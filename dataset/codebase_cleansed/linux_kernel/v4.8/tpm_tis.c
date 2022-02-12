static inline struct tpm_tis_tcg_phy *to_tpm_tis_tcg_phy(struct tpm_tis_data *data)
{
return container_of(data, struct tpm_tis_tcg_phy, priv);
}
static int has_hid(struct acpi_device *dev, const char *hid)
{
struct acpi_hardware_id *id;
list_for_each_entry(id, &dev->pnp.ids, list)
if (!strcmp(hid, id->id))
return 1;
return 0;
}
static inline int is_itpm(struct acpi_device *dev)
{
return has_hid(dev, "INTC0102");
}
static inline int is_itpm(struct acpi_device *dev)
{
return 0;
}
static int tpm_tcg_read_bytes(struct tpm_tis_data *data, u32 addr, u16 len,
u8 *result)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
while (len--)
*result++ = ioread8(phy->iobase + addr);
return 0;
}
static int tpm_tcg_write_bytes(struct tpm_tis_data *data, u32 addr, u16 len,
u8 *value)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
while (len--)
iowrite8(*value++, phy->iobase + addr);
return 0;
}
static int tpm_tcg_read16(struct tpm_tis_data *data, u32 addr, u16 *result)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
*result = ioread16(phy->iobase + addr);
return 0;
}
static int tpm_tcg_read32(struct tpm_tis_data *data, u32 addr, u32 *result)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
*result = ioread32(phy->iobase + addr);
return 0;
}
static int tpm_tcg_write32(struct tpm_tis_data *data, u32 addr, u32 value)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
iowrite32(value, phy->iobase + addr);
return 0;
}
static int tpm_tis_init(struct device *dev, struct tpm_info *tpm_info,
acpi_handle acpi_dev_handle)
{
struct tpm_tis_tcg_phy *phy;
int irq = -1;
phy = devm_kzalloc(dev, sizeof(struct tpm_tis_tcg_phy), GFP_KERNEL);
if (phy == NULL)
return -ENOMEM;
phy->iobase = devm_ioremap_resource(dev, &tpm_info->res);
if (IS_ERR(phy->iobase))
return PTR_ERR(phy->iobase);
if (interrupts)
irq = tpm_info->irq;
if (itpm)
phy->priv.flags |= TPM_TIS_ITPM_POSSIBLE;
return tpm_tis_core_init(dev, &phy->priv, irq, &tpm_tcg,
acpi_dev_handle);
}
static int tpm_tis_pnp_init(struct pnp_dev *pnp_dev,
const struct pnp_device_id *pnp_id)
{
struct tpm_info tpm_info = {};
acpi_handle acpi_dev_handle = NULL;
struct resource *res;
res = pnp_get_resource(pnp_dev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
tpm_info.res = *res;
if (pnp_irq_valid(pnp_dev, 0))
tpm_info.irq = pnp_irq(pnp_dev, 0);
else
tpm_info.irq = -1;
if (pnp_acpi_device(pnp_dev)) {
if (is_itpm(pnp_acpi_device(pnp_dev)))
itpm = true;
acpi_dev_handle = ACPI_HANDLE(&pnp_dev->dev);
}
return tpm_tis_init(&pnp_dev->dev, &tpm_info, acpi_dev_handle);
}
static void tpm_tis_pnp_remove(struct pnp_dev *dev)
{
struct tpm_chip *chip = pnp_get_drvdata(dev);
tpm_chip_unregister(chip);
tpm_tis_remove(chip);
}
static int tpm_check_resource(struct acpi_resource *ares, void *data)
{
struct tpm_info *tpm_info = (struct tpm_info *) data;
struct resource res;
if (acpi_dev_resource_interrupt(ares, 0, &res))
tpm_info->irq = res.start;
else if (acpi_dev_resource_memory(ares, &res)) {
tpm_info->res = res;
tpm_info->res.name = NULL;
}
return 1;
}
static int tpm_tis_acpi_init(struct acpi_device *acpi_dev)
{
struct acpi_table_tpm2 *tbl;
acpi_status st;
struct list_head resources;
struct tpm_info tpm_info = {};
int ret;
st = acpi_get_table(ACPI_SIG_TPM2, 1,
(struct acpi_table_header **) &tbl);
if (ACPI_FAILURE(st) || tbl->header.length < sizeof(*tbl)) {
dev_err(&acpi_dev->dev,
FW_BUG "failed to get TPM2 ACPI table\n");
return -EINVAL;
}
if (tbl->start_method != ACPI_TPM2_MEMORY_MAPPED)
return -ENODEV;
INIT_LIST_HEAD(&resources);
tpm_info.irq = -1;
ret = acpi_dev_get_resources(acpi_dev, &resources, tpm_check_resource,
&tpm_info);
if (ret < 0)
return ret;
acpi_dev_free_resource_list(&resources);
if (resource_type(&tpm_info.res) != IORESOURCE_MEM) {
dev_err(&acpi_dev->dev,
FW_BUG "TPM2 ACPI table does not define a memory resource\n");
return -EINVAL;
}
if (is_itpm(acpi_dev))
itpm = true;
return tpm_tis_init(&acpi_dev->dev, &tpm_info, acpi_dev->handle);
}
static int tpm_tis_acpi_remove(struct acpi_device *dev)
{
struct tpm_chip *chip = dev_get_drvdata(&dev->dev);
tpm_chip_unregister(chip);
tpm_tis_remove(chip);
return 0;
}
static int tpm_tis_plat_probe(struct platform_device *pdev)
{
struct tpm_info tpm_info = {};
struct resource *res;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (res == NULL) {
dev_err(&pdev->dev, "no memory resource defined\n");
return -ENODEV;
}
tpm_info.res = *res;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (res) {
tpm_info.irq = res->start;
} else {
if (pdev == force_pdev)
tpm_info.irq = -1;
else
tpm_info.irq = 0;
}
return tpm_tis_init(&pdev->dev, &tpm_info, NULL);
}
static int tpm_tis_plat_remove(struct platform_device *pdev)
{
struct tpm_chip *chip = dev_get_drvdata(&pdev->dev);
tpm_chip_unregister(chip);
tpm_tis_remove(chip);
return 0;
}
static int tpm_tis_force_device(void)
{
struct platform_device *pdev;
static const struct resource x86_resources[] = {
{
.start = 0xFED40000,
.end = 0xFED40000 + TIS_MEM_LEN - 1,
.flags = IORESOURCE_MEM,
},
};
if (!force)
return 0;
pdev = platform_device_register_simple("tpm_tis", -1, x86_resources,
ARRAY_SIZE(x86_resources));
if (IS_ERR(pdev))
return PTR_ERR(pdev);
force_pdev = pdev;
return 0;
}
static int __init init_tis(void)
{
int rc;
rc = tpm_tis_force_device();
if (rc)
goto err_force;
rc = platform_driver_register(&tis_drv);
if (rc)
goto err_platform;
#ifdef CONFIG_ACPI
rc = acpi_bus_register_driver(&tis_acpi_driver);
if (rc)
goto err_acpi;
#endif
if (IS_ENABLED(CONFIG_PNP)) {
rc = pnp_register_driver(&tis_pnp_driver);
if (rc)
goto err_pnp;
}
return 0;
err_pnp:
#ifdef CONFIG_ACPI
acpi_bus_unregister_driver(&tis_acpi_driver);
err_acpi:
#endif
platform_device_unregister(force_pdev);
err_platform:
if (force_pdev)
platform_device_unregister(force_pdev);
err_force:
return rc;
}
static void __exit cleanup_tis(void)
{
pnp_unregister_driver(&tis_pnp_driver);
#ifdef CONFIG_ACPI
acpi_bus_unregister_driver(&tis_acpi_driver);
#endif
platform_driver_unregister(&tis_drv);
if (force_pdev)
platform_device_unregister(force_pdev);
}
