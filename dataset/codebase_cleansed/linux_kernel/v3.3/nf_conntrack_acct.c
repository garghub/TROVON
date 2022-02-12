unsigned int
seq_print_acct(struct seq_file *s, const struct nf_conn *ct, int dir)
{
struct nf_conn_counter *acct;
acct = nf_conn_acct_find(ct);
if (!acct)
return 0;
return seq_printf(s, "packets=%llu bytes=%llu ",
(unsigned long long)atomic64_read(&acct[dir].packets),
(unsigned long long)atomic64_read(&acct[dir].bytes));
}
static int nf_conntrack_acct_init_sysctl(struct net *net)
{
struct ctl_table *table;
table = kmemdup(acct_sysctl_table, sizeof(acct_sysctl_table),
GFP_KERNEL);
if (!table)
goto out;
table[0].data = &net->ct.sysctl_acct;
net->ct.acct_sysctl_header = register_net_sysctl_table(net,
nf_net_netfilter_sysctl_path, table);
if (!net->ct.acct_sysctl_header) {
printk(KERN_ERR "nf_conntrack_acct: can't register to sysctl.\n");
goto out_register;
}
return 0;
out_register:
kfree(table);
out:
return -ENOMEM;
}
static void nf_conntrack_acct_fini_sysctl(struct net *net)
{
struct ctl_table *table;
table = net->ct.acct_sysctl_header->ctl_table_arg;
unregister_net_sysctl_table(net->ct.acct_sysctl_header);
kfree(table);
}
static int nf_conntrack_acct_init_sysctl(struct net *net)
{
return 0;
}
static void nf_conntrack_acct_fini_sysctl(struct net *net)
{
}
int nf_conntrack_acct_init(struct net *net)
{
int ret;
net->ct.sysctl_acct = nf_ct_acct;
if (net_eq(net, &init_net)) {
ret = nf_ct_extend_register(&acct_extend);
if (ret < 0) {
printk(KERN_ERR "nf_conntrack_acct: Unable to register extension\n");
goto out_extend_register;
}
}
ret = nf_conntrack_acct_init_sysctl(net);
if (ret < 0)
goto out_sysctl;
return 0;
out_sysctl:
if (net_eq(net, &init_net))
nf_ct_extend_unregister(&acct_extend);
out_extend_register:
return ret;
}
void nf_conntrack_acct_fini(struct net *net)
{
nf_conntrack_acct_fini_sysctl(net);
if (net_eq(net, &init_net))
nf_ct_extend_unregister(&acct_extend);
}
