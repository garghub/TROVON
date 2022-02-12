static int cpu_mt_check(const struct xt_mtchk_param *par)
{
const struct xt_cpu_info *info = par->matchinfo;
if (info->invert & ~1)
return -EINVAL;
return 0;
}
static bool cpu_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_cpu_info *info = par->matchinfo;
return (info->cpu == smp_processor_id()) ^ info->invert;
}
static int __init cpu_mt_init(void)
{
return xt_register_match(&cpu_mt_reg);
}
static void __exit cpu_mt_exit(void)
{
xt_unregister_match(&cpu_mt_reg);
}
