static bool
string_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_string_info *conf = par->matchinfo;
struct ts_state state;
bool invert;
memset(&state, 0, sizeof(struct ts_state));
invert = conf->u.v1.flags & XT_STRING_FLAG_INVERT;
return (skb_find_text((struct sk_buff *)skb, conf->from_offset,
conf->to_offset, conf->config, &state)
!= UINT_MAX) ^ invert;
}
static int string_mt_check(const struct xt_mtchk_param *par)
{
struct xt_string_info *conf = par->matchinfo;
struct ts_config *ts_conf;
int flags = TS_AUTOLOAD;
if (conf->from_offset > conf->to_offset)
return -EINVAL;
if (conf->algo[XT_STRING_MAX_ALGO_NAME_SIZE - 1] != '\0')
return -EINVAL;
if (conf->patlen > XT_STRING_MAX_PATTERN_SIZE)
return -EINVAL;
if (conf->u.v1.flags &
~(XT_STRING_FLAG_IGNORECASE | XT_STRING_FLAG_INVERT))
return -EINVAL;
if (conf->u.v1.flags & XT_STRING_FLAG_IGNORECASE)
flags |= TS_IGNORECASE;
ts_conf = textsearch_prepare(conf->algo, conf->pattern, conf->patlen,
GFP_KERNEL, flags);
if (IS_ERR(ts_conf))
return PTR_ERR(ts_conf);
conf->config = ts_conf;
return 0;
}
static void string_mt_destroy(const struct xt_mtdtor_param *par)
{
textsearch_destroy(STRING_TEXT_PRIV(par->matchinfo)->config);
}
static int __init string_mt_init(void)
{
return xt_register_match(&xt_string_mt_reg);
}
static void __exit string_mt_exit(void)
{
xt_unregister_match(&xt_string_mt_reg);
}
