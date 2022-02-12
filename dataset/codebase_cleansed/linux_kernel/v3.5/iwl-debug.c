void __iwl_err(struct device *dev, bool rfkill_prefix, bool trace_only,
const char *fmt, ...)
{
struct va_format vaf = {
.fmt = fmt,
};
va_list args;
va_start(args, fmt);
vaf.va = &args;
if (!trace_only) {
if (rfkill_prefix)
dev_err(dev, "(RFKILL) %pV", &vaf);
else
dev_err(dev, "%pV", &vaf);
}
trace_iwlwifi_err(&vaf);
va_end(args);
}
void __iwl_dbg(struct device *dev,
u32 level, bool limit, const char *function,
const char *fmt, ...)
{
struct va_format vaf = {
.fmt = fmt,
};
va_list args;
va_start(args, fmt);
vaf.va = &args;
#ifdef CONFIG_IWLWIFI_DEBUG
if (iwl_have_debug_level(level) &&
(!limit || net_ratelimit()))
dev_err(dev, "%c %s %pV", in_interrupt() ? 'I' : 'U',
function, &vaf);
#endif
trace_iwlwifi_dbg(level, in_interrupt(), function, &vaf);
va_end(args);
}
