int mlx5e_ipsec_get_count(struct mlx5e_priv *priv)
{
if (!priv->ipsec)
return 0;
return NUM_IPSEC_COUNTERS;
}
int mlx5e_ipsec_get_strings(struct mlx5e_priv *priv, uint8_t *data)
{
unsigned int i, idx = 0;
if (!priv->ipsec)
return 0;
for (i = 0; i < NUM_IPSEC_HW_COUNTERS; i++)
strcpy(data + (idx++) * ETH_GSTRING_LEN,
mlx5e_ipsec_hw_stats_desc[i].format);
for (i = 0; i < NUM_IPSEC_SW_COUNTERS; i++)
strcpy(data + (idx++) * ETH_GSTRING_LEN,
mlx5e_ipsec_sw_stats_desc[i].format);
return NUM_IPSEC_COUNTERS;
}
void mlx5e_ipsec_update_stats(struct mlx5e_priv *priv)
{
int ret;
if (!priv->ipsec)
return;
ret = mlx5_accel_ipsec_counters_read(priv->mdev, (u64 *)&priv->ipsec->stats,
NUM_IPSEC_HW_COUNTERS);
if (ret)
memset(&priv->ipsec->stats, 0, sizeof(priv->ipsec->stats));
}
int mlx5e_ipsec_get_stats(struct mlx5e_priv *priv, u64 *data)
{
int i, idx = 0;
if (!priv->ipsec)
return 0;
for (i = 0; i < NUM_IPSEC_HW_COUNTERS; i++)
data[idx++] = MLX5E_READ_CTR64_CPU(&priv->ipsec->stats,
mlx5e_ipsec_hw_stats_desc, i);
for (i = 0; i < NUM_IPSEC_SW_COUNTERS; i++)
data[idx++] = MLX5E_READ_CTR_ATOMIC64(&priv->ipsec->sw_stats,
mlx5e_ipsec_sw_stats_desc, i);
return NUM_IPSEC_COUNTERS;
}
