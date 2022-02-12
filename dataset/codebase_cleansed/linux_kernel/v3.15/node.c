static ssize_t node_read_cpumap(struct device *dev, int type, char *buf)
{
struct node *node_dev = to_node(dev);
const struct cpumask *mask = cpumask_of_node(node_dev->dev.id);
int len;
BUILD_BUG_ON((NR_CPUS/32 * 9) > (PAGE_SIZE-1));
len = type?
cpulist_scnprintf(buf, PAGE_SIZE-2, mask) :
cpumask_scnprintf(buf, PAGE_SIZE-2, mask);
buf[len++] = '\n';
buf[len] = '\0';
return len;
}
static inline ssize_t node_read_cpumask(struct device *dev,
struct device_attribute *attr, char *buf)
{
return node_read_cpumap(dev, 0, buf);
}
static inline ssize_t node_read_cpulist(struct device *dev,
struct device_attribute *attr, char *buf)
{
return node_read_cpumap(dev, 1, buf);
}
static ssize_t node_read_meminfo(struct device *dev,
struct device_attribute *attr, char *buf)
{
int n;
int nid = dev->id;
struct sysinfo i;
si_meminfo_node(&i, nid);
n = sprintf(buf,
"Node %d MemTotal: %8lu kB\n"
"Node %d MemFree: %8lu kB\n"
"Node %d MemUsed: %8lu kB\n"
"Node %d Active: %8lu kB\n"
"Node %d Inactive: %8lu kB\n"
"Node %d Active(anon): %8lu kB\n"
"Node %d Inactive(anon): %8lu kB\n"
"Node %d Active(file): %8lu kB\n"
"Node %d Inactive(file): %8lu kB\n"
"Node %d Unevictable: %8lu kB\n"
"Node %d Mlocked: %8lu kB\n",
nid, K(i.totalram),
nid, K(i.freeram),
nid, K(i.totalram - i.freeram),
nid, K(node_page_state(nid, NR_ACTIVE_ANON) +
node_page_state(nid, NR_ACTIVE_FILE)),
nid, K(node_page_state(nid, NR_INACTIVE_ANON) +
node_page_state(nid, NR_INACTIVE_FILE)),
nid, K(node_page_state(nid, NR_ACTIVE_ANON)),
nid, K(node_page_state(nid, NR_INACTIVE_ANON)),
nid, K(node_page_state(nid, NR_ACTIVE_FILE)),
nid, K(node_page_state(nid, NR_INACTIVE_FILE)),
nid, K(node_page_state(nid, NR_UNEVICTABLE)),
nid, K(node_page_state(nid, NR_MLOCK)));
#ifdef CONFIG_HIGHMEM
n += sprintf(buf + n,
"Node %d HighTotal: %8lu kB\n"
"Node %d HighFree: %8lu kB\n"
"Node %d LowTotal: %8lu kB\n"
"Node %d LowFree: %8lu kB\n",
nid, K(i.totalhigh),
nid, K(i.freehigh),
nid, K(i.totalram - i.totalhigh),
nid, K(i.freeram - i.freehigh));
#endif
n += sprintf(buf + n,
"Node %d Dirty: %8lu kB\n"
"Node %d Writeback: %8lu kB\n"
"Node %d FilePages: %8lu kB\n"
"Node %d Mapped: %8lu kB\n"
"Node %d AnonPages: %8lu kB\n"
"Node %d Shmem: %8lu kB\n"
"Node %d KernelStack: %8lu kB\n"
"Node %d PageTables: %8lu kB\n"
"Node %d NFS_Unstable: %8lu kB\n"
"Node %d Bounce: %8lu kB\n"
"Node %d WritebackTmp: %8lu kB\n"
"Node %d Slab: %8lu kB\n"
"Node %d SReclaimable: %8lu kB\n"
"Node %d SUnreclaim: %8lu kB\n"
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
"Node %d AnonHugePages: %8lu kB\n"
#endif
,
nid, K(node_page_state(nid, NR_FILE_DIRTY)),
nid, K(node_page_state(nid, NR_WRITEBACK)),
nid, K(node_page_state(nid, NR_FILE_PAGES)),
nid, K(node_page_state(nid, NR_FILE_MAPPED)),
nid, K(node_page_state(nid, NR_ANON_PAGES)),
nid, K(node_page_state(nid, NR_SHMEM)),
nid, node_page_state(nid, NR_KERNEL_STACK) *
THREAD_SIZE / 1024,
nid, K(node_page_state(nid, NR_PAGETABLE)),
nid, K(node_page_state(nid, NR_UNSTABLE_NFS)),
nid, K(node_page_state(nid, NR_BOUNCE)),
nid, K(node_page_state(nid, NR_WRITEBACK_TEMP)),
nid, K(node_page_state(nid, NR_SLAB_RECLAIMABLE) +
node_page_state(nid, NR_SLAB_UNRECLAIMABLE)),
nid, K(node_page_state(nid, NR_SLAB_RECLAIMABLE)),
#ifdef CONFIG_TRANSPARENT_HUGEPAGE
nid, K(node_page_state(nid, NR_SLAB_UNRECLAIMABLE))
, nid,
K(node_page_state(nid, NR_ANON_TRANSPARENT_HUGEPAGES) *
HPAGE_PMD_NR));
#else
nid, K(node_page_state(nid, NR_SLAB_UNRECLAIMABLE)));
static ssize_t node_read_numastat(struct device *dev,
struct device_attribute *attr, char *buf)
{
return sprintf(buf,
"numa_hit %lu\n"
"numa_miss %lu\n"
"numa_foreign %lu\n"
"interleave_hit %lu\n"
"local_node %lu\n"
"other_node %lu\n",
node_page_state(dev->id, NUMA_HIT),
node_page_state(dev->id, NUMA_MISS),
node_page_state(dev->id, NUMA_FOREIGN),
node_page_state(dev->id, NUMA_INTERLEAVE_HIT),
node_page_state(dev->id, NUMA_LOCAL),
node_page_state(dev->id, NUMA_OTHER));
}
static ssize_t node_read_vmstat(struct device *dev,
struct device_attribute *attr, char *buf)
{
int nid = dev->id;
int i;
int n = 0;
for (i = 0; i < NR_VM_ZONE_STAT_ITEMS; i++)
n += sprintf(buf+n, "%s %lu\n", vmstat_text[i],
node_page_state(nid, i));
return n;
}
static ssize_t node_read_distance(struct device *dev,
struct device_attribute *attr, char * buf)
{
int nid = dev->id;
int len = 0;
int i;
BUILD_BUG_ON(MAX_NUMNODES * 4 > PAGE_SIZE);
for_each_online_node(i)
len += sprintf(buf + len, "%s%d", i ? " " : "", node_distance(nid, i));
len += sprintf(buf + len, "\n");
return len;
}
static inline bool hugetlb_register_node(struct node *node)
{
if (__hugetlb_register_node &&
node_state(node->dev.id, N_MEMORY)) {
__hugetlb_register_node(node);
return true;
}
return false;
}
static inline void hugetlb_unregister_node(struct node *node)
{
if (__hugetlb_unregister_node)
__hugetlb_unregister_node(node);
}
void register_hugetlbfs_with_node(node_registration_func_t doregister,
node_registration_func_t unregister)
{
__hugetlb_register_node = doregister;
__hugetlb_unregister_node = unregister;
}
static inline void hugetlb_register_node(struct node *node) {}
static inline void hugetlb_unregister_node(struct node *node) {}
static void node_device_release(struct device *dev)
{
struct node *node = to_node(dev);
#if defined(CONFIG_MEMORY_HOTPLUG_SPARSE) && defined(CONFIG_HUGETLBFS)
flush_work(&node->node_work);
#endif
kfree(node);
}
static int register_node(struct node *node, int num, struct node *parent)
{
int error;
node->dev.id = num;
node->dev.bus = &node_subsys;
node->dev.release = node_device_release;
error = device_register(&node->dev);
if (!error){
device_create_file(&node->dev, &dev_attr_cpumap);
device_create_file(&node->dev, &dev_attr_cpulist);
device_create_file(&node->dev, &dev_attr_meminfo);
device_create_file(&node->dev, &dev_attr_numastat);
device_create_file(&node->dev, &dev_attr_distance);
device_create_file(&node->dev, &dev_attr_vmstat);
scan_unevictable_register_node(node);
hugetlb_register_node(node);
compaction_register_node(node);
}
return error;
}
void unregister_node(struct node *node)
{
device_remove_file(&node->dev, &dev_attr_cpumap);
device_remove_file(&node->dev, &dev_attr_cpulist);
device_remove_file(&node->dev, &dev_attr_meminfo);
device_remove_file(&node->dev, &dev_attr_numastat);
device_remove_file(&node->dev, &dev_attr_distance);
device_remove_file(&node->dev, &dev_attr_vmstat);
scan_unevictable_unregister_node(node);
hugetlb_unregister_node(node);
device_unregister(&node->dev);
}
int register_cpu_under_node(unsigned int cpu, unsigned int nid)
{
int ret;
struct device *obj;
if (!node_online(nid))
return 0;
obj = get_cpu_device(cpu);
if (!obj)
return 0;
ret = sysfs_create_link(&node_devices[nid]->dev.kobj,
&obj->kobj,
kobject_name(&obj->kobj));
if (ret)
return ret;
return sysfs_create_link(&obj->kobj,
&node_devices[nid]->dev.kobj,
kobject_name(&node_devices[nid]->dev.kobj));
}
int unregister_cpu_under_node(unsigned int cpu, unsigned int nid)
{
struct device *obj;
if (!node_online(nid))
return 0;
obj = get_cpu_device(cpu);
if (!obj)
return 0;
sysfs_remove_link(&node_devices[nid]->dev.kobj,
kobject_name(&obj->kobj));
sysfs_remove_link(&obj->kobj,
kobject_name(&node_devices[nid]->dev.kobj));
return 0;
}
static int get_nid_for_pfn(unsigned long pfn)
{
struct page *page;
if (!pfn_valid_within(pfn))
return -1;
page = pfn_to_page(pfn);
if (!page_initialized(page))
return -1;
return pfn_to_nid(pfn);
}
int register_mem_sect_under_node(struct memory_block *mem_blk, int nid)
{
int ret;
unsigned long pfn, sect_start_pfn, sect_end_pfn;
if (!mem_blk)
return -EFAULT;
if (!node_online(nid))
return 0;
sect_start_pfn = section_nr_to_pfn(mem_blk->start_section_nr);
sect_end_pfn = section_nr_to_pfn(mem_blk->end_section_nr);
sect_end_pfn += PAGES_PER_SECTION - 1;
for (pfn = sect_start_pfn; pfn <= sect_end_pfn; pfn++) {
int page_nid;
page_nid = get_nid_for_pfn(pfn);
if (page_nid < 0)
continue;
if (page_nid != nid)
continue;
ret = sysfs_create_link_nowarn(&node_devices[nid]->dev.kobj,
&mem_blk->dev.kobj,
kobject_name(&mem_blk->dev.kobj));
if (ret)
return ret;
return sysfs_create_link_nowarn(&mem_blk->dev.kobj,
&node_devices[nid]->dev.kobj,
kobject_name(&node_devices[nid]->dev.kobj));
}
return 0;
}
int unregister_mem_sect_under_nodes(struct memory_block *mem_blk,
unsigned long phys_index)
{
NODEMASK_ALLOC(nodemask_t, unlinked_nodes, GFP_KERNEL);
unsigned long pfn, sect_start_pfn, sect_end_pfn;
if (!mem_blk) {
NODEMASK_FREE(unlinked_nodes);
return -EFAULT;
}
if (!unlinked_nodes)
return -ENOMEM;
nodes_clear(*unlinked_nodes);
sect_start_pfn = section_nr_to_pfn(phys_index);
sect_end_pfn = sect_start_pfn + PAGES_PER_SECTION - 1;
for (pfn = sect_start_pfn; pfn <= sect_end_pfn; pfn++) {
int nid;
nid = get_nid_for_pfn(pfn);
if (nid < 0)
continue;
if (!node_online(nid))
continue;
if (node_test_and_set(nid, *unlinked_nodes))
continue;
sysfs_remove_link(&node_devices[nid]->dev.kobj,
kobject_name(&mem_blk->dev.kobj));
sysfs_remove_link(&mem_blk->dev.kobj,
kobject_name(&node_devices[nid]->dev.kobj));
}
NODEMASK_FREE(unlinked_nodes);
return 0;
}
static int link_mem_sections(int nid)
{
unsigned long start_pfn = NODE_DATA(nid)->node_start_pfn;
unsigned long end_pfn = start_pfn + NODE_DATA(nid)->node_spanned_pages;
unsigned long pfn;
struct memory_block *mem_blk = NULL;
int err = 0;
for (pfn = start_pfn; pfn < end_pfn; pfn += PAGES_PER_SECTION) {
unsigned long section_nr = pfn_to_section_nr(pfn);
struct mem_section *mem_sect;
int ret;
if (!present_section_nr(section_nr))
continue;
mem_sect = __nr_to_section(section_nr);
if (mem_blk)
if ((section_nr >= mem_blk->start_section_nr) &&
(section_nr <= mem_blk->end_section_nr))
continue;
mem_blk = find_memory_block_hinted(mem_sect, mem_blk);
ret = register_mem_sect_under_node(mem_blk, nid);
if (!err)
err = ret;
}
if (mem_blk)
kobject_put(&mem_blk->dev.kobj);
return err;
}
static void node_hugetlb_work(struct work_struct *work)
{
struct node *node = container_of(work, struct node, node_work);
if (!hugetlb_register_node(node))
hugetlb_unregister_node(node);
}
static void init_node_hugetlb_work(int nid)
{
INIT_WORK(&node_devices[nid]->node_work, node_hugetlb_work);
}
static int node_memory_callback(struct notifier_block *self,
unsigned long action, void *arg)
{
struct memory_notify *mnb = arg;
int nid = mnb->status_change_nid;
switch (action) {
case MEM_ONLINE:
case MEM_OFFLINE:
if (nid != NUMA_NO_NODE)
schedule_work(&node_devices[nid]->node_work);
break;
case MEM_GOING_ONLINE:
case MEM_GOING_OFFLINE:
case MEM_CANCEL_ONLINE:
case MEM_CANCEL_OFFLINE:
default:
break;
}
return NOTIFY_OK;
}
static int link_mem_sections(int nid) { return 0; }
static inline int node_memory_callback(struct notifier_block *self,
unsigned long action, void *arg)
{
return NOTIFY_OK;
}
static void init_node_hugetlb_work(int nid) { }
int register_one_node(int nid)
{
int error = 0;
int cpu;
if (node_online(nid)) {
int p_node = parent_node(nid);
struct node *parent = NULL;
if (p_node != nid)
parent = node_devices[p_node];
node_devices[nid] = kzalloc(sizeof(struct node), GFP_KERNEL);
if (!node_devices[nid])
return -ENOMEM;
error = register_node(node_devices[nid], nid, parent);
for_each_present_cpu(cpu) {
if (cpu_to_node(cpu) == nid)
register_cpu_under_node(cpu, nid);
}
error = link_mem_sections(nid);
init_node_hugetlb_work(nid);
}
return error;
}
void unregister_one_node(int nid)
{
if (!node_devices[nid])
return;
unregister_node(node_devices[nid]);
kfree(node_devices[nid]);
node_devices[nid] = NULL;
}
static ssize_t print_nodes_state(enum node_states state, char *buf)
{
int n;
n = nodelist_scnprintf(buf, PAGE_SIZE-2, node_states[state]);
buf[n++] = '\n';
buf[n] = '\0';
return n;
}
static ssize_t show_node_state(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct node_attr *na = container_of(attr, struct node_attr, attr);
return print_nodes_state(na->state, buf);
}
static int __init register_node_type(void)
{
int ret;
BUILD_BUG_ON(ARRAY_SIZE(node_state_attr) != NR_NODE_STATES);
BUILD_BUG_ON(ARRAY_SIZE(node_state_attrs)-1 != NR_NODE_STATES);
ret = subsys_system_register(&node_subsys, cpu_root_attr_groups);
if (!ret) {
static struct notifier_block node_memory_callback_nb = {
.notifier_call = node_memory_callback,
.priority = NODE_CALLBACK_PRI,
};
register_hotmemory_notifier(&node_memory_callback_nb);
}
return ret;
}
