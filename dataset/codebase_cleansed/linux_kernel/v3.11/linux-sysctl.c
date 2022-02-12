int LL_PROC_PROTO(proc_set_timeout)
{
int rc;
rc = ll_proc_dointvec(table, write, filp, buffer, lenp, ppos);
if (ldlm_timeout >= obd_timeout)
ldlm_timeout = max(obd_timeout / 3, 1U);
return rc;
}
int LL_PROC_PROTO(proc_memory_alloc)
{
char buf[22];
int len;
DECLARE_LL_PROC_PPOS_DECL;
if (!*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write)
return -EINVAL;
len = snprintf(buf, sizeof(buf), LPU64"\n", obd_memory_sum());
if (len > *lenp)
len = *lenp;
buf[len] = '\0';
if (copy_to_user(buffer, buf, len))
return -EFAULT;
*lenp = len;
*ppos += *lenp;
return 0;
}
int LL_PROC_PROTO(proc_pages_alloc)
{
char buf[22];
int len;
DECLARE_LL_PROC_PPOS_DECL;
if (!*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write)
return -EINVAL;
len = snprintf(buf, sizeof(buf), LPU64"\n", obd_pages_sum());
if (len > *lenp)
len = *lenp;
buf[len] = '\0';
if (copy_to_user(buffer, buf, len))
return -EFAULT;
*lenp = len;
*ppos += *lenp;
return 0;
}
int LL_PROC_PROTO(proc_mem_max)
{
char buf[22];
int len;
DECLARE_LL_PROC_PPOS_DECL;
if (!*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write)
return -EINVAL;
len = snprintf(buf, sizeof(buf), LPU64"\n", obd_memory_max());
if (len > *lenp)
len = *lenp;
buf[len] = '\0';
if (copy_to_user(buffer, buf, len))
return -EFAULT;
*lenp = len;
*ppos += *lenp;
return 0;
}
int LL_PROC_PROTO(proc_pages_max)
{
char buf[22];
int len;
DECLARE_LL_PROC_PPOS_DECL;
if (!*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write)
return -EINVAL;
len = snprintf(buf, sizeof(buf), LPU64"\n", obd_pages_max());
if (len > *lenp)
len = *lenp;
buf[len] = '\0';
if (copy_to_user(buffer, buf, len))
return -EFAULT;
*lenp = len;
*ppos += *lenp;
return 0;
}
int LL_PROC_PROTO(proc_max_dirty_pages_in_mb)
{
int rc = 0;
DECLARE_LL_PROC_PPOS_DECL;
if (!table->data || !table->maxlen || !*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write) {
rc = lprocfs_write_frac_helper(buffer, *lenp,
(unsigned int*)table->data,
1 << (20 - PAGE_CACHE_SHIFT));
if (obd_max_dirty_pages > ((num_physpages / 10) * 9)) {
CERROR("Refusing to set max dirty pages to %u, which "
"is more than 90%% of available RAM; setting "
"to %lu\n", obd_max_dirty_pages,
((num_physpages / 10) * 9));
obd_max_dirty_pages = ((num_physpages / 10) * 9);
} else if (obd_max_dirty_pages < 4 << (20 - PAGE_CACHE_SHIFT)) {
obd_max_dirty_pages = 4 << (20 - PAGE_CACHE_SHIFT);
}
} else {
char buf[21];
int len;
len = lprocfs_read_frac_helper(buf, sizeof(buf),
*(unsigned int*)table->data,
1 << (20 - PAGE_CACHE_SHIFT));
if (len > *lenp)
len = *lenp;
buf[len] = '\0';
if (copy_to_user(buffer, buf, len))
return -EFAULT;
*lenp = len;
}
*ppos += *lenp;
return rc;
}
int LL_PROC_PROTO(proc_alloc_fail_rate)
{
int rc = 0;
DECLARE_LL_PROC_PPOS_DECL;
if (!table->data || !table->maxlen || !*lenp || (*ppos && !write)) {
*lenp = 0;
return 0;
}
if (write) {
rc = lprocfs_write_frac_helper(buffer, *lenp,
(unsigned int*)table->data,
OBD_ALLOC_FAIL_MULT);
} else {
char buf[21];
int len;
len = lprocfs_read_frac_helper(buf, 21,
*(unsigned int*)table->data,
OBD_ALLOC_FAIL_MULT);
if (len > *lenp)
len = *lenp;
buf[len] = '\0';
if (copy_to_user(buffer, buf, len))
return -EFAULT;
*lenp = len;
}
*ppos += *lenp;
return rc;
}
int LL_PROC_PROTO(proc_at_min)
{
return ll_proc_dointvec(table, write, filp, buffer, lenp, ppos);
}
int LL_PROC_PROTO(proc_at_max)
{
return ll_proc_dointvec(table, write, filp, buffer, lenp, ppos);
}
int LL_PROC_PROTO(proc_at_extra)
{
return ll_proc_dointvec(table, write, filp, buffer, lenp, ppos);
}
int LL_PROC_PROTO(proc_at_early_margin)
{
return ll_proc_dointvec(table, write, filp, buffer, lenp, ppos);
}
int LL_PROC_PROTO(proc_at_history)
{
return ll_proc_dointvec(table, write, filp, buffer, lenp, ppos);
}
void obd_sysctl_init (void)
{
#ifdef CONFIG_SYSCTL
if ( !obd_table_header )
obd_table_header = cfs_register_sysctl_table(parent_table, 0);
#endif
}
void obd_sysctl_clean (void)
{
#ifdef CONFIG_SYSCTL
if ( obd_table_header )
unregister_sysctl_table(obd_table_header);
obd_table_header = NULL;
#endif
}
