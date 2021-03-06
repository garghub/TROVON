static inline u32 tb10x_reg_read(struct tb10x_gpio *gpio, unsigned int offs)
{
return ioread32(gpio->base + offs);
}
static inline void tb10x_reg_write(struct tb10x_gpio *gpio, unsigned int offs,
u32 val)
{
iowrite32(val, gpio->base + offs);
}
static inline void tb10x_set_bits(struct tb10x_gpio *gpio, unsigned int offs,
u32 mask, u32 val)
{
u32 r;
unsigned long flags;
spin_lock_irqsave(&gpio->spinlock, flags);
r = tb10x_reg_read(gpio, offs);
r = (r & ~mask) | (val & mask);
tb10x_reg_write(gpio, offs, r);
spin_unlock_irqrestore(&gpio->spinlock, flags);
}
static inline struct tb10x_gpio *to_tb10x_gpio(struct gpio_chip *chip)
{
return container_of(chip, struct tb10x_gpio, gc);
}
static int tb10x_gpio_direction_in(struct gpio_chip *chip, unsigned offset)
{
struct tb10x_gpio *tb10x_gpio = to_tb10x_gpio(chip);
int mask = BIT(offset);
int val = TB10X_GPIO_DIR_IN << offset;
tb10x_set_bits(tb10x_gpio, OFFSET_TO_REG_DDR, mask, val);
return 0;
}
static int tb10x_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct tb10x_gpio *tb10x_gpio = to_tb10x_gpio(chip);
int val;
val = tb10x_reg_read(tb10x_gpio, OFFSET_TO_REG_DATA);
if (val & BIT(offset))
return 1;
else
return 0;
}
static void tb10x_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct tb10x_gpio *tb10x_gpio = to_tb10x_gpio(chip);
int mask = BIT(offset);
int val = value << offset;
tb10x_set_bits(tb10x_gpio, OFFSET_TO_REG_DATA, mask, val);
}
static int tb10x_gpio_direction_out(struct gpio_chip *chip,
unsigned offset, int value)
{
struct tb10x_gpio *tb10x_gpio = to_tb10x_gpio(chip);
int mask = BIT(offset);
int val = TB10X_GPIO_DIR_OUT << offset;
tb10x_gpio_set(chip, offset, value);
tb10x_set_bits(tb10x_gpio, OFFSET_TO_REG_DDR, mask, val);
return 0;
}
static int tb10x_gpio_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(chip->base + offset);
}
static void tb10x_gpio_free(struct gpio_chip *chip, unsigned offset)
{
pinctrl_free_gpio(chip->base + offset);
}
static int tb10x_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct tb10x_gpio *tb10x_gpio = to_tb10x_gpio(chip);
return irq_create_mapping(tb10x_gpio->domain, offset);
}
static int tb10x_gpio_irq_set_type(struct irq_data *data, unsigned int type)
{
if ((type & IRQF_TRIGGER_MASK) != IRQ_TYPE_EDGE_BOTH) {
pr_err("Only (both) edge triggered interrupts supported.\n");
return -EINVAL;
}
irqd_set_trigger_type(data, type);
return IRQ_SET_MASK_OK;
}
static irqreturn_t tb10x_gpio_irq_cascade(int irq, void *data)
{
struct tb10x_gpio *tb10x_gpio = data;
u32 r = tb10x_reg_read(tb10x_gpio, OFFSET_TO_REG_CHANGE);
u32 m = tb10x_reg_read(tb10x_gpio, OFFSET_TO_REG_INT_EN);
const unsigned long bits = r & m;
int i;
for_each_set_bit(i, &bits, 32)
generic_handle_irq(irq_find_mapping(tb10x_gpio->domain, i));
return IRQ_HANDLED;
}
static int tb10x_gpio_probe(struct platform_device *pdev)
{
struct tb10x_gpio *tb10x_gpio;
struct resource *mem;
struct device_node *dn = pdev->dev.of_node;
int ret = -EBUSY;
u32 ngpio;
if (!dn)
return -EINVAL;
if (of_property_read_u32(dn, "abilis,ngpio", &ngpio))
return -EINVAL;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem) {
dev_err(&pdev->dev, "No memory resource defined.\n");
return -EINVAL;
}
tb10x_gpio = devm_kzalloc(&pdev->dev, sizeof(*tb10x_gpio), GFP_KERNEL);
if (tb10x_gpio == NULL)
return -ENOMEM;
spin_lock_init(&tb10x_gpio->spinlock);
tb10x_gpio->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(tb10x_gpio->base))
return PTR_ERR(tb10x_gpio->base);
tb10x_gpio->gc.label = of_node_full_name(dn);
tb10x_gpio->gc.dev = &pdev->dev;
tb10x_gpio->gc.owner = THIS_MODULE;
tb10x_gpio->gc.direction_input = tb10x_gpio_direction_in;
tb10x_gpio->gc.get = tb10x_gpio_get;
tb10x_gpio->gc.direction_output = tb10x_gpio_direction_out;
tb10x_gpio->gc.set = tb10x_gpio_set;
tb10x_gpio->gc.request = tb10x_gpio_request;
tb10x_gpio->gc.free = tb10x_gpio_free;
tb10x_gpio->gc.base = -1;
tb10x_gpio->gc.ngpio = ngpio;
tb10x_gpio->gc.can_sleep = 0;
ret = gpiochip_add(&tb10x_gpio->gc);
if (ret < 0) {
dev_err(&pdev->dev, "Could not add gpiochip.\n");
goto fail_gpiochip_registration;
}
platform_set_drvdata(pdev, tb10x_gpio);
if (of_find_property(dn, "interrupt-controller", NULL)) {
struct irq_chip_generic *gc;
ret = platform_get_irq(pdev, 0);
if (ret < 0) {
dev_err(&pdev->dev, "No interrupt specified.\n");
goto fail_get_irq;
}
tb10x_gpio->gc.to_irq = tb10x_gpio_to_irq;
tb10x_gpio->irq = ret;
ret = devm_request_irq(&pdev->dev, ret, tb10x_gpio_irq_cascade,
IRQF_TRIGGER_NONE | IRQF_SHARED,
dev_name(&pdev->dev), tb10x_gpio);
if (ret != 0)
goto fail_request_irq;
tb10x_gpio->domain = irq_domain_add_linear(dn,
tb10x_gpio->gc.ngpio,
&irq_generic_chip_ops, NULL);
if (!tb10x_gpio->domain) {
ret = -ENOMEM;
goto fail_irq_domain;
}
ret = irq_alloc_domain_generic_chips(tb10x_gpio->domain,
tb10x_gpio->gc.ngpio, 1, tb10x_gpio->gc.label,
handle_edge_irq, IRQ_NOREQUEST, IRQ_NOPROBE,
IRQ_GC_INIT_MASK_CACHE);
if (ret)
goto fail_irq_domain;
gc = tb10x_gpio->domain->gc->gc[0];
gc->reg_base = tb10x_gpio->base;
gc->chip_types[0].type = IRQ_TYPE_EDGE_BOTH;
gc->chip_types[0].chip.irq_ack = irq_gc_ack_set_bit;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[0].chip.irq_unmask = irq_gc_mask_set_bit;
gc->chip_types[0].chip.irq_set_type = tb10x_gpio_irq_set_type;
gc->chip_types[0].regs.ack = OFFSET_TO_REG_CHANGE;
gc->chip_types[0].regs.mask = OFFSET_TO_REG_INT_EN;
}
return 0;
fail_irq_domain:
fail_request_irq:
fail_get_irq:
gpiochip_remove(&tb10x_gpio->gc);
fail_gpiochip_registration:
fail_ioremap:
return ret;
}
static int __exit tb10x_gpio_remove(struct platform_device *pdev)
{
struct tb10x_gpio *tb10x_gpio = platform_get_drvdata(pdev);
int ret;
if (tb10x_gpio->gc.to_irq) {
irq_remove_generic_chip(tb10x_gpio->domain->gc->gc[0],
BIT(tb10x_gpio->gc.ngpio) - 1, 0, 0);
kfree(tb10x_gpio->domain->gc);
irq_domain_remove(tb10x_gpio->domain);
free_irq(tb10x_gpio->irq, tb10x_gpio);
}
ret = gpiochip_remove(&tb10x_gpio->gc);
if (ret)
return ret;
return 0;
}
