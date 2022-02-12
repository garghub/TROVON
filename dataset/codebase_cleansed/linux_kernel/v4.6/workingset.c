static void *pack_shadow(int memcgid, struct zone *zone, unsigned long eviction)
{
eviction >>= bucket_order;
eviction = (eviction << MEM_CGROUP_ID_SHIFT) | memcgid;
eviction = (eviction << NODES_SHIFT) | zone_to_nid(zone);
eviction = (eviction << ZONES_SHIFT) | zone_idx(zone);
eviction = (eviction << RADIX_TREE_EXCEPTIONAL_SHIFT);
return (void *)(eviction | RADIX_TREE_EXCEPTIONAL_ENTRY);
}
static void unpack_shadow(void *shadow, int *memcgidp, struct zone **zonep,
unsigned long *evictionp)
{
unsigned long entry = (unsigned long)shadow;
int memcgid, nid, zid;
entry >>= RADIX_TREE_EXCEPTIONAL_SHIFT;
zid = entry & ((1UL << ZONES_SHIFT) - 1);
entry >>= ZONES_SHIFT;
nid = entry & ((1UL << NODES_SHIFT) - 1);
entry >>= NODES_SHIFT;
memcgid = entry & ((1UL << MEM_CGROUP_ID_SHIFT) - 1);
entry >>= MEM_CGROUP_ID_SHIFT;
*memcgidp = memcgid;
*zonep = NODE_DATA(nid)->node_zones + zid;
*evictionp = entry << bucket_order;
}
void *workingset_eviction(struct address_space *mapping, struct page *page)
{
struct mem_cgroup *memcg = page_memcg(page);
struct zone *zone = page_zone(page);
int memcgid = mem_cgroup_id(memcg);
unsigned long eviction;
struct lruvec *lruvec;
VM_BUG_ON_PAGE(PageLRU(page), page);
VM_BUG_ON_PAGE(page_count(page), page);
VM_BUG_ON_PAGE(!PageLocked(page), page);
lruvec = mem_cgroup_zone_lruvec(zone, memcg);
eviction = atomic_long_inc_return(&lruvec->inactive_age);
return pack_shadow(memcgid, zone, eviction);
}
bool workingset_refault(void *shadow)
{
unsigned long refault_distance;
unsigned long active_file;
struct mem_cgroup *memcg;
unsigned long eviction;
struct lruvec *lruvec;
unsigned long refault;
struct zone *zone;
int memcgid;
unpack_shadow(shadow, &memcgid, &zone, &eviction);
rcu_read_lock();
memcg = mem_cgroup_from_id(memcgid);
if (!mem_cgroup_disabled() && !memcg) {
rcu_read_unlock();
return false;
}
lruvec = mem_cgroup_zone_lruvec(zone, memcg);
refault = atomic_long_read(&lruvec->inactive_age);
active_file = lruvec_lru_size(lruvec, LRU_ACTIVE_FILE);
rcu_read_unlock();
refault_distance = (refault - eviction) & EVICTION_MASK;
inc_zone_state(zone, WORKINGSET_REFAULT);
if (refault_distance <= active_file) {
inc_zone_state(zone, WORKINGSET_ACTIVATE);
return true;
}
return false;
}
void workingset_activation(struct page *page)
{
struct lruvec *lruvec;
lock_page_memcg(page);
if (!mem_cgroup_disabled() && !page_memcg(page))
goto out;
lruvec = mem_cgroup_zone_lruvec(page_zone(page), page_memcg(page));
atomic_long_inc(&lruvec->inactive_age);
out:
unlock_page_memcg(page);
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
if (memcg_kmem_enabled())
pages = mem_cgroup_node_nr_lru_pages(sc->memcg, sc->nid,
LRU_ALL_FILE);
else
pages = node_page_state(sc->nid, NR_ACTIVE_FILE) +
node_page_state(sc->nid, NR_INACTIVE_FILE);
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
BUG_ON(!node->count);
BUG_ON(node->count & RADIX_TREE_COUNT_MASK);
for (i = 0; i < RADIX_TREE_MAP_SIZE; i++) {
if (node->slots[i]) {
BUG_ON(!radix_tree_exceptional_entry(node->slots[i]));
node->slots[i] = NULL;
BUG_ON(node->count < (1U << RADIX_TREE_COUNT_SHIFT));
node->count -= 1U << RADIX_TREE_COUNT_SHIFT;
BUG_ON(!mapping->nrexceptional);
mapping->nrexceptional--;
}
}
BUG_ON(node->count);
inc_zone_state(page_zone(virt_to_page(node)), WORKINGSET_NODERECLAIM);
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
printk("workingset: timestamp_bits=%d max_order=%d bucket_order=%u\n",
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
