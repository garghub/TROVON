static int __init malta_add_devices(void)
{
int err;
err = platform_add_devices(malta_devices, ARRAY_SIZE(malta_devices));
if (err)
return err;
CMOS_WRITE(CMOS_READ(RTC_CONTROL) & ~RTC_DM_BINARY, RTC_CONTROL);
return 0;
}
