static void set_dflts(struct dtsec_cfg *cfg)
{
cfg->halfdup_retransmit = DEFAULT_HALFDUP_RETRANSMIT;
cfg->halfdup_coll_window = DEFAULT_HALFDUP_COLL_WINDOW;
cfg->tx_pad_crc = true;
cfg->tx_pause_time = DEFAULT_TX_PAUSE_TIME;
cfg->rx_prepend = DEFAULT_RX_PREPEND;
cfg->ptp_tsu_en = true;
cfg->ptp_exception_en = true;
cfg->preamble_len = DEFAULT_PREAMBLE_LEN;
cfg->tx_pause_time_extd = DEFAULT_TX_PAUSE_TIME_EXTD;
cfg->non_back_to_back_ipg1 = DEFAULT_NON_BACK_TO_BACK_IPG1;
cfg->non_back_to_back_ipg2 = DEFAULT_NON_BACK_TO_BACK_IPG2;
cfg->min_ifg_enforcement = DEFAULT_MIN_IFG_ENFORCEMENT;
cfg->back_to_back_ipg = DEFAULT_BACK_TO_BACK_IPG;
cfg->maximum_frame = DEFAULT_MAXIMUM_FRAME;
}
static int init(struct dtsec_regs __iomem *regs, struct dtsec_cfg *cfg,
phy_interface_t iface, u16 iface_speed, u8 *macaddr,
u32 exception_mask, u8 tbi_addr)
{
bool is_rgmii, is_sgmii, is_qsgmii;
int i;
u32 tmp;
iowrite32be(MACCFG1_SOFT_RESET, &regs->maccfg1);
iowrite32be(0, &regs->maccfg1);
tmp = ioread32be(&regs->tsec_id2);
if (iface == PHY_INTERFACE_MODE_RGMII ||
iface == PHY_INTERFACE_MODE_RGMII_ID ||
iface == PHY_INTERFACE_MODE_RGMII_RXID ||
iface == PHY_INTERFACE_MODE_RGMII_TXID ||
iface == PHY_INTERFACE_MODE_RMII)
if (tmp & DTSEC_ID2_INT_REDUCED_OFF)
return -EINVAL;
if (iface == PHY_INTERFACE_MODE_SGMII ||
iface == PHY_INTERFACE_MODE_MII)
if (tmp & DTSEC_ID2_INT_REDUCED_OFF)
return -EINVAL;
is_rgmii = iface == PHY_INTERFACE_MODE_RGMII ||
iface == PHY_INTERFACE_MODE_RGMII_ID ||
iface == PHY_INTERFACE_MODE_RGMII_RXID ||
iface == PHY_INTERFACE_MODE_RGMII_TXID;
is_sgmii = iface == PHY_INTERFACE_MODE_SGMII;
is_qsgmii = iface == PHY_INTERFACE_MODE_QSGMII;
tmp = 0;
if (is_rgmii || iface == PHY_INTERFACE_MODE_GMII)
tmp |= DTSEC_ECNTRL_GMIIM;
if (is_sgmii)
tmp |= (DTSEC_ECNTRL_SGMIIM | DTSEC_ECNTRL_TBIM);
if (is_qsgmii)
tmp |= (DTSEC_ECNTRL_SGMIIM | DTSEC_ECNTRL_TBIM |
DTSEC_ECNTRL_QSGMIIM);
if (is_rgmii)
tmp |= DTSEC_ECNTRL_RPM;
if (iface_speed == SPEED_100)
tmp |= DTSEC_ECNTRL_R100M;
iowrite32be(tmp, &regs->ecntrl);
tmp = 0;
if (cfg->tx_pause_time)
tmp |= cfg->tx_pause_time;
if (cfg->tx_pause_time_extd)
tmp |= cfg->tx_pause_time_extd << PTV_PTE_SHIFT;
iowrite32be(tmp, &regs->ptv);
tmp = 0;
tmp |= (cfg->rx_prepend << RCTRL_PAL_SHIFT) & RCTRL_PAL_MASK;
tmp |= RCTRL_RSF;
iowrite32be(tmp, &regs->rctrl);
iowrite32be(tbi_addr, &regs->tbipa);
iowrite32be(0, &regs->tmr_ctrl);
if (cfg->ptp_tsu_en) {
tmp = 0;
tmp |= TMR_PEVENT_TSRE;
iowrite32be(tmp, &regs->tmr_pevent);
if (cfg->ptp_exception_en) {
tmp = 0;
tmp |= TMR_PEMASK_TSREEN;
iowrite32be(tmp, &regs->tmr_pemask);
}
}
tmp = 0;
tmp |= MACCFG1_RX_FLOW;
tmp |= MACCFG1_TX_FLOW;
iowrite32be(tmp, &regs->maccfg1);
tmp = 0;
if (iface_speed < SPEED_1000)
tmp |= MACCFG2_NIBBLE_MODE;
else if (iface_speed == SPEED_1000)
tmp |= MACCFG2_BYTE_MODE;
tmp |= (cfg->preamble_len << MACCFG2_PREAMBLE_LENGTH_SHIFT) &
MACCFG2_PREAMBLE_LENGTH_MASK;
if (cfg->tx_pad_crc)
tmp |= MACCFG2_PAD_CRC_EN;
tmp |= MACCFG2_FULL_DUPLEX;
iowrite32be(tmp, &regs->maccfg2);
tmp = (((cfg->non_back_to_back_ipg1 <<
IPGIFG_NON_BACK_TO_BACK_IPG_1_SHIFT)
& IPGIFG_NON_BACK_TO_BACK_IPG_1)
| ((cfg->non_back_to_back_ipg2 <<
IPGIFG_NON_BACK_TO_BACK_IPG_2_SHIFT)
& IPGIFG_NON_BACK_TO_BACK_IPG_2)
| ((cfg->min_ifg_enforcement << IPGIFG_MIN_IFG_ENFORCEMENT_SHIFT)
& IPGIFG_MIN_IFG_ENFORCEMENT)
| (cfg->back_to_back_ipg & IPGIFG_BACK_TO_BACK_IPG));
iowrite32be(tmp, &regs->ipgifg);
tmp = 0;
tmp |= HAFDUP_EXCESS_DEFER;
tmp |= ((cfg->halfdup_retransmit << HAFDUP_RETRANSMISSION_MAX_SHIFT)
& HAFDUP_RETRANSMISSION_MAX);
tmp |= (cfg->halfdup_coll_window & HAFDUP_COLLISION_WINDOW);
iowrite32be(tmp, &regs->hafdup);
iowrite32be(cfg->maximum_frame, &regs->maxfrm);
iowrite32be(0xffffffff, &regs->cam1);
iowrite32be(0xffffffff, &regs->cam2);
iowrite32be(exception_mask, &regs->imask);
iowrite32be(0xffffffff, &regs->ievent);
tmp = (u32)((macaddr[5] << 24) |
(macaddr[4] << 16) | (macaddr[3] << 8) | macaddr[2]);
iowrite32be(tmp, &regs->macstnaddr1);
tmp = (u32)((macaddr[1] << 24) | (macaddr[0] << 16));
iowrite32be(tmp, &regs->macstnaddr2);
for (i = 0; i < NUM_OF_HASH_REGS; i++) {
iowrite32be(0, &regs->igaddr[i]);
iowrite32be(0, &regs->gaddr[i]);
}
return 0;
}
static void set_mac_address(struct dtsec_regs __iomem *regs, u8 *adr)
{
u32 tmp;
tmp = (u32)((adr[5] << 24) |
(adr[4] << 16) | (adr[3] << 8) | adr[2]);
iowrite32be(tmp, &regs->macstnaddr1);
tmp = (u32)((adr[1] << 24) | (adr[0] << 16));
iowrite32be(tmp, &regs->macstnaddr2);
}
static void set_bucket(struct dtsec_regs __iomem *regs, int bucket,
bool enable)
{
int reg_idx = (bucket >> 5) & 0xf;
int bit_idx = bucket & 0x1f;
u32 bit_mask = 0x80000000 >> bit_idx;
u32 __iomem *reg;
if (reg_idx > 7)
reg = &regs->gaddr[reg_idx - 8];
else
reg = &regs->igaddr[reg_idx];
if (enable)
iowrite32be(ioread32be(reg) | bit_mask, reg);
else
iowrite32be(ioread32be(reg) & (~bit_mask), reg);
}
static int check_init_parameters(struct fman_mac *dtsec)
{
if (dtsec->max_speed >= SPEED_10000) {
pr_err("1G MAC driver supports 1G or lower speeds\n");
return -EINVAL;
}
if (dtsec->addr == 0) {
pr_err("Ethernet MAC Must have a valid MAC Address\n");
return -EINVAL;
}
if ((dtsec->dtsec_drv_param)->rx_prepend >
MAX_PACKET_ALIGNMENT) {
pr_err("packetAlignmentPadding can't be > than %d\n",
MAX_PACKET_ALIGNMENT);
return -EINVAL;
}
if (((dtsec->dtsec_drv_param)->non_back_to_back_ipg1 >
MAX_INTER_PACKET_GAP) ||
((dtsec->dtsec_drv_param)->non_back_to_back_ipg2 >
MAX_INTER_PACKET_GAP) ||
((dtsec->dtsec_drv_param)->back_to_back_ipg >
MAX_INTER_PACKET_GAP)) {
pr_err("Inter packet gap can't be greater than %d\n",
MAX_INTER_PACKET_GAP);
return -EINVAL;
}
if ((dtsec->dtsec_drv_param)->halfdup_retransmit >
MAX_RETRANSMISSION) {
pr_err("maxRetransmission can't be greater than %d\n",
MAX_RETRANSMISSION);
return -EINVAL;
}
if ((dtsec->dtsec_drv_param)->halfdup_coll_window >
MAX_COLLISION_WINDOW) {
pr_err("collisionWindow can't be greater than %d\n",
MAX_COLLISION_WINDOW);
return -EINVAL;
}
if (!dtsec->exception_cb) {
pr_err("uninitialized exception_cb\n");
return -EINVAL;
}
if (!dtsec->event_cb) {
pr_err("uninitialized event_cb\n");
return -EINVAL;
}
return 0;
}
static int get_exception_flag(enum fman_mac_exceptions exception)
{
u32 bit_mask;
switch (exception) {
case FM_MAC_EX_1G_BAB_RX:
bit_mask = DTSEC_IMASK_BREN;
break;
case FM_MAC_EX_1G_RX_CTL:
bit_mask = DTSEC_IMASK_RXCEN;
break;
case FM_MAC_EX_1G_GRATEFUL_TX_STP_COMPLET:
bit_mask = DTSEC_IMASK_GTSCEN;
break;
case FM_MAC_EX_1G_BAB_TX:
bit_mask = DTSEC_IMASK_BTEN;
break;
case FM_MAC_EX_1G_TX_CTL:
bit_mask = DTSEC_IMASK_TXCEN;
break;
case FM_MAC_EX_1G_TX_ERR:
bit_mask = DTSEC_IMASK_TXEEN;
break;
case FM_MAC_EX_1G_LATE_COL:
bit_mask = DTSEC_IMASK_LCEN;
break;
case FM_MAC_EX_1G_COL_RET_LMT:
bit_mask = DTSEC_IMASK_CRLEN;
break;
case FM_MAC_EX_1G_TX_FIFO_UNDRN:
bit_mask = DTSEC_IMASK_XFUNEN;
break;
case FM_MAC_EX_1G_MAG_PCKT:
bit_mask = DTSEC_IMASK_MAGEN;
break;
case FM_MAC_EX_1G_MII_MNG_RD_COMPLET:
bit_mask = DTSEC_IMASK_MMRDEN;
break;
case FM_MAC_EX_1G_MII_MNG_WR_COMPLET:
bit_mask = DTSEC_IMASK_MMWREN;
break;
case FM_MAC_EX_1G_GRATEFUL_RX_STP_COMPLET:
bit_mask = DTSEC_IMASK_GRSCEN;
break;
case FM_MAC_EX_1G_DATA_ERR:
bit_mask = DTSEC_IMASK_TDPEEN;
break;
case FM_MAC_EX_1G_RX_MIB_CNT_OVFL:
bit_mask = DTSEC_IMASK_MSROEN;
break;
default:
bit_mask = 0;
break;
}
return bit_mask;
}
static bool is_init_done(struct dtsec_cfg *dtsec_drv_params)
{
if (!dtsec_drv_params)
return true;
return false;
}
static u16 dtsec_get_max_frame_length(struct fman_mac *dtsec)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
if (is_init_done(dtsec->dtsec_drv_param))
return 0;
return (u16)ioread32be(&regs->maxfrm);
}
static void dtsec_isr(void *handle)
{
struct fman_mac *dtsec = (struct fman_mac *)handle;
struct dtsec_regs __iomem *regs = dtsec->regs;
u32 event;
event = ioread32be(&regs->ievent) &
(u32)(~(DTSEC_IMASK_MMRDEN | DTSEC_IMASK_MMWREN));
event &= ioread32be(&regs->imask);
iowrite32be(event, &regs->ievent);
if (event & DTSEC_IMASK_BREN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_BAB_RX);
if (event & DTSEC_IMASK_RXCEN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_RX_CTL);
if (event & DTSEC_IMASK_GTSCEN)
dtsec->exception_cb(dtsec->dev_id,
FM_MAC_EX_1G_GRATEFUL_TX_STP_COMPLET);
if (event & DTSEC_IMASK_BTEN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_BAB_TX);
if (event & DTSEC_IMASK_TXCEN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_TX_CTL);
if (event & DTSEC_IMASK_TXEEN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_TX_ERR);
if (event & DTSEC_IMASK_LCEN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_LATE_COL);
if (event & DTSEC_IMASK_CRLEN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_COL_RET_LMT);
if (event & DTSEC_IMASK_XFUNEN) {
if (dtsec->fm_rev_info.major == 2) {
u32 tpkt1, tmp_reg1, tpkt2, tmp_reg2, i;
tpkt1 = ioread32be(&regs->tpkt);
tmp_reg1 = ioread32be(&regs->reserved02c0[27]);
if ((tmp_reg1 & 0x007F0000) !=
(tmp_reg1 & 0x0000007F)) {
usleep_range((u32)(min
(dtsec_get_max_frame_length(dtsec) *
16 / 1000, 1)), (u32)
(min(dtsec_get_max_frame_length
(dtsec) * 16 / 1000, 1) + 1));
}
tpkt2 = ioread32be(&regs->tpkt);
tmp_reg2 = ioread32be(&regs->reserved02c0[27]);
if ((tpkt1 == tpkt2) && ((tmp_reg1 & 0x007F0000) ==
(tmp_reg2 & 0x007F0000))) {
iowrite32be(ioread32be(&regs->rctrl) |
RCTRL_GRS, &regs->rctrl);
for (i = 0; i < 100; i++) {
if (ioread32be(&regs->ievent) &
DTSEC_IMASK_GRSCEN)
break;
udelay(1);
}
if (ioread32be(&regs->ievent) &
DTSEC_IMASK_GRSCEN)
iowrite32be(DTSEC_IMASK_GRSCEN,
&regs->ievent);
else
pr_debug("Rx lockup due to Tx lockup\n");
fman_reset_mac(dtsec->fm, dtsec->mac_id);
udelay(1);
}
}
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_TX_FIFO_UNDRN);
}
if (event & DTSEC_IMASK_MAGEN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_MAG_PCKT);
if (event & DTSEC_IMASK_GRSCEN)
dtsec->exception_cb(dtsec->dev_id,
FM_MAC_EX_1G_GRATEFUL_RX_STP_COMPLET);
if (event & DTSEC_IMASK_TDPEEN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_EX_1G_DATA_ERR);
if (event & DTSEC_IMASK_RDPEEN)
dtsec->exception_cb(dtsec->dev_id, FM_MAC_1G_RX_DATA_ERR);
WARN_ON(event & DTSEC_IMASK_ABRTEN);
WARN_ON(event & DTSEC_IMASK_IFERREN);
}
static void dtsec_1588_isr(void *handle)
{
struct fman_mac *dtsec = (struct fman_mac *)handle;
struct dtsec_regs __iomem *regs = dtsec->regs;
u32 event;
if (dtsec->ptp_tsu_enabled) {
event = ioread32be(&regs->tmr_pevent);
event &= ioread32be(&regs->tmr_pemask);
if (event) {
iowrite32be(event, &regs->tmr_pevent);
WARN_ON(event & TMR_PEVENT_TSRE);
dtsec->exception_cb(dtsec->dev_id,
FM_MAC_EX_1G_1588_TS_RX_ERR);
}
}
}
static void free_init_resources(struct fman_mac *dtsec)
{
fman_unregister_intr(dtsec->fm, FMAN_MOD_MAC, dtsec->mac_id,
FMAN_INTR_TYPE_ERR);
fman_unregister_intr(dtsec->fm, FMAN_MOD_MAC, dtsec->mac_id,
FMAN_INTR_TYPE_NORMAL);
free_hash_table(dtsec->multicast_addr_hash);
dtsec->multicast_addr_hash = NULL;
free_hash_table(dtsec->unicast_addr_hash);
dtsec->unicast_addr_hash = NULL;
}
int dtsec_cfg_max_frame_len(struct fman_mac *dtsec, u16 new_val)
{
if (is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
dtsec->dtsec_drv_param->maximum_frame = new_val;
return 0;
}
int dtsec_cfg_pad_and_crc(struct fman_mac *dtsec, bool new_val)
{
if (is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
dtsec->dtsec_drv_param->tx_pad_crc = new_val;
return 0;
}
static void graceful_start(struct fman_mac *dtsec, enum comm_mode mode)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
if (mode & COMM_MODE_TX)
iowrite32be(ioread32be(&regs->tctrl) &
~TCTRL_GTS, &regs->tctrl);
if (mode & COMM_MODE_RX)
iowrite32be(ioread32be(&regs->rctrl) &
~RCTRL_GRS, &regs->rctrl);
}
static void graceful_stop(struct fman_mac *dtsec, enum comm_mode mode)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
u32 tmp;
if (mode & COMM_MODE_RX) {
tmp = ioread32be(&regs->rctrl) | RCTRL_GRS;
iowrite32be(tmp, &regs->rctrl);
if (dtsec->fm_rev_info.major == 2) {
usleep_range(100, 200);
} else {
usleep_range(10, 50);
}
}
if (mode & COMM_MODE_TX) {
if (dtsec->fm_rev_info.major == 2) {
pr_debug("GTS not supported due to DTSEC_A004 Errata.\n");
} else {
tmp = ioread32be(&regs->tctrl) | TCTRL_GTS;
iowrite32be(tmp, &regs->tctrl);
usleep_range(10, 50);
}
}
}
int dtsec_enable(struct fman_mac *dtsec, enum comm_mode mode)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
u32 tmp;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
tmp = ioread32be(&regs->maccfg1);
if (mode & COMM_MODE_RX)
tmp |= MACCFG1_RX_EN;
if (mode & COMM_MODE_TX)
tmp |= MACCFG1_TX_EN;
iowrite32be(tmp, &regs->maccfg1);
graceful_start(dtsec, mode);
return 0;
}
int dtsec_disable(struct fman_mac *dtsec, enum comm_mode mode)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
u32 tmp;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
graceful_stop(dtsec, mode);
tmp = ioread32be(&regs->maccfg1);
if (mode & COMM_MODE_RX)
tmp &= ~MACCFG1_RX_EN;
if (mode & COMM_MODE_TX)
tmp &= ~MACCFG1_TX_EN;
iowrite32be(tmp, &regs->maccfg1);
return 0;
}
int dtsec_set_tx_pause_frames(struct fman_mac *dtsec,
u8 __maybe_unused priority,
u16 pause_time, u16 __maybe_unused thresh_time)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
enum comm_mode mode = COMM_MODE_NONE;
u32 ptv = 0;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
if ((ioread32be(&regs->rctrl) & RCTRL_GRS) == 0)
mode |= COMM_MODE_RX;
if ((ioread32be(&regs->tctrl) & TCTRL_GTS) == 0)
mode |= COMM_MODE_TX;
graceful_stop(dtsec, mode);
if (pause_time) {
if (dtsec->fm_rev_info.major == 2 && pause_time <= 320) {
pr_warn("pause-time: %d illegal.Should be > 320\n",
pause_time);
return -EINVAL;
}
ptv = ioread32be(&regs->ptv);
ptv &= PTV_PTE_MASK;
ptv |= pause_time & PTV_PT_MASK;
iowrite32be(ptv, &regs->ptv);
iowrite32be(ioread32be(&regs->maccfg1) | MACCFG1_TX_FLOW,
&regs->maccfg1);
} else
iowrite32be(ioread32be(&regs->maccfg1) & ~MACCFG1_TX_FLOW,
&regs->maccfg1);
graceful_start(dtsec, mode);
return 0;
}
int dtsec_accept_rx_pause_frames(struct fman_mac *dtsec, bool en)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
enum comm_mode mode = COMM_MODE_NONE;
u32 tmp;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
if ((ioread32be(&regs->rctrl) & RCTRL_GRS) == 0)
mode |= COMM_MODE_RX;
if ((ioread32be(&regs->tctrl) & TCTRL_GTS) == 0)
mode |= COMM_MODE_TX;
graceful_stop(dtsec, mode);
tmp = ioread32be(&regs->maccfg1);
if (en)
tmp |= MACCFG1_RX_FLOW;
else
tmp &= ~MACCFG1_RX_FLOW;
iowrite32be(tmp, &regs->maccfg1);
graceful_start(dtsec, mode);
return 0;
}
int dtsec_modify_mac_address(struct fman_mac *dtsec, enet_addr_t *enet_addr)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
enum comm_mode mode = COMM_MODE_NONE;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
if ((ioread32be(&regs->rctrl) & RCTRL_GRS) == 0)
mode |= COMM_MODE_RX;
if ((ioread32be(&regs->tctrl) & TCTRL_GTS) == 0)
mode |= COMM_MODE_TX;
graceful_stop(dtsec, mode);
dtsec->addr = ENET_ADDR_TO_UINT64(*enet_addr);
set_mac_address(dtsec->regs, (u8 *)(*enet_addr));
graceful_start(dtsec, mode);
return 0;
}
int dtsec_add_hash_mac_address(struct fman_mac *dtsec, enet_addr_t *eth_addr)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
struct eth_hash_entry *hash_entry;
u64 addr;
s32 bucket;
u32 crc = 0xFFFFFFFF;
bool mcast, ghtx;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
addr = ENET_ADDR_TO_UINT64(*eth_addr);
ghtx = (bool)((ioread32be(&regs->rctrl) & RCTRL_GHTX) ? true : false);
mcast = (bool)((addr & MAC_GROUP_ADDRESS) ? true : false);
if (ghtx && !mcast) {
pr_err("Could not compute hash bucket\n");
return -EINVAL;
}
crc = crc32_le(crc, (u8 *)eth_addr, ETH_ALEN);
crc = bitrev32(crc);
if (ghtx) {
bucket = (s32)((crc >> 23) & 0x1ff);
} else {
bucket = (s32)((crc >> 24) & 0xff);
if (mcast)
bucket += 0x100;
}
set_bucket(dtsec->regs, bucket, true);
hash_entry = kmalloc(sizeof(*hash_entry), GFP_KERNEL);
if (!hash_entry)
return -ENOMEM;
hash_entry->addr = addr;
INIT_LIST_HEAD(&hash_entry->node);
if (addr & MAC_GROUP_ADDRESS)
list_add_tail(&hash_entry->node,
&dtsec->multicast_addr_hash->lsts[bucket]);
else
list_add_tail(&hash_entry->node,
&dtsec->unicast_addr_hash->lsts[bucket]);
return 0;
}
int dtsec_del_hash_mac_address(struct fman_mac *dtsec, enet_addr_t *eth_addr)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
struct list_head *pos;
struct eth_hash_entry *hash_entry = NULL;
u64 addr;
s32 bucket;
u32 crc = 0xFFFFFFFF;
bool mcast, ghtx;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
addr = ENET_ADDR_TO_UINT64(*eth_addr);
ghtx = (bool)((ioread32be(&regs->rctrl) & RCTRL_GHTX) ? true : false);
mcast = (bool)((addr & MAC_GROUP_ADDRESS) ? true : false);
if (ghtx && !mcast) {
pr_err("Could not compute hash bucket\n");
return -EINVAL;
}
crc = crc32_le(crc, (u8 *)eth_addr, ETH_ALEN);
crc = bitrev32(crc);
if (ghtx) {
bucket = (s32)((crc >> 23) & 0x1ff);
} else {
bucket = (s32)((crc >> 24) & 0xff);
if (mcast)
bucket += 0x100;
}
if (addr & MAC_GROUP_ADDRESS) {
list_for_each(pos,
&dtsec->multicast_addr_hash->lsts[bucket]) {
hash_entry = ETH_HASH_ENTRY_OBJ(pos);
if (hash_entry->addr == addr) {
list_del_init(&hash_entry->node);
kfree(hash_entry);
break;
}
}
if (list_empty(&dtsec->multicast_addr_hash->lsts[bucket]))
set_bucket(dtsec->regs, bucket, false);
} else {
list_for_each(pos,
&dtsec->unicast_addr_hash->lsts[bucket]) {
hash_entry = ETH_HASH_ENTRY_OBJ(pos);
if (hash_entry->addr == addr) {
list_del_init(&hash_entry->node);
kfree(hash_entry);
break;
}
}
if (list_empty(&dtsec->unicast_addr_hash->lsts[bucket]))
set_bucket(dtsec->regs, bucket, false);
}
WARN_ON(!hash_entry);
return 0;
}
int dtsec_set_promiscuous(struct fman_mac *dtsec, bool new_val)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
u32 tmp;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
tmp = ioread32be(&regs->rctrl);
if (new_val)
tmp |= RCTRL_UPROM;
else
tmp &= ~RCTRL_UPROM;
iowrite32be(tmp, &regs->rctrl);
tmp = ioread32be(&regs->rctrl);
if (new_val)
tmp |= RCTRL_MPROM;
else
tmp &= ~RCTRL_MPROM;
iowrite32be(tmp, &regs->rctrl);
return 0;
}
int dtsec_adjust_link(struct fman_mac *dtsec, u16 speed)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
enum comm_mode mode = COMM_MODE_NONE;
u32 tmp;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
if ((ioread32be(&regs->rctrl) & RCTRL_GRS) == 0)
mode |= COMM_MODE_RX;
if ((ioread32be(&regs->tctrl) & TCTRL_GTS) == 0)
mode |= COMM_MODE_TX;
graceful_stop(dtsec, mode);
tmp = ioread32be(&regs->maccfg2);
tmp |= MACCFG2_FULL_DUPLEX;
tmp &= ~(MACCFG2_NIBBLE_MODE | MACCFG2_BYTE_MODE);
if (speed < SPEED_1000)
tmp |= MACCFG2_NIBBLE_MODE;
else if (speed == SPEED_1000)
tmp |= MACCFG2_BYTE_MODE;
iowrite32be(tmp, &regs->maccfg2);
tmp = ioread32be(&regs->ecntrl);
if (speed == SPEED_100)
tmp |= DTSEC_ECNTRL_R100M;
else
tmp &= ~DTSEC_ECNTRL_R100M;
iowrite32be(tmp, &regs->ecntrl);
graceful_start(dtsec, mode);
return 0;
}
int dtsec_restart_autoneg(struct fman_mac *dtsec)
{
u16 tmp_reg16;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
tmp_reg16 = phy_read(dtsec->tbiphy, MII_BMCR);
tmp_reg16 &= ~(BMCR_SPEED100 | BMCR_SPEED1000);
tmp_reg16 |= (BMCR_ANENABLE | BMCR_ANRESTART |
BMCR_FULLDPLX | BMCR_SPEED1000);
phy_write(dtsec->tbiphy, MII_BMCR, tmp_reg16);
return 0;
}
int dtsec_get_version(struct fman_mac *dtsec, u32 *mac_version)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
*mac_version = ioread32be(&regs->tsec_id);
return 0;
}
int dtsec_set_exception(struct fman_mac *dtsec,
enum fman_mac_exceptions exception, bool enable)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
u32 bit_mask = 0;
if (!is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
if (exception != FM_MAC_EX_1G_1588_TS_RX_ERR) {
bit_mask = get_exception_flag(exception);
if (bit_mask) {
if (enable)
dtsec->exceptions |= bit_mask;
else
dtsec->exceptions &= ~bit_mask;
} else {
pr_err("Undefined exception\n");
return -EINVAL;
}
if (enable)
iowrite32be(ioread32be(&regs->imask) | bit_mask,
&regs->imask);
else
iowrite32be(ioread32be(&regs->imask) & ~bit_mask,
&regs->imask);
} else {
if (!dtsec->ptp_tsu_enabled) {
pr_err("Exception valid for 1588 only\n");
return -EINVAL;
}
switch (exception) {
case FM_MAC_EX_1G_1588_TS_RX_ERR:
if (enable) {
dtsec->en_tsu_err_exception = true;
iowrite32be(ioread32be(&regs->tmr_pemask) |
TMR_PEMASK_TSREEN,
&regs->tmr_pemask);
} else {
dtsec->en_tsu_err_exception = false;
iowrite32be(ioread32be(&regs->tmr_pemask) &
~TMR_PEMASK_TSREEN,
&regs->tmr_pemask);
}
break;
default:
pr_err("Undefined exception\n");
return -EINVAL;
}
}
return 0;
}
int dtsec_init(struct fman_mac *dtsec)
{
struct dtsec_regs __iomem *regs = dtsec->regs;
struct dtsec_cfg *dtsec_drv_param;
int err;
u16 max_frm_ln;
enet_addr_t eth_addr;
if (is_init_done(dtsec->dtsec_drv_param))
return -EINVAL;
if (DEFAULT_RESET_ON_INIT &&
(fman_reset_mac(dtsec->fm, dtsec->mac_id) != 0)) {
pr_err("Can't reset MAC!\n");
return -EINVAL;
}
err = check_init_parameters(dtsec);
if (err)
return err;
dtsec_drv_param = dtsec->dtsec_drv_param;
MAKE_ENET_ADDR_FROM_UINT64(dtsec->addr, eth_addr);
err = init(dtsec->regs, dtsec_drv_param, dtsec->phy_if,
dtsec->max_speed, (u8 *)eth_addr, dtsec->exceptions,
dtsec->tbiphy->mdio.addr);
if (err) {
free_init_resources(dtsec);
pr_err("DTSEC version doesn't support this i/f mode\n");
return err;
}
if (dtsec->phy_if == PHY_INTERFACE_MODE_SGMII) {
u16 tmp_reg16;
tmp_reg16 = TBICON_CLK_SELECT | TBICON_SOFT_RESET;
phy_write(dtsec->tbiphy, MII_TBICON, tmp_reg16);
tmp_reg16 = TBICON_CLK_SELECT;
phy_write(dtsec->tbiphy, MII_TBICON, tmp_reg16);
tmp_reg16 = (BMCR_RESET | BMCR_ANENABLE |
BMCR_FULLDPLX | BMCR_SPEED1000);
phy_write(dtsec->tbiphy, MII_BMCR, tmp_reg16);
if (dtsec->basex_if)
tmp_reg16 = TBIANA_1000X;
else
tmp_reg16 = TBIANA_SGMII;
phy_write(dtsec->tbiphy, MII_ADVERTISE, tmp_reg16);
tmp_reg16 = (BMCR_ANENABLE | BMCR_ANRESTART |
BMCR_FULLDPLX | BMCR_SPEED1000);
phy_write(dtsec->tbiphy, MII_BMCR, tmp_reg16);
}
max_frm_ln = (u16)ioread32be(&regs->maxfrm);
err = fman_set_mac_max_frame(dtsec->fm, dtsec->mac_id, max_frm_ln);
if (err) {
pr_err("Setting max frame length failed\n");
free_init_resources(dtsec);
return -EINVAL;
}
dtsec->multicast_addr_hash =
alloc_hash_table(EXTENDED_HASH_TABLE_SIZE);
if (!dtsec->multicast_addr_hash) {
free_init_resources(dtsec);
pr_err("MC hash table is failed\n");
return -ENOMEM;
}
dtsec->unicast_addr_hash = alloc_hash_table(DTSEC_HASH_TABLE_SIZE);
if (!dtsec->unicast_addr_hash) {
free_init_resources(dtsec);
pr_err("UC hash table is failed\n");
return -ENOMEM;
}
fman_register_intr(dtsec->fm, FMAN_MOD_MAC, dtsec->mac_id,
FMAN_INTR_TYPE_ERR, dtsec_isr, dtsec);
fman_register_intr(dtsec->fm, FMAN_MOD_MAC, dtsec->mac_id,
FMAN_INTR_TYPE_NORMAL, dtsec_1588_isr, dtsec);
kfree(dtsec_drv_param);
dtsec->dtsec_drv_param = NULL;
return 0;
}
int dtsec_free(struct fman_mac *dtsec)
{
free_init_resources(dtsec);
kfree(dtsec->dtsec_drv_param);
dtsec->dtsec_drv_param = NULL;
kfree(dtsec);
return 0;
}
struct fman_mac *dtsec_config(struct fman_mac_params *params)
{
struct fman_mac *dtsec;
struct dtsec_cfg *dtsec_drv_param;
void __iomem *base_addr;
base_addr = params->base_addr;
dtsec = kzalloc(sizeof(*dtsec), GFP_KERNEL);
if (!dtsec)
return NULL;
dtsec_drv_param = kzalloc(sizeof(*dtsec_drv_param), GFP_KERNEL);
if (!dtsec_drv_param)
goto err_dtsec;
dtsec->dtsec_drv_param = dtsec_drv_param;
set_dflts(dtsec_drv_param);
dtsec->regs = base_addr;
dtsec->addr = ENET_ADDR_TO_UINT64(params->addr);
dtsec->max_speed = params->max_speed;
dtsec->phy_if = params->phy_if;
dtsec->mac_id = params->mac_id;
dtsec->exceptions = (DTSEC_IMASK_BREN |
DTSEC_IMASK_RXCEN |
DTSEC_IMASK_BTEN |
DTSEC_IMASK_TXCEN |
DTSEC_IMASK_TXEEN |
DTSEC_IMASK_ABRTEN |
DTSEC_IMASK_LCEN |
DTSEC_IMASK_CRLEN |
DTSEC_IMASK_XFUNEN |
DTSEC_IMASK_IFERREN |
DTSEC_IMASK_MAGEN |
DTSEC_IMASK_TDPEEN |
DTSEC_IMASK_RDPEEN);
dtsec->exception_cb = params->exception_cb;
dtsec->event_cb = params->event_cb;
dtsec->dev_id = params->dev_id;
dtsec->ptp_tsu_enabled = dtsec->dtsec_drv_param->ptp_tsu_en;
dtsec->en_tsu_err_exception = dtsec->dtsec_drv_param->ptp_exception_en;
dtsec->fm = params->fm;
dtsec->basex_if = params->basex_if;
if (!params->internal_phy_node) {
pr_err("TBI PHY node is not available\n");
goto err_dtsec_drv_param;
}
dtsec->tbiphy = of_phy_find_device(params->internal_phy_node);
if (!dtsec->tbiphy) {
pr_err("of_phy_find_device (TBI PHY) failed\n");
goto err_dtsec_drv_param;
}
put_device(&dtsec->tbiphy->mdio.dev);
fman_get_revision(dtsec->fm, &dtsec->fm_rev_info);
return dtsec;
err_dtsec_drv_param:
kfree(dtsec_drv_param);
err_dtsec:
kfree(dtsec);
return NULL;
}
