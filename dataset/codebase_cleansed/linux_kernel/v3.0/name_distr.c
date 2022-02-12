static void publ_to_item(struct distr_item *i, struct publication *p)
{
i->type = htonl(p->type);
i->lower = htonl(p->lower);
i->upper = htonl(p->upper);
i->ref = htonl(p->ref);
i->key = htonl(p->key);
}
static struct sk_buff *named_prepare_buf(u32 type, u32 size, u32 dest)
{
struct sk_buff *buf = tipc_buf_acquire(LONG_H_SIZE + size);
struct tipc_msg *msg;
if (buf != NULL) {
msg = buf_msg(buf);
tipc_msg_init(msg, NAME_DISTRIBUTOR, type, LONG_H_SIZE, dest);
msg_set_size(msg, LONG_H_SIZE + size);
}
return buf;
}
static void named_cluster_distribute(struct sk_buff *buf)
{
struct sk_buff *buf_copy;
struct tipc_node *n_ptr;
list_for_each_entry(n_ptr, &tipc_node_list, list) {
if (tipc_node_active_links(n_ptr)) {
buf_copy = skb_copy(buf, GFP_ATOMIC);
if (!buf_copy)
break;
msg_set_destnode(buf_msg(buf_copy), n_ptr->addr);
tipc_link_send(buf_copy, n_ptr->addr, n_ptr->addr);
}
}
buf_discard(buf);
}
void tipc_named_publish(struct publication *publ)
{
struct sk_buff *buf;
struct distr_item *item;
list_add_tail(&publ->local_list, &publ_root);
publ_cnt++;
buf = named_prepare_buf(PUBLICATION, ITEM_SIZE, 0);
if (!buf) {
warn("Publication distribution failure\n");
return;
}
item = (struct distr_item *)msg_data(buf_msg(buf));
publ_to_item(item, publ);
named_cluster_distribute(buf);
}
void tipc_named_withdraw(struct publication *publ)
{
struct sk_buff *buf;
struct distr_item *item;
list_del(&publ->local_list);
publ_cnt--;
buf = named_prepare_buf(WITHDRAWAL, ITEM_SIZE, 0);
if (!buf) {
warn("Withdrawal distribution failure\n");
return;
}
item = (struct distr_item *)msg_data(buf_msg(buf));
publ_to_item(item, publ);
named_cluster_distribute(buf);
}
void tipc_named_node_up(unsigned long node)
{
struct publication *publ;
struct distr_item *item = NULL;
struct sk_buff *buf = NULL;
u32 left = 0;
u32 rest;
u32 max_item_buf;
read_lock_bh(&tipc_nametbl_lock);
max_item_buf = TIPC_MAX_USER_MSG_SIZE / ITEM_SIZE;
max_item_buf *= ITEM_SIZE;
rest = publ_cnt * ITEM_SIZE;
list_for_each_entry(publ, &publ_root, local_list) {
if (!buf) {
left = (rest <= max_item_buf) ? rest : max_item_buf;
rest -= left;
buf = named_prepare_buf(PUBLICATION, left, node);
if (!buf) {
warn("Bulk publication distribution failure\n");
goto exit;
}
item = (struct distr_item *)msg_data(buf_msg(buf));
}
publ_to_item(item, publ);
item++;
left -= ITEM_SIZE;
if (!left) {
msg_set_link_selector(buf_msg(buf), node);
tipc_link_send(buf, node, node);
buf = NULL;
}
}
exit:
read_unlock_bh(&tipc_nametbl_lock);
}
static void named_purge_publ(struct publication *publ)
{
struct publication *p;
write_lock_bh(&tipc_nametbl_lock);
publ->key += 1222345;
p = tipc_nametbl_remove_publ(publ->type, publ->lower,
publ->node, publ->ref, publ->key);
if (p)
tipc_nodesub_unsubscribe(&p->subscr);
write_unlock_bh(&tipc_nametbl_lock);
if (p != publ) {
err("Unable to remove publication from failed node\n"
"(type=%u, lower=%u, node=0x%x, ref=%u, key=%u)\n",
publ->type, publ->lower, publ->node, publ->ref, publ->key);
}
kfree(p);
}
void tipc_named_recv(struct sk_buff *buf)
{
struct publication *publ;
struct tipc_msg *msg = buf_msg(buf);
struct distr_item *item = (struct distr_item *)msg_data(msg);
u32 count = msg_data_sz(msg) / ITEM_SIZE;
write_lock_bh(&tipc_nametbl_lock);
while (count--) {
if (msg_type(msg) == PUBLICATION) {
publ = tipc_nametbl_insert_publ(ntohl(item->type),
ntohl(item->lower),
ntohl(item->upper),
TIPC_CLUSTER_SCOPE,
msg_orignode(msg),
ntohl(item->ref),
ntohl(item->key));
if (publ) {
tipc_nodesub_subscribe(&publ->subscr,
msg_orignode(msg),
publ,
(net_ev_handler)
named_purge_publ);
}
} else if (msg_type(msg) == WITHDRAWAL) {
publ = tipc_nametbl_remove_publ(ntohl(item->type),
ntohl(item->lower),
msg_orignode(msg),
ntohl(item->ref),
ntohl(item->key));
if (publ) {
tipc_nodesub_unsubscribe(&publ->subscr);
kfree(publ);
} else {
err("Unable to remove publication by node 0x%x\n"
"(type=%u, lower=%u, ref=%u, key=%u)\n",
msg_orignode(msg),
ntohl(item->type), ntohl(item->lower),
ntohl(item->ref), ntohl(item->key));
}
} else {
warn("Unrecognized name table message received\n");
}
item++;
}
write_unlock_bh(&tipc_nametbl_lock);
buf_discard(buf);
}
void tipc_named_reinit(void)
{
struct publication *publ;
write_lock_bh(&tipc_nametbl_lock);
list_for_each_entry(publ, &publ_root, local_list) {
if (publ->node == tipc_own_addr)
break;
publ->node = tipc_own_addr;
}
write_unlock_bh(&tipc_nametbl_lock);
}
