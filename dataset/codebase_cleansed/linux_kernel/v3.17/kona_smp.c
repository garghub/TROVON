static int __init scu_a9_enable(void)
{
unsigned long config_base;
void __iomem *scu_base;
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
iounmap(scu_base);
return 0;
}
static void __init bcm_smp_prepare_cpus(unsigned int max_cpus)
{
static cpumask_t only_cpu_0 = { CPU_BITS_CPU0 };
struct device_node *node;
int ret;
BUG_ON(secondary_boot);
node = of_find_node_by_path("/cpus");
BUG_ON(!node);
if (of_property_read_u32(node, OF_SECONDARY_BOOT, &secondary_boot)) {
pr_err("%s: missing/invalid " OF_SECONDARY_BOOT " property\n",
node->name);
ret = -ENOENT;
goto out;
}
ret = scu_a9_enable();
out:
of_node_put(node);
if (ret) {
BUG_ON(ret != -ENOENT);
pr_warn("disabling SMP\n");
init_cpu_present(&only_cpu_0);
}
}
static int bcm_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
void __iomem *boot_reg;
phys_addr_t boot_func;
u64 start_clock;
u32 cpu_id;
u32 boot_val;
bool timeout = false;
cpu_id = cpu_logical_map(cpu);
if (cpu_id & ~BOOT_ADDR_CPUID_MASK) {
pr_err("bad cpu id (%u > %u)\n", cpu_id, BOOT_ADDR_CPUID_MASK);
return -EINVAL;
}
if (!secondary_boot) {
pr_err("required secondary boot register not specified\n");
return -EINVAL;
}
boot_reg = ioremap_nocache((phys_addr_t)secondary_boot, sizeof(u32));
if (!boot_reg) {
pr_err("unable to map boot register for cpu %u\n", cpu_id);
return -ENOSYS;
}
boot_func = virt_to_phys(secondary_startup);
BUG_ON(boot_func & BOOT_ADDR_CPUID_MASK);
BUG_ON(boot_func > (phys_addr_t)U32_MAX);
boot_val = (u32)boot_func | cpu_id;
writel_relaxed(boot_val, boot_reg);
sev();
start_clock = local_clock();
while (!timeout && readl_relaxed(boot_reg) == boot_val)
timeout = local_clock() - start_clock > SECONDARY_TIMEOUT_NS;
iounmap(boot_reg);
if (!timeout)
return 0;
pr_err("timeout waiting for cpu %u to start\n", cpu_id);
return -ENOSYS;
}
