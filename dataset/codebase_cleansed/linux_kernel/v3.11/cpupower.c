static void print_help(void)
{
unsigned int i;
#ifdef DEBUG
printf(_("Usage:\tcpupower [-d|--debug] [-c|--cpu cpulist ] <command> [<args>]\n"));
#else
printf(_("Usage:\tcpupower [-c|--cpu cpulist ] <command> [<args>]\n"));
#endif
printf(_("Supported commands are:\n"));
for (i = 0; i < ARRAY_SIZE(commands); i++)
printf("\t%s\n", commands[i].cmd);
printf(_("\nNot all commands can make use of the -c cpulist option.\n"));
printf(_("\nUse 'cpupower help <command>' for getting help for above commands.\n"));
}
static int print_man_page(const char *subpage)
{
int len;
char *page;
len = 10;
if (subpage != NULL)
len += strlen(subpage);
page = malloc(len);
if (!page)
return -ENOMEM;
sprintf(page, "cpupower");
if ((subpage != NULL) && strcmp(subpage, "help")) {
strcat(page, "-");
strcat(page, subpage);
}
execlp("man", "man", page, NULL);
return -EINVAL;
}
static int cmd_help(int argc, const char **argv)
{
if (argc > 1) {
print_man_page(argv[1]);
return EXIT_FAILURE;
}
print_help();
return EXIT_SUCCESS;
}
static void print_version(void)
{
printf(PACKAGE " " VERSION "\n");
printf(_("Report errors and bugs to %s, please.\n"), PACKAGE_BUGREPORT);
}
static void handle_options(int *argc, const char ***argv)
{
int ret, x, new_argc = 0;
if (*argc < 1)
return;
for (x = 0; x < *argc && ((*argv)[x])[0] == '-'; x++) {
const char *param = (*argv)[x];
if (!strcmp(param, "-h") || !strcmp(param, "--help")) {
print_help();
exit(EXIT_SUCCESS);
} else if (!strcmp(param, "-c") || !strcmp(param, "--cpu")) {
if (*argc < 2) {
print_help();
exit(EXIT_FAILURE);
}
if (!strcmp((*argv)[x+1], "all"))
bitmask_setall(cpus_chosen);
else {
ret = bitmask_parselist(
(*argv)[x+1], cpus_chosen);
if (ret < 0) {
fprintf(stderr, _("Error parsing cpu "
"list\n"));
exit(EXIT_FAILURE);
}
}
x += 1;
new_argc += 2;
continue;
} else if (!strcmp(param, "-v") ||
!strcmp(param, "--version")) {
print_version();
exit(EXIT_SUCCESS);
#ifdef DEBUG
} else if (!strcmp(param, "-d") || !strcmp(param, "--debug")) {
be_verbose = 1;
new_argc++;
continue;
#endif
} else {
fprintf(stderr, "Unknown option: %s\n", param);
print_help();
exit(EXIT_FAILURE);
}
}
*argc -= new_argc;
*argv += new_argc;
}
int main(int argc, const char *argv[])
{
const char *cmd;
unsigned int i, ret;
cpus_chosen = bitmask_alloc(sysconf(_SC_NPROCESSORS_CONF));
argc--;
argv += 1;
handle_options(&argc, &argv);
cmd = argv[0];
if (argc < 1) {
print_help();
return EXIT_FAILURE;
}
setlocale(LC_ALL, "");
textdomain(PACKAGE);
if (argc > 1 && !strcmp(argv[1], "--help")) {
argv[1] = argv[0];
argv[0] = cmd = "help";
}
get_cpu_info(0, &cpupower_cpu_info);
run_as_root = !getuid();
for (i = 0; i < ARRAY_SIZE(commands); i++) {
struct cmd_struct *p = commands + i;
if (strcmp(p->cmd, cmd))
continue;
if (!run_as_root && p->needs_root) {
fprintf(stderr, _("Subcommand %s needs root "
"privileges\n"), cmd);
return EXIT_FAILURE;
}
ret = p->main(argc, argv);
if (cpus_chosen)
bitmask_free(cpus_chosen);
return ret;
}
print_help();
return EXIT_FAILURE;
}
