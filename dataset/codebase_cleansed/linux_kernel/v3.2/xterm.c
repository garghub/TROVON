static void *xterm_init(char *str, int device, const struct chan_opts *opts)
{
struct xterm_chan *data;
data = uml_kmalloc(sizeof(*data), UM_GFP_KERNEL);
if (data == NULL)
return NULL;
*data = ((struct xterm_chan) { .pid = -1,
.helper_pid = -1,
.device = device,
.title = opts->xterm_title,
.raw = opts->raw } );
return data;
}
static int __init xterm_setup(char *line, int *add)
{
*add = 0;
terminal_emulator = line;
line = strchr(line, ',');
if (line == NULL)
return 0;
*line++ = '\0';
if (*line)
title_switch = line;
line = strchr(line, ',');
if (line == NULL)
return 0;
*line++ = '\0';
if (*line)
exec_switch = line;
return 0;
}
static int xterm_open(int input, int output, int primary, void *d,
char **dev_out)
{
struct xterm_chan *data = d;
int pid, fd, new, err;
char title[256], file[] = "/tmp/xterm-pipeXXXXXX";
char *argv[] = { terminal_emulator, title_switch, title, exec_switch,
OS_LIB_PATH "/uml/port-helper", "-uml-socket",
file, NULL };
if (access(argv[4], X_OK) < 0)
argv[4] = "port-helper";
if (getenv("DISPLAY") == NULL) {
printk(UM_KERN_ERR "xterm_open: $DISPLAY not set.\n");
return -ENODEV;
}
fd = mkstemp(file);
if (fd < 0) {
err = -errno;
printk(UM_KERN_ERR "xterm_open : mkstemp failed, errno = %d\n",
errno);
return err;
}
if (unlink(file)) {
err = -errno;
printk(UM_KERN_ERR "xterm_open : unlink failed, errno = %d\n",
errno);
close(fd);
return err;
}
close(fd);
fd = os_create_unix_socket(file, sizeof(file), 1);
if (fd < 0) {
printk(UM_KERN_ERR "xterm_open : create_unix_socket failed, "
"errno = %d\n", -fd);
return fd;
}
sprintf(title, data->title, data->device);
pid = run_helper(NULL, NULL, argv);
if (pid < 0) {
err = pid;
printk(UM_KERN_ERR "xterm_open : run_helper failed, "
"errno = %d\n", -err);
goto out_close1;
}
err = os_set_fd_block(fd, 0);
if (err < 0) {
printk(UM_KERN_ERR "xterm_open : failed to set descriptor "
"non-blocking, err = %d\n", -err);
goto out_kill;
}
new = xterm_fd(fd, &data->helper_pid);
if (new < 0) {
err = new;
printk(UM_KERN_ERR "xterm_open : os_rcv_fd failed, err = %d\n",
-err);
goto out_kill;
}
err = os_set_fd_block(new, 0);
if (err) {
printk(UM_KERN_ERR "xterm_open : failed to set xterm "
"descriptor non-blocking, err = %d\n", -err);
goto out_close2;
}
CATCH_EINTR(err = tcgetattr(new, &data->tt));
if (err) {
new = err;
goto out_close2;
}
if (data->raw) {
err = raw(new);
if (err) {
new = err;
goto out_close2;
}
}
unlink(file);
data->pid = pid;
*dev_out = NULL;
return new;
out_close2:
close(new);
out_kill:
os_kill_process(pid, 1);
out_close1:
close(fd);
return err;
}
static void xterm_close(int fd, void *d)
{
struct xterm_chan *data = d;
if (data->pid != -1)
os_kill_process(data->pid, 1);
data->pid = -1;
if (data->helper_pid != -1)
os_kill_process(data->helper_pid, 0);
data->helper_pid = -1;
os_close_file(fd);
}
