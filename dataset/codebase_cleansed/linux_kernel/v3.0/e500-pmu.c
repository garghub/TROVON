static u64 e500_xlate_event(u64 event_id)
{
u32 event_low = (u32)event_id;
u64 ret;
if (event_low >= num_events)
return 0;
ret = FSL_EMB_EVENT_VALID;
if (event_low >= 76 && event_low <= 81) {
ret |= FSL_EMB_EVENT_RESTRICTED;
ret |= event_id &
(FSL_EMB_EVENT_THRESHMUL | FSL_EMB_EVENT_THRESH);
} else if (event_id &
(FSL_EMB_EVENT_THRESHMUL | FSL_EMB_EVENT_THRESH)) {
return 0;
}
return ret;
}
static int init_e500_pmu(void)
{
if (!cur_cpu_spec->oprofile_cpu_type)
return -ENODEV;
if (!strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc/e500mc"))
num_events = 256;
else if (strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc/e500"))
return -ENODEV;
return register_fsl_emb_pmu(&e500_pmu);
}
