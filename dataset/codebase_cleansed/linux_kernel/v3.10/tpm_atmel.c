static int tpm_atml_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
u8 status, *hdr = buf;
u32 size;
int i;
__be32 *native_size;
if (count < 6)
return -EIO;
for (i = 0; i < 6; i++) {
status = ioread8(chip->vendor.iobase + 1);
if ((status & ATML_STATUS_DATA_AVAIL) == 0) {
dev_err(chip->dev, "error reading header\n");
return -EIO;
}
*buf++ = ioread8(chip->vendor.iobase);
}
native_size = (__force __be32 *) (hdr + 2);
size = be32_to_cpu(*native_size);
if (count < size) {
dev_err(chip->dev,
"Recv size(%d) less than available space\n", size);
for (; i < size; i++) {
status = ioread8(chip->vendor.iobase + 1);
if ((status & ATML_STATUS_DATA_AVAIL) == 0) {
dev_err(chip->dev, "error reading data\n");
return -EIO;
}
}
return -EIO;
}
for (; i < size; i++) {
status = ioread8(chip->vendor.iobase + 1);
if ((status & ATML_STATUS_DATA_AVAIL) == 0) {
dev_err(chip->dev, "error reading data\n");
return -EIO;
}
*buf++ = ioread8(chip->vendor.iobase);
}
status = ioread8(chip->vendor.iobase + 1);
if (status & ATML_STATUS_DATA_AVAIL) {
dev_err(chip->dev, "data available is stuck\n");
return -EIO;
}
return size;
}
static int tpm_atml_send(struct tpm_chip *chip, u8 *buf, size_t count)
{
int i;
dev_dbg(chip->dev, "tpm_atml_send:\n");
for (i = 0; i < count; i++) {
dev_dbg(chip->dev, "%d 0x%x(%d)\n", i, buf[i], buf[i]);
iowrite8(buf[i], chip->vendor.iobase);
}
return count;
}
static void tpm_atml_cancel(struct tpm_chip *chip)
{
iowrite8(ATML_STATUS_ABORT, chip->vendor.iobase + 1);
}
static u8 tpm_atml_status(struct tpm_chip *chip)
{
return ioread8(chip->vendor.iobase + 1);
}
static bool tpm_atml_req_canceled(struct tpm_chip *chip, u8 status)
{
return (status == ATML_STATUS_READY);
}
static void atml_plat_remove(void)
{
struct tpm_chip *chip = dev_get_drvdata(&pdev->dev);
if (chip) {
if (chip->vendor.have_region)
atmel_release_region(chip->vendor.base,
chip->vendor.region_size);
atmel_put_base_addr(chip->vendor.iobase);
tpm_remove_hardware(chip->dev);
platform_device_unregister(pdev);
}
}
static int __init init_atmel(void)
{
int rc = 0;
void __iomem *iobase = NULL;
int have_region, region_size;
unsigned long base;
struct tpm_chip *chip;
rc = platform_driver_register(&atml_drv);
if (rc)
return rc;
if ((iobase = atmel_get_base_addr(&base, &region_size)) == NULL) {
rc = -ENODEV;
goto err_unreg_drv;
}
have_region =
(atmel_request_region
(tpm_atmel.base, region_size, "tpm_atmel0") == NULL) ? 0 : 1;
pdev = platform_device_register_simple("tpm_atmel", -1, NULL, 0);
if (IS_ERR(pdev)) {
rc = PTR_ERR(pdev);
goto err_rel_reg;
}
if (!(chip = tpm_register_hardware(&pdev->dev, &tpm_atmel))) {
rc = -ENODEV;
goto err_unreg_dev;
}
chip->vendor.iobase = iobase;
chip->vendor.base = base;
chip->vendor.have_region = have_region;
chip->vendor.region_size = region_size;
return 0;
err_unreg_dev:
platform_device_unregister(pdev);
err_rel_reg:
atmel_put_base_addr(iobase);
if (have_region)
atmel_release_region(base,
region_size);
err_unreg_drv:
platform_driver_unregister(&atml_drv);
return rc;
}
static void __exit cleanup_atmel(void)
{
platform_driver_unregister(&atml_drv);
atml_plat_remove();
}
