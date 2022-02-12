static bool gpmc_hwecc_bch_capable(enum omap_ecc ecc_opt)
{
if (soc_is_am33xx() || soc_is_am43xx() || cpu_is_omap44xx() ||
soc_is_omap54xx() || soc_is_dra7xx())
return 1;
if (ecc_opt == OMAP_ECC_BCH4_CODE_HW_DETECTION_SW ||
ecc_opt == OMAP_ECC_BCH8_CODE_HW_DETECTION_SW) {
if (cpu_is_omap24xx())
return 0;
else if (cpu_is_omap3630() && (GET_OMAP_REVISION() == 0))
return 0;
else
return 1;
}
if ((cpu_is_omap34xx() || cpu_is_omap3630()) &&
((ecc_opt == OMAP_ECC_BCH4_CODE_HW) ||
(ecc_opt == OMAP_ECC_BCH8_CODE_HW)))
return 0;
if (ecc_opt == OMAP_ECC_HAM1_CODE_HW ||
ecc_opt == OMAP_ECC_HAM1_CODE_SW)
return 1;
else
return 0;
}
static void gpmc_set_legacy(struct omap_nand_platform_data *gpmc_nand_data,
struct gpmc_settings *s)
{
if (gpmc_nand_data->dev_ready) {
s->wait_on_read = true;
s->wait_on_write = true;
}
if (gpmc_nand_data->devsize == NAND_BUSWIDTH_16)
s->device_width = GPMC_DEVWIDTH_16BIT;
else
s->device_width = GPMC_DEVWIDTH_8BIT;
}
int gpmc_nand_init(struct omap_nand_platform_data *gpmc_nand_data,
struct gpmc_timings *gpmc_t)
{
int err = 0;
struct gpmc_settings s;
struct platform_device *pdev;
struct resource gpmc_nand_res[] = {
{ .flags = IORESOURCE_MEM, },
{ .flags = IORESOURCE_IRQ, },
{ .flags = IORESOURCE_IRQ, },
};
BUG_ON(gpmc_nand_data->cs >= GPMC_CS_NUM);
err = gpmc_cs_request(gpmc_nand_data->cs, NAND_IO_SIZE,
(unsigned long *)&gpmc_nand_res[0].start);
if (err < 0) {
pr_err("omap2-gpmc: Cannot request GPMC CS %d, error %d\n",
gpmc_nand_data->cs, err);
return err;
}
gpmc_nand_res[0].end = gpmc_nand_res[0].start + NAND_IO_SIZE - 1;
gpmc_nand_res[1].start = gpmc_get_client_irq(GPMC_IRQ_FIFOEVENTENABLE);
gpmc_nand_res[2].start = gpmc_get_client_irq(GPMC_IRQ_COUNT_EVENT);
memset(&s, 0, sizeof(struct gpmc_settings));
gpmc_set_legacy(gpmc_nand_data, &s);
s.device_nand = true;
if (gpmc_t) {
err = gpmc_cs_set_timings(gpmc_nand_data->cs, gpmc_t, &s);
if (err < 0) {
pr_err("omap2-gpmc: Unable to set gpmc timings: %d\n",
err);
return err;
}
}
err = gpmc_cs_program_settings(gpmc_nand_data->cs, &s);
if (err < 0)
goto out_free_cs;
err = gpmc_configure(GPMC_CONFIG_WP, 0);
if (err < 0)
goto out_free_cs;
if (!gpmc_hwecc_bch_capable(gpmc_nand_data->ecc_opt)) {
pr_err("omap2-nand: Unsupported NAND ECC scheme selected\n");
err = -EINVAL;
goto out_free_cs;
}
pdev = platform_device_alloc("omap2-nand", gpmc_nand_data->cs);
if (pdev) {
err = platform_device_add_resources(pdev, gpmc_nand_res,
ARRAY_SIZE(gpmc_nand_res));
if (!err)
pdev->dev.platform_data = gpmc_nand_data;
} else {
err = -ENOMEM;
}
if (err)
goto out_free_pdev;
err = platform_device_add(pdev);
if (err) {
dev_err(&pdev->dev, "Unable to register NAND device\n");
goto out_free_pdev;
}
return 0;
out_free_pdev:
platform_device_put(pdev);
out_free_cs:
gpmc_cs_free(gpmc_nand_data->cs);
return err;
}
