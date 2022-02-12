void sptlrpc_gc_add_sec(struct ptlrpc_sec *sec)
{
LASSERT(sec->ps_policy->sp_cops->gc_ctx);
LASSERT(sec->ps_gc_interval > 0);
LASSERT(list_empty(&sec->ps_gc_list));
sec->ps_gc_next = ktime_get_real_seconds() + sec->ps_gc_interval;
spin_lock(&sec_gc_list_lock);
list_add_tail(&sec_gc_list, &sec->ps_gc_list);
spin_unlock(&sec_gc_list_lock);
CDEBUG(D_SEC, "added sec %p(%s)\n", sec, sec->ps_policy->sp_name);
}
void sptlrpc_gc_del_sec(struct ptlrpc_sec *sec)
{
if (list_empty(&sec->ps_gc_list))
return;
might_sleep();
atomic_inc(&sec_gc_wait_del);
spin_lock(&sec_gc_list_lock);
list_del_init(&sec->ps_gc_list);
spin_unlock(&sec_gc_list_lock);
mutex_lock(&sec_gc_mutex);
mutex_unlock(&sec_gc_mutex);
atomic_dec(&sec_gc_wait_del);
CDEBUG(D_SEC, "del sec %p(%s)\n", sec, sec->ps_policy->sp_name);
}
static void sec_process_ctx_list(void)
{
struct ptlrpc_cli_ctx *ctx;
spin_lock(&sec_gc_ctx_list_lock);
while (!list_empty(&sec_gc_ctx_list)) {
ctx = list_entry(sec_gc_ctx_list.next,
struct ptlrpc_cli_ctx, cc_gc_chain);
list_del_init(&ctx->cc_gc_chain);
spin_unlock(&sec_gc_ctx_list_lock);
LASSERT(ctx->cc_sec);
LASSERT(atomic_read(&ctx->cc_refcount) == 1);
CDEBUG(D_SEC, "gc pick up ctx %p(%u->%s)\n",
ctx, ctx->cc_vcred.vc_uid, sec2target_str(ctx->cc_sec));
sptlrpc_cli_ctx_put(ctx, 1);
spin_lock(&sec_gc_ctx_list_lock);
}
spin_unlock(&sec_gc_ctx_list_lock);
}
static void sec_do_gc(struct ptlrpc_sec *sec)
{
LASSERT(sec->ps_policy->sp_cops->gc_ctx);
if (unlikely(sec->ps_gc_next == 0)) {
CDEBUG(D_SEC, "sec %p(%s) has 0 gc time\n",
sec, sec->ps_policy->sp_name);
return;
}
CDEBUG(D_SEC, "check on sec %p(%s)\n", sec, sec->ps_policy->sp_name);
if (sec->ps_gc_next > ktime_get_real_seconds())
return;
sec->ps_policy->sp_cops->gc_ctx(sec);
sec->ps_gc_next = ktime_get_real_seconds() + sec->ps_gc_interval;
}
static int sec_gc_main(void *arg)
{
struct ptlrpc_thread *thread = arg;
struct l_wait_info lwi;
unshare_fs_struct();
thread_set_flags(thread, SVC_RUNNING);
wake_up(&thread->t_ctl_waitq);
while (1) {
struct ptlrpc_sec *sec;
thread_clear_flags(thread, SVC_SIGNAL);
sec_process_ctx_list();
again:
mutex_lock(&sec_gc_mutex);
list_for_each_entry(sec, &sec_gc_list, ps_gc_list) {
if (atomic_read(&sec_gc_wait_del)) {
CDEBUG(D_SEC, "deletion pending, start over\n");
mutex_unlock(&sec_gc_mutex);
goto again;
}
sec_do_gc(sec);
}
mutex_unlock(&sec_gc_mutex);
sec_process_ctx_list();
lwi = LWI_TIMEOUT(SEC_GC_INTERVAL * HZ, NULL, NULL);
l_wait_event(thread->t_ctl_waitq,
thread_is_stopping(thread) ||
thread_is_signal(thread),
&lwi);
if (thread_test_and_clear_flags(thread, SVC_STOPPING))
break;
}
thread_set_flags(thread, SVC_STOPPED);
wake_up(&thread->t_ctl_waitq);
return 0;
}
int sptlrpc_gc_init(void)
{
struct l_wait_info lwi = { 0 };
struct task_struct *task;
mutex_init(&sec_gc_mutex);
spin_lock_init(&sec_gc_list_lock);
spin_lock_init(&sec_gc_ctx_list_lock);
memset(&sec_gc_thread, 0, sizeof(sec_gc_thread));
init_waitqueue_head(&sec_gc_thread.t_ctl_waitq);
task = kthread_run(sec_gc_main, &sec_gc_thread, "sptlrpc_gc");
if (IS_ERR(task)) {
CERROR("can't start gc thread: %ld\n", PTR_ERR(task));
return PTR_ERR(task);
}
l_wait_event(sec_gc_thread.t_ctl_waitq,
thread_is_running(&sec_gc_thread), &lwi);
return 0;
}
void sptlrpc_gc_fini(void)
{
struct l_wait_info lwi = { 0 };
thread_set_flags(&sec_gc_thread, SVC_STOPPING);
wake_up(&sec_gc_thread.t_ctl_waitq);
l_wait_event(sec_gc_thread.t_ctl_waitq,
thread_is_stopped(&sec_gc_thread), &lwi);
}
