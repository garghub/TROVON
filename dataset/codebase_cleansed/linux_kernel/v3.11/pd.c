int mlx5_core_alloc_pd(struct mlx5_core_dev *dev, u32 *pdn)
{
struct mlx5_alloc_pd_mbox_in in;
struct mlx5_alloc_pd_mbox_out out;
int err;
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_ALLOC_PD);
err = mlx5_cmd_exec(dev, &in, sizeof(in), &out, sizeof(out));
if (err)
return err;
if (out.hdr.status)
return mlx5_cmd_status_to_err(&out.hdr);
*pdn = be32_to_cpu(out.pdn) & 0xffffff;
return err;
}
int mlx5_core_dealloc_pd(struct mlx5_core_dev *dev, u32 pdn)
{
struct mlx5_dealloc_pd_mbox_in in;
struct mlx5_dealloc_pd_mbox_out out;
int err;
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_DEALLOC_PD);
in.pdn = cpu_to_be32(pdn);
err = mlx5_cmd_exec(dev, &in, sizeof(in), &out, sizeof(out));
if (err)
return err;
if (out.hdr.status)
return mlx5_cmd_status_to_err(&out.hdr);
return err;
}
