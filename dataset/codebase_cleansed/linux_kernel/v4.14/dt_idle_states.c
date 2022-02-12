static int init_state_node(struct cpuidle_state *idle_state,
const struct of_device_id *matches,
struct device_node *state_node)
{
int err;
const struct of_device_id *match_id;
const char *desc;
match_id = of_match_node(matches, state_node);
if (!match_id)
return -ENODEV;
idle_state->enter = match_id->data;
idle_state->enter_s2idle = match_id->data;
err = of_property_read_u32(state_node, "wakeup-latency-us",
&idle_state->exit_latency);
if (err) {
u32 entry_latency, exit_latency;
err = of_property_read_u32(state_node, "entry-latency-us",
&entry_latency);
if (err) {
pr_debug(" * %pOF missing entry-latency-us property\n",
state_node);
return -EINVAL;
}
err = of_property_read_u32(state_node, "exit-latency-us",
&exit_latency);
if (err) {
pr_debug(" * %pOF missing exit-latency-us property\n",
state_node);
return -EINVAL;
}
idle_state->exit_latency = entry_latency + exit_latency;
}
err = of_property_read_u32(state_node, "min-residency-us",
&idle_state->target_residency);
if (err) {
pr_debug(" * %pOF missing min-residency-us property\n",
state_node);
return -EINVAL;
}
err = of_property_read_string(state_node, "idle-state-name", &desc);
if (err)
desc = state_node->name;
idle_state->flags = 0;
if (of_property_read_bool(state_node, "local-timer-stop"))
idle_state->flags |= CPUIDLE_FLAG_TIMER_STOP;
strncpy(idle_state->name, state_node->name, CPUIDLE_NAME_LEN - 1);
strncpy(idle_state->desc, desc, CPUIDLE_DESC_LEN - 1);
return 0;
}
static bool idle_state_valid(struct device_node *state_node, unsigned int idx,
const cpumask_t *cpumask)
{
int cpu;
struct device_node *cpu_node, *curr_state_node;
bool valid = true;
for (cpu = cpumask_next(cpumask_first(cpumask), cpumask);
cpu < nr_cpu_ids; cpu = cpumask_next(cpu, cpumask)) {
cpu_node = of_cpu_device_node_get(cpu);
curr_state_node = of_parse_phandle(cpu_node, "cpu-idle-states",
idx);
if (state_node != curr_state_node)
valid = false;
of_node_put(curr_state_node);
of_node_put(cpu_node);
if (!valid)
break;
}
return valid;
}
int dt_init_idle_driver(struct cpuidle_driver *drv,
const struct of_device_id *matches,
unsigned int start_idx)
{
struct cpuidle_state *idle_state;
struct device_node *state_node, *cpu_node;
int i, err = 0;
const cpumask_t *cpumask;
unsigned int state_idx = start_idx;
if (state_idx >= CPUIDLE_STATE_MAX)
return -EINVAL;
cpumask = drv->cpumask ? : cpu_possible_mask;
cpu_node = of_cpu_device_node_get(cpumask_first(cpumask));
for (i = 0; ; i++) {
state_node = of_parse_phandle(cpu_node, "cpu-idle-states", i);
if (!state_node)
break;
if (!of_device_is_available(state_node)) {
of_node_put(state_node);
continue;
}
if (!idle_state_valid(state_node, i, cpumask)) {
pr_warn("%pOF idle state not valid, bailing out\n",
state_node);
err = -EINVAL;
break;
}
if (state_idx == CPUIDLE_STATE_MAX) {
pr_warn("State index reached static CPU idle driver states array size\n");
break;
}
idle_state = &drv->states[state_idx++];
err = init_state_node(idle_state, matches, state_node);
if (err) {
pr_err("Parsing idle state node %pOF failed with err %d\n",
state_node, err);
err = -EINVAL;
break;
}
of_node_put(state_node);
}
of_node_put(state_node);
of_node_put(cpu_node);
if (err)
return err;
if (i)
drv->state_count = state_idx;
return i;
}
