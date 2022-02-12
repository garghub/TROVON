int hgsmi_report_flags_location(struct gen_pool *ctx, u32 location)
{
struct hgsmi_buffer_location *p;
p = hgsmi_buffer_alloc(ctx, sizeof(*p), HGSMI_CH_HGSMI,
HGSMI_CC_HOST_FLAGS_LOCATION);
if (!p)
return -ENOMEM;
p->buf_location = location;
p->buf_len = sizeof(struct hgsmi_host_flags);
hgsmi_buffer_submit(ctx, p);
hgsmi_buffer_free(ctx, p);
return 0;
}
int hgsmi_send_caps_info(struct gen_pool *ctx, u32 caps)
{
struct vbva_caps *p;
p = hgsmi_buffer_alloc(ctx, sizeof(*p), HGSMI_CH_VBVA, VBVA_INFO_CAPS);
if (!p)
return -ENOMEM;
p->rc = VERR_NOT_IMPLEMENTED;
p->caps = caps;
hgsmi_buffer_submit(ctx, p);
WARN_ON_ONCE(RT_FAILURE(p->rc));
hgsmi_buffer_free(ctx, p);
return 0;
}
int hgsmi_test_query_conf(struct gen_pool *ctx)
{
u32 value = 0;
int ret;
ret = hgsmi_query_conf(ctx, U32_MAX, &value);
if (ret)
return ret;
return value == U32_MAX ? 0 : -EIO;
}
int hgsmi_query_conf(struct gen_pool *ctx, u32 index, u32 *value_ret)
{
struct vbva_conf32 *p;
p = hgsmi_buffer_alloc(ctx, sizeof(*p), HGSMI_CH_VBVA,
VBVA_QUERY_CONF32);
if (!p)
return -ENOMEM;
p->index = index;
p->value = U32_MAX;
hgsmi_buffer_submit(ctx, p);
*value_ret = p->value;
hgsmi_buffer_free(ctx, p);
return 0;
}
int hgsmi_update_pointer_shape(struct gen_pool *ctx, u32 flags,
u32 hot_x, u32 hot_y, u32 width, u32 height,
u8 *pixels, u32 len)
{
struct vbva_mouse_pointer_shape *p;
u32 pixel_len = 0;
int rc;
if (flags & VBOX_MOUSE_POINTER_SHAPE) {
pixel_len = ((((width + 7) / 8) * height + 3) & ~3) +
width * 4 * height;
if (pixel_len > len)
return -EINVAL;
flags |= VBOX_MOUSE_POINTER_VISIBLE;
}
p = hgsmi_buffer_alloc(ctx, sizeof(*p) + pixel_len, HGSMI_CH_VBVA,
VBVA_MOUSE_POINTER_SHAPE);
if (!p)
return -ENOMEM;
p->result = VINF_SUCCESS;
p->flags = flags;
p->hot_X = hot_x;
p->hot_y = hot_y;
p->width = width;
p->height = height;
if (pixel_len)
memcpy(p->data, pixels, pixel_len);
hgsmi_buffer_submit(ctx, p);
switch (p->result) {
case VINF_SUCCESS:
rc = 0;
break;
case VERR_NO_MEMORY:
rc = -ENOMEM;
break;
case VERR_NOT_SUPPORTED:
rc = -EBUSY;
break;
default:
rc = -EINVAL;
}
hgsmi_buffer_free(ctx, p);
return rc;
}
int hgsmi_cursor_position(struct gen_pool *ctx, bool report_position,
u32 x, u32 y, u32 *x_host, u32 *y_host)
{
struct vbva_cursor_position *p;
p = hgsmi_buffer_alloc(ctx, sizeof(*p), HGSMI_CH_VBVA,
VBVA_CURSOR_POSITION);
if (!p)
return -ENOMEM;
p->report_position = report_position;
p->x = x;
p->y = y;
hgsmi_buffer_submit(ctx, p);
*x_host = p->x;
*y_host = p->y;
hgsmi_buffer_free(ctx, p);
return 0;
}
