unsigned int pxa3xx_get_clk_frequency_khz(int info)
{
unsigned long acsr, xclkcfg;
unsigned int t, xl, xn, hss, ro, XL, XN, CLK, HSS;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
t = xclkcfg & 0x1;
acsr = ACSR;
xl = acsr & 0x1f;
xn = (acsr >> 8) & 0x7;
hss = (acsr >> 14) & 0x3;
XL = xl * BASE_CLK;
XN = xn * XL;
ro = acsr & ACCR_D0CS;
CLK = (ro) ? RO_CLK : ((t) ? XN : XL);
HSS = (ro) ? RO_CLK : hss_mult[hss] * BASE_CLK;
if (info) {
pr_info("RO Mode clock: %d.%02dMHz (%sactive)\n",
RO_CLK / 1000000, (RO_CLK % 1000000) / 10000,
(ro) ? "" : "in");
pr_info("Run Mode clock: %d.%02dMHz (*%d)\n",
XL / 1000000, (XL % 1000000) / 10000, xl);
pr_info("Turbo Mode clock: %d.%02dMHz (*%d, %sactive)\n",
XN / 1000000, (XN % 1000000) / 10000, xn,
(t) ? "" : "in");
pr_info("HSIO bus clock: %d.%02dMHz\n",
HSS / 1000000, (HSS % 1000000) / 10000);
}
return CLK / 1000;
}
static unsigned long clk_pxa3xx_ac97_getrate(struct clk *clk)
{
unsigned long rate = 312000000;
unsigned long ac97_div;
ac97_div = AC97_DIV;
rate /= (ac97_div >> 12) & 0x7fff;
rate *= (ac97_div & 0xfff);
return rate;
}
static unsigned long clk_pxa3xx_hsio_getrate(struct clk *clk)
{
unsigned long acsr;
unsigned int hss, hsio_clk;
acsr = ACSR;
hss = (acsr >> 14) & 0x3;
hsio_clk = (acsr & ACCR_D0CS) ? RO_CLK : hss_mult[hss] * BASE_CLK;
return hsio_clk;
}
static unsigned long clk_pxa3xx_smemc_getrate(struct clk *clk)
{
unsigned long acsr = ACSR;
unsigned long memclkcfg = __raw_readl(MEMCLKCFG);
return BASE_CLK * smcfs_mult[(acsr >> 23) & 0x7] /
df_clkdiv[(memclkcfg >> 16) & 0x3];
}
void clk_pxa3xx_cken_enable(struct clk *clk)
{
unsigned long mask = 1ul << (clk->cken & 0x1f);
if (clk->cken < 32)
CKENA |= mask;
else
CKENB |= mask;
}
void clk_pxa3xx_cken_disable(struct clk *clk)
{
unsigned long mask = 1ul << (clk->cken & 0x1f);
if (clk->cken < 32)
CKENA &= ~mask;
else
CKENB &= ~mask;
}
static void clk_pout_enable(struct clk *clk)
{
OSCC |= OSCC_PEN;
}
static void clk_pout_disable(struct clk *clk)
{
OSCC &= ~OSCC_PEN;
}
static int pxa3xx_clock_suspend(void)
{
cken[0] = CKENA;
cken[1] = CKENB;
accr = ACCR;
return 0;
}
static void pxa3xx_clock_resume(void)
{
ACCR = accr;
CKENA = cken[0];
CKENB = cken[1];
}
