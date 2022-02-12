static inline enum i2c_status i2c_get_status(struct saa7134_dev *dev)
{
enum i2c_status status;
status = saa_readb(SAA7134_I2C_ATTR_STATUS) & 0x0f;
i2c_dbg(2, "i2c stat <= %s\n", str_i2c_status[status]);
return status;
}
static inline void i2c_set_status(struct saa7134_dev *dev,
enum i2c_status status)
{
i2c_dbg(2, "i2c stat => %s\n", str_i2c_status[status]);
saa_andorb(SAA7134_I2C_ATTR_STATUS,0x0f,status);
}
static inline void i2c_set_attr(struct saa7134_dev *dev, enum i2c_attr attr)
{
i2c_dbg(2, "i2c attr => %s\n", str_i2c_attr[attr]);
saa_andorb(SAA7134_I2C_ATTR_STATUS,0xc0,attr << 6);
}
static inline int i2c_is_error(enum i2c_status status)
{
switch (status) {
case NO_DEVICE:
case NO_ACKN:
case BUS_ERR:
case ARB_LOST:
case SEQ_ERR:
case ST_ERR:
return true;
default:
return false;
}
}
static inline int i2c_is_idle(enum i2c_status status)
{
switch (status) {
case IDLE:
case DONE_STOP:
return true;
default:
return false;
}
}
static inline int i2c_is_busy(enum i2c_status status)
{
switch (status) {
case BUSY:
case TO_SCL:
case TO_ARB:
return true;
default:
return false;
}
}
static int i2c_is_busy_wait(struct saa7134_dev *dev)
{
enum i2c_status status;
int count;
for (count = 0; count < I2C_WAIT_RETRY; count++) {
status = i2c_get_status(dev);
if (!i2c_is_busy(status))
break;
saa_wait(I2C_WAIT_DELAY);
}
if (I2C_WAIT_RETRY == count)
return false;
return true;
}
static int i2c_reset(struct saa7134_dev *dev)
{
enum i2c_status status;
int count;
i2c_dbg(2, "i2c reset\n");
status = i2c_get_status(dev);
if (!i2c_is_error(status))
return true;
i2c_set_status(dev,status);
for (count = 0; count < I2C_WAIT_RETRY; count++) {
status = i2c_get_status(dev);
if (!i2c_is_error(status))
break;
udelay(I2C_WAIT_DELAY);
}
if (I2C_WAIT_RETRY == count)
return false;
if (!i2c_is_idle(status))
return false;
i2c_set_attr(dev,NOP);
return true;
}
static inline int i2c_send_byte(struct saa7134_dev *dev,
enum i2c_attr attr,
unsigned char data)
{
enum i2c_status status;
__u32 dword;
dword = saa_readl(SAA7134_I2C_ATTR_STATUS >> 2);
dword &= 0x0f;
dword |= (attr << 6);
dword |= ((__u32)data << 8);
dword |= 0x00 << 16;
dword |= 0xf0 << 24;
saa_writel(SAA7134_I2C_ATTR_STATUS >> 2, dword);
i2c_dbg(2, "i2c data => 0x%x\n", data);
if (!i2c_is_busy_wait(dev))
return -EIO;
status = i2c_get_status(dev);
if (i2c_is_error(status))
return -EIO;
return 0;
}
static inline int i2c_recv_byte(struct saa7134_dev *dev)
{
enum i2c_status status;
unsigned char data;
i2c_set_attr(dev,CONTINUE);
if (!i2c_is_busy_wait(dev))
return -EIO;
status = i2c_get_status(dev);
if (i2c_is_error(status))
return -EIO;
data = saa_readb(SAA7134_I2C_DATA);
i2c_dbg(2, "i2c data <= 0x%x\n", data);
return data;
}
static int saa7134_i2c_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg *msgs, int num)
{
struct saa7134_dev *dev = i2c_adap->algo_data;
enum i2c_status status;
unsigned char data;
int addr,rc,i,byte;
status = i2c_get_status(dev);
if (!i2c_is_idle(status))
if (!i2c_reset(dev))
return -EIO;
i2c_dbg(2, "start xfer\n");
i2c_dbg(1, "i2c xfer:");
for (i = 0; i < num; i++) {
if (!(msgs[i].flags & I2C_M_NOSTART) || 0 == i) {
i2c_dbg(2, "send address\n");
addr = msgs[i].addr << 1;
if (msgs[i].flags & I2C_M_RD)
addr |= 1;
if (i > 0 && msgs[i].flags &
I2C_M_RD && msgs[i].addr != 0x40 &&
msgs[i].addr != 0x41 &&
msgs[i].addr != 0x19) {
int quirk = 0xfe;
i2c_cont(1, " [%02x quirk]", quirk);
i2c_send_byte(dev,START,quirk);
i2c_recv_byte(dev);
}
i2c_cont(1, " < %02x", addr);
rc = i2c_send_byte(dev,START,addr);
if (rc < 0)
goto err;
}
if (msgs[i].flags & I2C_M_RD) {
i2c_dbg(2, "read bytes\n");
for (byte = 0; byte < msgs[i].len; byte++) {
i2c_cont(1, " =");
rc = i2c_recv_byte(dev);
if (rc < 0)
goto err;
i2c_cont(1, "%02x", rc);
msgs[i].buf[byte] = rc;
}
if (0x19 == msgs[i].addr) {
i2c_cont(1, " ?");
rc = i2c_recv_byte(dev);
if (rc < 0)
goto err;
i2c_cont(1, "%02x", rc);
}
} else {
i2c_dbg(2, "write bytes\n");
for (byte = 0; byte < msgs[i].len; byte++) {
data = msgs[i].buf[byte];
i2c_cont(1, " %02x", data);
rc = i2c_send_byte(dev,CONTINUE,data);
if (rc < 0)
goto err;
}
}
}
i2c_dbg(2, "xfer done\n");
i2c_cont(1, " >");
i2c_set_attr(dev,STOP);
rc = -EIO;
if (!i2c_is_busy_wait(dev))
goto err;
status = i2c_get_status(dev);
if (i2c_is_error(status))
goto err;
msleep(1);
i2c_cont(1, "\n");
return num;
err:
if (1 == i2c_debug) {
status = i2c_get_status(dev);
i2c_cont(1, " ERROR: %s\n", str_i2c_status[status]);
}
return rc;
}
static u32 functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_SMBUS_EMUL;
}
static int
saa7134_i2c_eeprom(struct saa7134_dev *dev, unsigned char *eedata, int len)
{
unsigned char buf;
int i,err;
dev->i2c_client.addr = 0xa0 >> 1;
buf = 0;
if (1 != (err = i2c_master_send(&dev->i2c_client,&buf,1))) {
pr_info("%s: Huh, no eeprom present (err=%d)?\n",
dev->name,err);
return -1;
}
if (len != (err = i2c_master_recv(&dev->i2c_client,eedata,len))) {
pr_warn("%s: i2c eeprom read error (err=%d)\n",
dev->name,err);
return -1;
}
for (i = 0; i < len; i += 16) {
int size = (len - i) > 16 ? 16 : len - i;
pr_info("i2c eeprom %02x: %*ph\n", i, size, &eedata[i]);
}
return 0;
}
static void do_i2c_scan(struct i2c_client *c)
{
unsigned char buf;
int i,rc;
for (i = 0; i < ARRAY_SIZE(i2c_devs); i++) {
c->addr = i;
rc = i2c_master_recv(c,&buf,0);
if (rc < 0)
continue;
pr_info("i2c scan: found device @ 0x%x [%s]\n",
i << 1, i2c_devs[i] ? i2c_devs[i] : "???");
}
}
int saa7134_i2c_register(struct saa7134_dev *dev)
{
dev->i2c_adap = saa7134_adap_template;
dev->i2c_adap.dev.parent = &dev->pci->dev;
strcpy(dev->i2c_adap.name,dev->name);
dev->i2c_adap.algo_data = dev;
i2c_set_adapdata(&dev->i2c_adap, &dev->v4l2_dev);
i2c_add_adapter(&dev->i2c_adap);
dev->i2c_client = saa7134_client_template;
dev->i2c_client.adapter = &dev->i2c_adap;
saa7134_i2c_eeprom(dev,dev->eedata,sizeof(dev->eedata));
if (i2c_scan)
do_i2c_scan(&dev->i2c_client);
saa7134_probe_i2c_ir(dev);
return 0;
}
int saa7134_i2c_unregister(struct saa7134_dev *dev)
{
i2c_del_adapter(&dev->i2c_adap);
return 0;
}
