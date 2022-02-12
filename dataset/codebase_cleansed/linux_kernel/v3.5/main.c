static bool mei_clear_list(struct mei_device *dev,
struct file *file, struct list_head *mei_cb_list)
{
struct mei_cl_cb *cb_pos = NULL;
struct mei_cl_cb *cb_next = NULL;
struct file *file_temp;
bool removed = false;
list_for_each_entry_safe(cb_pos, cb_next, mei_cb_list, cb_list) {
file_temp = (struct file *)cb_pos->file_object;
if (file_temp == file) {
list_del(&cb_pos->cb_list);
if (dev->iamthif_current_cb == cb_pos) {
dev->iamthif_current_cb = NULL;
mei_send_flow_control(dev, &dev->iamthif_cl);
}
mei_free_cb_private(cb_pos);
cb_pos = NULL;
removed = true;
}
}
return removed;
}
static bool mei_clear_lists(struct mei_device *dev, struct file *file)
{
bool removed = false;
mei_clear_list(dev, file, &dev->amthi_cmd_list.mei_cb.cb_list);
if (mei_clear_list(dev, file,
&dev->amthi_read_complete_list.mei_cb.cb_list))
removed = true;
mei_clear_list(dev, file, &dev->ctrl_rd_list.mei_cb.cb_list);
if (mei_clear_list(dev, file, &dev->ctrl_wr_list.mei_cb.cb_list))
removed = true;
if (mei_clear_list(dev, file, &dev->write_waiting_list.mei_cb.cb_list))
removed = true;
if (mei_clear_list(dev, file, &dev->write_list.mei_cb.cb_list))
removed = true;
if (dev->iamthif_current_cb && !removed) {
if (dev->iamthif_current_cb->file_object == file) {
mei_free_cb_private(dev->iamthif_current_cb);
dev->iamthif_current_cb = NULL;
removed = true;
}
}
return removed;
}
static struct mei_cl_cb *find_read_list_entry(
struct mei_device *dev,
struct mei_cl *cl)
{
struct mei_cl_cb *pos = NULL;
struct mei_cl_cb *next = NULL;
dev_dbg(&dev->pdev->dev, "remove read_list CB\n");
list_for_each_entry_safe(pos, next,
&dev->read_list.mei_cb.cb_list, cb_list) {
struct mei_cl *cl_temp;
cl_temp = (struct mei_cl *)pos->file_private;
if (mei_cl_cmp_id(cl, cl_temp))
return pos;
}
return NULL;
}
static int mei_open(struct inode *inode, struct file *file)
{
struct mei_cl *cl;
struct mei_device *dev;
unsigned long cl_id;
int err;
err = -ENODEV;
if (!mei_device)
goto out;
dev = pci_get_drvdata(mei_device);
if (!dev)
goto out;
mutex_lock(&dev->device_lock);
err = -ENOMEM;
cl = mei_cl_allocate(dev);
if (!cl)
goto out_unlock;
err = -ENODEV;
if (dev->mei_state != MEI_ENABLED) {
dev_dbg(&dev->pdev->dev, "mei_state != MEI_ENABLED mei_state= %d\n",
dev->mei_state);
goto out_unlock;
}
err = -EMFILE;
if (dev->open_handle_count >= MEI_MAX_OPEN_HANDLE_COUNT)
goto out_unlock;
cl_id = find_first_zero_bit(dev->host_clients_map, MEI_CLIENTS_MAX);
if (cl_id >= MEI_CLIENTS_MAX)
goto out_unlock;
cl->host_client_id = cl_id;
dev_dbg(&dev->pdev->dev, "client_id = %d\n", cl->host_client_id);
dev->open_handle_count++;
list_add_tail(&cl->link, &dev->file_list);
set_bit(cl->host_client_id, dev->host_clients_map);
cl->state = MEI_FILE_INITIALIZING;
cl->sm_state = 0;
file->private_data = cl;
mutex_unlock(&dev->device_lock);
return nonseekable_open(inode, file);
out_unlock:
mutex_unlock(&dev->device_lock);
kfree(cl);
out:
return err;
}
static int mei_release(struct inode *inode, struct file *file)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *cb;
struct mei_device *dev;
int rets = 0;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (cl != &dev->iamthif_cl) {
if (cl->state == MEI_FILE_CONNECTED) {
cl->state = MEI_FILE_DISCONNECTING;
dev_dbg(&dev->pdev->dev,
"disconnecting client host client = %d, "
"ME client = %d\n",
cl->host_client_id,
cl->me_client_id);
rets = mei_disconnect_host_client(dev, cl);
}
mei_cl_flush_queues(cl);
dev_dbg(&dev->pdev->dev, "remove client host client = %d, ME client = %d\n",
cl->host_client_id,
cl->me_client_id);
if (dev->open_handle_count > 0) {
clear_bit(cl->host_client_id, dev->host_clients_map);
dev->open_handle_count--;
}
mei_remove_client_from_file_list(dev, cl->host_client_id);
cb = NULL;
if (cl->read_cb) {
cb = find_read_list_entry(dev, cl);
if (cb)
list_del(&cb->cb_list);
cb = cl->read_cb;
cl->read_cb = NULL;
}
file->private_data = NULL;
if (cb) {
mei_free_cb_private(cb);
cb = NULL;
}
kfree(cl);
} else {
if (dev->open_handle_count > 0)
dev->open_handle_count--;
if (dev->iamthif_file_object == file &&
dev->iamthif_state != MEI_IAMTHIF_IDLE) {
dev_dbg(&dev->pdev->dev, "amthi canceled iamthif state %d\n",
dev->iamthif_state);
dev->iamthif_canceled = true;
if (dev->iamthif_state == MEI_IAMTHIF_READ_COMPLETE) {
dev_dbg(&dev->pdev->dev, "run next amthi iamthif cb\n");
mei_run_next_iamthif_cmd(dev);
}
}
if (mei_clear_lists(dev, file))
dev->iamthif_state = MEI_IAMTHIF_IDLE;
}
mutex_unlock(&dev->device_lock);
return rets;
}
static ssize_t mei_read(struct file *file, char __user *ubuf,
size_t length, loff_t *offset)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *cb_pos = NULL;
struct mei_cl_cb *cb = NULL;
struct mei_device *dev;
int i;
int rets;
int err;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (dev->mei_state != MEI_ENABLED) {
rets = -ENODEV;
goto out;
}
if ((cl->sm_state & MEI_WD_STATE_INDEPENDENCE_MSG_SENT) == 0) {
i = mei_find_me_client_index(dev, mei_wd_guid);
if (i >= 0) {
struct mei_me_client *me_client = &dev->me_clients[i];
if (cl->me_client_id == me_client->client_id) {
rets = -EBADF;
goto out;
}
}
} else {
cl->sm_state &= ~MEI_WD_STATE_INDEPENDENCE_MSG_SENT;
}
if (cl == &dev->iamthif_cl) {
rets = amthi_read(dev, file, ubuf, length, offset);
goto out;
}
if (cl->read_cb && cl->read_cb->information > *offset) {
cb = cl->read_cb;
goto copy_buffer;
} else if (cl->read_cb && cl->read_cb->information > 0 &&
cl->read_cb->information <= *offset) {
cb = cl->read_cb;
rets = 0;
goto free;
} else if ((!cl->read_cb || !cl->read_cb->information) &&
*offset > 0) {
*offset = 0;
rets = 0;
goto out;
}
err = mei_start_read(dev, cl);
if (err && err != -EBUSY) {
dev_dbg(&dev->pdev->dev,
"mei start read failure with status = %d\n", err);
rets = err;
goto out;
}
if (MEI_READ_COMPLETE != cl->reading_state &&
!waitqueue_active(&cl->rx_wait)) {
if (file->f_flags & O_NONBLOCK) {
rets = -EAGAIN;
goto out;
}
mutex_unlock(&dev->device_lock);
if (wait_event_interruptible(cl->rx_wait,
(MEI_READ_COMPLETE == cl->reading_state ||
MEI_FILE_INITIALIZING == cl->state ||
MEI_FILE_DISCONNECTED == cl->state ||
MEI_FILE_DISCONNECTING == cl->state))) {
if (signal_pending(current))
return -EINTR;
return -ERESTARTSYS;
}
mutex_lock(&dev->device_lock);
if (MEI_FILE_INITIALIZING == cl->state ||
MEI_FILE_DISCONNECTED == cl->state ||
MEI_FILE_DISCONNECTING == cl->state) {
rets = -EBUSY;
goto out;
}
}
cb = cl->read_cb;
if (!cb) {
rets = -ENODEV;
goto out;
}
if (cl->reading_state != MEI_READ_COMPLETE) {
rets = 0;
goto out;
}
copy_buffer:
dev_dbg(&dev->pdev->dev, "cb->response_buffer size - %d\n",
cb->response_buffer.size);
dev_dbg(&dev->pdev->dev, "cb->information - %lu\n",
cb->information);
if (length == 0 || ubuf == NULL || *offset > cb->information) {
rets = -EMSGSIZE;
goto free;
}
length = min_t(size_t, length, (cb->information - *offset));
if (copy_to_user(ubuf, cb->response_buffer.data + *offset, length)) {
rets = -EFAULT;
goto free;
}
rets = length;
*offset += length;
if ((unsigned long)*offset < cb->information)
goto out;
free:
cb_pos = find_read_list_entry(dev, cl);
if (cb_pos)
list_del(&cb_pos->cb_list);
mei_free_cb_private(cb);
cl->reading_state = MEI_IDLE;
cl->read_cb = NULL;
cl->read_pending = 0;
out:
dev_dbg(&dev->pdev->dev, "end mei read rets= %d\n", rets);
mutex_unlock(&dev->device_lock);
return rets;
}
static ssize_t mei_write(struct file *file, const char __user *ubuf,
size_t length, loff_t *offset)
{
struct mei_cl *cl = file->private_data;
struct mei_cl_cb *write_cb = NULL;
struct mei_msg_hdr mei_hdr;
struct mei_device *dev;
unsigned long timeout = 0;
int rets;
int i;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (dev->mei_state != MEI_ENABLED) {
mutex_unlock(&dev->device_lock);
return -ENODEV;
}
if (cl == &dev->iamthif_cl) {
write_cb = find_amthi_read_list_entry(dev, file);
if (write_cb) {
timeout = write_cb->read_time +
msecs_to_jiffies(IAMTHIF_READ_TIMER);
if (time_after(jiffies, timeout) ||
cl->reading_state == MEI_READ_COMPLETE) {
*offset = 0;
list_del(&write_cb->cb_list);
mei_free_cb_private(write_cb);
write_cb = NULL;
}
}
}
if (cl->reading_state == MEI_READ_COMPLETE) {
*offset = 0;
write_cb = find_read_list_entry(dev, cl);
if (write_cb) {
list_del(&write_cb->cb_list);
mei_free_cb_private(write_cb);
write_cb = NULL;
cl->reading_state = MEI_IDLE;
cl->read_cb = NULL;
cl->read_pending = 0;
}
} else if (cl->reading_state == MEI_IDLE && !cl->read_pending)
*offset = 0;
write_cb = kzalloc(sizeof(struct mei_cl_cb), GFP_KERNEL);
if (!write_cb) {
mutex_unlock(&dev->device_lock);
return -ENOMEM;
}
write_cb->file_object = file;
write_cb->file_private = cl;
write_cb->request_buffer.data = kmalloc(length, GFP_KERNEL);
rets = -ENOMEM;
if (!write_cb->request_buffer.data)
goto unlock_dev;
dev_dbg(&dev->pdev->dev, "length =%d\n", (int) length);
rets = -EFAULT;
if (copy_from_user(write_cb->request_buffer.data, ubuf, length))
goto unlock_dev;
cl->sm_state = 0;
if (length == 4 &&
((memcmp(mei_wd_state_independence_msg[0],
write_cb->request_buffer.data, 4) == 0) ||
(memcmp(mei_wd_state_independence_msg[1],
write_cb->request_buffer.data, 4) == 0) ||
(memcmp(mei_wd_state_independence_msg[2],
write_cb->request_buffer.data, 4) == 0)))
cl->sm_state |= MEI_WD_STATE_INDEPENDENCE_MSG_SENT;
INIT_LIST_HEAD(&write_cb->cb_list);
if (cl == &dev->iamthif_cl) {
write_cb->response_buffer.data =
kmalloc(dev->iamthif_mtu, GFP_KERNEL);
if (!write_cb->response_buffer.data) {
rets = -ENOMEM;
goto unlock_dev;
}
if (dev->mei_state != MEI_ENABLED) {
rets = -ENODEV;
goto unlock_dev;
}
for (i = 0; i < dev->me_clients_num; i++) {
if (dev->me_clients[i].client_id ==
dev->iamthif_cl.me_client_id)
break;
}
if (WARN_ON(dev->me_clients[i].client_id != cl->me_client_id)) {
rets = -ENODEV;
goto unlock_dev;
}
if (i == dev->me_clients_num ||
(dev->me_clients[i].client_id !=
dev->iamthif_cl.me_client_id)) {
rets = -ENODEV;
goto unlock_dev;
} else if (length > dev->me_clients[i].props.max_msg_length ||
length <= 0) {
rets = -EMSGSIZE;
goto unlock_dev;
}
write_cb->response_buffer.size = dev->iamthif_mtu;
write_cb->major_file_operations = MEI_IOCTL;
write_cb->information = 0;
write_cb->request_buffer.size = length;
if (dev->iamthif_cl.state != MEI_FILE_CONNECTED) {
rets = -ENODEV;
goto unlock_dev;
}
if (!list_empty(&dev->amthi_cmd_list.mei_cb.cb_list) ||
dev->iamthif_state != MEI_IAMTHIF_IDLE) {
dev_dbg(&dev->pdev->dev, "amthi_state = %d\n",
(int) dev->iamthif_state);
dev_dbg(&dev->pdev->dev, "add amthi cb to amthi cmd waiting list\n");
list_add_tail(&write_cb->cb_list,
&dev->amthi_cmd_list.mei_cb.cb_list);
rets = length;
} else {
dev_dbg(&dev->pdev->dev, "call amthi write\n");
rets = amthi_write(dev, write_cb);
if (rets) {
dev_dbg(&dev->pdev->dev, "amthi write failed with status = %d\n",
rets);
goto unlock_dev;
}
rets = length;
}
mutex_unlock(&dev->device_lock);
return rets;
}
write_cb->major_file_operations = MEI_WRITE;
write_cb->information = 0;
write_cb->request_buffer.size = length;
dev_dbg(&dev->pdev->dev, "host client = %d, ME client = %d\n",
cl->host_client_id, cl->me_client_id);
if (cl->state != MEI_FILE_CONNECTED) {
rets = -ENODEV;
dev_dbg(&dev->pdev->dev, "host client = %d, is not connected to ME client = %d",
cl->host_client_id,
cl->me_client_id);
goto unlock_dev;
}
for (i = 0; i < dev->me_clients_num; i++) {
if (dev->me_clients[i].client_id ==
cl->me_client_id)
break;
}
if (WARN_ON(dev->me_clients[i].client_id != cl->me_client_id)) {
rets = -ENODEV;
goto unlock_dev;
}
if (i == dev->me_clients_num) {
rets = -ENODEV;
goto unlock_dev;
}
if (length > dev->me_clients[i].props.max_msg_length || length <= 0) {
rets = -EINVAL;
goto unlock_dev;
}
write_cb->file_private = cl;
rets = mei_flow_ctrl_creds(dev, cl);
if (rets < 0)
goto unlock_dev;
if (rets && dev->mei_host_buffer_is_empty) {
rets = 0;
dev->mei_host_buffer_is_empty = false;
if (length > ((((dev->host_hw_state & H_CBD) >> 24) *
sizeof(u32)) - sizeof(struct mei_msg_hdr))) {
mei_hdr.length =
(((dev->host_hw_state & H_CBD) >> 24) *
sizeof(u32)) -
sizeof(struct mei_msg_hdr);
mei_hdr.msg_complete = 0;
} else {
mei_hdr.length = length;
mei_hdr.msg_complete = 1;
}
mei_hdr.host_addr = cl->host_client_id;
mei_hdr.me_addr = cl->me_client_id;
mei_hdr.reserved = 0;
dev_dbg(&dev->pdev->dev, "call mei_write_message header=%08x.\n",
*((u32 *) &mei_hdr));
if (mei_write_message(dev, &mei_hdr,
(unsigned char *) (write_cb->request_buffer.data),
mei_hdr.length)) {
rets = -ENODEV;
goto unlock_dev;
}
cl->writing_state = MEI_WRITING;
write_cb->information = mei_hdr.length;
if (mei_hdr.msg_complete) {
if (mei_flow_ctrl_reduce(dev, cl)) {
rets = -ENODEV;
goto unlock_dev;
}
list_add_tail(&write_cb->cb_list,
&dev->write_waiting_list.mei_cb.cb_list);
} else {
list_add_tail(&write_cb->cb_list,
&dev->write_list.mei_cb.cb_list);
}
} else {
write_cb->information = 0;
cl->writing_state = MEI_WRITING;
list_add_tail(&write_cb->cb_list,
&dev->write_list.mei_cb.cb_list);
}
mutex_unlock(&dev->device_lock);
return length;
unlock_dev:
mutex_unlock(&dev->device_lock);
mei_free_cb_private(write_cb);
return rets;
}
static long mei_ioctl(struct file *file, unsigned int cmd, unsigned long data)
{
struct mei_device *dev;
struct mei_cl *cl = file->private_data;
struct mei_connect_client_data *connect_data = NULL;
int rets;
if (cmd != IOCTL_MEI_CONNECT_CLIENT)
return -EINVAL;
if (WARN_ON(!cl || !cl->dev))
return -ENODEV;
dev = cl->dev;
dev_dbg(&dev->pdev->dev, "IOCTL cmd = 0x%x", cmd);
mutex_lock(&dev->device_lock);
if (dev->mei_state != MEI_ENABLED) {
rets = -ENODEV;
goto out;
}
dev_dbg(&dev->pdev->dev, ": IOCTL_MEI_CONNECT_CLIENT.\n");
connect_data = kzalloc(sizeof(struct mei_connect_client_data),
GFP_KERNEL);
if (!connect_data) {
rets = -ENOMEM;
goto out;
}
dev_dbg(&dev->pdev->dev, "copy connect data from user\n");
if (copy_from_user(connect_data, (char __user *)data,
sizeof(struct mei_connect_client_data))) {
dev_dbg(&dev->pdev->dev, "failed to copy data from userland\n");
rets = -EFAULT;
goto out;
}
rets = mei_ioctl_connect_client(file, connect_data);
if (rets)
goto out;
dev_dbg(&dev->pdev->dev, "copy connect data to user\n");
if (copy_to_user((char __user *)data, connect_data,
sizeof(struct mei_connect_client_data))) {
dev_dbg(&dev->pdev->dev, "failed to copy data to userland\n");
rets = -EFAULT;
goto out;
}
out:
kfree(connect_data);
mutex_unlock(&dev->device_lock);
return rets;
}
static long mei_compat_ioctl(struct file *file,
unsigned int cmd, unsigned long data)
{
return mei_ioctl(file, cmd, (unsigned long)compat_ptr(data));
}
static unsigned int mei_poll(struct file *file, poll_table *wait)
{
struct mei_cl *cl = file->private_data;
struct mei_device *dev;
unsigned int mask = 0;
if (WARN_ON(!cl || !cl->dev))
return mask;
dev = cl->dev;
mutex_lock(&dev->device_lock);
if (dev->mei_state != MEI_ENABLED)
goto out;
if (cl == &dev->iamthif_cl) {
mutex_unlock(&dev->device_lock);
poll_wait(file, &dev->iamthif_cl.wait, wait);
mutex_lock(&dev->device_lock);
if (dev->iamthif_state == MEI_IAMTHIF_READ_COMPLETE &&
dev->iamthif_file_object == file) {
mask |= (POLLIN | POLLRDNORM);
dev_dbg(&dev->pdev->dev, "run next amthi cb\n");
mei_run_next_iamthif_cmd(dev);
}
goto out;
}
mutex_unlock(&dev->device_lock);
poll_wait(file, &cl->tx_wait, wait);
mutex_lock(&dev->device_lock);
if (MEI_WRITE_COMPLETE == cl->writing_state)
mask |= (POLLIN | POLLRDNORM);
out:
mutex_unlock(&dev->device_lock);
return mask;
}
static int __devinit mei_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct mei_device *dev;
int err;
mutex_lock(&mei_mutex);
if (mei_device) {
err = -EEXIST;
goto end;
}
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "failed to enable pci device.\n");
goto end;
}
pci_set_master(pdev);
err = pci_request_regions(pdev, mei_driver_name);
if (err) {
dev_err(&pdev->dev, "failed to get pci regions.\n");
goto disable_device;
}
dev = mei_device_init(pdev);
if (!dev) {
err = -ENOMEM;
goto release_regions;
}
dev->mem_addr = pci_iomap(pdev, 0, 0);
if (!dev->mem_addr) {
dev_err(&pdev->dev, "mapping I/O device memory failure.\n");
err = -ENOMEM;
goto free_device;
}
pci_enable_msi(pdev);
if (pci_dev_msi_enabled(pdev))
err = request_threaded_irq(pdev->irq,
NULL,
mei_interrupt_thread_handler,
IRQF_ONESHOT, mei_driver_name, dev);
else
err = request_threaded_irq(pdev->irq,
mei_interrupt_quick_handler,
mei_interrupt_thread_handler,
IRQF_SHARED, mei_driver_name, dev);
if (err) {
dev_err(&pdev->dev, "request_threaded_irq failure. irq = %d\n",
pdev->irq);
goto disable_msi;
}
INIT_DELAYED_WORK(&dev->timer_work, mei_timer);
if (mei_hw_init(dev)) {
dev_err(&pdev->dev, "init hw failure.\n");
err = -ENODEV;
goto release_irq;
}
err = misc_register(&mei_misc_device);
if (err)
goto release_irq;
mei_device = pdev;
pci_set_drvdata(pdev, dev);
schedule_delayed_work(&dev->timer_work, HZ);
mutex_unlock(&mei_mutex);
pr_debug("initialization successful.\n");
return 0;
release_irq:
dev->host_hw_state = mei_hcsr_read(dev);
mei_disable_interrupts(dev);
flush_scheduled_work();
free_irq(pdev->irq, dev);
disable_msi:
pci_disable_msi(pdev);
pci_iounmap(pdev, dev->mem_addr);
free_device:
kfree(dev);
release_regions:
pci_release_regions(pdev);
disable_device:
pci_disable_device(pdev);
end:
mutex_unlock(&mei_mutex);
dev_err(&pdev->dev, "initialization failed.\n");
return err;
}
static void __devexit mei_remove(struct pci_dev *pdev)
{
struct mei_device *dev;
if (mei_device != pdev)
return;
dev = pci_get_drvdata(pdev);
if (!dev)
return;
mutex_lock(&dev->device_lock);
mei_wd_stop(dev, false);
mei_device = NULL;
if (dev->iamthif_cl.state == MEI_FILE_CONNECTED) {
dev->iamthif_cl.state = MEI_FILE_DISCONNECTING;
mei_disconnect_host_client(dev, &dev->iamthif_cl);
}
if (dev->wd_cl.state == MEI_FILE_CONNECTED) {
dev->wd_cl.state = MEI_FILE_DISCONNECTING;
mei_disconnect_host_client(dev, &dev->wd_cl);
}
mei_watchdog_unregister(dev);
dev_dbg(&pdev->dev, "list del iamthif and wd file list.\n");
mei_remove_client_from_file_list(dev, dev->wd_cl.host_client_id);
mei_remove_client_from_file_list(dev, dev->iamthif_cl.host_client_id);
dev->iamthif_current_cb = NULL;
dev->me_clients_num = 0;
mutex_unlock(&dev->device_lock);
flush_scheduled_work();
mei_disable_interrupts(dev);
free_irq(pdev->irq, dev);
pci_disable_msi(pdev);
pci_set_drvdata(pdev, NULL);
if (dev->mem_addr)
pci_iounmap(pdev, dev->mem_addr);
kfree(dev);
pci_release_regions(pdev);
pci_disable_device(pdev);
misc_deregister(&mei_misc_device);
}
static int mei_pci_suspend(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev = pci_get_drvdata(pdev);
int err;
if (!dev)
return -ENODEV;
mutex_lock(&dev->device_lock);
err = mei_wd_stop(dev, true);
if (dev->mei_state == MEI_ENABLED ||
dev->mei_state == MEI_RECOVERING_FROM_RESET) {
dev->mei_state = MEI_POWER_DOWN;
mei_reset(dev, 0);
}
mutex_unlock(&dev->device_lock);
free_irq(pdev->irq, dev);
pci_disable_msi(pdev);
return err;
}
static int mei_pci_resume(struct device *device)
{
struct pci_dev *pdev = to_pci_dev(device);
struct mei_device *dev;
int err;
dev = pci_get_drvdata(pdev);
if (!dev)
return -ENODEV;
pci_enable_msi(pdev);
if (pci_dev_msi_enabled(pdev))
err = request_threaded_irq(pdev->irq,
NULL,
mei_interrupt_thread_handler,
IRQF_ONESHOT, mei_driver_name, dev);
else
err = request_threaded_irq(pdev->irq,
mei_interrupt_quick_handler,
mei_interrupt_thread_handler,
IRQF_SHARED, mei_driver_name, dev);
if (err) {
dev_err(&pdev->dev, "request_threaded_irq failed: irq = %d.\n",
pdev->irq);
return err;
}
mutex_lock(&dev->device_lock);
dev->mei_state = MEI_POWER_UP;
mei_reset(dev, 1);
mutex_unlock(&dev->device_lock);
schedule_delayed_work(&dev->timer_work, HZ);
return err;
}
static int __init mei_init_module(void)
{
int ret;
pr_debug("loading.\n");
ret = pci_register_driver(&mei_driver);
if (ret < 0)
pr_err("error registering driver.\n");
return ret;
}
static void __exit mei_exit_module(void)
{
pci_unregister_driver(&mei_driver);
pr_debug("unloaded successfully.\n");
}
