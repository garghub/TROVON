dma_addr_t xhci_trb_virt_to_dma(struct xhci_segment *seg,
union xhci_trb *trb)
{
unsigned long segment_offset;
if (!seg || !trb || trb < seg->trbs)
return 0;
segment_offset = trb - seg->trbs;
if (segment_offset > TRBS_PER_SEGMENT)
return 0;
return seg->dma + (segment_offset * sizeof(*trb));
}
static bool last_trb_on_last_seg(struct xhci_hcd *xhci, struct xhci_ring *ring,
struct xhci_segment *seg, union xhci_trb *trb)
{
if (ring == xhci->event_ring)
return (trb == &seg->trbs[TRBS_PER_SEGMENT]) &&
(seg->next == xhci->event_ring->first_seg);
else
return le32_to_cpu(trb->link.control) & LINK_TOGGLE;
}
static int last_trb(struct xhci_hcd *xhci, struct xhci_ring *ring,
struct xhci_segment *seg, union xhci_trb *trb)
{
if (ring == xhci->event_ring)
return trb == &seg->trbs[TRBS_PER_SEGMENT];
else
return TRB_TYPE_LINK_LE32(trb->link.control);
}
static int enqueue_is_link_trb(struct xhci_ring *ring)
{
struct xhci_link_trb *link = &ring->enqueue->link;
return TRB_TYPE_LINK_LE32(link->control);
}
static void next_trb(struct xhci_hcd *xhci,
struct xhci_ring *ring,
struct xhci_segment **seg,
union xhci_trb **trb)
{
if (last_trb(xhci, ring, *seg, *trb)) {
*seg = (*seg)->next;
*trb = ((*seg)->trbs);
} else {
(*trb)++;
}
}
static void inc_deq(struct xhci_hcd *xhci, struct xhci_ring *ring, bool consumer)
{
union xhci_trb *next = ++(ring->dequeue);
unsigned long long addr;
ring->deq_updates++;
while (last_trb(xhci, ring, ring->deq_seg, next)) {
if (consumer && last_trb_on_last_seg(xhci, ring, ring->deq_seg, next)) {
ring->cycle_state = (ring->cycle_state ? 0 : 1);
if (!in_interrupt())
xhci_dbg(xhci, "Toggle cycle state for ring %p = %i\n",
ring,
(unsigned int) ring->cycle_state);
}
ring->deq_seg = ring->deq_seg->next;
ring->dequeue = ring->deq_seg->trbs;
next = ring->dequeue;
}
addr = (unsigned long long) xhci_trb_virt_to_dma(ring->deq_seg, ring->dequeue);
}
static void inc_enq(struct xhci_hcd *xhci, struct xhci_ring *ring,
bool consumer, bool more_trbs_coming)
{
u32 chain;
union xhci_trb *next;
unsigned long long addr;
chain = le32_to_cpu(ring->enqueue->generic.field[3]) & TRB_CHAIN;
next = ++(ring->enqueue);
ring->enq_updates++;
while (last_trb(xhci, ring, ring->enq_seg, next)) {
if (!consumer) {
if (ring != xhci->event_ring) {
if (!chain && !more_trbs_coming)
break;
if (!xhci_link_trb_quirk(xhci)) {
next->link.control &=
cpu_to_le32(~TRB_CHAIN);
next->link.control |=
cpu_to_le32(chain);
}
wmb();
next->link.control ^= cpu_to_le32(TRB_CYCLE);
}
if (last_trb_on_last_seg(xhci, ring, ring->enq_seg, next)) {
ring->cycle_state = (ring->cycle_state ? 0 : 1);
if (!in_interrupt())
xhci_dbg(xhci, "Toggle cycle state for ring %p = %i\n",
ring,
(unsigned int) ring->cycle_state);
}
}
ring->enq_seg = ring->enq_seg->next;
ring->enqueue = ring->enq_seg->trbs;
next = ring->enqueue;
}
addr = (unsigned long long) xhci_trb_virt_to_dma(ring->enq_seg, ring->enqueue);
}
static int room_on_ring(struct xhci_hcd *xhci, struct xhci_ring *ring,
unsigned int num_trbs)
{
int i;
union xhci_trb *enq = ring->enqueue;
struct xhci_segment *enq_seg = ring->enq_seg;
struct xhci_segment *cur_seg;
unsigned int left_on_ring;
while (last_trb(xhci, ring, enq_seg, enq)) {
enq_seg = enq_seg->next;
enq = enq_seg->trbs;
}
if (enq == ring->dequeue) {
left_on_ring = TRBS_PER_SEGMENT - 1;
for (cur_seg = enq_seg->next; cur_seg != enq_seg;
cur_seg = cur_seg->next)
left_on_ring += TRBS_PER_SEGMENT - 1;
left_on_ring -= 1;
if (num_trbs > left_on_ring) {
xhci_warn(xhci, "Not enough room on ring; "
"need %u TRBs, %u TRBs left\n",
num_trbs, left_on_ring);
return 0;
}
return 1;
}
for (i = 0; i <= num_trbs; ++i) {
if (enq == ring->dequeue)
return 0;
enq++;
while (last_trb(xhci, ring, enq_seg, enq)) {
enq_seg = enq_seg->next;
enq = enq_seg->trbs;
}
}
return 1;
}
void xhci_ring_cmd_db(struct xhci_hcd *xhci)
{
xhci_dbg(xhci, "// Ding dong!\n");
xhci_writel(xhci, DB_VALUE_HOST, &xhci->dba->doorbell[0]);
xhci_readl(xhci, &xhci->dba->doorbell[0]);
}
void xhci_ring_ep_doorbell(struct xhci_hcd *xhci,
unsigned int slot_id,
unsigned int ep_index,
unsigned int stream_id)
{
__le32 __iomem *db_addr = &xhci->dba->doorbell[slot_id];
struct xhci_virt_ep *ep = &xhci->devs[slot_id]->eps[ep_index];
unsigned int ep_state = ep->ep_state;
if ((ep_state & EP_HALT_PENDING) || (ep_state & SET_DEQ_PENDING) ||
(ep_state & EP_HALTED))
return;
xhci_writel(xhci, DB_VALUE(ep_index, stream_id), db_addr);
}
static void ring_doorbell_for_active_rings(struct xhci_hcd *xhci,
unsigned int slot_id,
unsigned int ep_index)
{
unsigned int stream_id;
struct xhci_virt_ep *ep;
ep = &xhci->devs[slot_id]->eps[ep_index];
if (!(ep->ep_state & EP_HAS_STREAMS)) {
if (!(list_empty(&ep->ring->td_list)))
xhci_ring_ep_doorbell(xhci, slot_id, ep_index, 0);
return;
}
for (stream_id = 1; stream_id < ep->stream_info->num_streams;
stream_id++) {
struct xhci_stream_info *stream_info = ep->stream_info;
if (!list_empty(&stream_info->stream_rings[stream_id]->td_list))
xhci_ring_ep_doorbell(xhci, slot_id, ep_index,
stream_id);
}
}
static struct xhci_segment *find_trb_seg(
struct xhci_segment *start_seg,
union xhci_trb *trb, int *cycle_state)
{
struct xhci_segment *cur_seg = start_seg;
struct xhci_generic_trb *generic_trb;
while (cur_seg->trbs > trb ||
&cur_seg->trbs[TRBS_PER_SEGMENT - 1] < trb) {
generic_trb = &cur_seg->trbs[TRBS_PER_SEGMENT - 1].generic;
if (generic_trb->field[3] & cpu_to_le32(LINK_TOGGLE))
*cycle_state ^= 0x1;
cur_seg = cur_seg->next;
if (cur_seg == start_seg)
return NULL;
}
return cur_seg;
}
static struct xhci_ring *xhci_triad_to_transfer_ring(struct xhci_hcd *xhci,
unsigned int slot_id, unsigned int ep_index,
unsigned int stream_id)
{
struct xhci_virt_ep *ep;
ep = &xhci->devs[slot_id]->eps[ep_index];
if (!(ep->ep_state & EP_HAS_STREAMS))
return ep->ring;
if (stream_id == 0) {
xhci_warn(xhci,
"WARN: Slot ID %u, ep index %u has streams, "
"but URB has no stream ID.\n",
slot_id, ep_index);
return NULL;
}
if (stream_id < ep->stream_info->num_streams)
return ep->stream_info->stream_rings[stream_id];
xhci_warn(xhci,
"WARN: Slot ID %u, ep index %u has "
"stream IDs 1 to %u allocated, "
"but stream ID %u is requested.\n",
slot_id, ep_index,
ep->stream_info->num_streams - 1,
stream_id);
return NULL;
}
static struct xhci_ring *xhci_urb_to_transfer_ring(struct xhci_hcd *xhci,
struct urb *urb)
{
return xhci_triad_to_transfer_ring(xhci, urb->dev->slot_id,
xhci_get_endpoint_index(&urb->ep->desc), urb->stream_id);
}
void xhci_find_new_dequeue_state(struct xhci_hcd *xhci,
unsigned int slot_id, unsigned int ep_index,
unsigned int stream_id, struct xhci_td *cur_td,
struct xhci_dequeue_state *state)
{
struct xhci_virt_device *dev = xhci->devs[slot_id];
struct xhci_ring *ep_ring;
struct xhci_generic_trb *trb;
struct xhci_ep_ctx *ep_ctx;
dma_addr_t addr;
ep_ring = xhci_triad_to_transfer_ring(xhci, slot_id,
ep_index, stream_id);
if (!ep_ring) {
xhci_warn(xhci, "WARN can't find new dequeue state "
"for invalid stream ID %u.\n",
stream_id);
return;
}
state->new_cycle_state = 0;
xhci_dbg(xhci, "Finding segment containing stopped TRB.\n");
state->new_deq_seg = find_trb_seg(cur_td->start_seg,
dev->eps[ep_index].stopped_trb,
&state->new_cycle_state);
if (!state->new_deq_seg) {
WARN_ON(1);
return;
}
xhci_dbg(xhci, "Finding endpoint context\n");
ep_ctx = xhci_get_ep_ctx(xhci, dev->out_ctx, ep_index);
state->new_cycle_state = 0x1 & le64_to_cpu(ep_ctx->deq);
state->new_deq_ptr = cur_td->last_trb;
xhci_dbg(xhci, "Finding segment containing last TRB in TD.\n");
state->new_deq_seg = find_trb_seg(state->new_deq_seg,
state->new_deq_ptr,
&state->new_cycle_state);
if (!state->new_deq_seg) {
WARN_ON(1);
return;
}
trb = &state->new_deq_ptr->generic;
if (TRB_TYPE_LINK_LE32(trb->field[3]) &&
(trb->field[3] & cpu_to_le32(LINK_TOGGLE)))
state->new_cycle_state ^= 0x1;
next_trb(xhci, ep_ring, &state->new_deq_seg, &state->new_deq_ptr);
if (ep_ring->first_seg == ep_ring->first_seg->next &&
state->new_deq_ptr < dev->eps[ep_index].stopped_trb)
state->new_cycle_state ^= 0x1;
xhci_dbg(xhci, "Cycle state = 0x%x\n", state->new_cycle_state);
xhci_dbg(xhci, "New dequeue segment = %p (virtual)\n",
state->new_deq_seg);
addr = xhci_trb_virt_to_dma(state->new_deq_seg, state->new_deq_ptr);
xhci_dbg(xhci, "New dequeue pointer = 0x%llx (DMA)\n",
(unsigned long long) addr);
}
static void td_to_noop(struct xhci_hcd *xhci, struct xhci_ring *ep_ring,
struct xhci_td *cur_td, bool flip_cycle)
{
struct xhci_segment *cur_seg;
union xhci_trb *cur_trb;
for (cur_seg = cur_td->start_seg, cur_trb = cur_td->first_trb;
true;
next_trb(xhci, ep_ring, &cur_seg, &cur_trb)) {
if (TRB_TYPE_LINK_LE32(cur_trb->generic.field[3])) {
cur_trb->generic.field[3] &= cpu_to_le32(~TRB_CHAIN);
if (flip_cycle)
cur_trb->generic.field[3] ^=
cpu_to_le32(TRB_CYCLE);
xhci_dbg(xhci, "Cancel (unchain) link TRB\n");
xhci_dbg(xhci, "Address = %p (0x%llx dma); "
"in seg %p (0x%llx dma)\n",
cur_trb,
(unsigned long long)xhci_trb_virt_to_dma(cur_seg, cur_trb),
cur_seg,
(unsigned long long)cur_seg->dma);
} else {
cur_trb->generic.field[0] = 0;
cur_trb->generic.field[1] = 0;
cur_trb->generic.field[2] = 0;
cur_trb->generic.field[3] &= cpu_to_le32(TRB_CYCLE);
if (flip_cycle && cur_trb != cur_td->first_trb &&
cur_trb != cur_td->last_trb)
cur_trb->generic.field[3] ^=
cpu_to_le32(TRB_CYCLE);
cur_trb->generic.field[3] |= cpu_to_le32(
TRB_TYPE(TRB_TR_NOOP));
xhci_dbg(xhci, "Cancel TRB %p (0x%llx dma) "
"in seg %p (0x%llx dma)\n",
cur_trb,
(unsigned long long)xhci_trb_virt_to_dma(cur_seg, cur_trb),
cur_seg,
(unsigned long long)cur_seg->dma);
}
if (cur_trb == cur_td->last_trb)
break;
}
}
void xhci_queue_new_dequeue_state(struct xhci_hcd *xhci,
unsigned int slot_id, unsigned int ep_index,
unsigned int stream_id,
struct xhci_dequeue_state *deq_state)
{
struct xhci_virt_ep *ep = &xhci->devs[slot_id]->eps[ep_index];
xhci_dbg(xhci, "Set TR Deq Ptr cmd, new deq seg = %p (0x%llx dma), "
"new deq ptr = %p (0x%llx dma), new cycle = %u\n",
deq_state->new_deq_seg,
(unsigned long long)deq_state->new_deq_seg->dma,
deq_state->new_deq_ptr,
(unsigned long long)xhci_trb_virt_to_dma(deq_state->new_deq_seg, deq_state->new_deq_ptr),
deq_state->new_cycle_state);
queue_set_tr_deq(xhci, slot_id, ep_index, stream_id,
deq_state->new_deq_seg,
deq_state->new_deq_ptr,
(u32) deq_state->new_cycle_state);
ep->ep_state |= SET_DEQ_PENDING;
}
static void xhci_stop_watchdog_timer_in_irq(struct xhci_hcd *xhci,
struct xhci_virt_ep *ep)
{
ep->ep_state &= ~EP_HALT_PENDING;
if (del_timer(&ep->stop_cmd_timer))
ep->stop_cmds_pending--;
}
static void xhci_giveback_urb_in_irq(struct xhci_hcd *xhci,
struct xhci_td *cur_td, int status, char *adjective)
{
struct usb_hcd *hcd;
struct urb *urb;
struct urb_priv *urb_priv;
urb = cur_td->urb;
urb_priv = urb->hcpriv;
urb_priv->td_cnt++;
hcd = bus_to_hcd(urb->dev->bus);
if (urb_priv->td_cnt == urb_priv->length) {
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS) {
xhci_to_hcd(xhci)->self.bandwidth_isoc_reqs--;
if (xhci_to_hcd(xhci)->self.bandwidth_isoc_reqs == 0) {
if (xhci->quirks & XHCI_AMD_PLL_FIX)
usb_amd_quirk_pll_enable();
}
}
usb_hcd_unlink_urb_from_ep(hcd, urb);
spin_unlock(&xhci->lock);
usb_hcd_giveback_urb(hcd, urb, status);
xhci_urb_free_priv(xhci, urb_priv);
spin_lock(&xhci->lock);
}
}
static void handle_stopped_endpoint(struct xhci_hcd *xhci,
union xhci_trb *trb, struct xhci_event_cmd *event)
{
unsigned int slot_id;
unsigned int ep_index;
struct xhci_virt_device *virt_dev;
struct xhci_ring *ep_ring;
struct xhci_virt_ep *ep;
struct list_head *entry;
struct xhci_td *cur_td = NULL;
struct xhci_td *last_unlinked_td;
struct xhci_dequeue_state deq_state;
if (unlikely(TRB_TO_SUSPEND_PORT(
le32_to_cpu(xhci->cmd_ring->dequeue->generic.field[3])))) {
slot_id = TRB_TO_SLOT_ID(
le32_to_cpu(xhci->cmd_ring->dequeue->generic.field[3]));
virt_dev = xhci->devs[slot_id];
if (virt_dev)
handle_cmd_in_cmd_wait_list(xhci, virt_dev,
event);
else
xhci_warn(xhci, "Stop endpoint command "
"completion for disabled slot %u\n",
slot_id);
return;
}
memset(&deq_state, 0, sizeof(deq_state));
slot_id = TRB_TO_SLOT_ID(le32_to_cpu(trb->generic.field[3]));
ep_index = TRB_TO_EP_INDEX(le32_to_cpu(trb->generic.field[3]));
ep = &xhci->devs[slot_id]->eps[ep_index];
if (list_empty(&ep->cancelled_td_list)) {
xhci_stop_watchdog_timer_in_irq(xhci, ep);
ep->stopped_td = NULL;
ep->stopped_trb = NULL;
ring_doorbell_for_active_rings(xhci, slot_id, ep_index);
return;
}
list_for_each(entry, &ep->cancelled_td_list) {
cur_td = list_entry(entry, struct xhci_td, cancelled_td_list);
xhci_dbg(xhci, "Cancelling TD starting at %p, 0x%llx (dma).\n",
cur_td->first_trb,
(unsigned long long)xhci_trb_virt_to_dma(cur_td->start_seg, cur_td->first_trb));
ep_ring = xhci_urb_to_transfer_ring(xhci, cur_td->urb);
if (!ep_ring) {
xhci_warn(xhci, "WARN Cancelled URB %p "
"has invalid stream ID %u.\n",
cur_td->urb,
cur_td->urb->stream_id);
goto remove_finished_td;
}
if (cur_td == ep->stopped_td)
xhci_find_new_dequeue_state(xhci, slot_id, ep_index,
cur_td->urb->stream_id,
cur_td, &deq_state);
else
td_to_noop(xhci, ep_ring, cur_td, false);
remove_finished_td:
list_del_init(&cur_td->td_list);
}
last_unlinked_td = cur_td;
xhci_stop_watchdog_timer_in_irq(xhci, ep);
if (deq_state.new_deq_ptr && deq_state.new_deq_seg) {
xhci_queue_new_dequeue_state(xhci,
slot_id, ep_index,
ep->stopped_td->urb->stream_id,
&deq_state);
xhci_ring_cmd_db(xhci);
} else {
ring_doorbell_for_active_rings(xhci, slot_id, ep_index);
}
ep->stopped_td = NULL;
ep->stopped_trb = NULL;
do {
cur_td = list_entry(ep->cancelled_td_list.next,
struct xhci_td, cancelled_td_list);
list_del_init(&cur_td->cancelled_td_list);
xhci_giveback_urb_in_irq(xhci, cur_td, 0, "cancelled");
if (xhci->xhc_state & XHCI_STATE_DYING)
return;
} while (cur_td != last_unlinked_td);
}
void xhci_stop_endpoint_command_watchdog(unsigned long arg)
{
struct xhci_hcd *xhci;
struct xhci_virt_ep *ep;
struct xhci_virt_ep *temp_ep;
struct xhci_ring *ring;
struct xhci_td *cur_td;
int ret, i, j;
ep = (struct xhci_virt_ep *) arg;
xhci = ep->xhci;
spin_lock(&xhci->lock);
ep->stop_cmds_pending--;
if (xhci->xhc_state & XHCI_STATE_DYING) {
xhci_dbg(xhci, "Stop EP timer ran, but another timer marked "
"xHCI as DYING, exiting.\n");
spin_unlock(&xhci->lock);
return;
}
if (!(ep->stop_cmds_pending == 0 && (ep->ep_state & EP_HALT_PENDING))) {
xhci_dbg(xhci, "Stop EP timer ran, but no command pending, "
"exiting.\n");
spin_unlock(&xhci->lock);
return;
}
xhci_warn(xhci, "xHCI host not responding to stop endpoint command.\n");
xhci_warn(xhci, "Assuming host is dying, halting host.\n");
xhci->xhc_state |= XHCI_STATE_DYING;
xhci_quiesce(xhci);
spin_unlock(&xhci->lock);
ret = xhci_halt(xhci);
spin_lock(&xhci->lock);
if (ret < 0) {
xhci_warn(xhci, "Non-responsive xHCI host is not halting.\n");
xhci_warn(xhci, "Completing active URBs anyway.\n");
}
for (i = 0; i < MAX_HC_SLOTS; i++) {
if (!xhci->devs[i])
continue;
for (j = 0; j < 31; j++) {
temp_ep = &xhci->devs[i]->eps[j];
ring = temp_ep->ring;
if (!ring)
continue;
xhci_dbg(xhci, "Killing URBs for slot ID %u, "
"ep index %u\n", i, j);
while (!list_empty(&ring->td_list)) {
cur_td = list_first_entry(&ring->td_list,
struct xhci_td,
td_list);
list_del_init(&cur_td->td_list);
if (!list_empty(&cur_td->cancelled_td_list))
list_del_init(&cur_td->cancelled_td_list);
xhci_giveback_urb_in_irq(xhci, cur_td,
-ESHUTDOWN, "killed");
}
while (!list_empty(&temp_ep->cancelled_td_list)) {
cur_td = list_first_entry(
&temp_ep->cancelled_td_list,
struct xhci_td,
cancelled_td_list);
list_del_init(&cur_td->cancelled_td_list);
xhci_giveback_urb_in_irq(xhci, cur_td,
-ESHUTDOWN, "killed");
}
}
}
spin_unlock(&xhci->lock);
xhci_dbg(xhci, "Calling usb_hc_died()\n");
usb_hc_died(xhci_to_hcd(xhci)->primary_hcd);
xhci_dbg(xhci, "xHCI host controller is dead.\n");
}
static void handle_set_deq_completion(struct xhci_hcd *xhci,
struct xhci_event_cmd *event,
union xhci_trb *trb)
{
unsigned int slot_id;
unsigned int ep_index;
unsigned int stream_id;
struct xhci_ring *ep_ring;
struct xhci_virt_device *dev;
struct xhci_ep_ctx *ep_ctx;
struct xhci_slot_ctx *slot_ctx;
slot_id = TRB_TO_SLOT_ID(le32_to_cpu(trb->generic.field[3]));
ep_index = TRB_TO_EP_INDEX(le32_to_cpu(trb->generic.field[3]));
stream_id = TRB_TO_STREAM_ID(le32_to_cpu(trb->generic.field[2]));
dev = xhci->devs[slot_id];
ep_ring = xhci_stream_id_to_ring(dev, ep_index, stream_id);
if (!ep_ring) {
xhci_warn(xhci, "WARN Set TR deq ptr command for "
"freed stream ID %u\n",
stream_id);
dev->eps[ep_index].ep_state &= ~SET_DEQ_PENDING;
return;
}
ep_ctx = xhci_get_ep_ctx(xhci, dev->out_ctx, ep_index);
slot_ctx = xhci_get_slot_ctx(xhci, dev->out_ctx);
if (GET_COMP_CODE(le32_to_cpu(event->status)) != COMP_SUCCESS) {
unsigned int ep_state;
unsigned int slot_state;
switch (GET_COMP_CODE(le32_to_cpu(event->status))) {
case COMP_TRB_ERR:
xhci_warn(xhci, "WARN Set TR Deq Ptr cmd invalid because "
"of stream ID configuration\n");
break;
case COMP_CTX_STATE:
xhci_warn(xhci, "WARN Set TR Deq Ptr cmd failed due "
"to incorrect slot or ep state.\n");
ep_state = le32_to_cpu(ep_ctx->ep_info);
ep_state &= EP_STATE_MASK;
slot_state = le32_to_cpu(slot_ctx->dev_state);
slot_state = GET_SLOT_STATE(slot_state);
xhci_dbg(xhci, "Slot state = %u, EP state = %u\n",
slot_state, ep_state);
break;
case COMP_EBADSLT:
xhci_warn(xhci, "WARN Set TR Deq Ptr cmd failed because "
"slot %u was not enabled.\n", slot_id);
break;
default:
xhci_warn(xhci, "WARN Set TR Deq Ptr cmd with unknown "
"completion code of %u.\n",
GET_COMP_CODE(le32_to_cpu(event->status)));
break;
}
} else {
xhci_dbg(xhci, "Successful Set TR Deq Ptr cmd, deq = @%08llx\n",
le64_to_cpu(ep_ctx->deq));
if (xhci_trb_virt_to_dma(dev->eps[ep_index].queued_deq_seg,
dev->eps[ep_index].queued_deq_ptr) ==
(le64_to_cpu(ep_ctx->deq) & ~(EP_CTX_CYCLE_MASK))) {
ep_ring->deq_seg = dev->eps[ep_index].queued_deq_seg;
ep_ring->dequeue = dev->eps[ep_index].queued_deq_ptr;
} else {
xhci_warn(xhci, "Mismatch between completed Set TR Deq "
"Ptr command & xHCI internal state.\n");
xhci_warn(xhci, "ep deq seg = %p, deq ptr = %p\n",
dev->eps[ep_index].queued_deq_seg,
dev->eps[ep_index].queued_deq_ptr);
}
}
dev->eps[ep_index].ep_state &= ~SET_DEQ_PENDING;
dev->eps[ep_index].queued_deq_seg = NULL;
dev->eps[ep_index].queued_deq_ptr = NULL;
ring_doorbell_for_active_rings(xhci, slot_id, ep_index);
}
static void handle_reset_ep_completion(struct xhci_hcd *xhci,
struct xhci_event_cmd *event,
union xhci_trb *trb)
{
int slot_id;
unsigned int ep_index;
slot_id = TRB_TO_SLOT_ID(le32_to_cpu(trb->generic.field[3]));
ep_index = TRB_TO_EP_INDEX(le32_to_cpu(trb->generic.field[3]));
xhci_dbg(xhci, "Ignoring reset ep completion code of %u\n",
GET_COMP_CODE(le32_to_cpu(event->status)));
if (xhci->quirks & XHCI_RESET_EP_QUIRK) {
xhci_dbg(xhci, "Queueing configure endpoint command\n");
xhci_queue_configure_endpoint(xhci,
xhci->devs[slot_id]->in_ctx->dma, slot_id,
false);
xhci_ring_cmd_db(xhci);
} else {
xhci->devs[slot_id]->eps[ep_index].ep_state &= ~EP_HALTED;
ring_doorbell_for_active_rings(xhci, slot_id, ep_index);
}
}
static int handle_cmd_in_cmd_wait_list(struct xhci_hcd *xhci,
struct xhci_virt_device *virt_dev,
struct xhci_event_cmd *event)
{
struct xhci_command *command;
if (list_empty(&virt_dev->cmd_list))
return 0;
command = list_entry(virt_dev->cmd_list.next,
struct xhci_command, cmd_list);
if (xhci->cmd_ring->dequeue != command->command_trb)
return 0;
command->status = GET_COMP_CODE(le32_to_cpu(event->status));
list_del(&command->cmd_list);
if (command->completion)
complete(command->completion);
else
xhci_free_command(xhci, command);
return 1;
}
static void handle_cmd_completion(struct xhci_hcd *xhci,
struct xhci_event_cmd *event)
{
int slot_id = TRB_TO_SLOT_ID(le32_to_cpu(event->flags));
u64 cmd_dma;
dma_addr_t cmd_dequeue_dma;
struct xhci_input_control_ctx *ctrl_ctx;
struct xhci_virt_device *virt_dev;
unsigned int ep_index;
struct xhci_ring *ep_ring;
unsigned int ep_state;
cmd_dma = le64_to_cpu(event->cmd_trb);
cmd_dequeue_dma = xhci_trb_virt_to_dma(xhci->cmd_ring->deq_seg,
xhci->cmd_ring->dequeue);
if (cmd_dequeue_dma == 0) {
xhci->error_bitmask |= 1 << 4;
return;
}
if (cmd_dma != (u64) cmd_dequeue_dma) {
xhci->error_bitmask |= 1 << 5;
return;
}
switch (le32_to_cpu(xhci->cmd_ring->dequeue->generic.field[3])
& TRB_TYPE_BITMASK) {
case TRB_TYPE(TRB_ENABLE_SLOT):
if (GET_COMP_CODE(le32_to_cpu(event->status)) == COMP_SUCCESS)
xhci->slot_id = slot_id;
else
xhci->slot_id = 0;
complete(&xhci->addr_dev);
break;
case TRB_TYPE(TRB_DISABLE_SLOT):
if (xhci->devs[slot_id]) {
if (xhci->quirks & XHCI_EP_LIMIT_QUIRK)
xhci_free_device_endpoint_resources(xhci,
xhci->devs[slot_id], true);
xhci_free_virt_device(xhci, slot_id);
}
break;
case TRB_TYPE(TRB_CONFIG_EP):
virt_dev = xhci->devs[slot_id];
if (handle_cmd_in_cmd_wait_list(xhci, virt_dev, event))
break;
ctrl_ctx = xhci_get_input_control_ctx(xhci,
virt_dev->in_ctx);
ep_index = xhci_last_valid_endpoint(le32_to_cpu(ctrl_ctx->add_flags)) - 1;
if (xhci->quirks & XHCI_RESET_EP_QUIRK &&
ep_index != (unsigned int) -1 &&
le32_to_cpu(ctrl_ctx->add_flags) - SLOT_FLAG ==
le32_to_cpu(ctrl_ctx->drop_flags)) {
ep_ring = xhci->devs[slot_id]->eps[ep_index].ring;
ep_state = xhci->devs[slot_id]->eps[ep_index].ep_state;
if (!(ep_state & EP_HALTED))
goto bandwidth_change;
xhci_dbg(xhci, "Completed config ep cmd - "
"last ep index = %d, state = %d\n",
ep_index, ep_state);
xhci->devs[slot_id]->eps[ep_index].ep_state &=
~EP_HALTED;
ring_doorbell_for_active_rings(xhci, slot_id, ep_index);
break;
}
bandwidth_change:
xhci_dbg(xhci, "Completed config ep cmd\n");
xhci->devs[slot_id]->cmd_status =
GET_COMP_CODE(le32_to_cpu(event->status));
complete(&xhci->devs[slot_id]->cmd_completion);
break;
case TRB_TYPE(TRB_EVAL_CONTEXT):
virt_dev = xhci->devs[slot_id];
if (handle_cmd_in_cmd_wait_list(xhci, virt_dev, event))
break;
xhci->devs[slot_id]->cmd_status = GET_COMP_CODE(le32_to_cpu(event->status));
complete(&xhci->devs[slot_id]->cmd_completion);
break;
case TRB_TYPE(TRB_ADDR_DEV):
xhci->devs[slot_id]->cmd_status = GET_COMP_CODE(le32_to_cpu(event->status));
complete(&xhci->addr_dev);
break;
case TRB_TYPE(TRB_STOP_RING):
handle_stopped_endpoint(xhci, xhci->cmd_ring->dequeue, event);
break;
case TRB_TYPE(TRB_SET_DEQ):
handle_set_deq_completion(xhci, event, xhci->cmd_ring->dequeue);
break;
case TRB_TYPE(TRB_CMD_NOOP):
break;
case TRB_TYPE(TRB_RESET_EP):
handle_reset_ep_completion(xhci, event, xhci->cmd_ring->dequeue);
break;
case TRB_TYPE(TRB_RESET_DEV):
xhci_dbg(xhci, "Completed reset device command.\n");
slot_id = TRB_TO_SLOT_ID(
le32_to_cpu(xhci->cmd_ring->dequeue->generic.field[3]));
virt_dev = xhci->devs[slot_id];
if (virt_dev)
handle_cmd_in_cmd_wait_list(xhci, virt_dev, event);
else
xhci_warn(xhci, "Reset device command completion "
"for disabled slot %u\n", slot_id);
break;
case TRB_TYPE(TRB_NEC_GET_FW):
if (!(xhci->quirks & XHCI_NEC_HOST)) {
xhci->error_bitmask |= 1 << 6;
break;
}
xhci_dbg(xhci, "NEC firmware version %2x.%02x\n",
NEC_FW_MAJOR(le32_to_cpu(event->status)),
NEC_FW_MINOR(le32_to_cpu(event->status)));
break;
default:
xhci->error_bitmask |= 1 << 6;
break;
}
inc_deq(xhci, xhci->cmd_ring, false);
}
static void handle_vendor_event(struct xhci_hcd *xhci,
union xhci_trb *event)
{
u32 trb_type;
trb_type = TRB_FIELD_TO_TYPE(le32_to_cpu(event->generic.field[3]));
xhci_dbg(xhci, "Vendor specific event TRB type = %u\n", trb_type);
if (trb_type == TRB_NEC_CMD_COMP && (xhci->quirks & XHCI_NEC_HOST))
handle_cmd_completion(xhci, &event->event_cmd);
}
static unsigned int find_faked_portnum_from_hw_portnum(struct usb_hcd *hcd,
struct xhci_hcd *xhci, u32 port_id)
{
unsigned int i;
unsigned int num_similar_speed_ports = 0;
for (i = 0; i < (port_id - 1); i++) {
u8 port_speed = xhci->port_array[i];
if (port_speed == 0 || port_speed == DUPLICATE_ENTRY)
continue;
if ((port_speed == 0x03) == (hcd->speed == HCD_USB3))
num_similar_speed_ports++;
}
return num_similar_speed_ports;
}
static void handle_port_status(struct xhci_hcd *xhci,
union xhci_trb *event)
{
struct usb_hcd *hcd;
u32 port_id;
u32 temp, temp1;
int max_ports;
int slot_id;
unsigned int faked_port_index;
u8 major_revision;
struct xhci_bus_state *bus_state;
__le32 __iomem **port_array;
bool bogus_port_status = false;
if (GET_COMP_CODE(le32_to_cpu(event->generic.field[2])) != COMP_SUCCESS) {
xhci_warn(xhci, "WARN: xHC returned failed port status event\n");
xhci->error_bitmask |= 1 << 8;
}
port_id = GET_PORT_ID(le32_to_cpu(event->generic.field[0]));
xhci_dbg(xhci, "Port Status Change Event for port %d\n", port_id);
max_ports = HCS_MAX_PORTS(xhci->hcs_params1);
if ((port_id <= 0) || (port_id > max_ports)) {
xhci_warn(xhci, "Invalid port id %d\n", port_id);
bogus_port_status = true;
goto cleanup;
}
major_revision = xhci->port_array[port_id - 1];
if (major_revision == 0) {
xhci_warn(xhci, "Event for port %u not in "
"Extended Capabilities, ignoring.\n",
port_id);
bogus_port_status = true;
goto cleanup;
}
if (major_revision == DUPLICATE_ENTRY) {
xhci_warn(xhci, "Event for port %u duplicated in"
"Extended Capabilities, ignoring.\n",
port_id);
bogus_port_status = true;
goto cleanup;
}
hcd = xhci_to_hcd(xhci);
if ((major_revision == 0x03) != (hcd->speed == HCD_USB3))
hcd = xhci->shared_hcd;
bus_state = &xhci->bus_state[hcd_index(hcd)];
if (hcd->speed == HCD_USB3)
port_array = xhci->usb3_ports;
else
port_array = xhci->usb2_ports;
faked_port_index = find_faked_portnum_from_hw_portnum(hcd, xhci,
port_id);
temp = xhci_readl(xhci, port_array[faked_port_index]);
if (hcd->state == HC_STATE_SUSPENDED) {
xhci_dbg(xhci, "resume root hub\n");
usb_hcd_resume_root_hub(hcd);
}
if ((temp & PORT_PLC) && (temp & PORT_PLS_MASK) == XDEV_RESUME) {
xhci_dbg(xhci, "port resume event for port %d\n", port_id);
temp1 = xhci_readl(xhci, &xhci->op_regs->command);
if (!(temp1 & CMD_RUN)) {
xhci_warn(xhci, "xHC is not running.\n");
goto cleanup;
}
if (DEV_SUPERSPEED(temp)) {
xhci_dbg(xhci, "resume SS port %d\n", port_id);
temp = xhci_port_state_to_neutral(temp);
temp &= ~PORT_PLS_MASK;
temp |= PORT_LINK_STROBE | XDEV_U0;
xhci_writel(xhci, temp, port_array[faked_port_index]);
slot_id = xhci_find_slot_id_by_port(hcd, xhci,
faked_port_index);
if (!slot_id) {
xhci_dbg(xhci, "slot_id is zero\n");
goto cleanup;
}
xhci_ring_device(xhci, slot_id);
xhci_dbg(xhci, "resume SS port %d finished\n", port_id);
temp = xhci_readl(xhci, port_array[faked_port_index]);
temp = xhci_port_state_to_neutral(temp);
temp |= PORT_PLC;
xhci_writel(xhci, temp, port_array[faked_port_index]);
} else {
xhci_dbg(xhci, "resume HS port %d\n", port_id);
bus_state->resume_done[faked_port_index] = jiffies +
msecs_to_jiffies(20);
mod_timer(&hcd->rh_timer,
bus_state->resume_done[faked_port_index]);
}
}
cleanup:
inc_deq(xhci, xhci->event_ring, true);
if (bogus_port_status)
return;
spin_unlock(&xhci->lock);
usb_hcd_poll_rh_status(hcd);
spin_lock(&xhci->lock);
}
struct xhci_segment *trb_in_td(struct xhci_segment *start_seg,
union xhci_trb *start_trb,
union xhci_trb *end_trb,
dma_addr_t suspect_dma)
{
dma_addr_t start_dma;
dma_addr_t end_seg_dma;
dma_addr_t end_trb_dma;
struct xhci_segment *cur_seg;
start_dma = xhci_trb_virt_to_dma(start_seg, start_trb);
cur_seg = start_seg;
do {
if (start_dma == 0)
return NULL;
end_seg_dma = xhci_trb_virt_to_dma(cur_seg,
&cur_seg->trbs[TRBS_PER_SEGMENT - 1]);
end_trb_dma = xhci_trb_virt_to_dma(cur_seg, end_trb);
if (end_trb_dma > 0) {
if (start_dma <= end_trb_dma) {
if (suspect_dma >= start_dma && suspect_dma <= end_trb_dma)
return cur_seg;
} else {
if ((suspect_dma >= start_dma &&
suspect_dma <= end_seg_dma) ||
(suspect_dma >= cur_seg->dma &&
suspect_dma <= end_trb_dma))
return cur_seg;
}
return NULL;
} else {
if (suspect_dma >= start_dma && suspect_dma <= end_seg_dma)
return cur_seg;
}
cur_seg = cur_seg->next;
start_dma = xhci_trb_virt_to_dma(cur_seg, &cur_seg->trbs[0]);
} while (cur_seg != start_seg);
return NULL;
}
static void xhci_cleanup_halted_endpoint(struct xhci_hcd *xhci,
unsigned int slot_id, unsigned int ep_index,
unsigned int stream_id,
struct xhci_td *td, union xhci_trb *event_trb)
{
struct xhci_virt_ep *ep = &xhci->devs[slot_id]->eps[ep_index];
ep->ep_state |= EP_HALTED;
ep->stopped_td = td;
ep->stopped_trb = event_trb;
ep->stopped_stream = stream_id;
xhci_queue_reset_ep(xhci, slot_id, ep_index);
xhci_cleanup_stalled_ring(xhci, td->urb->dev, ep_index);
ep->stopped_td = NULL;
ep->stopped_trb = NULL;
ep->stopped_stream = 0;
xhci_ring_cmd_db(xhci);
}
static int xhci_requires_manual_halt_cleanup(struct xhci_hcd *xhci,
struct xhci_ep_ctx *ep_ctx,
unsigned int trb_comp_code)
{
if (trb_comp_code == COMP_TX_ERR ||
trb_comp_code == COMP_BABBLE ||
trb_comp_code == COMP_SPLIT_ERR)
if ((ep_ctx->ep_info & cpu_to_le32(EP_STATE_MASK)) ==
cpu_to_le32(EP_STATE_HALTED))
return 1;
return 0;
}
int xhci_is_vendor_info_code(struct xhci_hcd *xhci, unsigned int trb_comp_code)
{
if (trb_comp_code >= 224 && trb_comp_code <= 255) {
xhci_dbg(xhci, "Vendor defined info completion code %u\n",
trb_comp_code);
xhci_dbg(xhci, "Treating code as success.\n");
return 1;
}
return 0;
}
static int finish_td(struct xhci_hcd *xhci, struct xhci_td *td,
union xhci_trb *event_trb, struct xhci_transfer_event *event,
struct xhci_virt_ep *ep, int *status, bool skip)
{
struct xhci_virt_device *xdev;
struct xhci_ring *ep_ring;
unsigned int slot_id;
int ep_index;
struct urb *urb = NULL;
struct xhci_ep_ctx *ep_ctx;
int ret = 0;
struct urb_priv *urb_priv;
u32 trb_comp_code;
slot_id = TRB_TO_SLOT_ID(le32_to_cpu(event->flags));
xdev = xhci->devs[slot_id];
ep_index = TRB_TO_EP_ID(le32_to_cpu(event->flags)) - 1;
ep_ring = xhci_dma_to_transfer_ring(ep, le64_to_cpu(event->buffer));
ep_ctx = xhci_get_ep_ctx(xhci, xdev->out_ctx, ep_index);
trb_comp_code = GET_COMP_CODE(le32_to_cpu(event->transfer_len));
if (skip)
goto td_cleanup;
if (trb_comp_code == COMP_STOP_INVAL ||
trb_comp_code == COMP_STOP) {
ep->stopped_td = td;
ep->stopped_trb = event_trb;
return 0;
} else {
if (trb_comp_code == COMP_STALL) {
ep->stopped_td = td;
ep->stopped_trb = event_trb;
ep->stopped_stream = ep_ring->stream_id;
} else if (xhci_requires_manual_halt_cleanup(xhci,
ep_ctx, trb_comp_code)) {
xhci_cleanup_halted_endpoint(xhci,
slot_id, ep_index, ep_ring->stream_id,
td, event_trb);
} else {
while (ep_ring->dequeue != td->last_trb)
inc_deq(xhci, ep_ring, false);
inc_deq(xhci, ep_ring, false);
}
td_cleanup:
urb = td->urb;
urb_priv = urb->hcpriv;
if (urb->actual_length > urb->transfer_buffer_length) {
xhci_warn(xhci, "URB transfer length is wrong, "
"xHC issue? req. len = %u, "
"act. len = %u\n",
urb->transfer_buffer_length,
urb->actual_length);
urb->actual_length = 0;
if (td->urb->transfer_flags & URB_SHORT_NOT_OK)
*status = -EREMOTEIO;
else
*status = 0;
}
list_del_init(&td->td_list);
if (!list_empty(&td->cancelled_td_list))
list_del_init(&td->cancelled_td_list);
urb_priv->td_cnt++;
if (urb_priv->td_cnt == urb_priv->length) {
ret = 1;
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS) {
xhci_to_hcd(xhci)->self.bandwidth_isoc_reqs--;
if (xhci_to_hcd(xhci)->self.bandwidth_isoc_reqs
== 0) {
if (xhci->quirks & XHCI_AMD_PLL_FIX)
usb_amd_quirk_pll_enable();
}
}
}
}
return ret;
}
static int process_ctrl_td(struct xhci_hcd *xhci, struct xhci_td *td,
union xhci_trb *event_trb, struct xhci_transfer_event *event,
struct xhci_virt_ep *ep, int *status)
{
struct xhci_virt_device *xdev;
struct xhci_ring *ep_ring;
unsigned int slot_id;
int ep_index;
struct xhci_ep_ctx *ep_ctx;
u32 trb_comp_code;
slot_id = TRB_TO_SLOT_ID(le32_to_cpu(event->flags));
xdev = xhci->devs[slot_id];
ep_index = TRB_TO_EP_ID(le32_to_cpu(event->flags)) - 1;
ep_ring = xhci_dma_to_transfer_ring(ep, le64_to_cpu(event->buffer));
ep_ctx = xhci_get_ep_ctx(xhci, xdev->out_ctx, ep_index);
trb_comp_code = GET_COMP_CODE(le32_to_cpu(event->transfer_len));
xhci_debug_trb(xhci, xhci->event_ring->dequeue);
switch (trb_comp_code) {
case COMP_SUCCESS:
if (event_trb == ep_ring->dequeue) {
xhci_warn(xhci, "WARN: Success on ctrl setup TRB "
"without IOC set??\n");
*status = -ESHUTDOWN;
} else if (event_trb != td->last_trb) {
xhci_warn(xhci, "WARN: Success on ctrl data TRB "
"without IOC set??\n");
*status = -ESHUTDOWN;
} else {
*status = 0;
}
break;
case COMP_SHORT_TX:
xhci_warn(xhci, "WARN: short transfer on control ep\n");
if (td->urb->transfer_flags & URB_SHORT_NOT_OK)
*status = -EREMOTEIO;
else
*status = 0;
break;
case COMP_STOP_INVAL:
case COMP_STOP:
return finish_td(xhci, td, event_trb, event, ep, status, false);
default:
if (!xhci_requires_manual_halt_cleanup(xhci,
ep_ctx, trb_comp_code))
break;
xhci_dbg(xhci, "TRB error code %u, "
"halted endpoint index = %u\n",
trb_comp_code, ep_index);
case COMP_STALL:
if (event_trb != ep_ring->dequeue &&
event_trb != td->last_trb)
td->urb->actual_length =
td->urb->transfer_buffer_length
- TRB_LEN(le32_to_cpu(event->transfer_len));
else
td->urb->actual_length = 0;
xhci_cleanup_halted_endpoint(xhci,
slot_id, ep_index, 0, td, event_trb);
return finish_td(xhci, td, event_trb, event, ep, status, true);
}
if (event_trb != ep_ring->dequeue) {
if (event_trb == td->last_trb) {
if (td->urb->actual_length != 0) {
if ((*status == -EINPROGRESS || *status == 0) &&
(td->urb->transfer_flags
& URB_SHORT_NOT_OK))
*status = -EREMOTEIO;
} else {
td->urb->actual_length =
td->urb->transfer_buffer_length;
}
} else {
td->urb->actual_length =
td->urb->transfer_buffer_length -
TRB_LEN(le32_to_cpu(event->transfer_len));
xhci_dbg(xhci, "Waiting for status "
"stage event\n");
return 0;
}
}
return finish_td(xhci, td, event_trb, event, ep, status, false);
}
static int process_isoc_td(struct xhci_hcd *xhci, struct xhci_td *td,
union xhci_trb *event_trb, struct xhci_transfer_event *event,
struct xhci_virt_ep *ep, int *status)
{
struct xhci_ring *ep_ring;
struct urb_priv *urb_priv;
int idx;
int len = 0;
union xhci_trb *cur_trb;
struct xhci_segment *cur_seg;
struct usb_iso_packet_descriptor *frame;
u32 trb_comp_code;
bool skip_td = false;
ep_ring = xhci_dma_to_transfer_ring(ep, le64_to_cpu(event->buffer));
trb_comp_code = GET_COMP_CODE(le32_to_cpu(event->transfer_len));
urb_priv = td->urb->hcpriv;
idx = urb_priv->td_cnt;
frame = &td->urb->iso_frame_desc[idx];
switch (trb_comp_code) {
case COMP_SUCCESS:
frame->status = 0;
break;
case COMP_SHORT_TX:
frame->status = td->urb->transfer_flags & URB_SHORT_NOT_OK ?
-EREMOTEIO : 0;
break;
case COMP_BW_OVER:
frame->status = -ECOMM;
skip_td = true;
break;
case COMP_BUFF_OVER:
case COMP_BABBLE:
frame->status = -EOVERFLOW;
skip_td = true;
break;
case COMP_DEV_ERR:
case COMP_STALL:
frame->status = -EPROTO;
skip_td = true;
break;
case COMP_STOP:
case COMP_STOP_INVAL:
break;
default:
frame->status = -1;
break;
}
if (trb_comp_code == COMP_SUCCESS || skip_td) {
frame->actual_length = frame->length;
td->urb->actual_length += frame->length;
} else {
for (cur_trb = ep_ring->dequeue,
cur_seg = ep_ring->deq_seg; cur_trb != event_trb;
next_trb(xhci, ep_ring, &cur_seg, &cur_trb)) {
if (!TRB_TYPE_NOOP_LE32(cur_trb->generic.field[3]) &&
!TRB_TYPE_LINK_LE32(cur_trb->generic.field[3]))
len += TRB_LEN(le32_to_cpu(cur_trb->generic.field[2]));
}
len += TRB_LEN(le32_to_cpu(cur_trb->generic.field[2])) -
TRB_LEN(le32_to_cpu(event->transfer_len));
if (trb_comp_code != COMP_STOP_INVAL) {
frame->actual_length = len;
td->urb->actual_length += len;
}
}
return finish_td(xhci, td, event_trb, event, ep, status, false);
}
static int skip_isoc_td(struct xhci_hcd *xhci, struct xhci_td *td,
struct xhci_transfer_event *event,
struct xhci_virt_ep *ep, int *status)
{
struct xhci_ring *ep_ring;
struct urb_priv *urb_priv;
struct usb_iso_packet_descriptor *frame;
int idx;
ep_ring = xhci_dma_to_transfer_ring(ep, le64_to_cpu(event->buffer));
urb_priv = td->urb->hcpriv;
idx = urb_priv->td_cnt;
frame = &td->urb->iso_frame_desc[idx];
frame->status = -EXDEV;
frame->actual_length = 0;
while (ep_ring->dequeue != td->last_trb)
inc_deq(xhci, ep_ring, false);
inc_deq(xhci, ep_ring, false);
return finish_td(xhci, td, NULL, event, ep, status, true);
}
static int process_bulk_intr_td(struct xhci_hcd *xhci, struct xhci_td *td,
union xhci_trb *event_trb, struct xhci_transfer_event *event,
struct xhci_virt_ep *ep, int *status)
{
struct xhci_ring *ep_ring;
union xhci_trb *cur_trb;
struct xhci_segment *cur_seg;
u32 trb_comp_code;
ep_ring = xhci_dma_to_transfer_ring(ep, le64_to_cpu(event->buffer));
trb_comp_code = GET_COMP_CODE(le32_to_cpu(event->transfer_len));
switch (trb_comp_code) {
case COMP_SUCCESS:
if (event_trb != td->last_trb) {
xhci_warn(xhci, "WARN Successful completion "
"on short TX\n");
if (td->urb->transfer_flags & URB_SHORT_NOT_OK)
*status = -EREMOTEIO;
else
*status = 0;
} else {
*status = 0;
}
break;
case COMP_SHORT_TX:
if (td->urb->transfer_flags & URB_SHORT_NOT_OK)
*status = -EREMOTEIO;
else
*status = 0;
break;
default:
break;
}
if (trb_comp_code == COMP_SHORT_TX)
xhci_dbg(xhci, "ep %#x - asked for %d bytes, "
"%d bytes untransferred\n",
td->urb->ep->desc.bEndpointAddress,
td->urb->transfer_buffer_length,
TRB_LEN(le32_to_cpu(event->transfer_len)));
if (event_trb == td->last_trb) {
if (TRB_LEN(le32_to_cpu(event->transfer_len)) != 0) {
td->urb->actual_length =
td->urb->transfer_buffer_length -
TRB_LEN(le32_to_cpu(event->transfer_len));
if (td->urb->transfer_buffer_length <
td->urb->actual_length) {
xhci_warn(xhci, "HC gave bad length "
"of %d bytes left\n",
TRB_LEN(le32_to_cpu(event->transfer_len)));
td->urb->actual_length = 0;
if (td->urb->transfer_flags & URB_SHORT_NOT_OK)
*status = -EREMOTEIO;
else
*status = 0;
}
if (*status == -EINPROGRESS) {
if (td->urb->transfer_flags & URB_SHORT_NOT_OK)
*status = -EREMOTEIO;
else
*status = 0;
}
} else {
td->urb->actual_length =
td->urb->transfer_buffer_length;
if (*status == -EREMOTEIO)
*status = 0;
}
} else {
td->urb->actual_length = 0;
for (cur_trb = ep_ring->dequeue, cur_seg = ep_ring->deq_seg;
cur_trb != event_trb;
next_trb(xhci, ep_ring, &cur_seg, &cur_trb)) {
if (!TRB_TYPE_NOOP_LE32(cur_trb->generic.field[3]) &&
!TRB_TYPE_LINK_LE32(cur_trb->generic.field[3]))
td->urb->actual_length +=
TRB_LEN(le32_to_cpu(cur_trb->generic.field[2]));
}
if (trb_comp_code != COMP_STOP_INVAL)
td->urb->actual_length +=
TRB_LEN(le32_to_cpu(cur_trb->generic.field[2])) -
TRB_LEN(le32_to_cpu(event->transfer_len));
}
return finish_td(xhci, td, event_trb, event, ep, status, false);
}
static int handle_tx_event(struct xhci_hcd *xhci,
struct xhci_transfer_event *event)
{
struct xhci_virt_device *xdev;
struct xhci_virt_ep *ep;
struct xhci_ring *ep_ring;
unsigned int slot_id;
int ep_index;
struct xhci_td *td = NULL;
dma_addr_t event_dma;
struct xhci_segment *event_seg;
union xhci_trb *event_trb;
struct urb *urb = NULL;
int status = -EINPROGRESS;
struct urb_priv *urb_priv;
struct xhci_ep_ctx *ep_ctx;
struct list_head *tmp;
u32 trb_comp_code;
int ret = 0;
int td_num = 0;
slot_id = TRB_TO_SLOT_ID(le32_to_cpu(event->flags));
xdev = xhci->devs[slot_id];
if (!xdev) {
xhci_err(xhci, "ERROR Transfer event pointed to bad slot\n");
return -ENODEV;
}
ep_index = TRB_TO_EP_ID(le32_to_cpu(event->flags)) - 1;
ep = &xdev->eps[ep_index];
ep_ring = xhci_dma_to_transfer_ring(ep, le64_to_cpu(event->buffer));
ep_ctx = xhci_get_ep_ctx(xhci, xdev->out_ctx, ep_index);
if (!ep_ring ||
(le32_to_cpu(ep_ctx->ep_info) & EP_STATE_MASK) ==
EP_STATE_DISABLED) {
xhci_err(xhci, "ERROR Transfer event for disabled endpoint "
"or incorrect stream ring\n");
return -ENODEV;
}
if (ep->skip) {
list_for_each(tmp, &ep_ring->td_list)
td_num++;
}
event_dma = le64_to_cpu(event->buffer);
trb_comp_code = GET_COMP_CODE(le32_to_cpu(event->transfer_len));
switch (trb_comp_code) {
case COMP_SUCCESS:
case COMP_SHORT_TX:
break;
case COMP_STOP:
xhci_dbg(xhci, "Stopped on Transfer TRB\n");
break;
case COMP_STOP_INVAL:
xhci_dbg(xhci, "Stopped on No-op or Link TRB\n");
break;
case COMP_STALL:
xhci_warn(xhci, "WARN: Stalled endpoint\n");
ep->ep_state |= EP_HALTED;
status = -EPIPE;
break;
case COMP_TRB_ERR:
xhci_warn(xhci, "WARN: TRB error on endpoint\n");
status = -EILSEQ;
break;
case COMP_SPLIT_ERR:
case COMP_TX_ERR:
xhci_warn(xhci, "WARN: transfer error on endpoint\n");
status = -EPROTO;
break;
case COMP_BABBLE:
xhci_warn(xhci, "WARN: babble error on endpoint\n");
status = -EOVERFLOW;
break;
case COMP_DB_ERR:
xhci_warn(xhci, "WARN: HC couldn't access mem fast enough\n");
status = -ENOSR;
break;
case COMP_BW_OVER:
xhci_warn(xhci, "WARN: bandwidth overrun event on endpoint\n");
break;
case COMP_BUFF_OVER:
xhci_warn(xhci, "WARN: buffer overrun event on endpoint\n");
break;
case COMP_UNDERRUN:
xhci_dbg(xhci, "underrun event on endpoint\n");
if (!list_empty(&ep_ring->td_list))
xhci_dbg(xhci, "Underrun Event for slot %d ep %d "
"still with TDs queued?\n",
TRB_TO_SLOT_ID(le32_to_cpu(event->flags)),
ep_index);
goto cleanup;
case COMP_OVERRUN:
xhci_dbg(xhci, "overrun event on endpoint\n");
if (!list_empty(&ep_ring->td_list))
xhci_dbg(xhci, "Overrun Event for slot %d ep %d "
"still with TDs queued?\n",
TRB_TO_SLOT_ID(le32_to_cpu(event->flags)),
ep_index);
goto cleanup;
case COMP_DEV_ERR:
xhci_warn(xhci, "WARN: detect an incompatible device");
status = -EPROTO;
break;
case COMP_MISSED_INT:
ep->skip = true;
xhci_dbg(xhci, "Miss service interval error, set skip flag\n");
goto cleanup;
default:
if (xhci_is_vendor_info_code(xhci, trb_comp_code)) {
status = 0;
break;
}
xhci_warn(xhci, "ERROR Unknown event condition, HC probably "
"busted\n");
goto cleanup;
}
do {
if (list_empty(&ep_ring->td_list)) {
xhci_warn(xhci, "WARN Event TRB for slot %d ep %d "
"with no TDs queued?\n",
TRB_TO_SLOT_ID(le32_to_cpu(event->flags)),
ep_index);
xhci_dbg(xhci, "Event TRB with TRB type ID %u\n",
(le32_to_cpu(event->flags) &
TRB_TYPE_BITMASK)>>10);
xhci_print_trb_offsets(xhci, (union xhci_trb *) event);
if (ep->skip) {
ep->skip = false;
xhci_dbg(xhci, "td_list is empty while skip "
"flag set. Clear skip flag.\n");
}
ret = 0;
goto cleanup;
}
if (ep->skip && td_num == 0) {
ep->skip = false;
xhci_dbg(xhci, "All tds on the ep_ring skipped. "
"Clear skip flag.\n");
ret = 0;
goto cleanup;
}
td = list_entry(ep_ring->td_list.next, struct xhci_td, td_list);
if (ep->skip)
td_num--;
event_seg = trb_in_td(ep_ring->deq_seg, ep_ring->dequeue,
td->last_trb, event_dma);
if (!event_seg && trb_comp_code == COMP_STOP_INVAL) {
ret = 0;
goto cleanup;
}
if (!event_seg) {
if (!ep->skip ||
!usb_endpoint_xfer_isoc(&td->urb->ep->desc)) {
if ((xhci->quirks & XHCI_SPURIOUS_SUCCESS) &&
ep_ring->last_td_was_short) {
ep_ring->last_td_was_short = false;
ret = 0;
goto cleanup;
}
xhci_err(xhci,
"ERROR Transfer event TRB DMA ptr not "
"part of current TD\n");
return -ESHUTDOWN;
}
ret = skip_isoc_td(xhci, td, event, ep, &status);
goto cleanup;
}
if (trb_comp_code == COMP_SHORT_TX)
ep_ring->last_td_was_short = true;
else
ep_ring->last_td_was_short = false;
if (ep->skip) {
xhci_dbg(xhci, "Found td. Clear skip flag.\n");
ep->skip = false;
}
event_trb = &event_seg->trbs[(event_dma - event_seg->dma) /
sizeof(*event_trb)];
if (TRB_TYPE_NOOP_LE32(event_trb->generic.field[3])) {
xhci_dbg(xhci,
"event_trb is a no-op TRB. Skip it\n");
goto cleanup;
}
if (usb_endpoint_xfer_control(&td->urb->ep->desc))
ret = process_ctrl_td(xhci, td, event_trb, event, ep,
&status);
else if (usb_endpoint_xfer_isoc(&td->urb->ep->desc))
ret = process_isoc_td(xhci, td, event_trb, event, ep,
&status);
else
ret = process_bulk_intr_td(xhci, td, event_trb, event,
ep, &status);
cleanup:
if (trb_comp_code == COMP_MISSED_INT || !ep->skip) {
inc_deq(xhci, xhci->event_ring, true);
}
if (ret) {
urb = td->urb;
urb_priv = urb->hcpriv;
if (usb_endpoint_xfer_control(&urb->ep->desc) ||
(trb_comp_code != COMP_STALL &&
trb_comp_code != COMP_BABBLE))
xhci_urb_free_priv(xhci, urb_priv);
usb_hcd_unlink_urb_from_ep(bus_to_hcd(urb->dev->bus), urb);
if ((urb->actual_length != urb->transfer_buffer_length &&
(urb->transfer_flags &
URB_SHORT_NOT_OK)) ||
status != 0)
xhci_dbg(xhci, "Giveback URB %p, len = %d, "
"expected = %x, status = %d\n",
urb, urb->actual_length,
urb->transfer_buffer_length,
status);
spin_unlock(&xhci->lock);
if (usb_pipetype(urb->pipe) == PIPE_ISOCHRONOUS)
status = 0;
usb_hcd_giveback_urb(bus_to_hcd(urb->dev->bus), urb, status);
spin_lock(&xhci->lock);
}
} while (ep->skip && trb_comp_code != COMP_MISSED_INT);
return 0;
}
static int xhci_handle_event(struct xhci_hcd *xhci)
{
union xhci_trb *event;
int update_ptrs = 1;
int ret;
if (!xhci->event_ring || !xhci->event_ring->dequeue) {
xhci->error_bitmask |= 1 << 1;
return 0;
}
event = xhci->event_ring->dequeue;
if ((le32_to_cpu(event->event_cmd.flags) & TRB_CYCLE) !=
xhci->event_ring->cycle_state) {
xhci->error_bitmask |= 1 << 2;
return 0;
}
rmb();
switch ((le32_to_cpu(event->event_cmd.flags) & TRB_TYPE_BITMASK)) {
case TRB_TYPE(TRB_COMPLETION):
handle_cmd_completion(xhci, &event->event_cmd);
break;
case TRB_TYPE(TRB_PORT_STATUS):
handle_port_status(xhci, event);
update_ptrs = 0;
break;
case TRB_TYPE(TRB_TRANSFER):
ret = handle_tx_event(xhci, &event->trans_event);
if (ret < 0)
xhci->error_bitmask |= 1 << 9;
else
update_ptrs = 0;
break;
default:
if ((le32_to_cpu(event->event_cmd.flags) & TRB_TYPE_BITMASK) >=
TRB_TYPE(48))
handle_vendor_event(xhci, event);
else
xhci->error_bitmask |= 1 << 3;
}
if (xhci->xhc_state & XHCI_STATE_DYING) {
xhci_dbg(xhci, "xHCI host dying, returning from "
"event handler.\n");
return 0;
}
if (update_ptrs)
inc_deq(xhci, xhci->event_ring, true);
return 1;
}
irqreturn_t xhci_irq(struct usb_hcd *hcd)
{
struct xhci_hcd *xhci = hcd_to_xhci(hcd);
u32 status;
union xhci_trb *trb;
u64 temp_64;
union xhci_trb *event_ring_deq;
dma_addr_t deq;
spin_lock(&xhci->lock);
trb = xhci->event_ring->dequeue;
status = xhci_readl(xhci, &xhci->op_regs->status);
if (status == 0xffffffff)
goto hw_died;
if (!(status & STS_EINT)) {
spin_unlock(&xhci->lock);
return IRQ_NONE;
}
if (status & STS_FATAL) {
xhci_warn(xhci, "WARNING: Host System Error\n");
xhci_halt(xhci);
hw_died:
spin_unlock(&xhci->lock);
return -ESHUTDOWN;
}
status |= STS_EINT;
xhci_writel(xhci, status, &xhci->op_regs->status);
if (hcd->irq != -1) {
u32 irq_pending;
irq_pending = xhci_readl(xhci, &xhci->ir_set->irq_pending);
irq_pending |= 0x3;
xhci_writel(xhci, irq_pending, &xhci->ir_set->irq_pending);
}
if (xhci->xhc_state & XHCI_STATE_DYING) {
xhci_dbg(xhci, "xHCI dying, ignoring interrupt. "
"Shouldn't IRQs be disabled?\n");
temp_64 = xhci_read_64(xhci, &xhci->ir_set->erst_dequeue);
xhci_write_64(xhci, temp_64 | ERST_EHB,
&xhci->ir_set->erst_dequeue);
spin_unlock(&xhci->lock);
return IRQ_HANDLED;
}
event_ring_deq = xhci->event_ring->dequeue;
while (xhci_handle_event(xhci) > 0) {}
temp_64 = xhci_read_64(xhci, &xhci->ir_set->erst_dequeue);
if (event_ring_deq != xhci->event_ring->dequeue) {
deq = xhci_trb_virt_to_dma(xhci->event_ring->deq_seg,
xhci->event_ring->dequeue);
if (deq == 0)
xhci_warn(xhci, "WARN something wrong with SW event "
"ring dequeue ptr.\n");
temp_64 &= ERST_PTR_MASK;
temp_64 |= ((u64) deq & (u64) ~ERST_PTR_MASK);
}
temp_64 |= ERST_EHB;
xhci_write_64(xhci, temp_64, &xhci->ir_set->erst_dequeue);
spin_unlock(&xhci->lock);
return IRQ_HANDLED;
}
irqreturn_t xhci_msi_irq(int irq, struct usb_hcd *hcd)
{
irqreturn_t ret;
struct xhci_hcd *xhci;
xhci = hcd_to_xhci(hcd);
set_bit(HCD_FLAG_SAW_IRQ, &hcd->flags);
if (xhci->shared_hcd)
set_bit(HCD_FLAG_SAW_IRQ, &xhci->shared_hcd->flags);
ret = xhci_irq(hcd);
return ret;
}
static void queue_trb(struct xhci_hcd *xhci, struct xhci_ring *ring,
bool consumer, bool more_trbs_coming,
u32 field1, u32 field2, u32 field3, u32 field4)
{
struct xhci_generic_trb *trb;
trb = &ring->enqueue->generic;
trb->field[0] = cpu_to_le32(field1);
trb->field[1] = cpu_to_le32(field2);
trb->field[2] = cpu_to_le32(field3);
trb->field[3] = cpu_to_le32(field4);
inc_enq(xhci, ring, consumer, more_trbs_coming);
}
static int prepare_ring(struct xhci_hcd *xhci, struct xhci_ring *ep_ring,
u32 ep_state, unsigned int num_trbs, gfp_t mem_flags)
{
switch (ep_state) {
case EP_STATE_DISABLED:
xhci_warn(xhci, "WARN urb submitted to disabled ep\n");
return -ENOENT;
case EP_STATE_ERROR:
xhci_warn(xhci, "WARN waiting for error on ep to be cleared\n");
return -EINVAL;
case EP_STATE_HALTED:
xhci_dbg(xhci, "WARN halted endpoint, queueing URB anyway.\n");
case EP_STATE_STOPPED:
case EP_STATE_RUNNING:
break;
default:
xhci_err(xhci, "ERROR unknown endpoint state for ep\n");
return -EINVAL;
}
if (!room_on_ring(xhci, ep_ring, num_trbs)) {
xhci_err(xhci, "ERROR no room on ep ring\n");
return -ENOMEM;
}
if (enqueue_is_link_trb(ep_ring)) {
struct xhci_ring *ring = ep_ring;
union xhci_trb *next;
next = ring->enqueue;
while (last_trb(xhci, ring, ring->enq_seg, next)) {
if (!xhci_link_trb_quirk(xhci))
next->link.control &= cpu_to_le32(~TRB_CHAIN);
else
next->link.control |= cpu_to_le32(TRB_CHAIN);
wmb();
next->link.control ^= cpu_to_le32(TRB_CYCLE);
if (last_trb_on_last_seg(xhci, ring, ring->enq_seg, next)) {
ring->cycle_state = (ring->cycle_state ? 0 : 1);
if (!in_interrupt()) {
xhci_dbg(xhci, "queue_trb: Toggle cycle "
"state for ring %p = %i\n",
ring, (unsigned int)ring->cycle_state);
}
}
ring->enq_seg = ring->enq_seg->next;
ring->enqueue = ring->enq_seg->trbs;
next = ring->enqueue;
}
}
return 0;
}
static int prepare_transfer(struct xhci_hcd *xhci,
struct xhci_virt_device *xdev,
unsigned int ep_index,
unsigned int stream_id,
unsigned int num_trbs,
struct urb *urb,
unsigned int td_index,
gfp_t mem_flags)
{
int ret;
struct urb_priv *urb_priv;
struct xhci_td *td;
struct xhci_ring *ep_ring;
struct xhci_ep_ctx *ep_ctx = xhci_get_ep_ctx(xhci, xdev->out_ctx, ep_index);
ep_ring = xhci_stream_id_to_ring(xdev, ep_index, stream_id);
if (!ep_ring) {
xhci_dbg(xhci, "Can't prepare ring for bad stream ID %u\n",
stream_id);
return -EINVAL;
}
ret = prepare_ring(xhci, ep_ring,
le32_to_cpu(ep_ctx->ep_info) & EP_STATE_MASK,
num_trbs, mem_flags);
if (ret)
return ret;
urb_priv = urb->hcpriv;
td = urb_priv->td[td_index];
INIT_LIST_HEAD(&td->td_list);
INIT_LIST_HEAD(&td->cancelled_td_list);
if (td_index == 0) {
ret = usb_hcd_link_urb_to_ep(bus_to_hcd(urb->dev->bus), urb);
if (unlikely(ret))
return ret;
}
td->urb = urb;
list_add_tail(&td->td_list, &ep_ring->td_list);
td->start_seg = ep_ring->enq_seg;
td->first_trb = ep_ring->enqueue;
urb_priv->td[td_index] = td;
return 0;
}
static unsigned int count_sg_trbs_needed(struct xhci_hcd *xhci, struct urb *urb)
{
int num_sgs, num_trbs, running_total, temp, i;
struct scatterlist *sg;
sg = NULL;
num_sgs = urb->num_sgs;
temp = urb->transfer_buffer_length;
xhci_dbg(xhci, "count sg list trbs: \n");
num_trbs = 0;
for_each_sg(urb->sg, sg, num_sgs, i) {
unsigned int previous_total_trbs = num_trbs;
unsigned int len = sg_dma_len(sg);
running_total = TRB_MAX_BUFF_SIZE -
(sg_dma_address(sg) & (TRB_MAX_BUFF_SIZE - 1));
running_total &= TRB_MAX_BUFF_SIZE - 1;
if (running_total != 0)
num_trbs++;
while (running_total < sg_dma_len(sg) && running_total < temp) {
num_trbs++;
running_total += TRB_MAX_BUFF_SIZE;
}
xhci_dbg(xhci, " sg #%d: dma = %#llx, len = %#x (%d), num_trbs = %d\n",
i, (unsigned long long)sg_dma_address(sg),
len, len, num_trbs - previous_total_trbs);
len = min_t(int, len, temp);
temp -= len;
if (temp == 0)
break;
}
xhci_dbg(xhci, "\n");
if (!in_interrupt())
xhci_dbg(xhci, "ep %#x - urb len = %d, sglist used, "
"num_trbs = %d\n",
urb->ep->desc.bEndpointAddress,
urb->transfer_buffer_length,
num_trbs);
return num_trbs;
}
static void check_trb_math(struct urb *urb, int num_trbs, int running_total)
{
if (num_trbs != 0)
dev_err(&urb->dev->dev, "%s - ep %#x - Miscalculated number of "
"TRBs, %d left\n", __func__,
urb->ep->desc.bEndpointAddress, num_trbs);
if (running_total != urb->transfer_buffer_length)
dev_err(&urb->dev->dev, "%s - ep %#x - Miscalculated tx length, "
"queued %#x (%d), asked for %#x (%d)\n",
__func__,
urb->ep->desc.bEndpointAddress,
running_total, running_total,
urb->transfer_buffer_length,
urb->transfer_buffer_length);
}
static void giveback_first_trb(struct xhci_hcd *xhci, int slot_id,
unsigned int ep_index, unsigned int stream_id, int start_cycle,
struct xhci_generic_trb *start_trb)
{
wmb();
if (start_cycle)
start_trb->field[3] |= cpu_to_le32(start_cycle);
else
start_trb->field[3] &= cpu_to_le32(~TRB_CYCLE);
xhci_ring_ep_doorbell(xhci, slot_id, ep_index, stream_id);
}
int xhci_queue_intr_tx(struct xhci_hcd *xhci, gfp_t mem_flags,
struct urb *urb, int slot_id, unsigned int ep_index)
{
struct xhci_ep_ctx *ep_ctx = xhci_get_ep_ctx(xhci,
xhci->devs[slot_id]->out_ctx, ep_index);
int xhci_interval;
int ep_interval;
xhci_interval = EP_INTERVAL_TO_UFRAMES(le32_to_cpu(ep_ctx->ep_info));
ep_interval = urb->interval;
if (urb->dev->speed == USB_SPEED_LOW ||
urb->dev->speed == USB_SPEED_FULL)
ep_interval *= 8;
if (xhci_interval != ep_interval) {
if (printk_ratelimit())
dev_dbg(&urb->dev->dev, "Driver uses different interval"
" (%d microframe%s) than xHCI "
"(%d microframe%s)\n",
ep_interval,
ep_interval == 1 ? "" : "s",
xhci_interval,
xhci_interval == 1 ? "" : "s");
urb->interval = xhci_interval;
if (urb->dev->speed == USB_SPEED_LOW ||
urb->dev->speed == USB_SPEED_FULL)
urb->interval /= 8;
}
return xhci_queue_bulk_tx(xhci, GFP_ATOMIC, urb, slot_id, ep_index);
}
static u32 xhci_td_remainder(unsigned int remainder)
{
u32 max = (1 << (21 - 17 + 1)) - 1;
if ((remainder >> 10) >= max)
return max << 17;
else
return (remainder >> 10) << 17;
}
static u32 xhci_v1_0_td_remainder(int running_total, int trb_buff_len,
unsigned int total_packet_count, struct urb *urb)
{
int packets_transferred;
if (running_total == 0 && trb_buff_len == 0)
return 0;
packets_transferred = (running_total + trb_buff_len) /
le16_to_cpu(urb->ep->desc.wMaxPacketSize);
return xhci_td_remainder(total_packet_count - packets_transferred);
}
static int queue_bulk_sg_tx(struct xhci_hcd *xhci, gfp_t mem_flags,
struct urb *urb, int slot_id, unsigned int ep_index)
{
struct xhci_ring *ep_ring;
unsigned int num_trbs;
struct urb_priv *urb_priv;
struct xhci_td *td;
struct scatterlist *sg;
int num_sgs;
int trb_buff_len, this_sg_len, running_total;
unsigned int total_packet_count;
bool first_trb;
u64 addr;
bool more_trbs_coming;
struct xhci_generic_trb *start_trb;
int start_cycle;
ep_ring = xhci_urb_to_transfer_ring(xhci, urb);
if (!ep_ring)
return -EINVAL;
num_trbs = count_sg_trbs_needed(xhci, urb);
num_sgs = urb->num_sgs;
total_packet_count = roundup(urb->transfer_buffer_length,
le16_to_cpu(urb->ep->desc.wMaxPacketSize));
trb_buff_len = prepare_transfer(xhci, xhci->devs[slot_id],
ep_index, urb->stream_id,
num_trbs, urb, 0, mem_flags);
if (trb_buff_len < 0)
return trb_buff_len;
urb_priv = urb->hcpriv;
td = urb_priv->td[0];
start_trb = &ep_ring->enqueue->generic;
start_cycle = ep_ring->cycle_state;
running_total = 0;
sg = urb->sg;
addr = (u64) sg_dma_address(sg);
this_sg_len = sg_dma_len(sg);
trb_buff_len = TRB_MAX_BUFF_SIZE - (addr & (TRB_MAX_BUFF_SIZE - 1));
trb_buff_len = min_t(int, trb_buff_len, this_sg_len);
if (trb_buff_len > urb->transfer_buffer_length)
trb_buff_len = urb->transfer_buffer_length;
xhci_dbg(xhci, "First length to xfer from 1st sglist entry = %u\n",
trb_buff_len);
first_trb = true;
do {
u32 field = 0;
u32 length_field = 0;
u32 remainder = 0;
if (first_trb) {
first_trb = false;
if (start_cycle == 0)
field |= 0x1;
} else
field |= ep_ring->cycle_state;
if (num_trbs > 1) {
field |= TRB_CHAIN;
} else {
td->last_trb = ep_ring->enqueue;
field |= TRB_IOC;
}
if (usb_urb_dir_in(urb))
field |= TRB_ISP;
xhci_dbg(xhci, " sg entry: dma = %#x, len = %#x (%d), "
"64KB boundary at %#x, end dma = %#x\n",
(unsigned int) addr, trb_buff_len, trb_buff_len,
(unsigned int) (addr + TRB_MAX_BUFF_SIZE) & ~(TRB_MAX_BUFF_SIZE - 1),
(unsigned int) addr + trb_buff_len);
if (TRB_MAX_BUFF_SIZE -
(addr & (TRB_MAX_BUFF_SIZE - 1)) < trb_buff_len) {
xhci_warn(xhci, "WARN: sg dma xfer crosses 64KB boundaries!\n");
xhci_dbg(xhci, "Next boundary at %#x, end dma = %#x\n",
(unsigned int) (addr + TRB_MAX_BUFF_SIZE) & ~(TRB_MAX_BUFF_SIZE - 1),
(unsigned int) addr + trb_buff_len);
}
if (xhci->hci_version < 0x100) {
remainder = xhci_td_remainder(
urb->transfer_buffer_length -
running_total);
} else {
remainder = xhci_v1_0_td_remainder(running_total,
trb_buff_len, total_packet_count, urb);
}
length_field = TRB_LEN(trb_buff_len) |
remainder |
TRB_INTR_TARGET(0);
if (num_trbs > 1)
more_trbs_coming = true;
else
more_trbs_coming = false;
queue_trb(xhci, ep_ring, false, more_trbs_coming,
lower_32_bits(addr),
upper_32_bits(addr),
length_field,
field | TRB_TYPE(TRB_NORMAL));
--num_trbs;
running_total += trb_buff_len;
this_sg_len -= trb_buff_len;
if (this_sg_len == 0) {
--num_sgs;
if (num_sgs == 0)
break;
sg = sg_next(sg);
addr = (u64) sg_dma_address(sg);
this_sg_len = sg_dma_len(sg);
} else {
addr += trb_buff_len;
}
trb_buff_len = TRB_MAX_BUFF_SIZE -
(addr & (TRB_MAX_BUFF_SIZE - 1));
trb_buff_len = min_t(int, trb_buff_len, this_sg_len);
if (running_total + trb_buff_len > urb->transfer_buffer_length)
trb_buff_len =
urb->transfer_buffer_length - running_total;
} while (running_total < urb->transfer_buffer_length);
check_trb_math(urb, num_trbs, running_total);
giveback_first_trb(xhci, slot_id, ep_index, urb->stream_id,
start_cycle, start_trb);
return 0;
}
int xhci_queue_bulk_tx(struct xhci_hcd *xhci, gfp_t mem_flags,
struct urb *urb, int slot_id, unsigned int ep_index)
{
struct xhci_ring *ep_ring;
struct urb_priv *urb_priv;
struct xhci_td *td;
int num_trbs;
struct xhci_generic_trb *start_trb;
bool first_trb;
bool more_trbs_coming;
int start_cycle;
u32 field, length_field;
int running_total, trb_buff_len, ret;
unsigned int total_packet_count;
u64 addr;
if (urb->num_sgs)
return queue_bulk_sg_tx(xhci, mem_flags, urb, slot_id, ep_index);
ep_ring = xhci_urb_to_transfer_ring(xhci, urb);
if (!ep_ring)
return -EINVAL;
num_trbs = 0;
running_total = TRB_MAX_BUFF_SIZE -
(urb->transfer_dma & (TRB_MAX_BUFF_SIZE - 1));
running_total &= TRB_MAX_BUFF_SIZE - 1;
if (running_total != 0 || urb->transfer_buffer_length == 0)
num_trbs++;
while (running_total < urb->transfer_buffer_length) {
num_trbs++;
running_total += TRB_MAX_BUFF_SIZE;
}
if (!in_interrupt())
xhci_dbg(xhci, "ep %#x - urb len = %#x (%d), "
"addr = %#llx, num_trbs = %d\n",
urb->ep->desc.bEndpointAddress,
urb->transfer_buffer_length,
urb->transfer_buffer_length,
(unsigned long long)urb->transfer_dma,
num_trbs);
ret = prepare_transfer(xhci, xhci->devs[slot_id],
ep_index, urb->stream_id,
num_trbs, urb, 0, mem_flags);
if (ret < 0)
return ret;
urb_priv = urb->hcpriv;
td = urb_priv->td[0];
start_trb = &ep_ring->enqueue->generic;
start_cycle = ep_ring->cycle_state;
running_total = 0;
total_packet_count = roundup(urb->transfer_buffer_length,
le16_to_cpu(urb->ep->desc.wMaxPacketSize));
addr = (u64) urb->transfer_dma;
trb_buff_len = TRB_MAX_BUFF_SIZE -
(urb->transfer_dma & (TRB_MAX_BUFF_SIZE - 1));
if (trb_buff_len > urb->transfer_buffer_length)
trb_buff_len = urb->transfer_buffer_length;
first_trb = true;
do {
u32 remainder = 0;
field = 0;
if (first_trb) {
first_trb = false;
if (start_cycle == 0)
field |= 0x1;
} else
field |= ep_ring->cycle_state;
if (num_trbs > 1) {
field |= TRB_CHAIN;
} else {
td->last_trb = ep_ring->enqueue;
field |= TRB_IOC;
}
if (usb_urb_dir_in(urb))
field |= TRB_ISP;
if (xhci->hci_version < 0x100) {
remainder = xhci_td_remainder(
urb->transfer_buffer_length -
running_total);
} else {
remainder = xhci_v1_0_td_remainder(running_total,
trb_buff_len, total_packet_count, urb);
}
length_field = TRB_LEN(trb_buff_len) |
remainder |
TRB_INTR_TARGET(0);
if (num_trbs > 1)
more_trbs_coming = true;
else
more_trbs_coming = false;
queue_trb(xhci, ep_ring, false, more_trbs_coming,
lower_32_bits(addr),
upper_32_bits(addr),
length_field,
field | TRB_TYPE(TRB_NORMAL));
--num_trbs;
running_total += trb_buff_len;
addr += trb_buff_len;
trb_buff_len = urb->transfer_buffer_length - running_total;
if (trb_buff_len > TRB_MAX_BUFF_SIZE)
trb_buff_len = TRB_MAX_BUFF_SIZE;
} while (running_total < urb->transfer_buffer_length);
check_trb_math(urb, num_trbs, running_total);
giveback_first_trb(xhci, slot_id, ep_index, urb->stream_id,
start_cycle, start_trb);
return 0;
}
int xhci_queue_ctrl_tx(struct xhci_hcd *xhci, gfp_t mem_flags,
struct urb *urb, int slot_id, unsigned int ep_index)
{
struct xhci_ring *ep_ring;
int num_trbs;
int ret;
struct usb_ctrlrequest *setup;
struct xhci_generic_trb *start_trb;
int start_cycle;
u32 field, length_field;
struct urb_priv *urb_priv;
struct xhci_td *td;
ep_ring = xhci_urb_to_transfer_ring(xhci, urb);
if (!ep_ring)
return -EINVAL;
if (!urb->setup_packet)
return -EINVAL;
if (!in_interrupt())
xhci_dbg(xhci, "Queueing ctrl tx for slot id %d, ep %d\n",
slot_id, ep_index);
num_trbs = 2;
if (urb->transfer_buffer_length > 0)
num_trbs++;
ret = prepare_transfer(xhci, xhci->devs[slot_id],
ep_index, urb->stream_id,
num_trbs, urb, 0, mem_flags);
if (ret < 0)
return ret;
urb_priv = urb->hcpriv;
td = urb_priv->td[0];
start_trb = &ep_ring->enqueue->generic;
start_cycle = ep_ring->cycle_state;
setup = (struct usb_ctrlrequest *) urb->setup_packet;
field = 0;
field |= TRB_IDT | TRB_TYPE(TRB_SETUP);
if (start_cycle == 0)
field |= 0x1;
if (xhci->hci_version == 0x100) {
if (urb->transfer_buffer_length > 0) {
if (setup->bRequestType & USB_DIR_IN)
field |= TRB_TX_TYPE(TRB_DATA_IN);
else
field |= TRB_TX_TYPE(TRB_DATA_OUT);
}
}
queue_trb(xhci, ep_ring, false, true,
setup->bRequestType | setup->bRequest << 8 | le16_to_cpu(setup->wValue) << 16,
le16_to_cpu(setup->wIndex) | le16_to_cpu(setup->wLength) << 16,
TRB_LEN(8) | TRB_INTR_TARGET(0),
field);
if (usb_urb_dir_in(urb))
field = TRB_ISP | TRB_TYPE(TRB_DATA);
else
field = TRB_TYPE(TRB_DATA);
length_field = TRB_LEN(urb->transfer_buffer_length) |
xhci_td_remainder(urb->transfer_buffer_length) |
TRB_INTR_TARGET(0);
if (urb->transfer_buffer_length > 0) {
if (setup->bRequestType & USB_DIR_IN)
field |= TRB_DIR_IN;
queue_trb(xhci, ep_ring, false, true,
lower_32_bits(urb->transfer_dma),
upper_32_bits(urb->transfer_dma),
length_field,
field | ep_ring->cycle_state);
}
td->last_trb = ep_ring->enqueue;
if (urb->transfer_buffer_length > 0 && setup->bRequestType & USB_DIR_IN)
field = 0;
else
field = TRB_DIR_IN;
queue_trb(xhci, ep_ring, false, false,
0,
0,
TRB_INTR_TARGET(0),
field | TRB_IOC | TRB_TYPE(TRB_STATUS) | ep_ring->cycle_state);
giveback_first_trb(xhci, slot_id, ep_index, 0,
start_cycle, start_trb);
return 0;
}
static int count_isoc_trbs_needed(struct xhci_hcd *xhci,
struct urb *urb, int i)
{
int num_trbs = 0;
u64 addr, td_len;
addr = (u64) (urb->transfer_dma + urb->iso_frame_desc[i].offset);
td_len = urb->iso_frame_desc[i].length;
num_trbs = DIV_ROUND_UP(td_len + (addr & (TRB_MAX_BUFF_SIZE - 1)),
TRB_MAX_BUFF_SIZE);
if (num_trbs == 0)
num_trbs++;
return num_trbs;
}
static unsigned int xhci_get_burst_count(struct xhci_hcd *xhci,
struct usb_device *udev,
struct urb *urb, unsigned int total_packet_count)
{
unsigned int max_burst;
if (xhci->hci_version < 0x100 || udev->speed != USB_SPEED_SUPER)
return 0;
max_burst = urb->ep->ss_ep_comp.bMaxBurst;
return roundup(total_packet_count, max_burst + 1) - 1;
}
static unsigned int xhci_get_last_burst_packet_count(struct xhci_hcd *xhci,
struct usb_device *udev,
struct urb *urb, unsigned int total_packet_count)
{
unsigned int max_burst;
unsigned int residue;
if (xhci->hci_version < 0x100)
return 0;
switch (udev->speed) {
case USB_SPEED_SUPER:
max_burst = urb->ep->ss_ep_comp.bMaxBurst;
residue = total_packet_count % (max_burst + 1);
if (residue == 0)
return max_burst;
return residue - 1;
default:
if (total_packet_count == 0)
return 0;
return total_packet_count - 1;
}
}
static int xhci_queue_isoc_tx(struct xhci_hcd *xhci, gfp_t mem_flags,
struct urb *urb, int slot_id, unsigned int ep_index)
{
struct xhci_ring *ep_ring;
struct urb_priv *urb_priv;
struct xhci_td *td;
int num_tds, trbs_per_td;
struct xhci_generic_trb *start_trb;
bool first_trb;
int start_cycle;
u32 field, length_field;
int running_total, trb_buff_len, td_len, td_remain_len, ret;
u64 start_addr, addr;
int i, j;
bool more_trbs_coming;
ep_ring = xhci->devs[slot_id]->eps[ep_index].ring;
num_tds = urb->number_of_packets;
if (num_tds < 1) {
xhci_dbg(xhci, "Isoc URB with zero packets?\n");
return -EINVAL;
}
if (!in_interrupt())
xhci_dbg(xhci, "ep %#x - urb len = %#x (%d),"
" addr = %#llx, num_tds = %d\n",
urb->ep->desc.bEndpointAddress,
urb->transfer_buffer_length,
urb->transfer_buffer_length,
(unsigned long long)urb->transfer_dma,
num_tds);
start_addr = (u64) urb->transfer_dma;
start_trb = &ep_ring->enqueue->generic;
start_cycle = ep_ring->cycle_state;
urb_priv = urb->hcpriv;
for (i = 0; i < num_tds; i++) {
unsigned int total_packet_count;
unsigned int burst_count;
unsigned int residue;
first_trb = true;
running_total = 0;
addr = start_addr + urb->iso_frame_desc[i].offset;
td_len = urb->iso_frame_desc[i].length;
td_remain_len = td_len;
total_packet_count = roundup(td_len,
le16_to_cpu(urb->ep->desc.wMaxPacketSize));
if (total_packet_count == 0)
total_packet_count++;
burst_count = xhci_get_burst_count(xhci, urb->dev, urb,
total_packet_count);
residue = xhci_get_last_burst_packet_count(xhci,
urb->dev, urb, total_packet_count);
trbs_per_td = count_isoc_trbs_needed(xhci, urb, i);
ret = prepare_transfer(xhci, xhci->devs[slot_id], ep_index,
urb->stream_id, trbs_per_td, urb, i, mem_flags);
if (ret < 0) {
if (i == 0)
return ret;
goto cleanup;
}
td = urb_priv->td[i];
for (j = 0; j < trbs_per_td; j++) {
u32 remainder = 0;
field = TRB_TBC(burst_count) | TRB_TLBPC(residue);
if (first_trb) {
field |= TRB_TYPE(TRB_ISOC);
field |= TRB_SIA;
if (i == 0) {
if (start_cycle == 0)
field |= 0x1;
} else
field |= ep_ring->cycle_state;
first_trb = false;
} else {
field |= TRB_TYPE(TRB_NORMAL);
field |= ep_ring->cycle_state;
}
if (usb_urb_dir_in(urb))
field |= TRB_ISP;
if (j < trbs_per_td - 1) {
field |= TRB_CHAIN;
more_trbs_coming = true;
} else {
td->last_trb = ep_ring->enqueue;
field |= TRB_IOC;
if (xhci->hci_version == 0x100) {
if (i < num_tds - 1)
field |= TRB_BEI;
}
more_trbs_coming = false;
}
trb_buff_len = TRB_MAX_BUFF_SIZE -
(addr & ((1 << TRB_MAX_BUFF_SHIFT) - 1));
if (trb_buff_len > td_remain_len)
trb_buff_len = td_remain_len;
if (xhci->hci_version < 0x100) {
remainder = xhci_td_remainder(
td_len - running_total);
} else {
remainder = xhci_v1_0_td_remainder(
running_total, trb_buff_len,
total_packet_count, urb);
}
length_field = TRB_LEN(trb_buff_len) |
remainder |
TRB_INTR_TARGET(0);
queue_trb(xhci, ep_ring, false, more_trbs_coming,
lower_32_bits(addr),
upper_32_bits(addr),
length_field,
field);
running_total += trb_buff_len;
addr += trb_buff_len;
td_remain_len -= trb_buff_len;
}
if (running_total != td_len) {
xhci_err(xhci, "ISOC TD length unmatch\n");
return -EINVAL;
}
}
if (xhci_to_hcd(xhci)->self.bandwidth_isoc_reqs == 0) {
if (xhci->quirks & XHCI_AMD_PLL_FIX)
usb_amd_quirk_pll_disable();
}
xhci_to_hcd(xhci)->self.bandwidth_isoc_reqs++;
giveback_first_trb(xhci, slot_id, ep_index, urb->stream_id,
start_cycle, start_trb);
return 0;
cleanup:
for (i--; i >= 0; i--)
list_del_init(&urb_priv->td[i]->td_list);
urb_priv->td[0]->last_trb = ep_ring->enqueue;
td_to_noop(xhci, ep_ring, urb_priv->td[0], true);
ep_ring->enqueue = urb_priv->td[0]->first_trb;
ep_ring->enq_seg = urb_priv->td[0]->start_seg;
ep_ring->cycle_state = start_cycle;
usb_hcd_unlink_urb_from_ep(bus_to_hcd(urb->dev->bus), urb);
return ret;
}
int xhci_queue_isoc_tx_prepare(struct xhci_hcd *xhci, gfp_t mem_flags,
struct urb *urb, int slot_id, unsigned int ep_index)
{
struct xhci_virt_device *xdev;
struct xhci_ring *ep_ring;
struct xhci_ep_ctx *ep_ctx;
int start_frame;
int xhci_interval;
int ep_interval;
int num_tds, num_trbs, i;
int ret;
xdev = xhci->devs[slot_id];
ep_ring = xdev->eps[ep_index].ring;
ep_ctx = xhci_get_ep_ctx(xhci, xdev->out_ctx, ep_index);
num_trbs = 0;
num_tds = urb->number_of_packets;
for (i = 0; i < num_tds; i++)
num_trbs += count_isoc_trbs_needed(xhci, urb, i);
ret = prepare_ring(xhci, ep_ring, le32_to_cpu(ep_ctx->ep_info) & EP_STATE_MASK,
num_trbs, mem_flags);
if (ret)
return ret;
start_frame = xhci_readl(xhci, &xhci->run_regs->microframe_index);
start_frame &= 0x3fff;
urb->start_frame = start_frame;
if (urb->dev->speed == USB_SPEED_LOW ||
urb->dev->speed == USB_SPEED_FULL)
urb->start_frame >>= 3;
xhci_interval = EP_INTERVAL_TO_UFRAMES(le32_to_cpu(ep_ctx->ep_info));
ep_interval = urb->interval;
if (urb->dev->speed == USB_SPEED_LOW ||
urb->dev->speed == USB_SPEED_FULL)
ep_interval *= 8;
if (xhci_interval != ep_interval) {
if (printk_ratelimit())
dev_dbg(&urb->dev->dev, "Driver uses different interval"
" (%d microframe%s) than xHCI "
"(%d microframe%s)\n",
ep_interval,
ep_interval == 1 ? "" : "s",
xhci_interval,
xhci_interval == 1 ? "" : "s");
urb->interval = xhci_interval;
if (urb->dev->speed == USB_SPEED_LOW ||
urb->dev->speed == USB_SPEED_FULL)
urb->interval /= 8;
}
return xhci_queue_isoc_tx(xhci, GFP_ATOMIC, urb, slot_id, ep_index);
}
static int queue_command(struct xhci_hcd *xhci, u32 field1, u32 field2,
u32 field3, u32 field4, bool command_must_succeed)
{
int reserved_trbs = xhci->cmd_ring_reserved_trbs;
int ret;
if (!command_must_succeed)
reserved_trbs++;
ret = prepare_ring(xhci, xhci->cmd_ring, EP_STATE_RUNNING,
reserved_trbs, GFP_ATOMIC);
if (ret < 0) {
xhci_err(xhci, "ERR: No room for command on command ring\n");
if (command_must_succeed)
xhci_err(xhci, "ERR: Reserved TRB counting for "
"unfailable commands failed.\n");
return ret;
}
queue_trb(xhci, xhci->cmd_ring, false, false, field1, field2, field3,
field4 | xhci->cmd_ring->cycle_state);
return 0;
}
int xhci_queue_slot_control(struct xhci_hcd *xhci, u32 trb_type, u32 slot_id)
{
return queue_command(xhci, 0, 0, 0,
TRB_TYPE(trb_type) | SLOT_ID_FOR_TRB(slot_id), false);
}
int xhci_queue_address_device(struct xhci_hcd *xhci, dma_addr_t in_ctx_ptr,
u32 slot_id)
{
return queue_command(xhci, lower_32_bits(in_ctx_ptr),
upper_32_bits(in_ctx_ptr), 0,
TRB_TYPE(TRB_ADDR_DEV) | SLOT_ID_FOR_TRB(slot_id),
false);
}
int xhci_queue_vendor_command(struct xhci_hcd *xhci,
u32 field1, u32 field2, u32 field3, u32 field4)
{
return queue_command(xhci, field1, field2, field3, field4, false);
}
int xhci_queue_reset_device(struct xhci_hcd *xhci, u32 slot_id)
{
return queue_command(xhci, 0, 0, 0,
TRB_TYPE(TRB_RESET_DEV) | SLOT_ID_FOR_TRB(slot_id),
false);
}
int xhci_queue_configure_endpoint(struct xhci_hcd *xhci, dma_addr_t in_ctx_ptr,
u32 slot_id, bool command_must_succeed)
{
return queue_command(xhci, lower_32_bits(in_ctx_ptr),
upper_32_bits(in_ctx_ptr), 0,
TRB_TYPE(TRB_CONFIG_EP) | SLOT_ID_FOR_TRB(slot_id),
command_must_succeed);
}
int xhci_queue_evaluate_context(struct xhci_hcd *xhci, dma_addr_t in_ctx_ptr,
u32 slot_id)
{
return queue_command(xhci, lower_32_bits(in_ctx_ptr),
upper_32_bits(in_ctx_ptr), 0,
TRB_TYPE(TRB_EVAL_CONTEXT) | SLOT_ID_FOR_TRB(slot_id),
false);
}
int xhci_queue_stop_endpoint(struct xhci_hcd *xhci, int slot_id,
unsigned int ep_index, int suspend)
{
u32 trb_slot_id = SLOT_ID_FOR_TRB(slot_id);
u32 trb_ep_index = EP_ID_FOR_TRB(ep_index);
u32 type = TRB_TYPE(TRB_STOP_RING);
u32 trb_suspend = SUSPEND_PORT_FOR_TRB(suspend);
return queue_command(xhci, 0, 0, 0,
trb_slot_id | trb_ep_index | type | trb_suspend, false);
}
static int queue_set_tr_deq(struct xhci_hcd *xhci, int slot_id,
unsigned int ep_index, unsigned int stream_id,
struct xhci_segment *deq_seg,
union xhci_trb *deq_ptr, u32 cycle_state)
{
dma_addr_t addr;
u32 trb_slot_id = SLOT_ID_FOR_TRB(slot_id);
u32 trb_ep_index = EP_ID_FOR_TRB(ep_index);
u32 trb_stream_id = STREAM_ID_FOR_TRB(stream_id);
u32 type = TRB_TYPE(TRB_SET_DEQ);
struct xhci_virt_ep *ep;
addr = xhci_trb_virt_to_dma(deq_seg, deq_ptr);
if (addr == 0) {
xhci_warn(xhci, "WARN Cannot submit Set TR Deq Ptr\n");
xhci_warn(xhci, "WARN deq seg = %p, deq pt = %p\n",
deq_seg, deq_ptr);
return 0;
}
ep = &xhci->devs[slot_id]->eps[ep_index];
if ((ep->ep_state & SET_DEQ_PENDING)) {
xhci_warn(xhci, "WARN Cannot submit Set TR Deq Ptr\n");
xhci_warn(xhci, "A Set TR Deq Ptr command is pending.\n");
return 0;
}
ep->queued_deq_seg = deq_seg;
ep->queued_deq_ptr = deq_ptr;
return queue_command(xhci, lower_32_bits(addr) | cycle_state,
upper_32_bits(addr), trb_stream_id,
trb_slot_id | trb_ep_index | type, false);
}
int xhci_queue_reset_ep(struct xhci_hcd *xhci, int slot_id,
unsigned int ep_index)
{
u32 trb_slot_id = SLOT_ID_FOR_TRB(slot_id);
u32 trb_ep_index = EP_ID_FOR_TRB(ep_index);
u32 type = TRB_TYPE(TRB_RESET_EP);
return queue_command(xhci, 0, 0, 0, trb_slot_id | trb_ep_index | type,
false);
}
