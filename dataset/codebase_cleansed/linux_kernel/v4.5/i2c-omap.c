static inline void omap_i2c_write_reg(struct omap_i2c_dev *omap,
int reg, u16 val)
{
writew_relaxed(val, omap->base +
(omap->regs[reg] << omap->reg_shift));
}
static inline u16 omap_i2c_read_reg(struct omap_i2c_dev *omap, int reg)
{
return readw_relaxed(omap->base +
(omap->regs[reg] << omap->reg_shift));
}
static void __omap_i2c_init(struct omap_i2c_dev *omap)
{
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG, 0);
omap_i2c_write_reg(omap, OMAP_I2C_PSC_REG, omap->pscstate);
omap_i2c_write_reg(omap, OMAP_I2C_SCLL_REG, omap->scllstate);
omap_i2c_write_reg(omap, OMAP_I2C_SCLH_REG, omap->sclhstate);
if (omap->rev >= OMAP_I2C_REV_ON_3430_3530)
omap_i2c_write_reg(omap, OMAP_I2C_WE_REG, omap->westate);
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG, OMAP_I2C_CON_EN);
if (omap->iestate)
omap_i2c_write_reg(omap, OMAP_I2C_IE_REG, omap->iestate);
}
static int omap_i2c_reset(struct omap_i2c_dev *omap)
{
unsigned long timeout;
u16 sysc;
if (omap->rev >= OMAP_I2C_OMAP1_REV_2) {
sysc = omap_i2c_read_reg(omap, OMAP_I2C_SYSC_REG);
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG,
omap_i2c_read_reg(omap, OMAP_I2C_CON_REG) &
~(OMAP_I2C_CON_EN));
omap_i2c_write_reg(omap, OMAP_I2C_SYSC_REG, SYSC_SOFTRESET_MASK);
timeout = jiffies + OMAP_I2C_TIMEOUT;
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG, OMAP_I2C_CON_EN);
while (!(omap_i2c_read_reg(omap, OMAP_I2C_SYSS_REG) &
SYSS_RESETDONE_MASK)) {
if (time_after(jiffies, timeout)) {
dev_warn(omap->dev, "timeout waiting "
"for controller reset\n");
return -ETIMEDOUT;
}
msleep(1);
}
omap_i2c_write_reg(omap, OMAP_I2C_SYSC_REG, sysc);
if (omap->rev > OMAP_I2C_REV_ON_3430_3530) {
omap->bb_valid = 0;
}
}
return 0;
}
static int omap_i2c_init(struct omap_i2c_dev *omap)
{
u16 psc = 0, scll = 0, sclh = 0;
u16 fsscll = 0, fssclh = 0, hsscll = 0, hssclh = 0;
unsigned long fclk_rate = 12000000;
unsigned long internal_clk = 0;
struct clk *fclk;
if (omap->rev >= OMAP_I2C_REV_ON_3430_3530) {
omap->westate = OMAP_I2C_WE_ALL;
}
if (omap->flags & OMAP_I2C_FLAG_ALWAYS_ARMXOR_CLK) {
fclk = clk_get(omap->dev, "fck");
fclk_rate = clk_get_rate(fclk);
clk_put(fclk);
if (fclk_rate > 12000000)
psc = fclk_rate / 12000000;
}
if (!(omap->flags & OMAP_I2C_FLAG_SIMPLE_CLOCK)) {
if (omap->speed > 400 ||
omap->flags & OMAP_I2C_FLAG_FORCE_19200_INT_CLK)
internal_clk = 19200;
else if (omap->speed > 100)
internal_clk = 9600;
else
internal_clk = 4000;
fclk = clk_get(omap->dev, "fck");
fclk_rate = clk_get_rate(fclk) / 1000;
clk_put(fclk);
psc = fclk_rate / internal_clk;
psc = psc - 1;
if (omap->speed > 400) {
unsigned long scl;
scl = internal_clk / 400;
fsscll = scl - (scl / 3) - 7;
fssclh = (scl / 3) - 5;
scl = fclk_rate / omap->speed;
hsscll = scl - (scl / 3) - 7;
hssclh = (scl / 3) - 5;
} else if (omap->speed > 100) {
unsigned long scl;
scl = internal_clk / omap->speed;
fsscll = scl - (scl / 3) - 7;
fssclh = (scl / 3) - 5;
} else {
fsscll = internal_clk / (omap->speed * 2) - 7;
fssclh = internal_clk / (omap->speed * 2) - 5;
}
scll = (hsscll << OMAP_I2C_SCLL_HSSCLL) | fsscll;
sclh = (hssclh << OMAP_I2C_SCLH_HSSCLH) | fssclh;
} else {
fclk_rate /= (psc + 1) * 1000;
if (psc > 2)
psc = 2;
scll = fclk_rate / (omap->speed * 2) - 7 + psc;
sclh = fclk_rate / (omap->speed * 2) - 7 + psc;
}
omap->iestate = (OMAP_I2C_IE_XRDY | OMAP_I2C_IE_RRDY |
OMAP_I2C_IE_ARDY | OMAP_I2C_IE_NACK |
OMAP_I2C_IE_AL) | ((omap->fifo_size) ?
(OMAP_I2C_IE_RDR | OMAP_I2C_IE_XDR) : 0);
omap->pscstate = psc;
omap->scllstate = scll;
omap->sclhstate = sclh;
if (omap->rev <= OMAP_I2C_REV_ON_3430_3530) {
omap->bb_valid = 1;
}
__omap_i2c_init(omap);
return 0;
}
static int omap_i2c_wait_for_bb(struct omap_i2c_dev *omap)
{
unsigned long timeout;
timeout = jiffies + OMAP_I2C_TIMEOUT;
while (omap_i2c_read_reg(omap, OMAP_I2C_STAT_REG) & OMAP_I2C_STAT_BB) {
if (time_after(jiffies, timeout))
return i2c_recover_bus(&omap->adapter);
msleep(1);
}
return 0;
}
static int omap_i2c_wait_for_bb_valid(struct omap_i2c_dev *omap)
{
unsigned long bus_free_timeout = 0;
unsigned long timeout;
int bus_free = 0;
u16 stat, systest;
if (omap->bb_valid)
return 0;
timeout = jiffies + OMAP_I2C_TIMEOUT;
while (1) {
stat = omap_i2c_read_reg(omap, OMAP_I2C_STAT_REG);
if (stat & (OMAP_I2C_STAT_BB | OMAP_I2C_STAT_BF))
break;
systest = omap_i2c_read_reg(omap, OMAP_I2C_SYSTEST_REG);
if ((systest & OMAP_I2C_SYSTEST_SCL_I_FUNC) &&
(systest & OMAP_I2C_SYSTEST_SDA_I_FUNC)) {
if (!bus_free) {
bus_free_timeout = jiffies +
OMAP_I2C_BUS_FREE_TIMEOUT;
bus_free = 1;
}
if (time_after(jiffies, bus_free_timeout))
break;
} else {
bus_free = 0;
}
if (time_after(jiffies, timeout)) {
dev_warn(omap->dev, "timeout waiting for bus ready\n");
return -ETIMEDOUT;
}
msleep(1);
}
omap->bb_valid = 1;
return 0;
}
static void omap_i2c_resize_fifo(struct omap_i2c_dev *omap, u8 size, bool is_rx)
{
u16 buf;
if (omap->flags & OMAP_I2C_FLAG_NO_FIFO)
return;
omap->threshold = clamp(size, (u8) 1, omap->fifo_size);
buf = omap_i2c_read_reg(omap, OMAP_I2C_BUF_REG);
if (is_rx) {
buf &= ~(0x3f << 8);
buf |= ((omap->threshold - 1) << 8) | OMAP_I2C_BUF_RXFIF_CLR;
} else {
buf &= ~0x3f;
buf |= (omap->threshold - 1) | OMAP_I2C_BUF_TXFIF_CLR;
}
omap_i2c_write_reg(omap, OMAP_I2C_BUF_REG, buf);
if (omap->rev < OMAP_I2C_REV_ON_3630)
omap->b_hw = 1;
if (omap->set_mpu_wkup_lat != NULL)
omap->latency = (1000000 * omap->threshold) /
(1000 * omap->speed / 8);
}
static int omap_i2c_xfer_msg(struct i2c_adapter *adap,
struct i2c_msg *msg, int stop)
{
struct omap_i2c_dev *omap = i2c_get_adapdata(adap);
unsigned long timeout;
u16 w;
dev_dbg(omap->dev, "addr: 0x%04x, len: %d, flags: 0x%x, stop: %d\n",
msg->addr, msg->len, msg->flags, stop);
if (msg->len == 0)
return -EINVAL;
omap->receiver = !!(msg->flags & I2C_M_RD);
omap_i2c_resize_fifo(omap, msg->len, omap->receiver);
omap_i2c_write_reg(omap, OMAP_I2C_SA_REG, msg->addr);
omap->buf = msg->buf;
omap->buf_len = msg->len;
barrier();
omap_i2c_write_reg(omap, OMAP_I2C_CNT_REG, omap->buf_len);
w = omap_i2c_read_reg(omap, OMAP_I2C_BUF_REG);
w |= OMAP_I2C_BUF_RXFIF_CLR | OMAP_I2C_BUF_TXFIF_CLR;
omap_i2c_write_reg(omap, OMAP_I2C_BUF_REG, w);
reinit_completion(&omap->cmd_complete);
omap->cmd_err = 0;
w = OMAP_I2C_CON_EN | OMAP_I2C_CON_MST | OMAP_I2C_CON_STT;
if (omap->speed > 400)
w |= OMAP_I2C_CON_OPMODE_HS;
if (msg->flags & I2C_M_STOP)
stop = 1;
if (msg->flags & I2C_M_TEN)
w |= OMAP_I2C_CON_XA;
if (!(msg->flags & I2C_M_RD))
w |= OMAP_I2C_CON_TRX;
if (!omap->b_hw && stop)
w |= OMAP_I2C_CON_STP;
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG, w);
if (omap->b_hw && stop) {
unsigned long delay = jiffies + OMAP_I2C_TIMEOUT;
u16 con = omap_i2c_read_reg(omap, OMAP_I2C_CON_REG);
while (con & OMAP_I2C_CON_STT) {
con = omap_i2c_read_reg(omap, OMAP_I2C_CON_REG);
if (time_after(jiffies, delay)) {
dev_err(omap->dev, "controller timed out "
"waiting for start condition to finish\n");
return -ETIMEDOUT;
}
cpu_relax();
}
w |= OMAP_I2C_CON_STP;
w &= ~OMAP_I2C_CON_STT;
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG, w);
}
timeout = wait_for_completion_timeout(&omap->cmd_complete,
OMAP_I2C_TIMEOUT);
if (timeout == 0) {
dev_err(omap->dev, "controller timed out\n");
omap_i2c_reset(omap);
__omap_i2c_init(omap);
return -ETIMEDOUT;
}
if (likely(!omap->cmd_err))
return 0;
if (omap->cmd_err & (OMAP_I2C_STAT_ROVR | OMAP_I2C_STAT_XUDF)) {
omap_i2c_reset(omap);
__omap_i2c_init(omap);
return -EIO;
}
if (omap->cmd_err & OMAP_I2C_STAT_AL)
return -EAGAIN;
if (omap->cmd_err & OMAP_I2C_STAT_NACK) {
if (msg->flags & I2C_M_IGNORE_NAK)
return 0;
w = omap_i2c_read_reg(omap, OMAP_I2C_CON_REG);
w |= OMAP_I2C_CON_STP;
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG, w);
return -EREMOTEIO;
}
return -EIO;
}
static int
omap_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg msgs[], int num)
{
struct omap_i2c_dev *omap = i2c_get_adapdata(adap);
int i;
int r;
r = pm_runtime_get_sync(omap->dev);
if (r < 0)
goto out;
r = omap_i2c_wait_for_bb_valid(omap);
if (r < 0)
goto out;
r = omap_i2c_wait_for_bb(omap);
if (r < 0)
goto out;
if (omap->set_mpu_wkup_lat != NULL)
omap->set_mpu_wkup_lat(omap->dev, omap->latency);
for (i = 0; i < num; i++) {
r = omap_i2c_xfer_msg(adap, &msgs[i], (i == (num - 1)));
if (r != 0)
break;
}
if (r == 0)
r = num;
omap_i2c_wait_for_bb(omap);
if (omap->set_mpu_wkup_lat != NULL)
omap->set_mpu_wkup_lat(omap->dev, -1);
out:
pm_runtime_mark_last_busy(omap->dev);
pm_runtime_put_autosuspend(omap->dev);
return r;
}
static u32
omap_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK) |
I2C_FUNC_PROTOCOL_MANGLING;
}
static inline void
omap_i2c_complete_cmd(struct omap_i2c_dev *omap, u16 err)
{
omap->cmd_err |= err;
complete(&omap->cmd_complete);
}
static inline void
omap_i2c_ack_stat(struct omap_i2c_dev *omap, u16 stat)
{
omap_i2c_write_reg(omap, OMAP_I2C_STAT_REG, stat);
}
static inline void i2c_omap_errata_i207(struct omap_i2c_dev *omap, u16 stat)
{
if (stat & OMAP_I2C_STAT_RDR) {
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_RDR);
if (!(omap_i2c_read_reg(omap, OMAP_I2C_STAT_REG)
& OMAP_I2C_STAT_BB)) {
if (omap_i2c_read_reg(omap, OMAP_I2C_STAT_REG)
& OMAP_I2C_STAT_RDR) {
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_RDR);
dev_dbg(omap->dev, "RDR when bus is busy.\n");
}
}
}
}
static irqreturn_t
omap_i2c_omap1_isr(int this_irq, void *dev_id)
{
struct omap_i2c_dev *omap = dev_id;
u16 iv, w;
if (pm_runtime_suspended(omap->dev))
return IRQ_NONE;
iv = omap_i2c_read_reg(omap, OMAP_I2C_IV_REG);
switch (iv) {
case 0x00:
break;
case 0x01:
dev_err(omap->dev, "Arbitration lost\n");
omap_i2c_complete_cmd(omap, OMAP_I2C_STAT_AL);
break;
case 0x02:
omap_i2c_complete_cmd(omap, OMAP_I2C_STAT_NACK);
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG, OMAP_I2C_CON_STP);
break;
case 0x03:
omap_i2c_complete_cmd(omap, 0);
break;
case 0x04:
if (omap->buf_len) {
w = omap_i2c_read_reg(omap, OMAP_I2C_DATA_REG);
*omap->buf++ = w;
omap->buf_len--;
if (omap->buf_len) {
*omap->buf++ = w >> 8;
omap->buf_len--;
}
} else
dev_err(omap->dev, "RRDY IRQ while no data requested\n");
break;
case 0x05:
if (omap->buf_len) {
w = *omap->buf++;
omap->buf_len--;
if (omap->buf_len) {
w |= *omap->buf++ << 8;
omap->buf_len--;
}
omap_i2c_write_reg(omap, OMAP_I2C_DATA_REG, w);
} else
dev_err(omap->dev, "XRDY IRQ while no data to send\n");
break;
default:
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static int errata_omap3_i462(struct omap_i2c_dev *omap)
{
unsigned long timeout = 10000;
u16 stat;
do {
stat = omap_i2c_read_reg(omap, OMAP_I2C_STAT_REG);
if (stat & OMAP_I2C_STAT_XUDF)
break;
if (stat & (OMAP_I2C_STAT_NACK | OMAP_I2C_STAT_AL)) {
omap_i2c_ack_stat(omap, (OMAP_I2C_STAT_XRDY |
OMAP_I2C_STAT_XDR));
if (stat & OMAP_I2C_STAT_NACK) {
omap->cmd_err |= OMAP_I2C_STAT_NACK;
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_NACK);
}
if (stat & OMAP_I2C_STAT_AL) {
dev_err(omap->dev, "Arbitration lost\n");
omap->cmd_err |= OMAP_I2C_STAT_AL;
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_AL);
}
return -EIO;
}
cpu_relax();
} while (--timeout);
if (!timeout) {
dev_err(omap->dev, "timeout waiting on XUDF bit\n");
return 0;
}
return 0;
}
static void omap_i2c_receive_data(struct omap_i2c_dev *omap, u8 num_bytes,
bool is_rdr)
{
u16 w;
while (num_bytes--) {
w = omap_i2c_read_reg(omap, OMAP_I2C_DATA_REG);
*omap->buf++ = w;
omap->buf_len--;
if (omap->flags & OMAP_I2C_FLAG_16BIT_DATA_REG) {
*omap->buf++ = w >> 8;
omap->buf_len--;
}
}
}
static int omap_i2c_transmit_data(struct omap_i2c_dev *omap, u8 num_bytes,
bool is_xdr)
{
u16 w;
while (num_bytes--) {
w = *omap->buf++;
omap->buf_len--;
if (omap->flags & OMAP_I2C_FLAG_16BIT_DATA_REG) {
w |= *omap->buf++ << 8;
omap->buf_len--;
}
if (omap->errata & I2C_OMAP_ERRATA_I462) {
int ret;
ret = errata_omap3_i462(omap);
if (ret < 0)
return ret;
}
omap_i2c_write_reg(omap, OMAP_I2C_DATA_REG, w);
}
return 0;
}
static irqreturn_t
omap_i2c_isr(int irq, void *dev_id)
{
struct omap_i2c_dev *omap = dev_id;
irqreturn_t ret = IRQ_HANDLED;
u16 mask;
u16 stat;
spin_lock(&omap->lock);
mask = omap_i2c_read_reg(omap, OMAP_I2C_IE_REG);
stat = omap_i2c_read_reg(omap, OMAP_I2C_STAT_REG);
if (stat & mask)
ret = IRQ_WAKE_THREAD;
spin_unlock(&omap->lock);
return ret;
}
static irqreturn_t
omap_i2c_isr_thread(int this_irq, void *dev_id)
{
struct omap_i2c_dev *omap = dev_id;
unsigned long flags;
u16 bits;
u16 stat;
int err = 0, count = 0;
spin_lock_irqsave(&omap->lock, flags);
do {
bits = omap_i2c_read_reg(omap, OMAP_I2C_IE_REG);
stat = omap_i2c_read_reg(omap, OMAP_I2C_STAT_REG);
stat &= bits;
if (omap->receiver)
stat &= ~(OMAP_I2C_STAT_XDR | OMAP_I2C_STAT_XRDY);
else
stat &= ~(OMAP_I2C_STAT_RDR | OMAP_I2C_STAT_RRDY);
if (!stat) {
goto out;
}
dev_dbg(omap->dev, "IRQ (ISR = 0x%04x)\n", stat);
if (count++ == 100) {
dev_warn(omap->dev, "Too much work in one IRQ\n");
break;
}
if (stat & OMAP_I2C_STAT_NACK) {
err |= OMAP_I2C_STAT_NACK;
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_NACK);
}
if (stat & OMAP_I2C_STAT_AL) {
dev_err(omap->dev, "Arbitration lost\n");
err |= OMAP_I2C_STAT_AL;
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_AL);
}
if (stat & OMAP_I2C_STAT_ARDY)
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_ARDY);
if (stat & (OMAP_I2C_STAT_ARDY | OMAP_I2C_STAT_NACK |
OMAP_I2C_STAT_AL)) {
omap_i2c_ack_stat(omap, (OMAP_I2C_STAT_RRDY |
OMAP_I2C_STAT_RDR |
OMAP_I2C_STAT_XRDY |
OMAP_I2C_STAT_XDR |
OMAP_I2C_STAT_ARDY));
break;
}
if (stat & OMAP_I2C_STAT_RDR) {
u8 num_bytes = 1;
if (omap->fifo_size)
num_bytes = omap->buf_len;
if (omap->errata & I2C_OMAP_ERRATA_I207) {
i2c_omap_errata_i207(omap, stat);
num_bytes = (omap_i2c_read_reg(omap,
OMAP_I2C_BUFSTAT_REG) >> 8) & 0x3F;
}
omap_i2c_receive_data(omap, num_bytes, true);
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_RDR);
continue;
}
if (stat & OMAP_I2C_STAT_RRDY) {
u8 num_bytes = 1;
if (omap->threshold)
num_bytes = omap->threshold;
omap_i2c_receive_data(omap, num_bytes, false);
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_RRDY);
continue;
}
if (stat & OMAP_I2C_STAT_XDR) {
u8 num_bytes = 1;
int ret;
if (omap->fifo_size)
num_bytes = omap->buf_len;
ret = omap_i2c_transmit_data(omap, num_bytes, true);
if (ret < 0)
break;
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_XDR);
continue;
}
if (stat & OMAP_I2C_STAT_XRDY) {
u8 num_bytes = 1;
int ret;
if (omap->threshold)
num_bytes = omap->threshold;
ret = omap_i2c_transmit_data(omap, num_bytes, false);
if (ret < 0)
break;
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_XRDY);
continue;
}
if (stat & OMAP_I2C_STAT_ROVR) {
dev_err(omap->dev, "Receive overrun\n");
err |= OMAP_I2C_STAT_ROVR;
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_ROVR);
break;
}
if (stat & OMAP_I2C_STAT_XUDF) {
dev_err(omap->dev, "Transmit underflow\n");
err |= OMAP_I2C_STAT_XUDF;
omap_i2c_ack_stat(omap, OMAP_I2C_STAT_XUDF);
break;
}
} while (stat);
omap_i2c_complete_cmd(omap, err);
out:
spin_unlock_irqrestore(&omap->lock, flags);
return IRQ_HANDLED;
}
static int omap_i2c_get_scl(struct i2c_adapter *adap)
{
struct omap_i2c_dev *dev = i2c_get_adapdata(adap);
u32 reg;
reg = omap_i2c_read_reg(dev, OMAP_I2C_SYSTEST_REG);
return reg & OMAP_I2C_SYSTEST_SCL_I_FUNC;
}
static int omap_i2c_get_sda(struct i2c_adapter *adap)
{
struct omap_i2c_dev *dev = i2c_get_adapdata(adap);
u32 reg;
reg = omap_i2c_read_reg(dev, OMAP_I2C_SYSTEST_REG);
return reg & OMAP_I2C_SYSTEST_SDA_I_FUNC;
}
static void omap_i2c_set_scl(struct i2c_adapter *adap, int val)
{
struct omap_i2c_dev *dev = i2c_get_adapdata(adap);
u32 reg;
reg = omap_i2c_read_reg(dev, OMAP_I2C_SYSTEST_REG);
if (val)
reg |= OMAP_I2C_SYSTEST_SCL_O;
else
reg &= ~OMAP_I2C_SYSTEST_SCL_O;
omap_i2c_write_reg(dev, OMAP_I2C_SYSTEST_REG, reg);
}
static void omap_i2c_prepare_recovery(struct i2c_adapter *adap)
{
struct omap_i2c_dev *dev = i2c_get_adapdata(adap);
u32 reg;
reg = omap_i2c_read_reg(dev, OMAP_I2C_SYSTEST_REG);
reg |= OMAP_I2C_SYSTEST_ST_EN;
reg |= 3 << OMAP_I2C_SYSTEST_TMODE_SHIFT;
reg |= OMAP_I2C_SYSTEST_SCL_O;
reg |= OMAP_I2C_SYSTEST_SDA_O;
omap_i2c_write_reg(dev, OMAP_I2C_SYSTEST_REG, reg);
}
static void omap_i2c_unprepare_recovery(struct i2c_adapter *adap)
{
struct omap_i2c_dev *dev = i2c_get_adapdata(adap);
u32 reg;
reg = omap_i2c_read_reg(dev, OMAP_I2C_SYSTEST_REG);
reg &= ~OMAP_I2C_SYSTEST_ST_EN;
reg &= ~OMAP_I2C_SYSTEST_TMODE_MASK;
reg &= ~OMAP_I2C_SYSTEST_SCL_O;
reg &= ~OMAP_I2C_SYSTEST_SDA_O;
omap_i2c_write_reg(dev, OMAP_I2C_SYSTEST_REG, reg);
}
static int
omap_i2c_probe(struct platform_device *pdev)
{
struct omap_i2c_dev *omap;
struct i2c_adapter *adap;
struct resource *mem;
const struct omap_i2c_bus_platform_data *pdata =
dev_get_platdata(&pdev->dev);
struct device_node *node = pdev->dev.of_node;
const struct of_device_id *match;
int irq;
int r;
u32 rev;
u16 minor, major;
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "no irq resource?\n");
return irq;
}
omap = devm_kzalloc(&pdev->dev, sizeof(struct omap_i2c_dev), GFP_KERNEL);
if (!omap)
return -ENOMEM;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
omap->base = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(omap->base))
return PTR_ERR(omap->base);
match = of_match_device(of_match_ptr(omap_i2c_of_match), &pdev->dev);
if (match) {
u32 freq = 100000;
pdata = match->data;
omap->flags = pdata->flags;
of_property_read_u32(node, "clock-frequency", &freq);
omap->speed = freq / 1000;
} else if (pdata != NULL) {
omap->speed = pdata->clkrate;
omap->flags = pdata->flags;
omap->set_mpu_wkup_lat = pdata->set_mpu_wkup_lat;
}
omap->dev = &pdev->dev;
omap->irq = irq;
spin_lock_init(&omap->lock);
platform_set_drvdata(pdev, omap);
init_completion(&omap->cmd_complete);
omap->reg_shift = (omap->flags >> OMAP_I2C_FLAG_BUS_SHIFT__SHIFT) & 3;
pm_runtime_enable(omap->dev);
pm_runtime_set_autosuspend_delay(omap->dev, OMAP_I2C_PM_TIMEOUT);
pm_runtime_use_autosuspend(omap->dev);
r = pm_runtime_get_sync(omap->dev);
if (r < 0)
goto err_free_mem;
rev = readw_relaxed(omap->base + 0x04);
omap->scheme = OMAP_I2C_SCHEME(rev);
switch (omap->scheme) {
case OMAP_I2C_SCHEME_0:
omap->regs = (u8 *)reg_map_ip_v1;
omap->rev = omap_i2c_read_reg(omap, OMAP_I2C_REV_REG);
minor = OMAP_I2C_REV_SCHEME_0_MAJOR(omap->rev);
major = OMAP_I2C_REV_SCHEME_0_MAJOR(omap->rev);
break;
case OMAP_I2C_SCHEME_1:
default:
omap->regs = (u8 *)reg_map_ip_v2;
rev = (rev << 16) |
omap_i2c_read_reg(omap, OMAP_I2C_IP_V2_REVNB_LO);
minor = OMAP_I2C_REV_SCHEME_1_MINOR(rev);
major = OMAP_I2C_REV_SCHEME_1_MAJOR(rev);
omap->rev = rev;
}
omap->errata = 0;
if (omap->rev >= OMAP_I2C_REV_ON_2430 &&
omap->rev < OMAP_I2C_REV_ON_4430_PLUS)
omap->errata |= I2C_OMAP_ERRATA_I207;
if (omap->rev <= OMAP_I2C_REV_ON_3430_3530)
omap->errata |= I2C_OMAP_ERRATA_I462;
if (!(omap->flags & OMAP_I2C_FLAG_NO_FIFO)) {
u16 s;
s = (omap_i2c_read_reg(omap, OMAP_I2C_BUFSTAT_REG) >> 14) & 0x3;
omap->fifo_size = 0x8 << s;
omap->fifo_size = (omap->fifo_size / 2);
if (omap->rev < OMAP_I2C_REV_ON_3630)
omap->b_hw = 1;
if (omap->set_mpu_wkup_lat != NULL)
omap->latency = (1000000 * omap->fifo_size) /
(1000 * omap->speed / 8);
}
omap_i2c_init(omap);
if (omap->rev < OMAP_I2C_OMAP1_REV_2)
r = devm_request_irq(&pdev->dev, omap->irq, omap_i2c_omap1_isr,
IRQF_NO_SUSPEND, pdev->name, omap);
else
r = devm_request_threaded_irq(&pdev->dev, omap->irq,
omap_i2c_isr, omap_i2c_isr_thread,
IRQF_NO_SUSPEND | IRQF_ONESHOT,
pdev->name, omap);
if (r) {
dev_err(omap->dev, "failure requesting irq %i\n", omap->irq);
goto err_unuse_clocks;
}
adap = &omap->adapter;
i2c_set_adapdata(adap, omap);
adap->owner = THIS_MODULE;
adap->class = I2C_CLASS_DEPRECATED;
strlcpy(adap->name, "OMAP I2C adapter", sizeof(adap->name));
adap->algo = &omap_i2c_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
adap->bus_recovery_info = &omap_i2c_bus_recovery_info;
adap->nr = pdev->id;
r = i2c_add_numbered_adapter(adap);
if (r) {
dev_err(omap->dev, "failure adding adapter\n");
goto err_unuse_clocks;
}
dev_info(omap->dev, "bus %d rev%d.%d at %d kHz\n", adap->nr,
major, minor, omap->speed);
pm_runtime_mark_last_busy(omap->dev);
pm_runtime_put_autosuspend(omap->dev);
return 0;
err_unuse_clocks:
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG, 0);
pm_runtime_dont_use_autosuspend(omap->dev);
pm_runtime_put_sync(omap->dev);
pm_runtime_disable(&pdev->dev);
err_free_mem:
return r;
}
static int omap_i2c_remove(struct platform_device *pdev)
{
struct omap_i2c_dev *omap = platform_get_drvdata(pdev);
int ret;
i2c_del_adapter(&omap->adapter);
ret = pm_runtime_get_sync(&pdev->dev);
if (ret < 0)
return ret;
omap_i2c_write_reg(omap, OMAP_I2C_CON_REG, 0);
pm_runtime_dont_use_autosuspend(&pdev->dev);
pm_runtime_put_sync(&pdev->dev);
pm_runtime_disable(&pdev->dev);
return 0;
}
static int omap_i2c_runtime_suspend(struct device *dev)
{
struct omap_i2c_dev *omap = dev_get_drvdata(dev);
omap->iestate = omap_i2c_read_reg(omap, OMAP_I2C_IE_REG);
if (omap->scheme == OMAP_I2C_SCHEME_0)
omap_i2c_write_reg(omap, OMAP_I2C_IE_REG, 0);
else
omap_i2c_write_reg(omap, OMAP_I2C_IP_V2_IRQENABLE_CLR,
OMAP_I2C_IP_V2_INTERRUPTS_MASK);
if (omap->rev < OMAP_I2C_OMAP1_REV_2) {
omap_i2c_read_reg(omap, OMAP_I2C_IV_REG);
} else {
omap_i2c_write_reg(omap, OMAP_I2C_STAT_REG, omap->iestate);
omap_i2c_read_reg(omap, OMAP_I2C_STAT_REG);
}
pinctrl_pm_select_sleep_state(dev);
return 0;
}
static int omap_i2c_runtime_resume(struct device *dev)
{
struct omap_i2c_dev *omap = dev_get_drvdata(dev);
pinctrl_pm_select_default_state(dev);
if (!omap->regs)
return 0;
__omap_i2c_init(omap);
return 0;
}
static int __init
omap_i2c_init_driver(void)
{
return platform_driver_register(&omap_i2c_driver);
}
static void __exit omap_i2c_exit_driver(void)
{
platform_driver_unregister(&omap_i2c_driver);
}
