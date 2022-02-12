static void __nmk_gpio_set_mode(struct nmk_gpio_chip *nmk_chip,
unsigned offset, int gpio_mode)
{
u32 bit = 1 << offset;
u32 afunc, bfunc;
afunc = readl(nmk_chip->addr + NMK_GPIO_AFSLA) & ~bit;
bfunc = readl(nmk_chip->addr + NMK_GPIO_AFSLB) & ~bit;
if (gpio_mode & NMK_GPIO_ALT_A)
afunc |= bit;
if (gpio_mode & NMK_GPIO_ALT_B)
bfunc |= bit;
writel(afunc, nmk_chip->addr + NMK_GPIO_AFSLA);
writel(bfunc, nmk_chip->addr + NMK_GPIO_AFSLB);
}
static void __nmk_gpio_set_slpm(struct nmk_gpio_chip *nmk_chip,
unsigned offset, enum nmk_gpio_slpm mode)
{
u32 bit = 1 << offset;
u32 slpm;
slpm = readl(nmk_chip->addr + NMK_GPIO_SLPC);
if (mode == NMK_GPIO_SLPM_NOCHANGE)
slpm |= bit;
else
slpm &= ~bit;
writel(slpm, nmk_chip->addr + NMK_GPIO_SLPC);
}
static void __nmk_gpio_set_pull(struct nmk_gpio_chip *nmk_chip,
unsigned offset, enum nmk_gpio_pull pull)
{
u32 bit = 1 << offset;
u32 pdis;
pdis = readl(nmk_chip->addr + NMK_GPIO_PDIS);
if (pull == NMK_GPIO_PULL_NONE) {
pdis |= bit;
nmk_chip->pull_up &= ~bit;
} else {
pdis &= ~bit;
}
writel(pdis, nmk_chip->addr + NMK_GPIO_PDIS);
if (pull == NMK_GPIO_PULL_UP) {
nmk_chip->pull_up |= bit;
writel(bit, nmk_chip->addr + NMK_GPIO_DATS);
} else if (pull == NMK_GPIO_PULL_DOWN) {
nmk_chip->pull_up &= ~bit;
writel(bit, nmk_chip->addr + NMK_GPIO_DATC);
}
}
static void __nmk_gpio_set_lowemi(struct nmk_gpio_chip *nmk_chip,
unsigned offset, bool lowemi)
{
u32 bit = BIT(offset);
bool enabled = nmk_chip->lowemi & bit;
if (lowemi == enabled)
return;
if (lowemi)
nmk_chip->lowemi |= bit;
else
nmk_chip->lowemi &= ~bit;
writel_relaxed(nmk_chip->lowemi,
nmk_chip->addr + NMK_GPIO_LOWEMI);
}
static void __nmk_gpio_make_input(struct nmk_gpio_chip *nmk_chip,
unsigned offset)
{
writel(1 << offset, nmk_chip->addr + NMK_GPIO_DIRC);
}
static void __nmk_gpio_set_output(struct nmk_gpio_chip *nmk_chip,
unsigned offset, int val)
{
if (val)
writel(1 << offset, nmk_chip->addr + NMK_GPIO_DATS);
else
writel(1 << offset, nmk_chip->addr + NMK_GPIO_DATC);
}
static void __nmk_gpio_make_output(struct nmk_gpio_chip *nmk_chip,
unsigned offset, int val)
{
writel(1 << offset, nmk_chip->addr + NMK_GPIO_DIRS);
__nmk_gpio_set_output(nmk_chip, offset, val);
}
static void __nmk_gpio_set_mode_safe(struct nmk_gpio_chip *nmk_chip,
unsigned offset, int gpio_mode,
bool glitch)
{
u32 rwimsc = nmk_chip->rwimsc;
u32 fwimsc = nmk_chip->fwimsc;
if (glitch && nmk_chip->set_ioforce) {
u32 bit = BIT(offset);
writel(rwimsc & ~bit, nmk_chip->addr + NMK_GPIO_RWIMSC);
writel(fwimsc & ~bit, nmk_chip->addr + NMK_GPIO_FWIMSC);
nmk_chip->set_ioforce(true);
}
__nmk_gpio_set_mode(nmk_chip, offset, gpio_mode);
if (glitch && nmk_chip->set_ioforce) {
nmk_chip->set_ioforce(false);
writel(rwimsc, nmk_chip->addr + NMK_GPIO_RWIMSC);
writel(fwimsc, nmk_chip->addr + NMK_GPIO_FWIMSC);
}
}
static void
nmk_gpio_disable_lazy_irq(struct nmk_gpio_chip *nmk_chip, unsigned offset)
{
u32 falling = nmk_chip->fimsc & BIT(offset);
u32 rising = nmk_chip->rimsc & BIT(offset);
int gpio = nmk_chip->chip.base + offset;
int irq = irq_find_mapping(nmk_chip->domain, offset);
struct irq_data *d = irq_get_irq_data(irq);
if (!rising && !falling)
return;
if (!d || !irqd_irq_disabled(d))
return;
if (rising) {
nmk_chip->rimsc &= ~BIT(offset);
writel_relaxed(nmk_chip->rimsc,
nmk_chip->addr + NMK_GPIO_RIMSC);
}
if (falling) {
nmk_chip->fimsc &= ~BIT(offset);
writel_relaxed(nmk_chip->fimsc,
nmk_chip->addr + NMK_GPIO_FIMSC);
}
dev_dbg(nmk_chip->chip.dev, "%d: clearing interrupt mask\n", gpio);
}
static void nmk_write_masked(void __iomem *reg, u32 mask, u32 value)
{
u32 val;
val = readl(reg);
val = ((val & ~mask) | (value & mask));
writel(val, reg);
}
static void nmk_prcm_altcx_set_mode(struct nmk_pinctrl *npct,
unsigned offset, unsigned alt_num)
{
int i;
u16 reg;
u8 bit;
u8 alt_index;
const struct prcm_gpiocr_altcx_pin_desc *pin_desc;
const u16 *gpiocr_regs;
if (!npct->prcm_base)
return;
if (alt_num > PRCM_IDX_GPIOCR_ALTC_MAX) {
dev_err(npct->dev, "PRCM GPIOCR: alternate-C%i is invalid\n",
alt_num);
return;
}
for (i = 0 ; i < npct->soc->npins_altcx ; i++) {
if (npct->soc->altcx_pins[i].pin == offset)
break;
}
if (i == npct->soc->npins_altcx) {
dev_dbg(npct->dev, "PRCM GPIOCR: pin %i is not found\n",
offset);
return;
}
pin_desc = npct->soc->altcx_pins + i;
gpiocr_regs = npct->soc->prcm_gpiocr_registers;
if (!alt_num) {
for (i = 0 ; i < PRCM_IDX_GPIOCR_ALTC_MAX ; i++) {
if (pin_desc->altcx[i].used == true) {
reg = gpiocr_regs[pin_desc->altcx[i].reg_index];
bit = pin_desc->altcx[i].control_bit;
if (readl(npct->prcm_base + reg) & BIT(bit)) {
nmk_write_masked(npct->prcm_base + reg, BIT(bit), 0);
dev_dbg(npct->dev,
"PRCM GPIOCR: pin %i: alternate-C%i has been disabled\n",
offset, i+1);
}
}
}
return;
}
alt_index = alt_num - 1;
if (pin_desc->altcx[alt_index].used == false) {
dev_warn(npct->dev,
"PRCM GPIOCR: pin %i: alternate-C%i does not exist\n",
offset, alt_num);
return;
}
for (i = 0 ; i < PRCM_IDX_GPIOCR_ALTC_MAX ; i++) {
if (i == alt_index)
continue;
if (pin_desc->altcx[i].used == true) {
reg = gpiocr_regs[pin_desc->altcx[i].reg_index];
bit = pin_desc->altcx[i].control_bit;
if (readl(npct->prcm_base + reg) & BIT(bit)) {
nmk_write_masked(npct->prcm_base + reg, BIT(bit), 0);
dev_dbg(npct->dev,
"PRCM GPIOCR: pin %i: alternate-C%i has been disabled\n",
offset, i+1);
}
}
}
reg = gpiocr_regs[pin_desc->altcx[alt_index].reg_index];
bit = pin_desc->altcx[alt_index].control_bit;
dev_dbg(npct->dev, "PRCM GPIOCR: pin %i: alternate-C%i has been selected\n",
offset, alt_index+1);
nmk_write_masked(npct->prcm_base + reg, BIT(bit), BIT(bit));
}
static void nmk_gpio_glitch_slpm_init(unsigned int *slpm)
{
int i;
for (i = 0; i < NUM_BANKS; i++) {
struct nmk_gpio_chip *chip = nmk_gpio_chips[i];
unsigned int temp = slpm[i];
if (!chip)
break;
clk_enable(chip->clk);
slpm[i] = readl(chip->addr + NMK_GPIO_SLPC);
writel(temp, chip->addr + NMK_GPIO_SLPC);
}
}
static void nmk_gpio_glitch_slpm_restore(unsigned int *slpm)
{
int i;
for (i = 0; i < NUM_BANKS; i++) {
struct nmk_gpio_chip *chip = nmk_gpio_chips[i];
if (!chip)
break;
writel(slpm[i], chip->addr + NMK_GPIO_SLPC);
clk_disable(chip->clk);
}
}
static int __maybe_unused nmk_prcm_gpiocr_get_mode(struct pinctrl_dev *pctldev, int gpio)
{
int i;
u16 reg;
u8 bit;
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
const struct prcm_gpiocr_altcx_pin_desc *pin_desc;
const u16 *gpiocr_regs;
if (!npct->prcm_base)
return NMK_GPIO_ALT_C;
for (i = 0; i < npct->soc->npins_altcx; i++) {
if (npct->soc->altcx_pins[i].pin == gpio)
break;
}
if (i == npct->soc->npins_altcx)
return NMK_GPIO_ALT_C;
pin_desc = npct->soc->altcx_pins + i;
gpiocr_regs = npct->soc->prcm_gpiocr_registers;
for (i = 0; i < PRCM_IDX_GPIOCR_ALTC_MAX; i++) {
if (pin_desc->altcx[i].used == true) {
reg = gpiocr_regs[pin_desc->altcx[i].reg_index];
bit = pin_desc->altcx[i].control_bit;
if (readl(npct->prcm_base + reg) & BIT(bit))
return NMK_GPIO_ALT_C+i+1;
}
}
return NMK_GPIO_ALT_C;
}
int nmk_gpio_get_mode(int gpio)
{
struct nmk_gpio_chip *nmk_chip;
u32 afunc, bfunc, bit;
nmk_chip = nmk_gpio_chips[gpio / NMK_GPIO_PER_CHIP];
if (!nmk_chip)
return -EINVAL;
bit = 1 << (gpio % NMK_GPIO_PER_CHIP);
clk_enable(nmk_chip->clk);
afunc = readl(nmk_chip->addr + NMK_GPIO_AFSLA) & bit;
bfunc = readl(nmk_chip->addr + NMK_GPIO_AFSLB) & bit;
clk_disable(nmk_chip->clk);
return (afunc ? NMK_GPIO_ALT_A : 0) | (bfunc ? NMK_GPIO_ALT_B : 0);
}
static inline int nmk_gpio_get_bitmask(int gpio)
{
return 1 << (gpio % NMK_GPIO_PER_CHIP);
}
static void nmk_gpio_irq_ack(struct irq_data *d)
{
struct nmk_gpio_chip *nmk_chip;
nmk_chip = irq_data_get_irq_chip_data(d);
if (!nmk_chip)
return;
clk_enable(nmk_chip->clk);
writel(nmk_gpio_get_bitmask(d->hwirq), nmk_chip->addr + NMK_GPIO_IC);
clk_disable(nmk_chip->clk);
}
static void __nmk_gpio_irq_modify(struct nmk_gpio_chip *nmk_chip,
int gpio, enum nmk_gpio_irq_type which,
bool enable)
{
u32 bitmask = nmk_gpio_get_bitmask(gpio);
u32 *rimscval;
u32 *fimscval;
u32 rimscreg;
u32 fimscreg;
if (which == NORMAL) {
rimscreg = NMK_GPIO_RIMSC;
fimscreg = NMK_GPIO_FIMSC;
rimscval = &nmk_chip->rimsc;
fimscval = &nmk_chip->fimsc;
} else {
rimscreg = NMK_GPIO_RWIMSC;
fimscreg = NMK_GPIO_FWIMSC;
rimscval = &nmk_chip->rwimsc;
fimscval = &nmk_chip->fwimsc;
}
if (nmk_chip->edge_rising & bitmask) {
if (enable)
*rimscval |= bitmask;
else
*rimscval &= ~bitmask;
writel(*rimscval, nmk_chip->addr + rimscreg);
}
if (nmk_chip->edge_falling & bitmask) {
if (enable)
*fimscval |= bitmask;
else
*fimscval &= ~bitmask;
writel(*fimscval, nmk_chip->addr + fimscreg);
}
}
static void __nmk_gpio_set_wake(struct nmk_gpio_chip *nmk_chip,
int gpio, bool on)
{
if (nmk_chip->sleepmode && on) {
__nmk_gpio_set_slpm(nmk_chip, gpio % NMK_GPIO_PER_CHIP,
NMK_GPIO_SLPM_WAKEUP_ENABLE);
}
__nmk_gpio_irq_modify(nmk_chip, gpio, WAKE, on);
}
static int nmk_gpio_irq_maskunmask(struct irq_data *d, bool enable)
{
struct nmk_gpio_chip *nmk_chip;
unsigned long flags;
u32 bitmask;
nmk_chip = irq_data_get_irq_chip_data(d);
bitmask = nmk_gpio_get_bitmask(d->hwirq);
if (!nmk_chip)
return -EINVAL;
clk_enable(nmk_chip->clk);
spin_lock_irqsave(&nmk_gpio_slpm_lock, flags);
spin_lock(&nmk_chip->lock);
__nmk_gpio_irq_modify(nmk_chip, d->hwirq, NORMAL, enable);
if (!(nmk_chip->real_wake & bitmask))
__nmk_gpio_set_wake(nmk_chip, d->hwirq, enable);
spin_unlock(&nmk_chip->lock);
spin_unlock_irqrestore(&nmk_gpio_slpm_lock, flags);
clk_disable(nmk_chip->clk);
return 0;
}
static void nmk_gpio_irq_mask(struct irq_data *d)
{
nmk_gpio_irq_maskunmask(d, false);
}
static void nmk_gpio_irq_unmask(struct irq_data *d)
{
nmk_gpio_irq_maskunmask(d, true);
}
static int nmk_gpio_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct nmk_gpio_chip *nmk_chip;
unsigned long flags;
u32 bitmask;
nmk_chip = irq_data_get_irq_chip_data(d);
if (!nmk_chip)
return -EINVAL;
bitmask = nmk_gpio_get_bitmask(d->hwirq);
clk_enable(nmk_chip->clk);
spin_lock_irqsave(&nmk_gpio_slpm_lock, flags);
spin_lock(&nmk_chip->lock);
if (irqd_irq_disabled(d))
__nmk_gpio_set_wake(nmk_chip, d->hwirq, on);
if (on)
nmk_chip->real_wake |= bitmask;
else
nmk_chip->real_wake &= ~bitmask;
spin_unlock(&nmk_chip->lock);
spin_unlock_irqrestore(&nmk_gpio_slpm_lock, flags);
clk_disable(nmk_chip->clk);
return 0;
}
static int nmk_gpio_irq_set_type(struct irq_data *d, unsigned int type)
{
bool enabled = !irqd_irq_disabled(d);
bool wake = irqd_is_wakeup_set(d);
struct nmk_gpio_chip *nmk_chip;
unsigned long flags;
u32 bitmask;
nmk_chip = irq_data_get_irq_chip_data(d);
bitmask = nmk_gpio_get_bitmask(d->hwirq);
if (!nmk_chip)
return -EINVAL;
if (type & IRQ_TYPE_LEVEL_HIGH)
return -EINVAL;
if (type & IRQ_TYPE_LEVEL_LOW)
return -EINVAL;
clk_enable(nmk_chip->clk);
spin_lock_irqsave(&nmk_chip->lock, flags);
if (enabled)
__nmk_gpio_irq_modify(nmk_chip, d->hwirq, NORMAL, false);
if (enabled || wake)
__nmk_gpio_irq_modify(nmk_chip, d->hwirq, WAKE, false);
nmk_chip->edge_rising &= ~bitmask;
if (type & IRQ_TYPE_EDGE_RISING)
nmk_chip->edge_rising |= bitmask;
nmk_chip->edge_falling &= ~bitmask;
if (type & IRQ_TYPE_EDGE_FALLING)
nmk_chip->edge_falling |= bitmask;
if (enabled)
__nmk_gpio_irq_modify(nmk_chip, d->hwirq, NORMAL, true);
if (enabled || wake)
__nmk_gpio_irq_modify(nmk_chip, d->hwirq, WAKE, true);
spin_unlock_irqrestore(&nmk_chip->lock, flags);
clk_disable(nmk_chip->clk);
return 0;
}
static unsigned int nmk_gpio_irq_startup(struct irq_data *d)
{
struct nmk_gpio_chip *nmk_chip = irq_data_get_irq_chip_data(d);
if (gpio_lock_as_irq(&nmk_chip->chip, d->hwirq))
dev_err(nmk_chip->chip.dev,
"unable to lock HW IRQ %lu for IRQ\n",
d->hwirq);
clk_enable(nmk_chip->clk);
nmk_gpio_irq_unmask(d);
return 0;
}
static void nmk_gpio_irq_shutdown(struct irq_data *d)
{
struct nmk_gpio_chip *nmk_chip = irq_data_get_irq_chip_data(d);
nmk_gpio_irq_mask(d);
clk_disable(nmk_chip->clk);
gpio_unlock_as_irq(&nmk_chip->chip, d->hwirq);
}
static void __nmk_gpio_irq_handler(unsigned int irq, struct irq_desc *desc,
u32 status)
{
struct nmk_gpio_chip *nmk_chip;
struct irq_chip *host_chip = irq_get_chip(irq);
chained_irq_enter(host_chip, desc);
nmk_chip = irq_get_handler_data(irq);
while (status) {
int bit = __ffs(status);
generic_handle_irq(irq_find_mapping(nmk_chip->domain, bit));
status &= ~BIT(bit);
}
chained_irq_exit(host_chip, desc);
}
static void nmk_gpio_irq_handler(unsigned int irq, struct irq_desc *desc)
{
struct nmk_gpio_chip *nmk_chip = irq_get_handler_data(irq);
u32 status;
clk_enable(nmk_chip->clk);
status = readl(nmk_chip->addr + NMK_GPIO_IS);
clk_disable(nmk_chip->clk);
__nmk_gpio_irq_handler(irq, desc, status);
}
static void nmk_gpio_secondary_irq_handler(unsigned int irq,
struct irq_desc *desc)
{
struct nmk_gpio_chip *nmk_chip = irq_get_handler_data(irq);
u32 status = nmk_chip->get_secondary_status(nmk_chip->bank);
__nmk_gpio_irq_handler(irq, desc, status);
}
static int nmk_gpio_init_irq(struct nmk_gpio_chip *nmk_chip)
{
irq_set_chained_handler(nmk_chip->parent_irq, nmk_gpio_irq_handler);
irq_set_handler_data(nmk_chip->parent_irq, nmk_chip);
if (nmk_chip->secondary_parent_irq >= 0) {
irq_set_chained_handler(nmk_chip->secondary_parent_irq,
nmk_gpio_secondary_irq_handler);
irq_set_handler_data(nmk_chip->secondary_parent_irq, nmk_chip);
}
return 0;
}
static int nmk_gpio_request(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
return pinctrl_request_gpio(gpio);
}
static void nmk_gpio_free(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
pinctrl_free_gpio(gpio);
}
static int nmk_gpio_make_input(struct gpio_chip *chip, unsigned offset)
{
struct nmk_gpio_chip *nmk_chip =
container_of(chip, struct nmk_gpio_chip, chip);
clk_enable(nmk_chip->clk);
writel(1 << offset, nmk_chip->addr + NMK_GPIO_DIRC);
clk_disable(nmk_chip->clk);
return 0;
}
static int nmk_gpio_get_input(struct gpio_chip *chip, unsigned offset)
{
struct nmk_gpio_chip *nmk_chip =
container_of(chip, struct nmk_gpio_chip, chip);
u32 bit = 1 << offset;
int value;
clk_enable(nmk_chip->clk);
value = (readl(nmk_chip->addr + NMK_GPIO_DAT) & bit) != 0;
clk_disable(nmk_chip->clk);
return value;
}
static void nmk_gpio_set_output(struct gpio_chip *chip, unsigned offset,
int val)
{
struct nmk_gpio_chip *nmk_chip =
container_of(chip, struct nmk_gpio_chip, chip);
clk_enable(nmk_chip->clk);
__nmk_gpio_set_output(nmk_chip, offset, val);
clk_disable(nmk_chip->clk);
}
static int nmk_gpio_make_output(struct gpio_chip *chip, unsigned offset,
int val)
{
struct nmk_gpio_chip *nmk_chip =
container_of(chip, struct nmk_gpio_chip, chip);
clk_enable(nmk_chip->clk);
__nmk_gpio_make_output(nmk_chip, offset, val);
clk_disable(nmk_chip->clk);
return 0;
}
static int nmk_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct nmk_gpio_chip *nmk_chip =
container_of(chip, struct nmk_gpio_chip, chip);
return irq_create_mapping(nmk_chip->domain, offset);
}
static void nmk_gpio_dbg_show_one(struct seq_file *s,
struct pinctrl_dev *pctldev, struct gpio_chip *chip,
unsigned offset, unsigned gpio)
{
const char *label = gpiochip_is_requested(chip, offset);
struct nmk_gpio_chip *nmk_chip =
container_of(chip, struct nmk_gpio_chip, chip);
int mode;
bool is_out;
bool pull;
u32 bit = 1 << offset;
const char *modes[] = {
[NMK_GPIO_ALT_GPIO] = "gpio",
[NMK_GPIO_ALT_A] = "altA",
[NMK_GPIO_ALT_B] = "altB",
[NMK_GPIO_ALT_C] = "altC",
[NMK_GPIO_ALT_C+1] = "altC1",
[NMK_GPIO_ALT_C+2] = "altC2",
[NMK_GPIO_ALT_C+3] = "altC3",
[NMK_GPIO_ALT_C+4] = "altC4",
};
clk_enable(nmk_chip->clk);
is_out = !!(readl(nmk_chip->addr + NMK_GPIO_DIR) & bit);
pull = !(readl(nmk_chip->addr + NMK_GPIO_PDIS) & bit);
mode = nmk_gpio_get_mode(gpio);
if ((mode == NMK_GPIO_ALT_C) && pctldev)
mode = nmk_prcm_gpiocr_get_mode(pctldev, gpio);
seq_printf(s, " gpio-%-3d (%-20.20s) %s %s %s %s",
gpio, label ?: "(none)",
is_out ? "out" : "in ",
chip->get
? (chip->get(chip, offset) ? "hi" : "lo")
: "? ",
(mode < 0) ? "unknown" : modes[mode],
pull ? "pull" : "none");
if (label && !is_out) {
int irq = gpio_to_irq(gpio);
struct irq_desc *desc = irq_to_desc(irq);
if (irq >= 0 && desc->action) {
char *trigger;
u32 bitmask = nmk_gpio_get_bitmask(gpio);
if (nmk_chip->edge_rising & bitmask)
trigger = "edge-rising";
else if (nmk_chip->edge_falling & bitmask)
trigger = "edge-falling";
else
trigger = "edge-undefined";
seq_printf(s, " irq-%d %s%s",
irq, trigger,
irqd_is_wakeup_set(&desc->irq_data)
? " wakeup" : "");
}
}
clk_disable(nmk_chip->clk);
}
static void nmk_gpio_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
unsigned i;
unsigned gpio = chip->base;
for (i = 0; i < chip->ngpio; i++, gpio++) {
nmk_gpio_dbg_show_one(s, NULL, chip, i, gpio);
seq_printf(s, "\n");
}
}
static inline void nmk_gpio_dbg_show_one(struct seq_file *s,
struct pinctrl_dev *pctldev,
struct gpio_chip *chip,
unsigned offset, unsigned gpio)
{
}
void nmk_gpio_clocks_enable(void)
{
int i;
for (i = 0; i < NUM_BANKS; i++) {
struct nmk_gpio_chip *chip = nmk_gpio_chips[i];
if (!chip)
continue;
clk_enable(chip->clk);
}
}
void nmk_gpio_clocks_disable(void)
{
int i;
for (i = 0; i < NUM_BANKS; i++) {
struct nmk_gpio_chip *chip = nmk_gpio_chips[i];
if (!chip)
continue;
clk_disable(chip->clk);
}
}
void nmk_gpio_wakeups_suspend(void)
{
int i;
for (i = 0; i < NUM_BANKS; i++) {
struct nmk_gpio_chip *chip = nmk_gpio_chips[i];
if (!chip)
break;
clk_enable(chip->clk);
writel(chip->rwimsc & chip->real_wake,
chip->addr + NMK_GPIO_RWIMSC);
writel(chip->fwimsc & chip->real_wake,
chip->addr + NMK_GPIO_FWIMSC);
clk_disable(chip->clk);
}
}
void nmk_gpio_wakeups_resume(void)
{
int i;
for (i = 0; i < NUM_BANKS; i++) {
struct nmk_gpio_chip *chip = nmk_gpio_chips[i];
if (!chip)
break;
clk_enable(chip->clk);
writel(chip->rwimsc, chip->addr + NMK_GPIO_RWIMSC);
writel(chip->fwimsc, chip->addr + NMK_GPIO_FWIMSC);
clk_disable(chip->clk);
}
}
void nmk_gpio_read_pull(int gpio_bank, u32 *pull_up)
{
if (gpio_bank < NUM_BANKS) {
struct nmk_gpio_chip *chip = nmk_gpio_chips[gpio_bank];
if (!chip)
return;
*pull_up = chip->pull_up;
}
}
static int nmk_gpio_irq_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hwirq)
{
struct nmk_gpio_chip *nmk_chip = d->host_data;
if (!nmk_chip)
return -EINVAL;
irq_set_chip_and_handler(irq, &nmk_gpio_irq_chip, handle_edge_irq);
set_irq_flags(irq, IRQF_VALID);
irq_set_chip_data(irq, nmk_chip);
irq_set_irq_type(irq, IRQ_TYPE_EDGE_FALLING);
return 0;
}
static int nmk_gpio_probe(struct platform_device *dev)
{
struct nmk_gpio_platform_data *pdata = dev->dev.platform_data;
struct device_node *np = dev->dev.of_node;
struct nmk_gpio_chip *nmk_chip;
struct gpio_chip *chip;
struct resource *res;
struct clk *clk;
int secondary_irq;
void __iomem *base;
int irq_start = 0;
int irq;
int ret;
if (!pdata && !np) {
dev_err(&dev->dev, "No platform data or device tree found\n");
return -ENODEV;
}
if (np) {
pdata = devm_kzalloc(&dev->dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
if (of_get_property(np, "st,supports-sleepmode", NULL))
pdata->supports_sleepmode = true;
if (of_property_read_u32(np, "gpio-bank", &dev->id)) {
dev_err(&dev->dev, "gpio-bank property not found\n");
return -EINVAL;
}
pdata->first_gpio = dev->id * NMK_GPIO_PER_CHIP;
pdata->num_gpio = NMK_GPIO_PER_CHIP;
}
irq = platform_get_irq(dev, 0);
if (irq < 0)
return irq;
secondary_irq = platform_get_irq(dev, 1);
if (secondary_irq >= 0 && !pdata->get_secondary_status)
return -EINVAL;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&dev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
clk = devm_clk_get(&dev->dev, NULL);
if (IS_ERR(clk))
return PTR_ERR(clk);
clk_prepare(clk);
nmk_chip = devm_kzalloc(&dev->dev, sizeof(*nmk_chip), GFP_KERNEL);
if (!nmk_chip)
return -ENOMEM;
nmk_chip->bank = dev->id;
nmk_chip->clk = clk;
nmk_chip->addr = base;
nmk_chip->chip = nmk_gpio_template;
nmk_chip->parent_irq = irq;
nmk_chip->secondary_parent_irq = secondary_irq;
nmk_chip->get_secondary_status = pdata->get_secondary_status;
nmk_chip->set_ioforce = pdata->set_ioforce;
nmk_chip->sleepmode = pdata->supports_sleepmode;
spin_lock_init(&nmk_chip->lock);
chip = &nmk_chip->chip;
chip->base = pdata->first_gpio;
chip->ngpio = pdata->num_gpio;
chip->label = pdata->name ?: dev_name(&dev->dev);
chip->dev = &dev->dev;
chip->owner = THIS_MODULE;
clk_enable(nmk_chip->clk);
nmk_chip->lowemi = readl_relaxed(nmk_chip->addr + NMK_GPIO_LOWEMI);
clk_disable(nmk_chip->clk);
#ifdef CONFIG_OF_GPIO
chip->of_node = np;
#endif
ret = gpiochip_add(&nmk_chip->chip);
if (ret)
return ret;
BUG_ON(nmk_chip->bank >= ARRAY_SIZE(nmk_gpio_chips));
nmk_gpio_chips[nmk_chip->bank] = nmk_chip;
platform_set_drvdata(dev, nmk_chip);
if (!np)
irq_start = pdata->first_irq;
nmk_chip->domain = irq_domain_add_simple(np,
NMK_GPIO_PER_CHIP, irq_start,
&nmk_gpio_irq_simple_ops, nmk_chip);
if (!nmk_chip->domain) {
dev_err(&dev->dev, "failed to create irqdomain\n");
ret = gpiochip_remove(&nmk_chip->chip);
return -ENOSYS;
}
nmk_gpio_init_irq(nmk_chip);
dev_info(&dev->dev, "at address %p\n", nmk_chip->addr);
return 0;
}
static int nmk_get_groups_cnt(struct pinctrl_dev *pctldev)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
return npct->soc->ngroups;
}
static const char *nmk_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
return npct->soc->groups[selector].name;
}
static int nmk_get_group_pins(struct pinctrl_dev *pctldev, unsigned selector,
const unsigned **pins,
unsigned *num_pins)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
*pins = npct->soc->groups[selector].pins;
*num_pins = npct->soc->groups[selector].npins;
return 0;
}
static struct pinctrl_gpio_range *
nmk_match_gpio_range(struct pinctrl_dev *pctldev, unsigned offset)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
int i;
for (i = 0; i < npct->soc->gpio_num_ranges; i++) {
struct pinctrl_gpio_range *range;
range = &npct->soc->gpio_ranges[i];
if (offset >= range->pin_base &&
offset <= (range->pin_base + range->npins - 1))
return range;
}
return NULL;
}
static void nmk_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned offset)
{
struct pinctrl_gpio_range *range;
struct gpio_chip *chip;
range = nmk_match_gpio_range(pctldev, offset);
if (!range || !range->gc) {
seq_printf(s, "invalid pin offset");
return;
}
chip = range->gc;
nmk_gpio_dbg_show_one(s, pctldev, chip, offset - chip->base, offset);
}
static void nmk_pinctrl_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map, unsigned num_maps)
{
int i;
for (i = 0; i < num_maps; i++)
if (map[i].type == PIN_MAP_TYPE_CONFIGS_PIN)
kfree(map[i].data.configs.configs);
kfree(map);
}
static int nmk_dt_reserve_map(struct pinctrl_map **map, unsigned *reserved_maps,
unsigned *num_maps, unsigned reserve)
{
unsigned old_num = *reserved_maps;
unsigned new_num = *num_maps + reserve;
struct pinctrl_map *new_map;
if (old_num >= new_num)
return 0;
new_map = krealloc(*map, sizeof(*new_map) * new_num, GFP_KERNEL);
if (!new_map)
return -ENOMEM;
memset(new_map + old_num, 0, (new_num - old_num) * sizeof(*new_map));
*map = new_map;
*reserved_maps = new_num;
return 0;
}
static int nmk_dt_add_map_mux(struct pinctrl_map **map, unsigned *reserved_maps,
unsigned *num_maps, const char *group,
const char *function)
{
if (*num_maps == *reserved_maps)
return -ENOSPC;
(*map)[*num_maps].type = PIN_MAP_TYPE_MUX_GROUP;
(*map)[*num_maps].data.mux.group = group;
(*map)[*num_maps].data.mux.function = function;
(*num_maps)++;
return 0;
}
static int nmk_dt_add_map_configs(struct pinctrl_map **map,
unsigned *reserved_maps,
unsigned *num_maps, const char *group,
unsigned long *configs, unsigned num_configs)
{
unsigned long *dup_configs;
if (*num_maps == *reserved_maps)
return -ENOSPC;
dup_configs = kmemdup(configs, num_configs * sizeof(*dup_configs),
GFP_KERNEL);
if (!dup_configs)
return -ENOMEM;
(*map)[*num_maps].type = PIN_MAP_TYPE_CONFIGS_PIN;
(*map)[*num_maps].data.configs.group_or_pin = group;
(*map)[*num_maps].data.configs.configs = dup_configs;
(*map)[*num_maps].data.configs.num_configs = num_configs;
(*num_maps)++;
return 0;
}
static int nmk_dt_pin_config(int index, int val, unsigned long *config)
{
int ret = 0;
if (nmk_cfg_params[index].choice == NULL)
*config = nmk_cfg_params[index].config;
else {
if (val < nmk_cfg_params[index].size) {
*config = nmk_cfg_params[index].config |
nmk_cfg_params[index].choice[val];
}
}
return ret;
}
static const char *nmk_find_pin_name(struct pinctrl_dev *pctldev, const char *pin_name)
{
int i, pin_number;
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
if (sscanf((char *)pin_name, "GPIO%d", &pin_number) == 1)
for (i = 0; i < npct->soc->npins; i++)
if (npct->soc->pins[i].number == pin_number)
return npct->soc->pins[i].name;
return NULL;
}
static bool nmk_pinctrl_dt_get_config(struct device_node *np,
unsigned long *configs)
{
bool has_config = 0;
unsigned long cfg = 0;
int i, val, ret;
for (i = 0; i < ARRAY_SIZE(nmk_cfg_params); i++) {
ret = of_property_read_u32(np,
nmk_cfg_params[i].property, &val);
if (ret != -EINVAL) {
if (nmk_dt_pin_config(i, val, &cfg) == 0) {
*configs |= cfg;
has_config = 1;
}
}
}
return has_config;
}
static int nmk_pinctrl_dt_subnode_to_map(struct pinctrl_dev *pctldev,
struct device_node *np,
struct pinctrl_map **map,
unsigned *reserved_maps,
unsigned *num_maps)
{
int ret;
const char *function = NULL;
unsigned long configs = 0;
bool has_config = 0;
unsigned reserve = 0;
struct property *prop;
const char *group, *gpio_name;
struct device_node *np_config;
ret = of_property_read_string(np, "ste,function", &function);
if (ret >= 0)
reserve = 1;
has_config = nmk_pinctrl_dt_get_config(np, &configs);
np_config = of_parse_phandle(np, "ste,config", 0);
if (np_config)
has_config |= nmk_pinctrl_dt_get_config(np_config, &configs);
ret = of_property_count_strings(np, "ste,pins");
if (ret < 0)
goto exit;
if (has_config)
reserve++;
reserve *= ret;
ret = nmk_dt_reserve_map(map, reserved_maps, num_maps, reserve);
if (ret < 0)
goto exit;
of_property_for_each_string(np, "ste,pins", prop, group) {
if (function) {
ret = nmk_dt_add_map_mux(map, reserved_maps, num_maps,
group, function);
if (ret < 0)
goto exit;
}
if (has_config) {
gpio_name = nmk_find_pin_name(pctldev, group);
ret = nmk_dt_add_map_configs(map, reserved_maps, num_maps,
gpio_name, &configs, 1);
if (ret < 0)
goto exit;
}
}
exit:
return ret;
}
static int nmk_pinctrl_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np_config,
struct pinctrl_map **map, unsigned *num_maps)
{
unsigned reserved_maps;
struct device_node *np;
int ret;
reserved_maps = 0;
*map = NULL;
*num_maps = 0;
for_each_child_of_node(np_config, np) {
ret = nmk_pinctrl_dt_subnode_to_map(pctldev, np, map,
&reserved_maps, num_maps);
if (ret < 0) {
nmk_pinctrl_dt_free_map(pctldev, *map, *num_maps);
return ret;
}
}
return 0;
}
static int nmk_pmx_get_funcs_cnt(struct pinctrl_dev *pctldev)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
return npct->soc->nfunctions;
}
static const char *nmk_pmx_get_func_name(struct pinctrl_dev *pctldev,
unsigned function)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
return npct->soc->functions[function].name;
}
static int nmk_pmx_get_func_groups(struct pinctrl_dev *pctldev,
unsigned function,
const char * const **groups,
unsigned * const num_groups)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
*groups = npct->soc->functions[function].groups;
*num_groups = npct->soc->functions[function].ngroups;
return 0;
}
static int nmk_pmx_enable(struct pinctrl_dev *pctldev, unsigned function,
unsigned group)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
const struct nmk_pingroup *g;
static unsigned int slpm[NUM_BANKS];
unsigned long flags = 0;
bool glitch;
int ret = -EINVAL;
int i;
g = &npct->soc->groups[group];
if (g->altsetting < 0)
return -EINVAL;
dev_dbg(npct->dev, "enable group %s, %u pins\n", g->name, g->npins);
glitch = ((g->altsetting & NMK_GPIO_ALT_C) == NMK_GPIO_ALT_C);
if (glitch) {
spin_lock_irqsave(&nmk_gpio_slpm_lock, flags);
memset(slpm, 0xff, sizeof(slpm));
for (i = 0; i < g->npins; i++)
slpm[g->pins[i] / NMK_GPIO_PER_CHIP] &= ~BIT(g->pins[i]);
nmk_gpio_glitch_slpm_init(slpm);
}
for (i = 0; i < g->npins; i++) {
struct pinctrl_gpio_range *range;
struct nmk_gpio_chip *nmk_chip;
struct gpio_chip *chip;
unsigned bit;
range = nmk_match_gpio_range(pctldev, g->pins[i]);
if (!range) {
dev_err(npct->dev,
"invalid pin offset %d in group %s at index %d\n",
g->pins[i], g->name, i);
goto out_glitch;
}
if (!range->gc) {
dev_err(npct->dev, "GPIO chip missing in range for pin offset %d in group %s at index %d\n",
g->pins[i], g->name, i);
goto out_glitch;
}
chip = range->gc;
nmk_chip = container_of(chip, struct nmk_gpio_chip, chip);
dev_dbg(npct->dev, "setting pin %d to altsetting %d\n", g->pins[i], g->altsetting);
clk_enable(nmk_chip->clk);
bit = g->pins[i] % NMK_GPIO_PER_CHIP;
nmk_gpio_disable_lazy_irq(nmk_chip, bit);
__nmk_gpio_set_mode_safe(nmk_chip, bit,
(g->altsetting & NMK_GPIO_ALT_C), glitch);
clk_disable(nmk_chip->clk);
if ((g->altsetting & NMK_GPIO_ALT_C) == NMK_GPIO_ALT_C)
nmk_prcm_altcx_set_mode(npct, g->pins[i],
g->altsetting >> NMK_GPIO_ALT_CX_SHIFT);
}
ret = 0;
out_glitch:
if (glitch) {
nmk_gpio_glitch_slpm_restore(slpm);
spin_unlock_irqrestore(&nmk_gpio_slpm_lock, flags);
}
return ret;
}
static void nmk_pmx_disable(struct pinctrl_dev *pctldev,
unsigned function, unsigned group)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
const struct nmk_pingroup *g;
g = &npct->soc->groups[group];
if (g->altsetting < 0)
return;
dev_dbg(npct->dev, "disable group %s, %u pins\n", g->name, g->npins);
}
static int nmk_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
struct nmk_gpio_chip *nmk_chip;
struct gpio_chip *chip;
unsigned bit;
if (!range) {
dev_err(npct->dev, "invalid range\n");
return -EINVAL;
}
if (!range->gc) {
dev_err(npct->dev, "missing GPIO chip in range\n");
return -EINVAL;
}
chip = range->gc;
nmk_chip = container_of(chip, struct nmk_gpio_chip, chip);
dev_dbg(npct->dev, "enable pin %u as GPIO\n", offset);
clk_enable(nmk_chip->clk);
bit = offset % NMK_GPIO_PER_CHIP;
__nmk_gpio_set_mode(nmk_chip, bit, NMK_GPIO_ALT_GPIO);
clk_disable(nmk_chip->clk);
return 0;
}
static void nmk_gpio_disable_free(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
dev_dbg(npct->dev, "disable pin %u as GPIO\n", offset);
}
static int nmk_pin_config_get(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
return -EINVAL;
}
static int nmk_pin_config_set(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *configs, unsigned num_configs)
{
static const char *pullnames[] = {
[NMK_GPIO_PULL_NONE] = "none",
[NMK_GPIO_PULL_UP] = "up",
[NMK_GPIO_PULL_DOWN] = "down",
[3] = "??"
};
static const char *slpmnames[] = {
[NMK_GPIO_SLPM_INPUT] = "input/wakeup",
[NMK_GPIO_SLPM_NOCHANGE] = "no-change/no-wakeup",
};
struct nmk_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
struct nmk_gpio_chip *nmk_chip;
struct pinctrl_gpio_range *range;
struct gpio_chip *chip;
unsigned bit;
pin_cfg_t cfg;
int pull, slpm, output, val, i;
bool lowemi, gpiomode, sleep;
range = nmk_match_gpio_range(pctldev, pin);
if (!range) {
dev_err(npct->dev, "invalid pin offset %d\n", pin);
return -EINVAL;
}
if (!range->gc) {
dev_err(npct->dev, "GPIO chip missing in range for pin %d\n",
pin);
return -EINVAL;
}
chip = range->gc;
nmk_chip = container_of(chip, struct nmk_gpio_chip, chip);
for (i = 0; i < num_configs; i++) {
cfg = (pin_cfg_t) configs[i];
pull = PIN_PULL(cfg);
slpm = PIN_SLPM(cfg);
output = PIN_DIR(cfg);
val = PIN_VAL(cfg);
lowemi = PIN_LOWEMI(cfg);
gpiomode = PIN_GPIOMODE(cfg);
sleep = PIN_SLEEPMODE(cfg);
if (sleep) {
int slpm_pull = PIN_SLPM_PULL(cfg);
int slpm_output = PIN_SLPM_DIR(cfg);
int slpm_val = PIN_SLPM_VAL(cfg);
gpiomode = true;
if (slpm_pull)
pull = slpm_pull - 1;
if (slpm_output)
output = slpm_output - 1;
if (slpm_val)
val = slpm_val - 1;
dev_dbg(nmk_chip->chip.dev,
"pin %d: sleep pull %s, dir %s, val %s\n",
pin,
slpm_pull ? pullnames[pull] : "same",
slpm_output ? (output ? "output" : "input")
: "same",
slpm_val ? (val ? "high" : "low") : "same");
}
dev_dbg(nmk_chip->chip.dev,
"pin %d [%#lx]: pull %s, slpm %s (%s%s), lowemi %s\n",
pin, cfg, pullnames[pull], slpmnames[slpm],
output ? "output " : "input",
output ? (val ? "high" : "low") : "",
lowemi ? "on" : "off");
clk_enable(nmk_chip->clk);
bit = pin % NMK_GPIO_PER_CHIP;
if (gpiomode)
__nmk_gpio_set_mode(nmk_chip, bit, NMK_GPIO_ALT_GPIO);
if (output)
__nmk_gpio_make_output(nmk_chip, bit, val);
else {
__nmk_gpio_make_input(nmk_chip, bit);
__nmk_gpio_set_pull(nmk_chip, bit, pull);
}
__nmk_gpio_set_lowemi(nmk_chip, bit, lowemi);
__nmk_gpio_set_slpm(nmk_chip, bit, slpm);
clk_disable(nmk_chip->clk);
}
return 0;
}
static int nmk_pinctrl_suspend(struct platform_device *pdev, pm_message_t state)
{
struct nmk_pinctrl *npct;
npct = platform_get_drvdata(pdev);
if (!npct)
return -EINVAL;
return pinctrl_force_sleep(npct->pctl);
}
static int nmk_pinctrl_resume(struct platform_device *pdev)
{
struct nmk_pinctrl *npct;
npct = platform_get_drvdata(pdev);
if (!npct)
return -EINVAL;
return pinctrl_force_default(npct->pctl);
}
static int nmk_pinctrl_probe(struct platform_device *pdev)
{
const struct platform_device_id *platid = platform_get_device_id(pdev);
struct device_node *np = pdev->dev.of_node;
struct device_node *prcm_np;
struct nmk_pinctrl *npct;
struct resource *res;
unsigned int version = 0;
int i;
npct = devm_kzalloc(&pdev->dev, sizeof(*npct), GFP_KERNEL);
if (!npct)
return -ENOMEM;
if (platid)
version = platid->driver_data;
else if (np) {
const struct of_device_id *match;
match = of_match_device(nmk_pinctrl_match, &pdev->dev);
if (!match)
return -ENODEV;
version = (unsigned int) match->data;
}
if (version == PINCTRL_NMK_STN8815)
nmk_pinctrl_stn8815_init(&npct->soc);
if (version == PINCTRL_NMK_DB8500)
nmk_pinctrl_db8500_init(&npct->soc);
if (version == PINCTRL_NMK_DB8540)
nmk_pinctrl_db8540_init(&npct->soc);
if (np) {
prcm_np = of_parse_phandle(np, "prcm", 0);
if (prcm_np)
npct->prcm_base = of_iomap(prcm_np, 0);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res)
npct->prcm_base = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!npct->prcm_base) {
if (version == PINCTRL_NMK_STN8815) {
dev_info(&pdev->dev,
"No PRCM base, "
"assuming no ALT-Cx control is available\n");
} else {
dev_err(&pdev->dev, "missing PRCM base address\n");
return -EINVAL;
}
}
for (i = 0; i < npct->soc->gpio_num_ranges; i++) {
if (!nmk_gpio_chips[npct->soc->gpio_ranges[i].id]) {
dev_warn(&pdev->dev, "GPIO chip %d not registered yet\n", i);
return -EPROBE_DEFER;
}
npct->soc->gpio_ranges[i].gc = &nmk_gpio_chips[npct->soc->gpio_ranges[i].id]->chip;
}
nmk_pinctrl_desc.pins = npct->soc->pins;
nmk_pinctrl_desc.npins = npct->soc->npins;
npct->dev = &pdev->dev;
npct->pctl = pinctrl_register(&nmk_pinctrl_desc, &pdev->dev, npct);
if (!npct->pctl) {
dev_err(&pdev->dev, "could not register Nomadik pinctrl driver\n");
return -EINVAL;
}
for (i = 0; i < npct->soc->gpio_num_ranges; i++)
pinctrl_add_gpio_range(npct->pctl, &npct->soc->gpio_ranges[i]);
platform_set_drvdata(pdev, npct);
dev_info(&pdev->dev, "initialized Nomadik pin control driver\n");
return 0;
}
static int __init nmk_gpio_init(void)
{
int ret;
ret = platform_driver_register(&nmk_gpio_driver);
if (ret)
return ret;
return platform_driver_register(&nmk_pinctrl_driver);
}
