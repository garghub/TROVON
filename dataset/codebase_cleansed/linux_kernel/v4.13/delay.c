void __delay(unsigned long loops)
{
__asm__ __volatile__(
".balign 8\n\t"
"tst %0, %0\n\t"
"1:\t"
"bf/s 1b\n\t"
" dt %0"
: "=r" (loops)
: "0" (loops)
: "t");
}
inline void __const_udelay(unsigned long xloops)
{
xloops *= 4;
__asm__("dmulu.l %0, %2\n\t"
"sts mach, %0"
: "=r" (xloops)
: "0" (xloops),
"r" (cpu_data[raw_smp_processor_id()].loops_per_jiffy * (HZ/4))
: "macl", "mach");
__delay(++xloops);
}
void __udelay(unsigned long usecs)
{
__const_udelay(usecs * 0x000010c6);
}
void __ndelay(unsigned long nsecs)
{
__const_udelay(nsecs * 0x00000005);
}
