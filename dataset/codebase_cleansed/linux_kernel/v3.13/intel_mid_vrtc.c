unsigned char vrtc_cmos_read(unsigned char reg)
{
unsigned char retval;
if (reg > 0xd || !vrtc_virt_base)
return 0xff;
lock_cmos_prefix(reg);
retval = __raw_readb(vrtc_virt_base + (reg << 2));
lock_cmos_suffix(reg);
return retval;
}
void vrtc_cmos_write(unsigned char val, unsigned char reg)
{
if (reg > 0xd || !vrtc_virt_base)
return;
lock_cmos_prefix(reg);
__raw_writeb(val, vrtc_virt_base + (reg << 2));
lock_cmos_suffix(reg);
}
void vrtc_get_time(struct timespec *now)
{
u8 sec, min, hour, mday, mon;
unsigned long flags;
u32 year;
spin_lock_irqsave(&rtc_lock, flags);
while ((vrtc_cmos_read(RTC_FREQ_SELECT) & RTC_UIP))
cpu_relax();
sec = vrtc_cmos_read(RTC_SECONDS);
min = vrtc_cmos_read(RTC_MINUTES);
hour = vrtc_cmos_read(RTC_HOURS);
mday = vrtc_cmos_read(RTC_DAY_OF_MONTH);
mon = vrtc_cmos_read(RTC_MONTH);
year = vrtc_cmos_read(RTC_YEAR);
spin_unlock_irqrestore(&rtc_lock, flags);
year += 1972;
pr_info("vRTC: sec: %d min: %d hour: %d day: %d "
"mon: %d year: %d\n", sec, min, hour, mday, mon, year);
now->tv_sec = mktime(year, mon, mday, hour, min, sec);
now->tv_nsec = 0;
}
int vrtc_set_mmss(const struct timespec *now)
{
unsigned long flags;
struct rtc_time tm;
int year;
int retval = 0;
rtc_time_to_tm(now->tv_sec, &tm);
if (!rtc_valid_tm(&tm) && tm.tm_year >= 72) {
year = tm.tm_year - 72;
spin_lock_irqsave(&rtc_lock, flags);
vrtc_cmos_write(year, RTC_YEAR);
vrtc_cmos_write(tm.tm_mon, RTC_MONTH);
vrtc_cmos_write(tm.tm_mday, RTC_DAY_OF_MONTH);
vrtc_cmos_write(tm.tm_hour, RTC_HOURS);
vrtc_cmos_write(tm.tm_min, RTC_MINUTES);
vrtc_cmos_write(tm.tm_sec, RTC_SECONDS);
spin_unlock_irqrestore(&rtc_lock, flags);
} else {
pr_err("%s: Invalid vRTC value: write of %lx to vRTC failed\n",
__FUNCTION__, now->tv_sec);
retval = -EINVAL;
}
return retval;
}
void __init intel_mid_rtc_init(void)
{
unsigned long vrtc_paddr;
sfi_table_parse(SFI_SIG_MRTC, NULL, NULL, sfi_parse_mrtc);
vrtc_paddr = sfi_mrtc_array[0].phys_addr;
if (!sfi_mrtc_num || !vrtc_paddr)
return;
vrtc_virt_base = (void __iomem *)set_fixmap_offset_nocache(FIX_LNW_VRTC,
vrtc_paddr);
x86_platform.get_wallclock = vrtc_get_time;
x86_platform.set_wallclock = vrtc_set_mmss;
}
static int __init intel_mid_device_create(void)
{
if (!intel_mid_identify_cpu())
return -ENODEV;
if (!sfi_mrtc_num)
return -ENODEV;
vrtc_resources[0].start = sfi_mrtc_array[0].phys_addr;
vrtc_resources[0].end = sfi_mrtc_array[0].phys_addr +
MRST_VRTC_MAP_SZ;
vrtc_resources[1].start = sfi_mrtc_array[0].irq;
vrtc_resources[1].end = sfi_mrtc_array[0].irq;
return platform_device_register(&vrtc_device);
}
