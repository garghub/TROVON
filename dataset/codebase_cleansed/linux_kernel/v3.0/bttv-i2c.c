static void bttv_bit_setscl(void *data, int state)
{
struct bttv *btv = (struct bttv*)data;
if (state)
btv->i2c_state |= 0x02;
else
btv->i2c_state &= ~0x02;
btwrite(btv->i2c_state, BT848_I2C);
btread(BT848_I2C);
}
static void bttv_bit_setsda(void *data, int state)
{
struct bttv *btv = (struct bttv*)data;
if (state)
btv->i2c_state |= 0x01;
else
btv->i2c_state &= ~0x01;
btwrite(btv->i2c_state, BT848_I2C);
btread(BT848_I2C);
}
static int bttv_bit_getscl(void *data)
{
struct bttv *btv = (struct bttv*)data;
int state;
state = btread(BT848_I2C) & 0x02 ? 1 : 0;
return state;
}
static int bttv_bit_getsda(void *data)
{
struct bttv *btv = (struct bttv*)data;
int state;
state = btread(BT848_I2C) & 0x01;
return state;
}
static u32 functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_SMBUS_EMUL;
}
static int
bttv_i2c_wait_done(struct bttv *btv)
{
int rc = 0;
if (wait_event_interruptible_timeout(btv->i2c_queue,
btv->i2c_done, msecs_to_jiffies(85)) == -ERESTARTSYS)
rc = -EIO;
if (btv->i2c_done & BT848_INT_RACK)
rc = 1;
btv->i2c_done = 0;
return rc;
}
static int
bttv_i2c_sendbytes(struct bttv *btv, const struct i2c_msg *msg, int last)
{
u32 xmit;
int retval,cnt;
if (0 == msg->len)
return -EINVAL;
xmit = (msg->addr << 25) | (msg->buf[0] << 16) | I2C_HW;
if (msg->len > 1 || !last)
xmit |= BT878_I2C_NOSTOP;
btwrite(xmit, BT848_I2C);
retval = bttv_i2c_wait_done(btv);
if (retval < 0)
goto err;
if (retval == 0)
goto eio;
if (i2c_debug) {
printk(" <W %02x %02x", msg->addr << 1, msg->buf[0]);
if (!(xmit & BT878_I2C_NOSTOP))
printk(" >\n");
}
for (cnt = 1; cnt < msg->len; cnt++ ) {
xmit = (msg->buf[cnt] << 24) | I2C_HW | BT878_I2C_NOSTART;
if (cnt < msg->len-1 || !last)
xmit |= BT878_I2C_NOSTOP;
btwrite(xmit, BT848_I2C);
retval = bttv_i2c_wait_done(btv);
if (retval < 0)
goto err;
if (retval == 0)
goto eio;
if (i2c_debug) {
printk(" %02x", msg->buf[cnt]);
if (!(xmit & BT878_I2C_NOSTOP))
printk(" >\n");
}
}
return msg->len;
eio:
retval = -EIO;
err:
if (i2c_debug)
printk(" ERR: %d\n",retval);
return retval;
}
static int
bttv_i2c_readbytes(struct bttv *btv, const struct i2c_msg *msg, int last)
{
u32 xmit;
u32 cnt;
int retval;
for(cnt = 0; cnt < msg->len; cnt++) {
xmit = (msg->addr << 25) | (1 << 24) | I2C_HW;
if (cnt < msg->len-1)
xmit |= BT848_I2C_W3B;
if (cnt < msg->len-1 || !last)
xmit |= BT878_I2C_NOSTOP;
if (cnt)
xmit |= BT878_I2C_NOSTART;
btwrite(xmit, BT848_I2C);
retval = bttv_i2c_wait_done(btv);
if (retval < 0)
goto err;
if (retval == 0)
goto eio;
msg->buf[cnt] = ((u32)btread(BT848_I2C) >> 8) & 0xff;
if (i2c_debug) {
if (!(xmit & BT878_I2C_NOSTART))
printk(" <R %02x", (msg->addr << 1) +1);
printk(" =%02x", msg->buf[cnt]);
if (!(xmit & BT878_I2C_NOSTOP))
printk(" >\n");
}
}
return msg->len;
eio:
retval = -EIO;
err:
if (i2c_debug)
printk(" ERR: %d\n",retval);
return retval;
}
static int bttv_i2c_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs, int num)
{
struct v4l2_device *v4l2_dev = i2c_get_adapdata(i2c_adap);
struct bttv *btv = to_bttv(v4l2_dev);
int retval = 0;
int i;
if (i2c_debug)
printk("bt-i2c:");
btwrite(BT848_INT_I2CDONE|BT848_INT_RACK, BT848_INT_STAT);
for (i = 0 ; i < num; i++) {
if (msgs[i].flags & I2C_M_RD) {
retval = bttv_i2c_readbytes(btv, &msgs[i], i+1 == num);
if (retval < 0)
goto err;
} else {
retval = bttv_i2c_sendbytes(btv, &msgs[i], i+1 == num);
if (retval < 0)
goto err;
}
}
return num;
err:
return retval;
}
int bttv_I2CRead(struct bttv *btv, unsigned char addr, char *probe_for)
{
unsigned char buffer = 0;
if (0 != btv->i2c_rc)
return -1;
if (bttv_verbose && NULL != probe_for)
printk(KERN_INFO "bttv%d: i2c: checking for %s @ 0x%02x... ",
btv->c.nr,probe_for,addr);
btv->i2c_client.addr = addr >> 1;
if (1 != i2c_master_recv(&btv->i2c_client, &buffer, 1)) {
if (NULL != probe_for) {
if (bttv_verbose)
printk("not found\n");
} else
printk(KERN_WARNING "bttv%d: i2c read 0x%x: error\n",
btv->c.nr,addr);
return -1;
}
if (bttv_verbose && NULL != probe_for)
printk("found\n");
return buffer;
}
int bttv_I2CWrite(struct bttv *btv, unsigned char addr, unsigned char b1,
unsigned char b2, int both)
{
unsigned char buffer[2];
int bytes = both ? 2 : 1;
if (0 != btv->i2c_rc)
return -1;
btv->i2c_client.addr = addr >> 1;
buffer[0] = b1;
buffer[1] = b2;
if (bytes != i2c_master_send(&btv->i2c_client, buffer, bytes))
return -1;
return 0;
}
void __devinit bttv_readee(struct bttv *btv, unsigned char *eedata, int addr)
{
memset(eedata, 0, 256);
if (0 != btv->i2c_rc)
return;
btv->i2c_client.addr = addr >> 1;
tveeprom_read(&btv->i2c_client, eedata, 256);
}
static void do_i2c_scan(char *name, struct i2c_client *c)
{
unsigned char buf;
int i,rc;
for (i = 0; i < ARRAY_SIZE(i2c_devs); i++) {
c->addr = i;
rc = i2c_master_recv(c,&buf,0);
if (rc < 0)
continue;
printk("%s: i2c scan: found device @ 0x%x [%s]\n",
name, i << 1, i2c_devs[i] ? i2c_devs[i] : "???");
}
}
int __devinit init_bttv_i2c(struct bttv *btv)
{
strlcpy(btv->i2c_client.name, "bttv internal", I2C_NAME_SIZE);
if (i2c_hw)
btv->use_i2c_hw = 1;
if (btv->use_i2c_hw) {
strlcpy(btv->c.i2c_adap.name, "bt878",
sizeof(btv->c.i2c_adap.name));
btv->c.i2c_adap.algo = &bttv_algo;
} else {
if (i2c_udelay<5)
i2c_udelay=5;
strlcpy(btv->c.i2c_adap.name, "bttv",
sizeof(btv->c.i2c_adap.name));
memcpy(&btv->i2c_algo, &bttv_i2c_algo_bit_template,
sizeof(bttv_i2c_algo_bit_template));
btv->i2c_algo.udelay = i2c_udelay;
btv->i2c_algo.data = btv;
btv->c.i2c_adap.algo_data = &btv->i2c_algo;
}
btv->c.i2c_adap.owner = THIS_MODULE;
btv->c.i2c_adap.dev.parent = &btv->c.pci->dev;
snprintf(btv->c.i2c_adap.name, sizeof(btv->c.i2c_adap.name),
"bt%d #%d [%s]", btv->id, btv->c.nr,
btv->use_i2c_hw ? "hw" : "sw");
i2c_set_adapdata(&btv->c.i2c_adap, &btv->c.v4l2_dev);
btv->i2c_client.adapter = &btv->c.i2c_adap;
if (btv->use_i2c_hw) {
btv->i2c_rc = i2c_add_adapter(&btv->c.i2c_adap);
} else {
bttv_bit_setscl(btv,1);
bttv_bit_setsda(btv,1);
btv->i2c_rc = i2c_bit_add_bus(&btv->c.i2c_adap);
}
if (0 == btv->i2c_rc && i2c_scan)
do_i2c_scan(btv->c.v4l2_dev.name, &btv->i2c_client);
return btv->i2c_rc;
}
