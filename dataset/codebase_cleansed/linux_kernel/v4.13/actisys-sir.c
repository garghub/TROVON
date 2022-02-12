static int __init actisys_sir_init(void)
{
int ret;
ret = irda_register_dongle(&act220l);
if (ret < 0)
return ret;
ret = irda_register_dongle(&act220l_plus);
if (ret < 0) {
irda_unregister_dongle(&act220l);
return ret;
}
return 0;
}
static void __exit actisys_sir_cleanup(void)
{
irda_unregister_dongle(&act220l_plus);
irda_unregister_dongle(&act220l);
}
static int actisys_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
sirdev_set_dtr_rts(dev, TRUE, TRUE);
qos->baud_rate.bits &= IR_9600|IR_19200|IR_38400|IR_57600|IR_115200;
if (dev->dongle_drv->type == IRDA_ACTISYS_DONGLE)
qos->baud_rate.bits &= ~IR_38400;
qos->min_turn_time.bits = 0x7f;
irda_qos_bits_to_value(qos);
return 0;
}
static int actisys_close(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, FALSE);
return 0;
}
static int actisys_change_speed(struct sir_dev *dev, unsigned speed)
{
int ret = 0;
int i = 0;
pr_debug("%s(), speed=%d (was %d)\n", __func__, speed, dev->speed);
for (i = 0; i < MAX_SPEEDS; i++) {
if (speed == baud_rates[i]) {
dev->speed = speed;
break;
}
sirdev_set_dtr_rts(dev, TRUE, FALSE);
udelay(MIN_DELAY);
sirdev_set_dtr_rts(dev, TRUE, TRUE);
udelay(MIN_DELAY);
}
if (i >= MAX_SPEEDS) {
actisys_reset(dev);
ret = -EINVAL;
}
return ret;
}
static int actisys_reset(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, TRUE);
udelay(MIN_DELAY);
sirdev_set_dtr_rts(dev, TRUE, TRUE);
dev->speed = 9600;
return 0;
}
