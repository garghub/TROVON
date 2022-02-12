uint32_t mdp_get_formats(uint32_t *pixel_formats, uint32_t max_formats,
bool rgb_only)
{
uint32_t i;
for (i = 0; i < ARRAY_SIZE(formats); i++) {
const struct mdp_format *f = &formats[i];
if (i == max_formats)
break;
if (rgb_only && MDP_FORMAT_IS_YUV(f))
break;
pixel_formats[i] = f->base.pixel_format;
}
return i;
}
const struct msm_format *mdp_get_format(struct msm_kms *kms, uint32_t format)
{
int i;
for (i = 0; i < ARRAY_SIZE(formats); i++) {
const struct mdp_format *f = &formats[i];
if (f->base.pixel_format == format)
return &f->base;
}
return NULL;
}
struct csc_cfg *mdp_get_default_csc_cfg(enum csc_type type)
{
if (unlikely(WARN_ON(type >= CSC_MAX)))
return NULL;
return &csc_convert[type];
}
