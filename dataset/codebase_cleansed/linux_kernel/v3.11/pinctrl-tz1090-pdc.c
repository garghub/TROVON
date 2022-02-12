static inline u32 pmx_read(struct tz1090_pdc_pmx *pmx, u32 reg)
{
return ioread32(pmx->regs + reg);
}
static inline void pmx_write(struct tz1090_pdc_pmx *pmx, u32 val, u32 reg)
{
iowrite32(val, pmx->regs + reg);
}
static int tz1090_pdc_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(tz1090_pdc_groups);
}
static const char *tz1090_pdc_pinctrl_get_group_name(struct pinctrl_dev *pctl,
unsigned int group)
{
return tz1090_pdc_groups[group].name;
}
static int tz1090_pdc_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int group,
const unsigned int **pins,
unsigned int *num_pins)
{
*pins = tz1090_pdc_groups[group].pins;
*num_pins = tz1090_pdc_groups[group].npins;
return 0;
}
static void tz1090_pdc_pinctrl_pin_dbg_show(struct pinctrl_dev *pctldev,
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
static int get_group_selector(const char *pin_group)
{
unsigned int group;
for (group = 0; group < ARRAY_SIZE(tz1090_pdc_groups); ++group)
if (!strcmp(tz1090_pdc_groups[group].name, pin_group))
return group;
return -EINVAL;
}
static int add_map_configs(struct device *dev,
struct pinctrl_map **map,
unsigned int *reserved_maps, unsigned int *num_maps,
const char *group, unsigned long *configs,
unsigned int num_configs)
{
unsigned long *dup_configs;
enum pinctrl_map_type type;
if (WARN_ON(*num_maps == *reserved_maps))
return -ENOSPC;
dup_configs = kmemdup(configs, num_configs * sizeof(*dup_configs),
GFP_KERNEL);
if (!dup_configs) {
dev_err(dev, "kmemdup(configs) failed\n");
return -ENOMEM;
}
if (get_group_selector(group) >= 0)
type = PIN_MAP_TYPE_CONFIGS_GROUP;
else
type = PIN_MAP_TYPE_CONFIGS_PIN;
(*map)[*num_maps].type = type;
(*map)[*num_maps].data.configs.group_or_pin = group;
(*map)[*num_maps].data.configs.configs = dup_configs;
(*map)[*num_maps].data.configs.num_configs = num_configs;
(*num_maps)++;
return 0;
}
static void tz1090_pdc_pinctrl_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map,
unsigned int num_maps)
{
int i;
for (i = 0; i < num_maps; i++)
if (map[i].type == PIN_MAP_TYPE_CONFIGS_GROUP)
kfree(map[i].data.configs.configs);
kfree(map);
}
static int tz1090_pdc_pinctrl_dt_subnode_to_map(struct device *dev,
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
dev_err(dev,
"could not parse property function\n");
function = NULL;
}
ret = pinconf_generic_parse_dt_config(np, &configs, &num_configs);
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
static int tz1090_pdc_pinctrl_dt_node_to_map(struct pinctrl_dev *pctldev,
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
ret = tz1090_pdc_pinctrl_dt_subnode_to_map(pctldev->dev, np,
map, &reserved_maps,
num_maps);
if (ret < 0) {
tz1090_pdc_pinctrl_dt_free_map(pctldev, *map,
*num_maps);
return ret;
}
}
return 0;
}
static int tz1090_pdc_pinctrl_get_funcs_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(tz1090_pdc_functions);
}
static const char *tz1090_pdc_pinctrl_get_func_name(struct pinctrl_dev *pctldev,
unsigned int function)
{
return tz1090_pdc_functions[function].name;
}
static int tz1090_pdc_pinctrl_get_func_groups(struct pinctrl_dev *pctldev,
unsigned int function,
const char * const **groups,
unsigned int * const num_groups)
{
*groups = tz1090_pdc_functions[function].groups;
*num_groups = tz1090_pdc_functions[function].ngroups;
return 0;
}
static void tz1090_pdc_pinctrl_mux(struct tz1090_pdc_pmx *pmx,
const struct tz1090_pdc_pingroup *grp)
{
u32 reg, select;
unsigned int pin_shift = grp->pins[0];
unsigned long flags;
select = ((pmx->mux_en & ~pmx->gpio_en) >> pin_shift) & 1;
__global_lock2(flags);
reg = pmx_read(pmx, grp->reg);
reg &= ~BIT(grp->bit);
reg |= select << grp->bit;
pmx_write(pmx, reg, grp->reg);
__global_unlock2(flags);
}
static int tz1090_pdc_pinctrl_enable(struct pinctrl_dev *pctldev,
unsigned int function, unsigned int group)
{
struct tz1090_pdc_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tz1090_pdc_pingroup *grp = &tz1090_pdc_groups[group];
dev_dbg(pctldev->dev, "%s(func=%u (%s), group=%u (%s))\n",
__func__,
function, tz1090_pdc_functions[function].name,
group, tz1090_pdc_groups[group].name);
if (grp->drv)
return -EINVAL;
if (function != grp->func)
return -EINVAL;
spin_lock(&pmx->lock);
pmx->mux_en |= BIT(grp->pins[0]);
tz1090_pdc_pinctrl_mux(pmx, grp);
spin_unlock(&pmx->lock);
return 0;
}
static void tz1090_pdc_pinctrl_disable(struct pinctrl_dev *pctldev,
unsigned int function,
unsigned int group)
{
struct tz1090_pdc_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tz1090_pdc_pingroup *grp = &tz1090_pdc_groups[group];
dev_dbg(pctldev->dev, "%s(func=%u (%s), group=%u (%s))\n",
__func__,
function, tz1090_pdc_functions[function].name,
group, tz1090_pdc_groups[group].name);
if (grp->drv)
return;
if (function != grp->func)
return;
spin_lock(&pmx->lock);
pmx->mux_en &= ~BIT(grp->pins[0]);
tz1090_pdc_pinctrl_mux(pmx, grp);
spin_unlock(&pmx->lock);
}
static const struct tz1090_pdc_pingroup *find_mux_group(
struct tz1090_pdc_pmx *pmx,
unsigned int pin)
{
const struct tz1090_pdc_pingroup *grp;
unsigned int group;
grp = tz1090_pdc_groups;
for (group = 0; group < ARRAY_SIZE(tz1090_pdc_groups); ++group, ++grp) {
if (grp->drv)
continue;
if (grp->pins[0] == pin)
return grp;
}
return NULL;
}
static int tz1090_pdc_pinctrl_gpio_request_enable(
struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int pin)
{
struct tz1090_pdc_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tz1090_pdc_pingroup *grp = find_mux_group(pmx, pin);
if (grp) {
spin_lock(&pmx->lock);
pmx->gpio_en |= BIT(pin);
tz1090_pdc_pinctrl_mux(pmx, grp);
spin_unlock(&pmx->lock);
}
return 0;
}
static void tz1090_pdc_pinctrl_gpio_disable_free(
struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int pin)
{
struct tz1090_pdc_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tz1090_pdc_pingroup *grp = find_mux_group(pmx, pin);
if (grp) {
spin_lock(&pmx->lock);
pmx->gpio_en &= ~BIT(pin);
tz1090_pdc_pinctrl_mux(pmx, grp);
spin_unlock(&pmx->lock);
}
}
static int tz1090_pdc_pinconf_reg(struct pinctrl_dev *pctldev,
unsigned int pin,
enum pin_config_param param,
bool report_err,
u32 *reg, u32 *width, u32 *mask, u32 *shift,
u32 *val)
{
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
};
*reg = REG_GPIO_CONTROL2;
*shift = REG_GPIO_CONTROL2_PU_PD_S + pin*2;
*width = 2;
*mask = (BIT(*width) - 1) << *shift;
return 0;
}
static int tz1090_pdc_pinconf_get(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long *config)
{
struct tz1090_pdc_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
int ret;
u32 reg, width, mask, shift, val, tmp, arg;
ret = tz1090_pdc_pinconf_reg(pctldev, pin, param, true,
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
static int tz1090_pdc_pinconf_set(struct pinctrl_dev *pctldev,
unsigned int pin, unsigned long config)
{
struct tz1090_pdc_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(config);
unsigned int arg = pinconf_to_config_argument(config);
int ret;
u32 reg, width, mask, shift, val, tmp;
unsigned long flags;
dev_dbg(pctldev->dev, "%s(pin=%s, config=%#lx)\n",
__func__, tz1090_pdc_pins[pin].name, config);
ret = tz1090_pdc_pinconf_reg(pctldev, pin, param, true,
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
return 0;
}
static int tz1090_pdc_pinconf_group_reg(struct pinctrl_dev *pctldev,
const struct tz1090_pdc_pingroup *g,
enum pin_config_param param,
bool report_err, u32 *reg, u32 *width,
u32 *mask, u32 *shift, const int **map)
{
if (!g->drv) {
if (report_err)
dev_dbg(pctldev->dev,
"%s: group %s has no drive control\n",
__func__, g->name);
return -ENOTSUPP;
}
*reg = REG_GPIO_CONTROL2;
switch (param) {
case PIN_CONFIG_INPUT_SCHMITT_ENABLE:
*shift = REG_GPIO_CONTROL2_PDC_SCHMITT_S;
*width = 1;
*map = tz1090_pdc_boolean_map;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
*shift = REG_GPIO_CONTROL2_PDC_DR_S;
*width = 2;
*map = tz1090_pdc_dr_map;
break;
case PIN_CONFIG_LOW_POWER_MODE:
*shift = REG_GPIO_CONTROL2_PDC_POS_S;
*width = 1;
*map = tz1090_pdc_boolean_map;
break;
default:
return -ENOTSUPP;
};
*mask = (BIT(*width) - 1) << *shift;
return 0;
}
static int tz1090_pdc_pinconf_group_get(struct pinctrl_dev *pctldev,
unsigned int group,
unsigned long *config)
{
struct tz1090_pdc_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tz1090_pdc_pingroup *g = &tz1090_pdc_groups[group];
enum pin_config_param param = pinconf_to_config_param(*config);
int ret, arg;
u32 reg, width, mask, shift, val;
const int *map;
ret = tz1090_pdc_pinconf_group_reg(pctldev, g, param, true,
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
static int tz1090_pdc_pinconf_group_set(struct pinctrl_dev *pctldev,
unsigned int group,
unsigned long config)
{
struct tz1090_pdc_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tz1090_pdc_pingroup *g = &tz1090_pdc_groups[group];
enum pin_config_param param = pinconf_to_config_param(config);
const unsigned int *pit;
unsigned int i;
int ret, arg;
u32 reg, width, mask, shift, val;
unsigned long flags;
const int *map;
dev_dbg(pctldev->dev, "%s(group=%s, config=%#lx)\n",
__func__, g->name, config);
ret = tz1090_pdc_pinconf_group_reg(pctldev, g, param, true,
&reg, &width, &mask, &shift, &map);
if (ret < 0) {
for (i = 0, pit = g->pins; i < g->npins; ++i, ++pit) {
ret = tz1090_pdc_pinconf_set(pctldev, *pit, config);
if (ret)
return ret;
}
return 0;
}
arg = pinconf_to_config_argument(config);
for (i = 0; i < BIT(width); ++i) {
if (map[i] == arg || (map[i] == -EINVAL && !arg)) {
__global_lock2(flags);
val = pmx_read(pmx, reg);
val &= ~mask;
val |= i << shift;
pmx_write(pmx, val, reg);
__global_unlock2(flags);
return 0;
}
}
dev_dbg(pctldev->dev, "%s: arg %u not supported\n",
__func__, arg);
return 0;
}
static int tz1090_pdc_pinctrl_probe(struct platform_device *pdev)
{
struct tz1090_pdc_pmx *pmx;
struct resource *res;
pmx = devm_kzalloc(&pdev->dev, sizeof(*pmx), GFP_KERNEL);
if (!pmx) {
dev_err(&pdev->dev, "Can't alloc tz1090_pdc_pmx\n");
return -ENOMEM;
}
pmx->dev = &pdev->dev;
spin_lock_init(&pmx->lock);
tz1090_pdc_pinctrl_desc.name = dev_name(&pdev->dev);
tz1090_pdc_pinctrl_desc.pins = tz1090_pdc_pins;
tz1090_pdc_pinctrl_desc.npins = ARRAY_SIZE(tz1090_pdc_pins);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "Missing MEM resource\n");
return -ENODEV;
}
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res),
dev_name(&pdev->dev))) {
dev_err(&pdev->dev,
"Couldn't request MEM resource\n");
return -ENODEV;
}
pmx->regs = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!pmx->regs) {
dev_err(&pdev->dev, "Couldn't ioremap regs\n");
return -ENODEV;
}
pmx->pctl = pinctrl_register(&tz1090_pdc_pinctrl_desc, &pdev->dev, pmx);
if (!pmx->pctl) {
dev_err(&pdev->dev, "Couldn't register pinctrl driver\n");
return -ENODEV;
}
platform_set_drvdata(pdev, pmx);
dev_info(&pdev->dev, "TZ1090 PDC pinctrl driver initialised\n");
return 0;
}
static int tz1090_pdc_pinctrl_remove(struct platform_device *pdev)
{
struct tz1090_pdc_pmx *pmx = platform_get_drvdata(pdev);
pinctrl_unregister(pmx->pctl);
return 0;
}
static int __init tz1090_pdc_pinctrl_init(void)
{
return platform_driver_register(&tz1090_pdc_pinctrl_driver);
}
static void __exit tz1090_pdc_pinctrl_exit(void)
{
platform_driver_unregister(&tz1090_pdc_pinctrl_driver);
}
