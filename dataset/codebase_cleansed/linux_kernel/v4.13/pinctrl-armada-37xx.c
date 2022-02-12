static inline void armada_37xx_update_reg(unsigned int *reg,
unsigned int offset)
{
if (offset >= GPIO_PER_REG) {
offset -= GPIO_PER_REG;
*reg += sizeof(u32);
}
}
static int armada_37xx_get_func_reg(struct armada_37xx_pin_group *grp,
const char *func)
{
int f;
for (f = 0; (f < NB_FUNCS) && grp->funcs[f]; f++)
if (!strcmp(grp->funcs[f], func))
return f;
return -ENOTSUPP;
}
static struct armada_37xx_pin_group *armada_37xx_find_next_grp_by_pin(
struct armada_37xx_pinctrl *info, int pin, int *grp)
{
while (*grp < info->ngroups) {
struct armada_37xx_pin_group *group = &info->groups[*grp];
int j;
*grp = *grp + 1;
for (j = 0; j < (group->npins + group->extra_npins); j++)
if (group->pins[j] == pin)
return group;
}
return NULL;
}
static int armada_37xx_pin_config_group_get(struct pinctrl_dev *pctldev,
unsigned int selector, unsigned long *config)
{
return -ENOTSUPP;
}
static int armada_37xx_pin_config_group_set(struct pinctrl_dev *pctldev,
unsigned int selector, unsigned long *configs,
unsigned int num_configs)
{
return -ENOTSUPP;
}
static int armada_37xx_get_groups_count(struct pinctrl_dev *pctldev)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->ngroups;
}
static const char *armada_37xx_get_group_name(struct pinctrl_dev *pctldev,
unsigned int group)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->groups[group].name;
}
static int armada_37xx_get_group_pins(struct pinctrl_dev *pctldev,
unsigned int selector,
const unsigned int **pins,
unsigned int *npins)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
if (selector >= info->ngroups)
return -EINVAL;
*pins = info->groups[selector].pins;
*npins = info->groups[selector].npins +
info->groups[selector].extra_npins;
return 0;
}
static int armada_37xx_pmx_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->nfuncs;
}
static const char *armada_37xx_pmx_get_func_name(struct pinctrl_dev *pctldev,
unsigned int selector)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->funcs[selector].name;
}
static int armada_37xx_pmx_get_groups(struct pinctrl_dev *pctldev,
unsigned int selector,
const char * const **groups,
unsigned int * const num_groups)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
*groups = info->funcs[selector].groups;
*num_groups = info->funcs[selector].ngroups;
return 0;
}
static int armada_37xx_pmx_set_by_name(struct pinctrl_dev *pctldev,
const char *name,
struct armada_37xx_pin_group *grp)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
unsigned int reg = SELECTION;
unsigned int mask = grp->reg_mask;
int func, val;
dev_dbg(info->dev, "enable function %s group %s\n",
name, grp->name);
func = armada_37xx_get_func_reg(grp, name);
if (func < 0)
return func;
val = grp->val[func];
regmap_update_bits(info->regmap, reg, mask, val);
return 0;
}
static int armada_37xx_pmx_set(struct pinctrl_dev *pctldev,
unsigned int selector,
unsigned int group)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
struct armada_37xx_pin_group *grp = &info->groups[group];
const char *name = info->funcs[selector].name;
return armada_37xx_pmx_set_by_name(pctldev, name, grp);
}
static inline void armada_37xx_irq_update_reg(unsigned int *reg,
struct irq_data *d)
{
int offset = irqd_to_hwirq(d);
armada_37xx_update_reg(reg, offset);
}
static int armada_37xx_gpio_direction_input(struct gpio_chip *chip,
unsigned int offset)
{
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
unsigned int reg = OUTPUT_EN;
unsigned int mask;
armada_37xx_update_reg(&reg, offset);
mask = BIT(offset);
return regmap_update_bits(info->regmap, reg, mask, 0);
}
static int armada_37xx_gpio_get_direction(struct gpio_chip *chip,
unsigned int offset)
{
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
unsigned int reg = OUTPUT_EN;
unsigned int val, mask;
armada_37xx_update_reg(&reg, offset);
mask = BIT(offset);
regmap_read(info->regmap, reg, &val);
return !(val & mask);
}
static int armada_37xx_gpio_direction_output(struct gpio_chip *chip,
unsigned int offset, int value)
{
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
unsigned int reg = OUTPUT_EN;
unsigned int mask;
armada_37xx_update_reg(&reg, offset);
mask = BIT(offset);
return regmap_update_bits(info->regmap, reg, mask, mask);
}
static int armada_37xx_gpio_get(struct gpio_chip *chip, unsigned int offset)
{
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
unsigned int reg = INPUT_VAL;
unsigned int val, mask;
armada_37xx_update_reg(&reg, offset);
mask = BIT(offset);
regmap_read(info->regmap, reg, &val);
return (val & mask) != 0;
}
static void armada_37xx_gpio_set(struct gpio_chip *chip, unsigned int offset,
int value)
{
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
unsigned int reg = OUTPUT_VAL;
unsigned int mask, val;
armada_37xx_update_reg(&reg, offset);
mask = BIT(offset);
val = value ? mask : 0;
regmap_update_bits(info->regmap, reg, mask, val);
}
static int armada_37xx_pmx_gpio_set_direction(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int offset, bool input)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
struct gpio_chip *chip = range->gc;
dev_dbg(info->dev, "gpio_direction for pin %u as %s-%d to %s\n",
offset, range->name, offset, input ? "input" : "output");
if (input)
armada_37xx_gpio_direction_input(chip, offset);
else
armada_37xx_gpio_direction_output(chip, offset, 0);
return 0;
}
static int armada_37xx_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned int offset)
{
struct armada_37xx_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
struct armada_37xx_pin_group *group;
int grp = 0;
dev_dbg(info->dev, "requesting gpio %d\n", offset);
while ((group = armada_37xx_find_next_grp_by_pin(info, offset, &grp)))
armada_37xx_pmx_set_by_name(pctldev, "gpio", group);
return 0;
}
static void armada_37xx_irq_ack(struct irq_data *d)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
u32 reg = IRQ_STATUS;
unsigned long flags;
armada_37xx_irq_update_reg(&reg, d);
spin_lock_irqsave(&info->irq_lock, flags);
writel(d->mask, info->base + reg);
spin_unlock_irqrestore(&info->irq_lock, flags);
}
static void armada_37xx_irq_mask(struct irq_data *d)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
u32 val, reg = IRQ_EN;
unsigned long flags;
armada_37xx_irq_update_reg(&reg, d);
spin_lock_irqsave(&info->irq_lock, flags);
val = readl(info->base + reg);
writel(val & ~d->mask, info->base + reg);
spin_unlock_irqrestore(&info->irq_lock, flags);
}
static void armada_37xx_irq_unmask(struct irq_data *d)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
u32 val, reg = IRQ_EN;
unsigned long flags;
armada_37xx_irq_update_reg(&reg, d);
spin_lock_irqsave(&info->irq_lock, flags);
val = readl(info->base + reg);
writel(val | d->mask, info->base + reg);
spin_unlock_irqrestore(&info->irq_lock, flags);
}
static int armada_37xx_irq_set_wake(struct irq_data *d, unsigned int on)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
u32 val, reg = IRQ_WKUP;
unsigned long flags;
armada_37xx_irq_update_reg(&reg, d);
spin_lock_irqsave(&info->irq_lock, flags);
val = readl(info->base + reg);
if (on)
val |= d->mask;
else
val &= ~d->mask;
writel(val, info->base + reg);
spin_unlock_irqrestore(&info->irq_lock, flags);
return 0;
}
static int armada_37xx_irq_set_type(struct irq_data *d, unsigned int type)
{
struct gpio_chip *chip = irq_data_get_irq_chip_data(d);
struct armada_37xx_pinctrl *info = gpiochip_get_data(chip);
u32 val, reg = IRQ_POL;
unsigned long flags;
spin_lock_irqsave(&info->irq_lock, flags);
armada_37xx_irq_update_reg(&reg, d);
val = readl(info->base + reg);
switch (type) {
case IRQ_TYPE_EDGE_RISING:
val &= ~d->mask;
break;
case IRQ_TYPE_EDGE_FALLING:
val |= d->mask;
break;
default:
spin_unlock_irqrestore(&info->irq_lock, flags);
return -EINVAL;
}
writel(val, info->base + reg);
spin_unlock_irqrestore(&info->irq_lock, flags);
return 0;
}
static void armada_37xx_irq_handler(struct irq_desc *desc)
{
struct gpio_chip *gc = irq_desc_get_handler_data(desc);
struct irq_chip *chip = irq_desc_get_chip(desc);
struct armada_37xx_pinctrl *info = gpiochip_get_data(gc);
struct irq_domain *d = gc->irqdomain;
int i;
chained_irq_enter(chip, desc);
for (i = 0; i <= d->revmap_size / GPIO_PER_REG; i++) {
u32 status;
unsigned long flags;
spin_lock_irqsave(&info->irq_lock, flags);
status = readl_relaxed(info->base + IRQ_STATUS + 4 * i);
status &= readl_relaxed(info->base + IRQ_EN + 4 * i);
spin_unlock_irqrestore(&info->irq_lock, flags);
while (status) {
u32 hwirq = ffs(status) - 1;
u32 virq = irq_find_mapping(d, hwirq +
i * GPIO_PER_REG);
generic_handle_irq(virq);
spin_lock_irqsave(&info->irq_lock, flags);
status = readl_relaxed(info->base +
IRQ_STATUS + 4 * i);
status &= readl_relaxed(info->base + IRQ_EN + 4 * i);
spin_unlock_irqrestore(&info->irq_lock, flags);
}
}
chained_irq_exit(chip, desc);
}
static int armada_37xx_irqchip_register(struct platform_device *pdev,
struct armada_37xx_pinctrl *info)
{
struct device_node *np = info->dev->of_node;
int nrirqs = info->data->nr_pins;
struct gpio_chip *gc = &info->gpio_chip;
struct irq_chip *irqchip = &info->irq_chip;
struct resource res;
int ret = -ENODEV, i, nr_irq_parent;
for_each_child_of_node(info->dev->of_node, np) {
if (of_property_read_bool(np, "gpio-controller")) {
ret = 0;
break;
}
};
if (ret)
return ret;
nr_irq_parent = of_irq_count(np);
spin_lock_init(&info->irq_lock);
if (!nr_irq_parent) {
dev_err(&pdev->dev, "Invalid or no IRQ\n");
return 0;
}
if (of_address_to_resource(info->dev->of_node, 1, &res)) {
dev_err(info->dev, "cannot find IO resource\n");
return -ENOENT;
}
info->base = devm_ioremap_resource(info->dev, &res);
if (IS_ERR(info->base))
return PTR_ERR(info->base);
irqchip->irq_ack = armada_37xx_irq_ack;
irqchip->irq_mask = armada_37xx_irq_mask;
irqchip->irq_unmask = armada_37xx_irq_unmask;
irqchip->irq_set_wake = armada_37xx_irq_set_wake;
irqchip->irq_set_type = armada_37xx_irq_set_type;
irqchip->name = info->data->name;
ret = gpiochip_irqchip_add(gc, irqchip, 0,
handle_edge_irq, IRQ_TYPE_NONE);
if (ret) {
dev_info(&pdev->dev, "could not add irqchip\n");
return ret;
}
for (i = 0; i < nrirqs; i++) {
struct irq_data *d = irq_get_irq_data(gc->irq_base + i);
d->mask = BIT(i % GPIO_PER_REG);
}
for (i = 0; i < nr_irq_parent; i++) {
int irq = irq_of_parse_and_map(np, i);
if (irq < 0)
continue;
gpiochip_set_chained_irqchip(gc, irqchip, irq,
armada_37xx_irq_handler);
}
return 0;
}
static int armada_37xx_gpiochip_register(struct platform_device *pdev,
struct armada_37xx_pinctrl *info)
{
struct device_node *np;
struct gpio_chip *gc;
int ret = -ENODEV;
for_each_child_of_node(info->dev->of_node, np) {
if (of_find_property(np, "gpio-controller", NULL)) {
ret = 0;
break;
}
};
if (ret)
return ret;
info->gpio_chip = armada_37xx_gpiolib_chip;
gc = &info->gpio_chip;
gc->ngpio = info->data->nr_pins;
gc->parent = &pdev->dev;
gc->base = -1;
gc->of_node = np;
gc->label = info->data->name;
ret = devm_gpiochip_add_data(&pdev->dev, gc, info);
if (ret)
return ret;
ret = armada_37xx_irqchip_register(pdev, info);
if (ret)
return ret;
return 0;
}
static int armada_37xx_add_function(struct armada_37xx_pmx_func *funcs,
int *funcsize, const char *name)
{
int i = 0;
if (*funcsize <= 0)
return -EOVERFLOW;
while (funcs->ngroups) {
if (strcmp(funcs->name, name) == 0) {
funcs->ngroups++;
return -EEXIST;
}
funcs++;
i++;
}
funcs->name = name;
funcs->ngroups = 1;
(*funcsize)--;
return 0;
}
static int armada_37xx_fill_group(struct armada_37xx_pinctrl *info)
{
int n, num = 0, funcsize = info->data->nr_pins;
for (n = 0; n < info->ngroups; n++) {
struct armada_37xx_pin_group *grp = &info->groups[n];
int i, j, f;
grp->pins = devm_kzalloc(info->dev,
(grp->npins + grp->extra_npins) *
sizeof(*grp->pins), GFP_KERNEL);
if (!grp->pins)
return -ENOMEM;
for (i = 0; i < grp->npins; i++)
grp->pins[i] = grp->start_pin + i;
for (j = 0; j < grp->extra_npins; j++)
grp->pins[i+j] = grp->extra_pin + j;
for (f = 0; (f < NB_FUNCS) && grp->funcs[f]; f++) {
int ret;
ret = armada_37xx_add_function(info->funcs, &funcsize,
grp->funcs[f]);
if (ret == -EOVERFLOW)
dev_err(info->dev,
"More functions than pins(%d)\n",
info->data->nr_pins);
if (ret < 0)
continue;
num++;
}
}
info->nfuncs = num;
return 0;
}
static int armada_37xx_fill_func(struct armada_37xx_pinctrl *info)
{
struct armada_37xx_pmx_func *funcs = info->funcs;
int n;
for (n = 0; n < info->nfuncs; n++) {
const char *name = funcs[n].name;
const char **groups;
int g;
funcs[n].groups = devm_kzalloc(info->dev, funcs[n].ngroups *
sizeof(*(funcs[n].groups)),
GFP_KERNEL);
if (!funcs[n].groups)
return -ENOMEM;
groups = funcs[n].groups;
for (g = 0; g < info->ngroups; g++) {
struct armada_37xx_pin_group *gp = &info->groups[g];
int f;
for (f = 0; (f < NB_FUNCS) && gp->funcs[f]; f++) {
if (strcmp(gp->funcs[f], name) == 0) {
*groups = gp->name;
groups++;
}
}
}
}
return 0;
}
static int armada_37xx_pinctrl_register(struct platform_device *pdev,
struct armada_37xx_pinctrl *info)
{
const struct armada_37xx_pin_data *pin_data = info->data;
struct pinctrl_desc *ctrldesc = &info->pctl;
struct pinctrl_pin_desc *pindesc, *pdesc;
int pin, ret;
info->groups = pin_data->groups;
info->ngroups = pin_data->ngroups;
ctrldesc->name = "armada_37xx-pinctrl";
ctrldesc->owner = THIS_MODULE;
ctrldesc->pctlops = &armada_37xx_pctrl_ops;
ctrldesc->pmxops = &armada_37xx_pmx_ops;
ctrldesc->confops = &armada_37xx_pinconf_ops;
pindesc = devm_kzalloc(&pdev->dev, sizeof(*pindesc) *
pin_data->nr_pins, GFP_KERNEL);
if (!pindesc)
return -ENOMEM;
ctrldesc->pins = pindesc;
ctrldesc->npins = pin_data->nr_pins;
pdesc = pindesc;
for (pin = 0; pin < pin_data->nr_pins; pin++) {
pdesc->number = pin;
pdesc->name = kasprintf(GFP_KERNEL, "%s-%d",
pin_data->name, pin);
pdesc++;
}
info->funcs = devm_kzalloc(&pdev->dev, pin_data->nr_pins *
sizeof(struct armada_37xx_pmx_func), GFP_KERNEL);
if (!info->funcs)
return -ENOMEM;
ret = armada_37xx_fill_group(info);
if (ret)
return ret;
ret = armada_37xx_fill_func(info);
if (ret)
return ret;
info->pctl_dev = devm_pinctrl_register(&pdev->dev, ctrldesc, info);
if (IS_ERR(info->pctl_dev)) {
dev_err(&pdev->dev, "could not register pinctrl driver\n");
return PTR_ERR(info->pctl_dev);
}
return 0;
}
static int __init armada_37xx_pinctrl_probe(struct platform_device *pdev)
{
struct armada_37xx_pinctrl *info;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct regmap *regmap;
int ret;
info = devm_kzalloc(dev, sizeof(struct armada_37xx_pinctrl),
GFP_KERNEL);
if (!info)
return -ENOMEM;
info->dev = dev;
regmap = syscon_node_to_regmap(np);
if (IS_ERR(regmap)) {
dev_err(&pdev->dev, "cannot get regmap\n");
return PTR_ERR(regmap);
}
info->regmap = regmap;
info->data = of_device_get_match_data(dev);
ret = armada_37xx_pinctrl_register(pdev, info);
if (ret)
return ret;
ret = armada_37xx_gpiochip_register(pdev, info);
if (ret)
return ret;
platform_set_drvdata(pdev, info);
return 0;
}
