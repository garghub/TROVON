static void bcm_kona_i2c_send_cmd_to_ctrl(struct bcm_kona_i2c_dev *dev,
enum bcm_kona_cmd_t cmd)
{
dev_dbg(dev->device, "%s, %d\n", __func__, cmd);
switch (cmd) {
case BCM_CMD_NOACTION:
writel((CS_CMD_CMD_NO_ACTION << CS_CMD_SHIFT) |
(CS_EN_CMD_ENABLE_BSC << CS_EN_SHIFT),
dev->base + CS_OFFSET);
break;
case BCM_CMD_START:
writel((CS_ACK_CMD_GEN_START << CS_ACK_SHIFT) |
(CS_CMD_CMD_START_RESTART << CS_CMD_SHIFT) |
(CS_EN_CMD_ENABLE_BSC << CS_EN_SHIFT),
dev->base + CS_OFFSET);
break;
case BCM_CMD_RESTART:
writel((CS_ACK_CMD_GEN_RESTART << CS_ACK_SHIFT) |
(CS_CMD_CMD_START_RESTART << CS_CMD_SHIFT) |
(CS_EN_CMD_ENABLE_BSC << CS_EN_SHIFT),
dev->base + CS_OFFSET);
break;
case BCM_CMD_STOP:
writel((CS_CMD_CMD_STOP << CS_CMD_SHIFT) |
(CS_EN_CMD_ENABLE_BSC << CS_EN_SHIFT),
dev->base + CS_OFFSET);
break;
default:
dev_err(dev->device, "Unknown command %d\n", cmd);
}
}
static void bcm_kona_i2c_enable_clock(struct bcm_kona_i2c_dev *dev)
{
writel(readl(dev->base + CLKEN_OFFSET) | CLKEN_CLKEN_MASK,
dev->base + CLKEN_OFFSET);
}
static void bcm_kona_i2c_disable_clock(struct bcm_kona_i2c_dev *dev)
{
writel(readl(dev->base + CLKEN_OFFSET) & ~CLKEN_CLKEN_MASK,
dev->base + CLKEN_OFFSET);
}
static irqreturn_t bcm_kona_i2c_isr(int irq, void *devid)
{
struct bcm_kona_i2c_dev *dev = devid;
uint32_t status = readl(dev->base + ISR_OFFSET);
if ((status & ~ISR_RESERVED_MASK) == 0)
return IRQ_NONE;
if (status & ISR_NOACK_MASK)
writel(TXFCR_FIFO_FLUSH_MASK | TXFCR_FIFO_EN_MASK,
dev->base + TXFCR_OFFSET);
writel(status & ~ISR_RESERVED_MASK, dev->base + ISR_OFFSET);
complete_all(&dev->done);
return IRQ_HANDLED;
}
static int bcm_kona_i2c_wait_if_busy(struct bcm_kona_i2c_dev *dev)
{
unsigned long timeout = jiffies + msecs_to_jiffies(I2C_TIMEOUT);
while (readl(dev->base + ISR_OFFSET) & ISR_CMDBUSY_MASK)
if (time_after(jiffies, timeout)) {
dev_err(dev->device, "CMDBUSY timeout\n");
return -ETIMEDOUT;
}
return 0;
}
static int bcm_kona_send_i2c_cmd(struct bcm_kona_i2c_dev *dev,
enum bcm_kona_cmd_t cmd)
{
int rc;
unsigned long time_left = msecs_to_jiffies(I2C_TIMEOUT);
rc = bcm_kona_i2c_wait_if_busy(dev);
if (rc < 0)
return rc;
writel(IER_I2C_INT_EN_MASK, dev->base + IER_OFFSET);
reinit_completion(&dev->done);
bcm_kona_i2c_send_cmd_to_ctrl(dev, cmd);
time_left = wait_for_completion_timeout(&dev->done, time_left);
writel(0, dev->base + IER_OFFSET);
if (!time_left) {
dev_err(dev->device, "controller timed out\n");
rc = -ETIMEDOUT;
}
bcm_kona_i2c_send_cmd_to_ctrl(dev, BCM_CMD_NOACTION);
return rc;
}
static int bcm_kona_i2c_read_fifo_single(struct bcm_kona_i2c_dev *dev,
uint8_t *buf, unsigned int len,
unsigned int last_byte_nak)
{
unsigned long time_left = msecs_to_jiffies(I2C_TIMEOUT);
reinit_completion(&dev->done);
writel(IER_READ_COMPLETE_INT_MASK, dev->base + IER_OFFSET);
writel((last_byte_nak << RXFCR_NACK_EN_SHIFT) |
(len << RXFCR_READ_COUNT_SHIFT),
dev->base + RXFCR_OFFSET);
time_left = wait_for_completion_timeout(&dev->done, time_left);
writel(0, dev->base + IER_OFFSET);
if (!time_left) {
dev_err(dev->device, "RX FIFO time out\n");
return -EREMOTEIO;
}
for (; len > 0; len--, buf++)
*buf = readl(dev->base + RXFIFORDOUT_OFFSET);
return 0;
}
static int bcm_kona_i2c_read_fifo(struct bcm_kona_i2c_dev *dev,
struct i2c_msg *msg)
{
unsigned int bytes_to_read = MAX_RX_FIFO_SIZE;
unsigned int last_byte_nak = 0;
unsigned int bytes_read = 0;
int rc;
uint8_t *tmp_buf = msg->buf;
while (bytes_read < msg->len) {
if (msg->len - bytes_read <= MAX_RX_FIFO_SIZE) {
last_byte_nak = 1;
bytes_to_read = msg->len - bytes_read;
}
rc = bcm_kona_i2c_read_fifo_single(dev, tmp_buf, bytes_to_read,
last_byte_nak);
if (rc < 0)
return -EREMOTEIO;
bytes_read += bytes_to_read;
tmp_buf += bytes_to_read;
}
return 0;
}
static int bcm_kona_i2c_write_byte(struct bcm_kona_i2c_dev *dev, uint8_t data,
unsigned int nak_expected)
{
int rc;
unsigned long time_left = msecs_to_jiffies(I2C_TIMEOUT);
unsigned int nak_received;
rc = bcm_kona_i2c_wait_if_busy(dev);
if (rc < 0)
return rc;
writel(ISR_SES_DONE_MASK, dev->base + ISR_OFFSET);
writel(IER_I2C_INT_EN_MASK, dev->base + IER_OFFSET);
reinit_completion(&dev->done);
writel(data, dev->base + DAT_OFFSET);
time_left = wait_for_completion_timeout(&dev->done, time_left);
writel(0, dev->base + IER_OFFSET);
if (!time_left) {
dev_dbg(dev->device, "controller timed out\n");
return -ETIMEDOUT;
}
nak_received = readl(dev->base + CS_OFFSET) & CS_ACK_MASK ? 1 : 0;
if (nak_received ^ nak_expected) {
dev_dbg(dev->device, "unexpected NAK/ACK\n");
return -EREMOTEIO;
}
return 0;
}
static int bcm_kona_i2c_write_fifo_single(struct bcm_kona_i2c_dev *dev,
uint8_t *buf, unsigned int len)
{
int k;
unsigned long time_left = msecs_to_jiffies(I2C_TIMEOUT);
unsigned int fifo_status;
reinit_completion(&dev->done);
writel(IER_FIFO_INT_EN_MASK | IER_NOACK_EN_MASK,
dev->base + IER_OFFSET);
disable_irq(dev->irq);
for (k = 0; k < len; k++)
writel(buf[k], (dev->base + DAT_OFFSET));
enable_irq(dev->irq);
do {
time_left = wait_for_completion_timeout(&dev->done, time_left);
fifo_status = readl(dev->base + FIFO_STATUS_OFFSET);
} while (time_left && !(fifo_status & FIFO_STATUS_TXFIFO_EMPTY_MASK));
writel(0, dev->base + IER_OFFSET);
if (readl(dev->base + CS_OFFSET) & CS_ACK_MASK) {
dev_err(dev->device, "unexpected NAK\n");
return -EREMOTEIO;
}
if (!time_left) {
dev_err(dev->device, "completion timed out\n");
return -EREMOTEIO;
}
return 0;
}
static int bcm_kona_i2c_write_fifo(struct bcm_kona_i2c_dev *dev,
struct i2c_msg *msg)
{
unsigned int bytes_to_write = MAX_TX_FIFO_SIZE;
unsigned int bytes_written = 0;
int rc;
uint8_t *tmp_buf = msg->buf;
while (bytes_written < msg->len) {
if (msg->len - bytes_written <= MAX_TX_FIFO_SIZE)
bytes_to_write = msg->len - bytes_written;
rc = bcm_kona_i2c_write_fifo_single(dev, tmp_buf,
bytes_to_write);
if (rc < 0)
return -EREMOTEIO;
bytes_written += bytes_to_write;
tmp_buf += bytes_to_write;
}
return 0;
}
static int bcm_kona_i2c_do_addr(struct bcm_kona_i2c_dev *dev,
struct i2c_msg *msg)
{
unsigned char addr;
if (msg->flags & I2C_M_TEN) {
addr = 0xF0 | ((msg->addr & 0x300) >> 7);
if (bcm_kona_i2c_write_byte(dev, addr, 0) < 0)
return -EREMOTEIO;
addr = msg->addr & 0xFF;
if (bcm_kona_i2c_write_byte(dev, addr, 0) < 0)
return -EREMOTEIO;
if (msg->flags & I2C_M_RD) {
if (bcm_kona_send_i2c_cmd(dev, BCM_CMD_RESTART) < 0)
return -EREMOTEIO;
addr = 0xF0 | ((msg->addr & 0x300) >> 7) | 0x01;
if (bcm_kona_i2c_write_byte(dev, addr, 0) < 0)
return -EREMOTEIO;
}
} else {
addr = i2c_8bit_addr_from_msg(msg);
if (bcm_kona_i2c_write_byte(dev, addr, 0) < 0)
return -EREMOTEIO;
}
return 0;
}
static void bcm_kona_i2c_enable_autosense(struct bcm_kona_i2c_dev *dev)
{
writel(readl(dev->base + CLKEN_OFFSET) & ~CLKEN_AUTOSENSE_OFF_MASK,
dev->base + CLKEN_OFFSET);
}
static void bcm_kona_i2c_config_timing(struct bcm_kona_i2c_dev *dev)
{
writel(readl(dev->base + HSTIM_OFFSET) & ~HSTIM_HS_MODE_MASK,
dev->base + HSTIM_OFFSET);
writel((dev->std_cfg->prescale << TIM_PRESCALE_SHIFT) |
(dev->std_cfg->time_p << TIM_P_SHIFT) |
(dev->std_cfg->no_div << TIM_NO_DIV_SHIFT) |
(dev->std_cfg->time_div << TIM_DIV_SHIFT),
dev->base + TIM_OFFSET);
writel((dev->std_cfg->time_m << CLKEN_M_SHIFT) |
(dev->std_cfg->time_n << CLKEN_N_SHIFT) |
CLKEN_CLKEN_MASK,
dev->base + CLKEN_OFFSET);
}
static void bcm_kona_i2c_config_timing_hs(struct bcm_kona_i2c_dev *dev)
{
writel((dev->hs_cfg->prescale << TIM_PRESCALE_SHIFT) |
(dev->hs_cfg->time_p << TIM_P_SHIFT) |
(dev->hs_cfg->no_div << TIM_NO_DIV_SHIFT) |
(dev->hs_cfg->time_div << TIM_DIV_SHIFT),
dev->base + TIM_OFFSET);
writel((dev->hs_cfg->hs_hold << HSTIM_HS_HOLD_SHIFT) |
(dev->hs_cfg->hs_high_phase << HSTIM_HS_HIGH_PHASE_SHIFT) |
(dev->hs_cfg->hs_setup << HSTIM_HS_SETUP_SHIFT),
dev->base + HSTIM_OFFSET);
writel(readl(dev->base + HSTIM_OFFSET) | HSTIM_HS_MODE_MASK,
dev->base + HSTIM_OFFSET);
}
static int bcm_kona_i2c_switch_to_hs(struct bcm_kona_i2c_dev *dev)
{
int rc;
rc = bcm_kona_i2c_write_byte(dev, MASTERCODE, 1);
if (rc < 0) {
pr_err("High speed handshake failed\n");
return rc;
}
rc = clk_set_rate(dev->external_clk, HS_EXT_CLK_FREQ);
if (rc) {
dev_err(dev->device, "%s: clk_set_rate returned %d\n",
__func__, rc);
return rc;
}
bcm_kona_i2c_config_timing_hs(dev);
rc = bcm_kona_send_i2c_cmd(dev, BCM_CMD_RESTART);
if (rc < 0)
dev_err(dev->device, "High speed restart command failed\n");
return rc;
}
static int bcm_kona_i2c_switch_to_std(struct bcm_kona_i2c_dev *dev)
{
int rc;
bcm_kona_i2c_config_timing(dev);
rc = clk_set_rate(dev->external_clk, STD_EXT_CLK_FREQ);
if (rc) {
dev_err(dev->device, "%s: clk_set_rate returned %d\n",
__func__, rc);
}
return rc;
}
static int bcm_kona_i2c_xfer(struct i2c_adapter *adapter,
struct i2c_msg msgs[], int num)
{
struct bcm_kona_i2c_dev *dev = i2c_get_adapdata(adapter);
struct i2c_msg *pmsg;
int rc = 0;
int i;
rc = clk_prepare_enable(dev->external_clk);
if (rc) {
dev_err(dev->device, "%s: peri clock enable failed. err %d\n",
__func__, rc);
return rc;
}
writel(0, dev->base + PADCTL_OFFSET);
bcm_kona_i2c_enable_clock(dev);
rc = bcm_kona_send_i2c_cmd(dev, BCM_CMD_START);
if (rc < 0) {
dev_err(dev->device, "Start command failed rc = %d\n", rc);
goto xfer_disable_pad;
}
if (dev->hs_cfg) {
rc = bcm_kona_i2c_switch_to_hs(dev);
if (rc < 0)
goto xfer_send_stop;
}
for (i = 0; i < num; i++) {
pmsg = &msgs[i];
if ((i != 0) && ((pmsg->flags & I2C_M_NOSTART) == 0)) {
rc = bcm_kona_send_i2c_cmd(dev, BCM_CMD_RESTART);
if (rc < 0) {
dev_err(dev->device,
"restart cmd failed rc = %d\n", rc);
goto xfer_send_stop;
}
}
if (!(pmsg->flags & I2C_M_NOSTART)) {
rc = bcm_kona_i2c_do_addr(dev, pmsg);
if (rc < 0) {
dev_err(dev->device,
"NAK from addr %2.2x msg#%d rc = %d\n",
pmsg->addr, i, rc);
goto xfer_send_stop;
}
}
if (pmsg->flags & I2C_M_RD) {
rc = bcm_kona_i2c_read_fifo(dev, pmsg);
if (rc < 0) {
dev_err(dev->device, "read failure\n");
goto xfer_send_stop;
}
} else {
rc = bcm_kona_i2c_write_fifo(dev, pmsg);
if (rc < 0) {
dev_err(dev->device, "write failure");
goto xfer_send_stop;
}
}
}
rc = num;
xfer_send_stop:
bcm_kona_send_i2c_cmd(dev, BCM_CMD_STOP);
if (dev->hs_cfg) {
int hs_rc = bcm_kona_i2c_switch_to_std(dev);
if (hs_rc)
rc = hs_rc;
}
xfer_disable_pad:
writel(PADCTL_PAD_OUT_EN_MASK, dev->base + PADCTL_OFFSET);
bcm_kona_i2c_disable_clock(dev);
clk_disable_unprepare(dev->external_clk);
return rc;
}
static uint32_t bcm_kona_i2c_functionality(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_10BIT_ADDR |
I2C_FUNC_NOSTART;
}
static int bcm_kona_i2c_assign_bus_speed(struct bcm_kona_i2c_dev *dev)
{
unsigned int bus_speed;
int ret = of_property_read_u32(dev->device->of_node, "clock-frequency",
&bus_speed);
if (ret < 0) {
dev_err(dev->device, "missing clock-frequency property\n");
return -ENODEV;
}
switch (bus_speed) {
case 100000:
dev->std_cfg = &std_cfg_table[BCM_SPD_100K];
break;
case 400000:
dev->std_cfg = &std_cfg_table[BCM_SPD_400K];
break;
case 1000000:
dev->std_cfg = &std_cfg_table[BCM_SPD_1MHZ];
break;
case 3400000:
dev->std_cfg = &std_cfg_table[BCM_SPD_100K];
dev->hs_cfg = &hs_cfg_table[BCM_SPD_3P4MHZ];
break;
default:
pr_err("%d hz bus speed not supported\n", bus_speed);
pr_err("Valid speeds are 100khz, 400khz, 1mhz, and 3.4mhz\n");
return -EINVAL;
}
return 0;
}
static int bcm_kona_i2c_probe(struct platform_device *pdev)
{
int rc = 0;
struct bcm_kona_i2c_dev *dev;
struct i2c_adapter *adap;
struct resource *iomem;
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
platform_set_drvdata(pdev, dev);
dev->device = &pdev->dev;
init_completion(&dev->done);
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
dev->base = devm_ioremap_resource(dev->device, iomem);
if (IS_ERR(dev->base))
return -ENOMEM;
dev->external_clk = devm_clk_get(dev->device, NULL);
if (IS_ERR(dev->external_clk)) {
dev_err(dev->device, "couldn't get clock\n");
return -ENODEV;
}
rc = clk_set_rate(dev->external_clk, STD_EXT_CLK_FREQ);
if (rc) {
dev_err(dev->device, "%s: clk_set_rate returned %d\n",
__func__, rc);
return rc;
}
rc = clk_prepare_enable(dev->external_clk);
if (rc) {
dev_err(dev->device, "couldn't enable clock\n");
return rc;
}
rc = bcm_kona_i2c_assign_bus_speed(dev);
if (rc)
goto probe_disable_clk;
bcm_kona_i2c_enable_clock(dev);
bcm_kona_i2c_config_timing(dev);
writel(0, dev->base + TOUT_OFFSET);
bcm_kona_i2c_enable_autosense(dev);
writel(TXFCR_FIFO_FLUSH_MASK | TXFCR_FIFO_EN_MASK,
dev->base + TXFCR_OFFSET);
writel(0, dev->base + IER_OFFSET);
writel(ISR_CMDBUSY_MASK |
ISR_READ_COMPLETE_MASK |
ISR_SES_DONE_MASK |
ISR_ERR_MASK |
ISR_TXFIFOEMPTY_MASK |
ISR_NOACK_MASK,
dev->base + ISR_OFFSET);
dev->irq = platform_get_irq(pdev, 0);
if (dev->irq < 0) {
dev_err(dev->device, "no irq resource\n");
rc = -ENODEV;
goto probe_disable_clk;
}
rc = devm_request_irq(&pdev->dev, dev->irq, bcm_kona_i2c_isr,
IRQF_SHARED, pdev->name, dev);
if (rc) {
dev_err(dev->device, "failed to request irq %i\n", dev->irq);
goto probe_disable_clk;
}
bcm_kona_i2c_send_cmd_to_ctrl(dev, BCM_CMD_NOACTION);
writel(PADCTL_PAD_OUT_EN_MASK, dev->base + PADCTL_OFFSET);
bcm_kona_i2c_disable_clock(dev);
clk_disable_unprepare(dev->external_clk);
adap = &dev->adapter;
i2c_set_adapdata(adap, dev);
adap->owner = THIS_MODULE;
strlcpy(adap->name, "Broadcom I2C adapter", sizeof(adap->name));
adap->algo = &bcm_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
rc = i2c_add_adapter(adap);
if (rc) {
dev_err(dev->device, "failed to add adapter\n");
return rc;
}
dev_info(dev->device, "device registered successfully\n");
return 0;
probe_disable_clk:
bcm_kona_i2c_disable_clock(dev);
clk_disable_unprepare(dev->external_clk);
return rc;
}
static int bcm_kona_i2c_remove(struct platform_device *pdev)
{
struct bcm_kona_i2c_dev *dev = platform_get_drvdata(pdev);
i2c_del_adapter(&dev->adapter);
return 0;
}
