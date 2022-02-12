static struct tipc_bc_base *tipc_bc_base(struct net *net)
{
return tipc_net(net)->bcbase;
}
int tipc_bcast_get_mtu(struct net *net)
{
return tipc_link_mtu(tipc_bc_sndlink(net)) - INT_H_SIZE;
}
void tipc_bcast_disable_rcast(struct net *net)
{
tipc_bc_base(net)->rcast_support = false;
}
static void tipc_bcbase_calc_bc_threshold(struct net *net)
{
struct tipc_bc_base *bb = tipc_bc_base(net);
int cluster_size = tipc_link_bc_peers(tipc_bc_sndlink(net));
bb->bc_threshold = 1 + (cluster_size * bb->rc_ratio / 100);
}
static void tipc_bcbase_select_primary(struct net *net)
{
struct tipc_bc_base *bb = tipc_bc_base(net);
int all_dests = tipc_link_bc_peers(bb->link);
int i, mtu, prim;
bb->primary_bearer = INVALID_BEARER_ID;
bb->bcast_support = true;
if (!all_dests)
return;
for (i = 0; i < MAX_BEARERS; i++) {
if (!bb->dests[i])
continue;
mtu = tipc_bearer_mtu(net, i);
if (mtu < tipc_link_mtu(bb->link))
tipc_link_set_mtu(bb->link, mtu);
bb->bcast_support &= tipc_bearer_bcast_support(net, i);
if (bb->dests[i] < all_dests)
continue;
bb->primary_bearer = i;
if ((i ^ tipc_own_addr(net)) & 1)
break;
}
prim = bb->primary_bearer;
if (prim != INVALID_BEARER_ID)
bb->bcast_support = tipc_bearer_bcast_support(net, prim);
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
static void tipc_bcast_select_xmit_method(struct net *net, int dests,
struct tipc_mc_method *method)
{
struct tipc_bc_base *bb = tipc_bc_base(net);
unsigned long exp = method->expires;
if (!bb->bcast_support) {
method->rcast = true;
return;
}
if (!bb->rcast_support) {
method->rcast = false;
return;
}
method->expires = jiffies + TIPC_METHOD_EXPIRE;
if (method->mandatory || time_before(jiffies, exp))
return;
method->rcast = dests <= bb->bc_threshold;
}
static int tipc_bcast_xmit(struct net *net, struct sk_buff_head *pkts,
u16 *cong_link_cnt)
{
struct tipc_link *l = tipc_bc_sndlink(net);
struct sk_buff_head xmitq;
int rc = 0;
__skb_queue_head_init(&xmitq);
tipc_bcast_lock(net);
if (tipc_link_bc_peers(l))
rc = tipc_link_xmit(l, pkts, &xmitq);
tipc_bcast_unlock(net);
tipc_bcbase_xmit(net, &xmitq);
__skb_queue_purge(pkts);
if (rc == -ELINKCONG) {
*cong_link_cnt = 1;
rc = 0;
}
return rc;
}
static int tipc_rcast_xmit(struct net *net, struct sk_buff_head *pkts,
struct tipc_nlist *dests, u16 *cong_link_cnt)
{
struct sk_buff_head _pkts;
struct u32_item *n, *tmp;
u32 dst, selector;
selector = msg_link_selector(buf_msg(skb_peek(pkts)));
__skb_queue_head_init(&_pkts);
list_for_each_entry_safe(n, tmp, &dests->list, list) {
dst = n->value;
if (!tipc_msg_pskb_copy(dst, pkts, &_pkts))
return -ENOMEM;
if (tipc_node_xmit(net, &_pkts, dst, selector) == -ELINKCONG)
(*cong_link_cnt)++;
}
return 0;
}
int tipc_mcast_xmit(struct net *net, struct sk_buff_head *pkts,
struct tipc_mc_method *method, struct tipc_nlist *dests,
u16 *cong_link_cnt)
{
struct sk_buff_head inputq, localq;
int rc = 0;
skb_queue_head_init(&inputq);
skb_queue_head_init(&localq);
if (dests->local && !tipc_msg_reassemble(pkts, &localq)) {
rc = -ENOMEM;
goto exit;
}
if (dests->remote) {
tipc_bcast_select_xmit_method(net, dests->remote, method);
if (method->rcast)
rc = tipc_rcast_xmit(net, pkts, dests, cong_link_cnt);
else
rc = tipc_bcast_xmit(net, pkts, cong_link_cnt);
}
if (dests->local)
tipc_sk_mcast_rcv(net, &localq, &inputq);
exit:
__skb_queue_purge(pkts);
return rc;
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
void tipc_bcast_ack_rcv(struct net *net, struct tipc_link *l,
struct tipc_msg *hdr)
{
struct sk_buff_head *inputq = &tipc_bc_base(net)->inputq;
u16 acked = msg_bcast_ack(hdr);
struct sk_buff_head xmitq;
if (msg_bc_ack_invalid(hdr))
return;
__skb_queue_head_init(&xmitq);
tipc_bcast_lock(net);
tipc_link_bc_ack_rcv(l, acked, &xmitq);
tipc_bcast_unlock(net);
tipc_bcbase_xmit(net, &xmitq);
if (!skb_queue_empty(inputq))
tipc_sk_rcv(net, inputq);
}
int tipc_bcast_sync_rcv(struct net *net, struct tipc_link *l,
struct tipc_msg *hdr)
{
struct sk_buff_head *inputq = &tipc_bc_base(net)->inputq;
struct sk_buff_head xmitq;
int rc = 0;
__skb_queue_head_init(&xmitq);
tipc_bcast_lock(net);
if (msg_type(hdr) != STATE_MSG) {
tipc_link_bc_init_rcv(l, hdr);
} else if (!msg_bc_ack_invalid(hdr)) {
tipc_link_bc_ack_rcv(l, msg_bcast_ack(hdr), &xmitq);
rc = tipc_link_bc_sync_rcv(l, hdr, &xmitq);
}
tipc_bcast_unlock(net);
tipc_bcbase_xmit(net, &xmitq);
if (!skb_queue_empty(inputq))
tipc_sk_rcv(net, inputq);
return rc;
}
void tipc_bcast_add_peer(struct net *net, struct tipc_link *uc_l,
struct sk_buff_head *xmitq)
{
struct tipc_link *snd_l = tipc_bc_sndlink(net);
tipc_bcast_lock(net);
tipc_link_add_bc_peer(snd_l, uc_l, xmitq);
tipc_bcbase_select_primary(net);
tipc_bcbase_calc_bc_threshold(net);
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
tipc_bcbase_calc_bc_threshold(net);
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
bb->rc_ratio = 25;
bb->rcast_support = true;
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
void tipc_nlist_init(struct tipc_nlist *nl, u32 self)
{
memset(nl, 0, sizeof(*nl));
INIT_LIST_HEAD(&nl->list);
nl->self = self;
}
void tipc_nlist_add(struct tipc_nlist *nl, u32 node)
{
if (node == nl->self)
nl->local = true;
else if (u32_push(&nl->list, node))
nl->remote++;
}
void tipc_nlist_del(struct tipc_nlist *nl, u32 node)
{
if (node == nl->self)
nl->local = false;
else if (u32_del(&nl->list, node))
nl->remote--;
}
void tipc_nlist_purge(struct tipc_nlist *nl)
{
u32_list_purge(&nl->list);
nl->remote = 0;
nl->local = 0;
}
