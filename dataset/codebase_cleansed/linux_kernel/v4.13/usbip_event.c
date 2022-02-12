static void set_event(struct usbip_device *ud, unsigned long event)
{
unsigned long flags;
spin_lock_irqsave(&ud->lock, flags);
ud->event |= event;
spin_unlock_irqrestore(&ud->lock, flags);
}
static void unset_event(struct usbip_device *ud, unsigned long event)
{
unsigned long flags;
spin_lock_irqsave(&ud->lock, flags);
ud->event &= ~event;
spin_unlock_irqrestore(&ud->lock, flags);
}
static struct usbip_device *get_event(void)
{
struct usbip_event *ue = NULL;
struct usbip_device *ud = NULL;
unsigned long flags;
spin_lock_irqsave(&event_lock, flags);
if (!list_empty(&event_list)) {
ue = list_first_entry(&event_list, struct usbip_event, node);
list_del(&ue->node);
}
spin_unlock_irqrestore(&event_lock, flags);
if (ue) {
ud = ue->ud;
kfree(ue);
}
return ud;
}
static void event_handler(struct work_struct *work)
{
struct usbip_device *ud;
if (worker_context == NULL) {
worker_context = current;
}
while ((ud = get_event()) != NULL) {
usbip_dbg_eh("pending event %lx\n", ud->event);
if (ud->event & USBIP_EH_SHUTDOWN) {
ud->eh_ops.shutdown(ud);
unset_event(ud, USBIP_EH_SHUTDOWN);
}
if (ud->event & USBIP_EH_RESET) {
ud->eh_ops.reset(ud);
unset_event(ud, USBIP_EH_RESET);
}
if (ud->event & USBIP_EH_UNUSABLE) {
ud->eh_ops.unusable(ud);
unset_event(ud, USBIP_EH_UNUSABLE);
}
if (ud->event & USBIP_EH_BYE)
usbip_dbg_eh("removed %p\n", ud);
wake_up(&ud->eh_waitq);
}
}
int usbip_start_eh(struct usbip_device *ud)
{
init_waitqueue_head(&ud->eh_waitq);
ud->event = 0;
return 0;
}
void usbip_stop_eh(struct usbip_device *ud)
{
unsigned long pending = ud->event & ~USBIP_EH_BYE;
if (!(ud->event & USBIP_EH_BYE))
usbip_dbg_eh("usbip_eh stopping but not removed\n");
if (pending)
usbip_dbg_eh("usbip_eh waiting completion %lx\n", pending);
wait_event_interruptible(ud->eh_waitq, !(ud->event & ~USBIP_EH_BYE));
usbip_dbg_eh("usbip_eh has stopped\n");
}
int usbip_init_eh(void)
{
usbip_queue = create_singlethread_workqueue(WORK_QUEUE_NAME);
if (usbip_queue == NULL) {
pr_err("failed to create usbip_event\n");
return -ENOMEM;
}
return 0;
}
void usbip_finish_eh(void)
{
flush_workqueue(usbip_queue);
destroy_workqueue(usbip_queue);
usbip_queue = NULL;
}
void usbip_event_add(struct usbip_device *ud, unsigned long event)
{
struct usbip_event *ue;
unsigned long flags;
if (ud->event & USBIP_EH_BYE)
return;
set_event(ud, event);
spin_lock_irqsave(&event_lock, flags);
list_for_each_entry_reverse(ue, &event_list, node) {
if (ue->ud == ud)
goto out;
}
ue = kmalloc(sizeof(struct usbip_event), GFP_ATOMIC);
if (ue == NULL)
goto out;
ue->ud = ud;
list_add_tail(&ue->node, &event_list);
queue_work(usbip_queue, &usbip_work);
out:
spin_unlock_irqrestore(&event_lock, flags);
}
int usbip_event_happened(struct usbip_device *ud)
{
int happened = 0;
unsigned long flags;
spin_lock_irqsave(&ud->lock, flags);
if (ud->event != 0)
happened = 1;
spin_unlock_irqrestore(&ud->lock, flags);
return happened;
}
int usbip_in_eh(struct task_struct *task)
{
if (task == worker_context)
return 1;
return 0;
}
