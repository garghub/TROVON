static int __init wilc_bus_probe(struct spi_device *spi)
{
PRINT_D(BUS_DBG, "spiModalias: %s\n", spi->modalias);
PRINT_D(BUS_DBG, "spiMax-Speed: %d\n", spi->max_speed_hz);
wilc_spi_dev = spi;
printk("Driver Initializing success\n");
return 0;
}
static int __exit wilc_bus_remove(struct spi_device *spi)
{
return 0;
}
void linux_spi_deinit(void *vp)
{
spi_unregister_driver(&wilc_bus);
SPEED = MIN_SPEED;
PRINT_ER("@@@@@@@@@@@@ restore SPI speed to %d @@@@@@@@@\n", SPEED);
}
int linux_spi_init(void *vp)
{
int ret = 1;
static int called;
if (called == 0) {
called++;
ret = spi_register_driver(&wilc_bus);
}
(ret < 0) ? (ret = 0) : (ret = 1);
return ret;
}
int linux_spi_write(u8 *b, u32 len)
{
int ret;
if (len > 0 && b != NULL) {
int i = 0;
int blk = len / TXRX_PHASE_SIZE;
int remainder = len % TXRX_PHASE_SIZE;
char *r_buffer = kzalloc(TXRX_PHASE_SIZE, GFP_KERNEL);
if (!r_buffer)
return -ENOMEM;
if (blk) {
while (i < blk) {
struct spi_message msg;
struct spi_transfer tr = {
.tx_buf = b + (i * TXRX_PHASE_SIZE),
.len = TXRX_PHASE_SIZE,
.speed_hz = SPEED,
.bits_per_word = 8,
.delay_usecs = 0,
};
tr.rx_buf = r_buffer;
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = wilc_spi_dev;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(wilc_spi_dev, &msg);
if (ret < 0) {
PRINT_ER("SPI transaction failed\n");
}
i++;
}
}
if (remainder) {
struct spi_message msg;
struct spi_transfer tr = {
.tx_buf = b + (blk * TXRX_PHASE_SIZE),
.len = remainder,
.speed_hz = SPEED,
.bits_per_word = 8,
.delay_usecs = 0,
};
tr.rx_buf = r_buffer;
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = wilc_spi_dev;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(wilc_spi_dev, &msg);
if (ret < 0) {
PRINT_ER("SPI transaction failed\n");
}
}
kfree(r_buffer);
} else {
PRINT_ER("can't write data with the following length: %d\n", len);
PRINT_ER("FAILED due to NULL buffer or ZERO length check the following length: %d\n", len);
ret = -1;
}
(ret < 0) ? (ret = 0) : (ret = 1);
return ret;
}
int linux_spi_write(u8 *b, u32 len)
{
int ret;
struct spi_message msg;
if (len > 0 && b != NULL) {
struct spi_transfer tr = {
.tx_buf = b,
.len = len,
.speed_hz = SPEED,
.delay_usecs = 0,
};
char *r_buffer = kzalloc(len, GFP_KERNEL);
if (!r_buffer)
return -ENOMEM;
tr.rx_buf = r_buffer;
PRINT_D(BUS_DBG, "Request writing %d bytes\n", len);
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = wilc_spi_dev;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(wilc_spi_dev, &msg);
if (ret < 0) {
PRINT_ER("SPI transaction failed\n");
}
kfree(r_buffer);
} else {
PRINT_ER("can't write data with the following length: %d\n", len);
PRINT_ER("FAILED due to NULL buffer or ZERO length check the following length: %d\n", len);
ret = -1;
}
(ret < 0) ? (ret = 0) : (ret = 1);
return ret;
}
int linux_spi_read(u8 *rb, u32 rlen)
{
int ret;
if (rlen > 0) {
int i = 0;
int blk = rlen / TXRX_PHASE_SIZE;
int remainder = rlen % TXRX_PHASE_SIZE;
char *t_buffer = kzalloc(TXRX_PHASE_SIZE, GFP_KERNEL);
if (!t_buffer)
return -ENOMEM;
if (blk) {
while (i < blk) {
struct spi_message msg;
struct spi_transfer tr = {
.rx_buf = rb + (i * TXRX_PHASE_SIZE),
.len = TXRX_PHASE_SIZE,
.speed_hz = SPEED,
.bits_per_word = 8,
.delay_usecs = 0,
};
tr.tx_buf = t_buffer;
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = wilc_spi_dev;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(wilc_spi_dev, &msg);
if (ret < 0) {
PRINT_ER("SPI transaction failed\n");
}
i++;
}
}
if (remainder) {
struct spi_message msg;
struct spi_transfer tr = {
.rx_buf = rb + (blk * TXRX_PHASE_SIZE),
.len = remainder,
.speed_hz = SPEED,
.bits_per_word = 8,
.delay_usecs = 0,
};
tr.tx_buf = t_buffer;
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = wilc_spi_dev;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(wilc_spi_dev, &msg);
if (ret < 0) {
PRINT_ER("SPI transaction failed\n");
}
}
kfree(t_buffer);
} else {
PRINT_ER("can't read data with the following length: %u\n", rlen);
ret = -1;
}
(ret < 0) ? (ret = 0) : (ret = 1);
return ret;
}
int linux_spi_read(u8 *rb, u32 rlen)
{
int ret;
if (rlen > 0) {
struct spi_message msg;
struct spi_transfer tr = {
.rx_buf = rb,
.len = rlen,
.speed_hz = SPEED,
.delay_usecs = 0,
};
char *t_buffer = kzalloc(rlen, GFP_KERNEL);
if (!t_buffer)
return -ENOMEM;
tr.tx_buf = t_buffer;
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = wilc_spi_dev;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(wilc_spi_dev, &msg);
if (ret < 0) {
PRINT_ER("SPI transaction failed\n");
}
kfree(t_buffer);
} else {
PRINT_ER("can't read data with the following length: %u\n", rlen);
ret = -1;
}
(ret < 0) ? (ret = 0) : (ret = 1);
return ret;
}
int linux_spi_write_read(u8 *wb, u8 *rb, u32 rlen)
{
int ret;
if (rlen > 0) {
struct spi_message msg;
struct spi_transfer tr = {
.rx_buf = rb,
.tx_buf = wb,
.len = rlen,
.speed_hz = SPEED,
.bits_per_word = 8,
.delay_usecs = 0,
};
memset(&msg, 0, sizeof(msg));
spi_message_init(&msg);
msg.spi = wilc_spi_dev;
msg.is_dma_mapped = USE_SPI_DMA;
spi_message_add_tail(&tr, &msg);
ret = spi_sync(wilc_spi_dev, &msg);
if (ret < 0) {
PRINT_ER("SPI transaction failed\n");
}
} else {
PRINT_ER("can't read data with the following length: %u\n", rlen);
ret = -1;
}
(ret < 0) ? (ret = 0) : (ret = 1);
return ret;
}
int linux_spi_set_max_speed(void)
{
SPEED = MAX_SPEED;
PRINT_INFO(BUS_DBG, "@@@@@@@@@@@@ change SPI speed to %d @@@@@@@@@\n", SPEED);
return 1;
}
