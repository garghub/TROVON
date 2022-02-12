static enum fpga_mgr_states altera_ps_state(struct fpga_manager *mgr)
{
struct altera_ps_conf *conf = mgr->priv;
if (gpiod_get_value_cansleep(conf->status))
return FPGA_MGR_STATE_RESET;
return FPGA_MGR_STATE_UNKNOWN;
}
static inline void altera_ps_delay(int delay_us)
{
if (delay_us > 10)
usleep_range(delay_us, delay_us + 5);
else
udelay(delay_us);
}
static int altera_ps_write_init(struct fpga_manager *mgr,
struct fpga_image_info *info,
const char *buf, size_t count)
{
struct altera_ps_conf *conf = mgr->priv;
int min, max, waits;
int i;
conf->info_flags = info->flags;
if (info->flags & FPGA_MGR_PARTIAL_RECONFIG) {
dev_err(&mgr->dev, "Partial reconfiguration not supported.\n");
return -EINVAL;
}
gpiod_set_value_cansleep(conf->config, 1);
altera_ps_delay(conf->data->t_cfg_us);
if (!gpiod_get_value_cansleep(conf->status)) {
dev_err(&mgr->dev, "Status pin failed to show a reset\n");
return -EIO;
}
gpiod_set_value_cansleep(conf->config, 0);
min = conf->data->status_wait_min_us;
max = conf->data->status_wait_max_us;
waits = max / min;
if (max % min)
waits++;
for (i = 0; i < waits; i++) {
usleep_range(min, min + 10);
if (!gpiod_get_value_cansleep(conf->status)) {
altera_ps_delay(conf->data->t_st2ck_us);
return 0;
}
}
dev_err(&mgr->dev, "Status pin not ready.\n");
return -EIO;
}
static void rev_buf(char *buf, size_t len)
{
u32 *fw32 = (u32 *)buf;
size_t extra_bytes = (len & 0x03);
const u32 *fw_end = (u32 *)(buf + len - extra_bytes);
while (fw32 < fw_end) {
*fw32 = bitrev8x4(*fw32);
fw32++;
}
if (extra_bytes) {
buf = (char *)fw_end;
while (extra_bytes) {
*buf = bitrev8(*buf);
buf++;
extra_bytes--;
}
}
}
static int altera_ps_write(struct fpga_manager *mgr, const char *buf,
size_t count)
{
struct altera_ps_conf *conf = mgr->priv;
const char *fw_data = buf;
const char *fw_data_end = fw_data + count;
while (fw_data < fw_data_end) {
int ret;
size_t stride = min_t(size_t, fw_data_end - fw_data, SZ_4K);
if (!(conf->info_flags & FPGA_MGR_BITSTREAM_LSB_FIRST))
rev_buf((char *)fw_data, stride);
ret = spi_write(conf->spi, fw_data, stride);
if (ret) {
dev_err(&mgr->dev, "spi error in firmware write: %d\n",
ret);
return ret;
}
fw_data += stride;
}
return 0;
}
static int altera_ps_write_complete(struct fpga_manager *mgr,
struct fpga_image_info *info)
{
struct altera_ps_conf *conf = mgr->priv;
const char dummy[] = {0};
int ret;
if (gpiod_get_value_cansleep(conf->status)) {
dev_err(&mgr->dev, "Error during configuration.\n");
return -EIO;
}
if (!IS_ERR(conf->confd)) {
if (!gpiod_get_raw_value_cansleep(conf->confd)) {
dev_err(&mgr->dev, "CONF_DONE is inactive!\n");
return -EIO;
}
}
ret = spi_write(conf->spi, dummy, 1);
if (ret) {
dev_err(&mgr->dev, "spi error during end sequence: %d\n", ret);
return ret;
}
return 0;
}
static int altera_ps_probe(struct spi_device *spi)
{
struct altera_ps_conf *conf;
const struct of_device_id *of_id;
conf = devm_kzalloc(&spi->dev, sizeof(*conf), GFP_KERNEL);
if (!conf)
return -ENOMEM;
of_id = of_match_device(of_ef_match, &spi->dev);
if (!of_id)
return -ENODEV;
conf->data = of_id->data;
conf->spi = spi;
conf->config = devm_gpiod_get(&spi->dev, "nconfig", GPIOD_OUT_HIGH);
if (IS_ERR(conf->config)) {
dev_err(&spi->dev, "Failed to get config gpio: %ld\n",
PTR_ERR(conf->config));
return PTR_ERR(conf->config);
}
conf->status = devm_gpiod_get(&spi->dev, "nstat", GPIOD_IN);
if (IS_ERR(conf->status)) {
dev_err(&spi->dev, "Failed to get status gpio: %ld\n",
PTR_ERR(conf->status));
return PTR_ERR(conf->status);
}
conf->confd = devm_gpiod_get(&spi->dev, "confd", GPIOD_IN);
if (IS_ERR(conf->confd)) {
dev_warn(&spi->dev, "Not using confd gpio: %ld\n",
PTR_ERR(conf->confd));
}
snprintf(conf->mgr_name, sizeof(conf->mgr_name), "%s %s",
dev_driver_string(&spi->dev), dev_name(&spi->dev));
return fpga_mgr_register(&spi->dev, conf->mgr_name,
&altera_ps_ops, conf);
}
static int altera_ps_remove(struct spi_device *spi)
{
fpga_mgr_unregister(&spi->dev);
return 0;
}
