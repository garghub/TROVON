void
ia_css_yuv444_io_config(
const struct ia_css_binary *binary,
const struct sh_css_binary_args *args)
{
const struct ia_css_frame *in_frame = args->in_frame;
const struct ia_css_frame **out_frames = (const struct ia_css_frame **)& args->out_frame;
const struct ia_css_frame_info *in_frame_info = (in_frame) ? &in_frame->info : &binary->in_frame_info;
const unsigned ddr_bits_per_element = sizeof(short) * 8;
const unsigned ddr_elems_per_word = ceil_div(HIVE_ISP_DDR_WORD_BITS, ddr_bits_per_element);
unsigned size_get = 0, size_put = 0;
unsigned offset = 0;
if (binary->info->mem_offsets.offsets.param) {
size_get = binary->info->mem_offsets.offsets.param->dmem.get.size;
offset = binary->info->mem_offsets.offsets.param->dmem.get.offset;
}
if (size_get) {
struct ia_css_common_io_config *to = (struct ia_css_common_io_config *)&binary->mem_params.params[IA_CSS_PARAM_CLASS_PARAM][IA_CSS_ISP_DMEM].address[offset];
struct dma_port_config config;
#ifndef IA_CSS_NO_DEBUG
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_yuv444_io_config() get part enter:\n");
#endif
ia_css_dma_configure_from_info(&config, in_frame_info);
to->width = in_frame_info->res.width;
to->height = in_frame_info->res.height;
to->stride = config.stride;
to->ddr_elems_per_word = ddr_elems_per_word;
#ifndef IA_CSS_NO_DEBUG
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_yuv444_io_config() get part leave:\n");
#endif
}
if (binary->info->mem_offsets.offsets.param) {
size_put = binary->info->mem_offsets.offsets.param->dmem.put.size;
offset = binary->info->mem_offsets.offsets.param->dmem.put.offset;
}
if (size_put) {
struct ia_css_common_io_config *to = (struct ia_css_common_io_config *)&binary->mem_params.params[IA_CSS_PARAM_CLASS_PARAM][IA_CSS_ISP_DMEM].address[offset];
struct dma_port_config config;
#ifndef IA_CSS_NO_DEBUG
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_yuv444_io_config() put part enter:\n");
#endif
ia_css_dma_configure_from_info(&config, &out_frames[0]->info);
to->base_address = out_frames[0]->data;
to->width = out_frames[0]->info.res.width;
to->height = out_frames[0]->info.res.height;
to->stride = config.stride;
to->ddr_elems_per_word = ddr_elems_per_word;
#ifndef IA_CSS_NO_DEBUG
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_yuv444_io_config() put part leave:\n");
#endif
}
}
