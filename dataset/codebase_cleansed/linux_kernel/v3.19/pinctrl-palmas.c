static int palmas_pinctrl_get_pin_mux(struct palmas_pctrl_chip_info *pci)
{
const struct palmas_pingroup *g;
unsigned int val;
int ret;
int i;
for (i = 0; i < pci->num_pin_groups; ++i) {
g = &pci->pin_groups[i];
if (g->mux_reg_base == PALMAS_NONE_BASE) {
pci->pins_current_opt[i] = 0;
continue;
}
ret = palmas_read(pci->palmas, g->mux_reg_base,
g->mux_reg_add, &val);
if (ret < 0) {
dev_err(pci->dev, "mux_reg 0x%02x read failed: %d\n",
g->mux_reg_add, ret);
return ret;
}
val &= g->mux_reg_mask;
pci->pins_current_opt[i] = val >> g->mux_bit_shift;
}
return 0;
}
static int palmas_pinctrl_set_dvfs1(struct palmas_pctrl_chip_info *pci,
bool enable)
{
int ret;
int val;
val = enable ? PALMAS_PRIMARY_SECONDARY_PAD3_DVFS1 : 0;
ret = palmas_update_bits(pci->palmas, PALMAS_PU_PD_OD_BASE,
PALMAS_PRIMARY_SECONDARY_PAD3,
PALMAS_PRIMARY_SECONDARY_PAD3_DVFS1, val);
if (ret < 0)
dev_err(pci->dev, "SECONDARY_PAD3 update failed %d\n", ret);
return ret;
}
static int palmas_pinctrl_set_dvfs2(struct palmas_pctrl_chip_info *pci,
bool enable)
{
int ret;
int val;
val = enable ? PALMAS_PRIMARY_SECONDARY_PAD3_DVFS2 : 0;
ret = palmas_update_bits(pci->palmas, PALMAS_PU_PD_OD_BASE,
PALMAS_PRIMARY_SECONDARY_PAD3,
PALMAS_PRIMARY_SECONDARY_PAD3_DVFS2, val);
if (ret < 0)
dev_err(pci->dev, "SECONDARY_PAD3 update failed %d\n", ret);
return ret;
}
static int palmas_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);
return pci->num_pin_groups;
}
static const char *palmas_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned group)
{
struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);
return pci->pin_groups[group].name;
}
static int palmas_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned group, const unsigned **pins, unsigned *num_pins)
{
struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);
*pins = pci->pin_groups[group].pins;
*num_pins = pci->pin_groups[group].npins;
return 0;
}
static int palmas_pinctrl_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);
return pci->num_functions;
}
static const char *palmas_pinctrl_get_func_name(struct pinctrl_dev *pctldev,
unsigned function)
{
struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);
return pci->functions[function].name;
}
static int palmas_pinctrl_get_func_groups(struct pinctrl_dev *pctldev,
unsigned function, const char * const **groups,
unsigned * const num_groups)
{
struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);
*groups = pci->functions[function].groups;
*num_groups = pci->functions[function].ngroups;
return 0;
}
static int palmas_pinctrl_set_mux(struct pinctrl_dev *pctldev,
unsigned function,
unsigned group)
{
struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);
const struct palmas_pingroup *g;
int i;
int ret;
g = &pci->pin_groups[group];
if (function <= PALMAS_PINMUX_OPTION3) {
if (!g->opt[function]) {
dev_err(pci->dev, "Pin %s does not support option %d\n",
g->name, function);
return -EINVAL;
}
i = function;
} else {
for (i = 0; i < ARRAY_SIZE(g->opt); i++) {
if (!g->opt[i])
continue;
if (g->opt[i]->mux_opt == function)
break;
}
if (WARN_ON(i == ARRAY_SIZE(g->opt))) {
dev_err(pci->dev, "Pin %s does not support option %d\n",
g->name, function);
return -EINVAL;
}
}
if (g->mux_reg_base == PALMAS_NONE_BASE) {
if (WARN_ON(i != 0))
return -EINVAL;
return 0;
}
dev_dbg(pci->dev, "%s(): Base0x%02x:0x%02x:0x%02x:0x%02x\n",
__func__, g->mux_reg_base, g->mux_reg_add,
g->mux_reg_mask, i << g->mux_bit_shift);
ret = palmas_update_bits(pci->palmas, g->mux_reg_base, g->mux_reg_add,
g->mux_reg_mask, i << g->mux_bit_shift);
if (ret < 0) {
dev_err(pci->dev, "Reg 0x%02x update failed: %d\n",
g->mux_reg_add, ret);
return ret;
}
pci->pins_current_opt[group] = i;
return 0;
}
static int palmas_pinconf_get(struct pinctrl_dev *pctldev,
unsigned pin, unsigned long *config)
{
struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param = pinconf_to_config_param(*config);
const struct palmas_pingroup *g;
const struct palmas_pin_info *opt;
unsigned int val;
int ret;
int base, add;
int rval;
int arg;
int group_nr;
for (group_nr = 0; group_nr < pci->num_pin_groups; ++group_nr) {
if (pci->pin_groups[group_nr].pins[0] == pin)
break;
}
if (group_nr == pci->num_pin_groups) {
dev_err(pci->dev,
"Pinconf is not supported for pin-id %d\n", pin);
return -ENOTSUPP;
}
g = &pci->pin_groups[group_nr];
opt = g->opt[pci->pins_current_opt[group_nr]];
if (!opt) {
dev_err(pci->dev,
"Pinconf is not supported for pin %s\n", g->name);
return -ENOTSUPP;
}
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
if (!opt->pud_info) {
dev_err(pci->dev,
"PULL control not supported for pin %s\n",
g->name);
return -ENOTSUPP;
}
base = opt->pud_info->pullup_dn_reg_base;
add = opt->pud_info->pullup_dn_reg_add;
ret = palmas_read(pci->palmas, base, add, &val);
if (ret < 0) {
dev_err(pci->dev, "Reg 0x%02x read failed: %d\n",
add, ret);
return ret;
}
rval = val & opt->pud_info->pullup_dn_mask;
arg = 0;
if ((opt->pud_info->normal_val >= 0) &&
(opt->pud_info->normal_val == rval) &&
(param == PIN_CONFIG_BIAS_DISABLE))
arg = 1;
else if ((opt->pud_info->pull_up_val >= 0) &&
(opt->pud_info->pull_up_val == rval) &&
(param == PIN_CONFIG_BIAS_PULL_UP))
arg = 1;
else if ((opt->pud_info->pull_dn_val >= 0) &&
(opt->pud_info->pull_dn_val == rval) &&
(param == PIN_CONFIG_BIAS_PULL_DOWN))
arg = 1;
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
if (!opt->od_info) {
dev_err(pci->dev,
"OD control not supported for pin %s\n",
g->name);
return -ENOTSUPP;
}
base = opt->od_info->od_reg_base;
add = opt->od_info->od_reg_add;
ret = palmas_read(pci->palmas, base, add, &val);
if (ret < 0) {
dev_err(pci->dev, "Reg 0x%02x read failed: %d\n",
add, ret);
return ret;
}
rval = val & opt->od_info->od_mask;
arg = -1;
if ((opt->od_info->od_disable >= 0) &&
(opt->od_info->od_disable == rval))
arg = 0;
else if ((opt->od_info->od_enable >= 0) &&
(opt->od_info->od_enable == rval))
arg = 1;
if (arg < 0) {
dev_err(pci->dev,
"OD control not supported for pin %s\n",
g->name);
return -ENOTSUPP;
}
break;
default:
dev_err(pci->dev, "Properties not supported\n");
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, (u16)arg);
return 0;
}
static int palmas_pinconf_set(struct pinctrl_dev *pctldev,
unsigned pin, unsigned long *configs,
unsigned num_configs)
{
struct palmas_pctrl_chip_info *pci = pinctrl_dev_get_drvdata(pctldev);
enum pin_config_param param;
u16 param_val;
const struct palmas_pingroup *g;
const struct palmas_pin_info *opt;
int ret;
int base, add, mask;
int rval;
int group_nr;
int i;
for (group_nr = 0; group_nr < pci->num_pin_groups; ++group_nr) {
if (pci->pin_groups[group_nr].pins[0] == pin)
break;
}
if (group_nr == pci->num_pin_groups) {
dev_err(pci->dev,
"Pinconf is not supported for pin-id %d\n", pin);
return -ENOTSUPP;
}
g = &pci->pin_groups[group_nr];
opt = g->opt[pci->pins_current_opt[group_nr]];
if (!opt) {
dev_err(pci->dev,
"Pinconf is not supported for pin %s\n", g->name);
return -ENOTSUPP;
}
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
param_val = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
if (!opt->pud_info) {
dev_err(pci->dev,
"PULL control not supported for pin %s\n",
g->name);
return -ENOTSUPP;
}
base = opt->pud_info->pullup_dn_reg_base;
add = opt->pud_info->pullup_dn_reg_add;
mask = opt->pud_info->pullup_dn_mask;
if (param == PIN_CONFIG_BIAS_DISABLE)
rval = opt->pud_info->normal_val;
else if (param == PIN_CONFIG_BIAS_PULL_UP)
rval = opt->pud_info->pull_up_val;
else
rval = opt->pud_info->pull_dn_val;
if (rval < 0) {
dev_err(pci->dev,
"PULL control not supported for pin %s\n",
g->name);
return -ENOTSUPP;
}
break;
case PIN_CONFIG_DRIVE_OPEN_DRAIN:
if (!opt->od_info) {
dev_err(pci->dev,
"OD control not supported for pin %s\n",
g->name);
return -ENOTSUPP;
}
base = opt->od_info->od_reg_base;
add = opt->od_info->od_reg_add;
mask = opt->od_info->od_mask;
if (param_val == 0)
rval = opt->od_info->od_disable;
else
rval = opt->od_info->od_enable;
if (rval < 0) {
dev_err(pci->dev,
"OD control not supported for pin %s\n",
g->name);
return -ENOTSUPP;
}
break;
default:
dev_err(pci->dev, "Properties not supported\n");
return -ENOTSUPP;
}
dev_dbg(pci->dev, "%s(): Add0x%02x:0x%02x:0x%02x:0x%02x\n",
__func__, base, add, mask, rval);
ret = palmas_update_bits(pci->palmas, base, add, mask, rval);
if (ret < 0) {
dev_err(pci->dev, "Reg 0x%02x update failed: %d\n",
add, ret);
return ret;
}
}
return 0;
}
static int palmas_pinctrl_probe(struct platform_device *pdev)
{
struct palmas_pctrl_chip_info *pci;
const struct palmas_pinctrl_data *pinctrl_data = &tps65913_pinctrl_data;
int ret;
bool enable_dvfs1 = false;
bool enable_dvfs2 = false;
if (pdev->dev.of_node) {
const struct of_device_id *match;
match = of_match_device(palmas_pinctrl_of_match, &pdev->dev);
pinctrl_data = match->data;
enable_dvfs1 = of_property_read_bool(pdev->dev.of_node,
"ti,palmas-enable-dvfs1");
enable_dvfs2 = of_property_read_bool(pdev->dev.of_node,
"ti,palmas-enable-dvfs2");
}
pci = devm_kzalloc(&pdev->dev, sizeof(*pci), GFP_KERNEL);
if (!pci) {
dev_err(&pdev->dev, "Malloc for pci failed\n");
return -ENOMEM;
}
pci->dev = &pdev->dev;
pci->palmas = dev_get_drvdata(pdev->dev.parent);
pci->pins = palmas_pins_desc;
pci->num_pins = ARRAY_SIZE(palmas_pins_desc);
pci->functions = palmas_pin_function;
pci->num_functions = ARRAY_SIZE(palmas_pin_function);
pci->pin_groups = pinctrl_data->pin_groups;
pci->num_pin_groups = pinctrl_data->num_pin_groups;
platform_set_drvdata(pdev, pci);
palmas_pinctrl_set_dvfs1(pci, enable_dvfs1);
palmas_pinctrl_set_dvfs2(pci, enable_dvfs2);
ret = palmas_pinctrl_get_pin_mux(pci);
if (ret < 0) {
dev_err(&pdev->dev,
"Reading pinctrol option register failed: %d\n", ret);
return ret;
}
palmas_pinctrl_desc.name = dev_name(&pdev->dev);
palmas_pinctrl_desc.pins = palmas_pins_desc;
palmas_pinctrl_desc.npins = ARRAY_SIZE(palmas_pins_desc);
pci->pctl = pinctrl_register(&palmas_pinctrl_desc, &pdev->dev, pci);
if (!pci->pctl) {
dev_err(&pdev->dev, "Couldn't register pinctrl driver\n");
return -ENODEV;
}
return 0;
}
static int palmas_pinctrl_remove(struct platform_device *pdev)
{
struct palmas_pctrl_chip_info *pci = platform_get_drvdata(pdev);
pinctrl_unregister(pci->pctl);
return 0;
}
