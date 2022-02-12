static void syscon_led_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct syscon_led *sled =
container_of(led_cdev, struct syscon_led, cdev);
u32 val;
int ret;
if (value == LED_OFF) {
val = 0;
sled->state = false;
} else {
val = sled->mask;
sled->state = true;
}
ret = regmap_update_bits(sled->map, sled->offset, sled->mask, val);
if (ret < 0)
dev_err(sled->cdev.dev, "error updating LED status\n");
}
static int __init syscon_leds_spawn(struct device_node *np,
struct device *dev,
struct regmap *map)
{
struct device_node *child;
int ret;
for_each_available_child_of_node(np, child) {
struct syscon_led *sled;
const char *state;
if (of_property_match_string(child, "compatible",
"register-bit-led") < 0)
continue;
sled = devm_kzalloc(dev, sizeof(*sled), GFP_KERNEL);
if (!sled)
return -ENOMEM;
sled->map = map;
if (of_property_read_u32(child, "offset", &sled->offset))
return -EINVAL;
if (of_property_read_u32(child, "mask", &sled->mask))
return -EINVAL;
sled->cdev.name =
of_get_property(child, "label", NULL) ? : child->name;
sled->cdev.default_trigger =
of_get_property(child, "linux,default-trigger", NULL);
state = of_get_property(child, "default-state", NULL);
if (state) {
if (!strcmp(state, "keep")) {
u32 val;
ret = regmap_read(map, sled->offset, &val);
if (ret < 0)
return ret;
sled->state = !!(val & sled->mask);
} else if (!strcmp(state, "on")) {
sled->state = true;
ret = regmap_update_bits(map, sled->offset,
sled->mask,
sled->mask);
if (ret < 0)
return ret;
} else {
sled->state = false;
ret = regmap_update_bits(map, sled->offset,
sled->mask, 0);
if (ret < 0)
return ret;
}
}
sled->cdev.brightness_set = syscon_led_set;
ret = led_classdev_register(dev, &sled->cdev);
if (ret < 0)
return ret;
dev_info(dev, "registered LED %s\n", sled->cdev.name);
}
return 0;
}
static int __init syscon_leds_init(void)
{
struct device_node *np;
for_each_of_allnodes(np) {
struct platform_device *pdev;
struct regmap *map;
int ret;
if (!of_device_is_compatible(np, "syscon"))
continue;
map = syscon_node_to_regmap(np);
if (IS_ERR(map)) {
pr_err("error getting regmap for syscon LEDs\n");
continue;
}
pdev = of_find_device_by_node(np);
if (!pdev)
return -ENODEV;
ret = syscon_leds_spawn(np, &pdev->dev, map);
if (ret)
dev_err(&pdev->dev, "could not spawn syscon LEDs\n");
}
return 0;
}
