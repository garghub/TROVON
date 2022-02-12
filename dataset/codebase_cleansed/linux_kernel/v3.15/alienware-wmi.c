static int dmi_matched(const struct dmi_system_id *dmi)
{
quirks = dmi->driver_data;
return 1;
}
static int parse_rgb(const char *buf, struct platform_zone *zone)
{
long unsigned int rgb;
int ret;
union color_union {
struct color_platform cp;
int package;
} repackager;
ret = kstrtoul(buf, 16, &rgb);
if (ret)
return ret;
if (rgb > 0xFFFFFF)
return -EINVAL;
repackager.package = rgb & 0x0f0f0f0f;
pr_debug("alienware-wmi: r: %d g:%d b: %d\n",
repackager.cp.red, repackager.cp.green, repackager.cp.blue);
zone->colors = repackager.cp;
return 0;
}
static struct platform_zone *match_zone(struct device_attribute *attr)
{
int i;
for (i = 0; i < quirks->num_zones; i++) {
if ((struct device_attribute *)zone_data[i].attr == attr) {
pr_debug("alienware-wmi: matched zone location: %d\n",
zone_data[i].location);
return &zone_data[i];
}
}
return NULL;
}
static int alienware_update_led(struct platform_zone *zone)
{
int method_id;
acpi_status status;
char *guid;
struct acpi_buffer input;
struct legacy_led_args legacy_args;
struct wmax_led_args wmax_args;
if (interface == WMAX) {
wmax_args.led_mask = 1 << zone->location;
wmax_args.colors = zone->colors;
wmax_args.state = lighting_control_state;
guid = WMAX_CONTROL_GUID;
method_id = WMAX_METHOD_ZONE_CONTROL;
input.length = (acpi_size) sizeof(wmax_args);
input.pointer = &wmax_args;
} else {
legacy_args.colors = zone->colors;
legacy_args.brightness = global_brightness;
legacy_args.state = 0;
if (lighting_control_state == LEGACY_BOOTING ||
lighting_control_state == LEGACY_SUSPEND) {
guid = LEGACY_POWER_CONTROL_GUID;
legacy_args.state = lighting_control_state;
} else
guid = LEGACY_CONTROL_GUID;
method_id = zone->location + 1;
input.length = (acpi_size) sizeof(legacy_args);
input.pointer = &legacy_args;
}
pr_debug("alienware-wmi: guid %s method %d\n", guid, method_id);
status = wmi_evaluate_method(guid, 1, method_id, &input, NULL);
if (ACPI_FAILURE(status))
pr_err("alienware-wmi: zone set failure: %u\n", status);
return ACPI_FAILURE(status);
}
static ssize_t zone_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct platform_zone *target_zone;
target_zone = match_zone(attr);
if (target_zone == NULL)
return sprintf(buf, "red: -1, green: -1, blue: -1\n");
return sprintf(buf, "red: %d, green: %d, blue: %d\n",
target_zone->colors.red,
target_zone->colors.green, target_zone->colors.blue);
}
static ssize_t zone_set(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct platform_zone *target_zone;
int ret;
target_zone = match_zone(attr);
if (target_zone == NULL) {
pr_err("alienware-wmi: invalid target zone\n");
return 1;
}
ret = parse_rgb(buf, target_zone);
if (ret)
return ret;
ret = alienware_update_led(target_zone);
return ret ? ret : count;
}
static int wmax_brightness(int brightness)
{
acpi_status status;
struct acpi_buffer input;
struct wmax_brightness_args args = {
.led_mask = 0xFF,
.percentage = brightness,
};
input.length = (acpi_size) sizeof(args);
input.pointer = &args;
status = wmi_evaluate_method(WMAX_CONTROL_GUID, 1,
WMAX_METHOD_BRIGHTNESS, &input, NULL);
if (ACPI_FAILURE(status))
pr_err("alienware-wmi: brightness set failure: %u\n", status);
return ACPI_FAILURE(status);
}
static void global_led_set(struct led_classdev *led_cdev,
enum led_brightness brightness)
{
int ret;
global_brightness = brightness;
if (interface == WMAX)
ret = wmax_brightness(brightness);
else
ret = alienware_update_led(&zone_data[0]);
if (ret)
pr_err("LED brightness update failed\n");
}
static enum led_brightness global_led_get(struct led_classdev *led_cdev)
{
return global_brightness;
}
static ssize_t show_control_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
if (lighting_control_state == LEGACY_BOOTING)
return scnprintf(buf, PAGE_SIZE, "[booting] running suspend\n");
else if (lighting_control_state == LEGACY_SUSPEND)
return scnprintf(buf, PAGE_SIZE, "booting running [suspend]\n");
return scnprintf(buf, PAGE_SIZE, "booting [running] suspend\n");
}
static ssize_t store_control_state(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
long unsigned int val;
if (strcmp(buf, "booting\n") == 0)
val = LEGACY_BOOTING;
else if (strcmp(buf, "suspend\n") == 0)
val = LEGACY_SUSPEND;
else if (interface == LEGACY)
val = LEGACY_RUNNING;
else
val = WMAX_RUNNING;
lighting_control_state = val;
pr_debug("alienware-wmi: updated control state to %d\n",
lighting_control_state);
return count;
}
static int alienware_zone_init(struct platform_device *dev)
{
int i;
char buffer[10];
char *name;
if (interface == WMAX) {
global_led.max_brightness = 100;
lighting_control_state = WMAX_RUNNING;
} else if (interface == LEGACY) {
global_led.max_brightness = 0x0F;
lighting_control_state = LEGACY_RUNNING;
}
global_brightness = global_led.max_brightness;
zone_dev_attrs =
kzalloc(sizeof(struct device_attribute) * (quirks->num_zones + 1),
GFP_KERNEL);
if (!zone_dev_attrs)
return -ENOMEM;
zone_attrs =
kzalloc(sizeof(struct attribute *) * (quirks->num_zones + 2),
GFP_KERNEL);
if (!zone_attrs)
return -ENOMEM;
zone_data =
kzalloc(sizeof(struct platform_zone) * (quirks->num_zones),
GFP_KERNEL);
if (!zone_data)
return -ENOMEM;
for (i = 0; i < quirks->num_zones; i++) {
sprintf(buffer, "zone%02X", i);
name = kstrdup(buffer, GFP_KERNEL);
if (name == NULL)
return 1;
sysfs_attr_init(&zone_dev_attrs[i].attr);
zone_dev_attrs[i].attr.name = name;
zone_dev_attrs[i].attr.mode = 0644;
zone_dev_attrs[i].show = zone_show;
zone_dev_attrs[i].store = zone_set;
zone_data[i].location = i;
zone_attrs[i] = &zone_dev_attrs[i].attr;
zone_data[i].attr = &zone_dev_attrs[i];
}
zone_attrs[quirks->num_zones] = &dev_attr_lighting_control_state.attr;
zone_attribute_group.attrs = zone_attrs;
led_classdev_register(&dev->dev, &global_led);
return sysfs_create_group(&dev->dev.kobj, &zone_attribute_group);
}
static void alienware_zone_exit(struct platform_device *dev)
{
sysfs_remove_group(&dev->dev.kobj, &zone_attribute_group);
led_classdev_unregister(&global_led);
if (zone_dev_attrs) {
int i;
for (i = 0; i < quirks->num_zones; i++)
kfree(zone_dev_attrs[i].attr.name);
}
kfree(zone_dev_attrs);
kfree(zone_data);
kfree(zone_attrs);
}
static ssize_t show_hdmi(struct device *dev, struct device_attribute *attr,
char *buf)
{
acpi_status status;
struct acpi_buffer input;
union acpi_object *obj;
u32 tmp = 0;
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
struct hdmi_args in_args = {
.arg = 0,
};
input.length = (acpi_size) sizeof(in_args);
input.pointer = &in_args;
status = wmi_evaluate_method(WMAX_CONTROL_GUID, 1,
WMAX_METHOD_HDMI_STATUS, &input, &output);
if (ACPI_SUCCESS(status)) {
obj = (union acpi_object *)output.pointer;
if (obj && obj->type == ACPI_TYPE_INTEGER)
tmp = (u32) obj->integer.value;
if (tmp == 1)
return scnprintf(buf, PAGE_SIZE,
"[input] gpu unknown\n");
else if (tmp == 2)
return scnprintf(buf, PAGE_SIZE,
"input [gpu] unknown\n");
}
pr_err("alienware-wmi: unknown HDMI status: %d\n", status);
return scnprintf(buf, PAGE_SIZE, "input gpu [unknown]\n");
}
static ssize_t toggle_hdmi(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct acpi_buffer input;
acpi_status status;
struct hdmi_args args;
if (strcmp(buf, "gpu\n") == 0)
args.arg = 1;
else if (strcmp(buf, "input\n") == 0)
args.arg = 2;
else
args.arg = 3;
pr_debug("alienware-wmi: setting hdmi to %d : %s", args.arg, buf);
input.length = (acpi_size) sizeof(args);
input.pointer = &args;
status = wmi_evaluate_method(WMAX_CONTROL_GUID, 1,
WMAX_METHOD_HDMI_SOURCE, &input, NULL);
if (ACPI_FAILURE(status))
pr_err("alienware-wmi: HDMI toggle failed: results: %u\n",
status);
return count;
}
static void remove_hdmi(struct platform_device *device)
{
device_remove_file(&device->dev, &dev_attr_hdmi);
}
static int create_hdmi(void)
{
int ret = -ENOMEM;
ret = device_create_file(&platform_device->dev, &dev_attr_hdmi);
if (ret)
goto error_create_hdmi;
return 0;
error_create_hdmi:
remove_hdmi(platform_device);
return ret;
}
static int __init alienware_wmi_init(void)
{
int ret;
if (wmi_has_guid(LEGACY_CONTROL_GUID))
interface = LEGACY;
else if (wmi_has_guid(WMAX_CONTROL_GUID))
interface = WMAX;
else {
pr_warn("alienware-wmi: No known WMI GUID found\n");
return -ENODEV;
}
dmi_check_system(alienware_quirks);
if (quirks == NULL)
quirks = &quirk_unknown;
ret = platform_driver_register(&platform_driver);
if (ret)
goto fail_platform_driver;
platform_device = platform_device_alloc("alienware-wmi", -1);
if (!platform_device) {
ret = -ENOMEM;
goto fail_platform_device1;
}
ret = platform_device_add(platform_device);
if (ret)
goto fail_platform_device2;
if (interface == WMAX) {
ret = create_hdmi();
if (ret)
goto fail_prep_hdmi;
}
ret = alienware_zone_init(platform_device);
if (ret)
goto fail_prep_zones;
return 0;
fail_prep_zones:
alienware_zone_exit(platform_device);
fail_prep_hdmi:
platform_device_del(platform_device);
fail_platform_device2:
platform_device_put(platform_device);
fail_platform_device1:
platform_driver_unregister(&platform_driver);
fail_platform_driver:
return ret;
}
static void __exit alienware_wmi_exit(void)
{
if (platform_device) {
alienware_zone_exit(platform_device);
remove_hdmi(platform_device);
platform_device_unregister(platform_device);
platform_driver_unregister(&platform_driver);
}
}
