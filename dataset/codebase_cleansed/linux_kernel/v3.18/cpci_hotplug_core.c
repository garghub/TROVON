static int
update_latch_status(struct hotplug_slot *hotplug_slot, u8 value)
{
struct hotplug_slot_info info;
memcpy(&info, hotplug_slot->info, sizeof(struct hotplug_slot_info));
info.latch_status = value;
return pci_hp_change_slot_info(hotplug_slot, &info);
}
static int
update_adapter_status(struct hotplug_slot *hotplug_slot, u8 value)
{
struct hotplug_slot_info info;
memcpy(&info, hotplug_slot->info, sizeof(struct hotplug_slot_info));
info.adapter_status = value;
return pci_hp_change_slot_info(hotplug_slot, &info);
}
static int
enable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s", __func__, slot_name(slot));
if (controller->ops->set_power)
retval = controller->ops->set_power(slot, 1);
return retval;
}
static int
disable_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
int retval = 0;
dbg("%s - physical_slot = %s", __func__, slot_name(slot));
down_write(&list_rwsem);
dbg("%s - unconfiguring slot %s", __func__, slot_name(slot));
retval = cpci_unconfigure_slot(slot);
if (retval) {
err("%s - could not unconfigure slot %s",
__func__, slot_name(slot));
goto disable_error;
}
dbg("%s - finished unconfiguring slot %s", __func__, slot_name(slot));
if (cpci_clear_ext(slot)) {
err("%s - could not clear EXT for slot %s",
__func__, slot_name(slot));
retval = -ENODEV;
goto disable_error;
}
cpci_led_on(slot);
if (controller->ops->set_power) {
retval = controller->ops->set_power(slot, 0);
if (retval)
goto disable_error;
}
if (update_adapter_status(slot->hotplug_slot, 0))
warn("failure to update adapter file");
if (slot->extracting) {
slot->extracting = 0;
atomic_dec(&extracting);
}
disable_error:
up_write(&list_rwsem);
return retval;
}
static u8
cpci_get_power_status(struct slot *slot)
{
u8 power = 1;
if (controller->ops->get_power)
power = controller->ops->get_power(slot);
return power;
}
static int
get_power_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
*value = cpci_get_power_status(slot);
return 0;
}
static int
get_attention_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
struct slot *slot = hotplug_slot->private;
*value = cpci_get_attention_status(slot);
return 0;
}
static int
set_attention_status(struct hotplug_slot *hotplug_slot, u8 status)
{
return cpci_set_attention_status(hotplug_slot->private, status);
}
static int
get_adapter_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
*value = hotplug_slot->info->adapter_status;
return 0;
}
static int
get_latch_status(struct hotplug_slot *hotplug_slot, u8 *value)
{
*value = hotplug_slot->info->latch_status;
return 0;
}
static void release_slot(struct hotplug_slot *hotplug_slot)
{
struct slot *slot = hotplug_slot->private;
kfree(slot->hotplug_slot->info);
kfree(slot->hotplug_slot);
if (slot->dev)
pci_dev_put(slot->dev);
kfree(slot);
}
int
cpci_hp_register_bus(struct pci_bus *bus, u8 first, u8 last)
{
struct slot *slot;
struct hotplug_slot *hotplug_slot;
struct hotplug_slot_info *info;
char name[SLOT_NAME_SIZE];
int status;
int i;
if (!(controller && bus))
return -ENODEV;
for (i = first; i <= last; ++i) {
slot = kzalloc(sizeof (struct slot), GFP_KERNEL);
if (!slot) {
status = -ENOMEM;
goto error;
}
hotplug_slot =
kzalloc(sizeof (struct hotplug_slot), GFP_KERNEL);
if (!hotplug_slot) {
status = -ENOMEM;
goto error_slot;
}
slot->hotplug_slot = hotplug_slot;
info = kzalloc(sizeof (struct hotplug_slot_info), GFP_KERNEL);
if (!info) {
status = -ENOMEM;
goto error_hpslot;
}
hotplug_slot->info = info;
slot->bus = bus;
slot->number = i;
slot->devfn = PCI_DEVFN(i, 0);
snprintf(name, SLOT_NAME_SIZE, "%02x:%02x", bus->number, i);
hotplug_slot->private = slot;
hotplug_slot->release = &release_slot;
hotplug_slot->ops = &cpci_hotplug_slot_ops;
dbg("initializing slot %s", name);
info->power_status = cpci_get_power_status(slot);
info->attention_status = cpci_get_attention_status(slot);
dbg("registering slot %s", name);
status = pci_hp_register(slot->hotplug_slot, bus, i, name);
if (status) {
err("pci_hp_register failed with error %d", status);
goto error_info;
}
dbg("slot registered with name: %s", slot_name(slot));
down_write(&list_rwsem);
list_add(&slot->slot_list, &slot_list);
slots++;
up_write(&list_rwsem);
}
return 0;
error_info:
kfree(info);
error_hpslot:
kfree(hotplug_slot);
error_slot:
kfree(slot);
error:
return status;
}
int
cpci_hp_unregister_bus(struct pci_bus *bus)
{
struct slot *slot;
struct slot *tmp;
int status = 0;
down_write(&list_rwsem);
if (!slots) {
up_write(&list_rwsem);
return -1;
}
list_for_each_entry_safe(slot, tmp, &slot_list, slot_list) {
if (slot->bus == bus) {
list_del(&slot->slot_list);
slots--;
dbg("deregistering slot %s", slot_name(slot));
status = pci_hp_deregister(slot->hotplug_slot);
if (status) {
err("pci_hp_deregister failed with error %d",
status);
break;
}
}
}
up_write(&list_rwsem);
return status;
}
static irqreturn_t
cpci_hp_intr(int irq, void *data)
{
dbg("entered cpci_hp_intr");
if ((controller->irq_flags & IRQF_SHARED) &&
!controller->ops->check_irq(controller->dev_id)) {
dbg("exited cpci_hp_intr, not our interrupt");
return IRQ_NONE;
}
controller->ops->disable_irq();
wake_up_process(cpci_thread);
return IRQ_HANDLED;
}
static int
init_slots(int clear_ins)
{
struct slot *slot;
struct pci_dev *dev;
dbg("%s - enter", __func__);
down_read(&list_rwsem);
if (!slots) {
up_read(&list_rwsem);
return -1;
}
list_for_each_entry(slot, &slot_list, slot_list) {
dbg("%s - looking at slot %s", __func__, slot_name(slot));
if (clear_ins && cpci_check_and_clear_ins(slot))
dbg("%s - cleared INS for slot %s",
__func__, slot_name(slot));
dev = pci_get_slot(slot->bus, PCI_DEVFN(slot->number, 0));
if (dev) {
if (update_adapter_status(slot->hotplug_slot, 1))
warn("failure to update adapter file");
if (update_latch_status(slot->hotplug_slot, 1))
warn("failure to update latch file");
slot->dev = dev;
}
}
up_read(&list_rwsem);
dbg("%s - exit", __func__);
return 0;
}
static int
check_slots(void)
{
struct slot *slot;
int extracted;
int inserted;
u16 hs_csr;
down_read(&list_rwsem);
if (!slots) {
up_read(&list_rwsem);
err("no slots registered, shutting down");
return -1;
}
extracted = inserted = 0;
list_for_each_entry(slot, &slot_list, slot_list) {
dbg("%s - looking at slot %s", __func__, slot_name(slot));
if (cpci_check_and_clear_ins(slot)) {
if (slot->dev) {
warn("slot %s already inserted",
slot_name(slot));
inserted++;
continue;
}
dbg("%s - slot %s inserted", __func__, slot_name(slot));
hs_csr = cpci_get_hs_csr(slot);
dbg("%s - slot %s HS_CSR (1) = %04x",
__func__, slot_name(slot), hs_csr);
dbg("%s - configuring slot %s",
__func__, slot_name(slot));
if (cpci_configure_slot(slot)) {
err("%s - could not configure slot %s",
__func__, slot_name(slot));
continue;
}
dbg("%s - finished configuring slot %s",
__func__, slot_name(slot));
hs_csr = cpci_get_hs_csr(slot);
dbg("%s - slot %s HS_CSR (2) = %04x",
__func__, slot_name(slot), hs_csr);
if (update_latch_status(slot->hotplug_slot, 1))
warn("failure to update latch file");
if (update_adapter_status(slot->hotplug_slot, 1))
warn("failure to update adapter file");
cpci_led_off(slot);
hs_csr = cpci_get_hs_csr(slot);
dbg("%s - slot %s HS_CSR (3) = %04x",
__func__, slot_name(slot), hs_csr);
inserted++;
} else if (cpci_check_ext(slot)) {
dbg("%s - slot %s extracted",
__func__, slot_name(slot));
hs_csr = cpci_get_hs_csr(slot);
dbg("%s - slot %s HS_CSR = %04x",
__func__, slot_name(slot), hs_csr);
if (!slot->extracting) {
if (update_latch_status(slot->hotplug_slot, 0))
warn("failure to update latch file");
slot->extracting = 1;
atomic_inc(&extracting);
}
extracted++;
} else if (slot->extracting) {
hs_csr = cpci_get_hs_csr(slot);
if (hs_csr == 0xffff) {
err("card in slot %s was improperly removed",
slot_name(slot));
if (update_adapter_status(slot->hotplug_slot, 0))
warn("failure to update adapter file");
slot->extracting = 0;
atomic_dec(&extracting);
}
}
}
up_read(&list_rwsem);
dbg("inserted=%d, extracted=%d, extracting=%d",
inserted, extracted, atomic_read(&extracting));
if (inserted || extracted)
return extracted;
else if (!atomic_read(&extracting)) {
err("cannot find ENUM# source, shutting down");
return -1;
}
return 0;
}
static int
event_thread(void *data)
{
int rc;
dbg("%s - event thread started", __func__);
while (1) {
dbg("event thread sleeping");
set_current_state(TASK_INTERRUPTIBLE);
schedule();
if (kthread_should_stop())
break;
do {
rc = check_slots();
if (rc > 0) {
msleep(500);
} else if (rc < 0) {
dbg("%s - error checking slots", __func__);
thread_finished = 1;
goto out;
}
} while (atomic_read(&extracting) && !kthread_should_stop());
if (kthread_should_stop())
break;
dbg("%s - re-enabling irq", __func__);
controller->ops->enable_irq();
}
out:
return 0;
}
static int
poll_thread(void *data)
{
int rc;
while (1) {
if (kthread_should_stop() || signal_pending(current))
break;
if (controller->ops->query_enum()) {
do {
rc = check_slots();
if (rc > 0) {
msleep(500);
} else if (rc < 0) {
dbg("%s - error checking slots", __func__);
thread_finished = 1;
goto out;
}
} while (atomic_read(&extracting) && !kthread_should_stop());
}
msleep(100);
}
out:
return 0;
}
static int
cpci_start_thread(void)
{
if (controller->irq)
cpci_thread = kthread_run(event_thread, NULL, "cpci_hp_eventd");
else
cpci_thread = kthread_run(poll_thread, NULL, "cpci_hp_polld");
if (IS_ERR(cpci_thread)) {
err("Can't start up our thread");
return PTR_ERR(cpci_thread);
}
thread_finished = 0;
return 0;
}
static void
cpci_stop_thread(void)
{
kthread_stop(cpci_thread);
thread_finished = 1;
}
int
cpci_hp_register_controller(struct cpci_hp_controller *new_controller)
{
int status = 0;
if (controller)
return -1;
if (!(new_controller && new_controller->ops))
return -EINVAL;
if (new_controller->irq) {
if (!(new_controller->ops->enable_irq &&
new_controller->ops->disable_irq))
status = -EINVAL;
if (request_irq(new_controller->irq,
cpci_hp_intr,
new_controller->irq_flags,
MY_NAME,
new_controller->dev_id)) {
err("Can't get irq %d for the hotplug cPCI controller",
new_controller->irq);
status = -ENODEV;
}
dbg("%s - acquired controller irq %d",
__func__, new_controller->irq);
}
if (!status)
controller = new_controller;
return status;
}
static void
cleanup_slots(void)
{
struct slot *slot;
struct slot *tmp;
down_write(&list_rwsem);
if (!slots)
goto cleanup_null;
list_for_each_entry_safe(slot, tmp, &slot_list, slot_list) {
list_del(&slot->slot_list);
pci_hp_deregister(slot->hotplug_slot);
}
cleanup_null:
up_write(&list_rwsem);
return;
}
int
cpci_hp_unregister_controller(struct cpci_hp_controller *old_controller)
{
int status = 0;
if (controller) {
if (!thread_finished)
cpci_stop_thread();
if (controller->irq)
free_irq(controller->irq, controller->dev_id);
controller = NULL;
cleanup_slots();
} else
status = -ENODEV;
return status;
}
int
cpci_hp_start(void)
{
static int first = 1;
int status;
dbg("%s - enter", __func__);
if (!controller)
return -ENODEV;
down_read(&list_rwsem);
if (list_empty(&slot_list)) {
up_read(&list_rwsem);
return -ENODEV;
}
up_read(&list_rwsem);
status = init_slots(first);
if (first)
first = 0;
if (status)
return status;
status = cpci_start_thread();
if (status)
return status;
dbg("%s - thread started", __func__);
if (controller->irq) {
dbg("%s - enabling irq", __func__);
controller->ops->enable_irq();
}
dbg("%s - exit", __func__);
return 0;
}
int
cpci_hp_stop(void)
{
if (!controller)
return -ENODEV;
if (controller->irq) {
dbg("%s - disabling irq", __func__);
controller->ops->disable_irq();
}
cpci_stop_thread();
return 0;
}
int __init
cpci_hotplug_init(int debug)
{
cpci_debug = debug;
return 0;
}
void __exit
cpci_hotplug_exit(void)
{
cpci_hp_stop();
cpci_hp_unregister_controller(controller);
}
