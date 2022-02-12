static u32 htohl(u32 in, int swap)
{
return swap ? swab32(in) : in;
}
static void tipc_subscrp_send_event(struct tipc_subscription *sub,
u32 found_lower, u32 found_upper,
u32 event, u32 port_ref, u32 node)
{
struct tipc_net *tn = net_generic(sub->net, tipc_net_id);
struct tipc_subscriber *subscriber = sub->subscriber;
struct kvec msg_sect;
msg_sect.iov_base = (void *)&sub->evt;
msg_sect.iov_len = sizeof(struct tipc_event);
sub->evt.event = htohl(event, sub->swap);
sub->evt.found_lower = htohl(found_lower, sub->swap);
sub->evt.found_upper = htohl(found_upper, sub->swap);
sub->evt.port.ref = htohl(port_ref, sub->swap);
sub->evt.port.node = htohl(node, sub->swap);
tipc_conn_sendmsg(tn->topsrv, subscriber->conid, NULL,
msg_sect.iov_base, msg_sect.iov_len);
}
int tipc_subscrp_check_overlap(struct tipc_subscription *sub, u32 found_lower,
u32 found_upper)
{
if (found_lower < sub->seq.lower)
found_lower = sub->seq.lower;
if (found_upper > sub->seq.upper)
found_upper = sub->seq.upper;
if (found_lower > found_upper)
return 0;
return 1;
}
void tipc_subscrp_report_overlap(struct tipc_subscription *sub, u32 found_lower,
u32 found_upper, u32 event, u32 port_ref,
u32 node, int must)
{
if (!tipc_subscrp_check_overlap(sub, found_lower, found_upper))
return;
if (!must && !(sub->filter & TIPC_SUB_PORTS))
return;
tipc_subscrp_send_event(sub, found_lower, found_upper, event, port_ref,
node);
}
static void tipc_subscrp_timeout(unsigned long data)
{
struct tipc_subscription *sub = (struct tipc_subscription *)data;
struct tipc_subscriber *subscriber = sub->subscriber;
tipc_subscrp_send_event(sub, sub->evt.s.seq.lower, sub->evt.s.seq.upper,
TIPC_SUBSCR_TIMEOUT, 0, 0);
spin_lock_bh(&subscriber->lock);
tipc_subscrp_delete(sub);
spin_unlock_bh(&subscriber->lock);
tipc_subscrb_put(subscriber);
}
static void tipc_subscrb_kref_release(struct kref *kref)
{
struct tipc_subscriber *subcriber = container_of(kref,
struct tipc_subscriber, kref);
kfree(subcriber);
}
static void tipc_subscrb_put(struct tipc_subscriber *subscriber)
{
kref_put(&subscriber->kref, tipc_subscrb_kref_release);
}
static void tipc_subscrb_get(struct tipc_subscriber *subscriber)
{
kref_get(&subscriber->kref);
}
static struct tipc_subscriber *tipc_subscrb_create(int conid)
{
struct tipc_subscriber *subscriber;
subscriber = kzalloc(sizeof(*subscriber), GFP_ATOMIC);
if (!subscriber) {
pr_warn("Subscriber rejected, no memory\n");
return NULL;
}
kref_init(&subscriber->kref);
INIT_LIST_HEAD(&subscriber->subscrp_list);
subscriber->conid = conid;
spin_lock_init(&subscriber->lock);
return subscriber;
}
static void tipc_subscrb_delete(struct tipc_subscriber *subscriber)
{
struct tipc_subscription *sub, *temp;
spin_lock_bh(&subscriber->lock);
list_for_each_entry_safe(sub, temp, &subscriber->subscrp_list,
subscrp_list) {
if (del_timer(&sub->timer)) {
tipc_subscrp_delete(sub);
tipc_subscrb_put(subscriber);
}
}
spin_unlock_bh(&subscriber->lock);
tipc_subscrb_put(subscriber);
}
static void tipc_subscrp_delete(struct tipc_subscription *sub)
{
struct tipc_net *tn = net_generic(sub->net, tipc_net_id);
tipc_nametbl_unsubscribe(sub);
list_del(&sub->subscrp_list);
kfree(sub);
atomic_dec(&tn->subscription_count);
}
static void tipc_subscrp_cancel(struct tipc_subscr *s,
struct tipc_subscriber *subscriber)
{
struct tipc_subscription *sub, *temp;
spin_lock_bh(&subscriber->lock);
list_for_each_entry_safe(sub, temp, &subscriber->subscrp_list,
subscrp_list) {
if (!memcmp(s, &sub->evt.s, sizeof(struct tipc_subscr))) {
if (del_timer(&sub->timer)) {
tipc_subscrp_delete(sub);
tipc_subscrb_put(subscriber);
}
break;
}
}
spin_unlock_bh(&subscriber->lock);
}
static int tipc_subscrp_create(struct net *net, struct tipc_subscr *s,
struct tipc_subscriber *subscriber,
struct tipc_subscription **sub_p)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct tipc_subscription *sub;
int swap;
swap = !(s->filter & (TIPC_SUB_PORTS | TIPC_SUB_SERVICE));
if (s->filter & htohl(TIPC_SUB_CANCEL, swap)) {
s->filter &= ~htohl(TIPC_SUB_CANCEL, swap);
tipc_subscrp_cancel(s, subscriber);
return 0;
}
if (atomic_read(&tn->subscription_count) >= TIPC_MAX_SUBSCRIPTIONS) {
pr_warn("Subscription rejected, limit reached (%u)\n",
TIPC_MAX_SUBSCRIPTIONS);
return -EINVAL;
}
sub = kmalloc(sizeof(*sub), GFP_ATOMIC);
if (!sub) {
pr_warn("Subscription rejected, no memory\n");
return -ENOMEM;
}
sub->net = net;
sub->seq.type = htohl(s->seq.type, swap);
sub->seq.lower = htohl(s->seq.lower, swap);
sub->seq.upper = htohl(s->seq.upper, swap);
sub->timeout = msecs_to_jiffies(htohl(s->timeout, swap));
sub->filter = htohl(s->filter, swap);
if ((!(sub->filter & TIPC_SUB_PORTS) ==
!(sub->filter & TIPC_SUB_SERVICE)) ||
(sub->seq.lower > sub->seq.upper)) {
pr_warn("Subscription rejected, illegal request\n");
kfree(sub);
return -EINVAL;
}
spin_lock_bh(&subscriber->lock);
list_add(&sub->subscrp_list, &subscriber->subscrp_list);
spin_unlock_bh(&subscriber->lock);
sub->subscriber = subscriber;
sub->swap = swap;
memcpy(&sub->evt.s, s, sizeof(*s));
atomic_inc(&tn->subscription_count);
setup_timer(&sub->timer, tipc_subscrp_timeout, (unsigned long)sub);
if (sub->timeout != TIPC_WAIT_FOREVER)
sub->timeout += jiffies;
if (!mod_timer(&sub->timer, sub->timeout))
tipc_subscrb_get(subscriber);
*sub_p = sub;
return 0;
}
static void tipc_subscrb_shutdown_cb(int conid, void *usr_data)
{
tipc_subscrb_delete((struct tipc_subscriber *)usr_data);
}
static void tipc_subscrb_rcv_cb(struct net *net, int conid,
struct sockaddr_tipc *addr, void *usr_data,
void *buf, size_t len)
{
struct tipc_subscriber *subscriber = usr_data;
struct tipc_subscription *sub = NULL;
struct tipc_net *tn = net_generic(net, tipc_net_id);
tipc_subscrp_create(net, (struct tipc_subscr *)buf, subscriber, &sub);
if (sub)
tipc_nametbl_subscribe(sub);
else
tipc_conn_terminate(tn->topsrv, subscriber->conid);
}
static void *tipc_subscrb_connect_cb(int conid)
{
return (void *)tipc_subscrb_create(conid);
}
int tipc_topsrv_start(struct net *net)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
const char name[] = "topology_server";
struct tipc_server *topsrv;
struct sockaddr_tipc *saddr;
saddr = kzalloc(sizeof(*saddr), GFP_ATOMIC);
if (!saddr)
return -ENOMEM;
saddr->family = AF_TIPC;
saddr->addrtype = TIPC_ADDR_NAMESEQ;
saddr->addr.nameseq.type = TIPC_TOP_SRV;
saddr->addr.nameseq.lower = TIPC_TOP_SRV;
saddr->addr.nameseq.upper = TIPC_TOP_SRV;
saddr->scope = TIPC_NODE_SCOPE;
topsrv = kzalloc(sizeof(*topsrv), GFP_ATOMIC);
if (!topsrv) {
kfree(saddr);
return -ENOMEM;
}
topsrv->net = net;
topsrv->saddr = saddr;
topsrv->imp = TIPC_CRITICAL_IMPORTANCE;
topsrv->type = SOCK_SEQPACKET;
topsrv->max_rcvbuf_size = sizeof(struct tipc_subscr);
topsrv->tipc_conn_recvmsg = tipc_subscrb_rcv_cb;
topsrv->tipc_conn_new = tipc_subscrb_connect_cb;
topsrv->tipc_conn_shutdown = tipc_subscrb_shutdown_cb;
strncpy(topsrv->name, name, strlen(name) + 1);
tn->topsrv = topsrv;
atomic_set(&tn->subscription_count, 0);
return tipc_server_start(topsrv);
}
void tipc_topsrv_stop(struct net *net)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct tipc_server *topsrv = tn->topsrv;
tipc_server_stop(topsrv);
kfree(topsrv->saddr);
kfree(topsrv);
}
