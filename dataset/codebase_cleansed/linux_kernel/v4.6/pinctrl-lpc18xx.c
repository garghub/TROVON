static int lpc18xx_pconf_get_usb1(enum pin_config_param param, int *arg, u32 reg)
{
switch (param) {
case PIN_CONFIG_LOW_POWER_MODE:
if (reg & LPC18XX_SCU_USB1_EPWR)
*arg = 0;
else
*arg = 1;
break;
case PIN_CONFIG_BIAS_DISABLE:
if (reg & LPC18XX_SCU_USB1_EPD)
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (reg & LPC18XX_SCU_USB1_EPD)
*arg = 1;
else
return -EINVAL;
break;
default:
return -ENOTSUPP;
}
return 0;
}
static int lpc18xx_pconf_get_i2c0(enum pin_config_param param, int *arg, u32 reg,
unsigned pin)
{
u8 shift;
if (pin == PIN_I2C0_SCL)
shift = LPC18XX_SCU_I2C0_SCL_SHIFT;
else
shift = LPC18XX_SCU_I2C0_SDA_SHIFT;
switch (param) {
case PIN_CONFIG_INPUT_ENABLE:
if (reg & (LPC18XX_SCU_I2C0_EZI << shift))
*arg = 1;
else
return -EINVAL;
break;
case PIN_CONFIG_SLEW_RATE:
if (reg & (LPC18XX_SCU_I2C0_EHD << shift))
*arg = 1;
else
*arg = 0;
break;
case PIN_CONFIG_INPUT_SCHMITT:
if (reg & (LPC18XX_SCU_I2C0_EFP << shift))
*arg = 3;
else
*arg = 50;
break;
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
if (reg & (LPC18XX_SCU_I2C0_ZIF << shift))
return -EINVAL;
else
*arg = 1;
break;
default:
return -ENOTSUPP;
}
return 0;
}
static int lpc18xx_pin_to_gpio(struct pinctrl_dev *pctldev, unsigned pin)
{
struct pinctrl_gpio_range *range;
range = pinctrl_find_gpio_range_from_pin_nolock(pctldev, pin);
if (!range)
return -EINVAL;
return pin - range->pin_base + range->base;
}
static int lpc18xx_get_pintsel(void __iomem *addr, u32 val, int *arg)
{
u32 reg_val;
int i;
reg_val = readl(addr);
for (i = 0; i < LPC18XX_SCU_IRQ_PER_PINTSEL; i++) {
if ((reg_val & LPC18XX_SCU_PINTSEL_VAL_MASK) == val)
return 0;
reg_val >>= BITS_PER_BYTE;
*arg += 1;
}
return -EINVAL;
}
static u32 lpc18xx_gpio_to_pintsel_val(int gpio)
{
unsigned int gpio_port, gpio_pin;
gpio_port = gpio / LPC18XX_GPIO_PINS_PER_PORT;
gpio_pin = gpio % LPC18XX_GPIO_PINS_PER_PORT;
return gpio_pin | (gpio_port << LPC18XX_SCU_PINTSEL_PORT_SHIFT);
}
static int lpc18xx_pconf_get_gpio_pin_int(struct pinctrl_dev *pctldev,
int *arg, unsigned pin)
{
struct lpc18xx_scu_data *scu = pinctrl_dev_get_drvdata(pctldev);
int gpio, ret;
u32 val;
gpio = lpc18xx_pin_to_gpio(pctldev, pin);
if (gpio < 0)
return -ENOTSUPP;
val = lpc18xx_gpio_to_pintsel_val(gpio);
*arg = 0;
ret = lpc18xx_get_pintsel(scu->base + LPC18XX_SCU_PINTSEL0, val, arg);
if (ret == 0)
return ret;
return lpc18xx_get_pintsel(scu->base + LPC18XX_SCU_PINTSEL1, val, arg);
}
static int lpc18xx_pconf_get_pin(struct pinctrl_dev *pctldev, unsigned param,
int *arg, u32 reg, unsigned pin,
struct lpc18xx_pin_caps *pin_cap)
{
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if ((!(reg & LPC18XX_SCU_PIN_EPD)) && (reg & LPC18XX_SCU_PIN_EPUN))
;
else
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_UP:
if (reg & LPC18XX_SCU_PIN_EPUN)
return -EINVAL;
else
*arg = 1;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
if (reg & LPC18XX_SCU_PIN_EPD)
*arg = 1;
else
return -EINVAL;
break;
case PIN_CONFIG_INPUT_ENABLE:
if (reg & LPC18XX_SCU_PIN_EZI)
*arg = 1;
else
return -EINVAL;
break;
case PIN_CONFIG_SLEW_RATE:
if (pin_cap->type == TYPE_HD)
return -ENOTSUPP;
if (reg & LPC18XX_SCU_PIN_EHS)
*arg = 1;
else
*arg = 0;
break;
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
if (reg & LPC18XX_SCU_PIN_ZIF)
return -EINVAL;
else
*arg = 1;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
if (pin_cap->type != TYPE_HD)
return -ENOTSUPP;
*arg = (reg & LPC18XX_SCU_PIN_EHD_MASK) >> LPC18XX_SCU_PIN_EHD_POS;
switch (*arg) {
case 3: *arg += 5;
case 2: *arg += 5;
case 1: *arg += 3;
case 0: *arg += 4;
}
break;
case PIN_CONFIG_GPIO_PIN_INT:
return lpc18xx_pconf_get_gpio_pin_int(pctldev, arg, pin);
default:
return -ENOTSUPP;
}
return 0;
}
static struct lpc18xx_pin_caps *lpc18xx_get_pin_caps(unsigned pin)
{
int i;
for (i = 0; i < ARRAY_SIZE(lpc18xx_pins); i++) {
if (lpc18xx_pins[i].number == pin)
return lpc18xx_pins[i].drv_data;
}
return NULL;
}
static int lpc18xx_pconf_get(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *config)
{
struct lpc18xx_scu_data *scu = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
struct lpc18xx_pin_caps *pin_cap;
int ret, arg = 0;
u32 reg;
pin_cap = lpc18xx_get_pin_caps(pin);
if (!pin_cap)
return -EINVAL;
reg = readl(scu->base + pin_cap->offset);
if (pin_cap->type == TYPE_I2C0)
ret = lpc18xx_pconf_get_i2c0(param, &arg, reg, pin);
else if (pin_cap->type == TYPE_USB1)
ret = lpc18xx_pconf_get_usb1(param, &arg, reg);
else
ret = lpc18xx_pconf_get_pin(pctldev, param, &arg, reg, pin, pin_cap);
if (ret < 0)
return ret;
*config = pinconf_to_config_packed(param, (u16)arg);
return 0;
}
static int lpc18xx_pconf_set_usb1(struct pinctrl_dev *pctldev,
enum pin_config_param param,
u16 param_val, u32 *reg)
{
switch (param) {
case PIN_CONFIG_LOW_POWER_MODE:
if (param_val)
*reg &= ~LPC18XX_SCU_USB1_EPWR;
else
*reg |= LPC18XX_SCU_USB1_EPWR;
break;
case PIN_CONFIG_BIAS_DISABLE:
*reg &= ~LPC18XX_SCU_USB1_EPD;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
*reg |= LPC18XX_SCU_USB1_EPD;
break;
default:
dev_err(pctldev->dev, "Property not supported\n");
return -ENOTSUPP;
}
return 0;
}
static int lpc18xx_pconf_set_i2c0(struct pinctrl_dev *pctldev,
enum pin_config_param param,
u16 param_val, u32 *reg,
unsigned pin)
{
u8 shift;
if (pin == PIN_I2C0_SCL)
shift = LPC18XX_SCU_I2C0_SCL_SHIFT;
else
shift = LPC18XX_SCU_I2C0_SDA_SHIFT;
switch (param) {
case PIN_CONFIG_INPUT_ENABLE:
if (param_val)
*reg |= (LPC18XX_SCU_I2C0_EZI << shift);
else
*reg &= ~(LPC18XX_SCU_I2C0_EZI << shift);
break;
case PIN_CONFIG_SLEW_RATE:
if (param_val)
*reg |= (LPC18XX_SCU_I2C0_EHD << shift);
else
*reg &= ~(LPC18XX_SCU_I2C0_EHD << shift);
break;
case PIN_CONFIG_INPUT_SCHMITT:
if (param_val == 3)
*reg |= (LPC18XX_SCU_I2C0_EFP << shift);
else if (param_val == 50)
*reg &= ~(LPC18XX_SCU_I2C0_EFP << shift);
else
return -ENOTSUPP;
break;
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
if (param_val)
*reg &= ~(LPC18XX_SCU_I2C0_ZIF << shift);
else
*reg |= (LPC18XX_SCU_I2C0_ZIF << shift);
break;
default:
dev_err(pctldev->dev, "Property not supported\n");
return -ENOTSUPP;
}
return 0;
}
static int lpc18xx_pconf_set_gpio_pin_int(struct pinctrl_dev *pctldev,
u16 param_val, unsigned pin)
{
struct lpc18xx_scu_data *scu = pinctrl_dev_get_drvdata(pctldev);
u32 val, reg_val, reg_offset = LPC18XX_SCU_PINTSEL0;
int gpio;
if (param_val >= LPC18XX_GPIO_PIN_INT_MAX)
return -EINVAL;
gpio = lpc18xx_pin_to_gpio(pctldev, pin);
if (gpio < 0)
return -ENOTSUPP;
val = lpc18xx_gpio_to_pintsel_val(gpio);
reg_offset += (param_val / LPC18XX_SCU_IRQ_PER_PINTSEL) * sizeof(u32);
reg_val = readl(scu->base + reg_offset);
reg_val &= ~LPC18XX_SCU_PINTSEL_VAL(LPC18XX_SCU_PINTSEL_VAL_MASK, param_val);
reg_val |= LPC18XX_SCU_PINTSEL_VAL(val, param_val);
writel(reg_val, scu->base + reg_offset);
return 0;
}
static int lpc18xx_pconf_set_pin(struct pinctrl_dev *pctldev, unsigned param,
u16 param_val, u32 *reg, unsigned pin,
struct lpc18xx_pin_caps *pin_cap)
{
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
*reg &= ~LPC18XX_SCU_PIN_EPD;
*reg |= LPC18XX_SCU_PIN_EPUN;
break;
case PIN_CONFIG_BIAS_PULL_UP:
*reg &= ~LPC18XX_SCU_PIN_EPUN;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
*reg |= LPC18XX_SCU_PIN_EPD;
break;
case PIN_CONFIG_INPUT_ENABLE:
if (param_val)
*reg |= LPC18XX_SCU_PIN_EZI;
else
*reg &= ~LPC18XX_SCU_PIN_EZI;
break;
case PIN_CONFIG_SLEW_RATE:
if (pin_cap->type == TYPE_HD) {
dev_err(pctldev->dev, "Slew rate unsupported on high-drive pins\n");
return -ENOTSUPP;
}
if (param_val == 0)
*reg &= ~LPC18XX_SCU_PIN_EHS;
else
*reg |= LPC18XX_SCU_PIN_EHS;
break;
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
if (param_val)
*reg &= ~LPC18XX_SCU_PIN_ZIF;
else
*reg |= LPC18XX_SCU_PIN_ZIF;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
if (pin_cap->type != TYPE_HD) {
dev_err(pctldev->dev, "Drive strength available only on high-drive pins\n");
return -ENOTSUPP;
}
*reg &= ~LPC18XX_SCU_PIN_EHD_MASK;
switch (param_val) {
case 20: param_val -= 5;
case 14: param_val -= 5;
case 8: param_val -= 3;
case 4: param_val -= 4;
break;
default:
dev_err(pctldev->dev, "Drive strength %u unsupported\n", param_val);
return -ENOTSUPP;
}
*reg |= param_val << LPC18XX_SCU_PIN_EHD_POS;
break;
case PIN_CONFIG_GPIO_PIN_INT:
return lpc18xx_pconf_set_gpio_pin_int(pctldev, param_val, pin);
default:
dev_err(pctldev->dev, "Property not supported\n");
return -ENOTSUPP;
}
return 0;
}
static int lpc18xx_pconf_set(struct pinctrl_dev *pctldev, unsigned pin,
unsigned long *configs, unsigned num_configs)
{
struct lpc18xx_scu_data *scu = pinctrl_dev_get_drvdata(pctldev);
struct lpc18xx_pin_caps *pin_cap;
enum pin_config_param param;
u16 param_val;
u32 reg;
int ret;
int i;
pin_cap = lpc18xx_get_pin_caps(pin);
if (!pin_cap)
return -EINVAL;
reg = readl(scu->base + pin_cap->offset);
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
param_val = pinconf_to_config_argument(configs[i]);
if (pin_cap->type == TYPE_I2C0)
ret = lpc18xx_pconf_set_i2c0(pctldev, param, param_val, &reg, pin);
else if (pin_cap->type == TYPE_USB1)
ret = lpc18xx_pconf_set_usb1(pctldev, param, param_val, &reg);
else
ret = lpc18xx_pconf_set_pin(pctldev, param, param_val, &reg, pin, pin_cap);
if (ret)
return ret;
}
writel(reg, scu->base + pin_cap->offset);
return 0;
}
static int lpc18xx_pmx_get_funcs_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(lpc18xx_function_names);
}
static const char *lpc18xx_pmx_get_func_name(struct pinctrl_dev *pctldev,
unsigned function)
{
return lpc18xx_function_names[function];
}
static int lpc18xx_pmx_get_func_groups(struct pinctrl_dev *pctldev,
unsigned function,
const char *const **groups,
unsigned *const num_groups)
{
struct lpc18xx_scu_data *scu = pinctrl_dev_get_drvdata(pctldev);
*groups = scu->func[function].groups;
*num_groups = scu->func[function].ngroups;
return 0;
}
static int lpc18xx_pmx_set(struct pinctrl_dev *pctldev, unsigned function,
unsigned group)
{
struct lpc18xx_scu_data *scu = pinctrl_dev_get_drvdata(pctldev);
struct lpc18xx_pin_caps *pin = lpc18xx_pins[group].drv_data;
int func;
u32 reg;
if (pin->type == TYPE_USB1) {
if (function == FUNC_USB1)
return 0;
goto fail;
}
if (pin->type == TYPE_I2C0) {
if (function == FUNC_I2C0)
return 0;
goto fail;
}
if (function == FUNC_ADC && (pin->analog & LPC18XX_ANALOG_PIN)) {
u32 offset;
writel(LPC18XX_SCU_ANALOG_PIN_CFG, scu->base + pin->offset);
if (LPC18XX_ANALOG_ADC(pin->analog) == 0)
offset = LPC18XX_SCU_REG_ENAIO0;
else
offset = LPC18XX_SCU_REG_ENAIO1;
reg = readl(scu->base + offset);
reg |= pin->analog & LPC18XX_ANALOG_BIT_MASK;
writel(reg, scu->base + offset);
return 0;
}
if (function == FUNC_DAC && (pin->analog & LPC18XX_ANALOG_PIN)) {
writel(LPC18XX_SCU_ANALOG_PIN_CFG, scu->base + pin->offset);
reg = readl(scu->base + LPC18XX_SCU_REG_ENAIO2);
reg |= LPC18XX_SCU_REG_ENAIO2_DAC;
writel(reg, scu->base + LPC18XX_SCU_REG_ENAIO2);
return 0;
}
for (func = 0; func < LPC18XX_SCU_FUNC_PER_PIN; func++) {
if (function == pin->functions[func])
break;
}
if (func >= LPC18XX_SCU_FUNC_PER_PIN)
goto fail;
reg = readl(scu->base + pin->offset);
reg &= ~LPC18XX_SCU_PIN_MODE_MASK;
writel(reg | func, scu->base + pin->offset);
return 0;
fail:
dev_err(pctldev->dev, "Pin %s can't be %s\n", lpc18xx_pins[group].name,
lpc18xx_function_names[function]);
return -EINVAL;
}
static int lpc18xx_pctl_get_groups_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(lpc18xx_pins);
}
static const char *lpc18xx_pctl_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
return lpc18xx_pins[group].name;
}
static int lpc18xx_pctl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned group,
const unsigned **pins,
unsigned *num_pins)
{
*pins = &lpc18xx_pins[group].number;
*num_pins = 1;
return 0;
}
static bool lpc18xx_valid_pin_function(unsigned pin, unsigned function)
{
struct lpc18xx_pin_caps *p = lpc18xx_pins[pin].drv_data;
int i;
if (function == FUNC_DAC && p->analog == DAC)
return true;
if (function == FUNC_ADC && p->analog)
return true;
if (function == FUNC_I2C0 && p->type == TYPE_I2C0)
return true;
if (function == FUNC_USB1 && p->type == TYPE_USB1)
return true;
for (i = 0; i < LPC18XX_SCU_FUNC_PER_PIN; i++) {
if (function == p->functions[i])
return true;
}
return false;
}
static int lpc18xx_create_group_func_map(struct device *dev,
struct lpc18xx_scu_data *scu)
{
u16 pins[ARRAY_SIZE(lpc18xx_pins)];
int func, ngroups, i;
for (func = 0; func < FUNC_MAX; func++) {
for (ngroups = 0, i = 0; i < ARRAY_SIZE(lpc18xx_pins); i++) {
if (lpc18xx_valid_pin_function(i, func))
pins[ngroups++] = i;
}
scu->func[func].ngroups = ngroups;
scu->func[func].groups = devm_kzalloc(dev, ngroups *
sizeof(char *), GFP_KERNEL);
if (!scu->func[func].groups)
return -ENOMEM;
for (i = 0; i < ngroups; i++)
scu->func[func].groups[i] = lpc18xx_pins[pins[i]].name;
}
return 0;
}
static int lpc18xx_scu_probe(struct platform_device *pdev)
{
struct lpc18xx_scu_data *scu;
struct resource *res;
int ret;
scu = devm_kzalloc(&pdev->dev, sizeof(*scu), GFP_KERNEL);
if (!scu)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
scu->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(scu->base))
return PTR_ERR(scu->base);
scu->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(scu->clk)) {
dev_err(&pdev->dev, "Input clock not found.\n");
return PTR_ERR(scu->clk);
}
ret = lpc18xx_create_group_func_map(&pdev->dev, scu);
if (ret) {
dev_err(&pdev->dev, "Unable to create group func map.\n");
return ret;
}
ret = clk_prepare_enable(scu->clk);
if (ret) {
dev_err(&pdev->dev, "Unable to enable clock.\n");
return ret;
}
platform_set_drvdata(pdev, scu);
scu->pctl = pinctrl_register(&lpc18xx_scu_desc, &pdev->dev, scu);
if (IS_ERR(scu->pctl)) {
dev_err(&pdev->dev, "Could not register pinctrl driver\n");
clk_disable_unprepare(scu->clk);
return PTR_ERR(scu->pctl);
}
return 0;
}
static int lpc18xx_scu_remove(struct platform_device *pdev)
{
struct lpc18xx_scu_data *scu = platform_get_drvdata(pdev);
pinctrl_unregister(scu->pctl);
clk_disable_unprepare(scu->clk);
return 0;
}
