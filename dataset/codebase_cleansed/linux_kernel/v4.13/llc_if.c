int llc_build_and_send_pkt(struct sock *sk, struct sk_buff *skb)
{
struct llc_conn_state_ev *ev;
int rc = -ECONNABORTED;
struct llc_sock *llc = llc_sk(sk);
if (unlikely(llc->state == LLC_CONN_STATE_ADM))
goto out;
rc = -EBUSY;
if (unlikely(llc_data_accept_state(llc->state) ||
llc->p_flag)) {
llc->failed_data_req = 1;
goto out;
}
ev = llc_conn_ev(skb);
ev->type = LLC_CONN_EV_TYPE_PRIM;
ev->prim = LLC_DATA_PRIM;
ev->prim_type = LLC_PRIM_TYPE_REQ;
skb->dev = llc->dev;
rc = llc_conn_state_process(sk, skb);
out:
return rc;
}
int llc_establish_connection(struct sock *sk, u8 *lmac, u8 *dmac, u8 dsap)
{
int rc = -EISCONN;
struct llc_addr laddr, daddr;
struct sk_buff *skb;
struct llc_sock *llc = llc_sk(sk);
struct sock *existing;
laddr.lsap = llc->sap->laddr.lsap;
daddr.lsap = dsap;
memcpy(daddr.mac, dmac, sizeof(daddr.mac));
memcpy(laddr.mac, lmac, sizeof(laddr.mac));
existing = llc_lookup_established(llc->sap, &daddr, &laddr);
if (existing) {
if (existing->sk_state == TCP_ESTABLISHED) {
sk = existing;
goto out_put;
} else
sock_put(existing);
}
sock_hold(sk);
rc = -ENOMEM;
skb = alloc_skb(0, GFP_ATOMIC);
if (skb) {
struct llc_conn_state_ev *ev = llc_conn_ev(skb);
ev->type = LLC_CONN_EV_TYPE_PRIM;
ev->prim = LLC_CONN_PRIM;
ev->prim_type = LLC_PRIM_TYPE_REQ;
skb_set_owner_w(skb, sk);
rc = llc_conn_state_process(sk, skb);
}
out_put:
sock_put(sk);
return rc;
}
int llc_send_disc(struct sock *sk)
{
u16 rc = 1;
struct llc_conn_state_ev *ev;
struct sk_buff *skb;
sock_hold(sk);
if (sk->sk_type != SOCK_STREAM || sk->sk_state != TCP_ESTABLISHED ||
llc_sk(sk)->state == LLC_CONN_STATE_ADM ||
llc_sk(sk)->state == LLC_CONN_OUT_OF_SVC)
goto out;
skb = alloc_skb(0, GFP_ATOMIC);
if (!skb)
goto out;
skb_set_owner_w(skb, sk);
sk->sk_state = TCP_CLOSING;
ev = llc_conn_ev(skb);
ev->type = LLC_CONN_EV_TYPE_PRIM;
ev->prim = LLC_DISC_PRIM;
ev->prim_type = LLC_PRIM_TYPE_REQ;
rc = llc_conn_state_process(sk, skb);
out:
sock_put(sk);
return rc;
}
