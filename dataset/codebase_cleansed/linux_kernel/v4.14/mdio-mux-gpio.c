static int mdio_mux_gpio_switch_fn(int current_child, int desired_child,
void *data)
{
struct mdio_mux_gpio_state *s = data;
int values[s->gpios->ndescs];
unsigned int n;
if (current_child == desired_child)
return 0;
for (n = 0; n < s->gpios->ndescs; n++)
values[n] = (desired_child >> n) & 1;
gpiod_set_array_value_cansleep(s->gpios->ndescs, s->gpios->desc,
values);
return 0;
}
static int mdio_mux_gpio_probe(struct platform_device *pdev)
{
struct mdio_mux_gpio_state *s;
int r;
s = devm_kzalloc(&pdev->dev, sizeof(*s), GFP_KERNEL);
if (!s)
return -ENOMEM;
s->gpios = gpiod_get_array(&pdev->dev, NULL, GPIOD_OUT_LOW);
if (IS_ERR(s->gpios))
return PTR_ERR(s->gpios);
r = mdio_mux_init(&pdev->dev, pdev->dev.of_node,
mdio_mux_gpio_switch_fn, &s->mux_handle, s, NULL);
if (r != 0) {
gpiod_put_array(s->gpios);
return r;
}
pdev->dev.platform_data = s;
return 0;
}
static int mdio_mux_gpio_remove(struct platform_device *pdev)
{
struct mdio_mux_gpio_state *s = dev_get_platdata(&pdev->dev);
mdio_mux_uninit(s->mux_handle);
gpiod_put_array(s->gpios);
return 0;
}
