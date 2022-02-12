static int __init esi_sir_init(void)
{
return irda_register_dongle(&esi);
}
static void __exit esi_sir_cleanup(void)
{
irda_unregister_dongle(&esi);
}
static int esi_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
sirdev_set_dtr_rts(dev, FALSE, TRUE);
qos->baud_rate.bits &= IR_9600|IR_19200|IR_115200;
qos->min_turn_time.bits = 0x01;
irda_qos_bits_to_value(qos);
return 0;
}
static int esi_close(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, FALSE);
return 0;
}
static int esi_change_speed(struct sir_dev *dev, unsigned speed)
{
int ret = 0;
int dtr, rts;
switch (speed) {
case 19200:
dtr = TRUE;
rts = FALSE;
break;
case 115200:
dtr = rts = TRUE;
break;
default:
ret = -EINVAL;
speed = 9600;
case 9600:
dtr = FALSE;
rts = TRUE;
break;
}
sirdev_set_dtr_rts(dev, dtr, rts);
dev->speed = speed;
return ret;
}
static int esi_reset(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, FALSE);
sirdev_set_dtr_rts(dev, FALSE, TRUE);
dev->speed = 9600;
return 0;
}
