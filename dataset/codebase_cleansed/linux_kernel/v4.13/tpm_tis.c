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
if (!dev)
return 0;
return has_hid(dev, "INTC0102");
}
static inline int is_itpm(struct acpi_device *dev)
{
return 0;
}
static int check_acpi_tpm2(struct device *dev)
{
const struct acpi_device_id *aid = acpi_match_device(tpm_acpi_tbl, dev);
struct acpi_table_tpm2 *tbl;
acpi_status st;
if (!aid || aid->driver_data != DEVICE_IS_TPM2)
return 0;
st =
acpi_get_table(ACPI_SIG_TPM2, 1, (struct acpi_table_header **)&tbl);
if (ACPI_FAILURE(st) || tbl->header.length < sizeof(*tbl)) {
dev_err(dev, FW_BUG "failed to get TPM2 ACPI table\n");
return -EINVAL;
}
if (tbl->start_method != ACPI_TPM2_MEMORY_MAPPED)
return -ENODEV;
return 0;
}
static int check_acpi_tpm2(struct device *dev)
{
return 0;
}
static inline bool is_bsw(void)
{
return ((boot_cpu_data.x86_model == INTEL_FAM6_ATOM_AIRMONT) ? 1 : 0);
}
static void tpm_platform_begin_xfer(void)
{
u32 clkrun_val;
if (!is_bsw())
return;
clkrun_val = ioread32(ilb_base_addr + LPC_CNTRL_REG_OFFSET);
clkrun_val &= ~LPC_CLKRUN_EN;
iowrite32(clkrun_val, ilb_base_addr + LPC_CNTRL_REG_OFFSET);
outb(0xCC, 0x80);
}
static void tpm_platform_end_xfer(void)
{
u32 clkrun_val;
if (!is_bsw())
return;
clkrun_val = ioread32(ilb_base_addr + LPC_CNTRL_REG_OFFSET);
clkrun_val |= LPC_CLKRUN_EN;
iowrite32(clkrun_val, ilb_base_addr + LPC_CNTRL_REG_OFFSET);
outb(0xCC, 0x80);
}
static inline bool is_bsw(void)
{
return false;
}
static void tpm_platform_begin_xfer(void)
{
}
static void tpm_platform_end_xfer(void)
{
}
static int tpm_tcg_read_bytes(struct tpm_tis_data *data, u32 addr, u16 len,
u8 *result)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
tpm_platform_begin_xfer();
while (len--)
*result++ = ioread8(phy->iobase + addr);
tpm_platform_end_xfer();
return 0;
}
static int tpm_tcg_write_bytes(struct tpm_tis_data *data, u32 addr, u16 len,
u8 *value)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
tpm_platform_begin_xfer();
while (len--)
iowrite8(*value++, phy->iobase + addr);
tpm_platform_end_xfer();
return 0;
}
static int tpm_tcg_read16(struct tpm_tis_data *data, u32 addr, u16 *result)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
tpm_platform_begin_xfer();
*result = ioread16(phy->iobase + addr);
tpm_platform_end_xfer();
return 0;
}
static int tpm_tcg_read32(struct tpm_tis_data *data, u32 addr, u32 *result)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
tpm_platform_begin_xfer();
*result = ioread32(phy->iobase + addr);
tpm_platform_end_xfer();
return 0;
}
static int tpm_tcg_write32(struct tpm_tis_data *data, u32 addr, u32 value)
{
struct tpm_tis_tcg_phy *phy = to_tpm_tis_tcg_phy(data);
tpm_platform_begin_xfer();
iowrite32(value, phy->iobase + addr);
tpm_platform_end_xfer();
return 0;
}
static int tpm_tis_init(struct device *dev, struct tpm_info *tpm_info)
{
struct tpm_tis_tcg_phy *phy;
int irq = -1;
int rc;
rc = check_acpi_tpm2(dev);
if (rc)
return rc;
phy = devm_kzalloc(dev, sizeof(struct tpm_tis_tcg_phy), GFP_KERNEL);
if (phy == NULL)
return -ENOMEM;
phy->iobase = devm_ioremap_resource(dev, &tpm_info->res);
if (IS_ERR(phy->iobase))
return PTR_ERR(phy->iobase);
if (interrupts)
irq = tpm_info->irq;
if (itpm || is_itpm(ACPI_COMPANION(dev)))
phy->priv.flags |= TPM_TIS_ITPM_WORKAROUND;
return tpm_tis_core_init(dev, &phy->priv, irq, &tpm_tcg,
ACPI_HANDLE(dev));
}
static int tpm_tis_pnp_init(struct pnp_dev *pnp_dev,
const struct pnp_device_id *pnp_id)
{
struct tpm_info tpm_info = {};
struct resource *res;
res = pnp_get_resource(pnp_dev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
tpm_info.res = *res;
if (pnp_irq_valid(pnp_dev, 0))
tpm_info.irq = pnp_irq(pnp_dev, 0);
else
tpm_info.irq = -1;
return tpm_tis_init(&pnp_dev->dev, &tpm_info);
}
static void tpm_tis_pnp_remove(struct pnp_dev *dev)
{
struct tpm_chip *chip = pnp_get_drvdata(dev);
tpm_chip_unregister(chip);
tpm_tis_remove(chip);
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
tpm_info.irq = platform_get_irq(pdev, 0);
if (tpm_info.irq <= 0) {
if (pdev != force_pdev)
tpm_info.irq = -1;
else
tpm_info.irq = 0;
}
return tpm_tis_init(&pdev->dev, &tpm_info);
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
#ifdef CONFIG_X86
if (is_bsw())
ilb_base_addr = ioremap(INTEL_LEGACY_BLK_BASE_ADDR,
ILB_REMAP_SIZE);
#endif
rc = platform_driver_register(&tis_drv);
if (rc)
goto err_platform;
if (IS_ENABLED(CONFIG_PNP)) {
rc = pnp_register_driver(&tis_pnp_driver);
if (rc)
goto err_pnp;
}
return 0;
err_pnp:
platform_driver_unregister(&tis_drv);
err_platform:
if (force_pdev)
platform_device_unregister(force_pdev);
#ifdef CONFIG_X86
if (is_bsw())
iounmap(ilb_base_addr);
#endif
err_force:
return rc;
}
static void __exit cleanup_tis(void)
{
pnp_unregister_driver(&tis_pnp_driver);
platform_driver_unregister(&tis_drv);
#ifdef CONFIG_X86
if (is_bsw())
iounmap(ilb_base_addr);
#endif
if (force_pdev)
platform_device_unregister(force_pdev);
}
