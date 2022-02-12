int ax25_register_dev_sysctl(ax25_dev *ax25_dev)
{
char path[sizeof("net/ax25/") + IFNAMSIZ];
int k;
struct ctl_table *table;
table = kmemdup(ax25_param_table, sizeof(ax25_param_table), GFP_KERNEL);
if (!table)
return -ENOMEM;
for (k = 0; k < AX25_MAX_VALUES; k++)
table[k].data = &ax25_dev->values[k];
snprintf(path, sizeof(path), "net/ax25/%s", ax25_dev->dev->name);
ax25_dev->sysheader = register_net_sysctl(&init_net, path, table);
if (!ax25_dev->sysheader) {
kfree(table);
return -ENOMEM;
}
return 0;
}
void ax25_unregister_dev_sysctl(ax25_dev *ax25_dev)
{
struct ctl_table_header *header = ax25_dev->sysheader;
struct ctl_table *table;
if (header) {
ax25_dev->sysheader = NULL;
table = header->ctl_table_arg;
unregister_net_sysctl_table(header);
kfree(table);
}
}
