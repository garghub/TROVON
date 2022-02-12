static bool hip04_cluster_is_down(unsigned int cluster)
{
int i;
for (i = 0; i < HIP04_MAX_CPUS_PER_CLUSTER; i++)
if (hip04_cpu_table[cluster][i])
return false;
return true;
}
static void hip04_set_snoop_filter(unsigned int cluster, unsigned int on)
{
unsigned long data;
if (!fabric)
BUG();
data = readl_relaxed(fabric + FAB_SF_MODE);
if (on)
data |= 1 << cluster;
else
data &= ~(1 << cluster);
writel_relaxed(data, fabric + FAB_SF_MODE);
do {
cpu_relax();
} while (data != readl_relaxed(fabric + FAB_SF_MODE));
}
static int hip04_mcpm_power_up(unsigned int cpu, unsigned int cluster)
{
unsigned long data;
void __iomem *sys_dreq, *sys_status;
if (!sysctrl)
return -ENODEV;
if (cluster >= HIP04_MAX_CLUSTERS || cpu >= HIP04_MAX_CPUS_PER_CLUSTER)
return -EINVAL;
spin_lock_irq(&boot_lock);
if (hip04_cpu_table[cluster][cpu])
goto out;
sys_dreq = sysctrl + SC_CPU_RESET_DREQ(cluster);
sys_status = sysctrl + SC_CPU_RESET_STATUS(cluster);
if (hip04_cluster_is_down(cluster)) {
data = CLUSTER_DEBUG_RESET_BIT;
writel_relaxed(data, sys_dreq);
do {
cpu_relax();
data = readl_relaxed(sys_status);
} while (data & CLUSTER_DEBUG_RESET_STATUS);
}
data = CORE_RESET_BIT(cpu) | NEON_RESET_BIT(cpu) | \
CORE_DEBUG_RESET_BIT(cpu);
writel_relaxed(data, sys_dreq);
do {
cpu_relax();
} while (data == readl_relaxed(sys_status));
udelay(20);
out:
hip04_cpu_table[cluster][cpu]++;
spin_unlock_irq(&boot_lock);
return 0;
}
static void hip04_mcpm_power_down(void)
{
unsigned int mpidr, cpu, cluster;
bool skip_wfi = false, last_man = false;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
__mcpm_cpu_going_down(cpu, cluster);
spin_lock(&boot_lock);
BUG_ON(__mcpm_cluster_state(cluster) != CLUSTER_UP);
hip04_cpu_table[cluster][cpu]--;
if (hip04_cpu_table[cluster][cpu] == 1) {
skip_wfi = true;
} else if (hip04_cpu_table[cluster][cpu] > 1) {
pr_err("Cluster %d CPU%d boots multiple times\n", cluster, cpu);
BUG();
}
last_man = hip04_cluster_is_down(cluster);
if (last_man && __mcpm_outbound_enter_critical(cpu, cluster)) {
spin_unlock(&boot_lock);
asm volatile(
"mcr p15, 1, %0, c15, c0, 3 \n\t"
"isb \n\t"
"dsb "
: : "r" (0x400) );
v7_exit_coherency_flush(all);
hip04_set_snoop_filter(cluster, 0);
__mcpm_outbound_leave_critical(cluster, CLUSTER_DOWN);
} else {
spin_unlock(&boot_lock);
v7_exit_coherency_flush(louis);
}
__mcpm_cpu_down(cpu, cluster);
if (!skip_wfi)
wfi();
}
static int hip04_mcpm_wait_for_powerdown(unsigned int cpu, unsigned int cluster)
{
unsigned int data, tries, count;
int ret = -ETIMEDOUT;
BUG_ON(cluster >= HIP04_MAX_CLUSTERS ||
cpu >= HIP04_MAX_CPUS_PER_CLUSTER);
count = TIMEOUT_MSEC / POLL_MSEC;
spin_lock_irq(&boot_lock);
for (tries = 0; tries < count; tries++) {
if (hip04_cpu_table[cluster][cpu]) {
ret = -EBUSY;
goto err;
}
cpu_relax();
data = readl_relaxed(sysctrl + SC_CPU_RESET_STATUS(cluster));
if (data & CORE_WFI_STATUS(cpu))
break;
spin_unlock_irq(&boot_lock);
msleep(POLL_MSEC);
spin_lock_irq(&boot_lock);
}
if (tries >= count)
goto err;
data = CORE_RESET_BIT(cpu) | NEON_RESET_BIT(cpu) | \
CORE_DEBUG_RESET_BIT(cpu);
writel_relaxed(data, sysctrl + SC_CPU_RESET_REQ(cluster));
for (tries = 0; tries < count; tries++) {
cpu_relax();
data = readl_relaxed(sysctrl + SC_CPU_RESET_STATUS(cluster));
if (data & CORE_RESET_STATUS(cpu))
break;
}
if (tries >= count)
goto err;
spin_unlock_irq(&boot_lock);
return 0;
err:
spin_unlock_irq(&boot_lock);
return ret;
}
static void hip04_mcpm_powered_up(void)
{
unsigned int mpidr, cpu, cluster;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
spin_lock(&boot_lock);
if (!hip04_cpu_table[cluster][cpu])
hip04_cpu_table[cluster][cpu] = 1;
spin_unlock(&boot_lock);
}
static void __naked hip04_mcpm_power_up_setup(unsigned int affinity_level)
{
asm volatile (" \n"
" cmp r0, #0 \n"
" bxeq lr \n"
" adr r2, 2f \n"
" ldmia r2, {r1, r3} \n"
" sub r0, r2, r1 \n"
" ldr r2, [r0, r3] \n"
" mrc p15, 0, r0, c0, c0, 5 \n"
" ubfx r1, r0, #8, #8 \n"
" mov r0, #1 \n"
" mov r3, r0, lsl r1 \n"
" ldr r0, [r2, #"__stringify(FAB_SF_MODE)"] \n"
" tst r0, r3 \n"
" bxne lr \n"
" orr r1, r0, r3 \n"
" str r1, [r2, #"__stringify(FAB_SF_MODE)"] \n"
"1: ldr r0, [r2, #"__stringify(FAB_SF_MODE)"] \n"
" tst r0, r3 \n"
" beq 1b \n"
" bx lr \n"
" .align 2 \n"
"2: .word . \n"
" .word fabric_phys_addr \n"
);
}
static bool __init hip04_cpu_table_init(void)
{
unsigned int mpidr, cpu, cluster;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
if (cluster >= HIP04_MAX_CLUSTERS ||
cpu >= HIP04_MAX_CPUS_PER_CLUSTER) {
pr_err("%s: boot CPU is out of bound!\n", __func__);
return false;
}
hip04_set_snoop_filter(cluster, 1);
hip04_cpu_table[cluster][cpu] = 1;
return true;
}
static int __init hip04_mcpm_init(void)
{
struct device_node *np, *np_sctl, *np_fab;
struct resource fab_res;
void __iomem *relocation;
int ret = -ENODEV;
np = of_find_compatible_node(NULL, NULL, "hisilicon,hip04-bootwrapper");
if (!np)
goto err;
ret = of_property_read_u32_array(np, "boot-method",
&hip04_boot_method[0], 4);
if (ret)
goto err;
np_sctl = of_find_compatible_node(NULL, NULL, "hisilicon,sysctrl");
if (!np_sctl)
goto err;
np_fab = of_find_compatible_node(NULL, NULL, "hisilicon,hip04-fabric");
if (!np_fab)
goto err;
ret = memblock_reserve(hip04_boot_method[0], hip04_boot_method[1]);
if (ret)
goto err;
relocation = ioremap(hip04_boot_method[2], hip04_boot_method[3]);
if (!relocation) {
pr_err("failed to map relocation space\n");
ret = -ENOMEM;
goto err_reloc;
}
sysctrl = of_iomap(np_sctl, 0);
if (!sysctrl) {
pr_err("failed to get sysctrl base\n");
ret = -ENOMEM;
goto err_sysctrl;
}
ret = of_address_to_resource(np_fab, 0, &fab_res);
if (ret) {
pr_err("failed to get fabric base phys\n");
goto err_fabric;
}
fabric_phys_addr = fab_res.start;
sync_cache_w(&fabric_phys_addr);
fabric = of_iomap(np_fab, 0);
if (!fabric) {
pr_err("failed to get fabric base\n");
ret = -ENOMEM;
goto err_fabric;
}
if (!hip04_cpu_table_init()) {
ret = -EINVAL;
goto err_table;
}
ret = mcpm_platform_register(&hip04_mcpm_ops);
if (ret) {
goto err_table;
}
writel_relaxed(hip04_boot_method[0], relocation);
writel_relaxed(0xa5a5a5a5, relocation + 4);
writel_relaxed(virt_to_phys(mcpm_entry_point), relocation + 8);
writel_relaxed(0, relocation + 12);
iounmap(relocation);
mcpm_sync_init(hip04_mcpm_power_up_setup);
mcpm_smp_set_ops();
pr_info("HiP04 MCPM initialized\n");
return ret;
err_table:
iounmap(fabric);
err_fabric:
iounmap(sysctrl);
err_sysctrl:
iounmap(relocation);
err_reloc:
memblock_free(hip04_boot_method[0], hip04_boot_method[1]);
err:
return ret;
}
