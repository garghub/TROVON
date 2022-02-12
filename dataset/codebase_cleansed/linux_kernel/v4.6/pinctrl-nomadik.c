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
int irq = irq_find_mapping(nmk_chip->chip.irqdomain, offset);
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
dev_dbg(nmk_chip->chip.parent, "%d: clearing interrupt mask\n", gpio);
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
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
struct nmk_gpio_chip *nmk_chip = gpiochip_get_data(chip);
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
clk_enable(nmk_chip->clk);
nmk_gpio_irq_unmask(d);
return 0;
}
static void nmk_gpio_irq_shutdown(struct irq_data *d)
{
struct nmk_gpio_chip *nmk_chip = irq_data_get_irq_chip_data(d);
nmk_gpio_irq_mask(d);
clk_disable(nmk_chip->clk);
}
static void __nmk_gpio_irq_handler(struct irq_desc *desc, u32 status)
{
struct irq_chip *host_chip = irq_desc_get_chip(desc);
struct gpio_chip *chip = irq_desc_get_handler_data(desc);
chained_irq_enter(host_chip, desc);
while (status) {
int bit = __ffs(status);
generic_handle_irq(irq_find_mapping(chip->irqdomain, bit));
status &= ~BIT(bit);
}
chained_irq_exit(host_chip, desc);
}
static void nmk_gpio_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *chip = irq_desc_get_handler_data(desc);
struct nmk_gpio_chip *nmk_chip = gpiochip_get_data(chip);
u32 status;
clk_enable(nmk_chip->clk);
status = readl(nmk_chip->addr + NMK_GPIO_IS);
clk_disable(nmk_chip->clk);
__nmk_gpio_irq_handler(desc, status);
}
static void nmk_gpio_latent_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *chip = irq_desc_get_handler_data(desc);
struct nmk_gpio_chip *nmk_chip = gpiochip_get_data(chip);
u32 status = nmk_chip->get_latent_status(nmk_chip->bank);
__nmk_gpio_irq_handler(desc, status);
}
static int nmk_gpio_make_input(struct gpio_chip *chip, unsigned offset)
{
struct nmk_gpio_chip *nmk_chip = gpiochip_get_data(chip);
clk_enable(nmk_chip->clk);
writel(1 << offset, nmk_chip->addr + NMK_GPIO_DIRC);
clk_disable(nmk_chip->clk);
return 0;
}
static int nmk_gpio_get_input(struct gpio_chip *chip, unsigned offset)
{
struct nmk_gpio_chip *nmk_chip = gpiochip_get_data(chip);
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
struct nmk_gpio_chip *nmk_chip = gpiochip_get_data(chip);
clk_enable(nmk_chip->clk);
__nmk_gpio_set_output(nmk_chip, offset, val);
clk_disable(nmk_chip->clk);
}
static int nmk_gpio_make_output(struct gpio_chip *chip, unsigned offset,
int val)
{
struct nmk_gpio_chip *nmk_chip = gpiochip_get_data(chip);
clk_enable(nmk_chip->clk);
__nmk_gpio_make_output(nmk_chip, offset, val);
clk_disable(nmk_chip->clk);
return 0;
}
static void nmk_gpio_dbg_show_one(struct seq_file *s,
struct pinctrl_dev *pctldev, struct gpio_chip *chip,
unsigned offset, unsigned gpio)
{
const char *label = gpiochip_is_requested(chip, offset);
struct nmk_gpio_chip *nmk_chip = gpiochip_get_data(chip);
int mode;
bool is_out;
bool data_out;
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
const char *pulls[] = {
"none ",
"pull down",
"pull up ",
};
clk_enable(nmk_chip->clk);
is_out = !!(readl(nmk_chip->addr + NMK_GPIO_DIR) & bit);
pull = !(readl(nmk_chip->addr + NMK_GPIO_PDIS) & bit);
data_out = !!(readl(nmk_chip->addr + NMK_GPIO_DAT) & bit);
mode = nmk_gpio_get_mode(gpio);
if ((mode == NMK_GPIO_ALT_C) && pctldev)
mode = nmk_prcm_gpiocr_get_mode(pctldev, gpio);
if (is_out) {
seq_printf(s, " gpio-%-3d (%-20.20s) out %s %s",
gpio,
label ?: "(none)",
data_out ? "hi" : "lo",
(mode < 0) ? "unknown" : modes[mode]);
} else {
int irq = gpio_to_irq(gpio);
struct irq_desc *desc = irq_to_desc(irq);
int pullidx = 0;
int val;
if (pull)
pullidx = data_out ? 2 : 1;
seq_printf(s, " gpio-%-3d (%-20.20s) in %s %s",
gpio,
label ?: "(none)",
pulls[pullidx],
(mode < 0) ? "unknown" : modes[mode]);
val = nmk_gpio_get_input(chip, offset);
seq_printf(s, " VAL %d", val);
if (irq > 0 && desc && desc->action) {
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
static struct nmk_gpio_chip *nmk_gpio_populate_chip(struct device_node *np,
struct platform_device *pdev)
{
struct nmk_gpio_chip *nmk_chip;
struct platform_device *gpio_pdev;
struct gpio_chip *chip;
struct resource *res;
struct clk *clk;
void __iomem *base;
u32 id;
gpio_pdev = of_find_device_by_node(np);
if (!gpio_pdev) {
pr_err("populate \"%s\": device not found\n", np->name);
return ERR_PTR(-ENODEV);
}
if (of_property_read_u32(np, "gpio-bank", &id)) {
dev_err(&pdev->dev, "populate: gpio-bank property not found\n");
return ERR_PTR(-EINVAL);
}
nmk_chip = nmk_gpio_chips[id];
if (nmk_chip)
return nmk_chip;
nmk_chip = devm_kzalloc(&pdev->dev, sizeof(*nmk_chip), GFP_KERNEL);
if (!nmk_chip)
return ERR_PTR(-ENOMEM);
nmk_chip->bank = id;
chip = &nmk_chip->chip;
chip->base = id * NMK_GPIO_PER_CHIP;
chip->ngpio = NMK_GPIO_PER_CHIP;
chip->label = dev_name(&gpio_pdev->dev);
chip->parent = &gpio_pdev->dev;
res = platform_get_resource(gpio_pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return base;
nmk_chip->addr = base;
clk = clk_get(&gpio_pdev->dev, NULL);
if (IS_ERR(clk))
return (void *) clk;
clk_prepare(clk);
nmk_chip->clk = clk;
BUG_ON(nmk_chip->bank >= ARRAY_SIZE(nmk_gpio_chips));
nmk_gpio_chips[id] = nmk_chip;
return nmk_chip;
}
static int nmk_gpio_probe(struct platform_device *dev)
{
struct device_node *np = dev->dev.of_node;
struct nmk_gpio_chip *nmk_chip;
struct gpio_chip *chip;
struct irq_chip *irqchip;
int latent_irq;
bool supports_sleepmode;
int irq;
int ret;
nmk_chip = nmk_gpio_populate_chip(np, dev);
if (IS_ERR(nmk_chip)) {
dev_err(&dev->dev, "could not populate nmk chip struct\n");
return PTR_ERR(nmk_chip);
}
if (of_get_property(np, "st,supports-sleepmode", NULL))
supports_sleepmode = true;
else
supports_sleepmode = false;
dev->id = nmk_chip->bank;
irq = platform_get_irq(dev, 0);
if (irq < 0)
return irq;
latent_irq = platform_get_irq(dev, 1);
nmk_chip->parent_irq = irq;
nmk_chip->latent_parent_irq = latent_irq;
nmk_chip->sleepmode = supports_sleepmode;
spin_lock_init(&nmk_chip->lock);
chip = &nmk_chip->chip;
chip->request = gpiochip_generic_request;
chip->free = gpiochip_generic_free;
chip->direction_input = nmk_gpio_make_input;
chip->get = nmk_gpio_get_input;
chip->direction_output = nmk_gpio_make_output;
chip->set = nmk_gpio_set_output;
chip->dbg_show = nmk_gpio_dbg_show;
chip->can_sleep = false;
chip->owner = THIS_MODULE;
irqchip = &nmk_chip->irqchip;
irqchip->irq_ack = nmk_gpio_irq_ack;
irqchip->irq_mask = nmk_gpio_irq_mask;
irqchip->irq_unmask = nmk_gpio_irq_unmask;
irqchip->irq_set_type = nmk_gpio_irq_set_type;
irqchip->irq_set_wake = nmk_gpio_irq_set_wake;
irqchip->irq_startup = nmk_gpio_irq_startup;
irqchip->irq_shutdown = nmk_gpio_irq_shutdown;
irqchip->flags = IRQCHIP_MASK_ON_SUSPEND;
irqchip->name = kasprintf(GFP_KERNEL, "nmk%u-%u-%u",
dev->id,
chip->base,
chip->base + chip->ngpio - 1);
clk_enable(nmk_chip->clk);
nmk_chip->lowemi = readl_relaxed(nmk_chip->addr + NMK_GPIO_LOWEMI);
clk_disable(nmk_chip->clk);
chip->of_node = np;
ret = gpiochip_add_data(chip, nmk_chip);
if (ret)
return ret;
platform_set_drvdata(dev, nmk_chip);
ret = gpiochip_irqchip_add(chip,
irqchip,
0,
handle_edge_irq,
IRQ_TYPE_EDGE_FALLING);
if (ret) {
dev_err(&dev->dev, "could not add irqchip\n");
gpiochip_remove(&nmk_chip->chip);
return -ENODEV;
}
gpiochip_set_chained_irqchip(chip,
irqchip,
nmk_chip->parent_irq,
nmk_gpio_irq_handler);
if (nmk_chip->latent_parent_irq > 0)
gpiochip_set_chained_irqchip(chip,
irqchip,
nmk_chip->latent_parent_irq,
nmk_gpio_latent_irq_handler);
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
static struct nmk_gpio_chip *find_nmk_gpio_from_pin(unsigned pin)
{
int i;
struct nmk_gpio_chip *nmk_gpio;
for(i = 0; i < NMK_MAX_BANKS; i++) {
nmk_gpio = nmk_gpio_chips[i];
if (!nmk_gpio)
continue;
if (pin >= nmk_gpio->chip.base &&
pin < nmk_gpio->chip.base + nmk_gpio->chip.ngpio)
return nmk_gpio;
}
return NULL;
}
static struct gpio_chip *find_gc_from_pin(unsigned pin)
{
struct nmk_gpio_chip *nmk_gpio = find_nmk_gpio_from_pin(pin);
if (nmk_gpio)
return &nmk_gpio->chip;
return NULL;
}
static void nmk_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned offset)
{
struct gpio_chip *chip = find_gc_from_pin(offset);
if (!chip) {
seq_printf(s, "invalid pin offset");
return;
}
nmk_gpio_dbg_show_one(s, pctldev, chip, offset - chip->base, offset);
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
struct property *prop;
struct device_node *np_config;
ret = of_property_read_string(np, "function", &function);
if (ret >= 0) {
const char *group;
ret = of_property_count_strings(np, "groups");
if (ret < 0)
goto exit;
ret = pinctrl_utils_reserve_map(pctldev, map,
reserved_maps,
num_maps, ret);
if (ret < 0)
goto exit;
of_property_for_each_string(np, "groups", prop, group) {
ret = nmk_dt_add_map_mux(map, reserved_maps, num_maps,
group, function);
if (ret < 0)
goto exit;
}
}
has_config = nmk_pinctrl_dt_get_config(np, &configs);
np_config = of_parse_phandle(np, "ste,config", 0);
if (np_config)
has_config |= nmk_pinctrl_dt_get_config(np_config, &configs);
if (has_config) {
const char *gpio_name;
const char *pin;
ret = of_property_count_strings(np, "pins");
if (ret < 0)
goto exit;
ret = pinctrl_utils_reserve_map(pctldev, map,
reserved_maps,
num_maps, ret);
if (ret < 0)
goto exit;
of_property_for_each_string(np, "pins", prop, pin) {
gpio_name = nmk_find_pin_name(pctldev, pin);
ret = nmk_dt_add_map_configs(map, reserved_maps,
num_maps,
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
pinctrl_utils_dt_free_map(pctldev, *map, *num_maps);
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
static int nmk_pmx_set(struct pinctrl_dev *pctldev, unsigned function,
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
struct nmk_gpio_chip *nmk_chip;
unsigned bit;
nmk_chip = find_nmk_gpio_from_pin(g->pins[i]);
if (!nmk_chip) {
dev_err(npct->dev,
"invalid pin offset %d in group %s at index %d\n",
g->pins[i], g->name, i);
goto out_glitch;
}
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
nmk_chip = gpiochip_get_data(chip);
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
unsigned bit;
pin_cfg_t cfg;
int pull, slpm, output, val, i;
bool lowemi, gpiomode, sleep;
nmk_chip = find_nmk_gpio_from_pin(pin);
if (!nmk_chip) {
dev_err(npct->dev,
"invalid pin offset %d\n", pin);
return -EINVAL;
}
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
dev_dbg(nmk_chip->chip.parent,
"pin %d: sleep pull %s, dir %s, val %s\n",
pin,
slpm_pull ? pullnames[pull] : "same",
slpm_output ? (output ? "output" : "input")
: "same",
slpm_val ? (val ? "high" : "low") : "same");
}
dev_dbg(nmk_chip->chip.parent,
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
static int nmk_pinctrl_suspend(struct device *dev)
{
struct nmk_pinctrl *npct;
npct = dev_get_drvdata(dev);
if (!npct)
return -EINVAL;
return pinctrl_force_sleep(npct->pctl);
}
static int nmk_pinctrl_resume(struct device *dev)
{
struct nmk_pinctrl *npct;
npct = dev_get_drvdata(dev);
if (!npct)
return -EINVAL;
return pinctrl_force_default(npct->pctl);
}
static int nmk_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct device_node *np = pdev->dev.of_node;
struct device_node *prcm_np;
struct nmk_pinctrl *npct;
unsigned int version = 0;
int i;
npct = devm_kzalloc(&pdev->dev, sizeof(*npct), GFP_KERNEL);
if (!npct)
return -ENOMEM;
match = of_match_device(nmk_pinctrl_match, &pdev->dev);
if (!match)
return -ENODEV;
version = (unsigned int) match->data;
if (version == PINCTRL_NMK_STN8815)
nmk_pinctrl_stn8815_init(&npct->soc);
if (version == PINCTRL_NMK_DB8500)
nmk_pinctrl_db8500_init(&npct->soc);
if (version == PINCTRL_NMK_DB8540)
nmk_pinctrl_db8540_init(&npct->soc);
for (i = 0; i < NMK_MAX_BANKS; i++) {
struct device_node *gpio_np;
struct nmk_gpio_chip *nmk_chip;
gpio_np = of_parse_phandle(np, "nomadik-gpio-chips", i);
if (gpio_np) {
dev_info(&pdev->dev,
"populate NMK GPIO %d \"%s\"\n",
i, gpio_np->name);
nmk_chip = nmk_gpio_populate_chip(gpio_np, pdev);
if (IS_ERR(nmk_chip))
dev_err(&pdev->dev,
"could not populate nmk chip struct "
"- continue anyway\n");
of_node_put(gpio_np);
}
}
prcm_np = of_parse_phandle(np, "prcm", 0);
if (prcm_np)
npct->prcm_base = of_iomap(prcm_np, 0);
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
nmk_pinctrl_desc.pins = npct->soc->pins;
nmk_pinctrl_desc.npins = npct->soc->npins;
npct->dev = &pdev->dev;
npct->pctl = pinctrl_register(&nmk_pinctrl_desc, &pdev->dev, npct);
if (IS_ERR(npct->pctl)) {
dev_err(&pdev->dev, "could not register Nomadik pinctrl driver\n");
return PTR_ERR(npct->pctl);
}
platform_set_drvdata(pdev, npct);
dev_info(&pdev->dev, "initialized Nomadik pin control driver\n");
return 0;
}
static int __init nmk_gpio_init(void)
{
return platform_driver_register(&nmk_gpio_driver);
}
static int __init nmk_pinctrl_init(void)
{
return platform_driver_register(&nmk_pinctrl_driver);
}
