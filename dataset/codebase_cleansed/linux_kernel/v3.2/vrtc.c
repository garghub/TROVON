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
unsigned long vrtc_get_time(void)
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
printk(KERN_INFO "vRTC: sec: %d min: %d hour: %d day: %d "
"mon: %d year: %d\n", sec, min, hour, mday, mon, year);
return mktime(year, mon, mday, hour, min, sec);
}
int vrtc_set_mmss(unsigned long nowtime)
{
int real_sec, real_min;
unsigned long flags;
int vrtc_min;
spin_lock_irqsave(&rtc_lock, flags);
vrtc_min = vrtc_cmos_read(RTC_MINUTES);
real_sec = nowtime % 60;
real_min = nowtime / 60;
if (((abs(real_min - vrtc_min) + 15)/30) & 1)
real_min += 30;
real_min %= 60;
vrtc_cmos_write(real_sec, RTC_SECONDS);
vrtc_cmos_write(real_min, RTC_MINUTES);
spin_unlock_irqrestore(&rtc_lock, flags);
return 0;
}
void __init mrst_rtc_init(void)
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
static int __init mrst_device_create(void)
{
if (!mrst_identify_cpu())
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
