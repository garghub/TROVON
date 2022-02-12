static inline void WR(struct i2c_au1550_data *a, int r, unsigned long v)
{
__raw_writel(v, a->psc_base + r);
wmb();
}
static inline unsigned long RD(struct i2c_au1550_data *a, int r)
{
return __raw_readl(a->psc_base + r);
}
static int wait_xfer_done(struct i2c_au1550_data *adap)
{
int i;
for (i = 0; i < adap->xfer_timeout; i++) {
if (RD(adap, PSC_SMBSTAT) & PSC_SMBSTAT_TE)
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static int wait_ack(struct i2c_au1550_data *adap)
{
unsigned long stat;
if (wait_xfer_done(adap))
return -ETIMEDOUT;
stat = RD(adap, PSC_SMBEVNT);
if ((stat & (PSC_SMBEVNT_DN | PSC_SMBEVNT_AN | PSC_SMBEVNT_AL)) != 0)
return -ETIMEDOUT;
return 0;
}
static int wait_master_done(struct i2c_au1550_data *adap)
{
int i;
for (i = 0; i < 2 * adap->xfer_timeout; i++) {
if ((RD(adap, PSC_SMBEVNT) & PSC_SMBEVNT_MD) != 0)
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static int
do_address(struct i2c_au1550_data *adap, unsigned int addr, int rd, int q)
{
unsigned long stat;
stat = RD(adap, PSC_SMBSTAT);
WR(adap, PSC_SMBEVNT, PSC_SMBEVNT_ALLCLR);
if (!(stat & PSC_SMBSTAT_TE) || !(stat & PSC_SMBSTAT_RE)) {
WR(adap, PSC_SMBPCR, PSC_SMBPCR_DC);
while ((RD(adap, PSC_SMBPCR) & PSC_SMBPCR_DC) != 0)
cpu_relax();
udelay(50);
}
addr <<= 1;
if (rd)
addr |= 1;
if (q)
addr |= PSC_SMBTXRX_STP;
WR(adap, PSC_SMBTXRX, addr);
WR(adap, PSC_SMBPCR, PSC_SMBPCR_MS);
if (wait_ack(adap))
return -EIO;
return (q) ? wait_master_done(adap) : 0;
}
static int wait_for_rx_byte(struct i2c_au1550_data *adap, unsigned char *out)
{
int j;
if (wait_xfer_done(adap))
return -EIO;
j = adap->xfer_timeout * 100;
do {
j--;
if (j <= 0)
return -EIO;
if ((RD(adap, PSC_SMBSTAT) & PSC_SMBSTAT_RE) == 0)
j = 0;
else
udelay(1);
} while (j > 0);
*out = RD(adap, PSC_SMBTXRX);
return 0;
}
static int i2c_read(struct i2c_au1550_data *adap, unsigned char *buf,
unsigned int len)
{
int i;
if (len == 0)
return 0;
i = 0;
while (i < (len - 1)) {
WR(adap, PSC_SMBTXRX, 0);
if (wait_for_rx_byte(adap, &buf[i]))
return -EIO;
i++;
}
WR(adap, PSC_SMBTXRX, PSC_SMBTXRX_STP);
if (wait_master_done(adap))
return -EIO;
buf[i] = (unsigned char)(RD(adap, PSC_SMBTXRX) & 0xff);
return 0;
}
static int i2c_write(struct i2c_au1550_data *adap, unsigned char *buf,
unsigned int len)
{
int i;
unsigned long data;
if (len == 0)
return 0;
i = 0;
while (i < (len-1)) {
data = buf[i];
WR(adap, PSC_SMBTXRX, data);
if (wait_ack(adap))
return -EIO;
i++;
}
data = buf[i];
data |= PSC_SMBTXRX_STP;
WR(adap, PSC_SMBTXRX, data);
if (wait_master_done(adap))
return -EIO;
return 0;
}
static int
au1550_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs, int num)
{
struct i2c_au1550_data *adap = i2c_adap->algo_data;
struct i2c_msg *p;
int i, err = 0;
WR(adap, PSC_CTRL, PSC_CTRL_ENABLE);
for (i = 0; !err && i < num; i++) {
p = &msgs[i];
err = do_address(adap, p->addr, p->flags & I2C_M_RD,
(p->len == 0));
if (err || !p->len)
continue;
if (p->flags & I2C_M_RD)
err = i2c_read(adap, p->buf, p->len);
else
err = i2c_write(adap, p->buf, p->len);
}
if (err == 0)
err = num;
WR(adap, PSC_CTRL, PSC_CTRL_SUSPEND);
return err;
}
static u32 au1550_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static void i2c_au1550_setup(struct i2c_au1550_data *priv)
{
unsigned long cfg;
WR(priv, PSC_CTRL, PSC_CTRL_DISABLE);
WR(priv, PSC_SEL, PSC_SEL_PS_SMBUSMODE);
WR(priv, PSC_SMBCFG, 0);
WR(priv, PSC_CTRL, PSC_CTRL_ENABLE);
while ((RD(priv, PSC_SMBSTAT) & PSC_SMBSTAT_SR) == 0)
cpu_relax();
cfg = PSC_SMBCFG_RT_FIFO8 | PSC_SMBCFG_TT_FIFO8 | PSC_SMBCFG_DD_DISABLE;
WR(priv, PSC_SMBCFG, cfg);
cfg |= PSC_SMBCFG_SET_DIV(PSC_SMBCFG_DIV8);
WR(priv, PSC_SMBCFG, cfg);
WR(priv, PSC_SMBMSK, PSC_SMBMSK_ALLMASK);
WR(priv, PSC_SMBTMR, PSC_SMBTMR_SET_TH(0) | PSC_SMBTMR_SET_PS(20) | \
PSC_SMBTMR_SET_PU(20) | PSC_SMBTMR_SET_SH(20) | \
PSC_SMBTMR_SET_SU(20) | PSC_SMBTMR_SET_CL(20) | \
PSC_SMBTMR_SET_CH(20));
cfg |= PSC_SMBCFG_DE_ENABLE;
WR(priv, PSC_SMBCFG, cfg);
while ((RD(priv, PSC_SMBSTAT) & PSC_SMBSTAT_SR) == 0)
cpu_relax();
WR(priv, PSC_CTRL, PSC_CTRL_SUSPEND);
}
static void i2c_au1550_disable(struct i2c_au1550_data *priv)
{
WR(priv, PSC_SMBCFG, 0);
WR(priv, PSC_CTRL, PSC_CTRL_DISABLE);
}
static int
i2c_au1550_probe(struct platform_device *pdev)
{
struct i2c_au1550_data *priv;
struct resource *r;
int ret;
priv = devm_kzalloc(&pdev->dev, sizeof(struct i2c_au1550_data),
GFP_KERNEL);
if (!priv)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->psc_base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(priv->psc_base))
return PTR_ERR(priv->psc_base);
priv->xfer_timeout = 200;
priv->adap.nr = pdev->id;
priv->adap.algo = &au1550_algo;
priv->adap.algo_data = priv;
priv->adap.dev.parent = &pdev->dev;
strlcpy(priv->adap.name, "Au1xxx PSC I2C", sizeof(priv->adap.name));
i2c_au1550_setup(priv);
ret = i2c_add_numbered_adapter(&priv->adap);
if (ret) {
i2c_au1550_disable(priv);
return ret;
}
platform_set_drvdata(pdev, priv);
return 0;
}
static int i2c_au1550_remove(struct platform_device *pdev)
{
struct i2c_au1550_data *priv = platform_get_drvdata(pdev);
i2c_del_adapter(&priv->adap);
i2c_au1550_disable(priv);
return 0;
}
static int i2c_au1550_suspend(struct device *dev)
{
struct i2c_au1550_data *priv = dev_get_drvdata(dev);
i2c_au1550_disable(priv);
return 0;
}
static int i2c_au1550_resume(struct device *dev)
{
struct i2c_au1550_data *priv = dev_get_drvdata(dev);
i2c_au1550_setup(priv);
return 0;
}
