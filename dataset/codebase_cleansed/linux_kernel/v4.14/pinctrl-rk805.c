static int rk805_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct rk805_pctrl_info *pci = gpiochip_get_data(chip);
int ret, val;
ret = regmap_read(pci->rk808->regmap, pci->pin_cfg[offset].reg, &val);
if (ret) {
dev_err(pci->dev, "get gpio%d value failed\n", offset);
return ret;
}
return !!(val & pci->pin_cfg[offset].val_msk);
}
static void rk805_gpio_set(struct gpio_chip *chip,
unsigned int offset,
int value)
{
struct rk805_pctrl_info *pci = gpiochip_get_data(chip);
int ret;
ret = regmap_update_bits(pci->rk808->regmap,
pci->pin_cfg[offset].reg,
pci->pin_cfg[offset].val_msk,
value ? pci->pin_cfg[offset].val_msk : 0);
if (ret)
dev_err(pci->dev, "set gpio%d value %d failed\n",
offset, value);
}
static int rk805_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
return pinctrl_gpio_direction_input(chip->base + offset);
}
static int rk805_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
rk805_gpio_set(chip, offset, value);
return pinctrl_gpio_direction_output(chip->base + offset);
}
static int rk805_gpio_get_direction(struct gpio_chip *chip, unsigned int offset)
{
struct rk805_pctrl_info *pci = gpiochip_get_data(chip);
unsigned int val;
int ret;
if (!pci->pin_cfg[offset].dir_msk)
return 0;
ret = regmap_read(pci->rk808->regmap,
pci->pin_cfg[offset].reg,
&val);
if (ret) {
dev_err(pci->dev, "get gpio%d direction failed\n", offset);
return ret;
}
return !(val & pci->pin_cfg[offset].dir_msk);
}
static int rk805_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
return pci->num_pin_groups;
}
static const char *rk805_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
return pci->groups[group].name;
}
static int rk805_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int group,
const unsigned int **pins,
unsigned int *num_pins)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
*pins = pci->groups[group].pins;
*num_pins = pci->groups[group].npins;
return 0;
}
static int rk805_pinctrl_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
return pci->num_functions;
}
static const char *rk805_pinctrl_get_func_name(struct pinctrl_dev *pctldev,
unsigned int function)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
return pci->functions[function].name;
}
static int rk805_pinctrl_get_func_groups(struct pinctrl_dev *pctldev,
unsigned int function,
const char *const **groups,
unsigned int *const num_groups)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
*groups = pci->functions[function].groups;
*num_groups = pci->functions[function].ngroups;
return 0;
}
static int _rk805_pinctrl_set_mux(struct pinctrl_dev *pctldev,
unsigned int offset,
int mux)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
int ret;
if (!pci->pin_cfg[offset].fun_msk)
return 0;
if (mux == RK805_PINMUX_GPIO) {
ret = regmap_update_bits(pci->rk808->regmap,
pci->pin_cfg[offset].reg,
pci->pin_cfg[offset].fun_msk,
pci->pin_cfg[offset].fun_msk);
if (ret) {
dev_err(pci->dev, "set gpio%d GPIO failed\n", offset);
return ret;
}
} else {
dev_err(pci->dev, "Couldn't find function mux %d\n", mux);
return -EINVAL;
}
return 0;
}
static int rk805_pinctrl_set_mux(struct pinctrl_dev *pctldev,
unsigned int function,
unsigned int group)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
int mux = pci->functions[function].mux_option;
int offset = group;
return _rk805_pinctrl_set_mux(pctldev, offset, mux);
}
static int rk805_pmx_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int offset, bool input)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
int ret;
ret = _rk805_pinctrl_set_mux(pctldev, offset, RK805_PINMUX_GPIO);
if (ret) {
dev_err(pci->dev, "set gpio%d mux failed\n", offset);
return ret;
}
if (!pci->pin_cfg[offset].dir_msk)
return 0;
ret = regmap_update_bits(pci->rk808->regmap,
pci->pin_cfg[offset].reg,
pci->pin_cfg[offset].dir_msk,
input ? 0 : pci->pin_cfg[offset].dir_msk);
if (ret) {
dev_err(pci->dev, "set gpio%d direction failed\n", offset);
return ret;
}
return ret;
}
static int rk805_pinconf_get(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *config)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
u32 arg = 0;
switch (param) {
case PIN_CONFIG_OUTPUT:
arg = rk805_gpio_get(&pci->gpio_chip, pin);
break;
default:
dev_err(pci->dev, "Properties not supported\n");
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, (u16)arg);
return 0;
}
static int rk805_pinconf_set(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *configs,
unsigned int num_configs)
{
struct rk805_pctrl_info *pci = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
u32 i, arg = 0;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_OUTPUT:
rk805_gpio_set(&pci->gpio_chip, pin, arg);
rk805_pmx_gpio_set_direction(pctldev, NULL, pin, false);
break;
default:
dev_err(pci->dev, "Properties not supported\n");
return -ENOTSUPP;
}
}
return 0;
}
static int rk805_pinctrl_probe(struct platform_device *pdev)
{
struct rk805_pctrl_info *pci;
int ret;
pci = devm_kzalloc(&pdev->dev, sizeof(*pci), GFP_KERNEL);
if (!pci)
return -ENOMEM;
pci->dev = &pdev->dev;
pci->dev->of_node = pdev->dev.parent->of_node;
pci->rk808 = dev_get_drvdata(pdev->dev.parent);
pci->pinctrl_desc = rk805_pinctrl_desc;
pci->gpio_chip = rk805_gpio_chip;
pci->gpio_chip.parent = &pdev->dev;
pci->gpio_chip.of_node = pdev->dev.parent->of_node;
platform_set_drvdata(pdev, pci);
switch (pci->rk808->variant) {
case RK805_ID:
pci->pins = rk805_pins_desc;
pci->num_pins = ARRAY_SIZE(rk805_pins_desc);
pci->functions = rk805_pin_functions;
pci->num_functions = ARRAY_SIZE(rk805_pin_functions);
pci->groups = rk805_pin_groups;
pci->num_pin_groups = ARRAY_SIZE(rk805_pin_groups);
pci->pinctrl_desc.pins = rk805_pins_desc;
pci->pinctrl_desc.npins = ARRAY_SIZE(rk805_pins_desc);
pci->pin_cfg = rk805_gpio_cfgs;
pci->gpio_chip.ngpio = ARRAY_SIZE(rk805_gpio_cfgs);
break;
default:
dev_err(&pdev->dev, "unsupported RK805 ID %lu\n",
pci->rk808->variant);
return -EINVAL;
}
ret = devm_gpiochip_add_data(&pdev->dev, &pci->gpio_chip, pci);
if (ret < 0) {
dev_err(&pdev->dev, "Couldn't add gpiochip\n");
return ret;
}
pci->pctl = devm_pinctrl_register(&pdev->dev, &pci->pinctrl_desc, pci);
if (IS_ERR(pci->pctl)) {
dev_err(&pdev->dev, "Couldn't add pinctrl\n");
return PTR_ERR(pci->pctl);
}
ret = gpiochip_add_pin_range(&pci->gpio_chip, dev_name(&pdev->dev),
0, 0, pci->gpio_chip.ngpio);
if (ret < 0) {
dev_err(&pdev->dev, "Couldn't add gpiochip pin range\n");
return ret;
}
return 0;
}
