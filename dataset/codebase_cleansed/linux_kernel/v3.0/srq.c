void mlx4_srq_event(struct mlx4_dev *dev, u32 srqn, int event_type)
{
struct mlx4_srq_table *srq_table = &mlx4_priv(dev)->srq_table;
struct mlx4_srq *srq;
spin_lock(&srq_table->lock);
srq = radix_tree_lookup(&srq_table->tree, srqn & (dev->caps.num_srqs - 1));
if (srq)
atomic_inc(&srq->refcount);
spin_unlock(&srq_table->lock);
if (!srq) {
mlx4_warn(dev, "Async event for bogus SRQ %08x\n", srqn);
return;
}
srq->event(srq, event_type);
if (atomic_dec_and_test(&srq->refcount))
complete(&srq->free);
}
static int mlx4_SW2HW_SRQ(struct mlx4_dev *dev, struct mlx4_cmd_mailbox *mailbox,
int srq_num)
{
return mlx4_cmd(dev, mailbox->dma, srq_num, 0, MLX4_CMD_SW2HW_SRQ,
MLX4_CMD_TIME_CLASS_A);
}
static int mlx4_HW2SW_SRQ(struct mlx4_dev *dev, struct mlx4_cmd_mailbox *mailbox,
int srq_num)
{
return mlx4_cmd_box(dev, 0, mailbox ? mailbox->dma : 0, srq_num,
mailbox ? 0 : 1, MLX4_CMD_HW2SW_SRQ,
MLX4_CMD_TIME_CLASS_A);
}
static int mlx4_ARM_SRQ(struct mlx4_dev *dev, int srq_num, int limit_watermark)
{
return mlx4_cmd(dev, limit_watermark, srq_num, 0, MLX4_CMD_ARM_SRQ,
MLX4_CMD_TIME_CLASS_B);
}
static int mlx4_QUERY_SRQ(struct mlx4_dev *dev, struct mlx4_cmd_mailbox *mailbox,
int srq_num)
{
return mlx4_cmd_box(dev, 0, mailbox->dma, srq_num, 0, MLX4_CMD_QUERY_SRQ,
MLX4_CMD_TIME_CLASS_A);
}
int mlx4_srq_alloc(struct mlx4_dev *dev, u32 pdn, struct mlx4_mtt *mtt,
u64 db_rec, struct mlx4_srq *srq)
{
struct mlx4_srq_table *srq_table = &mlx4_priv(dev)->srq_table;
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_srq_context *srq_context;
u64 mtt_addr;
int err;
srq->srqn = mlx4_bitmap_alloc(&srq_table->bitmap);
if (srq->srqn == -1)
return -ENOMEM;
err = mlx4_table_get(dev, &srq_table->table, srq->srqn);
if (err)
goto err_out;
err = mlx4_table_get(dev, &srq_table->cmpt_table, srq->srqn);
if (err)
goto err_put;
spin_lock_irq(&srq_table->lock);
err = radix_tree_insert(&srq_table->tree, srq->srqn, srq);
spin_unlock_irq(&srq_table->lock);
if (err)
goto err_cmpt_put;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox)) {
err = PTR_ERR(mailbox);
goto err_radix;
}
srq_context = mailbox->buf;
memset(srq_context, 0, sizeof *srq_context);
srq_context->state_logsize_srqn = cpu_to_be32((ilog2(srq->max) << 24) |
srq->srqn);
srq_context->logstride = srq->wqe_shift - 4;
srq_context->log_page_size = mtt->page_shift - MLX4_ICM_PAGE_SHIFT;
mtt_addr = mlx4_mtt_addr(dev, mtt);
srq_context->mtt_base_addr_h = mtt_addr >> 32;
srq_context->mtt_base_addr_l = cpu_to_be32(mtt_addr & 0xffffffff);
srq_context->pd = cpu_to_be32(pdn);
srq_context->db_rec_addr = cpu_to_be64(db_rec);
err = mlx4_SW2HW_SRQ(dev, mailbox, srq->srqn);
mlx4_free_cmd_mailbox(dev, mailbox);
if (err)
goto err_radix;
atomic_set(&srq->refcount, 1);
init_completion(&srq->free);
return 0;
err_radix:
spin_lock_irq(&srq_table->lock);
radix_tree_delete(&srq_table->tree, srq->srqn);
spin_unlock_irq(&srq_table->lock);
err_cmpt_put:
mlx4_table_put(dev, &srq_table->cmpt_table, srq->srqn);
err_put:
mlx4_table_put(dev, &srq_table->table, srq->srqn);
err_out:
mlx4_bitmap_free(&srq_table->bitmap, srq->srqn);
return err;
}
void mlx4_srq_free(struct mlx4_dev *dev, struct mlx4_srq *srq)
{
struct mlx4_srq_table *srq_table = &mlx4_priv(dev)->srq_table;
int err;
err = mlx4_HW2SW_SRQ(dev, NULL, srq->srqn);
if (err)
mlx4_warn(dev, "HW2SW_SRQ failed (%d) for SRQN %06x\n", err, srq->srqn);
spin_lock_irq(&srq_table->lock);
radix_tree_delete(&srq_table->tree, srq->srqn);
spin_unlock_irq(&srq_table->lock);
if (atomic_dec_and_test(&srq->refcount))
complete(&srq->free);
wait_for_completion(&srq->free);
mlx4_table_put(dev, &srq_table->table, srq->srqn);
mlx4_bitmap_free(&srq_table->bitmap, srq->srqn);
}
int mlx4_srq_arm(struct mlx4_dev *dev, struct mlx4_srq *srq, int limit_watermark)
{
return mlx4_ARM_SRQ(dev, srq->srqn, limit_watermark);
}
int mlx4_srq_query(struct mlx4_dev *dev, struct mlx4_srq *srq, int *limit_watermark)
{
struct mlx4_cmd_mailbox *mailbox;
struct mlx4_srq_context *srq_context;
int err;
mailbox = mlx4_alloc_cmd_mailbox(dev);
if (IS_ERR(mailbox))
return PTR_ERR(mailbox);
srq_context = mailbox->buf;
err = mlx4_QUERY_SRQ(dev, mailbox, srq->srqn);
if (err)
goto err_out;
*limit_watermark = be16_to_cpu(srq_context->limit_watermark);
err_out:
mlx4_free_cmd_mailbox(dev, mailbox);
return err;
}
int mlx4_init_srq_table(struct mlx4_dev *dev)
{
struct mlx4_srq_table *srq_table = &mlx4_priv(dev)->srq_table;
int err;
spin_lock_init(&srq_table->lock);
INIT_RADIX_TREE(&srq_table->tree, GFP_ATOMIC);
err = mlx4_bitmap_init(&srq_table->bitmap, dev->caps.num_srqs,
dev->caps.num_srqs - 1, dev->caps.reserved_srqs, 0);
if (err)
return err;
return 0;
}
void mlx4_cleanup_srq_table(struct mlx4_dev *dev)
{
mlx4_bitmap_cleanup(&mlx4_priv(dev)->srq_table.bitmap);
}
