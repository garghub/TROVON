static inline unsigned int get_input_clock(int pll)
{
switch (pll) {
case 0:
if (ltq_cgu_r32(LTQ_CGU_PLL0_CFG) & CGU_PLL0_SRC)
return BASIS_REQUENCY_USB;
else if (CGU_PLL0_PHASE_DIVIDER_ENABLE)
return BASIC_FREQUENCY_1;
else
return BASIC_FREQUENCY_2;
case 1:
if (CGU_PLL1_SRC)
return BASIS_REQUENCY_USB;
else if (CGU_PLL0_PHASE_DIVIDER_ENABLE)
return BASIC_FREQUENCY_1;
else
return BASIC_FREQUENCY_2;
case 2:
switch (CGU_PLL2_SRC) {
case 0:
return ltq_get_pll0_fdiv();
case 1:
return CGU_PLL2_PHASE_DIVIDER_ENABLE ?
BASIC_FREQUENCY_1 :
BASIC_FREQUENCY_2;
case 2:
return BASIS_REQUENCY_USB;
}
default:
return 0;
}
}
static inline unsigned int cal_dsm(int pll, unsigned int num, unsigned int den)
{
u64 res, clock = get_input_clock(pll);
res = num * clock;
do_div(res, den);
return res;
}
static inline unsigned int mash_dsm(int pll, unsigned int M, unsigned int N,
unsigned int K)
{
unsigned int num = ((N + 1) << 10) + K;
unsigned int den = (M + 1) << 10;
return cal_dsm(pll, num, den);
}
static inline unsigned int ssff_dsm_1(int pll, unsigned int M, unsigned int N,
unsigned int K)
{
unsigned int num = ((N + 1) << 11) + K + 512;
unsigned int den = (M + 1) << 11;
return cal_dsm(pll, num, den);
}
static inline unsigned int ssff_dsm_2(int pll, unsigned int M, unsigned int N,
unsigned int K)
{
unsigned int num = K >= 512 ?
((N + 1) << 12) + K - 512 : ((N + 1) << 12) + K + 3584;
unsigned int den = (M + 1) << 12;
return cal_dsm(pll, num, den);
}
static inline unsigned int dsm(int pll, unsigned int M, unsigned int N,
unsigned int K, unsigned int dsmsel, unsigned int phase_div_en)
{
if (!dsmsel)
return mash_dsm(pll, M, N, K);
else if (!phase_div_en)
return mash_dsm(pll, M, N, K);
else
return ssff_dsm_2(pll, M, N, K);
}
static inline unsigned int ltq_get_pll0_fosc(void)
{
if (CGU_PLL0_BYPASS)
return get_input_clock(0);
else
return !CGU_PLL0_CFG_FRAC_EN
? dsm(0, CGU_PLL0_CFG_PLLM, CGU_PLL0_CFG_PLLN, 0,
CGU_PLL0_CFG_DSMSEL,
CGU_PLL0_PHASE_DIVIDER_ENABLE)
: dsm(0, CGU_PLL0_CFG_PLLM, CGU_PLL0_CFG_PLLN,
CGU_PLL0_CFG_PLLK, CGU_PLL0_CFG_DSMSEL,
CGU_PLL0_PHASE_DIVIDER_ENABLE);
}
static unsigned int ltq_get_pll0_fdiv(void)
{
unsigned int div = CGU_PLL2_CFG_INPUT_DIV + 1;
return (ltq_get_pll0_fosc() + (div >> 1)) / div;
}
unsigned int ltq_get_io_region_clock(void)
{
unsigned int ret = ltq_get_pll0_fosc();
switch (ltq_cgu_r32(LTQ_CGU_PLL2_CFG) & CGU_SYS_DDR_SEL) {
default:
case 0:
return (ret + 1) / 2;
case 1:
return (ret * 2 + 2) / 5;
case 2:
return (ret + 1) / 3;
case 3:
return (ret + 2) / 4;
}
}
unsigned int ltq_get_fpi_bus_clock(int fpi)
{
unsigned int ret = ltq_get_io_region_clock();
if ((fpi == 2) && (ltq_cgu_r32(LTQ_CGU_SYS) & CGU_SYS_FPI_SEL))
ret >>= 1;
return ret;
}
unsigned int ltq_get_cpu_hz(void)
{
switch (ltq_cgu_r32(LTQ_CGU_SYS) & 0xc) {
case 0:
return CLOCK_333M;
case 4:
return DDR_HZ;
case 8:
return DDR_HZ << 1;
default:
return DDR_HZ >> 1;
}
}
unsigned int ltq_get_fpi_hz(void)
{
unsigned int ddr_clock = DDR_HZ;
if (ltq_cgu_r32(LTQ_CGU_SYS) & 0x40)
return ddr_clock >> 1;
return ddr_clock;
}
