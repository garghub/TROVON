unsigned long profile_pc(struct pt_regs *regs)
{
extern char __copy_user_begin[], __copy_user_end[];
extern char __bzero_begin[], __bzero_end[];
unsigned long pc = regs->pc;
if (in_lock_functions(pc) ||
(pc >= (unsigned long) __copy_user_begin &&
pc < (unsigned long) __copy_user_end) ||
(pc >= (unsigned long) __bzero_begin &&
pc < (unsigned long) __bzero_end))
pc = regs->u_regs[UREG_RETPC];
return pc;
}
int update_persistent_clock(struct timespec now)
{
return set_rtc_mmss(now.tv_sec);
}
irqreturn_t notrace timer_interrupt(int dummy, void *dev_id)
{
if (timer_cs_enabled) {
write_seqlock(&timer_cs_lock);
timer_cs_internal_counter++;
sparc_config.clear_clock_irq();
write_sequnlock(&timer_cs_lock);
} else {
sparc_config.clear_clock_irq();
}
if (timer_ce_enabled)
timer_ce.event_handler(&timer_ce);
return IRQ_HANDLED;
}
static void timer_ce_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
case CLOCK_EVT_MODE_RESUME:
timer_ce_enabled = 1;
break;
case CLOCK_EVT_MODE_SHUTDOWN:
timer_ce_enabled = 0;
break;
default:
break;
}
smp_mb();
}
static __init void setup_timer_ce(void)
{
struct clock_event_device *ce = &timer_ce;
BUG_ON(smp_processor_id() != boot_cpu_id);
ce->name = "timer_ce";
ce->rating = 100;
ce->features = CLOCK_EVT_FEAT_PERIODIC;
ce->set_mode = timer_ce_set_mode;
ce->cpumask = cpu_possible_mask;
ce->shift = 32;
ce->mult = div_sc(sparc_config.clock_rate, NSEC_PER_SEC,
ce->shift);
clockevents_register_device(ce);
}
static unsigned int sbus_cycles_offset(void)
{
u32 val, offset;
val = sbus_readl(master_l10_counter);
offset = (val >> TIMER_VALUE_SHIFT) & TIMER_VALUE_MASK;
if (val & TIMER_LIMIT_BIT)
offset += sparc_config.cs_period;
return offset;
}
static cycle_t timer_cs_read(struct clocksource *cs)
{
unsigned int seq, offset;
u64 cycles;
do {
seq = read_seqbegin(&timer_cs_lock);
cycles = timer_cs_internal_counter;
offset = sparc_config.get_cycles_offset();
} while (read_seqretry(&timer_cs_lock, seq));
cycles *= sparc_config.cs_period;
cycles += offset;
return cycles;
}
static __init int setup_timer_cs(void)
{
timer_cs_enabled = 1;
return clocksource_register_hz(&timer_cs, sparc_config.clock_rate);
}
static void percpu_ce_setup(enum clock_event_mode mode,
struct clock_event_device *evt)
{
int cpu = cpumask_first(evt->cpumask);
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
sparc_config.load_profile_irq(cpu,
SBUS_CLOCK_RATE / HZ);
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_SHUTDOWN:
case CLOCK_EVT_MODE_UNUSED:
sparc_config.load_profile_irq(cpu, 0);
break;
default:
break;
}
}
static int percpu_ce_set_next_event(unsigned long delta,
struct clock_event_device *evt)
{
int cpu = cpumask_first(evt->cpumask);
unsigned int next = (unsigned int)delta;
sparc_config.load_profile_irq(cpu, next);
return 0;
}
void register_percpu_ce(int cpu)
{
struct clock_event_device *ce = &per_cpu(sparc32_clockevent, cpu);
unsigned int features = CLOCK_EVT_FEAT_PERIODIC;
if (sparc_config.features & FEAT_L14_ONESHOT)
features |= CLOCK_EVT_FEAT_ONESHOT;
ce->name = "percpu_ce";
ce->rating = 200;
ce->features = features;
ce->set_mode = percpu_ce_setup;
ce->set_next_event = percpu_ce_set_next_event;
ce->cpumask = cpumask_of(cpu);
ce->shift = 32;
ce->mult = div_sc(sparc_config.clock_rate, NSEC_PER_SEC,
ce->shift);
ce->max_delta_ns = clockevent_delta2ns(sparc_config.clock_rate, ce);
ce->min_delta_ns = clockevent_delta2ns(100, ce);
clockevents_register_device(ce);
}
static unsigned char mostek_read_byte(struct device *dev, u32 ofs)
{
struct platform_device *pdev = to_platform_device(dev);
struct m48t59_plat_data *pdata = pdev->dev.platform_data;
return readb(pdata->ioaddr + ofs);
}
static void mostek_write_byte(struct device *dev, u32 ofs, u8 val)
{
struct platform_device *pdev = to_platform_device(dev);
struct m48t59_plat_data *pdata = pdev->dev.platform_data;
writeb(val, pdata->ioaddr + ofs);
}
static int clock_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
const char *model = of_get_property(dp, "model", NULL);
if (!model)
return -ENODEV;
if (!of_find_property(dp, "address", NULL))
return -ENODEV;
m48t59_rtc.resource = &op->resource[0];
if (!strcmp(model, "mk48t02")) {
m48t59_data.ioaddr = of_ioremap(&op->resource[0], 0,
2048, "rtc-m48t59");
m48t59_data.type = M48T59RTC_TYPE_M48T02;
} else if (!strcmp(model, "mk48t08")) {
m48t59_data.ioaddr = of_ioremap(&op->resource[0], 0,
8192, "rtc-m48t59");
m48t59_data.type = M48T59RTC_TYPE_M48T08;
} else
return -ENODEV;
if (platform_device_register(&m48t59_rtc) < 0)
printk(KERN_ERR "Registering RTC device failed\n");
return 0;
}
static int __init clock_init(void)
{
return platform_driver_register(&clock_driver);
}
static void __init sparc32_late_time_init(void)
{
if (sparc_config.features & FEAT_L10_CLOCKEVENT)
setup_timer_ce();
if (sparc_config.features & FEAT_L10_CLOCKSOURCE)
setup_timer_cs();
#ifdef CONFIG_SMP
register_percpu_ce(smp_processor_id());
#endif
}
static void __init sbus_time_init(void)
{
sparc_config.get_cycles_offset = sbus_cycles_offset;
sparc_config.init_timers();
}
void __init time_init(void)
{
sparc_config.features = 0;
late_time_init = sparc32_late_time_init;
if (pcic_present())
pci_time_init();
else
sbus_time_init();
}
static int set_rtc_mmss(unsigned long secs)
{
struct rtc_device *rtc = rtc_class_open("rtc0");
int err = -1;
if (rtc) {
err = rtc_set_mmss(rtc, secs);
rtc_class_close(rtc);
}
return err;
}
