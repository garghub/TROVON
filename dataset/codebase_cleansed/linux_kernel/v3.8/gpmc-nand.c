static int omap2_nand_gpmc_retime(
struct omap_nand_platform_data *gpmc_nand_data,
struct gpmc_timings *gpmc_t)
{
struct gpmc_timings t;
int err;
memset(&t, 0, sizeof(t));
t.sync_clk = gpmc_t->sync_clk;
t.cs_on = gpmc_t->cs_on;
t.adv_on = gpmc_t->adv_on;
t.adv_rd_off = gpmc_t->adv_rd_off;
t.oe_on = t.adv_on;
t.access = gpmc_t->access;
t.oe_off = gpmc_t->oe_off;
t.cs_rd_off = gpmc_t->cs_rd_off;
t.rd_cycle = gpmc_t->rd_cycle;
t.adv_wr_off = gpmc_t->adv_wr_off;
t.we_on = t.oe_on;
if (cpu_is_omap34xx()) {
t.wr_data_mux_bus = gpmc_t->wr_data_mux_bus;
t.wr_access = gpmc_t->wr_access;
}
t.we_off = gpmc_t->we_off;
t.cs_wr_off = gpmc_t->cs_wr_off;
t.wr_cycle = gpmc_t->wr_cycle;
if (gpmc_nand_data->devsize == NAND_BUSWIDTH_16)
gpmc_cs_configure(gpmc_nand_data->cs, GPMC_CONFIG_DEV_SIZE, 1);
else
gpmc_cs_configure(gpmc_nand_data->cs, GPMC_CONFIG_DEV_SIZE, 0);
gpmc_cs_configure(gpmc_nand_data->cs,
GPMC_CONFIG_DEV_TYPE, GPMC_DEVICETYPE_NAND);
gpmc_cs_configure(gpmc_nand_data->cs, GPMC_CONFIG_WP, 0);
err = gpmc_cs_set_timings(gpmc_nand_data->cs, &t);
if (err)
return err;
return 0;
}
static bool __init gpmc_hwecc_bch_capable(enum omap_ecc ecc_opt)
{
if (!cpu_is_omap34xx()) {
pr_err("BCH ecc is not supported on this CPU\n");
return 0;
}
if ((ecc_opt == OMAP_ECC_BCH4_CODE_HW) &&
(!cpu_is_omap3630() || (GET_OMAP_REVISION() == 0))) {
pr_err("BCH 4-bit mode is not supported on this CPU\n");
return 0;
}
return 1;
}
int __init gpmc_nand_init(struct omap_nand_platform_data *gpmc_nand_data,
struct gpmc_timings *gpmc_t)
{
int err = 0;
struct device *dev = &gpmc_nand_device.dev;
gpmc_nand_device.dev.platform_data = gpmc_nand_data;
err = gpmc_cs_request(gpmc_nand_data->cs, NAND_IO_SIZE,
(unsigned long *)&gpmc_nand_resource[0].start);
if (err < 0) {
dev_err(dev, "Cannot request GPMC CS\n");
return err;
}
gpmc_nand_resource[0].end = gpmc_nand_resource[0].start +
NAND_IO_SIZE - 1;
gpmc_nand_resource[1].start =
gpmc_get_client_irq(GPMC_IRQ_FIFOEVENTENABLE);
gpmc_nand_resource[2].start =
gpmc_get_client_irq(GPMC_IRQ_COUNT_EVENT);
if (gpmc_t) {
err = omap2_nand_gpmc_retime(gpmc_nand_data, gpmc_t);
if (err < 0) {
dev_err(dev, "Unable to set gpmc timings: %d\n", err);
return err;
}
}
if (gpmc_nand_data->dev_ready) {
gpmc_cs_configure(gpmc_nand_data->cs, GPMC_CONFIG_RDY_BSY, 1);
}
gpmc_update_nand_reg(&gpmc_nand_data->reg, gpmc_nand_data->cs);
if (!gpmc_hwecc_bch_capable(gpmc_nand_data->ecc_opt))
return -EINVAL;
err = platform_device_register(&gpmc_nand_device);
if (err < 0) {
dev_err(dev, "Unable to register NAND device\n");
goto out_free_cs;
}
return 0;
out_free_cs:
gpmc_cs_free(gpmc_nand_data->cs);
return err;
}
