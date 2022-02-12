static int iio_loop_thread(void *data)
{
struct iio_trigger *trig = data;
set_freezable();
do {
iio_trigger_poll_chained(trig);
} while (likely(!kthread_freezable_should_stop(NULL)));
return 0;
}
static int iio_loop_trigger_set_state(struct iio_trigger *trig, bool state)
{
struct iio_loop_info *loop_trig = iio_trigger_get_drvdata(trig);
if (state) {
loop_trig->task = kthread_run(iio_loop_thread,
trig, trig->name);
if (unlikely(IS_ERR(loop_trig->task))) {
dev_err(&trig->dev,
"failed to create trigger loop thread\n");
return PTR_ERR(loop_trig->task);
}
} else {
kthread_stop(loop_trig->task);
}
return 0;
}
static struct iio_sw_trigger *iio_trig_loop_probe(const char *name)
{
struct iio_loop_info *trig_info;
int ret;
trig_info = kzalloc(sizeof(*trig_info), GFP_KERNEL);
if (!trig_info)
return ERR_PTR(-ENOMEM);
trig_info->swt.trigger = iio_trigger_alloc("%s", name);
if (!trig_info->swt.trigger) {
ret = -ENOMEM;
goto err_free_trig_info;
}
iio_trigger_set_drvdata(trig_info->swt.trigger, trig_info);
trig_info->swt.trigger->ops = &iio_loop_trigger_ops;
ret = iio_trigger_register(trig_info->swt.trigger);
if (ret)
goto err_free_trigger;
iio_swt_group_init_type_name(&trig_info->swt, name, &iio_loop_type);
return &trig_info->swt;
err_free_trigger:
iio_trigger_free(trig_info->swt.trigger);
err_free_trig_info:
kfree(trig_info);
return ERR_PTR(ret);
}
static int iio_trig_loop_remove(struct iio_sw_trigger *swt)
{
struct iio_loop_info *trig_info;
trig_info = iio_trigger_get_drvdata(swt->trigger);
iio_trigger_unregister(swt->trigger);
iio_trigger_free(swt->trigger);
kfree(trig_info);
return 0;
}
