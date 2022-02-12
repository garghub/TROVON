static int __devinit wm1250_ev1_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
return snd_soc_register_codec(&i2c->dev, &soc_codec_dev_wm1250_ev1,
&wm1250_ev1_dai, 1);
}
static int __devexit wm1250_ev1_remove(struct i2c_client *i2c)
{
snd_soc_unregister_codec(&i2c->dev);
return 0;
}
static int __init wm1250_ev1_modinit(void)
{
int ret = 0;
ret = i2c_add_driver(&wm1250_ev1_i2c_driver);
if (ret != 0)
pr_err("Failed to register WM1250-EV1 I2C driver: %d\n", ret);
return ret;
}
static void __exit wm1250_ev1_exit(void)
{
i2c_del_driver(&wm1250_ev1_i2c_driver);
}
