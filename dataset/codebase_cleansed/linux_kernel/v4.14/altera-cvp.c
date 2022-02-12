static enum fpga_mgr_states altera_cvp_state(struct fpga_manager *mgr)
{
struct altera_cvp_conf *conf = mgr->priv;
u32 status;
pci_read_config_dword(conf->pci_dev, VSE_CVP_STATUS, &status);
if (status & VSE_CVP_STATUS_CFG_DONE)
return FPGA_MGR_STATE_OPERATING;
if (status & VSE_CVP_STATUS_CVP_EN)
return FPGA_MGR_STATE_POWER_UP;
return FPGA_MGR_STATE_UNKNOWN;
}
static void altera_cvp_write_data_iomem(struct altera_cvp_conf *conf, u32 val)
{
writel(val, conf->map);
}
static void altera_cvp_write_data_config(struct altera_cvp_conf *conf, u32 val)
{
pci_write_config_dword(conf->pci_dev, VSE_CVP_DATA, val);
}
static void altera_cvp_dummy_write(struct altera_cvp_conf *conf)
{
unsigned int i;
u32 val;
pci_read_config_dword(conf->pci_dev, VSE_CVP_MODE_CTRL, &val);
val &= ~VSE_CVP_MODE_CTRL_NUMCLKS_MASK;
val |= 1 << VSE_CVP_MODE_CTRL_NUMCLKS_OFF;
pci_write_config_dword(conf->pci_dev, VSE_CVP_MODE_CTRL, val);
for (i = 0; i < CVP_DUMMY_WR; i++)
conf->write_data(conf, 0);
}
static int altera_cvp_wait_status(struct altera_cvp_conf *conf, u32 status_mask,
u32 status_val, int timeout_us)
{
unsigned int retries;
u32 val;
retries = timeout_us / 10;
if (timeout_us % 10)
retries++;
do {
pci_read_config_dword(conf->pci_dev, VSE_CVP_STATUS, &val);
if ((val & status_mask) == status_val)
return 0;
usleep_range(10, 11);
} while (--retries);
return -ETIMEDOUT;
}
static int altera_cvp_teardown(struct fpga_manager *mgr,
struct fpga_image_info *info)
{
struct altera_cvp_conf *conf = mgr->priv;
struct pci_dev *pdev = conf->pci_dev;
int ret;
u32 val;
pci_read_config_dword(pdev, VSE_CVP_PROG_CTRL, &val);
val &= ~VSE_CVP_PROG_CTRL_START_XFER;
pci_write_config_dword(pdev, VSE_CVP_PROG_CTRL, val);
val &= ~VSE_CVP_PROG_CTRL_CONFIG;
pci_write_config_dword(pdev, VSE_CVP_PROG_CTRL, val);
altera_cvp_dummy_write(conf);
ret = altera_cvp_wait_status(conf, VSE_CVP_STATUS_CFG_RDY, 0, 10);
if (ret)
dev_err(&mgr->dev, "CFG_RDY == 0 timeout\n");
return ret;
}
static int altera_cvp_write_init(struct fpga_manager *mgr,
struct fpga_image_info *info,
const char *buf, size_t count)
{
struct altera_cvp_conf *conf = mgr->priv;
struct pci_dev *pdev = conf->pci_dev;
u32 iflags, val;
int ret;
iflags = info ? info->flags : 0;
if (iflags & FPGA_MGR_PARTIAL_RECONFIG) {
dev_err(&mgr->dev, "Partial reconfiguration not supported.\n");
return -EINVAL;
}
if (iflags & FPGA_MGR_COMPRESSED_BITSTREAM)
conf->numclks = 8;
else if (iflags & FPGA_MGR_ENCRYPTED_BITSTREAM)
conf->numclks = 4;
else
conf->numclks = 1;
pci_read_config_dword(pdev, VSE_CVP_STATUS, &val);
if (!(val & VSE_CVP_STATUS_CVP_EN)) {
dev_err(&mgr->dev, "CVP mode off: 0x%04x\n", val);
return -ENODEV;
}
if (val & VSE_CVP_STATUS_CFG_RDY) {
dev_warn(&mgr->dev, "CvP already started, teardown first\n");
ret = altera_cvp_teardown(mgr, info);
if (ret)
return ret;
}
pci_read_config_dword(pdev, VSE_CVP_MODE_CTRL, &val);
val |= VSE_CVP_MODE_CTRL_HIP_CLK_SEL;
pci_write_config_dword(pdev, VSE_CVP_MODE_CTRL, val);
pci_read_config_dword(pdev, VSE_CVP_MODE_CTRL, &val);
val |= VSE_CVP_MODE_CTRL_CVP_MODE;
pci_write_config_dword(pdev, VSE_CVP_MODE_CTRL, val);
altera_cvp_dummy_write(conf);
pci_read_config_dword(pdev, VSE_CVP_PROG_CTRL, &val);
val |= VSE_CVP_PROG_CTRL_CONFIG;
pci_write_config_dword(pdev, VSE_CVP_PROG_CTRL, val);
ret = altera_cvp_wait_status(conf, VSE_CVP_STATUS_CFG_RDY,
VSE_CVP_STATUS_CFG_RDY, 10);
if (ret) {
dev_warn(&mgr->dev, "CFG_RDY == 1 timeout\n");
return ret;
}
altera_cvp_dummy_write(conf);
pci_read_config_dword(pdev, VSE_CVP_PROG_CTRL, &val);
val |= VSE_CVP_PROG_CTRL_START_XFER;
pci_write_config_dword(pdev, VSE_CVP_PROG_CTRL, val);
pci_read_config_dword(pdev, VSE_CVP_MODE_CTRL, &val);
val &= ~VSE_CVP_MODE_CTRL_NUMCLKS_MASK;
val |= conf->numclks << VSE_CVP_MODE_CTRL_NUMCLKS_OFF;
pci_write_config_dword(pdev, VSE_CVP_MODE_CTRL, val);
return 0;
}
static inline int altera_cvp_chk_error(struct fpga_manager *mgr, size_t bytes)
{
struct altera_cvp_conf *conf = mgr->priv;
u32 val;
pci_read_config_dword(conf->pci_dev, VSE_CVP_STATUS, &val);
if (val & VSE_CVP_STATUS_CFG_ERR) {
dev_err(&mgr->dev, "CVP_CONFIG_ERROR after %zu bytes!\n",
bytes);
return -EPROTO;
}
return 0;
}
static int altera_cvp_write(struct fpga_manager *mgr, const char *buf,
size_t count)
{
struct altera_cvp_conf *conf = mgr->priv;
const u32 *data;
size_t done, remaining;
int status = 0;
u32 mask;
data = (u32 *)buf;
remaining = count;
done = 0;
while (remaining >= 4) {
conf->write_data(conf, *data++);
done += 4;
remaining -= 4;
if (altera_cvp_chkcfg && !(done % SZ_4K)) {
status = altera_cvp_chk_error(mgr, done);
if (status < 0)
return status;
}
}
mask = BIT(remaining * 8) - 1;
if (mask)
conf->write_data(conf, *data & mask);
if (altera_cvp_chkcfg)
status = altera_cvp_chk_error(mgr, count);
return status;
}
static int altera_cvp_write_complete(struct fpga_manager *mgr,
struct fpga_image_info *info)
{
struct altera_cvp_conf *conf = mgr->priv;
struct pci_dev *pdev = conf->pci_dev;
int ret;
u32 mask;
u32 val;
ret = altera_cvp_teardown(mgr, info);
if (ret)
return ret;
pci_read_config_dword(pdev, VSE_UNCOR_ERR_STATUS, &val);
if (val & VSE_UNCOR_ERR_CVP_CFG_ERR) {
dev_err(&mgr->dev, "detected CVP_CONFIG_ERROR_LATCHED!\n");
return -EPROTO;
}
pci_read_config_dword(pdev, VSE_CVP_MODE_CTRL, &val);
val &= ~VSE_CVP_MODE_CTRL_HIP_CLK_SEL;
val &= ~VSE_CVP_MODE_CTRL_CVP_MODE;
pci_write_config_dword(pdev, VSE_CVP_MODE_CTRL, val);
mask = VSE_CVP_STATUS_PLD_CLK_IN_USE | VSE_CVP_STATUS_USERMODE;
ret = altera_cvp_wait_status(conf, mask, mask, TIMEOUT_US);
if (ret)
dev_err(&mgr->dev, "PLD_CLK_IN_USE|USERMODE timeout\n");
return ret;
}
static ssize_t chkcfg_show(struct device_driver *dev, char *buf)
{
return snprintf(buf, 3, "%d\n", altera_cvp_chkcfg);
}
static ssize_t chkcfg_store(struct device_driver *drv, const char *buf,
size_t count)
{
int ret;
ret = kstrtobool(buf, &altera_cvp_chkcfg);
if (ret)
return ret;
return count;
}
static int altera_cvp_probe(struct pci_dev *pdev,
const struct pci_device_id *dev_id)
{
struct altera_cvp_conf *conf;
u16 cmd, val;
int ret;
pci_read_config_word(pdev, VSE_PCIE_EXT_CAP_ID, &val);
if (val != VSE_PCIE_EXT_CAP_ID_VAL) {
dev_err(&pdev->dev, "Wrong EXT_CAP_ID value 0x%x\n", val);
return -ENODEV;
}
conf = devm_kzalloc(&pdev->dev, sizeof(*conf), GFP_KERNEL);
if (!conf)
return -ENOMEM;
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
if (!(cmd & PCI_COMMAND_MEMORY)) {
cmd |= PCI_COMMAND_MEMORY;
pci_write_config_word(pdev, PCI_COMMAND, cmd);
}
ret = pci_request_region(pdev, CVP_BAR, "CVP");
if (ret) {
dev_err(&pdev->dev, "Requesting CVP BAR region failed\n");
goto err_disable;
}
conf->pci_dev = pdev;
conf->write_data = altera_cvp_write_data_iomem;
conf->map = pci_iomap(pdev, CVP_BAR, 0);
if (!conf->map) {
dev_warn(&pdev->dev, "Mapping CVP BAR failed\n");
conf->write_data = altera_cvp_write_data_config;
}
snprintf(conf->mgr_name, sizeof(conf->mgr_name), "%s @%s",
ALTERA_CVP_MGR_NAME, pci_name(pdev));
ret = fpga_mgr_register(&pdev->dev, conf->mgr_name,
&altera_cvp_ops, conf);
if (ret)
goto err_unmap;
ret = driver_create_file(&altera_cvp_driver.driver,
&driver_attr_chkcfg);
if (ret) {
dev_err(&pdev->dev, "Can't create sysfs chkcfg file\n");
fpga_mgr_unregister(&pdev->dev);
goto err_unmap;
}
return 0;
err_unmap:
pci_iounmap(pdev, conf->map);
pci_release_region(pdev, CVP_BAR);
err_disable:
cmd &= ~PCI_COMMAND_MEMORY;
pci_write_config_word(pdev, PCI_COMMAND, cmd);
return ret;
}
static void altera_cvp_remove(struct pci_dev *pdev)
{
struct fpga_manager *mgr = pci_get_drvdata(pdev);
struct altera_cvp_conf *conf = mgr->priv;
u16 cmd;
driver_remove_file(&altera_cvp_driver.driver, &driver_attr_chkcfg);
fpga_mgr_unregister(&pdev->dev);
pci_iounmap(pdev, conf->map);
pci_release_region(pdev, CVP_BAR);
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
cmd &= ~PCI_COMMAND_MEMORY;
pci_write_config_word(pdev, PCI_COMMAND, cmd);
}
