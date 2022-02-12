static inline struct hvcs_struct *from_vio_dev(struct vio_dev *viod)
{
return dev_get_drvdata(&viod->dev);
}
static ssize_t hvcs_partner_vtys_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct vio_dev *viod = to_vio_dev(dev);
struct hvcs_struct *hvcsd = from_vio_dev(viod);
unsigned long flags;
int retval;
spin_lock_irqsave(&hvcsd->lock, flags);
retval = sprintf(buf, "%X\n", hvcsd->p_unit_address);
spin_unlock_irqrestore(&hvcsd->lock, flags);
return retval;
}
static ssize_t hvcs_partner_clcs_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct vio_dev *viod = to_vio_dev(dev);
struct hvcs_struct *hvcsd = from_vio_dev(viod);
unsigned long flags;
int retval;
spin_lock_irqsave(&hvcsd->lock, flags);
retval = sprintf(buf, "%s\n", &hvcsd->p_location_code[0]);
spin_unlock_irqrestore(&hvcsd->lock, flags);
return retval;
}
static ssize_t hvcs_current_vty_store(struct device *dev, struct device_attribute *attr, const char * buf,
size_t count)
{
printk(KERN_INFO "HVCS: Denied current_vty change: -EPERM.\n");
return -EPERM;
}
static ssize_t hvcs_current_vty_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct vio_dev *viod = to_vio_dev(dev);
struct hvcs_struct *hvcsd = from_vio_dev(viod);
unsigned long flags;
int retval;
spin_lock_irqsave(&hvcsd->lock, flags);
retval = sprintf(buf, "%s\n", &hvcsd->p_location_code[0]);
spin_unlock_irqrestore(&hvcsd->lock, flags);
return retval;
}
static ssize_t hvcs_vterm_state_store(struct device *dev, struct device_attribute *attr, const char *buf,
size_t count)
{
struct vio_dev *viod = to_vio_dev(dev);
struct hvcs_struct *hvcsd = from_vio_dev(viod);
unsigned long flags;
if (simple_strtol(buf, NULL, 0) != 0)
return -EINVAL;
spin_lock_irqsave(&hvcsd->lock, flags);
if (hvcsd->port.count > 0) {
spin_unlock_irqrestore(&hvcsd->lock, flags);
printk(KERN_INFO "HVCS: vterm state unchanged. "
"The hvcs device node is still in use.\n");
return -EPERM;
}
if (hvcsd->connected == 0) {
spin_unlock_irqrestore(&hvcsd->lock, flags);
printk(KERN_INFO "HVCS: vterm state unchanged. The"
" vty-server is not connected to a vty.\n");
return -EPERM;
}
hvcs_partner_free(hvcsd);
printk(KERN_INFO "HVCS: Closed vty-server@%X and"
" partner vty@%X:%d connection.\n",
hvcsd->vdev->unit_address,
hvcsd->p_unit_address,
(uint32_t)hvcsd->p_partition_ID);
spin_unlock_irqrestore(&hvcsd->lock, flags);
return count;
}
static ssize_t hvcs_vterm_state_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct vio_dev *viod = to_vio_dev(dev);
struct hvcs_struct *hvcsd = from_vio_dev(viod);
unsigned long flags;
int retval;
spin_lock_irqsave(&hvcsd->lock, flags);
retval = sprintf(buf, "%d\n", hvcsd->connected);
spin_unlock_irqrestore(&hvcsd->lock, flags);
return retval;
}
static ssize_t hvcs_index_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct vio_dev *viod = to_vio_dev(dev);
struct hvcs_struct *hvcsd = from_vio_dev(viod);
unsigned long flags;
int retval;
spin_lock_irqsave(&hvcsd->lock, flags);
retval = sprintf(buf, "%d\n", hvcsd->index);
spin_unlock_irqrestore(&hvcsd->lock, flags);
return retval;
}
static ssize_t hvcs_rescan_show(struct device_driver *ddp, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%d\n", hvcs_rescan_status);
}
static ssize_t hvcs_rescan_store(struct device_driver *ddp, const char * buf,
size_t count)
{
if ((simple_strtol(buf, NULL, 0) != 1)
&& (hvcs_rescan_status != 0))
return -EINVAL;
hvcs_rescan_status = 1;
printk(KERN_INFO "HVCS: rescanning partner info for all"
" vty-servers.\n");
hvcs_rescan_devices_list();
hvcs_rescan_status = 0;
return count;
}
static void hvcs_kick(void)
{
hvcs_kicked = 1;
wmb();
wake_up_process(hvcs_task);
}
static void hvcs_unthrottle(struct tty_struct *tty)
{
struct hvcs_struct *hvcsd = tty->driver_data;
unsigned long flags;
spin_lock_irqsave(&hvcsd->lock, flags);
hvcsd->todo_mask |= HVCS_SCHED_READ;
spin_unlock_irqrestore(&hvcsd->lock, flags);
hvcs_kick();
}
static void hvcs_throttle(struct tty_struct *tty)
{
struct hvcs_struct *hvcsd = tty->driver_data;
unsigned long flags;
spin_lock_irqsave(&hvcsd->lock, flags);
vio_disable_interrupts(hvcsd->vdev);
spin_unlock_irqrestore(&hvcsd->lock, flags);
}
static irqreturn_t hvcs_handle_interrupt(int irq, void *dev_instance)
{
struct hvcs_struct *hvcsd = dev_instance;
spin_lock(&hvcsd->lock);
vio_disable_interrupts(hvcsd->vdev);
hvcsd->todo_mask |= HVCS_SCHED_READ;
spin_unlock(&hvcsd->lock);
hvcs_kick();
return IRQ_HANDLED;
}
static void hvcs_try_write(struct hvcs_struct *hvcsd)
{
uint32_t unit_address = hvcsd->vdev->unit_address;
struct tty_struct *tty = hvcsd->port.tty;
int sent;
if (hvcsd->todo_mask & HVCS_TRY_WRITE) {
sent = hvc_put_chars(unit_address,
&hvcsd->buffer[0],
hvcsd->chars_in_buffer );
if (sent > 0) {
hvcsd->chars_in_buffer = 0;
hvcsd->todo_mask &= ~(HVCS_TRY_WRITE);
if (tty) {
tty_wakeup(tty);
}
}
}
}
static int hvcs_io(struct hvcs_struct *hvcsd)
{
uint32_t unit_address;
struct tty_struct *tty;
char buf[HVCS_BUFF_LEN] __ALIGNED__;
unsigned long flags;
int got = 0;
spin_lock_irqsave(&hvcsd->lock, flags);
unit_address = hvcsd->vdev->unit_address;
tty = hvcsd->port.tty;
hvcs_try_write(hvcsd);
if (!tty || test_bit(TTY_THROTTLED, &tty->flags)) {
hvcsd->todo_mask &= ~(HVCS_READ_MASK);
goto bail;
} else if (!(hvcsd->todo_mask & (HVCS_READ_MASK)))
goto bail;
hvcsd->todo_mask &= ~(HVCS_READ_MASK);
if (tty_buffer_request_room(&hvcsd->port, HVCS_BUFF_LEN) >= HVCS_BUFF_LEN) {
got = hvc_get_chars(unit_address,
&buf[0],
HVCS_BUFF_LEN);
tty_insert_flip_string(&hvcsd->port, buf, got);
}
if (got)
hvcsd->todo_mask |= HVCS_QUICK_READ;
spin_unlock_irqrestore(&hvcsd->lock, flags);
if(got)
tty_flip_buffer_push(&hvcsd->port);
if (!got) {
spin_lock_irqsave(&hvcsd->lock, flags);
vio_enable_interrupts(hvcsd->vdev);
spin_unlock_irqrestore(&hvcsd->lock, flags);
}
return hvcsd->todo_mask;
bail:
spin_unlock_irqrestore(&hvcsd->lock, flags);
return hvcsd->todo_mask;
}
static int khvcsd(void *unused)
{
struct hvcs_struct *hvcsd;
int hvcs_todo_mask;
__set_current_state(TASK_RUNNING);
do {
hvcs_todo_mask = 0;
hvcs_kicked = 0;
wmb();
spin_lock(&hvcs_structs_lock);
list_for_each_entry(hvcsd, &hvcs_structs, next) {
hvcs_todo_mask |= hvcs_io(hvcsd);
}
spin_unlock(&hvcs_structs_lock);
if (hvcs_todo_mask & (HVCS_TRY_WRITE | HVCS_QUICK_READ)) {
yield();
continue;
}
set_current_state(TASK_INTERRUPTIBLE);
if (!hvcs_kicked)
schedule();
__set_current_state(TASK_RUNNING);
} while (!kthread_should_stop());
return 0;
}
static void hvcs_return_index(int index)
{
if (!hvcs_index_list)
return;
if (index < 0 || index >= hvcs_index_count)
return;
if (hvcs_index_list[index] == -1)
return;
else
hvcs_index_list[index] = -1;
}
static void hvcs_destruct_port(struct tty_port *p)
{
struct hvcs_struct *hvcsd = container_of(p, struct hvcs_struct, port);
struct vio_dev *vdev;
unsigned long flags;
spin_lock(&hvcs_structs_lock);
spin_lock_irqsave(&hvcsd->lock, flags);
list_del(&(hvcsd->next));
if (hvcsd->connected == 1) {
hvcs_partner_free(hvcsd);
printk(KERN_INFO "HVCS: Closed vty-server@%X and"
" partner vty@%X:%d connection.\n",
hvcsd->vdev->unit_address,
hvcsd->p_unit_address,
(uint32_t)hvcsd->p_partition_ID);
}
printk(KERN_INFO "HVCS: Destroyed hvcs_struct for vty-server@%X.\n",
hvcsd->vdev->unit_address);
vdev = hvcsd->vdev;
hvcsd->vdev = NULL;
hvcsd->p_unit_address = 0;
hvcsd->p_partition_ID = 0;
hvcs_return_index(hvcsd->index);
memset(&hvcsd->p_location_code[0], 0x00, HVCS_CLC_LENGTH + 1);
spin_unlock_irqrestore(&hvcsd->lock, flags);
spin_unlock(&hvcs_structs_lock);
sysfs_remove_group(&vdev->dev.kobj, &hvcs_attr_group);
kfree(hvcsd);
}
static int hvcs_get_index(void)
{
int i;
if (!hvcs_index_list) {
printk(KERN_ERR "HVCS: hvcs_index_list NOT valid!.\n");
return -EFAULT;
}
for(i = 0; i < hvcs_index_count; i++) {
if (hvcs_index_list[i] == -1) {
hvcs_index_list[i] = 0;
return i;
}
}
return -1;
}
static int hvcs_probe(
struct vio_dev *dev,
const struct vio_device_id *id)
{
struct hvcs_struct *hvcsd;
int index, rc;
int retval;
if (!dev || !id) {
printk(KERN_ERR "HVCS: probed with invalid parameter.\n");
return -EPERM;
}
rc = hvcs_initialize();
if (rc) {
pr_err("HVCS: Failed to initialize core driver.\n");
return rc;
}
index = hvcs_get_index();
if (index < 0) {
return -EFAULT;
}
hvcsd = kzalloc(sizeof(*hvcsd), GFP_KERNEL);
if (!hvcsd)
return -ENODEV;
tty_port_init(&hvcsd->port);
hvcsd->port.ops = &hvcs_port_ops;
spin_lock_init(&hvcsd->lock);
hvcsd->vdev = dev;
dev_set_drvdata(&dev->dev, hvcsd);
hvcsd->index = index;
hvcsd->chars_in_buffer = 0;
hvcsd->todo_mask = 0;
hvcsd->connected = 0;
if (hvcs_get_pi(hvcsd)) {
printk(KERN_ERR "HVCS: Failed to fetch partner"
" info for vty-server@%X on device probe.\n",
hvcsd->vdev->unit_address);
}
spin_lock(&hvcs_structs_lock);
list_add_tail(&(hvcsd->next), &hvcs_structs);
spin_unlock(&hvcs_structs_lock);
retval = sysfs_create_group(&dev->dev.kobj, &hvcs_attr_group);
if (retval) {
printk(KERN_ERR "HVCS: Can't create sysfs attrs for vty-server@%X\n",
hvcsd->vdev->unit_address);
return retval;
}
printk(KERN_INFO "HVCS: vty-server@%X added to the vio bus.\n", dev->unit_address);
return 0;
}
static int hvcs_remove(struct vio_dev *dev)
{
struct hvcs_struct *hvcsd = dev_get_drvdata(&dev->dev);
unsigned long flags;
struct tty_struct *tty;
if (!hvcsd)
return -ENODEV;
spin_lock_irqsave(&hvcsd->lock, flags);
tty = hvcsd->port.tty;
spin_unlock_irqrestore(&hvcsd->lock, flags);
tty_port_put(&hvcsd->port);
if (tty)
tty_hangup(tty);
printk(KERN_INFO "HVCS: vty-server@%X removed from the"
" vio bus.\n", dev->unit_address);
return 0;
}
static void hvcs_set_pi(struct hvcs_partner_info *pi, struct hvcs_struct *hvcsd)
{
hvcsd->p_unit_address = pi->unit_address;
hvcsd->p_partition_ID = pi->partition_ID;
strlcpy(&hvcsd->p_location_code[0],
&pi->location_code[0], sizeof(hvcsd->p_location_code));
}
static int hvcs_get_pi(struct hvcs_struct *hvcsd)
{
struct hvcs_partner_info *pi;
uint32_t unit_address = hvcsd->vdev->unit_address;
struct list_head head;
int retval;
spin_lock(&hvcs_pi_lock);
if (!hvcs_pi_buff) {
spin_unlock(&hvcs_pi_lock);
return -EFAULT;
}
retval = hvcs_get_partner_info(unit_address, &head, hvcs_pi_buff);
spin_unlock(&hvcs_pi_lock);
if (retval) {
printk(KERN_ERR "HVCS: Failed to fetch partner"
" info for vty-server@%x.\n", unit_address);
return retval;
}
hvcsd->p_unit_address = 0;
hvcsd->p_partition_ID = 0;
list_for_each_entry(pi, &head, node)
hvcs_set_pi(pi, hvcsd);
hvcs_free_partner_info(&head);
return 0;
}
static int hvcs_rescan_devices_list(void)
{
struct hvcs_struct *hvcsd;
unsigned long flags;
spin_lock(&hvcs_structs_lock);
list_for_each_entry(hvcsd, &hvcs_structs, next) {
spin_lock_irqsave(&hvcsd->lock, flags);
hvcs_get_pi(hvcsd);
spin_unlock_irqrestore(&hvcsd->lock, flags);
}
spin_unlock(&hvcs_structs_lock);
return 0;
}
static int hvcs_has_pi(struct hvcs_struct *hvcsd)
{
if ((!hvcsd->p_unit_address) || (!hvcsd->p_partition_ID))
return 0;
return 1;
}
static int hvcs_partner_connect(struct hvcs_struct *hvcsd)
{
int retval;
unsigned int unit_address = hvcsd->vdev->unit_address;
retval = hvcs_register_connection(unit_address,
hvcsd->p_partition_ID,
hvcsd->p_unit_address);
if (!retval) {
hvcsd->connected = 1;
return 0;
} else if (retval != -EINVAL)
return retval;
if (hvcs_get_pi(hvcsd))
return -ENOMEM;
if (!hvcs_has_pi(hvcsd))
return -ENODEV;
retval = hvcs_register_connection(unit_address,
hvcsd->p_partition_ID,
hvcsd->p_unit_address);
if (retval != -EINVAL) {
hvcsd->connected = 1;
return retval;
}
printk(KERN_INFO "HVCS: vty-server or partner"
" vty is busy. Try again later.\n");
return -EBUSY;
}
static void hvcs_partner_free(struct hvcs_struct *hvcsd)
{
int retval;
do {
retval = hvcs_free_connection(hvcsd->vdev->unit_address);
} while (retval == -EBUSY);
hvcsd->connected = 0;
}
static int hvcs_enable_device(struct hvcs_struct *hvcsd, uint32_t unit_address,
unsigned int irq, struct vio_dev *vdev)
{
unsigned long flags;
int rc;
rc = request_irq(irq, &hvcs_handle_interrupt, 0, "ibmhvcs", hvcsd);
if (!rc) {
if (vio_enable_interrupts(vdev) == H_SUCCESS)
return 0;
else {
printk(KERN_ERR "HVCS: int enable failed for"
" vty-server@%X.\n", unit_address);
free_irq(irq, hvcsd);
}
} else
printk(KERN_ERR "HVCS: irq req failed for"
" vty-server@%X.\n", unit_address);
spin_lock_irqsave(&hvcsd->lock, flags);
hvcs_partner_free(hvcsd);
spin_unlock_irqrestore(&hvcsd->lock, flags);
return rc;
}
static struct hvcs_struct *hvcs_get_by_index(int index)
{
struct hvcs_struct *hvcsd;
unsigned long flags;
spin_lock(&hvcs_structs_lock);
list_for_each_entry(hvcsd, &hvcs_structs, next) {
spin_lock_irqsave(&hvcsd->lock, flags);
if (hvcsd->index == index) {
tty_port_get(&hvcsd->port);
spin_unlock_irqrestore(&hvcsd->lock, flags);
spin_unlock(&hvcs_structs_lock);
return hvcsd;
}
spin_unlock_irqrestore(&hvcsd->lock, flags);
}
spin_unlock(&hvcs_structs_lock);
return NULL;
}
static int hvcs_install(struct tty_driver *driver, struct tty_struct *tty)
{
struct hvcs_struct *hvcsd;
struct vio_dev *vdev;
unsigned long unit_address, flags;
unsigned int irq;
int retval;
hvcsd = hvcs_get_by_index(tty->index);
if (!hvcsd) {
printk(KERN_WARNING "HVCS: open failed, no device associated"
" with tty->index %d.\n", tty->index);
return -ENODEV;
}
spin_lock_irqsave(&hvcsd->lock, flags);
if (hvcsd->connected == 0) {
retval = hvcs_partner_connect(hvcsd);
if (retval) {
spin_unlock_irqrestore(&hvcsd->lock, flags);
printk(KERN_WARNING "HVCS: partner connect failed.\n");
goto err_put;
}
}
hvcsd->port.count = 0;
hvcsd->port.tty = tty;
tty->driver_data = hvcsd;
memset(&hvcsd->buffer[0], 0x00, HVCS_BUFF_LEN);
irq = hvcsd->vdev->irq;
vdev = hvcsd->vdev;
unit_address = hvcsd->vdev->unit_address;
hvcsd->todo_mask |= HVCS_SCHED_READ;
spin_unlock_irqrestore(&hvcsd->lock, flags);
retval = hvcs_enable_device(hvcsd, unit_address, irq, vdev);
if (retval) {
printk(KERN_WARNING "HVCS: enable device failed.\n");
goto err_put;
}
retval = tty_port_install(&hvcsd->port, driver, tty);
if (retval)
goto err_irq;
return 0;
err_irq:
spin_lock_irqsave(&hvcsd->lock, flags);
vio_disable_interrupts(hvcsd->vdev);
spin_unlock_irqrestore(&hvcsd->lock, flags);
free_irq(irq, hvcsd);
err_put:
tty_port_put(&hvcsd->port);
return retval;
}
static int hvcs_open(struct tty_struct *tty, struct file *filp)
{
struct hvcs_struct *hvcsd = tty->driver_data;
unsigned long flags;
spin_lock_irqsave(&hvcsd->lock, flags);
hvcsd->port.count++;
hvcsd->todo_mask |= HVCS_SCHED_READ;
spin_unlock_irqrestore(&hvcsd->lock, flags);
hvcs_kick();
printk(KERN_INFO "HVCS: vty-server@%X connection opened.\n",
hvcsd->vdev->unit_address );
return 0;
}
static void hvcs_close(struct tty_struct *tty, struct file *filp)
{
struct hvcs_struct *hvcsd;
unsigned long flags;
int irq;
if (tty_hung_up_p(filp))
return;
if (!tty->driver_data)
return;
hvcsd = tty->driver_data;
spin_lock_irqsave(&hvcsd->lock, flags);
if (--hvcsd->port.count == 0) {
vio_disable_interrupts(hvcsd->vdev);
hvcsd->port.tty = NULL;
irq = hvcsd->vdev->irq;
spin_unlock_irqrestore(&hvcsd->lock, flags);
tty_wait_until_sent_from_close(tty, HVCS_CLOSE_WAIT);
tty->driver_data = NULL;
free_irq(irq, hvcsd);
return;
} else if (hvcsd->port.count < 0) {
printk(KERN_ERR "HVCS: vty-server@%X open_count: %d"
" is missmanaged.\n",
hvcsd->vdev->unit_address, hvcsd->port.count);
}
spin_unlock_irqrestore(&hvcsd->lock, flags);
}
static void hvcs_cleanup(struct tty_struct * tty)
{
struct hvcs_struct *hvcsd = tty->driver_data;
tty_port_put(&hvcsd->port);
}
static void hvcs_hangup(struct tty_struct * tty)
{
struct hvcs_struct *hvcsd = tty->driver_data;
unsigned long flags;
int temp_open_count;
int irq;
spin_lock_irqsave(&hvcsd->lock, flags);
temp_open_count = hvcsd->port.count;
vio_disable_interrupts(hvcsd->vdev);
hvcsd->todo_mask = 0;
tty->driver_data = NULL;
hvcsd->port.tty = NULL;
hvcsd->port.count = 0;
memset(&hvcsd->buffer[0], 0x00, HVCS_BUFF_LEN);
hvcsd->chars_in_buffer = 0;
irq = hvcsd->vdev->irq;
spin_unlock_irqrestore(&hvcsd->lock, flags);
free_irq(irq, hvcsd);
while(temp_open_count) {
--temp_open_count;
tty_port_put(&hvcsd->port);
}
}
static int hvcs_write(struct tty_struct *tty,
const unsigned char *buf, int count)
{
struct hvcs_struct *hvcsd = tty->driver_data;
unsigned int unit_address;
const unsigned char *charbuf;
unsigned long flags;
int total_sent = 0;
int tosend = 0;
int result = 0;
if (!hvcsd)
return -ENODEV;
if (count > HVCS_MAX_FROM_USER) {
printk(KERN_WARNING "HVCS write: count being truncated to"
" HVCS_MAX_FROM_USER.\n");
count = HVCS_MAX_FROM_USER;
}
charbuf = buf;
spin_lock_irqsave(&hvcsd->lock, flags);
if (hvcsd->port.count <= 0) {
spin_unlock_irqrestore(&hvcsd->lock, flags);
return -ENODEV;
}
unit_address = hvcsd->vdev->unit_address;
while (count > 0) {
tosend = min(count, (HVCS_BUFF_LEN - hvcsd->chars_in_buffer));
if (!tosend)
break;
memcpy(&hvcsd->buffer[hvcsd->chars_in_buffer],
&charbuf[total_sent],
tosend);
hvcsd->chars_in_buffer += tosend;
result = 0;
if (!(hvcsd->todo_mask & HVCS_TRY_WRITE))
result = hvc_put_chars(unit_address,
&hvcsd->buffer[0],
hvcsd->chars_in_buffer);
total_sent+=tosend;
count-=tosend;
if (result == 0) {
hvcsd->todo_mask |= HVCS_TRY_WRITE;
hvcs_kick();
break;
}
hvcsd->chars_in_buffer = 0;
if (result < 0)
break;
}
spin_unlock_irqrestore(&hvcsd->lock, flags);
if (result == -1)
return -EIO;
else
return total_sent;
}
static int hvcs_write_room(struct tty_struct *tty)
{
struct hvcs_struct *hvcsd = tty->driver_data;
if (!hvcsd || hvcsd->port.count <= 0)
return 0;
return HVCS_BUFF_LEN - hvcsd->chars_in_buffer;
}
static int hvcs_chars_in_buffer(struct tty_struct *tty)
{
struct hvcs_struct *hvcsd = tty->driver_data;
return hvcsd->chars_in_buffer;
}
static int hvcs_alloc_index_list(int n)
{
int i;
hvcs_index_list = kmalloc(n * sizeof(hvcs_index_count),GFP_KERNEL);
if (!hvcs_index_list)
return -ENOMEM;
hvcs_index_count = n;
for (i = 0; i < hvcs_index_count; i++)
hvcs_index_list[i] = -1;
return 0;
}
static void hvcs_free_index_list(void)
{
kfree(hvcs_index_list);
hvcs_index_list = NULL;
hvcs_index_count = 0;
}
static int hvcs_initialize(void)
{
int rc, num_ttys_to_alloc;
mutex_lock(&hvcs_init_mutex);
if (hvcs_task) {
mutex_unlock(&hvcs_init_mutex);
return 0;
}
if (hvcs_parm_num_devs <= 0 ||
(hvcs_parm_num_devs > HVCS_MAX_SERVER_ADAPTERS)) {
num_ttys_to_alloc = HVCS_DEFAULT_SERVER_ADAPTERS;
} else
num_ttys_to_alloc = hvcs_parm_num_devs;
hvcs_tty_driver = alloc_tty_driver(num_ttys_to_alloc);
if (!hvcs_tty_driver) {
mutex_unlock(&hvcs_init_mutex);
return -ENOMEM;
}
if (hvcs_alloc_index_list(num_ttys_to_alloc)) {
rc = -ENOMEM;
goto index_fail;
}
hvcs_tty_driver->driver_name = hvcs_driver_name;
hvcs_tty_driver->name = hvcs_device_node;
hvcs_tty_driver->minor_start = HVCS_MINOR_START;
hvcs_tty_driver->type = TTY_DRIVER_TYPE_SYSTEM;
hvcs_tty_driver->init_termios = hvcs_tty_termios;
hvcs_tty_driver->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(hvcs_tty_driver, &hvcs_ops);
if (tty_register_driver(hvcs_tty_driver)) {
printk(KERN_ERR "HVCS: registration as a tty driver failed.\n");
rc = -EIO;
goto register_fail;
}
hvcs_pi_buff = (unsigned long *) __get_free_page(GFP_KERNEL);
if (!hvcs_pi_buff) {
rc = -ENOMEM;
goto buff_alloc_fail;
}
hvcs_task = kthread_run(khvcsd, NULL, "khvcsd");
if (IS_ERR(hvcs_task)) {
printk(KERN_ERR "HVCS: khvcsd creation failed.\n");
rc = -EIO;
goto kthread_fail;
}
mutex_unlock(&hvcs_init_mutex);
return 0;
kthread_fail:
free_page((unsigned long)hvcs_pi_buff);
buff_alloc_fail:
tty_unregister_driver(hvcs_tty_driver);
register_fail:
hvcs_free_index_list();
index_fail:
put_tty_driver(hvcs_tty_driver);
hvcs_tty_driver = NULL;
mutex_unlock(&hvcs_init_mutex);
return rc;
}
static int __init hvcs_module_init(void)
{
int rc = vio_register_driver(&hvcs_vio_driver);
if (rc) {
printk(KERN_ERR "HVCS: can't register vio driver\n");
return rc;
}
pr_info("HVCS: Driver registered.\n");
rc = driver_create_file(&(hvcs_vio_driver.driver), &driver_attr_rescan);
if (rc)
pr_warning("HVCS: Failed to create rescan file (err %d)\n", rc);
return 0;
}
static void __exit hvcs_module_exit(void)
{
vio_unregister_driver(&hvcs_vio_driver);
if (!hvcs_task)
return;
kthread_stop(hvcs_task);
spin_lock(&hvcs_pi_lock);
free_page((unsigned long)hvcs_pi_buff);
hvcs_pi_buff = NULL;
spin_unlock(&hvcs_pi_lock);
driver_remove_file(&hvcs_vio_driver.driver, &driver_attr_rescan);
tty_unregister_driver(hvcs_tty_driver);
hvcs_free_index_list();
put_tty_driver(hvcs_tty_driver);
printk(KERN_INFO "HVCS: driver module removed.\n");
}
