u32 reciprocal_value(u32 k)\r\n{\r\nu64 val = (1LL << 32) + (k - 1);\r\ndo_div(val, k);\r\nreturn (u32)val;\r\n}
