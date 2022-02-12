static void *get_ipc(ctl_table *table)
{
char *which = table->data;
struct ipc_namespace *ipc_ns = current->nsproxy->ipc_ns;
which = (which - (char *)&init_ipc_ns) + (char *)ipc_ns;
return which;
}
static int proc_ipc_dointvec(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table ipc_table;
memcpy(&ipc_table, table, sizeof(ipc_table));
ipc_table.data = get_ipc(table);
return proc_dointvec(&ipc_table, write, buffer, lenp, ppos);
}
static int proc_ipc_dointvec_minmax(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table ipc_table;
memcpy(&ipc_table, table, sizeof(ipc_table));
ipc_table.data = get_ipc(table);
return proc_dointvec_minmax(&ipc_table, write, buffer, lenp, ppos);
}
static int proc_ipc_dointvec_minmax_orphans(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ipc_namespace *ns = current->nsproxy->ipc_ns;
int err = proc_ipc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (err < 0)
return err;
if (ns->shm_rmid_forced)
shm_destroy_orphaned(ns);
return err;
}
static int proc_ipc_callback_dointvec(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table ipc_table;
size_t lenp_bef = *lenp;
int rc;
memcpy(&ipc_table, table, sizeof(ipc_table));
ipc_table.data = get_ipc(table);
rc = proc_dointvec(&ipc_table, write, buffer, lenp, ppos);
if (write && !rc && lenp_bef == *lenp)
unregister_ipcns_notifier(current->nsproxy->ipc_ns);
return rc;
}
static int proc_ipc_doulongvec_minmax(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table ipc_table;
memcpy(&ipc_table, table, sizeof(ipc_table));
ipc_table.data = get_ipc(table);
return proc_doulongvec_minmax(&ipc_table, write, buffer,
lenp, ppos);
}
static void ipc_auto_callback(int val)
{
if (!val)
unregister_ipcns_notifier(current->nsproxy->ipc_ns);
else {
recompute_msgmni(current->nsproxy->ipc_ns);
cond_register_ipcns_notifier(current->nsproxy->ipc_ns);
}
}
static int proc_ipcauto_dointvec_minmax(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table ipc_table;
size_t lenp_bef = *lenp;
int oldval;
int rc;
memcpy(&ipc_table, table, sizeof(ipc_table));
ipc_table.data = get_ipc(table);
oldval = *((int *)(ipc_table.data));
rc = proc_dointvec_minmax(&ipc_table, write, buffer, lenp, ppos);
if (write && !rc && lenp_bef == *lenp) {
int newval = *((int *)(ipc_table.data));
if (newval != oldval)
ipc_auto_callback(newval);
}
return rc;
}
static int __init ipc_sysctl_init(void)
{
register_sysctl_table(ipc_root_table);
return 0;
}
