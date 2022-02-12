static void set_mac_address(struct tgec_regs __iomem *regs, u8 *adr)
{
u32 tmp0, tmp1;
tmp0 = (u32)(adr[0] | adr[1] << 8 | adr[2] << 16 | adr[3] << 24);
tmp1 = (u32)(adr[4] | adr[5] << 8);
iowrite32be(tmp0, &regs->mac_addr_0);
iowrite32be(tmp1, &regs->mac_addr_1);
}
static void set_dflts(struct tgec_cfg *cfg)
{
cfg->promiscuous_mode_enable = false;
cfg->pause_ignore = false;
cfg->tx_ipg_length = DEFAULT_TX_IPG_LENGTH;
cfg->max_frame_length = DEFAULT_MAX_FRAME_LENGTH;
cfg->pause_quant = DEFAULT_PAUSE_QUANT;
}
static int init(struct tgec_regs __iomem *regs, struct tgec_cfg *cfg,
u32 exception_mask)
{
u32 tmp;
tmp = CMF_CFG_CRC_FWD;
if (cfg->promiscuous_mode_enable)
tmp |= CMD_CFG_PROMIS_EN;
if (cfg->pause_ignore)
tmp |= CMD_CFG_PAUSE_IGNORE;
tmp |= CMD_CFG_NO_LEN_CHK;
iowrite32be(tmp, &regs->command_config);
iowrite32be((u32)cfg->max_frame_length, &regs->maxfrm);
iowrite32be(cfg->pause_quant, &regs->pause_quant);
iowrite32be(0xffffffff, &regs->ievent);
iowrite32be(ioread32be(&regs->imask) | exception_mask, &regs->imask);
return 0;
}
static int check_init_parameters(struct fman_mac *tgec)
{
if (tgec->max_speed < SPEED_10000) {
pr_err("10G MAC driver only support 10G speed\n");
return -EINVAL;
}
if (tgec->addr == 0) {
pr_err("Ethernet 10G MAC Must have valid MAC Address\n");
return -EINVAL;
}
if (!tgec->exception_cb) {
pr_err("uninitialized exception_cb\n");
return -EINVAL;
}
if (!tgec->event_cb) {
pr_err("uninitialized event_cb\n");
return -EINVAL;
}
return 0;
}
static int get_exception_flag(enum fman_mac_exceptions exception)
{
u32 bit_mask;
switch (exception) {
case FM_MAC_EX_10G_MDIO_SCAN_EVENT:
bit_mask = TGEC_IMASK_MDIO_SCAN_EVENT;
break;
case FM_MAC_EX_10G_MDIO_CMD_CMPL:
bit_mask = TGEC_IMASK_MDIO_CMD_CMPL;
break;
case FM_MAC_EX_10G_REM_FAULT:
bit_mask = TGEC_IMASK_REM_FAULT;
break;
case FM_MAC_EX_10G_LOC_FAULT:
bit_mask = TGEC_IMASK_LOC_FAULT;
break;
case FM_MAC_EX_10G_TX_ECC_ER:
bit_mask = TGEC_IMASK_TX_ECC_ER;
break;
case FM_MAC_EX_10G_TX_FIFO_UNFL:
bit_mask = TGEC_IMASK_TX_FIFO_UNFL;
break;
case FM_MAC_EX_10G_TX_FIFO_OVFL:
bit_mask = TGEC_IMASK_TX_FIFO_OVFL;
break;
case FM_MAC_EX_10G_TX_ER:
bit_mask = TGEC_IMASK_TX_ER;
break;
case FM_MAC_EX_10G_RX_FIFO_OVFL:
bit_mask = TGEC_IMASK_RX_FIFO_OVFL;
break;
case FM_MAC_EX_10G_RX_ECC_ER:
bit_mask = TGEC_IMASK_RX_ECC_ER;
break;
case FM_MAC_EX_10G_RX_JAB_FRM:
bit_mask = TGEC_IMASK_RX_JAB_FRM;
break;
case FM_MAC_EX_10G_RX_OVRSZ_FRM:
bit_mask = TGEC_IMASK_RX_OVRSZ_FRM;
break;
case FM_MAC_EX_10G_RX_RUNT_FRM:
bit_mask = TGEC_IMASK_RX_RUNT_FRM;
break;
case FM_MAC_EX_10G_RX_FRAG_FRM:
bit_mask = TGEC_IMASK_RX_FRAG_FRM;
break;
case FM_MAC_EX_10G_RX_LEN_ER:
bit_mask = TGEC_IMASK_RX_LEN_ER;
break;
case FM_MAC_EX_10G_RX_CRC_ER:
bit_mask = TGEC_IMASK_RX_CRC_ER;
break;
case FM_MAC_EX_10G_RX_ALIGN_ER:
bit_mask = TGEC_IMASK_RX_ALIGN_ER;
break;
default:
bit_mask = 0;
break;
}
return bit_mask;
}
static void tgec_err_exception(void *handle)
{
struct fman_mac *tgec = (struct fman_mac *)handle;
struct tgec_regs __iomem *regs = tgec->regs;
u32 event;
event = ioread32be(&regs->ievent) &
~(TGEC_IMASK_MDIO_SCAN_EVENT |
TGEC_IMASK_MDIO_CMD_CMPL);
event &= ioread32be(&regs->imask);
iowrite32be(event, &regs->ievent);
if (event & TGEC_IMASK_REM_FAULT)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_REM_FAULT);
if (event & TGEC_IMASK_LOC_FAULT)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_LOC_FAULT);
if (event & TGEC_IMASK_TX_ECC_ER)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_TX_ECC_ER);
if (event & TGEC_IMASK_TX_FIFO_UNFL)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_TX_FIFO_UNFL);
if (event & TGEC_IMASK_TX_FIFO_OVFL)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_TX_FIFO_OVFL);
if (event & TGEC_IMASK_TX_ER)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_TX_ER);
if (event & TGEC_IMASK_RX_FIFO_OVFL)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_RX_FIFO_OVFL);
if (event & TGEC_IMASK_RX_ECC_ER)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_RX_ECC_ER);
if (event & TGEC_IMASK_RX_JAB_FRM)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_RX_JAB_FRM);
if (event & TGEC_IMASK_RX_OVRSZ_FRM)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_RX_OVRSZ_FRM);
if (event & TGEC_IMASK_RX_RUNT_FRM)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_RX_RUNT_FRM);
if (event & TGEC_IMASK_RX_FRAG_FRM)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_RX_FRAG_FRM);
if (event & TGEC_IMASK_RX_LEN_ER)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_RX_LEN_ER);
if (event & TGEC_IMASK_RX_CRC_ER)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_RX_CRC_ER);
if (event & TGEC_IMASK_RX_ALIGN_ER)
tgec->exception_cb(tgec->dev_id, FM_MAC_EX_10G_RX_ALIGN_ER);
}
static void free_init_resources(struct fman_mac *tgec)
{
fman_unregister_intr(tgec->fm, FMAN_MOD_MAC, tgec->mac_id,
FMAN_INTR_TYPE_ERR);
free_hash_table(tgec->multicast_addr_hash);
tgec->multicast_addr_hash = NULL;
free_hash_table(tgec->unicast_addr_hash);
tgec->unicast_addr_hash = NULL;
}
static bool is_init_done(struct tgec_cfg *cfg)
{
if (!cfg)
return true;
return false;
}
int tgec_enable(struct fman_mac *tgec, enum comm_mode mode)
{
struct tgec_regs __iomem *regs = tgec->regs;
u32 tmp;
if (!is_init_done(tgec->cfg))
return -EINVAL;
tmp = ioread32be(&regs->command_config);
if (mode & COMM_MODE_RX)
tmp |= CMD_CFG_RX_EN;
if (mode & COMM_MODE_TX)
tmp |= CMD_CFG_TX_EN;
iowrite32be(tmp, &regs->command_config);
return 0;
}
int tgec_disable(struct fman_mac *tgec, enum comm_mode mode)
{
struct tgec_regs __iomem *regs = tgec->regs;
u32 tmp;
if (!is_init_done(tgec->cfg))
return -EINVAL;
tmp = ioread32be(&regs->command_config);
if (mode & COMM_MODE_RX)
tmp &= ~CMD_CFG_RX_EN;
if (mode & COMM_MODE_TX)
tmp &= ~CMD_CFG_TX_EN;
iowrite32be(tmp, &regs->command_config);
return 0;
}
int tgec_set_promiscuous(struct fman_mac *tgec, bool new_val)
{
struct tgec_regs __iomem *regs = tgec->regs;
u32 tmp;
if (!is_init_done(tgec->cfg))
return -EINVAL;
tmp = ioread32be(&regs->command_config);
if (new_val)
tmp |= CMD_CFG_PROMIS_EN;
else
tmp &= ~CMD_CFG_PROMIS_EN;
iowrite32be(tmp, &regs->command_config);
return 0;
}
int tgec_cfg_max_frame_len(struct fman_mac *tgec, u16 new_val)
{
if (is_init_done(tgec->cfg))
return -EINVAL;
tgec->cfg->max_frame_length = new_val;
return 0;
}
int tgec_set_tx_pause_frames(struct fman_mac *tgec, u8 __maybe_unused priority,
u16 pause_time, u16 __maybe_unused thresh_time)
{
struct tgec_regs __iomem *regs = tgec->regs;
if (!is_init_done(tgec->cfg))
return -EINVAL;
iowrite32be((u32)pause_time, &regs->pause_quant);
return 0;
}
int tgec_accept_rx_pause_frames(struct fman_mac *tgec, bool en)
{
struct tgec_regs __iomem *regs = tgec->regs;
u32 tmp;
if (!is_init_done(tgec->cfg))
return -EINVAL;
tmp = ioread32be(&regs->command_config);
if (!en)
tmp |= CMD_CFG_PAUSE_IGNORE;
else
tmp &= ~CMD_CFG_PAUSE_IGNORE;
iowrite32be(tmp, &regs->command_config);
return 0;
}
int tgec_modify_mac_address(struct fman_mac *tgec, enet_addr_t *p_enet_addr)
{
if (!is_init_done(tgec->cfg))
return -EINVAL;
tgec->addr = ENET_ADDR_TO_UINT64(*p_enet_addr);
set_mac_address(tgec->regs, (u8 *)(*p_enet_addr));
return 0;
}
int tgec_add_hash_mac_address(struct fman_mac *tgec, enet_addr_t *eth_addr)
{
struct tgec_regs __iomem *regs = tgec->regs;
struct eth_hash_entry *hash_entry;
u32 crc = 0xFFFFFFFF, hash;
u64 addr;
if (!is_init_done(tgec->cfg))
return -EINVAL;
addr = ENET_ADDR_TO_UINT64(*eth_addr);
if (!(addr & GROUP_ADDRESS)) {
pr_err("Unicast Address\n");
return -EINVAL;
}
crc = crc32_le(crc, (u8 *)eth_addr, ETH_ALEN);
crc = bitrev32(crc);
hash = (crc >> TGEC_HASH_MCAST_SHIFT) & TGEC_HASH_ADR_MSK;
hash_entry = kmalloc(sizeof(*hash_entry), GFP_KERNEL);
if (!hash_entry)
return -ENOMEM;
hash_entry->addr = addr;
INIT_LIST_HEAD(&hash_entry->node);
list_add_tail(&hash_entry->node,
&tgec->multicast_addr_hash->lsts[hash]);
iowrite32be((hash | TGEC_HASH_MCAST_EN), &regs->hashtable_ctrl);
return 0;
}
int tgec_del_hash_mac_address(struct fman_mac *tgec, enet_addr_t *eth_addr)
{
struct tgec_regs __iomem *regs = tgec->regs;
struct eth_hash_entry *hash_entry = NULL;
struct list_head *pos;
u32 crc = 0xFFFFFFFF, hash;
u64 addr;
if (!is_init_done(tgec->cfg))
return -EINVAL;
addr = ((*(u64 *)eth_addr) >> 16);
crc = crc32_le(crc, (u8 *)eth_addr, ETH_ALEN);
crc = bitrev32(crc);
hash = (crc >> TGEC_HASH_MCAST_SHIFT) & TGEC_HASH_ADR_MSK;
list_for_each(pos, &tgec->multicast_addr_hash->lsts[hash]) {
hash_entry = ETH_HASH_ENTRY_OBJ(pos);
if (hash_entry->addr == addr) {
list_del_init(&hash_entry->node);
kfree(hash_entry);
break;
}
}
if (list_empty(&tgec->multicast_addr_hash->lsts[hash]))
iowrite32be((hash & ~TGEC_HASH_MCAST_EN),
&regs->hashtable_ctrl);
return 0;
}
int tgec_get_version(struct fman_mac *tgec, u32 *mac_version)
{
struct tgec_regs __iomem *regs = tgec->regs;
if (!is_init_done(tgec->cfg))
return -EINVAL;
*mac_version = ioread32be(&regs->tgec_id);
return 0;
}
int tgec_set_exception(struct fman_mac *tgec,
enum fman_mac_exceptions exception, bool enable)
{
struct tgec_regs __iomem *regs = tgec->regs;
u32 bit_mask = 0;
if (!is_init_done(tgec->cfg))
return -EINVAL;
bit_mask = get_exception_flag(exception);
if (bit_mask) {
if (enable)
tgec->exceptions |= bit_mask;
else
tgec->exceptions &= ~bit_mask;
} else {
pr_err("Undefined exception\n");
return -EINVAL;
}
if (enable)
iowrite32be(ioread32be(&regs->imask) | bit_mask, &regs->imask);
else
iowrite32be(ioread32be(&regs->imask) & ~bit_mask, &regs->imask);
return 0;
}
int tgec_init(struct fman_mac *tgec)
{
struct tgec_cfg *cfg;
enet_addr_t eth_addr;
int err;
if (is_init_done(tgec->cfg))
return -EINVAL;
if (DEFAULT_RESET_ON_INIT &&
(fman_reset_mac(tgec->fm, tgec->mac_id) != 0)) {
pr_err("Can't reset MAC!\n");
return -EINVAL;
}
err = check_init_parameters(tgec);
if (err)
return err;
cfg = tgec->cfg;
MAKE_ENET_ADDR_FROM_UINT64(tgec->addr, eth_addr);
set_mac_address(tgec->regs, (u8 *)eth_addr);
if (tgec->fm_rev_info.major <= 2)
tgec->exceptions &= ~(TGEC_IMASK_REM_FAULT |
TGEC_IMASK_LOC_FAULT);
err = init(tgec->regs, cfg, tgec->exceptions);
if (err) {
free_init_resources(tgec);
pr_err("TGEC version doesn't support this i/f mode\n");
return err;
}
err = fman_set_mac_max_frame(tgec->fm, tgec->mac_id,
cfg->max_frame_length);
if (err) {
pr_err("Setting max frame length FAILED\n");
free_init_resources(tgec);
return -EINVAL;
}
if (tgec->fm_rev_info.major == 2) {
struct tgec_regs __iomem *regs = tgec->regs;
u32 tmp;
tmp = (ioread32be(&regs->tx_ipg_len) &
~TGEC_TX_IPG_LENGTH_MASK) | 12;
iowrite32be(tmp, &regs->tx_ipg_len);
}
tgec->multicast_addr_hash = alloc_hash_table(TGEC_HASH_TABLE_SIZE);
if (!tgec->multicast_addr_hash) {
free_init_resources(tgec);
pr_err("allocation hash table is FAILED\n");
return -ENOMEM;
}
tgec->unicast_addr_hash = alloc_hash_table(TGEC_HASH_TABLE_SIZE);
if (!tgec->unicast_addr_hash) {
free_init_resources(tgec);
pr_err("allocation hash table is FAILED\n");
return -ENOMEM;
}
fman_register_intr(tgec->fm, FMAN_MOD_MAC, tgec->mac_id,
FMAN_INTR_TYPE_ERR, tgec_err_exception, tgec);
kfree(cfg);
tgec->cfg = NULL;
return 0;
}
int tgec_free(struct fman_mac *tgec)
{
free_init_resources(tgec);
if (tgec->cfg)
tgec->cfg = NULL;
kfree(tgec->cfg);
kfree(tgec);
return 0;
}
struct fman_mac *tgec_config(struct fman_mac_params *params)
{
struct fman_mac *tgec;
struct tgec_cfg *cfg;
void __iomem *base_addr;
base_addr = params->base_addr;
tgec = kzalloc(sizeof(*tgec), GFP_KERNEL);
if (!tgec)
return NULL;
cfg = kzalloc(sizeof(*cfg), GFP_KERNEL);
if (!cfg) {
tgec_free(tgec);
return NULL;
}
tgec->cfg = cfg;
set_dflts(cfg);
tgec->regs = base_addr;
tgec->addr = ENET_ADDR_TO_UINT64(params->addr);
tgec->max_speed = params->max_speed;
tgec->mac_id = params->mac_id;
tgec->exceptions = (TGEC_IMASK_MDIO_SCAN_EVENT |
TGEC_IMASK_REM_FAULT |
TGEC_IMASK_LOC_FAULT |
TGEC_IMASK_TX_ECC_ER |
TGEC_IMASK_TX_FIFO_UNFL |
TGEC_IMASK_TX_FIFO_OVFL |
TGEC_IMASK_TX_ER |
TGEC_IMASK_RX_FIFO_OVFL |
TGEC_IMASK_RX_ECC_ER |
TGEC_IMASK_RX_JAB_FRM |
TGEC_IMASK_RX_OVRSZ_FRM |
TGEC_IMASK_RX_RUNT_FRM |
TGEC_IMASK_RX_FRAG_FRM |
TGEC_IMASK_RX_CRC_ER |
TGEC_IMASK_RX_ALIGN_ER);
tgec->exception_cb = params->exception_cb;
tgec->event_cb = params->event_cb;
tgec->dev_id = params->dev_id;
tgec->fm = params->fm;
fman_get_revision(tgec->fm, &tgec->fm_rev_info);
return tgec;
}
