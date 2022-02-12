void
ip_vs_update_conntrack(struct sk_buff *skb, struct ip_vs_conn *cp, int outin)
{
enum ip_conntrack_info ctinfo;
struct nf_conn *ct = nf_ct_get(skb, &ctinfo);
struct nf_conntrack_tuple new_tuple;
if (ct == NULL || nf_ct_is_confirmed(ct) ||
nf_ct_is_dying(ct))
return;
if (IP_VS_FWD_METHOD(cp) != IP_VS_CONN_F_MASQ)
return;
if (cp->flags & IP_VS_CONN_F_ONE_PACKET)
return;
if (CTINFO2DIR(ctinfo) != IP_CT_DIR_ORIGINAL)
return;
if (cp->app && nf_ct_protonum(ct) == IPPROTO_TCP &&
!nfct_seqadj(ct) && !nfct_seqadj_ext_add(ct))
return;
new_tuple = ct->tuplehash[IP_CT_DIR_REPLY].tuple;
if (outin) {
new_tuple.src.u3 = cp->daddr;
if (new_tuple.dst.protonum != IPPROTO_ICMP &&
new_tuple.dst.protonum != IPPROTO_ICMPV6)
new_tuple.src.u.tcp.port = cp->dport;
} else {
new_tuple.dst.u3 = cp->vaddr;
if (new_tuple.dst.protonum != IPPROTO_ICMP &&
new_tuple.dst.protonum != IPPROTO_ICMPV6)
new_tuple.dst.u.tcp.port = cp->vport;
}
IP_VS_DBG(7, "%s: Updating conntrack ct=%p, status=0x%lX, "
"ctinfo=%d, old reply=" FMT_TUPLE
", new reply=" FMT_TUPLE ", cp=" FMT_CONN "\n",
__func__, ct, ct->status, ctinfo,
ARG_TUPLE(&ct->tuplehash[IP_CT_DIR_REPLY].tuple),
ARG_TUPLE(&new_tuple), ARG_CONN(cp));
nf_conntrack_alter_reply(ct, &new_tuple);
}
int ip_vs_confirm_conntrack(struct sk_buff *skb)
{
return nf_conntrack_confirm(skb);
}
static void ip_vs_nfct_expect_callback(struct nf_conn *ct,
struct nf_conntrack_expect *exp)
{
struct nf_conntrack_tuple *orig, new_reply;
struct ip_vs_conn *cp;
struct ip_vs_conn_param p;
struct net *net = nf_ct_net(ct);
if (exp->tuple.src.l3num != PF_INET)
return;
orig = &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple;
ip_vs_conn_fill_param(net_ipvs(net), exp->tuple.src.l3num, orig->dst.protonum,
&orig->src.u3, orig->src.u.tcp.port,
&orig->dst.u3, orig->dst.u.tcp.port, &p);
cp = ip_vs_conn_out_get(&p);
if (cp) {
new_reply = ct->tuplehash[IP_CT_DIR_REPLY].tuple;
IP_VS_DBG(7, "%s: ct=%p, status=0x%lX, tuples=" FMT_TUPLE ", "
FMT_TUPLE ", found inout cp=" FMT_CONN "\n",
__func__, ct, ct->status,
ARG_TUPLE(orig), ARG_TUPLE(&new_reply),
ARG_CONN(cp));
new_reply.dst.u3 = cp->vaddr;
new_reply.dst.u.tcp.port = cp->vport;
IP_VS_DBG(7, "%s: ct=%p, new tuples=" FMT_TUPLE ", " FMT_TUPLE
", inout cp=" FMT_CONN "\n",
__func__, ct,
ARG_TUPLE(orig), ARG_TUPLE(&new_reply),
ARG_CONN(cp));
goto alter;
}
cp = ip_vs_conn_in_get(&p);
if (cp) {
new_reply = ct->tuplehash[IP_CT_DIR_REPLY].tuple;
IP_VS_DBG(7, "%s: ct=%p, status=0x%lX, tuples=" FMT_TUPLE ", "
FMT_TUPLE ", found outin cp=" FMT_CONN "\n",
__func__, ct, ct->status,
ARG_TUPLE(orig), ARG_TUPLE(&new_reply),
ARG_CONN(cp));
new_reply.src.u3 = cp->daddr;
new_reply.src.u.tcp.port = cp->dport;
IP_VS_DBG(7, "%s: ct=%p, new tuples=" FMT_TUPLE ", "
FMT_TUPLE ", outin cp=" FMT_CONN "\n",
__func__, ct,
ARG_TUPLE(orig), ARG_TUPLE(&new_reply),
ARG_CONN(cp));
goto alter;
}
IP_VS_DBG(7, "%s: ct=%p, status=0x%lX, tuple=" FMT_TUPLE
" - unknown expect\n",
__func__, ct, ct->status, ARG_TUPLE(orig));
return;
alter:
if (IP_VS_FWD_METHOD(cp) == IP_VS_CONN_F_MASQ)
nf_conntrack_alter_reply(ct, &new_reply);
ip_vs_conn_put(cp);
return;
}
void ip_vs_nfct_expect_related(struct sk_buff *skb, struct nf_conn *ct,
struct ip_vs_conn *cp, u_int8_t proto,
const __be16 port, int from_rs)
{
struct nf_conntrack_expect *exp;
if (ct == NULL)
return;
exp = nf_ct_expect_alloc(ct);
if (!exp)
return;
nf_ct_expect_init(exp, NF_CT_EXPECT_CLASS_DEFAULT, nf_ct_l3num(ct),
from_rs ? &cp->daddr : &cp->caddr,
from_rs ? &cp->caddr : &cp->vaddr,
proto, port ? &port : NULL,
from_rs ? &cp->cport : &cp->vport);
exp->expectfn = ip_vs_nfct_expect_callback;
IP_VS_DBG(7, "%s: ct=%p, expect tuple=" FMT_TUPLE "\n",
__func__, ct, ARG_TUPLE(&exp->tuple));
nf_ct_expect_related(exp);
nf_ct_expect_put(exp);
}
void ip_vs_conn_drop_conntrack(struct ip_vs_conn *cp)
{
struct nf_conntrack_tuple_hash *h;
struct nf_conn *ct;
struct nf_conntrack_tuple tuple;
if (!cp->cport)
return;
tuple = (struct nf_conntrack_tuple) {
.dst = { .protonum = cp->protocol, .dir = IP_CT_DIR_ORIGINAL } };
tuple.src.u3 = cp->caddr;
tuple.src.u.all = cp->cport;
tuple.src.l3num = cp->af;
tuple.dst.u3 = cp->vaddr;
tuple.dst.u.all = cp->vport;
IP_VS_DBG(7, "%s: dropping conntrack with tuple=" FMT_TUPLE
" for conn " FMT_CONN "\n",
__func__, ARG_TUPLE(&tuple), ARG_CONN(cp));
h = nf_conntrack_find_get(cp->ipvs->net, &nf_ct_zone_dflt, &tuple);
if (h) {
ct = nf_ct_tuplehash_to_ctrack(h);
if (nf_ct_kill(ct)) {
IP_VS_DBG(7, "%s: ct=%p, deleted conntrack for tuple="
FMT_TUPLE "\n",
__func__, ct, ARG_TUPLE(&tuple));
} else {
IP_VS_DBG(7, "%s: ct=%p, no conntrack timer for tuple="
FMT_TUPLE "\n",
__func__, ct, ARG_TUPLE(&tuple));
}
nf_ct_put(ct);
} else {
IP_VS_DBG(7, "%s: no conntrack for tuple=" FMT_TUPLE "\n",
__func__, ARG_TUPLE(&tuple));
}
}
