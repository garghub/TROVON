static long io_setup(int n, aio_context_t *ctxp)
{
return syscall(__NR_io_setup, n, ctxp);
}
static long io_submit(aio_context_t ctx, long nr, struct iocb **iocbpp)
{
return syscall(__NR_io_submit, ctx, nr, iocbpp);
}
static long io_getevents(aio_context_t ctx_id, long min_nr, long nr,
struct io_event *events, struct timespec *timeout)
{
return syscall(__NR_io_getevents, ctx_id, min_nr, nr, events, timeout);
}
static int do_aio(aio_context_t ctx, enum aio_type type, int fd, char *buf,
int len, unsigned long long offset, struct aio_context *aio)
{
struct iocb *iocbp = & ((struct iocb) {
.aio_data = (unsigned long) aio,
.aio_fildes = fd,
.aio_buf = (unsigned long) buf,
.aio_nbytes = len,
.aio_offset = offset
});
char c;
switch (type) {
case AIO_READ:
iocbp->aio_lio_opcode = IOCB_CMD_PREAD;
break;
case AIO_WRITE:
iocbp->aio_lio_opcode = IOCB_CMD_PWRITE;
break;
case AIO_MMAP:
iocbp->aio_lio_opcode = IOCB_CMD_PREAD;
iocbp->aio_buf = (unsigned long) &c;
iocbp->aio_nbytes = sizeof(c);
break;
default:
printk(UM_KERN_ERR "Bogus op in do_aio - %d\n", type);
return -EINVAL;
}
return (io_submit(ctx, 1, &iocbp) > 0) ? 0 : -errno;
}
static int aio_thread(void *arg)
{
struct aio_thread_reply reply;
struct io_event event;
int err, n, reply_fd;
signal(SIGWINCH, SIG_IGN);
while (1) {
n = io_getevents(ctx, 1, 1, &event, NULL);
if (n < 0) {
if (errno == EINTR)
continue;
printk(UM_KERN_ERR "aio_thread - io_getevents failed, "
"errno = %d\n", errno);
}
else {
reply = ((struct aio_thread_reply)
{ .data = (void *) (long) event.data,
.err = event.res });
reply_fd = ((struct aio_context *) reply.data)->reply_fd;
err = write(reply_fd, &reply, sizeof(reply));
if (err != sizeof(reply))
printk(UM_KERN_ERR "aio_thread - write failed, "
"fd = %d, err = %d\n", reply_fd, errno);
}
}
return 0;
}
static int do_not_aio(struct aio_thread_req *req)
{
char c;
unsigned long long actual;
int n;
actual = lseek64(req->io_fd, req->offset, SEEK_SET);
if (actual != req->offset)
return -errno;
switch (req->type) {
case AIO_READ:
n = read(req->io_fd, req->buf, req->len);
break;
case AIO_WRITE:
n = write(req->io_fd, req->buf, req->len);
break;
case AIO_MMAP:
n = read(req->io_fd, &c, sizeof(c));
break;
default:
printk(UM_KERN_ERR "do_not_aio - bad request type : %d\n",
req->type);
return -EINVAL;
}
if (n < 0)
return -errno;
return 0;
}
static int not_aio_thread(void *arg)
{
struct aio_thread_req req;
struct aio_thread_reply reply;
int err;
signal(SIGWINCH, SIG_IGN);
while (1) {
err = read(aio_req_fd_r, &req, sizeof(req));
if (err != sizeof(req)) {
if (err < 0)
printk(UM_KERN_ERR "not_aio_thread - "
"read failed, fd = %d, err = %d\n",
aio_req_fd_r,
errno);
else {
printk(UM_KERN_ERR "not_aio_thread - short "
"read, fd = %d, length = %d\n",
aio_req_fd_r, err);
}
continue;
}
err = do_not_aio(&req);
reply = ((struct aio_thread_reply) { .data = req.aio,
.err = err });
err = write(req.aio->reply_fd, &reply, sizeof(reply));
if (err != sizeof(reply))
printk(UM_KERN_ERR "not_aio_thread - write failed, "
"fd = %d, err = %d\n", req.aio->reply_fd, errno);
}
return 0;
}
static int init_aio_24(void)
{
int fds[2], err;
err = os_pipe(fds, 1, 1);
if (err)
goto out;
aio_req_fd_w = fds[0];
aio_req_fd_r = fds[1];
err = os_set_fd_block(aio_req_fd_w, 0);
if (err)
goto out_close_pipe;
err = run_helper_thread(not_aio_thread, NULL,
CLONE_FILES | CLONE_VM, &aio_stack);
if (err < 0)
goto out_close_pipe;
aio_pid = err;
goto out;
out_close_pipe:
close(fds[0]);
close(fds[1]);
aio_req_fd_w = -1;
aio_req_fd_r = -1;
out:
#ifndef HAVE_AIO_ABI
printk(UM_KERN_INFO "/usr/include/linux/aio_abi.h not present during "
"build\n");
#endif
printk(UM_KERN_INFO "2.6 host AIO support not used - falling back to "
"I/O thread\n");
return 0;
}
static int init_aio_26(void)
{
int err;
if (io_setup(256, &ctx)) {
err = -errno;
printk(UM_KERN_ERR "aio_thread failed to initialize context, "
"err = %d\n", errno);
return err;
}
err = run_helper_thread(aio_thread, NULL,
CLONE_FILES | CLONE_VM, &aio_stack);
if (err < 0)
return err;
aio_pid = err;
printk(UM_KERN_INFO "Using 2.6 host AIO\n");
return 0;
}
static int submit_aio_26(enum aio_type type, int io_fd, char *buf, int len,
unsigned long long offset, struct aio_context *aio)
{
struct aio_thread_reply reply;
int err;
err = do_aio(ctx, type, io_fd, buf, len, offset, aio);
if (err) {
reply = ((struct aio_thread_reply) { .data = aio,
.err = err });
err = write(aio->reply_fd, &reply, sizeof(reply));
if (err != sizeof(reply)) {
err = -errno;
printk(UM_KERN_ERR "submit_aio_26 - write failed, "
"fd = %d, err = %d\n", aio->reply_fd, -err);
}
else err = 0;
}
return err;
}
static int init_aio_26(void)
{
return -ENOSYS;
}
static int submit_aio_26(enum aio_type type, int io_fd, char *buf, int len,
unsigned long long offset, struct aio_context *aio)
{
return -ENOSYS;
}
static int __init set_aio_24(char *name, int *add)
{
aio_24 = 1;
return 0;
}
static int init_aio(void)
{
int err;
if (!aio_24) {
err = init_aio_26();
if (err && (errno == ENOSYS)) {
printk(UM_KERN_INFO "2.6 AIO not supported on the "
"host - reverting to 2.4 AIO\n");
aio_24 = 1;
}
else return err;
}
if (aio_24)
return init_aio_24();
return 0;
}
static void exit_aio(void)
{
if (aio_pid != -1) {
os_kill_process(aio_pid, 1);
free_stack(aio_stack, 0);
}
}
static int submit_aio_24(enum aio_type type, int io_fd, char *buf, int len,
unsigned long long offset, struct aio_context *aio)
{
struct aio_thread_req req = { .type = type,
.io_fd = io_fd,
.offset = offset,
.buf = buf,
.len = len,
.aio = aio,
};
int err;
err = write(aio_req_fd_w, &req, sizeof(req));
if (err == sizeof(req))
err = 0;
else err = -errno;
return err;
}
int submit_aio(enum aio_type type, int io_fd, char *buf, int len,
unsigned long long offset, int reply_fd,
struct aio_context *aio)
{
aio->reply_fd = reply_fd;
if (aio_24)
return submit_aio_24(type, io_fd, buf, len, offset, aio);
else
return submit_aio_26(type, io_fd, buf, len, offset, aio);
}
