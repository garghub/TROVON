int dgnc_ms_sleep(ulong ms)
{
__set_current_state(TASK_INTERRUPTIBLE);
schedule_timeout((ms * HZ) / 1000);
return signal_pending(current);
}
