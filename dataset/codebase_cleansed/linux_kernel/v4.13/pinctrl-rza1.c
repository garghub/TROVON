static inline bool rza1_pinmux_get_bidir(unsigned int port,
unsigned int pin,
unsigned int func,
const struct rza1_bidir_entry *table)
{
const struct rza1_bidir_entry *entry = &table[port];
const struct rza1_bidir_pin *bidir_pin;
unsigned int i;
for (i = 0; i < entry->npins; ++i) {
bidir_pin = &entry->pins[i];
if (bidir_pin->pin == pin && bidir_pin->func == func)
return true;
}
return false;
}
static inline int rza1_pinmux_get_swio(unsigned int port,
unsigned int pin,
unsigned int func,
const struct rza1_swio_entry *table)
{
const struct rza1_swio_pin *swio_pin;
unsigned int i;
for (i = 0; i < table->npins; ++i) {
swio_pin = &table->pins[i];
if (swio_pin->port == port && swio_pin->pin == pin &&
swio_pin->func == func)
return swio_pin->input;
}
return -ENOENT;
}
static unsigned int rza1_pinmux_get_flags(unsigned int port, unsigned int pin,
unsigned int func,
struct rza1_pinctrl *rza1_pctl)
{
const struct rza1_pinmux_conf *pmx_conf = rza1_pctl->data;
const struct rza1_bidir_entry *bidir_entries = pmx_conf->bidir_entries;
const struct rza1_swio_entry *swio_entries = pmx_conf->swio_entries;
unsigned int pmx_flags = 0;
int ret;
if (rza1_pinmux_get_bidir(port, pin, func, bidir_entries))
pmx_flags |= MUX_FLAGS_BIDIR;
ret = rza1_pinmux_get_swio(port, pin, func, swio_entries);
if (ret == 0)
pmx_flags |= MUX_FLAGS_SWIO_OUTPUT;
else if (ret > 0)
pmx_flags |= MUX_FLAGS_SWIO_INPUT;
return pmx_flags;
}
static inline void rza1_set_bit(struct rza1_port *port, unsigned int reg,
unsigned int bit, bool set)
{
void __iomem *mem = RZA1_ADDR(port->base, reg, port->id);
u16 val = ioread16(mem);
if (set)
val |= BIT(bit);
else
val &= ~BIT(bit);
iowrite16(val, mem);
}
static inline unsigned int rza1_get_bit(struct rza1_port *port,
unsigned int reg, unsigned int bit)
{
void __iomem *mem = RZA1_ADDR(port->base, reg, port->id);
return ioread16(mem) & BIT(bit);
}
static void rza1_pin_reset(struct rza1_port *port, unsigned int pin)
{
unsigned long irqflags;
spin_lock_irqsave(&port->lock, irqflags);
rza1_set_bit(port, RZA1_PIBC_REG, pin, 0);
rza1_set_bit(port, RZA1_PBDC_REG, pin, 0);
rza1_set_bit(port, RZA1_PM_REG, pin, 1);
rza1_set_bit(port, RZA1_PMC_REG, pin, 0);
rza1_set_bit(port, RZA1_PIPC_REG, pin, 0);
spin_unlock_irqrestore(&port->lock, irqflags);
}
static inline int rza1_pin_get_direction(struct rza1_port *port,
unsigned int pin)
{
unsigned long irqflags;
int input;
spin_lock_irqsave(&port->lock, irqflags);
input = rza1_get_bit(port, RZA1_PM_REG, pin);
spin_unlock_irqrestore(&port->lock, irqflags);
return !!input;
}
static inline void rza1_pin_set_direction(struct rza1_port *port,
unsigned int pin, bool input)
{
unsigned long irqflags;
spin_lock_irqsave(&port->lock, irqflags);
rza1_set_bit(port, RZA1_PIBC_REG, pin, 1);
if (input) {
rza1_set_bit(port, RZA1_PM_REG, pin, 1);
rza1_set_bit(port, RZA1_PBDC_REG, pin, 0);
} else {
rza1_set_bit(port, RZA1_PM_REG, pin, 0);
rza1_set_bit(port, RZA1_PBDC_REG, pin, 1);
}
spin_unlock_irqrestore(&port->lock, irqflags);
}
static inline void rza1_pin_set(struct rza1_port *port, unsigned int pin,
unsigned int value)
{
unsigned long irqflags;
spin_lock_irqsave(&port->lock, irqflags);
rza1_set_bit(port, RZA1_P_REG, pin, !!value);
spin_unlock_irqrestore(&port->lock, irqflags);
}
static inline int rza1_pin_get(struct rza1_port *port, unsigned int pin)
{
unsigned long irqflags;
int val;
spin_lock_irqsave(&port->lock, irqflags);
val = rza1_get_bit(port, RZA1_PPR_REG, pin);
spin_unlock_irqrestore(&port->lock, irqflags);
return val;
}
static int rza1_pin_mux_single(struct rza1_pinctrl *rza1_pctl,
struct rza1_mux_conf *mux_conf)
{
struct rza1_port *port = &rza1_pctl->ports[mux_conf->port];
unsigned int pin = mux_conf->pin;
u8 mux_func = mux_conf->mux_func;
u8 mux_flags = mux_conf->mux_flags;
u8 mux_flags_from_table;
rza1_pin_reset(port, pin);
mux_flags_from_table = rza1_pinmux_get_flags(port->id, pin, mux_func,
rza1_pctl);
if (mux_flags)
mux_flags |= (mux_flags_from_table & MUX_FLAGS_BIDIR);
else
mux_flags = mux_flags_from_table;
if (mux_flags & MUX_FLAGS_BIDIR)
rza1_set_bit(port, RZA1_PBDC_REG, pin, 1);
mux_func -= 1;
rza1_set_bit(port, RZA1_PFC_REG, pin, mux_func & MUX_FUNC_PFC_MASK);
rza1_set_bit(port, RZA1_PFCE_REG, pin, mux_func & MUX_FUNC_PFCE_MASK);
rza1_set_bit(port, RZA1_PFCEA_REG, pin, mux_func & MUX_FUNC_PFCEA_MASK);
if (mux_flags & (MUX_FLAGS_SWIO_INPUT | MUX_FLAGS_SWIO_OUTPUT))
rza1_set_bit(port, RZA1_PM_REG, pin,
mux_flags & MUX_FLAGS_SWIO_INPUT);
else
rza1_set_bit(port, RZA1_PIPC_REG, pin, 1);
rza1_set_bit(port, RZA1_PMC_REG, pin, 1);
return 0;
}
static int rza1_gpio_request(struct gpio_chip *chip, unsigned int gpio)
{
struct rza1_port *port = gpiochip_get_data(chip);
rza1_pin_reset(port, gpio);
return 0;
}
static void rza1_gpio_free(struct gpio_chip *chip, unsigned int gpio)
{
struct rza1_port *port = gpiochip_get_data(chip);
rza1_pin_reset(port, gpio);
}
static int rza1_gpio_get_direction(struct gpio_chip *chip, unsigned int gpio)
{
struct rza1_port *port = gpiochip_get_data(chip);
return rza1_pin_get_direction(port, gpio);
}
static int rza1_gpio_direction_input(struct gpio_chip *chip,
unsigned int gpio)
{
struct rza1_port *port = gpiochip_get_data(chip);
rza1_pin_set_direction(port, gpio, true);
return 0;
}
static int rza1_gpio_direction_output(struct gpio_chip *chip,
unsigned int gpio,
int value)
{
struct rza1_port *port = gpiochip_get_data(chip);
rza1_pin_set(port, gpio, value);
rza1_pin_set_direction(port, gpio, false);
return 0;
}
static int rza1_gpio_get(struct gpio_chip *chip, unsigned int gpio)
{
struct rza1_port *port = gpiochip_get_data(chip);
return rza1_pin_get(port, gpio);
}
static void rza1_gpio_set(struct gpio_chip *chip, unsigned int gpio,
int value)
{
struct rza1_port *port = gpiochip_get_data(chip);
rza1_pin_set(port, gpio, value);
}
static int rza1_dt_node_pin_count(struct device_node *np)
{
struct device_node *child;
struct property *of_pins;
unsigned int npins;
of_pins = of_find_property(np, "pinmux", NULL);
if (of_pins)
return of_pins->length / sizeof(u32);
npins = 0;
for_each_child_of_node(np, child) {
of_pins = of_find_property(child, "pinmux", NULL);
if (!of_pins)
return -EINVAL;
npins += of_pins->length / sizeof(u32);
}
return npins;
}
static int rza1_parse_pinmux_node(struct rza1_pinctrl *rza1_pctl,
struct device_node *np,
struct rza1_mux_conf *mux_confs,
unsigned int *grpins)
{
struct pinctrl_dev *pctldev = rza1_pctl->pctl;
char const *prop_name = "pinmux";
unsigned long *pin_configs;
unsigned int npin_configs;
struct property *of_pins;
unsigned int npins;
u8 pinmux_flags;
unsigned int i;
int ret;
of_pins = of_find_property(np, prop_name, NULL);
if (!of_pins) {
dev_dbg(rza1_pctl->dev, "Missing %s property\n", prop_name);
return -ENOENT;
}
npins = of_pins->length / sizeof(u32);
ret = pinconf_generic_parse_dt_config(np, pctldev, &pin_configs,
&npin_configs);
if (ret) {
dev_err(rza1_pctl->dev,
"Unable to parse pin configuration options for %s\n",
np->name);
return ret;
}
pinmux_flags = 0;
for (i = 0; i < npin_configs && pinmux_flags == 0; i++)
switch (pinconf_to_config_param(pin_configs[i])) {
case PIN_CONFIG_INPUT_ENABLE:
pinmux_flags |= MUX_FLAGS_SWIO_INPUT;
break;
case PIN_CONFIG_OUTPUT:
pinmux_flags |= MUX_FLAGS_SWIO_OUTPUT;
default:
break;
}
kfree(pin_configs);
for (i = 0; i < npins; ++i) {
u32 of_pinconf;
struct rza1_mux_conf *mux_conf = &mux_confs[i];
ret = of_property_read_u32_index(np, prop_name, i, &of_pinconf);
if (ret)
return ret;
mux_conf->id = of_pinconf & MUX_PIN_ID_MASK;
mux_conf->port = RZA1_PIN_ID_TO_PORT(mux_conf->id);
mux_conf->pin = RZA1_PIN_ID_TO_PIN(mux_conf->id);
mux_conf->mux_func = MUX_FUNC(of_pinconf);
mux_conf->mux_flags = pinmux_flags;
if (mux_conf->port >= RZA1_NPORTS ||
mux_conf->pin >= RZA1_PINS_PER_PORT) {
dev_err(rza1_pctl->dev,
"Wrong port %u pin %u for %s property\n",
mux_conf->port, mux_conf->pin, prop_name);
return -EINVAL;
}
grpins[i] = mux_conf->id;
}
return npins;
}
static int rza1_dt_node_to_map(struct pinctrl_dev *pctldev,
struct device_node *np,
struct pinctrl_map **map,
unsigned int *num_maps)
{
struct rza1_pinctrl *rza1_pctl = pinctrl_dev_get_drvdata(pctldev);
struct rza1_mux_conf *mux_confs, *mux_conf;
unsigned int *grpins, *grpin;
struct device_node *child;
const char *grpname;
const char **fngrps;
int ret, npins;
npins = rza1_dt_node_pin_count(np);
if (npins < 0) {
dev_err(rza1_pctl->dev, "invalid pinmux node structure\n");
return -EINVAL;
}
mux_confs = devm_kcalloc(rza1_pctl->dev, npins, sizeof(*mux_confs),
GFP_KERNEL);
grpins = devm_kcalloc(rza1_pctl->dev, npins, sizeof(*grpins),
GFP_KERNEL);
fngrps = devm_kzalloc(rza1_pctl->dev, sizeof(*fngrps), GFP_KERNEL);
if (!mux_confs || !grpins || !fngrps)
return -ENOMEM;
mux_conf = &mux_confs[0];
grpin = &grpins[0];
ret = rza1_parse_pinmux_node(rza1_pctl, np, mux_conf, grpin);
if (ret == -ENOENT)
for_each_child_of_node(np, child) {
ret = rza1_parse_pinmux_node(rza1_pctl, child, mux_conf,
grpin);
if (ret < 0)
return ret;
grpin += ret;
mux_conf += ret;
}
else if (ret < 0)
return ret;
grpname = np->name;
fngrps[0] = grpname;
mutex_lock(&rza1_pctl->mutex);
ret = pinctrl_generic_add_group(pctldev, grpname, grpins, npins,
NULL);
if (ret) {
mutex_unlock(&rza1_pctl->mutex);
return ret;
}
ret = pinmux_generic_add_function(pctldev, grpname, fngrps, 1,
mux_confs);
if (ret)
goto remove_group;
mutex_unlock(&rza1_pctl->mutex);
dev_info(rza1_pctl->dev, "Parsed function and group %s with %d pins\n",
grpname, npins);
*num_maps = 0;
*map = kzalloc(sizeof(**map), GFP_KERNEL);
if (!*map) {
ret = -ENOMEM;
goto remove_function;
}
(*map)->type = PIN_MAP_TYPE_MUX_GROUP;
(*map)->data.mux.group = np->name;
(*map)->data.mux.function = np->name;
*num_maps = 1;
return 0;
remove_function:
mutex_lock(&rza1_pctl->mutex);
pinmux_generic_remove_last_function(pctldev);
remove_group:
pinctrl_generic_remove_last_group(pctldev);
mutex_unlock(&rza1_pctl->mutex);
dev_info(rza1_pctl->dev, "Unable to parse function and group %s\n",
grpname);
return ret;
}
static void rza1_dt_free_map(struct pinctrl_dev *pctldev,
struct pinctrl_map *map, unsigned int num_maps)
{
kfree(map);
}
static int rza1_set_mux(struct pinctrl_dev *pctldev, unsigned int selector,
unsigned int group)
{
struct rza1_pinctrl *rza1_pctl = pinctrl_dev_get_drvdata(pctldev);
struct rza1_mux_conf *mux_confs;
struct function_desc *func;
struct group_desc *grp;
int i;
grp = pinctrl_generic_get_group(pctldev, group);
if (!grp)
return -EINVAL;
func = pinmux_generic_get_function(pctldev, selector);
if (!func)
return -EINVAL;
mux_confs = (struct rza1_mux_conf *)func->data;
for (i = 0; i < grp->num_pins; ++i) {
int ret;
ret = rza1_pin_mux_single(rza1_pctl, &mux_confs[i]);
if (ret)
return ret;
}
return 0;
}
static unsigned int rza1_count_gpio_chips(struct device_node *np)
{
struct device_node *child;
unsigned int count = 0;
for_each_child_of_node(np, child) {
if (!of_property_read_bool(child, "gpio-controller"))
continue;
count++;
}
return count;
}
static int rza1_parse_gpiochip(struct rza1_pinctrl *rza1_pctl,
struct device_node *np,
struct gpio_chip *chip,
struct pinctrl_gpio_range *range)
{
const char *list_name = "gpio-ranges";
struct of_phandle_args of_args;
unsigned int gpioport;
u32 pinctrl_base;
int ret;
ret = of_parse_phandle_with_fixed_args(np, list_name, 3, 0, &of_args);
if (ret) {
dev_err(rza1_pctl->dev, "Unable to parse %s list property\n",
list_name);
return ret;
}
pinctrl_base = of_args.args[1];
gpioport = RZA1_PIN_ID_TO_PORT(pinctrl_base);
if (gpioport > RZA1_NPORTS) {
dev_err(rza1_pctl->dev,
"Invalid values in property %s\n", list_name);
return -EINVAL;
}
*chip = rza1_gpiochip_template;
chip->base = -1;
chip->label = devm_kasprintf(rza1_pctl->dev, GFP_KERNEL, "%s-%u",
np->name, gpioport);
chip->ngpio = of_args.args[2];
chip->of_node = np;
chip->parent = rza1_pctl->dev;
range->id = gpioport;
range->name = chip->label;
range->pin_base = range->base = pinctrl_base;
range->npins = of_args.args[2];
range->gc = chip;
ret = devm_gpiochip_add_data(rza1_pctl->dev, chip,
&rza1_pctl->ports[gpioport]);
if (ret)
return ret;
pinctrl_add_gpio_range(rza1_pctl->pctl, range);
dev_info(rza1_pctl->dev, "Parsed gpiochip %s with %d pins\n",
chip->label, chip->ngpio);
return 0;
}
static int rza1_gpio_register(struct rza1_pinctrl *rza1_pctl)
{
struct device_node *np = rza1_pctl->dev->of_node;
struct pinctrl_gpio_range *gpio_ranges;
struct gpio_chip *gpio_chips;
struct device_node *child;
unsigned int ngpiochips;
unsigned int i;
int ret;
ngpiochips = rza1_count_gpio_chips(np);
if (ngpiochips == 0) {
dev_dbg(rza1_pctl->dev, "No gpiochip registered\n");
return 0;
}
gpio_chips = devm_kcalloc(rza1_pctl->dev, ngpiochips,
sizeof(*gpio_chips), GFP_KERNEL);
gpio_ranges = devm_kcalloc(rza1_pctl->dev, ngpiochips,
sizeof(*gpio_ranges), GFP_KERNEL);
if (!gpio_chips || !gpio_ranges)
return -ENOMEM;
i = 0;
for_each_child_of_node(np, child) {
if (!of_property_read_bool(child, "gpio-controller"))
continue;
ret = rza1_parse_gpiochip(rza1_pctl, child, &gpio_chips[i],
&gpio_ranges[i]);
if (ret)
goto gpiochip_remove;
++i;
}
dev_info(rza1_pctl->dev, "Registered %u gpio controllers\n", i);
return 0;
gpiochip_remove:
for (; i > 0; i--)
devm_gpiochip_remove(rza1_pctl->dev, &gpio_chips[i - 1]);
return ret;
}
static int rza1_pinctrl_register(struct rza1_pinctrl *rza1_pctl)
{
struct pinctrl_pin_desc *pins;
struct rza1_port *ports;
unsigned int i;
int ret;
pins = devm_kcalloc(rza1_pctl->dev, RZA1_NPINS, sizeof(*pins),
GFP_KERNEL);
ports = devm_kcalloc(rza1_pctl->dev, RZA1_NPORTS, sizeof(*ports),
GFP_KERNEL);
if (!pins || !ports)
return -ENOMEM;
rza1_pctl->pins = pins;
rza1_pctl->desc.pins = pins;
rza1_pctl->desc.npins = RZA1_NPINS;
rza1_pctl->ports = ports;
for (i = 0; i < RZA1_NPINS; ++i) {
unsigned int pin = RZA1_PIN_ID_TO_PIN(i);
unsigned int port = RZA1_PIN_ID_TO_PORT(i);
pins[i].number = i;
pins[i].name = devm_kasprintf(rza1_pctl->dev, GFP_KERNEL,
"P%u-%u", port, pin);
if (i % RZA1_PINS_PER_PORT == 0) {
unsigned int port_id = RZA1_PIN_ID_TO_PORT(i);
ports[port_id].id = port_id;
ports[port_id].base = rza1_pctl->base;
ports[port_id].pins = &pins[i];
spin_lock_init(&ports[port_id].lock);
}
}
ret = devm_pinctrl_register_and_init(rza1_pctl->dev, &rza1_pctl->desc,
rza1_pctl, &rza1_pctl->pctl);
if (ret) {
dev_err(rza1_pctl->dev,
"RZ/A1 pin controller registration failed\n");
return ret;
}
ret = pinctrl_enable(rza1_pctl->pctl);
if (ret) {
dev_err(rza1_pctl->dev,
"RZ/A1 pin controller failed to start\n");
return ret;
}
ret = rza1_gpio_register(rza1_pctl);
if (ret) {
dev_err(rza1_pctl->dev, "RZ/A1 GPIO registration failed\n");
return ret;
}
return 0;
}
static int rza1_pinctrl_probe(struct platform_device *pdev)
{
struct rza1_pinctrl *rza1_pctl;
struct resource *res;
int ret;
rza1_pctl = devm_kzalloc(&pdev->dev, sizeof(*rza1_pctl), GFP_KERNEL);
if (!rza1_pctl)
return -ENOMEM;
rza1_pctl->dev = &pdev->dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
rza1_pctl->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(rza1_pctl->base))
return PTR_ERR(rza1_pctl->base);
mutex_init(&rza1_pctl->mutex);
platform_set_drvdata(pdev, rza1_pctl);
rza1_pctl->desc.name = DRIVER_NAME;
rza1_pctl->desc.pctlops = &rza1_pinctrl_ops;
rza1_pctl->desc.pmxops = &rza1_pinmux_ops;
rza1_pctl->desc.owner = THIS_MODULE;
rza1_pctl->data = of_device_get_match_data(&pdev->dev);
ret = rza1_pinctrl_register(rza1_pctl);
if (ret)
return ret;
dev_info(&pdev->dev,
"RZ/A1 pin controller and gpio successfully registered\n");
return 0;
}
static int __init rza1_pinctrl_init(void)
{
return platform_driver_register(&rza1_pinctrl_driver);
}
