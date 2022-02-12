i40e_status i40evf_allocate_dma_mem_d(struct i40e_hw *hw,
struct i40e_dma_mem *mem,
u64 size, u32 alignment)
{
struct i40evf_adapter *adapter = (struct i40evf_adapter *)hw->back;
if (!mem)
return I40E_ERR_PARAM;
mem->size = ALIGN(size, alignment);
mem->va = dma_alloc_coherent(&adapter->pdev->dev, mem->size,
(dma_addr_t *)&mem->pa, GFP_KERNEL);
if (mem->va)
return 0;
else
return I40E_ERR_NO_MEMORY;
}
i40e_status i40evf_free_dma_mem_d(struct i40e_hw *hw, struct i40e_dma_mem *mem)
{
struct i40evf_adapter *adapter = (struct i40evf_adapter *)hw->back;
if (!mem || !mem->va)
return I40E_ERR_PARAM;
dma_free_coherent(&adapter->pdev->dev, mem->size,
mem->va, (dma_addr_t)mem->pa);
return 0;
}
i40e_status i40evf_allocate_virt_mem_d(struct i40e_hw *hw,
struct i40e_virt_mem *mem, u32 size)
{
if (!mem)
return I40E_ERR_PARAM;
mem->size = size;
mem->va = kzalloc(size, GFP_KERNEL);
if (mem->va)
return 0;
else
return I40E_ERR_NO_MEMORY;
}
i40e_status i40evf_free_virt_mem_d(struct i40e_hw *hw,
struct i40e_virt_mem *mem)
{
if (!mem)
return I40E_ERR_PARAM;
kfree(mem->va);
return 0;
}
void i40evf_debug_d(void *hw, u32 mask, char *fmt_str, ...)
{
char buf[512];
va_list argptr;
if (!(mask & ((struct i40e_hw *)hw)->debug_mask))
return;
va_start(argptr, fmt_str);
vsnprintf(buf, sizeof(buf), fmt_str, argptr);
va_end(argptr);
pr_info("%s", buf);
}
static void i40evf_tx_timeout(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
adapter->tx_timeout_count++;
dev_info(&adapter->pdev->dev, "TX timeout detected.\n");
if (!(adapter->flags & I40EVF_FLAG_RESET_PENDING)) {
adapter->flags |= I40EVF_FLAG_RESET_NEEDED;
schedule_work(&adapter->reset_task);
}
}
static void i40evf_misc_irq_disable(struct i40evf_adapter *adapter)
{
struct i40e_hw *hw = &adapter->hw;
wr32(hw, I40E_VFINT_DYN_CTL01, 0);
rd32(hw, I40E_VFGEN_RSTAT);
synchronize_irq(adapter->msix_entries[0].vector);
}
static void i40evf_misc_irq_enable(struct i40evf_adapter *adapter)
{
struct i40e_hw *hw = &adapter->hw;
wr32(hw, I40E_VFINT_DYN_CTL01, I40E_VFINT_DYN_CTL01_INTENA_MASK |
I40E_VFINT_DYN_CTL01_ITR_INDX_MASK);
wr32(hw, I40E_VFINT_ICR0_ENA1, I40E_VFINT_ICR0_ENA_ADMINQ_MASK);
rd32(hw, I40E_VFGEN_RSTAT);
}
static void i40evf_irq_disable(struct i40evf_adapter *adapter)
{
int i;
struct i40e_hw *hw = &adapter->hw;
if (!adapter->msix_entries)
return;
for (i = 1; i < adapter->num_msix_vectors; i++) {
wr32(hw, I40E_VFINT_DYN_CTLN1(i - 1), 0);
synchronize_irq(adapter->msix_entries[i].vector);
}
rd32(hw, I40E_VFGEN_RSTAT);
}
void i40evf_irq_enable_queues(struct i40evf_adapter *adapter, u32 mask)
{
struct i40e_hw *hw = &adapter->hw;
int i;
for (i = 1; i < adapter->num_msix_vectors; i++) {
if (mask & (1 << (i - 1))) {
wr32(hw, I40E_VFINT_DYN_CTLN1(i - 1),
I40E_VFINT_DYN_CTLN1_INTENA_MASK |
I40E_VFINT_DYN_CTLN_CLEARPBA_MASK);
}
}
}
static void i40evf_fire_sw_int(struct i40evf_adapter *adapter,
u32 mask)
{
struct i40e_hw *hw = &adapter->hw;
int i;
uint32_t dyn_ctl;
for (i = 1; i < adapter->num_msix_vectors; i++) {
if (mask & (1 << i)) {
dyn_ctl = rd32(hw, I40E_VFINT_DYN_CTLN1(i - 1));
dyn_ctl |= I40E_VFINT_DYN_CTLN_SWINT_TRIG_MASK |
I40E_VFINT_DYN_CTLN_CLEARPBA_MASK;
wr32(hw, I40E_VFINT_DYN_CTLN1(i - 1), dyn_ctl);
}
}
}
void i40evf_irq_enable(struct i40evf_adapter *adapter, bool flush)
{
struct i40e_hw *hw = &adapter->hw;
i40evf_irq_enable_queues(adapter, ~0);
if (flush)
rd32(hw, I40E_VFGEN_RSTAT);
}
static irqreturn_t i40evf_msix_aq(int irq, void *data)
{
struct net_device *netdev = data;
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_hw *hw = &adapter->hw;
u32 val;
u32 ena_mask;
val = rd32(hw, I40E_VFINT_ICR01);
ena_mask = rd32(hw, I40E_VFINT_ICR0_ENA1);
val = rd32(hw, I40E_VFINT_DYN_CTL01);
val = val | I40E_PFINT_DYN_CTL0_CLEARPBA_MASK;
wr32(hw, I40E_VFINT_DYN_CTL01, val);
wr32(hw, I40E_VFINT_ICR0_ENA1, ena_mask);
wr32(hw, I40E_VFINT_DYN_CTL01, I40E_VFINT_DYN_CTL01_INTENA_MASK);
schedule_work(&adapter->adminq_task);
return IRQ_HANDLED;
}
static irqreturn_t i40evf_msix_clean_rings(int irq, void *data)
{
struct i40e_q_vector *q_vector = data;
if (!q_vector->tx.ring && !q_vector->rx.ring)
return IRQ_HANDLED;
napi_schedule(&q_vector->napi);
return IRQ_HANDLED;
}
static void
i40evf_map_vector_to_rxq(struct i40evf_adapter *adapter, int v_idx, int r_idx)
{
struct i40e_q_vector *q_vector = adapter->q_vector[v_idx];
struct i40e_ring *rx_ring = adapter->rx_rings[r_idx];
rx_ring->q_vector = q_vector;
rx_ring->next = q_vector->rx.ring;
rx_ring->vsi = &adapter->vsi;
q_vector->rx.ring = rx_ring;
q_vector->rx.count++;
q_vector->rx.latency_range = I40E_LOW_LATENCY;
}
static void
i40evf_map_vector_to_txq(struct i40evf_adapter *adapter, int v_idx, int t_idx)
{
struct i40e_q_vector *q_vector = adapter->q_vector[v_idx];
struct i40e_ring *tx_ring = adapter->tx_rings[t_idx];
tx_ring->q_vector = q_vector;
tx_ring->next = q_vector->tx.ring;
tx_ring->vsi = &adapter->vsi;
q_vector->tx.ring = tx_ring;
q_vector->tx.count++;
q_vector->tx.latency_range = I40E_LOW_LATENCY;
q_vector->num_ringpairs++;
q_vector->ring_mask |= (1 << t_idx);
}
static int i40evf_map_rings_to_vectors(struct i40evf_adapter *adapter)
{
int q_vectors;
int v_start = 0;
int rxr_idx = 0, txr_idx = 0;
int rxr_remaining = adapter->vsi_res->num_queue_pairs;
int txr_remaining = adapter->vsi_res->num_queue_pairs;
int i, j;
int rqpv, tqpv;
int err = 0;
q_vectors = adapter->num_msix_vectors - NONQ_VECS;
if (q_vectors == (rxr_remaining * 2)) {
for (; rxr_idx < rxr_remaining; v_start++, rxr_idx++)
i40evf_map_vector_to_rxq(adapter, v_start, rxr_idx);
for (; txr_idx < txr_remaining; v_start++, txr_idx++)
i40evf_map_vector_to_txq(adapter, v_start, txr_idx);
goto out;
}
for (i = v_start; i < q_vectors; i++) {
rqpv = DIV_ROUND_UP(rxr_remaining, q_vectors - i);
for (j = 0; j < rqpv; j++) {
i40evf_map_vector_to_rxq(adapter, i, rxr_idx);
rxr_idx++;
rxr_remaining--;
}
}
for (i = v_start; i < q_vectors; i++) {
tqpv = DIV_ROUND_UP(txr_remaining, q_vectors - i);
for (j = 0; j < tqpv; j++) {
i40evf_map_vector_to_txq(adapter, i, txr_idx);
txr_idx++;
txr_remaining--;
}
}
out:
adapter->aq_required |= I40EVF_FLAG_AQ_MAP_VECTORS;
return err;
}
static int
i40evf_request_traffic_irqs(struct i40evf_adapter *adapter, char *basename)
{
int vector, err, q_vectors;
int rx_int_idx = 0, tx_int_idx = 0;
i40evf_irq_disable(adapter);
q_vectors = adapter->num_msix_vectors - NONQ_VECS;
for (vector = 0; vector < q_vectors; vector++) {
struct i40e_q_vector *q_vector = adapter->q_vector[vector];
if (q_vector->tx.ring && q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"i40evf-%s-%s-%d", basename,
"TxRx", rx_int_idx++);
tx_int_idx++;
} else if (q_vector->rx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"i40evf-%s-%s-%d", basename,
"rx", rx_int_idx++);
} else if (q_vector->tx.ring) {
snprintf(q_vector->name, sizeof(q_vector->name) - 1,
"i40evf-%s-%s-%d", basename,
"tx", tx_int_idx++);
} else {
continue;
}
err = request_irq(
adapter->msix_entries[vector + NONQ_VECS].vector,
i40evf_msix_clean_rings,
0,
q_vector->name,
q_vector);
if (err) {
dev_info(&adapter->pdev->dev,
"%s: request_irq failed, error: %d\n",
__func__, err);
goto free_queue_irqs;
}
irq_set_affinity_hint(
adapter->msix_entries[vector + NONQ_VECS].vector,
q_vector->affinity_mask);
}
return 0;
free_queue_irqs:
while (vector) {
vector--;
irq_set_affinity_hint(
adapter->msix_entries[vector + NONQ_VECS].vector,
NULL);
free_irq(adapter->msix_entries[vector + NONQ_VECS].vector,
adapter->q_vector[vector]);
}
return err;
}
static int i40evf_request_misc_irq(struct i40evf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int err;
sprintf(adapter->misc_vector_name, "i40evf:mbx");
err = request_irq(adapter->msix_entries[0].vector,
&i40evf_msix_aq, 0,
adapter->misc_vector_name, netdev);
if (err) {
dev_err(&adapter->pdev->dev,
"request_irq for %s failed: %d\n",
adapter->misc_vector_name, err);
free_irq(adapter->msix_entries[0].vector, netdev);
}
return err;
}
static void i40evf_free_traffic_irqs(struct i40evf_adapter *adapter)
{
int i;
int q_vectors;
q_vectors = adapter->num_msix_vectors - NONQ_VECS;
for (i = 0; i < q_vectors; i++) {
irq_set_affinity_hint(adapter->msix_entries[i+1].vector,
NULL);
free_irq(adapter->msix_entries[i+1].vector,
adapter->q_vector[i]);
}
}
static void i40evf_free_misc_irq(struct i40evf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
free_irq(adapter->msix_entries[0].vector, netdev);
}
static void i40evf_configure_tx(struct i40evf_adapter *adapter)
{
struct i40e_hw *hw = &adapter->hw;
int i;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++)
adapter->tx_rings[i]->tail = hw->hw_addr + I40E_QTX_TAIL1(i);
}
static void i40evf_configure_rx(struct i40evf_adapter *adapter)
{
struct i40e_hw *hw = &adapter->hw;
struct net_device *netdev = adapter->netdev;
int max_frame = netdev->mtu + ETH_HLEN + ETH_FCS_LEN;
int i;
int rx_buf_len;
adapter->flags &= ~I40EVF_FLAG_RX_PS_CAPABLE;
adapter->flags |= I40EVF_FLAG_RX_1BUF_CAPABLE;
if (netdev->mtu > ETH_DATA_LEN) {
if (adapter->flags & I40EVF_FLAG_RX_PS_CAPABLE)
adapter->flags |= I40EVF_FLAG_RX_PS_ENABLED;
else
adapter->flags &= ~I40EVF_FLAG_RX_PS_ENABLED;
} else {
if (adapter->flags & I40EVF_FLAG_RX_1BUF_CAPABLE)
adapter->flags &= ~I40EVF_FLAG_RX_PS_ENABLED;
else
adapter->flags |= I40EVF_FLAG_RX_PS_ENABLED;
}
if (adapter->flags & I40EVF_FLAG_RX_PS_ENABLED) {
rx_buf_len = I40E_RX_HDR_SIZE;
} else {
if (netdev->mtu <= ETH_DATA_LEN)
rx_buf_len = I40EVF_RXBUFFER_2048;
else
rx_buf_len = ALIGN(max_frame, 1024);
}
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++) {
adapter->rx_rings[i]->tail = hw->hw_addr + I40E_QRX_TAIL1(i);
adapter->rx_rings[i]->rx_buf_len = rx_buf_len;
}
}
static struct
i40evf_vlan_filter *i40evf_find_vlan(struct i40evf_adapter *adapter, u16 vlan)
{
struct i40evf_vlan_filter *f;
list_for_each_entry(f, &adapter->vlan_filter_list, list) {
if (vlan == f->vlan)
return f;
}
return NULL;
}
static struct
i40evf_vlan_filter *i40evf_add_vlan(struct i40evf_adapter *adapter, u16 vlan)
{
struct i40evf_vlan_filter *f;
f = i40evf_find_vlan(adapter, vlan);
if (NULL == f) {
f = kzalloc(sizeof(*f), GFP_ATOMIC);
if (NULL == f) {
dev_info(&adapter->pdev->dev,
"%s: no memory for new VLAN filter\n",
__func__);
return NULL;
}
f->vlan = vlan;
INIT_LIST_HEAD(&f->list);
list_add(&f->list, &adapter->vlan_filter_list);
f->add = true;
adapter->aq_required |= I40EVF_FLAG_AQ_ADD_VLAN_FILTER;
}
return f;
}
static void i40evf_del_vlan(struct i40evf_adapter *adapter, u16 vlan)
{
struct i40evf_vlan_filter *f;
f = i40evf_find_vlan(adapter, vlan);
if (f) {
f->remove = true;
adapter->aq_required |= I40EVF_FLAG_AQ_DEL_VLAN_FILTER;
}
return;
}
static int i40evf_vlan_rx_add_vid(struct net_device *netdev,
__always_unused __be16 proto, u16 vid)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
if (i40evf_add_vlan(adapter, vid) == NULL)
return -ENOMEM;
return 0;
}
static int i40evf_vlan_rx_kill_vid(struct net_device *netdev,
__always_unused __be16 proto, u16 vid)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
i40evf_del_vlan(adapter, vid);
return 0;
}
static struct
i40evf_mac_filter *i40evf_find_filter(struct i40evf_adapter *adapter,
u8 *macaddr)
{
struct i40evf_mac_filter *f;
if (!macaddr)
return NULL;
list_for_each_entry(f, &adapter->mac_filter_list, list) {
if (ether_addr_equal(macaddr, f->macaddr))
return f;
}
return NULL;
}
static struct
i40evf_mac_filter *i40evf_add_filter(struct i40evf_adapter *adapter,
u8 *macaddr)
{
struct i40evf_mac_filter *f;
if (!macaddr)
return NULL;
while (test_and_set_bit(__I40EVF_IN_CRITICAL_TASK,
&adapter->crit_section))
mdelay(1);
f = i40evf_find_filter(adapter, macaddr);
if (NULL == f) {
f = kzalloc(sizeof(*f), GFP_ATOMIC);
if (NULL == f) {
dev_info(&adapter->pdev->dev,
"%s: no memory for new filter\n", __func__);
clear_bit(__I40EVF_IN_CRITICAL_TASK,
&adapter->crit_section);
return NULL;
}
memcpy(f->macaddr, macaddr, ETH_ALEN);
list_add(&f->list, &adapter->mac_filter_list);
f->add = true;
adapter->aq_required |= I40EVF_FLAG_AQ_ADD_MAC_FILTER;
}
clear_bit(__I40EVF_IN_CRITICAL_TASK, &adapter->crit_section);
return f;
}
static int i40evf_set_mac(struct net_device *netdev, void *p)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_hw *hw = &adapter->hw;
struct i40evf_mac_filter *f;
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
if (ether_addr_equal(netdev->dev_addr, addr->sa_data))
return 0;
f = i40evf_add_filter(adapter, addr->sa_data);
if (f) {
memcpy(hw->mac.addr, addr->sa_data, netdev->addr_len);
memcpy(netdev->dev_addr, adapter->hw.mac.addr,
netdev->addr_len);
}
return (f == NULL) ? -ENOMEM : 0;
}
static void i40evf_set_rx_mode(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40evf_mac_filter *f, *ftmp;
struct netdev_hw_addr *uca;
struct netdev_hw_addr *mca;
netdev_for_each_uc_addr(uca, netdev) {
i40evf_add_filter(adapter, uca->addr);
}
netdev_for_each_mc_addr(mca, netdev) {
i40evf_add_filter(adapter, mca->addr);
}
while (test_and_set_bit(__I40EVF_IN_CRITICAL_TASK,
&adapter->crit_section))
mdelay(1);
list_for_each_entry_safe(f, ftmp, &adapter->mac_filter_list, list) {
bool found = false;
if (f->macaddr[0] & 0x01) {
netdev_for_each_mc_addr(mca, netdev) {
if (ether_addr_equal(mca->addr, f->macaddr)) {
found = true;
break;
}
}
} else {
netdev_for_each_uc_addr(uca, netdev) {
if (ether_addr_equal(uca->addr, f->macaddr)) {
found = true;
break;
}
}
}
if (found) {
f->remove = true;
adapter->aq_required |= I40EVF_FLAG_AQ_DEL_MAC_FILTER;
}
}
clear_bit(__I40EVF_IN_CRITICAL_TASK, &adapter->crit_section);
}
static void i40evf_napi_enable_all(struct i40evf_adapter *adapter)
{
int q_idx;
struct i40e_q_vector *q_vector;
int q_vectors = adapter->num_msix_vectors - NONQ_VECS;
for (q_idx = 0; q_idx < q_vectors; q_idx++) {
struct napi_struct *napi;
q_vector = adapter->q_vector[q_idx];
napi = &q_vector->napi;
napi_enable(napi);
}
}
static void i40evf_napi_disable_all(struct i40evf_adapter *adapter)
{
int q_idx;
struct i40e_q_vector *q_vector;
int q_vectors = adapter->num_msix_vectors - NONQ_VECS;
for (q_idx = 0; q_idx < q_vectors; q_idx++) {
q_vector = adapter->q_vector[q_idx];
napi_disable(&q_vector->napi);
}
}
static void i40evf_configure(struct i40evf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int i;
i40evf_set_rx_mode(netdev);
i40evf_configure_tx(adapter);
i40evf_configure_rx(adapter);
adapter->aq_required |= I40EVF_FLAG_AQ_CONFIGURE_QUEUES;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++) {
struct i40e_ring *ring = adapter->rx_rings[i];
i40evf_alloc_rx_buffers(ring, ring->count);
ring->next_to_use = ring->count - 1;
writel(ring->next_to_use, ring->tail);
}
}
static int i40evf_up_complete(struct i40evf_adapter *adapter)
{
adapter->state = __I40EVF_RUNNING;
clear_bit(__I40E_DOWN, &adapter->vsi.state);
i40evf_napi_enable_all(adapter);
adapter->aq_required |= I40EVF_FLAG_AQ_ENABLE_QUEUES;
mod_timer_pending(&adapter->watchdog_timer, jiffies + 1);
return 0;
}
static void i40evf_clean_all_rx_rings(struct i40evf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++)
i40evf_clean_rx_ring(adapter->rx_rings[i]);
}
static void i40evf_clean_all_tx_rings(struct i40evf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++)
i40evf_clean_tx_ring(adapter->tx_rings[i]);
}
void i40evf_down(struct i40evf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
struct i40evf_mac_filter *f;
list_for_each_entry(f, &adapter->mac_filter_list, list) {
f->remove = true;
}
list_for_each_entry(f, &adapter->vlan_filter_list, list) {
f->remove = true;
}
if (!(adapter->flags & I40EVF_FLAG_PF_COMMS_FAILED) &&
adapter->state != __I40EVF_RESETTING) {
adapter->aq_required |= I40EVF_FLAG_AQ_DEL_MAC_FILTER;
adapter->aq_required |= I40EVF_FLAG_AQ_DEL_VLAN_FILTER;
adapter->aq_required |= I40EVF_FLAG_AQ_DISABLE_QUEUES;
mod_timer_pending(&adapter->watchdog_timer, jiffies + 1);
msleep(20);
}
netif_tx_disable(netdev);
netif_tx_stop_all_queues(netdev);
i40evf_irq_disable(adapter);
i40evf_napi_disable_all(adapter);
netif_carrier_off(netdev);
i40evf_clean_all_tx_rings(adapter);
i40evf_clean_all_rx_rings(adapter);
}
static int
i40evf_acquire_msix_vectors(struct i40evf_adapter *adapter, int vectors)
{
int err, vector_threshold;
vector_threshold = MIN_MSIX_COUNT;
while (vectors >= vector_threshold) {
err = pci_enable_msix(adapter->pdev, adapter->msix_entries,
vectors);
if (!err)
break;
else if (err < 0)
vectors = 0;
else
vectors = err;
}
if (vectors < vector_threshold) {
dev_err(&adapter->pdev->dev, "Unable to allocate MSI-X interrupts.\n");
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
err = -EIO;
} else {
adapter->num_msix_vectors = vectors;
}
return err;
}
static void i40evf_free_queues(struct i40evf_adapter *adapter)
{
int i;
if (!adapter->vsi_res)
return;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++) {
if (adapter->tx_rings[i])
kfree_rcu(adapter->tx_rings[i], rcu);
adapter->tx_rings[i] = NULL;
adapter->rx_rings[i] = NULL;
}
}
static int i40evf_alloc_queues(struct i40evf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++) {
struct i40e_ring *tx_ring;
struct i40e_ring *rx_ring;
tx_ring = kzalloc(sizeof(struct i40e_ring) * 2, GFP_KERNEL);
if (!tx_ring)
goto err_out;
tx_ring->queue_index = i;
tx_ring->netdev = adapter->netdev;
tx_ring->dev = &adapter->pdev->dev;
tx_ring->count = I40EVF_DEFAULT_TXD;
adapter->tx_rings[i] = tx_ring;
rx_ring = &tx_ring[1];
rx_ring->queue_index = i;
rx_ring->netdev = adapter->netdev;
rx_ring->dev = &adapter->pdev->dev;
rx_ring->count = I40EVF_DEFAULT_RXD;
adapter->rx_rings[i] = rx_ring;
}
return 0;
err_out:
i40evf_free_queues(adapter);
return -ENOMEM;
}
static int i40evf_set_interrupt_capability(struct i40evf_adapter *adapter)
{
int vector, v_budget;
int pairs = 0;
int err = 0;
if (!adapter->vsi_res) {
err = -EIO;
goto out;
}
pairs = adapter->vsi_res->num_queue_pairs;
v_budget = min_t(int, pairs, (int)(num_online_cpus() * 2)) + NONQ_VECS;
v_budget = min_t(int, v_budget, (int)adapter->vf_res->max_vectors);
adapter->msix_entries = kcalloc(v_budget,
sizeof(struct msix_entry), GFP_KERNEL);
if (!adapter->msix_entries) {
err = -ENOMEM;
goto out;
}
for (vector = 0; vector < v_budget; vector++)
adapter->msix_entries[vector].entry = vector;
i40evf_acquire_msix_vectors(adapter, v_budget);
out:
adapter->netdev->real_num_tx_queues = pairs;
return err;
}
static int i40evf_alloc_q_vectors(struct i40evf_adapter *adapter)
{
int q_idx, num_q_vectors;
struct i40e_q_vector *q_vector;
num_q_vectors = adapter->num_msix_vectors - NONQ_VECS;
for (q_idx = 0; q_idx < num_q_vectors; q_idx++) {
q_vector = kzalloc(sizeof(struct i40e_q_vector), GFP_KERNEL);
if (!q_vector)
goto err_out;
q_vector->adapter = adapter;
q_vector->vsi = &adapter->vsi;
q_vector->v_idx = q_idx;
netif_napi_add(adapter->netdev, &q_vector->napi,
i40evf_napi_poll, 64);
adapter->q_vector[q_idx] = q_vector;
}
return 0;
err_out:
while (q_idx) {
q_idx--;
q_vector = adapter->q_vector[q_idx];
netif_napi_del(&q_vector->napi);
kfree(q_vector);
adapter->q_vector[q_idx] = NULL;
}
return -ENOMEM;
}
static void i40evf_free_q_vectors(struct i40evf_adapter *adapter)
{
int q_idx, num_q_vectors;
int napi_vectors;
num_q_vectors = adapter->num_msix_vectors - NONQ_VECS;
napi_vectors = adapter->vsi_res->num_queue_pairs;
for (q_idx = 0; q_idx < num_q_vectors; q_idx++) {
struct i40e_q_vector *q_vector = adapter->q_vector[q_idx];
adapter->q_vector[q_idx] = NULL;
if (q_idx < napi_vectors)
netif_napi_del(&q_vector->napi);
kfree(q_vector);
}
}
void i40evf_reset_interrupt_capability(struct i40evf_adapter *adapter)
{
pci_disable_msix(adapter->pdev);
kfree(adapter->msix_entries);
adapter->msix_entries = NULL;
return;
}
int i40evf_init_interrupt_scheme(struct i40evf_adapter *adapter)
{
int err;
err = i40evf_set_interrupt_capability(adapter);
if (err) {
dev_err(&adapter->pdev->dev,
"Unable to setup interrupt capabilities\n");
goto err_set_interrupt;
}
err = i40evf_alloc_q_vectors(adapter);
if (err) {
dev_err(&adapter->pdev->dev,
"Unable to allocate memory for queue vectors\n");
goto err_alloc_q_vectors;
}
err = i40evf_alloc_queues(adapter);
if (err) {
dev_err(&adapter->pdev->dev,
"Unable to allocate memory for queues\n");
goto err_alloc_queues;
}
dev_info(&adapter->pdev->dev, "Multiqueue %s: Queue pair count = %u",
(adapter->vsi_res->num_queue_pairs > 1) ? "Enabled" :
"Disabled", adapter->vsi_res->num_queue_pairs);
return 0;
err_alloc_queues:
i40evf_free_q_vectors(adapter);
err_alloc_q_vectors:
i40evf_reset_interrupt_capability(adapter);
err_set_interrupt:
return err;
}
static void i40evf_watchdog_timer(unsigned long data)
{
struct i40evf_adapter *adapter = (struct i40evf_adapter *)data;
schedule_work(&adapter->watchdog_task);
}
static void i40evf_watchdog_task(struct work_struct *work)
{
struct i40evf_adapter *adapter = container_of(work,
struct i40evf_adapter,
watchdog_task);
struct i40e_hw *hw = &adapter->hw;
if (test_and_set_bit(__I40EVF_IN_CRITICAL_TASK, &adapter->crit_section))
goto restart_watchdog;
if (adapter->flags & I40EVF_FLAG_PF_COMMS_FAILED) {
dev_info(&adapter->pdev->dev, "Checking for redemption\n");
if ((rd32(hw, I40E_VFGEN_RSTAT) & 0x3) == I40E_VFR_VFACTIVE) {
dev_err(&adapter->pdev->dev, "Hardware came out of reset. Attempting reinit.\n");
adapter->state = __I40EVF_STARTUP;
adapter->flags &= ~I40EVF_FLAG_PF_COMMS_FAILED;
schedule_delayed_work(&adapter->init_task, 10);
clear_bit(__I40EVF_IN_CRITICAL_TASK,
&adapter->crit_section);
return;
}
adapter->aq_pending = 0;
adapter->aq_required = 0;
adapter->current_op = I40E_VIRTCHNL_OP_UNKNOWN;
goto watchdog_done;
}
if ((adapter->state < __I40EVF_DOWN) ||
(adapter->flags & I40EVF_FLAG_RESET_PENDING))
goto watchdog_done;
if (!(adapter->flags & I40EVF_FLAG_RESET_PENDING) &&
(rd32(hw, I40E_VFGEN_RSTAT) & 0x3) != I40E_VFR_VFACTIVE) {
adapter->state = __I40EVF_RESETTING;
adapter->flags |= I40EVF_FLAG_RESET_PENDING;
dev_err(&adapter->pdev->dev, "Hardware reset detected.\n");
dev_info(&adapter->pdev->dev, "Scheduling reset task\n");
schedule_work(&adapter->reset_task);
adapter->aq_pending = 0;
adapter->aq_required = 0;
adapter->current_op = I40E_VIRTCHNL_OP_UNKNOWN;
goto watchdog_done;
}
if (adapter->aq_pending)
goto watchdog_done;
if (adapter->aq_required & I40EVF_FLAG_AQ_MAP_VECTORS) {
i40evf_map_queues(adapter);
goto watchdog_done;
}
if (adapter->aq_required & I40EVF_FLAG_AQ_ADD_MAC_FILTER) {
i40evf_add_ether_addrs(adapter);
goto watchdog_done;
}
if (adapter->aq_required & I40EVF_FLAG_AQ_ADD_VLAN_FILTER) {
i40evf_add_vlans(adapter);
goto watchdog_done;
}
if (adapter->aq_required & I40EVF_FLAG_AQ_DEL_MAC_FILTER) {
i40evf_del_ether_addrs(adapter);
goto watchdog_done;
}
if (adapter->aq_required & I40EVF_FLAG_AQ_DEL_VLAN_FILTER) {
i40evf_del_vlans(adapter);
goto watchdog_done;
}
if (adapter->aq_required & I40EVF_FLAG_AQ_DISABLE_QUEUES) {
i40evf_disable_queues(adapter);
goto watchdog_done;
}
if (adapter->aq_required & I40EVF_FLAG_AQ_CONFIGURE_QUEUES) {
i40evf_configure_queues(adapter);
goto watchdog_done;
}
if (adapter->aq_required & I40EVF_FLAG_AQ_ENABLE_QUEUES) {
i40evf_enable_queues(adapter);
goto watchdog_done;
}
if (adapter->state == __I40EVF_RUNNING)
i40evf_request_stats(adapter);
i40evf_irq_enable(adapter, true);
i40evf_fire_sw_int(adapter, 0xFF);
watchdog_done:
clear_bit(__I40EVF_IN_CRITICAL_TASK, &adapter->crit_section);
restart_watchdog:
if (adapter->aq_required)
mod_timer(&adapter->watchdog_timer,
jiffies + msecs_to_jiffies(20));
else
mod_timer(&adapter->watchdog_timer, jiffies + (HZ * 2));
schedule_work(&adapter->adminq_task);
}
static int next_queue(struct i40evf_adapter *adapter, int j)
{
j += 1;
return j >= adapter->vsi_res->num_queue_pairs ? 0 : j;
}
static void i40evf_configure_rss(struct i40evf_adapter *adapter)
{
struct i40e_hw *hw = &adapter->hw;
u32 lut = 0;
int i, j;
u64 hena;
static const u32 seed[I40E_VFQF_HKEY_MAX_INDEX + 1] = {
0x794221b4, 0xbca0c5ab, 0x6cd5ebd9, 0x1ada6127,
0x983b3aa1, 0x1c4e71eb, 0x7f6328b2, 0xfcdc0da0,
0xc135cafa, 0x7a6f7e2d, 0xe7102d28, 0x163cd12e,
0x4954b126 };
for (i = 0; i <= I40E_VFQF_HKEY_MAX_INDEX; i++)
wr32(hw, I40E_VFQF_HKEY(i), seed[i]);
hena = I40E_DEFAULT_RSS_HENA;
wr32(hw, I40E_VFQF_HENA(0), (u32)hena);
wr32(hw, I40E_VFQF_HENA(1), (u32)(hena >> 32));
j = adapter->vsi_res->num_queue_pairs;
for (i = 0; i <= I40E_VFQF_HLUT_MAX_INDEX; i++) {
j = next_queue(adapter, j);
lut = j;
j = next_queue(adapter, j);
lut |= j << 8;
j = next_queue(adapter, j);
lut |= j << 16;
j = next_queue(adapter, j);
lut |= j << 24;
wr32(hw, I40E_VFQF_HLUT(i), lut);
}
i40e_flush(hw);
}
static void i40evf_reset_task(struct work_struct *work)
{
struct i40evf_adapter *adapter = container_of(work,
struct i40evf_adapter,
reset_task);
struct i40e_hw *hw = &adapter->hw;
int i = 0, err;
uint32_t rstat_val;
while (test_and_set_bit(__I40EVF_IN_CRITICAL_TASK,
&adapter->crit_section))
udelay(500);
if (adapter->flags & I40EVF_FLAG_RESET_NEEDED) {
dev_info(&adapter->pdev->dev, "Requesting reset from PF\n");
i40evf_request_reset(adapter);
}
for (i = 0; i < I40EVF_RESET_WAIT_COUNT; i++) {
rstat_val = rd32(hw, I40E_VFGEN_RSTAT) &
I40E_VFGEN_RSTAT_VFR_STATE_MASK;
if (rstat_val != I40E_VFR_VFACTIVE) {
dev_info(&adapter->pdev->dev, "Reset now occurring\n");
break;
} else {
msleep(I40EVF_RESET_WAIT_MS);
}
}
if (i == I40EVF_RESET_WAIT_COUNT) {
dev_err(&adapter->pdev->dev, "Reset was not detected\n");
adapter->flags &= ~I40EVF_FLAG_RESET_PENDING;
goto continue_reset;
}
for (i = 0; i < I40EVF_RESET_WAIT_COUNT; i++) {
rstat_val = rd32(hw, I40E_VFGEN_RSTAT) &
I40E_VFGEN_RSTAT_VFR_STATE_MASK;
if (rstat_val == I40E_VFR_VFACTIVE) {
dev_info(&adapter->pdev->dev, "Reset is complete. Reinitializing.\n");
break;
} else {
msleep(I40EVF_RESET_WAIT_MS);
}
}
if (i == I40EVF_RESET_WAIT_COUNT) {
dev_err(&adapter->pdev->dev, "Reset never finished (%x). PF driver is dead, and so am I.\n",
rstat_val);
adapter->flags |= I40EVF_FLAG_PF_COMMS_FAILED;
if (netif_running(adapter->netdev))
i40evf_close(adapter->netdev);
i40evf_free_misc_irq(adapter);
i40evf_reset_interrupt_capability(adapter);
i40evf_free_queues(adapter);
kfree(adapter->vf_res);
i40evf_shutdown_adminq(hw);
adapter->netdev->flags &= ~IFF_UP;
clear_bit(__I40EVF_IN_CRITICAL_TASK, &adapter->crit_section);
return;
}
continue_reset:
adapter->flags &= ~I40EVF_FLAG_RESET_PENDING;
i40evf_down(adapter);
adapter->state = __I40EVF_RESETTING;
if (i40evf_shutdown_adminq(hw))
dev_warn(&adapter->pdev->dev,
"%s: Failed to destroy the Admin Queue resources\n",
__func__);
err = i40evf_init_adminq(hw);
if (err)
dev_info(&adapter->pdev->dev, "%s: init_adminq failed: %d\n",
__func__, err);
adapter->aq_pending = 0;
adapter->aq_required = 0;
i40evf_map_queues(adapter);
clear_bit(__I40EVF_IN_CRITICAL_TASK, &adapter->crit_section);
mod_timer(&adapter->watchdog_timer, jiffies + 2);
if (netif_running(adapter->netdev)) {
err = i40evf_setup_all_tx_resources(adapter);
if (err)
goto reset_err;
err = i40evf_setup_all_rx_resources(adapter);
if (err)
goto reset_err;
i40evf_configure(adapter);
err = i40evf_up_complete(adapter);
if (err)
goto reset_err;
i40evf_irq_enable(adapter, true);
}
return;
reset_err:
dev_err(&adapter->pdev->dev, "failed to allocate resources during reinit.\n");
i40evf_close(adapter->netdev);
}
static void i40evf_adminq_task(struct work_struct *work)
{
struct i40evf_adapter *adapter =
container_of(work, struct i40evf_adapter, adminq_task);
struct i40e_hw *hw = &adapter->hw;
struct i40e_arq_event_info event;
struct i40e_virtchnl_msg *v_msg;
i40e_status ret;
u16 pending;
if (adapter->flags & I40EVF_FLAG_PF_COMMS_FAILED)
return;
event.msg_size = I40EVF_MAX_AQ_BUF_SIZE;
event.msg_buf = kzalloc(event.msg_size, GFP_KERNEL);
if (!event.msg_buf) {
dev_info(&adapter->pdev->dev, "%s: no memory for ARQ clean\n",
__func__);
return;
}
v_msg = (struct i40e_virtchnl_msg *)&event.desc;
do {
ret = i40evf_clean_arq_element(hw, &event, &pending);
if (ret)
break;
i40evf_virtchnl_completion(adapter, v_msg->v_opcode,
v_msg->v_retval, event.msg_buf,
event.msg_size);
if (pending != 0) {
dev_info(&adapter->pdev->dev,
"%s: ARQ: Pending events %d\n",
__func__, pending);
memset(event.msg_buf, 0, I40EVF_MAX_AQ_BUF_SIZE);
}
} while (pending);
i40evf_misc_irq_enable(adapter);
kfree(event.msg_buf);
}
static void i40evf_free_all_tx_resources(struct i40evf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++)
if (adapter->tx_rings[i]->desc)
i40evf_free_tx_resources(adapter->tx_rings[i]);
}
static int i40evf_setup_all_tx_resources(struct i40evf_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++) {
err = i40evf_setup_tx_descriptors(adapter->tx_rings[i]);
if (!err)
continue;
dev_err(&adapter->pdev->dev,
"%s: Allocation for Tx Queue %u failed\n",
__func__, i);
break;
}
return err;
}
static int i40evf_setup_all_rx_resources(struct i40evf_adapter *adapter)
{
int i, err = 0;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++) {
err = i40evf_setup_rx_descriptors(adapter->rx_rings[i]);
if (!err)
continue;
dev_err(&adapter->pdev->dev,
"%s: Allocation for Rx Queue %u failed\n",
__func__, i);
break;
}
return err;
}
static void i40evf_free_all_rx_resources(struct i40evf_adapter *adapter)
{
int i;
for (i = 0; i < adapter->vsi_res->num_queue_pairs; i++)
if (adapter->rx_rings[i]->desc)
i40evf_free_rx_resources(adapter->rx_rings[i]);
}
static int i40evf_open(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
int err;
if (adapter->flags & I40EVF_FLAG_PF_COMMS_FAILED) {
dev_err(&adapter->pdev->dev, "Unable to open device due to PF driver failure.\n");
return -EIO;
}
if (adapter->state != __I40EVF_DOWN)
return -EBUSY;
err = i40evf_setup_all_tx_resources(adapter);
if (err)
goto err_setup_tx;
err = i40evf_setup_all_rx_resources(adapter);
if (err)
goto err_setup_rx;
err = i40evf_request_traffic_irqs(adapter, netdev->name);
if (err)
goto err_req_irq;
i40evf_configure(adapter);
err = i40evf_up_complete(adapter);
if (err)
goto err_req_irq;
i40evf_irq_enable(adapter, true);
return 0;
err_req_irq:
i40evf_down(adapter);
i40evf_free_traffic_irqs(adapter);
err_setup_rx:
i40evf_free_all_rx_resources(adapter);
err_setup_tx:
i40evf_free_all_tx_resources(adapter);
return err;
}
static int i40evf_close(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
if (adapter->state <= __I40EVF_DOWN)
return 0;
adapter->state = __I40EVF_DOWN;
set_bit(__I40E_DOWN, &adapter->vsi.state);
i40evf_down(adapter);
i40evf_free_traffic_irqs(adapter);
i40evf_free_all_tx_resources(adapter);
i40evf_free_all_rx_resources(adapter);
return 0;
}
static struct net_device_stats *i40evf_get_stats(struct net_device *netdev)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
return &adapter->net_stats;
}
void i40evf_reinit_locked(struct i40evf_adapter *adapter)
{
struct net_device *netdev = adapter->netdev;
int err;
WARN_ON(in_interrupt());
adapter->state = __I40EVF_RESETTING;
i40evf_down(adapter);
err = i40evf_setup_all_tx_resources(adapter);
if (err)
goto err_reinit;
err = i40evf_setup_all_rx_resources(adapter);
if (err)
goto err_reinit;
i40evf_configure(adapter);
err = i40evf_up_complete(adapter);
if (err)
goto err_reinit;
i40evf_irq_enable(adapter, true);
return;
err_reinit:
dev_err(&adapter->pdev->dev, "failed to allocate resources during reinit.\n");
i40evf_close(netdev);
}
static int i40evf_change_mtu(struct net_device *netdev, int new_mtu)
{
struct i40evf_adapter *adapter = netdev_priv(netdev);
int max_frame = new_mtu + ETH_HLEN + ETH_FCS_LEN;
if ((new_mtu < 68) || (max_frame > I40E_MAX_RXBUFFER))
return -EINVAL;
netdev->mtu = new_mtu;
i40evf_reinit_locked(adapter);
return 0;
}
static int i40evf_check_reset_complete(struct i40e_hw *hw)
{
u32 rstat;
int i;
for (i = 0; i < 100; i++) {
rstat = rd32(hw, I40E_VFGEN_RSTAT);
if (rstat == I40E_VFR_VFACTIVE)
return 0;
udelay(10);
}
return -EBUSY;
}
static void i40evf_init_task(struct work_struct *work)
{
struct i40evf_adapter *adapter = container_of(work,
struct i40evf_adapter,
init_task.work);
struct net_device *netdev = adapter->netdev;
struct i40evf_mac_filter *f;
struct i40e_hw *hw = &adapter->hw;
struct pci_dev *pdev = adapter->pdev;
int i, err, bufsz;
switch (adapter->state) {
case __I40EVF_STARTUP:
adapter->flags &= ~I40EVF_FLAG_PF_COMMS_FAILED;
adapter->flags &= ~I40EVF_FLAG_RESET_PENDING;
err = i40e_set_mac_type(hw);
if (err) {
dev_err(&pdev->dev, "Failed to set MAC type (%d)\n",
err);
goto err;
}
err = i40evf_check_reset_complete(hw);
if (err) {
dev_err(&pdev->dev, "Device is still in reset (%d)\n",
err);
goto err;
}
hw->aq.num_arq_entries = I40EVF_AQ_LEN;
hw->aq.num_asq_entries = I40EVF_AQ_LEN;
hw->aq.arq_buf_size = I40EVF_MAX_AQ_BUF_SIZE;
hw->aq.asq_buf_size = I40EVF_MAX_AQ_BUF_SIZE;
err = i40evf_init_adminq(hw);
if (err) {
dev_err(&pdev->dev, "Failed to init Admin Queue (%d)\n",
err);
goto err;
}
err = i40evf_send_api_ver(adapter);
if (err) {
dev_err(&pdev->dev, "Unable to send to PF (%d)\n", err);
i40evf_shutdown_adminq(hw);
goto err;
}
adapter->state = __I40EVF_INIT_VERSION_CHECK;
goto restart;
break;
case __I40EVF_INIT_VERSION_CHECK:
if (!i40evf_asq_done(hw)) {
dev_err(&pdev->dev, "Admin queue command never completed.\n");
goto err;
}
err = i40evf_verify_api_ver(adapter);
if (err) {
dev_err(&pdev->dev, "Unable to verify API version (%d)\n",
err);
goto err;
}
err = i40evf_send_vf_config_msg(adapter);
if (err) {
dev_err(&pdev->dev, "Unable send config request (%d)\n",
err);
goto err;
}
adapter->state = __I40EVF_INIT_GET_RESOURCES;
goto restart;
break;
case __I40EVF_INIT_GET_RESOURCES:
if (!adapter->vf_res) {
bufsz = sizeof(struct i40e_virtchnl_vf_resource) +
(I40E_MAX_VF_VSI *
sizeof(struct i40e_virtchnl_vsi_resource));
adapter->vf_res = kzalloc(bufsz, GFP_KERNEL);
if (!adapter->vf_res)
goto err;
}
err = i40evf_get_vf_config(adapter);
if (err == I40E_ERR_ADMIN_QUEUE_NO_WORK)
goto restart;
if (err) {
dev_err(&pdev->dev, "Unable to get VF config (%d)\n",
err);
goto err_alloc;
}
adapter->state = __I40EVF_INIT_SW;
break;
default:
goto err_alloc;
}
for (i = 0; i < adapter->vf_res->num_vsis; i++) {
if (adapter->vf_res->vsi_res[i].vsi_type == I40E_VSI_SRIOV)
adapter->vsi_res = &adapter->vf_res->vsi_res[i];
}
if (!adapter->vsi_res) {
dev_err(&pdev->dev, "No LAN VSI found\n");
goto err_alloc;
}
adapter->flags |= I40EVF_FLAG_RX_CSUM_ENABLED;
netdev->netdev_ops = &i40evf_netdev_ops;
i40evf_set_ethtool_ops(netdev);
netdev->watchdog_timeo = 5 * HZ;
netdev->features |= NETIF_F_HIGHDMA |
NETIF_F_SG |
NETIF_F_IP_CSUM |
NETIF_F_SCTP_CSUM |
NETIF_F_IPV6_CSUM |
NETIF_F_TSO |
NETIF_F_TSO6 |
NETIF_F_RXCSUM |
NETIF_F_GRO;
if (adapter->vf_res->vf_offload_flags
& I40E_VIRTCHNL_VF_OFFLOAD_VLAN) {
netdev->vlan_features = netdev->features;
netdev->features |= NETIF_F_HW_VLAN_CTAG_TX |
NETIF_F_HW_VLAN_CTAG_RX |
NETIF_F_HW_VLAN_CTAG_FILTER;
}
netdev->hw_features |= netdev->features;
netdev->hw_features &= ~NETIF_F_RXCSUM;
if (!is_valid_ether_addr(adapter->hw.mac.addr)) {
dev_info(&pdev->dev, "Invalid MAC address %pMAC, using random\n",
adapter->hw.mac.addr);
random_ether_addr(adapter->hw.mac.addr);
}
memcpy(netdev->dev_addr, adapter->hw.mac.addr, netdev->addr_len);
memcpy(netdev->perm_addr, adapter->hw.mac.addr, netdev->addr_len);
INIT_LIST_HEAD(&adapter->mac_filter_list);
INIT_LIST_HEAD(&adapter->vlan_filter_list);
f = kzalloc(sizeof(*f), GFP_ATOMIC);
if (NULL == f)
goto err_sw_init;
memcpy(f->macaddr, adapter->hw.mac.addr, ETH_ALEN);
f->add = true;
adapter->aq_required |= I40EVF_FLAG_AQ_ADD_MAC_FILTER;
list_add(&f->list, &adapter->mac_filter_list);
init_timer(&adapter->watchdog_timer);
adapter->watchdog_timer.function = &i40evf_watchdog_timer;
adapter->watchdog_timer.data = (unsigned long)adapter;
mod_timer(&adapter->watchdog_timer, jiffies + 1);
err = i40evf_init_interrupt_scheme(adapter);
if (err)
goto err_sw_init;
i40evf_map_rings_to_vectors(adapter);
i40evf_configure_rss(adapter);
err = i40evf_request_misc_irq(adapter);
if (err)
goto err_sw_init;
netif_carrier_off(netdev);
adapter->vsi.id = adapter->vsi_res->vsi_id;
adapter->vsi.seid = adapter->vsi_res->vsi_id;
adapter->vsi.back = adapter;
adapter->vsi.base_vector = 1;
adapter->vsi.work_limit = I40E_DEFAULT_IRQ_WORK;
adapter->vsi.rx_itr_setting = I40E_ITR_DYNAMIC;
adapter->vsi.tx_itr_setting = I40E_ITR_DYNAMIC;
adapter->vsi.netdev = adapter->netdev;
if (!adapter->netdev_registered) {
err = register_netdev(netdev);
if (err)
goto err_register;
}
adapter->netdev_registered = true;
netif_tx_stop_all_queues(netdev);
dev_info(&pdev->dev, "MAC address: %pMAC\n", adapter->hw.mac.addr);
if (netdev->features & NETIF_F_GRO)
dev_info(&pdev->dev, "GRO is enabled\n");
dev_info(&pdev->dev, "%s\n", i40evf_driver_string);
adapter->state = __I40EVF_DOWN;
set_bit(__I40E_DOWN, &adapter->vsi.state);
i40evf_misc_irq_enable(adapter);
return;
restart:
schedule_delayed_work(&adapter->init_task,
msecs_to_jiffies(50));
return;
err_register:
i40evf_free_misc_irq(adapter);
err_sw_init:
i40evf_reset_interrupt_capability(adapter);
err_alloc:
kfree(adapter->vf_res);
adapter->vf_res = NULL;
err:
if (++adapter->aq_wait_count > I40EVF_AQ_MAX_ERR) {
dev_err(&pdev->dev, "Failed to communicate with PF; giving up.\n");
adapter->flags |= I40EVF_FLAG_PF_COMMS_FAILED;
return;
}
schedule_delayed_work(&adapter->init_task, HZ * 3);
return;
}
static void i40evf_shutdown(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
netif_device_detach(netdev);
if (netif_running(netdev))
i40evf_close(netdev);
#ifdef CONFIG_PM
pci_save_state(pdev);
#endif
pci_disable_device(pdev);
}
static int i40evf_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct net_device *netdev;
struct i40evf_adapter *adapter = NULL;
struct i40e_hw *hw = NULL;
int err;
err = pci_enable_device(pdev);
if (err)
return err;
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(64));
if (err) {
err = dma_set_mask_and_coherent(&pdev->dev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev,
"DMA configuration failed: 0x%x\n", err);
goto err_dma;
}
}
err = pci_request_regions(pdev, i40evf_driver_name);
if (err) {
dev_err(&pdev->dev,
"pci_request_regions failed 0x%x\n", err);
goto err_pci_reg;
}
pci_enable_pcie_error_reporting(pdev);
pci_set_master(pdev);
netdev = alloc_etherdev_mq(sizeof(struct i40evf_adapter),
MAX_TX_QUEUES);
if (!netdev) {
err = -ENOMEM;
goto err_alloc_etherdev;
}
SET_NETDEV_DEV(netdev, &pdev->dev);
pci_set_drvdata(pdev, netdev);
adapter = netdev_priv(netdev);
adapter->netdev = netdev;
adapter->pdev = pdev;
hw = &adapter->hw;
hw->back = adapter;
adapter->msg_enable = (1 << DEFAULT_DEBUG_LEVEL_SHIFT) - 1;
adapter->state = __I40EVF_STARTUP;
pci_save_state(pdev);
hw->hw_addr = ioremap(pci_resource_start(pdev, 0),
pci_resource_len(pdev, 0));
if (!hw->hw_addr) {
err = -EIO;
goto err_ioremap;
}
hw->vendor_id = pdev->vendor;
hw->device_id = pdev->device;
pci_read_config_byte(pdev, PCI_REVISION_ID, &hw->revision_id);
hw->subsystem_vendor_id = pdev->subsystem_vendor;
hw->subsystem_device_id = pdev->subsystem_device;
hw->bus.device = PCI_SLOT(pdev->devfn);
hw->bus.func = PCI_FUNC(pdev->devfn);
INIT_WORK(&adapter->reset_task, i40evf_reset_task);
INIT_WORK(&adapter->adminq_task, i40evf_adminq_task);
INIT_WORK(&adapter->watchdog_task, i40evf_watchdog_task);
INIT_DELAYED_WORK(&adapter->init_task, i40evf_init_task);
schedule_delayed_work(&adapter->init_task, 10);
return 0;
err_ioremap:
free_netdev(netdev);
err_alloc_etherdev:
pci_release_regions(pdev);
err_pci_reg:
err_dma:
pci_disable_device(pdev);
return err;
}
static int i40evf_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct i40evf_adapter *adapter = netdev_priv(netdev);
int retval = 0;
netif_device_detach(netdev);
if (netif_running(netdev)) {
rtnl_lock();
i40evf_down(adapter);
rtnl_unlock();
}
i40evf_free_misc_irq(adapter);
i40evf_reset_interrupt_capability(adapter);
retval = pci_save_state(pdev);
if (retval)
return retval;
pci_disable_device(pdev);
return 0;
}
static int i40evf_resume(struct pci_dev *pdev)
{
struct i40evf_adapter *adapter = pci_get_drvdata(pdev);
struct net_device *netdev = adapter->netdev;
u32 err;
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
pci_save_state(pdev);
err = pci_enable_device_mem(pdev);
if (err) {
dev_err(&pdev->dev, "Cannot enable PCI device from suspend.\n");
return err;
}
pci_set_master(pdev);
rtnl_lock();
err = i40evf_set_interrupt_capability(adapter);
if (err) {
dev_err(&pdev->dev, "Cannot enable MSI-X interrupts.\n");
return err;
}
err = i40evf_request_misc_irq(adapter);
rtnl_unlock();
if (err) {
dev_err(&pdev->dev, "Cannot get interrupt vector.\n");
return err;
}
schedule_work(&adapter->reset_task);
netif_device_attach(netdev);
return err;
}
static void i40evf_remove(struct pci_dev *pdev)
{
struct net_device *netdev = pci_get_drvdata(pdev);
struct i40evf_adapter *adapter = netdev_priv(netdev);
struct i40e_hw *hw = &adapter->hw;
cancel_delayed_work_sync(&adapter->init_task);
cancel_work_sync(&adapter->reset_task);
if (adapter->netdev_registered) {
unregister_netdev(netdev);
adapter->netdev_registered = false;
}
adapter->state = __I40EVF_REMOVE;
if (adapter->msix_entries) {
i40evf_misc_irq_disable(adapter);
i40evf_free_misc_irq(adapter);
i40evf_reset_interrupt_capability(adapter);
}
del_timer_sync(&adapter->watchdog_timer);
flush_scheduled_work();
if (hw->aq.asq.count)
i40evf_shutdown_adminq(hw);
iounmap(hw->hw_addr);
pci_release_regions(pdev);
i40evf_free_queues(adapter);
kfree(adapter->vf_res);
free_netdev(netdev);
pci_disable_pcie_error_reporting(pdev);
pci_disable_device(pdev);
}
static int __init i40evf_init_module(void)
{
int ret;
pr_info("i40evf: %s - version %s\n", i40evf_driver_string,
i40evf_driver_version);
pr_info("%s\n", i40evf_copyright);
ret = pci_register_driver(&i40evf_driver);
return ret;
}
static void __exit i40evf_exit_module(void)
{
pci_unregister_driver(&i40evf_driver);
}
