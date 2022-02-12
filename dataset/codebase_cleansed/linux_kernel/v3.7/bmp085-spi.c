static int __devinit bmp085_spi_probe(struct spi_device *client)
{
int err;
struct regmap *regmap;
client->bits_per_word = 8;
err = spi_setup(client);
if (err < 0) {
dev_err(&client->dev, "spi_setup failed!\n");
return err;
}
regmap = devm_regmap_init_spi(client, &bmp085_regmap_config);
if (IS_ERR(regmap)) {
err = PTR_ERR(regmap);
dev_err(&client->dev, "Failed to init regmap: %d\n", err);
return err;
}
return bmp085_probe(&client->dev, regmap);
}
static int bmp085_spi_remove(struct spi_device *client)
{
return bmp085_remove(&client->dev);
}
