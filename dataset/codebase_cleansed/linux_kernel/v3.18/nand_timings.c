const struct nand_sdr_timings *onfi_async_timing_mode_to_sdr_timings(int mode)
{
if (mode < 0 || mode >= ARRAY_SIZE(onfi_sdr_timings))
return ERR_PTR(-EINVAL);
return &onfi_sdr_timings[mode];
}
