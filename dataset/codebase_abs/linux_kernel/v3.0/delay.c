void F_1 ( unsigned long V_1 )
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
inline void F_2 ( unsigned long V_2 )
{
V_2 *= 4 ;
__asm__("dmulu.l %0, %2\n\t"
"sts mach, %0"
: "=r" (xloops)
: "0" (xloops),
"r" (cpu_data[raw_smp_processor_id()].loops_per_jiffy * (HZ/4))
: "macl", "mach");
F_1 ( ++ V_2 ) ;
}
void F_3 ( unsigned long V_3 )
{
F_2 ( V_3 * 0x000010c6 ) ;
}
void F_4 ( unsigned long V_4 )
{
F_2 ( V_4 * 0x00000005 ) ;
}
