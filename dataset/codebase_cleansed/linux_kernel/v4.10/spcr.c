int __init parse_spcr(bool earlycon)
{
static char opts[64];
struct acpi_table_spcr *table;
acpi_status status;
char *uart;
char *iotype;
int baud_rate;
int err;
if (acpi_disabled)
return -ENODEV;
status = acpi_get_table(ACPI_SIG_SPCR, 0,
(struct acpi_table_header **)&table);
if (ACPI_FAILURE(status))
return -ENOENT;
if (table->header.revision < 2) {
err = -ENOENT;
pr_err("wrong table version\n");
goto done;
}
iotype = table->serial_port.space_id == ACPI_ADR_SPACE_SYSTEM_MEMORY ?
"mmio" : "io";
switch (table->interface_type) {
case ACPI_DBG2_ARM_SBSA_32BIT:
iotype = "mmio32";
case ACPI_DBG2_ARM_PL011:
case ACPI_DBG2_ARM_SBSA_GENERIC:
case ACPI_DBG2_BCM2835:
uart = "pl011";
break;
case ACPI_DBG2_16550_COMPATIBLE:
case ACPI_DBG2_16550_SUBSET:
uart = "uart";
break;
default:
err = -ENOENT;
goto done;
}
switch (table->baud_rate) {
case 3:
baud_rate = 9600;
break;
case 4:
baud_rate = 19200;
break;
case 6:
baud_rate = 57600;
break;
case 7:
baud_rate = 115200;
break;
default:
err = -ENOENT;
goto done;
}
snprintf(opts, sizeof(opts), "%s,%s,0x%llx,%d", uart, iotype,
table->serial_port.address, baud_rate);
pr_info("console: %s\n", opts);
if (earlycon)
setup_earlycon(opts);
err = add_preferred_console(uart, 0, opts + strlen(uart) + 1);
done:
acpi_put_table((struct acpi_table_header *)table);
return err;
}
