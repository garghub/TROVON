static inline struct usb_hcd *octeon_to_hcd(struct octeon_hcd *p)
{
return container_of((void *)p, struct usb_hcd, hcd_priv);
}
static int octeon_alloc_temp_buffer(struct urb *urb, gfp_t mem_flags)
{
struct octeon_temp_buffer *temp;
if (urb->num_sgs || urb->sg ||
(urb->transfer_flags & URB_NO_TRANSFER_DMA_MAP) ||
!(urb->transfer_buffer_length % sizeof(u32)))
return 0;
temp = kmalloc(ALIGN(urb->transfer_buffer_length, sizeof(u32)) +
sizeof(*temp), mem_flags);
if (!temp)
return -ENOMEM;
temp->orig_buffer = urb->transfer_buffer;
if (usb_urb_dir_out(urb))
memcpy(temp->data, urb->transfer_buffer,
urb->transfer_buffer_length);
urb->transfer_buffer = temp->data;
urb->transfer_flags |= URB_ALIGNED_TEMP_BUFFER;
return 0;
}
static void octeon_free_temp_buffer(struct urb *urb)
{
struct octeon_temp_buffer *temp;
size_t length;
if (!(urb->transfer_flags & URB_ALIGNED_TEMP_BUFFER))
return;
temp = container_of(urb->transfer_buffer, struct octeon_temp_buffer,
data);
if (usb_urb_dir_in(urb)) {
if (usb_pipeisoc(urb->pipe))
length = urb->transfer_buffer_length;
else
length = urb->actual_length;
memcpy(temp->orig_buffer, urb->transfer_buffer, length);
}
urb->transfer_buffer = temp->orig_buffer;
urb->transfer_flags &= ~URB_ALIGNED_TEMP_BUFFER;
kfree(temp);
}
static int octeon_map_urb_for_dma(struct usb_hcd *hcd, struct urb *urb,
gfp_t mem_flags)
{
int ret;
ret = octeon_alloc_temp_buffer(urb, mem_flags);
if (ret)
return ret;
ret = usb_hcd_map_urb_for_dma(hcd, urb, mem_flags);
if (ret)
octeon_free_temp_buffer(urb);
return ret;
}
static void octeon_unmap_urb_for_dma(struct usb_hcd *hcd, struct urb *urb)
{
usb_hcd_unmap_urb_for_dma(hcd, urb);
octeon_free_temp_buffer(urb);
}
static inline u32 cvmx_usb_read_csr32(struct octeon_hcd *usb, u64 address)
{
u32 result = cvmx_read64_uint32(address ^ 4);
return result;
}
static inline void cvmx_usb_write_csr32(struct octeon_hcd *usb,
u64 address, u32 value)
{
cvmx_write64_uint32(address ^ 4, value);
cvmx_read64_uint64(CVMX_USBNX_DMA0_INB_CHN0(usb->index));
}
static inline int cvmx_usb_pipe_needs_split(struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe)
{
return pipe->device_speed != CVMX_USB_SPEED_HIGH &&
usb->usbcx_hprt.s.prtspd == CVMX_USB_SPEED_HIGH;
}
static inline int cvmx_usb_get_data_pid(struct cvmx_usb_pipe *pipe)
{
if (pipe->pid_toggle)
return 2;
return 0;
}
static void cvmx_fifo_setup(struct octeon_hcd *usb)
{
union cvmx_usbcx_ghwcfg3 usbcx_ghwcfg3;
union cvmx_usbcx_gnptxfsiz npsiz;
union cvmx_usbcx_hptxfsiz psiz;
usbcx_ghwcfg3.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_GHWCFG3(usb->index));
USB_SET_FIELD32(CVMX_USBCX_GRXFSIZ(usb->index), cvmx_usbcx_grxfsiz,
rxfdep, usbcx_ghwcfg3.s.dfifodepth / 4);
npsiz.u32 = cvmx_usb_read_csr32(usb, CVMX_USBCX_GNPTXFSIZ(usb->index));
npsiz.s.nptxfdep = usbcx_ghwcfg3.s.dfifodepth / 2;
npsiz.s.nptxfstaddr = usbcx_ghwcfg3.s.dfifodepth / 4;
cvmx_usb_write_csr32(usb, CVMX_USBCX_GNPTXFSIZ(usb->index), npsiz.u32);
psiz.u32 = cvmx_usb_read_csr32(usb, CVMX_USBCX_HPTXFSIZ(usb->index));
psiz.s.ptxfsize = usbcx_ghwcfg3.s.dfifodepth / 4;
psiz.s.ptxfstaddr = 3 * usbcx_ghwcfg3.s.dfifodepth / 4;
cvmx_usb_write_csr32(usb, CVMX_USBCX_HPTXFSIZ(usb->index), psiz.u32);
USB_SET_FIELD32(CVMX_USBCX_GRSTCTL(usb->index),
cvmx_usbcx_grstctl, txfnum, 0x10);
USB_SET_FIELD32(CVMX_USBCX_GRSTCTL(usb->index),
cvmx_usbcx_grstctl, txfflsh, 1);
CVMX_WAIT_FOR_FIELD32(CVMX_USBCX_GRSTCTL(usb->index),
cvmx_usbcx_grstctl, c.s.txfflsh == 0, 100);
USB_SET_FIELD32(CVMX_USBCX_GRSTCTL(usb->index),
cvmx_usbcx_grstctl, rxfflsh, 1);
CVMX_WAIT_FOR_FIELD32(CVMX_USBCX_GRSTCTL(usb->index),
cvmx_usbcx_grstctl, c.s.rxfflsh == 0, 100);
}
static int cvmx_usb_shutdown(struct octeon_hcd *usb)
{
union cvmx_usbnx_clk_ctl usbn_clk_ctl;
if (!list_empty(&usb->idle_pipes) ||
!list_empty(&usb->active_pipes[CVMX_USB_TRANSFER_ISOCHRONOUS]) ||
!list_empty(&usb->active_pipes[CVMX_USB_TRANSFER_INTERRUPT]) ||
!list_empty(&usb->active_pipes[CVMX_USB_TRANSFER_CONTROL]) ||
!list_empty(&usb->active_pipes[CVMX_USB_TRANSFER_BULK]))
return -EBUSY;
usbn_clk_ctl.u64 = cvmx_read64_uint64(CVMX_USBNX_CLK_CTL(usb->index));
usbn_clk_ctl.s.enable = 1;
usbn_clk_ctl.s.por = 1;
usbn_clk_ctl.s.hclk_rst = 1;
usbn_clk_ctl.s.prst = 0;
usbn_clk_ctl.s.hrst = 0;
cvmx_write64_uint64(CVMX_USBNX_CLK_CTL(usb->index), usbn_clk_ctl.u64);
return 0;
}
static int cvmx_usb_initialize(struct device *dev,
struct octeon_hcd *usb)
{
int channel;
int divisor;
int retries = 0;
union cvmx_usbcx_hcfg usbcx_hcfg;
union cvmx_usbnx_clk_ctl usbn_clk_ctl;
union cvmx_usbcx_gintsts usbc_gintsts;
union cvmx_usbcx_gahbcfg usbcx_gahbcfg;
union cvmx_usbcx_gintmsk usbcx_gintmsk;
union cvmx_usbcx_gusbcfg usbcx_gusbcfg;
union cvmx_usbnx_usbp_ctl_status usbn_usbp_ctl_status;
retry:
usbn_clk_ctl.u64 = cvmx_read64_uint64(CVMX_USBNX_CLK_CTL(usb->index));
usbn_clk_ctl.s.por = 1;
usbn_clk_ctl.s.hrst = 0;
usbn_clk_ctl.s.prst = 0;
usbn_clk_ctl.s.hclk_rst = 0;
usbn_clk_ctl.s.enable = 0;
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_CLOCK_XO_GND) {
if (OCTEON_IS_MODEL(OCTEON_CN3XXX) ||
OCTEON_IS_MODEL(OCTEON_CN56XX) ||
OCTEON_IS_MODEL(OCTEON_CN50XX))
usbn_clk_ctl.s.p_rtype = 2;
else
usbn_clk_ctl.s.p_rtype = 1;
switch (usb->init_flags &
CVMX_USB_INITIALIZE_FLAGS_CLOCK_MHZ_MASK) {
case CVMX_USB_INITIALIZE_FLAGS_CLOCK_12MHZ:
usbn_clk_ctl.s.p_c_sel = 0;
break;
case CVMX_USB_INITIALIZE_FLAGS_CLOCK_24MHZ:
usbn_clk_ctl.s.p_c_sel = 1;
break;
case CVMX_USB_INITIALIZE_FLAGS_CLOCK_48MHZ:
usbn_clk_ctl.s.p_c_sel = 2;
break;
}
} else {
if (OCTEON_IS_MODEL(OCTEON_CN3XXX))
usbn_clk_ctl.s.p_rtype = 3;
else
usbn_clk_ctl.s.p_rtype = 0;
usbn_clk_ctl.s.p_c_sel = 0;
}
divisor = DIV_ROUND_UP(octeon_get_clock_rate(), 125000000);
if (divisor < 4)
divisor = 4;
usbn_clk_ctl.s.divide = divisor;
usbn_clk_ctl.s.divide2 = 0;
cvmx_write64_uint64(CVMX_USBNX_CLK_CTL(usb->index), usbn_clk_ctl.u64);
usbn_clk_ctl.s.hclk_rst = 1;
cvmx_write64_uint64(CVMX_USBNX_CLK_CTL(usb->index), usbn_clk_ctl.u64);
cvmx_wait(64);
usbn_clk_ctl.s.por = 0;
cvmx_write64_uint64(CVMX_USBNX_CLK_CTL(usb->index), usbn_clk_ctl.u64);
mdelay(1);
usbn_usbp_ctl_status.u64 =
cvmx_read64_uint64(CVMX_USBNX_USBP_CTL_STATUS(usb->index));
usbn_usbp_ctl_status.s.ate_reset = 1;
cvmx_write64_uint64(CVMX_USBNX_USBP_CTL_STATUS(usb->index),
usbn_usbp_ctl_status.u64);
cvmx_wait(10);
usbn_usbp_ctl_status.s.ate_reset = 0;
cvmx_write64_uint64(CVMX_USBNX_USBP_CTL_STATUS(usb->index),
usbn_usbp_ctl_status.u64);
usbn_clk_ctl.s.prst = 1;
cvmx_write64_uint64(CVMX_USBNX_CLK_CTL(usb->index), usbn_clk_ctl.u64);
usbn_usbp_ctl_status.s.hst_mode = 0;
cvmx_write64_uint64(CVMX_USBNX_USBP_CTL_STATUS(usb->index),
usbn_usbp_ctl_status.u64);
udelay(1);
usbn_clk_ctl.s.hrst = 1;
cvmx_write64_uint64(CVMX_USBNX_CLK_CTL(usb->index), usbn_clk_ctl.u64);
usbn_clk_ctl.s.enable = 1;
cvmx_write64_uint64(CVMX_USBNX_CLK_CTL(usb->index), usbn_clk_ctl.u64);
udelay(1);
usbcx_gahbcfg.u32 = 0;
usbcx_gahbcfg.s.dmaen = !(usb->init_flags &
CVMX_USB_INITIALIZE_FLAGS_NO_DMA);
usbcx_gahbcfg.s.hbstlen = 0;
usbcx_gahbcfg.s.nptxfemplvl = 1;
usbcx_gahbcfg.s.ptxfemplvl = 1;
usbcx_gahbcfg.s.glblintrmsk = 1;
cvmx_usb_write_csr32(usb, CVMX_USBCX_GAHBCFG(usb->index),
usbcx_gahbcfg.u32);
usbcx_gusbcfg.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_GUSBCFG(usb->index));
usbcx_gusbcfg.s.toutcal = 0;
usbcx_gusbcfg.s.ddrsel = 0;
usbcx_gusbcfg.s.usbtrdtim = 0x5;
usbcx_gusbcfg.s.phylpwrclksel = 0;
cvmx_usb_write_csr32(usb, CVMX_USBCX_GUSBCFG(usb->index),
usbcx_gusbcfg.u32);
usbcx_gintmsk.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_GINTMSK(usb->index));
usbcx_gintmsk.s.otgintmsk = 1;
usbcx_gintmsk.s.modemismsk = 1;
usbcx_gintmsk.s.hchintmsk = 1;
usbcx_gintmsk.s.sofmsk = 0;
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)
usbcx_gintmsk.s.rxflvlmsk = 1;
cvmx_usb_write_csr32(usb, CVMX_USBCX_GINTMSK(usb->index),
usbcx_gintmsk.u32);
for (channel = 0; channel < 8; channel++)
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCINTMSKX(channel, usb->index),
0);
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index),
cvmx_usbcx_gintmsk, prtintmsk, 1);
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index),
cvmx_usbcx_gintmsk, disconnintmsk, 1);
usbcx_hcfg.u32 = cvmx_usb_read_csr32(usb, CVMX_USBCX_HCFG(usb->index));
usbcx_hcfg.s.fslssupp = 0;
usbcx_hcfg.s.fslspclksel = 0;
cvmx_usb_write_csr32(usb, CVMX_USBCX_HCFG(usb->index), usbcx_hcfg.u32);
cvmx_fifo_setup(usb);
usbc_gintsts.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_GINTSTS(usb->index));
cvmx_usb_write_csr32(usb, CVMX_USBCX_GINTSTS(usb->index),
usbc_gintsts.u32);
dev_dbg(dev, "gintsts after reset: 0x%x\n", (int)usbc_gintsts.u32);
if (!usbc_gintsts.s.disconnint && !usbc_gintsts.s.prtint)
return 0;
if (retries++ >= 5)
return -EAGAIN;
dev_info(dev, "controller reset failed (gintsts=0x%x) - retrying\n",
(int)usbc_gintsts.u32);
msleep(50);
cvmx_usb_shutdown(usb);
msleep(50);
goto retry;
}
static void cvmx_usb_reset_port(struct octeon_hcd *usb)
{
usb->usbcx_hprt.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HPRT(usb->index));
USB_SET_FIELD32(CVMX_USBCX_HPRT(usb->index), cvmx_usbcx_hprt,
prtrst, 1);
mdelay(50);
USB_SET_FIELD32(CVMX_USBCX_HPRT(usb->index), cvmx_usbcx_hprt,
prtrst, 0);
usb->usbcx_hprt.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HPRT(usb->index));
}
static int cvmx_usb_disable(struct octeon_hcd *usb)
{
USB_SET_FIELD32(CVMX_USBCX_HPRT(usb->index), cvmx_usbcx_hprt,
prtena, 1);
return 0;
}
static struct cvmx_usb_port_status cvmx_usb_get_status(struct octeon_hcd *usb)
{
union cvmx_usbcx_hprt usbc_hprt;
struct cvmx_usb_port_status result;
memset(&result, 0, sizeof(result));
usbc_hprt.u32 = cvmx_usb_read_csr32(usb, CVMX_USBCX_HPRT(usb->index));
result.port_enabled = usbc_hprt.s.prtena;
result.port_over_current = usbc_hprt.s.prtovrcurract;
result.port_powered = usbc_hprt.s.prtpwr;
result.port_speed = usbc_hprt.s.prtspd;
result.connected = usbc_hprt.s.prtconnsts;
result.connect_change =
result.connected != usb->port_status.connected;
return result;
}
static struct cvmx_usb_pipe *cvmx_usb_open_pipe(struct octeon_hcd *usb,
int device_addr,
int endpoint_num,
enum cvmx_usb_speed
device_speed,
int max_packet,
enum cvmx_usb_transfer
transfer_type,
enum cvmx_usb_direction
transfer_dir,
int interval, int multi_count,
int hub_device_addr,
int hub_port)
{
struct cvmx_usb_pipe *pipe;
pipe = kzalloc(sizeof(*pipe), GFP_ATOMIC);
if (!pipe)
return NULL;
if ((device_speed == CVMX_USB_SPEED_HIGH) &&
(transfer_dir == CVMX_USB_DIRECTION_OUT) &&
(transfer_type == CVMX_USB_TRANSFER_BULK))
pipe->flags |= CVMX_USB_PIPE_FLAGS_NEED_PING;
pipe->device_addr = device_addr;
pipe->endpoint_num = endpoint_num;
pipe->device_speed = device_speed;
pipe->max_packet = max_packet;
pipe->transfer_type = transfer_type;
pipe->transfer_dir = transfer_dir;
INIT_LIST_HEAD(&pipe->transactions);
if (!interval)
interval = 1;
if (cvmx_usb_pipe_needs_split(usb, pipe)) {
pipe->interval = interval * 8;
pipe->next_tx_frame = ((usb->frame_number + 7) & ~7) +
pipe->interval;
} else {
pipe->interval = interval;
pipe->next_tx_frame = usb->frame_number + pipe->interval;
}
pipe->multi_count = multi_count;
pipe->hub_device_addr = hub_device_addr;
pipe->hub_port = hub_port;
pipe->pid_toggle = 0;
pipe->split_sc_frame = -1;
list_add_tail(&pipe->node, &usb->idle_pipes);
return pipe;
}
static void cvmx_usb_poll_rx_fifo(struct octeon_hcd *usb)
{
union cvmx_usbcx_grxstsph rx_status;
int channel;
int bytes;
u64 address;
u32 *ptr;
rx_status.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_GRXSTSPH(usb->index));
if (rx_status.s.pktsts != 2)
return;
if (!rx_status.s.bcnt)
return;
channel = rx_status.s.chnum;
bytes = rx_status.s.bcnt;
if (!bytes)
return;
address = cvmx_read64_uint64(CVMX_USBNX_DMA0_INB_CHN0(usb->index) +
channel * 8);
ptr = cvmx_phys_to_ptr(address);
cvmx_write64_uint64(CVMX_USBNX_DMA0_INB_CHN0(usb->index) + channel * 8,
address + bytes);
while (bytes > 0) {
*ptr++ = cvmx_usb_read_csr32(usb,
USB_FIFO_ADDRESS(channel, usb->index));
bytes -= 4;
}
CVMX_SYNCW;
}
static int cvmx_usb_fill_tx_hw(struct octeon_hcd *usb,
struct cvmx_usb_tx_fifo *fifo, int available)
{
while (available && (fifo->head != fifo->tail)) {
int i = fifo->tail;
const u32 *ptr = cvmx_phys_to_ptr(fifo->entry[i].address);
u64 csr_address = USB_FIFO_ADDRESS(fifo->entry[i].channel,
usb->index) ^ 4;
int words = available;
if (fifo->entry[i].size <= available) {
words = fifo->entry[i].size;
fifo->tail++;
if (fifo->tail > MAX_CHANNELS)
fifo->tail = 0;
}
available -= words;
fifo->entry[i].address += words * 4;
fifo->entry[i].size -= words;
while (words > 3) {
cvmx_write64_uint32(csr_address, *ptr++);
cvmx_write64_uint32(csr_address, *ptr++);
cvmx_write64_uint32(csr_address, *ptr++);
cvmx_read64_uint64(
CVMX_USBNX_DMA0_INB_CHN0(usb->index));
words -= 3;
}
cvmx_write64_uint32(csr_address, *ptr++);
if (--words) {
cvmx_write64_uint32(csr_address, *ptr++);
if (--words)
cvmx_write64_uint32(csr_address, *ptr++);
}
cvmx_read64_uint64(CVMX_USBNX_DMA0_INB_CHN0(usb->index));
}
return fifo->head != fifo->tail;
}
static void cvmx_usb_poll_tx_fifo(struct octeon_hcd *usb)
{
if (usb->periodic.head != usb->periodic.tail) {
union cvmx_usbcx_hptxsts tx_status;
tx_status.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HPTXSTS(usb->index));
if (cvmx_usb_fill_tx_hw(usb, &usb->periodic,
tx_status.s.ptxfspcavail))
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index),
cvmx_usbcx_gintmsk, ptxfempmsk, 1);
else
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index),
cvmx_usbcx_gintmsk, ptxfempmsk, 0);
}
if (usb->nonperiodic.head != usb->nonperiodic.tail) {
union cvmx_usbcx_gnptxsts tx_status;
tx_status.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_GNPTXSTS(usb->index));
if (cvmx_usb_fill_tx_hw(usb, &usb->nonperiodic,
tx_status.s.nptxfspcavail))
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index),
cvmx_usbcx_gintmsk, nptxfempmsk, 1);
else
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index),
cvmx_usbcx_gintmsk, nptxfempmsk, 0);
}
}
static void cvmx_usb_fill_tx_fifo(struct octeon_hcd *usb, int channel)
{
union cvmx_usbcx_hccharx hcchar;
union cvmx_usbcx_hcspltx usbc_hcsplt;
union cvmx_usbcx_hctsizx usbc_hctsiz;
struct cvmx_usb_tx_fifo *fifo;
hcchar.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCCHARX(channel, usb->index));
if (hcchar.s.epdir != CVMX_USB_DIRECTION_OUT)
return;
usbc_hcsplt.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCSPLTX(channel, usb->index));
if (usbc_hcsplt.s.spltena && usbc_hcsplt.s.compsplt)
return;
usbc_hctsiz.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCTSIZX(channel, usb->index));
if (!usbc_hctsiz.s.xfersize)
return;
if ((hcchar.s.eptype == CVMX_USB_TRANSFER_INTERRUPT) ||
(hcchar.s.eptype == CVMX_USB_TRANSFER_ISOCHRONOUS))
fifo = &usb->periodic;
else
fifo = &usb->nonperiodic;
fifo->entry[fifo->head].channel = channel;
fifo->entry[fifo->head].address =
cvmx_read64_uint64(CVMX_USBNX_DMA0_OUTB_CHN0(usb->index) +
channel * 8);
fifo->entry[fifo->head].size = (usbc_hctsiz.s.xfersize + 3) >> 2;
fifo->head++;
if (fifo->head > MAX_CHANNELS)
fifo->head = 0;
cvmx_usb_poll_tx_fifo(usb);
}
static void cvmx_usb_start_channel_control(struct octeon_hcd *usb,
int channel,
struct cvmx_usb_pipe *pipe)
{
struct usb_hcd *hcd = octeon_to_hcd(usb);
struct device *dev = hcd->self.controller;
struct cvmx_usb_transaction *transaction =
list_first_entry(&pipe->transactions, typeof(*transaction),
node);
struct usb_ctrlrequest *header =
cvmx_phys_to_ptr(transaction->control_header);
int bytes_to_transfer = transaction->buffer_length -
transaction->actual_bytes;
int packets_to_transfer;
union cvmx_usbcx_hctsizx usbc_hctsiz;
usbc_hctsiz.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCTSIZX(channel, usb->index));
switch (transaction->stage) {
case CVMX_USB_STAGE_NON_CONTROL:
case CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE:
dev_err(dev, "%s: ERROR - Non control stage\n", __func__);
break;
case CVMX_USB_STAGE_SETUP:
usbc_hctsiz.s.pid = 3;
bytes_to_transfer = sizeof(*header);
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index),
cvmx_usbcx_hccharx, epdir,
CVMX_USB_DIRECTION_OUT);
cvmx_write64_uint64(CVMX_USBNX_DMA0_OUTB_CHN0(usb->index) +
channel * 8,
transaction->control_header);
break;
case CVMX_USB_STAGE_SETUP_SPLIT_COMPLETE:
usbc_hctsiz.s.pid = 3;
bytes_to_transfer = 0;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index),
cvmx_usbcx_hccharx, epdir,
CVMX_USB_DIRECTION_OUT);
USB_SET_FIELD32(CVMX_USBCX_HCSPLTX(channel, usb->index),
cvmx_usbcx_hcspltx, compsplt, 1);
break;
case CVMX_USB_STAGE_DATA:
usbc_hctsiz.s.pid = cvmx_usb_get_data_pid(pipe);
if (cvmx_usb_pipe_needs_split(usb, pipe)) {
if (header->bRequestType & USB_DIR_IN)
bytes_to_transfer = 0;
else if (bytes_to_transfer > pipe->max_packet)
bytes_to_transfer = pipe->max_packet;
}
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index),
cvmx_usbcx_hccharx, epdir,
((header->bRequestType & USB_DIR_IN) ?
CVMX_USB_DIRECTION_IN :
CVMX_USB_DIRECTION_OUT));
break;
case CVMX_USB_STAGE_DATA_SPLIT_COMPLETE:
usbc_hctsiz.s.pid = cvmx_usb_get_data_pid(pipe);
if (!(header->bRequestType & USB_DIR_IN))
bytes_to_transfer = 0;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index),
cvmx_usbcx_hccharx, epdir,
((header->bRequestType & USB_DIR_IN) ?
CVMX_USB_DIRECTION_IN :
CVMX_USB_DIRECTION_OUT));
USB_SET_FIELD32(CVMX_USBCX_HCSPLTX(channel, usb->index),
cvmx_usbcx_hcspltx, compsplt, 1);
break;
case CVMX_USB_STAGE_STATUS:
usbc_hctsiz.s.pid = cvmx_usb_get_data_pid(pipe);
bytes_to_transfer = 0;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index),
cvmx_usbcx_hccharx, epdir,
((header->bRequestType & USB_DIR_IN) ?
CVMX_USB_DIRECTION_OUT :
CVMX_USB_DIRECTION_IN));
break;
case CVMX_USB_STAGE_STATUS_SPLIT_COMPLETE:
usbc_hctsiz.s.pid = cvmx_usb_get_data_pid(pipe);
bytes_to_transfer = 0;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index),
cvmx_usbcx_hccharx, epdir,
((header->bRequestType & USB_DIR_IN) ?
CVMX_USB_DIRECTION_OUT :
CVMX_USB_DIRECTION_IN));
USB_SET_FIELD32(CVMX_USBCX_HCSPLTX(channel, usb->index),
cvmx_usbcx_hcspltx, compsplt, 1);
break;
}
if (bytes_to_transfer > MAX_TRANSFER_BYTES) {
bytes_to_transfer = MAX_TRANSFER_BYTES / pipe->max_packet;
bytes_to_transfer *= pipe->max_packet;
}
packets_to_transfer = DIV_ROUND_UP(bytes_to_transfer,
pipe->max_packet);
if (packets_to_transfer == 0) {
packets_to_transfer = 1;
} else if ((packets_to_transfer > 1) &&
(usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)) {
packets_to_transfer = 1;
bytes_to_transfer = packets_to_transfer * pipe->max_packet;
} else if (packets_to_transfer > MAX_TRANSFER_PACKETS) {
packets_to_transfer = MAX_TRANSFER_PACKETS;
bytes_to_transfer = packets_to_transfer * pipe->max_packet;
}
usbc_hctsiz.s.xfersize = bytes_to_transfer;
usbc_hctsiz.s.pktcnt = packets_to_transfer;
cvmx_usb_write_csr32(usb, CVMX_USBCX_HCTSIZX(channel, usb->index),
usbc_hctsiz.u32);
}
static void cvmx_usb_start_channel(struct octeon_hcd *usb, int channel,
struct cvmx_usb_pipe *pipe)
{
struct cvmx_usb_transaction *transaction =
list_first_entry(&pipe->transactions, typeof(*transaction),
node);
CVMX_SYNCW;
usb->pipe_for_channel[channel] = pipe;
pipe->channel = channel;
pipe->flags |= CVMX_USB_PIPE_FLAGS_SCHEDULED;
usb->idle_hardware_channels &= ~(1 << channel);
{
union cvmx_usbcx_hcintx usbc_hcint;
union cvmx_usbcx_hcintmskx usbc_hcintmsk;
union cvmx_usbcx_haintmsk usbc_haintmsk;
usbc_hcint.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCINTX(channel, usb->index));
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCINTX(channel, usb->index),
usbc_hcint.u32);
usbc_hcintmsk.u32 = 0;
usbc_hcintmsk.s.chhltdmsk = 1;
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA) {
usbc_hcintmsk.s.datatglerrmsk = 1;
usbc_hcintmsk.s.frmovrunmsk = 1;
usbc_hcintmsk.s.bblerrmsk = 1;
usbc_hcintmsk.s.xacterrmsk = 1;
if (cvmx_usb_pipe_needs_split(usb, pipe)) {
usbc_hcintmsk.s.nyetmsk = 1;
usbc_hcintmsk.s.ackmsk = 1;
}
usbc_hcintmsk.s.nakmsk = 1;
usbc_hcintmsk.s.stallmsk = 1;
usbc_hcintmsk.s.xfercomplmsk = 1;
}
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCINTMSKX(channel, usb->index),
usbc_hcintmsk.u32);
usbc_haintmsk.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HAINTMSK(usb->index));
usbc_haintmsk.s.haintmsk |= 1 << channel;
cvmx_usb_write_csr32(usb, CVMX_USBCX_HAINTMSK(usb->index),
usbc_haintmsk.u32);
}
{
u64 reg;
u64 dma_address = transaction->buffer +
transaction->actual_bytes;
if (transaction->type == CVMX_USB_TRANSFER_ISOCHRONOUS)
dma_address = transaction->buffer +
transaction->iso_packets[0].offset +
transaction->actual_bytes;
if (pipe->transfer_dir == CVMX_USB_DIRECTION_OUT)
reg = CVMX_USBNX_DMA0_OUTB_CHN0(usb->index);
else
reg = CVMX_USBNX_DMA0_INB_CHN0(usb->index);
cvmx_write64_uint64(reg + channel * 8, dma_address);
}
{
union cvmx_usbcx_hcspltx usbc_hcsplt = {.u32 = 0};
union cvmx_usbcx_hctsizx usbc_hctsiz = {.u32 = 0};
int packets_to_transfer;
int bytes_to_transfer = transaction->buffer_length -
transaction->actual_bytes;
if (transaction->type == CVMX_USB_TRANSFER_ISOCHRONOUS)
bytes_to_transfer =
transaction->iso_packets[0].length -
transaction->actual_bytes;
if (cvmx_usb_pipe_needs_split(usb, pipe)) {
if ((transaction->stage & 1) == 0) {
if (transaction->type == CVMX_USB_TRANSFER_BULK)
pipe->split_sc_frame =
(usb->frame_number + 1) & 0x7f;
else
pipe->split_sc_frame =
(usb->frame_number + 2) & 0x7f;
} else {
pipe->split_sc_frame = -1;
}
usbc_hcsplt.s.spltena = 1;
usbc_hcsplt.s.hubaddr = pipe->hub_device_addr;
usbc_hcsplt.s.prtaddr = pipe->hub_port;
usbc_hcsplt.s.compsplt = (transaction->stage ==
CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE);
if (bytes_to_transfer > pipe->max_packet)
bytes_to_transfer = pipe->max_packet;
if (!usbc_hcsplt.s.compsplt &&
(pipe->transfer_dir == CVMX_USB_DIRECTION_OUT) &&
(pipe->transfer_type ==
CVMX_USB_TRANSFER_ISOCHRONOUS)) {
pipe->split_sc_frame = -1;
if (transaction->actual_bytes == 0) {
if (bytes_to_transfer <= 188)
usbc_hcsplt.s.xactpos = 3;
else
usbc_hcsplt.s.xactpos = 2;
} else {
if (bytes_to_transfer <= 188)
usbc_hcsplt.s.xactpos = 1;
else
usbc_hcsplt.s.xactpos = 0;
}
if (bytes_to_transfer > 188)
bytes_to_transfer = 188;
}
}
if (bytes_to_transfer > MAX_TRANSFER_BYTES) {
bytes_to_transfer = MAX_TRANSFER_BYTES /
pipe->max_packet;
bytes_to_transfer *= pipe->max_packet;
}
packets_to_transfer =
DIV_ROUND_UP(bytes_to_transfer, pipe->max_packet);
if (packets_to_transfer == 0) {
packets_to_transfer = 1;
} else if ((packets_to_transfer > 1) &&
(usb->init_flags &
CVMX_USB_INITIALIZE_FLAGS_NO_DMA)) {
packets_to_transfer = 1;
bytes_to_transfer = packets_to_transfer *
pipe->max_packet;
} else if (packets_to_transfer > MAX_TRANSFER_PACKETS) {
packets_to_transfer = MAX_TRANSFER_PACKETS;
bytes_to_transfer = packets_to_transfer *
pipe->max_packet;
}
usbc_hctsiz.s.xfersize = bytes_to_transfer;
usbc_hctsiz.s.pktcnt = packets_to_transfer;
usbc_hctsiz.s.pid = cvmx_usb_get_data_pid(pipe);
if (pipe->flags & CVMX_USB_PIPE_FLAGS_NEED_PING)
usbc_hctsiz.s.dopng = 1;
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCSPLTX(channel, usb->index),
usbc_hcsplt.u32);
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCTSIZX(channel, usb->index),
usbc_hctsiz.u32);
}
{
union cvmx_usbcx_hccharx usbc_hcchar = {.u32 = 0};
usbc_hcchar.s.oddfrm = usb->frame_number & 1;
if (cvmx_usb_pipe_needs_split(usb, pipe))
usbc_hcchar.s.ec = 1;
else if (pipe->multi_count < 1)
usbc_hcchar.s.ec = 1;
else if (pipe->multi_count > 3)
usbc_hcchar.s.ec = 3;
else
usbc_hcchar.s.ec = pipe->multi_count;
usbc_hcchar.s.devaddr = pipe->device_addr;
usbc_hcchar.s.eptype = transaction->type;
usbc_hcchar.s.lspddev =
(pipe->device_speed == CVMX_USB_SPEED_LOW);
usbc_hcchar.s.epdir = pipe->transfer_dir;
usbc_hcchar.s.epnum = pipe->endpoint_num;
usbc_hcchar.s.mps = pipe->max_packet;
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCCHARX(channel, usb->index),
usbc_hcchar.u32);
}
switch (transaction->type) {
case CVMX_USB_TRANSFER_CONTROL:
cvmx_usb_start_channel_control(usb, channel, pipe);
break;
case CVMX_USB_TRANSFER_BULK:
case CVMX_USB_TRANSFER_INTERRUPT:
break;
case CVMX_USB_TRANSFER_ISOCHRONOUS:
if (!cvmx_usb_pipe_needs_split(usb, pipe)) {
if (pipe->transfer_dir == CVMX_USB_DIRECTION_OUT) {
if (pipe->multi_count < 2)
USB_SET_FIELD32(
CVMX_USBCX_HCTSIZX(channel,
usb->index),
cvmx_usbcx_hctsizx, pid, 0);
else
USB_SET_FIELD32(
CVMX_USBCX_HCTSIZX(channel,
usb->index),
cvmx_usbcx_hctsizx, pid, 3);
}
}
break;
}
{
union cvmx_usbcx_hctsizx usbc_hctsiz = { .u32 =
cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCTSIZX(channel,
usb->index))
};
transaction->xfersize = usbc_hctsiz.s.xfersize;
transaction->pktcnt = usbc_hctsiz.s.pktcnt;
}
if (cvmx_usb_pipe_needs_split(usb, pipe))
usb->active_split = transaction;
USB_SET_FIELD32(CVMX_USBCX_HCCHARX(channel, usb->index),
cvmx_usbcx_hccharx, chena, 1);
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)
cvmx_usb_fill_tx_fifo(usb, channel);
}
static struct cvmx_usb_pipe *cvmx_usb_find_ready_pipe(
struct octeon_hcd *usb,
enum cvmx_usb_transfer xfer_type)
{
struct list_head *list = usb->active_pipes + xfer_type;
u64 current_frame = usb->frame_number;
struct cvmx_usb_pipe *pipe;
list_for_each_entry(pipe, list, node) {
struct cvmx_usb_transaction *t =
list_first_entry(&pipe->transactions, typeof(*t),
node);
if (!(pipe->flags & CVMX_USB_PIPE_FLAGS_SCHEDULED) && t &&
(pipe->next_tx_frame <= current_frame) &&
((pipe->split_sc_frame == -1) ||
((((int)current_frame - pipe->split_sc_frame) & 0x7f) <
0x40)) &&
(!usb->active_split || (usb->active_split == t))) {
prefetch(t);
return pipe;
}
}
return NULL;
}
static struct cvmx_usb_pipe *cvmx_usb_next_pipe(struct octeon_hcd *usb,
int is_sof)
{
struct cvmx_usb_pipe *pipe;
if (is_sof) {
pipe = cvmx_usb_find_ready_pipe(usb,
CVMX_USB_TRANSFER_ISOCHRONOUS);
if (pipe)
return pipe;
pipe = cvmx_usb_find_ready_pipe(usb,
CVMX_USB_TRANSFER_INTERRUPT);
if (pipe)
return pipe;
}
pipe = cvmx_usb_find_ready_pipe(usb, CVMX_USB_TRANSFER_CONTROL);
if (pipe)
return pipe;
return cvmx_usb_find_ready_pipe(usb, CVMX_USB_TRANSFER_BULK);
}
static void cvmx_usb_schedule(struct octeon_hcd *usb, int is_sof)
{
int channel;
struct cvmx_usb_pipe *pipe;
int need_sof;
enum cvmx_usb_transfer ttype;
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA) {
union cvmx_usbcx_hfnum hfnum = {
.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HFNUM(usb->index))
};
union cvmx_usbcx_hfir hfir = {
.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HFIR(usb->index))
};
if (hfnum.s.frrem < hfir.s.frint / 4)
goto done;
}
while (usb->idle_hardware_channels) {
channel = __fls(usb->idle_hardware_channels);
if (unlikely(channel > 7))
break;
pipe = cvmx_usb_next_pipe(usb, is_sof);
if (!pipe)
break;
cvmx_usb_start_channel(usb, channel, pipe);
}
done:
need_sof = 0;
for (ttype = CVMX_USB_TRANSFER_CONTROL;
ttype <= CVMX_USB_TRANSFER_INTERRUPT; ttype++) {
list_for_each_entry(pipe, &usb->active_pipes[ttype], node) {
if (pipe->next_tx_frame > usb->frame_number) {
need_sof = 1;
break;
}
}
}
USB_SET_FIELD32(CVMX_USBCX_GINTMSK(usb->index),
cvmx_usbcx_gintmsk, sofmsk, need_sof);
}
static void octeon_usb_urb_complete_callback(struct octeon_hcd *usb,
enum cvmx_usb_status status,
struct cvmx_usb_pipe *pipe,
struct cvmx_usb_transaction
*transaction,
int bytes_transferred,
struct urb *urb)
{
struct usb_hcd *hcd = octeon_to_hcd(usb);
struct device *dev = hcd->self.controller;
if (likely(status == CVMX_USB_STATUS_OK))
urb->actual_length = bytes_transferred;
else
urb->actual_length = 0;
urb->hcpriv = NULL;
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS) {
int i;
struct cvmx_usb_iso_packet *iso_packet =
(struct cvmx_usb_iso_packet *)urb->setup_packet;
urb->actual_length = 0;
for (i = 0; i < urb->number_of_packets; i++) {
if (iso_packet[i].status == CVMX_USB_STATUS_OK) {
urb->iso_frame_desc[i].status = 0;
urb->iso_frame_desc[i].actual_length =
iso_packet[i].length;
urb->actual_length +=
urb->iso_frame_desc[i].actual_length;
} else {
dev_dbg(dev, "ISOCHRONOUS packet=%d of %d status=%d pipe=%p transaction=%p size=%d\n",
i, urb->number_of_packets,
iso_packet[i].status, pipe,
transaction, iso_packet[i].length);
urb->iso_frame_desc[i].status = -EREMOTEIO;
}
}
kfree(iso_packet);
urb->setup_packet = NULL;
}
switch (status) {
case CVMX_USB_STATUS_OK:
urb->status = 0;
break;
case CVMX_USB_STATUS_CANCEL:
if (urb->status == 0)
urb->status = -ENOENT;
break;
case CVMX_USB_STATUS_STALL:
dev_dbg(dev, "status=stall pipe=%p transaction=%p size=%d\n",
pipe, transaction, bytes_transferred);
urb->status = -EPIPE;
break;
case CVMX_USB_STATUS_BABBLEERR:
dev_dbg(dev, "status=babble pipe=%p transaction=%p size=%d\n",
pipe, transaction, bytes_transferred);
urb->status = -EPIPE;
break;
case CVMX_USB_STATUS_SHORT:
dev_dbg(dev, "status=short pipe=%p transaction=%p size=%d\n",
pipe, transaction, bytes_transferred);
urb->status = -EREMOTEIO;
break;
case CVMX_USB_STATUS_ERROR:
case CVMX_USB_STATUS_XACTERR:
case CVMX_USB_STATUS_DATATGLERR:
case CVMX_USB_STATUS_FRAMEERR:
dev_dbg(dev, "status=%d pipe=%p transaction=%p size=%d\n",
status, pipe, transaction, bytes_transferred);
urb->status = -EPROTO;
break;
}
usb_hcd_unlink_urb_from_ep(octeon_to_hcd(usb), urb);
spin_unlock(&usb->lock);
usb_hcd_giveback_urb(octeon_to_hcd(usb), urb, urb->status);
spin_lock(&usb->lock);
}
static void cvmx_usb_complete(struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct cvmx_usb_transaction *transaction,
enum cvmx_usb_status complete_code)
{
if (usb->active_split == transaction)
usb->active_split = NULL;
if (unlikely(transaction->type == CVMX_USB_TRANSFER_ISOCHRONOUS)) {
transaction->iso_packets[0].length = transaction->actual_bytes;
transaction->iso_packets[0].status = complete_code;
if ((transaction->iso_number_packets > 1) &&
(complete_code == CVMX_USB_STATUS_OK)) {
transaction->actual_bytes = 0;
transaction->iso_number_packets--;
transaction->iso_packets++;
transaction->stage = CVMX_USB_STAGE_NON_CONTROL;
return;
}
}
list_del(&transaction->node);
if (list_empty(&pipe->transactions))
list_move_tail(&pipe->node, &usb->idle_pipes);
octeon_usb_urb_complete_callback(usb, complete_code, pipe,
transaction,
transaction->actual_bytes,
transaction->urb);
kfree(transaction);
}
static struct cvmx_usb_transaction *cvmx_usb_submit_transaction(
struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
enum cvmx_usb_transfer type,
u64 buffer,
int buffer_length,
u64 control_header,
int iso_start_frame,
int iso_number_packets,
struct cvmx_usb_iso_packet *iso_packets,
struct urb *urb)
{
struct cvmx_usb_transaction *transaction;
if (unlikely(pipe->transfer_type != type))
return NULL;
transaction = kzalloc(sizeof(*transaction), GFP_ATOMIC);
if (unlikely(!transaction))
return NULL;
transaction->type = type;
transaction->buffer = buffer;
transaction->buffer_length = buffer_length;
transaction->control_header = control_header;
transaction->iso_start_frame = iso_start_frame;
transaction->iso_number_packets = iso_number_packets;
transaction->iso_packets = iso_packets;
transaction->urb = urb;
if (transaction->type == CVMX_USB_TRANSFER_CONTROL)
transaction->stage = CVMX_USB_STAGE_SETUP;
else
transaction->stage = CVMX_USB_STAGE_NON_CONTROL;
if (!list_empty(&pipe->transactions)) {
list_add_tail(&transaction->node, &pipe->transactions);
} else {
list_add_tail(&transaction->node, &pipe->transactions);
list_move_tail(&pipe->node,
&usb->active_pipes[pipe->transfer_type]);
cvmx_usb_schedule(usb, 0);
}
return transaction;
}
static struct cvmx_usb_transaction *cvmx_usb_submit_bulk(
struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct urb *urb)
{
return cvmx_usb_submit_transaction(usb, pipe, CVMX_USB_TRANSFER_BULK,
urb->transfer_dma,
urb->transfer_buffer_length,
0,
0,
0,
NULL,
urb);
}
static struct cvmx_usb_transaction *cvmx_usb_submit_interrupt(
struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct urb *urb)
{
return cvmx_usb_submit_transaction(usb, pipe,
CVMX_USB_TRANSFER_INTERRUPT,
urb->transfer_dma,
urb->transfer_buffer_length,
0,
0,
0,
NULL,
urb);
}
static struct cvmx_usb_transaction *cvmx_usb_submit_control(
struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct urb *urb)
{
int buffer_length = urb->transfer_buffer_length;
u64 control_header = urb->setup_dma;
struct usb_ctrlrequest *header = cvmx_phys_to_ptr(control_header);
if ((header->bRequestType & USB_DIR_IN) == 0)
buffer_length = le16_to_cpu(header->wLength);
return cvmx_usb_submit_transaction(usb, pipe,
CVMX_USB_TRANSFER_CONTROL,
urb->transfer_dma, buffer_length,
control_header,
0,
0,
NULL,
urb);
}
static struct cvmx_usb_transaction *cvmx_usb_submit_isochronous(
struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct urb *urb)
{
struct cvmx_usb_iso_packet *packets;
packets = (struct cvmx_usb_iso_packet *)urb->setup_packet;
return cvmx_usb_submit_transaction(usb, pipe,
CVMX_USB_TRANSFER_ISOCHRONOUS,
urb->transfer_dma,
urb->transfer_buffer_length,
0,
urb->start_frame,
urb->number_of_packets,
packets, urb);
}
static int cvmx_usb_cancel(struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct cvmx_usb_transaction *transaction)
{
if (list_first_entry(&pipe->transactions, typeof(*transaction), node) ==
transaction && (pipe->flags & CVMX_USB_PIPE_FLAGS_SCHEDULED)) {
union cvmx_usbcx_hccharx usbc_hcchar;
usb->pipe_for_channel[pipe->channel] = NULL;
pipe->flags &= ~CVMX_USB_PIPE_FLAGS_SCHEDULED;
CVMX_SYNCW;
usbc_hcchar.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCCHARX(pipe->channel, usb->index));
if (usbc_hcchar.s.chena) {
usbc_hcchar.s.chdis = 1;
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCCHARX(pipe->channel,
usb->index),
usbc_hcchar.u32);
}
}
cvmx_usb_complete(usb, pipe, transaction, CVMX_USB_STATUS_CANCEL);
return 0;
}
static int cvmx_usb_cancel_all(struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe)
{
struct cvmx_usb_transaction *transaction, *next;
list_for_each_entry_safe(transaction, next, &pipe->transactions, node) {
int result = cvmx_usb_cancel(usb, pipe, transaction);
if (unlikely(result != 0))
return result;
}
return 0;
}
static int cvmx_usb_close_pipe(struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe)
{
if (!list_empty(&pipe->transactions))
return -EBUSY;
list_del(&pipe->node);
kfree(pipe);
return 0;
}
static int cvmx_usb_get_frame_number(struct octeon_hcd *usb)
{
int frame_number;
union cvmx_usbcx_hfnum usbc_hfnum;
usbc_hfnum.u32 = cvmx_usb_read_csr32(usb, CVMX_USBCX_HFNUM(usb->index));
frame_number = usbc_hfnum.s.frnum;
return frame_number;
}
static void cvmx_usb_transfer_control(struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct cvmx_usb_transaction *transaction,
union cvmx_usbcx_hccharx usbc_hcchar,
int buffer_space_left,
int bytes_in_last_packet)
{
switch (transaction->stage) {
case CVMX_USB_STAGE_NON_CONTROL:
case CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE:
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_ERROR);
break;
case CVMX_USB_STAGE_SETUP:
pipe->pid_toggle = 1;
if (cvmx_usb_pipe_needs_split(usb, pipe)) {
transaction->stage =
CVMX_USB_STAGE_SETUP_SPLIT_COMPLETE;
} else {
struct usb_ctrlrequest *header =
cvmx_phys_to_ptr(transaction->control_header);
if (header->wLength)
transaction->stage = CVMX_USB_STAGE_DATA;
else
transaction->stage = CVMX_USB_STAGE_STATUS;
}
break;
case CVMX_USB_STAGE_SETUP_SPLIT_COMPLETE:
{
struct usb_ctrlrequest *header =
cvmx_phys_to_ptr(transaction->control_header);
if (header->wLength)
transaction->stage = CVMX_USB_STAGE_DATA;
else
transaction->stage = CVMX_USB_STAGE_STATUS;
}
break;
case CVMX_USB_STAGE_DATA:
if (cvmx_usb_pipe_needs_split(usb, pipe)) {
transaction->stage = CVMX_USB_STAGE_DATA_SPLIT_COMPLETE;
if (!usbc_hcchar.s.epdir) {
if (buffer_space_left < pipe->max_packet)
transaction->actual_bytes +=
buffer_space_left;
else
transaction->actual_bytes +=
pipe->max_packet;
}
} else if ((buffer_space_left == 0) ||
(bytes_in_last_packet < pipe->max_packet)) {
pipe->pid_toggle = 1;
transaction->stage = CVMX_USB_STAGE_STATUS;
}
break;
case CVMX_USB_STAGE_DATA_SPLIT_COMPLETE:
if ((buffer_space_left == 0) ||
(bytes_in_last_packet < pipe->max_packet)) {
pipe->pid_toggle = 1;
transaction->stage = CVMX_USB_STAGE_STATUS;
} else {
transaction->stage = CVMX_USB_STAGE_DATA;
}
break;
case CVMX_USB_STAGE_STATUS:
if (cvmx_usb_pipe_needs_split(usb, pipe))
transaction->stage =
CVMX_USB_STAGE_STATUS_SPLIT_COMPLETE;
else
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_OK);
break;
case CVMX_USB_STAGE_STATUS_SPLIT_COMPLETE:
cvmx_usb_complete(usb, pipe, transaction, CVMX_USB_STATUS_OK);
break;
}
}
static void cvmx_usb_transfer_bulk(struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct cvmx_usb_transaction *transaction,
union cvmx_usbcx_hcintx usbc_hcint,
int buffer_space_left,
int bytes_in_last_packet)
{
if (cvmx_usb_pipe_needs_split(usb, pipe)) {
if (transaction->stage == CVMX_USB_STAGE_NON_CONTROL)
transaction->stage =
CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE;
else if (buffer_space_left &&
(bytes_in_last_packet == pipe->max_packet))
transaction->stage = CVMX_USB_STAGE_NON_CONTROL;
else
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_OK);
} else {
if ((pipe->device_speed == CVMX_USB_SPEED_HIGH) &&
(pipe->transfer_dir == CVMX_USB_DIRECTION_OUT) &&
(usbc_hcint.s.nak))
pipe->flags |= CVMX_USB_PIPE_FLAGS_NEED_PING;
if (!buffer_space_left ||
(bytes_in_last_packet < pipe->max_packet))
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_OK);
}
}
static void cvmx_usb_transfer_intr(struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct cvmx_usb_transaction *transaction,
int buffer_space_left,
int bytes_in_last_packet)
{
if (cvmx_usb_pipe_needs_split(usb, pipe)) {
if (transaction->stage == CVMX_USB_STAGE_NON_CONTROL) {
transaction->stage =
CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE;
} else if (buffer_space_left &&
(bytes_in_last_packet == pipe->max_packet)) {
transaction->stage = CVMX_USB_STAGE_NON_CONTROL;
} else {
pipe->next_tx_frame += pipe->interval;
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_OK);
}
} else if (!buffer_space_left ||
(bytes_in_last_packet < pipe->max_packet)) {
pipe->next_tx_frame += pipe->interval;
cvmx_usb_complete(usb, pipe, transaction, CVMX_USB_STATUS_OK);
}
}
static void cvmx_usb_transfer_isoc(struct octeon_hcd *usb,
struct cvmx_usb_pipe *pipe,
struct cvmx_usb_transaction *transaction,
int buffer_space_left,
int bytes_in_last_packet,
int bytes_this_transfer)
{
if (cvmx_usb_pipe_needs_split(usb, pipe)) {
if (pipe->transfer_dir == CVMX_USB_DIRECTION_OUT) {
if (!buffer_space_left || (bytes_this_transfer < 188)) {
pipe->next_tx_frame += pipe->interval;
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_OK);
}
return;
}
if (transaction->stage ==
CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE) {
if ((buffer_space_left == 0) ||
(bytes_in_last_packet < pipe->max_packet)) {
pipe->next_tx_frame += pipe->interval;
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_OK);
}
} else {
transaction->stage =
CVMX_USB_STAGE_NON_CONTROL_SPLIT_COMPLETE;
}
} else {
pipe->next_tx_frame += pipe->interval;
cvmx_usb_complete(usb, pipe, transaction, CVMX_USB_STATUS_OK);
}
}
static int cvmx_usb_poll_channel(struct octeon_hcd *usb, int channel)
{
struct usb_hcd *hcd = octeon_to_hcd(usb);
struct device *dev = hcd->self.controller;
union cvmx_usbcx_hcintx usbc_hcint;
union cvmx_usbcx_hctsizx usbc_hctsiz;
union cvmx_usbcx_hccharx usbc_hcchar;
struct cvmx_usb_pipe *pipe;
struct cvmx_usb_transaction *transaction;
int bytes_this_transfer;
int bytes_in_last_packet;
int packets_processed;
int buffer_space_left;
usbc_hcint.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCINTX(channel, usb->index));
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA) {
usbc_hcchar.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCCHARX(channel, usb->index));
if (usbc_hcchar.s.chena && usbc_hcchar.s.chdis) {
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCCHARX(channel,
usb->index),
usbc_hcchar.u32);
return 0;
}
if (!usbc_hcint.s.chhltd) {
if (usbc_hcchar.s.chena) {
union cvmx_usbcx_hcintmskx hcintmsk;
hcintmsk.u32 = 0;
hcintmsk.s.chhltdmsk = 1;
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCINTMSKX(channel, usb->index),
hcintmsk.u32);
usbc_hcchar.s.chdis = 1;
cvmx_usb_write_csr32(usb,
CVMX_USBCX_HCCHARX(channel, usb->index),
usbc_hcchar.u32);
return 0;
} else if (usbc_hcint.s.xfercompl) {
} else {
dev_err(dev, "USB%d: Channel %d interrupt without halt\n",
usb->index, channel);
return 0;
}
}
} else {
if (!usbc_hcint.s.chhltd)
return 0;
}
cvmx_usb_write_csr32(usb, CVMX_USBCX_HCINTMSKX(channel, usb->index), 0);
usb->idle_hardware_channels |= (1 << channel);
pipe = usb->pipe_for_channel[channel];
prefetch(pipe);
if (!pipe)
return 0;
transaction = list_first_entry(&pipe->transactions,
typeof(*transaction),
node);
prefetch(transaction);
usb->pipe_for_channel[channel] = NULL;
pipe->flags &= ~CVMX_USB_PIPE_FLAGS_SCHEDULED;
usbc_hcchar.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCCHARX(channel, usb->index));
usbc_hctsiz.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HCTSIZX(channel, usb->index));
packets_processed = transaction->pktcnt - usbc_hctsiz.s.pktcnt;
if (usbc_hcchar.s.epdir) {
bytes_this_transfer = transaction->xfersize -
usbc_hctsiz.s.xfersize;
} else {
bytes_this_transfer = packets_processed * usbc_hcchar.s.mps;
if (bytes_this_transfer > transaction->xfersize)
bytes_this_transfer = transaction->xfersize;
}
if (packets_processed)
bytes_in_last_packet = bytes_this_transfer -
(packets_processed - 1) * usbc_hcchar.s.mps;
else
bytes_in_last_packet = bytes_this_transfer;
if ((transaction->stage == CVMX_USB_STAGE_SETUP) ||
(transaction->stage == CVMX_USB_STAGE_SETUP_SPLIT_COMPLETE))
bytes_this_transfer = 0;
transaction->actual_bytes += bytes_this_transfer;
if (transaction->type == CVMX_USB_TRANSFER_ISOCHRONOUS)
buffer_space_left = transaction->iso_packets[0].length -
transaction->actual_bytes;
else
buffer_space_left = transaction->buffer_length -
transaction->actual_bytes;
pipe->pid_toggle = !(usbc_hctsiz.s.pid == 0);
if ((pipe->device_speed == CVMX_USB_SPEED_HIGH) &&
(pipe->transfer_type == CVMX_USB_TRANSFER_BULK) &&
(pipe->transfer_dir == CVMX_USB_DIRECTION_OUT))
pipe->flags |= CVMX_USB_PIPE_FLAGS_NEED_PING;
if (unlikely(WARN_ON_ONCE(bytes_this_transfer < 0))) {
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_ERROR);
return 0;
}
if (usbc_hcint.s.stall) {
pipe->pid_toggle = 0;
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_STALL);
} else if (usbc_hcint.s.xacterr) {
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_XACTERR);
} else if (usbc_hcint.s.bblerr) {
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_BABBLEERR);
} else if (usbc_hcint.s.datatglerr) {
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_DATATGLERR);
} else if (usbc_hcint.s.nyet) {
if (!cvmx_usb_pipe_needs_split(usb, pipe)) {
transaction->retries = 0;
if ((buffer_space_left == 0) ||
(bytes_in_last_packet < pipe->max_packet))
cvmx_usb_complete(usb, pipe,
transaction,
CVMX_USB_STATUS_OK);
} else {
transaction->retries++;
if ((transaction->retries & 0x3) == 0) {
transaction->stage &= ~1;
pipe->split_sc_frame = -1;
}
}
} else if (usbc_hcint.s.ack) {
transaction->retries = 0;
pipe->flags &= ~CVMX_USB_PIPE_FLAGS_NEED_PING;
switch (transaction->type) {
case CVMX_USB_TRANSFER_CONTROL:
cvmx_usb_transfer_control(usb, pipe, transaction,
usbc_hcchar,
buffer_space_left,
bytes_in_last_packet);
break;
case CVMX_USB_TRANSFER_BULK:
cvmx_usb_transfer_bulk(usb, pipe, transaction,
usbc_hcint, buffer_space_left,
bytes_in_last_packet);
break;
case CVMX_USB_TRANSFER_INTERRUPT:
cvmx_usb_transfer_intr(usb, pipe, transaction,
buffer_space_left,
bytes_in_last_packet);
break;
case CVMX_USB_TRANSFER_ISOCHRONOUS:
cvmx_usb_transfer_isoc(usb, pipe, transaction,
buffer_space_left,
bytes_in_last_packet,
bytes_this_transfer);
break;
}
} else if (usbc_hcint.s.nak) {
if (usb->active_split == transaction)
usb->active_split = NULL;
transaction->retries = 0;
transaction->stage &= ~1;
pipe->next_tx_frame += pipe->interval;
if (pipe->next_tx_frame < usb->frame_number)
pipe->next_tx_frame = usb->frame_number +
pipe->interval -
(usb->frame_number - pipe->next_tx_frame) %
pipe->interval;
} else {
struct cvmx_usb_port_status port;
port = cvmx_usb_get_status(usb);
if (port.port_enabled) {
transaction->retries++;
} else {
cvmx_usb_complete(usb, pipe, transaction,
CVMX_USB_STATUS_ERROR);
}
}
return 0;
}
static void octeon_usb_port_callback(struct octeon_hcd *usb)
{
spin_unlock(&usb->lock);
usb_hcd_poll_rh_status(octeon_to_hcd(usb));
spin_lock(&usb->lock);
}
static int cvmx_usb_poll(struct octeon_hcd *usb)
{
union cvmx_usbcx_hfnum usbc_hfnum;
union cvmx_usbcx_gintsts usbc_gintsts;
prefetch_range(usb, sizeof(*usb));
usbc_hfnum.u32 = cvmx_usb_read_csr32(usb, CVMX_USBCX_HFNUM(usb->index));
if ((usb->frame_number & 0x3fff) > usbc_hfnum.s.frnum)
usb->frame_number += 0x4000;
usb->frame_number &= ~0x3fffull;
usb->frame_number |= usbc_hfnum.s.frnum;
usbc_gintsts.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_GINTSTS(usb->index));
cvmx_usb_write_csr32(usb, CVMX_USBCX_GINTSTS(usb->index),
usbc_gintsts.u32);
if (usbc_gintsts.s.rxflvl) {
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)
cvmx_usb_poll_rx_fifo(usb);
}
if (usbc_gintsts.s.ptxfemp || usbc_gintsts.s.nptxfemp) {
if (usb->init_flags & CVMX_USB_INITIALIZE_FLAGS_NO_DMA)
cvmx_usb_poll_tx_fifo(usb);
}
if (usbc_gintsts.s.disconnint || usbc_gintsts.s.prtint) {
union cvmx_usbcx_hprt usbc_hprt;
octeon_usb_port_callback(usb);
usbc_hprt.u32 =
cvmx_usb_read_csr32(usb, CVMX_USBCX_HPRT(usb->index));
usbc_hprt.s.prtena = 0;
cvmx_usb_write_csr32(usb, CVMX_USBCX_HPRT(usb->index),
usbc_hprt.u32);
}
if (usbc_gintsts.s.hchint) {
union cvmx_usbcx_haint usbc_haint;
usbc_haint.u32 = cvmx_usb_read_csr32(usb,
CVMX_USBCX_HAINT(usb->index));
while (usbc_haint.u32) {
int channel;
channel = __fls(usbc_haint.u32);
cvmx_usb_poll_channel(usb, channel);
usbc_haint.u32 ^= 1 << channel;
}
}
cvmx_usb_schedule(usb, usbc_gintsts.s.sof);
return 0;
}
static inline struct octeon_hcd *hcd_to_octeon(struct usb_hcd *hcd)
{
return (struct octeon_hcd *)(hcd->hcd_priv);
}
static irqreturn_t octeon_usb_irq(struct usb_hcd *hcd)
{
struct octeon_hcd *usb = hcd_to_octeon(hcd);
unsigned long flags;
spin_lock_irqsave(&usb->lock, flags);
cvmx_usb_poll(usb);
spin_unlock_irqrestore(&usb->lock, flags);
return IRQ_HANDLED;
}
static int octeon_usb_start(struct usb_hcd *hcd)
{
hcd->state = HC_STATE_RUNNING;
return 0;
}
static void octeon_usb_stop(struct usb_hcd *hcd)
{
hcd->state = HC_STATE_HALT;
}
static int octeon_usb_get_frame_number(struct usb_hcd *hcd)
{
struct octeon_hcd *usb = hcd_to_octeon(hcd);
return cvmx_usb_get_frame_number(usb);
}
static int octeon_usb_urb_enqueue(struct usb_hcd *hcd,
struct urb *urb,
gfp_t mem_flags)
{
struct octeon_hcd *usb = hcd_to_octeon(hcd);
struct device *dev = hcd->self.controller;
struct cvmx_usb_transaction *transaction = NULL;
struct cvmx_usb_pipe *pipe;
unsigned long flags;
struct cvmx_usb_iso_packet *iso_packet;
struct usb_host_endpoint *ep = urb->ep;
int rc;
urb->status = 0;
spin_lock_irqsave(&usb->lock, flags);
rc = usb_hcd_link_urb_to_ep(hcd, urb);
if (rc) {
spin_unlock_irqrestore(&usb->lock, flags);
return rc;
}
if (!ep->hcpriv) {
enum cvmx_usb_transfer transfer_type;
enum cvmx_usb_speed speed;
int split_device = 0;
int split_port = 0;
switch (usb_pipetype(urb->pipe)) {
case PIPE_ISOCHRONOUS:
transfer_type = CVMX_USB_TRANSFER_ISOCHRONOUS;
break;
case PIPE_INTERRUPT:
transfer_type = CVMX_USB_TRANSFER_INTERRUPT;
break;
case PIPE_CONTROL:
transfer_type = CVMX_USB_TRANSFER_CONTROL;
break;
default:
transfer_type = CVMX_USB_TRANSFER_BULK;
break;
}
switch (urb->dev->speed) {
case USB_SPEED_LOW:
speed = CVMX_USB_SPEED_LOW;
break;
case USB_SPEED_FULL:
speed = CVMX_USB_SPEED_FULL;
break;
default:
speed = CVMX_USB_SPEED_HIGH;
break;
}
if (speed != CVMX_USB_SPEED_HIGH) {
struct usb_device *dev = urb->dev;
while (dev->parent) {
if (dev->parent->speed == USB_SPEED_HIGH) {
split_device = dev->parent->devnum;
split_port = dev->portnum;
break;
}
dev = dev->parent;
}
}
pipe = cvmx_usb_open_pipe(usb, usb_pipedevice(urb->pipe),
usb_pipeendpoint(urb->pipe), speed,
le16_to_cpu(ep->desc.wMaxPacketSize)
& 0x7ff,
transfer_type,
usb_pipein(urb->pipe) ?
CVMX_USB_DIRECTION_IN :
CVMX_USB_DIRECTION_OUT,
urb->interval,
(le16_to_cpu(ep->desc.wMaxPacketSize)
>> 11) & 0x3,
split_device, split_port);
if (!pipe) {
usb_hcd_unlink_urb_from_ep(hcd, urb);
spin_unlock_irqrestore(&usb->lock, flags);
dev_dbg(dev, "Failed to create pipe\n");
return -ENOMEM;
}
ep->hcpriv = pipe;
} else {
pipe = ep->hcpriv;
}
switch (usb_pipetype(urb->pipe)) {
case PIPE_ISOCHRONOUS:
dev_dbg(dev, "Submit isochronous to %d.%d\n",
usb_pipedevice(urb->pipe),
usb_pipeendpoint(urb->pipe));
iso_packet = kmalloc_array(urb->number_of_packets,
sizeof(struct cvmx_usb_iso_packet),
GFP_ATOMIC);
if (iso_packet) {
int i;
for (i = 0; i < urb->number_of_packets; i++) {
iso_packet[i].offset =
urb->iso_frame_desc[i].offset;
iso_packet[i].length =
urb->iso_frame_desc[i].length;
iso_packet[i].status = CVMX_USB_STATUS_ERROR;
}
urb->setup_packet = (char *)iso_packet;
transaction = cvmx_usb_submit_isochronous(usb,
pipe, urb);
if (!transaction) {
urb->setup_packet = NULL;
kfree(iso_packet);
}
}
break;
case PIPE_INTERRUPT:
dev_dbg(dev, "Submit interrupt to %d.%d\n",
usb_pipedevice(urb->pipe),
usb_pipeendpoint(urb->pipe));
transaction = cvmx_usb_submit_interrupt(usb, pipe, urb);
break;
case PIPE_CONTROL:
dev_dbg(dev, "Submit control to %d.%d\n",
usb_pipedevice(urb->pipe),
usb_pipeendpoint(urb->pipe));
transaction = cvmx_usb_submit_control(usb, pipe, urb);
break;
case PIPE_BULK:
dev_dbg(dev, "Submit bulk to %d.%d\n",
usb_pipedevice(urb->pipe),
usb_pipeendpoint(urb->pipe));
transaction = cvmx_usb_submit_bulk(usb, pipe, urb);
break;
}
if (!transaction) {
usb_hcd_unlink_urb_from_ep(hcd, urb);
spin_unlock_irqrestore(&usb->lock, flags);
dev_dbg(dev, "Failed to submit\n");
return -ENOMEM;
}
urb->hcpriv = transaction;
spin_unlock_irqrestore(&usb->lock, flags);
return 0;
}
static int octeon_usb_urb_dequeue(struct usb_hcd *hcd,
struct urb *urb,
int status)
{
struct octeon_hcd *usb = hcd_to_octeon(hcd);
unsigned long flags;
int rc;
if (!urb->dev)
return -EINVAL;
spin_lock_irqsave(&usb->lock, flags);
rc = usb_hcd_check_unlink_urb(hcd, urb, status);
if (rc)
goto out;
urb->status = status;
cvmx_usb_cancel(usb, urb->ep->hcpriv, urb->hcpriv);
out:
spin_unlock_irqrestore(&usb->lock, flags);
return rc;
}
static void octeon_usb_endpoint_disable(struct usb_hcd *hcd,
struct usb_host_endpoint *ep)
{
struct device *dev = hcd->self.controller;
if (ep->hcpriv) {
struct octeon_hcd *usb = hcd_to_octeon(hcd);
struct cvmx_usb_pipe *pipe = ep->hcpriv;
unsigned long flags;
spin_lock_irqsave(&usb->lock, flags);
cvmx_usb_cancel_all(usb, pipe);
if (cvmx_usb_close_pipe(usb, pipe))
dev_dbg(dev, "Closing pipe %p failed\n", pipe);
spin_unlock_irqrestore(&usb->lock, flags);
ep->hcpriv = NULL;
}
}
static int octeon_usb_hub_status_data(struct usb_hcd *hcd, char *buf)
{
struct octeon_hcd *usb = hcd_to_octeon(hcd);
struct cvmx_usb_port_status port_status;
unsigned long flags;
spin_lock_irqsave(&usb->lock, flags);
port_status = cvmx_usb_get_status(usb);
spin_unlock_irqrestore(&usb->lock, flags);
buf[0] = port_status.connect_change << 1;
return buf[0] != 0;
}
static int octeon_usb_hub_control(struct usb_hcd *hcd, u16 typeReq, u16 wValue,
u16 wIndex, char *buf, u16 wLength)
{
struct octeon_hcd *usb = hcd_to_octeon(hcd);
struct device *dev = hcd->self.controller;
struct cvmx_usb_port_status usb_port_status;
int port_status;
struct usb_hub_descriptor *desc;
unsigned long flags;
switch (typeReq) {
case ClearHubFeature:
dev_dbg(dev, "ClearHubFeature\n");
switch (wValue) {
case C_HUB_LOCAL_POWER:
case C_HUB_OVER_CURRENT:
break;
default:
return -EINVAL;
}
break;
case ClearPortFeature:
dev_dbg(dev, "ClearPortFeature\n");
if (wIndex != 1) {
dev_dbg(dev, " INVALID\n");
return -EINVAL;
}
switch (wValue) {
case USB_PORT_FEAT_ENABLE:
dev_dbg(dev, " ENABLE\n");
spin_lock_irqsave(&usb->lock, flags);
cvmx_usb_disable(usb);
spin_unlock_irqrestore(&usb->lock, flags);
break;
case USB_PORT_FEAT_SUSPEND:
dev_dbg(dev, " SUSPEND\n");
break;
case USB_PORT_FEAT_POWER:
dev_dbg(dev, " POWER\n");
break;
case USB_PORT_FEAT_INDICATOR:
dev_dbg(dev, " INDICATOR\n");
break;
case USB_PORT_FEAT_C_CONNECTION:
dev_dbg(dev, " C_CONNECTION\n");
spin_lock_irqsave(&usb->lock, flags);
usb->port_status = cvmx_usb_get_status(usb);
spin_unlock_irqrestore(&usb->lock, flags);
break;
case USB_PORT_FEAT_C_RESET:
dev_dbg(dev, " C_RESET\n");
spin_lock_irqsave(&usb->lock, flags);
usb->port_status = cvmx_usb_get_status(usb);
spin_unlock_irqrestore(&usb->lock, flags);
break;
case USB_PORT_FEAT_C_ENABLE:
dev_dbg(dev, " C_ENABLE\n");
spin_lock_irqsave(&usb->lock, flags);
usb->port_status = cvmx_usb_get_status(usb);
spin_unlock_irqrestore(&usb->lock, flags);
break;
case USB_PORT_FEAT_C_SUSPEND:
dev_dbg(dev, " C_SUSPEND\n");
break;
case USB_PORT_FEAT_C_OVER_CURRENT:
dev_dbg(dev, " C_OVER_CURRENT\n");
spin_lock_irqsave(&usb->lock, flags);
usb->port_status = cvmx_usb_get_status(usb);
spin_unlock_irqrestore(&usb->lock, flags);
break;
default:
dev_dbg(dev, " UNKNOWN\n");
return -EINVAL;
}
break;
case GetHubDescriptor:
dev_dbg(dev, "GetHubDescriptor\n");
desc = (struct usb_hub_descriptor *)buf;
desc->bDescLength = 9;
desc->bDescriptorType = 0x29;
desc->bNbrPorts = 1;
desc->wHubCharacteristics = cpu_to_le16(0x08);
desc->bPwrOn2PwrGood = 1;
desc->bHubContrCurrent = 0;
desc->u.hs.DeviceRemovable[0] = 0;
desc->u.hs.DeviceRemovable[1] = 0xff;
break;
case GetHubStatus:
dev_dbg(dev, "GetHubStatus\n");
*(__le32 *)buf = 0;
break;
case GetPortStatus:
dev_dbg(dev, "GetPortStatus\n");
if (wIndex != 1) {
dev_dbg(dev, " INVALID\n");
return -EINVAL;
}
spin_lock_irqsave(&usb->lock, flags);
usb_port_status = cvmx_usb_get_status(usb);
spin_unlock_irqrestore(&usb->lock, flags);
port_status = 0;
if (usb_port_status.connect_change) {
port_status |= (1 << USB_PORT_FEAT_C_CONNECTION);
dev_dbg(dev, " C_CONNECTION\n");
}
if (usb_port_status.port_enabled) {
port_status |= (1 << USB_PORT_FEAT_C_ENABLE);
dev_dbg(dev, " C_ENABLE\n");
}
if (usb_port_status.connected) {
port_status |= (1 << USB_PORT_FEAT_CONNECTION);
dev_dbg(dev, " CONNECTION\n");
}
if (usb_port_status.port_enabled) {
port_status |= (1 << USB_PORT_FEAT_ENABLE);
dev_dbg(dev, " ENABLE\n");
}
if (usb_port_status.port_over_current) {
port_status |= (1 << USB_PORT_FEAT_OVER_CURRENT);
dev_dbg(dev, " OVER_CURRENT\n");
}
if (usb_port_status.port_powered) {
port_status |= (1 << USB_PORT_FEAT_POWER);
dev_dbg(dev, " POWER\n");
}
if (usb_port_status.port_speed == CVMX_USB_SPEED_HIGH) {
port_status |= USB_PORT_STAT_HIGH_SPEED;
dev_dbg(dev, " HIGHSPEED\n");
} else if (usb_port_status.port_speed == CVMX_USB_SPEED_LOW) {
port_status |= (1 << USB_PORT_FEAT_LOWSPEED);
dev_dbg(dev, " LOWSPEED\n");
}
*((__le32 *)buf) = cpu_to_le32(port_status);
break;
case SetHubFeature:
dev_dbg(dev, "SetHubFeature\n");
break;
case SetPortFeature:
dev_dbg(dev, "SetPortFeature\n");
if (wIndex != 1) {
dev_dbg(dev, " INVALID\n");
return -EINVAL;
}
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
dev_dbg(dev, " SUSPEND\n");
return -EINVAL;
case USB_PORT_FEAT_POWER:
dev_dbg(dev, " POWER\n");
spin_lock_irqsave(&usb->lock, flags);
USB_SET_FIELD32(CVMX_USBCX_HPRT(usb->index),
cvmx_usbcx_hprt, prtpwr, 1);
spin_unlock_irqrestore(&usb->lock, flags);
return 0;
case USB_PORT_FEAT_RESET:
dev_dbg(dev, " RESET\n");
spin_lock_irqsave(&usb->lock, flags);
cvmx_usb_reset_port(usb);
spin_unlock_irqrestore(&usb->lock, flags);
return 0;
case USB_PORT_FEAT_INDICATOR:
dev_dbg(dev, " INDICATOR\n");
break;
default:
dev_dbg(dev, " UNKNOWN\n");
return -EINVAL;
}
break;
default:
dev_dbg(dev, "Unknown root hub request\n");
return -EINVAL;
}
return 0;
}
static int octeon_usb_probe(struct platform_device *pdev)
{
int status;
int initialize_flags;
int usb_num;
struct resource *res_mem;
struct device_node *usbn_node;
int irq = platform_get_irq(pdev, 0);
struct device *dev = &pdev->dev;
struct octeon_hcd *usb;
struct usb_hcd *hcd;
u32 clock_rate = 48000000;
bool is_crystal_clock = false;
const char *clock_type;
int i;
if (!dev->of_node) {
dev_err(dev, "Error: empty of_node\n");
return -ENXIO;
}
usbn_node = dev->of_node->parent;
i = of_property_read_u32(usbn_node,
"clock-frequency", &clock_rate);
if (i)
i = of_property_read_u32(usbn_node,
"refclk-frequency", &clock_rate);
if (i) {
dev_err(dev, "No USBN \"clock-frequency\"\n");
return -ENXIO;
}
switch (clock_rate) {
case 12000000:
initialize_flags = CVMX_USB_INITIALIZE_FLAGS_CLOCK_12MHZ;
break;
case 24000000:
initialize_flags = CVMX_USB_INITIALIZE_FLAGS_CLOCK_24MHZ;
break;
case 48000000:
initialize_flags = CVMX_USB_INITIALIZE_FLAGS_CLOCK_48MHZ;
break;
default:
dev_err(dev, "Illegal USBN \"clock-frequency\" %u\n",
clock_rate);
return -ENXIO;
}
i = of_property_read_string(usbn_node,
"cavium,refclk-type", &clock_type);
if (i)
i = of_property_read_string(usbn_node,
"refclk-type", &clock_type);
if (!i && strcmp("crystal", clock_type) == 0)
is_crystal_clock = true;
if (is_crystal_clock)
initialize_flags |= CVMX_USB_INITIALIZE_FLAGS_CLOCK_XO_XI;
else
initialize_flags |= CVMX_USB_INITIALIZE_FLAGS_CLOCK_XO_GND;
res_mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res_mem) {
dev_err(dev, "found no memory resource\n");
return -ENXIO;
}
usb_num = (res_mem->start >> 44) & 1;
if (irq < 0) {
irq_hw_number_t hwirq = usb_num ? (1 << 6) + 17 : 56;
irq = irq_create_mapping(NULL, hwirq);
}
dev->coherent_dma_mask = ~0;
dev->dma_mask = &dev->coherent_dma_mask;
if (OCTEON_IS_MODEL(OCTEON_CN52XX) || OCTEON_IS_MODEL(OCTEON_CN56XX)) {
union cvmx_iob_n2c_l2c_pri_cnt pri_cnt;
pri_cnt.u64 = 0;
pri_cnt.s.cnt_enb = 1;
pri_cnt.s.cnt_val = 400;
cvmx_write_csr(CVMX_IOB_N2C_L2C_PRI_CNT, pri_cnt.u64);
}
hcd = usb_create_hcd(&octeon_hc_driver, dev, dev_name(dev));
if (!hcd) {
dev_dbg(dev, "Failed to allocate memory for HCD\n");
return -1;
}
hcd->uses_new_polling = 1;
usb = (struct octeon_hcd *)hcd->hcd_priv;
spin_lock_init(&usb->lock);
usb->init_flags = initialize_flags;
usb->index = usb_num;
INIT_LIST_HEAD(&usb->idle_pipes);
for (i = 0; i < ARRAY_SIZE(usb->active_pipes); i++)
INIT_LIST_HEAD(&usb->active_pipes[i]);
if (OCTEON_IS_MODEL(OCTEON_CN31XX)) {
usb->init_flags |= CVMX_USB_INITIALIZE_FLAGS_NO_DMA;
usb->idle_hardware_channels = 0x1;
} else if (OCTEON_IS_MODEL(OCTEON_CN5XXX)) {
usb->idle_hardware_channels = 0xf7;
} else {
usb->idle_hardware_channels = 0xff;
}
status = cvmx_usb_initialize(dev, usb);
if (status) {
dev_dbg(dev, "USB initialization failed with %d\n", status);
usb_put_hcd(hcd);
return -1;
}
status = usb_add_hcd(hcd, irq, 0);
if (status) {
dev_dbg(dev, "USB add HCD failed with %d\n", status);
usb_put_hcd(hcd);
return -1;
}
device_wakeup_enable(hcd->self.controller);
dev_info(dev, "Registered HCD for port %d on irq %d\n", usb_num, irq);
return 0;
}
static int octeon_usb_remove(struct platform_device *pdev)
{
int status;
struct device *dev = &pdev->dev;
struct usb_hcd *hcd = dev_get_drvdata(dev);
struct octeon_hcd *usb = hcd_to_octeon(hcd);
unsigned long flags;
usb_remove_hcd(hcd);
spin_lock_irqsave(&usb->lock, flags);
status = cvmx_usb_shutdown(usb);
spin_unlock_irqrestore(&usb->lock, flags);
if (status)
dev_dbg(dev, "USB shutdown failed with %d\n", status);
usb_put_hcd(hcd);
return 0;
}
static int __init octeon_usb_driver_init(void)
{
if (usb_disabled())
return 0;
return platform_driver_register(&octeon_usb_driver);
}
static void __exit octeon_usb_driver_exit(void)
{
if (usb_disabled())
return;
platform_driver_unregister(&octeon_usb_driver);
}
