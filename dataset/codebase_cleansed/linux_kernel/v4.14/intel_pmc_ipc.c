static inline void ipc_send_command(u32 cmd)
{
ipcdev.cmd = cmd;
if (ipcdev.irq_mode) {
reinit_completion(&ipcdev.cmd_complete);
cmd |= IPC_CMD_MSI;
}
writel(cmd, ipcdev.ipc_base + IPC_CMD);
}
static inline u32 ipc_read_status(void)
{
return readl(ipcdev.ipc_base + IPC_STATUS);
}
static inline void ipc_data_writel(u32 data, u32 offset)
{
writel(data, ipcdev.ipc_base + IPC_WRITE_BUFFER + offset);
}
static inline u8 __maybe_unused ipc_data_readb(u32 offset)
{
return readb(ipcdev.ipc_base + IPC_READ_BUFFER + offset);
}
static inline u32 ipc_data_readl(u32 offset)
{
return readl(ipcdev.ipc_base + IPC_READ_BUFFER + offset);
}
static inline u64 gcr_data_readq(u32 offset)
{
return readq(ipcdev.gcr_mem_base + offset);
}
static inline int is_gcr_valid(u32 offset)
{
if (!ipcdev.has_gcr_regs)
return -EACCES;
if (offset > PLAT_RESOURCE_GCR_SIZE)
return -EINVAL;
return 0;
}
int intel_pmc_gcr_read(u32 offset, u32 *data)
{
int ret;
spin_lock(&ipcdev.gcr_lock);
ret = is_gcr_valid(offset);
if (ret < 0) {
spin_unlock(&ipcdev.gcr_lock);
return ret;
}
*data = readl(ipcdev.gcr_mem_base + offset);
spin_unlock(&ipcdev.gcr_lock);
return 0;
}
int intel_pmc_gcr_write(u32 offset, u32 data)
{
int ret;
spin_lock(&ipcdev.gcr_lock);
ret = is_gcr_valid(offset);
if (ret < 0) {
spin_unlock(&ipcdev.gcr_lock);
return ret;
}
writel(data, ipcdev.gcr_mem_base + offset);
spin_unlock(&ipcdev.gcr_lock);
return 0;
}
int intel_pmc_gcr_update(u32 offset, u32 mask, u32 val)
{
u32 new_val;
int ret = 0;
spin_lock(&ipcdev.gcr_lock);
ret = is_gcr_valid(offset);
if (ret < 0)
goto gcr_ipc_unlock;
new_val = readl(ipcdev.gcr_mem_base + offset);
new_val &= ~mask;
new_val |= val & mask;
writel(new_val, ipcdev.gcr_mem_base + offset);
new_val = readl(ipcdev.gcr_mem_base + offset);
if ((new_val & mask) != (val & mask)) {
ret = -EIO;
goto gcr_ipc_unlock;
}
gcr_ipc_unlock:
spin_unlock(&ipcdev.gcr_lock);
return ret;
}
static int update_no_reboot_bit(void *priv, bool set)
{
u32 value = set ? PMC_CFG_NO_REBOOT_EN : PMC_CFG_NO_REBOOT_DIS;
return intel_pmc_gcr_update(PMC_GCR_PMC_CFG_REG,
PMC_CFG_NO_REBOOT_MASK, value);
}
static int intel_pmc_ipc_check_status(void)
{
int status;
int ret = 0;
if (ipcdev.irq_mode) {
if (0 == wait_for_completion_timeout(
&ipcdev.cmd_complete, IPC_MAX_SEC * HZ))
ret = -ETIMEDOUT;
} else {
int loop_count = IPC_LOOP_CNT;
while ((ipc_read_status() & IPC_STATUS_BUSY) && --loop_count)
udelay(1);
if (loop_count == 0)
ret = -ETIMEDOUT;
}
status = ipc_read_status();
if (ret == -ETIMEDOUT) {
dev_err(ipcdev.dev,
"IPC timed out, TS=0x%x, CMD=0x%x\n",
status, ipcdev.cmd);
return ret;
}
if (status & IPC_STATUS_ERR) {
int i;
ret = -EIO;
i = (status >> IPC_CMD_SIZE) & 0xFF;
if (i < ARRAY_SIZE(ipc_err_sources))
dev_err(ipcdev.dev,
"IPC failed: %s, STS=0x%x, CMD=0x%x\n",
ipc_err_sources[i], status, ipcdev.cmd);
else
dev_err(ipcdev.dev,
"IPC failed: unknown, STS=0x%x, CMD=0x%x\n",
status, ipcdev.cmd);
if ((i == IPC_ERR_UNSIGNEDKERNEL) || (i == IPC_ERR_EMSECURITY))
ret = -EACCES;
}
return ret;
}
int intel_pmc_ipc_simple_command(int cmd, int sub)
{
int ret;
mutex_lock(&ipclock);
if (ipcdev.dev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
ipc_send_command(sub << IPC_CMD_SUBCMD | cmd);
ret = intel_pmc_ipc_check_status();
mutex_unlock(&ipclock);
return ret;
}
int intel_pmc_ipc_raw_cmd(u32 cmd, u32 sub, u8 *in, u32 inlen, u32 *out,
u32 outlen, u32 dptr, u32 sptr)
{
u32 wbuf[4] = { 0 };
int ret;
int i;
if (inlen > IPC_DATA_BUFFER_SIZE || outlen > IPC_DATA_BUFFER_SIZE / 4)
return -EINVAL;
mutex_lock(&ipclock);
if (ipcdev.dev == NULL) {
mutex_unlock(&ipclock);
return -ENODEV;
}
memcpy(wbuf, in, inlen);
writel(dptr, ipcdev.ipc_base + IPC_DPTR);
writel(sptr, ipcdev.ipc_base + IPC_SPTR);
for (i = 0; i < ((inlen + 3) / 4); i++)
ipc_data_writel(wbuf[i], 4 * i);
ipc_send_command((inlen << IPC_CMD_SIZE) |
(sub << IPC_CMD_SUBCMD) | cmd);
ret = intel_pmc_ipc_check_status();
if (!ret) {
for (i = 0; i < outlen; i++)
*out++ = ipc_data_readl(4 * i);
}
mutex_unlock(&ipclock);
return ret;
}
int intel_pmc_ipc_command(u32 cmd, u32 sub, u8 *in, u32 inlen,
u32 *out, u32 outlen)
{
return intel_pmc_ipc_raw_cmd(cmd, sub, in, inlen, out, outlen, 0, 0);
}
static irqreturn_t ioc(int irq, void *dev_id)
{
int status;
if (ipcdev.irq_mode) {
status = ipc_read_status();
writel(status | IPC_STATUS_IRQ, ipcdev.ipc_base + IPC_STATUS);
}
complete(&ipcdev.cmd_complete);
return IRQ_HANDLED;
}
static int ipc_pci_probe(struct pci_dev *pdev, const struct pci_device_id *id)
{
struct intel_pmc_ipc_dev *pmc = &ipcdev;
int ret;
if (pmc->dev)
return -EBUSY;
pmc->irq_mode = IPC_TRIGGER_MODE_IRQ;
spin_lock_init(&ipcdev.gcr_lock);
ret = pcim_enable_device(pdev);
if (ret)
return ret;
ret = pcim_iomap_regions(pdev, 1 << 0, pci_name(pdev));
if (ret)
return ret;
init_completion(&pmc->cmd_complete);
pmc->ipc_base = pcim_iomap_table(pdev)[0];
ret = devm_request_irq(&pdev->dev, pdev->irq, ioc, 0, "intel_pmc_ipc",
pmc);
if (ret) {
dev_err(&pdev->dev, "Failed to request irq\n");
return ret;
}
pmc->dev = &pdev->dev;
pci_set_drvdata(pdev, pmc);
return 0;
}
static ssize_t intel_pmc_ipc_simple_cmd_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
int subcmd;
int cmd;
int ret;
ret = sscanf(buf, "%d %d", &cmd, &subcmd);
if (ret != 2) {
dev_err(dev, "Error args\n");
return -EINVAL;
}
ret = intel_pmc_ipc_simple_command(cmd, subcmd);
if (ret) {
dev_err(dev, "command %d error with %d\n", cmd, ret);
return ret;
}
return (ssize_t)count;
}
static ssize_t intel_pmc_ipc_northpeak_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
unsigned long val;
int subcmd;
int ret;
if (kstrtoul(buf, 0, &val))
return -EINVAL;
if (val)
subcmd = 1;
else
subcmd = 0;
ret = intel_pmc_ipc_simple_command(PMC_IPC_NORTHPEAK_CTRL, subcmd);
if (ret) {
dev_err(dev, "command north %d error with %d\n", subcmd, ret);
return ret;
}
return (ssize_t)count;
}
static int ipc_create_punit_device(void)
{
struct platform_device *pdev;
const struct platform_device_info pdevinfo = {
.parent = ipcdev.dev,
.name = PUNIT_DEVICE_NAME,
.id = -1,
.res = punit_res_array,
.num_res = ARRAY_SIZE(punit_res_array),
};
pdev = platform_device_register_full(&pdevinfo);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
ipcdev.punit_dev = pdev;
return 0;
}
static int ipc_create_tco_device(void)
{
struct platform_device *pdev;
struct resource *res;
const struct platform_device_info pdevinfo = {
.parent = ipcdev.dev,
.name = TCO_DEVICE_NAME,
.id = -1,
.res = tco_res,
.num_res = ARRAY_SIZE(tco_res),
.data = &tco_info,
.size_data = sizeof(tco_info),
};
res = tco_res + TCO_RESOURCE_ACPI_IO;
res->start = ipcdev.acpi_io_base + TCO_BASE_OFFSET;
res->end = res->start + TCO_REGS_SIZE - 1;
res = tco_res + TCO_RESOURCE_SMI_EN_IO;
res->start = ipcdev.acpi_io_base + SMI_EN_OFFSET;
res->end = res->start + SMI_EN_SIZE - 1;
pdev = platform_device_register_full(&pdevinfo);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
ipcdev.tco_dev = pdev;
return 0;
}
static int ipc_create_telemetry_device(void)
{
struct platform_device *pdev;
struct resource *res;
const struct platform_device_info pdevinfo = {
.parent = ipcdev.dev,
.name = TELEMETRY_DEVICE_NAME,
.id = -1,
.res = telemetry_res,
.num_res = ARRAY_SIZE(telemetry_res),
};
res = telemetry_res + TELEMETRY_RESOURCE_PUNIT_SSRAM;
res->start = ipcdev.telem_punit_ssram_base;
res->end = res->start + ipcdev.telem_punit_ssram_size - 1;
res = telemetry_res + TELEMETRY_RESOURCE_PMC_SSRAM;
res->start = ipcdev.telem_pmc_ssram_base;
res->end = res->start + ipcdev.telem_pmc_ssram_size - 1;
pdev = platform_device_register_full(&pdevinfo);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
ipcdev.telemetry_dev = pdev;
return 0;
}
static int ipc_create_pmc_devices(void)
{
int ret;
if (!acpi_has_watchdog()) {
ret = ipc_create_tco_device();
if (ret) {
dev_err(ipcdev.dev, "Failed to add tco platform device\n");
return ret;
}
}
ret = ipc_create_punit_device();
if (ret) {
dev_err(ipcdev.dev, "Failed to add punit platform device\n");
platform_device_unregister(ipcdev.tco_dev);
}
if (!ipcdev.telem_res_inval) {
ret = ipc_create_telemetry_device();
if (ret)
dev_warn(ipcdev.dev,
"Failed to add telemetry platform device\n");
}
return ret;
}
static int ipc_plat_get_res(struct platform_device *pdev)
{
struct resource *res, *punit_res;
void __iomem *addr;
int size;
res = platform_get_resource(pdev, IORESOURCE_IO,
PLAT_RESOURCE_ACPI_IO_INDEX);
if (!res) {
dev_err(&pdev->dev, "Failed to get io resource\n");
return -ENXIO;
}
size = resource_size(res);
ipcdev.acpi_io_base = res->start;
ipcdev.acpi_io_size = size;
dev_info(&pdev->dev, "io res: %pR\n", res);
punit_res = punit_res_array;
res = platform_get_resource(pdev, IORESOURCE_MEM,
PLAT_RESOURCE_BIOS_DATA_INDEX);
if (!res) {
dev_err(&pdev->dev, "Failed to get res of punit BIOS data\n");
return -ENXIO;
}
*punit_res = *res;
dev_info(&pdev->dev, "punit BIOS data res: %pR\n", res);
res = platform_get_resource(pdev, IORESOURCE_MEM,
PLAT_RESOURCE_BIOS_IFACE_INDEX);
if (!res) {
dev_err(&pdev->dev, "Failed to get res of punit BIOS iface\n");
return -ENXIO;
}
*++punit_res = *res;
dev_info(&pdev->dev, "punit BIOS interface res: %pR\n", res);
res = platform_get_resource(pdev, IORESOURCE_MEM,
PLAT_RESOURCE_ISP_DATA_INDEX);
++punit_res;
if (res) {
*punit_res = *res;
dev_info(&pdev->dev, "punit ISP data res: %pR\n", res);
}
res = platform_get_resource(pdev, IORESOURCE_MEM,
PLAT_RESOURCE_ISP_IFACE_INDEX);
++punit_res;
if (res) {
*punit_res = *res;
dev_info(&pdev->dev, "punit ISP interface res: %pR\n", res);
}
res = platform_get_resource(pdev, IORESOURCE_MEM,
PLAT_RESOURCE_GTD_DATA_INDEX);
++punit_res;
if (res) {
*punit_res = *res;
dev_info(&pdev->dev, "punit GTD data res: %pR\n", res);
}
res = platform_get_resource(pdev, IORESOURCE_MEM,
PLAT_RESOURCE_GTD_IFACE_INDEX);
++punit_res;
if (res) {
*punit_res = *res;
dev_info(&pdev->dev, "punit GTD interface res: %pR\n", res);
}
res = platform_get_resource(pdev, IORESOURCE_MEM,
PLAT_RESOURCE_IPC_INDEX);
if (!res) {
dev_err(&pdev->dev, "Failed to get ipc resource\n");
return -ENXIO;
}
size = PLAT_RESOURCE_IPC_SIZE + PLAT_RESOURCE_GCR_SIZE;
res->end = res->start + size - 1;
addr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(addr))
return PTR_ERR(addr);
ipcdev.ipc_base = addr;
ipcdev.gcr_mem_base = addr + PLAT_RESOURCE_GCR_OFFSET;
dev_info(&pdev->dev, "ipc res: %pR\n", res);
ipcdev.telem_res_inval = 0;
res = platform_get_resource(pdev, IORESOURCE_MEM,
PLAT_RESOURCE_TELEM_SSRAM_INDEX);
if (!res) {
dev_err(&pdev->dev, "Failed to get telemetry ssram resource\n");
ipcdev.telem_res_inval = 1;
} else {
ipcdev.telem_punit_ssram_base = res->start +
TELEM_PUNIT_SSRAM_OFFSET;
ipcdev.telem_punit_ssram_size = TELEM_SSRAM_SIZE;
ipcdev.telem_pmc_ssram_base = res->start +
TELEM_PMC_SSRAM_OFFSET;
ipcdev.telem_pmc_ssram_size = TELEM_SSRAM_SIZE;
dev_info(&pdev->dev, "telemetry ssram res: %pR\n", res);
}
return 0;
}
int intel_pmc_s0ix_counter_read(u64 *data)
{
u64 deep, shlw;
if (!ipcdev.has_gcr_regs)
return -EACCES;
deep = gcr_data_readq(PMC_GCR_TELEM_DEEP_S0IX_REG);
shlw = gcr_data_readq(PMC_GCR_TELEM_SHLW_S0IX_REG);
*data = S0IX_RESIDENCY_IN_USECS(deep, shlw);
return 0;
}
static int ipc_plat_probe(struct platform_device *pdev)
{
int ret;
ipcdev.dev = &pdev->dev;
ipcdev.irq_mode = IPC_TRIGGER_MODE_IRQ;
init_completion(&ipcdev.cmd_complete);
spin_lock_init(&ipcdev.gcr_lock);
ipcdev.irq = platform_get_irq(pdev, 0);
if (ipcdev.irq < 0) {
dev_err(&pdev->dev, "Failed to get irq\n");
return -EINVAL;
}
ret = ipc_plat_get_res(pdev);
if (ret) {
dev_err(&pdev->dev, "Failed to request resource\n");
return ret;
}
ret = ipc_create_pmc_devices();
if (ret) {
dev_err(&pdev->dev, "Failed to create pmc devices\n");
return ret;
}
if (devm_request_irq(&pdev->dev, ipcdev.irq, ioc, IRQF_NO_SUSPEND,
"intel_pmc_ipc", &ipcdev)) {
dev_err(&pdev->dev, "Failed to request irq\n");
ret = -EBUSY;
goto err_irq;
}
ret = sysfs_create_group(&pdev->dev.kobj, &intel_ipc_group);
if (ret) {
dev_err(&pdev->dev, "Failed to create sysfs group %d\n",
ret);
goto err_sys;
}
ipcdev.has_gcr_regs = true;
return 0;
err_sys:
devm_free_irq(&pdev->dev, ipcdev.irq, &ipcdev);
err_irq:
platform_device_unregister(ipcdev.tco_dev);
platform_device_unregister(ipcdev.punit_dev);
platform_device_unregister(ipcdev.telemetry_dev);
return ret;
}
static int ipc_plat_remove(struct platform_device *pdev)
{
sysfs_remove_group(&pdev->dev.kobj, &intel_ipc_group);
devm_free_irq(&pdev->dev, ipcdev.irq, &ipcdev);
platform_device_unregister(ipcdev.tco_dev);
platform_device_unregister(ipcdev.punit_dev);
platform_device_unregister(ipcdev.telemetry_dev);
ipcdev.dev = NULL;
return 0;
}
static int __init intel_pmc_ipc_init(void)
{
int ret;
ret = platform_driver_register(&ipc_plat_driver);
if (ret) {
pr_err("Failed to register PMC ipc platform driver\n");
return ret;
}
ret = pci_register_driver(&ipc_pci_driver);
if (ret) {
pr_err("Failed to register PMC ipc pci driver\n");
platform_driver_unregister(&ipc_plat_driver);
return ret;
}
return ret;
}
static void __exit intel_pmc_ipc_exit(void)
{
pci_unregister_driver(&ipc_pci_driver);
platform_driver_unregister(&ipc_plat_driver);
}
