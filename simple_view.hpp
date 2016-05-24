#ifndef H_GIL_SIMPLE_VIEW
#define H_GIL_SIMPLE_VIEW
#include "boost/gil/gil_all.hpp"

namespace gil_simple_view
{
	enum struct channel_type
	{
		bits8  ,	//  uint8_t
		bits8s ,	//   int8_t
		bits16 ,	// uint16_t
		bits16s,	//  int16_t
		bits32 ,	// uint32_t
		bits32s,	//  int32_t
		bits32f 	//   double
	};
	
	enum struct color_type
	{
		gray_t   , // [gray]scale
		alpha_t  , // [a]rgb
		red_t    , // a[r]gb
		green_t  , // ar[g]b
		blue_t   , // arg[b]
		cyan_t   , // [c]myk
		magenta_t, // c[m]yk
		yellow_t , // cm[y]k
		black_t    // cmy[k]
	};
	
	enum struct color_space_type
	{
		gray, // ({ color_type::gray_t });
		rgb , // ({ color_type::red_t  , color_type::green_t  , color_type::blue_t  });
		bgr , // ({ color_type::blue_t , color_type::green_t  , color_type::red_t   });
		argb, // ({ color_type::alpha_t, color_type::red_t    , color_type::green_t , color_type::blue_t  });
		abgr, // ({ color_type::alpha_t, color_type::blue_t   , color_type::green_t , color_type::red_t   });
		rgba, // ({ color_type::red_t  , color_type::green_t  , color_type::blue_t  , color_type::alpha_t });
		bgra, // ({ color_type::blue_t , color_type::green_t  , color_type::red_t   , color_type::alpha_t });
		cmyk  // ({ color_type::cyan_t , color_type::magenta_t, color_type::yellow_t, color_type::black_t };
	};
	
	typedef union
	{
		uint8_t  bits8;
		int8_t   bits8s;
		uint16_t bits16;
		int16_t  bits16s;
		uint32_t bits32;
		int32_t  bits32s;
		double   bits32f;
	}
	simple_pixel_data;
	
	class simple_view
	{
	private:
		channel_type _channel;
		color_space_type _color_space;
		boost::gil::image_view* _src_view;
		
	public:
		simple_view(channel_type& channel, color_space_type& color_space, boost::gil::image_view& src_view);
		
		channel_type channel();
		color_space_type color_space();
		boost::gil::image_view* src_view();
		simple_pixel_data at(int x, int y);
	};
	
	// check channel type bit-wise
	bool is_8bit      (simple_view& v);
	bool is_16bit     (simple_view& v);
	bool is_32bit     (simple_view& v);
	
	// check channel type representation-wise
	bool is_unsigned  (simple_view& v);
	bool is_signed    (simple_view& v);
	bool is_float     (simple_view& v);
	
	// check color space type disregarding the order
	bool is_grayscale (simple_view& v);
	bool is_rgb       (simple_view& v);
	bool is_argb      (simple_view& v);
	bool is_cmyk      (simple_view& v);
	
	// create a simple_view from a boost::gil view
	template<typename T> simple_view create_simple_view (T& v);
	
	template<typename L> simple_view create_simple_view (boost::gil::image_view<L>& v);
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray8_loc_t  >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray8s_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray16_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray32_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::gray32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb8_loc_t  >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb8s_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb16_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb32_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgb32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr8_loc_t  >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr8s_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr16_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr32_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgr32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb8_loc_t  >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb8s_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb16_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb32_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::argb32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr8_loc_t  >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr8s_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr16_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr32_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::abgr32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba8_loc_t  >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba8s_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba16_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba32_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::rgba32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra8_loc_t  >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra8s_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra16_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra32_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::bgra32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk8_loc_t  >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk8s_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk16_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk32_loc_t >& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<boost::gil::cmyk32f_loc_t>& v);
	
}

#endif
