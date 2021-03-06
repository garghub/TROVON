static void pptp_expectfn(struct nf_conn *ct,
struct nf_conntrack_expect *exp)
{
struct net *net = nf_ct_net(ct);
typeof(nf_nat_pptp_hook_expectfn) nf_nat_pptp_expectfn;
pr_debug("increasing timeouts\n");
ct->proto.gre.timeout = PPTP_GRE_TIMEOUT;
ct->proto.gre.stream_timeout = PPTP_GRE_STREAM_TIMEOUT;
rcu_read_lock();
nf_nat_pptp_expectfn = rcu_dereference(nf_nat_pptp_hook_expectfn);
if (nf_nat_pptp_expectfn && ct->master->status & IPS_NAT_MASK)
nf_nat_pptp_expectfn(ct, exp);
else {
struct nf_conntrack_tuple inv_t;
struct nf_conntrack_expect *exp_other;
nf_ct_invert_tuplepr(&inv_t, &exp->tuple);
pr_debug("trying to unexpect other dir: ");
nf_ct_dump_tuple(&inv_t);
exp_other = nf_ct_expect_find_get(net, nf_ct_zone(ct), &inv_t);
if (exp_other) {
pr_debug("found\n");
nf_ct_unexpect_related(exp_other);
nf_ct_expect_put(exp_other);
} else {
pr_debug("not found\n");
}
}
rcu_read_unlock();
}
static int destroy_sibling_or_exp(struct net *net, struct nf_conn *ct,
const struct nf_conntrack_tuple *t)
{
const struct nf_conntrack_tuple_hash *h;
const struct nf_conntrack_zone *zone;
struct nf_conntrack_expect *exp;
struct nf_conn *sibling;
pr_debug("trying to timeout ct or exp for tuple ");
nf_ct_dump_tuple(t);
zone = nf_ct_zone(ct);
h = nf_conntrack_find_get(net, zone, t);
if (h) {
sibling = nf_ct_tuplehash_to_ctrack(h);
pr_debug("setting timeout of conntrack %p to 0\n", sibling);
sibling->proto.gre.timeout = 0;
sibling->proto.gre.stream_timeout = 0;
if (del_timer(&sibling->timeout))
sibling->timeout.function((unsigned long)sibling);
nf_ct_put(sibling);
return 1;
} else {
exp = nf_ct_expect_find_get(net, zone, t);
if (exp) {
pr_debug("unexpect_related of expect %p\n", exp);
nf_ct_unexpect_related(exp);
nf_ct_expect_put(exp);
return 1;
}
}
return 0;
}
static void pptp_destroy_siblings(struct nf_conn *ct)
{
struct net *net = nf_ct_net(ct);
const struct nf_ct_pptp_master *ct_pptp_info = nfct_help_data(ct);
struct nf_conntrack_tuple t;
nf_ct_gre_keymap_destroy(ct);
memcpy(&t, &ct->tuplehash[IP_CT_DIR_ORIGINAL].tuple, sizeof(t));
t.dst.protonum = IPPROTO_GRE;
t.src.u.gre.key = ct_pptp_info->pns_call_id;
t.dst.u.gre.key = ct_pptp_info->pac_call_id;
if (!destroy_sibling_or_exp(net, ct, &t))
pr_debug("failed to timeout original pns->pac ct/exp\n");
memcpy(&t, &ct->tuplehash[IP_CT_DIR_REPLY].tuple, sizeof(t));
t.dst.protonum = IPPROTO_GRE;
t.src.u.gre.key = ct_pptp_info->pac_call_id;
t.dst.u.gre.key = ct_pptp_info->pns_call_id;
if (!destroy_sibling_or_exp(net, ct, &t))
pr_debug("failed to timeout reply pac->pns ct/exp\n");
}
static int exp_gre(struct nf_conn *ct, __be16 callid, __be16 peer_callid)
{
struct nf_conntrack_expect *exp_orig, *exp_reply;
enum ip_conntrack_dir dir;
int ret = 1;
typeof(nf_nat_pptp_hook_exp_gre) nf_nat_pptp_exp_gre;
exp_orig = nf_ct_expect_alloc(ct);
if (exp_orig == NULL)
goto out;
exp_reply = nf_ct_expect_alloc(ct);
if (exp_reply == NULL)
goto out_put_orig;
dir = IP_CT_DIR_ORIGINAL;
nf_ct_expect_init(exp_orig, NF_CT_EXPECT_CLASS_DEFAULT,
nf_ct_l3num(ct),
&ct->tuplehash[dir].tuple.src.u3,
&ct->tuplehash[dir].tuple.dst.u3,
IPPROTO_GRE, &peer_callid, &callid);
exp_orig->expectfn = pptp_expectfn;
dir = IP_CT_DIR_REPLY;
nf_ct_expect_init(exp_reply, NF_CT_EXPECT_CLASS_DEFAULT,
nf_ct_l3num(ct),
&ct->tuplehash[dir].tuple.src.u3,
&ct->tuplehash[dir].tuple.dst.u3,
IPPROTO_GRE, &callid, &peer_callid);
exp_reply->expectfn = pptp_expectfn;
nf_nat_pptp_exp_gre = rcu_dereference(nf_nat_pptp_hook_exp_gre);
if (nf_nat_pptp_exp_gre && ct->status & IPS_NAT_MASK)
nf_nat_pptp_exp_gre(exp_orig, exp_reply);
if (nf_ct_expect_related(exp_orig) != 0)
goto out_put_both;
if (nf_ct_expect_related(exp_reply) != 0)
goto out_unexpect_orig;
if (nf_ct_gre_keymap_add(ct, IP_CT_DIR_ORIGINAL, &exp_orig->tuple) != 0)
goto out_unexpect_both;
if (nf_ct_gre_keymap_add(ct, IP_CT_DIR_REPLY, &exp_reply->tuple) != 0) {
nf_ct_gre_keymap_destroy(ct);
goto out_unexpect_both;
}
ret = 0;
out_put_both:
nf_ct_expect_put(exp_reply);
out_put_orig:
nf_ct_expect_put(exp_orig);
out:
return ret;
out_unexpect_both:
nf_ct_unexpect_related(exp_reply);
out_unexpect_orig:
nf_ct_unexpect_related(exp_orig);
goto out_put_both;
}
static inline int
pptp_inbound_pkt(struct sk_buff *skb, unsigned int protoff,
struct PptpControlHeader *ctlh,
union pptp_ctrl_union *pptpReq,
unsigned int reqlen,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo)
{
struct nf_ct_pptp_master *info = nfct_help_data(ct);
u_int16_t msg;
__be16 cid = 0, pcid = 0;
typeof(nf_nat_pptp_hook_inbound) nf_nat_pptp_inbound;
msg = ntohs(ctlh->messageType);
pr_debug("inbound control message %s\n", pptp_msg_name[msg]);
switch (msg) {
case PPTP_START_SESSION_REPLY:
if (info->sstate < PPTP_SESSION_REQUESTED)
goto invalid;
if (pptpReq->srep.resultCode == PPTP_START_OK)
info->sstate = PPTP_SESSION_CONFIRMED;
else
info->sstate = PPTP_SESSION_ERROR;
break;
case PPTP_STOP_SESSION_REPLY:
if (info->sstate > PPTP_SESSION_STOPREQ)
goto invalid;
if (pptpReq->strep.resultCode == PPTP_STOP_OK)
info->sstate = PPTP_SESSION_NONE;
else
info->sstate = PPTP_SESSION_ERROR;
break;
case PPTP_OUT_CALL_REPLY:
if (info->sstate != PPTP_SESSION_CONFIRMED)
goto invalid;
if (info->cstate != PPTP_CALL_OUT_REQ &&
info->cstate != PPTP_CALL_OUT_CONF)
goto invalid;
cid = pptpReq->ocack.callID;
pcid = pptpReq->ocack.peersCallID;
if (info->pns_call_id != pcid)
goto invalid;
pr_debug("%s, CID=%X, PCID=%X\n", pptp_msg_name[msg],
ntohs(cid), ntohs(pcid));
if (pptpReq->ocack.resultCode == PPTP_OUTCALL_CONNECT) {
info->cstate = PPTP_CALL_OUT_CONF;
info->pac_call_id = cid;
exp_gre(ct, cid, pcid);
} else
info->cstate = PPTP_CALL_NONE;
break;
case PPTP_IN_CALL_REQUEST:
if (info->sstate != PPTP_SESSION_CONFIRMED)
goto invalid;
cid = pptpReq->icreq.callID;
pr_debug("%s, CID=%X\n", pptp_msg_name[msg], ntohs(cid));
info->cstate = PPTP_CALL_IN_REQ;
info->pac_call_id = cid;
break;
case PPTP_IN_CALL_CONNECT:
if (info->sstate != PPTP_SESSION_CONFIRMED)
goto invalid;
if (info->cstate != PPTP_CALL_IN_REP &&
info->cstate != PPTP_CALL_IN_CONF)
goto invalid;
pcid = pptpReq->iccon.peersCallID;
cid = info->pac_call_id;
if (info->pns_call_id != pcid)
goto invalid;
pr_debug("%s, PCID=%X\n", pptp_msg_name[msg], ntohs(pcid));
info->cstate = PPTP_CALL_IN_CONF;
exp_gre(ct, cid, pcid);
break;
case PPTP_CALL_DISCONNECT_NOTIFY:
cid = pptpReq->disc.callID;
pr_debug("%s, CID=%X\n", pptp_msg_name[msg], ntohs(cid));
info->cstate = PPTP_CALL_NONE;
pptp_destroy_siblings(ct);
break;
case PPTP_WAN_ERROR_NOTIFY:
case PPTP_SET_LINK_INFO:
case PPTP_ECHO_REQUEST:
case PPTP_ECHO_REPLY:
break;
default:
goto invalid;
}
nf_nat_pptp_inbound = rcu_dereference(nf_nat_pptp_hook_inbound);
if (nf_nat_pptp_inbound && ct->status & IPS_NAT_MASK)
return nf_nat_pptp_inbound(skb, ct, ctinfo,
protoff, ctlh, pptpReq);
return NF_ACCEPT;
invalid:
pr_debug("invalid %s: type=%d cid=%u pcid=%u "
"cstate=%d sstate=%d pns_cid=%u pac_cid=%u\n",
msg <= PPTP_MSG_MAX ? pptp_msg_name[msg] : pptp_msg_name[0],
msg, ntohs(cid), ntohs(pcid), info->cstate, info->sstate,
ntohs(info->pns_call_id), ntohs(info->pac_call_id));
return NF_ACCEPT;
}
static inline int
pptp_outbound_pkt(struct sk_buff *skb, unsigned int protoff,
struct PptpControlHeader *ctlh,
union pptp_ctrl_union *pptpReq,
unsigned int reqlen,
struct nf_conn *ct,
enum ip_conntrack_info ctinfo)
{
struct nf_ct_pptp_master *info = nfct_help_data(ct);
u_int16_t msg;
__be16 cid = 0, pcid = 0;
typeof(nf_nat_pptp_hook_outbound) nf_nat_pptp_outbound;
msg = ntohs(ctlh->messageType);
pr_debug("outbound control message %s\n", pptp_msg_name[msg]);
switch (msg) {
case PPTP_START_SESSION_REQUEST:
if (info->sstate != PPTP_SESSION_NONE)
goto invalid;
info->sstate = PPTP_SESSION_REQUESTED;
break;
case PPTP_STOP_SESSION_REQUEST:
info->sstate = PPTP_SESSION_STOPREQ;
break;
case PPTP_OUT_CALL_REQUEST:
if (info->sstate != PPTP_SESSION_CONFIRMED)
goto invalid;
info->cstate = PPTP_CALL_OUT_REQ;
cid = pptpReq->ocreq.callID;
pr_debug("%s, CID=%X\n", pptp_msg_name[msg], ntohs(cid));
info->pns_call_id = cid;
break;
case PPTP_IN_CALL_REPLY:
if (info->cstate != PPTP_CALL_IN_REQ &&
info->cstate != PPTP_CALL_IN_REP)
goto invalid;
cid = pptpReq->icack.callID;
pcid = pptpReq->icack.peersCallID;
if (info->pac_call_id != pcid)
goto invalid;
pr_debug("%s, CID=%X PCID=%X\n", pptp_msg_name[msg],
ntohs(cid), ntohs(pcid));
if (pptpReq->icack.resultCode == PPTP_INCALL_ACCEPT) {
info->cstate = PPTP_CALL_IN_REP;
info->pns_call_id = cid;
} else
info->cstate = PPTP_CALL_NONE;
break;
case PPTP_CALL_CLEAR_REQUEST:
if (info->sstate != PPTP_SESSION_CONFIRMED)
goto invalid;
info->cstate = PPTP_CALL_CLEAR_REQ;
break;
case PPTP_SET_LINK_INFO:
case PPTP_ECHO_REQUEST:
case PPTP_ECHO_REPLY:
break;
default:
goto invalid;
}
nf_nat_pptp_outbound = rcu_dereference(nf_nat_pptp_hook_outbound);
if (nf_nat_pptp_outbound && ct->status & IPS_NAT_MASK)
return nf_nat_pptp_outbound(skb, ct, ctinfo,
protoff, ctlh, pptpReq);
return NF_ACCEPT;
invalid:
pr_debug("invalid %s: type=%d cid=%u pcid=%u "
"cstate=%d sstate=%d pns_cid=%u pac_cid=%u\n",
msg <= PPTP_MSG_MAX ? pptp_msg_name[msg] : pptp_msg_name[0],
msg, ntohs(cid), ntohs(pcid), info->cstate, info->sstate,
ntohs(info->pns_call_id), ntohs(info->pac_call_id));
return NF_ACCEPT;
}
static int
conntrack_pptp_help(struct sk_buff *skb, unsigned int protoff,
struct nf_conn *ct, enum ip_conntrack_info ctinfo)
{
int dir = CTINFO2DIR(ctinfo);
const struct nf_ct_pptp_master *info = nfct_help_data(ct);
const struct tcphdr *tcph;
struct tcphdr _tcph;
const struct pptp_pkt_hdr *pptph;
struct pptp_pkt_hdr _pptph;
struct PptpControlHeader _ctlh, *ctlh;
union pptp_ctrl_union _pptpReq, *pptpReq;
unsigned int tcplen = skb->len - protoff;
unsigned int datalen, reqlen, nexthdr_off;
int oldsstate, oldcstate;
int ret;
u_int16_t msg;
if (ctinfo != IP_CT_ESTABLISHED && ctinfo != IP_CT_ESTABLISHED_REPLY)
return NF_ACCEPT;
nexthdr_off = protoff;
tcph = skb_header_pointer(skb, nexthdr_off, sizeof(_tcph), &_tcph);
BUG_ON(!tcph);
nexthdr_off += tcph->doff * 4;
datalen = tcplen - tcph->doff * 4;
pptph = skb_header_pointer(skb, nexthdr_off, sizeof(_pptph), &_pptph);
if (!pptph) {
pr_debug("no full PPTP header, can't track\n");
return NF_ACCEPT;
}
nexthdr_off += sizeof(_pptph);
datalen -= sizeof(_pptph);
if (ntohs(pptph->packetType) != PPTP_PACKET_CONTROL ||
ntohl(pptph->magicCookie) != PPTP_MAGIC_COOKIE) {
pr_debug("not a control packet\n");
return NF_ACCEPT;
}
ctlh = skb_header_pointer(skb, nexthdr_off, sizeof(_ctlh), &_ctlh);
if (!ctlh)
return NF_ACCEPT;
nexthdr_off += sizeof(_ctlh);
datalen -= sizeof(_ctlh);
reqlen = datalen;
msg = ntohs(ctlh->messageType);
if (msg > 0 && msg <= PPTP_MSG_MAX && reqlen < pptp_msg_size[msg])
return NF_ACCEPT;
if (reqlen > sizeof(*pptpReq))
reqlen = sizeof(*pptpReq);
pptpReq = skb_header_pointer(skb, nexthdr_off, reqlen, &_pptpReq);
if (!pptpReq)
return NF_ACCEPT;
oldsstate = info->sstate;
oldcstate = info->cstate;
spin_lock_bh(&nf_pptp_lock);
if (dir == IP_CT_DIR_ORIGINAL)
ret = pptp_outbound_pkt(skb, protoff, ctlh, pptpReq, reqlen, ct,
ctinfo);
else
ret = pptp_inbound_pkt(skb, protoff, ctlh, pptpReq, reqlen, ct,
ctinfo);
pr_debug("sstate: %d->%d, cstate: %d->%d\n",
oldsstate, info->sstate, oldcstate, info->cstate);
spin_unlock_bh(&nf_pptp_lock);
return ret;
}
static int __init nf_conntrack_pptp_init(void)
{
return nf_conntrack_helper_register(&pptp);
}
static void __exit nf_conntrack_pptp_fini(void)
{
nf_conntrack_helper_unregister(&pptp);
}
