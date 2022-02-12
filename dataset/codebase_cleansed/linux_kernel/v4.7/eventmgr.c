static int pem_init(struct pp_eventmgr *eventmgr)
{
int result = 0;
struct pem_event_data event_data = { {0} };
pem_init_feature_info(eventmgr);
pem_init_event_action_chains(eventmgr);
result = pem_handle_event(eventmgr, AMD_PP_EVENT_INITIALIZE, &event_data);
if (0 != result)
return result;
result = pem_register_interrupts(eventmgr);
return 0;
}
static void pem_fini(struct pp_eventmgr *eventmgr)
{
struct pem_event_data event_data = { {0} };
pem_uninit_featureInfo(eventmgr);
pem_unregister_interrupts(eventmgr);
pem_handle_event(eventmgr, AMD_PP_EVENT_UNINITIALIZE, &event_data);
}
int eventmgr_init(struct pp_instance *handle)
{
int result = 0;
struct pp_eventmgr *eventmgr;
if (handle == NULL)
return -EINVAL;
eventmgr = kzalloc(sizeof(struct pp_eventmgr), GFP_KERNEL);
if (eventmgr == NULL)
return -ENOMEM;
eventmgr->hwmgr = handle->hwmgr;
handle->eventmgr = eventmgr;
eventmgr->platform_descriptor = &(eventmgr->hwmgr->platform_descriptor);
eventmgr->pp_eventmgr_init = pem_init;
eventmgr->pp_eventmgr_fini = pem_fini;
return result;
}
int eventmgr_fini(struct pp_eventmgr *eventmgr)
{
kfree(eventmgr);
return 0;
}
static int pem_handle_event_unlocked(struct pp_eventmgr *eventmgr, enum amd_pp_event event, struct pem_event_data *data)
{
if (eventmgr == NULL || event >= AMD_PP_EVENT_MAX || data == NULL)
return -EINVAL;
return pem_excute_event_chain(eventmgr, eventmgr->event_chain[event], data);
}
int pem_handle_event(struct pp_eventmgr *eventmgr, enum amd_pp_event event, struct pem_event_data *event_data)
{
int r = 0;
r = pem_handle_event_unlocked(eventmgr, event, event_data);
return r;
}
bool pem_is_hw_access_blocked(struct pp_eventmgr *eventmgr)
{
return (eventmgr->block_adjust_power_state || phm_is_hw_access_blocked(eventmgr->hwmgr));
}
