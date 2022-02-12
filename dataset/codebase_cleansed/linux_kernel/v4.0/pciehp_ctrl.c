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
u8 pciehp_handle_attention_button(struct slot *p_slot)
{
u32 event_type;
struct controller *ctrl = p_slot->ctrl;
ctrl_dbg(ctrl, "Attention button interrupt received\n");
ctrl_info(ctrl, "Button pressed on Slot(%s)\n", slot_name(p_slot));
event_type = INT_BUTTON_PRESS;
queue_interrupt_event(p_slot, event_type);
return 0;
}
u8 pciehp_handle_switch_change(struct slot *p_slot)
{
u8 getstatus;
u32 event_type;
struct controller *ctrl = p_slot->ctrl;
ctrl_dbg(ctrl, "Switch interrupt received\n");
pciehp_get_latch_status(p_slot, &getstatus);
if (getstatus) {
ctrl_info(ctrl, "Latch open on Slot(%s)\n", slot_name(p_slot));
event_type = INT_SWITCH_OPEN;
} else {
ctrl_info(ctrl, "Latch close on Slot(%s)\n", slot_name(p_slot));
event_type = INT_SWITCH_CLOSE;
}
queue_interrupt_event(p_slot, event_type);
return 1;
}
u8 pciehp_handle_presence_change(struct slot *p_slot)
{
u32 event_type;
u8 presence_save;
struct controller *ctrl = p_slot->ctrl;
ctrl_dbg(ctrl, "Presence/Notify input change\n");
pciehp_get_adapter_status(p_slot, &presence_save);
if (presence_save) {
ctrl_info(ctrl, "Card present on Slot(%s)\n", slot_name(p_slot));
event_type = INT_PRESENCE_ON;
} else {
ctrl_info(ctrl, "Card not present on Slot(%s)\n",
slot_name(p_slot));
event_type = INT_PRESENCE_OFF;
}
queue_interrupt_event(p_slot, event_type);
return 1;
}
u8 pciehp_handle_power_fault(struct slot *p_slot)
{
u32 event_type;
struct controller *ctrl = p_slot->ctrl;
ctrl_dbg(ctrl, "Power fault interrupt received\n");
ctrl_err(ctrl, "Power fault on slot %s\n", slot_name(p_slot));
event_type = INT_POWER_FAULT;
ctrl_info(ctrl, "Power fault bit %x set\n", 0);
queue_interrupt_event(p_slot, event_type);
return 1;
}
void pciehp_handle_linkstate_change(struct slot *p_slot)
{
u32 event_type;
struct controller *ctrl = p_slot->ctrl;
ctrl_dbg(ctrl, "Data Link Layer State change\n");
if (pciehp_check_link_active(ctrl)) {
ctrl_info(ctrl, "slot(%s): Link Up event\n",
slot_name(p_slot));
event_type = INT_LINK_UP;
} else {
ctrl_info(ctrl, "slot(%s): Link Down event\n",
slot_name(p_slot));
event_type = INT_LINK_DOWN;
}
queue_interrupt_event(p_slot, event_type);
}
static void set_slot_off(struct controller *ctrl, struct slot *pslot)
{
if (POWER_CTRL(ctrl)) {
pciehp_power_off_slot(pslot);
msleep(1000);
}
pciehp_green_led_off(pslot);
pciehp_set_attention_status(pslot, 1);
}
static int board_added(struct slot *p_slot)
{
int retval = 0;
struct controller *ctrl = p_slot->ctrl;
struct pci_bus *parent = ctrl->pcie->port->subordinate;
if (POWER_CTRL(ctrl)) {
retval = pciehp_power_on_slot(p_slot);
if (retval)
return retval;
}
pciehp_green_led_blink(p_slot);
retval = pciehp_check_link_status(ctrl);
if (retval) {
ctrl_err(ctrl, "Failed to check link status\n");
goto err_exit;
}
if (ctrl->power_fault_detected || pciehp_query_power_fault(p_slot)) {
ctrl_err(ctrl, "Power fault on slot %s\n", slot_name(p_slot));
retval = -EIO;
goto err_exit;
}
retval = pciehp_configure_device(p_slot);
if (retval) {
ctrl_err(ctrl, "Cannot add device at %04x:%02x:00\n",
pci_domain_nr(parent), parent->number);
if (retval != -EEXIST)
goto err_exit;
}
pciehp_green_led_on(p_slot);
return 0;
err_exit:
set_slot_off(ctrl, p_slot);
return retval;
}
static int remove_board(struct slot *p_slot)
{
int retval;
struct controller *ctrl = p_slot->ctrl;
retval = pciehp_unconfigure_device(p_slot);
if (retval)
return retval;
if (POWER_CTRL(ctrl)) {
pciehp_power_off_slot(p_slot);
msleep(1000);
}
pciehp_green_led_off(p_slot);
return 0;
}
static void pciehp_power_thread(struct work_struct *work)
{
struct power_work_info *info =
container_of(work, struct power_work_info, work);
struct slot *p_slot = info->p_slot;
int ret;
switch (info->req) {
case DISABLE_REQ:
ctrl_dbg(p_slot->ctrl,
"Disabling domain:bus:device=%04x:%02x:00\n",
pci_domain_nr(p_slot->ctrl->pcie->port->subordinate),
p_slot->ctrl->pcie->port->subordinate->number);
mutex_lock(&p_slot->hotplug_lock);
pciehp_disable_slot(p_slot);
mutex_unlock(&p_slot->hotplug_lock);
mutex_lock(&p_slot->lock);
p_slot->state = STATIC_STATE;
mutex_unlock(&p_slot->lock);
break;
case ENABLE_REQ:
ctrl_dbg(p_slot->ctrl,
"Enabling domain:bus:device=%04x:%02x:00\n",
pci_domain_nr(p_slot->ctrl->pcie->port->subordinate),
p_slot->ctrl->pcie->port->subordinate->number);
mutex_lock(&p_slot->hotplug_lock);
ret = pciehp_enable_slot(p_slot);
mutex_unlock(&p_slot->hotplug_lock);
if (ret)
pciehp_green_led_off(p_slot);
mutex_lock(&p_slot->lock);
p_slot->state = STATIC_STATE;
mutex_unlock(&p_slot->lock);
break;
default:
break;
}
kfree(info);
}
void pciehp_queue_pushbutton_work(struct work_struct *work)
{
struct slot *p_slot = container_of(work, struct slot, work.work);
struct power_work_info *info;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
ctrl_err(p_slot->ctrl, "%s: Cannot allocate memory\n",
__func__);
return;
}
info->p_slot = p_slot;
INIT_WORK(&info->work, pciehp_power_thread);
mutex_lock(&p_slot->lock);
switch (p_slot->state) {
case BLINKINGOFF_STATE:
p_slot->state = POWEROFF_STATE;
info->req = DISABLE_REQ;
break;
case BLINKINGON_STATE:
p_slot->state = POWERON_STATE;
info->req = ENABLE_REQ;
break;
default:
kfree(info);
goto out;
}
queue_work(p_slot->wq, &info->work);
out:
mutex_unlock(&p_slot->lock);
}
static void handle_button_press_event(struct slot *p_slot)
{
struct controller *ctrl = p_slot->ctrl;
u8 getstatus;
switch (p_slot->state) {
case STATIC_STATE:
pciehp_get_power_status(p_slot, &getstatus);
if (getstatus) {
p_slot->state = BLINKINGOFF_STATE;
ctrl_info(ctrl, "PCI slot #%s - powering off due to button press\n",
slot_name(p_slot));
} else {
p_slot->state = BLINKINGON_STATE;
ctrl_info(ctrl, "PCI slot #%s - powering on due to button press\n",
slot_name(p_slot));
}
pciehp_green_led_blink(p_slot);
pciehp_set_attention_status(p_slot, 0);
queue_delayed_work(p_slot->wq, &p_slot->work, 5*HZ);
break;
case BLINKINGOFF_STATE:
case BLINKINGON_STATE:
ctrl_info(ctrl, "Button cancel on Slot(%s)\n", slot_name(p_slot));
cancel_delayed_work(&p_slot->work);
if (p_slot->state == BLINKINGOFF_STATE)
pciehp_green_led_on(p_slot);
else
pciehp_green_led_off(p_slot);
pciehp_set_attention_status(p_slot, 0);
ctrl_info(ctrl, "PCI slot #%s - action canceled due to button press\n",
slot_name(p_slot));
p_slot->state = STATIC_STATE;
break;
case POWEROFF_STATE:
case POWERON_STATE:
ctrl_info(ctrl, "Button ignore on Slot(%s)\n", slot_name(p_slot));
break;
default:
ctrl_warn(ctrl, "Not a valid state\n");
break;
}
}
static void handle_surprise_event(struct slot *p_slot)
{
u8 getstatus;
struct power_work_info *info;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
ctrl_err(p_slot->ctrl, "%s: Cannot allocate memory\n",
__func__);
return;
}
info->p_slot = p_slot;
INIT_WORK(&info->work, pciehp_power_thread);
pciehp_get_adapter_status(p_slot, &getstatus);
if (!getstatus) {
p_slot->state = POWEROFF_STATE;
info->req = DISABLE_REQ;
} else {
p_slot->state = POWERON_STATE;
info->req = ENABLE_REQ;
}
queue_work(p_slot->wq, &info->work);
}
static void handle_link_event(struct slot *p_slot, u32 event)
{
struct controller *ctrl = p_slot->ctrl;
struct power_work_info *info;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
ctrl_err(p_slot->ctrl, "%s: Cannot allocate memory\n",
__func__);
return;
}
info->p_slot = p_slot;
info->req = event == INT_LINK_UP ? ENABLE_REQ : DISABLE_REQ;
INIT_WORK(&info->work, pciehp_power_thread);
switch (p_slot->state) {
case BLINKINGON_STATE:
case BLINKINGOFF_STATE:
cancel_delayed_work(&p_slot->work);
case STATIC_STATE:
p_slot->state = event == INT_LINK_UP ?
POWERON_STATE : POWEROFF_STATE;
queue_work(p_slot->wq, &info->work);
break;
case POWERON_STATE:
if (event == INT_LINK_UP) {
ctrl_info(ctrl,
"Link Up event ignored on slot(%s): already powering on\n",
slot_name(p_slot));
kfree(info);
} else {
ctrl_info(ctrl,
"Link Down event queued on slot(%s): currently getting powered on\n",
slot_name(p_slot));
p_slot->state = POWEROFF_STATE;
queue_work(p_slot->wq, &info->work);
}
break;
case POWEROFF_STATE:
if (event == INT_LINK_UP) {
ctrl_info(ctrl,
"Link Up event queued on slot(%s): currently getting powered off\n",
slot_name(p_slot));
p_slot->state = POWERON_STATE;
queue_work(p_slot->wq, &info->work);
} else {
ctrl_info(ctrl,
"Link Down event ignored on slot(%s): already powering off\n",
slot_name(p_slot));
kfree(info);
}
break;
default:
ctrl_err(ctrl, "Not a valid state on slot(%s)\n",
slot_name(p_slot));
kfree(info);
break;
}
}
static void interrupt_event_handler(struct work_struct *work)
{
struct event_info *info = container_of(work, struct event_info, work);
struct slot *p_slot = info->p_slot;
struct controller *ctrl = p_slot->ctrl;
mutex_lock(&p_slot->lock);
switch (info->event_type) {
case INT_BUTTON_PRESS:
handle_button_press_event(p_slot);
break;
case INT_POWER_FAULT:
if (!POWER_CTRL(ctrl))
break;
pciehp_set_attention_status(p_slot, 1);
pciehp_green_led_off(p_slot);
break;
case INT_PRESENCE_ON:
ctrl_dbg(ctrl, "Surprise Insertion\n");
handle_surprise_event(p_slot);
break;
case INT_PRESENCE_OFF:
ctrl_dbg(ctrl, "Surprise Removal\n");
handle_surprise_event(p_slot);
break;
case INT_LINK_UP:
case INT_LINK_DOWN:
handle_link_event(p_slot, info->event_type);
break;
default:
break;
}
mutex_unlock(&p_slot->lock);
kfree(info);
}
int pciehp_enable_slot(struct slot *p_slot)
{
u8 getstatus = 0;
int rc;
struct controller *ctrl = p_slot->ctrl;
pciehp_get_adapter_status(p_slot, &getstatus);
if (!getstatus) {
ctrl_info(ctrl, "No adapter on slot(%s)\n", slot_name(p_slot));
return -ENODEV;
}
if (MRL_SENS(p_slot->ctrl)) {
pciehp_get_latch_status(p_slot, &getstatus);
if (getstatus) {
ctrl_info(ctrl, "Latch open on slot(%s)\n",
slot_name(p_slot));
return -ENODEV;
}
}
if (POWER_CTRL(p_slot->ctrl)) {
pciehp_get_power_status(p_slot, &getstatus);
if (getstatus) {
ctrl_info(ctrl, "Already enabled on slot(%s)\n",
slot_name(p_slot));
return -EINVAL;
}
}
pciehp_get_latch_status(p_slot, &getstatus);
rc = board_added(p_slot);
if (rc)
pciehp_get_latch_status(p_slot, &getstatus);
return rc;
}
int pciehp_disable_slot(struct slot *p_slot)
{
u8 getstatus = 0;
struct controller *ctrl = p_slot->ctrl;
if (!p_slot->ctrl)
return 1;
if (POWER_CTRL(p_slot->ctrl)) {
pciehp_get_power_status(p_slot, &getstatus);
if (!getstatus) {
ctrl_info(ctrl, "Already disabled on slot(%s)\n",
slot_name(p_slot));
return -EINVAL;
}
}
return remove_board(p_slot);
}
int pciehp_sysfs_enable_slot(struct slot *p_slot)
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
mutex_lock(&p_slot->hotplug_lock);
retval = pciehp_enable_slot(p_slot);
mutex_unlock(&p_slot->hotplug_lock);
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
int pciehp_sysfs_disable_slot(struct slot *p_slot)
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
retval = pciehp_disable_slot(p_slot);
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
