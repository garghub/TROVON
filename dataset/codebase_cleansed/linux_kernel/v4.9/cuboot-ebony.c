void platform_init(unsigned long r3, unsigned long r4, unsigned long r5,\r\nunsigned long r6, unsigned long r7)\r\n{\r\nCUBOOT_INIT();\r\nebony_init(&bd.bi_enetaddr, &bd.bi_enet1addr);\r\n}
