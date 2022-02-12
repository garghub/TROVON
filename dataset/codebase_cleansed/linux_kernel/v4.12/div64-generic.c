uint32_t __div64_32(u64 *xp, u32 y)\r\n{\r\nuint32_t rem;\r\nuint64_t q = __xdiv64_32(*xp, y);\r\nrem = *xp - q * y;\r\n*xp = q;\r\nreturn rem;\r\n}
