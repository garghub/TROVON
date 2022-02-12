static int wmt_i2c_wait_bus_not_busy(struct wmt_i2c_dev *i2c_dev)
{
unsigned long timeout;
timeout = jiffies + WMT_I2C_TIMEOUT;
while (!(readw(i2c_dev->base + REG_CSR) & CSR_READY_MASK)) {
if (time_after(jiffies, timeout)) {
dev_warn(i2c_dev->dev, "timeout waiting for bus ready\n");
return -EBUSY;
}
msleep(20);
}
return 0;
}
static int wmt_check_status(struct wmt_i2c_dev *i2c_dev)
{
int ret = 0;
if (i2c_dev->cmd_status & ISR_NACK_ADDR)
ret = -EIO;
if (i2c_dev->cmd_status & ISR_SCL_TIMEOUT)
ret = -ETIMEDOUT;
return ret;
}
static int wmt_i2c_write(struct i2c_adapter *adap, struct i2c_msg *pmsg,
int last)
{
struct wmt_i2c_dev *i2c_dev = i2c_get_adapdata(adap);
u16 val, tcr_val;
int ret, wait_result;
int xfer_len = 0;
if (!(pmsg->flags & I2C_M_NOSTART)) {
ret = wmt_i2c_wait_bus_not_busy(i2c_dev);
if (ret < 0)
return ret;
}
if (pmsg->len == 0) {
xfer_len = -1;
writew(0, i2c_dev->base + REG_CDR);
} else {
writew(pmsg->buf[0] & 0xFF, i2c_dev->base + REG_CDR);
}
if (!(pmsg->flags & I2C_M_NOSTART)) {
val = readw(i2c_dev->base + REG_CR);
val &= ~CR_TX_END;
writew(val, i2c_dev->base + REG_CR);
val = readw(i2c_dev->base + REG_CR);
val |= CR_CPU_RDY;
writew(val, i2c_dev->base + REG_CR);
}
reinit_completion(&i2c_dev->complete);
if (i2c_dev->mode == I2C_MODE_STANDARD)
tcr_val = TCR_STANDARD_MODE;
else
tcr_val = TCR_FAST_MODE;
tcr_val |= (TCR_MASTER_WRITE | (pmsg->addr & TCR_SLAVE_ADDR_MASK));
writew(tcr_val, i2c_dev->base + REG_TCR);
if (pmsg->flags & I2C_M_NOSTART) {
val = readw(i2c_dev->base + REG_CR);
val |= CR_CPU_RDY;
writew(val, i2c_dev->base + REG_CR);
}
while (xfer_len < pmsg->len) {
wait_result = wait_for_completion_timeout(&i2c_dev->complete,
500 * HZ / 1000);
if (wait_result == 0)
return -ETIMEDOUT;
ret = wmt_check_status(i2c_dev);
if (ret)
return ret;
xfer_len++;
val = readw(i2c_dev->base + REG_CSR);
if ((val & CSR_RCV_ACK_MASK) == CSR_RCV_NOT_ACK) {
dev_dbg(i2c_dev->dev, "write RCV NACK error\n");
return -EIO;
}
if (pmsg->len == 0) {
val = CR_TX_END | CR_CPU_RDY | CR_ENABLE;
writew(val, i2c_dev->base + REG_CR);
break;
}
if (xfer_len == pmsg->len) {
if (last != 1)
writew(CR_ENABLE, i2c_dev->base + REG_CR);
} else {
writew(pmsg->buf[xfer_len] & 0xFF, i2c_dev->base +
REG_CDR);
writew(CR_CPU_RDY | CR_ENABLE, i2c_dev->base + REG_CR);
}
}
return 0;
}
static int wmt_i2c_read(struct i2c_adapter *adap, struct i2c_msg *pmsg,
int last)
{
struct wmt_i2c_dev *i2c_dev = i2c_get_adapdata(adap);
u16 val, tcr_val;
int ret, wait_result;
u32 xfer_len = 0;
if (!(pmsg->flags & I2C_M_NOSTART)) {
ret = wmt_i2c_wait_bus_not_busy(i2c_dev);
if (ret < 0)
return ret;
}
val = readw(i2c_dev->base + REG_CR);
val &= ~CR_TX_END;
writew(val, i2c_dev->base + REG_CR);
val = readw(i2c_dev->base + REG_CR);
val &= ~CR_TX_NEXT_NO_ACK;
writew(val, i2c_dev->base + REG_CR);
if (!(pmsg->flags & I2C_M_NOSTART)) {
val = readw(i2c_dev->base + REG_CR);
val |= CR_CPU_RDY;
writew(val, i2c_dev->base + REG_CR);
}
if (pmsg->len == 1) {
val = readw(i2c_dev->base + REG_CR);
val |= CR_TX_NEXT_NO_ACK;
writew(val, i2c_dev->base + REG_CR);
}
reinit_completion(&i2c_dev->complete);
if (i2c_dev->mode == I2C_MODE_STANDARD)
tcr_val = TCR_STANDARD_MODE;
else
tcr_val = TCR_FAST_MODE;
tcr_val |= TCR_MASTER_READ | (pmsg->addr & TCR_SLAVE_ADDR_MASK);
writew(tcr_val, i2c_dev->base + REG_TCR);
if (pmsg->flags & I2C_M_NOSTART) {
val = readw(i2c_dev->base + REG_CR);
val |= CR_CPU_RDY;
writew(val, i2c_dev->base + REG_CR);
}
while (xfer_len < pmsg->len) {
wait_result = wait_for_completion_timeout(&i2c_dev->complete,
500 * HZ / 1000);
if (!wait_result)
return -ETIMEDOUT;
ret = wmt_check_status(i2c_dev);
if (ret)
return ret;
pmsg->buf[xfer_len] = readw(i2c_dev->base + REG_CDR) >> 8;
xfer_len++;
if (xfer_len == pmsg->len - 1) {
val = readw(i2c_dev->base + REG_CR);
val |= (CR_TX_NEXT_NO_ACK | CR_CPU_RDY);
writew(val, i2c_dev->base + REG_CR);
} else {
val = readw(i2c_dev->base + REG_CR);
val |= CR_CPU_RDY;
writew(val, i2c_dev->base + REG_CR);
}
}
return 0;
}
static int wmt_i2c_xfer(struct i2c_adapter *adap,
struct i2c_msg msgs[],
int num)
{
struct i2c_msg *pmsg;
int i, is_last;
int ret = 0;
for (i = 0; ret >= 0 && i < num; i++) {
is_last = ((i + 1) == num);
pmsg = &msgs[i];
if (pmsg->flags & I2C_M_RD)
ret = wmt_i2c_read(adap, pmsg, is_last);
else
ret = wmt_i2c_write(adap, pmsg, is_last);
}
return (ret < 0) ? ret : i;
}
static u32 wmt_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL | I2C_FUNC_NOSTART;
}
static irqreturn_t wmt_i2c_isr(int irq, void *data)
{
struct wmt_i2c_dev *i2c_dev = data;
i2c_dev->cmd_status = readw(i2c_dev->base + REG_ISR);
writew(i2c_dev->cmd_status, i2c_dev->base + REG_ISR);
complete(&i2c_dev->complete);
return IRQ_HANDLED;
}
static int wmt_i2c_reset_hardware(struct wmt_i2c_dev *i2c_dev)
{
int err;
err = clk_prepare_enable(i2c_dev->clk);
if (err) {
dev_err(i2c_dev->dev, "failed to enable clock\n");
return err;
}
err = clk_set_rate(i2c_dev->clk, 20000000);
if (err) {
dev_err(i2c_dev->dev, "failed to set clock = 20Mhz\n");
clk_disable_unprepare(i2c_dev->clk);
return err;
}
writew(0, i2c_dev->base + REG_CR);
writew(MCR_APB_166M, i2c_dev->base + REG_MCR);
writew(ISR_WRITE_ALL, i2c_dev->base + REG_ISR);
writew(IMR_ENABLE_ALL, i2c_dev->base + REG_IMR);
writew(CR_ENABLE, i2c_dev->base + REG_CR);
readw(i2c_dev->base + REG_CSR);
writew(ISR_WRITE_ALL, i2c_dev->base + REG_ISR);
if (i2c_dev->mode == I2C_MODE_STANDARD)
writew(SCL_TIMEOUT(128) | TR_STD, i2c_dev->base + REG_TR);
else
writew(SCL_TIMEOUT(128) | TR_HS, i2c_dev->base + REG_TR);
return 0;
}
static int wmt_i2c_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct wmt_i2c_dev *i2c_dev;
struct i2c_adapter *adap;
struct resource *res;
int err;
u32 clk_rate;
i2c_dev = devm_kzalloc(&pdev->dev, sizeof(*i2c_dev), GFP_KERNEL);
if (!i2c_dev)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
i2c_dev->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(i2c_dev->base))
return PTR_ERR(i2c_dev->base);
i2c_dev->irq = irq_of_parse_and_map(np, 0);
if (!i2c_dev->irq) {
dev_err(&pdev->dev, "irq missing or invalid\n");
return -EINVAL;
}
i2c_dev->clk = of_clk_get(np, 0);
if (IS_ERR(i2c_dev->clk)) {
dev_err(&pdev->dev, "unable to request clock\n");
return PTR_ERR(i2c_dev->clk);
}
i2c_dev->mode = I2C_MODE_STANDARD;
err = of_property_read_u32(np, "clock-frequency", &clk_rate);
if ((!err) && (clk_rate == 400000))
i2c_dev->mode = I2C_MODE_FAST;
i2c_dev->dev = &pdev->dev;
err = devm_request_irq(&pdev->dev, i2c_dev->irq, wmt_i2c_isr, 0,
"i2c", i2c_dev);
if (err) {
dev_err(&pdev->dev, "failed to request irq %i\n", i2c_dev->irq);
return err;
}
adap = &i2c_dev->adapter;
i2c_set_adapdata(adap, i2c_dev);
strlcpy(adap->name, "WMT I2C adapter", sizeof(adap->name));
adap->owner = THIS_MODULE;
adap->algo = &wmt_i2c_algo;
adap->dev.parent = &pdev->dev;
adap->dev.of_node = pdev->dev.of_node;
init_completion(&i2c_dev->complete);
err = wmt_i2c_reset_hardware(i2c_dev);
if (err) {
dev_err(&pdev->dev, "error initializing hardware\n");
return err;
}
err = i2c_add_adapter(adap);
if (err) {
dev_err(&pdev->dev, "failed to add adapter\n");
return err;
}
platform_set_drvdata(pdev, i2c_dev);
return 0;
}
static int wmt_i2c_remove(struct platform_device *pdev)
{
struct wmt_i2c_dev *i2c_dev = platform_get_drvdata(pdev);
writew(0, i2c_dev->base + REG_IMR);
clk_disable_unprepare(i2c_dev->clk);
i2c_del_adapter(&i2c_dev->adapter);
return 0;
}
