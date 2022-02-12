void __drm_printfn_seq_file(struct drm_printer *p, struct va_format *vaf)
{
seq_printf(p->arg, "%pV", vaf);
}
void __drm_printfn_info(struct drm_printer *p, struct va_format *vaf)
{
dev_info(p->arg, "[" DRM_NAME "] %pV", vaf);
}
void __drm_printfn_debug(struct drm_printer *p, struct va_format *vaf)
{
pr_debug("%s %pV", p->prefix, vaf);
}
void drm_printf(struct drm_printer *p, const char *f, ...)
{
struct va_format vaf;
va_list args;
va_start(args, f);
vaf.fmt = f;
vaf.va = &args;
p->printfn(p, &vaf);
va_end(args);
}
