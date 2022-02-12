static void __devinit at91_twi_hwinit(void)
{
unsigned long cdiv, ckdiv;
at91_twi_write(AT91_TWI_IDR, 0xffffffff);
at91_twi_write(AT91_TWI_CR, AT91_TWI_SWRST);
at91_twi_write(AT91_TWI_CR, AT91_TWI_MSEN);
cdiv = (clk_get_rate(twi_clk) / (2 * TWI_CLOCK)) - 3;
cdiv = cdiv + 1;
ckdiv = 0;
while (cdiv > 255) {
ckdiv++;
cdiv = cdiv >> 1;
}
if (cpu_is_at91rm9200()) {
if (ckdiv > 5) {
printk(KERN_ERR "AT91 I2C: Invalid TWI_CLOCK value!\n");
ckdiv = 5;
}
}
at91_twi_write(AT91_TWI_CWGR, (ckdiv << 16) | (cdiv << 8) | cdiv);
}
static short at91_poll_status(unsigned long bit)
{
int loop_cntr = 10000;
do {
udelay(10);
} while (!(at91_twi_read(AT91_TWI_SR) & bit) && (--loop_cntr > 0));
return (loop_cntr > 0);
}
static int xfer_read(struct i2c_adapter *adap, unsigned char *buf, int length)
{
at91_twi_write(AT91_TWI_CR, AT91_TWI_START);
while (length--) {
if (!length)
at91_twi_write(AT91_TWI_CR, AT91_TWI_STOP);
if (!at91_poll_status(AT91_TWI_RXRDY)) {
dev_dbg(&adap->dev, "RXRDY timeout\n");
return -ETIMEDOUT;
}
*buf++ = (at91_twi_read(AT91_TWI_RHR) & 0xff);
}
return 0;
}
static int xfer_write(struct i2c_adapter *adap, unsigned char *buf, int length)
{
at91_twi_write(AT91_TWI_THR, *buf++);
at91_twi_write(AT91_TWI_CR, AT91_TWI_START);
do {
if (!at91_poll_status(AT91_TWI_TXRDY)) {
dev_dbg(&adap->dev, "TXRDY timeout\n");
return -ETIMEDOUT;
}
length--;
if (length > 0)
at91_twi_write(AT91_TWI_THR, *buf++);
} while (length);
at91_twi_write(AT91_TWI_CR, AT91_TWI_STOP);
return 0;
}
static int at91_xfer(struct i2c_adapter *adap, struct i2c_msg *pmsg, int num)
{
int i, ret;
dev_dbg(&adap->dev, "at91_xfer: processing %d messages:\n", num);
for (i = 0; i < num; i++) {
dev_dbg(&adap->dev, " #%d: %sing %d byte%s %s 0x%02x\n", i,
pmsg->flags & I2C_M_RD ? "read" : "writ",
pmsg->len, pmsg->len > 1 ? "s" : "",
pmsg->flags & I2C_M_RD ? "from" : "to", pmsg->addr);
at91_twi_write(AT91_TWI_MMR, (pmsg->addr << 16)
| ((pmsg->flags & I2C_M_RD) ? AT91_TWI_MREAD : 0));
if (pmsg->len && pmsg->buf) {
if (pmsg->flags & I2C_M_RD)
ret = xfer_read(adap, pmsg->buf, pmsg->len);
else
ret = xfer_write(adap, pmsg->buf, pmsg->len);
if (ret)
return ret;
if (!at91_poll_status(AT91_TWI_TXCOMP)) {
dev_dbg(&adap->dev, "TXCOMP timeout\n");
return -ETIMEDOUT;
}
}
dev_dbg(&adap->dev, "transfer complete\n");
pmsg++;
}
return i;
}
static u32 at91_func(struct i2c_adapter *adapter)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static int __devinit at91_i2c_probe(struct platform_device *pdev)
{
struct i2c_adapter *adapter;
struct resource *res;
int rc;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENXIO;
if (!request_mem_region(res->start, resource_size(res), "at91_i2c"))
return -EBUSY;
twi_base = ioremap(res->start, resource_size(res));
if (!twi_base) {
rc = -ENOMEM;
goto fail0;
}
twi_clk = clk_get(NULL, "twi_clk");
if (IS_ERR(twi_clk)) {
dev_err(&pdev->dev, "no clock defined\n");
rc = -ENODEV;
goto fail1;
}
adapter = kzalloc(sizeof(struct i2c_adapter), GFP_KERNEL);
if (adapter == NULL) {
dev_err(&pdev->dev, "can't allocate inteface!\n");
rc = -ENOMEM;
goto fail2;
}
snprintf(adapter->name, sizeof(adapter->name), "AT91");
adapter->algo = &at91_algorithm;
adapter->class = I2C_CLASS_HWMON;
adapter->dev.parent = &pdev->dev;
platform_set_drvdata(pdev, adapter);
clk_enable(twi_clk);
at91_twi_hwinit();
rc = i2c_add_numbered_adapter(adapter);
if (rc) {
dev_err(&pdev->dev, "Adapter %s registration failed\n",
adapter->name);
goto fail3;
}
dev_info(&pdev->dev, "AT91 i2c bus driver.\n");
return 0;
fail3:
platform_set_drvdata(pdev, NULL);
kfree(adapter);
clk_disable(twi_clk);
fail2:
clk_put(twi_clk);
fail1:
iounmap(twi_base);
fail0:
release_mem_region(res->start, resource_size(res));
return rc;
}
static int __devexit at91_i2c_remove(struct platform_device *pdev)
{
struct i2c_adapter *adapter = platform_get_drvdata(pdev);
struct resource *res;
int rc;
rc = i2c_del_adapter(adapter);
platform_set_drvdata(pdev, NULL);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
iounmap(twi_base);
release_mem_region(res->start, resource_size(res));
clk_disable(twi_clk);
clk_put(twi_clk);
return rc;
}
static int at91_i2c_suspend(struct platform_device *pdev, pm_message_t mesg)
{
clk_disable(twi_clk);
return 0;
}
static int at91_i2c_resume(struct platform_device *pdev)
{
return clk_enable(twi_clk);
}
static int __init at91_i2c_init(void)
{
return platform_driver_register(&at91_i2c_driver);
}
static void __exit at91_i2c_exit(void)
{
platform_driver_unregister(&at91_i2c_driver);
}
