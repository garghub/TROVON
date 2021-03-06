int tc_preadb(u8 *valp, void __iomem *addr)
{
return get_dbe(*valp, (u8 *)addr);
}
int __init tc_bus_get_info(struct tc_bus *tbus)
{
if (!dec_tc_bus)
return -ENXIO;
memcpy(&tbus->info, rex_gettcinfo(), sizeof(tbus->info));
tbus->slot_base = CPHYSADDR((long)rex_slot_address(0));
switch (mips_machtype) {
case MACH_DS5000_200:
tbus->num_tcslots = 7;
break;
case MACH_DS5000_2X0:
case MACH_DS5900:
tbus->ext_slot_base = 0x20000000;
tbus->ext_slot_size = 0x20000000;
case MACH_DS5000_1XX:
tbus->num_tcslots = 3;
break;
case MACH_DS5000_XX:
tbus->num_tcslots = 2;
default:
break;
}
return 0;
}
void __init tc_device_get_irq(struct tc_dev *tdev)
{
switch (tdev->slot) {
case 0:
tdev->interrupt = dec_interrupt[DEC_IRQ_TC0];
break;
case 1:
tdev->interrupt = dec_interrupt[DEC_IRQ_TC1];
break;
case 2:
tdev->interrupt = dec_interrupt[DEC_IRQ_TC2];
break;
case 5:
tdev->interrupt = dec_interrupt[DEC_IRQ_TC5];
break;
case 6:
tdev->interrupt = dec_interrupt[DEC_IRQ_TC6];
break;
default:
tdev->interrupt = -1;
break;
}
}
