static inline const char *
symbolic(struct hfcusb_symbolic_list list[], const int num)
{
int i;
for (i = 0; list[i].name != NULL; i++)
if (list[i].num == num)
return (list[i].name);
return "<unknown ERROR>";
}
static void
ctrl_start_transfer(hfcusb_data *hfc)
{
if (hfc->ctrl_cnt) {
hfc->ctrl_urb->pipe = hfc->ctrl_out_pipe;
hfc->ctrl_urb->setup_packet = (u_char *)&hfc->ctrl_write;
hfc->ctrl_urb->transfer_buffer = NULL;
hfc->ctrl_urb->transfer_buffer_length = 0;
hfc->ctrl_write.wIndex =
cpu_to_le16(hfc->ctrl_buff[hfc->ctrl_out_idx].hfc_reg);
hfc->ctrl_write.wValue =
cpu_to_le16(hfc->ctrl_buff[hfc->ctrl_out_idx].reg_val);
usb_submit_urb(hfc->ctrl_urb, GFP_ATOMIC);
}
}
static int
queue_control_request(hfcusb_data *hfc, __u8 reg, __u8 val, int action)
{
ctrl_buft *buf;
if (hfc->ctrl_cnt >= HFC_CTRL_BUFSIZE)
return (1);
buf = &hfc->ctrl_buff[hfc->ctrl_in_idx];
buf->hfc_reg = reg;
buf->reg_val = val;
buf->action = action;
if (++hfc->ctrl_in_idx >= HFC_CTRL_BUFSIZE)
hfc->ctrl_in_idx = 0;
if (++hfc->ctrl_cnt == 1)
ctrl_start_transfer(hfc);
return (0);
}
static void
ctrl_complete(struct urb *urb)
{
hfcusb_data *hfc = (hfcusb_data *) urb->context;
urb->dev = hfc->dev;
if (hfc->ctrl_cnt) {
hfc->ctrl_cnt--;
if (++hfc->ctrl_out_idx >= HFC_CTRL_BUFSIZE)
hfc->ctrl_out_idx = 0;
ctrl_start_transfer(hfc);
}
}
static void
write_led(hfcusb_data *hfc, __u8 led_state)
{
if (led_state != hfc->old_led_state) {
hfc->old_led_state = led_state;
queue_control_request(hfc, HFCUSB_P_DATA, led_state, 1);
}
}
static void
set_led_bit(hfcusb_data *hfc, signed short led_bits, int on)
{
if (on) {
if (led_bits < 0)
hfc->led_state &= ~abs(led_bits);
else
hfc->led_state |= led_bits;
} else {
if (led_bits < 0)
hfc->led_state |= abs(led_bits);
else
hfc->led_state &= ~led_bits;
}
}
static void
handle_led(hfcusb_data *hfc, int event)
{
hfcsusb_vdata *driver_info =
(hfcsusb_vdata *) hfcusb_idtab[hfc->vend_idx].driver_info;
if (driver_info->led_scheme == LED_OFF)
return;
switch (event) {
case LED_POWER_ON:
set_led_bit(hfc, driver_info->led_bits[0], 1);
set_led_bit(hfc, driver_info->led_bits[1], 0);
set_led_bit(hfc, driver_info->led_bits[2], 0);
set_led_bit(hfc, driver_info->led_bits[3], 0);
break;
case LED_POWER_OFF:
set_led_bit(hfc, driver_info->led_bits[0], 0);
set_led_bit(hfc, driver_info->led_bits[1], 0);
set_led_bit(hfc, driver_info->led_bits[2], 0);
set_led_bit(hfc, driver_info->led_bits[3], 0);
break;
case LED_S0_ON:
set_led_bit(hfc, driver_info->led_bits[1], 1);
break;
case LED_S0_OFF:
set_led_bit(hfc, driver_info->led_bits[1], 0);
break;
case LED_B1_ON:
set_led_bit(hfc, driver_info->led_bits[2], 1);
break;
case LED_B1_OFF:
set_led_bit(hfc, driver_info->led_bits[2], 0);
break;
case LED_B2_ON:
set_led_bit(hfc, driver_info->led_bits[3], 1);
break;
case LED_B2_OFF:
set_led_bit(hfc, driver_info->led_bits[3], 0);
break;
}
write_led(hfc, hfc->led_state);
}
static void
l1_timer_expire_t3(hfcusb_data *hfc)
{
hfc->d_if.ifc.l1l2(&hfc->d_if.ifc, PH_DEACTIVATE | INDICATION,
NULL);
DBG(HFCUSB_DBG_STATES,
"HFC-S USB: PH_DEACTIVATE | INDICATION sent (T3 expire)");
hfc->l1_activated = 0;
handle_led(hfc, LED_S0_OFF);
queue_control_request(hfc, HFCUSB_STATES, 0x10, 1);
queue_control_request(hfc, HFCUSB_STATES, 3, 1);
}
static void
l1_timer_expire_t4(hfcusb_data *hfc)
{
hfc->d_if.ifc.l1l2(&hfc->d_if.ifc, PH_DEACTIVATE | INDICATION,
NULL);
DBG(HFCUSB_DBG_STATES,
"HFC-S USB: PH_DEACTIVATE | INDICATION sent (T4 expire)");
hfc->l1_activated = 0;
handle_led(hfc, LED_S0_OFF);
}
static void
s0_state_handler(hfcusb_data *hfc, __u8 state)
{
__u8 old_state;
old_state = hfc->l1_state;
if (state == old_state || state < 1 || state > 8)
return;
DBG(HFCUSB_DBG_STATES, "HFC-S USB: S0 statechange(%d -> %d)",
old_state, state);
if (state < 4 || state == 7 || state == 8) {
if (timer_pending(&hfc->t3_timer))
del_timer(&hfc->t3_timer);
DBG(HFCUSB_DBG_STATES, "HFC-S USB: T3 deactivated");
}
if (state >= 7) {
if (timer_pending(&hfc->t4_timer))
del_timer(&hfc->t4_timer);
DBG(HFCUSB_DBG_STATES, "HFC-S USB: T4 deactivated");
}
if (state == 7 && !hfc->l1_activated) {
hfc->d_if.ifc.l1l2(&hfc->d_if.ifc,
PH_ACTIVATE | INDICATION, NULL);
DBG(HFCUSB_DBG_STATES, "HFC-S USB: PH_ACTIVATE | INDICATION sent");
hfc->l1_activated = 1;
handle_led(hfc, LED_S0_ON);
} else if (state <= 3 ) {
if (old_state == 7 || old_state == 8) {
DBG(HFCUSB_DBG_STATES, "HFC-S USB: T4 activated");
if (!timer_pending(&hfc->t4_timer)) {
hfc->t4_timer.expires =
jiffies + (HFC_TIMER_T4 * HZ) / 1000;
add_timer(&hfc->t4_timer);
}
} else {
hfc->d_if.ifc.l1l2(&hfc->d_if.ifc,
PH_DEACTIVATE | INDICATION,
NULL);
DBG(HFCUSB_DBG_STATES,
"HFC-S USB: PH_DEACTIVATE | INDICATION sent");
hfc->l1_activated = 0;
handle_led(hfc, LED_S0_OFF);
}
}
hfc->l1_state = state;
}
static void
fill_isoc_urb(struct urb *urb, struct usb_device *dev, unsigned int pipe,
void *buf, int num_packets, int packet_size, int interval,
usb_complete_t complete, void *context)
{
int k;
urb->dev = dev;
urb->pipe = pipe;
urb->complete = complete;
urb->number_of_packets = num_packets;
urb->transfer_buffer_length = packet_size * num_packets;
urb->context = context;
urb->transfer_buffer = buf;
urb->transfer_flags = URB_ISO_ASAP;
urb->actual_length = 0;
urb->interval = interval;
for (k = 0; k < num_packets; k++) {
urb->iso_frame_desc[k].offset = packet_size * k;
urb->iso_frame_desc[k].length = packet_size;
urb->iso_frame_desc[k].actual_length = 0;
}
}
static int
start_isoc_chain(usb_fifo *fifo, int num_packets_per_urb,
usb_complete_t complete, int packet_size)
{
int i, k, errcode;
DBG(HFCUSB_DBG_INIT, "HFC-S USB: starting ISO-URBs for fifo:%d\n",
fifo->fifonum);
for (i = 0; i < 2; i++) {
if (!(fifo->iso[i].purb)) {
fifo->iso[i].purb =
usb_alloc_urb(num_packets_per_urb, GFP_KERNEL);
if (!(fifo->iso[i].purb)) {
printk(KERN_INFO
"alloc urb for fifo %i failed!!!",
fifo->fifonum);
}
fifo->iso[i].owner_fifo = (struct usb_fifo *) fifo;
if (ISO_BUFFER_SIZE >=
(fifo->usb_packet_maxlen *
num_packets_per_urb)) {
fill_isoc_urb(fifo->iso[i].purb,
fifo->hfc->dev, fifo->pipe,
fifo->iso[i].buffer,
num_packets_per_urb,
fifo->usb_packet_maxlen,
fifo->intervall, complete,
&fifo->iso[i]);
memset(fifo->iso[i].buffer, 0,
sizeof(fifo->iso[i].buffer));
for (k = 0; k < num_packets_per_urb; k++) {
fifo->iso[i].purb->
iso_frame_desc[k].offset =
k * packet_size;
fifo->iso[i].purb->
iso_frame_desc[k].length =
packet_size;
}
} else {
printk(KERN_INFO
"HFC-S USB: ISO Buffer size to small!\n");
}
}
fifo->bit_line = BITLINE_INF;
errcode = usb_submit_urb(fifo->iso[i].purb, GFP_KERNEL);
fifo->active = (errcode >= 0) ? 1 : 0;
if (errcode < 0)
printk(KERN_INFO "HFC-S USB: usb_submit_urb URB nr:%d, error(%i): '%s'\n",
i, errcode, symbolic(urb_errlist, errcode));
}
return (fifo->active);
}
static void
stop_isoc_chain(usb_fifo *fifo)
{
int i;
for (i = 0; i < 2; i++) {
if (fifo->iso[i].purb) {
DBG(HFCUSB_DBG_INIT,
"HFC-S USB: Stopping iso chain for fifo %i.%i",
fifo->fifonum, i);
usb_kill_urb(fifo->iso[i].purb);
usb_free_urb(fifo->iso[i].purb);
fifo->iso[i].purb = NULL;
}
}
usb_kill_urb(fifo->urb);
usb_free_urb(fifo->urb);
fifo->urb = NULL;
fifo->active = 0;
}
static void
tx_iso_complete(struct urb *urb)
{
iso_urb_struct *context_iso_urb = (iso_urb_struct *) urb->context;
usb_fifo *fifo = context_iso_urb->owner_fifo;
hfcusb_data *hfc = fifo->hfc;
int k, tx_offset, num_isoc_packets, sink, len, current_len,
errcode;
int frame_complete, transp_mode, fifon, status;
__u8 threshbit;
fifon = fifo->fifonum;
status = urb->status;
tx_offset = 0;
if (status == -EXDEV) {
DBG(HFCUSB_DBG_VERBOSE_USB, "HFC-S USB: tx_iso_complete with -EXDEV"
", urb->status %d, fifonum %d\n",
status, fifon);
for (k = 0; k < iso_packets[fifon]; ++k) {
errcode = urb->iso_frame_desc[k].status;
if (errcode)
DBG(HFCUSB_DBG_VERBOSE_USB, "HFC-S USB: tx_iso_complete "
"packet %i, status: %i\n",
k, errcode);
}
status = 0;
}
if (fifo->active && !status) {
transp_mode = 0;
if (fifon < 4 && hfc->b_mode[fifon / 2] == L1_MODE_TRANS)
transp_mode = 1;
threshbit = (hfc->threshold_mask & (1 << fifon));
num_isoc_packets = iso_packets[fifon];
if (fifon >= HFCUSB_D_TX) {
sink = (threshbit) ? SINK_DMIN : SINK_DMAX;
} else {
sink = (threshbit) ? SINK_MIN : SINK_MAX;
}
fill_isoc_urb(urb, fifo->hfc->dev, fifo->pipe,
context_iso_urb->buffer, num_isoc_packets,
fifo->usb_packet_maxlen, fifo->intervall,
tx_iso_complete, urb->context);
memset(context_iso_urb->buffer, 0,
sizeof(context_iso_urb->buffer));
frame_complete = 0;
for (k = 0; k < num_isoc_packets; ++k) {
if (fifo->skbuff) {
len = fifo->skbuff->len;
fifo->bit_line -= sink;
current_len = (0 - fifo->bit_line) / 8;
if (current_len > 14)
current_len = 14;
current_len =
(len <=
current_len) ? len : current_len;
fifo->bit_line += current_len * 8;
context_iso_urb->buffer[tx_offset] = 0;
if (current_len == len) {
if (!transp_mode) {
context_iso_urb->
buffer[tx_offset] = 1;
fifo->bit_line += 32;
}
frame_complete = 1;
}
memcpy(context_iso_urb->buffer +
tx_offset + 1, fifo->skbuff->data,
current_len);
skb_pull(fifo->skbuff, current_len);
urb->iso_frame_desc[k].offset = tx_offset;
urb->iso_frame_desc[k].length =
current_len + 1;
tx_offset += (current_len + 1);
} else {
urb->iso_frame_desc[k].offset =
tx_offset++;
urb->iso_frame_desc[k].length = 1;
fifo->bit_line -= sink;
if (fifo->bit_line < BITLINE_INF) {
fifo->bit_line = BITLINE_INF;
}
}
if (frame_complete) {
fifo->delete_flg = 1;
fifo->hif->l1l2(fifo->hif,
PH_DATA | CONFIRM,
(void *) (unsigned long) fifo->skbuff->
truesize);
if (fifo->skbuff && fifo->delete_flg) {
dev_kfree_skb_any(fifo->skbuff);
fifo->skbuff = NULL;
fifo->delete_flg = 0;
}
frame_complete = 0;
}
}
errcode = usb_submit_urb(urb, GFP_ATOMIC);
if (errcode < 0) {
printk(KERN_INFO
"HFC-S USB: error submitting ISO URB: %d\n",
errcode);
}
} else {
if (status && !hfc->disc_flag) {
printk(KERN_INFO
"HFC-S USB: tx_iso_complete: error(%i): '%s', fifonum=%d\n",
status, symbolic(urb_errlist, status), fifon);
}
}
}
static void
rx_iso_complete(struct urb *urb)
{
iso_urb_struct *context_iso_urb = (iso_urb_struct *) urb->context;
usb_fifo *fifo = context_iso_urb->owner_fifo;
hfcusb_data *hfc = fifo->hfc;
int k, len, errcode, offset, num_isoc_packets, fifon, maxlen,
status;
unsigned int iso_status;
__u8 *buf;
static __u8 eof[8];
fifon = fifo->fifonum;
status = urb->status;
if (urb->status == -EOVERFLOW) {
DBG(HFCUSB_DBG_VERBOSE_USB,
"HFC-USB: ignoring USB DATAOVERRUN fifo(%i)", fifon);
status = 0;
}
if (status == -EXDEV) {
DBG(HFCUSB_DBG_VERBOSE_USB, "HFC-S USB: rx_iso_complete with -EXDEV "
"urb->status %d, fifonum %d\n",
status, fifon);
status = 0;
}
if (fifo->active && !status) {
num_isoc_packets = iso_packets[fifon];
maxlen = fifo->usb_packet_maxlen;
for (k = 0; k < num_isoc_packets; ++k) {
len = urb->iso_frame_desc[k].actual_length;
offset = urb->iso_frame_desc[k].offset;
buf = context_iso_urb->buffer + offset;
iso_status = urb->iso_frame_desc[k].status;
if (iso_status && !hfc->disc_flag)
DBG(HFCUSB_DBG_VERBOSE_USB,
"HFC-S USB: rx_iso_complete "
"ISO packet %i, status: %i\n",
k, iso_status);
if (fifon == HFCUSB_D_RX) {
DBG(HFCUSB_DBG_VERBOSE_USB,
"HFC-S USB: ISO-D-RX lst_urblen:%2d "
"act_urblen:%2d max-urblen:%2d EOF:0x%0x",
fifo->last_urblen, len, maxlen,
eof[5]);
DBG_PACKET(HFCUSB_DBG_VERBOSE_USB, buf, len);
}
if (fifo->last_urblen != maxlen) {
hfc->threshold_mask = buf[1];
if (fifon == HFCUSB_D_RX) {
s0_state_handler(hfc, buf[0] >> 4);
}
eof[fifon] = buf[0] & 1;
if (len > 2)
collect_rx_frame(fifo, buf + 2,
len - 2,
(len < maxlen) ?
eof[fifon] : 0);
} else {
collect_rx_frame(fifo, buf, len,
(len <
maxlen) ? eof[fifon] :
0);
}
fifo->last_urblen = len;
}
fill_isoc_urb(urb, fifo->hfc->dev, fifo->pipe,
context_iso_urb->buffer, num_isoc_packets,
fifo->usb_packet_maxlen, fifo->intervall,
rx_iso_complete, urb->context);
errcode = usb_submit_urb(urb, GFP_ATOMIC);
if (errcode < 0) {
printk(KERN_ERR
"HFC-S USB: error submitting ISO URB: %d\n",
errcode);
}
} else {
if (status && !hfc->disc_flag) {
printk(KERN_ERR
"HFC-S USB: rx_iso_complete : "
"urb->status %d, fifonum %d\n",
status, fifon);
}
}
}
static void
collect_rx_frame(usb_fifo *fifo, __u8 *data, int len, int finish)
{
hfcusb_data *hfc = fifo->hfc;
int transp_mode, fifon;
fifon = fifo->fifonum;
transp_mode = 0;
if (fifon < 4 && hfc->b_mode[fifon / 2] == L1_MODE_TRANS)
transp_mode = 1;
if (!fifo->skbuff) {
fifo->skbuff = dev_alloc_skb(fifo->max_size + 3);
if (!fifo->skbuff) {
printk(KERN_ERR
"HFC-S USB: cannot allocate buffer for fifo(%d)\n",
fifon);
return;
}
}
if (len) {
if (fifo->skbuff->len + len < fifo->max_size) {
memcpy(skb_put(fifo->skbuff, len), data, len);
} else {
DBG(HFCUSB_DBG_FIFO_ERR,
"HCF-USB: got frame exceeded fifo->max_size(%d) fifo(%d)",
fifo->max_size, fifon);
DBG_SKB(HFCUSB_DBG_VERBOSE_USB, fifo->skbuff);
skb_trim(fifo->skbuff, 0);
}
}
if (transp_mode && fifo->skbuff->len >= 128) {
fifo->hif->l1l2(fifo->hif, PH_DATA | INDICATION,
fifo->skbuff);
fifo->skbuff = NULL;
return;
}
if (finish) {
if (fifo->skbuff->len > 3 &&
!fifo->skbuff->data[fifo->skbuff->len - 1]) {
if (fifon == HFCUSB_D_RX) {
DBG(HFCUSB_DBG_DCHANNEL,
"HFC-S USB: D-RX len(%d)", fifo->skbuff->len);
DBG_SKB(HFCUSB_DBG_DCHANNEL, fifo->skbuff);
}
skb_trim(fifo->skbuff, fifo->skbuff->len - 3);
if (fifon == HFCUSB_PCM_RX) {
fifo->hif->l1l2(fifo->hif,
PH_DATA_E | INDICATION,
fifo->skbuff);
} else
fifo->hif->l1l2(fifo->hif,
PH_DATA | INDICATION,
fifo->skbuff);
fifo->skbuff = NULL;
} else {
DBG(HFCUSB_DBG_FIFO_ERR,
"HFC-S USB: ERROR frame len(%d) fifo(%d)",
fifo->skbuff->len, fifon);
DBG_SKB(HFCUSB_DBG_VERBOSE_USB, fifo->skbuff);
skb_trim(fifo->skbuff, 0);
}
}
}
static void
rx_int_complete(struct urb *urb)
{
int len;
int status;
__u8 *buf, maxlen, fifon;
usb_fifo *fifo = (usb_fifo *) urb->context;
hfcusb_data *hfc = fifo->hfc;
static __u8 eof[8];
urb->dev = hfc->dev;
fifon = fifo->fifonum;
if ((!fifo->active) || (urb->status)) {
DBG(HFCUSB_DBG_INIT, "HFC-S USB: RX-Fifo %i is going down (%i)",
fifon, urb->status);
fifo->urb->interval = 0;
if (fifo->skbuff) {
dev_kfree_skb_any(fifo->skbuff);
fifo->skbuff = NULL;
}
return;
}
len = urb->actual_length;
buf = fifo->buffer;
maxlen = fifo->usb_packet_maxlen;
if (fifon == HFCUSB_D_RX) {
DBG(HFCUSB_DBG_VERBOSE_USB,
"HFC-S USB: INT-D-RX lst_urblen:%2d "
"act_urblen:%2d max-urblen:%2d EOF:0x%0x",
fifo->last_urblen, len, maxlen,
eof[5]);
DBG_PACKET(HFCUSB_DBG_VERBOSE_USB, buf, len);
}
if (fifo->last_urblen != fifo->usb_packet_maxlen) {
hfc->threshold_mask = buf[1];
s0_state_handler(hfc, buf[0] >> 4);
eof[fifon] = buf[0] & 1;
if (len > 2)
collect_rx_frame(fifo, buf + 2,
urb->actual_length - 2,
(len < maxlen) ? eof[fifon] : 0);
} else {
collect_rx_frame(fifo, buf, urb->actual_length,
(len < maxlen) ? eof[fifon] : 0);
}
fifo->last_urblen = urb->actual_length;
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status) {
printk(KERN_INFO
"HFC-S USB: %s error resubmitting URB fifo(%d)\n",
__func__, fifon);
}
}
static void
start_int_fifo(usb_fifo *fifo)
{
int errcode;
DBG(HFCUSB_DBG_INIT, "HFC-S USB: starting RX INT-URB for fifo:%d\n",
fifo->fifonum);
if (!fifo->urb) {
fifo->urb = usb_alloc_urb(0, GFP_KERNEL);
if (!fifo->urb)
return;
}
usb_fill_int_urb(fifo->urb, fifo->hfc->dev, fifo->pipe,
fifo->buffer, fifo->usb_packet_maxlen,
rx_int_complete, fifo, fifo->intervall);
fifo->active = 1;
errcode = usb_submit_urb(fifo->urb, GFP_KERNEL);
if (errcode) {
printk(KERN_ERR
"HFC-S USB: submit URB error(start_int_info): status:%i\n",
errcode);
fifo->active = 0;
fifo->skbuff = NULL;
}
}
static void
setup_bchannel(hfcusb_data *hfc, int channel, int mode)
{
__u8 val, idx_table[2] = { 0, 2 };
if (hfc->disc_flag) {
return;
}
DBG(HFCUSB_DBG_STATES, "HFC-S USB: setting channel %d to mode %d",
channel, mode);
hfc->b_mode[channel] = mode;
val = 0;
if (mode != L1_MODE_NULL)
val = 8;
if (mode == L1_MODE_TRANS)
val |= 2;
queue_control_request(hfc, HFCUSB_FIFO, idx_table[channel], 1);
queue_control_request(hfc, HFCUSB_CON_HDLC, val, 1);
queue_control_request(hfc, HFCUSB_INC_RES_F, 2, 1);
queue_control_request(hfc, HFCUSB_FIFO, idx_table[channel] + 1, 1);
queue_control_request(hfc, HFCUSB_CON_HDLC, val, 1);
queue_control_request(hfc, HFCUSB_INC_RES_F, 2, 1);
val = 0x40;
if (hfc->b_mode[0])
val |= 1;
if (hfc->b_mode[1])
val |= 2;
queue_control_request(hfc, HFCUSB_SCTRL, val, 1);
val = 0;
if (hfc->b_mode[0])
val |= 1;
if (hfc->b_mode[1])
val |= 2;
queue_control_request(hfc, HFCUSB_SCTRL_R, val, 1);
if (mode == L1_MODE_NULL) {
if (channel)
handle_led(hfc, LED_B2_OFF);
else
handle_led(hfc, LED_B1_OFF);
} else {
if (channel)
handle_led(hfc, LED_B2_ON);
else
handle_led(hfc, LED_B1_ON);
}
}
static void
hfc_usb_l2l1(struct hisax_if *my_hisax_if, int pr, void *arg)
{
usb_fifo *fifo = my_hisax_if->priv;
hfcusb_data *hfc = fifo->hfc;
switch (pr) {
case PH_ACTIVATE | REQUEST:
if (fifo->fifonum == HFCUSB_D_TX) {
DBG(HFCUSB_DBG_STATES,
"HFC_USB: hfc_usb_d_l2l1 D-chan: PH_ACTIVATE | REQUEST");
if (hfc->l1_state != 3
&& hfc->l1_state != 7) {
hfc->d_if.ifc.l1l2(&hfc->d_if.ifc,
PH_DEACTIVATE |
INDICATION,
NULL);
DBG(HFCUSB_DBG_STATES,
"HFC-S USB: PH_DEACTIVATE | INDICATION sent (not state 3 or 7)");
} else {
if (hfc->l1_state == 7) {
hfc->d_if.ifc.l1l2(&hfc->
d_if.
ifc,
PH_ACTIVATE
|
INDICATION,
NULL);
DBG(HFCUSB_DBG_STATES,
"HFC-S USB: PH_ACTIVATE | INDICATION sent again ;)");
} else {
queue_control_request(hfc,
HFCUSB_STATES,
0x14,
1);
mdelay(1);
queue_control_request(hfc,
HFCUSB_STATES,
0x04,
1);
if (!timer_pending
(&hfc->t3_timer)) {
hfc->t3_timer.
expires =
jiffies +
(HFC_TIMER_T3 *
HZ) / 1000;
add_timer(&hfc->
t3_timer);
}
}
}
} else {
DBG(HFCUSB_DBG_STATES,
"HFC_USB: hfc_usb_d_l2l1 B-chan: PH_ACTIVATE | REQUEST");
setup_bchannel(hfc,
(fifo->fifonum ==
HFCUSB_B1_TX) ? 0 : 1,
(long) arg);
fifo->hif->l1l2(fifo->hif,
PH_ACTIVATE | INDICATION,
NULL);
}
break;
case PH_DEACTIVATE | REQUEST:
if (fifo->fifonum == HFCUSB_D_TX) {
DBG(HFCUSB_DBG_STATES,
"HFC_USB: hfc_usb_d_l2l1 D-chan: PH_DEACTIVATE | REQUEST");
} else {
DBG(HFCUSB_DBG_STATES,
"HFC_USB: hfc_usb_d_l2l1 Bx-chan: PH_DEACTIVATE | REQUEST");
setup_bchannel(hfc,
(fifo->fifonum ==
HFCUSB_B1_TX) ? 0 : 1,
(int) L1_MODE_NULL);
fifo->hif->l1l2(fifo->hif,
PH_DEACTIVATE | INDICATION,
NULL);
}
break;
case PH_DATA | REQUEST:
if (fifo->skbuff && fifo->delete_flg) {
dev_kfree_skb_any(fifo->skbuff);
fifo->skbuff = NULL;
fifo->delete_flg = 0;
}
fifo->skbuff = arg;
break;
default:
DBG(HFCUSB_DBG_STATES,
"HFC_USB: hfc_usb_d_l2l1: unknown state : %#x", pr);
break;
}
}
static int
hfc_usb_init(hfcusb_data *hfc)
{
usb_fifo *fifo;
int i;
u_char b;
struct hisax_b_if *p_b_if[2];
if (read_usb(hfc, HFCUSB_CHIP_ID, &b) != 1) {
printk(KERN_INFO "HFC-USB: cannot read chip id\n");
return (1);
}
if (b != HFCUSB_CHIPID) {
printk(KERN_INFO "HFC-S USB: Invalid chip id 0x%02x\n", b);
return (1);
}
usb_set_interface(hfc->dev, hfc->if_used, hfc->alt_used);
write_usb(hfc, HFCUSB_CIRM, 8);
write_usb(hfc, HFCUSB_CIRM, 0x10);
write_usb(hfc, HFCUSB_USB_SIZE,
(hfc->packet_size / 8) | ((hfc->packet_size / 8) << 4));
write_usb(hfc, HFCUSB_USB_SIZE_I, hfc->iso_packet_size);
write_usb(hfc, HFCUSB_MST_MODE1, 0);
write_usb(hfc, HFCUSB_MST_MODE0, 1);
write_usb(hfc, HFCUSB_F_THRES,
(HFCUSB_TX_THRESHOLD /
8) | ((HFCUSB_RX_THRESHOLD / 8) << 4));
fifo = hfc->fifos;
for (i = 0; i < HFCUSB_NUM_FIFOS; i++) {
write_usb(hfc, HFCUSB_FIFO, i);
fifo[i].skbuff = NULL;
fifo[i].max_size =
(i <= HFCUSB_B2_RX) ? MAX_BCH_SIZE : MAX_DFRAME_LEN;
fifo[i].last_urblen = 0;
write_usb(hfc, HFCUSB_HDLC_PAR,
((i <= HFCUSB_B2_RX) ? 0 : 2));
write_usb(hfc, HFCUSB_CON_HDLC,
((i == HFCUSB_D_TX) ? 0x09 : 0x08));
write_usb(hfc, HFCUSB_INC_RES_F, 2);
}
write_usb(hfc, HFCUSB_CLKDEL, 0x0f);
write_usb(hfc, HFCUSB_STATES, 3 | 0x10);
write_usb(hfc, HFCUSB_STATES, 3);
write_usb(hfc, HFCUSB_SCTRL_R, 0);
write_usb(hfc, HFCUSB_SCTRL, 0x40);
hfc->b_mode[0] = L1_MODE_NULL;
hfc->b_mode[1] = L1_MODE_NULL;
hfc->l1_activated = 0;
hfc->disc_flag = 0;
hfc->led_state = 0;
hfc->old_led_state = 0;
init_timer(&hfc->t3_timer);
hfc->t3_timer.data = (long) hfc;
hfc->t3_timer.function = (void *) l1_timer_expire_t3;
init_timer(&hfc->t4_timer);
hfc->t4_timer.data = (long) hfc;
hfc->t4_timer.function = (void *) l1_timer_expire_t4;
hfc->ctrl_read.bRequestType = 0xc0;
hfc->ctrl_read.bRequest = 1;
hfc->ctrl_read.wLength = cpu_to_le16(1);
hfc->ctrl_write.bRequestType = 0x40;
hfc->ctrl_write.bRequest = 0;
hfc->ctrl_write.wLength = 0;
usb_fill_control_urb(hfc->ctrl_urb,
hfc->dev,
hfc->ctrl_out_pipe,
(u_char *)&hfc->ctrl_write,
NULL, 0, ctrl_complete, hfc);
for (i = 0; i < HFCUSB_NUM_FIFOS; i++) {
hfc->fifos[i].iso[0].purb = NULL;
hfc->fifos[i].iso[1].purb = NULL;
hfc->fifos[i].active = 0;
}
hfc->d_if.owner = THIS_MODULE;
hfc->d_if.ifc.priv = &hfc->fifos[HFCUSB_D_TX];
hfc->d_if.ifc.l2l1 = hfc_usb_l2l1;
for (i = 0; i < 2; i++) {
hfc->b_if[i].ifc.priv = &hfc->fifos[HFCUSB_B1_TX + i * 2];
hfc->b_if[i].ifc.l2l1 = hfc_usb_l2l1;
p_b_if[i] = &hfc->b_if[i];
}
hfc->protocol = 2;
i = hisax_register(&hfc->d_if, p_b_if, "hfc_usb", hfc->protocol);
if (i) {
printk(KERN_INFO "HFC-S USB: hisax_register -> %d\n", i);
return i;
}
#ifdef CONFIG_HISAX_DEBUG
hfc_debug = debug;
#endif
for (i = 0; i < 4; i++)
hfc->fifos[i].hif = &p_b_if[i / 2]->ifc;
for (i = 4; i < 8; i++)
hfc->fifos[i].hif = &hfc->d_if.ifc;
if (hfc->cfg_used == CNF_3INT3ISO || hfc->cfg_used == CNF_4INT3ISO) {
start_int_fifo(hfc->fifos + HFCUSB_D_RX);
if (hfc->fifos[HFCUSB_PCM_RX].pipe)
start_int_fifo(hfc->fifos + HFCUSB_PCM_RX);
start_int_fifo(hfc->fifos + HFCUSB_B1_RX);
start_int_fifo(hfc->fifos + HFCUSB_B2_RX);
}
if (hfc->cfg_used == CNF_3ISO3ISO || hfc->cfg_used == CNF_4ISO3ISO) {
start_isoc_chain(hfc->fifos + HFCUSB_D_RX, ISOC_PACKETS_D,
rx_iso_complete, 16);
if (hfc->fifos[HFCUSB_PCM_RX].pipe)
start_isoc_chain(hfc->fifos + HFCUSB_PCM_RX,
ISOC_PACKETS_D, rx_iso_complete,
16);
start_isoc_chain(hfc->fifos + HFCUSB_B1_RX, ISOC_PACKETS_B,
rx_iso_complete, 16);
start_isoc_chain(hfc->fifos + HFCUSB_B2_RX, ISOC_PACKETS_B,
rx_iso_complete, 16);
}
start_isoc_chain(hfc->fifos + HFCUSB_D_TX, ISOC_PACKETS_D,
tx_iso_complete, 1);
start_isoc_chain(hfc->fifos + HFCUSB_B1_TX, ISOC_PACKETS_B,
tx_iso_complete, 1);
start_isoc_chain(hfc->fifos + HFCUSB_B2_TX, ISOC_PACKETS_B,
tx_iso_complete, 1);
handle_led(hfc, LED_POWER_ON);
return (0);
}
static int
hfc_usb_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *dev = interface_to_usbdev(intf);
hfcusb_data *context;
struct usb_host_interface *iface = intf->cur_altsetting;
struct usb_host_interface *iface_used = NULL;
struct usb_host_endpoint *ep;
int ifnum = iface->desc.bInterfaceNumber;
int i, idx, alt_idx, probe_alt_setting, vend_idx, cfg_used, *vcf,
attr, cfg_found, cidx, ep_addr;
int cmptbl[16], small_match, iso_packet_size, packet_size,
alt_used = 0;
hfcsusb_vdata *driver_info;
vend_idx = 0xffff;
for (i = 0; hfcusb_idtab[i].idVendor; i++) {
if ((le16_to_cpu(dev->descriptor.idVendor) == hfcusb_idtab[i].idVendor)
&& (le16_to_cpu(dev->descriptor.idProduct) == hfcusb_idtab[i].idProduct)) {
vend_idx = i;
continue;
}
}
printk(KERN_INFO
"HFC-S USB: probing interface(%d) actalt(%d) minor(%d)\n",
ifnum, iface->desc.bAlternateSetting, intf->minor);
if (vend_idx != 0xffff) {
alt_idx = 0;
small_match = 0xffff;
iso_packet_size = 16;
packet_size = 64;
while (alt_idx < intf->num_altsetting) {
iface = intf->altsetting + alt_idx;
probe_alt_setting = iface->desc.bAlternateSetting;
cfg_used = 0;
while (validconf[cfg_used][0]) {
cfg_found = 1;
vcf = validconf[cfg_used];
ep = iface->endpoint;
memcpy(cmptbl, vcf, 16 * sizeof(int));
for (i = 0; i < iface->desc.bNumEndpoints;
i++) {
ep_addr =
ep->desc.bEndpointAddress;
idx = ((ep_addr & 0x7f) - 1) * 2;
if (ep_addr & 0x80)
idx++;
attr = ep->desc.bmAttributes;
if (cmptbl[idx] == EP_NUL) {
cfg_found = 0;
}
if (attr == USB_ENDPOINT_XFER_INT
&& cmptbl[idx] == EP_INT)
cmptbl[idx] = EP_NUL;
if (attr == USB_ENDPOINT_XFER_BULK
&& cmptbl[idx] == EP_BLK)
cmptbl[idx] = EP_NUL;
if (attr == USB_ENDPOINT_XFER_ISOC
&& cmptbl[idx] == EP_ISO)
cmptbl[idx] = EP_NUL;
if ((attr == USB_ENDPOINT_XFER_INT)
&& (ep->desc.bInterval < vcf[17])) {
cfg_found = 0;
}
ep++;
}
for (i = 0; i < 16; i++) {
if (cmptbl[i] != EP_NOP
&& cmptbl[i] != EP_NUL)
cfg_found = 0;
}
if (cfg_found) {
if (cfg_used < small_match) {
small_match = cfg_used;
alt_used =
probe_alt_setting;
iface_used = iface;
}
}
cfg_used++;
}
alt_idx++;
}
if (small_match != 0xffff) {
iface = iface_used;
if (!(context = kzalloc(sizeof(hfcusb_data), GFP_KERNEL)))
return (-ENOMEM);
ep = iface->endpoint;
vcf = validconf[small_match];
for (i = 0; i < iface->desc.bNumEndpoints; i++) {
ep_addr = ep->desc.bEndpointAddress;
idx = ((ep_addr & 0x7f) - 1) * 2;
if (ep_addr & 0x80)
idx++;
cidx = idx & 7;
attr = ep->desc.bmAttributes;
if (vcf[idx] != EP_NOP
&& vcf[idx] != EP_NUL) {
switch (attr) {
case USB_ENDPOINT_XFER_INT:
context->
fifos[cidx].
pipe =
usb_rcvintpipe
(dev,
ep->desc.
bEndpointAddress);
context->
fifos[cidx].
usb_transfer_mode
= USB_INT;
packet_size =
le16_to_cpu(ep->desc.wMaxPacketSize);
break;
case USB_ENDPOINT_XFER_BULK:
if (ep_addr & 0x80)
context->
fifos
[cidx].
pipe =
usb_rcvbulkpipe
(dev,
ep->
desc.
bEndpointAddress);
else
context->
fifos
[cidx].
pipe =
usb_sndbulkpipe
(dev,
ep->
desc.
bEndpointAddress);
context->
fifos[cidx].
usb_transfer_mode
= USB_BULK;
packet_size =
le16_to_cpu(ep->desc.wMaxPacketSize);
break;
case USB_ENDPOINT_XFER_ISOC:
if (ep_addr & 0x80)
context->
fifos
[cidx].
pipe =
usb_rcvisocpipe
(dev,
ep->
desc.
bEndpointAddress);
else
context->
fifos
[cidx].
pipe =
usb_sndisocpipe
(dev,
ep->
desc.
bEndpointAddress);
context->
fifos[cidx].
usb_transfer_mode
= USB_ISOC;
iso_packet_size =
le16_to_cpu(ep->desc.wMaxPacketSize);
break;
default:
context->
fifos[cidx].
pipe = 0;
}
if (context->fifos[cidx].pipe) {
context->fifos[cidx].
fifonum = cidx;
context->fifos[cidx].hfc =
context;
context->fifos[cidx].usb_packet_maxlen =
le16_to_cpu(ep->desc.wMaxPacketSize);
context->fifos[cidx].
intervall =
ep->desc.bInterval;
context->fifos[cidx].
skbuff = NULL;
}
}
ep++;
}
context->dev = dev;
context->if_used = ifnum;
context->alt_used = alt_used;
context->ctrl_paksize = dev->descriptor.bMaxPacketSize0;
context->cfg_used = vcf[16];
context->vend_idx = vend_idx;
context->packet_size = packet_size;
context->iso_packet_size = iso_packet_size;
context->ctrl_in_pipe =
usb_rcvctrlpipe(context->dev, 0);
context->ctrl_out_pipe =
usb_sndctrlpipe(context->dev, 0);
context->ctrl_urb = usb_alloc_urb(0, GFP_KERNEL);
driver_info =
(hfcsusb_vdata *) hfcusb_idtab[vend_idx].
driver_info;
printk(KERN_INFO "HFC-S USB: detected \"%s\"\n",
driver_info->vend_name);
DBG(HFCUSB_DBG_INIT,
"HFC-S USB: Endpoint-Config: %s (if=%d alt=%d), E-Channel(%d)",
conf_str[small_match], context->if_used,
context->alt_used,
validconf[small_match][18]);
if (hfc_usb_init(context)) {
usb_kill_urb(context->ctrl_urb);
usb_free_urb(context->ctrl_urb);
context->ctrl_urb = NULL;
kfree(context);
return (-EIO);
}
usb_set_intfdata(intf, context);
return (0);
}
} else {
printk(KERN_INFO
"HFC-S USB: no valid vendor found in USB descriptor\n");
}
return (-EIO);
}
static void
hfc_usb_disconnect(struct usb_interface *intf)
{
hfcusb_data *context = usb_get_intfdata(intf);
int i;
handle_led(context, LED_POWER_OFF);
schedule_timeout(HZ / 100);
printk(KERN_INFO "HFC-S USB: device disconnect\n");
context->disc_flag = 1;
usb_set_intfdata(intf, NULL);
if (timer_pending(&context->t3_timer))
del_timer(&context->t3_timer);
if (timer_pending(&context->t4_timer))
del_timer(&context->t4_timer);
for (i = 0; i < HFCUSB_NUM_FIFOS; i++) {
if (context->fifos[i].usb_transfer_mode == USB_ISOC) {
if (context->fifos[i].active > 0) {
stop_isoc_chain(&context->fifos[i]);
DBG(HFCUSB_DBG_INIT,
"HFC-S USB: %s stopping ISOC chain Fifo(%i)",
__func__, i);
}
} else {
if (context->fifos[i].active > 0) {
context->fifos[i].active = 0;
DBG(HFCUSB_DBG_INIT,
"HFC-S USB: %s unlinking URB for Fifo(%i)",
__func__, i);
}
usb_kill_urb(context->fifos[i].urb);
usb_free_urb(context->fifos[i].urb);
context->fifos[i].urb = NULL;
}
context->fifos[i].active = 0;
}
usb_kill_urb(context->ctrl_urb);
usb_free_urb(context->ctrl_urb);
context->ctrl_urb = NULL;
hisax_unregister(&context->d_if);
kfree(context);
}
static void __exit
hfc_usb_mod_exit(void)
{
usb_deregister(&hfc_drv);
printk(KERN_INFO "HFC-S USB: module removed\n");
}
static int __init
hfc_usb_mod_init(void)
{
char revstr[30], datestr[30], dummy[30];
#ifndef CONFIG_HISAX_DEBUG
hfc_debug = debug;
#endif
sscanf(hfcusb_revision,
"%s %s $ %s %s %s $ ", dummy, revstr,
dummy, datestr, dummy);
printk(KERN_INFO
"HFC-S USB: driver module revision %s date %s loaded, (debug=%i)\n",
revstr, datestr, debug);
if (usb_register(&hfc_drv)) {
printk(KERN_INFO
"HFC-S USB: Unable to register HFC-S USB module at usb stack\n");
return (-1);
}
return (0);
}
