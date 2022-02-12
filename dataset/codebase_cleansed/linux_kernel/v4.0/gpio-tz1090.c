static inline void tz1090_gpio_write(struct tz1090_gpio_bank *bank,
unsigned int reg_offs, u32 data)
{
iowrite32(data, bank->reg + reg_offs);
}
static inline u32 tz1090_gpio_read(struct tz1090_gpio_bank *bank,
unsigned int reg_offs)
{
return ioread32(bank->reg + reg_offs);
}
static inline void _tz1090_gpio_clear_bit(struct tz1090_gpio_bank *bank,
unsigned int reg_offs,
unsigned int offset)
{
u32 value;
value = tz1090_gpio_read(bank, reg_offs);
value &= ~BIT(offset);
tz1090_gpio_write(bank, reg_offs, value);
}
static void tz1090_gpio_clear_bit(struct tz1090_gpio_bank *bank,
unsigned int reg_offs,
unsigned int offset)
{
int lstat;
__global_lock2(lstat);
_tz1090_gpio_clear_bit(bank, reg_offs, offset);
__global_unlock2(lstat);
}
static inline void _tz1090_gpio_set_bit(struct tz1090_gpio_bank *bank,
unsigned int reg_offs,
unsigned int offset)
{
u32 value;
value = tz1090_gpio_read(bank, reg_offs);
value |= BIT(offset);
tz1090_gpio_write(bank, reg_offs, value);
}
static void tz1090_gpio_set_bit(struct tz1090_gpio_bank *bank,
unsigned int reg_offs,
unsigned int offset)
{
int lstat;
__global_lock2(lstat);
_tz1090_gpio_set_bit(bank, reg_offs, offset);
__global_unlock2(lstat);
}
static inline void _tz1090_gpio_mod_bit(struct tz1090_gpio_bank *bank,
unsigned int reg_offs,
unsigned int offset,
bool val)
{
u32 value;
value = tz1090_gpio_read(bank, reg_offs);
value &= ~BIT(offset);
if (val)
value |= BIT(offset);
tz1090_gpio_write(bank, reg_offs, value);
}
static void tz1090_gpio_mod_bit(struct tz1090_gpio_bank *bank,
unsigned int reg_offs,
unsigned int offset,
bool val)
{
int lstat;
__global_lock2(lstat);
_tz1090_gpio_mod_bit(bank, reg_offs, offset, val);
__global_unlock2(lstat);
}
static inline int tz1090_gpio_read_bit(struct tz1090_gpio_bank *bank,
unsigned int reg_offs,
unsigned int offset)
{
return tz1090_gpio_read(bank, reg_offs) & BIT(offset);
}
static int tz1090_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct tz1090_gpio_bank *bank = to_bank(chip);
tz1090_gpio_set_bit(bank, REG_GPIO_DIR, offset);
return 0;
}
static int tz1090_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int output_value)
{
struct tz1090_gpio_bank *bank = to_bank(chip);
int lstat;
__global_lock2(lstat);
_tz1090_gpio_mod_bit(bank, REG_GPIO_DOUT, offset, output_value);
_tz1090_gpio_clear_bit(bank, REG_GPIO_DIR, offset);
__global_unlock2(lstat);
return 0;
}
static int tz1090_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct tz1090_gpio_bank *bank = to_bank(chip);
return tz1090_gpio_read_bit(bank, REG_GPIO_DIN, offset);
}
static void tz1090_gpio_set(struct gpio_chip *chip, unsigned int offset,
int output_value)
{
struct tz1090_gpio_bank *bank = to_bank(chip);
tz1090_gpio_mod_bit(bank, REG_GPIO_DOUT, offset, output_value);
}
static int tz1090_gpio_request(struct gpio_chip *chip, unsigned int offset)
{
struct tz1090_gpio_bank *bank = to_bank(chip);
int ret;
ret = pinctrl_request_gpio(chip->base + offset);
if (ret)
return ret;
tz1090_gpio_set_bit(bank, REG_GPIO_DIR, offset);
tz1090_gpio_set_bit(bank, REG_GPIO_BIT_EN, offset);
return 0;
}
static void tz1090_gpio_free(struct gpio_chip *chip, unsigned int offset)
{
struct tz1090_gpio_bank *bank = to_bank(chip);
pinctrl_free_gpio(chip->base + offset);
tz1090_gpio_clear_bit(bank, REG_GPIO_BIT_EN, offset);
}
static int tz1090_gpio_to_irq(struct gpio_chip *chip, unsigned int offset)
{
struct tz1090_gpio_bank *bank = to_bank(chip);
if (!bank->domain)
return -EINVAL;
return irq_create_mapping(bank->domain, offset);
}
static inline struct tz1090_gpio_bank *irqd_to_gpio_bank(struct irq_data *data)
{
return (struct tz1090_gpio_bank *)data->domain->host_data;
}
static void tz1090_gpio_irq_polarity(struct tz1090_gpio_bank *bank,
unsigned int offset, unsigned int polarity)
{
tz1090_gpio_mod_bit(bank, REG_GPIO_IRQ_PLRT, offset, polarity);
}
static void tz1090_gpio_irq_type(struct tz1090_gpio_bank *bank,
unsigned int offset, unsigned int type)
{
tz1090_gpio_mod_bit(bank, REG_GPIO_IRQ_TYPE, offset, type);
}
static void tz1090_gpio_irq_next_edge(struct tz1090_gpio_bank *bank,
unsigned int offset)
{
unsigned int value_p, value_i;
int lstat;
__global_lock2(lstat);
value_i = ~tz1090_gpio_read(bank, REG_GPIO_DIN);
value_p = tz1090_gpio_read(bank, REG_GPIO_IRQ_PLRT);
value_p &= ~BIT(offset);
value_p |= value_i & BIT(offset);
tz1090_gpio_write(bank, REG_GPIO_IRQ_PLRT, value_p);
__global_unlock2(lstat);
}
static unsigned int gpio_startup_irq(struct irq_data *data)
{
WARN(irqd_get_trigger_type(data) == IRQ_TYPE_NONE,
"irq type not set before enabling gpio irq %d", data->irq);
irq_gc_ack_clr_bit(data);
irq_gc_mask_set_bit(data);
return 0;
}
static int gpio_set_irq_type(struct irq_data *data, unsigned int flow_type)
{
struct tz1090_gpio_bank *bank = irqd_to_gpio_bank(data);
unsigned int type;
unsigned int polarity;
switch (flow_type) {
case IRQ_TYPE_EDGE_BOTH:
type = REG_GPIO_IRQ_TYPE_EDGE;
polarity = REG_GPIO_IRQ_PLRT_LOW;
break;
case IRQ_TYPE_EDGE_RISING:
type = REG_GPIO_IRQ_TYPE_EDGE;
polarity = REG_GPIO_IRQ_PLRT_HIGH;
break;
case IRQ_TYPE_EDGE_FALLING:
type = REG_GPIO_IRQ_TYPE_EDGE;
polarity = REG_GPIO_IRQ_PLRT_LOW;
break;
case IRQ_TYPE_LEVEL_HIGH:
type = REG_GPIO_IRQ_TYPE_LEVEL;
polarity = REG_GPIO_IRQ_PLRT_HIGH;
break;
case IRQ_TYPE_LEVEL_LOW:
type = REG_GPIO_IRQ_TYPE_LEVEL;
polarity = REG_GPIO_IRQ_PLRT_LOW;
break;
default:
return -EINVAL;
}
tz1090_gpio_irq_type(bank, data->hwirq, type);
irq_setup_alt_chip(data, flow_type);
if (flow_type == IRQ_TYPE_EDGE_BOTH)
tz1090_gpio_irq_next_edge(bank, data->hwirq);
else
tz1090_gpio_irq_polarity(bank, data->hwirq, polarity);
return 0;
}
static int gpio_set_irq_wake(struct irq_data *data, unsigned int on)
{
struct tz1090_gpio_bank *bank = irqd_to_gpio_bank(data);
#ifdef CONFIG_PM_DEBUG
pr_info("irq_wake irq%d state:%d\n", data->irq, on);
#endif
return irq_set_irq_wake(bank->irq, on);
}
static void tz1090_gpio_irq_handler(unsigned int irq, struct irq_desc *desc)
{
irq_hw_number_t hw;
unsigned int irq_stat, irq_no;
struct tz1090_gpio_bank *bank;
struct irq_desc *child_desc;
bank = (struct tz1090_gpio_bank *)irq_desc_get_handler_data(desc);
irq_stat = tz1090_gpio_read(bank, REG_GPIO_DIR) &
tz1090_gpio_read(bank, REG_GPIO_IRQ_STS) &
tz1090_gpio_read(bank, REG_GPIO_IRQ_EN) &
0x3FFFFFFF;
for (hw = 0; irq_stat; irq_stat >>= 1, ++hw) {
if (!(irq_stat & 1))
continue;
irq_no = irq_linear_revmap(bank->domain, hw);
child_desc = irq_to_desc(irq_no);
if (irqd_get_trigger_type(&child_desc->irq_data)
== IRQ_TYPE_EDGE_BOTH)
tz1090_gpio_irq_next_edge(bank, hw);
generic_handle_irq_desc(irq_no, child_desc);
}
}
static int tz1090_gpio_bank_probe(struct tz1090_gpio_bank_info *info)
{
struct device_node *np = info->node;
struct device *dev = info->priv->dev;
struct tz1090_gpio_bank *bank;
struct irq_chip_generic *gc;
int err;
bank = devm_kzalloc(dev, sizeof(*bank), GFP_KERNEL);
if (!bank) {
dev_err(dev, "unable to allocate driver data\n");
return -ENOMEM;
}
bank->reg = info->priv->reg + info->index * 4;
snprintf(bank->label, sizeof(bank->label), "tz1090-gpio-%u",
info->index);
bank->chip.label = bank->label;
bank->chip.dev = dev;
bank->chip.direction_input = tz1090_gpio_direction_input;
bank->chip.direction_output = tz1090_gpio_direction_output;
bank->chip.get = tz1090_gpio_get;
bank->chip.set = tz1090_gpio_set;
bank->chip.free = tz1090_gpio_free;
bank->chip.request = tz1090_gpio_request;
bank->chip.to_irq = tz1090_gpio_to_irq;
bank->chip.of_node = np;
bank->chip.base = info->index * 30;
bank->chip.ngpio = 30;
gpiochip_add(&bank->chip);
bank->irq = irq_of_parse_and_map(np, 0);
if (!bank->irq) {
dev_info(dev, "IRQ not provided for bank %u, IRQs disabled\n",
info->index);
return 0;
}
dev_info(dev, "Setting up IRQs for GPIO bank %u\n",
info->index);
tz1090_gpio_write(bank, REG_GPIO_IRQ_EN, 0);
bank->domain = irq_domain_add_linear(np,
bank->chip.ngpio,
&irq_generic_chip_ops,
bank);
err = irq_alloc_domain_generic_chips(bank->domain, bank->chip.ngpio, 2,
bank->label, handle_bad_irq, 0, 0,
IRQ_GC_INIT_NESTED_LOCK);
if (err) {
dev_info(dev,
"irq_alloc_domain_generic_chips failed for bank %u, IRQs disabled\n",
info->index);
irq_domain_remove(bank->domain);
return 0;
}
gc = irq_get_domain_generic_chip(bank->domain, 0);
gc->reg_base = bank->reg;
gc->chip_types[0].type = IRQ_TYPE_LEVEL_MASK;
gc->chip_types[0].handler = handle_level_irq;
gc->chip_types[0].regs.ack = REG_GPIO_IRQ_STS;
gc->chip_types[0].regs.mask = REG_GPIO_IRQ_EN;
gc->chip_types[0].chip.irq_startup = gpio_startup_irq;
gc->chip_types[0].chip.irq_ack = irq_gc_ack_clr_bit;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[0].chip.irq_unmask = irq_gc_mask_set_bit;
gc->chip_types[0].chip.irq_set_type = gpio_set_irq_type;
gc->chip_types[0].chip.irq_set_wake = gpio_set_irq_wake;
gc->chip_types[0].chip.flags = IRQCHIP_MASK_ON_SUSPEND;
gc->chip_types[1].type = IRQ_TYPE_EDGE_BOTH;
gc->chip_types[1].handler = handle_edge_irq;
gc->chip_types[1].regs.ack = REG_GPIO_IRQ_STS;
gc->chip_types[1].regs.mask = REG_GPIO_IRQ_EN;
gc->chip_types[1].chip.irq_startup = gpio_startup_irq;
gc->chip_types[1].chip.irq_ack = irq_gc_ack_clr_bit;
gc->chip_types[1].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[1].chip.irq_unmask = irq_gc_mask_set_bit;
gc->chip_types[1].chip.irq_set_type = gpio_set_irq_type;
gc->chip_types[1].chip.irq_set_wake = gpio_set_irq_wake;
gc->chip_types[1].chip.flags = IRQCHIP_MASK_ON_SUSPEND;
irq_set_handler_data(bank->irq, bank);
irq_set_chained_handler(bank->irq, tz1090_gpio_irq_handler);
return 0;
}
static void tz1090_gpio_register_banks(struct tz1090_gpio *priv)
{
struct device_node *np = priv->dev->of_node;
struct device_node *node;
for_each_available_child_of_node(np, node) {
struct tz1090_gpio_bank_info info;
u32 addr;
int ret;
ret = of_property_read_u32(node, "reg", &addr);
if (ret) {
dev_err(priv->dev, "invalid reg on %s\n",
node->full_name);
continue;
}
if (addr >= 3) {
dev_err(priv->dev, "index %u in %s out of range\n",
addr, node->full_name);
continue;
}
info.index = addr;
info.node = of_node_get(node);
info.priv = priv;
ret = tz1090_gpio_bank_probe(&info);
if (ret) {
dev_err(priv->dev, "failure registering %s\n",
node->full_name);
of_node_put(node);
continue;
}
}
}
static int tz1090_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *res_regs;
struct tz1090_gpio priv;
if (!np) {
dev_err(&pdev->dev, "must be instantiated via devicetree\n");
return -ENOENT;
}
res_regs = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res_regs) {
dev_err(&pdev->dev, "cannot find registers resource\n");
return -ENOENT;
}
priv.dev = &pdev->dev;
priv.reg = devm_ioremap(&pdev->dev, res_regs->start,
resource_size(res_regs));
if (!priv.reg) {
dev_err(&pdev->dev, "unable to ioremap registers\n");
return -ENOMEM;
}
tz1090_gpio_register_banks(&priv);
return 0;
}
static int __init tz1090_gpio_init(void)
{
return platform_driver_register(&tz1090_gpio_driver);
}
