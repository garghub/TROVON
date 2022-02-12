static struct sk_buff *tipc_disc_init_msg(u32 type, u32 dest_domain,
struct tipc_bearer *b_ptr)
{
struct sk_buff *buf = tipc_buf_acquire(INT_H_SIZE);
struct tipc_msg *msg;
if (buf) {
msg = buf_msg(buf);
tipc_msg_init(msg, LINK_CONFIG, type, INT_H_SIZE, dest_domain);
msg_set_non_seq(msg, 1);
msg_set_node_sig(msg, tipc_random);
msg_set_dest_domain(msg, dest_domain);
msg_set_bc_netid(msg, tipc_net_id);
b_ptr->media->addr2msg(&b_ptr->addr, msg_media_addr(msg));
}
return buf;
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
void tipc_disc_recv_msg(struct sk_buff *buf, struct tipc_bearer *b_ptr)
{
struct tipc_node *n_ptr;
struct tipc_link *link;
struct tipc_media_addr media_addr;
struct sk_buff *rbuf;
struct tipc_msg *msg = buf_msg(buf);
u32 dest = msg_dest_domain(msg);
u32 orig = msg_prevnode(msg);
u32 net_id = msg_bc_netid(msg);
u32 type = msg_type(msg);
u32 signature = msg_node_sig(msg);
int addr_mismatch;
int link_fully_up;
media_addr.broadcast = 1;
b_ptr->media->msg2addr(b_ptr, &media_addr, msg_media_addr(msg));
kfree_skb(buf);
if (net_id != tipc_net_id)
return;
if (media_addr.broadcast)
return;
if (!tipc_addr_domain_valid(dest))
return;
if (!tipc_addr_node_valid(orig))
return;
if (orig == tipc_own_addr) {
if (memcmp(&media_addr, &b_ptr->addr, sizeof(media_addr)))
disc_dupl_alert(b_ptr, tipc_own_addr, &media_addr);
return;
}
if (!tipc_in_scope(dest, tipc_own_addr))
return;
if (!tipc_in_scope(b_ptr->link_req->domain, orig))
return;
n_ptr = tipc_node_find(orig);
if (!n_ptr) {
n_ptr = tipc_node_create(orig);
if (!n_ptr)
return;
}
tipc_node_lock(n_ptr);
link = n_ptr->links[b_ptr->identity];
addr_mismatch = (link != NULL) &&
memcmp(&link->media_addr, &media_addr, sizeof(media_addr));
if (signature != n_ptr->signature) {
if (n_ptr->working_links == 0) {
struct tipc_link *curr_link;
int i;
for (i = 0; i < MAX_BEARERS; i++) {
curr_link = n_ptr->links[i];
if (curr_link) {
memset(&curr_link->media_addr, 0,
sizeof(media_addr));
tipc_link_reset(curr_link);
}
}
addr_mismatch = (link != NULL);
} else if (tipc_link_is_up(link) && !addr_mismatch) {
} else {
disc_dupl_alert(b_ptr, orig, &media_addr);
tipc_node_unlock(n_ptr);
return;
}
n_ptr->signature = signature;
}
if (addr_mismatch) {
if (tipc_link_is_up(link)) {
disc_dupl_alert(b_ptr, orig, &media_addr);
tipc_node_unlock(n_ptr);
return;
} else {
memcpy(&link->media_addr, &media_addr,
sizeof(media_addr));
tipc_link_reset(link);
}
}
if (!link) {
link = tipc_link_create(n_ptr, b_ptr, &media_addr);
if (!link) {
tipc_node_unlock(n_ptr);
return;
}
}
link_fully_up = link_working_working(link);
if ((type == DSC_REQ_MSG) && !link_fully_up) {
rbuf = tipc_disc_init_msg(DSC_RESP_MSG, orig, b_ptr);
if (rbuf) {
tipc_bearer_send(b_ptr, rbuf, &media_addr);
kfree_skb(rbuf);
}
}
tipc_node_unlock(n_ptr);
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
tipc_bearer_send(req->bearer, req->buf, &req->dest);
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
int tipc_disc_create(struct tipc_bearer *b_ptr, struct tipc_media_addr *dest,
u32 dest_domain)
{
struct tipc_link_req *req;
req = kmalloc(sizeof(*req), GFP_ATOMIC);
if (!req)
return -ENOMEM;
req->buf = tipc_disc_init_msg(DSC_REQ_MSG, dest_domain, b_ptr);
if (!req->buf) {
kfree(req);
return -ENOMSG;
}
memcpy(&req->dest, dest, sizeof(*dest));
req->bearer = b_ptr;
req->domain = dest_domain;
req->num_nodes = 0;
req->timer_intv = TIPC_LINK_REQ_INIT;
spin_lock_init(&req->lock);
k_init_timer(&req->timer, (Handler)disc_timeout, (unsigned long)req);
k_start_timer(&req->timer, req->timer_intv);
b_ptr->link_req = req;
tipc_bearer_send(req->bearer, req->buf, &req->dest);
return 0;
}
void tipc_disc_delete(struct tipc_link_req *req)
{
k_cancel_timer(&req->timer);
k_term_timer(&req->timer);
kfree_skb(req->buf);
kfree(req);
}
