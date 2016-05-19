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
		channel_type                channel;
		std::vector<color_type> color_space;
		boost::gil::image_view*    src_view;
	};
	
	bool is_8bit      (simple_view& v);
	bool is_16bit     (simple_view& v);
	bool is_32bit     (simple_view& v);
	
	bool is_unsigned  (simple_view& v);
	bool is_signed    (simple_view& v);
	bool is_float     (simple_view& v);
	
	bool is_grayscale (simple_view& v);
	bool is_rgb       (simple_view& v);
	bool is_argb      (simple_view& v);
	bool is_cmyk      (simple_view& v);
	
	simple_view create_simple_view (boost::gil::image_view& v);
}

#endif
