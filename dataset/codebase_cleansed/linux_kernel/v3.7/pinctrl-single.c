static unsigned __maybe_unused pcs_readb(void __iomem *reg)
{
return readb(reg);
}
static unsigned __maybe_unused pcs_readw(void __iomem *reg)
{
return readw(reg);
}
static unsigned __maybe_unused pcs_readl(void __iomem *reg)
{
return readl(reg);
}
static void __maybe_unused pcs_writeb(unsigned val, void __iomem *reg)
{
writeb(val, reg);
}
static void __maybe_unused pcs_writew(unsigned val, void __iomem *reg)
{
writew(val, reg);
}
static void __maybe_unused pcs_writel(unsigned val, void __iomem *reg)
{
writel(val, reg);
}
static int pcs_get_groups_count(struct pinctrl_dev *pctldev)
{
struct pcs_device *pcs;
pcs = pinctrl_dev_get_drvdata(pctldev);
return pcs->ngroups;
}
static const char *pcs_get_group_name(struct pinctrl_dev *pctldev,
unsigned gselector)
{
struct pcs_device *pcs;
struct pcs_pingroup *group;
pcs = pinctrl_dev_get_drvdata(pctldev);
group = radix_tree_lookup(&pcs->pgtree, gselector);
if (!group) {
dev_err(pcs->dev, "%s could not find pingroup%i\n",
__func__, gselector);
return NULL;
}
return group->name;
}
static int pcs_get_group_pins(struct pinctrl_dev *pctldev,
unsigned gselector,
const unsigned **pins,
unsigned *npins)
{
struct pcs_device *pcs;
struct pcs_pingroup *group;
pcs = pinctrl_dev_get_drvdata(pctldev);
group = radix_tree_lookup(&pcs->pgtree, gselector);
if (!group) {
dev_err(pcs->dev, "%s could not find pingroup%i\n",
__func__, gselector);
return -EINVAL;
}
*pins = group->gpins;
*npins = group->ngpins;
return 0;
}
static void pcs_pin_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s,
unsigned offset)
{
struct pcs_device *pcs;
unsigned val;
pcs = pinctrl_dev_get_drvdata(pctldev);
val = pcs->read(pcs->base + offset);
val &= pcs->fmask;
seq_printf(s, "%08x %s " , val, DRIVER_NAME);
}
static void pcs_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map, unsigned num_maps)
{
struct pcs_device *pcs;
pcs = pinctrl_dev_get_drvdata(pctldev);
devm_kfree(pcs->dev, map);
}
static int pcs_get_functions_count(struct pinctrl_dev *pctldev)
{
struct pcs_device *pcs;
pcs = pinctrl_dev_get_drvdata(pctldev);
return pcs->nfuncs;
}
static const char *pcs_get_function_name(struct pinctrl_dev *pctldev,
unsigned fselector)
{
struct pcs_device *pcs;
struct pcs_function *func;
pcs = pinctrl_dev_get_drvdata(pctldev);
func = radix_tree_lookup(&pcs->ftree, fselector);
if (!func) {
dev_err(pcs->dev, "%s could not find function%i\n",
__func__, fselector);
return NULL;
}
return func->name;
}
static int pcs_get_function_groups(struct pinctrl_dev *pctldev,
unsigned fselector,
const char * const **groups,
unsigned * const ngroups)
{
struct pcs_device *pcs;
struct pcs_function *func;
pcs = pinctrl_dev_get_drvdata(pctldev);
func = radix_tree_lookup(&pcs->ftree, fselector);
if (!func) {
dev_err(pcs->dev, "%s could not find function%i\n",
__func__, fselector);
return -EINVAL;
}
*groups = func->pgnames;
*ngroups = func->npgnames;
return 0;
}
static int pcs_enable(struct pinctrl_dev *pctldev, unsigned fselector,
unsigned group)
{
struct pcs_device *pcs;
struct pcs_function *func;
int i;
pcs = pinctrl_dev_get_drvdata(pctldev);
func = radix_tree_lookup(&pcs->ftree, fselector);
if (!func)
return -EINVAL;
dev_dbg(pcs->dev, "enabling %s function%i\n",
func->name, fselector);
for (i = 0; i < func->nvals; i++) {
struct pcs_func_vals *vals;
unsigned val, mask;
vals = &func->vals[i];
val = pcs->read(vals->reg);
if (!vals->mask)
mask = pcs->fmask;
else
mask = pcs->fmask & vals->mask;
val &= ~mask;
val |= (vals->val & mask);
pcs->write(val, vals->reg);
}
return 0;
}
static void pcs_disable(struct pinctrl_dev *pctldev, unsigned fselector,
unsigned group)
{
struct pcs_device *pcs;
struct pcs_function *func;
int i;
pcs = pinctrl_dev_get_drvdata(pctldev);
func = radix_tree_lookup(&pcs->ftree, fselector);
if (!func) {
dev_err(pcs->dev, "%s could not find function%i\n",
__func__, fselector);
return;
}
if (pcs->foff == PCS_OFF_DISABLED) {
dev_dbg(pcs->dev, "ignoring disable for %s function%i\n",
func->name, fselector);
return;
}
dev_dbg(pcs->dev, "disabling function%i %s\n",
fselector, func->name);
for (i = 0; i < func->nvals; i++) {
struct pcs_func_vals *vals;
unsigned val;
vals = &func->vals[i];
val = pcs->read(vals->reg);
val &= ~pcs->fmask;
val |= pcs->foff << pcs->fshift;
pcs->write(val, vals->reg);
}
}
static int pcs_request_gpio(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, unsigned offset)
{
return -ENOTSUPP;
}
static int pcs_pinconf_get(struct pinctrl_dev *pctldev,
unsigned pin, unsigned long *config)
{
return -ENOTSUPP;
}
static int pcs_pinconf_set(struct pinctrl_dev *pctldev,
unsigned pin, unsigned long config)
{
return -ENOTSUPP;
}
static int pcs_pinconf_group_get(struct pinctrl_dev *pctldev,
unsigned group, unsigned long *config)
{
return -ENOTSUPP;
}
static int pcs_pinconf_group_set(struct pinctrl_dev *pctldev,
unsigned group, unsigned long config)
{
return -ENOTSUPP;
}
static void pcs_pinconf_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned offset)
{
}
static void pcs_pinconf_group_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned selector)
{
}
static int __devinit pcs_add_pin(struct pcs_device *pcs, unsigned offset)
{
struct pinctrl_pin_desc *pin;
struct pcs_name *pn;
int i;
i = pcs->pins.cur;
if (i >= pcs->desc.npins) {
dev_err(pcs->dev, "too many pins, max %i\n",
pcs->desc.npins);
return -ENOMEM;
}
pin = &pcs->pins.pa[i];
pn = &pcs->names[i];
sprintf(pn->name, "%lx",
(unsigned long)pcs->res->start + offset);
pin->name = pn->name;
pin->number = i;
pcs->pins.cur++;
return i;
}
static int __devinit pcs_allocate_pin_table(struct pcs_device *pcs)
{
int mux_bytes, nr_pins, i;
mux_bytes = pcs->width / BITS_PER_BYTE;
nr_pins = pcs->size / mux_bytes;
dev_dbg(pcs->dev, "allocating %i pins\n", nr_pins);
pcs->pins.pa = devm_kzalloc(pcs->dev,
sizeof(*pcs->pins.pa) * nr_pins,
GFP_KERNEL);
if (!pcs->pins.pa)
return -ENOMEM;
pcs->names = devm_kzalloc(pcs->dev,
sizeof(struct pcs_name) * nr_pins,
GFP_KERNEL);
if (!pcs->names)
return -ENOMEM;
pcs->desc.pins = pcs->pins.pa;
pcs->desc.npins = nr_pins;
for (i = 0; i < pcs->desc.npins; i++) {
unsigned offset;
int res;
offset = i * mux_bytes;
res = pcs_add_pin(pcs, offset);
if (res < 0) {
dev_err(pcs->dev, "error adding pins: %i\n", res);
return res;
}
}
return 0;
}
static struct pcs_function *pcs_add_function(struct pcs_device *pcs,
struct device_node *np,
const char *name,
struct pcs_func_vals *vals,
unsigned nvals,
const char **pgnames,
unsigned npgnames)
{
struct pcs_function *function;
function = devm_kzalloc(pcs->dev, sizeof(*function), GFP_KERNEL);
if (!function)
return NULL;
function->name = name;
function->vals = vals;
function->nvals = nvals;
function->pgnames = pgnames;
function->npgnames = npgnames;
mutex_lock(&pcs->mutex);
list_add_tail(&function->node, &pcs->functions);
radix_tree_insert(&pcs->ftree, pcs->nfuncs, function);
pcs->nfuncs++;
mutex_unlock(&pcs->mutex);
return function;
}
static void pcs_remove_function(struct pcs_device *pcs,
struct pcs_function *function)
{
int i;
mutex_lock(&pcs->mutex);
for (i = 0; i < pcs->nfuncs; i++) {
struct pcs_function *found;
found = radix_tree_lookup(&pcs->ftree, i);
if (found == function)
radix_tree_delete(&pcs->ftree, i);
}
list_del(&function->node);
mutex_unlock(&pcs->mutex);
}
static int pcs_add_pingroup(struct pcs_device *pcs,
struct device_node *np,
const char *name,
int *gpins,
int ngpins)
{
struct pcs_pingroup *pingroup;
pingroup = devm_kzalloc(pcs->dev, sizeof(*pingroup), GFP_KERNEL);
if (!pingroup)
return -ENOMEM;
pingroup->name = name;
pingroup->np = np;
pingroup->gpins = gpins;
pingroup->ngpins = ngpins;
mutex_lock(&pcs->mutex);
list_add_tail(&pingroup->node, &pcs->pingroups);
radix_tree_insert(&pcs->pgtree, pcs->ngroups, pingroup);
pcs->ngroups++;
mutex_unlock(&pcs->mutex);
return 0;
}
static int pcs_get_pin_by_offset(struct pcs_device *pcs, unsigned offset)
{
unsigned index;
if (offset >= pcs->size) {
dev_err(pcs->dev, "mux offset out of range: 0x%x (0x%x)\n",
offset, pcs->size);
return -EINVAL;
}
index = offset / (pcs->width / BITS_PER_BYTE);
return index;
}
static int pcs_parse_one_pinctrl_entry(struct pcs_device *pcs,
struct device_node *np,
struct pinctrl_map **map,
const char **pgnames)
{
struct pcs_func_vals *vals;
const __be32 *mux;
int size, params, rows, *pins, index = 0, found = 0, res = -ENOMEM;
struct pcs_function *function;
if (pcs->bits_per_mux) {
params = 3;
mux = of_get_property(np, PCS_MUX_BITS_NAME, &size);
} else {
params = 2;
mux = of_get_property(np, PCS_MUX_PINS_NAME, &size);
}
if (!mux) {
dev_err(pcs->dev, "no valid property for %s\n", np->name);
return -EINVAL;
}
if (size < (sizeof(*mux) * params)) {
dev_err(pcs->dev, "bad data for %s\n", np->name);
return -EINVAL;
}
size /= sizeof(*mux);
rows = size / params;
vals = devm_kzalloc(pcs->dev, sizeof(*vals) * rows, GFP_KERNEL);
if (!vals)
return -ENOMEM;
pins = devm_kzalloc(pcs->dev, sizeof(*pins) * rows, GFP_KERNEL);
if (!pins)
goto free_vals;
while (index < size) {
unsigned offset, val;
int pin;
offset = be32_to_cpup(mux + index++);
val = be32_to_cpup(mux + index++);
vals[found].reg = pcs->base + offset;
vals[found].val = val;
if (params == 3) {
val = be32_to_cpup(mux + index++);
vals[found].mask = val;
}
pin = pcs_get_pin_by_offset(pcs, offset);
if (pin < 0) {
dev_err(pcs->dev,
"could not add functions for %s %ux\n",
np->name, offset);
break;
}
pins[found++] = pin;
}
pgnames[0] = np->name;
function = pcs_add_function(pcs, np, np->name, vals, found, pgnames, 1);
if (!function)
goto free_pins;
res = pcs_add_pingroup(pcs, np, np->name, pins, found);
if (res < 0)
goto free_function;
(*map)->type = PIN_MAP_TYPE_MUX_GROUP;
(*map)->data.mux.group = np->name;
(*map)->data.mux.function = np->name;
return 0;
free_function:
pcs_remove_function(pcs, function);
free_pins:
devm_kfree(pcs->dev, pins);
free_vals:
devm_kfree(pcs->dev, vals);
return res;
}
static int pcs_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np_config,
struct pinctrl_map **map, unsigned *num_maps)
{
struct pcs_device *pcs;
const char **pgnames;
int ret;
pcs = pinctrl_dev_get_drvdata(pctldev);
*map = devm_kzalloc(pcs->dev, sizeof(**map), GFP_KERNEL);
if (!map)
return -ENOMEM;
*num_maps = 0;
pgnames = devm_kzalloc(pcs->dev, sizeof(*pgnames), GFP_KERNEL);
if (!pgnames) {
ret = -ENOMEM;
goto free_map;
}
ret = pcs_parse_one_pinctrl_entry(pcs, np_config, map, pgnames);
if (ret < 0) {
dev_err(pcs->dev, "no pins entries for %s\n",
np_config->name);
goto free_pgnames;
}
*num_maps = 1;
return 0;
free_pgnames:
devm_kfree(pcs->dev, pgnames);
free_map:
devm_kfree(pcs->dev, *map);
return ret;
}
static void pcs_free_funcs(struct pcs_device *pcs)
{
struct list_head *pos, *tmp;
int i;
mutex_lock(&pcs->mutex);
for (i = 0; i < pcs->nfuncs; i++) {
struct pcs_function *func;
func = radix_tree_lookup(&pcs->ftree, i);
if (!func)
continue;
radix_tree_delete(&pcs->ftree, i);
}
list_for_each_safe(pos, tmp, &pcs->functions) {
struct pcs_function *function;
function = list_entry(pos, struct pcs_function, node);
list_del(&function->node);
}
mutex_unlock(&pcs->mutex);
}
static void pcs_free_pingroups(struct pcs_device *pcs)
{
struct list_head *pos, *tmp;
int i;
mutex_lock(&pcs->mutex);
for (i = 0; i < pcs->ngroups; i++) {
struct pcs_pingroup *pingroup;
pingroup = radix_tree_lookup(&pcs->pgtree, i);
if (!pingroup)
continue;
radix_tree_delete(&pcs->pgtree, i);
}
list_for_each_safe(pos, tmp, &pcs->pingroups) {
struct pcs_pingroup *pingroup;
pingroup = list_entry(pos, struct pcs_pingroup, node);
list_del(&pingroup->node);
}
mutex_unlock(&pcs->mutex);
}
static void pcs_free_resources(struct pcs_device *pcs)
{
if (pcs->pctl)
pinctrl_unregister(pcs->pctl);
pcs_free_funcs(pcs);
pcs_free_pingroups(pcs);
}
static int __devinit pcs_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
const struct of_device_id *match;
struct resource *res;
struct pcs_device *pcs;
int ret;
match = of_match_device(pcs_of_match, &pdev->dev);
if (!match)
return -EINVAL;
pcs = devm_kzalloc(&pdev->dev, sizeof(*pcs), GFP_KERNEL);
if (!pcs) {
dev_err(&pdev->dev, "could not allocate\n");
return -ENOMEM;
}
pcs->dev = &pdev->dev;
mutex_init(&pcs->mutex);
INIT_LIST_HEAD(&pcs->pingroups);
INIT_LIST_HEAD(&pcs->functions);
PCS_GET_PROP_U32("pinctrl-single,register-width", &pcs->width,
"register width not specified\n");
PCS_GET_PROP_U32("pinctrl-single,function-mask", &pcs->fmask,
"function register mask not specified\n");
pcs->fshift = ffs(pcs->fmask) - 1;
pcs->fmax = pcs->fmask >> pcs->fshift;
ret = of_property_read_u32(np, "pinctrl-single,function-off",
&pcs->foff);
if (ret)
pcs->foff = PCS_OFF_DISABLED;
pcs->bits_per_mux = of_property_read_bool(np,
"pinctrl-single,bit-per-mux");
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(pcs->dev, "could not get resource\n");
return -ENODEV;
}
pcs->res = devm_request_mem_region(pcs->dev, res->start,
resource_size(res), DRIVER_NAME);
if (!pcs->res) {
dev_err(pcs->dev, "could not get mem_region\n");
return -EBUSY;
}
pcs->size = resource_size(pcs->res);
pcs->base = devm_ioremap(pcs->dev, pcs->res->start, pcs->size);
if (!pcs->base) {
dev_err(pcs->dev, "could not ioremap\n");
return -ENODEV;
}
INIT_RADIX_TREE(&pcs->pgtree, GFP_KERNEL);
INIT_RADIX_TREE(&pcs->ftree, GFP_KERNEL);
platform_set_drvdata(pdev, pcs);
switch (pcs->width) {
case 8:
pcs->read = pcs_readb;
pcs->write = pcs_writeb;
break;
case 16:
pcs->read = pcs_readw;
pcs->write = pcs_writew;
break;
case 32:
pcs->read = pcs_readl;
pcs->write = pcs_writel;
break;
default:
break;
}
pcs->desc.name = DRIVER_NAME;
pcs->desc.pctlops = &pcs_pinctrl_ops;
pcs->desc.pmxops = &pcs_pinmux_ops;
pcs->desc.confops = &pcs_pinconf_ops;
pcs->desc.owner = THIS_MODULE;
ret = pcs_allocate_pin_table(pcs);
if (ret < 0)
goto free;
pcs->pctl = pinctrl_register(&pcs->desc, pcs->dev, pcs);
if (!pcs->pctl) {
dev_err(pcs->dev, "could not register single pinctrl driver\n");
ret = -EINVAL;
goto free;
}
dev_info(pcs->dev, "%i pins at pa %p size %u\n",
pcs->desc.npins, pcs->base, pcs->size);
return 0;
free:
pcs_free_resources(pcs);
return ret;
}
static int __devexit pcs_remove(struct platform_device *pdev)
{
struct pcs_device *pcs = platform_get_drvdata(pdev);
if (!pcs)
return 0;
pcs_free_resources(pcs);
return 0;
}
