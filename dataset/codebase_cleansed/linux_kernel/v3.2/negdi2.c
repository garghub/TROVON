s64 __negdi2(s64 u)\r\n{\r\nunion DWunion w;\r\nunion DWunion uu;\r\nuu.ll = u;\r\nw.s.low = -uu.s.low;\r\nw.s.high = -uu.s.high - ((u32) w.s.low > 0);\r\nreturn w.ll;\r\n}
