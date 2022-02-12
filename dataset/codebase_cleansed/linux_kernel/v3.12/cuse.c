static struct cuse_conn *fc_to_cc(struct fuse_conn *fc)
{
return container_of(fc, struct cuse_conn, fc);
}
static struct list_head *cuse_conntbl_head(dev_t devt)
{
return &cuse_conntbl[(MAJOR(devt) + MINOR(devt)) % CUSE_CONNTBL_LEN];
}
static ssize_t cuse_read(struct file *file, char __user *buf, size_t count,
loff_t *ppos)
{
loff_t pos = 0;
struct iovec iov = { .iov_base = buf, .iov_len = count };
struct fuse_io_priv io = { .async = 0, .file = file };
return fuse_direct_io(&io, &iov, 1, count, &pos, 0);
}
static ssize_t cuse_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
loff_t pos = 0;
struct iovec iov = { .iov_base = (void __user *)buf, .iov_len = count };
struct fuse_io_priv io = { .async = 0, .file = file };
return fuse_direct_io(&io, &iov, 1, count, &pos, 1);
}
static int cuse_open(struct inode *inode, struct file *file)
{
dev_t devt = inode->i_cdev->dev;
struct cuse_conn *cc = NULL, *pos;
int rc;
mutex_lock(&cuse_lock);
list_for_each_entry(pos, cuse_conntbl_head(devt), list)
if (pos->dev->devt == devt) {
fuse_conn_get(&pos->fc);
cc = pos;
break;
}
mutex_unlock(&cuse_lock);
if (!cc)
return -ENODEV;
rc = fuse_do_open(&cc->fc, 0, file, 0);
if (rc)
fuse_conn_put(&cc->fc);
return rc;
}
static int cuse_release(struct inode *inode, struct file *file)
{
struct fuse_file *ff = file->private_data;
struct fuse_conn *fc = ff->fc;
fuse_sync_release(ff, file->f_flags);
fuse_conn_put(fc);
return 0;
}
static long cuse_file_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct fuse_file *ff = file->private_data;
struct cuse_conn *cc = fc_to_cc(ff->fc);
unsigned int flags = 0;
if (cc->unrestricted_ioctl)
flags |= FUSE_IOCTL_UNRESTRICTED;
return fuse_do_ioctl(file, cmd, arg, flags);
}
static long cuse_file_compat_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct fuse_file *ff = file->private_data;
struct cuse_conn *cc = fc_to_cc(ff->fc);
unsigned int flags = FUSE_IOCTL_COMPAT;
if (cc->unrestricted_ioctl)
flags |= FUSE_IOCTL_UNRESTRICTED;
return fuse_do_ioctl(file, cmd, arg, flags);
}
static int cuse_parse_one(char **pp, char *end, char **keyp, char **valp)
{
char *p = *pp;
char *key, *val;
while (p < end && *p == '\0')
p++;
if (p == end)
return 0;
if (end[-1] != '\0') {
printk(KERN_ERR "CUSE: info not properly terminated\n");
return -EINVAL;
}
key = val = p;
p += strlen(p);
if (valp) {
strsep(&val, "=");
if (!val)
val = key + strlen(key);
key = strstrip(key);
val = strstrip(val);
} else
key = strstrip(key);
if (!strlen(key)) {
printk(KERN_ERR "CUSE: zero length info key specified\n");
return -EINVAL;
}
*pp = p;
*keyp = key;
if (valp)
*valp = val;
return 1;
}
static int cuse_parse_devinfo(char *p, size_t len, struct cuse_devinfo *devinfo)
{
char *end = p + len;
char *uninitialized_var(key), *uninitialized_var(val);
int rc;
while (true) {
rc = cuse_parse_one(&p, end, &key, &val);
if (rc < 0)
return rc;
if (!rc)
break;
if (strcmp(key, "DEVNAME") == 0)
devinfo->name = val;
else
printk(KERN_WARNING "CUSE: unknown device info \"%s\"\n",
key);
}
if (!devinfo->name || !strlen(devinfo->name)) {
printk(KERN_ERR "CUSE: DEVNAME unspecified\n");
return -EINVAL;
}
return 0;
}
static void cuse_gendev_release(struct device *dev)
{
kfree(dev);
}
static void cuse_process_init_reply(struct fuse_conn *fc, struct fuse_req *req)
{
struct cuse_conn *cc = fc_to_cc(fc), *pos;
struct cuse_init_out *arg = req->out.args[0].value;
struct page *page = req->pages[0];
struct cuse_devinfo devinfo = { };
struct device *dev;
struct cdev *cdev;
dev_t devt;
int rc, i;
if (req->out.h.error ||
arg->major != FUSE_KERNEL_VERSION || arg->minor < 11) {
goto err;
}
fc->minor = arg->minor;
fc->max_read = max_t(unsigned, arg->max_read, 4096);
fc->max_write = max_t(unsigned, arg->max_write, 4096);
cc->unrestricted_ioctl = arg->flags & CUSE_UNRESTRICTED_IOCTL;
rc = cuse_parse_devinfo(page_address(page), req->out.args[1].size,
&devinfo);
if (rc)
goto err;
devt = MKDEV(arg->dev_major, arg->dev_minor);
if (!MAJOR(devt))
rc = alloc_chrdev_region(&devt, MINOR(devt), 1, devinfo.name);
else
rc = register_chrdev_region(devt, 1, devinfo.name);
if (rc) {
printk(KERN_ERR "CUSE: failed to register chrdev region\n");
goto err;
}
rc = -ENOMEM;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
if (!dev)
goto err_region;
device_initialize(dev);
dev_set_uevent_suppress(dev, 1);
dev->class = cuse_class;
dev->devt = devt;
dev->release = cuse_gendev_release;
dev_set_drvdata(dev, cc);
dev_set_name(dev, "%s", devinfo.name);
mutex_lock(&cuse_lock);
for (i = 0; i < CUSE_CONNTBL_LEN; ++i) {
list_for_each_entry(pos, &cuse_conntbl[i], list)
if (!strcmp(dev_name(pos->dev), dev_name(dev)))
goto err_unlock;
}
rc = device_add(dev);
if (rc)
goto err_unlock;
rc = -ENOMEM;
cdev = cdev_alloc();
if (!cdev)
goto err_unlock;
cdev->owner = THIS_MODULE;
cdev->ops = &cuse_frontend_fops;
rc = cdev_add(cdev, devt, 1);
if (rc)
goto err_cdev;
cc->dev = dev;
cc->cdev = cdev;
list_add(&cc->list, cuse_conntbl_head(devt));
mutex_unlock(&cuse_lock);
dev_set_uevent_suppress(dev, 0);
kobject_uevent(&dev->kobj, KOBJ_ADD);
out:
kfree(arg);
__free_page(page);
return;
err_cdev:
cdev_del(cdev);
err_unlock:
mutex_unlock(&cuse_lock);
put_device(dev);
err_region:
unregister_chrdev_region(devt, 1);
err:
fuse_conn_kill(fc);
goto out;
}
static int cuse_send_init(struct cuse_conn *cc)
{
int rc;
struct fuse_req *req;
struct page *page;
struct fuse_conn *fc = &cc->fc;
struct cuse_init_in *arg;
void *outarg;
BUILD_BUG_ON(CUSE_INIT_INFO_MAX > PAGE_SIZE);
req = fuse_get_req_for_background(fc, 1);
if (IS_ERR(req)) {
rc = PTR_ERR(req);
goto err;
}
rc = -ENOMEM;
page = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!page)
goto err_put_req;
outarg = kzalloc(sizeof(struct cuse_init_out), GFP_KERNEL);
if (!outarg)
goto err_free_page;
arg = &req->misc.cuse_init_in;
arg->major = FUSE_KERNEL_VERSION;
arg->minor = FUSE_KERNEL_MINOR_VERSION;
arg->flags |= CUSE_UNRESTRICTED_IOCTL;
req->in.h.opcode = CUSE_INIT;
req->in.numargs = 1;
req->in.args[0].size = sizeof(struct cuse_init_in);
req->in.args[0].value = arg;
req->out.numargs = 2;
req->out.args[0].size = sizeof(struct cuse_init_out);
req->out.args[0].value = outarg;
req->out.args[1].size = CUSE_INIT_INFO_MAX;
req->out.argvar = 1;
req->out.argpages = 1;
req->pages[0] = page;
req->page_descs[0].length = req->out.args[1].size;
req->num_pages = 1;
req->end = cuse_process_init_reply;
fuse_request_send_background(fc, req);
return 0;
err_free_page:
__free_page(page);
err_put_req:
fuse_put_request(fc, req);
err:
return rc;
}
static void cuse_fc_release(struct fuse_conn *fc)
{
struct cuse_conn *cc = fc_to_cc(fc);
kfree(cc);
}
static int cuse_channel_open(struct inode *inode, struct file *file)
{
struct cuse_conn *cc;
int rc;
cc = kzalloc(sizeof(*cc), GFP_KERNEL);
if (!cc)
return -ENOMEM;
fuse_conn_init(&cc->fc);
INIT_LIST_HEAD(&cc->list);
cc->fc.release = cuse_fc_release;
cc->fc.connected = 1;
cc->fc.initialized = 1;
rc = cuse_send_init(cc);
if (rc) {
fuse_conn_put(&cc->fc);
return rc;
}
file->private_data = &cc->fc;
return 0;
}
static int cuse_channel_release(struct inode *inode, struct file *file)
{
struct cuse_conn *cc = fc_to_cc(file->private_data);
int rc;
mutex_lock(&cuse_lock);
list_del_init(&cc->list);
mutex_unlock(&cuse_lock);
if (cc->dev)
device_unregister(cc->dev);
if (cc->cdev) {
unregister_chrdev_region(cc->cdev->dev, 1);
cdev_del(cc->cdev);
}
rc = fuse_dev_release(inode, file);
return rc;
}
static ssize_t cuse_class_waiting_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct cuse_conn *cc = dev_get_drvdata(dev);
return sprintf(buf, "%d\n", atomic_read(&cc->fc.num_waiting));
}
static ssize_t cuse_class_abort_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct cuse_conn *cc = dev_get_drvdata(dev);
fuse_abort_conn(&cc->fc);
return count;
}
static int __init cuse_init(void)
{
int i, rc;
for (i = 0; i < CUSE_CONNTBL_LEN; i++)
INIT_LIST_HEAD(&cuse_conntbl[i]);
cuse_channel_fops = fuse_dev_operations;
cuse_channel_fops.owner = THIS_MODULE;
cuse_channel_fops.open = cuse_channel_open;
cuse_channel_fops.release = cuse_channel_release;
cuse_class = class_create(THIS_MODULE, "cuse");
if (IS_ERR(cuse_class))
return PTR_ERR(cuse_class);
cuse_class->dev_groups = cuse_class_dev_groups;
rc = misc_register(&cuse_miscdev);
if (rc) {
class_destroy(cuse_class);
return rc;
}
return 0;
}
static void __exit cuse_exit(void)
{
misc_deregister(&cuse_miscdev);
class_destroy(cuse_class);
}
