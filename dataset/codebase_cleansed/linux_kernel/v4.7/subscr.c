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
int tipc_subscrp_check_overlap(struct tipc_name_seq *seq, u32 found_lower,
u32 found_upper)
{
if (found_lower < seq->lower)
found_lower = seq->lower;
if (found_upper > seq->upper)
found_upper = seq->upper;
if (found_lower > found_upper)
return 0;
return 1;
}
u32 tipc_subscrp_convert_seq_type(u32 type, int swap)
{
return htohl(type, swap);
}
void tipc_subscrp_convert_seq(struct tipc_name_seq *in, int swap,
struct tipc_name_seq *out)
{
out->type = htohl(in->type, swap);
out->lower = htohl(in->lower, swap);
out->upper = htohl(in->upper, swap);
}
void tipc_subscrp_report_overlap(struct tipc_subscription *sub, u32 found_lower,
u32 found_upper, u32 event, u32 port_ref,
u32 node, int must)
{
struct tipc_name_seq seq;
tipc_subscrp_convert_seq(&sub->evt.s.seq, sub->swap, &seq);
if (!tipc_subscrp_check_overlap(&seq, found_lower, found_upper))
return;
if (!must &&
!(htohl(sub->evt.s.filter, sub->swap) & TIPC_SUB_PORTS))
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
u32 timeout;
spin_lock_bh(&subscriber->lock);
list_for_each_entry_safe(sub, temp, &subscriber->subscrp_list,
subscrp_list) {
timeout = htohl(sub->evt.s.timeout, sub->swap);
if ((timeout == TIPC_WAIT_FOREVER) || del_timer(&sub->timer)) {
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
u32 timeout;
spin_lock_bh(&subscriber->lock);
list_for_each_entry_safe(sub, temp, &subscriber->subscrp_list,
subscrp_list) {
if (!memcmp(s, &sub->evt.s, sizeof(struct tipc_subscr))) {
timeout = htohl(sub->evt.s.timeout, sub->swap);
if ((timeout == TIPC_WAIT_FOREVER) ||
del_timer(&sub->timer)) {
tipc_subscrp_delete(sub);
tipc_subscrb_put(subscriber);
}
break;
}
}
spin_unlock_bh(&subscriber->lock);
}
static struct tipc_subscription *tipc_subscrp_create(struct net *net,
struct tipc_subscr *s,
int swap)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct tipc_subscription *sub;
u32 filter = htohl(s->filter, swap);
if (atomic_read(&tn->subscription_count) >= TIPC_MAX_SUBSCRIPTIONS) {
pr_warn("Subscription rejected, limit reached (%u)\n",
TIPC_MAX_SUBSCRIPTIONS);
return NULL;
}
sub = kmalloc(sizeof(*sub), GFP_ATOMIC);
if (!sub) {
pr_warn("Subscription rejected, no memory\n");
return NULL;
}
sub->net = net;
if (((filter & TIPC_SUB_PORTS) && (filter & TIPC_SUB_SERVICE)) ||
(htohl(s->seq.lower, swap) > htohl(s->seq.upper, swap))) {
pr_warn("Subscription rejected, illegal request\n");
kfree(sub);
return NULL;
}
sub->swap = swap;
memcpy(&sub->evt.s, s, sizeof(*s));
atomic_inc(&tn->subscription_count);
return sub;
}
static void tipc_subscrp_subscribe(struct net *net, struct tipc_subscr *s,
struct tipc_subscriber *subscriber, int swap)
{
struct tipc_net *tn = net_generic(net, tipc_net_id);
struct tipc_subscription *sub = NULL;
u32 timeout;
sub = tipc_subscrp_create(net, s, swap);
if (!sub)
return tipc_conn_terminate(tn->topsrv, subscriber->conid);
spin_lock_bh(&subscriber->lock);
list_add(&sub->subscrp_list, &subscriber->subscrp_list);
tipc_subscrb_get(subscriber);
sub->subscriber = subscriber;
tipc_nametbl_subscribe(sub);
spin_unlock_bh(&subscriber->lock);
timeout = htohl(sub->evt.s.timeout, swap);
if (timeout == TIPC_WAIT_FOREVER)
return;
setup_timer(&sub->timer, tipc_subscrp_timeout, (unsigned long)sub);
mod_timer(&sub->timer, jiffies + msecs_to_jiffies(timeout));
}
static void tipc_subscrb_release_cb(int conid, void *usr_data)
{
tipc_subscrb_delete((struct tipc_subscriber *)usr_data);
}
static void tipc_subscrb_rcv_cb(struct net *net, int conid,
struct sockaddr_tipc *addr, void *usr_data,
void *buf, size_t len)
{
struct tipc_subscriber *subscriber = usr_data;
struct tipc_subscr *s = (struct tipc_subscr *)buf;
int swap;
swap = !(s->filter & (TIPC_SUB_PORTS | TIPC_SUB_SERVICE |
TIPC_SUB_CANCEL));
if (s->filter & htohl(TIPC_SUB_CANCEL, swap)) {
s->filter &= ~htohl(TIPC_SUB_CANCEL, swap);
return tipc_subscrp_cancel(s, subscriber);
}
tipc_subscrp_subscribe(net, s, subscriber, swap);
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
topsrv->tipc_conn_release = tipc_subscrb_release_cb;
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
