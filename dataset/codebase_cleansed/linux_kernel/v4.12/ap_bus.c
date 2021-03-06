static inline int ap_using_interrupts(void)
{
return ap_airq_flag;
}
void *ap_airq_ptr(void)
{
if (ap_using_interrupts())
return ap_airq.lsi_ptr;
return NULL;
}
static int ap_interrupts_available(void)
{
return test_facility(65);
}
static int ap_configuration_available(void)
{
return test_facility(12);
}
static inline struct ap_queue_status
ap_test_queue(ap_qid_t qid, unsigned long *info)
{
if (test_facility(15))
qid |= 1UL << 23;
return ap_tapq(qid, info);
}
static inline int ap_query_configuration(void)
{
if (!ap_configuration)
return -EOPNOTSUPP;
return ap_qci(ap_configuration);
}
static void ap_init_configuration(void)
{
if (!ap_configuration_available())
return;
ap_configuration = kzalloc(sizeof(*ap_configuration), GFP_KERNEL);
if (!ap_configuration)
return;
if (ap_query_configuration() != 0) {
kfree(ap_configuration);
ap_configuration = NULL;
return;
}
}
static inline int ap_test_config(unsigned int *field, unsigned int nr)
{
return ap_test_bit((field + (nr >> 5)), (nr & 0x1f));
}
static inline int ap_test_config_card_id(unsigned int id)
{
if (!ap_configuration)
return 1;
return ap_test_config(ap_configuration->apm, id);
}
static inline int ap_test_config_domain(unsigned int domain)
{
if (!ap_configuration)
return domain < 16;
return ap_test_config(ap_configuration->aqm, domain);
}
static int ap_query_queue(ap_qid_t qid, int *queue_depth, int *device_type,
unsigned int *facilities)
{
struct ap_queue_status status;
unsigned long info;
int nd;
if (!ap_test_config_card_id(AP_QID_CARD(qid)))
return -ENODEV;
status = ap_test_queue(qid, &info);
switch (status.response_code) {
case AP_RESPONSE_NORMAL:
*queue_depth = (int)(info & 0xff);
*device_type = (int)((info >> 24) & 0xff);
*facilities = (unsigned int)(info >> 32);
nd = (info >> 16) & 0xff;
if ((info & (1UL << 57)) && nd > 0)
ap_max_domain_id = nd;
else
ap_max_domain_id = 15;
switch (*device_type) {
case AP_DEVICE_TYPE_CEX2A:
case AP_DEVICE_TYPE_CEX3A:
*facilities |= 0x08000000;
break;
case AP_DEVICE_TYPE_CEX2C:
case AP_DEVICE_TYPE_CEX3C:
*facilities |= 0x10000000;
break;
default:
break;
}
return 0;
case AP_RESPONSE_Q_NOT_AVAIL:
case AP_RESPONSE_DECONFIGURED:
case AP_RESPONSE_CHECKSTOPPED:
case AP_RESPONSE_INVALID_ADDRESS:
return -ENODEV;
case AP_RESPONSE_RESET_IN_PROGRESS:
case AP_RESPONSE_OTHERWISE_CHANGED:
case AP_RESPONSE_BUSY:
return -EBUSY;
default:
BUG();
}
}
void ap_wait(enum ap_wait wait)
{
ktime_t hr_time;
switch (wait) {
case AP_WAIT_AGAIN:
case AP_WAIT_INTERRUPT:
if (ap_using_interrupts())
break;
if (ap_poll_kthread) {
wake_up(&ap_poll_wait);
break;
}
case AP_WAIT_TIMEOUT:
spin_lock_bh(&ap_poll_timer_lock);
if (!hrtimer_is_queued(&ap_poll_timer)) {
hr_time = poll_timeout;
hrtimer_forward_now(&ap_poll_timer, hr_time);
hrtimer_restart(&ap_poll_timer);
}
spin_unlock_bh(&ap_poll_timer_lock);
break;
case AP_WAIT_NONE:
default:
break;
}
}
void ap_request_timeout(unsigned long data)
{
struct ap_queue *aq = (struct ap_queue *) data;
if (ap_suspend_flag)
return;
spin_lock_bh(&aq->lock);
ap_wait(ap_sm_event(aq, AP_EVENT_TIMEOUT));
spin_unlock_bh(&aq->lock);
}
static enum hrtimer_restart ap_poll_timeout(struct hrtimer *unused)
{
if (!ap_suspend_flag)
tasklet_schedule(&ap_tasklet);
return HRTIMER_NORESTART;
}
static void ap_interrupt_handler(struct airq_struct *airq)
{
inc_irq_stat(IRQIO_APB);
if (!ap_suspend_flag)
tasklet_schedule(&ap_tasklet);
}
static void ap_tasklet_fn(unsigned long dummy)
{
struct ap_card *ac;
struct ap_queue *aq;
enum ap_wait wait = AP_WAIT_NONE;
if (ap_using_interrupts())
xchg(ap_airq.lsi_ptr, 0);
spin_lock_bh(&ap_list_lock);
for_each_ap_card(ac) {
for_each_ap_queue(aq, ac) {
spin_lock_bh(&aq->lock);
wait = min(wait, ap_sm_event_loop(aq, AP_EVENT_POLL));
spin_unlock_bh(&aq->lock);
}
}
spin_unlock_bh(&ap_list_lock);
ap_wait(wait);
}
static int ap_pending_requests(void)
{
struct ap_card *ac;
struct ap_queue *aq;
spin_lock_bh(&ap_list_lock);
for_each_ap_card(ac) {
for_each_ap_queue(aq, ac) {
if (aq->queue_count == 0)
continue;
spin_unlock_bh(&ap_list_lock);
return 1;
}
}
spin_unlock_bh(&ap_list_lock);
return 0;
}
static int ap_poll_thread(void *data)
{
DECLARE_WAITQUEUE(wait, current);
set_user_nice(current, MAX_NICE);
set_freezable();
while (!kthread_should_stop()) {
add_wait_queue(&ap_poll_wait, &wait);
set_current_state(TASK_INTERRUPTIBLE);
if (ap_suspend_flag || !ap_pending_requests()) {
schedule();
try_to_freeze();
}
set_current_state(TASK_RUNNING);
remove_wait_queue(&ap_poll_wait, &wait);
if (need_resched()) {
schedule();
try_to_freeze();
continue;
}
ap_tasklet_fn(0);
}
return 0;
}
static int ap_poll_thread_start(void)
{
int rc;
if (ap_using_interrupts() || ap_poll_kthread)
return 0;
mutex_lock(&ap_poll_thread_mutex);
ap_poll_kthread = kthread_run(ap_poll_thread, NULL, "appoll");
rc = PTR_RET(ap_poll_kthread);
if (rc)
ap_poll_kthread = NULL;
mutex_unlock(&ap_poll_thread_mutex);
return rc;
}
static void ap_poll_thread_stop(void)
{
if (!ap_poll_kthread)
return;
mutex_lock(&ap_poll_thread_mutex);
kthread_stop(ap_poll_kthread);
ap_poll_kthread = NULL;
mutex_unlock(&ap_poll_thread_mutex);
}
static int ap_bus_match(struct device *dev, struct device_driver *drv)
{
struct ap_driver *ap_drv = to_ap_drv(drv);
struct ap_device_id *id;
for (id = ap_drv->ids; id->match_flags; id++) {
if (is_card_dev(dev) &&
id->match_flags & AP_DEVICE_ID_MATCH_CARD_TYPE &&
id->dev_type == to_ap_dev(dev)->device_type)
return 1;
if (is_queue_dev(dev) &&
id->match_flags & AP_DEVICE_ID_MATCH_QUEUE_TYPE &&
id->dev_type == to_ap_dev(dev)->device_type)
return 1;
}
return 0;
}
static int ap_uevent (struct device *dev, struct kobj_uevent_env *env)
{
struct ap_device *ap_dev = to_ap_dev(dev);
int retval = 0;
if (!ap_dev)
return -ENODEV;
retval = add_uevent_var(env, "DEV_TYPE=%04X", ap_dev->device_type);
if (retval)
return retval;
retval = add_uevent_var(env, "MODALIAS=ap:t%02X", ap_dev->device_type);
return retval;
}
static int ap_dev_suspend(struct device *dev)
{
struct ap_device *ap_dev = to_ap_dev(dev);
if (ap_dev->drv && ap_dev->drv->suspend)
ap_dev->drv->suspend(ap_dev);
return 0;
}
static int ap_dev_resume(struct device *dev)
{
struct ap_device *ap_dev = to_ap_dev(dev);
if (ap_dev->drv && ap_dev->drv->resume)
ap_dev->drv->resume(ap_dev);
return 0;
}
static void ap_bus_suspend(void)
{
AP_DBF(DBF_DEBUG, "ap_bus_suspend running\n");
ap_suspend_flag = 1;
flush_work(&ap_scan_work);
tasklet_disable(&ap_tasklet);
}
static int __ap_card_devices_unregister(struct device *dev, void *dummy)
{
if (is_card_dev(dev))
device_unregister(dev);
return 0;
}
static int __ap_queue_devices_unregister(struct device *dev, void *dummy)
{
if (is_queue_dev(dev))
device_unregister(dev);
return 0;
}
static int __ap_queue_devices_with_id_unregister(struct device *dev, void *data)
{
if (is_queue_dev(dev) &&
AP_QID_CARD(to_ap_queue(dev)->qid) == (int)(long) data)
device_unregister(dev);
return 0;
}
static void ap_bus_resume(void)
{
int rc;
AP_DBF(DBF_DEBUG, "ap_bus_resume running\n");
bus_for_each_dev(&ap_bus_type, NULL, NULL,
__ap_queue_devices_unregister);
bus_for_each_dev(&ap_bus_type, NULL, NULL,
__ap_card_devices_unregister);
if (ap_interrupts_available() && !ap_using_interrupts()) {
rc = register_adapter_interrupt(&ap_airq);
ap_airq_flag = (rc == 0);
}
if (!ap_interrupts_available() && ap_using_interrupts()) {
unregister_adapter_interrupt(&ap_airq);
ap_airq_flag = 0;
}
if (!user_set_domain)
ap_domain_index = -1;
ap_suspend_flag = 0;
if (ap_airq_flag)
xchg(ap_airq.lsi_ptr, 0);
tasklet_enable(&ap_tasklet);
queue_work(system_long_wq, &ap_scan_work);
}
static int ap_power_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
switch (event) {
case PM_HIBERNATION_PREPARE:
case PM_SUSPEND_PREPARE:
ap_bus_suspend();
break;
case PM_POST_HIBERNATION:
case PM_POST_SUSPEND:
ap_bus_resume();
break;
default:
break;
}
return NOTIFY_DONE;
}
static int ap_device_probe(struct device *dev)
{
struct ap_device *ap_dev = to_ap_dev(dev);
struct ap_driver *ap_drv = to_ap_drv(dev->driver);
int rc;
spin_lock_bh(&ap_list_lock);
if (is_card_dev(dev))
list_add(&to_ap_card(dev)->list, &ap_card_list);
else
list_add(&to_ap_queue(dev)->list,
&to_ap_queue(dev)->card->queues);
spin_unlock_bh(&ap_list_lock);
ap_dev->drv = ap_drv;
rc = ap_drv->probe ? ap_drv->probe(ap_dev) : -ENODEV;
if (rc) {
spin_lock_bh(&ap_list_lock);
if (is_card_dev(dev))
list_del_init(&to_ap_card(dev)->list);
else
list_del_init(&to_ap_queue(dev)->list);
spin_unlock_bh(&ap_list_lock);
ap_dev->drv = NULL;
}
return rc;
}
static int ap_device_remove(struct device *dev)
{
struct ap_device *ap_dev = to_ap_dev(dev);
struct ap_driver *ap_drv = ap_dev->drv;
if (ap_drv->remove)
ap_drv->remove(ap_dev);
spin_lock_bh(&ap_list_lock);
if (is_card_dev(dev))
list_del_init(&to_ap_card(dev)->list);
else
list_del_init(&to_ap_queue(dev)->list);
spin_unlock_bh(&ap_list_lock);
return 0;
}
int ap_driver_register(struct ap_driver *ap_drv, struct module *owner,
char *name)
{
struct device_driver *drv = &ap_drv->driver;
if (!initialised)
return -ENODEV;
drv->bus = &ap_bus_type;
drv->probe = ap_device_probe;
drv->remove = ap_device_remove;
drv->owner = owner;
drv->name = name;
return driver_register(drv);
}
void ap_driver_unregister(struct ap_driver *ap_drv)
{
driver_unregister(&ap_drv->driver);
}
void ap_bus_force_rescan(void)
{
if (ap_suspend_flag)
return;
del_timer(&ap_config_timer);
queue_work(system_long_wq, &ap_scan_work);
flush_work(&ap_scan_work);
}
static ssize_t ap_domain_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", ap_domain_index);
}
static ssize_t ap_domain_store(struct bus_type *bus,
const char *buf, size_t count)
{
int domain;
if (sscanf(buf, "%i\n", &domain) != 1 ||
domain < 0 || domain > ap_max_domain_id)
return -EINVAL;
spin_lock_bh(&ap_domain_lock);
ap_domain_index = domain;
spin_unlock_bh(&ap_domain_lock);
AP_DBF(DBF_DEBUG, "store new default domain=%d\n", domain);
return count;
}
static ssize_t ap_control_domain_mask_show(struct bus_type *bus, char *buf)
{
if (!ap_configuration)
return snprintf(buf, PAGE_SIZE, "not supported\n");
return snprintf(buf, PAGE_SIZE,
"0x%08x%08x%08x%08x%08x%08x%08x%08x\n",
ap_configuration->adm[0], ap_configuration->adm[1],
ap_configuration->adm[2], ap_configuration->adm[3],
ap_configuration->adm[4], ap_configuration->adm[5],
ap_configuration->adm[6], ap_configuration->adm[7]);
}
static ssize_t ap_usage_domain_mask_show(struct bus_type *bus, char *buf)
{
if (!ap_configuration)
return snprintf(buf, PAGE_SIZE, "not supported\n");
return snprintf(buf, PAGE_SIZE,
"0x%08x%08x%08x%08x%08x%08x%08x%08x\n",
ap_configuration->aqm[0], ap_configuration->aqm[1],
ap_configuration->aqm[2], ap_configuration->aqm[3],
ap_configuration->aqm[4], ap_configuration->aqm[5],
ap_configuration->aqm[6], ap_configuration->aqm[7]);
}
static ssize_t ap_config_time_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", ap_config_time);
}
static ssize_t ap_interrupts_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n",
ap_using_interrupts() ? 1 : 0);
}
static ssize_t ap_config_time_store(struct bus_type *bus,
const char *buf, size_t count)
{
int time;
if (sscanf(buf, "%d\n", &time) != 1 || time < 5 || time > 120)
return -EINVAL;
ap_config_time = time;
mod_timer(&ap_config_timer, jiffies + ap_config_time * HZ);
return count;
}
static ssize_t ap_poll_thread_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", ap_poll_kthread ? 1 : 0);
}
static ssize_t ap_poll_thread_store(struct bus_type *bus,
const char *buf, size_t count)
{
int flag, rc;
if (sscanf(buf, "%d\n", &flag) != 1)
return -EINVAL;
if (flag) {
rc = ap_poll_thread_start();
if (rc)
count = rc;
} else
ap_poll_thread_stop();
return count;
}
static ssize_t poll_timeout_show(struct bus_type *bus, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%llu\n", poll_timeout);
}
static ssize_t poll_timeout_store(struct bus_type *bus, const char *buf,
size_t count)
{
unsigned long long time;
ktime_t hr_time;
if (sscanf(buf, "%llu\n", &time) != 1 || time < 1 ||
time > 120000000000ULL)
return -EINVAL;
poll_timeout = time;
hr_time = poll_timeout;
spin_lock_bh(&ap_poll_timer_lock);
hrtimer_cancel(&ap_poll_timer);
hrtimer_set_expires(&ap_poll_timer, hr_time);
hrtimer_start_expires(&ap_poll_timer, HRTIMER_MODE_ABS);
spin_unlock_bh(&ap_poll_timer_lock);
return count;
}
static ssize_t ap_max_domain_id_show(struct bus_type *bus, char *buf)
{
int max_domain_id;
if (ap_configuration)
max_domain_id = ap_max_domain_id ? : -1;
else
max_domain_id = 15;
return snprintf(buf, PAGE_SIZE, "%d\n", max_domain_id);
}
static int ap_select_domain(void)
{
int count, max_count, best_domain;
struct ap_queue_status status;
int i, j;
spin_lock_bh(&ap_domain_lock);
if (ap_domain_index >= 0) {
spin_unlock_bh(&ap_domain_lock);
return 0;
}
best_domain = -1;
max_count = 0;
for (i = 0; i < AP_DOMAINS; i++) {
if (!ap_test_config_domain(i))
continue;
count = 0;
for (j = 0; j < AP_DEVICES; j++) {
if (!ap_test_config_card_id(j))
continue;
status = ap_test_queue(AP_MKQID(j, i), NULL);
if (status.response_code != AP_RESPONSE_NORMAL)
continue;
count++;
}
if (count > max_count) {
max_count = count;
best_domain = i;
}
}
if (best_domain >= 0){
ap_domain_index = best_domain;
spin_unlock_bh(&ap_domain_lock);
return 0;
}
spin_unlock_bh(&ap_domain_lock);
return -ENODEV;
}
static int __match_card_device_with_id(struct device *dev, void *data)
{
return is_card_dev(dev) && to_ap_card(dev)->id == (int)(long) data;
}
static int __match_queue_device_with_qid(struct device *dev, void *data)
{
return is_queue_dev(dev) && to_ap_queue(dev)->qid == (int)(long) data;
}
static void ap_scan_bus(struct work_struct *unused)
{
struct ap_queue *aq;
struct ap_card *ac;
struct device *dev;
ap_qid_t qid;
int depth = 0, type = 0;
unsigned int functions = 0;
int rc, id, dom, borked, domains;
AP_DBF(DBF_DEBUG, "ap_scan_bus running\n");
ap_query_configuration();
if (ap_select_domain() != 0)
goto out;
for (id = 0; id < AP_DEVICES; id++) {
dev = bus_find_device(&ap_bus_type, NULL,
(void *)(long) id,
__match_card_device_with_id);
ac = dev ? to_ap_card(dev) : NULL;
if (!ap_test_config_card_id(id)) {
if (dev) {
bus_for_each_dev(&ap_bus_type, NULL,
(void *)(long) id,
__ap_queue_devices_with_id_unregister);
device_unregister(dev);
put_device(dev);
}
continue;
}
domains = 0;
for (dom = 0; dom < AP_DOMAINS; dom++) {
qid = AP_MKQID(id, dom);
dev = bus_find_device(&ap_bus_type, NULL,
(void *)(long) qid,
__match_queue_device_with_qid);
aq = dev ? to_ap_queue(dev) : NULL;
if (!ap_test_config_domain(dom)) {
if (dev) {
device_unregister(dev);
put_device(dev);
}
continue;
}
rc = ap_query_queue(qid, &depth, &type, &functions);
if (dev) {
spin_lock_bh(&aq->lock);
if (rc == -ENODEV ||
(ac && ac->functions != functions))
aq->state = AP_STATE_BORKED;
borked = aq->state == AP_STATE_BORKED;
spin_unlock_bh(&aq->lock);
if (borked)
device_unregister(dev);
put_device(dev);
if (!borked) {
domains++;
continue;
}
}
if (rc)
continue;
if (!ac) {
ac = ap_card_create(id, depth,
type, functions);
if (!ac)
continue;
ac->ap_dev.device.bus = &ap_bus_type;
ac->ap_dev.device.parent = ap_root_device;
dev_set_name(&ac->ap_dev.device,
"card%02x", id);
rc = device_register(&ac->ap_dev.device);
if (rc) {
put_device(&ac->ap_dev.device);
ac = NULL;
break;
}
get_device(&ac->ap_dev.device);
}
aq = ap_queue_create(qid, type);
if (!aq)
continue;
aq->card = ac;
aq->ap_dev.device.bus = &ap_bus_type;
aq->ap_dev.device.parent = &ac->ap_dev.device;
dev_set_name(&aq->ap_dev.device,
"%02x.%04x", id, dom);
spin_lock_bh(&aq->lock);
ap_wait(ap_sm_event(aq, AP_EVENT_POLL));
spin_unlock_bh(&aq->lock);
rc = device_register(&aq->ap_dev.device);
if (rc) {
put_device(&aq->ap_dev.device);
continue;
}
domains++;
}
if (ac) {
if (!domains)
device_unregister(&ac->ap_dev.device);
put_device(&ac->ap_dev.device);
}
}
out:
mod_timer(&ap_config_timer, jiffies + ap_config_time * HZ);
}
static void ap_config_timeout(unsigned long ptr)
{
if (ap_suspend_flag)
return;
queue_work(system_long_wq, &ap_scan_work);
}
static void ap_reset_all(void)
{
int i, j;
for (i = 0; i < AP_DOMAINS; i++) {
if (!ap_test_config_domain(i))
continue;
for (j = 0; j < AP_DEVICES; j++) {
if (!ap_test_config_card_id(j))
continue;
ap_rapq(AP_MKQID(j, i));
}
}
}
int __init ap_debug_init(void)
{
ap_dbf_info = debug_register("ap", 1, 1,
DBF_MAX_SPRINTF_ARGS * sizeof(long));
debug_register_view(ap_dbf_info, &debug_sprintf_view);
debug_set_level(ap_dbf_info, DBF_ERR);
return 0;
}
void ap_debug_exit(void)
{
debug_unregister(ap_dbf_info);
}
int __init ap_module_init(void)
{
int max_domain_id;
int rc, i;
rc = ap_debug_init();
if (rc)
return rc;
if (ap_instructions_available() != 0) {
pr_warn("The hardware system does not support AP instructions\n");
return -ENODEV;
}
ap_init_configuration();
if (ap_configuration)
max_domain_id = ap_max_domain_id ? : (AP_DOMAINS - 1);
else
max_domain_id = 15;
if (ap_domain_index < -1 || ap_domain_index > max_domain_id) {
pr_warn("%d is not a valid cryptographic domain\n",
ap_domain_index);
rc = -EINVAL;
goto out_free;
}
if (ap_domain_index >= 0)
user_set_domain = 1;
if (ap_interrupts_available()) {
rc = register_adapter_interrupt(&ap_airq);
ap_airq_flag = (rc == 0);
}
register_reset_call(&ap_reset_call);
rc = bus_register(&ap_bus_type);
if (rc)
goto out;
for (i = 0; ap_bus_attrs[i]; i++) {
rc = bus_create_file(&ap_bus_type, ap_bus_attrs[i]);
if (rc)
goto out_bus;
}
ap_root_device = root_device_register("ap");
rc = PTR_RET(ap_root_device);
if (rc)
goto out_bus;
setup_timer(&ap_config_timer, ap_config_timeout, 0);
if (MACHINE_IS_VM)
poll_timeout = 1500000;
spin_lock_init(&ap_poll_timer_lock);
hrtimer_init(&ap_poll_timer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
ap_poll_timer.function = ap_poll_timeout;
if (ap_thread_flag) {
rc = ap_poll_thread_start();
if (rc)
goto out_work;
}
rc = register_pm_notifier(&ap_power_notifier);
if (rc)
goto out_pm;
queue_work(system_long_wq, &ap_scan_work);
initialised = true;
return 0;
out_pm:
ap_poll_thread_stop();
out_work:
hrtimer_cancel(&ap_poll_timer);
root_device_unregister(ap_root_device);
out_bus:
while (i--)
bus_remove_file(&ap_bus_type, ap_bus_attrs[i]);
bus_unregister(&ap_bus_type);
out:
unregister_reset_call(&ap_reset_call);
if (ap_using_interrupts())
unregister_adapter_interrupt(&ap_airq);
out_free:
kfree(ap_configuration);
return rc;
}
