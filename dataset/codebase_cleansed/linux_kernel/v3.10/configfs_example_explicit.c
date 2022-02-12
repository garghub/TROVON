static inline struct childless *to_childless(struct config_item *item)
{
return item ? container_of(to_configfs_subsystem(to_config_group(item)), struct childless, subsys) : NULL;
}
static ssize_t childless_showme_read(struct childless *childless,
char *page)
{
ssize_t pos;
pos = sprintf(page, "%d\n", childless->showme);
childless->showme++;
return pos;
}
static ssize_t childless_storeme_read(struct childless *childless,
char *page)
{
return sprintf(page, "%d\n", childless->storeme);
}
static ssize_t childless_storeme_write(struct childless *childless,
const char *page,
size_t count)
{
unsigned long tmp;
char *p = (char *) page;
tmp = simple_strtoul(p, &p, 10);
if ((*p != '\0') && (*p != '\n'))
return -EINVAL;
if (tmp > INT_MAX)
return -ERANGE;
childless->storeme = tmp;
return count;
}
static ssize_t childless_description_read(struct childless *childless,
char *page)
{
return sprintf(page,
"[01-childless]\n"
"\n"
"The childless subsystem is the simplest possible subsystem in\n"
"configfs. It does not support the creation of child config_items.\n"
"It only has a few attributes. In fact, it isn't much different\n"
"than a directory in /proc.\n");
}
static ssize_t childless_attr_show(struct config_item *item,
struct configfs_attribute *attr,
char *page)
{
struct childless *childless = to_childless(item);
struct childless_attribute *childless_attr =
container_of(attr, struct childless_attribute, attr);
ssize_t ret = 0;
if (childless_attr->show)
ret = childless_attr->show(childless, page);
return ret;
}
static ssize_t childless_attr_store(struct config_item *item,
struct configfs_attribute *attr,
const char *page, size_t count)
{
struct childless *childless = to_childless(item);
struct childless_attribute *childless_attr =
container_of(attr, struct childless_attribute, attr);
ssize_t ret = -EINVAL;
if (childless_attr->store)
ret = childless_attr->store(childless, page, count);
return ret;
}
static inline struct simple_child *to_simple_child(struct config_item *item)
{
return item ? container_of(item, struct simple_child, item) : NULL;
}
static ssize_t simple_child_attr_show(struct config_item *item,
struct configfs_attribute *attr,
char *page)
{
ssize_t count;
struct simple_child *simple_child = to_simple_child(item);
count = sprintf(page, "%d\n", simple_child->storeme);
return count;
}
static ssize_t simple_child_attr_store(struct config_item *item,
struct configfs_attribute *attr,
const char *page, size_t count)
{
struct simple_child *simple_child = to_simple_child(item);
unsigned long tmp;
char *p = (char *) page;
tmp = simple_strtoul(p, &p, 10);
if (!p || (*p && (*p != '\n')))
return -EINVAL;
if (tmp > INT_MAX)
return -ERANGE;
simple_child->storeme = tmp;
return count;
}
static void simple_child_release(struct config_item *item)
{
kfree(to_simple_child(item));
}
static inline struct simple_children *to_simple_children(struct config_item *item)
{
return item ? container_of(to_config_group(item), struct simple_children, group) : NULL;
}
static struct config_item *simple_children_make_item(struct config_group *group, const char *name)
{
struct simple_child *simple_child;
simple_child = kzalloc(sizeof(struct simple_child), GFP_KERNEL);
if (!simple_child)
return ERR_PTR(-ENOMEM);
config_item_init_type_name(&simple_child->item, name,
&simple_child_type);
simple_child->storeme = 0;
return &simple_child->item;
}
static ssize_t simple_children_attr_show(struct config_item *item,
struct configfs_attribute *attr,
char *page)
{
return sprintf(page,
"[02-simple-children]\n"
"\n"
"This subsystem allows the creation of child config_items. These\n"
"items have only one attribute that is readable and writeable.\n");
}
static void simple_children_release(struct config_item *item)
{
kfree(to_simple_children(item));
}
static struct config_group *group_children_make_group(struct config_group *group, const char *name)
{
struct simple_children *simple_children;
simple_children = kzalloc(sizeof(struct simple_children),
GFP_KERNEL);
if (!simple_children)
return ERR_PTR(-ENOMEM);
config_group_init_type_name(&simple_children->group, name,
&simple_children_type);
return &simple_children->group;
}
static ssize_t group_children_attr_show(struct config_item *item,
struct configfs_attribute *attr,
char *page)
{
return sprintf(page,
"[03-group-children]\n"
"\n"
"This subsystem allows the creation of child config_groups. These\n"
"groups are like the subsystem simple-children.\n");
}
static int __init configfs_example_init(void)
{
int ret;
int i;
struct configfs_subsystem *subsys;
for (i = 0; example_subsys[i]; i++) {
subsys = example_subsys[i];
config_group_init(&subsys->su_group);
mutex_init(&subsys->su_mutex);
ret = configfs_register_subsystem(subsys);
if (ret) {
printk(KERN_ERR "Error %d while registering subsystem %s\n",
ret,
subsys->su_group.cg_item.ci_namebuf);
goto out_unregister;
}
}
return 0;
out_unregister:
for (i--; i >= 0; i--)
configfs_unregister_subsystem(example_subsys[i]);
return ret;
}
static void __exit configfs_example_exit(void)
{
int i;
for (i = 0; example_subsys[i]; i++)
configfs_unregister_subsystem(example_subsys[i]);
}
