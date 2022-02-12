int mlx5e_create_tir(struct mlx5_core_dev *mdev,
struct mlx5e_tir *tir, u32 *in, int inlen)
{
int err;
err = mlx5_core_create_tir(mdev, in, inlen, &tir->tirn);
if (err)
return err;
list_add(&tir->list, &mdev->mlx5e_res.td.tirs_list);
return 0;
}
void mlx5e_destroy_tir(struct mlx5_core_dev *mdev,
struct mlx5e_tir *tir)
{
mlx5_core_destroy_tir(mdev, tir->tirn);
list_del(&tir->list);
}
static int mlx5e_create_mkey(struct mlx5_core_dev *mdev, u32 pdn,
struct mlx5_core_mkey *mkey)
{
int inlen = MLX5_ST_SZ_BYTES(create_mkey_in);
void *mkc;
u32 *in;
int err;
in = mlx5_vzalloc(inlen);
if (!in)
return -ENOMEM;
mkc = MLX5_ADDR_OF(create_mkey_in, in, memory_key_mkey_entry);
MLX5_SET(mkc, mkc, access_mode, MLX5_MKC_ACCESS_MODE_PA);
MLX5_SET(mkc, mkc, lw, 1);
MLX5_SET(mkc, mkc, lr, 1);
MLX5_SET(mkc, mkc, pd, pdn);
MLX5_SET(mkc, mkc, length64, 1);
MLX5_SET(mkc, mkc, qpn, 0xffffff);
err = mlx5_core_create_mkey(mdev, mkey, in, inlen);
kvfree(in);
return err;
}
int mlx5e_create_mdev_resources(struct mlx5_core_dev *mdev)
{
struct mlx5e_resources *res = &mdev->mlx5e_res;
int err;
err = mlx5_core_alloc_pd(mdev, &res->pdn);
if (err) {
mlx5_core_err(mdev, "alloc pd failed, %d\n", err);
return err;
}
err = mlx5_core_alloc_transport_domain(mdev, &res->td.tdn);
if (err) {
mlx5_core_err(mdev, "alloc td failed, %d\n", err);
goto err_dealloc_pd;
}
err = mlx5e_create_mkey(mdev, res->pdn, &res->mkey);
if (err) {
mlx5_core_err(mdev, "create mkey failed, %d\n", err);
goto err_dealloc_transport_domain;
}
INIT_LIST_HEAD(&mdev->mlx5e_res.td.tirs_list);
return 0;
err_dealloc_transport_domain:
mlx5_core_dealloc_transport_domain(mdev, res->td.tdn);
err_dealloc_pd:
mlx5_core_dealloc_pd(mdev, res->pdn);
return err;
}
void mlx5e_destroy_mdev_resources(struct mlx5_core_dev *mdev)
{
struct mlx5e_resources *res = &mdev->mlx5e_res;
mlx5_core_destroy_mkey(mdev, &res->mkey);
mlx5_core_dealloc_transport_domain(mdev, res->td.tdn);
mlx5_core_dealloc_pd(mdev, res->pdn);
}
int mlx5e_refresh_tirs_self_loopback(struct mlx5_core_dev *mdev,
bool enable_uc_lb)
{
struct mlx5e_tir *tir;
void *in;
int inlen;
int err = 0;
inlen = MLX5_ST_SZ_BYTES(modify_tir_in);
in = mlx5_vzalloc(inlen);
if (!in)
return -ENOMEM;
if (enable_uc_lb)
MLX5_SET(modify_tir_in, in, ctx.self_lb_block,
MLX5_TIRC_SELF_LB_BLOCK_BLOCK_UNICAST_);
MLX5_SET(modify_tir_in, in, bitmask.self_lb_en, 1);
list_for_each_entry(tir, &mdev->mlx5e_res.td.tirs_list, list) {
err = mlx5_core_modify_tir(mdev, tir->tirn, in, inlen);
if (err)
goto out;
}
out:
kvfree(in);
return err;
}
