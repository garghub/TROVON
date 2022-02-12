static int __init swarm_i2c_init(void)
{
int err;
err = i2c_register_board_info(1, swarm_i2c_info1,
ARRAY_SIZE(swarm_i2c_info1));
if (err < 0)
printk(KERN_ERR
"swarm-i2c: cannot register board I2C devices\n");
return err;
}
