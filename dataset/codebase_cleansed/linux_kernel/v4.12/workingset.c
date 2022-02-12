static void *pack_shadow(int memcgid, pg_data_t *pgdat, unsigned long eviction)
{
eviction >>= bucket_order;
eviction = (eviction << MEM_CGROUP_ID_SHIFT) | memcgid;
eviction = (eviction << NODES_SHIFT) | pgdat->node_id;
eviction = (eviction << RADIX_TREE_EXCEPTIONAL_SHIFT);
return (void *)(eviction | RADIX_TREE_EXCEPTIONAL_ENTRY);
}
static void unpack_shadow(void *shadow, int *memcgidp, pg_data_t **pgdat,
unsigned long *evictionp)
{
unsigned long entry = (unsigned long)shadow;
int memcgid, nid;
entry >>= RADIX_TREE_EXCEPTIONAL_SHIFT;
nid = entry & ((1UL << NODES_SHIFT) - 1);
entry >>= NODES_SHIFT;
memcgid = entry & ((1UL << MEM_CGROUP_ID_SHIFT) - 1);
entry >>= MEM_CGROUP_ID_SHIFT;
*memcgidp = memcgid;
*pgdat = NODE_DATA(nid);
*evictionp = entry << bucket_order;
}
void *workingset_eviction(struct address_space *mapping, struct page *page)
{
struct mem_cgroup *memcg = page_memcg(page);
struct pglist_data *pgdat = page_pgdat(page);
int memcgid = mem_cgroup_id(memcg);
unsigned long eviction;
struct lruvec *lruvec;
VM_BUG_ON_PAGE(PageLRU(page), page);
VM_BUG_ON_PAGE(page_count(page), page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
lruvec = mem_cgroup_lruvec(pgdat, memcg);
eviction = atomic_long_inc_return(&lruvec->inactive_age);
return pack_shadow(memcgid, pgdat, eviction);
}
bool workingset_refault(void *shadow)
{
unsigned long refault_distance;
unsigned long active_file;
struct mem_cgroup *memcg;
unsigned long eviction;
struct lruvec *lruvec;
unsigned long refault;
struct pglist_data *pgdat;
int memcgid;
unpack_shadow(shadow, &memcgid, &pgdat, &eviction);
rcu_read_lock();
memcg = mem_cgroup_from_id(memcgid);
if (!mem_cgroup_disabled() && !memcg) {
rcu_read_unlock();
return false;
}
lruvec = mem_cgroup_lruvec(pgdat, memcg);
refault = atomic_long_read(&lruvec->inactive_age);
active_file = lruvec_lru_size(lruvec, LRU_ACTIVE_FILE, MAX_NR_ZONES);
refault_distance = (refault - eviction) & EVICTION_MASK;
inc_node_state(pgdat, WORKINGSET_REFAULT);
inc_memcg_state(memcg, WORKINGSET_REFAULT);
if (refault_distance <= active_file) {
inc_node_state(pgdat, WORKINGSET_ACTIVATE);
inc_memcg_state(memcg, WORKINGSET_ACTIVATE);
rcu_read_unlock();
return true;
}
rcu_read_unlock();
return false;
}
void workingset_activation(struct page *page)
{
struct mem_cgroup *memcg;
struct lruvec *lruvec;
rcu_read_lock();
memcg = page_memcg_rcu(page);
if (!mem_cgroup_disabled() && !memcg)
goto out;
lruvec = mem_cgroup_lruvec(page_pgdat(page), memcg);
atomic_long_inc(&lruvec->inactive_age);
out:
rcu_read_unlock();
}
void workingset_update_node(struct radix_tree_node *node, void *private)
{
struct address_space *mapping = private;
if (dax_mapping(mapping) || shmem_mapping(mapping))
return;
if (node->count && node->count == node->exceptional) {
if (list_empty(&node->private_list))
list_lru_add(&shadow_nodes, &node->private_list);
} else {
if (!list_empty(&node->private_list))
list_lru_del(&shadow_nodes, &node->private_list);
}
}
static unsigned long count_shadow_nodes(struct shrinker *shrinker,
struct shrink_control *sc)
{
unsigned long max_nodes;
unsigned long nodes;
unsigned long cache;
local_irq_disable();
nodes = list_lru_shrink_count(&shadow_nodes, sc);
local_irq_enable();
if (sc->memcg) {
cache = mem_cgroup_node_nr_lru_pages(sc->memcg, sc->nid,
LRU_ALL_FILE);
} else {
cache = node_page_state(NODE_DATA(sc->nid), NR_ACTIVE_FILE) +
node_page_state(NODE_DATA(sc->nid), NR_INACTIVE_FILE);
}
max_nodes = cache >> (RADIX_TREE_MAP_SHIFT - 3);
if (nodes <= max_nodes)
return 0;
return nodes - max_nodes;
}
static enum lru_status shadow_lru_isolate(struct list_head *item,
struct list_lru_one *lru,
spinlock_t *lru_lock,
void *arg)
{
struct address_space *mapping;
struct radix_tree_node *node;
unsigned int i;
int ret;
node = container_of(item, struct radix_tree_node, private_list);
mapping = container_of(node->root, struct address_space, page_tree);
if (!spin_trylock(&mapping->tree_lock)) {
spin_unlock(lru_lock);
ret = LRU_RETRY;
goto out;
}
list_lru_isolate(lru, item);
spin_unlock(lru_lock);
if (WARN_ON_ONCE(!node->exceptional))
goto out_invalid;
if (WARN_ON_ONCE(node->count != node->exceptional))
goto out_invalid;
for (i = 0; i < RADIX_TREE_MAP_SIZE; i++) {
if (node->slots[i]) {
if (WARN_ON_ONCE(!radix_tree_exceptional_entry(node->slots[i])))
goto out_invalid;
if (WARN_ON_ONCE(!node->exceptional))
goto out_invalid;
if (WARN_ON_ONCE(!mapping->nrexceptional))
goto out_invalid;
node->slots[i] = NULL;
node->exceptional--;
node->count--;
mapping->nrexceptional--;
}
}
if (WARN_ON_ONCE(node->exceptional))
goto out_invalid;
inc_node_state(page_pgdat(virt_to_page(node)), WORKINGSET_NODERECLAIM);
inc_memcg_page_state(virt_to_page(node), WORKINGSET_NODERECLAIM);
__radix_tree_delete_node(&mapping->page_tree, node,
workingset_update_node, mapping);
out_invalid:
spin_unlock(&mapping->tree_lock);
ret = LRU_REMOVED_RETRY;
out:
local_irq_enable();
cond_resched();
local_irq_disable();
spin_lock(lru_lock);
return ret;
}
static unsigned long scan_shadow_nodes(struct shrinker *shrinker,
struct shrink_control *sc)
{
unsigned long ret;
local_irq_disable();
ret = list_lru_shrink_walk(&shadow_nodes, sc, shadow_lru_isolate, NULL);
local_irq_enable();
return ret;
}
static int __init workingset_init(void)
{
unsigned int timestamp_bits;
unsigned int max_order;
int ret;
BUILD_BUG_ON(BITS_PER_LONG < EVICTION_SHIFT);
timestamp_bits = BITS_PER_LONG - EVICTION_SHIFT;
max_order = fls_long(totalram_pages - 1);
if (max_order > timestamp_bits)
bucket_order = max_order - timestamp_bits;
pr_info("workingset: timestamp_bits=%d max_order=%d bucket_order=%u\n",
timestamp_bits, max_order, bucket_order);
ret = __list_lru_init(&shadow_nodes, true, &shadow_nodes_key);
if (ret)
goto err;
ret = register_shrinker(&workingset_shadow_shrinker);
if (ret)
goto err_list_lru;
return 0;
err_list_lru:
list_lru_destroy(&shadow_nodes);
err:
return ret;
}
