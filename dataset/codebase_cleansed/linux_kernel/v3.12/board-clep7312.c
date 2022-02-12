static void __init\r\nfixup_clep7312(struct tag *tags, char **cmdline, struct meminfo *mi)\r\n{\r\nmi->nr_banks=1;\r\nmi->bank[0].start = 0xc0000000;\r\nmi->bank[0].size = 0x01000000;\r\n}
