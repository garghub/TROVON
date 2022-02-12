static unsigned int
connmark_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_connmark_tginfo1 *info = par->targinfo;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
u_int32_t newmark;
ct = nf_ct_get(skb, &ctinfo);
if (ct == NULL || nf_ct_is_untracked(ct))
return XT_CONTINUE;
switch (info->mode) {
case XT_CONNMARK_SET:
newmark = (ct->mark & ~info->ctmask) ^ info->ctmark;
if (ct->mark != newmark) {
ct->mark = newmark;
nf_conntrack_event_cache(IPCT_MARK, ct);
}
break;
case XT_CONNMARK_SAVE:
newmark = (ct->mark & ~info->ctmask) ^
(skb->mark & info->nfmask);
if (ct->mark != newmark) {
ct->mark = newmark;
nf_conntrack_event_cache(IPCT_MARK, ct);
}
break;
case XT_CONNMARK_RESTORE:
newmark = (skb->mark & ~info->nfmask) ^
(ct->mark & info->ctmask);
skb->mark = newmark;
break;
}
return XT_CONTINUE;
}
static int connmark_tg_check(const struct xt_tgchk_param *par)
{
int ret;
ret = nf_ct_netns_get(par->net, par->family);
if (ret < 0)
pr_info("cannot load conntrack support for proto=%u\n",
par->family);
return ret;
}
static void connmark_tg_destroy(const struct xt_tgdtor_param *par)
{
nf_ct_netns_put(par->net, par->family);
}
static bool
connmark_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_connmark_mtinfo1 *info = par->matchinfo;
enum ip_conntrack_info ctinfo;
const struct nf_conn *ct;
ct = nf_ct_get(skb, &ctinfo);
if (ct == NULL || nf_ct_is_untracked(ct))
return false;
return ((ct->mark & info->mask) == info->mark) ^ info->invert;
}
static int connmark_mt_check(const struct xt_mtchk_param *par)
{
int ret;
ret = nf_ct_netns_get(par->net, par->family);
if (ret < 0)
pr_info("cannot load conntrack support for proto=%u\n",
par->family);
return ret;
}
static void connmark_mt_destroy(const struct xt_mtdtor_param *par)
{
nf_ct_netns_put(par->net, par->family);
}
static int __init connmark_mt_init(void)
{
int ret;
ret = xt_register_target(&connmark_tg_reg);
if (ret < 0)
return ret;
ret = xt_register_match(&connmark_mt_reg);
if (ret < 0) {
xt_unregister_target(&connmark_tg_reg);
return ret;
}
return 0;
}
static void __exit connmark_mt_exit(void)
{
xt_unregister_match(&connmark_mt_reg);
xt_unregister_target(&connmark_tg_reg);
}
