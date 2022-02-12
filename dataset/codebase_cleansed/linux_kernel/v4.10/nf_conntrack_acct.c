unsigned int
seq_print_acct(struct seq_file *s, const struct nf_conn *ct, int dir)
{
struct nf_conn_acct *acct;
struct nf_conn_counter *counter;
acct = nf_conn_acct_find(ct);
if (!acct)
return 0;
counter = acct->counter;
seq_printf(s, "packets=%llu bytes=%llu ",
(unsigned long long)atomic64_read(&counter[dir].packets),
(unsigned long long)atomic64_read(&counter[dir].bytes));
return 0;
}
static int nf_conntrack_acct_init_sysctl(struct net *net)
{
struct ctl_table *table;
table = kmemdup(acct_sysctl_table, sizeof(acct_sysctl_table),
GFP_KERNEL);
if (!table)
goto out;
table[0].data = &net->ct.sysctl_acct;
if (net->user_ns != &init_user_ns)
table[0].procname = NULL;
net->ct.acct_sysctl_header = register_net_sysctl(net, "net/netfilter",
table);
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
int nf_conntrack_acct_pernet_init(struct net *net)
{
net->ct.sysctl_acct = nf_ct_acct;
return nf_conntrack_acct_init_sysctl(net);
}
void nf_conntrack_acct_pernet_fini(struct net *net)
{
nf_conntrack_acct_fini_sysctl(net);
}
int nf_conntrack_acct_init(void)
{
int ret = nf_ct_extend_register(&acct_extend);
if (ret < 0)
pr_err("nf_conntrack_acct: Unable to register extension\n");
return ret;
}
void nf_conntrack_acct_fini(void)
{
nf_ct_extend_unregister(&acct_extend);
}
