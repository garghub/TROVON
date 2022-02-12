static u64 e6500_xlate_event(u64 event_id)
{
u32 event_low = (u32)event_id;
if (event_low >= num_events ||
(event_id & (FSL_EMB_EVENT_THRESHMUL | FSL_EMB_EVENT_THRESH)))
return 0;
return FSL_EMB_EVENT_VALID;
}
static int init_e6500_pmu(void)
{
if (!cur_cpu_spec->oprofile_cpu_type ||
strcmp(cur_cpu_spec->oprofile_cpu_type, "ppc/e6500"))
return -ENODEV;
return register_fsl_emb_pmu(&e6500_pmu);
}
