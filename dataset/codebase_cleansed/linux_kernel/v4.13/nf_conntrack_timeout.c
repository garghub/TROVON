int nf_conntrack_timeout_init(void)
{
int ret = nf_ct_extend_register(&timeout_extend);
if (ret < 0)
pr_err("nf_ct_timeout: Unable to register timeout extension.\n");
return ret;
}
void nf_conntrack_timeout_fini(void)
{
nf_ct_extend_unregister(&timeout_extend);
}
