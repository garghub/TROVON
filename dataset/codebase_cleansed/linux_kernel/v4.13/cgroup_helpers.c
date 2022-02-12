int setup_cgroup_environment(void)
{
char cgroup_workdir[PATH_MAX + 1];
format_cgroup_path(cgroup_workdir, "");
if (unshare(CLONE_NEWNS)) {
log_err("unshare");
return 1;
}
if (mount("none", "/", NULL, MS_REC | MS_PRIVATE, NULL)) {
log_err("mount fakeroot");
return 1;
}
if (mount("none", CGROUP_MOUNT_PATH, "cgroup2", 0, NULL)) {
log_err("mount cgroup2");
return 1;
}
cleanup_cgroup_environment();
if (mkdir(cgroup_workdir, 0777) && errno != EEXIST) {
log_err("mkdir cgroup work dir");
return 1;
}
return 0;
}
static int nftwfunc(const char *filename, const struct stat *statptr,
int fileflags, struct FTW *pfwt)
{
if ((fileflags & FTW_D) && rmdir(filename))
log_err("Removing cgroup: %s", filename);
return 0;
}
static int join_cgroup_from_top(char *cgroup_path)
{
char cgroup_procs_path[PATH_MAX + 1];
pid_t pid = getpid();
int fd, rc = 0;
snprintf(cgroup_procs_path, sizeof(cgroup_procs_path),
"%s/cgroup.procs", cgroup_path);
fd = open(cgroup_procs_path, O_WRONLY);
if (fd < 0) {
log_err("Opening Cgroup Procs: %s", cgroup_procs_path);
return 1;
}
if (dprintf(fd, "%d\n", pid) < 0) {
log_err("Joining Cgroup");
rc = 1;
}
close(fd);
return rc;
}
int join_cgroup(char *path)
{
char cgroup_path[PATH_MAX + 1];
format_cgroup_path(cgroup_path, path);
return join_cgroup_from_top(cgroup_path);
}
void cleanup_cgroup_environment(void)
{
char cgroup_workdir[PATH_MAX + 1];
format_cgroup_path(cgroup_workdir, "");
join_cgroup_from_top(CGROUP_MOUNT_PATH);
nftw(cgroup_workdir, nftwfunc, WALK_FD_LIMIT, FTW_DEPTH | FTW_MOUNT);
}
int create_and_get_cgroup(char *path)
{
char cgroup_path[PATH_MAX + 1];
int fd;
format_cgroup_path(cgroup_path, path);
if (mkdir(cgroup_path, 0777) && errno != EEXIST) {
log_err("mkdiring cgroup");
return 0;
}
fd = open(cgroup_path, O_RDONLY);
if (fd < 0) {
log_err("Opening Cgroup");
return 0;
}
return fd;
}
