void
cmdarg_err_init(void (*err)(const char *, va_list),
void (*err_cont)(const char *, va_list))
{
print_err = err;
print_err_cont = err_cont;
}
void
cmdarg_err(const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
print_err(fmt, ap);
va_end(ap);
}
void
cmdarg_err_cont(const char *fmt, ...)
{
va_list ap;
va_start(ap, fmt);
print_err_cont(fmt, ap);
va_end(ap);
}
