static inline void sb800_prefetch(struct ohci_hcd *ohci, int on)
{
return;
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
#ifdef OHCI_VERBOSE_DEBUG
urb_print(urb, "SUB", usb_pipein(pipe), -EINPROGRESS);
#endif
if (! (ed = ed_get (ohci, urb->ep, urb->dev, pipe, urb->interval)))
return -ENOMEM;
switch (ed->type) {
case PIPE_CONTROL:
if (urb->transfer_buffer_length > 4096)
return -EMSGSIZE;
size = 2;
default:
size += urb->transfer_buffer_length / 4096;
if ((urb->transfer_buffer_length % 4096) != 0)
size++;
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
if (!HC_IS_RUNNING(hcd->state)) {
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
if (ed->type == PIPE_ISOCHRONOUS) {
u16 frame = ohci_frame_no(ohci);
frame += max_t (u16, 8, ed->interval);
frame &= ~(ed->interval - 1);
frame |= ed->branch;
urb->start_frame = frame;
}
} else if (ed->type == PIPE_ISOCHRONOUS)
urb->start_frame = ed->last_iso + ed->interval;
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
#ifdef OHCI_VERBOSE_DEBUG
urb_print(urb, "UNLINK", 1, status);
#endif
spin_lock_irqsave (&ohci->lock, flags);
rc = usb_hcd_check_unlink_urb(hcd, urb, status);
if (rc) {
;
} else if (HC_IS_RUNNING(hcd->state)) {
urb_priv_t *urb_priv;
urb_priv = urb->hcpriv;
if (urb_priv) {
if (urb_priv->ed->state == ED_OPER)
start_ed_unlink (ohci, urb_priv->ed);
}
} else {
if (urb->hcpriv)
finish_urb(ohci, urb, status);
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
if (!HC_IS_RUNNING (hcd->state)) {
sanitize:
ed->state = ED_IDLE;
if (quirk_zfmicro(ohci) && ed->type == PIPE_INTERRUPT)
ohci->eds_scheduled--;
finish_unlinks (ohci, 0);
}
switch (ed->state) {
case ED_UNLINK:
if (limit-- == 0) {
ohci_warn(ohci, "ED unlink timeout\n");
if (quirk_zfmicro(ohci)) {
ohci_warn(ohci, "Attempting ZF TD recovery\n");
ohci->ed_to_check = ed;
ohci->zf_delay = 2;
}
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
}
static void
ohci_shutdown (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci;
ohci = hcd_to_ohci (hcd);
ohci_writel (ohci, OHCI_INTR_MIE, &ohci->regs->intrdisable);
ohci->hc_control = ohci_readl(ohci, &ohci->regs->control);
ohci->hc_control &= (ohci->flags & OHCI_QUIRK_SHUTDOWN ?
OHCI_CTRL_RWC | OHCI_CTRL_HCFS :
OHCI_CTRL_RWC);
ohci_writel(ohci, ohci->hc_control, &ohci->regs->control);
(void) ohci_readl (ohci, &ohci->regs->control);
}
static int check_ed(struct ohci_hcd *ohci, struct ed *ed)
{
return (hc32_to_cpu(ohci, ed->hwINFO) & ED_IN) != 0
&& (hc32_to_cpu(ohci, ed->hwHeadP) & TD_MASK)
== (hc32_to_cpu(ohci, ed->hwTailP) & TD_MASK)
&& !list_empty(&ed->td_list);
}
static void unlink_watchdog_func(unsigned long _ohci)
{
unsigned long flags;
unsigned max;
unsigned seen_count = 0;
unsigned i;
struct ed **seen = NULL;
struct ohci_hcd *ohci = (struct ohci_hcd *) _ohci;
spin_lock_irqsave(&ohci->lock, flags);
max = ohci->eds_scheduled;
if (!max)
goto done;
if (ohci->ed_to_check)
goto out;
seen = kcalloc(max, sizeof *seen, GFP_ATOMIC);
if (!seen)
goto out;
for (i = 0; i < NUM_INTS; i++) {
struct ed *ed = ohci->periodic[i];
while (ed) {
unsigned temp;
for (temp = 0; temp < seen_count; temp++) {
if (seen[temp] == ed) {
ed = NULL;
break;
}
}
if (!ed)
break;
seen[seen_count++] = ed;
if (!check_ed(ohci, ed)) {
ed = ed->ed_next;
continue;
}
ohci->ed_to_check = ed;
ohci->zf_delay = 2;
ohci_writel(ohci, OHCI_INTR_SF,
&ohci->regs->intrstatus);
ohci_writel(ohci, OHCI_INTR_SF,
&ohci->regs->intrenable);
(void) ohci_readl(ohci, &ohci->regs->control);
goto out;
}
}
out:
kfree(seen);
if (ohci->eds_scheduled)
mod_timer(&ohci->unlink_watchdog, round_jiffies(jiffies + HZ));
done:
spin_unlock_irqrestore(&ohci->lock, flags);
}
static int ohci_init (struct ohci_hcd *ohci)
{
int ret;
struct usb_hcd *hcd = ohci_to_hcd(ohci);
if (distrust_firmware)
ohci->flags |= OHCI_QUIRK_HUB_POWER;
disable (ohci);
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
ohci->hcca = dma_alloc_coherent (hcd->self.controller,
sizeof *ohci->hcca, &ohci->hcca_dma, 0);
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
disable (ohci);
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
hcd->state = HC_STATE_RUNNING;
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
hcd->state = HC_STATE_RUNNING;
if (quirk_zfmicro(ohci)) {
setup_timer(&ohci->unlink_watchdog, unlink_watchdog_func,
(unsigned long) ohci);
ohci->eds_scheduled = 0;
ohci->ed_to_check = NULL;
}
ohci_dump (ohci, 1);
return 0;
}
static irqreturn_t ohci_irq (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
struct ohci_regs __iomem *regs = ohci->regs;
int ints;
ints = ohci_readl(ohci, &regs->intrstatus);
if (ints == ~(u32)0) {
disable (ohci);
ohci_dbg (ohci, "device removed!\n");
usb_hc_died(hcd);
return IRQ_HANDLED;
}
ints &= ohci_readl(ohci, &regs->intrenable);
if (ints == 0 || unlikely(hcd->state == HC_STATE_HALT))
return IRQ_NOTMINE;
if (ints & OHCI_INTR_UE) {
if (quirk_nec(ohci)) {
ohci_err (ohci, "OHCI Unrecoverable Error, scheduling NEC chip restart\n");
ohci_writel (ohci, OHCI_INTR_UE, &regs->intrdisable);
schedule_work (&ohci->nec_work);
} else {
disable (ohci);
ohci_err (ohci, "OHCI Unrecoverable Error, disabled\n");
usb_hc_died(hcd);
}
ohci_dump (ohci, 1);
ohci_usb_reset (ohci);
}
if (ints & OHCI_INTR_RHSC) {
ohci_vdbg(ohci, "rhsc\n");
ohci->next_statechange = jiffies + STATECHANGE_DELAY;
ohci_writel(ohci, OHCI_INTR_RD | OHCI_INTR_RHSC,
&regs->intrstatus);
ohci_writel(ohci, OHCI_INTR_RHSC, &regs->intrdisable);
usb_hcd_poll_rh_status(hcd);
}
else if (ints & OHCI_INTR_RD) {
ohci_vdbg(ohci, "resume detect\n");
ohci_writel(ohci, OHCI_INTR_RD, &regs->intrstatus);
set_bit(HCD_FLAG_POLL_RH, &hcd->flags);
if (ohci->autostop) {
spin_lock (&ohci->lock);
ohci_rh_resume (ohci);
spin_unlock (&ohci->lock);
} else
usb_hcd_resume_root_hub(hcd);
}
if (ints & OHCI_INTR_WDH) {
spin_lock (&ohci->lock);
dl_done_list (ohci);
spin_unlock (&ohci->lock);
}
if (quirk_zfmicro(ohci) && (ints & OHCI_INTR_SF)) {
spin_lock(&ohci->lock);
if (ohci->ed_to_check) {
struct ed *ed = ohci->ed_to_check;
if (check_ed(ohci, ed)) {
if (--ohci->zf_delay == 0) {
struct td *td = list_entry(
ed->td_list.next,
struct td, td_list);
ohci_warn(ohci,
"Reclaiming orphan TD %p\n",
td);
takeback_td(ohci, td);
ohci->ed_to_check = NULL;
}
} else
ohci->ed_to_check = NULL;
}
spin_unlock(&ohci->lock);
}
spin_lock (&ohci->lock);
if (ohci->ed_rm_list)
finish_unlinks (ohci, ohci_frame_no(ohci));
if ((ints & OHCI_INTR_SF) != 0
&& !ohci->ed_rm_list
&& !ohci->ed_to_check
&& HC_IS_RUNNING(hcd->state))
ohci_writel (ohci, OHCI_INTR_SF, &regs->intrdisable);
spin_unlock (&ohci->lock);
if (HC_IS_RUNNING(hcd->state)) {
ohci_writel (ohci, ints, &regs->intrstatus);
ohci_writel (ohci, OHCI_INTR_MIE, &regs->intrenable);
(void) ohci_readl (ohci, &ohci->regs->control);
}
return IRQ_HANDLED;
}
static void ohci_stop (struct usb_hcd *hcd)
{
struct ohci_hcd *ohci = hcd_to_ohci (hcd);
ohci_dump (ohci, 1);
if (quirk_nec(ohci))
flush_work_sync(&ohci->nec_work);
ohci_usb_reset (ohci);
ohci_writel (ohci, OHCI_INTR_MIE, &ohci->regs->intrdisable);
free_irq(hcd->irq, hcd);
hcd->irq = -1;
if (quirk_zfmicro(ohci))
del_timer(&ohci->unlink_watchdog);
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
static int ohci_restart (struct ohci_hcd *ohci)
{
int temp;
int i;
struct urb_priv *priv;
spin_lock_irq(&ohci->lock);
disable (ohci);
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
finish_unlinks (ohci, 0);
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
static int __init ohci_hcd_mod_init(void)
{
int retval = 0;
if (usb_disabled())
return -ENODEV;
printk(KERN_INFO "%s: " DRIVER_DESC "\n", hcd_name);
pr_debug ("%s: block sizes: ed %Zd td %Zd\n", hcd_name,
sizeof (struct ed), sizeof (struct td));
set_bit(USB_OHCI_LOADED, &usb_hcds_loaded);
#ifdef DEBUG
ohci_debug_root = debugfs_create_dir("ohci", usb_debug_root);
if (!ohci_debug_root) {
retval = -ENOENT;
goto error_debug;
}
#endif
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
#ifdef OMAP1_PLATFORM_DRIVER
retval = platform_driver_register(&OMAP1_PLATFORM_DRIVER);
if (retval < 0)
goto error_omap1_platform;
#endif
#ifdef OMAP3_PLATFORM_DRIVER
retval = platform_driver_register(&OMAP3_PLATFORM_DRIVER);
if (retval < 0)
goto error_omap3_platform;
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
#ifdef PCI_DRIVER
retval = pci_register_driver(&PCI_DRIVER);
if (retval < 0)
goto error_pci;
#endif
#ifdef SSB_OHCI_DRIVER
retval = ssb_driver_register(&SSB_OHCI_DRIVER);
if (retval)
goto error_ssb;
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
#ifdef SSB_OHCI_DRIVER
ssb_driver_unregister(&SSB_OHCI_DRIVER);
error_ssb:
#endif
#ifdef PCI_DRIVER
pci_unregister_driver(&PCI_DRIVER);
error_pci:
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
#ifdef OMAP1_PLATFORM_DRIVER
platform_driver_unregister(&OMAP1_PLATFORM_DRIVER);
error_omap1_platform:
#endif
#ifdef OMAP3_PLATFORM_DRIVER
platform_driver_unregister(&OMAP3_PLATFORM_DRIVER);
error_omap3_platform:
#endif
#ifdef PS3_SYSTEM_BUS_DRIVER
ps3_ohci_driver_unregister(&PS3_SYSTEM_BUS_DRIVER);
error_ps3:
#endif
#ifdef DEBUG
debugfs_remove(ohci_debug_root);
ohci_debug_root = NULL;
error_debug:
#endif
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
#ifdef SSB_OHCI_DRIVER
ssb_driver_unregister(&SSB_OHCI_DRIVER);
#endif
#ifdef PCI_DRIVER
pci_unregister_driver(&PCI_DRIVER);
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
#ifdef OMAP3_PLATFORM_DRIVER
platform_driver_unregister(&OMAP3_PLATFORM_DRIVER);
#endif
#ifdef PS3_SYSTEM_BUS_DRIVER
ps3_ohci_driver_unregister(&PS3_SYSTEM_BUS_DRIVER);
#endif
#ifdef DEBUG
debugfs_remove(ohci_debug_root);
#endif
clear_bit(USB_OHCI_LOADED, &usb_hcds_loaded);
}
