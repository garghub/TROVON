int mlx5_core_attach_mcg(struct mlx5_core_dev *dev, union ib_gid *mgid, u32 qpn)
{
struct mlx5_attach_mcg_mbox_in in;
struct mlx5_attach_mcg_mbox_out out;
int err;
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_ATTACH_TO_MCG);
memcpy(in.gid, mgid, sizeof(*mgid));
in.qpn = cpu_to_be32(qpn);
err = mlx5_cmd_exec(dev, &in, sizeof(in), &out, sizeof(out));
if (err)
return err;
if (out.hdr.status)
err = mlx5_cmd_status_to_err(&out.hdr);
return err;
}
int mlx5_core_detach_mcg(struct mlx5_core_dev *dev, union ib_gid *mgid, u32 qpn)
{
struct mlx5_detach_mcg_mbox_in in;
struct mlx5_detach_mcg_mbox_out out;
int err;
memset(&in, 0, sizeof(in));
memset(&out, 0, sizeof(out));
in.hdr.opcode = cpu_to_be16(MLX5_CMD_OP_DETTACH_FROM_MCG);
memcpy(in.gid, mgid, sizeof(*mgid));
in.qpn = cpu_to_be32(qpn);
err = mlx5_cmd_exec(dev, &in, sizeof(in), &out, sizeof(out));
if (err)
return err;
if (out.hdr.status)
err = mlx5_cmd_status_to_err(&out.hdr);
return err;
}
