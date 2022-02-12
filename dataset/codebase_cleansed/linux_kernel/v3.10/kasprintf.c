char *kvasprintf(gfp_t gfp, const char *fmt, va_list ap)
{
unsigned int len;
char *p;
va_list aq;
va_copy(aq, ap);
len = vsnprintf(NULL, 0, fmt, aq);
va_end(aq);
p = kmalloc_track_caller(len+1, gfp);
if (!p)
return NULL;
vsnprintf(p, len+1, fmt, ap);
return p;
}
char *kasprintf(gfp_t gfp, const char *fmt, ...)
{
va_list ap;
char *p;
va_start(ap, fmt);
p = kvasprintf(gfp, fmt, ap);
va_end(ap);
return p;
}
