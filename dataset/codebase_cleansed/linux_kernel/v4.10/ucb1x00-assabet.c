static int ucb1x00_assabet_add(struct ucb1x00_dev *dev)
{
struct ucb1x00 *ucb = dev->ucb;
struct platform_device *pdev;
struct gpio_keys_platform_data keys;
static struct gpio_keys_button buttons[6];
unsigned i;
memset(buttons, 0, sizeof(buttons));
memset(&keys, 0, sizeof(keys));
for (i = 0; i < ARRAY_SIZE(buttons); i++) {
buttons[i].code = BTN_0 + i;
buttons[i].gpio = ucb->gpio.base + i;
buttons[i].type = EV_KEY;
buttons[i].can_disable = true;
}
keys.buttons = buttons;
keys.nbuttons = ARRAY_SIZE(buttons);
keys.poll_interval = 50;
keys.name = "ucb1x00";
pdev = platform_device_register_data(&ucb->dev, "gpio-keys", -1,
&keys, sizeof(keys));
device_create_file(&ucb->dev, &dev_attr_vbatt);
device_create_file(&ucb->dev, &dev_attr_vcharger);
device_create_file(&ucb->dev, &dev_attr_batt_temp);
dev->priv = pdev;
return 0;
}
static void ucb1x00_assabet_remove(struct ucb1x00_dev *dev)
{
struct platform_device *pdev = dev->priv;
if (!IS_ERR(pdev))
platform_device_unregister(pdev);
device_remove_file(&dev->ucb->dev, &dev_attr_batt_temp);
device_remove_file(&dev->ucb->dev, &dev_attr_vcharger);
device_remove_file(&dev->ucb->dev, &dev_attr_vbatt);
}
static int __init ucb1x00_assabet_init(void)
{
return ucb1x00_register_driver(&ucb1x00_assabet_driver);
}
static void __exit ucb1x00_assabet_exit(void)
{
ucb1x00_unregister_driver(&ucb1x00_assabet_driver);
}
