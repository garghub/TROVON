int en_print(const char *level, const struct mlx4_en_priv *priv,
const char *format, ...)
{
va_list args;
struct va_format vaf;
int i;
va_start(args, format);
vaf.fmt = format;
vaf.va = &args;
if (priv->registered)
i = printk("%s%s: %s: %pV",
level, DRV_NAME, priv->dev->name, &vaf);
else
i = printk("%s%s: %s: Port %d: %pV",
level, DRV_NAME, dev_name(&priv->mdev->pdev->dev),
priv->port, &vaf);
va_end(args);
return i;
}
void mlx4_en_update_loopback_state(struct net_device *dev,
netdev_features_t features)
{
struct mlx4_en_priv *priv = netdev_priv(dev);
priv->flags &= ~(MLX4_EN_FLAG_RX_FILTER_NEEDED|
MLX4_EN_FLAG_ENABLE_HW_LOOPBACK);
if (mlx4_is_mfunc(priv->mdev->dev) &&
!(features & NETIF_F_LOOPBACK) && !priv->validate_loopback)
priv->flags |= MLX4_EN_FLAG_RX_FILTER_NEEDED;
if (mlx4_is_mfunc(priv->mdev->dev) || priv->validate_loopback)
priv->flags |= MLX4_EN_FLAG_ENABLE_HW_LOOPBACK;
}
static int mlx4_en_get_profile(struct mlx4_en_dev *mdev)
{
struct mlx4_en_profile *params = &mdev->profile;
int i;
params->udp_rss = udp_rss;
params->num_tx_rings_p_up = mlx4_low_memory_profile() ?
MLX4_EN_MIN_TX_RING_P_UP :
min_t(int, num_online_cpus(), MLX4_EN_MAX_TX_RING_P_UP);
if (params->udp_rss && !(mdev->dev->caps.flags
& MLX4_DEV_CAP_FLAG_UDP_RSS)) {
mlx4_warn(mdev, "UDP RSS is not supported on this device\n");
params->udp_rss = 0;
}
for (i = 1; i <= MLX4_MAX_PORTS; i++) {
params->prof[i].rx_pause = 1;
params->prof[i].rx_ppp = pfcrx;
params->prof[i].tx_pause = 1;
params->prof[i].tx_ppp = pfctx;
params->prof[i].tx_ring_size = MLX4_EN_DEF_TX_RING_SIZE;
params->prof[i].rx_ring_size = MLX4_EN_DEF_RX_RING_SIZE;
params->prof[i].tx_ring_num = params->num_tx_rings_p_up *
MLX4_EN_NUM_UP;
params->prof[i].rss_rings = 0;
params->prof[i].inline_thold = inline_thold;
}
return 0;
}
static void *mlx4_en_get_netdev(struct mlx4_dev *dev, void *ctx, u8 port)
{
struct mlx4_en_dev *endev = ctx;
return endev->pndev[port];
}
static void mlx4_en_event(struct mlx4_dev *dev, void *endev_ptr,
enum mlx4_dev_event event, unsigned long port)
{
struct mlx4_en_dev *mdev = (struct mlx4_en_dev *) endev_ptr;
struct mlx4_en_priv *priv;
switch (event) {
case MLX4_DEV_EVENT_PORT_UP:
case MLX4_DEV_EVENT_PORT_DOWN:
if (!mdev->pndev[port])
return;
priv = netdev_priv(mdev->pndev[port]);
priv->link_state = event;
queue_work(mdev->workqueue, &priv->linkstate_task);
break;
case MLX4_DEV_EVENT_CATASTROPHIC_ERROR:
mlx4_err(mdev, "Internal error detected, restarting device\n");
break;
case MLX4_DEV_EVENT_SLAVE_INIT:
case MLX4_DEV_EVENT_SLAVE_SHUTDOWN:
break;
default:
if (port < 1 || port > dev->caps.num_ports ||
!mdev->pndev[port])
return;
mlx4_warn(mdev, "Unhandled event %d for port %d\n", event,
(int) port);
}
}
static void mlx4_en_remove(struct mlx4_dev *dev, void *endev_ptr)
{
struct mlx4_en_dev *mdev = endev_ptr;
int i;
mutex_lock(&mdev->state_lock);
mdev->device_up = false;
mutex_unlock(&mdev->state_lock);
mlx4_foreach_port(i, dev, MLX4_PORT_TYPE_ETH)
if (mdev->pndev[i])
mlx4_en_destroy_netdev(mdev->pndev[i]);
if (mdev->dev->caps.flags2 & MLX4_DEV_CAP_FLAG2_TS)
mlx4_en_remove_timestamp(mdev);
flush_workqueue(mdev->workqueue);
destroy_workqueue(mdev->workqueue);
(void) mlx4_mr_free(dev, &mdev->mr);
iounmap(mdev->uar_map);
mlx4_uar_free(dev, &mdev->priv_uar);
mlx4_pd_free(dev, mdev->priv_pdn);
kfree(mdev);
}
static void *mlx4_en_add(struct mlx4_dev *dev)
{
struct mlx4_en_dev *mdev;
int i;
int err;
printk_once(KERN_INFO "%s", mlx4_en_version);
mdev = kzalloc(sizeof(*mdev), GFP_KERNEL);
if (!mdev) {
err = -ENOMEM;
goto err_free_res;
}
if (mlx4_pd_alloc(dev, &mdev->priv_pdn))
goto err_free_dev;
if (mlx4_uar_alloc(dev, &mdev->priv_uar))
goto err_pd;
mdev->uar_map = ioremap((phys_addr_t) mdev->priv_uar.pfn << PAGE_SHIFT,
PAGE_SIZE);
if (!mdev->uar_map)
goto err_uar;
spin_lock_init(&mdev->uar_lock);
mdev->dev = dev;
mdev->dma_device = &(dev->pdev->dev);
mdev->pdev = dev->pdev;
mdev->device_up = false;
mdev->LSO_support = !!(dev->caps.flags & (1 << 15));
if (!mdev->LSO_support)
mlx4_warn(mdev, "LSO not supported, please upgrade to later FW version to enable LSO\n");
if (mlx4_mr_alloc(mdev->dev, mdev->priv_pdn, 0, ~0ull,
MLX4_PERM_LOCAL_WRITE | MLX4_PERM_LOCAL_READ,
0, 0, &mdev->mr)) {
mlx4_err(mdev, "Failed allocating memory region\n");
goto err_map;
}
if (mlx4_mr_enable(mdev->dev, &mdev->mr)) {
mlx4_err(mdev, "Failed enabling memory region\n");
goto err_mr;
}
err = mlx4_en_get_profile(mdev);
if (err) {
mlx4_err(mdev, "Bad module parameters, aborting\n");
goto err_mr;
}
mdev->port_cnt = 0;
mlx4_foreach_port(i, dev, MLX4_PORT_TYPE_ETH)
mdev->port_cnt++;
if (mdev->dev->caps.flags2 & MLX4_DEV_CAP_FLAG2_TS)
mlx4_en_init_timestamp(mdev);
mlx4_en_set_num_rx_rings(mdev);
mdev->workqueue = create_singlethread_workqueue("mlx4_en");
if (!mdev->workqueue) {
err = -ENOMEM;
goto err_mr;
}
mutex_init(&mdev->state_lock);
mdev->device_up = true;
mlx4_foreach_port(i, dev, MLX4_PORT_TYPE_ETH) {
mlx4_info(mdev, "Activating port:%d\n", i);
if (mlx4_en_init_netdev(mdev, i, &mdev->profile.prof[i]))
mdev->pndev[i] = NULL;
}
return mdev;
err_mr:
(void) mlx4_mr_free(dev, &mdev->mr);
err_map:
if (mdev->uar_map)
iounmap(mdev->uar_map);
err_uar:
mlx4_uar_free(dev, &mdev->priv_uar);
err_pd:
mlx4_pd_free(dev, mdev->priv_pdn);
err_free_dev:
kfree(mdev);
err_free_res:
return NULL;
}
static void mlx4_en_verify_params(void)
{
if (pfctx > MAX_PFC_TX) {
pr_warn("mlx4_en: WARNING: illegal module parameter pfctx 0x%x - should be in range 0-0x%x, will be changed to default (0)\n",
pfctx, MAX_PFC_TX);
pfctx = 0;
}
if (pfcrx > MAX_PFC_RX) {
pr_warn("mlx4_en: WARNING: illegal module parameter pfcrx 0x%x - should be in range 0-0x%x, will be changed to default (0)\n",
pfcrx, MAX_PFC_RX);
pfcrx = 0;
}
if (inline_thold < MIN_PKT_LEN || inline_thold > MAX_INLINE) {
pr_warn("mlx4_en: WARNING: illegal module parameter inline_thold %d - should be in range %d-%d, will be changed to default (%d)\n",
inline_thold, MIN_PKT_LEN, MAX_INLINE, MAX_INLINE);
inline_thold = MAX_INLINE;
}
}
static int __init mlx4_en_init(void)
{
mlx4_en_verify_params();
return mlx4_register_interface(&mlx4_en_interface);
}
static void __exit mlx4_en_cleanup(void)
{
mlx4_unregister_interface(&mlx4_en_interface);
}
