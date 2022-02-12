void __init octeon_setup_delays(void)
{
octeon_udelay_factor = octeon_get_clock_rate() / 1000000;
octeon_ndelay_factor = (octeon_udelay_factor * 0x10000ull) / 1000ull;
preset_lpj = octeon_get_clock_rate() / HZ;
if (current_cpu_type() == CPU_CAVIUM_OCTEON2) {
union cvmx_mio_rst_boot rst_boot;
rst_boot.u64 = cvmx_read_csr(CVMX_MIO_RST_BOOT);
rdiv = rst_boot.s.c_mul;
sdiv = rst_boot.s.pnr_mul;
f = (0x8000000000000000ull / sdiv) * 2;
}
}
void octeon_init_cvmcount(void)
{
unsigned long flags;
unsigned loops = 2;
asm("" : "+r" (loops));
local_irq_save(flags);
while (loops--) {
u64 ipd_clk_count = cvmx_read_csr(CVMX_IPD_CLK_COUNT);
if (rdiv != 0) {
ipd_clk_count *= rdiv;
if (f != 0) {
asm("dmultu\t%[cnt],%[f]\n\t"
"mfhi\t%[cnt]"
: [cnt] "+r" (ipd_clk_count)
: [f] "r" (f)
: "hi", "lo");
}
}
write_c0_cvmcount(ipd_clk_count);
}
local_irq_restore(flags);
}
static cycle_t octeon_cvmcount_read(struct clocksource *cs)
{
return read_c0_cvmcount();
}
unsigned long long notrace sched_clock(void)
{
u64 t1, t2, t3;
unsigned long long rv;
u64 mult = clocksource_mips.mult;
u64 shift = clocksource_mips.shift;
u64 cnt = read_c0_cvmcount();
asm (
"dmultu\t%[cnt],%[mult]\n\t"
"nor\t%[t1],$0,%[shift]\n\t"
"mfhi\t%[t2]\n\t"
"mflo\t%[t3]\n\t"
"dsll\t%[t2],%[t2],1\n\t"
"dsrlv\t%[rv],%[t3],%[shift]\n\t"
"dsllv\t%[t1],%[t2],%[t1]\n\t"
"or\t%[rv],%[t1],%[rv]\n\t"
: [rv] "=&r" (rv), [t1] "=&r" (t1), [t2] "=&r" (t2), [t3] "=&r" (t3)
: [cnt] "r" (cnt), [mult] "r" (mult), [shift] "r" (shift)
: "hi", "lo");
return rv;
}
void __init plat_time_init(void)
{
clocksource_mips.rating = 300;
clocksource_register_hz(&clocksource_mips, octeon_get_clock_rate());
}
void __udelay(unsigned long us)
{
u64 cur, end, inc;
cur = read_c0_cvmcount();
inc = us * octeon_udelay_factor;
end = cur + inc;
while (end > cur)
cur = read_c0_cvmcount();
}
void __ndelay(unsigned long ns)
{
u64 cur, end, inc;
cur = read_c0_cvmcount();
inc = ((ns * octeon_ndelay_factor) >> 16);
end = cur + inc;
while (end > cur)
cur = read_c0_cvmcount();
}
void __delay(unsigned long loops)
{
u64 cur, end;
cur = read_c0_cvmcount();
end = cur + loops;
while (end > cur)
cur = read_c0_cvmcount();
}
void octeon_io_clk_delay(unsigned long count)
{
u64 cur, end;
cur = read_c0_cvmcount();
if (rdiv != 0) {
end = count * rdiv;
if (f != 0) {
asm("dmultu\t%[cnt],%[f]\n\t"
"mfhi\t%[cnt]"
: [cnt] "+r" (end)
: [f] "r" (f)
: "hi", "lo");
}
end = cur + end;
} else {
end = cur + count;
}
while (end > cur)
cur = read_c0_cvmcount();
}
