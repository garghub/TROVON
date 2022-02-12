static int32_t mtk_mdp_map_color_format(int v4l2_format)
{
switch (v4l2_format) {
case V4L2_PIX_FMT_NV12M:
case V4L2_PIX_FMT_NV12:
return MDP_COLOR_NV12;
case V4L2_PIX_FMT_MT21C:
return MDP_COLOR_420_MT21;
case V4L2_PIX_FMT_YUV420M:
case V4L2_PIX_FMT_YUV420:
return MDP_COLOR_I420;
case V4L2_PIX_FMT_YVU420:
return MDP_COLOR_YV12;
}
mtk_mdp_err("Unknown format 0x%x", v4l2_format);
return MDP_COLOR_UNKNOWN;
}
void mtk_mdp_hw_set_input_addr(struct mtk_mdp_ctx *ctx,
struct mtk_mdp_addr *addr)
{
struct mdp_buffer *src_buf = &ctx->vpu.vsi->src_buffer;
int i;
for (i = 0; i < ARRAY_SIZE(addr->addr); i++)
src_buf->addr_mva[i] = (uint64_t)addr->addr[i];
}
void mtk_mdp_hw_set_output_addr(struct mtk_mdp_ctx *ctx,
struct mtk_mdp_addr *addr)
{
struct mdp_buffer *dst_buf = &ctx->vpu.vsi->dst_buffer;
int i;
for (i = 0; i < ARRAY_SIZE(addr->addr); i++)
dst_buf->addr_mva[i] = (uint64_t)addr->addr[i];
}
void mtk_mdp_hw_set_in_size(struct mtk_mdp_ctx *ctx)
{
struct mtk_mdp_frame *frame = &ctx->s_frame;
struct mdp_config *config = &ctx->vpu.vsi->src_config;
config->crop_x = frame->crop.left;
config->crop_y = frame->crop.top;
config->crop_w = frame->crop.width;
config->crop_h = frame->crop.height;
config->x = 0;
config->y = 0;
config->w = frame->width;
config->h = frame->height;
}
void mtk_mdp_hw_set_in_image_format(struct mtk_mdp_ctx *ctx)
{
unsigned int i;
struct mtk_mdp_frame *frame = &ctx->s_frame;
struct mdp_config *config = &ctx->vpu.vsi->src_config;
struct mdp_buffer *src_buf = &ctx->vpu.vsi->src_buffer;
src_buf->plane_num = frame->fmt->num_comp;
config->format = mtk_mdp_map_color_format(frame->fmt->pixelformat);
config->w_stride = 0;
config->h_stride = 0;
for (i = 0; i < src_buf->plane_num; i++)
src_buf->plane_size[i] = frame->payload[i];
}
void mtk_mdp_hw_set_out_size(struct mtk_mdp_ctx *ctx)
{
struct mtk_mdp_frame *frame = &ctx->d_frame;
struct mdp_config *config = &ctx->vpu.vsi->dst_config;
config->crop_x = frame->crop.left;
config->crop_y = frame->crop.top;
config->crop_w = frame->crop.width;
config->crop_h = frame->crop.height;
config->x = 0;
config->y = 0;
config->w = frame->width;
config->h = frame->height;
}
void mtk_mdp_hw_set_out_image_format(struct mtk_mdp_ctx *ctx)
{
unsigned int i;
struct mtk_mdp_frame *frame = &ctx->d_frame;
struct mdp_config *config = &ctx->vpu.vsi->dst_config;
struct mdp_buffer *dst_buf = &ctx->vpu.vsi->dst_buffer;
dst_buf->plane_num = frame->fmt->num_comp;
config->format = mtk_mdp_map_color_format(frame->fmt->pixelformat);
config->w_stride = 0;
config->h_stride = 0;
for (i = 0; i < dst_buf->plane_num; i++)
dst_buf->plane_size[i] = frame->payload[i];
}
void mtk_mdp_hw_set_rotation(struct mtk_mdp_ctx *ctx)
{
struct mdp_config_misc *misc = &ctx->vpu.vsi->misc;
misc->orientation = ctx->ctrls.rotate->val;
misc->hflip = ctx->ctrls.hflip->val;
misc->vflip = ctx->ctrls.vflip->val;
}
void mtk_mdp_hw_set_global_alpha(struct mtk_mdp_ctx *ctx)
{
struct mdp_config_misc *misc = &ctx->vpu.vsi->misc;
misc->alpha = ctx->ctrls.global_alpha->val;
}
