static void sun4c_mask_irq(struct irq_data *data)
{
unsigned long mask = (unsigned long)data->chip_data;
if (mask) {
unsigned long flags;
local_irq_save(flags);
mask = sbus_readb(interrupt_enable) & ~mask;
sbus_writeb(mask, interrupt_enable);
local_irq_restore(flags);
}
}
static void sun4c_unmask_irq(struct irq_data *data)
{
unsigned long mask = (unsigned long)data->chip_data;
if (mask) {
unsigned long flags;
local_irq_save(flags);
mask = sbus_readb(interrupt_enable) | mask;
sbus_writeb(mask, interrupt_enable);
local_irq_restore(flags);
}
}
static unsigned int sun4c_startup_irq(struct irq_data *data)
{
irq_link(data->irq);
sun4c_unmask_irq(data);
return 0;
}
static void sun4c_shutdown_irq(struct irq_data *data)
{
sun4c_mask_irq(data);
irq_unlink(data->irq);
}
static unsigned int sun4c_build_device_irq(struct platform_device *op,
unsigned int real_irq)
{
unsigned int irq;
if (real_irq >= 16) {
prom_printf("Bogus sun4c IRQ %u\n", real_irq);
prom_halt();
}
irq = irq_alloc(real_irq, real_irq);
if (irq) {
unsigned long mask = 0UL;
switch (real_irq) {
case 1:
mask = SUN4C_INT_E1;
break;
case 8:
mask = SUN4C_INT_E8;
break;
case 10:
mask = SUN4C_INT_E10;
break;
case 14:
mask = SUN4C_INT_E14;
break;
default:
break;
}
irq_set_chip_and_handler_name(irq, &sun4c_irq,
handle_level_irq, "level");
irq_set_chip_data(irq, (void *)mask);
}
return irq;
}
static void sun4c_clear_clock_irq(void)
{
sbus_readl(&sun4c_timers->l10_limit);
}
static void sun4c_load_profile_irq(int cpu, unsigned int limit)
{
}
static void __init sun4c_init_timers(irq_handler_t counter_fn)
{
const struct linux_prom_irqs *prom_irqs;
struct device_node *dp;
unsigned int irq;
const u32 *addr;
int err;
dp = of_find_node_by_name(NULL, "counter-timer");
if (!dp) {
prom_printf("sun4c_init_timers: Unable to find counter-timer\n");
prom_halt();
}
addr = of_get_property(dp, "address", NULL);
if (!addr) {
prom_printf("sun4c_init_timers: No address property\n");
prom_halt();
}
sun4c_timers = (void __iomem *) (unsigned long) addr[0];
prom_irqs = of_get_property(dp, "intr", NULL);
of_node_put(dp);
if (!prom_irqs) {
prom_printf("sun4c_init_timers: No intr property\n");
prom_halt();
}
sbus_writel((((1000000/HZ) + 1) << 10), &sun4c_timers->l10_limit);
master_l10_counter = &sun4c_timers->l10_count;
irq = sun4c_build_device_irq(NULL, prom_irqs[0].pri);
err = request_irq(irq, counter_fn, IRQF_TIMER, "timer", NULL);
if (err) {
prom_printf("sun4c_init_timers: request_irq() fails with %d\n", err);
prom_halt();
}
sun4c_mask_irq(irq_get_irq_data(irq));
}
static void sun4c_nop(void)
{
}
void __init sun4c_init_IRQ(void)
{
struct device_node *dp;
const u32 *addr;
dp = of_find_node_by_name(NULL, "interrupt-enable");
if (!dp) {
prom_printf("sun4c_init_IRQ: Unable to find interrupt-enable\n");
prom_halt();
}
addr = of_get_property(dp, "address", NULL);
of_node_put(dp);
if (!addr) {
prom_printf("sun4c_init_IRQ: No address property\n");
prom_halt();
}
interrupt_enable = (void __iomem *) (unsigned long) addr[0];
BTFIXUPSET_CALL(clear_clock_irq, sun4c_clear_clock_irq, BTFIXUPCALL_NORM);
BTFIXUPSET_CALL(load_profile_irq, sun4c_load_profile_irq, BTFIXUPCALL_NOP);
sparc_irq_config.init_timers = sun4c_init_timers;
sparc_irq_config.build_device_irq = sun4c_build_device_irq;
#ifdef CONFIG_SMP
BTFIXUPSET_CALL(set_cpu_int, sun4c_nop, BTFIXUPCALL_NOP);
BTFIXUPSET_CALL(clear_cpu_int, sun4c_nop, BTFIXUPCALL_NOP);
BTFIXUPSET_CALL(set_irq_udt, sun4c_nop, BTFIXUPCALL_NOP);
#endif
sbus_writeb(SUN4C_INT_ENABLE, interrupt_enable);
}
