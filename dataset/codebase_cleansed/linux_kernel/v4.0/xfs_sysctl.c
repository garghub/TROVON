STATIC int
xfs_stats_clear_proc_handler(
struct ctl_table *ctl,
int write,
void __user *buffer,
size_t *lenp,
loff_t *ppos)
{
int c, ret, *valp = ctl->data;
__uint32_t vn_active;
ret = proc_dointvec_minmax(ctl, write, buffer, lenp, ppos);
if (!ret && write && *valp) {
xfs_notice(NULL, "Clearing xfsstats");
for_each_possible_cpu(c) {
preempt_disable();
vn_active = per_cpu(xfsstats, c).vn_active;
memset(&per_cpu(xfsstats, c), 0,
sizeof(struct xfsstats));
per_cpu(xfsstats, c).vn_active = vn_active;
preempt_enable();
}
xfs_stats_clear = 0;
}
return ret;
}
STATIC int
xfs_panic_mask_proc_handler(
struct ctl_table *ctl,
int write,
void __user *buffer,
size_t *lenp,
loff_t *ppos)
{
int ret, *valp = ctl->data;
ret = proc_dointvec_minmax(ctl, write, buffer, lenp, ppos);
if (!ret && write) {
xfs_panic_mask = *valp;
#ifdef DEBUG
xfs_panic_mask |= (XFS_PTAG_SHUTDOWN_CORRUPT | XFS_PTAG_LOGRES);
#endif
}
return ret;
}
int
xfs_sysctl_register(void)
{
xfs_table_header = register_sysctl_table(xfs_root_table);
if (!xfs_table_header)
return -ENOMEM;
return 0;
}
void
xfs_sysctl_unregister(void)
{
unregister_sysctl_table(xfs_table_header);
}
