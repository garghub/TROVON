static void i2c_start(struct i2c_algo_pcf_data *adap)
{
DEBPROTO(printk(KERN_DEBUG "S "));
set_pcf(adap, 1, I2C_PCF_START);
}
static void i2c_repstart(struct i2c_algo_pcf_data *adap)
{
DEBPROTO(printk(" Sr "));
set_pcf(adap, 1, I2C_PCF_REPSTART);
}
static void i2c_stop(struct i2c_algo_pcf_data *adap)
{
DEBPROTO(printk("P\n"));
set_pcf(adap, 1, I2C_PCF_STOP);
}
static void handle_lab(struct i2c_algo_pcf_data *adap, const int *status)
{
DEB2(printk(KERN_INFO
"i2c-algo-pcf.o: lost arbitration (CSR 0x%02x)\n",
*status));
set_pcf(adap, 1, I2C_PCF_PIN);
set_pcf(adap, 1, I2C_PCF_ESO);
if (adap->lab_mdelay)
mdelay(adap->lab_mdelay);
DEB2(printk(KERN_INFO
"i2c-algo-pcf.o: reset LAB condition (CSR 0x%02x)\n",
get_pcf(adap, 1)));
}
static int wait_for_bb(struct i2c_algo_pcf_data *adap)
{
int timeout = DEF_TIMEOUT;
int status;
status = get_pcf(adap, 1);
while (!(status & I2C_PCF_BB) && --timeout) {
udelay(100);
status = get_pcf(adap, 1);
}
if (timeout == 0) {
printk(KERN_ERR "Timeout waiting for Bus Busy\n");
return -ETIMEDOUT;
}
return 0;
}
static int wait_for_pin(struct i2c_algo_pcf_data *adap, int *status)
{
int timeout = DEF_TIMEOUT;
*status = get_pcf(adap, 1);
while ((*status & I2C_PCF_PIN) && --timeout) {
adap->waitforpin(adap->data);
*status = get_pcf(adap, 1);
}
if (*status & I2C_PCF_LAB) {
handle_lab(adap, status);
return -EINTR;
}
if (timeout == 0)
return -ETIMEDOUT;
return 0;
}
static int pcf_init_8584 (struct i2c_algo_pcf_data *adap)
{
unsigned char temp;
DEB3(printk(KERN_DEBUG "i2c-algo-pcf.o: PCF state 0x%02x\n",
get_pcf(adap, 1)));
set_pcf(adap, 1, I2C_PCF_PIN);
if (((temp = get_pcf(adap, 1)) & 0x7f) != (0)) {
DEB2(printk(KERN_ERR "i2c-algo-pcf.o: PCF detection failed -- can't select S0 (0x%02x).\n", temp));
return -ENXIO;
}
i2c_outb(adap, get_own(adap));
if ((temp = i2c_inb(adap)) != get_own(adap)) {
DEB2(printk(KERN_ERR "i2c-algo-pcf.o: PCF detection failed -- can't set S0 (0x%02x).\n", temp));
return -ENXIO;
}
set_pcf(adap, 1, I2C_PCF_PIN | I2C_PCF_ES1);
if (((temp = get_pcf(adap, 1)) & 0x7f) != I2C_PCF_ES1) {
DEB2(printk(KERN_ERR "i2c-algo-pcf.o: PCF detection failed -- can't select S2 (0x%02x).\n", temp));
return -ENXIO;
}
i2c_outb(adap, get_clock(adap));
if (((temp = i2c_inb(adap)) & 0x1f) != get_clock(adap)) {
DEB2(printk(KERN_ERR "i2c-algo-pcf.o: PCF detection failed -- can't set S2 (0x%02x).\n", temp));
return -ENXIO;
}
set_pcf(adap, 1, I2C_PCF_IDLE);
if ((temp = get_pcf(adap, 1)) != (I2C_PCF_PIN | I2C_PCF_BB)) {
DEB2(printk(KERN_ERR "i2c-algo-pcf.o: PCF detection failed -- can't select S1` (0x%02x).\n", temp));
return -ENXIO;
}
printk(KERN_DEBUG "i2c-algo-pcf.o: detected and initialized PCF8584.\n");
return 0;
}
static int pcf_sendbytes(struct i2c_adapter *i2c_adap, const char *buf,
int count, int last)
{
struct i2c_algo_pcf_data *adap = i2c_adap->algo_data;
int wrcount, status, timeout;
for (wrcount=0; wrcount<count; ++wrcount) {
DEB2(dev_dbg(&i2c_adap->dev, "i2c_write: writing %2.2X\n",
buf[wrcount] & 0xff));
i2c_outb(adap, buf[wrcount]);
timeout = wait_for_pin(adap, &status);
if (timeout) {
if (timeout == -EINTR)
return -EINTR;
i2c_stop(adap);
dev_err(&i2c_adap->dev, "i2c_write: error - timeout.\n");
return -EREMOTEIO;
}
if (status & I2C_PCF_LRB) {
i2c_stop(adap);
dev_err(&i2c_adap->dev, "i2c_write: error - no ack.\n");
return -EREMOTEIO;
}
}
if (last)
i2c_stop(adap);
else
i2c_repstart(adap);
return wrcount;
}
static int pcf_readbytes(struct i2c_adapter *i2c_adap, char *buf,
int count, int last)
{
int i, status;
struct i2c_algo_pcf_data *adap = i2c_adap->algo_data;
int wfp;
for (i = 0; i <= count; i++) {
if ((wfp = wait_for_pin(adap, &status))) {
if (wfp == -EINTR)
return -EINTR;
i2c_stop(adap);
dev_err(&i2c_adap->dev, "pcf_readbytes timed out.\n");
return -1;
}
if ((status & I2C_PCF_LRB) && (i != count)) {
i2c_stop(adap);
dev_err(&i2c_adap->dev, "i2c_read: i2c_inb, No ack.\n");
return -1;
}
if (i == count - 1) {
set_pcf(adap, 1, I2C_PCF_ESO);
} else if (i == count) {
if (last)
i2c_stop(adap);
else
i2c_repstart(adap);
}
if (i)
buf[i - 1] = i2c_inb(adap);
else
i2c_inb(adap);
}
return i - 1;
}
static int pcf_doAddress(struct i2c_algo_pcf_data *adap,
struct i2c_msg *msg)
{
unsigned short flags = msg->flags;
unsigned char addr;
addr = msg->addr << 1;
if (flags & I2C_M_RD)
addr |= 1;
if (flags & I2C_M_REV_DIR_ADDR)
addr ^= 1;
i2c_outb(adap, addr);
return 0;
}
static int pcf_xfer(struct i2c_adapter *i2c_adap,
struct i2c_msg *msgs,
int num)
{
struct i2c_algo_pcf_data *adap = i2c_adap->algo_data;
struct i2c_msg *pmsg;
int i;
int ret=0, timeout, status;
if (adap->xfer_begin)
adap->xfer_begin(adap->data);
timeout = wait_for_bb(adap);
if (timeout) {
DEB2(printk(KERN_ERR "i2c-algo-pcf.o: "
"Timeout waiting for BB in pcf_xfer\n");)
i = -EIO;
goto out;
}
for (i = 0;ret >= 0 && i < num; i++) {
pmsg = &msgs[i];
DEB2(printk(KERN_DEBUG "i2c-algo-pcf.o: Doing %s %d bytes to 0x%02x - %d of %d messages\n",
pmsg->flags & I2C_M_RD ? "read" : "write",
pmsg->len, pmsg->addr, i + 1, num);)
ret = pcf_doAddress(adap, pmsg);
if (i == 0)
i2c_start(adap);
timeout = wait_for_pin(adap, &status);
if (timeout) {
if (timeout == -EINTR) {
i = -EINTR;
goto out;
}
i2c_stop(adap);
DEB2(printk(KERN_ERR "i2c-algo-pcf.o: Timeout waiting "
"for PIN(1) in pcf_xfer\n");)
i = -EREMOTEIO;
goto out;
}
if (status & I2C_PCF_LRB) {
i2c_stop(adap);
DEB2(printk(KERN_ERR "i2c-algo-pcf.o: No LRB(1) in pcf_xfer\n");)
i = -EREMOTEIO;
goto out;
}
DEB3(printk(KERN_DEBUG "i2c-algo-pcf.o: Msg %d, addr=0x%x, flags=0x%x, len=%d\n",
i, msgs[i].addr, msgs[i].flags, msgs[i].len);)
if (pmsg->flags & I2C_M_RD) {
ret = pcf_readbytes(i2c_adap, pmsg->buf, pmsg->len,
(i + 1 == num));
if (ret != pmsg->len) {
DEB2(printk(KERN_DEBUG "i2c-algo-pcf.o: fail: "
"only read %d bytes.\n",ret));
} else {
DEB2(printk(KERN_DEBUG "i2c-algo-pcf.o: read %d bytes.\n",ret));
}
} else {
ret = pcf_sendbytes(i2c_adap, pmsg->buf, pmsg->len,
(i + 1 == num));
if (ret != pmsg->len) {
DEB2(printk(KERN_DEBUG "i2c-algo-pcf.o: fail: "
"only wrote %d bytes.\n",ret));
} else {
DEB2(printk(KERN_DEBUG "i2c-algo-pcf.o: wrote %d bytes.\n",ret));
}
}
}
out:
if (adap->xfer_end)
adap->xfer_end(adap->data);
return i;
}
static u32 pcf_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL |
I2C_FUNC_PROTOCOL_MANGLING;
}
int i2c_pcf_add_bus(struct i2c_adapter *adap)
{
struct i2c_algo_pcf_data *pcf_adap = adap->algo_data;
int rval;
DEB2(dev_dbg(&adap->dev, "hw routines registered.\n"));
adap->algo = &pcf_algo;
if ((rval = pcf_init_8584(pcf_adap)))
return rval;
rval = i2c_add_adapter(adap);
return rval;
}
