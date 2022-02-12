static const inline struct imx_pin_group *imx_pinctrl_find_group_by_name(
const struct imx_pinctrl_soc_info *info,
const char *name)
{
const struct imx_pin_group *grp = NULL;
int i;
for (i = 0; i < info->ngroups; i++) {
if (!strcmp(info->groups[i].name, name)) {
grp = &info->groups[i];
break;
}
}
return grp;
}
static int imx_get_groups_count(struct pinctrl_dev *pctldev)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
return info->ngroups;
}
static const char *imx_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
return info->groups[selector].name;
}
static int imx_get_group_pins(struct pinctrl_dev *pctldev, unsigned selector,
const unsigned **pins,
unsigned *npins)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
if (selector >= info->ngroups)
return -EINVAL;
*pins = info->groups[selector].pin_ids;
*npins = info->groups[selector].npins;
return 0;
}
static void imx_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned offset)
{
seq_printf(s, "%s", dev_name(pctldev->dev));
}
static int imx_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np,
struct pinctrl_map **map, unsigned *num_maps)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_group *grp;
struct pinctrl_map *new_map;
struct device_node *parent;
int map_num = 1;
int i, j;
grp = imx_pinctrl_find_group_by_name(info, np->name);
if (!grp) {
dev_err(info->dev, "unable to find group for node %s\n",
np->name);
return -EINVAL;
}
for (i = 0; i < grp->npins; i++) {
if (!(grp->pins[i].config & IMX_NO_PAD_CTL))
map_num++;
}
new_map = kmalloc(sizeof(struct pinctrl_map) * map_num, GFP_KERNEL);
if (!new_map)
return -ENOMEM;
*map = new_map;
*num_maps = map_num;
parent = of_get_parent(np);
if (!parent) {
kfree(new_map);
return -EINVAL;
}
new_map[0].type = PIN_MAP_TYPE_MUX_GROUP;
new_map[0].data.mux.function = parent->name;
new_map[0].data.mux.group = np->name;
of_node_put(parent);
new_map++;
for (i = j = 0; i < grp->npins; i++) {
if (!(grp->pins[i].config & IMX_NO_PAD_CTL)) {
new_map[j].type = PIN_MAP_TYPE_CONFIGS_PIN;
new_map[j].data.configs.group_or_pin =
pin_get_name(pctldev, grp->pins[i].pin);
new_map[j].data.configs.configs = &grp->pins[i].config;
new_map[j].data.configs.num_configs = 1;
j++;
}
}
dev_dbg(pctldev->dev, "maps: function %s group %s num %d\n",
(*map)->data.mux.function, (*map)->data.mux.group, map_num);
return 0;
}
static void imx_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map, unsigned num_maps)
{
kfree(map);
}
static int imx_pmx_set(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg;
unsigned int npins, pin_id;
int i;
struct imx_pin_group *grp;
grp = &info->groups[group];
npins = grp->npins;
dev_dbg(ipctl->dev, "enable function %s group %s\n",
info->functions[selector].name, grp->name);
for (i = 0; i < npins; i++) {
struct imx_pin *pin = &grp->pins[i];
pin_id = pin->pin;
pin_reg = &info->pin_regs[pin_id];
if (pin_reg->mux_reg == -1) {
dev_err(ipctl->dev, "Pin(%s) does not support mux function\n",
info->pins[pin_id].name);
return -EINVAL;
}
if (info->flags & SHARE_MUX_CONF_REG) {
u32 reg;
reg = readl(ipctl->base + pin_reg->mux_reg);
reg &= ~(0x7 << 20);
reg |= (pin->mux_mode << 20);
writel(reg, ipctl->base + pin_reg->mux_reg);
} else {
writel(pin->mux_mode, ipctl->base + pin_reg->mux_reg);
}
dev_dbg(ipctl->dev, "write: offset 0x%x val 0x%x\n",
pin_reg->mux_reg, pin->mux_mode);
if (pin->input_val >> 24 == 0xff) {
u32 val = pin->input_val;
u8 select = val & 0xff;
u8 width = (val >> 8) & 0xff;
u8 shift = (val >> 16) & 0xff;
u32 mask = ((1 << width) - 1) << shift;
val = readl(ipctl->base + pin->input_reg);
val &= ~mask;
val |= select << shift;
writel(val, ipctl->base + pin->input_reg);
} else if (pin->input_reg) {
if (ipctl->input_sel_base)
writel(pin->input_val, ipctl->input_sel_base +
pin->input_reg);
else
writel(pin->input_val, ipctl->base +
pin->input_reg);
dev_dbg(ipctl->dev,
"==>select_input: offset 0x%x val 0x%x\n",
pin->input_reg, pin->input_val);
}
}
return 0;
}
static int imx_pmx_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
return info->nfunctions;
}
static const char *imx_pmx_get_func_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
return info->functions[selector].name;
}
static int imx_pmx_get_groups(struct pinctrl_dev *pctldev, unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
*groups = info->functions[selector].groups;
*num_groups = info->functions[selector].num_groups;
return 0;
}
static int imx_pmx_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, unsigned offset)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg;
struct imx_pin_group *grp;
struct imx_pin *imx_pin;
unsigned int pin, group;
u32 reg;
if (!(info->flags & SHARE_MUX_CONF_REG))
return -EINVAL;
pin_reg = &info->pin_regs[offset];
if (pin_reg->mux_reg == -1)
return -EINVAL;
for (group = 0; group < info->ngroups; group++) {
grp = &info->groups[group];
for (pin = 0; pin < grp->npins; pin++) {
imx_pin = &grp->pins[pin];
if (imx_pin->pin == offset && !imx_pin->mux_mode)
goto mux_pin;
}
}
return -EINVAL;
mux_pin:
reg = readl(ipctl->base + pin_reg->mux_reg);
reg &= ~(0x7 << 20);
reg |= imx_pin->config;
writel(reg, ipctl->base + pin_reg->mux_reg);
return 0;
}
static void imx_pmx_gpio_disable_free(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, unsigned offset)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg;
u32 reg;
if (!(info->flags & SHARE_MUX_CONF_REG))
return;
pin_reg = &info->pin_regs[offset];
if (pin_reg->mux_reg == -1)
return;
reg = readl(ipctl->base + pin_reg->mux_reg);
reg &= ~0x7;
writel(reg, ipctl->base + pin_reg->mux_reg);
}
static int imx_pmx_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, unsigned offset, bool input)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg;
u32 reg;
if (!(info->flags & SHARE_MUX_CONF_REG))
return -EINVAL;
pin_reg = &info->pin_regs[offset];
if (pin_reg->mux_reg == -1)
return -EINVAL;
reg = readl(ipctl->base + pin_reg->mux_reg);
if (input)
reg &= ~0x2;
else
reg |= 0x2;
writel(reg, ipctl->base + pin_reg->mux_reg);
return 0;
}
static int imx_pinconf_get(struct pinctrl_dev *pctldev,
unsigned pin_id, unsigned long *config)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg = &info->pin_regs[pin_id];
if (pin_reg->conf_reg == -1) {
dev_err(info->dev, "Pin(%s) does not support config function\n",
info->pins[pin_id].name);
return -EINVAL;
}
*config = readl(ipctl->base + pin_reg->conf_reg);
if (info->flags & SHARE_MUX_CONF_REG)
*config &= 0xffff;
return 0;
}
static int imx_pinconf_set(struct pinctrl_dev *pctldev,
unsigned pin_id, unsigned long *configs,
unsigned num_configs)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg = &info->pin_regs[pin_id];
int i;
if (pin_reg->conf_reg == -1) {
dev_err(info->dev, "Pin(%s) does not support config function\n",
info->pins[pin_id].name);
return -EINVAL;
}
dev_dbg(ipctl->dev, "pinconf set pin %s\n",
info->pins[pin_id].name);
for (i = 0; i < num_configs; i++) {
if (info->flags & SHARE_MUX_CONF_REG) {
u32 reg;
reg = readl(ipctl->base + pin_reg->conf_reg);
reg &= ~0xffff;
reg |= configs[i];
writel(reg, ipctl->base + pin_reg->conf_reg);
} else {
writel(configs[i], ipctl->base + pin_reg->conf_reg);
}
dev_dbg(ipctl->dev, "write: offset 0x%x val 0x%lx\n",
pin_reg->conf_reg, configs[i]);
}
return 0;
}
static void imx_pinconf_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned pin_id)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg = &info->pin_regs[pin_id];
unsigned long config;
if (!pin_reg || pin_reg->conf_reg == -1) {
seq_printf(s, "N/A");
return;
}
config = readl(ipctl->base + pin_reg->conf_reg);
seq_printf(s, "0x%lx", config);
}
static void imx_pinconf_group_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned group)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
const struct imx_pinctrl_soc_info *info = ipctl->info;
struct imx_pin_group *grp;
unsigned long config;
const char *name;
int i, ret;
if (group > info->ngroups)
return;
seq_printf(s, "\n");
grp = &info->groups[group];
for (i = 0; i < grp->npins; i++) {
struct imx_pin *pin = &grp->pins[i];
name = pin_get_name(pctldev, pin->pin);
ret = imx_pinconf_get(pctldev, pin->pin, &config);
if (ret)
return;
seq_printf(s, "%s: 0x%lx", name, config);
}
}
static int imx_pinctrl_parse_groups(struct device_node *np,
struct imx_pin_group *grp,
struct imx_pinctrl_soc_info *info,
u32 index)
{
int size, pin_size;
const __be32 *list;
int i;
u32 config;
dev_dbg(info->dev, "group(%d): %s\n", index, np->name);
if (info->flags & SHARE_MUX_CONF_REG)
pin_size = SHARE_FSL_PIN_SIZE;
else
pin_size = FSL_PIN_SIZE;
grp->name = np->name;
list = of_get_property(np, "fsl,pins", &size);
if (!list) {
dev_err(info->dev, "no fsl,pins property in node %s\n", np->full_name);
return -EINVAL;
}
if (!size || size % pin_size) {
dev_err(info->dev, "Invalid fsl,pins property in node %s\n", np->full_name);
return -EINVAL;
}
grp->npins = size / pin_size;
grp->pins = devm_kzalloc(info->dev, grp->npins * sizeof(struct imx_pin),
GFP_KERNEL);
grp->pin_ids = devm_kzalloc(info->dev, grp->npins * sizeof(unsigned int),
GFP_KERNEL);
if (!grp->pins || ! grp->pin_ids)
return -ENOMEM;
for (i = 0; i < grp->npins; i++) {
u32 mux_reg = be32_to_cpu(*list++);
u32 conf_reg;
unsigned int pin_id;
struct imx_pin_reg *pin_reg;
struct imx_pin *pin = &grp->pins[i];
if (!(info->flags & ZERO_OFFSET_VALID) && !mux_reg)
mux_reg = -1;
if (info->flags & SHARE_MUX_CONF_REG) {
conf_reg = mux_reg;
} else {
conf_reg = be32_to_cpu(*list++);
if (!conf_reg)
conf_reg = -1;
}
pin_id = (mux_reg != -1) ? mux_reg / 4 : conf_reg / 4;
pin_reg = &info->pin_regs[pin_id];
pin->pin = pin_id;
grp->pin_ids[i] = pin_id;
pin_reg->mux_reg = mux_reg;
pin_reg->conf_reg = conf_reg;
pin->input_reg = be32_to_cpu(*list++);
pin->mux_mode = be32_to_cpu(*list++);
pin->input_val = be32_to_cpu(*list++);
config = be32_to_cpu(*list++);
if (config & IMX_PAD_SION)
pin->mux_mode |= IOMUXC_CONFIG_SION;
pin->config = config & ~IMX_PAD_SION;
dev_dbg(info->dev, "%s: 0x%x 0x%08lx", info->pins[pin_id].name,
pin->mux_mode, pin->config);
}
return 0;
}
static int imx_pinctrl_parse_functions(struct device_node *np,
struct imx_pinctrl_soc_info *info,
u32 index)
{
struct device_node *child;
struct imx_pmx_func *func;
struct imx_pin_group *grp;
u32 i = 0;
dev_dbg(info->dev, "parse function(%d): %s\n", index, np->name);
func = &info->functions[index];
func->name = np->name;
func->num_groups = of_get_child_count(np);
if (func->num_groups == 0) {
dev_err(info->dev, "no groups defined in %s\n", np->full_name);
return -EINVAL;
}
func->groups = devm_kzalloc(info->dev,
func->num_groups * sizeof(char *), GFP_KERNEL);
for_each_child_of_node(np, child) {
func->groups[i] = child->name;
grp = &info->groups[info->group_index++];
imx_pinctrl_parse_groups(child, grp, info, i++);
}
return 0;
}
static bool imx_pinctrl_dt_is_flat_functions(struct device_node *np)
{
struct device_node *function_np;
struct device_node *pinctrl_np;
for_each_child_of_node(np, function_np) {
if (of_property_read_bool(function_np, "fsl,pins"))
return true;
for_each_child_of_node(function_np, pinctrl_np) {
if (of_property_read_bool(pinctrl_np, "fsl,pins"))
return false;
}
}
return true;
}
static int imx_pinctrl_probe_dt(struct platform_device *pdev,
struct imx_pinctrl_soc_info *info)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *child;
u32 nfuncs = 0;
u32 i = 0;
bool flat_funcs;
if (!np)
return -ENODEV;
flat_funcs = imx_pinctrl_dt_is_flat_functions(np);
if (flat_funcs) {
nfuncs = 1;
} else {
nfuncs = of_get_child_count(np);
if (nfuncs <= 0) {
dev_err(&pdev->dev, "no functions defined\n");
return -EINVAL;
}
}
info->nfunctions = nfuncs;
info->functions = devm_kzalloc(&pdev->dev, nfuncs * sizeof(struct imx_pmx_func),
GFP_KERNEL);
if (!info->functions)
return -ENOMEM;
if (flat_funcs) {
info->ngroups = of_get_child_count(np);
} else {
info->ngroups = 0;
for_each_child_of_node(np, child)
info->ngroups += of_get_child_count(child);
}
info->groups = devm_kzalloc(&pdev->dev, info->ngroups * sizeof(struct imx_pin_group),
GFP_KERNEL);
if (!info->groups)
return -ENOMEM;
if (flat_funcs) {
imx_pinctrl_parse_functions(np, info, 0);
} else {
for_each_child_of_node(np, child)
imx_pinctrl_parse_functions(child, info, i++);
}
return 0;
}
int imx_pinctrl_probe(struct platform_device *pdev,
struct imx_pinctrl_soc_info *info)
{
struct regmap_config config = { .name = "gpr" };
struct device_node *dev_np = pdev->dev.of_node;
struct device_node *np;
struct imx_pinctrl *ipctl;
struct resource *res;
struct regmap *gpr;
int ret, i;
if (!info || !info->pins || !info->npins) {
dev_err(&pdev->dev, "wrong pinctrl info\n");
return -EINVAL;
}
info->dev = &pdev->dev;
if (info->gpr_compatible) {
gpr = syscon_regmap_lookup_by_compatible(info->gpr_compatible);
if (!IS_ERR(gpr))
regmap_attach_dev(&pdev->dev, gpr, &config);
}
ipctl = devm_kzalloc(&pdev->dev, sizeof(*ipctl), GFP_KERNEL);
if (!ipctl)
return -ENOMEM;
info->pin_regs = devm_kmalloc(&pdev->dev, sizeof(*info->pin_regs) *
info->npins, GFP_KERNEL);
if (!info->pin_regs)
return -ENOMEM;
for (i = 0; i < info->npins; i++) {
info->pin_regs[i].mux_reg = -1;
info->pin_regs[i].conf_reg = -1;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
ipctl->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(ipctl->base))
return PTR_ERR(ipctl->base);
if (of_property_read_bool(dev_np, "fsl,input-sel")) {
np = of_parse_phandle(dev_np, "fsl,input-sel", 0);
if (!np) {
dev_err(&pdev->dev, "iomuxc fsl,input-sel property not found\n");
return -EINVAL;
}
ipctl->input_sel_base = of_iomap(np, 0);
of_node_put(np);
if (!ipctl->input_sel_base) {
dev_err(&pdev->dev,
"iomuxc input select base address not found\n");
return -ENOMEM;
}
}
imx_pinctrl_desc.name = dev_name(&pdev->dev);
imx_pinctrl_desc.pins = info->pins;
imx_pinctrl_desc.npins = info->npins;
ret = imx_pinctrl_probe_dt(pdev, info);
if (ret) {
dev_err(&pdev->dev, "fail to probe dt properties\n");
return ret;
}
ipctl->info = info;
ipctl->dev = info->dev;
platform_set_drvdata(pdev, ipctl);
ipctl->pctl = pinctrl_register(&imx_pinctrl_desc, &pdev->dev, ipctl);
if (IS_ERR(ipctl->pctl)) {
dev_err(&pdev->dev, "could not register IMX pinctrl driver\n");
return PTR_ERR(ipctl->pctl);
}
dev_info(&pdev->dev, "initialized IMX pinctrl driver\n");
return 0;
}
int imx_pinctrl_remove(struct platform_device *pdev)
{
struct imx_pinctrl *ipctl = platform_get_drvdata(pdev);
pinctrl_unregister(ipctl->pctl);
return 0;
}
