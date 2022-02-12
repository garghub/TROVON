static inline struct gov_attr_set *to_gov_attr_set(struct kobject *kobj)
{
return container_of(kobj, struct gov_attr_set, kobj);
}
static inline struct governor_attr *to_gov_attr(struct attribute *attr)
{
return container_of(attr, struct governor_attr, attr);
}
static ssize_t governor_show(struct kobject *kobj, struct attribute *attr,
char *buf)
{
struct governor_attr *gattr = to_gov_attr(attr);
return gattr->show(to_gov_attr_set(kobj), buf);
}
static ssize_t governor_store(struct kobject *kobj, struct attribute *attr,
const char *buf, size_t count)
{
struct gov_attr_set *attr_set = to_gov_attr_set(kobj);
struct governor_attr *gattr = to_gov_attr(attr);
int ret;
mutex_lock(&attr_set->update_lock);
ret = attr_set->usage_count ? gattr->store(attr_set, buf, count) : -EBUSY;
mutex_unlock(&attr_set->update_lock);
return ret;
}
void gov_attr_set_init(struct gov_attr_set *attr_set, struct list_head *list_node)
{
INIT_LIST_HEAD(&attr_set->policy_list);
mutex_init(&attr_set->update_lock);
attr_set->usage_count = 1;
list_add(list_node, &attr_set->policy_list);
}
void gov_attr_set_get(struct gov_attr_set *attr_set, struct list_head *list_node)
{
mutex_lock(&attr_set->update_lock);
attr_set->usage_count++;
list_add(list_node, &attr_set->policy_list);
mutex_unlock(&attr_set->update_lock);
}
unsigned int gov_attr_set_put(struct gov_attr_set *attr_set, struct list_head *list_node)
{
unsigned int count;
mutex_lock(&attr_set->update_lock);
list_del(list_node);
count = --attr_set->usage_count;
mutex_unlock(&attr_set->update_lock);
if (count)
return count;
kobject_put(&attr_set->kobj);
mutex_destroy(&attr_set->update_lock);
return 0;
}
