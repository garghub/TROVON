static int surface3_button_lookup_gpio(struct device *dev, int acpi_index)
{
struct gpio_desc *desc;
int gpio;
desc = gpiod_get_index(dev, NULL, acpi_index, GPIOD_ASIS);
if (IS_ERR(desc))
return PTR_ERR(desc);
gpio = desc_to_gpio(desc);
gpiod_put(desc);
return gpio;
}
static struct platform_device *
surface3_button_device_create(struct i2c_client *client,
const struct surface3_button_info *button_info,
bool autorepeat)
{
const struct surface3_button_info *info;
struct platform_device *pd;
struct gpio_keys_button *gpio_keys;
struct gpio_keys_platform_data *gpio_keys_pdata;
int n_buttons = 0;
int gpio;
int error;
gpio_keys_pdata = devm_kzalloc(&client->dev,
sizeof(*gpio_keys_pdata) +
sizeof(*gpio_keys) * MAX_NBUTTONS,
GFP_KERNEL);
if (!gpio_keys_pdata)
return ERR_PTR(-ENOMEM);
gpio_keys = (void *)(gpio_keys_pdata + 1);
for (info = button_info; info->name; info++) {
if (info->autorepeat != autorepeat)
continue;
gpio = surface3_button_lookup_gpio(&client->dev,
info->acpi_index);
if (!gpio_is_valid(gpio))
continue;
gpio_keys[n_buttons].type = info->event_type;
gpio_keys[n_buttons].code = info->event_code;
gpio_keys[n_buttons].gpio = gpio;
gpio_keys[n_buttons].active_low = info->active_low;
gpio_keys[n_buttons].desc = info->name;
gpio_keys[n_buttons].wakeup = info->wakeup;
n_buttons++;
}
if (n_buttons == 0) {
error = -ENODEV;
goto err_free_mem;
}
gpio_keys_pdata->buttons = gpio_keys;
gpio_keys_pdata->nbuttons = n_buttons;
gpio_keys_pdata->rep = autorepeat;
pd = platform_device_alloc("gpio-keys", PLATFORM_DEVID_AUTO);
if (!pd) {
error = -ENOMEM;
goto err_free_mem;
}
error = platform_device_add_data(pd, gpio_keys_pdata,
sizeof(*gpio_keys_pdata));
if (error)
goto err_free_pdev;
error = platform_device_add(pd);
if (error)
goto err_free_pdev;
return pd;
err_free_pdev:
platform_device_put(pd);
err_free_mem:
devm_kfree(&client->dev, gpio_keys_pdata);
return ERR_PTR(error);
}
static int surface3_button_remove(struct i2c_client *client)
{
struct surface3_button_data *priv = i2c_get_clientdata(client);
int i;
for (i = 0; i < BUTTON_TYPES; i++)
if (priv->children[i])
platform_device_unregister(priv->children[i]);
return 0;
}
static int surface3_button_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct surface3_button_data *priv;
struct platform_device *pd;
int i;
int error;
if (strncmp(acpi_device_bid(ACPI_COMPANION(&client->dev)),
SURFACE_BUTTON_OBJ_NAME,
strlen(SURFACE_BUTTON_OBJ_NAME)))
return -ENODEV;
if (gpiod_count(dev, KBUILD_MODNAME) <= 0) {
dev_dbg(dev, "no GPIO attached, ignoring...\n");
return -ENODEV;
}
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
i2c_set_clientdata(client, priv);
for (i = 0; i < BUTTON_TYPES; i++) {
pd = surface3_button_device_create(client,
surface3_button_surface3,
i == 0);
if (IS_ERR(pd)) {
error = PTR_ERR(pd);
if (error != -ENODEV) {
surface3_button_remove(client);
return error;
}
continue;
}
priv->children[i] = pd;
}
if (!priv->children[0] && !priv->children[1])
return -ENODEV;
return 0;
}
