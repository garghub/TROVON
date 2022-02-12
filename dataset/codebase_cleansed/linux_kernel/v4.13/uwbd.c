static
int uwbd_event_handle_urc(struct uwb_event *evt)
{
int result = -EINVAL;
struct uwbd_evt_type_handler *type_table;
uwbd_evt_handler_f handler;
u8 type, context;
u16 event;
type = evt->notif.rceb->bEventType;
event = le16_to_cpu(evt->notif.rceb->wEvent);
context = evt->notif.rceb->bEventContext;
if (type >= ARRAY_SIZE(uwbd_urc_evt_type_handlers))
goto out;
type_table = &uwbd_urc_evt_type_handlers[type];
if (type_table->uwbd_events == NULL)
goto out;
if (event >= type_table->size)
goto out;
handler = type_table->uwbd_events[event].handler;
if (handler == NULL)
goto out;
result = (*handler)(evt);
out:
if (result < 0)
dev_err(&evt->rc->uwb_dev.dev,
"UWBD: event 0x%02x/%04x/%02x, handling failed: %d\n",
type, event, context, result);
return result;
}
static void uwbd_event_handle_message(struct uwb_event *evt)
{
struct uwb_rc *rc;
int result;
rc = evt->rc;
if (evt->message < 0 || evt->message >= ARRAY_SIZE(uwbd_message_handlers)) {
dev_err(&rc->uwb_dev.dev, "UWBD: invalid message type %d\n", evt->message);
return;
}
result = uwbd_message_handlers[evt->message].handler(evt);
if (result < 0)
dev_err(&rc->uwb_dev.dev, "UWBD: '%s' message failed: %d\n",
uwbd_message_handlers[evt->message].name, result);
}
static void uwbd_event_handle(struct uwb_event *evt)
{
struct uwb_rc *rc;
int should_keep;
rc = evt->rc;
if (rc->ready) {
switch (evt->type) {
case UWB_EVT_TYPE_NOTIF:
should_keep = uwbd_event_handle_urc(evt);
if (should_keep <= 0)
kfree(evt->notif.rceb);
break;
case UWB_EVT_TYPE_MSG:
uwbd_event_handle_message(evt);
break;
default:
dev_err(&rc->uwb_dev.dev, "UWBD: invalid event type %d\n", evt->type);
break;
}
}
__uwb_rc_put(rc);
}
static int uwbd(void *param)
{
struct uwb_rc *rc = param;
unsigned long flags;
struct uwb_event *evt;
int should_stop = 0;
while (1) {
wait_event_interruptible_timeout(
rc->uwbd.wq,
!list_empty(&rc->uwbd.event_list)
|| (should_stop = kthread_should_stop()),
HZ);
if (should_stop)
break;
spin_lock_irqsave(&rc->uwbd.event_list_lock, flags);
if (!list_empty(&rc->uwbd.event_list)) {
evt = list_first_entry(&rc->uwbd.event_list, struct uwb_event, list_node);
list_del(&evt->list_node);
} else
evt = NULL;
spin_unlock_irqrestore(&rc->uwbd.event_list_lock, flags);
if (evt) {
uwbd_event_handle(evt);
kfree(evt);
}
uwb_beca_purge(rc);
}
return 0;
}
void uwbd_start(struct uwb_rc *rc)
{
rc->uwbd.task = kthread_run(uwbd, rc, "uwbd");
if (rc->uwbd.task == NULL)
printk(KERN_ERR "UWB: Cannot start management daemon; "
"UWB won't work\n");
else
rc->uwbd.pid = rc->uwbd.task->pid;
}
void uwbd_stop(struct uwb_rc *rc)
{
kthread_stop(rc->uwbd.task);
uwbd_flush(rc);
}
void uwbd_event_queue(struct uwb_event *evt)
{
struct uwb_rc *rc = evt->rc;
unsigned long flags;
spin_lock_irqsave(&rc->uwbd.event_list_lock, flags);
if (rc->uwbd.pid != 0) {
list_add(&evt->list_node, &rc->uwbd.event_list);
wake_up_all(&rc->uwbd.wq);
} else {
__uwb_rc_put(evt->rc);
if (evt->type == UWB_EVT_TYPE_NOTIF)
kfree(evt->notif.rceb);
kfree(evt);
}
spin_unlock_irqrestore(&rc->uwbd.event_list_lock, flags);
return;
}
void uwbd_flush(struct uwb_rc *rc)
{
struct uwb_event *evt, *nxt;
spin_lock_irq(&rc->uwbd.event_list_lock);
list_for_each_entry_safe(evt, nxt, &rc->uwbd.event_list, list_node) {
if (evt->rc == rc) {
__uwb_rc_put(rc);
list_del(&evt->list_node);
if (evt->type == UWB_EVT_TYPE_NOTIF)
kfree(evt->notif.rceb);
kfree(evt);
}
}
spin_unlock_irq(&rc->uwbd.event_list_lock);
}
