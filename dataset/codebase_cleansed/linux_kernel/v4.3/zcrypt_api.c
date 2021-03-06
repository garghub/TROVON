static ssize_t zcrypt_type_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zcrypt_device *zdev = to_ap_dev(dev)->private;
return snprintf(buf, PAGE_SIZE, "%s\n", zdev->type_string);
}
static ssize_t zcrypt_online_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct zcrypt_device *zdev = to_ap_dev(dev)->private;
return snprintf(buf, PAGE_SIZE, "%d\n", zdev->online);
}
static ssize_t zcrypt_online_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct zcrypt_device *zdev = to_ap_dev(dev)->private;
int online;
if (sscanf(buf, "%d\n", &online) != 1 || online < 0 || online > 1)
return -EINVAL;
zdev->online = online;
ZCRYPT_DBF_DEV(DBF_INFO, zdev, "dev%04xo%dman", zdev->ap_dev->qid,
zdev->online);
if (!online)
ap_flush_queue(zdev->ap_dev);
return count;
}
static inline int zcrypt_process_rescan(void)
{
if (atomic_read(&zcrypt_rescan_req)) {
atomic_set(&zcrypt_rescan_req, 0);
atomic_inc(&zcrypt_rescan_count);
ap_bus_force_rescan();
ZCRYPT_DBF_COMMON(DBF_INFO, "rescan%07d",
atomic_inc_return(&zcrypt_rescan_count));
return 1;
}
return 0;
}
static void __zcrypt_increase_preference(struct zcrypt_device *zdev)
{
struct zcrypt_device *tmp;
struct list_head *l;
if (zdev->speed_rating == 0)
return;
for (l = zdev->list.prev; l != &zcrypt_device_list; l = l->prev) {
tmp = list_entry(l, struct zcrypt_device, list);
if ((tmp->request_count + 1) * tmp->speed_rating <=
(zdev->request_count + 1) * zdev->speed_rating &&
tmp->speed_rating != 0)
break;
}
if (l == zdev->list.prev)
return;
list_move(&zdev->list, l);
}
static void __zcrypt_decrease_preference(struct zcrypt_device *zdev)
{
struct zcrypt_device *tmp;
struct list_head *l;
if (zdev->speed_rating == 0)
return;
for (l = zdev->list.next; l != &zcrypt_device_list; l = l->next) {
tmp = list_entry(l, struct zcrypt_device, list);
if ((tmp->request_count + 1) * tmp->speed_rating >
(zdev->request_count + 1) * zdev->speed_rating ||
tmp->speed_rating == 0)
break;
}
if (l == zdev->list.next)
return;
list_move_tail(&zdev->list, l);
}
static void zcrypt_device_release(struct kref *kref)
{
struct zcrypt_device *zdev =
container_of(kref, struct zcrypt_device, refcount);
zcrypt_device_free(zdev);
}
void zcrypt_device_get(struct zcrypt_device *zdev)
{
kref_get(&zdev->refcount);
}
int zcrypt_device_put(struct zcrypt_device *zdev)
{
return kref_put(&zdev->refcount, zcrypt_device_release);
}
struct zcrypt_device *zcrypt_device_alloc(size_t max_response_size)
{
struct zcrypt_device *zdev;
zdev = kzalloc(sizeof(struct zcrypt_device), GFP_KERNEL);
if (!zdev)
return NULL;
zdev->reply.message = kmalloc(max_response_size, GFP_KERNEL);
if (!zdev->reply.message)
goto out_free;
zdev->reply.length = max_response_size;
spin_lock_init(&zdev->lock);
INIT_LIST_HEAD(&zdev->list);
zdev->dbf_area = zcrypt_dbf_devices;
return zdev;
out_free:
kfree(zdev);
return NULL;
}
void zcrypt_device_free(struct zcrypt_device *zdev)
{
kfree(zdev->reply.message);
kfree(zdev);
}
int zcrypt_device_register(struct zcrypt_device *zdev)
{
int rc;
if (!zdev->ops)
return -ENODEV;
rc = sysfs_create_group(&zdev->ap_dev->device.kobj,
&zcrypt_device_attr_group);
if (rc)
goto out;
get_device(&zdev->ap_dev->device);
kref_init(&zdev->refcount);
spin_lock_bh(&zcrypt_device_lock);
zdev->online = 1;
ZCRYPT_DBF_DEV(DBF_INFO, zdev, "dev%04xo%dreg", zdev->ap_dev->qid,
zdev->online);
list_add_tail(&zdev->list, &zcrypt_device_list);
__zcrypt_increase_preference(zdev);
zcrypt_device_count++;
spin_unlock_bh(&zcrypt_device_lock);
if (zdev->ops->rng) {
rc = zcrypt_rng_device_add();
if (rc)
goto out_unregister;
}
return 0;
out_unregister:
spin_lock_bh(&zcrypt_device_lock);
zcrypt_device_count--;
list_del_init(&zdev->list);
spin_unlock_bh(&zcrypt_device_lock);
sysfs_remove_group(&zdev->ap_dev->device.kobj,
&zcrypt_device_attr_group);
put_device(&zdev->ap_dev->device);
zcrypt_device_put(zdev);
out:
return rc;
}
void zcrypt_device_unregister(struct zcrypt_device *zdev)
{
if (zdev->ops->rng)
zcrypt_rng_device_remove();
spin_lock_bh(&zcrypt_device_lock);
zcrypt_device_count--;
list_del_init(&zdev->list);
spin_unlock_bh(&zcrypt_device_lock);
sysfs_remove_group(&zdev->ap_dev->device.kobj,
&zcrypt_device_attr_group);
put_device(&zdev->ap_dev->device);
zcrypt_device_put(zdev);
}
void zcrypt_msgtype_register(struct zcrypt_ops *zops)
{
if (zops->owner) {
spin_lock_bh(&zcrypt_ops_list_lock);
list_add_tail(&zops->list, &zcrypt_ops_list);
spin_unlock_bh(&zcrypt_ops_list_lock);
}
}
void zcrypt_msgtype_unregister(struct zcrypt_ops *zops)
{
spin_lock_bh(&zcrypt_ops_list_lock);
list_del_init(&zops->list);
spin_unlock_bh(&zcrypt_ops_list_lock);
}
static inline
struct zcrypt_ops *__ops_lookup(unsigned char *name, int variant)
{
struct zcrypt_ops *zops;
int found = 0;
spin_lock_bh(&zcrypt_ops_list_lock);
list_for_each_entry(zops, &zcrypt_ops_list, list) {
if ((zops->variant == variant) &&
(!strncmp(zops->owner->name, name, MODULE_NAME_LEN))) {
found = 1;
break;
}
}
if (!found || !try_module_get(zops->owner))
zops = NULL;
spin_unlock_bh(&zcrypt_ops_list_lock);
return zops;
}
struct zcrypt_ops *zcrypt_msgtype_request(unsigned char *name, int variant)
{
struct zcrypt_ops *zops = NULL;
zops = __ops_lookup(name, variant);
if (!zops) {
request_module("%s", name);
zops = __ops_lookup(name, variant);
}
return zops;
}
void zcrypt_msgtype_release(struct zcrypt_ops *zops)
{
if (zops)
module_put(zops->owner);
}
static ssize_t zcrypt_read(struct file *filp, char __user *buf,
size_t count, loff_t *f_pos)
{
return -EPERM;
}
static ssize_t zcrypt_write(struct file *filp, const char __user *buf,
size_t count, loff_t *f_pos)
{
return -EPERM;
}
static int zcrypt_open(struct inode *inode, struct file *filp)
{
atomic_inc(&zcrypt_open_count);
return nonseekable_open(inode, filp);
}
static int zcrypt_release(struct inode *inode, struct file *filp)
{
atomic_dec(&zcrypt_open_count);
return 0;
}
static long zcrypt_rsa_modexpo(struct ica_rsa_modexpo *mex)
{
struct zcrypt_device *zdev;
int rc;
if (mex->outputdatalength < mex->inputdatalength)
return -EINVAL;
mex->outputdatalength = mex->inputdatalength;
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list) {
if (!zdev->online ||
!zdev->ops->rsa_modexpo ||
zdev->min_mod_size > mex->inputdatalength ||
zdev->max_mod_size < mex->inputdatalength)
continue;
zcrypt_device_get(zdev);
get_device(&zdev->ap_dev->device);
zdev->request_count++;
__zcrypt_decrease_preference(zdev);
if (try_module_get(zdev->ap_dev->drv->driver.owner)) {
spin_unlock_bh(&zcrypt_device_lock);
rc = zdev->ops->rsa_modexpo(zdev, mex);
spin_lock_bh(&zcrypt_device_lock);
module_put(zdev->ap_dev->drv->driver.owner);
}
else
rc = -EAGAIN;
zdev->request_count--;
__zcrypt_increase_preference(zdev);
put_device(&zdev->ap_dev->device);
zcrypt_device_put(zdev);
spin_unlock_bh(&zcrypt_device_lock);
return rc;
}
spin_unlock_bh(&zcrypt_device_lock);
return -ENODEV;
}
static long zcrypt_rsa_crt(struct ica_rsa_modexpo_crt *crt)
{
struct zcrypt_device *zdev;
unsigned long long z1, z2, z3;
int rc, copied;
if (crt->outputdatalength < crt->inputdatalength ||
(crt->inputdatalength & 1))
return -EINVAL;
crt->outputdatalength = crt->inputdatalength;
copied = 0;
restart:
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list) {
if (!zdev->online ||
!zdev->ops->rsa_modexpo_crt ||
zdev->min_mod_size > crt->inputdatalength ||
zdev->max_mod_size < crt->inputdatalength)
continue;
if (zdev->short_crt && crt->inputdatalength > 240) {
if (copied == 0) {
unsigned int len;
spin_unlock_bh(&zcrypt_device_lock);
if (crt->inputdatalength <= 256)
len = crt->inputdatalength / 2 - 120;
else
len = 8;
if (len > sizeof(z1))
return -EFAULT;
z1 = z2 = z3 = 0;
if (copy_from_user(&z1, crt->np_prime, len) ||
copy_from_user(&z2, crt->bp_key, len) ||
copy_from_user(&z3, crt->u_mult_inv, len))
return -EFAULT;
z1 = z2 = z3 = 0;
copied = 1;
goto restart;
}
if (z1 != 0ULL || z2 != 0ULL || z3 != 0ULL)
continue;
}
zcrypt_device_get(zdev);
get_device(&zdev->ap_dev->device);
zdev->request_count++;
__zcrypt_decrease_preference(zdev);
if (try_module_get(zdev->ap_dev->drv->driver.owner)) {
spin_unlock_bh(&zcrypt_device_lock);
rc = zdev->ops->rsa_modexpo_crt(zdev, crt);
spin_lock_bh(&zcrypt_device_lock);
module_put(zdev->ap_dev->drv->driver.owner);
}
else
rc = -EAGAIN;
zdev->request_count--;
__zcrypt_increase_preference(zdev);
put_device(&zdev->ap_dev->device);
zcrypt_device_put(zdev);
spin_unlock_bh(&zcrypt_device_lock);
return rc;
}
spin_unlock_bh(&zcrypt_device_lock);
return -ENODEV;
}
static long zcrypt_send_cprb(struct ica_xcRB *xcRB)
{
struct zcrypt_device *zdev;
int rc;
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list) {
if (!zdev->online || !zdev->ops->send_cprb ||
(zdev->ops->variant == MSGTYPE06_VARIANT_EP11) ||
(xcRB->user_defined != AUTOSELECT &&
AP_QID_DEVICE(zdev->ap_dev->qid) != xcRB->user_defined))
continue;
zcrypt_device_get(zdev);
get_device(&zdev->ap_dev->device);
zdev->request_count++;
__zcrypt_decrease_preference(zdev);
if (try_module_get(zdev->ap_dev->drv->driver.owner)) {
spin_unlock_bh(&zcrypt_device_lock);
rc = zdev->ops->send_cprb(zdev, xcRB);
spin_lock_bh(&zcrypt_device_lock);
module_put(zdev->ap_dev->drv->driver.owner);
}
else
rc = -EAGAIN;
zdev->request_count--;
__zcrypt_increase_preference(zdev);
put_device(&zdev->ap_dev->device);
zcrypt_device_put(zdev);
spin_unlock_bh(&zcrypt_device_lock);
return rc;
}
spin_unlock_bh(&zcrypt_device_lock);
return -ENODEV;
}
static bool is_desired_ep11dev(unsigned int dev_qid,
struct ep11_target_dev_list dev_list)
{
int n;
for (n = 0; n < dev_list.targets_num; n++, dev_list.targets++) {
if ((AP_QID_DEVICE(dev_qid) == dev_list.targets->ap_id) &&
(AP_QID_QUEUE(dev_qid) == dev_list.targets->dom_id)) {
return true;
}
}
return false;
}
static long zcrypt_send_ep11_cprb(struct ep11_urb *xcrb)
{
struct zcrypt_device *zdev;
bool autoselect = false;
int rc;
struct ep11_target_dev_list ep11_dev_list = {
.targets_num = 0x00,
.targets = NULL,
};
ep11_dev_list.targets_num = (unsigned short) xcrb->targets_num;
if (ep11_dev_list.targets_num == 0)
autoselect = true;
else {
ep11_dev_list.targets = kcalloc((unsigned short)
xcrb->targets_num,
sizeof(struct ep11_target_dev),
GFP_KERNEL);
if (!ep11_dev_list.targets)
return -ENOMEM;
if (copy_from_user(ep11_dev_list.targets,
(struct ep11_target_dev __force __user *)
xcrb->targets, xcrb->targets_num *
sizeof(struct ep11_target_dev)))
return -EFAULT;
}
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list) {
if (!zdev->online ||
zdev->ops->variant != MSGTYPE06_VARIANT_EP11)
continue;
if (!is_desired_ep11dev(zdev->ap_dev->qid, ep11_dev_list) &&
!autoselect)
continue;
zcrypt_device_get(zdev);
get_device(&zdev->ap_dev->device);
zdev->request_count++;
__zcrypt_decrease_preference(zdev);
if (try_module_get(zdev->ap_dev->drv->driver.owner)) {
spin_unlock_bh(&zcrypt_device_lock);
rc = zdev->ops->send_ep11_cprb(zdev, xcrb);
spin_lock_bh(&zcrypt_device_lock);
module_put(zdev->ap_dev->drv->driver.owner);
} else {
rc = -EAGAIN;
}
zdev->request_count--;
__zcrypt_increase_preference(zdev);
put_device(&zdev->ap_dev->device);
zcrypt_device_put(zdev);
spin_unlock_bh(&zcrypt_device_lock);
return rc;
}
spin_unlock_bh(&zcrypt_device_lock);
return -ENODEV;
}
static long zcrypt_rng(char *buffer)
{
struct zcrypt_device *zdev;
int rc;
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list) {
if (!zdev->online || !zdev->ops->rng)
continue;
zcrypt_device_get(zdev);
get_device(&zdev->ap_dev->device);
zdev->request_count++;
__zcrypt_decrease_preference(zdev);
if (try_module_get(zdev->ap_dev->drv->driver.owner)) {
spin_unlock_bh(&zcrypt_device_lock);
rc = zdev->ops->rng(zdev, buffer);
spin_lock_bh(&zcrypt_device_lock);
module_put(zdev->ap_dev->drv->driver.owner);
} else
rc = -EAGAIN;
zdev->request_count--;
__zcrypt_increase_preference(zdev);
put_device(&zdev->ap_dev->device);
zcrypt_device_put(zdev);
spin_unlock_bh(&zcrypt_device_lock);
return rc;
}
spin_unlock_bh(&zcrypt_device_lock);
return -ENODEV;
}
static void zcrypt_status_mask(char status[AP_DEVICES])
{
struct zcrypt_device *zdev;
memset(status, 0, sizeof(char) * AP_DEVICES);
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list)
status[AP_QID_DEVICE(zdev->ap_dev->qid)] =
zdev->online ? zdev->user_space_type : 0x0d;
spin_unlock_bh(&zcrypt_device_lock);
}
static void zcrypt_qdepth_mask(char qdepth[AP_DEVICES])
{
struct zcrypt_device *zdev;
memset(qdepth, 0, sizeof(char) * AP_DEVICES);
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list) {
spin_lock(&zdev->ap_dev->lock);
qdepth[AP_QID_DEVICE(zdev->ap_dev->qid)] =
zdev->ap_dev->pendingq_count +
zdev->ap_dev->requestq_count;
spin_unlock(&zdev->ap_dev->lock);
}
spin_unlock_bh(&zcrypt_device_lock);
}
static void zcrypt_perdev_reqcnt(int reqcnt[AP_DEVICES])
{
struct zcrypt_device *zdev;
memset(reqcnt, 0, sizeof(int) * AP_DEVICES);
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list) {
spin_lock(&zdev->ap_dev->lock);
reqcnt[AP_QID_DEVICE(zdev->ap_dev->qid)] =
zdev->ap_dev->total_request_count;
spin_unlock(&zdev->ap_dev->lock);
}
spin_unlock_bh(&zcrypt_device_lock);
}
static int zcrypt_pendingq_count(void)
{
struct zcrypt_device *zdev;
int pendingq_count = 0;
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list) {
spin_lock(&zdev->ap_dev->lock);
pendingq_count += zdev->ap_dev->pendingq_count;
spin_unlock(&zdev->ap_dev->lock);
}
spin_unlock_bh(&zcrypt_device_lock);
return pendingq_count;
}
static int zcrypt_requestq_count(void)
{
struct zcrypt_device *zdev;
int requestq_count = 0;
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list) {
spin_lock(&zdev->ap_dev->lock);
requestq_count += zdev->ap_dev->requestq_count;
spin_unlock(&zdev->ap_dev->lock);
}
spin_unlock_bh(&zcrypt_device_lock);
return requestq_count;
}
static int zcrypt_count_type(int type)
{
struct zcrypt_device *zdev;
int device_count = 0;
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list)
if (zdev->user_space_type == type)
device_count++;
spin_unlock_bh(&zcrypt_device_lock);
return device_count;
}
static long zcrypt_ica_status(struct file *filp, unsigned long arg)
{
struct ica_z90_status *pstat;
int ret;
pstat = kzalloc(sizeof(*pstat), GFP_KERNEL);
if (!pstat)
return -ENOMEM;
pstat->totalcount = zcrypt_device_count;
pstat->leedslitecount = zcrypt_count_type(ZCRYPT_PCICA);
pstat->leeds2count = zcrypt_count_type(ZCRYPT_PCICC);
pstat->requestqWaitCount = zcrypt_requestq_count();
pstat->pendingqWaitCount = zcrypt_pendingq_count();
pstat->totalOpenCount = atomic_read(&zcrypt_open_count);
pstat->cryptoDomain = ap_domain_index;
zcrypt_status_mask(pstat->status);
zcrypt_qdepth_mask(pstat->qdepth);
ret = 0;
if (copy_to_user((void __user *) arg, pstat, sizeof(*pstat)))
ret = -EFAULT;
kfree(pstat);
return ret;
}
static long zcrypt_unlocked_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
int rc;
switch (cmd) {
case ICARSAMODEXPO: {
struct ica_rsa_modexpo __user *umex = (void __user *) arg;
struct ica_rsa_modexpo mex;
if (copy_from_user(&mex, umex, sizeof(mex)))
return -EFAULT;
do {
rc = zcrypt_rsa_modexpo(&mex);
} while (rc == -EAGAIN);
if ((rc == -ENODEV) && (zcrypt_process_rescan()))
do {
rc = zcrypt_rsa_modexpo(&mex);
} while (rc == -EAGAIN);
if (rc)
return rc;
return put_user(mex.outputdatalength, &umex->outputdatalength);
}
case ICARSACRT: {
struct ica_rsa_modexpo_crt __user *ucrt = (void __user *) arg;
struct ica_rsa_modexpo_crt crt;
if (copy_from_user(&crt, ucrt, sizeof(crt)))
return -EFAULT;
do {
rc = zcrypt_rsa_crt(&crt);
} while (rc == -EAGAIN);
if ((rc == -ENODEV) && (zcrypt_process_rescan()))
do {
rc = zcrypt_rsa_crt(&crt);
} while (rc == -EAGAIN);
if (rc)
return rc;
return put_user(crt.outputdatalength, &ucrt->outputdatalength);
}
case ZSECSENDCPRB: {
struct ica_xcRB __user *uxcRB = (void __user *) arg;
struct ica_xcRB xcRB;
if (copy_from_user(&xcRB, uxcRB, sizeof(xcRB)))
return -EFAULT;
do {
rc = zcrypt_send_cprb(&xcRB);
} while (rc == -EAGAIN);
if ((rc == -ENODEV) && (zcrypt_process_rescan()))
do {
rc = zcrypt_send_cprb(&xcRB);
} while (rc == -EAGAIN);
if (copy_to_user(uxcRB, &xcRB, sizeof(xcRB)))
return -EFAULT;
return rc;
}
case ZSENDEP11CPRB: {
struct ep11_urb __user *uxcrb = (void __user *)arg;
struct ep11_urb xcrb;
if (copy_from_user(&xcrb, uxcrb, sizeof(xcrb)))
return -EFAULT;
do {
rc = zcrypt_send_ep11_cprb(&xcrb);
} while (rc == -EAGAIN);
if ((rc == -ENODEV) && (zcrypt_process_rescan()))
do {
rc = zcrypt_send_ep11_cprb(&xcrb);
} while (rc == -EAGAIN);
if (copy_to_user(uxcrb, &xcrb, sizeof(xcrb)))
return -EFAULT;
return rc;
}
case Z90STAT_STATUS_MASK: {
char status[AP_DEVICES];
zcrypt_status_mask(status);
if (copy_to_user((char __user *) arg, status,
sizeof(char) * AP_DEVICES))
return -EFAULT;
return 0;
}
case Z90STAT_QDEPTH_MASK: {
char qdepth[AP_DEVICES];
zcrypt_qdepth_mask(qdepth);
if (copy_to_user((char __user *) arg, qdepth,
sizeof(char) * AP_DEVICES))
return -EFAULT;
return 0;
}
case Z90STAT_PERDEV_REQCNT: {
int reqcnt[AP_DEVICES];
zcrypt_perdev_reqcnt(reqcnt);
if (copy_to_user((int __user *) arg, reqcnt,
sizeof(int) * AP_DEVICES))
return -EFAULT;
return 0;
}
case Z90STAT_REQUESTQ_COUNT:
return put_user(zcrypt_requestq_count(), (int __user *) arg);
case Z90STAT_PENDINGQ_COUNT:
return put_user(zcrypt_pendingq_count(), (int __user *) arg);
case Z90STAT_TOTALOPEN_COUNT:
return put_user(atomic_read(&zcrypt_open_count),
(int __user *) arg);
case Z90STAT_DOMAIN_INDEX:
return put_user(ap_domain_index, (int __user *) arg);
case ICAZ90STATUS:
return zcrypt_ica_status(filp, arg);
case Z90STAT_TOTALCOUNT:
return put_user(zcrypt_device_count, (int __user *) arg);
case Z90STAT_PCICACOUNT:
return put_user(zcrypt_count_type(ZCRYPT_PCICA),
(int __user *) arg);
case Z90STAT_PCICCCOUNT:
return put_user(zcrypt_count_type(ZCRYPT_PCICC),
(int __user *) arg);
case Z90STAT_PCIXCCMCL2COUNT:
return put_user(zcrypt_count_type(ZCRYPT_PCIXCC_MCL2),
(int __user *) arg);
case Z90STAT_PCIXCCMCL3COUNT:
return put_user(zcrypt_count_type(ZCRYPT_PCIXCC_MCL3),
(int __user *) arg);
case Z90STAT_PCIXCCCOUNT:
return put_user(zcrypt_count_type(ZCRYPT_PCIXCC_MCL2) +
zcrypt_count_type(ZCRYPT_PCIXCC_MCL3),
(int __user *) arg);
case Z90STAT_CEX2CCOUNT:
return put_user(zcrypt_count_type(ZCRYPT_CEX2C),
(int __user *) arg);
case Z90STAT_CEX2ACOUNT:
return put_user(zcrypt_count_type(ZCRYPT_CEX2A),
(int __user *) arg);
default:
return -ENOIOCTLCMD;
}
}
static long trans_modexpo32(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct compat_ica_rsa_modexpo __user *umex32 = compat_ptr(arg);
struct compat_ica_rsa_modexpo mex32;
struct ica_rsa_modexpo mex64;
long rc;
if (copy_from_user(&mex32, umex32, sizeof(mex32)))
return -EFAULT;
mex64.inputdata = compat_ptr(mex32.inputdata);
mex64.inputdatalength = mex32.inputdatalength;
mex64.outputdata = compat_ptr(mex32.outputdata);
mex64.outputdatalength = mex32.outputdatalength;
mex64.b_key = compat_ptr(mex32.b_key);
mex64.n_modulus = compat_ptr(mex32.n_modulus);
do {
rc = zcrypt_rsa_modexpo(&mex64);
} while (rc == -EAGAIN);
if ((rc == -ENODEV) && (zcrypt_process_rescan()))
do {
rc = zcrypt_rsa_modexpo(&mex64);
} while (rc == -EAGAIN);
if (rc)
return rc;
return put_user(mex64.outputdatalength,
&umex32->outputdatalength);
}
static long trans_modexpo_crt32(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct compat_ica_rsa_modexpo_crt __user *ucrt32 = compat_ptr(arg);
struct compat_ica_rsa_modexpo_crt crt32;
struct ica_rsa_modexpo_crt crt64;
long rc;
if (copy_from_user(&crt32, ucrt32, sizeof(crt32)))
return -EFAULT;
crt64.inputdata = compat_ptr(crt32.inputdata);
crt64.inputdatalength = crt32.inputdatalength;
crt64.outputdata= compat_ptr(crt32.outputdata);
crt64.outputdatalength = crt32.outputdatalength;
crt64.bp_key = compat_ptr(crt32.bp_key);
crt64.bq_key = compat_ptr(crt32.bq_key);
crt64.np_prime = compat_ptr(crt32.np_prime);
crt64.nq_prime = compat_ptr(crt32.nq_prime);
crt64.u_mult_inv = compat_ptr(crt32.u_mult_inv);
do {
rc = zcrypt_rsa_crt(&crt64);
} while (rc == -EAGAIN);
if ((rc == -ENODEV) && (zcrypt_process_rescan()))
do {
rc = zcrypt_rsa_crt(&crt64);
} while (rc == -EAGAIN);
if (rc)
return rc;
return put_user(crt64.outputdatalength,
&ucrt32->outputdatalength);
}
static long trans_xcRB32(struct file *filp, unsigned int cmd,
unsigned long arg)
{
struct compat_ica_xcRB __user *uxcRB32 = compat_ptr(arg);
struct compat_ica_xcRB xcRB32;
struct ica_xcRB xcRB64;
long rc;
if (copy_from_user(&xcRB32, uxcRB32, sizeof(xcRB32)))
return -EFAULT;
xcRB64.agent_ID = xcRB32.agent_ID;
xcRB64.user_defined = xcRB32.user_defined;
xcRB64.request_ID = xcRB32.request_ID;
xcRB64.request_control_blk_length =
xcRB32.request_control_blk_length;
xcRB64.request_control_blk_addr =
compat_ptr(xcRB32.request_control_blk_addr);
xcRB64.request_data_length =
xcRB32.request_data_length;
xcRB64.request_data_address =
compat_ptr(xcRB32.request_data_address);
xcRB64.reply_control_blk_length =
xcRB32.reply_control_blk_length;
xcRB64.reply_control_blk_addr =
compat_ptr(xcRB32.reply_control_blk_addr);
xcRB64.reply_data_length = xcRB32.reply_data_length;
xcRB64.reply_data_addr =
compat_ptr(xcRB32.reply_data_addr);
xcRB64.priority_window = xcRB32.priority_window;
xcRB64.status = xcRB32.status;
do {
rc = zcrypt_send_cprb(&xcRB64);
} while (rc == -EAGAIN);
if ((rc == -ENODEV) && (zcrypt_process_rescan()))
do {
rc = zcrypt_send_cprb(&xcRB64);
} while (rc == -EAGAIN);
xcRB32.reply_control_blk_length = xcRB64.reply_control_blk_length;
xcRB32.reply_data_length = xcRB64.reply_data_length;
xcRB32.status = xcRB64.status;
if (copy_to_user(uxcRB32, &xcRB32, sizeof(xcRB32)))
return -EFAULT;
return rc;
}
static long zcrypt_compat_ioctl(struct file *filp, unsigned int cmd,
unsigned long arg)
{
if (cmd == ICARSAMODEXPO)
return trans_modexpo32(filp, cmd, arg);
if (cmd == ICARSACRT)
return trans_modexpo_crt32(filp, cmd, arg);
if (cmd == ZSECSENDCPRB)
return trans_xcRB32(filp, cmd, arg);
return zcrypt_unlocked_ioctl(filp, cmd, arg);
}
static void sprintcl(struct seq_file *m, unsigned char *addr, unsigned int len)
{
int i;
for (i = 0; i < len; i++)
seq_printf(m, "%01x", (unsigned int) addr[i]);
seq_putc(m, ' ');
}
static void sprintrw(struct seq_file *m, unsigned char *addr, unsigned int len)
{
int inl, c, cx;
seq_printf(m, " ");
inl = 0;
for (c = 0; c < (len / 16); c++) {
sprintcl(m, addr+inl, 16);
inl += 16;
}
cx = len%16;
if (cx) {
sprintcl(m, addr+inl, cx);
inl += cx;
}
seq_putc(m, '\n');
}
static void sprinthx(unsigned char *title, struct seq_file *m,
unsigned char *addr, unsigned int len)
{
int inl, r, rx;
seq_printf(m, "\n%s\n", title);
inl = 0;
for (r = 0; r < (len / 64); r++) {
sprintrw(m, addr+inl, 64);
inl += 64;
}
rx = len % 64;
if (rx) {
sprintrw(m, addr+inl, rx);
inl += rx;
}
seq_putc(m, '\n');
}
static void sprinthx4(unsigned char *title, struct seq_file *m,
unsigned int *array, unsigned int len)
{
seq_printf(m, "\n%s\n", title);
seq_hex_dump(m, " ", DUMP_PREFIX_NONE, 32, 4, array, len, false);
seq_putc(m, '\n');
}
static int zcrypt_proc_show(struct seq_file *m, void *v)
{
char workarea[sizeof(int) * AP_DEVICES];
seq_printf(m, "\nzcrypt version: %d.%d.%d\n",
ZCRYPT_VERSION, ZCRYPT_RELEASE, ZCRYPT_VARIANT);
seq_printf(m, "Cryptographic domain: %d\n", ap_domain_index);
seq_printf(m, "Total device count: %d\n", zcrypt_device_count);
seq_printf(m, "PCICA count: %d\n", zcrypt_count_type(ZCRYPT_PCICA));
seq_printf(m, "PCICC count: %d\n", zcrypt_count_type(ZCRYPT_PCICC));
seq_printf(m, "PCIXCC MCL2 count: %d\n",
zcrypt_count_type(ZCRYPT_PCIXCC_MCL2));
seq_printf(m, "PCIXCC MCL3 count: %d\n",
zcrypt_count_type(ZCRYPT_PCIXCC_MCL3));
seq_printf(m, "CEX2C count: %d\n", zcrypt_count_type(ZCRYPT_CEX2C));
seq_printf(m, "CEX2A count: %d\n", zcrypt_count_type(ZCRYPT_CEX2A));
seq_printf(m, "CEX3C count: %d\n", zcrypt_count_type(ZCRYPT_CEX3C));
seq_printf(m, "CEX3A count: %d\n", zcrypt_count_type(ZCRYPT_CEX3A));
seq_printf(m, "requestq count: %d\n", zcrypt_requestq_count());
seq_printf(m, "pendingq count: %d\n", zcrypt_pendingq_count());
seq_printf(m, "Total open handles: %d\n\n",
atomic_read(&zcrypt_open_count));
zcrypt_status_mask(workarea);
sprinthx("Online devices: 1=PCICA 2=PCICC 3=PCIXCC(MCL2) "
"4=PCIXCC(MCL3) 5=CEX2C 6=CEX2A 7=CEX3C 8=CEX3A",
m, workarea, AP_DEVICES);
zcrypt_qdepth_mask(workarea);
sprinthx("Waiting work element counts", m, workarea, AP_DEVICES);
zcrypt_perdev_reqcnt((int *) workarea);
sprinthx4("Per-device successfully completed request counts",
m, (unsigned int *) workarea, AP_DEVICES);
return 0;
}
static int zcrypt_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, zcrypt_proc_show, NULL);
}
static void zcrypt_disable_card(int index)
{
struct zcrypt_device *zdev;
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list)
if (AP_QID_DEVICE(zdev->ap_dev->qid) == index) {
zdev->online = 0;
ap_flush_queue(zdev->ap_dev);
break;
}
spin_unlock_bh(&zcrypt_device_lock);
}
static void zcrypt_enable_card(int index)
{
struct zcrypt_device *zdev;
spin_lock_bh(&zcrypt_device_lock);
list_for_each_entry(zdev, &zcrypt_device_list, list)
if (AP_QID_DEVICE(zdev->ap_dev->qid) == index) {
zdev->online = 1;
break;
}
spin_unlock_bh(&zcrypt_device_lock);
}
static ssize_t zcrypt_proc_write(struct file *file, const char __user *buffer,
size_t count, loff_t *pos)
{
unsigned char *lbuf, *ptr;
size_t local_count;
int j;
if (count <= 0)
return 0;
#define LBUFSIZE 1200UL
lbuf = kmalloc(LBUFSIZE, GFP_KERNEL);
if (!lbuf)
return 0;
local_count = min(LBUFSIZE - 1, count);
if (copy_from_user(lbuf, buffer, local_count) != 0) {
kfree(lbuf);
return -EFAULT;
}
lbuf[local_count] = '\0';
ptr = strstr(lbuf, "Online devices");
if (!ptr)
goto out;
ptr = strstr(ptr, "\n");
if (!ptr)
goto out;
ptr++;
if (strstr(ptr, "Waiting work element counts") == NULL)
goto out;
for (j = 0; j < 64 && *ptr; ptr++) {
if (*ptr >= '0' && *ptr <= '8')
j++;
else if (*ptr == 'd' || *ptr == 'D')
zcrypt_disable_card(j++);
else if (*ptr == 'e' || *ptr == 'E')
zcrypt_enable_card(j++);
else if (*ptr != ' ' && *ptr != '\t')
break;
}
out:
kfree(lbuf);
return count;
}
static int zcrypt_rng_data_read(struct hwrng *rng, u32 *data)
{
int rc;
if (zcrypt_rng_buffer_index == 0) {
rc = zcrypt_rng((char *) zcrypt_rng_buffer);
if ((rc == -ENODEV) && (zcrypt_process_rescan()))
rc = zcrypt_rng((char *) zcrypt_rng_buffer);
if (rc < 0)
return -EIO;
zcrypt_rng_buffer_index = rc / sizeof *data;
}
*data = zcrypt_rng_buffer[--zcrypt_rng_buffer_index];
return sizeof *data;
}
static int zcrypt_rng_device_add(void)
{
int rc = 0;
mutex_lock(&zcrypt_rng_mutex);
if (zcrypt_rng_device_count == 0) {
zcrypt_rng_buffer = (u32 *) get_zeroed_page(GFP_KERNEL);
if (!zcrypt_rng_buffer) {
rc = -ENOMEM;
goto out;
}
zcrypt_rng_buffer_index = 0;
if (!zcrypt_hwrng_seed)
zcrypt_rng_dev.quality = 0;
rc = hwrng_register(&zcrypt_rng_dev);
if (rc)
goto out_free;
zcrypt_rng_device_count = 1;
} else
zcrypt_rng_device_count++;
mutex_unlock(&zcrypt_rng_mutex);
return 0;
out_free:
free_page((unsigned long) zcrypt_rng_buffer);
out:
mutex_unlock(&zcrypt_rng_mutex);
return rc;
}
static void zcrypt_rng_device_remove(void)
{
mutex_lock(&zcrypt_rng_mutex);
zcrypt_rng_device_count--;
if (zcrypt_rng_device_count == 0) {
hwrng_unregister(&zcrypt_rng_dev);
free_page((unsigned long) zcrypt_rng_buffer);
}
mutex_unlock(&zcrypt_rng_mutex);
}
int __init zcrypt_debug_init(void)
{
debugfs_root = debugfs_create_dir("zcrypt", NULL);
zcrypt_dbf_common = debug_register("zcrypt_common", 1, 1, 16);
debug_register_view(zcrypt_dbf_common, &debug_hex_ascii_view);
debug_set_level(zcrypt_dbf_common, DBF_ERR);
zcrypt_dbf_devices = debug_register("zcrypt_devices", 1, 1, 16);
debug_register_view(zcrypt_dbf_devices, &debug_hex_ascii_view);
debug_set_level(zcrypt_dbf_devices, DBF_ERR);
return 0;
}
void zcrypt_debug_exit(void)
{
debugfs_remove(debugfs_root);
if (zcrypt_dbf_common)
debug_unregister(zcrypt_dbf_common);
if (zcrypt_dbf_devices)
debug_unregister(zcrypt_dbf_devices);
}
int __init zcrypt_api_init(void)
{
int rc;
rc = zcrypt_debug_init();
if (rc)
goto out;
atomic_set(&zcrypt_rescan_req, 0);
rc = misc_register(&zcrypt_misc_device);
if (rc < 0)
goto out;
zcrypt_entry = proc_create("driver/z90crypt", 0644, NULL, &zcrypt_proc_fops);
if (!zcrypt_entry) {
rc = -ENOMEM;
goto out_misc;
}
return 0;
out_misc:
misc_deregister(&zcrypt_misc_device);
out:
return rc;
}
void zcrypt_api_exit(void)
{
remove_proc_entry("driver/z90crypt", NULL);
misc_deregister(&zcrypt_misc_device);
zcrypt_debug_exit();
}
