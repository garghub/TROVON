char *str_error_r(int errnum, char *buf, size_t buflen)
{
int err = strerror_r(errnum, buf, buflen);
if (err)
snprintf(buf, buflen, "INTERNAL ERROR: strerror_r(%d, %p, %zd)=%d", errnum, buf, buflen, err);
return buf;
}
