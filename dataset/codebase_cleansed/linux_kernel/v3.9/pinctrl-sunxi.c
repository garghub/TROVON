static struct sunxi_pinctrl_group *
sunxi_pinctrl_find_group_by_name(struct sunxi_pinctrl *pctl, const char *group)
{
int i;
for (i = 0; i < pctl->ngroups; i++) {
struct sunxi_pinctrl_group *grp = pctl->groups + i;
if (!strcmp(grp->name, group))
return grp;
}
return NULL;
}
static struct sunxi_pinctrl_function *
sunxi_pinctrl_find_function_by_name(struct sunxi_pinctrl *pctl,
const char *name)
{
struct sunxi_pinctrl_function *func = pctl->functions;
int i;
for (i = 0; i < pctl->nfunctions; i++) {
if (!func[i].name)
break;
if (!strcmp(func[i].name, name))
return func + i;
}
return NULL;
}
static struct sunxi_desc_function *
sunxi_pinctrl_desc_find_function_by_name(struct sunxi_pinctrl *pctl,
const char *pin_name,
const char *func_name)
{
int i;
for (i = 0; i < pctl->desc->npins; i++) {
const struct sunxi_desc_pin *pin = pctl->desc->pins + i;
if (!strcmp(pin->pin.name, pin_name)) {
struct sunxi_desc_function *func = pin->functions;
while (func->name) {
if (!strcmp(func->name, func_name))
return func;
func++;
}
}
}
return NULL;
}
static int sunxi_pctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->ngroups;
}
static const char *sunxi_pctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->groups[group].name;
}
static int sunxi_pctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned group,
const unsigned **pins,
unsigned *num_pins)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
*pins = (unsigned *)&pctl->groups[group].pin;
*num_pins = 1;
return 0;
}
static int sunxi_pctrl_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *node,
struct pinctrl_map **map,
unsigned *num_maps)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
unsigned long *pinconfig;
struct property *prop;
const char *function;
const char *group;
int ret, nmaps, i = 0;
u32 val;
*map = NULL;
*num_maps = 0;
ret = of_property_read_string(node, "allwinner,function", &function);
if (ret) {
dev_err(pctl->dev,
"missing allwinner,function property in node %s\n",
node->name);
return -EINVAL;
}
nmaps = of_property_count_strings(node, "allwinner,pins") * 2;
if (nmaps < 0) {
dev_err(pctl->dev,
"missing allwinner,pins property in node %s\n",
node->name);
return -EINVAL;
}
*map = kmalloc(nmaps * sizeof(struct pinctrl_map), GFP_KERNEL);
if (!map)
return -ENOMEM;
of_property_for_each_string(node, "allwinner,pins", prop, group) {
struct sunxi_pinctrl_group *grp =
sunxi_pinctrl_find_group_by_name(pctl, group);
int j = 0, configlen = 0;
if (!grp) {
dev_err(pctl->dev, "unknown pin %s", group);
continue;
}
if (!sunxi_pinctrl_desc_find_function_by_name(pctl,
grp->name,
function)) {
dev_err(pctl->dev, "unsupported function %s on pin %s",
function, group);
continue;
}
(*map)[i].type = PIN_MAP_TYPE_MUX_GROUP;
(*map)[i].data.mux.group = group;
(*map)[i].data.mux.function = function;
i++;
(*map)[i].type = PIN_MAP_TYPE_CONFIGS_GROUP;
(*map)[i].data.configs.group_or_pin = group;
if (of_find_property(node, "allwinner,drive", NULL))
configlen++;
if (of_find_property(node, "allwinner,pull", NULL))
configlen++;
pinconfig = kzalloc(configlen * sizeof(*pinconfig), GFP_KERNEL);
if (!of_property_read_u32(node, "allwinner,drive", &val)) {
u16 strength = (val + 1) * 10;
pinconfig[j++] =
pinconf_to_config_packed(PIN_CONFIG_DRIVE_STRENGTH,
strength);
}
if (!of_property_read_u32(node, "allwinner,pull", &val)) {
enum pin_config_param pull = PIN_CONFIG_END;
if (val == 1)
pull = PIN_CONFIG_BIAS_PULL_UP;
else if (val == 2)
pull = PIN_CONFIG_BIAS_PULL_DOWN;
pinconfig[j++] = pinconf_to_config_packed(pull, 0);
}
(*map)[i].data.configs.configs = pinconfig;
(*map)[i].data.configs.num_configs = configlen;
i++;
}
*num_maps = nmaps;
return 0;
}
static void sunxi_pctrl_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map,
unsigned num_maps)
{
int i;
for (i = 0; i < num_maps; i++) {
if (map[i].type == PIN_MAP_TYPE_CONFIGS_GROUP)
kfree(map[i].data.configs.configs);
}
kfree(map);
}
static int sunxi_pconf_group_get(struct pinctrl_dev *pctldev,
unsigned group,
unsigned long *config)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
*config = pctl->groups[group].config;
return 0;
}
static int sunxi_pconf_group_set(struct pinctrl_dev *pctldev,
unsigned group,
unsigned long config)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct sunxi_pinctrl_group *g = &pctl->groups[group];
u32 val, mask;
u16 strength;
u8 dlevel;
switch (pinconf_to_config_param(config)) {
case PIN_CONFIG_DRIVE_STRENGTH:
strength = pinconf_to_config_argument(config);
if (strength > 40)
return -EINVAL;
dlevel = strength / 10 - 1;
val = readl(pctl->membase + sunxi_dlevel_reg(g->pin));
mask = DLEVEL_PINS_MASK << sunxi_dlevel_offset(g->pin);
writel((val & ~mask) | dlevel << sunxi_dlevel_offset(g->pin),
pctl->membase + sunxi_dlevel_reg(g->pin));
break;
case PIN_CONFIG_BIAS_PULL_UP:
val = readl(pctl->membase + sunxi_pull_reg(g->pin));
mask = PULL_PINS_MASK << sunxi_pull_offset(g->pin);
writel((val & ~mask) | 1 << sunxi_pull_offset(g->pin),
pctl->membase + sunxi_pull_reg(g->pin));
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
val = readl(pctl->membase + sunxi_pull_reg(g->pin));
mask = PULL_PINS_MASK << sunxi_pull_offset(g->pin);
writel((val & ~mask) | 2 << sunxi_pull_offset(g->pin),
pctl->membase + sunxi_pull_reg(g->pin));
break;
default:
break;
}
g->config = config;
return 0;
}
static int sunxi_pmx_get_funcs_cnt(struct pinctrl_dev *pctldev)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->nfunctions;
}
static const char *sunxi_pmx_get_func_name(struct pinctrl_dev *pctldev,
unsigned function)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
return pctl->functions[function].name;
}
static int sunxi_pmx_get_func_groups(struct pinctrl_dev *pctldev,
unsigned function,
const char * const **groups,
unsigned * const num_groups)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
*groups = pctl->functions[function].groups;
*num_groups = pctl->functions[function].ngroups;
return 0;
}
static void sunxi_pmx_set(struct pinctrl_dev *pctldev,
unsigned pin,
u8 config)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
u32 val = readl(pctl->membase + sunxi_mux_reg(pin));
u32 mask = MUX_PINS_MASK << sunxi_mux_offset(pin);
writel((val & ~mask) | config << sunxi_mux_offset(pin),
pctl->membase + sunxi_mux_reg(pin));
}
static int sunxi_pmx_enable(struct pinctrl_dev *pctldev,
unsigned function,
unsigned group)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct sunxi_pinctrl_group *g = pctl->groups + group;
struct sunxi_pinctrl_function *func = pctl->functions + function;
struct sunxi_desc_function *desc =
sunxi_pinctrl_desc_find_function_by_name(pctl,
g->name,
func->name);
if (!desc)
return -EINVAL;
sunxi_pmx_set(pctldev, g->pin, desc->muxval);
return 0;
}
static int
sunxi_pmx_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset,
bool input)
{
struct sunxi_pinctrl *pctl = pinctrl_dev_get_drvdata(pctldev);
struct sunxi_desc_function *desc;
char pin_name[SUNXI_PIN_NAME_MAX_LEN];
const char *func;
u8 bank, pin;
int ret;
bank = (offset) / PINS_PER_BANK;
pin = (offset) % PINS_PER_BANK;
ret = sprintf(pin_name, "P%c%d", 'A' + bank, pin);
if (!ret)
goto error;
if (input)
func = "gpio_in";
else
func = "gpio_out";
desc = sunxi_pinctrl_desc_find_function_by_name(pctl,
pin_name,
func);
if (!desc) {
ret = -EINVAL;
goto error;
}
sunxi_pmx_set(pctldev, offset, desc->muxval);
ret = 0;
error:
return ret;
}
static int sunxi_pinctrl_gpio_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(chip->base + offset);
}
static void sunxi_pinctrl_gpio_free(struct gpio_chip *chip, unsigned offset)
{
pinctrl_free_gpio(chip->base + offset);
}
static int sunxi_pinctrl_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
return pinctrl_gpio_direction_input(chip->base + offset);
}
static int sunxi_pinctrl_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct sunxi_pinctrl *pctl = dev_get_drvdata(chip->dev);
u32 reg = sunxi_data_reg(offset);
u8 index = sunxi_data_offset(offset);
u32 val = (readl(pctl->membase + reg) >> index) & DATA_PINS_MASK;
return val;
}
static int sunxi_pinctrl_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
return pinctrl_gpio_direction_output(chip->base + offset);
}
static void sunxi_pinctrl_gpio_set(struct gpio_chip *chip,
unsigned offset, int value)
{
struct sunxi_pinctrl *pctl = dev_get_drvdata(chip->dev);
u32 reg = sunxi_data_reg(offset);
u8 index = sunxi_data_offset(offset);
writel((value & DATA_PINS_MASK) << index, pctl->membase + reg);
}
static int sunxi_pinctrl_gpio_of_xlate(struct gpio_chip *gc,
const struct of_phandle_args *gpiospec,
u32 *flags)
{
int pin, base;
base = PINS_PER_BANK * gpiospec->args[0];
pin = base + gpiospec->args[1];
if (pin > (gc->base + gc->ngpio))
return -EINVAL;
if (flags)
*flags = gpiospec->args[2];
return pin;
}
static int sunxi_pinctrl_add_function(struct sunxi_pinctrl *pctl,
const char *name)
{
struct sunxi_pinctrl_function *func = pctl->functions;
while (func->name) {
if (strcmp(func->name, name) == 0) {
func->ngroups++;
return -EEXIST;
}
func++;
}
func->name = name;
func->ngroups = 1;
pctl->nfunctions++;
return 0;
}
static int sunxi_pinctrl_build_state(struct platform_device *pdev)
{
struct sunxi_pinctrl *pctl = platform_get_drvdata(pdev);
int i;
pctl->ngroups = pctl->desc->npins;
pctl->groups = devm_kzalloc(&pdev->dev,
pctl->ngroups * sizeof(*pctl->groups),
GFP_KERNEL);
if (!pctl->groups)
return -ENOMEM;
for (i = 0; i < pctl->desc->npins; i++) {
const struct sunxi_desc_pin *pin = pctl->desc->pins + i;
struct sunxi_pinctrl_group *group = pctl->groups + i;
group->name = pin->pin.name;
group->pin = pin->pin.number;
}
pctl->functions = devm_kzalloc(&pdev->dev,
pctl->desc->npins * sizeof(*pctl->functions),
GFP_KERNEL);
if (!pctl->functions)
return -ENOMEM;
for (i = 0; i < pctl->desc->npins; i++) {
const struct sunxi_desc_pin *pin = pctl->desc->pins + i;
struct sunxi_desc_function *func = pin->functions;
while (func->name) {
sunxi_pinctrl_add_function(pctl, func->name);
func++;
}
}
pctl->functions = krealloc(pctl->functions,
pctl->nfunctions * sizeof(*pctl->functions),
GFP_KERNEL);
for (i = 0; i < pctl->desc->npins; i++) {
const struct sunxi_desc_pin *pin = pctl->desc->pins + i;
struct sunxi_desc_function *func = pin->functions;
while (func->name) {
struct sunxi_pinctrl_function *func_item;
const char **func_grp;
func_item = sunxi_pinctrl_find_function_by_name(pctl,
func->name);
if (!func_item)
return -EINVAL;
if (!func_item->groups) {
func_item->groups =
devm_kzalloc(&pdev->dev,
func_item->ngroups * sizeof(*func_item->groups),
GFP_KERNEL);
if (!func_item->groups)
return -ENOMEM;
}
func_grp = func_item->groups;
while (*func_grp)
func_grp++;
*func_grp = pin->pin.name;
func++;
}
}
return 0;
}
static int sunxi_pinctrl_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
const struct of_device_id *device;
struct pinctrl_pin_desc *pins;
struct sunxi_pinctrl *pctl;
int i, ret, last_pin;
pctl = devm_kzalloc(&pdev->dev, sizeof(*pctl), GFP_KERNEL);
if (!pctl)
return -ENOMEM;
platform_set_drvdata(pdev, pctl);
pctl->membase = of_iomap(node, 0);
if (!pctl->membase)
return -ENOMEM;
device = of_match_device(sunxi_pinctrl_match, &pdev->dev);
if (!device)
return -ENODEV;
pctl->desc = (struct sunxi_pinctrl_desc *)device->data;
ret = sunxi_pinctrl_build_state(pdev);
if (ret) {
dev_err(&pdev->dev, "dt probe failed: %d\n", ret);
return ret;
}
pins = devm_kzalloc(&pdev->dev,
pctl->desc->npins * sizeof(*pins),
GFP_KERNEL);
if (!pins)
return -ENOMEM;
for (i = 0; i < pctl->desc->npins; i++)
pins[i] = pctl->desc->pins[i].pin;
sunxi_pctrl_desc.name = dev_name(&pdev->dev);
sunxi_pctrl_desc.owner = THIS_MODULE;
sunxi_pctrl_desc.pins = pins;
sunxi_pctrl_desc.npins = pctl->desc->npins;
pctl->dev = &pdev->dev;
pctl->pctl_dev = pinctrl_register(&sunxi_pctrl_desc,
&pdev->dev, pctl);
if (!pctl->pctl_dev) {
dev_err(&pdev->dev, "couldn't register pinctrl driver\n");
return -EINVAL;
}
pctl->chip = devm_kzalloc(&pdev->dev, sizeof(*pctl->chip), GFP_KERNEL);
if (!pctl->chip) {
ret = -ENOMEM;
goto pinctrl_error;
}
last_pin = pctl->desc->pins[pctl->desc->npins - 1].pin.number;
pctl->chip = &sunxi_pinctrl_gpio_chip;
pctl->chip->ngpio = round_up(last_pin, PINS_PER_BANK);
pctl->chip->label = dev_name(&pdev->dev);
pctl->chip->dev = &pdev->dev;
pctl->chip->base = 0;
ret = gpiochip_add(pctl->chip);
if (ret)
goto pinctrl_error;
for (i = 0; i < pctl->desc->npins; i++) {
const struct sunxi_desc_pin *pin = pctl->desc->pins + i;
ret = gpiochip_add_pin_range(pctl->chip, dev_name(&pdev->dev),
pin->pin.number,
pin->pin.number, 1);
if (ret)
goto gpiochip_error;
}
dev_info(&pdev->dev, "initialized sunXi PIO driver\n");
return 0;
gpiochip_error:
ret = gpiochip_remove(pctl->chip);
pinctrl_error:
pinctrl_unregister(pctl->pctl_dev);
return ret;
}
