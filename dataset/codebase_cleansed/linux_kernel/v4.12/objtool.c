static void cmd_usage(void)
{
unsigned int i, longest = 0;
printf("\n usage: %s\n\n", objtool_usage_string);
for (i = 0; i < ARRAY_SIZE(objtool_cmds); i++) {
if (longest < strlen(objtool_cmds[i].name))
longest = strlen(objtool_cmds[i].name);
}
puts(" Commands:");
for (i = 0; i < ARRAY_SIZE(objtool_cmds); i++) {
printf(" %-*s ", longest, objtool_cmds[i].name);
puts(objtool_cmds[i].help);
}
printf("\n");
exit(1);
}
static void handle_options(int *argc, const char ***argv)
{
while (*argc > 0) {
const char *cmd = (*argv)[0];
if (cmd[0] != '-')
break;
if (!strcmp(cmd, "--help") || !strcmp(cmd, "-h")) {
help = true;
break;
} else {
fprintf(stderr, "Unknown option: %s\n", cmd);
fprintf(stderr, "\n Usage: %s\n",
objtool_usage_string);
exit(1);
}
(*argv)++;
(*argc)--;
}
}
static void handle_internal_command(int argc, const char **argv)
{
const char *cmd = argv[0];
unsigned int i, ret;
for (i = 0; i < ARRAY_SIZE(objtool_cmds); i++) {
struct cmd_struct *p = objtool_cmds+i;
if (strcmp(p->name, cmd))
continue;
ret = p->fn(argc, argv);
exit(ret);
}
cmd_usage();
}
int main(int argc, const char **argv)
{
static const char *UNUSED = "OBJTOOL_NOT_IMPLEMENTED";
exec_cmd_init("objtool", UNUSED, UNUSED, UNUSED);
pager_init(UNUSED);
argv++;
argc--;
handle_options(&argc, &argv);
if (!argc || help)
cmd_usage();
handle_internal_command(argc, argv);
return 0;
}
