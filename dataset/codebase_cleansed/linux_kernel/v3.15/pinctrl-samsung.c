static inline struct samsung_pin_bank *gc_to_pin_bank(struct gpio_chip *gc)
{
return container_of(gc, struct samsung_pin_bank, gpio_chip);
}
static int samsung_get_group_count(struct pinctrl_dev *pctldev)
{
struct samsung_pinctrl_drv_data *drvdata;
drvdata = pinctrl_dev_get_drvdata(pctldev);
return drvdata->nr_groups;
}
static const char *samsung_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct samsung_pinctrl_drv_data *drvdata;
drvdata = pinctrl_dev_get_drvdata(pctldev);
return drvdata->pin_groups[selector].name;
}
static int samsung_get_group_pins(struct pinctrl_dev *pctldev,
unsigned selector, const unsigned **pins, unsigned *num_pins)
{
struct samsung_pinctrl_drv_data *drvdata;
drvdata = pinctrl_dev_get_drvdata(pctldev);
*pins = drvdata->pin_groups[selector].pins;
*num_pins = drvdata->pin_groups[selector].num_pins;
return 0;
}
static int samsung_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np, struct pinctrl_map **maps,
unsigned *nmaps)
{
struct device *dev = pctldev->dev;
struct pinctrl_map *map;
unsigned long *cfg = NULL;
char *gname, *fname;
int cfg_cnt = 0, map_cnt = 0, idx = 0;
for (idx = 0; idx < ARRAY_SIZE(pcfgs); idx++) {
if (of_find_property(np, pcfgs[idx].prop_cfg, NULL))
cfg_cnt++;
}
if (cfg_cnt)
map_cnt = 1;
if (of_find_property(np, "samsung,pin-function", NULL))
map_cnt++;
if (!map_cnt) {
dev_err(dev, "node %s does not have either config or function "
"configurations\n", np->name);
return -EINVAL;
}
map = kzalloc(sizeof(*map) * map_cnt, GFP_KERNEL);
if (!map) {
dev_err(dev, "could not alloc memory for pin-maps\n");
return -ENOMEM;
}
*nmaps = 0;
gname = kzalloc(strlen(np->name) + GSUFFIX_LEN, GFP_KERNEL);
if (!gname) {
dev_err(dev, "failed to alloc memory for group name\n");
goto free_map;
}
sprintf(gname, "%s%s", np->name, GROUP_SUFFIX);
if (!cfg_cnt)
goto skip_cfgs;
cfg = kzalloc(sizeof(*cfg) * cfg_cnt, GFP_KERNEL);
if (!cfg) {
dev_err(dev, "failed to alloc memory for configs\n");
goto free_gname;
}
for (idx = 0, cfg_cnt = 0; idx < ARRAY_SIZE(pcfgs); idx++) {
u32 value;
if (!of_property_read_u32(np, pcfgs[idx].prop_cfg, &value))
cfg[cfg_cnt++] =
PINCFG_PACK(pcfgs[idx].cfg_type, value);
}
map[*nmaps].data.configs.group_or_pin = gname;
map[*nmaps].data.configs.configs = cfg;
map[*nmaps].data.configs.num_configs = cfg_cnt;
map[*nmaps].type = PIN_MAP_TYPE_CONFIGS_GROUP;
*nmaps += 1;
skip_cfgs:
if (of_find_property(np, "samsung,pin-function", NULL)) {
fname = kzalloc(strlen(np->name) + FSUFFIX_LEN, GFP_KERNEL);
if (!fname) {
dev_err(dev, "failed to alloc memory for func name\n");
goto free_cfg;
}
sprintf(fname, "%s%s", np->name, FUNCTION_SUFFIX);
map[*nmaps].data.mux.group = gname;
map[*nmaps].data.mux.function = fname;
map[*nmaps].type = PIN_MAP_TYPE_MUX_GROUP;
*nmaps += 1;
}
*maps = map;
return 0;
free_cfg:
kfree(cfg);
free_gname:
kfree(gname);
free_map:
kfree(map);
return -ENOMEM;
}
static void samsung_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map, unsigned num_maps)
{
int idx;
for (idx = 0; idx < num_maps; idx++) {
if (map[idx].type == PIN_MAP_TYPE_MUX_GROUP) {
kfree(map[idx].data.mux.function);
if (!idx)
kfree(map[idx].data.mux.group);
} else if (map->type == PIN_MAP_TYPE_CONFIGS_GROUP) {
kfree(map[idx].data.configs.configs);
if (!idx)
kfree(map[idx].data.configs.group_or_pin);
}
};
kfree(map);
}
static int samsung_get_functions_count(struct pinctrl_dev *pctldev)
{
struct samsung_pinctrl_drv_data *drvdata;
drvdata = pinctrl_dev_get_drvdata(pctldev);
return drvdata->nr_functions;
}
static const char *samsung_pinmux_get_fname(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct samsung_pinctrl_drv_data *drvdata;
drvdata = pinctrl_dev_get_drvdata(pctldev);
return drvdata->pmx_functions[selector].name;
}
static int samsung_pinmux_get_groups(struct pinctrl_dev *pctldev,
unsigned selector, const char * const **groups,
unsigned * const num_groups)
{
struct samsung_pinctrl_drv_data *drvdata;
drvdata = pinctrl_dev_get_drvdata(pctldev);
*groups = drvdata->pmx_functions[selector].groups;
*num_groups = drvdata->pmx_functions[selector].num_groups;
return 0;
}
static void pin_to_reg_bank(struct samsung_pinctrl_drv_data *drvdata,
unsigned pin, void __iomem **reg, u32 *offset,
struct samsung_pin_bank **bank)
{
struct samsung_pin_bank *b;
b = drvdata->ctrl->pin_banks;
while ((pin >= b->pin_base) &&
((b->pin_base + b->nr_pins - 1) < pin))
b++;
*reg = drvdata->virt_base + b->pctl_offset;
*offset = pin - b->pin_base;
if (bank)
*bank = b;
}
static void samsung_pinmux_setup(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group, bool enable)
{
struct samsung_pinctrl_drv_data *drvdata;
const unsigned int *pins;
struct samsung_pin_bank *bank;
void __iomem *reg;
u32 mask, shift, data, pin_offset, cnt;
unsigned long flags;
drvdata = pinctrl_dev_get_drvdata(pctldev);
pins = drvdata->pin_groups[group].pins;
for (cnt = 0; cnt < drvdata->pin_groups[group].num_pins; cnt++) {
struct samsung_pin_bank_type *type;
pin_to_reg_bank(drvdata, pins[cnt] - drvdata->ctrl->base,
&reg, &pin_offset, &bank);
type = bank->type;
mask = (1 << type->fld_width[PINCFG_TYPE_FUNC]) - 1;
shift = pin_offset * type->fld_width[PINCFG_TYPE_FUNC];
if (shift >= 32) {
shift -= 32;
reg += 4;
}
spin_lock_irqsave(&bank->slock, flags);
data = readl(reg + type->reg_offset[PINCFG_TYPE_FUNC]);
data &= ~(mask << shift);
if (enable)
data |= drvdata->pin_groups[group].func << shift;
writel(data, reg + type->reg_offset[PINCFG_TYPE_FUNC]);
spin_unlock_irqrestore(&bank->slock, flags);
}
}
static int samsung_pinmux_enable(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
samsung_pinmux_setup(pctldev, selector, group, true);
return 0;
}
static void samsung_pinmux_disable(struct pinctrl_dev *pctldev,
unsigned selector, unsigned group)
{
samsung_pinmux_setup(pctldev, selector, group, false);
}
static int samsung_pinmux_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range, unsigned offset, bool input)
{
struct samsung_pin_bank_type *type;
struct samsung_pin_bank *bank;
struct samsung_pinctrl_drv_data *drvdata;
void __iomem *reg;
u32 data, pin_offset, mask, shift;
unsigned long flags;
bank = gc_to_pin_bank(range->gc);
type = bank->type;
drvdata = pinctrl_dev_get_drvdata(pctldev);
pin_offset = offset - bank->pin_base;
reg = drvdata->virt_base + bank->pctl_offset +
type->reg_offset[PINCFG_TYPE_FUNC];
mask = (1 << type->fld_width[PINCFG_TYPE_FUNC]) - 1;
shift = pin_offset * type->fld_width[PINCFG_TYPE_FUNC];
if (shift >= 32) {
shift -= 32;
reg += 4;
}
spin_lock_irqsave(&bank->slock, flags);
data = readl(reg);
data &= ~(mask << shift);
if (!input)
data |= FUNC_OUTPUT << shift;
writel(data, reg);
spin_unlock_irqrestore(&bank->slock, flags);
return 0;
}
static int samsung_pinconf_rw(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *config, bool set)
{
struct samsung_pinctrl_drv_data *drvdata;
struct samsung_pin_bank_type *type;
struct samsung_pin_bank *bank;
void __iomem *reg_base;
enum pincfg_type cfg_type = PINCFG_UNPACK_TYPE(*config);
u32 data, width, pin_offset, mask, shift;
u32 cfg_value, cfg_reg;
unsigned long flags;
drvdata = pinctrl_dev_get_drvdata(pctldev);
pin_to_reg_bank(drvdata, pin - drvdata->ctrl->base, &reg_base,
&pin_offset, &bank);
type = bank->type;
if (cfg_type >= PINCFG_TYPE_NUM || !type->fld_width[cfg_type])
return -EINVAL;
width = type->fld_width[cfg_type];
cfg_reg = type->reg_offset[cfg_type];
spin_lock_irqsave(&bank->slock, flags);
mask = (1 << width) - 1;
shift = pin_offset * width;
data = readl(reg_base + cfg_reg);
if (set) {
cfg_value = PINCFG_UNPACK_VALUE(*config);
data &= ~(mask << shift);
data |= (cfg_value << shift);
writel(data, reg_base + cfg_reg);
} else {
data >>= shift;
data &= mask;
*config = PINCFG_PACK(cfg_type, data);
}
spin_unlock_irqrestore(&bank->slock, flags);
return 0;
}
static int samsung_pinconf_set(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *configs, unsigned num_configs)
{
int i, ret;
for (i = 0; i < num_configs; i++) {
ret = samsung_pinconf_rw(pctldev, pin, &configs[i], true);
if (ret < 0)
return ret;
}
return 0;
}
static int samsung_pinconf_get(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *config)
{
return samsung_pinconf_rw(pctldev, pin, config, false);
}
static int samsung_pinconf_group_set(struct pinctrl_dev *pctldev,
unsigned group, unsigned long *configs,
unsigned num_configs)
{
struct samsung_pinctrl_drv_data *drvdata;
const unsigned int *pins;
unsigned int cnt;
drvdata = pinctrl_dev_get_drvdata(pctldev);
pins = drvdata->pin_groups[group].pins;
for (cnt = 0; cnt < drvdata->pin_groups[group].num_pins; cnt++)
samsung_pinconf_set(pctldev, pins[cnt], configs, num_configs);
return 0;
}
static int samsung_pinconf_group_get(struct pinctrl_dev *pctldev,
unsigned int group, unsigned long *config)
{
struct samsung_pinctrl_drv_data *drvdata;
const unsigned int *pins;
drvdata = pinctrl_dev_get_drvdata(pctldev);
pins = drvdata->pin_groups[group].pins;
samsung_pinconf_get(pctldev, pins[0], config);
return 0;
}
static void samsung_gpio_set(struct gpio_chip *gc, unsigned offset, int value)
{
struct samsung_pin_bank *bank = gc_to_pin_bank(gc);
struct samsung_pin_bank_type *type = bank->type;
unsigned long flags;
void __iomem *reg;
u32 data;
reg = bank->drvdata->virt_base + bank->pctl_offset;
spin_lock_irqsave(&bank->slock, flags);
data = readl(reg + type->reg_offset[PINCFG_TYPE_DAT]);
data &= ~(1 << offset);
if (value)
data |= 1 << offset;
writel(data, reg + type->reg_offset[PINCFG_TYPE_DAT]);
spin_unlock_irqrestore(&bank->slock, flags);
}
static int samsung_gpio_get(struct gpio_chip *gc, unsigned offset)
{
void __iomem *reg;
u32 data;
struct samsung_pin_bank *bank = gc_to_pin_bank(gc);
struct samsung_pin_bank_type *type = bank->type;
reg = bank->drvdata->virt_base + bank->pctl_offset;
data = readl(reg + type->reg_offset[PINCFG_TYPE_DAT]);
data >>= offset;
data &= 1;
return data;
}
static int samsung_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
return pinctrl_gpio_direction_input(gc->base + offset);
}
static int samsung_gpio_direction_output(struct gpio_chip *gc, unsigned offset,
int value)
{
samsung_gpio_set(gc, offset, value);
return pinctrl_gpio_direction_output(gc->base + offset);
}
static int samsung_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct samsung_pin_bank *bank = gc_to_pin_bank(gc);
unsigned int virq;
if (!bank->irq_domain)
return -ENXIO;
virq = irq_create_mapping(bank->irq_domain, offset);
return (virq) ? : -ENXIO;
}
static int samsung_pinctrl_parse_dt_pins(struct platform_device *pdev,
struct device_node *cfg_np,
struct pinctrl_desc *pctl,
unsigned int **pin_list,
unsigned int *npins)
{
struct device *dev = &pdev->dev;
struct property *prop;
struct pinctrl_pin_desc const *pdesc = pctl->pins;
unsigned int idx = 0, cnt;
const char *pin_name;
*npins = of_property_count_strings(cfg_np, "samsung,pins");
if (IS_ERR_VALUE(*npins)) {
dev_err(dev, "invalid pin list in %s node", cfg_np->name);
return -EINVAL;
}
*pin_list = devm_kzalloc(dev, *npins * sizeof(**pin_list), GFP_KERNEL);
if (!*pin_list) {
dev_err(dev, "failed to allocate memory for pin list\n");
return -ENOMEM;
}
of_property_for_each_string(cfg_np, "samsung,pins", prop, pin_name) {
for (cnt = 0; cnt < pctl->npins; cnt++) {
if (pdesc[cnt].name) {
if (!strcmp(pin_name, pdesc[cnt].name)) {
(*pin_list)[idx++] = pdesc[cnt].number;
break;
}
}
}
if (cnt == pctl->npins) {
dev_err(dev, "pin %s not valid in %s node\n",
pin_name, cfg_np->name);
devm_kfree(dev, *pin_list);
return -EINVAL;
}
}
return 0;
}
static int samsung_pinctrl_parse_dt(struct platform_device *pdev,
struct samsung_pinctrl_drv_data *drvdata)
{
struct device *dev = &pdev->dev;
struct device_node *dev_np = dev->of_node;
struct device_node *cfg_np;
struct samsung_pin_group *groups, *grp;
struct samsung_pmx_func *functions, *func;
unsigned *pin_list;
unsigned int npins, grp_cnt, func_idx = 0;
char *gname, *fname;
int ret;
grp_cnt = of_get_child_count(dev_np);
if (!grp_cnt)
return -EINVAL;
groups = devm_kzalloc(dev, grp_cnt * sizeof(*groups), GFP_KERNEL);
if (!groups) {
dev_err(dev, "failed allocate memory for ping group list\n");
return -EINVAL;
}
grp = groups;
functions = devm_kzalloc(dev, grp_cnt * sizeof(*functions), GFP_KERNEL);
if (!functions) {
dev_err(dev, "failed to allocate memory for function list\n");
return -EINVAL;
}
func = functions;
for_each_child_of_node(dev_np, cfg_np) {
u32 function;
if (!of_find_property(cfg_np, "samsung,pins", NULL))
continue;
ret = samsung_pinctrl_parse_dt_pins(pdev, cfg_np,
&drvdata->pctl, &pin_list, &npins);
if (ret)
return ret;
gname = devm_kzalloc(dev, strlen(cfg_np->name) + GSUFFIX_LEN,
GFP_KERNEL);
if (!gname) {
dev_err(dev, "failed to alloc memory for group name\n");
return -ENOMEM;
}
sprintf(gname, "%s%s", cfg_np->name, GROUP_SUFFIX);
grp->name = gname;
grp->pins = pin_list;
grp->num_pins = npins;
of_property_read_u32(cfg_np, "samsung,pin-function", &function);
grp->func = function;
grp++;
if (!of_find_property(cfg_np, "samsung,pin-function", NULL))
continue;
fname = devm_kzalloc(dev, strlen(cfg_np->name) + FSUFFIX_LEN,
GFP_KERNEL);
if (!fname) {
dev_err(dev, "failed to alloc memory for func name\n");
return -ENOMEM;
}
sprintf(fname, "%s%s", cfg_np->name, FUNCTION_SUFFIX);
func->name = fname;
func->groups = devm_kzalloc(dev, sizeof(char *), GFP_KERNEL);
if (!func->groups) {
dev_err(dev, "failed to alloc memory for group list "
"in pin function");
return -ENOMEM;
}
func->groups[0] = gname;
func->num_groups = 1;
func++;
func_idx++;
}
drvdata->pin_groups = groups;
drvdata->nr_groups = grp_cnt;
drvdata->pmx_functions = functions;
drvdata->nr_functions = func_idx;
return 0;
}
static int samsung_pinctrl_register(struct platform_device *pdev,
struct samsung_pinctrl_drv_data *drvdata)
{
struct pinctrl_desc *ctrldesc = &drvdata->pctl;
struct pinctrl_pin_desc *pindesc, *pdesc;
struct samsung_pin_bank *pin_bank;
char *pin_names;
int pin, bank, ret;
ctrldesc->name = "samsung-pinctrl";
ctrldesc->owner = THIS_MODULE;
ctrldesc->pctlops = &samsung_pctrl_ops;
ctrldesc->pmxops = &samsung_pinmux_ops;
ctrldesc->confops = &samsung_pinconf_ops;
pindesc = devm_kzalloc(&pdev->dev, sizeof(*pindesc) *
drvdata->ctrl->nr_pins, GFP_KERNEL);
if (!pindesc) {
dev_err(&pdev->dev, "mem alloc for pin descriptors failed\n");
return -ENOMEM;
}
ctrldesc->pins = pindesc;
ctrldesc->npins = drvdata->ctrl->nr_pins;
for (pin = 0, pdesc = pindesc; pin < ctrldesc->npins; pin++, pdesc++)
pdesc->number = pin + drvdata->ctrl->base;
pin_names = devm_kzalloc(&pdev->dev, sizeof(char) * PIN_NAME_LENGTH *
drvdata->ctrl->nr_pins, GFP_KERNEL);
if (!pin_names) {
dev_err(&pdev->dev, "mem alloc for pin names failed\n");
return -ENOMEM;
}
for (bank = 0; bank < drvdata->ctrl->nr_banks; bank++) {
pin_bank = &drvdata->ctrl->pin_banks[bank];
for (pin = 0; pin < pin_bank->nr_pins; pin++) {
sprintf(pin_names, "%s-%d", pin_bank->name, pin);
pdesc = pindesc + pin_bank->pin_base + pin;
pdesc->name = pin_names;
pin_names += PIN_NAME_LENGTH;
}
}
ret = samsung_pinctrl_parse_dt(pdev, drvdata);
if (ret)
return ret;
drvdata->pctl_dev = pinctrl_register(ctrldesc, &pdev->dev, drvdata);
if (!drvdata->pctl_dev) {
dev_err(&pdev->dev, "could not register pinctrl driver\n");
return -EINVAL;
}
for (bank = 0; bank < drvdata->ctrl->nr_banks; ++bank) {
pin_bank = &drvdata->ctrl->pin_banks[bank];
pin_bank->grange.name = pin_bank->name;
pin_bank->grange.id = bank;
pin_bank->grange.pin_base = pin_bank->pin_base;
pin_bank->grange.base = pin_bank->gpio_chip.base;
pin_bank->grange.npins = pin_bank->gpio_chip.ngpio;
pin_bank->grange.gc = &pin_bank->gpio_chip;
pinctrl_add_gpio_range(drvdata->pctl_dev, &pin_bank->grange);
}
return 0;
}
static int samsung_gpiolib_register(struct platform_device *pdev,
struct samsung_pinctrl_drv_data *drvdata)
{
struct samsung_pin_ctrl *ctrl = drvdata->ctrl;
struct samsung_pin_bank *bank = ctrl->pin_banks;
struct gpio_chip *gc;
int ret;
int i;
for (i = 0; i < ctrl->nr_banks; ++i, ++bank) {
bank->gpio_chip = samsung_gpiolib_chip;
gc = &bank->gpio_chip;
gc->base = ctrl->base + bank->pin_base;
gc->ngpio = bank->nr_pins;
gc->dev = &pdev->dev;
gc->of_node = bank->of_node;
gc->label = bank->name;
ret = gpiochip_add(gc);
if (ret) {
dev_err(&pdev->dev, "failed to register gpio_chip %s, error code: %d\n",
gc->label, ret);
goto fail;
}
}
return 0;
fail:
for (--i, --bank; i >= 0; --i, --bank)
if (gpiochip_remove(&bank->gpio_chip))
dev_err(&pdev->dev, "gpio chip %s remove failed\n",
bank->gpio_chip.label);
return ret;
}
static int samsung_gpiolib_unregister(struct platform_device *pdev,
struct samsung_pinctrl_drv_data *drvdata)
{
struct samsung_pin_ctrl *ctrl = drvdata->ctrl;
struct samsung_pin_bank *bank = ctrl->pin_banks;
int ret = 0;
int i;
for (i = 0; !ret && i < ctrl->nr_banks; ++i, ++bank)
ret = gpiochip_remove(&bank->gpio_chip);
if (ret)
dev_err(&pdev->dev, "gpio chip remove failed\n");
return ret;
}
static struct samsung_pin_ctrl *samsung_pinctrl_get_soc_data(
struct samsung_pinctrl_drv_data *d,
struct platform_device *pdev)
{
int id;
const struct of_device_id *match;
struct device_node *node = pdev->dev.of_node;
struct device_node *np;
struct samsung_pin_ctrl *ctrl;
struct samsung_pin_bank *bank;
int i;
id = of_alias_get_id(node, "pinctrl");
if (id < 0) {
dev_err(&pdev->dev, "failed to get alias id\n");
return NULL;
}
match = of_match_node(samsung_pinctrl_dt_match, node);
ctrl = (struct samsung_pin_ctrl *)match->data + id;
bank = ctrl->pin_banks;
for (i = 0; i < ctrl->nr_banks; ++i, ++bank) {
spin_lock_init(&bank->slock);
bank->drvdata = d;
bank->pin_base = ctrl->nr_pins;
ctrl->nr_pins += bank->nr_pins;
}
for_each_child_of_node(node, np) {
if (!of_find_property(np, "gpio-controller", NULL))
continue;
bank = ctrl->pin_banks;
for (i = 0; i < ctrl->nr_banks; ++i, ++bank) {
if (!strcmp(bank->name, np->name)) {
bank->of_node = np;
break;
}
}
}
ctrl->base = pin_base;
pin_base += ctrl->nr_pins;
return ctrl;
}
static int samsung_pinctrl_probe(struct platform_device *pdev)
{
struct samsung_pinctrl_drv_data *drvdata;
struct device *dev = &pdev->dev;
struct samsung_pin_ctrl *ctrl;
struct resource *res;
int ret;
if (!dev->of_node) {
dev_err(dev, "device tree node not found\n");
return -ENODEV;
}
drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata) {
dev_err(dev, "failed to allocate memory for driver's "
"private data\n");
return -ENOMEM;
}
ctrl = samsung_pinctrl_get_soc_data(drvdata, pdev);
if (!ctrl) {
dev_err(&pdev->dev, "driver data not available\n");
return -EINVAL;
}
drvdata->ctrl = ctrl;
drvdata->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
drvdata->virt_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(drvdata->virt_base))
return PTR_ERR(drvdata->virt_base);
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res)
drvdata->irq = res->start;
ret = samsung_gpiolib_register(pdev, drvdata);
if (ret)
return ret;
ret = samsung_pinctrl_register(pdev, drvdata);
if (ret) {
samsung_gpiolib_unregister(pdev, drvdata);
return ret;
}
if (ctrl->eint_gpio_init)
ctrl->eint_gpio_init(drvdata);
if (ctrl->eint_wkup_init)
ctrl->eint_wkup_init(drvdata);
platform_set_drvdata(pdev, drvdata);
list_add_tail(&drvdata->node, &drvdata_list);
return 0;
}
static void samsung_pinctrl_suspend_dev(
struct samsung_pinctrl_drv_data *drvdata)
{
struct samsung_pin_ctrl *ctrl = drvdata->ctrl;
void __iomem *virt_base = drvdata->virt_base;
int i;
for (i = 0; i < ctrl->nr_banks; i++) {
struct samsung_pin_bank *bank = &ctrl->pin_banks[i];
void __iomem *reg = virt_base + bank->pctl_offset;
u8 *offs = bank->type->reg_offset;
u8 *widths = bank->type->fld_width;
enum pincfg_type type;
if (!widths[PINCFG_TYPE_CON_PDN])
continue;
for (type = 0; type < PINCFG_TYPE_NUM; type++)
if (widths[type])
bank->pm_save[type] = readl(reg + offs[type]);
if (widths[PINCFG_TYPE_FUNC] * bank->nr_pins > 32) {
bank->pm_save[PINCFG_TYPE_NUM] =
readl(reg + offs[PINCFG_TYPE_FUNC] + 4);
pr_debug("Save %s @ %p (con %#010x %08x)\n",
bank->name, reg,
bank->pm_save[PINCFG_TYPE_FUNC],
bank->pm_save[PINCFG_TYPE_NUM]);
} else {
pr_debug("Save %s @ %p (con %#010x)\n", bank->name,
reg, bank->pm_save[PINCFG_TYPE_FUNC]);
}
}
if (ctrl->suspend)
ctrl->suspend(drvdata);
}
static void samsung_pinctrl_resume_dev(struct samsung_pinctrl_drv_data *drvdata)
{
struct samsung_pin_ctrl *ctrl = drvdata->ctrl;
void __iomem *virt_base = drvdata->virt_base;
int i;
if (ctrl->resume)
ctrl->resume(drvdata);
for (i = 0; i < ctrl->nr_banks; i++) {
struct samsung_pin_bank *bank = &ctrl->pin_banks[i];
void __iomem *reg = virt_base + bank->pctl_offset;
u8 *offs = bank->type->reg_offset;
u8 *widths = bank->type->fld_width;
enum pincfg_type type;
if (!widths[PINCFG_TYPE_CON_PDN])
continue;
if (widths[PINCFG_TYPE_FUNC] * bank->nr_pins > 32) {
pr_debug("%s @ %p (con %#010x %08x => %#010x %08x)\n",
bank->name, reg,
readl(reg + offs[PINCFG_TYPE_FUNC]),
readl(reg + offs[PINCFG_TYPE_FUNC] + 4),
bank->pm_save[PINCFG_TYPE_FUNC],
bank->pm_save[PINCFG_TYPE_NUM]);
writel(bank->pm_save[PINCFG_TYPE_NUM],
reg + offs[PINCFG_TYPE_FUNC] + 4);
} else {
pr_debug("%s @ %p (con %#010x => %#010x)\n", bank->name,
reg, readl(reg + offs[PINCFG_TYPE_FUNC]),
bank->pm_save[PINCFG_TYPE_FUNC]);
}
for (type = 0; type < PINCFG_TYPE_NUM; type++)
if (widths[type])
writel(bank->pm_save[type], reg + offs[type]);
}
}
static int samsung_pinctrl_suspend(void)
{
struct samsung_pinctrl_drv_data *drvdata;
list_for_each_entry(drvdata, &drvdata_list, node) {
samsung_pinctrl_suspend_dev(drvdata);
}
return 0;
}
static void samsung_pinctrl_resume(void)
{
struct samsung_pinctrl_drv_data *drvdata;
list_for_each_entry_reverse(drvdata, &drvdata_list, node) {
samsung_pinctrl_resume_dev(drvdata);
}
}
static int __init samsung_pinctrl_drv_register(void)
{
register_syscore_ops(&samsung_pinctrl_syscore_ops);
return platform_driver_register(&samsung_pinctrl_driver);
}
static void __exit samsung_pinctrl_drv_unregister(void)
{
platform_driver_unregister(&samsung_pinctrl_driver);
}
