static int powernv_get_led_type(const char *led_type_desc)
{
int i;
for (i = 0; i < ARRAY_SIZE(led_type_map); i++)
if (!strcmp(led_type_map[i].desc, led_type_desc))
return led_type_map[i].type;
return -1;
}
static int powernv_led_set(struct powernv_led_data *powernv_led,
enum led_brightness value)
{
int rc, token;
u64 led_mask, led_value = 0;
__be64 max_type;
struct opal_msg msg;
struct device *dev = powernv_led->cdev.dev;
struct powernv_led_common *powernv_led_common = powernv_led->common;
max_type = powernv_led_common->max_led_type;
led_mask = OPAL_SLOT_LED_STATE_ON << powernv_led->led_type;
if (value)
led_value = led_mask;
token = opal_async_get_token_interruptible();
if (token < 0) {
if (token != -ERESTARTSYS)
dev_err(dev, "%s: Couldn't get OPAL async token\n",
__func__);
return token;
}
rc = opal_leds_set_ind(token, powernv_led->loc_code,
led_mask, led_value, &max_type);
if (rc != OPAL_ASYNC_COMPLETION) {
dev_err(dev, "%s: OPAL set LED call failed for %s [rc=%d]\n",
__func__, powernv_led->loc_code, rc);
goto out_token;
}
rc = opal_async_wait_response(token, &msg);
if (rc) {
dev_err(dev,
"%s: Failed to wait for the async response [rc=%d]\n",
__func__, rc);
goto out_token;
}
rc = opal_get_async_rc(msg);
if (rc != OPAL_SUCCESS)
dev_err(dev, "%s : OAPL async call returned failed [rc=%d]\n",
__func__, rc);
out_token:
opal_async_release_token(token);
return rc;
}
static enum led_brightness powernv_led_get(struct powernv_led_data *powernv_led)
{
int rc;
__be64 mask, value, max_type;
u64 led_mask, led_value;
struct device *dev = powernv_led->cdev.dev;
struct powernv_led_common *powernv_led_common = powernv_led->common;
mask = cpu_to_be64(0);
value = cpu_to_be64(0);
max_type = powernv_led_common->max_led_type;
rc = opal_leds_get_ind(powernv_led->loc_code,
&mask, &value, &max_type);
if (rc != OPAL_SUCCESS && rc != OPAL_PARTIAL) {
dev_err(dev, "%s: OPAL get led call failed [rc=%d]\n",
__func__, rc);
return LED_OFF;
}
led_mask = be64_to_cpu(mask);
led_value = be64_to_cpu(value);
if (!((led_mask >> powernv_led->led_type) & OPAL_SLOT_LED_STATE_ON)) {
dev_err(dev, "%s: LED status not available for %s\n",
__func__, powernv_led->cdev.name);
return LED_OFF;
}
if ((led_value >> powernv_led->led_type) & OPAL_SLOT_LED_STATE_ON)
return LED_FULL;
return LED_OFF;
}
static int powernv_brightness_set(struct led_classdev *led_cdev,
enum led_brightness value)
{
struct powernv_led_data *powernv_led =
container_of(led_cdev, struct powernv_led_data, cdev);
struct powernv_led_common *powernv_led_common = powernv_led->common;
int rc;
if (powernv_led_common->led_disabled)
return 0;
mutex_lock(&powernv_led_common->lock);
rc = powernv_led_set(powernv_led, value);
mutex_unlock(&powernv_led_common->lock);
return rc;
}
static enum led_brightness powernv_brightness_get(struct led_classdev *led_cdev)
{
struct powernv_led_data *powernv_led =
container_of(led_cdev, struct powernv_led_data, cdev);
return powernv_led_get(powernv_led);
}
static int powernv_led_create(struct device *dev,
struct powernv_led_data *powernv_led,
const char *led_type_desc)
{
int rc;
powernv_led->led_type = powernv_get_led_type(led_type_desc);
if (powernv_led->led_type == -1) {
dev_warn(dev, "%s: No support for led type : %s\n",
__func__, led_type_desc);
return -EINVAL;
}
powernv_led->cdev.name = devm_kasprintf(dev, GFP_KERNEL, "%s:%s",
powernv_led->loc_code,
led_type_desc);
if (!powernv_led->cdev.name) {
dev_err(dev,
"%s: Memory allocation failed for classdev name\n",
__func__);
return -ENOMEM;
}
powernv_led->cdev.brightness_set_blocking = powernv_brightness_set;
powernv_led->cdev.brightness_get = powernv_brightness_get;
powernv_led->cdev.brightness = LED_OFF;
powernv_led->cdev.max_brightness = LED_FULL;
rc = devm_led_classdev_register(dev, &powernv_led->cdev);
if (rc) {
dev_err(dev, "%s: Classdev registration failed for %s\n",
__func__, powernv_led->cdev.name);
}
return rc;
}
static int powernv_led_classdev(struct platform_device *pdev,
struct device_node *led_node,
struct powernv_led_common *powernv_led_common)
{
const char *cur = NULL;
int rc = -1;
struct property *p;
struct device_node *np;
struct powernv_led_data *powernv_led;
struct device *dev = &pdev->dev;
for_each_child_of_node(led_node, np) {
p = of_find_property(np, "led-types", NULL);
while ((cur = of_prop_next_string(p, cur)) != NULL) {
powernv_led = devm_kzalloc(dev, sizeof(*powernv_led),
GFP_KERNEL);
if (!powernv_led) {
of_node_put(np);
return -ENOMEM;
}
powernv_led->common = powernv_led_common;
powernv_led->loc_code = (char *)np->name;
rc = powernv_led_create(dev, powernv_led, cur);
if (rc) {
of_node_put(np);
return rc;
}
}
}
return rc;
}
static int powernv_led_probe(struct platform_device *pdev)
{
struct device_node *led_node;
struct powernv_led_common *powernv_led_common;
struct device *dev = &pdev->dev;
led_node = of_find_node_by_path("/ibm,opal/leds");
if (!led_node) {
dev_err(dev, "%s: LED parent device node not found\n",
__func__);
return -EINVAL;
}
powernv_led_common = devm_kzalloc(dev, sizeof(*powernv_led_common),
GFP_KERNEL);
if (!powernv_led_common)
return -ENOMEM;
mutex_init(&powernv_led_common->lock);
powernv_led_common->max_led_type = cpu_to_be64(OPAL_SLOT_LED_TYPE_MAX);
platform_set_drvdata(pdev, powernv_led_common);
return powernv_led_classdev(pdev, led_node, powernv_led_common);
}
static int powernv_led_remove(struct platform_device *pdev)
{
struct powernv_led_common *powernv_led_common;
powernv_led_common = platform_get_drvdata(pdev);
powernv_led_common->led_disabled = true;
mutex_destroy(&powernv_led_common->lock);
dev_info(&pdev->dev, "PowerNV led module unregistered\n");
return 0;
}
