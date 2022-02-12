int mlx5_core_attach_mcg(struct mlx5_core_dev *dev, union ib_gid *mgid, u32 qpn)
{
u32 out[MLX5_ST_SZ_DW(attach_to_mcg_out)] = {0};
u32 in[MLX5_ST_SZ_DW(attach_to_mcg_in)] = {0};
void *gid;
MLX5_SET(attach_to_mcg_in, in, opcode, MLX5_CMD_OP_ATTACH_TO_MCG);
MLX5_SET(attach_to_mcg_in, in, qpn, qpn);
gid = MLX5_ADDR_OF(attach_to_mcg_in, in, multicast_gid);
memcpy(gid, mgid, sizeof(*mgid));
return mlx5_cmd_exec(dev, in, sizeof(in), out, sizeof(out));
}
int mlx5_core_detach_mcg(struct mlx5_core_dev *dev, union ib_gid *mgid, u32 qpn)
{
u32 out[MLX5_ST_SZ_DW(detach_from_mcg_out)] = {0};
u32 in[MLX5_ST_SZ_DW(detach_from_mcg_in)] = {0};
void *gid;
MLX5_SET(detach_from_mcg_in, in, opcode, MLX5_CMD_OP_DETACH_FROM_MCG);
MLX5_SET(detach_from_mcg_in, in, qpn, qpn);
gid = MLX5_ADDR_OF(detach_from_mcg_in, in, multicast_gid);
memcpy(gid, mgid, sizeof(*mgid));
return mlx5_cmd_exec(dev, in, sizeof(in), out, sizeof(out));
}
