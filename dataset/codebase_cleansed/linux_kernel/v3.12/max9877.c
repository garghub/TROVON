static int max9877_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int i;
regmap = devm_regmap_init_i2c(client, &max9877_regmap);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
for (i = 0; i < ARRAY_SIZE(max9877_regs); i++)
regmap_write(regmap, max9877_regs[i].reg, max9877_regs[i].def);
return snd_soc_register_codec(&client->dev, &max9877_codec, NULL, 0);
}
static int max9877_i2c_remove(struct i2c_client *client)
{
snd_soc_unregister_codec(&client->dev);
return 0;
}
