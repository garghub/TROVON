void __ref omap4_cpu_die(unsigned int cpu)
{
unsigned int boot_cpu = 0;
void __iomem *base = omap_get_wakeupgen_base();
flush_cache_all();
dsb();
if (omap_secure_apis_support()) {
if (omap_modify_auxcoreboot0(0x0, 0x200) != 0x0)
pr_err("Secure clear status failed\n");
} else {
__raw_writel(0, base + OMAP_AUX_CORE_BOOT_0);
}
for (;;) {
omap4_hotplug_cpu(cpu, PWRDM_POWER_OFF);
if (omap_secure_apis_support())
boot_cpu = omap_read_auxcoreboot0();
else
boot_cpu =
__raw_readl(base + OMAP_AUX_CORE_BOOT_0) >> 5;
if (boot_cpu == smp_processor_id()) {
break;
}
pr_debug("CPU%u: spurious wakeup call\n", cpu);
}
}
