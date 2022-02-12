u32 hw_read_otgsc(struct ci_hdrc *ci, u32 mask)
{
return hw_read(ci, OP_OTGSC, mask);
}
void hw_write_otgsc(struct ci_hdrc *ci, u32 mask, u32 data)
{
hw_write(ci, OP_OTGSC, mask | OTGSC_INT_STATUS_BITS, data);
}
enum ci_role ci_otg_role(struct ci_hdrc *ci)
{
enum ci_role role = hw_read_otgsc(ci, OTGSC_ID)
? CI_ROLE_GADGET
: CI_ROLE_HOST;
return role;
}
void ci_handle_vbus_change(struct ci_hdrc *ci)
{
if (!ci->is_otg)
return;
if (hw_read_otgsc(ci, OTGSC_BSV))
usb_gadget_vbus_connect(&ci->gadget);
else
usb_gadget_vbus_disconnect(&ci->gadget);
}
static void ci_handle_id_switch(struct ci_hdrc *ci)
{
enum ci_role role = ci_otg_role(ci);
if (role != ci->role) {
dev_dbg(ci->dev, "switching from %s to %s\n",
ci_role(ci)->name, ci->roles[role]->name);
ci_role_stop(ci);
hw_wait_reg(ci, OP_OTGSC, OTGSC_BSV, 0,
CI_VBUS_STABLE_TIMEOUT_MS);
ci_role_start(ci, role);
}
}
static void ci_otg_work(struct work_struct *work)
{
struct ci_hdrc *ci = container_of(work, struct ci_hdrc, work);
if (ci_otg_is_fsm_mode(ci) && !ci_otg_fsm_work(ci)) {
enable_irq(ci->irq);
return;
}
if (ci->id_event) {
ci->id_event = false;
ci_handle_id_switch(ci);
} else if (ci->b_sess_valid_event) {
ci->b_sess_valid_event = false;
ci_handle_vbus_change(ci);
} else
dev_err(ci->dev, "unexpected event occurs at %s\n", __func__);
enable_irq(ci->irq);
}
int ci_hdrc_otg_init(struct ci_hdrc *ci)
{
INIT_WORK(&ci->work, ci_otg_work);
ci->wq = create_singlethread_workqueue("ci_otg");
if (!ci->wq) {
dev_err(ci->dev, "can't create workqueue\n");
return -ENODEV;
}
if (ci_otg_is_fsm_mode(ci))
return ci_hdrc_otg_fsm_init(ci);
return 0;
}
void ci_hdrc_otg_destroy(struct ci_hdrc *ci)
{
if (ci->wq) {
flush_workqueue(ci->wq);
destroy_workqueue(ci->wq);
}
hw_write_otgsc(ci, OTGSC_INT_EN_BITS | OTGSC_INT_STATUS_BITS,
OTGSC_INT_STATUS_BITS);
if (ci_otg_is_fsm_mode(ci))
ci_hdrc_otg_fsm_remove(ci);
}
