static void __init\r\nfixup_clep7312(struct tag *tags, char **cmdline)\r\n{\r\nmemblock_add(0xc0000000, 0x01000000);\r\n}
