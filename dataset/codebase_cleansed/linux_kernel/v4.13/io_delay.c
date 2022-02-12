void native_io_delay(void)
{
switch (io_delay_type) {
default:
case CONFIG_IO_DELAY_TYPE_0X80:
asm volatile ("outb %al, $0x80");
break;
case CONFIG_IO_DELAY_TYPE_0XED:
asm volatile ("outb %al, $0xed");
break;
case CONFIG_IO_DELAY_TYPE_UDELAY:
udelay(2);
case CONFIG_IO_DELAY_TYPE_NONE:
break;
}
}
static int __init dmi_io_delay_0xed_port(const struct dmi_system_id *id)
{
if (io_delay_type == CONFIG_IO_DELAY_TYPE_0X80) {
pr_notice("%s: using 0xed I/O delay port\n", id->ident);
io_delay_type = CONFIG_IO_DELAY_TYPE_0XED;
}
return 0;
}
void __init io_delay_init(void)
{
if (!io_delay_override)
dmi_check_system(io_delay_0xed_port_dmi_table);
}
static int __init io_delay_param(char *s)
{
if (!s)
return -EINVAL;
if (!strcmp(s, "0x80"))
io_delay_type = CONFIG_IO_DELAY_TYPE_0X80;
else if (!strcmp(s, "0xed"))
io_delay_type = CONFIG_IO_DELAY_TYPE_0XED;
else if (!strcmp(s, "udelay"))
io_delay_type = CONFIG_IO_DELAY_TYPE_UDELAY;
else if (!strcmp(s, "none"))
io_delay_type = CONFIG_IO_DELAY_TYPE_NONE;
else
return -EINVAL;
io_delay_override = 1;
return 0;
}
