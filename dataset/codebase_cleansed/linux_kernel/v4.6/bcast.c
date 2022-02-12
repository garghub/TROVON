static struct tipc_bc_base *tipc_bc_base(struct net *net)
{
return tipc_net(net)->bcbase;
}
int tipc_bcast_get_mtu(struct net *net)
{
return tipc_link_mtu(tipc_bc_sndlink(net));
}
static void tipc_bcbase_select_primary(struct net *net)
{
struct tipc_bc_base *bb = tipc_bc_base(net);
int all_dests = tipc_link_bc_peers(bb->link);
int i, mtu;
bb->primary_bearer = INVALID_BEARER_ID;
if (!all_dests)
return;
for (i = 0; i < MAX_BEARERS; i++) {
if (!bb->dests[i])
continue;
mtu = tipc_bearer_mtu(net, i);
if (mtu < tipc_link_mtu(bb->link))
tipc_link_set_mtu(bb->link, mtu);
if (bb->dests[i] < all_dests)
continue;
bb->primary_bearer = i;
if ((i ^ tipc_own_addr(net)) & 1)
break;
}
}
void tipc_bcast_inc_bearer_dst_cnt(struct net *net, int bearer_id)
{
struct tipc_bc_base *bb = tipc_bc_base(net);
tipc_bcast_lock(net);
bb->dests[bearer_id]++;
tipc_bcbase_select_primary(net);
tipc_bcast_unlock(net);
}
void tipc_bcast_dec_bearer_dst_cnt(struct net *net, int bearer_id)
{
struct tipc_bc_base *bb = tipc_bc_base(net);
tipc_bcast_lock(net);
bb->dests[bearer_id]--;
tipc_bcbase_select_primary(net);
tipc_bcast_unlock(net);
}
static void tipc_bcbase_xmit(struct net *net, struct sk_buff_head *xmitq)
{
int bearer_id;
struct tipc_bc_base *bb = tipc_bc_base(net);
struct sk_buff *skb, *_skb;
struct sk_buff_head _xmitq;
if (skb_queue_empty(xmitq))
return;
bearer_id = bb->primary_bearer;
if (bearer_id >= 0) {
tipc_bearer_bc_xmit(net, bearer_id, xmitq);
return;
}
skb_queue_head_init(&_xmitq);
for (bearer_id = 0; bearer_id < MAX_BEARERS; bearer_id++) {
if (!bb->dests[bearer_id])
continue;
skb_queue_walk(xmitq, skb) {
_skb = pskb_copy_for_clone(skb, GFP_ATOMIC);
if (!_skb)
break;
__skb_queue_tail(&_xmitq, _skb);
}
tipc_bearer_bc_xmit(net, bearer_id, &_xmitq);
}
__skb_queue_purge(xmitq);
__skb_queue_purge(&_xmitq);
}
int tipc_bcast_xmit(struct net *net, struct sk_buff_head *list)
{
struct tipc_link *l = tipc_bc_sndlink(net);
struct sk_buff_head xmitq, inputq, rcvq;
int rc = 0;
__skb_queue_head_init(&rcvq);
__skb_queue_head_init(&xmitq);
skb_queue_head_init(&inputq);
if (unlikely(!tipc_msg_reassemble(list, &rcvq)))
return -EHOSTUNREACH;
tipc_bcast_lock(net);
if (tipc_link_bc_peers(l))
rc = tipc_link_xmit(l, list, &xmitq);
tipc_bcast_unlock(net);
if (unlikely(rc)) {
__skb_queue_purge(&rcvq);
return rc;
}
tipc_bcbase_xmit(net, &xmitq);
tipc_sk_mcast_rcv(net, &rcvq, &inputq);
__skb_queue_purge(list);
return 0;
}
int tipc_bcast_rcv(struct net *net, struct tipc_link *l, struct sk_buff *skb)
{
struct tipc_msg *hdr = buf_msg(skb);
struct sk_buff_head *inputq = &tipc_bc_base(net)->inputq;
struct sk_buff_head xmitq;
int rc;
__skb_queue_head_init(&xmitq);
if (msg_mc_netid(hdr) != tipc_netid(net) || !tipc_link_is_up(l)) {
kfree_skb(skb);
return 0;
}
tipc_bcast_lock(net);
if (msg_user(hdr) == BCAST_PROTOCOL)
rc = tipc_link_bc_nack_rcv(l, skb, &xmitq);
else
rc = tipc_link_rcv(l, skb, NULL);
tipc_bcast_unlock(net);
tipc_bcbase_xmit(net, &xmitq);
if (!skb_queue_empty(inputq))
tipc_sk_rcv(net, inputq);
return rc;
}
void tipc_bcast_ack_rcv(struct net *net, struct tipc_link *l, u32 acked)
{
struct sk_buff_head *inputq = &tipc_bc_base(net)->inputq;
struct sk_buff_head xmitq;
__skb_queue_head_init(&xmitq);
tipc_bcast_lock(net);
tipc_link_bc_ack_rcv(l, acked, &xmitq);
tipc_bcast_unlock(net);
tipc_bcbase_xmit(net, &xmitq);
if (!skb_queue_empty(inputq))
tipc_sk_rcv(net, inputq);
}
void tipc_bcast_sync_rcv(struct net *net, struct tipc_link *l,
struct tipc_msg *hdr)
{
struct sk_buff_head *inputq = &tipc_bc_base(net)->inputq;
struct sk_buff_head xmitq;
__skb_queue_head_init(&xmitq);
tipc_bcast_lock(net);
if (msg_type(hdr) == STATE_MSG) {
tipc_link_bc_ack_rcv(l, msg_bcast_ack(hdr), &xmitq);
tipc_link_bc_sync_rcv(l, hdr, &xmitq);
} else {
tipc_link_bc_init_rcv(l, hdr);
}
tipc_bcast_unlock(net);
tipc_bcbase_xmit(net, &xmitq);
if (!skb_queue_empty(inputq))
tipc_sk_rcv(net, inputq);
}
void tipc_bcast_add_peer(struct net *net, struct tipc_link *uc_l,
struct sk_buff_head *xmitq)
{
struct tipc_link *snd_l = tipc_bc_sndlink(net);
tipc_bcast_lock(net);
tipc_link_add_bc_peer(snd_l, uc_l, xmitq);
tipc_bcbase_select_primary(net);
tipc_bcast_unlock(net);
}
void tipc_bcast_remove_peer(struct net *net, struct tipc_link *rcv_l)
{
struct tipc_link *snd_l = tipc_bc_sndlink(net);
struct sk_buff_head *inputq = &tipc_bc_base(net)->inputq;
struct sk_buff_head xmitq;
__skb_queue_head_init(&xmitq);
tipc_bcast_lock(net);
tipc_link_remove_bc_peer(snd_l, rcv_l, &xmitq);
tipc_bcbase_select_primary(net);
tipc_bcast_unlock(net);
tipc_bcbase_xmit(net, &xmitq);
if (!skb_queue_empty(inputq))
tipc_sk_rcv(net, inputq);
}
int tipc_bclink_reset_stats(struct net *net)
{
struct tipc_link *l = tipc_bc_sndlink(net);
if (!l)
return -ENOPROTOOPT;
tipc_bcast_lock(net);
tipc_link_reset_stats(l);
tipc_bcast_unlock(net);
return 0;
}
static int tipc_bc_link_set_queue_limits(struct net *net, u32 limit)
{
struct tipc_link *l = tipc_bc_sndlink(net);
if (!l)
return -ENOPROTOOPT;
if (limit < BCLINK_WIN_MIN)
limit = BCLINK_WIN_MIN;
if (limit > TIPC_MAX_LINK_WIN)
return -EINVAL;
tipc_bcast_lock(net);
tipc_link_set_queue_limits(l, limit);
tipc_bcast_unlock(net);
return 0;
}
int tipc_nl_bc_link_set(struct net *net, struct nlattr *attrs[])
{
int err;
u32 win;
struct nlattr *props[TIPC_NLA_PROP_MAX + 1];
if (!attrs[TIPC_NLA_LINK_PROP])
return -EINVAL;
err = tipc_nl_parse_link_prop(attrs[TIPC_NLA_LINK_PROP], props);
if (err)
return err;
if (!props[TIPC_NLA_PROP_WIN])
return -EOPNOTSUPP;
win = nla_get_u32(props[TIPC_NLA_PROP_WIN]);
return tipc_bc_link_set_queue_limits(net, win);
}
int tipc_bcast_init(struct net *net)
{
struct tipc_net *tn = tipc_net(net);
struct tipc_bc_base *bb = NULL;
struct tipc_link *l = NULL;
bb = kzalloc(sizeof(*bb), GFP_ATOMIC);
if (!bb)
goto enomem;
tn->bcbase = bb;
spin_lock_init(&tipc_net(net)->bclock);
if (!tipc_link_bc_create(net, 0, 0,
U16_MAX,
BCLINK_WIN_DEFAULT,
0,
&bb->inputq,
NULL,
NULL,
&l))
goto enomem;
bb->link = l;
tn->bcl = l;
return 0;
enomem:
kfree(bb);
kfree(l);
return -ENOMEM;
}
void tipc_bcast_stop(struct net *net)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
synchronize_net();
kfree(tn->bcbase);
kfree(tn->bcl);
}
