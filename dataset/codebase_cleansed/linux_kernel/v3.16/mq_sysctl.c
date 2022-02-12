static void *get_mq(struct ctl_table *table)
{
char *which = table->data;
struct ipc_namespace *ipc_ns = current->nsproxy->ipc_ns;
which = (which - (char *)&init_ipc_ns) + (char *)ipc_ns;
return which;
}
static int proc_mq_dointvec(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table mq_table;
memcpy(&mq_table, table, sizeof(mq_table));
mq_table.data = get_mq(table);
return proc_dointvec(&mq_table, write, buffer, lenp, ppos);
}
static int proc_mq_dointvec_minmax(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table mq_table;
memcpy(&mq_table, table, sizeof(mq_table));
mq_table.data = get_mq(table);
return proc_dointvec_minmax(&mq_table, write, buffer,
lenp, ppos);
}
struct ctl_table_header *mq_register_sysctl_table(void)
{
return register_sysctl_table(mq_sysctl_root);
}
