static int fb_notifier_callback(struct notifier_block *self,
unsigned long event, void *data)
{
struct backlight_device *bd;
struct fb_event *evdata = data;
int node = evdata->info->node;
int fb_blank = 0;
if (event != FB_EVENT_BLANK && event != FB_EVENT_CONBLANK)
return 0;
bd = container_of(self, struct backlight_device, fb_notif);
mutex_lock(&bd->ops_lock);
if (bd->ops)
if (!bd->ops->check_fb ||
bd->ops->check_fb(bd, evdata->info)) {
fb_blank = *(int *)evdata->data;
if (fb_blank == FB_BLANK_UNBLANK &&
!bd->fb_bl_on[node]) {
bd->fb_bl_on[node] = true;
if (!bd->use_count++) {
bd->props.state &= ~BL_CORE_FBBLANK;
bd->props.fb_blank = FB_BLANK_UNBLANK;
backlight_update_status(bd);
}
} else if (fb_blank != FB_BLANK_UNBLANK &&
bd->fb_bl_on[node]) {
bd->fb_bl_on[node] = false;
if (!(--bd->use_count)) {
bd->props.state |= BL_CORE_FBBLANK;
bd->props.fb_blank = fb_blank;
backlight_update_status(bd);
}
}
}
mutex_unlock(&bd->ops_lock);
return 0;
}
static int backlight_register_fb(struct backlight_device *bd)
{
memset(&bd->fb_notif, 0, sizeof(bd->fb_notif));
bd->fb_notif.notifier_call = fb_notifier_callback;
return fb_register_client(&bd->fb_notif);
}
static void backlight_unregister_fb(struct backlight_device *bd)
{
fb_unregister_client(&bd->fb_notif);
}
static inline int backlight_register_fb(struct backlight_device *bd)
{
return 0;
}
static inline void backlight_unregister_fb(struct backlight_device *bd)
{
}
static void backlight_generate_event(struct backlight_device *bd,
enum backlight_update_reason reason)
{
char *envp[2];
switch (reason) {
case BACKLIGHT_UPDATE_SYSFS:
envp[0] = "SOURCE=sysfs";
break;
case BACKLIGHT_UPDATE_HOTKEY:
envp[0] = "SOURCE=hotkey";
break;
default:
envp[0] = "SOURCE=unknown";
break;
}
envp[1] = NULL;
kobject_uevent_env(&bd->dev.kobj, KOBJ_CHANGE, envp);
sysfs_notify(&bd->dev.kobj, NULL, "actual_brightness");
}
static ssize_t bl_power_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct backlight_device *bd = to_backlight_device(dev);
return sprintf(buf, "%d\n", bd->props.power);
}
static ssize_t bl_power_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
int rc;
struct backlight_device *bd = to_backlight_device(dev);
unsigned long power, old_power;
rc = kstrtoul(buf, 0, &power);
if (rc)
return rc;
rc = -ENXIO;
mutex_lock(&bd->ops_lock);
if (bd->ops) {
pr_debug("set power to %lu\n", power);
if (bd->props.power != power) {
old_power = bd->props.power;
bd->props.power = power;
rc = backlight_update_status(bd);
if (rc)
bd->props.power = old_power;
else
rc = count;
} else {
rc = count;
}
}
mutex_unlock(&bd->ops_lock);
return rc;
}
static ssize_t brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct backlight_device *bd = to_backlight_device(dev);
return sprintf(buf, "%d\n", bd->props.brightness);
}
int backlight_device_set_brightness(struct backlight_device *bd,
unsigned long brightness)
{
int rc = -ENXIO;
mutex_lock(&bd->ops_lock);
if (bd->ops) {
if (brightness > bd->props.max_brightness)
rc = -EINVAL;
else {
pr_debug("set brightness to %lu\n", brightness);
bd->props.brightness = brightness;
rc = backlight_update_status(bd);
}
}
mutex_unlock(&bd->ops_lock);
backlight_generate_event(bd, BACKLIGHT_UPDATE_SYSFS);
return rc;
}
static ssize_t brightness_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
int rc;
struct backlight_device *bd = to_backlight_device(dev);
unsigned long brightness;
rc = kstrtoul(buf, 0, &brightness);
if (rc)
return rc;
rc = backlight_device_set_brightness(bd, brightness);
return rc ? rc : count;
}
static ssize_t type_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct backlight_device *bd = to_backlight_device(dev);
return sprintf(buf, "%s\n", backlight_types[bd->props.type]);
}
static ssize_t max_brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct backlight_device *bd = to_backlight_device(dev);
return sprintf(buf, "%d\n", bd->props.max_brightness);
}
static ssize_t actual_brightness_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int rc = -ENXIO;
struct backlight_device *bd = to_backlight_device(dev);
mutex_lock(&bd->ops_lock);
if (bd->ops && bd->ops->get_brightness)
rc = sprintf(buf, "%d\n", bd->ops->get_brightness(bd));
else
rc = sprintf(buf, "%d\n", bd->props.brightness);
mutex_unlock(&bd->ops_lock);
return rc;
}
static int backlight_suspend(struct device *dev)
{
struct backlight_device *bd = to_backlight_device(dev);
mutex_lock(&bd->ops_lock);
if (bd->ops && bd->ops->options & BL_CORE_SUSPENDRESUME) {
bd->props.state |= BL_CORE_SUSPENDED;
backlight_update_status(bd);
}
mutex_unlock(&bd->ops_lock);
return 0;
}
static int backlight_resume(struct device *dev)
{
struct backlight_device *bd = to_backlight_device(dev);
mutex_lock(&bd->ops_lock);
if (bd->ops && bd->ops->options & BL_CORE_SUSPENDRESUME) {
bd->props.state &= ~BL_CORE_SUSPENDED;
backlight_update_status(bd);
}
mutex_unlock(&bd->ops_lock);
return 0;
}
static void bl_device_release(struct device *dev)
{
struct backlight_device *bd = to_backlight_device(dev);
kfree(bd);
}
void backlight_force_update(struct backlight_device *bd,
enum backlight_update_reason reason)
{
mutex_lock(&bd->ops_lock);
if (bd->ops && bd->ops->get_brightness)
bd->props.brightness = bd->ops->get_brightness(bd);
mutex_unlock(&bd->ops_lock);
backlight_generate_event(bd, reason);
}
struct backlight_device *backlight_device_register(const char *name,
struct device *parent, void *devdata, const struct backlight_ops *ops,
const struct backlight_properties *props)
{
struct backlight_device *new_bd;
int rc;
pr_debug("backlight_device_register: name=%s\n", name);
new_bd = kzalloc(sizeof(struct backlight_device), GFP_KERNEL);
if (!new_bd)
return ERR_PTR(-ENOMEM);
mutex_init(&new_bd->update_lock);
mutex_init(&new_bd->ops_lock);
new_bd->dev.class = backlight_class;
new_bd->dev.parent = parent;
new_bd->dev.release = bl_device_release;
dev_set_name(&new_bd->dev, "%s", name);
dev_set_drvdata(&new_bd->dev, devdata);
if (props) {
memcpy(&new_bd->props, props,
sizeof(struct backlight_properties));
if (props->type <= 0 || props->type >= BACKLIGHT_TYPE_MAX) {
WARN(1, "%s: invalid backlight type", name);
new_bd->props.type = BACKLIGHT_RAW;
}
} else {
new_bd->props.type = BACKLIGHT_RAW;
}
rc = device_register(&new_bd->dev);
if (rc) {
put_device(&new_bd->dev);
return ERR_PTR(rc);
}
rc = backlight_register_fb(new_bd);
if (rc) {
device_unregister(&new_bd->dev);
return ERR_PTR(rc);
}
new_bd->ops = ops;
#ifdef CONFIG_PMAC_BACKLIGHT
mutex_lock(&pmac_backlight_mutex);
if (!pmac_backlight)
pmac_backlight = new_bd;
mutex_unlock(&pmac_backlight_mutex);
#endif
mutex_lock(&backlight_dev_list_mutex);
list_add(&new_bd->entry, &backlight_dev_list);
mutex_unlock(&backlight_dev_list_mutex);
blocking_notifier_call_chain(&backlight_notifier,
BACKLIGHT_REGISTERED, new_bd);
return new_bd;
}
struct backlight_device *backlight_device_get_by_type(enum backlight_type type)
{
bool found = false;
struct backlight_device *bd;
mutex_lock(&backlight_dev_list_mutex);
list_for_each_entry(bd, &backlight_dev_list, entry) {
if (bd->props.type == type) {
found = true;
break;
}
}
mutex_unlock(&backlight_dev_list_mutex);
return found ? bd : NULL;
}
void backlight_device_unregister(struct backlight_device *bd)
{
if (!bd)
return;
mutex_lock(&backlight_dev_list_mutex);
list_del(&bd->entry);
mutex_unlock(&backlight_dev_list_mutex);
#ifdef CONFIG_PMAC_BACKLIGHT
mutex_lock(&pmac_backlight_mutex);
if (pmac_backlight == bd)
pmac_backlight = NULL;
mutex_unlock(&pmac_backlight_mutex);
#endif
blocking_notifier_call_chain(&backlight_notifier,
BACKLIGHT_UNREGISTERED, bd);
mutex_lock(&bd->ops_lock);
bd->ops = NULL;
mutex_unlock(&bd->ops_lock);
backlight_unregister_fb(bd);
device_unregister(&bd->dev);
}
static void devm_backlight_device_release(struct device *dev, void *res)
{
struct backlight_device *backlight = *(struct backlight_device **)res;
backlight_device_unregister(backlight);
}
static int devm_backlight_device_match(struct device *dev, void *res,
void *data)
{
struct backlight_device **r = res;
return *r == data;
}
int backlight_register_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_register(&backlight_notifier, nb);
}
int backlight_unregister_notifier(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(&backlight_notifier, nb);
}
struct backlight_device *devm_backlight_device_register(struct device *dev,
const char *name, struct device *parent, void *devdata,
const struct backlight_ops *ops,
const struct backlight_properties *props)
{
struct backlight_device **ptr, *backlight;
ptr = devres_alloc(devm_backlight_device_release, sizeof(*ptr),
GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
backlight = backlight_device_register(name, parent, devdata, ops,
props);
if (!IS_ERR(backlight)) {
*ptr = backlight;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return backlight;
}
void devm_backlight_device_unregister(struct device *dev,
struct backlight_device *bd)
{
int rc;
rc = devres_release(dev, devm_backlight_device_release,
devm_backlight_device_match, bd);
WARN_ON(rc);
}
static int of_parent_match(struct device *dev, const void *data)
{
return dev->parent && dev->parent->of_node == data;
}
struct backlight_device *of_find_backlight_by_node(struct device_node *node)
{
struct device *dev;
dev = class_find_device(backlight_class, NULL, node, of_parent_match);
return dev ? to_backlight_device(dev) : NULL;
}
static void __exit backlight_class_exit(void)
{
class_destroy(backlight_class);
}
static int __init backlight_class_init(void)
{
backlight_class = class_create(THIS_MODULE, "backlight");
if (IS_ERR(backlight_class)) {
pr_warn("Unable to create backlight class; errno = %ld\n",
PTR_ERR(backlight_class));
return PTR_ERR(backlight_class);
}
backlight_class->dev_groups = bl_device_groups;
backlight_class->pm = &backlight_class_dev_pm_ops;
INIT_LIST_HEAD(&backlight_dev_list);
mutex_init(&backlight_dev_list_mutex);
BLOCKING_INIT_NOTIFIER_HEAD(&backlight_notifier);
return 0;
}
