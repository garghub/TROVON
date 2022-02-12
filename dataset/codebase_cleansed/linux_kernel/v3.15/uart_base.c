void prom_init_loongson_uart_base(void)
{
switch (mips_machtype) {
case MACH_LEMOTE_FL2E:
loongson_uart_base = LOONGSON_PCIIO_BASE + 0x3f8;
break;
case MACH_LEMOTE_FL2F:
case MACH_LEMOTE_LL2F:
loongson_uart_base = LOONGSON_PCIIO_BASE + 0x2f8;
break;
case MACH_LEMOTE_ML2F7:
case MACH_LEMOTE_YL2F89:
case MACH_DEXXON_GDIUM2F10:
case MACH_LEMOTE_NAS:
default:
loongson_uart_base = LOONGSON_LIO1_BASE + 0x3f8;
break;
case MACH_LEMOTE_A1004:
case MACH_LEMOTE_A1101:
case MACH_LEMOTE_A1201:
case MACH_LEMOTE_A1205:
loongson_uart_base = LOONGSON_REG_BASE + 0x1e0;
break;
}
_loongson_uart_base =
(unsigned long)ioremap_nocache(loongson_uart_base, 8);
}
