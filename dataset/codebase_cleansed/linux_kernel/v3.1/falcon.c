static void falcon_setsda(void *data, int state)
{
struct efx_nic *efx = (struct efx_nic *)data;
efx_oword_t reg;
efx_reado(efx, &reg, FR_AB_GPIO_CTL);
EFX_SET_OWORD_FIELD(reg, FRF_AB_GPIO3_OEN, !state);
efx_writeo(efx, &reg, FR_AB_GPIO_CTL);
}
static void falcon_setscl(void *data, int state)
{
struct efx_nic *efx = (struct efx_nic *)data;
efx_oword_t reg;
efx_reado(efx, &reg, FR_AB_GPIO_CTL);
EFX_SET_OWORD_FIELD(reg, FRF_AB_GPIO0_OEN, !state);
efx_writeo(efx, &reg, FR_AB_GPIO_CTL);
}
static int falcon_getsda(void *data)
{
struct efx_nic *efx = (struct efx_nic *)data;
efx_oword_t reg;
efx_reado(efx, &reg, FR_AB_GPIO_CTL);
return EFX_OWORD_FIELD(reg, FRF_AB_GPIO3_IN);
}
static int falcon_getscl(void *data)
{
struct efx_nic *efx = (struct efx_nic *)data;
efx_oword_t reg;
efx_reado(efx, &reg, FR_AB_GPIO_CTL);
return EFX_OWORD_FIELD(reg, FRF_AB_GPIO0_IN);
}
static void falcon_push_irq_moderation(struct efx_channel *channel)
{
efx_dword_t timer_cmd;
struct efx_nic *efx = channel->efx;
if (channel->irq_moderation) {
EFX_POPULATE_DWORD_2(timer_cmd,
FRF_AB_TC_TIMER_MODE,
FFE_BB_TIMER_MODE_INT_HLDOFF,
FRF_AB_TC_TIMER_VAL,
channel->irq_moderation - 1);
} else {
EFX_POPULATE_DWORD_2(timer_cmd,
FRF_AB_TC_TIMER_MODE,
FFE_BB_TIMER_MODE_DIS,
FRF_AB_TC_TIMER_VAL, 0);
}
BUILD_BUG_ON(FR_AA_TIMER_COMMAND_KER != FR_BZ_TIMER_COMMAND_P0);
efx_writed_page_locked(efx, &timer_cmd, FR_BZ_TIMER_COMMAND_P0,
channel->channel);
}
static void falcon_prepare_flush(struct efx_nic *efx)
{
falcon_deconfigure_mac_wrapper(efx);
msleep(10);
}
inline void falcon_irq_ack_a1(struct efx_nic *efx)
{
efx_dword_t reg;
EFX_POPULATE_DWORD_1(reg, FRF_AA_INT_ACK_KER_FIELD, 0xb7eb7e);
efx_writed(efx, &reg, FR_AA_INT_ACK_KER);
efx_readd(efx, &reg, FR_AA_WORK_AROUND_BROKEN_PCI_READS);
}
irqreturn_t falcon_legacy_interrupt_a1(int irq, void *dev_id)
{
struct efx_nic *efx = dev_id;
efx_oword_t *int_ker = efx->irq_status.addr;
int syserr;
int queues;
if (unlikely(EFX_OWORD_IS_ZERO(*int_ker))) {
netif_vdbg(efx, intr, efx->net_dev,
"IRQ %d on CPU %d not for me\n", irq,
raw_smp_processor_id());
return IRQ_NONE;
}
efx->last_irq_cpu = raw_smp_processor_id();
netif_vdbg(efx, intr, efx->net_dev,
"IRQ %d on CPU %d status " EFX_OWORD_FMT "\n",
irq, raw_smp_processor_id(), EFX_OWORD_VAL(*int_ker));
BUILD_BUG_ON(FSF_AZ_NET_IVEC_INT_Q_WIDTH > EFX_MAX_CHANNELS);
queues = EFX_OWORD_FIELD(*int_ker, FSF_AZ_NET_IVEC_INT_Q);
if (queues & (1U << efx->fatal_irq_level)) {
syserr = EFX_OWORD_FIELD(*int_ker, FSF_AZ_NET_IVEC_FATAL_INT);
if (unlikely(syserr))
return efx_nic_fatal_interrupt(efx);
}
EFX_ZERO_OWORD(*int_ker);
wmb();
falcon_irq_ack_a1(efx);
if (queues & 1)
efx_schedule_channel(efx_get_channel(efx, 0));
if (queues & 2)
efx_schedule_channel(efx_get_channel(efx, 1));
return IRQ_HANDLED;
}
static int falcon_spi_poll(struct efx_nic *efx)
{
efx_oword_t reg;
efx_reado(efx, &reg, FR_AB_EE_SPI_HCMD);
return EFX_OWORD_FIELD(reg, FRF_AB_EE_SPI_HCMD_CMD_EN) ? -EBUSY : 0;
}
static int falcon_spi_wait(struct efx_nic *efx)
{
unsigned long timeout = jiffies + 1 + DIV_ROUND_UP(HZ, 10);
int i;
for (i = 0; i < 10; i++) {
if (!falcon_spi_poll(efx))
return 0;
udelay(10);
}
for (;;) {
if (!falcon_spi_poll(efx))
return 0;
if (time_after_eq(jiffies, timeout)) {
netif_err(efx, hw, efx->net_dev,
"timed out waiting for SPI\n");
return -ETIMEDOUT;
}
schedule_timeout_uninterruptible(1);
}
}
int falcon_spi_cmd(struct efx_nic *efx, const struct efx_spi_device *spi,
unsigned int command, int address,
const void *in, void *out, size_t len)
{
bool addressed = (address >= 0);
bool reading = (out != NULL);
efx_oword_t reg;
int rc;
if (len > FALCON_SPI_MAX_LEN)
return -EINVAL;
rc = falcon_spi_poll(efx);
if (rc)
return rc;
if (addressed) {
EFX_POPULATE_OWORD_1(reg, FRF_AB_EE_SPI_HADR_ADR, address);
efx_writeo(efx, &reg, FR_AB_EE_SPI_HADR);
}
if (in != NULL) {
memcpy(&reg, in, len);
efx_writeo(efx, &reg, FR_AB_EE_SPI_HDATA);
}
EFX_POPULATE_OWORD_7(reg,
FRF_AB_EE_SPI_HCMD_CMD_EN, 1,
FRF_AB_EE_SPI_HCMD_SF_SEL, spi->device_id,
FRF_AB_EE_SPI_HCMD_DABCNT, len,
FRF_AB_EE_SPI_HCMD_READ, reading,
FRF_AB_EE_SPI_HCMD_DUBCNT, 0,
FRF_AB_EE_SPI_HCMD_ADBCNT,
(addressed ? spi->addr_len : 0),
FRF_AB_EE_SPI_HCMD_ENC, command);
efx_writeo(efx, &reg, FR_AB_EE_SPI_HCMD);
rc = falcon_spi_wait(efx);
if (rc)
return rc;
if (out != NULL) {
efx_reado(efx, &reg, FR_AB_EE_SPI_HDATA);
memcpy(out, &reg, len);
}
return 0;
}
static size_t
falcon_spi_write_limit(const struct efx_spi_device *spi, size_t start)
{
return min(FALCON_SPI_MAX_LEN,
(spi->block_size - (start & (spi->block_size - 1))));
}
static inline u8
efx_spi_munge_command(const struct efx_spi_device *spi,
const u8 command, const unsigned int address)
{
return command | (((address >> 8) & spi->munge_address) << 3);
}
int
falcon_spi_wait_write(struct efx_nic *efx, const struct efx_spi_device *spi)
{
unsigned long timeout = jiffies + 1 + DIV_ROUND_UP(HZ, 100);
u8 status;
int rc;
for (;;) {
rc = falcon_spi_cmd(efx, spi, SPI_RDSR, -1, NULL,
&status, sizeof(status));
if (rc)
return rc;
if (!(status & SPI_STATUS_NRDY))
return 0;
if (time_after_eq(jiffies, timeout)) {
netif_err(efx, hw, efx->net_dev,
"SPI write timeout on device %d"
" last status=0x%02x\n",
spi->device_id, status);
return -ETIMEDOUT;
}
schedule_timeout_uninterruptible(1);
}
}
int falcon_spi_read(struct efx_nic *efx, const struct efx_spi_device *spi,
loff_t start, size_t len, size_t *retlen, u8 *buffer)
{
size_t block_len, pos = 0;
unsigned int command;
int rc = 0;
while (pos < len) {
block_len = min(len - pos, FALCON_SPI_MAX_LEN);
command = efx_spi_munge_command(spi, SPI_READ, start + pos);
rc = falcon_spi_cmd(efx, spi, command, start + pos, NULL,
buffer + pos, block_len);
if (rc)
break;
pos += block_len;
cond_resched();
if (signal_pending(current)) {
rc = -EINTR;
break;
}
}
if (retlen)
*retlen = pos;
return rc;
}
int
falcon_spi_write(struct efx_nic *efx, const struct efx_spi_device *spi,
loff_t start, size_t len, size_t *retlen, const u8 *buffer)
{
u8 verify_buffer[FALCON_SPI_MAX_LEN];
size_t block_len, pos = 0;
unsigned int command;
int rc = 0;
while (pos < len) {
rc = falcon_spi_cmd(efx, spi, SPI_WREN, -1, NULL, NULL, 0);
if (rc)
break;
block_len = min(len - pos,
falcon_spi_write_limit(spi, start + pos));
command = efx_spi_munge_command(spi, SPI_WRITE, start + pos);
rc = falcon_spi_cmd(efx, spi, command, start + pos,
buffer + pos, NULL, block_len);
if (rc)
break;
rc = falcon_spi_wait_write(efx, spi);
if (rc)
break;
command = efx_spi_munge_command(spi, SPI_READ, start + pos);
rc = falcon_spi_cmd(efx, spi, command, start + pos,
NULL, verify_buffer, block_len);
if (memcmp(verify_buffer, buffer + pos, block_len)) {
rc = -EIO;
break;
}
pos += block_len;
cond_resched();
if (signal_pending(current)) {
rc = -EINTR;
break;
}
}
if (retlen)
*retlen = pos;
return rc;
}
static void falcon_push_multicast_hash(struct efx_nic *efx)
{
union efx_multicast_hash *mc_hash = &efx->multicast_hash;
WARN_ON(!mutex_is_locked(&efx->mac_lock));
efx_writeo(efx, &mc_hash->oword[0], FR_AB_MAC_MC_HASH_REG0);
efx_writeo(efx, &mc_hash->oword[1], FR_AB_MAC_MC_HASH_REG1);
}
static void falcon_reset_macs(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
efx_oword_t reg, mac_ctrl;
int count;
if (efx_nic_rev(efx) < EFX_REV_FALCON_B0) {
EFX_POPULATE_OWORD_1(reg, FRF_AB_XM_CORE_RST, 1);
efx_writeo(efx, &reg, FR_AB_XM_GLB_CFG);
for (count = 0; count < 10000; count++) {
efx_reado(efx, &reg, FR_AB_XM_GLB_CFG);
if (EFX_OWORD_FIELD(reg, FRF_AB_XM_CORE_RST) ==
0)
return;
udelay(10);
}
netif_err(efx, hw, efx->net_dev,
"timed out waiting for XMAC core reset\n");
}
WARN_ON(nic_data->stats_disable_count == 0);
efx_reado(efx, &mac_ctrl, FR_AB_MAC_CTRL);
EFX_SET_OWORD_FIELD(mac_ctrl, FRF_BB_TXFIFO_DRAIN_EN, 1);
efx_writeo(efx, &mac_ctrl, FR_AB_MAC_CTRL);
efx_reado(efx, &reg, FR_AB_GLB_CTL);
EFX_SET_OWORD_FIELD(reg, FRF_AB_RST_XGTX, 1);
EFX_SET_OWORD_FIELD(reg, FRF_AB_RST_XGRX, 1);
EFX_SET_OWORD_FIELD(reg, FRF_AB_RST_EM, 1);
efx_writeo(efx, &reg, FR_AB_GLB_CTL);
count = 0;
while (1) {
efx_reado(efx, &reg, FR_AB_GLB_CTL);
if (!EFX_OWORD_FIELD(reg, FRF_AB_RST_XGTX) &&
!EFX_OWORD_FIELD(reg, FRF_AB_RST_XGRX) &&
!EFX_OWORD_FIELD(reg, FRF_AB_RST_EM)) {
netif_dbg(efx, hw, efx->net_dev,
"Completed MAC reset after %d loops\n",
count);
break;
}
if (count > 20) {
netif_err(efx, hw, efx->net_dev, "MAC reset failed\n");
break;
}
count++;
udelay(10);
}
efx_writeo(efx, &mac_ctrl, FR_AB_MAC_CTRL);
falcon_setup_xaui(efx);
}
void falcon_drain_tx_fifo(struct efx_nic *efx)
{
efx_oword_t reg;
if ((efx_nic_rev(efx) < EFX_REV_FALCON_B0) ||
(efx->loopback_mode != LOOPBACK_NONE))
return;
efx_reado(efx, &reg, FR_AB_MAC_CTRL);
if (EFX_OWORD_FIELD(reg, FRF_BB_TXFIFO_DRAIN_EN))
return;
falcon_reset_macs(efx);
}
static void falcon_deconfigure_mac_wrapper(struct efx_nic *efx)
{
efx_oword_t reg;
if (efx_nic_rev(efx) < EFX_REV_FALCON_B0)
return;
efx_reado(efx, &reg, FR_AZ_RX_CFG);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_INGR_EN, 0);
efx_writeo(efx, &reg, FR_AZ_RX_CFG);
falcon_drain_tx_fifo(efx);
}
void falcon_reconfigure_mac_wrapper(struct efx_nic *efx)
{
struct efx_link_state *link_state = &efx->link_state;
efx_oword_t reg;
int link_speed, isolate;
isolate = !!ACCESS_ONCE(efx->reset_pending);
switch (link_state->speed) {
case 10000: link_speed = 3; break;
case 1000: link_speed = 2; break;
case 100: link_speed = 1; break;
default: link_speed = 0; break;
}
EFX_POPULATE_OWORD_5(reg,
FRF_AB_MAC_XOFF_VAL, 0xffff ,
FRF_AB_MAC_BCAD_ACPT, 1,
FRF_AB_MAC_UC_PROM, efx->promiscuous,
FRF_AB_MAC_LINK_STATUS, 1,
FRF_AB_MAC_SPEED, link_speed);
if (efx_nic_rev(efx) >= EFX_REV_FALCON_B0) {
EFX_SET_OWORD_FIELD(reg, FRF_BB_TXFIFO_DRAIN_EN,
!link_state->up || isolate);
}
efx_writeo(efx, &reg, FR_AB_MAC_CTRL);
falcon_push_multicast_hash(efx);
efx_reado(efx, &reg, FR_AZ_RX_CFG);
EFX_SET_OWORD_FIELD(reg, FRF_AZ_RX_XOFF_MAC_EN, 1);
if (efx_nic_rev(efx) >= EFX_REV_FALCON_B0)
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_INGR_EN, !isolate);
efx_writeo(efx, &reg, FR_AZ_RX_CFG);
}
static void falcon_stats_request(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
efx_oword_t reg;
WARN_ON(nic_data->stats_pending);
WARN_ON(nic_data->stats_disable_count);
if (nic_data->stats_dma_done == NULL)
return;
*nic_data->stats_dma_done = FALCON_STATS_NOT_DONE;
nic_data->stats_pending = true;
wmb();
EFX_POPULATE_OWORD_2(reg,
FRF_AB_MAC_STAT_DMA_CMD, 1,
FRF_AB_MAC_STAT_DMA_ADR,
efx->stats_buffer.dma_addr);
efx_writeo(efx, &reg, FR_AB_MAC_STAT_DMA);
mod_timer(&nic_data->stats_timer, round_jiffies_up(jiffies + HZ / 2));
}
static void falcon_stats_complete(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
if (!nic_data->stats_pending)
return;
nic_data->stats_pending = 0;
if (*nic_data->stats_dma_done == FALCON_STATS_DONE) {
rmb();
efx->mac_op->update_stats(efx);
} else {
netif_err(efx, hw, efx->net_dev,
"timed out waiting for statistics\n");
}
}
static void falcon_stats_timer_func(unsigned long context)
{
struct efx_nic *efx = (struct efx_nic *)context;
struct falcon_nic_data *nic_data = efx->nic_data;
spin_lock(&efx->stats_lock);
falcon_stats_complete(efx);
if (nic_data->stats_disable_count == 0)
falcon_stats_request(efx);
spin_unlock(&efx->stats_lock);
}
static bool falcon_loopback_link_poll(struct efx_nic *efx)
{
struct efx_link_state old_state = efx->link_state;
WARN_ON(!mutex_is_locked(&efx->mac_lock));
WARN_ON(!LOOPBACK_INTERNAL(efx));
efx->link_state.fd = true;
efx->link_state.fc = efx->wanted_fc;
efx->link_state.up = true;
efx->link_state.speed = 10000;
return !efx_link_state_equal(&efx->link_state, &old_state);
}
static int falcon_reconfigure_port(struct efx_nic *efx)
{
int rc;
WARN_ON(efx_nic_rev(efx) > EFX_REV_FALCON_B0);
if (LOOPBACK_INTERNAL(efx))
falcon_loopback_link_poll(efx);
else
efx->phy_op->poll(efx);
falcon_stop_nic_stats(efx);
falcon_deconfigure_mac_wrapper(efx);
falcon_reset_macs(efx);
efx->phy_op->reconfigure(efx);
rc = efx->mac_op->reconfigure(efx);
BUG_ON(rc);
falcon_start_nic_stats(efx);
efx_link_status_changed(efx);
return 0;
}
static int falcon_gmii_wait(struct efx_nic *efx)
{
efx_oword_t md_stat;
int count;
for (count = 0; count < 5000; count++) {
efx_reado(efx, &md_stat, FR_AB_MD_STAT);
if (EFX_OWORD_FIELD(md_stat, FRF_AB_MD_BSY) == 0) {
if (EFX_OWORD_FIELD(md_stat, FRF_AB_MD_LNFL) != 0 ||
EFX_OWORD_FIELD(md_stat, FRF_AB_MD_BSERR) != 0) {
netif_err(efx, hw, efx->net_dev,
"error from GMII access "
EFX_OWORD_FMT"\n",
EFX_OWORD_VAL(md_stat));
return -EIO;
}
return 0;
}
udelay(10);
}
netif_err(efx, hw, efx->net_dev, "timed out waiting for GMII\n");
return -ETIMEDOUT;
}
static int falcon_mdio_write(struct net_device *net_dev,
int prtad, int devad, u16 addr, u16 value)
{
struct efx_nic *efx = netdev_priv(net_dev);
struct falcon_nic_data *nic_data = efx->nic_data;
efx_oword_t reg;
int rc;
netif_vdbg(efx, hw, efx->net_dev,
"writing MDIO %d register %d.%d with 0x%04x\n",
prtad, devad, addr, value);
mutex_lock(&nic_data->mdio_lock);
rc = falcon_gmii_wait(efx);
if (rc)
goto out;
EFX_POPULATE_OWORD_1(reg, FRF_AB_MD_PHY_ADR, addr);
efx_writeo(efx, &reg, FR_AB_MD_PHY_ADR);
EFX_POPULATE_OWORD_2(reg, FRF_AB_MD_PRT_ADR, prtad,
FRF_AB_MD_DEV_ADR, devad);
efx_writeo(efx, &reg, FR_AB_MD_ID);
EFX_POPULATE_OWORD_1(reg, FRF_AB_MD_TXD, value);
efx_writeo(efx, &reg, FR_AB_MD_TXD);
EFX_POPULATE_OWORD_2(reg,
FRF_AB_MD_WRC, 1,
FRF_AB_MD_GC, 0);
efx_writeo(efx, &reg, FR_AB_MD_CS);
rc = falcon_gmii_wait(efx);
if (rc) {
EFX_POPULATE_OWORD_2(reg,
FRF_AB_MD_WRC, 0,
FRF_AB_MD_GC, 1);
efx_writeo(efx, &reg, FR_AB_MD_CS);
udelay(10);
}
out:
mutex_unlock(&nic_data->mdio_lock);
return rc;
}
static int falcon_mdio_read(struct net_device *net_dev,
int prtad, int devad, u16 addr)
{
struct efx_nic *efx = netdev_priv(net_dev);
struct falcon_nic_data *nic_data = efx->nic_data;
efx_oword_t reg;
int rc;
mutex_lock(&nic_data->mdio_lock);
rc = falcon_gmii_wait(efx);
if (rc)
goto out;
EFX_POPULATE_OWORD_1(reg, FRF_AB_MD_PHY_ADR, addr);
efx_writeo(efx, &reg, FR_AB_MD_PHY_ADR);
EFX_POPULATE_OWORD_2(reg, FRF_AB_MD_PRT_ADR, prtad,
FRF_AB_MD_DEV_ADR, devad);
efx_writeo(efx, &reg, FR_AB_MD_ID);
EFX_POPULATE_OWORD_2(reg, FRF_AB_MD_RDC, 1, FRF_AB_MD_GC, 0);
efx_writeo(efx, &reg, FR_AB_MD_CS);
rc = falcon_gmii_wait(efx);
if (rc == 0) {
efx_reado(efx, &reg, FR_AB_MD_RXD);
rc = EFX_OWORD_FIELD(reg, FRF_AB_MD_RXD);
netif_vdbg(efx, hw, efx->net_dev,
"read from MDIO %d register %d.%d, got %04x\n",
prtad, devad, addr, rc);
} else {
EFX_POPULATE_OWORD_2(reg,
FRF_AB_MD_RIC, 0,
FRF_AB_MD_GC, 1);
efx_writeo(efx, &reg, FR_AB_MD_CS);
netif_dbg(efx, hw, efx->net_dev,
"read from MDIO %d register %d.%d, got error %d\n",
prtad, devad, addr, rc);
}
out:
mutex_unlock(&nic_data->mdio_lock);
return rc;
}
static int falcon_probe_port(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
int rc;
switch (efx->phy_type) {
case PHY_TYPE_SFX7101:
efx->phy_op = &falcon_sfx7101_phy_ops;
break;
case PHY_TYPE_QT2022C2:
case PHY_TYPE_QT2025C:
efx->phy_op = &falcon_qt202x_phy_ops;
break;
case PHY_TYPE_TXC43128:
efx->phy_op = &falcon_txc_phy_ops;
break;
default:
netif_err(efx, probe, efx->net_dev, "Unknown PHY type %d\n",
efx->phy_type);
return -ENODEV;
}
mutex_init(&nic_data->mdio_lock);
efx->mdio.mdio_read = falcon_mdio_read;
efx->mdio.mdio_write = falcon_mdio_write;
rc = efx->phy_op->probe(efx);
if (rc != 0)
return rc;
efx->link_state.speed = 10000;
efx->link_state.fd = true;
if (efx_nic_rev(efx) >= EFX_REV_FALCON_B0)
efx->wanted_fc = EFX_FC_RX | EFX_FC_TX;
else
efx->wanted_fc = EFX_FC_RX;
if (efx->mdio.mmds & MDIO_DEVS_AN)
efx->wanted_fc |= EFX_FC_AUTO;
rc = efx_nic_alloc_buffer(efx, &efx->stats_buffer,
FALCON_MAC_STATS_SIZE);
if (rc)
return rc;
netif_dbg(efx, probe, efx->net_dev,
"stats buffer at %llx (virt %p phys %llx)\n",
(u64)efx->stats_buffer.dma_addr,
efx->stats_buffer.addr,
(u64)virt_to_phys(efx->stats_buffer.addr));
nic_data->stats_dma_done = efx->stats_buffer.addr + XgDmaDone_offset;
return 0;
}
static void falcon_remove_port(struct efx_nic *efx)
{
efx->phy_op->remove(efx);
efx_nic_free_buffer(efx, &efx->stats_buffer);
}
static bool
falcon_handle_global_event(struct efx_channel *channel, efx_qword_t *event)
{
struct efx_nic *efx = channel->efx;
struct falcon_nic_data *nic_data = efx->nic_data;
if (EFX_QWORD_FIELD(*event, FSF_AB_GLB_EV_G_PHY0_INTR) ||
EFX_QWORD_FIELD(*event, FSF_AB_GLB_EV_XG_PHY0_INTR) ||
EFX_QWORD_FIELD(*event, FSF_AB_GLB_EV_XFP_PHY0_INTR))
return true;
if ((efx_nic_rev(efx) == EFX_REV_FALCON_B0) &&
EFX_QWORD_FIELD(*event, FSF_BB_GLB_EV_XG_MGT_INTR)) {
nic_data->xmac_poll_required = true;
return true;
}
if (efx_nic_rev(efx) <= EFX_REV_FALCON_A1 ?
EFX_QWORD_FIELD(*event, FSF_AA_GLB_EV_RX_RECOVERY) :
EFX_QWORD_FIELD(*event, FSF_BB_GLB_EV_RX_RECOVERY)) {
netif_err(efx, rx_err, efx->net_dev,
"channel %d seen global RX_RESET event. Resetting.\n",
channel->channel);
atomic_inc(&efx->rx_reset);
efx_schedule_reset(efx, EFX_WORKAROUND_6555(efx) ?
RESET_TYPE_RX_RECOVERY : RESET_TYPE_DISABLE);
return true;
}
return false;
}
static int
falcon_read_nvram(struct efx_nic *efx, struct falcon_nvconfig *nvconfig_out)
{
struct falcon_nic_data *nic_data = efx->nic_data;
struct falcon_nvconfig *nvconfig;
struct efx_spi_device *spi;
void *region;
int rc, magic_num, struct_ver;
__le16 *word, *limit;
u32 csum;
if (efx_spi_present(&nic_data->spi_flash))
spi = &nic_data->spi_flash;
else if (efx_spi_present(&nic_data->spi_eeprom))
spi = &nic_data->spi_eeprom;
else
return -EINVAL;
region = kmalloc(FALCON_NVCONFIG_END, GFP_KERNEL);
if (!region)
return -ENOMEM;
nvconfig = region + FALCON_NVCONFIG_OFFSET;
mutex_lock(&nic_data->spi_lock);
rc = falcon_spi_read(efx, spi, 0, FALCON_NVCONFIG_END, NULL, region);
mutex_unlock(&nic_data->spi_lock);
if (rc) {
netif_err(efx, hw, efx->net_dev, "Failed to read %s\n",
efx_spi_present(&nic_data->spi_flash) ?
"flash" : "EEPROM");
rc = -EIO;
goto out;
}
magic_num = le16_to_cpu(nvconfig->board_magic_num);
struct_ver = le16_to_cpu(nvconfig->board_struct_ver);
rc = -EINVAL;
if (magic_num != FALCON_NVCONFIG_BOARD_MAGIC_NUM) {
netif_err(efx, hw, efx->net_dev,
"NVRAM bad magic 0x%x\n", magic_num);
goto out;
}
if (struct_ver < 2) {
netif_err(efx, hw, efx->net_dev,
"NVRAM has ancient version 0x%x\n", struct_ver);
goto out;
} else if (struct_ver < 4) {
word = &nvconfig->board_magic_num;
limit = (__le16 *) (nvconfig + 1);
} else {
word = region;
limit = region + FALCON_NVCONFIG_END;
}
for (csum = 0; word < limit; ++word)
csum += le16_to_cpu(*word);
if (~csum & 0xffff) {
netif_err(efx, hw, efx->net_dev,
"NVRAM has incorrect checksum\n");
goto out;
}
rc = 0;
if (nvconfig_out)
memcpy(nvconfig_out, nvconfig, sizeof(*nvconfig));
out:
kfree(region);
return rc;
}
static int falcon_test_nvram(struct efx_nic *efx)
{
return falcon_read_nvram(efx, NULL);
}
static int falcon_b0_test_registers(struct efx_nic *efx)
{
return efx_nic_test_registers(efx, falcon_b0_register_tests,
ARRAY_SIZE(falcon_b0_register_tests));
}
static enum reset_type falcon_map_reset_reason(enum reset_type reason)
{
switch (reason) {
case RESET_TYPE_RX_RECOVERY:
case RESET_TYPE_RX_DESC_FETCH:
case RESET_TYPE_TX_DESC_FETCH:
case RESET_TYPE_TX_SKIP:
return RESET_TYPE_INVISIBLE;
default:
return RESET_TYPE_ALL;
}
}
static int falcon_map_reset_flags(u32 *flags)
{
enum {
FALCON_RESET_INVISIBLE = (ETH_RESET_DMA | ETH_RESET_FILTER |
ETH_RESET_OFFLOAD | ETH_RESET_MAC),
FALCON_RESET_ALL = FALCON_RESET_INVISIBLE | ETH_RESET_PHY,
FALCON_RESET_WORLD = FALCON_RESET_ALL | ETH_RESET_IRQ,
};
if ((*flags & FALCON_RESET_WORLD) == FALCON_RESET_WORLD) {
*flags &= ~FALCON_RESET_WORLD;
return RESET_TYPE_WORLD;
}
if ((*flags & FALCON_RESET_ALL) == FALCON_RESET_ALL) {
*flags &= ~FALCON_RESET_ALL;
return RESET_TYPE_ALL;
}
if ((*flags & FALCON_RESET_INVISIBLE) == FALCON_RESET_INVISIBLE) {
*flags &= ~FALCON_RESET_INVISIBLE;
return RESET_TYPE_INVISIBLE;
}
return -EINVAL;
}
static int __falcon_reset_hw(struct efx_nic *efx, enum reset_type method)
{
struct falcon_nic_data *nic_data = efx->nic_data;
efx_oword_t glb_ctl_reg_ker;
int rc;
netif_dbg(efx, hw, efx->net_dev, "performing %s hardware reset\n",
RESET_TYPE(method));
if (method == RESET_TYPE_WORLD) {
rc = pci_save_state(efx->pci_dev);
if (rc) {
netif_err(efx, drv, efx->net_dev,
"failed to backup PCI state of primary "
"function prior to hardware reset\n");
goto fail1;
}
if (efx_nic_is_dual_func(efx)) {
rc = pci_save_state(nic_data->pci_dev2);
if (rc) {
netif_err(efx, drv, efx->net_dev,
"failed to backup PCI state of "
"secondary function prior to "
"hardware reset\n");
goto fail2;
}
}
EFX_POPULATE_OWORD_2(glb_ctl_reg_ker,
FRF_AB_EXT_PHY_RST_DUR,
FFE_AB_EXT_PHY_RST_DUR_10240US,
FRF_AB_SWRST, 1);
} else {
EFX_POPULATE_OWORD_7(glb_ctl_reg_ker,
FRF_AB_EXT_PHY_RST_CTL,
method == RESET_TYPE_INVISIBLE,
FRF_AB_PCIE_CORE_RST_CTL, 1,
FRF_AB_PCIE_NSTKY_RST_CTL, 1,
FRF_AB_PCIE_SD_RST_CTL, 1,
FRF_AB_EE_RST_CTL, 1,
FRF_AB_EXT_PHY_RST_DUR,
FFE_AB_EXT_PHY_RST_DUR_10240US,
FRF_AB_SWRST, 1);
}
efx_writeo(efx, &glb_ctl_reg_ker, FR_AB_GLB_CTL);
netif_dbg(efx, hw, efx->net_dev, "waiting for hardware reset\n");
schedule_timeout_uninterruptible(HZ / 20);
if (method == RESET_TYPE_WORLD) {
if (efx_nic_is_dual_func(efx))
pci_restore_state(nic_data->pci_dev2);
pci_restore_state(efx->pci_dev);
netif_dbg(efx, drv, efx->net_dev,
"successfully restored PCI config\n");
}
efx_reado(efx, &glb_ctl_reg_ker, FR_AB_GLB_CTL);
if (EFX_OWORD_FIELD(glb_ctl_reg_ker, FRF_AB_SWRST) != 0) {
rc = -ETIMEDOUT;
netif_err(efx, hw, efx->net_dev,
"timed out waiting for hardware reset\n");
goto fail3;
}
netif_dbg(efx, hw, efx->net_dev, "hardware reset complete\n");
return 0;
fail2:
pci_restore_state(efx->pci_dev);
fail1:
fail3:
return rc;
}
static int falcon_reset_hw(struct efx_nic *efx, enum reset_type method)
{
struct falcon_nic_data *nic_data = efx->nic_data;
int rc;
mutex_lock(&nic_data->spi_lock);
rc = __falcon_reset_hw(efx, method);
mutex_unlock(&nic_data->spi_lock);
return rc;
}
static void falcon_monitor(struct efx_nic *efx)
{
bool link_changed;
int rc;
BUG_ON(!mutex_is_locked(&efx->mac_lock));
rc = falcon_board(efx)->type->monitor(efx);
if (rc) {
netif_err(efx, hw, efx->net_dev,
"Board sensor %s; shutting down PHY\n",
(rc == -ERANGE) ? "reported fault" : "failed");
efx->phy_mode |= PHY_MODE_LOW_POWER;
rc = __efx_reconfigure_port(efx);
WARN_ON(rc);
}
if (LOOPBACK_INTERNAL(efx))
link_changed = falcon_loopback_link_poll(efx);
else
link_changed = efx->phy_op->poll(efx);
if (link_changed) {
falcon_stop_nic_stats(efx);
falcon_deconfigure_mac_wrapper(efx);
falcon_reset_macs(efx);
rc = efx->mac_op->reconfigure(efx);
BUG_ON(rc);
falcon_start_nic_stats(efx);
efx_link_status_changed(efx);
}
falcon_poll_xmac(efx);
}
static int falcon_reset_sram(struct efx_nic *efx)
{
efx_oword_t srm_cfg_reg_ker, gpio_cfg_reg_ker;
int count;
efx_reado(efx, &gpio_cfg_reg_ker, FR_AB_GPIO_CTL);
EFX_SET_OWORD_FIELD(gpio_cfg_reg_ker, FRF_AB_GPIO1_OEN, 1);
EFX_SET_OWORD_FIELD(gpio_cfg_reg_ker, FRF_AB_GPIO1_OUT, 1);
efx_writeo(efx, &gpio_cfg_reg_ker, FR_AB_GPIO_CTL);
EFX_POPULATE_OWORD_2(srm_cfg_reg_ker,
FRF_AZ_SRM_INIT_EN, 1,
FRF_AZ_SRM_NB_SZ, 0);
efx_writeo(efx, &srm_cfg_reg_ker, FR_AZ_SRM_CFG);
count = 0;
do {
netif_dbg(efx, hw, efx->net_dev,
"waiting for SRAM reset (attempt %d)...\n", count);
schedule_timeout_uninterruptible(HZ / 50);
efx_reado(efx, &srm_cfg_reg_ker, FR_AZ_SRM_CFG);
if (!EFX_OWORD_FIELD(srm_cfg_reg_ker, FRF_AZ_SRM_INIT_EN)) {
netif_dbg(efx, hw, efx->net_dev,
"SRAM reset complete\n");
return 0;
}
} while (++count < 20);
netif_err(efx, hw, efx->net_dev, "timed out waiting for SRAM reset\n");
return -ETIMEDOUT;
}
static void falcon_spi_device_init(struct efx_nic *efx,
struct efx_spi_device *spi_device,
unsigned int device_id, u32 device_type)
{
if (device_type != 0) {
spi_device->device_id = device_id;
spi_device->size =
1 << SPI_DEV_TYPE_FIELD(device_type, SPI_DEV_TYPE_SIZE);
spi_device->addr_len =
SPI_DEV_TYPE_FIELD(device_type, SPI_DEV_TYPE_ADDR_LEN);
spi_device->munge_address = (spi_device->size == 1 << 9 &&
spi_device->addr_len == 1);
spi_device->erase_command =
SPI_DEV_TYPE_FIELD(device_type, SPI_DEV_TYPE_ERASE_CMD);
spi_device->erase_size =
1 << SPI_DEV_TYPE_FIELD(device_type,
SPI_DEV_TYPE_ERASE_SIZE);
spi_device->block_size =
1 << SPI_DEV_TYPE_FIELD(device_type,
SPI_DEV_TYPE_BLOCK_SIZE);
} else {
spi_device->size = 0;
}
}
static int falcon_probe_nvconfig(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
struct falcon_nvconfig *nvconfig;
int rc;
nvconfig = kmalloc(sizeof(*nvconfig), GFP_KERNEL);
if (!nvconfig)
return -ENOMEM;
rc = falcon_read_nvram(efx, nvconfig);
if (rc)
goto out;
efx->phy_type = nvconfig->board_v2.port0_phy_type;
efx->mdio.prtad = nvconfig->board_v2.port0_phy_addr;
if (le16_to_cpu(nvconfig->board_struct_ver) >= 3) {
falcon_spi_device_init(
efx, &nic_data->spi_flash, FFE_AB_SPI_DEVICE_FLASH,
le32_to_cpu(nvconfig->board_v3
.spi_device_type[FFE_AB_SPI_DEVICE_FLASH]));
falcon_spi_device_init(
efx, &nic_data->spi_eeprom, FFE_AB_SPI_DEVICE_EEPROM,
le32_to_cpu(nvconfig->board_v3
.spi_device_type[FFE_AB_SPI_DEVICE_EEPROM]));
}
memcpy(efx->net_dev->perm_addr, nvconfig->mac_address[0], ETH_ALEN);
netif_dbg(efx, probe, efx->net_dev, "PHY is %d phy_id %d\n",
efx->phy_type, efx->mdio.prtad);
rc = falcon_probe_board(efx,
le16_to_cpu(nvconfig->board_v2.board_revision));
out:
kfree(nvconfig);
return rc;
}
static void falcon_probe_spi_devices(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
efx_oword_t nic_stat, gpio_ctl, ee_vpd_cfg;
int boot_dev;
efx_reado(efx, &gpio_ctl, FR_AB_GPIO_CTL);
efx_reado(efx, &nic_stat, FR_AB_NIC_STAT);
efx_reado(efx, &ee_vpd_cfg, FR_AB_EE_VPD_CFG0);
if (EFX_OWORD_FIELD(gpio_ctl, FRF_AB_GPIO3_PWRUP_VALUE)) {
boot_dev = (EFX_OWORD_FIELD(nic_stat, FRF_AB_SF_PRST) ?
FFE_AB_SPI_DEVICE_FLASH : FFE_AB_SPI_DEVICE_EEPROM);
netif_dbg(efx, probe, efx->net_dev, "Booted from %s\n",
boot_dev == FFE_AB_SPI_DEVICE_FLASH ?
"flash" : "EEPROM");
} else {
boot_dev = -1;
netif_dbg(efx, probe, efx->net_dev,
"Booted from internal ASIC settings;"
" setting SPI config\n");
EFX_POPULATE_OWORD_3(ee_vpd_cfg, FRF_AB_EE_VPD_EN, 0,
FRF_AB_EE_SF_CLOCK_DIV, 7,
FRF_AB_EE_EE_CLOCK_DIV, 63);
efx_writeo(efx, &ee_vpd_cfg, FR_AB_EE_VPD_CFG0);
}
mutex_init(&nic_data->spi_lock);
if (boot_dev == FFE_AB_SPI_DEVICE_FLASH)
falcon_spi_device_init(efx, &nic_data->spi_flash,
FFE_AB_SPI_DEVICE_FLASH,
default_flash_type);
if (boot_dev == FFE_AB_SPI_DEVICE_EEPROM)
falcon_spi_device_init(efx, &nic_data->spi_eeprom,
FFE_AB_SPI_DEVICE_EEPROM,
large_eeprom_type);
}
static int falcon_probe_nic(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data;
struct falcon_board *board;
int rc;
nic_data = kzalloc(sizeof(*nic_data), GFP_KERNEL);
if (!nic_data)
return -ENOMEM;
efx->nic_data = nic_data;
rc = -ENODEV;
if (efx_nic_fpga_ver(efx) != 0) {
netif_err(efx, probe, efx->net_dev,
"Falcon FPGA not supported\n");
goto fail1;
}
if (efx_nic_rev(efx) <= EFX_REV_FALCON_A1) {
efx_oword_t nic_stat;
struct pci_dev *dev;
u8 pci_rev = efx->pci_dev->revision;
if ((pci_rev == 0xff) || (pci_rev == 0)) {
netif_err(efx, probe, efx->net_dev,
"Falcon rev A0 not supported\n");
goto fail1;
}
efx_reado(efx, &nic_stat, FR_AB_NIC_STAT);
if (EFX_OWORD_FIELD(nic_stat, FRF_AB_STRAP_10G) == 0) {
netif_err(efx, probe, efx->net_dev,
"Falcon rev A1 1G not supported\n");
goto fail1;
}
if (EFX_OWORD_FIELD(nic_stat, FRF_AA_STRAP_PCIE) == 0) {
netif_err(efx, probe, efx->net_dev,
"Falcon rev A1 PCI-X not supported\n");
goto fail1;
}
dev = pci_dev_get(efx->pci_dev);
while ((dev = pci_get_device(EFX_VENDID_SFC, FALCON_A_S_DEVID,
dev))) {
if (dev->bus == efx->pci_dev->bus &&
dev->devfn == efx->pci_dev->devfn + 1) {
nic_data->pci_dev2 = dev;
break;
}
}
if (!nic_data->pci_dev2) {
netif_err(efx, probe, efx->net_dev,
"failed to find secondary function\n");
rc = -ENODEV;
goto fail2;
}
}
rc = __falcon_reset_hw(efx, RESET_TYPE_ALL);
if (rc) {
netif_err(efx, probe, efx->net_dev, "failed to reset NIC\n");
goto fail3;
}
rc = efx_nic_alloc_buffer(efx, &efx->irq_status, sizeof(efx_oword_t));
if (rc)
goto fail4;
BUG_ON(efx->irq_status.dma_addr & 0x0f);
netif_dbg(efx, probe, efx->net_dev,
"INT_KER at %llx (virt %p phys %llx)\n",
(u64)efx->irq_status.dma_addr,
efx->irq_status.addr,
(u64)virt_to_phys(efx->irq_status.addr));
falcon_probe_spi_devices(efx);
rc = falcon_probe_nvconfig(efx);
if (rc) {
if (rc == -EINVAL)
netif_err(efx, probe, efx->net_dev, "NVRAM is invalid\n");
goto fail5;
}
board = falcon_board(efx);
board->i2c_adap.owner = THIS_MODULE;
board->i2c_data = falcon_i2c_bit_operations;
board->i2c_data.data = efx;
board->i2c_adap.algo_data = &board->i2c_data;
board->i2c_adap.dev.parent = &efx->pci_dev->dev;
strlcpy(board->i2c_adap.name, "SFC4000 GPIO",
sizeof(board->i2c_adap.name));
rc = i2c_bit_add_bus(&board->i2c_adap);
if (rc)
goto fail5;
rc = falcon_board(efx)->type->init(efx);
if (rc) {
netif_err(efx, probe, efx->net_dev,
"failed to initialise board\n");
goto fail6;
}
nic_data->stats_disable_count = 1;
setup_timer(&nic_data->stats_timer, &falcon_stats_timer_func,
(unsigned long)efx);
return 0;
fail6:
BUG_ON(i2c_del_adapter(&board->i2c_adap));
memset(&board->i2c_adap, 0, sizeof(board->i2c_adap));
fail5:
efx_nic_free_buffer(efx, &efx->irq_status);
fail4:
fail3:
if (nic_data->pci_dev2) {
pci_dev_put(nic_data->pci_dev2);
nic_data->pci_dev2 = NULL;
}
fail2:
fail1:
kfree(efx->nic_data);
return rc;
}
static void falcon_init_rx_cfg(struct efx_nic *efx)
{
const unsigned huge_buf_size = (3 * 4096) >> 5;
const unsigned ctrl_xon_thr = 20;
const unsigned ctrl_xoff_thr = 25;
efx_oword_t reg;
efx_reado(efx, &reg, FR_AZ_RX_CFG);
if (efx_nic_rev(efx) <= EFX_REV_FALCON_A1) {
EFX_SET_OWORD_FIELD(reg, FRF_AA_RX_DESC_PUSH_EN, 0);
EFX_SET_OWORD_FIELD(reg, FRF_AA_RX_USR_BUF_SIZE,
huge_buf_size);
EFX_SET_OWORD_FIELD(reg, FRF_AA_RX_XON_MAC_TH, 512 >> 8);
EFX_SET_OWORD_FIELD(reg, FRF_AA_RX_XOFF_MAC_TH, 2048 >> 8);
EFX_SET_OWORD_FIELD(reg, FRF_AA_RX_XON_TX_TH, ctrl_xon_thr);
EFX_SET_OWORD_FIELD(reg, FRF_AA_RX_XOFF_TX_TH, ctrl_xoff_thr);
} else {
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_DESC_PUSH_EN, 0);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_USR_BUF_SIZE,
huge_buf_size);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_XON_MAC_TH, 27648 >> 8);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_XOFF_MAC_TH, 54272 >> 8);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_XON_TX_TH, ctrl_xon_thr);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_XOFF_TX_TH, ctrl_xoff_thr);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_INGR_EN, 1);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_HASH_INSRT_HDR, 1);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_HASH_ALG, 1);
EFX_SET_OWORD_FIELD(reg, FRF_BZ_RX_IP_HASH, 1);
}
EFX_SET_OWORD_FIELD(reg, FRF_AZ_RX_XOFF_MAC_EN, 1);
efx_writeo(efx, &reg, FR_AZ_RX_CFG);
}
static int falcon_init_nic(struct efx_nic *efx)
{
efx_oword_t temp;
int rc;
efx_reado(efx, &temp, FR_AB_NIC_STAT);
EFX_SET_OWORD_FIELD(temp, FRF_AB_ONCHIP_SRAM, 1);
efx_writeo(efx, &temp, FR_AB_NIC_STAT);
rc = falcon_reset_sram(efx);
if (rc)
return rc;
if (EFX_WORKAROUND_5129(efx)) {
efx_reado(efx, &temp, FR_AZ_CSR_SPARE);
EFX_SET_OWORD_FIELD(temp, FRF_AB_MEM_PERR_EN_TX_DATA, 0);
efx_writeo(efx, &temp, FR_AZ_CSR_SPARE);
}
if (EFX_WORKAROUND_7244(efx)) {
efx_reado(efx, &temp, FR_BZ_RX_FILTER_CTL);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_UDP_FULL_SRCH_LIMIT, 8);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_UDP_WILD_SRCH_LIMIT, 8);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_TCP_FULL_SRCH_LIMIT, 8);
EFX_SET_OWORD_FIELD(temp, FRF_BZ_TCP_WILD_SRCH_LIMIT, 8);
efx_writeo(efx, &temp, FR_BZ_RX_FILTER_CTL);
}
efx_reado(efx, &temp, FR_AA_RX_SELF_RST);
EFX_SET_OWORD_FIELD(temp, FRF_AA_RX_NODESC_WAIT_DIS, 1);
EFX_SET_OWORD_FIELD(temp, FRF_AA_RX_SELF_RST_EN, 1);
if (EFX_WORKAROUND_5583(efx))
EFX_SET_OWORD_FIELD(temp, FRF_AA_RX_ISCSI_DIS, 1);
efx_writeo(efx, &temp, FR_AA_RX_SELF_RST);
efx_reado(efx, &temp, FR_AZ_TX_CFG);
EFX_SET_OWORD_FIELD(temp, FRF_AZ_TX_NO_EOP_DISC_EN, 0);
efx_writeo(efx, &temp, FR_AZ_TX_CFG);
falcon_init_rx_cfg(efx);
if (efx_nic_rev(efx) >= EFX_REV_FALCON_B0) {
memcpy(&temp, efx->rx_hash_key, sizeof(temp));
efx_writeo(efx, &temp, FR_BZ_RX_RSS_TKEY);
EFX_POPULATE_OWORD_1(temp, FRF_BZ_FLS_EVQ_ID, 0);
efx_writeo(efx, &temp, FR_BZ_DP_CTRL);
}
efx_nic_init_common(efx);
return 0;
}
static void falcon_remove_nic(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
struct falcon_board *board = falcon_board(efx);
int rc;
board->type->fini(efx);
rc = i2c_del_adapter(&board->i2c_adap);
BUG_ON(rc);
memset(&board->i2c_adap, 0, sizeof(board->i2c_adap));
efx_nic_free_buffer(efx, &efx->irq_status);
__falcon_reset_hw(efx, RESET_TYPE_ALL);
if (nic_data->pci_dev2) {
pci_dev_put(nic_data->pci_dev2);
nic_data->pci_dev2 = NULL;
}
kfree(efx->nic_data);
efx->nic_data = NULL;
}
static void falcon_update_nic_stats(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
efx_oword_t cnt;
if (nic_data->stats_disable_count)
return;
efx_reado(efx, &cnt, FR_AZ_RX_NODESC_DROP);
efx->n_rx_nodesc_drop_cnt +=
EFX_OWORD_FIELD(cnt, FRF_AB_RX_NODESC_DROP_CNT);
if (nic_data->stats_pending &&
*nic_data->stats_dma_done == FALCON_STATS_DONE) {
nic_data->stats_pending = false;
rmb();
efx->mac_op->update_stats(efx);
}
}
void falcon_start_nic_stats(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
spin_lock_bh(&efx->stats_lock);
if (--nic_data->stats_disable_count == 0)
falcon_stats_request(efx);
spin_unlock_bh(&efx->stats_lock);
}
void falcon_stop_nic_stats(struct efx_nic *efx)
{
struct falcon_nic_data *nic_data = efx->nic_data;
int i;
might_sleep();
spin_lock_bh(&efx->stats_lock);
++nic_data->stats_disable_count;
spin_unlock_bh(&efx->stats_lock);
del_timer_sync(&nic_data->stats_timer);
for (i = 0; i < 4 && nic_data->stats_pending; i++) {
if (*nic_data->stats_dma_done == FALCON_STATS_DONE)
break;
msleep(1);
}
spin_lock_bh(&efx->stats_lock);
falcon_stats_complete(efx);
spin_unlock_bh(&efx->stats_lock);
}
static void falcon_set_id_led(struct efx_nic *efx, enum efx_led_mode mode)
{
falcon_board(efx)->type->set_id_led(efx, mode);
}
static void falcon_get_wol(struct efx_nic *efx, struct ethtool_wolinfo *wol)
{
wol->supported = 0;
wol->wolopts = 0;
memset(&wol->sopass, 0, sizeof(wol->sopass));
}
static int falcon_set_wol(struct efx_nic *efx, u32 type)
{
if (type != 0)
return -EINVAL;
return 0;
}
