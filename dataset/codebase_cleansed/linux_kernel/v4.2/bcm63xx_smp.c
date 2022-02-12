static int __init scu_a9_enable(void)
{
unsigned long config_base;
void __iomem *scu_base;
unsigned int i, ncores;
if (!scu_a9_has_base()) {
pr_err("no configuration base address register!\n");
return -ENXIO;
}
config_base = scu_a9_get_base();
if (!config_base) {
pr_err("hardware reports only one core\n");
return -ENOENT;
}
scu_base = ioremap((phys_addr_t)config_base, CORTEX_A9_SCU_SIZE);
if (!scu_base) {
pr_err("failed to remap config base (%lu/%u) for SCU\n",
config_base, CORTEX_A9_SCU_SIZE);
return -ENOMEM;
}
scu_enable(scu_base);
ncores = scu_base ? scu_get_core_count(scu_base) : 1;
if (ncores > nr_cpu_ids) {
pr_warn("SMP: %u cores greater than maximum (%u), clipping\n",
ncores, nr_cpu_ids);
ncores = nr_cpu_ids;
}
#ifdef CONFIG_VFP
if (ncores > 1) {
pr_warn("SMP: secondary CPUs lack VFP unit, disabling VFP\n");
vfp_disable();
#ifdef CONFIG_KERNEL_MODE_NEON
WARN(1, "SMP: kernel-mode NEON enabled, restricting to UP\n");
ncores = 1;
#endif
}
#endif
for (i = 0; i < ncores; i++)
set_cpu_possible(i, true);
iounmap(scu_base);
return 0;
}
static int bcm63138_smp_boot_secondary(unsigned int cpu,
struct task_struct *idle)
{
void __iomem *bootlut_base;
struct device_node *dn;
int ret = 0;
u32 val;
dn = of_find_matching_node(NULL, bcm63138_bootlut_ids);
if (!dn) {
pr_err("SMP: unable to find bcm63138 boot LUT node\n");
return -ENODEV;
}
bootlut_base = of_iomap(dn, 0);
of_node_put(dn);
if (!bootlut_base) {
pr_err("SMP: unable to remap boot LUT base register\n");
return -ENOMEM;
}
dn = of_get_cpu_node(cpu_logical_map(cpu), NULL);
if (!dn) {
pr_err("SMP: failed to locate secondary CPU%d node\n", cpu);
ret = -ENODEV;
goto out;
}
val = virt_to_phys(bcm63138_secondary_startup);
writel_relaxed(val, bootlut_base + BOOTLUT_RESET_VECT);
ret = bcm63xx_pmb_power_on_cpu(dn);
if (ret)
goto out;
out:
iounmap(bootlut_base);
return ret;
}
static void __init bcm63138_smp_prepare_cpus(unsigned int max_cpus)
{
int ret;
ret = scu_a9_enable();
if (ret) {
pr_warn("SMP: Cortex-A9 SCU setup failed\n");
return;
}
}
