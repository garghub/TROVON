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
pr_debug("SCU%x[0x%08x]=0x%x, got 0x%x from 0x%08x\n", desc->reg,
desc->mask, enable ? desc->enable : desc->disable,
(rv & desc->mask) >> __ffs(desc->mask), rv);
}
static bool aspeed_sig_desc_eval(const struct aspeed_sig_desc *desc,
bool enabled, struct regmap *map)
{
unsigned int raw;
u32 want;
if (regmap_read(map, desc->reg, &raw) < 0)
return false;
aspeed_sig_desc_print_val(desc, enabled, raw);
want = enabled ? desc->enable : desc->disable;
return ((raw & desc->mask) >> __ffs(desc->mask)) == want;
}
static bool aspeed_sig_expr_eval(const struct aspeed_sig_expr *expr,
bool enabled, struct regmap *map)
{
int i;
for (i = 0; i < expr->ndescs; i++) {
const struct aspeed_sig_desc *desc = &expr->descs[i];
if (!aspeed_sig_desc_eval(desc, enabled, map))
return false;
}
return true;
}
static bool aspeed_sig_expr_set(const struct aspeed_sig_expr *expr,
bool enable, struct regmap *map)
{
int i;
for (i = 0; i < expr->ndescs; i++) {
bool ret;
const struct aspeed_sig_desc *desc = &expr->descs[i];
u32 pattern = enable ? desc->enable : desc->disable;
if (desc->reg == HW_STRAP1 || desc->reg == HW_STRAP2)
continue;
ret = regmap_update_bits(map, desc->reg, desc->mask,
pattern << __ffs(desc->mask)) == 0;
if (!ret)
return ret;
}
return aspeed_sig_expr_eval(expr, enable, map);
}
static bool aspeed_sig_expr_enable(const struct aspeed_sig_expr *expr,
struct regmap *map)
{
if (aspeed_sig_expr_eval(expr, true, map))
return true;
return aspeed_sig_expr_set(expr, true, map);
}
static bool aspeed_sig_expr_disable(const struct aspeed_sig_expr *expr,
struct regmap *map)
{
if (!aspeed_sig_expr_eval(expr, true, map))
return true;
return aspeed_sig_expr_set(expr, false, map);
}
static bool aspeed_disable_sig(const struct aspeed_sig_expr **exprs,
struct regmap *map)
{
bool disabled = true;
if (!exprs)
return true;
while (*exprs) {
bool ret;
ret = aspeed_sig_expr_disable(*exprs, map);
disabled = disabled && ret;
exprs++;
}
return disabled;
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
if (!pdesc)
return -EINVAL;
prios = pdesc->prios;
if (!prios)
continue;
while ((funcs = *prios)) {
expr = aspeed_find_expr_by_name(funcs, pfunc->name);
if (expr)
break;
if (!aspeed_disable_sig(funcs, pdata->map))
return -EPERM;
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
if (!aspeed_sig_expr_enable(expr, pdata->map))
return -EPERM;
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
if (!aspeed_disable_sig(funcs, pdata->map))
return -EPERM;
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
if (!aspeed_sig_expr_enable(expr, pdata->map))
return -EPERM;
return 0;
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
pdata->map = syscon_node_to_regmap(parent->of_node);
if (IS_ERR(pdata->map)) {
dev_err(&pdev->dev, "No regmap for syscon pincontroller parent\n");
return PTR_ERR(pdata->map);
}
pctl = pinctrl_register(pdesc, &pdev->dev, pdata);
if (IS_ERR(pctl)) {
dev_err(&pdev->dev, "Failed to register pinctrl\n");
return PTR_ERR(pctl);
}
platform_set_drvdata(pdev, pdata);
return 0;
}
