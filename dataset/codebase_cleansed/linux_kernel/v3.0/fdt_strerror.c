const char *fdt_strerror(int errval)
{
if (errval > 0)
return "<valid offset/length>";
else if (errval == 0)
return "<no error>";
else if (errval > -FDT_ERRTABSIZE) {
const char *s = fdt_errtable[-errval].str;
if (s)
return s;
}
return "<unknown error>";
}
