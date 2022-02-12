static unsigned int
log_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_log_info *loginfo = par->targinfo;
struct nf_loginfo li;
struct net *net = par->net;
li.type = NF_LOG_TYPE_LOG;
li.u.log.level = loginfo->level;
li.u.log.logflags = loginfo->logflags;
nf_log_packet(net, par->family, par->hooknum, skb, par->in, par->out,
&li, "%s", loginfo->prefix);
return XT_CONTINUE;
}
static int log_tg_check(const struct xt_tgchk_param *par)
{
const struct xt_log_info *loginfo = par->targinfo;
if (par->family != NFPROTO_IPV4 && par->family != NFPROTO_IPV6)
return -EINVAL;
if (loginfo->level >= 8) {
pr_debug("level %u >= 8\n", loginfo->level);
return -EINVAL;
}
if (loginfo->prefix[sizeof(loginfo->prefix)-1] != '\0') {
pr_debug("prefix is not null-terminated\n");
return -EINVAL;
}
return nf_logger_find_get(par->family, NF_LOG_TYPE_LOG);
}
static void log_tg_destroy(const struct xt_tgdtor_param *par)
{
nf_logger_put(par->family, NF_LOG_TYPE_LOG);
}
static int __init log_tg_init(void)
{
return xt_register_targets(log_tg_regs, ARRAY_SIZE(log_tg_regs));
}
static void __exit log_tg_exit(void)
{
xt_unregister_targets(log_tg_regs, ARRAY_SIZE(log_tg_regs));
}
