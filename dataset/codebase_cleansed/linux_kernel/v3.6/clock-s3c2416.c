void __init s3c2416_init_clocks(int xtal)
{
u32 epllcon = __raw_readl(S3C2443_EPLLCON);
u32 epllcon1 = __raw_readl(S3C2443_EPLLCON+4);
int ptr;
clk_epll.rate = s3c_get_pll6553x(xtal, epllcon, epllcon1);
clk_epll.parent = &clk_epllref.clk;
s3c2443_common_init_clocks(xtal, s3c2416_get_pll,
armdiv, ARRAY_SIZE(armdiv),
S3C2416_CLKDIV0_ARMDIV_MASK);
for (ptr = 0; ptr < ARRAY_SIZE(clksrcs); ptr++)
s3c_register_clksrc(clksrcs[ptr], 1);
s3c24xx_register_clock(&hsmmc0_clk);
clkdev_add_table(s3c2416_clk_lookup, ARRAY_SIZE(s3c2416_clk_lookup));
s3c_pwmclk_init();
}
