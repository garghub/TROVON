static inline enum i2c_status i2c_get_status(struct saa7134_dev *dev)
{
enum i2c_status status;
status = saa_readb(SAA7134_I2C_ATTR_STATUS) & 0x0f;
d2printk(KERN_DEBUG "%s: i2c stat <= %s\n",dev->name,
str_i2c_status[status]);
return status;
}
static inline void i2c_set_status(struct saa7134_dev *dev,
enum i2c_status status)
{
d2printk(KERN_DEBUG "%s: i2c stat => %s\n",dev->name,
str_i2c_status[status]);
saa_andorb(SAA7134_I2C_ATTR_STATUS,0x0f,status);
}
static inline void i2c_set_attr(struct saa7134_dev *dev, enum i2c_attr attr)
{
d2printk(KERN_DEBUG "%s: i2c attr => %s\n",dev->name,
str_i2c_attr[attr]);
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
d2printk(KERN_DEBUG "%s: i2c reset\n",dev->name);
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
d2printk(KERN_DEBUG "%s: i2c data => 0x%x\n",dev->name,data);
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
d2printk(KERN_DEBUG "%s: i2c data <= 0x%x\n",dev->name,data);
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
d2printk("start xfer\n");
d1printk(KERN_DEBUG "%s: i2c xfer:",dev->name);
for (i = 0; i < num; i++) {
if (!(msgs[i].flags & I2C_M_NOSTART) || 0 == i) {
d2printk("send address\n");
addr = msgs[i].addr << 1;
if (msgs[i].flags & I2C_M_RD)
addr |= 1;
if (i > 0 && msgs[i].flags &
I2C_M_RD && msgs[i].addr != 0x40 &&
msgs[i].addr != 0x41 &&
msgs[i].addr != 0x19) {
int quirk = 0xfe;
d1printk(" [%02x quirk]",quirk);
i2c_send_byte(dev,START,quirk);
i2c_recv_byte(dev);
}
d1printk(" < %02x", addr);
rc = i2c_send_byte(dev,START,addr);
if (rc < 0)
goto err;
}
if (msgs[i].flags & I2C_M_RD) {
d2printk("read bytes\n");
for (byte = 0; byte < msgs[i].len; byte++) {
d1printk(" =");
rc = i2c_recv_byte(dev);
if (rc < 0)
goto err;
d1printk("%02x", rc);
msgs[i].buf[byte] = rc;
}
if (0x19 == msgs[i].addr) {
d1printk(" ?");
rc = i2c_recv_byte(dev);
if (rc < 0)
goto err;
d1printk("%02x", rc);
}
} else {
d2printk("write bytes\n");
for (byte = 0; byte < msgs[i].len; byte++) {
data = msgs[i].buf[byte];
d1printk(" %02x", data);
rc = i2c_send_byte(dev,CONTINUE,data);
if (rc < 0)
goto err;
}
}
}
d2printk("xfer done\n");
d1printk(" >");
i2c_set_attr(dev,STOP);
rc = -EIO;
if (!i2c_is_busy_wait(dev))
goto err;
status = i2c_get_status(dev);
if (i2c_is_error(status))
goto err;
msleep(1);
d1printk("\n");
return num;
err:
if (1 == i2c_debug) {
status = i2c_get_status(dev);
printk(" ERROR: %s\n",str_i2c_status[status]);
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
printk(KERN_INFO "%s: Huh, no eeprom present (err=%d)?\n",
dev->name,err);
return -1;
}
if (len != (err = i2c_master_recv(&dev->i2c_client,eedata,len))) {
printk(KERN_WARNING "%s: i2c eeprom read error (err=%d)\n",
dev->name,err);
return -1;
}
for (i = 0; i < len; i++) {
if (0 == (i % 16))
printk(KERN_INFO "%s: i2c eeprom %02x:",dev->name,i);
printk(" %02x",eedata[i]);
if (15 == (i % 16))
printk("\n");
}
return 0;
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
do_i2c_scan(dev->name,&dev->i2c_client);
saa7134_probe_i2c_ir(dev);
return 0;
}
int saa7134_i2c_unregister(struct saa7134_dev *dev)
{
i2c_del_adapter(&dev->i2c_adap);
return 0;
}
