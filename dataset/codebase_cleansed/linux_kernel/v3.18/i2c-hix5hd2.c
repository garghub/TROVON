static u32 hix5hd2_i2c_clr_pend_irq(struct hix5hd2_i2c_priv *priv)
{
u32 val = readl_relaxed(priv->regs + HIX5I2C_SR);
writel_relaxed(val, priv->regs + HIX5I2C_ICR);
return val;
}
static void hix5hd2_i2c_clr_all_irq(struct hix5hd2_i2c_priv *priv)
{
writel_relaxed(I2C_CLEAR_ALL, priv->regs + HIX5I2C_ICR);
}
static void hix5hd2_i2c_disable_irq(struct hix5hd2_i2c_priv *priv)
{
writel_relaxed(0, priv->regs + HIX5I2C_CTRL);
}
static void hix5hd2_i2c_enable_irq(struct hix5hd2_i2c_priv *priv)
{
writel_relaxed(I2C_ENABLE | I2C_UNMASK_TOTAL | I2C_UNMASK_ALL,
priv->regs + HIX5I2C_CTRL);
}
static void hix5hd2_i2c_drv_setrate(struct hix5hd2_i2c_priv *priv)
{
u32 rate, val;
u32 scl, sysclock;
val = readl_relaxed(priv->regs + HIX5I2C_CTRL);
writel_relaxed(val & (~I2C_UNMASK_TOTAL), priv->regs + HIX5I2C_CTRL);
rate = priv->freq;
sysclock = clk_get_rate(priv->clk);
scl = (sysclock / (rate * 2)) / 2 - 1;
writel_relaxed(scl, priv->regs + HIX5I2C_SCL_H);
writel_relaxed(scl, priv->regs + HIX5I2C_SCL_L);
writel_relaxed(val, priv->regs + HIX5I2C_CTRL);
dev_dbg(priv->dev, "%s: sysclock=%d, rate=%d, scl=%d\n",
__func__, sysclock, rate, scl);
}
static void hix5hd2_i2c_init(struct hix5hd2_i2c_priv *priv)
{
hix5hd2_i2c_disable_irq(priv);
hix5hd2_i2c_drv_setrate(priv);
hix5hd2_i2c_clr_all_irq(priv);
hix5hd2_i2c_enable_irq(priv);
}
static void hix5hd2_i2c_reset(struct hix5hd2_i2c_priv *priv)
{
clk_disable_unprepare(priv->clk);
msleep(20);
clk_prepare_enable(priv->clk);
hix5hd2_i2c_init(priv);
}
static int hix5hd2_i2c_wait_bus_idle(struct hix5hd2_i2c_priv *priv)
{
unsigned long stop_time;
u32 int_status;
stop_time = jiffies + msecs_to_jiffies(100);
do {
int_status = hix5hd2_i2c_clr_pend_irq(priv);
if (!(int_status & I2C_BUSY))
return 0;
usleep_range(50, 200);
} while (time_before(jiffies, stop_time));
return -EBUSY;
}
static void hix5hd2_rw_over(struct hix5hd2_i2c_priv *priv)
{
if (priv->state == HIX5I2C_STAT_SND_STOP)
dev_dbg(priv->dev, "%s: rw and send stop over\n", __func__);
else
dev_dbg(priv->dev, "%s: have not data to send\n", __func__);
priv->state = HIX5I2C_STAT_RW_SUCCESS;
priv->err = 0;
}
static void hix5hd2_rw_handle_stop(struct hix5hd2_i2c_priv *priv)
{
if (priv->stop) {
priv->state = HIX5I2C_STAT_SND_STOP;
writel_relaxed(I2C_STOP, priv->regs + HIX5I2C_COM);
} else {
hix5hd2_rw_over(priv);
}
}
static void hix5hd2_read_handle(struct hix5hd2_i2c_priv *priv)
{
if (priv->msg_len == 1) {
writel_relaxed(I2C_READ | I2C_NO_ACK, priv->regs + HIX5I2C_COM);
} else if (priv->msg_len > 1) {
writel_relaxed(I2C_READ, priv->regs + HIX5I2C_COM);
} else {
hix5hd2_rw_handle_stop(priv);
}
}
static void hix5hd2_write_handle(struct hix5hd2_i2c_priv *priv)
{
u8 data;
if (priv->msg_len > 0) {
data = priv->msg->buf[priv->msg_idx++];
writel_relaxed(data, priv->regs + HIX5I2C_TXR);
writel_relaxed(I2C_WRITE, priv->regs + HIX5I2C_COM);
} else {
hix5hd2_rw_handle_stop(priv);
}
}
static int hix5hd2_rw_preprocess(struct hix5hd2_i2c_priv *priv)
{
u8 data;
if (priv->state == HIX5I2C_STAT_INIT) {
priv->state = HIX5I2C_STAT_RW;
} else if (priv->state == HIX5I2C_STAT_RW) {
if (priv->msg->flags & I2C_M_RD) {
data = readl_relaxed(priv->regs + HIX5I2C_RXR);
priv->msg->buf[priv->msg_idx++] = data;
}
priv->msg_len--;
} else {
dev_dbg(priv->dev, "%s: error: priv->state = %d, msg_len = %d\n",
__func__, priv->state, priv->msg_len);
return -EAGAIN;
}
return 0;
}
static irqreturn_t hix5hd2_i2c_irq(int irqno, void *dev_id)
{
struct hix5hd2_i2c_priv *priv = dev_id;
u32 int_status;
int ret;
spin_lock(&priv->lock);
int_status = hix5hd2_i2c_clr_pend_irq(priv);
if (int_status & I2C_ARBITRATE_INTR) {
dev_dbg(priv->dev, "ARB bus loss\n");
priv->err = -EAGAIN;
priv->state = HIX5I2C_STAT_RW_ERR;
goto stop;
} else if (int_status & I2C_ACK_INTR) {
dev_dbg(priv->dev, "No ACK from device\n");
priv->err = -ENXIO;
priv->state = HIX5I2C_STAT_RW_ERR;
goto stop;
}
if (int_status & I2C_OVER_INTR) {
if (priv->msg_len > 0) {
ret = hix5hd2_rw_preprocess(priv);
if (ret) {
priv->err = ret;
priv->state = HIX5I2C_STAT_RW_ERR;
goto stop;
}
if (priv->msg->flags & I2C_M_RD)
hix5hd2_read_handle(priv);
else
hix5hd2_write_handle(priv);
} else {
hix5hd2_rw_over(priv);
}
}
stop:
if ((priv->state == HIX5I2C_STAT_RW_SUCCESS &&
priv->msg->len == priv->msg_idx) ||
(priv->state == HIX5I2C_STAT_RW_ERR)) {
hix5hd2_i2c_disable_irq(priv);
hix5hd2_i2c_clr_pend_irq(priv);
complete(&priv->msg_complete);
}
spin_unlock(&priv->lock);
return IRQ_HANDLED;
}
static void hix5hd2_i2c_message_start(struct hix5hd2_i2c_priv *priv, int stop)
{
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
hix5hd2_i2c_clr_all_irq(priv);
hix5hd2_i2c_enable_irq(priv);
if (priv->msg->flags & I2C_M_RD)
writel_relaxed((priv->msg->addr << 1) | HIX5I2C_READ_OPERATION,
priv->regs + HIX5I2C_TXR);
else
writel_relaxed(priv->msg->addr << 1,
priv->regs + HIX5I2C_TXR);
writel_relaxed(I2C_WRITE | I2C_START, priv->regs + HIX5I2C_COM);
spin_unlock_irqrestore(&priv->lock, flags);
}
static int hix5hd2_i2c_xfer_msg(struct hix5hd2_i2c_priv *priv,
struct i2c_msg *msgs, int stop)
{
unsigned long timeout;
int ret;
priv->msg = msgs;
priv->msg_idx = 0;
priv->msg_len = priv->msg->len;
priv->stop = stop;
priv->err = 0;
priv->state = HIX5I2C_STAT_INIT;
reinit_completion(&priv->msg_complete);
hix5hd2_i2c_message_start(priv, stop);
timeout = wait_for_completion_timeout(&priv->msg_complete,
priv->adap.timeout);
if (timeout == 0) {
priv->state = HIX5I2C_STAT_RW_ERR;
priv->err = -ETIMEDOUT;
dev_warn(priv->dev, "%s timeout=%d\n",
msgs->flags & I2C_M_RD ? "rx" : "tx",
priv->adap.timeout);
}
ret = priv->state;
if (priv->state == HIX5I2C_STAT_RW_SUCCESS && stop)
ret = hix5hd2_i2c_wait_bus_idle(priv);
if (ret < 0)
hix5hd2_i2c_reset(priv);
return priv->err;
}
static int hix5hd2_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
struct hix5hd2_i2c_priv *priv = i2c_get_adapdata(adap);
int i, ret, stop;
pm_runtime_get_sync(priv->dev);
for (i = 0; i < num; i++, msgs++) {
stop = (i == num - 1);
ret = hix5hd2_i2c_xfer_msg(priv, msgs, stop);
if (ret < 0)
goto out;
}
if (i == num) {
ret = num;
} else {
if (i == 1)
ret = -EREMOTEIO;
else
ret = i;
dev_warn(priv->dev, "xfer message failed\n");
}
out:
pm_runtime_mark_last_busy(priv->dev);
pm_runtime_put_autosuspend(priv->dev);
return ret;
}
static u32 hix5hd2_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}
static int hix5hd2_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct hix5hd2_i2c_priv *priv;
struct resource *mem;
unsigned int freq;
int irq, ret;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (of_property_read_u32(np, "clock-frequency", &freq)) {
priv->freq = 100000;
} else {
if (freq > HIX5I2C_MAX_FREQ) {
priv->freq = HIX5I2C_MAX_FREQ;
dev_warn(priv->dev, "use max freq %d instead\n",
HIX5I2C_MAX_FREQ);
} else {
priv->freq = freq;
}
}
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(priv->regs))
return PTR_ERR(priv->regs);
irq = platform_get_irq(pdev, 0);
if (irq <= 0) {
dev_err(&pdev->dev, "cannot find HS-I2C IRQ\n");
return irq;
}
priv->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(priv->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
return PTR_ERR(priv->clk);
}
clk_prepare_enable(priv->clk);
strlcpy(priv->adap.name, "hix5hd2-i2c", sizeof(priv->adap.name));
priv->dev = &pdev->dev;
priv->adap.owner = THIS_MODULE;
priv->adap.algo = &hix5hd2_i2c_algorithm;
priv->adap.retries = 3;
priv->adap.dev.of_node = np;
priv->adap.algo_data = priv;
priv->adap.dev.parent = &pdev->dev;
i2c_set_adapdata(&priv->adap, priv);
platform_set_drvdata(pdev, priv);
spin_lock_init(&priv->lock);
init_completion(&priv->msg_complete);
hix5hd2_i2c_init(priv);
ret = devm_request_irq(&pdev->dev, irq, hix5hd2_i2c_irq,
IRQF_NO_SUSPEND | IRQF_ONESHOT,
dev_name(&pdev->dev), priv);
if (ret != 0) {
dev_err(&pdev->dev, "cannot request HS-I2C IRQ %d\n", irq);
goto err_clk;
}
pm_suspend_ignore_children(&pdev->dev, true);
pm_runtime_set_autosuspend_delay(priv->dev, MSEC_PER_SEC);
pm_runtime_use_autosuspend(priv->dev);
pm_runtime_set_active(priv->dev);
pm_runtime_enable(priv->dev);
ret = i2c_add_adapter(&priv->adap);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add bus to i2c core\n");
goto err_runtime;
}
return ret;
err_runtime:
pm_runtime_disable(priv->dev);
pm_runtime_set_suspended(priv->dev);
err_clk:
clk_disable_unprepare(priv->clk);
return ret;
}
static int hix5hd2_i2c_remove(struct platform_device *pdev)
{
struct hix5hd2_i2c_priv *priv = platform_get_drvdata(pdev);
i2c_del_adapter(&priv->adap);
pm_runtime_disable(priv->dev);
pm_runtime_set_suspended(priv->dev);
return 0;
}
static int hix5hd2_i2c_runtime_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct hix5hd2_i2c_priv *priv = platform_get_drvdata(pdev);
clk_disable_unprepare(priv->clk);
return 0;
}
static int hix5hd2_i2c_runtime_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct hix5hd2_i2c_priv *priv = platform_get_drvdata(pdev);
clk_prepare_enable(priv->clk);
hix5hd2_i2c_init(priv);
return 0;
}
