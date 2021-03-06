static int devid_to_int(struct ccw_dev_id *dev_id)
{
return dev_id->devno + (dev_id->ssid << 16);
}
static ssize_t
tape_medium_state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct tape_device *tdev;
tdev = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%i\n", tdev->medium_state);
}
static ssize_t
tape_first_minor_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct tape_device *tdev;
tdev = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%i\n", tdev->first_minor);
}
static ssize_t
tape_state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct tape_device *tdev;
tdev = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%s\n", (tdev->first_minor < 0) ?
"OFFLINE" : tape_state_verbose[tdev->tape_state]);
}
static ssize_t
tape_operation_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct tape_device *tdev;
ssize_t rc;
tdev = dev_get_drvdata(dev);
if (tdev->first_minor < 0)
return scnprintf(buf, PAGE_SIZE, "N/A\n");
spin_lock_irq(get_ccwdev_lock(tdev->cdev));
if (list_empty(&tdev->req_queue))
rc = scnprintf(buf, PAGE_SIZE, "---\n");
else {
struct tape_request *req;
req = list_entry(tdev->req_queue.next, struct tape_request,
list);
rc = scnprintf(buf,PAGE_SIZE, "%s\n", tape_op_verbose[req->op]);
}
spin_unlock_irq(get_ccwdev_lock(tdev->cdev));
return rc;
}
static ssize_t
tape_blocksize_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct tape_device *tdev;
tdev = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%i\n", tdev->char_data.block_size);
}
void
tape_state_set(struct tape_device *device, enum tape_state newstate)
{
const char *str;
if (device->tape_state == TS_NOT_OPER) {
DBF_EVENT(3, "ts_set err: not oper\n");
return;
}
DBF_EVENT(4, "ts. dev: %x\n", device->first_minor);
DBF_EVENT(4, "old ts:\t\n");
if (device->tape_state < TS_SIZE && device->tape_state >=0 )
str = tape_state_verbose[device->tape_state];
else
str = "UNKNOWN TS";
DBF_EVENT(4, "%s\n", str);
DBF_EVENT(4, "new ts:\t\n");
if (newstate < TS_SIZE && newstate >= 0)
str = tape_state_verbose[newstate];
else
str = "UNKNOWN TS";
DBF_EVENT(4, "%s\n", str);
device->tape_state = newstate;
wake_up(&device->state_change_wq);
}
static void
tape_med_state_work_handler(struct work_struct *work)
{
static char env_state_loaded[] = "MEDIUM_STATE=LOADED";
static char env_state_unloaded[] = "MEDIUM_STATE=UNLOADED";
struct tape_med_state_work_data *p =
container_of(work, struct tape_med_state_work_data, work);
struct tape_device *device = p->device;
char *envp[] = { NULL, NULL };
switch (p->state) {
case MS_UNLOADED:
pr_info("%s: The tape cartridge has been successfully "
"unloaded\n", dev_name(&device->cdev->dev));
envp[0] = env_state_unloaded;
kobject_uevent_env(&device->cdev->dev.kobj, KOBJ_CHANGE, envp);
break;
case MS_LOADED:
pr_info("%s: A tape cartridge has been mounted\n",
dev_name(&device->cdev->dev));
envp[0] = env_state_loaded;
kobject_uevent_env(&device->cdev->dev.kobj, KOBJ_CHANGE, envp);
break;
default:
break;
}
tape_put_device(device);
kfree(p);
}
static void
tape_med_state_work(struct tape_device *device, enum tape_medium_state state)
{
struct tape_med_state_work_data *p;
p = kzalloc(sizeof(*p), GFP_ATOMIC);
if (p) {
INIT_WORK(&p->work, tape_med_state_work_handler);
p->device = tape_get_device(device);
p->state = state;
schedule_work(&p->work);
}
}
void
tape_med_state_set(struct tape_device *device, enum tape_medium_state newstate)
{
enum tape_medium_state oldstate;
oldstate = device->medium_state;
if (oldstate == newstate)
return;
device->medium_state = newstate;
switch(newstate){
case MS_UNLOADED:
device->tape_generic_status |= GMT_DR_OPEN(~0);
if (oldstate == MS_LOADED)
tape_med_state_work(device, MS_UNLOADED);
break;
case MS_LOADED:
device->tape_generic_status &= ~GMT_DR_OPEN(~0);
if (oldstate == MS_UNLOADED)
tape_med_state_work(device, MS_LOADED);
break;
default:
break;
}
wake_up(&device->state_change_wq);
}
static int
__tape_cancel_io(struct tape_device *device, struct tape_request *request)
{
int retries;
int rc;
if (request->callback == NULL)
return 0;
rc = 0;
for (retries = 0; retries < 5; retries++) {
rc = ccw_device_clear(device->cdev, (long) request);
switch (rc) {
case 0:
request->status = TAPE_REQUEST_DONE;
return 0;
case -EBUSY:
request->status = TAPE_REQUEST_CANCEL;
schedule_delayed_work(&device->tape_dnr, 0);
return 0;
case -ENODEV:
DBF_EXCEPTION(2, "device gone, retry\n");
break;
case -EIO:
DBF_EXCEPTION(2, "I/O error, retry\n");
break;
default:
BUG();
}
}
return rc;
}
static int
tape_assign_minor(struct tape_device *device)
{
struct tape_device *tmp;
int minor;
minor = 0;
write_lock(&tape_device_lock);
list_for_each_entry(tmp, &tape_device_list, node) {
if (minor < tmp->first_minor)
break;
minor += TAPE_MINORS_PER_DEV;
}
if (minor >= 256) {
write_unlock(&tape_device_lock);
return -ENODEV;
}
device->first_minor = minor;
list_add_tail(&device->node, &tmp->node);
write_unlock(&tape_device_lock);
return 0;
}
static void
tape_remove_minor(struct tape_device *device)
{
write_lock(&tape_device_lock);
list_del_init(&device->node);
device->first_minor = -1;
write_unlock(&tape_device_lock);
}
int
tape_generic_online(struct tape_device *device,
struct tape_discipline *discipline)
{
int rc;
DBF_LH(6, "tape_enable_device(%p, %p)\n", device, discipline);
if (device->tape_state != TS_INIT) {
DBF_LH(3, "Tapestate not INIT (%d)\n", device->tape_state);
return -EINVAL;
}
init_timer(&device->lb_timeout);
device->lb_timeout.function = tape_long_busy_timeout;
device->discipline = discipline;
if (!try_module_get(discipline->owner)) {
return -EINVAL;
}
rc = discipline->setup_device(device);
if (rc)
goto out;
rc = tape_assign_minor(device);
if (rc)
goto out_discipline;
rc = tapechar_setup_device(device);
if (rc)
goto out_minor;
tape_state_set(device, TS_UNUSED);
DBF_LH(3, "(%08x): Drive set online\n", device->cdev_id);
return 0;
out_minor:
tape_remove_minor(device);
out_discipline:
device->discipline->cleanup_device(device);
device->discipline = NULL;
out:
module_put(discipline->owner);
return rc;
}
static void
tape_cleanup_device(struct tape_device *device)
{
tapechar_cleanup_device(device);
device->discipline->cleanup_device(device);
module_put(device->discipline->owner);
tape_remove_minor(device);
tape_med_state_set(device, MS_UNKNOWN);
}
int tape_generic_pm_suspend(struct ccw_device *cdev)
{
struct tape_device *device;
device = dev_get_drvdata(&cdev->dev);
if (!device) {
return -ENODEV;
}
DBF_LH(3, "(%08x): tape_generic_pm_suspend(%p)\n",
device->cdev_id, device);
if (device->medium_state != MS_UNLOADED) {
pr_err("A cartridge is loaded in tape device %s, "
"refusing to suspend\n", dev_name(&cdev->dev));
return -EBUSY;
}
spin_lock_irq(get_ccwdev_lock(device->cdev));
switch (device->tape_state) {
case TS_INIT:
case TS_NOT_OPER:
case TS_UNUSED:
spin_unlock_irq(get_ccwdev_lock(device->cdev));
break;
default:
pr_err("Tape device %s is busy, refusing to "
"suspend\n", dev_name(&cdev->dev));
spin_unlock_irq(get_ccwdev_lock(device->cdev));
return -EBUSY;
}
DBF_LH(3, "(%08x): Drive suspended.\n", device->cdev_id);
return 0;
}
int
tape_generic_offline(struct ccw_device *cdev)
{
struct tape_device *device;
device = dev_get_drvdata(&cdev->dev);
if (!device) {
return -ENODEV;
}
DBF_LH(3, "(%08x): tape_generic_offline(%p)\n",
device->cdev_id, device);
spin_lock_irq(get_ccwdev_lock(device->cdev));
switch (device->tape_state) {
case TS_INIT:
case TS_NOT_OPER:
spin_unlock_irq(get_ccwdev_lock(device->cdev));
break;
case TS_UNUSED:
tape_state_set(device, TS_INIT);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
tape_cleanup_device(device);
break;
default:
DBF_EVENT(3, "(%08x): Set offline failed "
"- drive in use.\n",
device->cdev_id);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
return -EBUSY;
}
DBF_LH(3, "(%08x): Drive set offline.\n", device->cdev_id);
return 0;
}
static struct tape_device *
tape_alloc_device(void)
{
struct tape_device *device;
device = kzalloc(sizeof(struct tape_device), GFP_KERNEL);
if (device == NULL) {
DBF_EXCEPTION(2, "ti:no mem\n");
return ERR_PTR(-ENOMEM);
}
device->modeset_byte = kmalloc(1, GFP_KERNEL | GFP_DMA);
if (device->modeset_byte == NULL) {
DBF_EXCEPTION(2, "ti:no mem\n");
kfree(device);
return ERR_PTR(-ENOMEM);
}
mutex_init(&device->mutex);
INIT_LIST_HEAD(&device->req_queue);
INIT_LIST_HEAD(&device->node);
init_waitqueue_head(&device->state_change_wq);
init_waitqueue_head(&device->wait_queue);
device->tape_state = TS_INIT;
device->medium_state = MS_UNKNOWN;
*device->modeset_byte = 0;
device->first_minor = -1;
atomic_set(&device->ref_count, 1);
INIT_DELAYED_WORK(&device->tape_dnr, tape_delayed_next_request);
return device;
}
struct tape_device *
tape_get_device(struct tape_device *device)
{
int count;
count = atomic_inc_return(&device->ref_count);
DBF_EVENT(4, "tape_get_device(%p) = %i\n", device, count);
return device;
}
void
tape_put_device(struct tape_device *device)
{
int count;
count = atomic_dec_return(&device->ref_count);
DBF_EVENT(4, "tape_put_device(%p) -> %i\n", device, count);
BUG_ON(count < 0);
if (count == 0) {
kfree(device->modeset_byte);
kfree(device);
}
}
struct tape_device *
tape_find_device(int devindex)
{
struct tape_device *device, *tmp;
device = ERR_PTR(-ENODEV);
read_lock(&tape_device_lock);
list_for_each_entry(tmp, &tape_device_list, node) {
if (tmp->first_minor / TAPE_MINORS_PER_DEV == devindex) {
device = tape_get_device(tmp);
break;
}
}
read_unlock(&tape_device_lock);
return device;
}
int
tape_generic_probe(struct ccw_device *cdev)
{
struct tape_device *device;
int ret;
struct ccw_dev_id dev_id;
device = tape_alloc_device();
if (IS_ERR(device))
return -ENODEV;
ccw_device_set_options(cdev, CCWDEV_DO_PATHGROUP |
CCWDEV_DO_MULTIPATH);
ret = sysfs_create_group(&cdev->dev.kobj, &tape_attr_group);
if (ret) {
tape_put_device(device);
return ret;
}
dev_set_drvdata(&cdev->dev, device);
cdev->handler = __tape_do_irq;
device->cdev = cdev;
ccw_device_get_id(cdev, &dev_id);
device->cdev_id = devid_to_int(&dev_id);
return ret;
}
static void
__tape_discard_requests(struct tape_device *device)
{
struct tape_request * request;
struct list_head * l, *n;
list_for_each_safe(l, n, &device->req_queue) {
request = list_entry(l, struct tape_request, list);
if (request->status == TAPE_REQUEST_IN_IO)
request->status = TAPE_REQUEST_DONE;
list_del(&request->list);
request->device = NULL;
tape_put_device(device);
request->rc = -EIO;
if (request->callback != NULL)
request->callback(request, request->callback_data);
}
}
void
tape_generic_remove(struct ccw_device *cdev)
{
struct tape_device * device;
device = dev_get_drvdata(&cdev->dev);
if (!device) {
return;
}
DBF_LH(3, "(%08x): tape_generic_remove(%p)\n", device->cdev_id, cdev);
spin_lock_irq(get_ccwdev_lock(device->cdev));
switch (device->tape_state) {
case TS_INIT:
tape_state_set(device, TS_NOT_OPER);
case TS_NOT_OPER:
spin_unlock_irq(get_ccwdev_lock(device->cdev));
break;
case TS_UNUSED:
tape_state_set(device, TS_NOT_OPER);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
tape_cleanup_device(device);
break;
default:
DBF_EVENT(3, "(%08x): Drive in use vanished!\n",
device->cdev_id);
pr_warning("%s: A tape unit was detached while in "
"use\n", dev_name(&device->cdev->dev));
tape_state_set(device, TS_NOT_OPER);
__tape_discard_requests(device);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
tape_cleanup_device(device);
}
device = dev_get_drvdata(&cdev->dev);
if (device) {
sysfs_remove_group(&cdev->dev.kobj, &tape_attr_group);
dev_set_drvdata(&cdev->dev, NULL);
tape_put_device(device);
}
}
struct tape_request *
tape_alloc_request(int cplength, int datasize)
{
struct tape_request *request;
BUG_ON(datasize > PAGE_SIZE || (cplength*sizeof(struct ccw1)) > PAGE_SIZE);
DBF_LH(6, "tape_alloc_request(%d, %d)\n", cplength, datasize);
request = kzalloc(sizeof(struct tape_request), GFP_KERNEL);
if (request == NULL) {
DBF_EXCEPTION(1, "cqra nomem\n");
return ERR_PTR(-ENOMEM);
}
if (cplength > 0) {
request->cpaddr = kcalloc(cplength, sizeof(struct ccw1),
GFP_ATOMIC | GFP_DMA);
if (request->cpaddr == NULL) {
DBF_EXCEPTION(1, "cqra nomem\n");
kfree(request);
return ERR_PTR(-ENOMEM);
}
}
if (datasize > 0) {
request->cpdata = kzalloc(datasize, GFP_KERNEL | GFP_DMA);
if (request->cpdata == NULL) {
DBF_EXCEPTION(1, "cqra nomem\n");
kfree(request->cpaddr);
kfree(request);
return ERR_PTR(-ENOMEM);
}
}
DBF_LH(6, "New request %p(%p/%p)\n", request, request->cpaddr,
request->cpdata);
return request;
}
void
tape_free_request (struct tape_request * request)
{
DBF_LH(6, "Free request %p\n", request);
if (request->device)
tape_put_device(request->device);
kfree(request->cpdata);
kfree(request->cpaddr);
kfree(request);
}
static int
__tape_start_io(struct tape_device *device, struct tape_request *request)
{
int rc;
rc = ccw_device_start(
device->cdev,
request->cpaddr,
(unsigned long) request,
0x00,
request->options
);
if (rc == 0) {
request->status = TAPE_REQUEST_IN_IO;
} else if (rc == -EBUSY) {
request->status = TAPE_REQUEST_QUEUED;
schedule_delayed_work(&device->tape_dnr, 0);
rc = 0;
} else {
DBF_EVENT(1, "tape: start request failed with RC = %i\n", rc);
}
return rc;
}
static void
__tape_start_next_request(struct tape_device *device)
{
struct list_head *l, *n;
struct tape_request *request;
int rc;
DBF_LH(6, "__tape_start_next_request(%p)\n", device);
list_for_each_safe(l, n, &device->req_queue) {
request = list_entry(l, struct tape_request, list);
if (request->status == TAPE_REQUEST_IN_IO)
return;
if (request->status == TAPE_REQUEST_DONE)
return;
if (request->status == TAPE_REQUEST_CANCEL) {
rc = __tape_cancel_io(device, request);
} else {
rc = __tape_start_io(device, request);
}
if (rc == 0)
return;
request->rc = rc;
request->status = TAPE_REQUEST_DONE;
list_del(&request->list);
if (request->callback != NULL)
request->callback(request, request->callback_data);
}
}
static void
tape_delayed_next_request(struct work_struct *work)
{
struct tape_device *device =
container_of(work, struct tape_device, tape_dnr.work);
DBF_LH(6, "tape_delayed_next_request(%p)\n", device);
spin_lock_irq(get_ccwdev_lock(device->cdev));
__tape_start_next_request(device);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
}
static void tape_long_busy_timeout(unsigned long data)
{
struct tape_request *request;
struct tape_device *device;
device = (struct tape_device *) data;
spin_lock_irq(get_ccwdev_lock(device->cdev));
request = list_entry(device->req_queue.next, struct tape_request, list);
BUG_ON(request->status != TAPE_REQUEST_LONG_BUSY);
DBF_LH(6, "%08x: Long busy timeout.\n", device->cdev_id);
__tape_start_next_request(device);
device->lb_timeout.data = 0UL;
tape_put_device(device);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
}
static void
__tape_end_request(
struct tape_device * device,
struct tape_request * request,
int rc)
{
DBF_LH(6, "__tape_end_request(%p, %p, %i)\n", device, request, rc);
if (request) {
request->rc = rc;
request->status = TAPE_REQUEST_DONE;
list_del(&request->list);
if (request->callback != NULL)
request->callback(request, request->callback_data);
}
if (!list_empty(&device->req_queue))
__tape_start_next_request(device);
}
void
tape_dump_sense_dbf(struct tape_device *device, struct tape_request *request,
struct irb *irb)
{
unsigned int *sptr;
const char* op;
if (request != NULL)
op = tape_op_verbose[request->op];
else
op = "---";
DBF_EVENT(3, "DSTAT : %02x CSTAT: %02x\n",
irb->scsw.cmd.dstat, irb->scsw.cmd.cstat);
DBF_EVENT(3, "DEVICE: %08x OP\t: %s\n", device->cdev_id, op);
sptr = (unsigned int *) irb->ecw;
DBF_EVENT(3, "%08x %08x\n", sptr[0], sptr[1]);
DBF_EVENT(3, "%08x %08x\n", sptr[2], sptr[3]);
DBF_EVENT(3, "%08x %08x\n", sptr[4], sptr[5]);
DBF_EVENT(3, "%08x %08x\n", sptr[6], sptr[7]);
}
static int
__tape_start_request(struct tape_device *device, struct tape_request *request)
{
int rc;
switch (request->op) {
case TO_MSEN:
case TO_ASSIGN:
case TO_UNASSIGN:
case TO_READ_ATTMSG:
case TO_RDC:
if (device->tape_state == TS_INIT)
break;
if (device->tape_state == TS_UNUSED)
break;
default:
if (device->tape_state == TS_BLKUSE)
break;
if (device->tape_state != TS_IN_USE)
return -ENODEV;
}
request->device = tape_get_device(device);
if (list_empty(&device->req_queue)) {
rc = __tape_start_io(device, request);
if (rc)
return rc;
DBF_LH(5, "Request %p added for execution.\n", request);
list_add(&request->list, &device->req_queue);
} else {
DBF_LH(5, "Request %p add to queue.\n", request);
request->status = TAPE_REQUEST_QUEUED;
list_add_tail(&request->list, &device->req_queue);
}
return 0;
}
int
tape_do_io_async(struct tape_device *device, struct tape_request *request)
{
int rc;
DBF_LH(6, "tape_do_io_async(%p, %p)\n", device, request);
spin_lock_irq(get_ccwdev_lock(device->cdev));
rc = __tape_start_request(device, request);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
return rc;
}
static void
__tape_wake_up(struct tape_request *request, void *data)
{
request->callback = NULL;
wake_up((wait_queue_head_t *) data);
}
int
tape_do_io(struct tape_device *device, struct tape_request *request)
{
int rc;
spin_lock_irq(get_ccwdev_lock(device->cdev));
request->callback = __tape_wake_up;
request->callback_data = &device->wait_queue;
rc = __tape_start_request(device, request);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
if (rc)
return rc;
wait_event(device->wait_queue, (request->callback == NULL));
return request->rc;
}
static void
__tape_wake_up_interruptible(struct tape_request *request, void *data)
{
request->callback = NULL;
wake_up_interruptible((wait_queue_head_t *) data);
}
int
tape_do_io_interruptible(struct tape_device *device,
struct tape_request *request)
{
int rc;
spin_lock_irq(get_ccwdev_lock(device->cdev));
request->callback = __tape_wake_up_interruptible;
request->callback_data = &device->wait_queue;
rc = __tape_start_request(device, request);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
if (rc)
return rc;
rc = wait_event_interruptible(device->wait_queue,
(request->callback == NULL));
if (rc != -ERESTARTSYS)
return request->rc;
spin_lock_irq(get_ccwdev_lock(device->cdev));
rc = __tape_cancel_io(device, request);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
if (rc == 0) {
do {
rc = wait_event_interruptible(
device->wait_queue,
(request->callback == NULL)
);
} while (rc == -ERESTARTSYS);
DBF_EVENT(3, "IO stopped on %08x\n", device->cdev_id);
rc = -ERESTARTSYS;
}
return rc;
}
int
tape_cancel_io(struct tape_device *device, struct tape_request *request)
{
int rc;
spin_lock_irq(get_ccwdev_lock(device->cdev));
rc = __tape_cancel_io(device, request);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
return rc;
}
static void
__tape_do_irq (struct ccw_device *cdev, unsigned long intparm, struct irb *irb)
{
struct tape_device *device;
struct tape_request *request;
int rc;
device = dev_get_drvdata(&cdev->dev);
if (device == NULL) {
return;
}
request = (struct tape_request *) intparm;
DBF_LH(6, "__tape_do_irq(device=%p, request=%p)\n", device, request);
if (IS_ERR(irb)) {
switch (PTR_ERR(irb)) {
case -ETIMEDOUT:
DBF_LH(1, "(%08x): Request timed out\n",
device->cdev_id);
case -EIO:
__tape_end_request(device, request, -EIO);
break;
default:
DBF_LH(1, "(%08x): Unexpected i/o error %li\n",
device->cdev_id, PTR_ERR(irb));
}
return;
}
if (irb->scsw.cmd.cc != 0 &&
(irb->scsw.cmd.fctl & SCSW_FCTL_START_FUNC) &&
(request->status == TAPE_REQUEST_IN_IO)) {
DBF_EVENT(3,"(%08x): deferred cc=%i, fctl=%i. restarting\n",
device->cdev_id, irb->scsw.cmd.cc, irb->scsw.cmd.fctl);
request->status = TAPE_REQUEST_QUEUED;
schedule_delayed_work(&device->tape_dnr, HZ);
return;
}
if(request != NULL)
request->rescnt = irb->scsw.cmd.count;
else if ((irb->scsw.cmd.dstat == 0x85 || irb->scsw.cmd.dstat == 0x80) &&
!list_empty(&device->req_queue)) {
struct tape_request *req;
req = list_entry(device->req_queue.next,
struct tape_request, list);
if (req->status == TAPE_REQUEST_LONG_BUSY) {
DBF_EVENT(3, "(%08x): del timer\n", device->cdev_id);
if (del_timer(&device->lb_timeout)) {
device->lb_timeout.data = 0UL;
tape_put_device(device);
__tape_start_next_request(device);
}
return;
}
}
if (irb->scsw.cmd.dstat != 0x0c) {
if(*(((__u8 *) irb->ecw) + 1) & SENSE_DRIVE_ONLINE)
device->tape_generic_status |= GMT_ONLINE(~0);
else
device->tape_generic_status &= ~GMT_ONLINE(~0);
DBF_EVENT(3,"-- Tape Interrupthandler --\n");
tape_dump_sense_dbf(device, request, irb);
} else {
device->tape_generic_status |= GMT_ONLINE(~0);
}
if (device->tape_state == TS_NOT_OPER) {
DBF_EVENT(6, "tape:device is not operational\n");
return;
}
if(request != NULL && request->status == TAPE_REQUEST_DONE) {
__tape_end_request(device, request, -EIO);
return;
}
rc = device->discipline->irq(device, request, irb);
switch (rc) {
case TAPE_IO_SUCCESS:
device->tape_generic_status |= GMT_ONLINE(~0);
__tape_end_request(device, request, rc);
break;
case TAPE_IO_PENDING:
break;
case TAPE_IO_LONG_BUSY:
device->lb_timeout.data =
(unsigned long) tape_get_device(device);
device->lb_timeout.expires = jiffies +
LONG_BUSY_TIMEOUT * HZ;
DBF_EVENT(3, "(%08x): add timer\n", device->cdev_id);
add_timer(&device->lb_timeout);
request->status = TAPE_REQUEST_LONG_BUSY;
break;
case TAPE_IO_RETRY:
rc = __tape_start_io(device, request);
if (rc)
__tape_end_request(device, request, rc);
break;
case TAPE_IO_STOP:
rc = __tape_cancel_io(device, request);
if (rc)
__tape_end_request(device, request, rc);
break;
default:
if (rc > 0) {
DBF_EVENT(6, "xunknownrc\n");
__tape_end_request(device, request, -EIO);
} else {
__tape_end_request(device, request, rc);
}
break;
}
}
int
tape_open(struct tape_device *device)
{
int rc;
spin_lock_irq(get_ccwdev_lock(device->cdev));
if (device->tape_state == TS_NOT_OPER) {
DBF_EVENT(6, "TAPE:nodev\n");
rc = -ENODEV;
} else if (device->tape_state == TS_IN_USE) {
DBF_EVENT(6, "TAPE:dbusy\n");
rc = -EBUSY;
} else if (device->tape_state == TS_BLKUSE) {
DBF_EVENT(6, "TAPE:dbusy\n");
rc = -EBUSY;
} else if (device->discipline != NULL &&
!try_module_get(device->discipline->owner)) {
DBF_EVENT(6, "TAPE:nodisc\n");
rc = -ENODEV;
} else {
tape_state_set(device, TS_IN_USE);
rc = 0;
}
spin_unlock_irq(get_ccwdev_lock(device->cdev));
return rc;
}
int
tape_release(struct tape_device *device)
{
spin_lock_irq(get_ccwdev_lock(device->cdev));
if (device->tape_state == TS_IN_USE)
tape_state_set(device, TS_UNUSED);
module_put(device->discipline->owner);
spin_unlock_irq(get_ccwdev_lock(device->cdev));
return 0;
}
int
tape_mtop(struct tape_device *device, int mt_op, int mt_count)
{
tape_mtop_fn fn;
int rc;
DBF_EVENT(6, "TAPE:mtio\n");
DBF_EVENT(6, "TAPE:ioop: %x\n", mt_op);
DBF_EVENT(6, "TAPE:arg: %x\n", mt_count);
if (mt_op < 0 || mt_op >= TAPE_NR_MTOPS)
return -EINVAL;
fn = device->discipline->mtop_array[mt_op];
if (fn == NULL)
return -EINVAL;
if (mt_op == MTBSR || mt_op == MTFSR || mt_op == MTFSF ||
mt_op == MTBSF || mt_op == MTFSFM || mt_op == MTBSFM) {
rc = 0;
for (; mt_count > 500; mt_count -= 500)
if ((rc = fn(device, 500)) != 0)
break;
if (rc == 0)
rc = fn(device, mt_count);
} else
rc = fn(device, mt_count);
return rc;
}
static int
tape_init (void)
{
TAPE_DBF_AREA = debug_register ( "tape", 2, 2, 4*sizeof(long));
debug_register_view(TAPE_DBF_AREA, &debug_sprintf_view);
#ifdef DBF_LIKE_HELL
debug_set_level(TAPE_DBF_AREA, 6);
#endif
DBF_EVENT(3, "tape init\n");
tape_proc_init();
tapechar_init ();
return 0;
}
static void
tape_exit(void)
{
DBF_EVENT(6, "tape exit\n");
tapechar_exit();
tape_proc_cleanup();
debug_unregister (TAPE_DBF_AREA);
}
