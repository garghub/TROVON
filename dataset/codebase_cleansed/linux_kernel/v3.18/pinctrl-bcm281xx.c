static inline enum bcm281xx_pin_type pin_type_get(struct pinctrl_dev *pctldev,
unsigned pin)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
if (pin >= pdata->npins)
return BCM281XX_PIN_TYPE_UNKNOWN;
return *(enum bcm281xx_pin_type *)(pdata->pins[pin].drv_data);
}
static inline void bcm281xx_pin_update(u32 *reg_val, u32 *reg_mask,
u32 param_val, u32 param_shift,
u32 param_mask)
{
*reg_val &= ~param_mask;
*reg_val |= (param_val << param_shift) & param_mask;
*reg_mask |= param_mask;
}
static int bcm281xx_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
return pdata->npins;
}
static const char *bcm281xx_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
return pdata->pins[group].name;
}
static int bcm281xx_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned group,
const unsigned **pins,
unsigned *num_pins)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
*pins = &pdata->pins[group].number;
*num_pins = 1;
return 0;
}
static void bcm281xx_pinctrl_pin_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s,
unsigned offset)
{
seq_printf(s, " %s", dev_name(pctldev->dev));
}
static int bcm281xx_pinctrl_get_fcns_count(struct pinctrl_dev *pctldev)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
return pdata->nfunctions;
}
static const char *bcm281xx_pinctrl_get_fcn_name(struct pinctrl_dev *pctldev,
unsigned function)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
return pdata->functions[function].name;
}
static int bcm281xx_pinctrl_get_fcn_groups(struct pinctrl_dev *pctldev,
unsigned function,
const char * const **groups,
unsigned * const num_groups)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
*groups = pdata->functions[function].groups;
*num_groups = pdata->functions[function].ngroups;
return 0;
}
static int bcm281xx_pinmux_set(struct pinctrl_dev *pctldev,
unsigned function,
unsigned group)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
const struct bcm281xx_pin_function *f = &pdata->functions[function];
u32 offset = 4 * pdata->pins[group].number;
int rc = 0;
dev_dbg(pctldev->dev,
"%s(): Enable function %s (%d) of pin %s (%d) @offset 0x%x.\n",
__func__, f->name, function, pdata->pins[group].name,
pdata->pins[group].number, offset);
rc = regmap_update_bits(pdata->regmap, offset,
BCM281XX_PIN_REG_F_SEL_MASK,
function << BCM281XX_PIN_REG_F_SEL_SHIFT);
if (rc)
dev_err(pctldev->dev,
"Error updating register for pin %s (%d).\n",
pdata->pins[group].name, pdata->pins[group].number);
return rc;
}
static int bcm281xx_pinctrl_pin_config_get(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *config)
{
return -ENOTSUPP;
}
static int bcm281xx_std_pin_update(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *configs,
unsigned num_configs,
u32 *val,
u32 *mask)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
int i;
enum pin_config_param param;
u16 arg;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
arg = (arg >= 1 ? 1 : 0);
bcm281xx_pin_update(val, mask, arg,
BCM281XX_PIN_SHIFT(STD, HYST),
BCM281XX_PIN_MASK(STD, HYST));
break;
case PIN_CONFIG_BIAS_DISABLE:
bcm281xx_pin_update(val, mask, 0,
BCM281XX_PIN_SHIFT(STD, PULL_UP),
BCM281XX_PIN_MASK(STD, PULL_UP));
bcm281xx_pin_update(val, mask, 0,
BCM281XX_PIN_SHIFT(STD, PULL_DN),
BCM281XX_PIN_MASK(STD, PULL_DN));
break;
case PIN_CONFIG_BIAS_PULL_UP:
bcm281xx_pin_update(val, mask, 1,
BCM281XX_PIN_SHIFT(STD, PULL_UP),
BCM281XX_PIN_MASK(STD, PULL_UP));
bcm281xx_pin_update(val, mask, 0,
BCM281XX_PIN_SHIFT(STD, PULL_DN),
BCM281XX_PIN_MASK(STD, PULL_DN));
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
bcm281xx_pin_update(val, mask, 0,
BCM281XX_PIN_SHIFT(STD, PULL_UP),
BCM281XX_PIN_MASK(STD, PULL_UP));
bcm281xx_pin_update(val, mask, 1,
BCM281XX_PIN_SHIFT(STD, PULL_DN),
BCM281XX_PIN_MASK(STD, PULL_DN));
break;
case PIN_CONFIG_SLEW_RATE:
arg = (arg >= 1 ? 1 : 0);
bcm281xx_pin_update(val, mask, arg,
BCM281XX_PIN_SHIFT(STD, SLEW),
BCM281XX_PIN_MASK(STD, SLEW));
break;
case PIN_CONFIG_INPUT_ENABLE:
arg = (arg >= 1 ? 0 : 1);
bcm281xx_pin_update(val, mask, arg,
BCM281XX_PIN_SHIFT(STD, INPUT_DIS),
BCM281XX_PIN_MASK(STD, INPUT_DIS));
break;
case PIN_CONFIG_DRIVE_STRENGTH:
if ((arg < 2) || (arg > 16) || (arg % 2)) {
dev_err(pctldev->dev,
"Invalid Drive Strength value (%d) for "
"pin %s (%d). Valid values are "
"(2..16) mA, even numbers only.\n",
arg, pdata->pins[pin].name, pin);
return -EINVAL;
}
bcm281xx_pin_update(val, mask, (arg/2)-1,
BCM281XX_PIN_SHIFT(STD, DRV_STR),
BCM281XX_PIN_MASK(STD, DRV_STR));
break;
default:
dev_err(pctldev->dev,
"Unrecognized pin config %d for pin %s (%d).\n",
param, pdata->pins[pin].name, pin);
return -EINVAL;
}
}
return 0;
}
static int bcm281xx_i2c_pin_update(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *configs,
unsigned num_configs,
u32 *val,
u32 *mask)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
int i, j;
enum pin_config_param param;
u16 arg;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
for (j = 0; j < ARRAY_SIZE(bcm281xx_pullup_map); j++)
if (bcm281xx_pullup_map[j] == arg)
break;
if (j == ARRAY_SIZE(bcm281xx_pullup_map)) {
dev_err(pctldev->dev,
"Invalid pull-up value (%d) for pin %s "
"(%d). Valid values are 568, 720, 831, "
"1080, 1200, 1800, 2700 Ohms.\n",
arg, pdata->pins[pin].name, pin);
return -EINVAL;
}
bcm281xx_pin_update(val, mask, j+1,
BCM281XX_PIN_SHIFT(I2C, PULL_UP_STR),
BCM281XX_PIN_MASK(I2C, PULL_UP_STR));
break;
case PIN_CONFIG_BIAS_DISABLE:
bcm281xx_pin_update(val, mask, 0,
BCM281XX_PIN_SHIFT(I2C, PULL_UP_STR),
BCM281XX_PIN_MASK(I2C, PULL_UP_STR));
break;
case PIN_CONFIG_SLEW_RATE:
arg = (arg >= 1 ? 1 : 0);
bcm281xx_pin_update(val, mask, arg,
BCM281XX_PIN_SHIFT(I2C, SLEW),
BCM281XX_PIN_MASK(I2C, SLEW));
break;
case PIN_CONFIG_INPUT_ENABLE:
arg = (arg >= 1 ? 0 : 1);
bcm281xx_pin_update(val, mask, arg,
BCM281XX_PIN_SHIFT(I2C, INPUT_DIS),
BCM281XX_PIN_MASK(I2C, INPUT_DIS));
break;
default:
dev_err(pctldev->dev,
"Unrecognized pin config %d for pin %s (%d).\n",
param, pdata->pins[pin].name, pin);
return -EINVAL;
}
}
return 0;
}
static int bcm281xx_hdmi_pin_update(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *configs,
unsigned num_configs,
u32 *val,
u32 *mask)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
int i;
enum pin_config_param param;
u16 arg;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_SLEW_RATE:
arg = (arg >= 1 ? 1 : 0);
bcm281xx_pin_update(val, mask, arg,
BCM281XX_PIN_SHIFT(HDMI, MODE),
BCM281XX_PIN_MASK(HDMI, MODE));
break;
case PIN_CONFIG_INPUT_ENABLE:
arg = (arg >= 1 ? 0 : 1);
bcm281xx_pin_update(val, mask, arg,
BCM281XX_PIN_SHIFT(HDMI, INPUT_DIS),
BCM281XX_PIN_MASK(HDMI, INPUT_DIS));
break;
default:
dev_err(pctldev->dev,
"Unrecognized pin config %d for pin %s (%d).\n",
param, pdata->pins[pin].name, pin);
return -EINVAL;
}
}
return 0;
}
static int bcm281xx_pinctrl_pin_config_set(struct pinctrl_dev *pctldev,
unsigned pin,
unsigned long *configs,
unsigned num_configs)
{
struct bcm281xx_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
enum bcm281xx_pin_type pin_type;
u32 offset = 4 * pin;
u32 cfg_val, cfg_mask;
int rc;
cfg_val = 0;
cfg_mask = 0;
pin_type = pin_type_get(pctldev, pin);
switch (pin_type) {
case BCM281XX_PIN_TYPE_STD:
rc = bcm281xx_std_pin_update(pctldev, pin, configs,
num_configs, &cfg_val, &cfg_mask);
break;
case BCM281XX_PIN_TYPE_I2C:
rc = bcm281xx_i2c_pin_update(pctldev, pin, configs,
num_configs, &cfg_val, &cfg_mask);
break;
case BCM281XX_PIN_TYPE_HDMI:
rc = bcm281xx_hdmi_pin_update(pctldev, pin, configs,
num_configs, &cfg_val, &cfg_mask);
break;
default:
dev_err(pctldev->dev, "Unknown pin type for pin %s (%d).\n",
pdata->pins[pin].name, pin);
return -EINVAL;
}
if (rc)
return rc;
dev_dbg(pctldev->dev,
"%s(): Set pin %s (%d) with config 0x%x, mask 0x%x\n",
__func__, pdata->pins[pin].name, pin, cfg_val, cfg_mask);
rc = regmap_update_bits(pdata->regmap, offset, cfg_mask, cfg_val);
if (rc) {
dev_err(pctldev->dev,
"Error updating register for pin %s (%d).\n",
pdata->pins[pin].name, pin);
return rc;
}
return 0;
}
static int __init bcm281xx_pinctrl_probe(struct platform_device *pdev)
{
struct bcm281xx_pinctrl_data *pdata = &bcm281xx_pinctrl;
struct resource *res;
struct pinctrl_dev *pctl;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Missing MEM resource\n");
return -ENODEV;
}
pdata->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pdata->reg_base)) {
dev_err(&pdev->dev, "Failed to ioremap MEM resource\n");
return -ENODEV;
}
pdata->regmap = devm_regmap_init_mmio(&pdev->dev, pdata->reg_base,
&bcm281xx_pinctrl_regmap_config);
if (IS_ERR(pdata->regmap)) {
dev_err(&pdev->dev, "Regmap MMIO init failed.\n");
return -ENODEV;
}
bcm281xx_pinctrl_desc.name = dev_name(&pdev->dev);
bcm281xx_pinctrl_desc.pins = bcm281xx_pinctrl.pins;
bcm281xx_pinctrl_desc.npins = bcm281xx_pinctrl.npins;
pctl = pinctrl_register(&bcm281xx_pinctrl_desc,
&pdev->dev,
pdata);
if (!pctl) {
dev_err(&pdev->dev, "Failed to register pinctrl\n");
return -ENODEV;
}
platform_set_drvdata(pdev, pdata);
return 0;
}
