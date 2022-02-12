static unsigned int
ebt_nflog_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct ebt_nflog_info *info = par->targinfo;
struct net *net = xt_net(par);
struct nf_loginfo li;
li.type = NF_LOG_TYPE_ULOG;
li.u.ulog.copy_len = info->len;
li.u.ulog.group = info->group;
li.u.ulog.qthreshold = info->threshold;
li.u.ulog.flags = 0;
nf_log_packet(net, PF_BRIDGE, xt_hooknum(par), skb, xt_in(par),
xt_out(par), &li, "%s", info->prefix);
return EBT_CONTINUE;
}
static int ebt_nflog_tg_check(const struct xt_tgchk_param *par)
{
struct ebt_nflog_info *info = par->targinfo;
if (info->flags & ~EBT_NFLOG_MASK)
return -EINVAL;
info->prefix[EBT_NFLOG_PREFIX_SIZE - 1] = '\0';
return 0;
}
static int __init ebt_nflog_init(void)
{
return xt_register_target(&ebt_nflog_tg_reg);
}
static void __exit ebt_nflog_fini(void)
{
xt_unregister_target(&ebt_nflog_tg_reg);
}
