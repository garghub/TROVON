static char * __init move_firmware_args(char* cp)
{
char *s;
int actr, i;
actr = 1;
while (actr < prom_argc) {
for(i = 0; i < ARRAY_SIZE(used_arc); i++) {
int len = strlen(used_arc[i][0]);
if (!strncmp(prom_argv(actr), used_arc[i][0], len)) {
strcat(cp, used_arc[i][1]);
cp += strlen(used_arc[i][1]);
s = strchr(prom_argv(actr), '=');
if (s) {
s++;
strcpy(cp, s);
cp += strlen(s);
}
*cp++ = ' ';
break;
}
}
actr++;
}
return cp;
}
void __init prom_init_cmdline(void)
{
char *cp;
int actr, i;
actr = 1;
cp = arcs_cmdline;
cp = move_firmware_args(cp);
while (actr < prom_argc) {
for (i = 0; i < ARRAY_SIZE(ignored); i++) {
int len = strlen(ignored[i]);
if (!strncmp(prom_argv(actr), ignored[i], len))
goto pic_cont;
}
strcpy(cp, prom_argv(actr));
cp += strlen(prom_argv(actr));
*cp++ = ' ';
pic_cont:
actr++;
}
if (cp != arcs_cmdline)
--cp;
*cp = '\0';
#ifdef DEBUG_CMDLINE
printk(KERN_DEBUG "prom cmdline: %s\n", arcs_cmdline);
#endif
}
