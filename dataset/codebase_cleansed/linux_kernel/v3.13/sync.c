void sync_set_event(struct sync_object *event)
{
spin_lock_bh(&sync_lock);
complete(&event->comp);
if (event->multi_comp)
complete(event->multi_comp);
spin_unlock_bh(&sync_lock);
}
int sync_wait_on_multiple_events(struct sync_object **events,
unsigned count, unsigned timeout,
unsigned *index)
{
unsigned i;
int status = -EPERM;
struct completion m_comp;
init_completion(&m_comp);
if (SYNC_INFINITE == timeout)
timeout = MAX_SCHEDULE_TIMEOUT;
spin_lock_bh(&sync_lock);
for (i = 0; i < count; i++) {
if (completion_done(&events[i]->comp)) {
reinit_completion(&events[i]->comp);
*index = i;
spin_unlock_bh(&sync_lock);
status = 0;
goto func_end;
}
}
for (i = 0; i < count; i++)
events[i]->multi_comp = &m_comp;
spin_unlock_bh(&sync_lock);
if (!wait_for_completion_interruptible_timeout(&m_comp,
msecs_to_jiffies(timeout)))
status = -ETIME;
spin_lock_bh(&sync_lock);
for (i = 0; i < count; i++) {
if (completion_done(&events[i]->comp)) {
reinit_completion(&events[i]->comp);
*index = i;
status = 0;
}
events[i]->multi_comp = NULL;
}
spin_unlock_bh(&sync_lock);
func_end:
return status;
}
int dsp_notifier_event(struct notifier_block *this, unsigned long event,
void *data)
{
struct ntfy_event *ne = container_of(this, struct ntfy_event,
noti_block);
if (ne->event & event)
sync_set_event(&ne->sync_obj);
return NOTIFY_OK;
}
