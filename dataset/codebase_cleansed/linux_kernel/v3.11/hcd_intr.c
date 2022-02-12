static void dwc2_track_missed_sofs(struct dwc2_hsotg *hsotg)
{
#ifdef CONFIG_USB_DWC2_TRACK_MISSED_SOFS
u16 curr_frame_number = hsotg->frame_number;
if (hsotg->frame_num_idx < FRAME_NUM_ARRAY_SIZE) {
if (((hsotg->last_frame_num + 1) & HFNUM_MAX_FRNUM) !=
curr_frame_number) {
hsotg->frame_num_array[hsotg->frame_num_idx] =
curr_frame_number;
hsotg->last_frame_num_array[hsotg->frame_num_idx] =
hsotg->last_frame_num;
hsotg->frame_num_idx++;
}
} else if (!hsotg->dumped_frame_num_array) {
int i;
dev_info(hsotg->dev, "Frame Last Frame\n");
dev_info(hsotg->dev, "----- ----------\n");
for (i = 0; i < FRAME_NUM_ARRAY_SIZE; i++) {
dev_info(hsotg->dev, "0x%04x 0x%04x\n",
hsotg->frame_num_array[i],
hsotg->last_frame_num_array[i]);
}
hsotg->dumped_frame_num_array = 1;
}
hsotg->last_frame_num = curr_frame_number;
#endif
}
static void dwc2_hc_handle_tt_clear(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan,
struct dwc2_qtd *qtd)
{
struct urb *usb_urb;
if (!chan->qh || !qtd->urb)
return;
usb_urb = qtd->urb->priv;
if (!usb_urb || !usb_urb->dev)
return;
if (chan->qh->dev_speed != USB_SPEED_HIGH &&
qtd->urb->status != -EPIPE && qtd->urb->status != -EREMOTEIO) {
chan->qh->tt_buffer_dirty = 1;
if (usb_hub_clear_tt_buffer(usb_urb))
chan->qh->tt_buffer_dirty = 0;
}
}
static void dwc2_sof_intr(struct dwc2_hsotg *hsotg)
{
struct list_head *qh_entry;
struct dwc2_qh *qh;
enum dwc2_transaction_type tr_type;
#ifdef DEBUG_SOF
dev_vdbg(hsotg->dev, "--Start of Frame Interrupt--\n");
#endif
hsotg->frame_number = dwc2_hcd_get_frame_number(hsotg);
dwc2_track_missed_sofs(hsotg);
qh_entry = hsotg->periodic_sched_inactive.next;
while (qh_entry != &hsotg->periodic_sched_inactive) {
qh = list_entry(qh_entry, struct dwc2_qh, qh_list_entry);
qh_entry = qh_entry->next;
if (dwc2_frame_num_le(qh->sched_frame, hsotg->frame_number))
list_move(&qh->qh_list_entry,
&hsotg->periodic_sched_ready);
}
tr_type = dwc2_hcd_select_transactions(hsotg);
if (tr_type != DWC2_TRANSACTION_NONE)
dwc2_hcd_queue_transactions(hsotg, tr_type);
writel(GINTSTS_SOF, hsotg->regs + GINTSTS);
}
static void dwc2_rx_fifo_level_intr(struct dwc2_hsotg *hsotg)
{
u32 grxsts, chnum, bcnt, dpid, pktsts;
struct dwc2_host_chan *chan;
if (dbg_perio())
dev_vdbg(hsotg->dev, "--RxFIFO Level Interrupt--\n");
grxsts = readl(hsotg->regs + GRXSTSP);
chnum = grxsts >> GRXSTS_HCHNUM_SHIFT &
GRXSTS_HCHNUM_MASK >> GRXSTS_HCHNUM_SHIFT;
chan = hsotg->hc_ptr_array[chnum];
if (!chan) {
dev_err(hsotg->dev, "Unable to get corresponding channel\n");
return;
}
bcnt = grxsts >> GRXSTS_BYTECNT_SHIFT &
GRXSTS_BYTECNT_MASK >> GRXSTS_BYTECNT_SHIFT;
dpid = grxsts >> GRXSTS_DPID_SHIFT &
GRXSTS_DPID_MASK >> GRXSTS_DPID_SHIFT;
pktsts = grxsts & GRXSTS_PKTSTS_MASK;
if (dbg_perio()) {
dev_vdbg(hsotg->dev, " Ch num = %d\n", chnum);
dev_vdbg(hsotg->dev, " Count = %d\n", bcnt);
dev_vdbg(hsotg->dev, " DPID = %d, chan.dpid = %d\n", dpid,
chan->data_pid_start);
dev_vdbg(hsotg->dev, " PStatus = %d\n",
pktsts >> GRXSTS_PKTSTS_SHIFT &
GRXSTS_PKTSTS_MASK >> GRXSTS_PKTSTS_SHIFT);
}
switch (pktsts) {
case GRXSTS_PKTSTS_HCHIN:
if (bcnt > 0) {
dwc2_read_packet(hsotg, chan->xfer_buf, bcnt);
chan->xfer_count += bcnt;
chan->xfer_buf += bcnt;
}
break;
case GRXSTS_PKTSTS_HCHIN_XFER_COMP:
case GRXSTS_PKTSTS_DATATOGGLEERR:
case GRXSTS_PKTSTS_HCHHALTED:
break;
default:
dev_err(hsotg->dev,
"RxFIFO Level Interrupt: Unknown status %d\n", pktsts);
break;
}
}
static void dwc2_np_tx_fifo_empty_intr(struct dwc2_hsotg *hsotg)
{
dev_vdbg(hsotg->dev, "--Non-Periodic TxFIFO Empty Interrupt--\n");
dwc2_hcd_queue_transactions(hsotg, DWC2_TRANSACTION_NON_PERIODIC);
}
static void dwc2_perio_tx_fifo_empty_intr(struct dwc2_hsotg *hsotg)
{
if (dbg_perio())
dev_vdbg(hsotg->dev, "--Periodic TxFIFO Empty Interrupt--\n");
dwc2_hcd_queue_transactions(hsotg, DWC2_TRANSACTION_PERIODIC);
}
static void dwc2_hprt0_enable(struct dwc2_hsotg *hsotg, u32 hprt0,
u32 *hprt0_modify)
{
struct dwc2_core_params *params = hsotg->core_params;
int do_reset = 0;
u32 usbcfg;
u32 prtspd;
u32 hcfg;
u32 fslspclksel;
u32 hfir;
dev_vdbg(hsotg->dev, "%s(%p)\n", __func__, hsotg);
hfir = readl(hsotg->regs + HFIR);
hfir &= ~HFIR_FRINT_MASK;
hfir |= dwc2_calc_frame_interval(hsotg) << HFIR_FRINT_SHIFT &
HFIR_FRINT_MASK;
writel(hfir, hsotg->regs + HFIR);
if (!params->host_support_fs_ls_low_power) {
hsotg->flags.b.port_reset_change = 1;
return;
}
usbcfg = readl(hsotg->regs + GUSBCFG);
prtspd = hprt0 & HPRT0_SPD_MASK;
if (prtspd == HPRT0_SPD_LOW_SPEED || prtspd == HPRT0_SPD_FULL_SPEED) {
if (!(usbcfg & GUSBCFG_PHY_LP_CLK_SEL)) {
usbcfg |= GUSBCFG_PHY_LP_CLK_SEL;
writel(usbcfg, hsotg->regs + GUSBCFG);
do_reset = 1;
}
hcfg = readl(hsotg->regs + HCFG);
fslspclksel = hcfg & HCFG_FSLSPCLKSEL_MASK;
if (prtspd == HPRT0_SPD_LOW_SPEED &&
params->host_ls_low_power_phy_clk ==
DWC2_HOST_LS_LOW_POWER_PHY_CLK_PARAM_6MHZ) {
dev_vdbg(hsotg->dev,
"FS_PHY programming HCFG to 6 MHz\n");
if (fslspclksel != HCFG_FSLSPCLKSEL_6_MHZ) {
hcfg &= ~HCFG_FSLSPCLKSEL_MASK;
hcfg |= HCFG_FSLSPCLKSEL_6_MHZ;
writel(hcfg, hsotg->regs + HCFG);
do_reset = 1;
}
} else {
dev_vdbg(hsotg->dev,
"FS_PHY programming HCFG to 48 MHz\n");
if (fslspclksel != HCFG_FSLSPCLKSEL_48_MHZ) {
hcfg &= ~HCFG_FSLSPCLKSEL_MASK;
hcfg |= HCFG_FSLSPCLKSEL_48_MHZ;
writel(hcfg, hsotg->regs + HCFG);
do_reset = 1;
}
}
} else {
if (usbcfg & GUSBCFG_PHY_LP_CLK_SEL) {
usbcfg &= ~GUSBCFG_PHY_LP_CLK_SEL;
writel(usbcfg, hsotg->regs + GUSBCFG);
do_reset = 1;
}
}
if (do_reset) {
*hprt0_modify |= HPRT0_RST;
queue_delayed_work(hsotg->wq_otg, &hsotg->reset_work,
msecs_to_jiffies(60));
} else {
hsotg->flags.b.port_reset_change = 1;
}
}
static void dwc2_port_intr(struct dwc2_hsotg *hsotg)
{
u32 hprt0;
u32 hprt0_modify;
dev_vdbg(hsotg->dev, "--Port Interrupt--\n");
hprt0 = readl(hsotg->regs + HPRT0);
hprt0_modify = hprt0;
hprt0_modify &= ~(HPRT0_ENA | HPRT0_CONNDET | HPRT0_ENACHG |
HPRT0_OVRCURRCHG);
if (hprt0 & HPRT0_CONNDET) {
dev_vdbg(hsotg->dev,
"--Port Interrupt HPRT0=0x%08x Port Connect Detected--\n",
hprt0);
hsotg->flags.b.port_connect_status_change = 1;
hsotg->flags.b.port_connect_status = 1;
hprt0_modify |= HPRT0_CONNDET;
}
if (hprt0 & HPRT0_ENACHG) {
dev_vdbg(hsotg->dev,
" --Port Interrupt HPRT0=0x%08x Port Enable Changed (now %d)--\n",
hprt0, !!(hprt0 & HPRT0_ENA));
hprt0_modify |= HPRT0_ENACHG;
if (hprt0 & HPRT0_ENA)
dwc2_hprt0_enable(hsotg, hprt0, &hprt0_modify);
else
hsotg->flags.b.port_enable_change = 1;
}
if (hprt0 & HPRT0_OVRCURRCHG) {
dev_vdbg(hsotg->dev,
" --Port Interrupt HPRT0=0x%08x Port Overcurrent Changed--\n",
hprt0);
hsotg->flags.b.port_over_current_change = 1;
hprt0_modify |= HPRT0_OVRCURRCHG;
}
writel(hprt0_modify, hsotg->regs + HPRT0);
}
static u32 dwc2_get_actual_xfer_length(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd,
enum dwc2_halt_status halt_status,
int *short_read)
{
u32 hctsiz, count, length;
hctsiz = readl(hsotg->regs + HCTSIZ(chnum));
if (halt_status == DWC2_HC_XFER_COMPLETE) {
if (chan->ep_is_in) {
count = hctsiz >> TSIZ_XFERSIZE_SHIFT &
TSIZ_XFERSIZE_MASK >> TSIZ_XFERSIZE_SHIFT;
length = chan->xfer_len - count;
if (short_read != NULL)
*short_read = (count != 0);
} else if (chan->qh->do_split) {
length = qtd->ssplit_out_xfer_count;
} else {
length = chan->xfer_len;
}
} else {
count = hctsiz >> TSIZ_PKTCNT_SHIFT &
TSIZ_PKTCNT_MASK >> TSIZ_PKTCNT_SHIFT;
length = (chan->start_pkt_count - count) * chan->max_packet;
}
return length;
}
static int dwc2_update_urb_state(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_hcd_urb *urb,
struct dwc2_qtd *qtd)
{
u32 hctsiz;
int xfer_done = 0;
int short_read = 0;
int xfer_length = dwc2_get_actual_xfer_length(hsotg, chan, chnum, qtd,
DWC2_HC_XFER_COMPLETE,
&short_read);
if (urb->actual_length + xfer_length > urb->length) {
dev_warn(hsotg->dev, "%s(): trimming xfer length\n", __func__);
xfer_length = urb->length - urb->actual_length;
}
if (chan->align_buf && xfer_length && chan->ep_is_in) {
dev_dbg(hsotg->dev, "%s(): non-aligned buffer\n", __func__);
dma_sync_single_for_cpu(hsotg->dev, urb->dma, urb->length,
DMA_FROM_DEVICE);
memcpy(urb->buf + urb->actual_length, chan->qh->dw_align_buf,
xfer_length);
dma_sync_single_for_device(hsotg->dev, urb->dma, urb->length,
DMA_FROM_DEVICE);
}
dev_vdbg(hsotg->dev, "urb->actual_length=%d xfer_length=%d\n",
urb->actual_length, xfer_length);
urb->actual_length += xfer_length;
if (xfer_length && chan->ep_type == USB_ENDPOINT_XFER_BULK &&
(urb->flags & URB_SEND_ZERO_PACKET) &&
urb->actual_length >= urb->length &&
!(urb->length % chan->max_packet)) {
xfer_done = 0;
} else if (short_read || urb->actual_length >= urb->length) {
xfer_done = 1;
urb->status = 0;
}
hctsiz = readl(hsotg->regs + HCTSIZ(chnum));
dev_vdbg(hsotg->dev, "DWC_otg: %s: %s, channel %d\n",
__func__, (chan->ep_is_in ? "IN" : "OUT"), chnum);
dev_vdbg(hsotg->dev, " chan->xfer_len %d\n", chan->xfer_len);
dev_vdbg(hsotg->dev, " hctsiz.xfersize %d\n",
hctsiz >> TSIZ_XFERSIZE_SHIFT &
TSIZ_XFERSIZE_MASK >> TSIZ_XFERSIZE_SHIFT);
dev_vdbg(hsotg->dev, " urb->transfer_buffer_length %d\n", urb->length);
dev_vdbg(hsotg->dev, " urb->actual_length %d\n", urb->actual_length);
dev_vdbg(hsotg->dev, " short_read %d, xfer_done %d\n", short_read,
xfer_done);
return xfer_done;
}
void dwc2_hcd_save_data_toggle(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
u32 hctsiz = readl(hsotg->regs + HCTSIZ(chnum));
u32 pid = hctsiz & TSIZ_SC_MC_PID_MASK;
if (chan->ep_type != USB_ENDPOINT_XFER_CONTROL) {
if (pid == TSIZ_SC_MC_PID_DATA0)
chan->qh->data_toggle = DWC2_HC_PID_DATA0;
else
chan->qh->data_toggle = DWC2_HC_PID_DATA1;
} else {
if (pid == TSIZ_SC_MC_PID_DATA0)
qtd->data_toggle = DWC2_HC_PID_DATA0;
else
qtd->data_toggle = DWC2_HC_PID_DATA1;
}
}
static enum dwc2_halt_status dwc2_update_isoc_urb_state(
struct dwc2_hsotg *hsotg, struct dwc2_host_chan *chan,
int chnum, struct dwc2_qtd *qtd,
enum dwc2_halt_status halt_status)
{
struct dwc2_hcd_iso_packet_desc *frame_desc;
struct dwc2_hcd_urb *urb = qtd->urb;
if (!urb)
return DWC2_HC_XFER_NO_HALT_STATUS;
frame_desc = &urb->iso_descs[qtd->isoc_frame_index];
switch (halt_status) {
case DWC2_HC_XFER_COMPLETE:
frame_desc->status = 0;
frame_desc->actual_length = dwc2_get_actual_xfer_length(hsotg,
chan, chnum, qtd, halt_status, NULL);
if (chan->align_buf && frame_desc->actual_length &&
chan->ep_is_in) {
dev_dbg(hsotg->dev, "%s(): non-aligned buffer\n",
__func__);
dma_sync_single_for_cpu(hsotg->dev, urb->dma,
urb->length, DMA_FROM_DEVICE);
memcpy(urb->buf + frame_desc->offset +
qtd->isoc_split_offset, chan->qh->dw_align_buf,
frame_desc->actual_length);
dma_sync_single_for_device(hsotg->dev, urb->dma,
urb->length,
DMA_FROM_DEVICE);
}
break;
case DWC2_HC_XFER_FRAME_OVERRUN:
urb->error_count++;
if (chan->ep_is_in)
frame_desc->status = -ENOSR;
else
frame_desc->status = -ECOMM;
frame_desc->actual_length = 0;
break;
case DWC2_HC_XFER_BABBLE_ERR:
urb->error_count++;
frame_desc->status = -EOVERFLOW;
break;
case DWC2_HC_XFER_XACT_ERR:
urb->error_count++;
frame_desc->status = -EPROTO;
frame_desc->actual_length = dwc2_get_actual_xfer_length(hsotg,
chan, chnum, qtd, halt_status, NULL);
if (chan->align_buf && frame_desc->actual_length &&
chan->ep_is_in) {
dev_dbg(hsotg->dev, "%s(): non-aligned buffer\n",
__func__);
dma_sync_single_for_cpu(hsotg->dev, urb->dma,
urb->length, DMA_FROM_DEVICE);
memcpy(urb->buf + frame_desc->offset +
qtd->isoc_split_offset, chan->qh->dw_align_buf,
frame_desc->actual_length);
dma_sync_single_for_device(hsotg->dev, urb->dma,
urb->length,
DMA_FROM_DEVICE);
}
if (chan->qh->do_split &&
chan->ep_type == USB_ENDPOINT_XFER_ISOC && chan->ep_is_in &&
hsotg->core_params->dma_enable > 0) {
qtd->complete_split = 0;
qtd->isoc_split_offset = 0;
}
break;
default:
dev_err(hsotg->dev, "Unhandled halt_status (%d)\n",
halt_status);
break;
}
if (++qtd->isoc_frame_index == urb->packet_count) {
dwc2_host_complete(hsotg, urb->priv, urb, 0);
halt_status = DWC2_HC_XFER_URB_COMPLETE;
} else {
halt_status = DWC2_HC_XFER_COMPLETE;
}
return halt_status;
}
static void dwc2_deactivate_qh(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh,
int free_qtd)
{
int continue_split = 0;
struct dwc2_qtd *qtd;
if (dbg_qh(qh))
dev_vdbg(hsotg->dev, " %s(%p,%p,%d)\n", __func__,
hsotg, qh, free_qtd);
if (list_empty(&qh->qtd_list)) {
dev_dbg(hsotg->dev, "## QTD list empty ##\n");
goto no_qtd;
}
qtd = list_first_entry(&qh->qtd_list, struct dwc2_qtd, qtd_list_entry);
if (qtd->complete_split)
continue_split = 1;
else if (qtd->isoc_split_pos == DWC2_HCSPLT_XACTPOS_MID ||
qtd->isoc_split_pos == DWC2_HCSPLT_XACTPOS_END)
continue_split = 1;
if (free_qtd) {
dwc2_hcd_qtd_unlink_and_free(hsotg, qtd, qh);
continue_split = 0;
}
no_qtd:
if (qh->channel)
qh->channel->align_buf = 0;
qh->channel = NULL;
dwc2_hcd_qh_deactivate(hsotg, qh, continue_split);
}
static void dwc2_release_channel(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan,
struct dwc2_qtd *qtd,
enum dwc2_halt_status halt_status)
{
enum dwc2_transaction_type tr_type;
u32 haintmsk;
int free_qtd = 0;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, " %s: channel %d, halt_status %d\n",
__func__, chan->hc_num, halt_status);
switch (halt_status) {
case DWC2_HC_XFER_URB_COMPLETE:
free_qtd = 1;
break;
case DWC2_HC_XFER_AHB_ERR:
case DWC2_HC_XFER_STALL:
case DWC2_HC_XFER_BABBLE_ERR:
free_qtd = 1;
break;
case DWC2_HC_XFER_XACT_ERR:
if (qtd && qtd->error_count >= 3) {
dev_vdbg(hsotg->dev,
" Complete URB with transaction error\n");
free_qtd = 1;
if (qtd->urb) {
qtd->urb->status = -EPROTO;
dwc2_host_complete(hsotg, qtd->urb->priv,
qtd->urb, -EPROTO);
}
}
break;
case DWC2_HC_XFER_URB_DEQUEUE:
goto cleanup;
case DWC2_HC_XFER_PERIODIC_INCOMPLETE:
dev_vdbg(hsotg->dev, " Complete URB with I/O error\n");
free_qtd = 1;
if (qtd && qtd->urb) {
qtd->urb->status = -EIO;
dwc2_host_complete(hsotg, qtd->urb->priv, qtd->urb,
-EIO);
}
break;
case DWC2_HC_XFER_NO_HALT_STATUS:
default:
break;
}
dwc2_deactivate_qh(hsotg, chan->qh, free_qtd);
cleanup:
if (!list_empty(&chan->hc_list_entry))
list_del(&chan->hc_list_entry);
dwc2_hc_cleanup(hsotg, chan);
list_add_tail(&chan->hc_list_entry, &hsotg->free_hc_list);
switch (chan->ep_type) {
case USB_ENDPOINT_XFER_CONTROL:
case USB_ENDPOINT_XFER_BULK:
hsotg->non_periodic_channels--;
break;
default:
break;
}
haintmsk = readl(hsotg->regs + HAINTMSK);
haintmsk &= ~(1 << chan->hc_num);
writel(haintmsk, hsotg->regs + HAINTMSK);
tr_type = dwc2_hcd_select_transactions(hsotg);
if (tr_type != DWC2_TRANSACTION_NONE)
dwc2_hcd_queue_transactions(hsotg, tr_type);
}
static void dwc2_halt_channel(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, struct dwc2_qtd *qtd,
enum dwc2_halt_status halt_status)
{
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "%s()\n", __func__);
if (hsotg->core_params->dma_enable > 0) {
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "DMA enabled\n");
dwc2_release_channel(hsotg, chan, qtd, halt_status);
return;
}
dwc2_hc_halt(hsotg, chan, halt_status);
if (chan->halt_on_queue) {
u32 gintmsk;
dev_vdbg(hsotg->dev, "Halt on queue\n");
if (chan->ep_type == USB_ENDPOINT_XFER_CONTROL ||
chan->ep_type == USB_ENDPOINT_XFER_BULK) {
dev_vdbg(hsotg->dev, "control/bulk\n");
gintmsk = readl(hsotg->regs + GINTMSK);
gintmsk |= GINTSTS_NPTXFEMP;
writel(gintmsk, hsotg->regs + GINTMSK);
} else {
dev_vdbg(hsotg->dev, "isoc/intr\n");
list_move(&chan->qh->qh_list_entry,
&hsotg->periodic_sched_assigned);
gintmsk = readl(hsotg->regs + GINTMSK);
gintmsk |= GINTSTS_PTXFEMP;
writel(gintmsk, hsotg->regs + GINTMSK);
}
}
}
static void dwc2_complete_non_periodic_xfer(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan,
int chnum, struct dwc2_qtd *qtd,
enum dwc2_halt_status halt_status)
{
dev_vdbg(hsotg->dev, "%s()\n", __func__);
qtd->error_count = 0;
if (chan->hcint & HCINTMSK_NYET) {
dev_vdbg(hsotg->dev, "got NYET\n");
chan->qh->ping_state = 1;
}
if (chan->ep_is_in) {
dwc2_halt_channel(hsotg, chan, qtd, halt_status);
} else {
dwc2_release_channel(hsotg, chan, qtd, halt_status);
}
}
static void dwc2_complete_periodic_xfer(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd,
enum dwc2_halt_status halt_status)
{
u32 hctsiz = readl(hsotg->regs + HCTSIZ(chnum));
qtd->error_count = 0;
if (!chan->ep_is_in || (hctsiz & TSIZ_PKTCNT_MASK) == 0)
dwc2_release_channel(hsotg, chan, qtd, halt_status);
else
dwc2_halt_channel(hsotg, chan, qtd, halt_status);
}
static int dwc2_xfercomp_isoc_split_in(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
struct dwc2_hcd_iso_packet_desc *frame_desc;
u32 len;
if (!qtd->urb)
return 0;
frame_desc = &qtd->urb->iso_descs[qtd->isoc_frame_index];
len = dwc2_get_actual_xfer_length(hsotg, chan, chnum, qtd,
DWC2_HC_XFER_COMPLETE, NULL);
if (!len) {
qtd->complete_split = 0;
qtd->isoc_split_offset = 0;
return 0;
}
frame_desc->actual_length += len;
if (chan->align_buf && len) {
dev_dbg(hsotg->dev, "%s(): non-aligned buffer\n", __func__);
dma_sync_single_for_cpu(hsotg->dev, qtd->urb->dma,
qtd->urb->length, DMA_FROM_DEVICE);
memcpy(qtd->urb->buf + frame_desc->offset +
qtd->isoc_split_offset, chan->qh->dw_align_buf, len);
dma_sync_single_for_device(hsotg->dev, qtd->urb->dma,
qtd->urb->length, DMA_FROM_DEVICE);
}
qtd->isoc_split_offset += len;
if (frame_desc->actual_length >= frame_desc->length) {
frame_desc->status = 0;
qtd->isoc_frame_index++;
qtd->complete_split = 0;
qtd->isoc_split_offset = 0;
}
if (qtd->isoc_frame_index == qtd->urb->packet_count) {
dwc2_host_complete(hsotg, qtd->urb->priv, qtd->urb, 0);
dwc2_release_channel(hsotg, chan, qtd,
DWC2_HC_XFER_URB_COMPLETE);
} else {
dwc2_release_channel(hsotg, chan, qtd,
DWC2_HC_XFER_NO_HALT_STATUS);
}
return 1;
}
static void dwc2_hc_xfercomp_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
struct dwc2_hcd_urb *urb = qtd->urb;
int pipe_type = dwc2_hcd_get_pipe_type(&urb->pipe_info);
enum dwc2_halt_status halt_status = DWC2_HC_XFER_COMPLETE;
int urb_xfer_done;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev,
"--Host Channel %d Interrupt: Transfer Complete--\n",
chnum);
if (hsotg->core_params->dma_desc_enable > 0) {
dwc2_hcd_complete_xfer_ddma(hsotg, chan, chnum, halt_status);
if (pipe_type == USB_ENDPOINT_XFER_ISOC)
return;
goto handle_xfercomp_done;
}
if (chan->qh->do_split) {
if (chan->ep_type == USB_ENDPOINT_XFER_ISOC && chan->ep_is_in &&
hsotg->core_params->dma_enable > 0) {
if (qtd->complete_split &&
dwc2_xfercomp_isoc_split_in(hsotg, chan, chnum,
qtd))
goto handle_xfercomp_done;
} else {
qtd->complete_split = 0;
}
}
if (!urb)
goto handle_xfercomp_done;
switch (pipe_type) {
case USB_ENDPOINT_XFER_CONTROL:
switch (qtd->control_phase) {
case DWC2_CONTROL_SETUP:
if (urb->length > 0)
qtd->control_phase = DWC2_CONTROL_DATA;
else
qtd->control_phase = DWC2_CONTROL_STATUS;
dev_vdbg(hsotg->dev,
" Control setup transaction done\n");
halt_status = DWC2_HC_XFER_COMPLETE;
break;
case DWC2_CONTROL_DATA:
urb_xfer_done = dwc2_update_urb_state(hsotg, chan,
chnum, urb, qtd);
if (urb_xfer_done) {
qtd->control_phase = DWC2_CONTROL_STATUS;
dev_vdbg(hsotg->dev,
" Control data transfer done\n");
} else {
dwc2_hcd_save_data_toggle(hsotg, chan, chnum,
qtd);
}
halt_status = DWC2_HC_XFER_COMPLETE;
break;
case DWC2_CONTROL_STATUS:
dev_vdbg(hsotg->dev, " Control transfer complete\n");
if (urb->status == -EINPROGRESS)
urb->status = 0;
dwc2_host_complete(hsotg, urb->priv, urb, urb->status);
halt_status = DWC2_HC_XFER_URB_COMPLETE;
break;
}
dwc2_complete_non_periodic_xfer(hsotg, chan, chnum, qtd,
halt_status);
break;
case USB_ENDPOINT_XFER_BULK:
dev_vdbg(hsotg->dev, " Bulk transfer complete\n");
urb_xfer_done = dwc2_update_urb_state(hsotg, chan, chnum, urb,
qtd);
if (urb_xfer_done) {
dwc2_host_complete(hsotg, urb->priv, urb, urb->status);
halt_status = DWC2_HC_XFER_URB_COMPLETE;
} else {
halt_status = DWC2_HC_XFER_COMPLETE;
}
dwc2_hcd_save_data_toggle(hsotg, chan, chnum, qtd);
dwc2_complete_non_periodic_xfer(hsotg, chan, chnum, qtd,
halt_status);
break;
case USB_ENDPOINT_XFER_INT:
dev_vdbg(hsotg->dev, " Interrupt transfer complete\n");
urb_xfer_done = dwc2_update_urb_state(hsotg, chan, chnum, urb,
qtd);
if (urb_xfer_done) {
dwc2_host_complete(hsotg, urb->priv, urb,
urb->status);
halt_status = DWC2_HC_XFER_URB_COMPLETE;
} else {
halt_status = DWC2_HC_XFER_COMPLETE;
}
dwc2_hcd_save_data_toggle(hsotg, chan, chnum, qtd);
dwc2_complete_periodic_xfer(hsotg, chan, chnum, qtd,
halt_status);
break;
case USB_ENDPOINT_XFER_ISOC:
if (dbg_perio())
dev_vdbg(hsotg->dev, " Isochronous transfer complete\n");
if (qtd->isoc_split_pos == DWC2_HCSPLT_XACTPOS_ALL)
halt_status = dwc2_update_isoc_urb_state(hsotg, chan,
chnum, qtd, DWC2_HC_XFER_COMPLETE);
dwc2_complete_periodic_xfer(hsotg, chan, chnum, qtd,
halt_status);
break;
}
handle_xfercomp_done:
disable_hc_int(hsotg, chnum, HCINTMSK_XFERCOMPL);
}
static void dwc2_hc_stall_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
struct dwc2_hcd_urb *urb = qtd->urb;
int pipe_type = dwc2_hcd_get_pipe_type(&urb->pipe_info);
dev_dbg(hsotg->dev, "--Host Channel %d Interrupt: STALL Received--\n",
chnum);
if (hsotg->core_params->dma_desc_enable > 0) {
dwc2_hcd_complete_xfer_ddma(hsotg, chan, chnum,
DWC2_HC_XFER_STALL);
goto handle_stall_done;
}
if (!urb)
goto handle_stall_halt;
if (pipe_type == USB_ENDPOINT_XFER_CONTROL)
dwc2_host_complete(hsotg, urb->priv, urb, -EPIPE);
if (pipe_type == USB_ENDPOINT_XFER_BULK ||
pipe_type == USB_ENDPOINT_XFER_INT) {
dwc2_host_complete(hsotg, urb->priv, urb, -EPIPE);
chan->qh->data_toggle = 0;
}
handle_stall_halt:
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_STALL);
handle_stall_done:
disable_hc_int(hsotg, chnum, HCINTMSK_STALL);
}
static void dwc2_update_urb_state_abn(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_hcd_urb *urb,
struct dwc2_qtd *qtd,
enum dwc2_halt_status halt_status)
{
u32 xfer_length = dwc2_get_actual_xfer_length(hsotg, chan, chnum,
qtd, halt_status, NULL);
u32 hctsiz;
if (urb->actual_length + xfer_length > urb->length) {
dev_warn(hsotg->dev, "%s(): trimming xfer length\n", __func__);
xfer_length = urb->length - urb->actual_length;
}
if (chan->align_buf && xfer_length && chan->ep_is_in) {
dev_dbg(hsotg->dev, "%s(): non-aligned buffer\n", __func__);
dma_sync_single_for_cpu(hsotg->dev, urb->dma, urb->length,
DMA_FROM_DEVICE);
memcpy(urb->buf + urb->actual_length, chan->qh->dw_align_buf,
xfer_length);
dma_sync_single_for_device(hsotg->dev, urb->dma, urb->length,
DMA_FROM_DEVICE);
}
urb->actual_length += xfer_length;
hctsiz = readl(hsotg->regs + HCTSIZ(chnum));
dev_vdbg(hsotg->dev, "DWC_otg: %s: %s, channel %d\n",
__func__, (chan->ep_is_in ? "IN" : "OUT"), chnum);
dev_vdbg(hsotg->dev, " chan->start_pkt_count %d\n",
chan->start_pkt_count);
dev_vdbg(hsotg->dev, " hctsiz.pktcnt %d\n",
hctsiz >> TSIZ_PKTCNT_SHIFT &
TSIZ_PKTCNT_MASK >> TSIZ_PKTCNT_SHIFT);
dev_vdbg(hsotg->dev, " chan->max_packet %d\n", chan->max_packet);
dev_vdbg(hsotg->dev, " bytes_transferred %d\n",
xfer_length);
dev_vdbg(hsotg->dev, " urb->actual_length %d\n",
urb->actual_length);
dev_vdbg(hsotg->dev, " urb->transfer_buffer_length %d\n",
urb->length);
}
static void dwc2_hc_nak_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "--Host Channel %d Interrupt: NAK Received--\n",
chnum);
if (chan->do_split) {
if (chan->complete_split)
qtd->error_count = 0;
qtd->complete_split = 0;
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_NAK);
goto handle_nak_done;
}
switch (dwc2_hcd_get_pipe_type(&qtd->urb->pipe_info)) {
case USB_ENDPOINT_XFER_CONTROL:
case USB_ENDPOINT_XFER_BULK:
if (hsotg->core_params->dma_enable > 0 && chan->ep_is_in) {
qtd->error_count = 0;
break;
}
qtd->error_count = 0;
if (!chan->qh->ping_state) {
dwc2_update_urb_state_abn(hsotg, chan, chnum, qtd->urb,
qtd, DWC2_HC_XFER_NAK);
dwc2_hcd_save_data_toggle(hsotg, chan, chnum, qtd);
if (chan->speed == USB_SPEED_HIGH)
chan->qh->ping_state = 1;
}
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_NAK);
break;
case USB_ENDPOINT_XFER_INT:
qtd->error_count = 0;
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_NAK);
break;
case USB_ENDPOINT_XFER_ISOC:
dev_err(hsotg->dev, "NACK interrupt for ISOC transfer\n");
break;
}
handle_nak_done:
disable_hc_int(hsotg, chnum, HCINTMSK_NAK);
}
static void dwc2_hc_ack_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
struct dwc2_hcd_iso_packet_desc *frame_desc;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "--Host Channel %d Interrupt: ACK Received--\n",
chnum);
if (chan->do_split) {
if (!chan->ep_is_in &&
chan->data_pid_start != DWC2_HC_PID_SETUP)
qtd->ssplit_out_xfer_count = chan->xfer_len;
if (chan->ep_type != USB_ENDPOINT_XFER_ISOC || chan->ep_is_in) {
qtd->complete_split = 1;
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_ACK);
} else {
switch (chan->xact_pos) {
case DWC2_HCSPLT_XACTPOS_ALL:
break;
case DWC2_HCSPLT_XACTPOS_END:
qtd->isoc_split_pos = DWC2_HCSPLT_XACTPOS_ALL;
qtd->isoc_split_offset = 0;
break;
case DWC2_HCSPLT_XACTPOS_BEGIN:
case DWC2_HCSPLT_XACTPOS_MID:
frame_desc = &qtd->urb->iso_descs[
qtd->isoc_frame_index];
qtd->isoc_split_offset += 188;
if (frame_desc->length - qtd->isoc_split_offset
<= 188)
qtd->isoc_split_pos =
DWC2_HCSPLT_XACTPOS_END;
else
qtd->isoc_split_pos =
DWC2_HCSPLT_XACTPOS_MID;
break;
}
}
} else {
qtd->error_count = 0;
if (chan->qh->ping_state) {
chan->qh->ping_state = 0;
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_ACK);
}
}
disable_hc_int(hsotg, chnum, HCINTMSK_ACK);
}
static void dwc2_hc_nyet_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "--Host Channel %d Interrupt: NYET Received--\n",
chnum);
if (chan->do_split && chan->complete_split) {
if (chan->ep_is_in && chan->ep_type == USB_ENDPOINT_XFER_ISOC &&
hsotg->core_params->dma_enable > 0) {
qtd->complete_split = 0;
qtd->isoc_split_offset = 0;
if (qtd->urb &&
++qtd->isoc_frame_index == qtd->urb->packet_count) {
dwc2_host_complete(hsotg, qtd->urb->priv,
qtd->urb, 0);
dwc2_release_channel(hsotg, chan, qtd,
DWC2_HC_XFER_URB_COMPLETE);
} else {
dwc2_release_channel(hsotg, chan, qtd,
DWC2_HC_XFER_NO_HALT_STATUS);
}
goto handle_nyet_done;
}
if (chan->ep_type == USB_ENDPOINT_XFER_INT ||
chan->ep_type == USB_ENDPOINT_XFER_ISOC) {
int frnum = dwc2_hcd_get_frame_number(hsotg);
if (dwc2_full_frame_num(frnum) !=
dwc2_full_frame_num(chan->qh->sched_frame)) {
#if 0
qtd->error_count++;
#endif
qtd->complete_split = 0;
dwc2_halt_channel(hsotg, chan, qtd,
DWC2_HC_XFER_XACT_ERR);
goto handle_nyet_done;
}
}
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_NYET);
goto handle_nyet_done;
}
chan->qh->ping_state = 1;
qtd->error_count = 0;
dwc2_update_urb_state_abn(hsotg, chan, chnum, qtd->urb, qtd,
DWC2_HC_XFER_NYET);
dwc2_hcd_save_data_toggle(hsotg, chan, chnum, qtd);
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_NYET);
handle_nyet_done:
disable_hc_int(hsotg, chnum, HCINTMSK_NYET);
}
static void dwc2_hc_babble_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
dev_dbg(hsotg->dev, "--Host Channel %d Interrupt: Babble Error--\n",
chnum);
if (hsotg->core_params->dma_desc_enable > 0) {
dwc2_hcd_complete_xfer_ddma(hsotg, chan, chnum,
DWC2_HC_XFER_BABBLE_ERR);
goto handle_babble_done;
}
if (chan->ep_type != USB_ENDPOINT_XFER_ISOC) {
if (qtd->urb)
dwc2_host_complete(hsotg, qtd->urb->priv, qtd->urb,
-EOVERFLOW);
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_BABBLE_ERR);
} else {
enum dwc2_halt_status halt_status;
halt_status = dwc2_update_isoc_urb_state(hsotg, chan, chnum,
qtd, DWC2_HC_XFER_BABBLE_ERR);
dwc2_halt_channel(hsotg, chan, qtd, halt_status);
}
handle_babble_done:
dwc2_hc_handle_tt_clear(hsotg, chan, qtd);
disable_hc_int(hsotg, chnum, HCINTMSK_BBLERR);
}
static void dwc2_hc_ahberr_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
struct dwc2_hcd_urb *urb = qtd->urb;
char *pipetype, *speed;
u32 hcchar;
u32 hcsplt;
u32 hctsiz;
u32 hc_dma;
dev_dbg(hsotg->dev, "--Host Channel %d Interrupt: AHB Error--\n",
chnum);
if (!urb)
goto handle_ahberr_halt;
hcchar = readl(hsotg->regs + HCCHAR(chnum));
hcsplt = readl(hsotg->regs + HCSPLT(chnum));
hctsiz = readl(hsotg->regs + HCTSIZ(chnum));
hc_dma = readl(hsotg->regs + HCDMA(chnum));
dev_err(hsotg->dev, "AHB ERROR, Channel %d\n", chnum);
dev_err(hsotg->dev, " hcchar 0x%08x, hcsplt 0x%08x\n", hcchar, hcsplt);
dev_err(hsotg->dev, " hctsiz 0x%08x, hc_dma 0x%08x\n", hctsiz, hc_dma);
dev_err(hsotg->dev, " Device address: %d\n",
dwc2_hcd_get_dev_addr(&urb->pipe_info));
dev_err(hsotg->dev, " Endpoint: %d, %s\n",
dwc2_hcd_get_ep_num(&urb->pipe_info),
dwc2_hcd_is_pipe_in(&urb->pipe_info) ? "IN" : "OUT");
switch (dwc2_hcd_get_pipe_type(&urb->pipe_info)) {
case USB_ENDPOINT_XFER_CONTROL:
pipetype = "CONTROL";
break;
case USB_ENDPOINT_XFER_BULK:
pipetype = "BULK";
break;
case USB_ENDPOINT_XFER_INT:
pipetype = "INTERRUPT";
break;
case USB_ENDPOINT_XFER_ISOC:
pipetype = "ISOCHRONOUS";
break;
default:
pipetype = "UNKNOWN";
break;
}
dev_err(hsotg->dev, " Endpoint type: %s\n", pipetype);
switch (chan->speed) {
case USB_SPEED_HIGH:
speed = "HIGH";
break;
case USB_SPEED_FULL:
speed = "FULL";
break;
case USB_SPEED_LOW:
speed = "LOW";
break;
default:
speed = "UNKNOWN";
break;
}
dev_err(hsotg->dev, " Speed: %s\n", speed);
dev_err(hsotg->dev, " Max packet size: %d\n",
dwc2_hcd_get_mps(&urb->pipe_info));
dev_err(hsotg->dev, " Data buffer length: %d\n", urb->length);
dev_err(hsotg->dev, " Transfer buffer: %p, Transfer DMA: %08lx\n",
urb->buf, (unsigned long)urb->dma);
dev_err(hsotg->dev, " Setup buffer: %p, Setup DMA: %08lx\n",
urb->setup_packet, (unsigned long)urb->setup_dma);
dev_err(hsotg->dev, " Interval: %d\n", urb->interval);
if (hsotg->core_params->dma_desc_enable > 0) {
dwc2_hcd_complete_xfer_ddma(hsotg, chan, chnum,
DWC2_HC_XFER_AHB_ERR);
goto handle_ahberr_done;
}
dwc2_host_complete(hsotg, urb->priv, urb, -EIO);
handle_ahberr_halt:
dwc2_hc_halt(hsotg, chan, DWC2_HC_XFER_AHB_ERR);
handle_ahberr_done:
dwc2_hc_handle_tt_clear(hsotg, chan, qtd);
disable_hc_int(hsotg, chnum, HCINTMSK_AHBERR);
}
static void dwc2_hc_xacterr_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
dev_dbg(hsotg->dev,
"--Host Channel %d Interrupt: Transaction Error--\n", chnum);
if (hsotg->core_params->dma_desc_enable > 0) {
dwc2_hcd_complete_xfer_ddma(hsotg, chan, chnum,
DWC2_HC_XFER_XACT_ERR);
goto handle_xacterr_done;
}
switch (dwc2_hcd_get_pipe_type(&qtd->urb->pipe_info)) {
case USB_ENDPOINT_XFER_CONTROL:
case USB_ENDPOINT_XFER_BULK:
qtd->error_count++;
if (!chan->qh->ping_state) {
dwc2_update_urb_state_abn(hsotg, chan, chnum, qtd->urb,
qtd, DWC2_HC_XFER_XACT_ERR);
dwc2_hcd_save_data_toggle(hsotg, chan, chnum, qtd);
if (!chan->ep_is_in && chan->speed == USB_SPEED_HIGH)
chan->qh->ping_state = 1;
}
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_XACT_ERR);
break;
case USB_ENDPOINT_XFER_INT:
qtd->error_count++;
if (chan->do_split && chan->complete_split)
qtd->complete_split = 0;
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_XACT_ERR);
break;
case USB_ENDPOINT_XFER_ISOC:
{
enum dwc2_halt_status halt_status;
halt_status = dwc2_update_isoc_urb_state(hsotg, chan,
chnum, qtd, DWC2_HC_XFER_XACT_ERR);
dwc2_halt_channel(hsotg, chan, qtd, halt_status);
}
break;
}
handle_xacterr_done:
dwc2_hc_handle_tt_clear(hsotg, chan, qtd);
disable_hc_int(hsotg, chnum, HCINTMSK_XACTERR);
}
static void dwc2_hc_frmovrun_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
enum dwc2_halt_status halt_status;
if (dbg_hc(chan))
dev_dbg(hsotg->dev, "--Host Channel %d Interrupt: Frame Overrun--\n",
chnum);
switch (dwc2_hcd_get_pipe_type(&qtd->urb->pipe_info)) {
case USB_ENDPOINT_XFER_CONTROL:
case USB_ENDPOINT_XFER_BULK:
break;
case USB_ENDPOINT_XFER_INT:
dwc2_halt_channel(hsotg, chan, qtd, DWC2_HC_XFER_FRAME_OVERRUN);
break;
case USB_ENDPOINT_XFER_ISOC:
halt_status = dwc2_update_isoc_urb_state(hsotg, chan, chnum,
qtd, DWC2_HC_XFER_FRAME_OVERRUN);
dwc2_halt_channel(hsotg, chan, qtd, halt_status);
break;
}
dwc2_hc_handle_tt_clear(hsotg, chan, qtd);
disable_hc_int(hsotg, chnum, HCINTMSK_FRMOVRUN);
}
static void dwc2_hc_datatglerr_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
dev_dbg(hsotg->dev,
"--Host Channel %d Interrupt: Data Toggle Error--\n", chnum);
if (chan->ep_is_in)
qtd->error_count = 0;
else
dev_err(hsotg->dev,
"Data Toggle Error on OUT transfer, channel %d\n",
chnum);
dwc2_hc_handle_tt_clear(hsotg, chan, qtd);
disable_hc_int(hsotg, chnum, HCINTMSK_DATATGLERR);
}
static bool dwc2_halt_status_ok(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
#ifdef DEBUG
u32 hcchar;
u32 hctsiz;
u32 hcintmsk;
u32 hcsplt;
if (chan->halt_status == DWC2_HC_XFER_NO_HALT_STATUS) {
hcchar = readl(hsotg->regs + HCCHAR(chnum));
hctsiz = readl(hsotg->regs + HCTSIZ(chnum));
hcintmsk = readl(hsotg->regs + HCINTMSK(chnum));
hcsplt = readl(hsotg->regs + HCSPLT(chnum));
dev_dbg(hsotg->dev,
"%s: chan->halt_status DWC2_HC_XFER_NO_HALT_STATUS,\n",
__func__);
dev_dbg(hsotg->dev,
"channel %d, hcchar 0x%08x, hctsiz 0x%08x,\n",
chnum, hcchar, hctsiz);
dev_dbg(hsotg->dev,
"hcint 0x%08x, hcintmsk 0x%08x, hcsplt 0x%08x,\n",
chan->hcint, hcintmsk, hcsplt);
if (qtd)
dev_dbg(hsotg->dev, "qtd->complete_split %d\n",
qtd->complete_split);
dev_warn(hsotg->dev,
"%s: no halt status, channel %d, ignoring interrupt\n",
__func__, chnum);
return false;
}
hcchar = readl(hsotg->regs + HCCHAR(chnum));
if (hcchar & HCCHAR_CHDIS) {
dev_warn(hsotg->dev,
"%s: hcchar.chdis set unexpectedly, hcchar 0x%08x, trying to halt again\n",
__func__, hcchar);
chan->halt_pending = 0;
dwc2_halt_channel(hsotg, chan, qtd, chan->halt_status);
return false;
}
#endif
return true;
}
static void dwc2_hc_chhltd_intr_dma(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
u32 hcintmsk;
int out_nak_enh = 0;
if (dbg_hc(chan))
dev_vdbg(hsotg->dev,
"--Host Channel %d Interrupt: DMA Channel Halted--\n",
chnum);
if (hsotg->snpsid >= DWC2_CORE_REV_2_71a) {
if (chan->speed == USB_SPEED_HIGH && !chan->ep_is_in &&
(chan->ep_type == USB_ENDPOINT_XFER_CONTROL ||
chan->ep_type == USB_ENDPOINT_XFER_BULK)) {
out_nak_enh = 1;
}
}
if (chan->halt_status == DWC2_HC_XFER_URB_DEQUEUE ||
(chan->halt_status == DWC2_HC_XFER_AHB_ERR &&
hsotg->core_params->dma_desc_enable <= 0)) {
if (hsotg->core_params->dma_desc_enable > 0)
dwc2_hcd_complete_xfer_ddma(hsotg, chan, chnum,
chan->halt_status);
else
dwc2_release_channel(hsotg, chan, qtd,
chan->halt_status);
return;
}
hcintmsk = readl(hsotg->regs + HCINTMSK(chnum));
if (chan->hcint & HCINTMSK_XFERCOMPL) {
if (chan->ep_type == USB_ENDPOINT_XFER_ISOC && !chan->ep_is_in)
dwc2_hc_ack_intr(hsotg, chan, chnum, qtd);
dwc2_hc_xfercomp_intr(hsotg, chan, chnum, qtd);
} else if (chan->hcint & HCINTMSK_STALL) {
dwc2_hc_stall_intr(hsotg, chan, chnum, qtd);
} else if ((chan->hcint & HCINTMSK_XACTERR) &&
hsotg->core_params->dma_desc_enable <= 0) {
if (out_nak_enh) {
if (chan->hcint &
(HCINTMSK_NYET | HCINTMSK_NAK | HCINTMSK_ACK)) {
dev_vdbg(hsotg->dev,
"XactErr with NYET/NAK/ACK\n");
qtd->error_count = 0;
} else {
dev_vdbg(hsotg->dev,
"XactErr without NYET/NAK/ACK\n");
}
}
dwc2_hc_xacterr_intr(hsotg, chan, chnum, qtd);
} else if ((chan->hcint & HCINTMSK_XCS_XACT) &&
hsotg->core_params->dma_desc_enable > 0) {
dwc2_hc_xacterr_intr(hsotg, chan, chnum, qtd);
} else if ((chan->hcint & HCINTMSK_AHBERR) &&
hsotg->core_params->dma_desc_enable > 0) {
dwc2_hc_ahberr_intr(hsotg, chan, chnum, qtd);
} else if (chan->hcint & HCINTMSK_BBLERR) {
dwc2_hc_babble_intr(hsotg, chan, chnum, qtd);
} else if (chan->hcint & HCINTMSK_FRMOVRUN) {
dwc2_hc_frmovrun_intr(hsotg, chan, chnum, qtd);
} else if (!out_nak_enh) {
if (chan->hcint & HCINTMSK_NYET) {
dwc2_hc_nyet_intr(hsotg, chan, chnum, qtd);
} else if ((chan->hcint & HCINTMSK_NAK) &&
!(hcintmsk & HCINTMSK_NAK)) {
dwc2_hc_nak_intr(hsotg, chan, chnum, qtd);
} else if ((chan->hcint & HCINTMSK_ACK) &&
!(hcintmsk & HCINTMSK_ACK)) {
dwc2_hc_ack_intr(hsotg, chan, chnum, qtd);
} else {
if (chan->ep_type == USB_ENDPOINT_XFER_INT ||
chan->ep_type == USB_ENDPOINT_XFER_ISOC) {
dev_dbg(hsotg->dev,
"%s: Halt channel %d (assume incomplete periodic transfer)\n",
__func__, chnum);
dwc2_halt_channel(hsotg, chan, qtd,
DWC2_HC_XFER_PERIODIC_INCOMPLETE);
} else {
dev_err(hsotg->dev,
"%s: Channel %d - ChHltd set, but reason is unknown\n",
__func__, chnum);
dev_err(hsotg->dev,
"hcint 0x%08x, intsts 0x%08x\n",
chan->hcint,
readl(hsotg->regs + GINTSTS));
}
}
} else {
dev_info(hsotg->dev,
"NYET/NAK/ACK/other in non-error case, 0x%08x\n",
chan->hcint);
}
}
static void dwc2_hc_chhltd_intr(struct dwc2_hsotg *hsotg,
struct dwc2_host_chan *chan, int chnum,
struct dwc2_qtd *qtd)
{
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "--Host Channel %d Interrupt: Channel Halted--\n",
chnum);
if (hsotg->core_params->dma_enable > 0) {
dwc2_hc_chhltd_intr_dma(hsotg, chan, chnum, qtd);
} else {
if (!dwc2_halt_status_ok(hsotg, chan, chnum, qtd))
return;
dwc2_release_channel(hsotg, chan, qtd, chan->halt_status);
}
}
static void dwc2_hc_n_intr(struct dwc2_hsotg *hsotg, int chnum)
{
struct dwc2_qtd *qtd;
struct dwc2_host_chan *chan;
u32 hcint, hcintmsk;
chan = hsotg->hc_ptr_array[chnum];
if (dbg_hc(chan))
dev_vdbg(hsotg->dev, "--Host Channel Interrupt--, Channel %d\n",
chnum);
hcint = readl(hsotg->regs + HCINT(chnum));
hcintmsk = readl(hsotg->regs + HCINTMSK(chnum));
if (dbg_hc(chan))
dev_vdbg(hsotg->dev,
" hcint 0x%08x, hcintmsk 0x%08x, hcint&hcintmsk 0x%08x\n",
hcint, hcintmsk, hcint & hcintmsk);
if (!chan) {
dev_err(hsotg->dev, "## hc_ptr_array for channel is NULL ##\n");
writel(hcint, hsotg->regs + HCINT(chnum));
return;
}
writel(hcint, hsotg->regs + HCINT(chnum));
chan->hcint = hcint;
hcint &= hcintmsk;
if (chan->halt_status == DWC2_HC_XFER_URB_DEQUEUE) {
WARN_ON(hcint != HCINTMSK_CHHLTD);
if (hsotg->core_params->dma_desc_enable > 0)
dwc2_hcd_complete_xfer_ddma(hsotg, chan, chnum,
chan->halt_status);
else
dwc2_release_channel(hsotg, chan, NULL,
chan->halt_status);
return;
}
if (list_empty(&chan->qh->qtd_list)) {
dev_dbg(hsotg->dev, "## no QTD queued for channel %d ##\n",
chnum);
dev_dbg(hsotg->dev,
" hcint 0x%08x, hcintmsk 0x%08x, hcint&hcintmsk 0x%08x\n",
chan->hcint, hcintmsk, hcint);
chan->halt_status = DWC2_HC_XFER_NO_HALT_STATUS;
disable_hc_int(hsotg, chnum, HCINTMSK_CHHLTD);
chan->hcint = 0;
return;
}
qtd = list_first_entry(&chan->qh->qtd_list, struct dwc2_qtd,
qtd_list_entry);
if (hsotg->core_params->dma_enable <= 0) {
if ((hcint & HCINTMSK_CHHLTD) && hcint != HCINTMSK_CHHLTD)
hcint &= ~HCINTMSK_CHHLTD;
}
if (hcint & HCINTMSK_XFERCOMPL) {
dwc2_hc_xfercomp_intr(hsotg, chan, chnum, qtd);
hcint &= ~HCINTMSK_NYET;
}
if (hcint & HCINTMSK_CHHLTD)
dwc2_hc_chhltd_intr(hsotg, chan, chnum, qtd);
if (hcint & HCINTMSK_AHBERR)
dwc2_hc_ahberr_intr(hsotg, chan, chnum, qtd);
if (hcint & HCINTMSK_STALL)
dwc2_hc_stall_intr(hsotg, chan, chnum, qtd);
if (hcint & HCINTMSK_NAK)
dwc2_hc_nak_intr(hsotg, chan, chnum, qtd);
if (hcint & HCINTMSK_ACK)
dwc2_hc_ack_intr(hsotg, chan, chnum, qtd);
if (hcint & HCINTMSK_NYET)
dwc2_hc_nyet_intr(hsotg, chan, chnum, qtd);
if (hcint & HCINTMSK_XACTERR)
dwc2_hc_xacterr_intr(hsotg, chan, chnum, qtd);
if (hcint & HCINTMSK_BBLERR)
dwc2_hc_babble_intr(hsotg, chan, chnum, qtd);
if (hcint & HCINTMSK_FRMOVRUN)
dwc2_hc_frmovrun_intr(hsotg, chan, chnum, qtd);
if (hcint & HCINTMSK_DATATGLERR)
dwc2_hc_datatglerr_intr(hsotg, chan, chnum, qtd);
chan->hcint = 0;
}
static void dwc2_hc_intr(struct dwc2_hsotg *hsotg)
{
u32 haint;
int i;
haint = readl(hsotg->regs + HAINT);
if (dbg_perio()) {
dev_vdbg(hsotg->dev, "%s()\n", __func__);
dev_vdbg(hsotg->dev, "HAINT=%08x\n", haint);
}
for (i = 0; i < hsotg->core_params->host_channels; i++) {
if (haint & (1 << i))
dwc2_hc_n_intr(hsotg, i);
}
}
irqreturn_t dwc2_handle_hcd_intr(struct dwc2_hsotg *hsotg)
{
u32 gintsts, dbg_gintsts;
irqreturn_t retval = IRQ_NONE;
if (dwc2_check_core_status(hsotg) < 0) {
dev_warn(hsotg->dev, "Controller is disconnected\n");
return retval;
}
spin_lock(&hsotg->lock);
if (dwc2_is_host_mode(hsotg)) {
gintsts = dwc2_read_core_intr(hsotg);
if (!gintsts) {
spin_unlock(&hsotg->lock);
return retval;
}
retval = IRQ_HANDLED;
dbg_gintsts = gintsts;
#ifndef DEBUG_SOF
dbg_gintsts &= ~GINTSTS_SOF;
#endif
if (!dbg_perio())
dbg_gintsts &= ~(GINTSTS_HCHINT | GINTSTS_RXFLVL |
GINTSTS_PTXFEMP);
if (dbg_gintsts)
dev_vdbg(hsotg->dev,
"DWC OTG HCD Interrupt Detected gintsts&gintmsk=0x%08x\n",
gintsts);
if (gintsts & GINTSTS_SOF)
dwc2_sof_intr(hsotg);
if (gintsts & GINTSTS_RXFLVL)
dwc2_rx_fifo_level_intr(hsotg);
if (gintsts & GINTSTS_NPTXFEMP)
dwc2_np_tx_fifo_empty_intr(hsotg);
if (gintsts & GINTSTS_PRTINT)
dwc2_port_intr(hsotg);
if (gintsts & GINTSTS_HCHINT)
dwc2_hc_intr(hsotg);
if (gintsts & GINTSTS_PTXFEMP)
dwc2_perio_tx_fifo_empty_intr(hsotg);
if (dbg_gintsts) {
dev_vdbg(hsotg->dev,
"DWC OTG HCD Finished Servicing Interrupts\n");
dev_vdbg(hsotg->dev,
"DWC OTG HCD gintsts=0x%08x gintmsk=0x%08x\n",
readl(hsotg->regs + GINTSTS),
readl(hsotg->regs + GINTMSK));
}
}
spin_unlock(&hsotg->lock);
return retval;
}
