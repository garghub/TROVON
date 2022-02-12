int lustre_get_jobid(char *jobid)
{
memset(jobid, 0, JOBSTATS_JOBID_SIZE);
if (strcmp(obd_jobid_var, JOBSTATS_DISABLE) == 0)
return 0;
if (strcmp(obd_jobid_var, JOBSTATS_PROCNAME_UID) == 0) {
snprintf(jobid, JOBSTATS_JOBID_SIZE, "%s.%u",
current_comm(),
from_kuid(&init_user_ns, current_fsuid()));
return 0;
}
if (strcmp(obd_jobid_var, JOBSTATS_NODELOCAL) == 0) {
strcpy(jobid, obd_jobid_node);
return 0;
}
return -ENOENT;
}
int obd_alloc_fail(const void *ptr, const char *name, const char *type,
size_t size, const char *file, int line)
{
if (ptr == NULL ||
(cfs_rand() & OBD_ALLOC_FAIL_MASK) < obd_alloc_fail_rate) {
CERROR("%s%salloc of %s (%llu bytes) failed at %s:%d\n",
ptr ? "force " :"", type, name, (__u64)size, file,
line);
CERROR("%llu total bytes and %llu total pages (%llu bytes) allocated by Lustre, %d total bytes by LNET\n",
obd_memory_sum(),
obd_pages_sum() << PAGE_CACHE_SHIFT,
obd_pages_sum(),
atomic_read(&libcfs_kmemory));
return 1;
}
return 0;
}
static inline void obd_data2conn(struct lustre_handle *conn,
struct obd_ioctl_data *data)
{
memset(conn, 0, sizeof(*conn));
conn->cookie = data->ioc_cookie;
}
static inline void obd_conn2data(struct obd_ioctl_data *data,
struct lustre_handle *conn)
{
data->ioc_cookie = conn->cookie;
}
int class_resolve_dev_name(__u32 len, const char *name)
{
int rc;
int dev;
if (!len || !name) {
CERROR("No name passed,!\n");
rc = -EINVAL;
goto out;
}
if (name[len - 1] != 0) {
CERROR("Name not nul terminated!\n");
rc = -EINVAL;
goto out;
}
CDEBUG(D_IOCTL, "device name %s\n", name);
dev = class_name2dev(name);
if (dev == -1) {
CDEBUG(D_IOCTL, "No device for name %s!\n", name);
rc = -EINVAL;
goto out;
}
CDEBUG(D_IOCTL, "device name %s, dev %d\n", name, dev);
rc = dev;
out:
return rc;
}
int class_handle_ioctl(unsigned int cmd, unsigned long arg)
{
char *buf = NULL;
struct obd_ioctl_data *data;
struct libcfs_debug_ioctl_data *debug_data;
struct obd_device *obd = NULL;
int err = 0, len = 0;
if (cmd == LIBCFS_IOC_DEBUG_MASK) {
debug_data = (struct libcfs_debug_ioctl_data *)arg;
libcfs_subsystem_debug = debug_data->subs;
libcfs_debug = debug_data->debug;
return 0;
}
CDEBUG(D_IOCTL, "cmd = %x\n", cmd);
if (obd_ioctl_getdata(&buf, &len, (void *)arg)) {
CERROR("OBD ioctl: data error\n");
return -EINVAL;
}
data = (struct obd_ioctl_data *)buf;
switch (cmd) {
case OBD_IOC_PROCESS_CFG: {
struct lustre_cfg *lcfg;
if (!data->ioc_plen1 || !data->ioc_pbuf1) {
CERROR("No config buffer passed!\n");
err = -EINVAL;
goto out;
}
lcfg = kzalloc(data->ioc_plen1, GFP_NOFS);
if (lcfg == NULL) {
err = -ENOMEM;
goto out;
}
err = copy_from_user(lcfg, data->ioc_pbuf1,
data->ioc_plen1);
if (!err)
err = lustre_cfg_sanity_check(lcfg, data->ioc_plen1);
if (!err)
err = class_process_config(lcfg);
kfree(lcfg);
goto out;
}
case OBD_GET_VERSION:
if (!data->ioc_inlbuf1) {
CERROR("No buffer passed in ioctl\n");
err = -EINVAL;
goto out;
}
if (strlen(BUILD_VERSION) + 1 > data->ioc_inllen1) {
CERROR("ioctl buffer too small to hold version\n");
err = -EINVAL;
goto out;
}
memcpy(data->ioc_bulk, BUILD_VERSION,
strlen(BUILD_VERSION) + 1);
err = obd_ioctl_popdata((void *)arg, data, len);
if (err)
err = -EFAULT;
goto out;
case OBD_IOC_NAME2DEV: {
int dev;
dev = class_resolve_dev_name(data->ioc_inllen1,
data->ioc_inlbuf1);
data->ioc_dev = dev;
if (dev < 0) {
err = -EINVAL;
goto out;
}
err = obd_ioctl_popdata((void *)arg, data, sizeof(*data));
if (err)
err = -EFAULT;
goto out;
}
case OBD_IOC_UUID2DEV: {
int dev;
struct obd_uuid uuid;
if (!data->ioc_inllen1 || !data->ioc_inlbuf1) {
CERROR("No UUID passed!\n");
err = -EINVAL;
goto out;
}
if (data->ioc_inlbuf1[data->ioc_inllen1 - 1] != 0) {
CERROR("UUID not NUL terminated!\n");
err = -EINVAL;
goto out;
}
CDEBUG(D_IOCTL, "device name %s\n", data->ioc_inlbuf1);
obd_str2uuid(&uuid, data->ioc_inlbuf1);
dev = class_uuid2dev(&uuid);
data->ioc_dev = dev;
if (dev == -1) {
CDEBUG(D_IOCTL, "No device for UUID %s!\n",
data->ioc_inlbuf1);
err = -EINVAL;
goto out;
}
CDEBUG(D_IOCTL, "device name %s, dev %d\n", data->ioc_inlbuf1,
dev);
err = obd_ioctl_popdata((void *)arg, data, sizeof(*data));
if (err)
err = -EFAULT;
goto out;
}
case OBD_IOC_CLOSE_UUID: {
CDEBUG(D_IOCTL, "closing all connections to uuid %s (NOOP)\n",
data->ioc_inlbuf1);
err = 0;
goto out;
}
case OBD_IOC_GETDEVICE: {
int index = data->ioc_count;
char *status, *str;
if (!data->ioc_inlbuf1) {
CERROR("No buffer passed in ioctl\n");
err = -EINVAL;
goto out;
}
if (data->ioc_inllen1 < 128) {
CERROR("ioctl buffer too small to hold version\n");
err = -EINVAL;
goto out;
}
obd = class_num2obd(index);
if (!obd) {
err = -ENOENT;
goto out;
}
if (obd->obd_stopping)
status = "ST";
else if (obd->obd_set_up)
status = "UP";
else if (obd->obd_attached)
status = "AT";
else
status = "--";
str = (char *)data->ioc_bulk;
snprintf(str, len - sizeof(*data), "%3d %s %s %s %s %d",
(int)index, status, obd->obd_type->typ_name,
obd->obd_name, obd->obd_uuid.uuid,
atomic_read(&obd->obd_refcount));
err = obd_ioctl_popdata((void *)arg, data, len);
err = 0;
goto out;
}
}
if (data->ioc_dev == OBD_DEV_BY_DEVNAME) {
if (data->ioc_inllen4 <= 0 || data->ioc_inlbuf4 == NULL) {
err = -EINVAL;
goto out;
}
if (strnlen(data->ioc_inlbuf4, MAX_OBD_NAME) >= MAX_OBD_NAME) {
err = -EINVAL;
goto out;
}
obd = class_name2obd(data->ioc_inlbuf4);
} else if (data->ioc_dev < class_devno_max()) {
obd = class_num2obd(data->ioc_dev);
} else {
CERROR("OBD ioctl: No device\n");
err = -EINVAL;
goto out;
}
if (obd == NULL) {
CERROR("OBD ioctl : No Device %d\n", data->ioc_dev);
err = -EINVAL;
goto out;
}
LASSERT(obd->obd_magic == OBD_DEVICE_MAGIC);
if (!obd->obd_set_up || obd->obd_stopping) {
CERROR("OBD ioctl: device not setup %d\n", data->ioc_dev);
err = -EINVAL;
goto out;
}
switch (cmd) {
case OBD_IOC_NO_TRANSNO: {
if (!obd->obd_attached) {
CERROR("Device %d not attached\n", obd->obd_minor);
err = -ENODEV;
goto out;
}
CDEBUG(D_HA, "%s: disabling committed-transno notification\n",
obd->obd_name);
obd->obd_no_transno = 1;
err = 0;
goto out;
}
default: {
err = obd_iocontrol(cmd, obd->obd_self_export, len, data, NULL);
if (err)
goto out;
err = obd_ioctl_popdata((void *)arg, data, len);
if (err)
err = -EFAULT;
goto out;
}
}
out:
if (buf)
obd_ioctl_freedata(buf, len);
return err;
}
int obd_init_checks(void)
{
__u64 u64val, div64val;
char buf[64];
int len, ret = 0;
CDEBUG(D_INFO, "LPU64=%s, LPD64=%s, LPX64=%s\n", "%llu", "%lld", "%#llx");
CDEBUG(D_INFO, "OBD_OBJECT_EOF = %#llx\n", (__u64)OBD_OBJECT_EOF);
u64val = OBD_OBJECT_EOF;
CDEBUG(D_INFO, "u64val OBD_OBJECT_EOF = %#llx\n", u64val);
if (u64val != OBD_OBJECT_EOF) {
CERROR("__u64 %#llx(%d) != 0xffffffffffffffff\n",
u64val, (int)sizeof(u64val));
ret = -EINVAL;
}
len = snprintf(buf, sizeof(buf), "%#llx", u64val);
if (len != 18) {
CWARN("LPX64 wrong length! strlen(%s)=%d != 18\n", buf, len);
ret = -EINVAL;
}
div64val = OBD_OBJECT_EOF;
CDEBUG(D_INFO, "u64val OBD_OBJECT_EOF = %#llx\n", u64val);
if (u64val != OBD_OBJECT_EOF) {
CERROR("__u64 %#llx(%d) != 0xffffffffffffffff\n",
u64val, (int)sizeof(u64val));
ret = -EOVERFLOW;
}
if (u64val >> 8 != OBD_OBJECT_EOF >> 8) {
CERROR("__u64 %#llx(%d) != 0xffffffffffffffff\n",
u64val, (int)sizeof(u64val));
return -EOVERFLOW;
}
if (do_div(div64val, 256) != (u64val & 255)) {
CERROR("do_div(%#llx,256) != %llu\n", u64val, u64val &255);
return -EOVERFLOW;
}
if (u64val >> 8 != div64val) {
CERROR("do_div(%#llx,256) %llu != %llu\n",
u64val, div64val, u64val >> 8);
return -EOVERFLOW;
}
len = snprintf(buf, sizeof(buf), "%#llx", u64val);
if (len != 18) {
CWARN("LPX64 wrong length! strlen(%s)=%d != 18\n", buf, len);
ret = -EINVAL;
}
len = snprintf(buf, sizeof(buf), "%llu", u64val);
if (len != 20) {
CWARN("LPU64 wrong length! strlen(%s)=%d != 20\n", buf, len);
ret = -EINVAL;
}
len = snprintf(buf, sizeof(buf), "%lld", u64val);
if (len != 2) {
CWARN("LPD64 wrong length! strlen(%s)=%d != 2\n", buf, len);
ret = -EINVAL;
}
if ((u64val & ~CFS_PAGE_MASK) >= PAGE_CACHE_SIZE) {
CWARN("mask failed: u64val %llu >= %llu\n", u64val,
(__u64)PAGE_CACHE_SIZE);
ret = -EINVAL;
}
return ret;
}
static int __init init_obdclass(void)
{
int i, err;
int lustre_register_fs(void);
for (i = CAPA_SITE_CLIENT; i < CAPA_SITE_MAX; i++)
INIT_LIST_HEAD(&capa_list[i]);
LCONSOLE_INFO("Lustre: Build Version: "BUILD_VERSION"\n");
spin_lock_init(&obd_types_lock);
obd_zombie_impexp_init();
obd_memory = lprocfs_alloc_stats(OBD_STATS_NUM,
LPROCFS_STATS_FLAG_NONE |
LPROCFS_STATS_FLAG_IRQ_SAFE);
if (obd_memory == NULL) {
CERROR("kmalloc of 'obd_memory' failed\n");
return -ENOMEM;
}
lprocfs_counter_init(obd_memory, OBD_MEMORY_STAT,
LPROCFS_CNTR_AVGMINMAX,
"memused", "bytes");
lprocfs_counter_init(obd_memory, OBD_MEMORY_PAGES_STAT,
LPROCFS_CNTR_AVGMINMAX,
"pagesused", "pages");
err = obd_init_checks();
if (err == -EOVERFLOW)
return err;
class_init_uuidlist();
err = class_handle_init();
if (err)
return err;
INIT_LIST_HEAD(&obd_types);
err = misc_register(&obd_psdev);
if (err) {
CERROR("cannot register %d err %d\n", OBD_DEV_MINOR, err);
return err;
}
for (i = 0; i < class_devno_max(); i++)
obd_devs[i] = NULL;
if (totalram_pages <= 512 << (20 - PAGE_CACHE_SHIFT))
obd_max_dirty_pages = totalram_pages / 4;
else
obd_max_dirty_pages = totalram_pages / 2;
err = obd_init_caches();
if (err)
return err;
obd_sysctl_init();
err = class_procfs_init();
if (err)
return err;
err = lu_global_init();
if (err)
return err;
err = cl_global_init();
if (err != 0)
return err;
err = llog_info_init();
if (err)
return err;
err = lustre_register_fs();
return err;
}
void obd_update_maxusage(void)
{
__u64 max1, max2;
max1 = obd_pages_sum();
max2 = obd_memory_sum();
spin_lock(&obd_updatemax_lock);
if (max1 > obd_max_pages)
obd_max_pages = max1;
if (max2 > obd_max_alloc)
obd_max_alloc = max2;
spin_unlock(&obd_updatemax_lock);
}
__u64 obd_memory_max(void)
{
__u64 ret;
spin_lock(&obd_updatemax_lock);
ret = obd_max_alloc;
spin_unlock(&obd_updatemax_lock);
return ret;
}
__u64 obd_pages_max(void)
{
__u64 ret;
spin_lock(&obd_updatemax_lock);
ret = obd_max_pages;
spin_unlock(&obd_updatemax_lock);
return ret;
}
static void cleanup_obdclass(void)
{
int i;
int lustre_unregister_fs(void);
__u64 memory_leaked, pages_leaked;
__u64 memory_max, pages_max;
lustre_unregister_fs();
misc_deregister(&obd_psdev);
for (i = 0; i < class_devno_max(); i++) {
struct obd_device *obd = class_num2obd(i);
if (obd && obd->obd_set_up &&
OBT(obd) && OBP(obd, detach)) {
LASSERT(obd->obd_magic == OBD_DEVICE_MAGIC);
OBP(obd, detach)(obd);
}
}
llog_info_fini();
cl_global_fini();
lu_global_fini();
obd_cleanup_caches();
obd_sysctl_clean();
class_procfs_clean();
class_handle_cleanup();
class_exit_uuidlist();
obd_zombie_impexp_stop();
memory_leaked = obd_memory_sum();
pages_leaked = obd_pages_sum();
memory_max = obd_memory_max();
pages_max = obd_pages_max();
lprocfs_free_stats(&obd_memory);
CDEBUG((memory_leaked) ? D_ERROR : D_INFO,
"obd_memory max: %llu, leaked: %llu\n",
memory_max, memory_leaked);
CDEBUG((pages_leaked) ? D_ERROR : D_INFO,
"obd_memory_pages max: %llu, leaked: %llu\n",
pages_max, pages_leaked);
}
