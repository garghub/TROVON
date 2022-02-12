struct ib_ah *create_ib_ah(struct ib_ah_attr *ah_attr,
struct mlx5_ib_ah *ah)
{
if (ah_attr->ah_flags & IB_AH_GRH) {
memcpy(ah->av.rgid, &ah_attr->grh.dgid, 16);
ah->av.grh_gid_fl = cpu_to_be32(ah_attr->grh.flow_label |
(1 << 30) |
ah_attr->grh.sgid_index << 20);
ah->av.hop_limit = ah_attr->grh.hop_limit;
ah->av.tclass = ah_attr->grh.traffic_class;
}
ah->av.rlid = cpu_to_be16(ah_attr->dlid);
ah->av.fl_mlid = ah_attr->src_path_bits & 0x7f;
ah->av.stat_rate_sl = (ah_attr->static_rate << 4) | (ah_attr->sl & 0xf);
return &ah->ibah;
}
struct ib_ah *mlx5_ib_create_ah(struct ib_pd *pd, struct ib_ah_attr *ah_attr)
{
struct mlx5_ib_ah *ah;
ah = kzalloc(sizeof(*ah), GFP_ATOMIC);
if (!ah)
return ERR_PTR(-ENOMEM);
return create_ib_ah(ah_attr, ah);
}
int mlx5_ib_query_ah(struct ib_ah *ibah, struct ib_ah_attr *ah_attr)
{
struct mlx5_ib_ah *ah = to_mah(ibah);
u32 tmp;
memset(ah_attr, 0, sizeof(*ah_attr));
tmp = be32_to_cpu(ah->av.grh_gid_fl);
if (tmp & (1 << 30)) {
ah_attr->ah_flags = IB_AH_GRH;
ah_attr->grh.sgid_index = (tmp >> 20) & 0xff;
ah_attr->grh.flow_label = tmp & 0xfffff;
memcpy(&ah_attr->grh.dgid, ah->av.rgid, 16);
ah_attr->grh.hop_limit = ah->av.hop_limit;
ah_attr->grh.traffic_class = ah->av.tclass;
}
ah_attr->dlid = be16_to_cpu(ah->av.rlid);
ah_attr->static_rate = ah->av.stat_rate_sl >> 4;
ah_attr->sl = ah->av.stat_rate_sl & 0xf;
return 0;
}
int mlx5_ib_destroy_ah(struct ib_ah *ah)
{
kfree(to_mah(ah));
return 0;
}
