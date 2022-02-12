static void usbip_usage(void)
{
printf("usage: %s", usbip_usage_string);
}
static int usbip_help(int argc, char *argv[])
{
const struct command *cmd;
int i;
int ret = 0;
if (argc > 1 && argv++) {
for (i = 0; cmds[i].name != NULL; i++)
if (!strcmp(cmds[i].name, argv[0]) && cmds[i].usage) {
cmds[i].usage();
goto done;
}
ret = -1;
}
usbip_usage();
printf("\n");
for (cmd = cmds; cmd->name != NULL; cmd++)
if (cmd->help != NULL)
printf(" %-10s %s\n", cmd->name, cmd->help);
printf("\n");
done:
return ret;
}
static int usbip_version(int argc, char *argv[])
{
(void) argc;
(void) argv;
printf(PROGNAME " (%s)\n", usbip_version_string);
return 0;
}
static int run_command(const struct command *cmd, int argc, char *argv[])
{
dbg("running command: `%s'", cmd->name);
return cmd->fn(argc, argv);
}
int main(int argc, char *argv[])
{
static const struct option opts[] = {
{ "debug", no_argument, NULL, 'd' },
{ "log", no_argument, NULL, 'l' },
{ NULL, 0, NULL, 0 }
};
char *cmd;
int opt;
int i, rc = -1;
usbip_use_stderr = 1;
opterr = 0;
for (;;) {
opt = getopt_long(argc, argv, "+d", opts, NULL);
if (opt == -1)
break;
switch (opt) {
case 'd':
usbip_use_debug = 1;
break;
case 'l':
usbip_use_syslog = 1;
openlog("", LOG_PID, LOG_USER);
break;
case '?':
printf("usbip: invalid option\n");
default:
usbip_usage();
goto out;
}
}
cmd = argv[optind];
if (cmd) {
for (i = 0; cmds[i].name != NULL; i++)
if (!strcmp(cmds[i].name, cmd)) {
argc -= optind;
argv += optind;
optind = 0;
rc = run_command(&cmds[i], argc, argv);
goto out;
}
}
usbip_help(0, NULL);
out:
return (rc > -1 ? EXIT_SUCCESS : EXIT_FAILURE);
}
