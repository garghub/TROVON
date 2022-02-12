s32 CsrSnprintf(char *dest, size_t n, const char *fmt, ...)
{
s32 r;
va_list args;
va_start(args, fmt);
r = vsnprintf(dest, n, fmt, args);
va_end(args);
if (dest && (n > 0))
{
dest[n - 1] = '\0';
}
return r;
}
