static int eeh_event_handler(void * dummy)
{
unsigned long flags;
struct eeh_event *event;
struct eeh_dev *edev;
set_task_comm(current, "eehd");
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
edev = event->edev;
eeh_mark_slot(eeh_dev_to_of_node(edev), EEH_MODE_RECOVERING);
printk(KERN_INFO "EEH: Detected PCI bus error on device %s\n",
eeh_pci_name(edev->pdev));
set_current_state(TASK_INTERRUPTIBLE);
edev = handle_eeh_events(event);
if (edev) {
eeh_clear_slot(eeh_dev_to_of_node(edev), EEH_MODE_RECOVERING);
pci_dev_put(edev->pdev);
}
kfree(event);
mutex_unlock(&eeh_event_mutex);
if (edev && edev->freeze_count>0) {
msleep_interruptible(3600*1000);
if (edev->freeze_count>0)
edev->freeze_count--;
}
return 0;
}
static void eeh_thread_launcher(struct work_struct *dummy)
{
if (kernel_thread(eeh_event_handler, NULL, CLONE_KERNEL) < 0)
printk(KERN_ERR "Failed to start EEH daemon\n");
}
int eeh_send_failure_event(struct eeh_dev *edev)
{
unsigned long flags;
struct eeh_event *event;
struct device_node *dn = eeh_dev_to_of_node(edev);
const char *location;
if (!mem_init_done) {
printk(KERN_ERR "EEH: event during early boot not handled\n");
location = of_get_property(dn, "ibm,loc-code", NULL);
printk(KERN_ERR "EEH: device node = %s\n", dn->full_name);
printk(KERN_ERR "EEH: PCI location = %s\n", location);
return 1;
}
event = kmalloc(sizeof(*event), GFP_ATOMIC);
if (event == NULL) {
printk(KERN_ERR "EEH: out of memory, event not handled\n");
return 1;
}
if (edev->pdev)
pci_dev_get(edev->pdev);
event->edev = edev;
spin_lock_irqsave(&eeh_eventlist_lock, flags);
list_add(&event->list, &eeh_eventlist);
spin_unlock_irqrestore(&eeh_eventlist_lock, flags);
schedule_work(&eeh_event_wq);
return 0;
}
