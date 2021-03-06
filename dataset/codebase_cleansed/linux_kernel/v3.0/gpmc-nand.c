static int omap2_nand_gpmc_retime(void)
{
struct gpmc_timings t;
int err;
if (!gpmc_nand_data->gpmc_t)
return 0;
memset(&t, 0, sizeof(t));
t.sync_clk = gpmc_nand_data->gpmc_t->sync_clk;
t.cs_on = gpmc_round_ns_to_ticks(gpmc_nand_data->gpmc_t->cs_on);
t.adv_on = gpmc_round_ns_to_ticks(gpmc_nand_data->gpmc_t->adv_on);
t.adv_rd_off = gpmc_round_ns_to_ticks(
gpmc_nand_data->gpmc_t->adv_rd_off);
t.oe_on = t.adv_on;
t.access = gpmc_round_ns_to_ticks(gpmc_nand_data->gpmc_t->access);
t.oe_off = gpmc_round_ns_to_ticks(gpmc_nand_data->gpmc_t->oe_off);
t.cs_rd_off = gpmc_round_ns_to_ticks(gpmc_nand_data->gpmc_t->cs_rd_off);
t.rd_cycle = gpmc_round_ns_to_ticks(gpmc_nand_data->gpmc_t->rd_cycle);
t.adv_wr_off = gpmc_round_ns_to_ticks(
gpmc_nand_data->gpmc_t->adv_wr_off);
t.we_on = t.oe_on;
if (cpu_is_omap34xx()) {
t.wr_data_mux_bus = gpmc_round_ns_to_ticks(
gpmc_nand_data->gpmc_t->wr_data_mux_bus);
t.wr_access = gpmc_round_ns_to_ticks(
gpmc_nand_data->gpmc_t->wr_access);
}
t.we_off = gpmc_round_ns_to_ticks(gpmc_nand_data->gpmc_t->we_off);
t.cs_wr_off = gpmc_round_ns_to_ticks(gpmc_nand_data->gpmc_t->cs_wr_off);
t.wr_cycle = gpmc_round_ns_to_ticks(gpmc_nand_data->gpmc_t->wr_cycle);
if (gpmc_nand_data->devsize == NAND_BUSWIDTH_16)
gpmc_cs_configure(gpmc_nand_data->cs, GPMC_CONFIG_DEV_SIZE, 1);
else
gpmc_cs_configure(gpmc_nand_data->cs, GPMC_CONFIG_DEV_SIZE, 0);
gpmc_cs_configure(gpmc_nand_data->cs,
GPMC_CONFIG_DEV_TYPE, GPMC_DEVICETYPE_NAND);
err = gpmc_cs_set_timings(gpmc_nand_data->cs, &t);
if (err)
return err;
return 0;
}
int __init gpmc_nand_init(struct omap_nand_platform_data *_nand_data)
{
int err = 0;
struct device *dev = &gpmc_nand_device.dev;
gpmc_nand_data = _nand_data;
gpmc_nand_data->nand_setup = omap2_nand_gpmc_retime;
gpmc_nand_device.dev.platform_data = gpmc_nand_data;
err = gpmc_cs_request(gpmc_nand_data->cs, NAND_IO_SIZE,
&gpmc_nand_data->phys_base);
if (err < 0) {
dev_err(dev, "Cannot request GPMC CS\n");
return err;
}
err = omap2_nand_gpmc_retime();
if (err < 0) {
dev_err(dev, "Unable to set gpmc timings: %d\n", err);
return err;
}
if (gpmc_nand_data->dev_ready) {
gpmc_cs_configure(gpmc_nand_data->cs, GPMC_CONFIG_RDY_BSY, 1);
}
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
