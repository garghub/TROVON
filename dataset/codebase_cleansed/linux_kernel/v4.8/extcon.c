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
static int find_cable_index_by_id(struct extcon_dev *edev, const unsigned int id)
{
int i;
for (i = 0; i < edev->max_supported; i++) {
if (edev->supported_cable[i] == id)
return i;
}
return -EINVAL;
}
static bool is_extcon_changed(u32 prev, u32 new, int idx, bool *attached)
{
if (((prev >> idx) & 0x1) != ((new >> idx) & 0x1)) {
*attached = ((new >> idx) & 0x1) ? true : false;
return true;
}
return false;
}
static ssize_t state_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
int i, count = 0;
struct extcon_dev *edev = dev_get_drvdata(dev);
if (edev->max_supported == 0)
return sprintf(buf, "%u\n", edev->state);
for (i = 0; i < edev->max_supported; i++) {
count += sprintf(buf + count, "%s=%d\n",
extcon_name[edev->supported_cable[i]],
!!(edev->state & (1 << i)));
}
return count;
}
static ssize_t state_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
u32 state;
ssize_t ret = 0;
struct extcon_dev *edev = dev_get_drvdata(dev);
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
struct extcon_dev *edev = dev_get_drvdata(dev);
return sprintf(buf, "%s\n", edev->name);
}
static ssize_t cable_name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct extcon_cable *cable = container_of(attr, struct extcon_cable,
attr_name);
int i = cable->cable_index;
return sprintf(buf, "%s\n",
extcon_name[cable->edev->supported_cable[i]]);
}
static ssize_t cable_state_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct extcon_cable *cable = container_of(attr, struct extcon_cable,
attr_state);
int i = cable->cable_index;
return sprintf(buf, "%d\n",
extcon_get_cable_state_(cable->edev,
cable->edev->supported_cable[i]));
}
int extcon_update_state(struct extcon_dev *edev, u32 mask, u32 state)
{
char name_buf[120];
char state_buf[120];
char *prop_buf;
char *envp[3];
int env_offset = 0;
int length;
int index;
unsigned long flags;
bool attached;
if (!edev)
return -EINVAL;
spin_lock_irqsave(&edev->lock, flags);
if (edev->state != ((edev->state & ~mask) | (state & mask))) {
u32 old_state;
if (check_mutually_exclusive(edev, (edev->state & ~mask) |
(state & mask))) {
spin_unlock_irqrestore(&edev->lock, flags);
return -EPERM;
}
old_state = edev->state;
edev->state &= ~mask;
edev->state |= state & mask;
for (index = 0; index < edev->max_supported; index++) {
if (is_extcon_changed(old_state, edev->state, index,
&attached))
raw_notifier_call_chain(&edev->nh[index],
attached, edev);
}
prop_buf = (char *)get_zeroed_page(GFP_ATOMIC);
if (prop_buf) {
length = name_show(&edev->dev, NULL, prop_buf);
if (length > 0) {
if (prop_buf[length - 1] == '\n')
prop_buf[length - 1] = 0;
snprintf(name_buf, sizeof(name_buf),
"NAME=%s", prop_buf);
envp[env_offset++] = name_buf;
}
length = state_show(&edev->dev, NULL, prop_buf);
if (length > 0) {
if (prop_buf[length - 1] == '\n')
prop_buf[length - 1] = 0;
snprintf(state_buf, sizeof(state_buf),
"STATE=%s", prop_buf);
envp[env_offset++] = state_buf;
}
envp[env_offset] = NULL;
spin_unlock_irqrestore(&edev->lock, flags);
kobject_uevent_env(&edev->dev.kobj, KOBJ_CHANGE, envp);
free_page((unsigned long)prop_buf);
} else {
spin_unlock_irqrestore(&edev->lock, flags);
dev_err(&edev->dev, "out of memory in extcon_set_state\n");
kobject_uevent(&edev->dev.kobj, KOBJ_CHANGE);
}
} else {
spin_unlock_irqrestore(&edev->lock, flags);
}
return 0;
}
int extcon_set_state(struct extcon_dev *edev, u32 state)
{
if (!edev)
return -EINVAL;
return extcon_update_state(edev, 0xffffffff, state);
}
int extcon_get_cable_state_(struct extcon_dev *edev, const unsigned int id)
{
int index;
if (!edev)
return -EINVAL;
index = find_cable_index_by_id(edev, id);
if (index < 0)
return index;
if (edev->max_supported && edev->max_supported <= index)
return -EINVAL;
return !!(edev->state & (1 << index));
}
int extcon_set_cable_state_(struct extcon_dev *edev, unsigned int id,
bool cable_state)
{
u32 state;
int index;
if (!edev)
return -EINVAL;
index = find_cable_index_by_id(edev, id);
if (index < 0)
return index;
if (edev->max_supported && edev->max_supported <= index)
return -EINVAL;
state = cable_state ? (1 << index) : 0;
return extcon_update_state(edev, 1 << index, state);
}
struct extcon_dev *extcon_get_extcon_dev(const char *extcon_name)
{
struct extcon_dev *sd;
if (!extcon_name)
return ERR_PTR(-EINVAL);
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
int extcon_register_notifier(struct extcon_dev *edev, unsigned int id,
struct notifier_block *nb)
{
unsigned long flags;
int ret, idx;
if (!nb)
return -EINVAL;
if (edev) {
idx = find_cable_index_by_id(edev, id);
if (idx < 0)
return idx;
spin_lock_irqsave(&edev->lock, flags);
ret = raw_notifier_chain_register(&edev->nh[idx], nb);
spin_unlock_irqrestore(&edev->lock, flags);
} else {
struct extcon_dev *extd;
mutex_lock(&extcon_dev_list_lock);
list_for_each_entry(extd, &extcon_dev_list, entry) {
idx = find_cable_index_by_id(extd, id);
if (idx >= 0)
break;
}
mutex_unlock(&extcon_dev_list_lock);
if (idx >= 0) {
edev = extd;
return extcon_register_notifier(extd, id, nb);
} else {
ret = -ENODEV;
}
}
return ret;
}
int extcon_unregister_notifier(struct extcon_dev *edev, unsigned int id,
struct notifier_block *nb)
{
unsigned long flags;
int ret, idx;
if (!edev || !nb)
return -EINVAL;
idx = find_cable_index_by_id(edev, id);
if (idx < 0)
return idx;
spin_lock_irqsave(&edev->lock, flags);
ret = raw_notifier_chain_unregister(&edev->nh[idx], nb);
spin_unlock_irqrestore(&edev->lock, flags);
return ret;
}
static int create_extcon_class(void)
{
if (!extcon_class) {
extcon_class = class_create(THIS_MODULE, "extcon");
if (IS_ERR(extcon_class))
return PTR_ERR(extcon_class);
extcon_class->dev_groups = extcon_groups;
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
}
static void dummy_sysfs_dev_release(struct device *dev)
{
}
struct extcon_dev *extcon_dev_allocate(const unsigned int *supported_cable)
{
struct extcon_dev *edev;
if (!supported_cable)
return ERR_PTR(-EINVAL);
edev = kzalloc(sizeof(*edev), GFP_KERNEL);
if (!edev)
return ERR_PTR(-ENOMEM);
edev->max_supported = 0;
edev->supported_cable = supported_cable;
return edev;
}
void extcon_dev_free(struct extcon_dev *edev)
{
kfree(edev);
}
int extcon_dev_register(struct extcon_dev *edev)
{
int ret, index = 0;
static atomic_t edev_no = ATOMIC_INIT(-1);
if (!extcon_class) {
ret = create_extcon_class();
if (ret < 0)
return ret;
}
if (!edev || !edev->supported_cable)
return -EINVAL;
for (; edev->supported_cable[index] != EXTCON_NONE; index++);
edev->max_supported = index;
if (index > SUPPORTED_CABLE_MAX) {
dev_err(&edev->dev,
"exceed the maximum number of supported cables\n");
return -EINVAL;
}
edev->dev.class = extcon_class;
edev->dev.release = extcon_dev_release;
edev->name = dev_name(edev->dev.parent);
if (IS_ERR_OR_NULL(edev->name)) {
dev_err(&edev->dev,
"extcon device name is null\n");
return -EINVAL;
}
dev_set_name(&edev->dev, "extcon%lu",
(unsigned long)atomic_inc_return(&edev_no));
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
cable->attr_state.attr.mode = 0444;
cable->attr_state.show = cable_state_show;
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
edev->extcon_dev_type.name = dev_name(&edev->dev);
edev->extcon_dev_type.release = dummy_sysfs_dev_release;
for (index = 0; index < edev->max_supported; index++)
edev->extcon_dev_type.groups[index] =
&edev->cables[index].attr_g;
if (edev->mutually_exclusive)
edev->extcon_dev_type.groups[index] =
&edev->attr_g_muex;
edev->dev.type = &edev->extcon_dev_type;
}
ret = device_register(&edev->dev);
if (ret) {
put_device(&edev->dev);
goto err_dev;
}
#if defined(CONFIG_ANDROID)
if (switch_class)
ret = class_compat_create_link(switch_class, &edev->dev, NULL);
#endif
spin_lock_init(&edev->lock);
edev->nh = devm_kzalloc(&edev->dev,
sizeof(*edev->nh) * edev->max_supported, GFP_KERNEL);
if (!edev->nh) {
ret = -ENOMEM;
goto err_dev;
}
for (index = 0; index < edev->max_supported; index++)
RAW_INIT_NOTIFIER_HEAD(&edev->nh[index]);
dev_set_drvdata(&edev->dev, edev);
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
return ret;
}
void extcon_dev_unregister(struct extcon_dev *edev)
{
int index;
if (!edev)
return;
mutex_lock(&extcon_dev_list_lock);
list_del(&edev->entry);
mutex_unlock(&extcon_dev_list_lock);
if (IS_ERR_OR_NULL(get_device(&edev->dev))) {
dev_err(&edev->dev, "Failed to unregister extcon_dev (%s)\n",
dev_name(&edev->dev));
return;
}
device_unregister(&edev->dev);
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
class_compat_remove_link(switch_class, &edev->dev, NULL);
#endif
put_device(&edev->dev);
}
struct extcon_dev *extcon_get_edev_by_phandle(struct device *dev, int index)
{
struct device_node *node;
struct extcon_dev *edev;
if (!dev)
return ERR_PTR(-EINVAL);
if (!dev->of_node) {
dev_err(dev, "device does not have a device node entry\n");
return ERR_PTR(-EINVAL);
}
node = of_parse_phandle(dev->of_node, "extcon", index);
if (!node) {
dev_err(dev, "failed to get phandle in %s node\n",
dev->of_node->full_name);
return ERR_PTR(-ENODEV);
}
mutex_lock(&extcon_dev_list_lock);
list_for_each_entry(edev, &extcon_dev_list, entry) {
if (edev->dev.parent && edev->dev.parent->of_node == node) {
mutex_unlock(&extcon_dev_list_lock);
of_node_put(node);
return edev;
}
}
mutex_unlock(&extcon_dev_list_lock);
of_node_put(node);
return ERR_PTR(-EPROBE_DEFER);
}
struct extcon_dev *extcon_get_edev_by_phandle(struct device *dev, int index)
{
return ERR_PTR(-ENOSYS);
}
const char *extcon_get_edev_name(struct extcon_dev *edev)
{
return !edev ? NULL : edev->name;
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
