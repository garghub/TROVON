static inline u32 pmx_readl(struct tegra_pmx *pmx, u32 bank, u32 reg)
{
return readl(pmx->regs[bank] + reg);
}
static inline void pmx_writel(struct tegra_pmx *pmx, u32 val, u32 bank, u32 reg)
{
writel(val, pmx->regs[bank] + reg);
}
static int tegra_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->soc->ngroups;
}
static const char *tegra_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->soc->groups[group].name;
}
static int tegra_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned group,
const unsigned **pins,
unsigned *num_pins)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
*pins = pmx->soc->groups[group].pins;
*num_pins = pmx->soc->groups[group].npins;
return 0;
}
static void tegra_pinctrl_pin_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s,
unsigned offset)
{
seq_printf(s, " %s", dev_name(pctldev->dev));
}
static int reserve_map(struct device *dev, struct pinctrl_map **map,
unsigned *reserved_maps, unsigned *num_maps,
unsigned reserve)
{
unsigned old_num = *reserved_maps;
unsigned new_num = *num_maps + reserve;
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
static int add_map_mux(struct pinctrl_map **map, unsigned *reserved_maps,
unsigned *num_maps, const char *group,
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
static int add_map_configs(struct device *dev, struct pinctrl_map **map,
unsigned *reserved_maps, unsigned *num_maps,
const char *group, unsigned long *configs,
unsigned num_configs)
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
static int add_config(struct device *dev, unsigned long **configs,
unsigned *num_configs, unsigned long config)
{
unsigned old_num = *num_configs;
unsigned new_num = old_num + 1;
unsigned long *new_configs;
new_configs = krealloc(*configs, sizeof(*new_configs) * new_num,
GFP_KERNEL);
if (!new_configs) {
dev_err(dev, "krealloc(configs) failed\n");
return -ENOMEM;
}
new_configs[old_num] = config;
*configs = new_configs;
*num_configs = new_num;
return 0;
}
void tegra_pinctrl_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map, unsigned num_maps)
{
int i;
for (i = 0; i < num_maps; i++)
if (map[i].type == PIN_MAP_TYPE_CONFIGS_GROUP)
kfree(map[i].data.configs.configs);
kfree(map);
}
int tegra_pinctrl_dt_subnode_to_map(struct device *dev,
struct device_node *np,
struct pinctrl_map **map,
unsigned *reserved_maps,
unsigned *num_maps)
{
int ret, i;
const char *function;
u32 val;
unsigned long config;
unsigned long *configs = NULL;
unsigned num_configs = 0;
unsigned reserve;
struct property *prop;
const char *group;
ret = of_property_read_string(np, "nvidia,function", &function);
if (ret < 0) {
if (ret != -EINVAL)
dev_err(dev,
"could not parse property nvidia,function\n");
function = NULL;
}
for (i = 0; i < ARRAY_SIZE(cfg_params); i++) {
ret = of_property_read_u32(np, cfg_params[i].property, &val);
if (!ret) {
config = TEGRA_PINCONF_PACK(cfg_params[i].param, val);
ret = add_config(dev, &configs, &num_configs, config);
if (ret < 0)
goto exit;
} else if (ret != -EINVAL) {
dev_err(dev, "could not parse property %s\n",
cfg_params[i].property);
}
}
reserve = 0;
if (function != NULL)
reserve++;
if (num_configs)
reserve++;
ret = of_property_count_strings(np, "nvidia,pins");
if (ret < 0) {
dev_err(dev, "could not parse property nvidia,pins\n");
goto exit;
}
reserve *= ret;
ret = reserve_map(dev, map, reserved_maps, num_maps, reserve);
if (ret < 0)
goto exit;
of_property_for_each_string(np, "nvidia,pins", prop, group) {
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
int tegra_pinctrl_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np_config,
struct pinctrl_map **map, unsigned *num_maps)
{
unsigned reserved_maps;
struct device_node *np;
int ret;
reserved_maps = 0;
*map = NULL;
*num_maps = 0;
for_each_child_of_node(np_config, np) {
ret = tegra_pinctrl_dt_subnode_to_map(pctldev->dev, np, map,
&reserved_maps, num_maps);
if (ret < 0) {
tegra_pinctrl_dt_free_map(pctldev, *map, *num_maps);
return ret;
}
}
return 0;
}
static int tegra_pinctrl_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->soc->nfunctions;
}
static const char *tegra_pinctrl_get_func_name(struct pinctrl_dev *pctldev,
unsigned function)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
return pmx->soc->functions[function].name;
}
static int tegra_pinctrl_get_func_groups(struct pinctrl_dev *pctldev,
unsigned function,
const char * const **groups,
unsigned * const num_groups)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
*groups = pmx->soc->functions[function].groups;
*num_groups = pmx->soc->functions[function].ngroups;
return 0;
}
static int tegra_pinctrl_enable(struct pinctrl_dev *pctldev, unsigned function,
unsigned group)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tegra_pingroup *g;
int i;
u32 val;
g = &pmx->soc->groups[group];
if (WARN_ON(g->mux_reg < 0))
return -EINVAL;
for (i = 0; i < ARRAY_SIZE(g->funcs); i++) {
if (g->funcs[i] == function)
break;
}
if (WARN_ON(i == ARRAY_SIZE(g->funcs)))
return -EINVAL;
val = pmx_readl(pmx, g->mux_bank, g->mux_reg);
val &= ~(0x3 << g->mux_bit);
val |= i << g->mux_bit;
pmx_writel(pmx, val, g->mux_bank, g->mux_reg);
return 0;
}
static void tegra_pinctrl_disable(struct pinctrl_dev *pctldev,
unsigned function, unsigned group)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tegra_pingroup *g;
u32 val;
g = &pmx->soc->groups[group];
if (WARN_ON(g->mux_reg < 0))
return;
val = pmx_readl(pmx, g->mux_bank, g->mux_reg);
val &= ~(0x3 << g->mux_bit);
val |= g->func_safe << g->mux_bit;
pmx_writel(pmx, val, g->mux_bank, g->mux_reg);
}
static int tegra_pinconf_reg(struct tegra_pmx *pmx,
const struct tegra_pingroup *g,
enum tegra_pinconf_param param,
bool report_err,
s8 *bank, s16 *reg, s8 *bit, s8 *width)
{
switch (param) {
case TEGRA_PINCONF_PARAM_PULL:
*bank = g->pupd_bank;
*reg = g->pupd_reg;
*bit = g->pupd_bit;
*width = 2;
break;
case TEGRA_PINCONF_PARAM_TRISTATE:
*bank = g->tri_bank;
*reg = g->tri_reg;
*bit = g->tri_bit;
*width = 1;
break;
case TEGRA_PINCONF_PARAM_ENABLE_INPUT:
*bank = g->einput_bank;
*reg = g->einput_reg;
*bit = g->einput_bit;
*width = 1;
break;
case TEGRA_PINCONF_PARAM_OPEN_DRAIN:
*bank = g->odrain_bank;
*reg = g->odrain_reg;
*bit = g->odrain_bit;
*width = 1;
break;
case TEGRA_PINCONF_PARAM_LOCK:
*bank = g->lock_bank;
*reg = g->lock_reg;
*bit = g->lock_bit;
*width = 1;
break;
case TEGRA_PINCONF_PARAM_IORESET:
*bank = g->ioreset_bank;
*reg = g->ioreset_reg;
*bit = g->ioreset_bit;
*width = 1;
break;
case TEGRA_PINCONF_PARAM_HIGH_SPEED_MODE:
*bank = g->drv_bank;
*reg = g->drv_reg;
*bit = g->hsm_bit;
*width = 1;
break;
case TEGRA_PINCONF_PARAM_SCHMITT:
*bank = g->drv_bank;
*reg = g->drv_reg;
*bit = g->schmitt_bit;
*width = 1;
break;
case TEGRA_PINCONF_PARAM_LOW_POWER_MODE:
*bank = g->drv_bank;
*reg = g->drv_reg;
*bit = g->lpmd_bit;
*width = 1;
break;
case TEGRA_PINCONF_PARAM_DRIVE_DOWN_STRENGTH:
*bank = g->drv_bank;
*reg = g->drv_reg;
*bit = g->drvdn_bit;
*width = g->drvdn_width;
break;
case TEGRA_PINCONF_PARAM_DRIVE_UP_STRENGTH:
*bank = g->drv_bank;
*reg = g->drv_reg;
*bit = g->drvup_bit;
*width = g->drvup_width;
break;
case TEGRA_PINCONF_PARAM_SLEW_RATE_FALLING:
*bank = g->drv_bank;
*reg = g->drv_reg;
*bit = g->slwf_bit;
*width = g->slwf_width;
break;
case TEGRA_PINCONF_PARAM_SLEW_RATE_RISING:
*bank = g->drv_bank;
*reg = g->drv_reg;
*bit = g->slwr_bit;
*width = g->slwr_width;
break;
default:
dev_err(pmx->dev, "Invalid config param %04x\n", param);
return -ENOTSUPP;
}
if (*reg < 0) {
if (report_err)
dev_err(pmx->dev,
"Config param %04x not supported on group %s\n",
param, g->name);
return -ENOTSUPP;
}
return 0;
}
static int tegra_pinconf_get(struct pinctrl_dev *pctldev,
unsigned pin, unsigned long *config)
{
dev_err(pctldev->dev, "pin_config_get op not supported\n");
return -ENOTSUPP;
}
static int tegra_pinconf_set(struct pinctrl_dev *pctldev,
unsigned pin, unsigned long config)
{
dev_err(pctldev->dev, "pin_config_set op not supported\n");
return -ENOTSUPP;
}
static int tegra_pinconf_group_get(struct pinctrl_dev *pctldev,
unsigned group, unsigned long *config)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
enum tegra_pinconf_param param = TEGRA_PINCONF_UNPACK_PARAM(*config);
u16 arg;
const struct tegra_pingroup *g;
int ret;
s8 bank, bit, width;
s16 reg;
u32 val, mask;
g = &pmx->soc->groups[group];
ret = tegra_pinconf_reg(pmx, g, param, true, &bank, &reg, &bit,
&width);
if (ret < 0)
return ret;
val = pmx_readl(pmx, bank, reg);
mask = (1 << width) - 1;
arg = (val >> bit) & mask;
*config = TEGRA_PINCONF_PACK(param, arg);
return 0;
}
static int tegra_pinconf_group_set(struct pinctrl_dev *pctldev,
unsigned group, unsigned long config)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
enum tegra_pinconf_param param = TEGRA_PINCONF_UNPACK_PARAM(config);
u16 arg = TEGRA_PINCONF_UNPACK_ARG(config);
const struct tegra_pingroup *g;
int ret;
s8 bank, bit, width;
s16 reg;
u32 val, mask;
g = &pmx->soc->groups[group];
ret = tegra_pinconf_reg(pmx, g, param, true, &bank, &reg, &bit,
&width);
if (ret < 0)
return ret;
val = pmx_readl(pmx, bank, reg);
if (param == TEGRA_PINCONF_PARAM_LOCK) {
if ((val & BIT(bit)) && !arg) {
dev_err(pctldev->dev, "LOCK bit cannot be cleared\n");
return -EINVAL;
}
}
if (width == 1)
arg = !!arg;
mask = (1 << width) - 1;
if (arg & ~mask) {
dev_err(pctldev->dev,
"config %lx: %x too big for %d bit register\n",
config, arg, width);
return -EINVAL;
}
val &= ~(mask << bit);
val |= arg << bit;
pmx_writel(pmx, val, bank, reg);
return 0;
}
static void tegra_pinconf_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned offset)
{
}
static const char *strip_prefix(const char *s)
{
const char *comma = strchr(s, ',');
if (!comma)
return s;
return comma + 1;
}
static void tegra_pinconf_group_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned group)
{
struct tegra_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
const struct tegra_pingroup *g;
int i, ret;
s8 bank, bit, width;
s16 reg;
u32 val;
g = &pmx->soc->groups[group];
for (i = 0; i < ARRAY_SIZE(cfg_params); i++) {
ret = tegra_pinconf_reg(pmx, g, cfg_params[i].param, false,
&bank, &reg, &bit, &width);
if (ret < 0)
continue;
val = pmx_readl(pmx, bank, reg);
val >>= bit;
val &= (1 << width) - 1;
seq_printf(s, "\n\t%s=%u",
strip_prefix(cfg_params[i].property), val);
}
}
static void tegra_pinconf_config_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s,
unsigned long config)
{
enum tegra_pinconf_param param = TEGRA_PINCONF_UNPACK_PARAM(config);
u16 arg = TEGRA_PINCONF_UNPACK_ARG(config);
const char *pname = "unknown";
int i;
for (i = 0; i < ARRAY_SIZE(cfg_params); i++) {
if (cfg_params[i].param == param) {
pname = cfg_params[i].property;
break;
}
}
seq_printf(s, "%s=%d", strip_prefix(pname), arg);
}
int __devinit tegra_pinctrl_probe(struct platform_device *pdev,
const struct tegra_pinctrl_soc_data *soc_data)
{
struct tegra_pmx *pmx;
struct resource *res;
int i;
pmx = devm_kzalloc(&pdev->dev, sizeof(*pmx), GFP_KERNEL);
if (!pmx) {
dev_err(&pdev->dev, "Can't alloc tegra_pmx\n");
return -ENOMEM;
}
pmx->dev = &pdev->dev;
pmx->soc = soc_data;
tegra_pinctrl_gpio_range.npins = pmx->soc->ngpios;
tegra_pinctrl_desc.name = dev_name(&pdev->dev);
tegra_pinctrl_desc.pins = pmx->soc->pins;
tegra_pinctrl_desc.npins = pmx->soc->npins;
for (i = 0; ; i++) {
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
if (!res)
break;
}
pmx->nbanks = i;
pmx->regs = devm_kzalloc(&pdev->dev, pmx->nbanks * sizeof(*pmx->regs),
GFP_KERNEL);
if (!pmx->regs) {
dev_err(&pdev->dev, "Can't alloc regs pointer\n");
return -ENODEV;
}
for (i = 0; i < pmx->nbanks; i++) {
res = platform_get_resource(pdev, IORESOURCE_MEM, i);
if (!res) {
dev_err(&pdev->dev, "Missing MEM resource\n");
return -ENODEV;
}
if (!devm_request_mem_region(&pdev->dev, res->start,
resource_size(res),
dev_name(&pdev->dev))) {
dev_err(&pdev->dev,
"Couldn't request MEM resource %d\n", i);
return -ENODEV;
}
pmx->regs[i] = devm_ioremap(&pdev->dev, res->start,
resource_size(res));
if (!pmx->regs[i]) {
dev_err(&pdev->dev, "Couldn't ioremap regs %d\n", i);
return -ENODEV;
}
}
pmx->pctl = pinctrl_register(&tegra_pinctrl_desc, &pdev->dev, pmx);
if (IS_ERR(pmx->pctl)) {
dev_err(&pdev->dev, "Couldn't register pinctrl driver\n");
return PTR_ERR(pmx->pctl);
}
pinctrl_add_gpio_range(pmx->pctl, &tegra_pinctrl_gpio_range);
platform_set_drvdata(pdev, pmx);
dev_dbg(&pdev->dev, "Probed Tegra pinctrl driver\n");
return 0;
}
int __devexit tegra_pinctrl_remove(struct platform_device *pdev)
{
struct tegra_pmx *pmx = platform_get_drvdata(pdev);
pinctrl_remove_gpio_range(pmx->pctl, &tegra_pinctrl_gpio_range);
pinctrl_unregister(pmx->pctl);
return 0;
}
