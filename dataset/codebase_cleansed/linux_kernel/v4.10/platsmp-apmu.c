static int __maybe_unused apmu_power_on(void __iomem *p, int bit)
{
writel_relaxed(BIT(bit), p + WUPCR_OFFS);
while (readl_relaxed(p + WUPCR_OFFS) != 0)
;
return 0;
}
static int __maybe_unused apmu_power_off(void __iomem *p, int bit)
{
writel_relaxed(3, p + CPUNCR_OFFS(bit));
return 0;
}
static int __maybe_unused apmu_power_off_poll(void __iomem *p, int bit)
{
int k;
for (k = 0; k < 1000; k++) {
if (((readl_relaxed(p + PSTR_OFFS) >> (bit * 4)) & 0x03) == 3)
return 1;
mdelay(1);
}
return 0;
}
static int __maybe_unused apmu_wrap(int cpu, int (*fn)(void __iomem *p, int cpu))
{
void __iomem *p = apmu_cpus[cpu].iomem;
return p ? fn(p, apmu_cpus[cpu].bit) : -EINVAL;
}
static void apmu_init_cpu(struct resource *res, int cpu, int bit)
{
if ((cpu >= ARRAY_SIZE(apmu_cpus)) || apmu_cpus[cpu].iomem)
return;
apmu_cpus[cpu].iomem = ioremap_nocache(res->start, resource_size(res));
apmu_cpus[cpu].bit = bit;
pr_debug("apmu ioremap %d %d %pr\n", cpu, bit, res);
}
static void apmu_parse_cfg(void (*fn)(struct resource *res, int cpu, int bit),
struct rcar_apmu_config *apmu_config, int num)
{
int id;
int k;
int bit, index;
bool is_allowed;
for (k = 0; k < num; k++) {
is_allowed = false;
for (bit = 0; bit < ARRAY_SIZE(apmu_config[k].cpus); bit++) {
id = apmu_config[k].cpus[bit];
if (id >= 0) {
if (id == cpu_logical_map(0))
is_allowed = true;
}
}
if (!is_allowed)
continue;
for (bit = 0; bit < ARRAY_SIZE(apmu_config[k].cpus); bit++) {
id = apmu_config[k].cpus[bit];
if (id >= 0) {
index = get_logical_index(id);
if (index >= 0)
fn(&apmu_config[k].iomem, index, bit);
}
}
}
}
static void apmu_parse_dt(void (*fn)(struct resource *res, int cpu, int bit))
{
struct device_node *np_apmu, *np_cpu;
struct resource res;
int bit, index;
u32 id;
for_each_matching_node(np_apmu, apmu_ids) {
bool is_allowed = false;
for (bit = 0; bit < CONFIG_NR_CPUS; bit++) {
np_cpu = of_parse_phandle(np_apmu, "cpus", bit);
if (np_cpu) {
if (!of_property_read_u32(np_cpu, "reg", &id)) {
if (id == cpu_logical_map(0)) {
is_allowed = true;
of_node_put(np_cpu);
break;
}
}
of_node_put(np_cpu);
}
}
if (!is_allowed)
continue;
for (bit = 0; bit < CONFIG_NR_CPUS; bit++) {
np_cpu = of_parse_phandle(np_apmu, "cpus", bit);
if (np_cpu) {
if (!of_property_read_u32(np_cpu, "reg", &id)) {
index = get_logical_index(id);
if ((index >= 0) &&
!of_address_to_resource(np_apmu,
0, &res))
fn(&res, index, bit);
}
of_node_put(np_cpu);
}
}
}
}
static void __init shmobile_smp_apmu_setup_boot(void)
{
shmobile_boot_fn = virt_to_phys(shmobile_smp_boot);
}
void __init shmobile_smp_apmu_prepare_cpus(unsigned int max_cpus,
struct rcar_apmu_config *apmu_config,
int num)
{
shmobile_smp_apmu_setup_boot();
apmu_parse_cfg(apmu_init_cpu, apmu_config, num);
}
int shmobile_smp_apmu_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
shmobile_smp_hook(cpu, virt_to_phys(secondary_startup), 0);
return apmu_wrap(cpu, apmu_power_on);
}
static void __init shmobile_smp_apmu_prepare_cpus_dt(unsigned int max_cpus)
{
shmobile_smp_apmu_setup_boot();
apmu_parse_dt(apmu_init_cpu);
rcar_gen2_pm_init();
}
static int shmobile_smp_apmu_boot_secondary_md21(unsigned int cpu,
struct task_struct *idle)
{
if (rcar_gen2_read_mode_pins() & BIT(21)) {
pr_warn("Unable to boot CPU%u when MD21 is set\n", cpu);
return -ENOTSUPP;
}
return shmobile_smp_apmu_boot_secondary(cpu, idle);
}
static inline void cpu_enter_lowpower_a15(void)
{
unsigned int v;
asm volatile(
" mrc p15, 0, %0, c1, c0, 0\n"
" bic %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 0\n"
: "=&r" (v)
: "Ir" (CR_C)
: "cc");
flush_cache_louis();
asm volatile(
" mrc p15, 0, %0, c1, c0, 1\n"
" bic %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 1\n"
: "=&r" (v)
: "Ir" (0x40)
: "cc");
isb();
dsb();
}
static void shmobile_smp_apmu_cpu_shutdown(unsigned int cpu)
{
apmu_wrap(cpu, apmu_power_off);
cpu_enter_lowpower_a15();
}
static inline void cpu_leave_lowpower(void)
{
unsigned int v;
asm volatile("mrc p15, 0, %0, c1, c0, 0\n"
" orr %0, %0, %1\n"
" mcr p15, 0, %0, c1, c0, 0\n"
" mrc p15, 0, %0, c1, c0, 1\n"
" orr %0, %0, %2\n"
" mcr p15, 0, %0, c1, c0, 1\n"
: "=&r" (v)
: "Ir" (CR_C), "Ir" (0x40)
: "cc");
}
void shmobile_smp_apmu_cpu_die(unsigned int cpu)
{
shmobile_smp_hook(cpu, 0, 0);
shmobile_smp_apmu_cpu_shutdown(cpu);
shmobile_smp_sleep();
}
int shmobile_smp_apmu_cpu_kill(unsigned int cpu)
{
return apmu_wrap(cpu, apmu_power_off_poll);
}
static int shmobile_smp_apmu_do_suspend(unsigned long cpu)
{
shmobile_smp_hook(cpu, virt_to_phys(cpu_resume), 0);
shmobile_smp_apmu_cpu_shutdown(cpu);
cpu_do_idle();
return 1;
}
static int shmobile_smp_apmu_enter_suspend(suspend_state_t state)
{
cpu_suspend(smp_processor_id(), shmobile_smp_apmu_do_suspend);
cpu_leave_lowpower();
return 0;
}
void __init shmobile_smp_apmu_suspend_init(void)
{
shmobile_suspend_ops.enter = shmobile_smp_apmu_enter_suspend;
}
