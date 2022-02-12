static unsigned long sdrc_get_fclk_period(long rate)
{
return 1000000000 / rate;
}
static unsigned int sdrc_ps_to_ticks(unsigned int time_ps, long rate)
{
unsigned long tick_ps;
tick_ps = sdrc_get_fclk_period(rate);
return (time_ps + tick_ps - 1) / tick_ps;
}
static int sdrc_timings(int id, long rate,
const struct sdram_timings *memory_timings)
{
u32 ticks_per_ms;
u32 rfr, l;
u32 actim_ctrla = 0, actim_ctrlb = 0;
u32 rfr_ctrl;
int err = 0;
long l3_rate = rate / 1000;
SDRC_SET_ONE_PS(&actim_ctrla, 0, 4, tDAL, l3_rate);
SDRC_SET_ONE_PS(&actim_ctrla, 6, 8, tDPL, l3_rate);
SDRC_SET_ONE_PS(&actim_ctrla, 9, 11, tRRD, l3_rate);
SDRC_SET_ONE_PS(&actim_ctrla, 12, 14, tRCD, l3_rate);
SDRC_SET_ONE_PS(&actim_ctrla, 15, 17, tRP, l3_rate);
SDRC_SET_ONE_PS(&actim_ctrla, 18, 21, tRAS, l3_rate);
SDRC_SET_ONE_PS(&actim_ctrla, 22, 26, tRC, l3_rate);
SDRC_SET_ONE_PS(&actim_ctrla, 27, 31, tRFC, l3_rate);
SDRC_SET_ONE_PS(&actim_ctrlb, 0, 7, tXSR, l3_rate);
SDRC_SET_ONE(&actim_ctrlb, 8, 10, tXP, l3_rate);
SDRC_SET_ONE(&actim_ctrlb, 12, 14, tCKE, l3_rate);
SDRC_SET_ONE(&actim_ctrlb, 16, 17, tWTR, l3_rate);
ticks_per_ms = l3_rate;
rfr = memory_timings[0].tREF * ticks_per_ms / 1000000;
if (rfr > 65535 + 50)
rfr = 65535;
else
rfr -= 50;
#ifdef DEBUG
printk(KERN_INFO "SDRC tREF: %i ticks\n", rfr);
#endif
l = rfr << 8;
rfr_ctrl = l | 0x1;
nokia_sdrc_params[id].rate = rate;
nokia_sdrc_params[id].actim_ctrla = actim_ctrla;
nokia_sdrc_params[id].actim_ctrlb = actim_ctrlb;
nokia_sdrc_params[id].rfr_ctrl = rfr_ctrl;
nokia_sdrc_params[id].mr = 0x32;
nokia_sdrc_params[id + 1].rate = 0;
return err;
}
struct omap_sdrc_params *nokia_get_sdram_timings(void)
{
int err = 0;
int i;
for (i = 0; i < ARRAY_SIZE(nokia_timings); i++) {
err |= sdrc_timings(i, nokia_timings[i].rate,
nokia_timings[i].data);
if (err)
pr_err("%s: error with rate %ld: %d\n", __func__,
nokia_timings[i].rate, err);
}
return err ? NULL : nokia_sdrc_params;
}
