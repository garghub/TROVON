static inline int
match_set(ip_set_id_t index, const struct sk_buff *skb,
u8 pf, u8 dim, u8 flags, int inv)
{
if (ip_set_test(index, skb, pf, dim, flags))
inv = !inv;
return inv;
}
static bool
set_match_v0(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_set_info_match_v0 *info = par->matchinfo;
return match_set(info->match_set.index, skb, par->family,
info->match_set.u.compat.dim,
info->match_set.u.compat.flags,
info->match_set.u.compat.flags & IPSET_INV_MATCH);
}
static void
compat_flags(struct xt_set_info_v0 *info)
{
u_int8_t i;
info->u.compat.dim = IPSET_DIM_ZERO;
if (info->u.flags[0] & IPSET_MATCH_INV)
info->u.compat.flags |= IPSET_INV_MATCH;
for (i = 0; i < IPSET_DIM_MAX-1 && info->u.flags[i]; i++) {
info->u.compat.dim++;
if (info->u.flags[i] & IPSET_SRC)
info->u.compat.flags |= (1<<info->u.compat.dim);
}
}
static int
set_match_v0_checkentry(const struct xt_mtchk_param *par)
{
struct xt_set_info_match_v0 *info = par->matchinfo;
ip_set_id_t index;
index = ip_set_nfnl_get_byindex(info->match_set.index);
if (index == IPSET_INVALID_ID) {
pr_warning("Cannot find set indentified by id %u to match\n",
info->match_set.index);
return -ENOENT;
}
if (info->match_set.u.flags[IPSET_DIM_MAX-1] != 0) {
pr_warning("Protocol error: set match dimension "
"is over the limit!\n");
ip_set_nfnl_put(info->match_set.index);
return -ERANGE;
}
compat_flags(&info->match_set);
return 0;
}
static void
set_match_v0_destroy(const struct xt_mtdtor_param *par)
{
struct xt_set_info_match_v0 *info = par->matchinfo;
ip_set_nfnl_put(info->match_set.index);
}
static unsigned int
set_target_v0(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_set_info_target_v0 *info = par->targinfo;
if (info->add_set.index != IPSET_INVALID_ID)
ip_set_add(info->add_set.index, skb, par->family,
info->add_set.u.compat.dim,
info->add_set.u.compat.flags);
if (info->del_set.index != IPSET_INVALID_ID)
ip_set_del(info->del_set.index, skb, par->family,
info->del_set.u.compat.dim,
info->del_set.u.compat.flags);
return XT_CONTINUE;
}
static int
set_target_v0_checkentry(const struct xt_tgchk_param *par)
{
struct xt_set_info_target_v0 *info = par->targinfo;
ip_set_id_t index;
if (info->add_set.index != IPSET_INVALID_ID) {
index = ip_set_nfnl_get_byindex(info->add_set.index);
if (index == IPSET_INVALID_ID) {
pr_warning("Cannot find add_set index %u as target\n",
info->add_set.index);
return -ENOENT;
}
}
if (info->del_set.index != IPSET_INVALID_ID) {
index = ip_set_nfnl_get_byindex(info->del_set.index);
if (index == IPSET_INVALID_ID) {
pr_warning("Cannot find del_set index %u as target\n",
info->del_set.index);
if (info->add_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->add_set.index);
return -ENOENT;
}
}
if (info->add_set.u.flags[IPSET_DIM_MAX-1] != 0 ||
info->del_set.u.flags[IPSET_DIM_MAX-1] != 0) {
pr_warning("Protocol error: SET target dimension "
"is over the limit!\n");
if (info->add_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->add_set.index);
if (info->del_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->del_set.index);
return -ERANGE;
}
compat_flags(&info->add_set);
compat_flags(&info->del_set);
return 0;
}
static void
set_target_v0_destroy(const struct xt_tgdtor_param *par)
{
const struct xt_set_info_target_v0 *info = par->targinfo;
if (info->add_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->add_set.index);
if (info->del_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->del_set.index);
}
static bool
set_match(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_set_info_match *info = par->matchinfo;
return match_set(info->match_set.index, skb, par->family,
info->match_set.dim,
info->match_set.flags,
info->match_set.flags & IPSET_INV_MATCH);
}
static int
set_match_checkentry(const struct xt_mtchk_param *par)
{
struct xt_set_info_match *info = par->matchinfo;
ip_set_id_t index;
index = ip_set_nfnl_get_byindex(info->match_set.index);
if (index == IPSET_INVALID_ID) {
pr_warning("Cannot find set indentified by id %u to match\n",
info->match_set.index);
return -ENOENT;
}
if (info->match_set.dim > IPSET_DIM_MAX) {
pr_warning("Protocol error: set match dimension "
"is over the limit!\n");
ip_set_nfnl_put(info->match_set.index);
return -ERANGE;
}
return 0;
}
static void
set_match_destroy(const struct xt_mtdtor_param *par)
{
struct xt_set_info_match *info = par->matchinfo;
ip_set_nfnl_put(info->match_set.index);
}
static unsigned int
set_target(struct sk_buff *skb, const struct xt_action_param *par)
{
const struct xt_set_info_target *info = par->targinfo;
if (info->add_set.index != IPSET_INVALID_ID)
ip_set_add(info->add_set.index,
skb, par->family,
info->add_set.dim,
info->add_set.flags);
if (info->del_set.index != IPSET_INVALID_ID)
ip_set_del(info->del_set.index,
skb, par->family,
info->del_set.dim,
info->del_set.flags);
return XT_CONTINUE;
}
static int
set_target_checkentry(const struct xt_tgchk_param *par)
{
const struct xt_set_info_target *info = par->targinfo;
ip_set_id_t index;
if (info->add_set.index != IPSET_INVALID_ID) {
index = ip_set_nfnl_get_byindex(info->add_set.index);
if (index == IPSET_INVALID_ID) {
pr_warning("Cannot find add_set index %u as target\n",
info->add_set.index);
return -ENOENT;
}
}
if (info->del_set.index != IPSET_INVALID_ID) {
index = ip_set_nfnl_get_byindex(info->del_set.index);
if (index == IPSET_INVALID_ID) {
pr_warning("Cannot find del_set index %u as target\n",
info->del_set.index);
if (info->add_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->add_set.index);
return -ENOENT;
}
}
if (info->add_set.dim > IPSET_DIM_MAX ||
info->del_set.dim > IPSET_DIM_MAX) {
pr_warning("Protocol error: SET target dimension "
"is over the limit!\n");
if (info->add_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->add_set.index);
if (info->del_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->del_set.index);
return -ERANGE;
}
return 0;
}
static void
set_target_destroy(const struct xt_tgdtor_param *par)
{
const struct xt_set_info_target *info = par->targinfo;
if (info->add_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->add_set.index);
if (info->del_set.index != IPSET_INVALID_ID)
ip_set_nfnl_put(info->del_set.index);
}
static int __init xt_set_init(void)
{
int ret = xt_register_matches(set_matches, ARRAY_SIZE(set_matches));
if (!ret) {
ret = xt_register_targets(set_targets,
ARRAY_SIZE(set_targets));
if (ret)
xt_unregister_matches(set_matches,
ARRAY_SIZE(set_matches));
}
return ret;
}
static void __exit xt_set_fini(void)
{
xt_unregister_matches(set_matches, ARRAY_SIZE(set_matches));
xt_unregister_targets(set_targets, ARRAY_SIZE(set_targets));
}
