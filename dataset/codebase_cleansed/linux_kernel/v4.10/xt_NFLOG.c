static unsigned int
nflog_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_nflog_info *info = par->targinfo;
struct net *net = xt_net(par);
struct nf_loginfo li;
li.type = NF_LOG_TYPE_ULOG;
li.u.ulog.copy_len = info->len;
li.u.ulog.group = info->group;
li.u.ulog.qthreshold = info->threshold;
li.u.ulog.flags = 0;
if (info->flags & XT_NFLOG_F_COPY_LEN)
li.u.ulog.flags |= NF_LOG_F_COPY_LEN;
nfulnl_log_packet(net, xt_family(par), xt_hooknum(par), skb,
xt_in(par), xt_out(par), &li, info->prefix);
return XT_CONTINUE;
}
static int nflog_tg_check(const struct xt_tgchk_param *par)
{
const struct xt_nflog_info *info = par->targinfo;
if (info->flags & ~XT_NFLOG_MASK)
return -EINVAL;
if (info->prefix[sizeof(info->prefix) - 1] != '\0')
return -EINVAL;
return 0;
}
static int __init nflog_tg_init(void)
{
return xt_register_target(&nflog_tg_reg);
}
static void __exit nflog_tg_exit(void)
{
xt_unregister_target(&nflog_tg_reg);
}
