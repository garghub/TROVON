unsigned char spar_signal_insert(struct channel_header __iomem *ch, u32 queue,
void *sig)
{
void __iomem *psignal;
unsigned int head, tail, nof;
struct signal_queue_header __iomem *pqhdr =
(struct signal_queue_header __iomem *)
((char __iomem *)ch + readq(&ch->ch_space_offset))
+ queue;
head = readl(&pqhdr->head);
tail = readl(&pqhdr->tail);
if (((head + 1) % readl(&pqhdr->max_slots)) == tail) {
nof = readq(&pqhdr->num_overflows) + 1;
writeq(nof, &pqhdr->num_overflows);
return 0;
}
head = (head + 1) % readl(&pqhdr->max_slots);
psignal = (char __iomem *)pqhdr + readq(&pqhdr->sig_base_offset) +
(head * readl(&pqhdr->signal_size));
memcpy_toio(psignal, sig, readl(&pqhdr->signal_size));
mb();
writel(head, &pqhdr->head);
writeq(readq(&pqhdr->num_sent) + 1, &pqhdr->num_sent);
return 1;
}
unsigned char
spar_signal_remove(struct channel_header __iomem *ch, u32 queue, void *sig)
{
void __iomem *psource;
unsigned int head, tail;
struct signal_queue_header __iomem *pqhdr =
(struct signal_queue_header __iomem *)((char __iomem *)ch +
readq(&ch->ch_space_offset)) + queue;
head = readl(&pqhdr->head);
tail = readl(&pqhdr->tail);
if (head == tail) {
writeq(readq(&pqhdr->num_empty) + 1, &pqhdr->num_empty);
return 0;
}
tail = (tail + 1) % readl(&pqhdr->max_slots);
psource = (char __iomem *)pqhdr + readq(&pqhdr->sig_base_offset) +
(tail * readl(&pqhdr->signal_size));
memcpy_fromio(sig, psource, readl(&pqhdr->signal_size));
mb();
writel(tail, &pqhdr->tail);
writeq(readq(&pqhdr->num_received) + 1,
&pqhdr->num_received);
return 1;
}
unsigned int spar_signal_remove_all(struct channel_header *ch, u32 queue,
void *sig)
{
void *psource;
unsigned int head, tail, count = 0;
struct signal_queue_header *pqhdr =
(struct signal_queue_header *)((char *)ch +
ch->ch_space_offset) + queue;
head = pqhdr->head;
tail = pqhdr->tail;
if (head == tail)
return 0;
while (head != tail) {
tail = (tail + 1) % pqhdr->max_slots;
psource =
(char *)pqhdr + pqhdr->sig_base_offset +
(tail * pqhdr->signal_size);
memcpy((char *)sig + (pqhdr->signal_size * count),
psource, pqhdr->signal_size);
mb();
pqhdr->tail = tail;
count++;
pqhdr->num_received++;
}
return count;
}
unsigned char spar_signalqueue_empty(struct channel_header __iomem *ch,
u32 queue)
{
struct signal_queue_header __iomem *pqhdr =
(struct signal_queue_header __iomem *)((char __iomem *)ch +
readq(&ch->ch_space_offset)) + queue;
return readl(&pqhdr->head) == readl(&pqhdr->tail);
}
unsigned long long
uisqueue_interlocked_or(unsigned long long __iomem *tgt,
unsigned long long set)
{
unsigned long long i;
unsigned long long j;
j = readq(tgt);
do {
i = j;
j = cmpxchg((__force unsigned long long *)tgt, i, i | set);
} while (i != j);
return j;
}
unsigned long long
uisqueue_interlocked_and(unsigned long long __iomem *tgt,
unsigned long long set)
{
unsigned long long i;
unsigned long long j;
j = readq(tgt);
do {
i = j;
j = cmpxchg((__force unsigned long long *)tgt, i, i & set);
} while (i != j);
return j;
}
static u8
do_locked_client_insert(struct uisqueue_info *queueinfo,
unsigned int whichqueue,
void *signal,
spinlock_t *lock,
u8 *channel_id)
{
unsigned long flags;
u8 rc = 0;
spin_lock_irqsave(lock, flags);
if (!spar_channel_client_acquire_os(queueinfo->chan, channel_id))
goto unlock;
if (spar_signal_insert(queueinfo->chan, whichqueue, signal)) {
queueinfo->packets_sent++;
rc = 1;
}
spar_channel_client_release_os(queueinfo->chan, channel_id);
unlock:
spin_unlock_irqrestore((spinlock_t *)lock, flags);
return rc;
}
int
uisqueue_put_cmdrsp_with_lock_client(struct uisqueue_info *queueinfo,
struct uiscmdrsp *cmdrsp,
unsigned int whichqueue,
void *insertlock,
unsigned char issue_irq_if_empty,
u64 irq_handle,
char oktowait, u8 *channel_id)
{
while (!do_locked_client_insert(queueinfo, whichqueue, cmdrsp,
(spinlock_t *)insertlock,
channel_id)) {
if (oktowait != OK_TO_WAIT)
return 0;
set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout(msecs_to_jiffies(10));
}
return 1;
}
int
uisqueue_get_cmdrsp(struct uisqueue_info *queueinfo,
void *cmdrsp, unsigned int whichqueue)
{
if (!spar_signal_remove(queueinfo->chan, whichqueue, cmdrsp))
return 0;
queueinfo->packets_received++;
return 1;
}
