static void *pack_shadow(unsigned long eviction, struct zone *zone)
{
eviction = (eviction << NODES_SHIFT) | zone_to_nid(zone);
eviction = (eviction << ZONES_SHIFT) | zone_idx(zone);
eviction = (eviction << RADIX_TREE_EXCEPTIONAL_SHIFT);
return (void *)(eviction | RADIX_TREE_EXCEPTIONAL_ENTRY);
}
static void unpack_shadow(void *shadow,
struct zone **zone,
unsigned long *distance)
{
unsigned long entry = (unsigned long)shadow;
unsigned long eviction;
unsigned long refault;
unsigned long mask;
int zid, nid;
entry >>= RADIX_TREE_EXCEPTIONAL_SHIFT;
zid = entry & ((1UL << ZONES_SHIFT) - 1);
entry >>= ZONES_SHIFT;
nid = entry & ((1UL << NODES_SHIFT) - 1);
entry >>= NODES_SHIFT;
eviction = entry;
*zone = NODE_DATA(nid)->node_zones + zid;
refault = atomic_long_read(&(*zone)->inactive_age);
mask = ~0UL >> (NODES_SHIFT + ZONES_SHIFT +
RADIX_TREE_EXCEPTIONAL_SHIFT);
*distance = (refault - eviction) & mask;
}
void *workingset_eviction(struct address_space *mapping, struct page *page)
{
struct zone *zone = page_zone(page);
unsigned long eviction;
eviction = atomic_long_inc_return(&zone->inactive_age);
return pack_shadow(eviction, zone);
}
bool workingset_refault(void *shadow)
{
unsigned long refault_distance;
struct zone *zone;
unpack_shadow(shadow, &zone, &refault_distance);
inc_zone_state(zone, WORKINGSET_REFAULT);
if (refault_distance <= zone_page_state(zone, NR_ACTIVE_FILE)) {
inc_zone_state(zone, WORKINGSET_ACTIVATE);
return true;
}
return false;
}
void workingset_activation(struct page *page)
{
atomic_long_inc(&page_zone(page)->inactive_age);
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
pages = node_present_pages(sc->nid);
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
BUG_ON(!mapping->nrshadows);
mapping->nrshadows--;
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
int ret;
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
