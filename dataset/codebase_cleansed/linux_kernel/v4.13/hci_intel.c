static u8 intel_convert_speed(unsigned int speed)
{
switch (speed) {
case 9600:
return 0x00;
case 19200:
return 0x01;
case 38400:
return 0x02;
case 57600:
return 0x03;
case 115200:
return 0x04;
case 230400:
return 0x05;
case 460800:
return 0x06;
case 921600:
return 0x07;
case 1843200:
return 0x08;
case 3250000:
return 0x09;
case 2000000:
return 0x0a;
case 3000000:
return 0x0b;
default:
return 0xff;
}
}
static int intel_wait_booting(struct hci_uart *hu)
{
struct intel_data *intel = hu->priv;
int err;
err = wait_on_bit_timeout(&intel->flags, STATE_BOOTING,
TASK_INTERRUPTIBLE,
msecs_to_jiffies(1000));
if (err == -EINTR) {
bt_dev_err(hu->hdev, "Device boot interrupted");
return -EINTR;
}
if (err) {
bt_dev_err(hu->hdev, "Device boot timeout");
return -ETIMEDOUT;
}
return err;
}
static int intel_wait_lpm_transaction(struct hci_uart *hu)
{
struct intel_data *intel = hu->priv;
int err;
err = wait_on_bit_timeout(&intel->flags, STATE_LPM_TRANSACTION,
TASK_INTERRUPTIBLE,
msecs_to_jiffies(1000));
if (err == -EINTR) {
bt_dev_err(hu->hdev, "LPM transaction interrupted");
return -EINTR;
}
if (err) {
bt_dev_err(hu->hdev, "LPM transaction timeout");
return -ETIMEDOUT;
}
return err;
}
static int intel_lpm_suspend(struct hci_uart *hu)
{
static const u8 suspend[] = { 0x01, 0x01, 0x01 };
struct intel_data *intel = hu->priv;
struct sk_buff *skb;
if (!test_bit(STATE_LPM_ENABLED, &intel->flags) ||
test_bit(STATE_SUSPENDED, &intel->flags))
return 0;
if (test_bit(STATE_TX_ACTIVE, &intel->flags))
return -EAGAIN;
bt_dev_dbg(hu->hdev, "Suspending");
skb = bt_skb_alloc(sizeof(suspend), GFP_KERNEL);
if (!skb) {
bt_dev_err(hu->hdev, "Failed to alloc memory for LPM packet");
return -ENOMEM;
}
skb_put_data(skb, suspend, sizeof(suspend));
hci_skb_pkt_type(skb) = HCI_LPM_PKT;
set_bit(STATE_LPM_TRANSACTION, &intel->flags);
skb_queue_head(&intel->txq, skb);
hci_uart_tx_wakeup(hu);
intel_wait_lpm_transaction(hu);
clear_bit(STATE_LPM_TRANSACTION, &intel->flags);
if (!test_bit(STATE_SUSPENDED, &intel->flags)) {
bt_dev_err(hu->hdev, "Device suspend error");
return -EINVAL;
}
bt_dev_dbg(hu->hdev, "Suspended");
hci_uart_set_flow_control(hu, true);
return 0;
}
static int intel_lpm_resume(struct hci_uart *hu)
{
struct intel_data *intel = hu->priv;
struct sk_buff *skb;
if (!test_bit(STATE_LPM_ENABLED, &intel->flags) ||
!test_bit(STATE_SUSPENDED, &intel->flags))
return 0;
bt_dev_dbg(hu->hdev, "Resuming");
hci_uart_set_flow_control(hu, false);
skb = bt_skb_alloc(0, GFP_KERNEL);
if (!skb) {
bt_dev_err(hu->hdev, "Failed to alloc memory for LPM packet");
return -ENOMEM;
}
hci_skb_pkt_type(skb) = HCI_LPM_WAKE_PKT;
set_bit(STATE_LPM_TRANSACTION, &intel->flags);
skb_queue_head(&intel->txq, skb);
hci_uart_tx_wakeup(hu);
intel_wait_lpm_transaction(hu);
clear_bit(STATE_LPM_TRANSACTION, &intel->flags);
if (test_bit(STATE_SUSPENDED, &intel->flags)) {
bt_dev_err(hu->hdev, "Device resume error");
return -EINVAL;
}
bt_dev_dbg(hu->hdev, "Resumed");
return 0;
}
static int intel_lpm_host_wake(struct hci_uart *hu)
{
static const u8 lpm_resume_ack[] = { LPM_OP_RESUME_ACK, 0x00 };
struct intel_data *intel = hu->priv;
struct sk_buff *skb;
hci_uart_set_flow_control(hu, false);
clear_bit(STATE_SUSPENDED, &intel->flags);
skb = bt_skb_alloc(sizeof(lpm_resume_ack), GFP_KERNEL);
if (!skb) {
bt_dev_err(hu->hdev, "Failed to alloc memory for LPM packet");
return -ENOMEM;
}
skb_put_data(skb, lpm_resume_ack, sizeof(lpm_resume_ack));
hci_skb_pkt_type(skb) = HCI_LPM_PKT;
skb_queue_head(&intel->txq, skb);
hci_uart_tx_wakeup(hu);
bt_dev_dbg(hu->hdev, "Resumed by controller");
return 0;
}
static irqreturn_t intel_irq(int irq, void *dev_id)
{
struct intel_device *idev = dev_id;
dev_info(&idev->pdev->dev, "hci_intel irq\n");
mutex_lock(&idev->hu_lock);
if (idev->hu)
intel_lpm_host_wake(idev->hu);
mutex_unlock(&idev->hu_lock);
pm_runtime_get(&idev->pdev->dev);
pm_runtime_mark_last_busy(&idev->pdev->dev);
pm_runtime_put_autosuspend(&idev->pdev->dev);
return IRQ_HANDLED;
}
static int intel_set_power(struct hci_uart *hu, bool powered)
{
struct list_head *p;
int err = -ENODEV;
if (!hu->tty->dev)
return err;
mutex_lock(&intel_device_list_lock);
list_for_each(p, &intel_device_list) {
struct intel_device *idev = list_entry(p, struct intel_device,
list);
if (hu->tty->dev->parent != idev->pdev->dev.parent)
continue;
if (!idev->reset) {
err = -ENOTSUPP;
break;
}
BT_INFO("hu %p, Switching compatible pm device (%s) to %u",
hu, dev_name(&idev->pdev->dev), powered);
gpiod_set_value(idev->reset, powered);
mutex_lock(&idev->hu_lock);
idev->hu = powered ? hu : NULL;
mutex_unlock(&idev->hu_lock);
if (idev->irq < 0)
break;
if (powered && device_can_wakeup(&idev->pdev->dev)) {
err = devm_request_threaded_irq(&idev->pdev->dev,
idev->irq, NULL,
intel_irq,
IRQF_ONESHOT,
"bt-host-wake", idev);
if (err) {
BT_ERR("hu %p, unable to allocate irq-%d",
hu, idev->irq);
break;
}
device_wakeup_enable(&idev->pdev->dev);
pm_runtime_set_active(&idev->pdev->dev);
pm_runtime_use_autosuspend(&idev->pdev->dev);
pm_runtime_set_autosuspend_delay(&idev->pdev->dev,
LPM_SUSPEND_DELAY_MS);
pm_runtime_enable(&idev->pdev->dev);
} else if (!powered && device_may_wakeup(&idev->pdev->dev)) {
devm_free_irq(&idev->pdev->dev, idev->irq, idev);
device_wakeup_disable(&idev->pdev->dev);
pm_runtime_disable(&idev->pdev->dev);
}
}
mutex_unlock(&intel_device_list_lock);
return err;
}
static void intel_busy_work(struct work_struct *work)
{
struct list_head *p;
struct intel_data *intel = container_of(work, struct intel_data,
busy_work);
if (!intel->hu->tty->dev)
return;
mutex_lock(&intel_device_list_lock);
list_for_each(p, &intel_device_list) {
struct intel_device *idev = list_entry(p, struct intel_device,
list);
if (intel->hu->tty->dev->parent == idev->pdev->dev.parent) {
pm_runtime_get(&idev->pdev->dev);
pm_runtime_mark_last_busy(&idev->pdev->dev);
pm_runtime_put_autosuspend(&idev->pdev->dev);
break;
}
}
mutex_unlock(&intel_device_list_lock);
}
static int intel_open(struct hci_uart *hu)
{
struct intel_data *intel;
BT_DBG("hu %p", hu);
intel = kzalloc(sizeof(*intel), GFP_KERNEL);
if (!intel)
return -ENOMEM;
skb_queue_head_init(&intel->txq);
INIT_WORK(&intel->busy_work, intel_busy_work);
intel->hu = hu;
hu->priv = intel;
if (!intel_set_power(hu, true))
set_bit(STATE_BOOTING, &intel->flags);
return 0;
}
static int intel_close(struct hci_uart *hu)
{
struct intel_data *intel = hu->priv;
BT_DBG("hu %p", hu);
cancel_work_sync(&intel->busy_work);
intel_set_power(hu, false);
skb_queue_purge(&intel->txq);
kfree_skb(intel->rx_skb);
kfree(intel);
hu->priv = NULL;
return 0;
}
static int intel_flush(struct hci_uart *hu)
{
struct intel_data *intel = hu->priv;
BT_DBG("hu %p", hu);
skb_queue_purge(&intel->txq);
return 0;
}
static int inject_cmd_complete(struct hci_dev *hdev, __u16 opcode)
{
struct sk_buff *skb;
struct hci_event_hdr *hdr;
struct hci_ev_cmd_complete *evt;
skb = bt_skb_alloc(sizeof(*hdr) + sizeof(*evt) + 1, GFP_ATOMIC);
if (!skb)
return -ENOMEM;
hdr = skb_put(skb, sizeof(*hdr));
hdr->evt = HCI_EV_CMD_COMPLETE;
hdr->plen = sizeof(*evt) + 1;
evt = skb_put(skb, sizeof(*evt));
evt->ncmd = 0x01;
evt->opcode = cpu_to_le16(opcode);
skb_put_u8(skb, 0x00);
hci_skb_pkt_type(skb) = HCI_EVENT_PKT;
return hci_recv_frame(hdev, skb);
}
static int intel_set_baudrate(struct hci_uart *hu, unsigned int speed)
{
struct intel_data *intel = hu->priv;
struct hci_dev *hdev = hu->hdev;
u8 speed_cmd[] = { 0x06, 0xfc, 0x01, 0x00 };
struct sk_buff *skb;
int err;
err = intel_wait_booting(hu);
clear_bit(STATE_BOOTING, &intel->flags);
if (err && err != -ETIMEDOUT)
return err;
bt_dev_info(hdev, "Change controller speed to %d", speed);
speed_cmd[3] = intel_convert_speed(speed);
if (speed_cmd[3] == 0xff) {
bt_dev_err(hdev, "Unsupported speed");
return -EINVAL;
}
skb = __hci_cmd_sync(hdev, 0xfc05, 0, NULL, HCI_CMD_TIMEOUT);
if (IS_ERR(skb)) {
bt_dev_err(hdev, "Reading Intel version information failed (%ld)",
PTR_ERR(skb));
return PTR_ERR(skb);
}
kfree_skb(skb);
skb = bt_skb_alloc(sizeof(speed_cmd), GFP_KERNEL);
if (!skb) {
bt_dev_err(hdev, "Failed to alloc memory for baudrate packet");
return -ENOMEM;
}
skb_put_data(skb, speed_cmd, sizeof(speed_cmd));
hci_skb_pkt_type(skb) = HCI_COMMAND_PKT;
hci_uart_set_flow_control(hu, true);
skb_queue_tail(&intel->txq, skb);
hci_uart_tx_wakeup(hu);
msleep(100);
hci_uart_set_baudrate(hu, speed);
hci_uart_set_flow_control(hu, false);
return 0;
}
static int intel_setup(struct hci_uart *hu)
{
static const u8 reset_param[] = { 0x00, 0x01, 0x00, 0x01,
0x00, 0x08, 0x04, 0x00 };
struct intel_data *intel = hu->priv;
struct hci_dev *hdev = hu->hdev;
struct sk_buff *skb;
struct intel_version ver;
struct intel_boot_params *params;
struct list_head *p;
const struct firmware *fw;
const u8 *fw_ptr;
char fwname[64];
u32 frag_len;
ktime_t calltime, delta, rettime;
unsigned long long duration;
unsigned int init_speed, oper_speed;
int speed_change = 0;
int err;
bt_dev_dbg(hdev, "start intel_setup");
hu->hdev->set_diag = btintel_set_diag;
hu->hdev->set_bdaddr = btintel_set_bdaddr;
calltime = ktime_get();
if (hu->init_speed)
init_speed = hu->init_speed;
else
init_speed = hu->proto->init_speed;
if (hu->oper_speed)
oper_speed = hu->oper_speed;
else
oper_speed = hu->proto->oper_speed;
if (oper_speed && init_speed && oper_speed != init_speed)
speed_change = 1;
err = intel_wait_booting(hu);
clear_bit(STATE_BOOTING, &intel->flags);
if (err && err != -ETIMEDOUT)
return err;
set_bit(STATE_BOOTLOADER, &intel->flags);
err = btintel_read_version(hdev, &ver);
if (err)
return err;
if (ver.hw_platform != 0x37) {
bt_dev_err(hdev, "Unsupported Intel hardware platform (%u)",
ver.hw_platform);
return -EINVAL;
}
switch (ver.hw_variant) {
case 0x0b:
case 0x0c:
case 0x12:
break;
default:
bt_dev_err(hdev, "Unsupported Intel hardware variant (%u)",
ver.hw_variant);
return -EINVAL;
}
btintel_version_info(hdev, &ver);
if (ver.fw_variant == 0x23) {
clear_bit(STATE_BOOTLOADER, &intel->flags);
btintel_check_bdaddr(hdev);
return 0;
}
if (ver.fw_variant != 0x06) {
bt_dev_err(hdev, "Unsupported Intel firmware variant (%u)",
ver.fw_variant);
return -ENODEV;
}
skb = __hci_cmd_sync(hdev, 0xfc0d, 0, NULL, HCI_CMD_TIMEOUT);
if (IS_ERR(skb)) {
bt_dev_err(hdev, "Reading Intel boot parameters failed (%ld)",
PTR_ERR(skb));
return PTR_ERR(skb);
}
if (skb->len != sizeof(*params)) {
bt_dev_err(hdev, "Intel boot parameters size mismatch");
kfree_skb(skb);
return -EILSEQ;
}
params = (struct intel_boot_params *)skb->data;
if (params->status) {
bt_dev_err(hdev, "Intel boot parameters command failure (%02x)",
params->status);
err = -bt_to_errno(params->status);
kfree_skb(skb);
return err;
}
bt_dev_info(hdev, "Device revision is %u",
le16_to_cpu(params->dev_revid));
bt_dev_info(hdev, "Secure boot is %s",
params->secure_boot ? "enabled" : "disabled");
bt_dev_info(hdev, "Minimum firmware build %u week %u %u",
params->min_fw_build_nn, params->min_fw_build_cw,
2000 + params->min_fw_build_yy);
if (params->limited_cce != 0x00) {
bt_dev_err(hdev, "Unsupported Intel firmware loading method (%u)",
params->limited_cce);
kfree_skb(skb);
return -EINVAL;
}
if (!bacmp(&params->otp_bdaddr, BDADDR_ANY)) {
bt_dev_info(hdev, "No device address configured");
set_bit(HCI_QUIRK_INVALID_BDADDR, &hdev->quirks);
}
snprintf(fwname, sizeof(fwname), "intel/ibt-%u-%u.sfi",
le16_to_cpu(ver.hw_variant),
le16_to_cpu(params->dev_revid));
err = request_firmware(&fw, fwname, &hdev->dev);
if (err < 0) {
bt_dev_err(hdev, "Failed to load Intel firmware file (%d)",
err);
kfree_skb(skb);
return err;
}
bt_dev_info(hdev, "Found device firmware: %s", fwname);
snprintf(fwname, sizeof(fwname), "intel/ibt-%u-%u.ddc",
le16_to_cpu(ver.hw_variant),
le16_to_cpu(params->dev_revid));
kfree_skb(skb);
if (fw->size < 644) {
bt_dev_err(hdev, "Invalid size of firmware file (%zu)",
fw->size);
err = -EBADF;
goto done;
}
set_bit(STATE_DOWNLOADING, &intel->flags);
err = btintel_secure_send(hdev, 0x00, 128, fw->data);
if (err < 0) {
bt_dev_err(hdev, "Failed to send firmware header (%d)", err);
goto done;
}
err = btintel_secure_send(hdev, 0x03, 256, fw->data + 128);
if (err < 0) {
bt_dev_err(hdev, "Failed to send firmware public key (%d)",
err);
goto done;
}
err = btintel_secure_send(hdev, 0x02, 256, fw->data + 388);
if (err < 0) {
bt_dev_err(hdev, "Failed to send firmware signature (%d)",
err);
goto done;
}
fw_ptr = fw->data + 644;
frag_len = 0;
while (fw_ptr - fw->data < fw->size) {
struct hci_command_hdr *cmd = (void *)(fw_ptr + frag_len);
frag_len += sizeof(*cmd) + cmd->plen;
bt_dev_dbg(hdev, "Patching %td/%zu", (fw_ptr - fw->data),
fw->size);
if (frag_len % 4)
continue;
err = btintel_secure_send(hdev, 0x01, frag_len, fw_ptr);
if (err < 0) {
bt_dev_err(hdev, "Failed to send firmware data (%d)",
err);
goto done;
}
fw_ptr += frag_len;
frag_len = 0;
}
set_bit(STATE_FIRMWARE_LOADED, &intel->flags);
bt_dev_info(hdev, "Waiting for firmware download to complete");
err = wait_on_bit_timeout(&intel->flags, STATE_DOWNLOADING,
TASK_INTERRUPTIBLE,
msecs_to_jiffies(5000));
if (err == -EINTR) {
bt_dev_err(hdev, "Firmware loading interrupted");
err = -EINTR;
goto done;
}
if (err) {
bt_dev_err(hdev, "Firmware loading timeout");
err = -ETIMEDOUT;
goto done;
}
if (test_bit(STATE_FIRMWARE_FAILED, &intel->flags)) {
bt_dev_err(hdev, "Firmware loading failed");
err = -ENOEXEC;
goto done;
}
rettime = ktime_get();
delta = ktime_sub(rettime, calltime);
duration = (unsigned long long) ktime_to_ns(delta) >> 10;
bt_dev_info(hdev, "Firmware loaded in %llu usecs", duration);
done:
release_firmware(fw);
if (err < 0)
return err;
if (speed_change) {
err = intel_set_baudrate(hu, init_speed);
if (err)
return err;
}
calltime = ktime_get();
set_bit(STATE_BOOTING, &intel->flags);
skb = __hci_cmd_sync(hdev, 0xfc01, sizeof(reset_param), reset_param,
HCI_CMD_TIMEOUT);
if (IS_ERR(skb))
return PTR_ERR(skb);
kfree_skb(skb);
bt_dev_info(hdev, "Waiting for device to boot");
err = intel_wait_booting(hu);
if (err)
return err;
clear_bit(STATE_BOOTING, &intel->flags);
rettime = ktime_get();
delta = ktime_sub(rettime, calltime);
duration = (unsigned long long) ktime_to_ns(delta) >> 10;
bt_dev_info(hdev, "Device booted in %llu usecs", duration);
mutex_lock(&intel_device_list_lock);
list_for_each(p, &intel_device_list) {
struct intel_device *dev = list_entry(p, struct intel_device,
list);
if (!hu->tty->dev)
break;
if (hu->tty->dev->parent == dev->pdev->dev.parent) {
if (device_may_wakeup(&dev->pdev->dev)) {
set_bit(STATE_LPM_ENABLED, &intel->flags);
set_bit(STATE_TX_ACTIVE, &intel->flags);
}
break;
}
}
mutex_unlock(&intel_device_list_lock);
btintel_load_ddc_config(hdev, fwname);
skb = __hci_cmd_sync(hdev, HCI_OP_RESET, 0, NULL, HCI_CMD_TIMEOUT);
if (IS_ERR(skb))
return PTR_ERR(skb);
kfree_skb(skb);
if (speed_change) {
err = intel_set_baudrate(hu, oper_speed);
if (err)
return err;
}
bt_dev_info(hdev, "Setup complete");
clear_bit(STATE_BOOTLOADER, &intel->flags);
return 0;
}
static int intel_recv_event(struct hci_dev *hdev, struct sk_buff *skb)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
struct intel_data *intel = hu->priv;
struct hci_event_hdr *hdr;
if (!test_bit(STATE_BOOTLOADER, &intel->flags) &&
!test_bit(STATE_BOOTING, &intel->flags))
goto recv;
hdr = (void *)skb->data;
if (skb->len == 7 && hdr->evt == 0xff && hdr->plen == 0x05 &&
skb->data[2] == 0x06) {
if (skb->data[3] != 0x00)
set_bit(STATE_FIRMWARE_FAILED, &intel->flags);
if (test_and_clear_bit(STATE_DOWNLOADING, &intel->flags) &&
test_bit(STATE_FIRMWARE_LOADED, &intel->flags)) {
smp_mb__after_atomic();
wake_up_bit(&intel->flags, STATE_DOWNLOADING);
}
} else if (skb->len == 9 && hdr->evt == 0xff && hdr->plen == 0x07 &&
skb->data[2] == 0x02) {
if (test_and_clear_bit(STATE_BOOTING, &intel->flags)) {
smp_mb__after_atomic();
wake_up_bit(&intel->flags, STATE_BOOTING);
}
}
recv:
return hci_recv_frame(hdev, skb);
}
static void intel_recv_lpm_notify(struct hci_dev *hdev, int value)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
struct intel_data *intel = hu->priv;
bt_dev_dbg(hdev, "TX idle notification (%d)", value);
if (value) {
set_bit(STATE_TX_ACTIVE, &intel->flags);
schedule_work(&intel->busy_work);
} else {
clear_bit(STATE_TX_ACTIVE, &intel->flags);
}
}
static int intel_recv_lpm(struct hci_dev *hdev, struct sk_buff *skb)
{
struct hci_lpm_pkt *lpm = (void *)skb->data;
struct hci_uart *hu = hci_get_drvdata(hdev);
struct intel_data *intel = hu->priv;
switch (lpm->opcode) {
case LPM_OP_TX_NOTIFY:
if (lpm->dlen < 1) {
bt_dev_err(hu->hdev, "Invalid LPM notification packet");
break;
}
intel_recv_lpm_notify(hdev, lpm->data[0]);
break;
case LPM_OP_SUSPEND_ACK:
set_bit(STATE_SUSPENDED, &intel->flags);
if (test_and_clear_bit(STATE_LPM_TRANSACTION, &intel->flags)) {
smp_mb__after_atomic();
wake_up_bit(&intel->flags, STATE_LPM_TRANSACTION);
}
break;
case LPM_OP_RESUME_ACK:
clear_bit(STATE_SUSPENDED, &intel->flags);
if (test_and_clear_bit(STATE_LPM_TRANSACTION, &intel->flags)) {
smp_mb__after_atomic();
wake_up_bit(&intel->flags, STATE_LPM_TRANSACTION);
}
break;
default:
bt_dev_err(hdev, "Unknown LPM opcode (%02x)", lpm->opcode);
break;
}
kfree_skb(skb);
return 0;
}
static int intel_recv(struct hci_uart *hu, const void *data, int count)
{
struct intel_data *intel = hu->priv;
if (!test_bit(HCI_UART_REGISTERED, &hu->flags))
return -EUNATCH;
intel->rx_skb = h4_recv_buf(hu->hdev, intel->rx_skb, data, count,
intel_recv_pkts,
ARRAY_SIZE(intel_recv_pkts));
if (IS_ERR(intel->rx_skb)) {
int err = PTR_ERR(intel->rx_skb);
bt_dev_err(hu->hdev, "Frame reassembly failed (%d)", err);
intel->rx_skb = NULL;
return err;
}
return count;
}
static int intel_enqueue(struct hci_uart *hu, struct sk_buff *skb)
{
struct intel_data *intel = hu->priv;
struct list_head *p;
BT_DBG("hu %p skb %p", hu, skb);
if (!hu->tty->dev)
goto out_enqueue;
mutex_lock(&intel_device_list_lock);
list_for_each(p, &intel_device_list) {
struct intel_device *idev = list_entry(p, struct intel_device,
list);
if (hu->tty->dev->parent == idev->pdev->dev.parent) {
pm_runtime_get_sync(&idev->pdev->dev);
pm_runtime_mark_last_busy(&idev->pdev->dev);
pm_runtime_put_autosuspend(&idev->pdev->dev);
break;
}
}
mutex_unlock(&intel_device_list_lock);
out_enqueue:
skb_queue_tail(&intel->txq, skb);
return 0;
}
static struct sk_buff *intel_dequeue(struct hci_uart *hu)
{
struct intel_data *intel = hu->priv;
struct sk_buff *skb;
skb = skb_dequeue(&intel->txq);
if (!skb)
return skb;
if (test_bit(STATE_BOOTLOADER, &intel->flags) &&
(hci_skb_pkt_type(skb) == HCI_COMMAND_PKT)) {
struct hci_command_hdr *cmd = (void *)skb->data;
__u16 opcode = le16_to_cpu(cmd->opcode);
if (opcode == 0xfc01)
inject_cmd_complete(hu->hdev, opcode);
}
memcpy(skb_push(skb, 1), &hci_skb_pkt_type(skb), 1);
return skb;
}
static int intel_suspend_device(struct device *dev)
{
struct intel_device *idev = dev_get_drvdata(dev);
mutex_lock(&idev->hu_lock);
if (idev->hu)
intel_lpm_suspend(idev->hu);
mutex_unlock(&idev->hu_lock);
return 0;
}
static int intel_resume_device(struct device *dev)
{
struct intel_device *idev = dev_get_drvdata(dev);
mutex_lock(&idev->hu_lock);
if (idev->hu)
intel_lpm_resume(idev->hu);
mutex_unlock(&idev->hu_lock);
return 0;
}
static int intel_suspend(struct device *dev)
{
struct intel_device *idev = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
enable_irq_wake(idev->irq);
return intel_suspend_device(dev);
}
static int intel_resume(struct device *dev)
{
struct intel_device *idev = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
disable_irq_wake(idev->irq);
return intel_resume_device(dev);
}
static int intel_probe(struct platform_device *pdev)
{
struct intel_device *idev;
int ret;
idev = devm_kzalloc(&pdev->dev, sizeof(*idev), GFP_KERNEL);
if (!idev)
return -ENOMEM;
mutex_init(&idev->hu_lock);
idev->pdev = pdev;
ret = devm_acpi_dev_add_driver_gpios(&pdev->dev, acpi_hci_intel_gpios);
if (ret)
dev_dbg(&pdev->dev, "Unable to add GPIO mapping table\n");
idev->reset = devm_gpiod_get(&pdev->dev, "reset", GPIOD_OUT_LOW);
if (IS_ERR(idev->reset)) {
dev_err(&pdev->dev, "Unable to retrieve gpio\n");
return PTR_ERR(idev->reset);
}
idev->irq = platform_get_irq(pdev, 0);
if (idev->irq < 0) {
struct gpio_desc *host_wake;
dev_err(&pdev->dev, "No IRQ, falling back to gpio-irq\n");
host_wake = devm_gpiod_get(&pdev->dev, "host-wake", GPIOD_IN);
if (IS_ERR(host_wake)) {
dev_err(&pdev->dev, "Unable to retrieve IRQ\n");
goto no_irq;
}
idev->irq = gpiod_to_irq(host_wake);
if (idev->irq < 0) {
dev_err(&pdev->dev, "No corresponding irq for gpio\n");
goto no_irq;
}
}
device_set_wakeup_capable(&pdev->dev, true);
device_wakeup_disable(&pdev->dev);
no_irq:
platform_set_drvdata(pdev, idev);
mutex_lock(&intel_device_list_lock);
list_add_tail(&idev->list, &intel_device_list);
mutex_unlock(&intel_device_list_lock);
dev_info(&pdev->dev, "registered, gpio(%d)/irq(%d).\n",
desc_to_gpio(idev->reset), idev->irq);
return 0;
}
static int intel_remove(struct platform_device *pdev)
{
struct intel_device *idev = platform_get_drvdata(pdev);
device_wakeup_disable(&pdev->dev);
mutex_lock(&intel_device_list_lock);
list_del(&idev->list);
mutex_unlock(&intel_device_list_lock);
dev_info(&pdev->dev, "unregistered.\n");
return 0;
}
int __init intel_init(void)
{
platform_driver_register(&intel_driver);
return hci_uart_register_proto(&intel_proto);
}
int __exit intel_deinit(void)
{
platform_driver_unregister(&intel_driver);
return hci_uart_unregister_proto(&intel_proto);
}
