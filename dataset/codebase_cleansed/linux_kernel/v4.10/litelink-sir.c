static int __init litelink_sir_init(void)
{
return irda_register_dongle(&litelink);
}
static void __exit litelink_sir_cleanup(void)
{
irda_unregister_dongle(&litelink);
}
static int litelink_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
sirdev_set_dtr_rts(dev, TRUE, TRUE);
qos->baud_rate.bits &= IR_115200|IR_57600|IR_38400|IR_19200|IR_9600;
qos->min_turn_time.bits = 0x7f;
irda_qos_bits_to_value(qos);
return 0;
}
static int litelink_close(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, FALSE);
return 0;
}
static int litelink_change_speed(struct sir_dev *dev, unsigned speed)
{
int i;
for (i = 0; baud_rates[i] != speed; i++) {
if (baud_rates[i] == 9600)
break;
sirdev_set_dtr_rts(dev, FALSE, TRUE);
udelay(MIN_DELAY);
sirdev_set_dtr_rts(dev, TRUE, TRUE);
udelay(MIN_DELAY);
}
dev->speed = baud_rates[i];
return (dev->speed == speed) ? 0 : -EINVAL;
}
static int litelink_reset(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, TRUE, TRUE);
udelay(MIN_DELAY);
sirdev_set_dtr_rts(dev, TRUE, FALSE);
udelay(MIN_DELAY);
sirdev_set_dtr_rts(dev, TRUE, TRUE);
udelay(MIN_DELAY);
dev->speed = 115200;
return 0;
}
