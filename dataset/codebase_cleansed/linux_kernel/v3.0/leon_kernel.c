static inline unsigned int leon_eirq_get(int cpu)
{
return LEON3_BYPASS_LOAD_PA(&leon3_irqctrl_regs->intid[cpu]) & 0x1f;
}
static void leon_handle_ext_irq(unsigned int irq, struct irq_desc *desc)
{
unsigned int eirq;
int cpu = sparc_leon3_cpuid();
eirq = leon_eirq_get(cpu);
if ((eirq & 0x10) && irq_map[eirq]->irq)
generic_handle_irq(irq_map[eirq]->irq);
}
void leon_eirq_setup(unsigned int eirq)
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
static inline unsigned long get_irqmask(unsigned int irq)
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
cpus_and(mask, cpu_online_map, *affinity);
if (cpus_equal(mask, cpu_online_map) || cpus_empty(mask))
return boot_cpu_id;
else
return first_cpu(mask);
}
static int leon_set_affinity(struct irq_data *data, const struct cpumask *dest,
bool force)
{
unsigned long mask, oldmask, flags;
int oldcpu, newcpu;
mask = (unsigned long)data->chip_data;
oldcpu = irq_choose_cpu(data->affinity);
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
cpu = irq_choose_cpu(data->affinity);
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
cpu = irq_choose_cpu(data->affinity);
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
irq = 0;
mask = get_irqmask(real_irq);
if (mask == 0)
goto out;
irq = irq_alloc(real_irq, real_irq);
if (irq == 0)
goto out;
if (do_ack)
mask |= LEON_DO_ACK_HW;
irq_set_chip_and_handler_name(irq, &leon_irq,
flow_handler, name);
irq_set_chip_data(irq, (void *)mask);
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
void __init leon_init_timers(irq_handler_t counter_fn)
{
int irq, eirq;
struct device_node *rootnp, *np, *nnp;
struct property *pp;
int len;
int icsel;
int ampopts;
int err;
leondebug_irq_disable = 0;
leon_debug_irqout = 0;
master_l10_counter = (unsigned int *)&dummy_master_l10_counter;
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
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].val, 0);
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].rld,
(((1000000 / HZ) - 1)));
LEON3_BYPASS_STORE_PA(
&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl, 0);
#ifdef CONFIG_SMP
leon3_ticker_irq = leon3_gptimer_irq + 1 + leon3_gptimer_idx;
if (!(LEON3_BYPASS_LOAD_PA(&leon3_gptimer_regs->config) &
(1<<LEON3_GPTIMER_SEPIRQ))) {
printk(KERN_ERR "timer not configured with separate irqs\n");
BUG();
}
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx+1].val,
0);
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx+1].rld,
(((1000000/HZ) - 1)));
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx+1].ctrl,
0);
#endif
icsel = LEON3_BYPASS_LOAD_PA(&leon3_irqctrl_regs->icsel[boot_cpu_id/8]);
icsel = (icsel >> ((7 - (boot_cpu_id&0x7)) * 4)) & 0xf;
leon3_irqctrl_regs += icsel;
LEON3_BYPASS_STORE_PA(&leon3_irqctrl_regs->mask[boot_cpu_id], 0);
eirq = (LEON3_BYPASS_LOAD_PA(&leon3_irqctrl_regs->mpstatus)
>> 16) & 0xf;
if (eirq != 0)
leon_eirq_setup(eirq);
irq = _leon_build_device_irq(NULL, leon3_gptimer_irq+leon3_gptimer_idx);
err = request_irq(irq, counter_fn, IRQF_TIMER, "timer", NULL);
if (err) {
printk(KERN_ERR "unable to attach timer IRQ%d\n", irq);
prom_halt();
}
#ifdef CONFIG_SMP
{
unsigned long flags;
local_irq_save(flags);
patchme_maybe_smp_msg[0] = 0x01000000;
local_flush_cache_all();
local_irq_restore(flags);
}
#endif
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx].ctrl,
LEON3_GPTIMER_EN |
LEON3_GPTIMER_RL |
LEON3_GPTIMER_LD |
LEON3_GPTIMER_IRQEN);
#ifdef CONFIG_SMP
irq = leon_build_device_irq(leon3_ticker_irq, handle_percpu_irq,
"per-cpu", 0);
err = request_irq(irq, leon_percpu_timer_interrupt,
IRQF_PERCPU | IRQF_TIMER, "ticker",
NULL);
if (err) {
printk(KERN_ERR "unable to attach ticker IRQ%d\n", irq);
prom_halt();
}
LEON3_BYPASS_STORE_PA(&leon3_gptimer_regs->e[leon3_gptimer_idx+1].ctrl,
LEON3_GPTIMER_EN |
LEON3_GPTIMER_RL |
LEON3_GPTIMER_LD |
LEON3_GPTIMER_IRQEN);
#endif
return;
bad:
printk(KERN_ERR "No Timer/irqctrl found\n");
BUG();
return;
}
void leon_clear_clock_irq(void)
{
}
void leon_load_profile_irq(int cpu, unsigned int limit)
{
BUG();
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
void __init leon_node_init(struct device_node *dp, struct device_node ***nextp)
{
if (prom_amba_init &&
strcmp(dp->type, "ambapp") == 0 &&
strcmp(dp->name, "ambapp0") == 0) {
prom_amba_init(dp, nextp);
}
}
void leon_set_cpu_int(int cpu, int level)
{
unsigned long mask;
mask = get_irqmask(level);
LEON3_BYPASS_STORE_PA(&leon3_irqctrl_regs->force[cpu], mask);
}
static void leon_clear_ipi(int cpu, int level)
{
unsigned long mask;
mask = get_irqmask(level);
LEON3_BYPASS_STORE_PA(&leon3_irqctrl_regs->force[cpu], mask<<16);
}
static void leon_set_udt(int cpu)
{
}
void leon_clear_profile_irq(int cpu)
{
}
void leon_enable_irq_cpu(unsigned int irq_nr, unsigned int cpu)
{
unsigned long mask, flags, *addr;
mask = get_irqmask(irq_nr);
spin_lock_irqsave(&leon_irq_lock, flags);
addr = (unsigned long *)LEON_IMASK(cpu);
LEON3_BYPASS_STORE_PA(addr, (LEON3_BYPASS_LOAD_PA(addr) | mask));
spin_unlock_irqrestore(&leon_irq_lock, flags);
}
void __init leon_init_IRQ(void)
{
sparc_irq_config.init_timers = leon_init_timers;
sparc_irq_config.build_device_irq = _leon_build_device_irq;
BTFIXUPSET_CALL(clear_clock_irq, leon_clear_clock_irq,
BTFIXUPCALL_NORM);
BTFIXUPSET_CALL(load_profile_irq, leon_load_profile_irq,
BTFIXUPCALL_NOP);
#ifdef CONFIG_SMP
BTFIXUPSET_CALL(set_cpu_int, leon_set_cpu_int, BTFIXUPCALL_NORM);
BTFIXUPSET_CALL(clear_cpu_int, leon_clear_ipi, BTFIXUPCALL_NORM);
BTFIXUPSET_CALL(set_irq_udt, leon_set_udt, BTFIXUPCALL_NORM);
#endif
}
void __init leon_init(void)
{
of_pdt_build_more = &leon_node_init;
}
