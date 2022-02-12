static inline struct gsta_regs __iomem *__regs(struct gsta_gpio *chip, int nr)
{
return chip->regs[nr / GSTA_GPIO_PER_BLOCK];
}
static inline u32 __bit(int nr)
{
return 1U << (nr % GSTA_GPIO_PER_BLOCK);
}
static void gsta_gpio_set(struct gpio_chip *gpio, unsigned nr, int val)
{
struct gsta_gpio *chip = container_of(gpio, struct gsta_gpio, gpio);
struct gsta_regs __iomem *regs = __regs(chip, nr);
u32 bit = __bit(nr);
if (val)
writel(bit, &regs->dats);
else
writel(bit, &regs->datc);
}
static int gsta_gpio_get(struct gpio_chip *gpio, unsigned nr)
{
struct gsta_gpio *chip = container_of(gpio, struct gsta_gpio, gpio);
struct gsta_regs __iomem *regs = __regs(chip, nr);
u32 bit = __bit(nr);
return readl(&regs->dat) & bit;
}
static int gsta_gpio_direction_output(struct gpio_chip *gpio, unsigned nr,
int val)
{
struct gsta_gpio *chip = container_of(gpio, struct gsta_gpio, gpio);
struct gsta_regs __iomem *regs = __regs(chip, nr);
u32 bit = __bit(nr);
writel(bit, &regs->dirs);
if (val)
writel(bit, &regs->dats);
else
writel(bit, &regs->datc);
return 0;
}
static int gsta_gpio_direction_input(struct gpio_chip *gpio, unsigned nr)
{
struct gsta_gpio *chip = container_of(gpio, struct gsta_gpio, gpio);
struct gsta_regs __iomem *regs = __regs(chip, nr);
u32 bit = __bit(nr);
writel(bit, &regs->dirc);
return 0;
}
static int gsta_gpio_to_irq(struct gpio_chip *gpio, unsigned offset)
{
struct gsta_gpio *chip = container_of(gpio, struct gsta_gpio, gpio);
return chip->irq_base + offset;
}
static void gsta_gpio_setup(struct gsta_gpio *chip)
{
struct gpio_chip *gpio = &chip->gpio;
static int gpio_base;
gpio->label = dev_name(chip->dev);
gpio->owner = THIS_MODULE;
gpio->direction_input = gsta_gpio_direction_input;
gpio->get = gsta_gpio_get;
gpio->direction_output = gsta_gpio_direction_output;
gpio->set = gsta_gpio_set;
gpio->dbg_show = NULL;
gpio->base = gpio_base;
gpio->ngpio = GSTA_NR_GPIO;
gpio->can_sleep = 0;
gpio->to_irq = gsta_gpio_to_irq;
if (!gpio_base)
gpio_base = -1;
}
static void gsta_set_config(struct gsta_gpio *chip, int nr, unsigned cfg)
{
struct gsta_regs __iomem *regs = __regs(chip, nr);
unsigned long flags;
u32 bit = __bit(nr);
u32 val;
int err = 0;
pr_info("%s: %p %i %i\n", __func__, chip, nr, cfg);
if (cfg == PINMUX_TYPE_NONE)
return;
spin_lock_irqsave(&chip->lock, flags);
val = readl(&regs->afsela);
if (cfg == PINMUX_TYPE_FUNCTION)
val |= bit;
else
val &= ~bit;
writel(val | bit, &regs->afsela);
if (cfg == PINMUX_TYPE_FUNCTION) {
spin_unlock_irqrestore(&chip->lock, flags);
return;
}
switch (cfg) {
case PINMUX_TYPE_OUTPUT_LOW:
writel(bit, &regs->dirs);
writel(bit, &regs->datc);
break;
case PINMUX_TYPE_OUTPUT_HIGH:
writel(bit, &regs->dirs);
writel(bit, &regs->dats);
break;
case PINMUX_TYPE_INPUT:
writel(bit, &regs->dirc);
val = readl(&regs->pdis) | bit;
writel(val, &regs->pdis);
break;
case PINMUX_TYPE_INPUT_PULLUP:
writel(bit, &regs->dirc);
val = readl(&regs->pdis) & ~bit;
writel(val, &regs->pdis);
writel(bit, &regs->dats);
break;
case PINMUX_TYPE_INPUT_PULLDOWN:
writel(bit, &regs->dirc);
val = readl(&regs->pdis) & ~bit;
writel(val, &regs->pdis);
writel(bit, &regs->datc);
break;
default:
err = 1;
}
spin_unlock_irqrestore(&chip->lock, flags);
if (err)
pr_err("%s: chip %p, pin %i, cfg %i is invalid\n",
__func__, chip, nr, cfg);
}
static void gsta_irq_disable(struct irq_data *data)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(data);
struct gsta_gpio *chip = gc->private;
int nr = data->irq - chip->irq_base;
struct gsta_regs __iomem *regs = __regs(chip, nr);
u32 bit = __bit(nr);
u32 val;
unsigned long flags;
spin_lock_irqsave(&chip->lock, flags);
if (chip->irq_type[nr] & IRQ_TYPE_EDGE_RISING) {
val = readl(&regs->rimsc) & ~bit;
writel(val, &regs->rimsc);
}
if (chip->irq_type[nr] & IRQ_TYPE_EDGE_FALLING) {
val = readl(&regs->fimsc) & ~bit;
writel(val, &regs->fimsc);
}
spin_unlock_irqrestore(&chip->lock, flags);
return;
}
static void gsta_irq_enable(struct irq_data *data)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(data);
struct gsta_gpio *chip = gc->private;
int nr = data->irq - chip->irq_base;
struct gsta_regs __iomem *regs = __regs(chip, nr);
u32 bit = __bit(nr);
u32 val;
int type;
unsigned long flags;
type = chip->irq_type[nr];
spin_lock_irqsave(&chip->lock, flags);
val = readl(&regs->rimsc);
if (type & IRQ_TYPE_EDGE_RISING)
writel(val | bit, &regs->rimsc);
else
writel(val & ~bit, &regs->rimsc);
val = readl(&regs->rimsc);
if (type & IRQ_TYPE_EDGE_FALLING)
writel(val | bit, &regs->fimsc);
else
writel(val & ~bit, &regs->fimsc);
spin_unlock_irqrestore(&chip->lock, flags);
return;
}
static int gsta_irq_type(struct irq_data *d, unsigned int type)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct gsta_gpio *chip = gc->private;
int nr = d->irq - chip->irq_base;
if (!(type & (IRQ_TYPE_EDGE_RISING | IRQ_TYPE_EDGE_FALLING))) {
pr_debug("%s: unsupported type 0x%x\n", __func__, type);
return -EINVAL;
}
chip->irq_type[nr] = type;
gsta_irq_enable(d);
return 0;
}
static irqreturn_t gsta_gpio_handler(int irq, void *dev_id)
{
struct gsta_gpio *chip = dev_id;
struct gsta_regs __iomem *regs;
u32 is;
int i, nr, base;
irqreturn_t ret = IRQ_NONE;
for (i = 0; i < GSTA_NR_BLOCKS; i++) {
regs = chip->regs[i];
base = chip->irq_base + i * GSTA_GPIO_PER_BLOCK;
while ((is = readl(&regs->is))) {
nr = __ffs(is);
irq = base + nr;
generic_handle_irq(irq);
writel(1 << nr, &regs->ic);
ret = IRQ_HANDLED;
}
}
return ret;
}
static void gsta_alloc_irq_chip(struct gsta_gpio *chip)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
gc = irq_alloc_generic_chip(KBUILD_MODNAME, 1, chip->irq_base,
chip->reg_base, handle_simple_irq);
gc->private = chip;
ct = gc->chip_types;
ct->chip.irq_set_type = gsta_irq_type;
ct->chip.irq_disable = gsta_irq_disable;
ct->chip.irq_enable = gsta_irq_enable;
irq_setup_generic_chip(gc, 0 , 0,
IRQ_NOREQUEST | IRQ_NOPROBE, 0);
{
struct irq_chip_type *ct = gc->chip_types;
int i, j;
for (j = 0; j < GSTA_NR_GPIO; j++) {
i = chip->irq_base + j;
irq_set_chip_and_handler(i, &ct->chip, ct->handler);
irq_set_chip_data(i, gc);
irq_modify_status(i, IRQ_NOREQUEST | IRQ_NOPROBE, 0);
}
gc->irq_cnt = i - gc->irq_base;
}
}
static int gsta_probe(struct platform_device *dev)
{
int i, err;
struct pci_dev *pdev;
struct sta2x11_gpio_pdata *gpio_pdata;
struct gsta_gpio *chip;
struct resource *res;
pdev = *(struct pci_dev **)dev_get_platdata(&dev->dev);
gpio_pdata = dev_get_platdata(&pdev->dev);
if (gpio_pdata == NULL)
dev_err(&dev->dev, "no gpio config\n");
pr_debug("gpio config: %p\n", gpio_pdata);
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
chip = devm_kzalloc(&dev->dev, sizeof(*chip), GFP_KERNEL);
if (!chip)
return -ENOMEM;
chip->dev = &dev->dev;
chip->reg_base = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(chip->reg_base))
return PTR_ERR(chip->reg_base);
for (i = 0; i < GSTA_NR_BLOCKS; i++) {
chip->regs[i] = chip->reg_base + i * 4096;
writel(0, &chip->regs[i]->rimsc);
writel(0, &chip->regs[i]->fimsc);
writel(~0, &chip->regs[i]->ic);
}
spin_lock_init(&chip->lock);
gsta_gpio_setup(chip);
if (gpio_pdata)
for (i = 0; i < GSTA_NR_GPIO; i++)
gsta_set_config(chip, i, gpio_pdata->pinconfig[i]);
err = irq_alloc_descs(-1, 384, GSTA_NR_GPIO, NUMA_NO_NODE);
if (err < 0) {
dev_warn(&dev->dev, "sta2x11 gpio: Can't get irq base (%i)\n",
-err);
return err;
}
chip->irq_base = err;
gsta_alloc_irq_chip(chip);
err = request_irq(pdev->irq, gsta_gpio_handler,
IRQF_SHARED, KBUILD_MODNAME, chip);
if (err < 0) {
dev_err(&dev->dev, "sta2x11 gpio: Can't request irq (%i)\n",
-err);
goto err_free_descs;
}
err = gpiochip_add(&chip->gpio);
if (err < 0) {
dev_err(&dev->dev, "sta2x11 gpio: Can't register (%i)\n",
-err);
goto err_free_irq;
}
platform_set_drvdata(dev, chip);
return 0;
err_free_irq:
free_irq(pdev->irq, chip);
err_free_descs:
irq_free_descs(chip->irq_base, GSTA_NR_GPIO);
return err;
}
