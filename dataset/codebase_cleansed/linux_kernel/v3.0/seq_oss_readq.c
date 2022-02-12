struct seq_oss_readq *
snd_seq_oss_readq_new(struct seq_oss_devinfo *dp, int maxlen)
{
struct seq_oss_readq *q;
if ((q = kzalloc(sizeof(*q), GFP_KERNEL)) == NULL) {
snd_printk(KERN_ERR "can't malloc read queue\n");
return NULL;
}
if ((q->q = kcalloc(maxlen, sizeof(union evrec), GFP_KERNEL)) == NULL) {
snd_printk(KERN_ERR "can't malloc read queue buffer\n");
kfree(q);
return NULL;
}
q->maxlen = maxlen;
q->qlen = 0;
q->head = q->tail = 0;
init_waitqueue_head(&q->midi_sleep);
spin_lock_init(&q->lock);
q->pre_event_timeout = SNDRV_SEQ_OSS_MAX_TIMEOUT;
q->input_time = (unsigned long)-1;
return q;
}
void
snd_seq_oss_readq_delete(struct seq_oss_readq *q)
{
if (q) {
kfree(q->q);
kfree(q);
}
}
void
snd_seq_oss_readq_clear(struct seq_oss_readq *q)
{
if (q->qlen) {
q->qlen = 0;
q->head = q->tail = 0;
}
if (waitqueue_active(&q->midi_sleep))
wake_up(&q->midi_sleep);
q->input_time = (unsigned long)-1;
}
int
snd_seq_oss_readq_puts(struct seq_oss_readq *q, int dev, unsigned char *data, int len)
{
union evrec rec;
int result;
memset(&rec, 0, sizeof(rec));
rec.c[0] = SEQ_MIDIPUTC;
rec.c[2] = dev;
while (len-- > 0) {
rec.c[1] = *data++;
result = snd_seq_oss_readq_put_event(q, &rec);
if (result < 0)
return result;
}
return 0;
}
int
snd_seq_oss_readq_put_event(struct seq_oss_readq *q, union evrec *ev)
{
unsigned long flags;
spin_lock_irqsave(&q->lock, flags);
if (q->qlen >= q->maxlen - 1) {
spin_unlock_irqrestore(&q->lock, flags);
return -ENOMEM;
}
memcpy(&q->q[q->tail], ev, sizeof(*ev));
q->tail = (q->tail + 1) % q->maxlen;
q->qlen++;
if (waitqueue_active(&q->midi_sleep))
wake_up(&q->midi_sleep);
spin_unlock_irqrestore(&q->lock, flags);
return 0;
}
int
snd_seq_oss_readq_pick(struct seq_oss_readq *q, union evrec *rec)
{
if (q->qlen == 0)
return -EAGAIN;
memcpy(rec, &q->q[q->head], sizeof(*rec));
return 0;
}
void
snd_seq_oss_readq_wait(struct seq_oss_readq *q)
{
wait_event_interruptible_timeout(q->midi_sleep,
(q->qlen > 0 || q->head == q->tail),
q->pre_event_timeout);
}
void
snd_seq_oss_readq_free(struct seq_oss_readq *q)
{
if (q->qlen > 0) {
q->head = (q->head + 1) % q->maxlen;
q->qlen--;
}
}
unsigned int
snd_seq_oss_readq_poll(struct seq_oss_readq *q, struct file *file, poll_table *wait)
{
poll_wait(file, &q->midi_sleep, wait);
return q->qlen;
}
int
snd_seq_oss_readq_put_timestamp(struct seq_oss_readq *q, unsigned long curt, int seq_mode)
{
if (curt != q->input_time) {
union evrec rec;
memset(&rec, 0, sizeof(rec));
switch (seq_mode) {
case SNDRV_SEQ_OSS_MODE_SYNTH:
rec.echo = (curt << 8) | SEQ_WAIT;
snd_seq_oss_readq_put_event(q, &rec);
break;
case SNDRV_SEQ_OSS_MODE_MUSIC:
rec.t.code = EV_TIMING;
rec.t.cmd = TMR_WAIT_ABS;
rec.t.time = curt;
snd_seq_oss_readq_put_event(q, &rec);
break;
}
q->input_time = curt;
}
return 0;
}
void
snd_seq_oss_readq_info_read(struct seq_oss_readq *q, struct snd_info_buffer *buf)
{
snd_iprintf(buf, " read queue [%s] length = %d : tick = %ld\n",
(waitqueue_active(&q->midi_sleep) ? "sleeping":"running"),
q->qlen, q->input_time);
}
