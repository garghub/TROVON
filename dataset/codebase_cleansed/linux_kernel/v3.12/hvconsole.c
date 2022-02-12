int hvc_get_chars(uint32_t vtermno, char *buf, int count)
{
long ret;
unsigned long retbuf[PLPAR_HCALL_BUFSIZE];
unsigned long *lbuf = (unsigned long *)buf;
ret = plpar_hcall(H_GET_TERM_CHAR, retbuf, vtermno);
lbuf[0] = be64_to_cpu(retbuf[1]);
lbuf[1] = be64_to_cpu(retbuf[2]);
if (ret == H_SUCCESS)
return retbuf[0];
return 0;
}
int hvc_put_chars(uint32_t vtermno, const char *buf, int count)
{
unsigned long *lbuf = (unsigned long *) buf;
long ret;
if (count > MAX_VIO_PUT_CHARS)
count = MAX_VIO_PUT_CHARS;
ret = plpar_hcall_norets(H_PUT_TERM_CHAR, vtermno, count,
cpu_to_be64(lbuf[0]),
cpu_to_be64(lbuf[1]));
if (ret == H_SUCCESS)
return count;
if (ret == H_BUSY)
return -EAGAIN;
return -EIO;
}
