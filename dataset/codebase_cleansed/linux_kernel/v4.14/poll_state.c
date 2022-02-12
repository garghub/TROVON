static int __cpuidle poll_idle(struct cpuidle_device *dev,
struct cpuidle_driver *drv, int index)
{
local_irq_enable();
if (!current_set_polling_and_test()) {
while (!need_resched())
cpu_relax();
}
current_clr_polling();
return index;
}
void cpuidle_poll_state_init(struct cpuidle_driver *drv)
{
struct cpuidle_state *state = &drv->states[0];
snprintf(state->name, CPUIDLE_NAME_LEN, "POLL");
snprintf(state->desc, CPUIDLE_DESC_LEN, "CPUIDLE CORE POLL IDLE");
state->exit_latency = 0;
state->target_residency = 0;
state->power_usage = -1;
state->enter = poll_idle;
state->disabled = false;
state->flags = CPUIDLE_FLAG_POLLING;
}
