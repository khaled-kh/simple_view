#ifndef H_GIL_SIMPLE_VIEW
#define H_GIL_SIMPLE_VIEW

namespace boost{ namespace gil{ struct image_view; }}

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
		gray_t   ,	// [gray]scale
		alpha_t  ,	// [a]rgb
		red_t    ,	// a[r]gb
		green_t  ,	// ar[g]b
		blue_t   ,	// arg[b]
		cyan_t   ,	// [c]myk
		magenta_t,	// c[m]yk
		yellow_t ,	// cm[y]k
		black_t   	// cmy[k]
	};
	
	namespace color_space_type
	{
		std::vector<color_type> gray({ color_type::gray_t });
		std::vector<color_type> rgb ({ color_type::red_t  , color_type::green_t  , color_type::blue_t  });
		std::vector<color_type> bgr ({ color_type::blue_t , color_type::green_t  , color_type::red_t   });
		std::vector<color_type> argb({ color_type::alpha_t, color_type::red_t    , color_type::green_t , color_type::blue_t  });
		std::vector<color_type> abgr({ color_type::alpha_t, color_type::blue_t   , color_type::green_t , color_type::red_t   });
		std::vector<color_type> rgba({ color_type::red_t  , color_type::green_t  , color_type::blue_t  , color_type::alpha_t });
		std::vector<color_type> bgra({ color_type::blue_t , color_type::green_t  , color_type::red_t   , color_type::alpha_t });
		std::vector<color_type> cmyk({ color_type::cyan_t , color_type::magenta_t, color_type::yellow_t, color_type::black_t };
	}
	
	struct simple_view
	{
		channel_type channel;
		std::vector<color_type> color_space;
		boost::gil::image_view* src_view;
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
	
	simple_view create_simple_view (boost::gil::image_view<gray8_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<gray8s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<gray16_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<gray16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<gray32_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<gray32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<gray32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<rgb8_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgb8s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgb16_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgb16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgb32_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgb32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgb32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<bgr8_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgr8s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgr16_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgr16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgr32_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgr32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgr32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<argb8_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<argb8s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<argb16_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<argb16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<argb32_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<argb32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<argb32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<abgr8_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<abgr8s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<abgr16_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<abgr16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<abgr32_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<abgr32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<abgr32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<rgba8_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgba8s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgba16_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgba16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgba32_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgba32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<rgba32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<bgra8_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgra8s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgra16_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgra16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgra32_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgra32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<bgra32f_loc_t>& v);
	
	simple_view create_simple_view (boost::gil::image_view<cmyk8_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<cmyk8s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<cmyk16_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<cmyk16s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<cmyk32_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<cmyk32s_loc_t>& v);
	simple_view create_simple_view (boost::gil::image_view<cmyk32f_loc_t>& v);
	
}

#endif
