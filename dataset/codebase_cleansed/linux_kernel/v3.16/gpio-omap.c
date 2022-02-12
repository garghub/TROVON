static int irq_to_gpio(struct gpio_bank *bank, unsigned int gpio_irq)
{
return bank->chip.base + gpio_irq;
}
static inline struct gpio_bank *_irq_data_get_bank(struct irq_data *d)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
return container_of(chip, struct gpio_bank, chip);
}
static void _set_gpio_direction(struct gpio_bank *bank, int gpio, int is_input)
{
void __iomem *reg = bank->base;
u32 l;
reg += bank->regs->direction;
l = readl_relaxed(reg);
if (is_input)
l |= BIT(gpio);
else
l &= ~(BIT(gpio));
writel_relaxed(l, reg);
bank->context.oe = l;
}
static void _set_gpio_dataout_reg(struct gpio_bank *bank, int gpio, int enable)
{
void __iomem *reg = bank->base;
u32 l = GPIO_BIT(bank, gpio);
if (enable) {
reg += bank->regs->set_dataout;
bank->context.dataout |= l;
} else {
reg += bank->regs->clr_dataout;
bank->context.dataout &= ~l;
}
writel_relaxed(l, reg);
}
static void _set_gpio_dataout_mask(struct gpio_bank *bank, int gpio, int enable)
{
void __iomem *reg = bank->base + bank->regs->dataout;
u32 gpio_bit = GPIO_BIT(bank, gpio);
u32 l;
l = readl_relaxed(reg);
if (enable)
l |= gpio_bit;
else
l &= ~gpio_bit;
writel_relaxed(l, reg);
bank->context.dataout = l;
}
static int _get_gpio_datain(struct gpio_bank *bank, int offset)
{
void __iomem *reg = bank->base + bank->regs->datain;
return (readl_relaxed(reg) & (BIT(offset))) != 0;
}
static int _get_gpio_dataout(struct gpio_bank *bank, int offset)
{
void __iomem *reg = bank->base + bank->regs->dataout;
return (readl_relaxed(reg) & (BIT(offset))) != 0;
}
static inline void _gpio_rmw(void __iomem *base, u32 reg, u32 mask, bool set)
{
int l = readl_relaxed(base + reg);
if (set)
l |= mask;
else
l &= ~mask;
writel_relaxed(l, base + reg);
}
static inline void _gpio_dbck_enable(struct gpio_bank *bank)
{
if (bank->dbck_enable_mask && !bank->dbck_enabled) {
clk_prepare_enable(bank->dbck);
bank->dbck_enabled = true;
writel_relaxed(bank->dbck_enable_mask,
bank->base + bank->regs->debounce_en);
}
}
static inline void _gpio_dbck_disable(struct gpio_bank *bank)
{
if (bank->dbck_enable_mask && bank->dbck_enabled) {
writel_relaxed(0, bank->base + bank->regs->debounce_en);
clk_disable_unprepare(bank->dbck);
bank->dbck_enabled = false;
}
}
static void _set_gpio_debounce(struct gpio_bank *bank, unsigned gpio,
unsigned debounce)
{
void __iomem *reg;
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
l = GPIO_BIT(bank, gpio);
clk_prepare_enable(bank->dbck);
reg = bank->base + bank->regs->debounce;
writel_relaxed(debounce, reg);
reg = bank->base + bank->regs->debounce_en;
val = readl_relaxed(reg);
if (debounce)
val |= l;
else
val &= ~l;
bank->dbck_enable_mask = val;
writel_relaxed(val, reg);
clk_disable_unprepare(bank->dbck);
_gpio_dbck_enable(bank);
if (bank->dbck_enable_mask) {
bank->context.debounce = debounce;
bank->context.debounce_en = val;
}
}
static void _clear_gpio_debounce(struct gpio_bank *bank, unsigned gpio)
{
u32 gpio_bit = GPIO_BIT(bank, gpio);
if (!bank->dbck_flag)
return;
if (!(bank->dbck_enable_mask & gpio_bit))
return;
bank->dbck_enable_mask &= ~gpio_bit;
bank->context.debounce_en &= ~gpio_bit;
writel_relaxed(bank->context.debounce_en,
bank->base + bank->regs->debounce_en);
if (!bank->dbck_enable_mask) {
bank->context.debounce = 0;
writel_relaxed(bank->context.debounce, bank->base +
bank->regs->debounce);
clk_disable_unprepare(bank->dbck);
bank->dbck_enabled = false;
}
}
static inline void set_gpio_trigger(struct gpio_bank *bank, int gpio,
unsigned trigger)
{
void __iomem *base = bank->base;
u32 gpio_bit = BIT(gpio);
_gpio_rmw(base, bank->regs->leveldetect0, gpio_bit,
trigger & IRQ_TYPE_LEVEL_LOW);
_gpio_rmw(base, bank->regs->leveldetect1, gpio_bit,
trigger & IRQ_TYPE_LEVEL_HIGH);
_gpio_rmw(base, bank->regs->risingdetect, gpio_bit,
trigger & IRQ_TYPE_EDGE_RISING);
_gpio_rmw(base, bank->regs->fallingdetect, gpio_bit,
trigger & IRQ_TYPE_EDGE_FALLING);
bank->context.leveldetect0 =
readl_relaxed(bank->base + bank->regs->leveldetect0);
bank->context.leveldetect1 =
readl_relaxed(bank->base + bank->regs->leveldetect1);
bank->context.risingdetect =
readl_relaxed(bank->base + bank->regs->risingdetect);
bank->context.fallingdetect =
readl_relaxed(bank->base + bank->regs->fallingdetect);
if (likely(!(bank->non_wakeup_gpios & gpio_bit))) {
_gpio_rmw(base, bank->regs->wkup_en, gpio_bit, trigger != 0);
bank->context.wake_en =
readl_relaxed(bank->base + bank->regs->wkup_en);
}
if (!bank->regs->irqctrl) {
if (bank->non_wakeup_gpios) {
if (!(bank->non_wakeup_gpios & gpio_bit))
goto exit;
}
if (trigger & IRQ_TYPE_EDGE_BOTH)
bank->enabled_non_wakeup_gpios |= gpio_bit;
else
bank->enabled_non_wakeup_gpios &= ~gpio_bit;
}
exit:
bank->level_mask =
readl_relaxed(bank->base + bank->regs->leveldetect0) |
readl_relaxed(bank->base + bank->regs->leveldetect1);
}
static void _toggle_gpio_edge_triggering(struct gpio_bank *bank, int gpio)
{
void __iomem *reg = bank->base;
u32 l = 0;
if (!bank->regs->irqctrl)
return;
reg += bank->regs->irqctrl;
l = readl_relaxed(reg);
if ((l >> gpio) & 1)
l &= ~(BIT(gpio));
else
l |= BIT(gpio);
writel_relaxed(l, reg);
}
static void _toggle_gpio_edge_triggering(struct gpio_bank *bank, int gpio) {}
static int _set_gpio_triggering(struct gpio_bank *bank, int gpio,
unsigned trigger)
{
void __iomem *reg = bank->base;
void __iomem *base = bank->base;
u32 l = 0;
if (bank->regs->leveldetect0 && bank->regs->wkup_en) {
set_gpio_trigger(bank, gpio, trigger);
} else if (bank->regs->irqctrl) {
reg += bank->regs->irqctrl;
l = readl_relaxed(reg);
if ((trigger & IRQ_TYPE_SENSE_MASK) == IRQ_TYPE_EDGE_BOTH)
bank->toggle_mask |= BIT(gpio);
if (trigger & IRQ_TYPE_EDGE_RISING)
l |= BIT(gpio);
else if (trigger & IRQ_TYPE_EDGE_FALLING)
l &= ~(BIT(gpio));
else
return -EINVAL;
writel_relaxed(l, reg);
} else if (bank->regs->edgectrl1) {
if (gpio & 0x08)
reg += bank->regs->edgectrl2;
else
reg += bank->regs->edgectrl1;
gpio &= 0x07;
l = readl_relaxed(reg);
l &= ~(3 << (gpio << 1));
if (trigger & IRQ_TYPE_EDGE_RISING)
l |= 2 << (gpio << 1);
if (trigger & IRQ_TYPE_EDGE_FALLING)
l |= BIT(gpio << 1);
_gpio_rmw(base, bank->regs->wkup_en, BIT(gpio), trigger);
bank->context.wake_en =
readl_relaxed(bank->base + bank->regs->wkup_en);
writel_relaxed(l, reg);
}
return 0;
}
static void _enable_gpio_module(struct gpio_bank *bank, unsigned offset)
{
if (bank->regs->pinctrl) {
void __iomem *reg = bank->base + bank->regs->pinctrl;
writel_relaxed(readl_relaxed(reg) | (BIT(offset)), reg);
}
if (bank->regs->ctrl && !BANK_USED(bank)) {
void __iomem *reg = bank->base + bank->regs->ctrl;
u32 ctrl;
ctrl = readl_relaxed(reg);
ctrl &= ~GPIO_MOD_CTRL_BIT;
writel_relaxed(ctrl, reg);
bank->context.ctrl = ctrl;
}
}
static void _disable_gpio_module(struct gpio_bank *bank, unsigned offset)
{
void __iomem *base = bank->base;
if (bank->regs->wkup_en &&
!LINE_USED(bank->mod_usage, offset) &&
!LINE_USED(bank->irq_usage, offset)) {
_gpio_rmw(base, bank->regs->wkup_en, BIT(offset), 0);
bank->context.wake_en =
readl_relaxed(bank->base + bank->regs->wkup_en);
}
if (bank->regs->ctrl && !BANK_USED(bank)) {
void __iomem *reg = bank->base + bank->regs->ctrl;
u32 ctrl;
ctrl = readl_relaxed(reg);
ctrl |= GPIO_MOD_CTRL_BIT;
writel_relaxed(ctrl, reg);
bank->context.ctrl = ctrl;
}
}
static int gpio_is_input(struct gpio_bank *bank, int mask)
{
void __iomem *reg = bank->base + bank->regs->direction;
return readl_relaxed(reg) & mask;
}
static int gpio_irq_type(struct irq_data *d, unsigned type)
{
struct gpio_bank *bank = _irq_data_get_bank(d);
unsigned gpio = 0;
int retval;
unsigned long flags;
unsigned offset;
if (!BANK_USED(bank))
pm_runtime_get_sync(bank->dev);
#ifdef CONFIG_ARCH_OMAP1
if (d->irq > IH_MPUIO_BASE)
gpio = OMAP_MPUIO(d->irq - IH_MPUIO_BASE);
#endif
if (!gpio)
gpio = irq_to_gpio(bank, d->hwirq);
if (type & ~IRQ_TYPE_SENSE_MASK)
return -EINVAL;
if (!bank->regs->leveldetect0 &&
(type & (IRQ_TYPE_LEVEL_LOW|IRQ_TYPE_LEVEL_HIGH)))
return -EINVAL;
spin_lock_irqsave(&bank->lock, flags);
offset = GPIO_INDEX(bank, gpio);
retval = _set_gpio_triggering(bank, offset, type);
if (!LINE_USED(bank->mod_usage, offset)) {
_enable_gpio_module(bank, offset);
_set_gpio_direction(bank, offset, 1);
} else if (!gpio_is_input(bank, BIT(offset))) {
spin_unlock_irqrestore(&bank->lock, flags);
return -EINVAL;
}
bank->irq_usage |= BIT(GPIO_INDEX(bank, gpio));
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
reg += bank->regs->irqstatus;
writel_relaxed(gpio_mask, reg);
if (bank->regs->irqstatus2) {
reg = bank->base + bank->regs->irqstatus2;
writel_relaxed(gpio_mask, reg);
}
readl_relaxed(reg);
}
static inline void _clear_gpio_irqstatus(struct gpio_bank *bank, int gpio)
{
_clear_gpio_irqbank(bank, GPIO_BIT(bank, gpio));
}
static u32 _get_gpio_irqbank_mask(struct gpio_bank *bank)
{
void __iomem *reg = bank->base;
u32 l;
u32 mask = (BIT(bank->width)) - 1;
reg += bank->regs->irqenable;
l = readl_relaxed(reg);
if (bank->regs->irqenable_inv)
l = ~l;
l &= mask;
return l;
}
static void _enable_gpio_irqbank(struct gpio_bank *bank, int gpio_mask)
{
void __iomem *reg = bank->base;
u32 l;
if (bank->regs->set_irqenable) {
reg += bank->regs->set_irqenable;
l = gpio_mask;
bank->context.irqenable1 |= gpio_mask;
} else {
reg += bank->regs->irqenable;
l = readl_relaxed(reg);
if (bank->regs->irqenable_inv)
l &= ~gpio_mask;
else
l |= gpio_mask;
bank->context.irqenable1 = l;
}
writel_relaxed(l, reg);
}
static void _disable_gpio_irqbank(struct gpio_bank *bank, int gpio_mask)
{
void __iomem *reg = bank->base;
u32 l;
if (bank->regs->clr_irqenable) {
reg += bank->regs->clr_irqenable;
l = gpio_mask;
bank->context.irqenable1 &= ~gpio_mask;
} else {
reg += bank->regs->irqenable;
l = readl_relaxed(reg);
if (bank->regs->irqenable_inv)
l |= gpio_mask;
else
l &= ~gpio_mask;
bank->context.irqenable1 = l;
}
writel_relaxed(l, reg);
}
static inline void _set_gpio_irqenable(struct gpio_bank *bank, int gpio, int enable)
{
if (enable)
_enable_gpio_irqbank(bank, GPIO_BIT(bank, gpio));
else
_disable_gpio_irqbank(bank, GPIO_BIT(bank, gpio));
}
static int _set_gpio_wakeup(struct gpio_bank *bank, int gpio, int enable)
{
u32 gpio_bit = GPIO_BIT(bank, gpio);
unsigned long flags;
if (bank->non_wakeup_gpios & gpio_bit) {
dev_err(bank->dev,
"Unable to modify wakeup on non-wakeup GPIO%d\n", gpio);
return -EINVAL;
}
spin_lock_irqsave(&bank->lock, flags);
if (enable)
bank->context.wake_en |= gpio_bit;
else
bank->context.wake_en &= ~gpio_bit;
writel_relaxed(bank->context.wake_en, bank->base + bank->regs->wkup_en);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static void _reset_gpio(struct gpio_bank *bank, int gpio)
{
_set_gpio_direction(bank, GPIO_INDEX(bank, gpio), 1);
_set_gpio_irqenable(bank, gpio, 0);
_clear_gpio_irqstatus(bank, gpio);
_set_gpio_triggering(bank, GPIO_INDEX(bank, gpio), IRQ_TYPE_NONE);
_clear_gpio_debounce(bank, gpio);
}
static int gpio_wake_enable(struct irq_data *d, unsigned int enable)
{
struct gpio_bank *bank = _irq_data_get_bank(d);
unsigned int gpio = irq_to_gpio(bank, d->hwirq);
return _set_gpio_wakeup(bank, gpio, enable);
}
static int omap_gpio_request(struct gpio_chip *chip, unsigned offset)
{
struct gpio_bank *bank = container_of(chip, struct gpio_bank, chip);
unsigned long flags;
if (!BANK_USED(bank))
pm_runtime_get_sync(bank->dev);
spin_lock_irqsave(&bank->lock, flags);
if (!LINE_USED(bank->irq_usage, offset)) {
_set_gpio_triggering(bank, offset, IRQ_TYPE_NONE);
_enable_gpio_module(bank, offset);
}
bank->mod_usage |= BIT(offset);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static void omap_gpio_free(struct gpio_chip *chip, unsigned offset)
{
struct gpio_bank *bank = container_of(chip, struct gpio_bank, chip);
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
bank->mod_usage &= ~(BIT(offset));
_disable_gpio_module(bank, offset);
_reset_gpio(bank, bank->chip.base + offset);
spin_unlock_irqrestore(&bank->lock, flags);
if (!BANK_USED(bank))
pm_runtime_put(bank->dev);
}
static void gpio_irq_handler(unsigned int irq, struct irq_desc *desc)
{
void __iomem *isr_reg = NULL;
u32 isr;
unsigned int bit;
struct gpio_bank *bank;
int unmasked = 0;
struct irq_chip *irqchip = irq_desc_get_chip(desc);
struct gpio_chip *chip = irq_get_handler_data(irq);
chained_irq_enter(irqchip, desc);
bank = container_of(chip, struct gpio_bank, chip);
isr_reg = bank->base + bank->regs->irqstatus;
pm_runtime_get_sync(bank->dev);
if (WARN_ON(!isr_reg))
goto exit;
while (1) {
u32 isr_saved, level_mask = 0;
u32 enabled;
enabled = _get_gpio_irqbank_mask(bank);
isr_saved = isr = readl_relaxed(isr_reg) & enabled;
if (bank->level_mask)
level_mask = bank->level_mask & enabled;
_disable_gpio_irqbank(bank, isr_saved & ~level_mask);
_clear_gpio_irqbank(bank, isr_saved & ~level_mask);
_enable_gpio_irqbank(bank, isr_saved & ~level_mask);
if (!level_mask && !unmasked) {
unmasked = 1;
chained_irq_exit(irqchip, desc);
}
if (!isr)
break;
while (isr) {
bit = __ffs(isr);
isr &= ~(BIT(bit));
if (bank->toggle_mask & (BIT(bit)))
_toggle_gpio_edge_triggering(bank, bit);
generic_handle_irq(irq_find_mapping(bank->chip.irqdomain,
bit));
}
}
exit:
if (!unmasked)
chained_irq_exit(irqchip, desc);
pm_runtime_put(bank->dev);
}
static void gpio_irq_shutdown(struct irq_data *d)
{
struct gpio_bank *bank = _irq_data_get_bank(d);
unsigned int gpio = irq_to_gpio(bank, d->hwirq);
unsigned long flags;
unsigned offset = GPIO_INDEX(bank, gpio);
spin_lock_irqsave(&bank->lock, flags);
gpio_unlock_as_irq(&bank->chip, offset);
bank->irq_usage &= ~(BIT(offset));
_disable_gpio_module(bank, offset);
_reset_gpio(bank, gpio);
spin_unlock_irqrestore(&bank->lock, flags);
if (!BANK_USED(bank))
pm_runtime_put(bank->dev);
}
static void gpio_ack_irq(struct irq_data *d)
{
struct gpio_bank *bank = _irq_data_get_bank(d);
unsigned int gpio = irq_to_gpio(bank, d->hwirq);
_clear_gpio_irqstatus(bank, gpio);
}
static void gpio_mask_irq(struct irq_data *d)
{
struct gpio_bank *bank = _irq_data_get_bank(d);
unsigned int gpio = irq_to_gpio(bank, d->hwirq);
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
_set_gpio_irqenable(bank, gpio, 0);
_set_gpio_triggering(bank, GPIO_INDEX(bank, gpio), IRQ_TYPE_NONE);
spin_unlock_irqrestore(&bank->lock, flags);
}
static void gpio_unmask_irq(struct irq_data *d)
{
struct gpio_bank *bank = _irq_data_get_bank(d);
unsigned int gpio = irq_to_gpio(bank, d->hwirq);
unsigned int irq_mask = GPIO_BIT(bank, gpio);
u32 trigger = irqd_get_trigger_type(d);
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
if (trigger)
_set_gpio_triggering(bank, GPIO_INDEX(bank, gpio), trigger);
if (bank->level_mask & irq_mask) {
_set_gpio_irqenable(bank, gpio, 0);
_clear_gpio_irqstatus(bank, gpio);
}
_set_gpio_irqenable(bank, gpio, 1);
spin_unlock_irqrestore(&bank->lock, flags);
}
static int omap_mpuio_suspend_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct gpio_bank *bank = platform_get_drvdata(pdev);
void __iomem *mask_reg = bank->base +
OMAP_MPUIO_GPIO_MASKIT / bank->stride;
unsigned long flags;
spin_lock_irqsave(&bank->lock, flags);
writel_relaxed(0xffff & ~bank->context.wake_en, mask_reg);
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
writel_relaxed(bank->context.wake_en, mask_reg);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static inline void mpuio_init(struct gpio_bank *bank)
{
platform_set_drvdata(&omap_mpuio_device, bank);
if (platform_driver_register(&omap_mpuio_driver) == 0)
(void) platform_device_register(&omap_mpuio_device);
}
static int gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
struct gpio_bank *bank;
unsigned long flags;
void __iomem *reg;
int dir;
bank = container_of(chip, struct gpio_bank, chip);
reg = bank->base + bank->regs->direction;
spin_lock_irqsave(&bank->lock, flags);
dir = !!(readl_relaxed(reg) & BIT(offset));
spin_unlock_irqrestore(&bank->lock, flags);
return dir;
}
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
static int gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct gpio_bank *bank;
u32 mask;
bank = container_of(chip, struct gpio_bank, chip);
mask = (BIT(offset));
if (gpio_is_input(bank, mask))
return _get_gpio_datain(bank, offset);
else
return _get_gpio_dataout(bank, offset);
}
static int gpio_output(struct gpio_chip *chip, unsigned offset, int value)
{
struct gpio_bank *bank;
unsigned long flags;
bank = container_of(chip, struct gpio_bank, chip);
spin_lock_irqsave(&bank->lock, flags);
bank->set_dataout(bank, offset, value);
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
bank->set_dataout(bank, offset, value);
spin_unlock_irqrestore(&bank->lock, flags);
}
static void __init omap_gpio_show_rev(struct gpio_bank *bank)
{
static bool called;
u32 rev;
if (called || bank->regs->revision == USHRT_MAX)
return;
rev = readw_relaxed(bank->base + bank->regs->revision);
pr_info("OMAP GPIO hardware version %d.%d\n",
(rev >> 4) & 0x0f, rev & 0x0f);
called = true;
}
static void omap_gpio_mod_init(struct gpio_bank *bank)
{
void __iomem *base = bank->base;
u32 l = 0xffffffff;
if (bank->width == 16)
l = 0xffff;
if (bank->is_mpuio) {
writel_relaxed(l, bank->base + bank->regs->irqenable);
return;
}
_gpio_rmw(base, bank->regs->irqenable, l, bank->regs->irqenable_inv);
_gpio_rmw(base, bank->regs->irqstatus, l, !bank->regs->irqenable_inv);
if (bank->regs->debounce_en)
writel_relaxed(0, base + bank->regs->debounce_en);
bank->context.oe = readl_relaxed(bank->base + bank->regs->direction);
if (bank->regs->ctrl)
writel_relaxed(0, base + bank->regs->ctrl);
bank->dbck = clk_get(bank->dev, "dbclk");
if (IS_ERR(bank->dbck))
dev_err(bank->dev, "Could not get gpio dbck\n");
}
static void
omap_mpuio_alloc_gc(struct gpio_bank *bank, unsigned int irq_start,
unsigned int num)
{
struct irq_chip_generic *gc;
struct irq_chip_type *ct;
gc = irq_alloc_generic_chip("MPUIO", 1, irq_start, bank->base,
handle_simple_irq);
if (!gc) {
dev_err(bank->dev, "Memory alloc failed for gc\n");
return;
}
ct = gc->chip_types;
ct->chip.irq_mask = irq_gc_mask_set_bit;
ct->chip.irq_unmask = irq_gc_mask_clr_bit;
ct->chip.irq_set_type = gpio_irq_type;
if (bank->regs->wkup_en)
ct->chip.irq_set_wake = gpio_wake_enable;
ct->regs.mask = OMAP_MPUIO_GPIO_INT / bank->stride;
irq_setup_generic_chip(gc, IRQ_MSK(num), IRQ_GC_INIT_MASK_CACHE,
IRQ_NOREQUEST | IRQ_NOPROBE, 0);
}
static int omap_gpio_chip_init(struct gpio_bank *bank)
{
int j;
static int gpio;
int irq_base = 0;
int ret;
bank->chip.request = omap_gpio_request;
bank->chip.free = omap_gpio_free;
bank->chip.get_direction = gpio_get_direction;
bank->chip.direction_input = gpio_input;
bank->chip.get = gpio_get;
bank->chip.direction_output = gpio_output;
bank->chip.set_debounce = gpio_debounce;
bank->chip.set = gpio_set;
if (bank->is_mpuio) {
bank->chip.label = "mpuio";
if (bank->regs->wkup_en)
bank->chip.dev = &omap_mpuio_device.dev;
bank->chip.base = OMAP_MPUIO(0);
} else {
bank->chip.label = "gpio";
bank->chip.base = gpio;
gpio += bank->width;
}
bank->chip.ngpio = bank->width;
ret = gpiochip_add(&bank->chip);
if (ret) {
dev_err(bank->dev, "Could not register gpio chip %d\n", ret);
return ret;
}
#ifdef CONFIG_ARCH_OMAP1
irq_base = irq_alloc_descs(-1, 0, bank->width, 0);
if (irq_base < 0) {
dev_err(bank->dev, "Couldn't allocate IRQ numbers\n");
return -ENODEV;
}
#endif
ret = gpiochip_irqchip_add(&bank->chip, &gpio_irq_chip,
irq_base, gpio_irq_handler,
IRQ_TYPE_NONE);
if (ret) {
dev_err(bank->dev, "Couldn't add irqchip to gpiochip %d\n", ret);
ret = gpiochip_remove(&bank->chip);
return -ENODEV;
}
gpiochip_set_chained_irqchip(&bank->chip, &gpio_irq_chip,
bank->irq, gpio_irq_handler);
for (j = 0; j < bank->width; j++) {
int irq = irq_find_mapping(bank->chip.irqdomain, j);
irq_set_lockdep_class(irq, &gpio_lock_class);
if (bank->is_mpuio) {
omap_mpuio_alloc_gc(bank, irq, bank->width);
irq_set_chip_and_handler(irq, NULL, NULL);
set_irq_flags(irq, 0);
}
}
return 0;
}
static int omap_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
const struct of_device_id *match;
const struct omap_gpio_platform_data *pdata;
struct resource *res;
struct gpio_bank *bank;
int ret;
match = of_match_device(of_match_ptr(omap_gpio_match), dev);
pdata = match ? match->data : dev_get_platdata(dev);
if (!pdata)
return -EINVAL;
bank = devm_kzalloc(dev, sizeof(struct gpio_bank), GFP_KERNEL);
if (!bank) {
dev_err(dev, "Memory alloc failed\n");
return -ENOMEM;
}
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (unlikely(!res)) {
dev_err(dev, "Invalid IRQ resource\n");
return -ENODEV;
}
bank->irq = res->start;
bank->dev = dev;
bank->chip.dev = dev;
bank->dbck_flag = pdata->dbck_flag;
bank->stride = pdata->bank_stride;
bank->width = pdata->bank_width;
bank->is_mpuio = pdata->is_mpuio;
bank->non_wakeup_gpios = pdata->non_wakeup_gpios;
bank->regs = pdata->regs;
#ifdef CONFIG_OF_GPIO
bank->chip.of_node = of_node_get(node);
#endif
if (node) {
if (!of_property_read_bool(node, "ti,gpio-always-on"))
bank->loses_context = true;
} else {
bank->loses_context = pdata->loses_context;
if (bank->loses_context)
bank->get_context_loss_count =
pdata->get_context_loss_count;
}
if (bank->regs->set_dataout && bank->regs->clr_dataout)
bank->set_dataout = _set_gpio_dataout_reg;
else
bank->set_dataout = _set_gpio_dataout_mask;
spin_lock_init(&bank->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
bank->base = devm_ioremap_resource(dev, res);
if (IS_ERR(bank->base)) {
irq_domain_remove(bank->chip.irqdomain);
return PTR_ERR(bank->base);
}
platform_set_drvdata(pdev, bank);
pm_runtime_enable(bank->dev);
pm_runtime_irq_safe(bank->dev);
pm_runtime_get_sync(bank->dev);
if (bank->is_mpuio)
mpuio_init(bank);
omap_gpio_mod_init(bank);
ret = omap_gpio_chip_init(bank);
if (ret)
return ret;
omap_gpio_show_rev(bank);
pm_runtime_put(bank->dev);
list_add_tail(&bank->node, &omap_gpio_list);
return 0;
}
static int omap_gpio_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct gpio_bank *bank = platform_get_drvdata(pdev);
u32 l1 = 0, l2 = 0;
unsigned long flags;
u32 wake_low, wake_hi;
spin_lock_irqsave(&bank->lock, flags);
wake_low = bank->context.leveldetect0 & bank->context.wake_en;
if (wake_low)
writel_relaxed(wake_low | bank->context.fallingdetect,
bank->base + bank->regs->fallingdetect);
wake_hi = bank->context.leveldetect1 & bank->context.wake_en;
if (wake_hi)
writel_relaxed(wake_hi | bank->context.risingdetect,
bank->base + bank->regs->risingdetect);
if (!bank->enabled_non_wakeup_gpios)
goto update_gpio_context_count;
if (bank->power_mode != OFF_MODE) {
bank->power_mode = 0;
goto update_gpio_context_count;
}
bank->saved_datain = readl_relaxed(bank->base +
bank->regs->datain);
l1 = bank->context.fallingdetect;
l2 = bank->context.risingdetect;
l1 &= ~bank->enabled_non_wakeup_gpios;
l2 &= ~bank->enabled_non_wakeup_gpios;
writel_relaxed(l1, bank->base + bank->regs->fallingdetect);
writel_relaxed(l2, bank->base + bank->regs->risingdetect);
bank->workaround_enabled = true;
update_gpio_context_count:
if (bank->get_context_loss_count)
bank->context_loss_count =
bank->get_context_loss_count(bank->dev);
_gpio_dbck_disable(bank);
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
static int omap_gpio_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct gpio_bank *bank = platform_get_drvdata(pdev);
u32 l = 0, gen, gen0, gen1;
unsigned long flags;
int c;
spin_lock_irqsave(&bank->lock, flags);
if (bank->loses_context && !bank->context_valid) {
omap_gpio_init_context(bank);
if (bank->get_context_loss_count)
bank->context_loss_count =
bank->get_context_loss_count(bank->dev);
}
_gpio_dbck_enable(bank);
writel_relaxed(bank->context.fallingdetect,
bank->base + bank->regs->fallingdetect);
writel_relaxed(bank->context.risingdetect,
bank->base + bank->regs->risingdetect);
if (bank->loses_context) {
if (!bank->get_context_loss_count) {
omap_gpio_restore_context(bank);
} else {
c = bank->get_context_loss_count(bank->dev);
if (c != bank->context_loss_count) {
omap_gpio_restore_context(bank);
} else {
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
}
}
if (!bank->workaround_enabled) {
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
l = readl_relaxed(bank->base + bank->regs->datain);
l ^= bank->saved_datain;
l &= bank->enabled_non_wakeup_gpios;
gen0 = l & bank->context.fallingdetect;
gen0 &= bank->saved_datain;
gen1 = l & bank->context.risingdetect;
gen1 &= ~(bank->saved_datain);
gen = l & (~(bank->context.fallingdetect) &
~(bank->context.risingdetect));
gen |= gen0 | gen1;
if (gen) {
u32 old0, old1;
old0 = readl_relaxed(bank->base + bank->regs->leveldetect0);
old1 = readl_relaxed(bank->base + bank->regs->leveldetect1);
if (!bank->regs->irqstatus_raw0) {
writel_relaxed(old0 | gen, bank->base +
bank->regs->leveldetect0);
writel_relaxed(old1 | gen, bank->base +
bank->regs->leveldetect1);
}
if (bank->regs->irqstatus_raw0) {
writel_relaxed(old0 | l, bank->base +
bank->regs->leveldetect0);
writel_relaxed(old1 | l, bank->base +
bank->regs->leveldetect1);
}
writel_relaxed(old0, bank->base + bank->regs->leveldetect0);
writel_relaxed(old1, bank->base + bank->regs->leveldetect1);
}
bank->workaround_enabled = false;
spin_unlock_irqrestore(&bank->lock, flags);
return 0;
}
void omap2_gpio_prepare_for_idle(int pwr_mode)
{
struct gpio_bank *bank;
list_for_each_entry(bank, &omap_gpio_list, node) {
if (!BANK_USED(bank) || !bank->loses_context)
continue;
bank->power_mode = pwr_mode;
pm_runtime_put_sync_suspend(bank->dev);
}
}
void omap2_gpio_resume_after_idle(void)
{
struct gpio_bank *bank;
list_for_each_entry(bank, &omap_gpio_list, node) {
if (!BANK_USED(bank) || !bank->loses_context)
continue;
pm_runtime_get_sync(bank->dev);
}
}
static void omap_gpio_init_context(struct gpio_bank *p)
{
struct omap_gpio_reg_offs *regs = p->regs;
void __iomem *base = p->base;
p->context.ctrl = readl_relaxed(base + regs->ctrl);
p->context.oe = readl_relaxed(base + regs->direction);
p->context.wake_en = readl_relaxed(base + regs->wkup_en);
p->context.leveldetect0 = readl_relaxed(base + regs->leveldetect0);
p->context.leveldetect1 = readl_relaxed(base + regs->leveldetect1);
p->context.risingdetect = readl_relaxed(base + regs->risingdetect);
p->context.fallingdetect = readl_relaxed(base + regs->fallingdetect);
p->context.irqenable1 = readl_relaxed(base + regs->irqenable);
p->context.irqenable2 = readl_relaxed(base + regs->irqenable2);
if (regs->set_dataout && p->regs->clr_dataout)
p->context.dataout = readl_relaxed(base + regs->set_dataout);
else
p->context.dataout = readl_relaxed(base + regs->dataout);
p->context_valid = true;
}
static void omap_gpio_restore_context(struct gpio_bank *bank)
{
writel_relaxed(bank->context.wake_en,
bank->base + bank->regs->wkup_en);
writel_relaxed(bank->context.ctrl, bank->base + bank->regs->ctrl);
writel_relaxed(bank->context.leveldetect0,
bank->base + bank->regs->leveldetect0);
writel_relaxed(bank->context.leveldetect1,
bank->base + bank->regs->leveldetect1);
writel_relaxed(bank->context.risingdetect,
bank->base + bank->regs->risingdetect);
writel_relaxed(bank->context.fallingdetect,
bank->base + bank->regs->fallingdetect);
if (bank->regs->set_dataout && bank->regs->clr_dataout)
writel_relaxed(bank->context.dataout,
bank->base + bank->regs->set_dataout);
else
writel_relaxed(bank->context.dataout,
bank->base + bank->regs->dataout);
writel_relaxed(bank->context.oe, bank->base + bank->regs->direction);
if (bank->dbck_enable_mask) {
writel_relaxed(bank->context.debounce, bank->base +
bank->regs->debounce);
writel_relaxed(bank->context.debounce_en,
bank->base + bank->regs->debounce_en);
}
writel_relaxed(bank->context.irqenable1,
bank->base + bank->regs->irqenable);
writel_relaxed(bank->context.irqenable2,
bank->base + bank->regs->irqenable2);
}
static inline void omap_gpio_init_context(struct gpio_bank *p) {}
static int __init omap_gpio_drv_reg(void)
{
return platform_driver_register(&omap_gpio_driver);
}
