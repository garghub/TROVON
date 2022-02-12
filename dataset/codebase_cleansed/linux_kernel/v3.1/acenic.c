static int __devinit acenic_probe_one(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct net_device *dev;
struct ace_private *ap;
static int boards_found;
dev = alloc_etherdev(sizeof(struct ace_private));
if (dev == NULL) {
printk(KERN_ERR "acenic: Unable to allocate "
"net_device structure!\n");
return -ENOMEM;
}
SET_NETDEV_DEV(dev, &pdev->dev);
ap = netdev_priv(dev);
ap->pdev = pdev;
ap->name = pci_name(pdev);
dev->features |= NETIF_F_SG | NETIF_F_IP_CSUM;
dev->features |= NETIF_F_HW_VLAN_TX | NETIF_F_HW_VLAN_RX;
dev->watchdog_timeo = 5*HZ;
dev->netdev_ops = &ace_netdev_ops;
SET_ETHTOOL_OPS(dev, &ace_ethtool_ops);
if (!boards_found)
printk(version);
if (pci_enable_device(pdev))
goto fail_free_netdev;
pci_set_master(pdev);
pci_read_config_word(pdev, PCI_COMMAND, &ap->pci_command);
if (!(ap->pci_command & PCI_COMMAND_MEMORY)) {
printk(KERN_INFO "%s: Enabling PCI Memory Mapped "
"access - was not enabled by BIOS/Firmware\n",
ap->name);
ap->pci_command = ap->pci_command | PCI_COMMAND_MEMORY;
pci_write_config_word(ap->pdev, PCI_COMMAND,
ap->pci_command);
wmb();
}
pci_read_config_byte(pdev, PCI_LATENCY_TIMER, &ap->pci_latency);
if (ap->pci_latency <= 0x40) {
ap->pci_latency = 0x40;
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, ap->pci_latency);
}
dev->base_addr = pci_resource_start(pdev, 0);
ap->regs = ioremap(dev->base_addr, 0x4000);
if (!ap->regs) {
printk(KERN_ERR "%s: Unable to map I/O register, "
"AceNIC %i will be disabled.\n",
ap->name, boards_found);
goto fail_free_netdev;
}
switch(pdev->vendor) {
case PCI_VENDOR_ID_ALTEON:
if (pdev->device == PCI_DEVICE_ID_FARALLON_PN9100T) {
printk(KERN_INFO "%s: Farallon PN9100-T ",
ap->name);
} else {
printk(KERN_INFO "%s: Alteon AceNIC ",
ap->name);
}
break;
case PCI_VENDOR_ID_3COM:
printk(KERN_INFO "%s: 3Com 3C985 ", ap->name);
break;
case PCI_VENDOR_ID_NETGEAR:
printk(KERN_INFO "%s: NetGear GA620 ", ap->name);
break;
case PCI_VENDOR_ID_DEC:
if (pdev->device == PCI_DEVICE_ID_FARALLON_PN9000SX) {
printk(KERN_INFO "%s: Farallon PN9000-SX ",
ap->name);
break;
}
case PCI_VENDOR_ID_SGI:
printk(KERN_INFO "%s: SGI AceNIC ", ap->name);
break;
default:
printk(KERN_INFO "%s: Unknown AceNIC ", ap->name);
break;
}
printk("Gigabit Ethernet at 0x%08lx, ", dev->base_addr);
printk("irq %d\n", pdev->irq);
#ifdef CONFIG_ACENIC_OMIT_TIGON_I
if ((readl(&ap->regs->HostCtrl) >> 28) == 4) {
printk(KERN_ERR "%s: Driver compiled without Tigon I"
" support - NIC disabled\n", dev->name);
goto fail_uninit;
}
#endif
if (ace_allocate_descriptors(dev))
goto fail_free_netdev;
#ifdef MODULE
if (boards_found >= ACE_MAX_MOD_PARMS)
ap->board_idx = BOARD_IDX_OVERFLOW;
else
ap->board_idx = boards_found;
#else
ap->board_idx = BOARD_IDX_STATIC;
#endif
if (ace_init(dev))
goto fail_free_netdev;
if (register_netdev(dev)) {
printk(KERN_ERR "acenic: device registration failed\n");
goto fail_uninit;
}
ap->name = dev->name;
if (ap->pci_using_dac)
dev->features |= NETIF_F_HIGHDMA;
pci_set_drvdata(pdev, dev);
boards_found++;
return 0;
fail_uninit:
ace_init_cleanup(dev);
fail_free_netdev:
free_netdev(dev);
return -ENODEV;
}
static void __devexit acenic_remove_one(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
short i;
unregister_netdev(dev);
writel(readl(&regs->CpuCtrl) | CPU_HALT, &regs->CpuCtrl);
if (ap->version >= 2)
writel(readl(&regs->CpuBCtrl) | CPU_HALT, &regs->CpuBCtrl);
writel(1, &regs->Mb0Lo);
readl(&regs->CpuCtrl);
ace_sync_irq(dev->irq);
for (i = 0; i < RX_STD_RING_ENTRIES; i++) {
struct sk_buff *skb = ap->skb->rx_std_skbuff[i].skb;
if (skb) {
struct ring_info *ringp;
dma_addr_t mapping;
ringp = &ap->skb->rx_std_skbuff[i];
mapping = dma_unmap_addr(ringp, mapping);
pci_unmap_page(ap->pdev, mapping,
ACE_STD_BUFSIZE,
PCI_DMA_FROMDEVICE);
ap->rx_std_ring[i].size = 0;
ap->skb->rx_std_skbuff[i].skb = NULL;
dev_kfree_skb(skb);
}
}
if (ap->version >= 2) {
for (i = 0; i < RX_MINI_RING_ENTRIES; i++) {
struct sk_buff *skb = ap->skb->rx_mini_skbuff[i].skb;
if (skb) {
struct ring_info *ringp;
dma_addr_t mapping;
ringp = &ap->skb->rx_mini_skbuff[i];
mapping = dma_unmap_addr(ringp,mapping);
pci_unmap_page(ap->pdev, mapping,
ACE_MINI_BUFSIZE,
PCI_DMA_FROMDEVICE);
ap->rx_mini_ring[i].size = 0;
ap->skb->rx_mini_skbuff[i].skb = NULL;
dev_kfree_skb(skb);
}
}
}
for (i = 0; i < RX_JUMBO_RING_ENTRIES; i++) {
struct sk_buff *skb = ap->skb->rx_jumbo_skbuff[i].skb;
if (skb) {
struct ring_info *ringp;
dma_addr_t mapping;
ringp = &ap->skb->rx_jumbo_skbuff[i];
mapping = dma_unmap_addr(ringp, mapping);
pci_unmap_page(ap->pdev, mapping,
ACE_JUMBO_BUFSIZE,
PCI_DMA_FROMDEVICE);
ap->rx_jumbo_ring[i].size = 0;
ap->skb->rx_jumbo_skbuff[i].skb = NULL;
dev_kfree_skb(skb);
}
}
ace_init_cleanup(dev);
free_netdev(dev);
}
static int __init acenic_init(void)
{
return pci_register_driver(&acenic_pci_driver);
}
static void __exit acenic_exit(void)
{
pci_unregister_driver(&acenic_pci_driver);
}
static void ace_free_descriptors(struct net_device *dev)
{
struct ace_private *ap = netdev_priv(dev);
int size;
if (ap->rx_std_ring != NULL) {
size = (sizeof(struct rx_desc) *
(RX_STD_RING_ENTRIES +
RX_JUMBO_RING_ENTRIES +
RX_MINI_RING_ENTRIES +
RX_RETURN_RING_ENTRIES));
pci_free_consistent(ap->pdev, size, ap->rx_std_ring,
ap->rx_ring_base_dma);
ap->rx_std_ring = NULL;
ap->rx_jumbo_ring = NULL;
ap->rx_mini_ring = NULL;
ap->rx_return_ring = NULL;
}
if (ap->evt_ring != NULL) {
size = (sizeof(struct event) * EVT_RING_ENTRIES);
pci_free_consistent(ap->pdev, size, ap->evt_ring,
ap->evt_ring_dma);
ap->evt_ring = NULL;
}
if (ap->tx_ring != NULL && !ACE_IS_TIGON_I(ap)) {
size = (sizeof(struct tx_desc) * MAX_TX_RING_ENTRIES);
pci_free_consistent(ap->pdev, size, ap->tx_ring,
ap->tx_ring_dma);
}
ap->tx_ring = NULL;
if (ap->evt_prd != NULL) {
pci_free_consistent(ap->pdev, sizeof(u32),
(void *)ap->evt_prd, ap->evt_prd_dma);
ap->evt_prd = NULL;
}
if (ap->rx_ret_prd != NULL) {
pci_free_consistent(ap->pdev, sizeof(u32),
(void *)ap->rx_ret_prd,
ap->rx_ret_prd_dma);
ap->rx_ret_prd = NULL;
}
if (ap->tx_csm != NULL) {
pci_free_consistent(ap->pdev, sizeof(u32),
(void *)ap->tx_csm, ap->tx_csm_dma);
ap->tx_csm = NULL;
}
}
static int ace_allocate_descriptors(struct net_device *dev)
{
struct ace_private *ap = netdev_priv(dev);
int size;
size = (sizeof(struct rx_desc) *
(RX_STD_RING_ENTRIES +
RX_JUMBO_RING_ENTRIES +
RX_MINI_RING_ENTRIES +
RX_RETURN_RING_ENTRIES));
ap->rx_std_ring = pci_alloc_consistent(ap->pdev, size,
&ap->rx_ring_base_dma);
if (ap->rx_std_ring == NULL)
goto fail;
ap->rx_jumbo_ring = ap->rx_std_ring + RX_STD_RING_ENTRIES;
ap->rx_mini_ring = ap->rx_jumbo_ring + RX_JUMBO_RING_ENTRIES;
ap->rx_return_ring = ap->rx_mini_ring + RX_MINI_RING_ENTRIES;
size = (sizeof(struct event) * EVT_RING_ENTRIES);
ap->evt_ring = pci_alloc_consistent(ap->pdev, size, &ap->evt_ring_dma);
if (ap->evt_ring == NULL)
goto fail;
if (!ACE_IS_TIGON_I(ap)) {
size = (sizeof(struct tx_desc) * MAX_TX_RING_ENTRIES);
ap->tx_ring = pci_alloc_consistent(ap->pdev, size,
&ap->tx_ring_dma);
if (ap->tx_ring == NULL)
goto fail;
}
ap->evt_prd = pci_alloc_consistent(ap->pdev, sizeof(u32),
&ap->evt_prd_dma);
if (ap->evt_prd == NULL)
goto fail;
ap->rx_ret_prd = pci_alloc_consistent(ap->pdev, sizeof(u32),
&ap->rx_ret_prd_dma);
if (ap->rx_ret_prd == NULL)
goto fail;
ap->tx_csm = pci_alloc_consistent(ap->pdev, sizeof(u32),
&ap->tx_csm_dma);
if (ap->tx_csm == NULL)
goto fail;
return 0;
fail:
ace_init_cleanup(dev);
return 1;
}
static void ace_init_cleanup(struct net_device *dev)
{
struct ace_private *ap;
ap = netdev_priv(dev);
ace_free_descriptors(dev);
if (ap->info)
pci_free_consistent(ap->pdev, sizeof(struct ace_info),
ap->info, ap->info_dma);
kfree(ap->skb);
kfree(ap->trace_buf);
if (dev->irq)
free_irq(dev->irq, dev);
iounmap(ap->regs);
}
static inline void ace_issue_cmd(struct ace_regs __iomem *regs, struct cmd *cmd)
{
u32 idx;
idx = readl(&regs->CmdPrd);
writel(*(u32 *)(cmd), &regs->CmdRng[idx]);
idx = (idx + 1) % CMD_RING_ENTRIES;
writel(idx, &regs->CmdPrd);
}
static int __devinit ace_init(struct net_device *dev)
{
struct ace_private *ap;
struct ace_regs __iomem *regs;
struct ace_info *info = NULL;
struct pci_dev *pdev;
unsigned long myjif;
u64 tmp_ptr;
u32 tig_ver, mac1, mac2, tmp, pci_state;
int board_idx, ecode = 0;
short i;
unsigned char cache_size;
ap = netdev_priv(dev);
regs = ap->regs;
board_idx = ap->board_idx;
writel(HW_RESET | (HW_RESET << 24), &regs->HostCtrl);
readl(&regs->HostCtrl);
udelay(5);
#ifdef __BIG_ENDIAN
writel((WORD_SWAP | CLR_INT | ((WORD_SWAP | CLR_INT) << 24)),
&regs->HostCtrl);
#else
writel((CLR_INT | WORD_SWAP | ((CLR_INT | WORD_SWAP) << 24)),
&regs->HostCtrl);
#endif
readl(&regs->HostCtrl);
writel(readl(&regs->CpuCtrl) | CPU_HALT, &regs->CpuCtrl);
readl(&regs->CpuCtrl);
writel(0, &regs->Mb0Lo);
tig_ver = readl(&regs->HostCtrl) >> 28;
switch(tig_ver){
#ifndef CONFIG_ACENIC_OMIT_TIGON_I
case 4:
case 5:
printk(KERN_INFO " Tigon I (Rev. %i), Firmware: %i.%i.%i, ",
tig_ver, ap->firmware_major, ap->firmware_minor,
ap->firmware_fix);
writel(0, &regs->LocalCtrl);
ap->version = 1;
ap->tx_ring_entries = TIGON_I_TX_RING_ENTRIES;
break;
#endif
case 6:
printk(KERN_INFO " Tigon II (Rev. %i), Firmware: %i.%i.%i, ",
tig_ver, ap->firmware_major, ap->firmware_minor,
ap->firmware_fix);
writel(readl(&regs->CpuBCtrl) | CPU_HALT, &regs->CpuBCtrl);
readl(&regs->CpuBCtrl);
writel(SRAM_BANK_512K, &regs->LocalCtrl);
writel(SYNC_SRAM_TIMING, &regs->MiscCfg);
ap->version = 2;
ap->tx_ring_entries = MAX_TX_RING_ENTRIES;
break;
default:
printk(KERN_WARNING " Unsupported Tigon version detected "
"(%i)\n", tig_ver);
ecode = -ENODEV;
goto init_error;
}
#ifdef __BIG_ENDIAN
writel(ACE_BYTE_SWAP_DMA | ACE_WARN | ACE_FATAL | ACE_BYTE_SWAP_BD |
ACE_WORD_SWAP_BD | ACE_NO_JUMBO_FRAG, &regs->ModeStat);
#else
writel(ACE_BYTE_SWAP_DMA | ACE_WARN | ACE_FATAL |
ACE_WORD_SWAP_BD | ACE_NO_JUMBO_FRAG, &regs->ModeStat);
#endif
readl(&regs->ModeStat);
mac1 = 0;
for(i = 0; i < 4; i++) {
int t;
mac1 = mac1 << 8;
t = read_eeprom_byte(dev, 0x8c+i);
if (t < 0) {
ecode = -EIO;
goto init_error;
} else
mac1 |= (t & 0xff);
}
mac2 = 0;
for(i = 4; i < 8; i++) {
int t;
mac2 = mac2 << 8;
t = read_eeprom_byte(dev, 0x8c+i);
if (t < 0) {
ecode = -EIO;
goto init_error;
} else
mac2 |= (t & 0xff);
}
writel(mac1, &regs->MacAddrHi);
writel(mac2, &regs->MacAddrLo);
dev->dev_addr[0] = (mac1 >> 8) & 0xff;
dev->dev_addr[1] = mac1 & 0xff;
dev->dev_addr[2] = (mac2 >> 24) & 0xff;
dev->dev_addr[3] = (mac2 >> 16) & 0xff;
dev->dev_addr[4] = (mac2 >> 8) & 0xff;
dev->dev_addr[5] = mac2 & 0xff;
printk("MAC: %pM\n", dev->dev_addr);
pdev = ap->pdev;
pci_read_config_byte(pdev, PCI_CACHE_LINE_SIZE, &cache_size);
cache_size <<= 2;
if (cache_size != SMP_CACHE_BYTES) {
printk(KERN_INFO " PCI cache line size set incorrectly "
"(%i bytes) by BIOS/FW, ", cache_size);
if (cache_size > SMP_CACHE_BYTES)
printk("expecting %i\n", SMP_CACHE_BYTES);
else {
printk("correcting to %i\n", SMP_CACHE_BYTES);
pci_write_config_byte(pdev, PCI_CACHE_LINE_SIZE,
SMP_CACHE_BYTES >> 2);
}
}
pci_state = readl(&regs->PciState);
printk(KERN_INFO " PCI bus width: %i bits, speed: %iMHz, "
"latency: %i clks\n",
(pci_state & PCI_32BIT) ? 32 : 64,
(pci_state & PCI_66MHZ) ? 66 : 33,
ap->pci_latency);
tmp = READ_CMD_MEM | WRITE_CMD_MEM;
if (ap->version >= 2) {
tmp |= (MEM_READ_MULTIPLE | (pci_state & PCI_66MHZ));
if (board_idx == BOARD_IDX_OVERFLOW ||
dis_pci_mem_inval[board_idx]) {
if (ap->pci_command & PCI_COMMAND_INVALIDATE) {
ap->pci_command &= ~PCI_COMMAND_INVALIDATE;
pci_write_config_word(pdev, PCI_COMMAND,
ap->pci_command);
printk(KERN_INFO " Disabling PCI memory "
"write and invalidate\n");
}
} else if (ap->pci_command & PCI_COMMAND_INVALIDATE) {
printk(KERN_INFO " PCI memory write & invalidate "
"enabled by BIOS, enabling counter measures\n");
switch(SMP_CACHE_BYTES) {
case 16:
tmp |= DMA_WRITE_MAX_16;
break;
case 32:
tmp |= DMA_WRITE_MAX_32;
break;
case 64:
tmp |= DMA_WRITE_MAX_64;
break;
case 128:
tmp |= DMA_WRITE_MAX_128;
break;
default:
printk(KERN_INFO " Cache line size %i not "
"supported, PCI write and invalidate "
"disabled\n", SMP_CACHE_BYTES);
ap->pci_command &= ~PCI_COMMAND_INVALIDATE;
pci_write_config_word(pdev, PCI_COMMAND,
ap->pci_command);
}
}
}
#ifdef __sparc__
tmp &= ~DMA_READ_WRITE_MASK;
tmp |= DMA_READ_MAX_64;
tmp |= DMA_WRITE_MAX_64;
#endif
#ifdef __alpha__
tmp &= ~DMA_READ_WRITE_MASK;
tmp |= DMA_READ_MAX_128;
tmp |= DMA_WRITE_MAX_128;
#endif
writel(tmp, &regs->PciState);
#if 0
if (!(ap->pci_command & PCI_COMMAND_FAST_BACK)) {
printk(KERN_INFO " Enabling PCI Fast Back to Back\n");
ap->pci_command |= PCI_COMMAND_FAST_BACK;
pci_write_config_word(pdev, PCI_COMMAND, ap->pci_command);
}
#endif
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
ap->pci_using_dac = 1;
} else if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(32))) {
ap->pci_using_dac = 0;
} else {
ecode = -ENODEV;
goto init_error;
}
if (!(info = pci_alloc_consistent(ap->pdev, sizeof(struct ace_info),
&ap->info_dma))) {
ecode = -EAGAIN;
goto init_error;
}
ap->info = info;
if (!(ap->skb = kmalloc(sizeof(struct ace_skb), GFP_KERNEL))) {
ecode = -EAGAIN;
goto init_error;
}
ecode = request_irq(pdev->irq, ace_interrupt, IRQF_SHARED,
DRV_NAME, dev);
if (ecode) {
printk(KERN_WARNING "%s: Requested IRQ %d is busy\n",
DRV_NAME, pdev->irq);
goto init_error;
} else
dev->irq = pdev->irq;
#ifdef INDEX_DEBUG
spin_lock_init(&ap->debug_lock);
ap->last_tx = ACE_TX_RING_ENTRIES(ap) - 1;
ap->last_std_rx = 0;
ap->last_mini_rx = 0;
#endif
memset(ap->info, 0, sizeof(struct ace_info));
memset(ap->skb, 0, sizeof(struct ace_skb));
ecode = ace_load_firmware(dev);
if (ecode)
goto init_error;
ap->fw_running = 0;
tmp_ptr = ap->info_dma;
writel(tmp_ptr >> 32, &regs->InfoPtrHi);
writel(tmp_ptr & 0xffffffff, &regs->InfoPtrLo);
memset(ap->evt_ring, 0, EVT_RING_ENTRIES * sizeof(struct event));
set_aceaddr(&info->evt_ctrl.rngptr, ap->evt_ring_dma);
info->evt_ctrl.flags = 0;
*(ap->evt_prd) = 0;
wmb();
set_aceaddr(&info->evt_prd_ptr, ap->evt_prd_dma);
writel(0, &regs->EvtCsm);
set_aceaddr(&info->cmd_ctrl.rngptr, 0x100);
info->cmd_ctrl.flags = 0;
info->cmd_ctrl.max_len = 0;
for (i = 0; i < CMD_RING_ENTRIES; i++)
writel(0, &regs->CmdRng[i]);
writel(0, &regs->CmdPrd);
writel(0, &regs->CmdCsm);
tmp_ptr = ap->info_dma;
tmp_ptr += (unsigned long) &(((struct ace_info *)0)->s.stats);
set_aceaddr(&info->stats2_ptr, (dma_addr_t) tmp_ptr);
set_aceaddr(&info->rx_std_ctrl.rngptr, ap->rx_ring_base_dma);
info->rx_std_ctrl.max_len = ACE_STD_BUFSIZE;
info->rx_std_ctrl.flags =
RCB_FLG_TCP_UDP_SUM | RCB_FLG_NO_PSEUDO_HDR | RCB_FLG_VLAN_ASSIST;
memset(ap->rx_std_ring, 0,
RX_STD_RING_ENTRIES * sizeof(struct rx_desc));
for (i = 0; i < RX_STD_RING_ENTRIES; i++)
ap->rx_std_ring[i].flags = BD_FLG_TCP_UDP_SUM;
ap->rx_std_skbprd = 0;
atomic_set(&ap->cur_rx_bufs, 0);
set_aceaddr(&info->rx_jumbo_ctrl.rngptr,
(ap->rx_ring_base_dma +
(sizeof(struct rx_desc) * RX_STD_RING_ENTRIES)));
info->rx_jumbo_ctrl.max_len = 0;
info->rx_jumbo_ctrl.flags =
RCB_FLG_TCP_UDP_SUM | RCB_FLG_NO_PSEUDO_HDR | RCB_FLG_VLAN_ASSIST;
memset(ap->rx_jumbo_ring, 0,
RX_JUMBO_RING_ENTRIES * sizeof(struct rx_desc));
for (i = 0; i < RX_JUMBO_RING_ENTRIES; i++)
ap->rx_jumbo_ring[i].flags = BD_FLG_TCP_UDP_SUM | BD_FLG_JUMBO;
ap->rx_jumbo_skbprd = 0;
atomic_set(&ap->cur_jumbo_bufs, 0);
memset(ap->rx_mini_ring, 0,
RX_MINI_RING_ENTRIES * sizeof(struct rx_desc));
if (ap->version >= 2) {
set_aceaddr(&info->rx_mini_ctrl.rngptr,
(ap->rx_ring_base_dma +
(sizeof(struct rx_desc) *
(RX_STD_RING_ENTRIES +
RX_JUMBO_RING_ENTRIES))));
info->rx_mini_ctrl.max_len = ACE_MINI_SIZE;
info->rx_mini_ctrl.flags =
RCB_FLG_TCP_UDP_SUM|RCB_FLG_NO_PSEUDO_HDR|RCB_FLG_VLAN_ASSIST;
for (i = 0; i < RX_MINI_RING_ENTRIES; i++)
ap->rx_mini_ring[i].flags =
BD_FLG_TCP_UDP_SUM | BD_FLG_MINI;
} else {
set_aceaddr(&info->rx_mini_ctrl.rngptr, 0);
info->rx_mini_ctrl.flags = RCB_FLG_RNG_DISABLE;
info->rx_mini_ctrl.max_len = 0;
}
ap->rx_mini_skbprd = 0;
atomic_set(&ap->cur_mini_bufs, 0);
set_aceaddr(&info->rx_return_ctrl.rngptr,
(ap->rx_ring_base_dma +
(sizeof(struct rx_desc) *
(RX_STD_RING_ENTRIES +
RX_JUMBO_RING_ENTRIES +
RX_MINI_RING_ENTRIES))));
info->rx_return_ctrl.flags = 0;
info->rx_return_ctrl.max_len = RX_RETURN_RING_ENTRIES;
memset(ap->rx_return_ring, 0,
RX_RETURN_RING_ENTRIES * sizeof(struct rx_desc));
set_aceaddr(&info->rx_ret_prd_ptr, ap->rx_ret_prd_dma);
*(ap->rx_ret_prd) = 0;
writel(TX_RING_BASE, &regs->WinBase);
if (ACE_IS_TIGON_I(ap)) {
ap->tx_ring = (__force struct tx_desc *) regs->Window;
for (i = 0; i < (TIGON_I_TX_RING_ENTRIES
* sizeof(struct tx_desc)) / sizeof(u32); i++)
writel(0, (__force void __iomem *)ap->tx_ring + i * 4);
set_aceaddr(&info->tx_ctrl.rngptr, TX_RING_BASE);
} else {
memset(ap->tx_ring, 0,
MAX_TX_RING_ENTRIES * sizeof(struct tx_desc));
set_aceaddr(&info->tx_ctrl.rngptr, ap->tx_ring_dma);
}
info->tx_ctrl.max_len = ACE_TX_RING_ENTRIES(ap);
tmp = RCB_FLG_TCP_UDP_SUM | RCB_FLG_NO_PSEUDO_HDR | RCB_FLG_VLAN_ASSIST;
if (!ACE_IS_TIGON_I(ap))
tmp |= RCB_FLG_TX_HOST_RING;
#if TX_COAL_INTS_ONLY
tmp |= RCB_FLG_COAL_INT_ONLY;
#endif
info->tx_ctrl.flags = tmp;
set_aceaddr(&info->tx_csm_ptr, ap->tx_csm_dma);
#if 0
writel(DMA_THRESH_16W, &regs->DmaReadCfg);
writel(DMA_THRESH_16W, &regs->DmaWriteCfg);
#else
writel(DMA_THRESH_8W, &regs->DmaReadCfg);
writel(DMA_THRESH_8W, &regs->DmaWriteCfg);
#endif
writel(0, &regs->MaskInt);
writel(1, &regs->IfIdx);
#if 0
writel(1, &regs->AssistState);
#endif
writel(DEF_STAT, &regs->TuneStatTicks);
writel(DEF_TRACE, &regs->TuneTrace);
ace_set_rxtx_parms(dev, 0);
if (board_idx == BOARD_IDX_OVERFLOW) {
printk(KERN_WARNING "%s: more than %i NICs detected, "
"ignoring module parameters!\n",
ap->name, ACE_MAX_MOD_PARMS);
} else if (board_idx >= 0) {
if (tx_coal_tick[board_idx])
writel(tx_coal_tick[board_idx],
&regs->TuneTxCoalTicks);
if (max_tx_desc[board_idx])
writel(max_tx_desc[board_idx], &regs->TuneMaxTxDesc);
if (rx_coal_tick[board_idx])
writel(rx_coal_tick[board_idx],
&regs->TuneRxCoalTicks);
if (max_rx_desc[board_idx])
writel(max_rx_desc[board_idx], &regs->TuneMaxRxDesc);
if (trace[board_idx])
writel(trace[board_idx], &regs->TuneTrace);
if ((tx_ratio[board_idx] > 0) && (tx_ratio[board_idx] < 64))
writel(tx_ratio[board_idx], &regs->TxBufRat);
}
tmp = LNK_ENABLE | LNK_FULL_DUPLEX | LNK_1000MB | LNK_100MB |
LNK_10MB | LNK_RX_FLOW_CTL_Y | LNK_NEG_FCTL | LNK_NEGOTIATE;
if(ap->version >= 2)
tmp |= LNK_TX_FLOW_CTL_Y;
if ((board_idx >= 0) && link_state[board_idx]) {
int option = link_state[board_idx];
tmp = LNK_ENABLE;
if (option & 0x01) {
printk(KERN_INFO "%s: Setting half duplex link\n",
ap->name);
tmp &= ~LNK_FULL_DUPLEX;
}
if (option & 0x02)
tmp &= ~LNK_NEGOTIATE;
if (option & 0x10)
tmp |= LNK_10MB;
if (option & 0x20)
tmp |= LNK_100MB;
if (option & 0x40)
tmp |= LNK_1000MB;
if ((option & 0x70) == 0) {
printk(KERN_WARNING "%s: No media speed specified, "
"forcing auto negotiation\n", ap->name);
tmp |= LNK_NEGOTIATE | LNK_1000MB |
LNK_100MB | LNK_10MB;
}
if ((option & 0x100) == 0)
tmp |= LNK_NEG_FCTL;
else
printk(KERN_INFO "%s: Disabling flow control "
"negotiation\n", ap->name);
if (option & 0x200)
tmp |= LNK_RX_FLOW_CTL_Y;
if ((option & 0x400) && (ap->version >= 2)) {
printk(KERN_INFO "%s: Enabling TX flow control\n",
ap->name);
tmp |= LNK_TX_FLOW_CTL_Y;
}
}
ap->link = tmp;
writel(tmp, &regs->TuneLink);
if (ap->version >= 2)
writel(tmp, &regs->TuneFastLink);
writel(ap->firmware_start, &regs->Pc);
writel(0, &regs->Mb0Lo);
ap->cur_rx = 0;
ap->tx_prd = *(ap->tx_csm) = ap->tx_ret_csm = 0;
wmb();
ace_set_txprd(regs, ap, 0);
writel(0, &regs->RxRetCsm);
writel(1, &regs->AssistState);
writel(readl(&regs->CpuCtrl) & ~(CPU_HALT|CPU_TRACE), &regs->CpuCtrl);
readl(&regs->CpuCtrl);
myjif = jiffies + 3 * HZ;
while (time_before(jiffies, myjif) && !ap->fw_running)
cpu_relax();
if (!ap->fw_running) {
printk(KERN_ERR "%s: Firmware NOT running!\n", ap->name);
ace_dump_trace(ap);
writel(readl(&regs->CpuCtrl) | CPU_HALT, &regs->CpuCtrl);
readl(&regs->CpuCtrl);
if (ap->version >= 2)
writel(readl(&regs->CpuBCtrl) | CPU_HALT,
&regs->CpuBCtrl);
writel(0, &regs->Mb0Lo);
readl(&regs->Mb0Lo);
ecode = -EBUSY;
goto init_error;
}
if (!test_and_set_bit(0, &ap->std_refill_busy))
ace_load_std_rx_ring(dev, RX_RING_SIZE);
else
printk(KERN_ERR "%s: Someone is busy refilling the RX ring\n",
ap->name);
if (ap->version >= 2) {
if (!test_and_set_bit(0, &ap->mini_refill_busy))
ace_load_mini_rx_ring(dev, RX_MINI_SIZE);
else
printk(KERN_ERR "%s: Someone is busy refilling "
"the RX mini ring\n", ap->name);
}
return 0;
init_error:
ace_init_cleanup(dev);
return ecode;
}
static void ace_set_rxtx_parms(struct net_device *dev, int jumbo)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
int board_idx = ap->board_idx;
if (board_idx >= 0) {
if (!jumbo) {
if (!tx_coal_tick[board_idx])
writel(DEF_TX_COAL, &regs->TuneTxCoalTicks);
if (!max_tx_desc[board_idx])
writel(DEF_TX_MAX_DESC, &regs->TuneMaxTxDesc);
if (!rx_coal_tick[board_idx])
writel(DEF_RX_COAL, &regs->TuneRxCoalTicks);
if (!max_rx_desc[board_idx])
writel(DEF_RX_MAX_DESC, &regs->TuneMaxRxDesc);
if (!tx_ratio[board_idx])
writel(DEF_TX_RATIO, &regs->TxBufRat);
} else {
if (!tx_coal_tick[board_idx])
writel(DEF_JUMBO_TX_COAL,
&regs->TuneTxCoalTicks);
if (!max_tx_desc[board_idx])
writel(DEF_JUMBO_TX_MAX_DESC,
&regs->TuneMaxTxDesc);
if (!rx_coal_tick[board_idx])
writel(DEF_JUMBO_RX_COAL,
&regs->TuneRxCoalTicks);
if (!max_rx_desc[board_idx])
writel(DEF_JUMBO_RX_MAX_DESC,
&regs->TuneMaxRxDesc);
if (!tx_ratio[board_idx])
writel(DEF_JUMBO_TX_RATIO, &regs->TxBufRat);
}
}
}
static void ace_watchdog(struct net_device *data)
{
struct net_device *dev = data;
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
if (*ap->tx_csm != ap->tx_ret_csm) {
printk(KERN_WARNING "%s: Transmitter is stuck, %08x\n",
dev->name, (unsigned int)readl(&regs->HostCtrl));
} else {
printk(KERN_DEBUG "%s: BUG... transmitter died. Kicking it.\n",
dev->name);
#if 0
netif_wake_queue(dev);
#endif
}
}
static void ace_tasklet(unsigned long arg)
{
struct net_device *dev = (struct net_device *) arg;
struct ace_private *ap = netdev_priv(dev);
int cur_size;
cur_size = atomic_read(&ap->cur_rx_bufs);
if ((cur_size < RX_LOW_STD_THRES) &&
!test_and_set_bit(0, &ap->std_refill_busy)) {
#ifdef DEBUG
printk("refilling buffers (current %i)\n", cur_size);
#endif
ace_load_std_rx_ring(dev, RX_RING_SIZE - cur_size);
}
if (ap->version >= 2) {
cur_size = atomic_read(&ap->cur_mini_bufs);
if ((cur_size < RX_LOW_MINI_THRES) &&
!test_and_set_bit(0, &ap->mini_refill_busy)) {
#ifdef DEBUG
printk("refilling mini buffers (current %i)\n",
cur_size);
#endif
ace_load_mini_rx_ring(dev, RX_MINI_SIZE - cur_size);
}
}
cur_size = atomic_read(&ap->cur_jumbo_bufs);
if (ap->jumbo && (cur_size < RX_LOW_JUMBO_THRES) &&
!test_and_set_bit(0, &ap->jumbo_refill_busy)) {
#ifdef DEBUG
printk("refilling jumbo buffers (current %i)\n", cur_size);
#endif
ace_load_jumbo_rx_ring(dev, RX_JUMBO_SIZE - cur_size);
}
ap->tasklet_pending = 0;
}
static void ace_dump_trace(struct ace_private *ap)
{
#if 0
if (!ap->trace_buf)
if (!(ap->trace_buf = kmalloc(ACE_TRACE_SIZE, GFP_KERNEL)))
return;
#endif
}
static void ace_load_std_rx_ring(struct net_device *dev, int nr_bufs)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
short i, idx;
prefetchw(&ap->cur_rx_bufs);
idx = ap->rx_std_skbprd;
for (i = 0; i < nr_bufs; i++) {
struct sk_buff *skb;
struct rx_desc *rd;
dma_addr_t mapping;
skb = netdev_alloc_skb_ip_align(dev, ACE_STD_BUFSIZE);
if (!skb)
break;
mapping = pci_map_page(ap->pdev, virt_to_page(skb->data),
offset_in_page(skb->data),
ACE_STD_BUFSIZE,
PCI_DMA_FROMDEVICE);
ap->skb->rx_std_skbuff[idx].skb = skb;
dma_unmap_addr_set(&ap->skb->rx_std_skbuff[idx],
mapping, mapping);
rd = &ap->rx_std_ring[idx];
set_aceaddr(&rd->addr, mapping);
rd->size = ACE_STD_BUFSIZE;
rd->idx = idx;
idx = (idx + 1) % RX_STD_RING_ENTRIES;
}
if (!i)
goto error_out;
atomic_add(i, &ap->cur_rx_bufs);
ap->rx_std_skbprd = idx;
if (ACE_IS_TIGON_I(ap)) {
struct cmd cmd;
cmd.evt = C_SET_RX_PRD_IDX;
cmd.code = 0;
cmd.idx = ap->rx_std_skbprd;
ace_issue_cmd(regs, &cmd);
} else {
writel(idx, &regs->RxStdPrd);
wmb();
}
out:
clear_bit(0, &ap->std_refill_busy);
return;
error_out:
printk(KERN_INFO "Out of memory when allocating "
"standard receive buffers\n");
goto out;
}
static void ace_load_mini_rx_ring(struct net_device *dev, int nr_bufs)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
short i, idx;
prefetchw(&ap->cur_mini_bufs);
idx = ap->rx_mini_skbprd;
for (i = 0; i < nr_bufs; i++) {
struct sk_buff *skb;
struct rx_desc *rd;
dma_addr_t mapping;
skb = netdev_alloc_skb_ip_align(dev, ACE_MINI_BUFSIZE);
if (!skb)
break;
mapping = pci_map_page(ap->pdev, virt_to_page(skb->data),
offset_in_page(skb->data),
ACE_MINI_BUFSIZE,
PCI_DMA_FROMDEVICE);
ap->skb->rx_mini_skbuff[idx].skb = skb;
dma_unmap_addr_set(&ap->skb->rx_mini_skbuff[idx],
mapping, mapping);
rd = &ap->rx_mini_ring[idx];
set_aceaddr(&rd->addr, mapping);
rd->size = ACE_MINI_BUFSIZE;
rd->idx = idx;
idx = (idx + 1) % RX_MINI_RING_ENTRIES;
}
if (!i)
goto error_out;
atomic_add(i, &ap->cur_mini_bufs);
ap->rx_mini_skbprd = idx;
writel(idx, &regs->RxMiniPrd);
wmb();
out:
clear_bit(0, &ap->mini_refill_busy);
return;
error_out:
printk(KERN_INFO "Out of memory when allocating "
"mini receive buffers\n");
goto out;
}
static void ace_load_jumbo_rx_ring(struct net_device *dev, int nr_bufs)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
short i, idx;
idx = ap->rx_jumbo_skbprd;
for (i = 0; i < nr_bufs; i++) {
struct sk_buff *skb;
struct rx_desc *rd;
dma_addr_t mapping;
skb = netdev_alloc_skb_ip_align(dev, ACE_JUMBO_BUFSIZE);
if (!skb)
break;
mapping = pci_map_page(ap->pdev, virt_to_page(skb->data),
offset_in_page(skb->data),
ACE_JUMBO_BUFSIZE,
PCI_DMA_FROMDEVICE);
ap->skb->rx_jumbo_skbuff[idx].skb = skb;
dma_unmap_addr_set(&ap->skb->rx_jumbo_skbuff[idx],
mapping, mapping);
rd = &ap->rx_jumbo_ring[idx];
set_aceaddr(&rd->addr, mapping);
rd->size = ACE_JUMBO_BUFSIZE;
rd->idx = idx;
idx = (idx + 1) % RX_JUMBO_RING_ENTRIES;
}
if (!i)
goto error_out;
atomic_add(i, &ap->cur_jumbo_bufs);
ap->rx_jumbo_skbprd = idx;
if (ACE_IS_TIGON_I(ap)) {
struct cmd cmd;
cmd.evt = C_SET_RX_JUMBO_PRD_IDX;
cmd.code = 0;
cmd.idx = ap->rx_jumbo_skbprd;
ace_issue_cmd(regs, &cmd);
} else {
writel(idx, &regs->RxJumboPrd);
wmb();
}
out:
clear_bit(0, &ap->jumbo_refill_busy);
return;
error_out:
if (net_ratelimit())
printk(KERN_INFO "Out of memory when allocating "
"jumbo receive buffers\n");
goto out;
}
static u32 ace_handle_event(struct net_device *dev, u32 evtcsm, u32 evtprd)
{
struct ace_private *ap;
ap = netdev_priv(dev);
while (evtcsm != evtprd) {
switch (ap->evt_ring[evtcsm].evt) {
case E_FW_RUNNING:
printk(KERN_INFO "%s: Firmware up and running\n",
ap->name);
ap->fw_running = 1;
wmb();
break;
case E_STATS_UPDATED:
break;
case E_LNK_STATE:
{
u16 code = ap->evt_ring[evtcsm].code;
switch (code) {
case E_C_LINK_UP:
{
u32 state = readl(&ap->regs->GigLnkState);
printk(KERN_WARNING "%s: Optical link UP "
"(%s Duplex, Flow Control: %s%s)\n",
ap->name,
state & LNK_FULL_DUPLEX ? "Full":"Half",
state & LNK_TX_FLOW_CTL_Y ? "TX " : "",
state & LNK_RX_FLOW_CTL_Y ? "RX" : "");
break;
}
case E_C_LINK_DOWN:
printk(KERN_WARNING "%s: Optical link DOWN\n",
ap->name);
break;
case E_C_LINK_10_100:
printk(KERN_WARNING "%s: 10/100BaseT link "
"UP\n", ap->name);
break;
default:
printk(KERN_ERR "%s: Unknown optical link "
"state %02x\n", ap->name, code);
}
break;
}
case E_ERROR:
switch(ap->evt_ring[evtcsm].code) {
case E_C_ERR_INVAL_CMD:
printk(KERN_ERR "%s: invalid command error\n",
ap->name);
break;
case E_C_ERR_UNIMP_CMD:
printk(KERN_ERR "%s: unimplemented command "
"error\n", ap->name);
break;
case E_C_ERR_BAD_CFG:
printk(KERN_ERR "%s: bad config error\n",
ap->name);
break;
default:
printk(KERN_ERR "%s: unknown error %02x\n",
ap->name, ap->evt_ring[evtcsm].code);
}
break;
case E_RESET_JUMBO_RNG:
{
int i;
for (i = 0; i < RX_JUMBO_RING_ENTRIES; i++) {
if (ap->skb->rx_jumbo_skbuff[i].skb) {
ap->rx_jumbo_ring[i].size = 0;
set_aceaddr(&ap->rx_jumbo_ring[i].addr, 0);
dev_kfree_skb(ap->skb->rx_jumbo_skbuff[i].skb);
ap->skb->rx_jumbo_skbuff[i].skb = NULL;
}
}
if (ACE_IS_TIGON_I(ap)) {
struct cmd cmd;
cmd.evt = C_SET_RX_JUMBO_PRD_IDX;
cmd.code = 0;
cmd.idx = 0;
ace_issue_cmd(ap->regs, &cmd);
} else {
writel(0, &((ap->regs)->RxJumboPrd));
wmb();
}
ap->jumbo = 0;
ap->rx_jumbo_skbprd = 0;
printk(KERN_INFO "%s: Jumbo ring flushed\n",
ap->name);
clear_bit(0, &ap->jumbo_refill_busy);
break;
}
default:
printk(KERN_ERR "%s: Unhandled event 0x%02x\n",
ap->name, ap->evt_ring[evtcsm].evt);
}
evtcsm = (evtcsm + 1) % EVT_RING_ENTRIES;
}
return evtcsm;
}
static void ace_rx_int(struct net_device *dev, u32 rxretprd, u32 rxretcsm)
{
struct ace_private *ap = netdev_priv(dev);
u32 idx;
int mini_count = 0, std_count = 0;
idx = rxretcsm;
prefetchw(&ap->cur_rx_bufs);
prefetchw(&ap->cur_mini_bufs);
while (idx != rxretprd) {
struct ring_info *rip;
struct sk_buff *skb;
struct rx_desc *rxdesc, *retdesc;
u32 skbidx;
int bd_flags, desc_type, mapsize;
u16 csum;
if (idx == rxretcsm)
rmb();
retdesc = &ap->rx_return_ring[idx];
skbidx = retdesc->idx;
bd_flags = retdesc->flags;
desc_type = bd_flags & (BD_FLG_JUMBO | BD_FLG_MINI);
switch(desc_type) {
case 0:
rip = &ap->skb->rx_std_skbuff[skbidx];
mapsize = ACE_STD_BUFSIZE;
rxdesc = &ap->rx_std_ring[skbidx];
std_count++;
break;
case BD_FLG_JUMBO:
rip = &ap->skb->rx_jumbo_skbuff[skbidx];
mapsize = ACE_JUMBO_BUFSIZE;
rxdesc = &ap->rx_jumbo_ring[skbidx];
atomic_dec(&ap->cur_jumbo_bufs);
break;
case BD_FLG_MINI:
rip = &ap->skb->rx_mini_skbuff[skbidx];
mapsize = ACE_MINI_BUFSIZE;
rxdesc = &ap->rx_mini_ring[skbidx];
mini_count++;
break;
default:
printk(KERN_INFO "%s: unknown frame type (0x%02x) "
"returned by NIC\n", dev->name,
retdesc->flags);
goto error;
}
skb = rip->skb;
rip->skb = NULL;
pci_unmap_page(ap->pdev,
dma_unmap_addr(rip, mapping),
mapsize,
PCI_DMA_FROMDEVICE);
skb_put(skb, retdesc->size);
csum = retdesc->tcp_udp_csum;
skb->protocol = eth_type_trans(skb, dev);
if (bd_flags & BD_FLG_TCP_UDP_SUM) {
skb->csum = htons(csum);
skb->ip_summed = CHECKSUM_COMPLETE;
} else {
skb_checksum_none_assert(skb);
}
if ((bd_flags & BD_FLG_VLAN_TAG))
__vlan_hwaccel_put_tag(skb, retdesc->vlan);
netif_rx(skb);
dev->stats.rx_packets++;
dev->stats.rx_bytes += retdesc->size;
idx = (idx + 1) % RX_RETURN_RING_ENTRIES;
}
atomic_sub(std_count, &ap->cur_rx_bufs);
if (!ACE_IS_TIGON_I(ap))
atomic_sub(mini_count, &ap->cur_mini_bufs);
out:
if (ACE_IS_TIGON_I(ap)) {
writel(idx, &ap->regs->RxRetCsm);
}
ap->cur_rx = idx;
return;
error:
idx = rxretprd;
goto out;
}
static inline void ace_tx_int(struct net_device *dev,
u32 txcsm, u32 idx)
{
struct ace_private *ap = netdev_priv(dev);
do {
struct sk_buff *skb;
struct tx_ring_info *info;
info = ap->skb->tx_skbuff + idx;
skb = info->skb;
if (dma_unmap_len(info, maplen)) {
pci_unmap_page(ap->pdev, dma_unmap_addr(info, mapping),
dma_unmap_len(info, maplen),
PCI_DMA_TODEVICE);
dma_unmap_len_set(info, maplen, 0);
}
if (skb) {
dev->stats.tx_packets++;
dev->stats.tx_bytes += skb->len;
dev_kfree_skb_irq(skb);
info->skb = NULL;
}
idx = (idx + 1) % ACE_TX_RING_ENTRIES(ap);
} while (idx != txcsm);
if (netif_queue_stopped(dev))
netif_wake_queue(dev);
wmb();
ap->tx_ret_csm = txcsm;
}
static irqreturn_t ace_interrupt(int irq, void *dev_id)
{
struct net_device *dev = (struct net_device *)dev_id;
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
u32 idx;
u32 txcsm, rxretcsm, rxretprd;
u32 evtcsm, evtprd;
if (!(readl(&regs->HostCtrl) & IN_INT))
return IRQ_NONE;
writel(0, &regs->Mb0Lo);
readl(&regs->Mb0Lo);
rxretprd = *ap->rx_ret_prd;
rxretcsm = ap->cur_rx;
if (rxretprd != rxretcsm)
ace_rx_int(dev, rxretprd, rxretcsm);
txcsm = *ap->tx_csm;
idx = ap->tx_ret_csm;
if (txcsm != idx) {
if (!tx_ring_full(ap, txcsm, ap->tx_prd))
ace_tx_int(dev, txcsm, idx);
}
evtcsm = readl(&regs->EvtCsm);
evtprd = *ap->evt_prd;
if (evtcsm != evtprd) {
evtcsm = ace_handle_event(dev, evtcsm, evtprd);
writel(evtcsm, &regs->EvtCsm);
}
if (netif_running(dev)) {
int cur_size;
int run_tasklet = 0;
cur_size = atomic_read(&ap->cur_rx_bufs);
if (cur_size < RX_LOW_STD_THRES) {
if ((cur_size < RX_PANIC_STD_THRES) &&
!test_and_set_bit(0, &ap->std_refill_busy)) {
#ifdef DEBUG
printk("low on std buffers %i\n", cur_size);
#endif
ace_load_std_rx_ring(dev,
RX_RING_SIZE - cur_size);
} else
run_tasklet = 1;
}
if (!ACE_IS_TIGON_I(ap)) {
cur_size = atomic_read(&ap->cur_mini_bufs);
if (cur_size < RX_LOW_MINI_THRES) {
if ((cur_size < RX_PANIC_MINI_THRES) &&
!test_and_set_bit(0,
&ap->mini_refill_busy)) {
#ifdef DEBUG
printk("low on mini buffers %i\n",
cur_size);
#endif
ace_load_mini_rx_ring(dev,
RX_MINI_SIZE - cur_size);
} else
run_tasklet = 1;
}
}
if (ap->jumbo) {
cur_size = atomic_read(&ap->cur_jumbo_bufs);
if (cur_size < RX_LOW_JUMBO_THRES) {
if ((cur_size < RX_PANIC_JUMBO_THRES) &&
!test_and_set_bit(0,
&ap->jumbo_refill_busy)){
#ifdef DEBUG
printk("low on jumbo buffers %i\n",
cur_size);
#endif
ace_load_jumbo_rx_ring(dev,
RX_JUMBO_SIZE - cur_size);
} else
run_tasklet = 1;
}
}
if (run_tasklet && !ap->tasklet_pending) {
ap->tasklet_pending = 1;
tasklet_schedule(&ap->ace_tasklet);
}
}
return IRQ_HANDLED;
}
static int ace_open(struct net_device *dev)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
struct cmd cmd;
if (!(ap->fw_running)) {
printk(KERN_WARNING "%s: Firmware not running!\n", dev->name);
return -EBUSY;
}
writel(dev->mtu + ETH_HLEN + 4, &regs->IfMtu);
cmd.evt = C_CLEAR_STATS;
cmd.code = 0;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
cmd.evt = C_HOST_STATE;
cmd.code = C_C_STACK_UP;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
if (ap->jumbo &&
!test_and_set_bit(0, &ap->jumbo_refill_busy))
ace_load_jumbo_rx_ring(dev, RX_JUMBO_SIZE);
if (dev->flags & IFF_PROMISC) {
cmd.evt = C_SET_PROMISC_MODE;
cmd.code = C_C_PROMISC_ENABLE;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
ap->promisc = 1;
}else
ap->promisc = 0;
ap->mcast_all = 0;
#if 0
cmd.evt = C_LNK_NEGOTIATION;
cmd.code = 0;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
#endif
netif_start_queue(dev);
tasklet_init(&ap->ace_tasklet, ace_tasklet, (unsigned long)dev);
return 0;
}
static int ace_close(struct net_device *dev)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
struct cmd cmd;
unsigned long flags;
short i;
netif_stop_queue(dev);
if (ap->promisc) {
cmd.evt = C_SET_PROMISC_MODE;
cmd.code = C_C_PROMISC_DISABLE;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
ap->promisc = 0;
}
cmd.evt = C_HOST_STATE;
cmd.code = C_C_STACK_DOWN;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
tasklet_kill(&ap->ace_tasklet);
local_irq_save(flags);
ace_mask_irq(dev);
for (i = 0; i < ACE_TX_RING_ENTRIES(ap); i++) {
struct sk_buff *skb;
struct tx_ring_info *info;
info = ap->skb->tx_skbuff + i;
skb = info->skb;
if (dma_unmap_len(info, maplen)) {
if (ACE_IS_TIGON_I(ap)) {
struct tx_desc __iomem *tx;
tx = (__force struct tx_desc __iomem *) &ap->tx_ring[i];
writel(0, &tx->addr.addrhi);
writel(0, &tx->addr.addrlo);
writel(0, &tx->flagsize);
} else
memset(ap->tx_ring + i, 0,
sizeof(struct tx_desc));
pci_unmap_page(ap->pdev, dma_unmap_addr(info, mapping),
dma_unmap_len(info, maplen),
PCI_DMA_TODEVICE);
dma_unmap_len_set(info, maplen, 0);
}
if (skb) {
dev_kfree_skb(skb);
info->skb = NULL;
}
}
if (ap->jumbo) {
cmd.evt = C_RESET_JUMBO_RNG;
cmd.code = 0;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
}
ace_unmask_irq(dev);
local_irq_restore(flags);
return 0;
}
static inline dma_addr_t
ace_map_tx_skb(struct ace_private *ap, struct sk_buff *skb,
struct sk_buff *tail, u32 idx)
{
dma_addr_t mapping;
struct tx_ring_info *info;
mapping = pci_map_page(ap->pdev, virt_to_page(skb->data),
offset_in_page(skb->data),
skb->len, PCI_DMA_TODEVICE);
info = ap->skb->tx_skbuff + idx;
info->skb = tail;
dma_unmap_addr_set(info, mapping, mapping);
dma_unmap_len_set(info, maplen, skb->len);
return mapping;
}
static inline void
ace_load_tx_bd(struct ace_private *ap, struct tx_desc *desc, u64 addr,
u32 flagsize, u32 vlan_tag)
{
#if !USE_TX_COAL_NOW
flagsize &= ~BD_FLG_COAL_NOW;
#endif
if (ACE_IS_TIGON_I(ap)) {
struct tx_desc __iomem *io = (__force struct tx_desc __iomem *) desc;
writel(addr >> 32, &io->addr.addrhi);
writel(addr & 0xffffffff, &io->addr.addrlo);
writel(flagsize, &io->flagsize);
writel(vlan_tag, &io->vlanres);
} else {
desc->addr.addrhi = addr >> 32;
desc->addr.addrlo = addr;
desc->flagsize = flagsize;
desc->vlanres = vlan_tag;
}
}
static netdev_tx_t ace_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
struct tx_desc *desc;
u32 idx, flagsize;
unsigned long maxjiff = jiffies + 3*HZ;
restart:
idx = ap->tx_prd;
if (tx_ring_full(ap, ap->tx_ret_csm, idx))
goto overflow;
if (!skb_shinfo(skb)->nr_frags) {
dma_addr_t mapping;
u32 vlan_tag = 0;
mapping = ace_map_tx_skb(ap, skb, skb, idx);
flagsize = (skb->len << 16) | (BD_FLG_END);
if (skb->ip_summed == CHECKSUM_PARTIAL)
flagsize |= BD_FLG_TCP_UDP_SUM;
if (vlan_tx_tag_present(skb)) {
flagsize |= BD_FLG_VLAN_TAG;
vlan_tag = vlan_tx_tag_get(skb);
}
desc = ap->tx_ring + idx;
idx = (idx + 1) % ACE_TX_RING_ENTRIES(ap);
if (tx_ring_full(ap, ap->tx_ret_csm, idx))
flagsize |= BD_FLG_COAL_NOW;
ace_load_tx_bd(ap, desc, mapping, flagsize, vlan_tag);
} else {
dma_addr_t mapping;
u32 vlan_tag = 0;
int i, len = 0;
mapping = ace_map_tx_skb(ap, skb, NULL, idx);
flagsize = (skb_headlen(skb) << 16);
if (skb->ip_summed == CHECKSUM_PARTIAL)
flagsize |= BD_FLG_TCP_UDP_SUM;
if (vlan_tx_tag_present(skb)) {
flagsize |= BD_FLG_VLAN_TAG;
vlan_tag = vlan_tx_tag_get(skb);
}
ace_load_tx_bd(ap, ap->tx_ring + idx, mapping, flagsize, vlan_tag);
idx = (idx + 1) % ACE_TX_RING_ENTRIES(ap);
for (i = 0; i < skb_shinfo(skb)->nr_frags; i++) {
skb_frag_t *frag = &skb_shinfo(skb)->frags[i];
struct tx_ring_info *info;
len += frag->size;
info = ap->skb->tx_skbuff + idx;
desc = ap->tx_ring + idx;
mapping = pci_map_page(ap->pdev, frag->page,
frag->page_offset, frag->size,
PCI_DMA_TODEVICE);
flagsize = (frag->size << 16);
if (skb->ip_summed == CHECKSUM_PARTIAL)
flagsize |= BD_FLG_TCP_UDP_SUM;
idx = (idx + 1) % ACE_TX_RING_ENTRIES(ap);
if (i == skb_shinfo(skb)->nr_frags - 1) {
flagsize |= BD_FLG_END;
if (tx_ring_full(ap, ap->tx_ret_csm, idx))
flagsize |= BD_FLG_COAL_NOW;
info->skb = skb;
} else {
info->skb = NULL;
}
dma_unmap_addr_set(info, mapping, mapping);
dma_unmap_len_set(info, maplen, frag->size);
ace_load_tx_bd(ap, desc, mapping, flagsize, vlan_tag);
}
}
wmb();
ap->tx_prd = idx;
ace_set_txprd(regs, ap, idx);
if (flagsize & BD_FLG_COAL_NOW) {
netif_stop_queue(dev);
if (!tx_ring_full(ap, ap->tx_ret_csm, idx))
netif_wake_queue(dev);
}
return NETDEV_TX_OK;
overflow:
if (time_before(jiffies, maxjiff)) {
barrier();
cpu_relax();
goto restart;
}
printk(KERN_WARNING "%s: Transmit ring stuck full\n", dev->name);
return NETDEV_TX_BUSY;
}
static int ace_change_mtu(struct net_device *dev, int new_mtu)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
if (new_mtu > ACE_JUMBO_MTU)
return -EINVAL;
writel(new_mtu + ETH_HLEN + 4, &regs->IfMtu);
dev->mtu = new_mtu;
if (new_mtu > ACE_STD_MTU) {
if (!(ap->jumbo)) {
printk(KERN_INFO "%s: Enabling Jumbo frame "
"support\n", dev->name);
ap->jumbo = 1;
if (!test_and_set_bit(0, &ap->jumbo_refill_busy))
ace_load_jumbo_rx_ring(dev, RX_JUMBO_SIZE);
ace_set_rxtx_parms(dev, 1);
}
} else {
while (test_and_set_bit(0, &ap->jumbo_refill_busy));
ace_sync_irq(dev->irq);
ace_set_rxtx_parms(dev, 0);
if (ap->jumbo) {
struct cmd cmd;
cmd.evt = C_RESET_JUMBO_RNG;
cmd.code = 0;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
}
}
return 0;
}
static int ace_get_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
u32 link;
memset(ecmd, 0, sizeof(struct ethtool_cmd));
ecmd->supported =
(SUPPORTED_10baseT_Half | SUPPORTED_10baseT_Full |
SUPPORTED_100baseT_Half | SUPPORTED_100baseT_Full |
SUPPORTED_1000baseT_Half | SUPPORTED_1000baseT_Full |
SUPPORTED_Autoneg | SUPPORTED_FIBRE);
ecmd->port = PORT_FIBRE;
ecmd->transceiver = XCVR_INTERNAL;
link = readl(&regs->GigLnkState);
if (link & LNK_1000MB)
ethtool_cmd_speed_set(ecmd, SPEED_1000);
else {
link = readl(&regs->FastLnkState);
if (link & LNK_100MB)
ethtool_cmd_speed_set(ecmd, SPEED_100);
else if (link & LNK_10MB)
ethtool_cmd_speed_set(ecmd, SPEED_10);
else
ethtool_cmd_speed_set(ecmd, 0);
}
if (link & LNK_FULL_DUPLEX)
ecmd->duplex = DUPLEX_FULL;
else
ecmd->duplex = DUPLEX_HALF;
if (link & LNK_NEGOTIATE)
ecmd->autoneg = AUTONEG_ENABLE;
else
ecmd->autoneg = AUTONEG_DISABLE;
#if 0
ecmd->trace = readl(&regs->TuneTrace);
ecmd->txcoal = readl(&regs->TuneTxCoalTicks);
ecmd->rxcoal = readl(&regs->TuneRxCoalTicks);
#endif
ecmd->maxtxpkt = readl(&regs->TuneMaxTxDesc);
ecmd->maxrxpkt = readl(&regs->TuneMaxRxDesc);
return 0;
}
static int ace_set_settings(struct net_device *dev, struct ethtool_cmd *ecmd)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
u32 link, speed;
link = readl(&regs->GigLnkState);
if (link & LNK_1000MB)
speed = SPEED_1000;
else {
link = readl(&regs->FastLnkState);
if (link & LNK_100MB)
speed = SPEED_100;
else if (link & LNK_10MB)
speed = SPEED_10;
else
speed = SPEED_100;
}
link = LNK_ENABLE | LNK_1000MB | LNK_100MB | LNK_10MB |
LNK_RX_FLOW_CTL_Y | LNK_NEG_FCTL;
if (!ACE_IS_TIGON_I(ap))
link |= LNK_TX_FLOW_CTL_Y;
if (ecmd->autoneg == AUTONEG_ENABLE)
link |= LNK_NEGOTIATE;
if (ethtool_cmd_speed(ecmd) != speed) {
link &= ~(LNK_1000MB | LNK_100MB | LNK_10MB);
switch (ethtool_cmd_speed(ecmd)) {
case SPEED_1000:
link |= LNK_1000MB;
break;
case SPEED_100:
link |= LNK_100MB;
break;
case SPEED_10:
link |= LNK_10MB;
break;
}
}
if (ecmd->duplex == DUPLEX_FULL)
link |= LNK_FULL_DUPLEX;
if (link != ap->link) {
struct cmd cmd;
printk(KERN_INFO "%s: Renegotiating link state\n",
dev->name);
ap->link = link;
writel(link, &regs->TuneLink);
if (!ACE_IS_TIGON_I(ap))
writel(link, &regs->TuneFastLink);
wmb();
cmd.evt = C_LNK_NEGOTIATION;
cmd.code = 0;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
}
return 0;
}
static void ace_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct ace_private *ap = netdev_priv(dev);
strlcpy(info->driver, "acenic", sizeof(info->driver));
snprintf(info->version, sizeof(info->version), "%i.%i.%i",
ap->firmware_major, ap->firmware_minor,
ap->firmware_fix);
if (ap->pdev)
strlcpy(info->bus_info, pci_name(ap->pdev),
sizeof(info->bus_info));
}
static int ace_set_mac_addr(struct net_device *dev, void *p)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
struct sockaddr *addr=p;
u8 *da;
struct cmd cmd;
if(netif_running(dev))
return -EBUSY;
memcpy(dev->dev_addr, addr->sa_data,dev->addr_len);
da = (u8 *)dev->dev_addr;
writel(da[0] << 8 | da[1], &regs->MacAddrHi);
writel((da[2] << 24) | (da[3] << 16) | (da[4] << 8) | da[5],
&regs->MacAddrLo);
cmd.evt = C_SET_MAC_ADDR;
cmd.code = 0;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
return 0;
}
static void ace_set_multicast_list(struct net_device *dev)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
struct cmd cmd;
if ((dev->flags & IFF_ALLMULTI) && !(ap->mcast_all)) {
cmd.evt = C_SET_MULTICAST_MODE;
cmd.code = C_C_MCAST_ENABLE;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
ap->mcast_all = 1;
} else if (ap->mcast_all) {
cmd.evt = C_SET_MULTICAST_MODE;
cmd.code = C_C_MCAST_DISABLE;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
ap->mcast_all = 0;
}
if ((dev->flags & IFF_PROMISC) && !(ap->promisc)) {
cmd.evt = C_SET_PROMISC_MODE;
cmd.code = C_C_PROMISC_ENABLE;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
ap->promisc = 1;
}else if (!(dev->flags & IFF_PROMISC) && (ap->promisc)) {
cmd.evt = C_SET_PROMISC_MODE;
cmd.code = C_C_PROMISC_DISABLE;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
ap->promisc = 0;
}
if (!netdev_mc_empty(dev) && !ap->mcast_all) {
cmd.evt = C_SET_MULTICAST_MODE;
cmd.code = C_C_MCAST_ENABLE;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
}else if (!ap->mcast_all) {
cmd.evt = C_SET_MULTICAST_MODE;
cmd.code = C_C_MCAST_DISABLE;
cmd.idx = 0;
ace_issue_cmd(regs, &cmd);
}
}
static struct net_device_stats *ace_get_stats(struct net_device *dev)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_mac_stats __iomem *mac_stats =
(struct ace_mac_stats __iomem *)ap->regs->Stats;
dev->stats.rx_missed_errors = readl(&mac_stats->drop_space);
dev->stats.multicast = readl(&mac_stats->kept_mc);
dev->stats.collisions = readl(&mac_stats->coll);
return &dev->stats;
}
static void __devinit ace_copy(struct ace_regs __iomem *regs, const __be32 *src,
u32 dest, int size)
{
void __iomem *tdest;
short tsize, i;
if (size <= 0)
return;
while (size > 0) {
tsize = min_t(u32, ((~dest & (ACE_WINDOW_SIZE - 1)) + 1),
min_t(u32, size, ACE_WINDOW_SIZE));
tdest = (void __iomem *) &regs->Window +
(dest & (ACE_WINDOW_SIZE - 1));
writel(dest & ~(ACE_WINDOW_SIZE - 1), &regs->WinBase);
for (i = 0; i < (tsize / 4); i++) {
writel(be32_to_cpup(src), tdest);
src++;
tdest += 4;
dest += 4;
size -= 4;
}
}
}
static void __devinit ace_clear(struct ace_regs __iomem *regs, u32 dest, int size)
{
void __iomem *tdest;
short tsize = 0, i;
if (size <= 0)
return;
while (size > 0) {
tsize = min_t(u32, ((~dest & (ACE_WINDOW_SIZE - 1)) + 1),
min_t(u32, size, ACE_WINDOW_SIZE));
tdest = (void __iomem *) &regs->Window +
(dest & (ACE_WINDOW_SIZE - 1));
writel(dest & ~(ACE_WINDOW_SIZE - 1), &regs->WinBase);
for (i = 0; i < (tsize / 4); i++) {
writel(0, tdest + i*4);
}
dest += tsize;
size -= tsize;
}
}
static int __devinit ace_load_firmware(struct net_device *dev)
{
const struct firmware *fw;
const char *fw_name = "acenic/tg2.bin";
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
const __be32 *fw_data;
u32 load_addr;
int ret;
if (!(readl(&regs->CpuCtrl) & CPU_HALTED)) {
printk(KERN_ERR "%s: trying to download firmware while the "
"CPU is running!\n", ap->name);
return -EFAULT;
}
if (ACE_IS_TIGON_I(ap))
fw_name = "acenic/tg1.bin";
ret = request_firmware(&fw, fw_name, &ap->pdev->dev);
if (ret) {
printk(KERN_ERR "%s: Failed to load firmware \"%s\"\n",
ap->name, fw_name);
return ret;
}
fw_data = (void *)fw->data;
ap->firmware_major = fw->data[0];
ap->firmware_minor = fw->data[1];
ap->firmware_fix = fw->data[2];
ap->firmware_start = be32_to_cpu(fw_data[1]);
if (ap->firmware_start < 0x4000 || ap->firmware_start >= 0x80000) {
printk(KERN_ERR "%s: bogus load address %08x in \"%s\"\n",
ap->name, ap->firmware_start, fw_name);
ret = -EINVAL;
goto out;
}
load_addr = be32_to_cpu(fw_data[2]);
if (load_addr < 0x4000 || load_addr >= 0x80000) {
printk(KERN_ERR "%s: bogus load address %08x in \"%s\"\n",
ap->name, load_addr, fw_name);
ret = -EINVAL;
goto out;
}
ace_clear(regs, 0x2000, 0x80000-0x2000);
ace_copy(regs, &fw_data[3], load_addr, fw->size-12);
out:
release_firmware(fw);
return ret;
}
static void __devinit eeprom_start(struct ace_regs __iomem *regs)
{
u32 local;
readl(&regs->LocalCtrl);
udelay(ACE_SHORT_DELAY);
local = readl(&regs->LocalCtrl);
local |= EEPROM_DATA_OUT | EEPROM_WRITE_ENABLE;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
local |= EEPROM_CLK_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
local &= ~EEPROM_DATA_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
local &= ~EEPROM_CLK_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
}
static void __devinit eeprom_prep(struct ace_regs __iomem *regs, u8 magic)
{
short i;
u32 local;
udelay(ACE_SHORT_DELAY);
local = readl(&regs->LocalCtrl);
local &= ~EEPROM_DATA_OUT;
local |= EEPROM_WRITE_ENABLE;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
for (i = 0; i < 8; i++, magic <<= 1) {
udelay(ACE_SHORT_DELAY);
if (magic & 0x80)
local |= EEPROM_DATA_OUT;
else
local &= ~EEPROM_DATA_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
local |= EEPROM_CLK_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
local &= ~(EEPROM_CLK_OUT | EEPROM_DATA_OUT);
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
}
}
static int __devinit eeprom_check_ack(struct ace_regs __iomem *regs)
{
int state;
u32 local;
local = readl(&regs->LocalCtrl);
local &= ~EEPROM_WRITE_ENABLE;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_LONG_DELAY);
local |= EEPROM_CLK_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
state = (readl(&regs->LocalCtrl) & EEPROM_DATA_IN) != 0;
udelay(ACE_SHORT_DELAY);
mb();
writel(readl(&regs->LocalCtrl) & ~EEPROM_CLK_OUT, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
return state;
}
static void __devinit eeprom_stop(struct ace_regs __iomem *regs)
{
u32 local;
udelay(ACE_SHORT_DELAY);
local = readl(&regs->LocalCtrl);
local |= EEPROM_WRITE_ENABLE;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
local &= ~EEPROM_DATA_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
local |= EEPROM_CLK_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
local |= EEPROM_DATA_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_LONG_DELAY);
local &= ~EEPROM_CLK_OUT;
writel(local, &regs->LocalCtrl);
mb();
}
static int __devinit read_eeprom_byte(struct net_device *dev,
unsigned long offset)
{
struct ace_private *ap = netdev_priv(dev);
struct ace_regs __iomem *regs = ap->regs;
unsigned long flags;
u32 local;
int result = 0;
short i;
local_irq_save(flags);
eeprom_start(regs);
eeprom_prep(regs, EEPROM_WRITE_SELECT);
if (eeprom_check_ack(regs)) {
local_irq_restore(flags);
printk(KERN_ERR "%s: Unable to sync eeprom\n", ap->name);
result = -EIO;
goto eeprom_read_error;
}
eeprom_prep(regs, (offset >> 8) & 0xff);
if (eeprom_check_ack(regs)) {
local_irq_restore(flags);
printk(KERN_ERR "%s: Unable to set address byte 0\n",
ap->name);
result = -EIO;
goto eeprom_read_error;
}
eeprom_prep(regs, offset & 0xff);
if (eeprom_check_ack(regs)) {
local_irq_restore(flags);
printk(KERN_ERR "%s: Unable to set address byte 1\n",
ap->name);
result = -EIO;
goto eeprom_read_error;
}
eeprom_start(regs);
eeprom_prep(regs, EEPROM_READ_SELECT);
if (eeprom_check_ack(regs)) {
local_irq_restore(flags);
printk(KERN_ERR "%s: Unable to set READ_SELECT\n",
ap->name);
result = -EIO;
goto eeprom_read_error;
}
for (i = 0; i < 8; i++) {
local = readl(&regs->LocalCtrl);
local &= ~EEPROM_WRITE_ENABLE;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
udelay(ACE_LONG_DELAY);
mb();
local |= EEPROM_CLK_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
result = (result << 1) |
((readl(&regs->LocalCtrl) & EEPROM_DATA_IN) != 0);
udelay(ACE_SHORT_DELAY);
mb();
local = readl(&regs->LocalCtrl);
local &= ~EEPROM_CLK_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
udelay(ACE_SHORT_DELAY);
mb();
if (i == 7) {
local |= EEPROM_WRITE_ENABLE;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
}
}
local |= EEPROM_DATA_OUT;
writel(local, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
writel(readl(&regs->LocalCtrl) | EEPROM_CLK_OUT, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
udelay(ACE_LONG_DELAY);
writel(readl(&regs->LocalCtrl) & ~EEPROM_CLK_OUT, &regs->LocalCtrl);
readl(&regs->LocalCtrl);
mb();
udelay(ACE_SHORT_DELAY);
eeprom_stop(regs);
local_irq_restore(flags);
out:
return result;
eeprom_read_error:
printk(KERN_ERR "%s: Unable to read eeprom byte 0x%02lx\n",
ap->name, offset);
goto out;
}
