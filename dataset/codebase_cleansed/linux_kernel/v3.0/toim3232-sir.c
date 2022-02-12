static int __init toim3232_sir_init(void)
{
if (toim3232delay < 1 || toim3232delay > 500)
toim3232delay = 200;
IRDA_DEBUG(1, "%s - using %d ms delay\n",
toim3232.driver_name, toim3232delay);
return irda_register_dongle(&toim3232);
}
static void __exit toim3232_sir_cleanup(void)
{
irda_unregister_dongle(&toim3232);
}
static int toim3232_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
IRDA_DEBUG(2, "%s()\n", __func__);
sirdev_set_dtr_rts(dev, TRUE, TRUE);
qos->baud_rate.bits &= IR_2400|IR_9600|IR_19200|IR_38400|IR_57600|IR_115200;
qos->min_turn_time.bits = 0x01;
irda_qos_bits_to_value(qos);
return 0;
}
static int toim3232_close(struct sir_dev *dev)
{
IRDA_DEBUG(2, "%s()\n", __func__);
sirdev_set_dtr_rts(dev, FALSE, FALSE);
return 0;
}
static int toim3232_change_speed(struct sir_dev *dev, unsigned speed)
{
unsigned state = dev->fsm.substate;
unsigned delay = 0;
u8 byte;
static int ret = 0;
IRDA_DEBUG(2, "%s()\n", __func__);
switch(state) {
case SIRDEV_STATE_DONGLE_SPEED:
switch (speed) {
case 2400:
byte = TOIM3232_PW|TOIM3232_2400;
break;
default:
speed = 9600;
ret = -EINVAL;
case 9600:
byte = TOIM3232_PW|TOIM3232_9600;
break;
case 19200:
byte = TOIM3232_PW|TOIM3232_19200;
break;
case 38400:
byte = TOIM3232_PW|TOIM3232_38400;
break;
case 57600:
byte = TOIM3232_PW|TOIM3232_57600;
break;
case 115200:
byte = TOIM3232_115200;
break;
}
sirdev_set_dtr_rts(dev, TRUE, FALSE);
udelay(14);
sirdev_raw_write(dev, &byte, 1);
dev->speed = speed;
state = TOIM3232_STATE_WAIT_SPEED;
delay = toim3232delay;
break;
case TOIM3232_STATE_WAIT_SPEED:
udelay(14);
sirdev_set_dtr_rts(dev, TRUE, TRUE);
udelay(50);
break;
default:
printk(KERN_ERR "%s - undefined state %d\n", __func__, state);
ret = -EINVAL;
break;
}
dev->fsm.substate = state;
return (delay > 0) ? delay : ret;
}
static int toim3232_reset(struct sir_dev *dev)
{
IRDA_DEBUG(2, "%s()\n", __func__);
sirdev_set_dtr_rts(dev, FALSE, FALSE);
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(msecs_to_jiffies(50));
sirdev_set_dtr_rts(dev, TRUE, TRUE);
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(msecs_to_jiffies(10));
dev->speed = 9600;
return 0;
}
