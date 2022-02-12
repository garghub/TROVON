static void __iomem *byt_gpio_reg(struct gpio_chip *chip, unsigned offset,
int reg)
{
struct byt_gpio *vg = to_byt_gpio(chip);
u32 reg_offset;
if (reg == BYT_INT_STAT_REG)
reg_offset = (offset / 32) * 4;
else
reg_offset = vg->range->pins[offset] * 16;
return vg->reg_base + reg_offset + reg;
}
static bool is_special_pin(struct byt_gpio *vg, unsigned offset)
{
if (!strcmp(vg->range->name, BYT_SCORE_ACPI_UID) &&
offset >= 92 && offset <= 93)
return true;
if (!strcmp(vg->range->name, BYT_SUS_ACPI_UID) &&
offset >= 11 && offset <= 21)
return true;
return false;
}
static int byt_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct byt_gpio *vg = to_byt_gpio(chip);
void __iomem *reg = byt_gpio_reg(chip, offset, BYT_CONF0_REG);
u32 value;
bool special;
value = readl(reg) & BYT_PIN_MUX;
special = is_special_pin(vg, offset);
if ((special && value != 1) || (!special && value)) {
dev_err(&vg->pdev->dev,
"pin %u cannot be used as GPIO.\n", offset);
return -EINVAL;
}
pm_runtime_get(&vg->pdev->dev);
return 0;
}
static void byt_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct byt_gpio *vg = to_byt_gpio(chip);
void __iomem *reg = byt_gpio_reg(&vg->chip, offset, BYT_CONF0_REG);
u32 value;
value = readl(reg);
value &= ~(BYT_TRIG_POS | BYT_TRIG_NEG | BYT_TRIG_LVL);
writel(value, reg);
pm_runtime_put(&vg->pdev->dev);
}
static int byt_irq_type(struct irq_data *d, unsigned type)
{
struct byt_gpio *vg = to_byt_gpio(irq_data_get_irq_chip_data(d));
u32 offset = irqd_to_hwirq(d);
u32 value;
unsigned long flags;
void __iomem *reg = byt_gpio_reg(&vg->chip, offset, BYT_CONF0_REG);
if (offset >= vg->chip.ngpio)
return -EINVAL;
spin_lock_irqsave(&vg->lock, flags);
value = readl(reg);
WARN(value & BYT_DIRECT_IRQ_EN,
"Bad pad config for io mode, force direct_irq_en bit clearing");
value &= ~(BYT_DIRECT_IRQ_EN | BYT_TRIG_POS | BYT_TRIG_NEG |
BYT_TRIG_LVL);
switch (type) {
case IRQ_TYPE_LEVEL_HIGH:
value |= BYT_TRIG_LVL;
case IRQ_TYPE_EDGE_RISING:
value |= BYT_TRIG_POS;
break;
case IRQ_TYPE_LEVEL_LOW:
value |= BYT_TRIG_LVL;
case IRQ_TYPE_EDGE_FALLING:
value |= BYT_TRIG_NEG;
break;
case IRQ_TYPE_EDGE_BOTH:
value |= (BYT_TRIG_NEG | BYT_TRIG_POS);
break;
}
writel(value, reg);
spin_unlock_irqrestore(&vg->lock, flags);
return 0;
}
static int byt_gpio_get(struct gpio_chip *chip, unsigned offset)
{
void __iomem *reg = byt_gpio_reg(chip, offset, BYT_VAL_REG);
return readl(reg) & BYT_LEVEL;
}
static void byt_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct byt_gpio *vg = to_byt_gpio(chip);
void __iomem *reg = byt_gpio_reg(chip, offset, BYT_VAL_REG);
unsigned long flags;
u32 old_val;
spin_lock_irqsave(&vg->lock, flags);
old_val = readl(reg);
if (value)
writel(old_val | BYT_LEVEL, reg);
else
writel(old_val & ~BYT_LEVEL, reg);
spin_unlock_irqrestore(&vg->lock, flags);
}
static int byt_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct byt_gpio *vg = to_byt_gpio(chip);
void __iomem *reg = byt_gpio_reg(chip, offset, BYT_VAL_REG);
unsigned long flags;
u32 value;
spin_lock_irqsave(&vg->lock, flags);
value = readl(reg) | BYT_DIR_MASK;
value &= ~BYT_INPUT_EN;
writel(value, reg);
spin_unlock_irqrestore(&vg->lock, flags);
return 0;
}
static int byt_gpio_direction_output(struct gpio_chip *chip,
unsigned gpio, int value)
{
struct byt_gpio *vg = to_byt_gpio(chip);
void __iomem *conf_reg = byt_gpio_reg(chip, gpio, BYT_CONF0_REG);
void __iomem *reg = byt_gpio_reg(chip, gpio, BYT_VAL_REG);
unsigned long flags;
u32 reg_val;
spin_lock_irqsave(&vg->lock, flags);
WARN(readl(conf_reg) & BYT_DIRECT_IRQ_EN,
"Potential Error: Setting GPIO with direct_irq_en to output");
reg_val = readl(reg) | BYT_DIR_MASK;
reg_val &= ~(BYT_OUTPUT_EN | BYT_INPUT_EN);
if (value)
writel(reg_val | BYT_LEVEL, reg);
else
writel(reg_val & ~BYT_LEVEL, reg);
spin_unlock_irqrestore(&vg->lock, flags);
return 0;
}
static void byt_gpio_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
struct byt_gpio *vg = to_byt_gpio(chip);
int i;
unsigned long flags;
u32 conf0, val, offs;
spin_lock_irqsave(&vg->lock, flags);
for (i = 0; i < vg->chip.ngpio; i++) {
const char *pull_str = NULL;
const char *pull = NULL;
const char *label;
offs = vg->range->pins[i] * 16;
conf0 = readl(vg->reg_base + offs + BYT_CONF0_REG);
val = readl(vg->reg_base + offs + BYT_VAL_REG);
label = gpiochip_is_requested(chip, i);
if (!label)
label = "Unrequested";
switch (conf0 & BYT_PULL_ASSIGN_MASK) {
case BYT_PULL_ASSIGN_UP:
pull = "up";
break;
case BYT_PULL_ASSIGN_DOWN:
pull = "down";
break;
}
switch (conf0 & BYT_PULL_STR_MASK) {
case BYT_PULL_STR_2K:
pull_str = "2k";
break;
case BYT_PULL_STR_10K:
pull_str = "10k";
break;
case BYT_PULL_STR_20K:
pull_str = "20k";
break;
case BYT_PULL_STR_40K:
pull_str = "40k";
break;
}
seq_printf(s,
" gpio-%-3d (%-20.20s) %s %s %s pad-%-3d offset:0x%03x mux:%d %s%s%s",
i,
label,
val & BYT_INPUT_EN ? " " : "in",
val & BYT_OUTPUT_EN ? " " : "out",
val & BYT_LEVEL ? "hi" : "lo",
vg->range->pins[i], offs,
conf0 & 0x7,
conf0 & BYT_TRIG_NEG ? " fall" : " ",
conf0 & BYT_TRIG_POS ? " rise" : " ",
conf0 & BYT_TRIG_LVL ? " level" : " ");
if (pull && pull_str)
seq_printf(s, " %-4s %-3s", pull, pull_str);
else
seq_puts(s, " ");
if (conf0 & BYT_IODEN)
seq_puts(s, " open-drain");
seq_puts(s, "\n");
}
spin_unlock_irqrestore(&vg->lock, flags);
}
static void byt_gpio_irq_handler(unsigned irq, struct irq_desc *desc)
{
struct irq_data *data = irq_desc_get_irq_data(desc);
struct byt_gpio *vg = to_byt_gpio(irq_desc_get_handler_data(desc));
struct irq_chip *chip = irq_data_get_irq_chip(data);
u32 base, pin, mask;
void __iomem *reg;
u32 pending;
unsigned virq;
int looplimit = 0;
for (base = 0; base < vg->chip.ngpio; base += 32) {
reg = byt_gpio_reg(&vg->chip, base, BYT_INT_STAT_REG);
while ((pending = readl(reg))) {
pin = __ffs(pending);
mask = BIT(pin);
writel(mask, reg);
virq = irq_find_mapping(vg->chip.irqdomain, base + pin);
generic_handle_irq(virq);
if (looplimit++ > 32) {
dev_err(&vg->pdev->dev,
"Gpio %d interrupt flood, disabling\n",
base + pin);
reg = byt_gpio_reg(&vg->chip, base + pin,
BYT_CONF0_REG);
mask = readl(reg);
mask &= ~(BYT_TRIG_NEG | BYT_TRIG_POS |
BYT_TRIG_LVL);
writel(mask, reg);
mask = readl(reg);
break;
}
}
}
chip->irq_eoi(data);
}
static void byt_irq_unmask(struct irq_data *d)
{
}
static void byt_irq_mask(struct irq_data *d)
{
}
static void byt_gpio_irq_init_hw(struct byt_gpio *vg)
{
void __iomem *reg;
u32 base, value;
for (base = 0; base < vg->chip.ngpio; base += 32) {
reg = byt_gpio_reg(&vg->chip, base, BYT_INT_STAT_REG);
writel(0xffffffff, reg);
value = readl(reg);
if (value)
dev_err(&vg->pdev->dev,
"GPIO interrupt error, pins misconfigured\n");
}
}
static int byt_gpio_probe(struct platform_device *pdev)
{
struct byt_gpio *vg;
struct gpio_chip *gc;
struct resource *mem_rc, *irq_rc;
struct device *dev = &pdev->dev;
struct acpi_device *acpi_dev;
struct pinctrl_gpio_range *range;
acpi_handle handle = ACPI_HANDLE(dev);
int ret;
if (acpi_bus_get_device(handle, &acpi_dev))
return -ENODEV;
vg = devm_kzalloc(dev, sizeof(struct byt_gpio), GFP_KERNEL);
if (!vg) {
dev_err(&pdev->dev, "can't allocate byt_gpio chip data\n");
return -ENOMEM;
}
for (range = byt_ranges; range->name; range++) {
if (!strcmp(acpi_dev->pnp.unique_id, range->name)) {
vg->chip.ngpio = range->npins;
vg->range = range;
break;
}
}
if (!vg->chip.ngpio || !vg->range)
return -ENODEV;
vg->pdev = pdev;
platform_set_drvdata(pdev, vg);
mem_rc = platform_get_resource(pdev, IORESOURCE_MEM, 0);
vg->reg_base = devm_ioremap_resource(dev, mem_rc);
if (IS_ERR(vg->reg_base))
return PTR_ERR(vg->reg_base);
spin_lock_init(&vg->lock);
gc = &vg->chip;
gc->label = dev_name(&pdev->dev);
gc->owner = THIS_MODULE;
gc->request = byt_gpio_request;
gc->free = byt_gpio_free;
gc->direction_input = byt_gpio_direction_input;
gc->direction_output = byt_gpio_direction_output;
gc->get = byt_gpio_get;
gc->set = byt_gpio_set;
gc->dbg_show = byt_gpio_dbg_show;
gc->base = -1;
gc->can_sleep = false;
gc->dev = dev;
ret = gpiochip_add(gc);
if (ret) {
dev_err(&pdev->dev, "failed adding byt-gpio chip\n");
return ret;
}
irq_rc = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (irq_rc && irq_rc->start) {
byt_gpio_irq_init_hw(vg);
ret = gpiochip_irqchip_add(gc, &byt_irqchip, 0,
handle_simple_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(dev, "failed to add irqchip\n");
gpiochip_remove(gc);
return ret;
}
gpiochip_set_chained_irqchip(gc, &byt_irqchip,
(unsigned)irq_rc->start,
byt_gpio_irq_handler);
}
pm_runtime_enable(dev);
return 0;
}
static int byt_gpio_runtime_suspend(struct device *dev)
{
return 0;
}
static int byt_gpio_runtime_resume(struct device *dev)
{
return 0;
}
static int byt_gpio_remove(struct platform_device *pdev)
{
struct byt_gpio *vg = platform_get_drvdata(pdev);
pm_runtime_disable(&pdev->dev);
gpiochip_remove(&vg->chip);
return 0;
}
static int __init byt_gpio_init(void)
{
return platform_driver_register(&byt_gpio_driver);
}
