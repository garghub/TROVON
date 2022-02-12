void nfprint(const char *fmt, ...)
{
static char buf[256];
va_list ap;
int n;
va_start(ap, fmt);
n = vsnprintf(buf, 256, fmt, ap);
nf_call(nf_get_id("NF_STDERR"), buf);
va_end(ap);
}
static void nf_poweroff(void)
{
long id = nf_get_id("NF_SHUTDOWN");
if (id)
nf_call(id);
}
void nf_init(void)
{
unsigned long id, version;
char buf[256];
id = nf_get_id("NF_VERSION");
if (!id)
return;
version = nf_call(id);
id = nf_get_id("NF_NAME");
if (!id)
return;
nf_call(id, buf, 256);
buf[255] = 0;
pr_info("NatFeats found (%s, %lu.%lu)\n", buf, version >> 16,
version & 0xffff);
mach_power_off = nf_poweroff;
}
