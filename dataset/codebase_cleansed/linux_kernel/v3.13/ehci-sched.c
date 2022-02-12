static union ehci_shadow *
periodic_next_shadow(struct ehci_hcd *ehci, union ehci_shadow *periodic,
__hc32 tag)
{
switch (hc32_to_cpu(ehci, tag)) {
case Q_TYPE_QH:
return &periodic->qh->qh_next;
case Q_TYPE_FSTN:
return &periodic->fstn->fstn_next;
case Q_TYPE_ITD:
return &periodic->itd->itd_next;
default:
return &periodic->sitd->sitd_next;
}
}
static __hc32 *
shadow_next_periodic(struct ehci_hcd *ehci, union ehci_shadow *periodic,
__hc32 tag)
{
switch (hc32_to_cpu(ehci, tag)) {
case Q_TYPE_QH:
return &periodic->qh->hw->hw_next;
default:
return periodic->hw_next;
}
}
static void periodic_unlink (struct ehci_hcd *ehci, unsigned frame, void *ptr)
{
union ehci_shadow *prev_p = &ehci->pshadow[frame];
__hc32 *hw_p = &ehci->periodic[frame];
union ehci_shadow here = *prev_p;
while (here.ptr && here.ptr != ptr) {
prev_p = periodic_next_shadow(ehci, prev_p,
Q_NEXT_TYPE(ehci, *hw_p));
hw_p = shadow_next_periodic(ehci, &here,
Q_NEXT_TYPE(ehci, *hw_p));
here = *prev_p;
}
if (!here.ptr)
return;
*prev_p = *periodic_next_shadow(ehci, &here,
Q_NEXT_TYPE(ehci, *hw_p));
if (!ehci->use_dummy_qh ||
*shadow_next_periodic(ehci, &here, Q_NEXT_TYPE(ehci, *hw_p))
!= EHCI_LIST_END(ehci))
*hw_p = *shadow_next_periodic(ehci, &here,
Q_NEXT_TYPE(ehci, *hw_p));
else
*hw_p = cpu_to_hc32(ehci, ehci->dummy->qh_dma);
}
static struct ehci_tt *find_tt(struct usb_device *udev)
{
struct usb_tt *utt = udev->tt;
struct ehci_tt *tt, **tt_index, **ptt;
unsigned port;
bool allocated_index = false;
if (!utt)
return NULL;
tt_index = NULL;
if (utt->multi) {
tt_index = utt->hcpriv;
if (!tt_index) {
tt_index = kzalloc(utt->hub->maxchild *
sizeof(*tt_index), GFP_ATOMIC);
if (!tt_index)
return ERR_PTR(-ENOMEM);
utt->hcpriv = tt_index;
allocated_index = true;
}
port = udev->ttport - 1;
ptt = &tt_index[port];
} else {
port = 0;
ptt = (struct ehci_tt **) &utt->hcpriv;
}
tt = *ptt;
if (!tt) {
struct ehci_hcd *ehci =
hcd_to_ehci(bus_to_hcd(udev->bus));
tt = kzalloc(sizeof(*tt), GFP_ATOMIC);
if (!tt) {
if (allocated_index) {
utt->hcpriv = NULL;
kfree(tt_index);
}
return ERR_PTR(-ENOMEM);
}
list_add_tail(&tt->tt_list, &ehci->tt_list);
INIT_LIST_HEAD(&tt->ps_list);
tt->usb_tt = utt;
tt->tt_port = port;
*ptt = tt;
}
return tt;
}
static void drop_tt(struct usb_device *udev)
{
struct usb_tt *utt = udev->tt;
struct ehci_tt *tt, **tt_index, **ptt;
int cnt, i;
if (!utt || !utt->hcpriv)
return;
cnt = 0;
if (utt->multi) {
tt_index = utt->hcpriv;
ptt = &tt_index[udev->ttport - 1];
for (i = 0; i < utt->hub->maxchild; ++i)
cnt += !!tt_index[i];
} else {
tt_index = NULL;
ptt = (struct ehci_tt **) &utt->hcpriv;
}
tt = *ptt;
if (!tt || !list_empty(&tt->ps_list))
return;
list_del(&tt->tt_list);
*ptt = NULL;
kfree(tt);
if (cnt == 1) {
utt->hcpriv = NULL;
kfree(tt_index);
}
}
static void bandwidth_dbg(struct ehci_hcd *ehci, int sign, char *type,
struct ehci_per_sched *ps)
{
dev_dbg(&ps->udev->dev,
"ep %02x: %s %s @ %u+%u (%u.%u+%u) [%u/%u us] mask %04x\n",
ps->ep->desc.bEndpointAddress,
(sign >= 0 ? "reserve" : "release"), type,
(ps->bw_phase << 3) + ps->phase_uf, ps->bw_uperiod,
ps->phase, ps->phase_uf, ps->period,
ps->usecs, ps->c_usecs, ps->cs_mask);
}
static void reserve_release_intr_bandwidth(struct ehci_hcd *ehci,
struct ehci_qh *qh, int sign)
{
unsigned start_uf;
unsigned i, j, m;
int usecs = qh->ps.usecs;
int c_usecs = qh->ps.c_usecs;
int tt_usecs = qh->ps.tt_usecs;
struct ehci_tt *tt;
if (qh->ps.phase == NO_FRAME)
return;
start_uf = qh->ps.bw_phase << 3;
bandwidth_dbg(ehci, sign, "intr", &qh->ps);
if (sign < 0) {
usecs = -usecs;
c_usecs = -c_usecs;
tt_usecs = -tt_usecs;
}
for (i = start_uf + qh->ps.phase_uf; i < EHCI_BANDWIDTH_SIZE;
i += qh->ps.bw_uperiod)
ehci->bandwidth[i] += usecs;
if (qh->ps.c_usecs) {
for (i = start_uf; i < EHCI_BANDWIDTH_SIZE;
i += qh->ps.bw_uperiod) {
for ((j = 2, m = 1 << (j+8)); j < 8; (++j, m <<= 1)) {
if (qh->ps.cs_mask & m)
ehci->bandwidth[i+j] += c_usecs;
}
}
}
if (tt_usecs) {
tt = find_tt(qh->ps.udev);
if (sign > 0)
list_add_tail(&qh->ps.ps_list, &tt->ps_list);
else
list_del(&qh->ps.ps_list);
for (i = start_uf >> 3; i < EHCI_BANDWIDTH_FRAMES;
i += qh->ps.bw_period)
tt->bandwidth[i] += tt_usecs;
}
}
static void compute_tt_budget(u8 budget_table[EHCI_BANDWIDTH_SIZE],
struct ehci_tt *tt)
{
struct ehci_per_sched *ps;
unsigned uframe, uf, x;
u8 *budget_line;
if (!tt)
return;
memset(budget_table, 0, EHCI_BANDWIDTH_SIZE);
list_for_each_entry(ps, &tt->ps_list, ps_list) {
for (uframe = ps->bw_phase << 3; uframe < EHCI_BANDWIDTH_SIZE;
uframe += ps->bw_uperiod) {
budget_line = &budget_table[uframe];
x = ps->tt_usecs;
for (uf = ps->phase_uf; uf < 8; ++uf) {
x += budget_line[uf];
if (x <= 125) {
budget_line[uf] = x;
break;
} else {
budget_line[uf] = 125;
x -= 125;
}
}
}
}
}
static int __maybe_unused same_tt(struct usb_device *dev1,
struct usb_device *dev2)
{
if (!dev1->tt || !dev2->tt)
return 0;
if (dev1->tt != dev2->tt)
return 0;
if (dev1->tt->multi)
return dev1->ttport == dev2->ttport;
else
return 1;
}
static inline unsigned char tt_start_uframe(struct ehci_hcd *ehci, __hc32 mask)
{
unsigned char smask = QH_SMASK & hc32_to_cpu(ehci, mask);
if (!smask) {
ehci_err(ehci, "invalid empty smask!\n");
return 7;
}
return ffs(smask) - 1;
}
static inline void carryover_tt_bandwidth(unsigned short tt_usecs[8])
{
int i;
for (i=0; i<7; i++) {
if (max_tt_usecs[i] < tt_usecs[i]) {
tt_usecs[i+1] += tt_usecs[i] - max_tt_usecs[i];
tt_usecs[i] = max_tt_usecs[i];
}
}
}
static int tt_available (
struct ehci_hcd *ehci,
struct ehci_per_sched *ps,
struct ehci_tt *tt,
unsigned frame,
unsigned uframe
)
{
unsigned period = ps->bw_period;
unsigned usecs = ps->tt_usecs;
if ((period == 0) || (uframe >= 7))
return 0;
for (frame &= period - 1; frame < EHCI_BANDWIDTH_FRAMES;
frame += period) {
unsigned i, uf;
unsigned short tt_usecs[8];
if (tt->bandwidth[frame] + usecs > 900)
return 0;
uf = frame << 3;
for (i = 0; i < 8; (++i, ++uf))
tt_usecs[i] = ehci->tt_budget[uf];
if (max_tt_usecs[uframe] <= tt_usecs[uframe])
return 0;
if (125 < usecs) {
int ufs = (usecs / 125);
for (i = uframe; i < (uframe + ufs) && i < 8; i++)
if (0 < tt_usecs[i])
return 0;
}
tt_usecs[uframe] += usecs;
carryover_tt_bandwidth(tt_usecs);
if (max_tt_usecs[7] < tt_usecs[7])
return 0;
}
return 1;
}
static int tt_no_collision (
struct ehci_hcd *ehci,
unsigned period,
struct usb_device *dev,
unsigned frame,
u32 uf_mask
)
{
if (period == 0)
return 0;
for (; frame < ehci->periodic_size; frame += period) {
union ehci_shadow here;
__hc32 type;
struct ehci_qh_hw *hw;
here = ehci->pshadow [frame];
type = Q_NEXT_TYPE(ehci, ehci->periodic [frame]);
while (here.ptr) {
switch (hc32_to_cpu(ehci, type)) {
case Q_TYPE_ITD:
type = Q_NEXT_TYPE(ehci, here.itd->hw_next);
here = here.itd->itd_next;
continue;
case Q_TYPE_QH:
hw = here.qh->hw;
if (same_tt(dev, here.qh->ps.udev)) {
u32 mask;
mask = hc32_to_cpu(ehci,
hw->hw_info2);
mask |= mask >> 8;
if (mask & uf_mask)
break;
}
type = Q_NEXT_TYPE(ehci, hw->hw_next);
here = here.qh->qh_next;
continue;
case Q_TYPE_SITD:
if (same_tt (dev, here.sitd->urb->dev)) {
u16 mask;
mask = hc32_to_cpu(ehci, here.sitd
->hw_uframe);
mask |= mask >> 8;
if (mask & uf_mask)
break;
}
type = Q_NEXT_TYPE(ehci, here.sitd->hw_next);
here = here.sitd->sitd_next;
continue;
default:
ehci_dbg (ehci,
"periodic frame %d bogus type %d\n",
frame, type);
}
return 0;
}
}
return 1;
}
static void enable_periodic(struct ehci_hcd *ehci)
{
if (ehci->periodic_count++)
return;
ehci->enabled_hrtimer_events &= ~BIT(EHCI_HRTIMER_DISABLE_PERIODIC);
ehci_poll_PSS(ehci);
turn_on_io_watchdog(ehci);
}
static void disable_periodic(struct ehci_hcd *ehci)
{
if (--ehci->periodic_count)
return;
ehci_poll_PSS(ehci);
}
static void qh_link_periodic(struct ehci_hcd *ehci, struct ehci_qh *qh)
{
unsigned i;
unsigned period = qh->ps.period;
dev_dbg(&qh->ps.udev->dev,
"link qh%d-%04x/%p start %d [%d/%d us]\n",
period, hc32_to_cpup(ehci, &qh->hw->hw_info2)
& (QH_CMASK | QH_SMASK),
qh, qh->ps.phase, qh->ps.usecs, qh->ps.c_usecs);
if (period == 0)
period = 1;
for (i = qh->ps.phase; i < ehci->periodic_size; i += period) {
union ehci_shadow *prev = &ehci->pshadow[i];
__hc32 *hw_p = &ehci->periodic[i];
union ehci_shadow here = *prev;
__hc32 type = 0;
while (here.ptr) {
type = Q_NEXT_TYPE(ehci, *hw_p);
if (type == cpu_to_hc32(ehci, Q_TYPE_QH))
break;
prev = periodic_next_shadow(ehci, prev, type);
hw_p = shadow_next_periodic(ehci, &here, type);
here = *prev;
}
while (here.ptr && qh != here.qh) {
if (qh->ps.period > here.qh->ps.period)
break;
prev = &here.qh->qh_next;
hw_p = &here.qh->hw->hw_next;
here = *prev;
}
if (qh != here.qh) {
qh->qh_next = here;
if (here.qh)
qh->hw->hw_next = *hw_p;
wmb ();
prev->qh = qh;
*hw_p = QH_NEXT (ehci, qh->qh_dma);
}
}
qh->qh_state = QH_STATE_LINKED;
qh->xacterrs = 0;
qh->exception = 0;
ehci_to_hcd(ehci)->self.bandwidth_allocated += qh->ps.bw_period
? ((qh->ps.usecs + qh->ps.c_usecs) / qh->ps.bw_period)
: (qh->ps.usecs * 8);
list_add(&qh->intr_node, &ehci->intr_qh_list);
++ehci->intr_count;
enable_periodic(ehci);
}
static void qh_unlink_periodic(struct ehci_hcd *ehci, struct ehci_qh *qh)
{
unsigned i;
unsigned period;
period = qh->ps.period ? : 1;
for (i = qh->ps.phase; i < ehci->periodic_size; i += period)
periodic_unlink (ehci, i, qh);
ehci_to_hcd(ehci)->self.bandwidth_allocated -= qh->ps.bw_period
? ((qh->ps.usecs + qh->ps.c_usecs) / qh->ps.bw_period)
: (qh->ps.usecs * 8);
dev_dbg(&qh->ps.udev->dev,
"unlink qh%d-%04x/%p start %d [%d/%d us]\n",
qh->ps.period,
hc32_to_cpup(ehci, &qh->hw->hw_info2) & (QH_CMASK | QH_SMASK),
qh, qh->ps.phase, qh->ps.usecs, qh->ps.c_usecs);
qh->qh_state = QH_STATE_UNLINK;
qh->qh_next.ptr = NULL;
if (ehci->qh_scan_next == qh)
ehci->qh_scan_next = list_entry(qh->intr_node.next,
struct ehci_qh, intr_node);
list_del(&qh->intr_node);
}
static void cancel_unlink_wait_intr(struct ehci_hcd *ehci, struct ehci_qh *qh)
{
if (qh->qh_state != QH_STATE_LINKED ||
list_empty(&qh->unlink_node))
return;
list_del_init(&qh->unlink_node);
}
static void start_unlink_intr(struct ehci_hcd *ehci, struct ehci_qh *qh)
{
if (qh->qh_state != QH_STATE_LINKED)
return;
cancel_unlink_wait_intr(ehci, qh);
qh_unlink_periodic (ehci, qh);
wmb();
qh->unlink_cycle = ehci->intr_unlink_cycle;
list_add_tail(&qh->unlink_node, &ehci->intr_unlink);
if (ehci->intr_unlinking)
;
else if (ehci->rh_state < EHCI_RH_RUNNING)
ehci_handle_intr_unlinks(ehci);
else if (ehci->intr_unlink.next == &qh->unlink_node) {
ehci_enable_event(ehci, EHCI_HRTIMER_UNLINK_INTR, true);
++ehci->intr_unlink_cycle;
}
}
static void start_unlink_intr_wait(struct ehci_hcd *ehci,
struct ehci_qh *qh)
{
qh->unlink_cycle = ehci->intr_unlink_wait_cycle;
list_add_tail(&qh->unlink_node, &ehci->intr_unlink_wait);
if (ehci->rh_state < EHCI_RH_RUNNING)
ehci_handle_start_intr_unlinks(ehci);
else if (ehci->intr_unlink_wait.next == &qh->unlink_node) {
ehci_enable_event(ehci, EHCI_HRTIMER_START_UNLINK_INTR, true);
++ehci->intr_unlink_wait_cycle;
}
}
static void end_unlink_intr(struct ehci_hcd *ehci, struct ehci_qh *qh)
{
struct ehci_qh_hw *hw = qh->hw;
int rc;
qh->qh_state = QH_STATE_IDLE;
hw->hw_next = EHCI_LIST_END(ehci);
if (!list_empty(&qh->qtd_list))
qh_completions(ehci, qh);
if (!list_empty(&qh->qtd_list) && ehci->rh_state == EHCI_RH_RUNNING) {
rc = qh_schedule(ehci, qh);
if (rc == 0) {
qh_refresh(ehci, qh);
qh_link_periodic(ehci, qh);
}
else {
ehci_err(ehci, "can't reschedule qh %p, err %d\n",
qh, rc);
}
}
--ehci->intr_count;
disable_periodic(ehci);
}
static int check_period (
struct ehci_hcd *ehci,
unsigned frame,
unsigned uframe,
unsigned uperiod,
unsigned usecs
) {
if (uframe >= 8)
return 0;
usecs = ehci->uframe_periodic_max - usecs;
for (uframe += frame << 3; uframe < EHCI_BANDWIDTH_SIZE;
uframe += uperiod) {
if (ehci->bandwidth[uframe] > usecs)
return 0;
}
return 1;
}
static int check_intr_schedule (
struct ehci_hcd *ehci,
unsigned frame,
unsigned uframe,
struct ehci_qh *qh,
unsigned *c_maskp,
struct ehci_tt *tt
)
{
int retval = -ENOSPC;
u8 mask = 0;
if (qh->ps.c_usecs && uframe >= 6)
goto done;
if (!check_period(ehci, frame, uframe, qh->ps.bw_uperiod, qh->ps.usecs))
goto done;
if (!qh->ps.c_usecs) {
retval = 0;
*c_maskp = 0;
goto done;
}
#ifdef CONFIG_USB_EHCI_TT_NEWSCHED
if (tt_available(ehci, &qh->ps, tt, frame, uframe)) {
unsigned i;
for (i = uframe+2; i < 8 && i <= uframe+4; i++)
if (!check_period(ehci, frame, i,
qh->ps.bw_uperiod, qh->ps.c_usecs))
goto done;
else
mask |= 1 << i;
retval = 0;
*c_maskp = mask;
}
#else
mask = 0x03 << (uframe + qh->gap_uf);
*c_maskp = mask;
mask |= 1 << uframe;
if (tt_no_collision(ehci, qh->ps.bw_period, qh->ps.udev, frame, mask)) {
if (!check_period(ehci, frame, uframe + qh->gap_uf + 1,
qh->ps.bw_uperiod, qh->ps.c_usecs))
goto done;
if (!check_period(ehci, frame, uframe + qh->gap_uf,
qh->ps.bw_uperiod, qh->ps.c_usecs))
goto done;
retval = 0;
}
#endif
done:
return retval;
}
static int qh_schedule(struct ehci_hcd *ehci, struct ehci_qh *qh)
{
int status = 0;
unsigned uframe;
unsigned c_mask;
struct ehci_qh_hw *hw = qh->hw;
struct ehci_tt *tt;
hw->hw_next = EHCI_LIST_END(ehci);
if (qh->ps.phase != NO_FRAME) {
ehci_dbg(ehci, "reused qh %p schedule\n", qh);
return 0;
}
uframe = 0;
c_mask = 0;
tt = find_tt(qh->ps.udev);
if (IS_ERR(tt)) {
status = PTR_ERR(tt);
goto done;
}
compute_tt_budget(ehci->tt_budget, tt);
if (qh->ps.bw_period) {
int i;
unsigned frame;
for (i = qh->ps.bw_period; i > 0; --i) {
frame = ++ehci->random_frame & (qh->ps.bw_period - 1);
for (uframe = 0; uframe < 8; uframe++) {
status = check_intr_schedule(ehci,
frame, uframe, qh, &c_mask, tt);
if (status == 0)
goto got_it;
}
}
} else {
status = check_intr_schedule(ehci, 0, 0, qh, &c_mask, tt);
}
if (status)
goto done;
got_it:
qh->ps.phase = (qh->ps.period ? ehci->random_frame &
(qh->ps.period - 1) : 0);
qh->ps.bw_phase = qh->ps.phase & (qh->ps.bw_period - 1);
qh->ps.phase_uf = uframe;
qh->ps.cs_mask = qh->ps.period ?
(c_mask << 8) | (1 << uframe) :
QH_SMASK;
hw->hw_info2 &= cpu_to_hc32(ehci, ~(QH_CMASK | QH_SMASK));
hw->hw_info2 |= cpu_to_hc32(ehci, qh->ps.cs_mask);
reserve_release_intr_bandwidth(ehci, qh, 1);
done:
return status;
}
static int intr_submit (
struct ehci_hcd *ehci,
struct urb *urb,
struct list_head *qtd_list,
gfp_t mem_flags
) {
unsigned epnum;
unsigned long flags;
struct ehci_qh *qh;
int status;
struct list_head empty;
epnum = urb->ep->desc.bEndpointAddress;
spin_lock_irqsave (&ehci->lock, flags);
if (unlikely(!HCD_HW_ACCESSIBLE(ehci_to_hcd(ehci)))) {
status = -ESHUTDOWN;
goto done_not_linked;
}
status = usb_hcd_link_urb_to_ep(ehci_to_hcd(ehci), urb);
if (unlikely(status))
goto done_not_linked;
INIT_LIST_HEAD (&empty);
qh = qh_append_tds(ehci, urb, &empty, epnum, &urb->ep->hcpriv);
if (qh == NULL) {
status = -ENOMEM;
goto done;
}
if (qh->qh_state == QH_STATE_IDLE) {
if ((status = qh_schedule (ehci, qh)) != 0)
goto done;
}
qh = qh_append_tds(ehci, urb, qtd_list, epnum, &urb->ep->hcpriv);
BUG_ON (qh == NULL);
if (qh->qh_state == QH_STATE_IDLE) {
qh_refresh(ehci, qh);
qh_link_periodic(ehci, qh);
} else {
cancel_unlink_wait_intr(ehci, qh);
}
ehci_to_hcd(ehci)->self.bandwidth_int_reqs++;
done:
if (unlikely(status))
usb_hcd_unlink_urb_from_ep(ehci_to_hcd(ehci), urb);
done_not_linked:
spin_unlock_irqrestore (&ehci->lock, flags);
if (status)
qtd_list_free (ehci, urb, qtd_list);
return status;
}
static void scan_intr(struct ehci_hcd *ehci)
{
struct ehci_qh *qh;
list_for_each_entry_safe(qh, ehci->qh_scan_next, &ehci->intr_qh_list,
intr_node) {
if (!list_empty(&qh->qtd_list)) {
int temp;
temp = qh_completions(ehci, qh);
if (unlikely(temp))
start_unlink_intr(ehci, qh);
else if (unlikely(list_empty(&qh->qtd_list) &&
qh->qh_state == QH_STATE_LINKED))
start_unlink_intr_wait(ehci, qh);
}
}
}
static struct ehci_iso_stream *
iso_stream_alloc (gfp_t mem_flags)
{
struct ehci_iso_stream *stream;
stream = kzalloc(sizeof *stream, mem_flags);
if (likely (stream != NULL)) {
INIT_LIST_HEAD(&stream->td_list);
INIT_LIST_HEAD(&stream->free_list);
stream->next_uframe = NO_FRAME;
stream->ps.phase = NO_FRAME;
}
return stream;
}
static void
iso_stream_init (
struct ehci_hcd *ehci,
struct ehci_iso_stream *stream,
struct urb *urb
)
{
static const u8 smask_out [] = { 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f };
struct usb_device *dev = urb->dev;
u32 buf1;
unsigned epnum, maxp;
int is_input;
unsigned tmp;
epnum = usb_pipeendpoint(urb->pipe);
is_input = usb_pipein(urb->pipe) ? USB_DIR_IN : 0;
maxp = usb_endpoint_maxp(&urb->ep->desc);
if (is_input) {
buf1 = (1 << 11);
} else {
buf1 = 0;
}
if (dev->speed == USB_SPEED_HIGH) {
unsigned multi = hb_mult(maxp);
stream->highspeed = 1;
maxp = max_packet(maxp);
buf1 |= maxp;
maxp *= multi;
stream->buf0 = cpu_to_hc32(ehci, (epnum << 8) | dev->devnum);
stream->buf1 = cpu_to_hc32(ehci, buf1);
stream->buf2 = cpu_to_hc32(ehci, multi);
stream->ps.usecs = HS_USECS_ISO(maxp);
tmp = min_t(unsigned, EHCI_BANDWIDTH_SIZE,
1 << (urb->ep->desc.bInterval - 1));
stream->ps.bw_uperiod = min_t(unsigned, tmp, urb->interval);
stream->uperiod = urb->interval;
stream->ps.period = urb->interval >> 3;
stream->bandwidth = stream->ps.usecs * 8 /
stream->ps.bw_uperiod;
} else {
u32 addr;
int think_time;
int hs_transfers;
addr = dev->ttport << 24;
if (!ehci_is_TDI(ehci)
|| (dev->tt->hub !=
ehci_to_hcd(ehci)->self.root_hub))
addr |= dev->tt->hub->devnum << 16;
addr |= epnum << 8;
addr |= dev->devnum;
stream->ps.usecs = HS_USECS_ISO(maxp);
think_time = dev->tt ? dev->tt->think_time : 0;
stream->ps.tt_usecs = NS_TO_US(think_time + usb_calc_bus_time(
dev->speed, is_input, 1, maxp));
hs_transfers = max (1u, (maxp + 187) / 188);
if (is_input) {
u32 tmp;
addr |= 1 << 31;
stream->ps.c_usecs = stream->ps.usecs;
stream->ps.usecs = HS_USECS_ISO(1);
stream->ps.cs_mask = 1;
tmp = (1 << (hs_transfers + 2)) - 1;
stream->ps.cs_mask |= tmp << (8 + 2);
} else
stream->ps.cs_mask = smask_out[hs_transfers - 1];
tmp = min_t(unsigned, EHCI_BANDWIDTH_FRAMES,
1 << (urb->ep->desc.bInterval - 1));
stream->ps.bw_period = min_t(unsigned, tmp, urb->interval);
stream->ps.bw_uperiod = stream->ps.bw_period << 3;
stream->ps.period = urb->interval;
stream->uperiod = urb->interval << 3;
stream->bandwidth = (stream->ps.usecs + stream->ps.c_usecs) /
stream->ps.bw_period;
stream->address = cpu_to_hc32(ehci, addr);
}
stream->ps.udev = dev;
stream->ps.ep = urb->ep;
stream->bEndpointAddress = is_input | epnum;
stream->maxp = maxp;
}
static struct ehci_iso_stream *
iso_stream_find (struct ehci_hcd *ehci, struct urb *urb)
{
unsigned epnum;
struct ehci_iso_stream *stream;
struct usb_host_endpoint *ep;
unsigned long flags;
epnum = usb_pipeendpoint (urb->pipe);
if (usb_pipein(urb->pipe))
ep = urb->dev->ep_in[epnum];
else
ep = urb->dev->ep_out[epnum];
spin_lock_irqsave (&ehci->lock, flags);
stream = ep->hcpriv;
if (unlikely (stream == NULL)) {
stream = iso_stream_alloc(GFP_ATOMIC);
if (likely (stream != NULL)) {
ep->hcpriv = stream;
iso_stream_init(ehci, stream, urb);
}
} else if (unlikely (stream->hw != NULL)) {
ehci_dbg (ehci, "dev %s ep%d%s, not iso??\n",
urb->dev->devpath, epnum,
usb_pipein(urb->pipe) ? "in" : "out");
stream = NULL;
}
spin_unlock_irqrestore (&ehci->lock, flags);
return stream;
}
static struct ehci_iso_sched *
iso_sched_alloc (unsigned packets, gfp_t mem_flags)
{
struct ehci_iso_sched *iso_sched;
int size = sizeof *iso_sched;
size += packets * sizeof (struct ehci_iso_packet);
iso_sched = kzalloc(size, mem_flags);
if (likely (iso_sched != NULL)) {
INIT_LIST_HEAD (&iso_sched->td_list);
}
return iso_sched;
}
static inline void
itd_sched_init(
struct ehci_hcd *ehci,
struct ehci_iso_sched *iso_sched,
struct ehci_iso_stream *stream,
struct urb *urb
)
{
unsigned i;
dma_addr_t dma = urb->transfer_dma;
iso_sched->span = urb->number_of_packets * stream->uperiod;
for (i = 0; i < urb->number_of_packets; i++) {
struct ehci_iso_packet *uframe = &iso_sched->packet [i];
unsigned length;
dma_addr_t buf;
u32 trans;
length = urb->iso_frame_desc [i].length;
buf = dma + urb->iso_frame_desc [i].offset;
trans = EHCI_ISOC_ACTIVE;
trans |= buf & 0x0fff;
if (unlikely (((i + 1) == urb->number_of_packets))
&& !(urb->transfer_flags & URB_NO_INTERRUPT))
trans |= EHCI_ITD_IOC;
trans |= length << 16;
uframe->transaction = cpu_to_hc32(ehci, trans);
uframe->bufp = (buf & ~(u64)0x0fff);
buf += length;
if (unlikely ((uframe->bufp != (buf & ~(u64)0x0fff))))
uframe->cross = 1;
}
}
static void
iso_sched_free (
struct ehci_iso_stream *stream,
struct ehci_iso_sched *iso_sched
)
{
if (!iso_sched)
return;
list_splice (&iso_sched->td_list, &stream->free_list);
kfree (iso_sched);
}
static int
itd_urb_transaction (
struct ehci_iso_stream *stream,
struct ehci_hcd *ehci,
struct urb *urb,
gfp_t mem_flags
)
{
struct ehci_itd *itd;
dma_addr_t itd_dma;
int i;
unsigned num_itds;
struct ehci_iso_sched *sched;
unsigned long flags;
sched = iso_sched_alloc (urb->number_of_packets, mem_flags);
if (unlikely (sched == NULL))
return -ENOMEM;
itd_sched_init(ehci, sched, stream, urb);
if (urb->interval < 8)
num_itds = 1 + (sched->span + 7) / 8;
else
num_itds = urb->number_of_packets;
spin_lock_irqsave (&ehci->lock, flags);
for (i = 0; i < num_itds; i++) {
if (likely(!list_empty(&stream->free_list))) {
itd = list_first_entry(&stream->free_list,
struct ehci_itd, itd_list);
if (itd->frame == ehci->now_frame)
goto alloc_itd;
list_del (&itd->itd_list);
itd_dma = itd->itd_dma;
} else {
alloc_itd:
spin_unlock_irqrestore (&ehci->lock, flags);
itd = dma_pool_alloc (ehci->itd_pool, mem_flags,
&itd_dma);
spin_lock_irqsave (&ehci->lock, flags);
if (!itd) {
iso_sched_free(stream, sched);
spin_unlock_irqrestore(&ehci->lock, flags);
return -ENOMEM;
}
}
memset (itd, 0, sizeof *itd);
itd->itd_dma = itd_dma;
itd->frame = NO_FRAME;
list_add (&itd->itd_list, &sched->td_list);
}
spin_unlock_irqrestore (&ehci->lock, flags);
urb->hcpriv = sched;
urb->error_count = 0;
return 0;
}
static void reserve_release_iso_bandwidth(struct ehci_hcd *ehci,
struct ehci_iso_stream *stream, int sign)
{
unsigned uframe;
unsigned i, j;
unsigned s_mask, c_mask, m;
int usecs = stream->ps.usecs;
int c_usecs = stream->ps.c_usecs;
int tt_usecs = stream->ps.tt_usecs;
struct ehci_tt *tt;
if (stream->ps.phase == NO_FRAME)
return;
uframe = stream->ps.bw_phase << 3;
bandwidth_dbg(ehci, sign, "iso", &stream->ps);
if (sign < 0) {
usecs = -usecs;
c_usecs = -c_usecs;
tt_usecs = -tt_usecs;
}
if (!stream->splits) {
for (i = uframe + stream->ps.phase_uf; i < EHCI_BANDWIDTH_SIZE;
i += stream->ps.bw_uperiod)
ehci->bandwidth[i] += usecs;
} else {
s_mask = stream->ps.cs_mask;
c_mask = s_mask >> 8;
for (i = uframe; i < EHCI_BANDWIDTH_SIZE;
i += stream->ps.bw_uperiod) {
for ((j = stream->ps.phase_uf, m = 1 << j); j < 8;
(++j, m <<= 1)) {
if (s_mask & m)
ehci->bandwidth[i+j] += usecs;
else if (c_mask & m)
ehci->bandwidth[i+j] += c_usecs;
}
}
tt = find_tt(stream->ps.udev);
if (sign > 0)
list_add_tail(&stream->ps.ps_list, &tt->ps_list);
else
list_del(&stream->ps.ps_list);
for (i = uframe >> 3; i < EHCI_BANDWIDTH_FRAMES;
i += stream->ps.bw_period)
tt->bandwidth[i] += tt_usecs;
}
}
static inline int
itd_slot_ok (
struct ehci_hcd *ehci,
struct ehci_iso_stream *stream,
unsigned uframe
)
{
unsigned usecs;
usecs = ehci->uframe_periodic_max - stream->ps.usecs;
for (uframe &= stream->ps.bw_uperiod - 1; uframe < EHCI_BANDWIDTH_SIZE;
uframe += stream->ps.bw_uperiod) {
if (ehci->bandwidth[uframe] > usecs)
return 0;
}
return 1;
}
static inline int
sitd_slot_ok (
struct ehci_hcd *ehci,
struct ehci_iso_stream *stream,
unsigned uframe,
struct ehci_iso_sched *sched,
struct ehci_tt *tt
)
{
unsigned mask, tmp;
unsigned frame, uf;
mask = stream->ps.cs_mask << (uframe & 7);
if (((stream->ps.cs_mask & 0xff) << (uframe & 7)) >= (1 << 7))
return 0;
if (mask & ~0xffff)
return 0;
uframe &= stream->ps.bw_uperiod - 1;
frame = uframe >> 3;
#ifdef CONFIG_USB_EHCI_TT_NEWSCHED
uf = uframe & 7;
if (!tt_available(ehci, &stream->ps, tt, frame, uf))
return 0;
#else
if (!tt_no_collision(ehci, stream->ps.bw_period,
stream->ps.udev, frame, mask))
return 0;
#endif
do {
unsigned max_used;
unsigned i;
uf = uframe;
max_used = ehci->uframe_periodic_max - stream->ps.usecs;
for (tmp = stream->ps.cs_mask & 0xff; tmp; tmp >>= 1, uf++) {
if (ehci->bandwidth[uf] > max_used)
return 0;
}
if (stream->ps.c_usecs) {
max_used = ehci->uframe_periodic_max -
stream->ps.c_usecs;
uf = uframe & ~7;
tmp = 1 << (2+8);
for (i = (uframe & 7) + 2; i < 8; (++i, tmp <<= 1)) {
if ((stream->ps.cs_mask & tmp) == 0)
continue;
if (ehci->bandwidth[uf+i] > max_used)
return 0;
}
}
uframe += stream->ps.bw_uperiod;
} while (uframe < EHCI_BANDWIDTH_SIZE);
stream->ps.cs_mask <<= uframe & 7;
stream->splits = cpu_to_hc32(ehci, stream->ps.cs_mask);
return 1;
}
static int
iso_stream_schedule (
struct ehci_hcd *ehci,
struct urb *urb,
struct ehci_iso_stream *stream
)
{
u32 now, base, next, start, period, span, now2;
u32 wrap = 0, skip = 0;
int status = 0;
unsigned mod = ehci->periodic_size << 3;
struct ehci_iso_sched *sched = urb->hcpriv;
bool empty = list_empty(&stream->td_list);
bool new_stream = false;
period = stream->uperiod;
span = sched->span;
if (!stream->highspeed)
span <<= 3;
if (unlikely(empty && !hcd_periodic_completion_in_progress(
ehci_to_hcd(ehci), urb->ep))) {
if (stream->ps.phase == NO_FRAME) {
int done = 0;
struct ehci_tt *tt = find_tt(stream->ps.udev);
if (IS_ERR(tt)) {
status = PTR_ERR(tt);
goto fail;
}
compute_tt_budget(ehci->tt_budget, tt);
start = ((-(++ehci->random_frame)) << 3) & (period - 1);
next = start;
start += period;
do {
start--;
if (stream->highspeed) {
if (itd_slot_ok(ehci, stream, start))
done = 1;
} else {
if ((start % 8) >= 6)
continue;
if (sitd_slot_ok(ehci, stream, start,
sched, tt))
done = 1;
}
} while (start > next && !done);
if (!done) {
ehci_dbg(ehci, "iso sched full %p", urb);
status = -ENOSPC;
goto fail;
}
stream->ps.phase = (start >> 3) &
(stream->ps.period - 1);
stream->ps.bw_phase = stream->ps.phase &
(stream->ps.bw_period - 1);
stream->ps.phase_uf = start & 7;
reserve_release_iso_bandwidth(ehci, stream, 1);
}
else {
start = (stream->ps.phase << 3) + stream->ps.phase_uf;
}
stream->next_uframe = start;
new_stream = true;
}
now = ehci_read_frame_index(ehci) & (mod - 1);
if (ehci->i_thresh)
next = now + ehci->i_thresh;
else
next = (now + 2 + 7) & ~0x07;
base = ehci->last_iso_frame << 3;
next = (next - base) & (mod - 1);
start = (stream->next_uframe - base) & (mod - 1);
if (unlikely(new_stream))
goto do_ASAP;
now2 = (now - base) & (mod - 1);
if (unlikely(!empty && start < period)) {
ehci_dbg(ehci, "iso sched full %p (%u-%u < %u mod %u)\n",
urb, stream->next_uframe, base, period, mod);
status = -ENOSPC;
goto fail;
}
if (likely(!empty || start <= now2 + period)) {
if (unlikely(start < next &&
(urb->transfer_flags & URB_ISO_ASAP)))
goto do_ASAP;
if (likely(start >= now2))
goto use_start;
} else {
if (urb->transfer_flags & URB_ISO_ASAP)
goto do_ASAP;
wrap = mod;
now2 += mod;
}
skip = (now2 - start + period - 1) & -period;
if (skip >= span) {
ehci_dbg(ehci, "iso underrun %p (%u+%u < %u) [%u]\n",
urb, start + base, span - period, now2 + base,
base);
skip = span - period;
if (empty) {
skip = span;
status = 1;
iso_sched_free(stream, sched);
sched = NULL;
}
}
urb->error_count = skip / period;
if (sched)
sched->first_packet = urb->error_count;
goto use_start;
do_ASAP:
start = next + ((start - next) & (period - 1));
use_start:
if (unlikely(start + span - period >= mod + wrap)) {
ehci_dbg(ehci, "request %p would overflow (%u+%u >= %u)\n",
urb, start, span - period, mod + wrap);
status = -EFBIG;
goto fail;
}
start += base;
stream->next_uframe = (start + skip) & (mod - 1);
urb->start_frame = start & (mod - 1);
if (!stream->highspeed)
urb->start_frame >>= 3;
if (ehci->isoc_count == 0)
ehci->last_iso_frame = now >> 3;
return status;
fail:
iso_sched_free(stream, sched);
urb->hcpriv = NULL;
return status;
}
static inline void
itd_init(struct ehci_hcd *ehci, struct ehci_iso_stream *stream,
struct ehci_itd *itd)
{
int i;
itd->hw_next = EHCI_LIST_END(ehci);
itd->hw_bufp [0] = stream->buf0;
itd->hw_bufp [1] = stream->buf1;
itd->hw_bufp [2] = stream->buf2;
for (i = 0; i < 8; i++)
itd->index[i] = -1;
}
static inline void
itd_patch(
struct ehci_hcd *ehci,
struct ehci_itd *itd,
struct ehci_iso_sched *iso_sched,
unsigned index,
u16 uframe
)
{
struct ehci_iso_packet *uf = &iso_sched->packet [index];
unsigned pg = itd->pg;
uframe &= 0x07;
itd->index [uframe] = index;
itd->hw_transaction[uframe] = uf->transaction;
itd->hw_transaction[uframe] |= cpu_to_hc32(ehci, pg << 12);
itd->hw_bufp[pg] |= cpu_to_hc32(ehci, uf->bufp & ~(u32)0);
itd->hw_bufp_hi[pg] |= cpu_to_hc32(ehci, (u32)(uf->bufp >> 32));
if (unlikely (uf->cross)) {
u64 bufp = uf->bufp + 4096;
itd->pg = ++pg;
itd->hw_bufp[pg] |= cpu_to_hc32(ehci, bufp & ~(u32)0);
itd->hw_bufp_hi[pg] |= cpu_to_hc32(ehci, (u32)(bufp >> 32));
}
}
static inline void
itd_link (struct ehci_hcd *ehci, unsigned frame, struct ehci_itd *itd)
{
union ehci_shadow *prev = &ehci->pshadow[frame];
__hc32 *hw_p = &ehci->periodic[frame];
union ehci_shadow here = *prev;
__hc32 type = 0;
while (here.ptr) {
type = Q_NEXT_TYPE(ehci, *hw_p);
if (type == cpu_to_hc32(ehci, Q_TYPE_QH))
break;
prev = periodic_next_shadow(ehci, prev, type);
hw_p = shadow_next_periodic(ehci, &here, type);
here = *prev;
}
itd->itd_next = here;
itd->hw_next = *hw_p;
prev->itd = itd;
itd->frame = frame;
wmb ();
*hw_p = cpu_to_hc32(ehci, itd->itd_dma | Q_TYPE_ITD);
}
static void itd_link_urb(
struct ehci_hcd *ehci,
struct urb *urb,
unsigned mod,
struct ehci_iso_stream *stream
)
{
int packet;
unsigned next_uframe, uframe, frame;
struct ehci_iso_sched *iso_sched = urb->hcpriv;
struct ehci_itd *itd;
next_uframe = stream->next_uframe & (mod - 1);
if (unlikely (list_empty(&stream->td_list)))
ehci_to_hcd(ehci)->self.bandwidth_allocated
+= stream->bandwidth;
if (ehci_to_hcd(ehci)->self.bandwidth_isoc_reqs == 0) {
if (ehci->amd_pll_fix == 1)
usb_amd_quirk_pll_disable();
}
ehci_to_hcd(ehci)->self.bandwidth_isoc_reqs++;
for (packet = iso_sched->first_packet, itd = NULL;
packet < urb->number_of_packets;) {
if (itd == NULL) {
itd = list_entry (iso_sched->td_list.next,
struct ehci_itd, itd_list);
list_move_tail (&itd->itd_list, &stream->td_list);
itd->stream = stream;
itd->urb = urb;
itd_init (ehci, stream, itd);
}
uframe = next_uframe & 0x07;
frame = next_uframe >> 3;
itd_patch(ehci, itd, iso_sched, packet, uframe);
next_uframe += stream->uperiod;
next_uframe &= mod - 1;
packet++;
if (((next_uframe >> 3) != frame)
|| packet == urb->number_of_packets) {
itd_link(ehci, frame & (ehci->periodic_size - 1), itd);
itd = NULL;
}
}
stream->next_uframe = next_uframe;
iso_sched_free (stream, iso_sched);
urb->hcpriv = stream;
++ehci->isoc_count;
enable_periodic(ehci);
}
static bool itd_complete(struct ehci_hcd *ehci, struct ehci_itd *itd)
{
struct urb *urb = itd->urb;
struct usb_iso_packet_descriptor *desc;
u32 t;
unsigned uframe;
int urb_index = -1;
struct ehci_iso_stream *stream = itd->stream;
struct usb_device *dev;
bool retval = false;
for (uframe = 0; uframe < 8; uframe++) {
if (likely (itd->index[uframe] == -1))
continue;
urb_index = itd->index[uframe];
desc = &urb->iso_frame_desc [urb_index];
t = hc32_to_cpup(ehci, &itd->hw_transaction [uframe]);
itd->hw_transaction [uframe] = 0;
if (unlikely (t & ISO_ERRS)) {
urb->error_count++;
if (t & EHCI_ISOC_BUF_ERR)
desc->status = usb_pipein (urb->pipe)
? -ENOSR
: -ECOMM;
else if (t & EHCI_ISOC_BABBLE)
desc->status = -EOVERFLOW;
else
desc->status = -EPROTO;
if (!(t & EHCI_ISOC_BABBLE)) {
desc->actual_length = EHCI_ITD_LENGTH(t);
urb->actual_length += desc->actual_length;
}
} else if (likely ((t & EHCI_ISOC_ACTIVE) == 0)) {
desc->status = 0;
desc->actual_length = EHCI_ITD_LENGTH(t);
urb->actual_length += desc->actual_length;
} else {
urb->error_count++;
}
}
if (likely ((urb_index + 1) != urb->number_of_packets))
goto done;
dev = urb->dev;
ehci_urb_done(ehci, urb, 0);
retval = true;
urb = NULL;
--ehci->isoc_count;
disable_periodic(ehci);
ehci_to_hcd(ehci)->self.bandwidth_isoc_reqs--;
if (ehci_to_hcd(ehci)->self.bandwidth_isoc_reqs == 0) {
if (ehci->amd_pll_fix == 1)
usb_amd_quirk_pll_enable();
}
if (unlikely(list_is_singular(&stream->td_list)))
ehci_to_hcd(ehci)->self.bandwidth_allocated
-= stream->bandwidth;
done:
itd->urb = NULL;
list_move_tail(&itd->itd_list, &stream->free_list);
if (list_empty(&stream->td_list)) {
list_splice_tail_init(&stream->free_list,
&ehci->cached_itd_list);
start_free_itds(ehci);
}
return retval;
}
static int itd_submit (struct ehci_hcd *ehci, struct urb *urb,
gfp_t mem_flags)
{
int status = -EINVAL;
unsigned long flags;
struct ehci_iso_stream *stream;
stream = iso_stream_find (ehci, urb);
if (unlikely (stream == NULL)) {
ehci_dbg (ehci, "can't get iso stream\n");
return -ENOMEM;
}
if (unlikely(urb->interval != stream->uperiod)) {
ehci_dbg (ehci, "can't change iso interval %d --> %d\n",
stream->uperiod, urb->interval);
goto done;
}
#ifdef EHCI_URB_TRACE
ehci_dbg (ehci,
"%s %s urb %p ep%d%s len %d, %d pkts %d uframes [%p]\n",
__func__, urb->dev->devpath, urb,
usb_pipeendpoint (urb->pipe),
usb_pipein (urb->pipe) ? "in" : "out",
urb->transfer_buffer_length,
urb->number_of_packets, urb->interval,
stream);
#endif
status = itd_urb_transaction (stream, ehci, urb, mem_flags);
if (unlikely (status < 0)) {
ehci_dbg (ehci, "can't init itds\n");
goto done;
}
spin_lock_irqsave (&ehci->lock, flags);
if (unlikely(!HCD_HW_ACCESSIBLE(ehci_to_hcd(ehci)))) {
status = -ESHUTDOWN;
goto done_not_linked;
}
status = usb_hcd_link_urb_to_ep(ehci_to_hcd(ehci), urb);
if (unlikely(status))
goto done_not_linked;
status = iso_stream_schedule(ehci, urb, stream);
if (likely(status == 0)) {
itd_link_urb (ehci, urb, ehci->periodic_size << 3, stream);
} else if (status > 0) {
status = 0;
ehci_urb_done(ehci, urb, 0);
} else {
usb_hcd_unlink_urb_from_ep(ehci_to_hcd(ehci), urb);
}
done_not_linked:
spin_unlock_irqrestore (&ehci->lock, flags);
done:
return status;
}
static inline void
sitd_sched_init(
struct ehci_hcd *ehci,
struct ehci_iso_sched *iso_sched,
struct ehci_iso_stream *stream,
struct urb *urb
)
{
unsigned i;
dma_addr_t dma = urb->transfer_dma;
iso_sched->span = urb->number_of_packets * stream->ps.period;
for (i = 0; i < urb->number_of_packets; i++) {
struct ehci_iso_packet *packet = &iso_sched->packet [i];
unsigned length;
dma_addr_t buf;
u32 trans;
length = urb->iso_frame_desc [i].length & 0x03ff;
buf = dma + urb->iso_frame_desc [i].offset;
trans = SITD_STS_ACTIVE;
if (((i + 1) == urb->number_of_packets)
&& !(urb->transfer_flags & URB_NO_INTERRUPT))
trans |= SITD_IOC;
trans |= length << 16;
packet->transaction = cpu_to_hc32(ehci, trans);
packet->bufp = buf;
packet->buf1 = (buf + length) & ~0x0fff;
if (packet->buf1 != (buf & ~(u64)0x0fff))
packet->cross = 1;
if (stream->bEndpointAddress & USB_DIR_IN)
continue;
length = (length + 187) / 188;
if (length > 1)
length |= 1 << 3;
packet->buf1 |= length;
}
}
static int
sitd_urb_transaction (
struct ehci_iso_stream *stream,
struct ehci_hcd *ehci,
struct urb *urb,
gfp_t mem_flags
)
{
struct ehci_sitd *sitd;
dma_addr_t sitd_dma;
int i;
struct ehci_iso_sched *iso_sched;
unsigned long flags;
iso_sched = iso_sched_alloc (urb->number_of_packets, mem_flags);
if (iso_sched == NULL)
return -ENOMEM;
sitd_sched_init(ehci, iso_sched, stream, urb);
spin_lock_irqsave (&ehci->lock, flags);
for (i = 0; i < urb->number_of_packets; i++) {
if (likely(!list_empty(&stream->free_list))) {
sitd = list_first_entry(&stream->free_list,
struct ehci_sitd, sitd_list);
if (sitd->frame == ehci->now_frame)
goto alloc_sitd;
list_del (&sitd->sitd_list);
sitd_dma = sitd->sitd_dma;
} else {
alloc_sitd:
spin_unlock_irqrestore (&ehci->lock, flags);
sitd = dma_pool_alloc (ehci->sitd_pool, mem_flags,
&sitd_dma);
spin_lock_irqsave (&ehci->lock, flags);
if (!sitd) {
iso_sched_free(stream, iso_sched);
spin_unlock_irqrestore(&ehci->lock, flags);
return -ENOMEM;
}
}
memset (sitd, 0, sizeof *sitd);
sitd->sitd_dma = sitd_dma;
sitd->frame = NO_FRAME;
list_add (&sitd->sitd_list, &iso_sched->td_list);
}
urb->hcpriv = iso_sched;
urb->error_count = 0;
spin_unlock_irqrestore (&ehci->lock, flags);
return 0;
}
static inline void
sitd_patch(
struct ehci_hcd *ehci,
struct ehci_iso_stream *stream,
struct ehci_sitd *sitd,
struct ehci_iso_sched *iso_sched,
unsigned index
)
{
struct ehci_iso_packet *uf = &iso_sched->packet [index];
u64 bufp = uf->bufp;
sitd->hw_next = EHCI_LIST_END(ehci);
sitd->hw_fullspeed_ep = stream->address;
sitd->hw_uframe = stream->splits;
sitd->hw_results = uf->transaction;
sitd->hw_backpointer = EHCI_LIST_END(ehci);
bufp = uf->bufp;
sitd->hw_buf[0] = cpu_to_hc32(ehci, bufp);
sitd->hw_buf_hi[0] = cpu_to_hc32(ehci, bufp >> 32);
sitd->hw_buf[1] = cpu_to_hc32(ehci, uf->buf1);
if (uf->cross)
bufp += 4096;
sitd->hw_buf_hi[1] = cpu_to_hc32(ehci, bufp >> 32);
sitd->index = index;
}
static inline void
sitd_link (struct ehci_hcd *ehci, unsigned frame, struct ehci_sitd *sitd)
{
sitd->sitd_next = ehci->pshadow [frame];
sitd->hw_next = ehci->periodic [frame];
ehci->pshadow [frame].sitd = sitd;
sitd->frame = frame;
wmb ();
ehci->periodic[frame] = cpu_to_hc32(ehci, sitd->sitd_dma | Q_TYPE_SITD);
}
static void sitd_link_urb(
struct ehci_hcd *ehci,
struct urb *urb,
unsigned mod,
struct ehci_iso_stream *stream
)
{
int packet;
unsigned next_uframe;
struct ehci_iso_sched *sched = urb->hcpriv;
struct ehci_sitd *sitd;
next_uframe = stream->next_uframe;
if (list_empty(&stream->td_list))
ehci_to_hcd(ehci)->self.bandwidth_allocated
+= stream->bandwidth;
if (ehci_to_hcd(ehci)->self.bandwidth_isoc_reqs == 0) {
if (ehci->amd_pll_fix == 1)
usb_amd_quirk_pll_disable();
}
ehci_to_hcd(ehci)->self.bandwidth_isoc_reqs++;
for (packet = sched->first_packet, sitd = NULL;
packet < urb->number_of_packets;
packet++) {
BUG_ON (list_empty (&sched->td_list));
sitd = list_entry (sched->td_list.next,
struct ehci_sitd, sitd_list);
list_move_tail (&sitd->sitd_list, &stream->td_list);
sitd->stream = stream;
sitd->urb = urb;
sitd_patch(ehci, stream, sitd, sched, packet);
sitd_link(ehci, (next_uframe >> 3) & (ehci->periodic_size - 1),
sitd);
next_uframe += stream->uperiod;
}
stream->next_uframe = next_uframe & (mod - 1);
iso_sched_free (stream, sched);
urb->hcpriv = stream;
++ehci->isoc_count;
enable_periodic(ehci);
}
static bool sitd_complete(struct ehci_hcd *ehci, struct ehci_sitd *sitd)
{
struct urb *urb = sitd->urb;
struct usb_iso_packet_descriptor *desc;
u32 t;
int urb_index = -1;
struct ehci_iso_stream *stream = sitd->stream;
struct usb_device *dev;
bool retval = false;
urb_index = sitd->index;
desc = &urb->iso_frame_desc [urb_index];
t = hc32_to_cpup(ehci, &sitd->hw_results);
if (unlikely(t & SITD_ERRS)) {
urb->error_count++;
if (t & SITD_STS_DBE)
desc->status = usb_pipein (urb->pipe)
? -ENOSR
: -ECOMM;
else if (t & SITD_STS_BABBLE)
desc->status = -EOVERFLOW;
else
desc->status = -EPROTO;
} else if (unlikely(t & SITD_STS_ACTIVE)) {
urb->error_count++;
} else {
desc->status = 0;
desc->actual_length = desc->length - SITD_LENGTH(t);
urb->actual_length += desc->actual_length;
}
if ((urb_index + 1) != urb->number_of_packets)
goto done;
dev = urb->dev;
ehci_urb_done(ehci, urb, 0);
retval = true;
urb = NULL;
--ehci->isoc_count;
disable_periodic(ehci);
ehci_to_hcd(ehci)->self.bandwidth_isoc_reqs--;
if (ehci_to_hcd(ehci)->self.bandwidth_isoc_reqs == 0) {
if (ehci->amd_pll_fix == 1)
usb_amd_quirk_pll_enable();
}
if (list_is_singular(&stream->td_list))
ehci_to_hcd(ehci)->self.bandwidth_allocated
-= stream->bandwidth;
done:
sitd->urb = NULL;
list_move_tail(&sitd->sitd_list, &stream->free_list);
if (list_empty(&stream->td_list)) {
list_splice_tail_init(&stream->free_list,
&ehci->cached_sitd_list);
start_free_itds(ehci);
}
return retval;
}
static int sitd_submit (struct ehci_hcd *ehci, struct urb *urb,
gfp_t mem_flags)
{
int status = -EINVAL;
unsigned long flags;
struct ehci_iso_stream *stream;
stream = iso_stream_find (ehci, urb);
if (stream == NULL) {
ehci_dbg (ehci, "can't get iso stream\n");
return -ENOMEM;
}
if (urb->interval != stream->ps.period) {
ehci_dbg (ehci, "can't change iso interval %d --> %d\n",
stream->ps.period, urb->interval);
goto done;
}
#ifdef EHCI_URB_TRACE
ehci_dbg (ehci,
"submit %p dev%s ep%d%s-iso len %d\n",
urb, urb->dev->devpath,
usb_pipeendpoint (urb->pipe),
usb_pipein (urb->pipe) ? "in" : "out",
urb->transfer_buffer_length);
#endif
status = sitd_urb_transaction (stream, ehci, urb, mem_flags);
if (status < 0) {
ehci_dbg (ehci, "can't init sitds\n");
goto done;
}
spin_lock_irqsave (&ehci->lock, flags);
if (unlikely(!HCD_HW_ACCESSIBLE(ehci_to_hcd(ehci)))) {
status = -ESHUTDOWN;
goto done_not_linked;
}
status = usb_hcd_link_urb_to_ep(ehci_to_hcd(ehci), urb);
if (unlikely(status))
goto done_not_linked;
status = iso_stream_schedule(ehci, urb, stream);
if (likely(status == 0)) {
sitd_link_urb (ehci, urb, ehci->periodic_size << 3, stream);
} else if (status > 0) {
status = 0;
ehci_urb_done(ehci, urb, 0);
} else {
usb_hcd_unlink_urb_from_ep(ehci_to_hcd(ehci), urb);
}
done_not_linked:
spin_unlock_irqrestore (&ehci->lock, flags);
done:
return status;
}
static void scan_isoc(struct ehci_hcd *ehci)
{
unsigned uf, now_frame, frame;
unsigned fmask = ehci->periodic_size - 1;
bool modified, live;
if (ehci->rh_state >= EHCI_RH_RUNNING) {
uf = ehci_read_frame_index(ehci);
now_frame = (uf >> 3) & fmask;
live = true;
} else {
now_frame = (ehci->last_iso_frame - 1) & fmask;
live = false;
}
ehci->now_frame = now_frame;
frame = ehci->last_iso_frame;
for (;;) {
union ehci_shadow q, *q_p;
__hc32 type, *hw_p;
restart:
q_p = &ehci->pshadow [frame];
hw_p = &ehci->periodic [frame];
q.ptr = q_p->ptr;
type = Q_NEXT_TYPE(ehci, *hw_p);
modified = false;
while (q.ptr != NULL) {
switch (hc32_to_cpu(ehci, type)) {
case Q_TYPE_ITD:
if (frame == now_frame && live) {
rmb();
for (uf = 0; uf < 8; uf++) {
if (q.itd->hw_transaction[uf] &
ITD_ACTIVE(ehci))
break;
}
if (uf < 8) {
q_p = &q.itd->itd_next;
hw_p = &q.itd->hw_next;
type = Q_NEXT_TYPE(ehci,
q.itd->hw_next);
q = *q_p;
break;
}
}
*q_p = q.itd->itd_next;
if (!ehci->use_dummy_qh ||
q.itd->hw_next != EHCI_LIST_END(ehci))
*hw_p = q.itd->hw_next;
else
*hw_p = cpu_to_hc32(ehci,
ehci->dummy->qh_dma);
type = Q_NEXT_TYPE(ehci, q.itd->hw_next);
wmb();
modified = itd_complete (ehci, q.itd);
q = *q_p;
break;
case Q_TYPE_SITD:
if (((frame == now_frame) ||
(((frame + 1) & fmask) == now_frame))
&& live
&& (q.sitd->hw_results &
SITD_ACTIVE(ehci))) {
q_p = &q.sitd->sitd_next;
hw_p = &q.sitd->hw_next;
type = Q_NEXT_TYPE(ehci,
q.sitd->hw_next);
q = *q_p;
break;
}
*q_p = q.sitd->sitd_next;
if (!ehci->use_dummy_qh ||
q.sitd->hw_next != EHCI_LIST_END(ehci))
*hw_p = q.sitd->hw_next;
else
*hw_p = cpu_to_hc32(ehci,
ehci->dummy->qh_dma);
type = Q_NEXT_TYPE(ehci, q.sitd->hw_next);
wmb();
modified = sitd_complete (ehci, q.sitd);
q = *q_p;
break;
default:
ehci_dbg(ehci, "corrupt type %d frame %d shadow %p\n",
type, frame, q.ptr);
case Q_TYPE_QH:
case Q_TYPE_FSTN:
q.ptr = NULL;
break;
}
if (unlikely(modified && ehci->isoc_count > 0))
goto restart;
}
if (frame == now_frame)
break;
ehci->last_iso_frame = frame;
frame = (frame + 1) & fmask;
}
}
