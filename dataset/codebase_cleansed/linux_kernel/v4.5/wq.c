bool edac_queue_work(struct delayed_work *work, unsigned long delay)
{
return queue_delayed_work(wq, work, delay);
}
bool edac_mod_work(struct delayed_work *work, unsigned long delay)
{
return mod_delayed_work(wq, work, delay);
}
bool edac_stop_work(struct delayed_work *work)
{
bool ret;
ret = cancel_delayed_work_sync(work);
flush_workqueue(wq);
return ret;
}
int edac_workqueue_setup(void)
{
wq = create_singlethread_workqueue("edac-poller");
if (!wq)
return -ENODEV;
else
return 0;
}
void edac_workqueue_teardown(void)
{
flush_workqueue(wq);
destroy_workqueue(wq);
wq = NULL;
}
