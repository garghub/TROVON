static inline unsigned long apbt_readl_reg(unsigned long a)
{
return readl(apbt_virt_address + a);
}
static inline void apbt_writel_reg(unsigned long d, unsigned long a)
{
writel(d, apbt_virt_address + a);
}
static inline unsigned long apbt_readl(int n, unsigned long a)
{
return readl(apbt_virt_address + a + n * APBTMRS_REG_SIZE);
}
static inline void apbt_writel(int n, unsigned long d, unsigned long a)
{
writel(d, apbt_virt_address + a + n * APBTMRS_REG_SIZE);
}
static inline void apbt_set_mapping(void)
{
struct sfi_timer_table_entry *mtmr;
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
apbt_address = (unsigned long)mtmr->phys_addr;
if (!apbt_address) {
printk(KERN_WARNING "No timer base from SFI, use default\n");
apbt_address = APBT_DEFAULT_BASE;
}
apbt_virt_address = ioremap_nocache(apbt_address, APBT_MMAP_SIZE);
if (apbt_virt_address) {
pr_debug("Mapped APBT physical addr %p at virtual addr %p\n",\
(void *)apbt_address, (void *)apbt_virt_address);
} else {
pr_debug("Failed mapping APBT phy address at %p\n",\
(void *)apbt_address);
goto panic_noapbt;
}
apbt_freq = mtmr->freq_hz / USEC_PER_SEC;
sfi_free_mtmr(mtmr);
mtmr = sfi_get_mtmr(APBT_CLOCKSOURCE_NUM);
if (mtmr == NULL)
goto panic_noapbt;
phy_cs_timer_id = (unsigned int)(mtmr->phys_addr & 0xff)
/ APBTMRS_REG_SIZE;
pr_debug("Use timer %d for clocksource\n", phy_cs_timer_id);
return;
panic_noapbt:
panic("Failed to setup APB system timer\n");
}
static inline void apbt_clear_mapping(void)
{
iounmap(apbt_virt_address);
apbt_virt_address = NULL;
}
static inline int is_apbt_capable(void)
{
return apbt_virt_address ? 1 : 0;
}
static void apbt_start_counter(int n)
{
unsigned long ctrl = apbt_readl(n, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
apbt_writel(n, ctrl, APBTMR_N_CONTROL);
apbt_writel(n, ~0, APBTMR_N_LOAD_COUNT);
ctrl &= ~APBTMR_CONTROL_MODE_PERIODIC;
ctrl |= (APBTMR_CONTROL_ENABLE | APBTMR_CONTROL_INT);
apbt_writel(n, ctrl, APBTMR_N_CONTROL);
apbt_read_clocksource(&clocksource_apbt);
}
static irqreturn_t apbt_interrupt_handler(int irq, void *data)
{
struct apbt_dev *dev = (struct apbt_dev *)data;
struct clock_event_device *aevt = &dev->evt;
if (!aevt->event_handler) {
printk(KERN_INFO "Spurious APBT timer interrupt on %d\n",
dev->num);
return IRQ_NONE;
}
aevt->event_handler(aevt);
return IRQ_HANDLED;
}
static void apbt_restart_clocksource(struct clocksource *cs)
{
apbt_start_counter(phy_cs_timer_id);
}
static void apbt_enable_int(int n)
{
unsigned long ctrl = apbt_readl(n, APBTMR_N_CONTROL);
apbt_readl(n, APBTMR_N_EOI);
ctrl &= ~APBTMR_CONTROL_INT;
apbt_writel(n, ctrl, APBTMR_N_CONTROL);
}
static void apbt_disable_int(int n)
{
unsigned long ctrl = apbt_readl(n, APBTMR_N_CONTROL);
ctrl |= APBTMR_CONTROL_INT;
apbt_writel(n, ctrl, APBTMR_N_CONTROL);
}
static int __init apbt_clockevent_register(void)
{
struct sfi_timer_table_entry *mtmr;
struct apbt_dev *adev = &__get_cpu_var(cpu_apbt_dev);
mtmr = sfi_get_mtmr(APBT_CLOCKEVENT0_NUM);
if (mtmr == NULL) {
printk(KERN_ERR "Failed to get MTMR %d from SFI\n",
APBT_CLOCKEVENT0_NUM);
return -ENODEV;
}
apbt_clockevent.mult = div_sc((unsigned long) mtmr->freq_hz
, NSEC_PER_SEC, APBT_SHIFT);
apbt_clockevent.max_delta_ns = clockevent_delta2ns(0x7FFFFFFF,
&apbt_clockevent);
apbt_clockevent.min_delta_ns = clockevent_delta2ns(
APBT_MIN_DELTA_USEC*apbt_freq,
&apbt_clockevent);
apbt_clockevent.cpumask = cpumask_of(smp_processor_id());
adev->num = smp_processor_id();
memcpy(&adev->evt, &apbt_clockevent, sizeof(struct clock_event_device));
if (mrst_timer_options == MRST_TIMER_LAPIC_APBT) {
adev->evt.rating = APBT_CLOCKEVENT_RATING - 100;
global_clock_event = &adev->evt;
printk(KERN_DEBUG "%s clockevent registered as global\n",
global_clock_event->name);
}
if (request_irq(apbt_clockevent.irq, apbt_interrupt_handler,
IRQF_TIMER | IRQF_DISABLED | IRQF_NOBALANCING,
apbt_clockevent.name, adev)) {
printk(KERN_ERR "Failed request IRQ for APBT%d\n",
apbt_clockevent.irq);
}
clockevents_register_device(&adev->evt);
apbt_enable_int(APBT_CLOCKEVENT0_NUM);
sfi_free_mtmr(mtmr);
return 0;
}
static void apbt_setup_irq(struct apbt_dev *adev)
{
if (adev->irq == 0)
return;
irq_modify_status(adev->irq, 0, IRQ_MOVE_PCNTXT);
irq_set_affinity(adev->irq, cpumask_of(adev->cpu));
__irq_set_handler(adev->irq, handle_edge_irq, 0, "edge");
if (system_state == SYSTEM_BOOTING) {
if (request_irq(adev->irq, apbt_interrupt_handler,
IRQF_TIMER | IRQF_DISABLED |
IRQF_NOBALANCING,
adev->name, adev)) {
printk(KERN_ERR "Failed request IRQ for APBT%d\n",
adev->num);
}
} else
enable_irq(adev->irq);
}
void apbt_setup_secondary_clock(void)
{
struct apbt_dev *adev;
struct clock_event_device *aevt;
int cpu;
cpu = smp_processor_id();
if (!cpu)
return;
printk(KERN_INFO "Init per CPU clockevent %d\n", cpu);
adev = &per_cpu(cpu_apbt_dev, cpu);
aevt = &adev->evt;
memcpy(aevt, &apbt_clockevent, sizeof(*aevt));
aevt->cpumask = cpumask_of(cpu);
aevt->name = adev->name;
aevt->mode = CLOCK_EVT_MODE_UNUSED;
printk(KERN_INFO "Registering CPU %d clockevent device %s, mask %08x\n",
cpu, aevt->name, *(u32 *)aevt->cpumask);
apbt_setup_irq(adev);
clockevents_register_device(aevt);
apbt_enable_int(cpu);
return;
}
static int apbt_cpuhp_notify(struct notifier_block *n,
unsigned long action, void *hcpu)
{
unsigned long cpu = (unsigned long)hcpu;
struct apbt_dev *adev = &per_cpu(cpu_apbt_dev, cpu);
switch (action & 0xf) {
case CPU_DEAD:
disable_irq(adev->irq);
apbt_disable_int(cpu);
if (system_state == SYSTEM_RUNNING) {
pr_debug("skipping APBT CPU %lu offline\n", cpu);
} else if (adev) {
pr_debug("APBT clockevent for cpu %lu offline\n", cpu);
free_irq(adev->irq, adev);
}
break;
default:
pr_debug("APBT notified %lu, no action\n", action);
}
return NOTIFY_OK;
}
static __init int apbt_late_init(void)
{
if (mrst_timer_options == MRST_TIMER_LAPIC_APBT ||
!apb_timer_block_enabled)
return 0;
hotcpu_notifier(apbt_cpuhp_notify, -20);
return 0;
}
void apbt_setup_secondary_clock(void) {}
static void apbt_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
unsigned long ctrl;
uint64_t delta;
int timer_num;
struct apbt_dev *adev = EVT_TO_APBT_DEV(evt);
BUG_ON(!apbt_virt_address);
timer_num = adev->num;
pr_debug("%s CPU %d timer %d mode=%d\n",
__func__, first_cpu(*evt->cpumask), timer_num, mode);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
delta = ((uint64_t)(NSEC_PER_SEC/HZ)) * apbt_clockevent.mult;
delta >>= apbt_clockevent.shift;
ctrl = apbt_readl(timer_num, APBTMR_N_CONTROL);
ctrl |= APBTMR_CONTROL_MODE_PERIODIC;
apbt_writel(timer_num, ctrl, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
apbt_writel(timer_num, ctrl, APBTMR_N_CONTROL);
udelay(1);
pr_debug("Setting clock period %d for HZ %d\n", (int)delta, HZ);
apbt_writel(timer_num, delta, APBTMR_N_LOAD_COUNT);
ctrl |= APBTMR_CONTROL_ENABLE;
apbt_writel(timer_num, ctrl, APBTMR_N_CONTROL);
break;
case CLOCK_EVT_MODE_ONESHOT:
ctrl = apbt_readl(timer_num, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
ctrl &= ~APBTMR_CONTROL_MODE_PERIODIC;
apbt_writel(timer_num, ctrl, APBTMR_N_CONTROL);
apbt_writel(timer_num, ctrl, APBTMR_N_CONTROL);
apbt_writel(timer_num, ~0, APBTMR_N_LOAD_COUNT);
ctrl &= ~APBTMR_CONTROL_INT;
ctrl |= APBTMR_CONTROL_ENABLE;
apbt_writel(timer_num, ctrl, APBTMR_N_CONTROL);
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
apbt_disable_int(timer_num);
ctrl = apbt_readl(timer_num, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
apbt_writel(timer_num, ctrl, APBTMR_N_CONTROL);
break;
case CLOCK_EVT_MODE_RESUME:
apbt_enable_int(timer_num);
break;
}
}
static int apbt_next_event(unsigned long delta,
struct clock_event_device *evt)
{
unsigned long ctrl;
int timer_num;
struct apbt_dev *adev = EVT_TO_APBT_DEV(evt);
timer_num = adev->num;
ctrl = apbt_readl(timer_num, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
apbt_writel(timer_num, ctrl, APBTMR_N_CONTROL);
apbt_writel(timer_num, delta, APBTMR_N_LOAD_COUNT);
ctrl |= APBTMR_CONTROL_ENABLE;
apbt_writel(timer_num, ctrl, APBTMR_N_CONTROL);
return 0;
}
static cycle_t apbt_read_clocksource(struct clocksource *cs)
{
unsigned long current_count;
current_count = apbt_readl(phy_cs_timer_id, APBTMR_N_CURRENT_VALUE);
return (cycle_t)~current_count;
}
static int apbt_clocksource_register(void)
{
u64 start, now;
cycle_t t1;
apbt_start_counter(phy_cs_timer_id);
t1 = apbt_read_clocksource(&clocksource_apbt);
rdtscll(start);
do {
rep_nop();
rdtscll(now);
} while ((now - start) < 200000UL);
if (t1 == apbt_read_clocksource(&clocksource_apbt))
panic("APBT counter not counting. APBT disabled\n");
clocksource_register_khz(&clocksource_apbt, (u32)apbt_freq*1000);
return 0;
}
void __init apbt_time_init(void)
{
#ifdef CONFIG_SMP
int i;
struct sfi_timer_table_entry *p_mtmr;
unsigned int percpu_timer;
struct apbt_dev *adev;
#endif
if (apb_timer_block_enabled)
return;
apbt_set_mapping();
if (apbt_virt_address) {
pr_debug("Found APBT version 0x%lx\n",\
apbt_readl_reg(APBTMRS_COMP_VERSION));
} else
goto out_noapbt;
if (apbt_freq < APBT_MIN_FREQ || apbt_freq > APBT_MAX_FREQ) {
pr_debug("APBT has invalid freq 0x%llx\n", apbt_freq);
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
if (mrst_timer_options == MRST_TIMER_LAPIC_APBT) {
printk(KERN_INFO "apbt: disabled per cpu timer\n");
return;
}
pr_debug("%s: %d CPUs online\n", __func__, num_online_cpus());
if (num_possible_cpus() <= sfi_mtimer_num) {
percpu_timer = 1;
apbt_num_timers_used = num_possible_cpus();
} else {
percpu_timer = 0;
apbt_num_timers_used = 1;
adev = &per_cpu(cpu_apbt_dev, 0);
adev->flags &= ~APBT_DEV_USED;
}
pr_debug("%s: %d APB timers used\n", __func__, apbt_num_timers_used);
apbt_devs = kzalloc(sizeof(struct apbt_dev) * apbt_num_timers_used,
GFP_KERNEL);
if (!apbt_devs) {
printk(KERN_ERR "Failed to allocate APB timer devices\n");
return;
}
for (i = 0; i < apbt_num_timers_used; i++) {
adev = &per_cpu(cpu_apbt_dev, i);
adev->num = i;
adev->cpu = i;
p_mtmr = sfi_get_mtmr(i);
if (p_mtmr) {
adev->tick = p_mtmr->freq_hz;
adev->irq = p_mtmr->irq;
} else
printk(KERN_ERR "Failed to get timer for cpu %d\n", i);
adev->count = 0;
sprintf(adev->name, "apbt%d", i);
}
#endif
return;
out_noapbt:
apbt_clear_mapping();
apb_timer_block_enabled = 0;
panic("failed to enable APB timer\n");
}
static inline void apbt_disable(int n)
{
if (is_apbt_capable()) {
unsigned long ctrl = apbt_readl(n, APBTMR_N_CONTROL);
ctrl &= ~APBTMR_CONTROL_ENABLE;
apbt_writel(n, ctrl, APBTMR_N_CONTROL);
}
}
unsigned long apbt_quick_calibrate()
{
int i, scale;
u64 old, new;
cycle_t t1, t2;
unsigned long khz = 0;
u32 loop, shift;
apbt_set_mapping();
apbt_start_counter(phy_cs_timer_id);
old = apbt_read_clocksource(&clocksource_apbt);
i = 10000;
while (--i) {
if (old != apbt_read_clocksource(&clocksource_apbt))
break;
}
if (!i)
goto failed;
loop = (apbt_freq * 1000) << 4;
apbt_start_counter(phy_cs_timer_id);
old = apbt_read_clocksource(&clocksource_apbt);
old += loop;
t1 = __native_read_tsc();
do {
new = apbt_read_clocksource(&clocksource_apbt);
} while (new < old);
t2 = __native_read_tsc();
shift = 5;
if (unlikely(loop >> shift == 0)) {
printk(KERN_INFO
"APBT TSC calibration failed, not enough resolution\n");
return 0;
}
scale = (int)div_u64((t2 - t1), loop >> shift);
khz = (scale * apbt_freq * 1000) >> shift;
printk(KERN_INFO "TSC freq calculated by APB timer is %lu khz\n", khz);
return khz;
failed:
return 0;
}
