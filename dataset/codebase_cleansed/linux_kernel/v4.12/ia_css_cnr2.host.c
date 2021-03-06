void
ia_css_cnr_encode(
struct sh_css_isp_cnr_params *to,
const struct ia_css_cnr_config *from,
unsigned size)
{
(void)size;
to->coring_u = from->coring_u;
to->coring_v = from->coring_v;
to->sense_gain_vy = from->sense_gain_vy;
to->sense_gain_vu = from->sense_gain_vu;
to->sense_gain_vv = from->sense_gain_vv;
to->sense_gain_hy = from->sense_gain_hy;
to->sense_gain_hu = from->sense_gain_hu;
to->sense_gain_hv = from->sense_gain_hv;
}
void
ia_css_cnr_debug_dtrace(
const struct ia_css_cnr_config *config,
unsigned level)
{
ia_css_debug_dtrace(level,
"config.coring_u=%d, config.coring_v=%d, "
"config.sense_gain_vy=%d, config.sense_gain_hy=%d, "
"config.sense_gain_vu=%d, config.sense_gain_hu=%d, "
"config.sense_gain_vv=%d, config.sense_gain_hv=%d\n",
config->coring_u, config->coring_v,
config->sense_gain_vy, config->sense_gain_hy,
config->sense_gain_vu, config->sense_gain_hu,
config->sense_gain_vv, config->sense_gain_hv);
}
void
ia_css_init_cnr2_state(
void *state,
size_t size)
{
memset(state, 0, size);
}
