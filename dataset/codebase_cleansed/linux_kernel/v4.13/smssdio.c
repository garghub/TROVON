static int smssdio_sendrequest(void *context, void *buffer, size_t size)
{
int ret = 0;
struct smssdio_device *smsdev;
smsdev = context;
sdio_claim_host(smsdev->func);
smsendian_handle_tx_message((struct sms_msg_data *) buffer);
while (size >= smsdev->func->cur_blksize) {
ret = sdio_memcpy_toio(smsdev->func, SMSSDIO_DATA,
buffer, smsdev->func->cur_blksize);
if (ret)
goto out;
buffer += smsdev->func->cur_blksize;
size -= smsdev->func->cur_blksize;
}
if (size) {
ret = sdio_memcpy_toio(smsdev->func, SMSSDIO_DATA,
buffer, size);
}
out:
sdio_release_host(smsdev->func);
return ret;
}
static void smssdio_interrupt(struct sdio_func *func)
{
int ret;
struct smssdio_device *smsdev;
struct smscore_buffer_t *cb;
struct sms_msg_hdr *hdr;
size_t size;
smsdev = sdio_get_drvdata(func);
(void)sdio_readb(func, SMSSDIO_INT, &ret);
if (ret) {
pr_err("Unable to read interrupt register!\n");
return;
}
if (smsdev->split_cb == NULL) {
cb = smscore_getbuffer(smsdev->coredev);
if (!cb) {
pr_err("Unable to allocate data buffer!\n");
return;
}
ret = sdio_memcpy_fromio(smsdev->func,
cb->p,
SMSSDIO_DATA,
SMSSDIO_BLOCK_SIZE);
if (ret) {
pr_err("Error %d reading initial block!\n", ret);
return;
}
hdr = cb->p;
if (hdr->msg_flags & MSG_HDR_FLAG_SPLIT_MSG) {
smsdev->split_cb = cb;
return;
}
if (hdr->msg_length > smsdev->func->cur_blksize)
size = hdr->msg_length - smsdev->func->cur_blksize;
else
size = 0;
} else {
cb = smsdev->split_cb;
hdr = cb->p;
size = hdr->msg_length - sizeof(struct sms_msg_hdr);
smsdev->split_cb = NULL;
}
if (size) {
void *buffer;
buffer = cb->p + (hdr->msg_length - size);
size = ALIGN(size, SMSSDIO_BLOCK_SIZE);
BUG_ON(smsdev->func->cur_blksize != SMSSDIO_BLOCK_SIZE);
ret = sdio_memcpy_fromio(smsdev->func,
buffer,
SMSSDIO_DATA,
size);
if (ret && ret != -EINVAL) {
smscore_putbuffer(smsdev->coredev, cb);
pr_err("Error %d reading data from card!\n", ret);
return;
}
if (ret == -EINVAL) {
while (size) {
ret = sdio_memcpy_fromio(smsdev->func,
buffer, SMSSDIO_DATA,
smsdev->func->cur_blksize);
if (ret) {
smscore_putbuffer(smsdev->coredev, cb);
pr_err("Error %d reading data from card!\n",
ret);
return;
}
buffer += smsdev->func->cur_blksize;
if (size > smsdev->func->cur_blksize)
size -= smsdev->func->cur_blksize;
else
size = 0;
}
}
}
cb->size = hdr->msg_length;
cb->offset = 0;
smsendian_handle_rx_message((struct sms_msg_data *) cb->p);
smscore_onresponse(smsdev->coredev, cb);
}
static int smssdio_probe(struct sdio_func *func,
const struct sdio_device_id *id)
{
int ret;
int board_id;
struct smssdio_device *smsdev;
struct smsdevice_params_t params;
board_id = id->driver_data;
smsdev = kzalloc(sizeof(struct smssdio_device), GFP_KERNEL);
if (!smsdev)
return -ENOMEM;
smsdev->func = func;
memset(&params, 0, sizeof(struct smsdevice_params_t));
params.device = &func->dev;
params.buffer_size = 0x5000;
params.num_buffers = 22;
params.context = smsdev;
snprintf(params.devpath, sizeof(params.devpath),
"sdio\\%s", sdio_func_id(func));
params.sendrequest_handler = smssdio_sendrequest;
params.device_type = sms_get_board(board_id)->type;
if (params.device_type != SMS_STELLAR)
params.flags |= SMS_DEVICE_FAMILY2;
else {
ret = -ENODEV;
goto free;
}
ret = smscore_register_device(&params, &smsdev->coredev, NULL);
if (ret < 0)
goto free;
smscore_set_board_id(smsdev->coredev, board_id);
sdio_claim_host(func);
ret = sdio_enable_func(func);
if (ret)
goto release;
ret = sdio_set_block_size(func, SMSSDIO_BLOCK_SIZE);
if (ret)
goto disable;
ret = sdio_claim_irq(func, smssdio_interrupt);
if (ret)
goto disable;
sdio_set_drvdata(func, smsdev);
sdio_release_host(func);
ret = smscore_start_device(smsdev->coredev);
if (ret < 0)
goto reclaim;
return 0;
reclaim:
sdio_claim_host(func);
sdio_release_irq(func);
disable:
sdio_disable_func(func);
release:
sdio_release_host(func);
smscore_unregister_device(smsdev->coredev);
free:
kfree(smsdev);
return ret;
}
static void smssdio_remove(struct sdio_func *func)
{
struct smssdio_device *smsdev;
smsdev = sdio_get_drvdata(func);
if (smsdev->split_cb)
smscore_putbuffer(smsdev->coredev, smsdev->split_cb);
smscore_unregister_device(smsdev->coredev);
sdio_claim_host(func);
sdio_release_irq(func);
sdio_disable_func(func);
sdio_release_host(func);
kfree(smsdev);
}
static int __init smssdio_module_init(void)
{
int ret = 0;
printk(KERN_INFO "smssdio: Siano SMS1xxx SDIO driver\n");
printk(KERN_INFO "smssdio: Copyright Pierre Ossman\n");
ret = sdio_register_driver(&smssdio_driver);
return ret;
}
static void __exit smssdio_module_exit(void)
{
sdio_unregister_driver(&smssdio_driver);
}
