static void *null_init(char *str, int device, const struct chan_opts *opts)
{
return &null_chan;
}
static int null_open(int input, int output, int primary, void *d,
char **dev_out)
{
int fd;
*dev_out = NULL;
fd = open(DEV_NULL, O_RDWR);
return (fd < 0) ? -errno : fd;
}
static int null_read(int fd, char *c_out, void *unused)
{
return -ENODEV;
}
static void null_free(void *data)
{
}
