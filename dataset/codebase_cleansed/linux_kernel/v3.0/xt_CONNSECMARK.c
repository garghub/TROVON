static void secmark_save(const struct sk_buff *skb)
{
if (skb->secmark) {
struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
ct = nf_ct_get(skb, &ctinfo);
if (ct && !ct->secmark) {
ct->secmark = skb->secmark;
nf_conntrack_event_cache(IPCT_SECMARK, ct);
}
}
}
static void secmark_restore(struct sk_buff *skb)
{
if (!skb->secmark) {
const struct nf_conn *ct;
enum ip_conntrack_info ctinfo;
ct = nf_ct_get(skb, &ctinfo);
if (ct && ct->secmark)
skb->secmark = ct->secmark;
}
}
static unsigned int
connsecmark_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_connsecmark_target_info *info = par->targinfo;
switch (info->mode) {
case CONNSECMARK_SAVE:
secmark_save(skb);
break;
case CONNSECMARK_RESTORE:
secmark_restore(skb);
break;
default:
BUG();
}
return XT_CONTINUE;
}
static int connsecmark_tg_check(const struct xt_tgchk_param *par)
{
const struct xt_connsecmark_target_info *info = par->targinfo;
int ret;
if (strcmp(par->table, "mangle") != 0 &&
strcmp(par->table, "security") != 0) {
pr_info("target only valid in the \'mangle\' "
"or \'security\' tables, not \'%s\'.\n", par->table);
return -EINVAL;
}
switch (info->mode) {
case CONNSECMARK_SAVE:
case CONNSECMARK_RESTORE:
break;
default:
pr_info("invalid mode: %hu\n", info->mode);
return -EINVAL;
}
ret = nf_ct_l3proto_try_module_get(par->family);
if (ret < 0)
pr_info("cannot load conntrack support for proto=%u\n",
par->family);
return ret;
}
static void connsecmark_tg_destroy(const struct xt_tgdtor_param *par)
{
nf_ct_l3proto_module_put(par->family);
}
static int __init connsecmark_tg_init(void)
{
return xt_register_target(&connsecmark_tg_reg);
}
static void __exit connsecmark_tg_exit(void)
{
xt_unregister_target(&connsecmark_tg_reg);
}
