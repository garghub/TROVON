static int check_mutually_exclusive(struct extcon_dev *edev, u32 new_state)
{
int i = 0;
if (!edev->mutually_exclusive)
return 0;
for (i = 0; edev->mutually_exclusive[i]; i++) {
int weight;
u32 correspondants = new_state & edev->mutually_exclusive[i];
weight = hweight32(correspondants);
if (weight > 1)
return i + 1;
}
return 0;
}
static ssize_t state_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int i, count = 0;
struct extcon_dev *edev = (struct extcon_dev *) dev_get_drvdata(dev);
if (edev->print_state) {
int ret = edev->print_state(edev, buf);
if (ret >= 0)
return ret;
}
if (edev->max_supported == 0)
return sprintf(buf, "%u\n", edev->state);
for (i = 0; i < SUPPORTED_CABLE_MAX; i++) {
if (!edev->supported_cable[i])
break;
count += sprintf(buf + count, "%s=%d\n",
edev->supported_cable[i],
!!(edev->state & (1 << i)));
}
return count;
}
static ssize_t state_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
u32 state;
ssize_t ret = 0;
struct extcon_dev *edev = (struct extcon_dev *) dev_get_drvdata(dev);
ret = sscanf(buf, "0x%x", &state);
if (ret == 0)
ret = -EINVAL;
else
ret = extcon_set_state(edev, state);
if (ret < 0)
return ret;
return count;
}
static ssize_t name_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct extcon_dev *edev = (struct extcon_dev *) dev_get_drvdata(dev);
if (edev->print_name) {
int ret = edev->print_name(edev, buf);
if (ret >= 0)
return ret;
}
return sprintf(buf, "%s\n", dev_name(edev->dev));
}
static ssize_t cable_name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct extcon_cable *cable = container_of(attr, struct extcon_cable,
attr_name);
return sprintf(buf, "%s\n",
cable->edev->supported_cable[cable->cable_index]);
}
static ssize_t cable_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct extcon_cable *cable = container_of(attr, struct extcon_cable,
attr_state);
return sprintf(buf, "%d\n",
extcon_get_cable_state_(cable->edev,
cable->cable_index));
}
static ssize_t cable_state_store(struct device *dev,
struct device_attribute *attr, const char *buf,
size_t count)
{
struct extcon_cable *cable = container_of(attr, struct extcon_cable,
attr_state);
int ret, state;
ret = sscanf(buf, "%d", &state);
if (ret == 0)
ret = -EINVAL;
else
ret = extcon_set_cable_state_(cable->edev, cable->cable_index,
state);
if (ret < 0)
return ret;
return count;
}
int extcon_update_state(struct extcon_dev *edev, u32 mask, u32 state)
{
char name_buf[120];
char state_buf[120];
char *prop_buf;
char *envp[3];
int env_offset = 0;
int length;
unsigned long flags;
spin_lock_irqsave(&edev->lock, flags);
if (edev->state != ((edev->state & ~mask) | (state & mask))) {
u32 old_state = edev->state;
if (check_mutually_exclusive(edev, (edev->state & ~mask) |
(state & mask))) {
spin_unlock_irqrestore(&edev->lock, flags);
return -EPERM;
}
edev->state &= ~mask;
edev->state |= state & mask;
raw_notifier_call_chain(&edev->nh, old_state, edev);
prop_buf = (char *)get_zeroed_page(GFP_ATOMIC);
if (prop_buf) {
length = name_show(edev->dev, NULL, prop_buf);
if (length > 0) {
if (prop_buf[length - 1] == '\n')
prop_buf[length - 1] = 0;
snprintf(name_buf, sizeof(name_buf),
"NAME=%s", prop_buf);
envp[env_offset++] = name_buf;
}
length = state_show(edev->dev, NULL, prop_buf);
if (length > 0) {
if (prop_buf[length - 1] == '\n')
prop_buf[length - 1] = 0;
snprintf(state_buf, sizeof(state_buf),
"STATE=%s", prop_buf);
envp[env_offset++] = state_buf;
}
envp[env_offset] = NULL;
spin_unlock_irqrestore(&edev->lock, flags);
kobject_uevent_env(&edev->dev->kobj, KOBJ_CHANGE, envp);
free_page((unsigned long)prop_buf);
} else {
spin_unlock_irqrestore(&edev->lock, flags);
dev_err(edev->dev, "out of memory in extcon_set_state\n");
kobject_uevent(&edev->dev->kobj, KOBJ_CHANGE);
}
} else {
spin_unlock_irqrestore(&edev->lock, flags);
}
return 0;
}
int extcon_set_state(struct extcon_dev *edev, u32 state)
{
return extcon_update_state(edev, 0xffffffff, state);
}
int extcon_find_cable_index(struct extcon_dev *edev, const char *cable_name)
{
int i;
if (edev->supported_cable) {
for (i = 0; edev->supported_cable[i]; i++) {
if (!strncmp(edev->supported_cable[i],
cable_name, CABLE_NAME_MAX))
return i;
}
}
return -EINVAL;
}
int extcon_get_cable_state_(struct extcon_dev *edev, int index)
{
if (index < 0 || (edev->max_supported && edev->max_supported <= index))
return -EINVAL;
return !!(edev->state & (1 << index));
}
int extcon_get_cable_state(struct extcon_dev *edev, const char *cable_name)
{
return extcon_get_cable_state_(edev, extcon_find_cable_index
(edev, cable_name));
}
int extcon_set_cable_state_(struct extcon_dev *edev,
int index, bool cable_state)
{
u32 state;
if (index < 0 || (edev->max_supported && edev->max_supported <= index))
return -EINVAL;
state = cable_state ? (1 << index) : 0;
return extcon_update_state(edev, 1 << index, state);
}
int extcon_set_cable_state(struct extcon_dev *edev,
const char *cable_name, bool cable_state)
{
return extcon_set_cable_state_(edev, extcon_find_cable_index
(edev, cable_name), cable_state);
}
struct extcon_dev *extcon_get_extcon_dev(const char *extcon_name)
{
struct extcon_dev *sd;
mutex_lock(&extcon_dev_list_lock);
list_for_each_entry(sd, &extcon_dev_list, entry) {
if (!strcmp(sd->name, extcon_name))
goto out;
}
sd = NULL;
out:
mutex_unlock(&extcon_dev_list_lock);
return sd;
}
static int _call_per_cable(struct notifier_block *nb, unsigned long val,
void *ptr)
{
struct extcon_specific_cable_nb *obj = container_of(nb,
struct extcon_specific_cable_nb, internal_nb);
struct extcon_dev *edev = ptr;
if ((val & (1 << obj->cable_index)) !=
(edev->state & (1 << obj->cable_index))) {
bool cable_state = true;
obj->previous_value = val;
if (val & (1 << obj->cable_index))
cable_state = false;
return obj->user_nb->notifier_call(obj->user_nb,
cable_state, ptr);
}
return NOTIFY_OK;
}
int extcon_register_interest(struct extcon_specific_cable_nb *obj,
const char *extcon_name, const char *cable_name,
struct notifier_block *nb)
{
if (!obj || !cable_name || !nb)
return -EINVAL;
if (extcon_name) {
obj->edev = extcon_get_extcon_dev(extcon_name);
if (!obj->edev)
return -ENODEV;
obj->cable_index = extcon_find_cable_index(obj->edev, cable_name);
if (obj->cable_index < 0)
return obj->cable_index;
obj->user_nb = nb;
obj->internal_nb.notifier_call = _call_per_cable;
return raw_notifier_chain_register(&obj->edev->nh, &obj->internal_nb);
} else {
struct class_dev_iter iter;
struct extcon_dev *extd;
struct device *dev;
if (!extcon_class)
return -ENODEV;
class_dev_iter_init(&iter, extcon_class, NULL, NULL);
while ((dev = class_dev_iter_next(&iter))) {
extd = (struct extcon_dev *)dev_get_drvdata(dev);
if (extcon_find_cable_index(extd, cable_name) < 0)
continue;
class_dev_iter_exit(&iter);
return extcon_register_interest(obj, extd->name,
cable_name, nb);
}
return -ENODEV;
}
}
int extcon_unregister_interest(struct extcon_specific_cable_nb *obj)
{
if (!obj)
return -EINVAL;
return raw_notifier_chain_unregister(&obj->edev->nh, &obj->internal_nb);
}
int extcon_register_notifier(struct extcon_dev *edev,
struct notifier_block *nb)
{
return raw_notifier_chain_register(&edev->nh, nb);
}
int extcon_unregister_notifier(struct extcon_dev *edev,
struct notifier_block *nb)
{
return raw_notifier_chain_unregister(&edev->nh, nb);
}
static int create_extcon_class(void)
{
if (!extcon_class) {
extcon_class = class_create(THIS_MODULE, "extcon");
if (IS_ERR(extcon_class))
return PTR_ERR(extcon_class);
extcon_class->dev_attrs = extcon_attrs;
#if defined(CONFIG_ANDROID)
switch_class = class_compat_register("switch");
if (WARN(!switch_class, "cannot allocate"))
return -ENOMEM;
#endif
}
return 0;
}
static void extcon_dev_release(struct device *dev)
{
kfree(dev);
}
static void dummy_sysfs_dev_release(struct device *dev)
{
}
int extcon_dev_register(struct extcon_dev *edev, struct device *dev)
{
int ret, index = 0;
if (!extcon_class) {
ret = create_extcon_class();
if (ret < 0)
return ret;
}
if (edev->supported_cable) {
for (index = 0; edev->supported_cable[index]; index++)
;
edev->max_supported = index;
} else {
edev->max_supported = 0;
}
if (index > SUPPORTED_CABLE_MAX) {
dev_err(edev->dev, "extcon: maximum number of supported cables exceeded.\n");
return -EINVAL;
}
edev->dev = kzalloc(sizeof(struct device), GFP_KERNEL);
if (!edev->dev)
return -ENOMEM;
edev->dev->parent = dev;
edev->dev->class = extcon_class;
edev->dev->release = extcon_dev_release;
dev_set_name(edev->dev, edev->name ? edev->name : dev_name(dev));
if (edev->max_supported) {
char buf[10];
char *str;
struct extcon_cable *cable;
edev->cables = kzalloc(sizeof(struct extcon_cable) *
edev->max_supported, GFP_KERNEL);
if (!edev->cables) {
ret = -ENOMEM;
goto err_sysfs_alloc;
}
for (index = 0; index < edev->max_supported; index++) {
cable = &edev->cables[index];
snprintf(buf, 10, "cable.%d", index);
str = kzalloc(sizeof(char) * (strlen(buf) + 1),
GFP_KERNEL);
if (!str) {
for (index--; index >= 0; index--) {
cable = &edev->cables[index];
kfree(cable->attr_g.name);
}
ret = -ENOMEM;
goto err_alloc_cables;
}
strcpy(str, buf);
cable->edev = edev;
cable->cable_index = index;
cable->attrs[0] = &cable->attr_name.attr;
cable->attrs[1] = &cable->attr_state.attr;
cable->attrs[2] = NULL;
cable->attr_g.name = str;
cable->attr_g.attrs = cable->attrs;
sysfs_attr_init(&cable->attr_name.attr);
cable->attr_name.attr.name = "name";
cable->attr_name.attr.mode = 0444;
cable->attr_name.show = cable_name_show;
sysfs_attr_init(&cable->attr_state.attr);
cable->attr_state.attr.name = "state";
cable->attr_state.attr.mode = 0644;
cable->attr_state.show = cable_state_show;
cable->attr_state.store = cable_state_store;
}
}
if (edev->max_supported && edev->mutually_exclusive) {
char buf[80];
char *name;
for (index = 0; edev->mutually_exclusive[index]; index++)
;
edev->attrs_muex = kzalloc(sizeof(struct attribute *) *
(index + 1), GFP_KERNEL);
if (!edev->attrs_muex) {
ret = -ENOMEM;
goto err_muex;
}
edev->d_attrs_muex = kzalloc(sizeof(struct device_attribute) *
index, GFP_KERNEL);
if (!edev->d_attrs_muex) {
ret = -ENOMEM;
kfree(edev->attrs_muex);
goto err_muex;
}
for (index = 0; edev->mutually_exclusive[index]; index++) {
sprintf(buf, "0x%x", edev->mutually_exclusive[index]);
name = kzalloc(sizeof(char) * (strlen(buf) + 1),
GFP_KERNEL);
if (!name) {
for (index--; index >= 0; index--) {
kfree(edev->d_attrs_muex[index].attr.
name);
}
kfree(edev->d_attrs_muex);
kfree(edev->attrs_muex);
ret = -ENOMEM;
goto err_muex;
}
strcpy(name, buf);
sysfs_attr_init(&edev->d_attrs_muex[index].attr);
edev->d_attrs_muex[index].attr.name = name;
edev->d_attrs_muex[index].attr.mode = 0000;
edev->attrs_muex[index] = &edev->d_attrs_muex[index]
.attr;
}
edev->attr_g_muex.name = muex_name;
edev->attr_g_muex.attrs = edev->attrs_muex;
}
if (edev->max_supported) {
edev->extcon_dev_type.groups =
kzalloc(sizeof(struct attribute_group *) *
(edev->max_supported + 2), GFP_KERNEL);
if (!edev->extcon_dev_type.groups) {
ret = -ENOMEM;
goto err_alloc_groups;
}
edev->extcon_dev_type.name = dev_name(edev->dev);
edev->extcon_dev_type.release = dummy_sysfs_dev_release;
for (index = 0; index < edev->max_supported; index++)
edev->extcon_dev_type.groups[index] =
&edev->cables[index].attr_g;
if (edev->mutually_exclusive)
edev->extcon_dev_type.groups[index] =
&edev->attr_g_muex;
edev->dev->type = &edev->extcon_dev_type;
}
ret = device_register(edev->dev);
if (ret) {
put_device(edev->dev);
goto err_dev;
}
#if defined(CONFIG_ANDROID)
if (switch_class)
ret = class_compat_create_link(switch_class, edev->dev,
NULL);
#endif
spin_lock_init(&edev->lock);
RAW_INIT_NOTIFIER_HEAD(&edev->nh);
dev_set_drvdata(edev->dev, edev);
edev->state = 0;
mutex_lock(&extcon_dev_list_lock);
list_add(&edev->entry, &extcon_dev_list);
mutex_unlock(&extcon_dev_list_lock);
return 0;
err_dev:
if (edev->max_supported)
kfree(edev->extcon_dev_type.groups);
err_alloc_groups:
if (edev->max_supported && edev->mutually_exclusive) {
for (index = 0; edev->mutually_exclusive[index]; index++)
kfree(edev->d_attrs_muex[index].attr.name);
kfree(edev->d_attrs_muex);
kfree(edev->attrs_muex);
}
err_muex:
for (index = 0; index < edev->max_supported; index++)
kfree(edev->cables[index].attr_g.name);
err_alloc_cables:
if (edev->max_supported)
kfree(edev->cables);
err_sysfs_alloc:
kfree(edev->dev);
return ret;
}
void extcon_dev_unregister(struct extcon_dev *edev)
{
int index;
mutex_lock(&extcon_dev_list_lock);
list_del(&edev->entry);
mutex_unlock(&extcon_dev_list_lock);
if (IS_ERR_OR_NULL(get_device(edev->dev))) {
dev_err(edev->dev, "Failed to unregister extcon_dev (%s)\n",
dev_name(edev->dev));
return;
}
if (edev->mutually_exclusive && edev->max_supported) {
for (index = 0; edev->mutually_exclusive[index];
index++)
kfree(edev->d_attrs_muex[index].attr.name);
kfree(edev->d_attrs_muex);
kfree(edev->attrs_muex);
}
for (index = 0; index < edev->max_supported; index++)
kfree(edev->cables[index].attr_g.name);
if (edev->max_supported) {
kfree(edev->extcon_dev_type.groups);
kfree(edev->cables);
}
#if defined(CONFIG_ANDROID)
if (switch_class)
class_compat_remove_link(switch_class, edev->dev, NULL);
#endif
device_unregister(edev->dev);
put_device(edev->dev);
}
static int __init extcon_class_init(void)
{
return create_extcon_class();
}
static void __exit extcon_class_exit(void)
{
#if defined(CONFIG_ANDROID)
class_compat_unregister(switch_class);
#endif
class_destroy(extcon_class);
}
