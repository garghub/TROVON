int crw_register_handler(int rsc, crw_handler_t handler)
{
int rc = 0;
if ((rsc < 0) || (rsc >= NR_RSCS))
return -EINVAL;
mutex_lock(&crw_handler_mutex);
if (crw_handlers[rsc])
rc = -EBUSY;
else
crw_handlers[rsc] = handler;
mutex_unlock(&crw_handler_mutex);
return rc;
}
void crw_unregister_handler(int rsc)
{
if ((rsc < 0) || (rsc >= NR_RSCS))
return;
mutex_lock(&crw_handler_mutex);
crw_handlers[rsc] = NULL;
mutex_unlock(&crw_handler_mutex);
}
static int crw_collect_info(void *unused)
{
struct crw crw[2];
int ccode, signal;
unsigned int chain;
repeat:
signal = wait_event_interruptible(crw_handler_wait_q,
atomic_read(&crw_nr_req) > 0);
if (unlikely(signal))
atomic_inc(&crw_nr_req);
chain = 0;
while (1) {
crw_handler_t handler;
if (unlikely(chain > 1)) {
struct crw tmp_crw;
printk(KERN_WARNING"%s: Code does not support more "
"than two chained crws; please report to "
"linux390@de.ibm.com!\n", __func__);
ccode = stcrw(&tmp_crw);
printk(KERN_WARNING"%s: crw reports slct=%d, oflw=%d, "
"chn=%d, rsc=%X, anc=%d, erc=%X, rsid=%X\n",
__func__, tmp_crw.slct, tmp_crw.oflw,
tmp_crw.chn, tmp_crw.rsc, tmp_crw.anc,
tmp_crw.erc, tmp_crw.rsid);
printk(KERN_WARNING"%s: This was crw number %x in the "
"chain\n", __func__, chain);
if (ccode != 0)
break;
chain = tmp_crw.chn ? chain + 1 : 0;
continue;
}
ccode = stcrw(&crw[chain]);
if (ccode != 0)
break;
printk(KERN_DEBUG "crw_info : CRW reports slct=%d, oflw=%d, "
"chn=%d, rsc=%X, anc=%d, erc=%X, rsid=%X\n",
crw[chain].slct, crw[chain].oflw, crw[chain].chn,
crw[chain].rsc, crw[chain].anc, crw[chain].erc,
crw[chain].rsid);
if (crw[chain].oflw) {
int i;
pr_debug("%s: crw overflow detected!\n", __func__);
mutex_lock(&crw_handler_mutex);
for (i = 0; i < NR_RSCS; i++) {
if (crw_handlers[i])
crw_handlers[i](NULL, NULL, 1);
}
mutex_unlock(&crw_handler_mutex);
chain = 0;
continue;
}
if (crw[0].chn && !chain) {
chain++;
continue;
}
mutex_lock(&crw_handler_mutex);
handler = crw_handlers[crw[chain].rsc];
if (handler)
handler(&crw[0], chain ? &crw[1] : NULL, 0);
mutex_unlock(&crw_handler_mutex);
chain = crw[chain].chn ? chain + 1 : 0;
}
if (atomic_dec_and_test(&crw_nr_req))
wake_up(&crw_handler_wait_q);
goto repeat;
return 0;
}
void crw_handle_channel_report(void)
{
atomic_inc(&crw_nr_req);
wake_up(&crw_handler_wait_q);
}
void crw_wait_for_channel_report(void)
{
crw_handle_channel_report();
wait_event(crw_handler_wait_q, atomic_read(&crw_nr_req) == 0);
}
static int __init crw_machine_check_init(void)
{
struct task_struct *task;
task = kthread_run(crw_collect_info, NULL, "kmcheck");
if (IS_ERR(task))
return PTR_ERR(task);
ctl_set_bit(14, 28);
return 0;
}
