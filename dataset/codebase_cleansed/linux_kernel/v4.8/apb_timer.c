static inline void __iomem *adev_virt_addr(struct apbt_dev *adev)
{
return apbt_virt_address + adev->num * APBTMRS_REG_SIZE;
}
static inline void apbt_set_mapping(void)
{
struct sfi_timer_table_entry *mtmr;
int phy_cs_timer_id = 0;
if (apbt_virt_address) {
pr_debug("APBT base already mapped\n");
return;
}
mtmr = sfi_get_mtmr(APBT_CLOCKEVENT0_NUM);
if (mtmr == NULL) {
printk(KERN_ERR "Failed to get MTMR %d from SFI\n",
APBT_CLOCKEVENT0_NUM);
return;
}
apbt_address = (phys_addr_t)mtmr->phys_addr;
if (!apbt_address) {
printk(KERN_WARNING "No timer base from SFI, use default\n");
apbt_address = APBT_DEFAULT_BASE;
}
apbt_virt_address = ioremap_nocache(apbt_address, APBT_MMAP_SIZE);
if (!apbt_virt_address) {
pr_debug("Failed mapping APBT phy address at %lu\n",\
(unsigned long)apbt_address);
goto panic_noapbt;
}
apbt_freq = mtmr->freq_hz;
sfi_free_mtmr(mtmr);
mtmr = sfi_get_mtmr(APBT_CLOCKSOURCE_NUM);
if (mtmr == NULL)
goto panic_noapbt;
pr_debug("Use timer %d for clocksource\n",
(int)(mtmr->phys_addr & 0xff) / APBTMRS_REG_SIZE);
phy_cs_timer_id = (unsigned int)(mtmr->phys_addr & 0xff) /
APBTMRS_REG_SIZE;
clocksource_apbt = dw_apb_clocksource_init(APBT_CLOCKSOURCE_RATING,
"apbt0", apbt_virt_address + phy_cs_timer_id *
APBTMRS_REG_SIZE, apbt_freq);
return;
panic_noapbt:
panic("Failed to setup APB system timer\n");
}
static inline void apbt_clear_mapping(void)
{
iounmap(apbt_virt_address);
apbt_virt_address = NULL;
}
static int __init apbt_clockevent_register(void)
{
struct sfi_timer_table_entry *mtmr;
struct apbt_dev *adev = this_cpu_ptr(&cpu_apbt_dev);
mtmr = sfi_get_mtmr(APBT_CLOCKEVENT0_NUM);
if (mtmr == NULL) {
printk(KERN_ERR "Failed to get MTMR %d from SFI\n",
APBT_CLOCKEVENT0_NUM);
return -ENODEV;
}
adev->num = smp_processor_id();
adev->timer = dw_apb_clockevent_init(smp_processor_id(), "apbt0",
intel_mid_timer_options == INTEL_MID_TIMER_LAPIC_APBT ?
APBT_CLOCKEVENT_RATING - 100 : APBT_CLOCKEVENT_RATING,
adev_virt_addr(adev), 0, apbt_freq);
adev->timer->eoi = NULL;
if (intel_mid_timer_options == INTEL_MID_TIMER_LAPIC_APBT) {
global_clock_event = &adev->timer->ced;
printk(KERN_DEBUG "%s clockevent registered as global\n",
global_clock_event->name);
}
dw_apb_clockevent_register(adev->timer);
sfi_free_mtmr(mtmr);
return 0;
}
static void apbt_setup_irq(struct apbt_dev *adev)
{
irq_modify_status(adev->irq, 0, IRQ_MOVE_PCNTXT);
irq_set_affinity(adev->irq, cpumask_of(adev->cpu));
}
void apbt_setup_secondary_clock(void)
{
struct apbt_dev *adev;
int cpu;
cpu = smp_processor_id();
if (!cpu)
return;
adev = this_cpu_ptr(&cpu_apbt_dev);
if (!adev->timer) {
adev->timer = dw_apb_clockevent_init(cpu, adev->name,
APBT_CLOCKEVENT_RATING, adev_virt_addr(adev),
adev->irq, apbt_freq);
adev->timer->eoi = NULL;
} else {
dw_apb_clockevent_resume(adev->timer);
}
printk(KERN_INFO "Registering CPU %d clockevent device %s, cpu %08x\n",
cpu, adev->name, adev->cpu);
apbt_setup_irq(adev);
dw_apb_clockevent_register(adev->timer);
return;
}
static int apbt_cpu_dead(unsigned int cpu)
{
struct apbt_dev *adev = &per_cpu(cpu_apbt_dev, cpu);
dw_apb_clockevent_pause(adev->timer);
if (system_state == SYSTEM_RUNNING) {
pr_debug("skipping APBT CPU %u offline\n", cpu);
} else {
pr_debug("APBT clockevent for cpu %u offline\n", cpu);
dw_apb_clockevent_stop(adev->timer);
}
return 0;
}
static __init int apbt_late_init(void)
{
if (intel_mid_timer_options == INTEL_MID_TIMER_LAPIC_APBT ||
!apb_timer_block_enabled)
return 0;
return cpuhp_setup_state(CPUHP_X86_APB_DEAD, "X86_APB_DEAD", NULL,
apbt_cpu_dead);
}
void apbt_setup_secondary_clock(void) {}
static int apbt_clocksource_register(void)
{
u64 start, now;
cycle_t t1;
dw_apb_clocksource_start(clocksource_apbt);
t1 = dw_apb_clocksource_read(clocksource_apbt);
start = rdtsc();
do {
rep_nop();
now = rdtsc();
} while ((now - start) < 200000UL);
if (t1 == dw_apb_clocksource_read(clocksource_apbt))
panic("APBT counter not counting. APBT disabled\n");
dw_apb_clocksource_register(clocksource_apbt);
return 0;
}
void __init apbt_time_init(void)
{
#ifdef CONFIG_SMP
int i;
struct sfi_timer_table_entry *p_mtmr;
struct apbt_dev *adev;
#endif
if (apb_timer_block_enabled)
return;
apbt_set_mapping();
if (!apbt_virt_address)
goto out_noapbt;
if (apbt_freq < APBT_MIN_FREQ || apbt_freq > APBT_MAX_FREQ) {
pr_debug("APBT has invalid freq 0x%lx\n", apbt_freq);
goto out_noapbt;
}
if (apbt_clocksource_register()) {
pr_debug("APBT has failed to register clocksource\n");
goto out_noapbt;
}
if (!apbt_clockevent_register())
apb_timer_block_enabled = 1;
else {
pr_debug("APBT has failed to register clockevent\n");
goto out_noapbt;
}
#ifdef CONFIG_SMP
if (intel_mid_timer_options == INTEL_MID_TIMER_LAPIC_APBT) {
printk(KERN_INFO "apbt: disabled per cpu timer\n");
return;
}
pr_debug("%s: %d CPUs online\n", __func__, num_online_cpus());
if (num_possible_cpus() <= sfi_mtimer_num)
apbt_num_timers_used = num_possible_cpus();
else
apbt_num_timers_used = 1;
pr_debug("%s: %d APB timers used\n", __func__, apbt_num_timers_used);
for (i = 0; i < apbt_num_timers_used; i++) {
adev = &per_cpu(cpu_apbt_dev, i);
adev->num = i;
adev->cpu = i;
p_mtmr = sfi_get_mtmr(i);
if (p_mtmr)
adev->irq = p_mtmr->irq;
else
printk(KERN_ERR "Failed to get timer for cpu %d\n", i);
snprintf(adev->name, sizeof(adev->name) - 1, "apbt%d", i);
}
#endif
return;
out_noapbt:
apbt_clear_mapping();
apb_timer_block_enabled = 0;
panic("failed to enable APB timer\n");
}
unsigned long apbt_quick_calibrate(void)
{
int i, scale;
u64 old, new;
cycle_t t1, t2;
unsigned long khz = 0;
u32 loop, shift;
apbt_set_mapping();
dw_apb_clocksource_start(clocksource_apbt);
old = dw_apb_clocksource_read(clocksource_apbt);
i = 10000;
while (--i) {
if (old != dw_apb_clocksource_read(clocksource_apbt))
break;
}
if (!i)
goto failed;
loop = (apbt_freq / 1000) << 4;
dw_apb_clocksource_start(clocksource_apbt);
old = dw_apb_clocksource_read(clocksource_apbt);
old += loop;
t1 = rdtsc();
do {
new = dw_apb_clocksource_read(clocksource_apbt);
} while (new < old);
t2 = rdtsc();
shift = 5;
if (unlikely(loop >> shift == 0)) {
printk(KERN_INFO
"APBT TSC calibration failed, not enough resolution\n");
return 0;
}
scale = (int)div_u64((t2 - t1), loop >> shift);
khz = (scale * (apbt_freq / 1000)) >> shift;
printk(KERN_INFO "TSC freq calculated by APB timer is %lu khz\n", khz);
return khz;
failed:
return 0;
}
