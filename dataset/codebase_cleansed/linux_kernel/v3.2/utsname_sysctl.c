static void *get_uts(ctl_table *table, int write)
{
char *which = table->data;
struct uts_namespace *uts_ns;
uts_ns = current->nsproxy->uts_ns;
which = (which - (char *)&init_uts_ns) + (char *)uts_ns;
if (!write)
down_read(&uts_sem);
else
down_write(&uts_sem);
return which;
}
static void put_uts(ctl_table *table, int write, void *which)
{
if (!write)
up_read(&uts_sem);
else
up_write(&uts_sem);
}
static int proc_do_uts_string(ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
struct ctl_table uts_table;
int r;
memcpy(&uts_table, table, sizeof(uts_table));
uts_table.data = get_uts(table, write);
r = proc_dostring(&uts_table,write,buffer,lenp, ppos);
put_uts(table, write, uts_table.data);
if (write)
proc_sys_poll_notify(table->poll);
return r;
}
void uts_proc_notify(enum uts_proc proc)
{
struct ctl_table *table = &uts_kern_table[proc];
proc_sys_poll_notify(table->poll);
}
static int __init utsname_sysctl_init(void)
{
register_sysctl_table(uts_root_table);
return 0;
}
