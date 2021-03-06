static void i2c_sirfsoc_read_data(struct sirfsoc_i2c *siic)
{
u32 data = 0;
int i;
for (i = 0; i < siic->read_cmd_len; i++) {
if (!(i & 0x3))
data = readl(siic->base + SIRFSOC_I2C_DATA_BUF + i);
siic->buf[siic->finished_len++] =
(u8)((data & SIRFSOC_I2C_DATA_MASK(i)) >>
SIRFSOC_I2C_DATA_SHIFT(i));
}
}
static void i2c_sirfsoc_queue_cmd(struct sirfsoc_i2c *siic)
{
u32 regval;
int i = 0;
if (siic->msg_read) {
while (((siic->finished_len + i) < siic->msg_len)
&& (siic->cmd_ptr < SIRFSOC_I2C_CMD_BUF_MAX)) {
regval = SIRFSOC_I2C_READ | SIRFSOC_I2C_CMD_RP(0);
if (((siic->finished_len + i) ==
(siic->msg_len - 1)) && siic->last)
regval |= SIRFSOC_I2C_STOP | SIRFSOC_I2C_NACK;
writel(regval,
siic->base + SIRFSOC_I2C_CMD(siic->cmd_ptr++));
i++;
}
siic->read_cmd_len = i;
} else {
while ((siic->cmd_ptr < SIRFSOC_I2C_CMD_BUF_MAX - 1)
&& (siic->finished_len < siic->msg_len)) {
regval = SIRFSOC_I2C_WRITE | SIRFSOC_I2C_CMD_RP(0);
if ((siic->finished_len == (siic->msg_len - 1))
&& siic->last)
regval |= SIRFSOC_I2C_STOP;
writel(regval,
siic->base + SIRFSOC_I2C_CMD(siic->cmd_ptr++));
writel(siic->buf[siic->finished_len++],
siic->base + SIRFSOC_I2C_CMD(siic->cmd_ptr++));
}
}
siic->cmd_ptr = 0;
writel(SIRFSOC_I2C_START_CMD, siic->base + SIRFSOC_I2C_CMD_START);
}
static irqreturn_t i2c_sirfsoc_irq(int irq, void *dev_id)
{
struct sirfsoc_i2c *siic = (struct sirfsoc_i2c *)dev_id;
u32 i2c_stat = readl(siic->base + SIRFSOC_I2C_STATUS);
if (i2c_stat & SIRFSOC_I2C_STAT_ERR) {
siic->err_status = SIRFSOC_I2C_ERR_NOACK;
writel(SIRFSOC_I2C_STAT_ERR, siic->base + SIRFSOC_I2C_STATUS);
if (i2c_stat & SIRFSOC_I2C_STAT_NACK)
dev_dbg(&siic->adapter.dev, "ACK not received\n");
else
dev_err(&siic->adapter.dev, "I2C error\n");
writel(readl(siic->base + SIRFSOC_I2C_CTRL) | SIRFSOC_I2C_RESET,
siic->base + SIRFSOC_I2C_CTRL);
while (readl(siic->base + SIRFSOC_I2C_CTRL) & SIRFSOC_I2C_RESET)
cpu_relax();
complete(&siic->done);
} else if (i2c_stat & SIRFSOC_I2C_STAT_CMD_DONE) {
if (siic->msg_read)
i2c_sirfsoc_read_data(siic);
if (siic->finished_len == siic->msg_len)
complete(&siic->done);
else
i2c_sirfsoc_queue_cmd(siic);
writel(SIRFSOC_I2C_STAT_CMD_DONE, siic->base + SIRFSOC_I2C_STATUS);
}
return IRQ_HANDLED;
}
static void i2c_sirfsoc_set_address(struct sirfsoc_i2c *siic,
struct i2c_msg *msg)
{
unsigned char addr;
u32 regval = SIRFSOC_I2C_START | SIRFSOC_I2C_CMD_RP(0) | SIRFSOC_I2C_WRITE;
if (siic->last && (msg->len == 0))
regval |= SIRFSOC_I2C_STOP;
writel(regval, siic->base + SIRFSOC_I2C_CMD(siic->cmd_ptr++));
addr = msg->addr << 1;
if (msg->flags & I2C_M_RD)
addr |= 1;
if (msg->flags & I2C_M_REV_DIR_ADDR)
addr ^= 1;
writel(addr, siic->base + SIRFSOC_I2C_CMD(siic->cmd_ptr++));
}
static int i2c_sirfsoc_xfer_msg(struct sirfsoc_i2c *siic, struct i2c_msg *msg)
{
u32 regval = readl(siic->base + SIRFSOC_I2C_CTRL);
int timeout = msecs_to_jiffies((msg->len + 1) * 50);
i2c_sirfsoc_set_address(siic, msg);
writel(regval | SIRFSOC_I2C_CMD_DONE_EN | SIRFSOC_I2C_ERR_INT_EN,
siic->base + SIRFSOC_I2C_CTRL);
i2c_sirfsoc_queue_cmd(siic);
if (wait_for_completion_timeout(&siic->done, timeout) == 0) {
siic->err_status = SIRFSOC_I2C_ERR_TIMEOUT;
dev_err(&siic->adapter.dev, "Transfer timeout\n");
}
writel(regval & ~(SIRFSOC_I2C_CMD_DONE_EN | SIRFSOC_I2C_ERR_INT_EN),
siic->base + SIRFSOC_I2C_CTRL);
writel(0, siic->base + SIRFSOC_I2C_CMD_START);
if (siic->err_status == SIRFSOC_I2C_ERR_TIMEOUT) {
writel(readl(siic->base + SIRFSOC_I2C_CTRL) | SIRFSOC_I2C_RESET,
siic->base + SIRFSOC_I2C_CTRL);
while (readl(siic->base + SIRFSOC_I2C_CTRL) & SIRFSOC_I2C_RESET)
cpu_relax();
}
return siic->err_status ? -EAGAIN : 0;
}
static u32 i2c_sirfsoc_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int i2c_sirfsoc_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs,
int num)
{
struct sirfsoc_i2c *siic = adap->algo_data;
int i, ret;
clk_enable(siic->clk);
for (i = 0; i < num; i++) {
siic->buf = msgs[i].buf;
siic->msg_len = msgs[i].len;
siic->msg_read = !!(msgs[i].flags & I2C_M_RD);
siic->err_status = 0;
siic->cmd_ptr = 0;
siic->finished_len = 0;
siic->last = (i == (num - 1));
ret = i2c_sirfsoc_xfer_msg(siic, &msgs[i]);
if (ret) {
clk_disable(siic->clk);
return ret;
}
}
clk_disable(siic->clk);
return num;
}
static int i2c_sirfsoc_probe(struct platform_device *pdev)
{
struct sirfsoc_i2c *siic;
struct i2c_adapter *adap;
struct resource *mem_res;
struct clk *clk;
int bitrate;
int ctrl_speed;
int irq;
int err;
u32 regval;
clk = clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
err = PTR_ERR(clk);
dev_err(&pdev->dev, "Clock get failed\n");
goto err_get_clk;
}
err = clk_prepare(clk);
if (err) {
dev_err(&pdev->dev, "Clock prepare failed\n");
goto err_clk_prep;
}
err = clk_enable(clk);
if (err) {
dev_err(&pdev->dev, "Clock enable failed\n");
goto err_clk_en;
}
ctrl_speed = clk_get_rate(clk);
siic = devm_kzalloc(&pdev->dev, sizeof(*siic), GFP_KERNEL);
if (!siic) {
dev_err(&pdev->dev, "Can't allocate driver data\n");
err = -ENOMEM;
goto out;
}
adap = &siic->adapter;
adap->class = I2C_CLASS_HWMON | I2C_CLASS_DEPRECATED;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
siic->base = devm_ioremap_resource(&pdev->dev, mem_res);
if (IS_ERR(siic->base)) {
err = PTR_ERR(siic->base);
goto out;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
err = irq;
goto out;
}
err = devm_request_irq(&pdev->dev, irq, i2c_sirfsoc_irq, 0,
dev_name(&pdev->dev), siic);
if (err)
goto out;
adap->algo = &i2c_sirfsoc_algo;
adap->algo_data = siic;
adap->retries = 3;
adap->dev.of_node = pdev->dev.of_node;
adap->dev.parent = &pdev->dev;
adap->nr = pdev->id;
strlcpy(adap->name, "sirfsoc-i2c", sizeof(adap->name));
platform_set_drvdata(pdev, adap);
init_completion(&siic->done);
writel(SIRFSOC_I2C_RESET, siic->base + SIRFSOC_I2C_CTRL);
while (readl(siic->base + SIRFSOC_I2C_CTRL) & SIRFSOC_I2C_RESET)
cpu_relax();
writel(SIRFSOC_I2C_CORE_EN | SIRFSOC_I2C_MASTER_MODE,
siic->base + SIRFSOC_I2C_CTRL);
siic->clk = clk;
err = of_property_read_u32(pdev->dev.of_node,
"clock-frequency", &bitrate);
if (err < 0)
bitrate = SIRFSOC_I2C_DEFAULT_SPEED;
if (bitrate < 100000)
regval =
(2 * ctrl_speed) / (bitrate * 11);
else
regval = ctrl_speed / (bitrate * 5);
writel(regval, siic->base + SIRFSOC_I2C_CLK_CTRL);
if (regval > 0xFF)
writel(0xFF, siic->base + SIRFSOC_I2C_SDA_DELAY);
else
writel(regval, siic->base + SIRFSOC_I2C_SDA_DELAY);
err = i2c_add_numbered_adapter(adap);
if (err < 0) {
dev_err(&pdev->dev, "Can't add new i2c adapter\n");
goto out;
}
clk_disable(clk);
dev_info(&pdev->dev, " I2C adapter ready to operate\n");
return 0;
out:
clk_disable(clk);
err_clk_en:
clk_unprepare(clk);
err_clk_prep:
clk_put(clk);
err_get_clk:
return err;
}
static int i2c_sirfsoc_remove(struct platform_device *pdev)
{
struct i2c_adapter *adapter = platform_get_drvdata(pdev);
struct sirfsoc_i2c *siic = adapter->algo_data;
writel(SIRFSOC_I2C_RESET, siic->base + SIRFSOC_I2C_CTRL);
i2c_del_adapter(adapter);
clk_unprepare(siic->clk);
clk_put(siic->clk);
return 0;
}
static int i2c_sirfsoc_suspend(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct i2c_adapter *adapter = platform_get_drvdata(pdev);
struct sirfsoc_i2c *siic = adapter->algo_data;
clk_enable(siic->clk);
siic->sda_delay = readl(siic->base + SIRFSOC_I2C_SDA_DELAY);
siic->clk_div = readl(siic->base + SIRFSOC_I2C_CLK_CTRL);
clk_disable(siic->clk);
return 0;
}
static int i2c_sirfsoc_resume(struct device *dev)
{
struct platform_device *pdev = to_platform_device(dev);
struct i2c_adapter *adapter = platform_get_drvdata(pdev);
struct sirfsoc_i2c *siic = adapter->algo_data;
clk_enable(siic->clk);
writel(SIRFSOC_I2C_RESET, siic->base + SIRFSOC_I2C_CTRL);
while (readl(siic->base + SIRFSOC_I2C_CTRL) & SIRFSOC_I2C_RESET)
cpu_relax();
writel(SIRFSOC_I2C_CORE_EN | SIRFSOC_I2C_MASTER_MODE,
siic->base + SIRFSOC_I2C_CTRL);
writel(siic->clk_div, siic->base + SIRFSOC_I2C_CLK_CTRL);
writel(siic->sda_delay, siic->base + SIRFSOC_I2C_SDA_DELAY);
clk_disable(siic->clk);
return 0;
}
