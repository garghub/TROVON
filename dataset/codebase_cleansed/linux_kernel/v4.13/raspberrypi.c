static void response_callback(struct mbox_client *cl, void *msg)
{
struct rpi_firmware *fw = container_of(cl, struct rpi_firmware, cl);
complete(&fw->c);
}
static int
rpi_firmware_transaction(struct rpi_firmware *fw, u32 chan, u32 data)
{
u32 message = MBOX_MSG(chan, data);
int ret;
WARN_ON(data & 0xf);
mutex_lock(&transaction_lock);
reinit_completion(&fw->c);
ret = mbox_send_message(fw->chan, &message);
if (ret >= 0) {
wait_for_completion(&fw->c);
ret = 0;
} else {
dev_err(fw->cl.dev, "mbox_send_message returned %d\n", ret);
}
mutex_unlock(&transaction_lock);
return ret;
}
int rpi_firmware_property_list(struct rpi_firmware *fw,
void *data, size_t tag_size)
{
size_t size = tag_size + 12;
u32 *buf;
dma_addr_t bus_addr;
int ret;
if (size & 3)
return -EINVAL;
buf = dma_alloc_coherent(fw->cl.dev, PAGE_ALIGN(size), &bus_addr,
GFP_ATOMIC);
if (!buf)
return -ENOMEM;
WARN_ON(size >= 1024 * 1024);
buf[0] = size;
buf[1] = RPI_FIRMWARE_STATUS_REQUEST;
memcpy(&buf[2], data, tag_size);
buf[size / 4 - 1] = RPI_FIRMWARE_PROPERTY_END;
wmb();
ret = rpi_firmware_transaction(fw, MBOX_CHAN_PROPERTY, bus_addr);
rmb();
memcpy(data, &buf[2], tag_size);
if (ret == 0 && buf[1] != RPI_FIRMWARE_STATUS_SUCCESS) {
dev_err(fw->cl.dev, "Request 0x%08x returned status 0x%08x\n",
buf[2], buf[1]);
ret = -EINVAL;
}
dma_free_coherent(fw->cl.dev, PAGE_ALIGN(size), buf, bus_addr);
return ret;
}
int rpi_firmware_property(struct rpi_firmware *fw,
u32 tag, void *tag_data, size_t buf_size)
{
u8 data[buf_size + sizeof(struct rpi_firmware_property_tag_header)];
struct rpi_firmware_property_tag_header *header =
(struct rpi_firmware_property_tag_header *)data;
int ret;
header->tag = tag;
header->buf_size = buf_size;
header->req_resp_size = 0;
memcpy(data + sizeof(struct rpi_firmware_property_tag_header),
tag_data, buf_size);
ret = rpi_firmware_property_list(fw, &data, sizeof(data));
memcpy(tag_data,
data + sizeof(struct rpi_firmware_property_tag_header),
buf_size);
return ret;
}
static void
rpi_firmware_print_firmware_revision(struct rpi_firmware *fw)
{
u32 packet;
int ret = rpi_firmware_property(fw,
RPI_FIRMWARE_GET_FIRMWARE_REVISION,
&packet, sizeof(packet));
if (ret == 0) {
struct tm tm;
time_to_tm(packet, 0, &tm);
dev_info(fw->cl.dev,
"Attached to firmware from %04ld-%02d-%02d %02d:%02d\n",
tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
tm.tm_hour, tm.tm_min);
}
}
static int rpi_firmware_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rpi_firmware *fw;
fw = devm_kzalloc(dev, sizeof(*fw), GFP_KERNEL);
if (!fw)
return -ENOMEM;
fw->cl.dev = dev;
fw->cl.rx_callback = response_callback;
fw->cl.tx_block = true;
fw->chan = mbox_request_channel(&fw->cl, 0);
if (IS_ERR(fw->chan)) {
int ret = PTR_ERR(fw->chan);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Failed to get mbox channel: %d\n", ret);
return ret;
}
init_completion(&fw->c);
platform_set_drvdata(pdev, fw);
rpi_firmware_print_firmware_revision(fw);
return 0;
}
static int rpi_firmware_remove(struct platform_device *pdev)
{
struct rpi_firmware *fw = platform_get_drvdata(pdev);
mbox_free_channel(fw->chan);
return 0;
}
struct rpi_firmware *rpi_firmware_get(struct device_node *firmware_node)
{
struct platform_device *pdev = of_find_device_by_node(firmware_node);
if (!pdev)
return NULL;
return platform_get_drvdata(pdev);
}
