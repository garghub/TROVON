static inline struct config_item *to_item(struct list_head *entry)
{
return container_of(entry, struct config_item, ci_entry);
}
static void config_item_init(struct config_item *item)
{
kref_init(&item->ci_kref);
INIT_LIST_HEAD(&item->ci_entry);
}
int config_item_set_name(struct config_item *item, const char *fmt, ...)
{
int error = 0;
int limit = CONFIGFS_ITEM_NAME_LEN;
int need;
va_list args;
char *name;
va_start(args, fmt);
need = vsnprintf(item->ci_namebuf, limit, fmt, args);
va_end(args);
if (need < limit)
name = item->ci_namebuf;
else {
limit = need + 1;
name = kmalloc(limit, GFP_KERNEL);
if (!name) {
error = -ENOMEM;
goto Done;
}
va_start(args, fmt);
need = vsnprintf(name, limit, fmt, args);
va_end(args);
if (need >= limit) {
kfree(name);
error = -EFAULT;
goto Done;
}
}
if (item->ci_name && item->ci_name != item->ci_namebuf)
kfree(item->ci_name);
item->ci_name = name;
Done:
return error;
}
void config_item_init_type_name(struct config_item *item,
const char *name,
struct config_item_type *type)
{
config_item_set_name(item, "%s", name);
item->ci_type = type;
config_item_init(item);
}
void config_group_init_type_name(struct config_group *group, const char *name,
struct config_item_type *type)
{
config_item_set_name(&group->cg_item, "%s", name);
group->cg_item.ci_type = type;
config_group_init(group);
}
struct config_item *config_item_get(struct config_item *item)
{
if (item)
kref_get(&item->ci_kref);
return item;
}
static void config_item_cleanup(struct config_item *item)
{
struct config_item_type *t = item->ci_type;
struct config_group *s = item->ci_group;
struct config_item *parent = item->ci_parent;
pr_debug("config_item %s: cleaning up\n", config_item_name(item));
if (item->ci_name != item->ci_namebuf)
kfree(item->ci_name);
item->ci_name = NULL;
if (t && t->ct_item_ops && t->ct_item_ops->release)
t->ct_item_ops->release(item);
if (s)
config_group_put(s);
if (parent)
config_item_put(parent);
}
static void config_item_release(struct kref *kref)
{
config_item_cleanup(container_of(kref, struct config_item, ci_kref));
}
void config_item_put(struct config_item *item)
{
if (item)
kref_put(&item->ci_kref, config_item_release);
}
void config_group_init(struct config_group *group)
{
config_item_init(&group->cg_item);
INIT_LIST_HEAD(&group->cg_children);
INIT_LIST_HEAD(&group->default_groups);
}
struct config_item *config_group_find_item(struct config_group *group,
const char *name)
{
struct list_head *entry;
struct config_item *ret = NULL;
list_for_each(entry, &group->cg_children) {
struct config_item *item = to_item(entry);
if (config_item_name(item) &&
!strcmp(config_item_name(item), name)) {
ret = config_item_get(item);
break;
}
}
return ret;
}
