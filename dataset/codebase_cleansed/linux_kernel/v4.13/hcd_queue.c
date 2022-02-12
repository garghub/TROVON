static int dwc2_periodic_channel_available(struct dwc2_hsotg *hsotg)
{
int status;
int num_channels;
num_channels = hsotg->params.host_channels;
if ((hsotg->periodic_channels + hsotg->non_periodic_channels <
num_channels) && (hsotg->periodic_channels < num_channels - 1)) {
status = 0;
} else {
dev_dbg(hsotg->dev,
"%s: Total channels: %d, Periodic: %d, Non-periodic: %d\n",
__func__, num_channels,
hsotg->periodic_channels, hsotg->non_periodic_channels);
status = -ENOSPC;
}
return status;
}
static int dwc2_check_periodic_bandwidth(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh)
{
int status;
s16 max_claimed_usecs;
status = 0;
if (qh->dev_speed == USB_SPEED_HIGH || qh->do_split) {
max_claimed_usecs = 100 - qh->host_us;
} else {
max_claimed_usecs = 900 - qh->host_us;
}
if (hsotg->periodic_usecs > max_claimed_usecs) {
dev_err(hsotg->dev,
"%s: already claimed usecs %d, required usecs %d\n",
__func__, hsotg->periodic_usecs, qh->host_us);
status = -ENOSPC;
}
return status;
}
static int pmap_schedule(unsigned long *map, int bits_per_period,
int periods_in_map, int num_bits,
int interval, int start, bool only_one_period)
{
int interval_bits;
int to_reserve;
int first_end;
int i;
if (num_bits > bits_per_period)
return -ENOSPC;
interval = gcd(interval, periods_in_map);
interval_bits = bits_per_period * interval;
to_reserve = periods_in_map / interval;
if (start >= interval_bits)
return -ENOSPC;
if (only_one_period)
first_end = (start / bits_per_period + 1) * bits_per_period;
else
first_end = interval_bits;
while (start + num_bits <= first_end) {
int end;
end = (start / bits_per_period + 1) * bits_per_period;
start = bitmap_find_next_zero_area(map, end, start, num_bits,
0);
if (start >= end) {
start = end;
continue;
}
for (i = 1; i < to_reserve; i++) {
int ith_start = start + interval_bits * i;
int ith_end = end + interval_bits * i;
int ret;
ret = bitmap_find_next_zero_area(
map, ith_start + num_bits, ith_start, num_bits,
0);
if (ret == ith_start)
continue;
ith_start = bitmap_find_next_zero_area(
map, ith_end, ith_start, num_bits, 0);
if (ith_start >= ith_end)
start = end;
else
start = ith_start - interval_bits * i;
break;
}
if (i == to_reserve)
break;
}
if (start + num_bits > first_end)
return -ENOSPC;
for (i = 0; i < to_reserve; i++) {
int ith_start = start + interval_bits * i;
bitmap_set(map, ith_start, num_bits);
}
return start;
}
static void pmap_unschedule(unsigned long *map, int bits_per_period,
int periods_in_map, int num_bits,
int interval, int start)
{
int interval_bits;
int to_release;
int i;
interval = gcd(interval, periods_in_map);
interval_bits = bits_per_period * interval;
to_release = periods_in_map / interval;
for (i = 0; i < to_release; i++) {
int ith_start = start + interval_bits * i;
bitmap_clear(map, ith_start, num_bits);
}
}
static unsigned long *dwc2_get_ls_map(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh)
{
unsigned long *map;
if (WARN_ON(!qh->dwc_tt))
return NULL;
map = qh->dwc_tt->periodic_bitmaps;
if (qh->dwc_tt->usb_tt->multi)
map += DWC2_ELEMENTS_PER_LS_BITMAP * qh->ttport;
return map;
}
void pmap_print(unsigned long *map, int bits_per_period,
int periods_in_map, const char *period_name,
const char *units,
void (*print_fn)(const char *str, void *data),
void *print_data)
{
int period;
for (period = 0; period < periods_in_map; period++) {
char tmp[64];
char *buf = tmp;
size_t buf_size = sizeof(tmp);
int period_start = period * bits_per_period;
int period_end = period_start + bits_per_period;
int start = 0;
int count = 0;
bool printed = false;
int i;
for (i = period_start; i < period_end + 1; i++) {
if (i < period_end &&
bitmap_find_next_zero_area(map, i + 1,
i, 1, 0) != i) {
if (count == 0)
start = i - period_start;
count++;
continue;
}
if (count == 0)
continue;
if (!printed)
cat_printf(&buf, &buf_size, "%s %d: ",
period_name, period);
else
cat_printf(&buf, &buf_size, ", ");
printed = true;
cat_printf(&buf, &buf_size, "%d %s -%3d %s", start,
units, start + count - 1, units);
count = 0;
}
if (printed)
print_fn(tmp, print_data);
}
}
static void dwc2_qh_print(const char *str, void *data)
{
struct dwc2_qh_print_data *print_data = data;
dwc2_sch_dbg(print_data->hsotg, "QH=%p ...%s\n", print_data->qh, str);
}
static void dwc2_qh_schedule_print(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh)
{
struct dwc2_qh_print_data print_data = { hsotg, qh };
int i;
if (qh->schedule_low_speed) {
unsigned long *map = dwc2_get_ls_map(hsotg, qh);
dwc2_sch_dbg(hsotg, "QH=%p LS/FS trans: %d=>%d us @ %d us",
qh, qh->device_us,
DWC2_ROUND_US_TO_SLICE(qh->device_us),
DWC2_US_PER_SLICE * qh->ls_start_schedule_slice);
if (map) {
dwc2_sch_dbg(hsotg,
"QH=%p Whole low/full speed map %p now:\n",
qh, map);
pmap_print(map, DWC2_LS_PERIODIC_SLICES_PER_FRAME,
DWC2_LS_SCHEDULE_FRAMES, "Frame ", "slices",
dwc2_qh_print, &print_data);
}
}
for (i = 0; i < qh->num_hs_transfers; i++) {
struct dwc2_hs_transfer_time *trans_time = qh->hs_transfers + i;
int uframe = trans_time->start_schedule_us /
DWC2_HS_PERIODIC_US_PER_UFRAME;
int rel_us = trans_time->start_schedule_us %
DWC2_HS_PERIODIC_US_PER_UFRAME;
dwc2_sch_dbg(hsotg,
"QH=%p HS trans #%d: %d us @ uFrame %d + %d us\n",
qh, i, trans_time->duration_us, uframe, rel_us);
}
if (qh->num_hs_transfers) {
dwc2_sch_dbg(hsotg, "QH=%p Whole high speed map now:\n", qh);
pmap_print(hsotg->hs_periodic_bitmap,
DWC2_HS_PERIODIC_US_PER_UFRAME,
DWC2_HS_SCHEDULE_UFRAMES, "uFrame", "us",
dwc2_qh_print, &print_data);
}
}
static inline void dwc2_qh_schedule_print(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh) {}
static int dwc2_ls_pmap_schedule(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh,
int search_slice)
{
int slices = DIV_ROUND_UP(qh->device_us, DWC2_US_PER_SLICE);
unsigned long *map = dwc2_get_ls_map(hsotg, qh);
int slice;
if (!map)
return -EINVAL;
slice = pmap_schedule(map, DWC2_LS_PERIODIC_SLICES_PER_FRAME,
DWC2_LS_SCHEDULE_FRAMES, slices,
qh->device_interval, search_slice, false);
if (slice < 0)
return slice;
qh->ls_start_schedule_slice = slice;
return 0;
}
static void dwc2_ls_pmap_unschedule(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh)
{
int slices = DIV_ROUND_UP(qh->device_us, DWC2_US_PER_SLICE);
unsigned long *map = dwc2_get_ls_map(hsotg, qh);
if (!map)
return;
pmap_unschedule(map, DWC2_LS_PERIODIC_SLICES_PER_FRAME,
DWC2_LS_SCHEDULE_FRAMES, slices, qh->device_interval,
qh->ls_start_schedule_slice);
}
static int dwc2_hs_pmap_schedule(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh,
bool only_one_period, int index)
{
struct dwc2_hs_transfer_time *trans_time = qh->hs_transfers + index;
int us;
us = pmap_schedule(hsotg->hs_periodic_bitmap,
DWC2_HS_PERIODIC_US_PER_UFRAME,
DWC2_HS_SCHEDULE_UFRAMES, trans_time->duration_us,
qh->host_interval, trans_time->start_schedule_us,
only_one_period);
if (us < 0)
return us;
trans_time->start_schedule_us = us;
return 0;
}
static void dwc2_hs_pmap_unschedule(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh, int index)
{
struct dwc2_hs_transfer_time *trans_time = qh->hs_transfers + index;
pmap_unschedule(hsotg->hs_periodic_bitmap,
DWC2_HS_PERIODIC_US_PER_UFRAME,
DWC2_HS_SCHEDULE_UFRAMES, trans_time->duration_us,
qh->host_interval, trans_time->start_schedule_us);
}
static int dwc2_uframe_schedule_split(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh)
{
int bytecount = dwc2_hb_mult(qh->maxp) * dwc2_max_packet(qh->maxp);
int ls_search_slice;
int err = 0;
int host_interval_in_sched;
host_interval_in_sched = gcd(qh->host_interval,
DWC2_HS_SCHEDULE_UFRAMES);
ls_search_slice = 0;
while (ls_search_slice < DWC2_LS_SCHEDULE_SLICES) {
int start_s_uframe;
int ssplit_s_uframe;
int second_s_uframe;
int rel_uframe;
int first_count;
int middle_count;
int end_count;
int first_data_bytes;
int other_data_bytes;
int i;
if (qh->schedule_low_speed) {
err = dwc2_ls_pmap_schedule(hsotg, qh, ls_search_slice);
if (err)
return err;
} else {
WARN_ON_ONCE(1);
}
start_s_uframe = qh->ls_start_schedule_slice /
DWC2_SLICES_PER_UFRAME;
rel_uframe = (start_s_uframe % 8);
if (rel_uframe == 7) {
if (qh->schedule_low_speed)
dwc2_ls_pmap_unschedule(hsotg, qh);
ls_search_slice =
(qh->ls_start_schedule_slice /
DWC2_LS_PERIODIC_SLICES_PER_FRAME + 1) *
DWC2_LS_PERIODIC_SLICES_PER_FRAME;
continue;
}
ssplit_s_uframe = (start_s_uframe +
host_interval_in_sched - 1) %
host_interval_in_sched;
if (qh->ep_type == USB_ENDPOINT_XFER_ISOC && !qh->ep_is_in)
second_s_uframe = start_s_uframe;
else
second_s_uframe = start_s_uframe + 1;
first_data_bytes = 188 -
DIV_ROUND_UP(188 * (qh->ls_start_schedule_slice %
DWC2_SLICES_PER_UFRAME),
DWC2_SLICES_PER_UFRAME);
if (first_data_bytes > bytecount)
first_data_bytes = bytecount;
other_data_bytes = bytecount - first_data_bytes;
if (!qh->ep_is_in &&
(first_data_bytes != min_t(int, 188, bytecount))) {
dwc2_sch_dbg(hsotg,
"QH=%p avoiding broken 1st xfer (%d, %d)\n",
qh, first_data_bytes, bytecount);
if (qh->schedule_low_speed)
dwc2_ls_pmap_unschedule(hsotg, qh);
ls_search_slice = (start_s_uframe + 1) *
DWC2_SLICES_PER_UFRAME;
continue;
}
qh->num_hs_transfers = 1 + DIV_ROUND_UP(other_data_bytes, 188);
if (qh->ep_type == USB_ENDPOINT_XFER_INT) {
if (rel_uframe == 6)
qh->num_hs_transfers += 2;
else
qh->num_hs_transfers += 3;
if (qh->ep_is_in) {
first_count = 4;
middle_count = bytecount;
end_count = bytecount;
} else {
first_count = first_data_bytes;
middle_count = max_t(int, 4, other_data_bytes);
end_count = 4;
}
} else {
if (qh->ep_is_in) {
int last;
qh->num_hs_transfers++;
last = rel_uframe + qh->num_hs_transfers + 1;
if (last <= 6)
qh->num_hs_transfers += 2;
else
qh->num_hs_transfers += 1;
if (last >= 6 && rel_uframe == 0)
qh->num_hs_transfers--;
first_count = 4;
middle_count = min_t(int, 188, bytecount);
end_count = middle_count;
} else {
first_count = first_data_bytes;
middle_count = min_t(int, 188,
other_data_bytes);
end_count = other_data_bytes % 188;
}
}
qh->hs_transfers[0].duration_us = HS_USECS_ISO(first_count);
for (i = 1; i < qh->num_hs_transfers - 1; i++)
qh->hs_transfers[i].duration_us =
HS_USECS_ISO(middle_count);
if (qh->num_hs_transfers > 1)
qh->hs_transfers[qh->num_hs_transfers - 1].duration_us =
HS_USECS_ISO(end_count);
qh->hs_transfers[0].start_schedule_us =
ssplit_s_uframe * DWC2_HS_PERIODIC_US_PER_UFRAME;
for (i = 1; i < qh->num_hs_transfers; i++)
qh->hs_transfers[i].start_schedule_us =
((second_s_uframe + i - 1) %
DWC2_HS_SCHEDULE_UFRAMES) *
DWC2_HS_PERIODIC_US_PER_UFRAME;
for (i = 0; i < qh->num_hs_transfers; i++) {
err = dwc2_hs_pmap_schedule(hsotg, qh, true, i);
if (err)
break;
}
if (i == qh->num_hs_transfers)
break;
for (; i >= 0; i--)
dwc2_hs_pmap_unschedule(hsotg, qh, i);
if (qh->schedule_low_speed)
dwc2_ls_pmap_unschedule(hsotg, qh);
ls_search_slice = (start_s_uframe + 1) * DWC2_SLICES_PER_UFRAME;
}
if (ls_search_slice >= DWC2_LS_SCHEDULE_SLICES)
return -ENOSPC;
return 0;
}
static int dwc2_uframe_schedule_hs(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
WARN_ON(qh->host_us != qh->device_us);
WARN_ON(qh->host_interval != qh->device_interval);
WARN_ON(qh->num_hs_transfers != 1);
qh->hs_transfers[0].start_schedule_us = 0;
qh->hs_transfers[0].duration_us = qh->host_us;
return dwc2_hs_pmap_schedule(hsotg, qh, false, 0);
}
static int dwc2_uframe_schedule_ls(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
WARN_ON(qh->host_us != qh->device_us);
WARN_ON(qh->host_interval != qh->device_interval);
WARN_ON(!qh->schedule_low_speed);
return dwc2_ls_pmap_schedule(hsotg, qh, 0);
}
static int dwc2_uframe_schedule(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
int ret;
if (qh->dev_speed == USB_SPEED_HIGH)
ret = dwc2_uframe_schedule_hs(hsotg, qh);
else if (!qh->do_split)
ret = dwc2_uframe_schedule_ls(hsotg, qh);
else
ret = dwc2_uframe_schedule_split(hsotg, qh);
if (ret)
dwc2_sch_dbg(hsotg, "QH=%p Failed to schedule %d\n", qh, ret);
else
dwc2_qh_schedule_print(hsotg, qh);
return ret;
}
static void dwc2_uframe_unschedule(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
int i;
for (i = 0; i < qh->num_hs_transfers; i++)
dwc2_hs_pmap_unschedule(hsotg, qh, i);
if (qh->schedule_low_speed)
dwc2_ls_pmap_unschedule(hsotg, qh);
dwc2_sch_dbg(hsotg, "QH=%p Unscheduled\n", qh);
}
static void dwc2_pick_first_frame(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
u16 frame_number;
u16 earliest_frame;
u16 next_active_frame;
u16 relative_frame;
u16 interval;
frame_number = dwc2_hcd_get_frame_number(hsotg);
earliest_frame = dwc2_frame_num_inc(frame_number, 1);
next_active_frame = earliest_frame;
if (!hsotg->params.uframe_sched) {
if (qh->do_split)
next_active_frame |= 0x7;
goto exit;
}
if (qh->dev_speed == USB_SPEED_HIGH || qh->do_split) {
WARN_ON(qh->num_hs_transfers < 1);
relative_frame = qh->hs_transfers[0].start_schedule_us /
DWC2_HS_PERIODIC_US_PER_UFRAME;
interval = gcd(qh->host_interval, DWC2_HS_SCHEDULE_UFRAMES);
} else {
relative_frame = qh->ls_start_schedule_slice /
DWC2_LS_PERIODIC_SLICES_PER_FRAME;
interval = gcd(qh->host_interval, DWC2_LS_SCHEDULE_FRAMES);
}
WARN_ON(relative_frame >= interval);
next_active_frame = (next_active_frame / interval) * interval;
next_active_frame = dwc2_frame_num_inc(next_active_frame,
relative_frame);
next_active_frame = dwc2_frame_num_dec(next_active_frame, 1);
while (dwc2_frame_num_gt(earliest_frame, next_active_frame))
next_active_frame = dwc2_frame_num_inc(next_active_frame,
interval);
exit:
qh->next_active_frame = next_active_frame;
qh->start_active_frame = next_active_frame;
dwc2_sch_vdbg(hsotg, "QH=%p First fn=%04x nxt=%04x\n",
qh, frame_number, qh->next_active_frame);
}
static int dwc2_do_reserve(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
int status;
if (hsotg->params.uframe_sched) {
status = dwc2_uframe_schedule(hsotg, qh);
} else {
status = dwc2_periodic_channel_available(hsotg);
if (status) {
dev_info(hsotg->dev,
"%s: No host channel available for periodic transfer\n",
__func__);
return status;
}
status = dwc2_check_periodic_bandwidth(hsotg, qh);
}
if (status) {
dev_dbg(hsotg->dev,
"%s: Insufficient periodic bandwidth for periodic transfer\n",
__func__);
return status;
}
if (!hsotg->params.uframe_sched)
hsotg->periodic_channels++;
hsotg->periodic_usecs += qh->host_us;
dwc2_pick_first_frame(hsotg, qh);
return 0;
}
static void dwc2_do_unreserve(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
assert_spin_locked(&hsotg->lock);
WARN_ON(!qh->unreserve_pending);
qh->unreserve_pending = false;
if (WARN_ON(!list_empty(&qh->qh_list_entry)))
list_del_init(&qh->qh_list_entry);
hsotg->periodic_usecs -= qh->host_us;
if (hsotg->params.uframe_sched) {
dwc2_uframe_unschedule(hsotg, qh);
} else {
hsotg->periodic_channels--;
}
}
static void dwc2_unreserve_timer_fn(unsigned long data)
{
struct dwc2_qh *qh = (struct dwc2_qh *)data;
struct dwc2_hsotg *hsotg = qh->hsotg;
unsigned long flags;
while (!spin_trylock_irqsave(&hsotg->lock, flags)) {
if (timer_pending(&qh->unreserve_timer))
return;
}
if (qh->unreserve_pending)
dwc2_do_unreserve(hsotg, qh);
spin_unlock_irqrestore(&hsotg->lock, flags);
}
static int dwc2_check_max_xfer_size(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh)
{
u32 max_xfer_size;
u32 max_channel_xfer_size;
int status = 0;
max_xfer_size = dwc2_max_packet(qh->maxp) * dwc2_hb_mult(qh->maxp);
max_channel_xfer_size = hsotg->params.max_transfer_size;
if (max_xfer_size > max_channel_xfer_size) {
dev_err(hsotg->dev,
"%s: Periodic xfer length %d > max xfer length for channel %d\n",
__func__, max_xfer_size, max_channel_xfer_size);
status = -ENOSPC;
}
return status;
}
static int dwc2_schedule_periodic(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
int status;
status = dwc2_check_max_xfer_size(hsotg, qh);
if (status) {
dev_dbg(hsotg->dev,
"%s: Channel max transfer size too small for periodic transfer\n",
__func__);
return status;
}
if (del_timer(&qh->unreserve_timer))
WARN_ON(!qh->unreserve_pending);
if (!qh->unreserve_pending) {
status = dwc2_do_reserve(hsotg, qh);
if (status)
return status;
} else {
if (dwc2_frame_num_le(qh->next_active_frame,
hsotg->frame_number))
dwc2_pick_first_frame(hsotg, qh);
}
qh->unreserve_pending = 0;
if (hsotg->params.dma_desc_enable)
list_add_tail(&qh->qh_list_entry, &hsotg->periodic_sched_ready);
else
list_add_tail(&qh->qh_list_entry,
&hsotg->periodic_sched_inactive);
return 0;
}
static void dwc2_deschedule_periodic(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh)
{
bool did_modify;
assert_spin_locked(&hsotg->lock);
did_modify = mod_timer(&qh->unreserve_timer,
jiffies + DWC2_UNRESERVE_DELAY + 1);
WARN_ON(did_modify);
qh->unreserve_pending = 1;
list_del_init(&qh->qh_list_entry);
}
static void dwc2_qh_init(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh,
struct dwc2_hcd_urb *urb, gfp_t mem_flags)
{
int dev_speed = dwc2_host_get_speed(hsotg, urb->priv);
u8 ep_type = dwc2_hcd_get_pipe_type(&urb->pipe_info);
bool ep_is_in = !!dwc2_hcd_is_pipe_in(&urb->pipe_info);
bool ep_is_isoc = (ep_type == USB_ENDPOINT_XFER_ISOC);
bool ep_is_int = (ep_type == USB_ENDPOINT_XFER_INT);
u32 hprt = dwc2_readl(hsotg->regs + HPRT0);
u32 prtspd = (hprt & HPRT0_SPD_MASK) >> HPRT0_SPD_SHIFT;
bool do_split = (prtspd == HPRT0_SPD_HIGH_SPEED &&
dev_speed != USB_SPEED_HIGH);
int maxp = dwc2_hcd_get_mps(&urb->pipe_info);
int bytecount = dwc2_hb_mult(maxp) * dwc2_max_packet(maxp);
char *speed, *type;
qh->hsotg = hsotg;
setup_timer(&qh->unreserve_timer, dwc2_unreserve_timer_fn,
(unsigned long)qh);
qh->ep_type = ep_type;
qh->ep_is_in = ep_is_in;
qh->data_toggle = DWC2_HC_PID_DATA0;
qh->maxp = maxp;
INIT_LIST_HEAD(&qh->qtd_list);
INIT_LIST_HEAD(&qh->qh_list_entry);
qh->do_split = do_split;
qh->dev_speed = dev_speed;
if (ep_is_int || ep_is_isoc) {
int host_speed = do_split ? USB_SPEED_HIGH : dev_speed;
struct dwc2_tt *dwc_tt = dwc2_host_get_tt_info(hsotg, urb->priv,
mem_flags,
&qh->ttport);
int device_ns;
qh->dwc_tt = dwc_tt;
qh->host_us = NS_TO_US(usb_calc_bus_time(host_speed, ep_is_in,
ep_is_isoc, bytecount));
device_ns = usb_calc_bus_time(dev_speed, ep_is_in,
ep_is_isoc, bytecount);
if (do_split && dwc_tt)
device_ns += dwc_tt->usb_tt->think_time;
qh->device_us = NS_TO_US(device_ns);
qh->device_interval = urb->interval;
qh->host_interval = urb->interval * (do_split ? 8 : 1);
qh->schedule_low_speed = prtspd != HPRT0_SPD_HIGH_SPEED ||
dwc_tt;
if (do_split) {
qh->num_hs_transfers = -1;
} else if (dev_speed == USB_SPEED_HIGH) {
qh->num_hs_transfers = 1;
} else {
qh->num_hs_transfers = 0;
}
}
switch (dev_speed) {
case USB_SPEED_LOW:
speed = "low";
break;
case USB_SPEED_FULL:
speed = "full";
break;
case USB_SPEED_HIGH:
speed = "high";
break;
default:
speed = "?";
break;
}
switch (qh->ep_type) {
case USB_ENDPOINT_XFER_ISOC:
type = "isochronous";
break;
case USB_ENDPOINT_XFER_INT:
type = "interrupt";
break;
case USB_ENDPOINT_XFER_CONTROL:
type = "control";
break;
case USB_ENDPOINT_XFER_BULK:
type = "bulk";
break;
default:
type = "?";
break;
}
dwc2_sch_dbg(hsotg, "QH=%p Init %s, %s speed, %d bytes:\n", qh, type,
speed, bytecount);
dwc2_sch_dbg(hsotg, "QH=%p ...addr=%d, ep=%d, %s\n", qh,
dwc2_hcd_get_dev_addr(&urb->pipe_info),
dwc2_hcd_get_ep_num(&urb->pipe_info),
ep_is_in ? "IN" : "OUT");
if (ep_is_int || ep_is_isoc) {
dwc2_sch_dbg(hsotg,
"QH=%p ...duration: host=%d us, device=%d us\n",
qh, qh->host_us, qh->device_us);
dwc2_sch_dbg(hsotg, "QH=%p ...interval: host=%d, device=%d\n",
qh, qh->host_interval, qh->device_interval);
if (qh->schedule_low_speed)
dwc2_sch_dbg(hsotg, "QH=%p ...low speed schedule=%p\n",
qh, dwc2_get_ls_map(hsotg, qh));
}
}
struct dwc2_qh *dwc2_hcd_qh_create(struct dwc2_hsotg *hsotg,
struct dwc2_hcd_urb *urb,
gfp_t mem_flags)
{
struct dwc2_qh *qh;
if (!urb->priv)
return NULL;
qh = kzalloc(sizeof(*qh), mem_flags);
if (!qh)
return NULL;
dwc2_qh_init(hsotg, qh, urb, mem_flags);
if (hsotg->params.dma_desc_enable &&
dwc2_hcd_qh_init_ddma(hsotg, qh, mem_flags) < 0) {
dwc2_hcd_qh_free(hsotg, qh);
return NULL;
}
return qh;
}
void dwc2_hcd_qh_free(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
if (del_timer_sync(&qh->unreserve_timer)) {
unsigned long flags;
spin_lock_irqsave(&hsotg->lock, flags);
dwc2_do_unreserve(hsotg, qh);
spin_unlock_irqrestore(&hsotg->lock, flags);
}
dwc2_host_put_tt_info(hsotg, qh->dwc_tt);
if (qh->desc_list)
dwc2_hcd_qh_free_ddma(hsotg, qh);
kfree(qh);
}
int dwc2_hcd_qh_add(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
int status;
u32 intr_mask;
if (dbg_qh(qh))
dev_vdbg(hsotg->dev, "%s()\n", __func__);
if (!list_empty(&qh->qh_list_entry))
return 0;
if (dwc2_qh_is_non_per(qh)) {
qh->start_active_frame = hsotg->frame_number;
qh->next_active_frame = qh->start_active_frame;
list_add_tail(&qh->qh_list_entry,
&hsotg->non_periodic_sched_inactive);
return 0;
}
status = dwc2_schedule_periodic(hsotg, qh);
if (status)
return status;
if (!hsotg->periodic_qh_count) {
intr_mask = dwc2_readl(hsotg->regs + GINTMSK);
intr_mask |= GINTSTS_SOF;
dwc2_writel(intr_mask, hsotg->regs + GINTMSK);
}
hsotg->periodic_qh_count++;
return 0;
}
void dwc2_hcd_qh_unlink(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh)
{
u32 intr_mask;
dev_vdbg(hsotg->dev, "%s()\n", __func__);
if (list_empty(&qh->qh_list_entry))
return;
if (dwc2_qh_is_non_per(qh)) {
if (hsotg->non_periodic_qh_ptr == &qh->qh_list_entry)
hsotg->non_periodic_qh_ptr =
hsotg->non_periodic_qh_ptr->next;
list_del_init(&qh->qh_list_entry);
return;
}
dwc2_deschedule_periodic(hsotg, qh);
hsotg->periodic_qh_count--;
if (!hsotg->periodic_qh_count &&
!hsotg->params.dma_desc_enable) {
intr_mask = dwc2_readl(hsotg->regs + GINTMSK);
intr_mask &= ~GINTSTS_SOF;
dwc2_writel(intr_mask, hsotg->regs + GINTMSK);
}
}
static int dwc2_next_for_periodic_split(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh, u16 frame_number)
{
u16 old_frame = qh->next_active_frame;
u16 prev_frame_number = dwc2_frame_num_dec(frame_number, 1);
int missed = 0;
u16 incr;
if (old_frame == qh->start_active_frame &&
!(qh->ep_type == USB_ENDPOINT_XFER_ISOC && !qh->ep_is_in))
incr = 2;
else
incr = 1;
qh->next_active_frame = dwc2_frame_num_inc(old_frame, incr);
if (dwc2_frame_num_gt(prev_frame_number, qh->next_active_frame)) {
missed = dwc2_frame_num_dec(prev_frame_number,
qh->next_active_frame);
qh->next_active_frame = frame_number;
}
return missed;
}
static int dwc2_next_periodic_start(struct dwc2_hsotg *hsotg,
struct dwc2_qh *qh, u16 frame_number)
{
int missed = 0;
u16 interval = qh->host_interval;
u16 prev_frame_number = dwc2_frame_num_dec(frame_number, 1);
qh->start_active_frame = dwc2_frame_num_inc(qh->start_active_frame,
interval);
if (interval >= 0x1000)
goto exit;
if (qh->start_active_frame == qh->next_active_frame ||
dwc2_frame_num_gt(prev_frame_number, qh->start_active_frame)) {
u16 ideal_start = qh->start_active_frame;
int periods_in_map;
if (qh->do_split || qh->dev_speed == USB_SPEED_HIGH)
periods_in_map = DWC2_HS_SCHEDULE_UFRAMES;
else
periods_in_map = DWC2_LS_SCHEDULE_FRAMES;
interval = gcd(interval, periods_in_map);
do {
qh->start_active_frame = dwc2_frame_num_inc(
qh->start_active_frame, interval);
} while (dwc2_frame_num_gt(prev_frame_number,
qh->start_active_frame));
missed = dwc2_frame_num_dec(qh->start_active_frame,
ideal_start);
}
exit:
qh->next_active_frame = qh->start_active_frame;
return missed;
}
void dwc2_hcd_qh_deactivate(struct dwc2_hsotg *hsotg, struct dwc2_qh *qh,
int sched_next_periodic_split)
{
u16 old_frame = qh->next_active_frame;
u16 frame_number;
int missed;
if (dbg_qh(qh))
dev_vdbg(hsotg->dev, "%s()\n", __func__);
if (dwc2_qh_is_non_per(qh)) {
dwc2_hcd_qh_unlink(hsotg, qh);
if (!list_empty(&qh->qtd_list))
dwc2_hcd_qh_add(hsotg, qh);
return;
}
frame_number = dwc2_hcd_get_frame_number(hsotg);
if (sched_next_periodic_split)
missed = dwc2_next_for_periodic_split(hsotg, qh, frame_number);
else
missed = dwc2_next_periodic_start(hsotg, qh, frame_number);
dwc2_sch_vdbg(hsotg,
"QH=%p next(%d) fn=%04x, sch=%04x=>%04x (%+d) miss=%d %s\n",
qh, sched_next_periodic_split, frame_number, old_frame,
qh->next_active_frame,
dwc2_frame_num_dec(qh->next_active_frame, old_frame),
missed, missed ? "MISS" : "");
if (list_empty(&qh->qtd_list)) {
dwc2_hcd_qh_unlink(hsotg, qh);
return;
}
if (dwc2_frame_num_le(qh->next_active_frame, hsotg->frame_number))
list_move_tail(&qh->qh_list_entry,
&hsotg->periodic_sched_ready);
else
list_move_tail(&qh->qh_list_entry,
&hsotg->periodic_sched_inactive);
}
void dwc2_hcd_qtd_init(struct dwc2_qtd *qtd, struct dwc2_hcd_urb *urb)
{
qtd->urb = urb;
if (dwc2_hcd_get_pipe_type(&urb->pipe_info) ==
USB_ENDPOINT_XFER_CONTROL) {
qtd->data_toggle = DWC2_HC_PID_DATA1;
qtd->control_phase = DWC2_CONTROL_SETUP;
}
qtd->complete_split = 0;
qtd->isoc_split_pos = DWC2_HCSPLT_XACTPOS_ALL;
qtd->isoc_split_offset = 0;
qtd->in_process = 0;
urb->qtd = qtd;
}
int dwc2_hcd_qtd_add(struct dwc2_hsotg *hsotg, struct dwc2_qtd *qtd,
struct dwc2_qh *qh)
{
int retval;
if (unlikely(!qh)) {
dev_err(hsotg->dev, "%s: Invalid QH\n", __func__);
retval = -EINVAL;
goto fail;
}
retval = dwc2_hcd_qh_add(hsotg, qh);
if (retval)
goto fail;
qtd->qh = qh;
list_add_tail(&qtd->qtd_list_entry, &qh->qtd_list);
return 0;
fail:
return retval;
}
