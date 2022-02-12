int nf_conntrack_timeout_init(struct net *net)
{
int ret = 0;
if (net_eq(net, &init_net)) {
ret = nf_ct_extend_register(&timeout_extend);
if (ret < 0) {
printk(KERN_ERR "nf_ct_timeout: Unable to register "
"timeout extension.\n");
return ret;
}
}
return 0;
}
void nf_conntrack_timeout_fini(struct net *net)
{
if (net_eq(net, &init_net))
nf_ct_extend_unregister(&timeout_extend);
}
