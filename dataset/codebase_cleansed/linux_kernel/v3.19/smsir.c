void sms_ir_event(struct smscore_device_t *coredev, const char *buf, int len)
{
int i;
const s32 *samples = (const void *)buf;
for (i = 0; i < len >> 2; i++) {
DEFINE_IR_RAW_EVENT(ev);
ev.duration = abs(samples[i]) * 1000;
ev.pulse = (samples[i] > 0) ? false : true;
ir_raw_event_store(coredev->ir.dev, &ev);
}
ir_raw_event_handle(coredev->ir.dev);
}
int sms_ir_init(struct smscore_device_t *coredev)
{
int err;
int board_id = smscore_get_board_id(coredev);
struct rc_dev *dev;
sms_log("Allocating rc device");
dev = rc_allocate_device();
if (!dev) {
sms_err("Not enough memory");
return -ENOMEM;
}
coredev->ir.controller = 0;
coredev->ir.timeout = IR_DEFAULT_TIMEOUT;
sms_log("IR port %d, timeout %d ms",
coredev->ir.controller, coredev->ir.timeout);
snprintf(coredev->ir.name, sizeof(coredev->ir.name),
"SMS IR (%s)", sms_get_board(board_id)->name);
strlcpy(coredev->ir.phys, coredev->devpath, sizeof(coredev->ir.phys));
strlcat(coredev->ir.phys, "/ir0", sizeof(coredev->ir.phys));
dev->input_name = coredev->ir.name;
dev->input_phys = coredev->ir.phys;
dev->dev.parent = coredev->device;
#if 0
dev->input_id.bustype = BUS_USB;
dev->input_id.version = 1;
dev->input_id.vendor = le16_to_cpu(dev->udev->descriptor.idVendor);
dev->input_id.product = le16_to_cpu(dev->udev->descriptor.idProduct);
#endif
dev->priv = coredev;
dev->driver_type = RC_DRIVER_IR_RAW;
dev->allowed_protocols = RC_BIT_ALL;
dev->map_name = sms_get_board(board_id)->rc_codes;
dev->driver_name = MODULE_NAME;
sms_log("Input device (IR) %s is set for key events", dev->input_name);
err = rc_register_device(dev);
if (err < 0) {
sms_err("Failed to register device");
rc_free_device(dev);
return err;
}
coredev->ir.dev = dev;
return 0;
}
void sms_ir_exit(struct smscore_device_t *coredev)
{
rc_unregister_device(coredev->ir.dev);
sms_log("");
}
