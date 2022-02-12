u64 ehca_define_sqp(struct ehca_shca *shca,
struct ehca_qp *ehca_qp,
struct ib_qp_init_attr *qp_init_attr)
{
u32 pma_qp_nr, bma_qp_nr;
u64 ret;
u8 port = qp_init_attr->port_num;
int counter;
shca->sport[port - 1].port_state = IB_PORT_DOWN;
switch (qp_init_attr->qp_type) {
case IB_QPT_SMI:
break;
case IB_QPT_GSI:
ret = hipz_h_define_aqp1(shca->ipz_hca_handle,
ehca_qp->ipz_qp_handle,
ehca_qp->galpas.kernel,
(u32) qp_init_attr->port_num,
&pma_qp_nr, &bma_qp_nr);
if (ret != H_SUCCESS) {
ehca_err(&shca->ib_device,
"Can't define AQP1 for port %x. h_ret=%lli",
port, ret);
return ret;
}
shca->sport[port - 1].pma_qp_nr = pma_qp_nr;
ehca_dbg(&shca->ib_device, "port=%x pma_qp_nr=%x",
port, pma_qp_nr);
break;
default:
ehca_err(&shca->ib_device, "invalid qp_type=%x",
qp_init_attr->qp_type);
return H_PARAMETER;
}
if (ehca_nr_ports < 0)
return H_SUCCESS;
for (counter = 0;
shca->sport[port - 1].port_state != IB_PORT_ACTIVE &&
counter < ehca_port_act_time;
counter++) {
ehca_dbg(&shca->ib_device, "... wait until port %x is active",
port);
msleep_interruptible(1000);
}
if (counter == ehca_port_act_time) {
ehca_err(&shca->ib_device, "Port %x is not active.", port);
return H_HARDWARE;
}
return H_SUCCESS;
}
static int ehca_process_perf(struct ib_device *ibdev, u8 port_num,
const struct ib_wc *in_wc, const struct ib_grh *in_grh,
const struct ib_mad *in_mad, struct ib_mad *out_mad)
{
const struct ib_perf *in_perf = (const struct ib_perf *)in_mad;
struct ib_perf *out_perf = (struct ib_perf *)out_mad;
struct ib_class_port_info *poi =
(struct ib_class_port_info *)out_perf->data;
struct tcslfl *tcslfl =
(struct tcslfl *)&poi->redirect_tcslfl;
struct ehca_shca *shca =
container_of(ibdev, struct ehca_shca, ib_device);
struct ehca_sport *sport = &shca->sport[port_num - 1];
ehca_dbg(ibdev, "method=%x", in_perf->mad_hdr.method);
*out_mad = *in_mad;
if (in_perf->mad_hdr.class_version != 1) {
ehca_warn(ibdev, "Unsupported class_version=%x",
in_perf->mad_hdr.class_version);
out_perf->mad_hdr.status = IB_MAD_STATUS_UNSUP_VERSION;
goto perf_reply;
}
switch (in_perf->mad_hdr.method) {
case IB_MGMT_METHOD_GET:
case IB_MGMT_METHOD_SET:
out_perf->mad_hdr.attr_id = IB_PMA_CLASS_PORT_INFO;
out_perf->mad_hdr.status = IB_MAD_STATUS_REDIRECT;
memset(poi, 0, sizeof(*poi));
poi->base_version = 1;
poi->class_version = 1;
poi->resp_time_value = 18;
tcslfl->sl = in_wc->sl;
poi->redirect_lid =
sport->saved_attr.lid | in_wc->dlid_path_bits;
poi->redirect_qp = sport->pma_qp_nr;
poi->redirect_qkey = IB_QP1_QKEY;
ehca_query_pkey(ibdev, port_num, in_wc->pkey_index,
&poi->redirect_pkey);
if (in_grh) {
const struct vertcfl *vertcfl =
(const struct vertcfl *)&in_grh->version_tclass_flow;
memcpy(poi->redirect_gid, in_grh->dgid.raw,
sizeof(poi->redirect_gid));
tcslfl->tc = vertcfl->tc;
tcslfl->fl = vertcfl->fl;
} else
ehca_query_gid(ibdev, port_num, 0,
(union ib_gid *)&poi->redirect_gid);
ehca_dbg(ibdev, "ehca_pma_lid=%x ehca_pma_qp=%x",
sport->saved_attr.lid, sport->pma_qp_nr);
break;
case IB_MGMT_METHOD_GET_RESP:
return IB_MAD_RESULT_FAILURE;
default:
out_perf->mad_hdr.status = IB_MAD_STATUS_UNSUP_METHOD;
break;
}
perf_reply:
out_perf->mad_hdr.method = IB_MGMT_METHOD_GET_RESP;
return IB_MAD_RESULT_SUCCESS | IB_MAD_RESULT_REPLY;
}
int ehca_process_mad(struct ib_device *ibdev, int mad_flags, u8 port_num,
const struct ib_wc *in_wc, const struct ib_grh *in_grh,
const struct ib_mad_hdr *in, size_t in_mad_size,
struct ib_mad_hdr *out, size_t *out_mad_size,
u16 *out_mad_pkey_index)
{
int ret;
const struct ib_mad *in_mad = (const struct ib_mad *)in;
struct ib_mad *out_mad = (struct ib_mad *)out;
if (WARN_ON_ONCE(in_mad_size != sizeof(*in_mad) ||
*out_mad_size != sizeof(*out_mad)))
return IB_MAD_RESULT_FAILURE;
if (!port_num || port_num > ibdev->phys_port_cnt || !in_wc)
return IB_MAD_RESULT_FAILURE;
if (in_mad->mad_hdr.mgmt_class != IB_MGMT_CLASS_PERF_MGMT)
return IB_MAD_RESULT_SUCCESS;
ehca_dbg(ibdev, "port_num=%x src_qp=%x", port_num, in_wc->src_qp);
ret = ehca_process_perf(ibdev, port_num, in_wc, in_grh,
in_mad, out_mad);
return ret;
}
