static int fcoe_str_to_dev_loss(const char *buf, unsigned long *val)
{
int ret;
ret = kstrtoul(buf, 0, val);
if (ret)
return -EINVAL;
if (*val > UINT_MAX)
return -EINVAL;
return 0;
}
static int fcoe_fcf_set_dev_loss_tmo(struct fcoe_fcf_device *fcf,
unsigned long val)
{
if ((fcf->state == FCOE_FCF_STATE_UNKNOWN) ||
(fcf->state == FCOE_FCF_STATE_DISCONNECTED) ||
(fcf->state == FCOE_FCF_STATE_DELETED))
return -EBUSY;
if (val > UINT_MAX)
return -EINVAL;
fcoe_fcf_dev_loss_tmo(fcf) = val;
return 0;
}
static enum fip_conn_type fcoe_parse_mode(const char *buf)
{
int i;
for (i = 0; i < ARRAY_SIZE(fip_conn_type_names); i++) {
if (strcasecmp(buf, fip_conn_type_names[i]) == 0)
return i;
}
return FIP_CONN_TYPE_UNKNOWN;
}
static ssize_t show_fcf_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct fcoe_fcf_device *fcf = dev_to_fcf(dev);
const char *name;
name = get_fcoe_fcf_state_name(fcf->state);
if (!name)
return -EINVAL;
return snprintf(buf, FCOE_FCF_STATE_MAX_NAMELEN, "%s\n", name);
}
static ssize_t show_ctlr_mode(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct fcoe_ctlr_device *ctlr = dev_to_ctlr(dev);
const char *name;
name = get_fcoe_ctlr_mode_name(ctlr->mode);
if (!name)
return -EINVAL;
return snprintf(buf, FCOE_MAX_MODENAME_LEN,
"%s\n", name);
}
static ssize_t store_ctlr_mode(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fcoe_ctlr_device *ctlr = dev_to_ctlr(dev);
char mode[FCOE_MAX_MODENAME_LEN + 1];
if (count > FCOE_MAX_MODENAME_LEN)
return -EINVAL;
strncpy(mode, buf, count);
if (mode[count - 1] == '\n')
mode[count - 1] = '\0';
else
mode[count] = '\0';
switch (ctlr->enabled) {
case FCOE_CTLR_ENABLED:
LIBFCOE_SYSFS_DBG(ctlr, "Cannot change mode when enabled.\n");
return -EBUSY;
case FCOE_CTLR_DISABLED:
if (!ctlr->f->set_fcoe_ctlr_mode) {
LIBFCOE_SYSFS_DBG(ctlr,
"Mode change not supported by LLD.\n");
return -ENOTSUPP;
}
ctlr->mode = fcoe_parse_mode(mode);
if (ctlr->mode == FIP_CONN_TYPE_UNKNOWN) {
LIBFCOE_SYSFS_DBG(ctlr, "Unknown mode %s provided.\n",
buf);
return -EINVAL;
}
ctlr->f->set_fcoe_ctlr_mode(ctlr);
LIBFCOE_SYSFS_DBG(ctlr, "Mode changed to %s.\n", buf);
return count;
case FCOE_CTLR_UNUSED:
default:
LIBFCOE_SYSFS_DBG(ctlr, "Mode change not supported.\n");
return -ENOTSUPP;
};
}
static ssize_t store_ctlr_enabled(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fcoe_ctlr_device *ctlr = dev_to_ctlr(dev);
bool enabled;
int rc;
if (*buf == '1')
enabled = true;
else if (*buf == '0')
enabled = false;
else
return -EINVAL;
switch (ctlr->enabled) {
case FCOE_CTLR_ENABLED:
if (enabled)
return count;
ctlr->enabled = FCOE_CTLR_DISABLED;
break;
case FCOE_CTLR_DISABLED:
if (!enabled)
return count;
ctlr->enabled = FCOE_CTLR_ENABLED;
break;
case FCOE_CTLR_UNUSED:
return -ENOTSUPP;
};
rc = ctlr->f->set_fcoe_ctlr_enabled(ctlr);
if (rc)
return rc;
return count;
}
static ssize_t show_ctlr_enabled_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct fcoe_ctlr_device *ctlr = dev_to_ctlr(dev);
const char *name;
name = get_fcoe_ctlr_enabled_state_name(ctlr->enabled);
if (!name)
return -EINVAL;
return snprintf(buf, FCOE_CTLR_ENABLED_MAX_NAMELEN,
"%s\n", name);
}
static ssize_t store_ctlr_fip_resp(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fcoe_ctlr_device *ctlr = dev_to_ctlr(dev);
struct fcoe_ctlr *fip = fcoe_ctlr_device_priv(ctlr);
mutex_lock(&fip->ctlr_mutex);
if ((buf[1] == '\0') || ((buf[1] == '\n') && (buf[2] == '\0'))) {
if (buf[0] == '1') {
fip->fip_resp = 1;
mutex_unlock(&fip->ctlr_mutex);
return count;
}
if (buf[0] == '0') {
fip->fip_resp = 0;
mutex_unlock(&fip->ctlr_mutex);
return count;
}
}
mutex_unlock(&fip->ctlr_mutex);
return -EINVAL;
}
static ssize_t show_ctlr_fip_resp(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct fcoe_ctlr_device *ctlr = dev_to_ctlr(dev);
struct fcoe_ctlr *fip = fcoe_ctlr_device_priv(ctlr);
return sprintf(buf, "%d\n", fip->fip_resp ? 1 : 0);
}
static ssize_t
fcoe_ctlr_var_store(u32 *var, const char *buf, size_t count)
{
int err;
unsigned long v;
err = kstrtoul(buf, 10, &v);
if (err || v > UINT_MAX)
return -EINVAL;
*var = v;
return count;
}
static ssize_t store_ctlr_r_a_tov(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fcoe_ctlr_device *ctlr_dev = dev_to_ctlr(dev);
struct fcoe_ctlr *ctlr = fcoe_ctlr_device_priv(ctlr_dev);
if (ctlr_dev->enabled == FCOE_CTLR_ENABLED)
return -EBUSY;
if (ctlr_dev->enabled == FCOE_CTLR_DISABLED)
return fcoe_ctlr_var_store(&ctlr->lp->r_a_tov, buf, count);
return -ENOTSUPP;
}
static ssize_t show_ctlr_r_a_tov(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct fcoe_ctlr_device *ctlr_dev = dev_to_ctlr(dev);
struct fcoe_ctlr *ctlr = fcoe_ctlr_device_priv(ctlr_dev);
return sprintf(buf, "%d\n", ctlr->lp->r_a_tov);
}
static ssize_t store_ctlr_e_d_tov(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fcoe_ctlr_device *ctlr_dev = dev_to_ctlr(dev);
struct fcoe_ctlr *ctlr = fcoe_ctlr_device_priv(ctlr_dev);
if (ctlr_dev->enabled == FCOE_CTLR_ENABLED)
return -EBUSY;
if (ctlr_dev->enabled == FCOE_CTLR_DISABLED)
return fcoe_ctlr_var_store(&ctlr->lp->e_d_tov, buf, count);
return -ENOTSUPP;
}
static ssize_t show_ctlr_e_d_tov(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct fcoe_ctlr_device *ctlr_dev = dev_to_ctlr(dev);
struct fcoe_ctlr *ctlr = fcoe_ctlr_device_priv(ctlr_dev);
return sprintf(buf, "%d\n", ctlr->lp->e_d_tov);
}
static ssize_t
store_private_fcoe_ctlr_fcf_dev_loss_tmo(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct fcoe_ctlr_device *ctlr = dev_to_ctlr(dev);
struct fcoe_fcf_device *fcf;
unsigned long val;
int rc;
rc = fcoe_str_to_dev_loss(buf, &val);
if (rc)
return rc;
fcoe_ctlr_fcf_dev_loss_tmo(ctlr) = val;
mutex_lock(&ctlr->lock);
list_for_each_entry(fcf, &ctlr->fcfs, peers)
fcoe_fcf_set_dev_loss_tmo(fcf, val);
mutex_unlock(&ctlr->lock);
return count;
}
static ssize_t
store_fcoe_fcf_dev_loss_tmo(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct fcoe_fcf_device *fcf = dev_to_fcf(dev);
unsigned long val;
int rc;
rc = fcoe_str_to_dev_loss(buf, &val);
if (rc)
return rc;
rc = fcoe_fcf_set_dev_loss_tmo(fcf, val);
if (rc)
return rc;
return count;
}
static int fcoe_bus_match(struct device *dev,
struct device_driver *drv)
{
if (dev->bus == &fcoe_bus_type)
return 1;
return 0;
}
static void fcoe_ctlr_device_release(struct device *dev)
{
struct fcoe_ctlr_device *ctlr = dev_to_ctlr(dev);
kfree(ctlr);
}
static void fcoe_fcf_device_release(struct device *dev)
{
struct fcoe_fcf_device *fcf = dev_to_fcf(dev);
kfree(fcf);
}
static void fcoe_ctlr_device_flush_work(struct fcoe_ctlr_device *ctlr)
{
if (!fcoe_ctlr_work_q(ctlr)) {
printk(KERN_ERR
"ERROR: FIP Ctlr '%d' attempted to flush work, "
"when no workqueue created.\n", ctlr->id);
dump_stack();
return;
}
flush_workqueue(fcoe_ctlr_work_q(ctlr));
}
static int fcoe_ctlr_device_queue_work(struct fcoe_ctlr_device *ctlr,
struct work_struct *work)
{
if (unlikely(!fcoe_ctlr_work_q(ctlr))) {
printk(KERN_ERR
"ERROR: FIP Ctlr '%d' attempted to queue work, "
"when no workqueue created.\n", ctlr->id);
dump_stack();
return -EINVAL;
}
return queue_work(fcoe_ctlr_work_q(ctlr), work);
}
static void fcoe_ctlr_device_flush_devloss(struct fcoe_ctlr_device *ctlr)
{
if (!fcoe_ctlr_devloss_work_q(ctlr)) {
printk(KERN_ERR
"ERROR: FIP Ctlr '%d' attempted to flush work, "
"when no workqueue created.\n", ctlr->id);
dump_stack();
return;
}
flush_workqueue(fcoe_ctlr_devloss_work_q(ctlr));
}
static int fcoe_ctlr_device_queue_devloss_work(struct fcoe_ctlr_device *ctlr,
struct delayed_work *work,
unsigned long delay)
{
if (unlikely(!fcoe_ctlr_devloss_work_q(ctlr))) {
printk(KERN_ERR
"ERROR: FIP Ctlr '%d' attempted to queue work, "
"when no workqueue created.\n", ctlr->id);
dump_stack();
return -EINVAL;
}
return queue_delayed_work(fcoe_ctlr_devloss_work_q(ctlr), work, delay);
}
static int fcoe_fcf_device_match(struct fcoe_fcf_device *new,
struct fcoe_fcf_device *old)
{
if (new->switch_name == old->switch_name &&
new->fabric_name == old->fabric_name &&
new->fc_map == old->fc_map &&
ether_addr_equal(new->mac, old->mac))
return 1;
return 0;
}
struct fcoe_ctlr_device *fcoe_ctlr_device_add(struct device *parent,
struct fcoe_sysfs_function_template *f,
int priv_size)
{
struct fcoe_ctlr_device *ctlr;
int error = 0;
ctlr = kzalloc(sizeof(struct fcoe_ctlr_device) + priv_size,
GFP_KERNEL);
if (!ctlr)
goto out;
ctlr->id = atomic_inc_return(&ctlr_num) - 1;
ctlr->f = f;
ctlr->mode = FIP_CONN_TYPE_FABRIC;
INIT_LIST_HEAD(&ctlr->fcfs);
mutex_init(&ctlr->lock);
ctlr->dev.parent = parent;
ctlr->dev.bus = &fcoe_bus_type;
ctlr->dev.type = &fcoe_ctlr_device_type;
ctlr->fcf_dev_loss_tmo = fcoe_fcf_dev_loss_tmo;
snprintf(ctlr->work_q_name, sizeof(ctlr->work_q_name),
"ctlr_wq_%d", ctlr->id);
ctlr->work_q = create_singlethread_workqueue(
ctlr->work_q_name);
if (!ctlr->work_q)
goto out_del;
snprintf(ctlr->devloss_work_q_name,
sizeof(ctlr->devloss_work_q_name),
"ctlr_dl_wq_%d", ctlr->id);
ctlr->devloss_work_q = create_singlethread_workqueue(
ctlr->devloss_work_q_name);
if (!ctlr->devloss_work_q)
goto out_del_q;
dev_set_name(&ctlr->dev, "ctlr_%d", ctlr->id);
error = device_register(&ctlr->dev);
if (error)
goto out_del_q2;
return ctlr;
out_del_q2:
destroy_workqueue(ctlr->devloss_work_q);
ctlr->devloss_work_q = NULL;
out_del_q:
destroy_workqueue(ctlr->work_q);
ctlr->work_q = NULL;
out_del:
kfree(ctlr);
out:
return NULL;
}
void fcoe_ctlr_device_delete(struct fcoe_ctlr_device *ctlr)
{
struct fcoe_fcf_device *fcf, *next;
mutex_lock(&ctlr->lock);
list_for_each_entry_safe(fcf, next,
&ctlr->fcfs, peers) {
list_del(&fcf->peers);
fcf->state = FCOE_FCF_STATE_DELETED;
fcoe_ctlr_device_queue_work(ctlr, &fcf->delete_work);
}
mutex_unlock(&ctlr->lock);
fcoe_ctlr_device_flush_work(ctlr);
destroy_workqueue(ctlr->devloss_work_q);
ctlr->devloss_work_q = NULL;
destroy_workqueue(ctlr->work_q);
ctlr->work_q = NULL;
device_unregister(&ctlr->dev);
}
static void fcoe_fcf_device_final_delete(struct work_struct *work)
{
struct fcoe_fcf_device *fcf =
container_of(work, struct fcoe_fcf_device, delete_work);
struct fcoe_ctlr_device *ctlr = fcoe_fcf_dev_to_ctlr_dev(fcf);
if (!cancel_delayed_work(&fcf->dev_loss_work))
fcoe_ctlr_device_flush_devloss(ctlr);
device_unregister(&fcf->dev);
}
static void fip_timeout_deleted_fcf(struct work_struct *work)
{
struct fcoe_fcf_device *fcf =
container_of(work, struct fcoe_fcf_device, dev_loss_work.work);
struct fcoe_ctlr_device *ctlr = fcoe_fcf_dev_to_ctlr_dev(fcf);
mutex_lock(&ctlr->lock);
if (fcf->state != FCOE_FCF_STATE_DISCONNECTED)
goto out;
dev_printk(KERN_ERR, &fcf->dev,
"FIP fcf connection time out: removing fcf\n");
list_del(&fcf->peers);
fcf->state = FCOE_FCF_STATE_DELETED;
fcoe_ctlr_device_queue_work(ctlr, &fcf->delete_work);
out:
mutex_unlock(&ctlr->lock);
}
void fcoe_fcf_device_delete(struct fcoe_fcf_device *fcf)
{
struct fcoe_ctlr_device *ctlr = fcoe_fcf_dev_to_ctlr_dev(fcf);
int timeout = fcf->dev_loss_tmo;
if (fcf->state != FCOE_FCF_STATE_CONNECTED)
return;
fcf->state = FCOE_FCF_STATE_DISCONNECTED;
fcf->priv = NULL;
fcoe_ctlr_device_queue_devloss_work(ctlr, &fcf->dev_loss_work,
timeout * HZ);
}
struct fcoe_fcf_device *fcoe_fcf_device_add(struct fcoe_ctlr_device *ctlr,
struct fcoe_fcf_device *new_fcf)
{
struct fcoe_fcf_device *fcf;
int error = 0;
list_for_each_entry(fcf, &ctlr->fcfs, peers) {
if (fcoe_fcf_device_match(new_fcf, fcf)) {
if (fcf->state == FCOE_FCF_STATE_CONNECTED)
return fcf;
fcf->state = FCOE_FCF_STATE_CONNECTED;
if (!cancel_delayed_work(&fcf->dev_loss_work))
fcoe_ctlr_device_flush_devloss(ctlr);
return fcf;
}
}
fcf = kzalloc(sizeof(struct fcoe_fcf_device), GFP_ATOMIC);
if (unlikely(!fcf))
goto out;
INIT_WORK(&fcf->delete_work, fcoe_fcf_device_final_delete);
INIT_DELAYED_WORK(&fcf->dev_loss_work, fip_timeout_deleted_fcf);
fcf->dev.parent = &ctlr->dev;
fcf->dev.bus = &fcoe_bus_type;
fcf->dev.type = &fcoe_fcf_device_type;
fcf->id = atomic_inc_return(&fcf_num) - 1;
fcf->state = FCOE_FCF_STATE_UNKNOWN;
fcf->dev_loss_tmo = ctlr->fcf_dev_loss_tmo;
dev_set_name(&fcf->dev, "fcf_%d", fcf->id);
fcf->fabric_name = new_fcf->fabric_name;
fcf->switch_name = new_fcf->switch_name;
fcf->fc_map = new_fcf->fc_map;
fcf->vfid = new_fcf->vfid;
memcpy(fcf->mac, new_fcf->mac, ETH_ALEN);
fcf->priority = new_fcf->priority;
fcf->fka_period = new_fcf->fka_period;
fcf->selected = new_fcf->selected;
error = device_register(&fcf->dev);
if (error)
goto out_del;
fcf->state = FCOE_FCF_STATE_CONNECTED;
list_add_tail(&fcf->peers, &ctlr->fcfs);
return fcf;
out_del:
kfree(fcf);
out:
return NULL;
}
int __init fcoe_sysfs_setup(void)
{
int error;
atomic_set(&ctlr_num, 0);
atomic_set(&fcf_num, 0);
error = bus_register(&fcoe_bus_type);
if (error)
return error;
return 0;
}
void __exit fcoe_sysfs_teardown(void)
{
bus_unregister(&fcoe_bus_type);
}
