static int pm8xxx_read_bank(struct pm8xxx_gpio *pctrl,
struct pm8xxx_pin_data *pin, int bank)
{
unsigned int val = bank << 4;
int ret;
ret = regmap_write(pctrl->regmap, pin->reg, val);
if (ret) {
dev_err(pctrl->dev, "failed to select bank %d\n", bank);
return ret;
}
ret = regmap_read(pctrl->regmap, pin->reg, &val);
if (ret) {
dev_err(pctrl->dev, "failed to read register %d\n", bank);
return ret;
}
return val;
}
static int pm8xxx_write_bank(struct pm8xxx_gpio *pctrl,
struct pm8xxx_pin_data *pin,
int bank,
u8 val)
{
int ret;
val |= PM8XXX_BANK_WRITE;
val |= bank << 4;
ret = regmap_write(pctrl->regmap, pin->reg, val);
if (ret)
dev_err(pctrl->dev, "failed to write register\n");
return ret;
}
static int pm8xxx_get_groups_count(struct pinctrl_dev *pctldev)
{
struct pm8xxx_gpio *pctrl = pinctrl_dev_get_drvdata(pctldev);
return pctrl->npins;
}
static const char *pm8xxx_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
return pm8xxx_groups[group];
}
static int pm8xxx_get_group_pins(struct pinctrl_dev *pctldev,
unsigned group,
const unsigned **pins,
unsigned *num_pins)
{
struct pm8xxx_gpio *pctrl = pinctrl_dev_get_drvdata(pctldev);
*pins = &pctrl->desc.pins[group].number;
*num_pins = 1;
return 0;
}
static int pm8xxx_get_functions_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(pm8xxx_gpio_functions);
}
static const char *pm8xxx_get_function_name(struct pinctrl_dev *pctldev,
unsigned function)
{
return pm8xxx_gpio_functions[function];
}
static int pm8xxx_get_function_groups(struct pinctrl_dev *pctldev,
unsigned function,
const char * const **groups,
unsigned * const num_groups)
{
struct pm8xxx_gpio *pctrl = pinctrl_dev_get_drvdata(pctldev);
*groups = pm8xxx_groups;
*num_groups = pctrl->npins;
return 0;
}
static int pm8xxx_pinmux_set_mux(struct pinctrl_dev *pctldev,
unsigned function,
unsigned group)
{
struct pm8xxx_gpio *pctrl = pinctrl_dev_get_drvdata(pctldev);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[group].drv_data;
u8 val;
pin->function = function;
val = pin->function << 1;
pm8xxx_write_bank(pctrl, pin, 4, val);
return 0;
}
static int pm8xxx_pin_config_get(struct pinctrl_dev *pctldev,
unsigned int offset,
unsigned long *config)
{
struct pm8xxx_gpio *pctrl = pinctrl_dev_get_drvdata(pctldev);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
unsigned param = pinconf_to_config_param(*config);
unsigned arg;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
arg = pin->bias == PM8XXX_GPIO_BIAS_NP;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
arg = pin->bias == PM8XXX_GPIO_BIAS_PD;
break;
case PIN_CONFIG_BIAS_PULL_UP:
arg = pin->bias <= PM8XXX_GPIO_BIAS_PU_1P5_30;
break;
case PM8XXX_QCOM_PULL_UP_STRENGTH:
arg = pin->pull_up_strength;
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
arg = pin->disable;
break;
case PIN_CONFIG_INPUT_ENABLE:
arg = pin->mode == PM8XXX_GPIO_MODE_INPUT;
break;
case PIN_CONFIG_OUTPUT:
if (pin->mode & PM8XXX_GPIO_MODE_OUTPUT)
arg = pin->output_value;
else
arg = 0;
break;
case PIN_CONFIG_POWER_SOURCE:
arg = pin->power_source;
break;
case PM8XXX_QCOM_DRIVE_STRENGH:
arg = pin->output_strength;
break;
case PIN_CONFIG_DRIVE_PUSH_PULL:
arg = !pin->open_drain;
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
arg = pin->open_drain;
break;
default:
return -EINVAL;
}
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int pm8xxx_pin_config_set(struct pinctrl_dev *pctldev,
unsigned int offset,
unsigned long *configs,
unsigned num_configs)
{
struct pm8xxx_gpio *pctrl = pinctrl_dev_get_drvdata(pctldev);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
unsigned param;
unsigned arg;
unsigned i;
u8 banks = 0;
u8 val;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
pin->bias = PM8XXX_GPIO_BIAS_NP;
banks |= BIT(2);
pin->disable = 0;
banks |= BIT(3);
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
pin->bias = PM8XXX_GPIO_BIAS_PD;
banks |= BIT(2);
pin->disable = 0;
banks |= BIT(3);
break;
case PM8XXX_QCOM_PULL_UP_STRENGTH:
if (arg > PM8XXX_GPIO_BIAS_PU_1P5_30) {
dev_err(pctrl->dev, "invalid pull-up strength\n");
return -EINVAL;
}
pin->pull_up_strength = arg;
case PIN_CONFIG_BIAS_PULL_UP:
pin->bias = pin->pull_up_strength;
banks |= BIT(2);
pin->disable = 0;
banks |= BIT(3);
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
pin->disable = 1;
banks |= BIT(3);
break;
case PIN_CONFIG_INPUT_ENABLE:
pin->mode = PM8XXX_GPIO_MODE_INPUT;
banks |= BIT(0) | BIT(1);
break;
case PIN_CONFIG_OUTPUT:
pin->mode = PM8XXX_GPIO_MODE_OUTPUT;
pin->output_value = !!arg;
banks |= BIT(0) | BIT(1);
break;
case PIN_CONFIG_POWER_SOURCE:
pin->power_source = arg;
banks |= BIT(0);
break;
case PM8XXX_QCOM_DRIVE_STRENGH:
if (arg > PMIC_GPIO_STRENGTH_LOW) {
dev_err(pctrl->dev, "invalid drive strength\n");
return -EINVAL;
}
pin->output_strength = arg;
banks |= BIT(3);
break;
case PIN_CONFIG_DRIVE_PUSH_PULL:
pin->open_drain = 0;
banks |= BIT(1);
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
pin->open_drain = 1;
banks |= BIT(1);
break;
default:
dev_err(pctrl->dev,
"unsupported config parameter: %x\n",
param);
return -EINVAL;
}
}
if (banks & BIT(0)) {
val = pin->power_source << 1;
val |= PM8XXX_GPIO_MODE_ENABLED;
pm8xxx_write_bank(pctrl, pin, 0, val);
}
if (banks & BIT(1)) {
val = pin->mode << 2;
val |= pin->open_drain << 1;
val |= pin->output_value;
pm8xxx_write_bank(pctrl, pin, 1, val);
}
if (banks & BIT(2)) {
val = pin->bias << 1;
pm8xxx_write_bank(pctrl, pin, 2, val);
}
if (banks & BIT(3)) {
val = pin->output_strength << 2;
val |= pin->disable;
pm8xxx_write_bank(pctrl, pin, 3, val);
}
if (banks & BIT(4)) {
val = pin->function << 1;
pm8xxx_write_bank(pctrl, pin, 4, val);
}
if (banks & BIT(5)) {
val = 0;
if (!pin->inverted)
val |= BIT(3);
pm8xxx_write_bank(pctrl, pin, 5, val);
}
return 0;
}
static int pm8xxx_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
struct pm8xxx_gpio *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
u8 val;
pin->mode = PM8XXX_GPIO_MODE_INPUT;
val = pin->mode << 2;
pm8xxx_write_bank(pctrl, pin, 1, val);
return 0;
}
static int pm8xxx_gpio_direction_output(struct gpio_chip *chip,
unsigned offset,
int value)
{
struct pm8xxx_gpio *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
u8 val;
pin->mode = PM8XXX_GPIO_MODE_OUTPUT;
pin->output_value = !!value;
val = pin->mode << 2;
val |= pin->open_drain << 1;
val |= pin->output_value;
pm8xxx_write_bank(pctrl, pin, 1, val);
return 0;
}
static int pm8xxx_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct pm8xxx_gpio *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
bool state;
int ret;
if (pin->mode == PM8XXX_GPIO_MODE_OUTPUT) {
ret = pin->output_value;
} else {
ret = irq_get_irqchip_state(pin->irq, IRQCHIP_STATE_LINE_LEVEL, &state);
if (!ret)
ret = !!state;
}
return ret;
}
static void pm8xxx_gpio_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct pm8xxx_gpio *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
u8 val;
pin->output_value = !!value;
val = pin->mode << 2;
val |= pin->open_drain << 1;
val |= pin->output_value;
pm8xxx_write_bank(pctrl, pin, 1, val);
}
static int pm8xxx_gpio_of_xlate(struct gpio_chip *chip,
const struct of_phandle_args *gpio_desc,
u32 *flags)
{
if (chip->of_gpio_n_cells < 2)
return -EINVAL;
if (flags)
*flags = gpio_desc->args[1];
return gpio_desc->args[0] - 1;
}
static int pm8xxx_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct pm8xxx_gpio *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
return pin->irq;
}
static void pm8xxx_gpio_dbg_show_one(struct seq_file *s,
struct pinctrl_dev *pctldev,
struct gpio_chip *chip,
unsigned offset,
unsigned gpio)
{
struct pm8xxx_gpio *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
static const char * const modes[] = {
"in", "both", "out", "off"
};
static const char * const biases[] = {
"pull-up 30uA", "pull-up 1.5uA", "pull-up 31.5uA",
"pull-up 1.5uA + 30uA boost", "pull-down 10uA", "no pull"
};
static const char * const buffer_types[] = {
"push-pull", "open-drain"
};
static const char * const strengths[] = {
"no", "high", "medium", "low"
};
seq_printf(s, " gpio%-2d:", offset + 1);
if (pin->disable) {
seq_puts(s, " ---");
} else {
seq_printf(s, " %-4s", modes[pin->mode]);
seq_printf(s, " %-7s", pm8xxx_gpio_functions[pin->function]);
seq_printf(s, " VIN%d", pin->power_source);
seq_printf(s, " %-27s", biases[pin->bias]);
seq_printf(s, " %-10s", buffer_types[pin->open_drain]);
seq_printf(s, " %-4s", pin->output_value ? "high" : "low");
seq_printf(s, " %-7s", strengths[pin->output_strength]);
if (pin->inverted)
seq_puts(s, " inverted");
}
}
static void pm8xxx_gpio_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
unsigned gpio = chip->base;
unsigned i;
for (i = 0; i < chip->ngpio; i++, gpio++) {
pm8xxx_gpio_dbg_show_one(s, NULL, chip, i, gpio);
seq_puts(s, "\n");
}
}
static int pm8xxx_pin_populate(struct pm8xxx_gpio *pctrl,
struct pm8xxx_pin_data *pin)
{
int val;
val = pm8xxx_read_bank(pctrl, pin, 0);
if (val < 0)
return val;
pin->power_source = (val >> 1) & 0x7;
val = pm8xxx_read_bank(pctrl, pin, 1);
if (val < 0)
return val;
pin->mode = (val >> 2) & 0x3;
pin->open_drain = !!(val & BIT(1));
pin->output_value = val & BIT(0);
val = pm8xxx_read_bank(pctrl, pin, 2);
if (val < 0)
return val;
pin->bias = (val >> 1) & 0x7;
if (pin->bias <= PM8XXX_GPIO_BIAS_PU_1P5_30)
pin->pull_up_strength = pin->bias;
else
pin->pull_up_strength = PM8XXX_GPIO_BIAS_PU_30;
val = pm8xxx_read_bank(pctrl, pin, 3);
if (val < 0)
return val;
pin->output_strength = (val >> 2) & 0x3;
pin->disable = val & BIT(0);
val = pm8xxx_read_bank(pctrl, pin, 4);
if (val < 0)
return val;
pin->function = (val >> 1) & 0x7;
val = pm8xxx_read_bank(pctrl, pin, 5);
if (val < 0)
return val;
pin->inverted = !(val & BIT(3));
return 0;
}
static int pm8xxx_gpio_probe(struct platform_device *pdev)
{
struct pm8xxx_pin_data *pin_data;
struct pinctrl_pin_desc *pins;
struct pm8xxx_gpio *pctrl;
int ret;
int i, npins;
pctrl = devm_kzalloc(&pdev->dev, sizeof(*pctrl), GFP_KERNEL);
if (!pctrl)
return -ENOMEM;
pctrl->dev = &pdev->dev;
npins = platform_irq_count(pdev);
if (!npins)
return -EINVAL;
if (npins < 0)
return npins;
pctrl->npins = npins;
pctrl->regmap = dev_get_regmap(pdev->dev.parent, NULL);
if (!pctrl->regmap) {
dev_err(&pdev->dev, "parent regmap unavailable\n");
return -ENXIO;
}
pctrl->desc = pm8xxx_pinctrl_desc;
pctrl->desc.npins = pctrl->npins;
pins = devm_kcalloc(&pdev->dev,
pctrl->desc.npins,
sizeof(struct pinctrl_pin_desc),
GFP_KERNEL);
if (!pins)
return -ENOMEM;
pin_data = devm_kcalloc(&pdev->dev,
pctrl->desc.npins,
sizeof(struct pm8xxx_pin_data),
GFP_KERNEL);
if (!pin_data)
return -ENOMEM;
for (i = 0; i < pctrl->desc.npins; i++) {
pin_data[i].reg = SSBI_REG_ADDR_GPIO(i);
pin_data[i].irq = platform_get_irq(pdev, i);
if (pin_data[i].irq < 0) {
dev_err(&pdev->dev,
"missing interrupts for pin %d\n", i);
return pin_data[i].irq;
}
ret = pm8xxx_pin_populate(pctrl, &pin_data[i]);
if (ret)
return ret;
pins[i].number = i;
pins[i].name = pm8xxx_groups[i];
pins[i].drv_data = &pin_data[i];
}
pctrl->desc.pins = pins;
pctrl->desc.num_custom_params = ARRAY_SIZE(pm8xxx_gpio_bindings);
pctrl->desc.custom_params = pm8xxx_gpio_bindings;
#ifdef CONFIG_DEBUG_FS
pctrl->desc.custom_conf_items = pm8xxx_conf_items;
#endif
pctrl->pctrl = devm_pinctrl_register(&pdev->dev, &pctrl->desc, pctrl);
if (IS_ERR(pctrl->pctrl)) {
dev_err(&pdev->dev, "couldn't register pm8xxx gpio driver\n");
return PTR_ERR(pctrl->pctrl);
}
pctrl->chip = pm8xxx_gpio_template;
pctrl->chip.base = -1;
pctrl->chip.parent = &pdev->dev;
pctrl->chip.of_node = pdev->dev.of_node;
pctrl->chip.of_gpio_n_cells = 2;
pctrl->chip.label = dev_name(pctrl->dev);
pctrl->chip.ngpio = pctrl->npins;
ret = gpiochip_add_data(&pctrl->chip, pctrl);
if (ret) {
dev_err(&pdev->dev, "failed register gpiochip\n");
return ret;
}
ret = gpiochip_add_pin_range(&pctrl->chip,
dev_name(pctrl->dev),
0, 0, pctrl->chip.ngpio);
if (ret) {
dev_err(pctrl->dev, "failed to add pin range\n");
goto unregister_gpiochip;
}
platform_set_drvdata(pdev, pctrl);
dev_dbg(&pdev->dev, "Qualcomm pm8xxx gpio driver probed\n");
return 0;
unregister_gpiochip:
gpiochip_remove(&pctrl->chip);
return ret;
}
static int pm8xxx_gpio_remove(struct platform_device *pdev)
{
struct pm8xxx_gpio *pctrl = platform_get_drvdata(pdev);
gpiochip_remove(&pctrl->chip);
return 0;
}
