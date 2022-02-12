static void format_hwmsg(char *msg, size_t msgl, const char *hwmsg)
{
strlcat(msg, "[", msgl);
strlcat(msg, hwmsg, msgl);
strlcat(msg, "]", msgl);
}
void hfi1_format_hwerrors(u64 hwerrs, const struct hfi1_hwerror_msgs *hwerrmsgs,
size_t nhwerrmsgs, char *msg, size_t msgl)
{
int i;
for (i = 0; i < nhwerrmsgs; i++)
if (hwerrs & hwerrmsgs[i].mask)
format_hwmsg(msg, msgl, hwerrmsgs[i].msg);
}
static void signal_ib_event(struct hfi1_pportdata *ppd, enum ib_event_type ev)
{
struct ib_event event;
struct hfi1_devdata *dd = ppd->dd;
if (!(dd->flags & HFI1_INITTED))
return;
event.device = &dd->verbs_dev.rdi.ibdev;
event.element.port_num = ppd->port;
event.event = ev;
ib_dispatch_event(&event);
}
void handle_linkup_change(struct hfi1_devdata *dd, u32 linkup)
{
struct hfi1_pportdata *ppd = &dd->pport[0];
enum ib_event_type ev;
if (!(ppd->linkup ^ !!linkup))
return;
if (linkup) {
if (quick_linkup || dd->icode == ICODE_FUNCTIONAL_SIMULATOR) {
set_up_vau(dd, dd->vau);
set_up_vl15(dd, dd->vl15_init);
assign_remote_cm_au_table(dd, dd->vcu);
}
ppd->neighbor_guid =
read_csr(dd, DC_DC8051_STS_REMOTE_GUID);
ppd->neighbor_type =
read_csr(dd, DC_DC8051_STS_REMOTE_NODE_TYPE) &
DC_DC8051_STS_REMOTE_NODE_TYPE_VAL_MASK;
ppd->neighbor_port_number =
read_csr(dd, DC_DC8051_STS_REMOTE_PORT_NO) &
DC_DC8051_STS_REMOTE_PORT_NO_VAL_SMASK;
ppd->neighbor_fm_security =
read_csr(dd, DC_DC8051_STS_REMOTE_FM_SECURITY) &
DC_DC8051_STS_LOCAL_FM_SECURITY_DISABLED_MASK;
dd_dev_info(dd,
"Neighbor Guid %llx, Type %d, Port Num %d\n",
ppd->neighbor_guid, ppd->neighbor_type,
ppd->neighbor_port_number);
ppd->linkup = 1;
ppd->offline_disabled_reason =
HFI1_ODR_MASK(OPA_LINKDOWN_REASON_NONE);
get_linkup_link_widths(ppd);
} else {
ppd->linkup = 0;
ppd->actual_vls_operational = 0;
reset_link_credits(dd);
start_freeze_handling(ppd, FREEZE_SELF | FREEZE_LINK_DOWN);
ev = IB_EVENT_PORT_ERR;
hfi1_set_uevent_bits(ppd, _HFI1_EVENT_LINKDOWN_BIT);
ppd->neighbor_normal = 0;
signal_ib_event(ppd, ev);
}
}
void handle_user_interrupt(struct hfi1_ctxtdata *rcd)
{
struct hfi1_devdata *dd = rcd->dd;
unsigned long flags;
spin_lock_irqsave(&dd->uctxt_lock, flags);
if (bitmap_empty(rcd->in_use_ctxts, HFI1_MAX_SHARED_CTXTS))
goto done;
if (test_and_clear_bit(HFI1_CTXT_WAITING_RCV, &rcd->event_flags)) {
wake_up_interruptible(&rcd->wait);
hfi1_rcvctrl(dd, HFI1_RCVCTRL_INTRAVAIL_DIS, rcd);
} else if (test_and_clear_bit(HFI1_CTXT_WAITING_URG,
&rcd->event_flags)) {
rcd->urgent++;
wake_up_interruptible(&rcd->wait);
}
done:
spin_unlock_irqrestore(&dd->uctxt_lock, flags);
}
