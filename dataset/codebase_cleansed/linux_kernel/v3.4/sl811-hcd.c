static void port_power(struct sl811 *sl811, int is_on)
{
struct usb_hcd *hcd = sl811_to_hcd(sl811);
if (is_on) {
if (sl811->port1 & USB_PORT_STAT_POWER)
return;
sl811->port1 = USB_PORT_STAT_POWER;
sl811->irq_enable = SL11H_INTMASK_INSRMV;
} else {
sl811->port1 = 0;
sl811->irq_enable = 0;
hcd->state = HC_STATE_HALT;
}
sl811->ctrl1 = 0;
sl811_write(sl811, SL11H_IRQ_ENABLE, 0);
sl811_write(sl811, SL11H_IRQ_STATUS, ~0);
if (sl811->board && sl811->board->port_power) {
DBG("power %s\n", is_on ? "on" : "off");
sl811->board->port_power(hcd->self.controller, is_on);
}
if (sl811->board && sl811->board->reset)
sl811->board->reset(hcd->self.controller);
else {
sl811_write(sl811, SL11H_CTLREG1, SL11H_CTL1MASK_SE0);
mdelay(20);
}
sl811_write(sl811, SL11H_IRQ_ENABLE, 0);
sl811_write(sl811, SL11H_CTLREG1, sl811->ctrl1);
sl811_write(sl811, SL811HS_CTLREG2, SL811HS_CTL2_INIT);
sl811_write(sl811, SL11H_IRQ_ENABLE, sl811->irq_enable);
}
static void setup_packet(
struct sl811 *sl811,
struct sl811h_ep *ep,
struct urb *urb,
u8 bank,
u8 control
)
{
u8 addr;
u8 len;
void __iomem *data_reg;
addr = SL811HS_PACKET_BUF(bank == 0);
len = sizeof(struct usb_ctrlrequest);
data_reg = sl811->data_reg;
sl811_write_buf(sl811, addr, urb->setup_packet, len);
sl811_write(sl811, bank + SL11H_BUFADDRREG, addr);
writeb(len, data_reg);
writeb(SL_SETUP , data_reg);
writeb(usb_pipedevice(urb->pipe), data_reg);
;
sl811_write(sl811, bank + SL11H_HOSTCTLREG,
control | SL11H_HCTLMASK_OUT);
ep->length = 0;
PACKET("SETUP qh%p\n", ep);
}
static void status_packet(
struct sl811 *sl811,
struct sl811h_ep *ep,
struct urb *urb,
u8 bank,
u8 control
)
{
int do_out;
void __iomem *data_reg;
do_out = urb->transfer_buffer_length && usb_pipein(urb->pipe);
data_reg = sl811->data_reg;
sl811_write(sl811, bank + SL11H_BUFADDRREG, 0);
writeb(0, data_reg);
writeb((do_out ? SL_OUT : SL_IN) , data_reg);
writeb(usb_pipedevice(urb->pipe), data_reg);
control |= SL11H_HCTLMASK_TOGGLE;
if (do_out)
control |= SL11H_HCTLMASK_OUT;
sl811_write(sl811, bank + SL11H_HOSTCTLREG, control);
ep->length = 0;
PACKET("STATUS%s/%s qh%p\n", ep->nak_count ? "/retry" : "",
do_out ? "out" : "in", ep);
}
static void in_packet(
struct sl811 *sl811,
struct sl811h_ep *ep,
struct urb *urb,
u8 bank,
u8 control
)
{
u8 addr;
u8 len;
void __iomem *data_reg;
len = ep->maxpacket;
addr = SL811HS_PACKET_BUF(bank == 0);
if (!(control & SL11H_HCTLMASK_ISOCH)
&& usb_gettoggle(urb->dev, ep->epnum, 0))
control |= SL11H_HCTLMASK_TOGGLE;
data_reg = sl811->data_reg;
sl811_write(sl811, bank + SL11H_BUFADDRREG, addr);
writeb(len, data_reg);
writeb(SL_IN | ep->epnum, data_reg);
writeb(usb_pipedevice(urb->pipe), data_reg);
sl811_write(sl811, bank + SL11H_HOSTCTLREG, control);
ep->length = min_t(u32, len,
urb->transfer_buffer_length - urb->actual_length);
PACKET("IN%s/%d qh%p len%d\n", ep->nak_count ? "/retry" : "",
!!usb_gettoggle(urb->dev, ep->epnum, 0), ep, len);
}
static void out_packet(
struct sl811 *sl811,
struct sl811h_ep *ep,
struct urb *urb,
u8 bank,
u8 control
)
{
void *buf;
u8 addr;
u8 len;
void __iomem *data_reg;
buf = urb->transfer_buffer + urb->actual_length;
prefetch(buf);
len = min_t(u32, ep->maxpacket,
urb->transfer_buffer_length - urb->actual_length);
if (!(control & SL11H_HCTLMASK_ISOCH)
&& usb_gettoggle(urb->dev, ep->epnum, 1))
control |= SL11H_HCTLMASK_TOGGLE;
addr = SL811HS_PACKET_BUF(bank == 0);
data_reg = sl811->data_reg;
sl811_write_buf(sl811, addr, buf, len);
sl811_write(sl811, bank + SL11H_BUFADDRREG, addr);
writeb(len, data_reg);
writeb(SL_OUT | ep->epnum, data_reg);
writeb(usb_pipedevice(urb->pipe), data_reg);
sl811_write(sl811, bank + SL11H_HOSTCTLREG,
control | SL11H_HCTLMASK_OUT);
ep->length = len;
PACKET("OUT%s/%d qh%p len%d\n", ep->nak_count ? "/retry" : "",
!!usb_gettoggle(urb->dev, ep->epnum, 1), ep, len);
}
static inline void sofirq_on(struct sl811 *sl811)
{
if (sl811->irq_enable & SL11H_INTMASK_SOFINTR)
return;
VDBG("sof irq on\n");
sl811->irq_enable |= SL11H_INTMASK_SOFINTR;
}
static inline void sofirq_off(struct sl811 *sl811)
{
if (!(sl811->irq_enable & SL11H_INTMASK_SOFINTR))
return;
VDBG("sof irq off\n");
sl811->irq_enable &= ~SL11H_INTMASK_SOFINTR;
}
static struct sl811h_ep *start(struct sl811 *sl811, u8 bank)
{
struct sl811h_ep *ep;
struct urb *urb;
int fclock;
u8 control;
if (sl811->next_periodic) {
ep = sl811->next_periodic;
sl811->next_periodic = ep->next;
} else {
if (sl811->next_async)
ep = sl811->next_async;
else if (!list_empty(&sl811->async))
ep = container_of(sl811->async.next,
struct sl811h_ep, schedule);
else {
return NULL;
}
#ifdef USE_B
if ((bank && sl811->active_b == ep) || sl811->active_a == ep)
return NULL;
#endif
if (ep->schedule.next == &sl811->async)
sl811->next_async = NULL;
else
sl811->next_async = container_of(ep->schedule.next,
struct sl811h_ep, schedule);
}
if (unlikely(list_empty(&ep->hep->urb_list))) {
DBG("empty %p queue?\n", ep);
return NULL;
}
urb = container_of(ep->hep->urb_list.next, struct urb, urb_list);
control = ep->defctrl;
fclock = sl811_read(sl811, SL11H_SOFTMRREG) << 6;
fclock -= 100;
if (urb->dev->speed == USB_SPEED_LOW) {
if (control & SL11H_HCTLMASK_PREAMBLE) {
fclock -= 800;
}
fclock -= ep->maxpacket << 8;
if (fclock < 0) {
if (ep->period)
sl811->stat_overrun++;
sofirq_on(sl811);
return NULL;
}
} else {
fclock -= 12000 / 19;
if (fclock < 0) {
if (ep->period)
sl811->stat_overrun++;
control |= SL11H_HCTLMASK_AFTERSOF;
} else if (ep->nak_count)
control |= SL11H_HCTLMASK_AFTERSOF;
}
switch (ep->nextpid) {
case USB_PID_IN:
in_packet(sl811, ep, urb, bank, control);
break;
case USB_PID_OUT:
out_packet(sl811, ep, urb, bank, control);
break;
case USB_PID_SETUP:
setup_packet(sl811, ep, urb, bank, control);
break;
case USB_PID_ACK:
status_packet(sl811, ep, urb, bank, control);
break;
default:
DBG("bad ep%p pid %02x\n", ep, ep->nextpid);
ep = NULL;
}
return ep;
}
static inline void start_transfer(struct sl811 *sl811)
{
if (sl811->port1 & USB_PORT_STAT_SUSPEND)
return;
if (sl811->active_a == NULL) {
sl811->active_a = start(sl811, SL811_EP_A(SL811_HOST_BUF));
if (sl811->active_a != NULL)
sl811->jiffies_a = jiffies + MIN_JIFFIES;
}
#ifdef USE_B
if (sl811->active_b == NULL) {
sl811->active_b = start(sl811, SL811_EP_B(SL811_HOST_BUF));
if (sl811->active_b != NULL)
sl811->jiffies_b = jiffies + MIN_JIFFIES;
}
#endif
}
static void finish_request(
struct sl811 *sl811,
struct sl811h_ep *ep,
struct urb *urb,
int status
) __releases(sl811->lock) __acquires(sl811->lock)
{
unsigned i;
if (usb_pipecontrol(urb->pipe))
ep->nextpid = USB_PID_SETUP;
usb_hcd_unlink_urb_from_ep(sl811_to_hcd(sl811), urb);
spin_unlock(&sl811->lock);
usb_hcd_giveback_urb(sl811_to_hcd(sl811), urb, status);
spin_lock(&sl811->lock);
if (!list_empty(&ep->hep->urb_list))
return;
if (!list_empty(&ep->schedule)) {
list_del_init(&ep->schedule);
if (ep == sl811->next_async)
sl811->next_async = NULL;
return;
}
DBG("deschedule qh%d/%p branch %d\n", ep->period, ep, ep->branch);
for (i = ep->branch; i < PERIODIC_SIZE; i += ep->period) {
struct sl811h_ep *temp;
struct sl811h_ep **prev = &sl811->periodic[i];
while (*prev && ((temp = *prev) != ep))
prev = &temp->next;
if (*prev)
*prev = ep->next;
sl811->load[i] -= ep->load;
}
ep->branch = PERIODIC_SIZE;
sl811->periodic_count--;
sl811_to_hcd(sl811)->self.bandwidth_allocated
-= ep->load / ep->period;
if (ep == sl811->next_periodic)
sl811->next_periodic = ep->next;
if (sl811->periodic_count == 0)
sofirq_off(sl811);
}
static void
done(struct sl811 *sl811, struct sl811h_ep *ep, u8 bank)
{
u8 status;
struct urb *urb;
int urbstat = -EINPROGRESS;
if (unlikely(!ep))
return;
status = sl811_read(sl811, bank + SL11H_PKTSTATREG);
urb = container_of(ep->hep->urb_list.next, struct urb, urb_list);
if (status & SL11H_STATMASK_NAK) {
if (!ep->period)
ep->nak_count++;
ep->error_count = 0;
} else if (status & SL11H_STATMASK_ACK) {
struct usb_device *udev = urb->dev;
int len;
unsigned char *buf;
ep->nak_count = ep->error_count = 0;
switch (ep->nextpid) {
case USB_PID_OUT:
urb->actual_length += ep->length;
usb_dotoggle(udev, ep->epnum, 1);
if (urb->actual_length
== urb->transfer_buffer_length) {
if (usb_pipecontrol(urb->pipe))
ep->nextpid = USB_PID_ACK;
else if (ep->length < ep->maxpacket
|| !(urb->transfer_flags
& URB_ZERO_PACKET))
urbstat = 0;
}
break;
case USB_PID_IN:
buf = urb->transfer_buffer + urb->actual_length;
prefetchw(buf);
len = ep->maxpacket - sl811_read(sl811,
bank + SL11H_XFERCNTREG);
if (len > ep->length) {
len = ep->length;
urbstat = -EOVERFLOW;
}
urb->actual_length += len;
sl811_read_buf(sl811, SL811HS_PACKET_BUF(bank == 0),
buf, len);
usb_dotoggle(udev, ep->epnum, 0);
if (urbstat == -EINPROGRESS &&
(len < ep->maxpacket ||
urb->actual_length ==
urb->transfer_buffer_length)) {
if (usb_pipecontrol(urb->pipe))
ep->nextpid = USB_PID_ACK;
else
urbstat = 0;
}
break;
case USB_PID_SETUP:
if (urb->transfer_buffer_length == urb->actual_length)
ep->nextpid = USB_PID_ACK;
else if (usb_pipeout(urb->pipe)) {
usb_settoggle(udev, 0, 1, 1);
ep->nextpid = USB_PID_OUT;
} else {
usb_settoggle(udev, 0, 0, 1);
ep->nextpid = USB_PID_IN;
}
break;
case USB_PID_ACK:
urbstat = 0;
break;
}
} else if (status & SL11H_STATMASK_STALL) {
PACKET("...STALL_%02x qh%p\n", bank, ep);
ep->nak_count = ep->error_count = 0;
urbstat = -EPIPE;
} else if (++ep->error_count >= 3) {
if (status & SL11H_STATMASK_TMOUT)
urbstat = -ETIME;
else if (status & SL11H_STATMASK_OVF)
urbstat = -EOVERFLOW;
else
urbstat = -EPROTO;
ep->error_count = 0;
PACKET("...3STRIKES_%02x %02x qh%p stat %d\n",
bank, status, ep, urbstat);
}
if (urbstat != -EINPROGRESS || urb->unlinked)
finish_request(sl811, ep, urb, urbstat);
}
static inline u8 checkdone(struct sl811 *sl811)
{
u8 ctl;
u8 irqstat = 0;
if (sl811->active_a && time_before_eq(sl811->jiffies_a, jiffies)) {
ctl = sl811_read(sl811, SL811_EP_A(SL11H_HOSTCTLREG));
if (ctl & SL11H_HCTLMASK_ARM)
sl811_write(sl811, SL811_EP_A(SL11H_HOSTCTLREG), 0);
DBG("%s DONE_A: ctrl %02x sts %02x\n",
(ctl & SL11H_HCTLMASK_ARM) ? "timeout" : "lost",
ctl,
sl811_read(sl811, SL811_EP_A(SL11H_PKTSTATREG)));
irqstat |= SL11H_INTMASK_DONE_A;
}
#ifdef USE_B
if (sl811->active_b && time_before_eq(sl811->jiffies_b, jiffies)) {
ctl = sl811_read(sl811, SL811_EP_B(SL11H_HOSTCTLREG));
if (ctl & SL11H_HCTLMASK_ARM)
sl811_write(sl811, SL811_EP_B(SL11H_HOSTCTLREG), 0);
DBG("%s DONE_B: ctrl %02x sts %02x\n",
(ctl & SL11H_HCTLMASK_ARM) ? "timeout" : "lost",
ctl,
sl811_read(sl811, SL811_EP_B(SL11H_PKTSTATREG)));
irqstat |= SL11H_INTMASK_DONE_A;
}
#endif
return irqstat;
}
static irqreturn_t sl811h_irq(struct usb_hcd *hcd)
{
struct sl811 *sl811 = hcd_to_sl811(hcd);
u8 irqstat;
irqreturn_t ret = IRQ_NONE;
unsigned retries = 5;
spin_lock(&sl811->lock);
retry:
irqstat = sl811_read(sl811, SL11H_IRQ_STATUS) & ~SL11H_INTMASK_DP;
if (irqstat) {
sl811_write(sl811, SL11H_IRQ_STATUS, irqstat);
irqstat &= sl811->irq_enable;
}
#ifdef QUIRK2
if (irqstat == 0) {
irqstat = checkdone(sl811);
if (irqstat)
sl811->stat_lost++;
}
#endif
if (irqstat & SL11H_INTMASK_DONE_A) {
done(sl811, sl811->active_a, SL811_EP_A(SL811_HOST_BUF));
sl811->active_a = NULL;
sl811->stat_a++;
}
#ifdef USE_B
if (irqstat & SL11H_INTMASK_DONE_B) {
done(sl811, sl811->active_b, SL811_EP_B(SL811_HOST_BUF));
sl811->active_b = NULL;
sl811->stat_b++;
}
#endif
if (irqstat & SL11H_INTMASK_SOFINTR) {
unsigned index;
index = sl811->frame++ % (PERIODIC_SIZE - 1);
sl811->stat_sof++;
if (sl811->next_periodic) {
sl811->stat_overrun++;
}
if (sl811->periodic[index])
sl811->next_periodic = sl811->periodic[index];
}
if (irqstat & SL11H_INTMASK_INSRMV) {
sl811->stat_insrmv++;
sl811->stat_wake = 0;
sl811->stat_sof = 0;
sl811->stat_a = 0;
sl811->stat_b = 0;
sl811->stat_lost = 0;
sl811->ctrl1 = 0;
sl811_write(sl811, SL11H_CTLREG1, sl811->ctrl1);
sl811->irq_enable = SL11H_INTMASK_INSRMV;
sl811_write(sl811, SL11H_IRQ_ENABLE, sl811->irq_enable);
if (sl811->active_a) {
sl811_write(sl811, SL811_EP_A(SL11H_HOSTCTLREG), 0);
finish_request(sl811, sl811->active_a,
container_of(sl811->active_a
->hep->urb_list.next,
struct urb, urb_list),
-ESHUTDOWN);
sl811->active_a = NULL;
}
#ifdef USE_B
if (sl811->active_b) {
sl811_write(sl811, SL811_EP_B(SL11H_HOSTCTLREG), 0);
finish_request(sl811, sl811->active_b,
container_of(sl811->active_b
->hep->urb_list.next,
struct urb, urb_list),
NULL, -ESHUTDOWN);
sl811->active_b = NULL;
}
#endif
if (irqstat & SL11H_INTMASK_RD)
sl811->port1 &= ~USB_PORT_STAT_CONNECTION;
else
sl811->port1 |= USB_PORT_STAT_CONNECTION;
sl811->port1 |= USB_PORT_STAT_C_CONNECTION << 16;
} else if (irqstat & SL11H_INTMASK_RD) {
if (sl811->port1 & USB_PORT_STAT_SUSPEND) {
DBG("wakeup\n");
sl811->port1 |= USB_PORT_STAT_C_SUSPEND << 16;
sl811->stat_wake++;
} else
irqstat &= ~SL11H_INTMASK_RD;
}
if (irqstat) {
if (sl811->port1 & USB_PORT_STAT_ENABLE)
start_transfer(sl811);
ret = IRQ_HANDLED;
if (retries--)
goto retry;
}
if (sl811->periodic_count == 0 && list_empty(&sl811->async))
sofirq_off(sl811);
sl811_write(sl811, SL11H_IRQ_ENABLE, sl811->irq_enable);
spin_unlock(&sl811->lock);
return ret;
}
static int balance(struct sl811 *sl811, u16 period, u16 load)
{
int i, branch = -ENOSPC;
for (i = 0; i < period ; i++) {
if (branch < 0 || sl811->load[branch] > sl811->load[i]) {
int j;
for (j = i; j < PERIODIC_SIZE; j += period) {
if ((sl811->load[j] + load)
> MAX_PERIODIC_LOAD)
break;
}
if (j < PERIODIC_SIZE)
continue;
branch = i;
}
}
return branch;
}
static int sl811h_urb_enqueue(
struct usb_hcd *hcd,
struct urb *urb,
gfp_t mem_flags
) {
struct sl811 *sl811 = hcd_to_sl811(hcd);
struct usb_device *udev = urb->dev;
unsigned int pipe = urb->pipe;
int is_out = !usb_pipein(pipe);
int type = usb_pipetype(pipe);
int epnum = usb_pipeendpoint(pipe);
struct sl811h_ep *ep = NULL;
unsigned long flags;
int i;
int retval;
struct usb_host_endpoint *hep = urb->ep;
#ifndef CONFIG_USB_SL811_HCD_ISO
if (type == PIPE_ISOCHRONOUS)
return -ENOSPC;
#endif
if (!hep->hcpriv) {
ep = kzalloc(sizeof *ep, mem_flags);
if (ep == NULL)
return -ENOMEM;
}
spin_lock_irqsave(&sl811->lock, flags);
if (!(sl811->port1 & USB_PORT_STAT_ENABLE)
|| !HC_IS_RUNNING(hcd->state)) {
retval = -ENODEV;
kfree(ep);
goto fail_not_linked;
}
retval = usb_hcd_link_urb_to_ep(hcd, urb);
if (retval) {
kfree(ep);
goto fail_not_linked;
}
if (hep->hcpriv) {
kfree(ep);
ep = hep->hcpriv;
} else if (!ep) {
retval = -ENOMEM;
goto fail;
} else {
INIT_LIST_HEAD(&ep->schedule);
ep->udev = udev;
ep->epnum = epnum;
ep->maxpacket = usb_maxpacket(udev, urb->pipe, is_out);
ep->defctrl = SL11H_HCTLMASK_ARM | SL11H_HCTLMASK_ENABLE;
usb_settoggle(udev, epnum, is_out, 0);
if (type == PIPE_CONTROL)
ep->nextpid = USB_PID_SETUP;
else if (is_out)
ep->nextpid = USB_PID_OUT;
else
ep->nextpid = USB_PID_IN;
if (ep->maxpacket > H_MAXPACKET) {
DBG("dev %d ep%d maxpacket %d\n",
udev->devnum, epnum, ep->maxpacket);
retval = -EINVAL;
kfree(ep);
goto fail;
}
if (udev->speed == USB_SPEED_LOW) {
if (!(sl811->ctrl1 & SL11H_CTL1MASK_LSPD))
ep->defctrl |= SL11H_HCTLMASK_PREAMBLE;
}
switch (type) {
case PIPE_ISOCHRONOUS:
case PIPE_INTERRUPT:
if (urb->interval > PERIODIC_SIZE)
urb->interval = PERIODIC_SIZE;
ep->period = urb->interval;
ep->branch = PERIODIC_SIZE;
if (type == PIPE_ISOCHRONOUS)
ep->defctrl |= SL11H_HCTLMASK_ISOCH;
ep->load = usb_calc_bus_time(udev->speed, !is_out,
(type == PIPE_ISOCHRONOUS),
usb_maxpacket(udev, pipe, is_out))
/ 1000;
break;
}
ep->hep = hep;
hep->hcpriv = ep;
}
switch (type) {
case PIPE_CONTROL:
case PIPE_BULK:
if (list_empty(&ep->schedule))
list_add_tail(&ep->schedule, &sl811->async);
break;
case PIPE_ISOCHRONOUS:
case PIPE_INTERRUPT:
urb->interval = ep->period;
if (ep->branch < PERIODIC_SIZE) {
urb->start_frame = (sl811->frame & (PERIODIC_SIZE - 1))
+ ep->branch;
break;
}
retval = balance(sl811, ep->period, ep->load);
if (retval < 0)
goto fail;
ep->branch = retval;
retval = 0;
urb->start_frame = (sl811->frame & (PERIODIC_SIZE - 1))
+ ep->branch;
DBG("schedule qh%d/%p branch %d\n", ep->period, ep, ep->branch);
for (i = ep->branch; i < PERIODIC_SIZE; i += ep->period) {
struct sl811h_ep **prev = &sl811->periodic[i];
struct sl811h_ep *here = *prev;
while (here && ep != here) {
if (ep->period > here->period)
break;
prev = &here->next;
here = *prev;
}
if (ep != here) {
ep->next = here;
*prev = ep;
}
sl811->load[i] += ep->load;
}
sl811->periodic_count++;
hcd->self.bandwidth_allocated += ep->load / ep->period;
sofirq_on(sl811);
}
urb->hcpriv = hep;
start_transfer(sl811);
sl811_write(sl811, SL11H_IRQ_ENABLE, sl811->irq_enable);
fail:
if (retval)
usb_hcd_unlink_urb_from_ep(hcd, urb);
fail_not_linked:
spin_unlock_irqrestore(&sl811->lock, flags);
return retval;
}
static int sl811h_urb_dequeue(struct usb_hcd *hcd, struct urb *urb, int status)
{
struct sl811 *sl811 = hcd_to_sl811(hcd);
struct usb_host_endpoint *hep;
unsigned long flags;
struct sl811h_ep *ep;
int retval;
spin_lock_irqsave(&sl811->lock, flags);
retval = usb_hcd_check_unlink_urb(hcd, urb, status);
if (retval)
goto fail;
hep = urb->hcpriv;
ep = hep->hcpriv;
if (ep) {
if (ep->hep->urb_list.next != &urb->urb_list) {
} else if (sl811->active_a == ep) {
if (time_before_eq(sl811->jiffies_a, jiffies)) {
DBG("giveup on DONE_A: ctrl %02x sts %02x\n",
sl811_read(sl811,
SL811_EP_A(SL11H_HOSTCTLREG)),
sl811_read(sl811,
SL811_EP_A(SL11H_PKTSTATREG)));
sl811_write(sl811, SL811_EP_A(SL11H_HOSTCTLREG),
0);
sl811->active_a = NULL;
} else
urb = NULL;
#ifdef USE_B
} else if (sl811->active_b == ep) {
if (time_before_eq(sl811->jiffies_a, jiffies)) {
DBG("giveup on DONE_B: ctrl %02x sts %02x\n",
sl811_read(sl811,
SL811_EP_B(SL11H_HOSTCTLREG)),
sl811_read(sl811,
SL811_EP_B(SL11H_PKTSTATREG)));
sl811_write(sl811, SL811_EP_B(SL11H_HOSTCTLREG),
0);
sl811->active_b = NULL;
} else
urb = NULL;
#endif
} else {
}
if (urb)
finish_request(sl811, ep, urb, 0);
else
VDBG("dequeue, urb %p active %s; wait4irq\n", urb,
(sl811->active_a == ep) ? "A" : "B");
} else
retval = -EINVAL;
fail:
spin_unlock_irqrestore(&sl811->lock, flags);
return retval;
}
static void
sl811h_endpoint_disable(struct usb_hcd *hcd, struct usb_host_endpoint *hep)
{
struct sl811h_ep *ep = hep->hcpriv;
if (!ep)
return;
if (!list_empty(&hep->urb_list))
msleep(3);
if (!list_empty(&hep->urb_list))
WARNING("ep %p not empty?\n", ep);
kfree(ep);
hep->hcpriv = NULL;
}
static int
sl811h_get_frame(struct usb_hcd *hcd)
{
struct sl811 *sl811 = hcd_to_sl811(hcd);
return sl811->frame;
}
static int
sl811h_hub_status_data(struct usb_hcd *hcd, char *buf)
{
struct sl811 *sl811 = hcd_to_sl811(hcd);
#ifdef QUIRK3
unsigned long flags;
local_irq_save(flags);
if (!timer_pending(&sl811->timer)) {
if (sl811h_irq( hcd) != IRQ_NONE)
sl811->stat_lost++;
}
local_irq_restore(flags);
#endif
if (!(sl811->port1 & (0xffff << 16)))
return 0;
*buf = (1 << 1);
return 1;
}
static void
sl811h_hub_descriptor (
struct sl811 *sl811,
struct usb_hub_descriptor *desc
) {
u16 temp = 0;
desc->bDescriptorType = 0x29;
desc->bHubContrCurrent = 0;
desc->bNbrPorts = 1;
desc->bDescLength = 9;
desc->bPwrOn2PwrGood = 0;
if (sl811->board && sl811->board->port_power) {
desc->bPwrOn2PwrGood = sl811->board->potpg;
if (!desc->bPwrOn2PwrGood)
desc->bPwrOn2PwrGood = 10;
temp = 0x0001;
} else
temp = 0x0002;
temp |= 0x0010;
desc->wHubCharacteristics = cpu_to_le16(temp);
desc->u.hs.DeviceRemovable[0] = 0 << 1;
desc->u.hs.DeviceRemovable[1] = ~0;
}
static void
sl811h_timer(unsigned long _sl811)
{
struct sl811 *sl811 = (void *) _sl811;
unsigned long flags;
u8 irqstat;
u8 signaling = sl811->ctrl1 & SL11H_CTL1MASK_FORCE;
const u32 mask = USB_PORT_STAT_CONNECTION
| USB_PORT_STAT_ENABLE
| USB_PORT_STAT_LOW_SPEED;
spin_lock_irqsave(&sl811->lock, flags);
sl811->ctrl1 &= ~SL11H_CTL1MASK_FORCE;
sl811_write(sl811, SL11H_CTLREG1, sl811->ctrl1);
udelay(3);
irqstat = sl811_read(sl811, SL11H_IRQ_STATUS);
switch (signaling) {
case SL11H_CTL1MASK_SE0:
DBG("end reset\n");
sl811->port1 = (USB_PORT_STAT_C_RESET << 16)
| USB_PORT_STAT_POWER;
sl811->ctrl1 = 0;
if (irqstat & SL11H_INTMASK_INSRMV)
irqstat &= ~SL11H_INTMASK_RD;
break;
case SL11H_CTL1MASK_K:
DBG("end resume\n");
sl811->port1 &= ~USB_PORT_STAT_SUSPEND;
break;
default:
DBG("odd timer signaling: %02x\n", signaling);
break;
}
sl811_write(sl811, SL11H_IRQ_STATUS, irqstat);
if (irqstat & SL11H_INTMASK_RD) {
if (sl811->port1 & USB_PORT_STAT_CONNECTION)
sl811->port1 |= (USB_PORT_STAT_C_CONNECTION << 16)
| (USB_PORT_STAT_C_ENABLE << 16);
sl811->port1 &= ~mask;
sl811->irq_enable = SL11H_INTMASK_INSRMV;
} else {
sl811->port1 |= mask;
if (irqstat & SL11H_INTMASK_DP)
sl811->port1 &= ~USB_PORT_STAT_LOW_SPEED;
sl811->irq_enable = SL11H_INTMASK_INSRMV | SL11H_INTMASK_RD;
}
if (sl811->port1 & USB_PORT_STAT_CONNECTION) {
u8 ctrl2 = SL811HS_CTL2_INIT;
sl811->irq_enable |= SL11H_INTMASK_DONE_A;
#ifdef USE_B
sl811->irq_enable |= SL11H_INTMASK_DONE_B;
#endif
if (sl811->port1 & USB_PORT_STAT_LOW_SPEED) {
sl811->ctrl1 |= SL11H_CTL1MASK_LSPD;
ctrl2 |= SL811HS_CTL2MASK_DSWAP;
}
sl811->ctrl1 |= SL11H_CTL1MASK_SOF_ENA;
sl811_write(sl811, SL11H_SOFLOWREG, 0xe0);
sl811_write(sl811, SL811HS_CTLREG2, ctrl2);
sl811_write(sl811, SL811_EP_A(SL11H_BUFLNTHREG), 0);
writeb(SL_SOF, sl811->data_reg);
writeb(0, sl811->data_reg);
sl811_write(sl811, SL811_EP_A(SL11H_HOSTCTLREG),
SL11H_HCTLMASK_ARM);
} else {
sl811->ctrl1 = 0;
}
sl811_write(sl811, SL11H_CTLREG1, sl811->ctrl1);
sl811_write(sl811, SL11H_IRQ_ENABLE, sl811->irq_enable);
spin_unlock_irqrestore(&sl811->lock, flags);
}
static int
sl811h_hub_control(
struct usb_hcd *hcd,
u16 typeReq,
u16 wValue,
u16 wIndex,
char *buf,
u16 wLength
) {
struct sl811 *sl811 = hcd_to_sl811(hcd);
int retval = 0;
unsigned long flags;
spin_lock_irqsave(&sl811->lock, flags);
switch (typeReq) {
case ClearHubFeature:
case SetHubFeature:
switch (wValue) {
case C_HUB_OVER_CURRENT:
case C_HUB_LOCAL_POWER:
break;
default:
goto error;
}
break;
case ClearPortFeature:
if (wIndex != 1 || wLength != 0)
goto error;
switch (wValue) {
case USB_PORT_FEAT_ENABLE:
sl811->port1 &= USB_PORT_STAT_POWER;
sl811->ctrl1 = 0;
sl811_write(sl811, SL11H_CTLREG1, sl811->ctrl1);
sl811->irq_enable = SL11H_INTMASK_INSRMV;
sl811_write(sl811, SL11H_IRQ_ENABLE,
sl811->irq_enable);
break;
case USB_PORT_FEAT_SUSPEND:
if (!(sl811->port1 & USB_PORT_STAT_SUSPEND))
break;
DBG("start resume...\n");
sl811->irq_enable = 0;
sl811_write(sl811, SL11H_IRQ_ENABLE,
sl811->irq_enable);
sl811->ctrl1 |= SL11H_CTL1MASK_K;
sl811_write(sl811, SL11H_CTLREG1, sl811->ctrl1);
mod_timer(&sl811->timer, jiffies
+ msecs_to_jiffies(20));
break;
case USB_PORT_FEAT_POWER:
port_power(sl811, 0);
break;
case USB_PORT_FEAT_C_ENABLE:
case USB_PORT_FEAT_C_SUSPEND:
case USB_PORT_FEAT_C_CONNECTION:
case USB_PORT_FEAT_C_OVER_CURRENT:
case USB_PORT_FEAT_C_RESET:
break;
default:
goto error;
}
sl811->port1 &= ~(1 << wValue);
break;
case GetHubDescriptor:
sl811h_hub_descriptor(sl811, (struct usb_hub_descriptor *) buf);
break;
case GetHubStatus:
put_unaligned_le32(0, buf);
break;
case GetPortStatus:
if (wIndex != 1)
goto error;
put_unaligned_le32(sl811->port1, buf);
#ifndef VERBOSE
if (*(u16*)(buf+2))
#endif
DBG("GetPortStatus %08x\n", sl811->port1);
break;
case SetPortFeature:
if (wIndex != 1 || wLength != 0)
goto error;
switch (wValue) {
case USB_PORT_FEAT_SUSPEND:
if (sl811->port1 & USB_PORT_STAT_RESET)
goto error;
if (!(sl811->port1 & USB_PORT_STAT_ENABLE))
goto error;
DBG("suspend...\n");
sl811->ctrl1 &= ~SL11H_CTL1MASK_SOF_ENA;
sl811_write(sl811, SL11H_CTLREG1, sl811->ctrl1);
break;
case USB_PORT_FEAT_POWER:
port_power(sl811, 1);
break;
case USB_PORT_FEAT_RESET:
if (sl811->port1 & USB_PORT_STAT_SUSPEND)
goto error;
if (!(sl811->port1 & USB_PORT_STAT_POWER))
break;
sl811->irq_enable = 0;
sl811_write(sl811, SL11H_IRQ_ENABLE,
sl811->irq_enable);
sl811->ctrl1 = SL11H_CTL1MASK_SE0;
sl811_write(sl811, SL11H_CTLREG1, sl811->ctrl1);
sl811->port1 |= USB_PORT_STAT_RESET;
mod_timer(&sl811->timer, jiffies
+ msecs_to_jiffies(50));
break;
default:
goto error;
}
sl811->port1 |= 1 << wValue;
break;
default:
error:
retval = -EPIPE;
}
spin_unlock_irqrestore(&sl811->lock, flags);
return retval;
}
static int
sl811h_bus_suspend(struct usb_hcd *hcd)
{
DBG("%s\n", __func__);
return 0;
}
static int
sl811h_bus_resume(struct usb_hcd *hcd)
{
DBG("%s\n", __func__);
return 0;
}
static inline void create_debug_file(struct sl811 *sl811) { }
static inline void remove_debug_file(struct sl811 *sl811) { }
static void dump_irq(struct seq_file *s, char *label, u8 mask)
{
seq_printf(s, "%s %02x%s%s%s%s%s%s\n", label, mask,
(mask & SL11H_INTMASK_DONE_A) ? " done_a" : "",
(mask & SL11H_INTMASK_DONE_B) ? " done_b" : "",
(mask & SL11H_INTMASK_SOFINTR) ? " sof" : "",
(mask & SL11H_INTMASK_INSRMV) ? " ins/rmv" : "",
(mask & SL11H_INTMASK_RD) ? " rd" : "",
(mask & SL11H_INTMASK_DP) ? " dp" : "");
}
static int proc_sl811h_show(struct seq_file *s, void *unused)
{
struct sl811 *sl811 = s->private;
struct sl811h_ep *ep;
unsigned i;
seq_printf(s, "%s\n%s version %s\nportstatus[1] = %08x\n",
sl811_to_hcd(sl811)->product_desc,
hcd_name, DRIVER_VERSION,
sl811->port1);
seq_printf(s, "insert/remove: %ld\n", sl811->stat_insrmv);
seq_printf(s, "current session: done_a %ld done_b %ld "
"wake %ld sof %ld overrun %ld lost %ld\n\n",
sl811->stat_a, sl811->stat_b,
sl811->stat_wake, sl811->stat_sof,
sl811->stat_overrun, sl811->stat_lost);
spin_lock_irq(&sl811->lock);
if (sl811->ctrl1 & SL11H_CTL1MASK_SUSPEND)
seq_printf(s, "(suspended)\n\n");
else {
u8 t = sl811_read(sl811, SL11H_CTLREG1);
seq_printf(s, "ctrl1 %02x%s%s%s%s\n", t,
(t & SL11H_CTL1MASK_SOF_ENA) ? " sofgen" : "",
({char *s; switch (t & SL11H_CTL1MASK_FORCE) {
case SL11H_CTL1MASK_NORMAL: s = ""; break;
case SL11H_CTL1MASK_SE0: s = " se0/reset"; break;
case SL11H_CTL1MASK_K: s = " k/resume"; break;
default: s = "j"; break;
}; s; }),
(t & SL11H_CTL1MASK_LSPD) ? " lowspeed" : "",
(t & SL11H_CTL1MASK_SUSPEND) ? " suspend" : "");
dump_irq(s, "irq_enable",
sl811_read(sl811, SL11H_IRQ_ENABLE));
dump_irq(s, "irq_status",
sl811_read(sl811, SL11H_IRQ_STATUS));
seq_printf(s, "frame clocks remaining: %d\n",
sl811_read(sl811, SL11H_SOFTMRREG) << 6);
}
seq_printf(s, "A: qh%p ctl %02x sts %02x\n", sl811->active_a,
sl811_read(sl811, SL811_EP_A(SL11H_HOSTCTLREG)),
sl811_read(sl811, SL811_EP_A(SL11H_PKTSTATREG)));
seq_printf(s, "B: qh%p ctl %02x sts %02x\n", sl811->active_b,
sl811_read(sl811, SL811_EP_B(SL11H_HOSTCTLREG)),
sl811_read(sl811, SL811_EP_B(SL11H_PKTSTATREG)));
seq_printf(s, "\n");
list_for_each_entry (ep, &sl811->async, schedule) {
struct urb *urb;
seq_printf(s, "%s%sqh%p, ep%d%s, maxpacket %d"
" nak %d err %d\n",
(ep == sl811->active_a) ? "(A) " : "",
(ep == sl811->active_b) ? "(B) " : "",
ep, ep->epnum,
({ char *s; switch (ep->nextpid) {
case USB_PID_IN: s = "in"; break;
case USB_PID_OUT: s = "out"; break;
case USB_PID_SETUP: s = "setup"; break;
case USB_PID_ACK: s = "status"; break;
default: s = "?"; break;
}; s;}),
ep->maxpacket,
ep->nak_count, ep->error_count);
list_for_each_entry (urb, &ep->hep->urb_list, urb_list) {
seq_printf(s, " urb%p, %d/%d\n", urb,
urb->actual_length,
urb->transfer_buffer_length);
}
}
if (!list_empty(&sl811->async))
seq_printf(s, "\n");
seq_printf(s, "periodic size= %d\n", PERIODIC_SIZE);
for (i = 0; i < PERIODIC_SIZE; i++) {
ep = sl811->periodic[i];
if (!ep)
continue;
seq_printf(s, "%2d [%3d]:\n", i, sl811->load[i]);
do {
seq_printf(s,
" %s%sqh%d/%p (%sdev%d ep%d%s max %d) "
"err %d\n",
(ep == sl811->active_a) ? "(A) " : "",
(ep == sl811->active_b) ? "(B) " : "",
ep->period, ep,
(ep->udev->speed == USB_SPEED_FULL)
? "" : "ls ",
ep->udev->devnum, ep->epnum,
(ep->epnum == 0) ? ""
: ((ep->nextpid == USB_PID_IN)
? "in"
: "out"),
ep->maxpacket, ep->error_count);
ep = ep->next;
} while (ep);
}
spin_unlock_irq(&sl811->lock);
seq_printf(s, "\n");
return 0;
}
static int proc_sl811h_open(struct inode *inode, struct file *file)
{
return single_open(file, proc_sl811h_show, PDE(inode)->data);
}
static void create_debug_file(struct sl811 *sl811)
{
sl811->pde = proc_create_data(proc_filename, 0, NULL, &proc_ops, sl811);
}
static void remove_debug_file(struct sl811 *sl811)
{
if (sl811->pde)
remove_proc_entry(proc_filename, NULL);
}
static void
sl811h_stop(struct usb_hcd *hcd)
{
struct sl811 *sl811 = hcd_to_sl811(hcd);
unsigned long flags;
del_timer_sync(&hcd->rh_timer);
spin_lock_irqsave(&sl811->lock, flags);
port_power(sl811, 0);
spin_unlock_irqrestore(&sl811->lock, flags);
}
static int
sl811h_start(struct usb_hcd *hcd)
{
struct sl811 *sl811 = hcd_to_sl811(hcd);
hcd->state = HC_STATE_RUNNING;
if (sl811->board) {
if (!device_can_wakeup(hcd->self.controller))
device_init_wakeup(hcd->self.controller,
sl811->board->can_wakeup);
hcd->power_budget = sl811->board->power * 2;
}
port_power(sl811, 1);
return 0;
}
static int __devexit
sl811h_remove(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct sl811 *sl811 = hcd_to_sl811(hcd);
struct resource *res;
remove_debug_file(sl811);
usb_remove_hcd(hcd);
res = platform_get_resource(dev, IORESOURCE_MEM, 1);
if (res)
iounmap(sl811->data_reg);
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (res)
iounmap(sl811->addr_reg);
usb_put_hcd(hcd);
return 0;
}
static int __devinit
sl811h_probe(struct platform_device *dev)
{
struct usb_hcd *hcd;
struct sl811 *sl811;
struct resource *addr, *data, *ires;
int irq;
void __iomem *addr_reg;
void __iomem *data_reg;
int retval;
u8 tmp, ioaddr = 0;
unsigned long irqflags;
if (usb_disabled())
return -ENODEV;
ires = platform_get_resource(dev, IORESOURCE_IRQ, 0);
if (dev->num_resources < 3 || !ires)
return -ENODEV;
irq = ires->start;
irqflags = ires->flags & IRQF_TRIGGER_MASK;
if (dev->dev.dma_mask) {
DBG("no we won't dma\n");
return -EINVAL;
}
addr = platform_get_resource(dev, IORESOURCE_MEM, 0);
data = platform_get_resource(dev, IORESOURCE_MEM, 1);
retval = -EBUSY;
if (!addr || !data) {
addr = platform_get_resource(dev, IORESOURCE_IO, 0);
data = platform_get_resource(dev, IORESOURCE_IO, 1);
if (!addr || !data)
return -ENODEV;
ioaddr = 1;
addr_reg = (void __iomem *) (unsigned long) addr->start;
data_reg = (void __iomem *) (unsigned long) data->start;
} else {
addr_reg = ioremap(addr->start, 1);
if (addr_reg == NULL) {
retval = -ENOMEM;
goto err2;
}
data_reg = ioremap(data->start, 1);
if (data_reg == NULL) {
retval = -ENOMEM;
goto err4;
}
}
hcd = usb_create_hcd(&sl811h_hc_driver, &dev->dev, dev_name(&dev->dev));
if (!hcd) {
retval = -ENOMEM;
goto err5;
}
hcd->rsrc_start = addr->start;
sl811 = hcd_to_sl811(hcd);
spin_lock_init(&sl811->lock);
INIT_LIST_HEAD(&sl811->async);
sl811->board = dev->dev.platform_data;
init_timer(&sl811->timer);
sl811->timer.function = sl811h_timer;
sl811->timer.data = (unsigned long) sl811;
sl811->addr_reg = addr_reg;
sl811->data_reg = data_reg;
spin_lock_irq(&sl811->lock);
port_power(sl811, 0);
spin_unlock_irq(&sl811->lock);
msleep(200);
tmp = sl811_read(sl811, SL11H_HWREVREG);
switch (tmp >> 4) {
case 1:
hcd->product_desc = "SL811HS v1.2";
break;
case 2:
hcd->product_desc = "SL811HS v1.5";
break;
default:
DBG("chiprev %02x\n", tmp);
retval = -ENXIO;
goto err6;
}
irqflags |= IRQF_SHARED;
retval = usb_add_hcd(hcd, irq, irqflags);
if (retval != 0)
goto err6;
create_debug_file(sl811);
return retval;
err6:
usb_put_hcd(hcd);
err5:
if (!ioaddr)
iounmap(data_reg);
err4:
if (!ioaddr)
iounmap(addr_reg);
err2:
DBG("init error, %d\n", retval);
return retval;
}
static int
sl811h_suspend(struct platform_device *dev, pm_message_t state)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct sl811 *sl811 = hcd_to_sl811(hcd);
int retval = 0;
switch (state.event) {
case PM_EVENT_FREEZE:
retval = sl811h_bus_suspend(hcd);
break;
case PM_EVENT_SUSPEND:
case PM_EVENT_HIBERNATE:
case PM_EVENT_PRETHAW:
port_power(sl811, 0);
break;
}
return retval;
}
static int
sl811h_resume(struct platform_device *dev)
{
struct usb_hcd *hcd = platform_get_drvdata(dev);
struct sl811 *sl811 = hcd_to_sl811(hcd);
if (!sl811->port1 || !device_can_wakeup(&hcd->self.root_hub->dev)) {
sl811->port1 = 0;
port_power(sl811, 1);
usb_root_hub_lost_power(hcd->self.root_hub);
return 0;
}
return sl811h_bus_resume(hcd);
}
