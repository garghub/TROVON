static int ms1bit(unsigned long x)
{
int b = 0, s;
s = 16; if (x >> 16 == 0) s = 0; b += s; x >>= s;
s = 8; if (x >> 8 == 0) s = 0; b += s; x >>= s;
s = 4; if (x >> 4 == 0) s = 0; b += s; x >>= s;
s = 2; if (x >> 2 == 0) s = 0; b += s; x >>= s;
s = 1; if (x >> 1 == 0) s = 0; b += s;
return b;
}
static void ip27_do_irq_mask0(void)
{
int irq, swlevel;
hubreg_t pend0, mask0;
cpuid_t cpu = smp_processor_id();
int pi_int_mask0 =
(cputoslice(cpu) == 0) ? PI_INT_MASK0_A : PI_INT_MASK0_B;
pend0 = LOCAL_HUB_L(PI_INT_PEND0);
mask0 = LOCAL_HUB_L(pi_int_mask0);
pend0 &= mask0;
if (!pend0)
return;
swlevel = ms1bit(pend0);
#ifdef CONFIG_SMP
if (pend0 & (1UL << CPU_RESCHED_A_IRQ)) {
LOCAL_HUB_CLR_INTR(CPU_RESCHED_A_IRQ);
scheduler_ipi();
} else if (pend0 & (1UL << CPU_RESCHED_B_IRQ)) {
LOCAL_HUB_CLR_INTR(CPU_RESCHED_B_IRQ);
scheduler_ipi();
} else if (pend0 & (1UL << CPU_CALL_A_IRQ)) {
LOCAL_HUB_CLR_INTR(CPU_CALL_A_IRQ);
irq_enter();
generic_smp_call_function_interrupt();
irq_exit();
} else if (pend0 & (1UL << CPU_CALL_B_IRQ)) {
LOCAL_HUB_CLR_INTR(CPU_CALL_B_IRQ);
irq_enter();
generic_smp_call_function_interrupt();
irq_exit();
} else
#endif
{
struct slice_data *si = cpu_data[cpu].data;
irq = si->level_to_irq[swlevel];
do_IRQ(irq);
}
LOCAL_HUB_L(PI_INT_PEND0);
}
static void ip27_do_irq_mask1(void)
{
int irq, swlevel;
hubreg_t pend1, mask1;
cpuid_t cpu = smp_processor_id();
int pi_int_mask1 = (cputoslice(cpu) == 0) ? PI_INT_MASK1_A : PI_INT_MASK1_B;
struct slice_data *si = cpu_data[cpu].data;
pend1 = LOCAL_HUB_L(PI_INT_PEND1);
mask1 = LOCAL_HUB_L(pi_int_mask1);
pend1 &= mask1;
if (!pend1)
return;
swlevel = ms1bit(pend1);
irq = si->level_to_irq[swlevel];
LOCAL_HUB_CLR_INTR(swlevel);
do_IRQ(irq);
LOCAL_HUB_L(PI_INT_PEND1);
}
static void ip27_prof_timer(void)
{
panic("CPU %d got a profiling interrupt", smp_processor_id());
}
static void ip27_hub_error(void)
{
panic("CPU %d got a hub error interrupt", smp_processor_id());
}
asmlinkage void plat_irq_dispatch(void)
{
unsigned long pending = read_c0_cause() & read_c0_status();
extern unsigned int rt_timer_irq;
if (pending & CAUSEF_IP4)
do_IRQ(rt_timer_irq);
else if (pending & CAUSEF_IP2)
ip27_do_irq_mask0();
else if (pending & CAUSEF_IP3)
ip27_do_irq_mask1();
else if (pending & CAUSEF_IP5)
ip27_prof_timer();
else if (pending & CAUSEF_IP6)
ip27_hub_error();
}
void __init arch_init_irq(void)
{
}
void install_ipi(void)
{
int slice = LOCAL_HUB_L(PI_CPU_NUM);
int cpu = smp_processor_id();
struct slice_data *si = cpu_data[cpu].data;
struct hub_data *hub = hub_data(cpu_to_node(cpu));
int resched, call;
resched = CPU_RESCHED_A_IRQ + slice;
__set_bit(resched, hub->irq_alloc_mask);
__set_bit(resched, si->irq_enable_mask);
LOCAL_HUB_CLR_INTR(resched);
call = CPU_CALL_A_IRQ + slice;
__set_bit(call, hub->irq_alloc_mask);
__set_bit(call, si->irq_enable_mask);
LOCAL_HUB_CLR_INTR(call);
if (slice == 0) {
LOCAL_HUB_S(PI_INT_MASK0_A, si->irq_enable_mask[0]);
LOCAL_HUB_S(PI_INT_MASK1_A, si->irq_enable_mask[1]);
} else {
LOCAL_HUB_S(PI_INT_MASK0_B, si->irq_enable_mask[0]);
LOCAL_HUB_S(PI_INT_MASK1_B, si->irq_enable_mask[1]);
}
}
