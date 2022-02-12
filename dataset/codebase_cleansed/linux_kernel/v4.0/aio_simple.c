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
struct usb_functionfs_event event;
int ret;
struct pollfd pfds[1];
pfds[0].fd = ep0;
pfds[0].events = POLLIN;
ret = poll(pfds, 1, 0);
if (ret && (pfds[0].revents & POLLIN)) {
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
}
int main(int argc, char *argv[])
{
int i, ret;
char *ep_path;
int ep0;
int ep[2];
io_context_t ctx;
int evfd;
fd_set rfds;
char *buf_in, *buf_out;
struct iocb *iocb_in, *iocb_out;
int req_in = 0, req_out = 0;
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
for (i = 0; i < 2; ++i) {
sprintf(ep_path, "%s/ep%d", argv[1], i+1);
ep[i] = open(ep_path, O_RDWR);
if (ep[i] < 0) {
printf("unable to open ep%d: %s\n", i+1,
strerror(errno));
return 1;
}
}
free(ep_path);
memset(&ctx, 0, sizeof(ctx));
if (io_setup(2, &ctx) < 0) {
perror("unable to setup aio");
return 1;
}
evfd = eventfd(0, 0);
if (evfd < 0) {
perror("unable to open eventfd");
return 1;
}
buf_in = malloc(BUF_LEN);
buf_out = malloc(BUF_LEN);
iocb_in = malloc(sizeof(*iocb_in));
iocb_out = malloc(sizeof(*iocb_out));
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
if (FD_ISSET(evfd, &rfds)) {
uint64_t ev_cnt;
ret = read(evfd, &ev_cnt, sizeof(ev_cnt));
if (ret < 0) {
perror("unable to read eventfd");
break;
}
struct io_event e[2];
ret = io_getevents(ctx, 1, 2, e, NULL);
for (i = 0; i < ret; ++i) {
if (e[i].obj->aio_fildes == ep[0]) {
printf("ev=in; ret=%lu\n", e[i].res);
req_in = 0;
} else if (e[i].obj->aio_fildes == ep[1]) {
printf("ev=out; ret=%lu\n", e[i].res);
req_out = 0;
}
}
}
if (!req_in) {
io_prep_pwrite(iocb_in, ep[0], buf_in, BUF_LEN, 0);
iocb_in->u.c.flags |= IOCB_FLAG_RESFD;
iocb_in->u.c.resfd = evfd;
ret = io_submit(ctx, 1, &iocb_in);
if (ret >= 0) {
req_in = 1;
printf("submit: in\n");
} else
perror("unable to submit request");
}
if (!req_out) {
io_prep_pread(iocb_out, ep[1], buf_out, BUF_LEN, 0);
iocb_out->u.c.flags |= IOCB_FLAG_RESFD;
iocb_out->u.c.resfd = evfd;
ret = io_submit(ctx, 1, &iocb_out);
if (ret >= 0) {
req_out = 1;
printf("submit: out\n");
} else
perror("unable to submit request");
}
}
io_destroy(ctx);
free(buf_in);
free(buf_out);
free(iocb_in);
free(iocb_out);
for (i = 0; i < 2; ++i)
close(ep[i]);
close(ep0);
return 0;
}
