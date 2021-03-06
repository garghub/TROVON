static short poll_status(unsigned long bit)
{
int loop_cntr = 1000;
if (bit & I2C_STATUS_TFNF) {
do {
udelay(10);
} while (!(readl(I2C_STATUS) & bit) && (--loop_cntr > 0));
} else {
do {
if (readl(I2C_TAR) == I2C_TAR_EEPROM)
msleep(20);
else
udelay(10);
} while (!(readl(I2C_RXFLR) & 0xf) && (--loop_cntr > 0));
}
return (loop_cntr > 0);
}
static int xfer_read(struct i2c_adapter *adap, unsigned char *buf, int length)
{
int i2c_reg = *buf;
while (length--) {
if (!poll_status(I2C_STATUS_TFNF)) {
dev_dbg(&adap->dev, "Tx FIFO Not Full timeout\n");
return -ETIMEDOUT;
}
writel(i2c_reg | I2C_DATACMD_WRITE, I2C_DATACMD);
i2c_reg++;
writel(I2C_DATACMD_READ, I2C_DATACMD);
if (!poll_status(I2C_STATUS_RFNE)) {
dev_dbg(&adap->dev, "RXRDY timeout\n");
return -ETIMEDOUT;
}
*buf = (readl(I2C_DATACMD) & I2C_DATACMD_DAT_MASK);
buf++;
}
return 0;
}
static int xfer_write(struct i2c_adapter *adap, unsigned char *buf, int length)
{
int i2c_reg = *buf;
if (i2c_reg == -1) {
printk(KERN_WARNING "Error i2c reg\n");
return -ETIMEDOUT;
}
if (length == 1)
return 0;
buf++;
length--;
while (length--) {
writel(i2c_reg | I2C_DATACMD_WRITE, I2C_DATACMD);
writel(*buf | I2C_DATACMD_WRITE, I2C_DATACMD);
msleep(20);
i2c_reg++;
buf++;
}
return 0;
}
static int puv3_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *pmsg,
int num)
{
int i, ret;
unsigned char swap;
writel(I2C_ENABLE_DISABLE, I2C_ENABLE);
writel(I2C_CON_MASTER | I2C_CON_SPEED_STD | I2C_CON_SLAVEDISABLE, I2C_CON);
writel(pmsg->addr, I2C_TAR);
writel(I2C_ENABLE_ENABLE, I2C_ENABLE);
dev_dbg(&adap->dev, "puv3_i2c_xfer: processing %d messages:\n", num);
for (i = 0; i < num; i++) {
dev_dbg(&adap->dev, " #%d: %sing %d byte%s %s 0x%02x\n", i,
pmsg->flags & I2C_M_RD ? "read" : "writ",
pmsg->len, pmsg->len > 1 ? "s" : "",
pmsg->flags & I2C_M_RD ? "from" : "to", pmsg->addr);
if (pmsg->len && pmsg->buf) {
if (pmsg->flags & I2C_M_RD)
ret = xfer_read(adap, pmsg->buf, pmsg->len);
else
ret = xfer_write(adap, pmsg->buf, pmsg->len);
if (ret)
return ret;
}
dev_dbg(&adap->dev, "transfer complete\n");
pmsg++;
}
if (pmsg->addr == I2C_TAR_PWIC) {
swap = pmsg->buf[0];
pmsg->buf[0] = pmsg->buf[1];
pmsg->buf[1] = swap;
}
return i;
}
static u32 puv3_i2c_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int __devinit puv3_i2c_probe(struct platform_device *pdev)
{
struct i2c_adapter *adapter;
struct resource *mem;
int rc;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem)
return -ENODEV;
if (!request_mem_region(mem->start, resource_size(mem), "puv3_i2c"))
return -EBUSY;
adapter = kzalloc(sizeof(struct i2c_adapter), GFP_KERNEL);
if (adapter == NULL) {
dev_err(&pdev->dev, "can't allocate inteface!\n");
rc = -ENOMEM;
goto fail_nomem;
}
snprintf(adapter->name, sizeof(adapter->name), "PUV3-I2C at 0x%08x",
mem->start);
adapter->algo = &puv3_i2c_algorithm;
adapter->class = I2C_CLASS_HWMON;
adapter->dev.parent = &pdev->dev;
platform_set_drvdata(pdev, adapter);
adapter->nr = pdev->id;
rc = i2c_add_numbered_adapter(adapter);
if (rc) {
dev_err(&pdev->dev, "Adapter '%s' registration failed\n",
adapter->name);
goto fail_add_adapter;
}
dev_info(&pdev->dev, "PKUnity v3 i2c bus adapter.\n");
return 0;
fail_add_adapter:
platform_set_drvdata(pdev, NULL);
kfree(adapter);
fail_nomem:
release_mem_region(mem->start, resource_size(mem));
return rc;
}
static int __devexit puv3_i2c_remove(struct platform_device *pdev)
{
struct i2c_adapter *adapter = platform_get_drvdata(pdev);
struct resource *mem;
int rc;
rc = i2c_del_adapter(adapter);
if (rc) {
dev_err(&pdev->dev, "Adapter '%s' delete fail\n",
adapter->name);
return rc;
}
put_device(&pdev->dev);
platform_set_drvdata(pdev, NULL);
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(mem->start, resource_size(mem));
return rc;
}
static int puv3_i2c_suspend(struct platform_device *dev, pm_message_t state)
{
int poll_count;
writel(I2C_ENABLE_DISABLE, I2C_ENABLE);
for (poll_count = 0; poll_count < 50; poll_count++) {
if (readl(I2C_ENSTATUS) & I2C_ENSTATUS_ENABLE)
udelay(25);
}
return 0;
}
static int puv3_i2c_resume(struct platform_device *dev)
{
return 0 ;
}
