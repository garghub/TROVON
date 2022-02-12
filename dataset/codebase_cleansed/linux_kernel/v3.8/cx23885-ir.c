void cx23885_ir_rx_work_handler(struct work_struct *work)
{
struct cx23885_dev *dev =
container_of(work, struct cx23885_dev, ir_rx_work);
u32 events = 0;
unsigned long *notifications = &dev->ir_rx_notifications;
if (test_and_clear_bit(CX23885_IR_RX_SW_FIFO_OVERRUN, notifications))
events |= V4L2_SUBDEV_IR_RX_SW_FIFO_OVERRUN;
if (test_and_clear_bit(CX23885_IR_RX_HW_FIFO_OVERRUN, notifications))
events |= V4L2_SUBDEV_IR_RX_HW_FIFO_OVERRUN;
if (test_and_clear_bit(CX23885_IR_RX_END_OF_RX_DETECTED, notifications))
events |= V4L2_SUBDEV_IR_RX_END_OF_RX_DETECTED;
if (test_and_clear_bit(CX23885_IR_RX_FIFO_SERVICE_REQ, notifications))
events |= V4L2_SUBDEV_IR_RX_FIFO_SERVICE_REQ;
if (events == 0)
return;
if (dev->kernel_ir)
cx23885_input_rx_work_handler(dev, events);
}
void cx23885_ir_tx_work_handler(struct work_struct *work)
{
struct cx23885_dev *dev =
container_of(work, struct cx23885_dev, ir_tx_work);
u32 events = 0;
unsigned long *notifications = &dev->ir_tx_notifications;
if (test_and_clear_bit(CX23885_IR_TX_FIFO_SERVICE_REQ, notifications))
events |= V4L2_SUBDEV_IR_TX_FIFO_SERVICE_REQ;
if (events == 0)
return;
}
void cx23885_ir_rx_v4l2_dev_notify(struct v4l2_subdev *sd, u32 events)
{
struct cx23885_dev *dev = to_cx23885(sd->v4l2_dev);
unsigned long *notifications = &dev->ir_rx_notifications;
if (events & V4L2_SUBDEV_IR_RX_FIFO_SERVICE_REQ)
set_bit(CX23885_IR_RX_FIFO_SERVICE_REQ, notifications);
if (events & V4L2_SUBDEV_IR_RX_END_OF_RX_DETECTED)
set_bit(CX23885_IR_RX_END_OF_RX_DETECTED, notifications);
if (events & V4L2_SUBDEV_IR_RX_HW_FIFO_OVERRUN)
set_bit(CX23885_IR_RX_HW_FIFO_OVERRUN, notifications);
if (events & V4L2_SUBDEV_IR_RX_SW_FIFO_OVERRUN)
set_bit(CX23885_IR_RX_SW_FIFO_OVERRUN, notifications);
if (sd == dev->sd_cx25840)
cx23885_ir_rx_work_handler(&dev->ir_rx_work);
else
schedule_work(&dev->ir_rx_work);
}
void cx23885_ir_tx_v4l2_dev_notify(struct v4l2_subdev *sd, u32 events)
{
struct cx23885_dev *dev = to_cx23885(sd->v4l2_dev);
unsigned long *notifications = &dev->ir_tx_notifications;
if (events & V4L2_SUBDEV_IR_TX_FIFO_SERVICE_REQ)
set_bit(CX23885_IR_TX_FIFO_SERVICE_REQ, notifications);
if (sd == dev->sd_cx25840)
cx23885_ir_tx_work_handler(&dev->ir_tx_work);
else
schedule_work(&dev->ir_tx_work);
}
