static void __iomem *chv_padreg(struct chv_pinctrl *pctrl, unsigned offset,
unsigned reg)
{
unsigned family_no = offset / MAX_FAMILY_PAD_GPIO_NO;
unsigned pad_no = offset % MAX_FAMILY_PAD_GPIO_NO;
offset = FAMILY_PAD_REGS_OFF + FAMILY_PAD_REGS_SIZE * family_no +
GPIO_REGS_SIZE * pad_no;
return pctrl->regs + offset + reg;
}
static void chv_writel(u32 value, void __iomem *reg)
{
writel(value, reg);
readl(reg);
}
static bool chv_pad_locked(struct chv_pinctrl *pctrl, unsigned offset)
{
void __iomem *reg;
reg = chv_padreg(pctrl, offset, CHV_PADCTRL1);
return readl(reg) & CHV_PADCTRL1_CFGLOCK;
}
static int chv_get_groups_count(struct pinctrl_dev *pctldev)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->community->ngroups;
}
static const char *chv_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->community->groups[group].name;
}
static int chv_get_group_pins(struct pinctrl_dev *pctldev, unsigned group,
const unsigned **pins, unsigned *npins)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
*pins = pctrl->community->groups[group].pins;
*npins = pctrl->community->groups[group].npins;
return 0;
}
static void chv_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned offset)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
unsigned long flags;
u32 ctrl0, ctrl1;
bool locked;
raw_spin_lock_irqsave(&chv_lock, flags);
ctrl0 = readl(chv_padreg(pctrl, offset, CHV_PADCTRL0));
ctrl1 = readl(chv_padreg(pctrl, offset, CHV_PADCTRL1));
locked = chv_pad_locked(pctrl, offset);
raw_spin_unlock_irqrestore(&chv_lock, flags);
if (ctrl0 & CHV_PADCTRL0_GPIOEN) {
seq_puts(s, "GPIO ");
} else {
u32 mode;
mode = ctrl0 & CHV_PADCTRL0_PMODE_MASK;
mode >>= CHV_PADCTRL0_PMODE_SHIFT;
seq_printf(s, "mode %d ", mode);
}
seq_printf(s, "ctrl0 0x%08x ctrl1 0x%08x", ctrl0, ctrl1);
if (locked)
seq_puts(s, " [LOCKED]");
}
static int chv_get_functions_count(struct pinctrl_dev *pctldev)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->community->nfunctions;
}
static const char *chv_get_function_name(struct pinctrl_dev *pctldev,
unsigned function)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->community->functions[function].name;
}
static int chv_get_function_groups(struct pinctrl_dev *pctldev,
unsigned function,
const char * const **groups,
unsigned * const ngroups)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
*groups = pctrl->community->functions[function].groups;
*ngroups = pctrl->community->functions[function].ngroups;
return 0;
}
static int chv_pinmux_set_mux(struct pinctrl_dev *pctldev, unsigned function,
unsigned group)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
const struct chv_pingroup *grp;
unsigned long flags;
int i;
grp = &pctrl->community->groups[group];
raw_spin_lock_irqsave(&chv_lock, flags);
for (i = 0; i < grp->npins; i++) {
if (chv_pad_locked(pctrl, grp->pins[i])) {
dev_warn(pctrl->dev, "unable to set mode for locked pin %u\n",
grp->pins[i]);
raw_spin_unlock_irqrestore(&chv_lock, flags);
return -EBUSY;
}
}
for (i = 0; i < grp->npins; i++) {
const struct chv_alternate_function *altfunc = &grp->altfunc;
int pin = grp->pins[i];
void __iomem *reg;
u32 value;
if (grp->overrides) {
int j;
for (j = 0; j < grp->noverrides; j++) {
if (grp->overrides[j].pin == pin) {
altfunc = &grp->overrides[j];
break;
}
}
}
reg = chv_padreg(pctrl, pin, CHV_PADCTRL0);
value = readl(reg);
value &= ~CHV_PADCTRL0_GPIOEN;
value &= ~CHV_PADCTRL0_PMODE_MASK;
value |= altfunc->mode << CHV_PADCTRL0_PMODE_SHIFT;
chv_writel(value, reg);
reg = chv_padreg(pctrl, pin, CHV_PADCTRL1);
value = readl(reg) & ~CHV_PADCTRL1_INVRXTX_MASK;
if (altfunc->invert_oe)
value |= CHV_PADCTRL1_INVRXTX_TXENABLE;
chv_writel(value, reg);
dev_dbg(pctrl->dev, "configured pin %u mode %u OE %sinverted\n",
pin, altfunc->mode, altfunc->invert_oe ? "" : "not ");
}
raw_spin_unlock_irqrestore(&chv_lock, flags);
return 0;
}
static int chv_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
unsigned long flags;
void __iomem *reg;
u32 value;
raw_spin_lock_irqsave(&chv_lock, flags);
if (chv_pad_locked(pctrl, offset)) {
value = readl(chv_padreg(pctrl, offset, CHV_PADCTRL0));
if (!(value & CHV_PADCTRL0_GPIOEN)) {
raw_spin_unlock_irqrestore(&chv_lock, flags);
return -EBUSY;
}
} else {
int i;
for (i = 0; i < ARRAY_SIZE(pctrl->intr_lines); i++) {
if (pctrl->intr_lines[i] == offset) {
pctrl->intr_lines[i] = 0;
break;
}
}
reg = chv_padreg(pctrl, offset, CHV_PADCTRL1);
value = readl(reg);
value &= ~CHV_PADCTRL1_INTWAKECFG_MASK;
value &= ~CHV_PADCTRL1_INVRXTX_MASK;
chv_writel(value, reg);
reg = chv_padreg(pctrl, offset, CHV_PADCTRL0);
value = readl(reg);
if ((value & CHV_PADCTRL0_GPIOCFG_MASK) ==
(CHV_PADCTRL0_GPIOCFG_HIZ << CHV_PADCTRL0_GPIOCFG_SHIFT)) {
value &= ~CHV_PADCTRL0_GPIOCFG_MASK;
value |= CHV_PADCTRL0_GPIOCFG_GPI <<
CHV_PADCTRL0_GPIOCFG_SHIFT;
}
value |= CHV_PADCTRL0_GPIOEN;
chv_writel(value, reg);
}
raw_spin_unlock_irqrestore(&chv_lock, flags);
return 0;
}
static void chv_gpio_disable_free(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
unsigned long flags;
void __iomem *reg;
u32 value;
raw_spin_lock_irqsave(&chv_lock, flags);
reg = chv_padreg(pctrl, offset, CHV_PADCTRL0);
value = readl(reg) & ~CHV_PADCTRL0_GPIOEN;
chv_writel(value, reg);
raw_spin_unlock_irqrestore(&chv_lock, flags);
}
static int chv_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset, bool input)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
void __iomem *reg = chv_padreg(pctrl, offset, CHV_PADCTRL0);
unsigned long flags;
u32 ctrl0;
raw_spin_lock_irqsave(&chv_lock, flags);
ctrl0 = readl(reg) & ~CHV_PADCTRL0_GPIOCFG_MASK;
if (input)
ctrl0 |= CHV_PADCTRL0_GPIOCFG_GPI << CHV_PADCTRL0_GPIOCFG_SHIFT;
else
ctrl0 |= CHV_PADCTRL0_GPIOCFG_GPO << CHV_PADCTRL0_GPIOCFG_SHIFT;
chv_writel(ctrl0, reg);
raw_spin_unlock_irqrestore(&chv_lock, flags);
return 0;
}
static int chv_config_get(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
unsigned long flags;
u32 ctrl0, ctrl1;
u16 arg = 0;
u32 term;
raw_spin_lock_irqsave(&chv_lock, flags);
ctrl0 = readl(chv_padreg(pctrl, pin, CHV_PADCTRL0));
ctrl1 = readl(chv_padreg(pctrl, pin, CHV_PADCTRL1));
raw_spin_unlock_irqrestore(&chv_lock, flags);
term = (ctrl0 & CHV_PADCTRL0_TERM_MASK) >> CHV_PADCTRL0_TERM_SHIFT;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if (term)
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_UP:
if (!(ctrl0 & CHV_PADCTRL0_TERM_UP))
return -EINVAL;
switch (term) {
case CHV_PADCTRL0_TERM_20K:
arg = 20000;
break;
case CHV_PADCTRL0_TERM_5K:
arg = 5000;
break;
case CHV_PADCTRL0_TERM_1K:
arg = 1000;
break;
}
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (!term || (ctrl0 & CHV_PADCTRL0_TERM_UP))
return -EINVAL;
switch (term) {
case CHV_PADCTRL0_TERM_20K:
arg = 20000;
break;
case CHV_PADCTRL0_TERM_5K:
arg = 5000;
break;
}
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
if (!(ctrl1 & CHV_PADCTRL1_ODEN))
return -EINVAL;
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE: {
u32 cfg;
cfg = ctrl0 & CHV_PADCTRL0_GPIOCFG_MASK;
cfg >>= CHV_PADCTRL0_GPIOCFG_SHIFT;
if (cfg != CHV_PADCTRL0_GPIOCFG_HIZ)
return -EINVAL;
break;
}
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int chv_config_set_pull(struct chv_pinctrl *pctrl, unsigned pin,
enum pin_config_param param, u16 arg)
{
void __iomem *reg = chv_padreg(pctrl, pin, CHV_PADCTRL0);
unsigned long flags;
u32 ctrl0, pull;
raw_spin_lock_irqsave(&chv_lock, flags);
ctrl0 = readl(reg);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
ctrl0 &= ~(CHV_PADCTRL0_TERM_MASK | CHV_PADCTRL0_TERM_UP);
break;
case PIN_CONFIG_BIAS_PULL_UP:
ctrl0 &= ~(CHV_PADCTRL0_TERM_MASK | CHV_PADCTRL0_TERM_UP);
switch (arg) {
case 1000:
pull = CHV_PADCTRL0_TERM_1K << CHV_PADCTRL0_TERM_SHIFT;
break;
case 5000:
pull = CHV_PADCTRL0_TERM_5K << CHV_PADCTRL0_TERM_SHIFT;
break;
case 20000:
pull = CHV_PADCTRL0_TERM_20K << CHV_PADCTRL0_TERM_SHIFT;
break;
default:
raw_spin_unlock_irqrestore(&chv_lock, flags);
return -EINVAL;
}
ctrl0 |= CHV_PADCTRL0_TERM_UP | pull;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
ctrl0 &= ~(CHV_PADCTRL0_TERM_MASK | CHV_PADCTRL0_TERM_UP);
switch (arg) {
case 5000:
pull = CHV_PADCTRL0_TERM_5K << CHV_PADCTRL0_TERM_SHIFT;
break;
case 20000:
pull = CHV_PADCTRL0_TERM_20K << CHV_PADCTRL0_TERM_SHIFT;
break;
default:
raw_spin_unlock_irqrestore(&chv_lock, flags);
return -EINVAL;
}
ctrl0 |= pull;
break;
default:
raw_spin_unlock_irqrestore(&chv_lock, flags);
return -EINVAL;
}
chv_writel(ctrl0, reg);
raw_spin_unlock_irqrestore(&chv_lock, flags);
return 0;
}
static int chv_config_set_oden(struct chv_pinctrl *pctrl, unsigned int pin,
bool enable)
{
void __iomem *reg = chv_padreg(pctrl, pin, CHV_PADCTRL1);
unsigned long flags;
u32 ctrl1;
raw_spin_lock_irqsave(&chv_lock, flags);
ctrl1 = readl(reg);
if (enable)
ctrl1 |= CHV_PADCTRL1_ODEN;
else
ctrl1 &= ~CHV_PADCTRL1_ODEN;
chv_writel(ctrl1, reg);
raw_spin_unlock_irqrestore(&chv_lock, flags);
return 0;
}
static int chv_config_set(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *configs, unsigned nconfigs)
{
struct chv_pinctrl *pctrl = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
int i, ret;
u16 arg;
if (chv_pad_locked(pctrl, pin))
return -EBUSY;
for (i = 0; i < nconfigs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
ret = chv_config_set_pull(pctrl, pin, param, arg);
if (ret)
return ret;
break;
case PIN_CONFIG_DRIVE_PUSH_PULL:
ret = chv_config_set_oden(pctrl, pin, false);
if (ret)
return ret;
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
ret = chv_config_set_oden(pctrl, pin, true);
if (ret)
return ret;
break;
default:
return -ENOTSUPP;
}
dev_dbg(pctrl->dev, "pin %d set config %d arg %u\n", pin,
param, arg);
}
return 0;
}
static int chv_config_group_get(struct pinctrl_dev *pctldev,
unsigned int group,
unsigned long *config)
{
const unsigned int *pins;
unsigned int npins;
int ret;
ret = chv_get_group_pins(pctldev, group, &pins, &npins);
if (ret)
return ret;
ret = chv_config_get(pctldev, pins[0], config);
if (ret)
return ret;
return 0;
}
static int chv_config_group_set(struct pinctrl_dev *pctldev,
unsigned int group, unsigned long *configs,
unsigned int num_configs)
{
const unsigned int *pins;
unsigned int npins;
int i, ret;
ret = chv_get_group_pins(pctldev, group, &pins, &npins);
if (ret)
return ret;
for (i = 0; i < npins; i++) {
ret = chv_config_set(pctldev, pins[i], configs, num_configs);
if (ret)
return ret;
}
return 0;
}
static unsigned chv_gpio_offset_to_pin(struct chv_pinctrl *pctrl,
unsigned offset)
{
return pctrl->community->pins[offset].number;
}
static int chv_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct chv_pinctrl *pctrl = gpiochip_get_data(chip);
int pin = chv_gpio_offset_to_pin(pctrl, offset);
unsigned long flags;
u32 ctrl0, cfg;
raw_spin_lock_irqsave(&chv_lock, flags);
ctrl0 = readl(chv_padreg(pctrl, pin, CHV_PADCTRL0));
raw_spin_unlock_irqrestore(&chv_lock, flags);
cfg = ctrl0 & CHV_PADCTRL0_GPIOCFG_MASK;
cfg >>= CHV_PADCTRL0_GPIOCFG_SHIFT;
if (cfg == CHV_PADCTRL0_GPIOCFG_GPO)
return !!(ctrl0 & CHV_PADCTRL0_GPIOTXSTATE);
return !!(ctrl0 & CHV_PADCTRL0_GPIORXSTATE);
}
static void chv_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct chv_pinctrl *pctrl = gpiochip_get_data(chip);
unsigned pin = chv_gpio_offset_to_pin(pctrl, offset);
unsigned long flags;
void __iomem *reg;
u32 ctrl0;
raw_spin_lock_irqsave(&chv_lock, flags);
reg = chv_padreg(pctrl, pin, CHV_PADCTRL0);
ctrl0 = readl(reg);
if (value)
ctrl0 |= CHV_PADCTRL0_GPIOTXSTATE;
else
ctrl0 &= ~CHV_PADCTRL0_GPIOTXSTATE;
chv_writel(ctrl0, reg);
raw_spin_unlock_irqrestore(&chv_lock, flags);
}
static int chv_gpio_get_direction(struct gpio_chip *chip, unsigned offset)
{
struct chv_pinctrl *pctrl = gpiochip_get_data(chip);
unsigned pin = chv_gpio_offset_to_pin(pctrl, offset);
u32 ctrl0, direction;
unsigned long flags;
raw_spin_lock_irqsave(&chv_lock, flags);
ctrl0 = readl(chv_padreg(pctrl, pin, CHV_PADCTRL0));
raw_spin_unlock_irqrestore(&chv_lock, flags);
direction = ctrl0 & CHV_PADCTRL0_GPIOCFG_MASK;
direction >>= CHV_PADCTRL0_GPIOCFG_SHIFT;
return direction != CHV_PADCTRL0_GPIOCFG_GPO;
}
static int chv_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_gpio_direction_input(chip->base + offset);
}
static int chv_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
chv_gpio_set(chip, offset, value);
return pinctrl_gpio_direction_output(chip->base + offset);
}
static void chv_gpio_irq_ack(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct chv_pinctrl *pctrl = gpiochip_get_data(gc);
int pin = chv_gpio_offset_to_pin(pctrl, irqd_to_hwirq(d));
u32 intr_line;
raw_spin_lock(&chv_lock);
intr_line = readl(chv_padreg(pctrl, pin, CHV_PADCTRL0));
intr_line &= CHV_PADCTRL0_INTSEL_MASK;
intr_line >>= CHV_PADCTRL0_INTSEL_SHIFT;
chv_writel(BIT(intr_line), pctrl->regs + CHV_INTSTAT);
raw_spin_unlock(&chv_lock);
}
static void chv_gpio_irq_mask_unmask(struct irq_data *d, bool mask)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct chv_pinctrl *pctrl = gpiochip_get_data(gc);
int pin = chv_gpio_offset_to_pin(pctrl, irqd_to_hwirq(d));
u32 value, intr_line;
unsigned long flags;
raw_spin_lock_irqsave(&chv_lock, flags);
intr_line = readl(chv_padreg(pctrl, pin, CHV_PADCTRL0));
intr_line &= CHV_PADCTRL0_INTSEL_MASK;
intr_line >>= CHV_PADCTRL0_INTSEL_SHIFT;
value = readl(pctrl->regs + CHV_INTMASK);
if (mask)
value &= ~BIT(intr_line);
else
value |= BIT(intr_line);
chv_writel(value, pctrl->regs + CHV_INTMASK);
raw_spin_unlock_irqrestore(&chv_lock, flags);
}
static void chv_gpio_irq_mask(struct irq_data *d)
{
chv_gpio_irq_mask_unmask(d, true);
}
static void chv_gpio_irq_unmask(struct irq_data *d)
{
chv_gpio_irq_mask_unmask(d, false);
}
static unsigned chv_gpio_irq_startup(struct irq_data *d)
{
if (irqd_get_trigger_type(d) == IRQ_TYPE_NONE) {
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct chv_pinctrl *pctrl = gpiochip_get_data(gc);
unsigned offset = irqd_to_hwirq(d);
int pin = chv_gpio_offset_to_pin(pctrl, offset);
irq_flow_handler_t handler;
unsigned long flags;
u32 intsel, value;
raw_spin_lock_irqsave(&chv_lock, flags);
intsel = readl(chv_padreg(pctrl, pin, CHV_PADCTRL0));
intsel &= CHV_PADCTRL0_INTSEL_MASK;
intsel >>= CHV_PADCTRL0_INTSEL_SHIFT;
value = readl(chv_padreg(pctrl, pin, CHV_PADCTRL1));
if (value & CHV_PADCTRL1_INTWAKECFG_LEVEL)
handler = handle_level_irq;
else
handler = handle_edge_irq;
if (!pctrl->intr_lines[intsel]) {
irq_set_handler_locked(d, handler);
pctrl->intr_lines[intsel] = offset;
}
raw_spin_unlock_irqrestore(&chv_lock, flags);
}
chv_gpio_irq_unmask(d);
return 0;
}
static int chv_gpio_irq_type(struct irq_data *d, unsigned type)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct chv_pinctrl *pctrl = gpiochip_get_data(gc);
unsigned offset = irqd_to_hwirq(d);
int pin = chv_gpio_offset_to_pin(pctrl, offset);
unsigned long flags;
u32 value;
raw_spin_lock_irqsave(&chv_lock, flags);
if (!chv_pad_locked(pctrl, pin)) {
void __iomem *reg = chv_padreg(pctrl, pin, CHV_PADCTRL1);
value = readl(reg);
value &= ~CHV_PADCTRL1_INTWAKECFG_MASK;
value &= ~CHV_PADCTRL1_INVRXTX_MASK;
if (type & IRQ_TYPE_EDGE_BOTH) {
if ((type & IRQ_TYPE_EDGE_BOTH) == IRQ_TYPE_EDGE_BOTH)
value |= CHV_PADCTRL1_INTWAKECFG_BOTH;
else if (type & IRQ_TYPE_EDGE_RISING)
value |= CHV_PADCTRL1_INTWAKECFG_RISING;
else if (type & IRQ_TYPE_EDGE_FALLING)
value |= CHV_PADCTRL1_INTWAKECFG_FALLING;
} else if (type & IRQ_TYPE_LEVEL_MASK) {
value |= CHV_PADCTRL1_INTWAKECFG_LEVEL;
if (type & IRQ_TYPE_LEVEL_LOW)
value |= CHV_PADCTRL1_INVRXTX_RXDATA;
}
chv_writel(value, reg);
}
value = readl(chv_padreg(pctrl, pin, CHV_PADCTRL0));
value &= CHV_PADCTRL0_INTSEL_MASK;
value >>= CHV_PADCTRL0_INTSEL_SHIFT;
pctrl->intr_lines[value] = offset;
if (type & IRQ_TYPE_EDGE_BOTH)
irq_set_handler_locked(d, handle_edge_irq);
else if (type & IRQ_TYPE_LEVEL_MASK)
irq_set_handler_locked(d, handle_level_irq);
raw_spin_unlock_irqrestore(&chv_lock, flags);
return 0;
}
static void chv_gpio_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct chv_pinctrl *pctrl = gpiochip_get_data(gc);
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned long pending;
u32 intr_line;
chained_irq_enter(chip, desc);
pending = readl(pctrl->regs + CHV_INTSTAT);
for_each_set_bit(intr_line, &pending, pctrl->community->nirqs) {
unsigned irq, offset;
offset = pctrl->intr_lines[intr_line];
irq = irq_find_mapping(gc->irqdomain, offset);
generic_handle_irq(irq);
}
chained_irq_exit(chip, desc);
}
static int chv_gpio_probe(struct chv_pinctrl *pctrl, int irq)
{
const struct chv_gpio_pinrange *range;
struct gpio_chip *chip = &pctrl->chip;
int ret, i, offset;
*chip = chv_gpio_chip;
chip->ngpio = pctrl->community->ngpios;
chip->label = dev_name(pctrl->dev);
chip->parent = pctrl->dev;
chip->base = -1;
chip->irq_need_valid_mask = true;
ret = devm_gpiochip_add_data(pctrl->dev, chip, pctrl);
if (ret) {
dev_err(pctrl->dev, "Failed to register gpiochip\n");
return ret;
}
for (i = 0, offset = 0; i < pctrl->community->ngpio_ranges; i++) {
range = &pctrl->community->gpio_ranges[i];
ret = gpiochip_add_pin_range(chip, dev_name(pctrl->dev), offset,
range->base, range->npins);
if (ret) {
dev_err(pctrl->dev, "failed to add GPIO pin range\n");
return ret;
}
offset += range->npins;
}
for (i = 0; i < pctrl->community->npins; i++) {
const struct pinctrl_pin_desc *desc;
u32 intsel;
desc = &pctrl->community->pins[i];
intsel = readl(chv_padreg(pctrl, desc->number, CHV_PADCTRL0));
intsel &= CHV_PADCTRL0_INTSEL_MASK;
intsel >>= CHV_PADCTRL0_INTSEL_SHIFT;
if (intsel >= pctrl->community->nirqs)
clear_bit(i, chip->irq_valid_mask);
}
chv_writel(0xffff, pctrl->regs + CHV_INTSTAT);
ret = gpiochip_irqchip_add(chip, &chv_gpio_irqchip, 0,
handle_bad_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(pctrl->dev, "failed to add IRQ chip\n");
return ret;
}
gpiochip_set_chained_irqchip(chip, &chv_gpio_irqchip, irq,
chv_gpio_irq_handler);
return 0;
}
static int chv_pinctrl_probe(struct platform_device *pdev)
{
struct chv_pinctrl *pctrl;
struct acpi_device *adev;
struct resource *res;
int ret, irq, i;
adev = ACPI_COMPANION(&pdev->dev);
if (!adev)
return -ENODEV;
pctrl = devm_kzalloc(&pdev->dev, sizeof(*pctrl), GFP_KERNEL);
if (!pctrl)
return -ENOMEM;
for (i = 0; i < ARRAY_SIZE(chv_communities); i++)
if (!strcmp(adev->pnp.unique_id, chv_communities[i]->uid)) {
pctrl->community = chv_communities[i];
break;
}
if (i == ARRAY_SIZE(chv_communities))
return -ENODEV;
pctrl->dev = &pdev->dev;
#ifdef CONFIG_PM_SLEEP
pctrl->saved_pin_context = devm_kcalloc(pctrl->dev,
pctrl->community->npins, sizeof(*pctrl->saved_pin_context),
GFP_KERNEL);
if (!pctrl->saved_pin_context)
return -ENOMEM;
#endif
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pctrl->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pctrl->regs))
return PTR_ERR(pctrl->regs);
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get interrupt number\n");
return irq;
}
pctrl->pctldesc = chv_pinctrl_desc;
pctrl->pctldesc.name = dev_name(&pdev->dev);
pctrl->pctldesc.pins = pctrl->community->pins;
pctrl->pctldesc.npins = pctrl->community->npins;
pctrl->pctldev = devm_pinctrl_register(&pdev->dev, &pctrl->pctldesc,
pctrl);
if (IS_ERR(pctrl->pctldev)) {
dev_err(&pdev->dev, "failed to register pinctrl driver\n");
return PTR_ERR(pctrl->pctldev);
}
ret = chv_gpio_probe(pctrl, irq);
if (ret)
return ret;
platform_set_drvdata(pdev, pctrl);
return 0;
}
static int chv_pinctrl_suspend_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct chv_pinctrl *pctrl = platform_get_drvdata(pdev);
unsigned long flags;
int i;
raw_spin_lock_irqsave(&chv_lock, flags);
pctrl->saved_intmask = readl(pctrl->regs + CHV_INTMASK);
for (i = 0; i < pctrl->community->npins; i++) {
const struct pinctrl_pin_desc *desc;
struct chv_pin_context *ctx;
void __iomem *reg;
desc = &pctrl->community->pins[i];
if (chv_pad_locked(pctrl, desc->number))
continue;
ctx = &pctrl->saved_pin_context[i];
reg = chv_padreg(pctrl, desc->number, CHV_PADCTRL0);
ctx->padctrl0 = readl(reg) & ~CHV_PADCTRL0_GPIORXSTATE;
reg = chv_padreg(pctrl, desc->number, CHV_PADCTRL1);
ctx->padctrl1 = readl(reg);
}
raw_spin_unlock_irqrestore(&chv_lock, flags);
return 0;
}
static int chv_pinctrl_resume_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct chv_pinctrl *pctrl = platform_get_drvdata(pdev);
unsigned long flags;
int i;
raw_spin_lock_irqsave(&chv_lock, flags);
chv_writel(0, pctrl->regs + CHV_INTMASK);
for (i = 0; i < pctrl->community->npins; i++) {
const struct pinctrl_pin_desc *desc;
const struct chv_pin_context *ctx;
void __iomem *reg;
u32 val;
desc = &pctrl->community->pins[i];
if (chv_pad_locked(pctrl, desc->number))
continue;
ctx = &pctrl->saved_pin_context[i];
reg = chv_padreg(pctrl, desc->number, CHV_PADCTRL0);
val = readl(reg) & ~CHV_PADCTRL0_GPIORXSTATE;
if (ctx->padctrl0 != val) {
chv_writel(ctx->padctrl0, reg);
dev_dbg(pctrl->dev, "restored pin %2u ctrl0 0x%08x\n",
desc->number, readl(reg));
}
reg = chv_padreg(pctrl, desc->number, CHV_PADCTRL1);
val = readl(reg);
if (ctx->padctrl1 != val) {
chv_writel(ctx->padctrl1, reg);
dev_dbg(pctrl->dev, "restored pin %2u ctrl1 0x%08x\n",
desc->number, readl(reg));
}
}
chv_writel(0xffff, pctrl->regs + CHV_INTSTAT);
chv_writel(pctrl->saved_intmask, pctrl->regs + CHV_INTMASK);
raw_spin_unlock_irqrestore(&chv_lock, flags);
return 0;
}
static int __init chv_pinctrl_init(void)
{
return platform_driver_register(&chv_pinctrl_driver);
}
static void __exit chv_pinctrl_exit(void)
{
platform_driver_unregister(&chv_pinctrl_driver);
}
