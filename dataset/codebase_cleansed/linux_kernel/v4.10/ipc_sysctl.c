static void *get_ipc(struct ctl_table *table)
{
char *which = table->data;
struct ipc_namespace *ipc_ns = current->nsproxy->ipc_ns;
which = (which - (char *)&init_ipc_ns) + (char *)ipc_ns;
return which;
}
static int proc_ipc_dointvec(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table ipc_table;
memcpy(&ipc_table, table, sizeof(ipc_table));
ipc_table.data = get_ipc(table);
return proc_dointvec(&ipc_table, write, buffer, lenp, ppos);
}
static int proc_ipc_dointvec_minmax(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table ipc_table;
memcpy(&ipc_table, table, sizeof(ipc_table));
ipc_table.data = get_ipc(table);
return proc_dointvec_minmax(&ipc_table, write, buffer, lenp, ppos);
}
static int proc_ipc_dointvec_minmax_orphans(struct ctl_table *table, int write,
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
static int proc_ipc_doulongvec_minmax(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table ipc_table;
memcpy(&ipc_table, table, sizeof(ipc_table));
ipc_table.data = get_ipc(table);
return proc_doulongvec_minmax(&ipc_table, write, buffer,
lenp, ppos);
}
static int proc_ipc_auto_msgmni(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table ipc_table;
int dummy = 0;
memcpy(&ipc_table, table, sizeof(ipc_table));
ipc_table.data = &dummy;
if (write)
pr_info_once("writing to auto_msgmni has no effect");
return proc_dointvec_minmax(&ipc_table, write, buffer, lenp, ppos);
}
static int __init ipc_sysctl_init(void)
{
register_sysctl_table(ipc_root_table);
return 0;
}
