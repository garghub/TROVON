static int sp2_read_i2c(struct sp2 *s, u8 reg, u8 *buf, int len)
{
int ret;
struct i2c_client *client = s->client;
struct i2c_adapter *adap = client->adapter;
struct i2c_msg msg[] = {
{
.addr = client->addr,
.flags = 0,
.buf = &reg,
.len = 1
}, {
.addr = client->addr,
.flags = I2C_M_RD,
.buf = buf,
.len = len
}
};
ret = i2c_transfer(adap, msg, 2);
if (ret != 2) {
dev_err(&client->dev, "i2c read error, reg = 0x%02x, status = %d\n",
reg, ret);
if (ret < 0)
return ret;
else
return -EIO;
}
dev_dbg(&s->client->dev, "addr=0x%04x, reg = 0x%02x, data = %02x\n",
client->addr, reg, buf[0]);
return 0;
}
static int sp2_write_i2c(struct sp2 *s, u8 reg, u8 *buf, int len)
{
int ret;
u8 buffer[35];
struct i2c_client *client = s->client;
struct i2c_adapter *adap = client->adapter;
struct i2c_msg msg = {
.addr = client->addr,
.flags = 0,
.buf = &buffer[0],
.len = len + 1
};
if ((len + 1) > sizeof(buffer)) {
dev_err(&client->dev, "i2c wr reg=%02x: len=%d is too big!\n",
reg, len);
return -EINVAL;
}
buffer[0] = reg;
memcpy(&buffer[1], buf, len);
ret = i2c_transfer(adap, &msg, 1);
if (ret != 1) {
dev_err(&client->dev, "i2c write error, reg = 0x%02x, status = %d\n",
reg, ret);
if (ret < 0)
return ret;
else
return -EIO;
}
return 0;
}
static int sp2_ci_op_cam(struct dvb_ca_en50221 *en50221, int slot, u8 acs,
u8 read, int addr, u8 data)
{
struct sp2 *s = en50221->data;
u8 store;
int mem, ret;
int (*ci_op_cam)(void*, u8, int, u8, int*) = s->ci_control;
dev_dbg(&s->client->dev, "slot=%d, acs=0x%02x, addr=0x%04x, data = 0x%02x",
slot, acs, addr, data);
if (slot != 0)
return -EINVAL;
if (s->module_access_type != acs) {
ret = sp2_read_i2c(s, 0x00, &store, 1);
if (ret)
return ret;
store &= ~(SP2_MOD_CTL_ACS1 | SP2_MOD_CTL_ACS0);
store |= acs;
ret = sp2_write_i2c(s, 0x00, &store, 1);
if (ret)
return ret;
}
s->module_access_type = acs;
if (ci_op_cam) {
ret = ci_op_cam(s->priv, read, addr, data, &mem);
} else {
dev_err(&s->client->dev, "callback not defined");
return -EINVAL;
}
if (ret)
return ret;
if (read) {
dev_dbg(&s->client->dev, "cam read, addr=0x%04x, data = 0x%04x",
addr, mem);
return mem;
} else {
return 0;
}
}
int sp2_ci_read_attribute_mem(struct dvb_ca_en50221 *en50221,
int slot, int addr)
{
return sp2_ci_op_cam(en50221, slot, SP2_CI_ATTR_ACS,
SP2_CI_RD, addr, 0);
}
int sp2_ci_write_attribute_mem(struct dvb_ca_en50221 *en50221,
int slot, int addr, u8 data)
{
return sp2_ci_op_cam(en50221, slot, SP2_CI_ATTR_ACS,
SP2_CI_WR, addr, data);
}
int sp2_ci_read_cam_control(struct dvb_ca_en50221 *en50221,
int slot, u8 addr)
{
return sp2_ci_op_cam(en50221, slot, SP2_CI_IO_ACS,
SP2_CI_RD, addr, 0);
}
int sp2_ci_write_cam_control(struct dvb_ca_en50221 *en50221,
int slot, u8 addr, u8 data)
{
return sp2_ci_op_cam(en50221, slot, SP2_CI_IO_ACS,
SP2_CI_WR, addr, data);
}
int sp2_ci_slot_reset(struct dvb_ca_en50221 *en50221, int slot)
{
struct sp2 *s = en50221->data;
u8 buf;
int ret;
dev_dbg(&s->client->dev, "slot: %d\n", slot);
if (slot != 0)
return -EINVAL;
buf = SP2_MOD_CTL_RST;
ret = sp2_write_i2c(s, 0x00, &buf, 1);
if (ret)
return ret;
usleep_range(500, 600);
buf = 0x00;
ret = sp2_write_i2c(s, 0x00, &buf, 1);
if (ret)
return ret;
msleep(1000);
return 0;
}
int sp2_ci_slot_shutdown(struct dvb_ca_en50221 *en50221, int slot)
{
struct sp2 *s = en50221->data;
dev_dbg(&s->client->dev, "slot:%d\n", slot);
return 0;
}
int sp2_ci_slot_ts_enable(struct dvb_ca_en50221 *en50221, int slot)
{
struct sp2 *s = en50221->data;
u8 buf;
dev_dbg(&s->client->dev, "slot:%d\n", slot);
if (slot != 0)
return -EINVAL;
sp2_read_i2c(s, 0x00, &buf, 1);
buf |= (SP2_MOD_CTL_TSOEN | SP2_MOD_CTL_TSIEN);
return sp2_write_i2c(s, 0, &buf, 1);
}
int sp2_ci_poll_slot_status(struct dvb_ca_en50221 *en50221,
int slot, int open)
{
struct sp2 *s = en50221->data;
u8 buf[2];
int ret;
dev_dbg(&s->client->dev, "slot:%d open:%d\n", slot, open);
if (time_after(jiffies, s->next_status_checked_time)) {
ret = sp2_read_i2c(s, 0x00, buf, 1);
s->next_status_checked_time = jiffies + msecs_to_jiffies(1000);
if (ret)
return 0;
if (buf[0] & SP2_MOD_CTL_DET)
s->status = DVB_CA_EN50221_POLL_CAM_PRESENT |
DVB_CA_EN50221_POLL_CAM_READY;
else
s->status = 0;
}
return s->status;
}
static int sp2_init(struct sp2 *s)
{
int ret = 0;
u8 buf;
u8 cimax_init[34] = {
0x00,
0x00,
0x00,
0x00,
0x00,
0x44,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x44,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x02,
0x01,
0x00,
0x00,
0x00,
0x05,
0x00,
0x04,
0x00,
0x22,
0x00,
};
dev_dbg(&s->client->dev, "\n");
s->ca.owner = THIS_MODULE;
s->ca.read_attribute_mem = sp2_ci_read_attribute_mem;
s->ca.write_attribute_mem = sp2_ci_write_attribute_mem;
s->ca.read_cam_control = sp2_ci_read_cam_control;
s->ca.write_cam_control = sp2_ci_write_cam_control;
s->ca.slot_reset = sp2_ci_slot_reset;
s->ca.slot_shutdown = sp2_ci_slot_shutdown;
s->ca.slot_ts_enable = sp2_ci_slot_ts_enable;
s->ca.poll_slot_status = sp2_ci_poll_slot_status;
s->ca.data = s;
s->module_access_type = 0;
ret = sp2_write_i2c(s, 0x00, &cimax_init[0], 34);
if (ret)
goto err;
buf = 1;
ret = sp2_write_i2c(s, 0x1f, &buf, 1);
if (ret)
goto err;
ret = sp2_write_i2c(s, 0x18, &buf, 1);
if (ret)
goto err;
ret = dvb_ca_en50221_init(s->dvb_adap, &s->ca, 0, 1);
if (ret)
goto err;
return 0;
err:
dev_dbg(&s->client->dev, "init failed=%d\n", ret);
return ret;
}
static int sp2_exit(struct i2c_client *client)
{
struct sp2 *s;
dev_dbg(&client->dev, "\n");
if (client == NULL)
return 0;
s = i2c_get_clientdata(client);
if (s == NULL)
return 0;
if (s->ca.data == NULL)
return 0;
dvb_ca_en50221_release(&s->ca);
return 0;
}
static int sp2_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct sp2_config *cfg = client->dev.platform_data;
struct sp2 *s;
int ret;
dev_dbg(&client->dev, "\n");
s = kzalloc(sizeof(struct sp2), GFP_KERNEL);
if (!s) {
ret = -ENOMEM;
dev_err(&client->dev, "kzalloc() failed\n");
goto err;
}
s->client = client;
s->dvb_adap = cfg->dvb_adap;
s->priv = cfg->priv;
s->ci_control = cfg->ci_control;
i2c_set_clientdata(client, s);
ret = sp2_init(s);
if (ret)
goto err;
dev_info(&s->client->dev, "CIMaX SP2 successfully attached\n");
return 0;
err:
dev_dbg(&client->dev, "init failed=%d\n", ret);
kfree(s);
return ret;
}
static int sp2_remove(struct i2c_client *client)
{
struct si2157 *s = i2c_get_clientdata(client);
dev_dbg(&client->dev, "\n");
sp2_exit(client);
if (s != NULL)
kfree(s);
return 0;
}
