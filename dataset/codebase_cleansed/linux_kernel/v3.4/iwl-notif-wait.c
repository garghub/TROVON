void iwl_notification_wait_init(struct iwl_notif_wait_data *notif_wait)
{
spin_lock_init(&notif_wait->notif_wait_lock);
INIT_LIST_HEAD(&notif_wait->notif_waits);
init_waitqueue_head(&notif_wait->notif_waitq);
}
void iwl_notification_wait_notify(struct iwl_notif_wait_data *notif_wait,
struct iwl_rx_packet *pkt)
{
if (!list_empty(&notif_wait->notif_waits)) {
struct iwl_notification_wait *w;
spin_lock(&notif_wait->notif_wait_lock);
list_for_each_entry(w, &notif_wait->notif_waits, list) {
if (w->cmd != pkt->hdr.cmd)
continue;
w->triggered = true;
if (w->fn)
w->fn(notif_wait, pkt, w->fn_data);
}
spin_unlock(&notif_wait->notif_wait_lock);
wake_up_all(&notif_wait->notif_waitq);
}
}
void iwl_abort_notification_waits(struct iwl_notif_wait_data *notif_wait)
{
unsigned long flags;
struct iwl_notification_wait *wait_entry;
spin_lock_irqsave(&notif_wait->notif_wait_lock, flags);
list_for_each_entry(wait_entry, &notif_wait->notif_waits, list)
wait_entry->aborted = true;
spin_unlock_irqrestore(&notif_wait->notif_wait_lock, flags);
wake_up_all(&notif_wait->notif_waitq);
}
void
iwl_init_notification_wait(struct iwl_notif_wait_data *notif_wait,
struct iwl_notification_wait *wait_entry,
u8 cmd,
void (*fn)(struct iwl_notif_wait_data *notif_wait,
struct iwl_rx_packet *pkt, void *data),
void *fn_data)
{
wait_entry->fn = fn;
wait_entry->fn_data = fn_data;
wait_entry->cmd = cmd;
wait_entry->triggered = false;
wait_entry->aborted = false;
spin_lock_bh(&notif_wait->notif_wait_lock);
list_add(&wait_entry->list, &notif_wait->notif_waits);
spin_unlock_bh(&notif_wait->notif_wait_lock);
}
int iwl_wait_notification(struct iwl_notif_wait_data *notif_wait,
struct iwl_notification_wait *wait_entry,
unsigned long timeout)
{
int ret;
ret = wait_event_timeout(notif_wait->notif_waitq,
wait_entry->triggered || wait_entry->aborted,
timeout);
spin_lock_bh(&notif_wait->notif_wait_lock);
list_del(&wait_entry->list);
spin_unlock_bh(&notif_wait->notif_wait_lock);
if (wait_entry->aborted)
return -EIO;
if (ret <= 0)
return -ETIMEDOUT;
return 0;
}
void iwl_remove_notification(struct iwl_notif_wait_data *notif_wait,
struct iwl_notification_wait *wait_entry)
{
spin_lock_bh(&notif_wait->notif_wait_lock);
list_del(&wait_entry->list);
spin_unlock_bh(&notif_wait->notif_wait_lock);
}
