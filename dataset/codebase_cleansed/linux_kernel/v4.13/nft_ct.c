static u64 nft_ct_get_eval_counter(const struct nf_conn_counter *c,
enum nft_ct_keys k,
enum ip_conntrack_dir d)
{
if (d < IP_CT_DIR_MAX)
return k == NFT_CT_BYTES ? atomic64_read(&c[d].bytes) :
atomic64_read(&c[d].packets);
return nft_ct_get_eval_counter(c, k, IP_CT_DIR_ORIGINAL) +
nft_ct_get_eval_counter(c, k, IP_CT_DIR_REPLY);
}
static void nft_ct_get_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_ct *priv = nft_expr_priv(expr);
u32 *dest = &regs->data[priv->dreg];
enum ip_conntrack_info ctinfo;
const struct nf_conn *ct;
const struct nf_conn_help *help;
const struct nf_conntrack_tuple *tuple;
const struct nf_conntrack_helper *helper;
unsigned int state;
ct = nf_ct_get(pkt->skb, &ctinfo);
switch (priv->key) {
case NFT_CT_STATE:
if (ct)
state = NF_CT_STATE_BIT(ctinfo);
else if (ctinfo == IP_CT_UNTRACKED)
state = NF_CT_STATE_UNTRACKED_BIT;
else
state = NF_CT_STATE_INVALID_BIT;
*dest = state;
return;
default:
break;
}
if (ct == NULL)
goto err;
switch (priv->key) {
case NFT_CT_DIRECTION:
nft_reg_store8(dest, CTINFO2DIR(ctinfo));
return;
case NFT_CT_STATUS:
*dest = ct->status;
return;
#ifdef CONFIG_NF_CONNTRACK_MARK
case NFT_CT_MARK:
*dest = ct->mark;
return;
#endif
#ifdef CONFIG_NF_CONNTRACK_SECMARK
case NFT_CT_SECMARK:
*dest = ct->secmark;
return;
#endif
case NFT_CT_EXPIRATION:
*dest = jiffies_to_msecs(nf_ct_expires(ct));
return;
case NFT_CT_HELPER:
if (ct->master == NULL)
goto err;
help = nfct_help(ct->master);
if (help == NULL)
goto err;
helper = rcu_dereference(help->helper);
if (helper == NULL)
goto err;
strncpy((char *)dest, helper->name, NF_CT_HELPER_NAME_LEN);
return;
#ifdef CONFIG_NF_CONNTRACK_LABELS
case NFT_CT_LABELS: {
struct nf_conn_labels *labels = nf_ct_labels_find(ct);
if (labels)
memcpy(dest, labels->bits, NF_CT_LABELS_MAX_SIZE);
else
memset(dest, 0, NF_CT_LABELS_MAX_SIZE);
return;
}
#endif
case NFT_CT_BYTES:
case NFT_CT_PKTS: {
const struct nf_conn_acct *acct = nf_conn_acct_find(ct);
u64 count = 0;
if (acct)
count = nft_ct_get_eval_counter(acct->counter,
priv->key, priv->dir);
memcpy(dest, &count, sizeof(count));
return;
}
case NFT_CT_AVGPKT: {
const struct nf_conn_acct *acct = nf_conn_acct_find(ct);
u64 avgcnt = 0, bcnt = 0, pcnt = 0;
if (acct) {
pcnt = nft_ct_get_eval_counter(acct->counter,
NFT_CT_PKTS, priv->dir);
bcnt = nft_ct_get_eval_counter(acct->counter,
NFT_CT_BYTES, priv->dir);
if (pcnt != 0)
avgcnt = div64_u64(bcnt, pcnt);
}
memcpy(dest, &avgcnt, sizeof(avgcnt));
return;
}
case NFT_CT_L3PROTOCOL:
nft_reg_store8(dest, nf_ct_l3num(ct));
return;
case NFT_CT_PROTOCOL:
nft_reg_store8(dest, nf_ct_protonum(ct));
return;
#ifdef CONFIG_NF_CONNTRACK_ZONES
case NFT_CT_ZONE: {
const struct nf_conntrack_zone *zone = nf_ct_zone(ct);
u16 zoneid;
if (priv->dir < IP_CT_DIR_MAX)
zoneid = nf_ct_zone_id(zone, priv->dir);
else
zoneid = zone->id;
nft_reg_store16(dest, zoneid);
return;
}
#endif
default:
break;
}
tuple = &ct->tuplehash[priv->dir].tuple;
switch (priv->key) {
case NFT_CT_SRC:
memcpy(dest, tuple->src.u3.all,
nf_ct_l3num(ct) == NFPROTO_IPV4 ? 4 : 16);
return;
case NFT_CT_DST:
memcpy(dest, tuple->dst.u3.all,
nf_ct_l3num(ct) == NFPROTO_IPV4 ? 4 : 16);
return;
case NFT_CT_PROTO_SRC:
nft_reg_store16(dest, (__force u16)tuple->src.u.all);
return;
case NFT_CT_PROTO_DST:
nft_reg_store16(dest, (__force u16)tuple->dst.u.all);
return;
default:
break;
}
return;
err:
regs->verdict.code = NFT_BREAK;
}
static void nft_ct_set_zone_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct nf_conntrack_zone zone = { .dir = NF_CT_DEFAULT_ZONE_DIR };
const struct nft_ct *priv = nft_expr_priv(expr);
struct sk_buff *skb = pkt->skb;
enum ip_conntrack_info ctinfo;
u16 value = nft_reg_load16(&regs->data[priv->sreg]);
struct nf_conn *ct;
ct = nf_ct_get(skb, &ctinfo);
if (ct)
return;
zone.id = value;
switch (priv->dir) {
case IP_CT_DIR_ORIGINAL:
zone.dir = NF_CT_ZONE_DIR_ORIG;
break;
case IP_CT_DIR_REPLY:
zone.dir = NF_CT_ZONE_DIR_REPL;
break;
default:
break;
}
ct = this_cpu_read(nft_ct_pcpu_template);
if (likely(atomic_read(&ct->ct_general.use) == 1)) {
nf_ct_zone_add(ct, &zone);
} else {
ct = nf_ct_tmpl_alloc(nft_net(pkt), &zone, GFP_ATOMIC);
if (!ct) {
regs->verdict.code = NF_DROP;
return;
}
}
atomic_inc(&ct->ct_general.use);
nf_ct_set(skb, ct, IP_CT_NEW);
}
static void nft_ct_set_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_ct *priv = nft_expr_priv(expr);
struct sk_buff *skb = pkt->skb;
#ifdef CONFIG_NF_CONNTRACK_MARK
u32 value = regs->data[priv->sreg];
#endif
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
ct = nf_ct_get(skb, &ctinfo);
if (ct == NULL || nf_ct_is_template(ct))
return;
switch (priv->key) {
#ifdef CONFIG_NF_CONNTRACK_MARK
case NFT_CT_MARK:
if (ct->mark != value) {
ct->mark = value;
nf_conntrack_event_cache(IPCT_MARK, ct);
}
break;
#endif
#ifdef CONFIG_NF_CONNTRACK_LABELS
case NFT_CT_LABELS:
nf_connlabels_replace(ct,
&regs->data[priv->sreg],
&regs->data[priv->sreg],
NF_CT_LABELS_MAX_SIZE / sizeof(u32));
break;
#endif
#ifdef CONFIG_NF_CONNTRACK_EVENTS
case NFT_CT_EVENTMASK: {
struct nf_conntrack_ecache *e = nf_ct_ecache_find(ct);
u32 ctmask = regs->data[priv->sreg];
if (e) {
if (e->ctmask != ctmask)
e->ctmask = ctmask;
break;
}
if (ctmask && !nf_ct_is_confirmed(ct))
nf_ct_ecache_ext_add(ct, ctmask, 0, GFP_ATOMIC);
break;
}
#endif
default:
break;
}
}
static int nft_ct_netns_get(struct net *net, uint8_t family)
{
int err;
if (family == NFPROTO_INET) {
err = nf_ct_netns_get(net, NFPROTO_IPV4);
if (err < 0)
goto err1;
err = nf_ct_netns_get(net, NFPROTO_IPV6);
if (err < 0)
goto err2;
} else {
err = nf_ct_netns_get(net, family);
if (err < 0)
goto err1;
}
return 0;
err2:
nf_ct_netns_put(net, NFPROTO_IPV4);
err1:
return err;
}
static void nft_ct_netns_put(struct net *net, uint8_t family)
{
if (family == NFPROTO_INET) {
nf_ct_netns_put(net, NFPROTO_IPV4);
nf_ct_netns_put(net, NFPROTO_IPV6);
} else
nf_ct_netns_put(net, family);
}
static void nft_ct_tmpl_put_pcpu(void)
{
struct nf_conn *ct;
int cpu;
for_each_possible_cpu(cpu) {
ct = per_cpu(nft_ct_pcpu_template, cpu);
if (!ct)
break;
nf_ct_put(ct);
per_cpu(nft_ct_pcpu_template, cpu) = NULL;
}
}
static bool nft_ct_tmpl_alloc_pcpu(void)
{
struct nf_conntrack_zone zone = { .id = 0 };
struct nf_conn *tmp;
int cpu;
if (nft_ct_pcpu_template_refcnt)
return true;
for_each_possible_cpu(cpu) {
tmp = nf_ct_tmpl_alloc(&init_net, &zone, GFP_KERNEL);
if (!tmp) {
nft_ct_tmpl_put_pcpu();
return false;
}
atomic_set(&tmp->ct_general.use, 1);
per_cpu(nft_ct_pcpu_template, cpu) = tmp;
}
return true;
}
static int nft_ct_get_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_ct *priv = nft_expr_priv(expr);
unsigned int len;
int err;
priv->key = ntohl(nla_get_be32(tb[NFTA_CT_KEY]));
priv->dir = IP_CT_DIR_MAX;
switch (priv->key) {
case NFT_CT_DIRECTION:
if (tb[NFTA_CT_DIRECTION] != NULL)
return -EINVAL;
len = sizeof(u8);
break;
case NFT_CT_STATE:
case NFT_CT_STATUS:
#ifdef CONFIG_NF_CONNTRACK_MARK
case NFT_CT_MARK:
#endif
#ifdef CONFIG_NF_CONNTRACK_SECMARK
case NFT_CT_SECMARK:
#endif
case NFT_CT_EXPIRATION:
if (tb[NFTA_CT_DIRECTION] != NULL)
return -EINVAL;
len = sizeof(u32);
break;
#ifdef CONFIG_NF_CONNTRACK_LABELS
case NFT_CT_LABELS:
if (tb[NFTA_CT_DIRECTION] != NULL)
return -EINVAL;
len = NF_CT_LABELS_MAX_SIZE;
break;
#endif
case NFT_CT_HELPER:
if (tb[NFTA_CT_DIRECTION] != NULL)
return -EINVAL;
len = NF_CT_HELPER_NAME_LEN;
break;
case NFT_CT_L3PROTOCOL:
case NFT_CT_PROTOCOL:
len = sizeof(u8);
break;
case NFT_CT_SRC:
case NFT_CT_DST:
if (tb[NFTA_CT_DIRECTION] == NULL)
return -EINVAL;
switch (ctx->afi->family) {
case NFPROTO_IPV4:
len = FIELD_SIZEOF(struct nf_conntrack_tuple,
src.u3.ip);
break;
case NFPROTO_IPV6:
case NFPROTO_INET:
len = FIELD_SIZEOF(struct nf_conntrack_tuple,
src.u3.ip6);
break;
default:
return -EAFNOSUPPORT;
}
break;
case NFT_CT_PROTO_SRC:
case NFT_CT_PROTO_DST:
if (tb[NFTA_CT_DIRECTION] == NULL)
return -EINVAL;
len = FIELD_SIZEOF(struct nf_conntrack_tuple, src.u.all);
break;
case NFT_CT_BYTES:
case NFT_CT_PKTS:
case NFT_CT_AVGPKT:
len = sizeof(u64);
break;
#ifdef CONFIG_NF_CONNTRACK_ZONES
case NFT_CT_ZONE:
len = sizeof(u16);
break;
#endif
default:
return -EOPNOTSUPP;
}
if (tb[NFTA_CT_DIRECTION] != NULL) {
priv->dir = nla_get_u8(tb[NFTA_CT_DIRECTION]);
switch (priv->dir) {
case IP_CT_DIR_ORIGINAL:
case IP_CT_DIR_REPLY:
break;
default:
return -EINVAL;
}
}
priv->dreg = nft_parse_register(tb[NFTA_CT_DREG]);
err = nft_validate_register_store(ctx, priv->dreg, NULL,
NFT_DATA_VALUE, len);
if (err < 0)
return err;
err = nft_ct_netns_get(ctx->net, ctx->afi->family);
if (err < 0)
return err;
if (priv->key == NFT_CT_BYTES ||
priv->key == NFT_CT_PKTS ||
priv->key == NFT_CT_AVGPKT)
nf_ct_set_acct(ctx->net, true);
return 0;
}
static void __nft_ct_set_destroy(const struct nft_ctx *ctx, struct nft_ct *priv)
{
switch (priv->key) {
#ifdef CONFIG_NF_CONNTRACK_LABELS
case NFT_CT_LABELS:
nf_connlabels_put(ctx->net);
break;
#endif
#ifdef CONFIG_NF_CONNTRACK_ZONES
case NFT_CT_ZONE:
if (--nft_ct_pcpu_template_refcnt == 0)
nft_ct_tmpl_put_pcpu();
#endif
default:
break;
}
}
static int nft_ct_set_init(const struct nft_ctx *ctx,
const struct nft_expr *expr,
const struct nlattr * const tb[])
{
struct nft_ct *priv = nft_expr_priv(expr);
unsigned int len;
int err;
priv->dir = IP_CT_DIR_MAX;
priv->key = ntohl(nla_get_be32(tb[NFTA_CT_KEY]));
switch (priv->key) {
#ifdef CONFIG_NF_CONNTRACK_MARK
case NFT_CT_MARK:
if (tb[NFTA_CT_DIRECTION])
return -EINVAL;
len = FIELD_SIZEOF(struct nf_conn, mark);
break;
#endif
#ifdef CONFIG_NF_CONNTRACK_LABELS
case NFT_CT_LABELS:
if (tb[NFTA_CT_DIRECTION])
return -EINVAL;
len = NF_CT_LABELS_MAX_SIZE;
err = nf_connlabels_get(ctx->net, (len * BITS_PER_BYTE) - 1);
if (err)
return err;
break;
#endif
#ifdef CONFIG_NF_CONNTRACK_ZONES
case NFT_CT_ZONE:
if (!nft_ct_tmpl_alloc_pcpu())
return -ENOMEM;
nft_ct_pcpu_template_refcnt++;
len = sizeof(u16);
break;
#endif
#ifdef CONFIG_NF_CONNTRACK_EVENTS
case NFT_CT_EVENTMASK:
if (tb[NFTA_CT_DIRECTION])
return -EINVAL;
len = sizeof(u32);
break;
#endif
default:
return -EOPNOTSUPP;
}
if (tb[NFTA_CT_DIRECTION]) {
priv->dir = nla_get_u8(tb[NFTA_CT_DIRECTION]);
switch (priv->dir) {
case IP_CT_DIR_ORIGINAL:
case IP_CT_DIR_REPLY:
break;
default:
err = -EINVAL;
goto err1;
}
}
priv->sreg = nft_parse_register(tb[NFTA_CT_SREG]);
err = nft_validate_register_load(priv->sreg, len);
if (err < 0)
goto err1;
err = nft_ct_netns_get(ctx->net, ctx->afi->family);
if (err < 0)
goto err1;
return 0;
err1:
__nft_ct_set_destroy(ctx, priv);
return err;
}
static void nft_ct_get_destroy(const struct nft_ctx *ctx,
const struct nft_expr *expr)
{
nf_ct_netns_put(ctx->net, ctx->afi->family);
}
static void nft_ct_set_destroy(const struct nft_ctx *ctx,
const struct nft_expr *expr)
{
struct nft_ct *priv = nft_expr_priv(expr);
__nft_ct_set_destroy(ctx, priv);
nft_ct_netns_put(ctx->net, ctx->afi->family);
}
static int nft_ct_get_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_ct *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_CT_DREG, priv->dreg))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_CT_KEY, htonl(priv->key)))
goto nla_put_failure;
switch (priv->key) {
case NFT_CT_SRC:
case NFT_CT_DST:
case NFT_CT_PROTO_SRC:
case NFT_CT_PROTO_DST:
if (nla_put_u8(skb, NFTA_CT_DIRECTION, priv->dir))
goto nla_put_failure;
break;
case NFT_CT_BYTES:
case NFT_CT_PKTS:
case NFT_CT_AVGPKT:
case NFT_CT_ZONE:
if (priv->dir < IP_CT_DIR_MAX &&
nla_put_u8(skb, NFTA_CT_DIRECTION, priv->dir))
goto nla_put_failure;
break;
default:
break;
}
return 0;
nla_put_failure:
return -1;
}
static int nft_ct_set_dump(struct sk_buff *skb, const struct nft_expr *expr)
{
const struct nft_ct *priv = nft_expr_priv(expr);
if (nft_dump_register(skb, NFTA_CT_SREG, priv->sreg))
goto nla_put_failure;
if (nla_put_be32(skb, NFTA_CT_KEY, htonl(priv->key)))
goto nla_put_failure;
switch (priv->key) {
case NFT_CT_ZONE:
if (priv->dir < IP_CT_DIR_MAX &&
nla_put_u8(skb, NFTA_CT_DIRECTION, priv->dir))
goto nla_put_failure;
break;
default:
break;
}
return 0;
nla_put_failure:
return -1;
}
static const struct nft_expr_ops *
nft_ct_select_ops(const struct nft_ctx *ctx,
const struct nlattr * const tb[])
{
if (tb[NFTA_CT_KEY] == NULL)
return ERR_PTR(-EINVAL);
if (tb[NFTA_CT_DREG] && tb[NFTA_CT_SREG])
return ERR_PTR(-EINVAL);
if (tb[NFTA_CT_DREG])
return &nft_ct_get_ops;
if (tb[NFTA_CT_SREG]) {
#ifdef CONFIG_NF_CONNTRACK_ZONES
if (nla_get_be32(tb[NFTA_CT_KEY]) == htonl(NFT_CT_ZONE))
return &nft_ct_set_zone_ops;
#endif
return &nft_ct_set_ops;
}
return ERR_PTR(-EINVAL);
}
static void nft_notrack_eval(const struct nft_expr *expr,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
struct sk_buff *skb = pkt->skb;
enum ip_conntrack_info ctinfo;
struct nf_conn *ct;
ct = nf_ct_get(pkt->skb, &ctinfo);
if (ct || ctinfo == IP_CT_UNTRACKED)
return;
nf_ct_set(skb, ct, IP_CT_UNTRACKED);
}
static int nft_ct_helper_obj_init(const struct nft_ctx *ctx,
const struct nlattr * const tb[],
struct nft_object *obj)
{
struct nft_ct_helper_obj *priv = nft_obj_data(obj);
struct nf_conntrack_helper *help4, *help6;
char name[NF_CT_HELPER_NAME_LEN];
int family = ctx->afi->family;
if (!tb[NFTA_CT_HELPER_NAME] || !tb[NFTA_CT_HELPER_L4PROTO])
return -EINVAL;
priv->l4proto = nla_get_u8(tb[NFTA_CT_HELPER_L4PROTO]);
if (!priv->l4proto)
return -ENOENT;
nla_strlcpy(name, tb[NFTA_CT_HELPER_NAME], sizeof(name));
if (tb[NFTA_CT_HELPER_L3PROTO])
family = ntohs(nla_get_be16(tb[NFTA_CT_HELPER_L3PROTO]));
help4 = NULL;
help6 = NULL;
switch (family) {
case NFPROTO_IPV4:
if (ctx->afi->family == NFPROTO_IPV6)
return -EINVAL;
help4 = nf_conntrack_helper_try_module_get(name, family,
priv->l4proto);
break;
case NFPROTO_IPV6:
if (ctx->afi->family == NFPROTO_IPV4)
return -EINVAL;
help6 = nf_conntrack_helper_try_module_get(name, family,
priv->l4proto);
break;
case NFPROTO_NETDEV:
case NFPROTO_BRIDGE:
case NFPROTO_INET:
help4 = nf_conntrack_helper_try_module_get(name, NFPROTO_IPV4,
priv->l4proto);
help6 = nf_conntrack_helper_try_module_get(name, NFPROTO_IPV6,
priv->l4proto);
break;
default:
return -EAFNOSUPPORT;
}
if (!help4 && !help6)
return -ENOENT;
priv->helper4 = help4;
priv->helper6 = help6;
return 0;
}
static void nft_ct_helper_obj_destroy(struct nft_object *obj)
{
struct nft_ct_helper_obj *priv = nft_obj_data(obj);
if (priv->helper4)
nf_conntrack_helper_put(priv->helper4);
if (priv->helper6)
nf_conntrack_helper_put(priv->helper6);
}
static void nft_ct_helper_obj_eval(struct nft_object *obj,
struct nft_regs *regs,
const struct nft_pktinfo *pkt)
{
const struct nft_ct_helper_obj *priv = nft_obj_data(obj);
struct nf_conn *ct = (struct nf_conn *)skb_nfct(pkt->skb);
struct nf_conntrack_helper *to_assign = NULL;
struct nf_conn_help *help;
if (!ct ||
nf_ct_is_confirmed(ct) ||
nf_ct_is_template(ct) ||
priv->l4proto != nf_ct_protonum(ct))
return;
switch (nf_ct_l3num(ct)) {
case NFPROTO_IPV4:
to_assign = priv->helper4;
break;
case NFPROTO_IPV6:
to_assign = priv->helper6;
break;
default:
WARN_ON_ONCE(1);
return;
}
if (!to_assign)
return;
if (test_bit(IPS_HELPER_BIT, &ct->status))
return;
help = nf_ct_helper_ext_add(ct, to_assign, GFP_ATOMIC);
if (help) {
rcu_assign_pointer(help->helper, to_assign);
set_bit(IPS_HELPER_BIT, &ct->status);
}
}
static int nft_ct_helper_obj_dump(struct sk_buff *skb,
struct nft_object *obj, bool reset)
{
const struct nft_ct_helper_obj *priv = nft_obj_data(obj);
const struct nf_conntrack_helper *helper = priv->helper4;
u16 family;
if (nla_put_string(skb, NFTA_CT_HELPER_NAME, helper->name))
return -1;
if (nla_put_u8(skb, NFTA_CT_HELPER_L4PROTO, priv->l4proto))
return -1;
if (priv->helper4 && priv->helper6)
family = NFPROTO_INET;
else if (priv->helper6)
family = NFPROTO_IPV6;
else
family = NFPROTO_IPV4;
if (nla_put_be16(skb, NFTA_CT_HELPER_L3PROTO, htons(family)))
return -1;
return 0;
}
static int __init nft_ct_module_init(void)
{
int err;
BUILD_BUG_ON(NF_CT_LABELS_MAX_SIZE > NFT_REG_SIZE);
err = nft_register_expr(&nft_ct_type);
if (err < 0)
return err;
err = nft_register_expr(&nft_notrack_type);
if (err < 0)
goto err1;
err = nft_register_obj(&nft_ct_helper_obj);
if (err < 0)
goto err2;
return 0;
err2:
nft_unregister_expr(&nft_notrack_type);
err1:
nft_unregister_expr(&nft_ct_type);
return err;
}
static void __exit nft_ct_module_exit(void)
{
nft_unregister_obj(&nft_ct_helper_obj);
nft_unregister_expr(&nft_notrack_type);
nft_unregister_expr(&nft_ct_type);
}
