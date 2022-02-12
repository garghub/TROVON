uint32_t mdp4_get_formats(enum mdp4_pipe pipe_id, uint32_t *pixel_formats,
uint32_t max_formats)
{
uint32_t i;
for (i = 0; i < ARRAY_SIZE(formats); i++) {
const struct mdp4_format *f = &formats[i];
if (i == max_formats)
break;
pixel_formats[i] = f->base.pixel_format;
}
return i;
}
const struct msm_format *mdp4_get_format(struct msm_kms *kms, uint32_t format)
{
int i;
for (i = 0; i < ARRAY_SIZE(formats); i++) {
const struct mdp4_format *f = &formats[i];
if (f->base.pixel_format == format)
return &f->base;
}
return NULL;
}
