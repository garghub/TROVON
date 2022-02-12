static struct sk_buff *tipc_disc_init_msg(u32 type,
u32 dest_domain,
struct tipc_bearer *b_ptr)
{
struct sk_buff *buf = tipc_buf_acquire(INT_H_SIZE);
struct tipc_msg *msg;
if (buf) {
msg = buf_msg(buf);
tipc_msg_init(msg, LINK_CONFIG, type, INT_H_SIZE, dest_domain);
msg_set_non_seq(msg, 1);
msg_set_dest_domain(msg, dest_domain);
msg_set_bc_netid(msg, tipc_net_id);
msg_set_media_addr(msg, &b_ptr->addr);
}
return buf;
}
static void disc_dupl_alert(struct tipc_bearer *b_ptr, u32 node_addr,
struct tipc_media_addr *media_addr)
{
char node_addr_str[16];
char media_addr_str[64];
struct print_buf pb;
tipc_addr_string_fill(node_addr_str, node_addr);
tipc_printbuf_init(&pb, media_addr_str, sizeof(media_addr_str));
tipc_media_addr_printf(&pb, media_addr);
tipc_printbuf_validate(&pb);
warn("Duplicate %s using %s seen on <%s>\n",
node_addr_str, media_addr_str, b_ptr->name);
}
void tipc_disc_recv_msg(struct sk_buff *buf, struct tipc_bearer *b_ptr)
{
struct tipc_node *n_ptr;
struct link *link;
struct tipc_media_addr media_addr, *addr;
struct sk_buff *rbuf;
struct tipc_msg *msg = buf_msg(buf);
u32 dest = msg_dest_domain(msg);
u32 orig = msg_prevnode(msg);
u32 net_id = msg_bc_netid(msg);
u32 type = msg_type(msg);
int link_fully_up;
msg_get_media_addr(msg, &media_addr);
buf_discard(buf);
if (net_id != tipc_net_id)
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
if (!link) {
link = tipc_link_create(n_ptr, b_ptr, &media_addr);
if (!link) {
tipc_node_unlock(n_ptr);
return;
}
}
addr = &link->media_addr;
if (memcmp(addr, &media_addr, sizeof(*addr))) {
if (tipc_link_is_up(link) || (!link->started)) {
disc_dupl_alert(b_ptr, orig, &media_addr);
tipc_node_unlock(n_ptr);
return;
}
warn("Resetting link <%s>, peer interface address changed\n",
link->name);
memcpy(addr, &media_addr, sizeof(*addr));
tipc_link_reset(link);
}
link_fully_up = link_working_working(link);
if ((type == DSC_REQ_MSG) && !link_fully_up && !b_ptr->blocked) {
rbuf = tipc_disc_init_msg(DSC_RESP_MSG, orig, b_ptr);
if (rbuf) {
b_ptr->media->send_msg(rbuf, b_ptr, &media_addr);
buf_discard(rbuf);
}
}
tipc_node_unlock(n_ptr);
}
static void disc_update(struct link_req *req)
{
if (!req->num_nodes) {
if ((req->timer_intv == TIPC_LINK_REQ_INACTIVE) ||
(req->timer_intv > TIPC_LINK_REQ_FAST)) {
req->timer_intv = TIPC_LINK_REQ_INIT;
k_start_timer(&req->timer, req->timer_intv);
}
}
}
void tipc_disc_add_dest(struct link_req *req)
{
req->num_nodes++;
}
void tipc_disc_remove_dest(struct link_req *req)
{
req->num_nodes--;
disc_update(req);
}
static void disc_send_msg(struct link_req *req)
{
if (!req->bearer->blocked)
tipc_bearer_send(req->bearer, req->buf, &req->dest);
}
static void disc_timeout(struct link_req *req)
{
int max_delay;
spin_lock_bh(&req->bearer->lock);
if (tipc_node(req->domain) && req->num_nodes) {
req->timer_intv = TIPC_LINK_REQ_INACTIVE;
goto exit;
}
disc_send_msg(req);
req->timer_intv *= 2;
if (req->num_nodes)
max_delay = TIPC_LINK_REQ_SLOW;
else
max_delay = TIPC_LINK_REQ_FAST;
if (req->timer_intv > max_delay)
req->timer_intv = max_delay;
k_start_timer(&req->timer, req->timer_intv);
exit:
spin_unlock_bh(&req->bearer->lock);
}
int tipc_disc_create(struct tipc_bearer *b_ptr,
struct tipc_media_addr *dest, u32 dest_domain)
{
struct link_req *req;
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
k_init_timer(&req->timer, (Handler)disc_timeout, (unsigned long)req);
k_start_timer(&req->timer, req->timer_intv);
b_ptr->link_req = req;
disc_send_msg(req);
return 0;
}
void tipc_disc_delete(struct link_req *req)
{
k_cancel_timer(&req->timer);
k_term_timer(&req->timer);
buf_discard(req->buf);
kfree(req);
}
