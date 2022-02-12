static int nf_conntrack_tstamp_init_sysctl(struct net *net)
{
struct ctl_table *table;
table = kmemdup(tstamp_sysctl_table, sizeof(tstamp_sysctl_table),
GFP_KERNEL);
if (!table)
goto out;
table[0].data = &net->ct.sysctl_tstamp;
if (net->user_ns != &init_user_ns)
table[0].procname = NULL;
net->ct.tstamp_sysctl_header = register_net_sysctl(net, "net/netfilter",
table);
if (!net->ct.tstamp_sysctl_header) {
printk(KERN_ERR "nf_ct_tstamp: can't register to sysctl.\n");
goto out_register;
}
return 0;
out_register:
kfree(table);
out:
return -ENOMEM;
}
static void nf_conntrack_tstamp_fini_sysctl(struct net *net)
{
struct ctl_table *table;
table = net->ct.tstamp_sysctl_header->ctl_table_arg;
unregister_net_sysctl_table(net->ct.tstamp_sysctl_header);
kfree(table);
}
static int nf_conntrack_tstamp_init_sysctl(struct net *net)
{
return 0;
}
static void nf_conntrack_tstamp_fini_sysctl(struct net *net)
{
}
int nf_conntrack_tstamp_init(struct net *net)
{
int ret;
net->ct.sysctl_tstamp = nf_ct_tstamp;
if (net_eq(net, &init_net)) {
ret = nf_ct_extend_register(&tstamp_extend);
if (ret < 0) {
printk(KERN_ERR "nf_ct_tstamp: Unable to register "
"extension\n");
goto out_extend_register;
}
}
ret = nf_conntrack_tstamp_init_sysctl(net);
if (ret < 0)
goto out_sysctl;
return 0;
out_sysctl:
if (net_eq(net, &init_net))
nf_ct_extend_unregister(&tstamp_extend);
out_extend_register:
return ret;
}
void nf_conntrack_tstamp_fini(struct net *net)
{
nf_conntrack_tstamp_fini_sysctl(net);
if (net_eq(net, &init_net))
nf_ct_extend_unregister(&tstamp_extend);
}
