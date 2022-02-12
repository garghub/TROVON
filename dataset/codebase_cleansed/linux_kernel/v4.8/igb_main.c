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
pr_info("%-15s %08x\n", reginfo->name, rd32(reginfo->ofs));
return;
}
snprintf(rname, 16, "%s%s", reginfo->name, "[0-3]");
pr_info("%-15s %08x %08x %08x %08x\n", rname, regs[0], regs[1],
regs[2], regs[3]);
}
static void igb_dump(struct igb_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct e1000_hw *hw = &adapter->hw;
struct igb_reg_info *reginfo;
struct igb_ring *tx_ring;
union e1000_adv_tx_desc *tx_desc;
struct my_u0 { u64 a; u64 b; } *u0;
struct igb_ring *rx_ring;
union e1000_adv_rx_desc *rx_desc;
u32 staterr;
u16 i, n;
if (!netif_msg_hw(adapter))
return;
if (netdev) {
dev_info(&adapter->pdev->dev, "Net device Info\n");
pr_info("Device Name state trans_start last_rx\n");
pr_info("%-15s %016lX %016lX %016lX\n", netdev->name,
netdev->state, dev_trans_start(netdev), netdev->last_rx);
}
dev_info(&adapter->pdev->dev, "Register Dump\n");
pr_info(" Register Name Value\n");
for (reginfo = (struct igb_reg_info *)igb_reg_info_tbl;
reginfo->name; reginfo++) {
igb_regdump(hw, reginfo);
}
if (!netdev || !netif_running(netdev))
goto exit;
dev_info(&adapter->pdev->dev, "TX Rings Summary\n");
pr_info("Queue [NTU] [NTC] [bi(ntc)->dma ] leng ntw timestamp\n");
for (n = 0; n < adapter->num_tx_queues; n++) {
struct igb_tx_buffer *buffer_info;
tx_ring = adapter->tx_ring[n];
buffer_info = &tx_ring->tx_buffer_info[tx_ring->next_to_clean];
pr_info(" %5d %5X %5X %016llX %04X %p %016llX\n",
n, tx_ring->next_to_use, tx_ring->next_to_clean,
(u64)dma_unmap_addr(buffer_info, dma),
dma_unmap_len(buffer_info, len),
buffer_info->next_to_watch,
(u64)buffer_info->time_stamp);
}
if (!netif_msg_tx_done(adapter))
goto rx_ring_summary;
dev_info(&adapter->pdev->dev, "TX Rings Dump\n");
for (n = 0; n < adapter->num_tx_queues; n++) {
tx_ring = adapter->tx_ring[n];
pr_info("------------------------------------\n");
pr_info("TX QUEUE INDEX = %d\n", tx_ring->queue_index);
pr_info("------------------------------------\n");
pr_info("T [desc] [address 63:0 ] [PlPOCIStDDM Ln] [bi->dma ] leng ntw timestamp bi->skb\n");
for (i = 0; tx_ring->desc && (i < tx_ring->count); i++) {
const char *next_desc;
struct igb_tx_buffer *buffer_info;
tx_desc = IGB_TX_DESC(tx_ring, i);
buffer_info = &tx_ring->tx_buffer_info[i];
u0 = (struct my_u0 *)tx_desc;
if (i == tx_ring->next_to_use &&
i == tx_ring->next_to_clean)
next_desc = " NTC/U";
else if (i == tx_ring->next_to_use)
next_desc = " NTU";
else if (i == tx_ring->next_to_clean)
next_desc = " NTC";
else
next_desc = "";
pr_info("T [0x%03X] %016llX %016llX %016llX %04X %p %016llX %p%s\n",
i, le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
(u64)dma_unmap_addr(buffer_info, dma),
dma_unmap_len(buffer_info, len),
buffer_info->next_to_watch,
(u64)buffer_info->time_stamp,
buffer_info->skb, next_desc);
if (netif_msg_pktdata(adapter) && buffer_info->skb)
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS,
16, 1, buffer_info->skb->data,
dma_unmap_len(buffer_info, len),
true);
}
}
rx_ring_summary:
dev_info(&adapter->pdev->dev, "RX Rings Summary\n");
pr_info("Queue [NTU] [NTC]\n");
for (n = 0; n < adapter->num_rx_queues; n++) {
rx_ring = adapter->rx_ring[n];
pr_info(" %5d %5X %5X\n",
n, rx_ring->next_to_use, rx_ring->next_to_clean);
}
if (!netif_msg_rx_status(adapter))
goto exit;
dev_info(&adapter->pdev->dev, "RX Rings Dump\n");
for (n = 0; n < adapter->num_rx_queues; n++) {
rx_ring = adapter->rx_ring[n];
pr_info("------------------------------------\n");
pr_info("RX QUEUE INDEX = %d\n", rx_ring->queue_index);
pr_info("------------------------------------\n");
pr_info("R [desc] [ PktBuf A0] [ HeadBuf DD] [bi->dma ] [bi->skb] <-- Adv Rx Read format\n");
pr_info("RWB[desc] [PcsmIpSHl PtRs] [vl er S cks ln] ---------------- [bi->skb] <-- Adv Rx Write-Back format\n");
for (i = 0; i < rx_ring->count; i++) {
const char *next_desc;
struct igb_rx_buffer *buffer_info;
buffer_info = &rx_ring->rx_buffer_info[i];
rx_desc = IGB_RX_DESC(rx_ring, i);
u0 = (struct my_u0 *)rx_desc;
staterr = le32_to_cpu(rx_desc->wb.upper.status_error);
if (i == rx_ring->next_to_use)
next_desc = " NTU";
else if (i == rx_ring->next_to_clean)
next_desc = " NTC";
else
next_desc = "";
if (staterr & E1000_RXD_STAT_DD) {
pr_info("%s[0x%03X] %016llX %016llX ---------------- %s\n",
"RWB", i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
next_desc);
} else {
pr_info("%s[0x%03X] %016llX %016llX %016llX %s\n",
"R ", i,
le64_to_cpu(u0->a),
le64_to_cpu(u0->b),
(u64)buffer_info->dma,
next_desc);
if (netif_msg_pktdata(adapter) &&
buffer_info->dma && buffer_info->page) {
print_hex_dump(KERN_INFO, "",
DUMP_PREFIX_ADDRESS,
16, 1,
page_address(buffer_info->page) +
buffer_info->page_offset,
IGB_RX_BUFSZ, true);
}
}
}
}
exit:
return;
}
static int igb_get_i2c_data(void *data)
{
struct igb_adapter *adapter = (struct igb_adapter *)data;
struct e1000_hw *hw = &adapter->hw;
s32 i2cctl = rd32(E1000_I2CPARAMS);
return !!(i2cctl & E1000_I2C_DATA_IN);
}
static void igb_set_i2c_data(void *data, int state)
{
struct igb_adapter *adapter = (struct igb_adapter *)data;
struct e1000_hw *hw = &adapter->hw;
s32 i2cctl = rd32(E1000_I2CPARAMS);
if (state)
i2cctl |= E1000_I2C_DATA_OUT;
else
i2cctl &= ~E1000_I2C_DATA_OUT;
i2cctl &= ~E1000_I2C_DATA_OE_N;
i2cctl |= E1000_I2C_CLK_OE_N;
wr32(E1000_I2CPARAMS, i2cctl);
wrfl();
}
static void igb_set_i2c_clk(void *data, int state)
{
struct igb_adapter *adapter = (struct igb_adapter *)data;
struct e1000_hw *hw = &adapter->hw;
s32 i2cctl = rd32(E1000_I2CPARAMS);
if (state) {
i2cctl |= E1000_I2C_CLK_OUT;
i2cctl &= ~E1000_I2C_CLK_OE_N;
} else {
i2cctl &= ~E1000_I2C_CLK_OUT;
i2cctl &= ~E1000_I2C_CLK_OE_N;
}
wr32(E1000_I2CPARAMS, i2cctl);
wrfl();
}
static int igb_get_i2c_clk(void *data)
{
struct igb_adapter *adapter = (struct igb_adapter *)data;
struct e1000_hw *hw = &adapter->hw;
s32 i2cctl = rd32(E1000_I2CPARAMS);
return !!(i2cctl & E1000_I2C_CLK_IN);
}
struct net_device *igb_get_hw_dev(struct e1000_hw *hw)
{
struct igb_adapter *adapter = hw->back;
return adapter->netdev;
}
static int __init igb_init_module(void)
{
int ret;
pr_info("%s - version %s\n",
igb_driver_string, igb_driver_version);
pr_info("%s\n", igb_copyright);
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
case e1000_i354:
case e1000_i210:
case e1000_i211:
default:
for (; i < adapter->num_rx_queues; i++)
adapter->rx_ring[i]->reg_idx = rbase_offset + i;
for (; j < adapter->num_tx_queues; j++)
adapter->tx_ring[j]->reg_idx = rbase_offset + j;
break;
}
}
u32 igb_rd32(struct e1000_hw *hw, u32 reg)
{
struct igb_adapter *igb = container_of(hw, struct igb_adapter, hw);
u8 __iomem *hw_addr = ACCESS_ONCE(hw->hw_addr);
u32 value = 0;
if (E1000_REMOVED(hw_addr))
return ~value;
value = readl(&hw_addr[reg]);
if (!(~value) && (!reg || !(~readl(hw_addr)))) {
struct net_device *netdev = igb->netdev;
hw->hw_addr = NULL;
netif_device_detach(netdev);
netdev_err(netdev, "PCIe link lost, device now detached\n");
}
return value;
}
static void igb_write_ivar(struct e1000_hw *hw, int msix_vector,
int index, int offset)
{
u32 ivar = array_rd32(E1000_IVAR0, index);
ivar &= ~((u32)0xFF << offset);
ivar |= (msix_vector | E1000_IVAR_VALID) << offset;
array_wr32(E1000_IVAR0, index, ivar);
}
static void igb_assign_vector(struct igb_q_vector *q_vector, int msix_vector)
{
struct igb_adapter *adapter = q_vector->adapter;
struct e1000_hw *hw = &adapter->hw;
int rx_queue = IGB_N0_QUEUE;
int tx_queue = IGB_N0_QUEUE;
u32 msixbm = 0;
if (q_vector->rx.ring)
rx_queue = q_vector->rx.ring->reg_idx;
if (q_vector->tx.ring)
tx_queue = q_vector->tx.ring->reg_idx;
switch (hw->mac.type) {
case e1000_82575:
if (rx_queue > IGB_N0_QUEUE)
msixbm = E1000_EICR_RX_QUEUE0 << rx_queue;
if (tx_queue > IGB_N0_QUEUE)
msixbm |= E1000_EICR_TX_QUEUE0 << tx_queue;
if (!(adapter->flags & IGB_FLAG_HAS_MSIX) && msix_vector == 0)
msixbm |= E1000_EIMS_OTHER;
array_wr32(E1000_MSIXBM(0), msix_vector, msixbm);
q_vector->eims_value = msixbm;
break;
case e1000_82576:
if (rx_queue > IGB_N0_QUEUE)
igb_write_ivar(hw, msix_vector,
rx_queue & 0x7,
(rx_queue & 0x8) << 1);
if (tx_queue > IGB_N0_QUEUE)
igb_write_ivar(hw, msix_vector,
tx_queue & 0x7,
((tx_queue & 0x8) << 1) + 8);
q_vector->eims_value = BIT(msix_vector);
break;
case e1000_82580:
case e1000_i350:
case e1000_i354:
case e1000_i210:
case e1000_i211:
if (rx_queue > IGB_N0_QUEUE)
igb_write_ivar(hw, msix_vector,
rx_queue >> 1,
(rx_queue & 0x1) << 4);
if (tx_queue > IGB_N0_QUEUE)
igb_write_ivar(hw, msix_vector,
tx_queue >> 1,
((tx_queue & 0x1) << 4) + 8);
q_vector->eims_value = BIT(msix_vector);
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
array_wr32(E1000_MSIXBM(0), vector++, E1000_EIMS_OTHER);
adapter->eims_other = E1000_EIMS_OTHER;
break;
case e1000_82576:
case e1000_82580:
case e1000_i350:
case e1000_i354:
case e1000_i210:
case e1000_i211:
wr32(E1000_GPIE, E1000_GPIE_MSIX_MODE |
E1000_GPIE_PBA | E1000_GPIE_EIAME |
E1000_GPIE_NSICR);
adapter->eims_other = BIT(vector);
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
int i, err = 0, vector = 0, free_vector = 0;
err = request_irq(adapter->msix_entries[vector].vector,
igb_msix_other, 0, netdev->name, adapter);
if (err)
goto err_out;
for (i = 0; i < adapter->num_q_vectors; i++) {
struct igb_q_vector *q_vector = adapter->q_vector[i];
vector++;
q_vector->itr_register = adapter->io_addr + E1000_EITR(vector);
if (q_vector->rx.ring && q_vector->tx.ring)
sprintf(q_vector->name, "%s-TxRx-%u", netdev->name,
q_vector->rx.ring->queue_index);
else if (q_vector->tx.ring)
sprintf(q_vector->name, "%s-tx-%u", netdev->name,
q_vector->tx.ring->queue_index);
else if (q_vector->rx.ring)
sprintf(q_vector->name, "%s-rx-%u", netdev->name,
q_vector->rx.ring->queue_index);
else
sprintf(q_vector->name, "%s-unused", netdev->name);
err = request_irq(adapter->msix_entries[vector].vector,
igb_msix_ring, 0, q_vector->name,
q_vector);
if (err)
goto err_free;
}
igb_configure_msix(adapter);
return 0;
err_free:
free_irq(adapter->msix_entries[free_vector++].vector, adapter);
vector--;
for (i = 0; i < vector; i++) {
free_irq(adapter->msix_entries[free_vector++].vector,
adapter->q_vector[i]);
}
err_out:
return err;
}
static void igb_free_q_vector(struct igb_adapter *adapter, int v_idx)
{
struct igb_q_vector *q_vector = adapter->q_vector[v_idx];
adapter->q_vector[v_idx] = NULL;
if (q_vector)
kfree_rcu(q_vector, rcu);
}
static void igb_reset_q_vector(struct igb_adapter *adapter, int v_idx)
{
struct igb_q_vector *q_vector = adapter->q_vector[v_idx];
if (!q_vector)
return;
if (q_vector->tx.ring)
adapter->tx_ring[q_vector->tx.ring->queue_index] = NULL;
if (q_vector->rx.ring)
adapter->rx_ring[q_vector->rx.ring->queue_index] = NULL;
netif_napi_del(&q_vector->napi);
}
static void igb_reset_interrupt_capability(struct igb_adapter *adapter)
{
int v_idx = adapter->num_q_vectors;
if (adapter->flags & IGB_FLAG_HAS_MSIX)
pci_disable_msix(adapter->pdev);
else if (adapter->flags & IGB_FLAG_HAS_MSI)
pci_disable_msi(adapter->pdev);
while (v_idx--)
igb_reset_q_vector(adapter, v_idx);
}
static void igb_free_q_vectors(struct igb_adapter *adapter)
{
int v_idx = adapter->num_q_vectors;
adapter->num_tx_queues = 0;
adapter->num_rx_queues = 0;
adapter->num_q_vectors = 0;
while (v_idx--) {
igb_reset_q_vector(adapter, v_idx);
igb_free_q_vector(adapter, v_idx);
}
}
static void igb_clear_interrupt_scheme(struct igb_adapter *adapter)
{
igb_free_q_vectors(adapter);
igb_reset_interrupt_capability(adapter);
}
static void igb_set_interrupt_capability(struct igb_adapter *adapter, bool msix)
{
int err;
int numvecs, i;
if (!msix)
goto msi_only;
adapter->flags |= IGB_FLAG_HAS_MSIX;
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
for (i = 0; i < numvecs; i++)
adapter->msix_entries[i].entry = i;
err = pci_enable_msix_range(adapter->pdev,
adapter->msix_entries,
numvecs,
numvecs);
if (err > 0)
return;
igb_reset_interrupt_capability(adapter);
msi_only:
adapter->flags &= ~IGB_FLAG_HAS_MSIX;
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
}
static void igb_add_ring(struct igb_ring *ring,
struct igb_ring_container *head)
{
head->ring = ring;
head->count++;
}
static int igb_alloc_q_vector(struct igb_adapter *adapter,
int v_count, int v_idx,
int txr_count, int txr_idx,
int rxr_count, int rxr_idx)
{
struct igb_q_vector *q_vector;
struct igb_ring *ring;
int ring_count, size;
if (txr_count > 1 || rxr_count > 1)
return -ENOMEM;
ring_count = txr_count + rxr_count;
size = sizeof(struct igb_q_vector) +
(sizeof(struct igb_ring) * ring_count);
q_vector = adapter->q_vector[v_idx];
if (!q_vector) {
q_vector = kzalloc(size, GFP_KERNEL);
} else if (size > ksize(q_vector)) {
kfree_rcu(q_vector, rcu);
q_vector = kzalloc(size, GFP_KERNEL);
} else {
memset(q_vector, 0, size);
}
if (!q_vector)
return -ENOMEM;
netif_napi_add(adapter->netdev, &q_vector->napi,
igb_poll, 64);
adapter->q_vector[v_idx] = q_vector;
q_vector->adapter = adapter;
q_vector->tx.work_limit = adapter->tx_work_limit;
q_vector->itr_register = adapter->io_addr + E1000_EITR(0);
q_vector->itr_val = IGB_START_ITR;
ring = q_vector->ring;
if (rxr_count) {
if (!adapter->rx_itr_setting || adapter->rx_itr_setting > 3)
q_vector->itr_val = adapter->rx_itr_setting;
} else {
if (!adapter->tx_itr_setting || adapter->tx_itr_setting > 3)
q_vector->itr_val = adapter->tx_itr_setting;
}
if (txr_count) {
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
ring->q_vector = q_vector;
igb_add_ring(ring, &q_vector->tx);
if (adapter->hw.mac.type == e1000_82575)
set_bit(IGB_RING_FLAG_TX_CTX_IDX, &ring->flags);
ring->count = adapter->tx_ring_count;
ring->queue_index = txr_idx;
u64_stats_init(&ring->tx_syncp);
u64_stats_init(&ring->tx_syncp2);
adapter->tx_ring[txr_idx] = ring;
ring++;
}
if (rxr_count) {
ring->dev = &adapter->pdev->dev;
ring->netdev = adapter->netdev;
ring->q_vector = q_vector;
igb_add_ring(ring, &q_vector->rx);
if (adapter->hw.mac.type >= e1000_82576)
set_bit(IGB_RING_FLAG_RX_SCTP_CSUM, &ring->flags);
if (adapter->hw.mac.type >= e1000_i350)
set_bit(IGB_RING_FLAG_RX_LB_VLAN_BSWAP, &ring->flags);
ring->count = adapter->rx_ring_count;
ring->queue_index = rxr_idx;
u64_stats_init(&ring->rx_syncp);
adapter->rx_ring[rxr_idx] = ring;
}
return 0;
}
static int igb_alloc_q_vectors(struct igb_adapter *adapter)
{
int q_vectors = adapter->num_q_vectors;
int rxr_remaining = adapter->num_rx_queues;
int txr_remaining = adapter->num_tx_queues;
int rxr_idx = 0, txr_idx = 0, v_idx = 0;
int err;
if (q_vectors >= (rxr_remaining + txr_remaining)) {
for (; rxr_remaining; v_idx++) {
err = igb_alloc_q_vector(adapter, q_vectors, v_idx,
0, 0, 1, rxr_idx);
if (err)
goto err_out;
rxr_remaining--;
rxr_idx++;
}
}
for (; v_idx < q_vectors; v_idx++) {
int rqpv = DIV_ROUND_UP(rxr_remaining, q_vectors - v_idx);
int tqpv = DIV_ROUND_UP(txr_remaining, q_vectors - v_idx);
err = igb_alloc_q_vector(adapter, q_vectors, v_idx,
tqpv, txr_idx, rqpv, rxr_idx);
if (err)
goto err_out;
rxr_remaining -= rqpv;
txr_remaining -= tqpv;
rxr_idx++;
txr_idx++;
}
return 0;
err_out:
adapter->num_tx_queues = 0;
adapter->num_rx_queues = 0;
adapter->num_q_vectors = 0;
while (v_idx--)
igb_free_q_vector(adapter, v_idx);
return -ENOMEM;
}
static int igb_init_interrupt_scheme(struct igb_adapter *adapter, bool msix)
{
struct pci_dev *pdev = adapter->pdev;
int err;
igb_set_interrupt_capability(adapter, msix);
err = igb_alloc_q_vectors(adapter);
if (err) {
dev_err(&pdev->dev, "Unable to allocate memory for vectors\n");
goto err_alloc_q_vectors;
}
igb_cache_ring_register(adapter);
return 0;
err_alloc_q_vectors:
igb_reset_interrupt_capability(adapter);
return err;
}
static int igb_request_irq(struct igb_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct pci_dev *pdev = adapter->pdev;
int err = 0;
if (adapter->flags & IGB_FLAG_HAS_MSIX) {
err = igb_request_msix(adapter);
if (!err)
goto request_done;
igb_free_all_tx_resources(adapter);
igb_free_all_rx_resources(adapter);
igb_clear_interrupt_scheme(adapter);
err = igb_init_interrupt_scheme(adapter, false);
if (err)
goto request_done;
igb_setup_all_tx_resources(adapter);
igb_setup_all_rx_resources(adapter);
igb_configure(adapter);
}
igb_assign_vector(adapter->q_vector[0], 0);
if (adapter->flags & IGB_FLAG_HAS_MSI) {
err = request_irq(pdev->irq, igb_intr_msi, 0,
netdev->name, adapter);
if (!err)
goto request_done;
igb_reset_interrupt_capability(adapter);
adapter->flags &= ~IGB_FLAG_HAS_MSI;
}
err = request_irq(pdev->irq, igb_intr, IRQF_SHARED,
netdev->name, adapter);
if (err)
dev_err(&pdev->dev, "Error %d getting interrupt\n",
err);
request_done:
return err;
}
static void igb_free_irq(struct igb_adapter *adapter)
{
if (adapter->flags & IGB_FLAG_HAS_MSIX) {
int vector = 0, i;
free_irq(adapter->msix_entries[vector++].vector, adapter);
for (i = 0; i < adapter->num_q_vectors; i++)
free_irq(adapter->msix_entries[vector++].vector,
adapter->q_vector[i]);
} else {
free_irq(adapter->pdev->irq, adapter);
}
}
static void igb_irq_disable(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
if (adapter->flags & IGB_FLAG_HAS_MSIX) {
u32 regval = rd32(E1000_EIAM);
wr32(E1000_EIAM, regval & ~adapter->eims_enable_mask);
wr32(E1000_EIMC, adapter->eims_enable_mask);
regval = rd32(E1000_EIAC);
wr32(E1000_EIAC, regval & ~adapter->eims_enable_mask);
}
wr32(E1000_IAM, 0);
wr32(E1000_IMC, ~0);
wrfl();
if (adapter->flags & IGB_FLAG_HAS_MSIX) {
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
if (adapter->flags & IGB_FLAG_HAS_MSIX) {
u32 ims = E1000_IMS_LSC | E1000_IMS_DOUTSYNC | E1000_IMS_DRSTA;
u32 regval = rd32(E1000_EIAC);
wr32(E1000_EIAC, regval | adapter->eims_enable_mask);
regval = rd32(E1000_EIAM);
wr32(E1000_EIAM, regval | adapter->eims_enable_mask);
wr32(E1000_EIMS, adapter->eims_enable_mask);
if (adapter->vfs_allocated_count) {
wr32(E1000_MBVFIMR, 0xFF);
ims |= E1000_IMS_VMMB;
}
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
u16 pf_id = adapter->vfs_allocated_count;
u16 vid = adapter->hw.mng_cookie.vlan_id;
u16 old_vid = adapter->mng_vlan_id;
if (hw->mng_cookie.status & E1000_MNG_DHCP_COOKIE_STATUS_VLAN) {
igb_vfta_set(hw, vid, pf_id, true, true);
adapter->mng_vlan_id = vid;
} else {
adapter->mng_vlan_id = IGB_MNG_VLAN_NONE;
}
if ((old_vid != (u16)IGB_MNG_VLAN_NONE) &&
(vid != old_vid) &&
!test_bit(old_vid, adapter->active_vlans)) {
igb_vfta_set(hw, vid, pf_id, false, true);
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
igb_alloc_rx_buffers(ring, igb_desc_unused(ring));
}
}
void igb_power_up_link(struct igb_adapter *adapter)
{
igb_reset_phy(&adapter->hw);
if (adapter->hw.phy.media_type == e1000_media_type_copper)
igb_power_up_phy_copper(&adapter->hw);
else
igb_power_up_serdes_link_82575(&adapter->hw);
igb_setup_link(&adapter->hw);
}
static void igb_power_down_link(struct igb_adapter *adapter)
{
if (adapter->hw.phy.media_type == e1000_media_type_copper)
igb_power_down_phy_copper_82575(&adapter->hw);
else
igb_shutdown_serdes_link_82575(&adapter->hw);
}
static void igb_check_swap_media(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 ctrl_ext, connsw;
bool swap_now = false;
ctrl_ext = rd32(E1000_CTRL_EXT);
connsw = rd32(E1000_CONNSW);
if ((hw->phy.media_type == e1000_media_type_copper) &&
(!(connsw & E1000_CONNSW_AUTOSENSE_EN))) {
swap_now = true;
} else if (!(connsw & E1000_CONNSW_SERDESD)) {
if (adapter->copper_tries < 4) {
adapter->copper_tries++;
connsw |= E1000_CONNSW_AUTOSENSE_CONF;
wr32(E1000_CONNSW, connsw);
return;
} else {
adapter->copper_tries = 0;
if ((connsw & E1000_CONNSW_PHYSD) &&
(!(connsw & E1000_CONNSW_PHY_PDN))) {
swap_now = true;
connsw &= ~E1000_CONNSW_AUTOSENSE_CONF;
wr32(E1000_CONNSW, connsw);
}
}
}
if (!swap_now)
return;
switch (hw->phy.media_type) {
case e1000_media_type_copper:
netdev_info(adapter->netdev,
"MAS: changing media to fiber/serdes\n");
ctrl_ext |=
E1000_CTRL_EXT_LINK_MODE_PCIE_SERDES;
adapter->flags |= IGB_FLAG_MEDIA_RESET;
adapter->copper_tries = 0;
break;
case e1000_media_type_internal_serdes:
case e1000_media_type_fiber:
netdev_info(adapter->netdev,
"MAS: changing media to copper\n");
ctrl_ext &=
~E1000_CTRL_EXT_LINK_MODE_PCIE_SERDES;
adapter->flags |= IGB_FLAG_MEDIA_RESET;
break;
default:
netdev_err(adapter->netdev,
"AMS: Invalid media type found, returning\n");
break;
}
wr32(E1000_CTRL_EXT, ctrl_ext);
}
int igb_up(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
int i;
igb_configure(adapter);
clear_bit(__IGB_DOWN, &adapter->state);
for (i = 0; i < adapter->num_q_vectors; i++)
napi_enable(&(adapter->q_vector[i]->napi));
if (adapter->flags & IGB_FLAG_HAS_MSIX)
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
if ((adapter->flags & IGB_FLAG_EEE) &&
(!hw->dev_spec._82575.eee_disable))
adapter->eee_advert = MDIO_EEE_100TX | MDIO_EEE_1000T;
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
netif_carrier_off(netdev);
netif_tx_stop_all_queues(netdev);
tctl = rd32(E1000_TCTL);
tctl &= ~E1000_TCTL_EN;
wr32(E1000_TCTL, tctl);
wrfl();
usleep_range(10000, 11000);
igb_irq_disable(adapter);
adapter->flags &= ~IGB_FLAG_NEED_LINK_UPDATE;
for (i = 0; i < adapter->num_q_vectors; i++) {
if (adapter->q_vector[i]) {
napi_synchronize(&adapter->q_vector[i]->napi);
napi_disable(&adapter->q_vector[i]->napi);
}
}
del_timer_sync(&adapter->watchdog_timer);
del_timer_sync(&adapter->phy_info_timer);
spin_lock(&adapter->stats64_lock);
igb_update_stats(adapter, &adapter->stats64);
spin_unlock(&adapter->stats64_lock);
adapter->link_speed = 0;
adapter->link_duplex = 0;
if (!pci_channel_offline(adapter->pdev))
igb_reset(adapter);
adapter->flags &= ~IGB_FLAG_VLAN_PROMISC;
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
usleep_range(1000, 2000);
igb_down(adapter);
igb_up(adapter);
clear_bit(__IGB_RESETTING, &adapter->state);
}
static void igb_enable_mas(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 connsw = rd32(E1000_CONNSW);
if ((hw->phy.media_type == e1000_media_type_copper) &&
(!(connsw & E1000_CONNSW_SERDESD))) {
connsw |= E1000_CONNSW_ENRGSRC;
connsw |= E1000_CONNSW_AUTOSENSE_EN;
wr32(E1000_CONNSW, connsw);
wrfl();
}
}
void igb_reset(struct igb_adapter *adapter)
{
struct pci_dev *pdev = adapter->pdev;
struct e1000_hw *hw = &adapter->hw;
struct e1000_mac_info *mac = &hw->mac;
struct e1000_fc_info *fc = &hw->fc;
u32 pba, hwm;
switch (mac->type) {
case e1000_i350:
case e1000_i354:
case e1000_82580:
pba = rd32(E1000_RXPBS);
pba = igb_rxpbs_adjust_82580(pba);
break;
case e1000_82576:
pba = rd32(E1000_RXPBS);
pba &= E1000_RXPBS_SIZE_MASK_82576;
break;
case e1000_82575:
case e1000_i210:
case e1000_i211:
default:
pba = E1000_PBA_34K;
break;
}
if (mac->type == e1000_82575) {
u32 min_rx_space, min_tx_space, needed_tx_space;
wr32(E1000_PBA, pba);
min_rx_space = DIV_ROUND_UP(MAX_JUMBO_FRAME_SIZE, 1024);
min_tx_space = adapter->max_frame_size;
min_tx_space += sizeof(union e1000_adv_tx_desc) - ETH_FCS_LEN;
min_tx_space = DIV_ROUND_UP(min_tx_space, 512);
needed_tx_space = min_tx_space - (rd32(E1000_PBA) >> 16);
if (needed_tx_space < pba) {
pba -= needed_tx_space;
if (pba < min_rx_space)
pba = min_rx_space;
}
wr32(E1000_PBA, pba);
}
hwm = (pba << 10) - (adapter->max_frame_size + MAX_JUMBO_FRAME_SIZE);
fc->high_water = hwm & 0xFFFFFFF0;
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
if (adapter->flags & IGB_FLAG_MEDIA_RESET) {
adapter->ei.get_invariants(hw);
adapter->flags &= ~IGB_FLAG_MEDIA_RESET;
}
if ((mac->type == e1000_82575) &&
(adapter->flags & IGB_FLAG_MAS_ENABLE)) {
igb_enable_mas(adapter);
}
if (hw->mac.ops.init_hw(hw))
dev_err(&pdev->dev, "Hardware Error\n");
if (!hw->mac.autoneg)
igb_force_mac_fc(hw);
igb_init_dmac(adapter, pba);
#ifdef CONFIG_IGB_HWMON
if (!test_bit(__IGB_DOWN, &adapter->state)) {
if (mac->type == e1000_i350 && hw->bus.func == 0) {
if (adapter->ets)
mac->ops.init_thermal_sensor_thresh(hw);
}
}
#endif
if (hw->phy.media_type == e1000_media_type_copper) {
switch (mac->type) {
case e1000_i350:
case e1000_i210:
case e1000_i211:
igb_set_eee_i350(hw, true, true);
break;
case e1000_i354:
igb_set_eee_i354(hw, true, true);
break;
default:
break;
}
}
if (!netif_running(adapter->netdev))
igb_power_down_link(adapter);
igb_update_mng_vlan(adapter);
wr32(E1000_VET, ETHERNET_IEEE_VLAN_TYPE);
if (adapter->ptp_flags & IGB_PTP_ENABLED)
igb_ptp_reset(adapter);
igb_get_phy_info(hw);
}
static netdev_features_t igb_fix_features(struct net_device *netdev,
netdev_features_t features)
{
if (features & NETIF_F_HW_VLAN_CTAG_RX)
features |= NETIF_F_HW_VLAN_CTAG_TX;
else
features &= ~NETIF_F_HW_VLAN_CTAG_TX;
return features;
}
static int igb_set_features(struct net_device *netdev,
netdev_features_t features)
{
netdev_features_t changed = netdev->features ^ features;
struct igb_adapter *adapter = netdev_priv(netdev);
if (changed & NETIF_F_HW_VLAN_CTAG_RX)
igb_vlan_mode(netdev, features);
if (!(changed & (NETIF_F_RXALL | NETIF_F_NTUPLE)))
return 0;
netdev->features = features;
if (netif_running(netdev))
igb_reinit_locked(adapter);
else
igb_reset(adapter);
return 0;
}
static int igb_ndo_fdb_add(struct ndmsg *ndm, struct nlattr *tb[],
struct net_device *dev,
const unsigned char *addr, u16 vid,
u16 flags)
{
if (is_unicast_ether_addr(addr) || is_link_local_ether_addr(addr)) {
struct igb_adapter *adapter = netdev_priv(dev);
struct e1000_hw *hw = &adapter->hw;
int vfn = adapter->vfs_allocated_count;
int rar_entries = hw->mac.rar_entry_count - (vfn + 1);
if (netdev_uc_count(dev) >= rar_entries)
return -ENOMEM;
}
return ndo_dflt_fdb_add(ndm, tb, dev, addr, vid, flags);
}
static netdev_features_t
igb_features_check(struct sk_buff *skb, struct net_device *dev,
netdev_features_t features)
{
unsigned int network_hdr_len, mac_hdr_len;
mac_hdr_len = skb_network_header(skb) - skb->data;
if (unlikely(mac_hdr_len > IGB_MAX_MAC_HDR_LEN))
return features & ~(NETIF_F_HW_CSUM |
NETIF_F_SCTP_CRC |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_TSO |
NETIF_F_TSO6);
network_hdr_len = skb_checksum_start(skb) - skb_network_header(skb);
if (unlikely(network_hdr_len > IGB_MAX_NETWORK_HDR_LEN))
return features & ~(NETIF_F_HW_CSUM |
NETIF_F_SCTP_CRC |
NETIF_F_TSO |
NETIF_F_TSO6);
if (skb->encapsulation && !(features & NETIF_F_TSO_MANGLEID))
features &= ~NETIF_F_TSO;
return features;
}
void igb_set_fw_version(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
struct e1000_fw_version fw;
igb_get_fw_version(hw, &fw);
switch (hw->mac.type) {
case e1000_i210:
case e1000_i211:
if (!(igb_get_flash_presence_i210(hw))) {
snprintf(adapter->fw_version,
sizeof(adapter->fw_version),
"%2d.%2d-%d",
fw.invm_major, fw.invm_minor,
fw.invm_img_type);
break;
}
default:
if (fw.or_valid) {
snprintf(adapter->fw_version,
sizeof(adapter->fw_version),
"%d.%d, 0x%08x, %d.%d.%d",
fw.eep_major, fw.eep_minor, fw.etrack_id,
fw.or_major, fw.or_build, fw.or_patch);
} else if (fw.etrack_id != 0X0000) {
snprintf(adapter->fw_version,
sizeof(adapter->fw_version),
"%d.%d, 0x%08x",
fw.eep_major, fw.eep_minor, fw.etrack_id);
} else {
snprintf(adapter->fw_version,
sizeof(adapter->fw_version),
"%d.%d.%d",
fw.eep_major, fw.eep_minor, fw.eep_build);
}
break;
}
}
static void igb_init_mas(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u16 eeprom_data;
hw->nvm.ops.read(hw, NVM_COMPAT, 1, &eeprom_data);
switch (hw->bus.func) {
case E1000_FUNC_0:
if (eeprom_data & IGB_MAS_ENABLE_0) {
adapter->flags |= IGB_FLAG_MAS_ENABLE;
netdev_info(adapter->netdev,
"MAS: Enabling Media Autosense for port %d\n",
hw->bus.func);
}
break;
case E1000_FUNC_1:
if (eeprom_data & IGB_MAS_ENABLE_1) {
adapter->flags |= IGB_FLAG_MAS_ENABLE;
netdev_info(adapter->netdev,
"MAS: Enabling Media Autosense for port %d\n",
hw->bus.func);
}
break;
case E1000_FUNC_2:
if (eeprom_data & IGB_MAS_ENABLE_2) {
adapter->flags |= IGB_FLAG_MAS_ENABLE;
netdev_info(adapter->netdev,
"MAS: Enabling Media Autosense for port %d\n",
hw->bus.func);
}
break;
case E1000_FUNC_3:
if (eeprom_data & IGB_MAS_ENABLE_3) {
adapter->flags |= IGB_FLAG_MAS_ENABLE;
netdev_info(adapter->netdev,
"MAS: Enabling Media Autosense for port %d\n",
hw->bus.func);
}
break;
default:
netdev_err(adapter->netdev,
"MAS: Invalid port configuration, returning\n");
break;
}
}
static s32 igb_init_i2c(struct igb_adapter *adapter)
{
s32 status = 0;
if (adapter->hw.mac.type != e1000_i350)
return 0;
adapter->i2c_adap.owner = THIS_MODULE;
adapter->i2c_algo = igb_i2c_algo;
adapter->i2c_algo.data = adapter;
adapter->i2c_adap.algo_data = &adapter->i2c_algo;
adapter->i2c_adap.dev.parent = &adapter->pdev->dev;
strlcpy(adapter->i2c_adap.name, "igb BB",
sizeof(adapter->i2c_adap.name));
status = i2c_bit_add_bus(&adapter->i2c_adap);
return status;
}
static int igb_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev;
struct igb_adapter *adapter;
struct e1000_hw *hw;
u16 eeprom_data = 0;
s32 ret_val;
static int global_quad_port_a;
const struct e1000_info *ei = igb_info_tbl[ent->driver_data];
int err, pci_using_dac;
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
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
if (!err) {
pci_using_dac = 1;
} else {
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev,
"No usable DMA configuration, aborting\n");
goto err_dma;
}
}
err = pci_request_mem_regions(pdev, igb_driver_name);
if (err)
goto err_pci_reg;
pci_enable_pcie_error_reporting(pdev);
pci_set_master(pdev);
pci_save_state(pdev);
err = -ENOMEM;
netdev = alloc_etherdev_mq(sizeof(struct igb_adapter),
IGB_MAX_TX_QUEUES);
if (!netdev)
goto err_alloc_etherdev;
SET_NETDEV_DEV(netdev, &pdev->dev);
pci_set_drvdata(pdev, netdev);
adapter = netdev_priv(netdev);
adapter->netdev = netdev;
adapter->pdev = pdev;
hw = &adapter->hw;
hw->back = adapter;
adapter->msg_enable = netif_msg_init(debug, DEFAULT_MSG_ENABLE);
err = -EIO;
adapter->io_addr = pci_iomap(pdev, 0, 0);
if (!adapter->io_addr)
goto err_ioremap;
hw->hw_addr = adapter->io_addr;
netdev->netdev_ops = &igb_netdev_ops;
igb_set_ethtool_ops(netdev);
netdev->watchdog_timeo = 5 * HZ;
strncpy(netdev->name, pci_name(pdev), sizeof(netdev->name) - 1);
netdev->mem_start = pci_resource_start(pdev, 0);
netdev->mem_end = pci_resource_end(pdev, 0);
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
netdev->features |= NETIF_F_SG |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_RXHASH |
NETIF_F_RXCSUM |
NETIF_F_HW_CSUM;
if (hw->mac.type >= e1000_82576)
netdev->features |= NETIF_F_SCTP_CRC;
#define IGB_GSO_PARTIAL_FEATURES (NETIF_F_GSO_GRE | \
NETIF_F_GSO_GRE_CSUM | \
NETIF_F_GSO_IPXIP4 | \
NETIF_F_GSO_IPXIP6 | \
NETIF_F_GSO_UDP_TUNNEL | \
NETIF_F_GSO_UDP_TUNNEL_CSUM)
netdev->gso_partial_features = IGB_GSO_PARTIAL_FEATURES;
netdev->features |= NETIF_F_GSO_PARTIAL | IGB_GSO_PARTIAL_FEATURES;
netdev->hw_features |= netdev->features |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_RXALL;
if (hw->mac.type >= e1000_i350)
netdev->hw_features |= NETIF_F_NTUPLE;
if (pci_using_dac)
netdev->features |= NETIF_F_HIGHDMA;
netdev->vlan_features |= netdev->features | NETIF_F_TSO_MANGLEID;
netdev->mpls_features |= NETIF_F_HW_CSUM;
netdev->hw_enc_features |= netdev->vlan_features;
netdev->features |= NETIF_F_HW_VLAN_CTAG_FILTER |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_TX;
netdev->priv_flags |= IFF_SUPP_NOFCS;
netdev->priv_flags |= IFF_UNICAST_FLT;
adapter->en_mng_pt = igb_enable_mng_pass_thru(hw);
hw->mac.ops.reset_hw(hw);
switch (hw->mac.type) {
case e1000_i210:
case e1000_i211:
if (igb_get_flash_presence_i210(hw)) {
if (hw->nvm.ops.validate(hw) < 0) {
dev_err(&pdev->dev,
"The NVM Checksum Is Not Valid\n");
err = -EIO;
goto err_eeprom;
}
}
break;
default:
if (hw->nvm.ops.validate(hw) < 0) {
dev_err(&pdev->dev, "The NVM Checksum Is Not Valid\n");
err = -EIO;
goto err_eeprom;
}
break;
}
if (eth_platform_get_mac_address(&pdev->dev, hw->mac.addr)) {
if (hw->mac.ops.read_mac_addr(hw))
dev_err(&pdev->dev, "NVM Read Error\n");
}
memcpy(netdev->dev_addr, hw->mac.addr, netdev->addr_len);
if (!is_valid_ether_addr(netdev->dev_addr)) {
dev_err(&pdev->dev, "Invalid MAC Address\n");
err = -EIO;
goto err_eeprom;
}
igb_set_fw_version(adapter);
if (hw->mac.type == e1000_i210) {
wr32(E1000_RXPBS, I210_RXPBSIZE_DEFAULT);
wr32(E1000_TXPBS, I210_TXPBSIZE_DEFAULT);
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
adapter->flags |= IGB_FLAG_WOL_SUPPORTED;
if (hw->mac.type >= e1000_82580)
hw->nvm.ops.read(hw, NVM_INIT_CONTROL3_PORT_A +
NVM_82580_LAN_FUNC_OFFSET(hw->bus.func), 1,
&eeprom_data);
else if (hw->bus.func == 1)
hw->nvm.ops.read(hw, NVM_INIT_CONTROL3_PORT_B, 1, &eeprom_data);
if (eeprom_data & IGB_EEPROM_APME)
adapter->flags |= IGB_FLAG_WOL_SUPPORTED;
switch (pdev->device) {
case E1000_DEV_ID_82575GB_QUAD_COPPER:
adapter->flags &= ~IGB_FLAG_WOL_SUPPORTED;
break;
case E1000_DEV_ID_82575EB_FIBER_SERDES:
case E1000_DEV_ID_82576_FIBER:
case E1000_DEV_ID_82576_SERDES:
if (rd32(E1000_STATUS) & E1000_STATUS_FUNC_1)
adapter->flags &= ~IGB_FLAG_WOL_SUPPORTED;
break;
case E1000_DEV_ID_82576_QUAD_COPPER:
case E1000_DEV_ID_82576_QUAD_COPPER_ET2:
if (global_quad_port_a != 0)
adapter->flags &= ~IGB_FLAG_WOL_SUPPORTED;
else
adapter->flags |= IGB_FLAG_QUAD_PORT_A;
if (++global_quad_port_a == 4)
global_quad_port_a = 0;
break;
default:
if (!device_can_wakeup(&adapter->pdev->dev))
adapter->flags &= ~IGB_FLAG_WOL_SUPPORTED;
}
if (adapter->flags & IGB_FLAG_WOL_SUPPORTED)
adapter->wol |= E1000_WUFC_MAG;
if ((hw->mac.type == e1000_i350) &&
(pdev->subsystem_vendor == PCI_VENDOR_ID_HP)) {
adapter->flags |= IGB_FLAG_WOL_SUPPORTED;
adapter->wol = 0;
}
if (((hw->mac.type == e1000_i350) ||
(hw->mac.type == e1000_i354)) &&
(pdev->subsystem_vendor == PCI_VENDOR_ID_DELL)) {
adapter->flags |= IGB_FLAG_WOL_SUPPORTED;
adapter->wol = 0;
}
if (hw->mac.type == e1000_i350) {
if (((pdev->subsystem_device == 0x5001) ||
(pdev->subsystem_device == 0x5002)) &&
(hw->bus.func == 0)) {
adapter->flags |= IGB_FLAG_WOL_SUPPORTED;
adapter->wol = 0;
}
if (pdev->subsystem_device == 0x1F52)
adapter->flags |= IGB_FLAG_WOL_SUPPORTED;
}
device_set_wakeup_enable(&adapter->pdev->dev,
adapter->flags & IGB_FLAG_WOL_SUPPORTED);
igb_reset(adapter);
err = igb_init_i2c(adapter);
if (err) {
dev_err(&pdev->dev, "failed to init i2c interface\n");
goto err_eeprom;
}
igb_get_hw_control(adapter);
strcpy(netdev->name, "eth%d");
err = register_netdev(netdev);
if (err)
goto err_register;
netif_carrier_off(netdev);
#ifdef CONFIG_IGB_DCA
if (dca_add_requester(&pdev->dev) == 0) {
adapter->flags |= IGB_FLAG_DCA_ENABLED;
dev_info(&pdev->dev, "DCA enabled\n");
igb_setup_dca(adapter);
}
#endif
#ifdef CONFIG_IGB_HWMON
if (hw->mac.type == e1000_i350 && hw->bus.func == 0) {
u16 ets_word;
hw->nvm.ops.read(hw, NVM_ETS_CFG, 1, &ets_word);
if (ets_word != 0x0000 && ets_word != 0xFFFF)
adapter->ets = true;
else
adapter->ets = false;
if (igb_sysfs_init(adapter))
dev_err(&pdev->dev,
"failed to allocate sysfs resources\n");
} else {
adapter->ets = false;
}
#endif
adapter->ei = *ei;
if (hw->dev_spec._82575.mas_capable)
igb_init_mas(adapter);
igb_ptp_init(adapter);
dev_info(&pdev->dev, "Intel(R) Gigabit Ethernet Network Connection\n");
if (hw->mac.type != e1000_i354) {
dev_info(&pdev->dev, "%s: (PCIe:%s:%s) %pM\n",
netdev->name,
((hw->bus.speed == e1000_bus_speed_2500) ? "2.5Gb/s" :
(hw->bus.speed == e1000_bus_speed_5000) ? "5.0Gb/s" :
"unknown"),
((hw->bus.width == e1000_bus_width_pcie_x4) ?
"Width x4" :
(hw->bus.width == e1000_bus_width_pcie_x2) ?
"Width x2" :
(hw->bus.width == e1000_bus_width_pcie_x1) ?
"Width x1" : "unknown"), netdev->dev_addr);
}
if ((hw->mac.type >= e1000_i210 ||
igb_get_flash_presence_i210(hw))) {
ret_val = igb_read_part_string(hw, part_str,
E1000_PBANUM_LENGTH);
} else {
ret_val = -E1000_ERR_INVM_VALUE_NOT_FOUND;
}
if (ret_val)
strcpy(part_str, "Unknown");
dev_info(&pdev->dev, "%s: PBA No: %s\n", netdev->name, part_str);
dev_info(&pdev->dev,
"Using %s interrupts. %d rx queue(s), %d tx queue(s)\n",
(adapter->flags & IGB_FLAG_HAS_MSIX) ? "MSI-X" :
(adapter->flags & IGB_FLAG_HAS_MSI) ? "MSI" : "legacy",
adapter->num_rx_queues, adapter->num_tx_queues);
if (hw->phy.media_type == e1000_media_type_copper) {
switch (hw->mac.type) {
case e1000_i350:
case e1000_i210:
case e1000_i211:
err = igb_set_eee_i350(hw, true, true);
if ((!err) &&
(!hw->dev_spec._82575.eee_disable)) {
adapter->eee_advert =
MDIO_EEE_100TX | MDIO_EEE_1000T;
adapter->flags |= IGB_FLAG_EEE;
}
break;
case e1000_i354:
if ((rd32(E1000_CTRL_EXT) &
E1000_CTRL_EXT_LINK_MODE_SGMII)) {
err = igb_set_eee_i354(hw, true, true);
if ((!err) &&
(!hw->dev_spec._82575.eee_disable)) {
adapter->eee_advert =
MDIO_EEE_100TX | MDIO_EEE_1000T;
adapter->flags |= IGB_FLAG_EEE;
}
}
break;
default:
break;
}
}
pm_runtime_put_noidle(&pdev->dev);
return 0;
err_register:
igb_release_hw_control(adapter);
memset(&adapter->i2c_adap, 0, sizeof(adapter->i2c_adap));
err_eeprom:
if (!igb_check_reset_block(hw))
igb_reset_phy(hw);
if (hw->flash_address)
iounmap(hw->flash_address);
err_sw_init:
kfree(adapter->shadow_vfta);
igb_clear_interrupt_scheme(adapter);
#ifdef CONFIG_PCI_IOV
igb_disable_sriov(pdev);
#endif
pci_iounmap(pdev, adapter->io_addr);
err_ioremap:
free_netdev(netdev);
err_alloc_etherdev:
pci_release_mem_regions(pdev);
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static int igb_disable_sriov(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
if (adapter->vf_data) {
if (pci_vfs_assigned(pdev)) {
dev_warn(&pdev->dev,
"Cannot deallocate SR-IOV virtual functions while they are assigned - VFs will not be deallocated\n");
return -EPERM;
} else {
pci_disable_sriov(pdev);
msleep(500);
}
kfree(adapter->vf_data);
adapter->vf_data = NULL;
adapter->vfs_allocated_count = 0;
wr32(E1000_IOVCTL, E1000_IOVCTL_REUSE_VFQ);
wrfl();
msleep(100);
dev_info(&pdev->dev, "IOV Disabled\n");
adapter->flags |= IGB_FLAG_DMAC;
}
return 0;
}
static int igb_enable_sriov(struct pci_dev *pdev, int num_vfs)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
int old_vfs = pci_num_vf(pdev);
int err = 0;
int i;
if (!(adapter->flags & IGB_FLAG_HAS_MSIX) || num_vfs > 7) {
err = -EPERM;
goto out;
}
if (!num_vfs)
goto out;
if (old_vfs) {
dev_info(&pdev->dev, "%d pre-allocated VFs found - override max_vfs setting of %d\n",
old_vfs, max_vfs);
adapter->vfs_allocated_count = old_vfs;
} else
adapter->vfs_allocated_count = num_vfs;
adapter->vf_data = kcalloc(adapter->vfs_allocated_count,
sizeof(struct vf_data_storage), GFP_KERNEL);
if (!adapter->vf_data) {
adapter->vfs_allocated_count = 0;
dev_err(&pdev->dev,
"Unable to allocate memory for VF Data Storage\n");
err = -ENOMEM;
goto out;
}
if (!old_vfs) {
err = pci_enable_sriov(pdev, adapter->vfs_allocated_count);
if (err)
goto err_out;
}
dev_info(&pdev->dev, "%d VFs allocated\n",
adapter->vfs_allocated_count);
for (i = 0; i < adapter->vfs_allocated_count; i++)
igb_vf_configure(adapter, i);
adapter->flags &= ~IGB_FLAG_DMAC;
goto out;
err_out:
kfree(adapter->vf_data);
adapter->vf_data = NULL;
adapter->vfs_allocated_count = 0;
out:
return err;
}
static void igb_remove_i2c(struct igb_adapter *adapter)
{
i2c_del_adapter(&adapter->i2c_adap);
}
static void igb_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
pm_runtime_get_noresume(&pdev->dev);
#ifdef CONFIG_IGB_HWMON
igb_sysfs_exit(adapter);
#endif
igb_remove_i2c(adapter);
igb_ptp_stop(adapter);
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
#ifdef CONFIG_PCI_IOV
igb_disable_sriov(pdev);
#endif
unregister_netdev(netdev);
igb_clear_interrupt_scheme(adapter);
pci_iounmap(pdev, adapter->io_addr);
if (hw->flash_address)
iounmap(hw->flash_address);
pci_release_mem_regions(pdev);
kfree(adapter->shadow_vfta);
free_netdev(netdev);
pci_disable_pcie_error_reporting(pdev);
pci_disable_device(pdev);
}
static void igb_probe_vfs(struct igb_adapter *adapter)
{
#ifdef CONFIG_PCI_IOV
struct pci_dev *pdev = adapter->pdev;
struct e1000_hw *hw = &adapter->hw;
if ((hw->mac.type == e1000_i210) || (hw->mac.type == e1000_i211))
return;
igb_set_interrupt_capability(adapter, true);
igb_reset_interrupt_capability(adapter);
pci_sriov_set_totalvfs(pdev, 7);
igb_enable_sriov(pdev, max_vfs);
#endif
}
static void igb_init_queue_configuration(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 max_rss_queues;
switch (hw->mac.type) {
case e1000_i211:
max_rss_queues = IGB_MAX_RX_QUEUES_I211;
break;
case e1000_82575:
case e1000_i210:
max_rss_queues = IGB_MAX_RX_QUEUES_82575;
break;
case e1000_i350:
if (!!adapter->vfs_allocated_count) {
max_rss_queues = 1;
break;
}
case e1000_82576:
if (!!adapter->vfs_allocated_count) {
max_rss_queues = 2;
break;
}
case e1000_82580:
case e1000_i354:
default:
max_rss_queues = IGB_MAX_RX_QUEUES;
break;
}
adapter->rss_queues = min_t(u32, max_rss_queues, num_online_cpus());
igb_set_flag_queue_pairs(adapter, max_rss_queues);
}
void igb_set_flag_queue_pairs(struct igb_adapter *adapter,
const u32 max_rss_queues)
{
struct e1000_hw *hw = &adapter->hw;
switch (hw->mac.type) {
case e1000_82575:
case e1000_i211:
break;
case e1000_82576:
case e1000_82580:
case e1000_i350:
case e1000_i354:
case e1000_i210:
default:
if (adapter->rss_queues > (max_rss_queues / 2))
adapter->flags |= IGB_FLAG_QUEUE_PAIRS;
else
adapter->flags &= ~IGB_FLAG_QUEUE_PAIRS;
break;
}
}
static int igb_sw_init(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
struct pci_dev *pdev = adapter->pdev;
pci_read_config_word(pdev, PCI_COMMAND, &hw->bus.pci_cmd_word);
adapter->tx_ring_count = IGB_DEFAULT_TXD;
adapter->rx_ring_count = IGB_DEFAULT_RXD;
adapter->rx_itr_setting = IGB_DEFAULT_ITR;
adapter->tx_itr_setting = IGB_DEFAULT_ITR;
adapter->tx_work_limit = IGB_DEFAULT_TX_WORK;
adapter->max_frame_size = netdev->mtu + ETH_HLEN + ETH_FCS_LEN +
VLAN_HLEN;
adapter->min_frame_size = ETH_ZLEN + ETH_FCS_LEN;
spin_lock_init(&adapter->stats64_lock);
#ifdef CONFIG_PCI_IOV
switch (hw->mac.type) {
case e1000_82576:
case e1000_i350:
if (max_vfs > 7) {
dev_warn(&pdev->dev,
"Maximum of 7 VFs per PF, using max\n");
max_vfs = adapter->vfs_allocated_count = 7;
} else
adapter->vfs_allocated_count = max_vfs;
if (adapter->vfs_allocated_count)
dev_warn(&pdev->dev,
"Enabling SR-IOV VFs using the module parameter is deprecated - please use the pci sysfs interface.\n");
break;
default:
break;
}
#endif
adapter->flags |= IGB_FLAG_HAS_MSIX;
igb_probe_vfs(adapter);
igb_init_queue_configuration(adapter);
adapter->shadow_vfta = kcalloc(E1000_VLAN_FILTER_TBL_SIZE, sizeof(u32),
GFP_ATOMIC);
if (igb_init_interrupt_scheme(adapter, true)) {
dev_err(&pdev->dev, "Unable to allocate memory for queues\n");
return -ENOMEM;
}
igb_irq_disable(adapter);
if (hw->mac.type >= e1000_i350)
adapter->flags &= ~IGB_FLAG_DMAC;
set_bit(__IGB_DOWN, &adapter->state);
return 0;
}
static int __igb_open(struct net_device *netdev, bool resuming)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
int err;
int i;
if (test_bit(__IGB_TESTING, &adapter->state)) {
WARN_ON(resuming);
return -EBUSY;
}
if (!resuming)
pm_runtime_get_sync(&pdev->dev);
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
err = netif_set_real_num_tx_queues(adapter->netdev,
adapter->num_tx_queues);
if (err)
goto err_set_queues;
err = netif_set_real_num_rx_queues(adapter->netdev,
adapter->num_rx_queues);
if (err)
goto err_set_queues;
clear_bit(__IGB_DOWN, &adapter->state);
for (i = 0; i < adapter->num_q_vectors; i++)
napi_enable(&(adapter->q_vector[i]->napi));
rd32(E1000_ICR);
igb_irq_enable(adapter);
if (adapter->vfs_allocated_count) {
u32 reg_data = rd32(E1000_CTRL_EXT);
reg_data |= E1000_CTRL_EXT_PFRSTD;
wr32(E1000_CTRL_EXT, reg_data);
}
netif_tx_start_all_queues(netdev);
if (!resuming)
pm_runtime_put(&pdev->dev);
hw->mac.get_link_status = 1;
schedule_work(&adapter->watchdog_task);
return 0;
err_set_queues:
igb_free_irq(adapter);
err_req_irq:
igb_release_hw_control(adapter);
igb_power_down_link(adapter);
igb_free_all_rx_resources(adapter);
err_setup_rx:
igb_free_all_tx_resources(adapter);
err_setup_tx:
igb_reset(adapter);
if (!resuming)
pm_runtime_put(&pdev->dev);
return err;
}
int igb_open(struct net_device *netdev)
{
return __igb_open(netdev, false);
}
static int __igb_close(struct net_device *netdev, bool suspending)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct pci_dev *pdev = adapter->pdev;
WARN_ON(test_bit(__IGB_RESETTING, &adapter->state));
if (!suspending)
pm_runtime_get_sync(&pdev->dev);
igb_down(adapter);
igb_free_irq(adapter);
igb_free_all_tx_resources(adapter);
igb_free_all_rx_resources(adapter);
if (!suspending)
pm_runtime_put_sync(&pdev->dev);
return 0;
}
int igb_close(struct net_device *netdev)
{
return __igb_close(netdev, false);
}
int igb_setup_tx_resources(struct igb_ring *tx_ring)
{
struct device *dev = tx_ring->dev;
int size;
size = sizeof(struct igb_tx_buffer) * tx_ring->count;
tx_ring->tx_buffer_info = vzalloc(size);
if (!tx_ring->tx_buffer_info)
goto err;
tx_ring->size = tx_ring->count * sizeof(union e1000_adv_tx_desc);
tx_ring->size = ALIGN(tx_ring->size, 4096);
tx_ring->desc = dma_alloc_coherent(dev, tx_ring->size,
&tx_ring->dma, GFP_KERNEL);
if (!tx_ring->desc)
goto err;
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
return 0;
err:
vfree(tx_ring->tx_buffer_info);
tx_ring->tx_buffer_info = NULL;
dev_err(dev, "Unable to allocate memory for the Tx descriptor ring\n");
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
u32 txdctl = 0;
u64 tdba = ring->dma;
int reg_idx = ring->reg_idx;
wr32(E1000_TXDCTL(reg_idx), 0);
wrfl();
mdelay(10);
wr32(E1000_TDLEN(reg_idx),
ring->count * sizeof(union e1000_adv_tx_desc));
wr32(E1000_TDBAL(reg_idx),
tdba & 0x00000000ffffffffULL);
wr32(E1000_TDBAH(reg_idx), tdba >> 32);
ring->tail = hw->hw_addr + E1000_TDT(reg_idx);
wr32(E1000_TDH(reg_idx), 0);
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
int size;
size = sizeof(struct igb_rx_buffer) * rx_ring->count;
rx_ring->rx_buffer_info = vzalloc(size);
if (!rx_ring->rx_buffer_info)
goto err;
rx_ring->size = rx_ring->count * sizeof(union e1000_adv_rx_desc);
rx_ring->size = ALIGN(rx_ring->size, 4096);
rx_ring->desc = dma_alloc_coherent(dev, rx_ring->size,
&rx_ring->dma, GFP_KERNEL);
if (!rx_ring->desc)
goto err;
rx_ring->next_to_alloc = 0;
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
return 0;
err:
vfree(rx_ring->rx_buffer_info);
rx_ring->rx_buffer_info = NULL;
dev_err(dev, "Unable to allocate memory for the Rx descriptor ring\n");
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
u32 j, num_rx_queues;
u32 rss_key[10];
netdev_rss_key_fill(rss_key, sizeof(rss_key));
for (j = 0; j < 10; j++)
wr32(E1000_RSSRK(j), rss_key[j]);
num_rx_queues = adapter->rss_queues;
switch (hw->mac.type) {
case e1000_82576:
if (adapter->vfs_allocated_count)
num_rx_queues = 2;
break;
default:
break;
}
if (adapter->rss_indir_tbl_init != num_rx_queues) {
for (j = 0; j < IGB_RETA_SIZE; j++)
adapter->rss_indir_tbl[j] =
(j * num_rx_queues) / IGB_RETA_SIZE;
adapter->rss_indir_tbl_init = num_rx_queues;
}
igb_write_rss_indir_tbl(adapter);
rxcsum = rd32(E1000_RXCSUM);
rxcsum |= E1000_RXCSUM_PCSD;
if (adapter->hw.mac.type >= e1000_82576)
rxcsum |= E1000_RXCSUM_CRCOFL;
wr32(E1000_RXCSUM, rxcsum);
mrqc = E1000_MRQC_RSS_FIELD_IPV4 |
E1000_MRQC_RSS_FIELD_IPV4_TCP |
E1000_MRQC_RSS_FIELD_IPV6 |
E1000_MRQC_RSS_FIELD_IPV6_TCP |
E1000_MRQC_RSS_FIELD_IPV6_TCP_EX;
if (adapter->flags & IGB_FLAG_RSS_FIELD_IPV4_UDP)
mrqc |= E1000_MRQC_RSS_FIELD_IPV4_UDP;
if (adapter->flags & IGB_FLAG_RSS_FIELD_IPV6_UDP)
mrqc |= E1000_MRQC_RSS_FIELD_IPV6_UDP;
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
mrqc |= E1000_MRQC_ENABLE_VMDQ_RSS_MQ;
else
mrqc |= E1000_MRQC_ENABLE_VMDQ;
} else {
if (hw->mac.type != e1000_i211)
mrqc |= E1000_MRQC_ENABLE_RSS_MQ;
}
igb_vmm_control(adapter);
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
if (adapter->netdev->features & NETIF_F_RXALL) {
rctl |= (E1000_RCTL_SBP |
E1000_RCTL_BAM |
E1000_RCTL_PMCF);
rctl &= ~(E1000_RCTL_DPF |
E1000_RCTL_CFIEN);
}
wr32(E1000_RCTL, rctl);
}
static inline int igb_set_vf_rlpml(struct igb_adapter *adapter, int size,
int vfn)
{
struct e1000_hw *hw = &adapter->hw;
u32 vmolr;
if (size > MAX_JUMBO_FRAME_SIZE)
size = MAX_JUMBO_FRAME_SIZE;
vmolr = rd32(E1000_VMOLR(vfn));
vmolr &= ~E1000_VMOLR_RLPML_MASK;
vmolr |= size | E1000_VMOLR_LPE;
wr32(E1000_VMOLR(vfn), vmolr);
return 0;
}
static inline void igb_set_vf_vlan_strip(struct igb_adapter *adapter,
int vfn, bool enable)
{
struct e1000_hw *hw = &adapter->hw;
u32 val, reg;
if (hw->mac.type < e1000_82576)
return;
if (hw->mac.type == e1000_i350)
reg = E1000_DVMOLR(vfn);
else
reg = E1000_VMOLR(vfn);
val = rd32(reg);
if (enable)
val |= E1000_VMOLR_STRVLAN;
else
val &= ~(E1000_VMOLR_STRVLAN);
wr32(reg, val);
}
static inline void igb_set_vmolr(struct igb_adapter *adapter,
int vfn, bool aupe)
{
struct e1000_hw *hw = &adapter->hw;
u32 vmolr;
if (hw->mac.type < e1000_82576)
return;
vmolr = rd32(E1000_VMOLR(vfn));
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
u32 srrctl = 0, rxdctl = 0;
wr32(E1000_RXDCTL(reg_idx), 0);
wr32(E1000_RDBAL(reg_idx),
rdba & 0x00000000ffffffffULL);
wr32(E1000_RDBAH(reg_idx), rdba >> 32);
wr32(E1000_RDLEN(reg_idx),
ring->count * sizeof(union e1000_adv_rx_desc));
ring->tail = hw->hw_addr + E1000_RDT(reg_idx);
wr32(E1000_RDH(reg_idx), 0);
writel(0, ring->tail);
srrctl = IGB_RX_HDR_LEN << E1000_SRRCTL_BSIZEHDRSIZE_SHIFT;
srrctl |= IGB_RX_BUFSZ >> E1000_SRRCTL_BSIZEPKT_SHIFT;
srrctl |= E1000_SRRCTL_DESCTYPE_ADV_ONEBUF;
if (hw->mac.type >= e1000_82580)
srrctl |= E1000_SRRCTL_TIMESTAMP;
if (adapter->vfs_allocated_count || adapter->num_rx_queues > 1)
srrctl |= E1000_SRRCTL_DROP_EN;
wr32(E1000_SRRCTL(reg_idx), srrctl);
igb_set_vmolr(adapter, reg_idx & 0x7, true);
rxdctl |= IGB_RX_PTHRESH;
rxdctl |= IGB_RX_HTHRESH << 8;
rxdctl |= IGB_RX_WTHRESH << 16;
rxdctl |= E1000_RXDCTL_QUEUE_ENABLE;
wr32(E1000_RXDCTL(reg_idx), rxdctl);
}
static void igb_configure_rx(struct igb_adapter *adapter)
{
int i;
igb_rar_set_qsel(adapter, adapter->hw.mac.addr, 0,
adapter->vfs_allocated_count);
for (i = 0; i < adapter->num_rx_queues; i++)
igb_configure_rx_ring(adapter, adapter->rx_ring[i]);
}
void igb_free_tx_resources(struct igb_ring *tx_ring)
{
igb_clean_tx_ring(tx_ring);
vfree(tx_ring->tx_buffer_info);
tx_ring->tx_buffer_info = NULL;
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
if (adapter->tx_ring[i])
igb_free_tx_resources(adapter->tx_ring[i]);
}
void igb_unmap_and_free_tx_resource(struct igb_ring *ring,
struct igb_tx_buffer *tx_buffer)
{
if (tx_buffer->skb) {
dev_kfree_skb_any(tx_buffer->skb);
if (dma_unmap_len(tx_buffer, len))
dma_unmap_single(ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
} else if (dma_unmap_len(tx_buffer, len)) {
dma_unmap_page(ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
}
tx_buffer->next_to_watch = NULL;
tx_buffer->skb = NULL;
dma_unmap_len_set(tx_buffer, len, 0);
}
static void igb_clean_tx_ring(struct igb_ring *tx_ring)
{
struct igb_tx_buffer *buffer_info;
unsigned long size;
u16 i;
if (!tx_ring->tx_buffer_info)
return;
for (i = 0; i < tx_ring->count; i++) {
buffer_info = &tx_ring->tx_buffer_info[i];
igb_unmap_and_free_tx_resource(tx_ring, buffer_info);
}
netdev_tx_reset_queue(txring_txq(tx_ring));
size = sizeof(struct igb_tx_buffer) * tx_ring->count;
memset(tx_ring->tx_buffer_info, 0, size);
memset(tx_ring->desc, 0, tx_ring->size);
tx_ring->next_to_use = 0;
tx_ring->next_to_clean = 0;
}
static void igb_clean_all_tx_rings(struct igb_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_tx_queues; i++)
if (adapter->tx_ring[i])
igb_clean_tx_ring(adapter->tx_ring[i]);
}
void igb_free_rx_resources(struct igb_ring *rx_ring)
{
igb_clean_rx_ring(rx_ring);
vfree(rx_ring->rx_buffer_info);
rx_ring->rx_buffer_info = NULL;
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
if (adapter->rx_ring[i])
igb_free_rx_resources(adapter->rx_ring[i]);
}
static void igb_clean_rx_ring(struct igb_ring *rx_ring)
{
unsigned long size;
u16 i;
if (rx_ring->skb)
dev_kfree_skb(rx_ring->skb);
rx_ring->skb = NULL;
if (!rx_ring->rx_buffer_info)
return;
for (i = 0; i < rx_ring->count; i++) {
struct igb_rx_buffer *buffer_info = &rx_ring->rx_buffer_info[i];
if (!buffer_info->page)
continue;
dma_unmap_page(rx_ring->dev,
buffer_info->dma,
PAGE_SIZE,
DMA_FROM_DEVICE);
__free_page(buffer_info->page);
buffer_info->page = NULL;
}
size = sizeof(struct igb_rx_buffer) * rx_ring->count;
memset(rx_ring->rx_buffer_info, 0, size);
memset(rx_ring->desc, 0, rx_ring->size);
rx_ring->next_to_alloc = 0;
rx_ring->next_to_clean = 0;
rx_ring->next_to_use = 0;
}
static void igb_clean_all_rx_rings(struct igb_adapter *adapter)
{
int i;
for (i = 0; i < adapter->num_rx_queues; i++)
if (adapter->rx_ring[i])
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
static int igb_vlan_promisc_enable(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 i, pf_id;
switch (hw->mac.type) {
case e1000_i210:
case e1000_i211:
case e1000_i350:
if (adapter->netdev->features & NETIF_F_NTUPLE)
break;
case e1000_82576:
case e1000_82580:
case e1000_i354:
if (adapter->vfs_allocated_count)
break;
default:
return 1;
}
if (adapter->flags & IGB_FLAG_VLAN_PROMISC)
return 0;
if (!adapter->vfs_allocated_count)
goto set_vfta;
pf_id = adapter->vfs_allocated_count + E1000_VLVF_POOLSEL_SHIFT;
for (i = E1000_VLVF_ARRAY_SIZE; --i;) {
u32 vlvf = rd32(E1000_VLVF(i));
vlvf |= BIT(pf_id);
wr32(E1000_VLVF(i), vlvf);
}
set_vfta:
for (i = E1000_VLAN_FILTER_TBL_SIZE; i--;)
hw->mac.ops.write_vfta(hw, i, ~0U);
adapter->flags |= IGB_FLAG_VLAN_PROMISC;
return 0;
}
static void igb_scrub_vfta(struct igb_adapter *adapter, u32 vfta_offset)
{
struct e1000_hw *hw = &adapter->hw;
u32 vfta[VFTA_BLOCK_SIZE] = { 0 };
u32 vid_start = vfta_offset * 32;
u32 vid_end = vid_start + (VFTA_BLOCK_SIZE * 32);
u32 i, vid, word, bits, pf_id;
vid = adapter->mng_vlan_id;
if (vid >= vid_start && vid < vid_end)
vfta[(vid - vid_start) / 32] |= BIT(vid % 32);
if (!adapter->vfs_allocated_count)
goto set_vfta;
pf_id = adapter->vfs_allocated_count + E1000_VLVF_POOLSEL_SHIFT;
for (i = E1000_VLVF_ARRAY_SIZE; --i;) {
u32 vlvf = rd32(E1000_VLVF(i));
vid = vlvf & VLAN_VID_MASK;
if (vid < vid_start || vid >= vid_end)
continue;
if (vlvf & E1000_VLVF_VLANID_ENABLE) {
vfta[(vid - vid_start) / 32] |= BIT(vid % 32);
if (test_bit(vid, adapter->active_vlans))
continue;
}
bits = ~BIT(pf_id);
bits &= rd32(E1000_VLVF(i));
wr32(E1000_VLVF(i), bits);
}
set_vfta:
for (i = VFTA_BLOCK_SIZE; i--;) {
vid = (vfta_offset + i) * 32;
word = vid / BITS_PER_LONG;
bits = vid % BITS_PER_LONG;
vfta[i] |= adapter->active_vlans[word] >> bits;
hw->mac.ops.write_vfta(hw, vfta_offset + i, vfta[i]);
}
}
static void igb_vlan_promisc_disable(struct igb_adapter *adapter)
{
u32 i;
if (!(adapter->flags & IGB_FLAG_VLAN_PROMISC))
return;
adapter->flags &= ~IGB_FLAG_VLAN_PROMISC;
for (i = 0; i < E1000_VLAN_FILTER_TBL_SIZE; i += VFTA_BLOCK_SIZE)
igb_scrub_vfta(adapter, i);
}
static void igb_set_rx_mode(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
unsigned int vfn = adapter->vfs_allocated_count;
u32 rctl = 0, vmolr = 0;
int count;
if (netdev->flags & IFF_PROMISC) {
rctl |= E1000_RCTL_UPE | E1000_RCTL_MPE;
vmolr |= E1000_VMOLR_MPME;
if (hw->mac.type == e1000_82576)
vmolr |= E1000_VMOLR_ROPE;
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
}
count = igb_write_uc_addr_list(netdev);
if (count < 0) {
rctl |= E1000_RCTL_UPE;
vmolr |= E1000_VMOLR_ROPE;
}
rctl |= E1000_RCTL_VFE;
if ((netdev->flags & IFF_PROMISC) ||
(netdev->features & NETIF_F_RXALL)) {
if (igb_vlan_promisc_enable(adapter))
rctl &= ~E1000_RCTL_VFE;
} else {
igb_vlan_promisc_disable(adapter);
}
rctl |= rd32(E1000_RCTL) & ~(E1000_RCTL_UPE | E1000_RCTL_MPE |
E1000_RCTL_VFE);
wr32(E1000_RCTL, rctl);
if ((hw->mac.type < e1000_82576) || (hw->mac.type > e1000_i350))
return;
igb_set_uta(adapter, !!(vmolr & E1000_VMOLR_ROPE));
vmolr |= rd32(E1000_VMOLR(vfn)) &
~(E1000_VMOLR_ROPE | E1000_VMOLR_MPME | E1000_VMOLR_ROMPE);
vmolr &= ~E1000_VMOLR_RLPML_MASK;
vmolr |= MAX_JUMBO_FRAME_SIZE | E1000_VMOLR_LPE;
wr32(E1000_VMOLR(vfn), vmolr);
wr32(E1000_RLPML, MAX_JUMBO_FRAME_SIZE);
igb_restore_vf_multicasts(adapter);
}
static void igb_check_wvbr(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 wvbr = 0;
switch (hw->mac.type) {
case e1000_82576:
case e1000_i350:
wvbr = rd32(E1000_WVBR);
if (!wvbr)
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
for (j = 0; j < adapter->vfs_allocated_count; j++) {
if (adapter->wvbr & BIT(j) ||
adapter->wvbr & BIT(j + IGB_STAGGERED_QUEUE_OFFSET)) {
dev_warn(&adapter->pdev->dev,
"Spoof event(s) detected on VF %d\n", j);
adapter->wvbr &=
~(BIT(j) |
BIT(j + IGB_STAGGERED_QUEUE_OFFSET));
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
switch (hw->phy.media_type) {
case e1000_media_type_copper:
if (!hw->mac.get_link_status)
return true;
case e1000_media_type_internal_serdes:
hw->mac.ops.check_for_link(hw);
link_active = !hw->mac.get_link_status;
break;
default:
case e1000_media_type_unknown:
break;
}
if (((hw->mac.type == e1000_i210) ||
(hw->mac.type == e1000_i211)) &&
(hw->phy.id == I210_I_PHY_ID)) {
if (!netif_carrier_ok(adapter->netdev)) {
adapter->flags &= ~IGB_FLAG_NEED_LINK_UPDATE;
} else if (!(adapter->flags & IGB_FLAG_NEED_LINK_UPDATE)) {
adapter->flags |= IGB_FLAG_NEED_LINK_UPDATE;
adapter->link_check_timeout = jiffies;
}
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
!(ctrl_ext & E1000_CTRL_EXT_LINK_MODE_SGMII))
ret = !!(thstat & event);
}
return ret;
}
static void igb_check_lvmmc(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 lvmmc;
lvmmc = rd32(E1000_LVMMC);
if (lvmmc) {
if (unlikely(net_ratelimit())) {
netdev_warn(adapter->netdev,
"malformed Tx packet detected and dropped, LVMMC:0x%08x\n",
lvmmc);
}
}
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
struct e1000_phy_info *phy = &hw->phy;
struct net_device *netdev = adapter->netdev;
u32 link;
int i;
u32 connsw;
u16 phy_data, retry_count = 20;
link = igb_has_link(adapter);
if (adapter->flags & IGB_FLAG_NEED_LINK_UPDATE) {
if (time_after(jiffies, (adapter->link_check_timeout + HZ)))
adapter->flags &= ~IGB_FLAG_NEED_LINK_UPDATE;
else
link = false;
}
if (adapter->flags & IGB_FLAG_MAS_ENABLE) {
if (hw->phy.media_type == e1000_media_type_copper) {
connsw = rd32(E1000_CONNSW);
if (!(connsw & E1000_CONNSW_AUTOSENSE_EN))
link = 0;
}
}
if (link) {
if (hw->dev_spec._82575.media_changed) {
hw->dev_spec._82575.media_changed = false;
adapter->flags |= IGB_FLAG_MEDIA_RESET;
igb_reset(adapter);
}
pm_runtime_resume(netdev->dev.parent);
if (!netif_carrier_ok(netdev)) {
u32 ctrl;
hw->mac.ops.get_speed_and_duplex(hw,
&adapter->link_speed,
&adapter->link_duplex);
ctrl = rd32(E1000_CTRL);
netdev_info(netdev,
"igb: %s NIC Link is Up %d Mbps %s Duplex, Flow Control: %s\n",
netdev->name,
adapter->link_speed,
adapter->link_duplex == FULL_DUPLEX ?
"Full" : "Half",
(ctrl & E1000_CTRL_TFCE) &&
(ctrl & E1000_CTRL_RFCE) ? "RX/TX" :
(ctrl & E1000_CTRL_RFCE) ? "RX" :
(ctrl & E1000_CTRL_TFCE) ? "TX" : "None");
if ((adapter->flags & IGB_FLAG_EEE) &&
(adapter->link_duplex == HALF_DUPLEX)) {
dev_info(&adapter->pdev->dev,
"EEE Disabled: unsupported at half duplex. Re-enable using ethtool when at full duplex.\n");
adapter->hw.dev_spec._82575.eee_disable = true;
adapter->flags &= ~IGB_FLAG_EEE;
}
igb_check_downshift(hw);
if (phy->speed_downgraded)
netdev_warn(netdev, "Link Speed was downgraded by SmartSpeed\n");
if (igb_thermal_sensor_event(hw,
E1000_THSTAT_LINK_THROTTLE))
netdev_info(netdev, "The network adapter link speed was downshifted because it overheated\n");
adapter->tx_timeout_factor = 1;
switch (adapter->link_speed) {
case SPEED_10:
adapter->tx_timeout_factor = 14;
break;
case SPEED_100:
break;
}
if (adapter->link_speed != SPEED_1000)
goto no_wait;
retry_read_status:
if (!igb_read_phy_reg(hw, PHY_1000T_STATUS,
&phy_data)) {
if (!(phy_data & SR_1000T_REMOTE_RX_STATUS) &&
retry_count) {
msleep(100);
retry_count--;
goto retry_read_status;
} else if (!retry_count) {
dev_err(&adapter->pdev->dev, "exceed max 2 second\n");
}
} else {
dev_err(&adapter->pdev->dev, "read 1000Base-T Status Reg\n");
}
no_wait:
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
if (igb_thermal_sensor_event(hw,
E1000_THSTAT_PWR_DOWN)) {
netdev_err(netdev, "The network adapter was stopped because it overheated\n");
}
netdev_info(netdev, "igb: %s NIC Link is Down\n",
netdev->name);
netif_carrier_off(netdev);
igb_ping_all_vfs(adapter);
if (!test_bit(__IGB_DOWN, &adapter->state))
mod_timer(&adapter->phy_info_timer,
round_jiffies(jiffies + 2 * HZ));
if (adapter->flags & IGB_FLAG_MAS_ENABLE) {
igb_check_swap_media(adapter);
if (adapter->flags & IGB_FLAG_MEDIA_RESET) {
schedule_work(&adapter->reset_task);
return;
}
}
pm_schedule_suspend(netdev->dev.parent,
MSEC_PER_SEC * 5);
} else if (!netif_carrier_ok(netdev) &&
(adapter->flags & IGB_FLAG_MAS_ENABLE)) {
igb_check_swap_media(adapter);
if (adapter->flags & IGB_FLAG_MEDIA_RESET) {
schedule_work(&adapter->reset_task);
return;
}
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
set_bit(IGB_RING_FLAG_TX_DETECT_HANG, &tx_ring->flags);
}
if (adapter->flags & IGB_FLAG_HAS_MSIX) {
u32 eics = 0;
for (i = 0; i < adapter->num_q_vectors; i++)
eics |= adapter->q_vector[i]->eims_value;
wr32(E1000_EICS, eics);
} else {
wr32(E1000_ICS, E1000_ICS_RXDMT0);
}
igb_spoof_check(adapter);
igb_ptp_rx_hang(adapter);
if ((adapter->hw.mac.type == e1000_i350) ||
(adapter->hw.mac.type == e1000_i354))
igb_check_lvmmc(adapter);
if (!test_bit(__IGB_DOWN, &adapter->state)) {
if (adapter->flags & IGB_FLAG_NEED_LINK_UPDATE)
mod_timer(&adapter->watchdog_timer,
round_jiffies(jiffies + HZ));
else
mod_timer(&adapter->watchdog_timer,
round_jiffies(jiffies + 2 * HZ));
}
}
static void igb_update_ring_itr(struct igb_q_vector *q_vector)
{
int new_val = q_vector->itr_val;
int avg_wire_size = 0;
struct igb_adapter *adapter = q_vector->adapter;
unsigned int packets;
if (adapter->link_speed != SPEED_1000) {
new_val = IGB_4K_ITR;
goto set_itr_val;
}
packets = q_vector->rx.total_packets;
if (packets)
avg_wire_size = q_vector->rx.total_bytes / packets;
packets = q_vector->tx.total_packets;
if (packets)
avg_wire_size = max_t(u32, avg_wire_size,
q_vector->tx.total_bytes / packets);
if (!avg_wire_size)
goto clear_counts;
avg_wire_size += 24;
avg_wire_size = min(avg_wire_size, 3000);
if ((avg_wire_size > 300) && (avg_wire_size < 1200))
new_val = avg_wire_size / 3;
else
new_val = avg_wire_size / 2;
if (new_val < IGB_20K_ITR &&
((q_vector->rx.ring && adapter->rx_itr_setting == 3) ||
(!q_vector->rx.ring && adapter->tx_itr_setting == 3)))
new_val = IGB_20K_ITR;
set_itr_val:
if (new_val != q_vector->itr_val) {
q_vector->itr_val = new_val;
q_vector->set_itr = 1;
}
clear_counts:
q_vector->rx.total_bytes = 0;
q_vector->rx.total_packets = 0;
q_vector->tx.total_bytes = 0;
q_vector->tx.total_packets = 0;
}
static void igb_update_itr(struct igb_q_vector *q_vector,
struct igb_ring_container *ring_container)
{
unsigned int packets = ring_container->total_packets;
unsigned int bytes = ring_container->total_bytes;
u8 itrval = ring_container->itr;
if (packets == 0)
return;
switch (itrval) {
case lowest_latency:
if (bytes/packets > 8000)
itrval = bulk_latency;
else if ((packets < 5) && (bytes > 512))
itrval = low_latency;
break;
case low_latency:
if (bytes > 10000) {
if (bytes/packets > 8000)
itrval = bulk_latency;
else if ((packets < 10) || ((bytes/packets) > 1200))
itrval = bulk_latency;
else if ((packets > 35))
itrval = lowest_latency;
} else if (bytes/packets > 2000) {
itrval = bulk_latency;
} else if (packets <= 2 && bytes < 512) {
itrval = lowest_latency;
}
break;
case bulk_latency:
if (bytes > 25000) {
if (packets > 35)
itrval = low_latency;
} else if (bytes < 1500) {
itrval = low_latency;
}
break;
}
ring_container->total_bytes = 0;
ring_container->total_packets = 0;
ring_container->itr = itrval;
}
static void igb_set_itr(struct igb_q_vector *q_vector)
{
struct igb_adapter *adapter = q_vector->adapter;
u32 new_itr = q_vector->itr_val;
u8 current_itr = 0;
if (adapter->link_speed != SPEED_1000) {
current_itr = 0;
new_itr = IGB_4K_ITR;
goto set_itr_now;
}
igb_update_itr(q_vector, &q_vector->tx);
igb_update_itr(q_vector, &q_vector->rx);
current_itr = max(q_vector->rx.itr, q_vector->tx.itr);
if (current_itr == lowest_latency &&
((q_vector->rx.ring && adapter->rx_itr_setting == 3) ||
(!q_vector->rx.ring && adapter->tx_itr_setting == 3)))
current_itr = low_latency;
switch (current_itr) {
case lowest_latency:
new_itr = IGB_70K_ITR;
break;
case low_latency:
new_itr = IGB_20K_ITR;
break;
case bulk_latency:
new_itr = IGB_4K_ITR;
break;
default:
break;
}
set_itr_now:
if (new_itr != q_vector->itr_val) {
new_itr = new_itr > q_vector->itr_val ?
max((new_itr * q_vector->itr_val) /
(new_itr + (q_vector->itr_val >> 2)),
new_itr) : new_itr;
q_vector->itr_val = new_itr;
q_vector->set_itr = 1;
}
}
static void igb_tx_ctxtdesc(struct igb_ring *tx_ring, u32 vlan_macip_lens,
u32 type_tucmd, u32 mss_l4len_idx)
{
struct e1000_adv_tx_context_desc *context_desc;
u16 i = tx_ring->next_to_use;
context_desc = IGB_TX_CTXTDESC(tx_ring, i);
i++;
tx_ring->next_to_use = (i < tx_ring->count) ? i : 0;
type_tucmd |= E1000_TXD_CMD_DEXT | E1000_ADVTXD_DTYP_CTXT;
if (test_bit(IGB_RING_FLAG_TX_CTX_IDX, &tx_ring->flags))
mss_l4len_idx |= tx_ring->reg_idx << 4;
context_desc->vlan_macip_lens = cpu_to_le32(vlan_macip_lens);
context_desc->seqnum_seed = 0;
context_desc->type_tucmd_mlhl = cpu_to_le32(type_tucmd);
context_desc->mss_l4len_idx = cpu_to_le32(mss_l4len_idx);
}
static int igb_tso(struct igb_ring *tx_ring,
struct igb_tx_buffer *first,
u8 *hdr_len)
{
u32 vlan_macip_lens, type_tucmd, mss_l4len_idx;
struct sk_buff *skb = first->skb;
union {
struct iphdr *v4;
struct ipv6hdr *v6;
unsigned char *hdr;
} ip;
union {
struct tcphdr *tcp;
unsigned char *hdr;
} l4;
u32 paylen, l4_offset;
int err;
if (skb->ip_summed != CHECKSUM_PARTIAL)
return 0;
if (!skb_is_gso(skb))
return 0;
err = skb_cow_head(skb, 0);
if (err < 0)
return err;
ip.hdr = skb_network_header(skb);
l4.hdr = skb_checksum_start(skb);
type_tucmd = E1000_ADVTXD_TUCMD_L4T_TCP;
if (ip.v4->version == 4) {
ip.v4->check = csum_fold(csum_add(lco_csum(skb),
csum_unfold(l4.tcp->check)));
type_tucmd |= E1000_ADVTXD_TUCMD_IPV4;
ip.v4->tot_len = 0;
first->tx_flags |= IGB_TX_FLAGS_TSO |
IGB_TX_FLAGS_CSUM |
IGB_TX_FLAGS_IPV4;
} else {
ip.v6->payload_len = 0;
first->tx_flags |= IGB_TX_FLAGS_TSO |
IGB_TX_FLAGS_CSUM;
}
l4_offset = l4.hdr - skb->data;
*hdr_len = (l4.tcp->doff * 4) + l4_offset;
paylen = skb->len - l4_offset;
csum_replace_by_diff(&l4.tcp->check, htonl(paylen));
first->gso_segs = skb_shinfo(skb)->gso_segs;
first->bytecount += (first->gso_segs - 1) * *hdr_len;
mss_l4len_idx = (*hdr_len - l4_offset) << E1000_ADVTXD_L4LEN_SHIFT;
mss_l4len_idx |= skb_shinfo(skb)->gso_size << E1000_ADVTXD_MSS_SHIFT;
vlan_macip_lens = l4.hdr - ip.hdr;
vlan_macip_lens |= (ip.hdr - skb->data) << E1000_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= first->tx_flags & IGB_TX_FLAGS_VLAN_MASK;
igb_tx_ctxtdesc(tx_ring, vlan_macip_lens, type_tucmd, mss_l4len_idx);
return 1;
}
static inline bool igb_ipv6_csum_is_sctp(struct sk_buff *skb)
{
unsigned int offset = 0;
ipv6_find_hdr(skb, &offset, IPPROTO_SCTP, NULL, NULL);
return offset == skb_checksum_start_offset(skb);
}
static void igb_tx_csum(struct igb_ring *tx_ring, struct igb_tx_buffer *first)
{
struct sk_buff *skb = first->skb;
u32 vlan_macip_lens = 0;
u32 type_tucmd = 0;
if (skb->ip_summed != CHECKSUM_PARTIAL) {
csum_failed:
if (!(first->tx_flags & IGB_TX_FLAGS_VLAN))
return;
goto no_csum;
}
switch (skb->csum_offset) {
case offsetof(struct tcphdr, check):
type_tucmd = E1000_ADVTXD_TUCMD_L4T_TCP;
case offsetof(struct udphdr, check):
break;
case offsetof(struct sctphdr, checksum):
if (((first->protocol == htons(ETH_P_IP)) &&
(ip_hdr(skb)->protocol == IPPROTO_SCTP)) ||
((first->protocol == htons(ETH_P_IPV6)) &&
igb_ipv6_csum_is_sctp(skb))) {
type_tucmd = E1000_ADVTXD_TUCMD_L4T_SCTP;
break;
}
default:
skb_checksum_help(skb);
goto csum_failed;
}
first->tx_flags |= IGB_TX_FLAGS_CSUM;
vlan_macip_lens = skb_checksum_start_offset(skb) -
skb_network_offset(skb);
no_csum:
vlan_macip_lens |= skb_network_offset(skb) << E1000_ADVTXD_MACLEN_SHIFT;
vlan_macip_lens |= first->tx_flags & IGB_TX_FLAGS_VLAN_MASK;
igb_tx_ctxtdesc(tx_ring, vlan_macip_lens, type_tucmd, 0);
}
static u32 igb_tx_cmd_type(struct sk_buff *skb, u32 tx_flags)
{
u32 cmd_type = E1000_ADVTXD_DTYP_DATA |
E1000_ADVTXD_DCMD_DEXT |
E1000_ADVTXD_DCMD_IFCS;
cmd_type |= IGB_SET_FLAG(tx_flags, IGB_TX_FLAGS_VLAN,
(E1000_ADVTXD_DCMD_VLE));
cmd_type |= IGB_SET_FLAG(tx_flags, IGB_TX_FLAGS_TSO,
(E1000_ADVTXD_DCMD_TSE));
cmd_type |= IGB_SET_FLAG(tx_flags, IGB_TX_FLAGS_TSTAMP,
(E1000_ADVTXD_MAC_TSTAMP));
cmd_type ^= IGB_SET_FLAG(skb->no_fcs, 1, E1000_ADVTXD_DCMD_IFCS);
return cmd_type;
}
static void igb_tx_olinfo_status(struct igb_ring *tx_ring,
union e1000_adv_tx_desc *tx_desc,
u32 tx_flags, unsigned int paylen)
{
u32 olinfo_status = paylen << E1000_ADVTXD_PAYLEN_SHIFT;
if (test_bit(IGB_RING_FLAG_TX_CTX_IDX, &tx_ring->flags))
olinfo_status |= tx_ring->reg_idx << 4;
olinfo_status |= IGB_SET_FLAG(tx_flags,
IGB_TX_FLAGS_CSUM,
(E1000_TXD_POPTS_TXSM << 8));
olinfo_status |= IGB_SET_FLAG(tx_flags,
IGB_TX_FLAGS_IPV4,
(E1000_TXD_POPTS_IXSM << 8));
tx_desc->read.olinfo_status = cpu_to_le32(olinfo_status);
}
static int __igb_maybe_stop_tx(struct igb_ring *tx_ring, const u16 size)
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
static inline int igb_maybe_stop_tx(struct igb_ring *tx_ring, const u16 size)
{
if (igb_desc_unused(tx_ring) >= size)
return 0;
return __igb_maybe_stop_tx(tx_ring, size);
}
static void igb_tx_map(struct igb_ring *tx_ring,
struct igb_tx_buffer *first,
const u8 hdr_len)
{
struct sk_buff *skb = first->skb;
struct igb_tx_buffer *tx_buffer;
union e1000_adv_tx_desc *tx_desc;
struct skb_frag_struct *frag;
dma_addr_t dma;
unsigned int data_len, size;
u32 tx_flags = first->tx_flags;
u32 cmd_type = igb_tx_cmd_type(skb, tx_flags);
u16 i = tx_ring->next_to_use;
tx_desc = IGB_TX_DESC(tx_ring, i);
igb_tx_olinfo_status(tx_ring, tx_desc, tx_flags, skb->len - hdr_len);
size = skb_headlen(skb);
data_len = skb->data_len;
dma = dma_map_single(tx_ring->dev, skb->data, size, DMA_TO_DEVICE);
tx_buffer = first;
for (frag = &skb_shinfo(skb)->frags[0];; frag++) {
if (dma_mapping_error(tx_ring->dev, dma))
goto dma_error;
dma_unmap_len_set(tx_buffer, len, size);
dma_unmap_addr_set(tx_buffer, dma, dma);
tx_desc->read.buffer_addr = cpu_to_le64(dma);
while (unlikely(size > IGB_MAX_DATA_PER_TXD)) {
tx_desc->read.cmd_type_len =
cpu_to_le32(cmd_type ^ IGB_MAX_DATA_PER_TXD);
i++;
tx_desc++;
if (i == tx_ring->count) {
tx_desc = IGB_TX_DESC(tx_ring, 0);
i = 0;
}
tx_desc->read.olinfo_status = 0;
dma += IGB_MAX_DATA_PER_TXD;
size -= IGB_MAX_DATA_PER_TXD;
tx_desc->read.buffer_addr = cpu_to_le64(dma);
}
if (likely(!data_len))
break;
tx_desc->read.cmd_type_len = cpu_to_le32(cmd_type ^ size);
i++;
tx_desc++;
if (i == tx_ring->count) {
tx_desc = IGB_TX_DESC(tx_ring, 0);
i = 0;
}
tx_desc->read.olinfo_status = 0;
size = skb_frag_size(frag);
data_len -= size;
dma = skb_frag_dma_map(tx_ring->dev, frag, 0,
size, DMA_TO_DEVICE);
tx_buffer = &tx_ring->tx_buffer_info[i];
}
cmd_type |= size | IGB_TXD_DCMD;
tx_desc->read.cmd_type_len = cpu_to_le32(cmd_type);
netdev_tx_sent_queue(txring_txq(tx_ring), first->bytecount);
first->time_stamp = jiffies;
wmb();
first->next_to_watch = tx_desc;
i++;
if (i == tx_ring->count)
i = 0;
tx_ring->next_to_use = i;
igb_maybe_stop_tx(tx_ring, DESC_NEEDED);
if (netif_xmit_stopped(txring_txq(tx_ring)) || !skb->xmit_more) {
writel(i, tx_ring->tail);
mmiowb();
}
return;
dma_error:
dev_err(tx_ring->dev, "TX DMA map failed\n");
for (;;) {
tx_buffer = &tx_ring->tx_buffer_info[i];
igb_unmap_and_free_tx_resource(tx_ring, tx_buffer);
if (tx_buffer == first)
break;
if (i == 0)
i = tx_ring->count;
i--;
}
tx_ring->next_to_use = i;
}
netdev_tx_t igb_xmit_frame_ring(struct sk_buff *skb,
struct igb_ring *tx_ring)
{
struct igb_tx_buffer *first;
int tso;
u32 tx_flags = 0;
unsigned short f;
u16 count = TXD_USE_COUNT(skb_headlen(skb));
__be16 protocol = vlan_get_protocol(skb);
u8 hdr_len = 0;
for (f = 0; f < skb_shinfo(skb)->nr_frags; f++)
count += TXD_USE_COUNT(skb_shinfo(skb)->frags[f].size);
if (igb_maybe_stop_tx(tx_ring, count + 3)) {
return NETDEV_TX_BUSY;
}
first = &tx_ring->tx_buffer_info[tx_ring->next_to_use];
first->skb = skb;
first->bytecount = skb->len;
first->gso_segs = 1;
if (unlikely(skb_shinfo(skb)->tx_flags & SKBTX_HW_TSTAMP)) {
struct igb_adapter *adapter = netdev_priv(tx_ring->netdev);
if (!test_and_set_bit_lock(__IGB_PTP_TX_IN_PROGRESS,
&adapter->state)) {
skb_shinfo(skb)->tx_flags |= SKBTX_IN_PROGRESS;
tx_flags |= IGB_TX_FLAGS_TSTAMP;
adapter->ptp_tx_skb = skb_get(skb);
adapter->ptp_tx_start = jiffies;
if (adapter->hw.mac.type == e1000_82576)
schedule_work(&adapter->ptp_tx_work);
}
}
skb_tx_timestamp(skb);
if (skb_vlan_tag_present(skb)) {
tx_flags |= IGB_TX_FLAGS_VLAN;
tx_flags |= (skb_vlan_tag_get(skb) << IGB_TX_FLAGS_VLAN_SHIFT);
}
first->tx_flags = tx_flags;
first->protocol = protocol;
tso = igb_tso(tx_ring, first, &hdr_len);
if (tso < 0)
goto out_drop;
else if (!tso)
igb_tx_csum(tx_ring, first);
igb_tx_map(tx_ring, first, hdr_len);
return NETDEV_TX_OK;
out_drop:
igb_unmap_and_free_tx_resource(tx_ring, first);
return NETDEV_TX_OK;
}
static inline struct igb_ring *igb_tx_queue_mapping(struct igb_adapter *adapter,
struct sk_buff *skb)
{
unsigned int r_idx = skb->queue_mapping;
if (r_idx >= adapter->num_tx_queues)
r_idx = r_idx % adapter->num_tx_queues;
return adapter->tx_ring[r_idx];
}
static netdev_tx_t igb_xmit_frame(struct sk_buff *skb,
struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
if (skb_put_padto(skb, 17))
return NETDEV_TX_OK;
return igb_xmit_frame_ring(skb, igb_tx_queue_mapping(adapter, skb));
}
static void igb_tx_timeout(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
adapter->tx_timeout_count++;
if (hw->mac.type >= e1000_82580)
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
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN + VLAN_HLEN;
if ((new_mtu < 68) || (max_frame > MAX_JUMBO_FRAME_SIZE)) {
dev_err(&pdev->dev, "Invalid MTU setting\n");
return -EINVAL;
}
#define MAX_STD_JUMBO_FRAME_SIZE 9238
if (max_frame > MAX_STD_JUMBO_FRAME_SIZE) {
dev_err(&pdev->dev, "MTU > 9216 not supported.\n");
return -EINVAL;
}
if (max_frame < (ETH_FRAME_LEN + ETH_FCS_LEN))
max_frame = ETH_FRAME_LEN + ETH_FCS_LEN;
while (test_and_set_bit(__IGB_RESETTING, &adapter->state))
usleep_range(1000, 2000);
adapter->max_frame_size = max_frame;
if (netif_running(netdev))
igb_down(adapter);
dev_info(&pdev->dev, "changing MTU from %d to %d\n",
netdev->mtu, new_mtu);
netdev->mtu = new_mtu;
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
int i;
u64 bytes, packets;
unsigned int start;
u64 _bytes, _packets;
if (adapter->link_speed == 0)
return;
if (pci_channel_offline(pdev))
return;
bytes = 0;
packets = 0;
rcu_read_lock();
for (i = 0; i < adapter->num_rx_queues; i++) {
struct igb_ring *ring = adapter->rx_ring[i];
u32 rqdpc = rd32(E1000_RQDPC(i));
if (hw->mac.type >= e1000_i210)
wr32(E1000_RQDPC(i), 0);
if (rqdpc) {
ring->rx_stats.drops += rqdpc;
net_stats->rx_fifo_errors += rqdpc;
}
do {
start = u64_stats_fetch_begin_irq(&ring->rx_syncp);
_bytes = ring->rx_stats.bytes;
_packets = ring->rx_stats.packets;
} while (u64_stats_fetch_retry_irq(&ring->rx_syncp, start));
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
start = u64_stats_fetch_begin_irq(&ring->tx_syncp);
_bytes = ring->tx_stats.bytes;
_packets = ring->tx_stats.packets;
} while (u64_stats_fetch_retry_irq(&ring->tx_syncp, start));
bytes += _bytes;
packets += _packets;
}
net_stats->tx_bytes = bytes;
net_stats->tx_packets = packets;
rcu_read_unlock();
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
if ((hw->mac.type != e1000_i210) &&
(hw->mac.type != e1000_i211))
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
static void igb_tsync_interrupt(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
struct ptp_clock_event event;
struct timespec64 ts;
u32 ack = 0, tsauxc, sec, nsec, tsicr = rd32(E1000_TSICR);
if (tsicr & TSINTR_SYS_WRAP) {
event.type = PTP_CLOCK_PPS;
if (adapter->ptp_caps.pps)
ptp_clock_event(adapter->ptp_clock, &event);
else
dev_err(&adapter->pdev->dev, "unexpected SYS WRAP");
ack |= TSINTR_SYS_WRAP;
}
if (tsicr & E1000_TSICR_TXTS) {
schedule_work(&adapter->ptp_tx_work);
ack |= E1000_TSICR_TXTS;
}
if (tsicr & TSINTR_TT0) {
spin_lock(&adapter->tmreg_lock);
ts = timespec64_add(adapter->perout[0].start,
adapter->perout[0].period);
wr32(E1000_TRGTTIML0, ts.tv_nsec);
wr32(E1000_TRGTTIMH0, (u32)ts.tv_sec);
tsauxc = rd32(E1000_TSAUXC);
tsauxc |= TSAUXC_EN_TT0;
wr32(E1000_TSAUXC, tsauxc);
adapter->perout[0].start = ts;
spin_unlock(&adapter->tmreg_lock);
ack |= TSINTR_TT0;
}
if (tsicr & TSINTR_TT1) {
spin_lock(&adapter->tmreg_lock);
ts = timespec64_add(adapter->perout[1].start,
adapter->perout[1].period);
wr32(E1000_TRGTTIML1, ts.tv_nsec);
wr32(E1000_TRGTTIMH1, (u32)ts.tv_sec);
tsauxc = rd32(E1000_TSAUXC);
tsauxc |= TSAUXC_EN_TT1;
wr32(E1000_TSAUXC, tsauxc);
adapter->perout[1].start = ts;
spin_unlock(&adapter->tmreg_lock);
ack |= TSINTR_TT1;
}
if (tsicr & TSINTR_AUTT0) {
nsec = rd32(E1000_AUXSTMPL0);
sec = rd32(E1000_AUXSTMPH0);
event.type = PTP_CLOCK_EXTTS;
event.index = 0;
event.timestamp = sec * 1000000000ULL + nsec;
ptp_clock_event(adapter->ptp_clock, &event);
ack |= TSINTR_AUTT0;
}
if (tsicr & TSINTR_AUTT1) {
nsec = rd32(E1000_AUXSTMPL1);
sec = rd32(E1000_AUXSTMPH1);
event.type = PTP_CLOCK_EXTTS;
event.index = 1;
event.timestamp = sec * 1000000000ULL + nsec;
ptp_clock_event(adapter->ptp_clock, &event);
ack |= TSINTR_AUTT1;
}
wr32(E1000_TSICR, ack);
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
if (icr & E1000_ICR_TS)
igb_tsync_interrupt(adapter);
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
itr_val |= E1000_EITR_CNT_IGNR;
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
static void igb_update_tx_dca(struct igb_adapter *adapter,
struct igb_ring *tx_ring,
int cpu)
{
struct e1000_hw *hw = &adapter->hw;
u32 txctrl = dca3_get_tag(tx_ring->dev, cpu);
if (hw->mac.type != e1000_82575)
txctrl <<= E1000_DCA_TXCTRL_CPUID_SHIFT;
txctrl |= E1000_DCA_TXCTRL_DESC_RRO_EN |
E1000_DCA_TXCTRL_DATA_RRO_EN |
E1000_DCA_TXCTRL_DESC_DCA_EN;
wr32(E1000_DCA_TXCTRL(tx_ring->reg_idx), txctrl);
}
static void igb_update_rx_dca(struct igb_adapter *adapter,
struct igb_ring *rx_ring,
int cpu)
{
struct e1000_hw *hw = &adapter->hw;
u32 rxctrl = dca3_get_tag(&adapter->pdev->dev, cpu);
if (hw->mac.type != e1000_82575)
rxctrl <<= E1000_DCA_RXCTRL_CPUID_SHIFT;
rxctrl |= E1000_DCA_RXCTRL_DESC_RRO_EN |
E1000_DCA_RXCTRL_DESC_DCA_EN;
wr32(E1000_DCA_RXCTRL(rx_ring->reg_idx), rxctrl);
}
static void igb_update_dca(struct igb_q_vector *q_vector)
{
struct igb_adapter *adapter = q_vector->adapter;
int cpu = get_cpu();
if (q_vector->cpu == cpu)
goto out_no_update;
if (q_vector->tx.ring)
igb_update_tx_dca(adapter, q_vector->tx.ring, cpu);
if (q_vector->rx.ring)
igb_update_rx_dca(adapter, q_vector->rx.ring, cpu);
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
static int igb_vf_configure(struct igb_adapter *adapter, int vf)
{
unsigned char mac_addr[ETH_ALEN];
eth_zero_addr(mac_addr);
igb_set_vf_mac(adapter, vf, mac_addr);
adapter->vf_data[vf].spoofchk_enabled = true;
return 0;
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
u32 pool_mask, vlvf_mask, i;
pool_mask = E1000_VLVF_POOLSEL_MASK;
vlvf_mask = BIT(E1000_VLVF_POOLSEL_SHIFT + vf);
pool_mask &= ~BIT(E1000_VLVF_POOLSEL_SHIFT +
adapter->vfs_allocated_count);
for (i = E1000_VLVF_ARRAY_SIZE; i--;) {
u32 vlvf = rd32(E1000_VLVF(i));
u32 vfta_mask, vid, vfta;
if (!(vlvf & vlvf_mask))
continue;
vlvf ^= vlvf_mask;
if (vlvf & pool_mask)
goto update_vlvfb;
if (vlvf & E1000_VLVF_POOLSEL_MASK)
goto update_vlvf;
vid = vlvf & E1000_VLVF_VLANID_MASK;
vfta_mask = BIT(vid % 32);
vfta = adapter->shadow_vfta[vid / 32];
if (vfta & vfta_mask)
hw->mac.ops.write_vfta(hw, vid / 32, vfta ^ vfta_mask);
update_vlvf:
if (adapter->flags & IGB_FLAG_VLAN_PROMISC)
vlvf &= E1000_VLVF_POOLSEL_MASK;
else
vlvf = 0;
update_vlvfb:
wr32(E1000_VLVF(i), vlvf);
}
}
static int igb_find_vlvf_entry(struct e1000_hw *hw, u32 vlan)
{
u32 vlvf;
int idx;
if (vlan == 0)
return 0;
for (idx = E1000_VLVF_ARRAY_SIZE; --idx;) {
vlvf = rd32(E1000_VLVF(idx));
if ((vlvf & VLAN_VID_MASK) == vlan)
break;
}
return idx;
}
static void igb_update_pf_vlvf(struct igb_adapter *adapter, u32 vid)
{
struct e1000_hw *hw = &adapter->hw;
u32 bits, pf_id;
int idx;
idx = igb_find_vlvf_entry(hw, vid);
if (!idx)
return;
pf_id = adapter->vfs_allocated_count + E1000_VLVF_POOLSEL_SHIFT;
bits = ~BIT(pf_id) & E1000_VLVF_POOLSEL_MASK;
bits &= rd32(E1000_VLVF(idx));
if (!bits) {
if (adapter->flags & IGB_FLAG_VLAN_PROMISC)
wr32(E1000_VLVF(idx), BIT(pf_id));
else
wr32(E1000_VLVF(idx), 0);
}
}
static s32 igb_set_vf_vlan(struct igb_adapter *adapter, u32 vid,
bool add, u32 vf)
{
int pf_id = adapter->vfs_allocated_count;
struct e1000_hw *hw = &adapter->hw;
int err;
if (add && test_bit(vid, adapter->active_vlans)) {
err = igb_vfta_set(hw, vid, pf_id, true, false);
if (err)
return err;
}
err = igb_vfta_set(hw, vid, vf, add, false);
if (add && !err)
return err;
if (test_bit(vid, adapter->active_vlans) ||
(adapter->flags & IGB_FLAG_VLAN_PROMISC))
igb_update_pf_vlvf(adapter, vid);
return err;
}
static void igb_set_vmvir(struct igb_adapter *adapter, u32 vid, u32 vf)
{
struct e1000_hw *hw = &adapter->hw;
if (vid)
wr32(E1000_VMVIR(vf), (vid | E1000_VMVIR_VLANA_DEFAULT));
else
wr32(E1000_VMVIR(vf), 0);
}
static int igb_enable_port_vlan(struct igb_adapter *adapter, int vf,
u16 vlan, u8 qos)
{
int err;
err = igb_set_vf_vlan(adapter, vlan, true, vf);
if (err)
return err;
igb_set_vmvir(adapter, vlan | (qos << VLAN_PRIO_SHIFT), vf);
igb_set_vmolr(adapter, vf, !vlan);
if (vlan != adapter->vf_data[vf].pf_vlan)
igb_set_vf_vlan(adapter, adapter->vf_data[vf].pf_vlan,
false, vf);
adapter->vf_data[vf].pf_vlan = vlan;
adapter->vf_data[vf].pf_qos = qos;
igb_set_vf_vlan_strip(adapter, vf, true);
dev_info(&adapter->pdev->dev,
"Setting VLAN %d, QOS 0x%x on VF %d\n", vlan, qos, vf);
if (test_bit(__IGB_DOWN, &adapter->state)) {
dev_warn(&adapter->pdev->dev,
"The VF VLAN has been set, but the PF device is not up.\n");
dev_warn(&adapter->pdev->dev,
"Bring the PF device up before attempting to use the VF device.\n");
}
return err;
}
static int igb_disable_port_vlan(struct igb_adapter *adapter, int vf)
{
igb_set_vf_vlan(adapter, 0, true, vf);
igb_set_vmvir(adapter, 0, vf);
igb_set_vmolr(adapter, vf, true);
if (adapter->vf_data[vf].pf_vlan)
igb_set_vf_vlan(adapter, adapter->vf_data[vf].pf_vlan,
false, vf);
adapter->vf_data[vf].pf_vlan = 0;
adapter->vf_data[vf].pf_qos = 0;
igb_set_vf_vlan_strip(adapter, vf, false);
return 0;
}
static int igb_ndo_set_vf_vlan(struct net_device *netdev,
int vf, u16 vlan, u8 qos)
{
struct igb_adapter *adapter = netdev_priv(netdev);
if ((vf >= adapter->vfs_allocated_count) || (vlan > 4095) || (qos > 7))
return -EINVAL;
return (vlan || qos) ? igb_enable_port_vlan(adapter, vf, vlan, qos) :
igb_disable_port_vlan(adapter, vf);
}
static int igb_set_vf_vlan_msg(struct igb_adapter *adapter, u32 *msgbuf, u32 vf)
{
int add = (msgbuf[0] & E1000_VT_MSGINFO_MASK) >> E1000_VT_MSGINFO_SHIFT;
int vid = (msgbuf[1] & E1000_VLVF_VLANID_MASK);
int ret;
if (adapter->vf_data[vf].pf_vlan)
return -1;
if (!vid && !add)
return 0;
ret = igb_set_vf_vlan(adapter, vid, !!add, vf);
if (!ret)
igb_set_vf_vlan_strip(adapter, vf, !!vid);
return ret;
}
static inline void igb_vf_reset(struct igb_adapter *adapter, u32 vf)
{
struct vf_data_storage *vf_data = &adapter->vf_data[vf];
vf_data->flags &= IGB_VF_FLAG_PF_SET_MAC;
vf_data->last_nack = jiffies;
igb_clear_vf_vfta(adapter, vf);
igb_set_vf_vlan(adapter, vf_data->pf_vlan, true, vf);
igb_set_vmvir(adapter, vf_data->pf_vlan |
(vf_data->pf_qos << VLAN_PRIO_SHIFT), vf);
igb_set_vmolr(adapter, vf, !vf_data->pf_vlan);
igb_set_vf_vlan_strip(adapter, vf, !!(vf_data->pf_vlan));
adapter->vf_data[vf].num_vf_mc_hashes = 0;
igb_set_rx_mode(adapter->netdev);
}
static void igb_vf_reset_event(struct igb_adapter *adapter, u32 vf)
{
unsigned char *vf_mac = adapter->vf_data[vf].vf_mac_addresses;
if (!(adapter->vf_data[vf].flags & IGB_VF_FLAG_PF_SET_MAC))
eth_zero_addr(vf_mac);
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
wr32(E1000_VFTE, reg | BIT(vf));
reg = rd32(E1000_VFRE);
wr32(E1000_VFRE, reg | BIT(vf));
adapter->vf_data[vf].flags |= IGB_VF_FLAG_CTS;
if (!is_zero_ether_addr(vf_mac)) {
msgbuf[0] = E1000_VF_RESET | E1000_VT_MSGTYPE_ACK;
memcpy(addr, vf_mac, ETH_ALEN);
} else {
msgbuf[0] = E1000_VF_RESET | E1000_VT_MSGTYPE_NACK;
}
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
"VF %d attempted to override administratively set MAC address\nReload the VF driver to resume operations\n",
vf);
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
"VF %d attempted to override administratively set VLAN tag\nReload the VF driver to resume operations\n",
vf);
else
retval = igb_set_vf_vlan_msg(adapter, msgbuf, vf);
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
static void igb_set_uta(struct igb_adapter *adapter, bool set)
{
struct e1000_hw *hw = &adapter->hw;
u32 uta = set ? ~0 : 0;
int i;
if (!adapter->vfs_allocated_count)
return;
for (i = hw->mac.uta_reg_count; i--;)
array_wr32(E1000_UTA, i, uta);
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
if (icr & E1000_ICR_TS)
igb_tsync_interrupt(adapter);
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static irqreturn_t igb_intr(int irq, void *data)
{
struct igb_adapter *adapter = data;
struct igb_q_vector *q_vector = adapter->q_vector[0];
struct e1000_hw *hw = &adapter->hw;
u32 icr = rd32(E1000_ICR);
if (!(icr & E1000_ICR_INT_ASSERTED))
return IRQ_NONE;
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
if (icr & E1000_ICR_TS)
igb_tsync_interrupt(adapter);
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static void igb_ring_irq_enable(struct igb_q_vector *q_vector)
{
struct igb_adapter *adapter = q_vector->adapter;
struct e1000_hw *hw = &adapter->hw;
if ((q_vector->rx.ring && (adapter->rx_itr_setting & 3)) ||
(!q_vector->rx.ring && (adapter->tx_itr_setting & 3))) {
if ((adapter->num_q_vectors == 1) && !adapter->vf_data)
igb_set_itr(q_vector);
else
igb_update_ring_itr(q_vector);
}
if (!test_bit(__IGB_DOWN, &adapter->state)) {
if (adapter->flags & IGB_FLAG_HAS_MSIX)
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
bool clean_complete = true;
int work_done = 0;
#ifdef CONFIG_IGB_DCA
if (q_vector->adapter->flags & IGB_FLAG_DCA_ENABLED)
igb_update_dca(q_vector);
#endif
if (q_vector->tx.ring)
clean_complete = igb_clean_tx_irq(q_vector, budget);
if (q_vector->rx.ring) {
int cleaned = igb_clean_rx_irq(q_vector, budget);
work_done += cleaned;
if (cleaned >= budget)
clean_complete = false;
}
if (!clean_complete)
return budget;
napi_complete_done(napi, work_done);
igb_ring_irq_enable(q_vector);
return 0;
}
static bool igb_clean_tx_irq(struct igb_q_vector *q_vector, int napi_budget)
{
struct igb_adapter *adapter = q_vector->adapter;
struct igb_ring *tx_ring = q_vector->tx.ring;
struct igb_tx_buffer *tx_buffer;
union e1000_adv_tx_desc *tx_desc;
unsigned int total_bytes = 0, total_packets = 0;
unsigned int budget = q_vector->tx.work_limit;
unsigned int i = tx_ring->next_to_clean;
if (test_bit(__IGB_DOWN, &adapter->state))
return true;
tx_buffer = &tx_ring->tx_buffer_info[i];
tx_desc = IGB_TX_DESC(tx_ring, i);
i -= tx_ring->count;
do {
union e1000_adv_tx_desc *eop_desc = tx_buffer->next_to_watch;
if (!eop_desc)
break;
read_barrier_depends();
if (!(eop_desc->wb.status & cpu_to_le32(E1000_TXD_STAT_DD)))
break;
tx_buffer->next_to_watch = NULL;
total_bytes += tx_buffer->bytecount;
total_packets += tx_buffer->gso_segs;
napi_consume_skb(tx_buffer->skb, napi_budget);
dma_unmap_single(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
tx_buffer->skb = NULL;
dma_unmap_len_set(tx_buffer, len, 0);
while (tx_desc != eop_desc) {
tx_buffer++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buffer = tx_ring->tx_buffer_info;
tx_desc = IGB_TX_DESC(tx_ring, 0);
}
if (dma_unmap_len(tx_buffer, len)) {
dma_unmap_page(tx_ring->dev,
dma_unmap_addr(tx_buffer, dma),
dma_unmap_len(tx_buffer, len),
DMA_TO_DEVICE);
dma_unmap_len_set(tx_buffer, len, 0);
}
}
tx_buffer++;
tx_desc++;
i++;
if (unlikely(!i)) {
i -= tx_ring->count;
tx_buffer = tx_ring->tx_buffer_info;
tx_desc = IGB_TX_DESC(tx_ring, 0);
}
prefetch(tx_desc);
budget--;
} while (likely(budget));
netdev_tx_completed_queue(txring_txq(tx_ring),
total_packets, total_bytes);
i += tx_ring->count;
tx_ring->next_to_clean = i;
u64_stats_update_begin(&tx_ring->tx_syncp);
tx_ring->tx_stats.bytes += total_bytes;
tx_ring->tx_stats.packets += total_packets;
u64_stats_update_end(&tx_ring->tx_syncp);
q_vector->tx.total_bytes += total_bytes;
q_vector->tx.total_packets += total_packets;
if (test_bit(IGB_RING_FLAG_TX_DETECT_HANG, &tx_ring->flags)) {
struct e1000_hw *hw = &adapter->hw;
clear_bit(IGB_RING_FLAG_TX_DETECT_HANG, &tx_ring->flags);
if (tx_buffer->next_to_watch &&
time_after(jiffies, tx_buffer->time_stamp +
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
" next_to_watch <%p>\n"
" jiffies <%lx>\n"
" desc.status <%x>\n",
tx_ring->queue_index,
rd32(E1000_TDH(tx_ring->reg_idx)),
readl(tx_ring->tail),
tx_ring->next_to_use,
tx_ring->next_to_clean,
tx_buffer->time_stamp,
tx_buffer->next_to_watch,
jiffies,
tx_buffer->next_to_watch->wb.status);
netif_stop_subqueue(tx_ring->netdev,
tx_ring->queue_index);
return true;
}
}
#define TX_WAKE_THRESHOLD (DESC_NEEDED * 2)
if (unlikely(total_packets &&
netif_carrier_ok(tx_ring->netdev) &&
igb_desc_unused(tx_ring) >= TX_WAKE_THRESHOLD)) {
smp_mb();
if (__netif_subqueue_stopped(tx_ring->netdev,
tx_ring->queue_index) &&
!(test_bit(__IGB_DOWN, &adapter->state))) {
netif_wake_subqueue(tx_ring->netdev,
tx_ring->queue_index);
u64_stats_update_begin(&tx_ring->tx_syncp);
tx_ring->tx_stats.restart_queue++;
u64_stats_update_end(&tx_ring->tx_syncp);
}
}
return !!budget;
}
static void igb_reuse_rx_page(struct igb_ring *rx_ring,
struct igb_rx_buffer *old_buff)
{
struct igb_rx_buffer *new_buff;
u16 nta = rx_ring->next_to_alloc;
new_buff = &rx_ring->rx_buffer_info[nta];
nta++;
rx_ring->next_to_alloc = (nta < rx_ring->count) ? nta : 0;
*new_buff = *old_buff;
dma_sync_single_range_for_device(rx_ring->dev, old_buff->dma,
old_buff->page_offset,
IGB_RX_BUFSZ,
DMA_FROM_DEVICE);
}
static inline bool igb_page_is_reserved(struct page *page)
{
return (page_to_nid(page) != numa_mem_id()) || page_is_pfmemalloc(page);
}
static bool igb_can_reuse_rx_page(struct igb_rx_buffer *rx_buffer,
struct page *page,
unsigned int truesize)
{
if (unlikely(igb_page_is_reserved(page)))
return false;
#if (PAGE_SIZE < 8192)
if (unlikely(page_count(page) != 1))
return false;
rx_buffer->page_offset ^= IGB_RX_BUFSZ;
#else
rx_buffer->page_offset += truesize;
if (rx_buffer->page_offset > (PAGE_SIZE - IGB_RX_BUFSZ))
return false;
#endif
page_ref_inc(page);
return true;
}
static bool igb_add_rx_frag(struct igb_ring *rx_ring,
struct igb_rx_buffer *rx_buffer,
unsigned int size,
union e1000_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct page *page = rx_buffer->page;
unsigned char *va = page_address(page) + rx_buffer->page_offset;
#if (PAGE_SIZE < 8192)
unsigned int truesize = IGB_RX_BUFSZ;
#else
unsigned int truesize = SKB_DATA_ALIGN(size);
#endif
unsigned int pull_len;
if (unlikely(skb_is_nonlinear(skb)))
goto add_tail_frag;
if (unlikely(igb_test_staterr(rx_desc, E1000_RXDADV_STAT_TSIP))) {
igb_ptp_rx_pktstamp(rx_ring->q_vector, va, skb);
va += IGB_TS_HDR_LEN;
size -= IGB_TS_HDR_LEN;
}
if (likely(size <= IGB_RX_HDR_LEN)) {
memcpy(__skb_put(skb, size), va, ALIGN(size, sizeof(long)));
if (likely(!igb_page_is_reserved(page)))
return true;
__free_page(page);
return false;
}
pull_len = eth_get_headlen(va, IGB_RX_HDR_LEN);
memcpy(__skb_put(skb, pull_len), va, ALIGN(pull_len, sizeof(long)));
va += pull_len;
size -= pull_len;
add_tail_frag:
skb_add_rx_frag(skb, skb_shinfo(skb)->nr_frags, page,
(unsigned long)va & ~PAGE_MASK, size, truesize);
return igb_can_reuse_rx_page(rx_buffer, page, truesize);
}
static struct sk_buff *igb_fetch_rx_buffer(struct igb_ring *rx_ring,
union e1000_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
unsigned int size = le16_to_cpu(rx_desc->wb.upper.length);
struct igb_rx_buffer *rx_buffer;
struct page *page;
rx_buffer = &rx_ring->rx_buffer_info[rx_ring->next_to_clean];
page = rx_buffer->page;
prefetchw(page);
if (likely(!skb)) {
void *page_addr = page_address(page) +
rx_buffer->page_offset;
prefetch(page_addr);
#if L1_CACHE_BYTES < 128
prefetch(page_addr + L1_CACHE_BYTES);
#endif
skb = napi_alloc_skb(&rx_ring->q_vector->napi, IGB_RX_HDR_LEN);
if (unlikely(!skb)) {
rx_ring->rx_stats.alloc_failed++;
return NULL;
}
prefetchw(skb->data);
}
dma_sync_single_range_for_cpu(rx_ring->dev,
rx_buffer->dma,
rx_buffer->page_offset,
size,
DMA_FROM_DEVICE);
if (igb_add_rx_frag(rx_ring, rx_buffer, size, rx_desc, skb)) {
igb_reuse_rx_page(rx_ring, rx_buffer);
} else {
dma_unmap_page(rx_ring->dev, rx_buffer->dma,
PAGE_SIZE, DMA_FROM_DEVICE);
}
rx_buffer->page = NULL;
return skb;
}
static inline void igb_rx_checksum(struct igb_ring *ring,
union e1000_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
skb_checksum_none_assert(skb);
if (igb_test_staterr(rx_desc, E1000_RXD_STAT_IXSM))
return;
if (!(ring->netdev->features & NETIF_F_RXCSUM))
return;
if (igb_test_staterr(rx_desc,
E1000_RXDEXT_STATERR_TCPE |
E1000_RXDEXT_STATERR_IPE)) {
if (!((skb->len == 60) &&
test_bit(IGB_RING_FLAG_RX_SCTP_CSUM, &ring->flags))) {
u64_stats_update_begin(&ring->rx_syncp);
ring->rx_stats.csum_err++;
u64_stats_update_end(&ring->rx_syncp);
}
return;
}
if (igb_test_staterr(rx_desc, E1000_RXD_STAT_TCPCS |
E1000_RXD_STAT_UDPCS))
skb->ip_summed = CHECKSUM_UNNECESSARY;
dev_dbg(ring->dev, "cksum success: bits %08X\n",
le32_to_cpu(rx_desc->wb.upper.status_error));
}
static inline void igb_rx_hash(struct igb_ring *ring,
union e1000_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
if (ring->netdev->features & NETIF_F_RXHASH)
skb_set_hash(skb,
le32_to_cpu(rx_desc->wb.lower.hi_dword.rss),
PKT_HASH_TYPE_L3);
}
static bool igb_is_non_eop(struct igb_ring *rx_ring,
union e1000_adv_rx_desc *rx_desc)
{
u32 ntc = rx_ring->next_to_clean + 1;
ntc = (ntc < rx_ring->count) ? ntc : 0;
rx_ring->next_to_clean = ntc;
prefetch(IGB_RX_DESC(rx_ring, ntc));
if (likely(igb_test_staterr(rx_desc, E1000_RXD_STAT_EOP)))
return false;
return true;
}
static bool igb_cleanup_headers(struct igb_ring *rx_ring,
union e1000_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
if (unlikely((igb_test_staterr(rx_desc,
E1000_RXDEXT_ERR_FRAME_ERR_MASK)))) {
struct net_device *netdev = rx_ring->netdev;
if (!(netdev->features & NETIF_F_RXALL)) {
dev_kfree_skb_any(skb);
return true;
}
}
if (eth_skb_pad(skb))
return true;
return false;
}
static void igb_process_skb_fields(struct igb_ring *rx_ring,
union e1000_adv_rx_desc *rx_desc,
struct sk_buff *skb)
{
struct net_device *dev = rx_ring->netdev;
igb_rx_hash(rx_ring, rx_desc, skb);
igb_rx_checksum(rx_ring, rx_desc, skb);
if (igb_test_staterr(rx_desc, E1000_RXDADV_STAT_TS) &&
!igb_test_staterr(rx_desc, E1000_RXDADV_STAT_TSIP))
igb_ptp_rx_rgtstamp(rx_ring->q_vector, skb);
if ((dev->features & NETIF_F_HW_VLAN_CTAG_RX) &&
igb_test_staterr(rx_desc, E1000_RXD_STAT_VP)) {
u16 vid;
if (igb_test_staterr(rx_desc, E1000_RXDEXT_STATERR_LB) &&
test_bit(IGB_RING_FLAG_RX_LB_VLAN_BSWAP, &rx_ring->flags))
vid = be16_to_cpu(rx_desc->wb.upper.vlan);
else
vid = le16_to_cpu(rx_desc->wb.upper.vlan);
__vlan_hwaccel_put_tag(skb, htons(ETH_P_8021Q), vid);
}
skb_record_rx_queue(skb, rx_ring->queue_index);
skb->protocol = eth_type_trans(skb, rx_ring->netdev);
}
static int igb_clean_rx_irq(struct igb_q_vector *q_vector, const int budget)
{
struct igb_ring *rx_ring = q_vector->rx.ring;
struct sk_buff *skb = rx_ring->skb;
unsigned int total_bytes = 0, total_packets = 0;
u16 cleaned_count = igb_desc_unused(rx_ring);
while (likely(total_packets < budget)) {
union e1000_adv_rx_desc *rx_desc;
if (cleaned_count >= IGB_RX_BUFFER_WRITE) {
igb_alloc_rx_buffers(rx_ring, cleaned_count);
cleaned_count = 0;
}
rx_desc = IGB_RX_DESC(rx_ring, rx_ring->next_to_clean);
if (!rx_desc->wb.upper.status_error)
break;
dma_rmb();
skb = igb_fetch_rx_buffer(rx_ring, rx_desc, skb);
if (!skb)
break;
cleaned_count++;
if (igb_is_non_eop(rx_ring, rx_desc))
continue;
if (igb_cleanup_headers(rx_ring, rx_desc, skb)) {
skb = NULL;
continue;
}
total_bytes += skb->len;
igb_process_skb_fields(rx_ring, rx_desc, skb);
napi_gro_receive(&q_vector->napi, skb);
skb = NULL;
total_packets++;
}
rx_ring->skb = skb;
u64_stats_update_begin(&rx_ring->rx_syncp);
rx_ring->rx_stats.packets += total_packets;
rx_ring->rx_stats.bytes += total_bytes;
u64_stats_update_end(&rx_ring->rx_syncp);
q_vector->rx.total_packets += total_packets;
q_vector->rx.total_bytes += total_bytes;
if (cleaned_count)
igb_alloc_rx_buffers(rx_ring, cleaned_count);
return total_packets;
}
static bool igb_alloc_mapped_page(struct igb_ring *rx_ring,
struct igb_rx_buffer *bi)
{
struct page *page = bi->page;
dma_addr_t dma;
if (likely(page))
return true;
page = dev_alloc_page();
if (unlikely(!page)) {
rx_ring->rx_stats.alloc_failed++;
return false;
}
dma = dma_map_page(rx_ring->dev, page, 0, PAGE_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(rx_ring->dev, dma)) {
__free_page(page);
rx_ring->rx_stats.alloc_failed++;
return false;
}
bi->dma = dma;
bi->page = page;
bi->page_offset = 0;
return true;
}
void igb_alloc_rx_buffers(struct igb_ring *rx_ring, u16 cleaned_count)
{
union e1000_adv_rx_desc *rx_desc;
struct igb_rx_buffer *bi;
u16 i = rx_ring->next_to_use;
if (!cleaned_count)
return;
rx_desc = IGB_RX_DESC(rx_ring, i);
bi = &rx_ring->rx_buffer_info[i];
i -= rx_ring->count;
do {
if (!igb_alloc_mapped_page(rx_ring, bi))
break;
rx_desc->read.pkt_addr = cpu_to_le64(bi->dma + bi->page_offset);
rx_desc++;
bi++;
i++;
if (unlikely(!i)) {
rx_desc = IGB_RX_DESC(rx_ring, 0);
bi = rx_ring->rx_buffer_info;
i -= rx_ring->count;
}
rx_desc->wb.upper.status_error = 0;
cleaned_count--;
} while (cleaned_count);
i += rx_ring->count;
if (rx_ring->next_to_use != i) {
rx_ring->next_to_use = i;
rx_ring->next_to_alloc = i;
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
static int igb_ioctl(struct net_device *netdev, struct ifreq *ifr, int cmd)
{
switch (cmd) {
case SIOCGMIIPHY:
case SIOCGMIIREG:
case SIOCSMIIREG:
return igb_mii_ioctl(netdev, ifr, cmd);
case SIOCGHWTSTAMP:
return igb_ptp_get_ts_config(netdev, ifr);
case SIOCSHWTSTAMP:
return igb_ptp_set_ts_config(netdev, ifr);
default:
return -EOPNOTSUPP;
}
}
void igb_read_pci_cfg(struct e1000_hw *hw, u32 reg, u16 *value)
{
struct igb_adapter *adapter = hw->back;
pci_read_config_word(adapter->pdev, reg, value);
}
void igb_write_pci_cfg(struct e1000_hw *hw, u32 reg, u16 *value)
{
struct igb_adapter *adapter = hw->back;
pci_write_config_word(adapter->pdev, reg, *value);
}
s32 igb_read_pcie_cap_reg(struct e1000_hw *hw, u32 reg, u16 *value)
{
struct igb_adapter *adapter = hw->back;
if (pcie_capability_read_word(adapter->pdev, reg, value))
return -E1000_ERR_CONFIG;
return 0;
}
s32 igb_write_pcie_cap_reg(struct e1000_hw *hw, u32 reg, u16 *value)
{
struct igb_adapter *adapter = hw->back;
if (pcie_capability_write_word(adapter->pdev, reg, *value))
return -E1000_ERR_CONFIG;
return 0;
}
static void igb_vlan_mode(struct net_device *netdev, netdev_features_t features)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
u32 ctrl, rctl;
bool enable = !!(features & NETIF_F_HW_VLAN_CTAG_RX);
if (enable) {
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
igb_set_vf_vlan_strip(adapter, adapter->vfs_allocated_count, enable);
}
static int igb_vlan_rx_add_vid(struct net_device *netdev,
__be16 proto, u16 vid)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
int pf_id = adapter->vfs_allocated_count;
if (!vid || !(adapter->flags & IGB_FLAG_VLAN_PROMISC))
igb_vfta_set(hw, vid, pf_id, true, !!vid);
set_bit(vid, adapter->active_vlans);
return 0;
}
static int igb_vlan_rx_kill_vid(struct net_device *netdev,
__be16 proto, u16 vid)
{
struct igb_adapter *adapter = netdev_priv(netdev);
int pf_id = adapter->vfs_allocated_count;
struct e1000_hw *hw = &adapter->hw;
if (vid && !(adapter->flags & IGB_FLAG_VLAN_PROMISC))
igb_vfta_set(hw, vid, pf_id, false, true);
clear_bit(vid, adapter->active_vlans);
return 0;
}
static void igb_restore_vlan(struct igb_adapter *adapter)
{
u16 vid = 1;
igb_vlan_mode(adapter->netdev, adapter->netdev->features);
igb_vlan_rx_add_vid(adapter->netdev, htons(ETH_P_8021Q), 0);
for_each_set_bit_from(vid, adapter->active_vlans, VLAN_N_VID)
igb_vlan_rx_add_vid(adapter->netdev, htons(ETH_P_8021Q), vid);
}
int igb_set_spd_dplx(struct igb_adapter *adapter, u32 spd, u8 dplx)
{
struct pci_dev *pdev = adapter->pdev;
struct e1000_mac_info *mac = &adapter->hw.mac;
mac->autoneg = 0;
if ((spd & 1) || (dplx & ~1))
goto err_inval;
if (adapter->hw.phy.media_type == e1000_media_type_internal_serdes) {
switch (spd + dplx) {
case SPEED_10 + DUPLEX_HALF:
case SPEED_10 + DUPLEX_FULL:
case SPEED_100 + DUPLEX_HALF:
goto err_inval;
default:
break;
}
}
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
adapter->hw.phy.mdix = AUTO_ALL_MODES;
return 0;
err_inval:
dev_err(&pdev->dev, "Unsupported Speed/Duplex configuration\n");
return -EINVAL;
}
static int __igb_shutdown(struct pci_dev *pdev, bool *enable_wake,
bool runtime)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
u32 ctrl, rctl, status;
u32 wufc = runtime ? E1000_WUFC_LNKC : adapter->wol;
#ifdef CONFIG_PM
int retval = 0;
#endif
netif_device_detach(netdev);
if (netif_running(netdev))
__igb_close(netdev, true);
igb_ptp_suspend(adapter);
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
static int igb_suspend(struct device *dev)
{
int retval;
bool wake;
struct pci_dev *pdev = to_pci_dev(dev);
retval = __igb_shutdown(pdev, &wake, 0);
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
static int igb_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
u32 err;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
pci_save_state(pdev);
if (!pci_device_is_present(pdev))
return -ENODEV;
err = pci_enable_device_mem(pdev);
if (err) {
dev_err(&pdev->dev,
"igb: Cannot enable PCI device from suspend\n");
return err;
}
pci_set_master(pdev);
pci_enable_wake(pdev, PCI_D3hot, 0);
pci_enable_wake(pdev, PCI_D3cold, 0);
if (igb_init_interrupt_scheme(adapter, true)) {
dev_err(&pdev->dev, "Unable to allocate memory for queues\n");
return -ENOMEM;
}
igb_reset(adapter);
igb_get_hw_control(adapter);
wr32(E1000_WUS, ~0);
if (netdev->flags & IFF_UP) {
rtnl_lock();
err = __igb_open(netdev, true);
rtnl_unlock();
if (err)
return err;
}
netif_device_attach(netdev);
return 0;
}
static int igb_runtime_idle(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct net_device *netdev = pci_get_drvdata(pdev);
struct igb_adapter *adapter = netdev_priv(netdev);
if (!igb_has_link(adapter))
pm_schedule_suspend(dev, MSEC_PER_SEC * 5);
return -EBUSY;
}
static int igb_runtime_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
int retval;
bool wake;
retval = __igb_shutdown(pdev, &wake, 1);
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
static int igb_runtime_resume(struct device *dev)
{
return igb_resume(dev);
}
static void igb_shutdown(struct pci_dev *pdev)
{
bool wake;
__igb_shutdown(pdev, &wake, 0);
if (system_state == SYSTEM_POWER_OFF) {
pci_wake_from_d3(pdev, wake);
pci_set_power_state(pdev, PCI_D3hot);
}
}
static int igb_sriov_reinit(struct pci_dev *dev)
{
struct net_device *netdev = pci_get_drvdata(dev);
struct igb_adapter *adapter = netdev_priv(netdev);
struct pci_dev *pdev = adapter->pdev;
rtnl_lock();
if (netif_running(netdev))
igb_close(netdev);
else
igb_reset(adapter);
igb_clear_interrupt_scheme(adapter);
igb_init_queue_configuration(adapter);
if (igb_init_interrupt_scheme(adapter, true)) {
rtnl_unlock();
dev_err(&pdev->dev, "Unable to allocate memory for queues\n");
return -ENOMEM;
}
if (netif_running(netdev))
igb_open(netdev);
rtnl_unlock();
return 0;
}
static int igb_pci_disable_sriov(struct pci_dev *dev)
{
int err = igb_disable_sriov(dev);
if (!err)
err = igb_sriov_reinit(dev);
return err;
}
static int igb_pci_enable_sriov(struct pci_dev *dev, int num_vfs)
{
int err = igb_enable_sriov(dev, num_vfs);
if (err)
goto out;
err = igb_sriov_reinit(dev);
if (!err)
return num_vfs;
out:
return err;
}
static int igb_pci_sriov_configure(struct pci_dev *dev, int num_vfs)
{
#ifdef CONFIG_PCI_IOV
if (num_vfs == 0)
return igb_pci_disable_sriov(dev);
else
return igb_pci_enable_sriov(dev, num_vfs);
#endif
return 0;
}
static void igb_netpoll(struct net_device *netdev)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
struct igb_q_vector *q_vector;
int i;
for (i = 0; i < adapter->num_q_vectors; i++) {
q_vector = adapter->q_vector[i];
if (adapter->flags & IGB_FLAG_HAS_MSIX)
wr32(E1000_EIMC, q_vector->eims_value);
else
igb_irq_disable(adapter);
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
dev_err(&pdev->dev,
"pci_cleanup_aer_uncorrect_error_status failed 0x%0x\n",
err);
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
struct e1000_hw *hw = &adapter->hw;
u32 rar_low, rar_high;
rar_low = le32_to_cpup((__le32 *)(addr));
rar_high = le16_to_cpup((__le16 *)(addr + 4));
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
dev_info(&adapter->pdev->dev,
"Reload the VF driver to make this change effective.");
if (test_bit(__IGB_DOWN, &adapter->state)) {
dev_warn(&adapter->pdev->dev,
"The VF MAC address has been set, but the PF device is not up.\n");
dev_warn(&adapter->pdev->dev,
"Bring the PF device up before attempting to use the VF device.\n");
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
rf_dec = (rf_dec * BIT(E1000_RTTBCNRC_RF_INT_SHIFT)) /
tx_rate;
bcnrc_val = E1000_RTTBCNRC_RS_ENA;
bcnrc_val |= ((rf_int << E1000_RTTBCNRC_RF_INT_SHIFT) &
E1000_RTTBCNRC_RF_INT_MASK);
bcnrc_val |= (rf_dec & E1000_RTTBCNRC_RF_DEC_MASK);
} else {
bcnrc_val = 0;
}
wr32(E1000_RTTDQSEL, vf);
wr32(E1000_RTTBCNRM, 0x14);
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
"Link speed has been changed. VF Transmit rate is disabled\n");
}
for (i = 0; i < adapter->vfs_allocated_count; i++) {
if (reset_rate)
adapter->vf_data[i].tx_rate = 0;
igb_set_vf_rate_limit(&adapter->hw, i,
adapter->vf_data[i].tx_rate,
actual_link_speed);
}
}
static int igb_ndo_set_vf_bw(struct net_device *netdev, int vf,
int min_tx_rate, int max_tx_rate)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
int actual_link_speed;
if (hw->mac.type != e1000_82576)
return -EOPNOTSUPP;
if (min_tx_rate)
return -EINVAL;
actual_link_speed = igb_link_mbps(adapter->link_speed);
if ((vf >= adapter->vfs_allocated_count) ||
(!(rd32(E1000_STATUS) & E1000_STATUS_LU)) ||
(max_tx_rate < 0) ||
(max_tx_rate > actual_link_speed))
return -EINVAL;
adapter->vf_rate_link_speed = actual_link_speed;
adapter->vf_data[vf].tx_rate = (u16)max_tx_rate;
igb_set_vf_rate_limit(hw, vf, max_tx_rate, actual_link_speed);
return 0;
}
static int igb_ndo_set_vf_spoofchk(struct net_device *netdev, int vf,
bool setting)
{
struct igb_adapter *adapter = netdev_priv(netdev);
struct e1000_hw *hw = &adapter->hw;
u32 reg_val, reg_offset;
if (!adapter->vfs_allocated_count)
return -EOPNOTSUPP;
if (vf >= adapter->vfs_allocated_count)
return -EINVAL;
reg_offset = (hw->mac.type == e1000_82576) ? E1000_DTXSWC : E1000_TXSWC;
reg_val = rd32(reg_offset);
if (setting)
reg_val |= (BIT(vf) |
BIT(vf + E1000_DTXSWC_VLAN_SPOOF_SHIFT));
else
reg_val &= ~(BIT(vf) |
BIT(vf + E1000_DTXSWC_VLAN_SPOOF_SHIFT));
wr32(reg_offset, reg_val);
adapter->vf_data[vf].spoofchk_enabled = setting;
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
ivi->max_tx_rate = adapter->vf_data[vf].tx_rate;
ivi->min_tx_rate = 0;
ivi->vlan = adapter->vf_data[vf].pf_vlan;
ivi->qos = adapter->vf_data[vf].pf_qos;
ivi->spoofchk = adapter->vf_data[vf].spoofchk_enabled;
return 0;
}
static void igb_vmm_control(struct igb_adapter *adapter)
{
struct e1000_hw *hw = &adapter->hw;
u32 reg;
switch (hw->mac.type) {
case e1000_82575:
case e1000_i210:
case e1000_i211:
case e1000_i354:
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
static void igb_init_dmac(struct igb_adapter *adapter, u32 pba)
{
struct e1000_hw *hw = &adapter->hw;
u32 dmac_thr;
u16 hwm;
if (hw->mac.type > e1000_82580) {
if (adapter->flags & IGB_FLAG_DMAC) {
u32 reg;
wr32(E1000_DMCTXTH, 0);
hwm = 64 * (pba - 6);
reg = rd32(E1000_FCRTC);
reg &= ~E1000_FCRTC_RTH_COAL_MASK;
reg |= ((hwm << E1000_FCRTC_RTH_COAL_SHIFT)
& E1000_FCRTC_RTH_COAL_MASK);
wr32(E1000_FCRTC, reg);
dmac_thr = pba - 10;
reg = rd32(E1000_DMACR);
reg &= ~E1000_DMACR_DMACTHR_MASK;
reg |= ((dmac_thr << E1000_DMACR_DMACTHR_SHIFT)
& E1000_DMACR_DMACTHR_MASK);
reg |= (E1000_DMACR_DMAC_EN | E1000_DMACR_DMAC_LX_MASK);
reg |= (1000 >> 5);
if (hw->mac.type != e1000_i354)
reg &= ~E1000_DMACR_DC_BMC2OSW_EN;
wr32(E1000_DMACR, reg);
wr32(E1000_DMCRTRH, 0);
reg = (IGB_DMCTLX_DCFLUSH_DIS | 0x4);
wr32(E1000_DMCTLX, reg);
wr32(E1000_DMCTXTH, (IGB_MIN_TXPBSIZE -
(IGB_TX_BUF_4096 + adapter->max_frame_size)) >> 6);
reg = rd32(E1000_PCIEMISC);
reg &= ~E1000_PCIEMISC_LX_DECISION;
wr32(E1000_PCIEMISC, reg);
}
} else if (hw->mac.type == e1000_82580) {
u32 reg = rd32(E1000_PCIEMISC);
wr32(E1000_PCIEMISC, reg & ~E1000_PCIEMISC_LX_DECISION);
wr32(E1000_DMACR, 0);
}
}
s32 igb_read_i2c_byte(struct e1000_hw *hw, u8 byte_offset,
u8 dev_addr, u8 *data)
{
struct igb_adapter *adapter = container_of(hw, struct igb_adapter, hw);
struct i2c_client *this_client = adapter->i2c_client;
s32 status;
u16 swfw_mask = 0;
if (!this_client)
return E1000_ERR_I2C;
swfw_mask = E1000_SWFW_PHY0_SM;
if (hw->mac.ops.acquire_swfw_sync(hw, swfw_mask))
return E1000_ERR_SWFW_SYNC;
status = i2c_smbus_read_byte_data(this_client, byte_offset);
hw->mac.ops.release_swfw_sync(hw, swfw_mask);
if (status < 0)
return E1000_ERR_I2C;
else {
*data = status;
return 0;
}
}
s32 igb_write_i2c_byte(struct e1000_hw *hw, u8 byte_offset,
u8 dev_addr, u8 data)
{
struct igb_adapter *adapter = container_of(hw, struct igb_adapter, hw);
struct i2c_client *this_client = adapter->i2c_client;
s32 status;
u16 swfw_mask = E1000_SWFW_PHY0_SM;
if (!this_client)
return E1000_ERR_I2C;
if (hw->mac.ops.acquire_swfw_sync(hw, swfw_mask))
return E1000_ERR_SWFW_SYNC;
status = i2c_smbus_write_byte_data(this_client, byte_offset, data);
hw->mac.ops.release_swfw_sync(hw, swfw_mask);
if (status)
return E1000_ERR_I2C;
else
return 0;
}
int igb_reinit_queues(struct igb_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct pci_dev *pdev = adapter->pdev;
int err = 0;
if (netif_running(netdev))
igb_close(netdev);
igb_reset_interrupt_capability(adapter);
if (igb_init_interrupt_scheme(adapter, true)) {
dev_err(&pdev->dev, "Unable to allocate memory for queues\n");
return -ENOMEM;
}
if (netif_running(netdev))
err = igb_open(netdev);
return err;
}
