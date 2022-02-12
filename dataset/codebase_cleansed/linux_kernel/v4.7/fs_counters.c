static void mlx5_fc_stats_work(struct work_struct *work)
{
struct mlx5_core_dev *dev = container_of(work, struct mlx5_core_dev,
priv.fc_stats.work.work);
struct mlx5_fc_stats *fc_stats = &dev->priv.fc_stats;
unsigned long now = jiffies;
struct mlx5_fc *counter;
struct mlx5_fc *tmp;
int err = 0;
spin_lock(&fc_stats->addlist_lock);
list_splice_tail_init(&fc_stats->addlist, &fc_stats->list);
if (!list_empty(&fc_stats->list))
queue_delayed_work(fc_stats->wq, &fc_stats->work, MLX5_FC_STATS_PERIOD);
spin_unlock(&fc_stats->addlist_lock);
list_for_each_entry_safe(counter, tmp, &fc_stats->list, list) {
struct mlx5_fc_cache *c = &counter->cache;
u64 packets;
u64 bytes;
if (counter->deleted) {
list_del(&counter->list);
mlx5_cmd_fc_free(dev, counter->id);
kfree(counter);
continue;
}
if (time_before(now, fc_stats->next_query))
continue;
err = mlx5_cmd_fc_query(dev, counter->id, &packets, &bytes);
if (err) {
pr_err("Error querying stats for counter id %d\n",
counter->id);
continue;
}
if (packets == c->packets)
continue;
c->lastuse = jiffies;
c->packets = packets;
c->bytes = bytes;
}
if (time_after_eq(now, fc_stats->next_query))
fc_stats->next_query = now + MLX5_FC_STATS_PERIOD;
}
struct mlx5_fc *mlx5_fc_create(struct mlx5_core_dev *dev, bool aging)
{
struct mlx5_fc_stats *fc_stats = &dev->priv.fc_stats;
struct mlx5_fc *counter;
int err;
counter = kzalloc(sizeof(*counter), GFP_KERNEL);
if (!counter)
return ERR_PTR(-ENOMEM);
err = mlx5_cmd_fc_alloc(dev, &counter->id);
if (err)
goto err_out;
if (aging) {
counter->aging = true;
spin_lock(&fc_stats->addlist_lock);
list_add(&counter->list, &fc_stats->addlist);
spin_unlock(&fc_stats->addlist_lock);
mod_delayed_work(fc_stats->wq, &fc_stats->work, 0);
}
return counter;
err_out:
kfree(counter);
return ERR_PTR(err);
}
void mlx5_fc_destroy(struct mlx5_core_dev *dev, struct mlx5_fc *counter)
{
struct mlx5_fc_stats *fc_stats = &dev->priv.fc_stats;
if (!counter)
return;
if (counter->aging) {
counter->deleted = true;
mod_delayed_work(fc_stats->wq, &fc_stats->work, 0);
return;
}
mlx5_cmd_fc_free(dev, counter->id);
kfree(counter);
}
int mlx5_init_fc_stats(struct mlx5_core_dev *dev)
{
struct mlx5_fc_stats *fc_stats = &dev->priv.fc_stats;
INIT_LIST_HEAD(&fc_stats->list);
INIT_LIST_HEAD(&fc_stats->addlist);
spin_lock_init(&fc_stats->addlist_lock);
fc_stats->wq = create_singlethread_workqueue("mlx5_fc");
if (!fc_stats->wq)
return -ENOMEM;
INIT_DELAYED_WORK(&fc_stats->work, mlx5_fc_stats_work);
return 0;
}
void mlx5_cleanup_fc_stats(struct mlx5_core_dev *dev)
{
struct mlx5_fc_stats *fc_stats = &dev->priv.fc_stats;
struct mlx5_fc *counter;
struct mlx5_fc *tmp;
cancel_delayed_work_sync(&dev->priv.fc_stats.work);
destroy_workqueue(dev->priv.fc_stats.wq);
dev->priv.fc_stats.wq = NULL;
list_splice_tail_init(&fc_stats->addlist, &fc_stats->list);
list_for_each_entry_safe(counter, tmp, &fc_stats->list, list) {
list_del(&counter->list);
mlx5_cmd_fc_free(dev, counter->id);
kfree(counter);
}
}
void mlx5_fc_query_cached(struct mlx5_fc *counter,
u64 *bytes, u64 *packets, u64 *lastuse)
{
struct mlx5_fc_cache c;
c = counter->cache;
*bytes = c.bytes - counter->lastbytes;
*packets = c.packets - counter->lastpackets;
*lastuse = c.lastuse;
counter->lastbytes = c.bytes;
counter->lastpackets = c.packets;
}
