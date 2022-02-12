static irqreturn_t arch_timer_handle_irq(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
unsigned long ctrl;
ctrl = arch_timer_reg_read(ARCH_TIMER_REG_CTRL);
if (ctrl & ARCH_TIMER_CTRL_ISTATUS) {
ctrl |= ARCH_TIMER_CTRL_IMASK;
arch_timer_reg_write(ARCH_TIMER_REG_CTRL, ctrl);
evt->event_handler(evt);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void arch_timer_stop(void)
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
arch_timer_stop();
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
ctrl &= ~ARCH_TIMER_CTRL_IMASK;
arch_timer_reg_write(ARCH_TIMER_REG_TVAL, evt);
arch_timer_reg_write(ARCH_TIMER_REG_CTRL, ctrl);
return 0;
}
static void __cpuinit arch_timer_setup(struct clock_event_device *clk)
{
arch_timer_stop();
clk->features = CLOCK_EVT_FEAT_ONESHOT | CLOCK_EVT_FEAT_C3STOP;
clk->name = "arch_sys_timer";
clk->rating = 400;
clk->set_mode = arch_timer_set_mode;
clk->set_next_event = arch_timer_set_next_event;
clk->irq = arch_timer_ppi;
clk->cpumask = cpumask_of(smp_processor_id());
clockevents_config_and_register(clk, arch_timer_rate,
0xf, 0x7fffffff);
enable_percpu_irq(clk->irq, 0);
arch_counter_enable_user_access();
}
static void __init arch_timer_calibrate(void)
{
if (arch_timer_rate == 0) {
arch_timer_reg_write(ARCH_TIMER_REG_CTRL, 0);
arch_timer_rate = arch_timer_reg_read(ARCH_TIMER_REG_FREQ);
if (arch_timer_rate == 0)
panic("Architected timer frequency is set to zero.\n"
"You must set this in your .dts file\n");
}
sched_clock_mult = NSEC_PER_SEC / arch_timer_rate;
pr_info("Architected local timer running at %u.%02uMHz.\n",
arch_timer_rate / 1000000, (arch_timer_rate / 10000) % 100);
}
static cycle_t arch_counter_read(struct clocksource *cs)
{
return arch_counter_get_cntpct();
}
int read_current_timer(unsigned long *timer_value)
{
*timer_value = arch_counter_get_cntpct();
return 0;
}
unsigned long long notrace sched_clock(void)
{
return arch_counter_get_cntvct() * sched_clock_mult;
}
static int __cpuinit arch_timer_cpu_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
int cpu = (long)hcpu;
struct clock_event_device *clk = per_cpu_ptr(&arch_timer_evt, cpu);
switch(action) {
case CPU_STARTING:
case CPU_STARTING_FROZEN:
arch_timer_setup(clk);
break;
case CPU_DYING:
case CPU_DYING_FROZEN:
pr_debug("arch_timer_teardown disable IRQ%d cpu #%d\n",
clk->irq, cpu);
disable_percpu_irq(clk->irq);
arch_timer_set_mode(CLOCK_EVT_MODE_UNUSED, clk);
break;
}
return NOTIFY_OK;
}
int __init arm_generic_timer_init(void)
{
struct device_node *np;
int err;
u32 freq;
np = of_find_matching_node(NULL, arch_timer_of_match);
if (!np) {
pr_err("arch_timer: can't find DT node\n");
return -ENODEV;
}
if (!of_property_read_u32(np, "clock-frequency", &freq))
arch_timer_rate = freq;
arch_timer_calibrate();
arch_timer_ppi = irq_of_parse_and_map(np, 0);
pr_info("arch_timer: found %s irq %d\n", np->name, arch_timer_ppi);
err = request_percpu_irq(arch_timer_ppi, arch_timer_handle_irq,
np->name, &arch_timer_evt);
if (err) {
pr_err("arch_timer: can't register interrupt %d (%d)\n",
arch_timer_ppi, err);
return err;
}
clocksource_register_hz(&clocksource_counter, arch_timer_rate);
lpj_fine = arch_timer_rate / HZ;
arch_timer_setup(per_cpu_ptr(&arch_timer_evt, smp_processor_id()));
register_cpu_notifier(&arch_timer_cpu_nb);
return 0;
}
