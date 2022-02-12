unsigned long profile_pc(struct pt_regs *regs)
{
unsigned long pc = instruction_pointer(regs);
if (in_lock_functions(pc))
return regs->u_regs[UREG_RETPC];
return pc;
}
static void tick_disable_protection(void)
{
__asm__ __volatile__(
" ba,pt %%xcc, 1f\n"
" nop\n"
" .align 64\n"
"1: rd %%tick, %%g2\n"
" add %%g2, 6, %%g2\n"
" andn %%g2, %0, %%g2\n"
" wrpr %%g2, 0, %%tick\n"
" rdpr %%tick, %%g0"
:
: "r" (TICK_PRIV_BIT)
: "g2");
}
static void tick_disable_irq(void)
{
__asm__ __volatile__(
" ba,pt %%xcc, 1f\n"
" nop\n"
" .align 64\n"
"1: wr %0, 0x0, %%tick_cmpr\n"
" rd %%tick_cmpr, %%g0"
:
: "r" (TICKCMP_IRQ_BIT));
}
static void tick_init_tick(void)
{
tick_disable_protection();
tick_disable_irq();
}
static unsigned long long tick_get_tick(void)
{
unsigned long ret;
__asm__ __volatile__("rd %%tick, %0\n\t"
"mov %0, %0"
: "=r" (ret));
return ret & ~TICK_PRIV_BIT;
}
static int tick_add_compare(unsigned long adj)
{
unsigned long orig_tick, new_tick, new_compare;
__asm__ __volatile__("rd %%tick, %0"
: "=r" (orig_tick));
orig_tick &= ~TICKCMP_IRQ_BIT;
__asm__ __volatile__("ba,pt %%xcc, 1f\n\t"
" add %1, %2, %0\n\t"
".align 64\n"
"1:\n\t"
"wr %0, 0, %%tick_cmpr\n\t"
"rd %%tick_cmpr, %%g0\n\t"
: "=r" (new_compare)
: "r" (orig_tick), "r" (adj));
__asm__ __volatile__("rd %%tick, %0"
: "=r" (new_tick));
new_tick &= ~TICKCMP_IRQ_BIT;
return ((long)(new_tick - (orig_tick+adj))) > 0L;
}
static unsigned long tick_add_tick(unsigned long adj)
{
unsigned long new_tick;
__asm__ __volatile__("rd %%tick, %0\n\t"
"add %0, %1, %0\n\t"
"wrpr %0, 0, %%tick\n\t"
: "=&r" (new_tick)
: "r" (adj));
return new_tick;
}
static void stick_disable_irq(void)
{
__asm__ __volatile__(
"wr %0, 0x0, %%asr25"
:
: "r" (TICKCMP_IRQ_BIT));
}
static void stick_init_tick(void)
{
if (tlb_type != hypervisor) {
tick_disable_protection();
tick_disable_irq();
__asm__ __volatile__(
" rd %%asr24, %%g2\n"
" andn %%g2, %0, %%g2\n"
" wr %%g2, 0, %%asr24"
:
: "r" (TICK_PRIV_BIT)
: "g1", "g2");
}
stick_disable_irq();
}
static unsigned long long stick_get_tick(void)
{
unsigned long ret;
__asm__ __volatile__("rd %%asr24, %0"
: "=r" (ret));
return ret & ~TICK_PRIV_BIT;
}
static unsigned long stick_add_tick(unsigned long adj)
{
unsigned long new_tick;
__asm__ __volatile__("rd %%asr24, %0\n\t"
"add %0, %1, %0\n\t"
"wr %0, 0, %%asr24\n\t"
: "=&r" (new_tick)
: "r" (adj));
return new_tick;
}
static int stick_add_compare(unsigned long adj)
{
unsigned long orig_tick, new_tick;
__asm__ __volatile__("rd %%asr24, %0"
: "=r" (orig_tick));
orig_tick &= ~TICKCMP_IRQ_BIT;
__asm__ __volatile__("wr %0, 0, %%asr25"
:
: "r" (orig_tick + adj));
__asm__ __volatile__("rd %%asr24, %0"
: "=r" (new_tick));
new_tick &= ~TICKCMP_IRQ_BIT;
return ((long)(new_tick - (orig_tick+adj))) > 0L;
}
static unsigned long __hbird_read_stick(void)
{
unsigned long ret, tmp1, tmp2, tmp3;
unsigned long addr = HBIRD_STICK_ADDR+8;
__asm__ __volatile__("ldxa [%1] %5, %2\n"
"1:\n\t"
"sub %1, 0x8, %1\n\t"
"ldxa [%1] %5, %3\n\t"
"add %1, 0x8, %1\n\t"
"ldxa [%1] %5, %4\n\t"
"cmp %4, %2\n\t"
"bne,a,pn %%xcc, 1b\n\t"
" mov %4, %2\n\t"
"sllx %4, 32, %4\n\t"
"or %3, %4, %0\n\t"
: "=&r" (ret), "=&r" (addr),
"=&r" (tmp1), "=&r" (tmp2), "=&r" (tmp3)
: "i" (ASI_PHYS_BYPASS_EC_E), "1" (addr));
return ret;
}
static void __hbird_write_stick(unsigned long val)
{
unsigned long low = (val & 0xffffffffUL);
unsigned long high = (val >> 32UL);
unsigned long addr = HBIRD_STICK_ADDR;
__asm__ __volatile__("stxa %%g0, [%0] %4\n\t"
"add %0, 0x8, %0\n\t"
"stxa %3, [%0] %4\n\t"
"sub %0, 0x8, %0\n\t"
"stxa %2, [%0] %4"
: "=&r" (addr)
: "0" (addr), "r" (low), "r" (high),
"i" (ASI_PHYS_BYPASS_EC_E));
}
static void __hbird_write_compare(unsigned long val)
{
unsigned long low = (val & 0xffffffffUL);
unsigned long high = (val >> 32UL);
unsigned long addr = HBIRD_STICKCMP_ADDR + 0x8UL;
__asm__ __volatile__("stxa %3, [%0] %4\n\t"
"sub %0, 0x8, %0\n\t"
"stxa %2, [%0] %4"
: "=&r" (addr)
: "0" (addr), "r" (low), "r" (high),
"i" (ASI_PHYS_BYPASS_EC_E));
}
static void hbtick_disable_irq(void)
{
__hbird_write_compare(TICKCMP_IRQ_BIT);
}
static void hbtick_init_tick(void)
{
tick_disable_protection();
__hbird_write_stick(__hbird_read_stick());
hbtick_disable_irq();
}
static unsigned long long hbtick_get_tick(void)
{
return __hbird_read_stick() & ~TICK_PRIV_BIT;
}
static unsigned long hbtick_add_tick(unsigned long adj)
{
unsigned long val;
val = __hbird_read_stick() + adj;
__hbird_write_stick(val);
return val;
}
static int hbtick_add_compare(unsigned long adj)
{
unsigned long val = __hbird_read_stick();
unsigned long val2;
val &= ~TICKCMP_IRQ_BIT;
val += adj;
__hbird_write_compare(val);
val2 = __hbird_read_stick() & ~TICKCMP_IRQ_BIT;
return ((long)(val2 - val)) > 0L;
}
static int rtc_probe(struct platform_device *op)
{
struct resource *r;
printk(KERN_INFO "%s: RTC regs at 0x%llx\n",
op->dev.of_node->full_name, op->resource[0].start);
r = &rtc_cmos_resource;
r->flags = IORESOURCE_IO;
r->name = op->resource[0].name;
r->start = op->resource[0].start;
r->end = op->resource[0].end;
cmos_regs = op->resource[0].start;
return platform_device_register(&rtc_cmos_device);
}
static int bq4802_probe(struct platform_device *op)
{
printk(KERN_INFO "%s: BQ4802 regs at 0x%llx\n",
op->dev.of_node->full_name, op->resource[0].start);
rtc_bq4802_device.resource = &op->resource[0];
return platform_device_register(&rtc_bq4802_device);
}
static unsigned char mostek_read_byte(struct device *dev, u32 ofs)
{
struct platform_device *pdev = to_platform_device(dev);
void __iomem *regs = (void __iomem *) pdev->resource[0].start;
return readb(regs + ofs);
}
static void mostek_write_byte(struct device *dev, u32 ofs, u8 val)
{
struct platform_device *pdev = to_platform_device(dev);
void __iomem *regs = (void __iomem *) pdev->resource[0].start;
writeb(val, regs + ofs);
}
static int mostek_probe(struct platform_device *op)
{
struct device_node *dp = op->dev.of_node;
if (!strcmp(dp->parent->name, "fhc") &&
strcmp(dp->parent->parent->name, "central") != 0)
return -ENODEV;
printk(KERN_INFO "%s: Mostek regs at 0x%llx\n",
dp->full_name, op->resource[0].start);
m48t59_rtc.resource = &op->resource[0];
return platform_device_register(&m48t59_rtc);
}
static int __init clock_init(void)
{
if (this_is_starfire)
return platform_device_register(&rtc_starfire_device);
if (tlb_type == hypervisor)
return platform_device_register(&rtc_sun4v_device);
(void) platform_driver_register(&rtc_driver);
(void) platform_driver_register(&mostek_driver);
(void) platform_driver_register(&bq4802_driver);
return 0;
}
static unsigned long sparc64_init_timers(void)
{
struct device_node *dp;
unsigned long freq;
dp = of_find_node_by_path("/");
if (tlb_type == spitfire) {
unsigned long ver, manuf, impl;
__asm__ __volatile__ ("rdpr %%ver, %0"
: "=&r" (ver));
manuf = ((ver >> 48) & 0xffff);
impl = ((ver >> 32) & 0xffff);
if (manuf == 0x17 && impl == 0x13) {
tick_ops = &hbtick_operations;
freq = of_getintprop_default(dp, "stick-frequency", 0);
} else {
tick_ops = &tick_operations;
freq = local_cpu_data().clock_tick;
}
} else {
tick_ops = &stick_operations;
freq = of_getintprop_default(dp, "stick-frequency", 0);
}
return freq;
}
unsigned long sparc64_get_clock_tick(unsigned int cpu)
{
struct freq_table *ft = &per_cpu(sparc64_freq_table, cpu);
if (ft->clock_tick_ref)
return ft->clock_tick_ref;
return cpu_data(cpu).clock_tick;
}
static int sparc64_cpufreq_notifier(struct notifier_block *nb, unsigned long val,
void *data)
{
struct cpufreq_freqs *freq = data;
unsigned int cpu = freq->cpu;
struct freq_table *ft = &per_cpu(sparc64_freq_table, cpu);
if (!ft->ref_freq) {
ft->ref_freq = freq->old;
ft->clock_tick_ref = cpu_data(cpu).clock_tick;
}
if ((val == CPUFREQ_PRECHANGE && freq->old < freq->new) ||
(val == CPUFREQ_POSTCHANGE && freq->old > freq->new)) {
cpu_data(cpu).clock_tick =
cpufreq_scale(ft->clock_tick_ref,
ft->ref_freq,
freq->new);
}
return 0;
}
static int __init register_sparc64_cpufreq_notifier(void)
{
cpufreq_register_notifier(&sparc64_cpufreq_notifier_block,
CPUFREQ_TRANSITION_NOTIFIER);
return 0;
}
static int sparc64_next_event(unsigned long delta,
struct clock_event_device *evt)
{
return tick_ops->add_compare(delta) ? -ETIME : 0;
}
static int sparc64_timer_shutdown(struct clock_event_device *evt)
{
tick_ops->disable_irq();
return 0;
}
void __irq_entry timer_interrupt(int irq, struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
unsigned long tick_mask = tick_ops->softint_mask;
int cpu = smp_processor_id();
struct clock_event_device *evt = &per_cpu(sparc64_events, cpu);
clear_softint(tick_mask);
irq_enter();
local_cpu_data().irq0_irqs++;
kstat_incr_irq_this_cpu(0);
if (unlikely(!evt->event_handler)) {
printk(KERN_WARNING
"Spurious SPARC64 timer interrupt on cpu %d\n", cpu);
} else
evt->event_handler(evt);
irq_exit();
set_irq_regs(old_regs);
}
void setup_sparc64_timer(void)
{
struct clock_event_device *sevt;
unsigned long pstate;
__asm__ __volatile__("rdpr %%pstate, %0\n\t"
"wrpr %0, %1, %%pstate"
: "=r" (pstate)
: "i" (PSTATE_IE));
tick_ops->init_tick();
__asm__ __volatile__("wrpr %0, 0x0, %%pstate"
:
: "r" (pstate));
sevt = this_cpu_ptr(&sparc64_events);
memcpy(sevt, &sparc64_clockevent, sizeof(*sevt));
sevt->cpumask = cpumask_of(smp_processor_id());
clockevents_register_device(sevt);
}
void __delay(unsigned long loops)
{
unsigned long bclock, now;
bclock = tick_ops->get_tick();
do {
now = tick_ops->get_tick();
} while ((now-bclock) < loops);
}
void udelay(unsigned long usecs)
{
__delay(tb_ticks_per_usec * usecs);
}
static cycle_t clocksource_tick_read(struct clocksource *cs)
{
return tick_ops->get_tick();
}
void __init time_init(void)
{
unsigned long freq = sparc64_init_timers();
tb_ticks_per_usec = freq / USEC_PER_SEC;
timer_ticks_per_nsec_quotient =
clocksource_hz2mult(freq, SPARC64_NSEC_PER_CYC_SHIFT);
clocksource_tick.name = tick_ops->name;
clocksource_tick.read = clocksource_tick_read;
clocksource_register_hz(&clocksource_tick, freq);
printk("clocksource: mult[%x] shift[%d]\n",
clocksource_tick.mult, clocksource_tick.shift);
sparc64_clockevent.name = tick_ops->name;
clockevents_calc_mult_shift(&sparc64_clockevent, freq, 4);
sparc64_clockevent.max_delta_ns =
clockevent_delta2ns(0x7fffffffffffffffUL, &sparc64_clockevent);
sparc64_clockevent.min_delta_ns =
clockevent_delta2ns(0xF, &sparc64_clockevent);
printk("clockevent: mult[%x] shift[%d]\n",
sparc64_clockevent.mult, sparc64_clockevent.shift);
setup_sparc64_timer();
}
unsigned long long sched_clock(void)
{
unsigned long ticks = tick_ops->get_tick();
return (ticks * timer_ticks_per_nsec_quotient)
>> SPARC64_NSEC_PER_CYC_SHIFT;
}
int read_current_timer(unsigned long *timer_val)
{
*timer_val = tick_ops->get_tick();
return 0;
}
