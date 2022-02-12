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
active_file = lruvec_lru_size(lruvec, LRU_ACTIVE_FILE);
rcu_read_unlock();
refault_distance = (refault - eviction) & EVICTION_MASK;
inc_node_state(pgdat, WORKINGSET_REFAULT);
if (refault_distance <= active_file) {
inc_node_state(pgdat, WORKINGSET_ACTIVATE);
return true;
}
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
static unsigned long count_shadow_nodes(struct shrinker *shrinker,
struct shrink_control *sc)
{
unsigned long shadow_nodes;
unsigned long max_nodes;
unsigned long pages;
local_irq_disable();
shadow_nodes = list_lru_shrink_count(&workingset_shadow_nodes, sc);
local_irq_enable();
if (sc->memcg) {
pages = mem_cgroup_node_nr_lru_pages(sc->memcg, sc->nid,
LRU_ALL_FILE);
} else {
pages = node_page_state(NODE_DATA(sc->nid), NR_ACTIVE_FILE) +
node_page_state(NODE_DATA(sc->nid), NR_INACTIVE_FILE);
}
max_nodes = pages >> (1 + RADIX_TREE_MAP_SHIFT - 3);
if (shadow_nodes <= max_nodes)
return 0;
return shadow_nodes - max_nodes;
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
mapping = node->private_data;
if (!spin_trylock(&mapping->tree_lock)) {
spin_unlock(lru_lock);
ret = LRU_RETRY;
goto out;
}
list_lru_isolate(lru, item);
spin_unlock(lru_lock);
BUG_ON(!workingset_node_shadows(node));
BUG_ON(workingset_node_pages(node));
for (i = 0; i < RADIX_TREE_MAP_SIZE; i++) {
if (node->slots[i]) {
BUG_ON(!radix_tree_exceptional_entry(node->slots[i]));
node->slots[i] = NULL;
workingset_node_shadows_dec(node);
BUG_ON(!mapping->nrexceptional);
mapping->nrexceptional--;
}
}
BUG_ON(workingset_node_shadows(node));
inc_node_state(page_pgdat(virt_to_page(node)), WORKINGSET_NODERECLAIM);
if (!__radix_tree_delete_node(&mapping->page_tree, node))
BUG();
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
ret = list_lru_shrink_walk(&workingset_shadow_nodes, sc,
shadow_lru_isolate, NULL);
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
ret = list_lru_init_key(&workingset_shadow_nodes, &shadow_nodes_key);
if (ret)
goto err;
ret = register_shrinker(&workingset_shadow_shrinker);
if (ret)
goto err_list_lru;
return 0;
err_list_lru:
list_lru_destroy(&workingset_shadow_nodes);
err:
return ret;
}
