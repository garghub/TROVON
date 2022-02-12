int psm_get_ui_state(struct pp_eventmgr *eventmgr, enum PP_StateUILabel ui_label, unsigned long *state_id)
{
struct pp_power_state *state;
int table_entries;
struct pp_hwmgr *hwmgr = eventmgr->hwmgr;
int i;
table_entries = hwmgr->num_ps;
state = hwmgr->ps;
for (i = 0; i < table_entries; i++) {
if (state->classification.ui_label & ui_label) {
*state_id = state->id;
return 0;
}
state = (struct pp_power_state *)((unsigned long)state + hwmgr->ps_size);
}
return -1;
}
int psm_get_state_by_classification(struct pp_eventmgr *eventmgr, enum PP_StateClassificationFlag flag, unsigned long *state_id)
{
struct pp_power_state *state;
int table_entries;
struct pp_hwmgr *hwmgr = eventmgr->hwmgr;
int i;
table_entries = hwmgr->num_ps;
state = hwmgr->ps;
for (i = 0; i < table_entries; i++) {
if (state->classification.flags & flag) {
*state_id = state->id;
return 0;
}
state = (struct pp_power_state *)((unsigned long)state + hwmgr->ps_size);
}
return -1;
}
int psm_set_states(struct pp_eventmgr *eventmgr, unsigned long *state_id)
{
struct pp_power_state *state;
int table_entries;
struct pp_hwmgr *hwmgr = eventmgr->hwmgr;
int i;
table_entries = hwmgr->num_ps;
state = hwmgr->ps;
for (i = 0; i < table_entries; i++) {
if (state->id == *state_id) {
hwmgr->request_ps = state;
return 0;
}
state = (struct pp_power_state *)((unsigned long)state + hwmgr->ps_size);
}
return -1;
}
int psm_adjust_power_state_dynamic(struct pp_eventmgr *eventmgr, bool skip)
{
struct pp_power_state *pcurrent;
struct pp_power_state *requested;
struct pp_hwmgr *hwmgr;
bool equal;
if (skip)
return 0;
hwmgr = eventmgr->hwmgr;
pcurrent = hwmgr->current_ps;
requested = hwmgr->request_ps;
if (requested == NULL)
return 0;
if (pcurrent == NULL || (0 != phm_check_states_equal(hwmgr, &pcurrent->hardware, &requested->hardware, &equal)))
equal = false;
if (!equal || phm_check_smc_update_required_for_display_configuration(hwmgr)) {
phm_apply_state_adjust_rules(hwmgr, requested, pcurrent);
phm_set_power_state(hwmgr, &pcurrent->hardware, &requested->hardware);
hwmgr->current_ps = requested;
}
return 0;
}
int psm_adjust_power_state_static(struct pp_eventmgr *eventmgr, bool skip)
{
return 0;
}
