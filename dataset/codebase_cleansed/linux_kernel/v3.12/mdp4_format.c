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
