static int counter_val(int idx)
{
int val = 0, cpu;
for_each_possible_cpu(cpu)
val += *(((__u32 *)&per_cpu(xfsstats, cpu) + idx));
return val;
}
static int xfs_stat_proc_show(struct seq_file *m, void *v)
{
int i, j;
__uint64_t xs_xstrat_bytes = 0;
__uint64_t xs_write_bytes = 0;
__uint64_t xs_read_bytes = 0;
static const struct xstats_entry {
char *desc;
int endpoint;
} xstats[] = {
{ "extent_alloc", XFSSTAT_END_EXTENT_ALLOC },
{ "abt", XFSSTAT_END_ALLOC_BTREE },
{ "blk_map", XFSSTAT_END_BLOCK_MAPPING },
{ "bmbt", XFSSTAT_END_BLOCK_MAP_BTREE },
{ "dir", XFSSTAT_END_DIRECTORY_OPS },
{ "trans", XFSSTAT_END_TRANSACTIONS },
{ "ig", XFSSTAT_END_INODE_OPS },
{ "log", XFSSTAT_END_LOG_OPS },
{ "push_ail", XFSSTAT_END_TAIL_PUSHING },
{ "xstrat", XFSSTAT_END_WRITE_CONVERT },
{ "rw", XFSSTAT_END_READ_WRITE_OPS },
{ "attr", XFSSTAT_END_ATTRIBUTE_OPS },
{ "icluster", XFSSTAT_END_INODE_CLUSTER },
{ "vnodes", XFSSTAT_END_VNODE_OPS },
{ "buf", XFSSTAT_END_BUF },
{ "abtb2", XFSSTAT_END_ABTB_V2 },
{ "abtc2", XFSSTAT_END_ABTC_V2 },
{ "bmbt2", XFSSTAT_END_BMBT_V2 },
{ "ibt2", XFSSTAT_END_IBT_V2 },
{ "fibt2", XFSSTAT_END_FIBT_V2 },
{ "qm", XFSSTAT_END_QM },
};
for (i = j = 0; i < ARRAY_SIZE(xstats); i++) {
seq_printf(m, "%s", xstats[i].desc);
for (; j < xstats[i].endpoint; j++)
seq_printf(m, " %u", counter_val(j));
seq_putc(m, '\n');
}
for_each_possible_cpu(i) {
xs_xstrat_bytes += per_cpu(xfsstats, i).xs_xstrat_bytes;
xs_write_bytes += per_cpu(xfsstats, i).xs_write_bytes;
xs_read_bytes += per_cpu(xfsstats, i).xs_read_bytes;
}
seq_printf(m, "xpc %Lu %Lu %Lu\n",
xs_xstrat_bytes, xs_write_bytes, xs_read_bytes);
seq_printf(m, "debug %u\n",
#if defined(DEBUG)
1);
#else
0);
int xfs_stat_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, xfs_stat_proc_show, NULL);
}
static int xqm_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%d\t%d\t%d\t%u\n",
0,
counter_val(XFSSTAT_END_XQMSTAT),
0,
counter_val(XFSSTAT_END_XQMSTAT + 1));
return 0;
}
static int xqm_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, xqm_proc_show, NULL);
}
static int xqmstat_proc_show(struct seq_file *m, void *v)
{
int j;
seq_printf(m, "qm");
for (j = XFSSTAT_END_IBT_V2; j < XFSSTAT_END_XQMSTAT; j++)
seq_printf(m, " %u", counter_val(j));
seq_putc(m, '\n');
return 0;
}
static int xqmstat_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, xqmstat_proc_show, NULL);
}
int
xfs_init_procfs(void)
{
if (!proc_mkdir("fs/xfs", NULL))
goto out;
if (!proc_create("fs/xfs/stat", 0, NULL,
&xfs_stat_proc_fops))
goto out_remove_xfs_dir;
#ifdef CONFIG_XFS_QUOTA
if (!proc_create("fs/xfs/xqmstat", 0, NULL,
&xqmstat_proc_fops))
goto out_remove_stat_file;
if (!proc_create("fs/xfs/xqm", 0, NULL,
&xqm_proc_fops))
goto out_remove_xqmstat_file;
#endif
return 0;
#ifdef CONFIG_XFS_QUOTA
out_remove_xqmstat_file:
remove_proc_entry("fs/xfs/xqmstat", NULL);
out_remove_stat_file:
remove_proc_entry("fs/xfs/stat", NULL);
#endif
out_remove_xfs_dir:
remove_proc_entry("fs/xfs", NULL);
out:
return -ENOMEM;
}
void
xfs_cleanup_procfs(void)
{
#ifdef CONFIG_XFS_QUOTA
remove_proc_entry("fs/xfs/xqm", NULL);
remove_proc_entry("fs/xfs/xqmstat", NULL);
#endif
remove_proc_entry("fs/xfs/stat", NULL);
remove_proc_entry("fs/xfs", NULL);
}
