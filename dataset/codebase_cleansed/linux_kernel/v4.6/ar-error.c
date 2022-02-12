void rxrpc_UDP_error_report(struct sock *sk)
{
struct sock_exterr_skb *serr;
struct rxrpc_transport *trans;
struct rxrpc_local *local = sk->sk_user_data;
struct rxrpc_peer *peer;
struct sk_buff *skb;
__be32 addr;
__be16 port;
_enter("%p{%d}", sk, local->debug_id);
skb = sock_dequeue_err_skb(sk);
if (!skb) {
_leave("UDP socket errqueue empty");
return;
}
serr = SKB_EXT_ERR(skb);
if (!skb->len && serr->ee.ee_origin == SO_EE_ORIGIN_TIMESTAMPING) {
_leave("UDP empty message");
kfree_skb(skb);
return;
}
rxrpc_new_skb(skb);
addr = *(__be32 *)(skb_network_header(skb) + serr->addr_offset);
port = serr->port;
_net("Rx UDP Error from %pI4:%hu", &addr, ntohs(port));
_debug("Msg l:%d d:%d", skb->len, skb->data_len);
peer = rxrpc_find_peer(local, addr, port);
if (IS_ERR(peer)) {
rxrpc_free_skb(skb);
_leave(" [no peer]");
return;
}
trans = rxrpc_find_transport(local, peer);
if (!trans) {
rxrpc_put_peer(peer);
rxrpc_free_skb(skb);
_leave(" [no trans]");
return;
}
if (serr->ee.ee_origin == SO_EE_ORIGIN_ICMP &&
serr->ee.ee_type == ICMP_DEST_UNREACH &&
serr->ee.ee_code == ICMP_FRAG_NEEDED
) {
u32 mtu = serr->ee.ee_info;
_net("Rx Received ICMP Fragmentation Needed (%d)", mtu);
if (mtu > 0 && peer->if_mtu == 65535 && mtu < peer->if_mtu) {
peer->if_mtu = mtu;
_net("I/F MTU %u", mtu);
}
if (mtu == 0) {
mtu = peer->if_mtu;
if (mtu > 1500) {
mtu >>= 1;
if (mtu < 1500)
mtu = 1500;
} else {
mtu -= 100;
if (mtu < peer->hdrsize)
mtu = peer->hdrsize + 4;
}
}
if (mtu < peer->mtu) {
spin_lock_bh(&peer->lock);
peer->mtu = mtu;
peer->maxdata = peer->mtu - peer->hdrsize;
spin_unlock_bh(&peer->lock);
_net("Net MTU %u (maxdata %u)",
peer->mtu, peer->maxdata);
}
}
rxrpc_put_peer(peer);
skb_queue_tail(&trans->error_queue, skb);
rxrpc_queue_work(&trans->error_handler);
_leave("");
}
void rxrpc_UDP_error_handler(struct work_struct *work)
{
struct sock_extended_err *ee;
struct sock_exterr_skb *serr;
struct rxrpc_transport *trans =
container_of(work, struct rxrpc_transport, error_handler);
struct sk_buff *skb;
int err;
_enter("");
skb = skb_dequeue(&trans->error_queue);
if (!skb)
return;
serr = SKB_EXT_ERR(skb);
ee = &serr->ee;
_net("Rx Error o=%d t=%d c=%d e=%d",
ee->ee_origin, ee->ee_type, ee->ee_code, ee->ee_errno);
err = ee->ee_errno;
switch (ee->ee_origin) {
case SO_EE_ORIGIN_ICMP:
switch (ee->ee_type) {
case ICMP_DEST_UNREACH:
switch (ee->ee_code) {
case ICMP_NET_UNREACH:
_net("Rx Received ICMP Network Unreachable");
break;
case ICMP_HOST_UNREACH:
_net("Rx Received ICMP Host Unreachable");
break;
case ICMP_PORT_UNREACH:
_net("Rx Received ICMP Port Unreachable");
break;
case ICMP_NET_UNKNOWN:
_net("Rx Received ICMP Unknown Network");
break;
case ICMP_HOST_UNKNOWN:
_net("Rx Received ICMP Unknown Host");
break;
default:
_net("Rx Received ICMP DestUnreach code=%u",
ee->ee_code);
break;
}
break;
case ICMP_TIME_EXCEEDED:
_net("Rx Received ICMP TTL Exceeded");
break;
default:
_proto("Rx Received ICMP error { type=%u code=%u }",
ee->ee_type, ee->ee_code);
break;
}
break;
case SO_EE_ORIGIN_LOCAL:
_proto("Rx Received local error { error=%d }",
ee->ee_errno);
break;
case SO_EE_ORIGIN_NONE:
case SO_EE_ORIGIN_ICMP6:
default:
_proto("Rx Received error report { orig=%u }",
ee->ee_origin);
break;
}
if (err) {
struct rxrpc_call *call, *_n;
_debug("ISSUE ERROR %d", err);
spin_lock_bh(&trans->peer->lock);
trans->peer->net_error = err;
list_for_each_entry_safe(call, _n, &trans->peer->error_targets,
error_link) {
write_lock(&call->state_lock);
if (call->state != RXRPC_CALL_COMPLETE &&
call->state < RXRPC_CALL_NETWORK_ERROR) {
call->state = RXRPC_CALL_NETWORK_ERROR;
set_bit(RXRPC_CALL_EV_RCVD_ERROR, &call->events);
rxrpc_queue_call(call);
}
write_unlock(&call->state_lock);
list_del_init(&call->error_link);
}
spin_unlock_bh(&trans->peer->lock);
}
if (!skb_queue_empty(&trans->error_queue))
rxrpc_queue_work(&trans->error_handler);
rxrpc_free_skb(skb);
rxrpc_put_transport(trans);
_leave("");
}
