static inline unsigned short jz4780_i2c_readw(struct jz4780_i2c *i2c,
unsigned long offset)
{
return readw(i2c->iomem + offset);
}
static inline void jz4780_i2c_writew(struct jz4780_i2c *i2c,
unsigned long offset, unsigned short val)
{
writew(val, i2c->iomem + offset);
}
static int jz4780_i2c_disable(struct jz4780_i2c *i2c)
{
unsigned short regval;
unsigned long loops = 5;
jz4780_i2c_writew(i2c, JZ4780_I2C_ENB, 0);
do {
regval = jz4780_i2c_readw(i2c, JZ4780_I2C_ENSTA);
if (!(regval & JZ4780_I2C_ENB_I2C))
return 0;
usleep_range(5000, 15000);
} while (--loops);
dev_err(&i2c->adap.dev, "disable failed: ENSTA=0x%04x\n", regval);
return -ETIMEDOUT;
}
static int jz4780_i2c_enable(struct jz4780_i2c *i2c)
{
unsigned short regval;
unsigned long loops = 5;
jz4780_i2c_writew(i2c, JZ4780_I2C_ENB, 1);
do {
regval = jz4780_i2c_readw(i2c, JZ4780_I2C_ENSTA);
if (regval & JZ4780_I2C_ENB_I2C)
return 0;
usleep_range(5000, 15000);
} while (--loops);
dev_err(&i2c->adap.dev, "enable failed: ENSTA=0x%04x\n", regval);
return -ETIMEDOUT;
}
static int jz4780_i2c_set_target(struct jz4780_i2c *i2c, unsigned char address)
{
unsigned short regval;
unsigned long loops = 5;
do {
regval = jz4780_i2c_readw(i2c, JZ4780_I2C_STA);
if ((regval & JZ4780_I2C_STA_TFE) &&
!(regval & JZ4780_I2C_STA_MSTACT))
break;
usleep_range(5000, 15000);
} while (--loops);
if (loops) {
jz4780_i2c_writew(i2c, JZ4780_I2C_TAR, address);
return 0;
}
dev_err(&i2c->adap.dev,
"set device to address 0x%02x failed, STA=0x%04x\n",
address, regval);
return -ENXIO;
}
static int jz4780_i2c_set_speed(struct jz4780_i2c *i2c)
{
int dev_clk_khz = clk_get_rate(i2c->clk) / 1000;
int cnt_high = 0;
int cnt_low = 0;
int cnt_period = 0;
int setup_time = 0;
int hold_time = 0;
unsigned short tmp = 0;
int i2c_clk = i2c->speed;
if (jz4780_i2c_disable(i2c))
dev_dbg(&i2c->adap.dev, "i2c not disabled\n");
cnt_period = dev_clk_khz / i2c_clk;
if (i2c_clk <= 100)
cnt_high = (cnt_period * 4000) / (4700 + 4000);
else
cnt_high = (cnt_period * 600) / (1300 + 600);
cnt_low = cnt_period - cnt_high;
if (i2c_clk <= 100) {
tmp = JZ4780_I2C_CTRL_SPDS | JZ4780_I2C_CTRL_REST
| JZ4780_I2C_CTRL_SLVDIS | JZ4780_I2C_CTRL_MD;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL, tmp);
jz4780_i2c_writew(i2c, JZ4780_I2C_SHCNT,
JZ4780_I2CSHCNT_ADJUST(cnt_high));
jz4780_i2c_writew(i2c, JZ4780_I2C_SLCNT,
JZ4780_I2CSLCNT_ADJUST(cnt_low));
} else {
tmp = JZ4780_I2C_CTRL_SPDF | JZ4780_I2C_CTRL_REST
| JZ4780_I2C_CTRL_SLVDIS | JZ4780_I2C_CTRL_MD;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL, tmp);
jz4780_i2c_writew(i2c, JZ4780_I2C_FHCNT,
JZ4780_I2CFHCNT_ADJUST(cnt_high));
jz4780_i2c_writew(i2c, JZ4780_I2C_FLCNT,
JZ4780_I2CFLCNT_ADJUST(cnt_low));
}
if (i2c_clk <= 100) {
setup_time = 300;
hold_time = 400;
} else {
setup_time = 450;
hold_time = 450;
}
hold_time = ((hold_time * dev_clk_khz) / 1000000) - 1;
setup_time = ((setup_time * dev_clk_khz) / 1000000) + 1;
if (setup_time > 255)
setup_time = 255;
if (setup_time <= 0)
setup_time = 1;
jz4780_i2c_writew(i2c, JZ4780_I2C_SDASU, setup_time);
if (hold_time > 255)
hold_time = 255;
if (hold_time >= 0) {
hold_time |= JZ4780_I2C_SDAHD_HDENB;
jz4780_i2c_writew(i2c, JZ4780_I2C_SDAHD, hold_time);
} else {
jz4780_i2c_writew(i2c, JZ4780_I2C_SDAHD, 0);
}
return 0;
}
static int jz4780_i2c_cleanup(struct jz4780_i2c *i2c)
{
int ret;
unsigned long flags;
unsigned short tmp;
spin_lock_irqsave(&i2c->lock, flags);
tmp = jz4780_i2c_readw(i2c, JZ4780_I2C_CTRL);
tmp &= ~JZ4780_I2C_CTRL_STPHLD;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL, tmp);
jz4780_i2c_writew(i2c, JZ4780_I2C_INTM, 0);
jz4780_i2c_readw(i2c, JZ4780_I2C_CTXABRT);
jz4780_i2c_readw(i2c, JZ4780_I2C_CINTR);
tmp = jz4780_i2c_readw(i2c, JZ4780_I2C_CTRL);
tmp &= ~JZ4780_I2C_ENB_I2C;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL, tmp);
udelay(10);
tmp |= JZ4780_I2C_ENB_I2C;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL, tmp);
spin_unlock_irqrestore(&i2c->lock, flags);
ret = jz4780_i2c_disable(i2c);
if (ret)
dev_err(&i2c->adap.dev,
"unable to disable device during cleanup!\n");
if (unlikely(jz4780_i2c_readw(i2c, JZ4780_I2C_INTM)
& jz4780_i2c_readw(i2c, JZ4780_I2C_INTST)))
dev_err(&i2c->adap.dev,
"device has interrupts after a complete cleanup!\n");
return ret;
}
static int jz4780_i2c_prepare(struct jz4780_i2c *i2c)
{
jz4780_i2c_set_speed(i2c);
return jz4780_i2c_enable(i2c);
}
static void jz4780_i2c_send_rcmd(struct jz4780_i2c *i2c, int cmd_count)
{
int i;
for (i = 0; i < cmd_count; i++)
jz4780_i2c_writew(i2c, JZ4780_I2C_DC, JZ4780_I2C_DC_READ);
}
static void jz4780_i2c_trans_done(struct jz4780_i2c *i2c)
{
jz4780_i2c_writew(i2c, JZ4780_I2C_INTM, 0);
complete(&i2c->trans_waitq);
}
static irqreturn_t jz4780_i2c_irq(int irqno, void *dev_id)
{
unsigned short tmp;
unsigned short intst;
unsigned short intmsk;
struct jz4780_i2c *i2c = dev_id;
unsigned long flags;
spin_lock_irqsave(&i2c->lock, flags);
intmsk = jz4780_i2c_readw(i2c, JZ4780_I2C_INTM);
intst = jz4780_i2c_readw(i2c, JZ4780_I2C_INTST);
intst &= intmsk;
if (intst & JZ4780_I2C_INTST_TXABT) {
jz4780_i2c_trans_done(i2c);
goto done;
}
if (intst & JZ4780_I2C_INTST_RXOF) {
dev_dbg(&i2c->adap.dev, "received fifo overflow!\n");
jz4780_i2c_trans_done(i2c);
goto done;
}
if (i2c->is_write == 0) {
int rd_left;
while ((jz4780_i2c_readw(i2c, JZ4780_I2C_STA)
& JZ4780_I2C_STA_RFNE)) {
*(i2c->rbuf++) = jz4780_i2c_readw(i2c, JZ4780_I2C_DC)
& 0xff;
i2c->rd_data_xfered++;
if (i2c->rd_data_xfered == i2c->rd_total_len) {
jz4780_i2c_trans_done(i2c);
goto done;
}
}
rd_left = i2c->rd_total_len - i2c->rd_data_xfered;
if (rd_left <= JZ4780_I2C_FIFO_LEN)
jz4780_i2c_writew(i2c, JZ4780_I2C_RXTL, rd_left - 1);
}
if (intst & JZ4780_I2C_INTST_TXEMP) {
if (i2c->is_write == 0) {
int cmd_left = i2c->rd_total_len - i2c->rd_cmd_xfered;
int max_send = (JZ4780_I2C_FIFO_LEN - 1)
- (i2c->rd_cmd_xfered
- i2c->rd_data_xfered);
int cmd_to_send = min(cmd_left, max_send);
if (i2c->rd_cmd_xfered != 0)
cmd_to_send = min(cmd_to_send,
JZ4780_I2C_FIFO_LEN
- TX_LEVEL - 1);
if (cmd_to_send) {
jz4780_i2c_send_rcmd(i2c, cmd_to_send);
i2c->rd_cmd_xfered += cmd_to_send;
}
cmd_left = i2c->rd_total_len - i2c->rd_cmd_xfered;
if (cmd_left == 0) {
intmsk = jz4780_i2c_readw(i2c, JZ4780_I2C_INTM);
intmsk &= ~JZ4780_I2C_INTM_MTXEMP;
jz4780_i2c_writew(i2c, JZ4780_I2C_INTM, intmsk);
tmp = jz4780_i2c_readw(i2c, JZ4780_I2C_CTRL);
tmp &= ~JZ4780_I2C_CTRL_STPHLD;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL, tmp);
}
} else {
unsigned short data;
unsigned short i2c_sta;
i2c_sta = jz4780_i2c_readw(i2c, JZ4780_I2C_STA);
while ((i2c_sta & JZ4780_I2C_STA_TFNF) &&
(i2c->wt_len > 0)) {
i2c_sta = jz4780_i2c_readw(i2c, JZ4780_I2C_STA);
data = *i2c->wbuf;
data &= ~JZ4780_I2C_DC_READ;
jz4780_i2c_writew(i2c, JZ4780_I2C_DC,
data);
i2c->wbuf++;
i2c->wt_len--;
}
if (i2c->wt_len == 0) {
if (!i2c->stop_hold) {
tmp = jz4780_i2c_readw(i2c,
JZ4780_I2C_CTRL);
tmp &= ~JZ4780_I2C_CTRL_STPHLD;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL,
tmp);
}
jz4780_i2c_trans_done(i2c);
goto done;
}
}
}
done:
spin_unlock_irqrestore(&i2c->lock, flags);
return IRQ_HANDLED;
}
static void jz4780_i2c_txabrt(struct jz4780_i2c *i2c, int src)
{
int i;
dev_err(&i2c->adap.dev, "txabrt: 0x%08x\n", src);
dev_err(&i2c->adap.dev, "device addr=%x\n",
jz4780_i2c_readw(i2c, JZ4780_I2C_TAR));
dev_err(&i2c->adap.dev, "send cmd count:%d %d\n",
i2c->cmd, i2c->cmd_buf[i2c->cmd]);
dev_err(&i2c->adap.dev, "receive data count:%d %d\n",
i2c->cmd, i2c->data_buf[i2c->cmd]);
for (i = 0; i < 16; i++) {
if (src & BIT(i))
dev_dbg(&i2c->adap.dev, "I2C TXABRT[%d]=%s\n",
i, jz4780_i2c_abrt_src[i]);
}
}
static inline int jz4780_i2c_xfer_read(struct jz4780_i2c *i2c,
unsigned char *buf, int len, int cnt,
int idx)
{
int ret = 0;
long timeout;
int wait_time = JZ4780_I2C_TIMEOUT * (len + 5);
unsigned short tmp;
unsigned long flags;
memset(buf, 0, len);
spin_lock_irqsave(&i2c->lock, flags);
i2c->stop_hold = 0;
i2c->is_write = 0;
i2c->rbuf = buf;
i2c->rd_total_len = len;
i2c->rd_data_xfered = 0;
i2c->rd_cmd_xfered = 0;
if (len <= JZ4780_I2C_FIFO_LEN)
jz4780_i2c_writew(i2c, JZ4780_I2C_RXTL, len - 1);
else
jz4780_i2c_writew(i2c, JZ4780_I2C_RXTL, RX_LEVEL);
jz4780_i2c_writew(i2c, JZ4780_I2C_TXTL, TX_LEVEL);
jz4780_i2c_writew(i2c, JZ4780_I2C_INTM,
JZ4780_I2C_INTM_MRXFL | JZ4780_I2C_INTM_MTXEMP
| JZ4780_I2C_INTM_MTXABT | JZ4780_I2C_INTM_MRXOF);
tmp = jz4780_i2c_readw(i2c, JZ4780_I2C_CTRL);
tmp |= JZ4780_I2C_CTRL_STPHLD;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL, tmp);
spin_unlock_irqrestore(&i2c->lock, flags);
timeout = wait_for_completion_timeout(&i2c->trans_waitq,
msecs_to_jiffies(wait_time));
if (!timeout) {
dev_err(&i2c->adap.dev, "irq read timeout\n");
dev_dbg(&i2c->adap.dev, "send cmd count:%d %d\n",
i2c->cmd, i2c->cmd_buf[i2c->cmd]);
dev_dbg(&i2c->adap.dev, "receive data count:%d %d\n",
i2c->cmd, i2c->data_buf[i2c->cmd]);
ret = -EIO;
}
tmp = jz4780_i2c_readw(i2c, JZ4780_I2C_TXABRT);
if (tmp) {
jz4780_i2c_txabrt(i2c, tmp);
ret = -EIO;
}
return ret;
}
static inline int jz4780_i2c_xfer_write(struct jz4780_i2c *i2c,
unsigned char *buf, int len,
int cnt, int idx)
{
int ret = 0;
int wait_time = JZ4780_I2C_TIMEOUT * (len + 5);
long timeout;
unsigned short tmp;
unsigned long flags;
spin_lock_irqsave(&i2c->lock, flags);
if (idx < (cnt - 1))
i2c->stop_hold = 1;
else
i2c->stop_hold = 0;
i2c->is_write = 1;
i2c->wbuf = buf;
i2c->wt_len = len;
jz4780_i2c_writew(i2c, JZ4780_I2C_TXTL, TX_LEVEL);
jz4780_i2c_writew(i2c, JZ4780_I2C_INTM, JZ4780_I2C_INTM_MTXEMP
| JZ4780_I2C_INTM_MTXABT);
tmp = jz4780_i2c_readw(i2c, JZ4780_I2C_CTRL);
tmp |= JZ4780_I2C_CTRL_STPHLD;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL, tmp);
spin_unlock_irqrestore(&i2c->lock, flags);
timeout = wait_for_completion_timeout(&i2c->trans_waitq,
msecs_to_jiffies(wait_time));
if (timeout && !i2c->stop_hold) {
unsigned short i2c_sta;
int write_in_process;
timeout = JZ4780_I2C_TIMEOUT * 100;
for (; timeout > 0; timeout--) {
i2c_sta = jz4780_i2c_readw(i2c, JZ4780_I2C_STA);
write_in_process = (i2c_sta & JZ4780_I2C_STA_MSTACT) ||
!(i2c_sta & JZ4780_I2C_STA_TFE);
if (!write_in_process)
break;
udelay(10);
}
}
if (!timeout) {
dev_err(&i2c->adap.dev, "write wait timeout\n");
ret = -EIO;
}
tmp = jz4780_i2c_readw(i2c, JZ4780_I2C_TXABRT);
if (tmp) {
jz4780_i2c_txabrt(i2c, tmp);
ret = -EIO;
}
return ret;
}
static int jz4780_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msg,
int count)
{
int i = -EIO;
int ret = 0;
struct jz4780_i2c *i2c = adap->algo_data;
ret = jz4780_i2c_prepare(i2c);
if (ret) {
dev_err(&i2c->adap.dev, "I2C prepare failed\n");
goto out;
}
if (msg->addr != jz4780_i2c_readw(i2c, JZ4780_I2C_TAR)) {
ret = jz4780_i2c_set_target(i2c, msg->addr);
if (ret)
goto out;
}
for (i = 0; i < count; i++, msg++) {
if (msg->flags & I2C_M_RD)
ret = jz4780_i2c_xfer_read(i2c, msg->buf, msg->len,
count, i);
else
ret = jz4780_i2c_xfer_write(i2c, msg->buf, msg->len,
count, i);
if (ret)
goto out;
}
ret = i;
out:
jz4780_i2c_cleanup(i2c);
return ret;
}
static u32 jz4780_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int jz4780_i2c_probe(struct platform_device *pdev)
{
int ret = 0;
unsigned int clk_freq = 0;
unsigned short tmp;
struct resource *r;
struct jz4780_i2c *i2c;
i2c = devm_kzalloc(&pdev->dev, sizeof(struct jz4780_i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
i2c->adap.owner = THIS_MODULE;
i2c->adap.algo = &jz4780_i2c_algorithm;
i2c->adap.algo_data = i2c;
i2c->adap.retries = 5;
i2c->adap.dev.parent = &pdev->dev;
i2c->adap.dev.of_node = pdev->dev.of_node;
sprintf(i2c->adap.name, "%s", pdev->name);
init_completion(&i2c->trans_waitq);
spin_lock_init(&i2c->lock);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->iomem = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(i2c->iomem))
return PTR_ERR(i2c->iomem);
platform_set_drvdata(pdev, i2c);
i2c->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(i2c->clk))
return PTR_ERR(i2c->clk);
ret = clk_prepare_enable(i2c->clk);
if (ret)
return ret;
ret = of_property_read_u32(pdev->dev.of_node, "clock-frequency",
&clk_freq);
if (ret) {
dev_err(&pdev->dev, "clock-frequency not specified in DT\n");
goto err;
}
i2c->speed = clk_freq / 1000;
if (i2c->speed == 0) {
ret = -EINVAL;
dev_err(&pdev->dev, "clock-frequency minimum is 1000\n");
goto err;
}
jz4780_i2c_set_speed(i2c);
dev_info(&pdev->dev, "Bus frequency is %d KHz\n", i2c->speed);
tmp = jz4780_i2c_readw(i2c, JZ4780_I2C_CTRL);
tmp &= ~JZ4780_I2C_CTRL_STPHLD;
jz4780_i2c_writew(i2c, JZ4780_I2C_CTRL, tmp);
jz4780_i2c_writew(i2c, JZ4780_I2C_INTM, 0x0);
i2c->irq = platform_get_irq(pdev, 0);
ret = devm_request_irq(&pdev->dev, i2c->irq, jz4780_i2c_irq, 0,
dev_name(&pdev->dev), i2c);
if (ret)
goto err;
ret = i2c_add_adapter(&i2c->adap);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to add bus\n");
goto err;
}
return 0;
err:
clk_disable_unprepare(i2c->clk);
return ret;
}
static int jz4780_i2c_remove(struct platform_device *pdev)
{
struct jz4780_i2c *i2c = platform_get_drvdata(pdev);
clk_disable_unprepare(i2c->clk);
i2c_del_adapter(&i2c->adap);
return 0;
}
