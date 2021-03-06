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
u32 rwimsc = readl(nmk_chip->addr + NMK_GPIO_RWIMSC);
u32 fwimsc = readl(nmk_chip->addr + NMK_GPIO_FWIMSC);
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
static void __nmk_config_pin(struct nmk_gpio_chip *nmk_chip, unsigned offset,
pin_cfg_t cfg, bool sleep, unsigned int *slpmregs)
{
static const char *afnames[] = {
[NMK_GPIO_ALT_GPIO] = "GPIO",
[NMK_GPIO_ALT_A] = "A",
[NMK_GPIO_ALT_B] = "B",
[NMK_GPIO_ALT_C] = "C"
};
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
int pin = PIN_NUM(cfg);
int pull = PIN_PULL(cfg);
int af = PIN_ALT(cfg);
int slpm = PIN_SLPM(cfg);
int output = PIN_DIR(cfg);
int val = PIN_VAL(cfg);
bool glitch = af == NMK_GPIO_ALT_C;
dev_dbg(nmk_chip->chip.dev, "pin %d [%#lx]: af %s, pull %s, slpm %s (%s%s)\n",
pin, cfg, afnames[af], pullnames[pull], slpmnames[slpm],
output ? "output " : "input",
output ? (val ? "high" : "low") : "");
if (sleep) {
int slpm_pull = PIN_SLPM_PULL(cfg);
int slpm_output = PIN_SLPM_DIR(cfg);
int slpm_val = PIN_SLPM_VAL(cfg);
af = NMK_GPIO_ALT_GPIO;
if (slpm_pull)
pull = slpm_pull - 1;
if (slpm_output)
output = slpm_output - 1;
if (slpm_val)
val = slpm_val - 1;
dev_dbg(nmk_chip->chip.dev, "pin %d: sleep pull %s, dir %s, val %s\n",
pin,
slpm_pull ? pullnames[pull] : "same",
slpm_output ? (output ? "output" : "input") : "same",
slpm_val ? (val ? "high" : "low") : "same");
}
if (output)
__nmk_gpio_make_output(nmk_chip, offset, val);
else {
__nmk_gpio_make_input(nmk_chip, offset);
__nmk_gpio_set_pull(nmk_chip, offset, pull);
}
if (slpmregs) {
if (slpm == NMK_GPIO_SLPM_NOCHANGE)
slpmregs[nmk_chip->bank] |= BIT(offset);
else
slpmregs[nmk_chip->bank] &= ~BIT(offset);
} else
__nmk_gpio_set_slpm(nmk_chip, offset, slpm);
__nmk_gpio_set_mode_safe(nmk_chip, offset, af, glitch);
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
static int __nmk_config_pins(pin_cfg_t *cfgs, int num, bool sleep)
{
static unsigned int slpm[NUM_BANKS];
unsigned long flags;
bool glitch = false;
int ret = 0;
int i;
for (i = 0; i < num; i++) {
if (PIN_ALT(cfgs[i]) == NMK_GPIO_ALT_C) {
glitch = true;
break;
}
}
spin_lock_irqsave(&nmk_gpio_slpm_lock, flags);
if (glitch) {
memset(slpm, 0xff, sizeof(slpm));
for (i = 0; i < num; i++) {
int pin = PIN_NUM(cfgs[i]);
int offset = pin % NMK_GPIO_PER_CHIP;
if (PIN_ALT(cfgs[i]) == NMK_GPIO_ALT_C)
slpm[pin / NMK_GPIO_PER_CHIP] &= ~BIT(offset);
}
nmk_gpio_glitch_slpm_init(slpm);
}
for (i = 0; i < num; i++) {
struct nmk_gpio_chip *nmk_chip;
int pin = PIN_NUM(cfgs[i]);
nmk_chip = irq_get_chip_data(NOMADIK_GPIO_TO_IRQ(pin));
if (!nmk_chip) {
ret = -EINVAL;
break;
}
clk_enable(nmk_chip->clk);
spin_lock(&nmk_chip->lock);
__nmk_config_pin(nmk_chip, pin - nmk_chip->chip.base,
cfgs[i], sleep, glitch ? slpm : NULL);
spin_unlock(&nmk_chip->lock);
clk_disable(nmk_chip->clk);
}
if (glitch)
nmk_gpio_glitch_slpm_restore(slpm);
spin_unlock_irqrestore(&nmk_gpio_slpm_lock, flags);
return ret;
}
int nmk_config_pin(pin_cfg_t cfg, bool sleep)
{
return __nmk_config_pins(&cfg, 1, sleep);
}
int nmk_config_pins(pin_cfg_t *cfgs, int num)
{
return __nmk_config_pins(cfgs, num, false);
}
int nmk_config_pins_sleep(pin_cfg_t *cfgs, int num)
{
return __nmk_config_pins(cfgs, num, true);
}
int nmk_gpio_set_slpm(int gpio, enum nmk_gpio_slpm mode)
{
struct nmk_gpio_chip *nmk_chip;
unsigned long flags;
nmk_chip = irq_get_chip_data(NOMADIK_GPIO_TO_IRQ(gpio));
if (!nmk_chip)
return -EINVAL;
clk_enable(nmk_chip->clk);
spin_lock_irqsave(&nmk_gpio_slpm_lock, flags);
spin_lock(&nmk_chip->lock);
__nmk_gpio_set_slpm(nmk_chip, gpio - nmk_chip->chip.base, mode);
spin_unlock(&nmk_chip->lock);
spin_unlock_irqrestore(&nmk_gpio_slpm_lock, flags);
clk_disable(nmk_chip->clk);
return 0;
}
int nmk_gpio_set_pull(int gpio, enum nmk_gpio_pull pull)
{
struct nmk_gpio_chip *nmk_chip;
unsigned long flags;
nmk_chip = irq_get_chip_data(NOMADIK_GPIO_TO_IRQ(gpio));
if (!nmk_chip)
return -EINVAL;
clk_enable(nmk_chip->clk);
spin_lock_irqsave(&nmk_chip->lock, flags);
__nmk_gpio_set_pull(nmk_chip, gpio - nmk_chip->chip.base, pull);
spin_unlock_irqrestore(&nmk_chip->lock, flags);
clk_disable(nmk_chip->clk);
return 0;
}
int nmk_gpio_set_mode(int gpio, int gpio_mode)
{
struct nmk_gpio_chip *nmk_chip;
unsigned long flags;
nmk_chip = irq_get_chip_data(NOMADIK_GPIO_TO_IRQ(gpio));
if (!nmk_chip)
return -EINVAL;
clk_enable(nmk_chip->clk);
spin_lock_irqsave(&nmk_chip->lock, flags);
__nmk_gpio_set_mode(nmk_chip, gpio - nmk_chip->chip.base, gpio_mode);
spin_unlock_irqrestore(&nmk_chip->lock, flags);
clk_disable(nmk_chip->clk);
return 0;
}
int nmk_gpio_get_mode(int gpio)
{
struct nmk_gpio_chip *nmk_chip;
u32 afunc, bfunc, bit;
nmk_chip = irq_get_chip_data(NOMADIK_GPIO_TO_IRQ(gpio));
if (!nmk_chip)
return -EINVAL;
bit = 1 << (gpio - nmk_chip->chip.base);
clk_enable(nmk_chip->clk);
afunc = readl(nmk_chip->addr + NMK_GPIO_AFSLA) & bit;
bfunc = readl(nmk_chip->addr + NMK_GPIO_AFSLB) & bit;
clk_disable(nmk_chip->clk);
return (afunc ? NMK_GPIO_ALT_A : 0) | (bfunc ? NMK_GPIO_ALT_B : 0);
}
static inline int nmk_gpio_get_bitmask(int gpio)
{
return 1 << (gpio % 32);
}
static void nmk_gpio_irq_ack(struct irq_data *d)
{
int gpio;
struct nmk_gpio_chip *nmk_chip;
gpio = NOMADIK_IRQ_TO_GPIO(d->irq);
nmk_chip = irq_data_get_irq_chip_data(d);
if (!nmk_chip)
return;
clk_enable(nmk_chip->clk);
writel(nmk_gpio_get_bitmask(gpio), nmk_chip->addr + NMK_GPIO_IC);
clk_disable(nmk_chip->clk);
}
static void __nmk_gpio_irq_modify(struct nmk_gpio_chip *nmk_chip,
int gpio, enum nmk_gpio_irq_type which,
bool enable)
{
u32 rimsc = which == WAKE ? NMK_GPIO_RWIMSC : NMK_GPIO_RIMSC;
u32 fimsc = which == WAKE ? NMK_GPIO_FWIMSC : NMK_GPIO_FIMSC;
u32 bitmask = nmk_gpio_get_bitmask(gpio);
u32 reg;
if (nmk_chip->edge_rising & bitmask) {
reg = readl(nmk_chip->addr + rimsc);
if (enable)
reg |= bitmask;
else
reg &= ~bitmask;
writel(reg, nmk_chip->addr + rimsc);
}
if (nmk_chip->edge_falling & bitmask) {
reg = readl(nmk_chip->addr + fimsc);
if (enable)
reg |= bitmask;
else
reg &= ~bitmask;
writel(reg, nmk_chip->addr + fimsc);
}
}
static void __nmk_gpio_set_wake(struct nmk_gpio_chip *nmk_chip,
int gpio, bool on)
{
if (nmk_chip->sleepmode) {
__nmk_gpio_set_slpm(nmk_chip, gpio - nmk_chip->chip.base,
on ? NMK_GPIO_SLPM_WAKEUP_ENABLE
: NMK_GPIO_SLPM_WAKEUP_DISABLE);
}
__nmk_gpio_irq_modify(nmk_chip, gpio, WAKE, on);
}
static int nmk_gpio_irq_maskunmask(struct irq_data *d, bool enable)
{
int gpio;
struct nmk_gpio_chip *nmk_chip;
unsigned long flags;
u32 bitmask;
gpio = NOMADIK_IRQ_TO_GPIO(d->irq);
nmk_chip = irq_data_get_irq_chip_data(d);
bitmask = nmk_gpio_get_bitmask(gpio);
if (!nmk_chip)
return -EINVAL;
clk_enable(nmk_chip->clk);
spin_lock_irqsave(&nmk_gpio_slpm_lock, flags);
spin_lock(&nmk_chip->lock);
__nmk_gpio_irq_modify(nmk_chip, gpio, NORMAL, enable);
if (!(nmk_chip->real_wake & bitmask))
__nmk_gpio_set_wake(nmk_chip, gpio, enable);
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
int gpio;
gpio = NOMADIK_IRQ_TO_GPIO(d->irq);
nmk_chip = irq_data_get_irq_chip_data(d);
if (!nmk_chip)
return -EINVAL;
bitmask = nmk_gpio_get_bitmask(gpio);
clk_enable(nmk_chip->clk);
spin_lock_irqsave(&nmk_gpio_slpm_lock, flags);
spin_lock(&nmk_chip->lock);
if (irqd_irq_disabled(d))
__nmk_gpio_set_wake(nmk_chip, gpio, on);
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
int gpio;
struct nmk_gpio_chip *nmk_chip;
unsigned long flags;
u32 bitmask;
gpio = NOMADIK_IRQ_TO_GPIO(d->irq);
nmk_chip = irq_data_get_irq_chip_data(d);
bitmask = nmk_gpio_get_bitmask(gpio);
if (!nmk_chip)
return -EINVAL;
if (type & IRQ_TYPE_LEVEL_HIGH)
return -EINVAL;
if (type & IRQ_TYPE_LEVEL_LOW)
return -EINVAL;
clk_enable(nmk_chip->clk);
spin_lock_irqsave(&nmk_chip->lock, flags);
if (enabled)
__nmk_gpio_irq_modify(nmk_chip, gpio, NORMAL, false);
if (enabled || wake)
__nmk_gpio_irq_modify(nmk_chip, gpio, WAKE, false);
nmk_chip->edge_rising &= ~bitmask;
if (type & IRQ_TYPE_EDGE_RISING)
nmk_chip->edge_rising |= bitmask;
nmk_chip->edge_falling &= ~bitmask;
if (type & IRQ_TYPE_EDGE_FALLING)
nmk_chip->edge_falling |= bitmask;
if (enabled)
__nmk_gpio_irq_modify(nmk_chip, gpio, NORMAL, true);
if (enabled || wake)
__nmk_gpio_irq_modify(nmk_chip, gpio, WAKE, true);
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
static void __nmk_gpio_irq_handler(unsigned int irq, struct irq_desc *desc,
u32 status)
{
struct nmk_gpio_chip *nmk_chip;
struct irq_chip *host_chip = irq_get_chip(irq);
unsigned int first_irq;
chained_irq_enter(host_chip, desc);
nmk_chip = irq_get_handler_data(irq);
first_irq = NOMADIK_GPIO_TO_IRQ(nmk_chip->chip.base);
while (status) {
int bit = __ffs(status);
generic_handle_irq(first_irq + bit);
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
unsigned int first_irq;
int i;
first_irq = NOMADIK_GPIO_TO_IRQ(nmk_chip->chip.base);
for (i = first_irq; i < first_irq + nmk_chip->chip.ngpio; i++) {
irq_set_chip_and_handler(i, &nmk_gpio_irq_chip,
handle_edge_irq);
set_irq_flags(i, IRQF_VALID);
irq_set_chip_data(i, nmk_chip);
irq_set_irq_type(i, IRQ_TYPE_EDGE_FALLING);
}
irq_set_chained_handler(nmk_chip->parent_irq, nmk_gpio_irq_handler);
irq_set_handler_data(nmk_chip->parent_irq, nmk_chip);
if (nmk_chip->secondary_parent_irq >= 0) {
irq_set_chained_handler(nmk_chip->secondary_parent_irq,
nmk_gpio_secondary_irq_handler);
irq_set_handler_data(nmk_chip->secondary_parent_irq, nmk_chip);
}
return 0;
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
return NOMADIK_GPIO_TO_IRQ(nmk_chip->chip.base) + offset;
}
static void nmk_gpio_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
int mode;
unsigned i;
unsigned gpio = chip->base;
int is_out;
struct nmk_gpio_chip *nmk_chip =
container_of(chip, struct nmk_gpio_chip, chip);
const char *modes[] = {
[NMK_GPIO_ALT_GPIO] = "gpio",
[NMK_GPIO_ALT_A] = "altA",
[NMK_GPIO_ALT_B] = "altB",
[NMK_GPIO_ALT_C] = "altC",
};
clk_enable(nmk_chip->clk);
for (i = 0; i < chip->ngpio; i++, gpio++) {
const char *label = gpiochip_is_requested(chip, i);
bool pull;
u32 bit = 1 << i;
is_out = readl(nmk_chip->addr + NMK_GPIO_DIR) & bit;
pull = !(readl(nmk_chip->addr + NMK_GPIO_PDIS) & bit);
mode = nmk_gpio_get_mode(gpio);
seq_printf(s, " gpio-%-3d (%-20.20s) %s %s %s %s",
gpio, label ?: "(none)",
is_out ? "out" : "in ",
chip->get
? (chip->get(chip, i) ? "hi" : "lo")
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
seq_printf(s, "\n");
}
clk_disable(nmk_chip->clk);
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
chip->rwimsc = readl(chip->addr + NMK_GPIO_RWIMSC);
chip->fwimsc = readl(chip->addr + NMK_GPIO_FWIMSC);
writel(chip->rwimsc & chip->real_wake,
chip->addr + NMK_GPIO_RWIMSC);
writel(chip->fwimsc & chip->real_wake,
chip->addr + NMK_GPIO_FWIMSC);
if (chip->sleepmode) {
chip->slpm = readl(chip->addr + NMK_GPIO_SLPC);
writel(~chip->real_wake, chip->addr + NMK_GPIO_SLPC);
}
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
if (chip->sleepmode)
writel(chip->slpm, chip->addr + NMK_GPIO_SLPC);
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
static int __devinit nmk_gpio_probe(struct platform_device *dev)
{
struct nmk_gpio_platform_data *pdata = dev->dev.platform_data;
struct nmk_gpio_chip *nmk_chip;
struct gpio_chip *chip;
struct resource *res;
struct clk *clk;
int secondary_irq;
int irq;
int ret;
if (!pdata)
return -ENODEV;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENOENT;
goto out;
}
irq = platform_get_irq(dev, 0);
if (irq < 0) {
ret = irq;
goto out;
}
secondary_irq = platform_get_irq(dev, 1);
if (secondary_irq >= 0 && !pdata->get_secondary_status) {
ret = -EINVAL;
goto out;
}
if (request_mem_region(res->start, resource_size(res),
dev_name(&dev->dev)) == NULL) {
ret = -EBUSY;
goto out;
}
clk = clk_get(&dev->dev, NULL);
if (IS_ERR(clk)) {
ret = PTR_ERR(clk);
goto out_release;
}
nmk_chip = kzalloc(sizeof(*nmk_chip), GFP_KERNEL);
if (!nmk_chip) {
ret = -ENOMEM;
goto out_clk;
}
nmk_chip->bank = dev->id;
nmk_chip->clk = clk;
nmk_chip->addr = io_p2v(res->start);
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
ret = gpiochip_add(&nmk_chip->chip);
if (ret)
goto out_free;
BUG_ON(nmk_chip->bank >= ARRAY_SIZE(nmk_gpio_chips));
nmk_gpio_chips[nmk_chip->bank] = nmk_chip;
platform_set_drvdata(dev, nmk_chip);
nmk_gpio_init_irq(nmk_chip);
dev_info(&dev->dev, "at address %p\n",
nmk_chip->addr);
return 0;
out_free:
kfree(nmk_chip);
out_clk:
clk_disable(clk);
clk_put(clk);
out_release:
release_mem_region(res->start, resource_size(res));
out:
dev_err(&dev->dev, "Failure %i for GPIO %i-%i\n", ret,
pdata->first_gpio, pdata->first_gpio+31);
return ret;
}
static int __init nmk_gpio_init(void)
{
return platform_driver_register(&nmk_gpio_driver);
}
