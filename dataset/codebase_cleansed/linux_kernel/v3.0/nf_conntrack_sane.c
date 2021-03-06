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
struct nf_ct_sane_master *ct_sane_info;
struct nf_conntrack_expect *exp;
struct nf_conntrack_tuple *tuple;
struct sane_request *req;
struct sane_reply_net_start *reply;
ct_sane_info = &nfct_help(ct)->help.ct_sane_info;
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
pr_debug("nf_ct_sane: NET_START reply too short\n");
goto out;
}
reply = sb_ptr;
if (reply->status != htonl(SANE_STATUS_SUCCESS)) {
pr_debug("nf_ct_sane: unsuccessful SANE_STATUS = %u\n",
ntohl(reply->status));
goto out;
}
if (reply->zero != 0)
goto out;
exp = nf_ct_expect_alloc(ct);
if (exp == NULL) {
ret = NF_DROP;
goto out;
}
tuple = &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
&tuple->src.u3, &tuple->dst.u3,
IPPROTO_TCP, NULL, &reply->port);
pr_debug("nf_ct_sane: expect: ");
nf_ct_dump_tuple(&exp->tuple);
if (nf_ct_expect_related(exp) != 0)
ret = NF_DROP;
nf_ct_expect_put(exp);
out:
spin_unlock_bh(&nf_sane_lock);
return ret;
}
static void nf_conntrack_sane_fini(void)
{
int i, j;
for (i = 0; i < ports_c; i++) {
for (j = 0; j < 2; j++) {
pr_debug("nf_ct_sane: unregistering helper for pf: %d "
"port: %d\n",
sane[i][j].tuple.src.l3num, ports[i]);
nf_conntrack_helper_unregister(&sane[i][j]);
}
}
kfree(sane_buffer);
}
static int __init nf_conntrack_sane_init(void)
{
int i, j = -1, ret = 0;
char *tmpname;
sane_buffer = kmalloc(65536, GFP_KERNEL);
if (!sane_buffer)
return -ENOMEM;
if (ports_c == 0)
ports[ports_c++] = SANE_PORT;
for (i = 0; i < ports_c; i++) {
sane[i][0].tuple.src.l3num = PF_INET;
sane[i][1].tuple.src.l3num = PF_INET6;
for (j = 0; j < 2; j++) {
sane[i][j].tuple.src.u.tcp.port = htons(ports[i]);
sane[i][j].tuple.dst.protonum = IPPROTO_TCP;
sane[i][j].expect_policy = &sane_exp_policy;
sane[i][j].me = THIS_MODULE;
sane[i][j].help = help;
tmpname = &sane_names[i][j][0];
if (ports[i] == SANE_PORT)
sprintf(tmpname, "sane");
else
sprintf(tmpname, "sane-%d", ports[i]);
sane[i][j].name = tmpname;
pr_debug("nf_ct_sane: registering helper for pf: %d "
"port: %d\n",
sane[i][j].tuple.src.l3num, ports[i]);
ret = nf_conntrack_helper_register(&sane[i][j]);
if (ret) {
printk(KERN_ERR "nf_ct_sane: failed to "
"register helper for pf: %d port: %d\n",
sane[i][j].tuple.src.l3num, ports[i]);
nf_conntrack_sane_fini();
return ret;
}
}
}
return 0;
}
