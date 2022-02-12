static void *tty_chan_init(char *str, int device, const struct chan_opts *opts)
{
struct tty_chan *data;
if (*str != ':') {
printk(UM_KERN_ERR "tty_init : channel type 'tty' must specify "
"a device\n");
return NULL;
}
str++;
data = uml_kmalloc(sizeof(*data), UM_GFP_KERNEL);
if (data == NULL)
return NULL;
*data = ((struct tty_chan) { .dev = str,
.raw = opts->raw });
return data;
}
static int tty_open(int input, int output, int primary, void *d,
char **dev_out)
{
struct tty_chan *data = d;
int fd, err, mode = 0;
if (input && output)
mode = O_RDWR;
else if (input)
mode = O_RDONLY;
else if (output)
mode = O_WRONLY;
fd = open(data->dev, mode);
if (fd < 0)
return -errno;
if (data->raw) {
CATCH_EINTR(err = tcgetattr(fd, &data->tt));
if (err)
return err;
err = raw(fd);
if (err)
return err;
}
*dev_out = data->dev;
return fd;
}
