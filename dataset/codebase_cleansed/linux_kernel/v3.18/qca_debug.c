static int
qcaspi_info_show(struct seq_file *s, void *what)
{
struct qcaspi *qca = s->private;
seq_printf(s, "RX buffer size : %lu\n",
(unsigned long)qca->buffer_size);
seq_puts(s, "TX ring state : ");
if (qca->txr.skb[qca->txr.head] == NULL)
seq_puts(s, "empty");
else if (qca->txr.skb[qca->txr.tail])
seq_puts(s, "full");
else
seq_puts(s, "in use");
seq_puts(s, "\n");
seq_printf(s, "TX ring size : %u\n",
qca->txr.size);
seq_printf(s, "Sync state : %u (",
(unsigned int)qca->sync);
switch (qca->sync) {
case QCASPI_SYNC_UNKNOWN:
seq_puts(s, "QCASPI_SYNC_UNKNOWN");
break;
case QCASPI_SYNC_RESET:
seq_puts(s, "QCASPI_SYNC_RESET");
break;
case QCASPI_SYNC_READY:
seq_puts(s, "QCASPI_SYNC_READY");
break;
default:
seq_puts(s, "INVALID");
break;
}
seq_puts(s, ")\n");
seq_printf(s, "IRQ : %d\n",
qca->spi_dev->irq);
seq_printf(s, "INTR REQ : %u\n",
qca->intr_req);
seq_printf(s, "INTR SVC : %u\n",
qca->intr_svc);
seq_printf(s, "SPI max speed : %lu\n",
(unsigned long)qca->spi_dev->max_speed_hz);
seq_printf(s, "SPI mode : %x\n",
qca->spi_dev->mode);
seq_printf(s, "SPI chip select : %u\n",
(unsigned int)qca->spi_dev->chip_select);
seq_printf(s, "SPI legacy mode : %u\n",
(unsigned int)qca->legacy_mode);
seq_printf(s, "SPI burst length : %u\n",
(unsigned int)qca->burst_len);
return 0;
}
static int
qcaspi_info_open(struct inode *inode, struct file *file)
{
return single_open(file, qcaspi_info_show, inode->i_private);
}
void
qcaspi_init_device_debugfs(struct qcaspi *qca)
{
struct dentry *device_root;
device_root = debugfs_create_dir(dev_name(&qca->net_dev->dev), NULL);
qca->device_root = device_root;
if (IS_ERR(device_root) || !device_root) {
pr_warn("failed to create debugfs directory for %s\n",
dev_name(&qca->net_dev->dev));
return;
}
debugfs_create_file("info", S_IFREG | S_IRUGO, device_root, qca,
&qcaspi_info_ops);
}
void
qcaspi_remove_device_debugfs(struct qcaspi *qca)
{
debugfs_remove_recursive(qca->device_root);
}
void
qcaspi_init_device_debugfs(struct qcaspi *qca)
{
}
void
qcaspi_remove_device_debugfs(struct qcaspi *qca)
{
}
static void
qcaspi_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *p)
{
struct qcaspi *qca = netdev_priv(dev);
strlcpy(p->driver, QCASPI_DRV_NAME, sizeof(p->driver));
strlcpy(p->version, QCASPI_DRV_VERSION, sizeof(p->version));
strlcpy(p->fw_version, "QCA7000", sizeof(p->fw_version));
strlcpy(p->bus_info, dev_name(&qca->spi_dev->dev),
sizeof(p->bus_info));
}
static int
qcaspi_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
cmd->transceiver = XCVR_INTERNAL;
cmd->supported = SUPPORTED_10baseT_Half;
ethtool_cmd_speed_set(cmd, SPEED_10);
cmd->duplex = DUPLEX_HALF;
cmd->port = PORT_OTHER;
cmd->autoneg = AUTONEG_DISABLE;
return 0;
}
static void
qcaspi_get_ethtool_stats(struct net_device *dev, struct ethtool_stats *estats, u64 *data)
{
struct qcaspi *qca = netdev_priv(dev);
struct qcaspi_stats *st = &qca->stats;
memcpy(data, st, ARRAY_SIZE(qcaspi_gstrings_stats) * sizeof(u64));
}
static void
qcaspi_get_strings(struct net_device *dev, u32 stringset, u8 *buf)
{
switch (stringset) {
case ETH_SS_STATS:
memcpy(buf, &qcaspi_gstrings_stats,
sizeof(qcaspi_gstrings_stats));
break;
default:
WARN_ON(1);
break;
}
}
static int
qcaspi_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return ARRAY_SIZE(qcaspi_gstrings_stats);
default:
return -EINVAL;
}
}
static int
qcaspi_get_regs_len(struct net_device *dev)
{
return sizeof(u32) * QCASPI_MAX_REGS;
}
static void
qcaspi_get_regs(struct net_device *dev, struct ethtool_regs *regs, void *p)
{
struct qcaspi *qca = netdev_priv(dev);
u32 *regs_buff = p;
unsigned int i;
regs->version = 1;
memset(regs_buff, 0, sizeof(u32) * QCASPI_MAX_REGS);
for (i = 0; i < ARRAY_SIZE(qcaspi_spi_regs); i++) {
u16 offset, value;
qcaspi_read_register(qca, qcaspi_spi_regs[i], &value);
offset = qcaspi_spi_regs[i] >> 8;
regs_buff[offset] = value;
}
}
static void
qcaspi_get_ringparam(struct net_device *dev, struct ethtool_ringparam *ring)
{
struct qcaspi *qca = netdev_priv(dev);
ring->rx_max_pending = 4;
ring->tx_max_pending = TX_RING_MAX_LEN;
ring->rx_pending = 4;
ring->tx_pending = qca->txr.count;
}
static int
qcaspi_set_ringparam(struct net_device *dev, struct ethtool_ringparam *ring)
{
struct qcaspi *qca = netdev_priv(dev);
if ((ring->rx_pending) ||
(ring->rx_mini_pending) ||
(ring->rx_jumbo_pending))
return -EINVAL;
if (netif_running(dev))
qcaspi_netdev_close(dev);
qca->txr.count = max_t(u32, ring->tx_pending, TX_RING_MIN_LEN);
qca->txr.count = min_t(u16, qca->txr.count, TX_RING_MAX_LEN);
if (netif_running(dev))
qcaspi_netdev_open(dev);
return 0;
}
void qcaspi_set_ethtool_ops(struct net_device *dev)
{
dev->ethtool_ops = &qcaspi_ethtool_ops;
}
