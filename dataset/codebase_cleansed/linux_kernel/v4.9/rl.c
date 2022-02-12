static struct mlx5_rl_entry *find_rl_entry(struct mlx5_rl_table *table,
u32 rate)
{
struct mlx5_rl_entry *ret_entry = NULL;
bool empty_found = false;
int i;
for (i = 0; i < table->max_size; i++) {
if (table->rl_entry[i].rate == rate)
return &table->rl_entry[i];
if (!empty_found && !table->rl_entry[i].rate) {
empty_found = true;
ret_entry = &table->rl_entry[i];
}
}
return ret_entry;
}
static int mlx5_set_rate_limit_cmd(struct mlx5_core_dev *dev,
u32 rate, u16 index)
{
u32 in[MLX5_ST_SZ_DW(set_rate_limit_in)] = {0};
u32 out[MLX5_ST_SZ_DW(set_rate_limit_out)] = {0};
MLX5_SET(set_rate_limit_in, in, opcode,
MLX5_CMD_OP_SET_RATE_LIMIT);
MLX5_SET(set_rate_limit_in, in, rate_limit_index, index);
MLX5_SET(set_rate_limit_in, in, rate_limit, rate);
return mlx5_cmd_exec(dev, in, sizeof(in), out, sizeof(out));
}
bool mlx5_rl_is_in_range(struct mlx5_core_dev *dev, u32 rate)
{
struct mlx5_rl_table *table = &dev->priv.rl_table;
return (rate <= table->max_rate && rate >= table->min_rate);
}
int mlx5_rl_add_rate(struct mlx5_core_dev *dev, u32 rate, u16 *index)
{
struct mlx5_rl_table *table = &dev->priv.rl_table;
struct mlx5_rl_entry *entry;
int err = 0;
mutex_lock(&table->rl_lock);
if (!rate || !mlx5_rl_is_in_range(dev, rate)) {
mlx5_core_err(dev, "Invalid rate: %u, should be %u to %u\n",
rate, table->min_rate, table->max_rate);
err = -EINVAL;
goto out;
}
entry = find_rl_entry(table, rate);
if (!entry) {
mlx5_core_err(dev, "Max number of %u rates reached\n",
table->max_size);
err = -ENOSPC;
goto out;
}
if (entry->refcount) {
entry->refcount++;
} else {
err = mlx5_set_rate_limit_cmd(dev, rate, entry->index);
if (err) {
mlx5_core_err(dev, "Failed configuring rate: %u (%d)\n",
rate, err);
goto out;
}
entry->rate = rate;
entry->refcount = 1;
}
*index = entry->index;
out:
mutex_unlock(&table->rl_lock);
return err;
}
void mlx5_rl_remove_rate(struct mlx5_core_dev *dev, u32 rate)
{
struct mlx5_rl_table *table = &dev->priv.rl_table;
struct mlx5_rl_entry *entry = NULL;
if (rate == 0)
return;
mutex_lock(&table->rl_lock);
entry = find_rl_entry(table, rate);
if (!entry || !entry->refcount) {
mlx5_core_warn(dev, "Rate %u is not configured\n", rate);
goto out;
}
entry->refcount--;
if (!entry->refcount) {
mlx5_set_rate_limit_cmd(dev, 0, entry->index);
entry->rate = 0;
}
out:
mutex_unlock(&table->rl_lock);
}
int mlx5_init_rl_table(struct mlx5_core_dev *dev)
{
struct mlx5_rl_table *table = &dev->priv.rl_table;
int i;
mutex_init(&table->rl_lock);
if (!MLX5_CAP_GEN(dev, qos) || !MLX5_CAP_QOS(dev, packet_pacing)) {
table->max_size = 0;
return 0;
}
table->max_size = MLX5_CAP_QOS(dev, packet_pacing_rate_table_size) - 1;
table->max_rate = MLX5_CAP_QOS(dev, packet_pacing_max_rate);
table->min_rate = MLX5_CAP_QOS(dev, packet_pacing_min_rate);
table->rl_entry = kcalloc(table->max_size, sizeof(struct mlx5_rl_entry),
GFP_KERNEL);
if (!table->rl_entry)
return -ENOMEM;
for (i = 0; i < table->max_size; i++)
table->rl_entry[i].index = i + 1;
mlx5_core_info(dev, "Rate limit: %u rates are supported, range: %uMbps to %uMbps\n",
table->max_size,
table->min_rate >> 10,
table->max_rate >> 10);
return 0;
}
void mlx5_cleanup_rl_table(struct mlx5_core_dev *dev)
{
struct mlx5_rl_table *table = &dev->priv.rl_table;
int i;
for (i = 0; i < table->max_size; i++)
if (table->rl_entry[i].rate)
mlx5_set_rate_limit_cmd(dev, 0,
table->rl_entry[i].index);
kfree(dev->priv.rl_table.rl_entry);
}
