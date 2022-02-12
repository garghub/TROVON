void __init ixp4xx_map_io(void)
{
iotable_init(ixp4xx_io_desc, ARRAY_SIZE(ixp4xx_io_desc));
}
static void gpio_line_config(u8 line, u32 direction)
{
if (direction == IXP4XX_GPIO_IN)
*IXP4XX_GPIO_GPOER |= (1 << line);
else
*IXP4XX_GPIO_GPOER &= ~(1 << line);
}
static void gpio_line_get(u8 line, int *value)
{
*value = (*IXP4XX_GPIO_GPINR >> line) & 0x1;
}
static void gpio_line_set(u8 line, int value)
{
if (value == IXP4XX_GPIO_HIGH)
*IXP4XX_GPIO_GPOUTR |= (1 << line);
else if (value == IXP4XX_GPIO_LOW)
*IXP4XX_GPIO_GPOUTR &= ~(1 << line);
}
static int ixp4xx_gpio_to_irq(struct gpio_chip *chip, unsigned gpio)
{
int irq;
for (irq = 0; irq < 32; irq++) {
if (irq2gpio[irq] == gpio)
return irq;
}
return -EINVAL;
}
static int ixp4xx_set_irq_type(struct irq_data *d, unsigned int type)
{
int line = irq2gpio[d->irq];
u32 int_style;
enum ixp4xx_irq_type irq_type;
volatile u32 *int_reg;
if (line < 0)
return -EINVAL;
switch (type){
case IRQ_TYPE_EDGE_BOTH:
int_style = IXP4XX_GPIO_STYLE_TRANSITIONAL;
irq_type = IXP4XX_IRQ_EDGE;
break;
case IRQ_TYPE_EDGE_RISING:
int_style = IXP4XX_GPIO_STYLE_RISING_EDGE;
irq_type = IXP4XX_IRQ_EDGE;
break;
case IRQ_TYPE_EDGE_FALLING:
int_style = IXP4XX_GPIO_STYLE_FALLING_EDGE;
irq_type = IXP4XX_IRQ_EDGE;
break;
case IRQ_TYPE_LEVEL_HIGH:
int_style = IXP4XX_GPIO_STYLE_ACTIVE_HIGH;
irq_type = IXP4XX_IRQ_LEVEL;
break;
case IRQ_TYPE_LEVEL_LOW:
int_style = IXP4XX_GPIO_STYLE_ACTIVE_LOW;
irq_type = IXP4XX_IRQ_LEVEL;
break;
default:
return -EINVAL;
}
if (irq_type == IXP4XX_IRQ_EDGE)
ixp4xx_irq_edge |= (1 << d->irq);
else
ixp4xx_irq_edge &= ~(1 << d->irq);
if (line >= 8) {
line -= 8;
int_reg = IXP4XX_GPIO_GPIT2R;
} else {
int_reg = IXP4XX_GPIO_GPIT1R;
}
*int_reg &= ~(IXP4XX_GPIO_STYLE_CLEAR <<
(line * IXP4XX_GPIO_STYLE_SIZE));
*IXP4XX_GPIO_GPISR = (1 << line);
*int_reg |= (int_style << (line * IXP4XX_GPIO_STYLE_SIZE));
gpio_line_config(irq2gpio[d->irq], IXP4XX_GPIO_IN);
return 0;
}
static void ixp4xx_irq_mask(struct irq_data *d)
{
if ((cpu_is_ixp46x() || cpu_is_ixp43x()) && d->irq >= 32)
*IXP4XX_ICMR2 &= ~(1 << (d->irq - 32));
else
*IXP4XX_ICMR &= ~(1 << d->irq);
}
static void ixp4xx_irq_ack(struct irq_data *d)
{
int line = (d->irq < 32) ? irq2gpio[d->irq] : -1;
if (line >= 0)
*IXP4XX_GPIO_GPISR = (1 << line);
}
static void ixp4xx_irq_unmask(struct irq_data *d)
{
if (!(ixp4xx_irq_edge & (1 << d->irq)))
ixp4xx_irq_ack(d);
if ((cpu_is_ixp46x() || cpu_is_ixp43x()) && d->irq >= 32)
*IXP4XX_ICMR2 |= (1 << (d->irq - 32));
else
*IXP4XX_ICMR |= (1 << d->irq);
}
void __init ixp4xx_init_irq(void)
{
int i = 0;
cpu_idle_poll_ctrl(true);
*IXP4XX_ICLR = 0x0;
*IXP4XX_ICMR = 0x0;
if (cpu_is_ixp46x() || cpu_is_ixp43x()) {
*IXP4XX_ICLR2 = 0x00;
*IXP4XX_ICMR2 = 0x00;
}
for(i = 0; i < NR_IRQS; i++) {
irq_set_chip_and_handler(i, &ixp4xx_irq_chip,
handle_level_irq);
irq_clear_status_flags(i, IRQ_NOREQUEST);
}
}
static irqreturn_t ixp4xx_timer_interrupt(int irq, void *dev_id)
{
struct clock_event_device *evt = dev_id;
*IXP4XX_OSST = IXP4XX_OSST_TIMER_1_PEND;
evt->event_handler(evt);
return IRQ_HANDLED;
}
void __init ixp4xx_timer_init(void)
{
*IXP4XX_OSRT1 = 0;
*IXP4XX_OSST = IXP4XX_OSST_TIMER_1_PEND;
*IXP4XX_OSTS = 0;
setup_irq(IRQ_IXP4XX_TIMER1, &ixp4xx_timer_irq);
ixp4xx_clocksource_init();
ixp4xx_clockevent_init();
}
void __init ixp4xx_set_udc_info(struct pxa2xx_udc_mach_info *info)
{
memcpy(&ixp4xx_udc_info, info, sizeof *info);
}
static int ixp4xx_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
gpio_line_config(gpio, IXP4XX_GPIO_IN);
return 0;
}
static int ixp4xx_gpio_direction_output(struct gpio_chip *chip, unsigned gpio,
int level)
{
gpio_line_set(gpio, level);
gpio_line_config(gpio, IXP4XX_GPIO_OUT);
return 0;
}
static int ixp4xx_gpio_get_value(struct gpio_chip *chip, unsigned gpio)
{
int value;
gpio_line_get(gpio, &value);
return value;
}
static void ixp4xx_gpio_set_value(struct gpio_chip *chip, unsigned gpio,
int value)
{
gpio_line_set(gpio, value);
}
void __init ixp4xx_sys_init(void)
{
ixp4xx_exp_bus_size = SZ_16M;
platform_add_devices(ixp4xx_devices, ARRAY_SIZE(ixp4xx_devices));
gpiochip_add_data(&ixp4xx_gpio_chip, NULL);
if (cpu_is_ixp46x()) {
int region;
platform_add_devices(ixp46x_devices,
ARRAY_SIZE(ixp46x_devices));
for (region = 0; region < 7; region++) {
if((*(IXP4XX_EXP_REG(0x4 * region)) & 0x200)) {
ixp4xx_exp_bus_size = SZ_32M;
break;
}
}
}
printk("IXP4xx: Using %luMiB expansion bus window size\n",
ixp4xx_exp_bus_size >> 20);
}
static u64 notrace ixp4xx_read_sched_clock(void)
{
return *IXP4XX_OSTS;
}
static u64 ixp4xx_clocksource_read(struct clocksource *c)
{
return *IXP4XX_OSTS;
}
static void __init ixp4xx_clocksource_init(void)
{
sched_clock_register(ixp4xx_read_sched_clock, 32, ixp4xx_timer_freq);
clocksource_mmio_init(NULL, "OSTS", ixp4xx_timer_freq, 200, 32,
ixp4xx_clocksource_read);
}
static int ixp4xx_set_next_event(unsigned long evt,
struct clock_event_device *unused)
{
unsigned long opts = *IXP4XX_OSRT1 & IXP4XX_OST_RELOAD_MASK;
*IXP4XX_OSRT1 = (evt & ~IXP4XX_OST_RELOAD_MASK) | opts;
return 0;
}
static int ixp4xx_shutdown(struct clock_event_device *evt)
{
unsigned long opts = *IXP4XX_OSRT1 & IXP4XX_OST_RELOAD_MASK;
unsigned long osrt = *IXP4XX_OSRT1 & ~IXP4XX_OST_RELOAD_MASK;
opts &= ~IXP4XX_OST_ENABLE;
*IXP4XX_OSRT1 = osrt | opts;
return 0;
}
static int ixp4xx_set_oneshot(struct clock_event_device *evt)
{
unsigned long opts = IXP4XX_OST_ENABLE | IXP4XX_OST_ONE_SHOT;
unsigned long osrt = 0;
*IXP4XX_OSRT1 = osrt | opts;
return 0;
}
static int ixp4xx_set_periodic(struct clock_event_device *evt)
{
unsigned long opts = IXP4XX_OST_ENABLE;
unsigned long osrt = IXP4XX_LATCH & ~IXP4XX_OST_RELOAD_MASK;
*IXP4XX_OSRT1 = osrt | opts;
return 0;
}
static int ixp4xx_resume(struct clock_event_device *evt)
{
unsigned long opts = *IXP4XX_OSRT1 & IXP4XX_OST_RELOAD_MASK;
unsigned long osrt = *IXP4XX_OSRT1 & ~IXP4XX_OST_RELOAD_MASK;
opts |= IXP4XX_OST_ENABLE;
*IXP4XX_OSRT1 = osrt | opts;
return 0;
}
static void __init ixp4xx_clockevent_init(void)
{
clockevent_ixp4xx.cpumask = cpumask_of(0);
clockevents_config_and_register(&clockevent_ixp4xx, IXP4XX_TIMER_FREQ,
0xf, 0xfffffffe);
}
void ixp4xx_restart(enum reboot_mode mode, const char *cmd)
{
if (mode == REBOOT_SOFT) {
soft_restart(0);
} else {
*IXP4XX_OSWK = IXP4XX_WDT_KEY;
*IXP4XX_OSWT = 0;
*IXP4XX_OSWE = IXP4XX_WDT_RESET_ENABLE | IXP4XX_WDT_COUNT_ENABLE;
}
}
static int ixp4xx_needs_bounce(struct device *dev, dma_addr_t dma_addr, size_t size)
{
return (dma_addr + size) > SZ_64M;
}
static int ixp4xx_platform_notify_remove(struct device *dev)
{
if (dev_is_pci(dev))
dmabounce_unregister_dev(dev);
return 0;
}
static int ixp4xx_platform_notify(struct device *dev)
{
dev->dma_mask = &dev->coherent_dma_mask;
#ifdef CONFIG_PCI
if (dev_is_pci(dev)) {
dev->coherent_dma_mask = DMA_BIT_MASK(28);
dmabounce_register_dev(dev, 2048, 4096, ixp4xx_needs_bounce);
return 0;
}
#endif
dev->coherent_dma_mask = DMA_BIT_MASK(32);
return 0;
}
int dma_set_coherent_mask(struct device *dev, u64 mask)
{
if (dev_is_pci(dev))
mask &= DMA_BIT_MASK(28);
if ((mask & DMA_BIT_MASK(28)) == DMA_BIT_MASK(28)) {
dev->coherent_dma_mask = mask;
return 0;
}
return -EIO;
}
static void __iomem *ixp4xx_ioremap_caller(phys_addr_t addr, size_t size,
unsigned int mtype, void *caller)
{
if (!is_pci_memory(addr))
return __arm_ioremap_caller(addr, size, mtype, caller);
return (void __iomem *)addr;
}
static void ixp4xx_iounmap(volatile void __iomem *addr)
{
if (!is_pci_memory((__force u32)addr))
__iounmap(addr);
}
void __init ixp4xx_init_early(void)
{
platform_notify = ixp4xx_platform_notify;
#ifdef CONFIG_PCI
platform_notify_remove = ixp4xx_platform_notify_remove;
#endif
#ifdef CONFIG_IXP4XX_INDIRECT_PCI
arch_ioremap_caller = ixp4xx_ioremap_caller;
arch_iounmap = ixp4xx_iounmap;
#endif
}
