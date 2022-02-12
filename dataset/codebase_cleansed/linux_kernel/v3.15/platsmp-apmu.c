static int apmu_power_on(void __iomem *p, int bit)
{
writel_relaxed(BIT(bit), p + WUPCR_OFFS);
while (readl_relaxed(p + WUPCR_OFFS) != 0)
;
return 0;
}
static int apmu_power_off(void __iomem *p, int bit)
{
writel_relaxed(3, p + CPUNCR_OFFS(bit));
return 0;
}
static int apmu_power_off_poll(void __iomem *p, int bit)
{
int k;
for (k = 0; k < 1000; k++) {
if (((readl_relaxed(p + PSTR_OFFS) >> (bit * 4)) & 0x03) == 3)
return 1;
mdelay(1);
}
return 0;
}
static int apmu_wrap(int cpu, int (*fn)(void __iomem *p, int cpu))
{
void __iomem *p = apmu_cpus[cpu].iomem;
return p ? fn(p, apmu_cpus[cpu].bit) : -EINVAL;
}
static void apmu_init_cpu(struct resource *res, int cpu, int bit)
{
if (apmu_cpus[cpu].iomem)
return;
apmu_cpus[cpu].iomem = ioremap_nocache(res->start, resource_size(res));
apmu_cpus[cpu].bit = bit;
pr_debug("apmu ioremap %d %d %pr\n", cpu, bit, res);
}
static void apmu_parse_cfg(void (*fn)(struct resource *res, int cpu, int bit))
{
u32 id;
int k;
int bit, index;
bool is_allowed;
for (k = 0; k < ARRAY_SIZE(apmu_config); k++) {
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
void __init shmobile_smp_apmu_prepare_cpus(unsigned int max_cpus)
{
shmobile_boot_fn = virt_to_phys(shmobile_smp_boot);
shmobile_boot_arg = MPIDR_HWID_BITMASK;
apmu_parse_cfg(apmu_init_cpu);
}
int shmobile_smp_apmu_boot_secondary(unsigned int cpu, struct task_struct *idle)
{
shmobile_smp_hook(cpu, virt_to_phys(shmobile_invalidate_start), 0);
return apmu_wrap(cpu, apmu_power_on);
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
void shmobile_smp_apmu_cpu_die(unsigned int cpu)
{
shmobile_smp_hook(cpu, 0, 0);
apmu_wrap(cpu, apmu_power_off);
cpu_enter_lowpower_a15();
shmobile_smp_sleep();
}
int shmobile_smp_apmu_cpu_kill(unsigned int cpu)
{
return apmu_wrap(cpu, apmu_power_off_poll);
}
