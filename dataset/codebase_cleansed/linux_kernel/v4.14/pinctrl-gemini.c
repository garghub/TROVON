static int gemini_get_groups_count(struct pinctrl_dev *pctldev)
{
struct gemini_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
if (pmx->is_3512)
return ARRAY_SIZE(gemini_3512_pin_groups);
if (pmx->is_3516)
return ARRAY_SIZE(gemini_3516_pin_groups);
return 0;
}
static const char *gemini_get_group_name(struct pinctrl_dev *pctldev,
unsigned int selector)
{
struct gemini_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
if (pmx->is_3512)
return gemini_3512_pin_groups[selector].name;
if (pmx->is_3516)
return gemini_3516_pin_groups[selector].name;
return NULL;
}
static int gemini_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int selector,
const unsigned int **pins,
unsigned int *num_pins)
{
struct gemini_pmx *pmx = pinctrl_dev_get_drvdata(pctldev);
if (pmx->flash_pin &&
pmx->is_3512 &&
!strcmp(gemini_3512_pin_groups[selector].name, "pflashgrp")) {
*pins = pflash_3512_pins_extended;
*num_pins = ARRAY_SIZE(pflash_3512_pins_extended);
return 0;
}
if (pmx->flash_pin &&
pmx->is_3516 &&
!strcmp(gemini_3516_pin_groups[selector].name, "pflashgrp")) {
*pins = pflash_3516_pins_extended;
*num_pins = ARRAY_SIZE(pflash_3516_pins_extended);
return 0;
}
if (pmx->is_3512) {
*pins = gemini_3512_pin_groups[selector].pins;
*num_pins = gemini_3512_pin_groups[selector].num_pins;
}
if (pmx->is_3516) {
*pins = gemini_3516_pin_groups[selector].pins;
*num_pins = gemini_3516_pin_groups[selector].num_pins;
}
return 0;
}
static void gemini_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned int offset)
{
seq_printf(s, " " DRIVER_NAME);
}
static int gemini_pinctrl_dt_subnode_to_map(struct pinctrl_dev *pctldev,
struct device_node *np,
struct pinctrl_map **map,
unsigned int *reserved_maps,
unsigned int *num_maps)
{
int ret;
const char *function = NULL;
const char *group;
struct property *prop;
ret = of_property_read_string(np, "function", &function);
if (ret < 0)
return ret;
ret = of_property_count_strings(np, "groups");
if (ret < 0)
return ret;
ret = pinctrl_utils_reserve_map(pctldev, map, reserved_maps,
num_maps, ret);
if (ret < 0)
return ret;
of_property_for_each_string(np, "groups", prop, group) {
ret = pinctrl_utils_add_map_mux(pctldev, map, reserved_maps,
num_maps, group, function);
if (ret < 0)
return ret;
pr_debug("ADDED FUNCTION %s <-> GROUP %s\n",
function, group);
}
return 0;
}
static int gemini_pinctrl_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np_config,
struct pinctrl_map **map,
unsigned int *num_maps)
{
unsigned int reserved_maps = 0;
struct device_node *np;
int ret;
*map = NULL;
*num_maps = 0;
for_each_child_of_node(np_config, np) {
ret = gemini_pinctrl_dt_subnode_to_map(pctldev, np, map,
&reserved_maps, num_maps);
if (ret < 0) {
pinctrl_utils_free_map(pctldev, *map, *num_maps);
return ret;
}
}
return 0;
}
static int gemini_pmx_set_mux(struct pinctrl_dev *pctldev,
unsigned int selector,
unsigned int group)
{
struct gemini_pmx *pmx;
const struct gemini_pmx_func *func;
const struct gemini_pin_group *grp;
u32 before, after, expected;
unsigned long tmp;
int i;
pmx = pinctrl_dev_get_drvdata(pctldev);
func = &gemini_pmx_functions[selector];
if (pmx->is_3512)
grp = &gemini_3512_pin_groups[group];
else if (pmx->is_3516)
grp = &gemini_3516_pin_groups[group];
else {
dev_err(pmx->dev, "invalid SoC type\n");
return -ENODEV;
}
dev_info(pmx->dev,
"ACTIVATE function \"%s\" with group \"%s\"\n",
func->name, grp->name);
regmap_read(pmx->map, GLOBAL_MISC_CTRL, &before);
regmap_update_bits(pmx->map, GLOBAL_MISC_CTRL, grp->mask,
grp->value);
regmap_read(pmx->map, GLOBAL_MISC_CTRL, &after);
before &= PADS_MASK;
after &= PADS_MASK;
expected = before &= ~grp->mask;
expected |= grp->value;
expected &= PADS_MASK;
tmp = grp->mask;
for_each_set_bit(i, &tmp, PADS_MAXBIT) {
bool enabled = !(i > 3);
if (after & BIT(i)) {
dev_err(pmx->dev,
"pin group %s could not be %s: "
"probably a hardware limitation\n",
gemini_padgroups[i],
enabled ? "enabled" : "disabled");
dev_err(pmx->dev,
"GLOBAL MISC CTRL before: %08x, after %08x, expected %08x\n",
before, after, expected);
} else {
dev_info(pmx->dev,
"padgroup %s %s\n",
gemini_padgroups[i],
enabled ? "enabled" : "disabled");
}
}
tmp = grp->value;
for_each_set_bit(i, &tmp, PADS_MAXBIT) {
bool enabled = (i > 3);
if (!(after & BIT(i))) {
dev_err(pmx->dev,
"pin group %s could not be %s: "
"probably a hardware limitation\n",
gemini_padgroups[i],
enabled ? "enabled" : "disabled");
dev_err(pmx->dev,
"GLOBAL MISC CTRL before: %08x, after %08x, expected %08x\n",
before, after, expected);
} else {
dev_info(pmx->dev,
"padgroup %s %s\n",
gemini_padgroups[i],
enabled ? "enabled" : "disabled");
}
}
return 0;
}
static int gemini_pmx_get_funcs_count(struct pinctrl_dev *pctldev)
{
return ARRAY_SIZE(gemini_pmx_functions);
}
static const char *gemini_pmx_get_func_name(struct pinctrl_dev *pctldev,
unsigned int selector)
{
return gemini_pmx_functions[selector].name;
}
static int gemini_pmx_get_groups(struct pinctrl_dev *pctldev,
unsigned int selector,
const char * const **groups,
unsigned int * const num_groups)
{
*groups = gemini_pmx_functions[selector].groups;
*num_groups = gemini_pmx_functions[selector].num_groups;
return 0;
}
static int gemini_pmx_probe(struct platform_device *pdev)
{
struct gemini_pmx *pmx;
struct regmap *map;
struct device *dev = &pdev->dev;
struct device *parent;
unsigned long tmp;
u32 val;
int ret;
int i;
pmx = devm_kzalloc(&pdev->dev, sizeof(*pmx), GFP_KERNEL);
if (!pmx)
return -ENOMEM;
pmx->dev = &pdev->dev;
parent = dev->parent;
if (!parent) {
dev_err(dev, "no parent to pin controller\n");
return -ENODEV;
}
map = syscon_node_to_regmap(parent->of_node);
if (IS_ERR(map)) {
dev_err(dev, "no syscon regmap\n");
return PTR_ERR(map);
}
pmx->map = map;
ret = regmap_read(map, GLOBAL_WORD_ID, &val);
if (ret) {
dev_err(dev, "cannot access regmap\n");
return ret;
}
val >>= 8;
val &= 0xffff;
if (val == 0x3512) {
pmx->is_3512 = true;
gemini_pmx_desc.pins = gemini_3512_pins;
gemini_pmx_desc.npins = ARRAY_SIZE(gemini_3512_pins);
dev_info(dev, "detected 3512 chip variant\n");
} else if (val == 0x3516) {
pmx->is_3516 = true;
gemini_pmx_desc.pins = gemini_3516_pins;
gemini_pmx_desc.npins = ARRAY_SIZE(gemini_3516_pins);
dev_info(dev, "detected 3516 chip variant\n");
} else {
dev_err(dev, "unknown chip ID: %04x\n", val);
return -ENODEV;
}
ret = regmap_read(map, GLOBAL_MISC_CTRL, &val);
dev_info(dev, "GLOBAL MISC CTRL at boot: 0x%08x\n", val);
val &= PADS_MASK;
val ^= 0x0f;
tmp = val;
for_each_set_bit(i, &tmp, PADS_MAXBIT) {
dev_info(dev, "pad group %s %s\n", gemini_padgroups[i],
(val & BIT(i)) ? "enabled" : "disabled");
}
regmap_read(map, GLOBAL_STATUS, &val);
pmx->flash_pin = !!(val & GLOBAL_STATUS_FLPIN);
dev_info(dev, "flash pin is %s\n", pmx->flash_pin ? "set" : "not set");
pmx->pctl = devm_pinctrl_register(dev, &gemini_pmx_desc, pmx);
if (IS_ERR(pmx->pctl)) {
dev_err(dev, "could not register pinmux driver\n");
return PTR_ERR(pmx->pctl);
}
dev_info(dev, "initialized Gemini pin control driver\n");
return 0;
}
static int __init gemini_pmx_init(void)
{
return platform_driver_register(&gemini_pmx_driver);
}
