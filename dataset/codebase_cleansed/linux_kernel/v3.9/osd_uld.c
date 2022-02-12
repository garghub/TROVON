static ssize_t osdname_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct osd_uld_device *ould = container_of(dev, struct osd_uld_device,
class_dev);
return sprintf(buf, "%s\n", ould->odi.osdname);
}
static ssize_t systemid_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct osd_uld_device *ould = container_of(dev, struct osd_uld_device,
class_dev);
memcpy(buf, ould->odi.systemid, ould->odi.systemid_len);
return ould->odi.systemid_len;
}
static int osd_uld_open(struct inode *inode, struct file *file)
{
struct osd_uld_device *oud = container_of(inode->i_cdev,
struct osd_uld_device, cdev);
get_device(&oud->class_dev);
file->private_data = oud;
OSD_DEBUG("osd_uld_open %p\n", oud);
return 0;
}
static int osd_uld_release(struct inode *inode, struct file *file)
{
struct osd_uld_device *oud = file->private_data;
OSD_DEBUG("osd_uld_release %p\n", file->private_data);
file->private_data = NULL;
put_device(&oud->class_dev);
return 0;
}
int osduld_register_test(unsigned ioctl, do_test_fn *do_test)
{
if (g_test_ioctl)
return -EINVAL;
g_test_ioctl = ioctl;
g_do_test = do_test;
return 0;
}
void osduld_unregister_test(unsigned ioctl)
{
if (ioctl == g_test_ioctl) {
g_test_ioctl = 0;
g_do_test = NULL;
}
}
static do_test_fn *_find_ioctl(unsigned cmd)
{
if (g_test_ioctl == cmd)
return g_do_test;
else
return NULL;
}
static long osd_uld_ioctl(struct file *file, unsigned int cmd,
unsigned long arg)
{
struct osd_uld_device *oud = file->private_data;
int ret;
do_test_fn *do_test;
do_test = _find_ioctl(cmd);
if (do_test)
ret = do_test(&oud->od, cmd, arg);
else {
OSD_ERR("Unknown ioctl %d: osd_uld_device=%p\n", cmd, oud);
ret = -ENOIOCTLCMD;
}
return ret;
}
struct osd_dev *osduld_path_lookup(const char *name)
{
struct osd_uld_device *oud;
struct osd_dev_handle *odh;
struct file *file;
int error;
if (!name || !*name) {
OSD_ERR("Mount with !path || !*path\n");
return ERR_PTR(-EINVAL);
}
odh = kzalloc(sizeof(*odh), GFP_KERNEL);
if (unlikely(!odh))
return ERR_PTR(-ENOMEM);
file = filp_open(name, O_RDWR, 0);
if (IS_ERR(file)) {
error = PTR_ERR(file);
goto free_od;
}
if (file->f_op != &osd_fops){
error = -EINVAL;
goto close_file;
}
oud = file->private_data;
odh->od = oud->od;
odh->file = file;
odh->oud = oud;
return &odh->od;
close_file:
fput(file);
free_od:
kfree(odh);
return ERR_PTR(error);
}
static inline bool _the_same_or_null(const u8 *a1, unsigned a1_len,
const u8 *a2, unsigned a2_len)
{
if (!a2_len)
return true;
if (a1_len != a2_len)
return false;
return 0 == memcmp(a1, a2, a1_len);
}
static int _match_odi(struct device *dev, const void *find_data)
{
struct osd_uld_device *oud = container_of(dev, struct osd_uld_device,
class_dev);
const struct osd_dev_info *odi = find_data;
if (_the_same_or_null(oud->odi.systemid, oud->odi.systemid_len,
odi->systemid, odi->systemid_len) &&
_the_same_or_null(oud->odi.osdname, oud->odi.osdname_len,
odi->osdname, odi->osdname_len)) {
OSD_DEBUG("found device sysid_len=%d osdname=%d\n",
odi->systemid_len, odi->osdname_len);
return 1;
} else {
return 0;
}
}
struct osd_dev *osduld_info_lookup(const struct osd_dev_info *odi)
{
struct device *dev = class_find_device(&osd_uld_class, NULL, odi, _match_odi);
if (likely(dev)) {
struct osd_dev_handle *odh = kzalloc(sizeof(*odh), GFP_KERNEL);
struct osd_uld_device *oud = container_of(dev,
struct osd_uld_device, class_dev);
if (unlikely(!odh)) {
put_device(dev);
return ERR_PTR(-ENOMEM);
}
odh->od = oud->od;
odh->oud = oud;
return &odh->od;
}
return ERR_PTR(-ENODEV);
}
void osduld_put_device(struct osd_dev *od)
{
if (od && !IS_ERR(od)) {
struct osd_dev_handle *odh =
container_of(od, struct osd_dev_handle, od);
struct osd_uld_device *oud = odh->oud;
BUG_ON(od->scsi_device != oud->od.scsi_device);
if (odh->file) {
get_device(&oud->class_dev);
fput(odh->file);
}
put_device(&oud->class_dev);
kfree(odh);
}
}
const struct osd_dev_info *osduld_device_info(struct osd_dev *od)
{
struct osd_dev_handle *odh =
container_of(od, struct osd_dev_handle, od);
return &odh->oud->odi;
}
bool osduld_device_same(struct osd_dev *od, const struct osd_dev_info *odi)
{
struct osd_dev_handle *odh =
container_of(od, struct osd_dev_handle, od);
struct osd_uld_device *oud = odh->oud;
return (oud->odi.systemid_len == odi->systemid_len) &&
_the_same_or_null(oud->odi.systemid, oud->odi.systemid_len,
odi->systemid, odi->systemid_len) &&
(oud->odi.osdname_len == odi->osdname_len) &&
_the_same_or_null(oud->odi.osdname, oud->odi.osdname_len,
odi->osdname, odi->osdname_len);
}
static int __detect_osd(struct osd_uld_device *oud)
{
struct scsi_device *scsi_device = oud->od.scsi_device;
char caps[OSD_CAP_LEN];
int error;
OSD_DEBUG("start scsi_test_unit_ready %p %p %p\n",
oud, scsi_device, scsi_device->request_queue);
error = scsi_test_unit_ready(scsi_device, 10*HZ, 5, NULL);
if (error)
OSD_ERR("warning: scsi_test_unit_ready failed\n");
osd_sec_init_nosec_doall_caps(caps, &osd_root_object, false, true);
if (osd_auto_detect_ver(&oud->od, caps, &oud->odi))
return -ENODEV;
return 0;
}
static void __remove(struct device *dev)
{
struct osd_uld_device *oud = container_of(dev, struct osd_uld_device,
class_dev);
struct scsi_device *scsi_device = oud->od.scsi_device;
kfree(oud->odi.osdname);
if (oud->cdev.owner)
cdev_del(&oud->cdev);
osd_dev_fini(&oud->od);
scsi_device_put(scsi_device);
OSD_INFO("osd_remove %s\n",
oud->disk ? oud->disk->disk_name : NULL);
if (oud->disk)
put_disk(oud->disk);
ida_remove(&osd_minor_ida, oud->minor);
kfree(oud);
}
static int osd_probe(struct device *dev)
{
struct scsi_device *scsi_device = to_scsi_device(dev);
struct gendisk *disk;
struct osd_uld_device *oud;
int minor;
int error;
if (scsi_device->type != TYPE_OSD)
return -ENODEV;
do {
if (!ida_pre_get(&osd_minor_ida, GFP_KERNEL))
return -ENODEV;
error = ida_get_new(&osd_minor_ida, &minor);
} while (error == -EAGAIN);
if (error)
return error;
if (minor >= SCSI_OSD_MAX_MINOR) {
error = -EBUSY;
goto err_retract_minor;
}
error = -ENOMEM;
oud = kzalloc(sizeof(*oud), GFP_KERNEL);
if (NULL == oud)
goto err_retract_minor;
dev_set_drvdata(dev, oud);
oud->minor = minor;
disk = alloc_disk(1);
if (!disk) {
OSD_ERR("alloc_disk failed\n");
goto err_free_osd;
}
disk->major = SCSI_OSD_MAJOR;
disk->first_minor = oud->minor;
sprintf(disk->disk_name, "osd%d", oud->minor);
oud->disk = disk;
scsi_device_get(scsi_device);
osd_dev_init(&oud->od, scsi_device);
error = __detect_osd(oud);
if (error) {
OSD_ERR("osd detection failed, non-compatible OSD device\n");
goto err_put_disk;
}
cdev_init(&oud->cdev, &osd_fops);
oud->cdev.owner = THIS_MODULE;
error = cdev_add(&oud->cdev,
MKDEV(SCSI_OSD_MAJOR, oud->minor), 1);
if (error) {
OSD_ERR("cdev_add failed\n");
goto err_put_disk;
}
oud->class_dev.devt = oud->cdev.dev;
oud->class_dev.class = &osd_uld_class;
oud->class_dev.parent = dev;
oud->class_dev.release = __remove;
error = dev_set_name(&oud->class_dev, disk->disk_name);
if (error) {
OSD_ERR("dev_set_name failed => %d\n", error);
goto err_put_cdev;
}
error = device_register(&oud->class_dev);
if (error) {
OSD_ERR("device_register failed => %d\n", error);
goto err_put_cdev;
}
get_device(&oud->class_dev);
OSD_INFO("osd_probe %s\n", disk->disk_name);
return 0;
err_put_cdev:
cdev_del(&oud->cdev);
err_put_disk:
scsi_device_put(scsi_device);
put_disk(disk);
err_free_osd:
dev_set_drvdata(dev, NULL);
kfree(oud);
err_retract_minor:
ida_remove(&osd_minor_ida, minor);
return error;
}
static int osd_remove(struct device *dev)
{
struct scsi_device *scsi_device = to_scsi_device(dev);
struct osd_uld_device *oud = dev_get_drvdata(dev);
if (!oud || (oud->od.scsi_device != scsi_device)) {
OSD_ERR("Half cooked osd-device %p,%p || %p!=%p",
dev, oud, oud ? oud->od.scsi_device : NULL,
scsi_device);
}
device_unregister(&oud->class_dev);
put_device(&oud->class_dev);
return 0;
}
static int __init osd_uld_init(void)
{
int err;
err = class_register(&osd_uld_class);
if (err) {
OSD_ERR("Unable to register sysfs class => %d\n", err);
return err;
}
err = register_chrdev_region(MKDEV(SCSI_OSD_MAJOR, 0),
SCSI_OSD_MAX_MINOR, osd_name);
if (err) {
OSD_ERR("Unable to register major %d for osd ULD => %d\n",
SCSI_OSD_MAJOR, err);
goto err_out;
}
err = scsi_register_driver(&osd_driver.gendrv);
if (err) {
OSD_ERR("scsi_register_driver failed => %d\n", err);
goto err_out_chrdev;
}
OSD_INFO("LOADED %s\n", osd_version_string);
return 0;
err_out_chrdev:
unregister_chrdev_region(MKDEV(SCSI_OSD_MAJOR, 0), SCSI_OSD_MAX_MINOR);
err_out:
class_unregister(&osd_uld_class);
return err;
}
static void __exit osd_uld_exit(void)
{
scsi_unregister_driver(&osd_driver.gendrv);
unregister_chrdev_region(MKDEV(SCSI_OSD_MAJOR, 0), SCSI_OSD_MAX_MINOR);
class_unregister(&osd_uld_class);
OSD_INFO("UNLOADED %s\n", osd_version_string);
}
