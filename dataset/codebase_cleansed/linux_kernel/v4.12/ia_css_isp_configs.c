void
ia_css_configure_iterator(
const struct ia_css_binary *binary,
const struct ia_css_iterator_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_iterator() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.iterator.size;
offset = binary->info->mem_offsets.offsets.config->dmem.iterator.offset;
}
if (size) {
ia_css_iterator_config((struct sh_css_isp_iterator_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_iterator() leave:\n");
}
void
ia_css_configure_copy_output(
const struct ia_css_binary *binary,
const struct ia_css_copy_output_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_copy_output() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.copy_output.size;
offset = binary->info->mem_offsets.offsets.config->dmem.copy_output.offset;
}
if (size) {
ia_css_copy_output_config((struct sh_css_isp_copy_output_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_copy_output() leave:\n");
}
void
ia_css_configure_crop(
const struct ia_css_binary *binary,
const struct ia_css_crop_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_crop() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.crop.size;
offset = binary->info->mem_offsets.offsets.config->dmem.crop.offset;
}
if (size) {
ia_css_crop_config((struct sh_css_isp_crop_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_crop() leave:\n");
}
void
ia_css_configure_fpn(
const struct ia_css_binary *binary,
const struct ia_css_fpn_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_fpn() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.fpn.size;
offset = binary->info->mem_offsets.offsets.config->dmem.fpn.offset;
}
if (size) {
ia_css_fpn_config((struct sh_css_isp_fpn_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_fpn() leave:\n");
}
void
ia_css_configure_dvs(
const struct ia_css_binary *binary,
const struct ia_css_dvs_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_dvs() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.dvs.size;
offset = binary->info->mem_offsets.offsets.config->dmem.dvs.offset;
}
if (size) {
ia_css_dvs_config((struct sh_css_isp_dvs_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_dvs() leave:\n");
}
void
ia_css_configure_qplane(
const struct ia_css_binary *binary,
const struct ia_css_qplane_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_qplane() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.qplane.size;
offset = binary->info->mem_offsets.offsets.config->dmem.qplane.offset;
}
if (size) {
ia_css_qplane_config((struct sh_css_isp_qplane_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_qplane() leave:\n");
}
void
ia_css_configure_output0(
const struct ia_css_binary *binary,
const struct ia_css_output0_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_output0() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.output0.size;
offset = binary->info->mem_offsets.offsets.config->dmem.output0.offset;
}
if (size) {
ia_css_output0_config((struct sh_css_isp_output_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_output0() leave:\n");
}
void
ia_css_configure_output1(
const struct ia_css_binary *binary,
const struct ia_css_output1_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_output1() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.output1.size;
offset = binary->info->mem_offsets.offsets.config->dmem.output1.offset;
}
if (size) {
ia_css_output1_config((struct sh_css_isp_output_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_output1() leave:\n");
}
void
ia_css_configure_output(
const struct ia_css_binary *binary,
const struct ia_css_output_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_output() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.output.size;
offset = binary->info->mem_offsets.offsets.config->dmem.output.offset;
}
if (size) {
ia_css_output_config((struct sh_css_isp_output_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_output() leave:\n");
}
void
ia_css_configure_sc(
const struct ia_css_binary *binary,
const struct ia_css_sc_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_sc() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.sc.size;
offset = binary->info->mem_offsets.offsets.config->dmem.sc.offset;
}
if (size) {
ia_css_sc_config((struct sh_css_isp_sc_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_sc() leave:\n");
}
void
ia_css_configure_raw(
const struct ia_css_binary *binary,
const struct ia_css_raw_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_raw() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.raw.size;
offset = binary->info->mem_offsets.offsets.config->dmem.raw.offset;
}
if (size) {
ia_css_raw_config((struct sh_css_isp_raw_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_raw() leave:\n");
}
void
ia_css_configure_tnr(
const struct ia_css_binary *binary,
const struct ia_css_tnr_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_tnr() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.tnr.size;
offset = binary->info->mem_offsets.offsets.config->dmem.tnr.offset;
}
if (size) {
ia_css_tnr_config((struct sh_css_isp_tnr_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_tnr() leave:\n");
}
void
ia_css_configure_ref(
const struct ia_css_binary *binary,
const struct ia_css_ref_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_ref() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.ref.size;
offset = binary->info->mem_offsets.offsets.config->dmem.ref.offset;
}
if (size) {
ia_css_ref_config((struct sh_css_isp_ref_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_ref() leave:\n");
}
void
ia_css_configure_vf(
const struct ia_css_binary *binary,
const struct ia_css_vf_configuration *config_dmem)
{
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_vf() enter:\n");
{
unsigned offset = 0;
unsigned size = 0;
if (binary->info->mem_offsets.offsets.config) {
size = binary->info->mem_offsets.offsets.config->dmem.vf.size;
offset = binary->info->mem_offsets.offsets.config->dmem.vf.offset;
}
if (size) {
ia_css_vf_config((struct sh_css_isp_vf_isp_config *)
&binary->mem_params.params[IA_CSS_PARAM_CLASS_CONFIG][IA_CSS_ISP_DMEM].address[offset],
config_dmem, size); }
}
ia_css_debug_dtrace(IA_CSS_DEBUG_TRACE_PRIVATE, "ia_css_configure_vf() leave:\n");
}
