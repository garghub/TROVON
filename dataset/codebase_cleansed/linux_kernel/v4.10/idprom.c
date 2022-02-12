static void __init display_system_type(unsigned char machtype)
{
register int i;
for (i = 0; i < NUM_SUN_MACHINES; i++) {
if(Sun_Machines[i].id_machtype == machtype) {
if (machtype != (SM_SUN4M_OBP | 0x00))
printk("TYPE: %s\n", Sun_Machines[i].name);
else {
#if 0
prom_getproperty(prom_root_node, "banner-name",
sysname, sizeof(sysname));
printk("TYPE: %s\n", sysname);
#endif
}
return;
}
}
prom_printf("IDPROM: Bogus id_machtype value, 0x%x\n", machtype);
prom_halt();
}
void sun3_get_model(unsigned char* model)
{
register int i;
for (i = 0; i < NUM_SUN_MACHINES; i++) {
if(Sun_Machines[i].id_machtype == idprom->id_machtype) {
strcpy(model, Sun_Machines[i].name);
return;
}
}
}
static unsigned char __init calc_idprom_cksum(struct idprom *idprom)
{
unsigned char cksum, i, *ptr = (unsigned char *)idprom;
for (i = cksum = 0; i <= 0x0E; i++)
cksum ^= *ptr++;
return cksum;
}
void __init idprom_init(void)
{
prom_get_idprom((char *) &idprom_buffer, sizeof(idprom_buffer));
idprom = &idprom_buffer;
if (idprom->id_format != 0x01) {
prom_printf("IDPROM: Unknown format type!\n");
prom_halt();
}
if (idprom->id_cksum != calc_idprom_cksum(idprom)) {
prom_printf("IDPROM: Checksum failure (nvram=%x, calc=%x)!\n",
idprom->id_cksum, calc_idprom_cksum(idprom));
prom_halt();
}
display_system_type(idprom->id_machtype);
printk("Ethernet address: %pM\n", idprom->id_ethaddr);
}
