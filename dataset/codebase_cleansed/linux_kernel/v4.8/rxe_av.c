int rxe_av_chk_attr(struct rxe_dev *rxe, struct ib_ah_attr *attr)
{
struct rxe_port *port;
if (attr->port_num != 1) {
pr_info("rxe: invalid port_num = %d\n", attr->port_num);
return -EINVAL;
}
port = &rxe->port;
if (attr->ah_flags & IB_AH_GRH) {
if (attr->grh.sgid_index > port->attr.gid_tbl_len) {
pr_info("rxe: invalid sgid index = %d\n",
attr->grh.sgid_index);
return -EINVAL;
}
}
return 0;
}
int rxe_av_from_attr(struct rxe_dev *rxe, u8 port_num,
struct rxe_av *av, struct ib_ah_attr *attr)
{
memset(av, 0, sizeof(*av));
memcpy(&av->grh, &attr->grh, sizeof(attr->grh));
av->port_num = port_num;
return 0;
}
int rxe_av_to_attr(struct rxe_dev *rxe, struct rxe_av *av,
struct ib_ah_attr *attr)
{
memcpy(&attr->grh, &av->grh, sizeof(av->grh));
attr->port_num = av->port_num;
return 0;
}
int rxe_av_fill_ip_info(struct rxe_dev *rxe,
struct rxe_av *av,
struct ib_ah_attr *attr,
struct ib_gid_attr *sgid_attr,
union ib_gid *sgid)
{
rdma_gid2ip(&av->sgid_addr._sockaddr, sgid);
rdma_gid2ip(&av->dgid_addr._sockaddr, &attr->grh.dgid);
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
