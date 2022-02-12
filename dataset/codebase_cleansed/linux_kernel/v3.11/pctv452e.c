static int tt3650_ci_msg(struct dvb_usb_device *d, u8 cmd, u8 *data,
unsigned int write_len, unsigned int read_len)
{
struct pctv452e_state *state = (struct pctv452e_state *)d->priv;
u8 buf[64];
u8 id;
unsigned int rlen;
int ret;
BUG_ON(NULL == data && 0 != (write_len | read_len));
BUG_ON(write_len > 64 - 4);
BUG_ON(read_len > 64 - 4);
id = state->c++;
buf[0] = SYNC_BYTE_OUT;
buf[1] = id;
buf[2] = cmd;
buf[3] = write_len;
memcpy(buf + 4, data, write_len);
rlen = (read_len > 0) ? 64 : 0;
ret = dvb_usb_generic_rw(d, buf, 4 + write_len,
buf, rlen, 0);
if (0 != ret)
goto failed;
ret = -EIO;
if (SYNC_BYTE_IN != buf[0] || id != buf[1])
goto failed;
memcpy(data, buf + 4, read_len);
return 0;
failed:
err("CI error %d; %02X %02X %02X -> %*ph.",
ret, SYNC_BYTE_OUT, id, cmd, 3, buf);
return ret;
}
static int tt3650_ci_msg_locked(struct dvb_ca_en50221 *ca,
u8 cmd, u8 *data, unsigned int write_len,
unsigned int read_len)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct pctv452e_state *state = (struct pctv452e_state *)d->priv;
int ret;
mutex_lock(&state->ca_mutex);
ret = tt3650_ci_msg(d, cmd, data, write_len, read_len);
mutex_unlock(&state->ca_mutex);
return ret;
}
static int tt3650_ci_read_attribute_mem(struct dvb_ca_en50221 *ca,
int slot, int address)
{
u8 buf[3];
int ret;
if (0 != slot)
return -EINVAL;
buf[0] = (address >> 8) & 0x0F;
buf[1] = address;
ret = tt3650_ci_msg_locked(ca, TT3650_CMD_CI_RD_ATTR, buf, 2, 3);
ci_dbg("%s %04x -> %d 0x%02x",
__func__, address, ret, buf[2]);
if (ret < 0)
return ret;
return buf[2];
}
static int tt3650_ci_write_attribute_mem(struct dvb_ca_en50221 *ca,
int slot, int address, u8 value)
{
u8 buf[3];
ci_dbg("%s %d 0x%04x 0x%02x",
__func__, slot, address, value);
if (0 != slot)
return -EINVAL;
buf[0] = (address >> 8) & 0x0F;
buf[1] = address;
buf[2] = value;
return tt3650_ci_msg_locked(ca, TT3650_CMD_CI_WR_ATTR, buf, 3, 3);
}
static int tt3650_ci_read_cam_control(struct dvb_ca_en50221 *ca,
int slot,
u8 address)
{
u8 buf[2];
int ret;
if (0 != slot)
return -EINVAL;
buf[0] = address & 3;
ret = tt3650_ci_msg_locked(ca, TT3650_CMD_CI_RD_CTRL, buf, 1, 2);
ci_dbg("%s 0x%02x -> %d 0x%02x",
__func__, address, ret, buf[1]);
if (ret < 0)
return ret;
return buf[1];
}
static int tt3650_ci_write_cam_control(struct dvb_ca_en50221 *ca,
int slot,
u8 address,
u8 value)
{
u8 buf[2];
ci_dbg("%s %d 0x%02x 0x%02x",
__func__, slot, address, value);
if (0 != slot)
return -EINVAL;
buf[0] = address;
buf[1] = value;
return tt3650_ci_msg_locked(ca, TT3650_CMD_CI_WR_CTRL, buf, 2, 2);
}
static int tt3650_ci_set_video_port(struct dvb_ca_en50221 *ca,
int slot,
int enable)
{
u8 buf[1];
int ret;
ci_dbg("%s %d %d", __func__, slot, enable);
if (0 != slot)
return -EINVAL;
enable = !!enable;
buf[0] = enable;
ret = tt3650_ci_msg_locked(ca, TT3650_CMD_CI_SET_VIDEO_PORT, buf, 1, 1);
if (ret < 0)
return ret;
if (enable != buf[0]) {
err("CI not %sabled.", enable ? "en" : "dis");
return -EIO;
}
return 0;
}
static int tt3650_ci_slot_shutdown(struct dvb_ca_en50221 *ca, int slot)
{
return tt3650_ci_set_video_port(ca, slot, 0);
}
static int tt3650_ci_slot_ts_enable(struct dvb_ca_en50221 *ca, int slot)
{
return tt3650_ci_set_video_port(ca, slot, 1);
}
static int tt3650_ci_slot_reset(struct dvb_ca_en50221 *ca, int slot)
{
struct dvb_usb_device *d = (struct dvb_usb_device *)ca->data;
struct pctv452e_state *state = (struct pctv452e_state *)d->priv;
u8 buf[1];
int ret;
ci_dbg("%s %d", __func__, slot);
if (0 != slot)
return -EINVAL;
buf[0] = 0;
mutex_lock(&state->ca_mutex);
ret = tt3650_ci_msg(d, TT3650_CMD_CI_RESET, buf, 1, 1);
if (0 != ret)
goto failed;
msleep(500);
buf[0] = 1;
ret = tt3650_ci_msg(d, TT3650_CMD_CI_RESET, buf, 1, 1);
if (0 != ret)
goto failed;
msleep(500);
buf[0] = 0;
ret = tt3650_ci_msg(d, TT3650_CMD_CI_SET_VIDEO_PORT, buf, 1, 1);
failed:
mutex_unlock(&state->ca_mutex);
return ret;
}
static int tt3650_ci_poll_slot_status(struct dvb_ca_en50221 *ca,
int slot,
int open)
{
u8 buf[1];
int ret;
if (0 != slot)
return -EINVAL;
ret = tt3650_ci_msg_locked(ca, TT3650_CMD_CI_TEST, buf, 0, 1);
if (0 != ret)
return ret;
if (1 == buf[0])
return DVB_CA_EN50221_POLL_CAM_PRESENT |
DVB_CA_EN50221_POLL_CAM_READY;
return 0;
}
static void tt3650_ci_uninit(struct dvb_usb_device *d)
{
struct pctv452e_state *state;
ci_dbg("%s", __func__);
if (NULL == d)
return;
state = (struct pctv452e_state *)d->priv;
if (NULL == state)
return;
if (NULL == state->ca.data)
return;
tt3650_ci_set_video_port(&state->ca, 0, 0);
dvb_ca_en50221_release(&state->ca);
memset(&state->ca, 0, sizeof(state->ca));
}
static int tt3650_ci_init(struct dvb_usb_adapter *a)
{
struct dvb_usb_device *d = a->dev;
struct pctv452e_state *state = (struct pctv452e_state *)d->priv;
int ret;
ci_dbg("%s", __func__);
mutex_init(&state->ca_mutex);
state->ca.owner = THIS_MODULE;
state->ca.read_attribute_mem = tt3650_ci_read_attribute_mem;
state->ca.write_attribute_mem = tt3650_ci_write_attribute_mem;
state->ca.read_cam_control = tt3650_ci_read_cam_control;
state->ca.write_cam_control = tt3650_ci_write_cam_control;
state->ca.slot_reset = tt3650_ci_slot_reset;
state->ca.slot_shutdown = tt3650_ci_slot_shutdown;
state->ca.slot_ts_enable = tt3650_ci_slot_ts_enable;
state->ca.poll_slot_status = tt3650_ci_poll_slot_status;
state->ca.data = d;
ret = dvb_ca_en50221_init(&a->dvb_adap,
&state->ca,
0,
1);
if (0 != ret) {
err("Cannot initialize CI: Error %d.", ret);
memset(&state->ca, 0, sizeof(state->ca));
return ret;
}
info("CI initialized.");
return 0;
}
static int pctv452e_i2c_msg(struct dvb_usb_device *d, u8 addr,
const u8 *snd_buf, u8 snd_len,
u8 *rcv_buf, u8 rcv_len)
{
struct pctv452e_state *state = (struct pctv452e_state *)d->priv;
u8 buf[64];
u8 id;
int ret;
id = state->c++;
ret = -EINVAL;
if (snd_len > 64 - 7 || rcv_len > 64 - 7)
goto failed;
buf[0] = SYNC_BYTE_OUT;
buf[1] = id;
buf[2] = PCTV_CMD_I2C;
buf[3] = snd_len + 3;
buf[4] = addr << 1;
buf[5] = snd_len;
buf[6] = rcv_len;
memcpy(buf + 7, snd_buf, snd_len);
ret = dvb_usb_generic_rw(d, buf, 7 + snd_len,
buf, 64,
0);
if (ret < 0)
goto failed;
ret = -EIO;
if (SYNC_BYTE_IN != buf[0] || id != buf[1])
goto failed;
ret = -EREMOTEIO;
if (buf[5] < snd_len || buf[6] < rcv_len)
goto failed;
memcpy(rcv_buf, buf + 7, rcv_len);
return rcv_len;
failed:
err("I2C error %d; %02X %02X %02X %02X %02X -> "
"%02X %02X %02X %02X %02X.",
ret, SYNC_BYTE_OUT, id, addr << 1, snd_len, rcv_len,
buf[0], buf[1], buf[4], buf[5], buf[6]);
return ret;
}
static int pctv452e_i2c_xfer(struct i2c_adapter *adapter, struct i2c_msg *msg,
int num)
{
struct dvb_usb_device *d = i2c_get_adapdata(adapter);
int i;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
return -EAGAIN;
for (i = 0; i < num; i++) {
u8 addr, snd_len, rcv_len, *snd_buf, *rcv_buf;
int ret;
if (msg[i].flags & I2C_M_RD) {
addr = msg[i].addr;
snd_buf = NULL;
snd_len = 0;
rcv_buf = msg[i].buf;
rcv_len = msg[i].len;
} else {
addr = msg[i].addr;
snd_buf = msg[i].buf;
snd_len = msg[i].len;
rcv_buf = NULL;
rcv_len = 0;
}
ret = pctv452e_i2c_msg(d, addr, snd_buf, snd_len, rcv_buf,
rcv_len);
if (ret < rcv_len)
break;
}
mutex_unlock(&d->i2c_mutex);
return i;
}
static u32 pctv452e_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C;
}
static int pctv452e_power_ctrl(struct dvb_usb_device *d, int i)
{
struct pctv452e_state *state = (struct pctv452e_state *)d->priv;
u8 b0[] = { 0xaa, 0, PCTV_CMD_RESET, 1, 0 };
u8 rx[PCTV_ANSWER_LEN];
int ret;
info("%s: %d\n", __func__, i);
if (!i)
return 0;
if (state->initialized)
return 0;
ret = usb_set_interface(d->udev, 0, ISOC_INTERFACE_ALTERNATIVE);
if (ret != 0)
info("%s: Warning set interface returned: %d\n",
__func__, ret);
b0[1] = state->c++;
ret = dvb_usb_generic_rw(d, b0, sizeof(b0), rx, PCTV_ANSWER_LEN, 0);
if (ret)
return ret;
b0[1] = state->c++;
b0[4] = 1;
ret = dvb_usb_generic_rw(d, b0, sizeof(b0), rx, PCTV_ANSWER_LEN, 0);
if (ret)
return ret;
state->initialized = 1;
return 0;
}
static int pctv452e_rc_query(struct dvb_usb_device *d)
{
struct pctv452e_state *state = (struct pctv452e_state *)d->priv;
u8 b[CMD_BUFFER_SIZE];
u8 rx[PCTV_ANSWER_LEN];
int ret, i;
u8 id = state->c++;
b[0] = SYNC_BYTE_OUT;
b[1] = id;
b[2] = PCTV_CMD_IR;
b[3] = 0;
ret = dvb_usb_generic_rw(d, b, 4, rx, PCTV_ANSWER_LEN, 0);
if (ret != 0)
return ret;
if (debug > 3) {
info("%s: read: %2d: %*ph: ", __func__, ret, 3, rx);
for (i = 0; (i < rx[3]) && ((i+3) < PCTV_ANSWER_LEN); i++)
info(" %02x", rx[i+3]);
info("\n");
}
if ((rx[3] == 9) && (rx[12] & 0x01)) {
state->last_rc_key = (rx[7] << 8) | rx[6];
if (debug > 2)
info("%s: cmd=0x%02x sys=0x%02x\n",
__func__, rx[6], rx[7]);
rc_keydown(d->rc_dev, state->last_rc_key, 0);
} else if (state->last_rc_key) {
rc_keyup(d->rc_dev);
state->last_rc_key = 0;
}
return 0;
}
static int pctv452e_read_mac_address(struct dvb_usb_device *d, u8 mac[6])
{
const u8 mem_addr[] = { 0x1f, 0xcc };
u8 encoded_mac[20];
int ret;
ret = -EAGAIN;
if (mutex_lock_interruptible(&d->i2c_mutex) < 0)
goto failed;
ret = pctv452e_i2c_msg(d, I2C_ADDR_24C16,
mem_addr + 1, 1,
encoded_mac, 20);
if (-EREMOTEIO == ret)
ret = pctv452e_i2c_msg(d, I2C_ADDR_24C64,
mem_addr, 2,
encoded_mac, 20);
mutex_unlock(&d->i2c_mutex);
if (20 != ret)
goto failed;
ret = ttpci_eeprom_decode_mac(mac, encoded_mac);
if (0 != ret)
goto failed;
return 0;
failed:
memset(mac, 0, 6);
return ret;
}
static int pctv452e_frontend_attach(struct dvb_usb_adapter *a)
{
struct usb_device_id *id;
a->fe_adap[0].fe = dvb_attach(stb0899_attach, &stb0899_config,
&a->dev->i2c_adap);
if (!a->fe_adap[0].fe)
return -ENODEV;
if ((dvb_attach(lnbp22_attach, a->fe_adap[0].fe,
&a->dev->i2c_adap)) == 0)
err("Cannot attach lnbp22\n");
id = a->dev->desc->warm_ids[0];
if (USB_VID_TECHNOTREND == id->idVendor
&& USB_PID_TECHNOTREND_CONNECT_S2_3650_CI == id->idProduct)
tt3650_ci_init(a);
return 0;
}
static int pctv452e_tuner_attach(struct dvb_usb_adapter *a)
{
if (!a->fe_adap[0].fe)
return -ENODEV;
if (dvb_attach(stb6100_attach, a->fe_adap[0].fe, &stb6100_config,
&a->dev->i2c_adap) == 0) {
err("%s failed\n", __func__);
return -ENODEV;
}
return 0;
}
static void pctv452e_usb_disconnect(struct usb_interface *intf)
{
struct dvb_usb_device *d = usb_get_intfdata(intf);
tt3650_ci_uninit(d);
dvb_usb_device_exit(intf);
}
static int pctv452e_usb_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
if (0 == dvb_usb_device_init(intf, &pctv452e_properties,
THIS_MODULE, NULL, adapter_nr) ||
0 == dvb_usb_device_init(intf, &tt_connect_s2_3600_properties,
THIS_MODULE, NULL, adapter_nr))
return 0;
return -ENODEV;
}
