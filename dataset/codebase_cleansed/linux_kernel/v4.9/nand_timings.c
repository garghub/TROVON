const struct nand_sdr_timings *onfi_async_timing_mode_to_sdr_timings(int mode)
{
if (mode < 0 || mode >= ARRAY_SIZE(onfi_sdr_timings))
return ERR_PTR(-EINVAL);
return &onfi_sdr_timings[mode].timings.sdr;
}
int onfi_init_data_interface(struct nand_chip *chip,
struct nand_data_interface *iface,
enum nand_data_interface_type type,
int timing_mode)
{
if (type != NAND_SDR_IFACE)
return -EINVAL;
if (timing_mode < 0 || timing_mode >= ARRAY_SIZE(onfi_sdr_timings))
return -EINVAL;
*iface = onfi_sdr_timings[timing_mode];
return 0;
}
const struct nand_data_interface *nand_get_default_data_interface(void)
{
return &onfi_sdr_timings[0];
}
