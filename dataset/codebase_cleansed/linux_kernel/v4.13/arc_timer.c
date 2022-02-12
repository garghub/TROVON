static int noinline arc_get_timer_clk(struct device_node *node)
{
struct clk *clk;
int ret;
clk = of_clk_get(node, 0);
if (IS_ERR(clk)) {
pr_err("timer missing clk\n");
return PTR_ERR(clk);
}
ret = clk_prepare_enable(clk);
if (ret) {
pr_err("Couldn't enable parent clk\n");
return ret;
}
arc_timer_freq = clk_get_rate(clk);
return 0;
}
static u64 arc_read_gfrc(struct clocksource *cs)
{
unsigned long flags;
u32 l, h;
local_irq_save(flags);
__mcip_cmd(CMD_GFRC_READ_LO, 0);
l = read_aux_reg(ARC_REG_MCIP_READBACK);
__mcip_cmd(CMD_GFRC_READ_HI, 0);
h = read_aux_reg(ARC_REG_MCIP_READBACK);
local_irq_restore(flags);
return (((u64)h) << 32) | l;
}
static int __init arc_cs_setup_gfrc(struct device_node *node)
{
struct mcip_bcr mp;
int ret;
READ_BCR(ARC_REG_MCIP_BCR, mp);
if (!mp.gfrc) {
pr_warn("Global-64-bit-Ctr clocksource not detected\n");
return -ENXIO;
}
ret = arc_get_timer_clk(node);
if (ret)
return ret;
return clocksource_register_hz(&arc_counter_gfrc, arc_timer_freq);
}
static u64 arc_read_rtc(struct clocksource *cs)
{
unsigned long status;
u32 l, h;
do {
l = read_aux_reg(AUX_RTC_LOW);
h = read_aux_reg(AUX_RTC_HIGH);
status = read_aux_reg(AUX_RTC_CTRL);
} while (!(status & _BITUL(31)));
return (((u64)h) << 32) | l;
}
static int __init arc_cs_setup_rtc(struct device_node *node)
{
struct bcr_timer timer;
int ret;
READ_BCR(ARC_REG_TIMERS_BCR, timer);
if (!timer.rtc) {
pr_warn("Local-64-bit-Ctr clocksource not detected\n");
return -ENXIO;
}
if (IS_ENABLED(CONFIG_SMP)) {
pr_warn("Local-64-bit-Ctr not usable in SMP\n");
return -EINVAL;
}
ret = arc_get_timer_clk(node);
if (ret)
return ret;
write_aux_reg(AUX_RTC_CTRL, 1);
return clocksource_register_hz(&arc_counter_rtc, arc_timer_freq);
}
static u64 arc_read_timer1(struct clocksource *cs)
{
return (u64) read_aux_reg(ARC_REG_TIMER1_CNT);
}
static int __init arc_cs_setup_timer1(struct device_node *node)
{
int ret;
if (IS_ENABLED(CONFIG_SMP))
return -EINVAL;
ret = arc_get_timer_clk(node);
if (ret)
return ret;
write_aux_reg(ARC_REG_TIMER1_LIMIT, ARC_TIMERN_MAX);
write_aux_reg(ARC_REG_TIMER1_CNT, 0);
write_aux_reg(ARC_REG_TIMER1_CTRL, TIMER_CTRL_NH);
return clocksource_register_hz(&arc_counter_timer1, arc_timer_freq);
}
static void arc_timer_event_setup(unsigned int cycles)
{
write_aux_reg(ARC_REG_TIMER0_LIMIT, cycles);
write_aux_reg(ARC_REG_TIMER0_CNT, 0);
write_aux_reg(ARC_REG_TIMER0_CTRL, TIMER_CTRL_IE | TIMER_CTRL_NH);
}
static int arc_clkevent_set_next_event(unsigned long delta,
struct clock_event_device *dev)
{
arc_timer_event_setup(delta);
return 0;
}
static int arc_clkevent_set_periodic(struct clock_event_device *dev)
{
arc_timer_event_setup(arc_timer_freq / HZ);
return 0;
}
static irqreturn_t timer_irq_handler(int irq, void *dev_id)
{
struct clock_event_device *evt = this_cpu_ptr(&arc_clockevent_device);
int irq_reenable = clockevent_state_periodic(evt);
write_aux_reg(ARC_REG_TIMER0_CTRL, irq_reenable | TIMER_CTRL_NH);
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int arc_timer_starting_cpu(unsigned int cpu)
{
struct clock_event_device *evt = this_cpu_ptr(&arc_clockevent_device);
evt->cpumask = cpumask_of(smp_processor_id());
clockevents_config_and_register(evt, arc_timer_freq, 0, ARC_TIMERN_MAX);
enable_percpu_irq(arc_timer_irq, 0);
return 0;
}
static int arc_timer_dying_cpu(unsigned int cpu)
{
disable_percpu_irq(arc_timer_irq);
return 0;
}
static int __init arc_clockevent_setup(struct device_node *node)
{
struct clock_event_device *evt = this_cpu_ptr(&arc_clockevent_device);
int ret;
arc_timer_irq = irq_of_parse_and_map(node, 0);
if (arc_timer_irq <= 0) {
pr_err("clockevent: missing irq\n");
return -EINVAL;
}
ret = arc_get_timer_clk(node);
if (ret) {
pr_err("clockevent: missing clk\n");
return ret;
}
ret = request_percpu_irq(arc_timer_irq, timer_irq_handler,
"Timer0 (per-cpu-tick)", evt);
if (ret) {
pr_err("clockevent: unable to request irq\n");
return ret;
}
ret = cpuhp_setup_state(CPUHP_AP_ARC_TIMER_STARTING,
"clockevents/arc/timer:starting",
arc_timer_starting_cpu,
arc_timer_dying_cpu);
if (ret) {
pr_err("Failed to setup hotplug state\n");
return ret;
}
return 0;
}
static int __init arc_of_timer_init(struct device_node *np)
{
static int init_count = 0;
int ret;
if (!init_count) {
init_count = 1;
ret = arc_clockevent_setup(np);
} else {
ret = arc_cs_setup_timer1(np);
}
return ret;
}
