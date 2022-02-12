static ssize_t class_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct class_attribute *class_attr = to_class_attr(attr);
struct subsys_private *cp = to_subsys_private(kobj);
ssize_t ret = -EIO;
if (class_attr->show)
ret = class_attr->show(cp->class, class_attr, buf);
return ret;
}
static ssize_t class_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct class_attribute *class_attr = to_class_attr(attr);
struct subsys_private *cp = to_subsys_private(kobj);
ssize_t ret = -EIO;
if (class_attr->store)
ret = class_attr->store(cp->class, class_attr, buf, count);
return ret;
}
static void class_release(struct kobject *kobj)
{
struct subsys_private *cp = to_subsys_private(kobj);
struct class *class = cp->class;
pr_debug("class '%s': release.\n", class->name);
if (class->class_release)
class->class_release(class);
else
pr_debug("class '%s' does not have a release() function, "
"be careful\n", class->name);
kfree(cp);
}
static const struct kobj_ns_type_operations *class_child_ns_type(struct kobject *kobj)
{
struct subsys_private *cp = to_subsys_private(kobj);
struct class *class = cp->class;
return class->ns_type;
}
int class_create_file_ns(struct class *cls, const struct class_attribute *attr,
const void *ns)
{
int error;
if (cls)
error = sysfs_create_file_ns(&cls->p->subsys.kobj,
&attr->attr, ns);
else
error = -EINVAL;
return error;
}
void class_remove_file_ns(struct class *cls, const struct class_attribute *attr,
const void *ns)
{
if (cls)
sysfs_remove_file_ns(&cls->p->subsys.kobj, &attr->attr, ns);
}
static struct class *class_get(struct class *cls)
{
if (cls)
kset_get(&cls->p->subsys);
return cls;
}
static void class_put(struct class *cls)
{
if (cls)
kset_put(&cls->p->subsys);
}
static void klist_class_dev_get(struct klist_node *n)
{
struct device *dev = container_of(n, struct device, knode_class);
get_device(dev);
}
static void klist_class_dev_put(struct klist_node *n)
{
struct device *dev = container_of(n, struct device, knode_class);
put_device(dev);
}
static int class_add_groups(struct class *cls,
const struct attribute_group **groups)
{
return sysfs_create_groups(&cls->p->subsys.kobj, groups);
}
static void class_remove_groups(struct class *cls,
const struct attribute_group **groups)
{
return sysfs_remove_groups(&cls->p->subsys.kobj, groups);
}
int __class_register(struct class *cls, struct lock_class_key *key)
{
struct subsys_private *cp;
int error;
pr_debug("device class '%s': registering\n", cls->name);
cp = kzalloc(sizeof(*cp), GFP_KERNEL);
if (!cp)
return -ENOMEM;
klist_init(&cp->klist_devices, klist_class_dev_get, klist_class_dev_put);
INIT_LIST_HEAD(&cp->interfaces);
kset_init(&cp->glue_dirs);
__mutex_init(&cp->mutex, "subsys mutex", key);
error = kobject_set_name(&cp->subsys.kobj, "%s", cls->name);
if (error) {
kfree(cp);
return error;
}
if (!cls->dev_kobj)
cls->dev_kobj = sysfs_dev_char_kobj;
#if defined(CONFIG_BLOCK)
if (!sysfs_deprecated || cls != &block_class)
cp->subsys.kobj.kset = class_kset;
#else
cp->subsys.kobj.kset = class_kset;
#endif
cp->subsys.kobj.ktype = &class_ktype;
cp->class = cls;
cls->p = cp;
error = kset_register(&cp->subsys);
if (error) {
kfree(cp);
return error;
}
error = class_add_groups(class_get(cls), cls->class_groups);
class_put(cls);
return error;
}
void class_unregister(struct class *cls)
{
pr_debug("device class '%s': unregistering\n", cls->name);
class_remove_groups(cls, cls->class_groups);
kset_unregister(&cls->p->subsys);
}
static void class_create_release(struct class *cls)
{
pr_debug("%s called for %s\n", __func__, cls->name);
kfree(cls);
}
struct class *__class_create(struct module *owner, const char *name,
struct lock_class_key *key)
{
struct class *cls;
int retval;
cls = kzalloc(sizeof(*cls), GFP_KERNEL);
if (!cls) {
retval = -ENOMEM;
goto error;
}
cls->name = name;
cls->owner = owner;
cls->class_release = class_create_release;
retval = __class_register(cls, key);
if (retval)
goto error;
return cls;
error:
kfree(cls);
return ERR_PTR(retval);
}
void class_destroy(struct class *cls)
{
if ((cls == NULL) || (IS_ERR(cls)))
return;
class_unregister(cls);
}
void class_dev_iter_init(struct class_dev_iter *iter, struct class *class,
struct device *start, const struct device_type *type)
{
struct klist_node *start_knode = NULL;
if (start)
start_knode = &start->knode_class;
klist_iter_init_node(&class->p->klist_devices, &iter->ki, start_knode);
iter->type = type;
}
struct device *class_dev_iter_next(struct class_dev_iter *iter)
{
struct klist_node *knode;
struct device *dev;
while (1) {
knode = klist_next(&iter->ki);
if (!knode)
return NULL;
dev = container_of(knode, struct device, knode_class);
if (!iter->type || iter->type == dev->type)
return dev;
}
}
void class_dev_iter_exit(struct class_dev_iter *iter)
{
klist_iter_exit(&iter->ki);
}
int class_for_each_device(struct class *class, struct device *start,
void *data, int (*fn)(struct device *, void *))
{
struct class_dev_iter iter;
struct device *dev;
int error = 0;
if (!class)
return -EINVAL;
if (!class->p) {
WARN(1, "%s called for class '%s' before it was initialized",
__func__, class->name);
return -EINVAL;
}
class_dev_iter_init(&iter, class, start, NULL);
while ((dev = class_dev_iter_next(&iter))) {
error = fn(dev, data);
if (error)
break;
}
class_dev_iter_exit(&iter);
return error;
}
struct device *class_find_device(struct class *class, struct device *start,
const void *data,
int (*match)(struct device *, const void *))
{
struct class_dev_iter iter;
struct device *dev;
if (!class)
return NULL;
if (!class->p) {
WARN(1, "%s called for class '%s' before it was initialized",
__func__, class->name);
return NULL;
}
class_dev_iter_init(&iter, class, start, NULL);
while ((dev = class_dev_iter_next(&iter))) {
if (match(dev, data)) {
get_device(dev);
break;
}
}
class_dev_iter_exit(&iter);
return dev;
}
int class_interface_register(struct class_interface *class_intf)
{
struct class *parent;
struct class_dev_iter iter;
struct device *dev;
if (!class_intf || !class_intf->class)
return -ENODEV;
parent = class_get(class_intf->class);
if (!parent)
return -EINVAL;
mutex_lock(&parent->p->mutex);
list_add_tail(&class_intf->node, &parent->p->interfaces);
if (class_intf->add_dev) {
class_dev_iter_init(&iter, parent, NULL, NULL);
while ((dev = class_dev_iter_next(&iter)))
class_intf->add_dev(dev, class_intf);
class_dev_iter_exit(&iter);
}
mutex_unlock(&parent->p->mutex);
return 0;
}
void class_interface_unregister(struct class_interface *class_intf)
{
struct class *parent = class_intf->class;
struct class_dev_iter iter;
struct device *dev;
if (!parent)
return;
mutex_lock(&parent->p->mutex);
list_del_init(&class_intf->node);
if (class_intf->remove_dev) {
class_dev_iter_init(&iter, parent, NULL, NULL);
while ((dev = class_dev_iter_next(&iter)))
class_intf->remove_dev(dev, class_intf);
class_dev_iter_exit(&iter);
}
mutex_unlock(&parent->p->mutex);
class_put(parent);
}
ssize_t show_class_attr_string(struct class *class,
struct class_attribute *attr, char *buf)
{
struct class_attribute_string *cs;
cs = container_of(attr, struct class_attribute_string, attr);
return snprintf(buf, PAGE_SIZE, "%s\n", cs->str);
}
struct class_compat *class_compat_register(const char *name)
{
struct class_compat *cls;
cls = kmalloc(sizeof(struct class_compat), GFP_KERNEL);
if (!cls)
return NULL;
cls->kobj = kobject_create_and_add(name, &class_kset->kobj);
if (!cls->kobj) {
kfree(cls);
return NULL;
}
return cls;
}
void class_compat_unregister(struct class_compat *cls)
{
kobject_put(cls->kobj);
kfree(cls);
}
int class_compat_create_link(struct class_compat *cls, struct device *dev,
struct device *device_link)
{
int error;
error = sysfs_create_link(cls->kobj, &dev->kobj, dev_name(dev));
if (error)
return error;
if (device_link) {
error = sysfs_create_link(&dev->kobj, &device_link->kobj,
"device");
if (error)
sysfs_remove_link(cls->kobj, dev_name(dev));
}
return error;
}
void class_compat_remove_link(struct class_compat *cls, struct device *dev,
struct device *device_link)
{
if (device_link)
sysfs_remove_link(&dev->kobj, "device");
sysfs_remove_link(cls->kobj, dev_name(dev));
}
int __init classes_init(void)
{
class_kset = kset_create_and_add("class", NULL, NULL);
if (!class_kset)
return -ENOMEM;
return 0;
}
