static struct byt_community *byt_get_community(struct byt_gpio *vg,
unsigned int pin)
{
struct byt_community *comm;
int i;
for (i = 0; i < vg->soc_data->ncommunities; i++) {
comm = vg->communities_copy + i;
if (pin < comm->pin_base + comm->npins && pin >= comm->pin_base)
return comm;
}
return NULL;
}
static void __iomem *byt_gpio_reg(struct byt_gpio *vg, unsigned int offset,
int reg)
{
struct byt_community *comm = byt_get_community(vg, offset);
u32 reg_offset = 0;
if (!comm)
return NULL;
offset -= comm->pin_base;
if (reg == BYT_INT_STAT_REG)
reg_offset = (offset / 32) * 4;
else
reg_offset = comm->pad_map[offset] * 16;
return comm->reg_base + reg_offset + reg;
}
static int byt_get_groups_count(struct pinctrl_dev *pctldev)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctldev);
return vg->soc_data->ngroups;
}
static const char *byt_get_group_name(struct pinctrl_dev *pctldev,
unsigned int selector)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctldev);
return vg->soc_data->groups[selector].name;
}
static int byt_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int selector,
const unsigned int **pins,
unsigned int *num_pins)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctldev);
*pins = vg->soc_data->groups[selector].pins;
*num_pins = vg->soc_data->groups[selector].npins;
return 0;
}
static int byt_get_functions_count(struct pinctrl_dev *pctldev)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctldev);
return vg->soc_data->nfunctions;
}
static const char *byt_get_function_name(struct pinctrl_dev *pctldev,
unsigned int selector)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctldev);
return vg->soc_data->functions[selector].name;
}
static int byt_get_function_groups(struct pinctrl_dev *pctldev,
unsigned int selector,
const char * const **groups,
unsigned int *num_groups)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctldev);
*groups = vg->soc_data->functions[selector].groups;
*num_groups = vg->soc_data->functions[selector].ngroups;
return 0;
}
static int byt_get_group_simple_mux(const struct byt_pingroup group,
const char *func_name,
unsigned short *func)
{
int i;
for (i = 0; i < group.nfuncs; i++) {
if (!strcmp(group.simple_funcs[i].name, func_name)) {
*func = group.simple_funcs[i].func;
return 0;
}
}
return 1;
}
static int byt_get_group_mixed_mux(const struct byt_pingroup group,
const char *func_name,
const unsigned short **func)
{
int i;
for (i = 0; i < group.nfuncs; i++) {
if (!strcmp(group.mixed_funcs[i].name, func_name)) {
*func = group.mixed_funcs[i].func_values;
return 0;
}
}
return 1;
}
static void byt_set_group_simple_mux(struct byt_gpio *vg,
const struct byt_pingroup group,
unsigned short func)
{
unsigned long flags;
int i;
raw_spin_lock_irqsave(&vg->lock, flags);
for (i = 0; i < group.npins; i++) {
void __iomem *padcfg0;
u32 value;
padcfg0 = byt_gpio_reg(vg, group.pins[i], BYT_CONF0_REG);
if (!padcfg0) {
dev_warn(&vg->pdev->dev,
"Group %s, pin %i not muxed (no padcfg0)\n",
group.name, i);
continue;
}
value = readl(padcfg0);
value &= ~BYT_PIN_MUX;
value |= func;
writel(value, padcfg0);
}
raw_spin_unlock_irqrestore(&vg->lock, flags);
}
static void byt_set_group_mixed_mux(struct byt_gpio *vg,
const struct byt_pingroup group,
const unsigned short *func)
{
unsigned long flags;
int i;
raw_spin_lock_irqsave(&vg->lock, flags);
for (i = 0; i < group.npins; i++) {
void __iomem *padcfg0;
u32 value;
padcfg0 = byt_gpio_reg(vg, group.pins[i], BYT_CONF0_REG);
if (!padcfg0) {
dev_warn(&vg->pdev->dev,
"Group %s, pin %i not muxed (no padcfg0)\n",
group.name, i);
continue;
}
value = readl(padcfg0);
value &= ~BYT_PIN_MUX;
value |= func[i];
writel(value, padcfg0);
}
raw_spin_unlock_irqrestore(&vg->lock, flags);
}
static int byt_set_mux(struct pinctrl_dev *pctldev, unsigned int func_selector,
unsigned int group_selector)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctldev);
const struct byt_function func = vg->soc_data->functions[func_selector];
const struct byt_pingroup group = vg->soc_data->groups[group_selector];
const unsigned short *mixed_func;
unsigned short simple_func;
int ret = 1;
if (group.has_simple_funcs)
ret = byt_get_group_simple_mux(group, func.name, &simple_func);
else
ret = byt_get_group_mixed_mux(group, func.name, &mixed_func);
if (ret)
byt_set_group_simple_mux(vg, group, BYT_DEFAULT_GPIO_MUX);
else if (group.has_simple_funcs)
byt_set_group_simple_mux(vg, group, simple_func);
else
byt_set_group_mixed_mux(vg, group, mixed_func);
return 0;
}
static u32 byt_get_gpio_mux(struct byt_gpio *vg, unsigned offset)
{
if (!strcmp(vg->soc_data->uid, BYT_SCORE_ACPI_UID) &&
offset >= 92 && offset <= 93)
return 1;
if (!strcmp(vg->soc_data->uid, BYT_SUS_ACPI_UID) &&
offset >= 11 && offset <= 21)
return 1;
return 0;
}
static void byt_gpio_clear_triggering(struct byt_gpio *vg, unsigned int offset)
{
void __iomem *reg = byt_gpio_reg(vg, offset, BYT_CONF0_REG);
unsigned long flags;
u32 value;
raw_spin_lock_irqsave(&vg->lock, flags);
value = readl(reg);
value &= ~(BYT_TRIG_POS | BYT_TRIG_NEG | BYT_TRIG_LVL);
writel(value, reg);
raw_spin_unlock_irqrestore(&vg->lock, flags);
}
static int byt_gpio_request_enable(struct pinctrl_dev *pctl_dev,
struct pinctrl_gpio_range *range,
unsigned int offset)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctl_dev);
void __iomem *reg = byt_gpio_reg(vg, offset, BYT_CONF0_REG);
u32 value, gpio_mux;
unsigned long flags;
raw_spin_lock_irqsave(&vg->lock, flags);
value = readl(reg) & BYT_PIN_MUX;
gpio_mux = byt_get_gpio_mux(vg, offset);
if (WARN_ON(gpio_mux != value)) {
value = readl(reg) & ~BYT_PIN_MUX;
value |= gpio_mux;
writel(value, reg);
dev_warn(&vg->pdev->dev,
"pin %u forcibly re-configured as GPIO\n", offset);
}
raw_spin_unlock_irqrestore(&vg->lock, flags);
pm_runtime_get(&vg->pdev->dev);
return 0;
}
static void byt_gpio_disable_free(struct pinctrl_dev *pctl_dev,
struct pinctrl_gpio_range *range,
unsigned int offset)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctl_dev);
byt_gpio_clear_triggering(vg, offset);
pm_runtime_put(&vg->pdev->dev);
}
static int byt_gpio_set_direction(struct pinctrl_dev *pctl_dev,
struct pinctrl_gpio_range *range,
unsigned int offset,
bool input)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctl_dev);
void __iomem *val_reg = byt_gpio_reg(vg, offset, BYT_VAL_REG);
void __iomem *conf_reg = byt_gpio_reg(vg, offset, BYT_CONF0_REG);
unsigned long flags;
u32 value;
raw_spin_lock_irqsave(&vg->lock, flags);
value = readl(val_reg);
value &= ~BYT_DIR_MASK;
if (input)
value |= BYT_OUTPUT_EN;
else
WARN(readl(conf_reg) & BYT_DIRECT_IRQ_EN,
"Potential Error: Setting GPIO with direct_irq_en to output");
writel(value, val_reg);
raw_spin_unlock_irqrestore(&vg->lock, flags);
return 0;
}
static void byt_get_pull_strength(u32 reg, u16 *strength)
{
switch (reg & BYT_PULL_STR_MASK) {
case BYT_PULL_STR_2K:
*strength = 2000;
break;
case BYT_PULL_STR_10K:
*strength = 10000;
break;
case BYT_PULL_STR_20K:
*strength = 20000;
break;
case BYT_PULL_STR_40K:
*strength = 40000;
break;
}
}
static int byt_set_pull_strength(u32 *reg, u16 strength)
{
*reg &= ~BYT_PULL_STR_MASK;
switch (strength) {
case 2000:
*reg |= BYT_PULL_STR_2K;
break;
case 10000:
*reg |= BYT_PULL_STR_10K;
break;
case 20000:
*reg |= BYT_PULL_STR_20K;
break;
case 40000:
*reg |= BYT_PULL_STR_40K;
break;
default:
return -EINVAL;
}
return 0;
}
static int byt_pin_config_get(struct pinctrl_dev *pctl_dev, unsigned int offset,
unsigned long *config)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctl_dev);
enum pin_config_param param = pinconf_to_config_param(*config);
void __iomem *conf_reg = byt_gpio_reg(vg, offset, BYT_CONF0_REG);
void __iomem *val_reg = byt_gpio_reg(vg, offset, BYT_VAL_REG);
unsigned long flags;
u32 conf, pull, val, debounce;
u16 arg = 0;
raw_spin_lock_irqsave(&vg->lock, flags);
conf = readl(conf_reg);
pull = conf & BYT_PULL_ASSIGN_MASK;
val = readl(val_reg);
raw_spin_unlock_irqrestore(&vg->lock, flags);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if (pull)
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if ((val & BYT_INPUT_EN) || pull != BYT_PULL_ASSIGN_DOWN)
return -EINVAL;
byt_get_pull_strength(conf, &arg);
break;
case PIN_CONFIG_BIAS_PULL_UP:
if ((val & BYT_INPUT_EN) || pull != BYT_PULL_ASSIGN_UP)
return -EINVAL;
byt_get_pull_strength(conf, &arg);
break;
case PIN_CONFIG_INPUT_DEBOUNCE:
if (!(conf & BYT_DEBOUNCE_EN))
return -EINVAL;
raw_spin_lock_irqsave(&vg->lock, flags);
debounce = readl(byt_gpio_reg(vg, offset, BYT_DEBOUNCE_REG));
raw_spin_unlock_irqrestore(&vg->lock, flags);
switch (debounce & BYT_DEBOUNCE_PULSE_MASK) {
case BYT_DEBOUNCE_PULSE_375US:
arg = 375;
break;
case BYT_DEBOUNCE_PULSE_750US:
arg = 750;
break;
case BYT_DEBOUNCE_PULSE_1500US:
arg = 1500;
break;
case BYT_DEBOUNCE_PULSE_3MS:
arg = 3000;
break;
case BYT_DEBOUNCE_PULSE_6MS:
arg = 6000;
break;
case BYT_DEBOUNCE_PULSE_12MS:
arg = 12000;
break;
case BYT_DEBOUNCE_PULSE_24MS:
arg = 24000;
break;
default:
return -EINVAL;
}
break;
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int byt_pin_config_set(struct pinctrl_dev *pctl_dev,
unsigned int offset,
unsigned long *configs,
unsigned int num_configs)
{
struct byt_gpio *vg = pinctrl_dev_get_drvdata(pctl_dev);
unsigned int param, arg;
void __iomem *conf_reg = byt_gpio_reg(vg, offset, BYT_CONF0_REG);
void __iomem *val_reg = byt_gpio_reg(vg, offset, BYT_VAL_REG);
unsigned long flags;
u32 conf, val, debounce;
int i, ret = 0;
raw_spin_lock_irqsave(&vg->lock, flags);
conf = readl(conf_reg);
val = readl(val_reg);
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
conf &= ~BYT_PULL_ASSIGN_MASK;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (arg == 1)
arg = 2000;
if (val & BYT_INPUT_EN) {
val &= ~BYT_INPUT_EN;
writel(val, val_reg);
dev_warn(&vg->pdev->dev,
"pin %u forcibly set to input mode\n",
offset);
}
conf &= ~BYT_PULL_ASSIGN_MASK;
conf |= BYT_PULL_ASSIGN_DOWN;
ret = byt_set_pull_strength(&conf, arg);
break;
case PIN_CONFIG_BIAS_PULL_UP:
if (arg == 1)
arg = 2000;
if (val & BYT_INPUT_EN) {
val &= ~BYT_INPUT_EN;
writel(val, val_reg);
dev_warn(&vg->pdev->dev,
"pin %u forcibly set to input mode\n",
offset);
}
conf &= ~BYT_PULL_ASSIGN_MASK;
conf |= BYT_PULL_ASSIGN_UP;
ret = byt_set_pull_strength(&conf, arg);
break;
case PIN_CONFIG_INPUT_DEBOUNCE:
debounce = readl(byt_gpio_reg(vg, offset,
BYT_DEBOUNCE_REG));
conf &= ~BYT_DEBOUNCE_PULSE_MASK;
switch (arg) {
case 375:
conf |= BYT_DEBOUNCE_PULSE_375US;
break;
case 750:
conf |= BYT_DEBOUNCE_PULSE_750US;
break;
case 1500:
conf |= BYT_DEBOUNCE_PULSE_1500US;
break;
case 3000:
conf |= BYT_DEBOUNCE_PULSE_3MS;
break;
case 6000:
conf |= BYT_DEBOUNCE_PULSE_6MS;
break;
case 12000:
conf |= BYT_DEBOUNCE_PULSE_12MS;
break;
case 24000:
conf |= BYT_DEBOUNCE_PULSE_24MS;
break;
default:
ret = -EINVAL;
}
break;
default:
ret = -ENOTSUPP;
}
if (ret)
break;
}
if (!ret)
writel(conf, conf_reg);
raw_spin_unlock_irqrestore(&vg->lock, flags);
return ret;
}
static int byt_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct byt_gpio *vg = gpiochip_get_data(chip);
void __iomem *reg = byt_gpio_reg(vg, offset, BYT_VAL_REG);
unsigned long flags;
u32 val;
raw_spin_lock_irqsave(&vg->lock, flags);
val = readl(reg);
raw_spin_unlock_irqrestore(&vg->lock, flags);
return !!(val & BYT_LEVEL);
}
static void byt_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct byt_gpio *vg = gpiochip_get_data(chip);
void __iomem *reg = byt_gpio_reg(vg, offset, BYT_VAL_REG);
unsigned long flags;
u32 old_val;
if (!reg)
return;
raw_spin_lock_irqsave(&vg->lock, flags);
old_val = readl(reg);
if (value)
writel(old_val | BYT_LEVEL, reg);
else
writel(old_val & ~BYT_LEVEL, reg);
raw_spin_unlock_irqrestore(&vg->lock, flags);
}
static int byt_gpio_get_direction(struct gpio_chip *chip, unsigned int offset)
{
struct byt_gpio *vg = gpiochip_get_data(chip);
void __iomem *reg = byt_gpio_reg(vg, offset, BYT_VAL_REG);
unsigned long flags;
u32 value;
if (!reg)
return -EINVAL;
raw_spin_lock_irqsave(&vg->lock, flags);
value = readl(reg);
raw_spin_unlock_irqrestore(&vg->lock, flags);
if (!(value & BYT_OUTPUT_EN))
return GPIOF_DIR_OUT;
if (!(value & BYT_INPUT_EN))
return GPIOF_DIR_IN;
return -EINVAL;
}
static int byt_gpio_direction_input(struct gpio_chip *chip, unsigned int offset)
{
return pinctrl_gpio_direction_input(chip->base + offset);
}
static int byt_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
int ret = pinctrl_gpio_direction_output(chip->base + offset);
if (ret)
return ret;
byt_gpio_set(chip, offset, value);
return 0;
}
static void byt_gpio_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
struct byt_gpio *vg = gpiochip_get_data(chip);
int i;
u32 conf0, val;
for (i = 0; i < vg->soc_data->npins; i++) {
const struct byt_community *comm;
const char *pull_str = NULL;
const char *pull = NULL;
void __iomem *reg;
unsigned long flags;
const char *label;
unsigned int pin;
raw_spin_lock_irqsave(&vg->lock, flags);
pin = vg->soc_data->pins[i].number;
reg = byt_gpio_reg(vg, pin, BYT_CONF0_REG);
if (!reg) {
seq_printf(s,
"Could not retrieve pin %i conf0 reg\n",
pin);
raw_spin_unlock_irqrestore(&vg->lock, flags);
continue;
}
conf0 = readl(reg);
reg = byt_gpio_reg(vg, pin, BYT_VAL_REG);
if (!reg) {
seq_printf(s,
"Could not retrieve pin %i val reg\n", pin);
raw_spin_unlock_irqrestore(&vg->lock, flags);
continue;
}
val = readl(reg);
raw_spin_unlock_irqrestore(&vg->lock, flags);
comm = byt_get_community(vg, pin);
if (!comm) {
seq_printf(s,
"Could not get community for pin %i\n", pin);
continue;
}
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
pin,
label,
val & BYT_INPUT_EN ? " " : "in",
val & BYT_OUTPUT_EN ? " " : "out",
val & BYT_LEVEL ? "hi" : "lo",
comm->pad_map[i], comm->pad_map[i] * 32,
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
}
static void byt_irq_ack(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct byt_gpio *vg = gpiochip_get_data(gc);
unsigned offset = irqd_to_hwirq(d);
void __iomem *reg;
reg = byt_gpio_reg(vg, offset, BYT_INT_STAT_REG);
if (!reg)
return;
raw_spin_lock(&vg->lock);
writel(BIT(offset % 32), reg);
raw_spin_unlock(&vg->lock);
}
static void byt_irq_mask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct byt_gpio *vg = gpiochip_get_data(gc);
byt_gpio_clear_triggering(vg, irqd_to_hwirq(d));
}
static void byt_irq_unmask(struct irq_data *d)
{
struct gpio_chip *gc = irq_data_get_irq_chip_data(d);
struct byt_gpio *vg = gpiochip_get_data(gc);
unsigned offset = irqd_to_hwirq(d);
unsigned long flags;
void __iomem *reg;
u32 value;
reg = byt_gpio_reg(vg, offset, BYT_CONF0_REG);
if (!reg)
return;
raw_spin_lock_irqsave(&vg->lock, flags);
value = readl(reg);
switch (irqd_get_trigger_type(d)) {
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
raw_spin_unlock_irqrestore(&vg->lock, flags);
}
static int byt_irq_type(struct irq_data *d, unsigned int type)
{
struct byt_gpio *vg = gpiochip_get_data(irq_data_get_irq_chip_data(d));
u32 offset = irqd_to_hwirq(d);
u32 value;
unsigned long flags;
void __iomem *reg = byt_gpio_reg(vg, offset, BYT_CONF0_REG);
if (!reg || offset >= vg->chip.ngpio)
return -EINVAL;
raw_spin_lock_irqsave(&vg->lock, flags);
value = readl(reg);
WARN(value & BYT_DIRECT_IRQ_EN,
"Bad pad config for io mode, force direct_irq_en bit clearing");
value &= ~(BYT_DIRECT_IRQ_EN | BYT_TRIG_POS | BYT_TRIG_NEG |
BYT_TRIG_LVL);
writel(value, reg);
if (type & IRQ_TYPE_EDGE_BOTH)
irq_set_handler_locked(d, handle_edge_irq);
else if (type & IRQ_TYPE_LEVEL_MASK)
irq_set_handler_locked(d, handle_level_irq);
raw_spin_unlock_irqrestore(&vg->lock, flags);
return 0;
}
static void byt_gpio_irq_handler(struct irq_desc *desc)
{
struct irq_data *data = irq_desc_get_irq_data(desc);
struct byt_gpio *vg = gpiochip_get_data(
irq_desc_get_handler_data(desc));
struct irq_chip *chip = irq_data_get_irq_chip(data);
u32 base, pin;
void __iomem *reg;
unsigned long pending;
unsigned int virq;
for (base = 0; base < vg->chip.ngpio; base += 32) {
reg = byt_gpio_reg(vg, base, BYT_INT_STAT_REG);
if (!reg) {
dev_warn(&vg->pdev->dev,
"Pin %i: could not retrieve interrupt status register\n",
base);
continue;
}
pending = readl(reg);
for_each_set_bit(pin, &pending, 32) {
virq = irq_find_mapping(vg->chip.irqdomain, base + pin);
generic_handle_irq(virq);
}
}
chip->irq_eoi(data);
}
static void byt_gpio_irq_init_hw(struct byt_gpio *vg)
{
void __iomem *reg;
u32 base, value;
int i;
for (i = 0; i < vg->soc_data->npins; i++) {
unsigned int pin = vg->soc_data->pins[i].number;
reg = byt_gpio_reg(vg, pin, BYT_CONF0_REG);
if (!reg) {
dev_warn(&vg->pdev->dev,
"Pin %i: could not retrieve conf0 register\n",
i);
continue;
}
value = readl(reg);
if ((value & BYT_PIN_MUX) == byt_get_gpio_mux(vg, i) &&
!(value & BYT_DIRECT_IRQ_EN)) {
byt_gpio_clear_triggering(vg, i);
dev_dbg(&vg->pdev->dev, "disabling GPIO %d\n", i);
}
}
for (base = 0; base < vg->soc_data->npins; base += 32) {
reg = byt_gpio_reg(vg, base, BYT_INT_STAT_REG);
if (!reg) {
dev_warn(&vg->pdev->dev,
"Pin %i: could not retrieve irq status reg\n",
base);
continue;
}
writel(0xffffffff, reg);
value = readl(reg);
if (value)
dev_err(&vg->pdev->dev,
"GPIO interrupt error, pins misconfigured\n");
}
}
static int byt_gpio_probe(struct byt_gpio *vg)
{
struct gpio_chip *gc;
struct resource *irq_rc;
int ret;
vg->chip = byt_gpio_chip;
gc = &vg->chip;
gc->label = dev_name(&vg->pdev->dev);
gc->base = -1;
gc->can_sleep = false;
gc->parent = &vg->pdev->dev;
gc->ngpio = vg->soc_data->npins;
#ifdef CONFIG_PM_SLEEP
vg->saved_context = devm_kcalloc(&vg->pdev->dev, gc->ngpio,
sizeof(*vg->saved_context), GFP_KERNEL);
#endif
ret = gpiochip_add_data(gc, vg);
if (ret) {
dev_err(&vg->pdev->dev, "failed adding byt-gpio chip\n");
return ret;
}
ret = gpiochip_add_pin_range(&vg->chip, dev_name(&vg->pdev->dev),
0, 0, vg->soc_data->npins);
if (ret) {
dev_err(&vg->pdev->dev, "failed to add GPIO pin range\n");
goto fail;
}
irq_rc = platform_get_resource(vg->pdev, IORESOURCE_IRQ, 0);
if (irq_rc && irq_rc->start) {
byt_gpio_irq_init_hw(vg);
ret = gpiochip_irqchip_add(gc, &byt_irqchip, 0,
handle_simple_irq, IRQ_TYPE_NONE);
if (ret) {
dev_err(&vg->pdev->dev, "failed to add irqchip\n");
goto fail;
}
gpiochip_set_chained_irqchip(gc, &byt_irqchip,
(unsigned)irq_rc->start,
byt_gpio_irq_handler);
}
return ret;
fail:
gpiochip_remove(&vg->chip);
return ret;
}
static int byt_set_soc_data(struct byt_gpio *vg,
const struct byt_pinctrl_soc_data *soc_data)
{
int i;
vg->soc_data = soc_data;
vg->communities_copy = devm_kcalloc(&vg->pdev->dev,
soc_data->ncommunities,
sizeof(*vg->communities_copy),
GFP_KERNEL);
if (!vg->communities_copy)
return -ENOMEM;
for (i = 0; i < soc_data->ncommunities; i++) {
struct byt_community *comm = vg->communities_copy + i;
struct resource *mem_rc;
*comm = vg->soc_data->communities[i];
mem_rc = platform_get_resource(vg->pdev, IORESOURCE_MEM, 0);
comm->reg_base = devm_ioremap_resource(&vg->pdev->dev, mem_rc);
if (IS_ERR(comm->reg_base))
return PTR_ERR(comm->reg_base);
}
return 0;
}
static int byt_pinctrl_probe(struct platform_device *pdev)
{
const struct byt_pinctrl_soc_data *soc_data = NULL;
const struct byt_pinctrl_soc_data **soc_table;
const struct acpi_device_id *acpi_id;
struct acpi_device *acpi_dev;
struct byt_gpio *vg;
int i, ret;
acpi_dev = ACPI_COMPANION(&pdev->dev);
if (!acpi_dev)
return -ENODEV;
acpi_id = acpi_match_device(byt_gpio_acpi_match, &pdev->dev);
if (!acpi_id)
return -ENODEV;
soc_table = (const struct byt_pinctrl_soc_data **)acpi_id->driver_data;
for (i = 0; soc_table[i]; i++) {
if (!strcmp(acpi_dev->pnp.unique_id, soc_table[i]->uid)) {
soc_data = soc_table[i];
break;
}
}
if (!soc_data)
return -ENODEV;
vg = devm_kzalloc(&pdev->dev, sizeof(*vg), GFP_KERNEL);
if (!vg)
return -ENOMEM;
vg->pdev = pdev;
ret = byt_set_soc_data(vg, soc_data);
if (ret) {
dev_err(&pdev->dev, "failed to set soc data\n");
return ret;
}
vg->pctl_desc = byt_pinctrl_desc;
vg->pctl_desc.name = dev_name(&pdev->dev);
vg->pctl_desc.pins = vg->soc_data->pins;
vg->pctl_desc.npins = vg->soc_data->npins;
vg->pctl_dev = pinctrl_register(&vg->pctl_desc, &pdev->dev, vg);
if (IS_ERR(vg->pctl_dev)) {
dev_err(&pdev->dev, "failed to register pinctrl driver\n");
return PTR_ERR(vg->pctl_dev);
}
raw_spin_lock_init(&vg->lock);
ret = byt_gpio_probe(vg);
if (ret) {
pinctrl_unregister(vg->pctl_dev);
return ret;
}
platform_set_drvdata(pdev, vg);
pm_runtime_enable(&pdev->dev);
return 0;
}
static int byt_gpio_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct byt_gpio *vg = platform_get_drvdata(pdev);
int i;
for (i = 0; i < vg->soc_data->npins; i++) {
void __iomem *reg;
u32 value;
unsigned int pin = vg->soc_data->pins[i].number;
reg = byt_gpio_reg(vg, pin, BYT_CONF0_REG);
if (!reg) {
dev_warn(&vg->pdev->dev,
"Pin %i: could not retrieve conf0 register\n",
i);
continue;
}
value = readl(reg) & BYT_CONF0_RESTORE_MASK;
vg->saved_context[i].conf0 = value;
reg = byt_gpio_reg(vg, pin, BYT_VAL_REG);
value = readl(reg) & BYT_VAL_RESTORE_MASK;
vg->saved_context[i].val = value;
}
return 0;
}
static int byt_gpio_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct byt_gpio *vg = platform_get_drvdata(pdev);
int i;
for (i = 0; i < vg->soc_data->npins; i++) {
void __iomem *reg;
u32 value;
unsigned int pin = vg->soc_data->pins[i].number;
reg = byt_gpio_reg(vg, pin, BYT_CONF0_REG);
if (!reg) {
dev_warn(&vg->pdev->dev,
"Pin %i: could not retrieve conf0 register\n",
i);
continue;
}
value = readl(reg);
if ((value & BYT_CONF0_RESTORE_MASK) !=
vg->saved_context[i].conf0) {
value &= ~BYT_CONF0_RESTORE_MASK;
value |= vg->saved_context[i].conf0;
writel(value, reg);
dev_info(dev, "restored pin %d conf0 %#08x", i, value);
}
reg = byt_gpio_reg(vg, pin, BYT_VAL_REG);
value = readl(reg);
if ((value & BYT_VAL_RESTORE_MASK) !=
vg->saved_context[i].val) {
u32 v;
v = value & ~BYT_VAL_RESTORE_MASK;
v |= vg->saved_context[i].val;
if (v != value) {
writel(v, reg);
dev_dbg(dev, "restored pin %d val %#08x\n",
i, v);
}
}
}
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
static int __init byt_gpio_init(void)
{
return platform_driver_register(&byt_gpio_driver);
}
