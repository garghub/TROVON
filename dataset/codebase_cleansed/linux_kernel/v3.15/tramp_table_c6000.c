static u32 tramp_size_get(void)\r\n{\r\nreturn sizeof(u32) * C6X_TRAMP_WORD_COUNT;\r\n}\r\nstatic u32 tramp_img_pkt_size_get(void)\r\n{\r\nreturn sizeof(struct c6000_gen_code);\r\n}
