static inline void
StartI2C(struct i2c_platform_data *adap)
{
pr_debug("StartI2C\n");
pic32_bus_writel(I2CCON_SEN, adap->base + PIC32_I2CxCONSET);
}
static inline void
StopI2C(struct i2c_platform_data *adap)
{
pr_debug("StopI2C\n");
pic32_bus_writel(I2CCON_PEN, adap->base + PIC32_I2CxCONSET);
}
static inline void
AckI2C(struct i2c_platform_data *adap)
{
pr_debug("AckI2C\n");
pic32_bus_writel(I2CCON_ACKDT, adap->base + PIC32_I2CxCONCLR);
pic32_bus_writel(I2CCON_ACKEN, adap->base + PIC32_I2CxCONSET);
}
static inline void
NotAckI2C(struct i2c_platform_data *adap)
{
pr_debug("NakI2C\n");
pic32_bus_writel(I2CCON_ACKDT, adap->base + PIC32_I2CxCONSET);
pic32_bus_writel(I2CCON_ACKEN, adap->base + PIC32_I2CxCONSET);
}
static inline int
IdleI2C(struct i2c_platform_data *adap)
{
int i;
pr_debug("IdleI2C\n");
for (i = 0; i < adap->ctl_timeout; i++) {
if (((pic32_bus_readl(adap->base + PIC32_I2CxCON) &
(I2CCON_ACKEN | I2CCON_RCEN | I2CCON_PEN | I2CCON_RSEN |
I2CCON_SEN)) == 0) &&
((pic32_bus_readl(adap->base + PIC32_I2CxSTAT) &
(I2CSTAT_TRSTAT)) == 0))
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static inline u32
MasterWriteI2C(struct i2c_platform_data *adap, u32 byte)
{
pr_debug("MasterWriteI2C\n");
pic32_bus_writel(byte, adap->base + PIC32_I2CxTRN);
return pic32_bus_readl(adap->base + PIC32_I2CxSTAT) & I2CSTAT_IWCOL;
}
static inline u32
MasterReadI2C(struct i2c_platform_data *adap)
{
pr_debug("MasterReadI2C\n");
pic32_bus_writel(I2CCON_RCEN, adap->base + PIC32_I2CxCONSET);
while (pic32_bus_readl(adap->base + PIC32_I2CxCON) & I2CCON_RCEN)
;
pic32_bus_writel(I2CSTAT_I2COV, adap->base + PIC32_I2CxSTATCLR);
return pic32_bus_readl(adap->base + PIC32_I2CxRCV);
}
static int
do_address(struct i2c_platform_data *adap, unsigned int addr, int rd)
{
pr_debug("doaddress\n");
IdleI2C(adap);
StartI2C(adap);
IdleI2C(adap);
addr <<= 1;
if (rd)
addr |= 1;
if (MasterWriteI2C(adap, addr))
return -EIO;
IdleI2C(adap);
if (pic32_bus_readl(adap->base + PIC32_I2CxSTAT) & I2CSTAT_ACKSTAT)
return -EIO;
return 0;
}
static int
i2c_read(struct i2c_platform_data *adap, unsigned char *buf,
unsigned int len)
{
int i;
u32 data;
pr_debug("i2c_read\n");
i = 0;
while (i < len) {
data = MasterReadI2C(adap);
buf[i++] = data;
if (i < len)
AckI2C(adap);
else
NotAckI2C(adap);
}
StopI2C(adap);
IdleI2C(adap);
return 0;
}
static int
i2c_write(struct i2c_platform_data *adap, unsigned char *buf,
unsigned int len)
{
int i;
u32 data;
pr_debug("i2c_write\n");
i = 0;
while (i < len) {
data = buf[i];
if (MasterWriteI2C(adap, data))
return -EIO;
IdleI2C(adap);
if (pic32_bus_readl(adap->base + PIC32_I2CxSTAT) &
I2CSTAT_ACKSTAT)
return -EIO;
i++;
}
StopI2C(adap);
IdleI2C(adap);
return 0;
}
static int
platform_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs, int num)
{
struct i2c_platform_data *adap = i2c_adap->algo_data;
struct i2c_msg *p;
int i, err = 0;
pr_debug("platform_xfer\n");
for (i = 0; i < num; i++) {
#define __BUFSIZE 80
int ii;
static char buf[__BUFSIZE];
char *b = buf;
p = &msgs[i];
b += sprintf(buf, " [%d bytes]", p->len);
if ((p->flags & I2C_M_RD) == 0) {
for (ii = 0; ii < p->len; ii++) {
if (b < &buf[__BUFSIZE-4]) {
b += sprintf(b, " %02x", p->buf[ii]);
} else {
strcat(b, "...");
break;
}
}
}
pr_debug("xfer%d: DevAddr: %04x Op:%s Data:%s\n", i, p->addr,
(p->flags & I2C_M_RD) ? "Rd" : "Wr", buf);
}
for (i = 0; !err && i < num; i++) {
p = &msgs[i];
err = do_address(adap, p->addr, p->flags & I2C_M_RD);
if (err || !p->len)
continue;
if (p->flags & I2C_M_RD)
err = i2c_read(adap, p->buf, p->len);
else
err = i2c_write(adap, p->buf, p->len);
}
if (err == 0)
err = num;
return err;
}
static u32
platform_func(struct i2c_adapter *adap)
{
pr_debug("platform_algo\n");
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static void i2c_platform_setup(struct i2c_platform_data *priv)
{
pr_debug("i2c_platform_setup\n");
pic32_bus_writel(500, priv->base + PIC32_I2CxBRG);
pic32_bus_writel(I2CCON_ON, priv->base + PIC32_I2CxCONCLR);
pic32_bus_writel(I2CCON_ON, priv->base + PIC32_I2CxCONSET);
pic32_bus_writel((I2CSTAT_BCL | I2CSTAT_IWCOL),
(priv->base + PIC32_I2CxSTATCLR));
}
static void i2c_platform_disable(struct i2c_platform_data *priv)
{
pr_debug("i2c_platform_disable\n");
}
static int __devinit
i2c_platform_probe(struct platform_device *pdev)
{
struct i2c_platform_data *priv;
struct resource *r;
int ret;
pr_debug("i2c_platform_probe\n");
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
ret = -ENODEV;
goto out;
}
priv = kzalloc(sizeof(struct i2c_platform_data), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto out;
}
#if 0
priv->base = bus_request_region(r->start, resource_size(r),
pdev->name);
#else
priv->base = r->start;
#endif
if (!priv->base) {
ret = -EBUSY;
goto out_mem;
}
priv->xfer_timeout = 200;
priv->ack_timeout = 200;
priv->ctl_timeout = 200;
priv->adap.nr = pdev->id;
priv->adap.algo = &platform_algo;
priv->adap.algo_data = priv;
priv->adap.dev.parent = &pdev->dev;
strlcpy(priv->adap.name, "PIC32 I2C", sizeof(priv->adap.name));
i2c_platform_setup(priv);
ret = i2c_add_numbered_adapter(&priv->adap);
if (ret == 0) {
platform_set_drvdata(pdev, priv);
return 0;
}
i2c_platform_disable(priv);
out_mem:
kfree(priv);
out:
return ret;
}
static int __devexit
i2c_platform_remove(struct platform_device *pdev)
{
struct i2c_platform_data *priv = platform_get_drvdata(pdev);
pr_debug("i2c_platform_remove\n");
platform_set_drvdata(pdev, NULL);
i2c_del_adapter(&priv->adap);
i2c_platform_disable(priv);
kfree(priv);
return 0;
}
static int
i2c_platform_suspend(struct platform_device *pdev, pm_message_t state)
{
struct i2c_platform_data *priv = platform_get_drvdata(pdev);
dev_dbg(&pdev->dev, "i2c_platform_disable\n");
i2c_platform_disable(priv);
return 0;
}
static int
i2c_platform_resume(struct platform_device *pdev)
{
struct i2c_platform_data *priv = platform_get_drvdata(pdev);
dev_dbg(&pdev->dev, "i2c_platform_setup\n");
i2c_platform_setup(priv);
return 0;
}
static int __init
i2c_platform_init(void)
{
pr_debug("i2c_platform_init\n");
return platform_driver_register(&i2c_platform_driver);
}
static void __exit
i2c_platform_exit(void)
{
pr_debug("i2c_platform_exit\n");
platform_driver_unregister(&i2c_platform_driver);
}
