const char *get_system_type(void)
{
return system_types[mips_machtype];
}
void __weak __init mach_prom_init_machtype(void)
{
}
void __init prom_init_machtype(void)
{
char *p, str[MACHTYPE_LEN + 1];
int machtype = MACH_LEMOTE_FL2E;
mips_machtype = LOONGSON_MACHTYPE;
p = strstr(arcs_cmdline, "machtype=");
if (!p) {
mach_prom_init_machtype();
return;
}
p += strlen("machtype=");
strncpy(str, p, MACHTYPE_LEN);
str[MACHTYPE_LEN] = '\0';
p = strstr(str, " ");
if (p)
*p = '\0';
for (; system_types[machtype]; machtype++)
if (strstr(system_types[machtype], str)) {
mips_machtype = machtype;
break;
}
}
