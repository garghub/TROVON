static void __mcpm_cpu_going_down(unsigned int cpu, unsigned int cluster)
{
mcpm_sync.clusters[cluster].cpus[cpu].cpu = CPU_GOING_DOWN;
sync_cache_w(&mcpm_sync.clusters[cluster].cpus[cpu].cpu);
}
static void __mcpm_cpu_down(unsigned int cpu, unsigned int cluster)
{
dmb();
mcpm_sync.clusters[cluster].cpus[cpu].cpu = CPU_DOWN;
sync_cache_w(&mcpm_sync.clusters[cluster].cpus[cpu].cpu);
sev();
}
static void __mcpm_outbound_leave_critical(unsigned int cluster, int state)
{
dmb();
mcpm_sync.clusters[cluster].cluster = state;
sync_cache_w(&mcpm_sync.clusters[cluster].cluster);
sev();
}
static bool __mcpm_outbound_enter_critical(unsigned int cpu, unsigned int cluster)
{
unsigned int i;
struct mcpm_sync_struct *c = &mcpm_sync.clusters[cluster];
c->cluster = CLUSTER_GOING_DOWN;
sync_cache_w(&c->cluster);
sync_cache_r(&c->inbound);
if (c->inbound == INBOUND_COMING_UP)
goto abort;
sync_cache_r(&c->cpus);
for (i = 0; i < MAX_CPUS_PER_CLUSTER; i++) {
int cpustate;
if (i == cpu)
continue;
while (1) {
cpustate = c->cpus[i].cpu;
if (cpustate != CPU_GOING_DOWN)
break;
wfe();
sync_cache_r(&c->cpus[i].cpu);
}
switch (cpustate) {
case CPU_DOWN:
continue;
default:
goto abort;
}
}
return true;
abort:
__mcpm_outbound_leave_critical(cluster, CLUSTER_UP);
return false;
}
static int __mcpm_cluster_state(unsigned int cluster)
{
sync_cache_r(&mcpm_sync.clusters[cluster].cluster);
return mcpm_sync.clusters[cluster].cluster;
}
void mcpm_set_entry_vector(unsigned cpu, unsigned cluster, void *ptr)
{
unsigned long val = ptr ? __pa_symbol(ptr) : 0;
mcpm_entry_vectors[cluster][cpu] = val;
sync_cache_w(&mcpm_entry_vectors[cluster][cpu]);
}
void mcpm_set_early_poke(unsigned cpu, unsigned cluster,
unsigned long poke_phys_addr, unsigned long poke_val)
{
unsigned long *poke = &mcpm_entry_early_pokes[cluster][cpu][0];
poke[0] = poke_phys_addr;
poke[1] = poke_val;
__sync_cache_range_w(poke, 2 * sizeof(*poke));
}
int __init mcpm_platform_register(const struct mcpm_platform_ops *ops)
{
if (platform_ops)
return -EBUSY;
platform_ops = ops;
return 0;
}
bool mcpm_is_available(void)
{
return (platform_ops) ? true : false;
}
static inline bool mcpm_cluster_unused(unsigned int cluster)
{
int i, cnt;
for (i = 0, cnt = 0; i < MAX_CPUS_PER_CLUSTER; i++)
cnt |= mcpm_cpu_use_count[cluster][i];
return !cnt;
}
int mcpm_cpu_power_up(unsigned int cpu, unsigned int cluster)
{
bool cpu_is_down, cluster_is_down;
int ret = 0;
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (!platform_ops)
return -EUNATCH;
might_sleep();
local_irq_disable();
arch_spin_lock(&mcpm_lock);
cpu_is_down = !mcpm_cpu_use_count[cluster][cpu];
cluster_is_down = mcpm_cluster_unused(cluster);
mcpm_cpu_use_count[cluster][cpu]++;
BUG_ON(mcpm_cpu_use_count[cluster][cpu] != 1 &&
mcpm_cpu_use_count[cluster][cpu] != 2);
if (cluster_is_down)
ret = platform_ops->cluster_powerup(cluster);
if (cpu_is_down && !ret)
ret = platform_ops->cpu_powerup(cpu, cluster);
arch_spin_unlock(&mcpm_lock);
local_irq_enable();
return ret;
}
void mcpm_cpu_power_down(void)
{
unsigned int mpidr, cpu, cluster;
bool cpu_going_down, last_man;
phys_reset_t phys_reset;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
pr_debug("%s: cpu %u cluster %u\n", __func__, cpu, cluster);
if (WARN_ON_ONCE(!platform_ops))
return;
BUG_ON(!irqs_disabled());
setup_mm_for_reboot();
__mcpm_cpu_going_down(cpu, cluster);
arch_spin_lock(&mcpm_lock);
BUG_ON(__mcpm_cluster_state(cluster) != CLUSTER_UP);
mcpm_cpu_use_count[cluster][cpu]--;
BUG_ON(mcpm_cpu_use_count[cluster][cpu] != 0 &&
mcpm_cpu_use_count[cluster][cpu] != 1);
cpu_going_down = !mcpm_cpu_use_count[cluster][cpu];
last_man = mcpm_cluster_unused(cluster);
if (last_man && __mcpm_outbound_enter_critical(cpu, cluster)) {
platform_ops->cpu_powerdown_prepare(cpu, cluster);
platform_ops->cluster_powerdown_prepare(cluster);
arch_spin_unlock(&mcpm_lock);
platform_ops->cluster_cache_disable();
__mcpm_outbound_leave_critical(cluster, CLUSTER_DOWN);
} else {
if (cpu_going_down)
platform_ops->cpu_powerdown_prepare(cpu, cluster);
arch_spin_unlock(&mcpm_lock);
platform_ops->cpu_cache_disable();
}
__mcpm_cpu_down(cpu, cluster);
if (cpu_going_down)
wfi();
phys_reset = (phys_reset_t)(unsigned long)__pa_symbol(cpu_reset);
phys_reset(__pa_symbol(mcpm_entry_point), false);
BUG();
}
int mcpm_wait_for_cpu_powerdown(unsigned int cpu, unsigned int cluster)
{
int ret;
if (WARN_ON_ONCE(!platform_ops || !platform_ops->wait_for_powerdown))
return -EUNATCH;
ret = platform_ops->wait_for_powerdown(cpu, cluster);
if (ret)
pr_warn("%s: cpu %u, cluster %u failed to power down (%d)\n",
__func__, cpu, cluster, ret);
return ret;
}
void mcpm_cpu_suspend(void)
{
if (WARN_ON_ONCE(!platform_ops))
return;
if (platform_ops->cpu_suspend_prepare) {
unsigned int mpidr = read_cpuid_mpidr();
unsigned int cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
unsigned int cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
arch_spin_lock(&mcpm_lock);
platform_ops->cpu_suspend_prepare(cpu, cluster);
arch_spin_unlock(&mcpm_lock);
}
mcpm_cpu_power_down();
}
int mcpm_cpu_powered_up(void)
{
unsigned int mpidr, cpu, cluster;
bool cpu_was_down, first_man;
unsigned long flags;
if (!platform_ops)
return -EUNATCH;
mpidr = read_cpuid_mpidr();
cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
local_irq_save(flags);
arch_spin_lock(&mcpm_lock);
cpu_was_down = !mcpm_cpu_use_count[cluster][cpu];
first_man = mcpm_cluster_unused(cluster);
if (first_man && platform_ops->cluster_is_up)
platform_ops->cluster_is_up(cluster);
if (cpu_was_down)
mcpm_cpu_use_count[cluster][cpu] = 1;
if (platform_ops->cpu_is_up)
platform_ops->cpu_is_up(cpu, cluster);
arch_spin_unlock(&mcpm_lock);
local_irq_restore(flags);
return 0;
}
static int __init nocache_trampoline(unsigned long _arg)
{
void (*cache_disable)(void) = (void *)_arg;
unsigned int mpidr = read_cpuid_mpidr();
unsigned int cpu = MPIDR_AFFINITY_LEVEL(mpidr, 0);
unsigned int cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
phys_reset_t phys_reset;
mcpm_set_entry_vector(cpu, cluster, cpu_resume);
setup_mm_for_reboot();
__mcpm_cpu_going_down(cpu, cluster);
BUG_ON(!__mcpm_outbound_enter_critical(cpu, cluster));
cache_disable();
__mcpm_outbound_leave_critical(cluster, CLUSTER_DOWN);
__mcpm_cpu_down(cpu, cluster);
phys_reset = (phys_reset_t)(unsigned long)__pa_symbol(cpu_reset);
phys_reset(__pa_symbol(mcpm_entry_point), false);
BUG();
}
int __init mcpm_loopback(void (*cache_disable)(void))
{
int ret;
local_irq_disable();
local_fiq_disable();
ret = cpu_pm_enter();
if (!ret) {
ret = cpu_suspend((unsigned long)cache_disable, nocache_trampoline);
cpu_pm_exit();
}
local_fiq_enable();
local_irq_enable();
if (ret)
pr_err("%s returned %d\n", __func__, ret);
return ret;
}
int __init mcpm_sync_init(
void (*power_up_setup)(unsigned int affinity_level))
{
unsigned int i, j, mpidr, this_cluster;
BUILD_BUG_ON(MCPM_SYNC_CLUSTER_SIZE * MAX_NR_CLUSTERS != sizeof mcpm_sync);
BUG_ON((unsigned long)&mcpm_sync & (__CACHE_WRITEBACK_GRANULE - 1));
for (i = 0; i < MAX_NR_CLUSTERS; i++) {
mcpm_sync.clusters[i].cluster = CLUSTER_DOWN;
mcpm_sync.clusters[i].inbound = INBOUND_NOT_COMING_UP;
for (j = 0; j < MAX_CPUS_PER_CLUSTER; j++)
mcpm_sync.clusters[i].cpus[j].cpu = CPU_DOWN;
}
mpidr = read_cpuid_mpidr();
this_cluster = MPIDR_AFFINITY_LEVEL(mpidr, 1);
for_each_online_cpu(i) {
mcpm_cpu_use_count[this_cluster][i] = 1;
mcpm_sync.clusters[this_cluster].cpus[i].cpu = CPU_UP;
}
mcpm_sync.clusters[this_cluster].cluster = CLUSTER_UP;
sync_cache_w(&mcpm_sync);
if (power_up_setup) {
mcpm_power_up_setup_phys = __pa_symbol(power_up_setup);
sync_cache_w(&mcpm_power_up_setup_phys);
}
return 0;
}
