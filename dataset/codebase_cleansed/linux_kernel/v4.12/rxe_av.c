int rxe_av_chk_attr(struct rxe_dev *rxe, struct rdma_ah_attr *attr)
{
struct rxe_port *port;
if (rdma_ah_get_port_num(attr) != 1) {
pr_info("invalid port_num = %d\n", rdma_ah_get_port_num(attr));
return -EINVAL;
}
port = &rxe->port;
if (rdma_ah_get_ah_flags(attr) & IB_AH_GRH) {
u8 sgid_index = rdma_ah_read_grh(attr)->sgid_index;
if (sgid_index > port->attr.gid_tbl_len) {
pr_info("invalid sgid index = %d\n", sgid_index);
return -EINVAL;
}
}
return 0;
}
int rxe_av_from_attr(struct rxe_dev *rxe, u8 port_num,
struct rxe_av *av, struct rdma_ah_attr *attr)
{
memset(av, 0, sizeof(*av));
memcpy(&av->grh, rdma_ah_read_grh(attr),
sizeof(*rdma_ah_read_grh(attr)));
av->port_num = port_num;
return 0;
}
int rxe_av_to_attr(struct rxe_dev *rxe, struct rxe_av *av,
struct rdma_ah_attr *attr)
{
attr->type = RDMA_AH_ATTR_TYPE_ROCE;
memcpy(rdma_ah_retrieve_grh(attr), &av->grh, sizeof(av->grh));
rdma_ah_set_ah_flags(attr, IB_AH_GRH);
rdma_ah_set_port_num(attr, av->port_num);
return 0;
}
int rxe_av_fill_ip_info(struct rxe_dev *rxe,
struct rxe_av *av,
struct rdma_ah_attr *attr,
struct ib_gid_attr *sgid_attr,
union ib_gid *sgid)
{
rdma_gid2ip(&av->sgid_addr._sockaddr, sgid);
rdma_gid2ip(&av->dgid_addr._sockaddr, &rdma_ah_read_grh(attr)->dgid);
av->network_type = ib_gid_to_network_type(sgid_attr->gid_type, sgid);
return 0;
}
struct rxe_av *rxe_get_av(struct rxe_pkt_info *pkt)
{
if (!pkt || !pkt->qp)
return NULL;
if (qp_type(pkt->qp) == IB_QPT_RC || qp_type(pkt->qp) == IB_QPT_UC)
return &pkt->qp->pri_av;
return (pkt->wqe) ? &pkt->wqe->av : NULL;
}
