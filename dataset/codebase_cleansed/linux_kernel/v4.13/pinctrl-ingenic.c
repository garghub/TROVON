static inline void ingenic_config_pin(struct ingenic_pinctrl *jzpc,
unsigned int pin, u8 reg, bool set)
{
unsigned int idx = pin % PINS_PER_GPIO_CHIP;
unsigned int offt = pin / PINS_PER_GPIO_CHIP;
regmap_write(jzpc->map, offt * 0x100 +
(set ? REG_SET(reg) : REG_CLEAR(reg)), BIT(idx));
}
static inline bool ingenic_get_pin_config(struct ingenic_pinctrl *jzpc,
unsigned int pin, u8 reg)
{
unsigned int idx = pin % PINS_PER_GPIO_CHIP;
unsigned int offt = pin / PINS_PER_GPIO_CHIP;
unsigned int val;
regmap_read(jzpc->map, offt * 0x100 + reg, &val);
return val & BIT(idx);
}
static int ingenic_pinmux_set_pin_fn(struct ingenic_pinctrl *jzpc,
int pin, int func)
{
unsigned int idx = pin % PINS_PER_GPIO_CHIP;
unsigned int offt = pin / PINS_PER_GPIO_CHIP;
dev_dbg(jzpc->dev, "set pin P%c%u to function %u\n",
'A' + offt, idx, func);
if (jzpc->version >= ID_JZ4770) {
ingenic_config_pin(jzpc, pin, JZ4770_GPIO_INT, false);
ingenic_config_pin(jzpc, pin, JZ4770_GPIO_MSK, false);
ingenic_config_pin(jzpc, pin, JZ4770_GPIO_PAT1, func & 0x2);
ingenic_config_pin(jzpc, pin, JZ4770_GPIO_PAT0, func & 0x1);
} else {
ingenic_config_pin(jzpc, pin, JZ4740_GPIO_FUNC, true);
ingenic_config_pin(jzpc, pin, JZ4740_GPIO_TRIG, func & 0x2);
ingenic_config_pin(jzpc, pin, JZ4740_GPIO_SELECT, func > 0);
}
return 0;
}
static int ingenic_pinmux_set_mux(struct pinctrl_dev *pctldev,
unsigned int selector, unsigned int group)
{
struct ingenic_pinctrl *jzpc = pinctrl_dev_get_drvdata(pctldev);
struct function_desc *func;
struct group_desc *grp;
unsigned int i;
func = pinmux_generic_get_function(pctldev, selector);
if (!func)
return -EINVAL;
grp = pinctrl_generic_get_group(pctldev, group);
if (!grp)
return -EINVAL;
dev_dbg(pctldev->dev, "enable function %s group %s\n",
func->name, grp->name);
for (i = 0; i < grp->num_pins; i++) {
int *pin_modes = grp->data;
ingenic_pinmux_set_pin_fn(jzpc, grp->pins[i], pin_modes[i]);
}
return 0;
}
static int ingenic_pinmux_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int pin, bool input)
{
struct ingenic_pinctrl *jzpc = pinctrl_dev_get_drvdata(pctldev);
unsigned int idx = pin % PINS_PER_GPIO_CHIP;
unsigned int offt = pin / PINS_PER_GPIO_CHIP;
dev_dbg(pctldev->dev, "set pin P%c%u to %sput\n",
'A' + offt, idx, input ? "in" : "out");
if (jzpc->version >= ID_JZ4770) {
ingenic_config_pin(jzpc, pin, JZ4770_GPIO_INT, false);
ingenic_config_pin(jzpc, pin, JZ4770_GPIO_MSK, true);
ingenic_config_pin(jzpc, pin, JZ4770_GPIO_PAT1, input);
} else {
ingenic_config_pin(jzpc, pin, JZ4740_GPIO_SELECT, false);
ingenic_config_pin(jzpc, pin, JZ4740_GPIO_DIR, input);
ingenic_config_pin(jzpc, pin, JZ4740_GPIO_FUNC, false);
}
return 0;
}
static int ingenic_pinconf_get(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *config)
{
struct ingenic_pinctrl *jzpc = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
unsigned int idx = pin % PINS_PER_GPIO_CHIP;
unsigned int offt = pin / PINS_PER_GPIO_CHIP;
bool pull;
if (jzpc->version >= ID_JZ4770)
pull = !ingenic_get_pin_config(jzpc, pin, JZ4770_GPIO_PEN);
else
pull = !ingenic_get_pin_config(jzpc, pin, JZ4740_GPIO_PULL_DIS);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if (pull)
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_UP:
if (!pull || !(jzpc->info->pull_ups[offt] & BIT(idx)))
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (!pull || !(jzpc->info->pull_downs[offt] & BIT(idx)))
return -EINVAL;
break;
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, 1);
return 0;
}
static void ingenic_set_bias(struct ingenic_pinctrl *jzpc,
unsigned int pin, bool enabled)
{
if (jzpc->version >= ID_JZ4770)
ingenic_config_pin(jzpc, pin, JZ4770_GPIO_PEN, !enabled);
else
ingenic_config_pin(jzpc, pin, JZ4740_GPIO_PULL_DIS, !enabled);
}
static int ingenic_pinconf_set(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *configs, unsigned int num_configs)
{
struct ingenic_pinctrl *jzpc = pinctrl_dev_get_drvdata(pctldev);
unsigned int idx = pin % PINS_PER_GPIO_CHIP;
unsigned int offt = pin / PINS_PER_GPIO_CHIP;
unsigned int cfg;
for (cfg = 0; cfg < num_configs; cfg++) {
switch (pinconf_to_config_param(configs[cfg])) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
continue;
default:
return -ENOTSUPP;
}
}
for (cfg = 0; cfg < num_configs; cfg++) {
switch (pinconf_to_config_param(configs[cfg])) {
case PIN_CONFIG_BIAS_DISABLE:
dev_dbg(jzpc->dev, "disable pull-over for pin P%c%u\n",
'A' + offt, idx);
ingenic_set_bias(jzpc, pin, false);
break;
case PIN_CONFIG_BIAS_PULL_UP:
if (!(jzpc->info->pull_ups[offt] & BIT(idx)))
return -EINVAL;
dev_dbg(jzpc->dev, "set pull-up for pin P%c%u\n",
'A' + offt, idx);
ingenic_set_bias(jzpc, pin, true);
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (!(jzpc->info->pull_downs[offt] & BIT(idx)))
return -EINVAL;
dev_dbg(jzpc->dev, "set pull-down for pin P%c%u\n",
'A' + offt, idx);
ingenic_set_bias(jzpc, pin, true);
break;
default:
unreachable();
}
}
return 0;
}
static int ingenic_pinconf_group_get(struct pinctrl_dev *pctldev,
unsigned int group, unsigned long *config)
{
const unsigned int *pins;
unsigned int i, npins, old = 0;
int ret;
ret = pinctrl_generic_get_group_pins(pctldev, group, &pins, &npins);
if (ret)
return ret;
for (i = 0; i < npins; i++) {
if (ingenic_pinconf_get(pctldev, pins[i], config))
return -ENOTSUPP;
if (i && (old != *config))
return -ENOTSUPP;
old = *config;
}
return 0;
}
static int ingenic_pinconf_group_set(struct pinctrl_dev *pctldev,
unsigned int group, unsigned long *configs,
unsigned int num_configs)
{
const unsigned int *pins;
unsigned int i, npins;
int ret;
ret = pinctrl_generic_get_group_pins(pctldev, group, &pins, &npins);
if (ret)
return ret;
for (i = 0; i < npins; i++) {
ret = ingenic_pinconf_set(pctldev,
pins[i], configs, num_configs);
if (ret)
return ret;
}
return 0;
}
int ingenic_pinctrl_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ingenic_pinctrl *jzpc;
struct pinctrl_desc *pctl_desc;
void __iomem *base;
const struct platform_device_id *id = platform_get_device_id(pdev);
const struct of_device_id *of_id = of_match_device(
ingenic_pinctrl_of_match, dev);
const struct ingenic_chip_info *chip_info;
unsigned int i;
int err;
jzpc = devm_kzalloc(dev, sizeof(*jzpc), GFP_KERNEL);
if (!jzpc)
return -ENOMEM;
base = devm_ioremap_resource(dev,
platform_get_resource(pdev, IORESOURCE_MEM, 0));
if (IS_ERR(base)) {
dev_err(dev, "Failed to ioremap registers\n");
return PTR_ERR(base);
}
jzpc->map = devm_regmap_init_mmio(dev, base,
&ingenic_pinctrl_regmap_config);
if (IS_ERR(jzpc->map)) {
dev_err(dev, "Failed to create regmap\n");
return PTR_ERR(jzpc->map);
}
jzpc->dev = dev;
if (of_id)
jzpc->version = (enum jz_version)of_id->data;
else
jzpc->version = (enum jz_version)id->driver_data;
if (jzpc->version >= ID_JZ4770)
chip_info = &jz4770_chip_info;
else
chip_info = &jz4740_chip_info;
jzpc->info = chip_info;
pctl_desc = devm_kzalloc(&pdev->dev, sizeof(*pctl_desc), GFP_KERNEL);
if (!pctl_desc)
return -ENOMEM;
pctl_desc->name = dev_name(dev);
pctl_desc->owner = THIS_MODULE;
pctl_desc->pctlops = &ingenic_pctlops;
pctl_desc->pmxops = &ingenic_pmxops;
pctl_desc->confops = &ingenic_confops;
pctl_desc->npins = chip_info->num_chips * PINS_PER_GPIO_CHIP;
pctl_desc->pins = jzpc->pdesc = devm_kzalloc(&pdev->dev,
sizeof(*jzpc->pdesc) * pctl_desc->npins, GFP_KERNEL);
if (!jzpc->pdesc)
return -ENOMEM;
for (i = 0; i < pctl_desc->npins; i++) {
jzpc->pdesc[i].number = i;
jzpc->pdesc[i].name = kasprintf(GFP_KERNEL, "P%c%d",
'A' + (i / PINS_PER_GPIO_CHIP),
i % PINS_PER_GPIO_CHIP);
}
jzpc->pctl = devm_pinctrl_register(dev, pctl_desc, jzpc);
if (IS_ERR(jzpc->pctl)) {
dev_err(dev, "Failed to register pinctrl\n");
return PTR_ERR(jzpc->pctl);
}
for (i = 0; i < chip_info->num_groups; i++) {
const struct group_desc *group = &chip_info->groups[i];
err = pinctrl_generic_add_group(jzpc->pctl, group->name,
group->pins, group->num_pins, group->data);
if (err) {
dev_err(dev, "Failed to register group %s\n",
group->name);
return err;
}
}
for (i = 0; i < chip_info->num_functions; i++) {
const struct function_desc *func = &chip_info->functions[i];
err = pinmux_generic_add_function(jzpc->pctl, func->name,
func->group_names, func->num_group_names,
func->data);
if (err) {
dev_err(dev, "Failed to register function %s\n",
func->name);
return err;
}
}
dev_set_drvdata(dev, jzpc->map);
if (dev->of_node) {
err = of_platform_populate(dev->of_node, NULL, NULL, dev);
if (err) {
dev_err(dev, "Failed to probe GPIO devices\n");
return err;
}
}
return 0;
}
static int __init ingenic_pinctrl_drv_register(void)
{
return platform_driver_register(&ingenic_pinctrl_driver);
}
