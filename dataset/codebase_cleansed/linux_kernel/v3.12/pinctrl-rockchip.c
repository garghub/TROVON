static inline struct rockchip_pin_bank *gc_to_pin_bank(struct gpio_chip *gc)
{
return container_of(gc, struct rockchip_pin_bank, gpio_chip);
}
static const inline struct rockchip_pin_group *pinctrl_name_to_group(
const struct rockchip_pinctrl *info,
const char *name)
{
int i;
for (i = 0; i < info->ngroups; i++) {
if (!strcmp(info->groups[i].name, name))
return &info->groups[i];
}
return NULL;
}
static struct rockchip_pin_bank *pin_to_bank(struct rockchip_pinctrl *info,
unsigned pin)
{
struct rockchip_pin_bank *b = info->ctrl->pin_banks;
while (pin >= (b->pin_base + b->nr_pins))
b++;
return b;
}
static struct rockchip_pin_bank *bank_num_to_bank(
struct rockchip_pinctrl *info,
unsigned num)
{
struct rockchip_pin_bank *b = info->ctrl->pin_banks;
int i;
for (i = 0; i < info->ctrl->nr_banks; i++, b++) {
if (b->bank_num == num)
return b;
}
return ERR_PTR(-EINVAL);
}
static int rockchip_get_groups_count(struct pinctrl_dev *pctldev)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->ngroups;
}
static const char *rockchip_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->groups[selector].name;
}
static int rockchip_get_group_pins(struct pinctrl_dev *pctldev,
unsigned selector, const unsigned **pins,
unsigned *npins)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
if (selector >= info->ngroups)
return -EINVAL;
*pins = info->groups[selector].pins;
*npins = info->groups[selector].npins;
return 0;
}
static int rockchip_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np,
struct pinctrl_map **map, unsigned *num_maps)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
const struct rockchip_pin_group *grp;
struct pinctrl_map *new_map;
struct device_node *parent;
int map_num = 1;
int i;
grp = pinctrl_name_to_group(info, np->name);
if (!grp) {
dev_err(info->dev, "unable to find group for node %s\n",
np->name);
return -EINVAL;
}
map_num += grp->npins;
new_map = devm_kzalloc(pctldev->dev, sizeof(*new_map) * map_num,
GFP_KERNEL);
if (!new_map)
return -ENOMEM;
*map = new_map;
*num_maps = map_num;
parent = of_get_parent(np);
if (!parent) {
devm_kfree(pctldev->dev, new_map);
return -EINVAL;
}
new_map[0].type = PIN_MAP_TYPE_MUX_GROUP;
new_map[0].data.mux.function = parent->name;
new_map[0].data.mux.group = np->name;
of_node_put(parent);
new_map++;
for (i = 0; i < grp->npins; i++) {
new_map[i].type = PIN_MAP_TYPE_CONFIGS_PIN;
new_map[i].data.configs.group_or_pin =
pin_get_name(pctldev, grp->pins[i]);
new_map[i].data.configs.configs = grp->data[i].configs;
new_map[i].data.configs.num_configs = grp->data[i].nconfigs;
}
dev_dbg(pctldev->dev, "maps: function %s group %s num %d\n",
(*map)->data.mux.function, (*map)->data.mux.group, map_num);
return 0;
}
static void rockchip_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map, unsigned num_maps)
{
}
static void rockchip_set_mux(struct rockchip_pin_bank *bank, int pin, int mux)
{
struct rockchip_pinctrl *info = bank->drvdata;
void __iomem *reg = info->reg_base + info->ctrl->mux_offset;
unsigned long flags;
u8 bit;
u32 data;
dev_dbg(info->dev, "setting mux of GPIO%d-%d to %d\n",
bank->bank_num, pin, mux);
reg += bank->bank_num * 0x10;
reg += (pin / 8) * 4;
bit = (pin % 8) * 2;
spin_lock_irqsave(&bank->slock, flags);
data = (3 << (bit + 16));
data |= (mux & 3) << bit;
writel(data, reg);
spin_unlock_irqrestore(&bank->slock, flags);
}
static int rockchip_get_pull(struct rockchip_pin_bank *bank, int pin_num)
{
struct rockchip_pinctrl *info = bank->drvdata;
struct rockchip_pin_ctrl *ctrl = info->ctrl;
void __iomem *reg;
u8 bit;
if (!ctrl->pull_offset)
return PIN_CONFIG_BIAS_DISABLE;
reg = info->reg_base + ctrl->pull_offset;
if (ctrl->pull_auto) {
reg += bank->bank_num * ctrl->pull_bank_stride;
reg += (pin_num / 16) * 4;
bit = pin_num % 16;
return !(readl_relaxed(reg) & BIT(bit))
? PIN_CONFIG_BIAS_PULL_PIN_DEFAULT
: PIN_CONFIG_BIAS_DISABLE;
} else {
dev_err(info->dev, "pull support for rk31xx not implemented\n");
return -EIO;
}
}
static int rockchip_set_pull(struct rockchip_pin_bank *bank,
int pin_num, int pull)
{
struct rockchip_pinctrl *info = bank->drvdata;
struct rockchip_pin_ctrl *ctrl = info->ctrl;
void __iomem *reg;
unsigned long flags;
u8 bit;
u32 data;
dev_dbg(info->dev, "setting pull of GPIO%d-%d to %d\n",
bank->bank_num, pin_num, pull);
if (!ctrl->pull_offset)
return pull ? -EINVAL : 0;
reg = info->reg_base + ctrl->pull_offset;
if (ctrl->pull_auto) {
if (pull != PIN_CONFIG_BIAS_PULL_PIN_DEFAULT &&
pull != PIN_CONFIG_BIAS_DISABLE) {
dev_err(info->dev, "only PIN_DEFAULT and DISABLE allowed\n");
return -EINVAL;
}
reg += bank->bank_num * ctrl->pull_bank_stride;
reg += (pin_num / 16) * 4;
bit = pin_num % 16;
spin_lock_irqsave(&bank->slock, flags);
data = BIT(bit + 16);
if (pull == PIN_CONFIG_BIAS_DISABLE)
data |= BIT(bit);
writel(data, reg);
spin_unlock_irqrestore(&bank->slock, flags);
} else {
if (pull == PIN_CONFIG_BIAS_PULL_PIN_DEFAULT) {
dev_err(info->dev, "pull direction (up/down) needs to be specified\n");
return -EINVAL;
}
dev_err(info->dev, "pull support for rk31xx not implemented\n");
return -EIO;
}
return 0;
}
static int rockchip_pmx_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->nfunctions;
}
static const char *rockchip_pmx_get_func_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->functions[selector].name;
}
static int rockchip_pmx_get_groups(struct pinctrl_dev *pctldev,
unsigned selector, const char * const **groups,
unsigned * const num_groups)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
*groups = info->functions[selector].groups;
*num_groups = info->functions[selector].ngroups;
return 0;
}
static int rockchip_pmx_enable(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
const unsigned int *pins = info->groups[group].pins;
const struct rockchip_pin_config *data = info->groups[group].data;
struct rockchip_pin_bank *bank;
int cnt;
dev_dbg(info->dev, "enable function %s group %s\n",
info->functions[selector].name, info->groups[group].name);
for (cnt = 0; cnt < info->groups[group].npins; cnt++) {
bank = pin_to_bank(info, pins[cnt]);
rockchip_set_mux(bank, pins[cnt] - bank->pin_base,
data[cnt].func);
}
return 0;
}
static void rockchip_pmx_disable(struct pinctrl_dev *pctldev,
unsigned selector, unsigned group)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
const unsigned int *pins = info->groups[group].pins;
struct rockchip_pin_bank *bank;
int cnt;
dev_dbg(info->dev, "disable function %s group %s\n",
info->functions[selector].name, info->groups[group].name);
for (cnt = 0; cnt < info->groups[group].npins; cnt++) {
bank = pin_to_bank(info, pins[cnt]);
rockchip_set_mux(bank, pins[cnt] - bank->pin_base, 0);
}
}
static int rockchip_pmx_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset, bool input)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
struct rockchip_pin_bank *bank;
struct gpio_chip *chip;
int pin;
u32 data;
chip = range->gc;
bank = gc_to_pin_bank(chip);
pin = offset - chip->base;
dev_dbg(info->dev, "gpio_direction for pin %u as %s-%d to %s\n",
offset, range->name, pin, input ? "input" : "output");
rockchip_set_mux(bank, pin, RK_FUNC_GPIO);
data = readl_relaxed(bank->reg_base + GPIO_SWPORT_DDR);
if (!input)
data |= BIT(pin);
else
data &= ~BIT(pin);
writel_relaxed(data, bank->reg_base + GPIO_SWPORT_DDR);
return 0;
}
static bool rockchip_pinconf_pull_valid(struct rockchip_pin_ctrl *ctrl,
enum pin_config_param pull)
{
if (!ctrl->pull_offset)
return pull ? false : true;
if (ctrl->pull_auto) {
if (pull != PIN_CONFIG_BIAS_PULL_PIN_DEFAULT &&
pull != PIN_CONFIG_BIAS_DISABLE)
return false;
} else {
if (pull == PIN_CONFIG_BIAS_PULL_PIN_DEFAULT)
return false;
}
return true;
}
static int rockchip_pinconf_set(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *configs, unsigned num_configs)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
struct rockchip_pin_bank *bank = pin_to_bank(info, pin);
enum pin_config_param param;
u16 arg;
int i;
int rc;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
rc = rockchip_set_pull(bank, pin - bank->pin_base,
param);
if (rc)
return rc;
break;
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
case PIN_CONFIG_BIAS_PULL_PIN_DEFAULT:
if (!rockchip_pinconf_pull_valid(info->ctrl, param))
return -ENOTSUPP;
if (!arg)
return -EINVAL;
rc = rockchip_set_pull(bank, pin - bank->pin_base,
param);
if (rc)
return rc;
break;
default:
return -ENOTSUPP;
break;
}
}
return 0;
}
static int rockchip_pinconf_get(struct pinctrl_dev *pctldev, unsigned int pin,
unsigned long *config)
{
struct rockchip_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
struct rockchip_pin_bank *bank = pin_to_bank(info, pin);
enum pin_config_param param = pinconf_to_config_param(*config);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
if (rockchip_get_pull(bank, pin - bank->pin_base) != param)
return -EINVAL;
*config = 0;
break;
case PIN_CONFIG_BIAS_PULL_UP:
case PIN_CONFIG_BIAS_PULL_DOWN:
case PIN_CONFIG_BIAS_PULL_PIN_DEFAULT:
if (!rockchip_pinconf_pull_valid(info->ctrl, param))
return -ENOTSUPP;
if (rockchip_get_pull(bank, pin - bank->pin_base) != param)
return -EINVAL;
*config = 1;
break;
default:
return -ENOTSUPP;
break;
}
return 0;
}
static void rockchip_pinctrl_child_count(struct rockchip_pinctrl *info,
struct device_node *np)
{
struct device_node *child;
for_each_child_of_node(np, child) {
if (of_device_is_compatible(child, gpio_compat))
continue;
info->nfunctions++;
info->ngroups += of_get_child_count(child);
}
}
static int rockchip_pinctrl_parse_groups(struct device_node *np,
struct rockchip_pin_group *grp,
struct rockchip_pinctrl *info,
u32 index)
{
struct rockchip_pin_bank *bank;
int size;
const __be32 *list;
int num;
int i, j;
int ret;
dev_dbg(info->dev, "group(%d): %s\n", index, np->name);
grp->name = np->name;
list = of_get_property(np, "rockchip,pins", &size);
size /= sizeof(*list);
if (!size || size % 4) {
dev_err(info->dev, "wrong pins number or pins and configs should be by 4\n");
return -EINVAL;
}
grp->npins = size / 4;
grp->pins = devm_kzalloc(info->dev, grp->npins * sizeof(unsigned int),
GFP_KERNEL);
grp->data = devm_kzalloc(info->dev, grp->npins *
sizeof(struct rockchip_pin_config),
GFP_KERNEL);
if (!grp->pins || !grp->data)
return -ENOMEM;
for (i = 0, j = 0; i < size; i += 4, j++) {
const __be32 *phandle;
struct device_node *np_config;
num = be32_to_cpu(*list++);
bank = bank_num_to_bank(info, num);
if (IS_ERR(bank))
return PTR_ERR(bank);
grp->pins[j] = bank->pin_base + be32_to_cpu(*list++);
grp->data[j].func = be32_to_cpu(*list++);
phandle = list++;
if (!phandle)
return -EINVAL;
np_config = of_find_node_by_phandle(be32_to_cpup(phandle));
ret = pinconf_generic_parse_dt_config(np_config,
&grp->data[j].configs, &grp->data[j].nconfigs);
if (ret)
return ret;
}
return 0;
}
static int rockchip_pinctrl_parse_functions(struct device_node *np,
struct rockchip_pinctrl *info,
u32 index)
{
struct device_node *child;
struct rockchip_pmx_func *func;
struct rockchip_pin_group *grp;
int ret;
static u32 grp_index;
u32 i = 0;
dev_dbg(info->dev, "parse function(%d): %s\n", index, np->name);
func = &info->functions[index];
func->name = np->name;
func->ngroups = of_get_child_count(np);
if (func->ngroups <= 0)
return 0;
func->groups = devm_kzalloc(info->dev,
func->ngroups * sizeof(char *), GFP_KERNEL);
if (!func->groups)
return -ENOMEM;
for_each_child_of_node(np, child) {
func->groups[i] = child->name;
grp = &info->groups[grp_index++];
ret = rockchip_pinctrl_parse_groups(child, grp, info, i++);
if (ret)
return ret;
}
return 0;
}
static int rockchip_pinctrl_parse_dt(struct platform_device *pdev,
struct rockchip_pinctrl *info)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device_node *child;
int ret;
int i;
rockchip_pinctrl_child_count(info, np);
dev_dbg(&pdev->dev, "nfunctions = %d\n", info->nfunctions);
dev_dbg(&pdev->dev, "ngroups = %d\n", info->ngroups);
info->functions = devm_kzalloc(dev, info->nfunctions *
sizeof(struct rockchip_pmx_func),
GFP_KERNEL);
if (!info->functions) {
dev_err(dev, "failed to allocate memory for function list\n");
return -EINVAL;
}
info->groups = devm_kzalloc(dev, info->ngroups *
sizeof(struct rockchip_pin_group),
GFP_KERNEL);
if (!info->groups) {
dev_err(dev, "failed allocate memory for ping group list\n");
return -EINVAL;
}
i = 0;
for_each_child_of_node(np, child) {
if (of_device_is_compatible(child, gpio_compat))
continue;
ret = rockchip_pinctrl_parse_functions(child, info, i++);
if (ret) {
dev_err(&pdev->dev, "failed to parse function\n");
return ret;
}
}
return 0;
}
static int rockchip_pinctrl_register(struct platform_device *pdev,
struct rockchip_pinctrl *info)
{
struct pinctrl_desc *ctrldesc = &info->pctl;
struct pinctrl_pin_desc *pindesc, *pdesc;
struct rockchip_pin_bank *pin_bank;
int pin, bank, ret;
int k;
ctrldesc->name = "rockchip-pinctrl";
ctrldesc->owner = THIS_MODULE;
ctrldesc->pctlops = &rockchip_pctrl_ops;
ctrldesc->pmxops = &rockchip_pmx_ops;
ctrldesc->confops = &rockchip_pinconf_ops;
pindesc = devm_kzalloc(&pdev->dev, sizeof(*pindesc) *
info->ctrl->nr_pins, GFP_KERNEL);
if (!pindesc) {
dev_err(&pdev->dev, "mem alloc for pin descriptors failed\n");
return -ENOMEM;
}
ctrldesc->pins = pindesc;
ctrldesc->npins = info->ctrl->nr_pins;
pdesc = pindesc;
for (bank = 0 , k = 0; bank < info->ctrl->nr_banks; bank++) {
pin_bank = &info->ctrl->pin_banks[bank];
for (pin = 0; pin < pin_bank->nr_pins; pin++, k++) {
pdesc->number = k;
pdesc->name = kasprintf(GFP_KERNEL, "%s-%d",
pin_bank->name, pin);
pdesc++;
}
}
info->pctl_dev = pinctrl_register(ctrldesc, &pdev->dev, info);
if (!info->pctl_dev) {
dev_err(&pdev->dev, "could not register pinctrl driver\n");
return -EINVAL;
}
for (bank = 0; bank < info->ctrl->nr_banks; ++bank) {
pin_bank = &info->ctrl->pin_banks[bank];
pin_bank->grange.name = pin_bank->name;
pin_bank->grange.id = bank;
pin_bank->grange.pin_base = pin_bank->pin_base;
pin_bank->grange.base = pin_bank->gpio_chip.base;
pin_bank->grange.npins = pin_bank->gpio_chip.ngpio;
pin_bank->grange.gc = &pin_bank->gpio_chip;
pinctrl_add_gpio_range(info->pctl_dev, &pin_bank->grange);
}
ret = rockchip_pinctrl_parse_dt(pdev, info);
if (ret) {
pinctrl_unregister(info->pctl_dev);
return ret;
}
return 0;
}
static int rockchip_gpio_request(struct gpio_chip *chip, unsigned offset)
{
return pinctrl_request_gpio(chip->base + offset);
}
static void rockchip_gpio_free(struct gpio_chip *chip, unsigned offset)
{
pinctrl_free_gpio(chip->base + offset);
}
static void rockchip_gpio_set(struct gpio_chip *gc, unsigned offset, int value)
{
struct rockchip_pin_bank *bank = gc_to_pin_bank(gc);
void __iomem *reg = bank->reg_base + GPIO_SWPORT_DR;
unsigned long flags;
u32 data;
spin_lock_irqsave(&bank->slock, flags);
data = readl(reg);
data &= ~BIT(offset);
if (value)
data |= BIT(offset);
writel(data, reg);
spin_unlock_irqrestore(&bank->slock, flags);
}
static int rockchip_gpio_get(struct gpio_chip *gc, unsigned offset)
{
struct rockchip_pin_bank *bank = gc_to_pin_bank(gc);
u32 data;
data = readl(bank->reg_base + GPIO_EXT_PORT);
data >>= offset;
data &= 1;
return data;
}
static int rockchip_gpio_direction_input(struct gpio_chip *gc, unsigned offset)
{
return pinctrl_gpio_direction_input(gc->base + offset);
}
static int rockchip_gpio_direction_output(struct gpio_chip *gc,
unsigned offset, int value)
{
rockchip_gpio_set(gc, offset, value);
return pinctrl_gpio_direction_output(gc->base + offset);
}
static int rockchip_gpio_to_irq(struct gpio_chip *gc, unsigned offset)
{
struct rockchip_pin_bank *bank = gc_to_pin_bank(gc);
unsigned int virq;
if (!bank->domain)
return -ENXIO;
virq = irq_create_mapping(bank->domain, offset);
return (virq) ? : -ENXIO;
}
static void rockchip_irq_demux(unsigned int irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_get_chip(irq);
struct rockchip_pin_bank *bank = irq_get_handler_data(irq);
u32 pend;
dev_dbg(bank->drvdata->dev, "got irq for bank %s\n", bank->name);
chained_irq_enter(chip, desc);
pend = readl_relaxed(bank->reg_base + GPIO_INT_STATUS);
while (pend) {
unsigned int virq;
irq = __ffs(pend);
pend &= ~BIT(irq);
virq = irq_linear_revmap(bank->domain, irq);
if (!virq) {
dev_err(bank->drvdata->dev, "unmapped irq %d\n", irq);
continue;
}
dev_dbg(bank->drvdata->dev, "handling irq %d\n", irq);
generic_handle_irq(virq);
}
chained_irq_exit(chip, desc);
}
static int rockchip_irq_set_type(struct irq_data *d, unsigned int type)
{
struct irq_chip_generic *gc = irq_data_get_irq_chip_data(d);
struct rockchip_pin_bank *bank = gc->private;
u32 mask = BIT(d->hwirq);
u32 polarity;
u32 level;
u32 data;
if (type & IRQ_TYPE_EDGE_BOTH)
__irq_set_handler_locked(d->irq, handle_edge_irq);
else
__irq_set_handler_locked(d->irq, handle_level_irq);
irq_gc_lock(gc);
level = readl_relaxed(gc->reg_base + GPIO_INTTYPE_LEVEL);
polarity = readl_relaxed(gc->reg_base + GPIO_INT_POLARITY);
switch (type) {
case IRQ_TYPE_EDGE_RISING:
level |= mask;
polarity |= mask;
break;
case IRQ_TYPE_EDGE_FALLING:
level |= mask;
polarity &= ~mask;
break;
case IRQ_TYPE_LEVEL_HIGH:
level &= ~mask;
polarity |= mask;
break;
case IRQ_TYPE_LEVEL_LOW:
level &= ~mask;
polarity &= ~mask;
break;
default:
irq_gc_unlock(gc);
return -EINVAL;
}
writel_relaxed(level, gc->reg_base + GPIO_INTTYPE_LEVEL);
writel_relaxed(polarity, gc->reg_base + GPIO_INT_POLARITY);
irq_gc_unlock(gc);
rockchip_set_mux(bank, d->hwirq, RK_FUNC_GPIO);
data = readl_relaxed(bank->reg_base + GPIO_SWPORT_DDR);
data &= ~mask;
writel_relaxed(data, bank->reg_base + GPIO_SWPORT_DDR);
return 0;
}
static int rockchip_interrupts_register(struct platform_device *pdev,
struct rockchip_pinctrl *info)
{
struct rockchip_pin_ctrl *ctrl = info->ctrl;
struct rockchip_pin_bank *bank = ctrl->pin_banks;
unsigned int clr = IRQ_NOREQUEST | IRQ_NOPROBE | IRQ_NOAUTOEN;
struct irq_chip_generic *gc;
int ret;
int i;
for (i = 0; i < ctrl->nr_banks; ++i, ++bank) {
if (!bank->valid) {
dev_warn(&pdev->dev, "bank %s is not valid\n",
bank->name);
continue;
}
bank->domain = irq_domain_add_linear(bank->of_node, 32,
&irq_generic_chip_ops, NULL);
if (!bank->domain) {
dev_warn(&pdev->dev, "could not initialize irq domain for bank %s\n",
bank->name);
continue;
}
ret = irq_alloc_domain_generic_chips(bank->domain, 32, 1,
"rockchip_gpio_irq", handle_level_irq,
clr, 0, IRQ_GC_INIT_MASK_CACHE);
if (ret) {
dev_err(&pdev->dev, "could not alloc generic chips for bank %s\n",
bank->name);
irq_domain_remove(bank->domain);
continue;
}
gc = irq_get_domain_generic_chip(bank->domain, 0);
gc->reg_base = bank->reg_base;
gc->private = bank;
gc->chip_types[0].regs.mask = GPIO_INTEN;
gc->chip_types[0].regs.ack = GPIO_PORTS_EOI;
gc->chip_types[0].chip.irq_ack = irq_gc_ack_set_bit;
gc->chip_types[0].chip.irq_mask = irq_gc_mask_clr_bit;
gc->chip_types[0].chip.irq_unmask = irq_gc_mask_set_bit;
gc->chip_types[0].chip.irq_set_wake = irq_gc_set_wake;
gc->chip_types[0].chip.irq_set_type = rockchip_irq_set_type;
irq_set_handler_data(bank->irq, bank);
irq_set_chained_handler(bank->irq, rockchip_irq_demux);
}
return 0;
}
static int rockchip_gpiolib_register(struct platform_device *pdev,
struct rockchip_pinctrl *info)
{
struct rockchip_pin_ctrl *ctrl = info->ctrl;
struct rockchip_pin_bank *bank = ctrl->pin_banks;
struct gpio_chip *gc;
int ret;
int i;
for (i = 0; i < ctrl->nr_banks; ++i, ++bank) {
if (!bank->valid) {
dev_warn(&pdev->dev, "bank %s is not valid\n",
bank->name);
continue;
}
bank->gpio_chip = rockchip_gpiolib_chip;
gc = &bank->gpio_chip;
gc->base = bank->pin_base;
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
rockchip_interrupts_register(pdev, info);
return 0;
fail:
for (--i, --bank; i >= 0; --i, --bank) {
if (!bank->valid)
continue;
if (gpiochip_remove(&bank->gpio_chip))
dev_err(&pdev->dev, "gpio chip %s remove failed\n",
bank->gpio_chip.label);
}
return ret;
}
static int rockchip_gpiolib_unregister(struct platform_device *pdev,
struct rockchip_pinctrl *info)
{
struct rockchip_pin_ctrl *ctrl = info->ctrl;
struct rockchip_pin_bank *bank = ctrl->pin_banks;
int ret = 0;
int i;
for (i = 0; !ret && i < ctrl->nr_banks; ++i, ++bank) {
if (!bank->valid)
continue;
ret = gpiochip_remove(&bank->gpio_chip);
}
if (ret)
dev_err(&pdev->dev, "gpio chip remove failed\n");
return ret;
}
static int rockchip_get_bank_data(struct rockchip_pin_bank *bank,
struct device *dev)
{
struct resource res;
if (of_address_to_resource(bank->of_node, 0, &res)) {
dev_err(dev, "cannot find IO resource for bank\n");
return -ENOENT;
}
bank->reg_base = devm_ioremap_resource(dev, &res);
if (IS_ERR(bank->reg_base))
return PTR_ERR(bank->reg_base);
bank->irq = irq_of_parse_and_map(bank->of_node, 0);
bank->clk = of_clk_get(bank->of_node, 0);
if (IS_ERR(bank->clk))
return PTR_ERR(bank->clk);
return clk_prepare_enable(bank->clk);
}
static struct rockchip_pin_ctrl *rockchip_pinctrl_get_soc_data(
struct rockchip_pinctrl *d,
struct platform_device *pdev)
{
const struct of_device_id *match;
struct device_node *node = pdev->dev.of_node;
struct device_node *np;
struct rockchip_pin_ctrl *ctrl;
struct rockchip_pin_bank *bank;
int i;
match = of_match_node(rockchip_pinctrl_dt_match, node);
ctrl = (struct rockchip_pin_ctrl *)match->data;
for_each_child_of_node(node, np) {
if (!of_find_property(np, "gpio-controller", NULL))
continue;
bank = ctrl->pin_banks;
for (i = 0; i < ctrl->nr_banks; ++i, ++bank) {
if (!strcmp(bank->name, np->name)) {
bank->of_node = np;
if (!rockchip_get_bank_data(bank, &pdev->dev))
bank->valid = true;
break;
}
}
}
bank = ctrl->pin_banks;
for (i = 0; i < ctrl->nr_banks; ++i, ++bank) {
spin_lock_init(&bank->slock);
bank->drvdata = d;
bank->pin_base = ctrl->nr_pins;
ctrl->nr_pins += bank->nr_pins;
}
return ctrl;
}
static int rockchip_pinctrl_probe(struct platform_device *pdev)
{
struct rockchip_pinctrl *info;
struct device *dev = &pdev->dev;
struct rockchip_pin_ctrl *ctrl;
struct resource *res;
int ret;
if (!dev->of_node) {
dev_err(dev, "device tree node not found\n");
return -ENODEV;
}
info = devm_kzalloc(dev, sizeof(struct rockchip_pinctrl), GFP_KERNEL);
if (!info)
return -ENOMEM;
ctrl = rockchip_pinctrl_get_soc_data(info, pdev);
if (!ctrl) {
dev_err(dev, "driver data not available\n");
return -EINVAL;
}
info->ctrl = ctrl;
info->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
info->reg_base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(info->reg_base))
return PTR_ERR(info->reg_base);
ret = rockchip_gpiolib_register(pdev, info);
if (ret)
return ret;
ret = rockchip_pinctrl_register(pdev, info);
if (ret) {
rockchip_gpiolib_unregister(pdev, info);
return ret;
}
platform_set_drvdata(pdev, info);
return 0;
}
static int __init rockchip_pinctrl_drv_register(void)
{
return platform_driver_register(&rockchip_pinctrl_driver);
}
