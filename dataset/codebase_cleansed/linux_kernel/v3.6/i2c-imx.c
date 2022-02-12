static int i2c_imx_bus_busy(struct imx_i2c_struct *i2c_imx, int for_busy)
{
unsigned long orig_jiffies = jiffies;
unsigned int temp;
dev_dbg(&i2c_imx->adapter.dev, "<%s>\n", __func__);
while (1) {
temp = readb(i2c_imx->base + IMX_I2C_I2SR);
if (for_busy && (temp & I2SR_IBB))
break;
if (!for_busy && !(temp & I2SR_IBB))
break;
if (time_after(jiffies, orig_jiffies + msecs_to_jiffies(500))) {
dev_dbg(&i2c_imx->adapter.dev,
"<%s> I2C bus is busy\n", __func__);
return -ETIMEDOUT;
}
schedule();
}
return 0;
}
static int i2c_imx_trx_complete(struct imx_i2c_struct *i2c_imx)
{
wait_event_timeout(i2c_imx->queue, i2c_imx->i2csr & I2SR_IIF, HZ / 10);
if (unlikely(!(i2c_imx->i2csr & I2SR_IIF))) {
dev_dbg(&i2c_imx->adapter.dev, "<%s> Timeout\n", __func__);
return -ETIMEDOUT;
}
dev_dbg(&i2c_imx->adapter.dev, "<%s> TRX complete\n", __func__);
i2c_imx->i2csr = 0;
return 0;
}
static int i2c_imx_acked(struct imx_i2c_struct *i2c_imx)
{
if (readb(i2c_imx->base + IMX_I2C_I2SR) & I2SR_RXAK) {
dev_dbg(&i2c_imx->adapter.dev, "<%s> No ACK\n", __func__);
return -EIO;
}
dev_dbg(&i2c_imx->adapter.dev, "<%s> ACK received\n", __func__);
return 0;
}
static int i2c_imx_start(struct imx_i2c_struct *i2c_imx)
{
unsigned int temp = 0;
int result;
dev_dbg(&i2c_imx->adapter.dev, "<%s>\n", __func__);
clk_prepare_enable(i2c_imx->clk);
writeb(i2c_imx->ifdr, i2c_imx->base + IMX_I2C_IFDR);
writeb(0, i2c_imx->base + IMX_I2C_I2SR);
writeb(I2CR_IEN, i2c_imx->base + IMX_I2C_I2CR);
udelay(50);
temp = readb(i2c_imx->base + IMX_I2C_I2CR);
temp |= I2CR_MSTA;
writeb(temp, i2c_imx->base + IMX_I2C_I2CR);
result = i2c_imx_bus_busy(i2c_imx, 1);
if (result)
return result;
i2c_imx->stopped = 0;
temp |= I2CR_IIEN | I2CR_MTX | I2CR_TXAK;
writeb(temp, i2c_imx->base + IMX_I2C_I2CR);
return result;
}
static void i2c_imx_stop(struct imx_i2c_struct *i2c_imx)
{
unsigned int temp = 0;
if (!i2c_imx->stopped) {
dev_dbg(&i2c_imx->adapter.dev, "<%s>\n", __func__);
temp = readb(i2c_imx->base + IMX_I2C_I2CR);
temp &= ~(I2CR_MSTA | I2CR_MTX);
writeb(temp, i2c_imx->base + IMX_I2C_I2CR);
}
if (cpu_is_mx1()) {
udelay(i2c_imx->disable_delay);
}
if (!i2c_imx->stopped) {
i2c_imx_bus_busy(i2c_imx, 0);
i2c_imx->stopped = 1;
}
writeb(0, i2c_imx->base + IMX_I2C_I2CR);
clk_disable_unprepare(i2c_imx->clk);
}
static void __init i2c_imx_set_clk(struct imx_i2c_struct *i2c_imx,
unsigned int rate)
{
unsigned int i2c_clk_rate;
unsigned int div;
int i;
i2c_clk_rate = clk_get_rate(i2c_imx->clk);
div = (i2c_clk_rate + rate - 1) / rate;
if (div < i2c_clk_div[0][0])
i = 0;
else if (div > i2c_clk_div[ARRAY_SIZE(i2c_clk_div) - 1][0])
i = ARRAY_SIZE(i2c_clk_div) - 1;
else
for (i = 0; i2c_clk_div[i][0] < div; i++);
i2c_imx->ifdr = i2c_clk_div[i][1];
i2c_imx->disable_delay = (500000U * i2c_clk_div[i][0]
+ (i2c_clk_rate / 2) - 1) / (i2c_clk_rate / 2);
#ifdef CONFIG_I2C_DEBUG_BUS
printk(KERN_DEBUG "I2C: <%s> I2C_CLK=%d, REQ DIV=%d\n",
__func__, i2c_clk_rate, div);
printk(KERN_DEBUG "I2C: <%s> IFDR[IC]=0x%x, REAL DIV=%d\n",
__func__, i2c_clk_div[i][1], i2c_clk_div[i][0]);
#endif
}
static irqreturn_t i2c_imx_isr(int irq, void *dev_id)
{
struct imx_i2c_struct *i2c_imx = dev_id;
unsigned int temp;
temp = readb(i2c_imx->base + IMX_I2C_I2SR);
if (temp & I2SR_IIF) {
i2c_imx->i2csr = temp;
temp &= ~I2SR_IIF;
writeb(temp, i2c_imx->base + IMX_I2C_I2SR);
wake_up(&i2c_imx->queue);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int i2c_imx_write(struct imx_i2c_struct *i2c_imx, struct i2c_msg *msgs)
{
int i, result;
dev_dbg(&i2c_imx->adapter.dev, "<%s> write slave address: addr=0x%x\n",
__func__, msgs->addr << 1);
writeb(msgs->addr << 1, i2c_imx->base + IMX_I2C_I2DR);
result = i2c_imx_trx_complete(i2c_imx);
if (result)
return result;
result = i2c_imx_acked(i2c_imx);
if (result)
return result;
dev_dbg(&i2c_imx->adapter.dev, "<%s> write data\n", __func__);
for (i = 0; i < msgs->len; i++) {
dev_dbg(&i2c_imx->adapter.dev,
"<%s> write byte: B%d=0x%X\n",
__func__, i, msgs->buf[i]);
writeb(msgs->buf[i], i2c_imx->base + IMX_I2C_I2DR);
result = i2c_imx_trx_complete(i2c_imx);
if (result)
return result;
result = i2c_imx_acked(i2c_imx);
if (result)
return result;
}
return 0;
}
static int i2c_imx_read(struct imx_i2c_struct *i2c_imx, struct i2c_msg *msgs)
{
int i, result;
unsigned int temp;
dev_dbg(&i2c_imx->adapter.dev,
"<%s> write slave address: addr=0x%x\n",
__func__, (msgs->addr << 1) | 0x01);
writeb((msgs->addr << 1) | 0x01, i2c_imx->base + IMX_I2C_I2DR);
result = i2c_imx_trx_complete(i2c_imx);
if (result)
return result;
result = i2c_imx_acked(i2c_imx);
if (result)
return result;
dev_dbg(&i2c_imx->adapter.dev, "<%s> setup bus\n", __func__);
temp = readb(i2c_imx->base + IMX_I2C_I2CR);
temp &= ~I2CR_MTX;
if (msgs->len - 1)
temp &= ~I2CR_TXAK;
writeb(temp, i2c_imx->base + IMX_I2C_I2CR);
readb(i2c_imx->base + IMX_I2C_I2DR);
dev_dbg(&i2c_imx->adapter.dev, "<%s> read data\n", __func__);
for (i = 0; i < msgs->len; i++) {
result = i2c_imx_trx_complete(i2c_imx);
if (result)
return result;
if (i == (msgs->len - 1)) {
dev_dbg(&i2c_imx->adapter.dev,
"<%s> clear MSTA\n", __func__);
temp = readb(i2c_imx->base + IMX_I2C_I2CR);
temp &= ~(I2CR_MSTA | I2CR_MTX);
writeb(temp, i2c_imx->base + IMX_I2C_I2CR);
i2c_imx_bus_busy(i2c_imx, 0);
i2c_imx->stopped = 1;
} else if (i == (msgs->len - 2)) {
dev_dbg(&i2c_imx->adapter.dev,
"<%s> set TXAK\n", __func__);
temp = readb(i2c_imx->base + IMX_I2C_I2CR);
temp |= I2CR_TXAK;
writeb(temp, i2c_imx->base + IMX_I2C_I2CR);
}
msgs->buf[i] = readb(i2c_imx->base + IMX_I2C_I2DR);
dev_dbg(&i2c_imx->adapter.dev,
"<%s> read byte: B%d=0x%X\n",
__func__, i, msgs->buf[i]);
}
return 0;
}
static int i2c_imx_xfer(struct i2c_adapter *adapter,
struct i2c_msg *msgs, int num)
{
unsigned int i, temp;
int result;
struct imx_i2c_struct *i2c_imx = i2c_get_adapdata(adapter);
dev_dbg(&i2c_imx->adapter.dev, "<%s>\n", __func__);
result = i2c_imx_start(i2c_imx);
if (result)
goto fail0;
for (i = 0; i < num; i++) {
if (i) {
dev_dbg(&i2c_imx->adapter.dev,
"<%s> repeated start\n", __func__);
temp = readb(i2c_imx->base + IMX_I2C_I2CR);
temp |= I2CR_RSTA;
writeb(temp, i2c_imx->base + IMX_I2C_I2CR);
result = i2c_imx_bus_busy(i2c_imx, 1);
if (result)
goto fail0;
}
dev_dbg(&i2c_imx->adapter.dev,
"<%s> transfer message: %d\n", __func__, i);
#ifdef CONFIG_I2C_DEBUG_BUS
temp = readb(i2c_imx->base + IMX_I2C_I2CR);
dev_dbg(&i2c_imx->adapter.dev, "<%s> CONTROL: IEN=%d, IIEN=%d, "
"MSTA=%d, MTX=%d, TXAK=%d, RSTA=%d\n", __func__,
(temp & I2CR_IEN ? 1 : 0), (temp & I2CR_IIEN ? 1 : 0),
(temp & I2CR_MSTA ? 1 : 0), (temp & I2CR_MTX ? 1 : 0),
(temp & I2CR_TXAK ? 1 : 0), (temp & I2CR_RSTA ? 1 : 0));
temp = readb(i2c_imx->base + IMX_I2C_I2SR);
dev_dbg(&i2c_imx->adapter.dev,
"<%s> STATUS: ICF=%d, IAAS=%d, IBB=%d, "
"IAL=%d, SRW=%d, IIF=%d, RXAK=%d\n", __func__,
(temp & I2SR_ICF ? 1 : 0), (temp & I2SR_IAAS ? 1 : 0),
(temp & I2SR_IBB ? 1 : 0), (temp & I2SR_IAL ? 1 : 0),
(temp & I2SR_SRW ? 1 : 0), (temp & I2SR_IIF ? 1 : 0),
(temp & I2SR_RXAK ? 1 : 0));
#endif
if (msgs[i].flags & I2C_M_RD)
result = i2c_imx_read(i2c_imx, &msgs[i]);
else
result = i2c_imx_write(i2c_imx, &msgs[i]);
if (result)
goto fail0;
}
fail0:
i2c_imx_stop(i2c_imx);
dev_dbg(&i2c_imx->adapter.dev, "<%s> exit with: %s: %d\n", __func__,
(result < 0) ? "error" : "success msg",
(result < 0) ? result : num);
return (result < 0) ? result : num;
}
static u32 i2c_imx_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int __init i2c_imx_probe(struct platform_device *pdev)
{
struct imx_i2c_struct *i2c_imx;
struct resource *res;
struct imxi2c_platform_data *pdata = pdev->dev.platform_data;
struct pinctrl *pinctrl;
void __iomem *base;
int irq, ret;
u32 bitrate;
dev_dbg(&pdev->dev, "<%s>\n", __func__);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "can't get device resources\n");
return -ENOENT;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "can't get irq number\n");
return -ENOENT;
}
base = devm_request_and_ioremap(&pdev->dev, res);
if (!base)
return -EBUSY;
i2c_imx = devm_kzalloc(&pdev->dev, sizeof(struct imx_i2c_struct),
GFP_KERNEL);
if (!i2c_imx) {
dev_err(&pdev->dev, "can't allocate interface\n");
return -ENOMEM;
}
strlcpy(i2c_imx->adapter.name, pdev->name, sizeof(i2c_imx->adapter.name));
i2c_imx->adapter.owner = THIS_MODULE;
i2c_imx->adapter.algo = &i2c_imx_algo;
i2c_imx->adapter.dev.parent = &pdev->dev;
i2c_imx->adapter.nr = pdev->id;
i2c_imx->adapter.dev.of_node = pdev->dev.of_node;
i2c_imx->base = base;
pinctrl = devm_pinctrl_get_select_default(&pdev->dev);
if (IS_ERR(pinctrl)) {
dev_err(&pdev->dev, "can't get/select pinctrl\n");
return PTR_ERR(pinctrl);
}
i2c_imx->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(i2c_imx->clk)) {
dev_err(&pdev->dev, "can't get I2C clock\n");
return PTR_ERR(i2c_imx->clk);
}
ret = devm_request_irq(&pdev->dev, irq, i2c_imx_isr, 0,
pdev->name, i2c_imx);
if (ret) {
dev_err(&pdev->dev, "can't claim irq %d\n", irq);
return ret;
}
init_waitqueue_head(&i2c_imx->queue);
i2c_set_adapdata(&i2c_imx->adapter, i2c_imx);
bitrate = IMX_I2C_BIT_RATE;
ret = of_property_read_u32(pdev->dev.of_node,
"clock-frequency", &bitrate);
if (ret < 0 && pdata && pdata->bitrate)
bitrate = pdata->bitrate;
i2c_imx_set_clk(i2c_imx, bitrate);
writeb(0, i2c_imx->base + IMX_I2C_I2CR);
writeb(0, i2c_imx->base + IMX_I2C_I2SR);
ret = i2c_add_numbered_adapter(&i2c_imx->adapter);
if (ret < 0) {
dev_err(&pdev->dev, "registration failed\n");
return ret;
}
of_i2c_register_devices(&i2c_imx->adapter);
platform_set_drvdata(pdev, i2c_imx);
dev_dbg(&i2c_imx->adapter.dev, "claimed irq %d\n", irq);
dev_dbg(&i2c_imx->adapter.dev, "device resources from 0x%x to 0x%x\n",
res->start, res->end);
dev_dbg(&i2c_imx->adapter.dev, "allocated %d bytes at 0x%x\n",
resource_size(res), res->start);
dev_dbg(&i2c_imx->adapter.dev, "adapter name: \"%s\"\n",
i2c_imx->adapter.name);
dev_dbg(&i2c_imx->adapter.dev, "IMX I2C adapter registered\n");
return 0;
}
static int __exit i2c_imx_remove(struct platform_device *pdev)
{
struct imx_i2c_struct *i2c_imx = platform_get_drvdata(pdev);
dev_dbg(&i2c_imx->adapter.dev, "adapter removed\n");
i2c_del_adapter(&i2c_imx->adapter);
platform_set_drvdata(pdev, NULL);
writeb(0, i2c_imx->base + IMX_I2C_IADR);
writeb(0, i2c_imx->base + IMX_I2C_IFDR);
writeb(0, i2c_imx->base + IMX_I2C_I2CR);
writeb(0, i2c_imx->base + IMX_I2C_I2SR);
return 0;
}
static int __init i2c_adap_imx_init(void)
{
return platform_driver_probe(&i2c_imx_driver, i2c_imx_probe);
}
static void __exit i2c_adap_imx_exit(void)
{
platform_driver_unregister(&i2c_imx_driver);
}
