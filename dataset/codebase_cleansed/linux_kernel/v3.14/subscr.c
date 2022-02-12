static u32 htohl(u32 in, int swap)
{
return swap ? swab32(in) : in;
}
static void subscr_send_event(struct tipc_subscription *sub, u32 found_lower,
u32 found_upper, u32 event, u32 port_ref,
u32 node)
{
struct tipc_subscriber *subscriber = sub->subscriber;
struct kvec msg_sect;
msg_sect.iov_base = (void *)&sub->evt;
msg_sect.iov_len = sizeof(struct tipc_event);
sub->evt.event = htohl(event, sub->swap);
sub->evt.found_lower = htohl(found_lower, sub->swap);
sub->evt.found_upper = htohl(found_upper, sub->swap);
sub->evt.port.ref = htohl(port_ref, sub->swap);
sub->evt.port.node = htohl(node, sub->swap);
tipc_conn_sendmsg(&topsrv, subscriber->conid, NULL, msg_sect.iov_base,
msg_sect.iov_len);
}
int tipc_subscr_overlap(struct tipc_subscription *sub, u32 found_lower,
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
void tipc_subscr_report_overlap(struct tipc_subscription *sub, u32 found_lower,
u32 found_upper, u32 event, u32 port_ref,
u32 node, int must)
{
if (!tipc_subscr_overlap(sub, found_lower, found_upper))
return;
if (!must && !(sub->filter & TIPC_SUB_PORTS))
return;
subscr_send_event(sub, found_lower, found_upper, event, port_ref, node);
}
static void subscr_timeout(struct tipc_subscription *sub)
{
struct tipc_subscriber *subscriber = sub->subscriber;
spin_lock_bh(&subscriber->lock);
if (sub->timeout == TIPC_WAIT_FOREVER) {
spin_unlock_bh(&subscriber->lock);
return;
}
tipc_nametbl_unsubscribe(sub);
list_del(&sub->subscription_list);
spin_unlock_bh(&subscriber->lock);
subscr_send_event(sub, sub->evt.s.seq.lower, sub->evt.s.seq.upper,
TIPC_SUBSCR_TIMEOUT, 0, 0);
k_term_timer(&sub->timer);
kfree(sub);
atomic_dec(&subscription_count);
}
static void subscr_del(struct tipc_subscription *sub)
{
tipc_nametbl_unsubscribe(sub);
list_del(&sub->subscription_list);
kfree(sub);
atomic_dec(&subscription_count);
}
static void subscr_terminate(struct tipc_subscriber *subscriber)
{
tipc_conn_terminate(&topsrv, subscriber->conid);
}
static void subscr_release(struct tipc_subscriber *subscriber)
{
struct tipc_subscription *sub;
struct tipc_subscription *sub_temp;
spin_lock_bh(&subscriber->lock);
list_for_each_entry_safe(sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if (sub->timeout != TIPC_WAIT_FOREVER) {
spin_unlock_bh(&subscriber->lock);
k_cancel_timer(&sub->timer);
k_term_timer(&sub->timer);
spin_lock_bh(&subscriber->lock);
}
subscr_del(sub);
}
spin_unlock_bh(&subscriber->lock);
kfree(subscriber);
}
static void subscr_cancel(struct tipc_subscr *s,
struct tipc_subscriber *subscriber)
{
struct tipc_subscription *sub;
struct tipc_subscription *sub_temp;
int found = 0;
list_for_each_entry_safe(sub, sub_temp, &subscriber->subscription_list,
subscription_list) {
if (!memcmp(s, &sub->evt.s, sizeof(struct tipc_subscr))) {
found = 1;
break;
}
}
if (!found)
return;
if (sub->timeout != TIPC_WAIT_FOREVER) {
sub->timeout = TIPC_WAIT_FOREVER;
spin_unlock_bh(&subscriber->lock);
k_cancel_timer(&sub->timer);
k_term_timer(&sub->timer);
spin_lock_bh(&subscriber->lock);
}
subscr_del(sub);
}
static int subscr_subscribe(struct tipc_subscr *s,
struct tipc_subscriber *subscriber,
struct tipc_subscription **sub_p) {
struct tipc_subscription *sub;
int swap;
swap = !(s->filter & (TIPC_SUB_PORTS | TIPC_SUB_SERVICE));
if (s->filter & htohl(TIPC_SUB_CANCEL, swap)) {
s->filter &= ~htohl(TIPC_SUB_CANCEL, swap);
subscr_cancel(s, subscriber);
return 0;
}
if (atomic_read(&subscription_count) >= TIPC_MAX_SUBSCRIPTIONS) {
pr_warn("Subscription rejected, limit reached (%u)\n",
TIPC_MAX_SUBSCRIPTIONS);
return -EINVAL;
}
sub = kmalloc(sizeof(*sub), GFP_ATOMIC);
if (!sub) {
pr_warn("Subscription rejected, no memory\n");
return -ENOMEM;
}
sub->seq.type = htohl(s->seq.type, swap);
sub->seq.lower = htohl(s->seq.lower, swap);
sub->seq.upper = htohl(s->seq.upper, swap);
sub->timeout = htohl(s->timeout, swap);
sub->filter = htohl(s->filter, swap);
if ((!(sub->filter & TIPC_SUB_PORTS) ==
!(sub->filter & TIPC_SUB_SERVICE)) ||
(sub->seq.lower > sub->seq.upper)) {
pr_warn("Subscription rejected, illegal request\n");
kfree(sub);
return -EINVAL;
}
INIT_LIST_HEAD(&sub->nameseq_list);
list_add(&sub->subscription_list, &subscriber->subscription_list);
sub->subscriber = subscriber;
sub->swap = swap;
memcpy(&sub->evt.s, s, sizeof(struct tipc_subscr));
atomic_inc(&subscription_count);
if (sub->timeout != TIPC_WAIT_FOREVER) {
k_init_timer(&sub->timer,
(Handler)subscr_timeout, (unsigned long)sub);
k_start_timer(&sub->timer, sub->timeout);
}
*sub_p = sub;
return 0;
}
static void subscr_conn_shutdown_event(int conid, void *usr_data)
{
subscr_release((struct tipc_subscriber *)usr_data);
}
static void subscr_conn_msg_event(int conid, struct sockaddr_tipc *addr,
void *usr_data, void *buf, size_t len)
{
struct tipc_subscriber *subscriber = usr_data;
struct tipc_subscription *sub = NULL;
spin_lock_bh(&subscriber->lock);
if (subscr_subscribe((struct tipc_subscr *)buf, subscriber, &sub) < 0) {
spin_unlock_bh(&subscriber->lock);
subscr_terminate(subscriber);
return;
}
if (sub)
tipc_nametbl_subscribe(sub);
spin_unlock_bh(&subscriber->lock);
}
static void *subscr_named_msg_event(int conid)
{
struct tipc_subscriber *subscriber;
subscriber = kzalloc(sizeof(struct tipc_subscriber), GFP_ATOMIC);
if (subscriber == NULL) {
pr_warn("Subscriber rejected, no memory\n");
return NULL;
}
INIT_LIST_HEAD(&subscriber->subscription_list);
subscriber->conid = conid;
spin_lock_init(&subscriber->lock);
return (void *)subscriber;
}
int tipc_subscr_start(void)
{
return tipc_server_start(&topsrv);
}
void tipc_subscr_stop(void)
{
tipc_server_stop(&topsrv);
}
