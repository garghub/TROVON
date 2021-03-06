int pem_init_event_action_chains(struct pp_eventmgr *eventmgr)
{
int i;
for (i = 0; i < AMD_PP_EVENT_MAX; i++)
eventmgr->event_chain[i] = NULL;
eventmgr->event_chain[AMD_PP_EVENT_SUSPEND] = pem_get_suspend_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_INITIALIZE] = pem_get_initialize_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_UNINITIALIZE] = pem_get_uninitialize_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_POWER_SOURCE_CHANGE] = pem_get_power_source_change_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_HIBERNATE] = pem_get_hibernate_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_RESUME] = pem_get_resume_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_THERMAL_NOTIFICATION] = pem_get_thermal_notification_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_VBIOS_NOTIFICATION] = pem_get_vbios_notification_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_ENTER_THERMAL_STATE] = pem_get_enter_thermal_state_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_EXIT_THERMAL_STATE] = pem_get_exit_thermal_state_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_ENABLE_POWER_PLAY] = pem_get_enable_powerplay_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_DISABLE_POWER_PLAY] = pem_get_disable_powerplay_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_ENABLE_OVER_DRIVE_TEST] = pem_get_enable_overdrive_test_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_DISABLE_OVER_DRIVE_TEST] = pem_get_disable_overdrive_test_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_ENABLE_GFX_CLOCK_GATING] = pem_get_enable_gfx_clock_gating_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_DISABLE_GFX_CLOCK_GATING] = pem_get_disable_gfx_clock_gating_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_ENABLE_CGPG] = pem_get_enable_cgpg_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_DISABLE_CGPG] = pem_get_disable_cgpg_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_COMPLETE_INIT] = pem_get_complete_init_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_SCREEN_ON] = pem_get_screen_on_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_SCREEN_OFF] = pem_get_screen_off_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_PRE_SUSPEND] = pem_get_pre_suspend_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_PRE_RESUME] = pem_get_pre_resume_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_ENABLE_USER_STATE] = pem_enable_user_state_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_READJUST_POWER_STATE] = pem_readjust_power_state_action_chain(eventmgr);
eventmgr->event_chain[AMD_PP_EVENT_DISPLAY_CONFIG_CHANGE] = pem_display_config_change_action_chain(eventmgr);
return 0;
}
int pem_excute_event_chain(struct pp_eventmgr *eventmgr, const struct action_chain *event_chain, struct pem_event_data *event_data)
{
const pem_event_action **paction_chain;
const pem_event_action *psub_chain;
int tmp_result = 0;
int result = 0;
if (eventmgr == NULL || event_chain == NULL || event_data == NULL)
return -EINVAL;
for (paction_chain = event_chain->action_chain; NULL != *paction_chain; paction_chain++) {
if (0 != result)
return result;
for (psub_chain = *paction_chain; NULL != *psub_chain; psub_chain++) {
tmp_result = (*psub_chain)(eventmgr, event_data);
if (0 == result)
result = tmp_result;
}
}
return result;
}
const struct action_chain *pem_get_suspend_action_chain(struct pp_eventmgr *eventmgr)
{
return &suspend_action_chain;
}
const struct action_chain *pem_get_initialize_action_chain(struct pp_eventmgr *eventmgr)
{
return &initialize_action_chain;
}
const struct action_chain *pem_get_uninitialize_action_chain(struct pp_eventmgr *eventmgr)
{
return &uninitialize_action_chain;
}
const struct action_chain *pem_get_power_source_change_action_chain(struct pp_eventmgr *eventmgr)
{
return &power_source_change_action_chain_pp_enabled;
}
const struct action_chain *pem_get_resume_action_chain(struct pp_eventmgr *eventmgr)
{
return &resume_action_chain;
}
const struct action_chain *pem_get_hibernate_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_thermal_notification_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_vbios_notification_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_enter_thermal_state_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_exit_thermal_state_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_enable_powerplay_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_disable_powerplay_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_enable_overdrive_test_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_disable_overdrive_test_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_enable_gfx_clock_gating_action_chain(struct pp_eventmgr *eventmgr)
{
return &enable_gfx_clock_gating_action_chain;
}
const struct action_chain *pem_get_disable_gfx_clock_gating_action_chain(struct pp_eventmgr *eventmgr)
{
return &disable_gfx_clock_gating_action_chain;
}
const struct action_chain *pem_get_enable_cgpg_action_chain(struct pp_eventmgr *eventmgr)
{
return &enable_cgpg_action_chain;
}
const struct action_chain *pem_get_disable_cgpg_action_chain(struct pp_eventmgr *eventmgr)
{
return &disable_cgpg_action_chain;
}
const struct action_chain *pem_get_complete_init_action_chain(struct pp_eventmgr *eventmgr)
{
return &complete_init_action_chain;
}
const struct action_chain *pem_get_screen_on_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_screen_off_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_pre_suspend_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_get_pre_resume_action_chain(struct pp_eventmgr *eventmgr)
{
return NULL;
}
const struct action_chain *pem_enable_user_state_action_chain(struct pp_eventmgr *eventmgr)
{
return &enable_user_state_action_chain;
}
const struct action_chain *pem_readjust_power_state_action_chain(struct pp_eventmgr *eventmgr)
{
return &readjust_power_state_action_chain;
}
const struct action_chain *pem_display_config_change_action_chain(struct pp_eventmgr *eventmgr)
{
return &display_config_change_action_chain;
}
