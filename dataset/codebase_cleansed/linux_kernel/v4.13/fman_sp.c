void fman_sp_set_buf_pools_in_asc_order_of_buf_sizes(struct fman_ext_pools
*fm_ext_pools,
u8 *ordered_array,
u16 *sizes_array)
{
u16 buf_size = 0;
int i = 0, j = 0, k = 0;
for (i = 0; i < fm_ext_pools->num_of_pools_used; i++) {
buf_size = fm_ext_pools->ext_buf_pool[i].size;
sizes_array[fm_ext_pools->ext_buf_pool[i].id] = buf_size;
for (j = 0; j <= i; j++) {
if (j == i)
ordered_array[i] =
fm_ext_pools->ext_buf_pool[i].id;
else {
if (buf_size < sizes_array[ordered_array[j]]) {
for (k = i; k > j; k--)
ordered_array[k] =
ordered_array[k - 1];
ordered_array[k] =
fm_ext_pools->ext_buf_pool[i].id;
break;
}
}
}
}
}
int fman_sp_build_buffer_struct(struct fman_sp_int_context_data_copy *
int_context_data_copy,
struct fman_buffer_prefix_content *
buffer_prefix_content,
struct fman_sp_buf_margins *buf_margins,
struct fman_sp_buffer_offsets *buffer_offsets,
u8 *internal_buf_offset)
{
u32 tmp;
int_context_data_copy->ext_buf_offset = (u16)
((buffer_prefix_content->priv_data_size & (OFFSET_UNITS - 1)) ?
((buffer_prefix_content->priv_data_size + OFFSET_UNITS) &
~(u16)(OFFSET_UNITS - 1)) :
buffer_prefix_content->priv_data_size);
buffer_offsets->prs_result_offset = (u32)ILLEGAL_BASE;
buffer_offsets->time_stamp_offset = (u32)ILLEGAL_BASE;
buffer_offsets->hash_result_offset = (u32)ILLEGAL_BASE;
int_context_data_copy->size =
(u16)((buffer_prefix_content->pass_prs_result ? 32 : 0) +
((buffer_prefix_content->pass_time_stamp ||
buffer_prefix_content->pass_hash_result) ? 16 : 0));
int_context_data_copy->int_context_offset =
(u8)(buffer_prefix_content->pass_prs_result ? 32 :
((buffer_prefix_content->pass_time_stamp ||
buffer_prefix_content->pass_hash_result) ? 64 : 0));
if (buffer_prefix_content->pass_prs_result)
buffer_offsets->prs_result_offset =
int_context_data_copy->ext_buf_offset;
if (buffer_prefix_content->pass_time_stamp)
buffer_offsets->time_stamp_offset =
buffer_prefix_content->pass_prs_result ?
(int_context_data_copy->ext_buf_offset +
sizeof(struct fman_prs_result)) :
int_context_data_copy->ext_buf_offset;
if (buffer_prefix_content->pass_hash_result)
buffer_offsets->hash_result_offset =
buffer_prefix_content->pass_prs_result ?
(int_context_data_copy->ext_buf_offset +
sizeof(struct fman_prs_result) + 8) :
int_context_data_copy->ext_buf_offset + 8;
if (int_context_data_copy->size)
buf_margins->start_margins =
(u16)(int_context_data_copy->ext_buf_offset +
int_context_data_copy->size);
else
buf_margins->start_margins =
buffer_prefix_content->priv_data_size;
tmp = (u32)(buf_margins->start_margins %
buffer_prefix_content->data_align);
if (tmp)
buf_margins->start_margins +=
(buffer_prefix_content->data_align - tmp);
buffer_offsets->data_offset = buf_margins->start_margins;
return 0;
}
