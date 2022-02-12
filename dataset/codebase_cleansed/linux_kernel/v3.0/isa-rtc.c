void __init isa_rtc_init(void)
{
int reg_d, reg_b;
reg_d = CMOS_READ(RTC_REG_D);
CMOS_WRITE(RTC_REF_CLCK_32KHZ, RTC_REG_A);
reg_b = CMOS_READ(RTC_REG_B) & 0x7f;
reg_b |= 2;
CMOS_WRITE(reg_b, RTC_REG_B);
if ((CMOS_READ(RTC_REG_A) & 0x7f) == RTC_REF_CLCK_32KHZ &&
CMOS_READ(RTC_REG_B) == reg_b) {
if ((reg_d & 0x80) == 0)
printk(KERN_WARNING "RTC: *** warning: CMOS battery bad\n");
}
}
