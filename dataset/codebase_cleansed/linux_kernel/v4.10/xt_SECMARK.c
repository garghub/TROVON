static unsigned int
secmark_tg(struct sk_buff *skb, const struct xt_action_param *par)
{
u32 secmark = 0;
const struct xt_secmark_target_info *info = par->targinfo;
BUG_ON(info->mode != mode);
switch (mode) {
case SECMARK_MODE_SEL:
secmark = info->secid;
break;
default:
BUG();
}
skb->secmark = secmark;
return XT_CONTINUE;
}
static int checkentry_lsm(struct xt_secmark_target_info *info)
{
int err;
info->secctx[SECMARK_SECCTX_MAX - 1] = '\0';
info->secid = 0;
err = security_secctx_to_secid(info->secctx, strlen(info->secctx),
&info->secid);
if (err) {
if (err == -EINVAL)
pr_info("invalid security context \'%s\'\n", info->secctx);
return err;
}
if (!info->secid) {
pr_info("unable to map security context \'%s\'\n", info->secctx);
return -ENOENT;
}
err = security_secmark_relabel_packet(info->secid);
if (err) {
pr_info("unable to obtain relabeling permission\n");
return err;
}
security_secmark_refcount_inc();
return 0;
}
static int secmark_tg_check(const struct xt_tgchk_param *par)
{
struct xt_secmark_target_info *info = par->targinfo;
int err;
if (strcmp(par->table, "mangle") != 0 &&
strcmp(par->table, "security") != 0) {
pr_info("target only valid in the \'mangle\' "
"or \'security\' tables, not \'%s\'.\n", par->table);
return -EINVAL;
}
if (mode && mode != info->mode) {
pr_info("mode already set to %hu cannot mix with "
"rules for mode %hu\n", mode, info->mode);
return -EINVAL;
}
switch (info->mode) {
case SECMARK_MODE_SEL:
break;
default:
pr_info("invalid mode: %hu\n", info->mode);
return -EINVAL;
}
err = checkentry_lsm(info);
if (err)
return err;
if (!mode)
mode = info->mode;
return 0;
}
static void secmark_tg_destroy(const struct xt_tgdtor_param *par)
{
switch (mode) {
case SECMARK_MODE_SEL:
security_secmark_refcount_dec();
}
}
static int __init secmark_tg_init(void)
{
return xt_register_target(&secmark_tg_reg);
}
static void __exit secmark_tg_exit(void)
{
xt_unregister_target(&secmark_tg_reg);
}
