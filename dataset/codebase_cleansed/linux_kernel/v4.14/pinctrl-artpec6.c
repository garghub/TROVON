static unsigned int artpec6_pmx_reg_offset(unsigned int pin)
{
int i;
for (i = 0; i < ARRAY_SIZE(pin_register); i++) {
if (pin <= pin_register[i].end) {
return (pin - pin_register[i].start) * 4 +
pin_register[i].reg_base;
}
}
pr_err("%s: Impossible pin %d\n", __func__, pin);
return 0;
}
static int artpec6_get_groups_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(artpec6_pin_groups);
}
static const char *artpec6_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
return artpec6_pin_groups[group].name;
}
static int artpec6_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int group,
const unsigned int **pins,
unsigned int *num_pins)
{
*pins = (unsigned int *)artpec6_pin_groups[group].pins;
*num_pins = artpec6_pin_groups[group].num_pins;
return 0;
}
static int artpec6_pconf_drive_mA_to_field(unsigned int mA)
{
switch (mA) {
case ARTPEC6_DRIVE_4mA:
return ARTPEC6_DRIVE_4mA_SET;
case ARTPEC6_DRIVE_6mA:
return ARTPEC6_DRIVE_6mA_SET;
case ARTPEC6_DRIVE_8mA:
return ARTPEC6_DRIVE_8mA_SET;
case ARTPEC6_DRIVE_9mA:
return ARTPEC6_DRIVE_9mA_SET;
default:
return -EINVAL;
}
}
static unsigned int artpec6_pconf_drive_field_to_mA(int field)
{
switch (field) {
case ARTPEC6_DRIVE_4mA_SET:
return ARTPEC6_DRIVE_4mA;
case ARTPEC6_DRIVE_6mA_SET:
return ARTPEC6_DRIVE_6mA;
case ARTPEC6_DRIVE_8mA_SET:
return ARTPEC6_DRIVE_8mA;
case ARTPEC6_DRIVE_9mA_SET:
return ARTPEC6_DRIVE_9mA;
default:
return 0;
}
}
static int artpec6_pmx_get_functions_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(artpec6_pmx_functions);
}
static const char *artpec6_pmx_get_fname(struct pinctrl_dev *pctldev,
unsigned int function)
{
return artpec6_pmx_functions[function].name;
}
static int artpec6_pmx_get_fgroups(struct pinctrl_dev *pctldev,
unsigned int function,
const char * const **groups,
unsigned int * const num_groups)
{
*groups = artpec6_pmx_functions[function].groups;
*num_groups = artpec6_pmx_functions[function].num_groups;
return 0;
}
static void artpec6_pmx_select_func(struct pinctrl_dev *pctldev,
unsigned int function, unsigned int group,
bool enable)
{
unsigned int regval, val;
unsigned int reg;
int i;
struct artpec6_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
for (i = 0; i < artpec6_pin_groups[group].num_pins; i++) {
if (artpec6_pin_groups[group].pins[i] > ARTPEC6_MAX_MUXABLE)
continue;
if (!strcmp(artpec6_pmx_get_fname(pctldev, function), "gpio")) {
val = ARTPEC6_CONFIG_0 << ARTPEC6_PINMUX_SEL_SHIFT;
} else {
if (enable)
val = artpec6_pin_groups[group].config
<< ARTPEC6_PINMUX_SEL_SHIFT;
else
val = ARTPEC6_CONFIG_0
<< ARTPEC6_PINMUX_SEL_SHIFT;
}
reg = artpec6_pmx_reg_offset(artpec6_pin_groups[group].pins[i]);
regval = readl(pmx->base + reg);
regval &= ~ARTPEC6_PINMUX_SEL_MASK;
regval |= val;
writel(regval, pmx->base + reg);
}
}
int artpec6_pmx_enable(struct pinctrl_dev *pctldev, unsigned int function,
unsigned int group)
{
struct artpec6_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
dev_dbg(pmx->dev, "enabling %s function for pin group %s\n",
artpec6_pmx_get_fname(pctldev, function),
artpec6_get_group_name(pctldev, group));
artpec6_pmx_select_func(pctldev, function, group, true);
return 0;
}
void artpec6_pmx_disable(struct pinctrl_dev *pctldev, unsigned int function,
unsigned int group)
{
struct artpec6_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
dev_dbg(pmx->dev, "disabling %s function for pin group %s\n",
artpec6_pmx_get_fname(pctldev, function),
artpec6_get_group_name(pctldev, group));
artpec6_pmx_select_func(pctldev, function, group, false);
}
static int artpec6_pmx_request_gpio(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int pin)
{
struct artpec6_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
unsigned int reg = artpec6_pmx_reg_offset(pin);
u32 val;
if (pin >= 32)
return -EINVAL;
val = readl_relaxed(pmx->base + reg);
val &= ~ARTPEC6_PINMUX_SEL_MASK;
val |= ARTPEC6_CONFIG_0 << ARTPEC6_PINMUX_SEL_SHIFT;
writel_relaxed(val, pmx->base + reg);
return 0;
}
static int artpec6_pconf_get(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *config)
{
struct artpec6_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
unsigned int regval;
if (pin >= pmx->num_pins) {
dev_dbg(pmx->dev, "pinconf is not supported for pin %s\n",
pmx->pins[pin].name);
return -ENOTSUPP;
}
dev_dbg(pmx->dev, "getting configuration for pin %s\n",
pmx->pins[pin].name);
regval = readl(pmx->base + artpec6_pmx_reg_offset(pin));
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if (!(regval & ARTPEC6_PINMUX_UDC1_MASK))
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
if (regval & ARTPEC6_PINMUX_UDC1_MASK)
return -EINVAL;
regval = regval & ARTPEC6_PINMUX_UDC0_MASK;
if ((param == PIN_CONFIG_BIAS_PULL_UP && !regval) ||
(param == PIN_CONFIG_BIAS_PULL_DOWN && regval))
return -EINVAL;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
regval = (regval & ARTPEC6_PINMUX_DRV_MASK)
>> ARTPEC6_PINMUX_DRV_SHIFT;
regval = artpec6_pconf_drive_field_to_mA(regval);
*config = pinconf_to_config_packed(param, regval);
break;
default:
return -ENOTSUPP;
}
return 0;
}
static int artpec6_pconf_set(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *configs, unsigned int num_configs)
{
struct artpec6_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
unsigned int arg;
unsigned int regval;
unsigned int *reg;
int i;
if (pin >= pmx->num_pins) {
dev_dbg(pmx->dev, "pinconf is not supported for pin %s\n",
pmx->pins[pin].name);
return -ENOTSUPP;
}
dev_dbg(pmx->dev, "setting configuration for pin %s\n",
pmx->pins[pin].name);
reg = pmx->base + artpec6_pmx_reg_offset(pin);
for (i = 0; i < num_configs; i++) {
int drive;
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
regval = readl(reg);
regval |= (1 << ARTPEC6_PINMUX_UDC1_SHIFT);
writel(regval, reg);
break;
case PIN_CONFIG_BIAS_PULL_UP:
if (arg != 1) {
dev_dbg(pctldev->dev, "%s: arg %u out of range\n",
__func__, arg);
return -EINVAL;
}
regval = readl(reg);
regval |= (arg << ARTPEC6_PINMUX_UDC0_SHIFT);
regval &= ~ARTPEC6_PINMUX_UDC1_MASK;
writel(regval, reg);
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (arg != 1) {
dev_dbg(pctldev->dev, "%s: arg %u out of range\n",
__func__, arg);
return -EINVAL;
}
regval = readl(reg);
regval &= ~(arg << ARTPEC6_PINMUX_UDC0_SHIFT);
regval &= ~ARTPEC6_PINMUX_UDC1_MASK;
writel(regval, reg);
break;
case PIN_CONFIG_DRIVE_STRENGTH:
drive = artpec6_pconf_drive_mA_to_field(arg);
if (drive < 0) {
dev_dbg(pctldev->dev, "%s: arg %u out of range\n",
__func__, arg);
return -EINVAL;
}
regval = readl(reg);
regval &= ~ARTPEC6_PINMUX_DRV_MASK;
regval |= (drive << ARTPEC6_PINMUX_DRV_SHIFT);
writel(regval, reg);
break;
default:
dev_dbg(pmx->dev, "parameter not supported\n");
return -ENOTSUPP;
}
}
return 0;
}
static int artpec6_pconf_group_set(struct pinctrl_dev *pctldev,
unsigned int group, unsigned long *configs,
unsigned int num_configs)
{
unsigned int num_pins, current_pin;
int ret;
dev_dbg(pctldev->dev, "setting group %s configuration\n",
artpec6_get_group_name(pctldev, group));
num_pins = artpec6_pin_groups[group].num_pins;
for (current_pin = 0; current_pin < num_pins; current_pin++) {
ret = artpec6_pconf_set(pctldev,
artpec6_pin_groups[group].pins[current_pin],
configs, num_configs);
if (ret < 0)
return ret;
}
return 0;
}
static void artpec6_pmx_reset(struct artpec6_pmx *pmx)
{
void __iomem *base = pmx->base;
int i;
for (i = 0; i < ARTPEC6_LAST_PIN; i++) {
u32 val;
val = readl_relaxed(base + artpec6_pmx_reg_offset(i));
val &= ~ARTPEC6_PINMUX_DRV_MASK;
val |= ARTPEC6_DRIVE_8mA_SET << ARTPEC6_PINMUX_DRV_SHIFT;
writel_relaxed(val, base + artpec6_pmx_reg_offset(i));
}
}
static int artpec6_pmx_probe(struct platform_device *pdev)
{
struct artpec6_pmx *pmx;
struct resource *res;
pmx = devm_kzalloc(&pdev->dev, sizeof(*pmx), GFP_KERNEL);
if (!pmx)
return -ENOMEM;
pmx->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pmx->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pmx->base))
return PTR_ERR(pmx->base);
artpec6_pmx_reset(pmx);
pmx->pins = artpec6_pins;
pmx->num_pins = ARRAY_SIZE(artpec6_pins);
pmx->functions = artpec6_pmx_functions;
pmx->num_functions = ARRAY_SIZE(artpec6_pmx_functions);
pmx->pin_groups = artpec6_pin_groups;
pmx->num_pin_groups = ARRAY_SIZE(artpec6_pin_groups);
pmx->pctl = pinctrl_register(&artpec6_desc, &pdev->dev, pmx);
if (IS_ERR(pmx->pctl)) {
dev_err(&pdev->dev, "could not register pinctrl driver\n");
return PTR_ERR(pmx->pctl);
}
platform_set_drvdata(pdev, pmx);
dev_info(&pdev->dev, "initialised Axis ARTPEC-6 pinctrl driver\n");
return 0;
}
static int artpec6_pmx_remove(struct platform_device *pdev)
{
struct artpec6_pmx *pmx = platform_get_drvdata(pdev);
pinctrl_unregister(pmx->pctl);
return 0;
}
static int __init artpec6_pmx_init(void)
{
return platform_driver_register(&artpec6_pmx_driver);
}
