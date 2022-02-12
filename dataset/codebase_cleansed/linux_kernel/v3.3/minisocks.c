void dccp_time_wait(struct sock *sk, int state, int timeo)
{
struct inet_timewait_sock *tw = NULL;
if (dccp_death_row.tw_count < dccp_death_row.sysctl_max_tw_buckets)
tw = inet_twsk_alloc(sk, state);
if (tw != NULL) {
const struct inet_connection_sock *icsk = inet_csk(sk);
const int rto = (icsk->icsk_rto << 2) - (icsk->icsk_rto >> 1);
#if IS_ENABLED(CONFIG_IPV6)
if (tw->tw_family == PF_INET6) {
const struct ipv6_pinfo *np = inet6_sk(sk);
struct inet6_timewait_sock *tw6;
tw->tw_ipv6_offset = inet6_tw_offset(sk->sk_prot);
tw6 = inet6_twsk((struct sock *)tw);
tw6->tw_v6_daddr = np->daddr;
tw6->tw_v6_rcv_saddr = np->rcv_saddr;
tw->tw_ipv6only = np->ipv6only;
}
#endif
__inet_twsk_hashdance(tw, sk, &dccp_hashinfo);
if (timeo < rto)
timeo = rto;
tw->tw_timeout = DCCP_TIMEWAIT_LEN;
if (state == DCCP_TIME_WAIT)
timeo = DCCP_TIMEWAIT_LEN;
inet_twsk_schedule(tw, &dccp_death_row, timeo,
DCCP_TIMEWAIT_LEN);
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
newdp->dccps_gss = newdp->dccps_iss = dreq->dreq_iss;
newdp->dccps_gar = newdp->dccps_iss;
newdp->dccps_gsr = newdp->dccps_isr = dreq->dreq_isr;
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
struct request_sock *req,
struct request_sock **prev)
{
struct sock *child = NULL;
struct dccp_request_sock *dreq = dccp_rsk(req);
if (dccp_hdr(skb)->dccph_type == DCCP_PKT_REQUEST) {
if (after48(DCCP_SKB_CB(skb)->dccpd_seq, dreq->dreq_isr)) {
dccp_pr_debug("Retransmitted REQUEST\n");
dreq->dreq_isr = DCCP_SKB_CB(skb)->dccpd_seq;
req->retrans++;
req->rsk_ops->rtx_syn_ack(sk, req, NULL);
}
return NULL;
}
DCCP_SKB_CB(skb)->dccpd_reset_code = DCCP_RESET_CODE_PACKET_ERROR;
if (dccp_hdr(skb)->dccph_type != DCCP_PKT_ACK &&
dccp_hdr(skb)->dccph_type != DCCP_PKT_DATAACK)
goto drop;
if (DCCP_SKB_CB(skb)->dccpd_ack_seq != dreq->dreq_iss) {
dccp_pr_debug("Invalid ACK number: ack_seq=%llu, "
"dreq_iss=%llu\n",
(unsigned long long)
DCCP_SKB_CB(skb)->dccpd_ack_seq,
(unsigned long long) dreq->dreq_iss);
goto drop;
}
if (dccp_parse_options(sk, dreq, skb))
goto drop;
child = inet_csk(sk)->icsk_af_ops->syn_recv_sock(sk, skb, req, NULL);
if (child == NULL)
goto listen_overflow;
inet_csk_reqsk_queue_unlink(sk, req, prev);
inet_csk_reqsk_queue_removed(sk, req);
inet_csk_reqsk_queue_add(sk, req, child);
out:
return child;
listen_overflow:
dccp_pr_debug("listen_overflow!\n");
DCCP_SKB_CB(skb)->dccpd_reset_code = DCCP_RESET_CODE_TOO_BUSY;
drop:
if (dccp_hdr(skb)->dccph_type != DCCP_PKT_RESET)
req->rsk_ops->send_reset(sk, skb);
inet_csk_reqsk_queue_drop(sk, req, prev);
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
parent->sk_data_ready(parent, 0);
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
inet_rsk(req)->rmt_port = dccp_hdr(skb)->dccph_sport;
inet_rsk(req)->loc_port = dccp_hdr(skb)->dccph_dport;
inet_rsk(req)->acked = 0;
dreq->dreq_timestamp_echo = 0;
return dccp_feat_clone_list(&dp->dccps_featneg, &dreq->dreq_featneg);
}
