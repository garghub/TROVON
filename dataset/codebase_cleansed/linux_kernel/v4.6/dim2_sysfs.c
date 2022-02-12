static ssize_t state_show(struct medialb_bus *bus, char *buf)
{
bool state = dim2_sysfs_get_state_cb();
return sprintf(buf, "%s\n", state ? "locked" : "");
}
static void bus_kobj_release(struct kobject *kobj)
{
}
static ssize_t bus_kobj_attr_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct medialb_bus *bus =
container_of(kobj, struct medialb_bus, kobj_group);
struct bus_attr *xattr = container_of(attr, struct bus_attr, attr);
if (!xattr->show)
return -EIO;
return xattr->show(bus, buf);
}
static ssize_t bus_kobj_attr_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct medialb_bus *bus =
container_of(kobj, struct medialb_bus, kobj_group);
struct bus_attr *xattr = container_of(attr, struct bus_attr, attr);
if (!xattr->store)
return -EIO;
return xattr->store(bus, buf, count);
}
int dim2_sysfs_probe(struct medialb_bus *bus, struct kobject *parent_kobj)
{
int err;
kobject_init(&bus->kobj_group, &bus_ktype);
err = kobject_add(&bus->kobj_group, parent_kobj, "bus");
if (err) {
pr_err("kobject_add() failed: %d\n", err);
goto err_kobject_add;
}
err = sysfs_create_group(&bus->kobj_group, &bus_attr_group);
if (err) {
pr_err("sysfs_create_group() failed: %d\n", err);
goto err_create_group;
}
return 0;
err_create_group:
kobject_put(&bus->kobj_group);
err_kobject_add:
return err;
}
void dim2_sysfs_destroy(struct medialb_bus *bus)
{
kobject_put(&bus->kobj_group);
}
