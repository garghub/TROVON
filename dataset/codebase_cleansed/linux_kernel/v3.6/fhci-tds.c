static struct usb_td __iomem *next_bd(struct usb_td __iomem *base,
struct usb_td __iomem *td,
u16 status)
{
if (status & TD_W)
return base;
else
return ++td;
}
void fhci_push_dummy_bd(struct endpoint *ep)
{
if (ep->already_pushed_dummy_bd == false) {
u16 td_status = in_be16(&ep->empty_td->status);
out_be32(&ep->empty_td->buf_ptr, DUMMY_BD_BUFFER);
ep->empty_td = next_bd(ep->td_base, ep->empty_td, td_status);
ep->already_pushed_dummy_bd = true;
}
}
void fhci_ep0_free(struct fhci_usb *usb)
{
struct endpoint *ep;
int size;
ep = usb->ep0;
if (ep) {
if (ep->td_base)
cpm_muram_free(cpm_muram_offset(ep->td_base));
if (kfifo_initialized(&ep->conf_frame_Q)) {
size = cq_howmany(&ep->conf_frame_Q);
for (; size; size--) {
struct packet *pkt = cq_get(&ep->conf_frame_Q);
kfree(pkt);
}
cq_delete(&ep->conf_frame_Q);
}
if (kfifo_initialized(&ep->empty_frame_Q)) {
size = cq_howmany(&ep->empty_frame_Q);
for (; size; size--) {
struct packet *pkt = cq_get(&ep->empty_frame_Q);
kfree(pkt);
}
cq_delete(&ep->empty_frame_Q);
}
if (kfifo_initialized(&ep->dummy_packets_Q)) {
size = cq_howmany(&ep->dummy_packets_Q);
for (; size; size--) {
u8 *buff = cq_get(&ep->dummy_packets_Q);
kfree(buff);
}
cq_delete(&ep->dummy_packets_Q);
}
kfree(ep);
usb->ep0 = NULL;
}
}
u32 fhci_create_ep(struct fhci_usb *usb, enum fhci_mem_alloc data_mem,
u32 ring_len)
{
struct endpoint *ep;
struct usb_td __iomem *td;
unsigned long ep_offset;
char *err_for = "endpoint PRAM";
int ep_mem_size;
u32 i;
if (!(ring_len > 2)) {
fhci_err(usb->fhci, "illegal TD ring length parameters\n");
return -EINVAL;
}
ep = kzalloc(sizeof(*ep), GFP_KERNEL);
if (!ep)
return -ENOMEM;
ep_mem_size = ring_len * sizeof(*td) + sizeof(struct fhci_ep_pram);
ep_offset = cpm_muram_alloc(ep_mem_size, 32);
if (IS_ERR_VALUE(ep_offset))
goto err;
ep->td_base = cpm_muram_addr(ep_offset);
if (cq_new(&ep->conf_frame_Q, ring_len + 2) ||
cq_new(&ep->empty_frame_Q, ring_len + 2) ||
cq_new(&ep->dummy_packets_Q, ring_len + 2)) {
err_for = "frame_queues";
goto err;
}
for (i = 0; i < (ring_len + 1); i++) {
struct packet *pkt;
u8 *buff;
pkt = kmalloc(sizeof(*pkt), GFP_KERNEL);
if (!pkt) {
err_for = "frame";
goto err;
}
buff = kmalloc(1028 * sizeof(*buff), GFP_KERNEL);
if (!buff) {
kfree(pkt);
err_for = "buffer";
goto err;
}
cq_put(&ep->empty_frame_Q, pkt);
cq_put(&ep->dummy_packets_Q, buff);
}
ep->ep_pram_ptr = (void __iomem *)ep->td_base + sizeof(*td) * ring_len;
ep->conf_td = ep->td_base;
ep->empty_td = ep->td_base;
ep->already_pushed_dummy_bd = false;
td = ep->td_base;
for (i = 0; i < ring_len; i++) {
out_be32(&td->buf_ptr, 0);
out_be16(&td->status, 0);
out_be16(&td->length, 0);
out_be16(&td->extra, 0);
td++;
}
td--;
out_be16(&td->status, TD_W);
out_be16(&td->length, 0);
usb->ep0 = ep;
return 0;
err:
fhci_ep0_free(usb);
kfree(ep);
fhci_err(usb->fhci, "no memory for the %s\n", err_for);
return -ENOMEM;
}
void fhci_init_ep_registers(struct fhci_usb *usb, struct endpoint *ep,
enum fhci_mem_alloc data_mem)
{
u8 rt;
out_be16(&usb->fhci->regs->usb_usep[0],
USB_TRANS_CTR | USB_EP_MF | USB_EP_RTE);
out_be16(&usb->fhci->pram->ep_ptr[0],
cpm_muram_offset(ep->ep_pram_ptr));
rt = (BUS_MODE_BO_BE | BUS_MODE_GBL);
#ifdef MULTI_DATA_BUS
if (data_mem == MEM_SECONDARY)
rt |= BUS_MODE_DTB;
#endif
out_8(&ep->ep_pram_ptr->rx_func_code, rt);
out_8(&ep->ep_pram_ptr->tx_func_code, rt);
out_be16(&ep->ep_pram_ptr->rx_buff_len, 1028);
out_be16(&ep->ep_pram_ptr->rx_base, 0);
out_be16(&ep->ep_pram_ptr->tx_base, cpm_muram_offset(ep->td_base));
out_be16(&ep->ep_pram_ptr->rx_bd_ptr, 0);
out_be16(&ep->ep_pram_ptr->tx_bd_ptr, cpm_muram_offset(ep->td_base));
out_be32(&ep->ep_pram_ptr->tx_state, 0);
}
static void fhci_td_transaction_confirm(struct fhci_usb *usb)
{
struct endpoint *ep = usb->ep0;
struct packet *pkt;
struct usb_td __iomem *td;
u16 extra_data;
u16 td_status;
u16 td_length;
u32 buf;
while (1) {
td = ep->conf_td;
td_status = in_be16(&td->status);
td_length = in_be16(&td->length);
buf = in_be32(&td->buf_ptr);
extra_data = in_be16(&td->extra);
if (!(!(td_status & TD_R) && ((td_status & ~TD_W) || buf)))
break;
else if ((buf == DUMMY_BD_BUFFER) && !(td_status & ~TD_W))
break;
clrbits16(&td->status, ~TD_W);
out_be16(&td->length, 0);
out_be32(&td->buf_ptr, 0);
out_be16(&td->extra, 0);
ep->conf_td = next_bd(ep->td_base, ep->conf_td, td_status);
if ((buf == DUMMY2_BD_BUFFER) && !(td_status & ~TD_W))
continue;
pkt = cq_get(&ep->conf_frame_Q);
if (!pkt)
fhci_err(usb->fhci, "no frame to confirm\n");
if (td_status & TD_ERRORS) {
if (td_status & TD_RXER) {
if (td_status & TD_CR)
pkt->status = USB_TD_RX_ER_CRC;
else if (td_status & TD_AB)
pkt->status = USB_TD_RX_ER_BITSTUFF;
else if (td_status & TD_OV)
pkt->status = USB_TD_RX_ER_OVERUN;
else if (td_status & TD_BOV)
pkt->status = USB_TD_RX_DATA_OVERUN;
else if (td_status & TD_NO)
pkt->status = USB_TD_RX_ER_NONOCT;
else
fhci_err(usb->fhci, "illegal error "
"occurred\n");
} else if (td_status & TD_NAK)
pkt->status = USB_TD_TX_ER_NAK;
else if (td_status & TD_TO)
pkt->status = USB_TD_TX_ER_TIMEOUT;
else if (td_status & TD_UN)
pkt->status = USB_TD_TX_ER_UNDERUN;
else if (td_status & TD_STAL)
pkt->status = USB_TD_TX_ER_STALL;
else
fhci_err(usb->fhci, "illegal error occurred\n");
} else if ((extra_data & TD_TOK_IN) &&
pkt->len > td_length - CRC_SIZE) {
pkt->status = USB_TD_RX_DATA_UNDERUN;
}
if (extra_data & TD_TOK_IN)
pkt->len = td_length - CRC_SIZE;
else if (pkt->info & PKT_ZLP)
pkt->len = 0;
else
pkt->len = td_length;
fhci_transaction_confirm(usb, pkt);
}
}
u32 fhci_host_transaction(struct fhci_usb *usb,
struct packet *pkt,
enum fhci_ta_type trans_type,
u8 dest_addr,
u8 dest_ep,
enum fhci_tf_mode trans_mode,
enum fhci_speed dest_speed, u8 data_toggle)
{
struct endpoint *ep = usb->ep0;
struct usb_td __iomem *td;
u16 extra_data;
u16 td_status;
fhci_usb_disable_interrupt(usb);
td = ep->empty_td;
td_status = in_be16(&td->status);
if (td_status & TD_R && in_be16(&td->length)) {
fhci_usb_enable_interrupt(usb);
return -1;
}
ep->empty_td = next_bd(ep->td_base, ep->empty_td, td_status);
fhci_usb_enable_interrupt(usb);
pkt->priv_data = td;
out_be32(&td->buf_ptr, virt_to_phys(pkt->data));
extra_data = (dest_ep << TD_ENDP_SHIFT) | dest_addr;
switch (trans_type) {
case FHCI_TA_IN:
extra_data |= TD_TOK_IN;
break;
case FHCI_TA_OUT:
extra_data |= TD_TOK_OUT;
break;
case FHCI_TA_SETUP:
extra_data |= TD_TOK_SETUP;
break;
}
if (trans_mode == FHCI_TF_ISO)
extra_data |= TD_ISO;
out_be16(&td->extra, extra_data);
td_status = ((td_status & TD_W) | TD_R | TD_L | TD_I | TD_CNF);
if (!(pkt->info & PKT_NO_CRC))
td_status |= TD_TC;
switch (trans_type) {
case FHCI_TA_IN:
if (data_toggle)
pkt->info |= PKT_PID_DATA1;
else
pkt->info |= PKT_PID_DATA0;
break;
default:
if (data_toggle) {
td_status |= TD_PID_DATA1;
pkt->info |= PKT_PID_DATA1;
} else {
td_status |= TD_PID_DATA0;
pkt->info |= PKT_PID_DATA0;
}
break;
}
if ((dest_speed == FHCI_LOW_SPEED) &&
(usb->port_status == FHCI_PORT_FULL))
td_status |= TD_LSP;
out_be16(&td->status, td_status);
if (trans_type == FHCI_TA_IN)
out_be16(&td->length, pkt->len + CRC_SIZE);
else
out_be16(&td->length, pkt->len);
cq_put(&ep->conf_frame_Q, pkt);
if (cq_howmany(&ep->conf_frame_Q) == 1)
out_8(&usb->fhci->regs->usb_uscom, USB_CMD_STR_FIFO);
return 0;
}
void fhci_flush_bds(struct fhci_usb *usb)
{
u16 extra_data;
u16 td_status;
u32 buf;
struct usb_td __iomem *td;
struct endpoint *ep = usb->ep0;
td = ep->td_base;
while (1) {
td_status = in_be16(&td->status);
buf = in_be32(&td->buf_ptr);
extra_data = in_be16(&td->extra);
if (td_status & TD_R)
out_be16(&td->status, (td_status & ~TD_R) | TD_TO);
else if (in_be32(&td->buf_ptr) == DUMMY_BD_BUFFER)
out_be32(&td->buf_ptr, DUMMY2_BD_BUFFER);
if (td_status & TD_W)
break;
td++;
}
fhci_td_transaction_confirm(usb);
td = ep->td_base;
do {
out_be16(&td->status, 0);
out_be16(&td->length, 0);
out_be32(&td->buf_ptr, 0);
out_be16(&td->extra, 0);
td++;
} while (!(in_be16(&td->status) & TD_W));
out_be16(&td->status, TD_W);
out_be16(&td->length, 0);
out_be32(&td->buf_ptr, 0);
out_be16(&td->extra, 0);
out_be16(&ep->ep_pram_ptr->tx_bd_ptr,
in_be16(&ep->ep_pram_ptr->tx_base));
out_be32(&ep->ep_pram_ptr->tx_state, 0);
out_be16(&ep->ep_pram_ptr->tx_cnt, 0);
ep->empty_td = ep->td_base;
ep->conf_td = ep->td_base;
}
void fhci_flush_actual_frame(struct fhci_usb *usb)
{
u8 mode;
u16 tb_ptr;
u16 extra_data;
u16 td_status;
u32 buf_ptr;
struct usb_td __iomem *td;
struct endpoint *ep = usb->ep0;
mode = in_8(&usb->fhci->regs->usb_usmod);
out_8(&usb->fhci->regs->usb_usmod, mode & ~USB_MODE_EN);
tb_ptr = in_be16(&ep->ep_pram_ptr->tx_bd_ptr);
td = cpm_muram_addr(tb_ptr);
td_status = in_be16(&td->status);
buf_ptr = in_be32(&td->buf_ptr);
extra_data = in_be16(&td->extra);
do {
if (td_status & TD_R) {
out_be16(&td->status, (td_status & ~TD_R) | TD_TO);
} else {
out_be32(&td->buf_ptr, 0);
ep->already_pushed_dummy_bd = false;
break;
}
td = next_bd(ep->td_base, td, td_status);
td_status = in_be16(&td->status);
buf_ptr = in_be32(&td->buf_ptr);
extra_data = in_be16(&td->extra);
} while ((td_status & TD_R) || buf_ptr);
fhci_td_transaction_confirm(usb);
out_be16(&ep->ep_pram_ptr->tx_bd_ptr,
in_be16(&ep->ep_pram_ptr->tx_base));
out_be32(&ep->ep_pram_ptr->tx_state, 0);
out_be16(&ep->ep_pram_ptr->tx_cnt, 0);
ep->empty_td = ep->td_base;
ep->conf_td = ep->td_base;
usb->actual_frame->frame_status = FRAME_TIMER_END_TRANSMISSION;
out_be16(&usb->fhci->regs->usb_usber, 0xffff);
out_8(&usb->fhci->regs->usb_usmod, mode | USB_MODE_EN);
}
void fhci_tx_conf_interrupt(struct fhci_usb *usb)
{
fhci_td_transaction_confirm(usb);
if (((fhci_get_sof_timer_count(usb) < usb->max_frame_usage) ||
(usb->actual_frame->frame_status & FRAME_END_TRANSMISSION)) &&
(list_empty(&usb->actual_frame->tds_list)))
fhci_schedule_transactions(usb);
}
void fhci_host_transmit_actual_frame(struct fhci_usb *usb)
{
u16 tb_ptr;
u16 td_status;
struct usb_td __iomem *td;
struct endpoint *ep = usb->ep0;
tb_ptr = in_be16(&ep->ep_pram_ptr->tx_bd_ptr);
td = cpm_muram_addr(tb_ptr);
if (in_be32(&td->buf_ptr) == DUMMY_BD_BUFFER) {
struct usb_td __iomem *old_td = td;
ep->already_pushed_dummy_bd = false;
td_status = in_be16(&td->status);
td = next_bd(ep->td_base, td, td_status);
tb_ptr = cpm_muram_offset(td);
out_be16(&ep->ep_pram_ptr->tx_bd_ptr, tb_ptr);
if (in_be16(&td->status) & TD_R)
out_8(&usb->fhci->regs->usb_uscom, USB_CMD_STR_FIFO);
if (in_be32(&ep->conf_td->buf_ptr) == DUMMY_BD_BUFFER) {
out_be32(&old_td->buf_ptr, 0);
ep->conf_td = next_bd(ep->td_base, ep->conf_td,
td_status);
} else {
out_be32(&old_td->buf_ptr, DUMMY2_BD_BUFFER);
}
}
}
