static unsigned ehci_moschip_read_frame_index(struct ehci_hcd *ehci)
{
unsigned uf;
uf = ehci_readl(ehci, &ehci->regs->frame_index);
if (unlikely((uf & 7) == 0))
uf = ehci_readl(ehci, &ehci->regs->frame_index);
return uf;
}
static inline unsigned ehci_read_frame_index(struct ehci_hcd *ehci)
{
if (ehci->frame_index_bug)
return ehci_moschip_read_frame_index(ehci);
return ehci_readl(ehci, &ehci->regs->frame_index);
}
int ehci_handshake(struct ehci_hcd *ehci, void __iomem *ptr,
u32 mask, u32 done, int usec)
{
u32 result;
do {
result = ehci_readl(ehci, ptr);
if (result == ~(u32)0)
return -ENODEV;
result &= mask;
if (result == done)
return 0;
udelay (1);
usec--;
} while (usec > 0);
return -ETIMEDOUT;
}
static int tdi_in_host_mode (struct ehci_hcd *ehci)
{
u32 tmp;
tmp = ehci_readl(ehci, &ehci->regs->usbmode);
return (tmp & 3) == USBMODE_CM_HC;
}
static int ehci_halt (struct ehci_hcd *ehci)
{
u32 temp;
spin_lock_irq(&ehci->lock);
ehci_writel(ehci, 0, &ehci->regs->intr_enable);
if (ehci_is_TDI(ehci) && !tdi_in_host_mode(ehci)) {
spin_unlock_irq(&ehci->lock);
return 0;
}
ehci->command &= ~CMD_RUN;
temp = ehci_readl(ehci, &ehci->regs->command);
temp &= ~(CMD_RUN | CMD_IAAD);
ehci_writel(ehci, temp, &ehci->regs->command);
spin_unlock_irq(&ehci->lock);
synchronize_irq(ehci_to_hcd(ehci)->irq);
return ehci_handshake(ehci, &ehci->regs->status,
STS_HALT, STS_HALT, 16 * 125);
}
static void tdi_reset (struct ehci_hcd *ehci)
{
u32 tmp;
tmp = ehci_readl(ehci, &ehci->regs->usbmode);
tmp |= USBMODE_CM_HC;
if (ehci_big_endian_mmio(ehci))
tmp |= USBMODE_BE;
ehci_writel(ehci, tmp, &ehci->regs->usbmode);
}
static int ehci_reset (struct ehci_hcd *ehci)
{
int retval;
u32 command = ehci_readl(ehci, &ehci->regs->command);
if (ehci->debug && !dbgp_reset_prep(ehci_to_hcd(ehci)))
ehci->debug = NULL;
command |= CMD_RESET;
dbg_cmd (ehci, "reset", command);
ehci_writel(ehci, command, &ehci->regs->command);
ehci->rh_state = EHCI_RH_HALTED;
ehci->next_statechange = jiffies;
retval = ehci_handshake(ehci, &ehci->regs->command,
CMD_RESET, 0, 250 * 1000);
if (ehci->has_hostpc) {
ehci_writel(ehci, USBMODE_EX_HC | USBMODE_EX_VBPS,
&ehci->regs->usbmode_ex);
ehci_writel(ehci, TXFIFO_DEFAULT, &ehci->regs->txfill_tuning);
}
if (retval)
return retval;
if (ehci_is_TDI(ehci))
tdi_reset (ehci);
if (ehci->debug)
dbgp_external_startup(ehci_to_hcd(ehci));
ehci->port_c_suspend = ehci->suspended_ports =
ehci->resuming_ports = 0;
return retval;
}
static void ehci_quiesce (struct ehci_hcd *ehci)
{
u32 temp;
if (ehci->rh_state != EHCI_RH_RUNNING)
return;
temp = (ehci->command << 10) & (STS_ASS | STS_PSS);
ehci_handshake(ehci, &ehci->regs->status, STS_ASS | STS_PSS, temp,
16 * 125);
spin_lock_irq(&ehci->lock);
ehci->command &= ~(CMD_ASE | CMD_PSE);
ehci_writel(ehci, ehci->command, &ehci->regs->command);
spin_unlock_irq(&ehci->lock);
ehci_handshake(ehci, &ehci->regs->status, STS_ASS | STS_PSS, 0,
16 * 125);
}
static void ehci_turn_off_all_ports(struct ehci_hcd *ehci)
{
int port = HCS_N_PORTS(ehci->hcs_params);
while (port--)
ehci_writel(ehci, PORT_RWC_BITS,
&ehci->regs->port_status[port]);
}
static void ehci_silence_controller(struct ehci_hcd *ehci)
{
ehci_halt(ehci);
spin_lock_irq(&ehci->lock);
ehci->rh_state = EHCI_RH_HALTED;
ehci_turn_off_all_ports(ehci);
ehci_writel(ehci, 0, &ehci->regs->configured_flag);
ehci_readl(ehci, &ehci->regs->configured_flag);
spin_unlock_irq(&ehci->lock);
}
static void ehci_shutdown(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
spin_lock_irq(&ehci->lock);
ehci->shutdown = true;
ehci->rh_state = EHCI_RH_STOPPING;
ehci->enabled_hrtimer_events = 0;
spin_unlock_irq(&ehci->lock);
ehci_silence_controller(ehci);
hrtimer_cancel(&ehci->hrtimer);
}
static void ehci_work (struct ehci_hcd *ehci)
{
if (ehci->scanning) {
ehci->need_rescan = true;
return;
}
ehci->scanning = true;
rescan:
ehci->need_rescan = false;
if (ehci->async_count)
scan_async(ehci);
if (ehci->intr_count > 0)
scan_intr(ehci);
if (ehci->isoc_count > 0)
scan_isoc(ehci);
if (ehci->need_rescan)
goto rescan;
ehci->scanning = false;
turn_on_io_watchdog(ehci);
}
static void ehci_stop (struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci (hcd);
ehci_dbg (ehci, "stop\n");
spin_lock_irq(&ehci->lock);
ehci->enabled_hrtimer_events = 0;
spin_unlock_irq(&ehci->lock);
ehci_quiesce(ehci);
ehci_silence_controller(ehci);
ehci_reset (ehci);
hrtimer_cancel(&ehci->hrtimer);
remove_sysfs_files(ehci);
remove_debug_files (ehci);
spin_lock_irq (&ehci->lock);
end_free_itds(ehci);
spin_unlock_irq (&ehci->lock);
ehci_mem_cleanup (ehci);
if (ehci->amd_pll_fix == 1)
usb_amd_dev_put();
dbg_status (ehci, "ehci_stop completed",
ehci_readl(ehci, &ehci->regs->status));
}
static int ehci_init(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
u32 temp;
int retval;
u32 hcc_params;
struct ehci_qh_hw *hw;
spin_lock_init(&ehci->lock);
ehci->need_io_watchdog = 1;
hrtimer_init(&ehci->hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
ehci->hrtimer.function = ehci_hrtimer_func;
ehci->next_hrtimer_event = EHCI_HRTIMER_NO_EVENT;
hcc_params = ehci_readl(ehci, &ehci->caps->hcc_params);
ehci->uframe_periodic_max = 100;
ehci->periodic_size = DEFAULT_I_TDPS;
INIT_LIST_HEAD(&ehci->async_unlink);
INIT_LIST_HEAD(&ehci->async_idle);
INIT_LIST_HEAD(&ehci->intr_unlink_wait);
INIT_LIST_HEAD(&ehci->intr_unlink);
INIT_LIST_HEAD(&ehci->intr_qh_list);
INIT_LIST_HEAD(&ehci->cached_itd_list);
INIT_LIST_HEAD(&ehci->cached_sitd_list);
INIT_LIST_HEAD(&ehci->tt_list);
if (HCC_PGM_FRAMELISTLEN(hcc_params)) {
switch (EHCI_TUNE_FLS) {
case 0: ehci->periodic_size = 1024; break;
case 1: ehci->periodic_size = 512; break;
case 2: ehci->periodic_size = 256; break;
default: BUG();
}
}
if ((retval = ehci_mem_init(ehci, GFP_KERNEL)) < 0)
return retval;
if (HCC_ISOC_CACHE(hcc_params))
ehci->i_thresh = 0;
else
ehci->i_thresh = 2 + HCC_ISOC_THRES(hcc_params);
ehci->async->qh_next.qh = NULL;
hw = ehci->async->hw;
hw->hw_next = QH_NEXT(ehci, ehci->async->qh_dma);
hw->hw_info1 = cpu_to_hc32(ehci, QH_HEAD);
#if defined(CONFIG_PPC_PS3)
hw->hw_info1 |= cpu_to_hc32(ehci, QH_INACTIVATE);
#endif
hw->hw_token = cpu_to_hc32(ehci, QTD_STS_HALT);
hw->hw_qtd_next = EHCI_LIST_END(ehci);
ehci->async->qh_state = QH_STATE_LINKED;
hw->hw_alt_next = QTD_NEXT(ehci, ehci->async->dummy->qtd_dma);
if (log2_irq_thresh < 0 || log2_irq_thresh > 6)
log2_irq_thresh = 0;
temp = 1 << (16 + log2_irq_thresh);
if (HCC_PER_PORT_CHANGE_EVENT(hcc_params)) {
ehci->has_ppcd = 1;
ehci_dbg(ehci, "enable per-port change event\n");
temp |= CMD_PPCEE;
}
if (HCC_CANPARK(hcc_params)) {
if (park) {
park = min(park, (unsigned) 3);
temp |= CMD_PARK;
temp |= park << 8;
}
ehci_dbg(ehci, "park %d\n", park);
}
if (HCC_PGM_FRAMELISTLEN(hcc_params)) {
temp &= ~(3 << 2);
temp |= (EHCI_TUNE_FLS << 2);
}
ehci->command = temp;
if (!(hcd->driver->flags & HCD_LOCAL_MEM))
hcd->self.sg_tablesize = ~0;
return 0;
}
static int ehci_run (struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci (hcd);
u32 temp;
u32 hcc_params;
hcd->uses_new_polling = 1;
ehci_writel(ehci, ehci->periodic_dma, &ehci->regs->frame_list);
ehci_writel(ehci, (u32)ehci->async->qh_dma, &ehci->regs->async_next);
hcc_params = ehci_readl(ehci, &ehci->caps->hcc_params);
if (HCC_64BIT_ADDR(hcc_params)) {
ehci_writel(ehci, 0, &ehci->regs->segment);
#if 0
if (!dma_set_mask(hcd->self.controller, DMA_BIT_MASK(64)))
ehci_info(ehci, "enabled 64bit DMA\n");
#endif
}
ehci->command &= ~(CMD_LRESET|CMD_IAAD|CMD_PSE|CMD_ASE|CMD_RESET);
ehci->command |= CMD_RUN;
ehci_writel(ehci, ehci->command, &ehci->regs->command);
dbg_cmd (ehci, "init", ehci->command);
down_write(&ehci_cf_port_reset_rwsem);
ehci->rh_state = EHCI_RH_RUNNING;
ehci_writel(ehci, FLAG_CF, &ehci->regs->configured_flag);
ehci_readl(ehci, &ehci->regs->command);
msleep(5);
up_write(&ehci_cf_port_reset_rwsem);
ehci->last_periodic_enable = ktime_get_real();
temp = HC_VERSION(ehci, ehci_readl(ehci, &ehci->caps->hc_capbase));
ehci_info (ehci,
"USB %x.%x started, EHCI %x.%02x%s\n",
((ehci->sbrn & 0xf0)>>4), (ehci->sbrn & 0x0f),
temp >> 8, temp & 0xff,
ignore_oc ? ", overcurrent ignored" : "");
ehci_writel(ehci, INTR_MASK,
&ehci->regs->intr_enable);
create_debug_files(ehci);
create_sysfs_files(ehci);
return 0;
}
int ehci_setup(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
int retval;
ehci->regs = (void __iomem *)ehci->caps +
HC_LENGTH(ehci, ehci_readl(ehci, &ehci->caps->hc_capbase));
dbg_hcs_params(ehci, "reset");
dbg_hcc_params(ehci, "reset");
ehci->hcs_params = ehci_readl(ehci, &ehci->caps->hcs_params);
ehci->sbrn = HCD_USB2;
retval = ehci_init(hcd);
if (retval)
return retval;
retval = ehci_halt(ehci);
if (retval)
return retval;
ehci_reset(ehci);
return 0;
}
static irqreturn_t ehci_irq (struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci (hcd);
u32 status, masked_status, pcd_status = 0, cmd;
int bh;
unsigned long flags;
spin_lock_irqsave(&ehci->lock, flags);
status = ehci_readl(ehci, &ehci->regs->status);
if (status == ~(u32) 0) {
ehci_dbg (ehci, "device removed\n");
goto dead;
}
masked_status = status & (INTR_MASK | STS_FLR);
if (!masked_status || unlikely(ehci->rh_state == EHCI_RH_HALTED)) {
spin_unlock_irqrestore(&ehci->lock, flags);
return IRQ_NONE;
}
ehci_writel(ehci, masked_status, &ehci->regs->status);
cmd = ehci_readl(ehci, &ehci->regs->command);
bh = 0;
if (likely ((status & (STS_INT|STS_ERR)) != 0)) {
if (likely ((status & STS_ERR) == 0))
COUNT (ehci->stats.normal);
else
COUNT (ehci->stats.error);
bh = 1;
}
if (status & STS_IAA) {
ehci->enabled_hrtimer_events &= ~BIT(EHCI_HRTIMER_IAA_WATCHDOG);
if (ehci->next_hrtimer_event == EHCI_HRTIMER_IAA_WATCHDOG)
++ehci->next_hrtimer_event;
if (cmd & CMD_IAAD)
ehci_dbg(ehci, "IAA with IAAD still set?\n");
if (ehci->iaa_in_progress)
COUNT(ehci->stats.iaa);
end_unlink_async(ehci);
}
if (status & STS_PCD) {
unsigned i = HCS_N_PORTS (ehci->hcs_params);
u32 ppcd = ~0;
pcd_status = status;
if (ehci->rh_state == EHCI_RH_SUSPENDED)
usb_hcd_resume_root_hub(hcd);
if (ehci->has_ppcd)
ppcd = status >> 16;
while (i--) {
int pstatus;
if (!(ppcd & (1 << i)))
continue;
pstatus = ehci_readl(ehci,
&ehci->regs->port_status[i]);
if (pstatus & PORT_OWNER)
continue;
if (!(test_bit(i, &ehci->suspended_ports) &&
((pstatus & PORT_RESUME) ||
!(pstatus & PORT_SUSPEND)) &&
(pstatus & PORT_PE) &&
ehci->reset_done[i] == 0))
continue;
ehci->reset_done[i] = jiffies + msecs_to_jiffies(25);
set_bit(i, &ehci->resuming_ports);
ehci_dbg (ehci, "port %d remote wakeup\n", i + 1);
usb_hcd_start_port_resume(&hcd->self, i);
mod_timer(&hcd->rh_timer, ehci->reset_done[i]);
}
}
if (unlikely ((status & STS_FATAL) != 0)) {
ehci_err(ehci, "fatal error\n");
dbg_cmd(ehci, "fatal", cmd);
dbg_status(ehci, "fatal", status);
dead:
usb_hc_died(hcd);
ehci->shutdown = true;
ehci->rh_state = EHCI_RH_STOPPING;
ehci->command &= ~(CMD_RUN | CMD_ASE | CMD_PSE);
ehci_writel(ehci, ehci->command, &ehci->regs->command);
ehci_writel(ehci, 0, &ehci->regs->intr_enable);
ehci_handle_controller_death(ehci);
bh = 0;
}
if (bh)
ehci_work (ehci);
spin_unlock_irqrestore(&ehci->lock, flags);
if (pcd_status)
usb_hcd_poll_rh_status(hcd);
return IRQ_HANDLED;
}
static int ehci_urb_enqueue (
struct usb_hcd *hcd,
struct urb *urb,
gfp_t mem_flags
) {
struct ehci_hcd *ehci = hcd_to_ehci (hcd);
struct list_head qtd_list;
INIT_LIST_HEAD (&qtd_list);
switch (usb_pipetype (urb->pipe)) {
case PIPE_CONTROL:
if (urb->transfer_buffer_length > (16 * 1024))
return -EMSGSIZE;
default:
if (!qh_urb_transaction (ehci, urb, &qtd_list, mem_flags))
return -ENOMEM;
return submit_async(ehci, urb, &qtd_list, mem_flags);
case PIPE_INTERRUPT:
if (!qh_urb_transaction (ehci, urb, &qtd_list, mem_flags))
return -ENOMEM;
return intr_submit(ehci, urb, &qtd_list, mem_flags);
case PIPE_ISOCHRONOUS:
if (urb->dev->speed == USB_SPEED_HIGH)
return itd_submit (ehci, urb, mem_flags);
else
return sitd_submit (ehci, urb, mem_flags);
}
}
static int ehci_urb_dequeue(struct usb_hcd *hcd, struct urb *urb, int status)
{
struct ehci_hcd *ehci = hcd_to_ehci (hcd);
struct ehci_qh *qh;
unsigned long flags;
int rc;
spin_lock_irqsave (&ehci->lock, flags);
rc = usb_hcd_check_unlink_urb(hcd, urb, status);
if (rc)
goto done;
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS) {
} else {
qh = (struct ehci_qh *) urb->hcpriv;
qh->exception = 1;
switch (qh->qh_state) {
case QH_STATE_LINKED:
if (usb_pipetype(urb->pipe) == PIPE_INTERRUPT)
start_unlink_intr(ehci, qh);
else
start_unlink_async(ehci, qh);
break;
case QH_STATE_COMPLETING:
qh->dequeue_during_giveback = 1;
break;
case QH_STATE_UNLINK:
case QH_STATE_UNLINK_WAIT:
break;
case QH_STATE_IDLE:
qh_completions(ehci, qh);
break;
}
}
done:
spin_unlock_irqrestore (&ehci->lock, flags);
return rc;
}
static void
ehci_endpoint_disable (struct usb_hcd *hcd, struct usb_host_endpoint *ep)
{
struct ehci_hcd *ehci = hcd_to_ehci (hcd);
unsigned long flags;
struct ehci_qh *qh;
rescan:
spin_lock_irqsave (&ehci->lock, flags);
qh = ep->hcpriv;
if (!qh)
goto done;
if (qh->hw == NULL) {
struct ehci_iso_stream *stream = ep->hcpriv;
if (!list_empty(&stream->td_list))
goto idle_timeout;
reserve_release_iso_bandwidth(ehci, stream, -1);
kfree(stream);
goto done;
}
qh->exception = 1;
switch (qh->qh_state) {
case QH_STATE_LINKED:
WARN_ON(!list_empty(&qh->qtd_list));
if (usb_endpoint_type(&ep->desc) != USB_ENDPOINT_XFER_INT)
start_unlink_async(ehci, qh);
else
start_unlink_intr(ehci, qh);
case QH_STATE_COMPLETING:
case QH_STATE_UNLINK:
case QH_STATE_UNLINK_WAIT:
idle_timeout:
spin_unlock_irqrestore (&ehci->lock, flags);
schedule_timeout_uninterruptible(1);
goto rescan;
case QH_STATE_IDLE:
if (qh->clearing_tt)
goto idle_timeout;
if (list_empty (&qh->qtd_list)) {
if (qh->ps.bw_uperiod)
reserve_release_intr_bandwidth(ehci, qh, -1);
qh_destroy(ehci, qh);
break;
}
default:
ehci_err (ehci, "qh %p (#%02x) state %d%s\n",
qh, ep->desc.bEndpointAddress, qh->qh_state,
list_empty (&qh->qtd_list) ? "" : "(has tds)");
break;
}
done:
ep->hcpriv = NULL;
spin_unlock_irqrestore (&ehci->lock, flags);
}
static void
ehci_endpoint_reset(struct usb_hcd *hcd, struct usb_host_endpoint *ep)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
struct ehci_qh *qh;
int eptype = usb_endpoint_type(&ep->desc);
int epnum = usb_endpoint_num(&ep->desc);
int is_out = usb_endpoint_dir_out(&ep->desc);
unsigned long flags;
if (eptype != USB_ENDPOINT_XFER_BULK && eptype != USB_ENDPOINT_XFER_INT)
return;
spin_lock_irqsave(&ehci->lock, flags);
qh = ep->hcpriv;
if (qh) {
if (!list_empty(&qh->qtd_list)) {
WARN_ONCE(1, "clear_halt for a busy endpoint\n");
} else {
usb_settoggle(qh->ps.udev, epnum, is_out, 0);
qh->exception = 1;
if (eptype == USB_ENDPOINT_XFER_BULK)
start_unlink_async(ehci, qh);
else
start_unlink_intr(ehci, qh);
}
}
spin_unlock_irqrestore(&ehci->lock, flags);
}
static int ehci_get_frame (struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci (hcd);
return (ehci_read_frame_index(ehci) >> 3) % ehci->periodic_size;
}
static void ehci_remove_device(struct usb_hcd *hcd, struct usb_device *udev)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
spin_lock_irq(&ehci->lock);
drop_tt(udev);
spin_unlock_irq(&ehci->lock);
}
int ehci_suspend(struct usb_hcd *hcd, bool do_wakeup)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
if (time_before(jiffies, ehci->next_statechange))
msleep(10);
ehci_prepare_ports_for_controller_suspend(ehci, do_wakeup);
spin_lock_irq(&ehci->lock);
ehci_writel(ehci, 0, &ehci->regs->intr_enable);
(void) ehci_readl(ehci, &ehci->regs->intr_enable);
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
spin_unlock_irq(&ehci->lock);
synchronize_irq(hcd->irq);
if (do_wakeup && HCD_WAKEUP_PENDING(hcd)) {
ehci_resume(hcd, false);
return -EBUSY;
}
return 0;
}
int ehci_resume(struct usb_hcd *hcd, bool hibernated)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
if (time_before(jiffies, ehci->next_statechange))
msleep(100);
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
if (ehci->shutdown)
return 0;
if (ehci_readl(ehci, &ehci->regs->configured_flag) == FLAG_CF &&
!hibernated) {
int mask = INTR_MASK;
ehci_prepare_ports_for_controller_resume(ehci);
spin_lock_irq(&ehci->lock);
if (ehci->shutdown)
goto skip;
if (!hcd->self.root_hub->do_remote_wakeup)
mask &= ~STS_PCD;
ehci_writel(ehci, mask, &ehci->regs->intr_enable);
ehci_readl(ehci, &ehci->regs->intr_enable);
skip:
spin_unlock_irq(&ehci->lock);
return 0;
}
usb_root_hub_lost_power(hcd->self.root_hub);
(void) ehci_halt(ehci);
(void) ehci_reset(ehci);
spin_lock_irq(&ehci->lock);
if (ehci->shutdown)
goto skip;
ehci_writel(ehci, ehci->command, &ehci->regs->command);
ehci_writel(ehci, FLAG_CF, &ehci->regs->configured_flag);
ehci_readl(ehci, &ehci->regs->command);
ehci->rh_state = EHCI_RH_SUSPENDED;
spin_unlock_irq(&ehci->lock);
return 1;
}
void ehci_init_driver(struct hc_driver *drv,
const struct ehci_driver_overrides *over)
{
*drv = ehci_hc_driver;
if (over) {
drv->hcd_priv_size += over->extra_priv_size;
if (over->reset)
drv->reset = over->reset;
}
}
static int __init ehci_hcd_init(void)
{
int retval = 0;
if (usb_disabled())
return -ENODEV;
printk(KERN_INFO "%s: " DRIVER_DESC "\n", hcd_name);
set_bit(USB_EHCI_LOADED, &usb_hcds_loaded);
if (test_bit(USB_UHCI_LOADED, &usb_hcds_loaded) ||
test_bit(USB_OHCI_LOADED, &usb_hcds_loaded))
printk(KERN_WARNING "Warning! ehci_hcd should always be loaded"
" before uhci_hcd and ohci_hcd, not after\n");
pr_debug("%s: block sizes: qh %Zd qtd %Zd itd %Zd sitd %Zd\n",
hcd_name,
sizeof(struct ehci_qh), sizeof(struct ehci_qtd),
sizeof(struct ehci_itd), sizeof(struct ehci_sitd));
#ifdef CONFIG_DYNAMIC_DEBUG
ehci_debug_root = debugfs_create_dir("ehci", usb_debug_root);
if (!ehci_debug_root) {
retval = -ENOENT;
goto err_debug;
}
#endif
#ifdef PLATFORM_DRIVER
retval = platform_driver_register(&PLATFORM_DRIVER);
if (retval < 0)
goto clean0;
#endif
#ifdef PS3_SYSTEM_BUS_DRIVER
retval = ps3_ehci_driver_register(&PS3_SYSTEM_BUS_DRIVER);
if (retval < 0)
goto clean2;
#endif
#ifdef OF_PLATFORM_DRIVER
retval = platform_driver_register(&OF_PLATFORM_DRIVER);
if (retval < 0)
goto clean3;
#endif
#ifdef XILINX_OF_PLATFORM_DRIVER
retval = platform_driver_register(&XILINX_OF_PLATFORM_DRIVER);
if (retval < 0)
goto clean4;
#endif
return retval;
#ifdef XILINX_OF_PLATFORM_DRIVER
clean4:
#endif
#ifdef OF_PLATFORM_DRIVER
platform_driver_unregister(&OF_PLATFORM_DRIVER);
clean3:
#endif
#ifdef PS3_SYSTEM_BUS_DRIVER
ps3_ehci_driver_unregister(&PS3_SYSTEM_BUS_DRIVER);
clean2:
#endif
#ifdef PLATFORM_DRIVER
platform_driver_unregister(&PLATFORM_DRIVER);
clean0:
#endif
#ifdef CONFIG_DYNAMIC_DEBUG
debugfs_remove(ehci_debug_root);
ehci_debug_root = NULL;
err_debug:
#endif
clear_bit(USB_EHCI_LOADED, &usb_hcds_loaded);
return retval;
}
static void __exit ehci_hcd_cleanup(void)
{
#ifdef XILINX_OF_PLATFORM_DRIVER
platform_driver_unregister(&XILINX_OF_PLATFORM_DRIVER);
#endif
#ifdef OF_PLATFORM_DRIVER
platform_driver_unregister(&OF_PLATFORM_DRIVER);
#endif
#ifdef PLATFORM_DRIVER
platform_driver_unregister(&PLATFORM_DRIVER);
#endif
#ifdef PS3_SYSTEM_BUS_DRIVER
ps3_ehci_driver_unregister(&PS3_SYSTEM_BUS_DRIVER);
#endif
#ifdef CONFIG_DYNAMIC_DEBUG
debugfs_remove(ehci_debug_root);
#endif
clear_bit(USB_EHCI_LOADED, &usb_hcds_loaded);
}
