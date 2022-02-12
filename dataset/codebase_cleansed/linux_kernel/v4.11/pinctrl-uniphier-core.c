static int uniphier_pctl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
return priv->socdata->groups_count;
}
static const char *uniphier_pctl_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
return priv->socdata->groups[selector].name;
}
static int uniphier_pctl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned selector,
const unsigned **pins,
unsigned *num_pins)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
*pins = priv->socdata->groups[selector].pins;
*num_pins = priv->socdata->groups[selector].num_pins;
return 0;
}
static void uniphier_pctl_pin_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned offset)
{
const struct pin_desc *desc = pin_desc_get(pctldev, offset);
const char *pull_dir, *drv_type;
switch (uniphier_pin_get_pull_dir(desc->drv_data)) {
case UNIPHIER_PIN_PULL_UP:
pull_dir = "UP";
break;
case UNIPHIER_PIN_PULL_DOWN:
pull_dir = "DOWN";
break;
case UNIPHIER_PIN_PULL_UP_FIXED:
pull_dir = "UP(FIXED)";
break;
case UNIPHIER_PIN_PULL_DOWN_FIXED:
pull_dir = "DOWN(FIXED)";
break;
case UNIPHIER_PIN_PULL_NONE:
pull_dir = "NONE";
break;
default:
BUG();
}
switch (uniphier_pin_get_drv_type(desc->drv_data)) {
case UNIPHIER_PIN_DRV_1BIT:
drv_type = "4/8(mA)";
break;
case UNIPHIER_PIN_DRV_2BIT:
drv_type = "8/12/16/20(mA)";
break;
case UNIPHIER_PIN_DRV_3BIT:
drv_type = "4/5/7/9/11/12/14/16(mA)";
break;
case UNIPHIER_PIN_DRV_FIXED4:
drv_type = "4(mA)";
break;
case UNIPHIER_PIN_DRV_FIXED5:
drv_type = "5(mA)";
break;
case UNIPHIER_PIN_DRV_FIXED8:
drv_type = "8(mA)";
break;
case UNIPHIER_PIN_DRV_NONE:
drv_type = "NONE";
break;
default:
BUG();
}
seq_printf(s, " PULL_DIR=%s DRV_TYPE=%s", pull_dir, drv_type);
}
static int uniphier_conf_pin_bias_get(struct pinctrl_dev *pctldev,
const struct pin_desc *desc,
enum pin_config_param param)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
enum uniphier_pin_pull_dir pull_dir =
uniphier_pin_get_pull_dir(desc->drv_data);
unsigned int pupdctrl, reg, shift, val;
unsigned int expected = 1;
int ret;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if (pull_dir == UNIPHIER_PIN_PULL_NONE)
return 0;
if (pull_dir == UNIPHIER_PIN_PULL_UP_FIXED ||
pull_dir == UNIPHIER_PIN_PULL_DOWN_FIXED)
return -EINVAL;
expected = 0;
break;
case PIN_CONFIG_BIAS_PULL_UP:
if (pull_dir == UNIPHIER_PIN_PULL_UP_FIXED)
return 0;
if (pull_dir != UNIPHIER_PIN_PULL_UP)
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (pull_dir == UNIPHIER_PIN_PULL_DOWN_FIXED)
return 0;
if (pull_dir != UNIPHIER_PIN_PULL_DOWN)
return -EINVAL;
break;
default:
BUG();
}
pupdctrl = uniphier_pin_get_pupdctrl(desc->drv_data);
reg = UNIPHIER_PINCTRL_PUPDCTRL_BASE + pupdctrl / 32 * 4;
shift = pupdctrl % 32;
ret = regmap_read(priv->regmap, priv->regbase + reg, &val);
if (ret)
return ret;
val = (val >> shift) & 1;
return (val == expected) ? 0 : -EINVAL;
}
static int uniphier_conf_pin_drive_get(struct pinctrl_dev *pctldev,
const struct pin_desc *desc,
u16 *strength)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
enum uniphier_pin_drv_type type =
uniphier_pin_get_drv_type(desc->drv_data);
const unsigned int strength_1bit[] = {4, 8};
const unsigned int strength_2bit[] = {8, 12, 16, 20};
const unsigned int strength_3bit[] = {4, 5, 7, 9, 11, 12, 14, 16};
const unsigned int *supported_strength;
unsigned int drvctrl, reg, shift, mask, width, val;
int ret;
switch (type) {
case UNIPHIER_PIN_DRV_1BIT:
supported_strength = strength_1bit;
reg = UNIPHIER_PINCTRL_DRVCTRL_BASE;
width = 1;
break;
case UNIPHIER_PIN_DRV_2BIT:
supported_strength = strength_2bit;
reg = UNIPHIER_PINCTRL_DRV2CTRL_BASE;
width = 2;
break;
case UNIPHIER_PIN_DRV_3BIT:
supported_strength = strength_3bit;
reg = UNIPHIER_PINCTRL_DRV3CTRL_BASE;
width = 4;
break;
case UNIPHIER_PIN_DRV_FIXED4:
*strength = 4;
return 0;
case UNIPHIER_PIN_DRV_FIXED5:
*strength = 5;
return 0;
case UNIPHIER_PIN_DRV_FIXED8:
*strength = 8;
return 0;
default:
return -EINVAL;
}
drvctrl = uniphier_pin_get_drvctrl(desc->drv_data);
drvctrl *= width;
reg += drvctrl / 32 * 4;
shift = drvctrl % 32;
mask = (1U << width) - 1;
ret = regmap_read(priv->regmap, priv->regbase + reg, &val);
if (ret)
return ret;
*strength = supported_strength[(val >> shift) & mask];
return 0;
}
static int uniphier_conf_pin_input_enable_get(struct pinctrl_dev *pctldev,
const struct pin_desc *desc)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
unsigned int iectrl = uniphier_pin_get_iectrl(desc->drv_data);
unsigned int val;
int ret;
if (iectrl == UNIPHIER_PIN_IECTRL_NONE)
return 0;
ret = regmap_read(priv->regmap,
priv->regbase + UNIPHIER_PINCTRL_IECTRL, &val);
if (ret)
return ret;
return val & BIT(iectrl) ? 0 : -EINVAL;
}
static int uniphier_conf_pin_config_get(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *configs)
{
const struct pin_desc *desc = pin_desc_get(pctldev, pin);
enum pin_config_param param = pinconf_to_config_param(*configs);
bool has_arg = false;
u16 arg;
int ret;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
ret = uniphier_conf_pin_bias_get(pctldev, desc, param);
break;
case PIN_CONFIG_DRIVE_STRENGTH:
ret = uniphier_conf_pin_drive_get(pctldev, desc, &arg);
has_arg = true;
break;
case PIN_CONFIG_INPUT_ENABLE:
ret = uniphier_conf_pin_input_enable_get(pctldev, desc);
break;
default:
ret = -EINVAL;
break;
}
if (ret == 0 && has_arg)
*configs = pinconf_to_config_packed(param, arg);
return ret;
}
static int uniphier_conf_pin_bias_set(struct pinctrl_dev *pctldev,
const struct pin_desc *desc,
enum pin_config_param param, u32 arg)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
enum uniphier_pin_pull_dir pull_dir =
uniphier_pin_get_pull_dir(desc->drv_data);
unsigned int pupdctrl, reg, shift;
unsigned int val = 1;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if (pull_dir == UNIPHIER_PIN_PULL_NONE)
return 0;
if (pull_dir == UNIPHIER_PIN_PULL_UP_FIXED ||
pull_dir == UNIPHIER_PIN_PULL_DOWN_FIXED) {
dev_err(pctldev->dev,
"can not disable pull register for pin %s\n",
desc->name);
return -EINVAL;
}
val = 0;
break;
case PIN_CONFIG_BIAS_PULL_UP:
if (pull_dir == UNIPHIER_PIN_PULL_UP_FIXED && arg != 0)
return 0;
if (pull_dir != UNIPHIER_PIN_PULL_UP) {
dev_err(pctldev->dev,
"pull-up is unsupported for pin %s\n",
desc->name);
return -EINVAL;
}
if (arg == 0) {
dev_err(pctldev->dev, "pull-up can not be total\n");
return -EINVAL;
}
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (pull_dir == UNIPHIER_PIN_PULL_DOWN_FIXED && arg != 0)
return 0;
if (pull_dir != UNIPHIER_PIN_PULL_DOWN) {
dev_err(pctldev->dev,
"pull-down is unsupported for pin %s\n",
desc->name);
return -EINVAL;
}
if (arg == 0) {
dev_err(pctldev->dev, "pull-down can not be total\n");
return -EINVAL;
}
break;
case PIN_CONFIG_BIAS_PULL_PIN_DEFAULT:
if (pull_dir == UNIPHIER_PIN_PULL_NONE) {
dev_err(pctldev->dev,
"pull-up/down is unsupported for pin %s\n",
desc->name);
return -EINVAL;
}
if (arg == 0)
return 0;
break;
default:
BUG();
}
pupdctrl = uniphier_pin_get_pupdctrl(desc->drv_data);
reg = UNIPHIER_PINCTRL_PUPDCTRL_BASE + pupdctrl / 32 * 4;
shift = pupdctrl % 32;
return regmap_update_bits(priv->regmap, priv->regbase + reg,
1 << shift, val << shift);
}
static int uniphier_conf_pin_drive_set(struct pinctrl_dev *pctldev,
const struct pin_desc *desc,
u16 strength)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
enum uniphier_pin_drv_type type =
uniphier_pin_get_drv_type(desc->drv_data);
const unsigned int strength_1bit[] = {4, 8, -1};
const unsigned int strength_2bit[] = {8, 12, 16, 20, -1};
const unsigned int strength_3bit[] = {4, 5, 7, 9, 11, 12, 14, 16, -1};
const unsigned int *supported_strength;
unsigned int drvctrl, reg, shift, mask, width, val;
switch (type) {
case UNIPHIER_PIN_DRV_1BIT:
supported_strength = strength_1bit;
reg = UNIPHIER_PINCTRL_DRVCTRL_BASE;
width = 1;
break;
case UNIPHIER_PIN_DRV_2BIT:
supported_strength = strength_2bit;
reg = UNIPHIER_PINCTRL_DRV2CTRL_BASE;
width = 2;
break;
case UNIPHIER_PIN_DRV_3BIT:
supported_strength = strength_3bit;
reg = UNIPHIER_PINCTRL_DRV3CTRL_BASE;
width = 4;
break;
default:
dev_err(pctldev->dev,
"cannot change drive strength for pin %s\n",
desc->name);
return -EINVAL;
}
for (val = 0; supported_strength[val] > 0; val++) {
if (supported_strength[val] > strength)
break;
}
if (val == 0) {
dev_err(pctldev->dev,
"unsupported drive strength %u mA for pin %s\n",
strength, desc->name);
return -EINVAL;
}
val--;
drvctrl = uniphier_pin_get_drvctrl(desc->drv_data);
drvctrl *= width;
reg += drvctrl / 32 * 4;
shift = drvctrl % 32;
mask = (1U << width) - 1;
return regmap_update_bits(priv->regmap, priv->regbase + reg,
mask << shift, val << shift);
}
static int uniphier_conf_pin_input_enable(struct pinctrl_dev *pctldev,
const struct pin_desc *desc,
u16 enable)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
unsigned int iectrl = uniphier_pin_get_iectrl(desc->drv_data);
unsigned int reg, mask;
if (!(priv->socdata->caps & UNIPHIER_PINCTRL_CAPS_PERPIN_IECTRL) &&
!enable)
return -EINVAL;
if (iectrl == UNIPHIER_PIN_IECTRL_NONE)
return enable ? 0 : -EINVAL;
reg = priv->regbase + UNIPHIER_PINCTRL_IECTRL + iectrl / 32 * 4;
mask = BIT(iectrl % 32);
return regmap_update_bits(priv->regmap, reg, mask, enable ? mask : 0);
}
static int uniphier_conf_pin_config_set(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *configs,
unsigned num_configs)
{
const struct pin_desc *desc = pin_desc_get(pctldev, pin);
int i, ret;
for (i = 0; i < num_configs; i++) {
enum pin_config_param param =
pinconf_to_config_param(configs[i]);
u32 arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
case PIN_CONFIG_BIAS_PULL_PIN_DEFAULT:
ret = uniphier_conf_pin_bias_set(pctldev, desc,
param, arg);
break;
case PIN_CONFIG_DRIVE_STRENGTH:
ret = uniphier_conf_pin_drive_set(pctldev, desc, arg);
break;
case PIN_CONFIG_INPUT_ENABLE:
ret = uniphier_conf_pin_input_enable(pctldev, desc,
arg);
break;
default:
dev_err(pctldev->dev,
"unsupported configuration parameter %u\n",
param);
return -EINVAL;
}
if (ret)
return ret;
}
return 0;
}
static int uniphier_conf_pin_config_group_set(struct pinctrl_dev *pctldev,
unsigned selector,
unsigned long *configs,
unsigned num_configs)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
const unsigned *pins = priv->socdata->groups[selector].pins;
unsigned num_pins = priv->socdata->groups[selector].num_pins;
int i, ret;
for (i = 0; i < num_pins; i++) {
ret = uniphier_conf_pin_config_set(pctldev, pins[i],
configs, num_configs);
if (ret)
return ret;
}
return 0;
}
static int uniphier_pmx_get_functions_count(struct pinctrl_dev *pctldev)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
return priv->socdata->functions_count;
}
static const char *uniphier_pmx_get_function_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
return priv->socdata->functions[selector].name;
}
static int uniphier_pmx_get_function_groups(struct pinctrl_dev *pctldev,
unsigned selector,
const char * const **groups,
unsigned *num_groups)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
*groups = priv->socdata->functions[selector].groups;
*num_groups = priv->socdata->functions[selector].num_groups;
return 0;
}
static int uniphier_pmx_set_one_mux(struct pinctrl_dev *pctldev, unsigned pin,
int muxval)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
unsigned int mux_bits, reg_stride, reg, reg_end, shift, mask;
bool load_pinctrl;
int ret;
ret = uniphier_conf_pin_input_enable(pctldev,
pin_desc_get(pctldev, pin), 1);
if (ret)
return ret;
if (muxval < 0)
return 0;
if (priv->socdata->caps & UNIPHIER_PINCTRL_CAPS_DBGMUX_SEPARATE) {
mux_bits = 4;
reg_stride = 8;
load_pinctrl = true;
} else {
mux_bits = 8;
reg_stride = 4;
load_pinctrl = false;
}
reg = UNIPHIER_PINCTRL_PINMUX_BASE + pin * mux_bits / 32 * reg_stride;
reg_end = reg + reg_stride;
shift = pin * mux_bits % 32;
mask = (1U << mux_bits) - 1;
for (; reg < reg_end; reg += 4) {
ret = regmap_update_bits(priv->regmap, priv->regbase + reg,
mask << shift, muxval << shift);
if (ret)
return ret;
muxval >>= mux_bits;
}
if (load_pinctrl) {
ret = regmap_write(priv->regmap,
priv->regbase + UNIPHIER_PINCTRL_LOAD_PINMUX,
1);
if (ret)
return ret;
}
return 0;
}
static int uniphier_pmx_set_mux(struct pinctrl_dev *pctldev,
unsigned func_selector,
unsigned group_selector)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
const struct uniphier_pinctrl_group *grp =
&priv->socdata->groups[group_selector];
int i;
int ret;
for (i = 0; i < grp->num_pins; i++) {
ret = uniphier_pmx_set_one_mux(pctldev, grp->pins[i],
grp->muxvals[i]);
if (ret)
return ret;
}
return 0;
}
static int uniphier_pmx_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct uniphier_pinctrl_priv *priv = pinctrl_dev_get_drvdata(pctldev);
const struct uniphier_pinctrl_group *groups = priv->socdata->groups;
int groups_count = priv->socdata->groups_count;
enum uniphier_pinmux_gpio_range_type range_type;
int i, j;
if (strstr(range->name, "irq"))
range_type = UNIPHIER_PINMUX_GPIO_RANGE_IRQ;
else
range_type = UNIPHIER_PINMUX_GPIO_RANGE_PORT;
for (i = 0; i < groups_count; i++) {
if (groups[i].range_type != range_type)
continue;
for (j = 0; j < groups[i].num_pins; j++)
if (groups[i].pins[j] == offset)
goto found;
}
dev_err(pctldev->dev, "pin %u does not support GPIO\n", offset);
return -EINVAL;
found:
return uniphier_pmx_set_one_mux(pctldev, offset, groups[i].muxvals[j]);
}
int uniphier_pinctrl_probe(struct platform_device *pdev,
struct uniphier_pinctrl_socdata *socdata)
{
struct device *dev = &pdev->dev;
struct uniphier_pinctrl_priv *priv;
struct device_node *parent;
if (!socdata ||
!socdata->pins || !socdata->npins ||
!socdata->groups || !socdata->groups_count ||
!socdata->functions || !socdata->functions_count) {
dev_err(dev, "pinctrl socdata lacks necessary members\n");
return -EINVAL;
}
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (of_device_is_compatible(dev->of_node, "socionext,ph1-ld4-pinctrl") ||
of_device_is_compatible(dev->of_node, "socionext,ph1-pro4-pinctrl") ||
of_device_is_compatible(dev->of_node, "socionext,ph1-sld8-pinctrl") ||
of_device_is_compatible(dev->of_node, "socionext,ph1-pro5-pinctrl") ||
of_device_is_compatible(dev->of_node, "socionext,proxstream2-pinctrl") ||
of_device_is_compatible(dev->of_node, "socionext,ph1-ld6b-pinctrl")) {
priv->regmap = syscon_node_to_regmap(dev->of_node);
} else {
priv->regbase = 0x1000;
parent = of_get_parent(dev->of_node);
priv->regmap = syscon_node_to_regmap(parent);
of_node_put(parent);
}
if (IS_ERR(priv->regmap)) {
dev_err(dev, "failed to get regmap\n");
return PTR_ERR(priv->regmap);
}
priv->socdata = socdata;
priv->pctldesc.name = dev->driver->name;
priv->pctldesc.pins = socdata->pins;
priv->pctldesc.npins = socdata->npins;
priv->pctldesc.pctlops = &uniphier_pctlops;
priv->pctldesc.pmxops = &uniphier_pmxops;
priv->pctldesc.confops = &uniphier_confops;
priv->pctldesc.owner = dev->driver->owner;
priv->pctldev = devm_pinctrl_register(dev, &priv->pctldesc, priv);
if (IS_ERR(priv->pctldev)) {
dev_err(dev, "failed to register UniPhier pinctrl driver\n");
return PTR_ERR(priv->pctldev);
}
platform_set_drvdata(pdev, priv);
return 0;
}
