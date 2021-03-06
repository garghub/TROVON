static inline uint8_t r852_read_reg(struct r852_device *dev, int address)
{
uint8_t reg = readb(dev->mmio + address);
return reg;
}
static inline void r852_write_reg(struct r852_device *dev,
int address, uint8_t value)
{
writeb(value, dev->mmio + address);
mmiowb();
}
static inline uint32_t r852_read_reg_dword(struct r852_device *dev, int address)
{
uint32_t reg = le32_to_cpu(readl(dev->mmio + address));
return reg;
}
static inline void r852_write_reg_dword(struct r852_device *dev,
int address, uint32_t value)
{
writel(cpu_to_le32(value), dev->mmio + address);
mmiowb();
}
static inline struct r852_device *r852_get_dev(struct mtd_info *mtd)
{
struct nand_chip *chip = mtd->priv;
return chip->priv;
}
static void r852_dma_test(struct r852_device *dev)
{
dev->dma_usable = (r852_read_reg(dev, R852_DMA_CAP) &
(R852_DMA1 | R852_DMA2)) == (R852_DMA1 | R852_DMA2);
if (!dev->dma_usable)
message("Non dma capable device detected, dma disabled");
if (!r852_enable_dma) {
message("disabling dma on user request");
dev->dma_usable = 0;
}
}
static void r852_dma_enable(struct r852_device *dev)
{
uint8_t dma_reg, dma_irq_reg;
dma_reg = r852_read_reg_dword(dev, R852_DMA_SETTINGS);
dma_reg &= ~(R852_DMA_READ | R852_DMA_INTERNAL | R852_DMA_MEMORY);
if (dev->dma_dir)
dma_reg |= R852_DMA_READ;
if (dev->dma_state == DMA_INTERNAL) {
dma_reg |= R852_DMA_INTERNAL;
r852_write_reg_dword(dev, R852_DMA_ADDR,
cpu_to_le32(dev->phys_bounce_buffer));
} else {
dma_reg |= R852_DMA_MEMORY;
r852_write_reg_dword(dev, R852_DMA_ADDR,
cpu_to_le32(dev->phys_dma_addr));
}
r852_read_reg_dword(dev, R852_DMA_ADDR);
r852_write_reg_dword(dev, R852_DMA_SETTINGS, dma_reg);
dma_irq_reg = r852_read_reg_dword(dev, R852_DMA_IRQ_ENABLE);
r852_write_reg_dword(dev, R852_DMA_IRQ_ENABLE,
dma_irq_reg |
R852_DMA_IRQ_INTERNAL |
R852_DMA_IRQ_ERROR |
R852_DMA_IRQ_MEMORY);
}
static void r852_dma_done(struct r852_device *dev, int error)
{
WARN_ON(dev->dma_stage == 0);
r852_write_reg_dword(dev, R852_DMA_IRQ_STA,
r852_read_reg_dword(dev, R852_DMA_IRQ_STA));
r852_write_reg_dword(dev, R852_DMA_SETTINGS, 0);
r852_write_reg_dword(dev, R852_DMA_IRQ_ENABLE, 0);
r852_write_reg_dword(dev, R852_DMA_ADDR,
cpu_to_le32(dev->phys_bounce_buffer));
r852_read_reg_dword(dev, R852_DMA_ADDR);
dev->dma_error = error;
dev->dma_stage = 0;
if (dev->phys_dma_addr && dev->phys_dma_addr != dev->phys_bounce_buffer)
pci_unmap_single(dev->pci_dev, dev->phys_dma_addr, R852_DMA_LEN,
dev->dma_dir ? PCI_DMA_FROMDEVICE : PCI_DMA_TODEVICE);
}
static int r852_dma_wait(struct r852_device *dev)
{
long timeout = wait_for_completion_timeout(&dev->dma_done,
msecs_to_jiffies(1000));
if (!timeout) {
dbg("timeout waiting for DMA interrupt");
return -ETIMEDOUT;
}
return 0;
}
static void r852_do_dma(struct r852_device *dev, uint8_t *buf, int do_read)
{
int bounce = 0;
unsigned long flags;
int error;
dev->dma_error = 0;
dev->dma_dir = do_read;
dev->dma_stage = 1;
reinit_completion(&dev->dma_done);
dbg_verbose("doing dma %s ", do_read ? "read" : "write");
dev->dma_state = do_read ? DMA_INTERNAL : DMA_MEMORY;
if ((unsigned long)buf & (R852_DMA_LEN-1))
bounce = 1;
if (!bounce) {
dev->phys_dma_addr = pci_map_single(dev->pci_dev, (void *)buf,
R852_DMA_LEN,
(do_read ? PCI_DMA_FROMDEVICE : PCI_DMA_TODEVICE));
if (pci_dma_mapping_error(dev->pci_dev, dev->phys_dma_addr))
bounce = 1;
}
if (bounce) {
dbg_verbose("dma: using bounce buffer");
dev->phys_dma_addr = dev->phys_bounce_buffer;
if (!do_read)
memcpy(dev->bounce_buffer, buf, R852_DMA_LEN);
}
spin_lock_irqsave(&dev->irqlock, flags);
r852_dma_enable(dev);
spin_unlock_irqrestore(&dev->irqlock, flags);
error = r852_dma_wait(dev);
if (error) {
r852_dma_done(dev, error);
return;
}
if (do_read && bounce)
memcpy((void *)buf, dev->bounce_buffer, R852_DMA_LEN);
}
static void r852_write_buf(struct mtd_info *mtd, const uint8_t *buf, int len)
{
struct r852_device *dev = r852_get_dev(mtd);
uint32_t reg;
if (dev->card_unstable)
return;
if (len == R852_DMA_LEN && dev->dma_usable) {
r852_do_dma(dev, (uint8_t *)buf, 0);
return;
}
while (len >= 4) {
reg = buf[0] | buf[1] << 8 | buf[2] << 16 | buf[3] << 24;
r852_write_reg_dword(dev, R852_DATALINE, reg);
buf += 4;
len -= 4;
}
while (len > 0) {
r852_write_reg(dev, R852_DATALINE, *buf++);
len--;
}
}
static void r852_read_buf(struct mtd_info *mtd, uint8_t *buf, int len)
{
struct r852_device *dev = r852_get_dev(mtd);
uint32_t reg;
if (dev->card_unstable) {
memset(buf, 0, len);
return;
}
if (len == R852_DMA_LEN && dev->dma_usable) {
r852_do_dma(dev, buf, 1);
return;
}
while (len >= 4) {
reg = r852_read_reg_dword(dev, R852_DATALINE);
*buf++ = reg & 0xFF;
*buf++ = (reg >> 8) & 0xFF;
*buf++ = (reg >> 16) & 0xFF;
*buf++ = (reg >> 24) & 0xFF;
len -= 4;
}
while (len--)
*buf++ = r852_read_reg(dev, R852_DATALINE);
}
static uint8_t r852_read_byte(struct mtd_info *mtd)
{
struct r852_device *dev = r852_get_dev(mtd);
if (dev->card_unstable)
return 0;
return r852_read_reg(dev, R852_DATALINE);
}
static void r852_cmdctl(struct mtd_info *mtd, int dat, unsigned int ctrl)
{
struct r852_device *dev = r852_get_dev(mtd);
if (dev->card_unstable)
return;
if (ctrl & NAND_CTRL_CHANGE) {
dev->ctlreg &= ~(R852_CTL_DATA | R852_CTL_COMMAND |
R852_CTL_ON | R852_CTL_CARDENABLE);
if (ctrl & NAND_ALE)
dev->ctlreg |= R852_CTL_DATA;
if (ctrl & NAND_CLE)
dev->ctlreg |= R852_CTL_COMMAND;
if (ctrl & NAND_NCE)
dev->ctlreg |= (R852_CTL_CARDENABLE | R852_CTL_ON);
else
dev->ctlreg &= ~R852_CTL_WRITE;
if (dat == NAND_CMD_ERASE1)
dev->ctlreg |= R852_CTL_WRITE;
r852_write_reg(dev, R852_CTL, dev->ctlreg);
}
if (dat == NAND_CMD_SEQIN && (dev->ctlreg & R852_CTL_COMMAND)) {
dev->ctlreg |= R852_CTL_WRITE;
r852_write_reg(dev, R852_CTL, dev->ctlreg);
}
if (dat != NAND_CMD_NONE)
r852_write_reg(dev, R852_DATALINE, dat);
}
static int r852_wait(struct mtd_info *mtd, struct nand_chip *chip)
{
struct r852_device *dev = chip->priv;
unsigned long timeout;
int status;
timeout = jiffies + (chip->state == FL_ERASING ?
msecs_to_jiffies(400) : msecs_to_jiffies(20));
while (time_before(jiffies, timeout))
if (chip->dev_ready(mtd))
break;
chip->cmdfunc(mtd, NAND_CMD_STATUS, -1, -1);
status = (int)chip->read_byte(mtd);
if (dev->dma_error) {
status |= NAND_STATUS_FAIL;
dev->dma_error = 0;
}
return status;
}
static int r852_ready(struct mtd_info *mtd)
{
struct r852_device *dev = r852_get_dev(mtd);
return !(r852_read_reg(dev, R852_CARD_STA) & R852_CARD_STA_BUSY);
}
static void r852_ecc_hwctl(struct mtd_info *mtd, int mode)
{
struct r852_device *dev = r852_get_dev(mtd);
if (dev->card_unstable)
return;
switch (mode) {
case NAND_ECC_READ:
case NAND_ECC_WRITE:
dev->ctlreg |= R852_CTL_ECC_ENABLE;
r852_write_reg(dev, R852_CTL,
dev->ctlreg | R852_CTL_ECC_ACCESS);
r852_read_reg_dword(dev, R852_DATALINE);
r852_write_reg(dev, R852_CTL, dev->ctlreg);
return;
case NAND_ECC_READSYN:
dev->ctlreg &= ~R852_CTL_ECC_ENABLE;
r852_write_reg(dev, R852_CTL, dev->ctlreg);
}
}
static int r852_ecc_calculate(struct mtd_info *mtd, const uint8_t *dat,
uint8_t *ecc_code)
{
struct r852_device *dev = r852_get_dev(mtd);
struct sm_oob *oob = (struct sm_oob *)ecc_code;
uint32_t ecc1, ecc2;
if (dev->card_unstable)
return 0;
dev->ctlreg &= ~R852_CTL_ECC_ENABLE;
r852_write_reg(dev, R852_CTL, dev->ctlreg | R852_CTL_ECC_ACCESS);
ecc1 = r852_read_reg_dword(dev, R852_DATALINE);
ecc2 = r852_read_reg_dword(dev, R852_DATALINE);
oob->ecc1[0] = (ecc1) & 0xFF;
oob->ecc1[1] = (ecc1 >> 8) & 0xFF;
oob->ecc1[2] = (ecc1 >> 16) & 0xFF;
oob->ecc2[0] = (ecc2) & 0xFF;
oob->ecc2[1] = (ecc2 >> 8) & 0xFF;
oob->ecc2[2] = (ecc2 >> 16) & 0xFF;
r852_write_reg(dev, R852_CTL, dev->ctlreg);
return 0;
}
static int r852_ecc_correct(struct mtd_info *mtd, uint8_t *dat,
uint8_t *read_ecc, uint8_t *calc_ecc)
{
uint32_t ecc_reg;
uint8_t ecc_status, err_byte;
int i, error = 0;
struct r852_device *dev = r852_get_dev(mtd);
if (dev->card_unstable)
return 0;
if (dev->dma_error) {
dev->dma_error = 0;
return -1;
}
r852_write_reg(dev, R852_CTL, dev->ctlreg | R852_CTL_ECC_ACCESS);
ecc_reg = r852_read_reg_dword(dev, R852_DATALINE);
r852_write_reg(dev, R852_CTL, dev->ctlreg);
for (i = 0 ; i <= 1 ; i++) {
ecc_status = (ecc_reg >> 8) & 0xFF;
if (ecc_status & R852_ECC_FAIL) {
dbg("ecc: unrecoverable error, in half %d", i);
error = -1;
goto exit;
}
if (ecc_status & R852_ECC_CORRECTABLE) {
err_byte = ecc_reg & 0xFF;
dbg("ecc: recoverable error, "
"in half %d, byte %d, bit %d", i,
err_byte, ecc_status & R852_ECC_ERR_BIT_MSK);
dat[err_byte] ^=
1 << (ecc_status & R852_ECC_ERR_BIT_MSK);
error++;
}
dat += 256;
ecc_reg >>= 16;
}
exit:
return error;
}
static int r852_read_oob(struct mtd_info *mtd, struct nand_chip *chip,
int page)
{
chip->cmdfunc(mtd, NAND_CMD_READOOB, 0, page);
chip->read_buf(mtd, chip->oob_poi, mtd->oobsize);
return 0;
}
static void r852_engine_enable(struct r852_device *dev)
{
if (r852_read_reg_dword(dev, R852_HW) & R852_HW_UNKNOWN) {
r852_write_reg(dev, R852_CTL, R852_CTL_RESET | R852_CTL_ON);
r852_write_reg_dword(dev, R852_HW, R852_HW_ENABLED);
} else {
r852_write_reg_dword(dev, R852_HW, R852_HW_ENABLED);
r852_write_reg(dev, R852_CTL, R852_CTL_RESET | R852_CTL_ON);
}
msleep(300);
r852_write_reg(dev, R852_CTL, 0);
}
static void r852_engine_disable(struct r852_device *dev)
{
r852_write_reg_dword(dev, R852_HW, 0);
r852_write_reg(dev, R852_CTL, R852_CTL_RESET);
}
static void r852_card_update_present(struct r852_device *dev)
{
unsigned long flags;
uint8_t reg;
spin_lock_irqsave(&dev->irqlock, flags);
reg = r852_read_reg(dev, R852_CARD_STA);
dev->card_detected = !!(reg & R852_CARD_STA_PRESENT);
spin_unlock_irqrestore(&dev->irqlock, flags);
}
static void r852_update_card_detect(struct r852_device *dev)
{
int card_detect_reg = r852_read_reg(dev, R852_CARD_IRQ_ENABLE);
dev->card_unstable = 0;
card_detect_reg &= ~(R852_CARD_IRQ_REMOVE | R852_CARD_IRQ_INSERT);
card_detect_reg |= R852_CARD_IRQ_GENABLE;
card_detect_reg |= dev->card_detected ?
R852_CARD_IRQ_REMOVE : R852_CARD_IRQ_INSERT;
r852_write_reg(dev, R852_CARD_IRQ_ENABLE, card_detect_reg);
}
static ssize_t r852_media_type_show(struct device *sys_dev,
struct device_attribute *attr, char *buf)
{
struct mtd_info *mtd = container_of(sys_dev, struct mtd_info, dev);
struct r852_device *dev = r852_get_dev(mtd);
char *data = dev->sm ? "smartmedia" : "xd";
strcpy(buf, data);
return strlen(data);
}
static void r852_update_media_status(struct r852_device *dev)
{
uint8_t reg;
unsigned long flags;
int readonly;
spin_lock_irqsave(&dev->irqlock, flags);
if (!dev->card_detected) {
message("card removed");
spin_unlock_irqrestore(&dev->irqlock, flags);
return ;
}
readonly = r852_read_reg(dev, R852_CARD_STA) & R852_CARD_STA_RO;
reg = r852_read_reg(dev, R852_DMA_CAP);
dev->sm = (reg & (R852_DMA1 | R852_DMA2)) && (reg & R852_SMBIT);
message("detected %s %s card in slot",
dev->sm ? "SmartMedia" : "xD",
readonly ? "readonly" : "writeable");
dev->readonly = readonly;
spin_unlock_irqrestore(&dev->irqlock, flags);
}
static int r852_register_nand_device(struct r852_device *dev)
{
dev->mtd = kzalloc(sizeof(struct mtd_info), GFP_KERNEL);
if (!dev->mtd)
goto error1;
WARN_ON(dev->card_registred);
dev->mtd->owner = THIS_MODULE;
dev->mtd->priv = dev->chip;
dev->mtd->dev.parent = &dev->pci_dev->dev;
if (dev->readonly)
dev->chip->options |= NAND_ROM;
r852_engine_enable(dev);
if (sm_register_device(dev->mtd, dev->sm))
goto error2;
if (device_create_file(&dev->mtd->dev, &dev_attr_media_type)) {
message("can't create media type sysfs attribute");
goto error3;
}
dev->card_registred = 1;
return 0;
error3:
nand_release(dev->mtd);
error2:
kfree(dev->mtd);
error1:
dev->card_detected = 0;
return -1;
}
static void r852_unregister_nand_device(struct r852_device *dev)
{
if (!dev->card_registred)
return;
device_remove_file(&dev->mtd->dev, &dev_attr_media_type);
nand_release(dev->mtd);
r852_engine_disable(dev);
dev->card_registred = 0;
kfree(dev->mtd);
dev->mtd = NULL;
}
static void r852_card_detect_work(struct work_struct *work)
{
struct r852_device *dev =
container_of(work, struct r852_device, card_detect_work.work);
r852_card_update_present(dev);
r852_update_card_detect(dev);
dev->card_unstable = 0;
if (dev->card_detected == dev->card_registred)
goto exit;
r852_update_media_status(dev);
if (dev->card_detected)
r852_register_nand_device(dev);
else
r852_unregister_nand_device(dev);
exit:
r852_update_card_detect(dev);
}
static void r852_disable_irqs(struct r852_device *dev)
{
uint8_t reg;
reg = r852_read_reg(dev, R852_CARD_IRQ_ENABLE);
r852_write_reg(dev, R852_CARD_IRQ_ENABLE, reg & ~R852_CARD_IRQ_MASK);
reg = r852_read_reg_dword(dev, R852_DMA_IRQ_ENABLE);
r852_write_reg_dword(dev, R852_DMA_IRQ_ENABLE,
reg & ~R852_DMA_IRQ_MASK);
r852_write_reg(dev, R852_CARD_IRQ_STA, R852_CARD_IRQ_MASK);
r852_write_reg_dword(dev, R852_DMA_IRQ_STA, R852_DMA_IRQ_MASK);
}
static irqreturn_t r852_irq(int irq, void *data)
{
struct r852_device *dev = (struct r852_device *)data;
uint8_t card_status, dma_status;
unsigned long flags;
irqreturn_t ret = IRQ_NONE;
spin_lock_irqsave(&dev->irqlock, flags);
card_status = r852_read_reg(dev, R852_CARD_IRQ_STA);
r852_write_reg(dev, R852_CARD_IRQ_STA, card_status);
if (card_status & (R852_CARD_IRQ_INSERT|R852_CARD_IRQ_REMOVE)) {
ret = IRQ_HANDLED;
dev->card_detected = !!(card_status & R852_CARD_IRQ_INSERT);
WARN_ON(dev->card_unstable);
r852_disable_irqs(dev);
if (dev->card_unstable)
goto out;
dev->card_unstable = 1;
queue_delayed_work(dev->card_workqueue,
&dev->card_detect_work, msecs_to_jiffies(100));
goto out;
}
dma_status = r852_read_reg_dword(dev, R852_DMA_IRQ_STA);
r852_write_reg_dword(dev, R852_DMA_IRQ_STA, dma_status);
if (dma_status & R852_DMA_IRQ_MASK) {
ret = IRQ_HANDLED;
if (dma_status & R852_DMA_IRQ_ERROR) {
dbg("received dma error IRQ");
r852_dma_done(dev, -EIO);
complete(&dev->dma_done);
goto out;
}
WARN_ON_ONCE(dev->dma_stage == 0);
if (dev->dma_stage == 0)
goto out;
if (dev->dma_state == DMA_INTERNAL &&
(dma_status & R852_DMA_IRQ_INTERNAL)) {
dev->dma_state = DMA_MEMORY;
dev->dma_stage++;
}
if (dev->dma_state == DMA_MEMORY &&
(dma_status & R852_DMA_IRQ_MEMORY)) {
dev->dma_state = DMA_INTERNAL;
dev->dma_stage++;
}
if (dev->dma_stage == 2)
r852_dma_enable(dev);
if (dev->dma_stage == 3) {
r852_dma_done(dev, 0);
complete(&dev->dma_done);
}
goto out;
}
if (dma_status)
dbg("bad dma IRQ status = %x", dma_status);
if (card_status & ~R852_CARD_STA_CD)
dbg("strange card status = %x", card_status);
out:
spin_unlock_irqrestore(&dev->irqlock, flags);
return ret;
}
static int r852_probe(struct pci_dev *pci_dev, const struct pci_device_id *id)
{
int error;
struct nand_chip *chip;
struct r852_device *dev;
error = pci_enable_device(pci_dev);
if (error)
goto error1;
pci_set_master(pci_dev);
error = pci_set_dma_mask(pci_dev, DMA_BIT_MASK(32));
if (error)
goto error2;
error = pci_request_regions(pci_dev, DRV_NAME);
if (error)
goto error3;
error = -ENOMEM;
chip = kzalloc(sizeof(struct nand_chip), GFP_KERNEL);
if (!chip)
goto error4;
chip->cmd_ctrl = r852_cmdctl;
chip->waitfunc = r852_wait;
chip->dev_ready = r852_ready;
chip->read_byte = r852_read_byte;
chip->read_buf = r852_read_buf;
chip->write_buf = r852_write_buf;
chip->ecc.mode = NAND_ECC_HW_SYNDROME;
chip->ecc.size = R852_DMA_LEN;
chip->ecc.bytes = SM_OOB_SIZE;
chip->ecc.strength = 2;
chip->ecc.hwctl = r852_ecc_hwctl;
chip->ecc.calculate = r852_ecc_calculate;
chip->ecc.correct = r852_ecc_correct;
chip->ecc.read_oob = r852_read_oob;
dev = kzalloc(sizeof(struct r852_device), GFP_KERNEL);
if (!dev)
goto error5;
chip->priv = dev;
dev->chip = chip;
dev->pci_dev = pci_dev;
pci_set_drvdata(pci_dev, dev);
dev->bounce_buffer = pci_alloc_consistent(pci_dev, R852_DMA_LEN,
&dev->phys_bounce_buffer);
if (!dev->bounce_buffer)
goto error6;
error = -ENODEV;
dev->mmio = pci_ioremap_bar(pci_dev, 0);
if (!dev->mmio)
goto error7;
error = -ENOMEM;
dev->tmp_buffer = kzalloc(SM_SECTOR_SIZE, GFP_KERNEL);
if (!dev->tmp_buffer)
goto error8;
init_completion(&dev->dma_done);
dev->card_workqueue = create_freezable_workqueue(DRV_NAME);
if (!dev->card_workqueue)
goto error9;
INIT_DELAYED_WORK(&dev->card_detect_work, r852_card_detect_work);
r852_engine_disable(dev);
r852_disable_irqs(dev);
r852_dma_test(dev);
dev->irq = pci_dev->irq;
spin_lock_init(&dev->irqlock);
dev->card_detected = 0;
r852_card_update_present(dev);
error = -ENODEV;
if (request_irq(pci_dev->irq, &r852_irq, IRQF_SHARED,
DRV_NAME, dev))
goto error10;
queue_delayed_work(dev->card_workqueue,
&dev->card_detect_work, 0);
printk(KERN_NOTICE DRV_NAME ": driver loaded successfully\n");
return 0;
error10:
destroy_workqueue(dev->card_workqueue);
error9:
kfree(dev->tmp_buffer);
error8:
pci_iounmap(pci_dev, dev->mmio);
error7:
pci_free_consistent(pci_dev, R852_DMA_LEN,
dev->bounce_buffer, dev->phys_bounce_buffer);
error6:
kfree(dev);
error5:
kfree(chip);
error4:
pci_release_regions(pci_dev);
error3:
error2:
pci_disable_device(pci_dev);
error1:
return error;
}
static void r852_remove(struct pci_dev *pci_dev)
{
struct r852_device *dev = pci_get_drvdata(pci_dev);
cancel_delayed_work_sync(&dev->card_detect_work);
destroy_workqueue(dev->card_workqueue);
r852_unregister_nand_device(dev);
r852_disable_irqs(dev);
synchronize_irq(dev->irq);
free_irq(dev->irq, dev);
kfree(dev->tmp_buffer);
pci_iounmap(pci_dev, dev->mmio);
pci_free_consistent(pci_dev, R852_DMA_LEN,
dev->bounce_buffer, dev->phys_bounce_buffer);
kfree(dev->chip);
kfree(dev);
pci_release_regions(pci_dev);
pci_disable_device(pci_dev);
}
static void r852_shutdown(struct pci_dev *pci_dev)
{
struct r852_device *dev = pci_get_drvdata(pci_dev);
cancel_delayed_work_sync(&dev->card_detect_work);
r852_disable_irqs(dev);
synchronize_irq(dev->irq);
pci_disable_device(pci_dev);
}
static int r852_suspend(struct device *device)
{
struct r852_device *dev = pci_get_drvdata(to_pci_dev(device));
if (dev->ctlreg & R852_CTL_CARDENABLE)
return -EBUSY;
cancel_delayed_work_sync(&dev->card_detect_work);
r852_disable_irqs(dev);
r852_engine_disable(dev);
dev->card_unstable = 0;
return 0;
}
static int r852_resume(struct device *device)
{
struct r852_device *dev = pci_get_drvdata(to_pci_dev(device));
r852_disable_irqs(dev);
r852_card_update_present(dev);
r852_engine_disable(dev);
if (dev->card_detected != dev->card_registred) {
dbg("card was %s during low power state",
dev->card_detected ? "added" : "removed");
queue_delayed_work(dev->card_workqueue,
&dev->card_detect_work, msecs_to_jiffies(1000));
return 0;
}
if (dev->card_registred) {
r852_engine_enable(dev);
dev->chip->select_chip(dev->mtd, 0);
dev->chip->cmdfunc(dev->mtd, NAND_CMD_RESET, -1, -1);
dev->chip->select_chip(dev->mtd, -1);
}
r852_update_card_detect(dev);
return 0;
}
