static inline struct gpio_bank *get_gpio_bank(int gpio)
{
if (cpu_is_omap15xx()) {
if (OMAP_GPIO_IS_MPUIO(gpio))
return &gpio_bank[0];
return &gpio_bank[1];
}
if (cpu_is_omap16xx()) {
if (OMAP_GPIO_IS_MPUIO(gpio))
return &gpio_bank[0];
return &gpio_bank[1 + (gpio >> 4)];
}
if (cpu_is_omap7xx()) {
if (OMAP_GPIO_IS_MPUIO(gpio))
return &gpio_bank[0];
return &gpio_bank[1 + (gpio >> 5)];
}
if (cpu_is_omap24xx())
return &gpio_bank[gpio >> 5];
if (cpu_is_omap34xx() || cpu_is_omap44xx())
return &gpio_bank[gpio >> 5];
BUG();
return NULL;
}
static inline int get_gpio_index(int gpio)
{
if (cpu_is_omap7xx())
return gpio & 0x1f;
if (cpu_is_omap24xx())
return gpio & 0x1f;
if (cpu_is_omap34xx() || cpu_is_omap44xx())
return gpio & 0x1f;
return gpio & 0x0f;
}
static inline int gpio_valid(int gpio)
{
if (gpio < 0)
return -1;
if (cpu_class_is_omap1() && OMAP_GPIO_IS_MPUIO(gpio)) {
if (gpio >= OMAP_MAX_GPIO_LINES + 16)
return -1;
return 0;
}
if (cpu_is_omap15xx() && gpio < 16)
return 0;
if ((cpu_is_omap16xx()) && gpio < 64)
return 0;
if (cpu_is_omap7xx() && gpio < 192)
return 0;
if (cpu_is_omap2420() && gpio < 128)
return 0;
if (cpu_is_omap2430() && gpio < 160)
return 0;
if ((cpu_is_omap34xx() || cpu_is_omap44xx()) && gpio < 192)
return 0;
return -1;
}
static int check_gpio(int gpio)
{
if (unlikely(gpio_valid(gpio) < 0)) {
printk(KERN_ERR "omap-gpio: invalid GPIO %d\n", gpio);
dump_stack();
return -1;
}
return 0;
}
static void _set_gpio_direction(struct gpio_bank *bank, int gpio, int is_input)
{
void __iomem *reg = bank->base;
u32 l;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP1
case METHOD_MPUIO:
reg += OMAP_MPUIO_IO_CNTL / bank->stride;
break;
#endif
#ifdef CONFIG_ARCH_OMAP15XX
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_DIR_CONTROL;
break;
#endif
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
reg += OMAP1610_GPIO_DIRECTION;
break;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_DIR_CONTROL;
break;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
case METHOD_GPIO_24XX:
reg += OMAP24XX_GPIO_OE;
break;
#endif
#if defined(CONFIG_ARCH_OMAP4)
case METHOD_GPIO_44XX:
reg += OMAP4_GPIO_OE;
break;
#endif
default:
WARN_ON(1);
return;
}
l = __raw_readl(reg);
if (is_input)
l |= 1 << gpio;
else
l &= ~(1 << gpio);
__raw_writel(l, reg);
}
static void _set_gpio_dataout(struct gpio_bank *bank, int gpio, int enable)
{
void __iomem *reg = bank->base;
u32 l = 0;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP1
case METHOD_MPUIO:
reg += OMAP_MPUIO_OUTPUT / bank->stride;
l = __raw_readl(reg);
if (enable)
l |= 1 << gpio;
else
l &= ~(1 << gpio);
break;
#endif
#ifdef CONFIG_ARCH_OMAP15XX
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_DATA_OUTPUT;
l = __raw_readl(reg);
if (enable)
l |= 1 << gpio;
else
l &= ~(1 << gpio);
break;
#endif
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
if (enable)
reg += OMAP1610_GPIO_SET_DATAOUT;
else
reg += OMAP1610_GPIO_CLEAR_DATAOUT;
l = 1 << gpio;
break;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_DATA_OUTPUT;
l = __raw_readl(reg);
if (enable)
l |= 1 << gpio;
else
l &= ~(1 << gpio);
break;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
case METHOD_GPIO_24XX:
if (enable)
reg += OMAP24XX_GPIO_SETDATAOUT;
else
reg += OMAP24XX_GPIO_CLEARDATAOUT;
l = 1 << gpio;
break;
#endif
#ifdef CONFIG_ARCH_OMAP4
case METHOD_GPIO_44XX:
if (enable)
reg += OMAP4_GPIO_SETDATAOUT;
else
reg += OMAP4_GPIO_CLEARDATAOUT;
l = 1 << gpio;
break;
#endif
default:
WARN_ON(1);
return;
}
__raw_writel(l, reg);
}
static int _get_gpio_datain(struct gpio_bank *bank, int gpio)
{
void __iomem *reg;
if (check_gpio(gpio) < 0)
return -EINVAL;
reg = bank->base;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP1
case METHOD_MPUIO:
reg += OMAP_MPUIO_INPUT_LATCH / bank->stride;
break;
#endif
#ifdef CONFIG_ARCH_OMAP15XX
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_DATA_INPUT;
break;
#endif
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
reg += OMAP1610_GPIO_DATAIN;
break;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_DATA_INPUT;
break;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
case METHOD_GPIO_24XX:
reg += OMAP24XX_GPIO_DATAIN;
break;
#endif
#ifdef CONFIG_ARCH_OMAP4
case METHOD_GPIO_44XX:
reg += OMAP4_GPIO_DATAIN;
break;
#endif
default:
return -EINVAL;
}
return (__raw_readl(reg)
& (1 << get_gpio_index(gpio))) != 0;
}
static int _get_gpio_dataout(struct gpio_bank *bank, int gpio)
{
void __iomem *reg;
if (check_gpio(gpio) < 0)
return -EINVAL;
reg = bank->base;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP1
case METHOD_MPUIO:
reg += OMAP_MPUIO_OUTPUT / bank->stride;
break;
#endif
#ifdef CONFIG_ARCH_OMAP15XX
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_DATA_OUTPUT;
break;
#endif
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
reg += OMAP1610_GPIO_DATAOUT;
break;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_DATA_OUTPUT;
break;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
case METHOD_GPIO_24XX:
reg += OMAP24XX_GPIO_DATAOUT;
break;
#endif
#ifdef CONFIG_ARCH_OMAP4
case METHOD_GPIO_44XX:
reg += OMAP4_GPIO_DATAOUT;
break;
#endif
default:
return -EINVAL;
}
return (__raw_readl(reg) & (1 << get_gpio_index(gpio))) != 0;
}
static void _set_gpio_debounce(struct gpio_bank *bank, unsigned gpio,
unsigned debounce)
{
void __iomem *reg = bank->base;
u32 val;
u32 l;
if (!bank->dbck_flag)
return;
if (debounce < 32)
debounce = 0x01;
else if (debounce > 7936)
debounce = 0xff;
else
debounce = (debounce / 0x1f) - 1;
l = 1 << get_gpio_index(gpio);
if (bank->method == METHOD_GPIO_44XX)
reg += OMAP4_GPIO_DEBOUNCINGTIME;
else
reg += OMAP24XX_GPIO_DEBOUNCE_VAL;
__raw_writel(debounce, reg);
reg = bank->base;
if (bank->method == METHOD_GPIO_44XX)
reg += OMAP4_GPIO_DEBOUNCENABLE;
else
reg += OMAP24XX_GPIO_DEBOUNCE_EN;
val = __raw_readl(reg);
if (debounce) {
val |= l;
clk_enable(bank->dbck);
} else {
val &= ~l;
clk_disable(bank->dbck);
}
bank->dbck_enable_mask = val;
__raw_writel(val, reg);
}
static inline void set_24xx_gpio_triggering(struct gpio_bank *bank, int gpio,
int trigger)
{
void __iomem *base = bank->base;
u32 gpio_bit = 1 << gpio;
if (cpu_is_omap44xx()) {
MOD_REG_BIT(OMAP4_GPIO_LEVELDETECT0, gpio_bit,
trigger & IRQ_TYPE_LEVEL_LOW);
MOD_REG_BIT(OMAP4_GPIO_LEVELDETECT1, gpio_bit,
trigger & IRQ_TYPE_LEVEL_HIGH);
MOD_REG_BIT(OMAP4_GPIO_RISINGDETECT, gpio_bit,
trigger & IRQ_TYPE_EDGE_RISING);
MOD_REG_BIT(OMAP4_GPIO_FALLINGDETECT, gpio_bit,
trigger & IRQ_TYPE_EDGE_FALLING);
} else {
MOD_REG_BIT(OMAP24XX_GPIO_LEVELDETECT0, gpio_bit,
trigger & IRQ_TYPE_LEVEL_LOW);
MOD_REG_BIT(OMAP24XX_GPIO_LEVELDETECT1, gpio_bit,
trigger & IRQ_TYPE_LEVEL_HIGH);
MOD_REG_BIT(OMAP24XX_GPIO_RISINGDETECT, gpio_bit,
trigger & IRQ_TYPE_EDGE_RISING);
MOD_REG_BIT(OMAP24XX_GPIO_FALLINGDETECT, gpio_bit,
trigger & IRQ_TYPE_EDGE_FALLING);
}
if (likely(!(bank->non_wakeup_gpios & gpio_bit))) {
if (cpu_is_omap44xx()) {
MOD_REG_BIT(OMAP4_GPIO_IRQWAKEN0, gpio_bit,
trigger != 0);
} else {
if (trigger & IRQ_TYPE_EDGE_BOTH)
__raw_writel(1 << gpio, bank->base
+ OMAP24XX_GPIO_SETWKUENA);
else
__raw_writel(1 << gpio, bank->base
+ OMAP24XX_GPIO_CLEARWKUENA);
}
}
if (cpu_is_omap34xx() || cpu_is_omap44xx() ||
(bank->non_wakeup_gpios & gpio_bit)) {
if (trigger & IRQ_TYPE_EDGE_BOTH)
bank->enabled_non_wakeup_gpios |= gpio_bit;
else
bank->enabled_non_wakeup_gpios &= ~gpio_bit;
}
if (cpu_is_omap44xx()) {
bank->level_mask =
__raw_readl(bank->base + OMAP4_GPIO_LEVELDETECT0) |
__raw_readl(bank->base + OMAP4_GPIO_LEVELDETECT1);
} else {
bank->level_mask =
__raw_readl(bank->base + OMAP24XX_GPIO_LEVELDETECT0) |
__raw_readl(bank->base + OMAP24XX_GPIO_LEVELDETECT1);
}
}
static void _toggle_gpio_edge_triggering(struct gpio_bank *bank, int gpio)
{
void __iomem *reg = bank->base;
u32 l = 0;
switch (bank->method) {
case METHOD_MPUIO:
reg += OMAP_MPUIO_GPIO_INT_EDGE / bank->stride;
break;
#ifdef CONFIG_ARCH_OMAP15XX
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_INT_CONTROL;
break;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_INT_CONTROL;
break;
#endif
default:
return;
}
l = __raw_readl(reg);
if ((l >> gpio) & 1)
l &= ~(1 << gpio);
else
l |= 1 << gpio;
__raw_writel(l, reg);
}
static int _set_gpio_triggering(struct gpio_bank *bank, int gpio, int trigger)
{
void __iomem *reg = bank->base;
u32 l = 0;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP1
case METHOD_MPUIO:
reg += OMAP_MPUIO_GPIO_INT_EDGE / bank->stride;
l = __raw_readl(reg);
if ((trigger & IRQ_TYPE_SENSE_MASK) == IRQ_TYPE_EDGE_BOTH)
bank->toggle_mask |= 1 << gpio;
if (trigger & IRQ_TYPE_EDGE_RISING)
l |= 1 << gpio;
else if (trigger & IRQ_TYPE_EDGE_FALLING)
l &= ~(1 << gpio);
else
goto bad;
break;
#endif
#ifdef CONFIG_ARCH_OMAP15XX
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_INT_CONTROL;
l = __raw_readl(reg);
if ((trigger & IRQ_TYPE_SENSE_MASK) == IRQ_TYPE_EDGE_BOTH)
bank->toggle_mask |= 1 << gpio;
if (trigger & IRQ_TYPE_EDGE_RISING)
l |= 1 << gpio;
else if (trigger & IRQ_TYPE_EDGE_FALLING)
l &= ~(1 << gpio);
else
goto bad;
break;
#endif
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
if (gpio & 0x08)
reg += OMAP1610_GPIO_EDGE_CTRL2;
else
reg += OMAP1610_GPIO_EDGE_CTRL1;
gpio &= 0x07;
l = __raw_readl(reg);
l &= ~(3 << (gpio << 1));
if (trigger & IRQ_TYPE_EDGE_RISING)
l |= 2 << (gpio << 1);
if (trigger & IRQ_TYPE_EDGE_FALLING)
l |= 1 << (gpio << 1);
if (trigger)
__raw_writel(1 << gpio, bank->base + OMAP1610_GPIO_SET_WAKEUPENA);
else
__raw_writel(1 << gpio, bank->base + OMAP1610_GPIO_CLEAR_WAKEUPENA);
break;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_INT_CONTROL;
l = __raw_readl(reg);
if ((trigger & IRQ_TYPE_SENSE_MASK) == IRQ_TYPE_EDGE_BOTH)
bank->toggle_mask |= 1 << gpio;
if (trigger & IRQ_TYPE_EDGE_RISING)
l |= 1 << gpio;
else if (trigger & IRQ_TYPE_EDGE_FALLING)
l &= ~(1 << gpio);
else
goto bad;
break;
#endif
#ifdef CONFIG_ARCH_OMAP2PLUS
case METHOD_GPIO_24XX:
case METHOD_GPIO_44XX:
set_24xx_gpio_triggering(bank, gpio, trigger);
return 0;
#endif
default:
goto bad;
}
__raw_writel(l, reg);
return 0;
bad:
return -EINVAL;
}
static int gpio_irq_type(struct irq_data *d, unsigned type)
{
struct gpio_bank *bank;
unsigned gpio;
int retval;
unsigned long flags;
if (!cpu_class_is_omap2() && d->irq > IH_MPUIO_BASE)
gpio = OMAP_MPUIO(d->irq - IH_MPUIO_BASE);
else
gpio = d->irq - IH_GPIO_BASE;
if (check_gpio(gpio) < 0)
return -EINVAL;
if (type & ~IRQ_TYPE_SENSE_MASK)
return -EINVAL;
if (!cpu_class_is_omap2()
&& (type & (IRQ_TYPE_LEVEL_LOW|IRQ_TYPE_LEVEL_HIGH)))
return -EINVAL;
bank = irq_data_get_irq_chip_data(d);
spin_lock_irqsave(&bank->lock, flags);
retval = _set_gpio_triggering(bank, get_gpio_index(gpio), type);
spin_unlock_irqrestore(&bank->lock, flags);
if (type & (IRQ_TYPE_LEVEL_LOW | IRQ_TYPE_LEVEL_HIGH))
__irq_set_handler_locked(d->irq, handle_level_irq);
else if (type & (IRQ_TYPE_EDGE_FALLING | IRQ_TYPE_EDGE_RISING))
__irq_set_handler_locked(d->irq, handle_edge_irq);
return retval;
}
static void _clear_gpio_irqbank(struct gpio_bank *bank, int gpio_mask)
{
void __iomem *reg = bank->base;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP1
case METHOD_MPUIO:
return;
#endif
#ifdef CONFIG_ARCH_OMAP15XX
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_INT_STATUS;
break;
#endif
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
reg += OMAP1610_GPIO_IRQSTATUS1;
break;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_INT_STATUS;
break;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
case METHOD_GPIO_24XX:
reg += OMAP24XX_GPIO_IRQSTATUS1;
break;
#endif
#if defined(CONFIG_ARCH_OMAP4)
case METHOD_GPIO_44XX:
reg += OMAP4_GPIO_IRQSTATUS0;
break;
#endif
default:
WARN_ON(1);
return;
}
__raw_writel(gpio_mask, reg);
if (cpu_is_omap24xx() || cpu_is_omap34xx())
reg = bank->base + OMAP24XX_GPIO_IRQSTATUS2;
else if (cpu_is_omap44xx())
reg = bank->base + OMAP4_GPIO_IRQSTATUS1;
if (cpu_is_omap24xx() || cpu_is_omap34xx() || cpu_is_omap44xx()) {
__raw_writel(gpio_mask, reg);
__raw_readl(reg);
}
}
static inline void _clear_gpio_irqstatus(struct gpio_bank *bank, int gpio)
{
_clear_gpio_irqbank(bank, 1 << get_gpio_index(gpio));
}
static u32 _get_gpio_irqbank_mask(struct gpio_bank *bank)
{
void __iomem *reg = bank->base;
int inv = 0;
u32 l;
u32 mask;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP1
case METHOD_MPUIO:
reg += OMAP_MPUIO_GPIO_MASKIT / bank->stride;
mask = 0xffff;
inv = 1;
break;
#endif
#ifdef CONFIG_ARCH_OMAP15XX
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_INT_MASK;
mask = 0xffff;
inv = 1;
break;
#endif
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
reg += OMAP1610_GPIO_IRQENABLE1;
mask = 0xffff;
break;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_INT_MASK;
mask = 0xffffffff;
inv = 1;
break;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
case METHOD_GPIO_24XX:
reg += OMAP24XX_GPIO_IRQENABLE1;
mask = 0xffffffff;
break;
#endif
#if defined(CONFIG_ARCH_OMAP4)
case METHOD_GPIO_44XX:
reg += OMAP4_GPIO_IRQSTATUSSET0;
mask = 0xffffffff;
break;
#endif
default:
WARN_ON(1);
return 0;
}
l = __raw_readl(reg);
if (inv)
l = ~l;
l &= mask;
return l;
}
static void _enable_gpio_irqbank(struct gpio_bank *bank, int gpio_mask, int enable)
{
void __iomem *reg = bank->base;
u32 l;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP1
case METHOD_MPUIO:
reg += OMAP_MPUIO_GPIO_MASKIT / bank->stride;
l = __raw_readl(reg);
if (enable)
l &= ~(gpio_mask);
else
l |= gpio_mask;
break;
#endif
#ifdef CONFIG_ARCH_OMAP15XX
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_INT_MASK;
l = __raw_readl(reg);
if (enable)
l &= ~(gpio_mask);
else
l |= gpio_mask;
break;
#endif
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
if (enable)
reg += OMAP1610_GPIO_SET_IRQENABLE1;
else
reg += OMAP1610_GPIO_CLEAR_IRQENABLE1;
l = gpio_mask;
break;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_INT_MASK;
l = __raw_readl(reg);
if (enable)
l &= ~(gpio_mask);
else
l |= gpio_mask;
break;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
case METHOD_GPIO_24XX:
if (enable)
reg += OMAP24XX_GPIO_SETIRQENABLE1;
else
reg += OMAP24XX_GPIO_CLEARIRQENABLE1;
l = gpio_mask;
break;
#endif
#ifdef CONFIG_ARCH_OMAP4
case METHOD_GPIO_44XX:
if (enable)
reg += OMAP4_GPIO_IRQSTATUSSET0;
else
reg += OMAP4_GPIO_IRQSTATUSCLR0;
l = gpio_mask;
break;
#endif
default:
WARN_ON(1);
return;
}
__raw_writel(l, reg);
}
static inline void _set_gpio_irqenable(struct gpio_bank *bank, int gpio, int enable)
{
_enable_gpio_irqbank(bank, 1 << get_gpio_index(gpio), enable);
}
static int _set_gpio_wakeup(struct gpio_bank *bank, int gpio, int enable)
{
unsigned long uninitialized_var(flags);
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_MPUIO:
case METHOD_GPIO_1610:
spin_lock_irqsave(&bank->lock, flags);
if (enable)
bank->suspend_wakeup |= (1 << gpio);
else
bank->suspend_wakeup &= ~(1 << gpio);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
#endif
#ifdef CONFIG_ARCH_OMAP2PLUS
case METHOD_GPIO_24XX:
case METHOD_GPIO_44XX:
if (bank->non_wakeup_gpios & (1 << gpio)) {
printk(KERN_ERR "Unable to modify wakeup on "
"non-wakeup GPIO%d\n",
(bank - gpio_bank) * 32 + gpio);
return -EINVAL;
}
spin_lock_irqsave(&bank->lock, flags);
if (enable)
bank->suspend_wakeup |= (1 << gpio);
else
bank->suspend_wakeup &= ~(1 << gpio);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
#endif
default:
printk(KERN_ERR "Can't enable GPIO wakeup for method %i\n",
bank->method);
return -EINVAL;
}
}
static void _reset_gpio(struct gpio_bank *bank, int gpio)
{
_set_gpio_direction(bank, get_gpio_index(gpio), 1);
_set_gpio_irqenable(bank, gpio, 0);
_clear_gpio_irqstatus(bank, gpio);
_set_gpio_triggering(bank, get_gpio_index(gpio), IRQ_TYPE_NONE);
}
static int gpio_wake_enable(struct irq_data *d, unsigned int enable)
{
unsigned int gpio = d->irq - IH_GPIO_BASE;
struct gpio_bank *bank;
int retval;
if (check_gpio(gpio) < 0)
return -ENODEV;
bank = irq_data_get_irq_chip_data(d);
retval = _set_gpio_wakeup(bank, get_gpio_index(gpio), enable);
return retval;
}
static int omap_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct gpio_bank *bank = container_of(chip, struct gpio_bank, chip);
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
_set_gpio_triggering(bank, offset, IRQ_TYPE_NONE);
#ifdef CONFIG_ARCH_OMAP15XX
if (bank->method == METHOD_GPIO_1510) {
void __iomem *reg;
reg = bank->base + OMAP1510_GPIO_PIN_CONTROL;
__raw_writel(__raw_readl(reg) | (1 << offset), reg);
}
#endif
if (!cpu_class_is_omap1()) {
if (!bank->mod_usage) {
void __iomem *reg = bank->base;
u32 ctrl;
if (cpu_is_omap24xx() || cpu_is_omap34xx())
reg += OMAP24XX_GPIO_CTRL;
else if (cpu_is_omap44xx())
reg += OMAP4_GPIO_CTRL;
ctrl = __raw_readl(reg);
ctrl &= 0xFFFFFFFE;
__raw_writel(ctrl, reg);
}
bank->mod_usage |= 1 << offset;
}
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static void omap_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct gpio_bank *bank = container_of(chip, struct gpio_bank, chip);
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
#ifdef CONFIG_ARCH_OMAP16XX
if (bank->method == METHOD_GPIO_1610) {
void __iomem *reg = bank->base + OMAP1610_GPIO_CLEAR_WAKEUPENA;
__raw_writel(1 << offset, reg);
}
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
if (bank->method == METHOD_GPIO_24XX) {
void __iomem *reg = bank->base + OMAP24XX_GPIO_CLEARWKUENA;
__raw_writel(1 << offset, reg);
}
#endif
#ifdef CONFIG_ARCH_OMAP4
if (bank->method == METHOD_GPIO_44XX) {
void __iomem *reg = bank->base + OMAP4_GPIO_IRQWAKEN0;
__raw_writel(1 << offset, reg);
}
#endif
if (!cpu_class_is_omap1()) {
bank->mod_usage &= ~(1 << offset);
if (!bank->mod_usage) {
void __iomem *reg = bank->base;
u32 ctrl;
if (cpu_is_omap24xx() || cpu_is_omap34xx())
reg += OMAP24XX_GPIO_CTRL;
else if (cpu_is_omap44xx())
reg += OMAP4_GPIO_CTRL;
ctrl = __raw_readl(reg);
ctrl |= 1;
__raw_writel(ctrl, reg);
}
}
_reset_gpio(bank, bank->chip.base + offset);
spin_unlock_irqrestore(&bank->lock, flags);
}
static void gpio_irq_handler(unsigned int irq, struct irq_desc *desc)
{
void __iomem *isr_reg = NULL;
u32 isr;
unsigned int gpio_irq, gpio_index;
struct gpio_bank *bank;
u32 retrigger = 0;
int unmasked = 0;
struct irq_chip *chip = irq_desc_get_chip(desc);
chained_irq_enter(chip, desc);
bank = irq_get_handler_data(irq);
#ifdef CONFIG_ARCH_OMAP1
if (bank->method == METHOD_MPUIO)
isr_reg = bank->base +
OMAP_MPUIO_GPIO_INT / bank->stride;
#endif
#ifdef CONFIG_ARCH_OMAP15XX
if (bank->method == METHOD_GPIO_1510)
isr_reg = bank->base + OMAP1510_GPIO_INT_STATUS;
#endif
#if defined(CONFIG_ARCH_OMAP16XX)
if (bank->method == METHOD_GPIO_1610)
isr_reg = bank->base + OMAP1610_GPIO_IRQSTATUS1;
#endif
#if defined(CONFIG_ARCH_OMAP730) || defined(CONFIG_ARCH_OMAP850)
if (bank->method == METHOD_GPIO_7XX)
isr_reg = bank->base + OMAP7XX_GPIO_INT_STATUS;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
if (bank->method == METHOD_GPIO_24XX)
isr_reg = bank->base + OMAP24XX_GPIO_IRQSTATUS1;
#endif
#if defined(CONFIG_ARCH_OMAP4)
if (bank->method == METHOD_GPIO_44XX)
isr_reg = bank->base + OMAP4_GPIO_IRQSTATUS0;
#endif
if (WARN_ON(!isr_reg))
goto exit;
while(1) {
u32 isr_saved, level_mask = 0;
u32 enabled;
enabled = _get_gpio_irqbank_mask(bank);
isr_saved = isr = __raw_readl(isr_reg) & enabled;
if (cpu_is_omap15xx() && (bank->method == METHOD_MPUIO))
isr &= 0x0000ffff;
if (cpu_class_is_omap2()) {
level_mask = bank->level_mask & enabled;
}
_enable_gpio_irqbank(bank, isr_saved & ~level_mask, 0);
_clear_gpio_irqbank(bank, isr_saved & ~level_mask);
_enable_gpio_irqbank(bank, isr_saved & ~level_mask, 1);
if (!level_mask && !unmasked) {
unmasked = 1;
chained_irq_exit(chip, desc);
}
isr |= retrigger;
retrigger = 0;
if (!isr)
break;
gpio_irq = bank->virtual_irq_start;
for (; isr != 0; isr >>= 1, gpio_irq++) {
gpio_index = get_gpio_index(irq_to_gpio(gpio_irq));
if (!(isr & 1))
continue;
#ifdef CONFIG_ARCH_OMAP1
if (bank->toggle_mask & (1 << gpio_index))
_toggle_gpio_edge_triggering(bank, gpio_index);
#endif
generic_handle_irq(gpio_irq);
}
}
exit:
if (!unmasked)
chained_irq_exit(chip, desc);
}
static void gpio_irq_shutdown(struct irq_data *d)
{
unsigned int gpio = d->irq - IH_GPIO_BASE;
struct gpio_bank *bank = irq_data_get_irq_chip_data(d);
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
_reset_gpio(bank, gpio);
spin_unlock_irqrestore(&bank->lock, flags);
}
static void gpio_ack_irq(struct irq_data *d)
{
unsigned int gpio = d->irq - IH_GPIO_BASE;
struct gpio_bank *bank = irq_data_get_irq_chip_data(d);
_clear_gpio_irqstatus(bank, gpio);
}
static void gpio_mask_irq(struct irq_data *d)
{
unsigned int gpio = d->irq - IH_GPIO_BASE;
struct gpio_bank *bank = irq_data_get_irq_chip_data(d);
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
_set_gpio_irqenable(bank, gpio, 0);
_set_gpio_triggering(bank, get_gpio_index(gpio), IRQ_TYPE_NONE);
spin_unlock_irqrestore(&bank->lock, flags);
}
static void gpio_unmask_irq(struct irq_data *d)
{
unsigned int gpio = d->irq - IH_GPIO_BASE;
struct gpio_bank *bank = irq_data_get_irq_chip_data(d);
unsigned int irq_mask = 1 << get_gpio_index(gpio);
u32 trigger = irqd_get_trigger_type(d);
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
if (trigger)
_set_gpio_triggering(bank, get_gpio_index(gpio), trigger);
if (bank->level_mask & irq_mask) {
_set_gpio_irqenable(bank, gpio, 0);
_clear_gpio_irqstatus(bank, gpio);
}
_set_gpio_irqenable(bank, gpio, 1);
spin_unlock_irqrestore(&bank->lock, flags);
}
static void mpuio_ack_irq(struct irq_data *d)
{
}
static void mpuio_mask_irq(struct irq_data *d)
{
unsigned int gpio = OMAP_MPUIO(d->irq - IH_MPUIO_BASE);
struct gpio_bank *bank = irq_data_get_irq_chip_data(d);
_set_gpio_irqenable(bank, gpio, 0);
}
static void mpuio_unmask_irq(struct irq_data *d)
{
unsigned int gpio = OMAP_MPUIO(d->irq - IH_MPUIO_BASE);
struct gpio_bank *bank = irq_data_get_irq_chip_data(d);
_set_gpio_irqenable(bank, gpio, 1);
}
static int omap_mpuio_suspend_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct gpio_bank *bank = platform_get_drvdata(pdev);
void __iomem *mask_reg = bank->base +
OMAP_MPUIO_GPIO_MASKIT / bank->stride;
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
bank->saved_wakeup = __raw_readl(mask_reg);
__raw_writel(0xffff & ~bank->suspend_wakeup, mask_reg);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static int omap_mpuio_resume_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct gpio_bank *bank = platform_get_drvdata(pdev);
void __iomem *mask_reg = bank->base +
OMAP_MPUIO_GPIO_MASKIT / bank->stride;
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
__raw_writel(bank->saved_wakeup, mask_reg);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static inline void mpuio_init(void)
{
struct gpio_bank *bank = get_gpio_bank(OMAP_MPUIO(0));
platform_set_drvdata(&omap_mpuio_device, bank);
if (platform_driver_register(&omap_mpuio_driver) == 0)
(void) platform_device_register(&omap_mpuio_device);
}
static inline void mpuio_init(void) {}
static inline void mpuio_init(void) {}
static int gpio_input(struct gpio_chip *chip, unsigned offset)
{
struct gpio_bank *bank;
unsigned long flags;
bank = container_of(chip, struct gpio_bank, chip);
spin_lock_irqsave(&bank->lock, flags);
_set_gpio_direction(bank, offset, 1);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static int gpio_is_input(struct gpio_bank *bank, int mask)
{
void __iomem *reg = bank->base;
switch (bank->method) {
case METHOD_MPUIO:
reg += OMAP_MPUIO_IO_CNTL / bank->stride;
break;
case METHOD_GPIO_1510:
reg += OMAP1510_GPIO_DIR_CONTROL;
break;
case METHOD_GPIO_1610:
reg += OMAP1610_GPIO_DIRECTION;
break;
case METHOD_GPIO_7XX:
reg += OMAP7XX_GPIO_DIR_CONTROL;
break;
case METHOD_GPIO_24XX:
reg += OMAP24XX_GPIO_OE;
break;
case METHOD_GPIO_44XX:
reg += OMAP4_GPIO_OE;
break;
default:
WARN_ONCE(1, "gpio_is_input: incorrect OMAP GPIO method");
return -EINVAL;
}
return __raw_readl(reg) & mask;
}
static int gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct gpio_bank *bank;
void __iomem *reg;
int gpio;
u32 mask;
gpio = chip->base + offset;
bank = get_gpio_bank(gpio);
reg = bank->base;
mask = 1 << get_gpio_index(gpio);
if (gpio_is_input(bank, mask))
return _get_gpio_datain(bank, gpio);
else
return _get_gpio_dataout(bank, gpio);
}
static int gpio_output(struct gpio_chip *chip, unsigned offset, int value)
{
struct gpio_bank *bank;
unsigned long flags;
bank = container_of(chip, struct gpio_bank, chip);
spin_lock_irqsave(&bank->lock, flags);
_set_gpio_dataout(bank, offset, value);
_set_gpio_direction(bank, offset, 0);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static int gpio_debounce(struct gpio_chip *chip, unsigned offset,
unsigned debounce)
{
struct gpio_bank *bank;
unsigned long flags;
bank = container_of(chip, struct gpio_bank, chip);
if (!bank->dbck) {
bank->dbck = clk_get(bank->dev, "dbclk");
if (IS_ERR(bank->dbck))
dev_err(bank->dev, "Could not get gpio dbck\n");
}
spin_lock_irqsave(&bank->lock, flags);
_set_gpio_debounce(bank, offset, debounce);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static void gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct gpio_bank *bank;
unsigned long flags;
bank = container_of(chip, struct gpio_bank, chip);
spin_lock_irqsave(&bank->lock, flags);
_set_gpio_dataout(bank, offset, value);
spin_unlock_irqrestore(&bank->lock, flags);
}
static int gpio_2irq(struct gpio_chip *chip, unsigned offset)
{
struct gpio_bank *bank;
bank = container_of(chip, struct gpio_bank, chip);
return bank->virtual_irq_start + offset;
}
static void __init omap_gpio_show_rev(struct gpio_bank *bank)
{
u32 rev;
if (cpu_is_omap16xx() && !(bank->method != METHOD_MPUIO))
rev = __raw_readw(bank->base + OMAP1610_GPIO_REVISION);
else if (cpu_is_omap24xx() || cpu_is_omap34xx())
rev = __raw_readl(bank->base + OMAP24XX_GPIO_REVISION);
else if (cpu_is_omap44xx())
rev = __raw_readl(bank->base + OMAP4_GPIO_REVISION);
else
return;
printk(KERN_INFO "OMAP GPIO hardware version %d.%d\n",
(rev >> 4) & 0x0f, rev & 0x0f);
}
static inline int init_gpio_info(struct platform_device *pdev)
{
gpio_bank = kzalloc(gpio_bank_count * sizeof(struct gpio_bank),
GFP_KERNEL);
if (!gpio_bank) {
dev_err(&pdev->dev, "Memory alloc failed for gpio_bank\n");
return -ENOMEM;
}
return 0;
}
static void omap_gpio_mod_init(struct gpio_bank *bank, int id)
{
if (cpu_class_is_omap2()) {
if (cpu_is_omap44xx()) {
__raw_writel(0xffffffff, bank->base +
OMAP4_GPIO_IRQSTATUSCLR0);
__raw_writel(0x00000000, bank->base +
OMAP4_GPIO_DEBOUNCENABLE);
__raw_writel(0, bank->base + OMAP4_GPIO_CTRL);
} else if (cpu_is_omap34xx()) {
__raw_writel(0x00000000, bank->base +
OMAP24XX_GPIO_IRQENABLE1);
__raw_writel(0xffffffff, bank->base +
OMAP24XX_GPIO_IRQSTATUS1);
__raw_writel(0x00000000, bank->base +
OMAP24XX_GPIO_DEBOUNCE_EN);
__raw_writel(0, bank->base + OMAP24XX_GPIO_CTRL);
} else if (cpu_is_omap24xx()) {
static const u32 non_wakeup_gpios[] = {
0xe203ffc0, 0x08700040
};
if (id < ARRAY_SIZE(non_wakeup_gpios))
bank->non_wakeup_gpios = non_wakeup_gpios[id];
}
} else if (cpu_class_is_omap1()) {
if (bank_is_mpuio(bank))
__raw_writew(0xffff, bank->base +
OMAP_MPUIO_GPIO_MASKIT / bank->stride);
if (cpu_is_omap15xx() && bank->method == METHOD_GPIO_1510) {
__raw_writew(0xffff, bank->base
+ OMAP1510_GPIO_INT_MASK);
__raw_writew(0x0000, bank->base
+ OMAP1510_GPIO_INT_STATUS);
}
if (cpu_is_omap16xx() && bank->method == METHOD_GPIO_1610) {
__raw_writew(0x0000, bank->base
+ OMAP1610_GPIO_IRQENABLE1);
__raw_writew(0xffff, bank->base
+ OMAP1610_GPIO_IRQSTATUS1);
__raw_writew(0x0014, bank->base
+ OMAP1610_GPIO_SYSCONFIG);
omap_writel(omap_readl(ULPD_CAM_CLK_CTRL) | 0x04,
ULPD_CAM_CLK_CTRL);
}
if (cpu_is_omap7xx() && bank->method == METHOD_GPIO_7XX) {
__raw_writel(0xffffffff, bank->base
+ OMAP7XX_GPIO_INT_MASK);
__raw_writel(0x00000000, bank->base
+ OMAP7XX_GPIO_INT_STATUS);
}
}
}
static void __devinit omap_gpio_chip_init(struct gpio_bank *bank)
{
int j;
static int gpio;
bank->mod_usage = 0;
bank->chip.request = omap_gpio_request;
bank->chip.free = omap_gpio_free;
bank->chip.direction_input = gpio_input;
bank->chip.get = gpio_get;
bank->chip.direction_output = gpio_output;
bank->chip.set_debounce = gpio_debounce;
bank->chip.set = gpio_set;
bank->chip.to_irq = gpio_2irq;
if (bank_is_mpuio(bank)) {
bank->chip.label = "mpuio";
#ifdef CONFIG_ARCH_OMAP16XX
bank->chip.dev = &omap_mpuio_device.dev;
#endif
bank->chip.base = OMAP_MPUIO(0);
} else {
bank->chip.label = "gpio";
bank->chip.base = gpio;
gpio += bank_width;
}
bank->chip.ngpio = bank_width;
gpiochip_add(&bank->chip);
for (j = bank->virtual_irq_start;
j < bank->virtual_irq_start + bank_width; j++) {
irq_set_lockdep_class(j, &gpio_lock_class);
irq_set_chip_data(j, bank);
if (bank_is_mpuio(bank))
irq_set_chip(j, &mpuio_irq_chip);
else
irq_set_chip(j, &gpio_irq_chip);
irq_set_handler(j, handle_simple_irq);
set_irq_flags(j, IRQF_VALID);
}
irq_set_chained_handler(bank->irq, gpio_irq_handler);
irq_set_handler_data(bank->irq, bank);
}
static int __devinit omap_gpio_probe(struct platform_device *pdev)
{
static int gpio_init_done;
struct omap_gpio_platform_data *pdata;
struct resource *res;
int id;
struct gpio_bank *bank;
if (!pdev->dev.platform_data)
return -EINVAL;
pdata = pdev->dev.platform_data;
if (!gpio_init_done) {
int ret;
ret = init_gpio_info(pdev);
if (ret)
return ret;
}
id = pdev->id;
bank = &gpio_bank[id];
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (unlikely(!res)) {
dev_err(&pdev->dev, "GPIO Bank %i Invalid IRQ resource\n", id);
return -ENODEV;
}
bank->irq = res->start;
bank->virtual_irq_start = pdata->virtual_irq_start;
bank->method = pdata->bank_type;
bank->dev = &pdev->dev;
bank->dbck_flag = pdata->dbck_flag;
bank->stride = pdata->bank_stride;
bank_width = pdata->bank_width;
spin_lock_init(&bank->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (unlikely(!res)) {
dev_err(&pdev->dev, "GPIO Bank %i Invalid mem resource\n", id);
return -ENODEV;
}
bank->base = ioremap(res->start, resource_size(res));
if (!bank->base) {
dev_err(&pdev->dev, "Could not ioremap gpio bank%i\n", id);
return -ENOMEM;
}
pm_runtime_enable(bank->dev);
pm_runtime_get_sync(bank->dev);
omap_gpio_mod_init(bank, id);
omap_gpio_chip_init(bank);
omap_gpio_show_rev(bank);
if (!gpio_init_done)
gpio_init_done = 1;
return 0;
}
static int omap_gpio_suspend(void)
{
int i;
if (!cpu_class_is_omap2() && !cpu_is_omap16xx())
return 0;
for (i = 0; i < gpio_bank_count; i++) {
struct gpio_bank *bank = &gpio_bank[i];
void __iomem *wake_status;
void __iomem *wake_clear;
void __iomem *wake_set;
unsigned long flags;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
wake_status = bank->base + OMAP1610_GPIO_WAKEUPENABLE;
wake_clear = bank->base + OMAP1610_GPIO_CLEAR_WAKEUPENA;
wake_set = bank->base + OMAP1610_GPIO_SET_WAKEUPENA;
break;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
case METHOD_GPIO_24XX:
wake_status = bank->base + OMAP24XX_GPIO_WAKE_EN;
wake_clear = bank->base + OMAP24XX_GPIO_CLEARWKUENA;
wake_set = bank->base + OMAP24XX_GPIO_SETWKUENA;
break;
#endif
#ifdef CONFIG_ARCH_OMAP4
case METHOD_GPIO_44XX:
wake_status = bank->base + OMAP4_GPIO_IRQWAKEN0;
wake_clear = bank->base + OMAP4_GPIO_IRQWAKEN0;
wake_set = bank->base + OMAP4_GPIO_IRQWAKEN0;
break;
#endif
default:
continue;
}
spin_lock_irqsave(&bank->lock, flags);
bank->saved_wakeup = __raw_readl(wake_status);
__raw_writel(0xffffffff, wake_clear);
__raw_writel(bank->suspend_wakeup, wake_set);
spin_unlock_irqrestore(&bank->lock, flags);
}
return 0;
}
static void omap_gpio_resume(void)
{
int i;
if (!cpu_class_is_omap2() && !cpu_is_omap16xx())
return;
for (i = 0; i < gpio_bank_count; i++) {
struct gpio_bank *bank = &gpio_bank[i];
void __iomem *wake_clear;
void __iomem *wake_set;
unsigned long flags;
switch (bank->method) {
#ifdef CONFIG_ARCH_OMAP16XX
case METHOD_GPIO_1610:
wake_clear = bank->base + OMAP1610_GPIO_CLEAR_WAKEUPENA;
wake_set = bank->base + OMAP1610_GPIO_SET_WAKEUPENA;
break;
#endif
#if defined(CONFIG_ARCH_OMAP2) || defined(CONFIG_ARCH_OMAP3)
case METHOD_GPIO_24XX:
wake_clear = bank->base + OMAP24XX_GPIO_CLEARWKUENA;
wake_set = bank->base + OMAP24XX_GPIO_SETWKUENA;
break;
#endif
#ifdef CONFIG_ARCH_OMAP4
case METHOD_GPIO_44XX:
wake_clear = bank->base + OMAP4_GPIO_IRQWAKEN0;
wake_set = bank->base + OMAP4_GPIO_IRQWAKEN0;
break;
#endif
default:
continue;
}
spin_lock_irqsave(&bank->lock, flags);
__raw_writel(0xffffffff, wake_clear);
__raw_writel(bank->saved_wakeup, wake_set);
spin_unlock_irqrestore(&bank->lock, flags);
}
}
void omap2_gpio_prepare_for_idle(int off_mode)
{
int i, c = 0;
int min = 0;
if (cpu_is_omap34xx())
min = 1;
for (i = min; i < gpio_bank_count; i++) {
struct gpio_bank *bank = &gpio_bank[i];
u32 l1 = 0, l2 = 0;
int j;
for (j = 0; j < hweight_long(bank->dbck_enable_mask); j++)
clk_disable(bank->dbck);
if (!off_mode)
continue;
if (!(bank->enabled_non_wakeup_gpios))
continue;
if (cpu_is_omap24xx() || cpu_is_omap34xx()) {
bank->saved_datain = __raw_readl(bank->base +
OMAP24XX_GPIO_DATAIN);
l1 = __raw_readl(bank->base +
OMAP24XX_GPIO_FALLINGDETECT);
l2 = __raw_readl(bank->base +
OMAP24XX_GPIO_RISINGDETECT);
}
if (cpu_is_omap44xx()) {
bank->saved_datain = __raw_readl(bank->base +
OMAP4_GPIO_DATAIN);
l1 = __raw_readl(bank->base +
OMAP4_GPIO_FALLINGDETECT);
l2 = __raw_readl(bank->base +
OMAP4_GPIO_RISINGDETECT);
}
bank->saved_fallingdetect = l1;
bank->saved_risingdetect = l2;
l1 &= ~bank->enabled_non_wakeup_gpios;
l2 &= ~bank->enabled_non_wakeup_gpios;
if (cpu_is_omap24xx() || cpu_is_omap34xx()) {
__raw_writel(l1, bank->base +
OMAP24XX_GPIO_FALLINGDETECT);
__raw_writel(l2, bank->base +
OMAP24XX_GPIO_RISINGDETECT);
}
if (cpu_is_omap44xx()) {
__raw_writel(l1, bank->base + OMAP4_GPIO_FALLINGDETECT);
__raw_writel(l2, bank->base + OMAP4_GPIO_RISINGDETECT);
}
c++;
}
if (!c) {
workaround_enabled = 0;
return;
}
workaround_enabled = 1;
}
void omap2_gpio_resume_after_idle(void)
{
int i;
int min = 0;
if (cpu_is_omap34xx())
min = 1;
for (i = min; i < gpio_bank_count; i++) {
struct gpio_bank *bank = &gpio_bank[i];
u32 l = 0, gen, gen0, gen1;
int j;
for (j = 0; j < hweight_long(bank->dbck_enable_mask); j++)
clk_enable(bank->dbck);
if (!workaround_enabled)
continue;
if (!(bank->enabled_non_wakeup_gpios))
continue;
if (cpu_is_omap24xx() || cpu_is_omap34xx()) {
__raw_writel(bank->saved_fallingdetect,
bank->base + OMAP24XX_GPIO_FALLINGDETECT);
__raw_writel(bank->saved_risingdetect,
bank->base + OMAP24XX_GPIO_RISINGDETECT);
l = __raw_readl(bank->base + OMAP24XX_GPIO_DATAIN);
}
if (cpu_is_omap44xx()) {
__raw_writel(bank->saved_fallingdetect,
bank->base + OMAP4_GPIO_FALLINGDETECT);
__raw_writel(bank->saved_risingdetect,
bank->base + OMAP4_GPIO_RISINGDETECT);
l = __raw_readl(bank->base + OMAP4_GPIO_DATAIN);
}
l ^= bank->saved_datain;
l &= bank->enabled_non_wakeup_gpios;
gen0 = l & bank->saved_fallingdetect;
gen0 &= bank->saved_datain;
gen1 = l & bank->saved_risingdetect;
gen1 &= ~(bank->saved_datain);
gen = l & (~(bank->saved_fallingdetect) &
~(bank->saved_risingdetect));
gen |= gen0 | gen1;
if (gen) {
u32 old0, old1;
if (cpu_is_omap24xx() || cpu_is_omap34xx()) {
old0 = __raw_readl(bank->base +
OMAP24XX_GPIO_LEVELDETECT0);
old1 = __raw_readl(bank->base +
OMAP24XX_GPIO_LEVELDETECT1);
__raw_writel(old0 | gen, bank->base +
OMAP24XX_GPIO_LEVELDETECT0);
__raw_writel(old1 | gen, bank->base +
OMAP24XX_GPIO_LEVELDETECT1);
__raw_writel(old0, bank->base +
OMAP24XX_GPIO_LEVELDETECT0);
__raw_writel(old1, bank->base +
OMAP24XX_GPIO_LEVELDETECT1);
}
if (cpu_is_omap44xx()) {
old0 = __raw_readl(bank->base +
OMAP4_GPIO_LEVELDETECT0);
old1 = __raw_readl(bank->base +
OMAP4_GPIO_LEVELDETECT1);
__raw_writel(old0 | l, bank->base +
OMAP4_GPIO_LEVELDETECT0);
__raw_writel(old1 | l, bank->base +
OMAP4_GPIO_LEVELDETECT1);
__raw_writel(old0, bank->base +
OMAP4_GPIO_LEVELDETECT0);
__raw_writel(old1, bank->base +
OMAP4_GPIO_LEVELDETECT1);
}
}
}
}
void omap_gpio_save_context(void)
{
int i;
for (i = 1; i < gpio_bank_count; i++) {
struct gpio_bank *bank = &gpio_bank[i];
gpio_context[i].irqenable1 =
__raw_readl(bank->base + OMAP24XX_GPIO_IRQENABLE1);
gpio_context[i].irqenable2 =
__raw_readl(bank->base + OMAP24XX_GPIO_IRQENABLE2);
gpio_context[i].wake_en =
__raw_readl(bank->base + OMAP24XX_GPIO_WAKE_EN);
gpio_context[i].ctrl =
__raw_readl(bank->base + OMAP24XX_GPIO_CTRL);
gpio_context[i].oe =
__raw_readl(bank->base + OMAP24XX_GPIO_OE);
gpio_context[i].leveldetect0 =
__raw_readl(bank->base + OMAP24XX_GPIO_LEVELDETECT0);
gpio_context[i].leveldetect1 =
__raw_readl(bank->base + OMAP24XX_GPIO_LEVELDETECT1);
gpio_context[i].risingdetect =
__raw_readl(bank->base + OMAP24XX_GPIO_RISINGDETECT);
gpio_context[i].fallingdetect =
__raw_readl(bank->base + OMAP24XX_GPIO_FALLINGDETECT);
gpio_context[i].dataout =
__raw_readl(bank->base + OMAP24XX_GPIO_DATAOUT);
}
}
void omap_gpio_restore_context(void)
{
int i;
for (i = 1; i < gpio_bank_count; i++) {
struct gpio_bank *bank = &gpio_bank[i];
__raw_writel(gpio_context[i].irqenable1,
bank->base + OMAP24XX_GPIO_IRQENABLE1);
__raw_writel(gpio_context[i].irqenable2,
bank->base + OMAP24XX_GPIO_IRQENABLE2);
__raw_writel(gpio_context[i].wake_en,
bank->base + OMAP24XX_GPIO_WAKE_EN);
__raw_writel(gpio_context[i].ctrl,
bank->base + OMAP24XX_GPIO_CTRL);
__raw_writel(gpio_context[i].oe,
bank->base + OMAP24XX_GPIO_OE);
__raw_writel(gpio_context[i].leveldetect0,
bank->base + OMAP24XX_GPIO_LEVELDETECT0);
__raw_writel(gpio_context[i].leveldetect1,
bank->base + OMAP24XX_GPIO_LEVELDETECT1);
__raw_writel(gpio_context[i].risingdetect,
bank->base + OMAP24XX_GPIO_RISINGDETECT);
__raw_writel(gpio_context[i].fallingdetect,
bank->base + OMAP24XX_GPIO_FALLINGDETECT);
__raw_writel(gpio_context[i].dataout,
bank->base + OMAP24XX_GPIO_DATAOUT);
}
}
static int __init omap_gpio_drv_reg(void)
{
return platform_driver_register(&omap_gpio_driver);
}
static int __init omap_gpio_sysinit(void)
{
mpuio_init();
#if defined(CONFIG_ARCH_OMAP16XX) || defined(CONFIG_ARCH_OMAP2PLUS)
if (cpu_is_omap16xx() || cpu_class_is_omap2())
register_syscore_ops(&omap_gpio_syscore_ops);
#endif
return 0;
}
