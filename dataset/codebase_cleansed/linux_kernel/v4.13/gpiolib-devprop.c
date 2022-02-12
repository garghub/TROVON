void devprop_gpiochip_set_names(struct gpio_chip *chip)
{
struct gpio_device *gdev = chip->gpiodev;
const char **names;
int ret, i;
if (!chip->parent) {
dev_warn(&gdev->dev, "GPIO chip parent is NULL\n");
return;
}
ret = device_property_read_string_array(chip->parent, "gpio-line-names",
NULL, 0);
if (ret < 0)
return;
if (ret != gdev->ngpio) {
dev_warn(chip->parent,
"names %d do not match number of GPIOs %d\n", ret,
gdev->ngpio);
return;
}
names = kcalloc(gdev->ngpio, sizeof(*names), GFP_KERNEL);
if (!names)
return;
ret = device_property_read_string_array(chip->parent, "gpio-line-names",
names, gdev->ngpio);
if (ret < 0) {
dev_warn(chip->parent, "failed to read GPIO line names\n");
kfree(names);
return;
}
for (i = 0; i < gdev->ngpio; i++)
gdev->descs[i].name = names[i];
kfree(names);
}
