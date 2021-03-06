static void arch_timer_reg_write(int reg, u32 val)
{
switch (reg) {
case ARCH_TIMER_REG_CTRL:
asm volatile("mcr p15, 0, %0, c14, c2, 1" : : "r" (val));
break;
case ARCH_TIMER_REG_TVAL:
asm volatile("mcr p15, 0, %0, c14, c2, 0" : : "r" (val));
break;
}
isb();
}
static u32 arch_timer_reg_read(int reg)
{
u32 val;
switch (reg) {
case ARCH_TIMER_REG_CTRL:
asm volatile("mrc p15, 0, %0, c14, c2, 1" : "=r" (val));
break;
case ARCH_TIMER_REG_FREQ:
asm volatile("mrc p15, 0, %0, c14, c0, 0" : "=r" (val));
break;
case ARCH_TIMER_REG_TVAL:
asm volatile("mrc p15, 0, %0, c14, c2, 0" : "=r" (val));
break;
default:
BUG();
}
return val;
}
static irqreturn_t arch_timer_handler(int irq, void *dev_id)
{
struct clock_event_device *evt = *(struct clock_event_device **)dev_id;
unsigned long ctrl;
ctrl = arch_timer_reg_read(ARCH_TIMER_REG_CTRL);
if (ctrl & ARCH_TIMER_CTRL_IT_STAT) {
ctrl |= ARCH_TIMER_CTRL_IT_MASK;
arch_timer_reg_write(ARCH_TIMER_REG_CTRL, ctrl);
evt->event_handler(evt);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void arch_timer_disable(void)
{
unsigned long ctrl;
ctrl = arch_timer_reg_read(ARCH_TIMER_REG_CTRL);
ctrl &= ~ARCH_TIMER_CTRL_ENABLE;
arch_timer_reg_write(ARCH_TIMER_REG_CTRL, ctrl);
}
static void arch_timer_set_mode(enum clock_event_mode mode,
struct clock_event_device *clk)
{
switch (mode) {
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_SHUTDOWN:
arch_timer_disable();
break;
default:
break;
}
}
static int arch_timer_set_next_event(unsigned long evt,
struct clock_event_device *unused)
{
unsigned long ctrl;
ctrl = arch_timer_reg_read(ARCH_TIMER_REG_CTRL);
ctrl |= ARCH_TIMER_CTRL_ENABLE;
ctrl &= ~ARCH_TIMER_CTRL_IT_MASK;
arch_timer_reg_write(ARCH_TIMER_REG_TVAL, evt);
arch_timer_reg_write(ARCH_TIMER_REG_CTRL, ctrl);
return 0;
}
static int __cpuinit arch_timer_setup(struct clock_event_device *clk)
{
arch_timer_disable();
clk->features = CLOCK_EVT_FEAT_ONESHOT;
clk->name = "arch_sys_timer";
clk->rating = 450;
clk->set_mode = arch_timer_set_mode;
clk->set_next_event = arch_timer_set_next_event;
clk->irq = arch_timer_ppi;
clockevents_config_and_register(clk, arch_timer_rate,
0xf, 0x7fffffff);
*__this_cpu_ptr(arch_timer_evt) = clk;
enable_percpu_irq(clk->irq, 0);
if (arch_timer_ppi2)
enable_percpu_irq(arch_timer_ppi2, 0);
return 0;
}
static int local_timer_is_architected(void)
{
return (cpu_architecture() >= CPU_ARCH_ARMv7) &&
((read_cpuid_ext(CPUID_EXT_PFR1) >> 16) & 0xf) == 1;
}
static int arch_timer_available(void)
{
unsigned long freq;
if (!local_timer_is_architected())
return -ENXIO;
if (arch_timer_rate == 0) {
arch_timer_reg_write(ARCH_TIMER_REG_CTRL, 0);
freq = arch_timer_reg_read(ARCH_TIMER_REG_FREQ);
if (freq == 0) {
pr_warn("Architected timer frequency not available\n");
return -EINVAL;
}
arch_timer_rate = freq;
}
pr_info_once("Architected local timer running at %lu.%02luMHz.\n",
arch_timer_rate / 1000000, (arch_timer_rate / 10000) % 100);
return 0;
}
static inline cycle_t arch_counter_get_cntpct(void)
{
u32 cvall, cvalh;
asm volatile("mrrc p15, 0, %0, %1, c14" : "=r" (cvall), "=r" (cvalh));
return ((cycle_t) cvalh << 32) | cvall;
}
static inline cycle_t arch_counter_get_cntvct(void)
{
u32 cvall, cvalh;
asm volatile("mrrc p15, 1, %0, %1, c14" : "=r" (cvall), "=r" (cvalh));
return ((cycle_t) cvalh << 32) | cvall;
}
static u32 notrace arch_counter_get_cntvct32(void)
{
cycle_t cntvct = arch_counter_get_cntvct();
return (u32)(cntvct & (u32)~0);
}
static cycle_t arch_counter_read(struct clocksource *cs)
{
return arch_counter_get_cntpct();
}
static void __cpuinit arch_timer_stop(struct clock_event_device *clk)
{
pr_debug("arch_timer_teardown disable IRQ%d cpu #%d\n",
clk->irq, smp_processor_id());
disable_percpu_irq(clk->irq);
if (arch_timer_ppi2)
disable_percpu_irq(arch_timer_ppi2);
arch_timer_set_mode(CLOCK_EVT_MODE_UNUSED, clk);
}
static int __init arch_timer_register(void)
{
int err;
err = arch_timer_available();
if (err)
return err;
arch_timer_evt = alloc_percpu(struct clock_event_device *);
if (!arch_timer_evt)
return -ENOMEM;
clocksource_register_hz(&clocksource_counter, arch_timer_rate);
err = request_percpu_irq(arch_timer_ppi, arch_timer_handler,
"arch_timer", arch_timer_evt);
if (err) {
pr_err("arch_timer: can't register interrupt %d (%d)\n",
arch_timer_ppi, err);
goto out_free;
}
if (arch_timer_ppi2) {
err = request_percpu_irq(arch_timer_ppi2, arch_timer_handler,
"arch_timer", arch_timer_evt);
if (err) {
pr_err("arch_timer: can't register interrupt %d (%d)\n",
arch_timer_ppi2, err);
arch_timer_ppi2 = 0;
goto out_free_irq;
}
}
err = local_timer_register(&arch_timer_ops);
if (err) {
arch_timer_global_evt.cpumask = cpumask_of(0);
err = arch_timer_setup(&arch_timer_global_evt);
}
if (err)
goto out_free_irq;
return 0;
out_free_irq:
free_percpu_irq(arch_timer_ppi, arch_timer_evt);
if (arch_timer_ppi2)
free_percpu_irq(arch_timer_ppi2, arch_timer_evt);
out_free:
free_percpu(arch_timer_evt);
return err;
}
int __init arch_timer_of_register(void)
{
struct device_node *np;
u32 freq;
np = of_find_matching_node(NULL, arch_timer_of_match);
if (!np) {
pr_err("arch_timer: can't find DT node\n");
return -ENODEV;
}
if (!of_property_read_u32(np, "clock-frequency", &freq))
arch_timer_rate = freq;
arch_timer_ppi = irq_of_parse_and_map(np, 0);
arch_timer_ppi2 = irq_of_parse_and_map(np, 1);
pr_info("arch_timer: found %s irqs %d %d\n",
np->name, arch_timer_ppi, arch_timer_ppi2);
return arch_timer_register();
}
int __init arch_timer_sched_clock_init(void)
{
int err;
err = arch_timer_available();
if (err)
return err;
setup_sched_clock(arch_counter_get_cntvct32, 32, arch_timer_rate);
return 0;
}
