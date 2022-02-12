static u32 asle_set_backlight(struct drm_device *dev, u32 bclp)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct opregion_asle *asle = dev_priv->opregion.asle;
struct backlight_device *bd = dev_priv->backlight_device;
DRM_DEBUG_DRIVER("asle set backlight %x\n", bclp);
if (!(bclp & ASLE_BCLP_VALID))
return ASLE_BACKLIGHT_FAILED;
if (bd == NULL)
return ASLE_BACKLIGHT_FAILED;
bclp &= ASLE_BCLP_MSK;
if (bclp > 255)
return ASLE_BACKLIGHT_FAILED;
if (config_enabled(CONFIG_BACKLIGHT_CLASS_DEVICE)) {
int max = bd->props.max_brightness;
gma_backlight_set(dev, bclp * max / 255);
}
asle->cblv = (bclp * 0x64) / 0xff | ASLE_CBLV_VALID;
return 0;
}
static void psb_intel_opregion_asle_work(struct work_struct *work)
{
struct psb_intel_opregion *opregion =
container_of(work, struct psb_intel_opregion, asle_work);
struct drm_psb_private *dev_priv =
container_of(opregion, struct drm_psb_private, opregion);
struct opregion_asle *asle = opregion->asle;
u32 asle_stat = 0;
u32 asle_req;
if (!asle)
return;
asle_req = asle->aslc & ASLE_REQ_MSK;
if (!asle_req) {
DRM_DEBUG_DRIVER("non asle set request??\n");
return;
}
if (asle_req & ASLE_SET_BACKLIGHT)
asle_stat |= asle_set_backlight(dev_priv->dev, asle->bclp);
asle->aslc = asle_stat;
}
void psb_intel_opregion_asle_intr(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
if (dev_priv->opregion.asle)
schedule_work(&dev_priv->opregion.asle_work);
}
void psb_intel_opregion_enable_asle(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct opregion_asle *asle = dev_priv->opregion.asle;
if (asle && system_opregion ) {
psb_enable_pipestat(dev_priv, 0, PIPE_LEGACY_BLC_EVENT_ENABLE);
psb_enable_pipestat(dev_priv, 1, PIPE_LEGACY_BLC_EVENT_ENABLE);
asle->tche = ASLE_ALS_EN | ASLE_BLC_EN | ASLE_PFIT_EN
| ASLE_PFMB_EN;
asle->ardy = 1;
}
}
static int psb_intel_opregion_video_event(struct notifier_block *nb,
unsigned long val, void *data)
{
struct opregion_acpi *acpi;
if (!system_opregion)
return NOTIFY_DONE;
acpi = system_opregion->acpi;
acpi->csts = 0;
return NOTIFY_OK;
}
void psb_intel_opregion_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_intel_opregion *opregion = &dev_priv->opregion;
if (!opregion->header)
return;
if (opregion->acpi) {
opregion->acpi->csts = 0;
opregion->acpi->drdy = 1;
system_opregion = opregion;
register_acpi_notifier(&psb_intel_opregion_notifier);
}
}
void psb_intel_opregion_fini(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_intel_opregion *opregion = &dev_priv->opregion;
if (!opregion->header)
return;
if (opregion->acpi) {
opregion->acpi->drdy = 0;
system_opregion = NULL;
unregister_acpi_notifier(&psb_intel_opregion_notifier);
}
cancel_work_sync(&opregion->asle_work);
iounmap(opregion->header);
opregion->header = NULL;
opregion->acpi = NULL;
opregion->swsci = NULL;
opregion->asle = NULL;
opregion->vbt = NULL;
}
int psb_intel_opregion_setup(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
struct psb_intel_opregion *opregion = &dev_priv->opregion;
u32 opregion_phy, mboxes;
void __iomem *base;
int err = 0;
pci_read_config_dword(dev->pdev, PCI_ASLS, &opregion_phy);
if (opregion_phy == 0) {
DRM_DEBUG_DRIVER("ACPI Opregion not supported\n");
return -ENOTSUPP;
}
INIT_WORK(&opregion->asle_work, psb_intel_opregion_asle_work);
DRM_DEBUG("OpRegion detected at 0x%8x\n", opregion_phy);
base = acpi_os_ioremap(opregion_phy, 8*1024);
if (!base)
return -ENOMEM;
if (memcmp(base, OPREGION_SIGNATURE, 16)) {
DRM_DEBUG_DRIVER("opregion signature mismatch\n");
err = -EINVAL;
goto err_out;
}
opregion->header = base;
opregion->vbt = base + OPREGION_VBT_OFFSET;
opregion->lid_state = base + ACPI_CLID;
mboxes = opregion->header->mboxes;
if (mboxes & MBOX_ACPI) {
DRM_DEBUG_DRIVER("Public ACPI methods supported\n");
opregion->acpi = base + OPREGION_ACPI_OFFSET;
}
if (mboxes & MBOX_ASLE) {
DRM_DEBUG_DRIVER("ASLE supported\n");
opregion->asle = base + OPREGION_ASLE_OFFSET;
}
return 0;
err_out:
iounmap(base);
return err;
}
