static int xfrm_statistics_seq_show(struct seq_file *seq, void *v)
{
struct net *net = seq->private;
int i;
for (i=0; xfrm_mib_list[i].name; i++)
seq_printf(seq, "%-24s\t%lu\n", xfrm_mib_list[i].name,
snmp_fold_field((void __percpu **)
net->mib.xfrm_statistics,
xfrm_mib_list[i].entry));
return 0;
}
static int xfrm_statistics_seq_open(struct inode *inode, struct file *file)
{
return single_open_net(inode, file, xfrm_statistics_seq_show);
}
int __net_init xfrm_proc_init(struct net *net)
{
if (!proc_net_fops_create(net, "xfrm_stat", S_IRUGO,
&xfrm_statistics_seq_fops))
return -ENOMEM;
return 0;
}
void xfrm_proc_fini(struct net *net)
{
proc_net_remove(net, "xfrm_stat");
}
