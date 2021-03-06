static inline void cas_lock_tx(struct cas *cp)
{
int i;
for (i = 0; i < N_TX_RINGS; i++)
spin_lock(&cp->tx_lock[i]);
}
static inline void cas_lock_all(struct cas *cp)
{
spin_lock_irq(&cp->lock);
cas_lock_tx(cp);
}
static inline void cas_unlock_tx(struct cas *cp)
{
int i;
for (i = N_TX_RINGS; i > 0; i--)
spin_unlock(&cp->tx_lock[i - 1]);
}
static inline void cas_unlock_all(struct cas *cp)
{
cas_unlock_tx(cp);
spin_unlock_irq(&cp->lock);
}
static void cas_disable_irq(struct cas *cp, const int ring)
{
if (ring == 0) {
writel(0xFFFFFFFF, cp->regs + REG_INTR_MASK);
return;
}
if (cp->cas_flags & CAS_FLAG_REG_PLUS) {
switch (ring) {
#if defined (USE_PCI_INTB) || defined(USE_PCI_INTC) || defined(USE_PCI_INTD)
#ifdef USE_PCI_INTB
case 1:
#endif
#ifdef USE_PCI_INTC
case 2:
#endif
#ifdef USE_PCI_INTD
case 3:
#endif
writel(INTRN_MASK_CLEAR_ALL | INTRN_MASK_RX_EN,
cp->regs + REG_PLUS_INTRN_MASK(ring));
break;
#endif
default:
writel(INTRN_MASK_CLEAR_ALL, cp->regs +
REG_PLUS_INTRN_MASK(ring));
break;
}
}
}
static inline void cas_mask_intr(struct cas *cp)
{
int i;
for (i = 0; i < N_RX_COMP_RINGS; i++)
cas_disable_irq(cp, i);
}
static void cas_enable_irq(struct cas *cp, const int ring)
{
if (ring == 0) {
writel(INTR_TX_DONE, cp->regs + REG_INTR_MASK);
return;
}
if (cp->cas_flags & CAS_FLAG_REG_PLUS) {
switch (ring) {
#if defined (USE_PCI_INTB) || defined(USE_PCI_INTC) || defined(USE_PCI_INTD)
#ifdef USE_PCI_INTB
case 1:
#endif
#ifdef USE_PCI_INTC
case 2:
#endif
#ifdef USE_PCI_INTD
case 3:
#endif
writel(INTRN_MASK_RX_EN, cp->regs +
REG_PLUS_INTRN_MASK(ring));
break;
#endif
default:
break;
}
}
}
static inline void cas_unmask_intr(struct cas *cp)
{
int i;
for (i = 0; i < N_RX_COMP_RINGS; i++)
cas_enable_irq(cp, i);
}
static inline void cas_entropy_gather(struct cas *cp)
{
#ifdef USE_ENTROPY_DEV
if ((cp->cas_flags & CAS_FLAG_ENTROPY_DEV) == 0)
return;
batch_entropy_store(readl(cp->regs + REG_ENTROPY_IV),
readl(cp->regs + REG_ENTROPY_IV),
sizeof(uint64_t)*8);
#endif
}
static inline void cas_entropy_reset(struct cas *cp)
{
#ifdef USE_ENTROPY_DEV
if ((cp->cas_flags & CAS_FLAG_ENTROPY_DEV) == 0)
return;
writel(BIM_LOCAL_DEV_PAD | BIM_LOCAL_DEV_PROM | BIM_LOCAL_DEV_EXT,
cp->regs + REG_BIM_LOCAL_DEV_EN);
writeb(ENTROPY_RESET_STC_MODE, cp->regs + REG_ENTROPY_RESET);
writeb(0x55, cp->regs + REG_ENTROPY_RAND_REG);
if (readb(cp->regs + REG_ENTROPY_RAND_REG) == 0)
cp->cas_flags &= ~CAS_FLAG_ENTROPY_DEV;
#endif
}
static u16 cas_phy_read(struct cas *cp, int reg)
{
u32 cmd;
int limit = STOP_TRIES_PHY;
cmd = MIF_FRAME_ST | MIF_FRAME_OP_READ;
cmd |= CAS_BASE(MIF_FRAME_PHY_ADDR, cp->phy_addr);
cmd |= CAS_BASE(MIF_FRAME_REG_ADDR, reg);
cmd |= MIF_FRAME_TURN_AROUND_MSB;
writel(cmd, cp->regs + REG_MIF_FRAME);
while (limit-- > 0) {
udelay(10);
cmd = readl(cp->regs + REG_MIF_FRAME);
if (cmd & MIF_FRAME_TURN_AROUND_LSB)
return cmd & MIF_FRAME_DATA_MASK;
}
return 0xFFFF;
}
static int cas_phy_write(struct cas *cp, int reg, u16 val)
{
int limit = STOP_TRIES_PHY;
u32 cmd;
cmd = MIF_FRAME_ST | MIF_FRAME_OP_WRITE;
cmd |= CAS_BASE(MIF_FRAME_PHY_ADDR, cp->phy_addr);
cmd |= CAS_BASE(MIF_FRAME_REG_ADDR, reg);
cmd |= MIF_FRAME_TURN_AROUND_MSB;
cmd |= val & MIF_FRAME_DATA_MASK;
writel(cmd, cp->regs + REG_MIF_FRAME);
while (limit-- > 0) {
udelay(10);
cmd = readl(cp->regs + REG_MIF_FRAME);
if (cmd & MIF_FRAME_TURN_AROUND_LSB)
return 0;
}
return -1;
}
static void cas_phy_powerup(struct cas *cp)
{
u16 ctl = cas_phy_read(cp, MII_BMCR);
if ((ctl & BMCR_PDOWN) == 0)
return;
ctl &= ~BMCR_PDOWN;
cas_phy_write(cp, MII_BMCR, ctl);
}
static void cas_phy_powerdown(struct cas *cp)
{
u16 ctl = cas_phy_read(cp, MII_BMCR);
if (ctl & BMCR_PDOWN)
return;
ctl |= BMCR_PDOWN;
cas_phy_write(cp, MII_BMCR, ctl);
}
static int cas_page_free(struct cas *cp, cas_page_t *page)
{
pci_unmap_page(cp->pdev, page->dma_addr, cp->page_size,
PCI_DMA_FROMDEVICE);
__free_pages(page->buffer, cp->page_order);
kfree(page);
return 0;
}
static cas_page_t *cas_page_alloc(struct cas *cp, const gfp_t flags)
{
cas_page_t *page;
page = kmalloc(sizeof(cas_page_t), flags);
if (!page)
return NULL;
INIT_LIST_HEAD(&page->list);
RX_USED_SET(page, 0);
page->buffer = alloc_pages(flags, cp->page_order);
if (!page->buffer)
goto page_err;
page->dma_addr = pci_map_page(cp->pdev, page->buffer, 0,
cp->page_size, PCI_DMA_FROMDEVICE);
return page;
page_err:
kfree(page);
return NULL;
}
static void cas_spare_init(struct cas *cp)
{
spin_lock(&cp->rx_inuse_lock);
INIT_LIST_HEAD(&cp->rx_inuse_list);
spin_unlock(&cp->rx_inuse_lock);
spin_lock(&cp->rx_spare_lock);
INIT_LIST_HEAD(&cp->rx_spare_list);
cp->rx_spares_needed = RX_SPARE_COUNT;
spin_unlock(&cp->rx_spare_lock);
}
static void cas_spare_free(struct cas *cp)
{
struct list_head list, *elem, *tmp;
INIT_LIST_HEAD(&list);
spin_lock(&cp->rx_spare_lock);
list_splice_init(&cp->rx_spare_list, &list);
spin_unlock(&cp->rx_spare_lock);
list_for_each_safe(elem, tmp, &list) {
cas_page_free(cp, list_entry(elem, cas_page_t, list));
}
INIT_LIST_HEAD(&list);
#if 1
spin_lock(&cp->rx_inuse_lock);
list_splice_init(&cp->rx_inuse_list, &list);
spin_unlock(&cp->rx_inuse_lock);
#else
spin_lock(&cp->rx_spare_lock);
list_splice_init(&cp->rx_inuse_list, &list);
spin_unlock(&cp->rx_spare_lock);
#endif
list_for_each_safe(elem, tmp, &list) {
cas_page_free(cp, list_entry(elem, cas_page_t, list));
}
}
static void cas_spare_recover(struct cas *cp, const gfp_t flags)
{
struct list_head list, *elem, *tmp;
int needed, i;
INIT_LIST_HEAD(&list);
spin_lock(&cp->rx_inuse_lock);
list_splice_init(&cp->rx_inuse_list, &list);
spin_unlock(&cp->rx_inuse_lock);
list_for_each_safe(elem, tmp, &list) {
cas_page_t *page = list_entry(elem, cas_page_t, list);
if (page_count(page->buffer) > 1)
continue;
list_del(elem);
spin_lock(&cp->rx_spare_lock);
if (cp->rx_spares_needed > 0) {
list_add(elem, &cp->rx_spare_list);
cp->rx_spares_needed--;
spin_unlock(&cp->rx_spare_lock);
} else {
spin_unlock(&cp->rx_spare_lock);
cas_page_free(cp, page);
}
}
if (!list_empty(&list)) {
spin_lock(&cp->rx_inuse_lock);
list_splice(&list, &cp->rx_inuse_list);
spin_unlock(&cp->rx_inuse_lock);
}
spin_lock(&cp->rx_spare_lock);
needed = cp->rx_spares_needed;
spin_unlock(&cp->rx_spare_lock);
if (!needed)
return;
INIT_LIST_HEAD(&list);
i = 0;
while (i < needed) {
cas_page_t *spare = cas_page_alloc(cp, flags);
if (!spare)
break;
list_add(&spare->list, &list);
i++;
}
spin_lock(&cp->rx_spare_lock);
list_splice(&list, &cp->rx_spare_list);
cp->rx_spares_needed -= i;
spin_unlock(&cp->rx_spare_lock);
}
static cas_page_t *cas_page_dequeue(struct cas *cp)
{
struct list_head *entry;
int recover;
spin_lock(&cp->rx_spare_lock);
if (list_empty(&cp->rx_spare_list)) {
spin_unlock(&cp->rx_spare_lock);
cas_spare_recover(cp, GFP_ATOMIC);
spin_lock(&cp->rx_spare_lock);
if (list_empty(&cp->rx_spare_list)) {
netif_err(cp, rx_err, cp->dev,
"no spare buffers available\n");
spin_unlock(&cp->rx_spare_lock);
return NULL;
}
}
entry = cp->rx_spare_list.next;
list_del(entry);
recover = ++cp->rx_spares_needed;
spin_unlock(&cp->rx_spare_lock);
if ((recover & (RX_SPARE_RECOVER_VAL - 1)) == 0) {
#if 1
atomic_inc(&cp->reset_task_pending);
atomic_inc(&cp->reset_task_pending_spare);
schedule_work(&cp->reset_task);
#else
atomic_set(&cp->reset_task_pending, CAS_RESET_SPARE);
schedule_work(&cp->reset_task);
#endif
}
return list_entry(entry, cas_page_t, list);
}
static void cas_mif_poll(struct cas *cp, const int enable)
{
u32 cfg;
cfg = readl(cp->regs + REG_MIF_CFG);
cfg &= (MIF_CFG_MDIO_0 | MIF_CFG_MDIO_1);
if (cp->phy_type & CAS_PHY_MII_MDIO1)
cfg |= MIF_CFG_PHY_SELECT;
if (enable) {
cfg |= MIF_CFG_POLL_EN;
cfg |= CAS_BASE(MIF_CFG_POLL_REG, MII_BMSR);
cfg |= CAS_BASE(MIF_CFG_POLL_PHY, cp->phy_addr);
}
writel((enable) ? ~(BMSR_LSTATUS | BMSR_ANEGCOMPLETE) : 0xFFFF,
cp->regs + REG_MIF_MASK);
writel(cfg, cp->regs + REG_MIF_CFG);
}
static void cas_begin_auto_negotiation(struct cas *cp, struct ethtool_cmd *ep)
{
u16 ctl;
#if 1
int lcntl;
int changed = 0;
int oldstate = cp->lstate;
int link_was_not_down = !(oldstate == link_down);
#endif
if (!ep)
goto start_aneg;
lcntl = cp->link_cntl;
if (ep->autoneg == AUTONEG_ENABLE)
cp->link_cntl = BMCR_ANENABLE;
else {
u32 speed = ethtool_cmd_speed(ep);
cp->link_cntl = 0;
if (speed == SPEED_100)
cp->link_cntl |= BMCR_SPEED100;
else if (speed == SPEED_1000)
cp->link_cntl |= CAS_BMCR_SPEED1000;
if (ep->duplex == DUPLEX_FULL)
cp->link_cntl |= BMCR_FULLDPLX;
}
#if 1
changed = (lcntl != cp->link_cntl);
#endif
start_aneg:
if (cp->lstate == link_up) {
netdev_info(cp->dev, "PCS link down\n");
} else {
if (changed) {
netdev_info(cp->dev, "link configuration changed\n");
}
}
cp->lstate = link_down;
cp->link_transition = LINK_TRANSITION_LINK_DOWN;
if (!cp->hw_running)
return;
#if 1
if (oldstate == link_up)
netif_carrier_off(cp->dev);
if (changed && link_was_not_down) {
atomic_inc(&cp->reset_task_pending);
atomic_inc(&cp->reset_task_pending_all);
schedule_work(&cp->reset_task);
cp->timer_ticks = 0;
mod_timer(&cp->link_timer, jiffies + CAS_LINK_TIMEOUT);
return;
}
#endif
if (cp->phy_type & CAS_PHY_SERDES) {
u32 val = readl(cp->regs + REG_PCS_MII_CTRL);
if (cp->link_cntl & BMCR_ANENABLE) {
val |= (PCS_MII_RESTART_AUTONEG | PCS_MII_AUTONEG_EN);
cp->lstate = link_aneg;
} else {
if (cp->link_cntl & BMCR_FULLDPLX)
val |= PCS_MII_CTRL_DUPLEX;
val &= ~PCS_MII_AUTONEG_EN;
cp->lstate = link_force_ok;
}
cp->link_transition = LINK_TRANSITION_LINK_CONFIG;
writel(val, cp->regs + REG_PCS_MII_CTRL);
} else {
cas_mif_poll(cp, 0);
ctl = cas_phy_read(cp, MII_BMCR);
ctl &= ~(BMCR_FULLDPLX | BMCR_SPEED100 |
CAS_BMCR_SPEED1000 | BMCR_ANENABLE);
ctl |= cp->link_cntl;
if (ctl & BMCR_ANENABLE) {
ctl |= BMCR_ANRESTART;
cp->lstate = link_aneg;
} else {
cp->lstate = link_force_ok;
}
cp->link_transition = LINK_TRANSITION_LINK_CONFIG;
cas_phy_write(cp, MII_BMCR, ctl);
cas_mif_poll(cp, 1);
}
cp->timer_ticks = 0;
mod_timer(&cp->link_timer, jiffies + CAS_LINK_TIMEOUT);
}
static int cas_reset_mii_phy(struct cas *cp)
{
int limit = STOP_TRIES_PHY;
u16 val;
cas_phy_write(cp, MII_BMCR, BMCR_RESET);
udelay(100);
while (--limit) {
val = cas_phy_read(cp, MII_BMCR);
if ((val & BMCR_RESET) == 0)
break;
udelay(10);
}
return limit <= 0;
}
static int cas_saturn_firmware_init(struct cas *cp)
{
const struct firmware *fw;
const char fw_name[] = "sun/cassini.bin";
int err;
if (PHY_NS_DP83065 != cp->phy_id)
return 0;
err = request_firmware(&fw, fw_name, &cp->pdev->dev);
if (err) {
pr_err("Failed to load firmware \"%s\"\n",
fw_name);
return err;
}
if (fw->size < 2) {
pr_err("bogus length %zu in \"%s\"\n",
fw->size, fw_name);
err = -EINVAL;
goto out;
}
cp->fw_load_addr= fw->data[1] << 8 | fw->data[0];
cp->fw_size = fw->size - 2;
cp->fw_data = vmalloc(cp->fw_size);
if (!cp->fw_data) {
err = -ENOMEM;
pr_err("\"%s\" Failed %d\n", fw_name, err);
goto out;
}
memcpy(cp->fw_data, &fw->data[2], cp->fw_size);
out:
release_firmware(fw);
return err;
}
static void cas_saturn_firmware_load(struct cas *cp)
{
int i;
cas_phy_powerdown(cp);
cas_phy_write(cp, DP83065_MII_MEM, 0x0);
cas_phy_write(cp, DP83065_MII_REGE, 0x8ff9);
cas_phy_write(cp, DP83065_MII_REGD, 0xbd);
cas_phy_write(cp, DP83065_MII_REGE, 0x8ffa);
cas_phy_write(cp, DP83065_MII_REGD, 0x82);
cas_phy_write(cp, DP83065_MII_REGE, 0x8ffb);
cas_phy_write(cp, DP83065_MII_REGD, 0x0);
cas_phy_write(cp, DP83065_MII_REGE, 0x8ffc);
cas_phy_write(cp, DP83065_MII_REGD, 0x39);
cas_phy_write(cp, DP83065_MII_MEM, 0x1);
cas_phy_write(cp, DP83065_MII_REGE, cp->fw_load_addr);
for (i = 0; i < cp->fw_size; i++)
cas_phy_write(cp, DP83065_MII_REGD, cp->fw_data[i]);
cas_phy_write(cp, DP83065_MII_REGE, 0x8ff8);
cas_phy_write(cp, DP83065_MII_REGD, 0x1);
}
static void cas_phy_init(struct cas *cp)
{
u16 val;
if (CAS_PHY_MII(cp->phy_type)) {
writel(PCS_DATAPATH_MODE_MII,
cp->regs + REG_PCS_DATAPATH_MODE);
cas_mif_poll(cp, 0);
cas_reset_mii_phy(cp);
if (PHY_LUCENT_B0 == cp->phy_id) {
cas_phy_write(cp, LUCENT_MII_REG, 0x8000);
cas_phy_write(cp, MII_BMCR, 0x00f1);
cas_phy_write(cp, LUCENT_MII_REG, 0x0);
} else if (PHY_BROADCOM_B0 == (cp->phy_id & 0xFFFFFFFC)) {
cas_phy_write(cp, BROADCOM_MII_REG8, 0x0C20);
cas_phy_write(cp, BROADCOM_MII_REG7, 0x0012);
cas_phy_write(cp, BROADCOM_MII_REG5, 0x1804);
cas_phy_write(cp, BROADCOM_MII_REG7, 0x0013);
cas_phy_write(cp, BROADCOM_MII_REG5, 0x1204);
cas_phy_write(cp, BROADCOM_MII_REG7, 0x8006);
cas_phy_write(cp, BROADCOM_MII_REG5, 0x0132);
cas_phy_write(cp, BROADCOM_MII_REG7, 0x8006);
cas_phy_write(cp, BROADCOM_MII_REG5, 0x0232);
cas_phy_write(cp, BROADCOM_MII_REG7, 0x201F);
cas_phy_write(cp, BROADCOM_MII_REG5, 0x0A20);
} else if (PHY_BROADCOM_5411 == cp->phy_id) {
val = cas_phy_read(cp, BROADCOM_MII_REG4);
val = cas_phy_read(cp, BROADCOM_MII_REG4);
if (val & 0x0080) {
cas_phy_write(cp, BROADCOM_MII_REG4,
val & ~0x0080);
}
} else if (cp->cas_flags & CAS_FLAG_SATURN) {
writel((cp->phy_type & CAS_PHY_MII_MDIO0) ?
SATURN_PCFG_FSI : 0x0,
cp->regs + REG_SATURN_PCFG);
if (PHY_NS_DP83065 == cp->phy_id) {
cas_saturn_firmware_load(cp);
}
cas_phy_powerup(cp);
}
val = cas_phy_read(cp, MII_BMCR);
val &= ~BMCR_ANENABLE;
cas_phy_write(cp, MII_BMCR, val);
udelay(10);
cas_phy_write(cp, MII_ADVERTISE,
cas_phy_read(cp, MII_ADVERTISE) |
(ADVERTISE_10HALF | ADVERTISE_10FULL |
ADVERTISE_100HALF | ADVERTISE_100FULL |
CAS_ADVERTISE_PAUSE |
CAS_ADVERTISE_ASYM_PAUSE));
if (cp->cas_flags & CAS_FLAG_1000MB_CAP) {
val = cas_phy_read(cp, CAS_MII_1000_CTRL);
val &= ~CAS_ADVERTISE_1000HALF;
val |= CAS_ADVERTISE_1000FULL;
cas_phy_write(cp, CAS_MII_1000_CTRL, val);
}
} else {
u32 val;
int limit;
writel(PCS_DATAPATH_MODE_SERDES,
cp->regs + REG_PCS_DATAPATH_MODE);
if (cp->cas_flags & CAS_FLAG_SATURN)
writel(0, cp->regs + REG_SATURN_PCFG);
val = readl(cp->regs + REG_PCS_MII_CTRL);
val |= PCS_MII_RESET;
writel(val, cp->regs + REG_PCS_MII_CTRL);
limit = STOP_TRIES;
while (--limit > 0) {
udelay(10);
if ((readl(cp->regs + REG_PCS_MII_CTRL) &
PCS_MII_RESET) == 0)
break;
}
if (limit <= 0)
netdev_warn(cp->dev, "PCS reset bit would not clear [%08x]\n",
readl(cp->regs + REG_PCS_STATE_MACHINE));
writel(0x0, cp->regs + REG_PCS_CFG);
val = readl(cp->regs + REG_PCS_MII_ADVERT);
val &= ~PCS_MII_ADVERT_HD;
val |= (PCS_MII_ADVERT_FD | PCS_MII_ADVERT_SYM_PAUSE |
PCS_MII_ADVERT_ASYM_PAUSE);
writel(val, cp->regs + REG_PCS_MII_ADVERT);
writel(PCS_CFG_EN, cp->regs + REG_PCS_CFG);
writel(PCS_SERDES_CTRL_SYNCD_EN,
cp->regs + REG_PCS_SERDES_CTRL);
}
}
static int cas_pcs_link_check(struct cas *cp)
{
u32 stat, state_machine;
int retval = 0;
stat = readl(cp->regs + REG_PCS_MII_STATUS);
if ((stat & PCS_MII_STATUS_LINK_STATUS) == 0)
stat = readl(cp->regs + REG_PCS_MII_STATUS);
if ((stat & (PCS_MII_STATUS_AUTONEG_COMP |
PCS_MII_STATUS_REMOTE_FAULT)) ==
(PCS_MII_STATUS_AUTONEG_COMP | PCS_MII_STATUS_REMOTE_FAULT))
netif_info(cp, link, cp->dev, "PCS RemoteFault\n");
state_machine = readl(cp->regs + REG_PCS_STATE_MACHINE);
if ((state_machine & PCS_SM_LINK_STATE_MASK) != SM_LINK_STATE_UP) {
stat &= ~PCS_MII_STATUS_LINK_STATUS;
} else if (state_machine & PCS_SM_WORD_SYNC_STATE_MASK) {
stat |= PCS_MII_STATUS_LINK_STATUS;
}
if (stat & PCS_MII_STATUS_LINK_STATUS) {
if (cp->lstate != link_up) {
if (cp->opened) {
cp->lstate = link_up;
cp->link_transition = LINK_TRANSITION_LINK_UP;
cas_set_link_modes(cp);
netif_carrier_on(cp->dev);
}
}
} else if (cp->lstate == link_up) {
cp->lstate = link_down;
if (link_transition_timeout != 0 &&
cp->link_transition != LINK_TRANSITION_REQUESTED_RESET &&
!cp->link_transition_jiffies_valid) {
retval = 1;
cp->link_transition = LINK_TRANSITION_REQUESTED_RESET;
cp->link_transition_jiffies = jiffies;
cp->link_transition_jiffies_valid = 1;
} else {
cp->link_transition = LINK_TRANSITION_ON_FAILURE;
}
netif_carrier_off(cp->dev);
if (cp->opened)
netif_info(cp, link, cp->dev, "PCS link down\n");
if ((cp->cas_flags & CAS_FLAG_REG_PLUS) == 0) {
stat = readl(cp->regs + REG_PCS_SERDES_STATE);
if (stat == 0x03)
return 1;
}
} else if (cp->lstate == link_down) {
if (link_transition_timeout != 0 &&
cp->link_transition != LINK_TRANSITION_REQUESTED_RESET &&
!cp->link_transition_jiffies_valid) {
retval = 1;
cp->link_transition = LINK_TRANSITION_REQUESTED_RESET;
cp->link_transition_jiffies = jiffies;
cp->link_transition_jiffies_valid = 1;
} else {
cp->link_transition = LINK_TRANSITION_STILL_FAILED;
}
}
return retval;
}
static int cas_pcs_interrupt(struct net_device *dev,
struct cas *cp, u32 status)
{
u32 stat = readl(cp->regs + REG_PCS_INTR_STATUS);
if ((stat & PCS_INTR_STATUS_LINK_CHANGE) == 0)
return 0;
return cas_pcs_link_check(cp);
}
static int cas_txmac_interrupt(struct net_device *dev,
struct cas *cp, u32 status)
{
u32 txmac_stat = readl(cp->regs + REG_MAC_TX_STATUS);
if (!txmac_stat)
return 0;
netif_printk(cp, intr, KERN_DEBUG, cp->dev,
"txmac interrupt, txmac_stat: 0x%x\n", txmac_stat);
if ((txmac_stat & MAC_TX_DEFER_TIMER) &&
!(txmac_stat & ~MAC_TX_DEFER_TIMER))
return 0;
spin_lock(&cp->stat_lock[0]);
if (txmac_stat & MAC_TX_UNDERRUN) {
netdev_err(dev, "TX MAC xmit underrun\n");
cp->net_stats[0].tx_fifo_errors++;
}
if (txmac_stat & MAC_TX_MAX_PACKET_ERR) {
netdev_err(dev, "TX MAC max packet size error\n");
cp->net_stats[0].tx_errors++;
}
if (txmac_stat & MAC_TX_COLL_NORMAL)
cp->net_stats[0].collisions += 0x10000;
if (txmac_stat & MAC_TX_COLL_EXCESS) {
cp->net_stats[0].tx_aborted_errors += 0x10000;
cp->net_stats[0].collisions += 0x10000;
}
if (txmac_stat & MAC_TX_COLL_LATE) {
cp->net_stats[0].tx_aborted_errors += 0x10000;
cp->net_stats[0].collisions += 0x10000;
}
spin_unlock(&cp->stat_lock[0]);
return 0;
}
static void cas_load_firmware(struct cas *cp, cas_hp_inst_t *firmware)
{
cas_hp_inst_t *inst;
u32 val;
int i;
i = 0;
while ((inst = firmware) && inst->note) {
writel(i, cp->regs + REG_HP_INSTR_RAM_ADDR);
val = CAS_BASE(HP_INSTR_RAM_HI_VAL, inst->val);
val |= CAS_BASE(HP_INSTR_RAM_HI_MASK, inst->mask);
writel(val, cp->regs + REG_HP_INSTR_RAM_DATA_HI);
val = CAS_BASE(HP_INSTR_RAM_MID_OUTARG, inst->outarg >> 10);
val |= CAS_BASE(HP_INSTR_RAM_MID_OUTOP, inst->outop);
val |= CAS_BASE(HP_INSTR_RAM_MID_FNEXT, inst->fnext);
val |= CAS_BASE(HP_INSTR_RAM_MID_FOFF, inst->foff);
val |= CAS_BASE(HP_INSTR_RAM_MID_SNEXT, inst->snext);
val |= CAS_BASE(HP_INSTR_RAM_MID_SOFF, inst->soff);
val |= CAS_BASE(HP_INSTR_RAM_MID_OP, inst->op);
writel(val, cp->regs + REG_HP_INSTR_RAM_DATA_MID);
val = CAS_BASE(HP_INSTR_RAM_LOW_OUTMASK, inst->outmask);
val |= CAS_BASE(HP_INSTR_RAM_LOW_OUTSHIFT, inst->outshift);
val |= CAS_BASE(HP_INSTR_RAM_LOW_OUTEN, inst->outenab);
val |= CAS_BASE(HP_INSTR_RAM_LOW_OUTARG, inst->outarg);
writel(val, cp->regs + REG_HP_INSTR_RAM_DATA_LOW);
++firmware;
++i;
}
}
static void cas_init_rx_dma(struct cas *cp)
{
u64 desc_dma = cp->block_dvma;
u32 val;
int i, size;
val = CAS_BASE(RX_CFG_SWIVEL, RX_SWIVEL_OFF_VAL);
val |= CAS_BASE(RX_CFG_DESC_RING, RX_DESC_RINGN_INDEX(0));
val |= CAS_BASE(RX_CFG_COMP_RING, RX_COMP_RINGN_INDEX(0));
if ((N_RX_DESC_RINGS > 1) &&
(cp->cas_flags & CAS_FLAG_REG_PLUS))
val |= CAS_BASE(RX_CFG_DESC_RING1, RX_DESC_RINGN_INDEX(1));
writel(val, cp->regs + REG_RX_CFG);
val = (unsigned long) cp->init_rxds[0] -
(unsigned long) cp->init_block;
writel((desc_dma + val) >> 32, cp->regs + REG_RX_DB_HI);
writel((desc_dma + val) & 0xffffffff, cp->regs + REG_RX_DB_LOW);
writel(RX_DESC_RINGN_SIZE(0) - 4, cp->regs + REG_RX_KICK);
if (cp->cas_flags & CAS_FLAG_REG_PLUS) {
val = (unsigned long) cp->init_rxds[1] -
(unsigned long) cp->init_block;
writel((desc_dma + val) >> 32, cp->regs + REG_PLUS_RX_DB1_HI);
writel((desc_dma + val) & 0xffffffff, cp->regs +
REG_PLUS_RX_DB1_LOW);
writel(RX_DESC_RINGN_SIZE(1) - 4, cp->regs +
REG_PLUS_RX_KICK1);
}
val = (unsigned long) cp->init_rxcs[0] -
(unsigned long) cp->init_block;
writel((desc_dma + val) >> 32, cp->regs + REG_RX_CB_HI);
writel((desc_dma + val) & 0xffffffff, cp->regs + REG_RX_CB_LOW);
if (cp->cas_flags & CAS_FLAG_REG_PLUS) {
for (i = 1; i < MAX_RX_COMP_RINGS; i++) {
val = (unsigned long) cp->init_rxcs[i] -
(unsigned long) cp->init_block;
writel((desc_dma + val) >> 32, cp->regs +
REG_PLUS_RX_CBN_HI(i));
writel((desc_dma + val) & 0xffffffff, cp->regs +
REG_PLUS_RX_CBN_LOW(i));
}
}
readl(cp->regs + REG_INTR_STATUS_ALIAS);
writel(INTR_RX_DONE | INTR_RX_BUF_UNAVAIL, cp->regs + REG_ALIAS_CLEAR);
if (cp->cas_flags & CAS_FLAG_REG_PLUS) {
for (i = 1; i < N_RX_COMP_RINGS; i++)
readl(cp->regs + REG_PLUS_INTRN_STATUS_ALIAS(i));
if (N_RX_COMP_RINGS > 1)
writel(INTR_RX_DONE_ALT | INTR_RX_BUF_UNAVAIL_1,
cp->regs + REG_PLUS_ALIASN_CLEAR(1));
for (i = 2; i < N_RX_COMP_RINGS; i++)
writel(INTR_RX_DONE_ALT,
cp->regs + REG_PLUS_ALIASN_CLEAR(i));
}
val = CAS_BASE(RX_PAUSE_THRESH_OFF,
cp->rx_pause_off / RX_PAUSE_THRESH_QUANTUM);
val |= CAS_BASE(RX_PAUSE_THRESH_ON,
cp->rx_pause_on / RX_PAUSE_THRESH_QUANTUM);
writel(val, cp->regs + REG_RX_PAUSE_THRESH);
for (i = 0; i < 64; i++) {
writel(i, cp->regs + REG_RX_TABLE_ADDR);
writel(0x0, cp->regs + REG_RX_TABLE_DATA_LOW);
writel(0x0, cp->regs + REG_RX_TABLE_DATA_MID);
writel(0x0, cp->regs + REG_RX_TABLE_DATA_HI);
}
writel(0x0, cp->regs + REG_RX_CTRL_FIFO_ADDR);
writel(0x0, cp->regs + REG_RX_IPP_FIFO_ADDR);
#ifdef USE_RX_BLANK
val = CAS_BASE(RX_BLANK_INTR_TIME, RX_BLANK_INTR_TIME_VAL);
val |= CAS_BASE(RX_BLANK_INTR_PKT, RX_BLANK_INTR_PKT_VAL);
writel(val, cp->regs + REG_RX_BLANK);
#else
writel(0x0, cp->regs + REG_RX_BLANK);
#endif
val = CAS_BASE(RX_AE_THRESH_COMP, RX_AE_COMP_VAL);
writel(val, cp->regs + REG_RX_AE_THRESH);
if (cp->cas_flags & CAS_FLAG_REG_PLUS) {
val = CAS_BASE(RX_AE1_THRESH_FREE, RX_AE_FREEN_VAL(1));
writel(val, cp->regs + REG_PLUS_RX_AE1_THRESH);
}
writel(0x0, cp->regs + REG_RX_RED);
val = 0;
if (cp->page_size == 0x1000)
val = 0x1;
else if (cp->page_size == 0x2000)
val = 0x2;
else if (cp->page_size == 0x4000)
val = 0x3;
size = cp->dev->mtu + 64;
if (size > cp->page_size)
size = cp->page_size;
if (size <= 0x400)
i = 0x0;
else if (size <= 0x800)
i = 0x1;
else if (size <= 0x1000)
i = 0x2;
else
i = 0x3;
cp->mtu_stride = 1 << (i + 10);
val = CAS_BASE(RX_PAGE_SIZE, val);
val |= CAS_BASE(RX_PAGE_SIZE_MTU_STRIDE, i);
val |= CAS_BASE(RX_PAGE_SIZE_MTU_COUNT, cp->page_size >> (i + 10));
val |= CAS_BASE(RX_PAGE_SIZE_MTU_OFF, 0x1);
writel(val, cp->regs + REG_RX_PAGE_SIZE);
if (CAS_HP_FIRMWARE == cas_prog_null)
return;
val = CAS_BASE(HP_CFG_NUM_CPU, CAS_NCPUS > 63 ? 0 : CAS_NCPUS);
val |= HP_CFG_PARSE_EN | HP_CFG_SYN_INC_MASK;
val |= CAS_BASE(HP_CFG_TCP_THRESH, HP_TCP_THRESH_VAL);
writel(val, cp->regs + REG_HP_CFG);
}
static inline void cas_rxc_init(struct cas_rx_comp *rxc)
{
memset(rxc, 0, sizeof(*rxc));
rxc->word4 = cpu_to_le64(RX_COMP4_ZERO);
}
static inline cas_page_t *cas_page_spare(struct cas *cp, const int index)
{
cas_page_t *page = cp->rx_pages[1][index];
cas_page_t *new;
if (page_count(page->buffer) == 1)
return page;
new = cas_page_dequeue(cp);
if (new) {
spin_lock(&cp->rx_inuse_lock);
list_add(&page->list, &cp->rx_inuse_list);
spin_unlock(&cp->rx_inuse_lock);
}
return new;
}
static cas_page_t *cas_page_swap(struct cas *cp, const int ring,
const int index)
{
cas_page_t **page0 = cp->rx_pages[0];
cas_page_t **page1 = cp->rx_pages[1];
if (page_count(page0[index]->buffer) > 1) {
cas_page_t *new = cas_page_spare(cp, index);
if (new) {
page1[index] = page0[index];
page0[index] = new;
}
}
RX_USED_SET(page0[index], 0);
return page0[index];
}
static void cas_clean_rxds(struct cas *cp)
{
struct cas_rx_desc *rxd = cp->init_rxds[0];
int i, size;
for (i = 0; i < N_RX_FLOWS; i++) {
struct sk_buff *skb;
while ((skb = __skb_dequeue(&cp->rx_flows[i]))) {
cas_skb_release(skb);
}
}
size = RX_DESC_RINGN_SIZE(0);
for (i = 0; i < size; i++) {
cas_page_t *page = cas_page_swap(cp, 0, i);
rxd[i].buffer = cpu_to_le64(page->dma_addr);
rxd[i].index = cpu_to_le64(CAS_BASE(RX_INDEX_NUM, i) |
CAS_BASE(RX_INDEX_RING, 0));
}
cp->rx_old[0] = RX_DESC_RINGN_SIZE(0) - 4;
cp->rx_last[0] = 0;
cp->cas_flags &= ~CAS_FLAG_RXD_POST(0);
}
static void cas_clean_rxcs(struct cas *cp)
{
int i, j;
memset(cp->rx_cur, 0, sizeof(*cp->rx_cur)*N_RX_COMP_RINGS);
memset(cp->rx_new, 0, sizeof(*cp->rx_new)*N_RX_COMP_RINGS);
for (i = 0; i < N_RX_COMP_RINGS; i++) {
struct cas_rx_comp *rxc = cp->init_rxcs[i];
for (j = 0; j < RX_COMP_RINGN_SIZE(i); j++) {
cas_rxc_init(rxc + j);
}
}
}
static int cas_rxmac_interrupt(struct net_device *dev, struct cas *cp,
u32 status)
{
u32 stat = readl(cp->regs + REG_MAC_RX_STATUS);
if (!stat)
return 0;
netif_dbg(cp, intr, cp->dev, "rxmac interrupt, stat: 0x%x\n", stat);
spin_lock(&cp->stat_lock[0]);
if (stat & MAC_RX_ALIGN_ERR)
cp->net_stats[0].rx_frame_errors += 0x10000;
if (stat & MAC_RX_CRC_ERR)
cp->net_stats[0].rx_crc_errors += 0x10000;
if (stat & MAC_RX_LEN_ERR)
cp->net_stats[0].rx_length_errors += 0x10000;
if (stat & MAC_RX_OVERFLOW) {
cp->net_stats[0].rx_over_errors++;
cp->net_stats[0].rx_fifo_errors++;
}
spin_unlock(&cp->stat_lock[0]);
return 0;
}
static int cas_mac_interrupt(struct net_device *dev, struct cas *cp,
u32 status)
{
u32 stat = readl(cp->regs + REG_MAC_CTRL_STATUS);
if (!stat)
return 0;
netif_printk(cp, intr, KERN_DEBUG, cp->dev,
"mac interrupt, stat: 0x%x\n", stat);
if (stat & MAC_CTRL_PAUSE_STATE)
cp->pause_entered++;
if (stat & MAC_CTRL_PAUSE_RECEIVED)
cp->pause_last_time_recvd = (stat >> 16);
return 0;
}
static inline int cas_mdio_link_not_up(struct cas *cp)
{
u16 val;
switch (cp->lstate) {
case link_force_ret:
netif_info(cp, link, cp->dev, "Autoneg failed again, keeping forced mode\n");
cas_phy_write(cp, MII_BMCR, cp->link_fcntl);
cp->timer_ticks = 5;
cp->lstate = link_force_ok;
cp->link_transition = LINK_TRANSITION_LINK_CONFIG;
break;
case link_aneg:
val = cas_phy_read(cp, MII_BMCR);
val &= ~(BMCR_ANRESTART | BMCR_ANENABLE);
val |= BMCR_FULLDPLX;
val |= (cp->cas_flags & CAS_FLAG_1000MB_CAP) ?
CAS_BMCR_SPEED1000 : BMCR_SPEED100;
cas_phy_write(cp, MII_BMCR, val);
cp->timer_ticks = 5;
cp->lstate = link_force_try;
cp->link_transition = LINK_TRANSITION_LINK_CONFIG;
break;
case link_force_try:
val = cas_phy_read(cp, MII_BMCR);
cp->timer_ticks = 5;
if (val & CAS_BMCR_SPEED1000) {
val &= ~CAS_BMCR_SPEED1000;
val |= (BMCR_SPEED100 | BMCR_FULLDPLX);
cas_phy_write(cp, MII_BMCR, val);
break;
}
if (val & BMCR_SPEED100) {
if (val & BMCR_FULLDPLX)
val &= ~BMCR_FULLDPLX;
else {
val &= ~BMCR_SPEED100;
}
cas_phy_write(cp, MII_BMCR, val);
break;
}
default:
break;
}
return 0;
}
static int cas_mii_link_check(struct cas *cp, const u16 bmsr)
{
int restart;
if (bmsr & BMSR_LSTATUS) {
if ((cp->lstate == link_force_try) &&
(cp->link_cntl & BMCR_ANENABLE)) {
cp->lstate = link_force_ret;
cp->link_transition = LINK_TRANSITION_LINK_CONFIG;
cas_mif_poll(cp, 0);
cp->link_fcntl = cas_phy_read(cp, MII_BMCR);
cp->timer_ticks = 5;
if (cp->opened)
netif_info(cp, link, cp->dev,
"Got link after fallback, retrying autoneg once...\n");
cas_phy_write(cp, MII_BMCR,
cp->link_fcntl | BMCR_ANENABLE |
BMCR_ANRESTART);
cas_mif_poll(cp, 1);
} else if (cp->lstate != link_up) {
cp->lstate = link_up;
cp->link_transition = LINK_TRANSITION_LINK_UP;
if (cp->opened) {
cas_set_link_modes(cp);
netif_carrier_on(cp->dev);
}
}
return 0;
}
restart = 0;
if (cp->lstate == link_up) {
cp->lstate = link_down;
cp->link_transition = LINK_TRANSITION_LINK_DOWN;
netif_carrier_off(cp->dev);
if (cp->opened)
netif_info(cp, link, cp->dev, "Link down\n");
restart = 1;
} else if (++cp->timer_ticks > 10)
cas_mdio_link_not_up(cp);
return restart;
}
static int cas_mif_interrupt(struct net_device *dev, struct cas *cp,
u32 status)
{
u32 stat = readl(cp->regs + REG_MIF_STATUS);
u16 bmsr;
if (CAS_VAL(MIF_STATUS_POLL_STATUS, stat) == 0)
return 0;
bmsr = CAS_VAL(MIF_STATUS_POLL_DATA, stat);
return cas_mii_link_check(cp, bmsr);
}
static int cas_pci_interrupt(struct net_device *dev, struct cas *cp,
u32 status)
{
u32 stat = readl(cp->regs + REG_PCI_ERR_STATUS);
if (!stat)
return 0;
netdev_err(dev, "PCI error [%04x:%04x]",
stat, readl(cp->regs + REG_BIM_DIAG));
if ((stat & PCI_ERR_BADACK) &&
((cp->cas_flags & CAS_FLAG_REG_PLUS) == 0))
pr_cont(" <No ACK64# during ABS64 cycle>");
if (stat & PCI_ERR_DTRTO)
pr_cont(" <Delayed transaction timeout>");
if (stat & PCI_ERR_OTHER)
pr_cont(" <other>");
if (stat & PCI_ERR_BIM_DMA_WRITE)
pr_cont(" <BIM DMA 0 write req>");
if (stat & PCI_ERR_BIM_DMA_READ)
pr_cont(" <BIM DMA 0 read req>");
pr_cont("\n");
if (stat & PCI_ERR_OTHER) {
u16 cfg;
pci_read_config_word(cp->pdev, PCI_STATUS, &cfg);
netdev_err(dev, "Read PCI cfg space status [%04x]\n", cfg);
if (cfg & PCI_STATUS_PARITY)
netdev_err(dev, "PCI parity error detected\n");
if (cfg & PCI_STATUS_SIG_TARGET_ABORT)
netdev_err(dev, "PCI target abort\n");
if (cfg & PCI_STATUS_REC_TARGET_ABORT)
netdev_err(dev, "PCI master acks target abort\n");
if (cfg & PCI_STATUS_REC_MASTER_ABORT)
netdev_err(dev, "PCI master abort\n");
if (cfg & PCI_STATUS_SIG_SYSTEM_ERROR)
netdev_err(dev, "PCI system error SERR#\n");
if (cfg & PCI_STATUS_DETECTED_PARITY)
netdev_err(dev, "PCI parity error\n");
cfg &= (PCI_STATUS_PARITY |
PCI_STATUS_SIG_TARGET_ABORT |
PCI_STATUS_REC_TARGET_ABORT |
PCI_STATUS_REC_MASTER_ABORT |
PCI_STATUS_SIG_SYSTEM_ERROR |
PCI_STATUS_DETECTED_PARITY);
pci_write_config_word(cp->pdev, PCI_STATUS, cfg);
}
return 1;
}
static int cas_abnormal_irq(struct net_device *dev, struct cas *cp,
u32 status)
{
if (status & INTR_RX_TAG_ERROR) {
netif_printk(cp, rx_err, KERN_DEBUG, cp->dev,
"corrupt rx tag framing\n");
spin_lock(&cp->stat_lock[0]);
cp->net_stats[0].rx_errors++;
spin_unlock(&cp->stat_lock[0]);
goto do_reset;
}
if (status & INTR_RX_LEN_MISMATCH) {
netif_printk(cp, rx_err, KERN_DEBUG, cp->dev,
"length mismatch for rx frame\n");
spin_lock(&cp->stat_lock[0]);
cp->net_stats[0].rx_errors++;
spin_unlock(&cp->stat_lock[0]);
goto do_reset;
}
if (status & INTR_PCS_STATUS) {
if (cas_pcs_interrupt(dev, cp, status))
goto do_reset;
}
if (status & INTR_TX_MAC_STATUS) {
if (cas_txmac_interrupt(dev, cp, status))
goto do_reset;
}
if (status & INTR_RX_MAC_STATUS) {
if (cas_rxmac_interrupt(dev, cp, status))
goto do_reset;
}
if (status & INTR_MAC_CTRL_STATUS) {
if (cas_mac_interrupt(dev, cp, status))
goto do_reset;
}
if (status & INTR_MIF_STATUS) {
if (cas_mif_interrupt(dev, cp, status))
goto do_reset;
}
if (status & INTR_PCI_ERROR_STATUS) {
if (cas_pci_interrupt(dev, cp, status))
goto do_reset;
}
return 0;
do_reset:
#if 1
atomic_inc(&cp->reset_task_pending);
atomic_inc(&cp->reset_task_pending_all);
netdev_err(dev, "reset called in cas_abnormal_irq [0x%x]\n", status);
schedule_work(&cp->reset_task);
#else
atomic_set(&cp->reset_task_pending, CAS_RESET_ALL);
netdev_err(dev, "reset called in cas_abnormal_irq\n");
schedule_work(&cp->reset_task);
#endif
return 1;
}
static inline int cas_calc_tabort(struct cas *cp, const unsigned long addr,
const int len)
{
unsigned long off = addr + len;
if (CAS_TABORT(cp) == 1)
return 0;
if ((CAS_ROUND_PAGE(off) - off) > TX_TARGET_ABORT_LEN)
return 0;
return TX_TARGET_ABORT_LEN;
}
static inline void cas_tx_ringN(struct cas *cp, int ring, int limit)
{
struct cas_tx_desc *txds;
struct sk_buff **skbs;
struct net_device *dev = cp->dev;
int entry, count;
spin_lock(&cp->tx_lock[ring]);
txds = cp->init_txds[ring];
skbs = cp->tx_skbs[ring];
entry = cp->tx_old[ring];
count = TX_BUFF_COUNT(ring, entry, limit);
while (entry != limit) {
struct sk_buff *skb = skbs[entry];
dma_addr_t daddr;
u32 dlen;
int frag;
if (!skb) {
entry = TX_DESC_NEXT(ring, entry);
continue;
}
count -= skb_shinfo(skb)->nr_frags +
+ cp->tx_tiny_use[ring][entry].nbufs + 1;
if (count < 0)
break;
netif_printk(cp, tx_done, KERN_DEBUG, cp->dev,
"tx[%d] done, slot %d\n", ring, entry);
skbs[entry] = NULL;
cp->tx_tiny_use[ring][entry].nbufs = 0;
for (frag = 0; frag <= skb_shinfo(skb)->nr_frags; frag++) {
struct cas_tx_desc *txd = txds + entry;
daddr = le64_to_cpu(txd->buffer);
dlen = CAS_VAL(TX_DESC_BUFLEN,
le64_to_cpu(txd->control));
pci_unmap_page(cp->pdev, daddr, dlen,
PCI_DMA_TODEVICE);
entry = TX_DESC_NEXT(ring, entry);
if (cp->tx_tiny_use[ring][entry].used) {
cp->tx_tiny_use[ring][entry].used = 0;
entry = TX_DESC_NEXT(ring, entry);
}
}
spin_lock(&cp->stat_lock[ring]);
cp->net_stats[ring].tx_packets++;
cp->net_stats[ring].tx_bytes += skb->len;
spin_unlock(&cp->stat_lock[ring]);
dev_kfree_skb_irq(skb);
}
cp->tx_old[ring] = entry;
if (netif_queue_stopped(dev) &&
(TX_BUFFS_AVAIL(cp, ring) > CAS_TABORT(cp)*(MAX_SKB_FRAGS + 1)))
netif_wake_queue(dev);
spin_unlock(&cp->tx_lock[ring]);
}
static void cas_tx(struct net_device *dev, struct cas *cp,
u32 status)
{
int limit, ring;
#ifdef USE_TX_COMPWB
u64 compwb = le64_to_cpu(cp->init_block->tx_compwb);
#endif
netif_printk(cp, intr, KERN_DEBUG, cp->dev,
"tx interrupt, status: 0x%x, %llx\n",
status, (unsigned long long)compwb);
for (ring = 0; ring < N_TX_RINGS; ring++) {
#ifdef USE_TX_COMPWB
limit = (CAS_VAL(TX_COMPWB_MSB, compwb) << 8) |
CAS_VAL(TX_COMPWB_LSB, compwb);
compwb = TX_COMPWB_NEXT(compwb);
#else
limit = readl(cp->regs + REG_TX_COMPN(ring));
#endif
if (cp->tx_old[ring] != limit)
cas_tx_ringN(cp, ring, limit);
}
}
static int cas_rx_process_pkt(struct cas *cp, struct cas_rx_comp *rxc,
int entry, const u64 *words,
struct sk_buff **skbref)
{
int dlen, hlen, len, i, alloclen;
int off, swivel = RX_SWIVEL_OFF_VAL;
struct cas_page *page;
struct sk_buff *skb;
void *addr, *crcaddr;
__sum16 csum;
char *p;
hlen = CAS_VAL(RX_COMP2_HDR_SIZE, words[1]);
dlen = CAS_VAL(RX_COMP1_DATA_SIZE, words[0]);
len = hlen + dlen;
if (RX_COPY_ALWAYS || (words[2] & RX_COMP3_SMALL_PKT))
alloclen = len;
else
alloclen = max(hlen, RX_COPY_MIN);
skb = dev_alloc_skb(alloclen + swivel + cp->crc_size);
if (skb == NULL)
return -1;
*skbref = skb;
skb_reserve(skb, swivel);
p = skb->data;
addr = crcaddr = NULL;
if (hlen) {
i = CAS_VAL(RX_COMP2_HDR_INDEX, words[1]);
page = cp->rx_pages[CAS_VAL(RX_INDEX_RING, i)][CAS_VAL(RX_INDEX_NUM, i)];
off = CAS_VAL(RX_COMP2_HDR_OFF, words[1]) * 0x100 +
swivel;
i = hlen;
if (!dlen)
i += cp->crc_size;
pci_dma_sync_single_for_cpu(cp->pdev, page->dma_addr + off, i,
PCI_DMA_FROMDEVICE);
addr = cas_page_map(page->buffer);
memcpy(p, addr + off, i);
pci_dma_sync_single_for_device(cp->pdev, page->dma_addr + off, i,
PCI_DMA_FROMDEVICE);
cas_page_unmap(addr);
RX_USED_ADD(page, 0x100);
p += hlen;
swivel = 0;
}
if (alloclen < (hlen + dlen)) {
skb_frag_t *frag = skb_shinfo(skb)->frags;
i = CAS_VAL(RX_COMP1_DATA_INDEX, words[0]);
page = cp->rx_pages[CAS_VAL(RX_INDEX_RING, i)][CAS_VAL(RX_INDEX_NUM, i)];
off = CAS_VAL(RX_COMP1_DATA_OFF, words[0]) + swivel;
hlen = min(cp->page_size - off, dlen);
if (hlen < 0) {
netif_printk(cp, rx_err, KERN_DEBUG, cp->dev,
"rx page overflow: %d\n", hlen);
dev_kfree_skb_irq(skb);
return -1;
}
i = hlen;
if (i == dlen)
i += cp->crc_size;
pci_dma_sync_single_for_cpu(cp->pdev, page->dma_addr + off, i,
PCI_DMA_FROMDEVICE);
swivel = 0;
if (p == (char *) skb->data) {
addr = cas_page_map(page->buffer);
memcpy(p, addr + off, RX_COPY_MIN);
pci_dma_sync_single_for_device(cp->pdev, page->dma_addr + off, i,
PCI_DMA_FROMDEVICE);
cas_page_unmap(addr);
off += RX_COPY_MIN;
swivel = RX_COPY_MIN;
RX_USED_ADD(page, cp->mtu_stride);
} else {
RX_USED_ADD(page, hlen);
}
skb_put(skb, alloclen);
skb_shinfo(skb)->nr_frags++;
skb->data_len += hlen - swivel;
skb->truesize += hlen - swivel;
skb->len += hlen - swivel;
get_page(page->buffer);
frag->page = page->buffer;
frag->page_offset = off;
frag->size = hlen - swivel;
if ((words[0] & RX_COMP1_SPLIT_PKT) && ((dlen -= hlen) > 0)) {
hlen = dlen;
off = 0;
i = CAS_VAL(RX_COMP2_NEXT_INDEX, words[1]);
page = cp->rx_pages[CAS_VAL(RX_INDEX_RING, i)][CAS_VAL(RX_INDEX_NUM, i)];
pci_dma_sync_single_for_cpu(cp->pdev, page->dma_addr,
hlen + cp->crc_size,
PCI_DMA_FROMDEVICE);
pci_dma_sync_single_for_device(cp->pdev, page->dma_addr,
hlen + cp->crc_size,
PCI_DMA_FROMDEVICE);
skb_shinfo(skb)->nr_frags++;
skb->data_len += hlen;
skb->len += hlen;
frag++;
get_page(page->buffer);
frag->page = page->buffer;
frag->page_offset = 0;
frag->size = hlen;
RX_USED_ADD(page, hlen + cp->crc_size);
}
if (cp->crc_size) {
addr = cas_page_map(page->buffer);
crcaddr = addr + off + hlen;
}
} else {
if (!dlen)
goto end_copy_pkt;
i = CAS_VAL(RX_COMP1_DATA_INDEX, words[0]);
page = cp->rx_pages[CAS_VAL(RX_INDEX_RING, i)][CAS_VAL(RX_INDEX_NUM, i)];
off = CAS_VAL(RX_COMP1_DATA_OFF, words[0]) + swivel;
hlen = min(cp->page_size - off, dlen);
if (hlen < 0) {
netif_printk(cp, rx_err, KERN_DEBUG, cp->dev,
"rx page overflow: %d\n", hlen);
dev_kfree_skb_irq(skb);
return -1;
}
i = hlen;
if (i == dlen)
i += cp->crc_size;
pci_dma_sync_single_for_cpu(cp->pdev, page->dma_addr + off, i,
PCI_DMA_FROMDEVICE);
addr = cas_page_map(page->buffer);
memcpy(p, addr + off, i);
pci_dma_sync_single_for_device(cp->pdev, page->dma_addr + off, i,
PCI_DMA_FROMDEVICE);
cas_page_unmap(addr);
if (p == (char *) skb->data)
RX_USED_ADD(page, cp->mtu_stride);
else
RX_USED_ADD(page, i);
if ((words[0] & RX_COMP1_SPLIT_PKT) && ((dlen -= hlen) > 0)) {
p += hlen;
i = CAS_VAL(RX_COMP2_NEXT_INDEX, words[1]);
page = cp->rx_pages[CAS_VAL(RX_INDEX_RING, i)][CAS_VAL(RX_INDEX_NUM, i)];
pci_dma_sync_single_for_cpu(cp->pdev, page->dma_addr,
dlen + cp->crc_size,
PCI_DMA_FROMDEVICE);
addr = cas_page_map(page->buffer);
memcpy(p, addr, dlen + cp->crc_size);
pci_dma_sync_single_for_device(cp->pdev, page->dma_addr,
dlen + cp->crc_size,
PCI_DMA_FROMDEVICE);
cas_page_unmap(addr);
RX_USED_ADD(page, dlen + cp->crc_size);
}
end_copy_pkt:
if (cp->crc_size) {
addr = NULL;
crcaddr = skb->data + alloclen;
}
skb_put(skb, alloclen);
}
csum = (__force __sum16)htons(CAS_VAL(RX_COMP4_TCP_CSUM, words[3]));
if (cp->crc_size) {
csum = csum_fold(csum_partial(crcaddr, cp->crc_size,
csum_unfold(csum)));
if (addr)
cas_page_unmap(addr);
}
skb->protocol = eth_type_trans(skb, cp->dev);
if (skb->protocol == htons(ETH_P_IP)) {
skb->csum = csum_unfold(~csum);
skb->ip_summed = CHECKSUM_COMPLETE;
} else
skb_checksum_none_assert(skb);
return len;
}
static inline void cas_rx_flow_pkt(struct cas *cp, const u64 *words,
struct sk_buff *skb)
{
int flowid = CAS_VAL(RX_COMP3_FLOWID, words[2]) & (N_RX_FLOWS - 1);
struct sk_buff_head *flow = &cp->rx_flows[flowid];
__skb_queue_tail(flow, skb);
if (words[0] & RX_COMP1_RELEASE_FLOW) {
while ((skb = __skb_dequeue(flow))) {
cas_skb_release(skb);
}
}
}
static void cas_post_page(struct cas *cp, const int ring, const int index)
{
cas_page_t *new;
int entry;
entry = cp->rx_old[ring];
new = cas_page_swap(cp, ring, index);
cp->init_rxds[ring][entry].buffer = cpu_to_le64(new->dma_addr);
cp->init_rxds[ring][entry].index =
cpu_to_le64(CAS_BASE(RX_INDEX_NUM, index) |
CAS_BASE(RX_INDEX_RING, ring));
entry = RX_DESC_ENTRY(ring, entry + 1);
cp->rx_old[ring] = entry;
if (entry % 4)
return;
if (ring == 0)
writel(entry, cp->regs + REG_RX_KICK);
else if ((N_RX_DESC_RINGS > 1) &&
(cp->cas_flags & CAS_FLAG_REG_PLUS))
writel(entry, cp->regs + REG_PLUS_RX_KICK1);
}
static int cas_post_rxds_ringN(struct cas *cp, int ring, int num)
{
unsigned int entry, last, count, released;
int cluster;
cas_page_t **page = cp->rx_pages[ring];
entry = cp->rx_old[ring];
netif_printk(cp, intr, KERN_DEBUG, cp->dev,
"rxd[%d] interrupt, done: %d\n", ring, entry);
cluster = -1;
count = entry & 0x3;
last = RX_DESC_ENTRY(ring, num ? entry + num - 4: entry - 4);
released = 0;
while (entry != last) {
if (page_count(page[entry]->buffer) > 1) {
cas_page_t *new = cas_page_dequeue(cp);
if (!new) {
cp->cas_flags |= CAS_FLAG_RXD_POST(ring);
if (!timer_pending(&cp->link_timer))
mod_timer(&cp->link_timer, jiffies +
CAS_LINK_FAST_TIMEOUT);
cp->rx_old[ring] = entry;
cp->rx_last[ring] = num ? num - released : 0;
return -ENOMEM;
}
spin_lock(&cp->rx_inuse_lock);
list_add(&page[entry]->list, &cp->rx_inuse_list);
spin_unlock(&cp->rx_inuse_lock);
cp->init_rxds[ring][entry].buffer =
cpu_to_le64(new->dma_addr);
page[entry] = new;
}
if (++count == 4) {
cluster = entry;
count = 0;
}
released++;
entry = RX_DESC_ENTRY(ring, entry + 1);
}
cp->rx_old[ring] = entry;
if (cluster < 0)
return 0;
if (ring == 0)
writel(cluster, cp->regs + REG_RX_KICK);
else if ((N_RX_DESC_RINGS > 1) &&
(cp->cas_flags & CAS_FLAG_REG_PLUS))
writel(cluster, cp->regs + REG_PLUS_RX_KICK1);
return 0;
}
static int cas_rx_ringN(struct cas *cp, int ring, int budget)
{
struct cas_rx_comp *rxcs = cp->init_rxcs[ring];
int entry, drops;
int npackets = 0;
netif_printk(cp, intr, KERN_DEBUG, cp->dev,
"rx[%d] interrupt, done: %d/%d\n",
ring,
readl(cp->regs + REG_RX_COMP_HEAD), cp->rx_new[ring]);
entry = cp->rx_new[ring];
drops = 0;
while (1) {
struct cas_rx_comp *rxc = rxcs + entry;
struct sk_buff *uninitialized_var(skb);
int type, len;
u64 words[4];
int i, dring;
words[0] = le64_to_cpu(rxc->word1);
words[1] = le64_to_cpu(rxc->word2);
words[2] = le64_to_cpu(rxc->word3);
words[3] = le64_to_cpu(rxc->word4);
type = CAS_VAL(RX_COMP1_TYPE, words[0]);
if (type == 0)
break;
if (words[3] & RX_COMP4_ZERO) {
break;
}
if (words[3] & (RX_COMP4_LEN_MISMATCH | RX_COMP4_BAD)) {
spin_lock(&cp->stat_lock[ring]);
cp->net_stats[ring].rx_errors++;
if (words[3] & RX_COMP4_LEN_MISMATCH)
cp->net_stats[ring].rx_length_errors++;
if (words[3] & RX_COMP4_BAD)
cp->net_stats[ring].rx_crc_errors++;
spin_unlock(&cp->stat_lock[ring]);
drop_it:
spin_lock(&cp->stat_lock[ring]);
++cp->net_stats[ring].rx_dropped;
spin_unlock(&cp->stat_lock[ring]);
goto next;
}
len = cas_rx_process_pkt(cp, rxc, entry, words, &skb);
if (len < 0) {
++drops;
goto drop_it;
}
if (RX_DONT_BATCH || (type == 0x2)) {
cas_skb_release(skb);
} else {
cas_rx_flow_pkt(cp, words, skb);
}
spin_lock(&cp->stat_lock[ring]);
cp->net_stats[ring].rx_packets++;
cp->net_stats[ring].rx_bytes += len;
spin_unlock(&cp->stat_lock[ring]);
next:
npackets++;
if (words[0] & RX_COMP1_RELEASE_HDR) {
i = CAS_VAL(RX_COMP2_HDR_INDEX, words[1]);
dring = CAS_VAL(RX_INDEX_RING, i);
i = CAS_VAL(RX_INDEX_NUM, i);
cas_post_page(cp, dring, i);
}
if (words[0] & RX_COMP1_RELEASE_DATA) {
i = CAS_VAL(RX_COMP1_DATA_INDEX, words[0]);
dring = CAS_VAL(RX_INDEX_RING, i);
i = CAS_VAL(RX_INDEX_NUM, i);
cas_post_page(cp, dring, i);
}
if (words[0] & RX_COMP1_RELEASE_NEXT) {
i = CAS_VAL(RX_COMP2_NEXT_INDEX, words[1]);
dring = CAS_VAL(RX_INDEX_RING, i);
i = CAS_VAL(RX_INDEX_NUM, i);
cas_post_page(cp, dring, i);
}
entry = RX_COMP_ENTRY(ring, entry + 1 +
CAS_VAL(RX_COMP1_SKIP, words[0]));
#ifdef USE_NAPI
if (budget && (npackets >= budget))
break;
#endif
}
cp->rx_new[ring] = entry;
if (drops)
netdev_info(cp->dev, "Memory squeeze, deferring packet\n");
return npackets;
}
static void cas_post_rxcs_ringN(struct net_device *dev,
struct cas *cp, int ring)
{
struct cas_rx_comp *rxc = cp->init_rxcs[ring];
int last, entry;
last = cp->rx_cur[ring];
entry = cp->rx_new[ring];
netif_printk(cp, intr, KERN_DEBUG, dev,
"rxc[%d] interrupt, done: %d/%d\n",
ring, readl(cp->regs + REG_RX_COMP_HEAD), entry);
while (last != entry) {
cas_rxc_init(rxc + last);
last = RX_COMP_ENTRY(ring, last + 1);
}
cp->rx_cur[ring] = last;
if (ring == 0)
writel(last, cp->regs + REG_RX_COMP_TAIL);
else if (cp->cas_flags & CAS_FLAG_REG_PLUS)
writel(last, cp->regs + REG_PLUS_RX_COMPN_TAIL(ring));
}
static inline void cas_handle_irqN(struct net_device *dev,
struct cas *cp, const u32 status,
const int ring)
{
if (status & (INTR_RX_COMP_FULL_ALT | INTR_RX_COMP_AF_ALT))
cas_post_rxcs_ringN(dev, cp, ring);
}
static irqreturn_t cas_interruptN(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct cas *cp = netdev_priv(dev);
unsigned long flags;
int ring = (irq == cp->pci_irq_INTC) ? 2 : 3;
u32 status = readl(cp->regs + REG_PLUS_INTRN_STATUS(ring));
if (status == 0)
return IRQ_NONE;
spin_lock_irqsave(&cp->lock, flags);
if (status & INTR_RX_DONE_ALT) {
#ifdef USE_NAPI
cas_mask_intr(cp);
napi_schedule(&cp->napi);
#else
cas_rx_ringN(cp, ring, 0);
#endif
status &= ~INTR_RX_DONE_ALT;
}
if (status)
cas_handle_irqN(dev, cp, status, ring);
spin_unlock_irqrestore(&cp->lock, flags);
return IRQ_HANDLED;
}
static inline void cas_handle_irq1(struct cas *cp, const u32 status)
{
if (status & INTR_RX_BUF_UNAVAIL_1) {
cas_post_rxds_ringN(cp, 1, 0);
spin_lock(&cp->stat_lock[1]);
cp->net_stats[1].rx_dropped++;
spin_unlock(&cp->stat_lock[1]);
}
if (status & INTR_RX_BUF_AE_1)
cas_post_rxds_ringN(cp, 1, RX_DESC_RINGN_SIZE(1) -
RX_AE_FREEN_VAL(1));
if (status & (INTR_RX_COMP_AF | INTR_RX_COMP_FULL))
cas_post_rxcs_ringN(cp, 1);
}
static irqreturn_t cas_interrupt1(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct cas *cp = netdev_priv(dev);
unsigned long flags;
u32 status = readl(cp->regs + REG_PLUS_INTRN_STATUS(1));
if (status == 0)
return IRQ_NONE;
spin_lock_irqsave(&cp->lock, flags);
if (status & INTR_RX_DONE_ALT) {
#ifdef USE_NAPI
cas_mask_intr(cp);
napi_schedule(&cp->napi);
#else
cas_rx_ringN(cp, 1, 0);
#endif
status &= ~INTR_RX_DONE_ALT;
}
if (status)
cas_handle_irq1(cp, status);
spin_unlock_irqrestore(&cp->lock, flags);
return IRQ_HANDLED;
}
static inline void cas_handle_irq(struct net_device *dev,
struct cas *cp, const u32 status)
{
if (status & INTR_ERROR_MASK)
cas_abnormal_irq(dev, cp, status);
if (status & INTR_RX_BUF_UNAVAIL) {
cas_post_rxds_ringN(cp, 0, 0);
spin_lock(&cp->stat_lock[0]);
cp->net_stats[0].rx_dropped++;
spin_unlock(&cp->stat_lock[0]);
} else if (status & INTR_RX_BUF_AE) {
cas_post_rxds_ringN(cp, 0, RX_DESC_RINGN_SIZE(0) -
RX_AE_FREEN_VAL(0));
}
if (status & (INTR_RX_COMP_AF | INTR_RX_COMP_FULL))
cas_post_rxcs_ringN(dev, cp, 0);
}
static irqreturn_t cas_interrupt(int irq, void *dev_id)
{
struct net_device *dev = dev_id;
struct cas *cp = netdev_priv(dev);
unsigned long flags;
u32 status = readl(cp->regs + REG_INTR_STATUS);
if (status == 0)
return IRQ_NONE;
spin_lock_irqsave(&cp->lock, flags);
if (status & (INTR_TX_ALL | INTR_TX_INTME)) {
cas_tx(dev, cp, status);
status &= ~(INTR_TX_ALL | INTR_TX_INTME);
}
if (status & INTR_RX_DONE) {
#ifdef USE_NAPI
cas_mask_intr(cp);
napi_schedule(&cp->napi);
#else
cas_rx_ringN(cp, 0, 0);
#endif
status &= ~INTR_RX_DONE;
}
if (status)
cas_handle_irq(dev, cp, status);
spin_unlock_irqrestore(&cp->lock, flags);
return IRQ_HANDLED;
}
static int cas_poll(struct napi_struct *napi, int budget)
{
struct cas *cp = container_of(napi, struct cas, napi);
struct net_device *dev = cp->dev;
int i, enable_intr, credits;
u32 status = readl(cp->regs + REG_INTR_STATUS);
unsigned long flags;
spin_lock_irqsave(&cp->lock, flags);
cas_tx(dev, cp, status);
spin_unlock_irqrestore(&cp->lock, flags);
enable_intr = 1;
credits = 0;
for (i = 0; i < N_RX_COMP_RINGS; i++) {
int j;
for (j = 0; j < N_RX_COMP_RINGS; j++) {
credits += cas_rx_ringN(cp, j, budget / N_RX_COMP_RINGS);
if (credits >= budget) {
enable_intr = 0;
goto rx_comp;
}
}
}
rx_comp:
spin_lock_irqsave(&cp->lock, flags);
if (status)
cas_handle_irq(dev, cp, status);
#ifdef USE_PCI_INTB
if (N_RX_COMP_RINGS > 1) {
status = readl(cp->regs + REG_PLUS_INTRN_STATUS(1));
if (status)
cas_handle_irq1(dev, cp, status);
}
#endif
#ifdef USE_PCI_INTC
if (N_RX_COMP_RINGS > 2) {
status = readl(cp->regs + REG_PLUS_INTRN_STATUS(2));
if (status)
cas_handle_irqN(dev, cp, status, 2);
}
#endif
#ifdef USE_PCI_INTD
if (N_RX_COMP_RINGS > 3) {
status = readl(cp->regs + REG_PLUS_INTRN_STATUS(3));
if (status)
cas_handle_irqN(dev, cp, status, 3);
}
#endif
spin_unlock_irqrestore(&cp->lock, flags);
if (enable_intr) {
napi_complete(napi);
cas_unmask_intr(cp);
}
return credits;
}
static void cas_netpoll(struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
cas_disable_irq(cp, 0);
cas_interrupt(cp->pdev->irq, dev);
cas_enable_irq(cp, 0);
#ifdef USE_PCI_INTB
if (N_RX_COMP_RINGS > 1) {
}
#endif
#ifdef USE_PCI_INTC
if (N_RX_COMP_RINGS > 2) {
}
#endif
#ifdef USE_PCI_INTD
if (N_RX_COMP_RINGS > 3) {
}
#endif
}
static void cas_tx_timeout(struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
netdev_err(dev, "transmit timed out, resetting\n");
if (!cp->hw_running) {
netdev_err(dev, "hrm.. hw not running!\n");
return;
}
netdev_err(dev, "MIF_STATE[%08x]\n",
readl(cp->regs + REG_MIF_STATE_MACHINE));
netdev_err(dev, "MAC_STATE[%08x]\n",
readl(cp->regs + REG_MAC_STATE_MACHINE));
netdev_err(dev, "TX_STATE[%08x:%08x:%08x] FIFO[%08x:%08x:%08x] SM1[%08x] SM2[%08x]\n",
readl(cp->regs + REG_TX_CFG),
readl(cp->regs + REG_MAC_TX_STATUS),
readl(cp->regs + REG_MAC_TX_CFG),
readl(cp->regs + REG_TX_FIFO_PKT_CNT),
readl(cp->regs + REG_TX_FIFO_WRITE_PTR),
readl(cp->regs + REG_TX_FIFO_READ_PTR),
readl(cp->regs + REG_TX_SM_1),
readl(cp->regs + REG_TX_SM_2));
netdev_err(dev, "RX_STATE[%08x:%08x:%08x]\n",
readl(cp->regs + REG_RX_CFG),
readl(cp->regs + REG_MAC_RX_STATUS),
readl(cp->regs + REG_MAC_RX_CFG));
netdev_err(dev, "HP_STATE[%08x:%08x:%08x:%08x]\n",
readl(cp->regs + REG_HP_STATE_MACHINE),
readl(cp->regs + REG_HP_STATUS0),
readl(cp->regs + REG_HP_STATUS1),
readl(cp->regs + REG_HP_STATUS2));
#if 1
atomic_inc(&cp->reset_task_pending);
atomic_inc(&cp->reset_task_pending_all);
schedule_work(&cp->reset_task);
#else
atomic_set(&cp->reset_task_pending, CAS_RESET_ALL);
schedule_work(&cp->reset_task);
#endif
}
static inline int cas_intme(int ring, int entry)
{
if (!(entry & ((TX_DESC_RINGN_SIZE(ring) >> 1) - 1)))
return 1;
return 0;
}
static void cas_write_txd(struct cas *cp, int ring, int entry,
dma_addr_t mapping, int len, u64 ctrl, int last)
{
struct cas_tx_desc *txd = cp->init_txds[ring] + entry;
ctrl |= CAS_BASE(TX_DESC_BUFLEN, len);
if (cas_intme(ring, entry))
ctrl |= TX_DESC_INTME;
if (last)
ctrl |= TX_DESC_EOF;
txd->control = cpu_to_le64(ctrl);
txd->buffer = cpu_to_le64(mapping);
}
static inline void *tx_tiny_buf(struct cas *cp, const int ring,
const int entry)
{
return cp->tx_tiny_bufs[ring] + TX_TINY_BUF_LEN*entry;
}
static inline dma_addr_t tx_tiny_map(struct cas *cp, const int ring,
const int entry, const int tentry)
{
cp->tx_tiny_use[ring][tentry].nbufs++;
cp->tx_tiny_use[ring][entry].used = 1;
return cp->tx_tiny_dvma[ring] + TX_TINY_BUF_LEN*entry;
}
static inline int cas_xmit_tx_ringN(struct cas *cp, int ring,
struct sk_buff *skb)
{
struct net_device *dev = cp->dev;
int entry, nr_frags, frag, tabort, tentry;
dma_addr_t mapping;
unsigned long flags;
u64 ctrl;
u32 len;
spin_lock_irqsave(&cp->tx_lock[ring], flags);
if (TX_BUFFS_AVAIL(cp, ring) <=
CAS_TABORT(cp)*(skb_shinfo(skb)->nr_frags + 1)) {
netif_stop_queue(dev);
spin_unlock_irqrestore(&cp->tx_lock[ring], flags);
netdev_err(dev, "BUG! Tx Ring full when queue awake!\n");
return 1;
}
ctrl = 0;
if (skb->ip_summed == CHECKSUM_PARTIAL) {
const u64 csum_start_off = skb_checksum_start_offset(skb);
const u64 csum_stuff_off = csum_start_off + skb->csum_offset;
ctrl = TX_DESC_CSUM_EN |
CAS_BASE(TX_DESC_CSUM_START, csum_start_off) |
CAS_BASE(TX_DESC_CSUM_STUFF, csum_stuff_off);
}
entry = cp->tx_new[ring];
cp->tx_skbs[ring][entry] = skb;
nr_frags = skb_shinfo(skb)->nr_frags;
len = skb_headlen(skb);
mapping = pci_map_page(cp->pdev, virt_to_page(skb->data),
offset_in_page(skb->data), len,
PCI_DMA_TODEVICE);
tentry = entry;
tabort = cas_calc_tabort(cp, (unsigned long) skb->data, len);
if (unlikely(tabort)) {
cas_write_txd(cp, ring, entry, mapping, len - tabort,
ctrl | TX_DESC_SOF, 0);
entry = TX_DESC_NEXT(ring, entry);
skb_copy_from_linear_data_offset(skb, len - tabort,
tx_tiny_buf(cp, ring, entry), tabort);
mapping = tx_tiny_map(cp, ring, entry, tentry);
cas_write_txd(cp, ring, entry, mapping, tabort, ctrl,
(nr_frags == 0));
} else {
cas_write_txd(cp, ring, entry, mapping, len, ctrl |
TX_DESC_SOF, (nr_frags == 0));
}
entry = TX_DESC_NEXT(ring, entry);
for (frag = 0; frag < nr_frags; frag++) {
skb_frag_t *fragp = &skb_shinfo(skb)->frags[frag];
len = fragp->size;
mapping = pci_map_page(cp->pdev, fragp->page,
fragp->page_offset, len,
PCI_DMA_TODEVICE);
tabort = cas_calc_tabort(cp, fragp->page_offset, len);
if (unlikely(tabort)) {
void *addr;
cas_write_txd(cp, ring, entry, mapping, len - tabort,
ctrl, 0);
entry = TX_DESC_NEXT(ring, entry);
addr = cas_page_map(fragp->page);
memcpy(tx_tiny_buf(cp, ring, entry),
addr + fragp->page_offset + len - tabort,
tabort);
cas_page_unmap(addr);
mapping = tx_tiny_map(cp, ring, entry, tentry);
len = tabort;
}
cas_write_txd(cp, ring, entry, mapping, len, ctrl,
(frag + 1 == nr_frags));
entry = TX_DESC_NEXT(ring, entry);
}
cp->tx_new[ring] = entry;
if (TX_BUFFS_AVAIL(cp, ring) <= CAS_TABORT(cp)*(MAX_SKB_FRAGS + 1))
netif_stop_queue(dev);
netif_printk(cp, tx_queued, KERN_DEBUG, dev,
"tx[%d] queued, slot %d, skblen %d, avail %d\n",
ring, entry, skb->len, TX_BUFFS_AVAIL(cp, ring));
writel(entry, cp->regs + REG_TX_KICKN(ring));
spin_unlock_irqrestore(&cp->tx_lock[ring], flags);
return 0;
}
static netdev_tx_t cas_start_xmit(struct sk_buff *skb, struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
static int ring;
if (skb_padto(skb, cp->min_frame_size))
return NETDEV_TX_OK;
if (cas_xmit_tx_ringN(cp, ring++ & N_TX_RINGS_MASK, skb))
return NETDEV_TX_BUSY;
return NETDEV_TX_OK;
}
static void cas_init_tx_dma(struct cas *cp)
{
u64 desc_dma = cp->block_dvma;
unsigned long off;
u32 val;
int i;
#ifdef USE_TX_COMPWB
off = offsetof(struct cas_init_block, tx_compwb);
writel((desc_dma + off) >> 32, cp->regs + REG_TX_COMPWB_DB_HI);
writel((desc_dma + off) & 0xffffffff, cp->regs + REG_TX_COMPWB_DB_LOW);
#endif
val = TX_CFG_COMPWB_Q1 | TX_CFG_COMPWB_Q2 |
TX_CFG_COMPWB_Q3 | TX_CFG_COMPWB_Q4 |
TX_CFG_DMA_RDPIPE_DIS | TX_CFG_PACED_MODE |
TX_CFG_INTR_COMPWB_DIS;
for (i = 0; i < MAX_TX_RINGS; i++) {
off = (unsigned long) cp->init_txds[i] -
(unsigned long) cp->init_block;
val |= CAS_TX_RINGN_BASE(i);
writel((desc_dma + off) >> 32, cp->regs + REG_TX_DBN_HI(i));
writel((desc_dma + off) & 0xffffffff, cp->regs +
REG_TX_DBN_LOW(i));
}
writel(val, cp->regs + REG_TX_CFG);
#ifdef USE_QOS
writel(0x800, cp->regs + REG_TX_MAXBURST_0);
writel(0x1600, cp->regs + REG_TX_MAXBURST_1);
writel(0x2400, cp->regs + REG_TX_MAXBURST_2);
writel(0x4800, cp->regs + REG_TX_MAXBURST_3);
#else
writel(0x800, cp->regs + REG_TX_MAXBURST_0);
writel(0x800, cp->regs + REG_TX_MAXBURST_1);
writel(0x800, cp->regs + REG_TX_MAXBURST_2);
writel(0x800, cp->regs + REG_TX_MAXBURST_3);
#endif
}
static inline void cas_init_dma(struct cas *cp)
{
cas_init_tx_dma(cp);
cas_init_rx_dma(cp);
}
static void cas_process_mc_list(struct cas *cp)
{
u16 hash_table[16];
u32 crc;
struct netdev_hw_addr *ha;
int i = 1;
memset(hash_table, 0, sizeof(hash_table));
netdev_for_each_mc_addr(ha, cp->dev) {
if (i <= CAS_MC_EXACT_MATCH_SIZE) {
writel((ha->addr[4] << 8) | ha->addr[5],
cp->regs + REG_MAC_ADDRN(i*3 + 0));
writel((ha->addr[2] << 8) | ha->addr[3],
cp->regs + REG_MAC_ADDRN(i*3 + 1));
writel((ha->addr[0] << 8) | ha->addr[1],
cp->regs + REG_MAC_ADDRN(i*3 + 2));
i++;
}
else {
crc = ether_crc_le(ETH_ALEN, ha->addr);
crc >>= 24;
hash_table[crc >> 4] |= 1 << (15 - (crc & 0xf));
}
}
for (i = 0; i < 16; i++)
writel(hash_table[i], cp->regs + REG_MAC_HASH_TABLEN(i));
}
static u32 cas_setup_multicast(struct cas *cp)
{
u32 rxcfg = 0;
int i;
if (cp->dev->flags & IFF_PROMISC) {
rxcfg |= MAC_RX_CFG_PROMISC_EN;
} else if (cp->dev->flags & IFF_ALLMULTI) {
for (i=0; i < 16; i++)
writel(0xFFFF, cp->regs + REG_MAC_HASH_TABLEN(i));
rxcfg |= MAC_RX_CFG_HASH_FILTER_EN;
} else {
cas_process_mc_list(cp);
rxcfg |= MAC_RX_CFG_HASH_FILTER_EN;
}
return rxcfg;
}
static void cas_clear_mac_err(struct cas *cp)
{
writel(0, cp->regs + REG_MAC_COLL_NORMAL);
writel(0, cp->regs + REG_MAC_COLL_FIRST);
writel(0, cp->regs + REG_MAC_COLL_EXCESS);
writel(0, cp->regs + REG_MAC_COLL_LATE);
writel(0, cp->regs + REG_MAC_TIMER_DEFER);
writel(0, cp->regs + REG_MAC_ATTEMPTS_PEAK);
writel(0, cp->regs + REG_MAC_RECV_FRAME);
writel(0, cp->regs + REG_MAC_LEN_ERR);
writel(0, cp->regs + REG_MAC_ALIGN_ERR);
writel(0, cp->regs + REG_MAC_FCS_ERR);
writel(0, cp->regs + REG_MAC_RX_CODE_ERR);
}
static void cas_mac_reset(struct cas *cp)
{
int i;
writel(0x1, cp->regs + REG_MAC_TX_RESET);
writel(0x1, cp->regs + REG_MAC_RX_RESET);
i = STOP_TRIES;
while (i-- > 0) {
if (readl(cp->regs + REG_MAC_TX_RESET) == 0)
break;
udelay(10);
}
i = STOP_TRIES;
while (i-- > 0) {
if (readl(cp->regs + REG_MAC_RX_RESET) == 0)
break;
udelay(10);
}
if (readl(cp->regs + REG_MAC_TX_RESET) |
readl(cp->regs + REG_MAC_RX_RESET))
netdev_err(cp->dev, "mac tx[%d]/rx[%d] reset failed [%08x]\n",
readl(cp->regs + REG_MAC_TX_RESET),
readl(cp->regs + REG_MAC_RX_RESET),
readl(cp->regs + REG_MAC_STATE_MACHINE));
}
static void cas_init_mac(struct cas *cp)
{
unsigned char *e = &cp->dev->dev_addr[0];
int i;
cas_mac_reset(cp);
writel(CAWR_RR_DIS, cp->regs + REG_CAWR);
#if !defined(CONFIG_SPARC64) && !defined(CONFIG_ALPHA)
if ((cp->cas_flags & CAS_FLAG_TARGET_ABORT) == 0)
writel(INF_BURST_EN, cp->regs + REG_INF_BURST);
#endif
writel(0x1BF0, cp->regs + REG_MAC_SEND_PAUSE);
writel(0x00, cp->regs + REG_MAC_IPG0);
writel(0x08, cp->regs + REG_MAC_IPG1);
writel(0x04, cp->regs + REG_MAC_IPG2);
writel(0x40, cp->regs + REG_MAC_SLOT_TIME);
writel(ETH_ZLEN + 4, cp->regs + REG_MAC_FRAMESIZE_MIN);
writel(CAS_BASE(MAC_FRAMESIZE_MAX_BURST, 0x2000) |
CAS_BASE(MAC_FRAMESIZE_MAX_FRAME,
(CAS_MAX_MTU + ETH_HLEN + 4 + 4)),
cp->regs + REG_MAC_FRAMESIZE_MAX);
if ((cp->cas_flags & CAS_FLAG_SATURN) && cp->crc_size)
writel(0x41, cp->regs + REG_MAC_PA_SIZE);
else
writel(0x07, cp->regs + REG_MAC_PA_SIZE);
writel(0x04, cp->regs + REG_MAC_JAM_SIZE);
writel(0x10, cp->regs + REG_MAC_ATTEMPT_LIMIT);
writel(0x8808, cp->regs + REG_MAC_CTRL_TYPE);
writel((e[5] | (e[4] << 8)) & 0x3ff, cp->regs + REG_MAC_RANDOM_SEED);
writel(0, cp->regs + REG_MAC_ADDR_FILTER0);
writel(0, cp->regs + REG_MAC_ADDR_FILTER1);
writel(0, cp->regs + REG_MAC_ADDR_FILTER2);
writel(0, cp->regs + REG_MAC_ADDR_FILTER2_1_MASK);
writel(0, cp->regs + REG_MAC_ADDR_FILTER0_MASK);
for (i = 0; i < 45; i++)
writel(0x0, cp->regs + REG_MAC_ADDRN(i));
writel((e[4] << 8) | e[5], cp->regs + REG_MAC_ADDRN(0));
writel((e[2] << 8) | e[3], cp->regs + REG_MAC_ADDRN(1));
writel((e[0] << 8) | e[1], cp->regs + REG_MAC_ADDRN(2));
writel(0x0001, cp->regs + REG_MAC_ADDRN(42));
writel(0xc200, cp->regs + REG_MAC_ADDRN(43));
writel(0x0180, cp->regs + REG_MAC_ADDRN(44));
cp->mac_rx_cfg = cas_setup_multicast(cp);
spin_lock(&cp->stat_lock[N_TX_RINGS]);
cas_clear_mac_err(cp);
spin_unlock(&cp->stat_lock[N_TX_RINGS]);
writel(MAC_TX_FRAME_XMIT, cp->regs + REG_MAC_TX_MASK);
writel(MAC_RX_FRAME_RECV, cp->regs + REG_MAC_RX_MASK);
writel(0xffffffff, cp->regs + REG_MAC_CTRL_MASK);
}
static void cas_init_pause_thresholds(struct cas *cp)
{
if (cp->rx_fifo_size <= (2 * 1024)) {
cp->rx_pause_off = cp->rx_pause_on = cp->rx_fifo_size;
} else {
int max_frame = (cp->dev->mtu + ETH_HLEN + 4 + 4 + 64) & ~63;
if (max_frame * 3 > cp->rx_fifo_size) {
cp->rx_pause_off = 7104;
cp->rx_pause_on = 960;
} else {
int off = (cp->rx_fifo_size - (max_frame * 2));
int on = off - max_frame;
cp->rx_pause_off = off;
cp->rx_pause_on = on;
}
}
}
static int cas_vpd_match(const void __iomem *p, const char *str)
{
int len = strlen(str) + 1;
int i;
for (i = 0; i < len; i++) {
if (readb(p + i) != str[i])
return 0;
}
return 1;
}
static int cas_get_vpd_info(struct cas *cp, unsigned char *dev_addr,
const int offset)
{
void __iomem *p = cp->regs + REG_EXPANSION_ROM_RUN_START;
void __iomem *base, *kstart;
int i, len;
int found = 0;
#define VPD_FOUND_MAC 0x01
#define VPD_FOUND_PHY 0x02
int phy_type = CAS_PHY_MII_MDIO0;
int mac_off = 0;
#if defined(CONFIG_SPARC)
const unsigned char *addr;
#endif
writel(BIM_LOCAL_DEV_PROM | BIM_LOCAL_DEV_PAD,
cp->regs + REG_BIM_LOCAL_DEV_EN);
if (readb(p) != 0x55 || readb(p + 1) != 0xaa)
goto use_random_mac_addr;
base = NULL;
for (i = 2; i < EXPANSION_ROM_SIZE; i++) {
if ((readb(p + i + 0) == 0x50) &&
(readb(p + i + 1) == 0x43) &&
(readb(p + i + 2) == 0x49) &&
(readb(p + i + 3) == 0x52)) {
base = p + (readb(p + i + 8) |
(readb(p + i + 9) << 8));
break;
}
}
if (!base || (readb(base) != 0x82))
goto use_random_mac_addr;
i = (readb(base + 1) | (readb(base + 2) << 8)) + 3;
while (i < EXPANSION_ROM_SIZE) {
if (readb(base + i) != 0x90)
goto use_random_mac_addr;
len = readb(base + i + 1) | (readb(base + i + 2) << 8);
kstart = base + i + 3;
p = kstart;
while ((p - kstart) < len) {
int klen = readb(p + 2);
int j;
char type;
p += 3;
if (readb(p) != 'I')
goto next;
type = readb(p + 3);
if (type == 'B') {
if ((klen == 29) && readb(p + 4) == 6 &&
cas_vpd_match(p + 5,
"local-mac-address")) {
if (mac_off++ > offset)
goto next;
for (j = 0; j < 6; j++)
dev_addr[j] =
readb(p + 23 + j);
goto found_mac;
}
}
if (type != 'S')
goto next;
#ifdef USE_ENTROPY_DEV
if ((klen == 24) &&
cas_vpd_match(p + 5, "entropy-dev") &&
cas_vpd_match(p + 17, "vms110")) {
cp->cas_flags |= CAS_FLAG_ENTROPY_DEV;
goto next;
}
#endif
if (found & VPD_FOUND_PHY)
goto next;
if ((klen == 18) && readb(p + 4) == 4 &&
cas_vpd_match(p + 5, "phy-type")) {
if (cas_vpd_match(p + 14, "pcs")) {
phy_type = CAS_PHY_SERDES;
goto found_phy;
}
}
if ((klen == 23) && readb(p + 4) == 4 &&
cas_vpd_match(p + 5, "phy-interface")) {
if (cas_vpd_match(p + 19, "pcs")) {
phy_type = CAS_PHY_SERDES;
goto found_phy;
}
}
found_mac:
found |= VPD_FOUND_MAC;
goto next;
found_phy:
found |= VPD_FOUND_PHY;
next:
p += klen;
}
i += len + 3;
}
use_random_mac_addr:
if (found & VPD_FOUND_MAC)
goto done;
#if defined(CONFIG_SPARC)
addr = of_get_property(cp->of_node, "local-mac-address", NULL);
if (addr != NULL) {
memcpy(dev_addr, addr, 6);
goto done;
}
#endif
pr_info("MAC address not found in ROM VPD\n");
dev_addr[0] = 0x08;
dev_addr[1] = 0x00;
dev_addr[2] = 0x20;
get_random_bytes(dev_addr + 3, 3);
done:
writel(0, cp->regs + REG_BIM_LOCAL_DEV_EN);
return phy_type;
}
static void cas_check_pci_invariants(struct cas *cp)
{
struct pci_dev *pdev = cp->pdev;
cp->cas_flags = 0;
if ((pdev->vendor == PCI_VENDOR_ID_SUN) &&
(pdev->device == PCI_DEVICE_ID_SUN_CASSINI)) {
if (pdev->revision >= CAS_ID_REVPLUS)
cp->cas_flags |= CAS_FLAG_REG_PLUS;
if (pdev->revision < CAS_ID_REVPLUS02u)
cp->cas_flags |= CAS_FLAG_TARGET_ABORT;
if (pdev->revision < CAS_ID_REV2)
cp->cas_flags |= CAS_FLAG_NO_HW_CSUM;
} else {
cp->cas_flags |= CAS_FLAG_REG_PLUS;
if ((pdev->vendor == PCI_VENDOR_ID_NS) &&
(pdev->device == PCI_DEVICE_ID_NS_SATURN))
cp->cas_flags |= CAS_FLAG_SATURN;
}
}
static int cas_check_invariants(struct cas *cp)
{
struct pci_dev *pdev = cp->pdev;
u32 cfg;
int i;
cp->page_order = 0;
#ifdef USE_PAGE_ORDER
if (PAGE_SHIFT < CAS_JUMBO_PAGE_SHIFT) {
struct page *page = alloc_pages(GFP_ATOMIC,
CAS_JUMBO_PAGE_SHIFT -
PAGE_SHIFT);
if (page) {
__free_pages(page, CAS_JUMBO_PAGE_SHIFT - PAGE_SHIFT);
cp->page_order = CAS_JUMBO_PAGE_SHIFT - PAGE_SHIFT;
} else {
printk("MTU limited to %d bytes\n", CAS_MAX_MTU);
}
}
#endif
cp->page_size = (PAGE_SIZE << cp->page_order);
cp->tx_fifo_size = readl(cp->regs + REG_TX_FIFO_SIZE) * 64;
cp->rx_fifo_size = RX_FIFO_SIZE;
cp->phy_type = cas_get_vpd_info(cp, cp->dev->dev_addr,
PCI_SLOT(pdev->devfn));
if (cp->phy_type & CAS_PHY_SERDES) {
cp->cas_flags |= CAS_FLAG_1000MB_CAP;
return 0;
}
cfg = readl(cp->regs + REG_MIF_CFG);
if (cfg & MIF_CFG_MDIO_1) {
cp->phy_type = CAS_PHY_MII_MDIO1;
} else if (cfg & MIF_CFG_MDIO_0) {
cp->phy_type = CAS_PHY_MII_MDIO0;
}
cas_mif_poll(cp, 0);
writel(PCS_DATAPATH_MODE_MII, cp->regs + REG_PCS_DATAPATH_MODE);
for (i = 0; i < 32; i++) {
u32 phy_id;
int j;
for (j = 0; j < 3; j++) {
cp->phy_addr = i;
phy_id = cas_phy_read(cp, MII_PHYSID1) << 16;
phy_id |= cas_phy_read(cp, MII_PHYSID2);
if (phy_id && (phy_id != 0xFFFFFFFF)) {
cp->phy_id = phy_id;
goto done;
}
}
}
pr_err("MII phy did not respond [%08x]\n",
readl(cp->regs + REG_MIF_STATE_MACHINE));
return -1;
done:
cfg = cas_phy_read(cp, MII_BMSR);
if ((cfg & CAS_BMSR_1000_EXTEND) &&
cas_phy_read(cp, CAS_MII_1000_EXTEND))
cp->cas_flags |= CAS_FLAG_1000MB_CAP;
return 0;
}
static inline void cas_start_dma(struct cas *cp)
{
int i;
u32 val;
int txfailed = 0;
val = readl(cp->regs + REG_TX_CFG) | TX_CFG_DMA_EN;
writel(val, cp->regs + REG_TX_CFG);
val = readl(cp->regs + REG_RX_CFG) | RX_CFG_DMA_EN;
writel(val, cp->regs + REG_RX_CFG);
val = readl(cp->regs + REG_MAC_TX_CFG) | MAC_TX_CFG_EN;
writel(val, cp->regs + REG_MAC_TX_CFG);
val = readl(cp->regs + REG_MAC_RX_CFG) | MAC_RX_CFG_EN;
writel(val, cp->regs + REG_MAC_RX_CFG);
i = STOP_TRIES;
while (i-- > 0) {
val = readl(cp->regs + REG_MAC_TX_CFG);
if ((val & MAC_TX_CFG_EN))
break;
udelay(10);
}
if (i < 0) txfailed = 1;
i = STOP_TRIES;
while (i-- > 0) {
val = readl(cp->regs + REG_MAC_RX_CFG);
if ((val & MAC_RX_CFG_EN)) {
if (txfailed) {
netdev_err(cp->dev,
"enabling mac failed [tx:%08x:%08x]\n",
readl(cp->regs + REG_MIF_STATE_MACHINE),
readl(cp->regs + REG_MAC_STATE_MACHINE));
}
goto enable_rx_done;
}
udelay(10);
}
netdev_err(cp->dev, "enabling mac failed [%s:%08x:%08x]\n",
(txfailed ? "tx,rx" : "rx"),
readl(cp->regs + REG_MIF_STATE_MACHINE),
readl(cp->regs + REG_MAC_STATE_MACHINE));
enable_rx_done:
cas_unmask_intr(cp);
writel(RX_DESC_RINGN_SIZE(0) - 4, cp->regs + REG_RX_KICK);
writel(0, cp->regs + REG_RX_COMP_TAIL);
if (cp->cas_flags & CAS_FLAG_REG_PLUS) {
if (N_RX_DESC_RINGS > 1)
writel(RX_DESC_RINGN_SIZE(1) - 4,
cp->regs + REG_PLUS_RX_KICK1);
for (i = 1; i < N_RX_COMP_RINGS; i++)
writel(0, cp->regs + REG_PLUS_RX_COMPN_TAIL(i));
}
}
static void cas_read_pcs_link_mode(struct cas *cp, int *fd, int *spd,
int *pause)
{
u32 val = readl(cp->regs + REG_PCS_MII_LPA);
*fd = (val & PCS_MII_LPA_FD) ? 1 : 0;
*pause = (val & PCS_MII_LPA_SYM_PAUSE) ? 0x01 : 0x00;
if (val & PCS_MII_LPA_ASYM_PAUSE)
*pause |= 0x10;
*spd = 1000;
}
static void cas_read_mii_link_mode(struct cas *cp, int *fd, int *spd,
int *pause)
{
u32 val;
*fd = 0;
*spd = 10;
*pause = 0;
val = cas_phy_read(cp, MII_LPA);
if (val & CAS_LPA_PAUSE)
*pause = 0x01;
if (val & CAS_LPA_ASYM_PAUSE)
*pause |= 0x10;
if (val & LPA_DUPLEX)
*fd = 1;
if (val & LPA_100)
*spd = 100;
if (cp->cas_flags & CAS_FLAG_1000MB_CAP) {
val = cas_phy_read(cp, CAS_MII_1000_STATUS);
if (val & (CAS_LPA_1000FULL | CAS_LPA_1000HALF))
*spd = 1000;
if (val & CAS_LPA_1000FULL)
*fd = 1;
}
}
static void cas_set_link_modes(struct cas *cp)
{
u32 val;
int full_duplex, speed, pause;
full_duplex = 0;
speed = 10;
pause = 0;
if (CAS_PHY_MII(cp->phy_type)) {
cas_mif_poll(cp, 0);
val = cas_phy_read(cp, MII_BMCR);
if (val & BMCR_ANENABLE) {
cas_read_mii_link_mode(cp, &full_duplex, &speed,
&pause);
} else {
if (val & BMCR_FULLDPLX)
full_duplex = 1;
if (val & BMCR_SPEED100)
speed = 100;
else if (val & CAS_BMCR_SPEED1000)
speed = (cp->cas_flags & CAS_FLAG_1000MB_CAP) ?
1000 : 100;
}
cas_mif_poll(cp, 1);
} else {
val = readl(cp->regs + REG_PCS_MII_CTRL);
cas_read_pcs_link_mode(cp, &full_duplex, &speed, &pause);
if ((val & PCS_MII_AUTONEG_EN) == 0) {
if (val & PCS_MII_CTRL_DUPLEX)
full_duplex = 1;
}
}
netif_info(cp, link, cp->dev, "Link up at %d Mbps, %s-duplex\n",
speed, full_duplex ? "full" : "half");
val = MAC_XIF_TX_MII_OUTPUT_EN | MAC_XIF_LINK_LED;
if (CAS_PHY_MII(cp->phy_type)) {
val |= MAC_XIF_MII_BUFFER_OUTPUT_EN;
if (!full_duplex)
val |= MAC_XIF_DISABLE_ECHO;
}
if (full_duplex)
val |= MAC_XIF_FDPLX_LED;
if (speed == 1000)
val |= MAC_XIF_GMII_MODE;
writel(val, cp->regs + REG_MAC_XIF_CFG);
val = MAC_TX_CFG_IPG_EN;
if (full_duplex) {
val |= MAC_TX_CFG_IGNORE_CARRIER;
val |= MAC_TX_CFG_IGNORE_COLL;
} else {
#ifndef USE_CSMA_CD_PROTO
val |= MAC_TX_CFG_NEVER_GIVE_UP_EN;
val |= MAC_TX_CFG_NEVER_GIVE_UP_LIM;
#endif
}
if ((speed == 1000) && !full_duplex) {
writel(val | MAC_TX_CFG_CARRIER_EXTEND,
cp->regs + REG_MAC_TX_CFG);
val = readl(cp->regs + REG_MAC_RX_CFG);
val &= ~MAC_RX_CFG_STRIP_FCS;
writel(val | MAC_RX_CFG_CARRIER_EXTEND,
cp->regs + REG_MAC_RX_CFG);
writel(0x200, cp->regs + REG_MAC_SLOT_TIME);
cp->crc_size = 4;
cp->min_frame_size = CAS_1000MB_MIN_FRAME;
} else {
writel(val, cp->regs + REG_MAC_TX_CFG);
val = readl(cp->regs + REG_MAC_RX_CFG);
if (full_duplex) {
val |= MAC_RX_CFG_STRIP_FCS;
cp->crc_size = 0;
cp->min_frame_size = CAS_MIN_MTU;
} else {
val &= ~MAC_RX_CFG_STRIP_FCS;
cp->crc_size = 4;
cp->min_frame_size = CAS_MIN_FRAME;
}
writel(val & ~MAC_RX_CFG_CARRIER_EXTEND,
cp->regs + REG_MAC_RX_CFG);
writel(0x40, cp->regs + REG_MAC_SLOT_TIME);
}
if (netif_msg_link(cp)) {
if (pause & 0x01) {
netdev_info(cp->dev, "Pause is enabled (rxfifo: %d off: %d on: %d)\n",
cp->rx_fifo_size,
cp->rx_pause_off,
cp->rx_pause_on);
} else if (pause & 0x10) {
netdev_info(cp->dev, "TX pause enabled\n");
} else {
netdev_info(cp->dev, "Pause is disabled\n");
}
}
val = readl(cp->regs + REG_MAC_CTRL_CFG);
val &= ~(MAC_CTRL_CFG_SEND_PAUSE_EN | MAC_CTRL_CFG_RECV_PAUSE_EN);
if (pause) {
val |= MAC_CTRL_CFG_SEND_PAUSE_EN;
if (pause & 0x01) {
val |= MAC_CTRL_CFG_RECV_PAUSE_EN;
}
}
writel(val, cp->regs + REG_MAC_CTRL_CFG);
cas_start_dma(cp);
}
static void cas_init_hw(struct cas *cp, int restart_link)
{
if (restart_link)
cas_phy_init(cp);
cas_init_pause_thresholds(cp);
cas_init_mac(cp);
cas_init_dma(cp);
if (restart_link) {
cp->timer_ticks = 0;
cas_begin_auto_negotiation(cp, NULL);
} else if (cp->lstate == link_up) {
cas_set_link_modes(cp);
netif_carrier_on(cp->dev);
}
}
static void cas_hard_reset(struct cas *cp)
{
writel(BIM_LOCAL_DEV_SOFT_0, cp->regs + REG_BIM_LOCAL_DEV_EN);
udelay(20);
pci_restore_state(cp->pdev);
}
static void cas_global_reset(struct cas *cp, int blkflag)
{
int limit;
if (blkflag && !CAS_PHY_MII(cp->phy_type)) {
writel((SW_RESET_TX | SW_RESET_RX | SW_RESET_BLOCK_PCS_SLINK),
cp->regs + REG_SW_RESET);
} else {
writel(SW_RESET_TX | SW_RESET_RX, cp->regs + REG_SW_RESET);
}
mdelay(3);
limit = STOP_TRIES;
while (limit-- > 0) {
u32 val = readl(cp->regs + REG_SW_RESET);
if ((val & (SW_RESET_TX | SW_RESET_RX)) == 0)
goto done;
udelay(10);
}
netdev_err(cp->dev, "sw reset failed\n");
done:
writel(BIM_CFG_DPAR_INTR_ENABLE | BIM_CFG_RMA_INTR_ENABLE |
BIM_CFG_RTA_INTR_ENABLE, cp->regs + REG_BIM_CFG);
writel(0xFFFFFFFFU & ~(PCI_ERR_BADACK | PCI_ERR_DTRTO |
PCI_ERR_OTHER | PCI_ERR_BIM_DMA_WRITE |
PCI_ERR_BIM_DMA_READ), cp->regs +
REG_PCI_ERR_STATUS_MASK);
writel(PCS_DATAPATH_MODE_MII, cp->regs + REG_PCS_DATAPATH_MODE);
}
static void cas_reset(struct cas *cp, int blkflag)
{
u32 val;
cas_mask_intr(cp);
cas_global_reset(cp, blkflag);
cas_mac_reset(cp);
cas_entropy_reset(cp);
val = readl(cp->regs + REG_TX_CFG);
val &= ~TX_CFG_DMA_EN;
writel(val, cp->regs + REG_TX_CFG);
val = readl(cp->regs + REG_RX_CFG);
val &= ~RX_CFG_DMA_EN;
writel(val, cp->regs + REG_RX_CFG);
if ((cp->cas_flags & CAS_FLAG_TARGET_ABORT) ||
(CAS_HP_ALT_FIRMWARE == cas_prog_null)) {
cas_load_firmware(cp, CAS_HP_FIRMWARE);
} else {
cas_load_firmware(cp, CAS_HP_ALT_FIRMWARE);
}
spin_lock(&cp->stat_lock[N_TX_RINGS]);
cas_clear_mac_err(cp);
spin_unlock(&cp->stat_lock[N_TX_RINGS]);
}
static void cas_shutdown(struct cas *cp)
{
unsigned long flags;
cp->hw_running = 0;
del_timer_sync(&cp->link_timer);
#if 0
while (atomic_read(&cp->reset_task_pending_mtu) ||
atomic_read(&cp->reset_task_pending_spare) ||
atomic_read(&cp->reset_task_pending_all))
schedule();
#else
while (atomic_read(&cp->reset_task_pending))
schedule();
#endif
cas_lock_all_save(cp, flags);
cas_reset(cp, 0);
if (cp->cas_flags & CAS_FLAG_SATURN)
cas_phy_powerdown(cp);
cas_unlock_all_restore(cp, flags);
}
static int cas_change_mtu(struct net_device *dev, int new_mtu)
{
struct cas *cp = netdev_priv(dev);
if (new_mtu < CAS_MIN_MTU || new_mtu > CAS_MAX_MTU)
return -EINVAL;
dev->mtu = new_mtu;
if (!netif_running(dev) || !netif_device_present(dev))
return 0;
#if 1
atomic_inc(&cp->reset_task_pending);
if ((cp->phy_type & CAS_PHY_SERDES)) {
atomic_inc(&cp->reset_task_pending_all);
} else {
atomic_inc(&cp->reset_task_pending_mtu);
}
schedule_work(&cp->reset_task);
#else
atomic_set(&cp->reset_task_pending, (cp->phy_type & CAS_PHY_SERDES) ?
CAS_RESET_ALL : CAS_RESET_MTU);
pr_err("reset called in cas_change_mtu\n");
schedule_work(&cp->reset_task);
#endif
flush_work_sync(&cp->reset_task);
return 0;
}
static void cas_clean_txd(struct cas *cp, int ring)
{
struct cas_tx_desc *txd = cp->init_txds[ring];
struct sk_buff *skb, **skbs = cp->tx_skbs[ring];
u64 daddr, dlen;
int i, size;
size = TX_DESC_RINGN_SIZE(ring);
for (i = 0; i < size; i++) {
int frag;
if (skbs[i] == NULL)
continue;
skb = skbs[i];
skbs[i] = NULL;
for (frag = 0; frag <= skb_shinfo(skb)->nr_frags; frag++) {
int ent = i & (size - 1);
daddr = le64_to_cpu(txd[ent].buffer);
dlen = CAS_VAL(TX_DESC_BUFLEN,
le64_to_cpu(txd[ent].control));
pci_unmap_page(cp->pdev, daddr, dlen,
PCI_DMA_TODEVICE);
if (frag != skb_shinfo(skb)->nr_frags) {
i++;
ent = i & (size - 1);
if (cp->tx_tiny_use[ring][ent].used)
i++;
}
}
dev_kfree_skb_any(skb);
}
memset(cp->tx_tiny_use[ring], 0, size*sizeof(*cp->tx_tiny_use[ring]));
}
static inline void cas_free_rx_desc(struct cas *cp, int ring)
{
cas_page_t **page = cp->rx_pages[ring];
int i, size;
size = RX_DESC_RINGN_SIZE(ring);
for (i = 0; i < size; i++) {
if (page[i]) {
cas_page_free(cp, page[i]);
page[i] = NULL;
}
}
}
static void cas_free_rxds(struct cas *cp)
{
int i;
for (i = 0; i < N_RX_DESC_RINGS; i++)
cas_free_rx_desc(cp, i);
}
static void cas_clean_rings(struct cas *cp)
{
int i;
memset(cp->tx_old, 0, sizeof(*cp->tx_old)*N_TX_RINGS);
memset(cp->tx_new, 0, sizeof(*cp->tx_new)*N_TX_RINGS);
for (i = 0; i < N_TX_RINGS; i++)
cas_clean_txd(cp, i);
memset(cp->init_block, 0, sizeof(struct cas_init_block));
cas_clean_rxds(cp);
cas_clean_rxcs(cp);
}
static inline int cas_alloc_rx_desc(struct cas *cp, int ring)
{
cas_page_t **page = cp->rx_pages[ring];
int size, i = 0;
size = RX_DESC_RINGN_SIZE(ring);
for (i = 0; i < size; i++) {
if ((page[i] = cas_page_alloc(cp, GFP_KERNEL)) == NULL)
return -1;
}
return 0;
}
static int cas_alloc_rxds(struct cas *cp)
{
int i;
for (i = 0; i < N_RX_DESC_RINGS; i++) {
if (cas_alloc_rx_desc(cp, i) < 0) {
cas_free_rxds(cp);
return -1;
}
}
return 0;
}
static void cas_reset_task(struct work_struct *work)
{
struct cas *cp = container_of(work, struct cas, reset_task);
#if 0
int pending = atomic_read(&cp->reset_task_pending);
#else
int pending_all = atomic_read(&cp->reset_task_pending_all);
int pending_spare = atomic_read(&cp->reset_task_pending_spare);
int pending_mtu = atomic_read(&cp->reset_task_pending_mtu);
if (pending_all == 0 && pending_spare == 0 && pending_mtu == 0) {
atomic_dec(&cp->reset_task_pending);
return;
}
#endif
if (cp->hw_running) {
unsigned long flags;
netif_device_detach(cp->dev);
cas_lock_all_save(cp, flags);
if (cp->opened) {
cas_spare_recover(cp, GFP_ATOMIC);
}
#if 1
if (!pending_all && !pending_mtu)
goto done;
#else
if (pending == CAS_RESET_SPARE)
goto done;
#endif
#if 1
cas_reset(cp, !(pending_all > 0));
if (cp->opened)
cas_clean_rings(cp);
cas_init_hw(cp, (pending_all > 0));
#else
cas_reset(cp, !(pending == CAS_RESET_ALL));
if (cp->opened)
cas_clean_rings(cp);
cas_init_hw(cp, pending == CAS_RESET_ALL);
#endif
done:
cas_unlock_all_restore(cp, flags);
netif_device_attach(cp->dev);
}
#if 1
atomic_sub(pending_all, &cp->reset_task_pending_all);
atomic_sub(pending_spare, &cp->reset_task_pending_spare);
atomic_sub(pending_mtu, &cp->reset_task_pending_mtu);
atomic_dec(&cp->reset_task_pending);
#else
atomic_set(&cp->reset_task_pending, 0);
#endif
}
static void cas_link_timer(unsigned long data)
{
struct cas *cp = (struct cas *) data;
int mask, pending = 0, reset = 0;
unsigned long flags;
if (link_transition_timeout != 0 &&
cp->link_transition_jiffies_valid &&
((jiffies - cp->link_transition_jiffies) >
(link_transition_timeout))) {
cp->link_transition_jiffies_valid = 0;
}
if (!cp->hw_running)
return;
spin_lock_irqsave(&cp->lock, flags);
cas_lock_tx(cp);
cas_entropy_gather(cp);
#if 1
if (atomic_read(&cp->reset_task_pending_all) ||
atomic_read(&cp->reset_task_pending_spare) ||
atomic_read(&cp->reset_task_pending_mtu))
goto done;
#else
if (atomic_read(&cp->reset_task_pending))
goto done;
#endif
if ((mask = (cp->cas_flags & CAS_FLAG_RXD_POST_MASK))) {
int i, rmask;
for (i = 0; i < MAX_RX_DESC_RINGS; i++) {
rmask = CAS_FLAG_RXD_POST(i);
if ((mask & rmask) == 0)
continue;
if (cas_post_rxds_ringN(cp, i, cp->rx_last[i]) < 0) {
pending = 1;
continue;
}
cp->cas_flags &= ~rmask;
}
}
if (CAS_PHY_MII(cp->phy_type)) {
u16 bmsr;
cas_mif_poll(cp, 0);
bmsr = cas_phy_read(cp, MII_BMSR);
bmsr = cas_phy_read(cp, MII_BMSR);
cas_mif_poll(cp, 1);
readl(cp->regs + REG_MIF_STATUS);
reset = cas_mii_link_check(cp, bmsr);
} else {
reset = cas_pcs_link_check(cp);
}
if (reset)
goto done;
if ((readl(cp->regs + REG_MAC_TX_STATUS) & MAC_TX_FRAME_XMIT) == 0) {
u32 val = readl(cp->regs + REG_MAC_STATE_MACHINE);
u32 wptr, rptr;
int tlm = CAS_VAL(MAC_SM_TLM, val);
if (((tlm == 0x5) || (tlm == 0x3)) &&
(CAS_VAL(MAC_SM_ENCAP_SM, val) == 0)) {
netif_printk(cp, tx_err, KERN_DEBUG, cp->dev,
"tx err: MAC_STATE[%08x]\n", val);
reset = 1;
goto done;
}
val = readl(cp->regs + REG_TX_FIFO_PKT_CNT);
wptr = readl(cp->regs + REG_TX_FIFO_WRITE_PTR);
rptr = readl(cp->regs + REG_TX_FIFO_READ_PTR);
if ((val == 0) && (wptr != rptr)) {
netif_printk(cp, tx_err, KERN_DEBUG, cp->dev,
"tx err: TX_FIFO[%08x:%08x:%08x]\n",
val, wptr, rptr);
reset = 1;
}
if (reset)
cas_hard_reset(cp);
}
done:
if (reset) {
#if 1
atomic_inc(&cp->reset_task_pending);
atomic_inc(&cp->reset_task_pending_all);
schedule_work(&cp->reset_task);
#else
atomic_set(&cp->reset_task_pending, CAS_RESET_ALL);
pr_err("reset called in cas_link_timer\n");
schedule_work(&cp->reset_task);
#endif
}
if (!pending)
mod_timer(&cp->link_timer, jiffies + CAS_LINK_TIMEOUT);
cas_unlock_tx(cp);
spin_unlock_irqrestore(&cp->lock, flags);
}
static void cas_tx_tiny_free(struct cas *cp)
{
struct pci_dev *pdev = cp->pdev;
int i;
for (i = 0; i < N_TX_RINGS; i++) {
if (!cp->tx_tiny_bufs[i])
continue;
pci_free_consistent(pdev, TX_TINY_BUF_BLOCK,
cp->tx_tiny_bufs[i],
cp->tx_tiny_dvma[i]);
cp->tx_tiny_bufs[i] = NULL;
}
}
static int cas_tx_tiny_alloc(struct cas *cp)
{
struct pci_dev *pdev = cp->pdev;
int i;
for (i = 0; i < N_TX_RINGS; i++) {
cp->tx_tiny_bufs[i] =
pci_alloc_consistent(pdev, TX_TINY_BUF_BLOCK,
&cp->tx_tiny_dvma[i]);
if (!cp->tx_tiny_bufs[i]) {
cas_tx_tiny_free(cp);
return -1;
}
}
return 0;
}
static int cas_open(struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
int hw_was_up, err;
unsigned long flags;
mutex_lock(&cp->pm_mutex);
hw_was_up = cp->hw_running;
if (!cp->hw_running) {
cas_lock_all_save(cp, flags);
cas_reset(cp, 0);
cp->hw_running = 1;
cas_unlock_all_restore(cp, flags);
}
err = -ENOMEM;
if (cas_tx_tiny_alloc(cp) < 0)
goto err_unlock;
if (cas_alloc_rxds(cp) < 0)
goto err_tx_tiny;
cas_spare_init(cp);
cas_spare_recover(cp, GFP_KERNEL);
if (request_irq(cp->pdev->irq, cas_interrupt,
IRQF_SHARED, dev->name, (void *) dev)) {
netdev_err(cp->dev, "failed to request irq !\n");
err = -EAGAIN;
goto err_spare;
}
#ifdef USE_NAPI
napi_enable(&cp->napi);
#endif
cas_lock_all_save(cp, flags);
cas_clean_rings(cp);
cas_init_hw(cp, !hw_was_up);
cp->opened = 1;
cas_unlock_all_restore(cp, flags);
netif_start_queue(dev);
mutex_unlock(&cp->pm_mutex);
return 0;
err_spare:
cas_spare_free(cp);
cas_free_rxds(cp);
err_tx_tiny:
cas_tx_tiny_free(cp);
err_unlock:
mutex_unlock(&cp->pm_mutex);
return err;
}
static int cas_close(struct net_device *dev)
{
unsigned long flags;
struct cas *cp = netdev_priv(dev);
#ifdef USE_NAPI
napi_disable(&cp->napi);
#endif
mutex_lock(&cp->pm_mutex);
netif_stop_queue(dev);
cas_lock_all_save(cp, flags);
cp->opened = 0;
cas_reset(cp, 0);
cas_phy_init(cp);
cas_begin_auto_negotiation(cp, NULL);
cas_clean_rings(cp);
cas_unlock_all_restore(cp, flags);
free_irq(cp->pdev->irq, (void *) dev);
cas_spare_free(cp);
cas_free_rxds(cp);
cas_tx_tiny_free(cp);
mutex_unlock(&cp->pm_mutex);
return 0;
}
static void cas_read_regs(struct cas *cp, u8 *ptr, int len)
{
u8 *p;
int i;
unsigned long flags;
spin_lock_irqsave(&cp->lock, flags);
for (i = 0, p = ptr; i < len ; i ++, p += sizeof(u32)) {
u16 hval;
u32 val;
if (ethtool_register_table[i].offsets < 0) {
hval = cas_phy_read(cp,
-ethtool_register_table[i].offsets);
val = hval;
} else {
val= readl(cp->regs+ethtool_register_table[i].offsets);
}
memcpy(p, (u8 *)&val, sizeof(u32));
}
spin_unlock_irqrestore(&cp->lock, flags);
}
static struct net_device_stats *cas_get_stats(struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
struct net_device_stats *stats = cp->net_stats;
unsigned long flags;
int i;
unsigned long tmp;
if (!cp->hw_running)
return stats + N_TX_RINGS;
spin_lock_irqsave(&cp->stat_lock[N_TX_RINGS], flags);
stats[N_TX_RINGS].rx_crc_errors +=
readl(cp->regs + REG_MAC_FCS_ERR) & 0xffff;
stats[N_TX_RINGS].rx_frame_errors +=
readl(cp->regs + REG_MAC_ALIGN_ERR) &0xffff;
stats[N_TX_RINGS].rx_length_errors +=
readl(cp->regs + REG_MAC_LEN_ERR) & 0xffff;
#if 1
tmp = (readl(cp->regs + REG_MAC_COLL_EXCESS) & 0xffff) +
(readl(cp->regs + REG_MAC_COLL_LATE) & 0xffff);
stats[N_TX_RINGS].tx_aborted_errors += tmp;
stats[N_TX_RINGS].collisions +=
tmp + (readl(cp->regs + REG_MAC_COLL_NORMAL) & 0xffff);
#else
stats[N_TX_RINGS].tx_aborted_errors +=
readl(cp->regs + REG_MAC_COLL_EXCESS);
stats[N_TX_RINGS].collisions += readl(cp->regs + REG_MAC_COLL_EXCESS) +
readl(cp->regs + REG_MAC_COLL_LATE);
#endif
cas_clear_mac_err(cp);
spin_lock(&cp->stat_lock[0]);
stats[N_TX_RINGS].collisions += stats[0].collisions;
stats[N_TX_RINGS].rx_over_errors += stats[0].rx_over_errors;
stats[N_TX_RINGS].rx_frame_errors += stats[0].rx_frame_errors;
stats[N_TX_RINGS].rx_fifo_errors += stats[0].rx_fifo_errors;
stats[N_TX_RINGS].tx_aborted_errors += stats[0].tx_aborted_errors;
stats[N_TX_RINGS].tx_fifo_errors += stats[0].tx_fifo_errors;
spin_unlock(&cp->stat_lock[0]);
for (i = 0; i < N_TX_RINGS; i++) {
spin_lock(&cp->stat_lock[i]);
stats[N_TX_RINGS].rx_length_errors +=
stats[i].rx_length_errors;
stats[N_TX_RINGS].rx_crc_errors += stats[i].rx_crc_errors;
stats[N_TX_RINGS].rx_packets += stats[i].rx_packets;
stats[N_TX_RINGS].tx_packets += stats[i].tx_packets;
stats[N_TX_RINGS].rx_bytes += stats[i].rx_bytes;
stats[N_TX_RINGS].tx_bytes += stats[i].tx_bytes;
stats[N_TX_RINGS].rx_errors += stats[i].rx_errors;
stats[N_TX_RINGS].tx_errors += stats[i].tx_errors;
stats[N_TX_RINGS].rx_dropped += stats[i].rx_dropped;
stats[N_TX_RINGS].tx_dropped += stats[i].tx_dropped;
memset(stats + i, 0, sizeof(struct net_device_stats));
spin_unlock(&cp->stat_lock[i]);
}
spin_unlock_irqrestore(&cp->stat_lock[N_TX_RINGS], flags);
return stats + N_TX_RINGS;
}
static void cas_set_multicast(struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
u32 rxcfg, rxcfg_new;
unsigned long flags;
int limit = STOP_TRIES;
if (!cp->hw_running)
return;
spin_lock_irqsave(&cp->lock, flags);
rxcfg = readl(cp->regs + REG_MAC_RX_CFG);
writel(rxcfg & ~MAC_RX_CFG_EN, cp->regs + REG_MAC_RX_CFG);
while (readl(cp->regs + REG_MAC_RX_CFG) & MAC_RX_CFG_EN) {
if (!limit--)
break;
udelay(10);
}
limit = STOP_TRIES;
rxcfg &= ~(MAC_RX_CFG_PROMISC_EN | MAC_RX_CFG_HASH_FILTER_EN);
writel(rxcfg & ~MAC_RX_CFG_EN, cp->regs + REG_MAC_RX_CFG);
while (readl(cp->regs + REG_MAC_RX_CFG) & MAC_RX_CFG_HASH_FILTER_EN) {
if (!limit--)
break;
udelay(10);
}
cp->mac_rx_cfg = rxcfg_new = cas_setup_multicast(cp);
rxcfg |= rxcfg_new;
writel(rxcfg, cp->regs + REG_MAC_RX_CFG);
spin_unlock_irqrestore(&cp->lock, flags);
}
static void cas_get_drvinfo(struct net_device *dev, struct ethtool_drvinfo *info)
{
struct cas *cp = netdev_priv(dev);
strncpy(info->driver, DRV_MODULE_NAME, ETHTOOL_BUSINFO_LEN);
strncpy(info->version, DRV_MODULE_VERSION, ETHTOOL_BUSINFO_LEN);
info->fw_version[0] = '\0';
strncpy(info->bus_info, pci_name(cp->pdev), ETHTOOL_BUSINFO_LEN);
info->regdump_len = cp->casreg_len < CAS_MAX_REGS ?
cp->casreg_len : CAS_MAX_REGS;
info->n_stats = CAS_NUM_STAT_KEYS;
}
static int cas_get_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct cas *cp = netdev_priv(dev);
u16 bmcr;
int full_duplex, speed, pause;
unsigned long flags;
enum link_state linkstate = link_up;
cmd->advertising = 0;
cmd->supported = SUPPORTED_Autoneg;
if (cp->cas_flags & CAS_FLAG_1000MB_CAP) {
cmd->supported |= SUPPORTED_1000baseT_Full;
cmd->advertising |= ADVERTISED_1000baseT_Full;
}
spin_lock_irqsave(&cp->lock, flags);
bmcr = 0;
linkstate = cp->lstate;
if (CAS_PHY_MII(cp->phy_type)) {
cmd->port = PORT_MII;
cmd->transceiver = (cp->cas_flags & CAS_FLAG_SATURN) ?
XCVR_INTERNAL : XCVR_EXTERNAL;
cmd->phy_address = cp->phy_addr;
cmd->advertising |= ADVERTISED_TP | ADVERTISED_MII |
ADVERTISED_10baseT_Half |
ADVERTISED_10baseT_Full |
ADVERTISED_100baseT_Half |
ADVERTISED_100baseT_Full;
cmd->supported |=
(SUPPORTED_10baseT_Half |
SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half |
SUPPORTED_100baseT_Full |
SUPPORTED_TP | SUPPORTED_MII);
if (cp->hw_running) {
cas_mif_poll(cp, 0);
bmcr = cas_phy_read(cp, MII_BMCR);
cas_read_mii_link_mode(cp, &full_duplex,
&speed, &pause);
cas_mif_poll(cp, 1);
}
} else {
cmd->port = PORT_FIBRE;
cmd->transceiver = XCVR_INTERNAL;
cmd->phy_address = 0;
cmd->supported |= SUPPORTED_FIBRE;
cmd->advertising |= ADVERTISED_FIBRE;
if (cp->hw_running) {
bmcr = readl(cp->regs + REG_PCS_MII_CTRL);
cas_read_pcs_link_mode(cp, &full_duplex,
&speed, &pause);
}
}
spin_unlock_irqrestore(&cp->lock, flags);
if (bmcr & BMCR_ANENABLE) {
cmd->advertising |= ADVERTISED_Autoneg;
cmd->autoneg = AUTONEG_ENABLE;
ethtool_cmd_speed_set(cmd, ((speed == 10) ?
SPEED_10 :
((speed == 1000) ?
SPEED_1000 : SPEED_100)));
cmd->duplex = full_duplex ? DUPLEX_FULL : DUPLEX_HALF;
} else {
cmd->autoneg = AUTONEG_DISABLE;
ethtool_cmd_speed_set(cmd, ((bmcr & CAS_BMCR_SPEED1000) ?
SPEED_1000 :
((bmcr & BMCR_SPEED100) ?
SPEED_100 : SPEED_10)));
cmd->duplex =
(bmcr & BMCR_FULLDPLX) ?
DUPLEX_FULL : DUPLEX_HALF;
}
if (linkstate != link_up) {
if (cp->link_cntl & BMCR_ANENABLE) {
ethtool_cmd_speed_set(cmd, 0);
cmd->duplex = 0xff;
} else {
ethtool_cmd_speed_set(cmd, SPEED_10);
if (cp->link_cntl & BMCR_SPEED100) {
ethtool_cmd_speed_set(cmd, SPEED_100);
} else if (cp->link_cntl & CAS_BMCR_SPEED1000) {
ethtool_cmd_speed_set(cmd, SPEED_1000);
}
cmd->duplex = (cp->link_cntl & BMCR_FULLDPLX)?
DUPLEX_FULL : DUPLEX_HALF;
}
}
return 0;
}
static int cas_set_settings(struct net_device *dev, struct ethtool_cmd *cmd)
{
struct cas *cp = netdev_priv(dev);
unsigned long flags;
u32 speed = ethtool_cmd_speed(cmd);
if (cmd->autoneg != AUTONEG_ENABLE &&
cmd->autoneg != AUTONEG_DISABLE)
return -EINVAL;
if (cmd->autoneg == AUTONEG_DISABLE &&
((speed != SPEED_1000 &&
speed != SPEED_100 &&
speed != SPEED_10) ||
(cmd->duplex != DUPLEX_HALF &&
cmd->duplex != DUPLEX_FULL)))
return -EINVAL;
spin_lock_irqsave(&cp->lock, flags);
cas_begin_auto_negotiation(cp, cmd);
spin_unlock_irqrestore(&cp->lock, flags);
return 0;
}
static int cas_nway_reset(struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
unsigned long flags;
if ((cp->link_cntl & BMCR_ANENABLE) == 0)
return -EINVAL;
spin_lock_irqsave(&cp->lock, flags);
cas_begin_auto_negotiation(cp, NULL);
spin_unlock_irqrestore(&cp->lock, flags);
return 0;
}
static u32 cas_get_link(struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
return cp->lstate == link_up;
}
static u32 cas_get_msglevel(struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
return cp->msg_enable;
}
static void cas_set_msglevel(struct net_device *dev, u32 value)
{
struct cas *cp = netdev_priv(dev);
cp->msg_enable = value;
}
static int cas_get_regs_len(struct net_device *dev)
{
struct cas *cp = netdev_priv(dev);
return cp->casreg_len < CAS_MAX_REGS ? cp->casreg_len: CAS_MAX_REGS;
}
static void cas_get_regs(struct net_device *dev, struct ethtool_regs *regs,
void *p)
{
struct cas *cp = netdev_priv(dev);
regs->version = 0;
cas_read_regs(cp, p, regs->len / sizeof(u32));
}
static int cas_get_sset_count(struct net_device *dev, int sset)
{
switch (sset) {
case ETH_SS_STATS:
return CAS_NUM_STAT_KEYS;
default:
return -EOPNOTSUPP;
}
}
static void cas_get_strings(struct net_device *dev, u32 stringset, u8 *data)
{
memcpy(data, &ethtool_cassini_statnames,
CAS_NUM_STAT_KEYS * ETH_GSTRING_LEN);
}
static void cas_get_ethtool_stats(struct net_device *dev,
struct ethtool_stats *estats, u64 *data)
{
struct cas *cp = netdev_priv(dev);
struct net_device_stats *stats = cas_get_stats(cp->dev);
int i = 0;
data[i++] = stats->collisions;
data[i++] = stats->rx_bytes;
data[i++] = stats->rx_crc_errors;
data[i++] = stats->rx_dropped;
data[i++] = stats->rx_errors;
data[i++] = stats->rx_fifo_errors;
data[i++] = stats->rx_frame_errors;
data[i++] = stats->rx_length_errors;
data[i++] = stats->rx_over_errors;
data[i++] = stats->rx_packets;
data[i++] = stats->tx_aborted_errors;
data[i++] = stats->tx_bytes;
data[i++] = stats->tx_dropped;
data[i++] = stats->tx_errors;
data[i++] = stats->tx_fifo_errors;
data[i++] = stats->tx_packets;
BUG_ON(i != CAS_NUM_STAT_KEYS);
}
static int cas_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd)
{
struct cas *cp = netdev_priv(dev);
struct mii_ioctl_data *data = if_mii(ifr);
unsigned long flags;
int rc = -EOPNOTSUPP;
mutex_lock(&cp->pm_mutex);
switch (cmd) {
case SIOCGMIIPHY:
data->phy_id = cp->phy_addr;
case SIOCGMIIREG:
spin_lock_irqsave(&cp->lock, flags);
cas_mif_poll(cp, 0);
data->val_out = cas_phy_read(cp, data->reg_num & 0x1f);
cas_mif_poll(cp, 1);
spin_unlock_irqrestore(&cp->lock, flags);
rc = 0;
break;
case SIOCSMIIREG:
spin_lock_irqsave(&cp->lock, flags);
cas_mif_poll(cp, 0);
rc = cas_phy_write(cp, data->reg_num & 0x1f, data->val_in);
cas_mif_poll(cp, 1);
spin_unlock_irqrestore(&cp->lock, flags);
break;
default:
break;
}
mutex_unlock(&cp->pm_mutex);
return rc;
}
static void __devinit cas_program_bridge(struct pci_dev *cas_pdev)
{
struct pci_dev *pdev = cas_pdev->bus->self;
u32 val;
if (!pdev)
return;
if (pdev->vendor != 0x8086 || pdev->device != 0x537c)
return;
pci_read_config_dword(pdev, 0x40, &val);
val &= ~0x00040000;
pci_write_config_dword(pdev, 0x40, val);
pci_write_config_word(pdev, 0x50, (5 << 10) | 0x3ff);
pci_write_config_word(pdev, 0x52,
(0x7 << 13) |
(0x7 << 10) |
(0x7 << 7) |
(0x7 << 4) |
(0xf << 0));
pci_write_config_byte(pdev, PCI_CACHE_LINE_SIZE, 0x08);
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0xff);
}
static int __devinit cas_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
static int cas_version_printed = 0;
unsigned long casreg_len;
struct net_device *dev;
struct cas *cp;
int i, err, pci_using_dac;
u16 pci_cmd;
u8 orig_cacheline_size = 0, cas_cacheline_size = 0;
if (cas_version_printed++ == 0)
pr_info("%s", version);
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "Cannot enable PCI device, aborting\n");
return err;
}
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM)) {
dev_err(&pdev->dev, "Cannot find proper PCI device "
"base address, aborting\n");
err = -ENODEV;
goto err_out_disable_pdev;
}
dev = alloc_etherdev(sizeof(*cp));
if (!dev) {
dev_err(&pdev->dev, "Etherdev alloc failed, aborting\n");
err = -ENOMEM;
goto err_out_disable_pdev;
}
SET_NETDEV_DEV(dev, &pdev->dev);
err = pci_request_regions(pdev, dev->name);
if (err) {
dev_err(&pdev->dev, "Cannot obtain PCI resources, aborting\n");
goto err_out_free_netdev;
}
pci_set_master(pdev);
pci_read_config_word(pdev, PCI_COMMAND, &pci_cmd);
pci_cmd &= ~PCI_COMMAND_SERR;
pci_cmd |= PCI_COMMAND_PARITY;
pci_write_config_word(pdev, PCI_COMMAND, pci_cmd);
if (pci_try_set_mwi(pdev))
pr_warning("Could not enable MWI for %s\n", pci_name(pdev));
cas_program_bridge(pdev);
#if 1
pci_read_config_byte(pdev, PCI_CACHE_LINE_SIZE,
&orig_cacheline_size);
if (orig_cacheline_size < CAS_PREF_CACHELINE_SIZE) {
cas_cacheline_size =
(CAS_PREF_CACHELINE_SIZE < SMP_CACHE_BYTES) ?
CAS_PREF_CACHELINE_SIZE : SMP_CACHE_BYTES;
if (pci_write_config_byte(pdev,
PCI_CACHE_LINE_SIZE,
cas_cacheline_size)) {
dev_err(&pdev->dev, "Could not set PCI cache "
"line size\n");
goto err_write_cacheline;
}
}
#endif
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
pci_using_dac = 1;
err = pci_set_consistent_dma_mask(pdev,
DMA_BIT_MASK(64));
if (err < 0) {
dev_err(&pdev->dev, "Unable to obtain 64-bit DMA "
"for consistent allocations\n");
goto err_out_free_res;
}
} else {
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "No usable DMA configuration, "
"aborting\n");
goto err_out_free_res;
}
pci_using_dac = 0;
}
casreg_len = pci_resource_len(pdev, 0);
cp = netdev_priv(dev);
cp->pdev = pdev;
#if 1
cp->orig_cacheline_size = cas_cacheline_size ? orig_cacheline_size: 0;
#endif
cp->dev = dev;
cp->msg_enable = (cassini_debug < 0) ? CAS_DEF_MSG_ENABLE :
cassini_debug;
#if defined(CONFIG_SPARC)
cp->of_node = pci_device_to_OF_node(pdev);
#endif
cp->link_transition = LINK_TRANSITION_UNKNOWN;
cp->link_transition_jiffies_valid = 0;
spin_lock_init(&cp->lock);
spin_lock_init(&cp->rx_inuse_lock);
spin_lock_init(&cp->rx_spare_lock);
for (i = 0; i < N_TX_RINGS; i++) {
spin_lock_init(&cp->stat_lock[i]);
spin_lock_init(&cp->tx_lock[i]);
}
spin_lock_init(&cp->stat_lock[N_TX_RINGS]);
mutex_init(&cp->pm_mutex);
init_timer(&cp->link_timer);
cp->link_timer.function = cas_link_timer;
cp->link_timer.data = (unsigned long) cp;
#if 1
atomic_set(&cp->reset_task_pending, 0);
atomic_set(&cp->reset_task_pending_all, 0);
atomic_set(&cp->reset_task_pending_spare, 0);
atomic_set(&cp->reset_task_pending_mtu, 0);
#endif
INIT_WORK(&cp->reset_task, cas_reset_task);
if (link_mode >= 0 && link_mode < 6)
cp->link_cntl = link_modes[link_mode];
else
cp->link_cntl = BMCR_ANENABLE;
cp->lstate = link_down;
cp->link_transition = LINK_TRANSITION_LINK_DOWN;
netif_carrier_off(cp->dev);
cp->timer_ticks = 0;
cp->regs = pci_iomap(pdev, 0, casreg_len);
if (!cp->regs) {
dev_err(&pdev->dev, "Cannot map device registers, aborting\n");
goto err_out_free_res;
}
cp->casreg_len = casreg_len;
pci_save_state(pdev);
cas_check_pci_invariants(cp);
cas_hard_reset(cp);
cas_reset(cp, 0);
if (cas_check_invariants(cp))
goto err_out_iounmap;
if (cp->cas_flags & CAS_FLAG_SATURN)
if (cas_saturn_firmware_init(cp))
goto err_out_iounmap;
cp->init_block = (struct cas_init_block *)
pci_alloc_consistent(pdev, sizeof(struct cas_init_block),
&cp->block_dvma);
if (!cp->init_block) {
dev_err(&pdev->dev, "Cannot allocate init block, aborting\n");
goto err_out_iounmap;
}
for (i = 0; i < N_TX_RINGS; i++)
cp->init_txds[i] = cp->init_block->txds[i];
for (i = 0; i < N_RX_DESC_RINGS; i++)
cp->init_rxds[i] = cp->init_block->rxds[i];
for (i = 0; i < N_RX_COMP_RINGS; i++)
cp->init_rxcs[i] = cp->init_block->rxcs[i];
for (i = 0; i < N_RX_FLOWS; i++)
skb_queue_head_init(&cp->rx_flows[i]);
dev->netdev_ops = &cas_netdev_ops;
dev->ethtool_ops = &cas_ethtool_ops;
dev->watchdog_timeo = CAS_TX_TIMEOUT;
#ifdef USE_NAPI
netif_napi_add(dev, &cp->napi, cas_poll, 64);
#endif
dev->irq = pdev->irq;
dev->dma = 0;
if ((cp->cas_flags & CAS_FLAG_NO_HW_CSUM) == 0)
dev->features |= NETIF_F_HW_CSUM | NETIF_F_SG;
if (pci_using_dac)
dev->features |= NETIF_F_HIGHDMA;
if (register_netdev(dev)) {
dev_err(&pdev->dev, "Cannot register net device, aborting\n");
goto err_out_free_consistent;
}
i = readl(cp->regs + REG_BIM_CFG);
netdev_info(dev, "Sun Cassini%s (%sbit/%sMHz PCI/%s) Ethernet[%d] %pM\n",
(cp->cas_flags & CAS_FLAG_REG_PLUS) ? "+" : "",
(i & BIM_CFG_32BIT) ? "32" : "64",
(i & BIM_CFG_66MHZ) ? "66" : "33",
(cp->phy_type == CAS_PHY_SERDES) ? "Fi" : "Cu", pdev->irq,
dev->dev_addr);
pci_set_drvdata(pdev, dev);
cp->hw_running = 1;
cas_entropy_reset(cp);
cas_phy_init(cp);
cas_begin_auto_negotiation(cp, NULL);
return 0;
err_out_free_consistent:
pci_free_consistent(pdev, sizeof(struct cas_init_block),
cp->init_block, cp->block_dvma);
err_out_iounmap:
mutex_lock(&cp->pm_mutex);
if (cp->hw_running)
cas_shutdown(cp);
mutex_unlock(&cp->pm_mutex);
pci_iounmap(pdev, cp->regs);
err_out_free_res:
pci_release_regions(pdev);
err_write_cacheline:
pci_write_config_byte(pdev, PCI_CACHE_LINE_SIZE, orig_cacheline_size);
err_out_free_netdev:
free_netdev(dev);
err_out_disable_pdev:
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
return -ENODEV;
}
static void __devexit cas_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct cas *cp;
if (!dev)
return;
cp = netdev_priv(dev);
unregister_netdev(dev);
if (cp->fw_data)
vfree(cp->fw_data);
mutex_lock(&cp->pm_mutex);
cancel_work_sync(&cp->reset_task);
if (cp->hw_running)
cas_shutdown(cp);
mutex_unlock(&cp->pm_mutex);
#if 1
if (cp->orig_cacheline_size) {
pci_write_config_byte(pdev, PCI_CACHE_LINE_SIZE,
cp->orig_cacheline_size);
}
#endif
pci_free_consistent(pdev, sizeof(struct cas_init_block),
cp->init_block, cp->block_dvma);
pci_iounmap(pdev, cp->regs);
free_netdev(dev);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static int cas_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct cas *cp = netdev_priv(dev);
unsigned long flags;
mutex_lock(&cp->pm_mutex);
if (cp->opened) {
netif_device_detach(dev);
cas_lock_all_save(cp, flags);
cas_reset(cp, 0);
cas_clean_rings(cp);
cas_unlock_all_restore(cp, flags);
}
if (cp->hw_running)
cas_shutdown(cp);
mutex_unlock(&cp->pm_mutex);
return 0;
}
static int cas_resume(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct cas *cp = netdev_priv(dev);
netdev_info(dev, "resuming\n");
mutex_lock(&cp->pm_mutex);
cas_hard_reset(cp);
if (cp->opened) {
unsigned long flags;
cas_lock_all_save(cp, flags);
cas_reset(cp, 0);
cp->hw_running = 1;
cas_clean_rings(cp);
cas_init_hw(cp, 1);
cas_unlock_all_restore(cp, flags);
netif_device_attach(dev);
}
mutex_unlock(&cp->pm_mutex);
return 0;
}
static int __init cas_init(void)
{
if (linkdown_timeout > 0)
link_transition_timeout = linkdown_timeout * HZ;
else
link_transition_timeout = 0;
return pci_register_driver(&cas_driver);
}
static void __exit cas_cleanup(void)
{
pci_unregister_driver(&cas_driver);
}
