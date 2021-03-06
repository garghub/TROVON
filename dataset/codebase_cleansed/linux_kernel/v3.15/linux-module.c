int libcfs_ioctl_getdata(char *buf, char *end, void *arg)
{
struct libcfs_ioctl_hdr *hdr;
struct libcfs_ioctl_data *data;
int err;
hdr = (struct libcfs_ioctl_hdr *)buf;
data = (struct libcfs_ioctl_data *)buf;
err = copy_from_user(buf, (void *)arg, sizeof(*hdr));
if (err)
return err;
if (hdr->ioc_version != LIBCFS_IOCTL_VERSION) {
CERROR("PORTALS: version mismatch kernel vs application\n");
return -EINVAL;
}
if (hdr->ioc_len + buf >= end) {
CERROR("PORTALS: user buffer exceeds kernel buffer\n");
return -EINVAL;
}
if (hdr->ioc_len < sizeof(struct libcfs_ioctl_data)) {
CERROR("PORTALS: user buffer too small for ioctl\n");
return -EINVAL;
}
err = copy_from_user(buf, (void *)arg, hdr->ioc_len);
if (err)
return err;
if (libcfs_ioctl_is_invalid(data)) {
CERROR("PORTALS: ioctl not correctly formatted\n");
return -EINVAL;
}
if (data->ioc_inllen1)
data->ioc_inlbuf1 = &data->ioc_bulk[0];
if (data->ioc_inllen2)
data->ioc_inlbuf2 = &data->ioc_bulk[0] +
cfs_size_round(data->ioc_inllen1);
return 0;
}
int libcfs_ioctl_popdata(void *arg, void *data, int size)
{
if (copy_to_user((char *)arg, data, size))
return -EFAULT;
return 0;
}
static int
libcfs_psdev_open(struct inode * inode, struct file * file)
{
struct libcfs_device_userstate **pdu = NULL;
int rc = 0;
if (!inode)
return (-EINVAL);
pdu = (struct libcfs_device_userstate **)&file->private_data;
if (libcfs_psdev_ops.p_open != NULL)
rc = libcfs_psdev_ops.p_open(0, (void *)pdu);
else
return (-EPERM);
return rc;
}
static int
libcfs_psdev_release(struct inode * inode, struct file * file)
{
struct libcfs_device_userstate *pdu;
int rc = 0;
if (!inode)
return (-EINVAL);
pdu = file->private_data;
if (libcfs_psdev_ops.p_close != NULL)
rc = libcfs_psdev_ops.p_close(0, (void *)pdu);
else
rc = -EPERM;
return rc;
}
static long libcfs_ioctl(struct file *file,
unsigned int cmd, unsigned long arg)
{
struct cfs_psdev_file pfile;
int rc = 0;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if ( _IOC_TYPE(cmd) != IOC_LIBCFS_TYPE ||
_IOC_NR(cmd) < IOC_LIBCFS_MIN_NR ||
_IOC_NR(cmd) > IOC_LIBCFS_MAX_NR ) {
CDEBUG(D_IOCTL, "invalid ioctl ( type %d, nr %d, size %d )\n",
_IOC_TYPE(cmd), _IOC_NR(cmd), _IOC_SIZE(cmd));
return (-EINVAL);
}
switch (cmd) {
case IOC_LIBCFS_PANIC:
if (!capable(CFS_CAP_SYS_BOOT))
return (-EPERM);
panic("debugctl-invoked panic");
return (0);
case IOC_LIBCFS_MEMHOG:
if (!capable(CFS_CAP_SYS_ADMIN))
return -EPERM;
}
pfile.off = 0;
pfile.private_data = file->private_data;
if (libcfs_psdev_ops.p_ioctl != NULL)
rc = libcfs_psdev_ops.p_ioctl(&pfile, cmd, (void *)arg);
else
rc = -EPERM;
return (rc);
}
