static unsigned int atmel_gpio_read(struct atmel_pioctrl *atmel_pioctrl,
unsigned int bank, unsigned int reg)
{
return readl_relaxed(atmel_pioctrl->reg_base
+ ATMEL_PIO_BANK_OFFSET * bank + reg);
}
static void atmel_gpio_write(struct atmel_pioctrl *atmel_pioctrl,
unsigned int bank, unsigned int reg,
unsigned int val)
{
writel_relaxed(val, atmel_pioctrl->reg_base
+ ATMEL_PIO_BANK_OFFSET * bank + reg);
}
static void atmel_gpio_irq_ack(struct irq_data *d)
{
}
static int atmel_gpio_irq_set_type(struct irq_data *d, unsigned type)
{
struct atmel_pioctrl *atmel_pioctrl = irq_data_get_irq_chip_data(d);
struct atmel_pin *pin = atmel_pioctrl->pins[d->hwirq];
unsigned reg;
atmel_gpio_write(atmel_pioctrl, pin->bank, ATMEL_PIO_MSKR,
BIT(pin->line));
reg = atmel_gpio_read(atmel_pioctrl, pin->bank, ATMEL_PIO_CFGR);
reg &= (~ATMEL_PIO_CFGR_EVTSEL_MASK);
switch (type) {
case IRQ_TYPE_EDGE_RISING:
irq_set_handler_locked(d, handle_edge_irq);
reg |= ATMEL_PIO_CFGR_EVTSEL_RISING;
break;
case IRQ_TYPE_EDGE_FALLING:
irq_set_handler_locked(d, handle_edge_irq);
reg |= ATMEL_PIO_CFGR_EVTSEL_FALLING;
break;
case IRQ_TYPE_EDGE_BOTH:
irq_set_handler_locked(d, handle_edge_irq);
reg |= ATMEL_PIO_CFGR_EVTSEL_BOTH;
break;
case IRQ_TYPE_LEVEL_LOW:
irq_set_handler_locked(d, handle_level_irq);
reg |= ATMEL_PIO_CFGR_EVTSEL_LOW;
break;
case IRQ_TYPE_LEVEL_HIGH:
irq_set_handler_locked(d, handle_level_irq);
reg |= ATMEL_PIO_CFGR_EVTSEL_HIGH;
break;
case IRQ_TYPE_NONE:
default:
return -EINVAL;
}
atmel_gpio_write(atmel_pioctrl, pin->bank, ATMEL_PIO_CFGR, reg);
return 0;
}
static void atmel_gpio_irq_mask(struct irq_data *d)
{
struct atmel_pioctrl *atmel_pioctrl = irq_data_get_irq_chip_data(d);
struct atmel_pin *pin = atmel_pioctrl->pins[d->hwirq];
atmel_gpio_write(atmel_pioctrl, pin->bank, ATMEL_PIO_IDR,
BIT(pin->line));
}
static void atmel_gpio_irq_unmask(struct irq_data *d)
{
struct atmel_pioctrl *atmel_pioctrl = irq_data_get_irq_chip_data(d);
struct atmel_pin *pin = atmel_pioctrl->pins[d->hwirq];
atmel_gpio_write(atmel_pioctrl, pin->bank, ATMEL_PIO_IER,
BIT(pin->line));
}
static int atmel_gpio_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct atmel_pioctrl *atmel_pioctrl = irq_data_get_irq_chip_data(d);
int bank = ATMEL_PIO_BANK(d->hwirq);
int line = ATMEL_PIO_LINE(d->hwirq);
irq_set_irq_wake(atmel_pioctrl->irqs[bank], on);
if (on)
atmel_pioctrl->pm_wakeup_sources[bank] |= BIT(line);
else
atmel_pioctrl->pm_wakeup_sources[bank] &= ~(BIT(line));
return 0;
}
static void atmel_gpio_irq_handler(struct irq_desc *desc)
{
unsigned int irq = irq_desc_get_irq(desc);
struct atmel_pioctrl *atmel_pioctrl = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
unsigned long isr;
int n, bank = -1;
for (n = 0; n < atmel_pioctrl->nbanks; n++) {
if (atmel_pioctrl->irqs[n] == irq) {
bank = n;
break;
}
}
if (bank < 0) {
dev_err(atmel_pioctrl->dev,
"no bank associated to irq %u\n", irq);
return;
}
chained_irq_enter(chip, desc);
for (;;) {
isr = (unsigned long)atmel_gpio_read(atmel_pioctrl, bank,
ATMEL_PIO_ISR);
isr &= (unsigned long)atmel_gpio_read(atmel_pioctrl, bank,
ATMEL_PIO_IMR);
if (!isr)
break;
for_each_set_bit(n, &isr, BITS_PER_LONG)
generic_handle_irq(gpio_to_irq(bank *
ATMEL_PIO_NPINS_PER_BANK + n));
}
chained_irq_exit(chip, desc);
}
static int atmel_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct atmel_pioctrl *atmel_pioctrl = gpiochip_get_data(chip);
struct atmel_pin *pin = atmel_pioctrl->pins[offset];
unsigned reg;
atmel_gpio_write(atmel_pioctrl, pin->bank, ATMEL_PIO_MSKR,
BIT(pin->line));
reg = atmel_gpio_read(atmel_pioctrl, pin->bank, ATMEL_PIO_CFGR);
reg &= ~ATMEL_PIO_DIR_MASK;
atmel_gpio_write(atmel_pioctrl, pin->bank, ATMEL_PIO_CFGR, reg);
return 0;
}
static int atmel_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct atmel_pioctrl *atmel_pioctrl = gpiochip_get_data(chip);
struct atmel_pin *pin = atmel_pioctrl->pins[offset];
unsigned reg;
reg = atmel_gpio_read(atmel_pioctrl, pin->bank, ATMEL_PIO_PDSR);
return !!(reg & BIT(pin->line));
}
static int atmel_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int value)
{
struct atmel_pioctrl *atmel_pioctrl = gpiochip_get_data(chip);
struct atmel_pin *pin = atmel_pioctrl->pins[offset];
unsigned reg;
atmel_gpio_write(atmel_pioctrl, pin->bank,
value ? ATMEL_PIO_SODR : ATMEL_PIO_CODR,
BIT(pin->line));
atmel_gpio_write(atmel_pioctrl, pin->bank, ATMEL_PIO_MSKR,
BIT(pin->line));
reg = atmel_gpio_read(atmel_pioctrl, pin->bank, ATMEL_PIO_CFGR);
reg |= ATMEL_PIO_DIR_MASK;
atmel_gpio_write(atmel_pioctrl, pin->bank, ATMEL_PIO_CFGR, reg);
return 0;
}
static void atmel_gpio_set(struct gpio_chip *chip, unsigned offset, int val)
{
struct atmel_pioctrl *atmel_pioctrl = gpiochip_get_data(chip);
struct atmel_pin *pin = atmel_pioctrl->pins[offset];
atmel_gpio_write(atmel_pioctrl, pin->bank,
val ? ATMEL_PIO_SODR : ATMEL_PIO_CODR,
BIT(pin->line));
}
static int atmel_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct atmel_pioctrl *atmel_pioctrl = gpiochip_get_data(chip);
return irq_find_mapping(atmel_pioctrl->irq_domain, offset);
}
static unsigned int atmel_pin_config_read(struct pinctrl_dev *pctldev,
unsigned pin_id)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
unsigned bank = atmel_pioctrl->pins[pin_id]->bank;
unsigned line = atmel_pioctrl->pins[pin_id]->line;
void __iomem *addr = atmel_pioctrl->reg_base
+ bank * ATMEL_PIO_BANK_OFFSET;
writel_relaxed(BIT(line), addr + ATMEL_PIO_MSKR);
wmb();
return readl_relaxed(addr + ATMEL_PIO_CFGR);
}
static void atmel_pin_config_write(struct pinctrl_dev *pctldev,
unsigned pin_id, u32 conf)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
unsigned bank = atmel_pioctrl->pins[pin_id]->bank;
unsigned line = atmel_pioctrl->pins[pin_id]->line;
void __iomem *addr = atmel_pioctrl->reg_base
+ bank * ATMEL_PIO_BANK_OFFSET;
writel_relaxed(BIT(line), addr + ATMEL_PIO_MSKR);
wmb();
writel_relaxed(conf, addr + ATMEL_PIO_CFGR);
}
static int atmel_pctl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
return atmel_pioctrl->npins;
}
static const char *atmel_pctl_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
return atmel_pioctrl->groups[selector].name;
}
static int atmel_pctl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned selector, const unsigned **pins,
unsigned *num_pins)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
*pins = (unsigned *)&atmel_pioctrl->groups[selector].pin;
*num_pins = 1;
return 0;
}
struct atmel_group *atmel_pctl_find_group_by_pin(struct pinctrl_dev *pctldev,
unsigned pin)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
int i;
for (i = 0; i < atmel_pioctrl->npins; i++) {
struct atmel_group *grp = atmel_pioctrl->groups + i;
if (grp->pin == pin)
return grp;
}
return NULL;
}
static int atmel_pctl_xlate_pinfunc(struct pinctrl_dev *pctldev,
struct device_node *np,
u32 pinfunc, const char **grp_name,
const char **func_name)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
unsigned pin_id, func_id;
struct atmel_group *grp;
pin_id = ATMEL_GET_PIN_NO(pinfunc);
func_id = ATMEL_GET_PIN_FUNC(pinfunc);
if (func_id >= ARRAY_SIZE(atmel_functions))
return -EINVAL;
*func_name = atmel_functions[func_id];
grp = atmel_pctl_find_group_by_pin(pctldev, pin_id);
if (!grp)
return -EINVAL;
*grp_name = grp->name;
atmel_pioctrl->pins[pin_id]->mux = func_id;
atmel_pioctrl->pins[pin_id]->ioset = ATMEL_GET_PIN_IOSET(pinfunc);
if (np->parent == atmel_pioctrl->node)
atmel_pioctrl->pins[pin_id]->device = np->name;
else
atmel_pioctrl->pins[pin_id]->device = np->parent->name;
return 0;
}
static int atmel_pctl_dt_subnode_to_map(struct pinctrl_dev *pctldev,
struct device_node *np,
struct pinctrl_map **map,
unsigned *reserved_maps,
unsigned *num_maps)
{
unsigned num_pins, num_configs, reserve;
unsigned long *configs;
struct property *pins;
bool has_config;
u32 pinfunc;
int ret, i;
pins = of_find_property(np, "pinmux", NULL);
if (!pins)
return -EINVAL;
ret = pinconf_generic_parse_dt_config(np, pctldev, &configs,
&num_configs);
if (ret < 0) {
dev_err(pctldev->dev, "%s: could not parse node property\n",
of_node_full_name(np));
return ret;
}
if (num_configs)
has_config = true;
num_pins = pins->length / sizeof(u32);
if (!num_pins) {
dev_err(pctldev->dev, "no pins found in node %s\n",
of_node_full_name(np));
ret = -EINVAL;
goto exit;
}
reserve = 1;
if (has_config && num_pins >= 1)
reserve++;
reserve *= num_pins;
ret = pinctrl_utils_reserve_map(pctldev, map, reserved_maps, num_maps,
reserve);
if (ret < 0)
goto exit;
for (i = 0; i < num_pins; i++) {
const char *group, *func;
ret = of_property_read_u32_index(np, "pinmux", i, &pinfunc);
if (ret)
goto exit;
ret = atmel_pctl_xlate_pinfunc(pctldev, np, pinfunc, &group,
&func);
if (ret)
goto exit;
pinctrl_utils_add_map_mux(pctldev, map, reserved_maps, num_maps,
group, func);
if (has_config) {
ret = pinctrl_utils_add_map_configs(pctldev, map,
reserved_maps, num_maps, group,
configs, num_configs,
PIN_MAP_TYPE_CONFIGS_GROUP);
if (ret < 0)
goto exit;
}
}
exit:
kfree(configs);
return ret;
}
static int atmel_pctl_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np_config,
struct pinctrl_map **map,
unsigned *num_maps)
{
struct device_node *np;
unsigned reserved_maps;
int ret;
*map = NULL;
*num_maps = 0;
reserved_maps = 0;
ret = atmel_pctl_dt_subnode_to_map(pctldev, np_config, map,
&reserved_maps, num_maps);
if (ret) {
for_each_child_of_node(np_config, np) {
ret = atmel_pctl_dt_subnode_to_map(pctldev, np, map,
&reserved_maps, num_maps);
if (ret < 0)
break;
}
}
if (ret < 0) {
pinctrl_utils_free_map(pctldev, *map, *num_maps);
dev_err(pctldev->dev, "can't create maps for node %s\n",
np_config->full_name);
}
return ret;
}
static int atmel_pmx_get_functions_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(atmel_functions);
}
static const char *atmel_pmx_get_function_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
return atmel_functions[selector];
}
static int atmel_pmx_get_function_groups(struct pinctrl_dev *pctldev,
unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
*groups = atmel_pioctrl->group_names;
*num_groups = atmel_pioctrl->npins;
return 0;
}
static int atmel_pmx_set_mux(struct pinctrl_dev *pctldev,
unsigned function,
unsigned group)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
unsigned pin;
u32 conf;
dev_dbg(pctldev->dev, "enable function %s group %s\n",
atmel_functions[function], atmel_pioctrl->groups[group].name);
pin = atmel_pioctrl->groups[group].pin;
conf = atmel_pin_config_read(pctldev, pin);
conf &= (~ATMEL_PIO_CFGR_FUNC_MASK);
conf |= (function & ATMEL_PIO_CFGR_FUNC_MASK);
dev_dbg(pctldev->dev, "pin: %u, conf: 0x%08x\n", pin, conf);
atmel_pin_config_write(pctldev, pin, conf);
return 0;
}
static int atmel_conf_pin_config_group_get(struct pinctrl_dev *pctldev,
unsigned group,
unsigned long *config)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
unsigned param = pinconf_to_config_param(*config), arg = 0;
struct atmel_group *grp = atmel_pioctrl->groups + group;
unsigned pin_id = grp->pin;
u32 res;
res = atmel_pin_config_read(pctldev, pin_id);
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
if (!(res & ATMEL_PIO_PUEN_MASK))
return -EINVAL;
arg = 1;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if ((res & ATMEL_PIO_PUEN_MASK) ||
(!(res & ATMEL_PIO_PDEN_MASK)))
return -EINVAL;
arg = 1;
break;
case PIN_CONFIG_BIAS_DISABLE:
if ((res & ATMEL_PIO_PUEN_MASK) ||
((res & ATMEL_PIO_PDEN_MASK)))
return -EINVAL;
arg = 1;
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
if (!(res & ATMEL_PIO_OPD_MASK))
return -EINVAL;
arg = 1;
break;
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
if (!(res & ATMEL_PIO_SCHMITT_MASK))
return -EINVAL;
arg = 1;
break;
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int atmel_conf_pin_config_group_set(struct pinctrl_dev *pctldev,
unsigned group,
unsigned long *configs,
unsigned num_configs)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
struct atmel_group *grp = atmel_pioctrl->groups + group;
unsigned bank, pin, pin_id = grp->pin;
u32 mask, conf = 0;
int i;
conf = atmel_pin_config_read(pctldev, pin_id);
for (i = 0; i < num_configs; i++) {
unsigned param = pinconf_to_config_param(configs[i]);
unsigned arg = pinconf_to_config_argument(configs[i]);
dev_dbg(pctldev->dev, "%s: pin=%u, config=0x%lx\n",
__func__, pin_id, configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
conf &= (~ATMEL_PIO_PUEN_MASK);
conf &= (~ATMEL_PIO_PDEN_MASK);
break;
case PIN_CONFIG_BIAS_PULL_UP:
conf |= ATMEL_PIO_PUEN_MASK;
conf &= (~ATMEL_PIO_PDEN_MASK);
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
conf |= ATMEL_PIO_PDEN_MASK;
conf &= (~ATMEL_PIO_PUEN_MASK);
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
if (arg == 0)
conf &= (~ATMEL_PIO_OPD_MASK);
else
conf |= ATMEL_PIO_OPD_MASK;
break;
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
if (arg == 0)
conf |= ATMEL_PIO_SCHMITT_MASK;
else
conf &= (~ATMEL_PIO_SCHMITT_MASK);
break;
case PIN_CONFIG_INPUT_DEBOUNCE:
if (arg == 0) {
conf &= (~ATMEL_PIO_IFEN_MASK);
conf &= (~ATMEL_PIO_IFSCEN_MASK);
} else {
conf |= ATMEL_PIO_IFEN_MASK;
conf |= ATMEL_PIO_IFSCEN_MASK;
}
break;
case PIN_CONFIG_OUTPUT:
conf |= ATMEL_PIO_DIR_MASK;
bank = ATMEL_PIO_BANK(pin_id);
pin = ATMEL_PIO_LINE(pin_id);
mask = 1 << pin;
if (arg == 0) {
writel_relaxed(mask, atmel_pioctrl->reg_base +
bank * ATMEL_PIO_BANK_OFFSET +
ATMEL_PIO_CODR);
} else {
writel_relaxed(mask, atmel_pioctrl->reg_base +
bank * ATMEL_PIO_BANK_OFFSET +
ATMEL_PIO_SODR);
}
break;
default:
dev_warn(pctldev->dev,
"unsupported configuration parameter: %u\n",
param);
continue;
}
}
dev_dbg(pctldev->dev, "%s: reg=0x%08x\n", __func__, conf);
atmel_pin_config_write(pctldev, pin_id, conf);
return 0;
}
static void atmel_conf_pin_config_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned pin_id)
{
struct atmel_pioctrl *atmel_pioctrl = pinctrl_dev_get_drvdata(pctldev);
u32 conf;
if (!atmel_pioctrl->pins[pin_id]->device)
return;
if (atmel_pioctrl->pins[pin_id])
seq_printf(s, " (%s, ioset %u) ",
atmel_pioctrl->pins[pin_id]->device,
atmel_pioctrl->pins[pin_id]->ioset);
conf = atmel_pin_config_read(pctldev, pin_id);
if (conf & ATMEL_PIO_PUEN_MASK)
seq_printf(s, "%s ", "pull-up");
if (conf & ATMEL_PIO_PDEN_MASK)
seq_printf(s, "%s ", "pull-down");
if (conf & ATMEL_PIO_IFEN_MASK)
seq_printf(s, "%s ", "debounce");
if (conf & ATMEL_PIO_OPD_MASK)
seq_printf(s, "%s ", "open-drain");
if (conf & ATMEL_PIO_SCHMITT_MASK)
seq_printf(s, "%s ", "schmitt");
}
static int __maybe_unused atmel_pctrl_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct atmel_pioctrl *atmel_pioctrl = platform_get_drvdata(pdev);
int i;
for (i = 0; i < atmel_pioctrl->nbanks; i++) {
atmel_pioctrl->pm_suspend_backup[i] =
atmel_gpio_read(atmel_pioctrl, i, ATMEL_PIO_IMR);
atmel_gpio_write(atmel_pioctrl, i, ATMEL_PIO_IDR,
~atmel_pioctrl->pm_wakeup_sources[i]);
}
return 0;
}
static int __maybe_unused atmel_pctrl_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct atmel_pioctrl *atmel_pioctrl = platform_get_drvdata(pdev);
int i;
for (i = 0; i < atmel_pioctrl->nbanks; i++)
atmel_gpio_write(atmel_pioctrl, i, ATMEL_PIO_IER,
atmel_pioctrl->pm_suspend_backup[i]);
return 0;
}
static int atmel_pinctrl_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct pinctrl_pin_desc *pin_desc;
const char **group_names;
const struct of_device_id *match;
int i, ret;
struct resource *res;
struct atmel_pioctrl *atmel_pioctrl;
struct atmel_pioctrl_data *atmel_pioctrl_data;
atmel_pioctrl = devm_kzalloc(dev, sizeof(*atmel_pioctrl), GFP_KERNEL);
if (!atmel_pioctrl)
return -ENOMEM;
atmel_pioctrl->dev = dev;
atmel_pioctrl->node = dev->of_node;
platform_set_drvdata(pdev, atmel_pioctrl);
match = of_match_node(atmel_pctrl_of_match, dev->of_node);
if (!match) {
dev_err(dev, "unknown compatible string\n");
return -ENODEV;
}
atmel_pioctrl_data = (struct atmel_pioctrl_data *)match->data;
atmel_pioctrl->nbanks = atmel_pioctrl_data->nbanks;
atmel_pioctrl->npins = atmel_pioctrl->nbanks * ATMEL_PIO_NPINS_PER_BANK;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(dev, "unable to get atmel pinctrl resource\n");
return -EINVAL;
}
atmel_pioctrl->reg_base = devm_ioremap_resource(dev, res);
if (IS_ERR(atmel_pioctrl->reg_base))
return -EINVAL;
atmel_pioctrl->clk = devm_clk_get(dev, NULL);
if (IS_ERR(atmel_pioctrl->clk)) {
dev_err(dev, "failed to get clock\n");
return PTR_ERR(atmel_pioctrl->clk);
}
atmel_pioctrl->pins = devm_kzalloc(dev, sizeof(*atmel_pioctrl->pins)
* atmel_pioctrl->npins, GFP_KERNEL);
if (!atmel_pioctrl->pins)
return -ENOMEM;
pin_desc = devm_kzalloc(dev, sizeof(*pin_desc)
* atmel_pioctrl->npins, GFP_KERNEL);
if (!pin_desc)
return -ENOMEM;
atmel_pinctrl_desc.pins = pin_desc;
atmel_pinctrl_desc.npins = atmel_pioctrl->npins;
group_names = devm_kzalloc(dev, sizeof(*group_names)
* atmel_pioctrl->npins, GFP_KERNEL);
if (!group_names)
return -ENOMEM;
atmel_pioctrl->group_names = group_names;
atmel_pioctrl->groups = devm_kzalloc(&pdev->dev,
sizeof(*atmel_pioctrl->groups) * atmel_pioctrl->npins,
GFP_KERNEL);
if (!atmel_pioctrl->groups)
return -ENOMEM;
for (i = 0 ; i < atmel_pioctrl->npins; i++) {
struct atmel_group *group = atmel_pioctrl->groups + i;
unsigned bank = ATMEL_PIO_BANK(i);
unsigned line = ATMEL_PIO_LINE(i);
atmel_pioctrl->pins[i] = devm_kzalloc(dev,
sizeof(**atmel_pioctrl->pins), GFP_KERNEL);
if (!atmel_pioctrl->pins[i])
return -ENOMEM;
atmel_pioctrl->pins[i]->pin_id = i;
atmel_pioctrl->pins[i]->bank = bank;
atmel_pioctrl->pins[i]->line = line;
pin_desc[i].number = i;
pin_desc[i].name = kasprintf(GFP_KERNEL, "P%c%d",
bank + 'A', line);
group->name = group_names[i] = pin_desc[i].name;
group->pin = pin_desc[i].number;
dev_dbg(dev, "pin_id=%u, bank=%u, line=%u", i, bank, line);
}
atmel_pioctrl->gpio_chip = &atmel_gpio_chip;
atmel_pioctrl->gpio_chip->of_node = dev->of_node;
atmel_pioctrl->gpio_chip->ngpio = atmel_pioctrl->npins;
atmel_pioctrl->gpio_chip->label = dev_name(dev);
atmel_pioctrl->gpio_chip->parent = dev;
atmel_pioctrl->gpio_chip->names = atmel_pioctrl->group_names;
atmel_pioctrl->pm_wakeup_sources = devm_kzalloc(dev,
sizeof(*atmel_pioctrl->pm_wakeup_sources)
* atmel_pioctrl->nbanks, GFP_KERNEL);
if (!atmel_pioctrl->pm_wakeup_sources)
return -ENOMEM;
atmel_pioctrl->pm_suspend_backup = devm_kzalloc(dev,
sizeof(*atmel_pioctrl->pm_suspend_backup)
* atmel_pioctrl->nbanks, GFP_KERNEL);
if (!atmel_pioctrl->pm_suspend_backup)
return -ENOMEM;
atmel_pioctrl->irqs = devm_kzalloc(dev, sizeof(*atmel_pioctrl->irqs)
* atmel_pioctrl->nbanks, GFP_KERNEL);
if (!atmel_pioctrl->irqs)
return -ENOMEM;
for (i = 0; i < atmel_pioctrl->nbanks; i++) {
res = platform_get_resource(pdev, IORESOURCE_IRQ, i);
if (!res) {
dev_err(dev, "missing irq resource for group %c\n",
'A' + i);
return -EINVAL;
}
atmel_pioctrl->irqs[i] = res->start;
irq_set_chained_handler(res->start, atmel_gpio_irq_handler);
irq_set_handler_data(res->start, atmel_pioctrl);
dev_dbg(dev, "bank %i: irq=%pr\n", i, res);
}
atmel_pioctrl->irq_domain = irq_domain_add_linear(dev->of_node,
atmel_pioctrl->gpio_chip->ngpio,
&irq_domain_simple_ops, NULL);
if (!atmel_pioctrl->irq_domain) {
dev_err(dev, "can't add the irq domain\n");
return -ENODEV;
}
atmel_pioctrl->irq_domain->name = "atmel gpio";
for (i = 0; i < atmel_pioctrl->npins; i++) {
int irq = irq_create_mapping(atmel_pioctrl->irq_domain, i);
irq_set_chip_and_handler(irq, &atmel_gpio_irq_chip,
handle_simple_irq);
irq_set_chip_data(irq, atmel_pioctrl);
dev_dbg(dev,
"atmel gpio irq domain: hwirq: %d, linux irq: %d\n",
i, irq);
}
ret = clk_prepare_enable(atmel_pioctrl->clk);
if (ret) {
dev_err(dev, "failed to prepare and enable clock\n");
goto clk_prepare_enable_error;
}
atmel_pioctrl->pinctrl_dev = devm_pinctrl_register(&pdev->dev,
&atmel_pinctrl_desc,
atmel_pioctrl);
if (IS_ERR(atmel_pioctrl->pinctrl_dev)) {
ret = PTR_ERR(atmel_pioctrl->pinctrl_dev);
dev_err(dev, "pinctrl registration failed\n");
goto clk_unprep;
}
ret = gpiochip_add_data(atmel_pioctrl->gpio_chip, atmel_pioctrl);
if (ret) {
dev_err(dev, "failed to add gpiochip\n");
goto clk_unprep;
}
ret = gpiochip_add_pin_range(atmel_pioctrl->gpio_chip, dev_name(dev),
0, 0, atmel_pioctrl->gpio_chip->ngpio);
if (ret) {
dev_err(dev, "failed to add gpio pin range\n");
goto gpiochip_add_pin_range_error;
}
dev_info(&pdev->dev, "atmel pinctrl initialized\n");
return 0;
gpiochip_add_pin_range_error:
gpiochip_remove(atmel_pioctrl->gpio_chip);
clk_unprep:
clk_disable_unprepare(atmel_pioctrl->clk);
clk_prepare_enable_error:
irq_domain_remove(atmel_pioctrl->irq_domain);
return ret;
}
int atmel_pinctrl_remove(struct platform_device *pdev)
{
struct atmel_pioctrl *atmel_pioctrl = platform_get_drvdata(pdev);
irq_domain_remove(atmel_pioctrl->irq_domain);
clk_disable_unprepare(atmel_pioctrl->clk);
gpiochip_remove(atmel_pioctrl->gpio_chip);
return 0;
}
