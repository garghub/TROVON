static void tmio_nand_hwcontrol(struct mtd_info *mtd, int cmd,
unsigned int ctrl)
{
struct tmio_nand *tmio = mtd_to_tmio(mtd);
struct nand_chip *chip = mtd->priv;
if (ctrl & NAND_CTRL_CHANGE) {
u8 mode;
if (ctrl & NAND_NCE) {
mode = FCR_MODE_DATA;
if (ctrl & NAND_CLE)
mode |= FCR_MODE_CLE;
else
mode &= ~FCR_MODE_CLE;
if (ctrl & NAND_ALE)
mode |= FCR_MODE_ALE;
else
mode &= ~FCR_MODE_ALE;
} else {
mode = FCR_MODE_STANDBY;
}
tmio_iowrite8(mode, tmio->fcr + FCR_MODE);
tmio->read_good = 0;
}
if (cmd != NAND_CMD_NONE)
tmio_iowrite8(cmd, chip->IO_ADDR_W);
}
static int tmio_nand_dev_ready(struct mtd_info *mtd)
{
struct tmio_nand *tmio = mtd_to_tmio(mtd);
return !(tmio_ioread8(tmio->fcr + FCR_STATUS) & FCR_STATUS_BUSY);
}
static irqreturn_t tmio_irq(int irq, void *__tmio)
{
struct tmio_nand *tmio = __tmio;
struct nand_chip *nand_chip = &tmio->chip;
tmio_iowrite8(0x00, tmio->fcr + FCR_IMR);
if (unlikely(!waitqueue_active(&nand_chip->controller->wq)))
dev_warn(&tmio->dev->dev, "spurious interrupt\n");
wake_up(&nand_chip->controller->wq);
return IRQ_HANDLED;
}
static int
tmio_nand_wait(struct mtd_info *mtd, struct nand_chip *nand_chip)
{
struct tmio_nand *tmio = mtd_to_tmio(mtd);
long timeout;
tmio_iowrite8(0x0f, tmio->fcr + FCR_ISR);
tmio_iowrite8(0x81, tmio->fcr + FCR_IMR);
timeout = wait_event_timeout(nand_chip->controller->wq,
tmio_nand_dev_ready(mtd),
msecs_to_jiffies(nand_chip->state == FL_ERASING ? 400 : 20));
if (unlikely(!tmio_nand_dev_ready(mtd))) {
tmio_iowrite8(0x00, tmio->fcr + FCR_IMR);
dev_warn(&tmio->dev->dev, "still busy with %s after %d ms\n",
nand_chip->state == FL_ERASING ? "erase" : "program",
nand_chip->state == FL_ERASING ? 400 : 20);
} else if (unlikely(!timeout)) {
tmio_iowrite8(0x00, tmio->fcr + FCR_IMR);
dev_warn(&tmio->dev->dev, "timeout waiting for interrupt\n");
}
nand_chip->cmdfunc(mtd, NAND_CMD_STATUS, -1, -1);
return nand_chip->read_byte(mtd);
}
static u_char tmio_nand_read_byte(struct mtd_info *mtd)
{
struct tmio_nand *tmio = mtd_to_tmio(mtd);
unsigned int data;
if (tmio->read_good--)
return tmio->read;
data = tmio_ioread16(tmio->fcr + FCR_DATA);
tmio->read = data >> 8;
return data;
}
static void
tmio_nand_write_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct tmio_nand *tmio = mtd_to_tmio(mtd);
tmio_iowrite16_rep(tmio->fcr + FCR_DATA, buf, len >> 1);
}
static void tmio_nand_read_buf(struct mtd_info *mtd, u_char *buf, int len)
{
struct tmio_nand *tmio = mtd_to_tmio(mtd);
tmio_ioread16_rep(tmio->fcr + FCR_DATA, buf, len >> 1);
}
static int
tmio_nand_verify_buf(struct mtd_info *mtd, const u_char *buf, int len)
{
struct tmio_nand *tmio = mtd_to_tmio(mtd);
u16 *p = (u16 *) buf;
for (len >>= 1; len; len--)
if (*(p++) != tmio_ioread16(tmio->fcr + FCR_DATA))
return -EFAULT;
return 0;
}
static void tmio_nand_enable_hwecc(struct mtd_info *mtd, int mode)
{
struct tmio_nand *tmio = mtd_to_tmio(mtd);
tmio_iowrite8(FCR_MODE_HWECC_RESET, tmio->fcr + FCR_MODE);
tmio_ioread8(tmio->fcr + FCR_DATA);
tmio_iowrite8(FCR_MODE_HWECC_CALC, tmio->fcr + FCR_MODE);
}
static int tmio_nand_calculate_ecc(struct mtd_info *mtd, const u_char *dat,
u_char *ecc_code)
{
struct tmio_nand *tmio = mtd_to_tmio(mtd);
unsigned int ecc;
tmio_iowrite8(FCR_MODE_HWECC_RESULT, tmio->fcr + FCR_MODE);
ecc = tmio_ioread16(tmio->fcr + FCR_DATA);
ecc_code[1] = ecc;
ecc_code[0] = ecc >> 8;
ecc = tmio_ioread16(tmio->fcr + FCR_DATA);
ecc_code[2] = ecc;
ecc_code[4] = ecc >> 8;
ecc = tmio_ioread16(tmio->fcr + FCR_DATA);
ecc_code[3] = ecc;
ecc_code[5] = ecc >> 8;
tmio_iowrite8(FCR_MODE_DATA, tmio->fcr + FCR_MODE);
return 0;
}
static int tmio_nand_correct_data(struct mtd_info *mtd, unsigned char *buf,
unsigned char *read_ecc, unsigned char *calc_ecc)
{
int r0, r1;
r0 = __nand_correct_data(buf, read_ecc, calc_ecc, 256);
if (r0 < 0)
return r0;
r1 = __nand_correct_data(buf + 256, read_ecc + 3, calc_ecc + 3, 256);
if (r1 < 0)
return r1;
return r0 + r1;
}
static int tmio_hw_init(struct platform_device *dev, struct tmio_nand *tmio)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
int ret;
if (cell->enable) {
ret = cell->enable(dev);
if (ret)
return ret;
}
tmio_iowrite8(0x81, tmio->ccr + CCR_ICC);
tmio_iowrite16(tmio->fcr_base, tmio->ccr + CCR_BASE);
tmio_iowrite16(tmio->fcr_base >> 16, tmio->ccr + CCR_BASE + 2);
tmio_iowrite8(0x02, tmio->ccr + CCR_COMMAND);
tmio_iowrite8(0x02, tmio->ccr + CCR_NFPSC);
tmio_iowrite8(0x02, tmio->ccr + CCR_NFDC);
tmio_iowrite8(0x0f, tmio->fcr + FCR_ISR);
tmio_iowrite8(FCR_MODE_POWER_ON, tmio->fcr + FCR_MODE);
tmio_iowrite8(FCR_MODE_COMMAND, tmio->fcr + FCR_MODE);
tmio_iowrite8(NAND_CMD_RESET, tmio->fcr + FCR_DATA);
tmio_iowrite8(FCR_MODE_STANDBY, tmio->fcr + FCR_MODE);
mdelay(5);
return 0;
}
static void tmio_hw_stop(struct platform_device *dev, struct tmio_nand *tmio)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
tmio_iowrite8(FCR_MODE_POWER_OFF, tmio->fcr + FCR_MODE);
if (cell->disable)
cell->disable(dev);
}
static int tmio_probe(struct platform_device *dev)
{
struct tmio_nand_data *data = dev->dev.platform_data;
struct resource *fcr = platform_get_resource(dev,
IORESOURCE_MEM, 0);
struct resource *ccr = platform_get_resource(dev,
IORESOURCE_MEM, 1);
int irq = platform_get_irq(dev, 0);
struct tmio_nand *tmio;
struct mtd_info *mtd;
struct nand_chip *nand_chip;
struct mtd_partition *parts;
int nbparts = 0;
int retval;
if (data == NULL)
dev_warn(&dev->dev, "NULL platform data!\n");
tmio = kzalloc(sizeof *tmio, GFP_KERNEL);
if (!tmio) {
retval = -ENOMEM;
goto err_kzalloc;
}
tmio->dev = dev;
platform_set_drvdata(dev, tmio);
mtd = &tmio->mtd;
nand_chip = &tmio->chip;
mtd->priv = nand_chip;
mtd->name = "tmio-nand";
tmio->ccr = ioremap(ccr->start, resource_size(ccr));
if (!tmio->ccr) {
retval = -EIO;
goto err_iomap_ccr;
}
tmio->fcr_base = fcr->start & 0xfffff;
tmio->fcr = ioremap(fcr->start, resource_size(fcr));
if (!tmio->fcr) {
retval = -EIO;
goto err_iomap_fcr;
}
retval = tmio_hw_init(dev, tmio);
if (retval)
goto err_hwinit;
nand_chip->IO_ADDR_R = tmio->fcr;
nand_chip->IO_ADDR_W = tmio->fcr;
nand_chip->cmd_ctrl = tmio_nand_hwcontrol;
nand_chip->dev_ready = tmio_nand_dev_ready;
nand_chip->read_byte = tmio_nand_read_byte;
nand_chip->write_buf = tmio_nand_write_buf;
nand_chip->read_buf = tmio_nand_read_buf;
nand_chip->verify_buf = tmio_nand_verify_buf;
nand_chip->ecc.mode = NAND_ECC_HW;
nand_chip->ecc.size = 512;
nand_chip->ecc.bytes = 6;
nand_chip->ecc.hwctl = tmio_nand_enable_hwecc;
nand_chip->ecc.calculate = tmio_nand_calculate_ecc;
nand_chip->ecc.correct = tmio_nand_correct_data;
if (data)
nand_chip->badblock_pattern = data->badblock_pattern;
nand_chip->chip_delay = 15;
retval = request_irq(irq, &tmio_irq,
IRQF_DISABLED, dev_name(&dev->dev), tmio);
if (retval) {
dev_err(&dev->dev, "request_irq error %d\n", retval);
goto err_irq;
}
tmio->irq = irq;
nand_chip->waitfunc = tmio_nand_wait;
if (nand_scan(mtd, 1)) {
retval = -ENODEV;
goto err_scan;
}
#ifdef CONFIG_MTD_CMDLINE_PARTS
nbparts = parse_mtd_partitions(mtd, part_probes, &parts, 0);
#endif
if (nbparts <= 0 && data) {
parts = data->partition;
nbparts = data->num_partitions;
}
retval = mtd_device_register(mtd, parts, nbparts);
if (!retval)
return retval;
nand_release(mtd);
err_scan:
if (tmio->irq)
free_irq(tmio->irq, tmio);
err_irq:
tmio_hw_stop(dev, tmio);
err_hwinit:
iounmap(tmio->fcr);
err_iomap_fcr:
iounmap(tmio->ccr);
err_iomap_ccr:
kfree(tmio);
err_kzalloc:
return retval;
}
static int tmio_remove(struct platform_device *dev)
{
struct tmio_nand *tmio = platform_get_drvdata(dev);
nand_release(&tmio->mtd);
if (tmio->irq)
free_irq(tmio->irq, tmio);
tmio_hw_stop(dev, tmio);
iounmap(tmio->fcr);
iounmap(tmio->ccr);
kfree(tmio);
return 0;
}
static int tmio_suspend(struct platform_device *dev, pm_message_t state)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
if (cell->suspend)
cell->suspend(dev);
tmio_hw_stop(dev, platform_get_drvdata(dev));
return 0;
}
static int tmio_resume(struct platform_device *dev)
{
const struct mfd_cell *cell = mfd_get_cell(dev);
tmio_hw_init(dev, platform_get_drvdata(dev));
if (cell->resume)
cell->resume(dev);
return 0;
}
static int __init tmio_init(void)
{
return platform_driver_register(&tmio_driver);
}
static void __exit tmio_exit(void)
{
platform_driver_unregister(&tmio_driver);
}
