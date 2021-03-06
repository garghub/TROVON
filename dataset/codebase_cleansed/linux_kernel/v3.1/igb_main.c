static void igb_regdump(struct e1000_hw *hw, struct igb_reg_info *reginfo)
{
int n = 0;
char rname[16];
u32 regs[8];
switch (reginfo->ofs) {
case E1000_RDLEN(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_RDLEN(n));
break;
case E1000_RDH(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_RDH(n));
break;
case E1000_RDT(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_RDT(n));
break;
case E1000_RXDCTL(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_RXDCTL(n));
break;
case E1000_RDBAL(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_RDBAL(n));
break;
case E1000_RDBAH(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_RDBAH(n));
break;
case E1000_TDBAL(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_RDBAL(n));
break;
case E1000_TDBAH(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_TDBAH(n));
break;
case E1000_TDLEN(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_TDLEN(n));
break;
case E1000_TDH(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_TDH(n));
break;
case E1000_TDT(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_TDT(n));
break;
case E1000_TXDCTL(0):
for (n = 0; n < 4; n++)
regs[n] = rd32(E1000_TXDCTL(n));
break;
default:
printk(KERN_INFO "%-15s %08x\n",
reginfo->name, rd32(reginfo->ofs));
return;
}
snprintf(rname, 16, "%s%s", reginfo->name, "[0-3]");
printk(KERN_INFO "%-15s ", rname);
for (n = 0; n < 4; n++)
printk(KERN_CONT "%08x ", regs[n]);
printk(KERN_CONT "\n");
}
static void igb_dump(struct igb_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct e1000_hw *hw = &adapter->hw;
struct igb_reg_info *reginfo;
int n = 0;
struct igb_ring *tx_ring;
union e1000_adv_tx_desc *tx_desc;
struct my_u0 { u64 a; u64 b; } *u0;
struct igb_buffer *buffer_info;
struct igb_ring *rx_ring;
union e1000_adv_rx_desc *rx_desc;
u32 staterr;
int i = 0;
if (!netif_msg_hw(adapter))
return;
if (netdev) {
dev_info(&adapter->pdev->dev, "Net device Info\n");
printk(KERN_INFO "Device Name state "
"trans_start last_rx\n");
printk(KERN_INFO "%-15s %016lX %016lX %016lX\n",
netdev->name,
netdev->state,
netdev->trans_start,
netdev->last_rx);
}
dev_info(&adapter->pdev->dev, "Register Dump\n");
printk(KERN_INFO " Register Name Value\n");
for (reginfo = (struct igb_reg_info *)igb_reg_info_tbl;
reginfo->name; reginfo++) {
igb_regdump(hw, reginfo);
}
if (!netdev || !netif_running(netdev))
goto exit;
dev_info(&adapter->pdev->dev, "TX Rings Summary\n");
printk(KERN_INFO "Queue [NTU] [NTC] [bi(ntc)->dma ]"
" leng ntw timestamp\n");
for (n = 0; n < adapter->num_tx_queues; n++) {
tx_ring = adapter->tx_ring[n];
buffer_info = &tx_ring->buffer_info[tx_ring->next_to_clean];
printk(KERN_INFO " %5d %5X %5X %016llX %04X %3X %016llX\n",
n, tx_ring->next_to_use, tx_ring->next_to_clean,
(u64)buffer_info->dma,
buffer_info->length,
buffer_info->next_to_watch,
(u64)buffer_info->time_stamp);
}
if (!netif_msg_tx_done(adapter))
goto rx_ring_summary;
dev_info(&adapter->pdev->dev, "TX Rings Dump\n");
for (n = 0; n < adapter->num_tx_queues; n++) {
tx_ring = adapter->tx_ring[n];
printk(KERN_INFO "------------------------------------\n");
printk(KERN_INFO "TX QUEUE INDEX = %d\n", tx_ring->queue_index);
printk(KERN_INFO "------------------------------------\n");
printk(KERN_INFO "T [desc] [address 63:0 ] "
"[PlPOCIStDDM Ln] [bi->dma ] "
"leng ntw timestamp bi->skb\n");
for (i = 0; tx_ring->desc && (i < tx_ring->count); i++) {
tx_desc = E1000_TX_DESC_ADV(*tx_ring, i);
buffer_info = &tx_ring->buffer_info[i];
u0 = (struct my_u0 *)tx_desc;
printk(KERN_INFO "T [0x%03X] %016llX %016llX %016llX"
" %04X %3X %016llX %p", i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
(u64)buffer_info->dma,
buffer_info->length,
buffer_info->next_to_watch,
(u64)buffer_info->time_stamp,
buffer_info->skb);
if (i == tx_ring->next_to_use &&
i == tx_ring->next_to_clean)
printk(KERN_CONT " NTC/U\n");
else if (i == tx_ring->next_to_use)
printk(KERN_CONT " NTU\n");
else if (i == tx_ring->next_to_clean)
printk(KERN_CONT " NTC\n");
else
printk(KERN_CONT "\n");
if (netif_msg_pktdata(adapter) && buffer_info->dma != 0)
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS,
16, 1, phys_to_virt(buffer_info->dma),
buffer_info->length, true);
}
}
rx_ring_summary:
dev_info(&adapter->pdev->dev, "RX Rings Summary\n");
printk(KERN_INFO "Queue [NTU] [NTC]\n");
for (n = 0; n < adapter->num_rx_queues; n++) {
rx_ring = adapter->rx_ring[n];
printk(KERN_INFO " %5d %5X %5X\n", n,
rx_ring->next_to_use, rx_ring->next_to_clean);
}
if (!netif_msg_rx_status(adapter))
goto exit;
dev_info(&adapter->pdev->dev, "RX Rings Dump\n");
for (n = 0; n < adapter->num_rx_queues; n++) {
rx_ring = adapter->rx_ring[n];
printk(KERN_INFO "------------------------------------\n");
printk(KERN_INFO "RX QUEUE INDEX = %d\n", rx_ring->queue_index);
printk(KERN_INFO "------------------------------------\n");
printk(KERN_INFO "R [desc] [ PktBuf A0] "
"[ HeadBuf DD] [bi->dma ] [bi->skb] "
"<-- Adv Rx Read format\n");
printk(KERN_INFO "RWB[desc] [PcsmIpSHl PtRs] "
"[vl er S cks ln] ---------------- [bi->skb] "
"<-- Adv Rx Write-Back format\n");
for (i = 0; i < rx_ring->count; i++) {
buffer_info = &rx_ring->buffer_info[i];
rx_desc = E1000_RX_DESC_ADV(*rx_ring, i);
u0 = (struct my_u0 *)rx_desc;
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
if (staterr & E1000_RXD_STAT_DD) {
printk(KERN_INFO "RWB[0x%03X] %016llX "
"%016llX ---------------- %p", i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
buffer_info->skb);
} else {
printk(KERN_INFO "R [0x%03X] %016llX "
"%016llX %016llX %p", i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
(u64)buffer_info->dma,
buffer_info->skb);
if (netif_msg_pktdata(adapter)) {
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS,
16, 1,
phys_to_virt(buffer_info->dma),
rx_ring->rx_buffer_len, true);
if (rx_ring->rx_buffer_len
< IGB_RXBUFFER_1024)
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS,
16, 1,
phys_to_virt(
buffer_info->page_dma +
buffer_info->page_offset),
PAGE_SIZE/2, true);
}
}
if (i == rx_ring->next_to_use)
printk(KERN_CONT " NTU\n");
else if (i == rx_ring->next_to_clean)
printk(KERN_CONT " NTC\n");
else
printk(KERN_CONT "\n");
}
}
exit:
return;
}
static cycle_t igb_read_clock(const struct cyclecounter *tc)
{
struct igb_adapter *adapter =
container_of(tc, struct igb_adapter, cycles);
struct e1000_hw *hw = &adapter->hw;
u64 stamp = 0;
int shift = 0;
if (hw->mac.type == e1000_82580) {
stamp = rd32(E1000_SYSTIMR) >> 8;
shift = IGB_82580_TSYNC_SHIFT;
}
stamp |= (u64)rd32(E1000_SYSTIML) << shift;
stamp |= (u64)rd32(E1000_SYSTIMH) << (shift + 32);
return stamp;
}
struct net_device *igb_get_hw_dev(struct e1000_hw *hw)
{
struct igb_adapter *adapter = hw->back;
return adapter->netdev;
}
static int __init igb_init_module(void)
{
int ret;
printk(KERN_INFO "%s - version %s\n",
igb_driver_string, igb_driver_version);
printk(KERN_INFO "%s\n", igb_copyright);
#ifdef CONFIG_IGB_DCA
dca_register_notify(&dca_notifier);
#endif
ret = pci_register_driver(&igb_driver);
return ret;
}
static void __exit igb_exit_module(void)
{
#ifdef CONFIG_IGB_DCA
dca_unregister_notify(&dca_notifier);
#endif
pci_unregister_driver(&igb_driver);
}
static void igb_cache_ring_register(struct igb_adapter *adapter)
{
int i = 0, j = 0;
u32 rbase_offset = adapter->vfs_allocated_count;
switch (adapter->hw.mac.type) {
case e1000_82576:
if (adapter->vfs_allocated_count) {
for (; i < adapter->rss_queues; i++)
adapter->rx_ring[i]->reg_idx = rbase_offset +
Q_IDX_82576(i);
}
case e1000_82575:
case e1000_82580:
case e1000_i350:
default:
for (; i < adapter->num_rx_queues; i++)
adapter->rx_ring[i]->reg_idx = rbase_offset + i;
for (; j < adapter->num_tx_queues; j++)
adapter->tx_ring[j]->reg_idx = rbase_offset + j;
break;
}
}
static void igb_free_queues(struct igb_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++) {
kfree(adapter->tx_ring[i]);
adapter->tx_ring[i] = NULL;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
kfree(adapter->rx_ring[i]);
adapter->rx_ring[i] = NULL;
}
adapter->num_rx_queues = 0;
adapter->num_tx_queues = 0;
}
static int igb_alloc_queues(struct igb_adapter *adapter)
{
struct igb_ring *ring;
int i;
for (i = 0; i < adapter->num_tx_queues; i++) {
ring = kzalloc(sizeof(struct igb_ring), GFP_KERNEL);
if (!ring)
goto err;
ring->count = adapter->tx_ring_count;
ring->queue_index = i;
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
if (adapter->hw.mac.type == e1000_82575)
ring->flags = IGB_RING_FLAG_TX_CTX_IDX;
adapter->tx_ring[i] = ring;
}
for (i = 0; i < adapter->num_rx_queues; i++) {
ring = kzalloc(sizeof(struct igb_ring), GFP_KERNEL);
if (!ring)
goto err;
ring->count = adapter->rx_ring_count;
ring->queue_index = i;
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
ring->rx_buffer_len = MAXIMUM_ETHERNET_VLAN_SIZE;
ring->flags = IGB_RING_FLAG_RX_CSUM;
if (adapter->hw.mac.type >= e1000_82576)
ring->flags |= IGB_RING_FLAG_RX_SCTP_CSUM;
adapter->rx_ring[i] = ring;
}
igb_cache_ring_register(adapter);
return 0;
err:
igb_free_queues(adapter);
return -ENOMEM;
}
static void igb_assign_vector(struct igb_q_vector *q_vector, int msix_vector)
{
u32 msixbm = 0;
struct igb_adapter *adapter = q_vector->adapter;
struct e1000_hw *hw = &adapter->hw;
u32 ivar, index;
int rx_queue = IGB_N0_QUEUE;
int tx_queue = IGB_N0_QUEUE;
if (q_vector->rx_ring)
rx_queue = q_vector->rx_ring->reg_idx;
if (q_vector->tx_ring)
tx_queue = q_vector->tx_ring->reg_idx;
switch (hw->mac.type) {
case e1000_82575:
if (rx_queue > IGB_N0_QUEUE)
msixbm = E1000_EICR_RX_QUEUE0 << rx_queue;
if (tx_queue > IGB_N0_QUEUE)
msixbm |= E1000_EICR_TX_QUEUE0 << tx_queue;
if (!adapter->msix_entries && msix_vector == 0)
msixbm |= E1000_EIMS_OTHER;
array_wr32(E1000_MSIXBM(0), msix_vector, msixbm);
q_vector->eims_value = msixbm;
break;
case e1000_82576:
if (rx_queue > IGB_N0_QUEUE) {
index = (rx_queue & 0x7);
ivar = array_rd32(E1000_IVAR0, index);
if (rx_queue < 8) {
ivar = ivar & 0xFFFFFF00;
ivar |= msix_vector | E1000_IVAR_VALID;
} else {
ivar = ivar & 0xFF00FFFF;
ivar |= (msix_vector | E1000_IVAR_VALID) << 16;
}
array_wr32(E1000_IVAR0, index, ivar);
}
if (tx_queue > IGB_N0_QUEUE) {
index = (tx_queue & 0x7);
ivar = array_rd32(E1000_IVAR0, index);
if (tx_queue < 8) {
ivar = ivar & 0xFFFF00FF;
ivar |= (msix_vector | E1000_IVAR_VALID) << 8;
} else {
ivar = ivar & 0x00FFFFFF;
ivar |= (msix_vector | E1000_IVAR_VALID) << 24;
}
array_wr32(E1000_IVAR0, index, ivar);
}
q_vector->eims_value = 1 << msix_vector;
break;
case e1000_82580:
case e1000_i350:
if (rx_queue > IGB_N0_QUEUE) {
index = (rx_queue >> 1);
ivar = array_rd32(E1000_IVAR0, index);
if (rx_queue & 0x1) {
ivar = ivar & 0xFF00FFFF;
ivar |= (msix_vector | E1000_IVAR_VALID) << 16;
} else {
ivar = ivar & 0xFFFFFF00;
ivar |= msix_vector | E1000_IVAR_VALID;
}
array_wr32(E1000_IVAR0, index, ivar);
}
if (tx_queue > IGB_N0_QUEUE) {
index = (tx_queue >> 1);
ivar = array_rd32(E1000_IVAR0, index);
if (tx_queue & 0x1) {
ivar = ivar & 0x00FFFFFF;
ivar |= (msix_vector | E1000_IVAR_VALID) << 24;
} else {
ivar = ivar & 0xFFFF00FF;
ivar |= (msix_vector | E1000_IVAR_VALID) << 8;
}
array_wr32(E1000_IVAR0, index, ivar);
}
q_vector->eims_value = 1 << msix_vector;
break;
default:
BUG();
break;
}
adapter->eims_enable_mask |= q_vector->eims_value;
q_vector->set_itr = 1;
}
static void igb_configure_msix(struct igb_adapter *adapter)
{
u32 tmp;
int i, vector = 0;
struct e1000_hw *hw = &adapter->hw;
adapter->eims_enable_mask = 0;
switch (hw->mac.type) {
case e1000_82575:
tmp = rd32(E1000_CTRL_EXT);
tmp |= E1000_CTRL_EXT_PBA_CLR;
tmp |= E1000_CTRL_EXT_EIAME;
tmp |= E1000_CTRL_EXT_IRCA;
wr32(E1000_CTRL_EXT, tmp);
array_wr32(E1000_MSIXBM(0), vector++,
E1000_EIMS_OTHER);
adapter->eims_other = E1000_EIMS_OTHER;
break;
case e1000_82576:
case e1000_82580:
case e1000_i350:
wr32(E1000_GPIE, E1000_GPIE_MSIX_MODE |
E1000_GPIE_PBA | E1000_GPIE_EIAME |
E1000_GPIE_NSICR);
adapter->eims_other = 1 << vector;
tmp = (vector++ | E1000_IVAR_VALID) << 8;
wr32(E1000_IVAR_MISC, tmp);
break;
default:
break;
}
adapter->eims_enable_mask |= adapter->eims_other;
for (i = 0; i < adapter->num_q_vectors; i++)
igb_assign_vector(adapter->q_vector[i], vector++);
wrfl();
}
static int igb_request_msix(struct igb_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct e1000_hw *hw = &adapter->hw;
int i, err = 0, vector = 0;
err = request_irq(adapter->msix_entries[vector].vector,
igb_msix_other, 0, netdev->name, adapter);
if (err)
goto out;
vector++;
for (i = 0; i < adapter->num_q_vectors; i++) {
struct igb_q_vector *q_vector = adapter->q_vector[i];
q_vector->itr_register = hw->hw_addr + E1000_EITR(vector);
if (q_vector->rx_ring && q_vector->tx_ring)
sprintf(q_vector->name, "%s-TxRx-%u", netdev->name,
q_vector->rx_ring->queue_index);
else if (q_vector->tx_ring)
sprintf(q_vector->name, "%s-tx-%u", netdev->name,
q_vector->tx_ring->queue_index);
else if (q_vector->rx_ring)
sprintf(q_vector->name, "%s-rx-%u", netdev->name,
q_vector->rx_ring->queue_index);
else
sprintf(q_vector->name, "%s-unused", netdev->name);
err = request_irq(adapter->msix_entries[vector].vector,
igb_msix_ring, 0, q_vector->name,
q_vector);
if (err)
goto out;
vector++;
}
igb_configure_msix(adapter);
return 0;
out:
return err;
}
static void igb_reset_interrupt_capability(struct igb_adapter *adapter)
{
if (adapter->msix_entries) {
pci_disable_msix(adapter->pdev);
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
} else if (adapter->flags & IGB_FLAG_HAS_MSI) {
pci_disable_msi(adapter->pdev);
}
}
static void igb_free_q_vectors(struct igb_adapter *adapter)
{
int v_idx;
for (v_idx = 0; v_idx < adapter->num_q_vectors; v_idx++) {
struct igb_q_vector *q_vector = adapter->q_vector[v_idx];
adapter->q_vector[v_idx] = NULL;
if (!q_vector)
continue;
netif_napi_del(&q_vector->napi);
kfree(q_vector);
}
adapter->num_q_vectors = 0;
}
static void igb_clear_interrupt_scheme(struct igb_adapter *adapter)
{
igb_free_queues(adapter);
igb_free_q_vectors(adapter);
igb_reset_interrupt_capability(adapter);
}
static int igb_set_interrupt_capability(struct igb_adapter *adapter)
{
int err;
int numvecs, i;
adapter->num_rx_queues = adapter->rss_queues;
if (adapter->vfs_allocated_count)
adapter->num_tx_queues = 1;
else
adapter->num_tx_queues = adapter->rss_queues;
numvecs = adapter->num_rx_queues;
if (!(adapter->flags & IGB_FLAG_QUEUE_PAIRS))
numvecs += adapter->num_tx_queues;
adapter->num_q_vectors = numvecs;
numvecs++;
adapter->msix_entries = kcalloc(numvecs, sizeof(struct msix_entry),
GFP_KERNEL);
if (!adapter->msix_entries)
goto msi_only;
for (i = 0; i < numvecs; i++)
adapter->msix_entries[i].entry = i;
err = pci_enable_msix(adapter->pdev,
adapter->msix_entries,
numvecs);
if (err == 0)
goto out;
igb_reset_interrupt_capability(adapter);
msi_only:
#ifdef CONFIG_PCI_IOV
if (adapter->vf_data) {
struct e1000_hw *hw = &adapter->hw;
pci_disable_sriov(adapter->pdev);
msleep(500);
kfree(adapter->vf_data);
adapter->vf_data = NULL;
wr32(E1000_IOVCTL, E1000_IOVCTL_REUSE_VFQ);
wrfl();
msleep(100);
dev_info(&adapter->pdev->dev, "IOV Disabled\n");
}
#endif
adapter->vfs_allocated_count = 0;
adapter->rss_queues = 1;
adapter->flags |= IGB_FLAG_QUEUE_PAIRS;
adapter->num_rx_queues = 1;
adapter->num_tx_queues = 1;
adapter->num_q_vectors = 1;
if (!pci_enable_msi(adapter->pdev))
adapter->flags |= IGB_FLAG_HAS_MSI;
out:
netif_set_real_num_tx_queues(adapter->netdev, adapter->num_tx_queues);
return netif_set_real_num_rx_queues(adapter->netdev,
adapter->num_rx_queues);
}
static int igb_alloc_q_vectors(struct igb_adapter *adapter)
{
struct igb_q_vector *q_vector;
struct e1000_hw *hw = &adapter->hw;
int v_idx;
for (v_idx = 0; v_idx < adapter->num_q_vectors; v_idx++) {
q_vector = kzalloc(sizeof(struct igb_q_vector), GFP_KERNEL);
if (!q_vector)
goto err_out;
q_vector->adapter = adapter;
q_vector->itr_register = hw->hw_addr + E1000_EITR(0);
q_vector->itr_val = IGB_START_ITR;
netif_napi_add(adapter->netdev, &q_vector->napi, igb_poll, 64);
adapter->q_vector[v_idx] = q_vector;
}
return 0;
err_out:
igb_free_q_vectors(adapter);
return -ENOMEM;
}
static void igb_map_rx_ring_to_vector(struct igb_adapter *adapter,
int ring_idx, int v_idx)
{
struct igb_q_vector *q_vector = adapter->q_vector[v_idx];
q_vector->rx_ring = adapter->rx_ring[ring_idx];
q_vector->rx_ring->q_vector = q_vector;
q_vector->itr_val = adapter->rx_itr_setting;
if (q_vector->itr_val && q_vector->itr_val <= 3)
q_vector->itr_val = IGB_START_ITR;
}
static void igb_map_tx_ring_to_vector(struct igb_adapter *adapter,
int ring_idx, int v_idx)
{
struct igb_q_vector *q_vector = adapter->q_vector[v_idx];
q_vector->tx_ring = adapter->tx_ring[ring_idx];
q_vector->tx_ring->q_vector = q_vector;
q_vector->itr_val = adapter->tx_itr_setting;
if (q_vector->itr_val && q_vector->itr_val <= 3)
q_vector->itr_val = IGB_START_ITR;
}
static int igb_map_ring_to_vector(struct igb_adapter *adapter)
{
int i;
int v_idx = 0;
if ((adapter->num_q_vectors < adapter->num_rx_queues) ||
(adapter->num_q_vectors < adapter->num_tx_queues))
return -ENOMEM;
if (adapter->num_q_vectors >=
(adapter->num_rx_queues + adapter->num_tx_queues)) {
for (i = 0; i < adapter->num_rx_queues; i++)
igb_map_rx_ring_to_vector(adapter, i, v_idx++);
for (i = 0; i < adapter->num_tx_queues; i++)
igb_map_tx_ring_to_vector(adapter, i, v_idx++);
} else {
for (i = 0; i < adapter->num_rx_queues; i++) {
if (i < adapter->num_tx_queues)
igb_map_tx_ring_to_vector(adapter, i, v_idx);
igb_map_rx_ring_to_vector(adapter, i, v_idx++);
}
for (; i < adapter->num_tx_queues; i++)
igb_map_tx_ring_to_vector(adapter, i, v_idx++);
}
return 0;
}
static int igb_init_interrupt_scheme(struct igb_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
int err;
err = igb_set_interrupt_capability(adapter);
if (err)
return err;
err = igb_alloc_q_vectors(adapter);
if (err) {
dev_err(&pdev->dev, "Unable to allocate memory for vectors\n");
goto err_alloc_q_vectors;
}
err = igb_alloc_queues(adapter);
if (err) {
dev_err(&pdev->dev, "Unable to allocate memory for queues\n");
goto err_alloc_queues;
}
err = igb_map_ring_to_vector(adapter);
if (err) {
dev_err(&pdev->dev, "Invalid q_vector to ring mapping\n");
goto err_map_queues;
}
return 0;
err_map_queues:
igb_free_queues(adapter);
err_alloc_queues:
igb_free_q_vectors(adapter);
err_alloc_q_vectors:
igb_reset_interrupt_capability(adapter);
return err;
}
static int igb_request_irq(struct igb_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct pci_dev *pdev = adapter->pdev;
int err = 0;
if (adapter->msix_entries) {
err = igb_request_msix(adapter);
if (!err)
goto request_done;
igb_clear_interrupt_scheme(adapter);
if (!pci_enable_msi(adapter->pdev))
adapter->flags |= IGB_FLAG_HAS_MSI;
igb_free_all_tx_resources(adapter);
igb_free_all_rx_resources(adapter);
adapter->num_tx_queues = 1;
adapter->num_rx_queues = 1;
adapter->num_q_vectors = 1;
err = igb_alloc_q_vectors(adapter);
if (err) {
dev_err(&pdev->dev,
"Unable to allocate memory for vectors\n");
goto request_done;
}
err = igb_alloc_queues(adapter);
if (err) {
dev_err(&pdev->dev,
"Unable to allocate memory for queues\n");
igb_free_q_vectors(adapter);
goto request_done;
}
igb_setup_all_tx_resources(adapter);
igb_setup_all_rx_resources(adapter);
} else {
igb_assign_vector(adapter->q_vector[0], 0);
}
if (adapter->flags & IGB_FLAG_HAS_MSI) {
err = request_irq(adapter->pdev->irq, igb_intr_msi, 0,
netdev->name, adapter);
if (!err)
goto request_done;
igb_reset_interrupt_capability(adapter);
adapter->flags &= ~IGB_FLAG_HAS_MSI;
}
err = request_irq(adapter->pdev->irq, igb_intr, IRQF_SHARED,
netdev->name, adapter);
if (err)
dev_err(&adapter->pdev->dev, "Error %d getting interrupt\n",
err);
request_done:
return err;
}
static void igb_free_irq(struct igb_adapter *adapter)
{
if (adapter->msix_entries) {
int vector = 0, i;
free_irq(adapter->msix_entries[vector++].vector, adapter);
for (i = 0; i < adapter->num_q_vectors; i++) {
struct igb_q_vector *q_vector = adapter->q_vector[i];
free_irq(adapter->msix_entries[vector++].vector,
q_vector);
}
} else {
free_irq(adapter->pdev->irq, adapter);
}
}
static void igb_irq_disable(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
if (adapter->msix_entries) {
u32 regval = rd32(E1000_EIAM);
wr32(E1000_EIAM, regval & ~adapter->eims_enable_mask);
wr32(E1000_EIMC, adapter->eims_enable_mask);
regval = rd32(E1000_EIAC);
wr32(E1000_EIAC, regval & ~adapter->eims_enable_mask);
}
wr32(E1000_IAM, 0);
wr32(E1000_IMC, ~0);
wrfl();
if (adapter->msix_entries) {
int i;
for (i = 0; i < adapter->num_q_vectors; i++)
synchronize_irq(adapter->msix_entries[i].vector);
} else {
synchronize_irq(adapter->pdev->irq);
}
}
static void igb_irq_enable(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
if (adapter->msix_entries) {
u32 ims = E1000_IMS_LSC | E1000_IMS_DOUTSYNC;
u32 regval = rd32(E1000_EIAC);
wr32(E1000_EIAC, regval | adapter->eims_enable_mask);
regval = rd32(E1000_EIAM);
wr32(E1000_EIAM, regval | adapter->eims_enable_mask);
wr32(E1000_EIMS, adapter->eims_enable_mask);
if (adapter->vfs_allocated_count) {
wr32(E1000_MBVFIMR, 0xFF);
ims |= E1000_IMS_VMMB;
}
if (adapter->hw.mac.type == e1000_82580)
ims |= E1000_IMS_DRSTA;
wr32(E1000_IMS, ims);
} else {
wr32(E1000_IMS, IMS_ENABLE_MASK |
E1000_IMS_DRSTA);
wr32(E1000_IAM, IMS_ENABLE_MASK |
E1000_IMS_DRSTA);
}
}
static void igb_update_mng_vlan(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u16 vid = adapter->hw.mng_cookie.vlan_id;
u16 old_vid = adapter->mng_vlan_id;
if (hw->mng_cookie.status & E1000_MNG_DHCP_COOKIE_STATUS_VLAN) {
igb_vfta_set(hw, vid, true);
adapter->mng_vlan_id = vid;
} else {
adapter->mng_vlan_id = IGB_MNG_VLAN_NONE;
}
if ((old_vid != (u16)IGB_MNG_VLAN_NONE) &&
(vid != old_vid) &&
!test_bit(old_vid, adapter->active_vlans)) {
igb_vfta_set(hw, old_vid, false);
}
}
static void igb_release_hw_control(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 ctrl_ext;
ctrl_ext = rd32(E1000_CTRL_EXT);
wr32(E1000_CTRL_EXT,
ctrl_ext & ~E1000_CTRL_EXT_DRV_LOAD);
}
static void igb_get_hw_control(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 ctrl_ext;
ctrl_ext = rd32(E1000_CTRL_EXT);
wr32(E1000_CTRL_EXT,
ctrl_ext | E1000_CTRL_EXT_DRV_LOAD);
}
static void igb_configure(struct igb_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int i;
igb_get_hw_control(adapter);
igb_set_rx_mode(netdev);
igb_restore_vlan(adapter);
igb_setup_tctl(adapter);
igb_setup_mrqc(adapter);
igb_setup_rctl(adapter);
igb_configure_tx(adapter);
igb_configure_rx(adapter);
igb_rx_fifo_flush_82575(&adapter->hw);
for (i = 0; i < adapter->num_rx_queues; i++) {
struct igb_ring *ring = adapter->rx_ring[i];
igb_alloc_rx_buffers_adv(ring, igb_desc_unused(ring));
}
}
void igb_power_up_link(struct igb_adapter *adapter)
{
if (adapter->hw.phy.media_type == e1000_media_type_copper)
igb_power_up_phy_copper(&adapter->hw);
else
igb_power_up_serdes_link_82575(&adapter->hw);
}
static void igb_power_down_link(struct igb_adapter *adapter)
{
if (adapter->hw.phy.media_type == e1000_media_type_copper)
igb_power_down_phy_copper_82575(&adapter->hw);
else
igb_shutdown_serdes_link_82575(&adapter->hw);
}
int igb_up(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
int i;
igb_configure(adapter);
clear_bit(__IGB_DOWN, &adapter->state);
for (i = 0; i < adapter->num_q_vectors; i++) {
struct igb_q_vector *q_vector = adapter->q_vector[i];
napi_enable(&q_vector->napi);
}
if (adapter->msix_entries)
igb_configure_msix(adapter);
else
igb_assign_vector(adapter->q_vector[0], 0);
rd32(E1000_ICR);
igb_irq_enable(adapter);
if (adapter->vfs_allocated_count) {
u32 reg_data = rd32(E1000_CTRL_EXT);
reg_data |= E1000_CTRL_EXT_PFRSTD;
wr32(E1000_CTRL_EXT, reg_data);
}
netif_tx_start_all_queues(adapter->netdev);
hw->mac.get_link_status = 1;
schedule_work(&adapter->watchdog_task);
return 0;
}
void igb_down(struct igb_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct e1000_hw *hw = &adapter->hw;
u32 tctl, rctl;
int i;
set_bit(__IGB_DOWN, &adapter->state);
rctl = rd32(E1000_RCTL);
wr32(E1000_RCTL, rctl & ~E1000_RCTL_EN);
netif_tx_stop_all_queues(netdev);
tctl = rd32(E1000_TCTL);
tctl &= ~E1000_TCTL_EN;
wr32(E1000_TCTL, tctl);
wrfl();
msleep(10);
for (i = 0; i < adapter->num_q_vectors; i++) {
struct igb_q_vector *q_vector = adapter->q_vector[i];
napi_disable(&q_vector->napi);
}
igb_irq_disable(adapter);
del_timer_sync(&adapter->watchdog_timer);
del_timer_sync(&adapter->phy_info_timer);
netif_carrier_off(netdev);
spin_lock(&adapter->stats64_lock);
igb_update_stats(adapter, &adapter->stats64);
spin_unlock(&adapter->stats64_lock);
adapter->link_speed = 0;
adapter->link_duplex = 0;
if (!pci_channel_offline(adapter->pdev))
igb_reset(adapter);
igb_clean_all_tx_rings(adapter);
igb_clean_all_rx_rings(adapter);
#ifdef CONFIG_IGB_DCA
igb_setup_dca(adapter);
#endif
}
void igb_reinit_locked(struct igb_adapter *adapter)
{
WARN_ON(in_interrupt());
while (test_and_set_bit(__IGB_RESETTING, &adapter->state))
msleep(1);
igb_down(adapter);
igb_up(adapter);
clear_bit(__IGB_RESETTING, &adapter->state);
}
void igb_reset(struct igb_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
struct e1000_hw *hw = &adapter->hw;
struct e1000_mac_info *mac = &hw->mac;
struct e1000_fc_info *fc = &hw->fc;
u32 pba = 0, tx_space, min_tx_space, min_rx_space;
u16 hwm;
switch (mac->type) {
case e1000_i350:
case e1000_82580:
pba = rd32(E1000_RXPBS);
pba = igb_rxpbs_adjust_82580(pba);
break;
case e1000_82576:
pba = rd32(E1000_RXPBS);
pba &= E1000_RXPBS_SIZE_MASK_82576;
break;
case e1000_82575:
default:
pba = E1000_PBA_34K;
break;
}
if ((adapter->max_frame_size > ETH_FRAME_LEN + ETH_FCS_LEN) &&
(mac->type < e1000_82576)) {
wr32(E1000_PBA, pba);
pba = rd32(E1000_PBA);
tx_space = pba >> 16;
pba &= 0xffff;
min_tx_space = (adapter->max_frame_size +
sizeof(union e1000_adv_tx_desc) -
ETH_FCS_LEN) * 2;
min_tx_space = ALIGN(min_tx_space, 1024);
min_tx_space >>= 10;
min_rx_space = adapter->max_frame_size;
min_rx_space = ALIGN(min_rx_space, 1024);
min_rx_space >>= 10;
if (tx_space < min_tx_space &&
((min_tx_space - tx_space) < pba)) {
pba = pba - (min_tx_space - tx_space);
if (pba < min_rx_space)
pba = min_rx_space;
}
wr32(E1000_PBA, pba);
}
hwm = min(((pba << 10) * 9 / 10),
((pba << 10) - 2 * adapter->max_frame_size));
fc->high_water = hwm & 0xFFF0;
fc->low_water = fc->high_water - 16;
fc->pause_time = 0xFFFF;
fc->send_xon = 1;
fc->current_mode = fc->requested_mode;
if (adapter->vfs_allocated_count) {
int i;
for (i = 0 ; i < adapter->vfs_allocated_count; i++)
adapter->vf_data[i].flags &= IGB_VF_FLAG_PF_SET_MAC;
igb_ping_all_vfs(adapter);
wr32(E1000_VFRE, 0);
wr32(E1000_VFTE, 0);
}
hw->mac.ops.reset_hw(hw);
wr32(E1000_WUC, 0);
if (hw->mac.ops.init_hw(hw))
dev_err(&pdev->dev, "Hardware Error\n");
if (hw->mac.type > e1000_82580) {
if (adapter->flags & IGB_FLAG_DMAC) {
u32 reg;
hwm = (pba - 4) << 10;
reg = (((pba-6) << E1000_DMACR_DMACTHR_SHIFT)
& E1000_DMACR_DMACTHR_MASK);
reg |= (E1000_DMACR_DMAC_EN | E1000_DMACR_DMAC_LX_MASK);
reg |= (1000 >> 5);
wr32(E1000_DMACR, reg);
wr32(E1000_DMCRTRH, 0);
wr32(E1000_FCRTC, hwm);
reg = rd32(E1000_DMCTLX);
reg |= IGB_DMCTLX_DCFLUSH_DIS;
reg |= 0xFF;
wr32(E1000_DMCTLX, reg);
wr32(E1000_DMCTXTH,
(IGB_MIN_TXPBSIZE -
(IGB_TX_BUF_4096 + adapter->max_frame_size))
>> 6);
reg = rd32(E1000_PCIEMISC);
reg |= E1000_PCIEMISC_LX_DECISION;
wr32(E1000_PCIEMISC, reg);
}
}
if (hw->mac.type == e1000_82580) {
u32 reg = rd32(E1000_PCIEMISC);
wr32(E1000_PCIEMISC,
reg & ~E1000_PCIEMISC_LX_DECISION);
}
if (!netif_running(adapter->netdev))
igb_power_down_link(adapter);
igb_update_mng_vlan(adapter);
wr32(E1000_VET, ETHERNET_IEEE_VLAN_TYPE);
igb_get_phy_info(hw);
}
static u32 igb_fix_features(struct net_device *netdev, u32 features)
{
if (features & NETIF_F_HW_VLAN_RX)
features |= NETIF_F_HW_VLAN_TX;
else
features &= ~NETIF_F_HW_VLAN_TX;
return features;
}
static int igb_set_features(struct net_device *netdev, u32 features)
{
struct igb_adapter *adapter = netdev_priv(netdev);
int i;
u32 changed = netdev->features ^ features;
for (i = 0; i < adapter->num_rx_queues; i++) {
if (features & NETIF_F_RXCSUM)
adapter->rx_ring[i]->flags |= IGB_RING_FLAG_RX_CSUM;
else
adapter->rx_ring[i]->flags &= ~IGB_RING_FLAG_RX_CSUM;
}
if (changed & NETIF_F_HW_VLAN_RX)
igb_vlan_mode(netdev, features);
return 0;
}
static int __devinit igb_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct net_device *netdev;
struct igb_adapter *adapter;
struct e1000_hw *hw;
u16 eeprom_data = 0;
s32 ret_val;
static int global_quad_port_a;
const struct e1000_info *ei = igb_info_tbl[ent->driver_data];
unsigned long mmio_start, mmio_len;
int err, pci_using_dac;
u16 eeprom_apme_mask = IGB_EEPROM_APME;
u8 part_str[E1000_PBANUM_LENGTH];
if (pdev->is_virtfn) {
WARN(1, KERN_ERR "%s (%hx:%hx) should not be a VF!\n",
pci_name(pdev), pdev->vendor, pdev->device);
return -EINVAL;
}
err = pci_enable_device_mem(pdev);
if (err)
return err;
pci_using_dac = 0;
err = dma_set_mask(&pdev->dev, DMA_BIT_MASK(64));
if (!err) {
err = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(64));
if (!err)
pci_using_dac = 1;
} else {
err = dma_set_mask(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
err = dma_set_coherent_mask(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "No usable DMA "
"configuration, aborting\n");
goto err_dma;
}
}
}
err = pci_request_selected_regions(pdev, pci_select_bars(pdev,
IORESOURCE_MEM),
igb_driver_name);
if (err)
goto err_pci_reg;
pci_enable_pcie_error_reporting(pdev);
pci_set_master(pdev);
pci_save_state(pdev);
err = -ENOMEM;
netdev = alloc_etherdev_mq(sizeof(struct igb_adapter),
IGB_ABS_MAX_TX_QUEUES);
if (!netdev)
goto err_alloc_etherdev;
SET_NETDEV_DEV(netdev, &pdev->dev);
pci_set_drvdata(pdev, netdev);
adapter = netdev_priv(netdev);
adapter->netdev = netdev;
adapter->pdev = pdev;
hw = &adapter->hw;
hw->back = adapter;
adapter->msg_enable = NETIF_MSG_DRV | NETIF_MSG_PROBE;
mmio_start = pci_resource_start(pdev, 0);
mmio_len = pci_resource_len(pdev, 0);
err = -EIO;
hw->hw_addr = ioremap(mmio_start, mmio_len);
if (!hw->hw_addr)
goto err_ioremap;
netdev->netdev_ops = &igb_netdev_ops;
igb_set_ethtool_ops(netdev);
netdev->watchdog_timeo = 5 * HZ;
strncpy(netdev->name, pci_name(pdev), sizeof(netdev->name) - 1);
netdev->mem_start = mmio_start;
netdev->mem_end = mmio_start + mmio_len;
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
hw->revision_id = pdev->revision;
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
memcpy(&hw->mac.ops, ei->mac_ops, sizeof(hw->mac.ops));
memcpy(&hw->phy.ops, ei->phy_ops, sizeof(hw->phy.ops));
memcpy(&hw->nvm.ops, ei->nvm_ops, sizeof(hw->nvm.ops));
err = ei->get_invariants(hw);
if (err)
goto err_sw_init;
err = igb_sw_init(adapter);
if (err)
goto err_sw_init;
igb_get_bus_info_pcie(hw);
hw->phy.autoneg_wait_to_complete = false;
if (hw->phy.media_type == e1000_media_type_copper) {
hw->phy.mdix = AUTO_ALL_MODES;
hw->phy.disable_polarity_correction = false;
hw->phy.ms_type = e1000_ms_hw_default;
}
if (igb_check_reset_block(hw))
dev_info(&pdev->dev,
"PHY reset is blocked due to SOL/IDER session.\n");
netdev->hw_features = NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_RXCSUM |
NETIF_F_HW_VLAN_RX;
netdev->features = netdev->hw_features |
NETIF_F_HW_VLAN_TX |
NETIF_F_HW_VLAN_FILTER;
netdev->vlan_features |= NETIF_F_TSO;
netdev->vlan_features |= NETIF_F_TSO6;
netdev->vlan_features |= NETIF_F_IP_CSUM;
netdev->vlan_features |= NETIF_F_IPV6_CSUM;
netdev->vlan_features |= NETIF_F_SG;
if (pci_using_dac) {
netdev->features |= NETIF_F_HIGHDMA;
netdev->vlan_features |= NETIF_F_HIGHDMA;
}
if (hw->mac.type >= e1000_82576) {
netdev->hw_features |= NETIF_F_SCTP_CSUM;
netdev->features |= NETIF_F_SCTP_CSUM;
}
adapter->en_mng_pt = igb_enable_mng_pass_thru(hw);
hw->mac.ops.reset_hw(hw);
if (hw->nvm.ops.validate(hw) < 0) {
dev_err(&pdev->dev, "The NVM Checksum Is Not Valid\n");
err = -EIO;
goto err_eeprom;
}
if (hw->mac.ops.read_mac_addr(hw))
dev_err(&pdev->dev, "NVM Read Error\n");
memcpy(netdev->dev_addr, hw->mac.addr, netdev->addr_len);
memcpy(netdev->perm_addr, hw->mac.addr, netdev->addr_len);
if (!is_valid_ether_addr(netdev->perm_addr)) {
dev_err(&pdev->dev, "Invalid MAC Address\n");
err = -EIO;
goto err_eeprom;
}
setup_timer(&adapter->watchdog_timer, igb_watchdog,
(unsigned long) adapter);
setup_timer(&adapter->phy_info_timer, igb_update_phy_info,
(unsigned long) adapter);
INIT_WORK(&adapter->reset_task, igb_reset_task);
INIT_WORK(&adapter->watchdog_task, igb_watchdog_task);
adapter->fc_autoneg = true;
hw->mac.autoneg = true;
hw->phy.autoneg_advertised = 0x2f;
hw->fc.requested_mode = e1000_fc_default;
hw->fc.current_mode = e1000_fc_default;
igb_validate_mdi_setting(hw);
if (hw->bus.func == 0)
hw->nvm.ops.read(hw, NVM_INIT_CONTROL3_PORT_A, 1, &eeprom_data);
else if (hw->mac.type >= e1000_82580)
hw->nvm.ops.read(hw, NVM_INIT_CONTROL3_PORT_A +
NVM_82580_LAN_FUNC_OFFSET(hw->bus.func), 1,
&eeprom_data);
else if (hw->bus.func == 1)
hw->nvm.ops.read(hw, NVM_INIT_CONTROL3_PORT_B, 1, &eeprom_data);
if (eeprom_data & eeprom_apme_mask)
adapter->eeprom_wol |= E1000_WUFC_MAG;
switch (pdev->device) {
case E1000_DEV_ID_82575GB_QUAD_COPPER:
adapter->eeprom_wol = 0;
break;
case E1000_DEV_ID_82575EB_FIBER_SERDES:
case E1000_DEV_ID_82576_FIBER:
case E1000_DEV_ID_82576_SERDES:
if (rd32(E1000_STATUS) & E1000_STATUS_FUNC_1)
adapter->eeprom_wol = 0;
break;
case E1000_DEV_ID_82576_QUAD_COPPER:
case E1000_DEV_ID_82576_QUAD_COPPER_ET2:
if (global_quad_port_a != 0)
adapter->eeprom_wol = 0;
else
adapter->flags |= IGB_FLAG_QUAD_PORT_A;
if (++global_quad_port_a == 4)
global_quad_port_a = 0;
break;
}
adapter->wol = adapter->eeprom_wol;
device_set_wakeup_enable(&adapter->pdev->dev, adapter->wol);
igb_reset(adapter);
igb_get_hw_control(adapter);
strcpy(netdev->name, "eth%d");
err = register_netdev(netdev);
if (err)
goto err_register;
igb_vlan_mode(netdev, netdev->features);
netif_carrier_off(netdev);
#ifdef CONFIG_IGB_DCA
if (dca_add_requester(&pdev->dev) == 0) {
adapter->flags |= IGB_FLAG_DCA_ENABLED;
dev_info(&pdev->dev, "DCA enabled\n");
igb_setup_dca(adapter);
}
#endif
igb_init_hw_timer(adapter);
dev_info(&pdev->dev, "Intel(R) Gigabit Ethernet Network Connection\n");
dev_info(&pdev->dev, "%s: (PCIe:%s:%s) %pM\n",
netdev->name,
((hw->bus.speed == e1000_bus_speed_2500) ? "2.5Gb/s" :
(hw->bus.speed == e1000_bus_speed_5000) ? "5.0Gb/s" :
"unknown"),
((hw->bus.width == e1000_bus_width_pcie_x4) ? "Width x4" :
(hw->bus.width == e1000_bus_width_pcie_x2) ? "Width x2" :
(hw->bus.width == e1000_bus_width_pcie_x1) ? "Width x1" :
"unknown"),
netdev->dev_addr);
ret_val = igb_read_part_string(hw, part_str, E1000_PBANUM_LENGTH);
if (ret_val)
strcpy(part_str, "Unknown");
dev_info(&pdev->dev, "%s: PBA No: %s\n", netdev->name, part_str);
dev_info(&pdev->dev,
"Using %s interrupts. %d rx queue(s), %d tx queue(s)\n",
adapter->msix_entries ? "MSI-X" :
(adapter->flags & IGB_FLAG_HAS_MSI) ? "MSI" : "legacy",
adapter->num_rx_queues, adapter->num_tx_queues);
switch (hw->mac.type) {
case e1000_i350:
igb_set_eee_i350(hw);
break;
default:
break;
}
return 0;
err_register:
igb_release_hw_control(adapter);
err_eeprom:
if (!igb_check_reset_block(hw))
igb_reset_phy(hw);
if (hw->flash_address)
iounmap(hw->flash_address);
err_sw_init:
igb_clear_interrupt_scheme(adapter);
iounmap(hw->hw_addr);
err_ioremap:
free_netdev(netdev);
err_alloc_etherdev:
pci_release_selected_regions(pdev,
pci_select_bars(pdev, IORESOURCE_MEM));
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static void __devexit igb_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
set_bit(__IGB_DOWN, &adapter->state);
del_timer_sync(&adapter->watchdog_timer);
del_timer_sync(&adapter->phy_info_timer);
cancel_work_sync(&adapter->reset_task);
cancel_work_sync(&adapter->watchdog_task);
#ifdef CONFIG_IGB_DCA
if (adapter->flags & IGB_FLAG_DCA_ENABLED) {
dev_info(&pdev->dev, "DCA disabled\n");
dca_remove_requester(&pdev->dev);
adapter->flags &= ~IGB_FLAG_DCA_ENABLED;
wr32(E1000_DCA_CTRL, E1000_DCA_CTRL_DCA_MODE_DISABLE);
}
#endif
igb_release_hw_control(adapter);
unregister_netdev(netdev);
igb_clear_interrupt_scheme(adapter);
#ifdef CONFIG_PCI_IOV
if (adapter->vf_data) {
pci_disable_sriov(pdev);
msleep(500);
kfree(adapter->vf_data);
adapter->vf_data = NULL;
wr32(E1000_IOVCTL, E1000_IOVCTL_REUSE_VFQ);
wrfl();
msleep(100);
dev_info(&pdev->dev, "IOV Disabled\n");
}
#endif
iounmap(hw->hw_addr);
if (hw->flash_address)
iounmap(hw->flash_address);
pci_release_selected_regions(pdev,
pci_select_bars(pdev, IORESOURCE_MEM));
free_netdev(netdev);
pci_disable_pcie_error_reporting(pdev);
pci_disable_device(pdev);
}
static void __devinit igb_probe_vfs(struct igb_adapter * adapter)
{
#ifdef CONFIG_PCI_IOV
struct pci_dev *pdev = adapter->pdev;
if (adapter->vfs_allocated_count) {
adapter->vf_data = kcalloc(adapter->vfs_allocated_count,
sizeof(struct vf_data_storage),
GFP_KERNEL);
if (!adapter->vf_data) {
adapter->vfs_allocated_count = 0;
dev_err(&pdev->dev, "Unable to allocate memory for VF "
"Data Storage\n");
}
}
if (pci_enable_sriov(pdev, adapter->vfs_allocated_count)) {
kfree(adapter->vf_data);
adapter->vf_data = NULL;
#endif
adapter->vfs_allocated_count = 0;
#ifdef CONFIG_PCI_IOV
} else {
unsigned char mac_addr[ETH_ALEN];
int i;
dev_info(&pdev->dev, "%d vfs allocated\n",
adapter->vfs_allocated_count);
for (i = 0; i < adapter->vfs_allocated_count; i++) {
random_ether_addr(mac_addr);
igb_set_vf_mac(adapter, i, mac_addr);
}
if (adapter->flags & IGB_FLAG_DMAC)
adapter->flags &= ~IGB_FLAG_DMAC;
}
#endif
}
static void igb_init_hw_timer(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
switch (hw->mac.type) {
case e1000_i350:
case e1000_82580:
memset(&adapter->cycles, 0, sizeof(adapter->cycles));
adapter->cycles.read = igb_read_clock;
adapter->cycles.mask = CLOCKSOURCE_MASK(64);
adapter->cycles.mult = 1;
adapter->cycles.shift = IGB_82580_TSYNC_SHIFT;
wr32(E1000_TSAUXC, 0x80000000);
wrfl();
wr32(E1000_SYSTIMR, 0x00000000);
wr32(E1000_SYSTIML, 0x80000000);
wr32(E1000_SYSTIMH, 0x000000FF);
wrfl();
wr32(E1000_TSAUXC, 0x0);
wrfl();
timecounter_init(&adapter->clock,
&adapter->cycles,
ktime_to_ns(ktime_get_real()));
memset(&adapter->compare, 0, sizeof(adapter->compare));
adapter->compare.source = &adapter->clock;
adapter->compare.target = ktime_get_real;
adapter->compare.num_samples = 10;
timecompare_update(&adapter->compare, 0);
break;
case e1000_82576:
memset(&adapter->cycles, 0, sizeof(adapter->cycles));
adapter->cycles.read = igb_read_clock;
adapter->cycles.mask = CLOCKSOURCE_MASK(64);
adapter->cycles.mult = 1;
adapter->cycles.shift = IGB_82576_TSYNC_SHIFT;
wr32(E1000_TIMINCA,
(1 << E1000_TIMINCA_16NS_SHIFT) |
(16 << IGB_82576_TSYNC_SHIFT));
wr32(E1000_SYSTIML, 0x00000000);
wr32(E1000_SYSTIMH, 0xFF800000);
wrfl();
timecounter_init(&adapter->clock,
&adapter->cycles,
ktime_to_ns(ktime_get_real()));
memset(&adapter->compare, 0, sizeof(adapter->compare));
adapter->compare.source = &adapter->clock;
adapter->compare.target = ktime_get_real;
adapter->compare.num_samples = 10;
timecompare_update(&adapter->compare, 0);
break;
case e1000_82575:
default:
break;
}
}
static int __devinit igb_sw_init(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
struct pci_dev *pdev = adapter->pdev;
pci_read_config_word(pdev, PCI_COMMAND, &hw->bus.pci_cmd_word);
adapter->tx_ring_count = IGB_DEFAULT_TXD;
adapter->rx_ring_count = IGB_DEFAULT_RXD;
adapter->rx_itr_setting = IGB_DEFAULT_ITR;
adapter->tx_itr_setting = IGB_DEFAULT_ITR;
adapter->max_frame_size = netdev->mtu + ETH_HLEN + ETH_FCS_LEN;
adapter->min_frame_size = ETH_ZLEN + ETH_FCS_LEN;
spin_lock_init(&adapter->stats64_lock);
#ifdef CONFIG_PCI_IOV
switch (hw->mac.type) {
case e1000_82576:
case e1000_i350:
if (max_vfs > 7) {
dev_warn(&pdev->dev,
"Maximum of 7 VFs per PF, using max\n");
adapter->vfs_allocated_count = 7;
} else
adapter->vfs_allocated_count = max_vfs;
break;
default:
break;
}
#endif
adapter->rss_queues = min_t(u32, IGB_MAX_RX_QUEUES, num_online_cpus());
if (hw->mac.type == e1000_i350 && adapter->vfs_allocated_count)
adapter->rss_queues = 1;
if ((adapter->rss_queues > 4) ||
((adapter->rss_queues > 1) && (adapter->vfs_allocated_count > 6)))
adapter->flags |= IGB_FLAG_QUEUE_PAIRS;
if (igb_init_interrupt_scheme(adapter)) {
dev_err(&pdev->dev, "Unable to allocate memory for queues\n");
return -ENOMEM;
}
igb_probe_vfs(adapter);
igb_irq_disable(adapter);
if (hw->mac.type == e1000_i350)
adapter->flags &= ~IGB_FLAG_DMAC;
set_bit(__IGB_DOWN, &adapter->state);
return 0;
}
static int igb_open(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
int err;
int i;
if (test_bit(__IGB_TESTING, &adapter->state))
return -EBUSY;
netif_carrier_off(netdev);
err = igb_setup_all_tx_resources(adapter);
if (err)
goto err_setup_tx;
err = igb_setup_all_rx_resources(adapter);
if (err)
goto err_setup_rx;
igb_power_up_link(adapter);
igb_configure(adapter);
err = igb_request_irq(adapter);
if (err)
goto err_req_irq;
clear_bit(__IGB_DOWN, &adapter->state);
for (i = 0; i < adapter->num_q_vectors; i++) {
struct igb_q_vector *q_vector = adapter->q_vector[i];
napi_enable(&q_vector->napi);
}
rd32(E1000_ICR);
igb_irq_enable(adapter);
if (adapter->vfs_allocated_count) {
u32 reg_data = rd32(E1000_CTRL_EXT);
reg_data |= E1000_CTRL_EXT_PFRSTD;
wr32(E1000_CTRL_EXT, reg_data);
}
netif_tx_start_all_queues(netdev);
hw->mac.get_link_status = 1;
schedule_work(&adapter->watchdog_task);
return 0;
err_req_irq:
igb_release_hw_control(adapter);
igb_power_down_link(adapter);
igb_free_all_rx_resources(adapter);
err_setup_rx:
igb_free_all_tx_resources(adapter);
err_setup_tx:
igb_reset(adapter);
return err;
}
static int igb_close(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
WARN_ON(test_bit(__IGB_RESETTING, &adapter->state));
igb_down(adapter);
igb_free_irq(adapter);
igb_free_all_tx_resources(adapter);
igb_free_all_rx_resources(adapter);
return 0;
}
int igb_setup_tx_resources(struct igb_ring *tx_ring)
{
struct device *dev = tx_ring->dev;
int size;
size = sizeof(struct igb_buffer) * tx_ring->count;
tx_ring->buffer_info = vzalloc(size);
if (!tx_ring->buffer_info)
goto err;
tx_ring->size = tx_ring->count * sizeof(union e1000_adv_tx_desc);
tx_ring->size = ALIGN(tx_ring->size, 4096);
tx_ring->desc = dma_alloc_coherent(dev,
tx_ring->size,
&tx_ring->dma,
GFP_KERNEL);
if (!tx_ring->desc)
goto err;
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
return 0;
err:
vfree(tx_ring->buffer_info);
dev_err(dev,
"Unable to allocate memory for the transmit descriptor ring\n");
return -ENOMEM;
}
static int igb_setup_all_tx_resources(struct igb_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
int i, err = 0;
for (i = 0; i < adapter->num_tx_queues; i++) {
err = igb_setup_tx_resources(adapter->tx_ring[i]);
if (err) {
dev_err(&pdev->dev,
"Allocation for Tx Queue %u failed\n", i);
for (i--; i >= 0; i--)
igb_free_tx_resources(adapter->tx_ring[i]);
break;
}
}
for (i = 0; i < IGB_ABS_MAX_TX_QUEUES; i++) {
int r_idx = i % adapter->num_tx_queues;
adapter->multi_tx_table[i] = adapter->tx_ring[r_idx];
}
return err;
}
void igb_setup_tctl(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 tctl;
wr32(E1000_TXDCTL(0), 0);
tctl = rd32(E1000_TCTL);
tctl &= ~E1000_TCTL_CT;
tctl |= E1000_TCTL_PSP | E1000_TCTL_RTLC |
(E1000_COLLISION_THRESHOLD << E1000_CT_SHIFT);
igb_config_collision_dist(hw);
tctl |= E1000_TCTL_EN;
wr32(E1000_TCTL, tctl);
}
void igb_configure_tx_ring(struct igb_adapter *adapter,
struct igb_ring *ring)
{
struct e1000_hw *hw = &adapter->hw;
u32 txdctl;
u64 tdba = ring->dma;
int reg_idx = ring->reg_idx;
txdctl = rd32(E1000_TXDCTL(reg_idx));
wr32(E1000_TXDCTL(reg_idx),
txdctl & ~E1000_TXDCTL_QUEUE_ENABLE);
wrfl();
mdelay(10);
wr32(E1000_TDLEN(reg_idx),
ring->count * sizeof(union e1000_adv_tx_desc));
wr32(E1000_TDBAL(reg_idx),
tdba & 0x00000000ffffffffULL);
wr32(E1000_TDBAH(reg_idx), tdba >> 32);
ring->head = hw->hw_addr + E1000_TDH(reg_idx);
ring->tail = hw->hw_addr + E1000_TDT(reg_idx);
writel(0, ring->head);
writel(0, ring->tail);
txdctl |= IGB_TX_PTHRESH;
txdctl |= IGB_TX_HTHRESH << 8;
txdctl |= IGB_TX_WTHRESH << 16;
txdctl |= E1000_TXDCTL_QUEUE_ENABLE;
wr32(E1000_TXDCTL(reg_idx), txdctl);
}
static void igb_configure_tx(struct igb_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
igb_configure_tx_ring(adapter, adapter->tx_ring[i]);
}
int igb_setup_rx_resources(struct igb_ring *rx_ring)
{
struct device *dev = rx_ring->dev;
int size, desc_len;
size = sizeof(struct igb_buffer) * rx_ring->count;
rx_ring->buffer_info = vzalloc(size);
if (!rx_ring->buffer_info)
goto err;
desc_len = sizeof(union e1000_adv_rx_desc);
rx_ring->size = rx_ring->count * desc_len;
rx_ring->size = ALIGN(rx_ring->size, 4096);
rx_ring->desc = dma_alloc_coherent(dev,
rx_ring->size,
&rx_ring->dma,
GFP_KERNEL);
if (!rx_ring->desc)
goto err;
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
return 0;
err:
vfree(rx_ring->buffer_info);
rx_ring->buffer_info = NULL;
dev_err(dev, "Unable to allocate memory for the receive descriptor"
" ring\n");
return -ENOMEM;
}
static int igb_setup_all_rx_resources(struct igb_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
int i, err = 0;
for (i = 0; i < adapter->num_rx_queues; i++) {
err = igb_setup_rx_resources(adapter->rx_ring[i]);
if (err) {
dev_err(&pdev->dev,
"Allocation for Rx Queue %u failed\n", i);
for (i--; i >= 0; i--)
igb_free_rx_resources(adapter->rx_ring[i]);
break;
}
}
return err;
}
static void igb_setup_mrqc(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 mrqc, rxcsum;
u32 j, num_rx_queues, shift = 0, shift2 = 0;
union e1000_reta {
u32 dword;
u8 bytes[4];
} reta;
static const u8 rsshash[40] = {
0x6d, 0x5a, 0x56, 0xda, 0x25, 0x5b, 0x0e, 0xc2, 0x41, 0x67,
0x25, 0x3d, 0x43, 0xa3, 0x8f, 0xb0, 0xd0, 0xca, 0x2b, 0xcb,
0xae, 0x7b, 0x30, 0xb4, 0x77, 0xcb, 0x2d, 0xa3, 0x80, 0x30,
0xf2, 0x0c, 0x6a, 0x42, 0xb7, 0x3b, 0xbe, 0xac, 0x01, 0xfa };
for (j = 0; j < 10; j++) {
u32 rsskey = rsshash[(j * 4)];
rsskey |= rsshash[(j * 4) + 1] << 8;
rsskey |= rsshash[(j * 4) + 2] << 16;
rsskey |= rsshash[(j * 4) + 3] << 24;
array_wr32(E1000_RSSRK(0), j, rsskey);
}
num_rx_queues = adapter->rss_queues;
if (adapter->vfs_allocated_count) {
switch (hw->mac.type) {
case e1000_i350:
case e1000_82580:
num_rx_queues = 1;
shift = 0;
break;
case e1000_82576:
shift = 3;
num_rx_queues = 2;
break;
case e1000_82575:
shift = 2;
shift2 = 6;
default:
break;
}
} else {
if (hw->mac.type == e1000_82575)
shift = 6;
}
for (j = 0; j < (32 * 4); j++) {
reta.bytes[j & 3] = (j % num_rx_queues) << shift;
if (shift2)
reta.bytes[j & 3] |= num_rx_queues << shift2;
if ((j & 3) == 3)
wr32(E1000_RETA(j >> 2), reta.dword);
}
rxcsum = rd32(E1000_RXCSUM);
rxcsum |= E1000_RXCSUM_PCSD;
if (adapter->hw.mac.type >= e1000_82576)
rxcsum |= E1000_RXCSUM_CRCOFL;
wr32(E1000_RXCSUM, rxcsum);
if (adapter->vfs_allocated_count) {
if (hw->mac.type > e1000_82575) {
u32 vtctl = rd32(E1000_VT_CTL);
vtctl &= ~(E1000_VT_CTL_DEFAULT_POOL_MASK |
E1000_VT_CTL_DISABLE_DEF_POOL);
vtctl |= adapter->vfs_allocated_count <<
E1000_VT_CTL_DEFAULT_POOL_SHIFT;
wr32(E1000_VT_CTL, vtctl);
}
if (adapter->rss_queues > 1)
mrqc = E1000_MRQC_ENABLE_VMDQ_RSS_2Q;
else
mrqc = E1000_MRQC_ENABLE_VMDQ;
} else {
mrqc = E1000_MRQC_ENABLE_RSS_4Q;
}
igb_vmm_control(adapter);
mrqc |= E1000_MRQC_RSS_FIELD_IPV4 |
E1000_MRQC_RSS_FIELD_IPV4_TCP |
E1000_MRQC_RSS_FIELD_IPV6 |
E1000_MRQC_RSS_FIELD_IPV6_TCP |
E1000_MRQC_RSS_FIELD_IPV6_TCP_EX;
wr32(E1000_MRQC, mrqc);
}
void igb_setup_rctl(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 rctl;
rctl = rd32(E1000_RCTL);
rctl &= ~(3 << E1000_RCTL_MO_SHIFT);
rctl &= ~(E1000_RCTL_LBM_TCVR | E1000_RCTL_LBM_MAC);
rctl |= E1000_RCTL_EN | E1000_RCTL_BAM | E1000_RCTL_RDMTS_HALF |
(hw->mac.mc_filter_type << E1000_RCTL_MO_SHIFT);
rctl |= E1000_RCTL_SECRC;
rctl &= ~(E1000_RCTL_SBP | E1000_RCTL_SZ_256);
rctl |= E1000_RCTL_LPE;
wr32(E1000_RXDCTL(0), 0);
if (adapter->vfs_allocated_count) {
wr32(E1000_QDE, ALL_QUEUES);
}
wr32(E1000_RCTL, rctl);
}
static inline int igb_set_vf_rlpml(struct igb_adapter *adapter, int size,
int vfn)
{
struct e1000_hw *hw = &adapter->hw;
u32 vmolr;
if (vfn < adapter->vfs_allocated_count &&
adapter->vf_data[vfn].vlans_enabled)
size += VLAN_TAG_SIZE;
vmolr = rd32(E1000_VMOLR(vfn));
vmolr &= ~E1000_VMOLR_RLPML_MASK;
vmolr |= size | E1000_VMOLR_LPE;
wr32(E1000_VMOLR(vfn), vmolr);
return 0;
}
static void igb_rlpml_set(struct igb_adapter *adapter)
{
u32 max_frame_size;
struct e1000_hw *hw = &adapter->hw;
u16 pf_id = adapter->vfs_allocated_count;
max_frame_size = adapter->max_frame_size + VLAN_TAG_SIZE;
if (pf_id) {
igb_set_vf_rlpml(adapter, max_frame_size, pf_id);
max_frame_size = MAX_JUMBO_FRAME_SIZE;
}
wr32(E1000_RLPML, max_frame_size);
}
static inline void igb_set_vmolr(struct igb_adapter *adapter,
int vfn, bool aupe)
{
struct e1000_hw *hw = &adapter->hw;
u32 vmolr;
if (hw->mac.type < e1000_82576)
return;
vmolr = rd32(E1000_VMOLR(vfn));
vmolr |= E1000_VMOLR_STRVLAN;
if (aupe)
vmolr |= E1000_VMOLR_AUPE;
else
vmolr &= ~(E1000_VMOLR_AUPE);
vmolr &= ~(E1000_VMOLR_BAM | E1000_VMOLR_RSSE);
if (adapter->rss_queues > 1 && vfn == adapter->vfs_allocated_count)
vmolr |= E1000_VMOLR_RSSE;
if (vfn <= adapter->vfs_allocated_count)
vmolr |= E1000_VMOLR_BAM;
wr32(E1000_VMOLR(vfn), vmolr);
}
void igb_configure_rx_ring(struct igb_adapter *adapter,
struct igb_ring *ring)
{
struct e1000_hw *hw = &adapter->hw;
u64 rdba = ring->dma;
int reg_idx = ring->reg_idx;
u32 srrctl, rxdctl;
rxdctl = rd32(E1000_RXDCTL(reg_idx));
wr32(E1000_RXDCTL(reg_idx),
rxdctl & ~E1000_RXDCTL_QUEUE_ENABLE);
wr32(E1000_RDBAL(reg_idx),
rdba & 0x00000000ffffffffULL);
wr32(E1000_RDBAH(reg_idx), rdba >> 32);
wr32(E1000_RDLEN(reg_idx),
ring->count * sizeof(union e1000_adv_rx_desc));
ring->head = hw->hw_addr + E1000_RDH(reg_idx);
ring->tail = hw->hw_addr + E1000_RDT(reg_idx);
writel(0, ring->head);
writel(0, ring->tail);
if (ring->rx_buffer_len < IGB_RXBUFFER_1024) {
srrctl = ALIGN(ring->rx_buffer_len, 64) <<
E1000_SRRCTL_BSIZEHDRSIZE_SHIFT;
#if (PAGE_SIZE / 2) > IGB_RXBUFFER_16384
srrctl |= IGB_RXBUFFER_16384 >>
E1000_SRRCTL_BSIZEPKT_SHIFT;
#else
srrctl |= (PAGE_SIZE / 2) >>
E1000_SRRCTL_BSIZEPKT_SHIFT;
#endif
srrctl |= E1000_SRRCTL_DESCTYPE_HDR_SPLIT_ALWAYS;
} else {
srrctl = ALIGN(ring->rx_buffer_len, 1024) >>
E1000_SRRCTL_BSIZEPKT_SHIFT;
srrctl |= E1000_SRRCTL_DESCTYPE_ADV_ONEBUF;
}
if (hw->mac.type == e1000_82580)
srrctl |= E1000_SRRCTL_TIMESTAMP;
if (adapter->vfs_allocated_count || adapter->num_rx_queues > 1)
srrctl |= E1000_SRRCTL_DROP_EN;
wr32(E1000_SRRCTL(reg_idx), srrctl);
igb_set_vmolr(adapter, reg_idx & 0x7, true);
rxdctl = rd32(E1000_RXDCTL(reg_idx));
rxdctl |= E1000_RXDCTL_QUEUE_ENABLE;
rxdctl &= 0xFFF00000;
rxdctl |= IGB_RX_PTHRESH;
rxdctl |= IGB_RX_HTHRESH << 8;
rxdctl |= IGB_RX_WTHRESH << 16;
wr32(E1000_RXDCTL(reg_idx), rxdctl);
}
static void igb_configure_rx(struct igb_adapter *adapter)
{
int i;
igb_set_uta(adapter);
igb_rar_set_qsel(adapter, adapter->hw.mac.addr, 0,
adapter->vfs_allocated_count);
for (i = 0; i < adapter->num_rx_queues; i++)
igb_configure_rx_ring(adapter, adapter->rx_ring[i]);
}
void igb_free_tx_resources(struct igb_ring *tx_ring)
{
igb_clean_tx_ring(tx_ring);
vfree(tx_ring->buffer_info);
tx_ring->buffer_info = NULL;
if (!tx_ring->desc)
return;
dma_free_coherent(tx_ring->dev, tx_ring->size,
tx_ring->desc, tx_ring->dma);
tx_ring->desc = NULL;
}
static void igb_free_all_tx_resources(struct igb_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
igb_free_tx_resources(adapter->tx_ring[i]);
}
void igb_unmap_and_free_tx_resource(struct igb_ring *tx_ring,
struct igb_buffer *buffer_info)
{
if (buffer_info->dma) {
if (buffer_info->mapped_as_page)
dma_unmap_page(tx_ring->dev,
buffer_info->dma,
buffer_info->length,
DMA_TO_DEVICE);
else
dma_unmap_single(tx_ring->dev,
buffer_info->dma,
buffer_info->length,
DMA_TO_DEVICE);
buffer_info->dma = 0;
}
if (buffer_info->skb) {
dev_kfree_skb_any(buffer_info->skb);
buffer_info->skb = NULL;
}
buffer_info->time_stamp = 0;
buffer_info->length = 0;
buffer_info->next_to_watch = 0;
buffer_info->mapped_as_page = false;
}
static void igb_clean_tx_ring(struct igb_ring *tx_ring)
{
struct igb_buffer *buffer_info;
unsigned long size;
unsigned int i;
if (!tx_ring->buffer_info)
return;
for (i = 0; i < tx_ring->count; i++) {
buffer_info = &tx_ring->buffer_info[i];
igb_unmap_and_free_tx_resource(tx_ring, buffer_info);
}
size = sizeof(struct igb_buffer) * tx_ring->count;
memset(tx_ring->buffer_info, 0, size);
memset(tx_ring->desc, 0, tx_ring->size);
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
}
static void igb_clean_all_tx_rings(struct igb_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
igb_clean_tx_ring(adapter->tx_ring[i]);
}
void igb_free_rx_resources(struct igb_ring *rx_ring)
{
igb_clean_rx_ring(rx_ring);
vfree(rx_ring->buffer_info);
rx_ring->buffer_info = NULL;
if (!rx_ring->desc)
return;
dma_free_coherent(rx_ring->dev, rx_ring->size,
rx_ring->desc, rx_ring->dma);
rx_ring->desc = NULL;
}
static void igb_free_all_rx_resources(struct igb_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
igb_free_rx_resources(adapter->rx_ring[i]);
}
static void igb_clean_rx_ring(struct igb_ring *rx_ring)
{
struct igb_buffer *buffer_info;
unsigned long size;
unsigned int i;
if (!rx_ring->buffer_info)
return;
for (i = 0; i < rx_ring->count; i++) {
buffer_info = &rx_ring->buffer_info[i];
if (buffer_info->dma) {
dma_unmap_single(rx_ring->dev,
buffer_info->dma,
rx_ring->rx_buffer_len,
DMA_FROM_DEVICE);
buffer_info->dma = 0;
}
if (buffer_info->skb) {
dev_kfree_skb(buffer_info->skb);
buffer_info->skb = NULL;
}
if (buffer_info->page_dma) {
dma_unmap_page(rx_ring->dev,
buffer_info->page_dma,
PAGE_SIZE / 2,
DMA_FROM_DEVICE);
buffer_info->page_dma = 0;
}
if (buffer_info->page) {
put_page(buffer_info->page);
buffer_info->page = NULL;
buffer_info->page_offset = 0;
}
}
size = sizeof(struct igb_buffer) * rx_ring->count;
memset(rx_ring->buffer_info, 0, size);
memset(rx_ring->desc, 0, rx_ring->size);
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
}
static void igb_clean_all_rx_rings(struct igb_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
igb_clean_rx_ring(adapter->rx_ring[i]);
}
static int igb_set_mac(struct net_device *netdev, void *p)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
memcpy(netdev->dev_addr, addr->sa_data, netdev->addr_len);
memcpy(hw->mac.addr, addr->sa_data, netdev->addr_len);
igb_rar_set_qsel(adapter, hw->mac.addr, 0,
adapter->vfs_allocated_count);
return 0;
}
static int igb_write_mc_addr_list(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
struct netdev_hw_addr *ha;
u8 *mta_list;
int i;
if (netdev_mc_empty(netdev)) {
igb_update_mc_addr_list(hw, NULL, 0);
igb_restore_vf_multicasts(adapter);
return 0;
}
mta_list = kzalloc(netdev_mc_count(netdev) * 6, GFP_ATOMIC);
if (!mta_list)
return -ENOMEM;
i = 0;
netdev_for_each_mc_addr(ha, netdev)
memcpy(mta_list + (i++ * ETH_ALEN), ha->addr, ETH_ALEN);
igb_update_mc_addr_list(hw, mta_list, i);
kfree(mta_list);
return netdev_mc_count(netdev);
}
static int igb_write_uc_addr_list(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
unsigned int vfn = adapter->vfs_allocated_count;
unsigned int rar_entries = hw->mac.rar_entry_count - (vfn + 1);
int count = 0;
if (netdev_uc_count(netdev) > rar_entries)
return -ENOMEM;
if (!netdev_uc_empty(netdev) && rar_entries) {
struct netdev_hw_addr *ha;
netdev_for_each_uc_addr(ha, netdev) {
if (!rar_entries)
break;
igb_rar_set_qsel(adapter, ha->addr,
rar_entries--,
vfn);
count++;
}
}
for (; rar_entries > 0 ; rar_entries--) {
wr32(E1000_RAH(rar_entries), 0);
wr32(E1000_RAL(rar_entries), 0);
}
wrfl();
return count;
}
static void igb_set_rx_mode(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
unsigned int vfn = adapter->vfs_allocated_count;
u32 rctl, vmolr = 0;
int count;
rctl = rd32(E1000_RCTL);
rctl &= ~(E1000_RCTL_UPE | E1000_RCTL_MPE | E1000_RCTL_VFE);
if (netdev->flags & IFF_PROMISC) {
rctl |= (E1000_RCTL_UPE | E1000_RCTL_MPE);
vmolr |= (E1000_VMOLR_ROPE | E1000_VMOLR_MPME);
} else {
if (netdev->flags & IFF_ALLMULTI) {
rctl |= E1000_RCTL_MPE;
vmolr |= E1000_VMOLR_MPME;
} else {
count = igb_write_mc_addr_list(netdev);
if (count < 0) {
rctl |= E1000_RCTL_MPE;
vmolr |= E1000_VMOLR_MPME;
} else if (count) {
vmolr |= E1000_VMOLR_ROMPE;
}
}
count = igb_write_uc_addr_list(netdev);
if (count < 0) {
rctl |= E1000_RCTL_UPE;
vmolr |= E1000_VMOLR_ROPE;
}
rctl |= E1000_RCTL_VFE;
}
wr32(E1000_RCTL, rctl);
if (hw->mac.type < e1000_82576)
return;
vmolr |= rd32(E1000_VMOLR(vfn)) &
~(E1000_VMOLR_ROPE | E1000_VMOLR_MPME | E1000_VMOLR_ROMPE);
wr32(E1000_VMOLR(vfn), vmolr);
igb_restore_vf_multicasts(adapter);
}
static void igb_check_wvbr(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 wvbr = 0;
switch (hw->mac.type) {
case e1000_82576:
case e1000_i350:
if (!(wvbr = rd32(E1000_WVBR)))
return;
break;
default:
break;
}
adapter->wvbr |= wvbr;
}
static void igb_spoof_check(struct igb_adapter *adapter)
{
int j;
if (!adapter->wvbr)
return;
for(j = 0; j < adapter->vfs_allocated_count; j++) {
if (adapter->wvbr & (1 << j) ||
adapter->wvbr & (1 << (j + IGB_STAGGERED_QUEUE_OFFSET))) {
dev_warn(&adapter->pdev->dev,
"Spoof event(s) detected on VF %d\n", j);
adapter->wvbr &=
~((1 << j) |
(1 << (j + IGB_STAGGERED_QUEUE_OFFSET)));
}
}
}
static void igb_update_phy_info(unsigned long data)
{
struct igb_adapter *adapter = (struct igb_adapter *) data;
igb_get_phy_info(&adapter->hw);
}
bool igb_has_link(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
bool link_active = false;
s32 ret_val = 0;
switch (hw->phy.media_type) {
case e1000_media_type_copper:
if (hw->mac.get_link_status) {
ret_val = hw->mac.ops.check_for_link(hw);
link_active = !hw->mac.get_link_status;
} else {
link_active = true;
}
break;
case e1000_media_type_internal_serdes:
ret_val = hw->mac.ops.check_for_link(hw);
link_active = hw->mac.serdes_has_link;
break;
default:
case e1000_media_type_unknown:
break;
}
return link_active;
}
static bool igb_thermal_sensor_event(struct e1000_hw *hw, u32 event)
{
bool ret = false;
u32 ctrl_ext, thstat;
if (hw->mac.type == e1000_i350) {
thstat = rd32(E1000_THSTAT);
ctrl_ext = rd32(E1000_CTRL_EXT);
if ((hw->phy.media_type == e1000_media_type_copper) &&
!(ctrl_ext & E1000_CTRL_EXT_LINK_MODE_SGMII)) {
ret = !!(thstat & event);
}
}
return ret;
}
static void igb_watchdog(unsigned long data)
{
struct igb_adapter *adapter = (struct igb_adapter *)data;
schedule_work(&adapter->watchdog_task);
}
static void igb_watchdog_task(struct work_struct *work)
{
struct igb_adapter *adapter = container_of(work,
struct igb_adapter,
watchdog_task);
struct e1000_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
u32 link;
int i;
link = igb_has_link(adapter);
if (link) {
if (!netif_carrier_ok(netdev)) {
u32 ctrl;
hw->mac.ops.get_speed_and_duplex(hw,
&adapter->link_speed,
&adapter->link_duplex);
ctrl = rd32(E1000_CTRL);
printk(KERN_INFO "igb: %s NIC Link is Up %d Mbps %s, "
"Flow Control: %s\n",
netdev->name,
adapter->link_speed,
adapter->link_duplex == FULL_DUPLEX ?
"Full Duplex" : "Half Duplex",
((ctrl & E1000_CTRL_TFCE) &&
(ctrl & E1000_CTRL_RFCE)) ? "RX/TX" :
((ctrl & E1000_CTRL_RFCE) ? "RX" :
((ctrl & E1000_CTRL_TFCE) ? "TX" : "None")));
if (igb_thermal_sensor_event(hw, E1000_THSTAT_LINK_THROTTLE)) {
printk(KERN_INFO "igb: %s The network adapter "
"link speed was downshifted "
"because it overheated.\n",
netdev->name);
}
adapter->tx_timeout_factor = 1;
switch (adapter->link_speed) {
case SPEED_10:
adapter->tx_timeout_factor = 14;
break;
case SPEED_100:
break;
}
netif_carrier_on(netdev);
igb_ping_all_vfs(adapter);
igb_check_vf_rate_limit(adapter);
if (!test_bit(__IGB_DOWN, &adapter->state))
mod_timer(&adapter->phy_info_timer,
round_jiffies(jiffies + 2 * HZ));
}
} else {
if (netif_carrier_ok(netdev)) {
adapter->link_speed = 0;
adapter->link_duplex = 0;
if (igb_thermal_sensor_event(hw, E1000_THSTAT_PWR_DOWN)) {
printk(KERN_ERR "igb: %s The network adapter "
"was stopped because it "
"overheated.\n",
netdev->name);
}
printk(KERN_INFO "igb: %s NIC Link is Down\n",
netdev->name);
netif_carrier_off(netdev);
igb_ping_all_vfs(adapter);
if (!test_bit(__IGB_DOWN, &adapter->state))
mod_timer(&adapter->phy_info_timer,
round_jiffies(jiffies + 2 * HZ));
}
}
spin_lock(&adapter->stats64_lock);
igb_update_stats(adapter, &adapter->stats64);
spin_unlock(&adapter->stats64_lock);
for (i = 0; i < adapter->num_tx_queues; i++) {
struct igb_ring *tx_ring = adapter->tx_ring[i];
if (!netif_carrier_ok(netdev)) {
if (igb_desc_unused(tx_ring) + 1 < tx_ring->count) {
adapter->tx_timeout_count++;
schedule_work(&adapter->reset_task);
return;
}
}
tx_ring->detect_tx_hung = true;
}
if (adapter->msix_entries) {
u32 eics = 0;
for (i = 0; i < adapter->num_q_vectors; i++) {
struct igb_q_vector *q_vector = adapter->q_vector[i];
eics |= q_vector->eims_value;
}
wr32(E1000_EICS, eics);
} else {
wr32(E1000_ICS, E1000_ICS_RXDMT0);
}
igb_spoof_check(adapter);
if (!test_bit(__IGB_DOWN, &adapter->state))
mod_timer(&adapter->watchdog_timer,
round_jiffies(jiffies + 2 * HZ));
}
static void igb_update_ring_itr(struct igb_q_vector *q_vector)
{
int new_val = q_vector->itr_val;
int avg_wire_size = 0;
struct igb_adapter *adapter = q_vector->adapter;
struct igb_ring *ring;
unsigned int packets;
if (adapter->link_speed != SPEED_1000) {
new_val = 976;
goto set_itr_val;
}
ring = q_vector->rx_ring;
if (ring) {
packets = ACCESS_ONCE(ring->total_packets);
if (packets)
avg_wire_size = ring->total_bytes / packets;
}
ring = q_vector->tx_ring;
if (ring) {
packets = ACCESS_ONCE(ring->total_packets);
if (packets)
avg_wire_size = max_t(u32, avg_wire_size,
ring->total_bytes / packets);
}
if (!avg_wire_size)
goto clear_counts;
avg_wire_size += 24;
avg_wire_size = min(avg_wire_size, 3000);
if ((avg_wire_size > 300) && (avg_wire_size < 1200))
new_val = avg_wire_size / 3;
else
new_val = avg_wire_size / 2;
if (adapter->rx_itr_setting == 3 && new_val < 196)
new_val = 196;
set_itr_val:
if (new_val != q_vector->itr_val) {
q_vector->itr_val = new_val;
q_vector->set_itr = 1;
}
clear_counts:
if (q_vector->rx_ring) {
q_vector->rx_ring->total_bytes = 0;
q_vector->rx_ring->total_packets = 0;
}
if (q_vector->tx_ring) {
q_vector->tx_ring->total_bytes = 0;
q_vector->tx_ring->total_packets = 0;
}
}
static unsigned int igb_update_itr(struct igb_adapter *adapter, u16 itr_setting,
int packets, int bytes)
{
unsigned int retval = itr_setting;
if (packets == 0)
goto update_itr_done;
switch (itr_setting) {
case lowest_latency:
if (bytes/packets > 8000)
retval = bulk_latency;
else if ((packets < 5) && (bytes > 512))
retval = low_latency;
break;
case low_latency:
if (bytes > 10000) {
if (bytes/packets > 8000) {
retval = bulk_latency;
} else if ((packets < 10) || ((bytes/packets) > 1200)) {
retval = bulk_latency;
} else if ((packets > 35)) {
retval = lowest_latency;
}
} else if (bytes/packets > 2000) {
retval = bulk_latency;
} else if (packets <= 2 && bytes < 512) {
retval = lowest_latency;
}
break;
case bulk_latency:
if (bytes > 25000) {
if (packets > 35)
retval = low_latency;
} else if (bytes < 1500) {
retval = low_latency;
}
break;
}
update_itr_done:
return retval;
}
static void igb_set_itr(struct igb_adapter *adapter)
{
struct igb_q_vector *q_vector = adapter->q_vector[0];
u16 current_itr;
u32 new_itr = q_vector->itr_val;
if (adapter->link_speed != SPEED_1000) {
current_itr = 0;
new_itr = 4000;
goto set_itr_now;
}
adapter->rx_itr = igb_update_itr(adapter,
adapter->rx_itr,
q_vector->rx_ring->total_packets,
q_vector->rx_ring->total_bytes);
adapter->tx_itr = igb_update_itr(adapter,
adapter->tx_itr,
q_vector->tx_ring->total_packets,
q_vector->tx_ring->total_bytes);
current_itr = max(adapter->rx_itr, adapter->tx_itr);
if (adapter->rx_itr_setting == 3 && current_itr == lowest_latency)
current_itr = low_latency;
switch (current_itr) {
case lowest_latency:
new_itr = 56;
break;
case low_latency:
new_itr = 196;
break;
case bulk_latency:
new_itr = 980;
break;
default:
break;
}
set_itr_now:
q_vector->rx_ring->total_bytes = 0;
q_vector->rx_ring->total_packets = 0;
q_vector->tx_ring->total_bytes = 0;
q_vector->tx_ring->total_packets = 0;
if (new_itr != q_vector->itr_val) {
new_itr = new_itr > q_vector->itr_val ?
max((new_itr * q_vector->itr_val) /
(new_itr + (q_vector->itr_val >> 2)),
new_itr) :
new_itr;
q_vector->itr_val = new_itr;
q_vector->set_itr = 1;
}
}
static inline int igb_tso_adv(struct igb_ring *tx_ring,
struct sk_buff *skb, u32 tx_flags, u8 *hdr_len)
{
struct e1000_adv_tx_context_desc *context_desc;
unsigned int i;
int err;
struct igb_buffer *buffer_info;
u32 info = 0, tu_cmd = 0;
u32 mss_l4len_idx;
u8 l4len;
if (skb_header_cloned(skb)) {
err = pskb_expand_head(skb, 0, 0, GFP_ATOMIC);
if (err)
return err;
}
l4len = tcp_hdrlen(skb);
*hdr_len += l4len;
if (skb->protocol == htons(ETH_P_IP)) {
struct iphdr *iph = ip_hdr(skb);
iph->tot_len = 0;
iph->check = 0;
tcp_hdr(skb)->check = ~csum_tcpudp_magic(iph->saddr,
iph->daddr, 0,
IPPROTO_TCP,
0);
} else if (skb_is_gso_v6(skb)) {
ipv6_hdr(skb)->payload_len = 0;
tcp_hdr(skb)->check = ~csum_ipv6_magic(&ipv6_hdr(skb)->saddr,
&ipv6_hdr(skb)->daddr,
0, IPPROTO_TCP, 0);
}
i = tx_ring->next_to_use;
buffer_info = &tx_ring->buffer_info[i];
context_desc = E1000_TX_CTXTDESC_ADV(*tx_ring, i);
if (tx_flags & IGB_TX_FLAGS_VLAN)
info |= (tx_flags & IGB_TX_FLAGS_VLAN_MASK);
info |= (skb_network_offset(skb) << E1000_ADVTXD_MACLEN_SHIFT);
*hdr_len += skb_network_offset(skb);
info |= skb_network_header_len(skb);
*hdr_len += skb_network_header_len(skb);
context_desc->vlan_macip_lens = cpu_to_le32(info);
tu_cmd |= (E1000_TXD_CMD_DEXT | E1000_ADVTXD_DTYP_CTXT);
if (skb->protocol == htons(ETH_P_IP))
tu_cmd |= E1000_ADVTXD_TUCMD_IPV4;
tu_cmd |= E1000_ADVTXD_TUCMD_L4T_TCP;
context_desc->type_tucmd_mlhl = cpu_to_le32(tu_cmd);
mss_l4len_idx = (skb_shinfo(skb)->gso_size << E1000_ADVTXD_MSS_SHIFT);
mss_l4len_idx |= (l4len << E1000_ADVTXD_L4LEN_SHIFT);
if (tx_ring->flags & IGB_RING_FLAG_TX_CTX_IDX)
mss_l4len_idx |= tx_ring->reg_idx << 4;
context_desc->mss_l4len_idx = cpu_to_le32(mss_l4len_idx);
context_desc->seqnum_seed = 0;
buffer_info->time_stamp = jiffies;
buffer_info->next_to_watch = i;
buffer_info->dma = 0;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
return true;
}
static inline bool igb_tx_csum_adv(struct igb_ring *tx_ring,
struct sk_buff *skb, u32 tx_flags)
{
struct e1000_adv_tx_context_desc *context_desc;
struct device *dev = tx_ring->dev;
struct igb_buffer *buffer_info;
u32 info = 0, tu_cmd = 0;
unsigned int i;
if ((skb->ip_summed == CHECKSUM_PARTIAL) ||
(tx_flags & IGB_TX_FLAGS_VLAN)) {
i = tx_ring->next_to_use;
buffer_info = &tx_ring->buffer_info[i];
context_desc = E1000_TX_CTXTDESC_ADV(*tx_ring, i);
if (tx_flags & IGB_TX_FLAGS_VLAN)
info |= (tx_flags & IGB_TX_FLAGS_VLAN_MASK);
info |= (skb_network_offset(skb) << E1000_ADVTXD_MACLEN_SHIFT);
if (skb->ip_summed == CHECKSUM_PARTIAL)
info |= skb_network_header_len(skb);
context_desc->vlan_macip_lens = cpu_to_le32(info);
tu_cmd |= (E1000_TXD_CMD_DEXT | E1000_ADVTXD_DTYP_CTXT);
if (skb->ip_summed == CHECKSUM_PARTIAL) {
__be16 protocol;
if (skb->protocol == cpu_to_be16(ETH_P_8021Q)) {
const struct vlan_ethhdr *vhdr =
(const struct vlan_ethhdr*)skb->data;
protocol = vhdr->h_vlan_encapsulated_proto;
} else {
protocol = skb->protocol;
}
switch (protocol) {
case cpu_to_be16(ETH_P_IP):
tu_cmd |= E1000_ADVTXD_TUCMD_IPV4;
if (ip_hdr(skb)->protocol == IPPROTO_TCP)
tu_cmd |= E1000_ADVTXD_TUCMD_L4T_TCP;
else if (ip_hdr(skb)->protocol == IPPROTO_SCTP)
tu_cmd |= E1000_ADVTXD_TUCMD_L4T_SCTP;
break;
case cpu_to_be16(ETH_P_IPV6):
if (ipv6_hdr(skb)->nexthdr == IPPROTO_TCP)
tu_cmd |= E1000_ADVTXD_TUCMD_L4T_TCP;
else if (ipv6_hdr(skb)->nexthdr == IPPROTO_SCTP)
tu_cmd |= E1000_ADVTXD_TUCMD_L4T_SCTP;
break;
default:
if (unlikely(net_ratelimit()))
dev_warn(dev,
"partial checksum but proto=%x!\n",
skb->protocol);
break;
}
}
context_desc->type_tucmd_mlhl = cpu_to_le32(tu_cmd);
context_desc->seqnum_seed = 0;
if (tx_ring->flags & IGB_RING_FLAG_TX_CTX_IDX)
context_desc->mss_l4len_idx =
cpu_to_le32(tx_ring->reg_idx << 4);
buffer_info->time_stamp = jiffies;
buffer_info->next_to_watch = i;
buffer_info->dma = 0;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
return true;
}
return false;
}
static inline int igb_tx_map_adv(struct igb_ring *tx_ring, struct sk_buff *skb,
unsigned int first)
{
struct igb_buffer *buffer_info;
struct device *dev = tx_ring->dev;
unsigned int hlen = skb_headlen(skb);
unsigned int count = 0, i;
unsigned int f;
u16 gso_segs = skb_shinfo(skb)->gso_segs ?: 1;
i = tx_ring->next_to_use;
buffer_info = &tx_ring->buffer_info[i];
BUG_ON(hlen >= IGB_MAX_DATA_PER_TXD);
buffer_info->length = hlen;
buffer_info->time_stamp = jiffies;
buffer_info->next_to_watch = i;
buffer_info->dma = dma_map_single(dev, skb->data, hlen,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, buffer_info->dma))
goto dma_error;
for (f = 0; f < skb_shinfo(skb)->nr_frags; f++) {
struct skb_frag_struct *frag = &skb_shinfo(skb)->frags[f];
unsigned int len = frag->size;
count++;
i++;
if (i == tx_ring->count)
i = 0;
buffer_info = &tx_ring->buffer_info[i];
BUG_ON(len >= IGB_MAX_DATA_PER_TXD);
buffer_info->length = len;
buffer_info->time_stamp = jiffies;
buffer_info->next_to_watch = i;
buffer_info->mapped_as_page = true;
buffer_info->dma = dma_map_page(dev,
frag->page,
frag->page_offset,
len,
DMA_TO_DEVICE);
if (dma_mapping_error(dev, buffer_info->dma))
goto dma_error;
}
tx_ring->buffer_info[i].skb = skb;
tx_ring->buffer_info[i].tx_flags = skb_shinfo(skb)->tx_flags;
tx_ring->buffer_info[i].bytecount = ((gso_segs - 1) * hlen) + skb->len;
tx_ring->buffer_info[i].gso_segs = gso_segs;
tx_ring->buffer_info[first].next_to_watch = i;
return ++count;
dma_error:
dev_err(dev, "TX DMA map failed\n");
buffer_info->dma = 0;
buffer_info->time_stamp = 0;
buffer_info->length = 0;
buffer_info->next_to_watch = 0;
buffer_info->mapped_as_page = false;
while (count--) {
if (i == 0)
i = tx_ring->count;
i--;
buffer_info = &tx_ring->buffer_info[i];
igb_unmap_and_free_tx_resource(tx_ring, buffer_info);
}
return 0;
}
static inline void igb_tx_queue_adv(struct igb_ring *tx_ring,
u32 tx_flags, int count, u32 paylen,
u8 hdr_len)
{
union e1000_adv_tx_desc *tx_desc;
struct igb_buffer *buffer_info;
u32 olinfo_status = 0, cmd_type_len;
unsigned int i = tx_ring->next_to_use;
cmd_type_len = (E1000_ADVTXD_DTYP_DATA | E1000_ADVTXD_DCMD_IFCS |
E1000_ADVTXD_DCMD_DEXT);
if (tx_flags & IGB_TX_FLAGS_VLAN)
cmd_type_len |= E1000_ADVTXD_DCMD_VLE;
if (tx_flags & IGB_TX_FLAGS_TSTAMP)
cmd_type_len |= E1000_ADVTXD_MAC_TSTAMP;
if (tx_flags & IGB_TX_FLAGS_TSO) {
cmd_type_len |= E1000_ADVTXD_DCMD_TSE;
olinfo_status |= E1000_TXD_POPTS_TXSM << 8;
if (tx_flags & IGB_TX_FLAGS_IPV4)
olinfo_status |= E1000_TXD_POPTS_IXSM << 8;
} else if (tx_flags & IGB_TX_FLAGS_CSUM) {
olinfo_status |= E1000_TXD_POPTS_TXSM << 8;
}
if ((tx_ring->flags & IGB_RING_FLAG_TX_CTX_IDX) &&
(tx_flags & (IGB_TX_FLAGS_CSUM |
IGB_TX_FLAGS_TSO |
IGB_TX_FLAGS_VLAN)))
olinfo_status |= tx_ring->reg_idx << 4;
olinfo_status |= ((paylen - hdr_len) << E1000_ADVTXD_PAYLEN_SHIFT);
do {
buffer_info = &tx_ring->buffer_info[i];
tx_desc = E1000_TX_DESC_ADV(*tx_ring, i);
tx_desc->read.buffer_addr = cpu_to_le64(buffer_info->dma);
tx_desc->read.cmd_type_len =
cpu_to_le32(cmd_type_len | buffer_info->length);
tx_desc->read.olinfo_status = cpu_to_le32(olinfo_status);
count--;
i++;
if (i == tx_ring->count)
i = 0;
} while (count > 0);
tx_desc->read.cmd_type_len |= cpu_to_le32(IGB_ADVTXD_DCMD);
wmb();
tx_ring->next_to_use = i;
writel(i, tx_ring->tail);
mmiowb();
}
static int __igb_maybe_stop_tx(struct igb_ring *tx_ring, int size)
{
struct net_device *netdev = tx_ring->netdev;
netif_stop_subqueue(netdev, tx_ring->queue_index);
smp_mb();
if (igb_desc_unused(tx_ring) < size)
return -EBUSY;
netif_wake_subqueue(netdev, tx_ring->queue_index);
u64_stats_update_begin(&tx_ring->tx_syncp2);
tx_ring->tx_stats.restart_queue2++;
u64_stats_update_end(&tx_ring->tx_syncp2);
return 0;
}
static inline int igb_maybe_stop_tx(struct igb_ring *tx_ring, int size)
{
if (igb_desc_unused(tx_ring) >= size)
return 0;
return __igb_maybe_stop_tx(tx_ring, size);
}
netdev_tx_t igb_xmit_frame_ring_adv(struct sk_buff *skb,
struct igb_ring *tx_ring)
{
int tso = 0, count;
u32 tx_flags = 0;
u16 first;
u8 hdr_len = 0;
if (igb_maybe_stop_tx(tx_ring, skb_shinfo(skb)->nr_frags + 4)) {
return NETDEV_TX_BUSY;
}
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
tx_flags |= IGB_TX_FLAGS_TSTAMP;
}
if (vlan_tx_tag_present(skb)) {
tx_flags |= IGB_TX_FLAGS_VLAN;
tx_flags |= (vlan_tx_tag_get(skb) << IGB_TX_FLAGS_VLAN_SHIFT);
}
if (skb->protocol == htons(ETH_P_IP))
tx_flags |= IGB_TX_FLAGS_IPV4;
first = tx_ring->next_to_use;
if (skb_is_gso(skb)) {
tso = igb_tso_adv(tx_ring, skb, tx_flags, &hdr_len);
if (tso < 0) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
}
if (tso)
tx_flags |= IGB_TX_FLAGS_TSO;
else if (igb_tx_csum_adv(tx_ring, skb, tx_flags) &&
(skb->ip_summed == CHECKSUM_PARTIAL))
tx_flags |= IGB_TX_FLAGS_CSUM;
count = igb_tx_map_adv(tx_ring, skb, first);
if (!count) {
dev_kfree_skb_any(skb);
tx_ring->buffer_info[first].time_stamp = 0;
tx_ring->next_to_use = first;
return NETDEV_TX_OK;
}
igb_tx_queue_adv(tx_ring, tx_flags, count, skb->len, hdr_len);
igb_maybe_stop_tx(tx_ring, MAX_SKB_FRAGS + 4);
return NETDEV_TX_OK;
}
static netdev_tx_t igb_xmit_frame_adv(struct sk_buff *skb,
struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct igb_ring *tx_ring;
int r_idx = 0;
if (test_bit(__IGB_DOWN, &adapter->state)) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
if (skb->len <= 0) {
dev_kfree_skb_any(skb);
return NETDEV_TX_OK;
}
r_idx = skb->queue_mapping & (IGB_ABS_MAX_TX_QUEUES - 1);
tx_ring = adapter->multi_tx_table[r_idx];
return igb_xmit_frame_ring_adv(skb, tx_ring);
}
static void igb_tx_timeout(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
adapter->tx_timeout_count++;
if (hw->mac.type == e1000_82580)
hw->dev_spec._82575.global_device_reset = true;
schedule_work(&adapter->reset_task);
wr32(E1000_EICS,
(adapter->eims_enable_mask & ~adapter->eims_other));
}
static void igb_reset_task(struct work_struct *work)
{
struct igb_adapter *adapter;
adapter = container_of(work, struct igb_adapter, reset_task);
igb_dump(adapter);
netdev_err(adapter->netdev, "Reset adapter\n");
igb_reinit_locked(adapter);
}
static struct rtnl_link_stats64 *igb_get_stats64(struct net_device *netdev,
struct rtnl_link_stats64 *stats)
{
struct igb_adapter *adapter = netdev_priv(netdev);
spin_lock(&adapter->stats64_lock);
igb_update_stats(adapter, &adapter->stats64);
memcpy(stats, &adapter->stats64, sizeof(*stats));
spin_unlock(&adapter->stats64_lock);
return stats;
}
static int igb_change_mtu(struct net_device *netdev, int new_mtu)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct pci_dev *pdev = adapter->pdev;
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN;
u32 rx_buffer_len, i;
if ((new_mtu < 68) || (max_frame > MAX_JUMBO_FRAME_SIZE)) {
dev_err(&pdev->dev, "Invalid MTU setting\n");
return -EINVAL;
}
if (max_frame > MAX_STD_JUMBO_FRAME_SIZE) {
dev_err(&pdev->dev, "MTU > 9216 not supported.\n");
return -EINVAL;
}
while (test_and_set_bit(__IGB_RESETTING, &adapter->state))
msleep(1);
adapter->max_frame_size = max_frame;
if (adapter->hw.mac.type == e1000_82580)
max_frame += IGB_TS_HDR_LEN;
if (max_frame <= IGB_RXBUFFER_1024)
rx_buffer_len = IGB_RXBUFFER_1024;
else if (max_frame <= MAXIMUM_ETHERNET_VLAN_SIZE)
rx_buffer_len = MAXIMUM_ETHERNET_VLAN_SIZE;
else
rx_buffer_len = IGB_RXBUFFER_128;
if ((max_frame == ETH_FRAME_LEN + ETH_FCS_LEN + IGB_TS_HDR_LEN) ||
(max_frame == MAXIMUM_ETHERNET_VLAN_SIZE + IGB_TS_HDR_LEN))
rx_buffer_len = MAXIMUM_ETHERNET_VLAN_SIZE + IGB_TS_HDR_LEN;
if ((adapter->hw.mac.type == e1000_82580) &&
(rx_buffer_len == IGB_RXBUFFER_128))
rx_buffer_len += IGB_RXBUFFER_64;
if (netif_running(netdev))
igb_down(adapter);
dev_info(&pdev->dev, "changing MTU from %d to %d\n",
netdev->mtu, new_mtu);
netdev->mtu = new_mtu;
for (i = 0; i < adapter->num_rx_queues; i++)
adapter->rx_ring[i]->rx_buffer_len = rx_buffer_len;
if (netif_running(netdev))
igb_up(adapter);
else
igb_reset(adapter);
clear_bit(__IGB_RESETTING, &adapter->state);
return 0;
}
void igb_update_stats(struct igb_adapter *adapter,
struct rtnl_link_stats64 *net_stats)
{
struct e1000_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
u32 reg, mpc;
u16 phy_tmp;
int i;
u64 bytes, packets;
unsigned int start;
u64 _bytes, _packets;
#define PHY_IDLE_ERROR_COUNT_MASK 0x00FF
if (adapter->link_speed == 0)
return;
if (pci_channel_offline(pdev))
return;
bytes = 0;
packets = 0;
for (i = 0; i < adapter->num_rx_queues; i++) {
u32 rqdpc_tmp = rd32(E1000_RQDPC(i)) & 0x0FFF;
struct igb_ring *ring = adapter->rx_ring[i];
ring->rx_stats.drops += rqdpc_tmp;
net_stats->rx_fifo_errors += rqdpc_tmp;
do {
start = u64_stats_fetch_begin_bh(&ring->rx_syncp);
_bytes = ring->rx_stats.bytes;
_packets = ring->rx_stats.packets;
} while (u64_stats_fetch_retry_bh(&ring->rx_syncp, start));
bytes += _bytes;
packets += _packets;
}
net_stats->rx_bytes = bytes;
net_stats->rx_packets = packets;
bytes = 0;
packets = 0;
for (i = 0; i < adapter->num_tx_queues; i++) {
struct igb_ring *ring = adapter->tx_ring[i];
do {
start = u64_stats_fetch_begin_bh(&ring->tx_syncp);
_bytes = ring->tx_stats.bytes;
_packets = ring->tx_stats.packets;
} while (u64_stats_fetch_retry_bh(&ring->tx_syncp, start));
bytes += _bytes;
packets += _packets;
}
net_stats->tx_bytes = bytes;
net_stats->tx_packets = packets;
adapter->stats.crcerrs += rd32(E1000_CRCERRS);
adapter->stats.gprc += rd32(E1000_GPRC);
adapter->stats.gorc += rd32(E1000_GORCL);
rd32(E1000_GORCH);
adapter->stats.bprc += rd32(E1000_BPRC);
adapter->stats.mprc += rd32(E1000_MPRC);
adapter->stats.roc += rd32(E1000_ROC);
adapter->stats.prc64 += rd32(E1000_PRC64);
adapter->stats.prc127 += rd32(E1000_PRC127);
adapter->stats.prc255 += rd32(E1000_PRC255);
adapter->stats.prc511 += rd32(E1000_PRC511);
adapter->stats.prc1023 += rd32(E1000_PRC1023);
adapter->stats.prc1522 += rd32(E1000_PRC1522);
adapter->stats.symerrs += rd32(E1000_SYMERRS);
adapter->stats.sec += rd32(E1000_SEC);
mpc = rd32(E1000_MPC);
adapter->stats.mpc += mpc;
net_stats->rx_fifo_errors += mpc;
adapter->stats.scc += rd32(E1000_SCC);
adapter->stats.ecol += rd32(E1000_ECOL);
adapter->stats.mcc += rd32(E1000_MCC);
adapter->stats.latecol += rd32(E1000_LATECOL);
adapter->stats.dc += rd32(E1000_DC);
adapter->stats.rlec += rd32(E1000_RLEC);
adapter->stats.xonrxc += rd32(E1000_XONRXC);
adapter->stats.xontxc += rd32(E1000_XONTXC);
adapter->stats.xoffrxc += rd32(E1000_XOFFRXC);
adapter->stats.xofftxc += rd32(E1000_XOFFTXC);
adapter->stats.fcruc += rd32(E1000_FCRUC);
adapter->stats.gptc += rd32(E1000_GPTC);
adapter->stats.gotc += rd32(E1000_GOTCL);
rd32(E1000_GOTCH);
adapter->stats.rnbc += rd32(E1000_RNBC);
adapter->stats.ruc += rd32(E1000_RUC);
adapter->stats.rfc += rd32(E1000_RFC);
adapter->stats.rjc += rd32(E1000_RJC);
adapter->stats.tor += rd32(E1000_TORH);
adapter->stats.tot += rd32(E1000_TOTH);
adapter->stats.tpr += rd32(E1000_TPR);
adapter->stats.ptc64 += rd32(E1000_PTC64);
adapter->stats.ptc127 += rd32(E1000_PTC127);
adapter->stats.ptc255 += rd32(E1000_PTC255);
adapter->stats.ptc511 += rd32(E1000_PTC511);
adapter->stats.ptc1023 += rd32(E1000_PTC1023);
adapter->stats.ptc1522 += rd32(E1000_PTC1522);
adapter->stats.mptc += rd32(E1000_MPTC);
adapter->stats.bptc += rd32(E1000_BPTC);
adapter->stats.tpt += rd32(E1000_TPT);
adapter->stats.colc += rd32(E1000_COLC);
adapter->stats.algnerrc += rd32(E1000_ALGNERRC);
reg = rd32(E1000_CTRL_EXT);
if (!(reg & E1000_CTRL_EXT_LINK_MODE_MASK)) {
adapter->stats.rxerrc += rd32(E1000_RXERRC);
adapter->stats.tncrs += rd32(E1000_TNCRS);
}
adapter->stats.tsctc += rd32(E1000_TSCTC);
adapter->stats.tsctfc += rd32(E1000_TSCTFC);
adapter->stats.iac += rd32(E1000_IAC);
adapter->stats.icrxoc += rd32(E1000_ICRXOC);
adapter->stats.icrxptc += rd32(E1000_ICRXPTC);
adapter->stats.icrxatc += rd32(E1000_ICRXATC);
adapter->stats.ictxptc += rd32(E1000_ICTXPTC);
adapter->stats.ictxatc += rd32(E1000_ICTXATC);
adapter->stats.ictxqec += rd32(E1000_ICTXQEC);
adapter->stats.ictxqmtc += rd32(E1000_ICTXQMTC);
adapter->stats.icrxdmtc += rd32(E1000_ICRXDMTC);
net_stats->multicast = adapter->stats.mprc;
net_stats->collisions = adapter->stats.colc;
net_stats->rx_errors = adapter->stats.rxerrc +
adapter->stats.crcerrs + adapter->stats.algnerrc +
adapter->stats.ruc + adapter->stats.roc +
adapter->stats.cexterr;
net_stats->rx_length_errors = adapter->stats.ruc +
adapter->stats.roc;
net_stats->rx_crc_errors = adapter->stats.crcerrs;
net_stats->rx_frame_errors = adapter->stats.algnerrc;
net_stats->rx_missed_errors = adapter->stats.mpc;
net_stats->tx_errors = adapter->stats.ecol +
adapter->stats.latecol;
net_stats->tx_aborted_errors = adapter->stats.ecol;
net_stats->tx_window_errors = adapter->stats.latecol;
net_stats->tx_carrier_errors = adapter->stats.tncrs;
if (hw->phy.media_type == e1000_media_type_copper) {
if ((adapter->link_speed == SPEED_1000) &&
(!igb_read_phy_reg(hw, PHY_1000T_STATUS, &phy_tmp))) {
phy_tmp &= PHY_IDLE_ERROR_COUNT_MASK;
adapter->phy_stats.idle_errors += phy_tmp;
}
}
adapter->stats.mgptc += rd32(E1000_MGTPTC);
adapter->stats.mgprc += rd32(E1000_MGTPRC);
adapter->stats.mgpdc += rd32(E1000_MGTPDC);
reg = rd32(E1000_MANC);
if (reg & E1000_MANC_EN_BMC2OS) {
adapter->stats.o2bgptc += rd32(E1000_O2BGPTC);
adapter->stats.o2bspc += rd32(E1000_O2BSPC);
adapter->stats.b2ospc += rd32(E1000_B2OSPC);
adapter->stats.b2ogprc += rd32(E1000_B2OGPRC);
}
}
static irqreturn_t igb_msix_other(int irq, void *data)
{
struct igb_adapter *adapter = data;
struct e1000_hw *hw = &adapter->hw;
u32 icr = rd32(E1000_ICR);
if (icr & E1000_ICR_DRSTA)
schedule_work(&adapter->reset_task);
if (icr & E1000_ICR_DOUTSYNC) {
adapter->stats.doosync++;
igb_check_wvbr(adapter);
}
if (icr & E1000_ICR_VMMB)
igb_msg_task(adapter);
if (icr & E1000_ICR_LSC) {
hw->mac.get_link_status = 1;
if (!test_bit(__IGB_DOWN, &adapter->state))
mod_timer(&adapter->watchdog_timer, jiffies + 1);
}
if (adapter->vfs_allocated_count)
wr32(E1000_IMS, E1000_IMS_LSC |
E1000_IMS_VMMB |
E1000_IMS_DOUTSYNC);
else
wr32(E1000_IMS, E1000_IMS_LSC | E1000_IMS_DOUTSYNC);
wr32(E1000_EIMS, adapter->eims_other);
return IRQ_HANDLED;
}
static void igb_write_itr(struct igb_q_vector *q_vector)
{
struct igb_adapter *adapter = q_vector->adapter;
u32 itr_val = q_vector->itr_val & 0x7FFC;
if (!q_vector->set_itr)
return;
if (!itr_val)
itr_val = 0x4;
if (adapter->hw.mac.type == e1000_82575)
itr_val |= itr_val << 16;
else
itr_val |= 0x8000000;
writel(itr_val, q_vector->itr_register);
q_vector->set_itr = 0;
}
static irqreturn_t igb_msix_ring(int irq, void *data)
{
struct igb_q_vector *q_vector = data;
igb_write_itr(q_vector);
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static void igb_update_dca(struct igb_q_vector *q_vector)
{
struct igb_adapter *adapter = q_vector->adapter;
struct e1000_hw *hw = &adapter->hw;
int cpu = get_cpu();
if (q_vector->cpu == cpu)
goto out_no_update;
if (q_vector->tx_ring) {
int q = q_vector->tx_ring->reg_idx;
u32 dca_txctrl = rd32(E1000_DCA_TXCTRL(q));
if (hw->mac.type == e1000_82575) {
dca_txctrl &= ~E1000_DCA_TXCTRL_CPUID_MASK;
dca_txctrl |= dca3_get_tag(&adapter->pdev->dev, cpu);
} else {
dca_txctrl &= ~E1000_DCA_TXCTRL_CPUID_MASK_82576;
dca_txctrl |= dca3_get_tag(&adapter->pdev->dev, cpu) <<
E1000_DCA_TXCTRL_CPUID_SHIFT;
}
dca_txctrl |= E1000_DCA_TXCTRL_DESC_DCA_EN;
wr32(E1000_DCA_TXCTRL(q), dca_txctrl);
}
if (q_vector->rx_ring) {
int q = q_vector->rx_ring->reg_idx;
u32 dca_rxctrl = rd32(E1000_DCA_RXCTRL(q));
if (hw->mac.type == e1000_82575) {
dca_rxctrl &= ~E1000_DCA_RXCTRL_CPUID_MASK;
dca_rxctrl |= dca3_get_tag(&adapter->pdev->dev, cpu);
} else {
dca_rxctrl &= ~E1000_DCA_RXCTRL_CPUID_MASK_82576;
dca_rxctrl |= dca3_get_tag(&adapter->pdev->dev, cpu) <<
E1000_DCA_RXCTRL_CPUID_SHIFT;
}
dca_rxctrl |= E1000_DCA_RXCTRL_DESC_DCA_EN;
dca_rxctrl |= E1000_DCA_RXCTRL_HEAD_DCA_EN;
dca_rxctrl |= E1000_DCA_RXCTRL_DATA_DCA_EN;
wr32(E1000_DCA_RXCTRL(q), dca_rxctrl);
}
q_vector->cpu = cpu;
out_no_update:
put_cpu();
}
static void igb_setup_dca(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
int i;
if (!(adapter->flags & IGB_FLAG_DCA_ENABLED))
return;
wr32(E1000_DCA_CTRL, E1000_DCA_CTRL_DCA_MODE_CB2);
for (i = 0; i < adapter->num_q_vectors; i++) {
adapter->q_vector[i]->cpu = -1;
igb_update_dca(adapter->q_vector[i]);
}
}
static int __igb_notify_dca(struct device *dev, void *data)
{
struct net_device *netdev = dev_get_drvdata(dev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct pci_dev *pdev = adapter->pdev;
struct e1000_hw *hw = &adapter->hw;
unsigned long event = *(unsigned long *)data;
switch (event) {
case DCA_PROVIDER_ADD:
if (adapter->flags & IGB_FLAG_DCA_ENABLED)
break;
if (dca_add_requester(dev) == 0) {
adapter->flags |= IGB_FLAG_DCA_ENABLED;
dev_info(&pdev->dev, "DCA enabled\n");
igb_setup_dca(adapter);
break;
}
case DCA_PROVIDER_REMOVE:
if (adapter->flags & IGB_FLAG_DCA_ENABLED) {
dca_remove_requester(dev);
dev_info(&pdev->dev, "DCA disabled\n");
adapter->flags &= ~IGB_FLAG_DCA_ENABLED;
wr32(E1000_DCA_CTRL, E1000_DCA_CTRL_DCA_MODE_DISABLE);
}
break;
}
return 0;
}
static int igb_notify_dca(struct notifier_block *nb, unsigned long event,
void *p)
{
int ret_val;
ret_val = driver_for_each_device(&igb_driver.driver, NULL, &event,
__igb_notify_dca);
return ret_val ? NOTIFY_BAD : NOTIFY_DONE;
}
static void igb_ping_all_vfs(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 ping;
int i;
for (i = 0 ; i < adapter->vfs_allocated_count; i++) {
ping = E1000_PF_CONTROL_MSG;
if (adapter->vf_data[i].flags & IGB_VF_FLAG_CTS)
ping |= E1000_VT_MSGTYPE_CTS;
igb_write_mbx(hw, &ping, 1, i);
}
}
static int igb_set_vf_promisc(struct igb_adapter *adapter, u32 *msgbuf, u32 vf)
{
struct e1000_hw *hw = &adapter->hw;
u32 vmolr = rd32(E1000_VMOLR(vf));
struct vf_data_storage *vf_data = &adapter->vf_data[vf];
vf_data->flags &= ~(IGB_VF_FLAG_UNI_PROMISC |
IGB_VF_FLAG_MULTI_PROMISC);
vmolr &= ~(E1000_VMOLR_ROPE | E1000_VMOLR_ROMPE | E1000_VMOLR_MPME);
if (*msgbuf & E1000_VF_SET_PROMISC_MULTICAST) {
vmolr |= E1000_VMOLR_MPME;
vf_data->flags |= IGB_VF_FLAG_MULTI_PROMISC;
*msgbuf &= ~E1000_VF_SET_PROMISC_MULTICAST;
} else {
if (vf_data->num_vf_mc_hashes > 30) {
vmolr |= E1000_VMOLR_MPME;
} else if (vf_data->num_vf_mc_hashes) {
int j;
vmolr |= E1000_VMOLR_ROMPE;
for (j = 0; j < vf_data->num_vf_mc_hashes; j++)
igb_mta_set(hw, vf_data->vf_mc_hashes[j]);
}
}
wr32(E1000_VMOLR(vf), vmolr);
if (*msgbuf & E1000_VT_MSGINFO_MASK)
return -EINVAL;
return 0;
}
static int igb_set_vf_multicasts(struct igb_adapter *adapter,
u32 *msgbuf, u32 vf)
{
int n = (msgbuf[0] & E1000_VT_MSGINFO_MASK) >> E1000_VT_MSGINFO_SHIFT;
u16 *hash_list = (u16 *)&msgbuf[1];
struct vf_data_storage *vf_data = &adapter->vf_data[vf];
int i;
vf_data->num_vf_mc_hashes = n;
if (n > 30)
n = 30;
for (i = 0; i < n; i++)
vf_data->vf_mc_hashes[i] = hash_list[i];
igb_set_rx_mode(adapter->netdev);
return 0;
}
static void igb_restore_vf_multicasts(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
struct vf_data_storage *vf_data;
int i, j;
for (i = 0; i < adapter->vfs_allocated_count; i++) {
u32 vmolr = rd32(E1000_VMOLR(i));
vmolr &= ~(E1000_VMOLR_ROMPE | E1000_VMOLR_MPME);
vf_data = &adapter->vf_data[i];
if ((vf_data->num_vf_mc_hashes > 30) ||
(vf_data->flags & IGB_VF_FLAG_MULTI_PROMISC)) {
vmolr |= E1000_VMOLR_MPME;
} else if (vf_data->num_vf_mc_hashes) {
vmolr |= E1000_VMOLR_ROMPE;
for (j = 0; j < vf_data->num_vf_mc_hashes; j++)
igb_mta_set(hw, vf_data->vf_mc_hashes[j]);
}
wr32(E1000_VMOLR(i), vmolr);
}
}
static void igb_clear_vf_vfta(struct igb_adapter *adapter, u32 vf)
{
struct e1000_hw *hw = &adapter->hw;
u32 pool_mask, reg, vid;
int i;
pool_mask = 1 << (E1000_VLVF_POOLSEL_SHIFT + vf);
for (i = 0; i < E1000_VLVF_ARRAY_SIZE; i++) {
reg = rd32(E1000_VLVF(i));
reg &= ~pool_mask;
if (!(reg & E1000_VLVF_POOLSEL_MASK) &&
(reg & E1000_VLVF_VLANID_ENABLE)) {
reg = 0;
vid = reg & E1000_VLVF_VLANID_MASK;
igb_vfta_set(hw, vid, false);
}
wr32(E1000_VLVF(i), reg);
}
adapter->vf_data[vf].vlans_enabled = 0;
}
static s32 igb_vlvf_set(struct igb_adapter *adapter, u32 vid, bool add, u32 vf)
{
struct e1000_hw *hw = &adapter->hw;
u32 reg, i;
if (hw->mac.type < e1000_82576)
return -1;
if (!adapter->vfs_allocated_count)
return -1;
for (i = 0; i < E1000_VLVF_ARRAY_SIZE; i++) {
reg = rd32(E1000_VLVF(i));
if ((reg & E1000_VLVF_VLANID_ENABLE) &&
vid == (reg & E1000_VLVF_VLANID_MASK))
break;
}
if (add) {
if (i == E1000_VLVF_ARRAY_SIZE) {
for (i = 0; i < E1000_VLVF_ARRAY_SIZE; i++) {
reg = rd32(E1000_VLVF(i));
if (!(reg & E1000_VLVF_VLANID_ENABLE))
break;
}
}
if (i < E1000_VLVF_ARRAY_SIZE) {
reg |= 1 << (E1000_VLVF_POOLSEL_SHIFT + vf);
if (!(reg & E1000_VLVF_VLANID_ENABLE)) {
igb_vfta_set(hw, vid, true);
reg |= E1000_VLVF_VLANID_ENABLE;
}
reg &= ~E1000_VLVF_VLANID_MASK;
reg |= vid;
wr32(E1000_VLVF(i), reg);
if (vf >= adapter->vfs_allocated_count)
return 0;
if (!adapter->vf_data[vf].vlans_enabled) {
u32 size;
reg = rd32(E1000_VMOLR(vf));
size = reg & E1000_VMOLR_RLPML_MASK;
size += 4;
reg &= ~E1000_VMOLR_RLPML_MASK;
reg |= size;
wr32(E1000_VMOLR(vf), reg);
}
adapter->vf_data[vf].vlans_enabled++;
return 0;
}
} else {
if (i < E1000_VLVF_ARRAY_SIZE) {
reg &= ~(1 << (E1000_VLVF_POOLSEL_SHIFT + vf));
if (!(reg & E1000_VLVF_POOLSEL_MASK)) {
reg = 0;
igb_vfta_set(hw, vid, false);
}
wr32(E1000_VLVF(i), reg);
if (vf >= adapter->vfs_allocated_count)
return 0;
adapter->vf_data[vf].vlans_enabled--;
if (!adapter->vf_data[vf].vlans_enabled) {
u32 size;
reg = rd32(E1000_VMOLR(vf));
size = reg & E1000_VMOLR_RLPML_MASK;
size -= 4;
reg &= ~E1000_VMOLR_RLPML_MASK;
reg |= size;
wr32(E1000_VMOLR(vf), reg);
}
}
}
return 0;
}
static void igb_set_vmvir(struct igb_adapter *adapter, u32 vid, u32 vf)
{
struct e1000_hw *hw = &adapter->hw;
if (vid)
wr32(E1000_VMVIR(vf), (vid | E1000_VMVIR_VLANA_DEFAULT));
else
wr32(E1000_VMVIR(vf), 0);
}
static int igb_ndo_set_vf_vlan(struct net_device *netdev,
int vf, u16 vlan, u8 qos)
{
int err = 0;
struct igb_adapter *adapter = netdev_priv(netdev);
if ((vf >= adapter->vfs_allocated_count) || (vlan > 4095) || (qos > 7))
return -EINVAL;
if (vlan || qos) {
err = igb_vlvf_set(adapter, vlan, !!vlan, vf);
if (err)
goto out;
igb_set_vmvir(adapter, vlan | (qos << VLAN_PRIO_SHIFT), vf);
igb_set_vmolr(adapter, vf, !vlan);
adapter->vf_data[vf].pf_vlan = vlan;
adapter->vf_data[vf].pf_qos = qos;
dev_info(&adapter->pdev->dev,
"Setting VLAN %d, QOS 0x%x on VF %d\n", vlan, qos, vf);
if (test_bit(__IGB_DOWN, &adapter->state)) {
dev_warn(&adapter->pdev->dev,
"The VF VLAN has been set,"
" but the PF device is not up.\n");
dev_warn(&adapter->pdev->dev,
"Bring the PF device up before"
" attempting to use the VF device.\n");
}
} else {
igb_vlvf_set(adapter, adapter->vf_data[vf].pf_vlan,
false, vf);
igb_set_vmvir(adapter, vlan, vf);
igb_set_vmolr(adapter, vf, true);
adapter->vf_data[vf].pf_vlan = 0;
adapter->vf_data[vf].pf_qos = 0;
}
out:
return err;
}
static int igb_set_vf_vlan(struct igb_adapter *adapter, u32 *msgbuf, u32 vf)
{
int add = (msgbuf[0] & E1000_VT_MSGINFO_MASK) >> E1000_VT_MSGINFO_SHIFT;
int vid = (msgbuf[1] & E1000_VLVF_VLANID_MASK);
return igb_vlvf_set(adapter, vid, add, vf);
}
static inline void igb_vf_reset(struct igb_adapter *adapter, u32 vf)
{
adapter->vf_data[vf].flags &= IGB_VF_FLAG_PF_SET_MAC;
adapter->vf_data[vf].last_nack = jiffies;
igb_set_vmolr(adapter, vf, true);
igb_clear_vf_vfta(adapter, vf);
if (adapter->vf_data[vf].pf_vlan)
igb_ndo_set_vf_vlan(adapter->netdev, vf,
adapter->vf_data[vf].pf_vlan,
adapter->vf_data[vf].pf_qos);
else
igb_clear_vf_vfta(adapter, vf);
adapter->vf_data[vf].num_vf_mc_hashes = 0;
igb_set_rx_mode(adapter->netdev);
}
static void igb_vf_reset_event(struct igb_adapter *adapter, u32 vf)
{
unsigned char *vf_mac = adapter->vf_data[vf].vf_mac_addresses;
if (!(adapter->vf_data[vf].flags & IGB_VF_FLAG_PF_SET_MAC))
random_ether_addr(vf_mac);
igb_vf_reset(adapter, vf);
}
static void igb_vf_reset_msg(struct igb_adapter *adapter, u32 vf)
{
struct e1000_hw *hw = &adapter->hw;
unsigned char *vf_mac = adapter->vf_data[vf].vf_mac_addresses;
int rar_entry = hw->mac.rar_entry_count - (vf + 1);
u32 reg, msgbuf[3];
u8 *addr = (u8 *)(&msgbuf[1]);
igb_vf_reset(adapter, vf);
igb_rar_set_qsel(adapter, vf_mac, rar_entry, vf);
reg = rd32(E1000_VFTE);
wr32(E1000_VFTE, reg | (1 << vf));
reg = rd32(E1000_VFRE);
wr32(E1000_VFRE, reg | (1 << vf));
adapter->vf_data[vf].flags |= IGB_VF_FLAG_CTS;
msgbuf[0] = E1000_VF_RESET | E1000_VT_MSGTYPE_ACK;
memcpy(addr, vf_mac, 6);
igb_write_mbx(hw, msgbuf, 3, vf);
}
static int igb_set_vf_mac_addr(struct igb_adapter *adapter, u32 *msg, int vf)
{
unsigned char *addr = (char *)&msg[1];
int err = -1;
if (is_valid_ether_addr(addr))
err = igb_set_vf_mac(adapter, vf, addr);
return err;
}
static void igb_rcv_ack_from_vf(struct igb_adapter *adapter, u32 vf)
{
struct e1000_hw *hw = &adapter->hw;
struct vf_data_storage *vf_data = &adapter->vf_data[vf];
u32 msg = E1000_VT_MSGTYPE_NACK;
if (!(vf_data->flags & IGB_VF_FLAG_CTS) &&
time_after(jiffies, vf_data->last_nack + (2 * HZ))) {
igb_write_mbx(hw, &msg, 1, vf);
vf_data->last_nack = jiffies;
}
}
static void igb_rcv_msg_from_vf(struct igb_adapter *adapter, u32 vf)
{
struct pci_dev *pdev = adapter->pdev;
u32 msgbuf[E1000_VFMAILBOX_SIZE];
struct e1000_hw *hw = &adapter->hw;
struct vf_data_storage *vf_data = &adapter->vf_data[vf];
s32 retval;
retval = igb_read_mbx(hw, msgbuf, E1000_VFMAILBOX_SIZE, vf);
if (retval) {
dev_err(&pdev->dev, "Error receiving message from VF\n");
vf_data->flags &= ~IGB_VF_FLAG_CTS;
if (!time_after(jiffies, vf_data->last_nack + (2 * HZ)))
return;
goto out;
}
if (msgbuf[0] & (E1000_VT_MSGTYPE_ACK | E1000_VT_MSGTYPE_NACK))
return;
if (msgbuf[0] == E1000_VF_RESET) {
igb_vf_reset_msg(adapter, vf);
return;
}
if (!(vf_data->flags & IGB_VF_FLAG_CTS)) {
if (!time_after(jiffies, vf_data->last_nack + (2 * HZ)))
return;
retval = -1;
goto out;
}
switch ((msgbuf[0] & 0xFFFF)) {
case E1000_VF_SET_MAC_ADDR:
retval = -EINVAL;
if (!(vf_data->flags & IGB_VF_FLAG_PF_SET_MAC))
retval = igb_set_vf_mac_addr(adapter, msgbuf, vf);
else
dev_warn(&pdev->dev,
"VF %d attempted to override administratively "
"set MAC address\nReload the VF driver to "
"resume operations\n", vf);
break;
case E1000_VF_SET_PROMISC:
retval = igb_set_vf_promisc(adapter, msgbuf, vf);
break;
case E1000_VF_SET_MULTICAST:
retval = igb_set_vf_multicasts(adapter, msgbuf, vf);
break;
case E1000_VF_SET_LPE:
retval = igb_set_vf_rlpml(adapter, msgbuf[1], vf);
break;
case E1000_VF_SET_VLAN:
retval = -1;
if (vf_data->pf_vlan)
dev_warn(&pdev->dev,
"VF %d attempted to override administratively "
"set VLAN tag\nReload the VF driver to "
"resume operations\n", vf);
else
retval = igb_set_vf_vlan(adapter, msgbuf, vf);
break;
default:
dev_err(&pdev->dev, "Unhandled Msg %08x\n", msgbuf[0]);
retval = -1;
break;
}
msgbuf[0] |= E1000_VT_MSGTYPE_CTS;
out:
if (retval)
msgbuf[0] |= E1000_VT_MSGTYPE_NACK;
else
msgbuf[0] |= E1000_VT_MSGTYPE_ACK;
igb_write_mbx(hw, msgbuf, 1, vf);
}
static void igb_msg_task(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 vf;
for (vf = 0; vf < adapter->vfs_allocated_count; vf++) {
if (!igb_check_for_rst(hw, vf))
igb_vf_reset_event(adapter, vf);
if (!igb_check_for_msg(hw, vf))
igb_rcv_msg_from_vf(adapter, vf);
if (!igb_check_for_ack(hw, vf))
igb_rcv_ack_from_vf(adapter, vf);
}
}
static void igb_set_uta(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
int i;
if (hw->mac.type < e1000_82576)
return;
if (!adapter->vfs_allocated_count)
return;
for (i = 0; i < hw->mac.uta_reg_count; i++)
array_wr32(E1000_UTA, i, ~0);
}
static irqreturn_t igb_intr_msi(int irq, void *data)
{
struct igb_adapter *adapter = data;
struct igb_q_vector *q_vector = adapter->q_vector[0];
struct e1000_hw *hw = &adapter->hw;
u32 icr = rd32(E1000_ICR);
igb_write_itr(q_vector);
if (icr & E1000_ICR_DRSTA)
schedule_work(&adapter->reset_task);
if (icr & E1000_ICR_DOUTSYNC) {
adapter->stats.doosync++;
}
if (icr & (E1000_ICR_RXSEQ | E1000_ICR_LSC)) {
hw->mac.get_link_status = 1;
if (!test_bit(__IGB_DOWN, &adapter->state))
mod_timer(&adapter->watchdog_timer, jiffies + 1);
}
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static irqreturn_t igb_intr(int irq, void *data)
{
struct igb_adapter *adapter = data;
struct igb_q_vector *q_vector = adapter->q_vector[0];
struct e1000_hw *hw = &adapter->hw;
u32 icr = rd32(E1000_ICR);
if (!icr)
return IRQ_NONE;
igb_write_itr(q_vector);
if (!(icr & E1000_ICR_INT_ASSERTED))
return IRQ_NONE;
if (icr & E1000_ICR_DRSTA)
schedule_work(&adapter->reset_task);
if (icr & E1000_ICR_DOUTSYNC) {
adapter->stats.doosync++;
}
if (icr & (E1000_ICR_RXSEQ | E1000_ICR_LSC)) {
hw->mac.get_link_status = 1;
if (!test_bit(__IGB_DOWN, &adapter->state))
mod_timer(&adapter->watchdog_timer, jiffies + 1);
}
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static inline void igb_ring_irq_enable(struct igb_q_vector *q_vector)
{
struct igb_adapter *adapter = q_vector->adapter;
struct e1000_hw *hw = &adapter->hw;
if ((q_vector->rx_ring && (adapter->rx_itr_setting & 3)) ||
(!q_vector->rx_ring && (adapter->tx_itr_setting & 3))) {
if (!adapter->msix_entries)
igb_set_itr(adapter);
else
igb_update_ring_itr(q_vector);
}
if (!test_bit(__IGB_DOWN, &adapter->state)) {
if (adapter->msix_entries)
wr32(E1000_EIMS, q_vector->eims_value);
else
igb_irq_enable(adapter);
}
}
static int igb_poll(struct napi_struct *napi, int budget)
{
struct igb_q_vector *q_vector = container_of(napi,
struct igb_q_vector,
napi);
int tx_clean_complete = 1, work_done = 0;
#ifdef CONFIG_IGB_DCA
if (q_vector->adapter->flags & IGB_FLAG_DCA_ENABLED)
igb_update_dca(q_vector);
#endif
if (q_vector->tx_ring)
tx_clean_complete = igb_clean_tx_irq(q_vector);
if (q_vector->rx_ring)
igb_clean_rx_irq_adv(q_vector, &work_done, budget);
if (!tx_clean_complete)
work_done = budget;
if (work_done < budget) {
napi_complete(napi);
igb_ring_irq_enable(q_vector);
}
return work_done;
}
static void igb_systim_to_hwtstamp(struct igb_adapter *adapter,
struct skb_shared_hwtstamps *shhwtstamps,
u64 regval)
{
u64 ns;
if (adapter->hw.mac.type == e1000_82580)
regval <<= IGB_82580_TSYNC_SHIFT;
ns = timecounter_cyc2time(&adapter->clock, regval);
timecompare_update(&adapter->compare, ns);
memset(shhwtstamps, 0, sizeof(struct skb_shared_hwtstamps));
shhwtstamps->hwtstamp = ns_to_ktime(ns);
shhwtstamps->syststamp = timecompare_transform(&adapter->compare, ns);
}
static void igb_tx_hwtstamp(struct igb_q_vector *q_vector, struct igb_buffer *buffer_info)
{
struct igb_adapter *adapter = q_vector->adapter;
struct e1000_hw *hw = &adapter->hw;
struct skb_shared_hwtstamps shhwtstamps;
u64 regval;
if (likely(!(buffer_info->tx_flags & SKBTX_HW_TSTAMP)) ||
!(rd32(E1000_TSYNCTXCTL) & E1000_TSYNCTXCTL_VALID))
return;
regval = rd32(E1000_TXSTMPL);
regval |= (u64)rd32(E1000_TXSTMPH) << 32;
igb_systim_to_hwtstamp(adapter, &shhwtstamps, regval);
skb_tstamp_tx(buffer_info->skb, &shhwtstamps);
}
static bool igb_clean_tx_irq(struct igb_q_vector *q_vector)
{
struct igb_adapter *adapter = q_vector->adapter;
struct igb_ring *tx_ring = q_vector->tx_ring;
struct net_device *netdev = tx_ring->netdev;
struct e1000_hw *hw = &adapter->hw;
struct igb_buffer *buffer_info;
union e1000_adv_tx_desc *tx_desc, *eop_desc;
unsigned int total_bytes = 0, total_packets = 0;
unsigned int i, eop, count = 0;
bool cleaned = false;
i = tx_ring->next_to_clean;
eop = tx_ring->buffer_info[i].next_to_watch;
eop_desc = E1000_TX_DESC_ADV(*tx_ring, eop);
while ((eop_desc->wb.status & cpu_to_le32(E1000_TXD_STAT_DD)) &&
(count < tx_ring->count)) {
rmb();
for (cleaned = false; !cleaned; count++) {
tx_desc = E1000_TX_DESC_ADV(*tx_ring, i);
buffer_info = &tx_ring->buffer_info[i];
cleaned = (i == eop);
if (buffer_info->skb) {
total_bytes += buffer_info->bytecount;
total_packets += buffer_info->gso_segs;
igb_tx_hwtstamp(q_vector, buffer_info);
}
igb_unmap_and_free_tx_resource(tx_ring, buffer_info);
tx_desc->wb.status = 0;
i++;
if (i == tx_ring->count)
i = 0;
}
eop = tx_ring->buffer_info[i].next_to_watch;
eop_desc = E1000_TX_DESC_ADV(*tx_ring, eop);
}
tx_ring->next_to_clean = i;
if (unlikely(count &&
netif_carrier_ok(netdev) &&
igb_desc_unused(tx_ring) >= IGB_TX_QUEUE_WAKE)) {
smp_mb();
if (__netif_subqueue_stopped(netdev, tx_ring->queue_index) &&
!(test_bit(__IGB_DOWN, &adapter->state))) {
netif_wake_subqueue(netdev, tx_ring->queue_index);
u64_stats_update_begin(&tx_ring->tx_syncp);
tx_ring->tx_stats.restart_queue++;
u64_stats_update_end(&tx_ring->tx_syncp);
}
}
if (tx_ring->detect_tx_hung) {
tx_ring->detect_tx_hung = false;
if (tx_ring->buffer_info[i].time_stamp &&
time_after(jiffies, tx_ring->buffer_info[i].time_stamp +
(adapter->tx_timeout_factor * HZ)) &&
!(rd32(E1000_STATUS) & E1000_STATUS_TXOFF)) {
dev_err(tx_ring->dev,
"Detected Tx Unit Hang\n"
" Tx Queue <%d>\n"
" TDH <%x>\n"
" TDT <%x>\n"
" next_to_use <%x>\n"
" next_to_clean <%x>\n"
"buffer_info[next_to_clean]\n"
" time_stamp <%lx>\n"
" next_to_watch <%x>\n"
" jiffies <%lx>\n"
" desc.status <%x>\n",
tx_ring->queue_index,
readl(tx_ring->head),
readl(tx_ring->tail),
tx_ring->next_to_use,
tx_ring->next_to_clean,
tx_ring->buffer_info[eop].time_stamp,
eop,
jiffies,
eop_desc->wb.status);
netif_stop_subqueue(netdev, tx_ring->queue_index);
}
}
tx_ring->total_bytes += total_bytes;
tx_ring->total_packets += total_packets;
u64_stats_update_begin(&tx_ring->tx_syncp);
tx_ring->tx_stats.bytes += total_bytes;
tx_ring->tx_stats.packets += total_packets;
u64_stats_update_end(&tx_ring->tx_syncp);
return count < tx_ring->count;
}
static inline void igb_rx_checksum_adv(struct igb_ring *ring,
u32 status_err, struct sk_buff *skb)
{
skb_checksum_none_assert(skb);
if (!(ring->flags & IGB_RING_FLAG_RX_CSUM) ||
(status_err & E1000_RXD_STAT_IXSM))
return;
if (status_err &
(E1000_RXDEXT_STATERR_TCPE | E1000_RXDEXT_STATERR_IPE)) {
if ((skb->len == 60) &&
(ring->flags & IGB_RING_FLAG_RX_SCTP_CSUM)) {
u64_stats_update_begin(&ring->rx_syncp);
ring->rx_stats.csum_err++;
u64_stats_update_end(&ring->rx_syncp);
}
return;
}
if (status_err & (E1000_RXD_STAT_TCPCS | E1000_RXD_STAT_UDPCS))
skb->ip_summed = CHECKSUM_UNNECESSARY;
dev_dbg(ring->dev, "cksum success: bits %08X\n", status_err);
}
static void igb_rx_hwtstamp(struct igb_q_vector *q_vector, u32 staterr,
struct sk_buff *skb)
{
struct igb_adapter *adapter = q_vector->adapter;
struct e1000_hw *hw = &adapter->hw;
u64 regval;
if (staterr & E1000_RXDADV_STAT_TSIP) {
u32 *stamp = (u32 *)skb->data;
regval = le32_to_cpu(*(stamp + 2));
regval |= (u64)le32_to_cpu(*(stamp + 3)) << 32;
skb_pull(skb, IGB_TS_HDR_LEN);
} else {
if(!(rd32(E1000_TSYNCRXCTL) & E1000_TSYNCRXCTL_VALID))
return;
regval = rd32(E1000_RXSTMPL);
regval |= (u64)rd32(E1000_RXSTMPH) << 32;
}
igb_systim_to_hwtstamp(adapter, skb_hwtstamps(skb), regval);
}
static inline u16 igb_get_hlen(struct igb_ring *rx_ring,
union e1000_adv_rx_desc *rx_desc)
{
u16 hlen = (le16_to_cpu(rx_desc->wb.lower.lo_dword.hdr_info) &
E1000_RXDADV_HDRBUFLEN_MASK) >> E1000_RXDADV_HDRBUFLEN_SHIFT;
if (hlen > rx_ring->rx_buffer_len)
hlen = rx_ring->rx_buffer_len;
return hlen;
}
static bool igb_clean_rx_irq_adv(struct igb_q_vector *q_vector,
int *work_done, int budget)
{
struct igb_ring *rx_ring = q_vector->rx_ring;
struct net_device *netdev = rx_ring->netdev;
struct device *dev = rx_ring->dev;
union e1000_adv_rx_desc *rx_desc , *next_rxd;
struct igb_buffer *buffer_info , *next_buffer;
struct sk_buff *skb;
bool cleaned = false;
int cleaned_count = 0;
int current_node = numa_node_id();
unsigned int total_bytes = 0, total_packets = 0;
unsigned int i;
u32 staterr;
u16 length;
i = rx_ring->next_to_clean;
buffer_info = &rx_ring->buffer_info[i];
rx_desc = E1000_RX_DESC_ADV(*rx_ring, i);
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
while (staterr & E1000_RXD_STAT_DD) {
if (*work_done >= budget)
break;
(*work_done)++;
rmb();
skb = buffer_info->skb;
prefetch(skb->data - NET_IP_ALIGN);
buffer_info->skb = NULL;
i++;
if (i == rx_ring->count)
i = 0;
next_rxd = E1000_RX_DESC_ADV(*rx_ring, i);
prefetch(next_rxd);
next_buffer = &rx_ring->buffer_info[i];
length = le16_to_cpu(rx_desc->wb.upper.length);
cleaned = true;
cleaned_count++;
if (buffer_info->dma) {
dma_unmap_single(dev, buffer_info->dma,
rx_ring->rx_buffer_len,
DMA_FROM_DEVICE);
buffer_info->dma = 0;
if (rx_ring->rx_buffer_len >= IGB_RXBUFFER_1024) {
skb_put(skb, length);
goto send_up;
}
skb_put(skb, igb_get_hlen(rx_ring, rx_desc));
}
if (length) {
dma_unmap_page(dev, buffer_info->page_dma,
PAGE_SIZE / 2, DMA_FROM_DEVICE);
buffer_info->page_dma = 0;
skb_fill_page_desc(skb, skb_shinfo(skb)->nr_frags,
buffer_info->page,
buffer_info->page_offset,
length);
if ((page_count(buffer_info->page) != 1) ||
(page_to_nid(buffer_info->page) != current_node))
buffer_info->page = NULL;
else
get_page(buffer_info->page);
skb->len += length;
skb->data_len += length;
skb->truesize += length;
}
if (!(staterr & E1000_RXD_STAT_EOP)) {
buffer_info->skb = next_buffer->skb;
buffer_info->dma = next_buffer->dma;
next_buffer->skb = skb;
next_buffer->dma = 0;
goto next_desc;
}
send_up:
if (staterr & E1000_RXDEXT_ERR_FRAME_ERR_MASK) {
dev_kfree_skb_irq(skb);
goto next_desc;
}
if (staterr & (E1000_RXDADV_STAT_TSIP | E1000_RXDADV_STAT_TS))
igb_rx_hwtstamp(q_vector, staterr, skb);
total_bytes += skb->len;
total_packets++;
igb_rx_checksum_adv(rx_ring, staterr, skb);
skb->protocol = eth_type_trans(skb, netdev);
skb_record_rx_queue(skb, rx_ring->queue_index);
if (staterr & E1000_RXD_STAT_VP) {
u16 vid = le16_to_cpu(rx_desc->wb.upper.vlan);
__vlan_hwaccel_put_tag(skb, vid);
}
napi_gro_receive(&q_vector->napi, skb);
next_desc:
rx_desc->wb.upper.status_error = 0;
if (cleaned_count >= IGB_RX_BUFFER_WRITE) {
igb_alloc_rx_buffers_adv(rx_ring, cleaned_count);
cleaned_count = 0;
}
rx_desc = next_rxd;
buffer_info = next_buffer;
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
}
rx_ring->next_to_clean = i;
cleaned_count = igb_desc_unused(rx_ring);
if (cleaned_count)
igb_alloc_rx_buffers_adv(rx_ring, cleaned_count);
rx_ring->total_packets += total_packets;
rx_ring->total_bytes += total_bytes;
u64_stats_update_begin(&rx_ring->rx_syncp);
rx_ring->rx_stats.packets += total_packets;
rx_ring->rx_stats.bytes += total_bytes;
u64_stats_update_end(&rx_ring->rx_syncp);
return cleaned;
}
void igb_alloc_rx_buffers_adv(struct igb_ring *rx_ring, int cleaned_count)
{
struct net_device *netdev = rx_ring->netdev;
union e1000_adv_rx_desc *rx_desc;
struct igb_buffer *buffer_info;
struct sk_buff *skb;
unsigned int i;
int bufsz;
i = rx_ring->next_to_use;
buffer_info = &rx_ring->buffer_info[i];
bufsz = rx_ring->rx_buffer_len;
while (cleaned_count--) {
rx_desc = E1000_RX_DESC_ADV(*rx_ring, i);
if ((bufsz < IGB_RXBUFFER_1024) && !buffer_info->page_dma) {
if (!buffer_info->page) {
buffer_info->page = netdev_alloc_page(netdev);
if (unlikely(!buffer_info->page)) {
u64_stats_update_begin(&rx_ring->rx_syncp);
rx_ring->rx_stats.alloc_failed++;
u64_stats_update_end(&rx_ring->rx_syncp);
goto no_buffers;
}
buffer_info->page_offset = 0;
} else {
buffer_info->page_offset ^= PAGE_SIZE / 2;
}
buffer_info->page_dma =
dma_map_page(rx_ring->dev, buffer_info->page,
buffer_info->page_offset,
PAGE_SIZE / 2,
DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev,
buffer_info->page_dma)) {
buffer_info->page_dma = 0;
u64_stats_update_begin(&rx_ring->rx_syncp);
rx_ring->rx_stats.alloc_failed++;
u64_stats_update_end(&rx_ring->rx_syncp);
goto no_buffers;
}
}
skb = buffer_info->skb;
if (!skb) {
skb = netdev_alloc_skb_ip_align(netdev, bufsz);
if (unlikely(!skb)) {
u64_stats_update_begin(&rx_ring->rx_syncp);
rx_ring->rx_stats.alloc_failed++;
u64_stats_update_end(&rx_ring->rx_syncp);
goto no_buffers;
}
buffer_info->skb = skb;
}
if (!buffer_info->dma) {
buffer_info->dma = dma_map_single(rx_ring->dev,
skb->data,
bufsz,
DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev,
buffer_info->dma)) {
buffer_info->dma = 0;
u64_stats_update_begin(&rx_ring->rx_syncp);
rx_ring->rx_stats.alloc_failed++;
u64_stats_update_end(&rx_ring->rx_syncp);
goto no_buffers;
}
}
if (bufsz < IGB_RXBUFFER_1024) {
rx_desc->read.pkt_addr =
cpu_to_le64(buffer_info->page_dma);
rx_desc->read.hdr_addr = cpu_to_le64(buffer_info->dma);
} else {
rx_desc->read.pkt_addr = cpu_to_le64(buffer_info->dma);
rx_desc->read.hdr_addr = 0;
}
i++;
if (i == rx_ring->count)
i = 0;
buffer_info = &rx_ring->buffer_info[i];
}
no_buffers:
if (rx_ring->next_to_use != i) {
rx_ring->next_to_use = i;
if (i == 0)
i = (rx_ring->count - 1);
else
i--;
wmb();
writel(i, rx_ring->tail);
}
}
static int igb_mii_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct mii_ioctl_data *data = if_mii(ifr);
if (adapter->hw.phy.media_type != e1000_media_type_copper)
return -EOPNOTSUPP;
switch (cmd) {
case SIOCGMIIPHY:
data->phy_id = adapter->hw.phy.addr;
break;
case SIOCGMIIREG:
if (igb_read_phy_reg(&adapter->hw, data->reg_num & 0x1F,
&data->val_out))
return -EIO;
break;
case SIOCSMIIREG:
default:
return -EOPNOTSUPP;
}
return 0;
}
static int igb_hwtstamp_ioctl(struct net_device *netdev,
struct ifreq *ifr, int cmd)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
struct hwtstamp_config config;
u32 tsync_tx_ctl = E1000_TSYNCTXCTL_ENABLED;
u32 tsync_rx_ctl = E1000_TSYNCRXCTL_ENABLED;
u32 tsync_rx_cfg = 0;
bool is_l4 = false;
bool is_l2 = false;
u32 regval;
if (copy_from_user(&config, ifr->ifr_data, sizeof(config)))
return -EFAULT;
if (config.flags)
return -EINVAL;
switch (config.tx_type) {
case HWTSTAMP_TX_OFF:
tsync_tx_ctl = 0;
case HWTSTAMP_TX_ON:
break;
default:
return -ERANGE;
}
switch (config.rx_filter) {
case HWTSTAMP_FILTER_NONE:
tsync_rx_ctl = 0;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L4_EVENT:
case HWTSTAMP_FILTER_PTP_V2_L2_EVENT:
case HWTSTAMP_FILTER_ALL:
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_ALL;
config.rx_filter = HWTSTAMP_FILTER_ALL;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_SYNC:
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_cfg = E1000_TSYNCRXCFG_PTP_V1_SYNC_MESSAGE;
is_l4 = true;
break;
case HWTSTAMP_FILTER_PTP_V1_L4_DELAY_REQ:
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_L4_V1;
tsync_rx_cfg = E1000_TSYNCRXCFG_PTP_V1_DELAY_REQ_MESSAGE;
is_l4 = true;
break;
case HWTSTAMP_FILTER_PTP_V2_L2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_L4_SYNC:
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_L2_L4_V2;
tsync_rx_cfg = E1000_TSYNCRXCFG_PTP_V2_SYNC_MESSAGE;
is_l2 = true;
is_l4 = true;
config.rx_filter = HWTSTAMP_FILTER_SOME;
break;
case HWTSTAMP_FILTER_PTP_V2_L2_DELAY_REQ:
case HWTSTAMP_FILTER_PTP_V2_L4_DELAY_REQ:
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_L2_L4_V2;
tsync_rx_cfg = E1000_TSYNCRXCFG_PTP_V2_DELAY_REQ_MESSAGE;
is_l2 = true;
is_l4 = true;
config.rx_filter = HWTSTAMP_FILTER_SOME;
break;
case HWTSTAMP_FILTER_PTP_V2_EVENT:
case HWTSTAMP_FILTER_PTP_V2_SYNC:
case HWTSTAMP_FILTER_PTP_V2_DELAY_REQ:
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_EVENT_V2;
config.rx_filter = HWTSTAMP_FILTER_PTP_V2_EVENT;
is_l2 = true;
break;
default:
return -ERANGE;
}
if (hw->mac.type == e1000_82575) {
if (tsync_rx_ctl | tsync_tx_ctl)
return -EINVAL;
return 0;
}
if ((hw->mac.type == e1000_82580) && tsync_rx_ctl) {
tsync_rx_ctl = E1000_TSYNCRXCTL_ENABLED;
tsync_rx_ctl |= E1000_TSYNCRXCTL_TYPE_ALL;
}
regval = rd32(E1000_TSYNCTXCTL);
regval &= ~E1000_TSYNCTXCTL_ENABLED;
regval |= tsync_tx_ctl;
wr32(E1000_TSYNCTXCTL, regval);
regval = rd32(E1000_TSYNCRXCTL);
regval &= ~(E1000_TSYNCRXCTL_ENABLED | E1000_TSYNCRXCTL_TYPE_MASK);
regval |= tsync_rx_ctl;
wr32(E1000_TSYNCRXCTL, regval);
wr32(E1000_TSYNCRXCFG, tsync_rx_cfg);
if (is_l2)
wr32(E1000_ETQF(3),
(E1000_ETQF_FILTER_ENABLE |
E1000_ETQF_1588 |
ETH_P_1588));
else
wr32(E1000_ETQF(3), 0);
#define PTP_PORT 319
if (is_l4) {
u32 ftqf = (IPPROTO_UDP
| E1000_FTQF_VF_BP
| E1000_FTQF_1588_TIME_STAMP
| E1000_FTQF_MASK);
ftqf &= ~E1000_FTQF_MASK_PROTO_BP;
wr32(E1000_IMIR(3), htons(PTP_PORT));
wr32(E1000_IMIREXT(3),
(E1000_IMIREXT_SIZE_BP | E1000_IMIREXT_CTRL_BP));
if (hw->mac.type == e1000_82576) {
wr32(E1000_SPQF(3), htons(PTP_PORT));
ftqf &= ~E1000_FTQF_MASK_SOURCE_PORT_BP;
}
wr32(E1000_FTQF(3), ftqf);
} else {
wr32(E1000_FTQF(3), E1000_FTQF_MASK);
}
wrfl();
adapter->hwtstamp_config = config;
regval = rd32(E1000_TXSTMPH);
regval = rd32(E1000_RXSTMPH);
return copy_to_user(ifr->ifr_data, &config, sizeof(config)) ?
-EFAULT : 0;
}
static int igb_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
return igb_mii_ioctl(netdev, ifr, cmd);
case SIOCSHWTSTAMP:
return igb_hwtstamp_ioctl(netdev, ifr, cmd);
default:
return -EOPNOTSUPP;
}
}
s32 igb_read_pcie_cap_reg(struct e1000_hw *hw, u32 reg, u16 *value)
{
struct igb_adapter *adapter = hw->back;
u16 cap_offset;
cap_offset = adapter->pdev->pcie_cap;
if (!cap_offset)
return -E1000_ERR_CONFIG;
pci_read_config_word(adapter->pdev, cap_offset + reg, value);
return 0;
}
s32 igb_write_pcie_cap_reg(struct e1000_hw *hw, u32 reg, u16 *value)
{
struct igb_adapter *adapter = hw->back;
u16 cap_offset;
cap_offset = adapter->pdev->pcie_cap;
if (!cap_offset)
return -E1000_ERR_CONFIG;
pci_write_config_word(adapter->pdev, cap_offset + reg, *value);
return 0;
}
static void igb_vlan_mode(struct net_device *netdev, u32 features)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
u32 ctrl, rctl;
igb_irq_disable(adapter);
if (features & NETIF_F_HW_VLAN_RX) {
ctrl = rd32(E1000_CTRL);
ctrl |= E1000_CTRL_VME;
wr32(E1000_CTRL, ctrl);
rctl = rd32(E1000_RCTL);
rctl &= ~E1000_RCTL_CFIEN;
wr32(E1000_RCTL, rctl);
} else {
ctrl = rd32(E1000_CTRL);
ctrl &= ~E1000_CTRL_VME;
wr32(E1000_CTRL, ctrl);
}
igb_rlpml_set(adapter);
if (!test_bit(__IGB_DOWN, &adapter->state))
igb_irq_enable(adapter);
}
static void igb_vlan_rx_add_vid(struct net_device *netdev, u16 vid)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
int pf_id = adapter->vfs_allocated_count;
igb_vlvf_set(adapter, vid, true, pf_id);
igb_vfta_set(hw, vid, true);
set_bit(vid, adapter->active_vlans);
}
static void igb_vlan_rx_kill_vid(struct net_device *netdev, u16 vid)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
int pf_id = adapter->vfs_allocated_count;
s32 err;
igb_irq_disable(adapter);
if (!test_bit(__IGB_DOWN, &adapter->state))
igb_irq_enable(adapter);
err = igb_vlvf_set(adapter, vid, false, pf_id);
if (err)
igb_vfta_set(hw, vid, false);
clear_bit(vid, adapter->active_vlans);
}
static void igb_restore_vlan(struct igb_adapter *adapter)
{
u16 vid;
for_each_set_bit(vid, adapter->active_vlans, VLAN_N_VID)
igb_vlan_rx_add_vid(adapter->netdev, vid);
}
int igb_set_spd_dplx(struct igb_adapter *adapter, u32 spd, u8 dplx)
{
struct pci_dev *pdev = adapter->pdev;
struct e1000_mac_info *mac = &adapter->hw.mac;
mac->autoneg = 0;
if ((spd & 1) || (dplx & ~1))
goto err_inval;
if ((adapter->hw.phy.media_type == e1000_media_type_internal_serdes) &&
spd != SPEED_1000 &&
dplx != DUPLEX_FULL)
goto err_inval;
switch (spd + dplx) {
case SPEED_10 + DUPLEX_HALF:
mac->forced_speed_duplex = ADVERTISE_10_HALF;
break;
case SPEED_10 + DUPLEX_FULL:
mac->forced_speed_duplex = ADVERTISE_10_FULL;
break;
case SPEED_100 + DUPLEX_HALF:
mac->forced_speed_duplex = ADVERTISE_100_HALF;
break;
case SPEED_100 + DUPLEX_FULL:
mac->forced_speed_duplex = ADVERTISE_100_FULL;
break;
case SPEED_1000 + DUPLEX_FULL:
mac->autoneg = 1;
adapter->hw.phy.autoneg_advertised = ADVERTISE_1000_FULL;
break;
case SPEED_1000 + DUPLEX_HALF:
default:
goto err_inval;
}
return 0;
err_inval:
dev_err(&pdev->dev, "Unsupported Speed/Duplex configuration\n");
return -EINVAL;
}
static int __igb_shutdown(struct pci_dev *pdev, bool *enable_wake)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
u32 ctrl, rctl, status;
u32 wufc = adapter->wol;
#ifdef CONFIG_PM
int retval = 0;
#endif
netif_device_detach(netdev);
if (netif_running(netdev))
igb_close(netdev);
igb_clear_interrupt_scheme(adapter);
#ifdef CONFIG_PM
retval = pci_save_state(pdev);
if (retval)
return retval;
#endif
status = rd32(E1000_STATUS);
if (status & E1000_STATUS_LU)
wufc &= ~E1000_WUFC_LNKC;
if (wufc) {
igb_setup_rctl(adapter);
igb_set_rx_mode(netdev);
if (wufc & E1000_WUFC_MC) {
rctl = rd32(E1000_RCTL);
rctl |= E1000_RCTL_MPE;
wr32(E1000_RCTL, rctl);
}
ctrl = rd32(E1000_CTRL);
#define E1000_CTRL_ADVD3WUC 0x00100000
#define E1000_CTRL_EN_PHY_PWR_MGMT 0x00200000
ctrl |= E1000_CTRL_ADVD3WUC;
wr32(E1000_CTRL, ctrl);
igb_disable_pcie_master(hw);
wr32(E1000_WUC, E1000_WUC_PME_EN);
wr32(E1000_WUFC, wufc);
} else {
wr32(E1000_WUC, 0);
wr32(E1000_WUFC, 0);
}
*enable_wake = wufc || adapter->en_mng_pt;
if (!*enable_wake)
igb_power_down_link(adapter);
else
igb_power_up_link(adapter);
igb_release_hw_control(adapter);
pci_disable_device(pdev);
return 0;
}
static int igb_suspend(struct pci_dev *pdev, pm_message_t state)
{
int retval;
bool wake;
retval = __igb_shutdown(pdev, &wake);
if (retval)
return retval;
if (wake) {
pci_prepare_to_sleep(pdev);
} else {
pci_wake_from_d3(pdev, false);
pci_set_power_state(pdev, PCI_D3hot);
}
return 0;
}
static int igb_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
u32 err;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
pci_save_state(pdev);
err = pci_enable_device_mem(pdev);
if (err) {
dev_err(&pdev->dev,
"igb: Cannot enable PCI device from suspend\n");
return err;
}
pci_set_master(pdev);
pci_enable_wake(pdev, PCI_D3hot, 0);
pci_enable_wake(pdev, PCI_D3cold, 0);
if (igb_init_interrupt_scheme(adapter)) {
dev_err(&pdev->dev, "Unable to allocate memory for queues\n");
return -ENOMEM;
}
igb_reset(adapter);
igb_get_hw_control(adapter);
wr32(E1000_WUS, ~0);
if (netif_running(netdev)) {
err = igb_open(netdev);
if (err)
return err;
}
netif_device_attach(netdev);
return 0;
}
static void igb_shutdown(struct pci_dev *pdev)
{
bool wake;
__igb_shutdown(pdev, &wake);
if (system_state == SYSTEM_POWER_OFF) {
pci_wake_from_d3(pdev, wake);
pci_set_power_state(pdev, PCI_D3hot);
}
}
static void igb_netpoll(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
int i;
if (!adapter->msix_entries) {
struct igb_q_vector *q_vector = adapter->q_vector[0];
igb_irq_disable(adapter);
napi_schedule(&q_vector->napi);
return;
}
for (i = 0; i < adapter->num_q_vectors; i++) {
struct igb_q_vector *q_vector = adapter->q_vector[i];
wr32(E1000_EIMC, q_vector->eims_value);
napi_schedule(&q_vector->napi);
}
}
static pci_ers_result_t igb_io_error_detected(struct pci_dev *pdev,
pci_channel_state_t state)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
netif_device_detach(netdev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
if (netif_running(netdev))
igb_down(adapter);
pci_disable_device(pdev);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t igb_io_slot_reset(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
pci_ers_result_t result;
int err;
if (pci_enable_device_mem(pdev)) {
dev_err(&pdev->dev,
"Cannot re-enable PCI device after reset.\n");
result = PCI_ERS_RESULT_DISCONNECT;
} else {
pci_set_master(pdev);
pci_restore_state(pdev);
pci_save_state(pdev);
pci_enable_wake(pdev, PCI_D3hot, 0);
pci_enable_wake(pdev, PCI_D3cold, 0);
igb_reset(adapter);
wr32(E1000_WUS, ~0);
result = PCI_ERS_RESULT_RECOVERED;
}
err = pci_cleanup_aer_uncorrect_error_status(pdev);
if (err) {
dev_err(&pdev->dev, "pci_cleanup_aer_uncorrect_error_status "
"failed 0x%0x\n", err);
}
return result;
}
static void igb_io_resume(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
if (netif_running(netdev)) {
if (igb_up(adapter)) {
dev_err(&pdev->dev, "igb_up failed after reset\n");
return;
}
}
netif_device_attach(netdev);
igb_get_hw_control(adapter);
}
static void igb_rar_set_qsel(struct igb_adapter *adapter, u8 *addr, u32 index,
u8 qsel)
{
u32 rar_low, rar_high;
struct e1000_hw *hw = &adapter->hw;
rar_low = ((u32) addr[0] | ((u32) addr[1] << 8) |
((u32) addr[2] << 16) | ((u32) addr[3] << 24));
rar_high = ((u32) addr[4] | ((u32) addr[5] << 8));
rar_high |= E1000_RAH_AV;
if (hw->mac.type == e1000_82575)
rar_high |= E1000_RAH_POOL_1 * qsel;
else
rar_high |= E1000_RAH_POOL_1 << qsel;
wr32(E1000_RAL(index), rar_low);
wrfl();
wr32(E1000_RAH(index), rar_high);
wrfl();
}
static int igb_set_vf_mac(struct igb_adapter *adapter,
int vf, unsigned char *mac_addr)
{
struct e1000_hw *hw = &adapter->hw;
int rar_entry = hw->mac.rar_entry_count - (vf + 1);
memcpy(adapter->vf_data[vf].vf_mac_addresses, mac_addr, ETH_ALEN);
igb_rar_set_qsel(adapter, mac_addr, rar_entry, vf);
return 0;
}
static int igb_ndo_set_vf_mac(struct net_device *netdev, int vf, u8 *mac)
{
struct igb_adapter *adapter = netdev_priv(netdev);
if (!is_valid_ether_addr(mac) || (vf >= adapter->vfs_allocated_count))
return -EINVAL;
adapter->vf_data[vf].flags |= IGB_VF_FLAG_PF_SET_MAC;
dev_info(&adapter->pdev->dev, "setting MAC %pM on VF %d\n", mac, vf);
dev_info(&adapter->pdev->dev, "Reload the VF driver to make this"
" change effective.");
if (test_bit(__IGB_DOWN, &adapter->state)) {
dev_warn(&adapter->pdev->dev, "The VF MAC address has been set,"
" but the PF device is not up.\n");
dev_warn(&adapter->pdev->dev, "Bring the PF device up before"
" attempting to use the VF device.\n");
}
return igb_set_vf_mac(adapter, vf, mac);
}
static int igb_link_mbps(int internal_link_speed)
{
switch (internal_link_speed) {
case SPEED_100:
return 100;
case SPEED_1000:
return 1000;
default:
return 0;
}
}
static void igb_set_vf_rate_limit(struct e1000_hw *hw, int vf, int tx_rate,
int link_speed)
{
int rf_dec, rf_int;
u32 bcnrc_val;
if (tx_rate != 0) {
rf_int = link_speed / tx_rate;
rf_dec = (link_speed - (rf_int * tx_rate));
rf_dec = (rf_dec * (1<<E1000_RTTBCNRC_RF_INT_SHIFT)) / tx_rate;
bcnrc_val = E1000_RTTBCNRC_RS_ENA;
bcnrc_val |= ((rf_int<<E1000_RTTBCNRC_RF_INT_SHIFT) &
E1000_RTTBCNRC_RF_INT_MASK);
bcnrc_val |= (rf_dec & E1000_RTTBCNRC_RF_DEC_MASK);
} else {
bcnrc_val = 0;
}
wr32(E1000_RTTDQSEL, vf);
wr32(E1000_RTTBCNRC, bcnrc_val);
}
static void igb_check_vf_rate_limit(struct igb_adapter *adapter)
{
int actual_link_speed, i;
bool reset_rate = false;
if ((adapter->vf_rate_link_speed == 0) ||
(adapter->hw.mac.type != e1000_82576))
return;
actual_link_speed = igb_link_mbps(adapter->link_speed);
if (actual_link_speed != adapter->vf_rate_link_speed) {
reset_rate = true;
adapter->vf_rate_link_speed = 0;
dev_info(&adapter->pdev->dev,
"Link speed has been changed. VF Transmit "
"rate is disabled\n");
}
for (i = 0; i < adapter->vfs_allocated_count; i++) {
if (reset_rate)
adapter->vf_data[i].tx_rate = 0;
igb_set_vf_rate_limit(&adapter->hw, i,
adapter->vf_data[i].tx_rate,
actual_link_speed);
}
}
static int igb_ndo_set_vf_bw(struct net_device *netdev, int vf, int tx_rate)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
int actual_link_speed;
if (hw->mac.type != e1000_82576)
return -EOPNOTSUPP;
actual_link_speed = igb_link_mbps(adapter->link_speed);
if ((vf >= adapter->vfs_allocated_count) ||
(!(rd32(E1000_STATUS) & E1000_STATUS_LU)) ||
(tx_rate < 0) || (tx_rate > actual_link_speed))
return -EINVAL;
adapter->vf_rate_link_speed = actual_link_speed;
adapter->vf_data[vf].tx_rate = (u16)tx_rate;
igb_set_vf_rate_limit(hw, vf, tx_rate, actual_link_speed);
return 0;
}
static int igb_ndo_get_vf_config(struct net_device *netdev,
int vf, struct ifla_vf_info *ivi)
{
struct igb_adapter *adapter = netdev_priv(netdev);
if (vf >= adapter->vfs_allocated_count)
return -EINVAL;
ivi->vf = vf;
memcpy(&ivi->mac, adapter->vf_data[vf].vf_mac_addresses, ETH_ALEN);
ivi->tx_rate = adapter->vf_data[vf].tx_rate;
ivi->vlan = adapter->vf_data[vf].pf_vlan;
ivi->qos = adapter->vf_data[vf].pf_qos;
return 0;
}
static void igb_vmm_control(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 reg;
switch (hw->mac.type) {
case e1000_82575:
default:
return;
case e1000_82576:
reg = rd32(E1000_DTXCTL);
reg |= E1000_DTXCTL_VLAN_ADDED;
wr32(E1000_DTXCTL, reg);
case e1000_82580:
reg = rd32(E1000_RPLOLR);
reg |= E1000_RPLOLR_STRVLAN;
wr32(E1000_RPLOLR, reg);
case e1000_i350:
break;
}
if (adapter->vfs_allocated_count) {
igb_vmdq_set_loopback_pf(hw, true);
igb_vmdq_set_replication_pf(hw, true);
igb_vmdq_set_anti_spoofing_pf(hw, true,
adapter->vfs_allocated_count);
} else {
igb_vmdq_set_loopback_pf(hw, false);
igb_vmdq_set_replication_pf(hw, false);
}
}
