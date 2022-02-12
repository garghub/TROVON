unsigned int omap_rev(void)
{
return omap_revision;
}
static u16 __init omap_get_jtag_id(void)
{
u32 prod_id, omap_id;
prod_id = omap_readl(OMAP_PRODUCTION_ID_1);
omap_id = omap_readl(OMAP32_ID_1);
if (((prod_id >> 20) == 0) || (prod_id == omap_id))
prod_id = 0;
else
prod_id &= 0xffff;
if (prod_id)
return prod_id;
prod_id = ((omap_id >> 12) & 0xffff);
return prod_id;
}
static u8 __init omap_get_die_rev(void)
{
u32 die_rev;
die_rev = omap_readl(OMAP_DIE_ID_1);
if (((die_rev >> 12) & 0xffff) == omap_get_jtag_id())
die_rev = 0;
die_rev = (die_rev >> 17) & 0xf;
if (die_rev)
return die_rev;
die_rev = (omap_readl(OMAP32_ID_1) >> 28) & 0xf;
return die_rev;
}
void __init omap_check_revision(void)
{
int i;
u16 jtag_id;
u8 die_rev;
u32 omap_id;
u8 cpu_type;
jtag_id = omap_get_jtag_id();
die_rev = omap_get_die_rev();
omap_id = omap_readl(OMAP32_ID_0);
#ifdef DEBUG
printk(KERN_DEBUG "OMAP_DIE_ID_0: 0x%08x\n", omap_readl(OMAP_DIE_ID_0));
printk(KERN_DEBUG "OMAP_DIE_ID_1: 0x%08x DIE_REV: %i\n",
omap_readl(OMAP_DIE_ID_1),
(omap_readl(OMAP_DIE_ID_1) >> 17) & 0xf);
printk(KERN_DEBUG "OMAP_PRODUCTION_ID_0: 0x%08x\n",
omap_readl(OMAP_PRODUCTION_ID_0));
printk(KERN_DEBUG "OMAP_PRODUCTION_ID_1: 0x%08x JTAG_ID: 0x%04x\n",
omap_readl(OMAP_PRODUCTION_ID_1),
omap_readl(OMAP_PRODUCTION_ID_1) & 0xffff);
printk(KERN_DEBUG "OMAP32_ID_0: 0x%08x\n", omap_readl(OMAP32_ID_0));
printk(KERN_DEBUG "OMAP32_ID_1: 0x%08x\n", omap_readl(OMAP32_ID_1));
printk(KERN_DEBUG "JTAG_ID: 0x%04x DIE_REV: %i\n", jtag_id, die_rev);
#endif
system_serial_high = omap_readl(OMAP_DIE_ID_0);
system_serial_low = omap_readl(OMAP_DIE_ID_1);
for (i = 0; i < ARRAY_SIZE(omap_ids); i++) {
if (jtag_id == (omap_ids[i].jtag_id)) {
omap_revision = omap_ids[i].type;
break;
}
}
for (i = 0; i < ARRAY_SIZE(omap_ids); i++) {
if (jtag_id == omap_ids[i].jtag_id && die_rev == omap_ids[i].die_rev) {
omap_revision = omap_ids[i].type;
break;
}
}
for (i = 0; i < ARRAY_SIZE(omap_ids); i++) {
if (jtag_id == omap_ids[i].jtag_id
&& die_rev == omap_ids[i].die_rev
&& omap_id == omap_ids[i].omap_id) {
omap_revision = omap_ids[i].type;
break;
}
}
cpu_type = omap_revision >> 24;
switch (cpu_type) {
case 0x07:
case 0x08:
omap_revision |= 0x07;
break;
case 0x03:
case 0x15:
omap_revision |= 0x15;
break;
case 0x16:
case 0x17:
omap_revision |= 0x16;
break;
default:
printk(KERN_INFO "Unknown OMAP cpu type: 0x%02x\n", cpu_type);
}
printk(KERN_INFO "OMAP%04x", omap_revision >> 16);
if ((omap_revision >> 8) & 0xff)
printk(KERN_INFO "%x", (omap_revision >> 8) & 0xff);
printk(KERN_INFO " revision %i handled as %02xxx id: %08x%08x\n",
die_rev, omap_revision & 0xff, system_serial_low,
system_serial_high);
}
