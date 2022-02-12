static void display_event(struct usb_functionfs_event *event)
{
static const char *const names[] = {
[FUNCTIONFS_BIND] = "BIND",
[FUNCTIONFS_UNBIND] = "UNBIND",
[FUNCTIONFS_ENABLE] = "ENABLE",
[FUNCTIONFS_DISABLE] = "DISABLE",
[FUNCTIONFS_SETUP] = "SETUP",
[FUNCTIONFS_SUSPEND] = "SUSPEND",
[FUNCTIONFS_RESUME] = "RESUME",
};
switch (event->type) {
case FUNCTIONFS_BIND:
case FUNCTIONFS_UNBIND:
case FUNCTIONFS_ENABLE:
case FUNCTIONFS_DISABLE:
case FUNCTIONFS_SETUP:
case FUNCTIONFS_SUSPEND:
case FUNCTIONFS_RESUME:
printf("Event %s\n", names[event->type]);
}
}
static void handle_ep0(int ep0, bool *ready)
{
int ret;
struct usb_functionfs_event event;
ret = read(ep0, &event, sizeof(event));
if (!ret) {
perror("unable to read event from ep0");
return;
}
display_event(&event);
switch (event.type) {
case FUNCTIONFS_SETUP:
if (event.u.setup.bRequestType & USB_DIR_IN)
write(ep0, NULL, 0);
else
read(ep0, NULL, 0);
break;
case FUNCTIONFS_ENABLE:
*ready = true;
break;
case FUNCTIONFS_DISABLE:
*ready = false;
break;
default:
break;
}
}
void init_bufs(struct io_buffer *iobuf, unsigned n, unsigned len)
{
unsigned i;
iobuf->buf = malloc(n*sizeof(*iobuf->buf));
iobuf->iocb = malloc(n*sizeof(*iobuf->iocb));
iobuf->cnt = n;
iobuf->len = len;
iobuf->requested = 0;
for (i = 0; i < n; ++i) {
iobuf->buf[i] = malloc(len*sizeof(**iobuf->buf));
iobuf->iocb[i] = malloc(sizeof(**iobuf->iocb));
}
iobuf->cnt = n;
}
void delete_bufs(struct io_buffer *iobuf)
{
unsigned i;
for (i = 0; i < iobuf->cnt; ++i) {
free(iobuf->buf[i]);
free(iobuf->iocb[i]);
}
free(iobuf->buf);
free(iobuf->iocb);
}
int main(int argc, char *argv[])
{
int ret;
unsigned i, j;
char *ep_path;
int ep0, ep1;
io_context_t ctx;
int evfd;
fd_set rfds;
struct io_buffer iobuf[2];
int actual = 0;
bool ready;
if (argc != 2) {
printf("ffs directory not specified!\n");
return 1;
}
ep_path = malloc(strlen(argv[1]) + 4 + 1 );
if (!ep_path) {
perror("malloc");
return 1;
}
sprintf(ep_path, "%s/ep0", argv[1]);
ep0 = open(ep_path, O_RDWR);
if (ep0 < 0) {
perror("unable to open ep0");
return 1;
}
if (write(ep0, &descriptors, sizeof(descriptors)) < 0) {
perror("unable do write descriptors");
return 1;
}
if (write(ep0, &strings, sizeof(strings)) < 0) {
perror("unable to write strings");
return 1;
}
sprintf(ep_path, "%s/ep1", argv[1]);
ep1 = open(ep_path, O_RDWR);
if (ep1 < 0) {
perror("unable to open ep1");
return 1;
}
free(ep_path);
memset(&ctx, 0, sizeof(ctx));
if (io_setup(AIO_MAX, &ctx) < 0) {
perror("unable to setup aio");
return 1;
}
evfd = eventfd(0, 0);
if (evfd < 0) {
perror("unable to open eventfd");
return 1;
}
for (i = 0; i < sizeof(iobuf)/sizeof(*iobuf); ++i)
init_bufs(&iobuf[i], BUFS_MAX, BUF_LEN);
while (1) {
FD_ZERO(&rfds);
FD_SET(ep0, &rfds);
FD_SET(evfd, &rfds);
ret = select(((ep0 > evfd) ? ep0 : evfd)+1,
&rfds, NULL, NULL, NULL);
if (ret < 0) {
if (errno == EINTR)
continue;
perror("select");
break;
}
if (FD_ISSET(ep0, &rfds))
handle_ep0(ep0, &ready);
if (!ready)
continue;
for (i = 0; i < sizeof(iobuf)/sizeof(*iobuf); ++i) {
if (iobuf[i].requested)
continue;
for (j = 0; j < iobuf[i].cnt; ++j) {
io_prep_pwrite(iobuf[i].iocb[j], ep1,
iobuf[i].buf[j],
iobuf[i].len, 0);
iobuf[i].iocb[j]->u.c.flags |= IOCB_FLAG_RESFD;
iobuf[i].iocb[j]->u.c.resfd = evfd;
}
ret = io_submit(ctx, iobuf[i].cnt, iobuf[i].iocb);
if (ret >= 0) {
iobuf[i].requested = ret;
printf("submit: %d requests buf: %d\n", ret, i);
} else
perror("unable to submit requests");
}
if (!FD_ISSET(evfd, &rfds))
continue;
uint64_t ev_cnt;
ret = read(evfd, &ev_cnt, sizeof(ev_cnt));
if (ret < 0) {
perror("unable to read eventfd");
break;
}
struct io_event e[BUFS_MAX];
ret = io_getevents(ctx, 1, BUFS_MAX, e, NULL);
if (ret > 0)
iobuf[actual].requested -= ret;
if (!iobuf[actual].requested)
actual = (actual + 1)%(sizeof(iobuf)/sizeof(*iobuf));
}
for (i = 0; i < sizeof(iobuf)/sizeof(*iobuf); ++i)
delete_bufs(&iobuf[i]);
io_destroy(ctx);
close(ep1);
close(ep0);
return 0;
}
