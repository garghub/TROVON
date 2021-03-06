unsigned int __init mips_get_pll_freq(void)\r\n{\r\nunsigned int pll_reg, m, n, p;\r\nunsigned int fin = 54000;\r\nunsigned int fout;\r\npll_reg = asic_read(mips_pll_setup);\r\nm = PLL_GET_M(pll_reg);\r\nn = PLL_GET_N(pll_reg);\r\np = PLL_GET_P(pll_reg);\r\npr_info("MIPS PLL Register:0x%x M=%d N=%d P=%d\n", pll_reg, m, n, p);\r\nfout = ((2 * n * fin) / (m * (0x01 << p)));\r\npr_info("MIPS Clock Freq=%d kHz\n", fout);\r\nreturn fout;\r\n}\r\nstatic cycle_t c0_hpt_read(struct clocksource *cs)\r\n{\r\nreturn read_c0_count();\r\n}\r\nstatic void __init powertv_c0_hpt_clocksource_init(void)\r\n{\r\nunsigned int pll_freq = mips_get_pll_freq();\r\npr_info("CPU frequency %d.%02d MHz\n", pll_freq / 1000,\r\n(pll_freq % 1000) * 100 / 1000);\r\nmips_hpt_frequency = pll_freq / 2 * 1000;\r\nclocksource_mips.rating = 200 + mips_hpt_frequency / 10000000;\r\nclocksource_register_hz(&clocksource_mips, mips_hpt_frequency);\r\n}\r\nstatic cycle_t tim_c_read(struct clocksource *cs)\r\n{\r\nunsigned int hi;\r\nunsigned int next_hi;\r\nunsigned int lo;\r\nhi = readl(&tim_c->hi);\r\nfor (;;) {\r\nlo = readl(&tim_c->lo);\r\nnext_hi = readl(&tim_c->hi);\r\nif (next_hi == hi)\r\nbreak;\r\nhi = next_hi;\r\n}\r\npr_crit("%s: read %llx\n", __func__, ((u64) hi << 32) | lo);\r\nreturn ((u64) hi << 32) | lo;\r\n}\r\nstatic void __init powertv_tim_c_clocksource_init(void)\r\n{\r\nconst unsigned long counts_per_second = 27000000 / 8;\r\nclocksource_tim_c.rating = 200;\r\nclocksource_register_hz(&clocksource_tim_c, counts_per_second);\r\ntim_c = (struct tim_c *) asic_reg_addr(tim_ch);\r\n}\r\nvoid __init powertv_clocksource_init(void)\r\n{\r\npowertv_c0_hpt_clocksource_init();\r\npowertv_tim_c_clocksource_init();\r\n}
