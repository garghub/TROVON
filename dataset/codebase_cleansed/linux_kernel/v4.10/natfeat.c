long nf_get_id(const char *feature_name)
{
char name_copy[32];
size_t n;
n = strlcpy(name_copy, feature_name, sizeof(name_copy));
if (n >= sizeof(name_copy))
return 0;
return nf_get_id_phys(virt_to_phys(name_copy));
}
void nfprint(const char *fmt, ...)
{
static char buf[256];
va_list ap;
int n;
va_start(ap, fmt);
n = vsnprintf(buf, 256, fmt, ap);
nf_call(nf_get_id("NF_STDERR"), virt_to_phys(buf));
va_end(ap);
}
static void nf_poweroff(void)
{
long id = nf_get_id("NF_SHUTDOWN");
if (id)
nf_call(id);
}
void __init nf_init(void)
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
nf_call(id, virt_to_phys(buf), 256);
buf[255] = 0;
pr_info("NatFeats found (%s, %lu.%lu)\n", buf, version >> 16,
version & 0xffff);
mach_power_off = nf_poweroff;
}
