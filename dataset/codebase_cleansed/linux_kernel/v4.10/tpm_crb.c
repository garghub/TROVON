static int __maybe_unused crb_go_idle(struct device *dev, struct crb_priv *priv)
{
if (priv->flags & CRB_FL_ACPI_START)
return 0;
iowrite32(CRB_CTRL_REQ_GO_IDLE, &priv->cca->req);
return 0;
}
static int __maybe_unused crb_cmd_ready(struct device *dev,
struct crb_priv *priv)
{
ktime_t stop, start;
if (priv->flags & CRB_FL_ACPI_START)
return 0;
iowrite32(CRB_CTRL_REQ_CMD_READY, &priv->cca->req);
start = ktime_get();
stop = ktime_add(start, ms_to_ktime(TPM2_TIMEOUT_C));
do {
if (!(ioread32(&priv->cca->req) & CRB_CTRL_REQ_CMD_READY))
return 0;
usleep_range(50, 100);
} while (ktime_before(ktime_get(), stop));
if (ioread32(&priv->cca->req) & CRB_CTRL_REQ_CMD_READY) {
dev_warn(dev, "cmdReady timed out\n");
return -ETIME;
}
return 0;
}
static u8 crb_status(struct tpm_chip *chip)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
u8 sts = 0;
if ((ioread32(&priv->cca->start) & CRB_START_INVOKE) !=
CRB_START_INVOKE)
sts |= CRB_DRV_STS_COMPLETE;
return sts;
}
static int crb_recv(struct tpm_chip *chip, u8 *buf, size_t count)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
unsigned int expected;
if (count < 6)
return -EIO;
if (ioread32(&priv->cca->sts) & CRB_CTRL_STS_ERROR)
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
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
int rc = 0;
iowrite32(0, &priv->cca->cancel);
if (len > priv->cmd_size) {
dev_err(&chip->dev, "invalid command count value %zd %d\n",
len, priv->cmd_size);
return -E2BIG;
}
memcpy_toio(priv->cmd, buf, len);
wmb();
if (priv->flags & CRB_FL_CRB_START)
iowrite32(CRB_START_INVOKE, &priv->cca->start);
if (priv->flags & CRB_FL_ACPI_START)
rc = crb_do_acpi_start(chip);
return rc;
}
static void crb_cancel(struct tpm_chip *chip)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
iowrite32(CRB_CANCEL_INVOKE, &priv->cca->cancel);
if ((priv->flags & CRB_FL_ACPI_START) && crb_do_acpi_start(chip))
dev_err(&chip->dev, "ACPI Start failed\n");
}
static bool crb_req_canceled(struct tpm_chip *chip, u8 status)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
u32 cancel = ioread32(&priv->cca->cancel);
return (cancel & CRB_CANCEL_INVOKE) == CRB_CANCEL_INVOKE;
}
static int crb_check_resource(struct acpi_resource *ares, void *data)
{
struct resource *io_res = data;
struct resource res;
if (acpi_dev_resource_memory(ares, &res)) {
*io_res = res;
io_res->name = NULL;
}
return 1;
}
static void __iomem *crb_map_res(struct device *dev, struct crb_priv *priv,
struct resource *io_res, u64 start, u32 size)
{
struct resource new_res = {
.start = start,
.end = start + size - 1,
.flags = IORESOURCE_MEM,
};
if (start != new_res.start)
return (void __iomem *) ERR_PTR(-EINVAL);
if (!resource_contains(io_res, &new_res))
return devm_ioremap_resource(dev, &new_res);
return priv->iobase + (new_res.start - io_res->start);
}
static int crb_map_io(struct acpi_device *device, struct crb_priv *priv,
struct acpi_table_tpm2 *buf)
{
struct list_head resources;
struct resource io_res;
struct device *dev = &device->dev;
u32 pa_high, pa_low;
u64 cmd_pa;
u32 cmd_size;
u64 rsp_pa;
u32 rsp_size;
int ret;
INIT_LIST_HEAD(&resources);
ret = acpi_dev_get_resources(device, &resources, crb_check_resource,
&io_res);
if (ret < 0)
return ret;
acpi_dev_free_resource_list(&resources);
if (resource_type(&io_res) != IORESOURCE_MEM) {
dev_err(dev, FW_BUG "TPM2 ACPI table does not define a memory resource\n");
return -EINVAL;
}
priv->iobase = devm_ioremap_resource(dev, &io_res);
if (IS_ERR(priv->iobase))
return PTR_ERR(priv->iobase);
priv->cca = crb_map_res(dev, priv, &io_res, buf->control_address,
sizeof(struct crb_control_area));
if (IS_ERR(priv->cca))
return PTR_ERR(priv->cca);
ret = crb_cmd_ready(dev, priv);
if (ret)
return ret;
pa_high = ioread32(&priv->cca->cmd_pa_high);
pa_low = ioread32(&priv->cca->cmd_pa_low);
cmd_pa = ((u64)pa_high << 32) | pa_low;
cmd_size = ioread32(&priv->cca->cmd_size);
dev_dbg(dev, "cmd_hi = %X cmd_low = %X cmd_size %X\n",
pa_high, pa_low, cmd_size);
priv->cmd = crb_map_res(dev, priv, &io_res, cmd_pa, cmd_size);
if (IS_ERR(priv->cmd)) {
ret = PTR_ERR(priv->cmd);
goto out;
}
memcpy_fromio(&rsp_pa, &priv->cca->rsp_pa, 8);
rsp_pa = le64_to_cpu(rsp_pa);
rsp_size = ioread32(&priv->cca->rsp_size);
if (cmd_pa != rsp_pa) {
priv->rsp = crb_map_res(dev, priv, &io_res, rsp_pa, rsp_size);
ret = PTR_ERR_OR_ZERO(priv->rsp);
goto out;
}
if (cmd_size != rsp_size) {
dev_err(dev, FW_BUG "overlapping command and response buffer sizes are not identical");
ret = -EINVAL;
goto out;
}
priv->cmd_size = cmd_size;
priv->rsp = priv->cmd;
out:
crb_go_idle(dev, priv);
return ret;
}
static int crb_acpi_add(struct acpi_device *device)
{
struct acpi_table_tpm2 *buf;
struct crb_priv *priv;
struct tpm_chip *chip;
struct device *dev = &device->dev;
acpi_status status;
u32 sm;
int rc;
status = acpi_get_table(ACPI_SIG_TPM2, 1,
(struct acpi_table_header **) &buf);
if (ACPI_FAILURE(status) || buf->header.length < sizeof(*buf)) {
dev_err(dev, FW_BUG "failed to get TPM2 ACPI table\n");
return -EINVAL;
}
sm = buf->start_method;
if (sm == ACPI_TPM2_MEMORY_MAPPED)
return -ENODEV;
priv = devm_kzalloc(dev, sizeof(struct crb_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
if (sm == ACPI_TPM2_COMMAND_BUFFER || sm == ACPI_TPM2_MEMORY_MAPPED ||
!strcmp(acpi_device_hid(device), "MSFT0101"))
priv->flags |= CRB_FL_CRB_START;
if (sm == ACPI_TPM2_START_METHOD ||
sm == ACPI_TPM2_COMMAND_BUFFER_WITH_START_METHOD)
priv->flags |= CRB_FL_ACPI_START;
rc = crb_map_io(device, priv, buf);
if (rc)
return rc;
chip = tpmm_chip_alloc(dev, &tpm_crb);
if (IS_ERR(chip))
return PTR_ERR(chip);
dev_set_drvdata(&chip->dev, priv);
chip->acpi_dev_handle = device->handle;
chip->flags = TPM_CHIP_FLAG_TPM2;
rc = crb_cmd_ready(dev, priv);
if (rc)
return rc;
pm_runtime_get_noresume(dev);
pm_runtime_set_active(dev);
pm_runtime_enable(dev);
rc = tpm_chip_register(chip);
if (rc) {
crb_go_idle(dev, priv);
pm_runtime_put_noidle(dev);
pm_runtime_disable(dev);
return rc;
}
pm_runtime_put(dev);
return 0;
}
static int crb_acpi_remove(struct acpi_device *device)
{
struct device *dev = &device->dev;
struct tpm_chip *chip = dev_get_drvdata(dev);
tpm_chip_unregister(chip);
pm_runtime_disable(dev);
return 0;
}
static int crb_pm_runtime_suspend(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
return crb_go_idle(dev, priv);
}
static int crb_pm_runtime_resume(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
return crb_cmd_ready(dev, priv);
}
