static int ttusb_cmd(struct ttusb *ttusb,
const u8 * data, int len, int needresult)
{
int actual_len;
int err;
int i;
if (debug >= 3) {
printk(KERN_DEBUG ">");
for (i = 0; i < len; ++i)
printk(KERN_CONT " %02x", data[i]);
printk(KERN_CONT "\n");
}
if (mutex_lock_interruptible(&ttusb->semusb) < 0)
return -EAGAIN;
err = usb_bulk_msg(ttusb->dev, ttusb->bulk_out_pipe,
(u8 *) data, len, &actual_len, 1000);
if (err != 0) {
dprintk("%s: usb_bulk_msg(send) failed, err == %i!\n",
__func__, err);
mutex_unlock(&ttusb->semusb);
return err;
}
if (actual_len != len) {
dprintk("%s: only wrote %d of %d bytes\n", __func__,
actual_len, len);
mutex_unlock(&ttusb->semusb);
return -1;
}
err = usb_bulk_msg(ttusb->dev, ttusb->bulk_in_pipe,
ttusb->last_result, 32, &actual_len, 1000);
if (err != 0) {
printk("%s: failed, receive error %d\n", __func__,
err);
mutex_unlock(&ttusb->semusb);
return err;
}
if (debug >= 3) {
actual_len = ttusb->last_result[3] + 4;
printk(KERN_DEBUG "<");
for (i = 0; i < actual_len; ++i)
printk(KERN_CONT " %02x", ttusb->last_result[i]);
printk(KERN_CONT "\n");
}
if (!needresult)
mutex_unlock(&ttusb->semusb);
return 0;
}
static int ttusb_result(struct ttusb *ttusb, u8 * data, int len)
{
memcpy(data, ttusb->last_result, len);
mutex_unlock(&ttusb->semusb);
return 0;
}
static int ttusb_i2c_msg(struct ttusb *ttusb,
u8 addr, u8 * snd_buf, u8 snd_len, u8 * rcv_buf,
u8 rcv_len)
{
u8 b[0x28];
u8 id = ++ttusb->c;
int i, err;
if (snd_len > 0x28 - 7 || rcv_len > 0x20 - 7)
return -EINVAL;
b[0] = 0xaa;
b[1] = id;
b[2] = 0x31;
b[3] = snd_len + 3;
b[4] = addr << 1;
b[5] = snd_len;
b[6] = rcv_len;
for (i = 0; i < snd_len; i++)
b[7 + i] = snd_buf[i];
err = ttusb_cmd(ttusb, b, snd_len + 7, 1);
if (err)
return -EREMOTEIO;
err = ttusb_result(ttusb, b, 0x20);
if ((snd_len != b[5]) || (rcv_len != b[6])) return -EREMOTEIO;
if (rcv_len > 0) {
if (err || b[0] != 0x55 || b[1] != id) {
dprintk
("%s: usb_bulk_msg(recv) failed, err == %i, id == %02x, b == ",
__func__, err, id);
return -EREMOTEIO;
}
for (i = 0; i < rcv_len; i++)
rcv_buf[i] = b[7 + i];
}
return rcv_len;
}
static int master_xfer(struct i2c_adapter* adapter, struct i2c_msg *msg, int num)
{
struct ttusb *ttusb = i2c_get_adapdata(adapter);
int i = 0;
int inc;
if (mutex_lock_interruptible(&ttusb->semi2c) < 0)
return -EAGAIN;
while (i < num) {
u8 addr, snd_len, rcv_len, *snd_buf, *rcv_buf;
int err;
if (num > i + 1 && (msg[i + 1].flags & I2C_M_RD)) {
addr = msg[i].addr;
snd_buf = msg[i].buf;
snd_len = msg[i].len;
rcv_buf = msg[i + 1].buf;
rcv_len = msg[i + 1].len;
inc = 2;
} else {
addr = msg[i].addr;
snd_buf = msg[i].buf;
snd_len = msg[i].len;
rcv_buf = NULL;
rcv_len = 0;
inc = 1;
}
err = ttusb_i2c_msg(ttusb, addr,
snd_buf, snd_len, rcv_buf, rcv_len);
if (err < rcv_len) {
dprintk("%s: i == %i\n", __func__, i);
break;
}
i += inc;
}
mutex_unlock(&ttusb->semi2c);
return i;
}
static int ttusb_boot_dsp(struct ttusb *ttusb)
{
const struct firmware *fw;
int i, err;
u8 b[40];
err = request_firmware(&fw, "ttusb-budget/dspbootcode.bin",
&ttusb->dev->dev);
if (err) {
printk(KERN_ERR "ttusb-budget: failed to request firmware\n");
return err;
}
b[0] = 0xaa;
b[2] = 0x13;
b[3] = 28;
for (i = 0; i < fw->size; i += 28) {
memcpy(&b[4], &fw->data[i], 28);
b[1] = ++ttusb->c;
err = ttusb_cmd(ttusb, b, 32, 0);
if (err)
goto done;
}
b[1] = ++ttusb->c;
b[2] = 0x13;
b[3] = 0;
err = ttusb_cmd(ttusb, b, 4, 0);
if (err)
goto done;
b[1] = ++ttusb->c;
b[2] = 0x14;
b[3] = 0;
err = ttusb_cmd(ttusb, b, 4, 0);
done:
release_firmware(fw);
if (err) {
dprintk("%s: usb_bulk_msg() failed, return value %i!\n",
__func__, err);
}
return err;
}
static int ttusb_set_channel(struct ttusb *ttusb, int chan_id, int filter_type,
int pid)
{
int err;
u8 b[] = { 0xaa, ++ttusb->c, 0x22, 4, chan_id, filter_type,
(pid >> 8) & 0xff, pid & 0xff
};
err = ttusb_cmd(ttusb, b, sizeof(b), 0);
return err;
}
static int ttusb_del_channel(struct ttusb *ttusb, int channel_id)
{
int err;
u8 b[] = { 0xaa, ++ttusb->c, 0x23, 1, channel_id };
err = ttusb_cmd(ttusb, b, sizeof(b), 0);
return err;
}
static int ttusb_set_filter(struct ttusb *ttusb, int filter_id,
int associated_chan, u8 filter[8], u8 mask[8])
{
int err;
u8 b[] = { 0xaa, 0, 0x24, 0x1a, filter_id, associated_chan,
filter[0], filter[1], filter[2], filter[3],
filter[4], filter[5], filter[6], filter[7],
filter[8], filter[9], filter[10], filter[11],
mask[0], mask[1], mask[2], mask[3],
mask[4], mask[5], mask[6], mask[7],
mask[8], mask[9], mask[10], mask[11]
};
err = ttusb_cmd(ttusb, b, sizeof(b), 0);
return err;
}
static int ttusb_del_filter(struct ttusb *ttusb, int filter_id)
{
int err;
u8 b[] = { 0xaa, ++ttusb->c, 0x25, 1, filter_id };
err = ttusb_cmd(ttusb, b, sizeof(b), 0);
return err;
}
static int ttusb_init_controller(struct ttusb *ttusb)
{
u8 b0[] = { 0xaa, ++ttusb->c, 0x15, 1, 0 };
u8 b1[] = { 0xaa, ++ttusb->c, 0x15, 1, 1 };
u8 b2[] = { 0xaa, ++ttusb->c, 0x32, 1, 0 };
u8 b3[] =
{ 0xaa, ++ttusb->c, 0x31, 5, 0x10, 0x02, 0x01, 0x00, 0x1e };
u8 b4[] =
{ 0x55, ttusb->c, 0x31, 4, 0x10, 0x02, 0x01, 0x00, 0x1e };
u8 get_version[] = { 0xaa, ++ttusb->c, 0x17, 5, 0, 0, 0, 0, 0 };
u8 get_dsp_version[0x20] =
{ 0xaa, ++ttusb->c, 0x26, 28, 0, 0, 0, 0, 0 };
int err;
if ((err = ttusb_cmd(ttusb, b0, sizeof(b0), 0)))
return err;
if ((err = ttusb_cmd(ttusb, b1, sizeof(b1), 0)))
return err;
ttusb_boot_dsp(ttusb);
if ((err = ttusb_cmd(ttusb, b2, sizeof(b2), 0)))
return err;
if ((err = ttusb_cmd(ttusb, b3, sizeof(b3), 1)))
return err;
err = ttusb_result(ttusb, b4, sizeof(b4));
if ((err = ttusb_cmd(ttusb, get_version, sizeof(get_version), 1)))
return err;
if ((err = ttusb_result(ttusb, get_version, sizeof(get_version))))
return err;
dprintk("%s: stc-version: %c%c%c%c%c\n", __func__,
get_version[4], get_version[5], get_version[6],
get_version[7], get_version[8]);
if (memcmp(get_version + 4, "V 0.0", 5) &&
memcmp(get_version + 4, "V 1.1", 5) &&
memcmp(get_version + 4, "V 2.1", 5) &&
memcmp(get_version + 4, "V 2.2", 5)) {
printk
("%s: unknown STC version %c%c%c%c%c, please report!\n",
__func__, get_version[4], get_version[5],
get_version[6], get_version[7], get_version[8]);
}
ttusb->revision = ((get_version[6] - '0') << 4) |
(get_version[8] - '0');
err =
ttusb_cmd(ttusb, get_dsp_version, sizeof(get_dsp_version), 1);
if (err)
return err;
err =
ttusb_result(ttusb, get_dsp_version, sizeof(get_dsp_version));
if (err)
return err;
printk("%s: dsp-version: %c%c%c\n", __func__,
get_dsp_version[4], get_dsp_version[5], get_dsp_version[6]);
return 0;
}
static int ttusb_send_diseqc(struct dvb_frontend* fe,
const struct dvb_diseqc_master_cmd *cmd)
{
struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
u8 b[12] = { 0xaa, ++ttusb->c, 0x18 };
int err;
b[3] = 4 + 2 + cmd->msg_len;
b[4] = 0xFF;
b[5] = cmd->msg_len;
memcpy(b + 5, cmd->msg, cmd->msg_len);
if ((err = ttusb_cmd(ttusb, b, 4 + b[3], 0))) {
dprintk("%s: usb_bulk_msg() failed, return value %i!\n",
__func__, err);
}
return err;
}
static int ttusb_update_lnb(struct ttusb *ttusb)
{
u8 b[] = { 0xaa, ++ttusb->c, 0x16, 5, 1,
ttusb->voltage == SEC_VOLTAGE_18 ? 0 : 1,
ttusb->tone == SEC_TONE_ON ? 1 : 0, 1, 1
};
int err;
if ((err = ttusb_cmd(ttusb, b, sizeof(b), 0))) {
dprintk("%s: usb_bulk_msg() failed, return value %i!\n",
__func__, err);
}
return err;
}
static int ttusb_set_voltage(struct dvb_frontend *fe,
enum fe_sec_voltage voltage)
{
struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
ttusb->voltage = voltage;
return ttusb_update_lnb(ttusb);
}
static int ttusb_set_tone(struct dvb_frontend *fe, enum fe_sec_tone_mode tone)
{
struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
ttusb->tone = tone;
return ttusb_update_lnb(ttusb);
}
static void ttusb_process_muxpack(struct ttusb *ttusb, const u8 * muxpack,
int len)
{
u16 csum = 0, cc;
int i;
if (len < 4 || len & 0x1) {
pr_warn("%s: muxpack has invalid len %d\n", __func__, len);
numinvalid++;
return;
}
for (i = 0; i < len; i += 2)
csum ^= le16_to_cpup((__le16 *) (muxpack + i));
if (csum) {
printk("%s: muxpack with incorrect checksum, ignoring\n",
__func__);
numinvalid++;
return;
}
cc = (muxpack[len - 4] << 8) | muxpack[len - 3];
cc &= 0x7FFF;
if ((cc != ttusb->cc) && (ttusb->cc != -1))
printk("%s: cc discontinuity (%d frames missing)\n",
__func__, (cc - ttusb->cc) & 0x7FFF);
ttusb->cc = (cc + 1) & 0x7FFF;
if (muxpack[0] & 0x80) {
#ifdef TTUSB_HWSECTIONS
int pusi = muxpack[0] & 0x40;
int channel = muxpack[0] & 0x1F;
int payload = muxpack[1];
const u8 *data = muxpack + 2;
if (muxpack[0] & 0x20)
data++;
ttusb_handle_sec_data(ttusb->channel + channel, data,
payload);
data += payload;
if ((!!(ttusb->muxpack[0] & 0x20)) ^
!!(ttusb->muxpack[1] & 1))
data++;
#warning TODO: pusi
printk("cc: %04x\n", (data[0] << 8) | data[1]);
#endif
numsec++;
} else if (muxpack[0] == 0x47) {
#ifdef TTUSB_HWSECTIONS
int pid = ((muxpack[1] & 0x0F) << 8) | muxpack[2];
int channel;
for (channel = 0; channel < TTUSB_MAXCHANNEL; ++channel)
if (ttusb->channel[channel].active
&& (pid == ttusb->channel[channel].pid))
ttusb_handle_ts_data(ttusb->channel +
channel, muxpack,
188);
#endif
numts++;
dvb_dmx_swfilter_packets(&ttusb->dvb_demux, muxpack, 1);
} else if (muxpack[0] != 0) {
numinvalid++;
printk("illegal muxpack type %02x\n", muxpack[0]);
} else
numstuff++;
}
static void ttusb_process_frame(struct ttusb *ttusb, u8 * data, int len)
{
int maxwork = 1024;
while (len) {
if (!(maxwork--)) {
printk("%s: too much work\n", __func__);
break;
}
switch (ttusb->mux_state) {
case 0:
case 1:
case 2:
len--;
if (*data++ == 0xAA)
++ttusb->mux_state;
else {
ttusb->mux_state = 0;
if (ttusb->insync) {
dprintk("%s: %02x\n",
__func__, data[-1]);
printk(KERN_INFO "%s: lost sync.\n",
__func__);
ttusb->insync = 0;
}
}
break;
case 3:
ttusb->insync = 1;
len--;
ttusb->mux_npacks = *data++;
++ttusb->mux_state;
ttusb->muxpack_ptr = 0;
ttusb->muxpack_len = 2;
break;
case 4:
{
int avail;
avail = len;
if (avail >
(ttusb->muxpack_len -
ttusb->muxpack_ptr))
avail =
ttusb->muxpack_len -
ttusb->muxpack_ptr;
memcpy(ttusb->muxpack + ttusb->muxpack_ptr,
data, avail);
ttusb->muxpack_ptr += avail;
BUG_ON(ttusb->muxpack_ptr > 264);
data += avail;
len -= avail;
if (ttusb->muxpack_ptr == 2) {
if (ttusb->muxpack[0] & 0x80) {
ttusb->muxpack_len =
ttusb->muxpack[1] + 2;
if (ttusb->
muxpack[0] & 0x20)
ttusb->
muxpack_len++;
if ((!!
(ttusb->
muxpack[0] & 0x20)) ^
!!(ttusb->
muxpack[1] & 1))
ttusb->
muxpack_len++;
ttusb->muxpack_len += 4;
} else if (ttusb->muxpack[0] ==
0x47)
ttusb->muxpack_len =
188 + 4;
else if (ttusb->muxpack[0] == 0x00)
ttusb->muxpack_len =
ttusb->muxpack[1] + 2 +
4;
else {
dprintk
("%s: invalid state: first byte is %x\n",
__func__,
ttusb->muxpack[0]);
ttusb->mux_state = 0;
}
}
if ((ttusb->muxpack_ptr >= 2) &&
(ttusb->muxpack_ptr ==
ttusb->muxpack_len)) {
ttusb_process_muxpack(ttusb,
ttusb->
muxpack,
ttusb->
muxpack_ptr);
ttusb->muxpack_ptr = 0;
ttusb->muxpack_len = 2;
if (!ttusb->mux_npacks--) {
ttusb->mux_state = 0;
break;
}
}
break;
}
default:
BUG();
break;
}
}
}
static void ttusb_iso_irq(struct urb *urb)
{
struct ttusb *ttusb = urb->context;
struct usb_iso_packet_descriptor *d;
u8 *data;
int len, i;
if (!ttusb->iso_streaming)
return;
#if 0
printk("%s: status %d, errcount == %d, length == %i\n",
__func__,
urb->status, urb->error_count, urb->actual_length);
#endif
if (!urb->status) {
for (i = 0; i < urb->number_of_packets; ++i) {
numpkt++;
if (time_after_eq(jiffies, lastj + HZ)) {
dprintk("frames/s: %lu (ts: %d, stuff %d, sec: %d, invalid: %d, all: %d)\n",
numpkt * HZ / (jiffies - lastj),
numts, numstuff, numsec, numinvalid,
numts + numstuff + numsec + numinvalid);
numts = numstuff = numsec = numinvalid = 0;
lastj = jiffies;
numpkt = 0;
}
d = &urb->iso_frame_desc[i];
data = urb->transfer_buffer + d->offset;
len = d->actual_length;
d->actual_length = 0;
d->status = 0;
ttusb_process_frame(ttusb, data, len);
}
}
usb_submit_urb(urb, GFP_ATOMIC);
}
static void ttusb_free_iso_urbs(struct ttusb *ttusb)
{
int i;
for (i = 0; i < ISO_BUF_COUNT; i++)
usb_free_urb(ttusb->iso_urb[i]);
pci_free_consistent(NULL,
ISO_FRAME_SIZE * FRAMES_PER_ISO_BUF *
ISO_BUF_COUNT, ttusb->iso_buffer,
ttusb->iso_dma_handle);
}
static int ttusb_alloc_iso_urbs(struct ttusb *ttusb)
{
int i;
ttusb->iso_buffer = pci_zalloc_consistent(NULL,
ISO_FRAME_SIZE * FRAMES_PER_ISO_BUF * ISO_BUF_COUNT,
&ttusb->iso_dma_handle);
if (!ttusb->iso_buffer) {
dprintk("%s: pci_alloc_consistent - not enough memory\n",
__func__);
return -ENOMEM;
}
for (i = 0; i < ISO_BUF_COUNT; i++) {
struct urb *urb;
if (!
(urb =
usb_alloc_urb(FRAMES_PER_ISO_BUF, GFP_ATOMIC))) {
ttusb_free_iso_urbs(ttusb);
return -ENOMEM;
}
ttusb->iso_urb[i] = urb;
}
return 0;
}
static void ttusb_stop_iso_xfer(struct ttusb *ttusb)
{
int i;
for (i = 0; i < ISO_BUF_COUNT; i++)
usb_kill_urb(ttusb->iso_urb[i]);
ttusb->iso_streaming = 0;
}
static int ttusb_start_iso_xfer(struct ttusb *ttusb)
{
int i, j, err, buffer_offset = 0;
if (ttusb->iso_streaming) {
printk("%s: iso xfer already running!\n", __func__);
return 0;
}
ttusb->cc = -1;
ttusb->insync = 0;
ttusb->mux_state = 0;
for (i = 0; i < ISO_BUF_COUNT; i++) {
int frame_offset = 0;
struct urb *urb = ttusb->iso_urb[i];
urb->dev = ttusb->dev;
urb->context = ttusb;
urb->complete = ttusb_iso_irq;
urb->pipe = ttusb->isoc_in_pipe;
urb->transfer_flags = URB_ISO_ASAP;
urb->interval = 1;
urb->number_of_packets = FRAMES_PER_ISO_BUF;
urb->transfer_buffer_length =
ISO_FRAME_SIZE * FRAMES_PER_ISO_BUF;
urb->transfer_buffer = ttusb->iso_buffer + buffer_offset;
buffer_offset += ISO_FRAME_SIZE * FRAMES_PER_ISO_BUF;
for (j = 0; j < FRAMES_PER_ISO_BUF; j++) {
urb->iso_frame_desc[j].offset = frame_offset;
urb->iso_frame_desc[j].length = ISO_FRAME_SIZE;
frame_offset += ISO_FRAME_SIZE;
}
}
for (i = 0; i < ISO_BUF_COUNT; i++) {
if ((err = usb_submit_urb(ttusb->iso_urb[i], GFP_ATOMIC))) {
ttusb_stop_iso_xfer(ttusb);
printk
("%s: failed urb submission (%i: err = %i)!\n",
__func__, i, err);
return err;
}
}
ttusb->iso_streaming = 1;
return 0;
}
static void ttusb_handle_ts_data(struct dvb_demux_feed *dvbdmxfeed, const u8 * data,
int len)
{
dvbdmxfeed->cb.ts(data, len, 0, 0, &dvbdmxfeed->feed.ts, 0);
}
static void ttusb_handle_sec_data(struct dvb_demux_feed *dvbdmxfeed, const u8 * data,
int len)
{
#error TODO: handle ugly stuff
}
static int ttusb_start_feed(struct dvb_demux_feed *dvbdmxfeed)
{
struct ttusb *ttusb = (struct ttusb *) dvbdmxfeed->demux;
int feed_type = 1;
dprintk("ttusb_start_feed\n");
switch (dvbdmxfeed->type) {
case DMX_TYPE_TS:
break;
case DMX_TYPE_SEC:
break;
default:
return -EINVAL;
}
if (dvbdmxfeed->type == DMX_TYPE_TS) {
switch (dvbdmxfeed->pes_type) {
case DMX_PES_VIDEO:
case DMX_PES_AUDIO:
case DMX_PES_TELETEXT:
case DMX_PES_PCR:
case DMX_PES_OTHER:
break;
default:
return -EINVAL;
}
}
#ifdef TTUSB_HWSECTIONS
#error TODO: allocate filters
if (dvbdmxfeed->type == DMX_TYPE_TS) {
feed_type = 1;
} else if (dvbdmxfeed->type == DMX_TYPE_SEC) {
feed_type = 2;
}
#endif
ttusb_set_channel(ttusb, dvbdmxfeed->index, feed_type, dvbdmxfeed->pid);
if (0 == ttusb->running_feed_count++)
ttusb_start_iso_xfer(ttusb);
return 0;
}
static int ttusb_stop_feed(struct dvb_demux_feed *dvbdmxfeed)
{
struct ttusb *ttusb = (struct ttusb *) dvbdmxfeed->demux;
ttusb_del_channel(ttusb, dvbdmxfeed->index);
if (--ttusb->running_feed_count == 0)
ttusb_stop_iso_xfer(ttusb);
return 0;
}
static int ttusb_setup_interfaces(struct ttusb *ttusb)
{
usb_set_interface(ttusb->dev, 1, 1);
ttusb->bulk_out_pipe = usb_sndbulkpipe(ttusb->dev, 1);
ttusb->bulk_in_pipe = usb_rcvbulkpipe(ttusb->dev, 1);
ttusb->isoc_in_pipe = usb_rcvisocpipe(ttusb->dev, 2);
return 0;
}
static u32 functionality(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int alps_tdmb7_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
u8 data[4];
struct i2c_msg msg = {.addr=0x61, .flags=0, .buf=data, .len=sizeof(data) };
u32 div;
div = (p->frequency + 36166667) / 166667;
data[0] = (div >> 8) & 0x7f;
data[1] = div & 0xff;
data[2] = ((div >> 10) & 0x60) | 0x85;
data[3] = p->frequency < 592000000 ? 0x40 : 0x80;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&ttusb->i2c_adap, &msg, 1) != 1) return -EIO;
return 0;
}
static int philips_tdm1316l_tuner_init(struct dvb_frontend* fe)
{
struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
static u8 td1316_init[] = { 0x0b, 0xf5, 0x85, 0xab };
static u8 disable_mc44BC374c[] = { 0x1d, 0x74, 0xa0, 0x68 };
struct i2c_msg tuner_msg = { .addr=0x60, .flags=0, .buf=td1316_init, .len=sizeof(td1316_init) };
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&ttusb->i2c_adap, &tuner_msg, 1) != 1) return -EIO;
msleep(1);
tuner_msg.addr = 0x65;
tuner_msg.buf = disable_mc44BC374c;
tuner_msg.len = sizeof(disable_mc44BC374c);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&ttusb->i2c_adap, &tuner_msg, 1) != 1) {
i2c_transfer(&ttusb->i2c_adap, &tuner_msg, 1);
}
return 0;
}
static int philips_tdm1316l_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
u8 tuner_buf[4];
struct i2c_msg tuner_msg = {.addr=0x60, .flags=0, .buf=tuner_buf, .len=sizeof(tuner_buf) };
int tuner_frequency = 0;
u8 band, cp, filter;
tuner_frequency = p->frequency + 36130000;
if (tuner_frequency < 87000000) return -EINVAL;
else if (tuner_frequency < 130000000) cp = 3;
else if (tuner_frequency < 160000000) cp = 5;
else if (tuner_frequency < 200000000) cp = 6;
else if (tuner_frequency < 290000000) cp = 3;
else if (tuner_frequency < 420000000) cp = 5;
else if (tuner_frequency < 480000000) cp = 6;
else if (tuner_frequency < 620000000) cp = 3;
else if (tuner_frequency < 830000000) cp = 5;
else if (tuner_frequency < 895000000) cp = 7;
else return -EINVAL;
if (p->frequency < 49000000)
return -EINVAL;
else if (p->frequency < 159000000)
band = 1;
else if (p->frequency < 444000000)
band = 2;
else if (p->frequency < 861000000)
band = 4;
else return -EINVAL;
switch (p->bandwidth_hz) {
case 6000000:
tda1004x_writereg(fe, 0x0C, 0);
filter = 0;
break;
case 7000000:
tda1004x_writereg(fe, 0x0C, 0);
filter = 0;
break;
case 8000000:
tda1004x_writereg(fe, 0x0C, 0xFF);
filter = 1;
break;
default:
return -EINVAL;
}
tuner_frequency = (((p->frequency / 1000) * 6) + 217280) / 1000;
tuner_buf[0] = tuner_frequency >> 8;
tuner_buf[1] = tuner_frequency & 0xff;
tuner_buf[2] = 0xca;
tuner_buf[3] = (cp << 5) | (filter << 3) | band;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&ttusb->i2c_adap, &tuner_msg, 1) != 1)
return -EIO;
msleep(1);
return 0;
}
static int philips_tdm1316l_request_firmware(struct dvb_frontend* fe, const struct firmware **fw, char* name)
{
struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
return request_firmware(fw, name, &ttusb->dev->dev);
}
static int alps_stv0299_set_symbol_rate(struct dvb_frontend *fe, u32 srate, u32 ratio)
{
u8 aclk = 0;
u8 bclk = 0;
if (srate < 1500000) {
aclk = 0xb7;
bclk = 0x47;
} else if (srate < 3000000) {
aclk = 0xb7;
bclk = 0x4b;
} else if (srate < 7000000) {
aclk = 0xb7;
bclk = 0x4f;
} else if (srate < 14000000) {
aclk = 0xb7;
bclk = 0x53;
} else if (srate < 30000000) {
aclk = 0xb6;
bclk = 0x53;
} else if (srate < 45000000) {
aclk = 0xb4;
bclk = 0x51;
}
stv0299_writereg(fe, 0x13, aclk);
stv0299_writereg(fe, 0x14, bclk);
stv0299_writereg(fe, 0x1f, (ratio >> 16) & 0xff);
stv0299_writereg(fe, 0x20, (ratio >> 8) & 0xff);
stv0299_writereg(fe, 0x21, (ratio) & 0xf0);
return 0;
}
static int philips_tsa5059_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
u8 buf[4];
u32 div;
struct i2c_msg msg = {.addr = 0x61,.flags = 0,.buf = buf,.len = sizeof(buf) };
if ((p->frequency < 950000) || (p->frequency > 2150000))
return -EINVAL;
div = (p->frequency + (125 - 1)) / 125;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = 0x80 | ((div & 0x18000) >> 10) | 4;
buf[3] = 0xC4;
if (p->frequency > 1530000)
buf[3] = 0xC0;
if (ttusb->revision == TTUSB_REV_2_2)
buf[3] |= 0x20;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&ttusb->i2c_adap, &msg, 1) != 1)
return -EIO;
return 0;
}
static int ttusb_novas_grundig_29504_491_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct ttusb* ttusb = (struct ttusb*) fe->dvb->priv;
u8 buf[4];
u32 div;
struct i2c_msg msg = {.addr = 0x61,.flags = 0,.buf = buf,.len = sizeof(buf) };
div = p->frequency / 125;
buf[0] = (div >> 8) & 0x7f;
buf[1] = div & 0xff;
buf[2] = 0x8e;
buf[3] = 0x00;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&ttusb->i2c_adap, &msg, 1) != 1)
return -EIO;
return 0;
}
static int alps_tdbe2_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct ttusb* ttusb = fe->dvb->priv;
u32 div;
u8 data[4];
struct i2c_msg msg = { .addr = 0x62, .flags = 0, .buf = data, .len = sizeof(data) };
div = (p->frequency + 35937500 + 31250) / 62500;
data[0] = (div >> 8) & 0x7f;
data[1] = div & 0xff;
data[2] = 0x85 | ((div >> 10) & 0x60);
data[3] = (p->frequency < 174000000 ? 0x88 : p->frequency < 470000000 ? 0x84 : 0x81);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer (&ttusb->i2c_adap, &msg, 1) != 1)
return -EIO;
return 0;
}
static u8 read_pwm(struct ttusb* ttusb)
{
u8 b = 0xff;
u8 pwm;
struct i2c_msg msg[] = { { .addr = 0x50,.flags = 0,.buf = &b,.len = 1 },
{ .addr = 0x50,.flags = I2C_M_RD,.buf = &pwm,.len = 1} };
if ((i2c_transfer(&ttusb->i2c_adap, msg, 2) != 2) || (pwm == 0xff))
pwm = 0x48;
return pwm;
}
static int dvbc_philips_tdm1316l_tuner_set_params(struct dvb_frontend *fe)
{
struct dtv_frontend_properties *p = &fe->dtv_property_cache;
struct ttusb *ttusb = (struct ttusb *) fe->dvb->priv;
u8 tuner_buf[5];
struct i2c_msg tuner_msg = {.addr = 0x60,
.flags = 0,
.buf = tuner_buf,
.len = sizeof(tuner_buf) };
int tuner_frequency = 0;
u8 band, cp, filter;
tuner_frequency = p->frequency;
if (tuner_frequency < 87000000) {return -EINVAL;}
else if (tuner_frequency < 130000000) {cp = 3; band = 1;}
else if (tuner_frequency < 160000000) {cp = 5; band = 1;}
else if (tuner_frequency < 200000000) {cp = 6; band = 1;}
else if (tuner_frequency < 290000000) {cp = 3; band = 2;}
else if (tuner_frequency < 420000000) {cp = 5; band = 2;}
else if (tuner_frequency < 480000000) {cp = 6; band = 2;}
else if (tuner_frequency < 620000000) {cp = 3; band = 4;}
else if (tuner_frequency < 830000000) {cp = 5; band = 4;}
else if (tuner_frequency < 895000000) {cp = 7; band = 4;}
else {return -EINVAL;}
filter = 1;
tuner_frequency = ((p->frequency + 36125000) / 62500);
tuner_buf[0] = tuner_frequency >> 8;
tuner_buf[1] = tuner_frequency & 0xff;
tuner_buf[2] = 0xc8;
tuner_buf[3] = (cp << 5) | (filter << 3) | band;
tuner_buf[4] = 0x80;
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&ttusb->i2c_adap, &tuner_msg, 1) != 1) {
printk("dvb-ttusb-budget: dvbc_philips_tdm1316l_pll_set Error 1\n");
return -EIO;
}
msleep(50);
if (fe->ops.i2c_gate_ctrl)
fe->ops.i2c_gate_ctrl(fe, 1);
if (i2c_transfer(&ttusb->i2c_adap, &tuner_msg, 1) != 1) {
printk("dvb-ttusb-budget: dvbc_philips_tdm1316l_pll_set Error 2\n");
return -EIO;
}
msleep(1);
return 0;
}
static void frontend_init(struct ttusb* ttusb)
{
switch(le16_to_cpu(ttusb->dev->descriptor.idProduct)) {
case 0x1003:
ttusb->fe = dvb_attach(stv0299_attach, &alps_stv0299_config, &ttusb->i2c_adap);
if (ttusb->fe != NULL) {
ttusb->fe->ops.tuner_ops.set_params = philips_tsa5059_tuner_set_params;
if(ttusb->revision == TTUSB_REV_2_2) {
alps_stv0299_config.inittab = alps_bsbe1_inittab;
dvb_attach(lnbp21_attach, ttusb->fe, &ttusb->i2c_adap, 0, 0);
} else {
ttusb->fe->ops.set_voltage = ttusb_set_voltage;
}
break;
}
ttusb->fe = dvb_attach(tda8083_attach, &ttusb_novas_grundig_29504_491_config, &ttusb->i2c_adap);
if (ttusb->fe != NULL) {
ttusb->fe->ops.tuner_ops.set_params = ttusb_novas_grundig_29504_491_tuner_set_params;
ttusb->fe->ops.set_voltage = ttusb_set_voltage;
break;
}
break;
case 0x1004:
ttusb->fe = dvb_attach(ves1820_attach, &alps_tdbe2_config, &ttusb->i2c_adap, read_pwm(ttusb));
if (ttusb->fe != NULL) {
ttusb->fe->ops.tuner_ops.set_params = alps_tdbe2_tuner_set_params;
break;
}
ttusb->fe = dvb_attach(stv0297_attach, &dvbc_philips_tdm1316l_config, &ttusb->i2c_adap);
if (ttusb->fe != NULL) {
ttusb->fe->ops.tuner_ops.set_params = dvbc_philips_tdm1316l_tuner_set_params;
break;
}
break;
case 0x1005:
ttusb->fe = dvb_attach(cx22700_attach, &alps_tdmb7_config, &ttusb->i2c_adap);
if (ttusb->fe != NULL) {
ttusb->fe->ops.tuner_ops.set_params = alps_tdmb7_tuner_set_params;
break;
}
ttusb->fe = dvb_attach(tda10046_attach, &philips_tdm1316l_config, &ttusb->i2c_adap);
if (ttusb->fe != NULL) {
ttusb->fe->ops.tuner_ops.init = philips_tdm1316l_tuner_init;
ttusb->fe->ops.tuner_ops.set_params = philips_tdm1316l_tuner_set_params;
break;
}
break;
}
if (ttusb->fe == NULL) {
printk("dvb-ttusb-budget: A frontend driver was not found for device [%04x:%04x]\n",
le16_to_cpu(ttusb->dev->descriptor.idVendor),
le16_to_cpu(ttusb->dev->descriptor.idProduct));
} else {
if (dvb_register_frontend(&ttusb->adapter, ttusb->fe)) {
printk("dvb-ttusb-budget: Frontend registration failed!\n");
dvb_frontend_detach(ttusb->fe);
ttusb->fe = NULL;
}
}
}
static int ttusb_probe(struct usb_interface *intf, const struct usb_device_id *id)
{
struct usb_device *udev;
struct ttusb *ttusb;
int result;
dprintk("%s: TTUSB DVB connected\n", __func__);
udev = interface_to_usbdev(intf);
if (intf->altsetting->desc.bInterfaceNumber != 1) return -ENODEV;
if (!(ttusb = kzalloc(sizeof(struct ttusb), GFP_KERNEL)))
return -ENOMEM;
ttusb->dev = udev;
ttusb->c = 0;
ttusb->mux_state = 0;
mutex_init(&ttusb->semi2c);
mutex_lock(&ttusb->semi2c);
mutex_init(&ttusb->semusb);
ttusb_setup_interfaces(ttusb);
result = ttusb_alloc_iso_urbs(ttusb);
if (result < 0) {
dprintk("%s: ttusb_alloc_iso_urbs - failed\n", __func__);
mutex_unlock(&ttusb->semi2c);
kfree(ttusb);
return result;
}
if (ttusb_init_controller(ttusb))
printk("ttusb_init_controller: error\n");
mutex_unlock(&ttusb->semi2c);
result = dvb_register_adapter(&ttusb->adapter,
"Technotrend/Hauppauge Nova-USB",
THIS_MODULE, &udev->dev, adapter_nr);
if (result < 0) {
ttusb_free_iso_urbs(ttusb);
kfree(ttusb);
return result;
}
ttusb->adapter.priv = ttusb;
memset(&ttusb->i2c_adap, 0, sizeof(struct i2c_adapter));
strcpy(ttusb->i2c_adap.name, "TTUSB DEC");
i2c_set_adapdata(&ttusb->i2c_adap, ttusb);
ttusb->i2c_adap.algo = &ttusb_dec_algo;
ttusb->i2c_adap.algo_data = NULL;
ttusb->i2c_adap.dev.parent = &udev->dev;
result = i2c_add_adapter(&ttusb->i2c_adap);
if (result)
goto err_unregister_adapter;
memset(&ttusb->dvb_demux, 0, sizeof(ttusb->dvb_demux));
ttusb->dvb_demux.dmx.capabilities =
DMX_TS_FILTERING | DMX_SECTION_FILTERING;
ttusb->dvb_demux.priv = NULL;
#ifdef TTUSB_HWSECTIONS
ttusb->dvb_demux.filternum = TTUSB_MAXFILTER;
#else
ttusb->dvb_demux.filternum = 32;
#endif
ttusb->dvb_demux.feednum = TTUSB_MAXCHANNEL;
ttusb->dvb_demux.start_feed = ttusb_start_feed;
ttusb->dvb_demux.stop_feed = ttusb_stop_feed;
ttusb->dvb_demux.write_to_decoder = NULL;
result = dvb_dmx_init(&ttusb->dvb_demux);
if (result < 0) {
printk("ttusb_dvb: dvb_dmx_init failed (errno = %d)\n", result);
result = -ENODEV;
goto err_i2c_del_adapter;
}
ttusb->dmxdev.filternum = ttusb->dvb_demux.filternum;
ttusb->dmxdev.demux = &ttusb->dvb_demux.dmx;
ttusb->dmxdev.capabilities = 0;
result = dvb_dmxdev_init(&ttusb->dmxdev, &ttusb->adapter);
if (result < 0) {
printk("ttusb_dvb: dvb_dmxdev_init failed (errno = %d)\n",
result);
result = -ENODEV;
goto err_release_dmx;
}
if (dvb_net_init(&ttusb->adapter, &ttusb->dvbnet, &ttusb->dvb_demux.dmx)) {
printk("ttusb_dvb: dvb_net_init failed!\n");
result = -ENODEV;
goto err_release_dmxdev;
}
usb_set_intfdata(intf, (void *) ttusb);
frontend_init(ttusb);
return 0;
err_release_dmxdev:
dvb_dmxdev_release(&ttusb->dmxdev);
err_release_dmx:
dvb_dmx_release(&ttusb->dvb_demux);
err_i2c_del_adapter:
i2c_del_adapter(&ttusb->i2c_adap);
err_unregister_adapter:
dvb_unregister_adapter (&ttusb->adapter);
ttusb_free_iso_urbs(ttusb);
kfree(ttusb);
return result;
}
static void ttusb_disconnect(struct usb_interface *intf)
{
struct ttusb *ttusb = usb_get_intfdata(intf);
usb_set_intfdata(intf, NULL);
ttusb->disconnecting = 1;
ttusb_stop_iso_xfer(ttusb);
ttusb->dvb_demux.dmx.close(&ttusb->dvb_demux.dmx);
dvb_net_release(&ttusb->dvbnet);
dvb_dmxdev_release(&ttusb->dmxdev);
dvb_dmx_release(&ttusb->dvb_demux);
if (ttusb->fe != NULL) {
dvb_unregister_frontend(ttusb->fe);
dvb_frontend_detach(ttusb->fe);
}
i2c_del_adapter(&ttusb->i2c_adap);
dvb_unregister_adapter(&ttusb->adapter);
ttusb_free_iso_urbs(ttusb);
kfree(ttusb);
dprintk("%s: TTUSB DVB disconnected\n", __func__);
}
