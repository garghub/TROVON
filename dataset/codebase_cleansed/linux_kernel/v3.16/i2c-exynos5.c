static inline struct exynos_hsi2c_variant *exynos5_i2c_get_variant
(struct platform_device *pdev)
{
const struct of_device_id *match;
match = of_match_node(exynos5_i2c_match, pdev->dev.of_node);
return (struct exynos_hsi2c_variant *)match->data;
}
static void exynos5_i2c_clr_pend_irq(struct exynos5_i2c *i2c)
{
writel(readl(i2c->regs + HSI2C_INT_STATUS),
i2c->regs + HSI2C_INT_STATUS);
}
static int exynos5_i2c_set_timing(struct exynos5_i2c *i2c, int mode)
{
u32 i2c_timing_s1;
u32 i2c_timing_s2;
u32 i2c_timing_s3;
u32 i2c_timing_sla;
unsigned int t_start_su, t_start_hd;
unsigned int t_stop_su;
unsigned int t_data_su, t_data_hd;
unsigned int t_scl_l, t_scl_h;
unsigned int t_sr_release;
unsigned int t_ftl_cycle;
unsigned int clkin = clk_get_rate(i2c->clk);
unsigned int div, utemp0 = 0, utemp1 = 0, clk_cycle;
unsigned int op_clk = (mode == HSI2C_HIGH_SPD) ?
i2c->hs_clock : i2c->fs_clock;
t_ftl_cycle = (readl(i2c->regs + HSI2C_CONF) >> 16) & 0x7;
utemp0 = (clkin / op_clk) - 8 - 2 * t_ftl_cycle;
for (div = 0; div < 256; div++) {
utemp1 = utemp0 / (div + 1);
if ((utemp1 < 512) && (utemp1 > 4)) {
clk_cycle = utemp1 - 2;
break;
} else if (div == 255) {
dev_warn(i2c->dev, "Failed to calculate divisor");
return -EINVAL;
}
}
t_scl_l = clk_cycle / 2;
t_scl_h = clk_cycle / 2;
t_start_su = t_scl_l;
t_start_hd = t_scl_l;
t_stop_su = t_scl_l;
t_data_su = t_scl_l / 2;
t_data_hd = t_scl_l / 2;
t_sr_release = clk_cycle;
i2c_timing_s1 = t_start_su << 24 | t_start_hd << 16 | t_stop_su << 8;
i2c_timing_s2 = t_data_su << 24 | t_scl_l << 8 | t_scl_h << 0;
i2c_timing_s3 = div << 16 | t_sr_release << 0;
i2c_timing_sla = t_data_hd << 0;
dev_dbg(i2c->dev, "tSTART_SU: %X, tSTART_HD: %X, tSTOP_SU: %X\n",
t_start_su, t_start_hd, t_stop_su);
dev_dbg(i2c->dev, "tDATA_SU: %X, tSCL_L: %X, tSCL_H: %X\n",
t_data_su, t_scl_l, t_scl_h);
dev_dbg(i2c->dev, "nClkDiv: %X, tSR_RELEASE: %X\n",
div, t_sr_release);
dev_dbg(i2c->dev, "tDATA_HD: %X\n", t_data_hd);
if (mode == HSI2C_HIGH_SPD) {
writel(i2c_timing_s1, i2c->regs + HSI2C_TIMING_HS1);
writel(i2c_timing_s2, i2c->regs + HSI2C_TIMING_HS2);
writel(i2c_timing_s3, i2c->regs + HSI2C_TIMING_HS3);
} else {
writel(i2c_timing_s1, i2c->regs + HSI2C_TIMING_FS1);
writel(i2c_timing_s2, i2c->regs + HSI2C_TIMING_FS2);
writel(i2c_timing_s3, i2c->regs + HSI2C_TIMING_FS3);
}
writel(i2c_timing_sla, i2c->regs + HSI2C_TIMING_SLA);
return 0;
}
static int exynos5_hsi2c_clock_setup(struct exynos5_i2c *i2c)
{
if (exynos5_i2c_set_timing(i2c, HSI2C_FAST_SPD)) {
dev_err(i2c->dev, "HSI2C FS Clock set up failed\n");
return -EINVAL;
}
if (i2c->speed_mode == HSI2C_HIGH_SPD) {
if (exynos5_i2c_set_timing(i2c, HSI2C_HIGH_SPD)) {
dev_err(i2c->dev, "HSI2C HS Clock set up failed\n");
return -EINVAL;
}
}
return 0;
}
static void exynos5_i2c_init(struct exynos5_i2c *i2c)
{
u32 i2c_conf = readl(i2c->regs + HSI2C_CONF);
u32 i2c_timeout = readl(i2c->regs + HSI2C_TIMEOUT);
i2c_timeout &= ~HSI2C_TIMEOUT_EN;
writel(i2c_timeout, i2c->regs + HSI2C_TIMEOUT);
writel((HSI2C_FUNC_MODE_I2C | HSI2C_MASTER),
i2c->regs + HSI2C_CTL);
writel(HSI2C_TRAILING_COUNT, i2c->regs + HSI2C_TRAILIG_CTL);
if (i2c->speed_mode == HSI2C_HIGH_SPD) {
writel(HSI2C_MASTER_ID(MASTER_ID(i2c->adap.nr)),
i2c->regs + HSI2C_ADDR);
i2c_conf |= HSI2C_HS_MODE;
}
writel(i2c_conf | HSI2C_AUTO_MODE, i2c->regs + HSI2C_CONF);
}
static void exynos5_i2c_reset(struct exynos5_i2c *i2c)
{
u32 i2c_ctl;
i2c_ctl = readl(i2c->regs + HSI2C_CTL);
i2c_ctl |= HSI2C_SW_RST;
writel(i2c_ctl, i2c->regs + HSI2C_CTL);
i2c_ctl = readl(i2c->regs + HSI2C_CTL);
i2c_ctl &= ~HSI2C_SW_RST;
writel(i2c_ctl, i2c->regs + HSI2C_CTL);
exynos5_hsi2c_clock_setup(i2c);
exynos5_i2c_init(i2c);
}
static irqreturn_t exynos5_i2c_irq(int irqno, void *dev_id)
{
struct exynos5_i2c *i2c = dev_id;
u32 fifo_level, int_status, fifo_status, trans_status;
unsigned char byte;
int len = 0;
i2c->state = -EINVAL;
spin_lock(&i2c->lock);
int_status = readl(i2c->regs + HSI2C_INT_STATUS);
writel(int_status, i2c->regs + HSI2C_INT_STATUS);
fifo_status = readl(i2c->regs + HSI2C_FIFO_STATUS);
if (int_status & HSI2C_INT_I2C) {
trans_status = readl(i2c->regs + HSI2C_TRANS_STATUS);
if (trans_status & HSI2C_NO_DEV_ACK) {
dev_dbg(i2c->dev, "No ACK from device\n");
i2c->state = -ENXIO;
goto stop;
} else if (trans_status & HSI2C_NO_DEV) {
dev_dbg(i2c->dev, "No device\n");
i2c->state = -ENXIO;
goto stop;
} else if (trans_status & HSI2C_TRANS_ABORT) {
dev_dbg(i2c->dev, "Deal with arbitration lose\n");
i2c->state = -EAGAIN;
goto stop;
} else if (trans_status & HSI2C_TIMEOUT_AUTO) {
dev_dbg(i2c->dev, "Accessing device timed out\n");
i2c->state = -EAGAIN;
goto stop;
} else if (trans_status & HSI2C_TRANS_DONE) {
i2c->trans_done = 1;
i2c->state = 0;
}
}
if ((i2c->msg->flags & I2C_M_RD) && (int_status &
(HSI2C_INT_TRAILING | HSI2C_INT_RX_ALMOSTFULL))) {
fifo_status = readl(i2c->regs + HSI2C_FIFO_STATUS);
fifo_level = HSI2C_RX_FIFO_LVL(fifo_status);
len = min(fifo_level, i2c->msg->len - i2c->msg_ptr);
while (len > 0) {
byte = (unsigned char)
readl(i2c->regs + HSI2C_RX_DATA);
i2c->msg->buf[i2c->msg_ptr++] = byte;
len--;
}
i2c->state = 0;
} else if (int_status & HSI2C_INT_TX_ALMOSTEMPTY) {
fifo_status = readl(i2c->regs + HSI2C_FIFO_STATUS);
fifo_level = HSI2C_TX_FIFO_LVL(fifo_status);
len = i2c->variant->fifo_depth - fifo_level;
if (len > (i2c->msg->len - i2c->msg_ptr))
len = i2c->msg->len - i2c->msg_ptr;
while (len > 0) {
byte = i2c->msg->buf[i2c->msg_ptr++];
writel(byte, i2c->regs + HSI2C_TX_DATA);
len--;
}
i2c->state = 0;
}
stop:
if ((i2c->trans_done && (i2c->msg->len == i2c->msg_ptr)) ||
(i2c->state < 0)) {
writel(0, i2c->regs + HSI2C_INT_ENABLE);
exynos5_i2c_clr_pend_irq(i2c);
complete(&i2c->msg_complete);
}
spin_unlock(&i2c->lock);
return IRQ_HANDLED;
}
static int exynos5_i2c_wait_bus_idle(struct exynos5_i2c *i2c)
{
unsigned long stop_time;
u32 trans_status;
stop_time = jiffies + msecs_to_jiffies(100) + 1;
do {
trans_status = readl(i2c->regs + HSI2C_TRANS_STATUS);
if (!(trans_status & HSI2C_MASTER_BUSY))
return 0;
usleep_range(50, 200);
} while (time_before(jiffies, stop_time));
return -EBUSY;
}
static void exynos5_i2c_message_start(struct exynos5_i2c *i2c, int stop)
{
u32 i2c_ctl;
u32 int_en = HSI2C_INT_I2C_EN;
u32 i2c_auto_conf = 0;
u32 fifo_ctl;
unsigned long flags;
unsigned short trig_lvl;
i2c_ctl = readl(i2c->regs + HSI2C_CTL);
i2c_ctl &= ~(HSI2C_TXCHON | HSI2C_RXCHON);
fifo_ctl = HSI2C_RXFIFO_EN | HSI2C_TXFIFO_EN;
if (i2c->msg->flags & I2C_M_RD) {
i2c_ctl |= HSI2C_RXCHON;
i2c_auto_conf = HSI2C_READ_WRITE;
trig_lvl = (i2c->msg->len > i2c->variant->fifo_depth) ?
(i2c->variant->fifo_depth * 3 / 4) : i2c->msg->len;
fifo_ctl |= HSI2C_RXFIFO_TRIGGER_LEVEL(trig_lvl);
int_en |= (HSI2C_INT_RX_ALMOSTFULL_EN |
HSI2C_INT_TRAILING_EN);
} else {
i2c_ctl |= HSI2C_TXCHON;
trig_lvl = (i2c->msg->len > i2c->variant->fifo_depth) ?
(i2c->variant->fifo_depth * 1 / 4) : i2c->msg->len;
fifo_ctl |= HSI2C_TXFIFO_TRIGGER_LEVEL(trig_lvl);
int_en |= HSI2C_INT_TX_ALMOSTEMPTY_EN;
}
writel(HSI2C_SLV_ADDR_MAS(i2c->msg->addr), i2c->regs + HSI2C_ADDR);
writel(fifo_ctl, i2c->regs + HSI2C_FIFO_CTL);
writel(i2c_ctl, i2c->regs + HSI2C_CTL);
spin_lock_irqsave(&i2c->lock, flags);
writel(int_en, i2c->regs + HSI2C_INT_ENABLE);
if (stop == 1)
i2c_auto_conf |= HSI2C_STOP_AFTER_TRANS;
i2c_auto_conf |= i2c->msg->len;
i2c_auto_conf |= HSI2C_MASTER_RUN;
writel(i2c_auto_conf, i2c->regs + HSI2C_AUTO_CONF);
spin_unlock_irqrestore(&i2c->lock, flags);
}
static int exynos5_i2c_xfer_msg(struct exynos5_i2c *i2c,
struct i2c_msg *msgs, int stop)
{
unsigned long timeout;
int ret;
i2c->msg = msgs;
i2c->msg_ptr = 0;
i2c->trans_done = 0;
reinit_completion(&i2c->msg_complete);
exynos5_i2c_message_start(i2c, stop);
timeout = wait_for_completion_timeout(&i2c->msg_complete,
EXYNOS5_I2C_TIMEOUT);
if (timeout == 0)
ret = -ETIMEDOUT;
else
ret = i2c->state;
if (ret == 0 && stop)
ret = exynos5_i2c_wait_bus_idle(i2c);
if (ret < 0) {
exynos5_i2c_reset(i2c);
if (ret == -ETIMEDOUT)
dev_warn(i2c->dev, "%s timeout\n",
(msgs->flags & I2C_M_RD) ? "rx" : "tx");
}
return ret;
}
static int exynos5_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs, int num)
{
struct exynos5_i2c *i2c = adap->algo_data;
int i = 0, ret = 0, stop = 0;
if (i2c->suspended) {
dev_err(i2c->dev, "HS-I2C is not initialized.\n");
return -EIO;
}
clk_prepare_enable(i2c->clk);
for (i = 0; i < num; i++, msgs++) {
stop = (i == num - 1);
ret = exynos5_i2c_xfer_msg(i2c, msgs, stop);
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
dev_warn(i2c->dev, "xfer message failed\n");
}
out:
clk_disable_unprepare(i2c->clk);
return ret;
}
static u32 exynos5_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}
static int exynos5_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct exynos5_i2c *i2c;
struct resource *mem;
unsigned int op_clock;
int ret;
i2c = devm_kzalloc(&pdev->dev, sizeof(struct exynos5_i2c), GFP_KERNEL);
if (!i2c)
return -ENOMEM;
if (of_property_read_u32(np, "clock-frequency", &op_clock)) {
i2c->speed_mode = HSI2C_FAST_SPD;
i2c->fs_clock = HSI2C_FS_TX_CLOCK;
} else {
if (op_clock >= HSI2C_HS_TX_CLOCK) {
i2c->speed_mode = HSI2C_HIGH_SPD;
i2c->fs_clock = HSI2C_FS_TX_CLOCK;
i2c->hs_clock = op_clock;
} else {
i2c->speed_mode = HSI2C_FAST_SPD;
i2c->fs_clock = op_clock;
}
}
strlcpy(i2c->adap.name, "exynos5-i2c", sizeof(i2c->adap.name));
i2c->adap.owner = THIS_MODULE;
i2c->adap.algo = &exynos5_i2c_algorithm;
i2c->adap.retries = 3;
i2c->dev = &pdev->dev;
i2c->clk = devm_clk_get(&pdev->dev, "hsi2c");
if (IS_ERR(i2c->clk)) {
dev_err(&pdev->dev, "cannot get clock\n");
return -ENOENT;
}
clk_prepare_enable(i2c->clk);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c->regs = devm_ioremap_resource(&pdev->dev, mem);
if (IS_ERR(i2c->regs)) {
ret = PTR_ERR(i2c->regs);
goto err_clk;
}
i2c->adap.dev.of_node = np;
i2c->adap.algo_data = i2c;
i2c->adap.dev.parent = &pdev->dev;
exynos5_i2c_clr_pend_irq(i2c);
spin_lock_init(&i2c->lock);
init_completion(&i2c->msg_complete);
i2c->irq = ret = platform_get_irq(pdev, 0);
if (ret <= 0) {
dev_err(&pdev->dev, "cannot find HS-I2C IRQ\n");
ret = -EINVAL;
goto err_clk;
}
ret = devm_request_irq(&pdev->dev, i2c->irq, exynos5_i2c_irq,
IRQF_NO_SUSPEND | IRQF_ONESHOT,
dev_name(&pdev->dev), i2c);
if (ret != 0) {
dev_err(&pdev->dev, "cannot request HS-I2C IRQ %d\n", i2c->irq);
goto err_clk;
}
ret = exynos5_hsi2c_clock_setup(i2c);
if (ret)
goto err_clk;
i2c->variant = exynos5_i2c_get_variant(pdev);
exynos5_i2c_reset(i2c);
ret = i2c_add_adapter(&i2c->adap);
if (ret < 0) {
dev_err(&pdev->dev, "failed to add bus to i2c core\n");
goto err_clk;
}
platform_set_drvdata(pdev, i2c);
err_clk:
clk_disable_unprepare(i2c->clk);
return ret;
}
static int exynos5_i2c_remove(struct platform_device *pdev)
{
struct exynos5_i2c *i2c = platform_get_drvdata(pdev);
i2c_del_adapter(&i2c->adap);
return 0;
}
static int exynos5_i2c_suspend_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct exynos5_i2c *i2c = platform_get_drvdata(pdev);
i2c->suspended = 1;
return 0;
}
static int exynos5_i2c_resume_noirq(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct exynos5_i2c *i2c = platform_get_drvdata(pdev);
int ret = 0;
clk_prepare_enable(i2c->clk);
ret = exynos5_hsi2c_clock_setup(i2c);
if (ret) {
clk_disable_unprepare(i2c->clk);
return ret;
}
exynos5_i2c_init(i2c);
clk_disable_unprepare(i2c->clk);
i2c->suspended = 0;
return 0;
}
