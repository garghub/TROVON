static int bpf_mt_check(const struct xt_mtchk_param *par)
{
struct xt_bpf_info *info = par->matchinfo;
struct sock_fprog_kern program;
program.len = info->bpf_program_num_elem;
program.filter = info->bpf_program;
if (sk_unattached_filter_create(&info->filter, &program)) {
pr_info("bpf: check failed: parse error\n");
return -EINVAL;
}
return 0;
}
static bool bpf_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_bpf_info *info = par->matchinfo;
return SK_RUN_FILTER(info->filter, skb);
}
static void bpf_mt_destroy(const struct xt_mtdtor_param *par)
{
const struct xt_bpf_info *info = par->matchinfo;
sk_unattached_filter_destroy(info->filter);
}
static int __init bpf_mt_init(void)
{
return xt_register_match(&bpf_mt_reg);
}
static void __exit bpf_mt_exit(void)
{
xt_unregister_match(&bpf_mt_reg);
}
