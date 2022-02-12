static inline void tegra_gpio_writel(struct tegra_gpio_info *tgi,
u32 val, u32 reg)
{
__raw_writel(val, tgi->regs + reg);
}
static inline u32 tegra_gpio_readl(struct tegra_gpio_info *tgi, u32 reg)
{
return __raw_readl(tgi->regs + reg);
}
static int tegra_gpio_compose(int bank, int port, int bit)
{
return (bank << 5) | ((port & 0x3) << 3) | (bit & 0x7);
}
static void tegra_gpio_mask_write(struct tegra_gpio_info *tgi, u32 reg,
int gpio, int value)
{
u32 val;
val = 0x100 << GPIO_BIT(gpio);
if (value)
val |= 1 << GPIO_BIT(gpio);
tegra_gpio_writel(tgi, val, reg);
}
static void tegra_gpio_enable(struct tegra_gpio_info *tgi, int gpio)
{
tegra_gpio_mask_write(tgi, GPIO_MSK_CNF(tgi, gpio), gpio, 1);
}
static void tegra_gpio_disable(struct tegra_gpio_info *tgi, int gpio)
{
tegra_gpio_mask_write(tgi, GPIO_MSK_CNF(tgi, gpio), gpio, 0);
}
static int tegra_gpio_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(offset);
}
static void tegra_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct tegra_gpio_info *tgi = gpiochip_get_data(chip);
pinctrl_free_gpio(offset);
tegra_gpio_disable(tgi, offset);
}
static void tegra_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct tegra_gpio_info *tgi = gpiochip_get_data(chip);
tegra_gpio_mask_write(tgi, GPIO_MSK_OUT(tgi, offset), offset, value);
}
static int tegra_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct tegra_gpio_info *tgi = gpiochip_get_data(chip);
int bval = BIT(GPIO_BIT(offset));
if (tegra_gpio_readl(tgi, GPIO_OE(tgi, offset)) & bval)
return !!(tegra_gpio_readl(tgi, GPIO_OUT(tgi, offset)) & bval);
return !!(tegra_gpio_readl(tgi, GPIO_IN(tgi, offset)) & bval);
}
static int tegra_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct tegra_gpio_info *tgi = gpiochip_get_data(chip);
tegra_gpio_mask_write(tgi, GPIO_MSK_OE(tgi, offset), offset, 0);
tegra_gpio_enable(tgi, offset);
return 0;
}
static int tegra_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct tegra_gpio_info *tgi = gpiochip_get_data(chip);
tegra_gpio_set(chip, offset, value);
tegra_gpio_mask_write(tgi, GPIO_MSK_OE(tgi, offset), offset, 1);
tegra_gpio_enable(tgi, offset);
return 0;
}
static int tegra_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
struct tegra_gpio_info *tgi = gpiochip_get_data(chip);
u32 pin_mask = BIT(GPIO_BIT(offset));
u32 cnf, oe;
cnf = tegra_gpio_readl(tgi, GPIO_CNF(tgi, offset));
if (!(cnf & pin_mask))
return -EINVAL;
oe = tegra_gpio_readl(tgi, GPIO_OE(tgi, offset));
return (oe & pin_mask) ? GPIOF_DIR_OUT : GPIOF_DIR_IN;
}
static int tegra_gpio_set_debounce(struct gpio_chip *chip, unsigned int offset,
unsigned int debounce)
{
struct tegra_gpio_info *tgi = gpiochip_get_data(chip);
struct tegra_gpio_bank *bank = &tgi->bank_info[GPIO_BANK(offset)];
unsigned int debounce_ms = DIV_ROUND_UP(debounce, 1000);
unsigned long flags;
int port;
if (!debounce_ms) {
tegra_gpio_mask_write(tgi, GPIO_MSK_DBC_EN(tgi, offset),
offset, 0);
return 0;
}
debounce_ms = min(debounce_ms, 255U);
port = GPIO_PORT(offset);
spin_lock_irqsave(&bank->dbc_lock[port], flags);
if (bank->dbc_cnt[port] < debounce_ms) {
tegra_gpio_writel(tgi, debounce_ms, GPIO_DBC_CNT(tgi, offset));
bank->dbc_cnt[port] = debounce_ms;
}
spin_unlock_irqrestore(&bank->dbc_lock[port], flags);
tegra_gpio_mask_write(tgi, GPIO_MSK_DBC_EN(tgi, offset), offset, 1);
return 0;
}
static int tegra_gpio_set_config(struct gpio_chip *chip, unsigned int offset,
unsigned long config)
{
u32 debounce;
if (pinconf_to_config_param(config) != PIN_CONFIG_INPUT_DEBOUNCE)
return -ENOTSUPP;
debounce = pinconf_to_config_argument(config);
return tegra_gpio_set_debounce(chip, offset, debounce);
}
static int tegra_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct tegra_gpio_info *tgi = gpiochip_get_data(chip);
return irq_find_mapping(tgi->irq_domain, offset);
}
static void tegra_gpio_irq_ack(struct irq_data *d)
{
struct tegra_gpio_bank *bank = irq_data_get_irq_chip_data(d);
struct tegra_gpio_info *tgi = bank->tgi;
int gpio = d->hwirq;
tegra_gpio_writel(tgi, 1 << GPIO_BIT(gpio), GPIO_INT_CLR(tgi, gpio));
}
static void tegra_gpio_irq_mask(struct irq_data *d)
{
struct tegra_gpio_bank *bank = irq_data_get_irq_chip_data(d);
struct tegra_gpio_info *tgi = bank->tgi;
int gpio = d->hwirq;
tegra_gpio_mask_write(tgi, GPIO_MSK_INT_ENB(tgi, gpio), gpio, 0);
}
static void tegra_gpio_irq_unmask(struct irq_data *d)
{
struct tegra_gpio_bank *bank = irq_data_get_irq_chip_data(d);
struct tegra_gpio_info *tgi = bank->tgi;
int gpio = d->hwirq;
tegra_gpio_mask_write(tgi, GPIO_MSK_INT_ENB(tgi, gpio), gpio, 1);
}
static int tegra_gpio_irq_set_type(struct irq_data *d, unsigned int type)
{
int gpio = d->hwirq;
struct tegra_gpio_bank *bank = irq_data_get_irq_chip_data(d);
struct tegra_gpio_info *tgi = bank->tgi;
int port = GPIO_PORT(gpio);
int lvl_type;
int val;
unsigned long flags;
int ret;
switch (type & IRQ_TYPE_SENSE_MASK) {
case IRQ_TYPE_EDGE_RISING:
lvl_type = GPIO_INT_LVL_EDGE_RISING;
break;
case IRQ_TYPE_EDGE_FALLING:
lvl_type = GPIO_INT_LVL_EDGE_FALLING;
break;
case IRQ_TYPE_EDGE_BOTH:
lvl_type = GPIO_INT_LVL_EDGE_BOTH;
break;
case IRQ_TYPE_LEVEL_HIGH:
lvl_type = GPIO_INT_LVL_LEVEL_HIGH;
break;
case IRQ_TYPE_LEVEL_LOW:
lvl_type = GPIO_INT_LVL_LEVEL_LOW;
break;
default:
return -EINVAL;
}
ret = gpiochip_lock_as_irq(&tgi->gc, gpio);
if (ret) {
dev_err(tgi->dev,
"unable to lock Tegra GPIO %d as IRQ\n", gpio);
return ret;
}
spin_lock_irqsave(&bank->lvl_lock[port], flags);
val = tegra_gpio_readl(tgi, GPIO_INT_LVL(tgi, gpio));
val &= ~(GPIO_INT_LVL_MASK << GPIO_BIT(gpio));
val |= lvl_type << GPIO_BIT(gpio);
tegra_gpio_writel(tgi, val, GPIO_INT_LVL(tgi, gpio));
spin_unlock_irqrestore(&bank->lvl_lock[port], flags);
tegra_gpio_mask_write(tgi, GPIO_MSK_OE(tgi, gpio), gpio, 0);
tegra_gpio_enable(tgi, gpio);
if (type & (IRQ_TYPE_LEVEL_LOW | IRQ_TYPE_LEVEL_HIGH))
irq_set_handler_locked(d, handle_level_irq);
else if (type & (IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING))
irq_set_handler_locked(d, handle_edge_irq);
return 0;
}
static void tegra_gpio_irq_shutdown(struct irq_data *d)
{
struct tegra_gpio_bank *bank = irq_data_get_irq_chip_data(d);
struct tegra_gpio_info *tgi = bank->tgi;
int gpio = d->hwirq;
gpiochip_unlock_as_irq(&tgi->gc, gpio);
}
static void tegra_gpio_irq_handler(struct irq_desc *desc)
{
int port;
int pin;
bool unmasked = false;
int gpio;
u32 lvl;
unsigned long sta;
struct irq_chip *chip = irq_desc_get_chip(desc);
struct tegra_gpio_bank *bank = irq_desc_get_handler_data(desc);
struct tegra_gpio_info *tgi = bank->tgi;
chained_irq_enter(chip, desc);
for (port = 0; port < 4; port++) {
gpio = tegra_gpio_compose(bank->bank, port, 0);
sta = tegra_gpio_readl(tgi, GPIO_INT_STA(tgi, gpio)) &
tegra_gpio_readl(tgi, GPIO_INT_ENB(tgi, gpio));
lvl = tegra_gpio_readl(tgi, GPIO_INT_LVL(tgi, gpio));
for_each_set_bit(pin, &sta, 8) {
tegra_gpio_writel(tgi, 1 << pin,
GPIO_INT_CLR(tgi, gpio));
if (!unmasked && lvl & (0x100 << pin)) {
unmasked = true;
chained_irq_exit(chip, desc);
}
generic_handle_irq(gpio_to_irq(gpio + pin));
}
}
if (!unmasked)
chained_irq_exit(chip, desc);
}
static int tegra_gpio_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct tegra_gpio_info *tgi = platform_get_drvdata(pdev);
unsigned long flags;
int b;
int p;
local_irq_save(flags);
for (b = 0; b < tgi->bank_count; b++) {
struct tegra_gpio_bank *bank = &tgi->bank_info[b];
for (p = 0; p < ARRAY_SIZE(bank->oe); p++) {
unsigned int gpio = (b<<5) | (p<<3);
tegra_gpio_writel(tgi, bank->cnf[p],
GPIO_CNF(tgi, gpio));
if (tgi->soc->debounce_supported) {
tegra_gpio_writel(tgi, bank->dbc_cnt[p],
GPIO_DBC_CNT(tgi, gpio));
tegra_gpio_writel(tgi, bank->dbc_enb[p],
GPIO_MSK_DBC_EN(tgi, gpio));
}
tegra_gpio_writel(tgi, bank->out[p],
GPIO_OUT(tgi, gpio));
tegra_gpio_writel(tgi, bank->oe[p],
GPIO_OE(tgi, gpio));
tegra_gpio_writel(tgi, bank->int_lvl[p],
GPIO_INT_LVL(tgi, gpio));
tegra_gpio_writel(tgi, bank->int_enb[p],
GPIO_INT_ENB(tgi, gpio));
}
}
local_irq_restore(flags);
return 0;
}
static int tegra_gpio_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct tegra_gpio_info *tgi = platform_get_drvdata(pdev);
unsigned long flags;
int b;
int p;
local_irq_save(flags);
for (b = 0; b < tgi->bank_count; b++) {
struct tegra_gpio_bank *bank = &tgi->bank_info[b];
for (p = 0; p < ARRAY_SIZE(bank->oe); p++) {
unsigned int gpio = (b<<5) | (p<<3);
bank->cnf[p] = tegra_gpio_readl(tgi,
GPIO_CNF(tgi, gpio));
bank->out[p] = tegra_gpio_readl(tgi,
GPIO_OUT(tgi, gpio));
bank->oe[p] = tegra_gpio_readl(tgi,
GPIO_OE(tgi, gpio));
if (tgi->soc->debounce_supported) {
bank->dbc_enb[p] = tegra_gpio_readl(tgi,
GPIO_MSK_DBC_EN(tgi, gpio));
bank->dbc_enb[p] = (bank->dbc_enb[p] << 8) |
bank->dbc_enb[p];
}
bank->int_enb[p] = tegra_gpio_readl(tgi,
GPIO_INT_ENB(tgi, gpio));
bank->int_lvl[p] = tegra_gpio_readl(tgi,
GPIO_INT_LVL(tgi, gpio));
tegra_gpio_writel(tgi, bank->wake_enb[p],
GPIO_INT_ENB(tgi, gpio));
}
}
local_irq_restore(flags);
return 0;
}
static int tegra_gpio_irq_set_wake(struct irq_data *d, unsigned int enable)
{
struct tegra_gpio_bank *bank = irq_data_get_irq_chip_data(d);
int gpio = d->hwirq;
u32 port, bit, mask;
port = GPIO_PORT(gpio);
bit = GPIO_BIT(gpio);
mask = BIT(bit);
if (enable)
bank->wake_enb[port] |= mask;
else
bank->wake_enb[port] &= ~mask;
return irq_set_irq_wake(bank->irq, enable);
}
static int dbg_gpio_show(struct seq_file *s, void *unused)
{
struct tegra_gpio_info *tgi = s->private;
int i;
int j;
for (i = 0; i < tgi->bank_count; i++) {
for (j = 0; j < 4; j++) {
int gpio = tegra_gpio_compose(i, j, 0);
seq_printf(s,
"%d:%d %02x %02x %02x %02x %02x %02x %06x\n",
i, j,
tegra_gpio_readl(tgi, GPIO_CNF(tgi, gpio)),
tegra_gpio_readl(tgi, GPIO_OE(tgi, gpio)),
tegra_gpio_readl(tgi, GPIO_OUT(tgi, gpio)),
tegra_gpio_readl(tgi, GPIO_IN(tgi, gpio)),
tegra_gpio_readl(tgi, GPIO_INT_STA(tgi, gpio)),
tegra_gpio_readl(tgi, GPIO_INT_ENB(tgi, gpio)),
tegra_gpio_readl(tgi, GPIO_INT_LVL(tgi, gpio)));
}
}
return 0;
}
static int dbg_gpio_open(struct inode *inode, struct file *file)
{
return single_open(file, dbg_gpio_show, inode->i_private);
}
static void tegra_gpio_debuginit(struct tegra_gpio_info *tgi)
{
(void) debugfs_create_file("tegra_gpio", S_IRUGO,
NULL, tgi, &debug_fops);
}
static inline void tegra_gpio_debuginit(struct tegra_gpio_info *tgi)
{
}
static int tegra_gpio_probe(struct platform_device *pdev)
{
const struct tegra_gpio_soc_config *config;
struct tegra_gpio_info *tgi;
struct resource *res;
struct tegra_gpio_bank *bank;
int ret;
int gpio;
int i;
int j;
config = of_device_get_match_data(&pdev->dev);
if (!config) {
dev_err(&pdev->dev, "Error: No device match found\n");
return -ENODEV;
}
tgi = devm_kzalloc(&pdev->dev, sizeof(*tgi), GFP_KERNEL);
if (!tgi)
return -ENODEV;
tgi->soc = config;
tgi->dev = &pdev->dev;
for (;;) {
res = platform_get_resource(pdev, IORESOURCE_IRQ,
tgi->bank_count);
if (!res)
break;
tgi->bank_count++;
}
if (!tgi->bank_count) {
dev_err(&pdev->dev, "Missing IRQ resource\n");
return -ENODEV;
}
tgi->gc.label = "tegra-gpio";
tgi->gc.request = tegra_gpio_request;
tgi->gc.free = tegra_gpio_free;
tgi->gc.direction_input = tegra_gpio_direction_input;
tgi->gc.get = tegra_gpio_get;
tgi->gc.direction_output = tegra_gpio_direction_output;
tgi->gc.set = tegra_gpio_set;
tgi->gc.get_direction = tegra_gpio_get_direction;
tgi->gc.to_irq = tegra_gpio_to_irq;
tgi->gc.base = 0;
tgi->gc.ngpio = tgi->bank_count * 32;
tgi->gc.parent = &pdev->dev;
tgi->gc.of_node = pdev->dev.of_node;
tgi->ic.name = "GPIO";
tgi->ic.irq_ack = tegra_gpio_irq_ack;
tgi->ic.irq_mask = tegra_gpio_irq_mask;
tgi->ic.irq_unmask = tegra_gpio_irq_unmask;
tgi->ic.irq_set_type = tegra_gpio_irq_set_type;
tgi->ic.irq_shutdown = tegra_gpio_irq_shutdown;
#ifdef CONFIG_PM_SLEEP
tgi->ic.irq_set_wake = tegra_gpio_irq_set_wake;
#endif
platform_set_drvdata(pdev, tgi);
if (config->debounce_supported)
tgi->gc.set_config = tegra_gpio_set_config;
tgi->bank_info = devm_kzalloc(&pdev->dev, tgi->bank_count *
sizeof(*tgi->bank_info), GFP_KERNEL);
if (!tgi->bank_info)
return -ENODEV;
tgi->irq_domain = irq_domain_add_linear(pdev->dev.of_node,
tgi->gc.ngpio,
&irq_domain_simple_ops, NULL);
if (!tgi->irq_domain)
return -ENODEV;
for (i = 0; i < tgi->bank_count; i++) {
res = platform_get_resource(pdev, IORESOURCE_IRQ, i);
if (!res) {
dev_err(&pdev->dev, "Missing IRQ resource\n");
return -ENODEV;
}
bank = &tgi->bank_info[i];
bank->bank = i;
bank->irq = res->start;
bank->tgi = tgi;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
tgi->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(tgi->regs))
return PTR_ERR(tgi->regs);
for (i = 0; i < tgi->bank_count; i++) {
for (j = 0; j < 4; j++) {
int gpio = tegra_gpio_compose(i, j, 0);
tegra_gpio_writel(tgi, 0x00, GPIO_INT_ENB(tgi, gpio));
}
}
ret = devm_gpiochip_add_data(&pdev->dev, &tgi->gc, tgi);
if (ret < 0) {
irq_domain_remove(tgi->irq_domain);
return ret;
}
for (gpio = 0; gpio < tgi->gc.ngpio; gpio++) {
int irq = irq_create_mapping(tgi->irq_domain, gpio);
bank = &tgi->bank_info[GPIO_BANK(gpio)];
irq_set_lockdep_class(irq, &gpio_lock_class);
irq_set_chip_data(irq, bank);
irq_set_chip_and_handler(irq, &tgi->ic, handle_simple_irq);
}
for (i = 0; i < tgi->bank_count; i++) {
bank = &tgi->bank_info[i];
irq_set_chained_handler_and_data(bank->irq,
tegra_gpio_irq_handler, bank);
for (j = 0; j < 4; j++) {
spin_lock_init(&bank->lvl_lock[j]);
spin_lock_init(&bank->dbc_lock[j]);
}
}
tegra_gpio_debuginit(tgi);
return 0;
}
static int __init tegra_gpio_init(void)
{
return platform_driver_register(&tegra_gpio_driver);
}
