static inline struct tpm_tis_spi_phy *to_tpm_tis_spi_phy(struct tpm_tis_data *data)
{
return container_of(data, struct tpm_tis_spi_phy, priv);
}
static int tpm_tis_spi_read_bytes(struct tpm_tis_data *data, u32 addr,
u16 len, u8 *result)
{
struct tpm_tis_spi_phy *phy = to_tpm_tis_spi_phy(data);
int ret, i;
struct spi_message m;
struct spi_transfer spi_xfer = {
.tx_buf = phy->tx_buf,
.rx_buf = phy->rx_buf,
.len = 4,
};
if (len > MAX_SPI_FRAMESIZE)
return -ENOMEM;
phy->tx_buf[0] = 0x80 | (len - 1);
phy->tx_buf[1] = 0xd4;
phy->tx_buf[2] = (addr >> 8) & 0xFF;
phy->tx_buf[3] = addr & 0xFF;
spi_xfer.cs_change = 1;
spi_message_init(&m);
spi_message_add_tail(&spi_xfer, &m);
spi_bus_lock(phy->spi_device->master);
ret = spi_sync_locked(phy->spi_device, &m);
if (ret < 0)
goto exit;
memset(phy->tx_buf, 0, len);
for (i = 0; (phy->rx_buf[0] & 0x01) == 0 && i < TPM_RETRY; i++) {
spi_xfer.len = 1;
spi_message_init(&m);
spi_message_add_tail(&spi_xfer, &m);
ret = spi_sync_locked(phy->spi_device, &m);
if (ret < 0)
goto exit;
}
spi_xfer.cs_change = 0;
spi_xfer.len = len;
spi_xfer.rx_buf = result;
spi_message_init(&m);
spi_message_add_tail(&spi_xfer, &m);
ret = spi_sync_locked(phy->spi_device, &m);
exit:
spi_bus_unlock(phy->spi_device->master);
return ret;
}
static int tpm_tis_spi_write_bytes(struct tpm_tis_data *data, u32 addr,
u16 len, u8 *value)
{
struct tpm_tis_spi_phy *phy = to_tpm_tis_spi_phy(data);
int ret, i;
struct spi_message m;
struct spi_transfer spi_xfer = {
.tx_buf = phy->tx_buf,
.rx_buf = phy->rx_buf,
.len = 4,
};
if (len > MAX_SPI_FRAMESIZE)
return -ENOMEM;
phy->tx_buf[0] = len - 1;
phy->tx_buf[1] = 0xd4;
phy->tx_buf[2] = (addr >> 8) & 0xFF;
phy->tx_buf[3] = addr & 0xFF;
spi_xfer.cs_change = 1;
spi_message_init(&m);
spi_message_add_tail(&spi_xfer, &m);
spi_bus_lock(phy->spi_device->master);
ret = spi_sync_locked(phy->spi_device, &m);
if (ret < 0)
goto exit;
memset(phy->tx_buf, 0, len);
for (i = 0; (phy->rx_buf[0] & 0x01) == 0 && i < TPM_RETRY; i++) {
spi_xfer.len = 1;
spi_message_init(&m);
spi_message_add_tail(&spi_xfer, &m);
ret = spi_sync_locked(phy->spi_device, &m);
if (ret < 0)
goto exit;
}
spi_xfer.len = len;
spi_xfer.tx_buf = value;
spi_xfer.cs_change = 0;
spi_xfer.tx_buf = value;
spi_message_init(&m);
spi_message_add_tail(&spi_xfer, &m);
ret = spi_sync_locked(phy->spi_device, &m);
exit:
spi_bus_unlock(phy->spi_device->master);
return ret;
}
static int tpm_tis_spi_read16(struct tpm_tis_data *data, u32 addr, u16 *result)
{
int rc;
rc = data->phy_ops->read_bytes(data, addr, sizeof(u16), (u8 *)result);
if (!rc)
*result = le16_to_cpu(*result);
return rc;
}
static int tpm_tis_spi_read32(struct tpm_tis_data *data, u32 addr, u32 *result)
{
int rc;
rc = data->phy_ops->read_bytes(data, addr, sizeof(u32), (u8 *)result);
if (!rc)
*result = le32_to_cpu(*result);
return rc;
}
static int tpm_tis_spi_write32(struct tpm_tis_data *data, u32 addr, u32 value)
{
value = cpu_to_le32(value);
return data->phy_ops->write_bytes(data, addr, sizeof(u32),
(u8 *)&value);
}
static int tpm_tis_spi_probe(struct spi_device *dev)
{
struct tpm_tis_spi_phy *phy;
phy = devm_kzalloc(&dev->dev, sizeof(struct tpm_tis_spi_phy),
GFP_KERNEL);
if (!phy)
return -ENOMEM;
phy->spi_device = dev;
return tpm_tis_core_init(&dev->dev, &phy->priv, -1, &tpm_spi_phy_ops,
NULL);
}
static int tpm_tis_spi_remove(struct spi_device *dev)
{
struct tpm_chip *chip = spi_get_drvdata(dev);
tpm_chip_unregister(chip);
tpm_tis_remove(chip);
return 0;
}
