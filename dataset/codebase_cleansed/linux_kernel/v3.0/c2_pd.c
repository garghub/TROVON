int c2_pd_alloc(struct c2_dev *c2dev, int privileged, struct c2_pd *pd)
{
u32 obj;
int ret = 0;
spin_lock(&c2dev->pd_table.lock);
obj = find_next_zero_bit(c2dev->pd_table.table, c2dev->pd_table.max,
c2dev->pd_table.last);
if (obj >= c2dev->pd_table.max)
obj = find_first_zero_bit(c2dev->pd_table.table,
c2dev->pd_table.max);
if (obj < c2dev->pd_table.max) {
pd->pd_id = obj;
__set_bit(obj, c2dev->pd_table.table);
c2dev->pd_table.last = obj+1;
if (c2dev->pd_table.last >= c2dev->pd_table.max)
c2dev->pd_table.last = 0;
} else
ret = -ENOMEM;
spin_unlock(&c2dev->pd_table.lock);
return ret;
}
void c2_pd_free(struct c2_dev *c2dev, struct c2_pd *pd)
{
spin_lock(&c2dev->pd_table.lock);
__clear_bit(pd->pd_id, c2dev->pd_table.table);
spin_unlock(&c2dev->pd_table.lock);
}
int __devinit c2_init_pd_table(struct c2_dev *c2dev)
{
c2dev->pd_table.last = 0;
c2dev->pd_table.max = c2dev->props.max_pd;
spin_lock_init(&c2dev->pd_table.lock);
c2dev->pd_table.table = kmalloc(BITS_TO_LONGS(c2dev->props.max_pd) *
sizeof(long), GFP_KERNEL);
if (!c2dev->pd_table.table)
return -ENOMEM;
bitmap_zero(c2dev->pd_table.table, c2dev->props.max_pd);
return 0;
}
void __devexit c2_cleanup_pd_table(struct c2_dev *c2dev)
{
kfree(c2dev->pd_table.table);
}
