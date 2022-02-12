static irqreturn_t cpm_i2c_interrupt(int irq, void *dev_id)
{
struct cpm_i2c *cpm;
struct i2c_reg __iomem *i2c_reg;
struct i2c_adapter *adap = dev_id;
int i;
cpm = i2c_get_adapdata(dev_id);
i2c_reg = cpm->i2c_reg;
i = in_8(&i2c_reg->i2cer);
out_8(&i2c_reg->i2cer, i);
dev_dbg(&adap->dev, "Interrupt: %x\n", i);
wake_up(&cpm->i2c_wait);
return i ? IRQ_HANDLED : IRQ_NONE;
}
static void cpm_reset_i2c_params(struct cpm_i2c *cpm)
{
struct i2c_ram __iomem *i2c_ram = cpm->i2c_ram;
out_be16(&i2c_ram->tbase, (u8 __iomem *)cpm->tbase - DPRAM_BASE);
out_be16(&i2c_ram->rbase, (u8 __iomem *)cpm->rbase - DPRAM_BASE);
if (cpm->version == 1) {
out_8(&i2c_ram->tfcr, I2C_EB);
out_8(&i2c_ram->rfcr, I2C_EB);
} else {
out_8(&i2c_ram->tfcr, I2C_EB_CPM2);
out_8(&i2c_ram->rfcr, I2C_EB_CPM2);
}
out_be16(&i2c_ram->mrblr, CPM_MAX_READ);
out_be32(&i2c_ram->rstate, 0);
out_be32(&i2c_ram->rdp, 0);
out_be16(&i2c_ram->rbptr, 0);
out_be16(&i2c_ram->rbc, 0);
out_be32(&i2c_ram->rxtmp, 0);
out_be32(&i2c_ram->tstate, 0);
out_be32(&i2c_ram->tdp, 0);
out_be16(&i2c_ram->tbptr, 0);
out_be16(&i2c_ram->tbc, 0);
out_be32(&i2c_ram->txtmp, 0);
}
static void cpm_i2c_force_close(struct i2c_adapter *adap)
{
struct cpm_i2c *cpm = i2c_get_adapdata(adap);
struct i2c_reg __iomem *i2c_reg = cpm->i2c_reg;
dev_dbg(&adap->dev, "cpm_i2c_force_close()\n");
cpm_command(cpm->cp_command, CPM_CR_CLOSE_RX_BD);
out_8(&i2c_reg->i2cmr, 0x00);
out_8(&i2c_reg->i2cer, 0xff);
}
static void cpm_i2c_parse_message(struct i2c_adapter *adap,
struct i2c_msg *pmsg, int num, int tx, int rx)
{
cbd_t __iomem *tbdf;
cbd_t __iomem *rbdf;
u_char addr;
u_char *tb;
u_char *rb;
struct cpm_i2c *cpm = i2c_get_adapdata(adap);
tbdf = cpm->tbase + tx;
rbdf = cpm->rbase + rx;
addr = pmsg->addr << 1;
if (pmsg->flags & I2C_M_RD)
addr |= 1;
tb = cpm->txbuf[tx];
rb = cpm->rxbuf[rx];
rb = (u_char *) (((ulong) rb + 1) & ~1);
tb[0] = addr;
out_be16(&tbdf->cbd_datlen, pmsg->len + 1);
out_be16(&tbdf->cbd_sc, 0);
if (!(pmsg->flags & I2C_M_NOSTART))
setbits16(&tbdf->cbd_sc, BD_I2C_START);
if (tx + 1 == num)
setbits16(&tbdf->cbd_sc, BD_SC_LAST | BD_SC_WRAP);
if (pmsg->flags & I2C_M_RD) {
dev_dbg(&adap->dev, "cpm_i2c_read(abyte=0x%x)\n", addr);
out_be16(&rbdf->cbd_datlen, 0);
out_be16(&rbdf->cbd_sc, BD_SC_EMPTY | BD_SC_INTRPT);
if (rx + 1 == CPM_MAXBD)
setbits16(&rbdf->cbd_sc, BD_SC_WRAP);
eieio();
setbits16(&tbdf->cbd_sc, BD_SC_READY);
} else {
dev_dbg(&adap->dev, "cpm_i2c_write(abyte=0x%x)\n", addr);
memcpy(tb+1, pmsg->buf, pmsg->len);
eieio();
setbits16(&tbdf->cbd_sc, BD_SC_READY | BD_SC_INTRPT);
}
}
static int cpm_i2c_check_message(struct i2c_adapter *adap,
struct i2c_msg *pmsg, int tx, int rx)
{
cbd_t __iomem *tbdf;
cbd_t __iomem *rbdf;
u_char *tb;
u_char *rb;
struct cpm_i2c *cpm = i2c_get_adapdata(adap);
tbdf = cpm->tbase + tx;
rbdf = cpm->rbase + rx;
tb = cpm->txbuf[tx];
rb = cpm->rxbuf[rx];
rb = (u_char *) (((uint) rb + 1) & ~1);
eieio();
if (pmsg->flags & I2C_M_RD) {
dev_dbg(&adap->dev, "tx sc 0x%04x, rx sc 0x%04x\n",
in_be16(&tbdf->cbd_sc), in_be16(&rbdf->cbd_sc));
if (in_be16(&tbdf->cbd_sc) & BD_SC_NAK) {
dev_dbg(&adap->dev, "I2C read; No ack\n");
return -ENXIO;
}
if (in_be16(&rbdf->cbd_sc) & BD_SC_EMPTY) {
dev_err(&adap->dev,
"I2C read; complete but rbuf empty\n");
return -EREMOTEIO;
}
if (in_be16(&rbdf->cbd_sc) & BD_SC_OV) {
dev_err(&adap->dev, "I2C read; Overrun\n");
return -EREMOTEIO;
}
memcpy(pmsg->buf, rb, pmsg->len);
} else {
dev_dbg(&adap->dev, "tx sc %d 0x%04x\n", tx,
in_be16(&tbdf->cbd_sc));
if (in_be16(&tbdf->cbd_sc) & BD_SC_NAK) {
dev_dbg(&adap->dev, "I2C write; No ack\n");
return -ENXIO;
}
if (in_be16(&tbdf->cbd_sc) & BD_SC_UN) {
dev_err(&adap->dev, "I2C write; Underrun\n");
return -EIO;
}
if (in_be16(&tbdf->cbd_sc) & BD_SC_CL) {
dev_err(&adap->dev, "I2C write; Collision\n");
return -EIO;
}
}
return 0;
}
static int cpm_i2c_xfer(struct i2c_adapter *adap, struct i2c_msg *msgs, int num)
{
struct cpm_i2c *cpm = i2c_get_adapdata(adap);
struct i2c_reg __iomem *i2c_reg = cpm->i2c_reg;
struct i2c_ram __iomem *i2c_ram = cpm->i2c_ram;
struct i2c_msg *pmsg;
int ret, i;
int tptr;
int rptr;
cbd_t __iomem *tbdf;
cbd_t __iomem *rbdf;
if (num > CPM_MAXBD)
return -EINVAL;
for (i = 0; i < num; i++) {
pmsg = &msgs[i];
if (pmsg->len >= CPM_MAX_READ)
return -EINVAL;
}
out_be16(&i2c_ram->rbptr, in_be16(&i2c_ram->rbase));
out_be16(&i2c_ram->tbptr, in_be16(&i2c_ram->tbase));
tbdf = cpm->tbase;
rbdf = cpm->rbase;
tptr = 0;
rptr = 0;
while (tptr < num) {
pmsg = &msgs[tptr];
dev_dbg(&adap->dev, "R: %d T: %d\n", rptr, tptr);
cpm_i2c_parse_message(adap, pmsg, num, tptr, rptr);
if (pmsg->flags & I2C_M_RD)
rptr++;
tptr++;
}
out_8(&i2c_reg->i2cmr, I2CER_TXE | I2CER_TXB | I2CER_RXB);
out_8(&i2c_reg->i2cer, 0xff);
setbits8(&i2c_reg->i2mod, I2MOD_EN);
setbits8(&i2c_reg->i2com, I2COM_START);
tptr = 0;
rptr = 0;
while (tptr < num) {
dev_dbg(&adap->dev, "test ready.\n");
pmsg = &msgs[tptr];
if (pmsg->flags & I2C_M_RD)
ret = wait_event_timeout(cpm->i2c_wait,
(in_be16(&tbdf[tptr].cbd_sc) & BD_SC_NAK) ||
!(in_be16(&rbdf[rptr].cbd_sc) & BD_SC_EMPTY),
1 * HZ);
else
ret = wait_event_timeout(cpm->i2c_wait,
!(in_be16(&tbdf[tptr].cbd_sc) & BD_SC_READY),
1 * HZ);
if (ret == 0) {
ret = -EREMOTEIO;
dev_err(&adap->dev, "I2C transfer: timeout\n");
goto out_err;
}
if (ret > 0) {
dev_dbg(&adap->dev, "ready.\n");
ret = cpm_i2c_check_message(adap, pmsg, tptr, rptr);
tptr++;
if (pmsg->flags & I2C_M_RD)
rptr++;
if (ret)
goto out_err;
}
}
#ifdef I2C_CHIP_ERRATA
udelay(4);
clrbits8(&i2c_reg->i2mod, I2MOD_EN);
#endif
return (num);
out_err:
cpm_i2c_force_close(adap);
#ifdef I2C_CHIP_ERRATA
clrbits8(&i2c_reg->i2mod, I2MOD_EN);
#endif
return ret;
}
static u32 cpm_i2c_func(struct i2c_adapter *adap)
{
return I2C_FUNC_I2C | (I2C_FUNC_SMBUS_EMUL & ~I2C_FUNC_SMBUS_QUICK);
}
static int __devinit cpm_i2c_setup(struct cpm_i2c *cpm)
{
struct platform_device *ofdev = cpm->ofdev;
const u32 *data;
int len, ret, i;
void __iomem *i2c_base;
cbd_t __iomem *tbdf;
cbd_t __iomem *rbdf;
unsigned char brg;
dev_dbg(&cpm->ofdev->dev, "cpm_i2c_setup()\n");
init_waitqueue_head(&cpm->i2c_wait);
cpm->irq = of_irq_to_resource(ofdev->dev.of_node, 0, NULL);
if (!cpm->irq)
return -EINVAL;
ret = request_irq(cpm->irq, cpm_i2c_interrupt, 0, "cpm_i2c",
&cpm->adap);
if (ret)
return ret;
i2c_base = of_iomap(ofdev->dev.of_node, 1);
if (i2c_base == NULL) {
ret = -EINVAL;
goto out_irq;
}
if (of_device_is_compatible(ofdev->dev.of_node, "fsl,cpm1-i2c")) {
cpm->i2c_ram = i2c_base;
cpm->i2c_addr = in_be16(&cpm->i2c_ram->rpbase);
if (cpm->i2c_addr) {
cpm->i2c_ram = cpm_muram_addr(cpm->i2c_addr);
iounmap(i2c_base);
}
cpm->version = 1;
} else if (of_device_is_compatible(ofdev->dev.of_node, "fsl,cpm2-i2c")) {
cpm->i2c_addr = cpm_muram_alloc(sizeof(struct i2c_ram), 64);
cpm->i2c_ram = cpm_muram_addr(cpm->i2c_addr);
out_be16(i2c_base, cpm->i2c_addr);
iounmap(i2c_base);
cpm->version = 2;
} else {
iounmap(i2c_base);
ret = -EINVAL;
goto out_irq;
}
cpm->i2c_reg = of_iomap(ofdev->dev.of_node, 0);
if (cpm->i2c_reg == NULL) {
ret = -EINVAL;
goto out_ram;
}
data = of_get_property(ofdev->dev.of_node, "fsl,cpm-command", &len);
if (!data || len != 4) {
ret = -EINVAL;
goto out_reg;
}
cpm->cp_command = *data;
data = of_get_property(ofdev->dev.of_node, "linux,i2c-class", &len);
if (data && len == 4)
cpm->adap.class = *data;
data = of_get_property(ofdev->dev.of_node, "clock-frequency", &len);
if (data && len == 4)
cpm->freq = *data;
else
cpm->freq = 60000;
cpm->dp_addr = cpm_muram_alloc(sizeof(cbd_t) * 2 * CPM_MAXBD, 8);
if (!cpm->dp_addr) {
ret = -ENOMEM;
goto out_reg;
}
cpm->tbase = cpm_muram_addr(cpm->dp_addr);
cpm->rbase = cpm_muram_addr(cpm->dp_addr + sizeof(cbd_t) * CPM_MAXBD);
tbdf = cpm->tbase;
rbdf = cpm->rbase;
for (i = 0; i < CPM_MAXBD; i++) {
cpm->rxbuf[i] = dma_alloc_coherent(&cpm->ofdev->dev,
CPM_MAX_READ + 1,
&cpm->rxdma[i], GFP_KERNEL);
if (!cpm->rxbuf[i]) {
ret = -ENOMEM;
goto out_muram;
}
out_be32(&rbdf[i].cbd_bufaddr, ((cpm->rxdma[i] + 1) & ~1));
cpm->txbuf[i] = (unsigned char *)dma_alloc_coherent(&cpm->ofdev->dev, CPM_MAX_READ + 1, &cpm->txdma[i], GFP_KERNEL);
if (!cpm->txbuf[i]) {
ret = -ENOMEM;
goto out_muram;
}
out_be32(&tbdf[i].cbd_bufaddr, cpm->txdma[i]);
}
cpm_reset_i2c_params(cpm);
dev_dbg(&cpm->ofdev->dev, "i2c_ram 0x%p, i2c_addr 0x%04x, freq %d\n",
cpm->i2c_ram, cpm->i2c_addr, cpm->freq);
dev_dbg(&cpm->ofdev->dev, "tbase 0x%04x, rbase 0x%04x\n",
(u8 __iomem *)cpm->tbase - DPRAM_BASE,
(u8 __iomem *)cpm->rbase - DPRAM_BASE);
cpm_command(cpm->cp_command, CPM_CR_INIT_TRX);
out_8(&cpm->i2c_reg->i2add, 0x7f << 1);
brg = get_brgfreq() / (32 * 2 * cpm->freq) - 3;
out_8(&cpm->i2c_reg->i2brg, brg);
out_8(&cpm->i2c_reg->i2mod, 0x00);
out_8(&cpm->i2c_reg->i2com, I2COM_MASTER);
out_8(&cpm->i2c_reg->i2cmr, 0);
out_8(&cpm->i2c_reg->i2cer, 0xff);
return 0;
out_muram:
for (i = 0; i < CPM_MAXBD; i++) {
if (cpm->rxbuf[i])
dma_free_coherent(&cpm->ofdev->dev, CPM_MAX_READ + 1,
cpm->rxbuf[i], cpm->rxdma[i]);
if (cpm->txbuf[i])
dma_free_coherent(&cpm->ofdev->dev, CPM_MAX_READ + 1,
cpm->txbuf[i], cpm->txdma[i]);
}
cpm_muram_free(cpm->dp_addr);
out_reg:
iounmap(cpm->i2c_reg);
out_ram:
if ((cpm->version == 1) && (!cpm->i2c_addr))
iounmap(cpm->i2c_ram);
if (cpm->version == 2)
cpm_muram_free(cpm->i2c_addr);
out_irq:
free_irq(cpm->irq, &cpm->adap);
return ret;
}
static void cpm_i2c_shutdown(struct cpm_i2c *cpm)
{
int i;
clrbits8(&cpm->i2c_reg->i2mod, I2MOD_EN);
out_8(&cpm->i2c_reg->i2cmr, 0);
out_8(&cpm->i2c_reg->i2cer, 0xff);
free_irq(cpm->irq, &cpm->adap);
for (i = 0; i < CPM_MAXBD; i++) {
dma_free_coherent(&cpm->ofdev->dev, CPM_MAX_READ + 1,
cpm->rxbuf[i], cpm->rxdma[i]);
dma_free_coherent(&cpm->ofdev->dev, CPM_MAX_READ + 1,
cpm->txbuf[i], cpm->txdma[i]);
}
cpm_muram_free(cpm->dp_addr);
iounmap(cpm->i2c_reg);
if ((cpm->version == 1) && (!cpm->i2c_addr))
iounmap(cpm->i2c_ram);
if (cpm->version == 2)
cpm_muram_free(cpm->i2c_addr);
}
static int __devinit cpm_i2c_probe(struct platform_device *ofdev)
{
int result, len;
struct cpm_i2c *cpm;
const u32 *data;
cpm = kzalloc(sizeof(struct cpm_i2c), GFP_KERNEL);
if (!cpm)
return -ENOMEM;
cpm->ofdev = ofdev;
dev_set_drvdata(&ofdev->dev, cpm);
cpm->adap = cpm_ops;
i2c_set_adapdata(&cpm->adap, cpm);
cpm->adap.dev.parent = &ofdev->dev;
cpm->adap.dev.of_node = of_node_get(ofdev->dev.of_node);
result = cpm_i2c_setup(cpm);
if (result) {
dev_err(&ofdev->dev, "Unable to init hardware\n");
goto out_free;
}
data = of_get_property(ofdev->dev.of_node, "linux,i2c-index", &len);
if (data && len == 4) {
cpm->adap.nr = *data;
result = i2c_add_numbered_adapter(&cpm->adap);
} else
result = i2c_add_adapter(&cpm->adap);
if (result < 0) {
dev_err(&ofdev->dev, "Unable to register with I2C\n");
goto out_shut;
}
dev_dbg(&ofdev->dev, "hw routines for %s registered.\n",
cpm->adap.name);
of_i2c_register_devices(&cpm->adap);
return 0;
out_shut:
cpm_i2c_shutdown(cpm);
out_free:
dev_set_drvdata(&ofdev->dev, NULL);
kfree(cpm);
return result;
}
static int __devexit cpm_i2c_remove(struct platform_device *ofdev)
{
struct cpm_i2c *cpm = dev_get_drvdata(&ofdev->dev);
i2c_del_adapter(&cpm->adap);
cpm_i2c_shutdown(cpm);
dev_set_drvdata(&ofdev->dev, NULL);
kfree(cpm);
return 0;
}
static int __init cpm_i2c_init(void)
{
return platform_driver_register(&cpm_i2c_driver);
}
static void __exit cpm_i2c_exit(void)
{
platform_driver_unregister(&cpm_i2c_driver);
}
