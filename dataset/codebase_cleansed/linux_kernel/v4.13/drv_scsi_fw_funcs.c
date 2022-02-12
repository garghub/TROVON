bool scsi_is_slow_sgl(u16 num_sges, bool small_mid_sge)
{
return (num_sges > SCSI_NUM_SGES_SLOW_SGL_THR && small_mid_sge);
}
void init_scsi_sgl_context(struct scsi_sgl_params *ctx_sgl_params,
struct scsi_cached_sges *ctx_data_desc,
struct scsi_sgl_task_params *sgl_task_params)
{
u8 num_sges_to_init = sgl_task_params->num_sges >
SCSI_NUM_SGES_IN_CACHE ? SCSI_NUM_SGES_IN_CACHE :
sgl_task_params->num_sges;
u8 sge_index;
u32 val;
val = cpu_to_le32(sgl_task_params->sgl_phys_addr.lo);
ctx_sgl_params->sgl_addr.lo = val;
val = cpu_to_le32(sgl_task_params->sgl_phys_addr.hi);
ctx_sgl_params->sgl_addr.hi = val;
val = cpu_to_le32(sgl_task_params->total_buffer_size);
ctx_sgl_params->sgl_total_length = val;
ctx_sgl_params->sgl_num_sges = cpu_to_le16(sgl_task_params->num_sges);
for (sge_index = 0; sge_index < num_sges_to_init; sge_index++) {
val = cpu_to_le32(sgl_task_params->sgl[sge_index].sge_addr.lo);
ctx_data_desc->sge[sge_index].sge_addr.lo = val;
val = cpu_to_le32(sgl_task_params->sgl[sge_index].sge_addr.hi);
ctx_data_desc->sge[sge_index].sge_addr.hi = val;
val = cpu_to_le32(sgl_task_params->sgl[sge_index].sge_len);
ctx_data_desc->sge[sge_index].sge_len = val;
}
}
