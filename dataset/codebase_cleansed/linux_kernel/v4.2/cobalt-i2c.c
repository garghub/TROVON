static struct cobalt_i2c_regs __iomem *
cobalt_i2c_regs(struct cobalt *cobalt, unsigned idx)
{
switch (idx) {
case 0:
default:
return (struct cobalt_i2c_regs __iomem *)
(cobalt->bar1 + COBALT_I2C_0_BASE);
case 1:
return (struct cobalt_i2c_regs __iomem *)
(cobalt->bar1 + COBALT_I2C_1_BASE);
case 2:
return (struct cobalt_i2c_regs __iomem *)
(cobalt->bar1 + COBALT_I2C_2_BASE);
case 3:
return (struct cobalt_i2c_regs __iomem *)
(cobalt->bar1 + COBALT_I2C_3_BASE);
case 4:
return (struct cobalt_i2c_regs __iomem *)
(cobalt->bar1 + COBALT_I2C_HSMA_BASE);
}
}
static int cobalt_tx_bytes(struct cobalt_i2c_regs __iomem *regs,
struct i2c_adapter *adap, bool start, bool stop,
u8 *data, u16 len)
{
unsigned long start_time;
int status;
int cmd;
int i;
for (i = 0; i < len; i++) {
iowrite8(data[i], &regs->txr_rxr);
if (i == 0 && start != 0) {
cmd = M00018_CR_BITMAP_WR_MSK |
M00018_CR_BITMAP_STA_MSK;
} else if (i == len - 1 && stop != 0) {
cmd = M00018_CR_BITMAP_WR_MSK |
M00018_CR_BITMAP_STO_MSK;
} else {
cmd = M00018_CR_BITMAP_WR_MSK;
}
iowrite8(cmd, &regs->cr_sr);
start_time = jiffies;
status = ioread8(&regs->cr_sr);
while (status & M00018_SR_BITMAP_TIP_MSK) {
if (time_after(jiffies, start_time + adap->timeout))
return -ETIMEDOUT;
cond_resched();
status = ioread8(&regs->cr_sr);
}
if (status & M00018_SR_BITMAP_RXACK_MSK) {
return -EIO;
}
if (status & M00018_SR_BITMAP_AL_MSK) {
return -EIO;
}
}
return 0;
}
static int cobalt_rx_bytes(struct cobalt_i2c_regs __iomem *regs,
struct i2c_adapter *adap, bool start, bool stop,
u8 *data, u16 len)
{
unsigned long start_time;
int status;
int cmd;
int i;
for (i = 0; i < len; i++) {
if (i == 0 && start != 0) {
cmd = M00018_CR_BITMAP_RD_MSK |
M00018_CR_BITMAP_STA_MSK;
} else if (i == len - 1 && stop != 0) {
cmd = M00018_CR_BITMAP_RD_MSK |
M00018_CR_BITMAP_STO_MSK;
} else {
cmd = M00018_CR_BITMAP_RD_MSK;
}
if (i == len - 1)
cmd |= M00018_CR_BITMAP_ACK_MSK;
iowrite8(cmd, &regs->cr_sr);
start_time = jiffies;
status = ioread8(&regs->cr_sr);
while (status & M00018_SR_BITMAP_TIP_MSK) {
if (time_after(jiffies, start_time + adap->timeout))
return -ETIMEDOUT;
cond_resched();
status = ioread8(&regs->cr_sr);
}
if (status & M00018_SR_BITMAP_AL_MSK) {
return -EIO;
}
data[i] = ioread8(&regs->txr_rxr);
}
return 0;
}
static int cobalt_stop(struct cobalt_i2c_regs __iomem *regs,
struct i2c_adapter *adap)
{
u8 data = 0;
return cobalt_tx_bytes(regs, adap, true, true, &data, 1);
}
static int cobalt_xfer(struct i2c_adapter *adap,
struct i2c_msg msgs[], int num)
{
struct cobalt_i2c_data *data = adap->algo_data;
struct cobalt_i2c_regs __iomem *regs = data->regs;
struct i2c_msg *pmsg;
unsigned short flags;
int ret = 0;
int i, j;
for (i = 0; i < num; i++) {
int stop = (i == num - 1);
pmsg = &msgs[i];
flags = pmsg->flags;
if (!(pmsg->flags & I2C_M_NOSTART)) {
u8 addr = pmsg->addr << 1;
if (flags & I2C_M_RD)
addr |= 1;
if (flags & I2C_M_REV_DIR_ADDR)
addr ^= 1;
for (j = 0; j < adap->retries; j++) {
ret = cobalt_tx_bytes(regs, adap, true, false,
&addr, 1);
if (!ret)
break;
cobalt_stop(regs, adap);
}
if (ret < 0)
return ret;
ret = 0;
}
if (pmsg->flags & I2C_M_RD) {
ret = cobalt_rx_bytes(regs, adap, false, stop,
pmsg->buf, pmsg->len);
if (ret < 0)
goto bailout;
} else {
ret = cobalt_tx_bytes(regs, adap, false, stop,
pmsg->buf, pmsg->len);
if (ret < 0)
goto bailout;
}
}
ret = i;
bailout:
if (ret < 0)
cobalt_stop(regs, adap);
return ret;
}
static u32 cobalt_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
int cobalt_i2c_init(struct cobalt *cobalt)
{
int i, err;
int status;
int prescale;
unsigned long start_time;
cobalt_dbg(1, "i2c init\n");
prescale = ((ALT_CPU_FREQ) / (5 * I2C_FREQUENCY)) - 1;
for (i = 0; i < COBALT_NUM_ADAPTERS; i++) {
struct cobalt_i2c_regs __iomem *regs =
cobalt_i2c_regs(cobalt, i);
struct i2c_adapter *adap = &cobalt->i2c_adap[i];
iowrite8(M00018_CTR_BITMAP_EN_MSK, &regs->cr_sr);
iowrite8(0, &regs->ctr);
iowrite8(0, &regs->cr_sr);
start_time = jiffies;
do {
if (time_after(jiffies, start_time + HZ)) {
if (cobalt_ignore_err) {
adap->dev.parent = NULL;
return 0;
}
return -ETIMEDOUT;
}
status = ioread8(&regs->cr_sr);
} while (status & M00018_SR_BITMAP_TIP_MSK);
iowrite8(0, &regs->ctr);
iowrite8(0, &regs->cr_sr);
iowrite8(prescale & 0xff, &regs->prerlo);
iowrite8((prescale >> 8) & 0xff, &regs->prerhi);
iowrite8(M00018_CTR_BITMAP_EN_MSK, &regs->ctr);
cobalt->i2c_data[i].cobalt = cobalt;
cobalt->i2c_data[i].regs = regs;
*adap = cobalt_i2c_adap_template;
adap->algo = &cobalt_algo;
adap->algo_data = &cobalt->i2c_data[i];
adap->retries = 3;
sprintf(adap->name + strlen(adap->name),
" #%d-%d", cobalt->instance, i);
i2c_set_adapdata(adap, &cobalt->v4l2_dev);
adap->dev.parent = &cobalt->pci_dev->dev;
err = i2c_add_adapter(adap);
if (err) {
if (cobalt_ignore_err) {
adap->dev.parent = NULL;
return 0;
}
while (i--)
i2c_del_adapter(&cobalt->i2c_adap[i]);
return err;
}
cobalt_info("registered bus %s\n", adap->name);
}
return 0;
}
void cobalt_i2c_exit(struct cobalt *cobalt)
{
int i;
cobalt_dbg(1, "i2c exit\n");
for (i = 0; i < COBALT_NUM_ADAPTERS; i++) {
cobalt_err("unregistered bus %s\n", cobalt->i2c_adap[i].name);
i2c_del_adapter(&cobalt->i2c_adap[i]);
}
}
