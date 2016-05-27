#include "simple_view.hpp"

namespace gil_simple_view
{
	// simple_view class definition
	
	simple_view::simple_view(channel_type& channel, color_space_type& color_space, boost::gil::image_view* src_view)
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
				d.bits8   =  (uint8_t)(*_src_view).col_begin(x)[y];
				break;
			case channel_type::bits8s  :
				d.bits8s  =   (int8_t)(*_src_view).col_begin(x)[y];
				break;
			case channel_type::bits16  :
				d.bits16  = (uint16_t)(*_src_view).col_begin(x)[y];
				break;
			case channel_type::bits16s :
				d.bits16s =  (int16_t)(*_src_view).col_begin(x)[y];
				break;
			case channel_type::bits32  :
				d.bits32  = (uint32_t)(*_src_view).col_begin(x)[y];
				break;
			case channel_type::bits32s :
				d.bits32s =  (int32_t)(*_src_view).col_begin(x)[y];
				break;
			case channel_type::bits32f :
				d.bits32f =   (double)(*_src_view).col_begin(x)[y];
				break;
		}
		
		return d;
	}
	
	byte simple_view::at_c(simple_pixel_data p, int c)
	{
		switch (_channel)
		{
			case channel_type::bits8   : return boost::gil::at_c<c>(p.bits8);
			case channel_type::bits8s  : return boost::gil::at_c<c>(p.bits8s);
			case channel_type::bits16  : return boost::gil::at_c<c>(p.bits16);
			case channel_type::bits16s : return boost::gil::at_c<c>(p.bits16s);
			case channel_type::bits32  : return boost::gil::at_c<c>(p.bits32);
			case channel_type::bits32s : return boost::gil::at_c<c>(p.bits32s);
			case channel_type::bits32f : return boost::gil::at_c<c>(p.bits32f);
			default: return 0;
		}
	}
	
	byte simple_view::get_color(simple_pixel_data p, color_type c)
	{
		switch (c)
		{
			case color_type::gray_t:
				switch (_color_space)
				{
					case color_space_type::gray: return at_c(p,0);
					case color_space_type::rgb : return 0;
					case color_space_type::bgr : return 0;
					case color_space_type::argb: return 0;
					case color_space_type::abgr: return 0;
					case color_space_type::rgba: return 0;
					case color_space_type::bgra: return 0;
					case color_space_type::cmyk: return 0;
					default: return 0;
				}
			case color_type::alpha_t:
				switch (_color_space)
				{
					case color_space_type::gray: return 255;
					case color_space_type::rgb : return 255;
					case color_space_type::bgr : return 255;
					case color_space_type::argb: return at_c(p,0);
					case color_space_type::abgr: return at_c(p,0);
					case color_space_type::rgba: return at_c(p,3);
					case color_space_type::bgra: return at_c(p,3);
					case color_space_type::cmyk: return 255;
					default: return 0;
				}
			case color_type::red_t:
				switch (_color_space)
				{
					case color_space_type::gray: return 0;
					case color_space_type::rgb : return at_c(p,0);
					case color_space_type::bgr : return at_c(p,2);
					case color_space_type::argb: return at_c(p,1);
					case color_space_type::abgr: return at_c(p,3);
					case color_space_type::rgba: return at_c(p,0);
					case color_space_type::bgra: return at_c(p,2);
					case color_space_type::cmyk: return 0;
					default: return 0;
				}
			case color_type::green_t:
				switch (_color_space)
				{
					case color_space_type::gray: return 0;
					case color_space_type::rgb : return at_c(p,1);
					case color_space_type::bgr : return at_c(p,1);
					case color_space_type::argb: return at_c(p,2);
					case color_space_type::abgr: return at_c(p,2);
					case color_space_type::rgba: return at_c(p,1);
					case color_space_type::bgra: return at_c(p,1);
					case color_space_type::cmyk: return 0;
					default: return 0;
				}
			case color_type::blue_t:
				switch (_color_space)
				{
					case color_space_type::gray: return 0;
					case color_space_type::rgb : return at_c(p,2);
					case color_space_type::bgr : return at_c(p,0);
					case color_space_type::argb: return at_c(p,3);
					case color_space_type::abgr: return at_c(p,1);
					case color_space_type::rgba: return at_c(p,2);
					case color_space_type::bgra: return at_c(p,0);
					case color_space_type::cmyk: return 0;
					default: return 0;
				}
			case color_type::cyan_t:
				switch (_color_space)
				{
					case color_space_type::gray: return 0;
					case color_space_type::rgb : return 0;
					case color_space_type::bgr : return 0;
					case color_space_type::argb: return 0;
					case color_space_type::abgr: return 0;
					case color_space_type::rgba: return 0;
					case color_space_type::bgra: return 0;
					case color_space_type::cmyk: return at_c(p,0);
					default: return 0;
				}
			case color_type::magenta_t:
				switch (_color_space)
				{
					case color_space_type::gray: return 0;
					case color_space_type::rgb : return 0;
					case color_space_type::bgr : return 0;
					case color_space_type::argb: return 0;
					case color_space_type::abgr: return 0;
					case color_space_type::rgba: return 0;
					case color_space_type::bgra: return 0;
					case color_space_type::cmyk: return at_c(p,1);
					default: return 0;
				}
			case color_type::yellow_t:
				switch (_color_space)
				{
					case color_space_type::gray: return 0;
					case color_space_type::rgb : return 0;
					case color_space_type::bgr : return 0;
					case color_space_type::argb: return 0;
					case color_space_type::abgr: return 0;
					case color_space_type::rgba: return 0;
					case color_space_type::bgra: return 0;
					case color_space_type::cmyk: return at_c(p,2);
					default: return 0;
				}
			case color_type::black_t:
				switch (_color_space)
				{
					case color_space_type::gray: return 0;
					case color_space_type::rgb : return 0;
					case color_space_type::bgr : return 0;
					case color_space_type::argb: return 0;
					case color_space_type::abgr: return 0;
					case color_space_type::rgba: return 0;
					case color_space_type::bgra: return 0;
					case color_space_type::cmyk: return at_c(p,3);
					default: return 0;
				}
			default: return 0;
		}
	}
	
	// check channel type bit-wise
	
	bool is_8bit (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits8  :
			case channel_type::bits8s : return true;
			default: return false;
		}
	}
	
	bool is_16bit (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits16  :
			case channel_type::bits16s : return true;
			default: return false;
		}
	}
	
	bool is_32bit (simple_view& v)
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
	
	bool is_unsigned (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits8  :
			case channel_type::bits16 :
			case channel_type::bits32 : return true;
			default: return false;
		}
	}
	
	bool is_signed (simple_view& v)
	{
		switch(v.channel())
		{
			case channel_type::bits8s  :
			case channel_type::bits16s :
			case channel_type::bits32s : return true;
			default: return false;
		}
	}
	
	bool is_float (simple_view& v)
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
	
	bool is_rgb (simple_view& v)
	{
		switch(v.color_space())
		{
			case color_space_type::rgb :
			case color_space_type::bgr : return true;
			default: return false;
		}
	}
	
	bool is_argb (simple_view& v)
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
	
	bool is_cmyk (simple_view& v)
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
