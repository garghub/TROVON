static int as3722_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
return as_pci->num_pin_groups;
}
static const char *as3722_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
return as_pci->pin_groups[group].name;
}
static int as3722_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned group, const unsigned **pins, unsigned *num_pins)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
*pins = as_pci->pin_groups[group].pins;
*num_pins = as_pci->pin_groups[group].npins;
return 0;
}
static int as3722_pinctrl_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
return as_pci->num_functions;
}
static const char *as3722_pinctrl_get_func_name(struct pinctrl_dev *pctldev,
unsigned function)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
return as_pci->functions[function].name;
}
static int as3722_pinctrl_get_func_groups(struct pinctrl_dev *pctldev,
unsigned function, const char * const **groups,
unsigned * const num_groups)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
*groups = as_pci->functions[function].groups;
*num_groups = as_pci->functions[function].ngroups;
return 0;
}
static int as3722_pinctrl_enable(struct pinctrl_dev *pctldev, unsigned function,
unsigned group)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
int gpio_cntr_reg = AS3722_GPIOn_CONTROL_REG(group);
u8 val = AS3722_GPIO_IOSF_VAL(as_pci->functions[function].mux_option);
int ret;
dev_dbg(as_pci->dev, "%s(): GPIO %u pin to function %u and val %u\n",
__func__, group, function, val);
ret = as3722_update_bits(as_pci->as3722, gpio_cntr_reg,
AS3722_GPIO_IOSF_MASK, val);
if (ret < 0) {
dev_err(as_pci->dev, "GPIO%d_CTRL_REG update failed %d\n",
group, ret);
return ret;
}
as_pci->gpio_control[group].io_function = function;
switch (val) {
case AS3722_GPIO_IOSF_SD0_OUT:
case AS3722_GPIO_IOSF_PWR_GOOD_OUT:
case AS3722_GPIO_IOSF_Q32K_OUT:
case AS3722_GPIO_IOSF_PWM_OUT:
case AS3722_GPIO_IOSF_SD6_LOW_VOLT_LOW:
ret = as3722_update_bits(as_pci->as3722, gpio_cntr_reg,
AS3722_GPIO_MODE_MASK, AS3722_GPIO_MODE_OUTPUT_VDDH);
if (ret < 0) {
dev_err(as_pci->dev, "GPIO%d_CTRL update failed %d\n",
group, ret);
return ret;
}
as_pci->gpio_control[group].mode_prop =
AS3722_GPIO_MODE_OUTPUT_VDDH;
break;
default:
break;
}
return ret;
}
static int as3722_pinctrl_gpio_get_mode(unsigned gpio_mode_prop, bool input)
{
if (gpio_mode_prop & AS3722_GPIO_MODE_HIGH_IMPED)
return -EINVAL;
if (gpio_mode_prop & AS3722_GPIO_MODE_OPEN_DRAIN) {
if (gpio_mode_prop & AS3722_GPIO_MODE_PULL_UP)
return AS3722_GPIO_MODE_IO_OPEN_DRAIN_PULL_UP;
return AS3722_GPIO_MODE_IO_OPEN_DRAIN;
}
if (input) {
if (gpio_mode_prop & AS3722_GPIO_MODE_PULL_UP)
return AS3722_GPIO_MODE_INPUT_PULL_UP;
else if (gpio_mode_prop & AS3722_GPIO_MODE_PULL_DOWN)
return AS3722_GPIO_MODE_INPUT_PULL_DOWN;
return AS3722_GPIO_MODE_INPUT;
}
if (gpio_mode_prop & AS3722_GPIO_MODE_PULL_DOWN)
return AS3722_GPIO_MODE_OUTPUT_VDDL;
return AS3722_GPIO_MODE_OUTPUT_VDDH;
}
static int as3722_pinctrl_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, unsigned offset)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
if (as_pci->gpio_control[offset].io_function)
return -EBUSY;
return 0;
}
static int as3722_pinctrl_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, unsigned offset, bool input)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
struct as3722 *as3722 = as_pci->as3722;
int mode;
mode = as3722_pinctrl_gpio_get_mode(
as_pci->gpio_control[offset].mode_prop, input);
if (mode < 0) {
dev_err(as_pci->dev, "%s direction for GPIO %d not supported\n",
(input) ? "Input" : "Output", offset);
return mode;
}
if (as_pci->gpio_control[offset].enable_gpio_invert)
mode |= AS3722_GPIO_INV;
return as3722_write(as3722, AS3722_GPIOn_CONTROL_REG(offset), mode);
}
static int as3722_pinconf_get(struct pinctrl_dev *pctldev,
unsigned pin, unsigned long *config)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
int arg = 0;
u16 prop;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
prop = AS3722_GPIO_MODE_PULL_UP |
AS3722_GPIO_MODE_PULL_DOWN;
if (!(as_pci->gpio_control[pin].mode_prop & prop))
arg = 1;
prop = 0;
break;
case PIN_CONFIG_BIAS_PULL_UP:
prop = AS3722_GPIO_MODE_PULL_UP;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
prop = AS3722_GPIO_MODE_PULL_DOWN;
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
prop = AS3722_GPIO_MODE_OPEN_DRAIN;
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
prop = AS3722_GPIO_MODE_HIGH_IMPED;
break;
default:
dev_err(as_pci->dev, "Properties not supported\n");
return -ENOTSUPP;
}
if (as_pci->gpio_control[pin].mode_prop & prop)
arg = 1;
*config = pinconf_to_config_packed(param, (u16)arg);
return 0;
}
static int as3722_pinconf_set(struct pinctrl_dev *pctldev,
unsigned pin, unsigned long *configs,
unsigned num_configs)
{
struct as3722_pctrl_info *as_pci = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
int mode_prop;
int i;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
mode_prop = as_pci->gpio_control[pin].mode_prop;
switch (param) {
case PIN_CONFIG_BIAS_PULL_PIN_DEFAULT:
break;
case PIN_CONFIG_BIAS_DISABLE:
mode_prop &= ~(AS3722_GPIO_MODE_PULL_UP |
AS3722_GPIO_MODE_PULL_DOWN);
break;
case PIN_CONFIG_BIAS_PULL_UP:
mode_prop |= AS3722_GPIO_MODE_PULL_UP;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
mode_prop |= AS3722_GPIO_MODE_PULL_DOWN;
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
mode_prop |= AS3722_GPIO_MODE_HIGH_IMPED;
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
mode_prop |= AS3722_GPIO_MODE_OPEN_DRAIN;
break;
default:
dev_err(as_pci->dev, "Properties not supported\n");
return -ENOTSUPP;
}
as_pci->gpio_control[pin].mode_prop = mode_prop;
}
return 0;
}
static inline struct as3722_pctrl_info *to_as_pci(struct gpio_chip *chip)
{
return container_of(chip, struct as3722_pctrl_info, gpio_chip);
}
static int as3722_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct as3722_pctrl_info *as_pci = to_as_pci(chip);
struct as3722 *as3722 = as_pci->as3722;
int ret;
u32 reg;
u32 control;
u32 val;
int mode;
int invert_enable;
ret = as3722_read(as3722, AS3722_GPIOn_CONTROL_REG(offset), &control);
if (ret < 0) {
dev_err(as_pci->dev,
"GPIO_CONTROL%d_REG read failed: %d\n", offset, ret);
return ret;
}
invert_enable = !!(control & AS3722_GPIO_INV);
mode = control & AS3722_GPIO_MODE_MASK;
switch (mode) {
case AS3722_GPIO_MODE_INPUT:
case AS3722_GPIO_MODE_INPUT_PULL_UP:
case AS3722_GPIO_MODE_INPUT_PULL_DOWN:
case AS3722_GPIO_MODE_IO_OPEN_DRAIN:
case AS3722_GPIO_MODE_IO_OPEN_DRAIN_PULL_UP:
reg = AS3722_GPIO_SIGNAL_IN_REG;
break;
case AS3722_GPIO_MODE_OUTPUT_VDDH:
case AS3722_GPIO_MODE_OUTPUT_VDDL:
reg = AS3722_GPIO_SIGNAL_OUT_REG;
break;
default:
return -EINVAL;
}
ret = as3722_read(as3722, reg, &val);
if (ret < 0) {
dev_err(as_pci->dev,
"GPIO_SIGNAL_IN_REG read failed: %d\n", ret);
return ret;
}
val = !!(val & AS3722_GPIOn_SIGNAL(offset));
return (invert_enable) ? !val : val;
}
static void as3722_gpio_set(struct gpio_chip *chip, unsigned offset,
int value)
{
struct as3722_pctrl_info *as_pci = to_as_pci(chip);
struct as3722 *as3722 = as_pci->as3722;
int en_invert = as_pci->gpio_control[offset].enable_gpio_invert;
u32 val;
int ret;
if (value)
val = (en_invert) ? 0 : AS3722_GPIOn_SIGNAL(offset);
else
val = (en_invert) ? AS3722_GPIOn_SIGNAL(offset) : 0;
ret = as3722_update_bits(as3722, AS3722_GPIO_SIGNAL_OUT_REG,
AS3722_GPIOn_SIGNAL(offset), val);
if (ret < 0)
dev_err(as_pci->dev,
"GPIO_SIGNAL_OUT_REG update failed: %d\n", ret);
}
static int as3722_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_gpio_direction_input(chip->base + offset);
}
static int as3722_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
as3722_gpio_set(chip, offset, value);
return pinctrl_gpio_direction_output(chip->base + offset);
}
static int as3722_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct as3722_pctrl_info *as_pci = to_as_pci(chip);
return as3722_irq_get_virq(as_pci->as3722, offset);
}
static int as3722_gpio_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(chip->base + offset);
}
static void as3722_gpio_free(struct gpio_chip *chip, unsigned offset)
{
pinctrl_free_gpio(chip->base + offset);
}
static int as3722_pinctrl_probe(struct platform_device *pdev)
{
struct as3722_pctrl_info *as_pci;
int ret;
int tret;
as_pci = devm_kzalloc(&pdev->dev, sizeof(*as_pci), GFP_KERNEL);
if (!as_pci)
return -ENOMEM;
as_pci->dev = &pdev->dev;
as_pci->dev->of_node = pdev->dev.parent->of_node;
as_pci->as3722 = dev_get_drvdata(pdev->dev.parent);
platform_set_drvdata(pdev, as_pci);
as_pci->pins = as3722_pins_desc;
as_pci->num_pins = ARRAY_SIZE(as3722_pins_desc);
as_pci->functions = as3722_pin_function;
as_pci->num_functions = ARRAY_SIZE(as3722_pin_function);
as_pci->pin_groups = as3722_pingroups;
as_pci->num_pin_groups = ARRAY_SIZE(as3722_pingroups);
as3722_pinctrl_desc.name = dev_name(&pdev->dev);
as3722_pinctrl_desc.pins = as3722_pins_desc;
as3722_pinctrl_desc.npins = ARRAY_SIZE(as3722_pins_desc);
as_pci->pctl = pinctrl_register(&as3722_pinctrl_desc,
&pdev->dev, as_pci);
if (!as_pci->pctl) {
dev_err(&pdev->dev, "Couldn't register pinctrl driver\n");
return -EINVAL;
}
as_pci->gpio_chip = as3722_gpio_chip;
as_pci->gpio_chip.dev = &pdev->dev;
as_pci->gpio_chip.of_node = pdev->dev.parent->of_node;
ret = gpiochip_add(&as_pci->gpio_chip);
if (ret < 0) {
dev_err(&pdev->dev, "Couldn't register gpiochip, %d\n", ret);
goto fail_chip_add;
}
ret = gpiochip_add_pin_range(&as_pci->gpio_chip, dev_name(&pdev->dev),
0, 0, AS3722_PIN_NUM);
if (ret < 0) {
dev_err(&pdev->dev, "Couldn't add pin range, %d\n", ret);
goto fail_range_add;
}
return 0;
fail_range_add:
tret = gpiochip_remove(&as_pci->gpio_chip);
if (tret < 0)
dev_warn(&pdev->dev, "Couldn't remove gpio chip, %d\n", tret);
fail_chip_add:
pinctrl_unregister(as_pci->pctl);
return ret;
}
static int as3722_pinctrl_remove(struct platform_device *pdev)
{
struct as3722_pctrl_info *as_pci = platform_get_drvdata(pdev);
int ret;
ret = gpiochip_remove(&as_pci->gpio_chip);
if (ret < 0)
return ret;
pinctrl_unregister(as_pci->pctl);
return 0;
}
