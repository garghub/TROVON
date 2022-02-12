int platform_cpu_kill(unsigned int cpu)
{
return 1;
}
void platform_cpu_die(unsigned int cpu)
{
flush_cache_all();
dsb();
if (omap_modify_auxcoreboot0(0x0, 0x200) != 0x0)
printk(KERN_CRIT "Secure clear status failed\n");
for (;;) {
do_wfi();
if (omap_read_auxcoreboot0() == cpu) {
break;
}
pr_debug("CPU%u: spurious wakeup call\n", cpu);
}
}
int platform_cpu_disable(unsigned int cpu)
{
return cpu == 0 ? -EPERM : 0;
}
