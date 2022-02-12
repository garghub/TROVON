static int tegra_gpio_compose(int bank, int port, int bit)
{
return (bank << 5) | ((port & 0x3) << 3) | (bit & 0x7);
}
static void tegra_gpio_mask_write(u32 reg, int gpio, int value)
{
u32 val;
val = 0x100 << GPIO_BIT(gpio);
if (value)
val |= 1 << GPIO_BIT(gpio);
__raw_writel(val, reg);
}
void tegra_gpio_enable(int gpio)
{
tegra_gpio_mask_write(GPIO_MSK_CNF(gpio), gpio, 1);
}
void tegra_gpio_disable(int gpio)
{
tegra_gpio_mask_write(GPIO_MSK_CNF(gpio), gpio, 0);
}
static void tegra_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
tegra_gpio_mask_write(GPIO_MSK_OUT(offset), offset, value);
}
static int tegra_gpio_get(struct gpio_chip *chip, unsigned offset)
{
return (__raw_readl(GPIO_IN(offset)) >> GPIO_BIT(offset)) & 0x1;
}
static int tegra_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
tegra_gpio_mask_write(GPIO_MSK_OE(offset), offset, 0);
return 0;
}
static int tegra_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
tegra_gpio_set(chip, offset, value);
tegra_gpio_mask_write(GPIO_MSK_OE(offset), offset, 1);
return 0;
}
static void tegra_gpio_irq_ack(struct irq_data *d)
{
int gpio = d->irq - INT_GPIO_BASE;
__raw_writel(1 << GPIO_BIT(gpio), GPIO_INT_CLR(gpio));
}
static void tegra_gpio_irq_mask(struct irq_data *d)
{
int gpio = d->irq - INT_GPIO_BASE;
tegra_gpio_mask_write(GPIO_MSK_INT_ENB(gpio), gpio, 0);
}
static void tegra_gpio_irq_unmask(struct irq_data *d)
{
int gpio = d->irq - INT_GPIO_BASE;
tegra_gpio_mask_write(GPIO_MSK_INT_ENB(gpio), gpio, 1);
}
static int tegra_gpio_irq_set_type(struct irq_data *d, unsigned int type)
{
int gpio = d->irq - INT_GPIO_BASE;
struct tegra_gpio_bank *bank = irq_data_get_irq_chip_data(d);
int port = GPIO_PORT(gpio);
int lvl_type;
int val;
unsigned long flags;
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
spin_lock_irqsave(&bank->lvl_lock[port], flags);
val = __raw_readl(GPIO_INT_LVL(gpio));
val &= ~(GPIO_INT_LVL_MASK << GPIO_BIT(gpio));
val |= lvl_type << GPIO_BIT(gpio);
__raw_writel(val, GPIO_INT_LVL(gpio));
spin_unlock_irqrestore(&bank->lvl_lock[port], flags);
if (type & (IRQ_TYPE_LEVEL_LOW | IRQ_TYPE_LEVEL_HIGH))
__irq_set_handler_locked(d->irq, handle_level_irq);
else if (type & (IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING))
__irq_set_handler_locked(d->irq, handle_edge_irq);
return 0;
}
static void tegra_gpio_irq_handler(unsigned int irq, struct irq_desc *desc)
{
struct tegra_gpio_bank *bank;
int port;
int pin;
int unmasked = 0;
struct irq_chip *chip = irq_desc_get_chip(desc);
chained_irq_enter(chip, desc);
bank = irq_get_handler_data(irq);
for (port = 0; port < 4; port++) {
int gpio = tegra_gpio_compose(bank->bank, port, 0);
unsigned long sta = __raw_readl(GPIO_INT_STA(gpio)) &
__raw_readl(GPIO_INT_ENB(gpio));
u32 lvl = __raw_readl(GPIO_INT_LVL(gpio));
for_each_set_bit(pin, &sta, 8) {
__raw_writel(1 << pin, GPIO_INT_CLR(gpio));
if (lvl & (0x100 << pin)) {
unmasked = 1;
chained_irq_exit(chip, desc);
}
generic_handle_irq(gpio_to_irq(gpio + pin));
}
}
if (!unmasked)
chained_irq_exit(chip, desc);
}
void tegra_gpio_resume(void)
{
unsigned long flags;
int b;
int p;
local_irq_save(flags);
for (b = 0; b < ARRAY_SIZE(tegra_gpio_banks); b++) {
struct tegra_gpio_bank *bank = &tegra_gpio_banks[b];
for (p = 0; p < ARRAY_SIZE(bank->oe); p++) {
unsigned int gpio = (b<<5) | (p<<3);
__raw_writel(bank->cnf[p], GPIO_CNF(gpio));
__raw_writel(bank->out[p], GPIO_OUT(gpio));
__raw_writel(bank->oe[p], GPIO_OE(gpio));
__raw_writel(bank->int_lvl[p], GPIO_INT_LVL(gpio));
__raw_writel(bank->int_enb[p], GPIO_INT_ENB(gpio));
}
}
local_irq_restore(flags);
}
void tegra_gpio_suspend(void)
{
unsigned long flags;
int b;
int p;
local_irq_save(flags);
for (b = 0; b < ARRAY_SIZE(tegra_gpio_banks); b++) {
struct tegra_gpio_bank *bank = &tegra_gpio_banks[b];
for (p = 0; p < ARRAY_SIZE(bank->oe); p++) {
unsigned int gpio = (b<<5) | (p<<3);
bank->cnf[p] = __raw_readl(GPIO_CNF(gpio));
bank->out[p] = __raw_readl(GPIO_OUT(gpio));
bank->oe[p] = __raw_readl(GPIO_OE(gpio));
bank->int_enb[p] = __raw_readl(GPIO_INT_ENB(gpio));
bank->int_lvl[p] = __raw_readl(GPIO_INT_LVL(gpio));
}
}
local_irq_restore(flags);
}
static int tegra_gpio_wake_enable(struct irq_data *d, unsigned int enable)
{
struct tegra_gpio_bank *bank = irq_data_get_irq_chip_data(d);
return irq_set_irq_wake(bank->irq, enable);
}
static int __init tegra_gpio_init(void)
{
struct tegra_gpio_bank *bank;
int i;
int j;
for (i = 0; i < 7; i++) {
for (j = 0; j < 4; j++) {
int gpio = tegra_gpio_compose(i, j, 0);
__raw_writel(0x00, GPIO_INT_ENB(gpio));
}
}
#ifdef CONFIG_OF_GPIO
tegra_gpio_chip.of_node = of_find_compatible_node(NULL, NULL,
"nvidia,tegra20-gpio");
#endif
gpiochip_add(&tegra_gpio_chip);
for (i = INT_GPIO_BASE; i < (INT_GPIO_BASE + TEGRA_NR_GPIOS); i++) {
bank = &tegra_gpio_banks[GPIO_BANK(irq_to_gpio(i))];
irq_set_lockdep_class(i, &gpio_lock_class);
irq_set_chip_data(i, bank);
irq_set_chip_and_handler(i, &tegra_gpio_irq_chip,
handle_simple_irq);
set_irq_flags(i, IRQF_VALID);
}
for (i = 0; i < ARRAY_SIZE(tegra_gpio_banks); i++) {
bank = &tegra_gpio_banks[i];
irq_set_chained_handler(bank->irq, tegra_gpio_irq_handler);
irq_set_handler_data(bank->irq, bank);
for (j = 0; j < 4; j++)
spin_lock_init(&bank->lvl_lock[j]);
}
return 0;
}
void __init tegra_gpio_config(struct tegra_gpio_table *table, int num)
{
int i;
for (i = 0; i < num; i++) {
int gpio = table[i].gpio;
if (table[i].enable)
tegra_gpio_enable(gpio);
else
tegra_gpio_disable(gpio);
}
}
static int dbg_gpio_show(struct seq_file *s, void *unused)
{
int i;
int j;
for (i = 0; i < 7; i++) {
for (j = 0; j < 4; j++) {
int gpio = tegra_gpio_compose(i, j, 0);
seq_printf(s,
"%d:%d %02x %02x %02x %02x %02x %02x %06x\n",
i, j,
__raw_readl(GPIO_CNF(gpio)),
__raw_readl(GPIO_OE(gpio)),
__raw_readl(GPIO_OUT(gpio)),
__raw_readl(GPIO_IN(gpio)),
__raw_readl(GPIO_INT_STA(gpio)),
__raw_readl(GPIO_INT_ENB(gpio)),
__raw_readl(GPIO_INT_LVL(gpio)));
}
}
return 0;
}
static int dbg_gpio_open(struct inode *inode, struct file *file)
{
return single_open(file, dbg_gpio_show, &inode->i_private);
}
static int __init tegra_gpio_debuginit(void)
{
(void) debugfs_create_file("tegra_gpio", S_IRUGO,
NULL, NULL, &debug_fops);
return 0;
}
