static u8 crb_status(struct tpm_chip *chip)
{
struct crb_priv *priv = chip->vendor.priv;
u8 sts = 0;
if ((le32_to_cpu(ioread32(&priv->cca->start)) & CRB_START_INVOKE) !=
CRB_START_INVOKE)
sts |= CRB_STS_COMPLETE;
return sts;
}
static int crb_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
struct crb_priv *priv = chip->vendor.priv;
unsigned int expected;
if (count < 6)
return -EIO;
if (le32_to_cpu(ioread32(&priv->cca->sts)) & CRB_CA_STS_ERROR)
return -EIO;
memcpy_fromio(buf, priv->rsp, 6);
expected = be32_to_cpup((__be32 *) &buf[2]);
if (expected > count)
return -EIO;
memcpy_fromio(&buf[6], &priv->rsp[6], expected - 6);
return expected;
}
static int crb_do_acpi_start(struct tpm_chip *chip)
{
union acpi_object *obj;
int rc;
obj = acpi_evaluate_dsm(chip->acpi_dev_handle,
CRB_ACPI_START_UUID,
CRB_ACPI_START_REVISION_ID,
CRB_ACPI_START_INDEX,
NULL);
if (!obj)
return -ENXIO;
rc = obj->integer.value == 0 ? 0 : -ENXIO;
ACPI_FREE(obj);
return rc;
}
static int crb_send(struct tpm_chip *chip, u8 *buf, size_t len)
{
struct crb_priv *priv = chip->vendor.priv;
int rc = 0;
if (len > le32_to_cpu(ioread32(&priv->cca->cmd_size))) {
dev_err(&chip->dev,
"invalid command count value %x %zx\n",
(unsigned int) len,
(size_t) le32_to_cpu(ioread32(&priv->cca->cmd_size)));
return -E2BIG;
}
memcpy_toio(priv->cmd, buf, len);
wmb();
if (priv->flags & CRB_FL_CRB_START)
iowrite32(cpu_to_le32(CRB_START_INVOKE), &priv->cca->start);
if (priv->flags & CRB_FL_ACPI_START)
rc = crb_do_acpi_start(chip);
return rc;
}
static void crb_cancel(struct tpm_chip *chip)
{
struct crb_priv *priv = chip->vendor.priv;
iowrite32(cpu_to_le32(CRB_CANCEL_INVOKE), &priv->cca->cancel);
wmb();
if ((priv->flags & CRB_FL_ACPI_START) && crb_do_acpi_start(chip))
dev_err(&chip->dev, "ACPI Start failed\n");
iowrite32(0, &priv->cca->cancel);
}
static bool crb_req_canceled(struct tpm_chip *chip, u8 status)
{
struct crb_priv *priv = chip->vendor.priv;
u32 cancel = le32_to_cpu(ioread32(&priv->cca->cancel));
return (cancel & CRB_CANCEL_INVOKE) == CRB_CANCEL_INVOKE;
}
static int crb_acpi_add(struct acpi_device *device)
{
struct tpm_chip *chip;
struct acpi_tpm2 *buf;
struct crb_priv *priv;
struct device *dev = &device->dev;
acpi_status status;
u32 sm;
u64 pa;
int rc;
status = acpi_get_table(ACPI_SIG_TPM2, 1,
(struct acpi_table_header **) &buf);
if (ACPI_FAILURE(status)) {
dev_err(dev, "failed to get TPM2 ACPI table\n");
return -ENODEV;
}
if (buf->start_method == TPM2_START_FIFO)
return -ENODEV;
chip = tpmm_chip_alloc(dev, &tpm_crb);
if (IS_ERR(chip))
return PTR_ERR(chip);
chip->flags = TPM_CHIP_FLAG_TPM2;
if (buf->hdr.length < sizeof(struct acpi_tpm2)) {
dev_err(dev, "TPM2 ACPI table has wrong size");
return -EINVAL;
}
priv = (struct crb_priv *) devm_kzalloc(dev, sizeof(struct crb_priv),
GFP_KERNEL);
if (!priv) {
dev_err(dev, "failed to devm_kzalloc for private data\n");
return -ENOMEM;
}
sm = le32_to_cpu(buf->start_method);
if (sm == TPM2_START_CRB || sm == TPM2_START_FIFO ||
!strcmp(acpi_device_hid(device), "MSFT0101"))
priv->flags |= CRB_FL_CRB_START;
if (sm == TPM2_START_ACPI || sm == TPM2_START_CRB_WITH_ACPI)
priv->flags |= CRB_FL_ACPI_START;
priv->cca = (struct crb_control_area __iomem *)
devm_ioremap_nocache(dev, buf->control_area_pa, 0x1000);
if (!priv->cca) {
dev_err(dev, "ioremap of the control area failed\n");
return -ENOMEM;
}
pa = ((u64) le32_to_cpu(ioread32(&priv->cca->cmd_pa_high)) << 32) |
(u64) le32_to_cpu(ioread32(&priv->cca->cmd_pa_low));
priv->cmd = devm_ioremap_nocache(dev, pa,
ioread32(&priv->cca->cmd_size));
if (!priv->cmd) {
dev_err(dev, "ioremap of the command buffer failed\n");
return -ENOMEM;
}
memcpy_fromio(&pa, &priv->cca->rsp_pa, 8);
pa = le64_to_cpu(pa);
priv->rsp = devm_ioremap_nocache(dev, pa,
ioread32(&priv->cca->rsp_size));
if (!priv->rsp) {
dev_err(dev, "ioremap of the response buffer failed\n");
return -ENOMEM;
}
chip->vendor.priv = priv;
rc = tpm_get_timeouts(chip);
if (rc)
return rc;
chip->acpi_dev_handle = device->handle;
rc = tpm2_do_selftest(chip);
if (rc)
return rc;
return tpm_chip_register(chip);
}
static int crb_acpi_remove(struct acpi_device *device)
{
struct device *dev = &device->dev;
struct tpm_chip *chip = dev_get_drvdata(dev);
tpm_chip_unregister(chip);
if (chip->flags & TPM_CHIP_FLAG_TPM2)
tpm2_shutdown(chip, TPM2_SU_CLEAR);
return 0;
}
