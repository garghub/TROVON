void __init setup_replication_mask(void)
{
cpumask_clear(&ktext_repmask);
cpumask_set_cpu(0, &ktext_repmask);
#ifdef CONFIG_REPLICATE_KTEXT
#ifndef CONFIG_MAPPED_KERNEL
#error Kernel replication works with mapped kernel support. No calias support.
#endif
{
cnodeid_t cnode;
for_each_online_node(cnode) {
if (cnode == 0)
continue;
cpumask_set_cpu(cnode, &ktext_repmask);
}
}
#endif
GDA->g_ktext_repmask = &ktext_repmask;
}
static __init void set_ktext_source(nasid_t client_nasid, nasid_t server_nasid)
{
kern_vars_t *kvp;
kvp = &hub_data(client_nasid)->kern_vars;
KERN_VARS_ADDR(client_nasid) = (unsigned long)kvp;
kvp->kv_magic = KV_MAGIC;
kvp->kv_ro_nasid = server_nasid;
kvp->kv_rw_nasid = master_nasid;
kvp->kv_ro_baseaddr = NODE_CAC_BASE(server_nasid);
kvp->kv_rw_baseaddr = NODE_CAC_BASE(master_nasid);
printk("REPLICATION: ON nasid %d, ktext from nasid %d, kdata from nasid %d\n", client_nasid, server_nasid, master_nasid);
}
static __init void copy_kernel(nasid_t dest_nasid)
{
unsigned long dest_kern_start, source_start, source_end, kern_size;
source_start = (unsigned long) _stext;
source_end = (unsigned long) _etext;
kern_size = source_end - source_start;
dest_kern_start = CHANGE_ADDR_NASID(MAPPED_KERN_RO_TO_K0(source_start),
dest_nasid);
memcpy((void *)dest_kern_start, (void *)source_start, kern_size);
}
void __init replicate_kernel_text(void)
{
cnodeid_t cnode;
nasid_t client_nasid;
nasid_t server_nasid;
server_nasid = master_nasid;
set_ktext_source(master_nasid, master_nasid);
for_each_online_node(cnode) {
if (cnode == 0)
continue;
client_nasid = COMPACT_TO_NASID_NODEID(cnode);
if (cpumask_test_cpu(cnode, &ktext_repmask)) {
server_nasid = client_nasid;
copy_kernel(server_nasid);
}
set_ktext_source(client_nasid, server_nasid);
}
}
unsigned long node_getfirstfree(cnodeid_t cnode)
{
unsigned long loadbase = REP_BASE;
nasid_t nasid = COMPACT_TO_NASID_NODEID(cnode);
unsigned long offset;
#ifdef CONFIG_MAPPED_KERNEL
loadbase += 16777216;
#endif
offset = PAGE_ALIGN((unsigned long)(&_end)) - loadbase;
if ((cnode == 0) || (cpumask_test_cpu(cnode, &ktext_repmask)))
return TO_NODE(nasid, offset) >> PAGE_SHIFT;
else
return KDM_TO_PHYS(PAGE_ALIGN(SYMMON_STK_ADDR(nasid, 0))) >> PAGE_SHIFT;
}
