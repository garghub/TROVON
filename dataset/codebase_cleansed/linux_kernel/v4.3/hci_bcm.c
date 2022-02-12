static int bcm_set_baudrate(struct hci_uart *hu, unsigned int speed)
{
struct hci_dev *hdev = hu->hdev;
struct sk_buff *skb;
struct bcm_update_uart_baud_rate param;
if (speed > 3000000) {
struct bcm_write_uart_clock_setting clock;
clock.type = BCM_UART_CLOCK_48MHZ;
BT_DBG("%s: Set Controller clock (%d)", hdev->name, clock.type);
skb = __hci_cmd_sync(hdev, 0xfc45, 1, &clock, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
int err = PTR_ERR(skb);
BT_ERR("%s: BCM: failed to write clock command (%d)",
hdev->name, err);
return err;
}
kfree_skb(skb);
}
BT_DBG("%s: Set Controller UART speed to %d bit/s", hdev->name, speed);
param.zero = cpu_to_le16(0);
param.baud_rate = cpu_to_le32(speed);
skb = __hci_cmd_sync(hdev, 0xfc18, sizeof(param), &param,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
int err = PTR_ERR(skb);
BT_ERR("%s: BCM: failed to write update baudrate command (%d)",
hdev->name, err);
return err;
}
kfree_skb(skb);
return 0;
}
static bool bcm_device_exists(struct bcm_device *device)
{
struct list_head *p;
list_for_each(p, &bcm_device_list) {
struct bcm_device *dev = list_entry(p, struct bcm_device, list);
if (device == dev)
return true;
}
return false;
}
static int bcm_gpio_set_power(struct bcm_device *dev, bool powered)
{
if (powered && !IS_ERR(dev->clk) && !dev->clk_enabled)
clk_enable(dev->clk);
gpiod_set_value(dev->shutdown, powered);
gpiod_set_value(dev->device_wakeup, powered);
if (!powered && !IS_ERR(dev->clk) && dev->clk_enabled)
clk_disable(dev->clk);
dev->clk_enabled = powered;
return 0;
}
static int bcm_open(struct hci_uart *hu)
{
struct bcm_data *bcm;
struct list_head *p;
BT_DBG("hu %p", hu);
bcm = kzalloc(sizeof(*bcm), GFP_KERNEL);
if (!bcm)
return -ENOMEM;
skb_queue_head_init(&bcm->txq);
hu->priv = bcm;
spin_lock(&bcm_device_lock);
list_for_each(p, &bcm_device_list) {
struct bcm_device *dev = list_entry(p, struct bcm_device, list);
if (hu->tty->dev->parent == dev->pdev->dev.parent) {
bcm->dev = dev;
hu->init_speed = dev->init_speed;
#ifdef CONFIG_PM_SLEEP
dev->hu = hu;
#endif
break;
}
}
if (bcm->dev)
bcm_gpio_set_power(bcm->dev, true);
spin_unlock(&bcm_device_lock);
return 0;
}
static int bcm_close(struct hci_uart *hu)
{
struct bcm_data *bcm = hu->priv;
BT_DBG("hu %p", hu);
spin_lock(&bcm_device_lock);
if (bcm_device_exists(bcm->dev)) {
bcm_gpio_set_power(bcm->dev, false);
#ifdef CONFIG_PM_SLEEP
bcm->dev->hu = NULL;
#endif
}
spin_unlock(&bcm_device_lock);
skb_queue_purge(&bcm->txq);
kfree_skb(bcm->rx_skb);
kfree(bcm);
hu->priv = NULL;
return 0;
}
static int bcm_flush(struct hci_uart *hu)
{
struct bcm_data *bcm = hu->priv;
BT_DBG("hu %p", hu);
skb_queue_purge(&bcm->txq);
return 0;
}
static int bcm_setup(struct hci_uart *hu)
{
char fw_name[64];
const struct firmware *fw;
unsigned int speed;
int err;
BT_DBG("hu %p", hu);
hu->hdev->set_bdaddr = btbcm_set_bdaddr;
err = btbcm_initialize(hu->hdev, fw_name, sizeof(fw_name));
if (err)
return err;
err = request_firmware(&fw, fw_name, &hu->hdev->dev);
if (err < 0) {
BT_INFO("%s: BCM: Patch %s not found", hu->hdev->name, fw_name);
return 0;
}
err = btbcm_patchram(hu->hdev, fw);
if (err) {
BT_INFO("%s: BCM: Patch failed (%d)", hu->hdev->name, err);
goto finalize;
}
if (hu->init_speed)
speed = hu->init_speed;
else if (hu->proto->init_speed)
speed = hu->proto->init_speed;
else
speed = 0;
if (speed)
hci_uart_set_baudrate(hu, speed);
if (hu->oper_speed)
speed = hu->oper_speed;
else if (hu->proto->oper_speed)
speed = hu->proto->oper_speed;
else
speed = 0;
if (speed) {
err = bcm_set_baudrate(hu, speed);
if (!err)
hci_uart_set_baudrate(hu, speed);
}
finalize:
release_firmware(fw);
err = btbcm_finalize(hu->hdev);
return err;
}
static int bcm_recv(struct hci_uart *hu, const void *data, int count)
{
struct bcm_data *bcm = hu->priv;
if (!test_bit(HCI_UART_REGISTERED, &hu->flags))
return -EUNATCH;
bcm->rx_skb = h4_recv_buf(hu->hdev, bcm->rx_skb, data, count,
bcm_recv_pkts, ARRAY_SIZE(bcm_recv_pkts));
if (IS_ERR(bcm->rx_skb)) {
int err = PTR_ERR(bcm->rx_skb);
BT_ERR("%s: Frame reassembly failed (%d)", hu->hdev->name, err);
bcm->rx_skb = NULL;
return err;
}
return count;
}
static int bcm_enqueue(struct hci_uart *hu, struct sk_buff *skb)
{
struct bcm_data *bcm = hu->priv;
BT_DBG("hu %p skb %p", hu, skb);
memcpy(skb_push(skb, 1), &bt_cb(skb)->pkt_type, 1);
skb_queue_tail(&bcm->txq, skb);
return 0;
}
static struct sk_buff *bcm_dequeue(struct hci_uart *hu)
{
struct bcm_data *bcm = hu->priv;
return skb_dequeue(&bcm->txq);
}
static int bcm_suspend(struct device *dev)
{
struct bcm_device *bdev = platform_get_drvdata(to_platform_device(dev));
BT_DBG("suspend (%p): is_suspended %d", bdev, bdev->is_suspended);
spin_lock(&bcm_device_lock);
if (!bdev->hu)
goto unlock;
if (!bdev->is_suspended) {
hci_uart_set_flow_control(bdev->hu, true);
bdev->is_suspended = true;
}
if (bdev->device_wakeup) {
gpiod_set_value(bdev->device_wakeup, false);
BT_DBG("suspend, delaying 15 ms");
mdelay(15);
}
unlock:
spin_unlock(&bcm_device_lock);
return 0;
}
static int bcm_resume(struct device *dev)
{
struct bcm_device *bdev = platform_get_drvdata(to_platform_device(dev));
BT_DBG("resume (%p): is_suspended %d", bdev, bdev->is_suspended);
spin_lock(&bcm_device_lock);
if (!bdev->hu)
goto unlock;
if (bdev->device_wakeup) {
gpiod_set_value(bdev->device_wakeup, true);
BT_DBG("resume, delaying 15 ms");
mdelay(15);
}
if (bdev->is_suspended) {
bdev->is_suspended = false;
hci_uart_set_flow_control(bdev->hu, false);
}
unlock:
spin_unlock(&bcm_device_lock);
return 0;
}
static int bcm_resource(struct acpi_resource *ares, void *data)
{
struct bcm_device *dev = data;
if (ares->type == ACPI_RESOURCE_TYPE_SERIAL_BUS) {
struct acpi_resource_uart_serialbus *sb;
sb = &ares->data.uart_serial_bus;
if (sb->type == ACPI_RESOURCE_SERIAL_TYPE_UART)
dev->init_speed = sb->default_baud_rate;
}
return 1;
}
static int bcm_acpi_probe(struct bcm_device *dev)
{
struct platform_device *pdev = dev->pdev;
const struct acpi_device_id *id;
struct acpi_device *adev;
LIST_HEAD(resources);
int ret;
id = acpi_match_device(pdev->dev.driver->acpi_match_table, &pdev->dev);
if (!id)
return -ENODEV;
dev->name = dev_name(&pdev->dev);
ret = acpi_dev_add_driver_gpios(ACPI_COMPANION(&pdev->dev),
acpi_bcm_default_gpios);
if (ret)
return ret;
dev->clk = devm_clk_get(&pdev->dev, NULL);
dev->device_wakeup = devm_gpiod_get_optional(&pdev->dev,
"device-wakeup",
GPIOD_OUT_LOW);
if (IS_ERR(dev->device_wakeup))
return PTR_ERR(dev->device_wakeup);
dev->shutdown = devm_gpiod_get_optional(&pdev->dev, "shutdown",
GPIOD_OUT_LOW);
if (IS_ERR(dev->shutdown))
return PTR_ERR(dev->shutdown);
if ((!dev->device_wakeup && !dev->shutdown) || !dev->name) {
dev_err(&pdev->dev, "invalid platform data\n");
return -EINVAL;
}
adev = ACPI_COMPANION(&dev->pdev->dev);
if (!adev)
return 0;
acpi_dev_get_resources(adev, &resources, bcm_resource, dev);
return 0;
}
static int bcm_acpi_probe(struct bcm_device *dev)
{
return -EINVAL;
}
static int bcm_probe(struct platform_device *pdev)
{
struct bcm_device *dev;
struct acpi_device_id *pdata = pdev->dev.platform_data;
int ret;
dev = devm_kzalloc(&pdev->dev, sizeof(*dev), GFP_KERNEL);
if (!dev)
return -ENOMEM;
dev->pdev = pdev;
if (ACPI_HANDLE(&pdev->dev)) {
ret = bcm_acpi_probe(dev);
if (ret)
return ret;
} else if (pdata) {
dev->name = pdata->id;
} else {
return -ENODEV;
}
platform_set_drvdata(pdev, dev);
dev_info(&pdev->dev, "%s device registered.\n", dev->name);
spin_lock(&bcm_device_lock);
list_add_tail(&dev->list, &bcm_device_list);
spin_unlock(&bcm_device_lock);
bcm_gpio_set_power(dev, false);
return 0;
}
static int bcm_remove(struct platform_device *pdev)
{
struct bcm_device *dev = platform_get_drvdata(pdev);
spin_lock(&bcm_device_lock);
list_del(&dev->list);
spin_unlock(&bcm_device_lock);
acpi_dev_remove_driver_gpios(ACPI_COMPANION(&pdev->dev));
dev_info(&pdev->dev, "%s device unregistered.\n", dev->name);
return 0;
}
int __init bcm_init(void)
{
platform_driver_register(&bcm_driver);
return hci_uart_register_proto(&bcm_proto);
}
int __exit bcm_deinit(void)
{
platform_driver_unregister(&bcm_driver);
return hci_uart_unregister_proto(&bcm_proto);
}
