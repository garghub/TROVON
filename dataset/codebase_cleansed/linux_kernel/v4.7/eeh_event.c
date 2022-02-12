static int eeh_event_handler(void * dummy)
{
unsigned long flags;
struct eeh_event *event;
struct eeh_pe *pe;
while (!kthread_should_stop()) {
if (down_interruptible(&eeh_eventlist_sem))
break;
spin_lock_irqsave(&eeh_eventlist_lock, flags);
event = NULL;
if (!list_empty(&eeh_eventlist)) {
event = list_entry(eeh_eventlist.next,
struct eeh_event, list);
list_del(&event->list);
}
spin_unlock_irqrestore(&eeh_eventlist_lock, flags);
if (!event)
continue;
pe = event->pe;
if (pe) {
eeh_pe_state_mark(pe, EEH_PE_RECOVERING);
if (pe->type & EEH_PE_PHB)
pr_info("EEH: Detected error on PHB#%d\n",
pe->phb->global_number);
else
pr_info("EEH: Detected PCI bus error on "
"PHB#%d-PE#%x\n",
pe->phb->global_number, pe->addr);
eeh_handle_event(pe);
eeh_pe_state_clear(pe, EEH_PE_RECOVERING);
} else {
eeh_handle_event(NULL);
}
kfree(event);
}
return 0;
}
int eeh_event_init(void)
{
struct task_struct *t;
int ret = 0;
sema_init(&eeh_eventlist_sem, 0);
t = kthread_run(eeh_event_handler, NULL, "eehd");
if (IS_ERR(t)) {
ret = PTR_ERR(t);
pr_err("%s: Failed to start EEH daemon (%d)\n",
__func__, ret);
return ret;
}
return 0;
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
up(&eeh_eventlist_sem);
return 0;
}
void eeh_remove_event(struct eeh_pe *pe, bool force)
{
unsigned long flags;
struct eeh_event *event, *tmp;
spin_lock_irqsave(&eeh_eventlist_lock, flags);
list_for_each_entry_safe(event, tmp, &eeh_eventlist, list) {
if (!force && event->pe &&
(event->pe->state & EEH_PE_ISOLATED))
continue;
if (!pe) {
list_del(&event->list);
kfree(event);
} else if (pe->type & EEH_PE_PHB) {
if (event->pe && event->pe->phb == pe->phb) {
list_del(&event->list);
kfree(event);
}
} else if (event->pe == pe) {
list_del(&event->list);
kfree(event);
}
}
spin_unlock_irqrestore(&eeh_eventlist_lock, flags);
}
