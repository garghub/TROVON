static int do_devname(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int ret;
ret = proc_dostring(table, write, buffer, lenp, ppos);
if (ret == 0 && write) {
struct ias_value *val;
val = irias_new_string_value(sysctl_devname);
if (val)
irias_object_change_attribute("Device", "DeviceName", val);
}
return ret;
}
static int do_discovery(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp, loff_t *ppos)
{
int ret;
ret = proc_dointvec(table, write, buffer, lenp, ppos);
if (ret)
return ret;
if (irlmp == NULL)
return -ENODEV;
if (sysctl_discovery)
irlmp_start_discovery_timer(irlmp, sysctl_discovery_timeout*HZ);
else
del_timer_sync(&irlmp->discovery_timer);
return ret;
}
int __init irda_sysctl_register(void)
{
irda_table_header = register_net_sysctl(&init_net, "net/irda", irda_table);
if (!irda_table_header)
return -ENOMEM;
return 0;
}
void irda_sysctl_unregister(void)
{
unregister_net_sysctl_table(irda_table_header);
}
