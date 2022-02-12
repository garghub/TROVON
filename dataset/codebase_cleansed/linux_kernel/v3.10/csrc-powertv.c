unsigned int __init mips_get_pll_freq(void)
{
unsigned int pll_reg, m, n, p;
unsigned int fin = 54000;
unsigned int fout;
pll_reg = asic_read(mips_pll_setup);
m = PLL_GET_M(pll_reg);
n = PLL_GET_N(pll_reg);
p = PLL_GET_P(pll_reg);
pr_info("MIPS PLL Register:0x%x M=%d N=%d P=%d\n", pll_reg, m, n, p);
fout = ((2 * n * fin) / (m * (0x01 << p)));
pr_info("MIPS Clock Freq=%d kHz\n", fout);
return fout;
}
static cycle_t c0_hpt_read(struct clocksource *cs)
{
return read_c0_count();
}
static void __init powertv_c0_hpt_clocksource_init(void)
{
unsigned int pll_freq = mips_get_pll_freq();
pr_info("CPU frequency %d.%02d MHz\n", pll_freq / 1000,
(pll_freq % 1000) * 100 / 1000);
mips_hpt_frequency = pll_freq / 2 * 1000;
clocksource_mips.rating = 200 + mips_hpt_frequency / 10000000;
clocksource_register_hz(&clocksource_mips, mips_hpt_frequency);
}
static cycle_t tim_c_read(struct clocksource *cs)
{
unsigned int hi;
unsigned int next_hi;
unsigned int lo;
hi = readl(&tim_c->hi);
for (;;) {
lo = readl(&tim_c->lo);
next_hi = readl(&tim_c->hi);
if (next_hi == hi)
break;
hi = next_hi;
}
pr_crit("%s: read %llx\n", __func__, ((u64) hi << 32) | lo);
return ((u64) hi << 32) | lo;
}
static void __init powertv_tim_c_clocksource_init(void)
{
const unsigned long counts_per_second = 27000000 / 8;
clocksource_tim_c.rating = 200;
clocksource_register_hz(&clocksource_tim_c, counts_per_second);
tim_c = (struct tim_c *) asic_reg_addr(tim_ch);
}
void __init powertv_clocksource_init(void)
{
powertv_c0_hpt_clocksource_init();
powertv_tim_c_clocksource_init();
}
