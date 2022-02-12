static struct intel_community *intel_get_community(struct intel_pinctrl *pctrl,
unsigned pin)
{
struct intel_community *community;
int i;
for (i = 0; i < pctrl->ncommunities; i++) {
community = &pctrl->communities[i];
if (pin >= community->pin_base &&
pin < community->pin_base + community->npins)
return community;
}
dev_warn(pctrl->dev, "failed to find community for pin %u\n", pin);
return NULL;
}
static const struct intel_padgroup *
intel_community_get_padgroup(const struct intel_community *community,
unsigned pin)
{
int i;
for (i = 0; i < community->ngpps; i++) {
const struct intel_padgroup *padgrp = &community->gpps[i];
if (pin >= padgrp->base && pin < padgrp->base + padgrp->size)
return padgrp;
}
return NULL;
}
static void __iomem *intel_get_padcfg(struct intel_pinctrl *pctrl, unsigned pin,
unsigned reg)
{
const struct intel_community *community;
unsigned padno;
size_t nregs;
community = intel_get_community(pctrl, pin);
if (!community)
return NULL;
padno = pin_to_padno(community, pin);
nregs = (community->features & PINCTRL_FEATURE_DEBOUNCE) ? 4 : 2;
if (reg == PADCFG2 && !(community->features & PINCTRL_FEATURE_DEBOUNCE))
return NULL;
return community->pad_regs + reg + padno * nregs * 4;
}
static bool intel_pad_owned_by_host(struct intel_pinctrl *pctrl, unsigned pin)
{
const struct intel_community *community;
const struct intel_padgroup *padgrp;
unsigned gpp, offset, gpp_offset;
void __iomem *padown;
community = intel_get_community(pctrl, pin);
if (!community)
return false;
if (!community->padown_offset)
return true;
padgrp = intel_community_get_padgroup(community, pin);
if (!padgrp)
return false;
gpp_offset = padgroup_offset(padgrp, pin);
gpp = PADOWN_GPP(gpp_offset);
offset = community->padown_offset + padgrp->padown_num * 4 + gpp * 4;
padown = community->regs + offset;
return !(readl(padown) & PADOWN_MASK(gpp_offset));
}
static bool intel_pad_acpi_mode(struct intel_pinctrl *pctrl, unsigned pin)
{
const struct intel_community *community;
const struct intel_padgroup *padgrp;
unsigned offset, gpp_offset;
void __iomem *hostown;
community = intel_get_community(pctrl, pin);
if (!community)
return true;
if (!community->hostown_offset)
return false;
padgrp = intel_community_get_padgroup(community, pin);
if (!padgrp)
return true;
gpp_offset = padgroup_offset(padgrp, pin);
offset = community->hostown_offset + padgrp->reg_num * 4;
hostown = community->regs + offset;
return !(readl(hostown) & BIT(gpp_offset));
}
static bool intel_pad_locked(struct intel_pinctrl *pctrl, unsigned pin)
{
struct intel_community *community;
const struct intel_padgroup *padgrp;
unsigned offset, gpp_offset;
u32 value;
community = intel_get_community(pctrl, pin);
if (!community)
return true;
if (!community->padcfglock_offset)
return false;
padgrp = intel_community_get_padgroup(community, pin);
if (!padgrp)
return true;
gpp_offset = padgroup_offset(padgrp, pin);
offset = community->padcfglock_offset + padgrp->reg_num * 8;
value = readl(community->regs + offset);
if (value & BIT(gpp_offset))
return true;
offset = community->padcfglock_offset + 4 + padgrp->reg_num * 8;
value = readl(community->regs + offset);
if (value & BIT(gpp_offset))
return true;
return false;
}
static bool intel_pad_usable(struct intel_pinctrl *pctrl, unsigned pin)
{
return intel_pad_owned_by_host(pctrl, pin) &&
!intel_pad_locked(pctrl, pin);
}
static int intel_get_groups_count(struct pinctrl_dev *pctldev)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->soc->ngroups;
}
static const char *intel_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->soc->groups[group].name;
}
static int intel_get_group_pins(struct pinctrl_dev *pctldev, unsigned group,
const unsigned **pins, unsigned *npins)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
*pins = pctrl->soc->groups[group].pins;
*npins = pctrl->soc->groups[group].npins;
return 0;
}
static void intel_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned pin)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
void __iomem *padcfg;
u32 cfg0, cfg1, mode;
bool locked, acpi;
if (!intel_pad_owned_by_host(pctrl, pin)) {
seq_puts(s, "not available");
return;
}
cfg0 = readl(intel_get_padcfg(pctrl, pin, PADCFG0));
cfg1 = readl(intel_get_padcfg(pctrl, pin, PADCFG1));
mode = (cfg0 & PADCFG0_PMODE_MASK) >> PADCFG0_PMODE_SHIFT;
if (!mode)
seq_puts(s, "GPIO ");
else
seq_printf(s, "mode %d ", mode);
seq_printf(s, "0x%08x 0x%08x", cfg0, cfg1);
padcfg = intel_get_padcfg(pctrl, pin, PADCFG2);
if (padcfg)
seq_printf(s, " 0x%08x", readl(padcfg));
locked = intel_pad_locked(pctrl, pin);
acpi = intel_pad_acpi_mode(pctrl, pin);
if (locked || acpi) {
seq_puts(s, " [");
if (locked) {
seq_puts(s, "LOCKED");
if (acpi)
seq_puts(s, ", ");
}
if (acpi)
seq_puts(s, "ACPI");
seq_puts(s, "]");
}
}
static int intel_get_functions_count(struct pinctrl_dev *pctldev)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->soc->nfunctions;
}
static const char *intel_get_function_name(struct pinctrl_dev *pctldev,
unsigned function)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->soc->functions[function].name;
}
static int intel_get_function_groups(struct pinctrl_dev *pctldev,
unsigned function,
const char * const **groups,
unsigned * const ngroups)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
*groups = pctrl->soc->functions[function].groups;
*ngroups = pctrl->soc->functions[function].ngroups;
return 0;
}
static int intel_pinmux_set_mux(struct pinctrl_dev *pctldev, unsigned function,
unsigned group)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
const struct intel_pingroup *grp = &pctrl->soc->groups[group];
unsigned long flags;
int i;
raw_spin_lock_irqsave(&pctrl->lock, flags);
for (i = 0; i < grp->npins; i++) {
if (!intel_pad_usable(pctrl, grp->pins[i])) {
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
return -EBUSY;
}
}
for (i = 0; i < grp->npins; i++) {
void __iomem *padcfg0;
u32 value;
padcfg0 = intel_get_padcfg(pctrl, grp->pins[i], PADCFG0);
value = readl(padcfg0);
value &= ~PADCFG0_PMODE_MASK;
if (grp->modes)
value |= grp->modes[i] << PADCFG0_PMODE_SHIFT;
else
value |= grp->mode << PADCFG0_PMODE_SHIFT;
writel(value, padcfg0);
}
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
return 0;
}
static void __intel_gpio_set_direction(void __iomem *padcfg0, bool input)
{
u32 value;
value = readl(padcfg0);
if (input) {
value &= ~PADCFG0_GPIORXDIS;
value |= PADCFG0_GPIOTXDIS;
} else {
value &= ~PADCFG0_GPIOTXDIS;
value |= PADCFG0_GPIORXDIS;
}
writel(value, padcfg0);
}
static int intel_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned pin)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
void __iomem *padcfg0;
unsigned long flags;
u32 value;
raw_spin_lock_irqsave(&pctrl->lock, flags);
if (!intel_pad_usable(pctrl, pin)) {
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
return -EBUSY;
}
padcfg0 = intel_get_padcfg(pctrl, pin, PADCFG0);
value = readl(padcfg0) & ~PADCFG0_PMODE_MASK;
value &= ~(PADCFG0_GPIROUTIOXAPIC | PADCFG0_GPIROUTSCI);
value &= ~(PADCFG0_GPIROUTSMI | PADCFG0_GPIROUTNMI);
writel(value, padcfg0);
__intel_gpio_set_direction(padcfg0, true);
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
return 0;
}
static int intel_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned pin, bool input)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
void __iomem *padcfg0;
unsigned long flags;
raw_spin_lock_irqsave(&pctrl->lock, flags);
padcfg0 = intel_get_padcfg(pctrl, pin, PADCFG0);
__intel_gpio_set_direction(padcfg0, input);
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
return 0;
}
static int intel_config_get(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
const struct intel_community *community;
u32 value, term;
u32 arg = 0;
if (!intel_pad_owned_by_host(pctrl, pin))
return -ENOTSUPP;
community = intel_get_community(pctrl, pin);
value = readl(intel_get_padcfg(pctrl, pin, PADCFG1));
term = (value & PADCFG1_TERM_MASK) >> PADCFG1_TERM_SHIFT;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if (term)
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_UP:
if (!term || !(value & PADCFG1_TERM_UP))
return -EINVAL;
switch (term) {
case PADCFG1_TERM_1K:
arg = 1000;
break;
case PADCFG1_TERM_2K:
arg = 2000;
break;
case PADCFG1_TERM_5K:
arg = 5000;
break;
case PADCFG1_TERM_20K:
arg = 20000;
break;
}
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (!term || value & PADCFG1_TERM_UP)
return -EINVAL;
switch (term) {
case PADCFG1_TERM_1K:
if (!(community->features & PINCTRL_FEATURE_1K_PD))
return -EINVAL;
arg = 1000;
break;
case PADCFG1_TERM_5K:
arg = 5000;
break;
case PADCFG1_TERM_20K:
arg = 20000;
break;
}
break;
case PIN_CONFIG_INPUT_DEBOUNCE: {
void __iomem *padcfg2;
u32 v;
padcfg2 = intel_get_padcfg(pctrl, pin, PADCFG2);
if (!padcfg2)
return -ENOTSUPP;
v = readl(padcfg2);
if (!(v & PADCFG2_DEBEN))
return -EINVAL;
v = (v & PADCFG2_DEBOUNCE_MASK) >> PADCFG2_DEBOUNCE_SHIFT;
arg = BIT(v) * DEBOUNCE_PERIOD / 1000;
break;
}
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int intel_config_set_pull(struct intel_pinctrl *pctrl, unsigned pin,
unsigned long config)
{
unsigned param = pinconf_to_config_param(config);
unsigned arg = pinconf_to_config_argument(config);
const struct intel_community *community;
void __iomem *padcfg1;
unsigned long flags;
int ret = 0;
u32 value;
raw_spin_lock_irqsave(&pctrl->lock, flags);
community = intel_get_community(pctrl, pin);
padcfg1 = intel_get_padcfg(pctrl, pin, PADCFG1);
value = readl(padcfg1);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
value &= ~(PADCFG1_TERM_MASK | PADCFG1_TERM_UP);
break;
case PIN_CONFIG_BIAS_PULL_UP:
value &= ~PADCFG1_TERM_MASK;
value |= PADCFG1_TERM_UP;
switch (arg) {
case 20000:
value |= PADCFG1_TERM_20K << PADCFG1_TERM_SHIFT;
break;
case 5000:
value |= PADCFG1_TERM_5K << PADCFG1_TERM_SHIFT;
break;
case 2000:
value |= PADCFG1_TERM_2K << PADCFG1_TERM_SHIFT;
break;
case 1000:
value |= PADCFG1_TERM_1K << PADCFG1_TERM_SHIFT;
break;
default:
ret = -EINVAL;
}
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
value &= ~(PADCFG1_TERM_UP | PADCFG1_TERM_MASK);
switch (arg) {
case 20000:
value |= PADCFG1_TERM_20K << PADCFG1_TERM_SHIFT;
break;
case 5000:
value |= PADCFG1_TERM_5K << PADCFG1_TERM_SHIFT;
break;
case 1000:
if (!(community->features & PINCTRL_FEATURE_1K_PD)) {
ret = -EINVAL;
break;
}
value |= PADCFG1_TERM_1K << PADCFG1_TERM_SHIFT;
break;
default:
ret = -EINVAL;
}
break;
}
if (!ret)
writel(value, padcfg1);
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
return ret;
}
static int intel_config_set_debounce(struct intel_pinctrl *pctrl, unsigned pin,
unsigned debounce)
{
void __iomem *padcfg0, *padcfg2;
unsigned long flags;
u32 value0, value2;
int ret = 0;
padcfg2 = intel_get_padcfg(pctrl, pin, PADCFG2);
if (!padcfg2)
return -ENOTSUPP;
padcfg0 = intel_get_padcfg(pctrl, pin, PADCFG0);
raw_spin_lock_irqsave(&pctrl->lock, flags);
value0 = readl(padcfg0);
value2 = readl(padcfg2);
value0 &= ~PADCFG0_PREGFRXSEL;
value2 &= ~(PADCFG2_DEBEN | PADCFG2_DEBOUNCE_MASK);
if (debounce) {
unsigned long v;
v = order_base_2(debounce * 1000 / DEBOUNCE_PERIOD);
if (v < 3 || v > 15) {
ret = -EINVAL;
goto exit_unlock;
} else {
value0 |= PADCFG0_PREGFRXSEL;
value2 |= v << PADCFG2_DEBOUNCE_SHIFT;
value2 |= PADCFG2_DEBEN;
}
}
writel(value0, padcfg0);
writel(value2, padcfg2);
exit_unlock:
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
return ret;
}
static int intel_config_set(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *configs, unsigned nconfigs)
{
struct intel_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
int i, ret;
if (!intel_pad_usable(pctrl, pin))
return -ENOTSUPP;
for (i = 0; i < nconfigs; i++) {
switch (pinconf_to_config_param(configs[i])) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
ret = intel_config_set_pull(pctrl, pin, configs[i]);
if (ret)
return ret;
break;
case PIN_CONFIG_INPUT_DEBOUNCE:
ret = intel_config_set_debounce(pctrl, pin,
pinconf_to_config_argument(configs[i]));
if (ret)
return ret;
break;
default:
return -ENOTSUPP;
}
}
return 0;
}
static int intel_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct intel_pinctrl *pctrl = gpiochip_get_data(chip);
void __iomem *reg;
u32 padcfg0;
reg = intel_get_padcfg(pctrl, offset, PADCFG0);
if (!reg)
return -EINVAL;
padcfg0 = readl(reg);
if (!(padcfg0 & PADCFG0_GPIOTXDIS))
return !!(padcfg0 & PADCFG0_GPIOTXSTATE);
return !!(padcfg0 & PADCFG0_GPIORXSTATE);
}
static void intel_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct intel_pinctrl *pctrl = gpiochip_get_data(chip);
unsigned long flags;
void __iomem *reg;
u32 padcfg0;
reg = intel_get_padcfg(pctrl, offset, PADCFG0);
if (!reg)
return;
raw_spin_lock_irqsave(&pctrl->lock, flags);
padcfg0 = readl(reg);
if (value)
padcfg0 |= PADCFG0_GPIOTXSTATE;
else
padcfg0 &= ~PADCFG0_GPIOTXSTATE;
writel(padcfg0, reg);
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
}
static int intel_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_gpio_direction_input(chip->base + offset);
}
static int intel_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
intel_gpio_set(chip, offset, value);
return pinctrl_gpio_direction_output(chip->base + offset);
}
static void intel_gpio_irq_ack(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct intel_pinctrl *pctrl = gpiochip_get_data(gc);
const struct intel_community *community;
unsigned pin = irqd_to_hwirq(d);
community = intel_get_community(pctrl, pin);
if (community) {
const struct intel_padgroup *padgrp;
unsigned gpp, gpp_offset;
padgrp = intel_community_get_padgroup(community, pin);
if (!padgrp)
return;
gpp = padgrp->reg_num;
gpp_offset = padgroup_offset(padgrp, pin);
raw_spin_lock(&pctrl->lock);
writel(BIT(gpp_offset), community->regs + GPI_IS + gpp * 4);
raw_spin_unlock(&pctrl->lock);
}
}
static void intel_gpio_irq_enable(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct intel_pinctrl *pctrl = gpiochip_get_data(gc);
const struct intel_community *community;
unsigned pin = irqd_to_hwirq(d);
community = intel_get_community(pctrl, pin);
if (community) {
const struct intel_padgroup *padgrp;
unsigned gpp, gpp_offset;
unsigned long flags;
u32 value;
padgrp = intel_community_get_padgroup(community, pin);
if (!padgrp)
return;
gpp = padgrp->reg_num;
gpp_offset = padgroup_offset(padgrp, pin);
raw_spin_lock_irqsave(&pctrl->lock, flags);
writel(BIT(gpp_offset), community->regs + GPI_IS + gpp * 4);
value = readl(community->regs + community->ie_offset + gpp * 4);
value |= BIT(gpp_offset);
writel(value, community->regs + community->ie_offset + gpp * 4);
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
}
}
static void intel_gpio_irq_mask_unmask(struct irq_data *d, bool mask)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct intel_pinctrl *pctrl = gpiochip_get_data(gc);
const struct intel_community *community;
unsigned pin = irqd_to_hwirq(d);
community = intel_get_community(pctrl, pin);
if (community) {
const struct intel_padgroup *padgrp;
unsigned gpp, gpp_offset;
unsigned long flags;
void __iomem *reg;
u32 value;
padgrp = intel_community_get_padgroup(community, pin);
if (!padgrp)
return;
gpp = padgrp->reg_num;
gpp_offset = padgroup_offset(padgrp, pin);
reg = community->regs + community->ie_offset + gpp * 4;
raw_spin_lock_irqsave(&pctrl->lock, flags);
value = readl(reg);
if (mask)
value &= ~BIT(gpp_offset);
else
value |= BIT(gpp_offset);
writel(value, reg);
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
}
}
static void intel_gpio_irq_mask(struct irq_data *d)
{
intel_gpio_irq_mask_unmask(d, true);
}
static void intel_gpio_irq_unmask(struct irq_data *d)
{
intel_gpio_irq_mask_unmask(d, false);
}
static int intel_gpio_irq_type(struct irq_data *d, unsigned type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct intel_pinctrl *pctrl = gpiochip_get_data(gc);
unsigned pin = irqd_to_hwirq(d);
unsigned long flags;
void __iomem *reg;
u32 value;
reg = intel_get_padcfg(pctrl, pin, PADCFG0);
if (!reg)
return -EINVAL;
if (intel_pad_acpi_mode(pctrl, pin)) {
dev_warn(pctrl->dev, "pin %u cannot be used as IRQ\n", pin);
return -EPERM;
}
raw_spin_lock_irqsave(&pctrl->lock, flags);
value = readl(reg);
value &= ~(PADCFG0_RXEVCFG_MASK | PADCFG0_RXINV);
if ((type & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH) {
value |= PADCFG0_RXEVCFG_EDGE_BOTH << PADCFG0_RXEVCFG_SHIFT;
} else if (type & IRQ_TYPE_EDGE_FALLING) {
value |= PADCFG0_RXEVCFG_EDGE << PADCFG0_RXEVCFG_SHIFT;
value |= PADCFG0_RXINV;
} else if (type & IRQ_TYPE_EDGE_RISING) {
value |= PADCFG0_RXEVCFG_EDGE << PADCFG0_RXEVCFG_SHIFT;
} else if (type & IRQ_TYPE_LEVEL_MASK) {
if (type & IRQ_TYPE_LEVEL_LOW)
value |= PADCFG0_RXINV;
} else {
value |= PADCFG0_RXEVCFG_DISABLED << PADCFG0_RXEVCFG_SHIFT;
}
writel(value, reg);
if (type & IRQ_TYPE_EDGE_BOTH)
irq_set_handler_locked(d, handle_edge_irq);
else if (type & IRQ_TYPE_LEVEL_MASK)
irq_set_handler_locked(d, handle_level_irq);
raw_spin_unlock_irqrestore(&pctrl->lock, flags);
return 0;
}
static int intel_gpio_irq_wake(struct irq_data *d, unsigned int on)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct intel_pinctrl *pctrl = gpiochip_get_data(gc);
unsigned pin = irqd_to_hwirq(d);
if (on)
enable_irq_wake(pctrl->irq);
else
disable_irq_wake(pctrl->irq);
dev_dbg(pctrl->dev, "%sable wake for pin %u\n", on ? "en" : "dis", pin);
return 0;
}
static irqreturn_t intel_gpio_community_irq_handler(struct intel_pinctrl *pctrl,
const struct intel_community *community)
{
struct gpio_chip *gc = &pctrl->chip;
irqreturn_t ret = IRQ_NONE;
int gpp;
for (gpp = 0; gpp < community->ngpps; gpp++) {
const struct intel_padgroup *padgrp = &community->gpps[gpp];
unsigned long pending, enabled, gpp_offset;
pending = readl(community->regs + GPI_IS + padgrp->reg_num * 4);
enabled = readl(community->regs + community->ie_offset +
padgrp->reg_num * 4);
pending &= enabled;
for_each_set_bit(gpp_offset, &pending, padgrp->size) {
unsigned padno, irq;
padno = padgrp->base - community->pin_base + gpp_offset;
if (padno >= community->npins)
break;
irq = irq_find_mapping(gc->irqdomain,
community->pin_base + padno);
generic_handle_irq(irq);
ret |= IRQ_HANDLED;
}
}
return ret;
}
static irqreturn_t intel_gpio_irq(int irq, void *data)
{
const struct intel_community *community;
struct intel_pinctrl *pctrl = data;
irqreturn_t ret = IRQ_NONE;
int i;
for (i = 0; i < pctrl->ncommunities; i++) {
community = &pctrl->communities[i];
ret |= intel_gpio_community_irq_handler(pctrl, community);
}
return ret;
}
static int intel_gpio_probe(struct intel_pinctrl *pctrl, int irq)
{
int ret;
pctrl->chip = intel_gpio_chip;
pctrl->chip.ngpio = pctrl->soc->npins;
pctrl->chip.label = dev_name(pctrl->dev);
pctrl->chip.parent = pctrl->dev;
pctrl->chip.base = -1;
pctrl->irq = irq;
ret = devm_gpiochip_add_data(pctrl->dev, &pctrl->chip, pctrl);
if (ret) {
dev_err(pctrl->dev, "failed to register gpiochip\n");
return ret;
}
ret = gpiochip_add_pin_range(&pctrl->chip, dev_name(pctrl->dev),
0, 0, pctrl->soc->npins);
if (ret) {
dev_err(pctrl->dev, "failed to add GPIO pin range\n");
return ret;
}
ret = devm_request_irq(pctrl->dev, irq, intel_gpio_irq,
IRQF_SHARED | IRQF_NO_THREAD,
dev_name(pctrl->dev), pctrl);
if (ret) {
dev_err(pctrl->dev, "failed to request interrupt\n");
return ret;
}
ret = gpiochip_irqchip_add(&pctrl->chip, &intel_gpio_irqchip, 0,
handle_bad_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(pctrl->dev, "failed to add irqchip\n");
return ret;
}
gpiochip_set_chained_irqchip(&pctrl->chip, &intel_gpio_irqchip, irq,
NULL);
return 0;
}
static int intel_pinctrl_add_padgroups(struct intel_pinctrl *pctrl,
struct intel_community *community)
{
struct intel_padgroup *gpps;
unsigned npins = community->npins;
unsigned padown_num = 0;
size_t ngpps, i;
if (community->gpps)
ngpps = community->ngpps;
else
ngpps = DIV_ROUND_UP(community->npins, community->gpp_size);
gpps = devm_kcalloc(pctrl->dev, ngpps, sizeof(*gpps), GFP_KERNEL);
if (!gpps)
return -ENOMEM;
for (i = 0; i < ngpps; i++) {
if (community->gpps) {
gpps[i] = community->gpps[i];
} else {
unsigned gpp_size = community->gpp_size;
gpps[i].reg_num = i;
gpps[i].base = community->pin_base + i * gpp_size;
gpps[i].size = min(gpp_size, npins);
npins -= gpps[i].size;
}
if (gpps[i].size > 32)
return -EINVAL;
gpps[i].padown_num = padown_num;
if (community->gpp_num_padown_regs)
padown_num += community->gpp_num_padown_regs;
else
padown_num += DIV_ROUND_UP(gpps[i].size * 4, 32);
}
community->ngpps = ngpps;
community->gpps = gpps;
return 0;
}
static int intel_pinctrl_pm_init(struct intel_pinctrl *pctrl)
{
#ifdef CONFIG_PM_SLEEP
const struct intel_pinctrl_soc_data *soc = pctrl->soc;
struct intel_community_context *communities;
struct intel_pad_context *pads;
int i;
pads = devm_kcalloc(pctrl->dev, soc->npins, sizeof(*pads), GFP_KERNEL);
if (!pads)
return -ENOMEM;
communities = devm_kcalloc(pctrl->dev, pctrl->ncommunities,
sizeof(*communities), GFP_KERNEL);
if (!communities)
return -ENOMEM;
for (i = 0; i < pctrl->ncommunities; i++) {
struct intel_community *community = &pctrl->communities[i];
u32 *intmask;
intmask = devm_kcalloc(pctrl->dev, community->ngpps,
sizeof(*intmask), GFP_KERNEL);
if (!intmask)
return -ENOMEM;
communities[i].intmask = intmask;
}
pctrl->context.pads = pads;
pctrl->context.communities = communities;
#endif
return 0;
}
int intel_pinctrl_probe(struct platform_device *pdev,
const struct intel_pinctrl_soc_data *soc_data)
{
struct intel_pinctrl *pctrl;
int i, ret, irq;
if (!soc_data)
return -EINVAL;
pctrl = devm_kzalloc(&pdev->dev, sizeof(*pctrl), GFP_KERNEL);
if (!pctrl)
return -ENOMEM;
pctrl->dev = &pdev->dev;
pctrl->soc = soc_data;
raw_spin_lock_init(&pctrl->lock);
pctrl->ncommunities = pctrl->soc->ncommunities;
pctrl->communities = devm_kcalloc(&pdev->dev, pctrl->ncommunities,
sizeof(*pctrl->communities), GFP_KERNEL);
if (!pctrl->communities)
return -ENOMEM;
for (i = 0; i < pctrl->ncommunities; i++) {
struct intel_community *community = &pctrl->communities[i];
struct resource *res;
void __iomem *regs;
u32 padbar;
*community = pctrl->soc->communities[i];
res = platform_get_resource(pdev, IORESOURCE_MEM,
community->barno);
regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
if (!community->features) {
u32 rev;
rev = (readl(regs + REVID) & REVID_MASK) >> REVID_SHIFT;
if (rev >= 0x94) {
community->features |= PINCTRL_FEATURE_DEBOUNCE;
community->features |= PINCTRL_FEATURE_1K_PD;
}
}
padbar = readl(regs + PADBAR);
community->regs = regs;
community->pad_regs = regs + padbar;
ret = intel_pinctrl_add_padgroups(pctrl, community);
if (ret)
return ret;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get interrupt number\n");
return irq;
}
ret = intel_pinctrl_pm_init(pctrl);
if (ret)
return ret;
pctrl->pctldesc = intel_pinctrl_desc;
pctrl->pctldesc.name = dev_name(&pdev->dev);
pctrl->pctldesc.pins = pctrl->soc->pins;
pctrl->pctldesc.npins = pctrl->soc->npins;
pctrl->pctldev = devm_pinctrl_register(&pdev->dev, &pctrl->pctldesc,
pctrl);
if (IS_ERR(pctrl->pctldev)) {
dev_err(&pdev->dev, "failed to register pinctrl driver\n");
return PTR_ERR(pctrl->pctldev);
}
ret = intel_gpio_probe(pctrl, irq);
if (ret)
return ret;
platform_set_drvdata(pdev, pctrl);
return 0;
}
static bool intel_pinctrl_should_save(struct intel_pinctrl *pctrl, unsigned pin)
{
const struct pin_desc *pd = pin_desc_get(pctrl->pctldev, pin);
if (!pd || !intel_pad_usable(pctrl, pin))
return false;
if (pd->mux_owner || pd->gpio_owner ||
gpiochip_line_is_irq(&pctrl->chip, pin))
return true;
return false;
}
int intel_pinctrl_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct intel_pinctrl *pctrl = platform_get_drvdata(pdev);
struct intel_community_context *communities;
struct intel_pad_context *pads;
int i;
pads = pctrl->context.pads;
for (i = 0; i < pctrl->soc->npins; i++) {
const struct pinctrl_pin_desc *desc = &pctrl->soc->pins[i];
void __iomem *padcfg;
u32 val;
if (!intel_pinctrl_should_save(pctrl, desc->number))
continue;
val = readl(intel_get_padcfg(pctrl, desc->number, PADCFG0));
pads[i].padcfg0 = val & ~PADCFG0_GPIORXSTATE;
val = readl(intel_get_padcfg(pctrl, desc->number, PADCFG1));
pads[i].padcfg1 = val;
padcfg = intel_get_padcfg(pctrl, desc->number, PADCFG2);
if (padcfg)
pads[i].padcfg2 = readl(padcfg);
}
communities = pctrl->context.communities;
for (i = 0; i < pctrl->ncommunities; i++) {
struct intel_community *community = &pctrl->communities[i];
void __iomem *base;
unsigned gpp;
base = community->regs + community->ie_offset;
for (gpp = 0; gpp < community->ngpps; gpp++)
communities[i].intmask[gpp] = readl(base + gpp * 4);
}
return 0;
}
static void intel_gpio_irq_init(struct intel_pinctrl *pctrl)
{
size_t i;
for (i = 0; i < pctrl->ncommunities; i++) {
const struct intel_community *community;
void __iomem *base;
unsigned gpp;
community = &pctrl->communities[i];
base = community->regs;
for (gpp = 0; gpp < community->ngpps; gpp++) {
writel(0, base + community->ie_offset + gpp * 4);
writel(0xffff, base + GPI_IS + gpp * 4);
}
}
}
int intel_pinctrl_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct intel_pinctrl *pctrl = platform_get_drvdata(pdev);
const struct intel_community_context *communities;
const struct intel_pad_context *pads;
int i;
intel_gpio_irq_init(pctrl);
pads = pctrl->context.pads;
for (i = 0; i < pctrl->soc->npins; i++) {
const struct pinctrl_pin_desc *desc = &pctrl->soc->pins[i];
void __iomem *padcfg;
u32 val;
if (!intel_pinctrl_should_save(pctrl, desc->number))
continue;
padcfg = intel_get_padcfg(pctrl, desc->number, PADCFG0);
val = readl(padcfg) & ~PADCFG0_GPIORXSTATE;
if (val != pads[i].padcfg0) {
writel(pads[i].padcfg0, padcfg);
dev_dbg(dev, "restored pin %u padcfg0 %#08x\n",
desc->number, readl(padcfg));
}
padcfg = intel_get_padcfg(pctrl, desc->number, PADCFG1);
val = readl(padcfg);
if (val != pads[i].padcfg1) {
writel(pads[i].padcfg1, padcfg);
dev_dbg(dev, "restored pin %u padcfg1 %#08x\n",
desc->number, readl(padcfg));
}
padcfg = intel_get_padcfg(pctrl, desc->number, PADCFG2);
if (padcfg) {
val = readl(padcfg);
if (val != pads[i].padcfg2) {
writel(pads[i].padcfg2, padcfg);
dev_dbg(dev, "restored pin %u padcfg2 %#08x\n",
desc->number, readl(padcfg));
}
}
}
communities = pctrl->context.communities;
for (i = 0; i < pctrl->ncommunities; i++) {
struct intel_community *community = &pctrl->communities[i];
void __iomem *base;
unsigned gpp;
base = community->regs + community->ie_offset;
for (gpp = 0; gpp < community->ngpps; gpp++) {
writel(communities[i].intmask[gpp], base + gpp * 4);
dev_dbg(dev, "restored mask %d/%u %#08x\n", i, gpp,
readl(base + gpp * 4));
}
}
return 0;
}
