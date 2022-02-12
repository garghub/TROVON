static inline void e100_write_flush(struct nic *nic)
{
(void)ioread8(&nic->csr->scb.status);
}
static void e100_enable_irq(struct nic *nic)
{
unsigned long flags;
spin_lock_irqsave(&nic->cmd_lock, flags);
iowrite8(irq_mask_none, &nic->csr->scb.cmd_hi);
e100_write_flush(nic);
spin_unlock_irqrestore(&nic->cmd_lock, flags);
}
static void e100_disable_irq(struct nic *nic)
{
unsigned long flags;
spin_lock_irqsave(&nic->cmd_lock, flags);
iowrite8(irq_mask_all, &nic->csr->scb.cmd_hi);
e100_write_flush(nic);
spin_unlock_irqrestore(&nic->cmd_lock, flags);
}
static void e100_hw_reset(struct nic *nic)
{
iowrite32(selective_reset, &nic->csr->port);
e100_write_flush(nic); udelay(20);
iowrite32(software_reset, &nic->csr->port);
e100_write_flush(nic); udelay(20);
e100_disable_irq(nic);
}
static int e100_self_test(struct nic *nic)
{
u32 dma_addr = nic->dma_addr + offsetof(struct mem, selftest);
nic->mem->selftest.signature = 0;
nic->mem->selftest.result = 0xFFFFFFFF;
iowrite32(selftest | dma_addr, &nic->csr->port);
e100_write_flush(nic);
msleep(10);
e100_disable_irq(nic);
if (nic->mem->selftest.result != 0) {
netif_err(nic, hw, nic->netdev,
"Self-test failed: result=0x%08X\n",
nic->mem->selftest.result);
return -ETIMEDOUT;
}
if (nic->mem->selftest.signature == 0) {
netif_err(nic, hw, nic->netdev, "Self-test failed: timed out\n");
return -ETIMEDOUT;
}
return 0;
}
static void e100_eeprom_write(struct nic *nic, u16 addr_len, u16 addr, __le16 data)
{
u32 cmd_addr_data[3];
u8 ctrl;
int i, j;
cmd_addr_data[0] = op_ewen << (addr_len - 2);
cmd_addr_data[1] = (((op_write << addr_len) | addr) << 16) |
le16_to_cpu(data);
cmd_addr_data[2] = op_ewds << (addr_len - 2);
for (j = 0; j < 3; j++) {
iowrite8(eecs | eesk, &nic->csr->eeprom_ctrl_lo);
e100_write_flush(nic); udelay(4);
for (i = 31; i >= 0; i--) {
ctrl = (cmd_addr_data[j] & (1 << i)) ?
eecs | eedi : eecs;
iowrite8(ctrl, &nic->csr->eeprom_ctrl_lo);
e100_write_flush(nic); udelay(4);
iowrite8(ctrl | eesk, &nic->csr->eeprom_ctrl_lo);
e100_write_flush(nic); udelay(4);
}
msleep(10);
iowrite8(0, &nic->csr->eeprom_ctrl_lo);
e100_write_flush(nic); udelay(4);
}
}
static __le16 e100_eeprom_read(struct nic *nic, u16 *addr_len, u16 addr)
{
u32 cmd_addr_data;
u16 data = 0;
u8 ctrl;
int i;
cmd_addr_data = ((op_read << *addr_len) | addr) << 16;
iowrite8(eecs | eesk, &nic->csr->eeprom_ctrl_lo);
e100_write_flush(nic); udelay(4);
for (i = 31; i >= 0; i--) {
ctrl = (cmd_addr_data & (1 << i)) ? eecs | eedi : eecs;
iowrite8(ctrl, &nic->csr->eeprom_ctrl_lo);
e100_write_flush(nic); udelay(4);
iowrite8(ctrl | eesk, &nic->csr->eeprom_ctrl_lo);
e100_write_flush(nic); udelay(4);
ctrl = ioread8(&nic->csr->eeprom_ctrl_lo);
if (!(ctrl & eedo) && i > 16) {
*addr_len -= (i - 16);
i = 17;
}
data = (data << 1) | (ctrl & eedo ? 1 : 0);
}
iowrite8(0, &nic->csr->eeprom_ctrl_lo);
e100_write_flush(nic); udelay(4);
return cpu_to_le16(data);
}
static int e100_eeprom_load(struct nic *nic)
{
u16 addr, addr_len = 8, checksum = 0;
e100_eeprom_read(nic, &addr_len, 0);
nic->eeprom_wc = 1 << addr_len;
for (addr = 0; addr < nic->eeprom_wc; addr++) {
nic->eeprom[addr] = e100_eeprom_read(nic, &addr_len, addr);
if (addr < nic->eeprom_wc - 1)
checksum += le16_to_cpu(nic->eeprom[addr]);
}
if (cpu_to_le16(0xBABA - checksum) != nic->eeprom[nic->eeprom_wc - 1]) {
netif_err(nic, probe, nic->netdev, "EEPROM corrupted\n");
if (!eeprom_bad_csum_allow)
return -EAGAIN;
}
return 0;
}
static int e100_eeprom_save(struct nic *nic, u16 start, u16 count)
{
u16 addr, addr_len = 8, checksum = 0;
e100_eeprom_read(nic, &addr_len, 0);
nic->eeprom_wc = 1 << addr_len;
if (start + count >= nic->eeprom_wc)
return -EINVAL;
for (addr = start; addr < start + count; addr++)
e100_eeprom_write(nic, addr_len, addr, nic->eeprom[addr]);
for (addr = 0; addr < nic->eeprom_wc - 1; addr++)
checksum += le16_to_cpu(nic->eeprom[addr]);
nic->eeprom[nic->eeprom_wc - 1] = cpu_to_le16(0xBABA - checksum);
e100_eeprom_write(nic, addr_len, nic->eeprom_wc - 1,
nic->eeprom[nic->eeprom_wc - 1]);
return 0;
}
static int e100_exec_cmd(struct nic *nic, u8 cmd, dma_addr_t dma_addr)
{
unsigned long flags;
unsigned int i;
int err = 0;
spin_lock_irqsave(&nic->cmd_lock, flags);
for (i = 0; i < E100_WAIT_SCB_TIMEOUT; i++) {
if (likely(!ioread8(&nic->csr->scb.cmd_lo)))
break;
cpu_relax();
if (unlikely(i > E100_WAIT_SCB_FAST))
udelay(5);
}
if (unlikely(i == E100_WAIT_SCB_TIMEOUT)) {
err = -EAGAIN;
goto err_unlock;
}
if (unlikely(cmd != cuc_resume))
iowrite32(dma_addr, &nic->csr->scb.gen_ptr);
iowrite8(cmd, &nic->csr->scb.cmd_lo);
err_unlock:
spin_unlock_irqrestore(&nic->cmd_lock, flags);
return err;
}
static int e100_exec_cb(struct nic *nic, struct sk_buff *skb,
int (*cb_prepare)(struct nic *, struct cb *, struct sk_buff *))
{
struct cb *cb;
unsigned long flags;
int err = 0;
spin_lock_irqsave(&nic->cb_lock, flags);
if (unlikely(!nic->cbs_avail)) {
err = -ENOMEM;
goto err_unlock;
}
cb = nic->cb_to_use;
nic->cb_to_use = cb->next;
nic->cbs_avail--;
cb->skb = skb;
err = cb_prepare(nic, cb, skb);
if (err)
goto err_unlock;
if (unlikely(!nic->cbs_avail))
err = -ENOSPC;
cb->command |= cpu_to_le16(cb_s);
wmb();
cb->prev->command &= cpu_to_le16(~cb_s);
while (nic->cb_to_send != nic->cb_to_use) {
if (unlikely(e100_exec_cmd(nic, nic->cuc_cmd,
nic->cb_to_send->dma_addr))) {
if (err == -ENOSPC) {
schedule_work(&nic->tx_timeout_task);
}
break;
} else {
nic->cuc_cmd = cuc_resume;
nic->cb_to_send = nic->cb_to_send->next;
}
}
err_unlock:
spin_unlock_irqrestore(&nic->cb_lock, flags);
return err;
}
static int mdio_read(struct net_device *netdev, int addr, int reg)
{
struct nic *nic = netdev_priv(netdev);
return nic->mdio_ctrl(nic, addr, mdi_read, reg, 0);
}
static void mdio_write(struct net_device *netdev, int addr, int reg, int data)
{
struct nic *nic = netdev_priv(netdev);
nic->mdio_ctrl(nic, addr, mdi_write, reg, data);
}
static u16 mdio_ctrl_hw(struct nic *nic, u32 addr, u32 dir, u32 reg, u16 data)
{
u32 data_out = 0;
unsigned int i;
unsigned long flags;
spin_lock_irqsave(&nic->mdio_lock, flags);
for (i = 100; i; --i) {
if (ioread32(&nic->csr->mdi_ctrl) & mdi_ready)
break;
udelay(20);
}
if (unlikely(!i)) {
netdev_err(nic->netdev, "e100.mdio_ctrl won't go Ready\n");
spin_unlock_irqrestore(&nic->mdio_lock, flags);
return 0;
}
iowrite32((reg << 16) | (addr << 21) | dir | data, &nic->csr->mdi_ctrl);
for (i = 0; i < 100; i++) {
udelay(20);
if ((data_out = ioread32(&nic->csr->mdi_ctrl)) & mdi_ready)
break;
}
spin_unlock_irqrestore(&nic->mdio_lock, flags);
netif_printk(nic, hw, KERN_DEBUG, nic->netdev,
"%s:addr=%d, reg=%d, data_in=0x%04X, data_out=0x%04X\n",
dir == mdi_read ? "READ" : "WRITE",
addr, reg, data, data_out);
return (u16)data_out;
}
static u16 mdio_ctrl_phy_82552_v(struct nic *nic,
u32 addr,
u32 dir,
u32 reg,
u16 data)
{
if ((reg == MII_BMCR) && (dir == mdi_write)) {
if (data & (BMCR_ANRESTART | BMCR_ANENABLE)) {
u16 advert = mdio_read(nic->netdev, nic->mii.phy_id,
MII_ADVERTISE);
if (advert & ADVERTISE_100FULL)
data |= BMCR_SPEED100 | BMCR_FULLDPLX;
else if (advert & ADVERTISE_100HALF)
data |= BMCR_SPEED100;
}
}
return mdio_ctrl_hw(nic, addr, dir, reg, data);
}
static u16 mdio_ctrl_phy_mii_emulated(struct nic *nic,
u32 addr,
u32 dir,
u32 reg,
u16 data)
{
if (dir == mdi_read) {
switch (reg) {
case MII_BMCR:
return BMCR_ANENABLE |
BMCR_FULLDPLX;
case MII_BMSR:
return BMSR_LSTATUS |
BMSR_ANEGCAPABLE |
BMSR_10FULL;
case MII_ADVERTISE:
return ADVERTISE_10HALF |
ADVERTISE_10FULL;
default:
netif_printk(nic, hw, KERN_DEBUG, nic->netdev,
"%s:addr=%d, reg=%d, data=0x%04X: unimplemented emulation!\n",
dir == mdi_read ? "READ" : "WRITE",
addr, reg, data);
return 0xFFFF;
}
} else {
switch (reg) {
default:
netif_printk(nic, hw, KERN_DEBUG, nic->netdev,
"%s:addr=%d, reg=%d, data=0x%04X: unimplemented emulation!\n",
dir == mdi_read ? "READ" : "WRITE",
addr, reg, data);
return 0xFFFF;
}
}
}
static inline int e100_phy_supports_mii(struct nic *nic)
{
return (nic->mdio_ctrl != mdio_ctrl_phy_mii_emulated);
}
static void e100_get_defaults(struct nic *nic)
{
struct param_range rfds = { .min = 16, .max = 256, .count = 256 };
struct param_range cbs = { .min = 64, .max = 256, .count = 128 };
nic->mac = (nic->flags & ich) ? mac_82559_D101M : nic->pdev->revision;
if (nic->mac == mac_unknown)
nic->mac = mac_82557_D100_A;
nic->params.rfds = rfds;
nic->params.cbs = cbs;
nic->tx_threshold = 0xE0;
nic->tx_command = cpu_to_le16(cb_tx | cb_tx_sf |
((nic->mac >= mac_82558_D101_A4) ? cb_cid : cb_i));
nic->blank_rfd.command = 0;
nic->blank_rfd.rbd = cpu_to_le32(0xFFFFFFFF);
nic->blank_rfd.size = cpu_to_le16(VLAN_ETH_FRAME_LEN + ETH_FCS_LEN);
nic->mii.phy_id_mask = 0x1F;
nic->mii.reg_num_mask = 0x1F;
nic->mii.dev = nic->netdev;
nic->mii.mdio_read = mdio_read;
nic->mii.mdio_write = mdio_write;
}
static int e100_configure(struct nic *nic, struct cb *cb, struct sk_buff *skb)
{
struct config *config = &cb->u.config;
u8 *c = (u8 *)config;
struct net_device *netdev = nic->netdev;
cb->command = cpu_to_le16(cb_config);
memset(config, 0, sizeof(struct config));
config->byte_count = 0x16;
config->rx_fifo_limit = 0x8;
config->direct_rx_dma = 0x1;
config->standard_tcb = 0x1;
config->standard_stat_counter = 0x1;
config->rx_discard_short_frames = 0x1;
config->tx_underrun_retry = 0x3;
if (e100_phy_supports_mii(nic))
config->mii_mode = 1;
config->pad10 = 0x6;
config->no_source_addr_insertion = 0x1;
config->preamble_length = 0x2;
config->ifs = 0x6;
config->ip_addr_hi = 0xF2;
config->pad15_1 = 0x1;
config->pad15_2 = 0x1;
config->crs_or_cdt = 0x0;
config->fc_delay_hi = 0x40;
config->tx_padding = 0x1;
config->fc_priority_threshold = 0x7;
config->pad18 = 0x1;
config->full_duplex_pin = 0x1;
config->pad20_1 = 0x1F;
config->fc_priority_location = 0x1;
config->pad21_1 = 0x5;
config->adaptive_ifs = nic->adaptive_ifs;
config->loopback = nic->loopback;
if (nic->mii.force_media && nic->mii.full_duplex)
config->full_duplex_force = 0x1;
if (nic->flags & promiscuous || nic->loopback) {
config->rx_save_bad_frames = 0x1;
config->rx_discard_short_frames = 0x0;
config->promiscuous_mode = 0x1;
}
if (unlikely(netdev->features & NETIF_F_RXFCS))
config->rx_crc_transfer = 0x1;
if (nic->flags & multicast_all)
config->multicast_all = 0x1;
if (netif_running(nic->netdev) || !(nic->flags & wol_magic))
config->magic_packet_disable = 0x1;
if (nic->mac >= mac_82558_D101_A4) {
config->fc_disable = 0x1;
config->mwi_enable = 0x1;
config->standard_tcb = 0x0;
config->rx_long_ok = 0x1;
if (nic->mac >= mac_82559_D101M) {
config->tno_intr = 0x1;
if (nic->mac >= mac_82551_10) {
config->byte_count = 0x20;
config->rx_d102_mode = 0x1;
}
} else {
config->standard_stat_counter = 0x0;
}
}
if (netdev->features & NETIF_F_RXALL) {
config->rx_save_overruns = 0x1;
config->rx_save_bad_frames = 0x1;
config->rx_discard_short_frames = 0x0;
}
netif_printk(nic, hw, KERN_DEBUG, nic->netdev, "[00-07]=%8ph\n",
c + 0);
netif_printk(nic, hw, KERN_DEBUG, nic->netdev, "[08-15]=%8ph\n",
c + 8);
netif_printk(nic, hw, KERN_DEBUG, nic->netdev, "[16-23]=%8ph\n",
c + 16);
return 0;
}
static const struct firmware *e100_request_firmware(struct nic *nic)
{
const char *fw_name;
const struct firmware *fw = nic->fw;
u8 timer, bundle, min_size;
int err = 0;
bool required = false;
if (nic->flags & ich)
return NULL;
if (nic->mac == mac_82559_D101M) {
fw_name = FIRMWARE_D101M;
} else if (nic->mac == mac_82559_D101S) {
fw_name = FIRMWARE_D101S;
} else if (nic->mac == mac_82551_F || nic->mac == mac_82551_10) {
fw_name = FIRMWARE_D102E;
required = true;
} else {
return NULL;
}
if (!fw)
err = request_firmware(&fw, fw_name, &nic->pdev->dev);
if (err) {
if (required) {
netif_err(nic, probe, nic->netdev,
"Failed to load firmware \"%s\": %d\n",
fw_name, err);
return ERR_PTR(err);
} else {
netif_info(nic, probe, nic->netdev,
"CPUSaver disabled. Needs \"%s\": %d\n",
fw_name, err);
return NULL;
}
}
if (fw->size != UCODE_SIZE * 4 + 3) {
netif_err(nic, probe, nic->netdev,
"Firmware \"%s\" has wrong size %zu\n",
fw_name, fw->size);
release_firmware(fw);
return ERR_PTR(-EINVAL);
}
timer = fw->data[UCODE_SIZE * 4];
bundle = fw->data[UCODE_SIZE * 4 + 1];
min_size = fw->data[UCODE_SIZE * 4 + 2];
if (timer >= UCODE_SIZE || bundle >= UCODE_SIZE ||
min_size >= UCODE_SIZE) {
netif_err(nic, probe, nic->netdev,
"\"%s\" has bogus offset values (0x%x,0x%x,0x%x)\n",
fw_name, timer, bundle, min_size);
release_firmware(fw);
return ERR_PTR(-EINVAL);
}
nic->fw = fw;
return fw;
}
static int e100_setup_ucode(struct nic *nic, struct cb *cb,
struct sk_buff *skb)
{
const struct firmware *fw = (void *)skb;
u8 timer, bundle, min_size;
cb->skb = NULL;
memcpy(cb->u.ucode, fw->data, UCODE_SIZE * 4);
timer = fw->data[UCODE_SIZE * 4];
bundle = fw->data[UCODE_SIZE * 4 + 1];
min_size = fw->data[UCODE_SIZE * 4 + 2];
cb->u.ucode[timer] &= cpu_to_le32(0xFFFF0000);
cb->u.ucode[timer] |= cpu_to_le32(INTDELAY);
cb->u.ucode[bundle] &= cpu_to_le32(0xFFFF0000);
cb->u.ucode[bundle] |= cpu_to_le32(BUNDLEMAX);
cb->u.ucode[min_size] &= cpu_to_le32(0xFFFF0000);
cb->u.ucode[min_size] |= cpu_to_le32((BUNDLESMALL) ? 0xFFFF : 0xFF80);
cb->command = cpu_to_le16(cb_ucode | cb_el);
return 0;
}
static inline int e100_load_ucode_wait(struct nic *nic)
{
const struct firmware *fw;
int err = 0, counter = 50;
struct cb *cb = nic->cb_to_clean;
fw = e100_request_firmware(nic);
if (!fw || IS_ERR(fw))
return PTR_ERR(fw);
if ((err = e100_exec_cb(nic, (void *)fw, e100_setup_ucode)))
netif_err(nic, probe, nic->netdev,
"ucode cmd failed with error %d\n", err);
nic->cuc_cmd = cuc_start;
e100_write_flush(nic);
udelay(10);
while (!(cb->status & cpu_to_le16(cb_complete))) {
msleep(10);
if (!--counter) break;
}
iowrite8(~0, &nic->csr->scb.stat_ack);
if (!counter || !(cb->status & cpu_to_le16(cb_ok))) {
netif_err(nic, probe, nic->netdev, "ucode load failed\n");
err = -EPERM;
}
return err;
}
static int e100_setup_iaaddr(struct nic *nic, struct cb *cb,
struct sk_buff *skb)
{
cb->command = cpu_to_le16(cb_iaaddr);
memcpy(cb->u.iaaddr, nic->netdev->dev_addr, ETH_ALEN);
return 0;
}
static int e100_dump(struct nic *nic, struct cb *cb, struct sk_buff *skb)
{
cb->command = cpu_to_le16(cb_dump);
cb->u.dump_buffer_addr = cpu_to_le32(nic->dma_addr +
offsetof(struct mem, dump_buf));
return 0;
}
static int e100_phy_check_without_mii(struct nic *nic)
{
u8 phy_type;
int without_mii;
phy_type = (nic->eeprom[eeprom_phy_iface] >> 8) & 0x0f;
switch (phy_type) {
case NoSuchPhy:
case I82503:
case S80C24:
netif_info(nic, probe, nic->netdev,
"found MII-less i82503 or 80c24 or other PHY\n");
nic->mdio_ctrl = mdio_ctrl_phy_mii_emulated;
nic->mii.phy_id = 0;
without_mii = 1;
break;
default:
without_mii = 0;
break;
}
return without_mii;
}
static int e100_phy_init(struct nic *nic)
{
struct net_device *netdev = nic->netdev;
u32 addr;
u16 bmcr, stat, id_lo, id_hi, cong;
for (addr = 0; addr < 32; addr++) {
nic->mii.phy_id = (addr == 0) ? 1 : (addr == 1) ? 0 : addr;
bmcr = mdio_read(netdev, nic->mii.phy_id, MII_BMCR);
stat = mdio_read(netdev, nic->mii.phy_id, MII_BMSR);
stat = mdio_read(netdev, nic->mii.phy_id, MII_BMSR);
if (!((bmcr == 0xFFFF) || ((stat == 0) && (bmcr == 0))))
break;
}
if (addr == 32) {
if (e100_phy_check_without_mii(nic))
return 0;
else {
netif_err(nic, hw, nic->netdev,
"Failed to locate any known PHY, aborting\n");
return -EAGAIN;
}
} else
netif_printk(nic, hw, KERN_DEBUG, nic->netdev,
"phy_addr = %d\n", nic->mii.phy_id);
id_lo = mdio_read(netdev, nic->mii.phy_id, MII_PHYSID1);
id_hi = mdio_read(netdev, nic->mii.phy_id, MII_PHYSID2);
nic->phy = (u32)id_hi << 16 | (u32)id_lo;
netif_printk(nic, hw, KERN_DEBUG, nic->netdev,
"phy ID = 0x%08X\n", nic->phy);
for (addr = 0; addr < 32; addr++) {
if (addr != nic->mii.phy_id) {
mdio_write(netdev, addr, MII_BMCR, BMCR_ISOLATE);
} else if (nic->phy != phy_82552_v) {
bmcr = mdio_read(netdev, addr, MII_BMCR);
mdio_write(netdev, addr, MII_BMCR,
bmcr & ~BMCR_ISOLATE);
}
}
if (nic->phy == phy_82552_v)
mdio_write(netdev, nic->mii.phy_id, MII_BMCR,
bmcr & ~BMCR_ISOLATE);
#define NCS_PHY_MODEL_MASK 0xFFF0FFFF
if ((nic->phy & NCS_PHY_MODEL_MASK) == phy_nsc_tx) {
cong = mdio_read(netdev, nic->mii.phy_id, MII_NSC_CONG);
cong |= NSC_CONG_TXREADY;
cong &= ~NSC_CONG_ENABLE;
mdio_write(netdev, nic->mii.phy_id, MII_NSC_CONG, cong);
}
if (nic->phy == phy_82552_v) {
u16 advert = mdio_read(netdev, nic->mii.phy_id, MII_ADVERTISE);
nic->mdio_ctrl = mdio_ctrl_phy_82552_v;
advert |= ADVERTISE_PAUSE_CAP | ADVERTISE_PAUSE_ASYM;
mdio_write(netdev, nic->mii.phy_id, MII_ADVERTISE, advert);
bmcr = mdio_read(netdev, nic->mii.phy_id, MII_BMCR);
bmcr |= BMCR_RESET;
mdio_write(netdev, nic->mii.phy_id, MII_BMCR, bmcr);
} else if ((nic->mac >= mac_82550_D102) || ((nic->flags & ich) &&
(mdio_read(netdev, nic->mii.phy_id, MII_TPISTATUS) & 0x8000) &&
!(nic->eeprom[eeprom_cnfg_mdix] & eeprom_mdix_enabled))) {
mdio_write(netdev, nic->mii.phy_id, MII_NCONFIG,
nic->mii.force_media ? 0 : NCONFIG_AUTO_SWITCH);
}
return 0;
}
static int e100_hw_init(struct nic *nic)
{
int err = 0;
e100_hw_reset(nic);
netif_err(nic, hw, nic->netdev, "e100_hw_init\n");
if (!in_interrupt() && (err = e100_self_test(nic)))
return err;
if ((err = e100_phy_init(nic)))
return err;
if ((err = e100_exec_cmd(nic, cuc_load_base, 0)))
return err;
if ((err = e100_exec_cmd(nic, ruc_load_base, 0)))
return err;
if ((err = e100_load_ucode_wait(nic)))
return err;
if ((err = e100_exec_cb(nic, NULL, e100_configure)))
return err;
if ((err = e100_exec_cb(nic, NULL, e100_setup_iaaddr)))
return err;
if ((err = e100_exec_cmd(nic, cuc_dump_addr,
nic->dma_addr + offsetof(struct mem, stats))))
return err;
if ((err = e100_exec_cmd(nic, cuc_dump_reset, 0)))
return err;
e100_disable_irq(nic);
return 0;
}
static int e100_multi(struct nic *nic, struct cb *cb, struct sk_buff *skb)
{
struct net_device *netdev = nic->netdev;
struct netdev_hw_addr *ha;
u16 i, count = min(netdev_mc_count(netdev), E100_MAX_MULTICAST_ADDRS);
cb->command = cpu_to_le16(cb_multi);
cb->u.multi.count = cpu_to_le16(count * ETH_ALEN);
i = 0;
netdev_for_each_mc_addr(ha, netdev) {
if (i == count)
break;
memcpy(&cb->u.multi.addr[i++ * ETH_ALEN], &ha->addr,
ETH_ALEN);
}
return 0;
}
static void e100_set_multicast_list(struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
netif_printk(nic, hw, KERN_DEBUG, nic->netdev,
"mc_count=%d, flags=0x%04X\n",
netdev_mc_count(netdev), netdev->flags);
if (netdev->flags & IFF_PROMISC)
nic->flags |= promiscuous;
else
nic->flags &= ~promiscuous;
if (netdev->flags & IFF_ALLMULTI ||
netdev_mc_count(netdev) > E100_MAX_MULTICAST_ADDRS)
nic->flags |= multicast_all;
else
nic->flags &= ~multicast_all;
e100_exec_cb(nic, NULL, e100_configure);
e100_exec_cb(nic, NULL, e100_multi);
}
static void e100_update_stats(struct nic *nic)
{
struct net_device *dev = nic->netdev;
struct net_device_stats *ns = &dev->stats;
struct stats *s = &nic->mem->stats;
__le32 *complete = (nic->mac < mac_82558_D101_A4) ? &s->fc_xmt_pause :
(nic->mac < mac_82559_D101M) ? (__le32 *)&s->xmt_tco_frames :
&s->complete;
if (*complete == cpu_to_le32(cuc_dump_reset_complete)) {
*complete = 0;
nic->tx_frames = le32_to_cpu(s->tx_good_frames);
nic->tx_collisions = le32_to_cpu(s->tx_total_collisions);
ns->tx_aborted_errors += le32_to_cpu(s->tx_max_collisions);
ns->tx_window_errors += le32_to_cpu(s->tx_late_collisions);
ns->tx_carrier_errors += le32_to_cpu(s->tx_lost_crs);
ns->tx_fifo_errors += le32_to_cpu(s->tx_underruns);
ns->collisions += nic->tx_collisions;
ns->tx_errors += le32_to_cpu(s->tx_max_collisions) +
le32_to_cpu(s->tx_lost_crs);
nic->rx_short_frame_errors +=
le32_to_cpu(s->rx_short_frame_errors);
ns->rx_length_errors = nic->rx_short_frame_errors +
nic->rx_over_length_errors;
ns->rx_crc_errors += le32_to_cpu(s->rx_crc_errors);
ns->rx_frame_errors += le32_to_cpu(s->rx_alignment_errors);
ns->rx_over_errors += le32_to_cpu(s->rx_overrun_errors);
ns->rx_fifo_errors += le32_to_cpu(s->rx_overrun_errors);
ns->rx_missed_errors += le32_to_cpu(s->rx_resource_errors);
ns->rx_errors += le32_to_cpu(s->rx_crc_errors) +
le32_to_cpu(s->rx_alignment_errors) +
le32_to_cpu(s->rx_short_frame_errors) +
le32_to_cpu(s->rx_cdt_errors);
nic->tx_deferred += le32_to_cpu(s->tx_deferred);
nic->tx_single_collisions +=
le32_to_cpu(s->tx_single_collisions);
nic->tx_multiple_collisions +=
le32_to_cpu(s->tx_multiple_collisions);
if (nic->mac >= mac_82558_D101_A4) {
nic->tx_fc_pause += le32_to_cpu(s->fc_xmt_pause);
nic->rx_fc_pause += le32_to_cpu(s->fc_rcv_pause);
nic->rx_fc_unsupported +=
le32_to_cpu(s->fc_rcv_unsupported);
if (nic->mac >= mac_82559_D101M) {
nic->tx_tco_frames +=
le16_to_cpu(s->xmt_tco_frames);
nic->rx_tco_frames +=
le16_to_cpu(s->rcv_tco_frames);
}
}
}
if (e100_exec_cmd(nic, cuc_dump_reset, 0))
netif_printk(nic, tx_err, KERN_DEBUG, nic->netdev,
"exec cuc_dump_reset failed\n");
}
static void e100_adjust_adaptive_ifs(struct nic *nic, int speed, int duplex)
{
if (duplex == DUPLEX_HALF) {
u32 prev = nic->adaptive_ifs;
u32 min_frames = (speed == SPEED_100) ? 1000 : 100;
if ((nic->tx_frames / 32 < nic->tx_collisions) &&
(nic->tx_frames > min_frames)) {
if (nic->adaptive_ifs < 60)
nic->adaptive_ifs += 5;
} else if (nic->tx_frames < min_frames) {
if (nic->adaptive_ifs >= 5)
nic->adaptive_ifs -= 5;
}
if (nic->adaptive_ifs != prev)
e100_exec_cb(nic, NULL, e100_configure);
}
}
static void e100_watchdog(unsigned long data)
{
struct nic *nic = (struct nic *)data;
struct ethtool_cmd cmd = { .cmd = ETHTOOL_GSET };
u32 speed;
netif_printk(nic, timer, KERN_DEBUG, nic->netdev,
"right now = %ld\n", jiffies);
mii_ethtool_gset(&nic->mii, &cmd);
speed = ethtool_cmd_speed(&cmd);
if (mii_link_ok(&nic->mii) && !netif_carrier_ok(nic->netdev)) {
netdev_info(nic->netdev, "NIC Link is Up %u Mbps %s Duplex\n",
speed == SPEED_100 ? 100 : 10,
cmd.duplex == DUPLEX_FULL ? "Full" : "Half");
} else if (!mii_link_ok(&nic->mii) && netif_carrier_ok(nic->netdev)) {
netdev_info(nic->netdev, "NIC Link is Down\n");
}
mii_check_link(&nic->mii);
spin_lock_irq(&nic->cmd_lock);
iowrite8(ioread8(&nic->csr->scb.cmd_hi) | irq_sw_gen,&nic->csr->scb.cmd_hi);
e100_write_flush(nic);
spin_unlock_irq(&nic->cmd_lock);
e100_update_stats(nic);
e100_adjust_adaptive_ifs(nic, speed, cmd.duplex);
if (nic->mac <= mac_82557_D100_C)
e100_set_multicast_list(nic->netdev);
if (nic->flags & ich && speed == SPEED_10 && cmd.duplex == DUPLEX_HALF)
nic->flags |= ich_10h_workaround;
else
nic->flags &= ~ich_10h_workaround;
mod_timer(&nic->watchdog,
round_jiffies(jiffies + E100_WATCHDOG_PERIOD));
}
static int e100_xmit_prepare(struct nic *nic, struct cb *cb,
struct sk_buff *skb)
{
dma_addr_t dma_addr;
cb->command = nic->tx_command;
dma_addr = pci_map_single(nic->pdev,
skb->data, skb->len, PCI_DMA_TODEVICE);
if (pci_dma_mapping_error(nic->pdev, dma_addr))
return -ENOMEM;
if (unlikely(skb->no_fcs))
cb->command |= cpu_to_le16(cb_tx_nc);
else
cb->command &= ~cpu_to_le16(cb_tx_nc);
if ((nic->cbs_avail & ~15) == nic->cbs_avail)
cb->command |= cpu_to_le16(cb_i);
cb->u.tcb.tbd_array = cb->dma_addr + offsetof(struct cb, u.tcb.tbd);
cb->u.tcb.tcb_byte_count = 0;
cb->u.tcb.threshold = nic->tx_threshold;
cb->u.tcb.tbd_count = 1;
cb->u.tcb.tbd.buf_addr = cpu_to_le32(dma_addr);
cb->u.tcb.tbd.size = cpu_to_le16(skb->len);
skb_tx_timestamp(skb);
return 0;
}
static netdev_tx_t e100_xmit_frame(struct sk_buff *skb,
struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
int err;
if (nic->flags & ich_10h_workaround) {
if (e100_exec_cmd(nic, cuc_nop, 0))
netif_printk(nic, tx_err, KERN_DEBUG, nic->netdev,
"exec cuc_nop failed\n");
udelay(1);
}
err = e100_exec_cb(nic, skb, e100_xmit_prepare);
switch (err) {
case -ENOSPC:
netif_printk(nic, tx_err, KERN_DEBUG, nic->netdev,
"No space for CB\n");
netif_stop_queue(netdev);
break;
case -ENOMEM:
netif_printk(nic, tx_err, KERN_DEBUG, nic->netdev,
"Out of Tx resources, returning skb\n");
netif_stop_queue(netdev);
return NETDEV_TX_BUSY;
}
return NETDEV_TX_OK;
}
static int e100_tx_clean(struct nic *nic)
{
struct net_device *dev = nic->netdev;
struct cb *cb;
int tx_cleaned = 0;
spin_lock(&nic->cb_lock);
for (cb = nic->cb_to_clean;
cb->status & cpu_to_le16(cb_complete);
cb = nic->cb_to_clean = cb->next) {
rmb();
netif_printk(nic, tx_done, KERN_DEBUG, nic->netdev,
"cb[%d]->status = 0x%04X\n",
(int)(((void*)cb - (void*)nic->cbs)/sizeof(struct cb)),
cb->status);
if (likely(cb->skb != NULL)) {
dev->stats.tx_packets++;
dev->stats.tx_bytes += cb->skb->len;
pci_unmap_single(nic->pdev,
le32_to_cpu(cb->u.tcb.tbd.buf_addr),
le16_to_cpu(cb->u.tcb.tbd.size),
PCI_DMA_TODEVICE);
dev_kfree_skb_any(cb->skb);
cb->skb = NULL;
tx_cleaned = 1;
}
cb->status = 0;
nic->cbs_avail++;
}
spin_unlock(&nic->cb_lock);
if (unlikely(tx_cleaned && netif_queue_stopped(nic->netdev)))
netif_wake_queue(nic->netdev);
return tx_cleaned;
}
static void e100_clean_cbs(struct nic *nic)
{
if (nic->cbs) {
while (nic->cbs_avail != nic->params.cbs.count) {
struct cb *cb = nic->cb_to_clean;
if (cb->skb) {
pci_unmap_single(nic->pdev,
le32_to_cpu(cb->u.tcb.tbd.buf_addr),
le16_to_cpu(cb->u.tcb.tbd.size),
PCI_DMA_TODEVICE);
dev_kfree_skb(cb->skb);
}
nic->cb_to_clean = nic->cb_to_clean->next;
nic->cbs_avail++;
}
pci_pool_free(nic->cbs_pool, nic->cbs, nic->cbs_dma_addr);
nic->cbs = NULL;
nic->cbs_avail = 0;
}
nic->cuc_cmd = cuc_start;
nic->cb_to_use = nic->cb_to_send = nic->cb_to_clean =
nic->cbs;
}
static int e100_alloc_cbs(struct nic *nic)
{
struct cb *cb;
unsigned int i, count = nic->params.cbs.count;
nic->cuc_cmd = cuc_start;
nic->cb_to_use = nic->cb_to_send = nic->cb_to_clean = NULL;
nic->cbs_avail = 0;
nic->cbs = pci_pool_alloc(nic->cbs_pool, GFP_KERNEL,
&nic->cbs_dma_addr);
if (!nic->cbs)
return -ENOMEM;
memset(nic->cbs, 0, count * sizeof(struct cb));
for (cb = nic->cbs, i = 0; i < count; cb++, i++) {
cb->next = (i + 1 < count) ? cb + 1 : nic->cbs;
cb->prev = (i == 0) ? nic->cbs + count - 1 : cb - 1;
cb->dma_addr = nic->cbs_dma_addr + i * sizeof(struct cb);
cb->link = cpu_to_le32(nic->cbs_dma_addr +
((i+1) % count) * sizeof(struct cb));
}
nic->cb_to_use = nic->cb_to_send = nic->cb_to_clean = nic->cbs;
nic->cbs_avail = count;
return 0;
}
static inline void e100_start_receiver(struct nic *nic, struct rx *rx)
{
if (!nic->rxs) return;
if (RU_SUSPENDED != nic->ru_running) return;
if (!rx) rx = nic->rxs;
if (rx->skb) {
e100_exec_cmd(nic, ruc_start, rx->dma_addr);
nic->ru_running = RU_RUNNING;
}
}
static int e100_rx_alloc_skb(struct nic *nic, struct rx *rx)
{
if (!(rx->skb = netdev_alloc_skb_ip_align(nic->netdev, RFD_BUF_LEN)))
return -ENOMEM;
skb_copy_to_linear_data(rx->skb, &nic->blank_rfd, sizeof(struct rfd));
rx->dma_addr = pci_map_single(nic->pdev, rx->skb->data,
RFD_BUF_LEN, PCI_DMA_BIDIRECTIONAL);
if (pci_dma_mapping_error(nic->pdev, rx->dma_addr)) {
dev_kfree_skb_any(rx->skb);
rx->skb = NULL;
rx->dma_addr = 0;
return -ENOMEM;
}
if (rx->prev->skb) {
struct rfd *prev_rfd = (struct rfd *)rx->prev->skb->data;
put_unaligned_le32(rx->dma_addr, &prev_rfd->link);
pci_dma_sync_single_for_device(nic->pdev, rx->prev->dma_addr,
sizeof(struct rfd), PCI_DMA_BIDIRECTIONAL);
}
return 0;
}
static int e100_rx_indicate(struct nic *nic, struct rx *rx,
unsigned int *work_done, unsigned int work_to_do)
{
struct net_device *dev = nic->netdev;
struct sk_buff *skb = rx->skb;
struct rfd *rfd = (struct rfd *)skb->data;
u16 rfd_status, actual_size;
u16 fcs_pad = 0;
if (unlikely(work_done && *work_done >= work_to_do))
return -EAGAIN;
pci_dma_sync_single_for_cpu(nic->pdev, rx->dma_addr,
sizeof(struct rfd), PCI_DMA_BIDIRECTIONAL);
rfd_status = le16_to_cpu(rfd->status);
netif_printk(nic, rx_status, KERN_DEBUG, nic->netdev,
"status=0x%04X\n", rfd_status);
rmb();
if (unlikely(!(rfd_status & cb_complete))) {
if ((le16_to_cpu(rfd->command) & cb_el) &&
(RU_RUNNING == nic->ru_running))
if (ioread8(&nic->csr->scb.status) & rus_no_res)
nic->ru_running = RU_SUSPENDED;
pci_dma_sync_single_for_device(nic->pdev, rx->dma_addr,
sizeof(struct rfd),
PCI_DMA_FROMDEVICE);
return -ENODATA;
}
if (unlikely(dev->features & NETIF_F_RXFCS))
fcs_pad = 4;
actual_size = le16_to_cpu(rfd->actual_size) & 0x3FFF;
if (unlikely(actual_size > RFD_BUF_LEN - sizeof(struct rfd)))
actual_size = RFD_BUF_LEN - sizeof(struct rfd);
pci_unmap_single(nic->pdev, rx->dma_addr,
RFD_BUF_LEN, PCI_DMA_BIDIRECTIONAL);
if ((le16_to_cpu(rfd->command) & cb_el) &&
(RU_RUNNING == nic->ru_running)) {
if (ioread8(&nic->csr->scb.status) & rus_no_res)
nic->ru_running = RU_SUSPENDED;
}
skb_reserve(skb, sizeof(struct rfd));
skb_put(skb, actual_size);
skb->protocol = eth_type_trans(skb, nic->netdev);
if (unlikely(dev->features & NETIF_F_RXALL)) {
if (actual_size > ETH_DATA_LEN + VLAN_ETH_HLEN + fcs_pad)
nic->rx_over_length_errors++;
goto process_skb;
}
if (unlikely(!(rfd_status & cb_ok))) {
dev_kfree_skb_any(skb);
} else if (actual_size > ETH_DATA_LEN + VLAN_ETH_HLEN + fcs_pad) {
nic->rx_over_length_errors++;
dev_kfree_skb_any(skb);
} else {
process_skb:
dev->stats.rx_packets++;
dev->stats.rx_bytes += (actual_size - fcs_pad);
netif_receive_skb(skb);
if (work_done)
(*work_done)++;
}
rx->skb = NULL;
return 0;
}
static void e100_rx_clean(struct nic *nic, unsigned int *work_done,
unsigned int work_to_do)
{
struct rx *rx;
int restart_required = 0, err = 0;
struct rx *old_before_last_rx, *new_before_last_rx;
struct rfd *old_before_last_rfd, *new_before_last_rfd;
for (rx = nic->rx_to_clean; rx->skb; rx = nic->rx_to_clean = rx->next) {
err = e100_rx_indicate(nic, rx, work_done, work_to_do);
if (-EAGAIN == err || -ENODATA == err)
break;
}
if (-EAGAIN != err && RU_SUSPENDED == nic->ru_running)
restart_required = 1;
old_before_last_rx = nic->rx_to_use->prev->prev;
old_before_last_rfd = (struct rfd *)old_before_last_rx->skb->data;
for (rx = nic->rx_to_use; !rx->skb; rx = nic->rx_to_use = rx->next) {
if (unlikely(e100_rx_alloc_skb(nic, rx)))
break;
}
new_before_last_rx = nic->rx_to_use->prev->prev;
if (new_before_last_rx != old_before_last_rx) {
new_before_last_rfd =
(struct rfd *)new_before_last_rx->skb->data;
new_before_last_rfd->size = 0;
new_before_last_rfd->command |= cpu_to_le16(cb_el);
pci_dma_sync_single_for_device(nic->pdev,
new_before_last_rx->dma_addr, sizeof(struct rfd),
PCI_DMA_BIDIRECTIONAL);
old_before_last_rfd->command &= ~cpu_to_le16(cb_el);
pci_dma_sync_single_for_device(nic->pdev,
old_before_last_rx->dma_addr, sizeof(struct rfd),
PCI_DMA_BIDIRECTIONAL);
old_before_last_rfd->size = cpu_to_le16(VLAN_ETH_FRAME_LEN
+ ETH_FCS_LEN);
pci_dma_sync_single_for_device(nic->pdev,
old_before_last_rx->dma_addr, sizeof(struct rfd),
PCI_DMA_BIDIRECTIONAL);
}
if (restart_required) {
iowrite8(stat_ack_rnr, &nic->csr->scb.stat_ack);
e100_start_receiver(nic, nic->rx_to_clean);
if (work_done)
(*work_done)++;
}
}
static void e100_rx_clean_list(struct nic *nic)
{
struct rx *rx;
unsigned int i, count = nic->params.rfds.count;
nic->ru_running = RU_UNINITIALIZED;
if (nic->rxs) {
for (rx = nic->rxs, i = 0; i < count; rx++, i++) {
if (rx->skb) {
pci_unmap_single(nic->pdev, rx->dma_addr,
RFD_BUF_LEN, PCI_DMA_BIDIRECTIONAL);
dev_kfree_skb(rx->skb);
}
}
kfree(nic->rxs);
nic->rxs = NULL;
}
nic->rx_to_use = nic->rx_to_clean = NULL;
}
static int e100_rx_alloc_list(struct nic *nic)
{
struct rx *rx;
unsigned int i, count = nic->params.rfds.count;
struct rfd *before_last;
nic->rx_to_use = nic->rx_to_clean = NULL;
nic->ru_running = RU_UNINITIALIZED;
if (!(nic->rxs = kcalloc(count, sizeof(struct rx), GFP_ATOMIC)))
return -ENOMEM;
for (rx = nic->rxs, i = 0; i < count; rx++, i++) {
rx->next = (i + 1 < count) ? rx + 1 : nic->rxs;
rx->prev = (i == 0) ? nic->rxs + count - 1 : rx - 1;
if (e100_rx_alloc_skb(nic, rx)) {
e100_rx_clean_list(nic);
return -ENOMEM;
}
}
rx = nic->rxs->prev->prev;
before_last = (struct rfd *)rx->skb->data;
before_last->command |= cpu_to_le16(cb_el);
before_last->size = 0;
pci_dma_sync_single_for_device(nic->pdev, rx->dma_addr,
sizeof(struct rfd), PCI_DMA_BIDIRECTIONAL);
nic->rx_to_use = nic->rx_to_clean = nic->rxs;
nic->ru_running = RU_SUSPENDED;
return 0;
}
static irqreturn_t e100_intr(int irq, void *dev_id)
{
struct net_device *netdev = dev_id;
struct nic *nic = netdev_priv(netdev);
u8 stat_ack = ioread8(&nic->csr->scb.stat_ack);
netif_printk(nic, intr, KERN_DEBUG, nic->netdev,
"stat_ack = 0x%02X\n", stat_ack);
if (stat_ack == stat_ack_not_ours ||
stat_ack == stat_ack_not_present)
return IRQ_NONE;
iowrite8(stat_ack, &nic->csr->scb.stat_ack);
if (stat_ack & stat_ack_rnr)
nic->ru_running = RU_SUSPENDED;
if (likely(napi_schedule_prep(&nic->napi))) {
e100_disable_irq(nic);
__napi_schedule(&nic->napi);
}
return IRQ_HANDLED;
}
static int e100_poll(struct napi_struct *napi, int budget)
{
struct nic *nic = container_of(napi, struct nic, napi);
unsigned int work_done = 0;
e100_rx_clean(nic, &work_done, budget);
e100_tx_clean(nic);
if (work_done < budget) {
napi_complete(napi);
e100_enable_irq(nic);
}
return work_done;
}
static void e100_netpoll(struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
e100_disable_irq(nic);
e100_intr(nic->pdev->irq, netdev);
e100_tx_clean(nic);
e100_enable_irq(nic);
}
static int e100_set_mac_address(struct net_device *netdev, void *p)
{
struct nic *nic = netdev_priv(netdev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
e100_exec_cb(nic, NULL, e100_setup_iaaddr);
return 0;
}
static int e100_change_mtu(struct net_device *netdev, int new_mtu)
{
if (new_mtu < ETH_ZLEN || new_mtu > ETH_DATA_LEN)
return -EINVAL;
netdev->mtu = new_mtu;
return 0;
}
static int e100_asf(struct nic *nic)
{
return (nic->pdev->device >= 0x1050) && (nic->pdev->device <= 0x1057) &&
(nic->eeprom[eeprom_config_asf] & eeprom_asf) &&
!(nic->eeprom[eeprom_config_asf] & eeprom_gcl) &&
((nic->eeprom[eeprom_smbus_addr] & 0xFF) != 0xFE);
}
static int e100_up(struct nic *nic)
{
int err;
if ((err = e100_rx_alloc_list(nic)))
return err;
if ((err = e100_alloc_cbs(nic)))
goto err_rx_clean_list;
if ((err = e100_hw_init(nic)))
goto err_clean_cbs;
e100_set_multicast_list(nic->netdev);
e100_start_receiver(nic, NULL);
mod_timer(&nic->watchdog, jiffies);
if ((err = request_irq(nic->pdev->irq, e100_intr, IRQF_SHARED,
nic->netdev->name, nic->netdev)))
goto err_no_irq;
netif_wake_queue(nic->netdev);
napi_enable(&nic->napi);
e100_enable_irq(nic);
return 0;
err_no_irq:
del_timer_sync(&nic->watchdog);
err_clean_cbs:
e100_clean_cbs(nic);
err_rx_clean_list:
e100_rx_clean_list(nic);
return err;
}
static void e100_down(struct nic *nic)
{
napi_disable(&nic->napi);
netif_stop_queue(nic->netdev);
e100_hw_reset(nic);
free_irq(nic->pdev->irq, nic->netdev);
del_timer_sync(&nic->watchdog);
netif_carrier_off(nic->netdev);
e100_clean_cbs(nic);
e100_rx_clean_list(nic);
}
static void e100_tx_timeout(struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
schedule_work(&nic->tx_timeout_task);
}
static void e100_tx_timeout_task(struct work_struct *work)
{
struct nic *nic = container_of(work, struct nic, tx_timeout_task);
struct net_device *netdev = nic->netdev;
netif_printk(nic, tx_err, KERN_DEBUG, nic->netdev,
"scb.status=0x%02X\n", ioread8(&nic->csr->scb.status));
rtnl_lock();
if (netif_running(netdev)) {
e100_down(netdev_priv(netdev));
e100_up(netdev_priv(netdev));
}
rtnl_unlock();
}
static int e100_loopback_test(struct nic *nic, enum loopback loopback_mode)
{
int err;
struct sk_buff *skb;
if ((err = e100_rx_alloc_list(nic)))
return err;
if ((err = e100_alloc_cbs(nic)))
goto err_clean_rx;
if (nic->flags & ich && loopback_mode == lb_phy)
loopback_mode = lb_mac;
nic->loopback = loopback_mode;
if ((err = e100_hw_init(nic)))
goto err_loopback_none;
if (loopback_mode == lb_phy)
mdio_write(nic->netdev, nic->mii.phy_id, MII_BMCR,
BMCR_LOOPBACK);
e100_start_receiver(nic, NULL);
if (!(skb = netdev_alloc_skb(nic->netdev, ETH_DATA_LEN))) {
err = -ENOMEM;
goto err_loopback_none;
}
skb_put(skb, ETH_DATA_LEN);
memset(skb->data, 0xFF, ETH_DATA_LEN);
e100_xmit_frame(skb, nic->netdev);
msleep(10);
pci_dma_sync_single_for_cpu(nic->pdev, nic->rx_to_clean->dma_addr,
RFD_BUF_LEN, PCI_DMA_BIDIRECTIONAL);
if (memcmp(nic->rx_to_clean->skb->data + sizeof(struct rfd),
skb->data, ETH_DATA_LEN))
err = -EAGAIN;
err_loopback_none:
mdio_write(nic->netdev, nic->mii.phy_id, MII_BMCR, 0);
nic->loopback = lb_none;
e100_clean_cbs(nic);
e100_hw_reset(nic);
err_clean_rx:
e100_rx_clean_list(nic);
return err;
}
static int e100_get_settings(struct net_device *netdev, struct ethtool_cmd *cmd)
{
struct nic *nic = netdev_priv(netdev);
return mii_ethtool_gset(&nic->mii, cmd);
}
static int e100_set_settings(struct net_device *netdev, struct ethtool_cmd *cmd)
{
struct nic *nic = netdev_priv(netdev);
int err;
mdio_write(netdev, nic->mii.phy_id, MII_BMCR, BMCR_RESET);
err = mii_ethtool_sset(&nic->mii, cmd);
e100_exec_cb(nic, NULL, e100_configure);
return err;
}
static void e100_get_drvinfo(struct net_device *netdev,
struct ethtool_drvinfo *info)
{
struct nic *nic = netdev_priv(netdev);
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
strlcpy(info->bus_info, pci_name(nic->pdev),
sizeof(info->bus_info));
}
static int e100_get_regs_len(struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
return 1 + E100_PHY_REGS + sizeof(nic->mem->dump_buf);
}
static void e100_get_regs(struct net_device *netdev,
struct ethtool_regs *regs, void *p)
{
struct nic *nic = netdev_priv(netdev);
u32 *buff = p;
int i;
regs->version = (1 << 24) | nic->pdev->revision;
buff[0] = ioread8(&nic->csr->scb.cmd_hi) << 24 |
ioread8(&nic->csr->scb.cmd_lo) << 16 |
ioread16(&nic->csr->scb.status);
for (i = E100_PHY_REGS; i >= 0; i--)
buff[1 + E100_PHY_REGS - i] =
mdio_read(netdev, nic->mii.phy_id, i);
memset(nic->mem->dump_buf, 0, sizeof(nic->mem->dump_buf));
e100_exec_cb(nic, NULL, e100_dump);
msleep(10);
memcpy(&buff[2 + E100_PHY_REGS], nic->mem->dump_buf,
sizeof(nic->mem->dump_buf));
}
static void e100_get_wol(struct net_device *netdev, struct ethtool_wolinfo *wol)
{
struct nic *nic = netdev_priv(netdev);
wol->supported = (nic->mac >= mac_82558_D101_A4) ? WAKE_MAGIC : 0;
wol->wolopts = (nic->flags & wol_magic) ? WAKE_MAGIC : 0;
}
static int e100_set_wol(struct net_device *netdev, struct ethtool_wolinfo *wol)
{
struct nic *nic = netdev_priv(netdev);
if ((wol->wolopts && wol->wolopts != WAKE_MAGIC) ||
!device_can_wakeup(&nic->pdev->dev))
return -EOPNOTSUPP;
if (wol->wolopts)
nic->flags |= wol_magic;
else
nic->flags &= ~wol_magic;
device_set_wakeup_enable(&nic->pdev->dev, wol->wolopts);
e100_exec_cb(nic, NULL, e100_configure);
return 0;
}
static u32 e100_get_msglevel(struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
return nic->msg_enable;
}
static void e100_set_msglevel(struct net_device *netdev, u32 value)
{
struct nic *nic = netdev_priv(netdev);
nic->msg_enable = value;
}
static int e100_nway_reset(struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
return mii_nway_restart(&nic->mii);
}
static u32 e100_get_link(struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
return mii_link_ok(&nic->mii);
}
static int e100_get_eeprom_len(struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
return nic->eeprom_wc << 1;
}
static int e100_get_eeprom(struct net_device *netdev,
struct ethtool_eeprom *eeprom, u8 *bytes)
{
struct nic *nic = netdev_priv(netdev);
eeprom->magic = E100_EEPROM_MAGIC;
memcpy(bytes, &((u8 *)nic->eeprom)[eeprom->offset], eeprom->len);
return 0;
}
static int e100_set_eeprom(struct net_device *netdev,
struct ethtool_eeprom *eeprom, u8 *bytes)
{
struct nic *nic = netdev_priv(netdev);
if (eeprom->magic != E100_EEPROM_MAGIC)
return -EINVAL;
memcpy(&((u8 *)nic->eeprom)[eeprom->offset], bytes, eeprom->len);
return e100_eeprom_save(nic, eeprom->offset >> 1,
(eeprom->len >> 1) + 1);
}
static void e100_get_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct nic *nic = netdev_priv(netdev);
struct param_range *rfds = &nic->params.rfds;
struct param_range *cbs = &nic->params.cbs;
ring->rx_max_pending = rfds->max;
ring->tx_max_pending = cbs->max;
ring->rx_pending = rfds->count;
ring->tx_pending = cbs->count;
}
static int e100_set_ringparam(struct net_device *netdev,
struct ethtool_ringparam *ring)
{
struct nic *nic = netdev_priv(netdev);
struct param_range *rfds = &nic->params.rfds;
struct param_range *cbs = &nic->params.cbs;
if ((ring->rx_mini_pending) || (ring->rx_jumbo_pending))
return -EINVAL;
if (netif_running(netdev))
e100_down(nic);
rfds->count = max(ring->rx_pending, rfds->min);
rfds->count = min(rfds->count, rfds->max);
cbs->count = max(ring->tx_pending, cbs->min);
cbs->count = min(cbs->count, cbs->max);
netif_info(nic, drv, nic->netdev, "Ring Param settings: rx: %d, tx %d\n",
rfds->count, cbs->count);
if (netif_running(netdev))
e100_up(nic);
return 0;
}
static void e100_diag_test(struct net_device *netdev,
struct ethtool_test *test, u64 *data)
{
struct ethtool_cmd cmd;
struct nic *nic = netdev_priv(netdev);
int i, err;
memset(data, 0, E100_TEST_LEN * sizeof(u64));
data[0] = !mii_link_ok(&nic->mii);
data[1] = e100_eeprom_load(nic);
if (test->flags & ETH_TEST_FL_OFFLINE) {
err = mii_ethtool_gset(&nic->mii, &cmd);
if (netif_running(netdev))
e100_down(nic);
data[2] = e100_self_test(nic);
data[3] = e100_loopback_test(nic, lb_mac);
data[4] = e100_loopback_test(nic, lb_phy);
err = mii_ethtool_sset(&nic->mii, &cmd);
if (netif_running(netdev))
e100_up(nic);
}
for (i = 0; i < E100_TEST_LEN; i++)
test->flags |= data[i] ? ETH_TEST_FL_FAILED : 0;
msleep_interruptible(4 * 1000);
}
static int e100_set_phys_id(struct net_device *netdev,
enum ethtool_phys_id_state state)
{
struct nic *nic = netdev_priv(netdev);
enum led_state {
led_on = 0x01,
led_off = 0x04,
led_on_559 = 0x05,
led_on_557 = 0x07,
};
u16 led_reg = (nic->phy == phy_82552_v) ? E100_82552_LED_OVERRIDE :
MII_LED_CONTROL;
u16 leds = 0;
switch (state) {
case ETHTOOL_ID_ACTIVE:
return 2;
case ETHTOOL_ID_ON:
leds = (nic->phy == phy_82552_v) ? E100_82552_LED_ON :
(nic->mac < mac_82559_D101M) ? led_on_557 : led_on_559;
break;
case ETHTOOL_ID_OFF:
leds = (nic->phy == phy_82552_v) ? E100_82552_LED_OFF : led_off;
break;
case ETHTOOL_ID_INACTIVE:
break;
}
mdio_write(netdev, nic->mii.phy_id, led_reg, leds);
return 0;
}
static int e100_get_sset_count(struct net_device *netdev, int sset)
{
switch (sset) {
case ETH_SS_TEST:
return E100_TEST_LEN;
case ETH_SS_STATS:
return E100_STATS_LEN;
default:
return -EOPNOTSUPP;
}
}
static void e100_get_ethtool_stats(struct net_device *netdev,
struct ethtool_stats *stats, u64 *data)
{
struct nic *nic = netdev_priv(netdev);
int i;
for (i = 0; i < E100_NET_STATS_LEN; i++)
data[i] = ((unsigned long *)&netdev->stats)[i];
data[i++] = nic->tx_deferred;
data[i++] = nic->tx_single_collisions;
data[i++] = nic->tx_multiple_collisions;
data[i++] = nic->tx_fc_pause;
data[i++] = nic->rx_fc_pause;
data[i++] = nic->rx_fc_unsupported;
data[i++] = nic->tx_tco_frames;
data[i++] = nic->rx_tco_frames;
data[i++] = nic->rx_short_frame_errors;
data[i++] = nic->rx_over_length_errors;
}
static void e100_get_strings(struct net_device *netdev, u32 stringset, u8 *data)
{
switch (stringset) {
case ETH_SS_TEST:
memcpy(data, *e100_gstrings_test, sizeof(e100_gstrings_test));
break;
case ETH_SS_STATS:
memcpy(data, *e100_gstrings_stats, sizeof(e100_gstrings_stats));
break;
}
}
static int e100_do_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
struct nic *nic = netdev_priv(netdev);
return generic_mii_ioctl(&nic->mii, if_mii(ifr), cmd, NULL);
}
static int e100_alloc(struct nic *nic)
{
nic->mem = pci_alloc_consistent(nic->pdev, sizeof(struct mem),
&nic->dma_addr);
return nic->mem ? 0 : -ENOMEM;
}
static void e100_free(struct nic *nic)
{
if (nic->mem) {
pci_free_consistent(nic->pdev, sizeof(struct mem),
nic->mem, nic->dma_addr);
nic->mem = NULL;
}
}
static int e100_open(struct net_device *netdev)
{
struct nic *nic = netdev_priv(netdev);
int err = 0;
netif_carrier_off(netdev);
if ((err = e100_up(nic)))
netif_err(nic, ifup, nic->netdev, "Cannot open interface, aborting\n");
return err;
}
static int e100_close(struct net_device *netdev)
{
e100_down(netdev_priv(netdev));
return 0;
}
static int e100_set_features(struct net_device *netdev,
netdev_features_t features)
{
struct nic *nic = netdev_priv(netdev);
netdev_features_t changed = features ^ netdev->features;
if (!(changed & (NETIF_F_RXFCS | NETIF_F_RXALL)))
return 0;
netdev->features = features;
e100_exec_cb(nic, NULL, e100_configure);
return 0;
}
static int e100_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev;
struct nic *nic;
int err;
if (!(netdev = alloc_etherdev(sizeof(struct nic))))
return -ENOMEM;
netdev->hw_features |= NETIF_F_RXFCS;
netdev->priv_flags |= IFF_SUPP_NOFCS;
netdev->hw_features |= NETIF_F_RXALL;
netdev->netdev_ops = &e100_netdev_ops;
netdev->ethtool_ops = &e100_ethtool_ops;
netdev->watchdog_timeo = E100_WATCHDOG_PERIOD;
strncpy(netdev->name, pci_name(pdev), sizeof(netdev->name) - 1);
nic = netdev_priv(netdev);
netif_napi_add(netdev, &nic->napi, e100_poll, E100_NAPI_WEIGHT);
nic->netdev = netdev;
nic->pdev = pdev;
nic->msg_enable = (1 << debug) - 1;
nic->mdio_ctrl = mdio_ctrl_hw;
pci_set_drvdata(pdev, netdev);
if ((err = pci_enable_device(pdev))) {
netif_err(nic, probe, nic->netdev, "Cannot enable PCI device, aborting\n");
goto err_out_free_dev;
}
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
netif_err(nic, probe, nic->netdev, "Cannot find proper PCI device base address, aborting\n");
err = -ENODEV;
goto err_out_disable_pdev;
}
if ((err = pci_request_regions(pdev, DRV_NAME))) {
netif_err(nic, probe, nic->netdev, "Cannot obtain PCI resources, aborting\n");
goto err_out_disable_pdev;
}
if ((err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32)))) {
netif_err(nic, probe, nic->netdev, "No usable DMA configuration, aborting\n");
goto err_out_free_res;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
if (use_io)
netif_info(nic, probe, nic->netdev, "using i/o access mode\n");
nic->csr = pci_iomap(pdev, (use_io ? 1 : 0), sizeof(struct csr));
if (!nic->csr) {
netif_err(nic, probe, nic->netdev, "Cannot map device registers, aborting\n");
err = -ENOMEM;
goto err_out_free_res;
}
if (ent->driver_data)
nic->flags |= ich;
else
nic->flags &= ~ich;
e100_get_defaults(nic);
if (nic->mac < mac_82558_D101_A4)
netdev->features |= NETIF_F_VLAN_CHALLENGED;
spin_lock_init(&nic->cb_lock);
spin_lock_init(&nic->cmd_lock);
spin_lock_init(&nic->mdio_lock);
e100_hw_reset(nic);
pci_set_master(pdev);
init_timer(&nic->watchdog);
nic->watchdog.function = e100_watchdog;
nic->watchdog.data = (unsigned long)nic;
INIT_WORK(&nic->tx_timeout_task, e100_tx_timeout_task);
if ((err = e100_alloc(nic))) {
netif_err(nic, probe, nic->netdev, "Cannot alloc driver memory, aborting\n");
goto err_out_iounmap;
}
if ((err = e100_eeprom_load(nic)))
goto err_out_free;
e100_phy_init(nic);
memcpy(netdev->dev_addr, nic->eeprom, ETH_ALEN);
if (!is_valid_ether_addr(netdev->dev_addr)) {
if (!eeprom_bad_csum_allow) {
netif_err(nic, probe, nic->netdev, "Invalid MAC address from EEPROM, aborting\n");
err = -EAGAIN;
goto err_out_free;
} else {
netif_err(nic, probe, nic->netdev, "Invalid MAC address from EEPROM, you MUST configure one.\n");
}
}
if ((nic->mac >= mac_82558_D101_A4) &&
(nic->eeprom[eeprom_id] & eeprom_id_wol)) {
nic->flags |= wol_magic;
device_set_wakeup_enable(&pdev->dev, true);
}
pci_pme_active(pdev, false);
strcpy(netdev->name, "eth%d");
if ((err = register_netdev(netdev))) {
netif_err(nic, probe, nic->netdev, "Cannot register net device, aborting\n");
goto err_out_free;
}
nic->cbs_pool = pci_pool_create(netdev->name,
nic->pdev,
nic->params.cbs.max * sizeof(struct cb),
sizeof(u32),
0);
netif_info(nic, probe, nic->netdev,
"addr 0x%llx, irq %d, MAC addr %pM\n",
(unsigned long long)pci_resource_start(pdev, use_io ? 1 : 0),
pdev->irq, netdev->dev_addr);
return 0;
err_out_free:
e100_free(nic);
err_out_iounmap:
pci_iounmap(pdev, nic->csr);
err_out_free_res:
pci_release_regions(pdev);
err_out_disable_pdev:
pci_disable_device(pdev);
err_out_free_dev:
free_netdev(netdev);
return err;
}
static void e100_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
if (netdev) {
struct nic *nic = netdev_priv(netdev);
unregister_netdev(netdev);
e100_free(nic);
pci_iounmap(pdev, nic->csr);
pci_pool_destroy(nic->cbs_pool);
free_netdev(netdev);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
}
static void __e100_shutdown(struct pci_dev *pdev, bool *enable_wake)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct nic *nic = netdev_priv(netdev);
if (netif_running(netdev))
e100_down(nic);
netif_device_detach(netdev);
pci_save_state(pdev);
if ((nic->flags & wol_magic) | e100_asf(nic)) {
if (nic->phy == phy_82552_v) {
u16 smartspeed = mdio_read(netdev, nic->mii.phy_id,
E100_82552_SMARTSPEED);
mdio_write(netdev, nic->mii.phy_id,
E100_82552_SMARTSPEED, smartspeed |
E100_82552_REV_ANEG | E100_82552_ANEG_NOW);
}
*enable_wake = true;
} else {
*enable_wake = false;
}
pci_clear_master(pdev);
}
static int __e100_power_off(struct pci_dev *pdev, bool wake)
{
if (wake)
return pci_prepare_to_sleep(pdev);
pci_wake_from_d3(pdev, false);
pci_set_power_state(pdev, PCI_D3hot);
return 0;
}
static int e100_suspend(struct pci_dev *pdev, pm_message_t state)
{
bool wake;
__e100_shutdown(pdev, &wake);
return __e100_power_off(pdev, wake);
}
static int e100_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct nic *nic = netdev_priv(netdev);
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
pci_enable_wake(pdev, PCI_D0, 0);
if (nic->phy == phy_82552_v) {
u16 smartspeed = mdio_read(netdev, nic->mii.phy_id,
E100_82552_SMARTSPEED);
mdio_write(netdev, nic->mii.phy_id,
E100_82552_SMARTSPEED,
smartspeed & ~(E100_82552_REV_ANEG));
}
netif_device_attach(netdev);
if (netif_running(netdev))
e100_up(nic);
return 0;
}
static void e100_shutdown(struct pci_dev *pdev)
{
bool wake;
__e100_shutdown(pdev, &wake);
if (system_state == SYSTEM_POWER_OFF)
__e100_power_off(pdev, wake);
}
static pci_ers_result_t e100_io_error_detected(struct pci_dev *pdev, pci_channel_state_t state)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct nic *nic = netdev_priv(netdev);
netif_device_detach(netdev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
if (netif_running(netdev))
e100_down(nic);
pci_disable_device(pdev);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t e100_io_slot_reset(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct nic *nic = netdev_priv(netdev);
if (pci_enable_device(pdev)) {
pr_err("Cannot re-enable PCI device after reset\n");
return PCI_ERS_RESULT_DISCONNECT;
}
pci_set_master(pdev);
if (0 != PCI_FUNC(pdev->devfn))
return PCI_ERS_RESULT_RECOVERED;
e100_hw_reset(nic);
e100_phy_init(nic);
return PCI_ERS_RESULT_RECOVERED;
}
static void e100_io_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct nic *nic = netdev_priv(netdev);
pci_enable_wake(pdev, PCI_D0, 0);
netif_device_attach(netdev);
if (netif_running(netdev)) {
e100_open(netdev);
mod_timer(&nic->watchdog, jiffies);
}
}
static int __init e100_init_module(void)
{
if (((1 << debug) - 1) & NETIF_MSG_DRV) {
pr_info("%s, %s\n", DRV_DESCRIPTION, DRV_VERSION);
pr_info("%s\n", DRV_COPYRIGHT);
}
return pci_register_driver(&e100_driver);
}
static void __exit e100_cleanup_module(void)
{
pci_unregister_driver(&e100_driver);
}
