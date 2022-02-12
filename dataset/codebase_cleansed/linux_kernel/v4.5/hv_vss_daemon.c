static int vss_do_freeze(char *dir, unsigned int cmd)
{
int ret, fd = open(dir, O_RDONLY);
if (fd < 0)
return 1;
ret = ioctl(fd, cmd, 0);
if (ret) {
if ((cmd == FIFREEZE && errno == EBUSY) ||
(cmd == FITHAW && errno == EINVAL)) {
close(fd);
return 0;
}
}
close(fd);
return !!ret;
}
static int vss_operate(int operation)
{
char match[] = "/dev/";
FILE *mounts;
struct mntent *ent;
char errdir[1024] = {0};
unsigned int cmd;
int error = 0, root_seen = 0, save_errno = 0;
switch (operation) {
case VSS_OP_FREEZE:
cmd = FIFREEZE;
break;
case VSS_OP_THAW:
cmd = FITHAW;
break;
default:
return -1;
}
mounts = setmntent("/proc/mounts", "r");
if (mounts == NULL)
return -1;
while ((ent = getmntent(mounts))) {
if (strncmp(ent->mnt_fsname, match, strlen(match)))
continue;
if (hasmntopt(ent, MNTOPT_RO) != NULL)
continue;
if (strcmp(ent->mnt_type, "vfat") == 0)
continue;
if (strcmp(ent->mnt_dir, "/") == 0) {
root_seen = 1;
continue;
}
error |= vss_do_freeze(ent->mnt_dir, cmd);
if (error && operation == VSS_OP_FREEZE)
goto err;
}
endmntent(mounts);
if (root_seen) {
error |= vss_do_freeze("/", cmd);
if (error && operation == VSS_OP_FREEZE)
goto err;
}
goto out;
err:
save_errno = errno;
if (ent) {
strncpy(errdir, ent->mnt_dir, sizeof(errdir)-1);
endmntent(mounts);
}
vss_operate(VSS_OP_THAW);
if (ent)
syslog(LOG_ERR, "FREEZE of %s failed; error:%d %s",
errdir, save_errno, strerror(save_errno));
else
syslog(LOG_ERR, "FREEZE of / failed; error:%d %s", save_errno,
strerror(save_errno));
out:
return error;
}
void print_usage(char *argv[])
{
fprintf(stderr, "Usage: %s [options]\n"
"Options are:\n"
" -n, --no-daemon stay in foreground, don't daemonize\n"
" -h, --help print this help\n", argv[0]);
}
int main(int argc, char *argv[])
{
int vss_fd, len;
int error;
struct pollfd pfd;
int op;
struct hv_vss_msg vss_msg[1];
int daemonize = 1, long_index = 0, opt;
int in_handshake = 1;
__u32 kernel_modver;
static struct option long_options[] = {
{"help", no_argument, 0, 'h' },
{"no-daemon", no_argument, 0, 'n' },
{0, 0, 0, 0 }
};
while ((opt = getopt_long(argc, argv, "hn", long_options,
&long_index)) != -1) {
switch (opt) {
case 'n':
daemonize = 0;
break;
case 'h':
default:
print_usage(argv);
exit(EXIT_FAILURE);
}
}
if (daemonize && daemon(1, 0))
return 1;
openlog("Hyper-V VSS", 0, LOG_USER);
syslog(LOG_INFO, "VSS starting; pid is:%d", getpid());
vss_fd = open("/dev/vmbus/hv_vss", O_RDWR);
if (vss_fd < 0) {
syslog(LOG_ERR, "open /dev/vmbus/hv_vss failed; error: %d %s",
errno, strerror(errno));
exit(EXIT_FAILURE);
}
vss_msg->vss_hdr.operation = VSS_OP_REGISTER1;
len = write(vss_fd, vss_msg, sizeof(struct hv_vss_msg));
if (len < 0) {
syslog(LOG_ERR, "registration to kernel failed; error: %d %s",
errno, strerror(errno));
close(vss_fd);
exit(EXIT_FAILURE);
}
pfd.fd = vss_fd;
while (1) {
pfd.events = POLLIN;
pfd.revents = 0;
if (poll(&pfd, 1, -1) < 0) {
syslog(LOG_ERR, "poll failed; error:%d %s", errno, strerror(errno));
if (errno == EINVAL) {
close(vss_fd);
exit(EXIT_FAILURE);
}
else
continue;
}
len = read(vss_fd, vss_msg, sizeof(struct hv_vss_msg));
if (in_handshake) {
if (len != sizeof(kernel_modver)) {
syslog(LOG_ERR, "invalid version negotiation");
exit(EXIT_FAILURE);
}
kernel_modver = *(__u32 *)vss_msg;
in_handshake = 0;
syslog(LOG_INFO, "VSS: kernel module version: %d",
kernel_modver);
continue;
}
if (len != sizeof(struct hv_vss_msg)) {
syslog(LOG_ERR, "read failed; error:%d %s",
errno, strerror(errno));
close(vss_fd);
return EXIT_FAILURE;
}
op = vss_msg->vss_hdr.operation;
error = HV_S_OK;
switch (op) {
case VSS_OP_FREEZE:
case VSS_OP_THAW:
error = vss_operate(op);
syslog(LOG_INFO, "VSS: op=%s: %s\n",
op == VSS_OP_FREEZE ? "FREEZE" : "THAW",
error ? "failed" : "succeeded");
if (error) {
error = HV_E_FAIL;
syslog(LOG_ERR, "op=%d failed!", op);
syslog(LOG_ERR, "report it with these files:");
syslog(LOG_ERR, "/etc/fstab and /proc/mounts");
}
break;
default:
syslog(LOG_ERR, "Illegal op:%d\n", op);
}
vss_msg->error = error;
len = write(vss_fd, vss_msg, sizeof(struct hv_vss_msg));
if (len != sizeof(struct hv_vss_msg)) {
syslog(LOG_ERR, "write failed; error: %d %s", errno,
strerror(errno));
exit(EXIT_FAILURE);
}
}
close(vss_fd);
exit(0);
}
