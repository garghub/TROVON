static inline unsigned int leon_eirq_get(int cpu)
{
return LEON3_BYPASS_LOAD_PA(&leon3_irqctrl_regs->intid[cpu]) & 0x1f;
}
static void leon_handle_ext_irq(struct irq_desc *desc)
{
unsigned int eirq;
struct irq_bucket *p;
int cpu = sparc_leon3_cpuid();
eirq = leon_eirq_get(cpu);
p = irq_map[eirq];
if ((eirq & 0x10) && p && p->irq)
generic_handle_irq(p->irq);
}
static void leon_eirq_setup(unsigned int eirq)
{
unsigned long mask, oldmask;
unsigned int veirq;
if (eirq < 1 || eirq > 0xf) {
printk(KERN_ERR "LEON EXT IRQ NUMBER BAD: %d\n", eirq);
return;
}
veirq = leon_build_device_irq(eirq, leon_handle_ext_irq, "extirq", 0);
irq_link(veirq);
mask = 1 << eirq;
oldmask = LEON3_BYPASS_LOAD_PA(LEON_IMASK(boot_cpu_id));
LEON3_BYPASS_STORE_PA(LEON_IMASK(boot_cpu_id), (oldmask | mask));
sparc_leon_eirq = eirq;
}
unsigned long leon_get_irqmask(unsigned int irq)
{
unsigned long mask;
if (!irq || ((irq > 0xf) && !sparc_leon_eirq)
|| ((irq > 0x1f) && sparc_leon_eirq)) {
printk(KERN_ERR
"leon_get_irqmask: false irq number: %d\n", irq);
mask = 0;
} else {
mask = LEON_HARD_INT(irq);
}
return mask;
}
static int irq_choose_cpu(const struct cpumask *affinity)
{
cpumask_t mask;
cpumask_and(&mask, cpu_online_mask, affinity);
if (cpumask_equal(&mask, cpu_online_mask) || cpumask_empty(&mask))
return boot_cpu_id;
else
return cpumask_first(&mask);
}
static int leon_set_affinity(struct irq_data *data, const struct cpumask *dest,
bool force)
{
unsigned long mask, oldmask, flags;
int oldcpu, newcpu;
mask = (unsigned long)data->chip_data;
oldcpu = irq_choose_cpu(irq_data_get_affinity_mask(data));
newcpu = irq_choose_cpu(dest);
if (oldcpu == newcpu)
goto out;
spin_lock_irqsave(&leon_irq_lock, flags);
oldmask = LEON3_BYPASS_LOAD_PA(LEON_IMASK(oldcpu));
LEON3_BYPASS_STORE_PA(LEON_IMASK(oldcpu), (oldmask & ~mask));
oldmask = LEON3_BYPASS_LOAD_PA(LEON_IMASK(newcpu));
LEON3_BYPASS_STORE_PA(LEON_IMASK(newcpu), (oldmask | mask));
spin_unlock_irqrestore(&leon_irq_lock, flags);
out:
return IRQ_SET_MASK_OK;
}
static void leon_unmask_irq(struct irq_data *data)
{
unsigned long mask, oldmask, flags;
int cpu;
mask = (unsigned long)data->chip_data;
cpu = irq_choose_cpu(irq_data_get_affinity_mask(data));
spin_lock_irqsave(&leon_irq_lock, flags);
oldmask = LEON3_BYPASS_LOAD_PA(LEON_IMASK(cpu));
LEON3_BYPASS_STORE_PA(LEON_IMASK(cpu), (oldmask | mask));
spin_unlock_irqrestore(&leon_irq_lock, flags);
}
static void leon_mask_irq(struct irq_data *data)
{
unsigned long mask, oldmask, flags;
int cpu;
mask = (unsigned long)data->chip_data;
cpu = irq_choose_cpu(irq_data_get_affinity_mask(data));
spin_lock_irqsave(&leon_irq_lock, flags);
oldmask = LEON3_BYPASS_LOAD_PA(LEON_IMASK(cpu));
LEON3_BYPASS_STORE_PA(LEON_IMASK(cpu), (oldmask & ~mask));
spin_unlock_irqrestore(&leon_irq_lock, flags);
}
static unsigned int leon_startup_irq(struct irq_data *data)
{
irq_link(data->irq);
leon_unmask_irq(data);
return 0;
}
static void leon_shutdown_irq(struct irq_data *data)
{
leon_mask_irq(data);
irq_unlink(data->irq);
}
static void leon_eoi_irq(struct irq_data *data)
{
unsigned long mask = (unsigned long)data->chip_data;
if (mask & LEON_DO_ACK_HW)
LEON3_BYPASS_STORE_PA(LEON_IACK, mask & ~LEON_DO_ACK_HW);
}
unsigned int leon_build_device_irq(unsigned int real_irq,
irq_flow_handler_t flow_handler,
const char *name, int do_ack)
{
unsigned int irq;
unsigned long mask;
struct irq_desc *desc;
irq = 0;
mask = leon_get_irqmask(real_irq);
if (mask == 0)
goto out;
irq = irq_alloc(real_irq, real_irq);
if (irq == 0)
goto out;
if (do_ack)
mask |= LEON_DO_ACK_HW;
desc = irq_to_desc(irq);
if (!desc || !desc->handle_irq || desc->handle_irq == handle_bad_irq) {
irq_set_chip_and_handler_name(irq, &leon_irq,
flow_handler, name);
irq_set_chip_data(irq, (void *)mask);
}
out:
return irq;
}
static unsigned int _leon_build_device_irq(struct platform_device *op,
unsigned int real_irq)
{
return leon_build_device_irq(real_irq, handle_simple_irq, "edge", 0);
}
void leon_update_virq_handling(unsigned int virq,
irq_flow_handler_t flow_handler,
const char *name, int do_ack)
{
unsigned long mask = (unsigned long)irq_get_chip_data(virq);
mask &= ~LEON_DO_ACK_HW;
if (do_ack)
mask |= LEON_DO_ACK_HW;
irq_set_chip_and_handler_name(virq, &leon_irq,
flow_handler, name);
irq_set_chip_data(virq, (void *)mask);
}
static u32 leon_cycles_offset(void)
{
u32 rld, val, ctrl, off;
rld = LEON3_BYPASS_LOAD_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].rld);
val = LEON3_BYPASS_LOAD_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].val);
ctrl = LEON3_BYPASS_LOAD_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl);
if (LEON3_GPTIMER_CTRL_ISPENDING(ctrl)) {
val = LEON3_BYPASS_LOAD_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].val);
off = 2 * rld - val;
} else {
off = rld - val;
}
return off;
}
static irqreturn_t leon_percpu_timer_ce_interrupt(int irq, void *unused)
{
struct clock_event_device *ce;
int cpu = smp_processor_id();
leon_clear_profile_irq(cpu);
if (cpu == boot_cpu_id)
timer_interrupt(irq, NULL);
ce = &per_cpu(sparc32_clockevent, cpu);
irq_enter();
if (ce->event_handler)
ce->event_handler(ce);
irq_exit();
return IRQ_HANDLED;
}
void __init leon_init_timers(void)
{
int irq, eirq;
struct device_node *rootnp, *np, *nnp;
struct property *pp;
int len;
int icsel;
int ampopts;
int err;
u32 config;
u32 ctrl;
sparc_config.get_cycles_offset = leon_cycles_offset;
sparc_config.cs_period = 1000000 / HZ;
sparc_config.features |= FEAT_L10_CLOCKSOURCE;
#ifndef CONFIG_SMP
sparc_config.features |= FEAT_L10_CLOCKEVENT;
#endif
leondebug_irq_disable = 0;
leon_debug_irqout = 0;
master_l10_counter = (u32 __iomem *)&dummy_master_l10_counter;
dummy_master_l10_counter = 0;
rootnp = of_find_node_by_path("/ambapp0");
if (!rootnp)
goto bad;
pp = of_find_property(rootnp, "systemid", &len);
if (pp)
amba_system_id = *(unsigned long *)pp->value;
np = of_find_node_by_name(rootnp, "GAISLER_IRQMP");
if (!np) {
np = of_find_node_by_name(rootnp, "01_00d");
if (!np)
goto bad;
}
pp = of_find_property(np, "reg", &len);
if (!pp)
goto bad;
leon3_irqctrl_regs = *(struct leon3_irqctrl_regs_map **)pp->value;
nnp = rootnp;
do {
np = of_find_node_by_name(nnp, "GAISLER_GPTIMER");
if (!np) {
np = of_find_node_by_name(nnp, "01_011");
if (!np)
goto bad;
}
ampopts = 0;
pp = of_find_property(np, "ampopts", &len);
if (pp) {
ampopts = *(int *)pp->value;
if (ampopts == 0) {
nnp = np;
continue;
}
}
leon3_gptimer_idx = ampopts & 0x7;
pp = of_find_property(np, "reg", &len);
if (pp)
leon3_gptimer_regs = *(struct leon3_gptimer_regs_map **)
pp->value;
pp = of_find_property(np, "interrupts", &len);
if (pp)
leon3_gptimer_irq = *(unsigned int *)pp->value;
} while (0);
if (!(leon3_gptimer_regs && leon3_irqctrl_regs && leon3_gptimer_irq))
goto bad;
ctrl = LEON3_BYPASS_LOAD_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl);
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl,
ctrl | LEON3_GPTIMER_CTRL_PENDING);
ctrl = LEON3_BYPASS_LOAD_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl);
if ((ctrl & LEON3_GPTIMER_CTRL_PENDING) != 0)
leon3_gptimer_ackmask = ~LEON3_GPTIMER_CTRL_PENDING;
else
leon3_gptimer_ackmask = ~0;
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].val, 0);
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].rld,
(((1000000 / HZ) - 1)));
LEON3_BYPASS_STORE_PA(
&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl, 0);
icsel = LEON3_BYPASS_LOAD_PA(&leon3_irqctrl_regs->icsel[boot_cpu_id/8]);
icsel = (icsel >> ((7 - (boot_cpu_id&0x7)) * 4)) & 0xf;
leon3_irqctrl_regs += icsel;
LEON3_BYPASS_STORE_PA(&leon3_irqctrl_regs->mask[boot_cpu_id], 0);
eirq = (LEON3_BYPASS_LOAD_PA(&leon3_irqctrl_regs->mpstatus)
>> 16) & 0xf;
if (eirq != 0)
leon_eirq_setup(eirq);
#ifdef CONFIG_SMP
{
unsigned long flags;
local_irq_save(flags);
patchme_maybe_smp_msg[0] = 0x01000000;
local_ops->cache_all();
local_irq_restore(flags);
}
#endif
config = LEON3_BYPASS_LOAD_PA(&leon3_gptimer_regs->config);
if (config & (1 << LEON3_GPTIMER_SEPIRQ))
leon3_gptimer_irq += leon3_gptimer_idx;
else if ((config & LEON3_GPTIMER_TIMERS) > 1)
pr_warn("GPTIMER uses shared irqs, using other timers of the same core will fail.\n");
#ifdef CONFIG_SMP
irq = leon_build_device_irq(leon3_gptimer_irq, handle_percpu_irq,
"per-cpu", 0);
err = request_irq(irq, leon_percpu_timer_ce_interrupt,
IRQF_PERCPU | IRQF_TIMER, "timer", NULL);
#else
irq = _leon_build_device_irq(NULL, leon3_gptimer_irq);
err = request_irq(irq, timer_interrupt, IRQF_TIMER, "timer", NULL);
#endif
if (err) {
pr_err("Unable to attach timer IRQ%d\n", irq);
prom_halt();
}
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl,
LEON3_GPTIMER_EN |
LEON3_GPTIMER_RL |
LEON3_GPTIMER_LD |
LEON3_GPTIMER_IRQEN);
return;
bad:
printk(KERN_ERR "No Timer/irqctrl found\n");
BUG();
return;
}
static void leon_clear_clock_irq(void)
{
u32 ctrl;
ctrl = LEON3_BYPASS_LOAD_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl);
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl,
ctrl & leon3_gptimer_ackmask);
}
static void leon_load_profile_irq(int cpu, unsigned int limit)
{
}
void __init leon_trans_init(struct device_node *dp)
{
if (strcmp(dp->type, "cpu") == 0 && strcmp(dp->name, "<NULL>") == 0) {
struct property *p;
p = of_find_property(dp, "mid", (void *)0);
if (p) {
int mid;
dp->name = prom_early_alloc(5 + 1);
memcpy(&mid, p->value, p->length);
sprintf((char *)dp->name, "cpu%.2d", mid);
}
}
}
void leon_clear_profile_irq(int cpu)
{
}
void leon_enable_irq_cpu(unsigned int irq_nr, unsigned int cpu)
{
unsigned long mask, flags, *addr;
mask = leon_get_irqmask(irq_nr);
spin_lock_irqsave(&leon_irq_lock, flags);
addr = (unsigned long *)LEON_IMASK(cpu);
LEON3_BYPASS_STORE_PA(addr, (LEON3_BYPASS_LOAD_PA(addr) | mask));
spin_unlock_irqrestore(&leon_irq_lock, flags);
}
void __init leon_init_IRQ(void)
{
sparc_config.init_timers = leon_init_timers;
sparc_config.build_device_irq = _leon_build_device_irq;
sparc_config.clock_rate = 1000000;
sparc_config.clear_clock_irq = leon_clear_clock_irq;
sparc_config.load_profile_irq = leon_load_profile_irq;
}
