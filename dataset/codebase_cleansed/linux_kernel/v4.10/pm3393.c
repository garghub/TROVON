static int pmread(struct cmac *cmac, u32 reg, u32 * data32)
{
t1_tpi_read(cmac->adapter, OFFSET(reg), data32);
return 0;
}
static int pmwrite(struct cmac *cmac, u32 reg, u32 data32)
{
t1_tpi_write(cmac->adapter, OFFSET(reg), data32);
return 0;
}
static int pm3393_reset(struct cmac *cmac)
{
return 0;
}
static int pm3393_interrupt_enable(struct cmac *cmac)
{
u32 pl_intr;
pmwrite(cmac, SUNI1x10GEXP_REG_SERDES_3125_INTERRUPT_ENABLE, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_XRF_INTERRUPT_ENABLE, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_XRF_DIAG_INTERRUPT_ENABLE, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_RXOAM_INTERRUPT_ENABLE, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_MSTAT_INTERRUPT_MASK_0, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_MSTAT_INTERRUPT_MASK_1, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_MSTAT_INTERRUPT_MASK_2, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_MSTAT_INTERRUPT_MASK_3, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_IFLX_FIFO_OVERFLOW_ENABLE, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_PL4ODP_INTERRUPT_MASK, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_XTEF_INTERRUPT_ENABLE, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_TXOAM_INTERRUPT_ENABLE, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_CONFIG_3, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_PL4IO_LOCK_DETECT_MASK, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_TXXG_CONFIG_3, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_PL4IDU_INTERRUPT_MASK, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_EFLX_FIFO_OVERFLOW_ERROR_ENABLE, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_GLOBAL_INTERRUPT_ENABLE,
0 );
pl_intr = readl(cmac->adapter->regs + A_PL_ENABLE);
pl_intr |= F_PL_INTR_EXT;
writel(pl_intr, cmac->adapter->regs + A_PL_ENABLE);
return 0;
}
static int pm3393_interrupt_disable(struct cmac *cmac)
{
u32 elmer;
pmwrite(cmac, SUNI1x10GEXP_REG_SERDES_3125_INTERRUPT_ENABLE, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_XRF_INTERRUPT_ENABLE, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_XRF_DIAG_INTERRUPT_ENABLE, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_RXOAM_INTERRUPT_ENABLE, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_MSTAT_INTERRUPT_MASK_0, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_MSTAT_INTERRUPT_MASK_1, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_MSTAT_INTERRUPT_MASK_2, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_MSTAT_INTERRUPT_MASK_3, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_IFLX_FIFO_OVERFLOW_ENABLE, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_PL4ODP_INTERRUPT_MASK, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_XTEF_INTERRUPT_ENABLE, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_TXOAM_INTERRUPT_ENABLE, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_CONFIG_3, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_PL4IO_LOCK_DETECT_MASK, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_TXXG_CONFIG_3, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_PL4IDU_INTERRUPT_MASK, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_EFLX_FIFO_OVERFLOW_ERROR_ENABLE, 0);
pmwrite(cmac, SUNI1x10GEXP_REG_GLOBAL_INTERRUPT_ENABLE, 0);
t1_tpi_read(cmac->adapter, A_ELMER0_INT_ENABLE, &elmer);
elmer &= ~ELMER0_GP_BIT1;
t1_tpi_write(cmac->adapter, A_ELMER0_INT_ENABLE, elmer);
return 0;
}
static int pm3393_interrupt_clear(struct cmac *cmac)
{
u32 elmer;
u32 pl_intr;
u32 val32;
pmread(cmac, SUNI1x10GEXP_REG_SERDES_3125_INTERRUPT_STATUS, &val32);
pmread(cmac, SUNI1x10GEXP_REG_XRF_INTERRUPT_STATUS, &val32);
pmread(cmac, SUNI1x10GEXP_REG_XRF_DIAG_INTERRUPT_STATUS, &val32);
pmread(cmac, SUNI1x10GEXP_REG_RXOAM_INTERRUPT_STATUS, &val32);
pmread(cmac, SUNI1x10GEXP_REG_PL4ODP_INTERRUPT, &val32);
pmread(cmac, SUNI1x10GEXP_REG_XTEF_INTERRUPT_STATUS, &val32);
pmread(cmac, SUNI1x10GEXP_REG_IFLX_FIFO_OVERFLOW_INTERRUPT, &val32);
pmread(cmac, SUNI1x10GEXP_REG_TXOAM_INTERRUPT_STATUS, &val32);
pmread(cmac, SUNI1x10GEXP_REG_RXXG_INTERRUPT, &val32);
pmread(cmac, SUNI1x10GEXP_REG_TXXG_INTERRUPT, &val32);
pmread(cmac, SUNI1x10GEXP_REG_PL4IDU_INTERRUPT, &val32);
pmread(cmac, SUNI1x10GEXP_REG_EFLX_FIFO_OVERFLOW_ERROR_INDICATION,
&val32);
pmread(cmac, SUNI1x10GEXP_REG_PL4IO_LOCK_DETECT_STATUS, &val32);
pmread(cmac, SUNI1x10GEXP_REG_PL4IO_LOCK_DETECT_CHANGE, &val32);
pmread(cmac, SUNI1x10GEXP_REG_MASTER_INTERRUPT_STATUS, &val32);
t1_tpi_read(cmac->adapter, A_ELMER0_INT_CAUSE, &elmer);
elmer |= ELMER0_GP_BIT1;
t1_tpi_write(cmac->adapter, A_ELMER0_INT_CAUSE, elmer);
pl_intr = readl(cmac->adapter->regs + A_PL_CAUSE);
pl_intr |= F_PL_INTR_EXT;
writel(pl_intr, cmac->adapter->regs + A_PL_CAUSE);
return 0;
}
static int pm3393_interrupt_handler(struct cmac *cmac)
{
u32 master_intr_status;
pmread(cmac, SUNI1x10GEXP_REG_MASTER_INTERRUPT_STATUS,
&master_intr_status);
if (netif_msg_intr(cmac->adapter))
dev_dbg(&cmac->adapter->pdev->dev, "PM3393 intr cause 0x%x\n",
master_intr_status);
pm3393_interrupt_clear(cmac);
return 0;
}
static int pm3393_enable(struct cmac *cmac, int which)
{
if (which & MAC_DIRECTION_RX)
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_CONFIG_1,
(RXXG_CONF1_VAL | SUNI1x10GEXP_BITMSK_RXXG_RXEN));
if (which & MAC_DIRECTION_TX) {
u32 val = TXXG_CONF1_VAL | SUNI1x10GEXP_BITMSK_TXXG_TXEN0;
if (cmac->instance->fc & PAUSE_RX)
val |= SUNI1x10GEXP_BITMSK_TXXG_FCRX;
if (cmac->instance->fc & PAUSE_TX)
val |= SUNI1x10GEXP_BITMSK_TXXG_FCTX;
pmwrite(cmac, SUNI1x10GEXP_REG_TXXG_CONFIG_1, val);
}
cmac->instance->enabled |= which;
return 0;
}
static int pm3393_enable_port(struct cmac *cmac, int which)
{
pmwrite(cmac, SUNI1x10GEXP_REG_MSTAT_CONTROL,
SUNI1x10GEXP_BITMSK_MSTAT_CLEAR);
udelay(2);
memset(&cmac->stats, 0, sizeof(struct cmac_statistics));
pm3393_enable(cmac, which);
t1_link_changed(cmac->adapter, 0);
return 0;
}
static int pm3393_disable(struct cmac *cmac, int which)
{
if (which & MAC_DIRECTION_RX)
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_CONFIG_1, RXXG_CONF1_VAL);
if (which & MAC_DIRECTION_TX)
pmwrite(cmac, SUNI1x10GEXP_REG_TXXG_CONFIG_1, TXXG_CONF1_VAL);
udelay(20);
cmac->instance->enabled &= ~which;
return 0;
}
static int pm3393_loopback_enable(struct cmac *cmac)
{
return 0;
}
static int pm3393_loopback_disable(struct cmac *cmac)
{
return 0;
}
static int pm3393_set_mtu(struct cmac *cmac, int mtu)
{
int enabled = cmac->instance->enabled;
mtu += ETH_HLEN + ETH_FCS_LEN;
if (enabled)
pm3393_disable(cmac, MAC_DIRECTION_RX | MAC_DIRECTION_TX);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_MAX_FRAME_LENGTH, mtu);
pmwrite(cmac, SUNI1x10GEXP_REG_TXXG_MAX_FRAME_SIZE, mtu);
if (enabled)
pm3393_enable(cmac, enabled);
return 0;
}
static int pm3393_set_rx_mode(struct cmac *cmac, struct t1_rx_mode *rm)
{
int enabled = cmac->instance->enabled & MAC_DIRECTION_RX;
u32 rx_mode;
if (enabled)
pm3393_disable(cmac, MAC_DIRECTION_RX);
pmread(cmac, SUNI1x10GEXP_REG_RXXG_ADDRESS_FILTER_CONTROL_2, &rx_mode);
rx_mode &= ~(SUNI1x10GEXP_BITMSK_RXXG_PMODE |
SUNI1x10GEXP_BITMSK_RXXG_MHASH_EN);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_ADDRESS_FILTER_CONTROL_2,
(u16)rx_mode);
if (t1_rx_mode_promisc(rm)) {
rx_mode |= SUNI1x10GEXP_BITMSK_RXXG_PMODE;
}
if (t1_rx_mode_allmulti(rm)) {
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_MULTICAST_HASH_LOW, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_MULTICAST_HASH_MIDLOW, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_MULTICAST_HASH_MIDHIGH, 0xffff);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_MULTICAST_HASH_HIGH, 0xffff);
rx_mode |= SUNI1x10GEXP_BITMSK_RXXG_MHASH_EN;
} else if (t1_rx_mode_mc_cnt(rm)) {
struct netdev_hw_addr *ha;
int bit;
u16 mc_filter[4] = { 0, };
netdev_for_each_mc_addr(ha, t1_get_netdev(rm)) {
bit = (ether_crc(ETH_ALEN, ha->addr) >> 23) & 0x3f;
mc_filter[bit >> 4] |= 1 << (bit & 0xf);
}
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_MULTICAST_HASH_LOW, mc_filter[0]);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_MULTICAST_HASH_MIDLOW, mc_filter[1]);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_MULTICAST_HASH_MIDHIGH, mc_filter[2]);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_MULTICAST_HASH_HIGH, mc_filter[3]);
rx_mode |= SUNI1x10GEXP_BITMSK_RXXG_MHASH_EN;
}
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_ADDRESS_FILTER_CONTROL_2, (u16)rx_mode);
if (enabled)
pm3393_enable(cmac, MAC_DIRECTION_RX);
return 0;
}
static int pm3393_get_speed_duplex_fc(struct cmac *cmac, int *speed,
int *duplex, int *fc)
{
if (speed)
*speed = SPEED_10000;
if (duplex)
*duplex = DUPLEX_FULL;
if (fc)
*fc = cmac->instance->fc;
return 0;
}
static int pm3393_set_speed_duplex_fc(struct cmac *cmac, int speed, int duplex,
int fc)
{
if (speed >= 0 && speed != SPEED_10000)
return -1;
if (duplex >= 0 && duplex != DUPLEX_FULL)
return -1;
if (fc & ~(PAUSE_TX | PAUSE_RX))
return -1;
if (fc != cmac->instance->fc) {
cmac->instance->fc = (u8) fc;
if (cmac->instance->enabled & MAC_DIRECTION_TX)
pm3393_enable(cmac, MAC_DIRECTION_TX);
}
return 0;
}
static const struct cmac_statistics *pm3393_update_statistics(struct cmac *mac,
int flag)
{
u64 ro;
u32 val0, val1, val2, val3;
pmwrite(mac, SUNI1x10GEXP_REG_MSTAT_CONTROL,
SUNI1x10GEXP_BITMSK_MSTAT_SNAP);
pmread(mac, SUNI1x10GEXP_REG_MSTAT_COUNTER_ROLLOVER_0, &val0);
pmread(mac, SUNI1x10GEXP_REG_MSTAT_COUNTER_ROLLOVER_1, &val1);
pmread(mac, SUNI1x10GEXP_REG_MSTAT_COUNTER_ROLLOVER_2, &val2);
pmread(mac, SUNI1x10GEXP_REG_MSTAT_COUNTER_ROLLOVER_3, &val3);
ro = ((u64)val0 & 0xffff) | (((u64)val1 & 0xffff) << 16) |
(((u64)val2 & 0xffff) << 32) | (((u64)val3 & 0xffff) << 48);
RMON_UPDATE(mac, RxOctetsReceivedOK, RxOctetsOK);
RMON_UPDATE(mac, RxUnicastFramesReceivedOK, RxUnicastFramesOK);
RMON_UPDATE(mac, RxMulticastFramesReceivedOK, RxMulticastFramesOK);
RMON_UPDATE(mac, RxBroadcastFramesReceivedOK, RxBroadcastFramesOK);
RMON_UPDATE(mac, RxPAUSEMACCtrlFramesReceived, RxPauseFrames);
RMON_UPDATE(mac, RxFrameCheckSequenceErrors, RxFCSErrors);
RMON_UPDATE(mac, RxFramesLostDueToInternalMACErrors,
RxInternalMACRcvError);
RMON_UPDATE(mac, RxSymbolErrors, RxSymbolErrors);
RMON_UPDATE(mac, RxInRangeLengthErrors, RxInRangeLengthErrors);
RMON_UPDATE(mac, RxFramesTooLongErrors , RxFrameTooLongErrors);
RMON_UPDATE(mac, RxJabbers, RxJabberErrors);
RMON_UPDATE(mac, RxFragments, RxRuntErrors);
RMON_UPDATE(mac, RxUndersizedFrames, RxRuntErrors);
RMON_UPDATE(mac, RxJumboFramesReceivedOK, RxJumboFramesOK);
RMON_UPDATE(mac, RxJumboOctetsReceivedOK, RxJumboOctetsOK);
RMON_UPDATE(mac, TxOctetsTransmittedOK, TxOctetsOK);
RMON_UPDATE(mac, TxFramesLostDueToInternalMACTransmissionError,
TxInternalMACXmitError);
RMON_UPDATE(mac, TxTransmitSystemError, TxFCSErrors);
RMON_UPDATE(mac, TxUnicastFramesTransmittedOK, TxUnicastFramesOK);
RMON_UPDATE(mac, TxMulticastFramesTransmittedOK, TxMulticastFramesOK);
RMON_UPDATE(mac, TxBroadcastFramesTransmittedOK, TxBroadcastFramesOK);
RMON_UPDATE(mac, TxPAUSEMACCtrlFramesTransmitted, TxPauseFrames);
RMON_UPDATE(mac, TxJumboFramesReceivedOK, TxJumboFramesOK);
RMON_UPDATE(mac, TxJumboOctetsReceivedOK, TxJumboOctetsOK);
return &mac->stats;
}
static int pm3393_macaddress_get(struct cmac *cmac, u8 mac_addr[6])
{
memcpy(mac_addr, cmac->instance->mac_addr, ETH_ALEN);
return 0;
}
static int pm3393_macaddress_set(struct cmac *cmac, u8 ma[6])
{
u32 val, lo, mid, hi, enabled = cmac->instance->enabled;
memcpy(cmac->instance->mac_addr, ma, ETH_ALEN);
lo = ((u32) ma[1] << 8) | (u32) ma[0];
mid = ((u32) ma[3] << 8) | (u32) ma[2];
hi = ((u32) ma[5] << 8) | (u32) ma[4];
if (enabled)
pm3393_disable(cmac, MAC_DIRECTION_RX | MAC_DIRECTION_TX);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_SA_15_0, lo);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_SA_31_16, mid);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_SA_47_32, hi);
pmwrite(cmac, SUNI1x10GEXP_REG_TXXG_SA_15_0, lo);
pmwrite(cmac, SUNI1x10GEXP_REG_TXXG_SA_31_16, mid);
pmwrite(cmac, SUNI1x10GEXP_REG_TXXG_SA_47_32, hi);
pmread(cmac, SUNI1x10GEXP_REG_RXXG_ADDRESS_FILTER_CONTROL_0, &val);
val &= 0xff0f;
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_ADDRESS_FILTER_CONTROL_0, val);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_EXACT_MATCH_ADDR_1_LOW, lo);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_EXACT_MATCH_ADDR_1_MID, mid);
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_EXACT_MATCH_ADDR_1_HIGH, hi);
val |= 0x0090;
pmwrite(cmac, SUNI1x10GEXP_REG_RXXG_ADDRESS_FILTER_CONTROL_0, val);
if (enabled)
pm3393_enable(cmac, enabled);
return 0;
}
static void pm3393_destroy(struct cmac *cmac)
{
kfree(cmac);
}
static struct cmac *pm3393_mac_create(adapter_t *adapter, int index)
{
struct cmac *cmac;
cmac = kzalloc(sizeof(*cmac) + sizeof(cmac_instance), GFP_KERNEL);
if (!cmac)
return NULL;
cmac->ops = &pm3393_ops;
cmac->instance = (cmac_instance *) (cmac + 1);
cmac->adapter = adapter;
cmac->instance->fc = PAUSE_TX | PAUSE_RX;
t1_tpi_write(adapter, OFFSET(0x0001), 0x00008000);
t1_tpi_write(adapter, OFFSET(0x0001), 0x00000000);
t1_tpi_write(adapter, OFFSET(0x2308), 0x00009800);
t1_tpi_write(adapter, OFFSET(0x2305), 0x00001001);
t1_tpi_write(adapter, OFFSET(0x2320), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x2321), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x2322), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x2323), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x2324), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x2325), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x2326), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x2327), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x2328), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x2329), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x232a), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x232b), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x232c), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x232d), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x232e), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x232f), 0x00008800);
t1_tpi_write(adapter, OFFSET(0x230d), 0x00009c00);
t1_tpi_write(adapter, OFFSET(0x2304), 0x00000202);
t1_tpi_write(adapter, OFFSET(0x3200), 0x00008080);
t1_tpi_write(adapter, OFFSET(0x3210), 0x00000000);
t1_tpi_write(adapter, OFFSET(0x3203), 0x00000000);
t1_tpi_write(adapter, OFFSET(0x3204), 0x00000040);
t1_tpi_write(adapter, OFFSET(0x3205), 0x000002cc);
t1_tpi_write(adapter, OFFSET(0x3206), 0x00000199);
t1_tpi_write(adapter, OFFSET(0x3207), 0x00000240);
t1_tpi_write(adapter, OFFSET(0x3202), 0x00000000);
t1_tpi_write(adapter, OFFSET(0x3210), 0x00000001);
t1_tpi_write(adapter, OFFSET(0x3208), 0x0000ffff);
t1_tpi_write(adapter, OFFSET(0x320a), 0x0000ffff);
t1_tpi_write(adapter, OFFSET(0x320c), 0x0000ffff);
t1_tpi_write(adapter, OFFSET(0x320e), 0x0000ffff);
t1_tpi_write(adapter, OFFSET(0x2200), 0x0000c000);
t1_tpi_write(adapter, OFFSET(0x2201), 0x00000000);
t1_tpi_write(adapter, OFFSET(0x220e), 0x00000000);
t1_tpi_write(adapter, OFFSET(0x220f), 0x00000100);
t1_tpi_write(adapter, OFFSET(0x2210), 0x00000c00);
t1_tpi_write(adapter, OFFSET(0x2211), 0x00000599);
t1_tpi_write(adapter, OFFSET(0x220d), 0x00000000);
t1_tpi_write(adapter, OFFSET(0x2201), 0x00000001);
t1_tpi_write(adapter, OFFSET(0x2203), 0x0000ffff);
t1_tpi_write(adapter, OFFSET(0x2205), 0x0000ffff);
t1_tpi_write(adapter, OFFSET(0x2209), 0x0000ffff);
t1_tpi_write(adapter, OFFSET(0x2241), 0xfffffffe);
t1_tpi_write(adapter, OFFSET(0x2242), 0x0000ffff);
t1_tpi_write(adapter, OFFSET(0x2243), 0x00000008);
t1_tpi_write(adapter, OFFSET(0x2244), 0x00000008);
t1_tpi_write(adapter, OFFSET(0x2245), 0x00000008);
t1_tpi_write(adapter, OFFSET(0x2240), 0x00000005);
t1_tpi_write(adapter, OFFSET(0x2280), 0x00002103);
t1_tpi_write(adapter, OFFSET(0x2284), 0x00000000);
t1_tpi_write(adapter, OFFSET(0x3280), 0x00000087);
t1_tpi_write(adapter, OFFSET(0x3282), 0x0000001f);
t1_tpi_write(adapter, OFFSET(0x3040), 0x0c32);
t1_tpi_write(adapter, OFFSET(0x304d), 0x8000);
t1_tpi_write(adapter, OFFSET(0x2040), 0x059c);
t1_tpi_write(adapter, OFFSET(0x2049), 0x0001);
t1_tpi_write(adapter, OFFSET(0x2070), 0x0000);
t1_tpi_write(adapter, OFFSET(0x206e), 0x0000);
t1_tpi_write(adapter, OFFSET(0x204a), 0xffff);
t1_tpi_write(adapter, OFFSET(0x204b), 0xffff);
t1_tpi_write(adapter, OFFSET(0x204c), 0xffff);
t1_tpi_write(adapter, OFFSET(0x206e), 0x0009);
t1_tpi_write(adapter, OFFSET(0x0003), 0x0000);
t1_tpi_write(adapter, OFFSET(0x0100), 0x0ff0);
t1_tpi_write(adapter, OFFSET(0x0101), 0x0f0f);
return cmac;
}
static int pm3393_mac_reset(adapter_t * adapter)
{
u32 val;
u32 x;
u32 is_pl4_reset_finished;
u32 is_pl4_outof_lock;
u32 is_xaui_mabc_pll_locked;
u32 successful_reset;
int i;
successful_reset = 0;
for (i = 0; i < 3 && !successful_reset; i++) {
t1_tpi_read(adapter, A_ELMER0_GPO, &val);
val &= ~1;
t1_tpi_write(adapter, A_ELMER0_GPO, val);
msleep(1);
msleep(1);
msleep(2 );
val |= 1;
t1_tpi_write(adapter, A_ELMER0_GPO, val);
msleep(15 );
msleep(1);
t1_tpi_read(adapter, OFFSET(SUNI1x10GEXP_REG_DEVICE_STATUS), &val);
is_pl4_reset_finished = (val & SUNI1x10GEXP_BITMSK_TOP_EXPIRED);
x = (SUNI1x10GEXP_BITMSK_TOP_PL4_ID_DOOL
|
SUNI1x10GEXP_BITMSK_TOP_PL4_ID_ROOL |
SUNI1x10GEXP_BITMSK_TOP_PL4_IS_ROOL |
SUNI1x10GEXP_BITMSK_TOP_PL4_OUT_ROOL);
is_pl4_outof_lock = (val & x);
is_xaui_mabc_pll_locked =
(val & SUNI1x10GEXP_BITMSK_TOP_SXRA_EXPIRED);
successful_reset = (is_pl4_reset_finished && !is_pl4_outof_lock
&& is_xaui_mabc_pll_locked);
if (netif_msg_hw(adapter))
dev_dbg(&adapter->pdev->dev,
"PM3393 HW reset %d: pl4_reset 0x%x, val 0x%x, "
"is_pl4_outof_lock 0x%x, xaui_locked 0x%x\n",
i, is_pl4_reset_finished, val,
is_pl4_outof_lock, is_xaui_mabc_pll_locked);
}
return successful_reset ? 0 : 1;
}
