static int mdio_mux_gpio_switch_fn(int current_child, int desired_child,
void *data)
{
int change;
unsigned int n;
struct mdio_mux_gpio_state *s = data;
if (current_child == desired_child)
return 0;
change = current_child == -1 ? -1 : current_child ^ desired_child;
for (n = 0; n < s->num_gpios; n++) {
if (change & 1)
gpio_set_value_cansleep(s->gpio[n],
(desired_child & 1) != 0);
change >>= 1;
desired_child >>= 1;
}
return 0;
}
static int mdio_mux_gpio_probe(struct platform_device *pdev)
{
enum of_gpio_flags f;
struct mdio_mux_gpio_state *s;
unsigned int num_gpios;
unsigned int n;
int r;
if (!pdev->dev.of_node)
return -ENODEV;
num_gpios = of_gpio_count(pdev->dev.of_node);
if (num_gpios == 0 || num_gpios > MDIO_MUX_GPIO_MAX_BITS)
return -ENODEV;
s = devm_kzalloc(&pdev->dev, sizeof(*s), GFP_KERNEL);
if (!s)
return -ENOMEM;
s->num_gpios = num_gpios;
for (n = 0; n < num_gpios; ) {
int gpio = of_get_gpio_flags(pdev->dev.of_node, n, &f);
if (gpio < 0) {
r = (gpio == -ENODEV) ? -EPROBE_DEFER : gpio;
goto err;
}
s->gpio[n] = gpio;
n++;
r = gpio_request(gpio, "mdio_mux_gpio");
if (r)
goto err;
r = gpio_direction_output(gpio, 0);
if (r)
goto err;
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
gpio_free(s->gpio[n]);
}
return r;
}
static int mdio_mux_gpio_remove(struct platform_device *pdev)
{
struct mdio_mux_gpio_state *s = pdev->dev.platform_data;
mdio_mux_uninit(s->mux_handle);
return 0;
}
