static void sun4m_mask_irq(struct irq_data *data)
{
struct sun4m_handler_data *handler_data = data->handler_data;
int cpu = smp_processor_id();
if (handler_data->mask) {
unsigned long flags;
local_irq_save(flags);
if (handler_data->percpu) {
sbus_writel(handler_data->mask, &sun4m_irq_percpu[cpu]->set);
} else {
sbus_writel(handler_data->mask, &sun4m_irq_global->mask_set);
}
local_irq_restore(flags);
}
}
static void sun4m_unmask_irq(struct irq_data *data)
{
struct sun4m_handler_data *handler_data = data->handler_data;
int cpu = smp_processor_id();
if (handler_data->mask) {
unsigned long flags;
local_irq_save(flags);
if (handler_data->percpu) {
sbus_writel(handler_data->mask, &sun4m_irq_percpu[cpu]->clear);
} else {
sbus_writel(handler_data->mask, &sun4m_irq_global->mask_clear);
}
local_irq_restore(flags);
}
}
static unsigned int sun4m_startup_irq(struct irq_data *data)
{
irq_link(data->irq);
sun4m_unmask_irq(data);
return 0;
}
static void sun4m_shutdown_irq(struct irq_data *data)
{
sun4m_mask_irq(data);
irq_unlink(data->irq);
}
static unsigned int sun4m_build_device_irq(struct platform_device *op,
unsigned int real_irq)
{
struct sun4m_handler_data *handler_data;
unsigned int irq;
unsigned int pil;
if (real_irq >= OBP_INT_LEVEL_VME) {
prom_printf("Bogus sun4m IRQ %u\n", real_irq);
prom_halt();
}
pil = (real_irq & 0xf);
irq = irq_alloc(real_irq, pil);
if (irq == 0)
goto out;
handler_data = irq_get_handler_data(irq);
if (unlikely(handler_data))
goto out;
handler_data = kzalloc(sizeof(struct sun4m_handler_data), GFP_ATOMIC);
if (unlikely(!handler_data)) {
prom_printf("IRQ: kzalloc(sun4m_handler_data) failed.\n");
prom_halt();
}
handler_data->mask = sun4m_imask[real_irq];
handler_data->percpu = real_irq < OBP_INT_LEVEL_ONBOARD;
irq_set_chip_and_handler_name(irq, &sun4m_irq,
handle_level_irq, "level");
irq_set_handler_data(irq, handler_data);
out:
return irq;
}
static void sun4m_send_ipi(int cpu, int level)
{
sbus_writel(SUN4M_SOFT_INT(level), &sun4m_irq_percpu[cpu]->set);
}
static void sun4m_clear_ipi(int cpu, int level)
{
sbus_writel(SUN4M_SOFT_INT(level), &sun4m_irq_percpu[cpu]->clear);
}
static void sun4m_set_udt(int cpu)
{
sbus_writel(cpu, &sun4m_irq_global->interrupt_target);
}
static void sun4m_clear_clock_irq(void)
{
sbus_readl(&timers_global->l10_limit);
}
void sun4m_nmi(struct pt_regs *regs)
{
unsigned long afsr, afar, si;
printk(KERN_ERR "Aieee: sun4m NMI received!\n");
__asm__ __volatile__("mov 0x500, %%g1\n\t"
"lda [%%g1] 0x4, %0\n\t"
"mov 0x600, %%g1\n\t"
"lda [%%g1] 0x4, %1\n\t" :
"=r" (afsr), "=r" (afar));
printk(KERN_ERR "afsr=%08lx afar=%08lx\n", afsr, afar);
si = sbus_readl(&sun4m_irq_global->pending);
printk(KERN_ERR "si=%08lx\n", si);
if (si & SUN4M_INT_MODULE_ERR)
printk(KERN_ERR "Module async error\n");
if (si & SUN4M_INT_M2S_WRITE_ERR)
printk(KERN_ERR "MBus/SBus async error\n");
if (si & SUN4M_INT_ECC_ERR)
printk(KERN_ERR "ECC memory error\n");
if (si & SUN4M_INT_VME_ERR)
printk(KERN_ERR "VME async error\n");
printk(KERN_ERR "you lose buddy boy...\n");
show_regs(regs);
prom_halt();
}
void sun4m_unmask_profile_irq(void)
{
unsigned long flags;
local_irq_save(flags);
sbus_writel(sun4m_imask[SUN4M_PROFILE_IRQ], &sun4m_irq_global->mask_clear);
local_irq_restore(flags);
}
void sun4m_clear_profile_irq(int cpu)
{
sbus_readl(&timers_percpu[cpu]->l14_limit);
}
static void sun4m_load_profile_irq(int cpu, unsigned int limit)
{
sbus_writel(limit, &timers_percpu[cpu]->l14_limit);
}
static void __init sun4m_init_timers(irq_handler_t counter_fn)
{
struct device_node *dp = of_find_node_by_name(NULL, "counter");
int i, err, len, num_cpu_timers;
unsigned int irq;
const u32 *addr;
if (!dp) {
printk(KERN_ERR "sun4m_init_timers: No 'counter' node.\n");
return;
}
addr = of_get_property(dp, "address", &len);
of_node_put(dp);
if (!addr) {
printk(KERN_ERR "sun4m_init_timers: No 'address' prop.\n");
return;
}
num_cpu_timers = (len / sizeof(u32)) - 1;
for (i = 0; i < num_cpu_timers; i++) {
timers_percpu[i] = (void __iomem *)
(unsigned long) addr[i];
}
timers_global = (void __iomem *)
(unsigned long) addr[num_cpu_timers];
sbus_writel(0x00000000, &timers_global->timer_config);
sbus_writel((((1000000/HZ) + 1) << 10), &timers_global->l10_limit);
master_l10_counter = &timers_global->l10_count;
irq = sun4m_build_device_irq(NULL, SUN4M_TIMER_IRQ);
err = request_irq(irq, counter_fn, IRQF_TIMER, "timer", NULL);
if (err) {
printk(KERN_ERR "sun4m_init_timers: Register IRQ error %d.\n",
err);
return;
}
for (i = 0; i < num_cpu_timers; i++)
sbus_writel(0, &timers_percpu[i]->l14_limit);
if (num_cpu_timers == 4)
sbus_writel(SUN4M_INT_E14, &sun4m_irq_global->mask_set);
#ifdef CONFIG_SMP
{
unsigned long flags;
struct tt_entry *trap_table = &sparc_ttable[SP_TRAP_IRQ1 + (14 - 1)];
local_irq_save(flags);
trap_table->inst_one = lvl14_save[0];
trap_table->inst_two = lvl14_save[1];
trap_table->inst_three = lvl14_save[2];
trap_table->inst_four = lvl14_save[3];
local_flush_cache_all();
local_irq_restore(flags);
}
#endif
}
void __init sun4m_init_IRQ(void)
{
struct device_node *dp = of_find_node_by_name(NULL, "interrupt");
int len, i, mid, num_cpu_iregs;
const u32 *addr;
if (!dp) {
printk(KERN_ERR "sun4m_init_IRQ: No 'interrupt' node.\n");
return;
}
addr = of_get_property(dp, "address", &len);
of_node_put(dp);
if (!addr) {
printk(KERN_ERR "sun4m_init_IRQ: No 'address' prop.\n");
return;
}
num_cpu_iregs = (len / sizeof(u32)) - 1;
for (i = 0; i < num_cpu_iregs; i++) {
sun4m_irq_percpu[i] = (void __iomem *)
(unsigned long) addr[i];
}
sun4m_irq_global = (void __iomem *)
(unsigned long) addr[num_cpu_iregs];
local_irq_disable();
sbus_writel(~SUN4M_INT_MASKALL, &sun4m_irq_global->mask_set);
for (i = 0; !cpu_find_by_instance(i, NULL, &mid); i++)
sbus_writel(~0x17fff, &sun4m_irq_percpu[mid]->clear);
if (num_cpu_iregs == 4)
sbus_writel(0, &sun4m_irq_global->interrupt_target);
BTFIXUPSET_CALL(clear_clock_irq, sun4m_clear_clock_irq, BTFIXUPCALL_NORM);
BTFIXUPSET_CALL(load_profile_irq, sun4m_load_profile_irq, BTFIXUPCALL_NORM);
sparc_irq_config.init_timers = sun4m_init_timers;
sparc_irq_config.build_device_irq = sun4m_build_device_irq;
#ifdef CONFIG_SMP
BTFIXUPSET_CALL(set_cpu_int, sun4m_send_ipi, BTFIXUPCALL_NORM);
BTFIXUPSET_CALL(clear_cpu_int, sun4m_clear_ipi, BTFIXUPCALL_NORM);
BTFIXUPSET_CALL(set_irq_udt, sun4m_set_udt, BTFIXUPCALL_NORM);
#endif
}
