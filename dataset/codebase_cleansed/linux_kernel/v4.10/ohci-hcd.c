static int number_of_tds(struct urb *urb)
{
int len, i, num, this_sg_len;
struct scatterlist *sg;
len = urb->transfer_buffer_length;
i = urb->num_mapped_sgs;
if (len > 0 && i > 0) {
num = 0;
sg = urb->sg;
for (;;) {
this_sg_len = min_t(int, sg_dma_len(sg), len);
num += DIV_ROUND_UP(this_sg_len, 4096);
len -= this_sg_len;
if (--i <= 0 || len <= 0)
break;
sg = sg_next(sg);
}
} else {
num = DIV_ROUND_UP(len, 4096);
}
return num;
}
static int ohci_urb_enqueue (
struct usb_hcd *hcd,
struct urb *urb,
gfp_t mem_flags
) {
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
struct ed *ed;
urb_priv_t *urb_priv;
unsigned int pipe = urb->pipe;
int i, size = 0;
unsigned long flags;
int retval = 0;
ed = ed_get(ohci, urb->ep, urb->dev, pipe, urb->interval);
if (! ed)
return -ENOMEM;
switch (ed->type) {
case PIPE_CONTROL:
if (urb->transfer_buffer_length > 4096)
return -EMSGSIZE;
size = 2;
default:
size += number_of_tds(urb);
if (size == 0)
size++;
else if ((urb->transfer_flags & URB_ZERO_PACKET) != 0
&& (urb->transfer_buffer_length
% usb_maxpacket (urb->dev, pipe,
usb_pipeout (pipe))) == 0)
size++;
break;
case PIPE_ISOCHRONOUS:
size = urb->number_of_packets;
break;
}
urb_priv = kzalloc (sizeof (urb_priv_t) + size * sizeof (struct td *),
mem_flags);
if (!urb_priv)
return -ENOMEM;
INIT_LIST_HEAD (&urb_priv->pending);
urb_priv->length = size;
urb_priv->ed = ed;
for (i = 0; i < size; i++) {
urb_priv->td [i] = td_alloc (ohci, mem_flags);
if (!urb_priv->td [i]) {
urb_priv->length = i;
urb_free_priv (ohci, urb_priv);
return -ENOMEM;
}
}
spin_lock_irqsave (&ohci->lock, flags);
if (!HCD_HW_ACCESSIBLE(hcd)) {
retval = -ENODEV;
goto fail;
}
if (ohci->rh_state != OHCI_RH_RUNNING) {
retval = -ENODEV;
goto fail;
}
retval = usb_hcd_link_urb_to_ep(hcd, urb);
if (retval)
goto fail;
if (ed->state == ED_IDLE) {
retval = ed_schedule (ohci, ed);
if (retval < 0) {
usb_hcd_unlink_urb_from_ep(hcd, urb);
goto fail;
}
if (!timer_pending(&ohci->io_watchdog) &&
list_empty(&ohci->eds_in_use)) {
ohci->prev_frame_no = ohci_frame_no(ohci);
mod_timer(&ohci->io_watchdog,
jiffies + IO_WATCHDOG_DELAY);
}
list_add(&ed->in_use_list, &ohci->eds_in_use);
if (ed->type == PIPE_ISOCHRONOUS) {
u16 frame = ohci_frame_no(ohci);
frame += max_t (u16, 8, ed->interval);
frame &= ~(ed->interval - 1);
frame |= ed->branch;
urb->start_frame = frame;
ed->last_iso = frame + ed->interval * (size - 1);
}
} else if (ed->type == PIPE_ISOCHRONOUS) {
u16 next = ohci_frame_no(ohci) + 1;
u16 frame = ed->last_iso + ed->interval;
u16 length = ed->interval * (size - 1);
if (unlikely(tick_before(frame, next))) {
if (urb->transfer_flags & URB_ISO_ASAP) {
frame += (next - frame + ed->interval - 1) &
-ed->interval;
} else {
urb_priv->td_cnt = DIV_ROUND_UP(
(u16) (next - frame),
ed->interval);
if (urb_priv->td_cnt >= urb_priv->length) {
++urb_priv->td_cnt;
ohci_dbg(ohci, "iso underrun %p (%u+%u < %u)\n",
urb, frame, length,
next);
}
}
}
urb->start_frame = frame;
ed->last_iso = frame + length;
}
urb->hcpriv = urb_priv;
td_submit_urb (ohci, urb);
fail:
if (retval)
urb_free_priv (ohci, urb_priv);
spin_unlock_irqrestore (&ohci->lock, flags);
return retval;
}
static int ohci_urb_dequeue(struct usb_hcd *hcd, struct urb *urb, int status)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
unsigned long flags;
int rc;
urb_priv_t *urb_priv;
spin_lock_irqsave (&ohci->lock, flags);
rc = usb_hcd_check_unlink_urb(hcd, urb, status);
if (rc == 0) {
urb_priv = urb->hcpriv;
if (urb_priv->ed->state == ED_OPER)
start_ed_unlink(ohci, urb_priv->ed);
if (ohci->rh_state != OHCI_RH_RUNNING) {
ohci_work(ohci);
}
}
spin_unlock_irqrestore (&ohci->lock, flags);
return rc;
}
static void
ohci_endpoint_disable (struct usb_hcd *hcd, struct usb_host_endpoint *ep)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
unsigned long flags;
struct ed *ed = ep->hcpriv;
unsigned limit = 1000;
if (!ed)
return;
rescan:
spin_lock_irqsave (&ohci->lock, flags);
if (ohci->rh_state != OHCI_RH_RUNNING) {
sanitize:
ed->state = ED_IDLE;
ohci_work(ohci);
}
switch (ed->state) {
case ED_UNLINK:
if (limit-- == 0) {
ohci_warn(ohci, "ED unlink timeout\n");
goto sanitize;
}
spin_unlock_irqrestore (&ohci->lock, flags);
schedule_timeout_uninterruptible(1);
goto rescan;
case ED_IDLE:
if (list_empty (&ed->td_list)) {
td_free (ohci, ed->dummy);
ed_free (ohci, ed);
break;
}
default:
ohci_err (ohci, "leak ed %p (#%02x) state %d%s\n",
ed, ep->desc.bEndpointAddress, ed->state,
list_empty (&ed->td_list) ? "" : " (has tds)");
td_free (ohci, ed->dummy);
break;
}
ep->hcpriv = NULL;
spin_unlock_irqrestore (&ohci->lock, flags);
}
static int ohci_get_frame (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
return ohci_frame_no(ohci);
}
static void ohci_usb_reset (struct ohci_hcd *ohci)
{
ohci->hc_control = ohci_readl (ohci, &ohci->regs->control);
ohci->hc_control &= OHCI_CTRL_RWC;
ohci_writel (ohci, ohci->hc_control, &ohci->regs->control);
ohci->rh_state = OHCI_RH_HALTED;
}
static void
ohci_shutdown (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci;
ohci = hcd_to_ohci (hcd);
ohci_writel(ohci, (u32) ~0, &ohci->regs->intrdisable);
ohci_writel(ohci, OHCI_HCR, &ohci->regs->cmdstatus);
ohci_readl(ohci, &ohci->regs->cmdstatus);
udelay(10);
ohci_writel(ohci, ohci->fminterval, &ohci->regs->fminterval);
ohci->rh_state = OHCI_RH_HALTED;
}
static int ohci_init (struct ohci_hcd *ohci)
{
int ret;
struct usb_hcd *hcd = ohci_to_hcd(ohci);
hcd->self.sg_tablesize = ~0;
if (distrust_firmware)
ohci->flags |= OHCI_QUIRK_HUB_POWER;
ohci->rh_state = OHCI_RH_HALTED;
ohci->regs = hcd->regs;
#ifndef IR_DISABLE
if (!no_handshake && ohci_readl (ohci,
&ohci->regs->control) & OHCI_CTRL_IR) {
u32 temp;
ohci_dbg (ohci, "USB HC TakeOver from BIOS/SMM\n");
temp = 500;
ohci_writel (ohci, OHCI_INTR_OC, &ohci->regs->intrenable);
ohci_writel (ohci, OHCI_OCR, &ohci->regs->cmdstatus);
while (ohci_readl (ohci, &ohci->regs->control) & OHCI_CTRL_IR) {
msleep (10);
if (--temp == 0) {
ohci_err (ohci, "USB HC takeover failed!"
" (BIOS/SMM bug)\n");
return -EBUSY;
}
}
ohci_usb_reset (ohci);
}
#endif
ohci_writel (ohci, OHCI_INTR_MIE, &ohci->regs->intrdisable);
if (ohci_readl (ohci, &ohci->regs->control) & OHCI_CTRL_RWC)
ohci->hc_control |= OHCI_CTRL_RWC;
if (ohci->num_ports == 0)
ohci->num_ports = roothub_a(ohci) & RH_A_NDP;
if (ohci->hcca)
return 0;
setup_timer(&ohci->io_watchdog, io_watchdog_func,
(unsigned long) ohci);
ohci->hcca = dma_alloc_coherent (hcd->self.controller,
sizeof(*ohci->hcca), &ohci->hcca_dma, GFP_KERNEL);
if (!ohci->hcca)
return -ENOMEM;
if ((ret = ohci_mem_init (ohci)) < 0)
ohci_stop (hcd);
else {
create_debug_files (ohci);
}
return ret;
}
static int ohci_run (struct ohci_hcd *ohci)
{
u32 mask, val;
int first = ohci->fminterval == 0;
struct usb_hcd *hcd = ohci_to_hcd(ohci);
ohci->rh_state = OHCI_RH_HALTED;
if (first) {
val = ohci_readl (ohci, &ohci->regs->fminterval);
ohci->fminterval = val & 0x3fff;
if (ohci->fminterval != FI)
ohci_dbg (ohci, "fminterval delta %d\n",
ohci->fminterval - FI);
ohci->fminterval |= FSMP (ohci->fminterval) << 16;
}
if ((ohci->hc_control & OHCI_CTRL_RWC) != 0)
device_set_wakeup_capable(hcd->self.controller, 1);
switch (ohci->hc_control & OHCI_CTRL_HCFS) {
case OHCI_USB_OPER:
val = 0;
break;
case OHCI_USB_SUSPEND:
case OHCI_USB_RESUME:
ohci->hc_control &= OHCI_CTRL_RWC;
ohci->hc_control |= OHCI_USB_RESUME;
val = 10 ;
break;
default:
ohci->hc_control &= OHCI_CTRL_RWC;
ohci->hc_control |= OHCI_USB_RESET;
val = 50 ;
break;
}
ohci_writel (ohci, ohci->hc_control, &ohci->regs->control);
(void) ohci_readl (ohci, &ohci->regs->control);
msleep(val);
memset (ohci->hcca, 0, sizeof (struct ohci_hcca));
spin_lock_irq (&ohci->lock);
retry:
ohci_writel (ohci, OHCI_HCR, &ohci->regs->cmdstatus);
val = 30;
while ((ohci_readl (ohci, &ohci->regs->cmdstatus) & OHCI_HCR) != 0) {
if (--val == 0) {
spin_unlock_irq (&ohci->lock);
ohci_err (ohci, "USB HC reset timed out!\n");
return -1;
}
udelay (1);
}
if (ohci->flags & OHCI_QUIRK_INITRESET) {
ohci_writel (ohci, ohci->hc_control, &ohci->regs->control);
(void) ohci_readl (ohci, &ohci->regs->control);
}
ohci_writel (ohci, 0, &ohci->regs->ed_controlhead);
ohci_writel (ohci, 0, &ohci->regs->ed_bulkhead);
ohci_writel (ohci, (u32) ohci->hcca_dma, &ohci->regs->hcca);
periodic_reinit (ohci);
if ((ohci_readl (ohci, &ohci->regs->fminterval) & 0x3fff0000) == 0
|| !ohci_readl (ohci, &ohci->regs->periodicstart)) {
if (!(ohci->flags & OHCI_QUIRK_INITRESET)) {
ohci->flags |= OHCI_QUIRK_INITRESET;
ohci_dbg (ohci, "enabling initreset quirk\n");
goto retry;
}
spin_unlock_irq (&ohci->lock);
ohci_err (ohci, "init err (%08x %04x)\n",
ohci_readl (ohci, &ohci->regs->fminterval),
ohci_readl (ohci, &ohci->regs->periodicstart));
return -EOVERFLOW;
}
set_bit(HCD_FLAG_POLL_RH, &hcd->flags);
hcd->uses_new_polling = 1;
ohci->hc_control &= OHCI_CTRL_RWC;
ohci->hc_control |= OHCI_CONTROL_INIT | OHCI_USB_OPER;
ohci_writel (ohci, ohci->hc_control, &ohci->regs->control);
ohci->rh_state = OHCI_RH_RUNNING;
ohci_writel (ohci, RH_HS_DRWE, &ohci->regs->roothub.status);
mask = OHCI_INTR_INIT;
ohci_writel (ohci, ~0, &ohci->regs->intrstatus);
ohci_writel (ohci, mask, &ohci->regs->intrenable);
val = roothub_a (ohci);
val &= ~(RH_A_PSM | RH_A_OCPM);
if (ohci->flags & OHCI_QUIRK_SUPERIO) {
val |= RH_A_NOCP;
val &= ~(RH_A_POTPGT | RH_A_NPS);
ohci_writel (ohci, val, &ohci->regs->roothub.a);
} else if ((ohci->flags & OHCI_QUIRK_AMD756) ||
(ohci->flags & OHCI_QUIRK_HUB_POWER)) {
val |= RH_A_NPS;
ohci_writel (ohci, val, &ohci->regs->roothub.a);
}
ohci_writel (ohci, RH_HS_LPSC, &ohci->regs->roothub.status);
ohci_writel (ohci, (val & RH_A_NPS) ? 0 : RH_B_PPCM,
&ohci->regs->roothub.b);
(void) ohci_readl (ohci, &ohci->regs->control);
ohci->next_statechange = jiffies + STATECHANGE_DELAY;
spin_unlock_irq (&ohci->lock);
mdelay ((val >> 23) & 0x1fe);
ohci_dump(ohci);
return 0;
}
int ohci_setup(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
ohci_hcd_init(ohci);
return ohci_init(ohci);
}
static int ohci_start(struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int ret;
ret = ohci_run(ohci);
if (ret < 0) {
ohci_err(ohci, "can't start\n");
ohci_stop(hcd);
}
return ret;
}
static void io_watchdog_func(unsigned long _ohci)
{
struct ohci_hcd *ohci = (struct ohci_hcd *) _ohci;
bool takeback_all_pending = false;
u32 status;
u32 head;
struct ed *ed;
struct td *td, *td_start, *td_next;
unsigned frame_no;
unsigned long flags;
spin_lock_irqsave(&ohci->lock, flags);
status = ohci_readl(ohci, &ohci->regs->intrstatus);
if (!(status & OHCI_INTR_WDH) && ohci->wdh_cnt == ohci->prev_wdh_cnt) {
if (ohci->prev_donehead) {
ohci_err(ohci, "HcDoneHead not written back; disabled\n");
died:
usb_hc_died(ohci_to_hcd(ohci));
ohci_dump(ohci);
ohci_shutdown(ohci_to_hcd(ohci));
goto done;
} else {
takeback_all_pending = true;
}
}
list_for_each_entry(ed, &ohci->eds_in_use, in_use_list) {
if (ed->pending_td) {
if (takeback_all_pending ||
OKAY_TO_TAKEBACK(ohci, ed)) {
unsigned tmp = hc32_to_cpu(ohci, ed->hwINFO);
ohci_dbg(ohci, "takeback pending TD for dev %d ep 0x%x\n",
0x007f & tmp,
(0x000f & (tmp >> 7)) +
((tmp & ED_IN) >> 5));
add_to_done_list(ohci, ed->pending_td);
}
}
td = ed->pending_td;
if (!td) {
list_for_each_entry(td_next, &ed->td_list, td_list) {
if (!td_next->next_dl_td)
break;
td = td_next;
}
}
head = hc32_to_cpu(ohci, ACCESS_ONCE(ed->hwHeadP)) & TD_MASK;
td_start = td;
td_next = list_prepare_entry(td, &ed->td_list, td_list);
list_for_each_entry_continue(td_next, &ed->td_list, td_list) {
if (head == (u32) td_next->td_dma)
break;
td = td_next;
}
if (td != td_start) {
ed->takeback_wdh_cnt = ohci->wdh_cnt + 2;
ed->pending_td = td;
}
}
ohci_work(ohci);
if (ohci->rh_state == OHCI_RH_RUNNING) {
frame_no = ohci_frame_no(ohci);
if (frame_no == ohci->prev_frame_no) {
int active_cnt = 0;
int i;
unsigned tmp;
for (i = 0; i < ohci->num_ports; ++i) {
tmp = roothub_portstatus(ohci, i);
if ((tmp & RH_PS_PES) && !(tmp & RH_PS_PSS))
++active_cnt;
}
if (active_cnt > 0) {
ohci_err(ohci, "frame counter not updating; disabled\n");
goto died;
}
}
if (!list_empty(&ohci->eds_in_use)) {
ohci->prev_frame_no = frame_no;
ohci->prev_wdh_cnt = ohci->wdh_cnt;
ohci->prev_donehead = ohci_readl(ohci,
&ohci->regs->donehead);
mod_timer(&ohci->io_watchdog,
jiffies + IO_WATCHDOG_DELAY);
}
}
done:
spin_unlock_irqrestore(&ohci->lock, flags);
}
static irqreturn_t ohci_irq (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
struct ohci_regs __iomem *regs = ohci->regs;
int ints;
ints = ohci_readl(ohci, &regs->intrstatus);
if (ints == ~(u32)0) {
ohci->rh_state = OHCI_RH_HALTED;
ohci_dbg (ohci, "device removed!\n");
usb_hc_died(hcd);
return IRQ_HANDLED;
}
ints &= ohci_readl(ohci, &regs->intrenable);
if (ints == 0 || unlikely(ohci->rh_state == OHCI_RH_HALTED))
return IRQ_NOTMINE;
if (ints & OHCI_INTR_UE) {
if (quirk_nec(ohci)) {
ohci_err (ohci, "OHCI Unrecoverable Error, scheduling NEC chip restart\n");
ohci_writel (ohci, OHCI_INTR_UE, &regs->intrdisable);
schedule_work (&ohci->nec_work);
} else {
ohci_err (ohci, "OHCI Unrecoverable Error, disabled\n");
ohci->rh_state = OHCI_RH_HALTED;
usb_hc_died(hcd);
}
ohci_dump(ohci);
ohci_usb_reset (ohci);
}
if (ints & OHCI_INTR_RHSC) {
ohci_dbg(ohci, "rhsc\n");
ohci->next_statechange = jiffies + STATECHANGE_DELAY;
ohci_writel(ohci, OHCI_INTR_RD | OHCI_INTR_RHSC,
&regs->intrstatus);
ohci_writel(ohci, OHCI_INTR_RHSC, &regs->intrdisable);
usb_hcd_poll_rh_status(hcd);
}
else if (ints & OHCI_INTR_RD) {
ohci_dbg(ohci, "resume detect\n");
ohci_writel(ohci, OHCI_INTR_RD, &regs->intrstatus);
set_bit(HCD_FLAG_POLL_RH, &hcd->flags);
if (ohci->autostop) {
spin_lock (&ohci->lock);
ohci_rh_resume (ohci);
spin_unlock (&ohci->lock);
} else
usb_hcd_resume_root_hub(hcd);
}
spin_lock(&ohci->lock);
if (ints & OHCI_INTR_WDH)
update_done_list(ohci);
ohci_work(ohci);
if ((ints & OHCI_INTR_SF) != 0 && !ohci->ed_rm_list
&& ohci->rh_state == OHCI_RH_RUNNING)
ohci_writel (ohci, OHCI_INTR_SF, &regs->intrdisable);
if (ohci->rh_state == OHCI_RH_RUNNING) {
ohci_writel (ohci, ints, &regs->intrstatus);
if (ints & OHCI_INTR_WDH)
++ohci->wdh_cnt;
ohci_writel (ohci, OHCI_INTR_MIE, &regs->intrenable);
(void) ohci_readl (ohci, &ohci->regs->control);
}
spin_unlock(&ohci->lock);
return IRQ_HANDLED;
}
static void ohci_stop (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
ohci_dump(ohci);
if (quirk_nec(ohci))
flush_work(&ohci->nec_work);
del_timer_sync(&ohci->io_watchdog);
ohci_writel (ohci, OHCI_INTR_MIE, &ohci->regs->intrdisable);
ohci_usb_reset(ohci);
free_irq(hcd->irq, hcd);
hcd->irq = 0;
if (quirk_amdiso(ohci))
usb_amd_dev_put();
remove_debug_files (ohci);
ohci_mem_cleanup (ohci);
if (ohci->hcca) {
dma_free_coherent (hcd->self.controller,
sizeof *ohci->hcca,
ohci->hcca, ohci->hcca_dma);
ohci->hcca = NULL;
ohci->hcca_dma = 0;
}
}
int ohci_restart(struct ohci_hcd *ohci)
{
int temp;
int i;
struct urb_priv *priv;
ohci_init(ohci);
spin_lock_irq(&ohci->lock);
ohci->rh_state = OHCI_RH_HALTED;
if (!list_empty (&ohci->pending))
ohci_dbg(ohci, "abort schedule...\n");
list_for_each_entry (priv, &ohci->pending, pending) {
struct urb *urb = priv->td[0]->urb;
struct ed *ed = priv->ed;
switch (ed->state) {
case ED_OPER:
ed->state = ED_UNLINK;
ed->hwINFO |= cpu_to_hc32(ohci, ED_DEQUEUE);
ed_deschedule (ohci, ed);
ed->ed_next = ohci->ed_rm_list;
ed->ed_prev = NULL;
ohci->ed_rm_list = ed;
case ED_UNLINK:
break;
default:
ohci_dbg(ohci, "bogus ed %p state %d\n",
ed, ed->state);
}
if (!urb->unlinked)
urb->unlinked = -ESHUTDOWN;
}
ohci_work(ohci);
spin_unlock_irq(&ohci->lock);
for (i = 0; i < NUM_INTS; i++) ohci->load [i] = 0;
for (i = 0; i < NUM_INTS; i++) ohci->hcca->int_table [i] = 0;
ohci->ed_rm_list = NULL;
ohci->ed_controltail = NULL;
ohci->ed_bulktail = NULL;
if ((temp = ohci_run (ohci)) < 0) {
ohci_err (ohci, "can't restart, %d\n", temp);
return temp;
}
ohci_dbg(ohci, "restart complete\n");
return 0;
}
int ohci_suspend(struct usb_hcd *hcd, bool do_wakeup)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
unsigned long flags;
int rc = 0;
spin_lock_irqsave (&ohci->lock, flags);
ohci_writel(ohci, OHCI_INTR_MIE, &ohci->regs->intrdisable);
(void)ohci_readl(ohci, &ohci->regs->intrdisable);
clear_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
spin_unlock_irqrestore (&ohci->lock, flags);
synchronize_irq(hcd->irq);
if (do_wakeup && HCD_WAKEUP_PENDING(hcd)) {
ohci_resume(hcd, false);
rc = -EBUSY;
}
return rc;
}
int ohci_resume(struct usb_hcd *hcd, bool hibernated)
{
struct ohci_hcd *ohci = hcd_to_ohci(hcd);
int port;
bool need_reinit = false;
set_bit(HCD_FLAG_HW_ACCESSIBLE, &hcd->flags);
if (hibernated)
ohci_usb_reset(ohci);
ohci->hc_control = ohci_readl(ohci, &ohci->regs->control);
if (ohci->hc_control & (OHCI_CTRL_IR | OHCI_SCHED_ENABLES)) {
need_reinit = true;
} else {
switch (ohci->hc_control & OHCI_CTRL_HCFS) {
case OHCI_USB_OPER:
case OHCI_USB_RESET:
need_reinit = true;
}
}
if (need_reinit) {
spin_lock_irq(&ohci->lock);
ohci_rh_resume(ohci);
ohci_rh_suspend(ohci, 0);
spin_unlock_irq(&ohci->lock);
}
else {
ohci_dbg(ohci, "powerup ports\n");
for (port = 0; port < ohci->num_ports; port++)
ohci_writel(ohci, RH_PS_PPS,
&ohci->regs->roothub.portstatus[port]);
ohci_writel(ohci, OHCI_INTR_MIE, &ohci->regs->intrenable);
ohci_readl(ohci, &ohci->regs->intrenable);
msleep(20);
}
usb_hcd_resume_root_hub(hcd);
return 0;
}
void ohci_init_driver(struct hc_driver *drv,
const struct ohci_driver_overrides *over)
{
*drv = ohci_hc_driver;
if (over) {
drv->product_desc = over->product_desc;
drv->hcd_priv_size += over->extra_priv_size;
if (over->reset)
drv->reset = over->reset;
}
}
static int __init ohci_hcd_mod_init(void)
{
int retval = 0;
if (usb_disabled())
return -ENODEV;
printk(KERN_INFO "%s: " DRIVER_DESC "\n", hcd_name);
pr_debug ("%s: block sizes: ed %Zd td %Zd\n", hcd_name,
sizeof (struct ed), sizeof (struct td));
set_bit(USB_OHCI_LOADED, &usb_hcds_loaded);
ohci_debug_root = debugfs_create_dir("ohci", usb_debug_root);
if (!ohci_debug_root) {
retval = -ENOENT;
goto error_debug;
}
#ifdef PS3_SYSTEM_BUS_DRIVER
retval = ps3_ohci_driver_register(&PS3_SYSTEM_BUS_DRIVER);
if (retval < 0)
goto error_ps3;
#endif
#ifdef PLATFORM_DRIVER
retval = platform_driver_register(&PLATFORM_DRIVER);
if (retval < 0)
goto error_platform;
#endif
#ifdef OF_PLATFORM_DRIVER
retval = platform_driver_register(&OF_PLATFORM_DRIVER);
if (retval < 0)
goto error_of_platform;
#endif
#ifdef SA1111_DRIVER
retval = sa1111_driver_register(&SA1111_DRIVER);
if (retval < 0)
goto error_sa1111;
#endif
#ifdef SM501_OHCI_DRIVER
retval = platform_driver_register(&SM501_OHCI_DRIVER);
if (retval < 0)
goto error_sm501;
#endif
#ifdef TMIO_OHCI_DRIVER
retval = platform_driver_register(&TMIO_OHCI_DRIVER);
if (retval < 0)
goto error_tmio;
#endif
return retval;
#ifdef TMIO_OHCI_DRIVER
platform_driver_unregister(&TMIO_OHCI_DRIVER);
error_tmio:
#endif
#ifdef SM501_OHCI_DRIVER
platform_driver_unregister(&SM501_OHCI_DRIVER);
error_sm501:
#endif
#ifdef SA1111_DRIVER
sa1111_driver_unregister(&SA1111_DRIVER);
error_sa1111:
#endif
#ifdef OF_PLATFORM_DRIVER
platform_driver_unregister(&OF_PLATFORM_DRIVER);
error_of_platform:
#endif
#ifdef PLATFORM_DRIVER
platform_driver_unregister(&PLATFORM_DRIVER);
error_platform:
#endif
#ifdef PS3_SYSTEM_BUS_DRIVER
ps3_ohci_driver_unregister(&PS3_SYSTEM_BUS_DRIVER);
error_ps3:
#endif
debugfs_remove(ohci_debug_root);
ohci_debug_root = NULL;
error_debug:
clear_bit(USB_OHCI_LOADED, &usb_hcds_loaded);
return retval;
}
static void __exit ohci_hcd_mod_exit(void)
{
#ifdef TMIO_OHCI_DRIVER
platform_driver_unregister(&TMIO_OHCI_DRIVER);
#endif
#ifdef SM501_OHCI_DRIVER
platform_driver_unregister(&SM501_OHCI_DRIVER);
#endif
#ifdef SA1111_DRIVER
sa1111_driver_unregister(&SA1111_DRIVER);
#endif
#ifdef OF_PLATFORM_DRIVER
platform_driver_unregister(&OF_PLATFORM_DRIVER);
#endif
#ifdef PLATFORM_DRIVER
platform_driver_unregister(&PLATFORM_DRIVER);
#endif
#ifdef PS3_SYSTEM_BUS_DRIVER
ps3_ohci_driver_unregister(&PS3_SYSTEM_BUS_DRIVER);
#endif
debugfs_remove(ohci_debug_root);
clear_bit(USB_OHCI_LOADED, &usb_hcds_loaded);
}
