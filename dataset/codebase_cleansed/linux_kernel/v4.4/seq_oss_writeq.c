struct seq_oss_writeq *
snd_seq_oss_writeq_new(struct seq_oss_devinfo *dp, int maxlen)
{
struct seq_oss_writeq *q;
struct snd_seq_client_pool pool;
if ((q = kzalloc(sizeof(*q), GFP_KERNEL)) == NULL)
return NULL;
q->dp = dp;
q->maxlen = maxlen;
spin_lock_init(&q->sync_lock);
q->sync_event_put = 0;
q->sync_time = 0;
init_waitqueue_head(&q->sync_sleep);
memset(&pool, 0, sizeof(pool));
pool.client = dp->cseq;
pool.output_pool = maxlen;
pool.output_room = maxlen / 2;
snd_seq_oss_control(dp, SNDRV_SEQ_IOCTL_SET_CLIENT_POOL, &pool);
return q;
}
void
snd_seq_oss_writeq_delete(struct seq_oss_writeq *q)
{
if (q) {
snd_seq_oss_writeq_clear(q);
kfree(q);
}
}
void
snd_seq_oss_writeq_clear(struct seq_oss_writeq *q)
{
struct snd_seq_remove_events reset;
memset(&reset, 0, sizeof(reset));
reset.remove_mode = SNDRV_SEQ_REMOVE_OUTPUT;
snd_seq_oss_control(q->dp, SNDRV_SEQ_IOCTL_REMOVE_EVENTS, &reset);
snd_seq_oss_writeq_wakeup(q, 0);
}
int
snd_seq_oss_writeq_sync(struct seq_oss_writeq *q)
{
struct seq_oss_devinfo *dp = q->dp;
abstime_t time;
time = snd_seq_oss_timer_cur_tick(dp->timer);
if (q->sync_time >= time)
return 0;
if (! q->sync_event_put) {
struct snd_seq_event ev;
union evrec *rec;
memset(&ev, 0, sizeof(ev));
ev.flags = 0;
ev.type = SNDRV_SEQ_EVENT_ECHO;
ev.time.tick = time;
snd_seq_oss_fill_addr(dp, &ev, dp->addr.client, dp->addr.port);
rec = (union evrec *)&ev.data;
rec->t.code = SEQ_SYNCTIMER;
rec->t.time = time;
q->sync_event_put = 1;
snd_seq_kernel_client_enqueue_blocking(dp->cseq, &ev, NULL, 0, 0);
}
wait_event_interruptible_timeout(q->sync_sleep, ! q->sync_event_put, HZ);
if (signal_pending(current))
q->sync_event_put = 0;
if (! q->sync_event_put || q->sync_time >= time)
return 0;
return 1;
}
void
snd_seq_oss_writeq_wakeup(struct seq_oss_writeq *q, abstime_t time)
{
unsigned long flags;
spin_lock_irqsave(&q->sync_lock, flags);
q->sync_time = time;
q->sync_event_put = 0;
wake_up(&q->sync_sleep);
spin_unlock_irqrestore(&q->sync_lock, flags);
}
int
snd_seq_oss_writeq_get_free_size(struct seq_oss_writeq *q)
{
struct snd_seq_client_pool pool;
pool.client = q->dp->cseq;
snd_seq_oss_control(q->dp, SNDRV_SEQ_IOCTL_GET_CLIENT_POOL, &pool);
return pool.output_free;
}
void
snd_seq_oss_writeq_set_output(struct seq_oss_writeq *q, int val)
{
struct snd_seq_client_pool pool;
pool.client = q->dp->cseq;
snd_seq_oss_control(q->dp, SNDRV_SEQ_IOCTL_GET_CLIENT_POOL, &pool);
pool.output_room = val;
snd_seq_oss_control(q->dp, SNDRV_SEQ_IOCTL_SET_CLIENT_POOL, &pool);
}
