struct device *mdev_parent_dev(struct mdev_device *mdev)
{
return mdev->parent->dev;
}
void *mdev_get_drvdata(struct mdev_device *mdev)
{
return mdev->driver_data;
}
void mdev_set_drvdata(struct mdev_device *mdev, void *data)
{
mdev->driver_data = data;
}
struct device *mdev_dev(struct mdev_device *mdev)
{
return &mdev->dev;
}
struct mdev_device *mdev_from_dev(struct device *dev)
{
return dev_is_mdev(dev) ? to_mdev_device(dev) : NULL;
}
uuid_le mdev_uuid(struct mdev_device *mdev)
{
return mdev->uuid;
}
static int _find_mdev_device(struct device *dev, void *data)
{
struct mdev_device *mdev;
if (!dev_is_mdev(dev))
return 0;
mdev = to_mdev_device(dev);
if (uuid_le_cmp(mdev->uuid, *(uuid_le *)data) == 0)
return 1;
return 0;
}
static bool mdev_device_exist(struct mdev_parent *parent, uuid_le uuid)
{
struct device *dev;
dev = device_find_child(parent->dev, &uuid, _find_mdev_device);
if (dev) {
put_device(dev);
return true;
}
return false;
}
static struct mdev_parent *__find_parent_device(struct device *dev)
{
struct mdev_parent *parent;
list_for_each_entry(parent, &parent_list, next) {
if (parent->dev == dev)
return parent;
}
return NULL;
}
static void mdev_release_parent(struct kref *kref)
{
struct mdev_parent *parent = container_of(kref, struct mdev_parent,
ref);
struct device *dev = parent->dev;
kfree(parent);
put_device(dev);
}
static
inline struct mdev_parent *mdev_get_parent(struct mdev_parent *parent)
{
if (parent)
kref_get(&parent->ref);
return parent;
}
static inline void mdev_put_parent(struct mdev_parent *parent)
{
if (parent)
kref_put(&parent->ref, mdev_release_parent);
}
static int mdev_device_create_ops(struct kobject *kobj,
struct mdev_device *mdev)
{
struct mdev_parent *parent = mdev->parent;
int ret;
ret = parent->ops->create(kobj, mdev);
if (ret)
return ret;
ret = sysfs_create_groups(&mdev->dev.kobj,
parent->ops->mdev_attr_groups);
if (ret)
parent->ops->remove(mdev);
return ret;
}
static int mdev_device_remove_ops(struct mdev_device *mdev, bool force_remove)
{
struct mdev_parent *parent = mdev->parent;
int ret;
ret = parent->ops->remove(mdev);
if (ret && !force_remove)
return -EBUSY;
sysfs_remove_groups(&mdev->dev.kobj, parent->ops->mdev_attr_groups);
return 0;
}
static int mdev_device_remove_cb(struct device *dev, void *data)
{
if (!dev_is_mdev(dev))
return 0;
return mdev_device_remove(dev, data ? *(bool *)data : true);
}
int mdev_register_device(struct device *dev, const struct mdev_parent_ops *ops)
{
int ret;
struct mdev_parent *parent;
if (!ops || !ops->create || !ops->remove || !ops->supported_type_groups)
return -EINVAL;
dev = get_device(dev);
if (!dev)
return -EINVAL;
mutex_lock(&parent_list_lock);
parent = __find_parent_device(dev);
if (parent) {
ret = -EEXIST;
goto add_dev_err;
}
parent = kzalloc(sizeof(*parent), GFP_KERNEL);
if (!parent) {
ret = -ENOMEM;
goto add_dev_err;
}
kref_init(&parent->ref);
mutex_init(&parent->lock);
parent->dev = dev;
parent->ops = ops;
if (!mdev_bus_compat_class) {
mdev_bus_compat_class = class_compat_register("mdev_bus");
if (!mdev_bus_compat_class) {
ret = -ENOMEM;
goto add_dev_err;
}
}
ret = parent_create_sysfs_files(parent);
if (ret)
goto add_dev_err;
ret = class_compat_create_link(mdev_bus_compat_class, dev, NULL);
if (ret)
dev_warn(dev, "Failed to create compatibility class link\n");
list_add(&parent->next, &parent_list);
mutex_unlock(&parent_list_lock);
dev_info(dev, "MDEV: Registered\n");
return 0;
add_dev_err:
mutex_unlock(&parent_list_lock);
if (parent)
mdev_put_parent(parent);
else
put_device(dev);
return ret;
}
void mdev_unregister_device(struct device *dev)
{
struct mdev_parent *parent;
bool force_remove = true;
mutex_lock(&parent_list_lock);
parent = __find_parent_device(dev);
if (!parent) {
mutex_unlock(&parent_list_lock);
return;
}
dev_info(dev, "MDEV: Unregistering\n");
list_del(&parent->next);
class_compat_remove_link(mdev_bus_compat_class, dev, NULL);
device_for_each_child(dev, (void *)&force_remove,
mdev_device_remove_cb);
parent_remove_sysfs_files(parent);
mutex_unlock(&parent_list_lock);
mdev_put_parent(parent);
}
static void mdev_device_release(struct device *dev)
{
struct mdev_device *mdev = to_mdev_device(dev);
dev_dbg(&mdev->dev, "MDEV: destroying\n");
kfree(mdev);
}
int mdev_device_create(struct kobject *kobj, struct device *dev, uuid_le uuid)
{
int ret;
struct mdev_device *mdev;
struct mdev_parent *parent;
struct mdev_type *type = to_mdev_type(kobj);
parent = mdev_get_parent(type->parent);
if (!parent)
return -EINVAL;
mutex_lock(&parent->lock);
if (mdev_device_exist(parent, uuid)) {
ret = -EEXIST;
goto create_err;
}
mdev = kzalloc(sizeof(*mdev), GFP_KERNEL);
if (!mdev) {
ret = -ENOMEM;
goto create_err;
}
memcpy(&mdev->uuid, &uuid, sizeof(uuid_le));
mdev->parent = parent;
kref_init(&mdev->ref);
mdev->dev.parent = dev;
mdev->dev.bus = &mdev_bus_type;
mdev->dev.release = mdev_device_release;
dev_set_name(&mdev->dev, "%pUl", uuid.b);
ret = device_register(&mdev->dev);
if (ret) {
put_device(&mdev->dev);
goto create_err;
}
ret = mdev_device_create_ops(kobj, mdev);
if (ret)
goto create_failed;
ret = mdev_create_sysfs_files(&mdev->dev, type);
if (ret) {
mdev_device_remove_ops(mdev, true);
goto create_failed;
}
mdev->type_kobj = kobj;
dev_dbg(&mdev->dev, "MDEV: created\n");
mutex_unlock(&parent->lock);
mutex_lock(&mdev_list_lock);
list_add(&mdev->next, &mdev_list);
mutex_unlock(&mdev_list_lock);
return ret;
create_failed:
device_unregister(&mdev->dev);
create_err:
mutex_unlock(&parent->lock);
mdev_put_parent(parent);
return ret;
}
int mdev_device_remove(struct device *dev, bool force_remove)
{
struct mdev_device *mdev, *tmp;
struct mdev_parent *parent;
struct mdev_type *type;
int ret;
bool found = false;
mdev = to_mdev_device(dev);
mutex_lock(&mdev_list_lock);
list_for_each_entry(tmp, &mdev_list, next) {
if (tmp == mdev) {
found = true;
break;
}
}
if (found)
list_del(&mdev->next);
mutex_unlock(&mdev_list_lock);
if (!found)
return -ENODEV;
type = to_mdev_type(mdev->type_kobj);
parent = mdev->parent;
mutex_lock(&parent->lock);
ret = mdev_device_remove_ops(mdev, force_remove);
if (ret) {
mutex_unlock(&parent->lock);
mutex_lock(&mdev_list_lock);
list_add(&mdev->next, &mdev_list);
mutex_unlock(&mdev_list_lock);
return ret;
}
mdev_remove_sysfs_files(dev, type);
device_unregister(dev);
mutex_unlock(&parent->lock);
mdev_put_parent(parent);
return 0;
}
static int __init mdev_init(void)
{
return mdev_bus_register();
}
static void __exit mdev_exit(void)
{
if (mdev_bus_compat_class)
class_compat_unregister(mdev_bus_compat_class);
mdev_bus_unregister();
}
