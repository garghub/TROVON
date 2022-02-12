int ide_scan_pio_blacklist(char *model)
{
struct ide_pio_info *p;
for (p = ide_pio_blacklist; p->name != NULL; p++) {
if (strncmp(p->name, model, strlen(p->name)) == 0)
return p->pio;
}
return -1;
}
