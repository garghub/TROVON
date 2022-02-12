static
void i2400ms_tx_submit(struct work_struct *ws)
{
int result;
struct i2400ms *i2400ms = container_of(ws, struct i2400ms, tx_worker);
struct i2400m *i2400m = &i2400ms->i2400m;
struct sdio_func *func = i2400ms->func;
struct device *dev = &func->dev;
struct i2400m_msg_hdr *tx_msg;
size_t tx_msg_size;
d_fnstart(4, dev, "(i2400ms %p, i2400m %p)\n", i2400ms, i2400ms);
while (NULL != (tx_msg = i2400m_tx_msg_get(i2400m, &tx_msg_size))) {
d_printf(2, dev, "TX: submitting %zu bytes\n", tx_msg_size);
d_dump(5, dev, tx_msg, tx_msg_size);
sdio_claim_host(func);
result = sdio_memcpy_toio(func, 0, tx_msg, tx_msg_size);
sdio_release_host(func);
i2400m_tx_msg_sent(i2400m);
if (result < 0) {
dev_err(dev, "TX: cannot submit TX; tx_msg @%zu %zu B:"
" %d\n", (void *) tx_msg - i2400m->tx_buf,
tx_msg_size, result);
}
if (result == -ETIMEDOUT) {
i2400m_error_recovery(i2400m);
break;
}
d_printf(2, dev, "TX: %zub submitted\n", tx_msg_size);
}
d_fnend(4, dev, "(i2400ms %p) = void\n", i2400ms);
}
void i2400ms_bus_tx_kick(struct i2400m *i2400m)
{
struct i2400ms *i2400ms = container_of(i2400m, struct i2400ms, i2400m);
struct device *dev = &i2400ms->func->dev;
unsigned long flags;
d_fnstart(3, dev, "(i2400m %p) = void\n", i2400m);
spin_lock_irqsave(&i2400m->tx_lock, flags);
if (i2400ms->tx_workqueue != NULL)
queue_work(i2400ms->tx_workqueue, &i2400ms->tx_worker);
spin_unlock_irqrestore(&i2400m->tx_lock, flags);
d_fnend(3, dev, "(i2400m %p) = void\n", i2400m);
}
int i2400ms_tx_setup(struct i2400ms *i2400ms)
{
int result;
struct device *dev = &i2400ms->func->dev;
struct i2400m *i2400m = &i2400ms->i2400m;
struct workqueue_struct *tx_workqueue;
unsigned long flags;
d_fnstart(5, dev, "(i2400ms %p)\n", i2400ms);
INIT_WORK(&i2400ms->tx_worker, i2400ms_tx_submit);
snprintf(i2400ms->tx_wq_name, sizeof(i2400ms->tx_wq_name),
"%s-tx", i2400m->wimax_dev.name);
tx_workqueue =
create_singlethread_workqueue(i2400ms->tx_wq_name);
if (tx_workqueue == NULL) {
dev_err(dev, "TX: failed to create workqueue\n");
result = -ENOMEM;
} else
result = 0;
spin_lock_irqsave(&i2400m->tx_lock, flags);
i2400ms->tx_workqueue = tx_workqueue;
spin_unlock_irqrestore(&i2400m->tx_lock, flags);
d_fnend(5, dev, "(i2400ms %p) = %d\n", i2400ms, result);
return result;
}
void i2400ms_tx_release(struct i2400ms *i2400ms)
{
struct i2400m *i2400m = &i2400ms->i2400m;
struct workqueue_struct *tx_workqueue;
unsigned long flags;
tx_workqueue = i2400ms->tx_workqueue;
spin_lock_irqsave(&i2400m->tx_lock, flags);
i2400ms->tx_workqueue = NULL;
spin_unlock_irqrestore(&i2400m->tx_lock, flags);
if (tx_workqueue)
destroy_workqueue(tx_workqueue);
}
