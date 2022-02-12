static ssize_t foo_attr_show(struct kobject *kobj,
struct attribute *attr,
char *buf)
{
struct foo_attribute *attribute;
struct foo_obj *foo;
attribute = to_foo_attr(attr);
foo = to_foo_obj(kobj);
if (!attribute->show)
return -EIO;
return attribute->show(foo, attribute, buf);
}
static ssize_t foo_attr_store(struct kobject *kobj,
struct attribute *attr,
const char *buf, size_t len)
{
struct foo_attribute *attribute;
struct foo_obj *foo;
attribute = to_foo_attr(attr);
foo = to_foo_obj(kobj);
if (!attribute->store)
return -EIO;
return attribute->store(foo, attribute, buf, len);
}
static void foo_release(struct kobject *kobj)
{
struct foo_obj *foo;
foo = to_foo_obj(kobj);
kfree(foo);
}
static ssize_t foo_show(struct foo_obj *foo_obj, struct foo_attribute *attr,
char *buf)
{
return sprintf(buf, "%d\n", foo_obj->foo);
}
static ssize_t foo_store(struct foo_obj *foo_obj, struct foo_attribute *attr,
const char *buf, size_t count)
{
sscanf(buf, "%du", &foo_obj->foo);
return count;
}
static ssize_t b_show(struct foo_obj *foo_obj, struct foo_attribute *attr,
char *buf)
{
int var;
if (strcmp(attr->attr.name, "baz") == 0)
var = foo_obj->baz;
else
var = foo_obj->bar;
return sprintf(buf, "%d\n", var);
}
static ssize_t b_store(struct foo_obj *foo_obj, struct foo_attribute *attr,
const char *buf, size_t count)
{
int var;
sscanf(buf, "%du", &var);
if (strcmp(attr->attr.name, "baz") == 0)
foo_obj->baz = var;
else
foo_obj->bar = var;
return count;
}
static struct foo_obj *create_foo_obj(const char *name)
{
struct foo_obj *foo;
int retval;
foo = kzalloc(sizeof(*foo), GFP_KERNEL);
if (!foo)
return NULL;
foo->kobj.kset = example_kset;
retval = kobject_init_and_add(&foo->kobj, &foo_ktype, NULL, "%s", name);
if (retval) {
kobject_put(&foo->kobj);
return NULL;
}
kobject_uevent(&foo->kobj, KOBJ_ADD);
return foo;
}
static void destroy_foo_obj(struct foo_obj *foo)
{
kobject_put(&foo->kobj);
}
static int __init example_init(void)
{
example_kset = kset_create_and_add("kset_example", NULL, kernel_kobj);
if (!example_kset)
return -ENOMEM;
foo_obj = create_foo_obj("foo");
if (!foo_obj)
goto foo_error;
bar_obj = create_foo_obj("bar");
if (!bar_obj)
goto bar_error;
baz_obj = create_foo_obj("baz");
if (!baz_obj)
goto baz_error;
return 0;
baz_error:
destroy_foo_obj(bar_obj);
bar_error:
destroy_foo_obj(foo_obj);
foo_error:
kset_unregister(example_kset);
return -EINVAL;
}
static void __exit example_exit(void)
{
destroy_foo_obj(baz_obj);
destroy_foo_obj(bar_obj);
destroy_foo_obj(foo_obj);
kset_unregister(example_kset);
}
