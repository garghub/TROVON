static int eeh_event_handler(void * dummy)
{
unsigned long flags;
struct eeh_event *event;
struct eeh_pe *pe;
spin_lock_irqsave(&eeh_eventlist_lock, flags);
event = NULL;
if (!list_empty(&eeh_eventlist)) {
event = list_entry(eeh_eventlist.next, struct eeh_event, list);
list_del(&event->list);
}
spin_unlock_irqrestore(&eeh_eventlist_lock, flags);
if (event == NULL)
return 0;
mutex_lock(&eeh_event_mutex);
pe = event->pe;
eeh_pe_state_mark(pe, EEH_PE_RECOVERING);
pr_info("EEH: Detected PCI bus error on PHB#%d-PE#%x\n",
pe->phb->global_number, pe->addr);
set_current_state(TASK_INTERRUPTIBLE);
eeh_handle_event(pe);
eeh_pe_state_clear(pe, EEH_PE_RECOVERING);
kfree(event);
mutex_unlock(&eeh_event_mutex);
if (pe && pe->freeze_count > 0) {
msleep_interruptible(3600*1000);
if (pe->freeze_count > 0)
pe->freeze_count--;
}
return 0;
}
static void eeh_thread_launcher(struct work_struct *dummy)
{
if (IS_ERR(kthread_run(eeh_event_handler, NULL, "eehd")))
printk(KERN_ERR "Failed to start EEH daemon\n");
}
int eeh_send_failure_event(struct eeh_pe *pe)
{
unsigned long flags;
struct eeh_event *event;
event = kzalloc(sizeof(*event), GFP_ATOMIC);
if (!event) {
pr_err("EEH: out of memory, event not handled\n");
return -ENOMEM;
}
event->pe = pe;
spin_lock_irqsave(&eeh_eventlist_lock, flags);
list_add(&event->list, &eeh_eventlist);
spin_unlock_irqrestore(&eeh_eventlist_lock, flags);
schedule_work(&eeh_event_wq);
return 0;
}
