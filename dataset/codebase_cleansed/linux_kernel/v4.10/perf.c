static int pager_command_config(const char *var, const char *value, void *data)
{
struct pager_config *c = data;
if (!prefixcmp(var, "pager.") && !strcmp(var + 6, c->cmd))
c->val = perf_config_bool(var, value);
return 0;
}
int check_pager_config(const char *cmd)
{
struct pager_config c;
c.cmd = cmd;
c.val = -1;
perf_config(pager_command_config, &c);
return c.val;
}
static int browser_command_config(const char *var, const char *value, void *data)
{
struct pager_config *c = data;
if (!prefixcmp(var, "tui.") && !strcmp(var + 4, c->cmd))
c->val = perf_config_bool(var, value);
if (!prefixcmp(var, "gtk.") && !strcmp(var + 4, c->cmd))
c->val = perf_config_bool(var, value) ? 2 : 0;
return 0;
}
static int check_browser_config(const char *cmd)
{
struct pager_config c;
c.cmd = cmd;
c.val = -1;
perf_config(browser_command_config, &c);
return c.val;
}
static void commit_pager_choice(void)
{
switch (use_pager) {
case 0:
setenv(PERF_PAGER_ENVIRONMENT, "cat", 1);
break;
case 1:
break;
default:
break;
}
}
static int handle_options(const char ***argv, int *argc, int *envchanged)
{
int handled = 0;
while (*argc > 0) {
const char *cmd = (*argv)[0];
if (cmd[0] != '-')
break;
if (!strcmp(cmd, "--help") || !strcmp(cmd, "--version"))
break;
if (!strcmp(cmd, "-h")) {
(*argv)[0] = "--help";
break;
}
if (!strcmp(cmd, "-v")) {
(*argv)[0] = "--version";
break;
}
if (!prefixcmp(cmd, CMD_EXEC_PATH)) {
cmd += strlen(CMD_EXEC_PATH);
if (*cmd == '=')
set_argv_exec_path(cmd + 1);
else {
puts(get_argv_exec_path());
exit(0);
}
} else if (!strcmp(cmd, "--html-path")) {
puts(system_path(PERF_HTML_PATH));
exit(0);
} else if (!strcmp(cmd, "-p") || !strcmp(cmd, "--paginate")) {
use_pager = 1;
} else if (!strcmp(cmd, "--no-pager")) {
use_pager = 0;
if (envchanged)
*envchanged = 1;
} else if (!strcmp(cmd, "--debugfs-dir")) {
if (*argc < 2) {
fprintf(stderr, "No directory given for --debugfs-dir.\n");
usage(perf_usage_string);
}
tracing_path_set((*argv)[1]);
if (envchanged)
*envchanged = 1;
(*argv)++;
(*argc)--;
} else if (!strcmp(cmd, "--buildid-dir")) {
if (*argc < 2) {
fprintf(stderr, "No directory given for --buildid-dir.\n");
usage(perf_usage_string);
}
set_buildid_dir((*argv)[1]);
if (envchanged)
*envchanged = 1;
(*argv)++;
(*argc)--;
} else if (!prefixcmp(cmd, CMD_DEBUGFS_DIR)) {
tracing_path_set(cmd + strlen(CMD_DEBUGFS_DIR));
fprintf(stderr, "dir: %s\n", tracing_path);
if (envchanged)
*envchanged = 1;
} else if (!strcmp(cmd, "--list-cmds")) {
unsigned int i;
for (i = 0; i < ARRAY_SIZE(commands); i++) {
struct cmd_struct *p = commands+i;
printf("%s ", p->cmd);
}
putchar('\n');
exit(0);
} else if (!strcmp(cmd, "--list-opts")) {
unsigned int i;
for (i = 0; i < ARRAY_SIZE(options)-1; i++) {
struct option *p = options+i;
printf("--%s ", p->long_name);
}
putchar('\n');
exit(0);
} else if (!strcmp(cmd, "--debug")) {
if (*argc < 2) {
fprintf(stderr, "No variable specified for --debug.\n");
usage(perf_usage_string);
}
if (perf_debug_option((*argv)[1]))
usage(perf_usage_string);
(*argv)++;
(*argc)--;
} else {
fprintf(stderr, "Unknown option: %s\n", cmd);
usage(perf_usage_string);
}
(*argv)++;
(*argc)--;
handled++;
}
return handled;
}
static int handle_alias(int *argcp, const char ***argv)
{
int envchanged = 0, ret = 0, saved_errno = errno;
int count, option_count;
const char **new_argv;
const char *alias_command;
char *alias_string;
alias_command = (*argv)[0];
alias_string = alias_lookup(alias_command);
if (alias_string) {
if (alias_string[0] == '!') {
if (*argcp > 1) {
struct strbuf buf;
if (strbuf_init(&buf, PATH_MAX) < 0 ||
strbuf_addstr(&buf, alias_string) < 0 ||
sq_quote_argv(&buf, (*argv) + 1,
PATH_MAX) < 0)
die("Failed to allocate memory.");
free(alias_string);
alias_string = buf.buf;
}
ret = system(alias_string + 1);
if (ret >= 0 && WIFEXITED(ret) &&
WEXITSTATUS(ret) != 127)
exit(WEXITSTATUS(ret));
die("Failed to run '%s' when expanding alias '%s'",
alias_string + 1, alias_command);
}
count = split_cmdline(alias_string, &new_argv);
if (count < 0)
die("Bad alias.%s string", alias_command);
option_count = handle_options(&new_argv, &count, &envchanged);
if (envchanged)
die("alias '%s' changes environment variables\n"
"You can use '!perf' in the alias to do this.",
alias_command);
memmove(new_argv - option_count, new_argv,
count * sizeof(char *));
new_argv -= option_count;
if (count < 1)
die("empty alias for %s", alias_command);
if (!strcmp(alias_command, new_argv[0]))
die("recursive alias: %s", alias_command);
new_argv = realloc(new_argv, sizeof(char *) *
(count + *argcp + 1));
memcpy(new_argv + count, *argv + 1, sizeof(char *) * *argcp);
new_argv[count + *argcp] = NULL;
*argv = new_argv;
*argcp += count - 1;
ret = 1;
}
errno = saved_errno;
return ret;
}
static int run_builtin(struct cmd_struct *p, int argc, const char **argv)
{
int status;
struct stat st;
const char *prefix;
char sbuf[STRERR_BUFSIZE];
prefix = NULL;
if (p->option & RUN_SETUP)
prefix = NULL;
if (use_browser == -1)
use_browser = check_browser_config(p->cmd);
if (use_pager == -1 && p->option & RUN_SETUP)
use_pager = check_pager_config(p->cmd);
if (use_pager == -1 && p->option & USE_PAGER)
use_pager = 1;
commit_pager_choice();
perf_env__set_cmdline(&perf_env, argc, argv);
status = p->fn(argc, argv, prefix);
perf_config__exit();
exit_browser(status);
perf_env__exit(&perf_env);
bpf__clear();
if (status)
return status & 0xff;
if (fstat(fileno(stdout), &st))
return 0;
if (S_ISFIFO(st.st_mode) || S_ISSOCK(st.st_mode))
return 0;
status = 1;
if (fflush(stdout)) {
fprintf(stderr, "write failure on standard output: %s",
str_error_r(errno, sbuf, sizeof(sbuf)));
goto out;
}
if (ferror(stdout)) {
fprintf(stderr, "unknown write failure on standard output");
goto out;
}
if (fclose(stdout)) {
fprintf(stderr, "close failed on standard output: %s",
str_error_r(errno, sbuf, sizeof(sbuf)));
goto out;
}
status = 0;
out:
return status;
}
static void handle_internal_command(int argc, const char **argv)
{
const char *cmd = argv[0];
unsigned int i;
static const char ext[] = STRIP_EXTENSION;
if (sizeof(ext) > 1) {
i = strlen(argv[0]) - strlen(ext);
if (i > 0 && !strcmp(argv[0] + i, ext)) {
char *argv0 = strdup(argv[0]);
argv[0] = cmd = argv0;
argv0[i] = '\0';
}
}
if (argc > 1 && !strcmp(argv[1], "--help")) {
argv[1] = argv[0];
argv[0] = cmd = "help";
}
for (i = 0; i < ARRAY_SIZE(commands); i++) {
struct cmd_struct *p = commands+i;
if (strcmp(p->cmd, cmd))
continue;
exit(run_builtin(p, argc, argv));
}
}
static void execv_dashed_external(const char **argv)
{
char *cmd;
const char *tmp;
int status;
if (asprintf(&cmd, "perf-%s", argv[0]) < 0)
goto do_die;
tmp = argv[0];
argv[0] = cmd;
status = run_command_v_opt(argv, 0);
if (status != -ERR_RUN_COMMAND_EXEC) {
if (IS_RUN_COMMAND_ERR(status)) {
do_die:
die("unable to run '%s'", argv[0]);
}
exit(-status);
}
errno = ENOENT;
argv[0] = tmp;
zfree(&cmd);
}
static int run_argv(int *argcp, const char ***argv)
{
int done_alias = 0;
while (1) {
handle_internal_command(*argcp, *argv);
execv_dashed_external(*argv);
if (done_alias || !handle_alias(argcp, argv))
break;
done_alias = 1;
}
return done_alias;
}
static void pthread__block_sigwinch(void)
{
sigset_t set;
sigemptyset(&set);
sigaddset(&set, SIGWINCH);
pthread_sigmask(SIG_BLOCK, &set, NULL);
}
void pthread__unblock_sigwinch(void)
{
sigset_t set;
sigemptyset(&set);
sigaddset(&set, SIGWINCH);
pthread_sigmask(SIG_UNBLOCK, &set, NULL);
}
static void cache_line_size(int *cacheline_sizep)
{
if (sysfs__read_int("devices/system/cpu/cpu0/cache/index0/coherency_line_size", cacheline_sizep))
pr_debug("cannot determine cache line size");
}
int main(int argc, const char **argv)
{
const char *cmd;
char sbuf[STRERR_BUFSIZE];
int value;
exec_cmd_init("perf", PREFIX, PERF_EXEC_PATH, EXEC_PATH_ENVIRONMENT);
pager_init(PERF_PAGER_ENVIRONMENT);
page_size = sysconf(_SC_PAGE_SIZE);
cache_line_size(&cacheline_size);
if (sysctl__read_int("kernel/perf_event_max_stack", &value) == 0)
sysctl_perf_event_max_stack = value;
if (sysctl__read_int("kernel/perf_event_max_contexts_per_stack", &value) == 0)
sysctl_perf_event_max_contexts_per_stack = value;
cmd = extract_argv0_path(argv[0]);
if (!cmd)
cmd = "perf-help";
srandom(time(NULL));
perf_config__init();
perf_config(perf_default_config, NULL);
set_buildid_dir(NULL);
tracing_path_mount();
if (!prefixcmp(cmd, "perf-")) {
cmd += 5;
argv[0] = cmd;
handle_internal_command(argc, argv);
fprintf(stderr, "cannot handle %s internally", cmd);
goto out;
}
if (!prefixcmp(cmd, "trace")) {
#ifdef HAVE_LIBAUDIT_SUPPORT
setup_path();
argv[0] = "trace";
return cmd_trace(argc, argv, NULL);
#else
fprintf(stderr,
"trace command not available: missing audit-libs devel package at build time.\n");
goto out;
#endif
}
argv++;
argc--;
handle_options(&argv, &argc, NULL);
commit_pager_choice();
if (argc > 0) {
if (!prefixcmp(argv[0], "--"))
argv[0] += 2;
} else {
printf("\n usage: %s\n\n", perf_usage_string);
list_common_cmds_help();
printf("\n %s\n\n", perf_more_info_string);
goto out;
}
cmd = argv[0];
test_attr__init();
setup_path();
pthread__block_sigwinch();
perf_debug_setup();
while (1) {
static int done_help;
int was_alias = run_argv(&argc, &argv);
if (errno != ENOENT)
break;
if (was_alias) {
fprintf(stderr, "Expansion of alias '%s' failed; "
"'%s' is not a perf-command\n",
cmd, argv[0]);
goto out;
}
if (!done_help) {
cmd = argv[0] = help_unknown_cmd(cmd);
done_help = 1;
} else
break;
}
fprintf(stderr, "Failed to run command '%s': %s\n",
cmd, str_error_r(errno, sbuf, sizeof(sbuf)));
out:
return 1;
}
