struct mlx5_fpga_conn *
mlx5_fpga_sbu_conn_create(struct mlx5_fpga_device *fdev,
struct mlx5_fpga_conn_attr *attr)
{
return mlx5_fpga_conn_create(fdev, attr, MLX5_FPGA_QPC_QP_TYPE_SANDBOX_QP);
}
void mlx5_fpga_sbu_conn_destroy(struct mlx5_fpga_conn *conn)
{
mlx5_fpga_conn_destroy(conn);
}
int mlx5_fpga_sbu_conn_sendmsg(struct mlx5_fpga_conn *conn,
struct mlx5_fpga_dma_buf *buf)
{
return mlx5_fpga_conn_send(conn, buf);
}
static int mlx5_fpga_mem_read_i2c(struct mlx5_fpga_device *fdev, size_t size,
u64 addr, u8 *buf)
{
size_t max_size = MLX5_FPGA_ACCESS_REG_SIZE_MAX;
size_t bytes_done = 0;
u8 actual_size;
int err;
if (!fdev->mdev)
return -ENOTCONN;
while (bytes_done < size) {
actual_size = min(max_size, (size - bytes_done));
err = mlx5_fpga_access_reg(fdev->mdev, actual_size,
addr + bytes_done,
buf + bytes_done, false);
if (err) {
mlx5_fpga_err(fdev, "Failed to read over I2C: %d\n",
err);
break;
}
bytes_done += actual_size;
}
return err;
}
static int mlx5_fpga_mem_write_i2c(struct mlx5_fpga_device *fdev, size_t size,
u64 addr, u8 *buf)
{
size_t max_size = MLX5_FPGA_ACCESS_REG_SIZE_MAX;
size_t bytes_done = 0;
u8 actual_size;
int err;
if (!fdev->mdev)
return -ENOTCONN;
while (bytes_done < size) {
actual_size = min(max_size, (size - bytes_done));
err = mlx5_fpga_access_reg(fdev->mdev, actual_size,
addr + bytes_done,
buf + bytes_done, true);
if (err) {
mlx5_fpga_err(fdev, "Failed to write FPGA crspace\n");
break;
}
bytes_done += actual_size;
}
return err;
}
int mlx5_fpga_mem_read(struct mlx5_fpga_device *fdev, size_t size, u64 addr,
void *buf, enum mlx5_fpga_access_type access_type)
{
int ret;
switch (access_type) {
case MLX5_FPGA_ACCESS_TYPE_I2C:
ret = mlx5_fpga_mem_read_i2c(fdev, size, addr, buf);
if (ret)
return ret;
break;
default:
mlx5_fpga_warn(fdev, "Unexpected read access_type %u\n",
access_type);
return -EACCES;
}
return size;
}
int mlx5_fpga_mem_write(struct mlx5_fpga_device *fdev, size_t size, u64 addr,
void *buf, enum mlx5_fpga_access_type access_type)
{
int ret;
switch (access_type) {
case MLX5_FPGA_ACCESS_TYPE_I2C:
ret = mlx5_fpga_mem_write_i2c(fdev, size, addr, buf);
if (ret)
return ret;
break;
default:
mlx5_fpga_warn(fdev, "Unexpected write access_type %u\n",
access_type);
return -EACCES;
}
return size;
}
int mlx5_fpga_get_sbu_caps(struct mlx5_fpga_device *fdev, int size, void *buf)
{
return mlx5_fpga_sbu_caps(fdev->mdev, buf, size);
}
