static int __maybe_unused crb_go_idle(struct device *dev, struct crb_priv *priv)
{
if ((priv->flags & CRB_FL_ACPI_START) ||
(priv->flags & CRB_FL_CRB_SMC_START))
return 0;
iowrite32(CRB_CTRL_REQ_GO_IDLE, &priv->regs_t->ctrl_req);
return 0;
}
static bool crb_wait_for_reg_32(u32 __iomem *reg, u32 mask, u32 value,
unsigned long timeout)
{
ktime_t start;
ktime_t stop;
start = ktime_get();
stop = ktime_add(start, ms_to_ktime(timeout));
do {
if ((ioread32(reg) & mask) == value)
return true;
usleep_range(50, 100);
} while (ktime_before(ktime_get(), stop));
return false;
}
static int __maybe_unused crb_cmd_ready(struct device *dev,
struct crb_priv *priv)
{
if ((priv->flags & CRB_FL_ACPI_START) ||
(priv->flags & CRB_FL_CRB_SMC_START))
return 0;
iowrite32(CRB_CTRL_REQ_CMD_READY, &priv->regs_t->ctrl_req);
if (!crb_wait_for_reg_32(&priv->regs_t->ctrl_req,
CRB_CTRL_REQ_CMD_READY ,
0,
TPM2_TIMEOUT_C)) {
dev_warn(dev, "cmdReady timed out\n");
return -ETIME;
}
return 0;
}
static int crb_request_locality(struct tpm_chip *chip, int loc)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
u32 value = CRB_LOC_STATE_LOC_ASSIGNED |
CRB_LOC_STATE_TPM_REG_VALID_STS;
if (!priv->regs_h)
return 0;
iowrite32(CRB_LOC_CTRL_REQUEST_ACCESS, &priv->regs_h->loc_ctrl);
if (!crb_wait_for_reg_32(&priv->regs_h->loc_state, value, value,
TPM2_TIMEOUT_C)) {
dev_warn(&chip->dev, "TPM_LOC_STATE_x.requestAccess timed out\n");
return -ETIME;
}
return 0;
}
static void crb_relinquish_locality(struct tpm_chip *chip, int loc)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
if (!priv->regs_h)
return;
iowrite32(CRB_LOC_CTRL_RELINQUISH, &priv->regs_h->loc_ctrl);
}
static u8 crb_status(struct tpm_chip *chip)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
u8 sts = 0;
if ((ioread32(&priv->regs_t->ctrl_start) & CRB_START_INVOKE) !=
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
if (ioread32(&priv->regs_t->ctrl_sts) & CRB_CTRL_STS_ERROR)
return -EIO;
memcpy_fromio(buf, priv->rsp, 6);
expected = be32_to_cpup((__be32 *) &buf[2]);
if (expected > count || expected < 6)
return -EIO;
memcpy_fromio(&buf[6], &priv->rsp[6], expected - 6);
return expected;
}
static int crb_do_acpi_start(struct tpm_chip *chip)
{
union acpi_object *obj;
int rc;
obj = acpi_evaluate_dsm(chip->acpi_dev_handle,
&crb_acpi_start_guid,
CRB_ACPI_START_REVISION_ID,
CRB_ACPI_START_INDEX,
NULL);
if (!obj)
return -ENXIO;
rc = obj->integer.value == 0 ? 0 : -ENXIO;
ACPI_FREE(obj);
return rc;
}
static int tpm_crb_smc_start(struct device *dev, unsigned long func_id)
{
struct arm_smccc_res res;
arm_smccc_smc(func_id, 0, 0, 0, 0, 0, 0, 0, &res);
if (res.a0 != 0) {
dev_err(dev,
FW_BUG "tpm_crb_smc_start() returns res.a0 = 0x%lx\n",
res.a0);
return -EIO;
}
return 0;
}
static int tpm_crb_smc_start(struct device *dev, unsigned long func_id)
{
dev_err(dev, FW_BUG "tpm_crb: incorrect start method\n");
return -EINVAL;
}
static int crb_send(struct tpm_chip *chip, u8 *buf, size_t len)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
int rc = 0;
iowrite32(0, &priv->regs_t->ctrl_cancel);
if (len > priv->cmd_size) {
dev_err(&chip->dev, "invalid command count value %zd %d\n",
len, priv->cmd_size);
return -E2BIG;
}
memcpy_toio(priv->cmd, buf, len);
wmb();
if (priv->flags & CRB_FL_CRB_START)
iowrite32(CRB_START_INVOKE, &priv->regs_t->ctrl_start);
if (priv->flags & CRB_FL_ACPI_START)
rc = crb_do_acpi_start(chip);
if (priv->flags & CRB_FL_CRB_SMC_START) {
iowrite32(CRB_START_INVOKE, &priv->regs_t->ctrl_start);
rc = tpm_crb_smc_start(&chip->dev, priv->smc_func_id);
}
return rc;
}
static void crb_cancel(struct tpm_chip *chip)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
iowrite32(CRB_CANCEL_INVOKE, &priv->regs_t->ctrl_cancel);
if ((priv->flags & CRB_FL_ACPI_START) && crb_do_acpi_start(chip))
dev_err(&chip->dev, "ACPI Start failed\n");
}
static bool crb_req_canceled(struct tpm_chip *chip, u8 status)
{
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
u32 cancel = ioread32(&priv->regs_t->ctrl_cancel);
return (cancel & CRB_CANCEL_INVOKE) == CRB_CANCEL_INVOKE;
}
static int crb_check_resource(struct acpi_resource *ares, void *data)
{
struct resource *io_res = data;
struct resource_win win;
struct resource *res = &(win.res);
if (acpi_dev_resource_memory(ares, res) ||
acpi_dev_resource_address_space(ares, &win)) {
*io_res = *res;
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
static u64 crb_fixup_cmd_size(struct device *dev, struct resource *io_res,
u64 start, u64 size)
{
if (io_res->start > start || io_res->end < start)
return size;
if (start + size - 1 <= io_res->end)
return size;
dev_err(dev,
FW_BUG "ACPI region does not cover the entire command/response buffer. %pr vs %llx %llx\n",
io_res, start, size);
return io_res->end - start + 1;
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
if (!(priv->flags & CRB_FL_ACPI_START)) {
if (buf->control_address == io_res.start +
sizeof(*priv->regs_h))
priv->regs_h = priv->iobase;
else
dev_warn(dev, FW_BUG "Bad ACPI memory layout");
}
priv->regs_t = crb_map_res(dev, priv, &io_res, buf->control_address,
sizeof(struct crb_regs_tail));
if (IS_ERR(priv->regs_t))
return PTR_ERR(priv->regs_t);
ret = crb_cmd_ready(dev, priv);
if (ret)
return ret;
pa_high = ioread32(&priv->regs_t->ctrl_cmd_pa_high);
pa_low = ioread32(&priv->regs_t->ctrl_cmd_pa_low);
cmd_pa = ((u64)pa_high << 32) | pa_low;
cmd_size = crb_fixup_cmd_size(dev, &io_res, cmd_pa,
ioread32(&priv->regs_t->ctrl_cmd_size));
dev_dbg(dev, "cmd_hi = %X cmd_low = %X cmd_size %X\n",
pa_high, pa_low, cmd_size);
priv->cmd = crb_map_res(dev, priv, &io_res, cmd_pa, cmd_size);
if (IS_ERR(priv->cmd)) {
ret = PTR_ERR(priv->cmd);
goto out;
}
memcpy_fromio(&rsp_pa, &priv->regs_t->ctrl_rsp_pa, 8);
rsp_pa = le64_to_cpu(rsp_pa);
rsp_size = crb_fixup_cmd_size(dev, &io_res, rsp_pa,
ioread32(&priv->regs_t->ctrl_rsp_size));
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
priv->rsp = priv->cmd;
out:
if (!ret)
priv->cmd_size = cmd_size;
crb_go_idle(dev, priv);
return ret;
}
static int crb_acpi_add(struct acpi_device *device)
{
struct acpi_table_tpm2 *buf;
struct crb_priv *priv;
struct tpm_chip *chip;
struct device *dev = &device->dev;
struct tpm2_crb_smc *crb_smc;
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
if (sm == ACPI_TPM2_COMMAND_BUFFER_WITH_ARM_SMC) {
if (buf->header.length < (sizeof(*buf) + sizeof(*crb_smc))) {
dev_err(dev,
FW_BUG "TPM2 ACPI table has wrong size %u for start method type %d\n",
buf->header.length,
ACPI_TPM2_COMMAND_BUFFER_WITH_ARM_SMC);
return -EINVAL;
}
crb_smc = ACPI_ADD_PTR(struct tpm2_crb_smc, buf, sizeof(*buf));
priv->smc_func_id = crb_smc->smc_func_id;
priv->flags |= CRB_FL_CRB_SMC_START;
}
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
static int __maybe_unused crb_pm_runtime_suspend(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
return crb_go_idle(dev, priv);
}
static int __maybe_unused crb_pm_runtime_resume(struct device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(dev);
struct crb_priv *priv = dev_get_drvdata(&chip->dev);
return crb_cmd_ready(dev, priv);
}
static int __maybe_unused crb_pm_suspend(struct device *dev)
{
int ret;
ret = tpm_pm_suspend(dev);
if (ret)
return ret;
return crb_pm_runtime_suspend(dev);
}
static int __maybe_unused crb_pm_resume(struct device *dev)
{
int ret;
ret = crb_pm_runtime_resume(dev);
if (ret)
return ret;
return tpm_pm_resume(dev);
}
