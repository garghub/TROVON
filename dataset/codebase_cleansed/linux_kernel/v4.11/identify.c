const char *get_system_type(void)
{
#define STR_BUF_LEN 64
static char system[STR_BUF_LEN];
static int called = 0;
if (called == 0) {
called = 1;
snprintf(system, STR_BUF_LEN, "Digital %s",
dec_system_strings[mips_machtype]);
}
return system;
}
static inline void prom_init_kn01(void)
{
dec_kn_slot_base = KN01_SLOT_BASE;
dec_kn_slot_size = KN01_SLOT_SIZE;
dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + KN01_RTC);
}
static inline void prom_init_kn230(void)
{
dec_kn_slot_base = KN01_SLOT_BASE;
dec_kn_slot_size = KN01_SLOT_SIZE;
dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + KN01_RTC);
}
static inline void prom_init_kn02(void)
{
dec_kn_slot_base = KN02_SLOT_BASE;
dec_kn_slot_size = KN02_SLOT_SIZE;
dec_tc_bus = 1;
dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + KN02_RTC);
}
static inline void prom_init_kn02xa(void)
{
dec_kn_slot_base = KN02XA_SLOT_BASE;
dec_kn_slot_size = IOASIC_SLOT_SIZE;
dec_tc_bus = 1;
ioasic_base = (void *)CKSEG1ADDR(dec_kn_slot_base + IOASIC_IOCTL);
dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + IOASIC_TOY);
}
static inline void prom_init_kn03(void)
{
dec_kn_slot_base = KN03_SLOT_BASE;
dec_kn_slot_size = IOASIC_SLOT_SIZE;
dec_tc_bus = 1;
ioasic_base = (void *)CKSEG1ADDR(dec_kn_slot_base + IOASIC_IOCTL);
dec_rtc_base = (void *)CKSEG1ADDR(dec_kn_slot_base + IOASIC_TOY);
}
void __init prom_identify_arch(u32 magic)
{
unsigned char dec_cpunum, dec_firmrev, dec_etc, dec_systype;
u32 dec_sysid;
if (!prom_is_rex(magic)) {
dec_sysid = simple_strtoul(prom_getenv("systype"),
(char **)0, 0);
} else {
dec_sysid = rex_getsysid();
if (dec_sysid == 0) {
printk("Zero sysid returned from PROM! "
"Assuming a PMAX-like machine.\n");
dec_sysid = 1;
}
}
dec_cpunum = (dec_sysid & 0xff000000) >> 24;
dec_systype = (dec_sysid & 0xff0000) >> 16;
dec_firmrev = (dec_sysid & 0xff00) >> 8;
dec_etc = dec_sysid & 0xff;
switch (dec_systype) {
case DS2100_3100:
mips_machtype = MACH_DS23100;
prom_init_kn01();
break;
case DS5100:
mips_machtype = MACH_DS5100;
prom_init_kn230();
break;
case DS5000_200:
mips_machtype = MACH_DS5000_200;
prom_init_kn02();
break;
case DS5000_1XX:
mips_machtype = MACH_DS5000_1XX;
prom_init_kn02xa();
break;
case DS5000_2X0:
mips_machtype = MACH_DS5000_2X0;
prom_init_kn03();
if (!(ioasic_read(IO_REG_SIR) & KN03_IO_INR_3MAXP))
mips_machtype = MACH_DS5900;
break;
case DS5000_XX:
mips_machtype = MACH_DS5000_XX;
prom_init_kn02xa();
break;
case DS5800:
mips_machtype = MACH_DS5800;
break;
case DS5400:
mips_machtype = MACH_DS5400;
break;
case DS5500:
mips_machtype = MACH_DS5500;
break;
default:
mips_machtype = MACH_DSUNKNOWN;
break;
}
if (mips_machtype == MACH_DSUNKNOWN)
printk("This is an %s, id is %x\n",
dec_system_strings[mips_machtype], dec_systype);
else
printk("This is a %s\n", dec_system_strings[mips_machtype]);
}
