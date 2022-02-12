static void *pty_chan_init(char *str, int device, const struct chan_opts *opts)
{
struct pty_chan *data;
data = uml_kmalloc(sizeof(*data), UM_GFP_KERNEL);
if (data == NULL)
return NULL;
*data = ((struct pty_chan) { .announce = opts->announce,
.dev = device,
.raw = opts->raw });
return data;
}
static int pts_open(int input, int output, int primary, void *d,
char **dev_out)
{
struct pty_chan *data = d;
char *dev;
int fd, err;
fd = get_pty();
if (fd < 0) {
err = -errno;
printk(UM_KERN_ERR "open_pts : Failed to open pts\n");
return err;
}
if (data->raw) {
CATCH_EINTR(err = tcgetattr(fd, &data->tt));
if (err)
goto out_close;
err = raw(fd);
if (err)
goto out_close;
}
dev = ptsname(fd);
sprintf(data->dev_name, "%s", dev);
*dev_out = data->dev_name;
if (data->announce)
(*data->announce)(dev, data->dev);
return fd;
out_close:
close(fd);
return err;
}
static int getmaster(char *line)
{
struct stat buf;
char *pty, *bank, *cp;
int master, err;
pty = &line[strlen("/dev/ptyp")];
for (bank = "pqrs"; *bank; bank++) {
line[strlen("/dev/pty")] = *bank;
*pty = '0';
if ((stat(line, &buf) < 0) && (errno == ENOENT))
break;
for (cp = "0123456789abcdef"; *cp; cp++) {
*pty = *cp;
master = open(line, O_RDWR);
if (master >= 0) {
char *tp = &line[strlen("/dev/")];
*tp = 't';
err = access(line, R_OK | W_OK);
*tp = 'p';
if (!err)
return master;
close(master);
}
}
}
printk(UM_KERN_ERR "getmaster - no usable host pty devices\n");
return -ENOENT;
}
static int pty_open(int input, int output, int primary, void *d,
char **dev_out)
{
struct pty_chan *data = d;
int fd, err;
char dev[sizeof("/dev/ptyxx\0")] = "/dev/ptyxx";
fd = getmaster(dev);
if (fd < 0)
return fd;
if (data->raw) {
err = raw(fd);
if (err) {
close(fd);
return err;
}
}
if (data->announce)
(*data->announce)(dev, data->dev);
sprintf(data->dev_name, "%s", dev);
*dev_out = data->dev_name;
return fd;
}
