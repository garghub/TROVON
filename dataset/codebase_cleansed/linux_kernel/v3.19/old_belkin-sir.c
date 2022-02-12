static int __init old_belkin_sir_init(void)
{
return irda_register_dongle(&old_belkin);
}
static void __exit old_belkin_sir_cleanup(void)
{
irda_unregister_dongle(&old_belkin);
}
static int old_belkin_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
sirdev_set_dtr_rts(dev, TRUE, TRUE);
qos->baud_rate.bits &= IR_9600;
qos->min_turn_time.bits = 0x01;
irda_qos_bits_to_value(qos);
return 0;
}
static int old_belkin_close(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, FALSE);
return 0;
}
static int old_belkin_change_speed(struct sir_dev *dev, unsigned speed)
{
dev->speed = 9600;
return (speed==dev->speed) ? 0 : -EINVAL;
}
static int old_belkin_reset(struct sir_dev *dev)
{
dev->speed = 9600;
return 0;
}
