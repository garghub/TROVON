static int mdio_mux_gpio_switch_fn(int current_child, int desired_child,
void *data)
{
int values[MDIO_MUX_GPIO_MAX_BITS];
unsigned int n;
struct mdio_mux_gpio_state *s = data;
if (current_child == desired_child)
return 0;
for (n = 0; n < s->num_gpios; n++) {
values[n] = (desired_child >> n) & 1;
}
gpiod_set_array_cansleep(s->num_gpios, s->gpio, values);
return 0;
}
static int mdio_mux_gpio_probe(struct platform_device *pdev)
{
struct mdio_mux_gpio_state *s;
int num_gpios;
unsigned int n;
int r;
if (!pdev->dev.of_node)
return -ENODEV;
num_gpios = of_gpio_count(pdev->dev.of_node);
if (num_gpios <= 0 || num_gpios > MDIO_MUX_GPIO_MAX_BITS)
return -ENODEV;
s = devm_kzalloc(&pdev->dev, sizeof(*s), GFP_KERNEL);
if (!s)
return -ENOMEM;
s->num_gpios = num_gpios;
for (n = 0; n < num_gpios; ) {
struct gpio_desc *gpio = gpiod_get_index(&pdev->dev, NULL, n,
GPIOD_OUT_LOW);
if (IS_ERR(gpio)) {
r = PTR_ERR(gpio);
goto err;
}
s->gpio[n] = gpio;
n++;
}
r = mdio_mux_init(&pdev->dev,
mdio_mux_gpio_switch_fn, &s->mux_handle, s);
if (r == 0) {
pdev->dev.platform_data = s;
return 0;
}
err:
while (n) {
n--;
gpiod_put(s->gpio[n]);
}
return r;
}
static int mdio_mux_gpio_remove(struct platform_device *pdev)
{
unsigned int n;
struct mdio_mux_gpio_state *s = dev_get_platdata(&pdev->dev);
mdio_mux_uninit(s->mux_handle);
for (n = 0; n < s->num_gpios; n++)
gpiod_put(s->gpio[n]);
return 0;
}
