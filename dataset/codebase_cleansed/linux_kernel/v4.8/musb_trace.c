void musb_dbg(struct musb *musb, const char *fmt, ...)
{
struct va_format vaf;
va_list args;
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
trace_musb_log(musb, &vaf);
va_end(args);
}
