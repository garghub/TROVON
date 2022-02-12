static int xqm_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "%d\t%d\t%d\t%u\n",
ndquot,
xfs_Gqm? atomic_read(&xfs_Gqm->qm_totaldquots) : 0,
xfs_Gqm? xfs_Gqm->qm_dqfree_ratio : 0,
xfs_Gqm? xfs_Gqm->qm_dqfrlist_cnt : 0);
return 0;
}
static int xqm_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, xqm_proc_show, NULL);
}
static int xqmstat_proc_show(struct seq_file *m, void *v)
{
seq_printf(m, "qm %u %u %u %u %u %u %u %u\n",
xqmstats.xs_qm_dqreclaims,
xqmstats.xs_qm_dqreclaim_misses,
xqmstats.xs_qm_dquot_dups,
xqmstats.xs_qm_dqcachemisses,
xqmstats.xs_qm_dqcachehits,
xqmstats.xs_qm_dqwants,
xqmstats.xs_qm_dqshake_reclaims,
xqmstats.xs_qm_dqinact_reclaims);
return 0;
}
static int xqmstat_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, xqmstat_proc_show, NULL);
}
void
xfs_qm_init_procfs(void)
{
proc_create("fs/xfs/xqmstat", 0, NULL, &xqmstat_proc_fops);
proc_create("fs/xfs/xqm", 0, NULL, &xqm_proc_fops);
}
void
xfs_qm_cleanup_procfs(void)
{
remove_proc_entry("fs/xfs/xqm", NULL);
remove_proc_entry("fs/xfs/xqmstat", NULL);
}
