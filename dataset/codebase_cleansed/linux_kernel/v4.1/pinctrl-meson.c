static int meson_get_bank(struct meson_domain *domain, unsigned int pin,
struct meson_bank **bank)
{
int i;
for (i = 0; i < domain->data->num_banks; i++) {
if (pin >= domain->data->banks[i].first &&
pin <= domain->data->banks[i].last) {
*bank = &domain->data->banks[i];
return 0;
}
}
return -EINVAL;
}
static int meson_get_domain_and_bank(struct meson_pinctrl *pc, unsigned int pin,
struct meson_domain **domain,
struct meson_bank **bank)
{
struct meson_domain *d;
int i;
for (i = 0; i < pc->data->num_domains; i++) {
d = &pc->domains[i];
if (pin >= d->data->pin_base &&
pin < d->data->pin_base + d->data->num_pins) {
*domain = d;
return meson_get_bank(d, pin, bank);
}
}
return -EINVAL;
}
static void meson_calc_reg_and_bit(struct meson_bank *bank, unsigned int pin,
enum meson_reg_type reg_type,
unsigned int *reg, unsigned int *bit)
{
struct meson_reg_desc *desc = &bank->regs[reg_type];
*reg = desc->reg * 4;
*bit = desc->bit + pin - bank->first;
}
static int meson_get_groups_count(struct pinctrl_dev *pcdev)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
return pc->data->num_groups;
}
static const char *meson_get_group_name(struct pinctrl_dev *pcdev,
unsigned selector)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
return pc->data->groups[selector].name;
}
static int meson_get_group_pins(struct pinctrl_dev *pcdev, unsigned selector,
const unsigned **pins, unsigned *num_pins)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
*pins = pc->data->groups[selector].pins;
*num_pins = pc->data->groups[selector].num_pins;
return 0;
}
static void meson_pin_dbg_show(struct pinctrl_dev *pcdev, struct seq_file *s,
unsigned offset)
{
seq_printf(s, " %s", dev_name(pcdev->dev));
}
static void meson_pmx_disable_other_groups(struct meson_pinctrl *pc,
unsigned int pin, int sel_group)
{
struct meson_pmx_group *group;
struct meson_domain *domain;
int i, j;
for (i = 0; i < pc->data->num_groups; i++) {
group = &pc->data->groups[i];
if (group->is_gpio || i == sel_group)
continue;
for (j = 0; j < group->num_pins; j++) {
if (group->pins[j] == pin) {
domain = &pc->domains[group->domain];
regmap_update_bits(domain->reg_mux,
group->reg * 4,
BIT(group->bit), 0);
}
}
}
}
static int meson_pmx_set_mux(struct pinctrl_dev *pcdev, unsigned func_num,
unsigned group_num)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
struct meson_pmx_func *func = &pc->data->funcs[func_num];
struct meson_pmx_group *group = &pc->data->groups[group_num];
struct meson_domain *domain = &pc->domains[group->domain];
int i, ret = 0;
dev_dbg(pc->dev, "enable function %s, group %s\n", func->name,
group->name);
for (i = 0; i < group->num_pins; i++)
meson_pmx_disable_other_groups(pc, group->pins[i], group_num);
if (func_num)
ret = regmap_update_bits(domain->reg_mux, group->reg * 4,
BIT(group->bit), BIT(group->bit));
return ret;
}
static int meson_pmx_request_gpio(struct pinctrl_dev *pcdev,
struct pinctrl_gpio_range *range,
unsigned offset)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
meson_pmx_disable_other_groups(pc, range->pin_base + offset, -1);
return 0;
}
static int meson_pmx_get_funcs_count(struct pinctrl_dev *pcdev)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
return pc->data->num_funcs;
}
static const char *meson_pmx_get_func_name(struct pinctrl_dev *pcdev,
unsigned selector)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
return pc->data->funcs[selector].name;
}
static int meson_pmx_get_groups(struct pinctrl_dev *pcdev, unsigned selector,
const char * const **groups,
unsigned * const num_groups)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
*groups = pc->data->funcs[selector].groups;
*num_groups = pc->data->funcs[selector].num_groups;
return 0;
}
static int meson_pinconf_set(struct pinctrl_dev *pcdev, unsigned int pin,
unsigned long *configs, unsigned num_configs)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
struct meson_domain *domain;
struct meson_bank *bank;
enum pin_config_param param;
unsigned int reg, bit;
int i, ret;
u16 arg;
ret = meson_get_domain_and_bank(pc, pin, &domain, &bank);
if (ret)
return ret;
for (i = 0; i < num_configs; i++) {
param = pinconf_to_config_param(configs[i]);
arg = pinconf_to_config_argument(configs[i]);
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
dev_dbg(pc->dev, "pin %u: disable bias\n", pin);
meson_calc_reg_and_bit(bank, pin, REG_PULL, &reg, &bit);
ret = regmap_update_bits(domain->reg_pull, reg,
BIT(bit), 0);
if (ret)
return ret;
break;
case PIN_CONFIG_BIAS_PULL_UP:
dev_dbg(pc->dev, "pin %u: enable pull-up\n", pin);
meson_calc_reg_and_bit(bank, pin, REG_PULLEN,
&reg, &bit);
ret = regmap_update_bits(domain->reg_pullen, reg,
BIT(bit), BIT(bit));
if (ret)
return ret;
meson_calc_reg_and_bit(bank, pin, REG_PULL, &reg, &bit);
ret = regmap_update_bits(domain->reg_pull, reg,
BIT(bit), BIT(bit));
if (ret)
return ret;
break;
case PIN_CONFIG_BIAS_PULL_DOWN:
dev_dbg(pc->dev, "pin %u: enable pull-down\n", pin);
meson_calc_reg_and_bit(bank, pin, REG_PULLEN,
&reg, &bit);
ret = regmap_update_bits(domain->reg_pullen, reg,
BIT(bit), BIT(bit));
if (ret)
return ret;
meson_calc_reg_and_bit(bank, pin, REG_PULL, &reg, &bit);
ret = regmap_update_bits(domain->reg_pull, reg,
BIT(bit), 0);
if (ret)
return ret;
break;
default:
return -ENOTSUPP;
}
}
return 0;
}
static int meson_pinconf_get_pull(struct meson_pinctrl *pc, unsigned int pin)
{
struct meson_domain *domain;
struct meson_bank *bank;
unsigned int reg, bit, val;
int ret, conf;
ret = meson_get_domain_and_bank(pc, pin, &domain, &bank);
if (ret)
return ret;
meson_calc_reg_and_bit(bank, pin, REG_PULLEN, &reg, &bit);
ret = regmap_read(domain->reg_pullen, reg, &val);
if (ret)
return ret;
if (!(val & BIT(bit))) {
conf = PIN_CONFIG_BIAS_DISABLE;
} else {
meson_calc_reg_and_bit(bank, pin, REG_PULL, &reg, &bit);
ret = regmap_read(domain->reg_pull, reg, &val);
if (ret)
return ret;
if (val & BIT(bit))
conf = PIN_CONFIG_BIAS_PULL_UP;
else
conf = PIN_CONFIG_BIAS_PULL_DOWN;
}
return conf;
}
static int meson_pinconf_get(struct pinctrl_dev *pcdev, unsigned int pin,
unsigned long *config)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
enum pin_config_param param = pinconf_to_config_param(*config);
u16 arg;
switch (param) {
case PIN_CONFIG_BIAS_DISABLE:
case PIN_CONFIG_BIAS_PULL_DOWN:
case PIN_CONFIG_BIAS_PULL_UP:
if (meson_pinconf_get_pull(pc, pin) == param)
arg = 1;
else
return -EINVAL;
break;
default:
return -ENOTSUPP;
}
*config = pinconf_to_config_packed(param, arg);
dev_dbg(pc->dev, "pinconf for pin %u is %lu\n", pin, *config);
return 0;
}
static int meson_pinconf_group_set(struct pinctrl_dev *pcdev,
unsigned int num_group,
unsigned long *configs, unsigned num_configs)
{
struct meson_pinctrl *pc = pinctrl_dev_get_drvdata(pcdev);
struct meson_pmx_group *group = &pc->data->groups[num_group];
int i;
dev_dbg(pc->dev, "set pinconf for group %s\n", group->name);
for (i = 0; i < group->num_pins; i++) {
meson_pinconf_set(pcdev, group->pins[i], configs,
num_configs);
}
return 0;
}
static int meson_pinconf_group_get(struct pinctrl_dev *pcdev,
unsigned int group, unsigned long *config)
{
return -ENOSYS;
}
static inline struct meson_domain *to_meson_domain(struct gpio_chip *chip)
{
return container_of(chip, struct meson_domain, chip);
}
static int meson_gpio_request(struct gpio_chip *chip, unsigned gpio)
{
return pinctrl_request_gpio(chip->base + gpio);
}
static void meson_gpio_free(struct gpio_chip *chip, unsigned gpio)
{
struct meson_domain *domain = to_meson_domain(chip);
pinctrl_free_gpio(domain->data->pin_base + gpio);
}
static int meson_gpio_direction_input(struct gpio_chip *chip, unsigned gpio)
{
struct meson_domain *domain = to_meson_domain(chip);
unsigned int reg, bit, pin;
struct meson_bank *bank;
int ret;
pin = domain->data->pin_base + gpio;
ret = meson_get_bank(domain, pin, &bank);
if (ret)
return ret;
meson_calc_reg_and_bit(bank, pin, REG_DIR, &reg, &bit);
return regmap_update_bits(domain->reg_gpio, reg, BIT(bit), BIT(bit));
}
static int meson_gpio_direction_output(struct gpio_chip *chip, unsigned gpio,
int value)
{
struct meson_domain *domain = to_meson_domain(chip);
unsigned int reg, bit, pin;
struct meson_bank *bank;
int ret;
pin = domain->data->pin_base + gpio;
ret = meson_get_bank(domain, pin, &bank);
if (ret)
return ret;
meson_calc_reg_and_bit(bank, pin, REG_DIR, &reg, &bit);
ret = regmap_update_bits(domain->reg_gpio, reg, BIT(bit), 0);
if (ret)
return ret;
meson_calc_reg_and_bit(bank, pin, REG_OUT, &reg, &bit);
return regmap_update_bits(domain->reg_gpio, reg, BIT(bit),
value ? BIT(bit) : 0);
}
static void meson_gpio_set(struct gpio_chip *chip, unsigned gpio, int value)
{
struct meson_domain *domain = to_meson_domain(chip);
unsigned int reg, bit, pin;
struct meson_bank *bank;
int ret;
pin = domain->data->pin_base + gpio;
ret = meson_get_bank(domain, pin, &bank);
if (ret)
return;
meson_calc_reg_and_bit(bank, pin, REG_OUT, &reg, &bit);
regmap_update_bits(domain->reg_gpio, reg, BIT(bit),
value ? BIT(bit) : 0);
}
static int meson_gpio_get(struct gpio_chip *chip, unsigned gpio)
{
struct meson_domain *domain = to_meson_domain(chip);
unsigned int reg, bit, val, pin;
struct meson_bank *bank;
int ret;
pin = domain->data->pin_base + gpio;
ret = meson_get_bank(domain, pin, &bank);
if (ret)
return ret;
meson_calc_reg_and_bit(bank, pin, REG_IN, &reg, &bit);
regmap_read(domain->reg_gpio, reg, &val);
return !!(val & BIT(bit));
}
static int meson_gpiolib_register(struct meson_pinctrl *pc)
{
struct meson_domain *domain;
int i, ret;
for (i = 0; i < pc->data->num_domains; i++) {
domain = &pc->domains[i];
domain->chip.label = domain->data->name;
domain->chip.dev = pc->dev;
domain->chip.request = meson_gpio_request;
domain->chip.free = meson_gpio_free;
domain->chip.direction_input = meson_gpio_direction_input;
domain->chip.direction_output = meson_gpio_direction_output;
domain->chip.get = meson_gpio_get;
domain->chip.set = meson_gpio_set;
domain->chip.base = domain->data->pin_base;
domain->chip.ngpio = domain->data->num_pins;
domain->chip.can_sleep = false;
domain->chip.of_node = domain->of_node;
domain->chip.of_gpio_n_cells = 2;
ret = gpiochip_add(&domain->chip);
if (ret) {
dev_err(pc->dev, "can't add gpio chip %s\n",
domain->data->name);
goto fail;
}
ret = gpiochip_add_pin_range(&domain->chip, dev_name(pc->dev),
0, domain->data->pin_base,
domain->chip.ngpio);
if (ret) {
dev_err(pc->dev, "can't add pin range\n");
goto fail;
}
}
return 0;
fail:
for (i--; i >= 0; i--)
gpiochip_remove(&pc->domains[i].chip);
return ret;
}
static struct meson_domain_data *meson_get_domain_data(struct meson_pinctrl *pc,
struct device_node *np)
{
int i;
for (i = 0; i < pc->data->num_domains; i++) {
if (!strcmp(np->name, pc->data->domain_data[i].name))
return &pc->data->domain_data[i];
}
return NULL;
}
static struct regmap *meson_map_resource(struct meson_pinctrl *pc,
struct device_node *node, char *name)
{
struct resource res;
void __iomem *base;
int i;
i = of_property_match_string(node, "reg-names", name);
if (of_address_to_resource(node, i, &res))
return ERR_PTR(-ENOENT);
base = devm_ioremap_resource(pc->dev, &res);
if (IS_ERR(base))
return ERR_CAST(base);
meson_regmap_config.max_register = resource_size(&res) - 4;
meson_regmap_config.name = devm_kasprintf(pc->dev, GFP_KERNEL,
"%s-%s", node->name,
name);
if (!meson_regmap_config.name)
return ERR_PTR(-ENOMEM);
return devm_regmap_init_mmio(pc->dev, base, &meson_regmap_config);
}
static int meson_pinctrl_parse_dt(struct meson_pinctrl *pc,
struct device_node *node)
{
struct device_node *np;
struct meson_domain *domain;
int i = 0, num_domains = 0;
for_each_child_of_node(node, np) {
if (!of_find_property(np, "gpio-controller", NULL))
continue;
num_domains++;
}
if (num_domains != pc->data->num_domains) {
dev_err(pc->dev, "wrong number of subnodes\n");
return -EINVAL;
}
pc->domains = devm_kzalloc(pc->dev, num_domains *
sizeof(struct meson_domain), GFP_KERNEL);
if (!pc->domains)
return -ENOMEM;
for_each_child_of_node(node, np) {
if (!of_find_property(np, "gpio-controller", NULL))
continue;
domain = &pc->domains[i];
domain->data = meson_get_domain_data(pc, np);
if (!domain->data) {
dev_err(pc->dev, "domain data not found for node %s\n",
np->name);
return -ENODEV;
}
domain->of_node = np;
domain->reg_mux = meson_map_resource(pc, np, "mux");
if (IS_ERR(domain->reg_mux)) {
dev_err(pc->dev, "mux registers not found\n");
return PTR_ERR(domain->reg_mux);
}
domain->reg_pull = meson_map_resource(pc, np, "pull");
if (IS_ERR(domain->reg_pull)) {
dev_err(pc->dev, "pull registers not found\n");
return PTR_ERR(domain->reg_pull);
}
domain->reg_pullen = meson_map_resource(pc, np, "pull-enable");
if (IS_ERR(domain->reg_pullen))
domain->reg_pullen = domain->reg_pull;
domain->reg_gpio = meson_map_resource(pc, np, "gpio");
if (IS_ERR(domain->reg_gpio)) {
dev_err(pc->dev, "gpio registers not found\n");
return PTR_ERR(domain->reg_gpio);
}
i++;
}
return 0;
}
static int meson_pinctrl_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct device *dev = &pdev->dev;
struct meson_pinctrl *pc;
int ret;
pc = devm_kzalloc(dev, sizeof(struct meson_pinctrl), GFP_KERNEL);
if (!pc)
return -ENOMEM;
pc->dev = dev;
match = of_match_node(meson_pinctrl_dt_match, pdev->dev.of_node);
pc->data = (struct meson_pinctrl_data *)match->data;
ret = meson_pinctrl_parse_dt(pc, pdev->dev.of_node);
if (ret)
return ret;
pc->desc.name = "pinctrl-meson";
pc->desc.owner = THIS_MODULE;
pc->desc.pctlops = &meson_pctrl_ops;
pc->desc.pmxops = &meson_pmx_ops;
pc->desc.confops = &meson_pinconf_ops;
pc->desc.pins = pc->data->pins;
pc->desc.npins = pc->data->num_pins;
pc->pcdev = pinctrl_register(&pc->desc, pc->dev, pc);
if (!pc->pcdev) {
dev_err(pc->dev, "can't register pinctrl device");
return -EINVAL;
}
ret = meson_gpiolib_register(pc);
if (ret) {
pinctrl_unregister(pc->pcdev);
return ret;
}
return 0;
}
