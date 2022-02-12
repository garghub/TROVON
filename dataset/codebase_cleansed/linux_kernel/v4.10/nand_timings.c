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
if (chip->onfi_version) {
struct nand_onfi_params *params = &chip->onfi_params;
struct nand_sdr_timings *timings = &iface->timings.sdr;
timings->tPROG_max = 1000000UL * le16_to_cpu(params->t_prog);
timings->tBERS_max = 1000000UL * le16_to_cpu(params->t_bers);
timings->tR_max = 1000000UL * le16_to_cpu(params->t_r);
timings->tCCS_min = 1000UL * le16_to_cpu(params->t_ccs);
}
return 0;
}
const struct nand_data_interface *nand_get_default_data_interface(void)
{
return &onfi_sdr_timings[0];
}
