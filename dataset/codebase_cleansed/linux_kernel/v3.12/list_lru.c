bool list_lru_add(struct list_lru *lru, struct list_head *item)
{
int nid = page_to_nid(virt_to_page(item));
struct list_lru_node *nlru = &lru->node[nid];
spin_lock(&nlru->lock);
WARN_ON_ONCE(nlru->nr_items < 0);
if (list_empty(item)) {
list_add_tail(item, &nlru->list);
if (nlru->nr_items++ == 0)
node_set(nid, lru->active_nodes);
spin_unlock(&nlru->lock);
return true;
}
spin_unlock(&nlru->lock);
return false;
}
bool list_lru_del(struct list_lru *lru, struct list_head *item)
{
int nid = page_to_nid(virt_to_page(item));
struct list_lru_node *nlru = &lru->node[nid];
spin_lock(&nlru->lock);
if (!list_empty(item)) {
list_del_init(item);
if (--nlru->nr_items == 0)
node_clear(nid, lru->active_nodes);
WARN_ON_ONCE(nlru->nr_items < 0);
spin_unlock(&nlru->lock);
return true;
}
spin_unlock(&nlru->lock);
return false;
}
unsigned long
list_lru_count_node(struct list_lru *lru, int nid)
{
unsigned long count = 0;
struct list_lru_node *nlru = &lru->node[nid];
spin_lock(&nlru->lock);
WARN_ON_ONCE(nlru->nr_items < 0);
count += nlru->nr_items;
spin_unlock(&nlru->lock);
return count;
}
unsigned long
list_lru_walk_node(struct list_lru *lru, int nid, list_lru_walk_cb isolate,
void *cb_arg, unsigned long *nr_to_walk)
{
struct list_lru_node *nlru = &lru->node[nid];
struct list_head *item, *n;
unsigned long isolated = 0;
spin_lock(&nlru->lock);
restart:
list_for_each_safe(item, n, &nlru->list) {
enum lru_status ret;
if (!*nr_to_walk)
break;
--*nr_to_walk;
ret = isolate(item, &nlru->lock, cb_arg);
switch (ret) {
case LRU_REMOVED:
if (--nlru->nr_items == 0)
node_clear(nid, lru->active_nodes);
WARN_ON_ONCE(nlru->nr_items < 0);
isolated++;
break;
case LRU_ROTATE:
list_move_tail(item, &nlru->list);
break;
case LRU_SKIP:
break;
case LRU_RETRY:
goto restart;
default:
BUG();
}
}
spin_unlock(&nlru->lock);
return isolated;
}
int list_lru_init(struct list_lru *lru)
{
int i;
size_t size = sizeof(*lru->node) * nr_node_ids;
lru->node = kzalloc(size, GFP_KERNEL);
if (!lru->node)
return -ENOMEM;
nodes_clear(lru->active_nodes);
for (i = 0; i < nr_node_ids; i++) {
spin_lock_init(&lru->node[i].lock);
INIT_LIST_HEAD(&lru->node[i].list);
lru->node[i].nr_items = 0;
}
return 0;
}
void list_lru_destroy(struct list_lru *lru)
{
kfree(lru->node);
}
