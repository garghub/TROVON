static int __init pb_keys_init(void)
{
struct gpio_keys_button *gb = gpio_button;
int i, num, good = 0;
num = sizeof(gpio_button) / sizeof(struct gpio_keys_button);
for (i = 0; i < num; i++) {
gb[i].gpio = get_gpio_by_name(gb[i].desc);
pr_debug("info[%2d]: name = %s, gpio = %d\n", i, gb[i].desc,
gb[i].gpio);
if (gb[i].gpio == -1)
continue;
if (i != good)
gb[good] = gb[i];
good++;
}
if (good) {
gpio_keys.nbuttons = good;
return platform_device_register(&pb_device);
}
return 0;
}
