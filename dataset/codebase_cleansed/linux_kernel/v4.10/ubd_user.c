int start_io_thread(unsigned long sp, int *fd_out)
{
int pid, fds[2], err;
err = os_pipe(fds, 1, 1);
if(err < 0){
printk("start_io_thread - os_pipe failed, err = %d\n", -err);
goto out;
}
kernel_fd = fds[0];
kernel_pollfd.fd = kernel_fd;
kernel_pollfd.events = POLLIN;
*fd_out = fds[1];
err = os_set_fd_block(*fd_out, 0);
err = os_set_fd_block(kernel_fd, 0);
if (err) {
printk("start_io_thread - failed to set nonblocking I/O.\n");
goto out_close;
}
pid = clone(io_thread, (void *) sp, CLONE_FILES | CLONE_VM, NULL);
if(pid < 0){
err = -errno;
printk("start_io_thread - clone failed : errno = %d\n", errno);
goto out_close;
}
return(pid);
out_close:
os_close_file(fds[0]);
os_close_file(fds[1]);
kernel_fd = -1;
*fd_out = -1;
out:
return err;
}
int ubd_read_poll(int timeout)
{
kernel_pollfd.events = POLLIN;
return poll(&kernel_pollfd, 1, timeout);
}
int ubd_write_poll(int timeout)
{
kernel_pollfd.events = POLLOUT;
return poll(&kernel_pollfd, 1, timeout);
}
