int __net_init unix_sysctl_register(struct net *net)
{
struct ctl_table *table;
table = kmemdup(unix_table, sizeof(unix_table), GFP_KERNEL);
if (table == NULL)
goto err_alloc;
table[0].data = &net->unx.sysctl_max_dgram_qlen;
net->unx.ctl = register_net_sysctl(net, "net/unix", table);
if (net->unx.ctl == NULL)
goto err_reg;
return 0;
err_reg:
kfree(table);
err_alloc:
return -ENOMEM;
}
void unix_sysctl_unregister(struct net *net)
{
struct ctl_table *table;
table = net->unx.ctl->ctl_table_arg;
unregister_net_sysctl_table(net->unx.ctl);
kfree(table);
}
