/* color_value.h --- Color Value Parser */
/* Copyright (C) 2019 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com> */
/* This file is public domain software. */
#ifndef COLOR_VALUE_H_
#define COLOR_VALUE_H_  4   /* Version 4 */

#if defined(__cplusplus) && (__cplusplus >= 201103L)    /* C++11 */
    #include <cstdint>
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)    /* C99 */
    #include <stdint.h>
#else
    #ifdef __cplusplus
        #include <climits>
    #else
        #include <limits.h>
    #endif
    typedef unsigned char uint8_t;
    #if (UINT_MAX == 0xFFFFFFFF)
        typedef unsigned int uint32_t;
    #elif (ULONG_MAX == 0xFFFFFFFF)
        typedef unsigned long uint32_t;
    #else
        #error Your compiler is not support yet.
    #endif
    typedef char COLOR_VALUE_ASSERT_1[sizeof(uint8_t) == 1 ? 1 : -1];
    typedef char COLOR_VALUE_ASSERT_2[sizeof(uint32_t) == 4 ? 1 : -1];
#endif

#ifdef __cplusplus
    #include <cstdlib>
    #include <cstdio>
    #include <cstring>
    #include <cctype>
    #include <cassert>
#else
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <ctype.h>
    #include <assert.h>
#endif

#ifndef NO_STRSAFE
    #include <strsafe.h>
#endif

#ifdef __cplusplus
    using std::size_t;
#endif

typedef struct COLOR_VALUE_HEX
{
    const char *name;
    const char *hex;
} COLOR_VALUE_HEX;

static __inline const COLOR_VALUE_HEX *color_value_table(size_t *pcount)
{
    /* names are in lower case */
    static const COLOR_VALUE_HEX s_table[] =
    {
        { "black", "#000000" },
        { "white", "#ffffff" },
        { "red", "#ff0000" },
        { "yellow", "#ffff00" },
        { "blue", "#0000ff" },
        { "purple", "#800080" },
        { "silver", "#c0c0c0" },
        { "gray", "#808080" },
        { "green", "#008000" },
        { "maroon", "#800000" },
        { "fuchsia", "#ff00ff" },
        { "lime", "#00ff00" },
        { "olive", "#808000" },
        { "navy", "#000080" },
        { "orange", "#ffa500" },
        { "teal", "#008080" },
        { "aqua", "#00ffff" },
        { "aliceblue", "#f0f8ff" },
        { "antiquewhite", "#faebd7" },
        { "aquamarine", "#7fffd4" },
        { "azure", "#f0ffff" },
        { "beige", "#f5f5dc" },
        { "bisque", "#ffe4c4" },
        { "blanchedalmond", "#ffebcd" },
        { "blueviolet", "#8a2be2" },
        { "brown", "#a52a2a" },
        { "burlywood", "#deb887" },
        { "cadetblue", "#5f9ea0" },
        { "chartreuse", "#7fff00" },
        { "chocolate", "#d2691e" },
        { "coral", "#ff7f50" },
        { "cornflowerblue", "#6495ed" },
        { "cornsilk", "#fff8dc" },
        { "crimson", "#dc143c" },
        { "cyan", "#00ffff" },
        { "darkblue", "#00008b" },
        { "darkcyan", "#008b8b" },
        { "darkgoldenrod", "#b8860b" },
        { "darkgray", "#a9a9a9" },
        { "darkgreen", "#006400" },
        { "darkgrey", "#a9a9a9" },
        { "darkkhaki", "#bdb76b" },
        { "darkmagenta", "#8b008b" },
        { "darkolivegreen", "#556b2f" },
        { "darkorange", "#ff8c00" },
        { "darkorchid", "#9932cc" },
        { "darkred", "#8b0000" },
        { "darksalmon", "#e9967a" },
        { "darkseagreen", "#8fbc8f" },
        { "darkslateblue", "#483d8b" },
        { "darkslategray", "#2f4f4f" },
        { "darkslategrey", "#2f4f4f" },
        { "darkturquoise", "#00ced1" },
        { "darkviolet", "#9400d3" },
        { "deeppink", "#ff1493" },
        { "deepskyblue", "#00bfff" },
        { "dimgray", "#696969" },
        { "dimgrey", "#696969" },
        { "dodgerblue", "#1e90ff" },
        { "firebrick", "#b22222" },
        { "floralwhite", "#fffaf0" },
        { "forestgreen", "#228b22" },
        { "gainsboro", "#dcdcdc" },
        { "ghostwhite", "#f8f8ff" },
        { "gold", "#ffd700" },
        { "goldenrod", "#daa520" },
        { "greenyellow", "#adff2f" },
        { "grey", "#808080" },
        { "honeydew", "#f0fff0" },
        { "hotpink", "#ff69b4" },
        { "indianred", "#cd5c5c" },
        { "indigo", "#4b0082" },
        { "ivory", "#fffff0" },
        { "khaki", "#f0e68c" },
        { "lavender", "#e6e6fa" },
        { "lavenderblush", "#fff0f5" },
        { "lawngreen", "#7cfc00" },
        { "lemonchiffon", "#fffacd" },
        { "lightblue", "#add8e6" },
        { "lightcoral", "#f08080" },
        { "lightcyan", "#e0ffff" },
        { "lightgoldenrodyellow", "#fafad2" },
        { "lightgray", "#d3d3d3" },
        { "lightgreen", "#90ee90" },
        { "lightgrey", "#d3d3d3" },
        { "lightpink", "#ffb6c1" },
        { "lightsalmon", "#ffa07a" },
        { "lightseagreen", "#20b2aa" },
        { "lightskyblue", "#87cefa" },
        { "lightslategray", "#778899" },
        { "lightslategrey", "#778899" },
        { "lightsteelblue", "#b0c4de" },
        { "lightyellow", "#ffffe0" },
        { "limegreen", "#32cd32" },
        { "linen", "#faf0e6" },
        { "magenta", "#ff00ff" },
        { "mediumaquamarine", "#66cdaa" },
        { "mediumblue", "#0000cd" },
        { "mediumorchid", "#ba55d3" },
        { "mediumpurple", "#9370db" },
        { "mediumseagreen", "#3cb371" },
        { "mediumslateblue", "#7b68ee" },
        { "mediumspringgreen", "#00fa9a" },
        { "mediumturquoise", "#48d1cc" },
        { "mediumvioletred", "#c71585" },
        { "midnightblue", "#191970" },
        { "mintcream", "#f5fffa" },
        { "mistyrose", "#ffe4e1" },
        { "moccasin", "#ffe4b5" },
        { "navajowhite", "#ffdead" },
        { "oldlace", "#fdf5e6" },
        { "olivedrab", "#6b8e23" },
        { "orangered", "#ff4500" },
        { "orchid", "#da70d6" },
        { "palegoldenrod", "#eee8aa" },
        { "palegreen", "#98fb98" },
        { "paleturquoise", "#afeeee" },
        { "palevioletred", "#db7093" },
        { "papayawhip", "#ffefd5" },
        { "peachpuff", "#ffdab9" },
        { "peru", "#cd853f" },
        { "pink", "#ffc0cb" },
        { "plum", "#dda0dd" },
        { "powderblue", "#b0e0e6" },
        { "rosybrown", "#bc8f8f" },
        { "royalblue", "#4169e1" },
        { "saddlebrown", "#8b4513" },
        { "salmon", "#fa8072" },
        { "sandybrown", "#f4a460" },
        { "seagreen", "#2e8b57" },
        { "seashell", "#fff5ee" },
        { "sienna", "#a0522d" },
        { "skyblue", "#87ceeb" },
        { "slateblue", "#6a5acd" },
        { "slategray", "#708090" },
        { "slategrey", "#708090" },
        { "snow", "#fffafa" },
        { "springgreen", "#00ff7f" },
        { "steelblue", "#4682b4" },
        { "tan", "#d2b48c" },
        { "thistle", "#d8bfd8" },
        { "tomato", "#ff6347" },
        { "turquoise", "#40e0d0" },
        { "violet", "#ee82ee" },
        { "wheat", "#f5deb3" },
        { "whitesmoke", "#f5f5f5" },
        { "yellowgreen", "#9acd32" },
        { "rebeccapurple", "#663399" },
    };
    const size_t count = sizeof(s_table) / sizeof(s_table[0]);
    *pcount = count;
    return s_table;
}

static __inline int color_value_valid(uint32_t value)
{
    return (value != (uint32_t)-1) && (value <= 0xFFFFFF);
}

static __inline uint32_t color_value_fix(uint32_t value)
{
    uint32_t r = (uint8_t)(value >> 16);
    uint32_t g = (uint8_t)(value >> 8);
    uint32_t b = (uint8_t)value;
    return (b << 16) | (g << 8) | r;
}

static __inline void color_value_strlwr(char *dest, const char *src, size_t max_len)
{
#ifdef __cplusplus
    using namespace std;
#endif
    for (; *src && max_len > 1; ++src, ++dest, --max_len)
    {
        *dest = (char)tolower((unsigned char)*src);
    }
    *dest = 0;
}

static __inline uint32_t color_value_parse(const char *color_name)
{
#ifdef __cplusplus
    using namespace std;
#endif
    if (!color_name || !color_name[0])
        return (uint32_t)(-1);

    if (color_name[0] == '#')
    {
        char *pch;
        size_t len = strlen(&color_name[1]);
        if (len == 3)
        {
            /* #rgb */
            unsigned long value = strtoul(&color_name[1], &pch, 16);
            if (*pch == 0 && value <= 0xFFF)
            {
                uint32_t r = ((value >> 8) & 0x0F) * 0xFF / 0xF;
                uint32_t g = ((value >> 4) & 0x0F) * 0xFF / 0xF;
                uint32_t b = ((value >> 0) & 0x0F) * 0xFF / 0xF;
                value = (r << 16) | (g << 8) | b;
                return (uint32_t)value;
            }
        }
        else if (len == 6)
        {
            /* #rrggbb */
            unsigned long value = strtoul(&color_name[1], &pch, 16);
            if (*pch == 0 && value <= 0xFFFFFF)
            {
                return (uint32_t)value;
            }
        }
    }
    else
    {
        size_t i, count;
        char name[64];
        const COLOR_VALUE_HEX *table;
        color_value_strlwr(name, color_name, 64);

        table = color_value_table(&count);
        for (i = 0; i < count; ++i)
        {
            if (strcmp(table[i].name, name) == 0)
                return color_value_parse(table[i].hex);
        }
    }

    return (uint32_t)(-1);
}

static __inline void color_value_store(char *str, size_t max_len, uint32_t color_value)
{
#ifdef __cplusplus
    using namespace std;
#endif
    assert(max_len >= 8);
    color_value &= 0xFFFFFF;
#ifdef NO_STRSAFE
    sprintf(str, "#%06x", color_value);
#else
    StringCchPrintfA(str, max_len, "#%06x", color_value);
#endif
}

static __inline void color_value_unittest(void)
{
#ifdef __cplusplus
    using namespace std;
#endif
    char buf[8];
    assert(color_value_parse("black") == 0x000000);
    assert(color_value_parse("white") == 0xFFFFFF);
    assert(color_value_parse("red") == 0xFF0000);
    assert(color_value_parse("lime") == 0x00FF00);
    assert(color_value_parse("blue") == 0x0000FF);
    assert(color_value_parse("Black") == 0x000000);
    assert(color_value_parse("White") == 0xFFFFFF);
    assert(color_value_parse("Red") == 0xFF0000);
    assert(color_value_parse("Lime") == 0x00FF00);
    assert(color_value_parse("Blue") == 0x0000FF);
    assert(color_value_parse("BLACK") == 0x000000);
    assert(color_value_parse("WHITE") == 0xFFFFFF);
    assert(color_value_parse("RED") == 0xFF0000);
    assert(color_value_parse("LIME") == 0x00FF00);
    assert(color_value_parse("BLUE") == 0x0000FF);

    assert(color_value_parse("#ffffff") == 0xFFFFFF);
    assert(color_value_parse("#FFFFFF") == 0xFFFFFF);
    assert(color_value_parse("#ff0000") == 0xFF0000);
    assert(color_value_parse("#FF0000") == 0xFF0000);
    assert(color_value_parse("#fff") == 0xFFFFFF);
    assert(color_value_parse("#FFF") == 0xFFFFFF);
    assert(color_value_parse("#f00") == 0xFF0000);
    assert(color_value_parse("#F00") == 0xFF0000);

    color_value_store(buf, 8, 0xFF0000);
    assert(strcmp(buf, "#ff0000") == 0);
    color_value_store(buf, 8, 0xFF00FF);
    assert(strcmp(buf, "#ff00ff") == 0);
    color_value_store(buf, 8, 0x00FFFF);
    assert(strcmp(buf, "#00ffff") == 0);

    assert(color_value_fix(0xFF0000) == 0x0000FF);
    assert(color_value_fix(0xFFFF00) == 0x00FFFF);
    assert(color_value_fix(0x0000FF) == 0xFF0000);
}

#endif  /* ndef COLOR_VALUE_H_ */
