struct request *blk_queue_find_tag(struct request_queue *q, int tag)
{
return blk_map_queue_find_tag(q->queue_tags, tag);
}
void blk_free_tags(struct blk_queue_tag *bqt)
{
if (atomic_dec_and_test(&bqt->refcnt)) {
BUG_ON(find_first_bit(bqt->tag_map, bqt->max_depth) <
bqt->max_depth);
kfree(bqt->tag_index);
bqt->tag_index = NULL;
kfree(bqt->tag_map);
bqt->tag_map = NULL;
kfree(bqt);
}
}
void __blk_queue_free_tags(struct request_queue *q)
{
struct blk_queue_tag *bqt = q->queue_tags;
if (!bqt)
return;
blk_free_tags(bqt);
q->queue_tags = NULL;
queue_flag_clear_unlocked(QUEUE_FLAG_QUEUED, q);
}
void blk_queue_free_tags(struct request_queue *q)
{
queue_flag_clear_unlocked(QUEUE_FLAG_QUEUED, q);
}
static int
init_tag_map(struct request_queue *q, struct blk_queue_tag *tags, int depth)
{
struct request **tag_index;
unsigned long *tag_map;
int nr_ulongs;
if (q && depth > q->nr_requests * 2) {
depth = q->nr_requests * 2;
printk(KERN_ERR "%s: adjusted depth to %d\n",
__func__, depth);
}
tag_index = kzalloc(depth * sizeof(struct request *), GFP_ATOMIC);
if (!tag_index)
goto fail;
nr_ulongs = ALIGN(depth, BITS_PER_LONG) / BITS_PER_LONG;
tag_map = kzalloc(nr_ulongs * sizeof(unsigned long), GFP_ATOMIC);
if (!tag_map)
goto fail;
tags->real_max_depth = depth;
tags->max_depth = depth;
tags->tag_index = tag_index;
tags->tag_map = tag_map;
return 0;
fail:
kfree(tag_index);
return -ENOMEM;
}
static struct blk_queue_tag *__blk_queue_init_tags(struct request_queue *q,
int depth, int alloc_policy)
{
struct blk_queue_tag *tags;
tags = kmalloc(sizeof(struct blk_queue_tag), GFP_ATOMIC);
if (!tags)
goto fail;
if (init_tag_map(q, tags, depth))
goto fail;
atomic_set(&tags->refcnt, 1);
tags->alloc_policy = alloc_policy;
tags->next_tag = 0;
return tags;
fail:
kfree(tags);
return NULL;
}
struct blk_queue_tag *blk_init_tags(int depth, int alloc_policy)
{
return __blk_queue_init_tags(NULL, depth, alloc_policy);
}
int blk_queue_init_tags(struct request_queue *q, int depth,
struct blk_queue_tag *tags, int alloc_policy)
{
int rc;
BUG_ON(tags && q->queue_tags && tags != q->queue_tags);
if (!tags && !q->queue_tags) {
tags = __blk_queue_init_tags(q, depth, alloc_policy);
if (!tags)
return -ENOMEM;
} else if (q->queue_tags) {
rc = blk_queue_resize_tags(q, depth);
if (rc)
return rc;
queue_flag_set(QUEUE_FLAG_QUEUED, q);
return 0;
} else
atomic_inc(&tags->refcnt);
q->queue_tags = tags;
queue_flag_set_unlocked(QUEUE_FLAG_QUEUED, q);
INIT_LIST_HEAD(&q->tag_busy_list);
return 0;
}
int blk_queue_resize_tags(struct request_queue *q, int new_depth)
{
struct blk_queue_tag *bqt = q->queue_tags;
struct request **tag_index;
unsigned long *tag_map;
int max_depth, nr_ulongs;
if (!bqt)
return -ENXIO;
if (new_depth <= bqt->real_max_depth) {
bqt->max_depth = new_depth;
return 0;
}
if (atomic_read(&bqt->refcnt) != 1)
return -EBUSY;
tag_index = bqt->tag_index;
tag_map = bqt->tag_map;
max_depth = bqt->real_max_depth;
if (init_tag_map(q, bqt, new_depth))
return -ENOMEM;
memcpy(bqt->tag_index, tag_index, max_depth * sizeof(struct request *));
nr_ulongs = ALIGN(max_depth, BITS_PER_LONG) / BITS_PER_LONG;
memcpy(bqt->tag_map, tag_map, nr_ulongs * sizeof(unsigned long));
kfree(tag_index);
kfree(tag_map);
return 0;
}
void blk_queue_end_tag(struct request_queue *q, struct request *rq)
{
struct blk_queue_tag *bqt = q->queue_tags;
unsigned tag = rq->tag;
BUG_ON(tag >= bqt->real_max_depth);
list_del_init(&rq->queuelist);
rq->cmd_flags &= ~REQ_QUEUED;
rq->tag = -1;
if (unlikely(bqt->tag_index[tag] == NULL))
printk(KERN_ERR "%s: tag %d is missing\n",
__func__, tag);
bqt->tag_index[tag] = NULL;
if (unlikely(!test_bit(tag, bqt->tag_map))) {
printk(KERN_ERR "%s: attempt to clear non-busy tag (%d)\n",
__func__, tag);
return;
}
clear_bit_unlock(tag, bqt->tag_map);
}
int blk_queue_start_tag(struct request_queue *q, struct request *rq)
{
struct blk_queue_tag *bqt = q->queue_tags;
unsigned max_depth;
int tag;
if (unlikely((rq->cmd_flags & REQ_QUEUED))) {
printk(KERN_ERR
"%s: request %p for device [%s] already tagged %d",
__func__, rq,
rq->rq_disk ? rq->rq_disk->disk_name : "?", rq->tag);
BUG();
}
max_depth = bqt->max_depth;
if (!rq_is_sync(rq) && max_depth > 1) {
switch (max_depth) {
case 2:
max_depth = 1;
break;
case 3:
max_depth = 2;
break;
default:
max_depth -= 2;
}
if (q->in_flight[BLK_RW_ASYNC] > max_depth)
return 1;
}
do {
if (bqt->alloc_policy == BLK_TAG_ALLOC_FIFO) {
tag = find_first_zero_bit(bqt->tag_map, max_depth);
if (tag >= max_depth)
return 1;
} else {
int start = bqt->next_tag;
int size = min_t(int, bqt->max_depth, max_depth + start);
tag = find_next_zero_bit(bqt->tag_map, size, start);
if (tag >= size && start + size > bqt->max_depth) {
size = start + size - bqt->max_depth;
tag = find_first_zero_bit(bqt->tag_map, size);
}
if (tag >= size)
return 1;
}
} while (test_and_set_bit_lock(tag, bqt->tag_map));
bqt->next_tag = (tag + 1) % bqt->max_depth;
rq->cmd_flags |= REQ_QUEUED;
rq->tag = tag;
bqt->tag_index[tag] = rq;
blk_start_request(rq);
list_add(&rq->queuelist, &q->tag_busy_list);
return 0;
}
void blk_queue_invalidate_tags(struct request_queue *q)
{
struct list_head *tmp, *n;
list_for_each_safe(tmp, n, &q->tag_busy_list)
blk_requeue_request(q, list_entry_rq(tmp));
}
