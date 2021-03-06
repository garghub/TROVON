static const inline struct at91_pin_group *at91_pinctrl_find_group_by_name(
const struct at91_pinctrl *info,
const char *name)
{
const struct at91_pin_group *grp = NULL;
int i;
for (i = 0; i < info->ngroups; i++) {
if (strcmp(info->groups[i].name, name))
continue;
grp = &info->groups[i];
dev_dbg(info->dev, "%s: %d 0:%d\n", name, grp->npins, grp->pins[0]);
break;
}
return grp;
}
static int at91_get_groups_count(struct pinctrl_dev *pctldev)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->ngroups;
}
static const char *at91_get_group_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->groups[selector].name;
}
static int at91_get_group_pins(struct pinctrl_dev *pctldev, unsigned selector,
const unsigned **pins,
unsigned *npins)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
if (selector >= info->ngroups)
return -EINVAL;
*pins = info->groups[selector].pins;
*npins = info->groups[selector].npins;
return 0;
}
static void at91_pin_dbg_show(struct pinctrl_dev *pctldev, struct seq_file *s,
unsigned offset)
{
seq_printf(s, "%s", dev_name(pctldev->dev));
}
static int at91_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np,
struct pinctrl_map **map, unsigned *num_maps)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
const struct at91_pin_group *grp;
struct pinctrl_map *new_map;
struct device_node *parent;
int map_num = 1;
int i;
grp = at91_pinctrl_find_group_by_name(info, np->name);
if (!grp) {
dev_err(info->dev, "unable to find group for node %s\n",
np->name);
return -EINVAL;
}
map_num += grp->npins;
new_map = devm_kzalloc(pctldev->dev, sizeof(*new_map) * map_num, GFP_KERNEL);
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
new_map[i].data.configs.configs = &grp->pins_conf[i].conf;
new_map[i].data.configs.num_configs = 1;
}
dev_dbg(pctldev->dev, "maps: function %s group %s num %d\n",
(*map)->data.mux.function, (*map)->data.mux.group, map_num);
return 0;
}
static void at91_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map, unsigned num_maps)
{
}
static void __iomem * pin_to_controller(struct at91_pinctrl *info,
unsigned int bank)
{
return gpio_chips[bank]->regbase;
}
static inline int pin_to_bank(unsigned pin)
{
return pin /= MAX_NB_GPIO_PER_BANK;
}
static unsigned pin_to_mask(unsigned int pin)
{
return 1 << pin;
}
static void at91_mux_disable_interrupt(void __iomem *pio, unsigned mask)
{
writel_relaxed(mask, pio + PIO_IDR);
}
static unsigned at91_mux_get_pullup(void __iomem *pio, unsigned pin)
{
return (readl_relaxed(pio + PIO_PUSR) >> pin) & 0x1;
}
static void at91_mux_set_pullup(void __iomem *pio, unsigned mask, bool on)
{
writel_relaxed(mask, pio + (on ? PIO_PUER : PIO_PUDR));
}
static unsigned at91_mux_get_multidrive(void __iomem *pio, unsigned pin)
{
return (readl_relaxed(pio + PIO_MDSR) >> pin) & 0x1;
}
static void at91_mux_set_multidrive(void __iomem *pio, unsigned mask, bool on)
{
writel_relaxed(mask, pio + (on ? PIO_MDER : PIO_MDDR));
}
static void at91_mux_set_A_periph(void __iomem *pio, unsigned mask)
{
writel_relaxed(mask, pio + PIO_ASR);
}
static void at91_mux_set_B_periph(void __iomem *pio, unsigned mask)
{
writel_relaxed(mask, pio + PIO_BSR);
}
static void at91_mux_pio3_set_A_periph(void __iomem *pio, unsigned mask)
{
writel_relaxed(readl_relaxed(pio + PIO_ABCDSR1) & ~mask,
pio + PIO_ABCDSR1);
writel_relaxed(readl_relaxed(pio + PIO_ABCDSR2) & ~mask,
pio + PIO_ABCDSR2);
}
static void at91_mux_pio3_set_B_periph(void __iomem *pio, unsigned mask)
{
writel_relaxed(readl_relaxed(pio + PIO_ABCDSR1) | mask,
pio + PIO_ABCDSR1);
writel_relaxed(readl_relaxed(pio + PIO_ABCDSR2) & ~mask,
pio + PIO_ABCDSR2);
}
static void at91_mux_pio3_set_C_periph(void __iomem *pio, unsigned mask)
{
writel_relaxed(readl_relaxed(pio + PIO_ABCDSR1) & ~mask, pio + PIO_ABCDSR1);
writel_relaxed(readl_relaxed(pio + PIO_ABCDSR2) | mask, pio + PIO_ABCDSR2);
}
static void at91_mux_pio3_set_D_periph(void __iomem *pio, unsigned mask)
{
writel_relaxed(readl_relaxed(pio + PIO_ABCDSR1) | mask, pio + PIO_ABCDSR1);
writel_relaxed(readl_relaxed(pio + PIO_ABCDSR2) | mask, pio + PIO_ABCDSR2);
}
static enum at91_mux at91_mux_pio3_get_periph(void __iomem *pio, unsigned mask)
{
unsigned select;
if (readl_relaxed(pio + PIO_PSR) & mask)
return AT91_MUX_GPIO;
select = !!(readl_relaxed(pio + PIO_ABCDSR1) & mask);
select |= (!!(readl_relaxed(pio + PIO_ABCDSR2) & mask) << 1);
return select + 1;
}
static enum at91_mux at91_mux_get_periph(void __iomem *pio, unsigned mask)
{
unsigned select;
if (readl_relaxed(pio + PIO_PSR) & mask)
return AT91_MUX_GPIO;
select = readl_relaxed(pio + PIO_ABSR) & mask;
return select + 1;
}
static bool at91_mux_get_deglitch(void __iomem *pio, unsigned pin)
{
return (__raw_readl(pio + PIO_IFSR) >> pin) & 0x1;
}
static void at91_mux_set_deglitch(void __iomem *pio, unsigned mask, bool is_on)
{
__raw_writel(mask, pio + (is_on ? PIO_IFER : PIO_IFDR));
}
static void at91_mux_pio3_set_deglitch(void __iomem *pio, unsigned mask, bool is_on)
{
if (is_on)
__raw_writel(mask, pio + PIO_IFSCDR);
at91_mux_set_deglitch(pio, mask, is_on);
}
static bool at91_mux_pio3_get_debounce(void __iomem *pio, unsigned pin, u32 *div)
{
*div = __raw_readl(pio + PIO_SCDR);
return (__raw_readl(pio + PIO_IFSCSR) >> pin) & 0x1;
}
static void at91_mux_pio3_set_debounce(void __iomem *pio, unsigned mask,
bool is_on, u32 div)
{
if (is_on) {
__raw_writel(mask, pio + PIO_IFSCER);
__raw_writel(div & PIO_SCDR_DIV, pio + PIO_SCDR);
__raw_writel(mask, pio + PIO_IFER);
} else {
__raw_writel(mask, pio + PIO_IFDR);
}
}
static bool at91_mux_pio3_get_pulldown(void __iomem *pio, unsigned pin)
{
return (__raw_readl(pio + PIO_PPDSR) >> pin) & 0x1;
}
static void at91_mux_pio3_set_pulldown(void __iomem *pio, unsigned mask, bool is_on)
{
__raw_writel(mask, pio + (is_on ? PIO_PPDER : PIO_PPDDR));
}
static void at91_mux_pio3_disable_schmitt_trig(void __iomem *pio, unsigned mask)
{
__raw_writel(__raw_readl(pio + PIO_SCHMITT) | mask, pio + PIO_SCHMITT);
}
static bool at91_mux_pio3_get_schmitt_trig(void __iomem *pio, unsigned pin)
{
return (__raw_readl(pio + PIO_SCHMITT) >> pin) & 0x1;
}
static void at91_pin_dbg(const struct device *dev, const struct at91_pmx_pin *pin)
{
if (pin->mux) {
dev_dbg(dev, "pio%c%d configured as periph%c with conf = 0x%lu\n",
pin->bank + 'A', pin->pin, pin->mux - 1 + 'A', pin->conf);
} else {
dev_dbg(dev, "pio%c%d configured as gpio with conf = 0x%lu\n",
pin->bank + 'A', pin->pin, pin->conf);
}
}
static int pin_check_config(struct at91_pinctrl *info, const char* name,
int index, const struct at91_pmx_pin *pin)
{
int mux;
if (pin->bank >= info->nbanks) {
dev_err(info->dev, "%s: pin conf %d bank_id %d >= nbanks %d\n",
name, index, pin->bank, info->nbanks);
return -EINVAL;
}
if (pin->pin >= MAX_NB_GPIO_PER_BANK) {
dev_err(info->dev, "%s: pin conf %d pin_bank_id %d >= %d\n",
name, index, pin->pin, MAX_NB_GPIO_PER_BANK);
return -EINVAL;
}
if (!pin->mux)
return 0;
mux = pin->mux - 1;
if (mux >= info->nmux) {
dev_err(info->dev, "%s: pin conf %d mux_id %d >= nmux %d\n",
name, index, mux, info->nmux);
return -EINVAL;
}
if (!(info->mux_mask[pin->bank * info->nmux + mux] & 1 << pin->pin)) {
dev_err(info->dev, "%s: pin conf %d mux_id %d not supported for pio%c%d\n",
name, index, mux, pin->bank + 'A', pin->pin);
return -EINVAL;
}
return 0;
}
static void at91_mux_gpio_disable(void __iomem *pio, unsigned mask)
{
writel_relaxed(mask, pio + PIO_PDR);
}
static void at91_mux_gpio_enable(void __iomem *pio, unsigned mask, bool input)
{
writel_relaxed(mask, pio + PIO_PER);
writel_relaxed(mask, pio + (input ? PIO_ODR : PIO_OER));
}
static int at91_pmx_enable(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
const struct at91_pmx_pin *pins_conf = info->groups[group].pins_conf;
const struct at91_pmx_pin *pin;
uint32_t npins = info->groups[group].npins;
int i, ret;
unsigned mask;
void __iomem *pio;
dev_dbg(info->dev, "enable function %s group %s\n",
info->functions[selector].name, info->groups[group].name);
for (i = 0; i < npins; i++) {
pin = &pins_conf[i];
ret = pin_check_config(info, info->groups[group].name, i, pin);
if (ret)
return ret;
}
for (i = 0; i < npins; i++) {
pin = &pins_conf[i];
at91_pin_dbg(info->dev, pin);
pio = pin_to_controller(info, pin->bank);
mask = pin_to_mask(pin->pin);
at91_mux_disable_interrupt(pio, mask);
switch(pin->mux) {
case AT91_MUX_GPIO:
at91_mux_gpio_enable(pio, mask, 1);
break;
case AT91_MUX_PERIPH_A:
info->ops->mux_A_periph(pio, mask);
break;
case AT91_MUX_PERIPH_B:
info->ops->mux_B_periph(pio, mask);
break;
case AT91_MUX_PERIPH_C:
if (!info->ops->mux_C_periph)
return -EINVAL;
info->ops->mux_C_periph(pio, mask);
break;
case AT91_MUX_PERIPH_D:
if (!info->ops->mux_D_periph)
return -EINVAL;
info->ops->mux_D_periph(pio, mask);
break;
}
if (pin->mux)
at91_mux_gpio_disable(pio, mask);
}
return 0;
}
static void at91_pmx_disable(struct pinctrl_dev *pctldev, unsigned selector,
unsigned group)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
const struct at91_pmx_pin *pins_conf = info->groups[group].pins_conf;
const struct at91_pmx_pin *pin;
uint32_t npins = info->groups[group].npins;
int i;
unsigned mask;
void __iomem *pio;
for (i = 0; i < npins; i++) {
pin = &pins_conf[i];
at91_pin_dbg(info->dev, pin);
pio = pin_to_controller(info, pin->bank);
mask = pin_to_mask(pin->pin);
at91_mux_gpio_enable(pio, mask, 1);
}
}
static int at91_pmx_get_funcs_count(struct pinctrl_dev *pctldev)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->nfunctions;
}
static const char *at91_pmx_get_func_name(struct pinctrl_dev *pctldev,
unsigned selector)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
return info->functions[selector].name;
}
static int at91_pmx_get_groups(struct pinctrl_dev *pctldev, unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
*groups = info->functions[selector].groups;
*num_groups = info->functions[selector].ngroups;
return 0;
}
static int at91_gpio_request_enable(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct at91_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
struct at91_gpio_chip *at91_chip;
struct gpio_chip *chip;
unsigned mask;
if (!range) {
dev_err(npct->dev, "invalid range\n");
return -EINVAL;
}
if (!range->gc) {
dev_err(npct->dev, "missing GPIO chip in range\n");
return -EINVAL;
}
chip = range->gc;
at91_chip = container_of(chip, struct at91_gpio_chip, chip);
dev_dbg(npct->dev, "enable pin %u as GPIO\n", offset);
mask = 1 << (offset - chip->base);
dev_dbg(npct->dev, "enable pin %u as PIO%c%d 0x%x\n",
offset, 'A' + range->id, offset - chip->base, mask);
writel_relaxed(mask, at91_chip->regbase + PIO_PER);
return 0;
}
static void at91_gpio_disable_free(struct pinctrl_dev *pctldev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct at91_pinctrl *npct = pinctrl_dev_get_drvdata(pctldev);
dev_dbg(npct->dev, "disable pin %u as GPIO\n", offset);
}
static int at91_pinconf_get(struct pinctrl_dev *pctldev,
unsigned pin_id, unsigned long *config)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
void __iomem *pio;
unsigned pin;
int div;
dev_dbg(info->dev, "%s:%d, pin_id=%d, config=0x%lx", __func__, __LINE__, pin_id, *config);
pio = pin_to_controller(info, pin_to_bank(pin_id));
pin = pin_id % MAX_NB_GPIO_PER_BANK;
if (at91_mux_get_multidrive(pio, pin))
*config |= MULTI_DRIVE;
if (at91_mux_get_pullup(pio, pin))
*config |= PULL_UP;
if (info->ops->get_deglitch && info->ops->get_deglitch(pio, pin))
*config |= DEGLITCH;
if (info->ops->get_debounce && info->ops->get_debounce(pio, pin, &div))
*config |= DEBOUNCE | (div << DEBOUNCE_VAL_SHIFT);
if (info->ops->get_pulldown && info->ops->get_pulldown(pio, pin))
*config |= PULL_DOWN;
if (info->ops->get_schmitt_trig && info->ops->get_schmitt_trig(pio, pin))
*config |= DIS_SCHMIT;
return 0;
}
static int at91_pinconf_set(struct pinctrl_dev *pctldev,
unsigned pin_id, unsigned long config)
{
struct at91_pinctrl *info = pinctrl_dev_get_drvdata(pctldev);
unsigned mask;
void __iomem *pio;
dev_dbg(info->dev, "%s:%d, pin_id=%d, config=0x%lx", __func__, __LINE__, pin_id, config);
pio = pin_to_controller(info, pin_to_bank(pin_id));
mask = pin_to_mask(pin_id % MAX_NB_GPIO_PER_BANK);
if (config & PULL_UP && config & PULL_DOWN)
return -EINVAL;
at91_mux_set_pullup(pio, mask, config & PULL_UP);
at91_mux_set_multidrive(pio, mask, config & MULTI_DRIVE);
if (info->ops->set_deglitch)
info->ops->set_deglitch(pio, mask, config & DEGLITCH);
if (info->ops->set_debounce)
info->ops->set_debounce(pio, mask, config & DEBOUNCE,
(config & DEBOUNCE_VAL) >> DEBOUNCE_VAL_SHIFT);
if (info->ops->set_pulldown)
info->ops->set_pulldown(pio, mask, config & PULL_DOWN);
if (info->ops->disable_schmitt_trig && config & DIS_SCHMIT)
info->ops->disable_schmitt_trig(pio, mask);
return 0;
}
static void at91_pinconf_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned pin_id)
{
}
static void at91_pinconf_group_dbg_show(struct pinctrl_dev *pctldev,
struct seq_file *s, unsigned group)
{
}
static void at91_pinctrl_child_count(struct at91_pinctrl *info,
struct device_node *np)
{
struct device_node *child;
for_each_child_of_node(np, child) {
if (of_device_is_compatible(child, gpio_compat)) {
info->nbanks++;
} else {
info->nfunctions++;
info->ngroups += of_get_child_count(child);
}
}
}
static int at91_pinctrl_mux_mask(struct at91_pinctrl *info,
struct device_node *np)
{
int ret = 0;
int size;
const const __be32 *list;
list = of_get_property(np, "atmel,mux-mask", &size);
if (!list) {
dev_err(info->dev, "can not read the mux-mask of %d\n", size);
return -EINVAL;
}
size /= sizeof(*list);
if (!size || size % info->nbanks) {
dev_err(info->dev, "wrong mux mask array should be by %d\n", info->nbanks);
return -EINVAL;
}
info->nmux = size / info->nbanks;
info->mux_mask = devm_kzalloc(info->dev, sizeof(u32) * size, GFP_KERNEL);
if (!info->mux_mask) {
dev_err(info->dev, "could not alloc mux_mask\n");
return -ENOMEM;
}
ret = of_property_read_u32_array(np, "atmel,mux-mask",
info->mux_mask, size);
if (ret)
dev_err(info->dev, "can not read the mux-mask of %d\n", size);
return ret;
}
static int at91_pinctrl_parse_groups(struct device_node *np,
struct at91_pin_group *grp,
struct at91_pinctrl *info, u32 index)
{
struct at91_pmx_pin *pin;
int size;
const const __be32 *list;
int i, j;
dev_dbg(info->dev, "group(%d): %s\n", index, np->name);
grp->name = np->name;
list = of_get_property(np, "atmel,pins", &size);
size /= sizeof(*list);
if (!size || size % 4) {
dev_err(info->dev, "wrong pins number or pins and configs should be by 4\n");
return -EINVAL;
}
grp->npins = size / 4;
pin = grp->pins_conf = devm_kzalloc(info->dev, grp->npins * sizeof(struct at91_pmx_pin),
GFP_KERNEL);
grp->pins = devm_kzalloc(info->dev, grp->npins * sizeof(unsigned int),
GFP_KERNEL);
if (!grp->pins_conf || !grp->pins)
return -ENOMEM;
for (i = 0, j = 0; i < size; i += 4, j++) {
pin->bank = be32_to_cpu(*list++);
pin->pin = be32_to_cpu(*list++);
grp->pins[j] = pin->bank * MAX_NB_GPIO_PER_BANK + pin->pin;
pin->mux = be32_to_cpu(*list++);
pin->conf = be32_to_cpu(*list++);
at91_pin_dbg(info->dev, pin);
pin++;
}
return 0;
}
static int at91_pinctrl_parse_functions(struct device_node *np,
struct at91_pinctrl *info, u32 index)
{
struct device_node *child;
struct at91_pmx_func *func;
struct at91_pin_group *grp;
int ret;
static u32 grp_index;
u32 i = 0;
dev_dbg(info->dev, "parse function(%d): %s\n", index, np->name);
func = &info->functions[index];
func->name = np->name;
func->ngroups = of_get_child_count(np);
if (func->ngroups <= 0) {
dev_err(info->dev, "no groups defined\n");
return -EINVAL;
}
func->groups = devm_kzalloc(info->dev,
func->ngroups * sizeof(char *), GFP_KERNEL);
if (!func->groups)
return -ENOMEM;
for_each_child_of_node(np, child) {
func->groups[i] = child->name;
grp = &info->groups[grp_index++];
ret = at91_pinctrl_parse_groups(child, grp, info, i++);
if (ret)
return ret;
}
return 0;
}
static int at91_pinctrl_probe_dt(struct platform_device *pdev,
struct at91_pinctrl *info)
{
int ret = 0;
int i, j;
uint32_t *tmp;
struct device_node *np = pdev->dev.of_node;
struct device_node *child;
if (!np)
return -ENODEV;
info->dev = &pdev->dev;
info->ops = (struct at91_pinctrl_mux_ops*)
of_match_device(at91_pinctrl_of_match, &pdev->dev)->data;
at91_pinctrl_child_count(info, np);
if (info->nbanks < 1) {
dev_err(&pdev->dev, "you need to specify atleast one gpio-controller\n");
return -EINVAL;
}
ret = at91_pinctrl_mux_mask(info, np);
if (ret)
return ret;
dev_dbg(&pdev->dev, "nmux = %d\n", info->nmux);
dev_dbg(&pdev->dev, "mux-mask\n");
tmp = info->mux_mask;
for (i = 0; i < info->nbanks; i++) {
for (j = 0; j < info->nmux; j++, tmp++) {
dev_dbg(&pdev->dev, "%d:%d\t0x%x\n", i, j, tmp[0]);
}
}
dev_dbg(&pdev->dev, "nfunctions = %d\n", info->nfunctions);
dev_dbg(&pdev->dev, "ngroups = %d\n", info->ngroups);
info->functions = devm_kzalloc(&pdev->dev, info->nfunctions * sizeof(struct at91_pmx_func),
GFP_KERNEL);
if (!info->functions)
return -ENOMEM;
info->groups = devm_kzalloc(&pdev->dev, info->ngroups * sizeof(struct at91_pin_group),
GFP_KERNEL);
if (!info->groups)
return -ENOMEM;
dev_dbg(&pdev->dev, "nbanks = %d\n", info->nbanks);
dev_dbg(&pdev->dev, "nfunctions = %d\n", info->nfunctions);
dev_dbg(&pdev->dev, "ngroups = %d\n", info->ngroups);
i = 0;
for_each_child_of_node(np, child) {
if (of_device_is_compatible(child, gpio_compat))
continue;
ret = at91_pinctrl_parse_functions(child, info, i++);
if (ret) {
dev_err(&pdev->dev, "failed to parse function\n");
return ret;
}
}
return 0;
}
static int at91_pinctrl_probe(struct platform_device *pdev)
{
struct at91_pinctrl *info;
struct pinctrl_pin_desc *pdesc;
int ret, i, j ,k;
info = devm_kzalloc(&pdev->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
ret = at91_pinctrl_probe_dt(pdev, info);
if (ret)
return ret;
for (i = 0; i < info->nbanks; i++) {
if (!gpio_chips[i]) {
dev_warn(&pdev->dev, "GPIO chip %d not registered yet\n", i);
devm_kfree(&pdev->dev, info);
return -EPROBE_DEFER;
}
}
at91_pinctrl_desc.name = dev_name(&pdev->dev);
at91_pinctrl_desc.npins = info->nbanks * MAX_NB_GPIO_PER_BANK;
at91_pinctrl_desc.pins = pdesc =
devm_kzalloc(&pdev->dev, sizeof(*pdesc) * at91_pinctrl_desc.npins, GFP_KERNEL);
if (!at91_pinctrl_desc.pins)
return -ENOMEM;
for (i = 0 , k = 0; i < info->nbanks; i++) {
for (j = 0; j < MAX_NB_GPIO_PER_BANK; j++, k++) {
pdesc->number = k;
pdesc->name = kasprintf(GFP_KERNEL, "pio%c%d", i + 'A', j);
pdesc++;
}
}
platform_set_drvdata(pdev, info);
info->pctl = pinctrl_register(&at91_pinctrl_desc, &pdev->dev, info);
if (!info->pctl) {
dev_err(&pdev->dev, "could not register AT91 pinctrl driver\n");
ret = -EINVAL;
goto err;
}
for (i = 0; i < info->nbanks; i++)
pinctrl_add_gpio_range(info->pctl, &gpio_chips[i]->range);
dev_info(&pdev->dev, "initialized AT91 pinctrl driver\n");
return 0;
err:
return ret;
}
static int at91_pinctrl_remove(struct platform_device *pdev)
{
struct at91_pinctrl *info = platform_get_drvdata(pdev);
pinctrl_unregister(info->pctl);
return 0;
}
static int at91_gpio_request(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
int bank = chip->base / chip->ngpio;
dev_dbg(chip->dev, "%s:%d pio%c%d(%d)\n", __func__, __LINE__,
'A' + bank, offset, gpio);
return pinctrl_request_gpio(gpio);
}
static void at91_gpio_free(struct gpio_chip *chip, unsigned offset)
{
int gpio = chip->base + offset;
pinctrl_free_gpio(gpio);
}
static int at91_gpio_direction_input(struct gpio_chip *chip, unsigned offset)
{
struct at91_gpio_chip *at91_gpio = to_at91_gpio_chip(chip);
void __iomem *pio = at91_gpio->regbase;
unsigned mask = 1 << offset;
writel_relaxed(mask, pio + PIO_ODR);
return 0;
}
static int at91_gpio_get(struct gpio_chip *chip, unsigned offset)
{
struct at91_gpio_chip *at91_gpio = to_at91_gpio_chip(chip);
void __iomem *pio = at91_gpio->regbase;
unsigned mask = 1 << offset;
u32 pdsr;
pdsr = readl_relaxed(pio + PIO_PDSR);
return (pdsr & mask) != 0;
}
static void at91_gpio_set(struct gpio_chip *chip, unsigned offset,
int val)
{
struct at91_gpio_chip *at91_gpio = to_at91_gpio_chip(chip);
void __iomem *pio = at91_gpio->regbase;
unsigned mask = 1 << offset;
writel_relaxed(mask, pio + (val ? PIO_SODR : PIO_CODR));
}
static int at91_gpio_direction_output(struct gpio_chip *chip, unsigned offset,
int val)
{
struct at91_gpio_chip *at91_gpio = to_at91_gpio_chip(chip);
void __iomem *pio = at91_gpio->regbase;
unsigned mask = 1 << offset;
writel_relaxed(mask, pio + (val ? PIO_SODR : PIO_CODR));
writel_relaxed(mask, pio + PIO_OER);
return 0;
}
static int at91_gpio_to_irq(struct gpio_chip *chip, unsigned offset)
{
struct at91_gpio_chip *at91_gpio = to_at91_gpio_chip(chip);
int virq;
if (offset < chip->ngpio)
virq = irq_create_mapping(at91_gpio->domain, offset);
else
virq = -ENXIO;
dev_dbg(chip->dev, "%s: request IRQ for GPIO %d, return %d\n",
chip->label, offset + chip->base, virq);
return virq;
}
static void at91_gpio_dbg_show(struct seq_file *s, struct gpio_chip *chip)
{
enum at91_mux mode;
int i;
struct at91_gpio_chip *at91_gpio = to_at91_gpio_chip(chip);
void __iomem *pio = at91_gpio->regbase;
for (i = 0; i < chip->ngpio; i++) {
unsigned pin = chip->base + i;
unsigned mask = pin_to_mask(pin);
const char *gpio_label;
u32 pdsr;
gpio_label = gpiochip_is_requested(chip, i);
if (!gpio_label)
continue;
mode = at91_gpio->ops->get_periph(pio, mask);
seq_printf(s, "[%s] GPIO%s%d: ",
gpio_label, chip->label, i);
if (mode == AT91_MUX_GPIO) {
pdsr = readl_relaxed(pio + PIO_PDSR);
seq_printf(s, "[gpio] %s\n",
pdsr & mask ?
"set" : "clear");
} else {
seq_printf(s, "[periph %c]\n",
mode + 'A' - 1);
}
}
}
static void gpio_irq_mask(struct irq_data *d)
{
struct at91_gpio_chip *at91_gpio = irq_data_get_irq_chip_data(d);
void __iomem *pio = at91_gpio->regbase;
unsigned mask = 1 << d->hwirq;
if (pio)
writel_relaxed(mask, pio + PIO_IDR);
}
static void gpio_irq_unmask(struct irq_data *d)
{
struct at91_gpio_chip *at91_gpio = irq_data_get_irq_chip_data(d);
void __iomem *pio = at91_gpio->regbase;
unsigned mask = 1 << d->hwirq;
if (pio)
writel_relaxed(mask, pio + PIO_IER);
}
static int gpio_irq_type(struct irq_data *d, unsigned type)
{
switch (type) {
case IRQ_TYPE_NONE:
case IRQ_TYPE_EDGE_BOTH:
return 0;
default:
return -EINVAL;
}
}
static int alt_gpio_irq_type(struct irq_data *d, unsigned type)
{
struct at91_gpio_chip *at91_gpio = irq_data_get_irq_chip_data(d);
void __iomem *pio = at91_gpio->regbase;
unsigned mask = 1 << d->hwirq;
switch (type) {
case IRQ_TYPE_EDGE_RISING:
writel_relaxed(mask, pio + PIO_ESR);
writel_relaxed(mask, pio + PIO_REHLSR);
break;
case IRQ_TYPE_EDGE_FALLING:
writel_relaxed(mask, pio + PIO_ESR);
writel_relaxed(mask, pio + PIO_FELLSR);
break;
case IRQ_TYPE_LEVEL_LOW:
writel_relaxed(mask, pio + PIO_LSR);
writel_relaxed(mask, pio + PIO_FELLSR);
break;
case IRQ_TYPE_LEVEL_HIGH:
writel_relaxed(mask, pio + PIO_LSR);
writel_relaxed(mask, pio + PIO_REHLSR);
break;
case IRQ_TYPE_EDGE_BOTH:
writel_relaxed(mask, pio + PIO_AIMDR);
return 0;
case IRQ_TYPE_NONE:
default:
pr_warn("AT91: No type for irq %d\n", gpio_to_irq(d->irq));
return -EINVAL;
}
writel_relaxed(mask, pio + PIO_AIMER);
return 0;
}
static int gpio_irq_set_wake(struct irq_data *d, unsigned state)
{
struct at91_gpio_chip *at91_gpio = irq_data_get_irq_chip_data(d);
unsigned bank = at91_gpio->pioc_idx;
if (unlikely(bank >= MAX_GPIO_BANKS))
return -EINVAL;
irq_set_irq_wake(at91_gpio->pioc_virq, state);
return 0;
}
static void gpio_irq_handler(unsigned irq, struct irq_desc *desc)
{
struct irq_chip *chip = irq_desc_get_chip(desc);
struct irq_data *idata = irq_desc_get_irq_data(desc);
struct at91_gpio_chip *at91_gpio = irq_data_get_irq_chip_data(idata);
void __iomem *pio = at91_gpio->regbase;
unsigned long isr;
int n;
chained_irq_enter(chip, desc);
for (;;) {
isr = readl_relaxed(pio + PIO_ISR) & readl_relaxed(pio + PIO_IMR);
if (!isr) {
if (!at91_gpio->next)
break;
at91_gpio = at91_gpio->next;
pio = at91_gpio->regbase;
continue;
}
for_each_set_bit(n, &isr, BITS_PER_LONG) {
generic_handle_irq(irq_find_mapping(at91_gpio->domain, n));
}
}
chained_irq_exit(chip, desc);
}
static int at91_gpio_irq_map(struct irq_domain *h, unsigned int virq,
irq_hw_number_t hw)
{
struct at91_gpio_chip *at91_gpio = h->host_data;
irq_set_lockdep_class(virq, &gpio_lock_class);
irq_set_chip_and_handler(virq, &gpio_irqchip,
handle_simple_irq);
set_irq_flags(virq, IRQF_VALID);
irq_set_chip_data(virq, at91_gpio);
return 0;
}
static int at91_gpio_irq_domain_xlate(struct irq_domain *d,
struct device_node *ctrlr,
const u32 *intspec, unsigned int intsize,
irq_hw_number_t *out_hwirq,
unsigned int *out_type)
{
struct at91_gpio_chip *at91_gpio = d->host_data;
int ret;
int pin = at91_gpio->chip.base + intspec[0];
if (WARN_ON(intsize < 2))
return -EINVAL;
*out_hwirq = intspec[0];
*out_type = intspec[1] & IRQ_TYPE_SENSE_MASK;
ret = gpio_request(pin, ctrlr->full_name);
if (ret)
return ret;
ret = gpio_direction_input(pin);
if (ret)
return ret;
return 0;
}
static int at91_gpio_of_irq_setup(struct device_node *node,
struct at91_gpio_chip *at91_gpio)
{
struct at91_gpio_chip *prev = NULL;
struct irq_data *d = irq_get_irq_data(at91_gpio->pioc_virq);
at91_gpio->pioc_hwirq = irqd_to_hwirq(d);
gpio_irqchip.irq_set_type = at91_gpio->ops->irq_type;
writel_relaxed(~0, at91_gpio->regbase + PIO_IDR);
at91_gpio->domain = irq_domain_add_linear(node, at91_gpio->chip.ngpio,
&at91_gpio_ops, at91_gpio);
if (!at91_gpio->domain)
panic("at91_gpio.%d: couldn't allocate irq domain (DT).\n",
at91_gpio->pioc_idx);
if (at91_gpio->pioc_idx)
prev = gpio_chips[at91_gpio->pioc_idx - 1];
if (prev && prev->next == at91_gpio)
return 0;
irq_set_chip_data(at91_gpio->pioc_virq, at91_gpio);
irq_set_chained_handler(at91_gpio->pioc_virq, gpio_irq_handler);
return 0;
}
static void at91_gpio_probe_fixup(void)
{
unsigned i;
struct at91_gpio_chip *at91_gpio, *last = NULL;
for (i = 0; i < gpio_banks; i++) {
at91_gpio = gpio_chips[i];
if (last && last->pioc_virq == at91_gpio->pioc_virq)
last->next = at91_gpio;
last = at91_gpio;
}
}
static int at91_gpio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct resource *res;
struct at91_gpio_chip *at91_chip = NULL;
struct gpio_chip *chip;
struct pinctrl_gpio_range *range;
int ret = 0;
int irq, i;
int alias_idx = of_alias_get_id(np, "gpio");
uint32_t ngpio;
char **names;
BUG_ON(alias_idx >= ARRAY_SIZE(gpio_chips));
if (gpio_chips[alias_idx]) {
ret = -EBUSY;
goto err;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
ret = -ENOENT;
goto err;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
ret = irq;
goto err;
}
at91_chip = devm_kzalloc(&pdev->dev, sizeof(*at91_chip), GFP_KERNEL);
if (!at91_chip) {
ret = -ENOMEM;
goto err;
}
at91_chip->regbase = devm_request_and_ioremap(&pdev->dev, res);
if (!at91_chip->regbase) {
dev_err(&pdev->dev, "failed to map registers, ignoring.\n");
ret = -EBUSY;
goto err;
}
at91_chip->ops = (struct at91_pinctrl_mux_ops*)
of_match_device(at91_gpio_of_match, &pdev->dev)->data;
at91_chip->pioc_virq = irq;
at91_chip->pioc_idx = alias_idx;
at91_chip->clock = clk_get(&pdev->dev, NULL);
if (IS_ERR(at91_chip->clock)) {
dev_err(&pdev->dev, "failed to get clock, ignoring.\n");
goto err;
}
if (clk_prepare(at91_chip->clock))
goto clk_prep_err;
if (clk_enable(at91_chip->clock)) {
dev_err(&pdev->dev, "failed to enable clock, ignoring.\n");
goto clk_err;
}
at91_chip->chip = at91_gpio_template;
chip = &at91_chip->chip;
chip->of_node = np;
chip->label = dev_name(&pdev->dev);
chip->dev = &pdev->dev;
chip->owner = THIS_MODULE;
chip->base = alias_idx * MAX_NB_GPIO_PER_BANK;
if (!of_property_read_u32(np, "#gpio-lines", &ngpio)) {
if (ngpio >= MAX_NB_GPIO_PER_BANK)
pr_err("at91_gpio.%d, gpio-nb >= %d failback to %d\n",
alias_idx, MAX_NB_GPIO_PER_BANK, MAX_NB_GPIO_PER_BANK);
else
chip->ngpio = ngpio;
}
names = devm_kzalloc(&pdev->dev, sizeof(char*) * chip->ngpio, GFP_KERNEL);
if (!names) {
ret = -ENOMEM;
goto clk_err;
}
for (i = 0; i < chip->ngpio; i++)
names[i] = kasprintf(GFP_KERNEL, "pio%c%d", alias_idx + 'A', i);
chip->names = (const char*const*)names;
range = &at91_chip->range;
range->name = chip->label;
range->id = alias_idx;
range->pin_base = range->base = range->id * MAX_NB_GPIO_PER_BANK;
range->npins = chip->ngpio;
range->gc = chip;
ret = gpiochip_add(chip);
if (ret)
goto clk_err;
gpio_chips[alias_idx] = at91_chip;
gpio_banks = max(gpio_banks, alias_idx + 1);
at91_gpio_probe_fixup();
at91_gpio_of_irq_setup(np, at91_chip);
dev_info(&pdev->dev, "at address %p\n", at91_chip->regbase);
return 0;
clk_err:
clk_unprepare(at91_chip->clock);
clk_prep_err:
clk_put(at91_chip->clock);
err:
dev_err(&pdev->dev, "Failure %i for GPIO %i\n", ret, alias_idx);
return ret;
}
static int __init at91_pinctrl_init(void)
{
int ret;
ret = platform_driver_register(&at91_gpio_driver);
if (ret)
return ret;
return platform_driver_register(&at91_pinctrl_driver);
}
static void __exit at91_pinctrl_exit(void)
{
platform_driver_unregister(&at91_pinctrl_driver);
}
