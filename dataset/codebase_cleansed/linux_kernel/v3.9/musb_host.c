static void musb_h_tx_flush_fifo(struct musb_hw_ep *ep)
{
struct musb *musb = ep->musb;
void __iomem *epio = ep->regs;
u16 csr;
u16 lastcsr = 0;
int retries = 1000;
csr = musb_readw(epio, MUSB_TXCSR);
while (csr & MUSB_TXCSR_FIFONOTEMPTY) {
if (csr != lastcsr)
dev_dbg(musb->controller, "Host TX FIFONOTEMPTY csr: %02x\n", csr);
lastcsr = csr;
csr |= MUSB_TXCSR_FLUSHFIFO;
musb_writew(epio, MUSB_TXCSR, csr);
csr = musb_readw(epio, MUSB_TXCSR);
if (WARN(retries-- < 1,
"Could not flush host TX%d fifo: csr: %04x\n",
ep->epnum, csr))
return;
mdelay(1);
}
}
static void musb_h_ep0_flush_fifo(struct musb_hw_ep *ep)
{
void __iomem *epio = ep->regs;
u16 csr;
int retries = 5;
do {
csr = musb_readw(epio, MUSB_TXCSR);
if (!(csr & (MUSB_CSR0_TXPKTRDY | MUSB_CSR0_RXPKTRDY)))
break;
musb_writew(epio, MUSB_TXCSR, MUSB_CSR0_FLUSHFIFO);
csr = musb_readw(epio, MUSB_TXCSR);
udelay(10);
} while (--retries);
WARN(!retries, "Could not flush host TX%d fifo: csr: %04x\n",
ep->epnum, csr);
musb_writew(epio, MUSB_TXCSR, 0);
}
static inline void musb_h_tx_start(struct musb_hw_ep *ep)
{
u16 txcsr;
if (ep->epnum) {
txcsr = musb_readw(ep->regs, MUSB_TXCSR);
txcsr |= MUSB_TXCSR_TXPKTRDY | MUSB_TXCSR_H_WZC_BITS;
musb_writew(ep->regs, MUSB_TXCSR, txcsr);
} else {
txcsr = MUSB_CSR0_H_SETUPPKT | MUSB_CSR0_TXPKTRDY;
musb_writew(ep->regs, MUSB_CSR0, txcsr);
}
}
static inline void musb_h_tx_dma_start(struct musb_hw_ep *ep)
{
u16 txcsr;
txcsr = musb_readw(ep->regs, MUSB_TXCSR);
txcsr |= MUSB_TXCSR_DMAENAB | MUSB_TXCSR_H_WZC_BITS;
if (is_cppi_enabled())
txcsr |= MUSB_TXCSR_DMAMODE;
musb_writew(ep->regs, MUSB_TXCSR, txcsr);
}
static void musb_ep_set_qh(struct musb_hw_ep *ep, int is_in, struct musb_qh *qh)
{
if (is_in != 0 || ep->is_shared_fifo)
ep->in_qh = qh;
if (is_in == 0 || ep->is_shared_fifo)
ep->out_qh = qh;
}
static struct musb_qh *musb_ep_get_qh(struct musb_hw_ep *ep, int is_in)
{
return is_in ? ep->in_qh : ep->out_qh;
}
static void
musb_start_urb(struct musb *musb, int is_in, struct musb_qh *qh)
{
u16 frame;
u32 len;
void __iomem *mbase = musb->mregs;
struct urb *urb = next_urb(qh);
void *buf = urb->transfer_buffer;
u32 offset = 0;
struct musb_hw_ep *hw_ep = qh->hw_ep;
unsigned pipe = urb->pipe;
u8 address = usb_pipedevice(pipe);
int epnum = hw_ep->epnum;
qh->offset = 0;
qh->segsize = 0;
switch (qh->type) {
case USB_ENDPOINT_XFER_CONTROL:
is_in = 0;
musb->ep0_stage = MUSB_EP0_START;
buf = urb->setup_packet;
len = 8;
break;
case USB_ENDPOINT_XFER_ISOC:
qh->iso_idx = 0;
qh->frame = 0;
offset = urb->iso_frame_desc[0].offset;
len = urb->iso_frame_desc[0].length;
break;
default:
buf = urb->transfer_buffer + urb->actual_length;
len = urb->transfer_buffer_length - urb->actual_length;
}
dev_dbg(musb->controller, "qh %p urb %p dev%d ep%d%s%s, hw_ep %d, %p/%d\n",
qh, urb, address, qh->epnum,
is_in ? "in" : "out",
({char *s; switch (qh->type) {
case USB_ENDPOINT_XFER_CONTROL: s = ""; break;
case USB_ENDPOINT_XFER_BULK: s = "-bulk"; break;
case USB_ENDPOINT_XFER_ISOC: s = "-iso"; break;
default: s = "-intr"; break;
}; s; }),
epnum, buf + offset, len);
musb_ep_set_qh(hw_ep, is_in, qh);
musb_ep_program(musb, epnum, urb, !is_in, buf, offset, len);
if (is_in)
return;
switch (qh->type) {
case USB_ENDPOINT_XFER_ISOC:
case USB_ENDPOINT_XFER_INT:
dev_dbg(musb->controller, "check whether there's still time for periodic Tx\n");
frame = musb_readw(mbase, MUSB_FRAME);
if ((urb->transfer_flags & URB_ISO_ASAP)
|| (frame >= urb->start_frame)) {
qh->frame = 0;
goto start;
} else {
qh->frame = urb->start_frame;
dev_dbg(musb->controller, "SOF for %d\n", epnum);
#if 1
musb_writeb(mbase, MUSB_INTRUSBE, 0xff);
#endif
}
break;
default:
start:
dev_dbg(musb->controller, "Start TX%d %s\n", epnum,
hw_ep->tx_channel ? "dma" : "pio");
if (!hw_ep->tx_channel)
musb_h_tx_start(hw_ep);
else if (is_cppi_enabled() || tusb_dma_omap())
musb_h_tx_dma_start(hw_ep);
}
}
static void musb_giveback(struct musb *musb, struct urb *urb, int status)
__releases(musb->lock)
__acquires(musb->lock)
{
dev_dbg(musb->controller,
"complete %p %pF (%d), dev%d ep%d%s, %d/%d\n",
urb, urb->complete, status,
usb_pipedevice(urb->pipe),
usb_pipeendpoint(urb->pipe),
usb_pipein(urb->pipe) ? "in" : "out",
urb->actual_length, urb->transfer_buffer_length
);
usb_hcd_unlink_urb_from_ep(musb_to_hcd(musb), urb);
spin_unlock(&musb->lock);
usb_hcd_giveback_urb(musb_to_hcd(musb), urb, status);
spin_lock(&musb->lock);
}
static inline void musb_save_toggle(struct musb_qh *qh, int is_in,
struct urb *urb)
{
void __iomem *epio = qh->hw_ep->regs;
u16 csr;
if (is_in)
csr = musb_readw(epio, MUSB_RXCSR) & MUSB_RXCSR_H_DATATOGGLE;
else
csr = musb_readw(epio, MUSB_TXCSR) & MUSB_TXCSR_H_DATATOGGLE;
usb_settoggle(urb->dev, qh->epnum, !is_in, csr ? 1 : 0);
}
static void musb_advance_schedule(struct musb *musb, struct urb *urb,
struct musb_hw_ep *hw_ep, int is_in)
{
struct musb_qh *qh = musb_ep_get_qh(hw_ep, is_in);
struct musb_hw_ep *ep = qh->hw_ep;
int ready = qh->is_ready;
int status;
status = (urb->status == -EINPROGRESS) ? 0 : urb->status;
switch (qh->type) {
case USB_ENDPOINT_XFER_BULK:
case USB_ENDPOINT_XFER_INT:
musb_save_toggle(qh, is_in, urb);
break;
case USB_ENDPOINT_XFER_ISOC:
if (status == 0 && urb->error_count)
status = -EXDEV;
break;
}
qh->is_ready = 0;
musb_giveback(musb, urb, status);
qh->is_ready = ready;
if (list_empty(&qh->hep->urb_list)) {
struct list_head *head;
struct dma_controller *dma = musb->dma_controller;
if (is_in) {
ep->rx_reinit = 1;
if (ep->rx_channel) {
dma->channel_release(ep->rx_channel);
ep->rx_channel = NULL;
}
} else {
ep->tx_reinit = 1;
if (ep->tx_channel) {
dma->channel_release(ep->tx_channel);
ep->tx_channel = NULL;
}
}
musb_ep_set_qh(ep, is_in, NULL);
qh->hep->hcpriv = NULL;
switch (qh->type) {
case USB_ENDPOINT_XFER_CONTROL:
case USB_ENDPOINT_XFER_BULK:
if (qh->mux == 1) {
head = qh->ring.prev;
list_del(&qh->ring);
kfree(qh);
qh = first_qh(head);
break;
}
case USB_ENDPOINT_XFER_ISOC:
case USB_ENDPOINT_XFER_INT:
kfree(qh);
qh = NULL;
break;
}
}
if (qh != NULL && qh->is_ready) {
dev_dbg(musb->controller, "... next ep%d %cX urb %p\n",
hw_ep->epnum, is_in ? 'R' : 'T', next_urb(qh));
musb_start_urb(musb, is_in, qh);
}
}
static u16 musb_h_flush_rxfifo(struct musb_hw_ep *hw_ep, u16 csr)
{
csr |= MUSB_RXCSR_FLUSHFIFO | MUSB_RXCSR_RXPKTRDY;
csr &= ~(MUSB_RXCSR_H_REQPKT
| MUSB_RXCSR_H_AUTOREQ
| MUSB_RXCSR_AUTOCLEAR);
musb_writew(hw_ep->regs, MUSB_RXCSR, csr);
musb_writew(hw_ep->regs, MUSB_RXCSR, csr);
return musb_readw(hw_ep->regs, MUSB_RXCSR);
}
static bool
musb_host_packet_rx(struct musb *musb, struct urb *urb, u8 epnum, u8 iso_err)
{
u16 rx_count;
u8 *buf;
u16 csr;
bool done = false;
u32 length;
int do_flush = 0;
struct musb_hw_ep *hw_ep = musb->endpoints + epnum;
void __iomem *epio = hw_ep->regs;
struct musb_qh *qh = hw_ep->in_qh;
int pipe = urb->pipe;
void *buffer = urb->transfer_buffer;
rx_count = musb_readw(epio, MUSB_RXCOUNT);
dev_dbg(musb->controller, "RX%d count %d, buffer %p len %d/%d\n", epnum, rx_count,
urb->transfer_buffer, qh->offset,
urb->transfer_buffer_length);
if (usb_pipeisoc(pipe)) {
int status = 0;
struct usb_iso_packet_descriptor *d;
if (iso_err) {
status = -EILSEQ;
urb->error_count++;
}
d = urb->iso_frame_desc + qh->iso_idx;
buf = buffer + d->offset;
length = d->length;
if (rx_count > length) {
if (status == 0) {
status = -EOVERFLOW;
urb->error_count++;
}
dev_dbg(musb->controller, "** OVERFLOW %d into %d\n", rx_count, length);
do_flush = 1;
} else
length = rx_count;
urb->actual_length += length;
d->actual_length = length;
d->status = status;
done = (++qh->iso_idx >= urb->number_of_packets);
} else {
buf = buffer + qh->offset;
length = urb->transfer_buffer_length - qh->offset;
if (rx_count > length) {
if (urb->status == -EINPROGRESS)
urb->status = -EOVERFLOW;
dev_dbg(musb->controller, "** OVERFLOW %d into %d\n", rx_count, length);
do_flush = 1;
} else
length = rx_count;
urb->actual_length += length;
qh->offset += length;
done = (urb->actual_length == urb->transfer_buffer_length)
|| (rx_count < qh->maxpacket)
|| (urb->status != -EINPROGRESS);
if (done
&& (urb->status == -EINPROGRESS)
&& (urb->transfer_flags & URB_SHORT_NOT_OK)
&& (urb->actual_length
< urb->transfer_buffer_length))
urb->status = -EREMOTEIO;
}
musb_read_fifo(hw_ep, length, buf);
csr = musb_readw(epio, MUSB_RXCSR);
csr |= MUSB_RXCSR_H_WZC_BITS;
if (unlikely(do_flush))
musb_h_flush_rxfifo(hw_ep, csr);
else {
csr &= ~(MUSB_RXCSR_RXPKTRDY | MUSB_RXCSR_H_REQPKT);
if (!done)
csr |= MUSB_RXCSR_H_REQPKT;
musb_writew(epio, MUSB_RXCSR, csr);
}
return done;
}
static void
musb_rx_reinit(struct musb *musb, struct musb_qh *qh, struct musb_hw_ep *ep)
{
u16 csr;
if (ep->is_shared_fifo) {
csr = musb_readw(ep->regs, MUSB_TXCSR);
if (csr & MUSB_TXCSR_MODE) {
musb_h_tx_flush_fifo(ep);
csr = musb_readw(ep->regs, MUSB_TXCSR);
musb_writew(ep->regs, MUSB_TXCSR,
csr | MUSB_TXCSR_FRCDATATOG);
}
if (csr & MUSB_TXCSR_DMAMODE)
musb_writew(ep->regs, MUSB_TXCSR, MUSB_TXCSR_DMAMODE);
musb_writew(ep->regs, MUSB_TXCSR, 0);
} else {
csr = musb_readw(ep->regs, MUSB_RXCSR);
if (csr & MUSB_RXCSR_RXPKTRDY)
WARNING("rx%d, packet/%d ready?\n", ep->epnum,
musb_readw(ep->regs, MUSB_RXCOUNT));
musb_h_flush_rxfifo(ep, MUSB_RXCSR_CLRDATATOG);
}
if (musb->is_multipoint) {
musb_write_rxfunaddr(ep->target_regs, qh->addr_reg);
musb_write_rxhubaddr(ep->target_regs, qh->h_addr_reg);
musb_write_rxhubport(ep->target_regs, qh->h_port_reg);
} else
musb_writeb(musb->mregs, MUSB_FADDR, qh->addr_reg);
musb_writeb(ep->regs, MUSB_RXTYPE, qh->type_reg);
musb_writeb(ep->regs, MUSB_RXINTERVAL, qh->intv_reg);
if (musb->double_buffer_not_ok)
musb_writew(ep->regs, MUSB_RXMAXP, ep->max_packet_sz_rx);
else
musb_writew(ep->regs, MUSB_RXMAXP,
qh->maxpacket | ((qh->hb_mult - 1) << 11));
ep->rx_reinit = 0;
}
static bool musb_tx_dma_program(struct dma_controller *dma,
struct musb_hw_ep *hw_ep, struct musb_qh *qh,
struct urb *urb, u32 offset, u32 length)
{
struct dma_channel *channel = hw_ep->tx_channel;
void __iomem *epio = hw_ep->regs;
u16 pkt_size = qh->maxpacket;
u16 csr;
u8 mode;
#ifdef CONFIG_USB_INVENTRA_DMA
if (length > channel->max_len)
length = channel->max_len;
csr = musb_readw(epio, MUSB_TXCSR);
if (length > pkt_size) {
mode = 1;
csr |= MUSB_TXCSR_DMAMODE | MUSB_TXCSR_DMAENAB;
if (qh->hb_mult == 1 || (qh->hb_mult > 1 &&
can_bulk_split(hw_ep->musb, qh->type)))
csr |= MUSB_TXCSR_AUTOSET;
} else {
mode = 0;
csr &= ~(MUSB_TXCSR_AUTOSET | MUSB_TXCSR_DMAMODE);
csr |= MUSB_TXCSR_DMAENAB;
}
channel->desired_mode = mode;
musb_writew(epio, MUSB_TXCSR, csr);
#else
if (!is_cppi_enabled() && !tusb_dma_omap())
return false;
channel->actual_len = 0;
mode = (urb->transfer_flags & URB_ZERO_PACKET) ? 1 : 0;
#endif
qh->segsize = length;
wmb();
if (!dma->channel_program(channel, pkt_size, mode,
urb->transfer_dma + offset, length)) {
dma->channel_release(channel);
hw_ep->tx_channel = NULL;
csr = musb_readw(epio, MUSB_TXCSR);
csr &= ~(MUSB_TXCSR_AUTOSET | MUSB_TXCSR_DMAENAB);
musb_writew(epio, MUSB_TXCSR, csr | MUSB_TXCSR_H_WZC_BITS);
return false;
}
return true;
}
static void musb_ep_program(struct musb *musb, u8 epnum,
struct urb *urb, int is_out,
u8 *buf, u32 offset, u32 len)
{
struct dma_controller *dma_controller;
struct dma_channel *dma_channel;
u8 dma_ok;
void __iomem *mbase = musb->mregs;
struct musb_hw_ep *hw_ep = musb->endpoints + epnum;
void __iomem *epio = hw_ep->regs;
struct musb_qh *qh = musb_ep_get_qh(hw_ep, !is_out);
u16 packet_sz = qh->maxpacket;
u8 use_dma = 1;
u16 csr;
dev_dbg(musb->controller, "%s hw%d urb %p spd%d dev%d ep%d%s "
"h_addr%02x h_port%02x bytes %d\n",
is_out ? "-->" : "<--",
epnum, urb, urb->dev->speed,
qh->addr_reg, qh->epnum, is_out ? "out" : "in",
qh->h_addr_reg, qh->h_port_reg,
len);
musb_ep_select(mbase, epnum);
if (is_out && !len) {
use_dma = 0;
csr = musb_readw(epio, MUSB_TXCSR);
csr &= ~MUSB_TXCSR_DMAENAB;
musb_writew(epio, MUSB_TXCSR, csr);
hw_ep->tx_channel = NULL;
}
dma_controller = musb->dma_controller;
if (use_dma && is_dma_capable() && epnum && dma_controller) {
dma_channel = is_out ? hw_ep->tx_channel : hw_ep->rx_channel;
if (!dma_channel) {
dma_channel = dma_controller->channel_alloc(
dma_controller, hw_ep, is_out);
if (is_out)
hw_ep->tx_channel = dma_channel;
else
hw_ep->rx_channel = dma_channel;
}
} else
dma_channel = NULL;
if (is_out) {
u16 csr;
u16 int_txe;
u16 load_count;
csr = musb_readw(epio, MUSB_TXCSR);
int_txe = musb->intrtxe;
musb_writew(mbase, MUSB_INTRTXE, int_txe & ~(1 << epnum));
if (epnum) {
if (!hw_ep->tx_double_buffered)
musb_h_tx_flush_fifo(hw_ep);
csr &= ~(MUSB_TXCSR_H_NAKTIMEOUT
| MUSB_TXCSR_AUTOSET
| MUSB_TXCSR_DMAENAB
| MUSB_TXCSR_FRCDATATOG
| MUSB_TXCSR_H_RXSTALL
| MUSB_TXCSR_H_ERROR
| MUSB_TXCSR_TXPKTRDY
);
csr |= MUSB_TXCSR_MODE;
if (!hw_ep->tx_double_buffered) {
if (usb_gettoggle(urb->dev, qh->epnum, 1))
csr |= MUSB_TXCSR_H_WR_DATATOGGLE
| MUSB_TXCSR_H_DATATOGGLE;
else
csr |= MUSB_TXCSR_CLRDATATOG;
}
musb_writew(epio, MUSB_TXCSR, csr);
csr &= ~MUSB_TXCSR_DMAMODE;
musb_writew(epio, MUSB_TXCSR, csr);
csr = musb_readw(epio, MUSB_TXCSR);
} else {
musb_h_ep0_flush_fifo(hw_ep);
}
if (musb->is_multipoint) {
musb_write_txfunaddr(mbase, epnum, qh->addr_reg);
musb_write_txhubaddr(mbase, epnum, qh->h_addr_reg);
musb_write_txhubport(mbase, epnum, qh->h_port_reg);
} else
musb_writeb(mbase, MUSB_FADDR, qh->addr_reg);
if (epnum) {
musb_writeb(epio, MUSB_TXTYPE, qh->type_reg);
if (musb->double_buffer_not_ok) {
musb_writew(epio, MUSB_TXMAXP,
hw_ep->max_packet_sz_tx);
} else if (can_bulk_split(musb, qh->type)) {
qh->hb_mult = hw_ep->max_packet_sz_tx
/ packet_sz;
musb_writew(epio, MUSB_TXMAXP, packet_sz
| ((qh->hb_mult) - 1) << 11);
} else {
musb_writew(epio, MUSB_TXMAXP,
qh->maxpacket |
((qh->hb_mult - 1) << 11));
}
musb_writeb(epio, MUSB_TXINTERVAL, qh->intv_reg);
} else {
musb_writeb(epio, MUSB_NAKLIMIT0, qh->intv_reg);
if (musb->is_multipoint)
musb_writeb(epio, MUSB_TYPE0,
qh->type_reg);
}
if (can_bulk_split(musb, qh->type))
load_count = min((u32) hw_ep->max_packet_sz_tx,
len);
else
load_count = min((u32) packet_sz, len);
if (dma_channel && musb_tx_dma_program(dma_controller,
hw_ep, qh, urb, offset, len))
load_count = 0;
if (load_count) {
qh->segsize = load_count;
if (!buf) {
sg_miter_start(&qh->sg_miter, urb->sg, 1,
SG_MITER_ATOMIC
| SG_MITER_FROM_SG);
if (!sg_miter_next(&qh->sg_miter)) {
dev_err(musb->controller,
"error: sg"
"list empty\n");
sg_miter_stop(&qh->sg_miter);
goto finish;
}
buf = qh->sg_miter.addr + urb->sg->offset +
urb->actual_length;
load_count = min_t(u32, load_count,
qh->sg_miter.length);
musb_write_fifo(hw_ep, load_count, buf);
qh->sg_miter.consumed = load_count;
sg_miter_stop(&qh->sg_miter);
} else
musb_write_fifo(hw_ep, load_count, buf);
}
finish:
musb_writew(mbase, MUSB_INTRTXE, int_txe);
} else {
u16 csr;
if (hw_ep->rx_reinit) {
musb_rx_reinit(musb, qh, hw_ep);
if (usb_gettoggle(urb->dev, qh->epnum, 0))
csr = MUSB_RXCSR_H_WR_DATATOGGLE
| MUSB_RXCSR_H_DATATOGGLE;
else
csr = 0;
if (qh->type == USB_ENDPOINT_XFER_INT)
csr |= MUSB_RXCSR_DISNYET;
} else {
csr = musb_readw(hw_ep->regs, MUSB_RXCSR);
if (csr & (MUSB_RXCSR_RXPKTRDY
| MUSB_RXCSR_DMAENAB
| MUSB_RXCSR_H_REQPKT))
ERR("broken !rx_reinit, ep%d csr %04x\n",
hw_ep->epnum, csr);
csr &= MUSB_RXCSR_DISNYET;
}
if ((is_cppi_enabled() || tusb_dma_omap()) && dma_channel) {
dma_channel->actual_len = 0L;
qh->segsize = len;
musb_writew(hw_ep->regs, MUSB_RXCSR, csr);
csr = musb_readw(hw_ep->regs, MUSB_RXCSR);
dma_ok = dma_controller->channel_program(dma_channel,
packet_sz, !(urb->transfer_flags &
URB_SHORT_NOT_OK),
urb->transfer_dma + offset,
qh->segsize);
if (!dma_ok) {
dma_controller->channel_release(dma_channel);
hw_ep->rx_channel = dma_channel = NULL;
} else
csr |= MUSB_RXCSR_DMAENAB;
}
csr |= MUSB_RXCSR_H_REQPKT;
dev_dbg(musb->controller, "RXCSR%d := %04x\n", epnum, csr);
musb_writew(hw_ep->regs, MUSB_RXCSR, csr);
csr = musb_readw(hw_ep->regs, MUSB_RXCSR);
}
}
static void musb_bulk_nak_timeout(struct musb *musb, struct musb_hw_ep *ep,
int is_in)
{
struct dma_channel *dma;
struct urb *urb;
void __iomem *mbase = musb->mregs;
void __iomem *epio = ep->regs;
struct musb_qh *cur_qh, *next_qh;
u16 rx_csr, tx_csr;
musb_ep_select(mbase, ep->epnum);
if (is_in) {
dma = is_dma_capable() ? ep->rx_channel : NULL;
rx_csr = musb_readw(epio, MUSB_RXCSR);
rx_csr |= MUSB_RXCSR_H_WZC_BITS;
rx_csr &= ~MUSB_RXCSR_DATAERROR;
musb_writew(epio, MUSB_RXCSR, rx_csr);
cur_qh = first_qh(&musb->in_bulk);
} else {
dma = is_dma_capable() ? ep->tx_channel : NULL;
tx_csr = musb_readw(epio, MUSB_TXCSR);
tx_csr |= MUSB_TXCSR_H_WZC_BITS;
tx_csr &= ~MUSB_TXCSR_H_NAKTIMEOUT;
musb_writew(epio, MUSB_TXCSR, tx_csr);
cur_qh = first_qh(&musb->out_bulk);
}
if (cur_qh) {
urb = next_urb(cur_qh);
if (dma_channel_status(dma) == MUSB_DMA_STATUS_BUSY) {
dma->status = MUSB_DMA_STATUS_CORE_ABORT;
musb->dma_controller->channel_abort(dma);
urb->actual_length += dma->actual_len;
dma->actual_len = 0L;
}
musb_save_toggle(cur_qh, is_in, urb);
if (is_in) {
list_move_tail(&cur_qh->ring, &musb->in_bulk);
next_qh = first_qh(&musb->in_bulk);
ep->rx_reinit = 1;
} else {
list_move_tail(&cur_qh->ring, &musb->out_bulk);
next_qh = first_qh(&musb->out_bulk);
ep->tx_reinit = 1;
}
musb_start_urb(musb, is_in, next_qh);
}
}
static bool musb_h_ep0_continue(struct musb *musb, u16 len, struct urb *urb)
{
bool more = false;
u8 *fifo_dest = NULL;
u16 fifo_count = 0;
struct musb_hw_ep *hw_ep = musb->control_ep;
struct musb_qh *qh = hw_ep->in_qh;
struct usb_ctrlrequest *request;
switch (musb->ep0_stage) {
case MUSB_EP0_IN:
fifo_dest = urb->transfer_buffer + urb->actual_length;
fifo_count = min_t(size_t, len, urb->transfer_buffer_length -
urb->actual_length);
if (fifo_count < len)
urb->status = -EOVERFLOW;
musb_read_fifo(hw_ep, fifo_count, fifo_dest);
urb->actual_length += fifo_count;
if (len < qh->maxpacket) {
} else if (urb->actual_length <
urb->transfer_buffer_length)
more = true;
break;
case MUSB_EP0_START:
request = (struct usb_ctrlrequest *) urb->setup_packet;
if (!request->wLength) {
dev_dbg(musb->controller, "start no-DATA\n");
break;
} else if (request->bRequestType & USB_DIR_IN) {
dev_dbg(musb->controller, "start IN-DATA\n");
musb->ep0_stage = MUSB_EP0_IN;
more = true;
break;
} else {
dev_dbg(musb->controller, "start OUT-DATA\n");
musb->ep0_stage = MUSB_EP0_OUT;
more = true;
}
case MUSB_EP0_OUT:
fifo_count = min_t(size_t, qh->maxpacket,
urb->transfer_buffer_length -
urb->actual_length);
if (fifo_count) {
fifo_dest = (u8 *) (urb->transfer_buffer
+ urb->actual_length);
dev_dbg(musb->controller, "Sending %d byte%s to ep0 fifo %p\n",
fifo_count,
(fifo_count == 1) ? "" : "s",
fifo_dest);
musb_write_fifo(hw_ep, fifo_count, fifo_dest);
urb->actual_length += fifo_count;
more = true;
}
break;
default:
ERR("bogus ep0 stage %d\n", musb->ep0_stage);
break;
}
return more;
}
irqreturn_t musb_h_ep0_irq(struct musb *musb)
{
struct urb *urb;
u16 csr, len;
int status = 0;
void __iomem *mbase = musb->mregs;
struct musb_hw_ep *hw_ep = musb->control_ep;
void __iomem *epio = hw_ep->regs;
struct musb_qh *qh = hw_ep->in_qh;
bool complete = false;
irqreturn_t retval = IRQ_NONE;
urb = next_urb(qh);
musb_ep_select(mbase, 0);
csr = musb_readw(epio, MUSB_CSR0);
len = (csr & MUSB_CSR0_RXPKTRDY)
? musb_readb(epio, MUSB_COUNT0)
: 0;
dev_dbg(musb->controller, "<== csr0 %04x, qh %p, count %d, urb %p, stage %d\n",
csr, qh, len, urb, musb->ep0_stage);
if (MUSB_EP0_STATUS == musb->ep0_stage) {
retval = IRQ_HANDLED;
complete = true;
}
if (csr & MUSB_CSR0_H_RXSTALL) {
dev_dbg(musb->controller, "STALLING ENDPOINT\n");
status = -EPIPE;
} else if (csr & MUSB_CSR0_H_ERROR) {
dev_dbg(musb->controller, "no response, csr0 %04x\n", csr);
status = -EPROTO;
} else if (csr & MUSB_CSR0_H_NAKTIMEOUT) {
dev_dbg(musb->controller, "control NAK timeout\n");
musb_writew(epio, MUSB_CSR0, 0);
retval = IRQ_HANDLED;
}
if (status) {
dev_dbg(musb->controller, "aborting\n");
retval = IRQ_HANDLED;
if (urb)
urb->status = status;
complete = true;
if (csr & MUSB_CSR0_H_REQPKT) {
csr &= ~MUSB_CSR0_H_REQPKT;
musb_writew(epio, MUSB_CSR0, csr);
csr &= ~MUSB_CSR0_H_NAKTIMEOUT;
musb_writew(epio, MUSB_CSR0, csr);
} else {
musb_h_ep0_flush_fifo(hw_ep);
}
musb_writeb(epio, MUSB_NAKLIMIT0, 0);
musb_writew(epio, MUSB_CSR0, 0);
}
if (unlikely(!urb)) {
ERR("no URB for end 0\n");
musb_h_ep0_flush_fifo(hw_ep);
goto done;
}
if (!complete) {
if (musb_h_ep0_continue(musb, len, urb)) {
csr = (MUSB_EP0_IN == musb->ep0_stage)
? MUSB_CSR0_H_REQPKT : MUSB_CSR0_TXPKTRDY;
} else {
if (usb_pipeout(urb->pipe)
|| !urb->transfer_buffer_length)
csr = MUSB_CSR0_H_STATUSPKT
| MUSB_CSR0_H_REQPKT;
else
csr = MUSB_CSR0_H_STATUSPKT
| MUSB_CSR0_TXPKTRDY;
musb->ep0_stage = MUSB_EP0_STATUS;
dev_dbg(musb->controller, "ep0 STATUS, csr %04x\n", csr);
}
musb_writew(epio, MUSB_CSR0, csr);
retval = IRQ_HANDLED;
} else
musb->ep0_stage = MUSB_EP0_IDLE;
if (complete)
musb_advance_schedule(musb, urb, hw_ep, 1);
done:
return retval;
}
void musb_host_tx(struct musb *musb, u8 epnum)
{
int pipe;
bool done = false;
u16 tx_csr;
size_t length = 0;
size_t offset = 0;
struct musb_hw_ep *hw_ep = musb->endpoints + epnum;
void __iomem *epio = hw_ep->regs;
struct musb_qh *qh = hw_ep->out_qh;
struct urb *urb = next_urb(qh);
u32 status = 0;
void __iomem *mbase = musb->mregs;
struct dma_channel *dma;
bool transfer_pending = false;
static bool use_sg;
musb_ep_select(mbase, epnum);
tx_csr = musb_readw(epio, MUSB_TXCSR);
if (!urb) {
dev_dbg(musb->controller, "extra TX%d ready, csr %04x\n", epnum, tx_csr);
return;
}
pipe = urb->pipe;
dma = is_dma_capable() ? hw_ep->tx_channel : NULL;
dev_dbg(musb->controller, "OUT/TX%d end, csr %04x%s\n", epnum, tx_csr,
dma ? ", dma" : "");
if (tx_csr & MUSB_TXCSR_H_RXSTALL) {
dev_dbg(musb->controller, "TX end %d stall\n", epnum);
status = -EPIPE;
} else if (tx_csr & MUSB_TXCSR_H_ERROR) {
dev_dbg(musb->controller, "TX 3strikes on ep=%d\n", epnum);
status = -ETIMEDOUT;
} else if (tx_csr & MUSB_TXCSR_H_NAKTIMEOUT) {
if (USB_ENDPOINT_XFER_BULK == qh->type && qh->mux == 1
&& !list_is_singular(&musb->out_bulk)) {
dev_dbg(musb->controller,
"NAK timeout on TX%d ep\n", epnum);
musb_bulk_nak_timeout(musb, hw_ep, 0);
} else {
dev_dbg(musb->controller,
"TX end=%d device not responding\n", epnum);
musb_ep_select(mbase, epnum);
musb_writew(epio, MUSB_TXCSR,
MUSB_TXCSR_H_WZC_BITS
| MUSB_TXCSR_TXPKTRDY);
}
return;
}
done:
if (status) {
if (dma_channel_status(dma) == MUSB_DMA_STATUS_BUSY) {
dma->status = MUSB_DMA_STATUS_CORE_ABORT;
(void) musb->dma_controller->channel_abort(dma);
}
musb_h_tx_flush_fifo(hw_ep);
tx_csr &= ~(MUSB_TXCSR_AUTOSET
| MUSB_TXCSR_DMAENAB
| MUSB_TXCSR_H_ERROR
| MUSB_TXCSR_H_RXSTALL
| MUSB_TXCSR_H_NAKTIMEOUT
);
musb_ep_select(mbase, epnum);
musb_writew(epio, MUSB_TXCSR, tx_csr);
musb_writew(epio, MUSB_TXCSR, tx_csr);
musb_writeb(epio, MUSB_TXINTERVAL, 0);
done = true;
}
if (dma_channel_status(dma) == MUSB_DMA_STATUS_BUSY) {
dev_dbg(musb->controller, "extra TX%d ready, csr %04x\n", epnum, tx_csr);
return;
}
if (is_dma_capable() && dma && !status) {
if (tx_csr & MUSB_TXCSR_DMAMODE) {
tx_csr &= musb_readw(epio, MUSB_TXCSR);
if (tx_csr & MUSB_TXCSR_TXPKTRDY) {
tx_csr &= ~(MUSB_TXCSR_DMAENAB |
MUSB_TXCSR_TXPKTRDY);
musb_writew(epio, MUSB_TXCSR,
tx_csr | MUSB_TXCSR_H_WZC_BITS);
}
tx_csr &= ~(MUSB_TXCSR_DMAMODE |
MUSB_TXCSR_TXPKTRDY);
musb_writew(epio, MUSB_TXCSR,
tx_csr | MUSB_TXCSR_H_WZC_BITS);
tx_csr = musb_readw(epio, MUSB_TXCSR);
}
if (tx_csr & (MUSB_TXCSR_FIFONOTEMPTY | MUSB_TXCSR_TXPKTRDY)) {
dev_dbg(musb->controller, "DMA complete but packet still in FIFO, "
"CSR %04x\n", tx_csr);
return;
}
}
if (!status || dma || usb_pipeisoc(pipe)) {
if (dma)
length = dma->actual_len;
else
length = qh->segsize;
qh->offset += length;
if (usb_pipeisoc(pipe)) {
struct usb_iso_packet_descriptor *d;
d = urb->iso_frame_desc + qh->iso_idx;
d->actual_length = length;
d->status = status;
if (++qh->iso_idx >= urb->number_of_packets) {
done = true;
} else {
d++;
offset = d->offset;
length = d->length;
}
} else if (dma && urb->transfer_buffer_length == qh->offset) {
done = true;
} else {
if (qh->segsize < qh->maxpacket)
done = true;
else if (qh->offset == urb->transfer_buffer_length
&& !(urb->transfer_flags
& URB_ZERO_PACKET))
done = true;
if (!done) {
offset = qh->offset;
length = urb->transfer_buffer_length - offset;
transfer_pending = true;
}
}
}
if (urb->status != -EINPROGRESS) {
done = true;
if (status == 0)
status = urb->status;
}
if (done) {
urb->status = status;
urb->actual_length = qh->offset;
musb_advance_schedule(musb, urb, hw_ep, USB_DIR_OUT);
return;
} else if ((usb_pipeisoc(pipe) || transfer_pending) && dma) {
if (musb_tx_dma_program(musb->dma_controller, hw_ep, qh, urb,
offset, length)) {
if (is_cppi_enabled() || tusb_dma_omap())
musb_h_tx_dma_start(hw_ep);
return;
}
} else if (tx_csr & MUSB_TXCSR_DMAENAB) {
dev_dbg(musb->controller, "not complete, but DMA enabled?\n");
return;
}
if (length > qh->maxpacket)
length = qh->maxpacket;
usb_hcd_unmap_urb_for_dma(musb_to_hcd(musb), urb);
if (!urb->transfer_buffer)
use_sg = true;
if (use_sg) {
if (!sg_miter_next(&qh->sg_miter)) {
dev_err(musb->controller, "error: sg list empty\n");
sg_miter_stop(&qh->sg_miter);
status = -EINVAL;
goto done;
}
urb->transfer_buffer = qh->sg_miter.addr;
length = min_t(u32, length, qh->sg_miter.length);
musb_write_fifo(hw_ep, length, urb->transfer_buffer);
qh->sg_miter.consumed = length;
sg_miter_stop(&qh->sg_miter);
} else {
musb_write_fifo(hw_ep, length, urb->transfer_buffer + offset);
}
qh->segsize = length;
if (use_sg) {
if (offset + length >= urb->transfer_buffer_length)
use_sg = false;
}
musb_ep_select(mbase, epnum);
musb_writew(epio, MUSB_TXCSR,
MUSB_TXCSR_H_WZC_BITS | MUSB_TXCSR_TXPKTRDY);
}
void musb_host_rx(struct musb *musb, u8 epnum)
{
struct urb *urb;
struct musb_hw_ep *hw_ep = musb->endpoints + epnum;
void __iomem *epio = hw_ep->regs;
struct musb_qh *qh = hw_ep->in_qh;
size_t xfer_len;
void __iomem *mbase = musb->mregs;
int pipe;
u16 rx_csr, val;
bool iso_err = false;
bool done = false;
u32 status;
struct dma_channel *dma;
static bool use_sg;
unsigned int sg_flags = SG_MITER_ATOMIC | SG_MITER_TO_SG;
musb_ep_select(mbase, epnum);
urb = next_urb(qh);
dma = is_dma_capable() ? hw_ep->rx_channel : NULL;
status = 0;
xfer_len = 0;
rx_csr = musb_readw(epio, MUSB_RXCSR);
val = rx_csr;
if (unlikely(!urb)) {
dev_dbg(musb->controller, "BOGUS RX%d ready, csr %04x, count %d\n", epnum, val,
musb_readw(epio, MUSB_RXCOUNT));
musb_h_flush_rxfifo(hw_ep, MUSB_RXCSR_CLRDATATOG);
return;
}
pipe = urb->pipe;
dev_dbg(musb->controller, "<== hw %d rxcsr %04x, urb actual %d (+dma %zu)\n",
epnum, rx_csr, urb->actual_length,
dma ? dma->actual_len : 0);
if (rx_csr & MUSB_RXCSR_H_RXSTALL) {
dev_dbg(musb->controller, "RX end %d STALL\n", epnum);
status = -EPIPE;
} else if (rx_csr & MUSB_RXCSR_H_ERROR) {
dev_dbg(musb->controller, "end %d RX proto error\n", epnum);
status = -EPROTO;
musb_writeb(epio, MUSB_RXINTERVAL, 0);
} else if (rx_csr & MUSB_RXCSR_DATAERROR) {
if (USB_ENDPOINT_XFER_ISOC != qh->type) {
dev_dbg(musb->controller, "RX end %d NAK timeout\n", epnum);
if (usb_pipebulk(urb->pipe)
&& qh->mux == 1
&& !list_is_singular(&musb->in_bulk)) {
musb_bulk_nak_timeout(musb, hw_ep, 1);
return;
}
musb_ep_select(mbase, epnum);
rx_csr |= MUSB_RXCSR_H_WZC_BITS;
rx_csr &= ~MUSB_RXCSR_DATAERROR;
musb_writew(epio, MUSB_RXCSR, rx_csr);
goto finish;
} else {
dev_dbg(musb->controller, "RX end %d ISO data error\n", epnum);
iso_err = true;
}
} else if (rx_csr & MUSB_RXCSR_INCOMPRX) {
dev_dbg(musb->controller, "end %d high bandwidth incomplete ISO packet RX\n",
epnum);
status = -EPROTO;
}
if (status) {
if (dma_channel_status(dma) == MUSB_DMA_STATUS_BUSY) {
dma->status = MUSB_DMA_STATUS_CORE_ABORT;
(void) musb->dma_controller->channel_abort(dma);
xfer_len = dma->actual_len;
}
musb_h_flush_rxfifo(hw_ep, MUSB_RXCSR_CLRDATATOG);
musb_writeb(epio, MUSB_RXINTERVAL, 0);
done = true;
goto finish;
}
if (unlikely(dma_channel_status(dma) == MUSB_DMA_STATUS_BUSY)) {
ERR("RX%d dma busy, csr %04x\n", epnum, rx_csr);
goto finish;
}
#ifndef CONFIG_USB_INVENTRA_DMA
if (rx_csr & MUSB_RXCSR_H_REQPKT) {
if (dma_channel_status(dma) == MUSB_DMA_STATUS_BUSY) {
dma->status = MUSB_DMA_STATUS_CORE_ABORT;
(void) musb->dma_controller->channel_abort(dma);
xfer_len = dma->actual_len;
done = true;
}
dev_dbg(musb->controller, "RXCSR%d %04x, reqpkt, len %zu%s\n", epnum, rx_csr,
xfer_len, dma ? ", dma" : "");
rx_csr &= ~MUSB_RXCSR_H_REQPKT;
musb_ep_select(mbase, epnum);
musb_writew(epio, MUSB_RXCSR,
MUSB_RXCSR_H_WZC_BITS | rx_csr);
}
#endif
if (dma && (rx_csr & MUSB_RXCSR_DMAENAB)) {
xfer_len = dma->actual_len;
val &= ~(MUSB_RXCSR_DMAENAB
| MUSB_RXCSR_H_AUTOREQ
| MUSB_RXCSR_AUTOCLEAR
| MUSB_RXCSR_RXPKTRDY);
musb_writew(hw_ep->regs, MUSB_RXCSR, val);
#ifdef CONFIG_USB_INVENTRA_DMA
if (usb_pipeisoc(pipe)) {
struct usb_iso_packet_descriptor *d;
d = urb->iso_frame_desc + qh->iso_idx;
d->actual_length = xfer_len;
if (d->status != -EILSEQ && d->status != -EOVERFLOW)
d->status = 0;
if (++qh->iso_idx >= urb->number_of_packets)
done = true;
else
done = false;
} else {
done = (urb->actual_length + xfer_len >=
urb->transfer_buffer_length
|| dma->actual_len < qh->maxpacket);
}
if (!done) {
val |= MUSB_RXCSR_H_REQPKT;
musb_writew(epio, MUSB_RXCSR,
MUSB_RXCSR_H_WZC_BITS | val);
}
dev_dbg(musb->controller, "ep %d dma %s, rxcsr %04x, rxcount %d\n", epnum,
done ? "off" : "reset",
musb_readw(epio, MUSB_RXCSR),
musb_readw(epio, MUSB_RXCOUNT));
#else
done = true;
#endif
} else if (urb->status == -EINPROGRESS) {
if (unlikely(!(rx_csr & MUSB_RXCSR_RXPKTRDY))) {
status = -EPROTO;
ERR("Rx interrupt with no errors or packet!\n");
musb_ep_select(mbase, epnum);
val &= ~MUSB_RXCSR_H_REQPKT;
musb_writew(epio, MUSB_RXCSR, val);
goto finish;
}
#ifdef CONFIG_USB_INVENTRA_DMA
if (dma) {
struct dma_controller *c;
u16 rx_count;
int ret, length;
dma_addr_t buf;
rx_count = musb_readw(epio, MUSB_RXCOUNT);
dev_dbg(musb->controller, "RX%d count %d, buffer 0x%x len %d/%d\n",
epnum, rx_count,
urb->transfer_dma
+ urb->actual_length,
qh->offset,
urb->transfer_buffer_length);
c = musb->dma_controller;
if (usb_pipeisoc(pipe)) {
int d_status = 0;
struct usb_iso_packet_descriptor *d;
d = urb->iso_frame_desc + qh->iso_idx;
if (iso_err) {
d_status = -EILSEQ;
urb->error_count++;
}
if (rx_count > d->length) {
if (d_status == 0) {
d_status = -EOVERFLOW;
urb->error_count++;
}
dev_dbg(musb->controller, "** OVERFLOW %d into %d\n",\
rx_count, d->length);
length = d->length;
} else
length = rx_count;
d->status = d_status;
buf = urb->transfer_dma + d->offset;
} else {
length = rx_count;
buf = urb->transfer_dma +
urb->actual_length;
}
dma->desired_mode = 0;
#ifdef USE_MODE1
if ((urb->transfer_flags &
URB_SHORT_NOT_OK)
&& (urb->transfer_buffer_length -
urb->actual_length)
> qh->maxpacket)
dma->desired_mode = 1;
if (rx_count < hw_ep->max_packet_sz_rx) {
length = rx_count;
dma->desired_mode = 0;
} else {
length = urb->transfer_buffer_length;
}
#endif
val = musb_readw(epio, MUSB_RXCSR);
val &= ~MUSB_RXCSR_H_REQPKT;
if (dma->desired_mode == 0)
val &= ~MUSB_RXCSR_H_AUTOREQ;
else
val |= MUSB_RXCSR_H_AUTOREQ;
val |= MUSB_RXCSR_DMAENAB;
if (qh->hb_mult == 1)
val |= MUSB_RXCSR_AUTOCLEAR;
musb_writew(epio, MUSB_RXCSR,
MUSB_RXCSR_H_WZC_BITS | val);
ret = c->channel_program(
dma, qh->maxpacket,
dma->desired_mode, buf, length);
if (!ret) {
c->channel_release(dma);
hw_ep->rx_channel = NULL;
dma = NULL;
val = musb_readw(epio, MUSB_RXCSR);
val &= ~(MUSB_RXCSR_DMAENAB
| MUSB_RXCSR_H_AUTOREQ
| MUSB_RXCSR_AUTOCLEAR);
musb_writew(epio, MUSB_RXCSR, val);
}
}
#endif
if (!dma) {
unsigned int received_len;
usb_hcd_unmap_urb_for_dma(musb_to_hcd(musb), urb);
if (!urb->transfer_buffer) {
use_sg = true;
sg_miter_start(&qh->sg_miter, urb->sg, 1,
sg_flags);
}
if (use_sg) {
if (!sg_miter_next(&qh->sg_miter)) {
dev_err(musb->controller, "error: sg list empty\n");
sg_miter_stop(&qh->sg_miter);
status = -EINVAL;
done = true;
goto finish;
}
urb->transfer_buffer = qh->sg_miter.addr;
received_len = urb->actual_length;
qh->offset = 0x0;
done = musb_host_packet_rx(musb, urb, epnum,
iso_err);
received_len = urb->actual_length -
received_len;
qh->sg_miter.consumed = received_len;
sg_miter_stop(&qh->sg_miter);
} else {
done = musb_host_packet_rx(musb, urb,
epnum, iso_err);
}
dev_dbg(musb->controller, "read %spacket\n", done ? "last " : "");
}
}
finish:
urb->actual_length += xfer_len;
qh->offset += xfer_len;
if (done) {
if (use_sg)
use_sg = false;
if (urb->status == -EINPROGRESS)
urb->status = status;
musb_advance_schedule(musb, urb, hw_ep, USB_DIR_IN);
}
}
static int musb_schedule(
struct musb *musb,
struct musb_qh *qh,
int is_in)
{
int idle;
int best_diff;
int best_end, epnum;
struct musb_hw_ep *hw_ep = NULL;
struct list_head *head = NULL;
u8 toggle;
u8 txtype;
struct urb *urb = next_urb(qh);
if (qh->type == USB_ENDPOINT_XFER_CONTROL) {
head = &musb->control;
hw_ep = musb->control_ep;
goto success;
}
best_diff = 4096;
best_end = -1;
for (epnum = 1, hw_ep = musb->endpoints + 1;
epnum < musb->nr_endpoints;
epnum++, hw_ep++) {
int diff;
if (musb_ep_get_qh(hw_ep, is_in) != NULL)
continue;
if (hw_ep == musb->bulk_ep)
continue;
if (is_in)
diff = hw_ep->max_packet_sz_rx;
else
diff = hw_ep->max_packet_sz_tx;
diff -= (qh->maxpacket * qh->hb_mult);
if (diff >= 0 && best_diff > diff) {
hw_ep = musb->endpoints + epnum;
toggle = usb_gettoggle(urb->dev, qh->epnum, !is_in);
txtype = (musb_readb(hw_ep->regs, MUSB_TXTYPE)
>> 4) & 0x3;
if (!is_in && (qh->type == USB_ENDPOINT_XFER_BULK) &&
toggle && (txtype == USB_ENDPOINT_XFER_ISOC))
continue;
best_diff = diff;
best_end = epnum;
}
}
if (best_end < 0 && qh->type == USB_ENDPOINT_XFER_BULK) {
hw_ep = musb->bulk_ep;
if (is_in)
head = &musb->in_bulk;
else
head = &musb->out_bulk;
if (qh->dev)
qh->intv_reg =
(USB_SPEED_HIGH == qh->dev->speed) ? 8 : 4;
goto success;
} else if (best_end < 0) {
return -ENOSPC;
}
idle = 1;
qh->mux = 0;
hw_ep = musb->endpoints + best_end;
dev_dbg(musb->controller, "qh %p periodic slot %d\n", qh, best_end);
success:
if (head) {
idle = list_empty(head);
list_add_tail(&qh->ring, head);
qh->mux = 1;
}
qh->hw_ep = hw_ep;
qh->hep->hcpriv = qh;
if (idle)
musb_start_urb(musb, is_in, qh);
return 0;
}
static int musb_urb_enqueue(
struct usb_hcd *hcd,
struct urb *urb,
gfp_t mem_flags)
{
unsigned long flags;
struct musb *musb = hcd_to_musb(hcd);
struct usb_host_endpoint *hep = urb->ep;
struct musb_qh *qh;
struct usb_endpoint_descriptor *epd = &hep->desc;
int ret;
unsigned type_reg;
unsigned interval;
if (!is_host_active(musb) || !musb->is_active)
return -ENODEV;
spin_lock_irqsave(&musb->lock, flags);
ret = usb_hcd_link_urb_to_ep(hcd, urb);
qh = ret ? NULL : hep->hcpriv;
if (qh)
urb->hcpriv = qh;
spin_unlock_irqrestore(&musb->lock, flags);
if (qh || ret)
return ret;
qh = kzalloc(sizeof *qh, mem_flags);
if (!qh) {
spin_lock_irqsave(&musb->lock, flags);
usb_hcd_unlink_urb_from_ep(hcd, urb);
spin_unlock_irqrestore(&musb->lock, flags);
return -ENOMEM;
}
qh->hep = hep;
qh->dev = urb->dev;
INIT_LIST_HEAD(&qh->ring);
qh->is_ready = 1;
qh->maxpacket = usb_endpoint_maxp(epd);
qh->type = usb_endpoint_type(epd);
qh->hb_mult = 1 + ((qh->maxpacket >> 11) & 0x03);
if (qh->hb_mult > 1) {
int ok = (qh->type == USB_ENDPOINT_XFER_ISOC);
if (ok)
ok = (usb_pipein(urb->pipe) && musb->hb_iso_rx)
|| (usb_pipeout(urb->pipe) && musb->hb_iso_tx);
if (!ok) {
ret = -EMSGSIZE;
goto done;
}
qh->maxpacket &= 0x7ff;
}
qh->epnum = usb_endpoint_num(epd);
qh->addr_reg = (u8) usb_pipedevice(urb->pipe);
type_reg = (qh->type << 4) | qh->epnum;
switch (urb->dev->speed) {
case USB_SPEED_LOW:
type_reg |= 0xc0;
break;
case USB_SPEED_FULL:
type_reg |= 0x80;
break;
default:
type_reg |= 0x40;
}
qh->type_reg = type_reg;
switch (qh->type) {
case USB_ENDPOINT_XFER_INT:
if (urb->dev->speed <= USB_SPEED_FULL) {
interval = max_t(u8, epd->bInterval, 1);
break;
}
case USB_ENDPOINT_XFER_ISOC:
interval = min_t(u8, epd->bInterval, 16);
break;
default:
interval = 0;
}
qh->intv_reg = interval;
if (musb->is_multipoint) {
struct usb_device *parent = urb->dev->parent;
if (parent != hcd->self.root_hub) {
qh->h_addr_reg = (u8) parent->devnum;
if (urb->dev->tt) {
qh->h_port_reg = (u8) urb->dev->ttport;
if (urb->dev->tt->hub)
qh->h_addr_reg =
(u8) urb->dev->tt->hub->devnum;
if (urb->dev->tt->multi)
qh->h_addr_reg |= 0x80;
}
}
}
spin_lock_irqsave(&musb->lock, flags);
if (hep->hcpriv || !next_urb(qh)) {
kfree(qh);
qh = NULL;
ret = 0;
} else
ret = musb_schedule(musb, qh,
epd->bEndpointAddress & USB_ENDPOINT_DIR_MASK);
if (ret == 0) {
urb->hcpriv = qh;
}
spin_unlock_irqrestore(&musb->lock, flags);
done:
if (ret != 0) {
spin_lock_irqsave(&musb->lock, flags);
usb_hcd_unlink_urb_from_ep(hcd, urb);
spin_unlock_irqrestore(&musb->lock, flags);
kfree(qh);
}
return ret;
}
static int musb_cleanup_urb(struct urb *urb, struct musb_qh *qh)
{
struct musb_hw_ep *ep = qh->hw_ep;
struct musb *musb = ep->musb;
void __iomem *epio = ep->regs;
unsigned hw_end = ep->epnum;
void __iomem *regs = ep->musb->mregs;
int is_in = usb_pipein(urb->pipe);
int status = 0;
u16 csr;
musb_ep_select(regs, hw_end);
if (is_dma_capable()) {
struct dma_channel *dma;
dma = is_in ? ep->rx_channel : ep->tx_channel;
if (dma) {
status = ep->musb->dma_controller->channel_abort(dma);
dev_dbg(musb->controller,
"abort %cX%d DMA for urb %p --> %d\n",
is_in ? 'R' : 'T', ep->epnum,
urb, status);
urb->actual_length += dma->actual_len;
}
}
if (ep->epnum && is_in) {
csr = musb_h_flush_rxfifo(ep, 0);
} else if (ep->epnum) {
musb_h_tx_flush_fifo(ep);
csr = musb_readw(epio, MUSB_TXCSR);
csr &= ~(MUSB_TXCSR_AUTOSET
| MUSB_TXCSR_DMAENAB
| MUSB_TXCSR_H_RXSTALL
| MUSB_TXCSR_H_NAKTIMEOUT
| MUSB_TXCSR_H_ERROR
| MUSB_TXCSR_TXPKTRDY);
musb_writew(epio, MUSB_TXCSR, csr);
musb_writew(epio, MUSB_TXCSR, csr);
csr = musb_readw(epio, MUSB_TXCSR);
} else {
musb_h_ep0_flush_fifo(ep);
}
if (status == 0)
musb_advance_schedule(ep->musb, urb, ep, is_in);
return status;
}
static int musb_urb_dequeue(struct usb_hcd *hcd, struct urb *urb, int status)
{
struct musb *musb = hcd_to_musb(hcd);
struct musb_qh *qh;
unsigned long flags;
int is_in = usb_pipein(urb->pipe);
int ret;
dev_dbg(musb->controller, "urb=%p, dev%d ep%d%s\n", urb,
usb_pipedevice(urb->pipe),
usb_pipeendpoint(urb->pipe),
is_in ? "in" : "out");
spin_lock_irqsave(&musb->lock, flags);
ret = usb_hcd_check_unlink_urb(hcd, urb, status);
if (ret)
goto done;
qh = urb->hcpriv;
if (!qh)
goto done;
if (!qh->is_ready
|| urb->urb_list.prev != &qh->hep->urb_list
|| musb_ep_get_qh(qh->hw_ep, is_in) != qh) {
int ready = qh->is_ready;
qh->is_ready = 0;
musb_giveback(musb, urb, 0);
qh->is_ready = ready;
if (ready && list_empty(&qh->hep->urb_list)) {
qh->hep->hcpriv = NULL;
list_del(&qh->ring);
kfree(qh);
}
} else
ret = musb_cleanup_urb(urb, qh);
done:
spin_unlock_irqrestore(&musb->lock, flags);
return ret;
}
static void
musb_h_disable(struct usb_hcd *hcd, struct usb_host_endpoint *hep)
{
u8 is_in = hep->desc.bEndpointAddress & USB_DIR_IN;
unsigned long flags;
struct musb *musb = hcd_to_musb(hcd);
struct musb_qh *qh;
struct urb *urb;
spin_lock_irqsave(&musb->lock, flags);
qh = hep->hcpriv;
if (qh == NULL)
goto exit;
qh->is_ready = 0;
if (musb_ep_get_qh(qh->hw_ep, is_in) == qh) {
urb = next_urb(qh);
if (!urb->unlinked)
urb->status = -ESHUTDOWN;
musb_cleanup_urb(urb, qh);
while (!list_empty(&hep->urb_list)) {
urb = next_urb(qh);
urb->status = -ESHUTDOWN;
musb_advance_schedule(musb, urb, qh->hw_ep, is_in);
}
} else {
while (!list_empty(&hep->urb_list))
musb_giveback(musb, next_urb(qh), -ESHUTDOWN);
hep->hcpriv = NULL;
list_del(&qh->ring);
kfree(qh);
}
exit:
spin_unlock_irqrestore(&musb->lock, flags);
}
static int musb_h_get_frame_number(struct usb_hcd *hcd)
{
struct musb *musb = hcd_to_musb(hcd);
return musb_readw(musb->mregs, MUSB_FRAME);
}
static int musb_h_start(struct usb_hcd *hcd)
{
struct musb *musb = hcd_to_musb(hcd);
hcd->state = HC_STATE_RUNNING;
musb->port1_status = 0;
return 0;
}
static void musb_h_stop(struct usb_hcd *hcd)
{
musb_stop(hcd_to_musb(hcd));
hcd->state = HC_STATE_HALT;
}
static int musb_bus_suspend(struct usb_hcd *hcd)
{
struct musb *musb = hcd_to_musb(hcd);
u8 devctl;
if (!is_host_active(musb))
return 0;
switch (musb->xceiv->state) {
case OTG_STATE_A_SUSPEND:
return 0;
case OTG_STATE_A_WAIT_VRISE:
devctl = musb_readb(musb->mregs, MUSB_DEVCTL);
if ((devctl & MUSB_DEVCTL_VBUS) == MUSB_DEVCTL_VBUS)
musb->xceiv->state = OTG_STATE_A_WAIT_BCON;
break;
default:
break;
}
if (musb->is_active) {
WARNING("trying to suspend as %s while active\n",
otg_state_string(musb->xceiv->state));
return -EBUSY;
} else
return 0;
}
static int musb_bus_resume(struct usb_hcd *hcd)
{
return 0;
}
