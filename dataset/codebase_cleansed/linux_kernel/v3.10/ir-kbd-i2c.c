static int get_key_haup_common(struct IR_i2c *ir, u32 *ir_key, u32 *ir_raw,
int size, int offset)
{
unsigned char buf[6];
int start, range, toggle, dev, code, ircode;
if (size != i2c_master_recv(ir->c, buf, size))
return -EIO;
start = (buf[offset] >> 7) & 1;
range = (buf[offset] >> 6) & 1;
toggle = (buf[offset] >> 5) & 1;
dev = buf[offset] & 0x1f;
code = (buf[offset+1] >> 2) & 0x3f;
if (!start)
return 0;
ircode= (start << 12) | (toggle << 11) | (dev << 6) | code;
if ((ircode & 0x1fff)==0x1fff)
return 0;
if (!range)
code += 64;
dprintk(1,"ir hauppauge (rc5): s%d r%d t%d dev=%d code=%d\n",
start, range, toggle, dev, code);
*ir_key = (dev << 8) | code;
*ir_raw = ircode;
return 1;
}
static int get_key_haup(struct IR_i2c *ir, u32 *ir_key, u32 *ir_raw)
{
return get_key_haup_common (ir, ir_key, ir_raw, 3, 0);
}
static int get_key_haup_xvr(struct IR_i2c *ir, u32 *ir_key, u32 *ir_raw)
{
int ret;
unsigned char buf[1] = { 0 };
ret = i2c_master_send(ir->c, buf, 1);
if (ret != 1)
return (ret < 0) ? ret : -EINVAL;
return get_key_haup_common (ir, ir_key, ir_raw, 6, 3);
}
static int get_key_pixelview(struct IR_i2c *ir, u32 *ir_key, u32 *ir_raw)
{
unsigned char b;
if (1 != i2c_master_recv(ir->c, &b, 1)) {
dprintk(1,"read error\n");
return -EIO;
}
*ir_key = b;
*ir_raw = b;
return 1;
}
static int get_key_fusionhdtv(struct IR_i2c *ir, u32 *ir_key, u32 *ir_raw)
{
unsigned char buf[4];
if (4 != i2c_master_recv(ir->c, buf, 4)) {
dprintk(1,"read error\n");
return -EIO;
}
if(buf[0] !=0 || buf[1] !=0 || buf[2] !=0 || buf[3] != 0)
dprintk(2, "%s: 0x%2x 0x%2x 0x%2x 0x%2x\n", __func__,
buf[0], buf[1], buf[2], buf[3]);
if(buf[0] != 0x1 || buf[1] != 0xfe)
return 0;
*ir_key = buf[2];
*ir_raw = (buf[2] << 8) | buf[3];
return 1;
}
static int get_key_knc1(struct IR_i2c *ir, u32 *ir_key, u32 *ir_raw)
{
unsigned char b;
if (1 != i2c_master_recv(ir->c, &b, 1)) {
dprintk(1,"read error\n");
return -EIO;
}
dprintk(2,"key %02x\n", b);
if (b == 0xff)
return 0;
if (b == 0xfe)
return 1;
*ir_key = b;
*ir_raw = b;
return 1;
}
static int get_key_avermedia_cardbus(struct IR_i2c *ir,
u32 *ir_key, u32 *ir_raw)
{
unsigned char subaddr, key, keygroup;
struct i2c_msg msg[] = { { .addr = ir->c->addr, .flags = 0,
.buf = &subaddr, .len = 1},
{ .addr = ir->c->addr, .flags = I2C_M_RD,
.buf = &key, .len = 1} };
subaddr = 0x0d;
if (2 != i2c_transfer(ir->c->adapter, msg, 2)) {
dprintk(1, "read error\n");
return -EIO;
}
if (key == 0xff)
return 0;
subaddr = 0x0b;
msg[1].buf = &keygroup;
if (2 != i2c_transfer(ir->c->adapter, msg, 2)) {
dprintk(1, "read error\n");
return -EIO;
}
if (keygroup == 0xff)
return 0;
dprintk(1, "read key 0x%02x/0x%02x\n", key, keygroup);
if (keygroup < 2 || keygroup > 4) {
dprintk(1, "warning: invalid key group 0x%02x for key 0x%02x\n",
keygroup, key);
}
key |= (keygroup & 1) << 6;
*ir_key = key;
*ir_raw = key;
if (!strcmp(ir->ir_codes, RC_MAP_AVERMEDIA_M733A_RM_K6)) {
*ir_key |= keygroup << 8;
*ir_raw |= keygroup << 8;
}
return 1;
}
static int ir_key_poll(struct IR_i2c *ir)
{
static u32 ir_key, ir_raw;
int rc;
dprintk(3, "%s\n", __func__);
rc = ir->get_key(ir, &ir_key, &ir_raw);
if (rc < 0) {
dprintk(2,"error\n");
return rc;
}
if (rc) {
dprintk(1, "%s: keycode = 0x%04x\n", __func__, ir_key);
rc_keydown(ir->rc, ir_key, 0);
}
return 0;
}
static void ir_work(struct work_struct *work)
{
int rc;
struct IR_i2c *ir = container_of(work, struct IR_i2c, work.work);
rc = ir_key_poll(ir);
if (rc == -ENODEV) {
rc_unregister_device(ir->rc);
ir->rc = NULL;
return;
}
schedule_delayed_work(&ir->work, msecs_to_jiffies(ir->polling_interval));
}
static int ir_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
char *ir_codes = NULL;
const char *name = NULL;
u64 rc_type = RC_BIT_UNKNOWN;
struct IR_i2c *ir;
struct rc_dev *rc = NULL;
struct i2c_adapter *adap = client->adapter;
unsigned short addr = client->addr;
int err;
ir = kzalloc(sizeof(struct IR_i2c), GFP_KERNEL);
if (!ir)
return -ENOMEM;
ir->c = client;
ir->polling_interval = DEFAULT_POLLING_INTERVAL;
i2c_set_clientdata(client, ir);
switch(addr) {
case 0x64:
name = "Pixelview";
ir->get_key = get_key_pixelview;
rc_type = RC_BIT_OTHER;
ir_codes = RC_MAP_EMPTY;
break;
case 0x18:
case 0x1f:
case 0x1a:
name = "Hauppauge";
ir->get_key = get_key_haup;
rc_type = RC_BIT_RC5;
ir_codes = RC_MAP_HAUPPAUGE;
break;
case 0x30:
name = "KNC One";
ir->get_key = get_key_knc1;
rc_type = RC_BIT_OTHER;
ir_codes = RC_MAP_EMPTY;
break;
case 0x6b:
name = "FusionHDTV";
ir->get_key = get_key_fusionhdtv;
rc_type = RC_BIT_RC5;
ir_codes = RC_MAP_FUSIONHDTV_MCE;
break;
case 0x40:
name = "AVerMedia Cardbus remote";
ir->get_key = get_key_avermedia_cardbus;
rc_type = RC_BIT_OTHER;
ir_codes = RC_MAP_AVERMEDIA_CARDBUS;
break;
case 0x41:
name = "AVerMedia EM78P153";
ir->get_key = get_key_avermedia_cardbus;
rc_type = RC_BIT_OTHER;
ir_codes = RC_MAP_AVERMEDIA_M733A_RM_K6;
break;
case 0x71:
name = "Hauppauge/Zilog Z8";
ir->get_key = get_key_haup_xvr;
rc_type = RC_BIT_RC5;
ir_codes = RC_MAP_HAUPPAUGE;
break;
}
if (client->dev.platform_data) {
const struct IR_i2c_init_data *init_data =
client->dev.platform_data;
ir_codes = init_data->ir_codes;
rc = init_data->rc_dev;
name = init_data->name;
if (init_data->type)
rc_type = init_data->type;
if (init_data->polling_interval)
ir->polling_interval = init_data->polling_interval;
switch (init_data->internal_get_key_func) {
case IR_KBD_GET_KEY_CUSTOM:
ir->get_key = init_data->get_key;
break;
case IR_KBD_GET_KEY_PIXELVIEW:
ir->get_key = get_key_pixelview;
break;
case IR_KBD_GET_KEY_HAUP:
ir->get_key = get_key_haup;
break;
case IR_KBD_GET_KEY_KNC1:
ir->get_key = get_key_knc1;
break;
case IR_KBD_GET_KEY_FUSIONHDTV:
ir->get_key = get_key_fusionhdtv;
break;
case IR_KBD_GET_KEY_HAUP_XVR:
ir->get_key = get_key_haup_xvr;
break;
case IR_KBD_GET_KEY_AVERMEDIA_CARDBUS:
ir->get_key = get_key_avermedia_cardbus;
break;
}
}
if (!rc) {
rc = rc_allocate_device();
if (!rc) {
err = -ENOMEM;
goto err_out_free;
}
}
ir->rc = rc;
if (!name || !ir->get_key || !rc_type || !ir_codes) {
dprintk(1, ": Unsupported device at address 0x%02x\n",
addr);
err = -ENODEV;
goto err_out_free;
}
snprintf(ir->name, sizeof(ir->name), "i2c IR (%s)", name);
ir->ir_codes = ir_codes;
snprintf(ir->phys, sizeof(ir->phys), "%s/%s/ir0",
dev_name(&adap->dev),
dev_name(&client->dev));
rc->input_id.bustype = BUS_I2C;
rc->input_phys = ir->phys;
rc->input_name = ir->name;
rc->map_name = ir->ir_codes;
rc->allowed_protos = rc_type;
rc->enabled_protocols = rc_type;
if (!rc->driver_name)
rc->driver_name = MODULE_NAME;
err = rc_register_device(rc);
if (err)
goto err_out_free;
printk(MODULE_NAME ": %s detected at %s [%s]\n",
ir->name, ir->phys, adap->name);
INIT_DELAYED_WORK(&ir->work, ir_work);
schedule_delayed_work(&ir->work, 0);
return 0;
err_out_free:
rc_free_device(rc);
kfree(ir);
return err;
}
static int ir_remove(struct i2c_client *client)
{
struct IR_i2c *ir = i2c_get_clientdata(client);
cancel_delayed_work_sync(&ir->work);
if (ir->rc)
rc_unregister_device(ir->rc);
kfree(ir);
return 0;
}
