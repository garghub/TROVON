static int __init girbil_sir_init(void)
{
return irda_register_dongle(&girbil);
}
static void __exit girbil_sir_cleanup(void)
{
irda_unregister_dongle(&girbil);
}
static int girbil_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
sirdev_set_dtr_rts(dev, TRUE, TRUE);
qos->baud_rate.bits &= IR_9600|IR_19200|IR_38400|IR_57600|IR_115200;
qos->min_turn_time.bits = 0x03;
irda_qos_bits_to_value(qos);
return 0;
}
static int girbil_close(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, FALSE);
return 0;
}
static int girbil_change_speed(struct sir_dev *dev, unsigned speed)
{
unsigned state = dev->fsm.substate;
unsigned delay = 0;
u8 control[2];
static int ret = 0;
switch(state) {
case SIRDEV_STATE_DONGLE_SPEED:
sirdev_set_dtr_rts(dev, FALSE, TRUE);
udelay(25);
ret = 0;
switch (speed) {
default:
ret = -EINVAL;
case 9600:
control[0] = GIRBIL_9600;
break;
case 19200:
control[0] = GIRBIL_19200;
break;
case 34800:
control[0] = GIRBIL_38400;
break;
case 57600:
control[0] = GIRBIL_57600;
break;
case 115200:
control[0] = GIRBIL_115200;
break;
}
control[1] = GIRBIL_LOAD;
sirdev_raw_write(dev, control, 2);
dev->speed = speed;
state = GIRBIL_STATE_WAIT_SPEED;
delay = 100;
break;
case GIRBIL_STATE_WAIT_SPEED:
sirdev_set_dtr_rts(dev, TRUE, TRUE);
udelay(25);
break;
default:
net_err_ratelimited("%s - undefined state %d\n",
__func__, state);
ret = -EINVAL;
break;
}
dev->fsm.substate = state;
return (delay > 0) ? delay : ret;
}
static int girbil_reset(struct sir_dev *dev)
{
unsigned state = dev->fsm.substate;
unsigned delay = 0;
u8 control = GIRBIL_TXEN | GIRBIL_RXEN;
int ret = 0;
switch (state) {
case SIRDEV_STATE_DONGLE_RESET:
sirdev_set_dtr_rts(dev, TRUE, FALSE);
delay = 20;
state = GIRBIL_STATE_WAIT1_RESET;
break;
case GIRBIL_STATE_WAIT1_RESET:
sirdev_set_dtr_rts(dev, FALSE, TRUE);
delay = 20;
state = GIRBIL_STATE_WAIT2_RESET;
break;
case GIRBIL_STATE_WAIT2_RESET:
sirdev_raw_write(dev, &control, 1);
delay = 20;
state = GIRBIL_STATE_WAIT3_RESET;
break;
case GIRBIL_STATE_WAIT3_RESET:
sirdev_set_dtr_rts(dev, TRUE, TRUE);
dev->speed = 9600;
break;
default:
net_err_ratelimited("%s(), undefined state %d\n",
__func__, state);
ret = -1;
break;
}
dev->fsm.substate = state;
return (delay > 0) ? delay : ret;
}
