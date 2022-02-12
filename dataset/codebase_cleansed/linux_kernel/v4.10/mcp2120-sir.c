static int __init mcp2120_sir_init(void)
{
return irda_register_dongle(&mcp2120);
}
static void __exit mcp2120_sir_cleanup(void)
{
irda_unregister_dongle(&mcp2120);
}
static int mcp2120_open(struct sir_dev *dev)
{
struct qos_info *qos = &dev->qos;
qos->baud_rate.bits &= IR_9600|IR_19200|IR_38400|IR_57600|IR_115200;
qos->min_turn_time.bits = 0x01;
irda_qos_bits_to_value(qos);
return 0;
}
static int mcp2120_close(struct sir_dev *dev)
{
sirdev_set_dtr_rts(dev, TRUE, TRUE);
return 0;
}
static int mcp2120_change_speed(struct sir_dev *dev, unsigned speed)
{
unsigned state = dev->fsm.substate;
unsigned delay = 0;
u8 control[2];
static int ret = 0;
switch (state) {
case SIRDEV_STATE_DONGLE_SPEED:
sirdev_set_dtr_rts(dev, TRUE, FALSE);
udelay(500);
ret = 0;
switch (speed) {
default:
speed = 9600;
ret = -EINVAL;
case 9600:
control[0] = MCP2120_9600;
break;
case 19200:
control[0] = MCP2120_19200;
break;
case 34800:
control[0] = MCP2120_38400;
break;
case 57600:
control[0] = MCP2120_57600;
break;
case 115200:
control[0] = MCP2120_115200;
break;
}
control[1] = MCP2120_COMMIT;
sirdev_raw_write(dev, control, 2);
dev->speed = speed;
state = MCP2120_STATE_WAIT_SPEED;
delay = 100;
break;
case MCP2120_STATE_WAIT_SPEED:
sirdev_set_dtr_rts(dev, FALSE, FALSE);
break;
default:
net_err_ratelimited("%s(), undefine state %d\n",
__func__, state);
ret = -EINVAL;
break;
}
dev->fsm.substate = state;
return (delay > 0) ? delay : ret;
}
static int mcp2120_reset(struct sir_dev *dev)
{
unsigned state = dev->fsm.substate;
unsigned delay = 0;
int ret = 0;
switch (state) {
case SIRDEV_STATE_DONGLE_RESET:
sirdev_set_dtr_rts(dev, TRUE, TRUE);
state = MCP2120_STATE_WAIT1_RESET;
delay = 50;
break;
case MCP2120_STATE_WAIT1_RESET:
sirdev_set_dtr_rts(dev, FALSE, FALSE);
state = MCP2120_STATE_WAIT2_RESET;
delay = 50;
break;
case MCP2120_STATE_WAIT2_RESET:
sirdev_set_dtr_rts(dev, FALSE, FALSE);
break;
default:
net_err_ratelimited("%s(), undefined state %d\n",
__func__, state);
ret = -EINVAL;
break;
}
dev->fsm.substate = state;
return (delay > 0) ? delay : ret;
}
