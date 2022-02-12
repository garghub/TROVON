static void signal_handler(int sig)
{
global_signal_val = sig;
}
int rw_ctl_init(const char *ctl_path)
{
int ctl_fd;
ctl_fd = open(ctl_path, O_RDONLY);
if (ctl_fd == -1) {
pr_err("Cannot open ctl_fd\n");
goto error;
}
return ctl_fd;
error:
exit(EXIT_FAILURE);
}
static int wait_order(int ctl_fd)
{
struct pollfd poll_fd;
int ret = 0;
while (!global_sig_receive) {
poll_fd.fd = ctl_fd;
poll_fd.events = POLLIN;
ret = poll(&poll_fd, 1, EVENT_WAIT_MSEC);
if (global_signal_val) {
global_sig_receive = true;
pr_info("Receive interrupt %d\n", global_signal_val);
if (!global_run_operation)
pthread_cond_broadcast(&cond_wakeup);
ret = -1;
break;
}
if (ret < 0) {
pr_err("Polling error\n");
goto error;
}
if (ret)
break;
};
return ret;
error:
exit(EXIT_FAILURE);
}
void *rw_ctl_loop(int ctl_fd)
{
ssize_t rlen;
char buf[HOST_MSG_SIZE];
int ret;
signal(SIGTERM, signal_handler);
signal(SIGINT, signal_handler);
signal(SIGQUIT, signal_handler);
while (!global_sig_receive) {
ret = wait_order(ctl_fd);
if (ret < 0)
break;
rlen = read(ctl_fd, buf, sizeof(buf));
if (rlen < 0) {
pr_err("read data error in ctl thread\n");
goto error;
}
if (rlen == 2 && buf[0] == '1') {
global_run_operation = true;
pthread_cond_broadcast(&cond_wakeup);
pr_debug("Wake up all read/write threads\n");
} else if (rlen == 2 && buf[0] == '0') {
global_run_operation = false;
pr_debug("Stop all read/write threads\n");
} else
pr_info("Invalid host notification: %s\n", buf);
}
return NULL;
error:
exit(EXIT_FAILURE);
}
