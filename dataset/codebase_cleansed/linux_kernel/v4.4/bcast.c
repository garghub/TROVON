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
static int __tipc_nl_add_bc_link_stat(struct sk_buff *skb,
struct tipc_stats *stats)
{
int i;
struct nlattr *nest;
struct nla_map {
__u32 key;
__u32 val;
};
struct nla_map map[] = {
{TIPC_NLA_STATS_RX_INFO, stats->recv_info},
{TIPC_NLA_STATS_RX_FRAGMENTS, stats->recv_fragments},
{TIPC_NLA_STATS_RX_FRAGMENTED, stats->recv_fragmented},
{TIPC_NLA_STATS_RX_BUNDLES, stats->recv_bundles},
{TIPC_NLA_STATS_RX_BUNDLED, stats->recv_bundled},
{TIPC_NLA_STATS_TX_INFO, stats->sent_info},
{TIPC_NLA_STATS_TX_FRAGMENTS, stats->sent_fragments},
{TIPC_NLA_STATS_TX_FRAGMENTED, stats->sent_fragmented},
{TIPC_NLA_STATS_TX_BUNDLES, stats->sent_bundles},
{TIPC_NLA_STATS_TX_BUNDLED, stats->sent_bundled},
{TIPC_NLA_STATS_RX_NACKS, stats->recv_nacks},
{TIPC_NLA_STATS_RX_DEFERRED, stats->deferred_recv},
{TIPC_NLA_STATS_TX_NACKS, stats->sent_nacks},
{TIPC_NLA_STATS_TX_ACKS, stats->sent_acks},
{TIPC_NLA_STATS_RETRANSMITTED, stats->retransmitted},
{TIPC_NLA_STATS_DUPLICATES, stats->duplicates},
{TIPC_NLA_STATS_LINK_CONGS, stats->link_congs},
{TIPC_NLA_STATS_MAX_QUEUE, stats->max_queue_sz},
{TIPC_NLA_STATS_AVG_QUEUE, stats->queue_sz_counts ?
(stats->accu_queue_sz / stats->queue_sz_counts) : 0}
};
nest = nla_nest_start(skb, TIPC_NLA_LINK_STATS);
if (!nest)
return -EMSGSIZE;
for (i = 0; i < ARRAY_SIZE(map); i++)
if (nla_put_u32(skb, map[i].key, map[i].val))
goto msg_full;
nla_nest_end(skb, nest);
return 0;
msg_full:
nla_nest_cancel(skb, nest);
return -EMSGSIZE;
}
int tipc_nl_add_bc_link(struct net *net, struct tipc_nl_msg *msg)
{
int err;
void *hdr;
struct nlattr *attrs;
struct nlattr *prop;
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct tipc_link *bcl = tn->bcl;
if (!bcl)
return 0;
tipc_bcast_lock(net);
hdr = genlmsg_put(msg->skb, msg->portid, msg->seq, &tipc_genl_family,
NLM_F_MULTI, TIPC_NL_LINK_GET);
if (!hdr)
return -EMSGSIZE;
attrs = nla_nest_start(msg->skb, TIPC_NLA_LINK);
if (!attrs)
goto msg_full;
if (nla_put_flag(msg->skb, TIPC_NLA_LINK_UP))
goto attr_msg_full;
if (nla_put_flag(msg->skb, TIPC_NLA_LINK_BROADCAST))
goto attr_msg_full;
if (nla_put_string(msg->skb, TIPC_NLA_LINK_NAME, bcl->name))
goto attr_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_LINK_RX, bcl->rcv_nxt))
goto attr_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_LINK_TX, bcl->snd_nxt))
goto attr_msg_full;
prop = nla_nest_start(msg->skb, TIPC_NLA_LINK_PROP);
if (!prop)
goto attr_msg_full;
if (nla_put_u32(msg->skb, TIPC_NLA_PROP_WIN, bcl->window))
goto prop_msg_full;
nla_nest_end(msg->skb, prop);
err = __tipc_nl_add_bc_link_stat(msg->skb, &bcl->stats);
if (err)
goto attr_msg_full;
tipc_bcast_unlock(net);
nla_nest_end(msg->skb, attrs);
genlmsg_end(msg->skb, hdr);
return 0;
prop_msg_full:
nla_nest_cancel(msg->skb, prop);
attr_msg_full:
nla_nest_cancel(msg->skb, attrs);
msg_full:
tipc_bcast_unlock(net);
genlmsg_cancel(msg->skb, hdr);
return -EMSGSIZE;
}
int tipc_bclink_reset_stats(struct net *net)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct tipc_link *bcl = tn->bcl;
if (!bcl)
return -ENOPROTOOPT;
tipc_bcast_lock(net);
memset(&bcl->stats, 0, sizeof(bcl->stats));
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
void tipc_bcast_reinit(struct net *net)
{
struct tipc_bc_base *b = tipc_bc_base(net);
msg_set_prevnode(b->link->pmsg, tipc_own_addr(net));
}
void tipc_bcast_stop(struct net *net)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
synchronize_net();
kfree(tn->bcbase);
kfree(tn->bcl);
}
