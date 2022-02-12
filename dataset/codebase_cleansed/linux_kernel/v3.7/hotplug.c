static inline void cpu_enter_lowpower(void)
{
unsigned int v;
flush_cache_all();
asm volatile(
" mcr p15, 0, %1, c7, c5, 0\n"
" mcr p15, 0, %1, c7, c10, 4\n"
" mrc p15, 0, %0, c1, c0, 1\n"
" bic %0, %0, #0x20\n"
" mcr p15, 0, %0, c1, c0, 1\n"
" mrc p15, 0, %0, c1, c0, 0\n"
" bic %0, %0, %2\n"
" mcr p15, 0, %0, c1, c0, 0\n"
: "=&r" (v)
: "r" (0), "Ir" (CR_C)
: "cc");
}
static inline void cpu_leave_lowpower(void)
{
unsigned int v;
asm volatile( "mrc p15, 0, %0, c1, c0, 0\n"
" orr %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 0\n"
" mrc p15, 0, %0, c1, c0, 1\n"
" orr %0, %0, #0x20\n"
" mcr p15, 0, %0, c1, c0, 1\n"
: "=&r" (v)
: "Ir" (CR_C)
: "cc");
}
static inline void platform_do_lowpower(unsigned int cpu, int *spurious)
{
for (;;) {
asm(".word 0xe320f003\n"
:
:
: "memory", "cc");
if (pen_release == cpu_logical_map(cpu)) {
break;
}
(*spurious)++;
}
}
void __ref realview_cpu_die(unsigned int cpu)
{
int spurious = 0;
cpu_enter_lowpower();
platform_do_lowpower(cpu, &spurious);
cpu_leave_lowpower();
if (spurious)
pr_warn("CPU%u: %u spurious wakeup calls\n", cpu, spurious);
}
