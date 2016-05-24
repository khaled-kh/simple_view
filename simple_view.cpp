#include "simple_view.hpp"

namespace gil_simple_view
{
	// simple_view class definition
	
	simple_view::simple_view(channel_type& channel, color_space_type& color_space, boost::gil::image_view& src_view)
	{
		_channel = channel; _color_space = color_space; _src_view = src_view;
	}
	
	channel_type            simple_view::channel()     { return _channel;     }
	color_space_type        simple_view::color_space() { return _color_space; }
	boost::gil::image_view* simple_view::src_view()    { return _src_view;    }
	
	simple_pixel_data simple_view::at(int x, int y)
	{
		simple_pixel_data d;
		d.bits32 = 0;
		
		switch (_channel)
		{
			case channel_type::bits8   :
				d.bits8   = 1; // TODO
				break;
			case channel_type::bits8s  :
				d.bits8s  = 1; // TODO
				break;
			case channel_type::bits16  :
				d.bits16  = 1; // TODO
				break;
			case channel_type::bits16s :
				d.bits16s = 1; // TODO
				break;
			case channel_type::bits32  :
				d.bits32  = 1; // TODO
				break;
			case channel_type::bits32s :
				d.bits32s = 1; // TODO
				break;
			case channel_type::bits32f :
				d.bits32f = 1; // TODO
				break;
		}
		
		return d;
	}
	
	// check channel type bit-wise
	
	bool is_8bit      (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits8  :
			case channel_type::bits8s : return true;
			default: return false;
		}
	}
	
	bool is_16bit     (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits16  :
			case channel_type::bits16s : return true;
			default: return false;
		}
	}
	
	bool is_32bit     (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits32  :
			case channel_type::bits32s :
			case channel_type::bits32f : return true;
			default: return false;
		}
	}
	
	// check channel type representation-wise
	
	bool is_unsigned  (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits8  :
			case channel_type::bits16 :
			case channel_type::bits32 : return true;
			default: return false;
		}
	}
	
	bool is_signed    (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits8s  :
			case channel_type::bits16s :
			case channel_type::bits32s : return true;
			default: return false;
		}
	}
	
	bool is_float     (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits32f : return true;
			default: return false;
		}
	}
	
	// check color space type disregarding the order
	
	bool is_grayscale (simple_view& v)
	{
		switch(v.color_space())
		{
			case color_space_type::gray : return true;
			default: return false;
		}
	}
	
	bool is_rgb       (simple_view& v)
	{
		switch(v.color_space())
		{
			case color_space_type::rgb :
			case color_space_type::bgr : return true;
			default: return false;
		}
	}
	
	bool is_argb      (simple_view& v)
	{
		switch(v.color_space())
		{
			case color_space_type::argb :
			case color_space_type::abgr :
			case color_space_type::rgba :
			case color_space_type::bgra : return true;
			default: return false;
		}
	}
	
	bool is_cmyk      (simple_view& v)
	{
		switch(v.color_space())
		{
			case color_space_type::cmyk : return true;
			default: return false;
		}
	}
	
	// create a simple_view from a boost::gil view
	
	template<typename T> simple_view create_simple_view (T& v)
	{
		throw std::invalid_argument("create_simple_view(..): Expected boost::gil::image_view<..>");
	}
	
	template<typename Loc> simple_view create_simple_view (boost::gil::image_view<Loc>& v)
	{
		throw std::invalid_argument("create_simple_view(boost::gil::image_view<Loc>): Loc is unsupported");
	}
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray8_loc_t  >& v){ return simple_view(channel_type::bits8  , color_space_type::gray, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray8s_loc_t >& v){ return simple_view(channel_type::bits8s , color_space_type::gray, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray16_loc_t >& v){ return simple_view(channel_type::bits16 , color_space_type::gray, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray16s_loc_t>& v){ return simple_view(channel_type::bits16s, color_space_type::gray, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray32_loc_t >& v){ return simple_view(channel_type::bits32 , color_space_type::gray, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray32s_loc_t>& v){ return simple_view(channel_type::bits32s, color_space_type::gray, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray32f_loc_t>& v){ return simple_view(channel_type::bits32f, color_space_type::gray, &v); }
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb8_loc_t  >& v){ return simple_view(channel_type::bits8  , color_space_type::rgb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb8s_loc_t >& v){ return simple_view(channel_type::bits8s , color_space_type::rgb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb16_loc_t >& v){ return simple_view(channel_type::bits16 , color_space_type::rgb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb16s_loc_t>& v){ return simple_view(channel_type::bits16s, color_space_type::rgb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb32_loc_t >& v){ return simple_view(channel_type::bits32 , color_space_type::rgb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb32s_loc_t>& v){ return simple_view(channel_type::bits32s, color_space_type::rgb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb32f_loc_t>& v){ return simple_view(channel_type::bits32f, color_space_type::rgb, &v); }
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr8_loc_t  >& v){ return simple_view(channel_type::bits8  , color_space_type::bgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr8s_loc_t >& v){ return simple_view(channel_type::bits8s , color_space_type::bgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr16_loc_t >& v){ return simple_view(channel_type::bits16 , color_space_type::bgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr16s_loc_t>& v){ return simple_view(channel_type::bits16s, color_space_type::bgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr32_loc_t >& v){ return simple_view(channel_type::bits32 , color_space_type::bgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr32s_loc_t>& v){ return simple_view(channel_type::bits32s, color_space_type::bgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr32f_loc_t>& v){ return simple_view(channel_type::bits32f, color_space_type::bgr, &v); }
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb8_loc_t  >& v){ return simple_view(channel_type::bits8  , color_space_type::argb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb8s_loc_t >& v){ return simple_view(channel_type::bits8s , color_space_type::argb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb16_loc_t >& v){ return simple_view(channel_type::bits16 , color_space_type::argb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb16s_loc_t>& v){ return simple_view(channel_type::bits16s, color_space_type::argb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb32_loc_t >& v){ return simple_view(channel_type::bits32 , color_space_type::argb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb32s_loc_t>& v){ return simple_view(channel_type::bits32s, color_space_type::argb, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb32f_loc_t>& v){ return simple_view(channel_type::bits32f, color_space_type::argb, &v); }
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr8_loc_t  >& v){ return simple_view(channel_type::bits8  , color_space_type::abgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr8s_loc_t >& v){ return simple_view(channel_type::bits8s , color_space_type::abgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr16_loc_t >& v){ return simple_view(channel_type::bits16 , color_space_type::abgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr16s_loc_t>& v){ return simple_view(channel_type::bits16s, color_space_type::abgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr32_loc_t >& v){ return simple_view(channel_type::bits32 , color_space_type::abgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr32s_loc_t>& v){ return simple_view(channel_type::bits32s, color_space_type::abgr, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr32f_loc_t>& v){ return simple_view(channel_type::bits32f, color_space_type::abgr, &v); }
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba8_loc_t  >& v){ return simple_view(channel_type::bits8  , color_space_type::rgba, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba8s_loc_t >& v){ return simple_view(channel_type::bits8s , color_space_type::rgba, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba16_loc_t >& v){ return simple_view(channel_type::bits16 , color_space_type::rgba, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba16s_loc_t>& v){ return simple_view(channel_type::bits16s, color_space_type::rgba, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba32_loc_t >& v){ return simple_view(channel_type::bits32 , color_space_type::rgba, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba32s_loc_t>& v){ return simple_view(channel_type::bits32s, color_space_type::rgba, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba32f_loc_t>& v){ return simple_view(channel_type::bits32f, color_space_type::rgba, &v); }
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra8_loc_t  >& v){ return simple_view(channel_type::bits8  , color_space_type::bgra, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra8s_loc_t >& v){ return simple_view(channel_type::bits8s , color_space_type::bgra, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra16_loc_t >& v){ return simple_view(channel_type::bits16 , color_space_type::bgra, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra16s_loc_t>& v){ return simple_view(channel_type::bits16s, color_space_type::bgra, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra32_loc_t >& v){ return simple_view(channel_type::bits32 , color_space_type::bgra, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra32s_loc_t>& v){ return simple_view(channel_type::bits32s, color_space_type::bgra, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra32f_loc_t>& v){ return simple_view(channel_type::bits32f, color_space_type::bgra, &v); }
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk8_loc_t  >& v){ return simple_view(channel_type::bits8  , color_space_type::cmyk, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk8s_loc_t >& v){ return simple_view(channel_type::bits8s , color_space_type::cmyk, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk16_loc_t >& v){ return simple_view(channel_type::bits16 , color_space_type::cmyk, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk16s_loc_t>& v){ return simple_view(channel_type::bits16s, color_space_type::cmyk, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk32_loc_t >& v){ return simple_view(channel_type::bits32 , color_space_type::cmyk, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk32s_loc_t>& v){ return simple_view(channel_type::bits32s, color_space_type::cmyk, &v); }
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk32f_loc_t>& v){ return simple_view(channel_type::bits32f, color_space_type::cmyk, &v); }
	
}
