void *mlx5_accel_ipsec_sa_cmd_exec(struct mlx5_core_dev *mdev,
struct mlx5_accel_ipsec_sa *cmd)
{
if (!MLX5_IPSEC_DEV(mdev))
return ERR_PTR(-EOPNOTSUPP);
return mlx5_fpga_ipsec_sa_cmd_exec(mdev, cmd);
}
int mlx5_accel_ipsec_sa_cmd_wait(void *ctx)
{
return mlx5_fpga_ipsec_sa_cmd_wait(ctx);
}
u32 mlx5_accel_ipsec_device_caps(struct mlx5_core_dev *mdev)
{
return mlx5_fpga_ipsec_device_caps(mdev);
}
unsigned int mlx5_accel_ipsec_counters_count(struct mlx5_core_dev *mdev)
{
return mlx5_fpga_ipsec_counters_count(mdev);
}
int mlx5_accel_ipsec_counters_read(struct mlx5_core_dev *mdev, u64 *counters,
unsigned int count)
{
return mlx5_fpga_ipsec_counters_read(mdev, counters, count);
}
int mlx5_accel_ipsec_init(struct mlx5_core_dev *mdev)
{
return mlx5_fpga_ipsec_init(mdev);
}
void mlx5_accel_ipsec_cleanup(struct mlx5_core_dev *mdev)
{
mlx5_fpga_ipsec_cleanup(mdev);
}
