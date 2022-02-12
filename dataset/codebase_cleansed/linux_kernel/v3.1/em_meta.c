static inline int meta_id(struct meta_value *v)
{
return TCF_META_ID(v->hdr.kind);
}
static inline int meta_type(struct meta_value *v)
{
return TCF_META_TYPE(v->hdr.kind);
}
static inline unsigned long fixed_loadavg(int load)
{
int rnd_load = load + (FIXED_1/200);
int rnd_frac = ((rnd_load & (FIXED_1-1)) * 100) >> FSHIFT;
return ((rnd_load >> FSHIFT) * 100) + rnd_frac;
}
static inline int int_dev(struct net_device *dev, struct meta_obj *dst)
{
if (unlikely(dev == NULL))
return -1;
dst->value = dev->ifindex;
return 0;
}
static inline int var_dev(struct net_device *dev, struct meta_obj *dst)
{
if (unlikely(dev == NULL))
return -1;
dst->value = (unsigned long) dev->name;
dst->len = strlen(dev->name);
return 0;
}
static inline struct meta_ops *meta_ops(struct meta_value *val)
{
return &__meta_ops[meta_type(val)][meta_id(val)];
}
static int meta_var_compare(struct meta_obj *a, struct meta_obj *b)
{
int r = a->len - b->len;
if (r == 0)
r = memcmp((void *) a->value, (void *) b->value, a->len);
return r;
}
static int meta_var_change(struct meta_value *dst, struct nlattr *nla)
{
int len = nla_len(nla);
dst->val = (unsigned long)kmemdup(nla_data(nla), len, GFP_KERNEL);
if (dst->val == 0UL)
return -ENOMEM;
dst->len = len;
return 0;
}
static void meta_var_destroy(struct meta_value *v)
{
kfree((void *) v->val);
}
static void meta_var_apply_extras(struct meta_value *v,
struct meta_obj *dst)
{
int shift = v->hdr.shift;
if (shift && shift < dst->len)
dst->len -= shift;
}
static int meta_var_dump(struct sk_buff *skb, struct meta_value *v, int tlv)
{
if (v->val && v->len)
NLA_PUT(skb, tlv, v->len, (void *) v->val);
return 0;
nla_put_failure:
return -1;
}
static int meta_int_compare(struct meta_obj *a, struct meta_obj *b)
{
if (unlikely(a->value == b->value))
return 0;
else if (a->value < b->value)
return -1;
else
return 1;
}
static int meta_int_change(struct meta_value *dst, struct nlattr *nla)
{
if (nla_len(nla) >= sizeof(unsigned long)) {
dst->val = *(unsigned long *) nla_data(nla);
dst->len = sizeof(unsigned long);
} else if (nla_len(nla) == sizeof(u32)) {
dst->val = nla_get_u32(nla);
dst->len = sizeof(u32);
} else
return -EINVAL;
return 0;
}
static void meta_int_apply_extras(struct meta_value *v,
struct meta_obj *dst)
{
if (v->hdr.shift)
dst->value >>= v->hdr.shift;
if (v->val)
dst->value &= v->val;
}
static int meta_int_dump(struct sk_buff *skb, struct meta_value *v, int tlv)
{
if (v->len == sizeof(unsigned long))
NLA_PUT(skb, tlv, sizeof(unsigned long), &v->val);
else if (v->len == sizeof(u32))
NLA_PUT_U32(skb, tlv, v->val);
return 0;
nla_put_failure:
return -1;
}
static inline struct meta_type_ops *meta_type_ops(struct meta_value *v)
{
return &__meta_type_ops[meta_type(v)];
}
static int meta_get(struct sk_buff *skb, struct tcf_pkt_info *info,
struct meta_value *v, struct meta_obj *dst)
{
int err = 0;
if (meta_id(v) == TCF_META_ID_VALUE) {
dst->value = v->val;
dst->len = v->len;
return 0;
}
meta_ops(v)->get(skb, info, v, dst, &err);
if (err < 0)
return err;
if (meta_type_ops(v)->apply_extras)
meta_type_ops(v)->apply_extras(v, dst);
return 0;
}
static int em_meta_match(struct sk_buff *skb, struct tcf_ematch *m,
struct tcf_pkt_info *info)
{
int r;
struct meta_match *meta = (struct meta_match *) m->data;
struct meta_obj l_value, r_value;
if (meta_get(skb, info, &meta->lvalue, &l_value) < 0 ||
meta_get(skb, info, &meta->rvalue, &r_value) < 0)
return 0;
r = meta_type_ops(&meta->lvalue)->compare(&l_value, &r_value);
switch (meta->lvalue.hdr.op) {
case TCF_EM_OPND_EQ:
return !r;
case TCF_EM_OPND_LT:
return r < 0;
case TCF_EM_OPND_GT:
return r > 0;
}
return 0;
}
static void meta_delete(struct meta_match *meta)
{
if (meta) {
struct meta_type_ops *ops = meta_type_ops(&meta->lvalue);
if (ops && ops->destroy) {
ops->destroy(&meta->lvalue);
ops->destroy(&meta->rvalue);
}
}
kfree(meta);
}
static inline int meta_change_data(struct meta_value *dst, struct nlattr *nla)
{
if (nla) {
if (nla_len(nla) == 0)
return -EINVAL;
return meta_type_ops(dst)->change(dst, nla);
}
return 0;
}
static inline int meta_is_supported(struct meta_value *val)
{
return !meta_id(val) || meta_ops(val)->get;
}
static int em_meta_change(struct tcf_proto *tp, void *data, int len,
struct tcf_ematch *m)
{
int err;
struct nlattr *tb[TCA_EM_META_MAX + 1];
struct tcf_meta_hdr *hdr;
struct meta_match *meta = NULL;
err = nla_parse(tb, TCA_EM_META_MAX, data, len, meta_policy);
if (err < 0)
goto errout;
err = -EINVAL;
if (tb[TCA_EM_META_HDR] == NULL)
goto errout;
hdr = nla_data(tb[TCA_EM_META_HDR]);
if (TCF_META_TYPE(hdr->left.kind) != TCF_META_TYPE(hdr->right.kind) ||
TCF_META_TYPE(hdr->left.kind) > TCF_META_TYPE_MAX ||
TCF_META_ID(hdr->left.kind) > TCF_META_ID_MAX ||
TCF_META_ID(hdr->right.kind) > TCF_META_ID_MAX)
goto errout;
meta = kzalloc(sizeof(*meta), GFP_KERNEL);
if (meta == NULL)
goto errout;
memcpy(&meta->lvalue.hdr, &hdr->left, sizeof(hdr->left));
memcpy(&meta->rvalue.hdr, &hdr->right, sizeof(hdr->right));
if (!meta_is_supported(&meta->lvalue) ||
!meta_is_supported(&meta->rvalue)) {
err = -EOPNOTSUPP;
goto errout;
}
if (meta_change_data(&meta->lvalue, tb[TCA_EM_META_LVALUE]) < 0 ||
meta_change_data(&meta->rvalue, tb[TCA_EM_META_RVALUE]) < 0)
goto errout;
m->datalen = sizeof(*meta);
m->data = (unsigned long) meta;
err = 0;
errout:
if (err && meta)
meta_delete(meta);
return err;
}
static void em_meta_destroy(struct tcf_proto *tp, struct tcf_ematch *m)
{
if (m)
meta_delete((struct meta_match *) m->data);
}
static int em_meta_dump(struct sk_buff *skb, struct tcf_ematch *em)
{
struct meta_match *meta = (struct meta_match *) em->data;
struct tcf_meta_hdr hdr;
struct meta_type_ops *ops;
memset(&hdr, 0, sizeof(hdr));
memcpy(&hdr.left, &meta->lvalue.hdr, sizeof(hdr.left));
memcpy(&hdr.right, &meta->rvalue.hdr, sizeof(hdr.right));
NLA_PUT(skb, TCA_EM_META_HDR, sizeof(hdr), &hdr);
ops = meta_type_ops(&meta->lvalue);
if (ops->dump(skb, &meta->lvalue, TCA_EM_META_LVALUE) < 0 ||
ops->dump(skb, &meta->rvalue, TCA_EM_META_RVALUE) < 0)
goto nla_put_failure;
return 0;
nla_put_failure:
return -1;
}
static int __init init_em_meta(void)
{
return tcf_em_register(&em_meta_ops);
}
static void __exit exit_em_meta(void)
{
tcf_em_unregister(&em_meta_ops);
}
