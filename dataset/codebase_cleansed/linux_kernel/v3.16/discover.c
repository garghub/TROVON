static void tipc_disc_init_msg(struct sk_buff *buf, u32 type,
struct tipc_bearer *b_ptr)
{
struct tipc_msg *msg;
u32 dest_domain = b_ptr->domain;
msg = buf_msg(buf);
tipc_msg_init(msg, LINK_CONFIG, type, INT_H_SIZE, dest_domain);
msg_set_non_seq(msg, 1);
msg_set_node_sig(msg, tipc_random);
msg_set_dest_domain(msg, dest_domain);
msg_set_bc_netid(msg, tipc_net_id);
b_ptr->media->addr2msg(msg_media_addr(msg), &b_ptr->addr);
}
static void disc_dupl_alert(struct tipc_bearer *b_ptr, u32 node_addr,
struct tipc_media_addr *media_addr)
{
char node_addr_str[16];
char media_addr_str[64];
tipc_addr_string_fill(node_addr_str, node_addr);
tipc_media_addr_printf(media_addr_str, sizeof(media_addr_str),
media_addr);
pr_warn("Duplicate %s using %s seen on <%s>\n", node_addr_str,
media_addr_str, b_ptr->name);
}
void tipc_disc_rcv(struct sk_buff *buf, struct tipc_bearer *bearer)
{
struct tipc_node *node;
struct tipc_link *link;
struct tipc_media_addr maddr;
struct sk_buff *rbuf;
struct tipc_msg *msg = buf_msg(buf);
u32 ddom = msg_dest_domain(msg);
u32 onode = msg_prevnode(msg);
u32 net_id = msg_bc_netid(msg);
u32 mtyp = msg_type(msg);
u32 signature = msg_node_sig(msg);
bool addr_match = false;
bool sign_match = false;
bool link_up = false;
bool accept_addr = false;
bool accept_sign = false;
bool respond = false;
bearer->media->msg2addr(bearer, &maddr, msg_media_addr(msg));
kfree_skb(buf);
if (net_id != tipc_net_id)
return;
if (maddr.broadcast)
return;
if (!tipc_addr_domain_valid(ddom))
return;
if (!tipc_addr_node_valid(onode))
return;
if (in_own_node(onode)) {
if (memcmp(&maddr, &bearer->addr, sizeof(maddr)))
disc_dupl_alert(bearer, tipc_own_addr, &maddr);
return;
}
if (!tipc_in_scope(ddom, tipc_own_addr))
return;
if (!tipc_in_scope(bearer->domain, onode))
return;
node = tipc_node_find(onode);
if (!node)
node = tipc_node_create(onode);
if (!node)
return;
tipc_node_lock(node);
link = node->links[bearer->identity];
sign_match = (signature == node->signature);
addr_match = link && !memcmp(&link->media_addr, &maddr, sizeof(maddr));
link_up = link && tipc_link_is_up(link);
if (sign_match && addr_match && link_up) {
} else if (sign_match && addr_match && !link_up) {
respond = true;
} else if (sign_match && !addr_match && link_up) {
disc_dupl_alert(bearer, onode, &maddr);
} else if (sign_match && !addr_match && !link_up) {
accept_addr = true;
respond = true;
} else if (!sign_match && addr_match && link_up) {
accept_sign = true;
} else if (!sign_match && addr_match && !link_up) {
accept_sign = true;
respond = true;
} else if (!sign_match && !addr_match && link_up) {
disc_dupl_alert(bearer, onode, &maddr);
} else if (!sign_match && !addr_match && !link_up) {
accept_sign = true;
accept_addr = true;
respond = true;
}
if (accept_sign)
node->signature = signature;
if (accept_addr) {
if (!link)
link = tipc_link_create(node, bearer, &maddr);
if (link) {
memcpy(&link->media_addr, &maddr, sizeof(maddr));
tipc_link_reset(link);
} else {
respond = false;
}
}
if (respond && (mtyp == DSC_REQ_MSG)) {
rbuf = tipc_buf_acquire(INT_H_SIZE);
if (rbuf) {
tipc_disc_init_msg(rbuf, DSC_RESP_MSG, bearer);
tipc_bearer_send(bearer->identity, rbuf, &maddr);
kfree_skb(rbuf);
}
}
tipc_node_unlock(node);
}
static void disc_update(struct tipc_link_req *req)
{
if (!req->num_nodes) {
if ((req->timer_intv == TIPC_LINK_REQ_INACTIVE) ||
(req->timer_intv > TIPC_LINK_REQ_FAST)) {
req->timer_intv = TIPC_LINK_REQ_INIT;
k_start_timer(&req->timer, req->timer_intv);
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
static void disc_timeout(struct tipc_link_req *req)
{
int max_delay;
spin_lock_bh(&req->lock);
if (tipc_node(req->domain) && req->num_nodes) {
req->timer_intv = TIPC_LINK_REQ_INACTIVE;
goto exit;
}
tipc_bearer_send(req->bearer_id, req->buf, &req->dest);
req->timer_intv *= 2;
if (req->num_nodes)
max_delay = TIPC_LINK_REQ_SLOW;
else
max_delay = TIPC_LINK_REQ_FAST;
if (req->timer_intv > max_delay)
req->timer_intv = max_delay;
k_start_timer(&req->timer, req->timer_intv);
exit:
spin_unlock_bh(&req->lock);
}
int tipc_disc_create(struct tipc_bearer *b_ptr, struct tipc_media_addr *dest)
{
struct tipc_link_req *req;
req = kmalloc(sizeof(*req), GFP_ATOMIC);
if (!req)
return -ENOMEM;
req->buf = tipc_buf_acquire(INT_H_SIZE);
if (!req->buf) {
kfree(req);
return -ENOMEM;
}
tipc_disc_init_msg(req->buf, DSC_REQ_MSG, b_ptr);
memcpy(&req->dest, dest, sizeof(*dest));
req->bearer_id = b_ptr->identity;
req->domain = b_ptr->domain;
req->num_nodes = 0;
req->timer_intv = TIPC_LINK_REQ_INIT;
spin_lock_init(&req->lock);
k_init_timer(&req->timer, (Handler)disc_timeout, (unsigned long)req);
k_start_timer(&req->timer, req->timer_intv);
b_ptr->link_req = req;
tipc_bearer_send(req->bearer_id, req->buf, &req->dest);
return 0;
}
void tipc_disc_delete(struct tipc_link_req *req)
{
k_cancel_timer(&req->timer);
k_term_timer(&req->timer);
kfree_skb(req->buf);
kfree(req);
}
void tipc_disc_reset(struct tipc_bearer *b_ptr)
{
struct tipc_link_req *req = b_ptr->link_req;
spin_lock_bh(&req->lock);
tipc_disc_init_msg(req->buf, DSC_REQ_MSG, b_ptr);
req->bearer_id = b_ptr->identity;
req->domain = b_ptr->domain;
req->num_nodes = 0;
req->timer_intv = TIPC_LINK_REQ_INIT;
k_start_timer(&req->timer, req->timer_intv);
tipc_bearer_send(req->bearer_id, req->buf, &req->dest);
spin_unlock_bh(&req->lock);
}
