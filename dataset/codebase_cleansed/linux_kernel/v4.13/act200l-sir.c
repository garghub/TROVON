static int __init act200l_sir_init(void)
{
return irda_register_dongle(&act200l);
}
static void __exit act200l_sir_cleanup(void)
{
irda_unregister_dongle(&act200l);
}
static int act200l_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
sirdev_set_dtr_rts(dev, TRUE, TRUE);
qos->baud_rate.bits &= IR_9600|IR_19200|IR_38400|IR_57600|IR_115200;
qos->min_turn_time.bits = 0x03;
irda_qos_bits_to_value(qos);
return 0;
}
static int act200l_close(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, FALSE);
return 0;
}
static int act200l_change_speed(struct sir_dev *dev, unsigned speed)
{
u8 control[3];
int ret = 0;
sirdev_set_dtr_rts(dev, FALSE, TRUE);
switch (speed) {
default:
ret = -EINVAL;
case 9600:
control[0] = ACT200L_REG8 | (ACT200L_9600 & 0x0f);
control[1] = ACT200L_REG9 | ((ACT200L_9600 >> 4) & 0x0f);
break;
case 19200:
control[0] = ACT200L_REG8 | (ACT200L_19200 & 0x0f);
control[1] = ACT200L_REG9 | ((ACT200L_19200 >> 4) & 0x0f);
break;
case 38400:
control[0] = ACT200L_REG8 | (ACT200L_38400 & 0x0f);
control[1] = ACT200L_REG9 | ((ACT200L_38400 >> 4) & 0x0f);
break;
case 57600:
control[0] = ACT200L_REG8 | (ACT200L_57600 & 0x0f);
control[1] = ACT200L_REG9 | ((ACT200L_57600 >> 4) & 0x0f);
break;
case 115200:
control[0] = ACT200L_REG8 | (ACT200L_115200 & 0x0f);
control[1] = ACT200L_REG9 | ((ACT200L_115200 >> 4) & 0x0f);
break;
}
control[2] = ACT200L_REG1 | ACT200L_LODB | ACT200L_WIDE;
sirdev_raw_write(dev, control, 3);
msleep(5);
sirdev_set_dtr_rts(dev, TRUE, TRUE);
dev->speed = speed;
return ret;
}
static int act200l_reset(struct sir_dev *dev)
{
unsigned state = dev->fsm.substate;
unsigned delay = 0;
static const u8 control[9] = {
ACT200L_REG15,
ACT200L_REG13 | ACT200L_SHDW,
ACT200L_REG21 | ACT200L_EXCK | ACT200L_OSCL,
ACT200L_REG13,
ACT200L_REG7 | ACT200L_ENPOS,
ACT200L_REG6 | ACT200L_RS0 | ACT200L_RS1,
ACT200L_REG5 | ACT200L_RWIDL,
ACT200L_REG4 | ACT200L_OP0 | ACT200L_OP1 | ACT200L_BLKR,
ACT200L_REG0 | ACT200L_TXEN | ACT200L_RXEN
};
int ret = 0;
switch (state) {
case SIRDEV_STATE_DONGLE_RESET:
sirdev_set_dtr_rts(dev, TRUE, FALSE);
state = ACT200L_STATE_WAIT1_RESET;
delay = 50;
break;
case ACT200L_STATE_WAIT1_RESET:
sirdev_set_dtr_rts(dev, FALSE, TRUE);
udelay(25);
sirdev_raw_write(dev, control, sizeof(control));
state = ACT200L_STATE_WAIT2_RESET;
delay = 15;
break;
case ACT200L_STATE_WAIT2_RESET:
sirdev_set_dtr_rts(dev, TRUE, TRUE);
dev->speed = 9600;
break;
default:
net_err_ratelimited("%s(), unknown state %d\n",
__func__, state);
ret = -1;
break;
}
dev->fsm.substate = state;
return (delay > 0) ? delay : ret;
}
