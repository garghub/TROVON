static void enable_rt_irq(struct irq_data *d)
{
}
static void disable_rt_irq(struct irq_data *d)
{
}
static int rt_next_event(unsigned long delta, struct clock_event_device *evt)
{
unsigned int cpu = smp_processor_id();
int slice = cputoslice(cpu);
unsigned long cnt;
cnt = LOCAL_HUB_L(PI_RT_COUNT);
cnt += delta;
LOCAL_HUB_S(PI_RT_COMPARE_A + PI_COUNT_OFFSET * slice, cnt);
return LOCAL_HUB_L(PI_RT_COUNT) >= cnt ? -ETIME : 0;
}
static void rt_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
}
static irqreturn_t hub_rt_counter_handler(int irq, void *dev_id)
{
unsigned int cpu = smp_processor_id();
struct clock_event_device *cd = &per_cpu(hub_rt_clockevent, cpu);
int slice = cputoslice(cpu);
LOCAL_HUB_S(PI_RT_PEND_A + PI_COUNT_OFFSET * slice, 0);
cd->event_handler(cd);
return IRQ_HANDLED;
}
void hub_rt_clock_event_init(void)
{
unsigned int cpu = smp_processor_id();
struct clock_event_device *cd = &per_cpu(hub_rt_clockevent, cpu);
unsigned char *name = per_cpu(hub_rt_name, cpu);
int irq = rt_timer_irq;
sprintf(name, "hub-rt %d", cpu);
cd->name = name;
cd->features = CLOCK_EVT_FEAT_ONESHOT;
clockevent_set_clock(cd, CYCLES_PER_SEC);
cd->max_delta_ns = clockevent_delta2ns(0xfffffffffffff, cd);
cd->min_delta_ns = clockevent_delta2ns(0x300, cd);
cd->rating = 200;
cd->irq = irq;
cd->cpumask = cpumask_of(cpu);
cd->set_next_event = rt_next_event;
cd->set_mode = rt_set_mode;
clockevents_register_device(cd);
}
static void __init hub_rt_clock_event_global_init(void)
{
int irq;
do {
smp_wmb();
irq = rt_timer_irq;
if (irq)
break;
irq = allocate_irqno();
if (irq < 0)
panic("Allocation of irq number for timer failed");
} while (xchg(&rt_timer_irq, irq));
irq_set_chip_and_handler(irq, &rt_irq_type, handle_percpu_irq);
setup_irq(irq, &hub_rt_irqaction);
}
static cycle_t hub_rt_read(struct clocksource *cs)
{
return REMOTE_HUB_L(cputonasid(0), PI_RT_COUNT);
}
static void __init hub_rt_clocksource_init(void)
{
struct clocksource *cs = &hub_rt_clocksource;
clocksource_register_hz(cs, CYCLES_PER_SEC);
}
void __init plat_time_init(void)
{
hub_rt_clocksource_init();
hub_rt_clock_event_global_init();
hub_rt_clock_event_init();
}
void cpu_time_init(void)
{
lboard_t *board;
klcpu_t *cpu;
int cpuid;
board = find_lboard(KL_CONFIG_INFO(get_nasid()), KLTYPE_IP27);
if (!board)
panic("Can't find board info for myself.");
cpuid = LOCAL_HUB_L(PI_CPU_NUM) ? IP27_CPU0_INDEX : IP27_CPU1_INDEX;
cpu = (klcpu_t *) KLCF_COMP(board, cpuid);
if (!cpu)
panic("No information about myself?");
printk("CPU %d clock is %dMHz.\n", smp_processor_id(), cpu->cpu_speed);
set_c0_status(SRB_TIMOCLK);
}
void hub_rtc_init(cnodeid_t cnode)
{
if (get_compact_nodeid() == cnode) {
LOCAL_HUB_S(PI_RT_EN_A, 1);
LOCAL_HUB_S(PI_RT_EN_B, 1);
LOCAL_HUB_S(PI_PROF_EN_A, 0);
LOCAL_HUB_S(PI_PROF_EN_B, 0);
LOCAL_HUB_S(PI_RT_COUNT, 0);
LOCAL_HUB_S(PI_RT_PEND_A, 0);
LOCAL_HUB_S(PI_RT_PEND_B, 0);
}
}
static int __init sgi_ip27_rtc_devinit(void)
{
struct resource res;
memset(&res, 0, sizeof(res));
res.start = XPHYSADDR(KL_CONFIG_CH_CONS_INFO(master_nasid)->memory_base +
IOC3_BYTEBUS_DEV0);
res.end = res.start + 32767;
res.flags = IORESOURCE_MEM;
return IS_ERR(platform_device_register_simple("rtc-m48t35", -1,
&res, 1));
}
