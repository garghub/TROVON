int dccp_v4_connect(struct sock *sk, struct sockaddr *uaddr, int addr_len)
{
const struct sockaddr_in *usin = (struct sockaddr_in *)uaddr;
struct inet_sock *inet = inet_sk(sk);
struct dccp_sock *dp = dccp_sk(sk);
__be16 orig_sport, orig_dport;
__be32 daddr, nexthop;
struct flowi4 *fl4;
struct rtable *rt;
int err;
struct ip_options_rcu *inet_opt;
dp->dccps_role = DCCP_ROLE_CLIENT;
if (addr_len < sizeof(struct sockaddr_in))
return -EINVAL;
if (usin->sin_family != AF_INET)
return -EAFNOSUPPORT;
nexthop = daddr = usin->sin_addr.s_addr;
inet_opt = rcu_dereference_protected(inet->inet_opt,
sock_owned_by_user(sk));
if (inet_opt != NULL && inet_opt->opt.srr) {
if (daddr == 0)
return -EINVAL;
nexthop = inet_opt->opt.faddr;
}
orig_sport = inet->inet_sport;
orig_dport = usin->sin_port;
fl4 = &inet->cork.fl.u.ip4;
rt = ip_route_connect(fl4, nexthop, inet->inet_saddr,
RT_CONN_FLAGS(sk), sk->sk_bound_dev_if,
IPPROTO_DCCP,
orig_sport, orig_dport, sk);
if (IS_ERR(rt))
return PTR_ERR(rt);
if (rt->rt_flags & (RTCF_MULTICAST | RTCF_BROADCAST)) {
ip_rt_put(rt);
return -ENETUNREACH;
}
if (inet_opt == NULL || !inet_opt->opt.srr)
daddr = fl4->daddr;
if (inet->inet_saddr == 0)
inet->inet_saddr = fl4->saddr;
sk_rcv_saddr_set(sk, inet->inet_saddr);
inet->inet_dport = usin->sin_port;
sk_daddr_set(sk, daddr);
inet_csk(sk)->icsk_ext_hdr_len = 0;
if (inet_opt)
inet_csk(sk)->icsk_ext_hdr_len = inet_opt->opt.optlen;
dccp_set_state(sk, DCCP_REQUESTING);
err = inet_hash_connect(&dccp_death_row, sk);
if (err != 0)
goto failure;
rt = ip_route_newports(fl4, rt, orig_sport, orig_dport,
inet->inet_sport, inet->inet_dport, sk);
if (IS_ERR(rt)) {
err = PTR_ERR(rt);
rt = NULL;
goto failure;
}
sk_setup_caps(sk, &rt->dst);
dp->dccps_iss = secure_dccp_sequence_number(inet->inet_saddr,
inet->inet_daddr,
inet->inet_sport,
inet->inet_dport);
inet->inet_id = dp->dccps_iss ^ jiffies;
err = dccp_connect(sk);
rt = NULL;
if (err != 0)
goto failure;
out:
return err;
failure:
dccp_set_state(sk, DCCP_CLOSED);
ip_rt_put(rt);
sk->sk_route_caps = 0;
inet->inet_dport = 0;
goto out;
}
static inline void dccp_do_pmtu_discovery(struct sock *sk,
const struct iphdr *iph,
u32 mtu)
{
struct dst_entry *dst;
const struct inet_sock *inet = inet_sk(sk);
const struct dccp_sock *dp = dccp_sk(sk);
if (sk->sk_state == DCCP_LISTEN)
return;
dst = inet_csk_update_pmtu(sk, mtu);
if (!dst)
return;
if (mtu < dst_mtu(dst) && ip_dont_fragment(sk, dst))
sk->sk_err_soft = EMSGSIZE;
mtu = dst_mtu(dst);
if (inet->pmtudisc != IP_PMTUDISC_DONT &&
ip_sk_accept_pmtu(sk) &&
inet_csk(sk)->icsk_pmtu_cookie > mtu) {
dccp_sync_mss(sk, mtu);
dccp_send_sync(sk, dp->dccps_gsr, DCCP_PKT_SYNC);
}
}
static void dccp_do_redirect(struct sk_buff *skb, struct sock *sk)
{
struct dst_entry *dst = __sk_dst_check(sk, 0);
if (dst)
dst->ops->redirect(dst, sk, skb);
}
void dccp_req_err(struct sock *sk, u64 seq)
{
struct request_sock *req = inet_reqsk(sk);
struct net *net = sock_net(sk);
if (!between48(seq, dccp_rsk(req)->dreq_iss, dccp_rsk(req)->dreq_gss)) {
NET_INC_STATS_BH(net, LINUX_MIB_OUTOFWINDOWICMPS);
} else {
inet_csk_reqsk_queue_drop(req->rsk_listener, req);
}
reqsk_put(req);
}
static void dccp_v4_err(struct sk_buff *skb, u32 info)
{
const struct iphdr *iph = (struct iphdr *)skb->data;
const u8 offset = iph->ihl << 2;
const struct dccp_hdr *dh = (struct dccp_hdr *)(skb->data + offset);
struct dccp_sock *dp;
struct inet_sock *inet;
const int type = icmp_hdr(skb)->type;
const int code = icmp_hdr(skb)->code;
struct sock *sk;
__u64 seq;
int err;
struct net *net = dev_net(skb->dev);
if (skb->len < offset + sizeof(*dh) ||
skb->len < offset + __dccp_basic_hdr_len(dh)) {
ICMP_INC_STATS_BH(net, ICMP_MIB_INERRORS);
return;
}
sk = __inet_lookup_established(net, &dccp_hashinfo,
iph->daddr, dh->dccph_dport,
iph->saddr, ntohs(dh->dccph_sport),
inet_iif(skb));
if (!sk) {
ICMP_INC_STATS_BH(net, ICMP_MIB_INERRORS);
return;
}
if (sk->sk_state == DCCP_TIME_WAIT) {
inet_twsk_put(inet_twsk(sk));
return;
}
seq = dccp_hdr_seq(dh);
if (sk->sk_state == DCCP_NEW_SYN_RECV)
return dccp_req_err(sk, seq);
bh_lock_sock(sk);
if (sock_owned_by_user(sk))
NET_INC_STATS_BH(net, LINUX_MIB_LOCKDROPPEDICMPS);
if (sk->sk_state == DCCP_CLOSED)
goto out;
dp = dccp_sk(sk);
if ((1 << sk->sk_state) & ~(DCCPF_REQUESTING | DCCPF_LISTEN) &&
!between48(seq, dp->dccps_awl, dp->dccps_awh)) {
NET_INC_STATS_BH(net, LINUX_MIB_OUTOFWINDOWICMPS);
goto out;
}
switch (type) {
case ICMP_REDIRECT:
dccp_do_redirect(skb, sk);
goto out;
case ICMP_SOURCE_QUENCH:
goto out;
case ICMP_PARAMETERPROB:
err = EPROTO;
break;
case ICMP_DEST_UNREACH:
if (code > NR_ICMP_UNREACH)
goto out;
if (code == ICMP_FRAG_NEEDED) {
if (!sock_owned_by_user(sk))
dccp_do_pmtu_discovery(sk, iph, info);
goto out;
}
err = icmp_err_convert[code].errno;
break;
case ICMP_TIME_EXCEEDED:
err = EHOSTUNREACH;
break;
default:
goto out;
}
switch (sk->sk_state) {
case DCCP_REQUESTING:
case DCCP_RESPOND:
if (!sock_owned_by_user(sk)) {
DCCP_INC_STATS_BH(DCCP_MIB_ATTEMPTFAILS);
sk->sk_err = err;
sk->sk_error_report(sk);
dccp_done(sk);
} else
sk->sk_err_soft = err;
goto out;
}
inet = inet_sk(sk);
if (!sock_owned_by_user(sk) && inet->recverr) {
sk->sk_err = err;
sk->sk_error_report(sk);
} else
sk->sk_err_soft = err;
out:
bh_unlock_sock(sk);
sock_put(sk);
}
static inline __sum16 dccp_v4_csum_finish(struct sk_buff *skb,
__be32 src, __be32 dst)
{
return csum_tcpudp_magic(src, dst, skb->len, IPPROTO_DCCP, skb->csum);
}
void dccp_v4_send_check(struct sock *sk, struct sk_buff *skb)
{
const struct inet_sock *inet = inet_sk(sk);
struct dccp_hdr *dh = dccp_hdr(skb);
dccp_csum_outgoing(skb);
dh->dccph_checksum = dccp_v4_csum_finish(skb,
inet->inet_saddr,
inet->inet_daddr);
}
static inline u64 dccp_v4_init_sequence(const struct sk_buff *skb)
{
return secure_dccp_sequence_number(ip_hdr(skb)->daddr,
ip_hdr(skb)->saddr,
dccp_hdr(skb)->dccph_dport,
dccp_hdr(skb)->dccph_sport);
}
struct sock *dccp_v4_request_recv_sock(const struct sock *sk,
struct sk_buff *skb,
struct request_sock *req,
struct dst_entry *dst,
struct request_sock *req_unhash,
bool *own_req)
{
struct inet_request_sock *ireq;
struct inet_sock *newinet;
struct sock *newsk;
if (sk_acceptq_is_full(sk))
goto exit_overflow;
newsk = dccp_create_openreq_child(sk, req, skb);
if (newsk == NULL)
goto exit_nonewsk;
newinet = inet_sk(newsk);
ireq = inet_rsk(req);
sk_daddr_set(newsk, ireq->ir_rmt_addr);
sk_rcv_saddr_set(newsk, ireq->ir_loc_addr);
newinet->inet_saddr = ireq->ir_loc_addr;
newinet->inet_opt = ireq->opt;
ireq->opt = NULL;
newinet->mc_index = inet_iif(skb);
newinet->mc_ttl = ip_hdr(skb)->ttl;
newinet->inet_id = jiffies;
if (dst == NULL && (dst = inet_csk_route_child_sock(sk, newsk, req)) == NULL)
goto put_and_exit;
sk_setup_caps(newsk, dst);
dccp_sync_mss(newsk, dst_mtu(dst));
if (__inet_inherit_port(sk, newsk) < 0)
goto put_and_exit;
*own_req = inet_ehash_nolisten(newsk, req_to_sk(req_unhash));
return newsk;
exit_overflow:
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_LISTENOVERFLOWS);
exit_nonewsk:
dst_release(dst);
exit:
NET_INC_STATS_BH(sock_net(sk), LINUX_MIB_LISTENDROPS);
return NULL;
put_and_exit:
inet_csk_prepare_forced_close(newsk);
dccp_done(newsk);
goto exit;
}
static struct dst_entry* dccp_v4_route_skb(struct net *net, struct sock *sk,
struct sk_buff *skb)
{
struct rtable *rt;
const struct iphdr *iph = ip_hdr(skb);
struct flowi4 fl4 = {
.flowi4_oif = inet_iif(skb),
.daddr = iph->saddr,
.saddr = iph->daddr,
.flowi4_tos = RT_CONN_FLAGS(sk),
.flowi4_proto = sk->sk_protocol,
.fl4_sport = dccp_hdr(skb)->dccph_dport,
.fl4_dport = dccp_hdr(skb)->dccph_sport,
};
security_skb_classify_flow(skb, flowi4_to_flowi(&fl4));
rt = ip_route_output_flow(net, &fl4, sk);
if (IS_ERR(rt)) {
IP_INC_STATS_BH(net, IPSTATS_MIB_OUTNOROUTES);
return NULL;
}
return &rt->dst;
}
static int dccp_v4_send_response(const struct sock *sk, struct request_sock *req)
{
int err = -1;
struct sk_buff *skb;
struct dst_entry *dst;
struct flowi4 fl4;
dst = inet_csk_route_req(sk, &fl4, req);
if (dst == NULL)
goto out;
skb = dccp_make_response(sk, dst, req);
if (skb != NULL) {
const struct inet_request_sock *ireq = inet_rsk(req);
struct dccp_hdr *dh = dccp_hdr(skb);
dh->dccph_checksum = dccp_v4_csum_finish(skb, ireq->ir_loc_addr,
ireq->ir_rmt_addr);
err = ip_build_and_send_pkt(skb, sk, ireq->ir_loc_addr,
ireq->ir_rmt_addr,
ireq->opt);
err = net_xmit_eval(err);
}
out:
dst_release(dst);
return err;
}
static void dccp_v4_ctl_send_reset(const struct sock *sk, struct sk_buff *rxskb)
{
int err;
const struct iphdr *rxiph;
struct sk_buff *skb;
struct dst_entry *dst;
struct net *net = dev_net(skb_dst(rxskb)->dev);
struct sock *ctl_sk = net->dccp.v4_ctl_sk;
if (dccp_hdr(rxskb)->dccph_type == DCCP_PKT_RESET)
return;
if (skb_rtable(rxskb)->rt_type != RTN_LOCAL)
return;
dst = dccp_v4_route_skb(net, ctl_sk, rxskb);
if (dst == NULL)
return;
skb = dccp_ctl_make_reset(ctl_sk, rxskb);
if (skb == NULL)
goto out;
rxiph = ip_hdr(rxskb);
dccp_hdr(skb)->dccph_checksum = dccp_v4_csum_finish(skb, rxiph->saddr,
rxiph->daddr);
skb_dst_set(skb, dst_clone(dst));
bh_lock_sock(ctl_sk);
err = ip_build_and_send_pkt(skb, ctl_sk,
rxiph->daddr, rxiph->saddr, NULL);
bh_unlock_sock(ctl_sk);
if (net_xmit_eval(err) == 0) {
DCCP_INC_STATS_BH(DCCP_MIB_OUTSEGS);
DCCP_INC_STATS_BH(DCCP_MIB_OUTRSTS);
}
out:
dst_release(dst);
}
static void dccp_v4_reqsk_destructor(struct request_sock *req)
{
dccp_feat_list_purge(&dccp_rsk(req)->dreq_featneg);
kfree(inet_rsk(req)->opt);
}
void dccp_syn_ack_timeout(const struct request_sock *req)
{
}
int dccp_v4_conn_request(struct sock *sk, struct sk_buff *skb)
{
struct inet_request_sock *ireq;
struct request_sock *req;
struct dccp_request_sock *dreq;
const __be32 service = dccp_hdr_request(skb)->dccph_req_service;
struct dccp_skb_cb *dcb = DCCP_SKB_CB(skb);
if (skb_rtable(skb)->rt_flags & (RTCF_BROADCAST | RTCF_MULTICAST))
return 0;
if (dccp_bad_service_code(sk, service)) {
dcb->dccpd_reset_code = DCCP_RESET_CODE_BAD_SERVICE_CODE;
goto drop;
}
dcb->dccpd_reset_code = DCCP_RESET_CODE_TOO_BUSY;
if (inet_csk_reqsk_queue_is_full(sk))
goto drop;
if (sk_acceptq_is_full(sk) && inet_csk_reqsk_queue_young(sk) > 1)
goto drop;
req = inet_reqsk_alloc(&dccp_request_sock_ops, sk, true);
if (req == NULL)
goto drop;
if (dccp_reqsk_init(req, dccp_sk(sk), skb))
goto drop_and_free;
dreq = dccp_rsk(req);
if (dccp_parse_options(sk, dreq, skb))
goto drop_and_free;
if (security_inet_conn_request(sk, skb, req))
goto drop_and_free;
ireq = inet_rsk(req);
sk_rcv_saddr_set(req_to_sk(req), ip_hdr(skb)->daddr);
sk_daddr_set(req_to_sk(req), ip_hdr(skb)->saddr);
ireq->ireq_family = AF_INET;
ireq->ir_iif = sk->sk_bound_dev_if;
dreq->dreq_isr = dcb->dccpd_seq;
dreq->dreq_gsr = dreq->dreq_isr;
dreq->dreq_iss = dccp_v4_init_sequence(skb);
dreq->dreq_gss = dreq->dreq_iss;
dreq->dreq_service = service;
if (dccp_v4_send_response(sk, req))
goto drop_and_free;
inet_csk_reqsk_queue_hash_add(sk, req, DCCP_TIMEOUT_INIT);
return 0;
drop_and_free:
reqsk_free(req);
drop:
DCCP_INC_STATS_BH(DCCP_MIB_ATTEMPTFAILS);
return -1;
}
int dccp_v4_do_rcv(struct sock *sk, struct sk_buff *skb)
{
struct dccp_hdr *dh = dccp_hdr(skb);
if (sk->sk_state == DCCP_OPEN) {
if (dccp_rcv_established(sk, skb, dh, skb->len))
goto reset;
return 0;
}
if (dccp_rcv_state_process(sk, skb, dh, skb->len))
goto reset;
return 0;
reset:
dccp_v4_ctl_send_reset(sk, skb);
kfree_skb(skb);
return 0;
}
int dccp_invalid_packet(struct sk_buff *skb)
{
const struct dccp_hdr *dh;
unsigned int cscov;
if (skb->pkt_type != PACKET_HOST)
return 1;
if (!pskb_may_pull(skb, sizeof(struct dccp_hdr))) {
DCCP_WARN("pskb_may_pull failed\n");
return 1;
}
dh = dccp_hdr(skb);
if (dh->dccph_type >= DCCP_PKT_INVALID) {
DCCP_WARN("invalid packet type\n");
return 1;
}
if (dh->dccph_doff < dccp_hdr_len(skb) / sizeof(u32)) {
DCCP_WARN("P.Data Offset(%u) too small\n", dh->dccph_doff);
return 1;
}
if (!pskb_may_pull(skb, dh->dccph_doff * sizeof(u32))) {
DCCP_WARN("P.Data Offset(%u) too large\n", dh->dccph_doff);
return 1;
}
if ((dh->dccph_type < DCCP_PKT_DATA ||
dh->dccph_type > DCCP_PKT_DATAACK) && dh->dccph_x == 0) {
DCCP_WARN("P.type (%s) not Data || [Data]Ack, while P.X == 0\n",
dccp_packet_name(dh->dccph_type));
return 1;
}
cscov = dccp_csum_coverage(skb);
if (cscov > skb->len) {
DCCP_WARN("P.CsCov %u exceeds packet length %d\n",
dh->dccph_cscov, skb->len);
return 1;
}
skb->csum = skb_checksum(skb, 0, cscov, 0);
return 0;
}
static int dccp_v4_rcv(struct sk_buff *skb)
{
const struct dccp_hdr *dh;
const struct iphdr *iph;
struct sock *sk;
int min_cov;
if (dccp_invalid_packet(skb))
goto discard_it;
iph = ip_hdr(skb);
if (dccp_v4_csum_finish(skb, iph->saddr, iph->daddr)) {
DCCP_WARN("dropped packet with invalid checksum\n");
goto discard_it;
}
dh = dccp_hdr(skb);
DCCP_SKB_CB(skb)->dccpd_seq = dccp_hdr_seq(dh);
DCCP_SKB_CB(skb)->dccpd_type = dh->dccph_type;
dccp_pr_debug("%8.8s src=%pI4@%-5d dst=%pI4@%-5d seq=%llu",
dccp_packet_name(dh->dccph_type),
&iph->saddr, ntohs(dh->dccph_sport),
&iph->daddr, ntohs(dh->dccph_dport),
(unsigned long long) DCCP_SKB_CB(skb)->dccpd_seq);
if (dccp_packet_without_ack(skb)) {
DCCP_SKB_CB(skb)->dccpd_ack_seq = DCCP_PKT_WITHOUT_ACK_SEQ;
dccp_pr_debug_cat("\n");
} else {
DCCP_SKB_CB(skb)->dccpd_ack_seq = dccp_hdr_ack_seq(skb);
dccp_pr_debug_cat(", ack=%llu\n", (unsigned long long)
DCCP_SKB_CB(skb)->dccpd_ack_seq);
}
lookup:
sk = __inet_lookup_skb(&dccp_hashinfo, skb, __dccp_hdr_len(dh),
dh->dccph_sport, dh->dccph_dport);
if (!sk) {
dccp_pr_debug("failed to look up flow ID in table and "
"get corresponding socket\n");
goto no_dccp_socket;
}
if (sk->sk_state == DCCP_TIME_WAIT) {
dccp_pr_debug("sk->sk_state == DCCP_TIME_WAIT: do_time_wait\n");
inet_twsk_put(inet_twsk(sk));
goto no_dccp_socket;
}
if (sk->sk_state == DCCP_NEW_SYN_RECV) {
struct request_sock *req = inet_reqsk(sk);
struct sock *nsk;
sk = req->rsk_listener;
if (unlikely(sk->sk_state != DCCP_LISTEN)) {
inet_csk_reqsk_queue_drop_and_put(sk, req);
goto lookup;
}
sock_hold(sk);
nsk = dccp_check_req(sk, skb, req);
if (!nsk) {
reqsk_put(req);
goto discard_and_relse;
}
if (nsk == sk) {
reqsk_put(req);
} else if (dccp_child_process(sk, nsk, skb)) {
dccp_v4_ctl_send_reset(sk, skb);
goto discard_and_relse;
} else {
sock_put(sk);
return 0;
}
}
min_cov = dccp_sk(sk)->dccps_pcrlen;
if (dh->dccph_cscov && (min_cov == 0 || dh->dccph_cscov < min_cov)) {
dccp_pr_debug("Packet CsCov %d does not satisfy MinCsCov %d\n",
dh->dccph_cscov, min_cov);
goto discard_and_relse;
}
if (!xfrm4_policy_check(sk, XFRM_POLICY_IN, skb))
goto discard_and_relse;
nf_reset(skb);
return sk_receive_skb(sk, skb, 1);
no_dccp_socket:
if (!xfrm4_policy_check(NULL, XFRM_POLICY_IN, skb))
goto discard_it;
if (dh->dccph_type != DCCP_PKT_RESET) {
DCCP_SKB_CB(skb)->dccpd_reset_code =
DCCP_RESET_CODE_NO_CONNECTION;
dccp_v4_ctl_send_reset(sk, skb);
}
discard_it:
kfree_skb(skb);
return 0;
discard_and_relse:
sock_put(sk);
goto discard_it;
}
static int dccp_v4_init_sock(struct sock *sk)
{
static __u8 dccp_v4_ctl_sock_initialized;
int err = dccp_init_sock(sk, dccp_v4_ctl_sock_initialized);
if (err == 0) {
if (unlikely(!dccp_v4_ctl_sock_initialized))
dccp_v4_ctl_sock_initialized = 1;
inet_csk(sk)->icsk_af_ops = &dccp_ipv4_af_ops;
}
return err;
}
static int __net_init dccp_v4_init_net(struct net *net)
{
if (dccp_hashinfo.bhash == NULL)
return -ESOCKTNOSUPPORT;
return inet_ctl_sock_create(&net->dccp.v4_ctl_sk, PF_INET,
SOCK_DCCP, IPPROTO_DCCP, net);
}
static void __net_exit dccp_v4_exit_net(struct net *net)
{
inet_ctl_sock_destroy(net->dccp.v4_ctl_sk);
}
static int __init dccp_v4_init(void)
{
int err = proto_register(&dccp_v4_prot, 1);
if (err != 0)
goto out;
err = inet_add_protocol(&dccp_v4_protocol, IPPROTO_DCCP);
if (err != 0)
goto out_proto_unregister;
inet_register_protosw(&dccp_v4_protosw);
err = register_pernet_subsys(&dccp_v4_ops);
if (err)
goto out_destroy_ctl_sock;
out:
return err;
out_destroy_ctl_sock:
inet_unregister_protosw(&dccp_v4_protosw);
inet_del_protocol(&dccp_v4_protocol, IPPROTO_DCCP);
out_proto_unregister:
proto_unregister(&dccp_v4_prot);
goto out;
}
static void __exit dccp_v4_exit(void)
{
unregister_pernet_subsys(&dccp_v4_ops);
inet_unregister_protosw(&dccp_v4_protosw);
inet_del_protocol(&dccp_v4_protocol, IPPROTO_DCCP);
proto_unregister(&dccp_v4_prot);
}
