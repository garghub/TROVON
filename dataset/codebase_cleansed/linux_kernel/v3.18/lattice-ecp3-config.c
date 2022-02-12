static void firmware_load(const struct firmware *fw, void *context)
{
struct spi_device *spi = (struct spi_device *)context;
struct fpga_data *data = spi_get_drvdata(spi);
u8 *buffer;
int ret;
u8 txbuf[8];
u8 rxbuf[8];
int rx_len = 8;
int i;
u32 jedec_id;
u32 status;
if (fw == NULL) {
dev_err(&spi->dev, "Cannot load firmware, aborting\n");
return;
}
if (fw->size == 0) {
dev_err(&spi->dev, "Error: Firmware size is 0!\n");
return;
}
txbuf[1] = 0x00;
txbuf[2] = 0x00;
txbuf[3] = 0x00;
txbuf[0] = FPGA_CMD_READ_ID;
ret = spi_write_then_read(spi, txbuf, 8, rxbuf, rx_len);
jedec_id = get_unaligned_be32(&rxbuf[4]);
dev_dbg(&spi->dev, "FPGA JTAG ID=%08x\n", jedec_id);
for (i = 0; i < ARRAY_SIZE(ecp3_dev); i++) {
if (jedec_id == ecp3_dev[i].jedec_id)
break;
}
if (i == ARRAY_SIZE(ecp3_dev)) {
dev_err(&spi->dev,
"Error: No supported FPGA detected (JEDEC_ID=%08x)!\n",
jedec_id);
return;
}
dev_info(&spi->dev, "FPGA %s detected\n", ecp3_dev[i].name);
txbuf[0] = FPGA_CMD_READ_STATUS;
ret = spi_write_then_read(spi, txbuf, 8, rxbuf, rx_len);
status = get_unaligned_be32(&rxbuf[4]);
dev_dbg(&spi->dev, "FPGA Status=%08x\n", status);
buffer = kzalloc(fw->size + 8, GFP_KERNEL);
if (!buffer) {
dev_err(&spi->dev, "Error: Can't allocate memory!\n");
return;
}
buffer[0] = FPGA_CMD_WRITE_INC;
buffer[1] = 0xff;
buffer[2] = 0xff;
buffer[3] = 0xff;
memcpy(buffer + 4, fw->data, fw->size);
txbuf[0] = FPGA_CMD_REFRESH;
ret = spi_write(spi, txbuf, 4);
txbuf[0] = FPGA_CMD_WRITE_EN;
ret = spi_write(spi, txbuf, 4);
txbuf[0] = FPGA_CMD_CLEAR;
ret = spi_write(spi, txbuf, 4);
for (i = 0; i < FPGA_CLEAR_LOOP_COUNT; i++) {
txbuf[0] = FPGA_CMD_READ_STATUS;
ret = spi_write_then_read(spi, txbuf, 8, rxbuf, rx_len);
status = get_unaligned_be32(&rxbuf[4]);
if (status == FPGA_STATUS_CLEARED)
break;
msleep(FPGA_CLEAR_MSLEEP);
}
if (i == FPGA_CLEAR_LOOP_COUNT) {
dev_err(&spi->dev,
"Error: Timeout waiting for FPGA to clear (status=%08x)!\n",
status);
kfree(buffer);
return;
}
dev_info(&spi->dev, "Configuring the FPGA...\n");
ret = spi_write(spi, buffer, fw->size + 8);
txbuf[0] = FPGA_CMD_WRITE_DIS;
ret = spi_write(spi, txbuf, 4);
txbuf[0] = FPGA_CMD_READ_STATUS;
ret = spi_write_then_read(spi, txbuf, 8, rxbuf, rx_len);
status = get_unaligned_be32(&rxbuf[4]);
dev_dbg(&spi->dev, "FPGA Status=%08x\n", status);
if (status & FPGA_STATUS_DONE)
dev_info(&spi->dev, "FPGA successfully configured!\n");
else
dev_info(&spi->dev, "FPGA not configured (DONE not set)\n");
release_firmware(fw);
kfree(buffer);
complete(&data->fw_loaded);
}
static int lattice_ecp3_probe(struct spi_device *spi)
{
struct fpga_data *data;
int err;
data = devm_kzalloc(&spi->dev, sizeof(*data), GFP_KERNEL);
if (!data) {
dev_err(&spi->dev, "Memory allocation for fpga_data failed\n");
return -ENOMEM;
}
spi_set_drvdata(spi, data);
init_completion(&data->fw_loaded);
err = request_firmware_nowait(THIS_MODULE, FW_ACTION_HOTPLUG,
FIRMWARE_NAME, &spi->dev,
GFP_KERNEL, spi, firmware_load);
if (err) {
dev_err(&spi->dev, "Firmware loading failed with %d!\n", err);
return err;
}
dev_info(&spi->dev, "FPGA bitstream configuration driver registered\n");
return 0;
}
static int lattice_ecp3_remove(struct spi_device *spi)
{
struct fpga_data *data = spi_get_drvdata(spi);
wait_for_completion(&data->fw_loaded);
return 0;
}
