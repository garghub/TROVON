void pager_init(const char *pager_env)
{
subcmd_config.pager_env = pager_env;
}
static void pager_preexec(void)
{
fd_set in;
FD_ZERO(&in);
FD_SET(0, &in);
select(1, &in, NULL, &in, NULL);
setenv("LESS", "FRSX", 0);
}
static void wait_for_pager(void)
{
fflush(stdout);
fflush(stderr);
close(1);
close(2);
finish_command(&pager_process);
}
static void wait_for_pager_signal(int signo)
{
wait_for_pager();
sigchain_pop(signo);
raise(signo);
}
void setup_pager(void)
{
const char *pager = getenv(subcmd_config.pager_env);
if (!isatty(1))
return;
if (!pager)
pager = getenv("PAGER");
if (!(pager || access("/usr/bin/pager", X_OK)))
pager = "/usr/bin/pager";
if (!(pager || access("/usr/bin/less", X_OK)))
pager = "/usr/bin/less";
if (!pager)
pager = "cat";
if (!*pager || !strcmp(pager, "cat"))
return;
spawned_pager = 1;
pager_argv[2] = pager;
pager_process.argv = pager_argv;
pager_process.in = -1;
pager_process.preexec_cb = pager_preexec;
if (start_command(&pager_process))
return;
dup2(pager_process.in, 1);
if (isatty(2))
dup2(pager_process.in, 2);
close(pager_process.in);
sigchain_push_common(wait_for_pager_signal);
atexit(wait_for_pager);
}
int pager_in_use(void)
{
return spawned_pager;
}
