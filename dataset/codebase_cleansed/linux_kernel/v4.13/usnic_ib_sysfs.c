static ssize_t usnic_ib_show_board(struct device *device,
struct device_attribute *attr,
char *buf)
{
struct usnic_ib_dev *us_ibdev =
container_of(device, struct usnic_ib_dev, ib_dev.dev);
unsigned short subsystem_device_id;
mutex_lock(&us_ibdev->usdev_lock);
subsystem_device_id = us_ibdev->pdev->subsystem_device;
mutex_unlock(&us_ibdev->usdev_lock);
return scnprintf(buf, PAGE_SIZE, "%hu\n", subsystem_device_id);
}
static ssize_t
usnic_ib_show_config(struct device *device, struct device_attribute *attr,
char *buf)
{
struct usnic_ib_dev *us_ibdev;
char *ptr;
unsigned left;
unsigned n;
enum usnic_vnic_res_type res_type;
us_ibdev = container_of(device, struct usnic_ib_dev, ib_dev.dev);
ptr = buf;
left = PAGE_SIZE;
mutex_lock(&us_ibdev->usdev_lock);
if (kref_read(&us_ibdev->vf_cnt) > 0) {
char *busname;
busname = us_ibdev->pdev->bus->name;
if (strncmp(busname, "PCI Bus ", 8) == 0)
busname += 8;
n = scnprintf(ptr, left,
"%s: %s:%d.%d, %s, %pM, %u VFs\n Per VF:",
us_ibdev->ib_dev.name,
busname,
PCI_SLOT(us_ibdev->pdev->devfn),
PCI_FUNC(us_ibdev->pdev->devfn),
netdev_name(us_ibdev->netdev),
us_ibdev->ufdev->mac,
kref_read(&us_ibdev->vf_cnt));
UPDATE_PTR_LEFT(n, ptr, left);
for (res_type = USNIC_VNIC_RES_TYPE_EOL;
res_type < USNIC_VNIC_RES_TYPE_MAX;
res_type++) {
if (us_ibdev->vf_res_cnt[res_type] == 0)
continue;
n = scnprintf(ptr, left, " %d %s%s",
us_ibdev->vf_res_cnt[res_type],
usnic_vnic_res_type_to_str(res_type),
(res_type < (USNIC_VNIC_RES_TYPE_MAX - 1)) ?
"," : "");
UPDATE_PTR_LEFT(n, ptr, left);
}
n = scnprintf(ptr, left, "\n");
UPDATE_PTR_LEFT(n, ptr, left);
} else {
n = scnprintf(ptr, left, "%s: no VFs\n",
us_ibdev->ib_dev.name);
UPDATE_PTR_LEFT(n, ptr, left);
}
mutex_unlock(&us_ibdev->usdev_lock);
return ptr - buf;
}
static ssize_t
usnic_ib_show_iface(struct device *device, struct device_attribute *attr,
char *buf)
{
struct usnic_ib_dev *us_ibdev;
us_ibdev = container_of(device, struct usnic_ib_dev, ib_dev.dev);
return scnprintf(buf, PAGE_SIZE, "%s\n",
netdev_name(us_ibdev->netdev));
}
static ssize_t
usnic_ib_show_max_vf(struct device *device, struct device_attribute *attr,
char *buf)
{
struct usnic_ib_dev *us_ibdev;
us_ibdev = container_of(device, struct usnic_ib_dev, ib_dev.dev);
return scnprintf(buf, PAGE_SIZE, "%u\n",
kref_read(&us_ibdev->vf_cnt));
}
static ssize_t
usnic_ib_show_qp_per_vf(struct device *device, struct device_attribute *attr,
char *buf)
{
struct usnic_ib_dev *us_ibdev;
int qp_per_vf;
us_ibdev = container_of(device, struct usnic_ib_dev, ib_dev.dev);
qp_per_vf = max(us_ibdev->vf_res_cnt[USNIC_VNIC_RES_TYPE_WQ],
us_ibdev->vf_res_cnt[USNIC_VNIC_RES_TYPE_RQ]);
return scnprintf(buf, PAGE_SIZE,
"%d\n", qp_per_vf);
}
static ssize_t
usnic_ib_show_cq_per_vf(struct device *device, struct device_attribute *attr,
char *buf)
{
struct usnic_ib_dev *us_ibdev;
us_ibdev = container_of(device, struct usnic_ib_dev, ib_dev.dev);
return scnprintf(buf, PAGE_SIZE, "%d\n",
us_ibdev->vf_res_cnt[USNIC_VNIC_RES_TYPE_CQ]);
}
static ssize_t
usnic_ib_qpn_attr_show(struct kobject *kobj, struct attribute *attr, char *buf)
{
struct usnic_ib_qp_grp *qp_grp;
struct qpn_attribute *qpn_attr;
qp_grp = container_of(kobj, struct usnic_ib_qp_grp, kobj);
qpn_attr = container_of(attr, struct qpn_attribute, attr);
return qpn_attr->show(qp_grp, buf);
}
static ssize_t context_show(struct usnic_ib_qp_grp *qp_grp, char *buf)
{
return scnprintf(buf, PAGE_SIZE, "0x%p\n", qp_grp->ctx);
}
static ssize_t summary_show(struct usnic_ib_qp_grp *qp_grp, char *buf)
{
int i, j, n;
int left;
char *ptr;
struct usnic_vnic_res_chunk *res_chunk;
struct usnic_vnic_res *vnic_res;
left = PAGE_SIZE;
ptr = buf;
n = scnprintf(ptr, left,
"QPN: %d State: (%s) PID: %u VF Idx: %hu ",
qp_grp->ibqp.qp_num,
usnic_ib_qp_grp_state_to_string(qp_grp->state),
qp_grp->owner_pid,
usnic_vnic_get_index(qp_grp->vf->vnic));
UPDATE_PTR_LEFT(n, ptr, left);
for (i = 0; qp_grp->res_chunk_list[i]; i++) {
res_chunk = qp_grp->res_chunk_list[i];
for (j = 0; j < res_chunk->cnt; j++) {
vnic_res = res_chunk->res[j];
n = scnprintf(ptr, left, "%s[%d] ",
usnic_vnic_res_type_to_str(vnic_res->type),
vnic_res->vnic_idx);
UPDATE_PTR_LEFT(n, ptr, left);
}
}
n = scnprintf(ptr, left, "\n");
UPDATE_PTR_LEFT(n, ptr, left);
return ptr - buf;
}
int usnic_ib_sysfs_register_usdev(struct usnic_ib_dev *us_ibdev)
{
int i;
int err;
for (i = 0; i < ARRAY_SIZE(usnic_class_attributes); ++i) {
err = device_create_file(&us_ibdev->ib_dev.dev,
usnic_class_attributes[i]);
if (err) {
usnic_err("Failed to create device file %d for %s eith err %d",
i, us_ibdev->ib_dev.name, err);
return -EINVAL;
}
}
kobject_get(&us_ibdev->ib_dev.dev.kobj);
us_ibdev->qpn_kobj = kobject_create_and_add("qpn",
&us_ibdev->ib_dev.dev.kobj);
if (us_ibdev->qpn_kobj == NULL) {
kobject_put(&us_ibdev->ib_dev.dev.kobj);
return -ENOMEM;
}
return 0;
}
void usnic_ib_sysfs_unregister_usdev(struct usnic_ib_dev *us_ibdev)
{
int i;
for (i = 0; i < ARRAY_SIZE(usnic_class_attributes); ++i) {
device_remove_file(&us_ibdev->ib_dev.dev,
usnic_class_attributes[i]);
}
kobject_put(us_ibdev->qpn_kobj);
}
void usnic_ib_sysfs_qpn_add(struct usnic_ib_qp_grp *qp_grp)
{
struct usnic_ib_dev *us_ibdev;
int err;
us_ibdev = qp_grp->vf->pf;
err = kobject_init_and_add(&qp_grp->kobj, &usnic_ib_qpn_type,
kobject_get(us_ibdev->qpn_kobj),
"%d", qp_grp->grp_id);
if (err) {
kobject_put(us_ibdev->qpn_kobj);
return;
}
}
void usnic_ib_sysfs_qpn_remove(struct usnic_ib_qp_grp *qp_grp)
{
struct usnic_ib_dev *us_ibdev;
us_ibdev = qp_grp->vf->pf;
kobject_put(&qp_grp->kobj);
kobject_put(us_ibdev->qpn_kobj);
}
