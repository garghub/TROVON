int mlx4_SET_VLAN_FLTR(struct mlx4_dev *dev, struct mlx4_en_priv *priv)
{
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_set_vlan_fltr_mbox *filter;
int i;
int j;
int index = 0;
u32 entry;
int err = 0;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
filter = mailbox->buf;
for (i = VLAN_FLTR_SIZE - 1; i >= 0; i--) {
entry = 0;
for (j = 0; j < 32; j++)
if (test_bit(index++, priv->active_vlans))
entry |= 1 << j;
filter->entry[i] = cpu_to_be32(entry);
}
err = mlx4_cmd(dev, mailbox->dma, priv->port, 0, MLX4_CMD_SET_VLAN_FLTR,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_WRAPPED);
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_en_QUERY_PORT(struct mlx4_en_dev *mdev, u8 port)
{
struct mlx4_en_query_port_context *qport_context;
struct mlx4_en_priv *priv = netdev_priv(mdev->pndev[port]);
struct mlx4_en_port_state *state = &priv->port_state;
struct mlx4_cmd_mailbox *mailbox;
int err;
mailbox = mlx4_alloc_cmd_mailbox(mdev->dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
err = mlx4_cmd_box(mdev->dev, 0, mailbox->dma, port, 0,
MLX4_CMD_QUERY_PORT, MLX4_CMD_TIME_CLASS_B,
MLX4_CMD_WRAPPED);
if (err)
goto out;
qport_context = mailbox->buf;
state->link_state = !!(qport_context->link_up & MLX4_EN_LINK_UP_MASK);
switch (qport_context->link_speed & MLX4_EN_SPEED_MASK) {
case MLX4_EN_100M_SPEED:
state->link_speed = SPEED_100;
break;
case MLX4_EN_1G_SPEED:
state->link_speed = SPEED_1000;
break;
case MLX4_EN_10G_SPEED_XAUI:
case MLX4_EN_10G_SPEED_XFI:
state->link_speed = SPEED_10000;
break;
case MLX4_EN_20G_SPEED:
state->link_speed = SPEED_20000;
break;
case MLX4_EN_40G_SPEED:
state->link_speed = SPEED_40000;
break;
case MLX4_EN_56G_SPEED:
state->link_speed = SPEED_56000;
break;
default:
state->link_speed = -1;
break;
}
state->transceiver = qport_context->transceiver;
state->flags = 0;
state->flags |= (qport_context->link_up & MLX4_EN_ANC_MASK) ?
MLX4_EN_PORT_ANC : 0;
state->flags |= (qport_context->autoneg & MLX4_EN_AUTONEG_MASK) ?
MLX4_EN_PORT_ANE : 0;
out:
mlx4_free_cmd_mailbox(mdev->dev, mailbox);
return err;
}
static unsigned long en_stats_adder(__be64 *start, __be64 *next, int num)
{
__be64 *curr = start;
unsigned long ret = 0;
int i;
int offset = next - start;
for (i = 0; i < num; i++) {
ret += be64_to_cpu(*curr);
curr += offset;
}
return ret;
}
int mlx4_en_DUMP_ETH_STATS(struct mlx4_en_dev *mdev, u8 port, u8 reset)
{
struct mlx4_en_stat_out_mbox *mlx4_en_stats;
struct mlx4_en_stat_out_flow_control_mbox *flowstats;
struct mlx4_en_priv *priv = netdev_priv(mdev->pndev[port]);
struct net_device_stats *stats = &priv->stats;
struct mlx4_cmd_mailbox *mailbox;
u64 in_mod = reset << 8 | port;
int err;
int i;
mailbox = mlx4_alloc_cmd_mailbox(mdev->dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
err = mlx4_cmd_box(mdev->dev, 0, mailbox->dma, in_mod, 0,
MLX4_CMD_DUMP_ETH_STATS, MLX4_CMD_TIME_CLASS_B,
MLX4_CMD_WRAPPED);
if (err)
goto out;
mlx4_en_stats = mailbox->buf;
spin_lock_bh(&priv->stats_lock);
stats->rx_packets = 0;
stats->rx_bytes = 0;
priv->port_stats.rx_chksum_good = 0;
priv->port_stats.rx_chksum_none = 0;
priv->port_stats.rx_chksum_complete = 0;
for (i = 0; i < priv->rx_ring_num; i++) {
stats->rx_packets += priv->rx_ring[i]->packets;
stats->rx_bytes += priv->rx_ring[i]->bytes;
priv->port_stats.rx_chksum_good += priv->rx_ring[i]->csum_ok;
priv->port_stats.rx_chksum_none += priv->rx_ring[i]->csum_none;
priv->port_stats.rx_chksum_complete += priv->rx_ring[i]->csum_complete;
}
stats->tx_packets = 0;
stats->tx_bytes = 0;
priv->port_stats.tx_chksum_offload = 0;
priv->port_stats.queue_stopped = 0;
priv->port_stats.wake_queue = 0;
priv->port_stats.tso_packets = 0;
priv->port_stats.xmit_more = 0;
for (i = 0; i < priv->tx_ring_num; i++) {
const struct mlx4_en_tx_ring *ring = priv->tx_ring[i];
stats->tx_packets += ring->packets;
stats->tx_bytes += ring->bytes;
priv->port_stats.tx_chksum_offload += ring->tx_csum;
priv->port_stats.queue_stopped += ring->queue_stopped;
priv->port_stats.wake_queue += ring->wake_queue;
priv->port_stats.tso_packets += ring->tso_packets;
priv->port_stats.xmit_more += ring->xmit_more;
}
stats->rx_errors = be64_to_cpu(mlx4_en_stats->PCS) +
be32_to_cpu(mlx4_en_stats->RJBBR) +
be32_to_cpu(mlx4_en_stats->RCRC) +
be32_to_cpu(mlx4_en_stats->RRUNT) +
be64_to_cpu(mlx4_en_stats->RInRangeLengthErr) +
be64_to_cpu(mlx4_en_stats->ROutRangeLengthErr) +
be32_to_cpu(mlx4_en_stats->RSHORT) +
en_stats_adder(&mlx4_en_stats->RGIANT_prio_0,
&mlx4_en_stats->RGIANT_prio_1,
NUM_PRIORITIES);
stats->tx_errors = en_stats_adder(&mlx4_en_stats->TGIANT_prio_0,
&mlx4_en_stats->TGIANT_prio_1,
NUM_PRIORITIES);
stats->multicast = en_stats_adder(&mlx4_en_stats->MCAST_prio_0,
&mlx4_en_stats->MCAST_prio_1,
NUM_PRIORITIES);
stats->collisions = 0;
stats->rx_dropped = be32_to_cpu(mlx4_en_stats->RDROP);
stats->rx_length_errors = be32_to_cpu(mlx4_en_stats->RdropLength);
stats->rx_over_errors = be32_to_cpu(mlx4_en_stats->RdropOvflw);
stats->rx_crc_errors = be32_to_cpu(mlx4_en_stats->RCRC);
stats->rx_frame_errors = 0;
stats->rx_fifo_errors = be32_to_cpu(mlx4_en_stats->RdropOvflw);
stats->rx_missed_errors = be32_to_cpu(mlx4_en_stats->RdropOvflw);
stats->tx_aborted_errors = 0;
stats->tx_carrier_errors = 0;
stats->tx_fifo_errors = 0;
stats->tx_heartbeat_errors = 0;
stats->tx_window_errors = 0;
stats->tx_dropped = be32_to_cpu(mlx4_en_stats->TDROP);
priv->pkstats.rx_multicast_packets = stats->multicast;
priv->pkstats.rx_broadcast_packets =
en_stats_adder(&mlx4_en_stats->RBCAST_prio_0,
&mlx4_en_stats->RBCAST_prio_1,
NUM_PRIORITIES);
priv->pkstats.rx_jabbers = be32_to_cpu(mlx4_en_stats->RJBBR);
priv->pkstats.rx_in_range_length_error =
be64_to_cpu(mlx4_en_stats->RInRangeLengthErr);
priv->pkstats.rx_out_range_length_error =
be64_to_cpu(mlx4_en_stats->ROutRangeLengthErr);
priv->pkstats.tx_multicast_packets =
en_stats_adder(&mlx4_en_stats->TMCAST_prio_0,
&mlx4_en_stats->TMCAST_prio_1,
NUM_PRIORITIES);
priv->pkstats.tx_broadcast_packets =
en_stats_adder(&mlx4_en_stats->TBCAST_prio_0,
&mlx4_en_stats->TBCAST_prio_1,
NUM_PRIORITIES);
priv->pkstats.rx_prio[0][0] = be64_to_cpu(mlx4_en_stats->RTOT_prio_0);
priv->pkstats.rx_prio[0][1] = be64_to_cpu(mlx4_en_stats->ROCT_prio_0);
priv->pkstats.rx_prio[1][0] = be64_to_cpu(mlx4_en_stats->RTOT_prio_1);
priv->pkstats.rx_prio[1][1] = be64_to_cpu(mlx4_en_stats->ROCT_prio_1);
priv->pkstats.rx_prio[2][0] = be64_to_cpu(mlx4_en_stats->RTOT_prio_2);
priv->pkstats.rx_prio[2][1] = be64_to_cpu(mlx4_en_stats->ROCT_prio_2);
priv->pkstats.rx_prio[3][0] = be64_to_cpu(mlx4_en_stats->RTOT_prio_3);
priv->pkstats.rx_prio[3][1] = be64_to_cpu(mlx4_en_stats->ROCT_prio_3);
priv->pkstats.rx_prio[4][0] = be64_to_cpu(mlx4_en_stats->RTOT_prio_4);
priv->pkstats.rx_prio[4][1] = be64_to_cpu(mlx4_en_stats->ROCT_prio_4);
priv->pkstats.rx_prio[5][0] = be64_to_cpu(mlx4_en_stats->RTOT_prio_5);
priv->pkstats.rx_prio[5][1] = be64_to_cpu(mlx4_en_stats->ROCT_prio_5);
priv->pkstats.rx_prio[6][0] = be64_to_cpu(mlx4_en_stats->RTOT_prio_6);
priv->pkstats.rx_prio[6][1] = be64_to_cpu(mlx4_en_stats->ROCT_prio_6);
priv->pkstats.rx_prio[7][0] = be64_to_cpu(mlx4_en_stats->RTOT_prio_7);
priv->pkstats.rx_prio[7][1] = be64_to_cpu(mlx4_en_stats->ROCT_prio_7);
priv->pkstats.rx_prio[8][0] = be64_to_cpu(mlx4_en_stats->RTOT_novlan);
priv->pkstats.rx_prio[8][1] = be64_to_cpu(mlx4_en_stats->ROCT_novlan);
priv->pkstats.tx_prio[0][0] = be64_to_cpu(mlx4_en_stats->TTOT_prio_0);
priv->pkstats.tx_prio[0][1] = be64_to_cpu(mlx4_en_stats->TOCT_prio_0);
priv->pkstats.tx_prio[1][0] = be64_to_cpu(mlx4_en_stats->TTOT_prio_1);
priv->pkstats.tx_prio[1][1] = be64_to_cpu(mlx4_en_stats->TOCT_prio_1);
priv->pkstats.tx_prio[2][0] = be64_to_cpu(mlx4_en_stats->TTOT_prio_2);
priv->pkstats.tx_prio[2][1] = be64_to_cpu(mlx4_en_stats->TOCT_prio_2);
priv->pkstats.tx_prio[3][0] = be64_to_cpu(mlx4_en_stats->TTOT_prio_3);
priv->pkstats.tx_prio[3][1] = be64_to_cpu(mlx4_en_stats->TOCT_prio_3);
priv->pkstats.tx_prio[4][0] = be64_to_cpu(mlx4_en_stats->TTOT_prio_4);
priv->pkstats.tx_prio[4][1] = be64_to_cpu(mlx4_en_stats->TOCT_prio_4);
priv->pkstats.tx_prio[5][0] = be64_to_cpu(mlx4_en_stats->TTOT_prio_5);
priv->pkstats.tx_prio[5][1] = be64_to_cpu(mlx4_en_stats->TOCT_prio_5);
priv->pkstats.tx_prio[6][0] = be64_to_cpu(mlx4_en_stats->TTOT_prio_6);
priv->pkstats.tx_prio[6][1] = be64_to_cpu(mlx4_en_stats->TOCT_prio_6);
priv->pkstats.tx_prio[7][0] = be64_to_cpu(mlx4_en_stats->TTOT_prio_7);
priv->pkstats.tx_prio[7][1] = be64_to_cpu(mlx4_en_stats->TOCT_prio_7);
priv->pkstats.tx_prio[8][0] = be64_to_cpu(mlx4_en_stats->TTOT_novlan);
priv->pkstats.tx_prio[8][1] = be64_to_cpu(mlx4_en_stats->TOCT_novlan);
spin_unlock_bh(&priv->stats_lock);
memset(mailbox->buf, 0xff, sizeof(*flowstats) * MLX4_NUM_PRIORITIES);
if (mdev->dev->caps.flags2 & MLX4_DEV_CAP_FLAG2_FLOWSTATS_EN) {
memset(mailbox->buf, 0,
sizeof(*flowstats) * MLX4_NUM_PRIORITIES);
err = mlx4_cmd_box(mdev->dev, 0, mailbox->dma,
in_mod | MLX4_DUMP_ETH_STATS_FLOW_CONTROL,
0, MLX4_CMD_DUMP_ETH_STATS,
MLX4_CMD_TIME_CLASS_B, MLX4_CMD_WRAPPED);
if (err)
goto out;
}
flowstats = mailbox->buf;
spin_lock_bh(&priv->stats_lock);
for (i = 0; i < MLX4_NUM_PRIORITIES; i++) {
priv->rx_priority_flowstats[i].rx_pause =
be64_to_cpu(flowstats[i].rx_pause);
priv->rx_priority_flowstats[i].rx_pause_duration =
be64_to_cpu(flowstats[i].rx_pause_duration);
priv->rx_priority_flowstats[i].rx_pause_transition =
be64_to_cpu(flowstats[i].rx_pause_transition);
priv->tx_priority_flowstats[i].tx_pause =
be64_to_cpu(flowstats[i].tx_pause);
priv->tx_priority_flowstats[i].tx_pause_duration =
be64_to_cpu(flowstats[i].tx_pause_duration);
priv->tx_priority_flowstats[i].tx_pause_transition =
be64_to_cpu(flowstats[i].tx_pause_transition);
}
priv->rx_flowstats.rx_pause =
be64_to_cpu(flowstats[0].rx_pause);
priv->rx_flowstats.rx_pause_duration =
be64_to_cpu(flowstats[0].rx_pause_duration);
priv->rx_flowstats.rx_pause_transition =
be64_to_cpu(flowstats[0].rx_pause_transition);
priv->tx_flowstats.tx_pause =
be64_to_cpu(flowstats[0].tx_pause);
priv->tx_flowstats.tx_pause_duration =
be64_to_cpu(flowstats[0].tx_pause_duration);
priv->tx_flowstats.tx_pause_transition =
be64_to_cpu(flowstats[0].tx_pause_transition);
spin_unlock_bh(&priv->stats_lock);
out:
mlx4_free_cmd_mailbox(mdev->dev, mailbox);
return err;
}
