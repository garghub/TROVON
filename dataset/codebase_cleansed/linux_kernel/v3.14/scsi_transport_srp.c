static inline struct Scsi_Host *rport_to_shost(struct srp_rport *r)
{
return dev_to_shost(r->dev.parent);
}
int srp_tmo_valid(int reconnect_delay, int fast_io_fail_tmo, int dev_loss_tmo)
{
if (reconnect_delay < 0 && fast_io_fail_tmo < 0 && dev_loss_tmo < 0)
return -EINVAL;
if (reconnect_delay == 0)
return -EINVAL;
if (fast_io_fail_tmo > SCSI_DEVICE_BLOCK_MAX_TIMEOUT)
return -EINVAL;
if (fast_io_fail_tmo < 0 &&
dev_loss_tmo > SCSI_DEVICE_BLOCK_MAX_TIMEOUT)
return -EINVAL;
if (dev_loss_tmo >= LONG_MAX / HZ)
return -EINVAL;
if (fast_io_fail_tmo >= 0 && dev_loss_tmo >= 0 &&
fast_io_fail_tmo >= dev_loss_tmo)
return -EINVAL;
return 0;
}
static int srp_host_setup(struct transport_container *tc, struct device *dev,
struct device *cdev)
{
struct Scsi_Host *shost = dev_to_shost(dev);
struct srp_host_attrs *srp_host = to_srp_host_attrs(shost);
atomic_set(&srp_host->next_port_id, 0);
return 0;
}
static ssize_t
show_srp_rport_id(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
return sprintf(buf, SRP_PID_FMT "\n", SRP_PID(rport));
}
static ssize_t
show_srp_rport_roles(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
int i;
char *name = NULL;
for (i = 0; i < ARRAY_SIZE(srp_rport_role_names); i++)
if (srp_rport_role_names[i].value == rport->roles) {
name = srp_rport_role_names[i].name;
break;
}
return sprintf(buf, "%s\n", name ? : "unknown");
}
static ssize_t store_srp_rport_delete(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
struct Scsi_Host *shost = dev_to_shost(dev);
struct srp_internal *i = to_srp_internal(shost->transportt);
if (i->f->rport_delete) {
i->f->rport_delete(rport);
return count;
} else {
return -ENOSYS;
}
}
static ssize_t show_srp_rport_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
static const char *const state_name[] = {
[SRP_RPORT_RUNNING] = "running",
[SRP_RPORT_BLOCKED] = "blocked",
[SRP_RPORT_FAIL_FAST] = "fail-fast",
[SRP_RPORT_LOST] = "lost",
};
struct srp_rport *rport = transport_class_to_srp_rport(dev);
enum srp_rport_state state = rport->state;
return sprintf(buf, "%s\n",
(unsigned)state < ARRAY_SIZE(state_name) ?
state_name[state] : "???");
}
static ssize_t srp_show_tmo(char *buf, int tmo)
{
return tmo >= 0 ? sprintf(buf, "%d\n", tmo) : sprintf(buf, "off\n");
}
static int srp_parse_tmo(int *tmo, const char *buf)
{
int res = 0;
if (strncmp(buf, "off", 3) != 0)
res = kstrtoint(buf, 0, tmo);
else
*tmo = -1;
return res;
}
static ssize_t show_reconnect_delay(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
return srp_show_tmo(buf, rport->reconnect_delay);
}
static ssize_t store_reconnect_delay(struct device *dev,
struct device_attribute *attr,
const char *buf, const size_t count)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
int res, delay;
res = srp_parse_tmo(&delay, buf);
if (res)
goto out;
res = srp_tmo_valid(delay, rport->fast_io_fail_tmo,
rport->dev_loss_tmo);
if (res)
goto out;
if (rport->reconnect_delay <= 0 && delay > 0 &&
rport->state != SRP_RPORT_RUNNING) {
queue_delayed_work(system_long_wq, &rport->reconnect_work,
delay * HZ);
} else if (delay <= 0) {
cancel_delayed_work(&rport->reconnect_work);
}
rport->reconnect_delay = delay;
res = count;
out:
return res;
}
static ssize_t show_failed_reconnects(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
return sprintf(buf, "%d\n", rport->failed_reconnects);
}
static ssize_t show_srp_rport_fast_io_fail_tmo(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
return srp_show_tmo(buf, rport->fast_io_fail_tmo);
}
static ssize_t store_srp_rport_fast_io_fail_tmo(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
int res;
int fast_io_fail_tmo;
res = srp_parse_tmo(&fast_io_fail_tmo, buf);
if (res)
goto out;
res = srp_tmo_valid(rport->reconnect_delay, fast_io_fail_tmo,
rport->dev_loss_tmo);
if (res)
goto out;
rport->fast_io_fail_tmo = fast_io_fail_tmo;
res = count;
out:
return res;
}
static ssize_t show_srp_rport_dev_loss_tmo(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
return srp_show_tmo(buf, rport->dev_loss_tmo);
}
static ssize_t store_srp_rport_dev_loss_tmo(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct srp_rport *rport = transport_class_to_srp_rport(dev);
int res;
int dev_loss_tmo;
res = srp_parse_tmo(&dev_loss_tmo, buf);
if (res)
goto out;
res = srp_tmo_valid(rport->reconnect_delay, rport->fast_io_fail_tmo,
dev_loss_tmo);
if (res)
goto out;
rport->dev_loss_tmo = dev_loss_tmo;
res = count;
out:
return res;
}
static int srp_rport_set_state(struct srp_rport *rport,
enum srp_rport_state new_state)
{
enum srp_rport_state old_state = rport->state;
lockdep_assert_held(&rport->mutex);
switch (new_state) {
case SRP_RPORT_RUNNING:
switch (old_state) {
case SRP_RPORT_LOST:
goto invalid;
default:
break;
}
break;
case SRP_RPORT_BLOCKED:
switch (old_state) {
case SRP_RPORT_RUNNING:
break;
default:
goto invalid;
}
break;
case SRP_RPORT_FAIL_FAST:
switch (old_state) {
case SRP_RPORT_LOST:
goto invalid;
default:
break;
}
break;
case SRP_RPORT_LOST:
break;
}
rport->state = new_state;
return 0;
invalid:
return -EINVAL;
}
static void srp_reconnect_work(struct work_struct *work)
{
struct srp_rport *rport = container_of(to_delayed_work(work),
struct srp_rport, reconnect_work);
struct Scsi_Host *shost = rport_to_shost(rport);
int delay, res;
res = srp_reconnect_rport(rport);
if (res != 0) {
shost_printk(KERN_ERR, shost,
"reconnect attempt %d failed (%d)\n",
++rport->failed_reconnects, res);
delay = rport->reconnect_delay *
min(100, max(1, rport->failed_reconnects - 10));
if (delay > 0)
queue_delayed_work(system_long_wq,
&rport->reconnect_work, delay * HZ);
}
}
static void __rport_fail_io_fast(struct srp_rport *rport)
{
struct Scsi_Host *shost = rport_to_shost(rport);
struct srp_internal *i;
lockdep_assert_held(&rport->mutex);
if (srp_rport_set_state(rport, SRP_RPORT_FAIL_FAST))
return;
scsi_target_unblock(rport->dev.parent, SDEV_TRANSPORT_OFFLINE);
i = to_srp_internal(shost->transportt);
if (i->f->terminate_rport_io)
i->f->terminate_rport_io(rport);
}
static void rport_fast_io_fail_timedout(struct work_struct *work)
{
struct srp_rport *rport = container_of(to_delayed_work(work),
struct srp_rport, fast_io_fail_work);
struct Scsi_Host *shost = rport_to_shost(rport);
pr_info("fast_io_fail_tmo expired for SRP %s / %s.\n",
dev_name(&rport->dev), dev_name(&shost->shost_gendev));
mutex_lock(&rport->mutex);
if (rport->state == SRP_RPORT_BLOCKED)
__rport_fail_io_fast(rport);
mutex_unlock(&rport->mutex);
}
static void rport_dev_loss_timedout(struct work_struct *work)
{
struct srp_rport *rport = container_of(to_delayed_work(work),
struct srp_rport, dev_loss_work);
struct Scsi_Host *shost = rport_to_shost(rport);
struct srp_internal *i = to_srp_internal(shost->transportt);
pr_info("dev_loss_tmo expired for SRP %s / %s.\n",
dev_name(&rport->dev), dev_name(&shost->shost_gendev));
mutex_lock(&rport->mutex);
WARN_ON(srp_rport_set_state(rport, SRP_RPORT_LOST) != 0);
scsi_target_unblock(rport->dev.parent, SDEV_TRANSPORT_OFFLINE);
mutex_unlock(&rport->mutex);
i->f->rport_delete(rport);
}
static void __srp_start_tl_fail_timers(struct srp_rport *rport)
{
struct Scsi_Host *shost = rport_to_shost(rport);
int delay, fast_io_fail_tmo, dev_loss_tmo;
lockdep_assert_held(&rport->mutex);
delay = rport->reconnect_delay;
fast_io_fail_tmo = rport->fast_io_fail_tmo;
dev_loss_tmo = rport->dev_loss_tmo;
pr_debug("%s current state: %d\n", dev_name(&shost->shost_gendev),
rport->state);
if (rport->state == SRP_RPORT_LOST)
return;
if (delay > 0)
queue_delayed_work(system_long_wq, &rport->reconnect_work,
1UL * delay * HZ);
if (srp_rport_set_state(rport, SRP_RPORT_BLOCKED) == 0) {
pr_debug("%s new state: %d\n", dev_name(&shost->shost_gendev),
rport->state);
scsi_target_block(&shost->shost_gendev);
if (fast_io_fail_tmo >= 0)
queue_delayed_work(system_long_wq,
&rport->fast_io_fail_work,
1UL * fast_io_fail_tmo * HZ);
if (dev_loss_tmo >= 0)
queue_delayed_work(system_long_wq,
&rport->dev_loss_work,
1UL * dev_loss_tmo * HZ);
}
}
void srp_start_tl_fail_timers(struct srp_rport *rport)
{
mutex_lock(&rport->mutex);
__srp_start_tl_fail_timers(rport);
mutex_unlock(&rport->mutex);
}
static int scsi_request_fn_active(struct Scsi_Host *shost)
{
struct scsi_device *sdev;
struct request_queue *q;
int request_fn_active = 0;
shost_for_each_device(sdev, shost) {
q = sdev->request_queue;
spin_lock_irq(q->queue_lock);
request_fn_active += q->request_fn_active;
spin_unlock_irq(q->queue_lock);
}
return request_fn_active;
}
int srp_reconnect_rport(struct srp_rport *rport)
{
struct Scsi_Host *shost = rport_to_shost(rport);
struct srp_internal *i = to_srp_internal(shost->transportt);
struct scsi_device *sdev;
int res;
pr_debug("SCSI host %s\n", dev_name(&shost->shost_gendev));
res = mutex_lock_interruptible(&rport->mutex);
if (res)
goto out;
scsi_target_block(&shost->shost_gendev);
while (scsi_request_fn_active(shost))
msleep(20);
res = rport->state != SRP_RPORT_LOST ? i->f->reconnect(rport) : -ENODEV;
pr_debug("%s (state %d): transport.reconnect() returned %d\n",
dev_name(&shost->shost_gendev), rport->state, res);
if (res == 0) {
cancel_delayed_work(&rport->fast_io_fail_work);
cancel_delayed_work(&rport->dev_loss_work);
rport->failed_reconnects = 0;
srp_rport_set_state(rport, SRP_RPORT_RUNNING);
scsi_target_unblock(&shost->shost_gendev, SDEV_RUNNING);
spin_lock_irq(shost->host_lock);
__shost_for_each_device(sdev, shost)
if (sdev->sdev_state == SDEV_OFFLINE)
sdev->sdev_state = SDEV_RUNNING;
spin_unlock_irq(shost->host_lock);
} else if (rport->state == SRP_RPORT_RUNNING) {
__rport_fail_io_fast(rport);
scsi_target_unblock(&shost->shost_gendev,
SDEV_TRANSPORT_OFFLINE);
__srp_start_tl_fail_timers(rport);
} else if (rport->state != SRP_RPORT_BLOCKED) {
scsi_target_unblock(&shost->shost_gendev,
SDEV_TRANSPORT_OFFLINE);
}
mutex_unlock(&rport->mutex);
out:
return res;
}
static enum blk_eh_timer_return srp_timed_out(struct scsi_cmnd *scmd)
{
struct scsi_device *sdev = scmd->device;
struct Scsi_Host *shost = sdev->host;
struct srp_internal *i = to_srp_internal(shost->transportt);
pr_debug("timeout for sdev %s\n", dev_name(&sdev->sdev_gendev));
return i->f->reset_timer_if_blocked && scsi_device_blocked(sdev) ?
BLK_EH_RESET_TIMER : BLK_EH_NOT_HANDLED;
}
static void srp_rport_release(struct device *dev)
{
struct srp_rport *rport = dev_to_rport(dev);
put_device(dev->parent);
kfree(rport);
}
static int scsi_is_srp_rport(const struct device *dev)
{
return dev->release == srp_rport_release;
}
static int srp_rport_match(struct attribute_container *cont,
struct device *dev)
{
struct Scsi_Host *shost;
struct srp_internal *i;
if (!scsi_is_srp_rport(dev))
return 0;
shost = dev_to_shost(dev->parent);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class != &srp_host_class.class)
return 0;
i = to_srp_internal(shost->transportt);
return &i->rport_attr_cont.ac == cont;
}
static int srp_host_match(struct attribute_container *cont, struct device *dev)
{
struct Scsi_Host *shost;
struct srp_internal *i;
if (!scsi_is_host_device(dev))
return 0;
shost = dev_to_shost(dev);
if (!shost->transportt)
return 0;
if (shost->transportt->host_attrs.ac.class != &srp_host_class.class)
return 0;
i = to_srp_internal(shost->transportt);
return &i->t.host_attrs.ac == cont;
}
void srp_rport_get(struct srp_rport *rport)
{
get_device(&rport->dev);
}
void srp_rport_put(struct srp_rport *rport)
{
put_device(&rport->dev);
}
struct srp_rport *srp_rport_add(struct Scsi_Host *shost,
struct srp_rport_identifiers *ids)
{
struct srp_rport *rport;
struct device *parent = &shost->shost_gendev;
struct srp_internal *i = to_srp_internal(shost->transportt);
int id, ret;
rport = kzalloc(sizeof(*rport), GFP_KERNEL);
if (!rport)
return ERR_PTR(-ENOMEM);
mutex_init(&rport->mutex);
device_initialize(&rport->dev);
rport->dev.parent = get_device(parent);
rport->dev.release = srp_rport_release;
memcpy(rport->port_id, ids->port_id, sizeof(rport->port_id));
rport->roles = ids->roles;
if (i->f->reconnect)
rport->reconnect_delay = i->f->reconnect_delay ?
*i->f->reconnect_delay : 10;
INIT_DELAYED_WORK(&rport->reconnect_work, srp_reconnect_work);
rport->fast_io_fail_tmo = i->f->fast_io_fail_tmo ?
*i->f->fast_io_fail_tmo : 15;
rport->dev_loss_tmo = i->f->dev_loss_tmo ? *i->f->dev_loss_tmo : 60;
INIT_DELAYED_WORK(&rport->fast_io_fail_work,
rport_fast_io_fail_timedout);
INIT_DELAYED_WORK(&rport->dev_loss_work, rport_dev_loss_timedout);
id = atomic_inc_return(&to_srp_host_attrs(shost)->next_port_id);
dev_set_name(&rport->dev, "port-%d:%d", shost->host_no, id);
transport_setup_device(&rport->dev);
ret = device_add(&rport->dev);
if (ret) {
transport_destroy_device(&rport->dev);
put_device(&rport->dev);
return ERR_PTR(ret);
}
if (shost->active_mode & MODE_TARGET &&
ids->roles == SRP_RPORT_ROLE_INITIATOR) {
ret = srp_tgt_it_nexus_create(shost, (unsigned long)rport,
rport->port_id);
if (ret) {
device_del(&rport->dev);
transport_destroy_device(&rport->dev);
put_device(&rport->dev);
return ERR_PTR(ret);
}
}
transport_add_device(&rport->dev);
transport_configure_device(&rport->dev);
return rport;
}
void srp_rport_del(struct srp_rport *rport)
{
struct device *dev = &rport->dev;
struct Scsi_Host *shost = dev_to_shost(dev->parent);
if (shost->active_mode & MODE_TARGET &&
rport->roles == SRP_RPORT_ROLE_INITIATOR)
srp_tgt_it_nexus_destroy(shost, (unsigned long)rport);
transport_remove_device(dev);
device_del(dev);
transport_destroy_device(dev);
put_device(dev);
}
static int do_srp_rport_del(struct device *dev, void *data)
{
if (scsi_is_srp_rport(dev))
srp_rport_del(dev_to_rport(dev));
return 0;
}
void srp_remove_host(struct Scsi_Host *shost)
{
device_for_each_child(&shost->shost_gendev, NULL, do_srp_rport_del);
}
void srp_stop_rport_timers(struct srp_rport *rport)
{
mutex_lock(&rport->mutex);
if (rport->state == SRP_RPORT_BLOCKED)
__rport_fail_io_fast(rport);
srp_rport_set_state(rport, SRP_RPORT_LOST);
mutex_unlock(&rport->mutex);
cancel_delayed_work_sync(&rport->reconnect_work);
cancel_delayed_work_sync(&rport->fast_io_fail_work);
cancel_delayed_work_sync(&rport->dev_loss_work);
}
static int srp_tsk_mgmt_response(struct Scsi_Host *shost, u64 nexus, u64 tm_id,
int result)
{
struct srp_internal *i = to_srp_internal(shost->transportt);
return i->f->tsk_mgmt_response(shost, nexus, tm_id, result);
}
static int srp_it_nexus_response(struct Scsi_Host *shost, u64 nexus, int result)
{
struct srp_internal *i = to_srp_internal(shost->transportt);
return i->f->it_nexus_response(shost, nexus, result);
}
struct scsi_transport_template *
srp_attach_transport(struct srp_function_template *ft)
{
int count;
struct srp_internal *i;
i = kzalloc(sizeof(*i), GFP_KERNEL);
if (!i)
return NULL;
i->t.eh_timed_out = srp_timed_out;
i->t.tsk_mgmt_response = srp_tsk_mgmt_response;
i->t.it_nexus_response = srp_it_nexus_response;
i->t.host_size = sizeof(struct srp_host_attrs);
i->t.host_attrs.ac.attrs = &i->host_attrs[0];
i->t.host_attrs.ac.class = &srp_host_class.class;
i->t.host_attrs.ac.match = srp_host_match;
i->host_attrs[0] = NULL;
transport_container_register(&i->t.host_attrs);
i->rport_attr_cont.ac.attrs = &i->rport_attrs[0];
i->rport_attr_cont.ac.class = &srp_rport_class.class;
i->rport_attr_cont.ac.match = srp_rport_match;
count = 0;
i->rport_attrs[count++] = &dev_attr_port_id;
i->rport_attrs[count++] = &dev_attr_roles;
if (ft->has_rport_state) {
i->rport_attrs[count++] = &dev_attr_state;
i->rport_attrs[count++] = &dev_attr_fast_io_fail_tmo;
i->rport_attrs[count++] = &dev_attr_dev_loss_tmo;
}
if (ft->reconnect) {
i->rport_attrs[count++] = &dev_attr_reconnect_delay;
i->rport_attrs[count++] = &dev_attr_failed_reconnects;
}
if (ft->rport_delete)
i->rport_attrs[count++] = &dev_attr_delete;
i->rport_attrs[count++] = NULL;
BUG_ON(count > ARRAY_SIZE(i->rport_attrs));
transport_container_register(&i->rport_attr_cont);
i->f = ft;
return &i->t;
}
void srp_release_transport(struct scsi_transport_template *t)
{
struct srp_internal *i = to_srp_internal(t);
transport_container_unregister(&i->t.host_attrs);
transport_container_unregister(&i->rport_attr_cont);
kfree(i);
}
static __init int srp_transport_init(void)
{
int ret;
ret = transport_class_register(&srp_host_class);
if (ret)
return ret;
ret = transport_class_register(&srp_rport_class);
if (ret)
goto unregister_host_class;
return 0;
unregister_host_class:
transport_class_unregister(&srp_host_class);
return ret;
}
static void __exit srp_transport_exit(void)
{
transport_class_unregister(&srp_host_class);
transport_class_unregister(&srp_rport_class);
}
