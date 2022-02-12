static inline void OUT32(struct cami2c *cam, int reg, unsigned long val)
{
__raw_writel(val, (unsigned long)cam->iobase + reg);
}
static inline unsigned long IN32(struct cami2c *cam, int reg)
{
return __raw_readl((unsigned long)cam->iobase + reg);
}
static irqreturn_t sh7760_i2c_irq(int irq, void *ptr)
{
struct cami2c *id = ptr;
struct i2c_msg *msg = id->msg;
char *data = msg->buf;
unsigned long msr, fsr, fier, len;
msr = IN32(id, I2CMSR);
fsr = IN32(id, I2CFSR);
if (msr & MSR_MAL) {
OUT32(id, I2CMCR, 0);
OUT32(id, I2CSCR, 0);
OUT32(id, I2CSAR, 0);
id->status |= IDS_DONE | IDS_ARBLOST;
goto out;
}
if (msr & MSR_MNR) {
udelay(100);
OUT32(id, I2CFCR, FCR_RFRST | FCR_TFRST);
OUT32(id, I2CMCR, MCR_MIE | MCR_FSB);
OUT32(id, I2CFIER, 0);
OUT32(id, I2CMIER, MIE_MSTE);
OUT32(id, I2CSCR, 0);
OUT32(id, I2CSAR, 0);
id->status |= IDS_NACK;
msr &= ~MSR_MAT;
fsr = 0;
}
if (msr & MSR_MST) {
id->status |= IDS_DONE;
goto out;
}
if (msr & MSR_MAT)
OUT32(id, I2CMCR, MCR_MIE);
fier = IN32(id, I2CFIER);
if (fsr & FSR_RDF) {
len = IN32(id, I2CRFDR);
if (msg->len <= len) {
if (id->flags & IDF_STOP) {
OUT32(id, I2CMCR, MCR_MIE | MCR_FSB);
OUT32(id, I2CFIER, 0);
udelay(5);
} else {
id->status |= IDS_DONE;
fsr &= ~FSR_RDF;
}
}
while (msg->len && len) {
*data++ = IN32(id, I2CRXTX);
msg->len--;
len--;
}
if (msg->len) {
len = (msg->len >= FIFO_SIZE) ? FIFO_SIZE - 1
: msg->len - 1;
OUT32(id, I2CFCR, FCR_TFRST | ((len & 0xf) << 4));
}
} else if (id->flags & IDF_SEND) {
if ((fsr & FSR_TEND) && (msg->len < 1)) {
if (id->flags & IDF_STOP) {
OUT32(id, I2CMCR, MCR_MIE | MCR_FSB);
} else {
id->status |= IDS_DONE;
fsr &= ~FSR_TEND;
}
}
if (fsr & FSR_TDFE) {
while (msg->len && (IN32(id, I2CTFDR) < FIFO_SIZE)) {
OUT32(id, I2CRXTX, *data++);
msg->len--;
}
if (msg->len < 1) {
fier &= ~FIER_TXIE;
OUT32(id, I2CFIER, fier);
} else {
len = (msg->len >= FIFO_SIZE) ? 2 : 0;
OUT32(id, I2CFCR,
FCR_RFRST | ((len & 3) << 2));
}
}
}
out:
if (id->status & IDS_DONE) {
OUT32(id, I2CMIER, 0);
OUT32(id, I2CFIER, 0);
id->msg = NULL;
complete(&id->xfer_done);
}
OUT32(id, I2CMSR, ~msr);
OUT32(id, I2CFSR, ~fsr);
OUT32(id, I2CSSR, 0);
return IRQ_HANDLED;
}
static void sh7760_i2c_mrecv(struct cami2c *id)
{
int len;
id->flags |= IDF_RECV;
OUT32(id, I2CSAR, 0xfe);
OUT32(id, I2CMAR, (id->msg->addr << 1) | 1);
if (id->msg->len >= FIFO_SIZE)
len = FIFO_SIZE - 1;
else
len = id->msg->len - 1;
OUT32(id, I2CFCR, FCR_RFRST | FCR_TFRST);
OUT32(id, I2CFCR, FCR_TFRST | ((len & 0xF) << 4));
OUT32(id, I2CMSR, 0);
OUT32(id, I2CMCR, MCR_MIE | MCR_ESG);
OUT32(id, I2CMIER, MIE_MNRE | MIE_MALE | MIE_MSTE | MIE_MATE);
OUT32(id, I2CFIER, FIER_RXIE);
}
static void sh7760_i2c_msend(struct cami2c *id)
{
int len;
id->flags |= IDF_SEND;
OUT32(id, I2CSAR, 0xfe);
OUT32(id, I2CMAR, (id->msg->addr << 1) | 0);
if (id->msg->len >= FIFO_SIZE)
len = 2;
else
len = 0;
OUT32(id, I2CFCR, FCR_RFRST | FCR_TFRST);
OUT32(id, I2CFCR, FCR_RFRST | ((len & 3) << 2));
while (id->msg->len && IN32(id, I2CTFDR) < FIFO_SIZE) {
OUT32(id, I2CRXTX, *(id->msg->buf));
(id->msg->len)--;
(id->msg->buf)++;
}
OUT32(id, I2CMSR, 0);
OUT32(id, I2CMCR, MCR_MIE | MCR_ESG);
OUT32(id, I2CFSR, 0);
OUT32(id, I2CMIER, MIE_MNRE | MIE_MALE | MIE_MSTE | MIE_MATE);
OUT32(id, I2CFIER, FIER_TEIE | (id->msg->len ? FIER_TXIE : 0));
}
static inline int sh7760_i2c_busy_check(struct cami2c *id)
{
return (IN32(id, I2CMCR) & MCR_FSDA);
}
static int sh7760_i2c_master_xfer(struct i2c_adapter *adap,
struct i2c_msg *msgs,
int num)
{
struct cami2c *id = adap->algo_data;
int i, retr;
if (sh7760_i2c_busy_check(id)) {
dev_err(&adap->dev, "sh7760-i2c%d: bus busy!\n", adap->nr);
return -EBUSY;
}
i = 0;
while (i < num) {
retr = adap->retries;
retry:
id->flags = ((i == (num-1)) ? IDF_STOP : 0);
id->status = 0;
id->msg = msgs;
init_completion(&id->xfer_done);
if (msgs->flags & I2C_M_RD)
sh7760_i2c_mrecv(id);
else
sh7760_i2c_msend(id);
wait_for_completion(&id->xfer_done);
if (id->status == 0) {
num = -EIO;
break;
}
if (id->status & IDS_NACK) {
mdelay(1);
num = -EREMOTEIO;
break;
}
if (id->status & IDS_ARBLOST) {
if (retr--) {
mdelay(2);
goto retry;
}
num = -EREMOTEIO;
break;
}
msgs++;
i++;
}
id->msg = NULL;
id->flags = 0;
id->status = 0;
OUT32(id, I2CMCR, 0);
OUT32(id, I2CMSR, 0);
OUT32(id, I2CMIER, 0);
OUT32(id, I2CFIER, 0);
OUT32(id, I2CSCR, 0);
OUT32(id, I2CSAR, 0);
OUT32(id, I2CSSR, 0);
return num;
}
static u32 sh7760_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}
static int __devinit calc_CCR(unsigned long scl_hz)
{
struct clk *mclk;
unsigned long mck, m1, dff, odff, iclk;
signed char cdf, cdfm;
int scgd, scgdm, scgds;
mclk = clk_get(NULL, "peripheral_clk");
if (IS_ERR(mclk)) {
return PTR_ERR(mclk);
} else {
mck = mclk->rate;
clk_put(mclk);
}
odff = scl_hz;
scgdm = cdfm = m1 = 0;
for (cdf = 3; cdf >= 0; cdf--) {
iclk = mck / (1 + cdf);
if (iclk >= 20000000)
continue;
scgds = ((iclk / scl_hz) - 20) >> 3;
for (scgd = scgds; (scgd < 63) && scgd <= scgds + 1; scgd++) {
m1 = iclk / (20 + (scgd << 3));
dff = abs(scl_hz - m1);
if (dff < odff) {
odff = dff;
cdfm = cdf;
scgdm = scgd;
}
}
}
if (odff > (scl_hz >> 2))
return -EINVAL;
return ((scgdm << 2) | cdfm);
}
static int __devinit sh7760_i2c_probe(struct platform_device *pdev)
{
struct sh7760_i2c_platdata *pd;
struct resource *res;
struct cami2c *id;
int ret;
pd = pdev->dev.platform_data;
if (!pd) {
dev_err(&pdev->dev, "no platform_data!\n");
ret = -ENODEV;
goto out0;
}
id = kzalloc(sizeof(struct cami2c), GFP_KERNEL);
if (!id) {
dev_err(&pdev->dev, "no mem for private data\n");
ret = -ENOMEM;
goto out0;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "no mmio resources\n");
ret = -ENODEV;
goto out1;
}
id->ioarea = request_mem_region(res->start, REGSIZE, pdev->name);
if (!id->ioarea) {
dev_err(&pdev->dev, "mmio already reserved\n");
ret = -EBUSY;
goto out1;
}
id->iobase = ioremap(res->start, REGSIZE);
if (!id->iobase) {
dev_err(&pdev->dev, "cannot ioremap\n");
ret = -ENODEV;
goto out2;
}
id->irq = platform_get_irq(pdev, 0);
id->adap.nr = pdev->id;
id->adap.algo = &sh7760_i2c_algo;
id->adap.class = I2C_CLASS_HWMON | I2C_CLASS_SPD;
id->adap.retries = 3;
id->adap.algo_data = id;
id->adap.dev.parent = &pdev->dev;
snprintf(id->adap.name, sizeof(id->adap.name),
"SH7760 I2C at %08lx", (unsigned long)res->start);
OUT32(id, I2CMCR, 0);
OUT32(id, I2CMSR, 0);
OUT32(id, I2CMIER, 0);
OUT32(id, I2CMAR, 0);
OUT32(id, I2CSIER, 0);
OUT32(id, I2CSAR, 0);
OUT32(id, I2CSCR, 0);
OUT32(id, I2CSSR, 0);
OUT32(id, I2CFIER, 0);
OUT32(id, I2CFCR, FCR_RFRST | FCR_TFRST);
OUT32(id, I2CFSR, 0);
ret = calc_CCR(pd->speed_khz * 1000);
if (ret < 0) {
dev_err(&pdev->dev, "invalid SCL clock: %dkHz\n",
pd->speed_khz);
goto out3;
}
OUT32(id, I2CCCR, ret);
if (request_irq(id->irq, sh7760_i2c_irq, 0,
SH7760_I2C_DEVNAME, id)) {
dev_err(&pdev->dev, "cannot get irq %d\n", id->irq);
ret = -EBUSY;
goto out3;
}
ret = i2c_add_numbered_adapter(&id->adap);
if (ret < 0) {
dev_err(&pdev->dev, "reg adap failed: %d\n", ret);
goto out4;
}
platform_set_drvdata(pdev, id);
dev_info(&pdev->dev, "%d kHz mmio %08x irq %d\n",
pd->speed_khz, res->start, id->irq);
return 0;
out4:
free_irq(id->irq, id);
out3:
iounmap(id->iobase);
out2:
release_resource(id->ioarea);
kfree(id->ioarea);
out1:
kfree(id);
out0:
return ret;
}
static int __devexit sh7760_i2c_remove(struct platform_device *pdev)
{
struct cami2c *id = platform_get_drvdata(pdev);
i2c_del_adapter(&id->adap);
free_irq(id->irq, id);
iounmap(id->iobase);
release_resource(id->ioarea);
kfree(id->ioarea);
kfree(id);
platform_set_drvdata(pdev, NULL);
return 0;
}
