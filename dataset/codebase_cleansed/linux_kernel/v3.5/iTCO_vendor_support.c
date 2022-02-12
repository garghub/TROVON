static void supermicro_old_pre_start(struct resource *smires)
{
unsigned long val32;
val32 = inl(smires->start);
val32 &= 0xffffdfff;
outl(val32, smires->start);
}
static void supermicro_old_pre_stop(struct resource *smires)
{
unsigned long val32;
val32 = inl(smires->start);
val32 |= 0x00002000;
outl(val32, smires->start);
}
static void supermicro_new_unlock_watchdog(void)
{
outb(SM_WATCHPAGE, SM_REGINDEX);
outb(SM_WATCHPAGE, SM_REGINDEX);
outb(SM_CTLPAGESW, SM_REGINDEX);
outb(SM_CTLPAGE, SM_DATAIO);
}
static void supermicro_new_lock_watchdog(void)
{
outb(SM_ENDWATCH, SM_REGINDEX);
}
static void supermicro_new_pre_start(unsigned int heartbeat)
{
unsigned int val;
supermicro_new_unlock_watchdog();
outb(SM_COUNTMODE, SM_REGINDEX);
val = inb(SM_DATAIO);
val &= 0xF7;
outb(val, SM_DATAIO);
outb(SM_WATCHTIMER, SM_REGINDEX);
outb((heartbeat & 255), SM_DATAIO);
outb(SM_RESETCONTROL, SM_REGINDEX);
val = inb(SM_DATAIO);
val &= 0x3f;
outb(val, SM_DATAIO);
outb(SM_WATCHENABLE, SM_REGINDEX);
val = inb(SM_DATAIO);
val |= 0x01;
outb(val, SM_DATAIO);
supermicro_new_lock_watchdog();
}
static void supermicro_new_pre_stop(void)
{
unsigned int val;
supermicro_new_unlock_watchdog();
outb(SM_WATCHENABLE, SM_REGINDEX);
val = inb(SM_DATAIO);
val &= 0xFE;
outb(val, SM_DATAIO);
supermicro_new_lock_watchdog();
}
static void supermicro_new_pre_set_heartbeat(unsigned int heartbeat)
{
supermicro_new_unlock_watchdog();
outb(SM_WATCHTIMER, SM_REGINDEX);
outb((heartbeat & 255), SM_DATAIO);
supermicro_new_lock_watchdog();
}
static void broken_bios_start(struct resource *smires)
{
unsigned long val32;
val32 = inl(smires->start);
val32 &= 0xffffdffe;
outl(val32, smires->start);
}
static void broken_bios_stop(struct resource *smires)
{
unsigned long val32;
val32 = inl(smires->start);
val32 |= 0x00002001;
outl(val32, smires->start);
}
void iTCO_vendor_pre_start(struct resource *smires,
unsigned int heartbeat)
{
switch (vendorsupport) {
case SUPERMICRO_OLD_BOARD:
supermicro_old_pre_start(smires);
break;
case SUPERMICRO_NEW_BOARD:
supermicro_new_pre_start(heartbeat);
break;
case BROKEN_BIOS:
broken_bios_start(smires);
break;
}
}
void iTCO_vendor_pre_stop(struct resource *smires)
{
switch (vendorsupport) {
case SUPERMICRO_OLD_BOARD:
supermicro_old_pre_stop(smires);
break;
case SUPERMICRO_NEW_BOARD:
supermicro_new_pre_stop();
break;
case BROKEN_BIOS:
broken_bios_stop(smires);
break;
}
}
void iTCO_vendor_pre_keepalive(struct resource *smires, unsigned int heartbeat)
{
if (vendorsupport == SUPERMICRO_NEW_BOARD)
supermicro_new_pre_set_heartbeat(heartbeat);
}
void iTCO_vendor_pre_set_heartbeat(unsigned int heartbeat)
{
if (vendorsupport == SUPERMICRO_NEW_BOARD)
supermicro_new_pre_set_heartbeat(heartbeat);
}
int iTCO_vendor_check_noreboot_on(void)
{
switch (vendorsupport) {
case SUPERMICRO_OLD_BOARD:
return 0;
default:
return 1;
}
}
static int __init iTCO_vendor_init_module(void)
{
pr_info("vendor-support=%d\n", vendorsupport);
return 0;
}
static void __exit iTCO_vendor_exit_module(void)
{
pr_info("Module Unloaded\n");
}
