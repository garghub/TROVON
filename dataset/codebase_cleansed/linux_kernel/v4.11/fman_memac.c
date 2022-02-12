static void add_addr_in_paddr(struct memac_regs __iomem *regs, u8 *adr,
u8 paddr_num)
{
u32 tmp0, tmp1;
tmp0 = (u32)(adr[0] | adr[1] << 8 | adr[2] << 16 | adr[3] << 24);
tmp1 = (u32)(adr[4] | adr[5] << 8);
if (paddr_num == 0) {
iowrite32be(tmp0, &regs->mac_addr0.mac_addr_l);
iowrite32be(tmp1, &regs->mac_addr0.mac_addr_u);
} else {
iowrite32be(tmp0, &regs->mac_addr[paddr_num - 1].mac_addr_l);
iowrite32be(tmp1, &regs->mac_addr[paddr_num - 1].mac_addr_u);
}
}
static int reset(struct memac_regs __iomem *regs)
{
u32 tmp;
int count;
tmp = ioread32be(&regs->command_config);
tmp |= CMD_CFG_SW_RESET;
iowrite32be(tmp, &regs->command_config);
count = 100;
do {
udelay(1);
} while ((ioread32be(&regs->command_config) & CMD_CFG_SW_RESET) &&
--count);
if (count == 0)
return -EBUSY;
return 0;
}
static void set_exception(struct memac_regs __iomem *regs, u32 val,
bool enable)
{
u32 tmp;
tmp = ioread32be(&regs->imask);
if (enable)
tmp |= val;
else
tmp &= ~val;
iowrite32be(tmp, &regs->imask);
}
static int init(struct memac_regs __iomem *regs, struct memac_cfg *cfg,
phy_interface_t phy_if, u16 speed, bool slow_10g_if,
u32 exceptions)
{
u32 tmp;
tmp = 0;
if (cfg->promiscuous_mode_enable)
tmp |= CMD_CFG_PROMIS_EN;
if (cfg->pause_ignore)
tmp |= CMD_CFG_PAUSE_IGNORE;
tmp |= CMD_CFG_NO_LEN_CHK;
tmp |= CMD_CFG_TX_PAD_EN;
tmp |= CMD_CFG_CRC_FWD;
iowrite32be(tmp, &regs->command_config);
iowrite32be((u32)cfg->max_frame_length, &regs->maxfrm);
iowrite32be((u32)cfg->pause_quanta, &regs->pause_quanta[0]);
iowrite32be((u32)0, &regs->pause_thresh[0]);
tmp = 0;
switch (phy_if) {
case PHY_INTERFACE_MODE_XGMII:
tmp |= IF_MODE_XGMII;
break;
default:
tmp |= IF_MODE_GMII;
if (phy_if == PHY_INTERFACE_MODE_RGMII)
tmp |= IF_MODE_RGMII | IF_MODE_RGMII_AUTO;
}
iowrite32be(tmp, &regs->if_mode);
tmp = 0;
if (phy_if == PHY_INTERFACE_MODE_XGMII) {
if (slow_10g_if) {
tmp |= (TX_FIFO_SECTIONS_TX_AVAIL_SLOW_10G |
TX_FIFO_SECTIONS_TX_EMPTY_DEFAULT_10G);
} else {
tmp |= (TX_FIFO_SECTIONS_TX_AVAIL_10G |
TX_FIFO_SECTIONS_TX_EMPTY_DEFAULT_10G);
}
} else {
tmp |= (TX_FIFO_SECTIONS_TX_AVAIL_1G |
TX_FIFO_SECTIONS_TX_EMPTY_DEFAULT_1G);
}
iowrite32be(tmp, &regs->tx_fifo_sections);
iowrite32be(0xffffffff, &regs->ievent);
set_exception(regs, exceptions, true);
return 0;
}
static void set_dflts(struct memac_cfg *cfg)
{
cfg->reset_on_init = false;
cfg->promiscuous_mode_enable = false;
cfg->pause_ignore = false;
cfg->tx_ipg_length = DEFAULT_TX_IPG_LENGTH;
cfg->max_frame_length = DEFAULT_FRAME_LENGTH;
cfg->pause_quanta = DEFAULT_PAUSE_QUANTA;
}
static u32 get_mac_addr_hash_code(u64 eth_addr)
{
u64 mask1, mask2;
u32 xor_val = 0;
u8 i, j;
for (i = 0; i < 6; i++) {
mask1 = eth_addr & (u64)0x01;
eth_addr >>= 1;
for (j = 0; j < 7; j++) {
mask2 = eth_addr & (u64)0x01;
mask1 ^= mask2;
eth_addr >>= 1;
}
xor_val |= (mask1 << (5 - i));
}
return xor_val;
}
static void setup_sgmii_internal_phy(struct fman_mac *memac,
struct fixed_phy_status *fixed_link)
{
u16 tmp_reg16;
if (WARN_ON(!memac->pcsphy))
return;
tmp_reg16 = IF_MODE_SGMII_EN;
if (!fixed_link)
tmp_reg16 |= IF_MODE_USE_SGMII_AN;
else {
switch (fixed_link->speed) {
case 10:
break;
case 100:
tmp_reg16 |= IF_MODE_SGMII_SPEED_100M;
break;
case 1000:
default:
tmp_reg16 |= IF_MODE_SGMII_SPEED_1G;
break;
}
if (!fixed_link->duplex)
tmp_reg16 |= IF_MODE_SGMII_DUPLEX_HALF;
}
phy_write(memac->pcsphy, MDIO_SGMII_IF_MODE, tmp_reg16);
tmp_reg16 = MDIO_SGMII_DEV_ABIL_SGMII_MODE;
phy_write(memac->pcsphy, MDIO_SGMII_DEV_ABIL_SGMII, tmp_reg16);
phy_write(memac->pcsphy, MDIO_SGMII_LINK_TMR_H, LINK_TMR_H);
phy_write(memac->pcsphy, MDIO_SGMII_LINK_TMR_L, LINK_TMR_L);
if (!fixed_link)
tmp_reg16 = SGMII_CR_DEF_VAL | SGMII_CR_RESTART_AN;
else
tmp_reg16 = SGMII_CR_DEF_VAL & ~SGMII_CR_AN_EN;
phy_write(memac->pcsphy, 0x0, tmp_reg16);
}
static void setup_sgmii_internal_phy_base_x(struct fman_mac *memac)
{
u16 tmp_reg16;
tmp_reg16 = MDIO_SGMII_DEV_ABIL_BASEX_MODE;
phy_write(memac->pcsphy, MDIO_SGMII_DEV_ABIL_SGMII, tmp_reg16);
phy_write(memac->pcsphy, MDIO_SGMII_LINK_TMR_H, LINK_TMR_H_BASEX);
phy_write(memac->pcsphy, MDIO_SGMII_LINK_TMR_L, LINK_TMR_L_BASEX);
tmp_reg16 = SGMII_CR_DEF_VAL | SGMII_CR_RESTART_AN;
phy_write(memac->pcsphy, 0x0, tmp_reg16);
}
static int check_init_parameters(struct fman_mac *memac)
{
if (memac->addr == 0) {
pr_err("Ethernet MAC must have a valid MAC address\n");
return -EINVAL;
}
if (!memac->exception_cb) {
pr_err("Uninitialized exception handler\n");
return -EINVAL;
}
if (!memac->event_cb) {
pr_warn("Uninitialize event handler\n");
return -EINVAL;
}
return 0;
}
static int get_exception_flag(enum fman_mac_exceptions exception)
{
u32 bit_mask;
switch (exception) {
case FM_MAC_EX_10G_TX_ECC_ER:
bit_mask = MEMAC_IMASK_TECC_ER;
break;
case FM_MAC_EX_10G_RX_ECC_ER:
bit_mask = MEMAC_IMASK_RECC_ER;
break;
case FM_MAC_EX_TS_FIFO_ECC_ERR:
bit_mask = MEMAC_IMASK_TSECC_ER;
break;
case FM_MAC_EX_MAGIC_PACKET_INDICATION:
bit_mask = MEMAC_IMASK_MGI;
break;
default:
bit_mask = 0;
break;
}
return bit_mask;
}
static void memac_err_exception(void *handle)
{
struct fman_mac *memac = (struct fman_mac *)handle;
struct memac_regs __iomem *regs = memac->regs;
u32 event, imask;
event = ioread32be(&regs->ievent);
imask = ioread32be(&regs->imask);
event &= ((imask & MEMAC_ALL_ERRS_IMASK) >> 16);
iowrite32be(event, &regs->ievent);
if (event & MEMAC_IEVNT_TS_ECC_ER)
memac->exception_cb(memac->dev_id, FM_MAC_EX_TS_FIFO_ECC_ERR);
if (event & MEMAC_IEVNT_TX_ECC_ER)
memac->exception_cb(memac->dev_id, FM_MAC_EX_10G_TX_ECC_ER);
if (event & MEMAC_IEVNT_RX_ECC_ER)
memac->exception_cb(memac->dev_id, FM_MAC_EX_10G_RX_ECC_ER);
}
static void memac_exception(void *handle)
{
struct fman_mac *memac = (struct fman_mac *)handle;
struct memac_regs __iomem *regs = memac->regs;
u32 event, imask;
event = ioread32be(&regs->ievent);
imask = ioread32be(&regs->imask);
event &= ((imask & MEMAC_ALL_ERRS_IMASK) >> 16);
iowrite32be(event, &regs->ievent);
if (event & MEMAC_IEVNT_MGI)
memac->exception_cb(memac->dev_id,
FM_MAC_EX_MAGIC_PACKET_INDICATION);
}
static void free_init_resources(struct fman_mac *memac)
{
fman_unregister_intr(memac->fm, FMAN_MOD_MAC, memac->mac_id,
FMAN_INTR_TYPE_ERR);
fman_unregister_intr(memac->fm, FMAN_MOD_MAC, memac->mac_id,
FMAN_INTR_TYPE_NORMAL);
free_hash_table(memac->multicast_addr_hash);
memac->multicast_addr_hash = NULL;
free_hash_table(memac->unicast_addr_hash);
memac->unicast_addr_hash = NULL;
}
static bool is_init_done(struct memac_cfg *memac_drv_params)
{
if (!memac_drv_params)
return true;
return false;
}
int memac_enable(struct fman_mac *memac, enum comm_mode mode)
{
struct memac_regs __iomem *regs = memac->regs;
u32 tmp;
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
tmp = ioread32be(&regs->command_config);
if (mode & COMM_MODE_RX)
tmp |= CMD_CFG_RX_EN;
if (mode & COMM_MODE_TX)
tmp |= CMD_CFG_TX_EN;
iowrite32be(tmp, &regs->command_config);
return 0;
}
int memac_disable(struct fman_mac *memac, enum comm_mode mode)
{
struct memac_regs __iomem *regs = memac->regs;
u32 tmp;
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
tmp = ioread32be(&regs->command_config);
if (mode & COMM_MODE_RX)
tmp &= ~CMD_CFG_RX_EN;
if (mode & COMM_MODE_TX)
tmp &= ~CMD_CFG_TX_EN;
iowrite32be(tmp, &regs->command_config);
return 0;
}
int memac_set_promiscuous(struct fman_mac *memac, bool new_val)
{
struct memac_regs __iomem *regs = memac->regs;
u32 tmp;
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
tmp = ioread32be(&regs->command_config);
if (new_val)
tmp |= CMD_CFG_PROMIS_EN;
else
tmp &= ~CMD_CFG_PROMIS_EN;
iowrite32be(tmp, &regs->command_config);
return 0;
}
int memac_adjust_link(struct fman_mac *memac, u16 speed)
{
struct memac_regs __iomem *regs = memac->regs;
u32 tmp;
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
tmp = ioread32be(&regs->if_mode);
tmp &= ~IF_MODE_HD;
if (memac->phy_if == PHY_INTERFACE_MODE_RGMII) {
tmp &= ~IF_MODE_RGMII_AUTO;
tmp &= ~IF_MODE_RGMII_SP_MASK;
tmp |= IF_MODE_RGMII_FD;
switch (speed) {
case SPEED_1000:
tmp |= IF_MODE_RGMII_1000;
break;
case SPEED_100:
tmp |= IF_MODE_RGMII_100;
break;
case SPEED_10:
tmp |= IF_MODE_RGMII_10;
break;
default:
break;
}
}
iowrite32be(tmp, &regs->if_mode);
return 0;
}
int memac_cfg_max_frame_len(struct fman_mac *memac, u16 new_val)
{
if (is_init_done(memac->memac_drv_param))
return -EINVAL;
memac->memac_drv_param->max_frame_length = new_val;
return 0;
}
int memac_cfg_reset_on_init(struct fman_mac *memac, bool enable)
{
if (is_init_done(memac->memac_drv_param))
return -EINVAL;
memac->memac_drv_param->reset_on_init = enable;
return 0;
}
int memac_cfg_fixed_link(struct fman_mac *memac,
struct fixed_phy_status *fixed_link)
{
if (is_init_done(memac->memac_drv_param))
return -EINVAL;
memac->memac_drv_param->fixed_link = fixed_link;
return 0;
}
int memac_set_tx_pause_frames(struct fman_mac *memac, u8 priority,
u16 pause_time, u16 thresh_time)
{
struct memac_regs __iomem *regs = memac->regs;
u32 tmp;
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
tmp = ioread32be(&regs->tx_fifo_sections);
GET_TX_EMPTY_DEFAULT_VALUE(tmp);
iowrite32be(tmp, &regs->tx_fifo_sections);
tmp = ioread32be(&regs->command_config);
tmp &= ~CMD_CFG_PFC_MODE;
priority = 0;
iowrite32be(tmp, &regs->command_config);
tmp = ioread32be(&regs->pause_quanta[priority / 2]);
if (priority % 2)
tmp &= CLXY_PAUSE_QUANTA_CLX_PQNT;
else
tmp &= CLXY_PAUSE_QUANTA_CLY_PQNT;
tmp |= ((u32)pause_time << (16 * (priority % 2)));
iowrite32be(tmp, &regs->pause_quanta[priority / 2]);
tmp = ioread32be(&regs->pause_thresh[priority / 2]);
if (priority % 2)
tmp &= CLXY_PAUSE_THRESH_CLX_QTH;
else
tmp &= CLXY_PAUSE_THRESH_CLY_QTH;
tmp |= ((u32)thresh_time << (16 * (priority % 2)));
iowrite32be(tmp, &regs->pause_thresh[priority / 2]);
return 0;
}
int memac_accept_rx_pause_frames(struct fman_mac *memac, bool en)
{
struct memac_regs __iomem *regs = memac->regs;
u32 tmp;
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
tmp = ioread32be(&regs->command_config);
if (en)
tmp &= ~CMD_CFG_PAUSE_IGNORE;
else
tmp |= CMD_CFG_PAUSE_IGNORE;
iowrite32be(tmp, &regs->command_config);
return 0;
}
int memac_modify_mac_address(struct fman_mac *memac, enet_addr_t *enet_addr)
{
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
add_addr_in_paddr(memac->regs, (u8 *)(*enet_addr), 0);
return 0;
}
int memac_add_hash_mac_address(struct fman_mac *memac, enet_addr_t *eth_addr)
{
struct memac_regs __iomem *regs = memac->regs;
struct eth_hash_entry *hash_entry;
u32 hash;
u64 addr;
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
addr = ENET_ADDR_TO_UINT64(*eth_addr);
if (!(addr & GROUP_ADDRESS)) {
pr_err("Unicast Address\n");
return -EINVAL;
}
hash = get_mac_addr_hash_code(addr) & HASH_CTRL_ADDR_MASK;
hash_entry = kmalloc(sizeof(*hash_entry), GFP_KERNEL);
if (!hash_entry)
return -ENOMEM;
hash_entry->addr = addr;
INIT_LIST_HEAD(&hash_entry->node);
list_add_tail(&hash_entry->node,
&memac->multicast_addr_hash->lsts[hash]);
iowrite32be(hash | HASH_CTRL_MCAST_EN, &regs->hashtable_ctrl);
return 0;
}
int memac_del_hash_mac_address(struct fman_mac *memac, enet_addr_t *eth_addr)
{
struct memac_regs __iomem *regs = memac->regs;
struct eth_hash_entry *hash_entry = NULL;
struct list_head *pos;
u32 hash;
u64 addr;
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
addr = ENET_ADDR_TO_UINT64(*eth_addr);
hash = get_mac_addr_hash_code(addr) & HASH_CTRL_ADDR_MASK;
list_for_each(pos, &memac->multicast_addr_hash->lsts[hash]) {
hash_entry = ETH_HASH_ENTRY_OBJ(pos);
if (hash_entry->addr == addr) {
list_del_init(&hash_entry->node);
kfree(hash_entry);
break;
}
}
if (list_empty(&memac->multicast_addr_hash->lsts[hash]))
iowrite32be(hash & ~HASH_CTRL_MCAST_EN, &regs->hashtable_ctrl);
return 0;
}
int memac_set_exception(struct fman_mac *memac,
enum fman_mac_exceptions exception, bool enable)
{
u32 bit_mask = 0;
if (!is_init_done(memac->memac_drv_param))
return -EINVAL;
bit_mask = get_exception_flag(exception);
if (bit_mask) {
if (enable)
memac->exceptions |= bit_mask;
else
memac->exceptions &= ~bit_mask;
} else {
pr_err("Undefined exception\n");
return -EINVAL;
}
set_exception(memac->regs, bit_mask, enable);
return 0;
}
int memac_init(struct fman_mac *memac)
{
struct memac_cfg *memac_drv_param;
u8 i;
enet_addr_t eth_addr;
bool slow_10g_if = false;
struct fixed_phy_status *fixed_link;
int err;
u32 reg32 = 0;
if (is_init_done(memac->memac_drv_param))
return -EINVAL;
err = check_init_parameters(memac);
if (err)
return err;
memac_drv_param = memac->memac_drv_param;
if (memac->fm_rev_info.major == 6 && memac->fm_rev_info.minor == 4)
slow_10g_if = true;
if (memac_drv_param->reset_on_init) {
err = reset(memac->regs);
if (err) {
pr_err("mEMAC reset failed\n");
return err;
}
}
MAKE_ENET_ADDR_FROM_UINT64(memac->addr, eth_addr);
add_addr_in_paddr(memac->regs, (u8 *)eth_addr, 0);
fixed_link = memac_drv_param->fixed_link;
init(memac->regs, memac->memac_drv_param, memac->phy_if,
memac->max_speed, slow_10g_if, memac->exceptions);
if ((memac->fm_rev_info.major == 6) &&
((memac->fm_rev_info.minor == 0) ||
(memac->fm_rev_info.minor == 3))) {
reg32 = ioread32be(&memac->regs->command_config);
reg32 &= ~CMD_CFG_CRC_FWD;
iowrite32be(reg32, &memac->regs->command_config);
}
if (memac->phy_if == PHY_INTERFACE_MODE_SGMII) {
if (memac->basex_if)
setup_sgmii_internal_phy_base_x(memac);
else
setup_sgmii_internal_phy(memac, fixed_link);
} else if (memac->phy_if == PHY_INTERFACE_MODE_QSGMII) {
for (i = 0; i < 4; i++) {
u8 qsmgii_phy_addr, phy_addr;
phy_addr = memac->pcsphy->mdio.addr;
qsmgii_phy_addr = (u8)((phy_addr << 2) | i);
memac->pcsphy->mdio.addr = qsmgii_phy_addr;
if (memac->basex_if)
setup_sgmii_internal_phy_base_x(memac);
else
setup_sgmii_internal_phy(memac, fixed_link);
memac->pcsphy->mdio.addr = phy_addr;
}
}
err = fman_set_mac_max_frame(memac->fm, memac->mac_id,
memac_drv_param->max_frame_length);
if (err) {
pr_err("settings Mac max frame length is FAILED\n");
return err;
}
memac->multicast_addr_hash = alloc_hash_table(HASH_TABLE_SIZE);
if (!memac->multicast_addr_hash) {
free_init_resources(memac);
pr_err("allocation hash table is FAILED\n");
return -ENOMEM;
}
memac->unicast_addr_hash = alloc_hash_table(HASH_TABLE_SIZE);
if (!memac->unicast_addr_hash) {
free_init_resources(memac);
pr_err("allocation hash table is FAILED\n");
return -ENOMEM;
}
fman_register_intr(memac->fm, FMAN_MOD_MAC, memac->mac_id,
FMAN_INTR_TYPE_ERR, memac_err_exception, memac);
fman_register_intr(memac->fm, FMAN_MOD_MAC, memac->mac_id,
FMAN_INTR_TYPE_NORMAL, memac_exception, memac);
kfree(memac_drv_param);
memac->memac_drv_param = NULL;
return 0;
}
int memac_free(struct fman_mac *memac)
{
free_init_resources(memac);
if (memac->pcsphy)
put_device(&memac->pcsphy->mdio.dev);
kfree(memac->memac_drv_param);
kfree(memac);
return 0;
}
struct fman_mac *memac_config(struct fman_mac_params *params)
{
struct fman_mac *memac;
struct memac_cfg *memac_drv_param;
void __iomem *base_addr;
base_addr = params->base_addr;
memac = kzalloc(sizeof(*memac), GFP_KERNEL);
if (!memac)
return NULL;
memac_drv_param = kzalloc(sizeof(*memac_drv_param), GFP_KERNEL);
if (!memac_drv_param) {
memac_free(memac);
return NULL;
}
memac->memac_drv_param = memac_drv_param;
set_dflts(memac_drv_param);
memac->addr = ENET_ADDR_TO_UINT64(params->addr);
memac->regs = base_addr;
memac->max_speed = params->max_speed;
memac->phy_if = params->phy_if;
memac->mac_id = params->mac_id;
memac->exceptions = (MEMAC_IMASK_TSECC_ER | MEMAC_IMASK_TECC_ER |
MEMAC_IMASK_RECC_ER | MEMAC_IMASK_MGI);
memac->exception_cb = params->exception_cb;
memac->event_cb = params->event_cb;
memac->dev_id = params->dev_id;
memac->fm = params->fm;
memac->basex_if = params->basex_if;
fman_get_revision(memac->fm, &memac->fm_rev_info);
if (memac->phy_if == PHY_INTERFACE_MODE_SGMII ||
memac->phy_if == PHY_INTERFACE_MODE_QSGMII) {
if (!params->internal_phy_node) {
pr_err("PCS PHY node is not available\n");
memac_free(memac);
return NULL;
}
memac->pcsphy = of_phy_find_device(params->internal_phy_node);
if (!memac->pcsphy) {
pr_err("of_phy_find_device (PCS PHY) failed\n");
memac_free(memac);
return NULL;
}
}
return memac;
}
