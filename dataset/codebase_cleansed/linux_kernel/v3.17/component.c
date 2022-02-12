static struct master *__master_find(struct device *dev,
const struct component_master_ops *ops)
{
struct master *m;
list_for_each_entry(m, &masters, node)
if (m->dev == dev && (!ops || m->ops == ops))
return m;
return NULL;
}
static void component_attach_master(struct master *master, struct component *c)
{
c->master = master;
list_add_tail(&c->master_node, &master->components);
}
static void component_detach_master(struct master *master, struct component *c)
{
list_del(&c->master_node);
c->master = NULL;
}
int component_master_add_child(struct master *master,
int (*compare)(struct device *, void *), void *compare_data)
{
struct component *c;
int ret = -ENXIO;
list_for_each_entry(c, &component_list, node) {
if (c->master && c->master != master)
continue;
if (compare(c->dev, compare_data)) {
if (!c->master)
component_attach_master(master, c);
ret = 0;
break;
}
}
return ret;
}
static int find_components(struct master *master)
{
struct component_match *match = master->match;
size_t i;
int ret = 0;
if (!match) {
return master->ops->add_components(master->dev, master);
}
for (i = 0; i < match->num; i++) {
ret = component_master_add_child(master,
match->compare[i].fn,
match->compare[i].data);
if (ret)
break;
}
return ret;
}
static void master_remove_components(struct master *master)
{
while (!list_empty(&master->components)) {
struct component *c = list_first_entry(&master->components,
struct component, master_node);
WARN_ON(c->master != master);
component_detach_master(master, c);
}
}
static int try_to_bring_up_master(struct master *master,
struct component *component)
{
int ret;
if (master->bound)
return 0;
if (find_components(master)) {
ret = 0;
goto out;
}
if (component && component->master != master) {
ret = 0;
goto out;
}
if (!devres_open_group(master->dev, NULL, GFP_KERNEL)) {
ret = -ENOMEM;
goto out;
}
ret = master->ops->bind(master->dev);
if (ret < 0) {
devres_release_group(master->dev, NULL);
dev_info(master->dev, "master bind failed: %d\n", ret);
goto out;
}
master->bound = true;
return 1;
out:
master_remove_components(master);
return ret;
}
static int try_to_bring_up_masters(struct component *component)
{
struct master *m;
int ret = 0;
list_for_each_entry(m, &masters, node) {
ret = try_to_bring_up_master(m, component);
if (ret != 0)
break;
}
return ret;
}
static void take_down_master(struct master *master)
{
if (master->bound) {
master->ops->unbind(master->dev);
devres_release_group(master->dev, NULL);
master->bound = false;
}
master_remove_components(master);
}
static size_t component_match_size(size_t num)
{
return offsetof(struct component_match, compare[num]);
}
static struct component_match *component_match_realloc(struct device *dev,
struct component_match *match, size_t num)
{
struct component_match *new;
if (match && match->alloc == num)
return match;
new = devm_kmalloc(dev, component_match_size(num), GFP_KERNEL);
if (!new)
return ERR_PTR(-ENOMEM);
if (match) {
memcpy(new, match, component_match_size(min(match->num, num)));
devm_kfree(dev, match);
} else {
new->num = 0;
}
new->alloc = num;
return new;
}
void component_match_add(struct device *dev, struct component_match **matchptr,
int (*compare)(struct device *, void *), void *compare_data)
{
struct component_match *match = *matchptr;
if (IS_ERR(match))
return;
if (!match || match->num == match->alloc) {
size_t new_size = match ? match->alloc + 16 : 15;
match = component_match_realloc(dev, match, new_size);
*matchptr = match;
if (IS_ERR(match))
return;
}
match->compare[match->num].fn = compare;
match->compare[match->num].data = compare_data;
match->num++;
}
int component_master_add_with_match(struct device *dev,
const struct component_master_ops *ops,
struct component_match *match)
{
struct master *master;
int ret;
if (ops->add_components && match)
return -EINVAL;
if (match) {
match = component_match_realloc(dev, match, match->num);
if (IS_ERR(match))
return PTR_ERR(match);
}
master = kzalloc(sizeof(*master), GFP_KERNEL);
if (!master)
return -ENOMEM;
master->dev = dev;
master->ops = ops;
master->match = match;
INIT_LIST_HEAD(&master->components);
mutex_lock(&component_mutex);
list_add(&master->node, &masters);
ret = try_to_bring_up_master(master, NULL);
if (ret < 0) {
list_del(&master->node);
kfree(master);
}
mutex_unlock(&component_mutex);
return ret < 0 ? ret : 0;
}
int component_master_add(struct device *dev,
const struct component_master_ops *ops)
{
return component_master_add_with_match(dev, ops, NULL);
}
void component_master_del(struct device *dev,
const struct component_master_ops *ops)
{
struct master *master;
mutex_lock(&component_mutex);
master = __master_find(dev, ops);
if (master) {
take_down_master(master);
list_del(&master->node);
kfree(master);
}
mutex_unlock(&component_mutex);
}
static void component_unbind(struct component *component,
struct master *master, void *data)
{
WARN_ON(!component->bound);
component->ops->unbind(component->dev, master->dev, data);
component->bound = false;
devres_release_group(component->dev, component);
}
void component_unbind_all(struct device *master_dev, void *data)
{
struct master *master;
struct component *c;
WARN_ON(!mutex_is_locked(&component_mutex));
master = __master_find(master_dev, NULL);
if (!master)
return;
list_for_each_entry_reverse(c, &master->components, master_node)
component_unbind(c, master, data);
}
static int component_bind(struct component *component, struct master *master,
void *data)
{
int ret;
if (!devres_open_group(master->dev, NULL, GFP_KERNEL))
return -ENOMEM;
if (!devres_open_group(component->dev, component, GFP_KERNEL)) {
devres_release_group(master->dev, NULL);
return -ENOMEM;
}
dev_dbg(master->dev, "binding %s (ops %ps)\n",
dev_name(component->dev), component->ops);
ret = component->ops->bind(component->dev, master->dev, data);
if (!ret) {
component->bound = true;
devres_close_group(component->dev, NULL);
devres_remove_group(master->dev, NULL);
dev_info(master->dev, "bound %s (ops %ps)\n",
dev_name(component->dev), component->ops);
} else {
devres_release_group(component->dev, NULL);
devres_release_group(master->dev, NULL);
dev_err(master->dev, "failed to bind %s (ops %ps): %d\n",
dev_name(component->dev), component->ops, ret);
}
return ret;
}
int component_bind_all(struct device *master_dev, void *data)
{
struct master *master;
struct component *c;
int ret = 0;
WARN_ON(!mutex_is_locked(&component_mutex));
master = __master_find(master_dev, NULL);
if (!master)
return -EINVAL;
list_for_each_entry(c, &master->components, master_node) {
ret = component_bind(c, master, data);
if (ret)
break;
}
if (ret != 0) {
list_for_each_entry_continue_reverse(c, &master->components,
master_node)
component_unbind(c, master, data);
}
return ret;
}
int component_add(struct device *dev, const struct component_ops *ops)
{
struct component *component;
int ret;
component = kzalloc(sizeof(*component), GFP_KERNEL);
if (!component)
return -ENOMEM;
component->ops = ops;
component->dev = dev;
dev_dbg(dev, "adding component (ops %ps)\n", ops);
mutex_lock(&component_mutex);
list_add_tail(&component->node, &component_list);
ret = try_to_bring_up_masters(component);
if (ret < 0) {
list_del(&component->node);
kfree(component);
}
mutex_unlock(&component_mutex);
return ret < 0 ? ret : 0;
}
void component_del(struct device *dev, const struct component_ops *ops)
{
struct component *c, *component = NULL;
mutex_lock(&component_mutex);
list_for_each_entry(c, &component_list, node)
if (c->dev == dev && c->ops == ops) {
list_del(&c->node);
component = c;
break;
}
if (component && component->master)
take_down_master(component->master);
mutex_unlock(&component_mutex);
WARN_ON(!component);
kfree(component);
}
