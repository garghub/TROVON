static unsigned int __init estimate_cpu_frequency(void)
{
unsigned int prid = read_c0_prid() & 0xffff00;
unsigned int count;
#if 1
if ((prid == (PRID_COMP_MIPS | PRID_IMP_20KC)) ||
(prid == (PRID_COMP_MIPS | PRID_IMP_25KF)))
count = 12000000;
else
count = 6000000;
#else
unsigned int flags;
local_irq_save(flags);
while (CMOS_READ(RTC_REG_A) & RTC_UIP);
while (!(CMOS_READ(RTC_REG_A) & RTC_UIP));
write_c0_count(0);
while (CMOS_READ(RTC_REG_A) & RTC_UIP);
while (!(CMOS_READ(RTC_REG_A) & RTC_UIP));
count = read_c0_count();
local_irq_restore(flags);
#endif
mips_hpt_frequency = count;
if ((prid != (PRID_COMP_MIPS | PRID_IMP_20KC)) &&
(prid != (PRID_COMP_MIPS | PRID_IMP_25KF)))
count *= 2;
count += 5000;
count -= count%10000;
return count;
}
static void mips_timer_dispatch(void)
{
do_IRQ(mips_cpu_timer_irq);
}
unsigned __cpuinit get_c0_compare_int(void)
{
#ifdef MSC01E_INT_BASE
if (cpu_has_veic) {
set_vi_handler(MSC01E_INT_CPUCTR, mips_timer_dispatch);
mips_cpu_timer_irq = MSC01E_INT_BASE + MSC01E_INT_CPUCTR;
return mips_cpu_timer_irq;
}
#endif
if (cpu_has_vint)
set_vi_handler(cp0_compare_irq, mips_timer_dispatch);
mips_cpu_timer_irq = MIPS_CPU_IRQ_BASE + cp0_compare_irq;
return mips_cpu_timer_irq;
}
void __init plat_time_init(void)
{
unsigned int est_freq;
CMOS_WRITE(CMOS_READ(RTC_CONTROL) | RTC_DM_BINARY, RTC_CONTROL);
est_freq = estimate_cpu_frequency();
printk(KERN_INFO "CPU frequency %d.%02d MHz\n", est_freq / 1000000,
(est_freq % 1000000) * 100 / 1000000);
cpu_khz = est_freq / 1000;
}
