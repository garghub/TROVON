struct ib_ah *hns_roce_create_ah(struct ib_pd *ibpd, struct ib_ah_attr *ah_attr)
{
struct hns_roce_dev *hr_dev = to_hr_dev(ibpd->device);
struct device *dev = &hr_dev->pdev->dev;
struct ib_gid_attr gid_attr;
struct hns_roce_ah *ah;
u16 vlan_tag = 0xffff;
struct in6_addr in6;
union ib_gid sgid;
int ret;
ah = kzalloc(sizeof(*ah), GFP_ATOMIC);
if (!ah)
return ERR_PTR(-ENOMEM);
memcpy(&in6, ah_attr->grh.dgid.raw, sizeof(ah_attr->grh.dgid.raw));
if (rdma_is_multicast_addr(&in6))
rdma_get_mcast_mac(&in6, ah->av.mac);
else
memcpy(ah->av.mac, ah_attr->dmac, sizeof(ah_attr->dmac));
ret = ib_get_cached_gid(ibpd->device, ah_attr->port_num,
ah_attr->grh.sgid_index, &sgid, &gid_attr);
if (ret) {
dev_err(dev, "get sgid failed! ret = %d\n", ret);
kfree(ah);
return ERR_PTR(ret);
}
if (gid_attr.ndev) {
if (is_vlan_dev(gid_attr.ndev))
vlan_tag = vlan_dev_vlan_id(gid_attr.ndev);
dev_put(gid_attr.ndev);
}
if (vlan_tag < 0x1000)
vlan_tag |= (ah_attr->sl & HNS_ROCE_VLAN_SL_BIT_MASK) <<
HNS_ROCE_VLAN_SL_SHIFT;
ah->av.port_pd = cpu_to_be32(to_hr_pd(ibpd)->pdn | (ah_attr->port_num <<
HNS_ROCE_PORT_NUM_SHIFT));
ah->av.gid_index = ah_attr->grh.sgid_index;
ah->av.vlan = cpu_to_le16(vlan_tag);
dev_dbg(dev, "gid_index = 0x%x,vlan = 0x%x\n", ah->av.gid_index,
ah->av.vlan);
if (ah_attr->static_rate)
ah->av.stat_rate = IB_RATE_10_GBPS;
memcpy(ah->av.dgid, ah_attr->grh.dgid.raw, HNS_ROCE_GID_SIZE);
ah->av.sl_tclass_flowlabel = cpu_to_le32(ah_attr->sl <<
HNS_ROCE_SL_SHIFT);
return &ah->ibah;
}
int hns_roce_query_ah(struct ib_ah *ibah, struct ib_ah_attr *ah_attr)
{
struct hns_roce_ah *ah = to_hr_ah(ibah);
memset(ah_attr, 0, sizeof(*ah_attr));
ah_attr->sl = le32_to_cpu(ah->av.sl_tclass_flowlabel) >>
HNS_ROCE_SL_SHIFT;
ah_attr->port_num = le32_to_cpu(ah->av.port_pd) >>
HNS_ROCE_PORT_NUM_SHIFT;
ah_attr->static_rate = ah->av.stat_rate;
ah_attr->ah_flags = IB_AH_GRH;
ah_attr->grh.traffic_class = le32_to_cpu(ah->av.sl_tclass_flowlabel) >>
HNS_ROCE_TCLASS_SHIFT;
ah_attr->grh.flow_label = le32_to_cpu(ah->av.sl_tclass_flowlabel) &
HNS_ROCE_FLOW_LABLE_MASK;
ah_attr->grh.hop_limit = ah->av.hop_limit;
ah_attr->grh.sgid_index = ah->av.gid_index;
memcpy(ah_attr->grh.dgid.raw, ah->av.dgid, HNS_ROCE_GID_SIZE);
return 0;
}
int hns_roce_destroy_ah(struct ib_ah *ah)
{
kfree(to_hr_ah(ah));
return 0;
}
