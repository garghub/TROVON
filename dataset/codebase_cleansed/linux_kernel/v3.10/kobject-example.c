static ssize_t foo_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
return sprintf(buf, "%d\n", foo);
}
static ssize_t foo_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
sscanf(buf, "%du", &foo);
return count;
}
static ssize_t b_show(struct kobject *kobj, struct kobj_attribute *attr,
char *buf)
{
int var;
if (strcmp(attr->attr.name, "baz") == 0)
var = baz;
else
var = bar;
return sprintf(buf, "%d\n", var);
}
static ssize_t b_store(struct kobject *kobj, struct kobj_attribute *attr,
const char *buf, size_t count)
{
int var;
sscanf(buf, "%du", &var);
if (strcmp(attr->attr.name, "baz") == 0)
baz = var;
else
bar = var;
return count;
}
static int __init example_init(void)
{
int retval;
example_kobj = kobject_create_and_add("kobject_example", kernel_kobj);
if (!example_kobj)
return -ENOMEM;
retval = sysfs_create_group(example_kobj, &attr_group);
if (retval)
kobject_put(example_kobj);
return retval;
}
static void __exit example_exit(void)
{
kobject_put(example_kobj);
}
