static int queue_interrupt_event(struct slot *p_slot, u32 event_type)
{
struct event_info *info;
info = kmalloc(sizeof(*info), GFP_ATOMIC);
if (!info)
return -ENOMEM;
info->event_type = event_type;
info->p_slot = p_slot;
INIT_WORK(&info->work, interrupt_event_handler);
queue_work(p_slot->wq, &info->work);
return 0;
}
u8 shpchp_handle_attention_button(u8 hp_slot, struct controller *ctrl)
{
struct slot *p_slot;
u32 event_type;
ctrl_dbg(ctrl, "Attention button interrupt received\n");
p_slot = shpchp_find_slot(ctrl, hp_slot + ctrl->slot_device_offset);
p_slot->hpc_ops->get_adapter_status(p_slot, &(p_slot->presence_save));
ctrl_info(ctrl, "Button pressed on Slot(%s)\n", slot_name(p_slot));
event_type = INT_BUTTON_PRESS;
queue_interrupt_event(p_slot, event_type);
return 0;
}
u8 shpchp_handle_switch_change(u8 hp_slot, struct controller *ctrl)
{
struct slot *p_slot;
u8 getstatus;
u32 event_type;
ctrl_dbg(ctrl, "Switch interrupt received\n");
p_slot = shpchp_find_slot(ctrl, hp_slot + ctrl->slot_device_offset);
p_slot->hpc_ops->get_adapter_status(p_slot, &(p_slot->presence_save));
p_slot->hpc_ops->get_latch_status(p_slot, &getstatus);
ctrl_dbg(ctrl, "Card present %x Power status %x\n",
p_slot->presence_save, p_slot->pwr_save);
if (getstatus) {
ctrl_info(ctrl, "Latch open on Slot(%s)\n", slot_name(p_slot));
event_type = INT_SWITCH_OPEN;
if (p_slot->pwr_save && p_slot->presence_save) {
event_type = INT_POWER_FAULT;
ctrl_err(ctrl, "Surprise Removal of card\n");
}
} else {
ctrl_info(ctrl, "Latch close on Slot(%s)\n", slot_name(p_slot));
event_type = INT_SWITCH_CLOSE;
}
queue_interrupt_event(p_slot, event_type);
return 1;
}
u8 shpchp_handle_presence_change(u8 hp_slot, struct controller *ctrl)
{
struct slot *p_slot;
u32 event_type;
ctrl_dbg(ctrl, "Presence/Notify input change\n");
p_slot = shpchp_find_slot(ctrl, hp_slot + ctrl->slot_device_offset);
p_slot->hpc_ops->get_adapter_status(p_slot, &(p_slot->presence_save));
if (p_slot->presence_save) {
ctrl_info(ctrl, "Card present on Slot(%s)\n",
slot_name(p_slot));
event_type = INT_PRESENCE_ON;
} else {
ctrl_info(ctrl, "Card not present on Slot(%s)\n",
slot_name(p_slot));
event_type = INT_PRESENCE_OFF;
}
queue_interrupt_event(p_slot, event_type);
return 1;
}
u8 shpchp_handle_power_fault(u8 hp_slot, struct controller *ctrl)
{
struct slot *p_slot;
u32 event_type;
ctrl_dbg(ctrl, "Power fault interrupt received\n");
p_slot = shpchp_find_slot(ctrl, hp_slot + ctrl->slot_device_offset);
if ( !(p_slot->hpc_ops->query_power_fault(p_slot))) {
ctrl_info(ctrl, "Power fault cleared on Slot(%s)\n",
slot_name(p_slot));
p_slot->status = 0x00;
event_type = INT_POWER_FAULT_CLEAR;
} else {
ctrl_info(ctrl, "Power fault on Slot(%s)\n", slot_name(p_slot));
event_type = INT_POWER_FAULT;
p_slot->status = 0xFF;
ctrl_info(ctrl, "Power fault bit %x set\n", hp_slot);
}
queue_interrupt_event(p_slot, event_type);
return 1;
}
static int change_bus_speed(struct controller *ctrl, struct slot *p_slot,
enum pci_bus_speed speed)
{
int rc = 0;
ctrl_dbg(ctrl, "Change speed to %d\n", speed);
if ((rc = p_slot->hpc_ops->set_bus_speed_mode(p_slot, speed))) {
ctrl_err(ctrl, "%s: Issue of set bus speed mode command "
"failed\n", __func__);
return WRONG_BUS_FREQUENCY;
}
return rc;
}
static int fix_bus_speed(struct controller *ctrl, struct slot *pslot,
u8 flag, enum pci_bus_speed asp, enum pci_bus_speed bsp,
enum pci_bus_speed msp)
{
int rc = 0;
if (flag) {
if (asp < bsp) {
ctrl_err(ctrl, "Speed of bus %x and adapter %x "
"mismatch\n", bsp, asp);
rc = WRONG_BUS_FREQUENCY;
}
return rc;
}
if (asp < msp) {
if (bsp != asp)
rc = change_bus_speed(ctrl, pslot, asp);
} else {
if (bsp != msp)
rc = change_bus_speed(ctrl, pslot, msp);
}
return rc;
}
static int board_added(struct slot *p_slot)
{
u8 hp_slot;
u8 slots_not_empty = 0;
int rc = 0;
enum pci_bus_speed asp, bsp, msp;
struct controller *ctrl = p_slot->ctrl;
struct pci_bus *parent = ctrl->pci_dev->subordinate;
hp_slot = p_slot->device - ctrl->slot_device_offset;
ctrl_dbg(ctrl,
"%s: p_slot->device, slot_offset, hp_slot = %d, %d ,%d\n",
__func__, p_slot->device, ctrl->slot_device_offset, hp_slot);
rc = p_slot->hpc_ops->power_on_slot(p_slot);
if (rc) {
ctrl_err(ctrl, "Failed to power on slot\n");
return -1;
}
if ((ctrl->pci_dev->vendor == 0x8086) && (ctrl->pci_dev->device == 0x0332)) {
if ((rc = p_slot->hpc_ops->set_bus_speed_mode(p_slot, PCI_SPEED_33MHz))) {
ctrl_err(ctrl, "%s: Issue of set bus speed mode command"
" failed\n", __func__);
return WRONG_BUS_FREQUENCY;
}
if ((rc = p_slot->hpc_ops->slot_enable(p_slot))) {
ctrl_err(ctrl, "Issue of Slot Enable command failed\n");
return rc;
}
}
rc = p_slot->hpc_ops->get_adapter_speed(p_slot, &asp);
if (rc) {
ctrl_err(ctrl, "Can't get adapter speed or "
"bus mode mismatch\n");
return WRONG_BUS_FREQUENCY;
}
bsp = ctrl->pci_dev->bus->cur_bus_speed;
msp = ctrl->pci_dev->bus->max_bus_speed;
if (!list_empty(&ctrl->pci_dev->subordinate->devices))
slots_not_empty = 1;
ctrl_dbg(ctrl, "%s: slots_not_empty %d, adapter_speed %d, bus_speed %d,"
" max_bus_speed %d\n", __func__, slots_not_empty, asp,
bsp, msp);
rc = fix_bus_speed(ctrl, p_slot, slots_not_empty, asp, bsp, msp);
if (rc)
return rc;
if ((rc = p_slot->hpc_ops->slot_enable(p_slot))) {
ctrl_err(ctrl, "Issue of Slot Enable command failed\n");
return rc;
}
msleep(1000);
ctrl_dbg(ctrl, "%s: slot status = %x\n", __func__, p_slot->status);
if (p_slot->status == 0xFF) {
ctrl_dbg(ctrl, "%s: Power fault\n", __func__);
rc = POWER_FAILURE;
p_slot->status = 0;
goto err_exit;
}
if (shpchp_configure_device(p_slot)) {
ctrl_err(ctrl, "Cannot add device at %04x:%02x:%02x\n",
pci_domain_nr(parent), p_slot->bus, p_slot->device);
goto err_exit;
}
p_slot->status = 0;
p_slot->is_a_board = 0x01;
p_slot->pwr_save = 1;
p_slot->hpc_ops->green_led_on(p_slot);
return 0;
err_exit:
rc = p_slot->hpc_ops->slot_disable(p_slot);
if (rc) {
ctrl_err(ctrl, "%s: Issue of Slot Disable command failed\n",
__func__);
return rc;
}
return(rc);
}
static int remove_board(struct slot *p_slot)
{
struct controller *ctrl = p_slot->ctrl;
u8 hp_slot;
int rc;
if (shpchp_unconfigure_device(p_slot))
return(1);
hp_slot = p_slot->device - ctrl->slot_device_offset;
p_slot = shpchp_find_slot(ctrl, hp_slot + ctrl->slot_device_offset);
ctrl_dbg(ctrl, "%s: hp_slot = %d\n", __func__, hp_slot);
if (p_slot->is_a_board)
p_slot->status = 0x01;
rc = p_slot->hpc_ops->slot_disable(p_slot);
if (rc) {
ctrl_err(ctrl, "%s: Issue of Slot Disable command failed\n",
__func__);
return rc;
}
rc = p_slot->hpc_ops->set_attention_status(p_slot, 0);
if (rc) {
ctrl_err(ctrl, "Issue of Set Attention command failed\n");
return rc;
}
p_slot->pwr_save = 0;
p_slot->is_a_board = 0;
return 0;
}
static void shpchp_pushbutton_thread(struct work_struct *work)
{
struct pushbutton_work_info *info =
container_of(work, struct pushbutton_work_info, work);
struct slot *p_slot = info->p_slot;
mutex_lock(&p_slot->lock);
switch (p_slot->state) {
case POWEROFF_STATE:
mutex_unlock(&p_slot->lock);
shpchp_disable_slot(p_slot);
mutex_lock(&p_slot->lock);
p_slot->state = STATIC_STATE;
break;
case POWERON_STATE:
mutex_unlock(&p_slot->lock);
if (shpchp_enable_slot(p_slot))
p_slot->hpc_ops->green_led_off(p_slot);
mutex_lock(&p_slot->lock);
p_slot->state = STATIC_STATE;
break;
default:
break;
}
mutex_unlock(&p_slot->lock);
kfree(info);
}
void shpchp_queue_pushbutton_work(struct work_struct *work)
{
struct slot *p_slot = container_of(work, struct slot, work.work);
struct pushbutton_work_info *info;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
ctrl_err(p_slot->ctrl, "%s: Cannot allocate memory\n",
__func__);
return;
}
info->p_slot = p_slot;
INIT_WORK(&info->work, shpchp_pushbutton_thread);
mutex_lock(&p_slot->lock);
switch (p_slot->state) {
case BLINKINGOFF_STATE:
p_slot->state = POWEROFF_STATE;
break;
case BLINKINGON_STATE:
p_slot->state = POWERON_STATE;
break;
default:
kfree(info);
goto out;
}
queue_work(p_slot->wq, &info->work);
out:
mutex_unlock(&p_slot->lock);
}
static int update_slot_info (struct slot *slot)
{
struct hotplug_slot_info *info;
int result;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
slot->hpc_ops->get_power_status(slot, &(info->power_status));
slot->hpc_ops->get_attention_status(slot, &(info->attention_status));
slot->hpc_ops->get_latch_status(slot, &(info->latch_status));
slot->hpc_ops->get_adapter_status(slot, &(info->adapter_status));
result = pci_hp_change_slot_info(slot->hotplug_slot, info);
kfree (info);
return result;
}
static void handle_button_press_event(struct slot *p_slot)
{
u8 getstatus;
struct controller *ctrl = p_slot->ctrl;
switch (p_slot->state) {
case STATIC_STATE:
p_slot->hpc_ops->get_power_status(p_slot, &getstatus);
if (getstatus) {
p_slot->state = BLINKINGOFF_STATE;
ctrl_info(ctrl, "PCI slot #%s - powering off due to "
"button press.\n", slot_name(p_slot));
} else {
p_slot->state = BLINKINGON_STATE;
ctrl_info(ctrl, "PCI slot #%s - powering on due to "
"button press.\n", slot_name(p_slot));
}
p_slot->hpc_ops->green_led_blink(p_slot);
p_slot->hpc_ops->set_attention_status(p_slot, 0);
queue_delayed_work(p_slot->wq, &p_slot->work, 5*HZ);
break;
case BLINKINGOFF_STATE:
case BLINKINGON_STATE:
ctrl_info(ctrl, "Button cancel on Slot(%s)\n",
slot_name(p_slot));
cancel_delayed_work(&p_slot->work);
if (p_slot->state == BLINKINGOFF_STATE)
p_slot->hpc_ops->green_led_on(p_slot);
else
p_slot->hpc_ops->green_led_off(p_slot);
p_slot->hpc_ops->set_attention_status(p_slot, 0);
ctrl_info(ctrl, "PCI slot #%s - action canceled due to "
"button press\n", slot_name(p_slot));
p_slot->state = STATIC_STATE;
break;
case POWEROFF_STATE:
case POWERON_STATE:
ctrl_info(ctrl, "Button ignore on Slot(%s)\n",
slot_name(p_slot));
update_slot_info(p_slot);
break;
default:
ctrl_warn(ctrl, "Not a valid state\n");
break;
}
}
static void interrupt_event_handler(struct work_struct *work)
{
struct event_info *info = container_of(work, struct event_info, work);
struct slot *p_slot = info->p_slot;
mutex_lock(&p_slot->lock);
switch (info->event_type) {
case INT_BUTTON_PRESS:
handle_button_press_event(p_slot);
break;
case INT_POWER_FAULT:
ctrl_dbg(p_slot->ctrl, "%s: Power fault\n", __func__);
p_slot->hpc_ops->set_attention_status(p_slot, 1);
p_slot->hpc_ops->green_led_off(p_slot);
break;
default:
update_slot_info(p_slot);
break;
}
mutex_unlock(&p_slot->lock);
kfree(info);
}
static int shpchp_enable_slot (struct slot *p_slot)
{
u8 getstatus = 0;
int rc, retval = -ENODEV;
struct controller *ctrl = p_slot->ctrl;
mutex_lock(&p_slot->ctrl->crit_sect);
rc = p_slot->hpc_ops->get_adapter_status(p_slot, &getstatus);
if (rc || !getstatus) {
ctrl_info(ctrl, "No adapter on slot(%s)\n", slot_name(p_slot));
goto out;
}
rc = p_slot->hpc_ops->get_latch_status(p_slot, &getstatus);
if (rc || getstatus) {
ctrl_info(ctrl, "Latch open on slot(%s)\n", slot_name(p_slot));
goto out;
}
rc = p_slot->hpc_ops->get_power_status(p_slot, &getstatus);
if (rc || getstatus) {
ctrl_info(ctrl, "Already enabled on slot(%s)\n",
slot_name(p_slot));
goto out;
}
p_slot->is_a_board = 1;
p_slot->hpc_ops->get_adapter_status(p_slot, &(p_slot->presence_save));
p_slot->hpc_ops->get_power_status(p_slot, &(p_slot->pwr_save));
ctrl_dbg(ctrl, "%s: p_slot->pwr_save %x\n", __func__, p_slot->pwr_save);
p_slot->hpc_ops->get_latch_status(p_slot, &getstatus);
if(((p_slot->ctrl->pci_dev->vendor == PCI_VENDOR_ID_AMD) ||
(p_slot->ctrl->pci_dev->device == PCI_DEVICE_ID_AMD_POGO_7458))
&& p_slot->ctrl->num_slots == 1) {
amd_pogo_errata_save_misc_reg(p_slot);
retval = board_added(p_slot);
amd_pogo_errata_restore_misc_reg(p_slot);
} else
retval = board_added(p_slot);
if (retval) {
p_slot->hpc_ops->get_adapter_status(p_slot,
&(p_slot->presence_save));
p_slot->hpc_ops->get_latch_status(p_slot, &getstatus);
}
update_slot_info(p_slot);
out:
mutex_unlock(&p_slot->ctrl->crit_sect);
return retval;
}
static int shpchp_disable_slot (struct slot *p_slot)
{
u8 getstatus = 0;
int rc, retval = -ENODEV;
struct controller *ctrl = p_slot->ctrl;
if (!p_slot->ctrl)
return -ENODEV;
mutex_lock(&p_slot->ctrl->crit_sect);
rc = p_slot->hpc_ops->get_adapter_status(p_slot, &getstatus);
if (rc || !getstatus) {
ctrl_info(ctrl, "No adapter on slot(%s)\n", slot_name(p_slot));
goto out;
}
rc = p_slot->hpc_ops->get_latch_status(p_slot, &getstatus);
if (rc || getstatus) {
ctrl_info(ctrl, "Latch open on slot(%s)\n", slot_name(p_slot));
goto out;
}
rc = p_slot->hpc_ops->get_power_status(p_slot, &getstatus);
if (rc || !getstatus) {
ctrl_info(ctrl, "Already disabled on slot(%s)\n",
slot_name(p_slot));
goto out;
}
retval = remove_board(p_slot);
update_slot_info(p_slot);
out:
mutex_unlock(&p_slot->ctrl->crit_sect);
return retval;
}
int shpchp_sysfs_enable_slot(struct slot *p_slot)
{
int retval = -ENODEV;
struct controller *ctrl = p_slot->ctrl;
mutex_lock(&p_slot->lock);
switch (p_slot->state) {
case BLINKINGON_STATE:
cancel_delayed_work(&p_slot->work);
case STATIC_STATE:
p_slot->state = POWERON_STATE;
mutex_unlock(&p_slot->lock);
retval = shpchp_enable_slot(p_slot);
mutex_lock(&p_slot->lock);
p_slot->state = STATIC_STATE;
break;
case POWERON_STATE:
ctrl_info(ctrl, "Slot %s is already in powering on state\n",
slot_name(p_slot));
break;
case BLINKINGOFF_STATE:
case POWEROFF_STATE:
ctrl_info(ctrl, "Already enabled on slot %s\n",
slot_name(p_slot));
break;
default:
ctrl_err(ctrl, "Not a valid state on slot %s\n",
slot_name(p_slot));
break;
}
mutex_unlock(&p_slot->lock);
return retval;
}
int shpchp_sysfs_disable_slot(struct slot *p_slot)
{
int retval = -ENODEV;
struct controller *ctrl = p_slot->ctrl;
mutex_lock(&p_slot->lock);
switch (p_slot->state) {
case BLINKINGOFF_STATE:
cancel_delayed_work(&p_slot->work);
case STATIC_STATE:
p_slot->state = POWEROFF_STATE;
mutex_unlock(&p_slot->lock);
retval = shpchp_disable_slot(p_slot);
mutex_lock(&p_slot->lock);
p_slot->state = STATIC_STATE;
break;
case POWEROFF_STATE:
ctrl_info(ctrl, "Slot %s is already in powering off state\n",
slot_name(p_slot));
break;
case BLINKINGON_STATE:
case POWERON_STATE:
ctrl_info(ctrl, "Already disabled on slot %s\n",
slot_name(p_slot));
break;
default:
ctrl_err(ctrl, "Not a valid state on slot %s\n",
slot_name(p_slot));
break;
}
mutex_unlock(&p_slot->lock);
return retval;
}
