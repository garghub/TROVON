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
struct sk_buff *buf = tipc_buf_acquire(INT_H_SIZE + size);
struct tipc_msg *msg;
if (buf != NULL) {
msg = buf_msg(buf);
tipc_msg_init(msg, NAME_DISTRIBUTOR, type, INT_H_SIZE, dest);
msg_set_size(msg, INT_H_SIZE + size);
}
return buf;
}
void named_cluster_distribute(struct sk_buff *buf)
{
struct sk_buff *obuf;
struct tipc_node *node;
u32 dnode;
rcu_read_lock();
list_for_each_entry_rcu(node, &tipc_node_list, list) {
dnode = node->addr;
if (in_own_node(dnode))
continue;
if (!tipc_node_active_links(node))
continue;
obuf = skb_copy(buf, GFP_ATOMIC);
if (!obuf)
break;
msg_set_destnode(buf_msg(obuf), dnode);
tipc_link_xmit(obuf, dnode, dnode);
}
rcu_read_unlock();
kfree_skb(buf);
}
struct sk_buff *tipc_named_publish(struct publication *publ)
{
struct sk_buff *buf;
struct distr_item *item;
list_add_tail(&publ->local_list, &publ_lists[publ->scope]->list);
publ_lists[publ->scope]->size++;
if (publ->scope == TIPC_NODE_SCOPE)
return NULL;
buf = named_prepare_buf(PUBLICATION, ITEM_SIZE, 0);
if (!buf) {
pr_warn("Publication distribution failure\n");
return NULL;
}
item = (struct distr_item *)msg_data(buf_msg(buf));
publ_to_item(item, publ);
return buf;
}
struct sk_buff *tipc_named_withdraw(struct publication *publ)
{
struct sk_buff *buf;
struct distr_item *item;
list_del(&publ->local_list);
publ_lists[publ->scope]->size--;
if (publ->scope == TIPC_NODE_SCOPE)
return NULL;
buf = named_prepare_buf(WITHDRAWAL, ITEM_SIZE, 0);
if (!buf) {
pr_warn("Withdrawal distribution failure\n");
return NULL;
}
item = (struct distr_item *)msg_data(buf_msg(buf));
publ_to_item(item, publ);
return buf;
}
static void named_distribute(struct list_head *msg_list, u32 dnode,
struct publ_list *pls)
{
struct publication *publ;
struct sk_buff *buf = NULL;
struct distr_item *item = NULL;
uint dsz = pls->size * ITEM_SIZE;
uint msg_dsz = (tipc_node_get_mtu(dnode, 0) / ITEM_SIZE) * ITEM_SIZE;
uint rem = dsz;
uint msg_rem = 0;
list_for_each_entry(publ, &pls->list, local_list) {
if (!buf) {
msg_rem = min_t(uint, rem, msg_dsz);
rem -= msg_rem;
buf = named_prepare_buf(PUBLICATION, msg_rem, dnode);
if (!buf) {
pr_warn("Bulk publication failure\n");
return;
}
item = (struct distr_item *)msg_data(buf_msg(buf));
}
publ_to_item(item, publ);
item++;
msg_rem -= ITEM_SIZE;
if (!msg_rem) {
list_add_tail((struct list_head *)buf, msg_list);
buf = NULL;
}
}
}
void tipc_named_node_up(u32 dnode)
{
LIST_HEAD(msg_list);
struct sk_buff *buf_chain;
read_lock_bh(&tipc_nametbl_lock);
named_distribute(&msg_list, dnode, &publ_cluster);
named_distribute(&msg_list, dnode, &publ_zone);
read_unlock_bh(&tipc_nametbl_lock);
buf_chain = (struct sk_buff *)msg_list.next;
((struct sk_buff *)msg_list.prev)->next = NULL;
tipc_link_xmit(buf_chain, dnode, dnode);
}
static void named_purge_publ(struct publication *publ)
{
struct publication *p;
write_lock_bh(&tipc_nametbl_lock);
p = tipc_nametbl_remove_publ(publ->type, publ->lower,
publ->node, publ->ref, publ->key);
if (p)
tipc_nodesub_unsubscribe(&p->subscr);
write_unlock_bh(&tipc_nametbl_lock);
if (p != publ) {
pr_err("Unable to remove publication from failed node\n"
" (type=%u, lower=%u, node=0x%x, ref=%u, key=%u)\n",
publ->type, publ->lower, publ->node, publ->ref,
publ->key);
}
kfree(p);
}
static bool tipc_update_nametbl(struct distr_item *i, u32 node, u32 dtype)
{
struct publication *publ = NULL;
if (dtype == PUBLICATION) {
publ = tipc_nametbl_insert_publ(ntohl(i->type), ntohl(i->lower),
ntohl(i->upper),
TIPC_CLUSTER_SCOPE, node,
ntohl(i->ref), ntohl(i->key));
if (publ) {
tipc_nodesub_subscribe(&publ->subscr, node, publ,
(net_ev_handler)
named_purge_publ);
return true;
}
} else if (dtype == WITHDRAWAL) {
publ = tipc_nametbl_remove_publ(ntohl(i->type), ntohl(i->lower),
node, ntohl(i->ref),
ntohl(i->key));
if (publ) {
tipc_nodesub_unsubscribe(&publ->subscr);
kfree(publ);
return true;
}
} else {
pr_warn("Unrecognized name table message received\n");
}
return false;
}
static void tipc_named_add_backlog(struct distr_item *i, u32 type, u32 node)
{
struct distr_queue_item *e;
unsigned long now = get_jiffies_64();
e = kzalloc(sizeof(*e), GFP_ATOMIC);
if (!e)
return;
e->dtype = type;
e->node = node;
e->expires = now + msecs_to_jiffies(sysctl_tipc_named_timeout);
memcpy(e, i, sizeof(*i));
list_add_tail(&e->next, &tipc_dist_queue);
}
void tipc_named_process_backlog(void)
{
struct distr_queue_item *e, *tmp;
char addr[16];
unsigned long now = get_jiffies_64();
list_for_each_entry_safe(e, tmp, &tipc_dist_queue, next) {
if (time_after(e->expires, now)) {
if (!tipc_update_nametbl(&e->i, e->node, e->dtype))
continue;
} else {
tipc_addr_string_fill(addr, e->node);
pr_warn_ratelimited("Dropping name table update (%d) of {%u, %u, %u} from %s key=%u\n",
e->dtype, ntohl(e->i.type),
ntohl(e->i.lower),
ntohl(e->i.upper),
addr, ntohl(e->i.key));
}
list_del(&e->next);
kfree(e);
}
}
void tipc_named_rcv(struct sk_buff *buf)
{
struct tipc_msg *msg = buf_msg(buf);
struct distr_item *item = (struct distr_item *)msg_data(msg);
u32 count = msg_data_sz(msg) / ITEM_SIZE;
u32 node = msg_orignode(msg);
write_lock_bh(&tipc_nametbl_lock);
while (count--) {
if (!tipc_update_nametbl(item, node, msg_type(msg)))
tipc_named_add_backlog(item, msg_type(msg), node);
item++;
}
tipc_named_process_backlog();
write_unlock_bh(&tipc_nametbl_lock);
kfree_skb(buf);
}
void tipc_named_reinit(void)
{
struct publication *publ;
int scope;
write_lock_bh(&tipc_nametbl_lock);
for (scope = TIPC_ZONE_SCOPE; scope <= TIPC_NODE_SCOPE; scope++)
list_for_each_entry(publ, &publ_lists[scope]->list, local_list)
publ->node = tipc_own_addr;
write_unlock_bh(&tipc_nametbl_lock);
}
