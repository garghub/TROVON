void atmel_smc_cs_conf_init(struct atmel_smc_cs_conf *conf)
{
memset(conf, 0, sizeof(*conf));
}
static int atmel_smc_cs_encode_ncycles(unsigned int ncycles,
unsigned int msbpos,
unsigned int msbwidth,
unsigned int msbfactor,
unsigned int *encodedval)
{
unsigned int lsbmask = GENMASK(msbpos - 1, 0);
unsigned int msbmask = GENMASK(msbwidth - 1, 0);
unsigned int msb, lsb;
int ret = 0;
msb = ncycles / msbfactor;
lsb = ncycles % msbfactor;
if (lsb > lsbmask) {
lsb = 0;
msb++;
}
if (msb > msbmask) {
msb = msbmask;
lsb = lsbmask;
ret = -ERANGE;
}
*encodedval = (msb << msbpos) | lsb;
return ret;
}
int atmel_smc_cs_conf_set_timing(struct atmel_smc_cs_conf *conf,
unsigned int shift, unsigned int ncycles)
{
unsigned int val;
int ret;
if (shift != ATMEL_HSMC_TIMINGS_TCLR_SHIFT &&
shift != ATMEL_HSMC_TIMINGS_TADL_SHIFT &&
shift != ATMEL_HSMC_TIMINGS_TAR_SHIFT &&
shift != ATMEL_HSMC_TIMINGS_TRR_SHIFT &&
shift != ATMEL_HSMC_TIMINGS_TWB_SHIFT)
return -EINVAL;
ret = atmel_smc_cs_encode_ncycles(ncycles, 3, 1, 64, &val);
conf->timings &= ~GENMASK(shift + 3, shift);
conf->timings |= val << shift;
return ret;
}
int atmel_smc_cs_conf_set_setup(struct atmel_smc_cs_conf *conf,
unsigned int shift, unsigned int ncycles)
{
unsigned int val;
int ret;
if (shift != ATMEL_SMC_NWE_SHIFT && shift != ATMEL_SMC_NCS_WR_SHIFT &&
shift != ATMEL_SMC_NRD_SHIFT && shift != ATMEL_SMC_NCS_RD_SHIFT)
return -EINVAL;
ret = atmel_smc_cs_encode_ncycles(ncycles, 5, 1, 128, &val);
conf->setup &= ~GENMASK(shift + 7, shift);
conf->setup |= val << shift;
return ret;
}
int atmel_smc_cs_conf_set_pulse(struct atmel_smc_cs_conf *conf,
unsigned int shift, unsigned int ncycles)
{
unsigned int val;
int ret;
if (shift != ATMEL_SMC_NWE_SHIFT && shift != ATMEL_SMC_NCS_WR_SHIFT &&
shift != ATMEL_SMC_NRD_SHIFT && shift != ATMEL_SMC_NCS_RD_SHIFT)
return -EINVAL;
ret = atmel_smc_cs_encode_ncycles(ncycles, 6, 1, 256, &val);
conf->pulse &= ~GENMASK(shift + 7, shift);
conf->pulse |= val << shift;
return ret;
}
int atmel_smc_cs_conf_set_cycle(struct atmel_smc_cs_conf *conf,
unsigned int shift, unsigned int ncycles)
{
unsigned int val;
int ret;
if (shift != ATMEL_SMC_NWE_SHIFT && shift != ATMEL_SMC_NRD_SHIFT)
return -EINVAL;
ret = atmel_smc_cs_encode_ncycles(ncycles, 7, 2, 256, &val);
conf->cycle &= ~GENMASK(shift + 15, shift);
conf->cycle |= val << shift;
return ret;
}
void atmel_smc_cs_conf_apply(struct regmap *regmap, int cs,
const struct atmel_smc_cs_conf *conf)
{
regmap_write(regmap, ATMEL_SMC_SETUP(cs), conf->setup);
regmap_write(regmap, ATMEL_SMC_PULSE(cs), conf->pulse);
regmap_write(regmap, ATMEL_SMC_CYCLE(cs), conf->cycle);
regmap_write(regmap, ATMEL_SMC_MODE(cs), conf->mode);
}
void atmel_hsmc_cs_conf_apply(struct regmap *regmap,
const struct atmel_hsmc_reg_layout *layout,
int cs, const struct atmel_smc_cs_conf *conf)
{
regmap_write(regmap, ATMEL_HSMC_SETUP(layout, cs), conf->setup);
regmap_write(regmap, ATMEL_HSMC_PULSE(layout, cs), conf->pulse);
regmap_write(regmap, ATMEL_HSMC_CYCLE(layout, cs), conf->cycle);
regmap_write(regmap, ATMEL_HSMC_TIMINGS(layout, cs), conf->timings);
regmap_write(regmap, ATMEL_HSMC_MODE(layout, cs), conf->mode);
}
void atmel_smc_cs_conf_get(struct regmap *regmap, int cs,
struct atmel_smc_cs_conf *conf)
{
regmap_read(regmap, ATMEL_SMC_SETUP(cs), &conf->setup);
regmap_read(regmap, ATMEL_SMC_PULSE(cs), &conf->pulse);
regmap_read(regmap, ATMEL_SMC_CYCLE(cs), &conf->cycle);
regmap_read(regmap, ATMEL_SMC_MODE(cs), &conf->mode);
}
void atmel_hsmc_cs_conf_get(struct regmap *regmap,
const struct atmel_hsmc_reg_layout *layout,
int cs, struct atmel_smc_cs_conf *conf)
{
regmap_read(regmap, ATMEL_HSMC_SETUP(layout, cs), &conf->setup);
regmap_read(regmap, ATMEL_HSMC_PULSE(layout, cs), &conf->pulse);
regmap_read(regmap, ATMEL_HSMC_CYCLE(layout, cs), &conf->cycle);
regmap_read(regmap, ATMEL_HSMC_TIMINGS(layout, cs), &conf->timings);
regmap_read(regmap, ATMEL_HSMC_MODE(layout, cs), &conf->mode);
}
const struct atmel_hsmc_reg_layout *
atmel_hsmc_get_reg_layout(struct device_node *np)
{
const struct of_device_id *match;
match = of_match_node(atmel_smc_ids, np);
return match ? match->data : ERR_PTR(-EINVAL);
}
