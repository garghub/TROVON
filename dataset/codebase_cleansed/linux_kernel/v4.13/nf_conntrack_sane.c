static int help(struct sk_buff *skb,
unsigned int protoff,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo)
{
unsigned int dataoff, datalen;
const struct tcphdr *th;
struct tcphdr _tcph;
void *sb_ptr;
int ret = NF_ACCEPT;
int dir = CTINFO2DIR(ctinfo);
struct nf_ct_sane_master *ct_sane_info = nfct_help_data(ct);
struct nf_conntrack_expect *exp;
struct nf_conntrack_tuple *tuple;
struct sane_request *req;
struct sane_reply_net_start *reply;
if (ctinfo != IP_CT_ESTABLISHED &&
ctinfo != IP_CT_ESTABLISHED_REPLY)
return NF_ACCEPT;
th = skb_header_pointer(skb, protoff, sizeof(_tcph), &_tcph);
if (th == NULL)
return NF_ACCEPT;
dataoff = protoff + th->doff * 4;
if (dataoff >= skb->len)
return NF_ACCEPT;
datalen = skb->len - dataoff;
spin_lock_bh(&nf_sane_lock);
sb_ptr = skb_header_pointer(skb, dataoff, datalen, sane_buffer);
BUG_ON(sb_ptr == NULL);
if (dir == IP_CT_DIR_ORIGINAL) {
if (datalen != sizeof(struct sane_request))
goto out;
req = sb_ptr;
if (req->RPC_code != htonl(SANE_NET_START)) {
ct_sane_info->state = SANE_STATE_NORMAL;
goto out;
}
ct_sane_info->state = SANE_STATE_START_REQUESTED;
goto out;
}
if (ct_sane_info->state != SANE_STATE_START_REQUESTED)
goto out;
ct_sane_info->state = SANE_STATE_NORMAL;
if (datalen < sizeof(struct sane_reply_net_start)) {
pr_debug("NET_START reply too short\n");
goto out;
}
reply = sb_ptr;
if (reply->status != htonl(SANE_STATUS_SUCCESS)) {
pr_debug("unsuccessful SANE_STATUS = %u\n",
ntohl(reply->status));
goto out;
}
if (reply->zero != 0)
goto out;
exp = nf_ct_expect_alloc(ct);
if (exp == NULL) {
nf_ct_helper_log(skb, ct, "cannot alloc expectation");
ret = NF_DROP;
goto out;
}
tuple = &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&tuple->src.u3, &tuple->dst.u3,
IPPROTO_TCP, NULL, &reply->port);
pr_debug("expect: ");
nf_ct_dump_tuple(&exp->tuple);
if (nf_ct_expect_related(exp) != 0) {
nf_ct_helper_log(skb, ct, "cannot add expectation");
ret = NF_DROP;
}
nf_ct_expect_put(exp);
out:
spin_unlock_bh(&nf_sane_lock);
return ret;
}
static void nf_conntrack_sane_fini(void)
{
nf_conntrack_helpers_unregister(sane, ports_c * 2);
kfree(sane_buffer);
}
static int __init nf_conntrack_sane_init(void)
{
int i, ret = 0;
NF_CT_HELPER_BUILD_BUG_ON(sizeof(struct nf_ct_sane_master));
sane_buffer = kmalloc(65536, GFP_KERNEL);
if (!sane_buffer)
return -ENOMEM;
if (ports_c == 0)
ports[ports_c++] = SANE_PORT;
for (i = 0; i < ports_c; i++) {
nf_ct_helper_init(&sane[2 * i], AF_INET, IPPROTO_TCP, "sane",
SANE_PORT, ports[i], ports[i],
&sane_exp_policy, 0, help, NULL,
THIS_MODULE);
nf_ct_helper_init(&sane[2 * i + 1], AF_INET6, IPPROTO_TCP, "sane",
SANE_PORT, ports[i], ports[i],
&sane_exp_policy, 0, help, NULL,
THIS_MODULE);
}
ret = nf_conntrack_helpers_register(sane, ports_c * 2);
if (ret < 0) {
pr_err("failed to register helpers\n");
kfree(sane_buffer);
return ret;
}
return 0;
}
