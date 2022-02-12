static int w5100_spi_read(struct net_device *ndev, u32 addr)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[3] = { W5100_SPI_READ_OPCODE, addr >> 8, addr & 0xff };
u8 data;
int ret;
ret = spi_write_then_read(spi, cmd, sizeof(cmd), &data, 1);
return ret ? ret : data;
}
static int w5100_spi_write(struct net_device *ndev, u32 addr, u8 data)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[4] = { W5100_SPI_WRITE_OPCODE, addr >> 8, addr & 0xff, data};
return spi_write_then_read(spi, cmd, sizeof(cmd), NULL, 0);
}
static int w5100_spi_read16(struct net_device *ndev, u32 addr)
{
u16 data;
int ret;
ret = w5100_spi_read(ndev, addr);
if (ret < 0)
return ret;
data = ret << 8;
ret = w5100_spi_read(ndev, addr + 1);
return ret < 0 ? ret : data | ret;
}
static int w5100_spi_write16(struct net_device *ndev, u32 addr, u16 data)
{
int ret;
ret = w5100_spi_write(ndev, addr, data >> 8);
if (ret)
return ret;
return w5100_spi_write(ndev, addr + 1, data & 0xff);
}
static int w5100_spi_readbulk(struct net_device *ndev, u32 addr, u8 *buf,
int len)
{
int i;
for (i = 0; i < len; i++) {
int ret = w5100_spi_read(ndev, addr + i);
if (ret < 0)
return ret;
buf[i] = ret;
}
return 0;
}
static int w5100_spi_writebulk(struct net_device *ndev, u32 addr, const u8 *buf,
int len)
{
int i;
for (i = 0; i < len; i++) {
int ret = w5100_spi_write(ndev, addr + i, buf[i]);
if (ret)
return ret;
}
return 0;
}
static struct w5200_spi_priv *w5200_spi_priv(struct net_device *ndev)
{
return w5100_ops_priv(ndev);
}
static int w5200_spi_init(struct net_device *ndev)
{
struct w5200_spi_priv *spi_priv = w5200_spi_priv(ndev);
mutex_init(&spi_priv->cmd_lock);
return 0;
}
static int w5200_spi_read(struct net_device *ndev, u32 addr)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[4] = { addr >> 8, addr & 0xff, 0, 1 };
u8 data;
int ret;
ret = spi_write_then_read(spi, cmd, sizeof(cmd), &data, 1);
return ret ? ret : data;
}
static int w5200_spi_write(struct net_device *ndev, u32 addr, u8 data)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[5] = { addr >> 8, addr & 0xff, W5200_SPI_WRITE_OPCODE, 1, data };
return spi_write_then_read(spi, cmd, sizeof(cmd), NULL, 0);
}
static int w5200_spi_read16(struct net_device *ndev, u32 addr)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[4] = { addr >> 8, addr & 0xff, 0, 2 };
__be16 data;
int ret;
ret = spi_write_then_read(spi, cmd, sizeof(cmd), &data, sizeof(data));
return ret ? ret : be16_to_cpu(data);
}
static int w5200_spi_write16(struct net_device *ndev, u32 addr, u16 data)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[6] = {
addr >> 8, addr & 0xff,
W5200_SPI_WRITE_OPCODE, 2,
data >> 8, data & 0xff
};
return spi_write_then_read(spi, cmd, sizeof(cmd), NULL, 0);
}
static int w5200_spi_readbulk(struct net_device *ndev, u32 addr, u8 *buf,
int len)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
struct w5200_spi_priv *spi_priv = w5200_spi_priv(ndev);
struct spi_transfer xfer[] = {
{
.tx_buf = spi_priv->cmd_buf,
.len = sizeof(spi_priv->cmd_buf),
},
{
.rx_buf = buf,
.len = len,
},
};
int ret;
mutex_lock(&spi_priv->cmd_lock);
spi_priv->cmd_buf[0] = addr >> 8;
spi_priv->cmd_buf[1] = addr;
spi_priv->cmd_buf[2] = len >> 8;
spi_priv->cmd_buf[3] = len;
ret = spi_sync_transfer(spi, xfer, ARRAY_SIZE(xfer));
mutex_unlock(&spi_priv->cmd_lock);
return ret;
}
static int w5200_spi_writebulk(struct net_device *ndev, u32 addr, const u8 *buf,
int len)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
struct w5200_spi_priv *spi_priv = w5200_spi_priv(ndev);
struct spi_transfer xfer[] = {
{
.tx_buf = spi_priv->cmd_buf,
.len = sizeof(spi_priv->cmd_buf),
},
{
.tx_buf = buf,
.len = len,
},
};
int ret;
mutex_lock(&spi_priv->cmd_lock);
spi_priv->cmd_buf[0] = addr >> 8;
spi_priv->cmd_buf[1] = addr;
spi_priv->cmd_buf[2] = W5200_SPI_WRITE_OPCODE | (len >> 8);
spi_priv->cmd_buf[3] = len;
ret = spi_sync_transfer(spi, xfer, ARRAY_SIZE(xfer));
mutex_unlock(&spi_priv->cmd_lock);
return ret;
}
static struct w5500_spi_priv *w5500_spi_priv(struct net_device *ndev)
{
return w5100_ops_priv(ndev);
}
static int w5500_spi_init(struct net_device *ndev)
{
struct w5500_spi_priv *spi_priv = w5500_spi_priv(ndev);
mutex_init(&spi_priv->cmd_lock);
return 0;
}
static int w5500_spi_read(struct net_device *ndev, u32 addr)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[3] = {
addr >> 8,
addr,
W5500_SPI_READ_CONTROL(addr)
};
u8 data;
int ret;
ret = spi_write_then_read(spi, cmd, sizeof(cmd), &data, 1);
return ret ? ret : data;
}
static int w5500_spi_write(struct net_device *ndev, u32 addr, u8 data)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[4] = {
addr >> 8,
addr,
W5500_SPI_WRITE_CONTROL(addr),
data
};
return spi_write_then_read(spi, cmd, sizeof(cmd), NULL, 0);
}
static int w5500_spi_read16(struct net_device *ndev, u32 addr)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[3] = {
addr >> 8,
addr,
W5500_SPI_READ_CONTROL(addr)
};
__be16 data;
int ret;
ret = spi_write_then_read(spi, cmd, sizeof(cmd), &data, sizeof(data));
return ret ? ret : be16_to_cpu(data);
}
static int w5500_spi_write16(struct net_device *ndev, u32 addr, u16 data)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
u8 cmd[5] = {
addr >> 8,
addr,
W5500_SPI_WRITE_CONTROL(addr),
data >> 8,
data
};
return spi_write_then_read(spi, cmd, sizeof(cmd), NULL, 0);
}
static int w5500_spi_readbulk(struct net_device *ndev, u32 addr, u8 *buf,
int len)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
struct w5500_spi_priv *spi_priv = w5500_spi_priv(ndev);
struct spi_transfer xfer[] = {
{
.tx_buf = spi_priv->cmd_buf,
.len = sizeof(spi_priv->cmd_buf),
},
{
.rx_buf = buf,
.len = len,
},
};
int ret;
mutex_lock(&spi_priv->cmd_lock);
spi_priv->cmd_buf[0] = addr >> 8;
spi_priv->cmd_buf[1] = addr;
spi_priv->cmd_buf[2] = W5500_SPI_READ_CONTROL(addr);
ret = spi_sync_transfer(spi, xfer, ARRAY_SIZE(xfer));
mutex_unlock(&spi_priv->cmd_lock);
return ret;
}
static int w5500_spi_writebulk(struct net_device *ndev, u32 addr, const u8 *buf,
int len)
{
struct spi_device *spi = to_spi_device(ndev->dev.parent);
struct w5500_spi_priv *spi_priv = w5500_spi_priv(ndev);
struct spi_transfer xfer[] = {
{
.tx_buf = spi_priv->cmd_buf,
.len = sizeof(spi_priv->cmd_buf),
},
{
.tx_buf = buf,
.len = len,
},
};
int ret;
mutex_lock(&spi_priv->cmd_lock);
spi_priv->cmd_buf[0] = addr >> 8;
spi_priv->cmd_buf[1] = addr;
spi_priv->cmd_buf[2] = W5500_SPI_WRITE_CONTROL(addr);
ret = spi_sync_transfer(spi, xfer, ARRAY_SIZE(xfer));
mutex_unlock(&spi_priv->cmd_lock);
return ret;
}
static int w5100_spi_probe(struct spi_device *spi)
{
const struct spi_device_id *id = spi_get_device_id(spi);
const struct w5100_ops *ops;
int priv_size;
const void *mac = of_get_mac_address(spi->dev.of_node);
switch (id->driver_data) {
case W5100:
ops = &w5100_spi_ops;
priv_size = 0;
break;
case W5200:
ops = &w5200_ops;
priv_size = sizeof(struct w5200_spi_priv);
break;
case W5500:
ops = &w5500_ops;
priv_size = sizeof(struct w5500_spi_priv);
break;
default:
return -EINVAL;
}
return w5100_probe(&spi->dev, ops, priv_size, mac, spi->irq, -EINVAL);
}
static int w5100_spi_remove(struct spi_device *spi)
{
return w5100_remove(&spi->dev);
}
