void ax25_register_sysctl(void)
{
ax25_dev *ax25_dev;
int n, k;
spin_lock_bh(&ax25_dev_lock);
for (ax25_table_size = sizeof(ctl_table), ax25_dev = ax25_dev_list; ax25_dev != NULL; ax25_dev = ax25_dev->next)
ax25_table_size += sizeof(ctl_table);
if ((ax25_table = kzalloc(ax25_table_size, GFP_ATOMIC)) == NULL) {
spin_unlock_bh(&ax25_dev_lock);
return;
}
for (n = 0, ax25_dev = ax25_dev_list; ax25_dev != NULL; ax25_dev = ax25_dev->next) {
struct ctl_table *child = kmemdup(ax25_param_table,
sizeof(ax25_param_table),
GFP_ATOMIC);
if (!child) {
while (n--)
kfree(ax25_table[n].child);
kfree(ax25_table);
spin_unlock_bh(&ax25_dev_lock);
return;
}
ax25_table[n].child = ax25_dev->systable = child;
ax25_table[n].procname = ax25_dev->dev->name;
ax25_table[n].mode = 0555;
for (k = 0; k < AX25_MAX_VALUES; k++)
child[k].data = &ax25_dev->values[k];
n++;
}
spin_unlock_bh(&ax25_dev_lock);
ax25_table_header = register_sysctl_paths(ax25_path, ax25_table);
}
void ax25_unregister_sysctl(void)
{
ctl_table *p;
unregister_sysctl_table(ax25_table_header);
for (p = ax25_table; p->procname; p++)
kfree(p->child);
kfree(ax25_table);
}
