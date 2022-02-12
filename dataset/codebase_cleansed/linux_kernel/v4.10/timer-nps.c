static int __init nps_get_timer_clk(struct device_node *node,
unsigned long *timer_freq,
struct clk **clk)
{
int ret;
*clk = of_clk_get(node, 0);
ret = PTR_ERR_OR_ZERO(*clk);
if (ret) {
pr_err("timer missing clk");
return ret;
}
ret = clk_prepare_enable(*clk);
if (ret) {
pr_err("Couldn't enable parent clk\n");
clk_put(*clk);
return ret;
}
*timer_freq = clk_get_rate(*clk);
if (!(*timer_freq)) {
pr_err("Couldn't get clk rate\n");
clk_disable_unprepare(*clk);
clk_put(*clk);
return -EINVAL;
}
return 0;
}
static u64 nps_clksrc_read(struct clocksource *clksrc)
{
int cluster = raw_smp_processor_id() >> NPS_CLUSTER_OFFSET;
return (u64)ioread32be(nps_msu_reg_low_addr[cluster]);
}
static int __init nps_setup_clocksource(struct device_node *node)
{
int ret, cluster;
struct clk *clk;
unsigned long nps_timer1_freq;
for (cluster = 0; cluster < NPS_CLUSTER_NUM; cluster++)
nps_msu_reg_low_addr[cluster] =
nps_host_reg((cluster << NPS_CLUSTER_OFFSET),
NPS_MSU_BLKID, NPS_MSU_TICK_LOW);
ret = nps_get_timer_clk(node, &nps_timer1_freq, &clk);
if (ret)
return ret;
ret = clocksource_mmio_init(nps_msu_reg_low_addr, "nps-tick",
nps_timer1_freq, 300, 32, nps_clksrc_read);
if (ret) {
pr_err("Couldn't register clock source.\n");
clk_disable_unprepare(clk);
}
return ret;
}
static void nps_clkevent_rm_thread(void)
{
int thread;
unsigned int cflags, enabled_threads;
hw_schd_save(&cflags);
enabled_threads = read_aux_reg(NPS_REG_TIMER0_TSI);
thread = read_aux_reg(CTOP_AUX_THREAD_ID);
enabled_threads &= ~(1 << thread);
write_aux_reg(NPS_REG_TIMER0_TSI, enabled_threads);
if (!enabled_threads)
write_aux_reg(NPS_REG_TIMER0_CTRL, TIMER0_CTRL_NH);
else
write_aux_reg(NPS_REG_TIMER0_CTRL,
TIMER0_CTRL_IE | TIMER0_CTRL_NH);
hw_schd_restore(cflags);
}
static void nps_clkevent_add_thread(unsigned long delta)
{
int thread;
unsigned int cflags, enabled_threads;
hw_schd_save(&cflags);
thread = read_aux_reg(CTOP_AUX_THREAD_ID);
enabled_threads = read_aux_reg(NPS_REG_TIMER0_TSI);
enabled_threads |= (1 << thread);
write_aux_reg(NPS_REG_TIMER0_TSI, enabled_threads);
write_aux_reg(NPS_REG_TIMER0_LIMIT, delta);
write_aux_reg(NPS_REG_TIMER0_CNT, 0);
write_aux_reg(NPS_REG_TIMER0_CTRL,
TIMER0_CTRL_IE | TIMER0_CTRL_NH);
hw_schd_restore(cflags);
}
static int nps_clkevent_set_state(struct clock_event_device *dev)
{
nps_clkevent_rm_thread();
disable_percpu_irq(nps_timer0_irq);
return 0;
}
static int nps_clkevent_set_next_event(unsigned long delta,
struct clock_event_device *dev)
{
nps_clkevent_add_thread(delta);
enable_percpu_irq(nps_timer0_irq, IRQ_TYPE_NONE);
return 0;
}
static irqreturn_t timer_irq_handler(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
nps_clkevent_rm_thread();
evt->event_handler(evt);
return IRQ_HANDLED;
}
static int nps_timer_starting_cpu(unsigned int cpu)
{
struct clock_event_device *evt = this_cpu_ptr(&nps_clockevent_device);
evt->cpumask = cpumask_of(smp_processor_id());
clockevents_config_and_register(evt, nps_timer0_freq, 0, ULONG_MAX);
enable_percpu_irq(nps_timer0_irq, IRQ_TYPE_NONE);
return 0;
}
static int nps_timer_dying_cpu(unsigned int cpu)
{
disable_percpu_irq(nps_timer0_irq);
return 0;
}
static int __init nps_setup_clockevent(struct device_node *node)
{
struct clk *clk;
int ret;
nps_timer0_irq = irq_of_parse_and_map(node, 0);
if (nps_timer0_irq <= 0) {
pr_err("clockevent: missing irq");
return -EINVAL;
}
ret = nps_get_timer_clk(node, &nps_timer0_freq, &clk);
if (ret)
return ret;
ret = request_percpu_irq(nps_timer0_irq, timer_irq_handler,
"Timer0 (per-cpu-tick)",
&nps_clockevent_device);
if (ret) {
pr_err("Couldn't request irq\n");
clk_disable_unprepare(clk);
return ret;
}
ret = cpuhp_setup_state(CPUHP_AP_ARC_TIMER_STARTING,
"clockevents/nps:starting",
nps_timer_starting_cpu,
nps_timer_dying_cpu);
if (ret) {
pr_err("Failed to setup hotplug state");
clk_disable_unprepare(clk);
free_percpu_irq(nps_timer0_irq, &nps_clockevent_device);
return ret;
}
return 0;
}
