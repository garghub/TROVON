static inline void platform_do_lowpower(unsigned int cpu)
{
flush_cache_all();
for (;;) {
__asm__ __volatile__("dsb\n\t" "wfi\n\t"
: : : "memory");
if (pen_release == cpu_logical_map(cpu)) {
break;
}
}
}
void __ref sirfsoc_cpu_die(unsigned int cpu)
{
platform_do_lowpower(cpu);
}
