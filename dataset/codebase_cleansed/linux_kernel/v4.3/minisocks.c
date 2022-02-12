void dccp_time_wait(struct sock *sk, int state, int timeo)
{
struct inet_timewait_sock *tw;
tw = inet_twsk_alloc(sk, &dccp_death_row, state);
if (tw != NULL) {
const struct inet_connection_sock *icsk = inet_csk(sk);
const int rto = (icsk->icsk_rto << 2) - (icsk->icsk_rto >> 1);
#if IS_ENABLED(CONFIG_IPV6)
if (tw->tw_family == PF_INET6) {
tw->tw_v6_daddr = sk->sk_v6_daddr;
tw->tw_v6_rcv_saddr = sk->sk_v6_rcv_saddr;
tw->tw_ipv6only = sk->sk_ipv6only;
}
#endif
if (timeo < rto)
timeo = rto;
tw->tw_timeout = DCCP_TIMEWAIT_LEN;
if (state == DCCP_TIME_WAIT)
timeo = DCCP_TIMEWAIT_LEN;
inet_twsk_schedule(tw, timeo);
__inet_twsk_hashdance(tw, sk, &dccp_hashinfo);
inet_twsk_put(tw);
} else {
DCCP_WARN("time wait bucket table overflow\n");
}
dccp_done(sk);
}
struct sock *dccp_create_openreq_child(struct sock *sk,
const struct request_sock *req,
const struct sk_buff *skb)
{
struct sock *newsk = inet_csk_clone_lock(sk, req, GFP_ATOMIC);
if (newsk != NULL) {
struct dccp_request_sock *dreq = dccp_rsk(req);
struct inet_connection_sock *newicsk = inet_csk(newsk);
struct dccp_sock *newdp = dccp_sk(newsk);
newdp->dccps_role = DCCP_ROLE_SERVER;
newdp->dccps_hc_rx_ackvec = NULL;
newdp->dccps_service_list = NULL;
newdp->dccps_service = dreq->dreq_service;
newdp->dccps_timestamp_echo = dreq->dreq_timestamp_echo;
newdp->dccps_timestamp_time = dreq->dreq_timestamp_time;
newicsk->icsk_rto = DCCP_TIMEOUT_INIT;
INIT_LIST_HEAD(&newdp->dccps_featneg);
newdp->dccps_iss = dreq->dreq_iss;
newdp->dccps_gss = dreq->dreq_gss;
newdp->dccps_gar = newdp->dccps_iss;
newdp->dccps_isr = dreq->dreq_isr;
newdp->dccps_gsr = dreq->dreq_gsr;
if (dccp_feat_activate_values(newsk, &dreq->dreq_featneg)) {
newsk->sk_destruct = NULL;
sk_free(newsk);
return NULL;
}
dccp_init_xmit_timers(newsk);
DCCP_INC_STATS_BH(DCCP_MIB_PASSIVEOPENS);
}
return newsk;
}
struct sock *dccp_check_req(struct sock *sk, struct sk_buff *skb,
struct request_sock *req)
{
struct sock *child = NULL;
struct dccp_request_sock *dreq = dccp_rsk(req);
if (dccp_hdr(skb)->dccph_type == DCCP_PKT_REQUEST) {
if (after48(DCCP_SKB_CB(skb)->dccpd_seq, dreq->dreq_gsr)) {
dccp_pr_debug("Retransmitted REQUEST\n");
dreq->dreq_gsr = DCCP_SKB_CB(skb)->dccpd_seq;
inet_rtx_syn_ack(sk, req);
}
return NULL;
}
DCCP_SKB_CB(skb)->dccpd_reset_code = DCCP_RESET_CODE_PACKET_ERROR;
if (dccp_hdr(skb)->dccph_type != DCCP_PKT_ACK &&
dccp_hdr(skb)->dccph_type != DCCP_PKT_DATAACK)
goto drop;
if (!between48(DCCP_SKB_CB(skb)->dccpd_ack_seq,
dreq->dreq_iss, dreq->dreq_gss)) {
dccp_pr_debug("Invalid ACK number: ack_seq=%llu, "
"dreq_iss=%llu, dreq_gss=%llu\n",
(unsigned long long)
DCCP_SKB_CB(skb)->dccpd_ack_seq,
(unsigned long long) dreq->dreq_iss,
(unsigned long long) dreq->dreq_gss);
goto drop;
}
if (dccp_parse_options(sk, dreq, skb))
goto drop;
child = inet_csk(sk)->icsk_af_ops->syn_recv_sock(sk, skb, req, NULL);
if (child == NULL)
goto listen_overflow;
inet_csk_reqsk_queue_drop(sk, req);
inet_csk_reqsk_queue_add(sk, req, child);
out:
return child;
listen_overflow:
dccp_pr_debug("listen_overflow!\n");
DCCP_SKB_CB(skb)->dccpd_reset_code = DCCP_RESET_CODE_TOO_BUSY;
drop:
if (dccp_hdr(skb)->dccph_type != DCCP_PKT_RESET)
req->rsk_ops->send_reset(sk, skb);
inet_csk_reqsk_queue_drop(sk, req);
goto out;
}
int dccp_child_process(struct sock *parent, struct sock *child,
struct sk_buff *skb)
{
int ret = 0;
const int state = child->sk_state;
if (!sock_owned_by_user(child)) {
ret = dccp_rcv_state_process(child, skb, dccp_hdr(skb),
skb->len);
if (state == DCCP_RESPOND && child->sk_state != state)
parent->sk_data_ready(parent);
} else {
__sk_add_backlog(child, skb);
}
bh_unlock_sock(child);
sock_put(child);
return ret;
}
void dccp_reqsk_send_ack(struct sock *sk, struct sk_buff *skb,
struct request_sock *rsk)
{
DCCP_BUG("DCCP-ACK packets are never sent in LISTEN/RESPOND state");
}
int dccp_reqsk_init(struct request_sock *req,
struct dccp_sock const *dp, struct sk_buff const *skb)
{
struct dccp_request_sock *dreq = dccp_rsk(req);
inet_rsk(req)->ir_rmt_port = dccp_hdr(skb)->dccph_sport;
inet_rsk(req)->ir_num = ntohs(dccp_hdr(skb)->dccph_dport);
inet_rsk(req)->acked = 0;
dreq->dreq_timestamp_echo = 0;
return dccp_feat_clone_list(&dp->dccps_featneg, &dreq->dreq_featneg);
}
