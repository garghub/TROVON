const char *AES_options(void) {\r\n#ifdef FULL_UNROLL\r\nreturn "aes(full)";\r\n#else\r\nreturn "aes(partial)";\r\n#endif\r\n}
