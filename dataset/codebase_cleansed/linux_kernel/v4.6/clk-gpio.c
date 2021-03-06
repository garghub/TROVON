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
static int gpio_clk_driver_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
const char **parent_names, *gpio_name;
unsigned int num_parents;
int gpio;
enum of_gpio_flags of_flags;
struct clk *clk;
bool active_low, is_mux;
num_parents = of_clk_get_parent_count(node);
if (num_parents) {
parent_names = devm_kcalloc(&pdev->dev, num_parents,
sizeof(char *), GFP_KERNEL);
if (!parent_names)
return -ENOMEM;
of_clk_parent_fill(node, parent_names, num_parents);
} else {
parent_names = NULL;
}
is_mux = of_device_is_compatible(node, "gpio-mux-clock");
gpio_name = is_mux ? "select-gpios" : "enable-gpios";
gpio = of_get_named_gpio_flags(node, gpio_name, 0, &of_flags);
if (gpio < 0) {
if (gpio == -EPROBE_DEFER)
pr_debug("%s: %s: GPIOs not yet available, retry later\n",
node->name, __func__);
else
pr_err("%s: %s: Can't get '%s' DT property\n",
node->name, __func__,
gpio_name);
return gpio;
}
active_low = of_flags & OF_GPIO_ACTIVE_LOW;
if (is_mux)
clk = clk_register_gpio_mux(&pdev->dev, node->name,
parent_names, num_parents, gpio, active_low, 0);
else
clk = clk_register_gpio_gate(&pdev->dev, node->name,
parent_names ? parent_names[0] : NULL, gpio,
active_low, 0);
if (IS_ERR(clk))
return PTR_ERR(clk);
return of_clk_add_provider(node, of_clk_src_simple_get, clk);
}
