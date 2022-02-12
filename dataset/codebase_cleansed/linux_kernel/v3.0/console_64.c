static int __prom_console_write_buf(const char *buf, int len)
{
unsigned long args[7];
int ret;
args[0] = (unsigned long) "write";
args[1] = 3;
args[2] = 1;
args[3] = (unsigned int) prom_stdout;
args[4] = (unsigned long) buf;
args[5] = (unsigned int) len;
args[6] = (unsigned long) -1;
p1275_cmd_direct(args);
ret = (int) args[6];
if (ret < 0)
return -1;
return ret;
}
void prom_console_write_buf(const char *buf, int len)
{
while (len) {
int n = __prom_console_write_buf(buf, len);
if (n < 0)
continue;
len -= n;
buf += len;
}
}
