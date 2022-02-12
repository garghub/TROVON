unsigned long arch_scale_cpu_capacity(struct sched_domain *sd, int cpu)
{
return per_cpu(cpu_scale, cpu);
}
static void set_capacity_scale(unsigned int cpu, unsigned long capacity)
{
per_cpu(cpu_scale, cpu) = capacity;
}
static ssize_t cpu_capacity_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct cpu *cpu = container_of(dev, struct cpu, dev);
return sprintf(buf, "%lu\n",
arch_scale_cpu_capacity(NULL, cpu->dev.id));
}
static ssize_t cpu_capacity_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t count)
{
struct cpu *cpu = container_of(dev, struct cpu, dev);
int this_cpu = cpu->dev.id, i;
unsigned long new_capacity;
ssize_t ret;
if (count) {
ret = kstrtoul(buf, 0, &new_capacity);
if (ret)
return ret;
if (new_capacity > SCHED_CAPACITY_SCALE)
return -EINVAL;
mutex_lock(&cpu_scale_mutex);
for_each_cpu(i, &cpu_topology[this_cpu].core_sibling)
set_capacity_scale(i, new_capacity);
mutex_unlock(&cpu_scale_mutex);
}
return count;
}
static int register_cpu_capacity_sysctl(void)
{
int i;
struct device *cpu;
for_each_possible_cpu(i) {
cpu = get_cpu_device(i);
if (!cpu) {
pr_err("%s: too early to get CPU%d device!\n",
__func__, i);
continue;
}
device_create_file(cpu, &dev_attr_cpu_capacity);
}
return 0;
}
static int __init parse_cpu_capacity(struct device_node *cpu_node, int cpu)
{
int ret = 1;
u32 cpu_capacity;
if (cap_parsing_failed)
return !ret;
ret = of_property_read_u32(cpu_node,
"capacity-dmips-mhz",
&cpu_capacity);
if (!ret) {
if (!raw_capacity) {
raw_capacity = kcalloc(num_possible_cpus(),
sizeof(*raw_capacity),
GFP_KERNEL);
if (!raw_capacity) {
pr_err("cpu_capacity: failed to allocate memory for raw capacities\n");
cap_parsing_failed = true;
return !ret;
}
}
capacity_scale = max(cpu_capacity, capacity_scale);
raw_capacity[cpu] = cpu_capacity;
pr_debug("cpu_capacity: %s cpu_capacity=%u (raw)\n",
cpu_node->full_name, raw_capacity[cpu]);
} else {
if (raw_capacity) {
pr_err("cpu_capacity: missing %s raw capacity\n",
cpu_node->full_name);
pr_err("cpu_capacity: partial information: fallback to 1024 for all CPUs\n");
}
cap_parsing_failed = true;
kfree(raw_capacity);
}
return !ret;
}
static void normalize_cpu_capacity(void)
{
u64 capacity;
int cpu;
if (!raw_capacity || cap_parsing_failed)
return;
pr_debug("cpu_capacity: capacity_scale=%u\n", capacity_scale);
mutex_lock(&cpu_scale_mutex);
for_each_possible_cpu(cpu) {
capacity = (raw_capacity[cpu] << SCHED_CAPACITY_SHIFT)
/ capacity_scale;
set_capacity_scale(cpu, capacity);
pr_debug("cpu_capacity: CPU%d cpu_capacity=%lu\n",
cpu, arch_scale_cpu_capacity(NULL, cpu));
}
mutex_unlock(&cpu_scale_mutex);
}
static int
init_cpu_capacity_callback(struct notifier_block *nb,
unsigned long val,
void *data)
{
struct cpufreq_policy *policy = data;
int cpu;
if (cap_parsing_failed || cap_parsing_done)
return 0;
switch (val) {
case CPUFREQ_NOTIFY:
pr_debug("cpu_capacity: init cpu capacity for CPUs [%*pbl] (to_visit=%*pbl)\n",
cpumask_pr_args(policy->related_cpus),
cpumask_pr_args(cpus_to_visit));
cpumask_andnot(cpus_to_visit,
cpus_to_visit,
policy->related_cpus);
for_each_cpu(cpu, policy->related_cpus) {
raw_capacity[cpu] = arch_scale_cpu_capacity(NULL, cpu) *
policy->cpuinfo.max_freq / 1000UL;
capacity_scale = max(raw_capacity[cpu], capacity_scale);
}
if (cpumask_empty(cpus_to_visit)) {
normalize_cpu_capacity();
kfree(raw_capacity);
pr_debug("cpu_capacity: parsing done\n");
cap_parsing_done = true;
schedule_work(&parsing_done_work);
}
}
return 0;
}
static int __init register_cpufreq_notifier(void)
{
if (cap_parsing_failed)
return -EINVAL;
if (!alloc_cpumask_var(&cpus_to_visit, GFP_KERNEL)) {
pr_err("cpu_capacity: failed to allocate memory for cpus_to_visit\n");
return -ENOMEM;
}
cpumask_copy(cpus_to_visit, cpu_possible_mask);
return cpufreq_register_notifier(&init_cpu_capacity_notifier,
CPUFREQ_POLICY_NOTIFIER);
}
static void parsing_done_workfn(struct work_struct *work)
{
cpufreq_unregister_notifier(&init_cpu_capacity_notifier,
CPUFREQ_POLICY_NOTIFIER);
}
static int __init free_raw_capacity(void)
{
kfree(raw_capacity);
return 0;
}
static void __init parse_dt_topology(void)
{
const struct cpu_efficiency *cpu_eff;
struct device_node *cn = NULL;
unsigned long min_capacity = ULONG_MAX;
unsigned long max_capacity = 0;
unsigned long capacity = 0;
int cpu = 0;
__cpu_capacity = kcalloc(nr_cpu_ids, sizeof(*__cpu_capacity),
GFP_NOWAIT);
cn = of_find_node_by_path("/cpus");
if (!cn) {
pr_err("No CPU information found in DT\n");
return;
}
for_each_possible_cpu(cpu) {
const u32 *rate;
int len;
cn = of_get_cpu_node(cpu, NULL);
if (!cn) {
pr_err("missing device node for CPU %d\n", cpu);
continue;
}
if (parse_cpu_capacity(cn, cpu)) {
of_node_put(cn);
continue;
}
cap_from_dt = false;
for (cpu_eff = table_efficiency; cpu_eff->compatible; cpu_eff++)
if (of_device_is_compatible(cn, cpu_eff->compatible))
break;
if (cpu_eff->compatible == NULL)
continue;
rate = of_get_property(cn, "clock-frequency", &len);
if (!rate || len != 4) {
pr_err("%s missing clock-frequency property\n",
cn->full_name);
continue;
}
capacity = ((be32_to_cpup(rate)) >> 20) * cpu_eff->efficiency;
if (capacity < min_capacity)
min_capacity = capacity;
if (capacity > max_capacity)
max_capacity = capacity;
cpu_capacity(cpu) = capacity;
}
if (4*max_capacity < (3*(max_capacity + min_capacity)))
middle_capacity = (min_capacity + max_capacity)
>> (SCHED_CAPACITY_SHIFT+1);
else
middle_capacity = ((max_capacity / 3)
>> (SCHED_CAPACITY_SHIFT-1)) + 1;
if (cap_from_dt && !cap_parsing_failed)
normalize_cpu_capacity();
}
static void update_cpu_capacity(unsigned int cpu)
{
if (!cpu_capacity(cpu) || cap_from_dt)
return;
set_capacity_scale(cpu, cpu_capacity(cpu) / middle_capacity);
pr_info("CPU%u: update cpu_capacity %lu\n",
cpu, arch_scale_cpu_capacity(NULL, cpu));
}
static inline void parse_dt_topology(void) {}
static inline void update_cpu_capacity(unsigned int cpuid) {}
const struct cpumask *cpu_coregroup_mask(int cpu)
{
return &cpu_topology[cpu].core_sibling;
}
const struct cpumask *cpu_corepower_mask(int cpu)
{
return &cpu_topology[cpu].thread_sibling;
}
static void update_siblings_masks(unsigned int cpuid)
{
struct cputopo_arm *cpu_topo, *cpuid_topo = &cpu_topology[cpuid];
int cpu;
for_each_possible_cpu(cpu) {
cpu_topo = &cpu_topology[cpu];
if (cpuid_topo->socket_id != cpu_topo->socket_id)
continue;
cpumask_set_cpu(cpuid, &cpu_topo->core_sibling);
if (cpu != cpuid)
cpumask_set_cpu(cpu, &cpuid_topo->core_sibling);
if (cpuid_topo->core_id != cpu_topo->core_id)
continue;
cpumask_set_cpu(cpuid, &cpu_topo->thread_sibling);
if (cpu != cpuid)
cpumask_set_cpu(cpu, &cpuid_topo->thread_sibling);
}
smp_wmb();
}
void store_cpu_topology(unsigned int cpuid)
{
struct cputopo_arm *cpuid_topo = &cpu_topology[cpuid];
unsigned int mpidr;
if (cpuid_topo->core_id != -1)
return;
mpidr = read_cpuid_mpidr();
if ((mpidr & MPIDR_SMP_BITMASK) == MPIDR_SMP_VALUE) {
if (mpidr & MPIDR_MT_BITMASK) {
cpuid_topo->thread_id = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cpuid_topo->core_id = MPIDR_AFFINITY_LEVEL(mpidr, 1);
cpuid_topo->socket_id = MPIDR_AFFINITY_LEVEL(mpidr, 2);
} else {
cpuid_topo->thread_id = -1;
cpuid_topo->core_id = MPIDR_AFFINITY_LEVEL(mpidr, 0);
cpuid_topo->socket_id = MPIDR_AFFINITY_LEVEL(mpidr, 1);
}
} else {
cpuid_topo->thread_id = -1;
cpuid_topo->core_id = 0;
cpuid_topo->socket_id = -1;
}
update_siblings_masks(cpuid);
update_cpu_capacity(cpuid);
pr_info("CPU%u: thread %d, cpu %d, socket %d, mpidr %x\n",
cpuid, cpu_topology[cpuid].thread_id,
cpu_topology[cpuid].core_id,
cpu_topology[cpuid].socket_id, mpidr);
}
static inline int cpu_corepower_flags(void)
{
return SD_SHARE_PKG_RESOURCES | SD_SHARE_POWERDOMAIN;
}
void __init init_cpu_topology(void)
{
unsigned int cpu;
for_each_possible_cpu(cpu) {
struct cputopo_arm *cpu_topo = &(cpu_topology[cpu]);
cpu_topo->thread_id = -1;
cpu_topo->core_id = -1;
cpu_topo->socket_id = -1;
cpumask_clear(&cpu_topo->core_sibling);
cpumask_clear(&cpu_topo->thread_sibling);
}
smp_wmb();
parse_dt_topology();
set_sched_topology(arm_topology);
}
