static bool u32_match_it(const struct xt_u32 *data,
const struct sk_buff *skb)
{
const struct xt_u32_test *ct;
unsigned int testind;
unsigned int nnums;
unsigned int nvals;
unsigned int i;
__be32 n;
u_int32_t pos;
u_int32_t val;
u_int32_t at;
for (testind = 0; testind < data->ntests; ++testind) {
ct = &data->tests[testind];
at = 0;
pos = ct->location[0].number;
if (skb->len < 4 || pos > skb->len - 4)
return false;
if (skb_copy_bits(skb, pos, &n, sizeof(n)) < 0)
BUG();
val = ntohl(n);
nnums = ct->nnums;
for (i = 1; i < nnums; ++i) {
u_int32_t number = ct->location[i].number;
switch (ct->location[i].nextop) {
case XT_U32_AND:
val &= number;
break;
case XT_U32_LEFTSH:
val <<= number;
break;
case XT_U32_RIGHTSH:
val >>= number;
break;
case XT_U32_AT:
if (at + val < at)
return false;
at += val;
pos = number;
if (at + 4 < at || skb->len < at + 4 ||
pos > skb->len - at - 4)
return false;
if (skb_copy_bits(skb, at + pos, &n,
sizeof(n)) < 0)
BUG();
val = ntohl(n);
break;
}
}
nvals = ct->nvalues;
for (i = 0; i < nvals; ++i)
if (ct->value[i].min <= val && val <= ct->value[i].max)
break;
if (i >= ct->nvalues)
return false;
}
return true;
}
static bool u32_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_u32 *data = par->matchinfo;
bool ret;
ret = u32_match_it(data, skb);
return ret ^ data->invert;
}
static int __init u32_mt_init(void)
{
return xt_register_match(&xt_u32_mt_reg);
}
static void __exit u32_mt_exit(void)
{
xt_unregister_match(&xt_u32_mt_reg);
}
