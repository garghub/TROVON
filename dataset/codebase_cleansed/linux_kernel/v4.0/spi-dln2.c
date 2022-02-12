static int dln2_spi_enable(struct dln2_spi *dln2, bool enable)
{
u16 cmd;
struct {
u8 port;
u8 wait_for_completion;
} tx;
unsigned len = sizeof(tx);
tx.port = dln2->port;
if (enable) {
cmd = DLN2_SPI_ENABLE;
len -= sizeof(tx.wait_for_completion);
} else {
tx.wait_for_completion = DLN2_TRANSFERS_WAIT_COMPLETE;
cmd = DLN2_SPI_DISABLE;
}
return dln2_transfer_tx(dln2->pdev, cmd, &tx, len);
}
static int dln2_spi_cs_set(struct dln2_spi *dln2, u8 cs_mask)
{
struct {
u8 port;
u8 cs;
} tx;
tx.port = dln2->port;
tx.cs = ~cs_mask;
return dln2_transfer_tx(dln2->pdev, DLN2_SPI_SET_SS, &tx, sizeof(tx));
}
static int dln2_spi_cs_set_one(struct dln2_spi *dln2, u8 cs)
{
return dln2_spi_cs_set(dln2, BIT(cs));
}
static int dln2_spi_cs_enable(struct dln2_spi *dln2, u8 cs_mask, bool enable)
{
struct {
u8 port;
u8 cs;
} tx;
u16 cmd;
tx.port = dln2->port;
tx.cs = cs_mask;
cmd = enable ? DLN2_SPI_SS_MULTI_ENABLE : DLN2_SPI_SS_MULTI_DISABLE;
return dln2_transfer_tx(dln2->pdev, cmd, &tx, sizeof(tx));
}
static int dln2_spi_cs_enable_all(struct dln2_spi *dln2, bool enable)
{
u8 cs_mask = GENMASK(dln2->master->num_chipselect - 1, 0);
return dln2_spi_cs_enable(dln2, cs_mask, enable);
}
static int dln2_spi_get_cs_num(struct dln2_spi *dln2, u16 *cs_num)
{
int ret;
struct {
u8 port;
} tx;
struct {
__le16 cs_count;
} rx;
unsigned rx_len = sizeof(rx);
tx.port = dln2->port;
ret = dln2_transfer(dln2->pdev, DLN2_SPI_GET_SS_COUNT, &tx, sizeof(tx),
&rx, &rx_len);
if (ret < 0)
return ret;
if (rx_len < sizeof(rx))
return -EPROTO;
*cs_num = le16_to_cpu(rx.cs_count);
dev_dbg(&dln2->pdev->dev, "cs_num = %d\n", *cs_num);
return 0;
}
static int dln2_spi_get_speed(struct dln2_spi *dln2, u16 cmd, u32 *freq)
{
int ret;
struct {
u8 port;
} tx;
struct {
__le32 speed;
} rx;
unsigned rx_len = sizeof(rx);
tx.port = dln2->port;
ret = dln2_transfer(dln2->pdev, cmd, &tx, sizeof(tx), &rx, &rx_len);
if (ret < 0)
return ret;
if (rx_len < sizeof(rx))
return -EPROTO;
*freq = le32_to_cpu(rx.speed);
return 0;
}
static int dln2_spi_get_speed_range(struct dln2_spi *dln2, u32 *fmin, u32 *fmax)
{
int ret;
ret = dln2_spi_get_speed(dln2, DLN2_SPI_GET_MIN_FREQUENCY, fmin);
if (ret < 0)
return ret;
ret = dln2_spi_get_speed(dln2, DLN2_SPI_GET_MAX_FREQUENCY, fmax);
if (ret < 0)
return ret;
dev_dbg(&dln2->pdev->dev, "freq_min = %d, freq_max = %d\n",
*fmin, *fmax);
return 0;
}
static int dln2_spi_set_speed(struct dln2_spi *dln2, u32 speed)
{
int ret;
struct {
u8 port;
__le32 speed;
} __packed tx;
struct {
__le32 speed;
} rx;
int rx_len = sizeof(rx);
tx.port = dln2->port;
tx.speed = cpu_to_le32(speed);
ret = dln2_transfer(dln2->pdev, DLN2_SPI_SET_FREQUENCY, &tx, sizeof(tx),
&rx, &rx_len);
if (ret < 0)
return ret;
if (rx_len < sizeof(rx))
return -EPROTO;
return 0;
}
static int dln2_spi_set_mode(struct dln2_spi *dln2, u8 mode)
{
struct {
u8 port;
u8 mode;
} tx;
tx.port = dln2->port;
tx.mode = mode;
return dln2_transfer_tx(dln2->pdev, DLN2_SPI_SET_MODE, &tx, sizeof(tx));
}
static int dln2_spi_set_bpw(struct dln2_spi *dln2, u8 bpw)
{
struct {
u8 port;
u8 bpw;
} tx;
tx.port = dln2->port;
tx.bpw = bpw;
return dln2_transfer_tx(dln2->pdev, DLN2_SPI_SET_FRAME_SIZE,
&tx, sizeof(tx));
}
static int dln2_spi_get_supported_frame_sizes(struct dln2_spi *dln2,
u32 *bpw_mask)
{
int ret;
struct {
u8 port;
} tx;
struct {
u8 count;
u8 frame_sizes[36];
} *rx = dln2->buf;
unsigned rx_len = sizeof(*rx);
int i;
tx.port = dln2->port;
ret = dln2_transfer(dln2->pdev, DLN2_SPI_GET_SUPPORTED_FRAME_SIZES,
&tx, sizeof(tx), rx, &rx_len);
if (ret < 0)
return ret;
if (rx_len < sizeof(*rx))
return -EPROTO;
if (rx->count > ARRAY_SIZE(rx->frame_sizes))
return -EPROTO;
*bpw_mask = 0;
for (i = 0; i < rx->count; i++)
*bpw_mask |= BIT(rx->frame_sizes[i] - 1);
dev_dbg(&dln2->pdev->dev, "bpw_mask = 0x%X\n", *bpw_mask);
return 0;
}
static int dln2_spi_copy_to_buf(u8 *dln2_buf, const u8 *src, u16 len, u8 bpw)
{
#ifdef __LITTLE_ENDIAN
memcpy(dln2_buf, src, len);
#else
if (bpw <= 8) {
memcpy(dln2_buf, src, len);
} else if (bpw <= 16) {
__le16 *d = (__le16 *)dln2_buf;
u16 *s = (u16 *)src;
len = len / 2;
while (len--)
*d++ = cpu_to_le16p(s++);
} else {
__le32 *d = (__le32 *)dln2_buf;
u32 *s = (u32 *)src;
len = len / 4;
while (len--)
*d++ = cpu_to_le32p(s++);
}
#endif
return 0;
}
static int dln2_spi_copy_from_buf(u8 *dest, const u8 *dln2_buf, u16 len, u8 bpw)
{
#ifdef __LITTLE_ENDIAN
memcpy(dest, dln2_buf, len);
#else
if (bpw <= 8) {
memcpy(dest, dln2_buf, len);
} else if (bpw <= 16) {
u16 *d = (u16 *)dest;
__le16 *s = (__le16 *)dln2_buf;
len = len / 2;
while (len--)
*d++ = le16_to_cpup(s++);
} else {
u32 *d = (u32 *)dest;
__le32 *s = (__le32 *)dln2_buf;
len = len / 4;
while (len--)
*d++ = get_unaligned_le32(s++);
}
#endif
return 0;
}
static int dln2_spi_write_one(struct dln2_spi *dln2, const u8 *data,
u16 data_len, u8 attr)
{
struct {
u8 port;
__le16 size;
u8 attr;
u8 buf[DLN2_SPI_MAX_XFER_SIZE];
} __packed *tx = dln2->buf;
unsigned tx_len;
BUILD_BUG_ON(sizeof(*tx) > DLN2_SPI_BUF_SIZE);
if (data_len > DLN2_SPI_MAX_XFER_SIZE)
return -EINVAL;
tx->port = dln2->port;
tx->size = cpu_to_le16(data_len);
tx->attr = attr;
dln2_spi_copy_to_buf(tx->buf, data, data_len, dln2->bpw);
tx_len = sizeof(*tx) + data_len - DLN2_SPI_MAX_XFER_SIZE;
return dln2_transfer_tx(dln2->pdev, DLN2_SPI_WRITE, tx, tx_len);
}
static int dln2_spi_read_one(struct dln2_spi *dln2, u8 *data,
u16 data_len, u8 attr)
{
int ret;
struct {
u8 port;
__le16 size;
u8 attr;
} __packed tx;
struct {
__le16 size;
u8 buf[DLN2_SPI_MAX_XFER_SIZE];
} __packed *rx = dln2->buf;
unsigned rx_len = sizeof(*rx);
BUILD_BUG_ON(sizeof(*rx) > DLN2_SPI_BUF_SIZE);
if (data_len > DLN2_SPI_MAX_XFER_SIZE)
return -EINVAL;
tx.port = dln2->port;
tx.size = cpu_to_le16(data_len);
tx.attr = attr;
ret = dln2_transfer(dln2->pdev, DLN2_SPI_READ, &tx, sizeof(tx),
rx, &rx_len);
if (ret < 0)
return ret;
if (rx_len < sizeof(rx->size) + data_len)
return -EPROTO;
if (le16_to_cpu(rx->size) != data_len)
return -EPROTO;
dln2_spi_copy_from_buf(data, rx->buf, data_len, dln2->bpw);
return 0;
}
static int dln2_spi_read_write_one(struct dln2_spi *dln2, const u8 *tx_data,
u8 *rx_data, u16 data_len, u8 attr)
{
int ret;
struct {
u8 port;
__le16 size;
u8 attr;
u8 buf[DLN2_SPI_MAX_XFER_SIZE];
} __packed *tx;
struct {
__le16 size;
u8 buf[DLN2_SPI_MAX_XFER_SIZE];
} __packed *rx;
unsigned tx_len, rx_len;
BUILD_BUG_ON(sizeof(*tx) > DLN2_SPI_BUF_SIZE ||
sizeof(*rx) > DLN2_SPI_BUF_SIZE);
if (data_len > DLN2_SPI_MAX_XFER_SIZE)
return -EINVAL;
tx = dln2->buf;
rx = dln2->buf;
tx->port = dln2->port;
tx->size = cpu_to_le16(data_len);
tx->attr = attr;
dln2_spi_copy_to_buf(tx->buf, tx_data, data_len, dln2->bpw);
tx_len = sizeof(*tx) + data_len - DLN2_SPI_MAX_XFER_SIZE;
rx_len = sizeof(*rx);
ret = dln2_transfer(dln2->pdev, DLN2_SPI_READ_WRITE, tx, tx_len,
rx, &rx_len);
if (ret < 0)
return ret;
if (rx_len < sizeof(rx->size) + data_len)
return -EPROTO;
if (le16_to_cpu(rx->size) != data_len)
return -EPROTO;
dln2_spi_copy_from_buf(rx_data, rx->buf, data_len, dln2->bpw);
return 0;
}
static int dln2_spi_rdwr(struct dln2_spi *dln2, const u8 *tx_data,
u8 *rx_data, u16 data_len, u8 attr) {
int ret;
u16 len;
u8 temp_attr;
u16 remaining = data_len;
u16 offset;
do {
if (remaining > DLN2_SPI_MAX_XFER_SIZE) {
len = DLN2_SPI_MAX_XFER_SIZE;
temp_attr = DLN2_SPI_ATTR_LEAVE_SS_LOW;
} else {
len = remaining;
temp_attr = attr;
}
offset = data_len - remaining;
if (tx_data && rx_data) {
ret = dln2_spi_read_write_one(dln2,
tx_data + offset,
rx_data + offset,
len, temp_attr);
} else if (tx_data) {
ret = dln2_spi_write_one(dln2,
tx_data + offset,
len, temp_attr);
} else if (rx_data) {
ret = dln2_spi_read_one(dln2,
rx_data + offset,
len, temp_attr);
} else {
return -EINVAL;
}
if (ret < 0)
return ret;
remaining -= len;
} while (remaining);
return 0;
}
static int dln2_spi_prepare_message(struct spi_master *master,
struct spi_message *message)
{
int ret;
struct dln2_spi *dln2 = spi_master_get_devdata(master);
struct spi_device *spi = message->spi;
if (dln2->cs != spi->chip_select) {
ret = dln2_spi_cs_set_one(dln2, spi->chip_select);
if (ret < 0)
return ret;
dln2->cs = spi->chip_select;
}
return 0;
}
static int dln2_spi_transfer_setup(struct dln2_spi *dln2, u32 speed,
u8 bpw, u8 mode)
{
int ret;
bool bus_setup_change;
bus_setup_change = dln2->speed != speed || dln2->mode != mode ||
dln2->bpw != bpw;
if (!bus_setup_change)
return 0;
ret = dln2_spi_enable(dln2, false);
if (ret < 0)
return ret;
if (dln2->speed != speed) {
ret = dln2_spi_set_speed(dln2, speed);
if (ret < 0)
return ret;
dln2->speed = speed;
}
if (dln2->mode != mode) {
ret = dln2_spi_set_mode(dln2, mode & 0x3);
if (ret < 0)
return ret;
dln2->mode = mode;
}
if (dln2->bpw != bpw) {
ret = dln2_spi_set_bpw(dln2, bpw);
if (ret < 0)
return ret;
dln2->bpw = bpw;
}
return dln2_spi_enable(dln2, true);
}
static int dln2_spi_transfer_one(struct spi_master *master,
struct spi_device *spi,
struct spi_transfer *xfer)
{
struct dln2_spi *dln2 = spi_master_get_devdata(master);
int status;
u8 attr = 0;
status = dln2_spi_transfer_setup(dln2, xfer->speed_hz,
xfer->bits_per_word,
spi->mode);
if (status < 0) {
dev_err(&dln2->pdev->dev, "Cannot setup transfer\n");
return status;
}
if (!xfer->cs_change && !spi_transfer_is_last(master, xfer))
attr = DLN2_SPI_ATTR_LEAVE_SS_LOW;
status = dln2_spi_rdwr(dln2, xfer->tx_buf, xfer->rx_buf,
xfer->len, attr);
if (status < 0)
dev_err(&dln2->pdev->dev, "write/read failed!\n");
return status;
}
static int dln2_spi_probe(struct platform_device *pdev)
{
struct spi_master *master;
struct dln2_spi *dln2;
struct dln2_platform_data *pdata = dev_get_platdata(&pdev->dev);
int ret;
master = spi_alloc_master(&pdev->dev, sizeof(*dln2));
if (!master)
return -ENOMEM;
platform_set_drvdata(pdev, master);
dln2 = spi_master_get_devdata(master);
dln2->buf = devm_kmalloc(&pdev->dev, DLN2_SPI_BUF_SIZE, GFP_KERNEL);
if (!dln2->buf) {
ret = -ENOMEM;
goto exit_free_master;
}
dln2->master = master;
dln2->pdev = pdev;
dln2->port = pdata->port;
dln2->cs = 0xff;
dln2->mode = 0xff;
ret = dln2_spi_enable(dln2, false);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to disable SPI module\n");
goto exit_free_master;
}
ret = dln2_spi_get_cs_num(dln2, &master->num_chipselect);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to get number of CS pins\n");
goto exit_free_master;
}
ret = dln2_spi_get_speed_range(dln2,
&master->min_speed_hz,
&master->max_speed_hz);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to read bus min/max freqs\n");
goto exit_free_master;
}
ret = dln2_spi_get_supported_frame_sizes(dln2,
&master->bits_per_word_mask);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to read supported frame sizes\n");
goto exit_free_master;
}
ret = dln2_spi_cs_enable_all(dln2, true);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to enable CS pins\n");
goto exit_free_master;
}
master->bus_num = -1;
master->mode_bits = SPI_CPOL | SPI_CPHA;
master->prepare_message = dln2_spi_prepare_message;
master->transfer_one = dln2_spi_transfer_one;
master->auto_runtime_pm = true;
ret = dln2_spi_enable(dln2, true);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to enable SPI module\n");
goto exit_free_master;
}
pm_runtime_set_autosuspend_delay(&pdev->dev,
DLN2_RPM_AUTOSUSPEND_TIMEOUT);
pm_runtime_use_autosuspend(&pdev->dev);
pm_runtime_set_active(&pdev->dev);
pm_runtime_enable(&pdev->dev);
ret = devm_spi_register_master(&pdev->dev, master);
if (ret < 0) {
dev_err(&pdev->dev, "Failed to register master\n");
goto exit_register;
}
return ret;
exit_register:
pm_runtime_disable(&pdev->dev);
pm_runtime_set_suspended(&pdev->dev);
if (dln2_spi_enable(dln2, false) < 0)
dev_err(&pdev->dev, "Failed to disable SPI module\n");
exit_free_master:
spi_master_put(master);
return ret;
}
static int dln2_spi_remove(struct platform_device *pdev)
{
struct spi_master *master = spi_master_get(platform_get_drvdata(pdev));
struct dln2_spi *dln2 = spi_master_get_devdata(master);
pm_runtime_disable(&pdev->dev);
if (dln2_spi_enable(dln2, false) < 0)
dev_err(&pdev->dev, "Failed to disable SPI module\n");
return 0;
}
static int dln2_spi_suspend(struct device *dev)
{
int ret;
struct spi_master *master = dev_get_drvdata(dev);
struct dln2_spi *dln2 = spi_master_get_devdata(master);
ret = spi_master_suspend(master);
if (ret < 0)
return ret;
if (!pm_runtime_suspended(dev)) {
ret = dln2_spi_enable(dln2, false);
if (ret < 0)
return ret;
}
dln2->cs = 0xff;
dln2->speed = 0;
dln2->bpw = 0;
dln2->mode = 0xff;
return 0;
}
static int dln2_spi_resume(struct device *dev)
{
int ret;
struct spi_master *master = dev_get_drvdata(dev);
struct dln2_spi *dln2 = spi_master_get_devdata(master);
if (!pm_runtime_suspended(dev)) {
ret = dln2_spi_cs_enable_all(dln2, true);
if (ret < 0)
return ret;
ret = dln2_spi_enable(dln2, true);
if (ret < 0)
return ret;
}
return spi_master_resume(master);
}
static int dln2_spi_runtime_suspend(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct dln2_spi *dln2 = spi_master_get_devdata(master);
return dln2_spi_enable(dln2, false);
}
static int dln2_spi_runtime_resume(struct device *dev)
{
struct spi_master *master = dev_get_drvdata(dev);
struct dln2_spi *dln2 = spi_master_get_devdata(master);
return dln2_spi_enable(dln2, true);
}
