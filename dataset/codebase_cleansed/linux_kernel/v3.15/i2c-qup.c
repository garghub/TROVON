static irqreturn_t qup_i2c_interrupt(int irq, void *dev)
{
struct qup_i2c_dev *qup = dev;
u32 bus_err;
u32 qup_err;
u32 opflags;
bus_err = readl(qup->base + QUP_I2C_STATUS);
qup_err = readl(qup->base + QUP_ERROR_FLAGS);
opflags = readl(qup->base + QUP_OPERATIONAL);
if (!qup->msg) {
writel(QUP_RESET_STATE, qup->base + QUP_STATE);
return IRQ_HANDLED;
}
bus_err &= I2C_STATUS_ERROR_MASK;
qup_err &= QUP_STATUS_ERROR_FLAGS;
if (qup_err) {
writel(qup_err, qup->base + QUP_ERROR_FLAGS);
goto done;
}
if (bus_err) {
writel(QUP_RESET_STATE, qup->base + QUP_STATE);
goto done;
}
if (opflags & QUP_IN_SVC_FLAG)
writel(QUP_IN_SVC_FLAG, qup->base + QUP_OPERATIONAL);
if (opflags & QUP_OUT_SVC_FLAG)
writel(QUP_OUT_SVC_FLAG, qup->base + QUP_OPERATIONAL);
done:
qup->qup_err = qup_err;
qup->bus_err = bus_err;
complete(&qup->xfer);
return IRQ_HANDLED;
}
static int qup_i2c_poll_state_mask(struct qup_i2c_dev *qup,
u32 req_state, u32 req_mask)
{
int retries = 1;
u32 state;
do {
state = readl(qup->base + QUP_STATE);
if (state & QUP_STATE_VALID &&
(state & req_mask) == req_state)
return 0;
udelay(1);
} while (retries--);
return -ETIMEDOUT;
}
static int qup_i2c_poll_state(struct qup_i2c_dev *qup, u32 req_state)
{
return qup_i2c_poll_state_mask(qup, req_state, QUP_STATE_MASK);
}
static int qup_i2c_poll_state_valid(struct qup_i2c_dev *qup)
{
return qup_i2c_poll_state_mask(qup, 0, 0);
}
static int qup_i2c_poll_state_i2c_master(struct qup_i2c_dev *qup)
{
return qup_i2c_poll_state_mask(qup, QUP_I2C_MAST_GEN, QUP_I2C_MAST_GEN);
}
static int qup_i2c_change_state(struct qup_i2c_dev *qup, u32 state)
{
if (qup_i2c_poll_state_valid(qup) != 0)
return -EIO;
writel(state, qup->base + QUP_STATE);
if (qup_i2c_poll_state(qup, state) != 0)
return -EIO;
return 0;
}
static int qup_i2c_wait_writeready(struct qup_i2c_dev *qup)
{
unsigned long timeout;
u32 opflags;
u32 status;
timeout = jiffies + HZ;
for (;;) {
opflags = readl(qup->base + QUP_OPERATIONAL);
status = readl(qup->base + QUP_I2C_STATUS);
if (!(opflags & QUP_OUT_NOT_EMPTY) &&
!(status & I2C_STATUS_BUS_ACTIVE))
return 0;
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
usleep_range(qup->one_byte_t, qup->one_byte_t * 2);
}
}
static void qup_i2c_set_write_mode(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
int total = msg->len + 1;
if (total < qup->out_fifo_sz) {
writel(QUP_REPACK_EN, qup->base + QUP_IO_MODE);
writel(total, qup->base + QUP_MX_WRITE_CNT);
} else {
writel(QUP_OUTPUT_BLK_MODE | QUP_REPACK_EN,
qup->base + QUP_IO_MODE);
writel(total, qup->base + QUP_MX_OUTPUT_CNT);
}
}
static void qup_i2c_issue_write(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
u32 addr = msg->addr << 1;
u32 qup_tag;
u32 opflags;
int idx;
u32 val;
if (qup->pos == 0) {
val = QUP_TAG_START | addr;
idx = 1;
} else {
val = 0;
idx = 0;
}
while (qup->pos < msg->len) {
opflags = readl(qup->base + QUP_OPERATIONAL);
if (opflags & QUP_OUT_FULL)
break;
if (qup->pos == msg->len - 1)
qup_tag = QUP_TAG_STOP;
else
qup_tag = QUP_TAG_DATA;
if (idx & 1)
val |= (qup_tag | msg->buf[qup->pos]) << QUP_MSW_SHIFT;
else
val = qup_tag | msg->buf[qup->pos];
if (idx & 1 || qup->pos == msg->len - 1)
writel(val, qup->base + QUP_OUT_FIFO_BASE);
qup->pos++;
idx++;
}
}
static int qup_i2c_write_one(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
unsigned long left;
int ret;
qup->msg = msg;
qup->pos = 0;
enable_irq(qup->irq);
qup_i2c_set_write_mode(qup, msg);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
writel(qup->clk_ctl, qup->base + QUP_I2C_CLK_CTL);
do {
ret = qup_i2c_change_state(qup, QUP_PAUSE_STATE);
if (ret)
goto err;
qup_i2c_issue_write(qup, msg);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
left = wait_for_completion_timeout(&qup->xfer, HZ);
if (!left) {
writel(1, qup->base + QUP_SW_RESET);
ret = -ETIMEDOUT;
goto err;
}
if (qup->bus_err || qup->qup_err) {
if (qup->bus_err & QUP_I2C_NACK_FLAG)
dev_err(qup->dev, "NACK from %x\n", msg->addr);
ret = -EIO;
goto err;
}
} while (qup->pos < msg->len);
ret = qup_i2c_wait_writeready(qup);
err:
disable_irq(qup->irq);
qup->msg = NULL;
return ret;
}
static void qup_i2c_set_read_mode(struct qup_i2c_dev *qup, int len)
{
if (len < qup->in_fifo_sz) {
writel(QUP_REPACK_EN, qup->base + QUP_IO_MODE);
writel(len, qup->base + QUP_MX_READ_CNT);
} else {
writel(QUP_INPUT_BLK_MODE | QUP_REPACK_EN,
qup->base + QUP_IO_MODE);
writel(len, qup->base + QUP_MX_INPUT_CNT);
}
}
static void qup_i2c_issue_read(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
u32 addr, len, val;
addr = (msg->addr << 1) | 1;
len = (msg->len == QUP_READ_LIMIT) ? 0 : msg->len;
val = ((QUP_TAG_REC | len) << QUP_MSW_SHIFT) | QUP_TAG_START | addr;
writel(val, qup->base + QUP_OUT_FIFO_BASE);
}
static void qup_i2c_read_fifo(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
u32 opflags;
u32 val = 0;
int idx;
for (idx = 0; qup->pos < msg->len; idx++) {
if ((idx & 1) == 0) {
opflags = readl(qup->base + QUP_OPERATIONAL);
if (!(opflags & QUP_IN_NOT_EMPTY))
break;
val = readl(qup->base + QUP_IN_FIFO_BASE);
msg->buf[qup->pos++] = val & 0xFF;
} else {
msg->buf[qup->pos++] = val >> QUP_MSW_SHIFT;
}
}
}
static int qup_i2c_read_one(struct qup_i2c_dev *qup, struct i2c_msg *msg)
{
unsigned long left;
int ret;
if (msg->len > QUP_READ_LIMIT) {
dev_err(qup->dev, "HW not capable of reads over %d bytes\n",
QUP_READ_LIMIT);
return -EINVAL;
}
qup->msg = msg;
qup->pos = 0;
enable_irq(qup->irq);
qup_i2c_set_read_mode(qup, msg->len);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
writel(qup->clk_ctl, qup->base + QUP_I2C_CLK_CTL);
ret = qup_i2c_change_state(qup, QUP_PAUSE_STATE);
if (ret)
goto err;
qup_i2c_issue_read(qup, msg);
ret = qup_i2c_change_state(qup, QUP_RUN_STATE);
if (ret)
goto err;
do {
left = wait_for_completion_timeout(&qup->xfer, HZ);
if (!left) {
writel(1, qup->base + QUP_SW_RESET);
ret = -ETIMEDOUT;
goto err;
}
if (qup->bus_err || qup->qup_err) {
if (qup->bus_err & QUP_I2C_NACK_FLAG)
dev_err(qup->dev, "NACK from %x\n", msg->addr);
ret = -EIO;
goto err;
}
qup_i2c_read_fifo(qup, msg);
} while (qup->pos < msg->len);
err:
disable_irq(qup->irq);
qup->msg = NULL;
return ret;
}
static int qup_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg msgs[],
int num)
{
struct qup_i2c_dev *qup = i2c_get_adapdata(adap);
int ret, idx;
ret = pm_runtime_get_sync(qup->dev);
if (ret < 0)
goto out;
writel(1, qup->base + QUP_SW_RESET);
ret = qup_i2c_poll_state(qup, QUP_RESET_STATE);
if (ret)
goto out;
writel(I2C_MINI_CORE | I2C_N_VAL, qup->base + QUP_CONFIG);
for (idx = 0; idx < num; idx++) {
if (msgs[idx].len == 0) {
ret = -EINVAL;
goto out;
}
if (qup_i2c_poll_state_i2c_master(qup)) {
ret = -EIO;
goto out;
}
if (msgs[idx].flags & I2C_M_RD)
ret = qup_i2c_read_one(qup, &msgs[idx]);
else
ret = qup_i2c_write_one(qup, &msgs[idx]);
if (ret)
break;
ret = qup_i2c_change_state(qup, QUP_RESET_STATE);
if (ret)
break;
}
if (ret == 0)
ret = num;
out:
pm_runtime_mark_last_busy(qup->dev);
pm_runtime_put_autosuspend(qup->dev);
return ret;
}
static u32 qup_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}
static void qup_i2c_enable_clocks(struct qup_i2c_dev *qup)
{
clk_prepare_enable(qup->clk);
clk_prepare_enable(qup->pclk);
}
static void qup_i2c_disable_clocks(struct qup_i2c_dev *qup)
{
u32 config;
qup_i2c_change_state(qup, QUP_RESET_STATE);
clk_disable_unprepare(qup->clk);
config = readl(qup->base + QUP_CONFIG);
config |= QUP_CLOCK_AUTO_GATE;
writel(config, qup->base + QUP_CONFIG);
clk_disable_unprepare(qup->pclk);
}
static int qup_i2c_probe(struct platform_device *pdev)
{
static const int blk_sizes[] = {4, 16, 32};
struct device_node *node = pdev->dev.of_node;
struct qup_i2c_dev *qup;
unsigned long one_bit_t;
struct resource *res;
u32 io_mode, hw_ver, size;
int ret, fs_div, hs_div;
int src_clk_freq;
u32 clk_freq = 100000;
qup = devm_kzalloc(&pdev->dev, sizeof(*qup), GFP_KERNEL);
if (!qup)
return -ENOMEM;
qup->dev = &pdev->dev;
init_completion(&qup->xfer);
platform_set_drvdata(pdev, qup);
of_property_read_u32(node, "clock-frequency", &clk_freq);
if (!clk_freq || clk_freq > 400000) {
dev_err(qup->dev, "clock frequency not supported %d\n",
clk_freq);
return -EINVAL;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
qup->base = devm_ioremap_resource(qup->dev, res);
if (IS_ERR(qup->base))
return PTR_ERR(qup->base);
qup->irq = platform_get_irq(pdev, 0);
if (qup->irq < 0) {
dev_err(qup->dev, "No IRQ defined\n");
return qup->irq;
}
qup->clk = devm_clk_get(qup->dev, "core");
if (IS_ERR(qup->clk)) {
dev_err(qup->dev, "Could not get core clock\n");
return PTR_ERR(qup->clk);
}
qup->pclk = devm_clk_get(qup->dev, "iface");
if (IS_ERR(qup->pclk)) {
dev_err(qup->dev, "Could not get iface clock\n");
return PTR_ERR(qup->pclk);
}
qup_i2c_enable_clocks(qup);
writel(1, qup->base + QUP_SW_RESET);
ret = qup_i2c_poll_state_valid(qup);
if (ret)
goto fail;
ret = devm_request_irq(qup->dev, qup->irq, qup_i2c_interrupt,
IRQF_TRIGGER_HIGH, "i2c_qup", qup);
if (ret) {
dev_err(qup->dev, "Request %d IRQ failed\n", qup->irq);
goto fail;
}
disable_irq(qup->irq);
hw_ver = readl(qup->base + QUP_HW_VERSION);
dev_dbg(qup->dev, "Revision %x\n", hw_ver);
io_mode = readl(qup->base + QUP_IO_MODE);
size = QUP_OUTPUT_BLOCK_SIZE(io_mode);
if (size >= ARRAY_SIZE(blk_sizes))
return -EIO;
qup->out_blk_sz = blk_sizes[size] / 2;
size = QUP_INPUT_BLOCK_SIZE(io_mode);
if (size >= ARRAY_SIZE(blk_sizes))
return -EIO;
qup->in_blk_sz = blk_sizes[size] / 2;
size = QUP_OUTPUT_FIFO_SIZE(io_mode);
qup->out_fifo_sz = qup->out_blk_sz * (2 << size);
size = QUP_INPUT_FIFO_SIZE(io_mode);
qup->in_fifo_sz = qup->in_blk_sz * (2 << size);
src_clk_freq = clk_get_rate(qup->clk);
fs_div = ((src_clk_freq / clk_freq) / 2) - 3;
hs_div = 3;
qup->clk_ctl = (hs_div << 8) | (fs_div & 0xff);
one_bit_t = (USEC_PER_SEC / clk_freq) + 1;
qup->one_byte_t = one_bit_t * 9;
dev_dbg(qup->dev, "IN:block:%d, fifo:%d, OUT:block:%d, fifo:%d\n",
qup->in_blk_sz, qup->in_fifo_sz,
qup->out_blk_sz, qup->out_fifo_sz);
i2c_set_adapdata(&qup->adap, qup);
qup->adap.algo = &qup_i2c_algo;
qup->adap.dev.parent = qup->dev;
qup->adap.dev.of_node = pdev->dev.of_node;
strlcpy(qup->adap.name, "QUP I2C adapter", sizeof(qup->adap.name));
ret = i2c_add_adapter(&qup->adap);
if (ret)
goto fail;
pm_runtime_set_autosuspend_delay(qup->dev, MSEC_PER_SEC);
pm_runtime_use_autosuspend(qup->dev);
pm_runtime_set_active(qup->dev);
pm_runtime_enable(qup->dev);
return 0;
fail:
qup_i2c_disable_clocks(qup);
return ret;
}
static int qup_i2c_remove(struct platform_device *pdev)
{
struct qup_i2c_dev *qup = platform_get_drvdata(pdev);
disable_irq(qup->irq);
qup_i2c_disable_clocks(qup);
i2c_del_adapter(&qup->adap);
pm_runtime_disable(qup->dev);
pm_runtime_set_suspended(qup->dev);
return 0;
}
static int qup_i2c_pm_suspend_runtime(struct device *device)
{
struct qup_i2c_dev *qup = dev_get_drvdata(device);
dev_dbg(device, "pm_runtime: suspending...\n");
qup_i2c_disable_clocks(qup);
return 0;
}
static int qup_i2c_pm_resume_runtime(struct device *device)
{
struct qup_i2c_dev *qup = dev_get_drvdata(device);
dev_dbg(device, "pm_runtime: resuming...\n");
qup_i2c_enable_clocks(qup);
return 0;
}
static int qup_i2c_suspend(struct device *device)
{
qup_i2c_pm_suspend_runtime(device);
return 0;
}
static int qup_i2c_resume(struct device *device)
{
qup_i2c_pm_resume_runtime(device);
pm_runtime_mark_last_busy(device);
pm_request_autosuspend(device);
return 0;
}
