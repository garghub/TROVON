static int pm8xxx_mpp_update(struct pm8xxx_mpp *pctrl,
struct pm8xxx_pin_data *pin)
{
unsigned level;
unsigned ctrl;
unsigned type;
int ret;
u8 val;
switch (pin->mode) {
case PM8XXX_MPP_DIGITAL:
if (pin->dtest) {
type = PM8XXX_MPP_TYPE_DTEST_OUTPUT;
ctrl = pin->dtest - 1;
} else if (pin->input && pin->output) {
type = PM8XXX_MPP_TYPE_D_BI_DIR;
if (pin->high_z)
ctrl = PM8XXX_MPP_BI_PULLUP_OPEN;
else if (pin->pullup == 600)
ctrl = PM8XXX_MPP_BI_PULLUP_1KOHM;
else if (pin->pullup == 10000)
ctrl = PM8XXX_MPP_BI_PULLUP_10KOHM;
else
ctrl = PM8XXX_MPP_BI_PULLUP_30KOHM;
} else if (pin->input) {
type = PM8XXX_MPP_TYPE_D_INPUT;
if (pin->dtest)
ctrl = pin->dtest;
else
ctrl = PM8XXX_MPP_DIN_TO_INT;
} else {
type = PM8XXX_MPP_TYPE_D_OUTPUT;
ctrl = !!pin->output_value;
if (pin->paired)
ctrl |= BIT(1);
}
level = pin->power_source;
break;
case PM8XXX_MPP_ANALOG:
if (pin->output) {
type = PM8XXX_MPP_TYPE_A_OUTPUT;
level = pin->aout_level;
ctrl = pin->output_value;
if (pin->paired)
ctrl |= BIT(1);
} else {
type = PM8XXX_MPP_TYPE_A_INPUT;
level = pin->amux;
ctrl = 0;
}
break;
case PM8XXX_MPP_SINK:
level = (pin->drive_strength / 5) - 1;
if (pin->dtest) {
type = PM8XXX_MPP_TYPE_DTEST_SINK;
ctrl = pin->dtest - 1;
} else {
type = PM8XXX_MPP_TYPE_SINK;
ctrl = pin->output_value;
if (pin->paired)
ctrl |= BIT(1);
}
break;
default:
return -EINVAL;
}
val = type << 5 | level << 2 | ctrl;
ret = regmap_write(pctrl->regmap, pin->reg, val);
if (ret)
dev_err(pctrl->dev, "failed to write register\n");
return ret;
}
static int pm8xxx_get_groups_count(struct pinctrl_dev *pctldev)
{
struct pm8xxx_mpp *pctrl = pinctrl_dev_get_drvdata(pctldev);
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
struct pm8xxx_mpp *pctrl = pinctrl_dev_get_drvdata(pctldev);
*pins = &pctrl->desc.pins[group].number;
*num_pins = 1;
return 0;
}
static int pm8xxx_get_functions_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(pm8xxx_mpp_functions);
}
static const char *pm8xxx_get_function_name(struct pinctrl_dev *pctldev,
unsigned function)
{
return pm8xxx_mpp_functions[function];
}
static int pm8xxx_get_function_groups(struct pinctrl_dev *pctldev,
unsigned function,
const char * const **groups,
unsigned * const num_groups)
{
struct pm8xxx_mpp *pctrl = pinctrl_dev_get_drvdata(pctldev);
*groups = pm8xxx_groups;
*num_groups = pctrl->npins;
return 0;
}
static int pm8xxx_pinmux_set_mux(struct pinctrl_dev *pctldev,
unsigned function,
unsigned group)
{
struct pm8xxx_mpp *pctrl = pinctrl_dev_get_drvdata(pctldev);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[group].drv_data;
pin->mode = function;
pm8xxx_mpp_update(pctrl, pin);
return 0;
}
static int pm8xxx_pin_config_get(struct pinctrl_dev *pctldev,
unsigned int offset,
unsigned long *config)
{
struct pm8xxx_mpp *pctrl = pinctrl_dev_get_drvdata(pctldev);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
unsigned param = pinconf_to_config_param(*config);
unsigned arg;
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
arg = pin->pullup;
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
arg = pin->high_z;
break;
case PIN_CONFIG_INPUT_ENABLE:
arg = pin->input;
break;
case PIN_CONFIG_OUTPUT:
arg = pin->output_value;
break;
case PIN_CONFIG_POWER_SOURCE:
arg = pin->power_source;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
arg = pin->drive_strength;
break;
case PM8XXX_CONFIG_DTEST_SELECTOR:
arg = pin->dtest;
break;
case PM8XXX_CONFIG_AMUX:
arg = pin->amux;
break;
case PM8XXX_CONFIG_ALEVEL:
arg = pin->aout_level;
break;
case PM8XXX_CONFIG_PAIRED:
arg = pin->paired;
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
struct pm8xxx_mpp *pctrl = pinctrl_dev_get_drvdata(pctldev);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
unsigned param;
unsigned arg;
unsigned i;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_PULL_UP:
pin->pullup = arg;
break;
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
pin->high_z = true;
break;
case PIN_CONFIG_INPUT_ENABLE:
pin->input = true;
break;
case PIN_CONFIG_OUTPUT:
pin->output = true;
pin->output_value = !!arg;
break;
case PIN_CONFIG_POWER_SOURCE:
pin->power_source = arg;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
pin->drive_strength = arg;
break;
case PM8XXX_CONFIG_DTEST_SELECTOR:
pin->dtest = arg;
break;
case PM8XXX_CONFIG_AMUX:
pin->amux = arg;
break;
case PM8XXX_CONFIG_ALEVEL:
pin->aout_level = arg;
break;
case PM8XXX_CONFIG_PAIRED:
pin->paired = !!arg;
break;
default:
dev_err(pctrl->dev,
"unsupported config parameter: %x\n",
param);
return -EINVAL;
}
}
pm8xxx_mpp_update(pctrl, pin);
return 0;
}
static int pm8xxx_mpp_direction_input(struct gpio_chip *chip,
unsigned offset)
{
struct pm8xxx_mpp *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
switch (pin->mode) {
case PM8XXX_MPP_DIGITAL:
pin->input = true;
break;
case PM8XXX_MPP_ANALOG:
pin->input = true;
pin->output = true;
break;
case PM8XXX_MPP_SINK:
return -EINVAL;
}
pm8xxx_mpp_update(pctrl, pin);
return 0;
}
static int pm8xxx_mpp_direction_output(struct gpio_chip *chip,
unsigned offset,
int value)
{
struct pm8xxx_mpp *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
switch (pin->mode) {
case PM8XXX_MPP_DIGITAL:
pin->output = true;
break;
case PM8XXX_MPP_ANALOG:
pin->input = false;
pin->output = true;
break;
case PM8XXX_MPP_SINK:
pin->input = false;
pin->output = true;
break;
}
pm8xxx_mpp_update(pctrl, pin);
return 0;
}
static int pm8xxx_mpp_get(struct gpio_chip *chip, unsigned offset)
{
struct pm8xxx_mpp *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
bool state;
int ret;
if (!pin->input)
return !!pin->output_value;
ret = irq_get_irqchip_state(pin->irq, IRQCHIP_STATE_LINE_LEVEL, &state);
if (!ret)
ret = !!state;
return ret;
}
static void pm8xxx_mpp_set(struct gpio_chip *chip, unsigned offset, int value)
{
struct pm8xxx_mpp *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
pin->output_value = !!value;
pm8xxx_mpp_update(pctrl, pin);
}
static int pm8xxx_mpp_of_xlate(struct gpio_chip *chip,
const struct of_phandle_args *gpio_desc,
u32 *flags)
{
if (chip->of_gpio_n_cells < 2)
return -EINVAL;
if (flags)
*flags = gpio_desc->args[1];
return gpio_desc->args[0] - 1;
}
static int pm8xxx_mpp_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct pm8xxx_mpp *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
return pin->irq;
}
static void pm8xxx_mpp_dbg_show_one(struct seq_file *s,
struct pinctrl_dev *pctldev,
struct gpio_chip *chip,
unsigned offset,
unsigned gpio)
{
struct pm8xxx_mpp *pctrl = gpiochip_get_data(chip);
struct pm8xxx_pin_data *pin = pctrl->desc.pins[offset].drv_data;
static const char * const aout_lvls[] = {
"1v25", "1v25_2", "0v625", "0v3125", "mpp", "abus1", "abus2",
"abus3"
};
static const char * const amuxs[] = {
"amux5", "amux6", "amux7", "amux8", "amux9", "abus1", "abus2",
"abus3",
};
seq_printf(s, " mpp%-2d:", offset + 1);
switch (pin->mode) {
case PM8XXX_MPP_DIGITAL:
seq_puts(s, " digital ");
if (pin->dtest) {
seq_printf(s, "dtest%d\n", pin->dtest);
} else if (pin->input && pin->output) {
if (pin->high_z)
seq_puts(s, "bi-dir high-z");
else
seq_printf(s, "bi-dir %dOhm", pin->pullup);
} else if (pin->input) {
if (pin->dtest)
seq_printf(s, "in dtest%d", pin->dtest);
else
seq_puts(s, "in gpio");
} else if (pin->output) {
seq_puts(s, "out ");
if (!pin->paired) {
seq_puts(s, pin->output_value ?
"high" : "low");
} else {
seq_puts(s, pin->output_value ?
"inverted" : "follow");
}
}
break;
case PM8XXX_MPP_ANALOG:
seq_puts(s, " analog ");
if (pin->output) {
seq_printf(s, "out %s ", aout_lvls[pin->aout_level]);
if (!pin->paired) {
seq_puts(s, pin->output_value ?
"high" : "low");
} else {
seq_puts(s, pin->output_value ?
"inverted" : "follow");
}
} else {
seq_printf(s, "input mux %s", amuxs[pin->amux]);
}
break;
case PM8XXX_MPP_SINK:
seq_printf(s, " sink %dmA ", pin->drive_strength);
if (pin->dtest) {
seq_printf(s, "dtest%d", pin->dtest);
} else {
if (!pin->paired) {
seq_puts(s, pin->output_value ?
"high" : "low");
} else {
seq_puts(s, pin->output_value ?
"inverted" : "follow");
}
}
break;
}
}
static void pm8xxx_mpp_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
unsigned gpio = chip->base;
unsigned i;
for (i = 0; i < chip->ngpio; i++, gpio++) {
pm8xxx_mpp_dbg_show_one(s, NULL, chip, i, gpio);
seq_puts(s, "\n");
}
}
static int pm8xxx_pin_populate(struct pm8xxx_mpp *pctrl,
struct pm8xxx_pin_data *pin)
{
unsigned int val;
unsigned level;
unsigned ctrl;
unsigned type;
int ret;
ret = regmap_read(pctrl->regmap, pin->reg, &val);
if (ret) {
dev_err(pctrl->dev, "failed to read register\n");
return ret;
}
type = (val >> 5) & 7;
level = (val >> 2) & 7;
ctrl = (val) & 3;
switch (type) {
case PM8XXX_MPP_TYPE_D_INPUT:
pin->mode = PM8XXX_MPP_DIGITAL;
pin->input = true;
pin->power_source = level;
pin->dtest = ctrl;
break;
case PM8XXX_MPP_TYPE_D_OUTPUT:
pin->mode = PM8XXX_MPP_DIGITAL;
pin->output = true;
pin->power_source = level;
pin->output_value = !!(ctrl & BIT(0));
pin->paired = !!(ctrl & BIT(1));
break;
case PM8XXX_MPP_TYPE_D_BI_DIR:
pin->mode = PM8XXX_MPP_DIGITAL;
pin->input = true;
pin->output = true;
pin->power_source = level;
switch (ctrl) {
case PM8XXX_MPP_BI_PULLUP_1KOHM:
pin->pullup = 600;
break;
case PM8XXX_MPP_BI_PULLUP_OPEN:
pin->high_z = true;
break;
case PM8XXX_MPP_BI_PULLUP_10KOHM:
pin->pullup = 10000;
break;
case PM8XXX_MPP_BI_PULLUP_30KOHM:
pin->pullup = 30000;
break;
}
break;
case PM8XXX_MPP_TYPE_A_INPUT:
pin->mode = PM8XXX_MPP_ANALOG;
pin->input = true;
pin->amux = level;
break;
case PM8XXX_MPP_TYPE_A_OUTPUT:
pin->mode = PM8XXX_MPP_ANALOG;
pin->output = true;
pin->aout_level = level;
pin->output_value = !!(ctrl & BIT(0));
pin->paired = !!(ctrl & BIT(1));
break;
case PM8XXX_MPP_TYPE_SINK:
pin->mode = PM8XXX_MPP_SINK;
pin->drive_strength = 5 * (level + 1);
pin->output_value = !!(ctrl & BIT(0));
pin->paired = !!(ctrl & BIT(1));
break;
case PM8XXX_MPP_TYPE_DTEST_SINK:
pin->mode = PM8XXX_MPP_SINK;
pin->dtest = ctrl + 1;
pin->drive_strength = 5 * (level + 1);
break;
case PM8XXX_MPP_TYPE_DTEST_OUTPUT:
pin->mode = PM8XXX_MPP_DIGITAL;
pin->power_source = level;
if (ctrl >= 1)
pin->dtest = ctrl;
break;
}
return 0;
}
static int pm8xxx_mpp_probe(struct platform_device *pdev)
{
struct pm8xxx_pin_data *pin_data;
struct pinctrl_pin_desc *pins;
struct pm8xxx_mpp *pctrl;
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
pin_data[i].reg = SSBI_REG_ADDR_MPP(i);
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
pctrl->desc.num_custom_params = ARRAY_SIZE(pm8xxx_mpp_bindings);
pctrl->desc.custom_params = pm8xxx_mpp_bindings;
#ifdef CONFIG_DEBUG_FS
pctrl->desc.custom_conf_items = pm8xxx_conf_items;
#endif
pctrl->pctrl = pinctrl_register(&pctrl->desc, &pdev->dev, pctrl);
if (IS_ERR(pctrl->pctrl)) {
dev_err(&pdev->dev, "couldn't register pm8xxx mpp driver\n");
return PTR_ERR(pctrl->pctrl);
}
pctrl->chip = pm8xxx_mpp_template;
pctrl->chip.base = -1;
pctrl->chip.parent = &pdev->dev;
pctrl->chip.of_node = pdev->dev.of_node;
pctrl->chip.of_gpio_n_cells = 2;
pctrl->chip.label = dev_name(pctrl->dev);
pctrl->chip.ngpio = pctrl->npins;
ret = gpiochip_add_data(&pctrl->chip, pctrl);
if (ret) {
dev_err(&pdev->dev, "failed register gpiochip\n");
goto unregister_pinctrl;
}
ret = gpiochip_add_pin_range(&pctrl->chip,
dev_name(pctrl->dev),
0, 0, pctrl->chip.ngpio);
if (ret) {
dev_err(pctrl->dev, "failed to add pin range\n");
goto unregister_gpiochip;
}
platform_set_drvdata(pdev, pctrl);
dev_dbg(&pdev->dev, "Qualcomm pm8xxx mpp driver probed\n");
return 0;
unregister_gpiochip:
gpiochip_remove(&pctrl->chip);
unregister_pinctrl:
pinctrl_unregister(pctrl->pctrl);
return ret;
}
static int pm8xxx_mpp_remove(struct platform_device *pdev)
{
struct pm8xxx_mpp *pctrl = platform_get_drvdata(pdev);
gpiochip_remove(&pctrl->chip);
pinctrl_unregister(pctrl->pctrl);
return 0;
}
