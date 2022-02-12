char * __init prom_getcmdline(void)
{
return &(arcs_cmdline[0]);
}
void __init prom_init_cmdline(void)
{
char *cp;
int actr;
actr = 1;
cp = &(arcs_cmdline[0]);
while (actr < prom_argc) {
strcpy(cp, prom_argv(actr));
cp += strlen(prom_argv(actr));
*cp++ = ' ';
actr++;
}
if (cp != &(arcs_cmdline[0])) {
--cp;
*cp = '\0';
}
}
