static inline int __reg_within_range(unsigned int r,
unsigned int start,
unsigned int end)
{
return ((r >= start) && (r <= end));
}
static struct sta2x11_mfd *sta2x11_mfd_find(struct pci_dev *pdev)
{
struct sta2x11_instance *instance;
struct sta2x11_mfd *mfd;
if (!pdev && !list_empty(&sta2x11_mfd_list)) {
pr_warning("%s: Unspecified device, "
"using first instance\n", __func__);
return list_entry(sta2x11_mfd_list.next,
struct sta2x11_mfd, list);
}
instance = sta2x11_get_instance(pdev);
if (!instance)
return NULL;
list_for_each_entry(mfd, &sta2x11_mfd_list, list) {
if (mfd->instance == instance)
return mfd;
}
return NULL;
}
static int sta2x11_mfd_add(struct pci_dev *pdev, gfp_t flags)
{
int i;
struct sta2x11_mfd *mfd = sta2x11_mfd_find(pdev);
struct sta2x11_instance *instance;
if (mfd)
return -EBUSY;
instance = sta2x11_get_instance(pdev);
if (!instance)
return -EINVAL;
mfd = kzalloc(sizeof(*mfd), flags);
if (!mfd)
return -ENOMEM;
INIT_LIST_HEAD(&mfd->list);
for (i = 0; i < ARRAY_SIZE(mfd->lock); i++)
spin_lock_init(&mfd->lock[i]);
mfd->instance = instance;
list_add(&mfd->list, &sta2x11_mfd_list);
return 0;
}
u32 __sta2x11_mfd_mask(struct pci_dev *pdev, u32 reg, u32 mask, u32 val,
enum sta2x11_mfd_plat_dev index)
{
struct sta2x11_mfd *mfd = sta2x11_mfd_find(pdev);
u32 r;
unsigned long flags;
void __iomem *regs;
if (!mfd) {
dev_warn(&pdev->dev, ": can't access sctl regs\n");
return 0;
}
regs = mfd->regs[index];
if (!regs) {
dev_warn(&pdev->dev, ": system ctl not initialized\n");
return 0;
}
spin_lock_irqsave(&mfd->lock[index], flags);
r = readl(regs + reg);
r &= ~mask;
r |= val;
if (mask)
writel(r, regs + reg);
spin_unlock_irqrestore(&mfd->lock[index], flags);
return r;
}
int sta2x11_mfd_get_regs_data(struct platform_device *dev,
enum sta2x11_mfd_plat_dev index,
void __iomem **regs,
spinlock_t **lock)
{
struct pci_dev *pdev = *(struct pci_dev **)(dev->dev.platform_data);
struct sta2x11_mfd *mfd;
if (!pdev)
return -ENODEV;
mfd = sta2x11_mfd_find(pdev);
if (!mfd)
return -ENODEV;
if (index >= sta2x11_n_mfd_plat_devs)
return -ENODEV;
*regs = mfd->regs[index];
*lock = &mfd->lock[index];
pr_debug("%s %d *regs = %p\n", __func__, __LINE__, *regs);
return *regs ? 0 : -ENODEV;
}
static void sta2x11_regmap_lock(void *__lock)
{
spinlock_t *lock = __lock;
spin_lock(lock);
}
static void sta2x11_regmap_unlock(void *__lock)
{
spinlock_t *lock = __lock;
spin_unlock(lock);
}
static void sta2x11_regmap_nolock(void *__lock)
{
}
static bool sta2x11_sctl_writeable_reg(struct device *dev, unsigned int reg)
{
return !__reg_within_range(reg, SCTL_SCPCIECSBRST, SCTL_SCRSTSTA);
}
static bool sta2x11_scr_readable_reg(struct device *dev, unsigned int reg)
{
return (reg == STA2X11_SECR_CR) ||
__reg_within_range(reg, STA2X11_SECR_FVR0, STA2X11_SECR_FVR1);
}
static bool sta2x11_scr_writeable_reg(struct device *dev, unsigned int reg)
{
return false;
}
static bool sta2x11_apbreg_readable_reg(struct device *dev, unsigned int reg)
{
if (reg >= APBREG_BSR_SARAC)
reg -= APBREG_BSR_SARAC;
switch (reg) {
case APBREG_BSR:
case APBREG_PAER:
case APBREG_PWAC:
case APBREG_PRAC:
case APBREG_PCG:
case APBREG_PUR:
case APBREG_EMU_PCG:
return true;
default:
return false;
}
}
static bool sta2x11_apbreg_writeable_reg(struct device *dev, unsigned int reg)
{
if (reg >= APBREG_BSR_SARAC)
reg -= APBREG_BSR_SARAC;
if (!sta2x11_apbreg_readable_reg(dev, reg))
return false;
return reg != APBREG_PAER;
}
static bool sta2x11_apb_soc_regs_readable_reg(struct device *dev,
unsigned int reg)
{
return reg <= PCIE_SoC_INT_ROUTER_STATUS3_REG ||
__reg_within_range(reg, DMA_IP_CTRL_REG, SPARE3_RESERVED) ||
__reg_within_range(reg, MASTER_LOCK_REG,
SYSTEM_CONFIG_STATUS_REG) ||
reg == MSP_CLK_CTRL_REG ||
__reg_within_range(reg, COMPENSATION_REG1, TEST_CTL_REG);
}
static bool sta2x11_apb_soc_regs_writeable_reg(struct device *dev,
unsigned int reg)
{
if (!sta2x11_apb_soc_regs_readable_reg(dev, reg))
return false;
switch (reg) {
case PCIE_COMMON_CLOCK_CONFIG_0_4_0:
case SYSTEM_CONFIG_STATUS_REG:
case COMPENSATION_REG1:
case PCIE_SoC_INT_ROUTER_STATUS0_REG...PCIE_SoC_INT_ROUTER_STATUS3_REG:
case PCIE_PM_STATUS_0_PORT_0_4...PCIE_PM_STATUS_7_0_EP4:
return false;
default:
return true;
}
}
static int sta2x11_mfd_platform_probe(struct platform_device *dev,
enum sta2x11_mfd_plat_dev index)
{
struct pci_dev **pdev;
struct sta2x11_mfd *mfd;
struct resource *res;
const char *name = sta2x11_mfd_names[index];
struct regmap_config *regmap_config = sta2x11_mfd_regmap_configs[index];
pdev = dev->dev.platform_data;
mfd = sta2x11_mfd_find(*pdev);
if (!mfd)
return -ENODEV;
if (!regmap_config)
return -ENODEV;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res)
return -ENOMEM;
if (!request_mem_region(res->start, resource_size(res), name))
return -EBUSY;
mfd->regs[index] = ioremap(res->start, resource_size(res));
if (!mfd->regs[index]) {
release_mem_region(res->start, resource_size(res));
return -ENOMEM;
}
regmap_config->lock_arg = &mfd->lock;
regmap_config->cache_type = REGCACHE_NONE;
mfd->regmap[index] = devm_regmap_init_mmio(&dev->dev, mfd->regs[index],
regmap_config);
WARN_ON(!mfd->regmap[index]);
return 0;
}
static int sta2x11_sctl_probe(struct platform_device *dev)
{
return sta2x11_mfd_platform_probe(dev, sta2x11_sctl);
}
static int sta2x11_apbreg_probe(struct platform_device *dev)
{
return sta2x11_mfd_platform_probe(dev, sta2x11_apbreg);
}
static int sta2x11_apb_soc_regs_probe(struct platform_device *dev)
{
return sta2x11_mfd_platform_probe(dev, sta2x11_apb_soc_regs);
}
static int sta2x11_scr_probe(struct platform_device *dev)
{
return sta2x11_mfd_platform_probe(dev, sta2x11_scr);
}
static int __init sta2x11_sctl_init(void)
{
pr_info("%s\n", __func__);
return platform_driver_register(&sta2x11_sctl_platform_driver);
}
static int __init sta2x11_apbreg_init(void)
{
pr_info("%s\n", __func__);
return platform_driver_register(&sta2x11_platform_driver);
}
static int __init sta2x11_apb_soc_regs_init(void)
{
pr_info("%s\n", __func__);
return platform_driver_register(&sta2x11_apb_soc_regs_platform_driver);
}
static int __init sta2x11_scr_init(void)
{
pr_info("%s\n", __func__);
return platform_driver_register(&sta2x11_scr_platform_driver);
}
static int sta2x11_mfd_suspend(struct pci_dev *pdev, pm_message_t state)
{
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
return 0;
}
static int sta2x11_mfd_resume(struct pci_dev *pdev)
{
int err;
pci_set_power_state(pdev, 0);
err = pci_enable_device(pdev);
if (err)
return err;
pci_restore_state(pdev);
return 0;
}
static void sta2x11_mfd_setup(struct pci_dev *pdev,
struct sta2x11_mfd_setup_data *sd)
{
int i, j;
for (i = 0; i < ARRAY_SIZE(sd->bars); i++)
for (j = 0; j < sd->bars[i].ncells; j++) {
sd->bars[i].cells[j].pdata_size = sizeof(pdev);
sd->bars[i].cells[j].platform_data = &pdev;
}
}
static int sta2x11_mfd_probe(struct pci_dev *pdev,
const struct pci_device_id *pci_id)
{
int err, i;
struct sta2x11_mfd_setup_data *setup_data;
dev_info(&pdev->dev, "%s\n", __func__);
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "Can't enable device.\n");
return err;
}
err = pci_enable_msi(pdev);
if (err)
dev_info(&pdev->dev, "Enable msi failed\n");
setup_data = pci_id->device == PCI_DEVICE_ID_STMICRO_GPIO ?
&mfd_setup_data[STA2X11_MFD0] :
&mfd_setup_data[STA2X11_MFD1];
sta2x11_mfd_setup(pdev, setup_data);
if (!sta2x11_mfd_find(pdev))
sta2x11_mfd_add(pdev, GFP_ATOMIC);
for (i = 0; i < 2; i++) {
err = mfd_add_devices(&pdev->dev, -1,
setup_data->bars[i].cells,
setup_data->bars[i].ncells,
&pdev->resource[i],
0, NULL);
if (err) {
dev_err(&pdev->dev,
"mfd_add_devices[%d] failed: %d\n", i, err);
goto err_disable;
}
}
return 0;
err_disable:
mfd_remove_devices(&pdev->dev);
pci_disable_device(pdev);
pci_disable_msi(pdev);
return err;
}
static int __init sta2x11_mfd_init(void)
{
pr_info("%s\n", __func__);
return pci_register_driver(&sta2x11_mfd_driver);
}
