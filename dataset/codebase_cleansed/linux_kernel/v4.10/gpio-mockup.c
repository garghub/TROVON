static int mockup_gpio_get(struct gpio_chip *gc, unsigned int offset)
{
struct mockup_gpio_controller *cntr = gpiochip_get_data(gc);
return cntr->stats[offset].value;
}
static void mockup_gpio_set(struct gpio_chip *gc, unsigned int offset,
int value)
{
struct mockup_gpio_controller *cntr = gpiochip_get_data(gc);
cntr->stats[offset].value = !!value;
}
static int mockup_gpio_dirout(struct gpio_chip *gc, unsigned int offset,
int value)
{
struct mockup_gpio_controller *cntr = gpiochip_get_data(gc);
mockup_gpio_set(gc, offset, value);
cntr->stats[offset].dir = OUT;
return 0;
}
static int mockup_gpio_dirin(struct gpio_chip *gc, unsigned int offset)
{
struct mockup_gpio_controller *cntr = gpiochip_get_data(gc);
cntr->stats[offset].dir = IN;
return 0;
}
static int mockup_gpio_get_direction(struct gpio_chip *gc, unsigned int offset)
{
struct mockup_gpio_controller *cntr = gpiochip_get_data(gc);
return cntr->stats[offset].dir;
}
static int mockup_gpio_add(struct device *dev,
struct mockup_gpio_controller *cntr,
const char *name, int base, int ngpio)
{
int ret;
cntr->gc.base = base;
cntr->gc.ngpio = ngpio;
cntr->gc.label = name;
cntr->gc.owner = THIS_MODULE;
cntr->gc.parent = dev;
cntr->gc.get = mockup_gpio_get;
cntr->gc.set = mockup_gpio_set;
cntr->gc.direction_output = mockup_gpio_dirout;
cntr->gc.direction_input = mockup_gpio_dirin;
cntr->gc.get_direction = mockup_gpio_get_direction;
cntr->stats = devm_kzalloc(dev, sizeof(*cntr->stats) * cntr->gc.ngpio,
GFP_KERNEL);
if (!cntr->stats) {
ret = -ENOMEM;
goto err;
}
ret = devm_gpiochip_add_data(dev, &cntr->gc, cntr);
if (ret)
goto err;
dev_info(dev, "gpio<%d..%d> add successful!", base, base + ngpio);
return 0;
err:
dev_err(dev, "gpio<%d..%d> add failed!", base, base + ngpio);
return ret;
}
static int mockup_gpio_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct mockup_gpio_controller *cntr;
int ret;
int i;
int base;
int ngpio;
char chip_name[sizeof(GPIO_NAME) + 3];
if (gpio_mockup_params_nr < 2)
return -EINVAL;
cntr = devm_kzalloc(dev, sizeof(*cntr) * (gpio_mockup_params_nr >> 1),
GFP_KERNEL);
if (!cntr)
return -ENOMEM;
platform_set_drvdata(pdev, cntr);
for (i = 0; i < gpio_mockup_params_nr >> 1; i++) {
base = gpio_mockup_ranges[i * 2];
if (base == -1)
ngpio = gpio_mockup_ranges[i * 2 + 1];
else
ngpio = gpio_mockup_ranges[i * 2 + 1] - base;
if (ngpio >= 0) {
sprintf(chip_name, "%s-%c", GPIO_NAME,
pins_name_start + i);
ret = mockup_gpio_add(dev, &cntr[i],
chip_name, base, ngpio);
} else {
ret = -1;
}
if (ret) {
if (base < 0)
dev_err(dev, "gpio<%d..%d> add failed\n",
base, ngpio);
else
dev_err(dev, "gpio<%d..%d> add failed\n",
base, base + ngpio);
return ret;
}
}
return 0;
}
static int __init mock_device_init(void)
{
int err;
pdev = platform_device_alloc(GPIO_NAME, -1);
if (!pdev)
return -ENOMEM;
err = platform_device_add(pdev);
if (err) {
platform_device_put(pdev);
return err;
}
err = platform_driver_register(&mockup_gpio_driver);
if (err) {
platform_device_unregister(pdev);
return err;
}
return 0;
}
static void __exit mock_device_exit(void)
{
platform_driver_unregister(&mockup_gpio_driver);
platform_device_unregister(pdev);
}
