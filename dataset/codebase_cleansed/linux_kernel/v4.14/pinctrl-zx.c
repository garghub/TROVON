static int zx_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np_config,
struct pinctrl_map **map, u32 *num_maps)
{
return pinconf_generic_dt_node_to_map(pctldev, np_config, map,
num_maps, PIN_MAP_TYPE_INVALID);
}
static int zx_set_mux(struct pinctrl_dev *pctldev, unsigned int func_selector,
unsigned int group_selector)
{
struct zx_pinctrl *zpctl = pinctrl_dev_get_drvdata(pctldev);
struct zx_pinctrl_soc_info *info = zpctl->info;
const struct pinctrl_pin_desc *pindesc = info->pins + group_selector;
struct zx_pin_data *data = pindesc->drv_data;
struct zx_mux_desc *mux;
u32 mask, offset, bitpos;
struct function_desc *func;
unsigned long flags;
u32 val, mval;
if (!data)
return -EINVAL;
mux = data->muxes;
mask = (1 << data->width) - 1;
offset = data->offset;
bitpos = data->bitpos;
func = pinmux_generic_get_function(pctldev, func_selector);
if (!func)
return -EINVAL;
while (mux->name) {
if (strcmp(mux->name, func->name) == 0)
break;
mux++;
}
mval = mux->muxval;
spin_lock_irqsave(&zpctl->lock, flags);
if (data->aon_pin) {
u16 aoffset = pindesc->number / 16 * 4;
u16 abitpos = (pindesc->number % 16) * 2;
if (mval & AON_MUX_FLAG) {
val = readl(zpctl->aux_base + aoffset);
val &= ~(0x3 << abitpos);
val |= (mval & 0x3) << abitpos;
writel(val, zpctl->aux_base + aoffset);
} else {
val = readl(zpctl->base + offset);
val &= ~(mask << bitpos);
val |= (mval & mask) << bitpos;
writel(val, zpctl->base + offset);
val = readl(zpctl->aux_base + aoffset);
val &= ~(0x3 << abitpos);
val |= NONAON_MVAL << abitpos;
writel(val, zpctl->aux_base + aoffset);
}
} else {
val = readl(zpctl->base + offset);
val &= ~(mask << bitpos);
val |= (mval & mask) << bitpos;
writel(val, zpctl->base + offset);
}
spin_unlock_irqrestore(&zpctl->lock, flags);
return 0;
}
static int zx_pin_config_get(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *config)
{
struct zx_pinctrl *zpctl = pinctrl_dev_get_drvdata(pctldev);
struct zx_pinctrl_soc_info *info = zpctl->info;
const struct pinctrl_pin_desc *pindesc = info->pins + pin;
struct zx_pin_data *data = pindesc->drv_data;
enum pin_config_param param = pinconf_to_config_param(*config);
u32 val;
if (!data)
return -EINVAL;
val = readl(zpctl->aux_base + data->coffset);
val = val >> data->cbitpos;
switch (param) {
case PIN_CONFIG_BIAS_PULL_DOWN:
val &= ZX_PULL_DOWN;
val = !!val;
if (val == 0)
return -EINVAL;
break;
case PIN_CONFIG_BIAS_PULL_UP:
val &= ZX_PULL_UP;
val = !!val;
if (val == 0)
return -EINVAL;
break;
case PIN_CONFIG_INPUT_ENABLE:
val &= ZX_INPUT_ENABLE;
val = !!val;
if (val == 0)
return -EINVAL;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
val &= ZX_DS_MASK;
val = val >> ZX_DS_SHIFT;
break;
case PIN_CONFIG_SLEW_RATE:
val &= ZX_SLEW;
val = !!val;
break;
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, val);
return 0;
}
static int zx_pin_config_set(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *configs, unsigned int num_configs)
{
struct zx_pinctrl *zpctl = pinctrl_dev_get_drvdata(pctldev);
struct zx_pinctrl_soc_info *info = zpctl->info;
const struct pinctrl_pin_desc *pindesc = info->pins + pin;
struct zx_pin_data *data = pindesc->drv_data;
enum pin_config_param param;
u32 val, arg;
int i;
if (!data)
return -EINVAL;
val = readl(zpctl->aux_base + data->coffset);
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_PULL_DOWN:
val |= ZX_PULL_DOWN << data->cbitpos;
break;
case PIN_CONFIG_BIAS_PULL_UP:
val |= ZX_PULL_UP << data->cbitpos;
break;
case PIN_CONFIG_INPUT_ENABLE:
val |= ZX_INPUT_ENABLE << data->cbitpos;
break;
case PIN_CONFIG_DRIVE_STRENGTH:
val &= ~(ZX_DS_MASK << data->cbitpos);
val |= ZX_DS_VALUE(arg) << data->cbitpos;
break;
case PIN_CONFIG_SLEW_RATE:
if (arg)
val |= ZX_SLEW << data->cbitpos;
else
val &= ~ZX_SLEW << data->cbitpos;
break;
default:
return -ENOTSUPP;
}
}
writel(val, zpctl->aux_base + data->coffset);
return 0;
}
static int zx_pinctrl_build_state(struct platform_device *pdev)
{
struct zx_pinctrl *zpctl = platform_get_drvdata(pdev);
struct zx_pinctrl_soc_info *info = zpctl->info;
struct pinctrl_dev *pctldev = zpctl->pctldev;
struct function_desc *functions;
int nfunctions;
struct group_desc *groups;
int ngroups;
int i;
ngroups = info->npins;
groups = devm_kzalloc(&pdev->dev, ngroups * sizeof(*groups),
GFP_KERNEL);
if (!groups)
return -ENOMEM;
for (i = 0; i < ngroups; i++) {
const struct pinctrl_pin_desc *pindesc = info->pins + i;
struct group_desc *group = groups + i;
group->name = pindesc->name;
group->pins = (int *) &pindesc->number;
group->num_pins = 1;
radix_tree_insert(&pctldev->pin_group_tree, i, group);
}
pctldev->num_groups = ngroups;
functions = kcalloc(info->npins, sizeof(*functions), GFP_KERNEL);
if (!functions)
return -ENOMEM;
nfunctions = 0;
for (i = 0; i < info->npins; i++) {
const struct pinctrl_pin_desc *pindesc = info->pins + i;
struct zx_pin_data *data = pindesc->drv_data;
struct zx_mux_desc *mux;
if (!data)
continue;
mux = data->muxes;
while (mux->name) {
struct function_desc *func = functions;
while (func->name) {
if (strcmp(mux->name, func->name) == 0) {
func->num_group_names++;
break;
}
func++;
}
if (!func->name) {
func->name = mux->name;
func->num_group_names = 1;
radix_tree_insert(&pctldev->pin_function_tree,
nfunctions++, func);
}
mux++;
}
}
pctldev->num_functions = nfunctions;
functions = krealloc(functions, nfunctions * sizeof(*functions),
GFP_KERNEL);
for (i = 0; i < info->npins; i++) {
const struct pinctrl_pin_desc *pindesc = info->pins + i;
struct zx_pin_data *data = pindesc->drv_data;
struct zx_mux_desc *mux;
if (!data)
continue;
mux = data->muxes;
while (mux->name) {
struct function_desc *func;
const char **group;
int j;
for (j = 0; j < nfunctions; j++)
if (strcmp(functions[j].name, mux->name) == 0)
break;
func = functions + j;
if (!func->group_names) {
func->group_names = devm_kzalloc(&pdev->dev,
func->num_group_names *
sizeof(*func->group_names),
GFP_KERNEL);
if (!func->group_names) {
kfree(functions);
return -ENOMEM;
}
}
group = func->group_names;
while (*group)
group++;
*group = pindesc->name;
mux++;
}
}
return 0;
}
int zx_pinctrl_init(struct platform_device *pdev,
struct zx_pinctrl_soc_info *info)
{
struct pinctrl_desc *pctldesc;
struct zx_pinctrl *zpctl;
struct device_node *np;
struct resource *res;
int ret;
zpctl = devm_kzalloc(&pdev->dev, sizeof(*zpctl), GFP_KERNEL);
if (!zpctl)
return -ENOMEM;
spin_lock_init(&zpctl->lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
zpctl->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(zpctl->base))
return PTR_ERR(zpctl->base);
np = of_parse_phandle(pdev->dev.of_node, "zte,auxiliary-controller", 0);
if (!np) {
dev_err(&pdev->dev, "failed to find auxiliary controller\n");
return -ENODEV;
}
zpctl->aux_base = of_iomap(np, 0);
if (!zpctl->aux_base)
return -ENOMEM;
zpctl->dev = &pdev->dev;
zpctl->info = info;
pctldesc = devm_kzalloc(&pdev->dev, sizeof(*pctldesc), GFP_KERNEL);
if (!pctldesc)
return -ENOMEM;
pctldesc->name = dev_name(&pdev->dev);
pctldesc->owner = THIS_MODULE;
pctldesc->pins = info->pins;
pctldesc->npins = info->npins;
pctldesc->pctlops = &zx_pinctrl_ops;
pctldesc->pmxops = &zx_pinmux_ops;
pctldesc->confops = &zx_pinconf_ops;
zpctl->pctldev = devm_pinctrl_register(&pdev->dev, pctldesc, zpctl);
if (IS_ERR(zpctl->pctldev)) {
ret = PTR_ERR(zpctl->pctldev);
dev_err(&pdev->dev, "failed to register pinctrl: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, zpctl);
ret = zx_pinctrl_build_state(pdev);
if (ret) {
dev_err(&pdev->dev, "failed to build state: %d\n", ret);
return ret;
}
dev_info(&pdev->dev, "initialized pinctrl driver\n");
return 0;
}
