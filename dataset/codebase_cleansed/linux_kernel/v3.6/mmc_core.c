void dwmac_mmc_ctrl(void __iomem *ioaddr, unsigned int mode)
{
u32 value = readl(ioaddr + MMC_CNTRL);
value |= (mode & 0x3F);
writel(value, ioaddr + MMC_CNTRL);
pr_debug("stmmac: MMC ctrl register (offset 0x%x): 0x%08x\n",
MMC_CNTRL, value);
}
void dwmac_mmc_intr_all_mask(void __iomem *ioaddr)
{
writel(MMC_DEFAULT_MASK, ioaddr + MMC_RX_INTR_MASK);
writel(MMC_DEFAULT_MASK, ioaddr + MMC_TX_INTR_MASK);
}
void dwmac_mmc_read(void __iomem *ioaddr, struct stmmac_counters *mmc)
{
mmc->mmc_tx_octetcount_gb += readl(ioaddr + MMC_TX_OCTETCOUNT_GB);
mmc->mmc_tx_framecount_gb += readl(ioaddr + MMC_TX_FRAMECOUNT_GB);
mmc->mmc_tx_broadcastframe_g += readl(ioaddr + MMC_TX_BROADCASTFRAME_G);
mmc->mmc_tx_multicastframe_g += readl(ioaddr + MMC_TX_MULTICASTFRAME_G);
mmc->mmc_tx_64_octets_gb += readl(ioaddr + MMC_TX_64_OCTETS_GB);
mmc->mmc_tx_65_to_127_octets_gb +=
readl(ioaddr + MMC_TX_65_TO_127_OCTETS_GB);
mmc->mmc_tx_128_to_255_octets_gb +=
readl(ioaddr + MMC_TX_128_TO_255_OCTETS_GB);
mmc->mmc_tx_256_to_511_octets_gb +=
readl(ioaddr + MMC_TX_256_TO_511_OCTETS_GB);
mmc->mmc_tx_512_to_1023_octets_gb +=
readl(ioaddr + MMC_TX_512_TO_1023_OCTETS_GB);
mmc->mmc_tx_1024_to_max_octets_gb +=
readl(ioaddr + MMC_TX_1024_TO_MAX_OCTETS_GB);
mmc->mmc_tx_unicast_gb += readl(ioaddr + MMC_TX_UNICAST_GB);
mmc->mmc_tx_multicast_gb += readl(ioaddr + MMC_TX_MULTICAST_GB);
mmc->mmc_tx_broadcast_gb += readl(ioaddr + MMC_TX_BROADCAST_GB);
mmc->mmc_tx_underflow_error += readl(ioaddr + MMC_TX_UNDERFLOW_ERROR);
mmc->mmc_tx_singlecol_g += readl(ioaddr + MMC_TX_SINGLECOL_G);
mmc->mmc_tx_multicol_g += readl(ioaddr + MMC_TX_MULTICOL_G);
mmc->mmc_tx_deferred += readl(ioaddr + MMC_TX_DEFERRED);
mmc->mmc_tx_latecol += readl(ioaddr + MMC_TX_LATECOL);
mmc->mmc_tx_exesscol += readl(ioaddr + MMC_TX_EXESSCOL);
mmc->mmc_tx_carrier_error += readl(ioaddr + MMC_TX_CARRIER_ERROR);
mmc->mmc_tx_octetcount_g += readl(ioaddr + MMC_TX_OCTETCOUNT_G);
mmc->mmc_tx_framecount_g += readl(ioaddr + MMC_TX_FRAMECOUNT_G);
mmc->mmc_tx_excessdef += readl(ioaddr + MMC_TX_EXCESSDEF);
mmc->mmc_tx_pause_frame += readl(ioaddr + MMC_TX_PAUSE_FRAME);
mmc->mmc_tx_vlan_frame_g += readl(ioaddr + MMC_TX_VLAN_FRAME_G);
mmc->mmc_rx_framecount_gb += readl(ioaddr + MMC_RX_FRAMECOUNT_GB);
mmc->mmc_rx_octetcount_gb += readl(ioaddr + MMC_RX_OCTETCOUNT_GB);
mmc->mmc_rx_octetcount_g += readl(ioaddr + MMC_RX_OCTETCOUNT_G);
mmc->mmc_rx_broadcastframe_g += readl(ioaddr + MMC_RX_BROADCASTFRAME_G);
mmc->mmc_rx_multicastframe_g += readl(ioaddr + MMC_RX_MULTICASTFRAME_G);
mmc->mmc_rx_crc_errror += readl(ioaddr + MMC_RX_CRC_ERRROR);
mmc->mmc_rx_align_error += readl(ioaddr + MMC_RX_ALIGN_ERROR);
mmc->mmc_rx_run_error += readl(ioaddr + MMC_RX_RUN_ERROR);
mmc->mmc_rx_jabber_error += readl(ioaddr + MMC_RX_JABBER_ERROR);
mmc->mmc_rx_undersize_g += readl(ioaddr + MMC_RX_UNDERSIZE_G);
mmc->mmc_rx_oversize_g += readl(ioaddr + MMC_RX_OVERSIZE_G);
mmc->mmc_rx_64_octets_gb += readl(ioaddr + MMC_RX_64_OCTETS_GB);
mmc->mmc_rx_65_to_127_octets_gb +=
readl(ioaddr + MMC_RX_65_TO_127_OCTETS_GB);
mmc->mmc_rx_128_to_255_octets_gb +=
readl(ioaddr + MMC_RX_128_TO_255_OCTETS_GB);
mmc->mmc_rx_256_to_511_octets_gb +=
readl(ioaddr + MMC_RX_256_TO_511_OCTETS_GB);
mmc->mmc_rx_512_to_1023_octets_gb +=
readl(ioaddr + MMC_RX_512_TO_1023_OCTETS_GB);
mmc->mmc_rx_1024_to_max_octets_gb +=
readl(ioaddr + MMC_RX_1024_TO_MAX_OCTETS_GB);
mmc->mmc_rx_unicast_g += readl(ioaddr + MMC_RX_UNICAST_G);
mmc->mmc_rx_length_error += readl(ioaddr + MMC_RX_LENGTH_ERROR);
mmc->mmc_rx_autofrangetype += readl(ioaddr + MMC_RX_AUTOFRANGETYPE);
mmc->mmc_rx_pause_frames += readl(ioaddr + MMC_RX_PAUSE_FRAMES);
mmc->mmc_rx_fifo_overflow += readl(ioaddr + MMC_RX_FIFO_OVERFLOW);
mmc->mmc_rx_vlan_frames_gb += readl(ioaddr + MMC_RX_VLAN_FRAMES_GB);
mmc->mmc_rx_watchdog_error += readl(ioaddr + MMC_RX_WATCHDOG_ERROR);
mmc->mmc_rx_ipc_intr_mask += readl(ioaddr + MMC_RX_IPC_INTR_MASK);
mmc->mmc_rx_ipc_intr += readl(ioaddr + MMC_RX_IPC_INTR);
mmc->mmc_rx_ipv4_gd += readl(ioaddr + MMC_RX_IPV4_GD);
mmc->mmc_rx_ipv4_hderr += readl(ioaddr + MMC_RX_IPV4_HDERR);
mmc->mmc_rx_ipv4_nopay += readl(ioaddr + MMC_RX_IPV4_NOPAY);
mmc->mmc_rx_ipv4_frag += readl(ioaddr + MMC_RX_IPV4_FRAG);
mmc->mmc_rx_ipv4_udsbl += readl(ioaddr + MMC_RX_IPV4_UDSBL);
mmc->mmc_rx_ipv4_gd_octets += readl(ioaddr + MMC_RX_IPV4_GD_OCTETS);
mmc->mmc_rx_ipv4_hderr_octets +=
readl(ioaddr + MMC_RX_IPV4_HDERR_OCTETS);
mmc->mmc_rx_ipv4_nopay_octets +=
readl(ioaddr + MMC_RX_IPV4_NOPAY_OCTETS);
mmc->mmc_rx_ipv4_frag_octets += readl(ioaddr + MMC_RX_IPV4_FRAG_OCTETS);
mmc->mmc_rx_ipv4_udsbl_octets +=
readl(ioaddr + MMC_RX_IPV4_UDSBL_OCTETS);
mmc->mmc_rx_ipv6_gd_octets += readl(ioaddr + MMC_RX_IPV6_GD_OCTETS);
mmc->mmc_rx_ipv6_hderr_octets +=
readl(ioaddr + MMC_RX_IPV6_HDERR_OCTETS);
mmc->mmc_rx_ipv6_nopay_octets +=
readl(ioaddr + MMC_RX_IPV6_NOPAY_OCTETS);
mmc->mmc_rx_ipv6_gd += readl(ioaddr + MMC_RX_IPV6_GD);
mmc->mmc_rx_ipv6_hderr += readl(ioaddr + MMC_RX_IPV6_HDERR);
mmc->mmc_rx_ipv6_nopay += readl(ioaddr + MMC_RX_IPV6_NOPAY);
mmc->mmc_rx_udp_gd += readl(ioaddr + MMC_RX_UDP_GD);
mmc->mmc_rx_udp_err += readl(ioaddr + MMC_RX_UDP_ERR);
mmc->mmc_rx_tcp_gd += readl(ioaddr + MMC_RX_TCP_GD);
mmc->mmc_rx_tcp_err += readl(ioaddr + MMC_RX_TCP_ERR);
mmc->mmc_rx_icmp_gd += readl(ioaddr + MMC_RX_ICMP_GD);
mmc->mmc_rx_icmp_err += readl(ioaddr + MMC_RX_ICMP_ERR);
mmc->mmc_rx_udp_gd_octets += readl(ioaddr + MMC_RX_UDP_GD_OCTETS);
mmc->mmc_rx_udp_err_octets += readl(ioaddr + MMC_RX_UDP_ERR_OCTETS);
mmc->mmc_rx_tcp_gd_octets += readl(ioaddr + MMC_RX_TCP_GD_OCTETS);
mmc->mmc_rx_tcp_err_octets += readl(ioaddr + MMC_RX_TCP_ERR_OCTETS);
mmc->mmc_rx_icmp_gd_octets += readl(ioaddr + MMC_RX_ICMP_GD_OCTETS);
mmc->mmc_rx_icmp_err_octets += readl(ioaddr + MMC_RX_ICMP_ERR_OCTETS);
}
