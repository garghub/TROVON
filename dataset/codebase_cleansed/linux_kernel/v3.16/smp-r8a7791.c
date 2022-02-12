static void __init r8a7791_smp_prepare_cpus(unsigned int max_cpus)
{
void __iomem *p;
u32 bar;
shmobile_smp_apmu_prepare_cpus(max_cpus);
p = ioremap_nocache(RAM, shmobile_boot_size);
memcpy_toio(p, shmobile_boot_vector, shmobile_boot_size);
iounmap(p);
p = ioremap_nocache(RST, 0x63);
bar = (RAM >> 8) & 0xfffffc00;
writel_relaxed(bar, p + CA15BAR);
writel_relaxed(bar | 0x10, p + CA15BAR);
writel_relaxed((readl_relaxed(p + CA15RESCNT) & ~0x0f) | 0xa5a50000,
p + CA15RESCNT);
iounmap(p);
}
static int r8a7791_smp_boot_secondary(unsigned int cpu,
struct task_struct *idle)
{
if (rcar_gen2_read_mode_pins() & BIT(21)) {
pr_warn("Unable to boot CPU%u when MD21 is set\n", cpu);
return -ENOTSUPP;
}
return shmobile_smp_apmu_boot_secondary(cpu, idle);
}
