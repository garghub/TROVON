static int print_hook(const char *fmt, ...)
{
char buf[400];
int len;
va_list args;
va_start(args, fmt);
vsnprintf(buf, sizeof(buf), fmt, args);
va_end(args);
len = strlen(buf);
if (*sn_oemdata_size + len <= sn_oemdata_bufsize)
memcpy(*sn_oemdata + *sn_oemdata_size, buf, len);
*sn_oemdata_size += len;
return 0;
}
static void sn_cpei_handler(int irq, void *devid, struct pt_regs *regs)
{
ia64_sn_plat_cpei_handler();
}
static void sn_cpei_timer_handler(unsigned long dummy)
{
sn_cpei_handler(-1, NULL, NULL);
mod_timer(&sn_cpei_timer, jiffies + CPEI_INTERVAL);
}
void sn_init_cpei_timer(void)
{
init_timer(&sn_cpei_timer);
sn_cpei_timer.expires = jiffies + CPEI_INTERVAL;
sn_cpei_timer.function = sn_cpei_timer_handler;
add_timer(&sn_cpei_timer);
}
static int
sn_platform_plat_specific_err_print(const u8 * sect_header, u8 ** oemdata,
u64 * oemdata_size)
{
mutex_lock(&sn_oemdata_mutex);
sn_oemdata = oemdata;
sn_oemdata_size = oemdata_size;
sn_oemdata_bufsize = 0;
*sn_oemdata_size = PAGE_SIZE;
while (*sn_oemdata_size > sn_oemdata_bufsize) {
u8 *newbuf = vmalloc(*sn_oemdata_size);
if (!newbuf) {
mutex_unlock(&sn_oemdata_mutex);
printk(KERN_ERR "%s: unable to extend sn_oemdata\n",
__func__);
return 1;
}
vfree(*sn_oemdata);
*sn_oemdata = newbuf;
sn_oemdata_bufsize = *sn_oemdata_size;
*sn_oemdata_size = 0;
ia64_sn_plat_specific_err_print(print_hook, (char *)sect_header);
}
mutex_unlock(&sn_oemdata_mutex);
return 0;
}
int sn_salinfo_platform_oemdata(const u8 *sect_header, u8 **oemdata, u64 *oemdata_size)
{
efi_guid_t guid = *(efi_guid_t *)sect_header;
int valid = 0;
*oemdata_size = 0;
vfree(*oemdata);
*oemdata = NULL;
if (efi_guidcmp(guid, SAL_PLAT_SPECIFIC_ERR_SECT_GUID) == 0) {
sal_log_plat_specific_err_info_t *psei = (sal_log_plat_specific_err_info_t *)sect_header;
valid = psei->valid.oem_data;
} else if (efi_guidcmp(guid, SAL_PLAT_MEM_DEV_ERR_SECT_GUID) == 0) {
sal_log_mem_dev_err_info_t *mdei = (sal_log_mem_dev_err_info_t *)sect_header;
valid = mdei->valid.oem_data;
}
if (valid)
return sn_platform_plat_specific_err_print(sect_header, oemdata, oemdata_size);
else
return 0;
}
static int __init sn_salinfo_init(void)
{
if (ia64_platform_is("sn2"))
salinfo_platform_oemdata = &sn_salinfo_platform_oemdata;
return 0;
}
