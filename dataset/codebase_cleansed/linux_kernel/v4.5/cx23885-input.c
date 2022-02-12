static void cx23885_input_process_measurements(struct cx23885_dev *dev,
bool overrun)
{
struct cx23885_kernel_ir *kernel_ir = dev->kernel_ir;
ssize_t num;
int count, i;
bool handle = false;
struct ir_raw_event ir_core_event[64];
do {
num = 0;
v4l2_subdev_call(dev->sd_ir, ir, rx_read, (u8 *) ir_core_event,
sizeof(ir_core_event), &num);
count = num / sizeof(struct ir_raw_event);
for (i = 0; i < count; i++) {
ir_raw_event_store(kernel_ir->rc,
&ir_core_event[i]);
handle = true;
}
} while (num != 0);
if (overrun)
ir_raw_event_reset(kernel_ir->rc);
else if (handle)
ir_raw_event_handle(kernel_ir->rc);
}
void cx23885_input_rx_work_handler(struct cx23885_dev *dev, u32 events)
{
struct v4l2_subdev_ir_parameters params;
int overrun, data_available;
if (dev->sd_ir == NULL || events == 0)
return;
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
case CX23885_BOARD_TEVII_S470:
case CX23885_BOARD_HAUPPAUGE_HVR1250:
case CX23885_BOARD_MYGICA_X8507:
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_TT_CT2_4500_CI:
case CX23885_BOARD_DVBSKY_S950:
case CX23885_BOARD_DVBSKY_S952:
case CX23885_BOARD_DVBSKY_T982:
break;
default:
return;
}
overrun = events & (V4L2_SUBDEV_IR_RX_SW_FIFO_OVERRUN |
V4L2_SUBDEV_IR_RX_HW_FIFO_OVERRUN);
data_available = events & (V4L2_SUBDEV_IR_RX_END_OF_RX_DETECTED |
V4L2_SUBDEV_IR_RX_FIFO_SERVICE_REQ);
if (overrun) {
v4l2_subdev_call(dev->sd_ir, ir, rx_g_parameters, &params);
params.enable = false;
params.shutdown = atomic_read(&dev->ir_input_stopping);
v4l2_subdev_call(dev->sd_ir, ir, rx_s_parameters, &params);
}
if (data_available)
cx23885_input_process_measurements(dev, overrun);
if (overrun) {
params.enable = true;
params.shutdown = atomic_read(&dev->ir_input_stopping);
v4l2_subdev_call(dev->sd_ir, ir, rx_s_parameters, &params);
}
}
static int cx23885_input_ir_start(struct cx23885_dev *dev)
{
struct v4l2_subdev_ir_parameters params;
if (dev->sd_ir == NULL)
return -ENODEV;
atomic_set(&dev->ir_input_stopping, 0);
v4l2_subdev_call(dev->sd_ir, ir, rx_g_parameters, &params);
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
case CX23885_BOARD_HAUPPAUGE_HVR1250:
case CX23885_BOARD_MYGICA_X8507:
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_TT_CT2_4500_CI:
case CX23885_BOARD_DVBSKY_S950:
case CX23885_BOARD_DVBSKY_S952:
case CX23885_BOARD_DVBSKY_T982:
params.mode = V4L2_SUBDEV_IR_MODE_PULSE_WIDTH;
params.enable = true;
params.interrupt_enable = true;
params.shutdown = false;
params.modulation = false;
params.max_pulse_width = 3333333;
params.noise_filter_min_width = 333333;
params.invert_level = true;
break;
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
case CX23885_BOARD_TEVII_S470:
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
params.mode = V4L2_SUBDEV_IR_MODE_PULSE_WIDTH;
params.enable = true;
params.interrupt_enable = true;
params.shutdown = false;
params.carrier_freq = 37917;
params.carrier_range_lower = 33000;
params.carrier_range_upper = 43000;
params.duty_cycle = 33;
params.max_pulse_width = 12378022;
params.noise_filter_min_width = 351648;
params.modulation = false;
params.invert_level = true;
break;
}
v4l2_subdev_call(dev->sd_ir, ir, rx_s_parameters, &params);
return 0;
}
static int cx23885_input_ir_open(struct rc_dev *rc)
{
struct cx23885_kernel_ir *kernel_ir = rc->priv;
if (kernel_ir->cx == NULL)
return -ENODEV;
return cx23885_input_ir_start(kernel_ir->cx);
}
static void cx23885_input_ir_stop(struct cx23885_dev *dev)
{
struct v4l2_subdev_ir_parameters params;
if (dev->sd_ir == NULL)
return;
atomic_set(&dev->ir_input_stopping, 1);
v4l2_subdev_call(dev->sd_ir, ir, rx_g_parameters, &params);
while (params.shutdown == false) {
params.enable = false;
params.interrupt_enable = false;
params.shutdown = true;
v4l2_subdev_call(dev->sd_ir, ir, rx_s_parameters, &params);
v4l2_subdev_call(dev->sd_ir, ir, rx_g_parameters, &params);
}
flush_work(&dev->cx25840_work);
flush_work(&dev->ir_rx_work);
flush_work(&dev->ir_tx_work);
}
static void cx23885_input_ir_close(struct rc_dev *rc)
{
struct cx23885_kernel_ir *kernel_ir = rc->priv;
if (kernel_ir->cx != NULL)
cx23885_input_ir_stop(kernel_ir->cx);
}
int cx23885_input_init(struct cx23885_dev *dev)
{
struct cx23885_kernel_ir *kernel_ir;
struct rc_dev *rc;
char *rc_map;
enum rc_driver_type driver_type;
u64 allowed_protos;
int ret;
if (dev->sd_ir == NULL)
return -ENODEV;
switch (dev->board) {
case CX23885_BOARD_HAUPPAUGE_HVR1270:
case CX23885_BOARD_HAUPPAUGE_HVR1850:
case CX23885_BOARD_HAUPPAUGE_HVR1290:
case CX23885_BOARD_HAUPPAUGE_HVR1250:
driver_type = RC_DRIVER_IR_RAW;
allowed_protos = RC_BIT_ALL;
rc_map = RC_MAP_HAUPPAUGE;
break;
case CX23885_BOARD_TERRATEC_CINERGY_T_PCIE_DUAL:
driver_type = RC_DRIVER_IR_RAW;
allowed_protos = RC_BIT_NEC;
rc_map = RC_MAP_NEC_TERRATEC_CINERGY_XS;
break;
case CX23885_BOARD_TEVII_S470:
driver_type = RC_DRIVER_IR_RAW;
allowed_protos = RC_BIT_ALL;
rc_map = RC_MAP_TEVII_NEC;
break;
case CX23885_BOARD_MYGICA_X8507:
driver_type = RC_DRIVER_IR_RAW;
allowed_protos = RC_BIT_ALL;
rc_map = RC_MAP_TOTAL_MEDIA_IN_HAND_02;
break;
case CX23885_BOARD_TBS_6980:
case CX23885_BOARD_TBS_6981:
driver_type = RC_DRIVER_IR_RAW;
allowed_protos = RC_BIT_ALL;
rc_map = RC_MAP_TBS_NEC;
break;
case CX23885_BOARD_DVBSKY_T9580:
case CX23885_BOARD_DVBSKY_T980C:
case CX23885_BOARD_DVBSKY_S950C:
case CX23885_BOARD_DVBSKY_S950:
case CX23885_BOARD_DVBSKY_S952:
case CX23885_BOARD_DVBSKY_T982:
driver_type = RC_DRIVER_IR_RAW;
allowed_protos = RC_BIT_ALL;
rc_map = RC_MAP_DVBSKY;
break;
case CX23885_BOARD_TT_CT2_4500_CI:
driver_type = RC_DRIVER_IR_RAW;
allowed_protos = RC_BIT_ALL;
rc_map = RC_MAP_TT_1500;
break;
default:
return -ENODEV;
}
kernel_ir = kzalloc(sizeof(struct cx23885_kernel_ir), GFP_KERNEL);
if (kernel_ir == NULL)
return -ENOMEM;
kernel_ir->cx = dev;
kernel_ir->name = kasprintf(GFP_KERNEL, "cx23885 IR (%s)",
cx23885_boards[dev->board].name);
kernel_ir->phys = kasprintf(GFP_KERNEL, "pci-%s/ir0",
pci_name(dev->pci));
rc = rc_allocate_device();
if (!rc) {
ret = -ENOMEM;
goto err_out_free;
}
kernel_ir->rc = rc;
rc->input_name = kernel_ir->name;
rc->input_phys = kernel_ir->phys;
rc->input_id.bustype = BUS_PCI;
rc->input_id.version = 1;
if (dev->pci->subsystem_vendor) {
rc->input_id.vendor = dev->pci->subsystem_vendor;
rc->input_id.product = dev->pci->subsystem_device;
} else {
rc->input_id.vendor = dev->pci->vendor;
rc->input_id.product = dev->pci->device;
}
rc->dev.parent = &dev->pci->dev;
rc->driver_type = driver_type;
rc->allowed_protocols = allowed_protos;
rc->priv = kernel_ir;
rc->open = cx23885_input_ir_open;
rc->close = cx23885_input_ir_close;
rc->map_name = rc_map;
rc->driver_name = MODULE_NAME;
dev->kernel_ir = kernel_ir;
ret = rc_register_device(rc);
if (ret)
goto err_out_stop;
return 0;
err_out_stop:
cx23885_input_ir_stop(dev);
dev->kernel_ir = NULL;
rc_free_device(rc);
err_out_free:
kfree(kernel_ir->phys);
kfree(kernel_ir->name);
kfree(kernel_ir);
return ret;
}
void cx23885_input_fini(struct cx23885_dev *dev)
{
cx23885_input_ir_stop(dev);
if (dev->kernel_ir == NULL)
return;
rc_unregister_device(dev->kernel_ir->rc);
kfree(dev->kernel_ir->phys);
kfree(dev->kernel_ir->name);
kfree(dev->kernel_ir);
dev->kernel_ir = NULL;
}
