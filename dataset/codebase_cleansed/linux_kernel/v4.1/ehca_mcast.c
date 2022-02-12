int ehca_attach_mcast(struct ib_qp *ibqp, union ib_gid *gid, u16 lid)
{
struct ehca_qp *my_qp = container_of(ibqp, struct ehca_qp, ib_qp);
struct ehca_shca *shca = container_of(ibqp->device, struct ehca_shca,
ib_device);
union ib_gid my_gid;
u64 subnet_prefix, interface_id, h_ret;
if (ibqp->qp_type != IB_QPT_UD) {
ehca_err(ibqp->device, "invalid qp_type=%x", ibqp->qp_type);
return -EINVAL;
}
if (!(EHCA_VALID_MULTICAST_GID(gid->raw))) {
ehca_err(ibqp->device, "invalid mulitcast gid");
return -EINVAL;
} else if ((lid < MIN_MC_LID) || (lid > MAX_MC_LID)) {
ehca_err(ibqp->device, "invalid mulitcast lid=%x", lid);
return -EINVAL;
}
memcpy(&my_gid, gid->raw, sizeof(union ib_gid));
subnet_prefix = be64_to_cpu(my_gid.global.subnet_prefix);
interface_id = be64_to_cpu(my_gid.global.interface_id);
h_ret = hipz_h_attach_mcqp(shca->ipz_hca_handle,
my_qp->ipz_qp_handle,
my_qp->galpas.kernel,
lid, subnet_prefix, interface_id);
if (h_ret != H_SUCCESS)
ehca_err(ibqp->device,
"ehca_qp=%p qp_num=%x hipz_h_attach_mcqp() failed "
"h_ret=%lli", my_qp, ibqp->qp_num, h_ret);
return ehca2ib_return_code(h_ret);
}
int ehca_detach_mcast(struct ib_qp *ibqp, union ib_gid *gid, u16 lid)
{
struct ehca_qp *my_qp = container_of(ibqp, struct ehca_qp, ib_qp);
struct ehca_shca *shca = container_of(ibqp->pd->device,
struct ehca_shca, ib_device);
union ib_gid my_gid;
u64 subnet_prefix, interface_id, h_ret;
if (ibqp->qp_type != IB_QPT_UD) {
ehca_err(ibqp->device, "invalid qp_type %x", ibqp->qp_type);
return -EINVAL;
}
if (!(EHCA_VALID_MULTICAST_GID(gid->raw))) {
ehca_err(ibqp->device, "invalid mulitcast gid");
return -EINVAL;
} else if ((lid < MIN_MC_LID) || (lid > MAX_MC_LID)) {
ehca_err(ibqp->device, "invalid mulitcast lid=%x", lid);
return -EINVAL;
}
memcpy(&my_gid, gid->raw, sizeof(union ib_gid));
subnet_prefix = be64_to_cpu(my_gid.global.subnet_prefix);
interface_id = be64_to_cpu(my_gid.global.interface_id);
h_ret = hipz_h_detach_mcqp(shca->ipz_hca_handle,
my_qp->ipz_qp_handle,
my_qp->galpas.kernel,
lid, subnet_prefix, interface_id);
if (h_ret != H_SUCCESS)
ehca_err(ibqp->device,
"ehca_qp=%p qp_num=%x hipz_h_detach_mcqp() failed "
"h_ret=%lli", my_qp, ibqp->qp_num, h_ret);
return ehca2ib_return_code(h_ret);
}
