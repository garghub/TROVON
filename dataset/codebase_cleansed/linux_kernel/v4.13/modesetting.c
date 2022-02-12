void hgsmi_process_display_info(struct gen_pool *ctx, u32 display,
s32 origin_x, s32 origin_y, u32 start_offset,
u32 pitch, u32 width, u32 height,
u16 bpp, u16 flags)
{
struct vbva_infoscreen *p;
p = hgsmi_buffer_alloc(ctx, sizeof(*p), HGSMI_CH_VBVA,
VBVA_INFO_SCREEN);
if (!p)
return;
p->view_index = display;
p->origin_x = origin_x;
p->origin_y = origin_y;
p->start_offset = start_offset;
p->line_size = pitch;
p->width = width;
p->height = height;
p->bits_per_pixel = bpp;
p->flags = flags;
hgsmi_buffer_submit(ctx, p);
hgsmi_buffer_free(ctx, p);
}
int hgsmi_update_input_mapping(struct gen_pool *ctx, s32 origin_x, s32 origin_y,
u32 width, u32 height)
{
struct vbva_report_input_mapping *p;
p = hgsmi_buffer_alloc(ctx, sizeof(*p), HGSMI_CH_VBVA,
VBVA_REPORT_INPUT_MAPPING);
if (!p)
return -ENOMEM;
p->x = origin_x;
p->y = origin_y;
p->cx = width;
p->cy = height;
hgsmi_buffer_submit(ctx, p);
hgsmi_buffer_free(ctx, p);
return 0;
}
int hgsmi_get_mode_hints(struct gen_pool *ctx, unsigned int screens,
struct vbva_modehint *hints)
{
struct vbva_query_mode_hints *p;
size_t size;
if (WARN_ON(!hints))
return -EINVAL;
size = screens * sizeof(struct vbva_modehint);
p = hgsmi_buffer_alloc(ctx, sizeof(*p) + size, HGSMI_CH_VBVA,
VBVA_QUERY_MODE_HINTS);
if (!p)
return -ENOMEM;
p->hints_queried_count = screens;
p->hint_structure_guest_size = sizeof(struct vbva_modehint);
p->rc = VERR_NOT_SUPPORTED;
hgsmi_buffer_submit(ctx, p);
if (RT_FAILURE(p->rc)) {
hgsmi_buffer_free(ctx, p);
return -EIO;
}
memcpy(hints, ((u8 *)p) + sizeof(struct vbva_query_mode_hints), size);
hgsmi_buffer_free(ctx, p);
return 0;
}
