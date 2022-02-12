static int wait_for_stat(struct tpm_chip *chip, u8 mask, u8 val, u8 * data)
{
unsigned long stop;
*data = inb(chip->vendor.base + NSC_STATUS);
if ((*data & mask) == val)
return 0;
stop = jiffies + 10 * HZ;
do {
msleep(TPM_TIMEOUT);
*data = inb(chip->vendor.base + 1);
if ((*data & mask) == val)
return 0;
}
while (time_before(jiffies, stop));
return -EBUSY;
}
static int nsc_wait_for_ready(struct tpm_chip *chip)
{
int status;
unsigned long stop;
status = inb(chip->vendor.base + NSC_STATUS);
if (status & NSC_STATUS_OBF)
status = inb(chip->vendor.base + NSC_DATA);
if (status & NSC_STATUS_RDY)
return 0;
stop = jiffies + 100;
do {
msleep(TPM_TIMEOUT);
status = inb(chip->vendor.base + NSC_STATUS);
if (status & NSC_STATUS_OBF)
status = inb(chip->vendor.base + NSC_DATA);
if (status & NSC_STATUS_RDY)
return 0;
}
while (time_before(jiffies, stop));
dev_info(chip->dev, "wait for ready failed\n");
return -EBUSY;
}
static int tpm_nsc_recv(struct tpm_chip *chip, u8 * buf, size_t count)
{
u8 *buffer = buf;
u8 data, *p;
u32 size;
__be32 *native_size;
if (count < 6)
return -EIO;
if (wait_for_stat(chip, NSC_STATUS_F0, NSC_STATUS_F0, &data) < 0) {
dev_err(chip->dev, "F0 timeout\n");
return -EIO;
}
if ((data =
inb(chip->vendor.base + NSC_DATA)) != NSC_COMMAND_NORMAL) {
dev_err(chip->dev, "not in normal mode (0x%x)\n",
data);
return -EIO;
}
for (p = buffer; p < &buffer[count]; p++) {
if (wait_for_stat
(chip, NSC_STATUS_OBF, NSC_STATUS_OBF, &data) < 0) {
dev_err(chip->dev,
"OBF timeout (while reading data)\n");
return -EIO;
}
if (data & NSC_STATUS_F0)
break;
*p = inb(chip->vendor.base + NSC_DATA);
}
if ((data & NSC_STATUS_F0) == 0 &&
(wait_for_stat(chip, NSC_STATUS_F0, NSC_STATUS_F0, &data) < 0)) {
dev_err(chip->dev, "F0 not set\n");
return -EIO;
}
if ((data = inb(chip->vendor.base + NSC_DATA)) != NSC_COMMAND_EOC) {
dev_err(chip->dev,
"expected end of command(0x%x)\n", data);
return -EIO;
}
native_size = (__force __be32 *) (buf + 2);
size = be32_to_cpu(*native_size);
if (count < size)
return -EIO;
return size;
}
static int tpm_nsc_send(struct tpm_chip *chip, u8 * buf, size_t count)
{
u8 data;
int i;
outb(NSC_COMMAND_CANCEL, chip->vendor.base + NSC_COMMAND);
if (nsc_wait_for_ready(chip) != 0)
return -EIO;
if (wait_for_stat(chip, NSC_STATUS_IBF, 0, &data) < 0) {
dev_err(chip->dev, "IBF timeout\n");
return -EIO;
}
outb(NSC_COMMAND_NORMAL, chip->vendor.base + NSC_COMMAND);
if (wait_for_stat(chip, NSC_STATUS_IBR, NSC_STATUS_IBR, &data) < 0) {
dev_err(chip->dev, "IBR timeout\n");
return -EIO;
}
for (i = 0; i < count; i++) {
if (wait_for_stat(chip, NSC_STATUS_IBF, 0, &data) < 0) {
dev_err(chip->dev,
"IBF timeout (while writing data)\n");
return -EIO;
}
outb(buf[i], chip->vendor.base + NSC_DATA);
}
if (wait_for_stat(chip, NSC_STATUS_IBF, 0, &data) < 0) {
dev_err(chip->dev, "IBF timeout\n");
return -EIO;
}
outb(NSC_COMMAND_EOC, chip->vendor.base + NSC_COMMAND);
return count;
}
static void tpm_nsc_cancel(struct tpm_chip *chip)
{
outb(NSC_COMMAND_CANCEL, chip->vendor.base + NSC_COMMAND);
}
static u8 tpm_nsc_status(struct tpm_chip *chip)
{
return inb(chip->vendor.base + NSC_STATUS);
}
static void tpm_nsc_remove(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
if ( chip ) {
release_region(chip->vendor.base, 2);
tpm_remove_hardware(chip->dev);
}
}
static int __init init_nsc(void)
{
int rc = 0;
int lo, hi, err;
int nscAddrBase = TPM_ADDR;
struct tpm_chip *chip;
unsigned long base;
if (tpm_read_index(TPM_ADDR, NSC_SID_INDEX) != 0xEF) {
nscAddrBase = (tpm_read_index(TPM_SUPERIO_ADDR, 0x2C)<<8)|
(tpm_read_index(TPM_SUPERIO_ADDR, 0x2B)&0xFE);
if (tpm_read_index(nscAddrBase, NSC_SID_INDEX) != 0xF6)
return -ENODEV;
}
err = platform_driver_register(&nsc_drv);
if (err)
return err;
hi = tpm_read_index(nscAddrBase, TPM_NSC_BASE0_HI);
lo = tpm_read_index(nscAddrBase, TPM_NSC_BASE0_LO);
base = (hi<<8) | lo;
tpm_write_index(nscAddrBase, NSC_LDC_INDEX, 0x01);
pdev = platform_device_alloc("tpm_nscl0", -1);
if (!pdev) {
rc = -ENOMEM;
goto err_unreg_drv;
}
pdev->num_resources = 0;
pdev->dev.driver = &nsc_drv.driver;
pdev->dev.release = tpm_nsc_remove;
if ((rc = platform_device_add(pdev)) < 0)
goto err_put_dev;
if (request_region(base, 2, "tpm_nsc0") == NULL ) {
rc = -EBUSY;
goto err_del_dev;
}
if (!(chip = tpm_register_hardware(&pdev->dev, &tpm_nsc))) {
rc = -ENODEV;
goto err_rel_reg;
}
dev_dbg(&pdev->dev, "NSC TPM detected\n");
dev_dbg(&pdev->dev,
"NSC LDN 0x%x, SID 0x%x, SRID 0x%x\n",
tpm_read_index(nscAddrBase,0x07), tpm_read_index(nscAddrBase,0x20),
tpm_read_index(nscAddrBase,0x27));
dev_dbg(&pdev->dev,
"NSC SIOCF1 0x%x SIOCF5 0x%x SIOCF6 0x%x SIOCF8 0x%x\n",
tpm_read_index(nscAddrBase,0x21), tpm_read_index(nscAddrBase,0x25),
tpm_read_index(nscAddrBase,0x26), tpm_read_index(nscAddrBase,0x28));
dev_dbg(&pdev->dev, "NSC IO Base0 0x%x\n",
(tpm_read_index(nscAddrBase,0x60) << 8) | tpm_read_index(nscAddrBase,0x61));
dev_dbg(&pdev->dev, "NSC IO Base1 0x%x\n",
(tpm_read_index(nscAddrBase,0x62) << 8) | tpm_read_index(nscAddrBase,0x63));
dev_dbg(&pdev->dev, "NSC Interrupt number and wakeup 0x%x\n",
tpm_read_index(nscAddrBase,0x70));
dev_dbg(&pdev->dev, "NSC IRQ type select 0x%x\n",
tpm_read_index(nscAddrBase,0x71));
dev_dbg(&pdev->dev,
"NSC DMA channel select0 0x%x, select1 0x%x\n",
tpm_read_index(nscAddrBase,0x74), tpm_read_index(nscAddrBase,0x75));
dev_dbg(&pdev->dev,
"NSC Config "
"0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x\n",
tpm_read_index(nscAddrBase,0xF0), tpm_read_index(nscAddrBase,0xF1),
tpm_read_index(nscAddrBase,0xF2), tpm_read_index(nscAddrBase,0xF3),
tpm_read_index(nscAddrBase,0xF4), tpm_read_index(nscAddrBase,0xF5),
tpm_read_index(nscAddrBase,0xF6), tpm_read_index(nscAddrBase,0xF7),
tpm_read_index(nscAddrBase,0xF8), tpm_read_index(nscAddrBase,0xF9));
dev_info(&pdev->dev,
"NSC TPM revision %d\n",
tpm_read_index(nscAddrBase, 0x27) & 0x1F);
chip->vendor.base = base;
return 0;
err_rel_reg:
release_region(base, 2);
err_del_dev:
platform_device_del(pdev);
err_put_dev:
platform_device_put(pdev);
err_unreg_drv:
platform_driver_unregister(&nsc_drv);
return rc;
}
static void __exit cleanup_nsc(void)
{
if (pdev) {
tpm_nsc_remove(&pdev->dev);
platform_device_unregister(pdev);
}
platform_driver_unregister(&nsc_drv);
}
