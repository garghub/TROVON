static int soc_button_lookup_gpio(struct device *dev, int acpi_index)
{
struct gpio_desc *desc;
int gpio;
desc = gpiod_get_index(dev, KBUILD_MODNAME, acpi_index, GPIOD_ASIS);
if (IS_ERR(desc))
return PTR_ERR(desc);
gpio = desc_to_gpio(desc);
gpiod_put(desc);
return gpio;
}
static struct platform_device *
soc_button_device_create(struct platform_device *pdev,
const struct soc_button_info *button_info,
bool autorepeat)
{
const struct soc_button_info *info;
struct platform_device *pd;
struct gpio_keys_button *gpio_keys;
struct gpio_keys_platform_data *gpio_keys_pdata;
int n_buttons = 0;
int gpio;
int error;
gpio_keys_pdata = devm_kzalloc(&pdev->dev,
sizeof(*gpio_keys_pdata) +
sizeof(*gpio_keys) * MAX_NBUTTONS,
GFP_KERNEL);
if (!gpio_keys_pdata)
return ERR_PTR(-ENOMEM);
gpio_keys = (void *)(gpio_keys_pdata + 1);
for (info = button_info; info->name; info++) {
if (info->autorepeat != autorepeat)
continue;
gpio = soc_button_lookup_gpio(&pdev->dev, info->acpi_index);
if (!gpio_is_valid(gpio))
continue;
gpio_keys[n_buttons].type = info->event_type;
gpio_keys[n_buttons].code = info->event_code;
gpio_keys[n_buttons].gpio = gpio;
gpio_keys[n_buttons].active_low = 1;
gpio_keys[n_buttons].desc = info->name;
gpio_keys[n_buttons].wakeup = info->wakeup;
gpio_keys[n_buttons].debounce_interval = 50;
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
devm_kfree(&pdev->dev, gpio_keys_pdata);
return ERR_PTR(error);
}
static int soc_button_remove(struct platform_device *pdev)
{
struct soc_button_data *priv = platform_get_drvdata(pdev);
int i;
for (i = 0; i < BUTTON_TYPES; i++)
if (priv->children[i])
platform_device_unregister(priv->children[i]);
return 0;
}
static int soc_button_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
const struct acpi_device_id *id;
struct soc_button_info *button_info;
struct soc_button_data *priv;
struct platform_device *pd;
int i;
int error;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return -ENODEV;
button_info = (struct soc_button_info *)id->driver_data;
if (gpiod_count(dev, KBUILD_MODNAME) <= 0) {
dev_dbg(dev, "no GPIO attached, ignoring...\n");
return -ENODEV;
}
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
platform_set_drvdata(pdev, priv);
for (i = 0; i < BUTTON_TYPES; i++) {
pd = soc_button_device_create(pdev, button_info, i == 0);
if (IS_ERR(pd)) {
error = PTR_ERR(pd);
if (error != -ENODEV) {
soc_button_remove(pdev);
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
