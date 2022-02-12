static void cvm_oct_rx_refill_worker(struct work_struct *work)
{
cvm_oct_rx_refill_pool(num_packet_buffers / 2);
if (!atomic_read(&cvm_oct_poll_queue_stopping))
schedule_delayed_work(&cvm_oct_rx_refill_work, HZ);
}
static void cvm_oct_periodic_worker(struct work_struct *work)
{
struct octeon_ethernet *priv = container_of(work,
struct octeon_ethernet,
port_periodic_work.work);
if (priv->poll)
priv->poll(cvm_oct_device[priv->port]);
cvm_oct_device[priv->port]->netdev_ops->ndo_get_stats(
cvm_oct_device[priv->port]);
if (!atomic_read(&cvm_oct_poll_queue_stopping))
schedule_delayed_work(&priv->port_periodic_work, HZ);
}
static void cvm_oct_configure_common_hw(void)
{
cvmx_fpa_enable();
cvm_oct_mem_fill_fpa(CVMX_FPA_PACKET_POOL, CVMX_FPA_PACKET_POOL_SIZE,
num_packet_buffers);
cvm_oct_mem_fill_fpa(CVMX_FPA_WQE_POOL, CVMX_FPA_WQE_POOL_SIZE,
num_packet_buffers);
if (CVMX_FPA_OUTPUT_BUFFER_POOL != CVMX_FPA_PACKET_POOL)
cvm_oct_mem_fill_fpa(CVMX_FPA_OUTPUT_BUFFER_POOL,
CVMX_FPA_OUTPUT_BUFFER_POOL_SIZE, 1024);
#ifdef __LITTLE_ENDIAN
{
union cvmx_ipd_ctl_status ipd_ctl_status;
ipd_ctl_status.u64 = cvmx_read_csr(CVMX_IPD_CTL_STATUS);
ipd_ctl_status.s.pkt_lend = 1;
ipd_ctl_status.s.wqe_lend = 1;
cvmx_write_csr(CVMX_IPD_CTL_STATUS, ipd_ctl_status.u64);
}
#endif
cvmx_helper_setup_red(num_packet_buffers / 4, num_packet_buffers / 8);
}
int cvm_oct_free_work(void *work_queue_entry)
{
cvmx_wqe_t *work = work_queue_entry;
int segments = work->word2.s.bufs;
union cvmx_buf_ptr segment_ptr = work->packet_ptr;
while (segments--) {
union cvmx_buf_ptr next_ptr = *(union cvmx_buf_ptr *)
cvmx_phys_to_ptr(segment_ptr.s.addr - 8);
if (unlikely(!segment_ptr.s.i))
cvmx_fpa_free(cvm_oct_get_buffer_ptr(segment_ptr),
segment_ptr.s.pool,
CVMX_FPA_PACKET_POOL_SIZE / 128);
segment_ptr = next_ptr;
}
cvmx_fpa_free(work, CVMX_FPA_WQE_POOL, 1);
return 0;
}
static struct net_device_stats *cvm_oct_common_get_stats(struct net_device *dev)
{
cvmx_pip_port_status_t rx_status;
cvmx_pko_port_status_t tx_status;
struct octeon_ethernet *priv = netdev_priv(dev);
if (priv->port < CVMX_PIP_NUM_INPUT_PORTS) {
if (octeon_is_simulation()) {
memset(&rx_status, 0, sizeof(rx_status));
memset(&tx_status, 0, sizeof(tx_status));
} else {
cvmx_pip_get_port_status(priv->port, 1, &rx_status);
cvmx_pko_get_port_status(priv->port, 1, &tx_status);
}
priv->stats.rx_packets += rx_status.inb_packets;
priv->stats.tx_packets += tx_status.packets;
priv->stats.rx_bytes += rx_status.inb_octets;
priv->stats.tx_bytes += tx_status.octets;
priv->stats.multicast += rx_status.multicast_packets;
priv->stats.rx_crc_errors += rx_status.inb_errors;
priv->stats.rx_frame_errors += rx_status.fcs_align_err_packets;
priv->stats.rx_dropped += rx_status.dropped_packets;
}
return &priv->stats;
}
static int cvm_oct_common_change_mtu(struct net_device *dev, int new_mtu)
{
struct octeon_ethernet *priv = netdev_priv(dev);
int interface = INTERFACE(priv->port);
#if IS_ENABLED(CONFIG_VLAN_8021Q)
int vlan_bytes = VLAN_HLEN;
#else
int vlan_bytes = 0;
#endif
int mtu_overhead = ETH_HLEN + ETH_FCS_LEN + vlan_bytes;
if ((new_mtu + mtu_overhead < VLAN_ETH_ZLEN) ||
(new_mtu + mtu_overhead > OCTEON_MAX_MTU)) {
pr_err("MTU must be between %d and %d.\n",
VLAN_ETH_ZLEN - mtu_overhead,
OCTEON_MAX_MTU - mtu_overhead);
return -EINVAL;
}
dev->mtu = new_mtu;
if ((interface < 2) &&
(cvmx_helper_interface_get_mode(interface) !=
CVMX_HELPER_INTERFACE_MODE_SPI)) {
int index = INDEX(priv->port);
int max_packet = new_mtu + mtu_overhead;
if (OCTEON_IS_MODEL(OCTEON_CN3XXX) ||
OCTEON_IS_MODEL(OCTEON_CN58XX)) {
cvmx_write_csr(CVMX_GMXX_RXX_FRM_MAX(index, interface),
max_packet);
} else {
union cvmx_pip_frm_len_chkx frm_len_chk;
frm_len_chk.u64 = 0;
frm_len_chk.s.minlen = VLAN_ETH_ZLEN;
frm_len_chk.s.maxlen = max_packet;
cvmx_write_csr(CVMX_PIP_FRM_LEN_CHKX(interface),
frm_len_chk.u64);
}
cvmx_write_csr(CVMX_GMXX_RXX_JABBER(index, interface),
(max_packet + 7) & ~7u);
}
return 0;
}
static void cvm_oct_common_set_multicast_list(struct net_device *dev)
{
union cvmx_gmxx_prtx_cfg gmx_cfg;
struct octeon_ethernet *priv = netdev_priv(dev);
int interface = INTERFACE(priv->port);
if ((interface < 2) &&
(cvmx_helper_interface_get_mode(interface) !=
CVMX_HELPER_INTERFACE_MODE_SPI)) {
union cvmx_gmxx_rxx_adr_ctl control;
int index = INDEX(priv->port);
control.u64 = 0;
control.s.bcst = 1;
if (!netdev_mc_empty(dev) || (dev->flags & IFF_ALLMULTI) ||
(dev->flags & IFF_PROMISC))
control.s.mcst = 2;
else
control.s.mcst = 1;
if (dev->flags & IFF_PROMISC)
control.s.cam_mode = 0;
else
control.s.cam_mode = 1;
gmx_cfg.u64 =
cvmx_read_csr(CVMX_GMXX_PRTX_CFG(index, interface));
cvmx_write_csr(CVMX_GMXX_PRTX_CFG(index, interface),
gmx_cfg.u64 & ~1ull);
cvmx_write_csr(CVMX_GMXX_RXX_ADR_CTL(index, interface),
control.u64);
if (dev->flags & IFF_PROMISC)
cvmx_write_csr(CVMX_GMXX_RXX_ADR_CAM_EN
(index, interface), 0);
else
cvmx_write_csr(CVMX_GMXX_RXX_ADR_CAM_EN
(index, interface), 1);
cvmx_write_csr(CVMX_GMXX_PRTX_CFG(index, interface),
gmx_cfg.u64);
}
}
static int cvm_oct_set_mac_filter(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
union cvmx_gmxx_prtx_cfg gmx_cfg;
int interface = INTERFACE(priv->port);
if ((interface < 2) &&
(cvmx_helper_interface_get_mode(interface) !=
CVMX_HELPER_INTERFACE_MODE_SPI)) {
int i;
u8 *ptr = dev->dev_addr;
u64 mac = 0;
int index = INDEX(priv->port);
for (i = 0; i < 6; i++)
mac = (mac << 8) | (u64)ptr[i];
gmx_cfg.u64 =
cvmx_read_csr(CVMX_GMXX_PRTX_CFG(index, interface));
cvmx_write_csr(CVMX_GMXX_PRTX_CFG(index, interface),
gmx_cfg.u64 & ~1ull);
cvmx_write_csr(CVMX_GMXX_SMACX(index, interface), mac);
cvmx_write_csr(CVMX_GMXX_RXX_ADR_CAM0(index, interface),
ptr[0]);
cvmx_write_csr(CVMX_GMXX_RXX_ADR_CAM1(index, interface),
ptr[1]);
cvmx_write_csr(CVMX_GMXX_RXX_ADR_CAM2(index, interface),
ptr[2]);
cvmx_write_csr(CVMX_GMXX_RXX_ADR_CAM3(index, interface),
ptr[3]);
cvmx_write_csr(CVMX_GMXX_RXX_ADR_CAM4(index, interface),
ptr[4]);
cvmx_write_csr(CVMX_GMXX_RXX_ADR_CAM5(index, interface),
ptr[5]);
cvm_oct_common_set_multicast_list(dev);
cvmx_write_csr(CVMX_GMXX_PRTX_CFG(index, interface),
gmx_cfg.u64);
}
return 0;
}
static int cvm_oct_common_set_mac_address(struct net_device *dev, void *addr)
{
int r = eth_mac_addr(dev, addr);
if (r)
return r;
return cvm_oct_set_mac_filter(dev);
}
int cvm_oct_common_init(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
const u8 *mac = NULL;
if (priv->of_node)
mac = of_get_mac_address(priv->of_node);
if (mac)
ether_addr_copy(dev->dev_addr, mac);
else
eth_hw_addr_random(dev);
if ((pow_send_group != -1) &&
(always_use_pow || strstr(pow_send_list, dev->name)))
priv->queue = -1;
if (priv->queue != -1)
dev->features |= NETIF_F_SG | NETIF_F_IP_CSUM;
dev->features |= NETIF_F_LLTX;
dev->ethtool_ops = &cvm_oct_ethtool_ops;
cvm_oct_set_mac_filter(dev);
dev->netdev_ops->ndo_change_mtu(dev, dev->mtu);
memset(dev->netdev_ops->ndo_get_stats(dev), 0,
sizeof(struct net_device_stats));
if (dev->netdev_ops->ndo_stop)
dev->netdev_ops->ndo_stop(dev);
return 0;
}
void cvm_oct_common_uninit(struct net_device *dev)
{
if (dev->phydev)
phy_disconnect(dev->phydev);
}
int cvm_oct_common_open(struct net_device *dev,
void (*link_poll)(struct net_device *))
{
union cvmx_gmxx_prtx_cfg gmx_cfg;
struct octeon_ethernet *priv = netdev_priv(dev);
int interface = INTERFACE(priv->port);
int index = INDEX(priv->port);
cvmx_helper_link_info_t link_info;
int rv;
rv = cvm_oct_phy_setup_device(dev);
if (rv)
return rv;
gmx_cfg.u64 = cvmx_read_csr(CVMX_GMXX_PRTX_CFG(index, interface));
gmx_cfg.s.en = 1;
if (octeon_has_feature(OCTEON_FEATURE_PKND))
gmx_cfg.s.pknd = priv->port;
cvmx_write_csr(CVMX_GMXX_PRTX_CFG(index, interface), gmx_cfg.u64);
if (octeon_is_simulation())
return 0;
if (dev->phydev) {
int r = phy_read_status(dev->phydev);
if (r == 0 && dev->phydev->link == 0)
netif_carrier_off(dev);
cvm_oct_adjust_link(dev);
} else {
link_info = cvmx_helper_link_get(priv->port);
if (!link_info.s.link_up)
netif_carrier_off(dev);
priv->poll = link_poll;
link_poll(dev);
}
return 0;
}
void cvm_oct_link_poll(struct net_device *dev)
{
struct octeon_ethernet *priv = netdev_priv(dev);
cvmx_helper_link_info_t link_info;
link_info = cvmx_helper_link_get(priv->port);
if (link_info.u64 == priv->link_info)
return;
if (cvmx_helper_link_set(priv->port, link_info))
link_info.u64 = priv->link_info;
else
priv->link_info = link_info.u64;
if (link_info.s.link_up) {
if (!netif_carrier_ok(dev))
netif_carrier_on(dev);
} else if (netif_carrier_ok(dev)) {
netif_carrier_off(dev);
}
cvm_oct_note_carrier(priv, link_info);
}
static int cvm_oct_xaui_open(struct net_device *dev)
{
return cvm_oct_common_open(dev, cvm_oct_link_poll);
}
static struct device_node *cvm_oct_of_get_child(
const struct device_node *parent, int reg_val)
{
struct device_node *node = NULL;
int size;
const __be32 *addr;
for (;;) {
node = of_get_next_child(parent, node);
if (!node)
break;
addr = of_get_property(node, "reg", &size);
if (addr && (be32_to_cpu(*addr) == reg_val))
break;
}
return node;
}
static struct device_node *cvm_oct_node_for_port(struct device_node *pip,
int interface, int port)
{
struct device_node *ni, *np;
ni = cvm_oct_of_get_child(pip, interface);
if (!ni)
return NULL;
np = cvm_oct_of_get_child(ni, port);
of_node_put(ni);
return np;
}
static void cvm_set_rgmii_delay(struct device_node *np, int iface, int port)
{
u32 delay_value;
if (!of_property_read_u32(np, "rx-delay", &delay_value))
cvmx_write_csr(CVMX_ASXX_RX_CLK_SETX(port, iface), delay_value);
if (!of_property_read_u32(np, "tx-delay", &delay_value))
cvmx_write_csr(CVMX_ASXX_TX_CLK_SETX(port, iface), delay_value);
}
static int cvm_oct_probe(struct platform_device *pdev)
{
int num_interfaces;
int interface;
int fau = FAU_NUM_PACKET_BUFFERS_TO_FREE;
int qos;
struct device_node *pip;
octeon_mdiobus_force_mod_depencency();
pip = pdev->dev.of_node;
if (!pip) {
pr_err("Error: No 'pip' in /aliases\n");
return -EINVAL;
}
cvm_oct_configure_common_hw();
cvmx_helper_initialize_packet_io_global();
if (receive_group_order) {
if (receive_group_order > 4)
receive_group_order = 4;
pow_receive_groups = (1 << (1 << receive_group_order)) - 1;
} else {
pow_receive_groups = BIT(pow_receive_group);
}
num_interfaces = cvmx_helper_get_number_of_interfaces();
for (interface = 0; interface < num_interfaces; interface++) {
int num_ports = cvmx_helper_ports_on_interface(interface);
int port;
for (port = cvmx_helper_get_ipd_port(interface, 0);
port < cvmx_helper_get_ipd_port(interface, num_ports);
port++) {
union cvmx_pip_prt_tagx pip_prt_tagx;
pip_prt_tagx.u64 =
cvmx_read_csr(CVMX_PIP_PRT_TAGX(port));
if (receive_group_order) {
int tag_mask;
if (OCTEON_IS_MODEL(OCTEON_CN68XX))
pip_prt_tagx.u64 |= 0x3ull << 44;
tag_mask = ~((1 << receive_group_order) - 1);
pip_prt_tagx.s.grptagbase = 0;
pip_prt_tagx.s.grptagmask = tag_mask;
pip_prt_tagx.s.grptag = 1;
pip_prt_tagx.s.tag_mode = 0;
pip_prt_tagx.s.inc_prt_flag = 1;
pip_prt_tagx.s.ip6_dprt_flag = 1;
pip_prt_tagx.s.ip4_dprt_flag = 1;
pip_prt_tagx.s.ip6_sprt_flag = 1;
pip_prt_tagx.s.ip4_sprt_flag = 1;
pip_prt_tagx.s.ip6_dst_flag = 1;
pip_prt_tagx.s.ip4_dst_flag = 1;
pip_prt_tagx.s.ip6_src_flag = 1;
pip_prt_tagx.s.ip4_src_flag = 1;
pip_prt_tagx.s.grp = 0;
} else {
pip_prt_tagx.s.grptag = 0;
pip_prt_tagx.s.grp = pow_receive_group;
}
cvmx_write_csr(CVMX_PIP_PRT_TAGX(port),
pip_prt_tagx.u64);
}
}
cvmx_helper_ipd_and_packet_input_enable();
memset(cvm_oct_device, 0, sizeof(cvm_oct_device));
cvmx_fau_atomic_write32(FAU_NUM_PACKET_BUFFERS_TO_FREE, 0);
cvmx_fau_atomic_write32(FAU_TOTAL_TX_TO_CLEAN, 0);
if ((pow_send_group != -1)) {
struct net_device *dev;
dev = alloc_etherdev(sizeof(struct octeon_ethernet));
if (dev) {
struct octeon_ethernet *priv = netdev_priv(dev);
dev->netdev_ops = &cvm_oct_pow_netdev_ops;
priv->imode = CVMX_HELPER_INTERFACE_MODE_DISABLED;
priv->port = CVMX_PIP_NUM_INPUT_PORTS;
priv->queue = -1;
strcpy(dev->name, "pow%d");
for (qos = 0; qos < 16; qos++)
skb_queue_head_init(&priv->tx_free_list[qos]);
if (register_netdev(dev) < 0) {
pr_err("Failed to register ethernet device for POW\n");
free_netdev(dev);
} else {
cvm_oct_device[CVMX_PIP_NUM_INPUT_PORTS] = dev;
pr_info("%s: POW send group %d, receive group %d\n",
dev->name, pow_send_group,
pow_receive_group);
}
} else {
pr_err("Failed to allocate ethernet device for POW\n");
}
}
num_interfaces = cvmx_helper_get_number_of_interfaces();
for (interface = 0; interface < num_interfaces; interface++) {
cvmx_helper_interface_mode_t imode =
cvmx_helper_interface_get_mode(interface);
int num_ports = cvmx_helper_ports_on_interface(interface);
int port;
int port_index;
for (port_index = 0,
port = cvmx_helper_get_ipd_port(interface, 0);
port < cvmx_helper_get_ipd_port(interface, num_ports);
port_index++, port++) {
struct octeon_ethernet *priv;
struct net_device *dev =
alloc_etherdev(sizeof(struct octeon_ethernet));
if (!dev) {
pr_err("Failed to allocate ethernet device for port %d\n",
port);
continue;
}
priv = netdev_priv(dev);
priv->netdev = dev;
priv->of_node = cvm_oct_node_for_port(pip, interface,
port_index);
INIT_DELAYED_WORK(&priv->port_periodic_work,
cvm_oct_periodic_worker);
priv->imode = imode;
priv->port = port;
priv->queue = cvmx_pko_get_base_queue(priv->port);
priv->fau = fau - cvmx_pko_get_num_queues(port) * 4;
for (qos = 0; qos < 16; qos++)
skb_queue_head_init(&priv->tx_free_list[qos]);
for (qos = 0; qos < cvmx_pko_get_num_queues(port);
qos++)
cvmx_fau_atomic_write32(priv->fau + qos * 4, 0);
switch (priv->imode) {
case CVMX_HELPER_INTERFACE_MODE_DISABLED:
case CVMX_HELPER_INTERFACE_MODE_PCIE:
case CVMX_HELPER_INTERFACE_MODE_PICMG:
break;
case CVMX_HELPER_INTERFACE_MODE_NPI:
dev->netdev_ops = &cvm_oct_npi_netdev_ops;
strcpy(dev->name, "npi%d");
break;
case CVMX_HELPER_INTERFACE_MODE_XAUI:
dev->netdev_ops = &cvm_oct_xaui_netdev_ops;
strcpy(dev->name, "xaui%d");
break;
case CVMX_HELPER_INTERFACE_MODE_LOOP:
dev->netdev_ops = &cvm_oct_npi_netdev_ops;
strcpy(dev->name, "loop%d");
break;
case CVMX_HELPER_INTERFACE_MODE_SGMII:
dev->netdev_ops = &cvm_oct_sgmii_netdev_ops;
strcpy(dev->name, "eth%d");
break;
case CVMX_HELPER_INTERFACE_MODE_SPI:
dev->netdev_ops = &cvm_oct_spi_netdev_ops;
strcpy(dev->name, "spi%d");
break;
case CVMX_HELPER_INTERFACE_MODE_RGMII:
case CVMX_HELPER_INTERFACE_MODE_GMII:
dev->netdev_ops = &cvm_oct_rgmii_netdev_ops;
strcpy(dev->name, "eth%d");
cvm_set_rgmii_delay(priv->of_node, interface,
port_index);
break;
}
if (!dev->netdev_ops) {
free_netdev(dev);
} else if (register_netdev(dev) < 0) {
pr_err("Failed to register ethernet device for interface %d, port %d\n",
interface, priv->port);
free_netdev(dev);
} else {
cvm_oct_device[priv->port] = dev;
fau -=
cvmx_pko_get_num_queues(priv->port) *
sizeof(u32);
schedule_delayed_work(&priv->port_periodic_work, HZ);
}
}
}
cvm_oct_tx_initialize();
cvm_oct_rx_initialize();
cvm_oct_tx_poll_interval = 150 * (octeon_get_clock_rate() / 1000000);
schedule_delayed_work(&cvm_oct_rx_refill_work, HZ);
return 0;
}
static int cvm_oct_remove(struct platform_device *pdev)
{
int port;
cvmx_ipd_disable();
atomic_inc_return(&cvm_oct_poll_queue_stopping);
cancel_delayed_work_sync(&cvm_oct_rx_refill_work);
cvm_oct_rx_shutdown();
cvm_oct_tx_shutdown();
cvmx_pko_disable();
for (port = 0; port < TOTAL_NUMBER_OF_PORTS; port++) {
if (cvm_oct_device[port]) {
struct net_device *dev = cvm_oct_device[port];
struct octeon_ethernet *priv = netdev_priv(dev);
cancel_delayed_work_sync(&priv->port_periodic_work);
cvm_oct_tx_shutdown_dev(dev);
unregister_netdev(dev);
free_netdev(dev);
cvm_oct_device[port] = NULL;
}
}
cvmx_pko_shutdown();
cvmx_ipd_free_ptr();
cvm_oct_mem_empty_fpa(CVMX_FPA_PACKET_POOL, CVMX_FPA_PACKET_POOL_SIZE,
num_packet_buffers);
cvm_oct_mem_empty_fpa(CVMX_FPA_WQE_POOL, CVMX_FPA_WQE_POOL_SIZE,
num_packet_buffers);
if (CVMX_FPA_OUTPUT_BUFFER_POOL != CVMX_FPA_PACKET_POOL)
cvm_oct_mem_empty_fpa(CVMX_FPA_OUTPUT_BUFFER_POOL,
CVMX_FPA_OUTPUT_BUFFER_POOL_SIZE, 128);
return 0;
}
