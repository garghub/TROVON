void pciehp_queue_interrupt_event(struct slot *p_slot, u32 event_type)
{
struct event_info *info;
info = kmalloc(sizeof(*info), GFP_ATOMIC);
if (!info) {
ctrl_err(p_slot->ctrl, "dropped event %d (ENOMEM)\n", event_type);
return;
}
INIT_WORK(&info->work, interrupt_event_handler);
info->event_type = event_type;
info->p_slot = p_slot;
queue_work(p_slot->wq, &info->work);
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
mutex_lock(&p_slot->hotplug_lock);
pciehp_disable_slot(p_slot);
mutex_unlock(&p_slot->hotplug_lock);
mutex_lock(&p_slot->lock);
p_slot->state = STATIC_STATE;
mutex_unlock(&p_slot->lock);
break;
case ENABLE_REQ:
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
static void pciehp_queue_power_work(struct slot *p_slot, int req)
{
struct power_work_info *info;
p_slot->state = (req == ENABLE_REQ) ? POWERON_STATE : POWEROFF_STATE;
info = kmalloc(sizeof(*info), GFP_KERNEL);
if (!info) {
ctrl_err(p_slot->ctrl, "no memory to queue %s request\n",
(req == ENABLE_REQ) ? "poweron" : "poweroff");
return;
}
info->p_slot = p_slot;
INIT_WORK(&info->work, pciehp_power_thread);
info->req = req;
queue_work(p_slot->wq, &info->work);
}
void pciehp_queue_pushbutton_work(struct work_struct *work)
{
struct slot *p_slot = container_of(work, struct slot, work.work);
mutex_lock(&p_slot->lock);
switch (p_slot->state) {
case BLINKINGOFF_STATE:
pciehp_queue_power_work(p_slot, DISABLE_REQ);
break;
case BLINKINGON_STATE:
pciehp_queue_power_work(p_slot, ENABLE_REQ);
break;
default:
break;
}
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
ctrl_warn(ctrl, "ignoring invalid state %#x\n", p_slot->state);
break;
}
}
static void handle_surprise_event(struct slot *p_slot)
{
u8 getstatus;
pciehp_get_adapter_status(p_slot, &getstatus);
if (!getstatus)
pciehp_queue_power_work(p_slot, DISABLE_REQ);
else
pciehp_queue_power_work(p_slot, ENABLE_REQ);
}
static void handle_link_event(struct slot *p_slot, u32 event)
{
struct controller *ctrl = p_slot->ctrl;
switch (p_slot->state) {
case BLINKINGON_STATE:
case BLINKINGOFF_STATE:
cancel_delayed_work(&p_slot->work);
case STATIC_STATE:
pciehp_queue_power_work(p_slot, event == INT_LINK_UP ?
ENABLE_REQ : DISABLE_REQ);
break;
case POWERON_STATE:
if (event == INT_LINK_UP) {
ctrl_info(ctrl,
"Link Up event ignored on slot(%s): already powering on\n",
slot_name(p_slot));
} else {
ctrl_info(ctrl,
"Link Down event queued on slot(%s): currently getting powered on\n",
slot_name(p_slot));
pciehp_queue_power_work(p_slot, DISABLE_REQ);
}
break;
case POWEROFF_STATE:
if (event == INT_LINK_UP) {
ctrl_info(ctrl,
"Link Up event queued on slot(%s): currently getting powered off\n",
slot_name(p_slot));
pciehp_queue_power_work(p_slot, ENABLE_REQ);
} else {
ctrl_info(ctrl,
"Link Down event ignored on slot(%s): already powering off\n",
slot_name(p_slot));
}
break;
default:
ctrl_err(ctrl, "ignoring invalid state %#x on slot(%s)\n",
p_slot->state, slot_name(p_slot));
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
handle_surprise_event(p_slot);
break;
case INT_PRESENCE_OFF:
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
ctrl_err(ctrl, "invalid state %#x on slot %s\n",
p_slot->state, slot_name(p_slot));
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
ctrl_err(ctrl, "invalid state %#x on slot %s\n",
p_slot->state, slot_name(p_slot));
break;
}
mutex_unlock(&p_slot->lock);
return retval;
}
