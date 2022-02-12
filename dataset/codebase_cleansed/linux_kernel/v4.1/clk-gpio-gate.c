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
struct clk *clk_register_gpio_gate(struct device *dev, const char *name,
const char *parent_name, unsigned gpio, bool active_low,
unsigned long flags)
{
struct clk_gpio *clk_gpio = NULL;
struct clk *clk = ERR_PTR(-EINVAL);
struct clk_init_data init = { NULL };
unsigned long gpio_flags;
int err;
if (active_low)
gpio_flags = GPIOF_ACTIVE_LOW | GPIOF_OUT_INIT_HIGH;
else
gpio_flags = GPIOF_OUT_INIT_LOW;
if (dev)
err = devm_gpio_request_one(dev, gpio, gpio_flags, name);
else
err = gpio_request_one(gpio, gpio_flags, name);
if (err) {
pr_err("%s: %s: Error requesting clock control gpio %u\n",
__func__, name, gpio);
return ERR_PTR(err);
}
if (dev)
clk_gpio = devm_kzalloc(dev, sizeof(struct clk_gpio),
GFP_KERNEL);
else
clk_gpio = kzalloc(sizeof(struct clk_gpio), GFP_KERNEL);
if (!clk_gpio) {
clk = ERR_PTR(-ENOMEM);
goto clk_register_gpio_gate_err;
}
init.name = name;
init.ops = &clk_gpio_gate_ops;
init.flags = flags | CLK_IS_BASIC;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
clk_gpio->gpiod = gpio_to_desc(gpio);
clk_gpio->hw.init = &init;
clk = clk_register(dev, &clk_gpio->hw);
if (!IS_ERR(clk))
return clk;
if (!dev)
kfree(clk_gpio);
clk_register_gpio_gate_err:
if (!dev)
gpio_free(gpio);
return clk;
}
static struct clk *of_clk_gpio_gate_delayed_register_get(
struct of_phandle_args *clkspec,
void *_data)
{
struct clk_gpio_gate_delayed_register_data *data = _data;
struct clk *clk;
const char *clk_name = data->node->name;
const char *parent_name;
int gpio;
enum of_gpio_flags of_flags;
mutex_lock(&data->lock);
if (data->clk) {
mutex_unlock(&data->lock);
return data->clk;
}
gpio = of_get_named_gpio_flags(data->node, "enable-gpios", 0,
&of_flags);
if (gpio < 0) {
mutex_unlock(&data->lock);
if (gpio != -EPROBE_DEFER)
pr_err("%s: %s: Can't get 'enable-gpios' DT property\n",
__func__, clk_name);
return ERR_PTR(gpio);
}
parent_name = of_clk_get_parent_name(data->node, 0);
clk = clk_register_gpio_gate(NULL, clk_name, parent_name, gpio,
of_flags & OF_GPIO_ACTIVE_LOW, 0);
if (IS_ERR(clk)) {
mutex_unlock(&data->lock);
return clk;
}
data->clk = clk;
mutex_unlock(&data->lock);
return clk;
}
void __init of_gpio_gate_clk_setup(struct device_node *node)
{
struct clk_gpio_gate_delayed_register_data *data;
data = kzalloc(sizeof(struct clk_gpio_gate_delayed_register_data),
GFP_KERNEL);
if (!data)
return;
data->node = node;
mutex_init(&data->lock);
of_clk_add_provider(node, of_clk_gpio_gate_delayed_register_get, data);
}
