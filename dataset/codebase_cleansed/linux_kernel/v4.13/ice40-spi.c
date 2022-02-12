static enum fpga_mgr_states ice40_fpga_ops_state(struct fpga_manager *mgr)
{
struct ice40_fpga_priv *priv = mgr->priv;
return gpiod_get_value(priv->cdone) ? FPGA_MGR_STATE_OPERATING :
FPGA_MGR_STATE_UNKNOWN;
}
static int ice40_fpga_ops_write_init(struct fpga_manager *mgr,
struct fpga_image_info *info,
const char *buf, size_t count)
{
struct ice40_fpga_priv *priv = mgr->priv;
struct spi_device *dev = priv->dev;
struct spi_message message;
struct spi_transfer assert_cs_then_reset_delay = {
.cs_change = 1,
.delay_usecs = ICE40_SPI_RESET_DELAY
};
struct spi_transfer housekeeping_delay_then_release_cs = {
.delay_usecs = ICE40_SPI_HOUSEKEEPING_DELAY
};
int ret;
if ((info->flags & FPGA_MGR_PARTIAL_RECONFIG)) {
dev_err(&dev->dev,
"Partial reconfiguration is not supported\n");
return -ENOTSUPP;
}
spi_bus_lock(dev->master);
gpiod_set_value(priv->reset, 1);
spi_message_init(&message);
spi_message_add_tail(&assert_cs_then_reset_delay, &message);
ret = spi_sync_locked(dev, &message);
gpiod_set_value(priv->reset, 0);
if (ret)
goto fail;
if (gpiod_get_value(priv->cdone)) {
dev_err(&dev->dev, "Device reset failed, CDONE is asserted\n");
ret = -EIO;
goto fail;
}
spi_message_init(&message);
spi_message_add_tail(&housekeeping_delay_then_release_cs, &message);
ret = spi_sync_locked(dev, &message);
fail:
spi_bus_unlock(dev->master);
return ret;
}
static int ice40_fpga_ops_write(struct fpga_manager *mgr,
const char *buf, size_t count)
{
struct ice40_fpga_priv *priv = mgr->priv;
return spi_write(priv->dev, buf, count);
}
static int ice40_fpga_ops_write_complete(struct fpga_manager *mgr,
struct fpga_image_info *info)
{
struct ice40_fpga_priv *priv = mgr->priv;
struct spi_device *dev = priv->dev;
const u8 padding[ICE40_SPI_NUM_ACTIVATION_BYTES] = {0};
if (!gpiod_get_value(priv->cdone)) {
dev_err(&dev->dev,
"CDONE was not asserted after firmware transfer\n");
return -EIO;
}
return spi_write(dev, padding, sizeof(padding));
}
static int ice40_fpga_probe(struct spi_device *spi)
{
struct device *dev = &spi->dev;
struct ice40_fpga_priv *priv;
int ret;
priv = devm_kzalloc(&spi->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = spi;
if (spi->max_speed_hz > ICE40_SPI_MAX_SPEED) {
dev_err(dev, "SPI speed is too high, maximum speed is "
__stringify(ICE40_SPI_MAX_SPEED) "\n");
return -EINVAL;
}
if (spi->max_speed_hz < ICE40_SPI_MIN_SPEED) {
dev_err(dev, "SPI speed is too low, minimum speed is "
__stringify(ICE40_SPI_MIN_SPEED) "\n");
return -EINVAL;
}
if (spi->mode & SPI_CPHA) {
dev_err(dev, "Bad SPI mode, CPHA not supported\n");
return -EINVAL;
}
priv->cdone = devm_gpiod_get(dev, "cdone", GPIOD_IN);
if (IS_ERR(priv->cdone)) {
ret = PTR_ERR(priv->cdone);
dev_err(dev, "Failed to get CDONE GPIO: %d\n", ret);
return ret;
}
priv->reset = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
if (IS_ERR(priv->reset)) {
ret = PTR_ERR(priv->reset);
dev_err(dev, "Failed to get CRESET_B GPIO: %d\n", ret);
return ret;
}
return fpga_mgr_register(dev, "Lattice iCE40 FPGA Manager",
&ice40_fpga_ops, priv);
}
static int ice40_fpga_remove(struct spi_device *spi)
{
fpga_mgr_unregister(&spi->dev);
return 0;
}
