static int __init ma600_sir_init(void)
{
return irda_register_dongle(&ma600);
}
static void __exit ma600_sir_cleanup(void)
{
irda_unregister_dongle(&ma600);
}
static int ma600_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
sirdev_set_dtr_rts(dev, TRUE, TRUE);
qos->baud_rate.bits &= IR_2400|IR_9600|IR_19200|IR_38400
|IR_57600|IR_115200;
qos->min_turn_time.bits = 0x01;
irda_qos_bits_to_value(qos);
return 0;
}
static int ma600_close(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, FALSE);
return 0;
}
static __u8 get_control_byte(__u32 speed)
{
__u8 byte;
switch (speed) {
default:
case 115200:
byte = MA600_115200;
break;
case 57600:
byte = MA600_57600;
break;
case 38400:
byte = MA600_38400;
break;
case 19200:
byte = MA600_19200;
break;
case 9600:
byte = MA600_9600;
break;
case 2400:
byte = MA600_2400;
break;
}
return byte;
}
static int ma600_change_speed(struct sir_dev *dev, unsigned speed)
{
u8 byte;
pr_debug("%s(), speed=%d (was %d)\n", __func__,
speed, dev->speed);
sirdev_set_dtr_rts(dev, TRUE, FALSE);
mdelay(1);
byte = get_control_byte(speed);
sirdev_raw_write(dev, &byte, sizeof(byte));
msleep(15);
#if 1
sirdev_raw_read(dev, &byte, sizeof(byte));
if (byte != get_control_byte(speed)) {
net_warn_ratelimited("%s(): bad control byte read-back %02x != %02x\n",
__func__, (unsigned)byte,
(unsigned)get_control_byte(speed));
return -1;
}
else
pr_debug("%s() control byte write read OK\n", __func__);
#endif
sirdev_set_dtr_rts(dev, TRUE, TRUE);
msleep(10);
dev->speed = speed;
return 0;
}
static int ma600_reset(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, FALSE, TRUE);
msleep(10);
sirdev_set_dtr_rts(dev, TRUE, TRUE);
msleep(10);
dev->speed = 9600;
return 0;
}
