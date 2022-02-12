void tipc_nodesub_subscribe(struct tipc_node_subscr *node_sub, u32 addr,
void *usr_handle, net_ev_handler handle_down)
{
if (in_own_node(addr)) {
node_sub->node = NULL;
return;
}
node_sub->node = tipc_node_find(addr);
if (!node_sub->node) {
pr_warn("Node subscription rejected, unknown node 0x%x\n",
addr);
return;
}
node_sub->handle_node_down = handle_down;
node_sub->usr_handle = usr_handle;
tipc_node_lock(node_sub->node);
list_add_tail(&node_sub->nodesub_list, &node_sub->node->nsub);
tipc_node_unlock(node_sub->node);
}
void tipc_nodesub_unsubscribe(struct tipc_node_subscr *node_sub)
{
if (!node_sub->node)
return;
tipc_node_lock(node_sub->node);
list_del_init(&node_sub->nodesub_list);
tipc_node_unlock(node_sub->node);
}
void tipc_nodesub_notify(struct list_head *nsub_list)
{
struct tipc_node_subscr *ns, *safe;
net_ev_handler handle_node_down;
list_for_each_entry_safe(ns, safe, nsub_list, nodesub_list) {
handle_node_down = ns->handle_node_down;
if (handle_node_down) {
ns->handle_node_down = NULL;
handle_node_down(ns->usr_handle);
}
}
}
