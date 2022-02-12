void __init initmem_init(void)
{
x86_numa_init();
}
unsigned long __init numa_free_all_bootmem(void)
{
unsigned long pages = 0;
int i;
for_each_online_node(i)
pages += free_all_bootmem_node(NODE_DATA(i));
pages += free_all_memory_core_early(MAX_NUMNODES);
return pages;
}
