static int clk_gpio_gate_enable(struct clk_hw *hw)
{
struct clk_gpio *clk = to_clk_gpio(hw);
gpiod_set_value(clk->gpiod, 1);
return 0;
}
static void clk_gpio_gate_disable(struct clk_hw *hw)
{
struct clk_gpio *clk = to_clk_gpio(hw);
gpiod_set_value(clk->gpiod, 0);
}
static int clk_gpio_gate_is_enabled(struct clk_hw *hw)
{
struct clk_gpio *clk = to_clk_gpio(hw);
return gpiod_get_value(clk->gpiod);
}
static u8 clk_gpio_mux_get_parent(struct clk_hw *hw)
{
struct clk_gpio *clk = to_clk_gpio(hw);
return gpiod_get_value(clk->gpiod);
}
static int clk_gpio_mux_set_parent(struct clk_hw *hw, u8 index)
{
struct clk_gpio *clk = to_clk_gpio(hw);
gpiod_set_value(clk->gpiod, index);
return 0;
}
static struct clk *clk_register_gpio(struct device *dev, const char *name,
const char * const *parent_names, u8 num_parents, unsigned gpio,
bool active_low, unsigned long flags,
const struct clk_ops *clk_gpio_ops)
{
struct clk_gpio *clk_gpio;
struct clk *clk;
struct clk_init_data init = {};
unsigned long gpio_flags;
int err;
if (dev)
clk_gpio = devm_kzalloc(dev, sizeof(*clk_gpio), GFP_KERNEL);
else
clk_gpio = kzalloc(sizeof(*clk_gpio), GFP_KERNEL);
if (!clk_gpio)
return ERR_PTR(-ENOMEM);
if (active_low)
gpio_flags = GPIOF_ACTIVE_LOW | GPIOF_OUT_INIT_HIGH;
else
gpio_flags = GPIOF_OUT_INIT_LOW;
if (dev)
err = devm_gpio_request_one(dev, gpio, gpio_flags, name);
else
err = gpio_request_one(gpio, gpio_flags, name);
if (err) {
if (err != -EPROBE_DEFER)
pr_err("%s: %s: Error requesting clock control gpio %u\n",
__func__, name, gpio);
if (!dev)
kfree(clk_gpio);
return ERR_PTR(err);
}
init.name = name;
init.ops = clk_gpio_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = parent_names;
init.num_parents = num_parents;
clk_gpio->gpiod = gpio_to_desc(gpio);
clk_gpio->hw.init = &init;
if (dev)
clk = devm_clk_register(dev, &clk_gpio->hw);
else
clk = clk_register(NULL, &clk_gpio->hw);
if (!IS_ERR(clk))
return clk;
if (!dev) {
gpiod_put(clk_gpio->gpiod);
kfree(clk_gpio);
}
return clk;
}
struct clk *clk_register_gpio_gate(struct device *dev, const char *name,
const char *parent_name, unsigned gpio, bool active_low,
unsigned long flags)
{
return clk_register_gpio(dev, name,
(parent_name ? &parent_name : NULL),
(parent_name ? 1 : 0), gpio, active_low, flags,
&clk_gpio_gate_ops);
}
struct clk *clk_register_gpio_mux(struct device *dev, const char *name,
const char * const *parent_names, u8 num_parents, unsigned gpio,
bool active_low, unsigned long flags)
{
if (num_parents != 2) {
pr_err("mux-clock %s must have 2 parents\n", name);
return ERR_PTR(-EINVAL);
}
return clk_register_gpio(dev, name, parent_names, num_parents,
gpio, active_low, flags, &clk_gpio_mux_ops);
}
static struct clk *of_clk_gpio_delayed_register_get(
struct of_phandle_args *clkspec, void *_data)
{
struct clk_gpio_delayed_register_data *data = _data;
struct clk *clk;
int gpio;
enum of_gpio_flags of_flags;
mutex_lock(&data->lock);
if (data->clk) {
mutex_unlock(&data->lock);
return data->clk;
}
gpio = of_get_named_gpio_flags(data->node, data->gpio_name, 0,
&of_flags);
if (gpio < 0) {
mutex_unlock(&data->lock);
if (gpio == -EPROBE_DEFER)
pr_debug("%s: %s: GPIOs not yet available, retry later\n",
data->node->name, __func__);
else
pr_err("%s: %s: Can't get '%s' DT property\n",
data->node->name, __func__,
data->gpio_name);
return ERR_PTR(gpio);
}
clk = data->clk_register_get(data->node->name, data->parent_names,
data->num_parents, gpio, of_flags & OF_GPIO_ACTIVE_LOW);
if (IS_ERR(clk))
goto out;
data->clk = clk;
out:
mutex_unlock(&data->lock);
return clk;
}
static struct clk *of_clk_gpio_gate_delayed_register_get(const char *name,
const char * const *parent_names, u8 num_parents,
unsigned gpio, bool active_low)
{
return clk_register_gpio_gate(NULL, name, parent_names[0],
gpio, active_low, 0);
}
static struct clk *of_clk_gpio_mux_delayed_register_get(const char *name,
const char * const *parent_names, u8 num_parents, unsigned gpio,
bool active_low)
{
return clk_register_gpio_mux(NULL, name, parent_names, num_parents,
gpio, active_low, 0);
}
static void __init of_gpio_gate_clk_setup(struct device_node *node)
{
of_gpio_clk_setup(node, "enable-gpios",
of_clk_gpio_gate_delayed_register_get);
}
void __init of_gpio_mux_clk_setup(struct device_node *node)
{
of_gpio_clk_setup(node, "select-gpios",
of_clk_gpio_mux_delayed_register_get);
}
