static inline void tb10x_pinctrl_set_config(struct tb10x_pinctrl *state,
unsigned int port, unsigned int mode)
{
u32 pcfg;
if (state->ports[port].count)
return;
state->ports[port].mode = mode;
pcfg = ioread32(state->base) & ~(PCFG_PORT_MASK(port));
pcfg |= (mode << (PCFG_PORT_BITWIDTH * port)) & PCFG_PORT_MASK(port);
iowrite32(pcfg, state->base);
}
static inline unsigned int tb10x_pinctrl_get_config(
struct tb10x_pinctrl *state,
unsigned int port)
{
return (ioread32(state->base) & PCFG_PORT_MASK(port))
>> (PCFG_PORT_BITWIDTH * port);
}
static int tb10x_get_groups_count(struct pinctrl_dev *pctl)
{
struct tb10x_pinctrl *state = pinctrl_dev_get_drvdata(pctl);
return state->pinfuncgrpcnt;
}
static const char *tb10x_get_group_name(struct pinctrl_dev *pctl, unsigned n)
{
struct tb10x_pinctrl *state = pinctrl_dev_get_drvdata(pctl);
return state->pingroups[n].name;
}
static int tb10x_get_group_pins(struct pinctrl_dev *pctl, unsigned n,
unsigned const **pins,
unsigned * const num_pins)
{
struct tb10x_pinctrl *state = pinctrl_dev_get_drvdata(pctl);
*pins = state->pingroups[n].pins;
*num_pins = state->pingroups[n].pincnt;
return 0;
}
static int tb10x_dt_node_to_map(struct pinctrl_dev *pctl,
struct device_node *np_config,
struct pinctrl_map **map, unsigned *num_maps)
{
const char *string;
unsigned reserved_maps = 0;
int ret = 0;
if (of_property_read_string(np_config, "abilis,function", &string)) {
pr_err("%s: No abilis,function property in device tree.\n",
np_config->full_name);
return -EINVAL;
}
*map = NULL;
*num_maps = 0;
ret = pinctrl_utils_reserve_map(pctl, map, &reserved_maps,
num_maps, 1);
if (ret)
goto out;
ret = pinctrl_utils_add_map_mux(pctl, map, &reserved_maps,
num_maps, string, np_config->name);
out:
return ret;
}
static int tb10x_get_functions_count(struct pinctrl_dev *pctl)
{
struct tb10x_pinctrl *state = pinctrl_dev_get_drvdata(pctl);
return state->pinfuncnt;
}
static const char *tb10x_get_function_name(struct pinctrl_dev *pctl,
unsigned n)
{
struct tb10x_pinctrl *state = pinctrl_dev_get_drvdata(pctl);
return state->pinfuncs[n].name;
}
static int tb10x_get_function_groups(struct pinctrl_dev *pctl,
unsigned n, const char * const **groups,
unsigned * const num_groups)
{
struct tb10x_pinctrl *state = pinctrl_dev_get_drvdata(pctl);
*groups = &state->pinfuncs[n].group;
*num_groups = 1;
return 0;
}
static int tb10x_gpio_request_enable(struct pinctrl_dev *pctl,
struct pinctrl_gpio_range *range,
unsigned pin)
{
struct tb10x_pinctrl *state = pinctrl_dev_get_drvdata(pctl);
int muxport = -1;
int muxmode = -1;
int i;
mutex_lock(&state->mutex);
for (i = 0; i < state->pinfuncgrpcnt; i++) {
const struct tb10x_pinfuncgrp *pfg = &state->pingroups[i];
unsigned int mode = pfg->mode;
int j, port = pfg->port;
if (port < 0)
continue;
for (j = 0; j < pfg->pincnt; j++) {
if (pin == pfg->pins[j]) {
if (pfg->isgpio) {
muxport = port;
muxmode = mode;
} else if (state->ports[port].count
&& (state->ports[port].mode == mode)) {
mutex_unlock(&state->mutex);
return -EBUSY;
}
break;
}
}
}
set_bit(pin, state->gpios);
if (muxport >= 0)
tb10x_pinctrl_set_config(state, muxport, muxmode);
mutex_unlock(&state->mutex);
return 0;
}
static void tb10x_gpio_disable_free(struct pinctrl_dev *pctl,
struct pinctrl_gpio_range *range,
unsigned pin)
{
struct tb10x_pinctrl *state = pinctrl_dev_get_drvdata(pctl);
mutex_lock(&state->mutex);
clear_bit(pin, state->gpios);
mutex_unlock(&state->mutex);
}
static int tb10x_pctl_set_mux(struct pinctrl_dev *pctl,
unsigned func_selector, unsigned group_selector)
{
struct tb10x_pinctrl *state = pinctrl_dev_get_drvdata(pctl);
const struct tb10x_pinfuncgrp *grp = &state->pingroups[group_selector];
int i;
if (grp->port < 0)
return 0;
mutex_lock(&state->mutex);
if (state->ports[grp->port].count
&& (state->ports[grp->port].mode != grp->mode)) {
mutex_unlock(&state->mutex);
return -EBUSY;
}
for (i = 0; i < grp->pincnt; i++)
if (test_bit(grp->pins[i], state->gpios)) {
mutex_unlock(&state->mutex);
return -EBUSY;
}
tb10x_pinctrl_set_config(state, grp->port, grp->mode);
state->ports[grp->port].count++;
mutex_unlock(&state->mutex);
return 0;
}
static int tb10x_pinctrl_probe(struct platform_device *pdev)
{
int ret = -EINVAL;
struct resource *mem;
struct device *dev = &pdev->dev;
struct device_node *of_node = dev->of_node;
struct device_node *child;
struct tb10x_pinctrl *state;
int i;
if (!of_node) {
dev_err(dev, "No device tree node found.\n");
return -EINVAL;
}
state = devm_kzalloc(dev, sizeof(struct tb10x_pinctrl) +
of_get_child_count(of_node)
* sizeof(struct tb10x_of_pinfunc),
GFP_KERNEL);
if (!state)
return -ENOMEM;
platform_set_drvdata(pdev, state);
state->pinfuncs = (struct tb10x_of_pinfunc *)(state + 1);
mutex_init(&state->mutex);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
state->base = devm_ioremap_resource(dev, mem);
if (IS_ERR(state->base)) {
ret = PTR_ERR(state->base);
goto fail;
}
state->pingroups = tb10x_pingroups;
state->pinfuncgrpcnt = ARRAY_SIZE(tb10x_pingroups);
for (i = 0; i < TB10X_PORTS; i++)
state->ports[i].mode = tb10x_pinctrl_get_config(state, i);
for_each_child_of_node(of_node, child) {
const char *name;
if (!of_property_read_string(child, "abilis,function",
&name)) {
state->pinfuncs[state->pinfuncnt].name = child->name;
state->pinfuncs[state->pinfuncnt].group = name;
state->pinfuncnt++;
}
}
state->pctl = pinctrl_register(&tb10x_pindesc, dev, state);
if (!state->pctl) {
dev_err(dev, "could not register TB10x pin driver\n");
ret = -EINVAL;
goto fail;
}
return 0;
fail:
mutex_destroy(&state->mutex);
return ret;
}
static int tb10x_pinctrl_remove(struct platform_device *pdev)
{
struct tb10x_pinctrl *state = platform_get_drvdata(pdev);
pinctrl_unregister(state->pctl);
mutex_destroy(&state->mutex);
return 0;
}
