void ax25_register_pid(struct ax25_protocol *ap)
{
write_lock_bh(&protocol_list_lock);
ap->next = protocol_list;
protocol_list = ap;
write_unlock_bh(&protocol_list_lock);
}
void ax25_protocol_release(unsigned int pid)
{
struct ax25_protocol *protocol;
write_lock_bh(&protocol_list_lock);
protocol = protocol_list;
if (protocol == NULL)
goto out;
if (protocol->pid == pid) {
protocol_list = protocol->next;
goto out;
}
while (protocol != NULL && protocol->next != NULL) {
if (protocol->next->pid == pid) {
protocol->next = protocol->next->next;
goto out;
}
protocol = protocol->next;
}
out:
write_unlock_bh(&protocol_list_lock);
}
void ax25_linkfail_register(struct ax25_linkfail *lf)
{
spin_lock_bh(&linkfail_lock);
hlist_add_head(&lf->lf_node, &ax25_linkfail_list);
spin_unlock_bh(&linkfail_lock);
}
void ax25_linkfail_release(struct ax25_linkfail *lf)
{
spin_lock_bh(&linkfail_lock);
hlist_del_init(&lf->lf_node);
spin_unlock_bh(&linkfail_lock);
}
int ax25_listen_register(ax25_address *callsign, struct net_device *dev)
{
struct listen_struct *listen;
if (ax25_listen_mine(callsign, dev))
return 0;
if ((listen = kmalloc(sizeof(*listen), GFP_ATOMIC)) == NULL)
return -ENOMEM;
listen->callsign = *callsign;
listen->dev = dev;
spin_lock_bh(&listen_lock);
listen->next = listen_list;
listen_list = listen;
spin_unlock_bh(&listen_lock);
return 0;
}
void ax25_listen_release(ax25_address *callsign, struct net_device *dev)
{
struct listen_struct *s, *listen;
spin_lock_bh(&listen_lock);
listen = listen_list;
if (listen == NULL) {
spin_unlock_bh(&listen_lock);
return;
}
if (ax25cmp(&listen->callsign, callsign) == 0 && listen->dev == dev) {
listen_list = listen->next;
spin_unlock_bh(&listen_lock);
kfree(listen);
return;
}
while (listen != NULL && listen->next != NULL) {
if (ax25cmp(&listen->next->callsign, callsign) == 0 && listen->next->dev == dev) {
s = listen->next;
listen->next = listen->next->next;
spin_unlock_bh(&listen_lock);
kfree(s);
return;
}
listen = listen->next;
}
spin_unlock_bh(&listen_lock);
}
void ax25_link_failed(ax25_cb *ax25, int reason)
{
struct ax25_linkfail *lf;
struct hlist_node *node;
spin_lock_bh(&linkfail_lock);
hlist_for_each_entry(lf, node, &ax25_linkfail_list, lf_node)
lf->func(ax25, reason);
spin_unlock_bh(&linkfail_lock);
}
int ax25_protocol_is_registered(unsigned int pid)
{
struct ax25_protocol *protocol;
int res = 0;
read_lock_bh(&protocol_list_lock);
for (protocol = protocol_list; protocol != NULL; protocol = protocol->next)
if (protocol->pid == pid) {
res = 1;
break;
}
read_unlock_bh(&protocol_list_lock);
return res;
}
