static struct davinci_gpio_regs __iomem *gpio2regs(unsigned gpio)
{
void __iomem *ptr;
if (gpio < 32 * 1)
ptr = gpio_base + 0x10;
else if (gpio < 32 * 2)
ptr = gpio_base + 0x38;
else if (gpio < 32 * 3)
ptr = gpio_base + 0x60;
else if (gpio < 32 * 4)
ptr = gpio_base + 0x88;
else if (gpio < 32 * 5)
ptr = gpio_base + 0xb0;
else
ptr = NULL;
return ptr;
}
static inline struct davinci_gpio_regs __iomem *irq2regs(int irq)
{
struct davinci_gpio_regs __iomem *g;
g = (__force struct davinci_gpio_regs __iomem *)irq_get_chip_data(irq);
return g;
}
static inline int __davinci_direction(struct gpio_chip *chip,
unsigned offset, bool out, int value)
{
struct davinci_gpio_controller *d = chip2controller(chip);
struct davinci_gpio_regs __iomem *g = d->regs;
unsigned long flags;
u32 temp;
u32 mask = 1 << offset;
spin_lock_irqsave(&d->lock, flags);
temp = __raw_readl(&g->dir);
if (out) {
temp &= ~mask;
__raw_writel(mask, value ? &g->set_data : &g->clr_data);
} else {
temp |= mask;
}
__raw_writel(temp, &g->dir);
spin_unlock_irqrestore(&d->lock, flags);
return 0;
}
static int davinci_direction_in(struct gpio_chip *chip, unsigned offset)
{
return __davinci_direction(chip, offset, false, 0);
}
static int
davinci_direction_out(struct gpio_chip *chip, unsigned offset, int value)
{
return __davinci_direction(chip, offset, true, value);
}
static int davinci_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct davinci_gpio_controller *d = chip2controller(chip);
struct davinci_gpio_regs __iomem *g = d->regs;
return (1 << offset) & __raw_readl(&g->in_data);
}
static void
davinci_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct davinci_gpio_controller *d = chip2controller(chip);
struct davinci_gpio_regs __iomem *g = d->regs;
__raw_writel((1 << offset), value ? &g->set_data : &g->clr_data);
}
static int davinci_gpio_probe(struct platform_device *pdev)
{
int i, base;
unsigned ngpio;
struct davinci_gpio_controller *chips;
struct davinci_gpio_platform_data *pdata;
struct davinci_gpio_regs __iomem *regs;
struct device *dev = &pdev->dev;
struct resource *res;
pdata = dev->platform_data;
if (!pdata) {
dev_err(dev, "No platform data found\n");
return -EINVAL;
}
ngpio = pdata->ngpio;
if (ngpio == 0) {
dev_err(dev, "How many GPIOs?\n");
return -EINVAL;
}
if (WARN_ON(DAVINCI_N_GPIO < ngpio))
ngpio = DAVINCI_N_GPIO;
chips = devm_kzalloc(dev,
ngpio * sizeof(struct davinci_gpio_controller),
GFP_KERNEL);
if (!chips) {
dev_err(dev, "Memory allocation failed\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "Invalid memory resource\n");
return -EBUSY;
}
gpio_base = devm_ioremap_resource(dev, res);
if (IS_ERR(gpio_base))
return PTR_ERR(gpio_base);
for (i = 0, base = 0; base < ngpio; i++, base += 32) {
chips[i].chip.label = "DaVinci";
chips[i].chip.direction_input = davinci_direction_in;
chips[i].chip.get = davinci_gpio_get;
chips[i].chip.direction_output = davinci_direction_out;
chips[i].chip.set = davinci_gpio_set;
chips[i].chip.base = base;
chips[i].chip.ngpio = ngpio - base;
if (chips[i].chip.ngpio > 32)
chips[i].chip.ngpio = 32;
spin_lock_init(&chips[i].lock);
regs = gpio2regs(base);
chips[i].regs = regs;
chips[i].set_data = &regs->set_data;
chips[i].clr_data = &regs->clr_data;
chips[i].in_data = &regs->in_data;
gpiochip_add(&chips[i].chip);
}
platform_set_drvdata(pdev, chips);
davinci_gpio_irq_setup(pdev);
return 0;
}
static void gpio_irq_disable(struct irq_data *d)
{
struct davinci_gpio_regs __iomem *g = irq2regs(d->irq);
u32 mask = (u32) irq_data_get_irq_handler_data(d);
__raw_writel(mask, &g->clr_falling);
__raw_writel(mask, &g->clr_rising);
}
static void gpio_irq_enable(struct irq_data *d)
{
struct davinci_gpio_regs __iomem *g = irq2regs(d->irq);
u32 mask = (u32) irq_data_get_irq_handler_data(d);
unsigned status = irqd_get_trigger_type(d);
status &= IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING;
if (!status)
status = IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING;
if (status & IRQ_TYPE_EDGE_FALLING)
__raw_writel(mask, &g->set_falling);
if (status & IRQ_TYPE_EDGE_RISING)
__raw_writel(mask, &g->set_rising);
}
static int gpio_irq_type(struct irq_data *d, unsigned trigger)
{
if (trigger & ~(IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING))
return -EINVAL;
return 0;
}
static void
gpio_irq_handler(unsigned irq, struct irq_desc *desc)
{
struct davinci_gpio_regs __iomem *g;
u32 mask = 0xffff;
struct davinci_gpio_controller *d;
d = (struct davinci_gpio_controller *)irq_desc_get_handler_data(desc);
g = (struct davinci_gpio_regs __iomem *)d->regs;
if (irq & 1)
mask <<= 16;
desc->irq_data.chip->irq_mask(&desc->irq_data);
desc->irq_data.chip->irq_ack(&desc->irq_data);
while (1) {
u32 status;
int n;
int res;
status = __raw_readl(&g->intstat) & mask;
if (!status)
break;
__raw_writel(status, &g->intstat);
n = d->irq_base;
if (irq & 1) {
n += 16;
status >>= 16;
}
while (status) {
res = ffs(status);
n += res;
generic_handle_irq(n - 1);
status >>= res;
}
}
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
static int gpio_to_irq_banked(struct gpio_chip *chip, unsigned offset)
{
struct davinci_gpio_controller *d = chip2controller(chip);
if (d->irq_base >= 0)
return d->irq_base + offset;
else
return -ENODEV;
}
static int gpio_to_irq_unbanked(struct gpio_chip *chip, unsigned offset)
{
struct davinci_gpio_controller *d = chip2controller(chip);
if (offset < d->gpio_unbanked)
return d->gpio_irq + offset;
else
return -ENODEV;
}
static int gpio_irq_type_unbanked(struct irq_data *data, unsigned trigger)
{
struct davinci_gpio_controller *d;
struct davinci_gpio_regs __iomem *g;
u32 mask;
d = (struct davinci_gpio_controller *)data->handler_data;
g = (struct davinci_gpio_regs __iomem *)d->regs;
mask = __gpio_mask(data->irq - d->gpio_irq);
if (trigger & ~(IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING))
return -EINVAL;
__raw_writel(mask, (trigger & IRQ_TYPE_EDGE_FALLING)
? &g->set_falling : &g->clr_falling);
__raw_writel(mask, (trigger & IRQ_TYPE_EDGE_RISING)
? &g->set_rising : &g->clr_rising);
return 0;
}
static int davinci_gpio_irq_setup(struct platform_device *pdev)
{
unsigned gpio, irq, bank;
struct clk *clk;
u32 binten = 0;
unsigned ngpio, bank_irq;
struct device *dev = &pdev->dev;
struct resource *res;
struct davinci_gpio_controller *chips = platform_get_drvdata(pdev);
struct davinci_gpio_platform_data *pdata = dev->platform_data;
struct davinci_gpio_regs __iomem *g;
ngpio = pdata->ngpio;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res) {
dev_err(dev, "Invalid IRQ resource\n");
return -EBUSY;
}
bank_irq = res->start;
if (!bank_irq) {
dev_err(dev, "Invalid IRQ resource\n");
return -ENODEV;
}
clk = devm_clk_get(dev, "gpio");
if (IS_ERR(clk)) {
printk(KERN_ERR "Error %ld getting gpio clock?\n",
PTR_ERR(clk));
return PTR_ERR(clk);
}
clk_prepare_enable(clk);
for (gpio = 0, bank = 0; gpio < ngpio; bank++, gpio += 32) {
chips[bank].chip.to_irq = gpio_to_irq_banked;
chips[bank].irq_base = pdata->gpio_unbanked
? -EINVAL
: (pdata->intc_irq_num + gpio);
}
if (pdata->gpio_unbanked) {
static struct irq_chip_type gpio_unbanked;
chips[0].chip.to_irq = gpio_to_irq_unbanked;
chips[0].gpio_irq = bank_irq;
chips[0].gpio_unbanked = pdata->gpio_unbanked;
binten = BIT(0);
irq = bank_irq;
gpio_unbanked = *container_of(irq_get_chip(irq),
struct irq_chip_type, chip);
gpio_unbanked.chip.name = "GPIO-AINTC";
gpio_unbanked.chip.irq_set_type = gpio_irq_type_unbanked;
g = gpio2regs(0);
__raw_writel(~0, &g->set_falling);
__raw_writel(~0, &g->set_rising);
for (gpio = 0; gpio < pdata->gpio_unbanked; gpio++, irq++) {
irq_set_chip(irq, &gpio_unbanked.chip);
irq_set_handler_data(irq, &chips[gpio / 32]);
irq_set_status_flags(irq, IRQ_TYPE_EDGE_BOTH);
}
goto done;
}
for (gpio = 0, irq = gpio_to_irq(0), bank = 0;
gpio < ngpio;
bank++, bank_irq++) {
unsigned i;
g = gpio2regs(gpio);
__raw_writel(~0, &g->clr_falling);
__raw_writel(~0, &g->clr_rising);
irq_set_chained_handler(bank_irq, gpio_irq_handler);
irq_set_handler_data(bank_irq, &chips[gpio / 32]);
for (i = 0; i < 16 && gpio < ngpio; i++, irq++, gpio++) {
irq_set_chip(irq, &gpio_irqchip);
irq_set_chip_data(irq, (__force void *)g);
irq_set_handler_data(irq, (void *)__gpio_mask(gpio));
irq_set_handler(irq, handle_simple_irq);
set_irq_flags(irq, IRQF_VALID);
}
binten |= BIT(bank);
}
done:
__raw_writel(binten, gpio_base + BINTEN);
printk(KERN_INFO "DaVinci: %d gpio irqs\n", irq - gpio_to_irq(0));
return 0;
}
static int __init davinci_gpio_drv_reg(void)
{
return platform_driver_register(&davinci_gpio_driver);
}
