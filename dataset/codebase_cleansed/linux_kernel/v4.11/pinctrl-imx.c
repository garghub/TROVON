static inline const struct group_desc *imx_pinctrl_find_group_by_name(
struct pinctrl_dev *pctldev,
const char *name)
{
const struct group_desc *grp = NULL;
int i;
for (i = 0; i < pctldev->num_groups; i++) {
grp = pinctrl_generic_get_group(pctldev, i);
if (grp && !strcmp(grp->name, name))
break;
}
return grp;
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
struct imx_pinctrl_soc_info *info = ipctl->info;
const struct group_desc *grp;
struct pinctrl_map *new_map;
struct device_node *parent;
int map_num = 1;
int i, j;
grp = imx_pinctrl_find_group_by_name(pctldev, np->name);
if (!grp) {
dev_err(info->dev, "unable to find group for node %s\n",
np->name);
return -EINVAL;
}
for (i = 0; i < grp->num_pins; i++) {
struct imx_pin *pin = &((struct imx_pin *)(grp->data))[i];
if (!(pin->config & IMX_NO_PAD_CTL))
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
for (i = j = 0; i < grp->num_pins; i++) {
struct imx_pin *pin = &((struct imx_pin *)(grp->data))[i];
if (!(pin->config & IMX_NO_PAD_CTL)) {
new_map[j].type = PIN_MAP_TYPE_CONFIGS_PIN;
new_map[j].data.configs.group_or_pin =
pin_get_name(pctldev, pin->pin);
new_map[j].data.configs.configs = &pin->config;
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
struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg;
unsigned int npins, pin_id;
int i;
struct group_desc *grp = NULL;
struct function_desc *func = NULL;
grp = pinctrl_generic_get_group(pctldev, group);
if (!grp)
return -EINVAL;
func = pinmux_generic_get_function(pctldev, selector);
if (!func)
return -EINVAL;
npins = grp->num_pins;
dev_dbg(ipctl->dev, "enable function %s group %s\n",
func->name, grp->name);
for (i = 0; i < npins; i++) {
struct imx_pin *pin = &((struct imx_pin *)(grp->data))[i];
pin_id = pin->pin;
pin_reg = &info->pin_regs[pin_id];
if (pin_reg->mux_reg == -1) {
dev_dbg(ipctl->dev, "Pin(%s) does not support mux function\n",
info->pins[pin_id].name);
continue;
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
static int imx_pmx_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, unsigned offset)
{
struct imx_pinctrl *ipctl = pinctrl_dev_get_drvdata(pctldev);
struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg;
struct group_desc *grp;
struct imx_pin *imx_pin;
unsigned int pin, group;
u32 reg;
if (!(info->flags & SHARE_MUX_CONF_REG))
return 0;
pin_reg = &info->pin_regs[offset];
if (pin_reg->mux_reg == -1)
return -EINVAL;
for (group = 0; group < pctldev->num_groups; group++) {
grp = pinctrl_generic_get_group(pctldev, group);
if (!grp)
continue;
for (pin = 0; pin < grp->num_pins; pin++) {
imx_pin = &((struct imx_pin *)(grp->data))[pin];
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
struct imx_pinctrl_soc_info *info = ipctl->info;
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
struct imx_pinctrl_soc_info *info = ipctl->info;
const struct imx_pin_reg *pin_reg;
u32 reg;
if (!(info->flags & SHARE_MUX_CONF_REG))
return 0;
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
struct imx_pinctrl_soc_info *info = ipctl->info;
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
struct imx_pinctrl_soc_info *info = ipctl->info;
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
struct imx_pinctrl_soc_info *info = ipctl->info;
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
struct group_desc *grp;
unsigned long config;
const char *name;
int i, ret;
if (group > pctldev->num_groups)
return;
seq_printf(s, "\n");
grp = pinctrl_generic_get_group(pctldev, group);
if (!grp)
return;
for (i = 0; i < grp->num_pins; i++) {
struct imx_pin *pin = &((struct imx_pin *)(grp->data))[i];
name = pin_get_name(pctldev, pin->pin);
ret = imx_pinconf_get(pctldev, pin->pin, &config);
if (ret)
return;
seq_printf(s, " %s: 0x%lx\n", name, config);
}
}
static int imx_pinctrl_parse_groups(struct device_node *np,
struct group_desc *grp,
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
grp->num_pins = size / pin_size;
grp->data = devm_kzalloc(info->dev, grp->num_pins *
sizeof(struct imx_pin), GFP_KERNEL);
grp->pins = devm_kzalloc(info->dev, grp->num_pins *
sizeof(unsigned int), GFP_KERNEL);
if (!grp->pins || !grp->data)
return -ENOMEM;
for (i = 0; i < grp->num_pins; i++) {
u32 mux_reg = be32_to_cpu(*list++);
u32 conf_reg;
unsigned int pin_id;
struct imx_pin_reg *pin_reg;
struct imx_pin *pin = &((struct imx_pin *)(grp->data))[i];
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
grp->pins[i] = pin_id;
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
struct imx_pinctrl *ipctl,
u32 index)
{
struct pinctrl_dev *pctl = ipctl->pctl;
struct imx_pinctrl_soc_info *info = ipctl->info;
struct device_node *child;
struct function_desc *func;
struct group_desc *grp;
u32 i = 0;
dev_dbg(info->dev, "parse function(%d): %s\n", index, np->name);
func = pinmux_generic_get_function(pctl, index);
if (!func)
return -EINVAL;
func->name = np->name;
func->num_group_names = of_get_child_count(np);
if (func->num_group_names == 0) {
dev_err(info->dev, "no groups defined in %s\n", np->full_name);
return -EINVAL;
}
func->group_names = devm_kzalloc(info->dev,
func->num_group_names *
sizeof(char *), GFP_KERNEL);
for_each_child_of_node(np, child) {
func->group_names[i] = child->name;
grp = devm_kzalloc(info->dev, sizeof(struct group_desc),
GFP_KERNEL);
if (!grp)
return -ENOMEM;
mutex_lock(&info->mutex);
radix_tree_insert(&pctl->pin_group_tree,
info->group_index++, grp);
mutex_unlock(&info->mutex);
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
struct imx_pinctrl *ipctl)
{
struct device_node *np = pdev->dev.of_node;
struct device_node *child;
struct pinctrl_dev *pctl = ipctl->pctl;
struct imx_pinctrl_soc_info *info = ipctl->info;
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
for (i = 0; i < nfuncs; i++) {
struct function_desc *function;
function = devm_kzalloc(&pdev->dev, sizeof(*function),
GFP_KERNEL);
if (!function)
return -ENOMEM;
mutex_lock(&info->mutex);
radix_tree_insert(&pctl->pin_function_tree, i, function);
mutex_unlock(&info->mutex);
}
pctl->num_functions = nfuncs;
info->group_index = 0;
if (flat_funcs) {
pctl->num_groups = of_get_child_count(np);
} else {
pctl->num_groups = 0;
for_each_child_of_node(np, child)
pctl->num_groups += of_get_child_count(child);
}
if (flat_funcs) {
imx_pinctrl_parse_functions(np, ipctl, 0);
} else {
i = 0;
for_each_child_of_node(np, child)
imx_pinctrl_parse_functions(child, ipctl, i++);
}
return 0;
}
static void imx_free_resources(struct imx_pinctrl *ipctl)
{
if (ipctl->pctl)
pinctrl_unregister(ipctl->pctl);
}
int imx_pinctrl_probe(struct platform_device *pdev,
struct imx_pinctrl_soc_info *info)
{
struct regmap_config config = { .name = "gpr" };
struct device_node *dev_np = pdev->dev.of_node;
struct pinctrl_desc *imx_pinctrl_desc;
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
imx_pinctrl_desc = devm_kzalloc(&pdev->dev, sizeof(*imx_pinctrl_desc),
GFP_KERNEL);
if (!imx_pinctrl_desc)
return -ENOMEM;
imx_pinctrl_desc->name = dev_name(&pdev->dev);
imx_pinctrl_desc->pins = info->pins;
imx_pinctrl_desc->npins = info->npins;
imx_pinctrl_desc->pctlops = &imx_pctrl_ops;
imx_pinctrl_desc->pmxops = &imx_pmx_ops;
imx_pinctrl_desc->confops = &imx_pinconf_ops;
imx_pinctrl_desc->owner = THIS_MODULE;
mutex_init(&info->mutex);
ipctl->info = info;
ipctl->dev = info->dev;
platform_set_drvdata(pdev, ipctl);
ret = devm_pinctrl_register_and_init(&pdev->dev,
imx_pinctrl_desc, ipctl,
&ipctl->pctl);
if (ret) {
dev_err(&pdev->dev, "could not register IMX pinctrl driver\n");
goto free;
}
ret = imx_pinctrl_probe_dt(pdev, ipctl);
if (ret) {
dev_err(&pdev->dev, "fail to probe dt properties\n");
goto free;
}
dev_info(&pdev->dev, "initialized IMX pinctrl driver\n");
return pinctrl_enable(ipctl->pctl);
free:
imx_free_resources(ipctl);
return ret;
}
