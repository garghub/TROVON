int
LNetEQAlloc(unsigned int count, lnet_eq_handler_t callback,
lnet_handle_eq_t *handle)
{
lnet_eq_t *eq;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
count = roundup_pow_of_two(count);
if (callback != LNET_EQ_HANDLER_NONE && count != 0)
CWARN("EQ callback is guaranteed to get every event, do you still want to set eqcount %d for polling event which will have locking overhead? Please contact with developer to confirm\n", count);
if (count == 0 && callback == LNET_EQ_HANDLER_NONE)
return -EINVAL;
eq = lnet_eq_alloc();
if (eq == NULL)
return -ENOMEM;
if (count != 0) {
LIBCFS_ALLOC(eq->eq_events, count * sizeof(lnet_event_t));
if (eq->eq_events == NULL)
goto failed;
}
eq->eq_deq_seq = 1;
eq->eq_enq_seq = 1;
eq->eq_size = count;
eq->eq_callback = callback;
eq->eq_refs = cfs_percpt_alloc(lnet_cpt_table(),
sizeof(*eq->eq_refs[0]));
if (eq->eq_refs == NULL)
goto failed;
lnet_res_lock(LNET_LOCK_EX);
lnet_eq_wait_lock();
lnet_res_lh_initialize(&the_lnet.ln_eq_container, &eq->eq_lh);
list_add(&eq->eq_list, &the_lnet.ln_eq_container.rec_active);
lnet_eq_wait_unlock();
lnet_res_unlock(LNET_LOCK_EX);
lnet_eq2handle(handle, eq);
return 0;
failed:
if (eq->eq_events != NULL)
LIBCFS_FREE(eq->eq_events, count * sizeof(lnet_event_t));
if (eq->eq_refs != NULL)
cfs_percpt_free(eq->eq_refs);
lnet_eq_free(eq);
return -ENOMEM;
}
int
LNetEQFree(lnet_handle_eq_t eqh)
{
struct lnet_eq *eq;
lnet_event_t *events = NULL;
int **refs = NULL;
int *ref;
int rc = 0;
int size = 0;
int i;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
lnet_res_lock(LNET_LOCK_EX);
lnet_eq_wait_lock();
eq = lnet_handle2eq(&eqh);
if (eq == NULL) {
rc = -ENOENT;
goto out;
}
cfs_percpt_for_each(ref, i, eq->eq_refs) {
LASSERT(*ref >= 0);
if (*ref == 0)
continue;
CDEBUG(D_NET, "Event equeue (%d: %d) busy on destroy.\n",
i, *ref);
rc = -EBUSY;
goto out;
}
events = eq->eq_events;
size = eq->eq_size;
refs = eq->eq_refs;
lnet_res_lh_invalidate(&eq->eq_lh);
list_del(&eq->eq_list);
lnet_eq_free(eq);
out:
lnet_eq_wait_unlock();
lnet_res_unlock(LNET_LOCK_EX);
if (events != NULL)
LIBCFS_FREE(events, size * sizeof(lnet_event_t));
if (refs != NULL)
cfs_percpt_free(refs);
return rc;
}
void
lnet_eq_enqueue_event(lnet_eq_t *eq, lnet_event_t *ev)
{
int index;
if (eq->eq_size == 0) {
LASSERT(eq->eq_callback != LNET_EQ_HANDLER_NONE);
eq->eq_callback(ev);
return;
}
lnet_eq_wait_lock();
ev->sequence = eq->eq_enq_seq++;
LASSERT(eq->eq_size == LOWEST_BIT_SET(eq->eq_size));
index = ev->sequence & (eq->eq_size - 1);
eq->eq_events[index] = *ev;
if (eq->eq_callback != LNET_EQ_HANDLER_NONE)
eq->eq_callback(ev);
if (waitqueue_active(&the_lnet.ln_eq_waitq))
wake_up_all(&the_lnet.ln_eq_waitq);
lnet_eq_wait_unlock();
}
static int
lnet_eq_dequeue_event(lnet_eq_t *eq, lnet_event_t *ev)
{
int new_index = eq->eq_deq_seq & (eq->eq_size - 1);
lnet_event_t *new_event = &eq->eq_events[new_index];
int rc;
if (LNET_SEQ_GT(eq->eq_deq_seq, new_event->sequence))
return 0;
*ev = *new_event;
CDEBUG(D_INFO, "event: %p, sequence: %lu, eq->size: %u\n",
new_event, eq->eq_deq_seq, eq->eq_size);
if (eq->eq_deq_seq == new_event->sequence) {
rc = 1;
} else {
CDEBUG(D_NET, "Event Queue Overflow: eq seq %lu ev seq %lu\n",
eq->eq_deq_seq, new_event->sequence);
rc = -EOVERFLOW;
}
eq->eq_deq_seq = new_event->sequence + 1;
return rc;
}
static int
lnet_eq_wait_locked(int *timeout_ms)
__must_hold(&the_lnet.ln_eq_wait_lock
int
LNetEQPoll(lnet_handle_eq_t *eventqs, int neq, int timeout_ms,
lnet_event_t *event, int *which)
{
int wait = 1;
int rc;
int i;
LASSERT(the_lnet.ln_init);
LASSERT(the_lnet.ln_refcount > 0);
if (neq < 1)
return -ENOENT;
lnet_eq_wait_lock();
for (;;) {
for (i = 0; i < neq; i++) {
lnet_eq_t *eq = lnet_handle2eq(&eventqs[i]);
if (eq == NULL) {
lnet_eq_wait_unlock();
return -ENOENT;
}
rc = lnet_eq_dequeue_event(eq, event);
if (rc != 0) {
lnet_eq_wait_unlock();
*which = i;
return rc;
}
}
if (wait == 0)
break;
wait = lnet_eq_wait_locked(&timeout_ms);
if (wait < 0)
break;
}
lnet_eq_wait_unlock();
return 0;
}
