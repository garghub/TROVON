void __brcmf_err(const char *func, const char *fmt, ...)
{
struct va_format vaf = {
.fmt = fmt,
};
va_list args;
va_start(args, fmt);
vaf.va = &args;
pr_err("%s: %pV", func, &vaf);
trace_brcmf_err(func, &vaf);
va_end(args);
}
