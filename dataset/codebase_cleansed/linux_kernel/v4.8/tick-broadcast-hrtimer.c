static int bc_shutdown(struct clock_event_device *evt)
{
hrtimer_try_to_cancel(&bctimer);
return 0;
}
static int bc_set_next(ktime_t expires, struct clock_event_device *bc)
{
int bc_moved;
RCU_NONIDLE({
bc_moved = hrtimer_try_to_cancel(&bctimer) >= 0;
if (bc_moved)
hrtimer_start(&bctimer, expires,
HRTIMER_MODE_ABS_PINNED);});
if (bc_moved) {
bc->bound_on = smp_processor_id();
} else if (bc->bound_on == smp_processor_id()) {
hrtimer_set_expires(&bctimer, expires);
}
return 0;
}
static enum hrtimer_restart bc_handler(struct hrtimer *t)
{
ce_broadcast_hrtimer.event_handler(&ce_broadcast_hrtimer);
if (clockevent_state_oneshot(&ce_broadcast_hrtimer))
if (ce_broadcast_hrtimer.next_event.tv64 != KTIME_MAX)
return HRTIMER_RESTART;
return HRTIMER_NORESTART;
}
void tick_setup_hrtimer_broadcast(void)
{
hrtimer_init(&bctimer, CLOCK_MONOTONIC, HRTIMER_MODE_ABS);
bctimer.function = bc_handler;
clockevents_register_device(&ce_broadcast_hrtimer);
}
