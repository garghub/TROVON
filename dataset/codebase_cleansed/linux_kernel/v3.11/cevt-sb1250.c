static void sibyte_set_mode(enum clock_event_mode mode,
struct clock_event_device *evt)
{
unsigned int cpu = smp_processor_id();
void __iomem *cfg, *init;
cfg = IOADDR(A_SCD_TIMER_REGISTER(cpu, R_SCD_TIMER_CFG));
init = IOADDR(A_SCD_TIMER_REGISTER(cpu, R_SCD_TIMER_INIT));
switch (mode) {
case CLOCK_EVT_MODE_PERIODIC:
__raw_writeq(0, cfg);
__raw_writeq((V_SCD_TIMER_FREQ / HZ) - 1, init);
__raw_writeq(M_SCD_TIMER_ENABLE | M_SCD_TIMER_MODE_CONTINUOUS,
cfg);
break;
case CLOCK_EVT_MODE_ONESHOT:
case CLOCK_EVT_MODE_SHUTDOWN:
__raw_writeq(0, cfg);
break;
case CLOCK_EVT_MODE_UNUSED:
case CLOCK_EVT_MODE_RESUME:
;
}
}
static int sibyte_next_event(unsigned long delta, struct clock_event_device *cd)
{
unsigned int cpu = smp_processor_id();
void __iomem *cfg, *init;
cfg = IOADDR(A_SCD_TIMER_REGISTER(cpu, R_SCD_TIMER_CFG));
init = IOADDR(A_SCD_TIMER_REGISTER(cpu, R_SCD_TIMER_INIT));
__raw_writeq(0, cfg);
__raw_writeq(delta - 1, init);
__raw_writeq(M_SCD_TIMER_ENABLE, cfg);
return 0;
}
static irqreturn_t sibyte_counter_handler(int irq, void *dev_id)
{
unsigned int cpu = smp_processor_id();
struct clock_event_device *cd = dev_id;
void __iomem *cfg;
unsigned long tmode;
if (cd->mode == CLOCK_EVT_MODE_PERIODIC)
tmode = M_SCD_TIMER_ENABLE | M_SCD_TIMER_MODE_CONTINUOUS;
else
tmode = 0;
cfg = IOADDR(A_SCD_TIMER_REGISTER(cpu, R_SCD_TIMER_CFG));
____raw_writeq(tmode, cfg);
cd->event_handler(cd);
return IRQ_HANDLED;
}
void sb1250_clockevent_init(void)
{
unsigned int cpu = smp_processor_id();
unsigned int irq = K_INT_TIMER_0 + cpu;
struct irqaction *action = &per_cpu(sibyte_hpt_irqaction, cpu);
struct clock_event_device *cd = &per_cpu(sibyte_hpt_clockevent, cpu);
unsigned char *name = per_cpu(sibyte_hpt_name, cpu);
BUG_ON(cpu > 2);
sprintf(name, "sb1250-counter-%d", cpu);
cd->name = name;
cd->features = CLOCK_EVT_FEAT_PERIODIC |
CLOCK_EVT_FEAT_ONESHOT;
clockevent_set_clock(cd, V_SCD_TIMER_FREQ);
cd->max_delta_ns = clockevent_delta2ns(0x7fffff, cd);
cd->min_delta_ns = clockevent_delta2ns(2, cd);
cd->rating = 200;
cd->irq = irq;
cd->cpumask = cpumask_of(cpu);
cd->set_next_event = sibyte_next_event;
cd->set_mode = sibyte_set_mode;
clockevents_register_device(cd);
sb1250_mask_irq(cpu, irq);
__raw_writeq(IMR_IP4_VAL,
IOADDR(A_IMR_REGISTER(cpu, R_IMR_INTERRUPT_MAP_BASE) +
(irq << 3)));
sb1250_unmask_irq(cpu, irq);
action->handler = sibyte_counter_handler;
action->flags = IRQF_PERCPU | IRQF_TIMER;
action->name = name;
action->dev_id = cd;
irq_set_affinity(irq, cpumask_of(cpu));
setup_irq(irq, action);
}
