void usb_usual_set_present(int type)
{
struct mod_status *st;
unsigned long flags;
if (type <= 0 || type >= 3)
return;
st = &stat[type];
spin_lock_irqsave(&usu_lock, flags);
st->fls |= USU_MOD_FL_PRESENT;
spin_unlock_irqrestore(&usu_lock, flags);
}
void usb_usual_clear_present(int type)
{
struct mod_status *st;
unsigned long flags;
if (type <= 0 || type >= 3)
return;
st = &stat[type];
spin_lock_irqsave(&usu_lock, flags);
st->fls &= ~USU_MOD_FL_PRESENT;
spin_unlock_irqrestore(&usu_lock, flags);
}
int usb_usual_check_type(const struct usb_device_id *id, int caller_type)
{
int id_type = USB_US_TYPE(id->driver_info);
if (caller_type <= 0 || caller_type >= 3)
return -EINVAL;
if (id_type == caller_type)
return 0;
if (id_type == USB_US_TYPE_NONE && caller_type == atomic_read(&usu_bias))
return 0;
return -ENODEV;
}
static int usu_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
int rc;
unsigned long type;
struct task_struct* task;
unsigned long flags;
type = USB_US_TYPE(id->driver_info);
if (type == 0)
type = atomic_read(&usu_bias);
spin_lock_irqsave(&usu_lock, flags);
if ((stat[type].fls & (USU_MOD_FL_THREAD|USU_MOD_FL_PRESENT)) != 0) {
spin_unlock_irqrestore(&usu_lock, flags);
return -ENXIO;
}
stat[type].fls |= USU_MOD_FL_THREAD;
spin_unlock_irqrestore(&usu_lock, flags);
task = kthread_run(usu_probe_thread, (void*)type, "libusual_%ld", type);
if (IS_ERR(task)) {
rc = PTR_ERR(task);
printk(KERN_WARNING "libusual: "
"Unable to start the thread for %s: %d\n",
bias_names[type], rc);
spin_lock_irqsave(&usu_lock, flags);
stat[type].fls &= ~USU_MOD_FL_THREAD;
spin_unlock_irqrestore(&usu_lock, flags);
return rc;
}
atomic_inc(&total_threads);
return -ENXIO;
}
static void usu_disconnect(struct usb_interface *intf)
{
;
}
static int usu_probe_thread(void *arg)
{
int type = (unsigned long) arg;
struct mod_status *st = &stat[type];
int rc;
unsigned long flags;
mutex_lock(&usu_probe_mutex);
rc = request_module(bias_names[type]);
spin_lock_irqsave(&usu_lock, flags);
if (rc == 0 && (st->fls & USU_MOD_FL_PRESENT) == 0) {
printk(KERN_NOTICE "libusual: "
"modprobe for %s succeeded, but module is not present\n",
bias_names[type]);
}
st->fls &= ~USU_MOD_FL_THREAD;
spin_unlock_irqrestore(&usu_lock, flags);
mutex_unlock(&usu_probe_mutex);
complete_and_exit(&usu_end_notify, 0);
}
static int __init usb_usual_init(void)
{
int rc;
mutex_lock(&usu_probe_mutex);
rc = usb_register(&usu_driver);
mutex_unlock(&usu_probe_mutex);
return rc;
}
static void __exit usb_usual_exit(void)
{
usb_deregister(&usu_driver);
while (atomic_read(&total_threads) > 0) {
wait_for_completion(&usu_end_notify);
atomic_dec(&total_threads);
}
}
static int usu_set_bias(const char *bias_s, struct kernel_param *kp)
{
int i;
int len;
int bias_n = 0;
len = strlen(bias_s);
if (len == 0)
return -EDOM;
if (bias_s[len-1] == '\n')
--len;
for (i = 1; i < 3; i++) {
if (strncmp(bias_s, bias_names[i], len) == 0) {
bias_n = i;
break;
}
}
if (bias_n == 0)
return -EINVAL;
atomic_set(&usu_bias, bias_n);
return 0;
}
static int usu_get_bias(char *buffer, struct kernel_param *kp)
{
return strlen(strcpy(buffer, bias_names[atomic_read(&usu_bias)]));
}
