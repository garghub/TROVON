static void __init tz1090_init_mux_pins(void)
{
unsigned int g, p;
const struct tz1090_pingroup *grp;
const unsigned int *pin;
for (p = 0; p < NUM_GPIOS; ++p)
tz1090_mux_pins[p] = TZ1090_MUX_GROUP_MAX;
grp = tz1090_mux_groups;
for (g = 0, grp = tz1090_mux_groups;
g < ARRAY_SIZE(tz1090_mux_groups); ++g, ++grp)
for (pin = grp->pins, p = 0; p < grp->npins; ++p, ++pin)
tz1090_mux_pins[*pin] = g;
}
static inline u32 pmx_read(struct tz1090_pmx *pmx, u32 reg)
{
return ioread32(pmx->regs + reg);
}
static inline void pmx_write(struct tz1090_pmx *pmx, u32 val, u32 reg)
{
iowrite32(val, pmx->regs + reg);
}
static int tz1090_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(tz1090_groups) + NUM_GPIOS;
}
static const char *tz1090_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
if (group < ARRAY_SIZE(tz1090_groups)) {
return tz1090_groups[group].name;
} else {
unsigned int pin = group - ARRAY_SIZE(tz1090_groups);
return tz1090_pins[pin].name;
}
}
static int tz1090_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int group,
const unsigned int **pins,
unsigned int *num_pins)
{
if (group < ARRAY_SIZE(tz1090_groups)) {
*pins = tz1090_groups[group].pins;
*num_pins = tz1090_groups[group].npins;
} else {
unsigned int pin = group - ARRAY_SIZE(tz1090_groups);
*pins = &tz1090_pins[pin].number;
*num_pins = 1;
}
return 0;
}
static void tz1090_pinctrl_pin_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s,
unsigned int offset)
{
seq_printf(s, " %s", dev_name(pctldev->dev));
}
static int reserve_map(struct device *dev, struct pinctrl_map **map,
unsigned int *reserved_maps, unsigned int *num_maps,
unsigned int reserve)
{
unsigned int old_num = *reserved_maps;
unsigned int new_num = *num_maps + reserve;
struct pinctrl_map *new_map;
if (old_num >= new_num)
return 0;
new_map = krealloc(*map, sizeof(*new_map) * new_num, GFP_KERNEL);
if (!new_map) {
dev_err(dev, "krealloc(map) failed\n");
return -ENOMEM;
}
memset(new_map + old_num, 0, (new_num - old_num) * sizeof(*new_map));
*map = new_map;
*reserved_maps = new_num;
return 0;
}
static int add_map_mux(struct pinctrl_map **map, unsigned int *reserved_maps,
unsigned int *num_maps, const char *group,
const char *function)
{
if (WARN_ON(*num_maps == *reserved_maps))
return -ENOSPC;
(*map)[*num_maps].type = PIN_MAP_TYPE_MUX_GROUP;
(*map)[*num_maps].data.mux.group = group;
(*map)[*num_maps].data.mux.function = function;
(*num_maps)++;
return 0;
}
static int add_map_configs(struct device *dev,
struct pinctrl_map **map,
unsigned int *reserved_maps, unsigned int *num_maps,
const char *group, unsigned long *configs,
unsigned int num_configs)
{
unsigned long *dup_configs;
if (WARN_ON(*num_maps == *reserved_maps))
return -ENOSPC;
dup_configs = kmemdup(configs, num_configs * sizeof(*dup_configs),
GFP_KERNEL);
if (!dup_configs) {
dev_err(dev, "kmemdup(configs) failed\n");
return -ENOMEM;
}
(*map)[*num_maps].type = PIN_MAP_TYPE_CONFIGS_GROUP;
(*map)[*num_maps].data.configs.group_or_pin = group;
(*map)[*num_maps].data.configs.configs = dup_configs;
(*map)[*num_maps].data.configs.num_configs = num_configs;
(*num_maps)++;
return 0;
}
static void tz1090_pinctrl_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map,
unsigned int num_maps)
{
int i;
for (i = 0; i < num_maps; i++)
if (map[i].type == PIN_MAP_TYPE_CONFIGS_GROUP)
kfree(map[i].data.configs.configs);
kfree(map);
}
static int tz1090_pinctrl_dt_subnode_to_map(struct device *dev,
struct device_node *np,
struct pinctrl_map **map,
unsigned int *reserved_maps,
unsigned int *num_maps)
{
int ret;
const char *function;
unsigned long *configs = NULL;
unsigned int num_configs = 0;
unsigned int reserve;
struct property *prop;
const char *group;
ret = of_property_read_string(np, "tz1090,function", &function);
if (ret < 0) {
if (ret != -EINVAL)
dev_err(dev, "could not parse property function\n");
function = NULL;
}
ret = pinconf_generic_parse_dt_config(np, NULL, &configs, &num_configs);
if (ret)
return ret;
reserve = 0;
if (function != NULL)
reserve++;
if (num_configs)
reserve++;
ret = of_property_count_strings(np, "tz1090,pins");
if (ret < 0) {
dev_err(dev, "could not parse property pins\n");
goto exit;
}
reserve *= ret;
ret = reserve_map(dev, map, reserved_maps, num_maps, reserve);
if (ret < 0)
goto exit;
of_property_for_each_string(np, "tz1090,pins", prop, group) {
if (function) {
ret = add_map_mux(map, reserved_maps, num_maps,
group, function);
if (ret < 0)
goto exit;
}
if (num_configs) {
ret = add_map_configs(dev, map, reserved_maps,
num_maps, group, configs,
num_configs);
if (ret < 0)
goto exit;
}
}
ret = 0;
exit:
kfree(configs);
return ret;
}
static int tz1090_pinctrl_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np_config,
struct pinctrl_map **map,
unsigned int *num_maps)
{
unsigned int reserved_maps;
struct device_node *np;
int ret;
reserved_maps = 0;
*map = NULL;
*num_maps = 0;
for_each_child_of_node(np_config, np) {
ret = tz1090_pinctrl_dt_subnode_to_map(pctldev->dev, np, map,
&reserved_maps,
num_maps);
if (ret < 0) {
tz1090_pinctrl_dt_free_map(pctldev, *map, *num_maps);
return ret;
}
}
return 0;
}
static int tz1090_pinctrl_get_funcs_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(tz1090_functions);
}
static const char *tz1090_pinctrl_get_func_name(struct pinctrl_dev *pctldev,
unsigned int function)
{
return tz1090_functions[function].name;
}
static int tz1090_pinctrl_get_func_groups(struct pinctrl_dev *pctldev,
unsigned int function,
const char * const **groups,
unsigned int * const num_groups)
{
*groups = tz1090_functions[function].groups;
*num_groups = tz1090_functions[function].ngroups;
return 0;
}
static void tz1090_pinctrl_select(struct tz1090_pmx *pmx,
unsigned int pin)
{
u32 reg, reg_shift, select, val;
unsigned int pmx_index, pmx_shift;
unsigned long flags;
pmx_index = pin >> 5;
pmx_shift = pin & 0x1f;
select = ((~pmx->pin_en[pmx_index] |
pmx->gpio_en[pmx_index]) >> pmx_shift) & 1;
reg = REG_PINCTRL_SELECT + 4*(pin / 30);
reg_shift = pin % 30;
__global_lock2(flags);
val = pmx_read(pmx, reg);
val &= ~BIT(reg_shift);
val |= select << reg_shift;
pmx_write(pmx, val, reg);
__global_unlock2(flags);
}
static void tz1090_pinctrl_gpio_select(struct tz1090_pmx *pmx,
unsigned int pin,
bool gpio_select)
{
unsigned int index, shift;
u32 gpio_en;
if (pin >= NUM_GPIOS)
return;
index = pin >> 5;
shift = pin & 0x1f;
spin_lock(&pmx->lock);
gpio_en = pmx->gpio_en[index];
gpio_en &= ~BIT(shift);
if (gpio_select)
gpio_en |= BIT(shift);
pmx->gpio_en[index] = gpio_en;
tz1090_pinctrl_select(pmx, pin);
spin_unlock(&pmx->lock);
}
static void tz1090_pinctrl_perip_select(struct tz1090_pmx *pmx,
unsigned int pin,
bool perip_select)
{
unsigned int index, shift;
u32 pin_en;
if (pin >= NUM_GPIOS)
return;
index = pin >> 5;
shift = pin & 0x1f;
spin_lock(&pmx->lock);
pin_en = pmx->pin_en[index];
pin_en &= ~BIT(shift);
if (perip_select)
pin_en |= BIT(shift);
pmx->pin_en[index] = pin_en;
tz1090_pinctrl_select(pmx, pin);
spin_unlock(&pmx->lock);
}
static int tz1090_pinctrl_enable_mux(struct tz1090_pmx *pmx,
const struct tz1090_muxdesc *desc,
unsigned int function)
{
const int *fit;
unsigned long flags;
int mux;
unsigned int func, ret;
u32 reg, mask;
for (mux = 0, fit = desc->funcs;
mux < ARRAY_SIZE(desc->funcs); ++mux, ++fit) {
func = *fit;
if (func == function)
goto found_mux;
if (func < ARRAY_SIZE(tz1090_submux) && tz1090_submux[func]) {
ret = tz1090_pinctrl_enable_mux(pmx,
tz1090_submux[func],
function);
if (!ret)
goto found_mux;
}
}
return -EINVAL;
found_mux:
if (desc->width) {
mask = (BIT(desc->width) - 1) << desc->bit;
__global_lock2(flags);
reg = pmx_read(pmx, desc->reg);
reg &= ~mask;
reg |= (mux << desc->bit) & mask;
pmx_write(pmx, reg, desc->reg);
__global_unlock2(flags);
}
return 0;
}
static int tz1090_pinctrl_set_mux(struct pinctrl_dev *pctldev,
unsigned int function, unsigned int group)
{
struct tz1090_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
struct tz1090_pingroup *grp;
int ret;
unsigned int pin_num, mux_group, i, npins;
const unsigned int *pins;
if (group < ARRAY_SIZE(tz1090_groups)) {
grp = &tz1090_groups[group];
npins = grp->npins;
pins = grp->pins;
} else {
pin_num = group - ARRAY_SIZE(tz1090_groups);
npins = 1;
pins = &pin_num;
}
mux_group = tz1090_mux_pins[*pins];
if (mux_group >= TZ1090_MUX_GROUP_MAX) {
if (function == TZ1090_MUX_PERIP)
goto mux_pins;
return -EINVAL;
}
grp = &tz1090_mux_groups[mux_group];
if (grp->func_count && grp->func != function) {
dev_err(pctldev->dev,
"%s: can't mux pin(s) to '%s', group already muxed to '%s'\n",
__func__, tz1090_functions[function].name,
tz1090_functions[grp->func].name);
return -EBUSY;
}
dev_dbg(pctldev->dev, "%s: muxing %u pin(s) in '%s' to '%s'\n",
__func__, npins, grp->name, tz1090_functions[function].name);
if (!grp->func_count) {
grp->func = function;
ret = tz1090_pinctrl_enable_mux(pmx, &grp->mux, function);
if (ret)
return ret;
}
grp->func_count += npins;
mux_pins:
for (i = 0; i < npins; ++i)
tz1090_pinctrl_perip_select(pmx, pins[i], true);
return 0;
}
static int tz1090_pinctrl_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int pin)
{
struct tz1090_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
tz1090_pinctrl_gpio_select(pmx, pin, true);
return 0;
}
static void tz1090_pinctrl_gpio_disable_free(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int pin)
{
struct tz1090_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
tz1090_pinctrl_gpio_select(pmx, pin, false);
}
static int tz1090_pinconf_reg(struct pinctrl_dev *pctldev,
unsigned int pin,
enum pin_config_param param,
bool report_err,
u32 *reg, u32 *width, u32 *mask, u32 *shift,
u32 *val)
{
struct tz1090_pinconf_pullup *pu;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_HIGH_IMPEDANCE:
*val = REG_PU_PD_TRISTATE;
break;
case PIN_CONFIG_BIAS_PULL_UP:
*val = REG_PU_PD_UP;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
*val = REG_PU_PD_DOWN;
break;
case PIN_CONFIG_BIAS_BUS_HOLD:
*val = REG_PU_PD_REPEATER;
break;
default:
return -ENOTSUPP;
}
pu = &tz1090_pinconf_pullup[pin];
*reg = REG_PINCTRL_PU_PD + 4*pu->index;
*shift = pu->shift;
*width = 2;
*mask = (BIT(*width) - 1) << *shift;
return 0;
}
static int tz1090_pinconf_get(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *config)
{
struct tz1090_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
int ret;
u32 reg, width, mask, shift, val, tmp, arg;
ret = tz1090_pinconf_reg(pctldev, pin, param, true,
&reg, &width, &mask, &shift, &val);
if (ret < 0)
return ret;
tmp = pmx_read(pmx, reg);
arg = ((tmp & mask) >> shift) == val;
if (!arg)
return -EINVAL;
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int tz1090_pinconf_set(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *configs,
unsigned num_configs)
{
struct tz1090_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
unsigned int arg;
int ret;
u32 reg, width, mask, shift, val, tmp;
unsigned long flags;
int i;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
dev_dbg(pctldev->dev, "%s(pin=%s, config=%#lx)\n",
__func__, tz1090_pins[pin].name, configs[i]);
ret = tz1090_pinconf_reg(pctldev, pin, param, true,
&reg, &width, &mask, &shift, &val);
if (ret < 0)
return ret;
if (arg > 1) {
dev_dbg(pctldev->dev, "%s: arg %u out of range\n",
__func__, arg);
return -EINVAL;
}
__global_lock2(flags);
tmp = pmx_read(pmx, reg);
tmp &= ~mask;
if (arg)
tmp |= val << shift;
pmx_write(pmx, tmp, reg);
__global_unlock2(flags);
}
return 0;
}
static int tz1090_pinconf_group_reg(struct pinctrl_dev *pctldev,
const struct tz1090_pingroup *g,
enum pin_config_param param,
bool report_err,
u32 *reg, u32 *width, u32 *mask, u32 *shift,
const int **map)
{
if (!g->drv) {
if (report_err)
dev_dbg(pctldev->dev,
"%s: group %s has no drive control\n",
__func__, g->name);
return -ENOTSUPP;
}
switch (param) {
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
*reg = REG_PINCTRL_SCHMITT;
*width = 1;
*map = tz1090_boolean_map;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
*reg = REG_PINCTRL_DR;
*width = 2;
*map = tz1090_dr_map;
break;
default:
return -ENOTSUPP;
}
*shift = g->slw_bit * *width;
*mask = (BIT(*width) - 1) << *shift;
return 0;
}
static int tz1090_pinconf_group_get(struct pinctrl_dev *pctldev,
unsigned int group,
unsigned long *config)
{
struct tz1090_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tz1090_pingroup *g;
enum pin_config_param param = pinconf_to_config_param(*config);
int ret, arg;
unsigned int pin;
u32 reg, width, mask, shift, val;
const int *map;
if (group >= ARRAY_SIZE(tz1090_groups)) {
pin = group - ARRAY_SIZE(tz1090_groups);
return tz1090_pinconf_get(pctldev, pin, config);
}
g = &tz1090_groups[group];
if (g->npins == 1) {
pin = g->pins[0];
ret = tz1090_pinconf_get(pctldev, pin, config);
if (ret != -ENOTSUPP)
return ret;
}
ret = tz1090_pinconf_group_reg(pctldev, g, param, true,
&reg, &width, &mask, &shift, &map);
if (ret < 0)
return ret;
val = pmx_read(pmx, reg);
arg = map[(val & mask) >> shift];
if (arg < 0)
return arg;
*config = pinconf_to_config_packed(param, arg);
return 0;
}
static int tz1090_pinconf_group_set(struct pinctrl_dev *pctldev,
unsigned int group, unsigned long *configs,
unsigned num_configs)
{
struct tz1090_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tz1090_pingroup *g;
enum pin_config_param param;
unsigned int arg, pin, i;
const unsigned int *pit;
int ret;
u32 reg, width, mask, shift, val;
unsigned long flags;
const int *map;
int j;
if (group >= ARRAY_SIZE(tz1090_groups)) {
pin = group - ARRAY_SIZE(tz1090_groups);
return tz1090_pinconf_set(pctldev, pin, configs, num_configs);
}
g = &tz1090_groups[group];
if (g->npins == 1) {
pin = g->pins[0];
ret = tz1090_pinconf_set(pctldev, pin, configs, num_configs);
if (ret != -ENOTSUPP)
return ret;
}
for (j = 0; j < num_configs; j++) {
param = pinconf_to_config_param(configs[j]);
dev_dbg(pctldev->dev, "%s(group=%s, config=%#lx)\n",
__func__, g->name, configs[j]);
ret = tz1090_pinconf_group_reg(pctldev, g, param, true, &reg,
&width, &mask, &shift, &map);
if (ret < 0) {
for (i = 0, pit = g->pins; i < g->npins; ++i, ++pit) {
ret = tz1090_pinconf_set(pctldev, *pit, configs,
num_configs);
if (ret)
return ret;
}
return 0;
}
arg = pinconf_to_config_argument(configs[j]);
for (i = 0; i < BIT(width); ++i) {
if (map[i] == arg || (map[i] == -EINVAL && !arg)) {
__global_lock2(flags);
val = pmx_read(pmx, reg);
val &= ~mask;
val |= i << shift;
pmx_write(pmx, val, reg);
__global_unlock2(flags);
goto next_config;
}
}
dev_dbg(pctldev->dev, "%s: arg %u not supported\n",
__func__, arg);
return -EINVAL;
next_config:
;
}
return 0;
}
static int tz1090_pinctrl_probe(struct platform_device *pdev)
{
struct tz1090_pmx *pmx;
struct resource *res;
pmx = devm_kzalloc(&pdev->dev, sizeof(*pmx), GFP_KERNEL);
if (!pmx) {
dev_err(&pdev->dev, "Can't alloc tz1090_pmx\n");
return -ENOMEM;
}
pmx->dev = &pdev->dev;
spin_lock_init(&pmx->lock);
tz1090_pinctrl_desc.name = dev_name(&pdev->dev);
tz1090_pinctrl_desc.pins = tz1090_pins;
tz1090_pinctrl_desc.npins = ARRAY_SIZE(tz1090_pins);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pmx->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pmx->regs))
return PTR_ERR(pmx->regs);
pmx->pctl = pinctrl_register(&tz1090_pinctrl_desc, &pdev->dev, pmx);
if (IS_ERR(pmx->pctl)) {
dev_err(&pdev->dev, "Couldn't register pinctrl driver\n");
return PTR_ERR(pmx->pctl);
}
platform_set_drvdata(pdev, pmx);
dev_info(&pdev->dev, "TZ1090 pinctrl driver initialised\n");
return 0;
}
static int tz1090_pinctrl_remove(struct platform_device *pdev)
{
struct tz1090_pmx *pmx = platform_get_drvdata(pdev);
pinctrl_unregister(pmx->pctl);
return 0;
}
static int __init tz1090_pinctrl_init(void)
{
tz1090_init_mux_pins();
return platform_driver_register(&tz1090_pinctrl_driver);
}
static void __exit tz1090_pinctrl_exit(void)
{
platform_driver_unregister(&tz1090_pinctrl_driver);
}
