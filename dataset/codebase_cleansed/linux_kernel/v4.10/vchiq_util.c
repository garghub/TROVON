static inline int is_pow2(int i)
{
return i && !(i & (i - 1));
}
int vchiu_queue_init(VCHIU_QUEUE_T *queue, int size)
{
WARN_ON(!is_pow2(size));
queue->size = size;
queue->read = 0;
queue->write = 0;
queue->initialized = 1;
sema_init(&queue->pop, 0);
sema_init(&queue->push, 0);
queue->storage = kzalloc(size * sizeof(VCHIQ_HEADER_T *), GFP_KERNEL);
if (queue->storage == NULL) {
vchiu_queue_delete(queue);
return 0;
}
return 1;
}
void vchiu_queue_delete(VCHIU_QUEUE_T *queue)
{
kfree(queue->storage);
}
int vchiu_queue_is_empty(VCHIU_QUEUE_T *queue)
{
return queue->read == queue->write;
}
int vchiu_queue_is_full(VCHIU_QUEUE_T *queue)
{
return queue->write == queue->read + queue->size;
}
void vchiu_queue_push(VCHIU_QUEUE_T *queue, VCHIQ_HEADER_T *header)
{
if (!queue->initialized)
return;
while (queue->write == queue->read + queue->size) {
if (down_interruptible(&queue->pop) != 0) {
flush_signals(current);
}
}
smp_mb();
queue->storage[queue->write & (queue->size - 1)] = header;
smp_wmb();
queue->write++;
up(&queue->push);
}
VCHIQ_HEADER_T *vchiu_queue_peek(VCHIU_QUEUE_T *queue)
{
while (queue->write == queue->read) {
if (down_interruptible(&queue->push) != 0) {
flush_signals(current);
}
}
up(&queue->push);
smp_rmb();
return queue->storage[queue->read & (queue->size - 1)];
}
VCHIQ_HEADER_T *vchiu_queue_pop(VCHIU_QUEUE_T *queue)
{
VCHIQ_HEADER_T *header;
while (queue->write == queue->read) {
if (down_interruptible(&queue->push) != 0) {
flush_signals(current);
}
}
smp_rmb();
header = queue->storage[queue->read & (queue->size - 1)];
smp_mb();
queue->read++;
up(&queue->pop);
return header;
}
