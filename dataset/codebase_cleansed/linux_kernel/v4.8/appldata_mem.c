static void appldata_get_mem_data(void *data)
{
static struct sysinfo val;
unsigned long ev[NR_VM_EVENT_ITEMS];
struct appldata_mem_data *mem_data;
mem_data = data;
mem_data->sync_count_1++;
all_vm_events(ev);
mem_data->pgpgin = ev[PGPGIN] >> 1;
mem_data->pgpgout = ev[PGPGOUT] >> 1;
mem_data->pswpin = ev[PSWPIN];
mem_data->pswpout = ev[PSWPOUT];
mem_data->pgalloc = ev[PGALLOC_NORMAL];
mem_data->pgalloc += ev[PGALLOC_DMA];
mem_data->pgfault = ev[PGFAULT];
mem_data->pgmajfault = ev[PGMAJFAULT];
si_meminfo(&val);
mem_data->sharedram = val.sharedram;
mem_data->totalram = P2K(val.totalram);
mem_data->freeram = P2K(val.freeram);
mem_data->totalhigh = P2K(val.totalhigh);
mem_data->freehigh = P2K(val.freehigh);
mem_data->bufferram = P2K(val.bufferram);
mem_data->cached = P2K(global_node_page_state(NR_FILE_PAGES)
- val.bufferram);
si_swapinfo(&val);
mem_data->totalswap = P2K(val.totalswap);
mem_data->freeswap = P2K(val.freeswap);
mem_data->timestamp = get_tod_clock();
mem_data->sync_count_2++;
}
static int __init appldata_mem_init(void)
{
int ret;
ops.data = kzalloc(sizeof(struct appldata_mem_data), GFP_KERNEL);
if (!ops.data)
return -ENOMEM;
ret = appldata_register_ops(&ops);
if (ret)
kfree(ops.data);
return ret;
}
static void __exit appldata_mem_exit(void)
{
appldata_unregister_ops(&ops);
kfree(ops.data);
}
