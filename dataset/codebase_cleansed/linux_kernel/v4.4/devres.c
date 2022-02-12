static void set_node_dbginfo(struct devres_node *node, const char *name,
size_t size)
{
node->name = name;
node->size = size;
}
static void devres_log(struct device *dev, struct devres_node *node,
const char *op)
{
if (unlikely(log_devres))
dev_err(dev, "DEVRES %3s %p %s (%lu bytes)\n",
op, node, node->name, (unsigned long)node->size);
}
static void group_open_release(struct device *dev, void *res)
{
}
static void group_close_release(struct device *dev, void *res)
{
}
static struct devres_group * node_to_group(struct devres_node *node)
{
if (node->release == &group_open_release)
return container_of(node, struct devres_group, node[0]);
if (node->release == &group_close_release)
return container_of(node, struct devres_group, node[1]);
return NULL;
}
void add_dr(struct device *dev, struct devres_node *node)
{
devres_log(dev, node, "ADD");
BUG_ON(!list_empty(&node->entry));
list_add_tail(&node->entry, &dev->devres_head);
}
void * __devres_alloc_node(dr_release_t release, size_t size, gfp_t gfp, int nid,
const char *name)
{
struct devres *dr;
dr = alloc_dr(release, size, gfp | __GFP_ZERO, nid);
if (unlikely(!dr))
return NULL;
set_node_dbginfo(&dr->node, name, size);
return dr->data;
}
void * devres_alloc_node(dr_release_t release, size_t size, gfp_t gfp, int nid)
{
struct devres *dr;
dr = alloc_dr(release, size, gfp | __GFP_ZERO, nid);
if (unlikely(!dr))
return NULL;
return dr->data;
}
void devres_for_each_res(struct device *dev, dr_release_t release,
dr_match_t match, void *match_data,
void (*fn)(struct device *, void *, void *),
void *data)
{
struct devres_node *node;
struct devres_node *tmp;
unsigned long flags;
if (!fn)
return;
spin_lock_irqsave(&dev->devres_lock, flags);
list_for_each_entry_safe_reverse(node, tmp,
&dev->devres_head, entry) {
struct devres *dr = container_of(node, struct devres, node);
if (node->release != release)
continue;
if (match && !match(dev, dr->data, match_data))
continue;
fn(dev, dr->data, data);
}
spin_unlock_irqrestore(&dev->devres_lock, flags);
}
void devres_free(void *res)
{
if (res) {
struct devres *dr = container_of(res, struct devres, data);
BUG_ON(!list_empty(&dr->node.entry));
kfree(dr);
}
}
void devres_add(struct device *dev, void *res)
{
struct devres *dr = container_of(res, struct devres, data);
unsigned long flags;
spin_lock_irqsave(&dev->devres_lock, flags);
add_dr(dev, &dr->node);
spin_unlock_irqrestore(&dev->devres_lock, flags);
}
static struct devres *find_dr(struct device *dev, dr_release_t release,
dr_match_t match, void *match_data)
{
struct devres_node *node;
list_for_each_entry_reverse(node, &dev->devres_head, entry) {
struct devres *dr = container_of(node, struct devres, node);
if (node->release != release)
continue;
if (match && !match(dev, dr->data, match_data))
continue;
return dr;
}
return NULL;
}
void * devres_find(struct device *dev, dr_release_t release,
dr_match_t match, void *match_data)
{
struct devres *dr;
unsigned long flags;
spin_lock_irqsave(&dev->devres_lock, flags);
dr = find_dr(dev, release, match, match_data);
spin_unlock_irqrestore(&dev->devres_lock, flags);
if (dr)
return dr->data;
return NULL;
}
void * devres_get(struct device *dev, void *new_res,
dr_match_t match, void *match_data)
{
struct devres *new_dr = container_of(new_res, struct devres, data);
struct devres *dr;
unsigned long flags;
spin_lock_irqsave(&dev->devres_lock, flags);
dr = find_dr(dev, new_dr->node.release, match, match_data);
if (!dr) {
add_dr(dev, &new_dr->node);
dr = new_dr;
new_res = NULL;
}
spin_unlock_irqrestore(&dev->devres_lock, flags);
devres_free(new_res);
return dr->data;
}
void * devres_remove(struct device *dev, dr_release_t release,
dr_match_t match, void *match_data)
{
struct devres *dr;
unsigned long flags;
spin_lock_irqsave(&dev->devres_lock, flags);
dr = find_dr(dev, release, match, match_data);
if (dr) {
list_del_init(&dr->node.entry);
devres_log(dev, &dr->node, "REM");
}
spin_unlock_irqrestore(&dev->devres_lock, flags);
if (dr)
return dr->data;
return NULL;
}
int devres_destroy(struct device *dev, dr_release_t release,
dr_match_t match, void *match_data)
{
void *res;
res = devres_remove(dev, release, match, match_data);
if (unlikely(!res))
return -ENOENT;
devres_free(res);
return 0;
}
int devres_release(struct device *dev, dr_release_t release,
dr_match_t match, void *match_data)
{
void *res;
res = devres_remove(dev, release, match, match_data);
if (unlikely(!res))
return -ENOENT;
(*release)(dev, res);
devres_free(res);
return 0;
}
static int remove_nodes(struct device *dev,
struct list_head *first, struct list_head *end,
struct list_head *todo)
{
int cnt = 0, nr_groups = 0;
struct list_head *cur;
cur = first;
while (cur != end) {
struct devres_node *node;
struct devres_group *grp;
node = list_entry(cur, struct devres_node, entry);
cur = cur->next;
grp = node_to_group(node);
if (grp) {
grp->color = 0;
nr_groups++;
} else {
if (&node->entry == first)
first = first->next;
list_move_tail(&node->entry, todo);
cnt++;
}
}
if (!nr_groups)
return cnt;
cur = first;
while (cur != end) {
struct devres_node *node;
struct devres_group *grp;
node = list_entry(cur, struct devres_node, entry);
cur = cur->next;
grp = node_to_group(node);
BUG_ON(!grp || list_empty(&grp->node[0].entry));
grp->color++;
if (list_empty(&grp->node[1].entry))
grp->color++;
BUG_ON(grp->color <= 0 || grp->color > 2);
if (grp->color == 2) {
list_move_tail(&grp->node[0].entry, todo);
list_del_init(&grp->node[1].entry);
}
}
return cnt;
}
static int release_nodes(struct device *dev, struct list_head *first,
struct list_head *end, unsigned long flags)
__releases(&dev->devres_lock
int devres_release_all(struct device *dev)
{
unsigned long flags;
if (WARN_ON(dev->devres_head.next == NULL))
return -ENODEV;
spin_lock_irqsave(&dev->devres_lock, flags);
return release_nodes(dev, dev->devres_head.next, &dev->devres_head,
flags);
}
void * devres_open_group(struct device *dev, void *id, gfp_t gfp)
{
struct devres_group *grp;
unsigned long flags;
grp = kmalloc(sizeof(*grp), gfp);
if (unlikely(!grp))
return NULL;
grp->node[0].release = &group_open_release;
grp->node[1].release = &group_close_release;
INIT_LIST_HEAD(&grp->node[0].entry);
INIT_LIST_HEAD(&grp->node[1].entry);
set_node_dbginfo(&grp->node[0], "grp<", 0);
set_node_dbginfo(&grp->node[1], "grp>", 0);
grp->id = grp;
if (id)
grp->id = id;
spin_lock_irqsave(&dev->devres_lock, flags);
add_dr(dev, &grp->node[0]);
spin_unlock_irqrestore(&dev->devres_lock, flags);
return grp->id;
}
static struct devres_group * find_group(struct device *dev, void *id)
{
struct devres_node *node;
list_for_each_entry_reverse(node, &dev->devres_head, entry) {
struct devres_group *grp;
if (node->release != &group_open_release)
continue;
grp = container_of(node, struct devres_group, node[0]);
if (id) {
if (grp->id == id)
return grp;
} else if (list_empty(&grp->node[1].entry))
return grp;
}
return NULL;
}
void devres_close_group(struct device *dev, void *id)
{
struct devres_group *grp;
unsigned long flags;
spin_lock_irqsave(&dev->devres_lock, flags);
grp = find_group(dev, id);
if (grp)
add_dr(dev, &grp->node[1]);
else
WARN_ON(1);
spin_unlock_irqrestore(&dev->devres_lock, flags);
}
void devres_remove_group(struct device *dev, void *id)
{
struct devres_group *grp;
unsigned long flags;
spin_lock_irqsave(&dev->devres_lock, flags);
grp = find_group(dev, id);
if (grp) {
list_del_init(&grp->node[0].entry);
list_del_init(&grp->node[1].entry);
devres_log(dev, &grp->node[0], "REM");
} else
WARN_ON(1);
spin_unlock_irqrestore(&dev->devres_lock, flags);
kfree(grp);
}
int devres_release_group(struct device *dev, void *id)
{
struct devres_group *grp;
unsigned long flags;
int cnt = 0;
spin_lock_irqsave(&dev->devres_lock, flags);
grp = find_group(dev, id);
if (grp) {
struct list_head *first = &grp->node[0].entry;
struct list_head *end = &dev->devres_head;
if (!list_empty(&grp->node[1].entry))
end = grp->node[1].entry.next;
cnt = release_nodes(dev, first, end, flags);
} else {
WARN_ON(1);
spin_unlock_irqrestore(&dev->devres_lock, flags);
}
return cnt;
}
static int devm_action_match(struct device *dev, void *res, void *p)
{
struct action_devres *devres = res;
struct action_devres *target = p;
return devres->action == target->action &&
devres->data == target->data;
}
static void devm_action_release(struct device *dev, void *res)
{
struct action_devres *devres = res;
devres->action(devres->data);
}
int devm_add_action(struct device *dev, void (*action)(void *), void *data)
{
struct action_devres *devres;
devres = devres_alloc(devm_action_release,
sizeof(struct action_devres), GFP_KERNEL);
if (!devres)
return -ENOMEM;
devres->data = data;
devres->action = action;
devres_add(dev, devres);
return 0;
}
void devm_remove_action(struct device *dev, void (*action)(void *), void *data)
{
struct action_devres devres = {
.data = data,
.action = action,
};
WARN_ON(devres_destroy(dev, devm_action_release, devm_action_match,
&devres));
}
static void devm_kmalloc_release(struct device *dev, void *res)
{
}
static int devm_kmalloc_match(struct device *dev, void *res, void *data)
{
return res == data;
}
void * devm_kmalloc(struct device *dev, size_t size, gfp_t gfp)
{
struct devres *dr;
dr = alloc_dr(devm_kmalloc_release, size, gfp, dev_to_node(dev));
if (unlikely(!dr))
return NULL;
set_node_dbginfo(&dr->node, "devm_kzalloc_release", size);
devres_add(dev, dr->data);
return dr->data;
}
char *devm_kstrdup(struct device *dev, const char *s, gfp_t gfp)
{
size_t size;
char *buf;
if (!s)
return NULL;
size = strlen(s) + 1;
buf = devm_kmalloc(dev, size, gfp);
if (buf)
memcpy(buf, s, size);
return buf;
}
char *devm_kvasprintf(struct device *dev, gfp_t gfp, const char *fmt,
va_list ap)
{
unsigned int len;
char *p;
va_list aq;
va_copy(aq, ap);
len = vsnprintf(NULL, 0, fmt, aq);
va_end(aq);
p = devm_kmalloc(dev, len+1, gfp);
if (!p)
return NULL;
vsnprintf(p, len+1, fmt, ap);
return p;
}
char *devm_kasprintf(struct device *dev, gfp_t gfp, const char *fmt, ...)
{
va_list ap;
char *p;
va_start(ap, fmt);
p = devm_kvasprintf(dev, gfp, fmt, ap);
va_end(ap);
return p;
}
void devm_kfree(struct device *dev, void *p)
{
int rc;
rc = devres_destroy(dev, devm_kmalloc_release, devm_kmalloc_match, p);
WARN_ON(rc);
}
void *devm_kmemdup(struct device *dev, const void *src, size_t len, gfp_t gfp)
{
void *p;
p = devm_kmalloc(dev, len, gfp);
if (p)
memcpy(p, src, len);
return p;
}
static int devm_pages_match(struct device *dev, void *res, void *p)
{
struct pages_devres *devres = res;
struct pages_devres *target = p;
return devres->addr == target->addr;
}
static void devm_pages_release(struct device *dev, void *res)
{
struct pages_devres *devres = res;
free_pages(devres->addr, devres->order);
}
unsigned long devm_get_free_pages(struct device *dev,
gfp_t gfp_mask, unsigned int order)
{
struct pages_devres *devres;
unsigned long addr;
addr = __get_free_pages(gfp_mask, order);
if (unlikely(!addr))
return 0;
devres = devres_alloc(devm_pages_release,
sizeof(struct pages_devres), GFP_KERNEL);
if (unlikely(!devres)) {
free_pages(addr, order);
return 0;
}
devres->addr = addr;
devres->order = order;
devres_add(dev, devres);
return addr;
}
void devm_free_pages(struct device *dev, unsigned long addr)
{
struct pages_devres devres = { .addr = addr };
WARN_ON(devres_release(dev, devm_pages_release, devm_pages_match,
&devres));
}
