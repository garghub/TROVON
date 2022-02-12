static void tipc_disc_init_msg(struct net *net, struct sk_buff *buf, u32 type,
struct tipc_bearer *b)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct tipc_msg *msg;
u32 dest_domain = b->domain;
msg = buf_msg(buf);
tipc_msg_init(tn->own_addr, msg, LINK_CONFIG, type,
MAX_H_SIZE, dest_domain);
msg_set_non_seq(msg, 1);
msg_set_node_sig(msg, tn->random);
msg_set_node_capabilities(msg, TIPC_NODE_CAPABILITIES);
msg_set_dest_domain(msg, dest_domain);
msg_set_bc_netid(msg, tn->net_id);
b->media->addr2msg(msg_media_addr(msg), &b->addr);
}
static void disc_dupl_alert(struct tipc_bearer *b, u32 node_addr,
struct tipc_media_addr *media_addr)
{
char node_addr_str[16];
char media_addr_str[64];
tipc_addr_string_fill(node_addr_str, node_addr);
tipc_media_addr_printf(media_addr_str, sizeof(media_addr_str),
media_addr);
pr_warn("Duplicate %s using %s seen on <%s>\n", node_addr_str,
media_addr_str, b->name);
}
void tipc_disc_rcv(struct net *net, struct sk_buff *skb,
struct tipc_bearer *bearer)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct tipc_media_addr maddr;
struct sk_buff *rskb;
struct tipc_msg *hdr = buf_msg(skb);
u32 ddom = msg_dest_domain(hdr);
u32 onode = msg_prevnode(hdr);
u32 net_id = msg_bc_netid(hdr);
u32 mtyp = msg_type(hdr);
u32 signature = msg_node_sig(hdr);
u16 caps = msg_node_capabilities(hdr);
bool respond = false;
bool dupl_addr = false;
int err;
err = bearer->media->msg2addr(bearer, &maddr, msg_media_addr(hdr));
kfree_skb(skb);
if (err)
return;
if (net_id != tn->net_id)
return;
if (maddr.broadcast)
return;
if (!tipc_addr_domain_valid(ddom))
return;
if (!tipc_addr_node_valid(onode))
return;
if (in_own_node(net, onode)) {
if (memcmp(&maddr, &bearer->addr, sizeof(maddr)))
disc_dupl_alert(bearer, tn->own_addr, &maddr);
return;
}
if (!tipc_in_scope(ddom, tn->own_addr))
return;
if (!tipc_in_scope(bearer->domain, onode))
return;
tipc_node_check_dest(net, onode, bearer, caps, signature,
&maddr, &respond, &dupl_addr);
if (dupl_addr)
disc_dupl_alert(bearer, onode, &maddr);
if (respond && (mtyp == DSC_REQ_MSG)) {
rskb = tipc_buf_acquire(MAX_H_SIZE, GFP_ATOMIC);
if (!rskb)
return;
tipc_disc_init_msg(net, rskb, DSC_RESP_MSG, bearer);
tipc_bearer_xmit_skb(net, bearer->identity, rskb, &maddr);
}
}
static void disc_update(struct tipc_link_req *req)
{
if (!req->num_nodes) {
if ((req->timer_intv == TIPC_LINK_REQ_INACTIVE) ||
(req->timer_intv > TIPC_LINK_REQ_FAST)) {
req->timer_intv = TIPC_LINK_REQ_INIT;
mod_timer(&req->timer, jiffies + req->timer_intv);
}
}
}
void tipc_disc_add_dest(struct tipc_link_req *req)
{
spin_lock_bh(&req->lock);
req->num_nodes++;
spin_unlock_bh(&req->lock);
}
void tipc_disc_remove_dest(struct tipc_link_req *req)
{
spin_lock_bh(&req->lock);
req->num_nodes--;
disc_update(req);
spin_unlock_bh(&req->lock);
}
static void disc_timeout(unsigned long data)
{
struct tipc_link_req *req = (struct tipc_link_req *)data;
struct sk_buff *skb;
int max_delay;
spin_lock_bh(&req->lock);
if (tipc_node(req->domain) && req->num_nodes) {
req->timer_intv = TIPC_LINK_REQ_INACTIVE;
goto exit;
}
skb = skb_clone(req->buf, GFP_ATOMIC);
if (skb)
tipc_bearer_xmit_skb(req->net, req->bearer_id, skb, &req->dest);
req->timer_intv *= 2;
if (req->num_nodes)
max_delay = TIPC_LINK_REQ_SLOW;
else
max_delay = TIPC_LINK_REQ_FAST;
if (req->timer_intv > max_delay)
req->timer_intv = max_delay;
mod_timer(&req->timer, jiffies + req->timer_intv);
exit:
spin_unlock_bh(&req->lock);
}
int tipc_disc_create(struct net *net, struct tipc_bearer *b,
struct tipc_media_addr *dest, struct sk_buff **skb)
{
struct tipc_link_req *req;
req = kmalloc(sizeof(*req), GFP_ATOMIC);
if (!req)
return -ENOMEM;
req->buf = tipc_buf_acquire(MAX_H_SIZE, GFP_ATOMIC);
if (!req->buf) {
kfree(req);
return -ENOMEM;
}
tipc_disc_init_msg(net, req->buf, DSC_REQ_MSG, b);
memcpy(&req->dest, dest, sizeof(*dest));
req->net = net;
req->bearer_id = b->identity;
req->domain = b->domain;
req->num_nodes = 0;
req->timer_intv = TIPC_LINK_REQ_INIT;
spin_lock_init(&req->lock);
setup_timer(&req->timer, disc_timeout, (unsigned long)req);
mod_timer(&req->timer, jiffies + req->timer_intv);
b->link_req = req;
*skb = skb_clone(req->buf, GFP_ATOMIC);
return 0;
}
void tipc_disc_delete(struct tipc_link_req *req)
{
del_timer_sync(&req->timer);
kfree_skb(req->buf);
kfree(req);
}
void tipc_disc_reset(struct net *net, struct tipc_bearer *b)
{
struct tipc_link_req *req = b->link_req;
struct sk_buff *skb;
spin_lock_bh(&req->lock);
tipc_disc_init_msg(net, req->buf, DSC_REQ_MSG, b);
req->net = net;
req->bearer_id = b->identity;
req->domain = b->domain;
req->num_nodes = 0;
req->timer_intv = TIPC_LINK_REQ_INIT;
mod_timer(&req->timer, jiffies + req->timer_intv);
skb = skb_clone(req->buf, GFP_ATOMIC);
if (skb)
tipc_bearer_xmit_skb(net, req->bearer_id, skb, &req->dest);
spin_unlock_bh(&req->lock);
}
