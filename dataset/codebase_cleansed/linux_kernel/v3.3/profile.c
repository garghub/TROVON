u64 mlx4_make_profile(struct mlx4_dev *dev,
struct mlx4_profile *request,
struct mlx4_dev_cap *dev_cap,
struct mlx4_init_hca_param *init_hca)
{
struct mlx4_priv *priv = mlx4_priv(dev);
struct mlx4_resource {
u64 size;
u64 start;
int type;
int num;
int log_num;
};
u64 total_size = 0;
struct mlx4_resource *profile;
struct mlx4_resource tmp;
int i, j;
profile = kcalloc(MLX4_RES_NUM, sizeof(*profile), GFP_KERNEL);
if (!profile)
return -ENOMEM;
profile[MLX4_RES_QP].size = dev_cap->qpc_entry_sz;
profile[MLX4_RES_RDMARC].size = dev_cap->rdmarc_entry_sz;
profile[MLX4_RES_ALTC].size = dev_cap->altc_entry_sz;
profile[MLX4_RES_AUXC].size = dev_cap->aux_entry_sz;
profile[MLX4_RES_SRQ].size = dev_cap->srq_entry_sz;
profile[MLX4_RES_CQ].size = dev_cap->cqc_entry_sz;
profile[MLX4_RES_EQ].size = dev_cap->eqc_entry_sz;
profile[MLX4_RES_DMPT].size = dev_cap->dmpt_entry_sz;
profile[MLX4_RES_CMPT].size = dev_cap->cmpt_entry_sz;
profile[MLX4_RES_MTT].size = dev_cap->mtt_entry_sz;
profile[MLX4_RES_MCG].size = mlx4_get_mgm_entry_size(dev);
profile[MLX4_RES_QP].num = request->num_qp;
profile[MLX4_RES_RDMARC].num = request->num_qp * request->rdmarc_per_qp;
profile[MLX4_RES_ALTC].num = request->num_qp;
profile[MLX4_RES_AUXC].num = request->num_qp;
profile[MLX4_RES_SRQ].num = request->num_srq;
profile[MLX4_RES_CQ].num = request->num_cq;
profile[MLX4_RES_EQ].num = min_t(unsigned, dev_cap->max_eqs, MAX_MSIX);
profile[MLX4_RES_DMPT].num = request->num_mpt;
profile[MLX4_RES_CMPT].num = MLX4_NUM_CMPTS;
profile[MLX4_RES_MTT].num = request->num_mtt * (1 << log_mtts_per_seg);
profile[MLX4_RES_MCG].num = request->num_mcg;
for (i = 0; i < MLX4_RES_NUM; ++i) {
profile[i].type = i;
profile[i].num = roundup_pow_of_two(profile[i].num);
profile[i].log_num = ilog2(profile[i].num);
profile[i].size *= profile[i].num;
profile[i].size = max(profile[i].size, (u64) PAGE_SIZE);
}
for (i = MLX4_RES_NUM; i > 0; --i)
for (j = 1; j < i; ++j) {
if (profile[j].size > profile[j - 1].size) {
tmp = profile[j];
profile[j] = profile[j - 1];
profile[j - 1] = tmp;
}
}
for (i = 0; i < MLX4_RES_NUM; ++i) {
if (profile[i].size) {
profile[i].start = total_size;
total_size += profile[i].size;
}
if (total_size > dev_cap->max_icm_sz) {
mlx4_err(dev, "Profile requires 0x%llx bytes; "
"won't fit in 0x%llx bytes of context memory.\n",
(unsigned long long) total_size,
(unsigned long long) dev_cap->max_icm_sz);
kfree(profile);
return -ENOMEM;
}
if (profile[i].size)
mlx4_dbg(dev, " profile[%2d] (%6s): 2^%02d entries @ 0x%10llx, "
"size 0x%10llx\n",
i, res_name[profile[i].type], profile[i].log_num,
(unsigned long long) profile[i].start,
(unsigned long long) profile[i].size);
}
mlx4_dbg(dev, "HCA context memory: reserving %d KB\n",
(int) (total_size >> 10));
for (i = 0; i < MLX4_RES_NUM; ++i) {
switch (profile[i].type) {
case MLX4_RES_QP:
dev->caps.num_qps = profile[i].num;
init_hca->qpc_base = profile[i].start;
init_hca->log_num_qps = profile[i].log_num;
break;
case MLX4_RES_RDMARC:
for (priv->qp_table.rdmarc_shift = 0;
request->num_qp << priv->qp_table.rdmarc_shift < profile[i].num;
++priv->qp_table.rdmarc_shift)
;
dev->caps.max_qp_dest_rdma = 1 << priv->qp_table.rdmarc_shift;
priv->qp_table.rdmarc_base = (u32) profile[i].start;
init_hca->rdmarc_base = profile[i].start;
init_hca->log_rd_per_qp = priv->qp_table.rdmarc_shift;
break;
case MLX4_RES_ALTC:
init_hca->altc_base = profile[i].start;
break;
case MLX4_RES_AUXC:
init_hca->auxc_base = profile[i].start;
break;
case MLX4_RES_SRQ:
dev->caps.num_srqs = profile[i].num;
init_hca->srqc_base = profile[i].start;
init_hca->log_num_srqs = profile[i].log_num;
break;
case MLX4_RES_CQ:
dev->caps.num_cqs = profile[i].num;
init_hca->cqc_base = profile[i].start;
init_hca->log_num_cqs = profile[i].log_num;
break;
case MLX4_RES_EQ:
dev->caps.num_eqs = profile[i].num;
init_hca->eqc_base = profile[i].start;
init_hca->log_num_eqs = profile[i].log_num;
break;
case MLX4_RES_DMPT:
dev->caps.num_mpts = profile[i].num;
priv->mr_table.mpt_base = profile[i].start;
init_hca->dmpt_base = profile[i].start;
init_hca->log_mpt_sz = profile[i].log_num;
break;
case MLX4_RES_CMPT:
init_hca->cmpt_base = profile[i].start;
break;
case MLX4_RES_MTT:
dev->caps.num_mtts = profile[i].num;
priv->mr_table.mtt_base = profile[i].start;
init_hca->mtt_base = profile[i].start;
break;
case MLX4_RES_MCG:
dev->caps.num_mgms = profile[i].num >> 1;
dev->caps.num_amgms = profile[i].num >> 1;
init_hca->mc_base = profile[i].start;
init_hca->log_mc_entry_sz =
ilog2(mlx4_get_mgm_entry_size(dev));
init_hca->log_mc_table_sz = profile[i].log_num;
init_hca->log_mc_hash_sz = profile[i].log_num - 1;
break;
default:
break;
}
}
dev->caps.num_pds = MLX4_NUM_PDS;
kfree(profile);
return total_size;
}
