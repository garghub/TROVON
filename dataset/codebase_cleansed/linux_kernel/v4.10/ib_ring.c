void rds_ib_ring_init(struct rds_ib_work_ring *ring, u32 nr)
{
memset(ring, 0, sizeof(*ring));
ring->w_nr = nr;
rdsdebug("ring %p nr %u\n", ring, ring->w_nr);
}
static inline u32 __rds_ib_ring_used(struct rds_ib_work_ring *ring)
{
u32 diff;
diff = ring->w_alloc_ctr - (u32) atomic_read(&ring->w_free_ctr);
BUG_ON(diff > ring->w_nr);
return diff;
}
void rds_ib_ring_resize(struct rds_ib_work_ring *ring, u32 nr)
{
BUG_ON(__rds_ib_ring_used(ring));
ring->w_nr = nr;
}
static int __rds_ib_ring_empty(struct rds_ib_work_ring *ring)
{
return __rds_ib_ring_used(ring) == 0;
}
u32 rds_ib_ring_alloc(struct rds_ib_work_ring *ring, u32 val, u32 *pos)
{
u32 ret = 0, avail;
avail = ring->w_nr - __rds_ib_ring_used(ring);
rdsdebug("ring %p val %u next %u free %u\n", ring, val,
ring->w_alloc_ptr, avail);
if (val && avail) {
ret = min(val, avail);
*pos = ring->w_alloc_ptr;
ring->w_alloc_ptr = (ring->w_alloc_ptr + ret) % ring->w_nr;
ring->w_alloc_ctr += ret;
}
return ret;
}
void rds_ib_ring_free(struct rds_ib_work_ring *ring, u32 val)
{
ring->w_free_ptr = (ring->w_free_ptr + val) % ring->w_nr;
atomic_add(val, &ring->w_free_ctr);
if (__rds_ib_ring_empty(ring) &&
waitqueue_active(&rds_ib_ring_empty_wait))
wake_up(&rds_ib_ring_empty_wait);
}
void rds_ib_ring_unalloc(struct rds_ib_work_ring *ring, u32 val)
{
ring->w_alloc_ptr = (ring->w_alloc_ptr - val) % ring->w_nr;
ring->w_alloc_ctr -= val;
}
int rds_ib_ring_empty(struct rds_ib_work_ring *ring)
{
return __rds_ib_ring_empty(ring);
}
int rds_ib_ring_low(struct rds_ib_work_ring *ring)
{
return __rds_ib_ring_used(ring) <= (ring->w_nr >> 1);
}
u32 rds_ib_ring_oldest(struct rds_ib_work_ring *ring)
{
return ring->w_free_ptr;
}
u32 rds_ib_ring_completed(struct rds_ib_work_ring *ring, u32 wr_id, u32 oldest)
{
u32 ret;
if (oldest <= (unsigned long long)wr_id)
ret = (unsigned long long)wr_id - oldest + 1;
else
ret = ring->w_nr - oldest + (unsigned long long)wr_id + 1;
rdsdebug("ring %p ret %u wr_id %u oldest %u\n", ring, ret,
wr_id, oldest);
return ret;
}
