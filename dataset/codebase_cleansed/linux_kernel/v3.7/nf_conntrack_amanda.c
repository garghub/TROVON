static int amanda_help(struct sk_buff *skb,
unsigned int protoff,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo)
{
struct ts_state ts;
struct nf_conntrack_expect *exp;
struct nf_conntrack_tuple *tuple;
unsigned int dataoff, start, stop, off, i;
char pbuf[sizeof("65535")], *tmp;
u_int16_t len;
__be16 port;
int ret = NF_ACCEPT;
typeof(nf_nat_amanda_hook) nf_nat_amanda;
if (CTINFO2DIR(ctinfo) == IP_CT_DIR_ORIGINAL)
return NF_ACCEPT;
nf_ct_refresh(ct, skb, master_timeout * HZ);
dataoff = protoff + sizeof(struct udphdr);
if (dataoff >= skb->len) {
net_err_ratelimited("amanda_help: skblen = %u\n", skb->len);
return NF_ACCEPT;
}
memset(&ts, 0, sizeof(ts));
start = skb_find_text(skb, dataoff, skb->len,
search[SEARCH_CONNECT].ts, &ts);
if (start == UINT_MAX)
goto out;
start += dataoff + search[SEARCH_CONNECT].len;
memset(&ts, 0, sizeof(ts));
stop = skb_find_text(skb, start, skb->len,
search[SEARCH_NEWLINE].ts, &ts);
if (stop == UINT_MAX)
goto out;
stop += start;
for (i = SEARCH_DATA; i <= SEARCH_INDEX; i++) {
memset(&ts, 0, sizeof(ts));
off = skb_find_text(skb, start, stop, search[i].ts, &ts);
if (off == UINT_MAX)
continue;
off += start + search[i].len;
len = min_t(unsigned int, sizeof(pbuf) - 1, stop - off);
if (skb_copy_bits(skb, off, pbuf, len))
break;
pbuf[len] = '\0';
port = htons(simple_strtoul(pbuf, &tmp, 10));
len = tmp - pbuf;
if (port == 0 || len > 5)
break;
exp = nf_ct_expect_alloc(ct);
if (exp == NULL) {
ret = NF_DROP;
goto out;
}
tuple = &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT,
nf_ct_l3num(ct),
&tuple->src.u3, &tuple->dst.u3,
IPPROTO_TCP, NULL, &port);
nf_nat_amanda = rcu_dereference(nf_nat_amanda_hook);
if (nf_nat_amanda && ct->status & IPS_NAT_MASK)
ret = nf_nat_amanda(skb, ctinfo, protoff,
off - dataoff, len, exp);
else if (nf_ct_expect_related(exp) != 0)
ret = NF_DROP;
nf_ct_expect_put(exp);
}
out:
return ret;
}
static void __exit nf_conntrack_amanda_fini(void)
{
int i;
nf_conntrack_helper_unregister(&amanda_helper[0]);
nf_conntrack_helper_unregister(&amanda_helper[1]);
for (i = 0; i < ARRAY_SIZE(search); i++)
textsearch_destroy(search[i].ts);
}
static int __init nf_conntrack_amanda_init(void)
{
int ret, i;
for (i = 0; i < ARRAY_SIZE(search); i++) {
search[i].ts = textsearch_prepare(ts_algo, search[i].string,
search[i].len,
GFP_KERNEL, TS_AUTOLOAD);
if (IS_ERR(search[i].ts)) {
ret = PTR_ERR(search[i].ts);
goto err1;
}
}
ret = nf_conntrack_helper_register(&amanda_helper[0]);
if (ret < 0)
goto err1;
ret = nf_conntrack_helper_register(&amanda_helper[1]);
if (ret < 0)
goto err2;
return 0;
err2:
nf_conntrack_helper_unregister(&amanda_helper[0]);
err1:
while (--i >= 0)
textsearch_destroy(search[i].ts);
return ret;
}
