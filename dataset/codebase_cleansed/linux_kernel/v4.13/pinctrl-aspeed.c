int aspeed_pinctrl_get_groups_count(struct pinctrl_dev *pctldev)
{
struct aspeed_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
return pdata->ngroups;
}
const char *aspeed_pinctrl_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
struct aspeed_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
return pdata->groups[group].name;
}
int aspeed_pinctrl_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int group, const unsigned int **pins,
unsigned int *npins)
{
struct aspeed_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
*pins = &pdata->groups[group].pins[0];
*npins = pdata->groups[group].npins;
return 0;
}
void aspeed_pinctrl_pin_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned int offset)
{
seq_printf(s, " %s", dev_name(pctldev->dev));
}
int aspeed_pinmux_get_fn_count(struct pinctrl_dev *pctldev)
{
struct aspeed_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
return pdata->nfunctions;
}
const char *aspeed_pinmux_get_fn_name(struct pinctrl_dev *pctldev,
unsigned int function)
{
struct aspeed_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
return pdata->functions[function].name;
}
int aspeed_pinmux_get_fn_groups(struct pinctrl_dev *pctldev,
unsigned int function,
const char * const **groups,
unsigned int * const num_groups)
{
struct aspeed_pinctrl_data *pdata = pinctrl_dev_get_drvdata(pctldev);
*groups = pdata->functions[function].groups;
*num_groups = pdata->functions[function].ngroups;
return 0;
}
static inline void aspeed_sig_desc_print_val(
const struct aspeed_sig_desc *desc, bool enable, u32 rv)
{
pr_debug("Want %s%X[0x%08X]=0x%X, got 0x%X from 0x%08X\n",
aspeed_pinmux_ips[desc->ip], desc->reg,
desc->mask, enable ? desc->enable : desc->disable,
(rv & desc->mask) >> __ffs(desc->mask), rv);
}
static int aspeed_sig_desc_eval(const struct aspeed_sig_desc *desc,
bool enabled, struct regmap *map)
{
int ret;
unsigned int raw;
u32 want;
if (!map)
return -ENODEV;
ret = regmap_read(map, desc->reg, &raw);
if (ret)
return ret;
aspeed_sig_desc_print_val(desc, enabled, raw);
want = enabled ? desc->enable : desc->disable;
return ((raw & desc->mask) >> __ffs(desc->mask)) == want;
}
static int aspeed_sig_expr_eval(const struct aspeed_sig_expr *expr,
bool enabled, struct regmap * const *maps)
{
int i;
int ret;
for (i = 0; i < expr->ndescs; i++) {
const struct aspeed_sig_desc *desc = &expr->descs[i];
ret = aspeed_sig_desc_eval(desc, enabled, maps[desc->ip]);
if (ret <= 0)
return ret;
}
return 1;
}
static int aspeed_sig_expr_set(const struct aspeed_sig_expr *expr,
bool enable, struct regmap * const *maps)
{
int ret;
int i;
for (i = 0; i < expr->ndescs; i++) {
const struct aspeed_sig_desc *desc = &expr->descs[i];
u32 pattern = enable ? desc->enable : desc->disable;
u32 val = (pattern << __ffs(desc->mask));
if (!maps[desc->ip])
return -ENODEV;
if (desc->ip == ASPEED_IP_SCU && desc->reg == HW_STRAP1 &&
!(desc->mask & (BIT(21) | BIT(22))))
continue;
if (desc->ip == ASPEED_IP_SCU && desc->reg == HW_STRAP2)
continue;
ret = regmap_update_bits(maps[desc->ip], desc->reg,
desc->mask, val);
if (ret)
return ret;
}
ret = aspeed_sig_expr_eval(expr, enable, maps);
if (ret < 0)
return ret;
if (!ret)
return -EPERM;
return 0;
}
static int aspeed_sig_expr_enable(const struct aspeed_sig_expr *expr,
struct regmap * const *maps)
{
int ret;
ret = aspeed_sig_expr_eval(expr, true, maps);
if (ret < 0)
return ret;
if (!ret)
return aspeed_sig_expr_set(expr, true, maps);
return 0;
}
static int aspeed_sig_expr_disable(const struct aspeed_sig_expr *expr,
struct regmap * const *maps)
{
int ret;
ret = aspeed_sig_expr_eval(expr, true, maps);
if (ret < 0)
return ret;
if (ret)
return aspeed_sig_expr_set(expr, false, maps);
return 0;
}
static int aspeed_disable_sig(const struct aspeed_sig_expr **exprs,
struct regmap * const *maps)
{
int ret = 0;
if (!exprs)
return true;
while (*exprs && !ret) {
ret = aspeed_sig_expr_disable(*exprs, maps);
exprs++;
}
return ret;
}
static const struct aspeed_sig_expr *aspeed_find_expr_by_name(
const struct aspeed_sig_expr **exprs, const char *name)
{
while (*exprs) {
if (strcmp((*exprs)->function, name) == 0)
return *exprs;
exprs++;
}
return NULL;
}
static char *get_defined_attribute(const struct aspeed_pin_desc *pdesc,
const char *(*get)(
const struct aspeed_sig_expr *))
{
char *found = NULL;
size_t len = 0;
const struct aspeed_sig_expr ***prios, **funcs, *expr;
prios = pdesc->prios;
while ((funcs = *prios)) {
while ((expr = *funcs)) {
const char *str = get(expr);
size_t delta = strlen(str) + 2;
char *expanded;
expanded = krealloc(found, len + delta + 1, GFP_KERNEL);
if (!expanded) {
kfree(found);
return expanded;
}
found = expanded;
found[len] = '\0';
len += delta;
strcat(found, str);
strcat(found, ", ");
funcs++;
}
prios++;
}
if (len < 2) {
kfree(found);
return NULL;
}
found[len - 2] = '\0';
return found;
}
static const char *aspeed_sig_expr_function(const struct aspeed_sig_expr *expr)
{
return expr->function;
}
static char *get_defined_functions(const struct aspeed_pin_desc *pdesc)
{
return get_defined_attribute(pdesc, aspeed_sig_expr_function);
}
static const char *aspeed_sig_expr_signal(const struct aspeed_sig_expr *expr)
{
return expr->signal;
}
static char *get_defined_signals(const struct aspeed_pin_desc *pdesc)
{
return get_defined_attribute(pdesc, aspeed_sig_expr_signal);
}
int aspeed_pinmux_set_mux(struct pinctrl_dev *pctldev, unsigned int function,
unsigned int group)
{
int i;
int ret;
const struct aspeed_pinctrl_data *pdata =
pinctrl_dev_get_drvdata(pctldev);
const struct aspeed_pin_group *pgroup = &pdata->groups[group];
const struct aspeed_pin_function *pfunc =
&pdata->functions[function];
for (i = 0; i < pgroup->npins; i++) {
int pin = pgroup->pins[i];
const struct aspeed_pin_desc *pdesc = pdata->pins[pin].drv_data;
const struct aspeed_sig_expr *expr = NULL;
const struct aspeed_sig_expr **funcs;
const struct aspeed_sig_expr ***prios;
pr_debug("Muxing pin %d for %s\n", pin, pfunc->name);
if (!pdesc)
return -EINVAL;
prios = pdesc->prios;
if (!prios)
continue;
while ((funcs = *prios)) {
expr = aspeed_find_expr_by_name(funcs, pfunc->name);
if (expr)
break;
ret = aspeed_disable_sig(funcs, pdata->maps);
if (ret)
return ret;
prios++;
}
if (!expr) {
char *functions = get_defined_functions(pdesc);
char *signals = get_defined_signals(pdesc);
pr_warn("No function %s found on pin %s (%d). Found signal(s) %s for function(s) %s\n",
pfunc->name, pdesc->name, pin, signals,
functions);
kfree(signals);
kfree(functions);
return -ENXIO;
}
ret = aspeed_sig_expr_enable(expr, pdata->maps);
if (ret)
return ret;
}
return 0;
}
static bool aspeed_expr_is_gpio(const struct aspeed_sig_expr *expr)
{
return strncmp(expr->signal, "GPIO", 4) == 0;
}
static bool aspeed_gpio_in_exprs(const struct aspeed_sig_expr **exprs)
{
if (!exprs)
return false;
while (*exprs) {
if (aspeed_expr_is_gpio(*exprs))
return true;
exprs++;
}
return false;
}
int aspeed_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int offset)
{
int ret;
const struct aspeed_pinctrl_data *pdata =
pinctrl_dev_get_drvdata(pctldev);
const struct aspeed_pin_desc *pdesc = pdata->pins[offset].drv_data;
const struct aspeed_sig_expr ***prios, **funcs, *expr;
if (!pdesc)
return -EINVAL;
prios = pdesc->prios;
if (!prios)
return -ENXIO;
while ((funcs = *prios)) {
if (aspeed_gpio_in_exprs(funcs))
break;
ret = aspeed_disable_sig(funcs, pdata->maps);
if (ret)
return ret;
prios++;
}
if (!funcs) {
char *signals = get_defined_signals(pdesc);
pr_warn("No GPIO signal type found on pin %s (%d). Found: %s\n",
pdesc->name, offset, signals);
kfree(signals);
return -ENXIO;
}
expr = *funcs;
if (!expr)
return 0;
return aspeed_sig_expr_enable(expr, pdata->maps);
}
int aspeed_pinctrl_probe(struct platform_device *pdev,
struct pinctrl_desc *pdesc,
struct aspeed_pinctrl_data *pdata)
{
struct device *parent;
struct pinctrl_dev *pctl;
parent = pdev->dev.parent;
if (!parent) {
dev_err(&pdev->dev, "No parent for syscon pincontroller\n");
return -ENODEV;
}
pdata->maps[ASPEED_IP_SCU] = syscon_node_to_regmap(parent->of_node);
if (IS_ERR(pdata->maps[ASPEED_IP_SCU])) {
dev_err(&pdev->dev, "No regmap for syscon pincontroller parent\n");
return PTR_ERR(pdata->maps[ASPEED_IP_SCU]);
}
pctl = pinctrl_register(pdesc, &pdev->dev, pdata);
if (IS_ERR(pctl)) {
dev_err(&pdev->dev, "Failed to register pinctrl\n");
return PTR_ERR(pctl);
}
platform_set_drvdata(pdev, pdata);
return 0;
}
static inline bool pin_in_config_range(unsigned int offset,
const struct aspeed_pin_config *config)
{
return offset >= config->pins[0] && offset <= config->pins[1];
}
static inline const struct aspeed_pin_config *find_pinconf_config(
const struct aspeed_pinctrl_data *pdata,
unsigned int offset,
enum pin_config_param param)
{
unsigned int i;
for (i = 0; i < pdata->nconfigs; i++) {
if (param == pdata->configs[i].param &&
pin_in_config_range(offset, &pdata->configs[i]))
return &pdata->configs[i];
}
return NULL;
}
static const struct aspeed_pin_config_map *find_pinconf_map(
enum pin_config_param param,
enum aspeed_pin_config_map_type type,
s64 value)
{
int i;
for (i = 0; i < ARRAY_SIZE(pin_config_map); i++) {
const struct aspeed_pin_config_map *elem;
bool match;
elem = &pin_config_map[i];
switch (type) {
case MAP_TYPE_ARG:
match = (elem->arg == -1 || elem->arg == value);
break;
case MAP_TYPE_VAL:
match = (elem->val == value);
break;
}
if (param == elem->param && match)
return elem;
}
return NULL;
}
int aspeed_pin_config_get(struct pinctrl_dev *pctldev, unsigned int offset,
unsigned long *config)
{
const enum pin_config_param param = pinconf_to_config_param(*config);
const struct aspeed_pin_config_map *pmap;
const struct aspeed_pinctrl_data *pdata;
const struct aspeed_pin_config *pconf;
unsigned int val;
int rc = 0;
u32 arg;
pdata = pinctrl_dev_get_drvdata(pctldev);
pconf = find_pinconf_config(pdata, offset, param);
if (!pconf)
return -ENOTSUPP;
rc = regmap_read(pdata->maps[ASPEED_IP_SCU], pconf->reg, &val);
if (rc < 0)
return rc;
pmap = find_pinconf_map(param, MAP_TYPE_VAL,
(val & BIT(pconf->bit)) >> pconf->bit);
if (!pmap)
return -EINVAL;
if (param == PIN_CONFIG_DRIVE_STRENGTH)
arg = (u32) pmap->arg;
else if (param == PIN_CONFIG_BIAS_PULL_DOWN)
arg = !!pmap->arg;
else
arg = 1;
if (!arg)
return -EINVAL;
*config = pinconf_to_config_packed(param, arg);
return 0;
}
int aspeed_pin_config_set(struct pinctrl_dev *pctldev, unsigned int offset,
unsigned long *configs, unsigned int num_configs)
{
const struct aspeed_pinctrl_data *pdata;
unsigned int i;
int rc = 0;
pdata = pinctrl_dev_get_drvdata(pctldev);
for (i = 0; i < num_configs; i++) {
const struct aspeed_pin_config_map *pmap;
const struct aspeed_pin_config *pconf;
enum pin_config_param param;
unsigned int val;
u32 arg;
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
pconf = find_pinconf_config(pdata, offset, param);
if (!pconf)
return -ENOTSUPP;
pmap = find_pinconf_map(param, MAP_TYPE_ARG, arg);
if (unlikely(WARN_ON(!pmap)))
return -EINVAL;
val = pmap->val << pconf->bit;
rc = regmap_update_bits(pdata->maps[ASPEED_IP_SCU], pconf->reg,
BIT(pconf->bit), val);
if (rc < 0)
return rc;
pr_debug("%s: Set SCU%02X[%d]=%d for param %d(=%d) on pin %d\n",
__func__, pconf->reg, pconf->bit, pmap->val,
param, arg, offset);
}
return 0;
}
int aspeed_pin_config_group_get(struct pinctrl_dev *pctldev,
unsigned int selector,
unsigned long *config)
{
const unsigned int *pins;
unsigned int npins;
int rc;
rc = aspeed_pinctrl_get_group_pins(pctldev, selector, &pins, &npins);
if (rc < 0)
return rc;
if (!npins)
return -ENODEV;
rc = aspeed_pin_config_get(pctldev, pins[0], config);
return rc;
}
int aspeed_pin_config_group_set(struct pinctrl_dev *pctldev,
unsigned int selector,
unsigned long *configs,
unsigned int num_configs)
{
const unsigned int *pins;
unsigned int npins;
int rc;
int i;
pr_debug("%s: Fetching pins for group selector %d\n",
__func__, selector);
rc = aspeed_pinctrl_get_group_pins(pctldev, selector, &pins, &npins);
if (rc < 0)
return rc;
for (i = 0; i < npins; i++) {
rc = aspeed_pin_config_set(pctldev, pins[i], configs,
num_configs);
if (rc < 0)
return rc;
}
return 0;
}
