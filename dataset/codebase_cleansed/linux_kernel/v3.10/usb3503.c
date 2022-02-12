static int usb3503_write_register(struct i2c_client *client,
char reg, char data)
{
return i2c_smbus_write_byte_data(client, reg, data);
}
static int usb3503_read_register(struct i2c_client *client, char reg)
{
return i2c_smbus_read_byte_data(client, reg);
}
static int usb3503_set_bits(struct i2c_client *client, char reg, char req)
{
int err;
err = usb3503_read_register(client, reg);
if (err < 0)
return err;
err = usb3503_write_register(client, reg, err | req);
if (err < 0)
return err;
return 0;
}
static int usb3503_clear_bits(struct i2c_client *client, char reg, char req)
{
int err;
err = usb3503_read_register(client, reg);
if (err < 0)
return err;
err = usb3503_write_register(client, reg, err & ~req);
if (err < 0)
return err;
return 0;
}
static int usb3503_reset(int gpio_reset, int state)
{
if (gpio_is_valid(gpio_reset))
gpio_set_value(gpio_reset, state);
if (state)
msleep(100);
return 0;
}
static int usb3503_switch_mode(struct usb3503 *hub, enum usb3503_mode mode)
{
struct i2c_client *i2c = hub->client;
int err = 0;
switch (mode) {
case USB3503_MODE_HUB:
usb3503_reset(hub->gpio_reset, 1);
err = usb3503_write_register(i2c, USB3503_SP_ILOCK,
(USB3503_SPILOCK_CONNECT
| USB3503_SPILOCK_CONFIG));
if (err < 0) {
dev_err(&i2c->dev, "SP_ILOCK failed (%d)\n", err);
goto err_hubmode;
}
err = usb3503_set_bits(i2c, USB3503_PDS,
(USB3503_PORT2 | USB3503_PORT3));
if (err < 0) {
dev_err(&i2c->dev, "PDS failed (%d)\n", err);
goto err_hubmode;
}
err = usb3503_set_bits(i2c, USB3503_CFG1, USB3503_SELF_BUS_PWR);
if (err < 0) {
dev_err(&i2c->dev, "CFG1 failed (%d)\n", err);
goto err_hubmode;
}
err = usb3503_clear_bits(i2c, USB3503_SP_ILOCK,
(USB3503_SPILOCK_CONNECT
| USB3503_SPILOCK_CONFIG));
if (err < 0) {
dev_err(&i2c->dev, "SP_ILOCK failed (%d)\n", err);
goto err_hubmode;
}
hub->mode = mode;
dev_info(&i2c->dev, "switched to HUB mode\n");
break;
case USB3503_MODE_STANDBY:
usb3503_reset(hub->gpio_reset, 0);
hub->mode = mode;
dev_info(&i2c->dev, "switched to STANDBY mode\n");
break;
default:
dev_err(&i2c->dev, "unknown mode is request\n");
err = -EINVAL;
break;
}
err_hubmode:
return err;
}
static int usb3503_probe(struct i2c_client *i2c, const struct i2c_device_id *id)
{
struct usb3503_platform_data *pdata = i2c->dev.platform_data;
struct device_node *np = i2c->dev.of_node;
struct usb3503 *hub;
int err = -ENOMEM;
u32 mode = USB3503_MODE_UNKNOWN;
hub = kzalloc(sizeof(struct usb3503), GFP_KERNEL);
if (!hub) {
dev_err(&i2c->dev, "private data alloc fail\n");
return err;
}
i2c_set_clientdata(i2c, hub);
hub->client = i2c;
if (pdata) {
hub->gpio_intn = pdata->gpio_intn;
hub->gpio_connect = pdata->gpio_connect;
hub->gpio_reset = pdata->gpio_reset;
hub->mode = pdata->initial_mode;
} else if (np) {
hub->gpio_intn = of_get_named_gpio(np, "connect-gpios", 0);
if (hub->gpio_intn == -EPROBE_DEFER)
return -EPROBE_DEFER;
hub->gpio_connect = of_get_named_gpio(np, "intn-gpios", 0);
if (hub->gpio_connect == -EPROBE_DEFER)
return -EPROBE_DEFER;
hub->gpio_reset = of_get_named_gpio(np, "reset-gpios", 0);
if (hub->gpio_reset == -EPROBE_DEFER)
return -EPROBE_DEFER;
of_property_read_u32(np, "initial-mode", &mode);
hub->mode = mode;
}
if (gpio_is_valid(hub->gpio_intn)) {
err = gpio_request_one(hub->gpio_intn,
GPIOF_OUT_INIT_HIGH, "usb3503 intn");
if (err) {
dev_err(&i2c->dev,
"unable to request GPIO %d as connect pin (%d)\n",
hub->gpio_intn, err);
goto err_out;
}
}
if (gpio_is_valid(hub->gpio_connect)) {
err = gpio_request_one(hub->gpio_connect,
GPIOF_OUT_INIT_HIGH, "usb3503 connect");
if (err) {
dev_err(&i2c->dev,
"unable to request GPIO %d as connect pin (%d)\n",
hub->gpio_connect, err);
goto err_gpio_connect;
}
}
if (gpio_is_valid(hub->gpio_reset)) {
err = gpio_request_one(hub->gpio_reset,
GPIOF_OUT_INIT_LOW, "usb3503 reset");
if (err) {
dev_err(&i2c->dev,
"unable to request GPIO %d as reset pin (%d)\n",
hub->gpio_reset, err);
goto err_gpio_reset;
}
}
usb3503_switch_mode(hub, hub->mode);
dev_info(&i2c->dev, "%s: probed on %s mode\n", __func__,
(hub->mode == USB3503_MODE_HUB) ? "hub" : "standby");
return 0;
err_gpio_reset:
if (gpio_is_valid(hub->gpio_connect))
gpio_free(hub->gpio_connect);
err_gpio_connect:
if (gpio_is_valid(hub->gpio_intn))
gpio_free(hub->gpio_intn);
err_out:
kfree(hub);
return err;
}
static int usb3503_remove(struct i2c_client *i2c)
{
struct usb3503 *hub = i2c_get_clientdata(i2c);
if (gpio_is_valid(hub->gpio_intn))
gpio_free(hub->gpio_intn);
if (gpio_is_valid(hub->gpio_connect))
gpio_free(hub->gpio_connect);
if (gpio_is_valid(hub->gpio_reset))
gpio_free(hub->gpio_reset);
kfree(hub);
return 0;
}
