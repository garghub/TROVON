void mminit_verify_zonelist(void)
{
int nid;
if (mminit_loglevel < MMINIT_VERIFY)
return;
for_each_online_node(nid) {
pg_data_t *pgdat = NODE_DATA(nid);
struct zone *zone;
struct zoneref *z;
struct zonelist *zonelist;
int i, listid, zoneid;
BUG_ON(MAX_ZONELISTS > 2);
for (i = 0; i < MAX_ZONELISTS * MAX_NR_ZONES; i++) {
zoneid = i % MAX_NR_ZONES;
listid = i / MAX_NR_ZONES;
zonelist = &pgdat->node_zonelists[listid];
zone = &pgdat->node_zones[zoneid];
if (!populated_zone(zone))
continue;
printk(KERN_DEBUG "mminit::zonelist %s %d:%s = ",
listid > 0 ? "thisnode" : "general", nid,
zone->name);
for_each_zone_zonelist(zone, z, zonelist, zoneid) {
#ifdef CONFIG_NUMA
printk(KERN_CONT "%d:%s ",
zone->node, zone->name);
#else
printk(KERN_CONT "0:%s ", zone->name);
#endif
}
printk(KERN_CONT "\n");
}
}
}
void __init mminit_verify_pageflags_layout(void)
{
int shift, width;
unsigned long or_mask, add_mask;
shift = 8 * sizeof(unsigned long);
width = shift - SECTIONS_WIDTH - NODES_WIDTH - ZONES_WIDTH - LAST_NID_SHIFT;
mminit_dprintk(MMINIT_TRACE, "pageflags_layout_widths",
"Section %d Node %d Zone %d Lastnid %d Flags %d\n",
SECTIONS_WIDTH,
NODES_WIDTH,
ZONES_WIDTH,
LAST_NID_WIDTH,
NR_PAGEFLAGS);
mminit_dprintk(MMINIT_TRACE, "pageflags_layout_shifts",
"Section %d Node %d Zone %d Lastnid %d\n",
SECTIONS_SHIFT,
NODES_SHIFT,
ZONES_SHIFT,
LAST_NID_SHIFT);
mminit_dprintk(MMINIT_TRACE, "pageflags_layout_pgshifts",
"Section %lu Node %lu Zone %lu Lastnid %lu\n",
(unsigned long)SECTIONS_PGSHIFT,
(unsigned long)NODES_PGSHIFT,
(unsigned long)ZONES_PGSHIFT,
(unsigned long)LAST_NID_PGSHIFT);
mminit_dprintk(MMINIT_TRACE, "pageflags_layout_nodezoneid",
"Node/Zone ID: %lu -> %lu\n",
(unsigned long)(ZONEID_PGOFF + ZONEID_SHIFT),
(unsigned long)ZONEID_PGOFF);
mminit_dprintk(MMINIT_TRACE, "pageflags_layout_usage",
"location: %d -> %d layout %d -> %d unused %d -> %d page-flags\n",
shift, width, width, NR_PAGEFLAGS, NR_PAGEFLAGS, 0);
#ifdef NODE_NOT_IN_PAGE_FLAGS
mminit_dprintk(MMINIT_TRACE, "pageflags_layout_nodeflags",
"Node not in page flags");
#endif
#ifdef LAST_NID_NOT_IN_PAGE_FLAGS
mminit_dprintk(MMINIT_TRACE, "pageflags_layout_nodeflags",
"Last nid not in page flags");
#endif
if (SECTIONS_WIDTH) {
shift -= SECTIONS_WIDTH;
BUG_ON(shift != SECTIONS_PGSHIFT);
}
if (NODES_WIDTH) {
shift -= NODES_WIDTH;
BUG_ON(shift != NODES_PGSHIFT);
}
if (ZONES_WIDTH) {
shift -= ZONES_WIDTH;
BUG_ON(shift != ZONES_PGSHIFT);
}
or_mask = (ZONES_MASK << ZONES_PGSHIFT) |
(NODES_MASK << NODES_PGSHIFT) |
(SECTIONS_MASK << SECTIONS_PGSHIFT);
add_mask = (ZONES_MASK << ZONES_PGSHIFT) +
(NODES_MASK << NODES_PGSHIFT) +
(SECTIONS_MASK << SECTIONS_PGSHIFT);
BUG_ON(or_mask != add_mask);
}
void __meminit mminit_verify_page_links(struct page *page, enum zone_type zone,
unsigned long nid, unsigned long pfn)
{
BUG_ON(page_to_nid(page) != nid);
BUG_ON(page_zonenum(page) != zone);
BUG_ON(page_to_pfn(page) != pfn);
}
static __init int set_mminit_loglevel(char *str)
{
get_option(&str, &mminit_loglevel);
return 0;
}
static int __init mm_sysfs_init(void)
{
mm_kobj = kobject_create_and_add("mm", kernel_kobj);
if (!mm_kobj)
return -ENOMEM;
return 0;
}
