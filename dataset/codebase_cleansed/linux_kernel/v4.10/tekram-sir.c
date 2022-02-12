static int __init tekram_sir_init(void)
{
if (tekram_delay < 1 || tekram_delay > 500)
tekram_delay = 200;
pr_debug("%s - using %d ms delay\n",
tekram.driver_name, tekram_delay);
return irda_register_dongle(&tekram);
}
static void __exit tekram_sir_cleanup(void)
{
irda_unregister_dongle(&tekram);
}
static int tekram_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
sirdev_set_dtr_rts(dev, TRUE, TRUE);
qos->baud_rate.bits &= IR_9600|IR_19200|IR_38400|IR_57600|IR_115200;
qos->min_turn_time.bits = 0x01;
irda_qos_bits_to_value(qos);
return 0;
}
static int tekram_close(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, FALSE);
return 0;
}
static int tekram_change_speed(struct sir_dev *dev, unsigned speed)
{
unsigned state = dev->fsm.substate;
unsigned delay = 0;
u8 byte;
static int ret = 0;
switch(state) {
case SIRDEV_STATE_DONGLE_SPEED:
switch (speed) {
default:
speed = 9600;
ret = -EINVAL;
case 9600:
byte = TEKRAM_PW|TEKRAM_9600;
break;
case 19200:
byte = TEKRAM_PW|TEKRAM_19200;
break;
case 38400:
byte = TEKRAM_PW|TEKRAM_38400;
break;
case 57600:
byte = TEKRAM_PW|TEKRAM_57600;
break;
case 115200:
byte = TEKRAM_115200;
break;
}
sirdev_set_dtr_rts(dev, TRUE, FALSE);
udelay(14);
sirdev_raw_write(dev, &byte, 1);
dev->speed = speed;
state = TEKRAM_STATE_WAIT_SPEED;
delay = tekram_delay;
break;
case TEKRAM_STATE_WAIT_SPEED:
sirdev_set_dtr_rts(dev, TRUE, TRUE);
udelay(50);
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
static int tekram_reset(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, TRUE);
msleep(1);
sirdev_set_dtr_rts(dev, TRUE, TRUE);
udelay(75);
dev->speed = 9600;
return 0;
}
