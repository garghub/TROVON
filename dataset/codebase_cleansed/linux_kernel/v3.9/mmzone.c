struct pglist_data *first_online_pgdat(void)
{
return NODE_DATA(first_online_node);
}
struct pglist_data *next_online_pgdat(struct pglist_data *pgdat)
{
int nid = next_online_node(pgdat->node_id);
if (nid == MAX_NUMNODES)
return NULL;
return NODE_DATA(nid);
}
struct zone *next_zone(struct zone *zone)
{
pg_data_t *pgdat = zone->zone_pgdat;
if (zone < pgdat->node_zones + MAX_NR_ZONES - 1)
zone++;
else {
pgdat = next_online_pgdat(pgdat);
if (pgdat)
zone = pgdat->node_zones;
else
zone = NULL;
}
return zone;
}
static inline int zref_in_nodemask(struct zoneref *zref, nodemask_t *nodes)
{
#ifdef CONFIG_NUMA
return node_isset(zonelist_node_idx(zref), *nodes);
#else
return 1;
#endif
}
struct zoneref *next_zones_zonelist(struct zoneref *z,
enum zone_type highest_zoneidx,
nodemask_t *nodes,
struct zone **zone)
{
if (likely(nodes == NULL))
while (zonelist_zone_idx(z) > highest_zoneidx)
z++;
else
while (zonelist_zone_idx(z) > highest_zoneidx ||
(z->zone && !zref_in_nodemask(z, nodes)))
z++;
*zone = zonelist_zone(z);
return z;
}
int memmap_valid_within(unsigned long pfn,
struct page *page, struct zone *zone)
{
if (page_to_pfn(page) != pfn)
return 0;
if (page_zone(page) != zone)
return 0;
return 1;
}
void lruvec_init(struct lruvec *lruvec)
{
enum lru_list lru;
memset(lruvec, 0, sizeof(struct lruvec));
for_each_lru(lru)
INIT_LIST_HEAD(&lruvec->lists[lru]);
}
int page_nid_xchg_last(struct page *page, int nid)
{
unsigned long old_flags, flags;
int last_nid;
do {
old_flags = flags = page->flags;
last_nid = page_nid_last(page);
flags &= ~(LAST_NID_MASK << LAST_NID_PGSHIFT);
flags |= (nid & LAST_NID_MASK) << LAST_NID_PGSHIFT;
} while (unlikely(cmpxchg(&page->flags, old_flags, flags) != old_flags));
return last_nid;
}
