void
ia_css_ref_config(
struct sh_css_isp_ref_isp_config *to,
const struct ia_css_ref_configuration *from,
unsigned size)
{
unsigned elems_a = ISP_VEC_NELEMS, i;
(void)size;
ia_css_dma_configure_from_info(&to->port_b, &(from->ref_frames[0]->info));
to->width_a_over_b = elems_a / to->port_b.elems;
to->dvs_frame_delay = from->dvs_frame_delay;
for (i = 0; i < MAX_NUM_VIDEO_DELAY_FRAMES; i++) {
if (from->ref_frames[i]) {
to->ref_frame_addr_y[i] = from->ref_frames[i]->data + from->ref_frames[i]->planes.yuv.y.offset;
to->ref_frame_addr_c[i] = from->ref_frames[i]->data + from->ref_frames[i]->planes.yuv.u.offset;
} else {
to->ref_frame_addr_y[i] = 0;
to->ref_frame_addr_c[i] = 0;
}
}
assert (elems_a % to->port_b.elems == 0);
}
void
ia_css_ref_configure(
const struct ia_css_binary *binary,
const struct ia_css_frame **ref_frames,
const uint32_t dvs_frame_delay)
{
struct ia_css_ref_configuration config;
unsigned i;
for (i = 0; i < MAX_NUM_VIDEO_DELAY_FRAMES; i++)
config.ref_frames[i] = ref_frames[i];
config.dvs_frame_delay = dvs_frame_delay;
ia_css_configure_ref(binary, &config);
}
void
ia_css_init_ref_state(
struct sh_css_isp_ref_dmem_state *state,
unsigned size)
{
(void)size;
assert(MAX_NUM_VIDEO_DELAY_FRAMES >= 2);
state->ref_in_buf_idx = 0;
state->ref_out_buf_idx = 1;
}
