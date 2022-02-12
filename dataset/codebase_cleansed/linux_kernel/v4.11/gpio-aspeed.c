static const struct aspeed_gpio_bank *to_bank(unsigned int offset)
{
unsigned int bank = GPIO_BANK(offset);
WARN_ON(bank > ARRAY_SIZE(aspeed_gpio_banks));
return &aspeed_gpio_banks[bank];
}
static inline bool is_bank_props_sentinel(const struct aspeed_bank_props *props)
{
return !(props->input || props->output);
}
static inline const struct aspeed_bank_props *find_bank_props(
struct aspeed_gpio *gpio, unsigned int offset)
{
const struct aspeed_bank_props *props = gpio->config->props;
while (!is_bank_props_sentinel(props)) {
if (props->bank == GPIO_BANK(offset))
return props;
props++;
}
return NULL;
}
static inline bool have_gpio(struct aspeed_gpio *gpio, unsigned int offset)
{
const struct aspeed_bank_props *props = find_bank_props(gpio, offset);
const struct aspeed_gpio_bank *bank = to_bank(offset);
unsigned int group = GPIO_OFFSET(offset) / 8;
return bank->names[group][0] != '\0' &&
(!props || ((props->input | props->output) & GPIO_BIT(offset)));
}
static inline bool have_input(struct aspeed_gpio *gpio, unsigned int offset)
{
const struct aspeed_bank_props *props = find_bank_props(gpio, offset);
return !props || (props->input & GPIO_BIT(offset));
}
static inline bool have_output(struct aspeed_gpio *gpio, unsigned int offset)
{
const struct aspeed_bank_props *props = find_bank_props(gpio, offset);
return !props || (props->output & GPIO_BIT(offset));
}
static void __iomem *bank_val_reg(struct aspeed_gpio *gpio,
const struct aspeed_gpio_bank *bank,
unsigned int reg)
{
return gpio->base + bank->val_regs + reg;
}
static void __iomem *bank_irq_reg(struct aspeed_gpio *gpio,
const struct aspeed_gpio_bank *bank,
unsigned int reg)
{
return gpio->base + bank->irq_regs + reg;
}
static int aspeed_gpio_get(struct gpio_chip *gc, unsigned int offset)
{
struct aspeed_gpio *gpio = gpiochip_get_data(gc);
const struct aspeed_gpio_bank *bank = to_bank(offset);
return !!(ioread32(bank_val_reg(gpio, bank, GPIO_DATA))
& GPIO_BIT(offset));
}
static void __aspeed_gpio_set(struct gpio_chip *gc, unsigned int offset,
int val)
{
struct aspeed_gpio *gpio = gpiochip_get_data(gc);
const struct aspeed_gpio_bank *bank = to_bank(offset);
void __iomem *addr;
u32 reg;
addr = bank_val_reg(gpio, bank, GPIO_DATA);
reg = ioread32(addr);
if (val)
reg |= GPIO_BIT(offset);
else
reg &= ~GPIO_BIT(offset);
iowrite32(reg, addr);
}
static void aspeed_gpio_set(struct gpio_chip *gc, unsigned int offset,
int val)
{
struct aspeed_gpio *gpio = gpiochip_get_data(gc);
unsigned long flags;
spin_lock_irqsave(&gpio->lock, flags);
__aspeed_gpio_set(gc, offset, val);
spin_unlock_irqrestore(&gpio->lock, flags);
}
static int aspeed_gpio_dir_in(struct gpio_chip *gc, unsigned int offset)
{
struct aspeed_gpio *gpio = gpiochip_get_data(gc);
const struct aspeed_gpio_bank *bank = to_bank(offset);
unsigned long flags;
u32 reg;
if (!have_input(gpio, offset))
return -ENOTSUPP;
spin_lock_irqsave(&gpio->lock, flags);
reg = ioread32(bank_val_reg(gpio, bank, GPIO_DIR));
iowrite32(reg & ~GPIO_BIT(offset), bank_val_reg(gpio, bank, GPIO_DIR));
spin_unlock_irqrestore(&gpio->lock, flags);
return 0;
}
static int aspeed_gpio_dir_out(struct gpio_chip *gc,
unsigned int offset, int val)
{
struct aspeed_gpio *gpio = gpiochip_get_data(gc);
const struct aspeed_gpio_bank *bank = to_bank(offset);
unsigned long flags;
u32 reg;
if (!have_output(gpio, offset))
return -ENOTSUPP;
spin_lock_irqsave(&gpio->lock, flags);
reg = ioread32(bank_val_reg(gpio, bank, GPIO_DIR));
iowrite32(reg | GPIO_BIT(offset), bank_val_reg(gpio, bank, GPIO_DIR));
__aspeed_gpio_set(gc, offset, val);
spin_unlock_irqrestore(&gpio->lock, flags);
return 0;
}
static int aspeed_gpio_get_direction(struct gpio_chip *gc, unsigned int offset)
{
struct aspeed_gpio *gpio = gpiochip_get_data(gc);
const struct aspeed_gpio_bank *bank = to_bank(offset);
unsigned long flags;
u32 val;
if (!have_input(gpio, offset))
return 0;
if (!have_output(gpio, offset))
return 1;
spin_lock_irqsave(&gpio->lock, flags);
val = ioread32(bank_val_reg(gpio, bank, GPIO_DIR)) & GPIO_BIT(offset);
spin_unlock_irqrestore(&gpio->lock, flags);
return !val;
}
static inline int irqd_to_aspeed_gpio_data(struct irq_data *d,
struct aspeed_gpio **gpio,
const struct aspeed_gpio_bank **bank,
u32 *bit)
{
int offset;
struct aspeed_gpio *internal;
offset = irqd_to_hwirq(d);
internal = irq_data_get_irq_chip_data(d);
if (!have_irq(internal, offset))
return -ENOTSUPP;
*gpio = internal;
*bank = to_bank(offset);
*bit = GPIO_BIT(offset);
return 0;
}
static void aspeed_gpio_irq_ack(struct irq_data *d)
{
const struct aspeed_gpio_bank *bank;
struct aspeed_gpio *gpio;
unsigned long flags;
void __iomem *status_addr;
u32 bit;
int rc;
rc = irqd_to_aspeed_gpio_data(d, &gpio, &bank, &bit);
if (rc)
return;
status_addr = bank_irq_reg(gpio, bank, GPIO_IRQ_STATUS);
spin_lock_irqsave(&gpio->lock, flags);
iowrite32(bit, status_addr);
spin_unlock_irqrestore(&gpio->lock, flags);
}
static void aspeed_gpio_irq_set_mask(struct irq_data *d, bool set)
{
const struct aspeed_gpio_bank *bank;
struct aspeed_gpio *gpio;
unsigned long flags;
u32 reg, bit;
void __iomem *addr;
int rc;
rc = irqd_to_aspeed_gpio_data(d, &gpio, &bank, &bit);
if (rc)
return;
addr = bank_irq_reg(gpio, bank, GPIO_IRQ_ENABLE);
spin_lock_irqsave(&gpio->lock, flags);
reg = ioread32(addr);
if (set)
reg |= bit;
else
reg &= bit;
iowrite32(reg, addr);
spin_unlock_irqrestore(&gpio->lock, flags);
}
static void aspeed_gpio_irq_mask(struct irq_data *d)
{
aspeed_gpio_irq_set_mask(d, false);
}
static void aspeed_gpio_irq_unmask(struct irq_data *d)
{
aspeed_gpio_irq_set_mask(d, true);
}
static int aspeed_gpio_set_type(struct irq_data *d, unsigned int type)
{
u32 type0 = 0;
u32 type1 = 0;
u32 type2 = 0;
u32 bit, reg;
const struct aspeed_gpio_bank *bank;
irq_flow_handler_t handler;
struct aspeed_gpio *gpio;
unsigned long flags;
void __iomem *addr;
int rc;
rc = irqd_to_aspeed_gpio_data(d, &gpio, &bank, &bit);
if (rc)
return -EINVAL;
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_BOTH:
type2 |= bit;
case IRQ_TYPE_EDGE_RISING:
type0 |= bit;
case IRQ_TYPE_EDGE_FALLING:
handler = handle_edge_irq;
break;
case IRQ_TYPE_LEVEL_HIGH:
type0 |= bit;
case IRQ_TYPE_LEVEL_LOW:
type1 |= bit;
handler = handle_level_irq;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&gpio->lock, flags);
addr = bank_irq_reg(gpio, bank, GPIO_IRQ_TYPE0);
reg = ioread32(addr);
reg = (reg & ~bit) | type0;
iowrite32(reg, addr);
addr = bank_irq_reg(gpio, bank, GPIO_IRQ_TYPE1);
reg = ioread32(addr);
reg = (reg & ~bit) | type1;
iowrite32(reg, addr);
addr = bank_irq_reg(gpio, bank, GPIO_IRQ_TYPE2);
reg = ioread32(addr);
reg = (reg & ~bit) | type2;
iowrite32(reg, addr);
spin_unlock_irqrestore(&gpio->lock, flags);
irq_set_handler_locked(d, handler);
return 0;
}
static void aspeed_gpio_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct irq_chip *ic = irq_desc_get_chip(desc);
struct aspeed_gpio *data = gpiochip_get_data(gc);
unsigned int i, p, girq;
unsigned long reg;
chained_irq_enter(ic, desc);
for (i = 0; i < ARRAY_SIZE(aspeed_gpio_banks); i++) {
const struct aspeed_gpio_bank *bank = &aspeed_gpio_banks[i];
reg = ioread32(bank_irq_reg(data, bank, GPIO_IRQ_STATUS));
for_each_set_bit(p, &reg, 32) {
girq = irq_find_mapping(gc->irqdomain, i * 32 + p);
generic_handle_irq(girq);
}
}
chained_irq_exit(ic, desc);
}
static void set_irq_valid_mask(struct aspeed_gpio *gpio)
{
const struct aspeed_bank_props *props = gpio->config->props;
while (!is_bank_props_sentinel(props)) {
unsigned int offset;
const unsigned long int input = props->input;
for_each_clear_bit(offset, &input, 32) {
unsigned int i = props->bank * 32 + offset;
if (i >= gpio->config->nr_gpios)
break;
clear_bit(i, gpio->chip.irq_valid_mask);
}
props++;
}
}
static int aspeed_gpio_setup_irqs(struct aspeed_gpio *gpio,
struct platform_device *pdev)
{
int rc;
rc = platform_get_irq(pdev, 0);
if (rc < 0)
return rc;
gpio->irq = rc;
set_irq_valid_mask(gpio);
rc = gpiochip_irqchip_add(&gpio->chip, &aspeed_gpio_irqchip,
0, handle_bad_irq, IRQ_TYPE_NONE);
if (rc) {
dev_info(&pdev->dev, "Could not add irqchip\n");
return rc;
}
gpiochip_set_chained_irqchip(&gpio->chip, &aspeed_gpio_irqchip,
gpio->irq, aspeed_gpio_irq_handler);
return 0;
}
static int aspeed_gpio_request(struct gpio_chip *chip, unsigned int offset)
{
if (!have_gpio(gpiochip_get_data(chip), offset))
return -ENODEV;
return pinctrl_request_gpio(chip->base + offset);
}
static void aspeed_gpio_free(struct gpio_chip *chip, unsigned int offset)
{
pinctrl_free_gpio(chip->base + offset);
}
static int __init aspeed_gpio_probe(struct platform_device *pdev)
{
const struct of_device_id *gpio_id;
struct aspeed_gpio *gpio;
struct resource *res;
int rc;
gpio = devm_kzalloc(&pdev->dev, sizeof(*gpio), GFP_KERNEL);
if (!gpio)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
gpio->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(gpio->base))
return PTR_ERR(gpio->base);
spin_lock_init(&gpio->lock);
gpio_id = of_match_node(aspeed_gpio_of_table, pdev->dev.of_node);
if (!gpio_id)
return -EINVAL;
gpio->config = gpio_id->data;
gpio->chip.ngpio = gpio->config->nr_gpios;
gpio->chip.parent = &pdev->dev;
gpio->chip.direction_input = aspeed_gpio_dir_in;
gpio->chip.direction_output = aspeed_gpio_dir_out;
gpio->chip.get_direction = aspeed_gpio_get_direction;
gpio->chip.request = aspeed_gpio_request;
gpio->chip.free = aspeed_gpio_free;
gpio->chip.get = aspeed_gpio_get;
gpio->chip.set = aspeed_gpio_set;
gpio->chip.label = dev_name(&pdev->dev);
gpio->chip.base = -1;
gpio->chip.irq_need_valid_mask = true;
rc = devm_gpiochip_add_data(&pdev->dev, &gpio->chip, gpio);
if (rc < 0)
return rc;
return aspeed_gpio_setup_irqs(gpio, pdev);
}
