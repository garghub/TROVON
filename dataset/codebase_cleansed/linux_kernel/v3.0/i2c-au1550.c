static int
wait_xfer_done(struct i2c_au1550_data *adap)
{
u32 stat;
int i;
volatile psc_smb_t *sp;
sp = (volatile psc_smb_t *)(adap->psc_base);
for (i = 0; i < adap->xfer_timeout; i++) {
stat = sp->psc_smbstat;
au_sync();
if ((stat & PSC_SMBSTAT_TE) != 0)
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static int
wait_ack(struct i2c_au1550_data *adap)
{
u32 stat;
volatile psc_smb_t *sp;
if (wait_xfer_done(adap))
return -ETIMEDOUT;
sp = (volatile psc_smb_t *)(adap->psc_base);
stat = sp->psc_smbevnt;
au_sync();
if ((stat & (PSC_SMBEVNT_DN | PSC_SMBEVNT_AN | PSC_SMBEVNT_AL)) != 0)
return -ETIMEDOUT;
return 0;
}
static int
wait_master_done(struct i2c_au1550_data *adap)
{
u32 stat;
int i;
volatile psc_smb_t *sp;
sp = (volatile psc_smb_t *)(adap->psc_base);
for (i = 0; i < adap->xfer_timeout; i++) {
stat = sp->psc_smbevnt;
au_sync();
if ((stat & PSC_SMBEVNT_MD) != 0)
return 0;
udelay(1);
}
return -ETIMEDOUT;
}
static int
do_address(struct i2c_au1550_data *adap, unsigned int addr, int rd, int q)
{
volatile psc_smb_t *sp;
u32 stat;
sp = (volatile psc_smb_t *)(adap->psc_base);
stat = sp->psc_smbstat;
sp->psc_smbevnt = PSC_SMBEVNT_ALLCLR;
au_sync();
if (!(stat & PSC_SMBSTAT_TE) || !(stat & PSC_SMBSTAT_RE)) {
sp->psc_smbpcr = PSC_SMBPCR_DC;
au_sync();
do {
stat = sp->psc_smbpcr;
au_sync();
} while ((stat & PSC_SMBPCR_DC) != 0);
udelay(50);
}
addr <<= 1;
if (rd)
addr |= 1;
if (q)
addr |= PSC_SMBTXRX_STP;
sp->psc_smbtxrx = addr;
au_sync();
sp->psc_smbpcr = PSC_SMBPCR_MS;
au_sync();
if (wait_ack(adap))
return -EIO;
return (q) ? wait_master_done(adap) : 0;
}
static u32
wait_for_rx_byte(struct i2c_au1550_data *adap, u32 *ret_data)
{
int j;
u32 data, stat;
volatile psc_smb_t *sp;
if (wait_xfer_done(adap))
return -EIO;
sp = (volatile psc_smb_t *)(adap->psc_base);
j = adap->xfer_timeout * 100;
do {
j--;
if (j <= 0)
return -EIO;
stat = sp->psc_smbstat;
au_sync();
if ((stat & PSC_SMBSTAT_RE) == 0)
j = 0;
else
udelay(1);
} while (j > 0);
data = sp->psc_smbtxrx;
au_sync();
*ret_data = data;
return 0;
}
static int
i2c_read(struct i2c_au1550_data *adap, unsigned char *buf,
unsigned int len)
{
int i;
u32 data;
volatile psc_smb_t *sp;
if (len == 0)
return 0;
sp = (volatile psc_smb_t *)(adap->psc_base);
i = 0;
while (i < (len-1)) {
sp->psc_smbtxrx = 0;
au_sync();
if (wait_for_rx_byte(adap, &data))
return -EIO;
buf[i] = data;
i++;
}
sp->psc_smbtxrx = PSC_SMBTXRX_STP;
au_sync();
if (wait_master_done(adap))
return -EIO;
data = sp->psc_smbtxrx;
au_sync();
buf[i] = data;
return 0;
}
static int
i2c_write(struct i2c_au1550_data *adap, unsigned char *buf,
unsigned int len)
{
int i;
u32 data;
volatile psc_smb_t *sp;
if (len == 0)
return 0;
sp = (volatile psc_smb_t *)(adap->psc_base);
i = 0;
while (i < (len-1)) {
data = buf[i];
sp->psc_smbtxrx = data;
au_sync();
if (wait_ack(adap))
return -EIO;
i++;
}
data = buf[i];
data |= PSC_SMBTXRX_STP;
sp->psc_smbtxrx = data;
au_sync();
if (wait_master_done(adap))
return -EIO;
return 0;
}
static int
au1550_xfer(struct i2c_adapter *i2c_adap, struct i2c_msg *msgs, int num)
{
struct i2c_au1550_data *adap = i2c_adap->algo_data;
volatile psc_smb_t *sp = (volatile psc_smb_t *)adap->psc_base;
struct i2c_msg *p;
int i, err = 0;
sp->psc_ctrl = PSC_CTRL_ENABLE;
au_sync();
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
sp->psc_ctrl = PSC_CTRL_SUSPEND;
au_sync();
return err;
}
static u32
au1550_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | I2C_FUNC_SMBUS_EMUL;
}
static void i2c_au1550_setup(struct i2c_au1550_data *priv)
{
volatile psc_smb_t *sp = (volatile psc_smb_t *)priv->psc_base;
u32 stat;
sp->psc_ctrl = PSC_CTRL_DISABLE;
au_sync();
sp->psc_sel = PSC_SEL_PS_SMBUSMODE;
sp->psc_smbcfg = 0;
au_sync();
sp->psc_ctrl = PSC_CTRL_ENABLE;
au_sync();
do {
stat = sp->psc_smbstat;
au_sync();
} while ((stat & PSC_SMBSTAT_SR) == 0);
sp->psc_smbcfg = (PSC_SMBCFG_RT_FIFO8 | PSC_SMBCFG_TT_FIFO8 |
PSC_SMBCFG_DD_DISABLE);
sp->psc_smbcfg |= PSC_SMBCFG_SET_DIV(PSC_SMBCFG_DIV8);
sp->psc_smbmsk = PSC_SMBMSK_ALLMASK;
au_sync();
sp->psc_smbtmr = PSC_SMBTMR_SET_TH(0) | PSC_SMBTMR_SET_PS(15) | \
PSC_SMBTMR_SET_PU(15) | PSC_SMBTMR_SET_SH(15) | \
PSC_SMBTMR_SET_SU(15) | PSC_SMBTMR_SET_CL(15) | \
PSC_SMBTMR_SET_CH(15);
au_sync();
sp->psc_smbcfg |= PSC_SMBCFG_DE_ENABLE;
do {
stat = sp->psc_smbstat;
au_sync();
} while ((stat & PSC_SMBSTAT_SR) == 0);
sp->psc_ctrl = PSC_CTRL_SUSPEND;
au_sync();
}
static void i2c_au1550_disable(struct i2c_au1550_data *priv)
{
volatile psc_smb_t *sp = (volatile psc_smb_t *)priv->psc_base;
sp->psc_smbcfg = 0;
sp->psc_ctrl = PSC_CTRL_DISABLE;
au_sync();
}
static int __devinit
i2c_au1550_probe(struct platform_device *pdev)
{
struct i2c_au1550_data *priv;
struct resource *r;
int ret;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
ret = -ENODEV;
goto out;
}
priv = kzalloc(sizeof(struct i2c_au1550_data), GFP_KERNEL);
if (!priv) {
ret = -ENOMEM;
goto out;
}
priv->ioarea = request_mem_region(r->start, resource_size(r),
pdev->name);
if (!priv->ioarea) {
ret = -EBUSY;
goto out_mem;
}
priv->psc_base = CKSEG1ADDR(r->start);
priv->xfer_timeout = 200;
priv->ack_timeout = 200;
priv->adap.nr = pdev->id;
priv->adap.algo = &au1550_algo;
priv->adap.algo_data = priv;
priv->adap.dev.parent = &pdev->dev;
strlcpy(priv->adap.name, "Au1xxx PSC I2C", sizeof(priv->adap.name));
i2c_au1550_setup(priv);
ret = i2c_add_numbered_adapter(&priv->adap);
if (ret == 0) {
platform_set_drvdata(pdev, priv);
return 0;
}
i2c_au1550_disable(priv);
release_resource(priv->ioarea);
kfree(priv->ioarea);
out_mem:
kfree(priv);
out:
return ret;
}
static int __devexit
i2c_au1550_remove(struct platform_device *pdev)
{
struct i2c_au1550_data *priv = platform_get_drvdata(pdev);
platform_set_drvdata(pdev, NULL);
i2c_del_adapter(&priv->adap);
i2c_au1550_disable(priv);
release_resource(priv->ioarea);
kfree(priv->ioarea);
kfree(priv);
return 0;
}
static int
i2c_au1550_suspend(struct platform_device *pdev, pm_message_t state)
{
struct i2c_au1550_data *priv = platform_get_drvdata(pdev);
i2c_au1550_disable(priv);
return 0;
}
static int
i2c_au1550_resume(struct platform_device *pdev)
{
struct i2c_au1550_data *priv = platform_get_drvdata(pdev);
i2c_au1550_setup(priv);
return 0;
}
static int __init
i2c_au1550_init(void)
{
return platform_driver_register(&au1xpsc_smbus_driver);
}
static void __exit
i2c_au1550_exit(void)
{
platform_driver_unregister(&au1xpsc_smbus_driver);
}
