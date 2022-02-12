static struct uvcg_control_header *to_uvcg_control_header(struct config_item *item)
{
return container_of(item, struct uvcg_control_header, item);
}
static struct config_item *uvcg_control_header_make(struct config_group *group,
const char *name)
{
struct uvcg_control_header *h;
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (!h)
return ERR_PTR(-ENOMEM);
h->desc.bLength = UVC_DT_HEADER_SIZE(1);
h->desc.bDescriptorType = USB_DT_CS_INTERFACE;
h->desc.bDescriptorSubType = UVC_VC_HEADER;
h->desc.bcdUVC = cpu_to_le16(0x0100);
h->desc.dwClockFrequency = cpu_to_le32(48000000);
config_item_init_type_name(&h->item, name, &uvcg_control_header_type);
return &h->item;
}
static void uvcg_control_header_drop(struct config_group *group,
struct config_item *item)
{
struct uvcg_control_header *h = to_uvcg_control_header(item);
kfree(h);
}
static inline struct uvcg_default_processing
*to_uvcg_default_processing(struct config_item *item)
{
return container_of(to_config_group(item),
struct uvcg_default_processing, group);
}
static ssize_t uvcg_default_processing_bm_controls_show(
struct uvcg_default_processing *dp, char *page)
{
struct f_uvc_opts *opts;
struct config_item *opts_item;
struct mutex *su_mutex = &dp->group.cg_subsys->su_mutex;
struct uvc_processing_unit_descriptor *pd;
int result, i;
char *pg = page;
mutex_lock(su_mutex);
opts_item = dp->group.cg_item.ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
pd = &opts->uvc_processing;
mutex_lock(&opts->lock);
for (result = 0, i = 0; i < pd->bControlSize; ++i) {
result += sprintf(pg, "%d\n", pd->bmControls[i]);
pg = page + result;
}
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return result;
}
static inline struct uvcg_default_camera
*to_uvcg_default_camera(struct config_item *item)
{
return container_of(to_config_group(item),
struct uvcg_default_camera, group);
}
static ssize_t uvcg_default_camera_bm_controls_show(
struct uvcg_default_camera *dc, char *page)
{
struct f_uvc_opts *opts;
struct config_item *opts_item;
struct mutex *su_mutex = &dc->group.cg_subsys->su_mutex;
struct uvc_camera_terminal_descriptor *cd;
int result, i;
char *pg = page;
mutex_lock(su_mutex);
opts_item = dc->group.cg_item.ci_parent->ci_parent->ci_parent->
ci_parent;
opts = to_f_uvc_opts(opts_item);
cd = &opts->uvc_camera_terminal;
mutex_lock(&opts->lock);
for (result = 0, i = 0; i < cd->bControlSize; ++i) {
result += sprintf(pg, "%d\n", cd->bmControls[i]);
pg = page + result;
}
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return result;
}
static inline struct uvcg_default_output
*to_uvcg_default_output(struct config_item *item)
{
return container_of(to_config_group(item),
struct uvcg_default_output, group);
}
static inline struct uvc_descriptor_header
**uvcg_get_ctl_class_arr(struct config_item *i, struct f_uvc_opts *o)
{
struct uvcg_control_class *cl = container_of(to_config_group(i),
struct uvcg_control_class, group);
if (cl == &uvcg_control_class_fs)
return o->uvc_fs_control_cls;
if (cl == &uvcg_control_class_ss)
return o->uvc_ss_control_cls;
return NULL;
}
static int uvcg_control_class_allow_link(struct config_item *src,
struct config_item *target)
{
struct config_item *control, *header;
struct f_uvc_opts *opts;
struct mutex *su_mutex = &src->ci_group->cg_subsys->su_mutex;
struct uvc_descriptor_header **class_array;
struct uvcg_control_header *target_hdr;
int ret = -EINVAL;
mutex_lock(su_mutex);
control = src->ci_parent->ci_parent;
header = config_group_find_item(to_config_group(control), "header");
if (!header || target->ci_parent != header)
goto out;
opts = to_f_uvc_opts(control->ci_parent);
mutex_lock(&opts->lock);
class_array = uvcg_get_ctl_class_arr(src, opts);
if (!class_array)
goto unlock;
if (opts->refcnt || class_array[0]) {
ret = -EBUSY;
goto unlock;
}
target_hdr = to_uvcg_control_header(target);
++target_hdr->linked;
class_array[0] = (struct uvc_descriptor_header *)&target_hdr->desc;
ret = 0;
unlock:
mutex_unlock(&opts->lock);
out:
mutex_unlock(su_mutex);
return ret;
}
static int uvcg_control_class_drop_link(struct config_item *src,
struct config_item *target)
{
struct config_item *control, *header;
struct f_uvc_opts *opts;
struct mutex *su_mutex = &src->ci_group->cg_subsys->su_mutex;
struct uvc_descriptor_header **class_array;
struct uvcg_control_header *target_hdr;
int ret = -EINVAL;
mutex_lock(su_mutex);
control = src->ci_parent->ci_parent;
header = config_group_find_item(to_config_group(control), "header");
if (!header || target->ci_parent != header)
goto out;
opts = to_f_uvc_opts(control->ci_parent);
mutex_lock(&opts->lock);
class_array = uvcg_get_ctl_class_arr(src, opts);
if (!class_array)
goto unlock;
if (opts->refcnt) {
ret = -EBUSY;
goto unlock;
}
target_hdr = to_uvcg_control_header(target);
--target_hdr->linked;
class_array[0] = NULL;
ret = 0;
unlock:
mutex_unlock(&opts->lock);
out:
mutex_unlock(su_mutex);
return ret;
}
static struct uvcg_format *to_uvcg_format(struct config_item *item)
{
return container_of(to_config_group(item), struct uvcg_format, group);
}
static ssize_t uvcg_format_bma_controls_show(struct uvcg_format *f, char *page)
{
struct f_uvc_opts *opts;
struct config_item *opts_item;
struct mutex *su_mutex = &f->group.cg_subsys->su_mutex;
int result, i;
char *pg = page;
mutex_lock(su_mutex);
opts_item = f->group.cg_item.ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
mutex_lock(&opts->lock);
result = sprintf(pg, "0x");
pg += result;
for (i = 0; i < UVCG_STREAMING_CONTROL_SIZE; ++i) {
result += sprintf(pg, "%x\n", f->bmaControls[i]);
pg = page + result;
}
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return result;
}
static ssize_t uvcg_format_bma_controls_store(struct uvcg_format *ch,
const char *page, size_t len)
{
struct f_uvc_opts *opts;
struct config_item *opts_item;
struct mutex *su_mutex = &ch->group.cg_subsys->su_mutex;
int ret = -EINVAL;
mutex_lock(su_mutex);
opts_item = ch->group.cg_item.ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
mutex_lock(&opts->lock);
if (ch->linked || opts->refcnt) {
ret = -EBUSY;
goto end;
}
if (len < 4 || *page != '0' ||
(*(page + 1) != 'x' && *(page + 1) != 'X'))
goto end;
ret = hex2bin(ch->bmaControls, page + 2, 1);
if (ret < 0)
goto end;
ret = len;
end:
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return ret;
}
static struct uvcg_streaming_header *to_uvcg_streaming_header(struct config_item *item)
{
return container_of(item, struct uvcg_streaming_header, item);
}
static int uvcg_streaming_header_allow_link(struct config_item *src,
struct config_item *target)
{
struct mutex *su_mutex = &src->ci_group->cg_subsys->su_mutex;
struct config_item *opts_item;
struct f_uvc_opts *opts;
struct uvcg_streaming_header *src_hdr;
struct uvcg_format *target_fmt = NULL;
struct uvcg_format_ptr *format_ptr;
int i, ret = -EINVAL;
src_hdr = to_uvcg_streaming_header(src);
mutex_lock(su_mutex);
opts_item = src->ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
mutex_lock(&opts->lock);
if (src_hdr->linked) {
ret = -EBUSY;
goto out;
}
for (i = 0; i < ARRAY_SIZE(fmt_parent); ++i)
if (target->ci_parent == fmt_parent[i])
break;
if (i == ARRAY_SIZE(fmt_parent))
goto out;
target_fmt = container_of(to_config_group(target), struct uvcg_format,
group);
if (!target_fmt)
goto out;
format_ptr = kzalloc(sizeof(*format_ptr), GFP_KERNEL);
if (!format_ptr) {
ret = -ENOMEM;
goto out;
}
ret = 0;
format_ptr->fmt = target_fmt;
list_add_tail(&format_ptr->entry, &src_hdr->formats);
++src_hdr->num_fmt;
out:
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return ret;
}
static int uvcg_streaming_header_drop_link(struct config_item *src,
struct config_item *target)
{
struct mutex *su_mutex = &src->ci_group->cg_subsys->su_mutex;
struct config_item *opts_item;
struct f_uvc_opts *opts;
struct uvcg_streaming_header *src_hdr;
struct uvcg_format *target_fmt = NULL;
struct uvcg_format_ptr *format_ptr, *tmp;
int ret = -EINVAL;
src_hdr = to_uvcg_streaming_header(src);
mutex_lock(su_mutex);
opts_item = src->ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
mutex_lock(&opts->lock);
target_fmt = container_of(to_config_group(target), struct uvcg_format,
group);
if (!target_fmt)
goto out;
list_for_each_entry_safe(format_ptr, tmp, &src_hdr->formats, entry)
if (format_ptr->fmt == target_fmt) {
list_del(&format_ptr->entry);
kfree(format_ptr);
--src_hdr->num_fmt;
break;
}
out:
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return ret;
}
static struct config_item
*uvcg_streaming_header_make(struct config_group *group, const char *name)
{
struct uvcg_streaming_header *h;
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (!h)
return ERR_PTR(-ENOMEM);
INIT_LIST_HEAD(&h->formats);
h->desc.bDescriptorType = USB_DT_CS_INTERFACE;
h->desc.bDescriptorSubType = UVC_VS_INPUT_HEADER;
h->desc.bTerminalLink = 3;
h->desc.bControlSize = UVCG_STREAMING_CONTROL_SIZE;
config_item_init_type_name(&h->item, name, &uvcg_streaming_header_type);
return &h->item;
}
static void uvcg_streaming_header_drop(struct config_group *group,
struct config_item *item)
{
struct uvcg_streaming_header *h = to_uvcg_streaming_header(item);
kfree(h);
}
static struct uvcg_frame *to_uvcg_frame(struct config_item *item)
{
return container_of(item, struct uvcg_frame, item);
}
static ssize_t uvcg_frame_dw_frame_interval_show(struct uvcg_frame *frm,
char *page)
{
struct f_uvc_opts *opts;
struct config_item *opts_item;
struct mutex *su_mutex = &frm->item.ci_group->cg_subsys->su_mutex;
int result, i;
char *pg = page;
mutex_lock(su_mutex);
opts_item = frm->item.ci_parent->ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
mutex_lock(&opts->lock);
for (result = 0, i = 0; i < frm->frame.b_frame_interval_type; ++i) {
result += sprintf(pg, "%d\n",
le32_to_cpu(frm->dw_frame_interval[i]));
pg = page + result;
}
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return result;
}
static inline int __uvcg_count_frm_intrv(char *buf, void *priv)
{
++*((int *)priv);
return 0;
}
static inline int __uvcg_fill_frm_intrv(char *buf, void *priv)
{
u32 num, **interv;
int ret;
ret = kstrtou32(buf, 0, &num);
if (ret)
return ret;
interv = priv;
**interv = cpu_to_le32(num);
++*interv;
return 0;
}
static int __uvcg_iter_frm_intrv(const char *page, size_t len,
int (*fun)(char *, void *), void *priv)
{
char buf[1 + sizeof(u32) * 8 + 1 + 1];
const char *pg = page;
int i, ret;
if (!fun)
return -EINVAL;
while (pg - page < len) {
i = 0;
while (i < sizeof(buf) && (pg - page < len) &&
*pg != '\0' && *pg != '\n')
buf[i++] = *pg++;
if (i == sizeof(buf))
return -EINVAL;
while ((pg - page < len) && (*pg == '\0' || *pg == '\n'))
++pg;
buf[i] = '\0';
ret = fun(buf, priv);
if (ret)
return ret;
}
return 0;
}
static ssize_t uvcg_frame_dw_frame_interval_store(struct uvcg_frame *ch,
const char *page, size_t len)
{
struct f_uvc_opts *opts;
struct config_item *opts_item;
struct uvcg_format *fmt;
struct mutex *su_mutex = &ch->item.ci_group->cg_subsys->su_mutex;
int ret = 0, n = 0;
u32 *frm_intrv, *tmp;
mutex_lock(su_mutex);
opts_item = ch->item.ci_parent->ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
fmt = to_uvcg_format(ch->item.ci_parent);
mutex_lock(&opts->lock);
if (fmt->linked || opts->refcnt) {
ret = -EBUSY;
goto end;
}
ret = __uvcg_iter_frm_intrv(page, len, __uvcg_count_frm_intrv, &n);
if (ret)
goto end;
tmp = frm_intrv = kcalloc(n, sizeof(u32), GFP_KERNEL);
if (!frm_intrv) {
ret = -ENOMEM;
goto end;
}
ret = __uvcg_iter_frm_intrv(page, len, __uvcg_fill_frm_intrv, &tmp);
if (ret) {
kfree(frm_intrv);
goto end;
}
kfree(ch->dw_frame_interval);
ch->dw_frame_interval = frm_intrv;
ch->frame.b_frame_interval_type = n;
ret = len;
end:
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return ret;
}
static struct config_item *uvcg_frame_make(struct config_group *group,
const char *name)
{
struct uvcg_frame *h;
struct uvcg_format *fmt;
struct f_uvc_opts *opts;
struct config_item *opts_item;
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (!h)
return ERR_PTR(-ENOMEM);
h->frame.b_descriptor_type = USB_DT_CS_INTERFACE;
h->frame.b_frame_index = 1;
h->frame.w_width = cpu_to_le16(640);
h->frame.w_height = cpu_to_le16(360);
h->frame.dw_min_bit_rate = cpu_to_le32(18432000);
h->frame.dw_max_bit_rate = cpu_to_le32(55296000);
h->frame.dw_max_video_frame_buffer_size = cpu_to_le32(460800);
h->frame.dw_default_frame_interval = cpu_to_le32(666666);
opts_item = group->cg_item.ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
mutex_lock(&opts->lock);
fmt = to_uvcg_format(&group->cg_item);
if (fmt->type == UVCG_UNCOMPRESSED) {
h->frame.b_descriptor_subtype = UVC_VS_FRAME_UNCOMPRESSED;
h->fmt_type = UVCG_UNCOMPRESSED;
} else if (fmt->type == UVCG_MJPEG) {
h->frame.b_descriptor_subtype = UVC_VS_FRAME_MJPEG;
h->fmt_type = UVCG_MJPEG;
} else {
mutex_unlock(&opts->lock);
kfree(h);
return ERR_PTR(-EINVAL);
}
++fmt->num_frames;
mutex_unlock(&opts->lock);
config_item_init_type_name(&h->item, name, &uvcg_frame_type);
return &h->item;
}
static void uvcg_frame_drop(struct config_group *group, struct config_item *item)
{
struct uvcg_frame *h = to_uvcg_frame(item);
struct uvcg_format *fmt;
struct f_uvc_opts *opts;
struct config_item *opts_item;
opts_item = group->cg_item.ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
mutex_lock(&opts->lock);
fmt = to_uvcg_format(&group->cg_item);
--fmt->num_frames;
kfree(h);
mutex_unlock(&opts->lock);
}
static struct uvcg_uncompressed *to_uvcg_uncompressed(struct config_item *item)
{
return container_of(
container_of(to_config_group(item), struct uvcg_format, group),
struct uvcg_uncompressed, fmt);
}
static ssize_t uvcg_uncompressed_guid_format_show(struct uvcg_uncompressed *ch,
char *page)
{
struct f_uvc_opts *opts;
struct config_item *opts_item;
struct mutex *su_mutex = &ch->fmt.group.cg_subsys->su_mutex;
mutex_lock(su_mutex);
opts_item = ch->fmt.group.cg_item.ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
mutex_lock(&opts->lock);
memcpy(page, ch->desc.guidFormat, sizeof(ch->desc.guidFormat));
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return sizeof(ch->desc.guidFormat);
}
static ssize_t uvcg_uncompressed_guid_format_store(struct uvcg_uncompressed *ch,
const char *page, size_t len)
{
struct f_uvc_opts *opts;
struct config_item *opts_item;
struct mutex *su_mutex = &ch->fmt.group.cg_subsys->su_mutex;
int ret;
mutex_lock(su_mutex);
opts_item = ch->fmt.group.cg_item.ci_parent->ci_parent->ci_parent;
opts = to_f_uvc_opts(opts_item);
mutex_lock(&opts->lock);
if (ch->fmt.linked || opts->refcnt) {
ret = -EBUSY;
goto end;
}
memcpy(ch->desc.guidFormat, page,
min(sizeof(ch->desc.guidFormat), len));
ret = sizeof(ch->desc.guidFormat);
end:
mutex_unlock(&opts->lock);
mutex_unlock(su_mutex);
return ret;
}
static inline ssize_t
uvcg_uncompressed_bma_controls_show(struct uvcg_uncompressed *unc, char *page)
{
return uvcg_format_bma_controls_show(&unc->fmt, page);
}
static inline ssize_t
uvcg_uncompressed_bma_controls_store(struct uvcg_uncompressed *ch,
const char *page, size_t len)
{
return uvcg_format_bma_controls_store(&ch->fmt, page, len);
}
static struct config_group *uvcg_uncompressed_make(struct config_group *group,
const char *name)
{
static char guid[] = {
'Y', 'U', 'Y', '2', 0x00, 0x00, 0x10, 0x00,
0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71
};
struct uvcg_uncompressed *h;
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (!h)
return ERR_PTR(-ENOMEM);
h->desc.bLength = UVC_DT_FORMAT_UNCOMPRESSED_SIZE;
h->desc.bDescriptorType = USB_DT_CS_INTERFACE;
h->desc.bDescriptorSubType = UVC_VS_FORMAT_UNCOMPRESSED;
memcpy(h->desc.guidFormat, guid, sizeof(guid));
h->desc.bBitsPerPixel = 16;
h->desc.bDefaultFrameIndex = 1;
h->desc.bAspectRatioX = 0;
h->desc.bAspectRatioY = 0;
h->desc.bmInterfaceFlags = 0;
h->desc.bCopyProtect = 0;
h->fmt.type = UVCG_UNCOMPRESSED;
config_group_init_type_name(&h->fmt.group, name,
&uvcg_uncompressed_type);
return &h->fmt.group;
}
static void uvcg_uncompressed_drop(struct config_group *group,
struct config_item *item)
{
struct uvcg_uncompressed *h = to_uvcg_uncompressed(item);
kfree(h);
}
static struct uvcg_mjpeg *to_uvcg_mjpeg(struct config_item *item)
{
return container_of(
container_of(to_config_group(item), struct uvcg_format, group),
struct uvcg_mjpeg, fmt);
}
static inline ssize_t
uvcg_mjpeg_bma_controls_show(struct uvcg_mjpeg *unc, char *page)
{
return uvcg_format_bma_controls_show(&unc->fmt, page);
}
static inline ssize_t
uvcg_mjpeg_bma_controls_store(struct uvcg_mjpeg *ch,
const char *page, size_t len)
{
return uvcg_format_bma_controls_store(&ch->fmt, page, len);
}
static struct config_group *uvcg_mjpeg_make(struct config_group *group,
const char *name)
{
struct uvcg_mjpeg *h;
h = kzalloc(sizeof(*h), GFP_KERNEL);
if (!h)
return ERR_PTR(-ENOMEM);
h->desc.bLength = UVC_DT_FORMAT_MJPEG_SIZE;
h->desc.bDescriptorType = USB_DT_CS_INTERFACE;
h->desc.bDescriptorSubType = UVC_VS_FORMAT_MJPEG;
h->desc.bDefaultFrameIndex = 1;
h->desc.bAspectRatioX = 0;
h->desc.bAspectRatioY = 0;
h->desc.bmInterfaceFlags = 0;
h->desc.bCopyProtect = 0;
h->fmt.type = UVCG_MJPEG;
config_group_init_type_name(&h->fmt.group, name,
&uvcg_mjpeg_type);
return &h->fmt.group;
}
static void uvcg_mjpeg_drop(struct config_group *group,
struct config_item *item)
{
struct uvcg_mjpeg *h = to_uvcg_mjpeg(item);
kfree(h);
}
static inline struct uvcg_default_color_matching
*to_uvcg_default_color_matching(struct config_item *item)
{
return container_of(to_config_group(item),
struct uvcg_default_color_matching, group);
}
static inline struct uvc_descriptor_header
***__uvcg_get_stream_class_arr(struct config_item *i, struct f_uvc_opts *o)
{
struct uvcg_streaming_class *cl = container_of(to_config_group(i),
struct uvcg_streaming_class, group);
if (cl == &uvcg_streaming_class_fs)
return &o->uvc_fs_streaming_cls;
if (cl == &uvcg_streaming_class_hs)
return &o->uvc_hs_streaming_cls;
if (cl == &uvcg_streaming_class_ss)
return &o->uvc_ss_streaming_cls;
return NULL;
}
static int __uvcg_iter_strm_cls(struct uvcg_streaming_header *h,
void *priv2, void *priv3,
int (*fun)(void *, void *, void *, int, enum uvcg_strm_type type))
{
struct uvcg_format_ptr *f;
struct config_group *grp;
struct config_item *item;
struct uvcg_frame *frm;
int ret, i, j;
if (!fun)
return -EINVAL;
i = j = 0;
ret = fun(h, priv2, priv3, 0, UVCG_HEADER);
if (ret)
return ret;
list_for_each_entry(f, &h->formats, entry) {
ret = fun(f->fmt, priv2, priv3, i++, UVCG_FORMAT);
if (ret)
return ret;
grp = &f->fmt->group;
list_for_each_entry(item, &grp->cg_children, ci_entry) {
frm = to_uvcg_frame(item);
ret = fun(frm, priv2, priv3, j++, UVCG_FRAME);
if (ret)
return ret;
}
}
return ret;
}
static int __uvcg_cnt_strm(void *priv1, void *priv2, void *priv3, int n,
enum uvcg_strm_type type)
{
size_t *size = priv2;
size_t *count = priv3;
switch (type) {
case UVCG_HEADER: {
struct uvcg_streaming_header *h = priv1;
*size += sizeof(h->desc);
*size += h->num_fmt * UVCG_STREAMING_CONTROL_SIZE;
}
break;
case UVCG_FORMAT: {
struct uvcg_format *fmt = priv1;
if (fmt->type == UVCG_UNCOMPRESSED) {
struct uvcg_uncompressed *u =
container_of(fmt, struct uvcg_uncompressed,
fmt);
*size += sizeof(u->desc);
} else if (fmt->type == UVCG_MJPEG) {
struct uvcg_mjpeg *m =
container_of(fmt, struct uvcg_mjpeg, fmt);
*size += sizeof(m->desc);
} else {
return -EINVAL;
}
}
break;
case UVCG_FRAME: {
struct uvcg_frame *frm = priv1;
int sz = sizeof(frm->dw_frame_interval);
*size += sizeof(frm->frame);
*size += frm->frame.b_frame_interval_type * sz;
}
break;
}
++*count;
return 0;
}
static int __uvcg_fill_strm(void *priv1, void *priv2, void *priv3, int n,
enum uvcg_strm_type type)
{
void **dest = priv2;
struct uvc_descriptor_header ***array = priv3;
size_t sz;
**array = *dest;
++*array;
switch (type) {
case UVCG_HEADER: {
struct uvc_input_header_descriptor *ihdr = *dest;
struct uvcg_streaming_header *h = priv1;
struct uvcg_format_ptr *f;
memcpy(*dest, &h->desc, sizeof(h->desc));
*dest += sizeof(h->desc);
sz = UVCG_STREAMING_CONTROL_SIZE;
list_for_each_entry(f, &h->formats, entry) {
memcpy(*dest, f->fmt->bmaControls, sz);
*dest += sz;
}
ihdr->bLength = sizeof(h->desc) + h->num_fmt * sz;
ihdr->bNumFormats = h->num_fmt;
}
break;
case UVCG_FORMAT: {
struct uvcg_format *fmt = priv1;
if (fmt->type == UVCG_UNCOMPRESSED) {
struct uvc_format_uncompressed *unc = *dest;
struct uvcg_uncompressed *u =
container_of(fmt, struct uvcg_uncompressed,
fmt);
memcpy(*dest, &u->desc, sizeof(u->desc));
*dest += sizeof(u->desc);
unc->bNumFrameDescriptors = fmt->num_frames;
unc->bFormatIndex = n + 1;
} else if (fmt->type == UVCG_MJPEG) {
struct uvc_format_mjpeg *mjp = *dest;
struct uvcg_mjpeg *m =
container_of(fmt, struct uvcg_mjpeg, fmt);
memcpy(*dest, &m->desc, sizeof(m->desc));
*dest += sizeof(m->desc);
mjp->bNumFrameDescriptors = fmt->num_frames;
mjp->bFormatIndex = n + 1;
} else {
return -EINVAL;
}
}
break;
case UVCG_FRAME: {
struct uvcg_frame *frm = priv1;
struct uvc_descriptor_header *h = *dest;
sz = sizeof(frm->frame);
memcpy(*dest, &frm->frame, sz);
*dest += sz;
sz = frm->frame.b_frame_interval_type *
sizeof(*frm->dw_frame_interval);
memcpy(*dest, frm->dw_frame_interval, sz);
*dest += sz;
if (frm->fmt_type == UVCG_UNCOMPRESSED)
h->bLength = UVC_DT_FRAME_UNCOMPRESSED_SIZE(
frm->frame.b_frame_interval_type);
else if (frm->fmt_type == UVCG_MJPEG)
h->bLength = UVC_DT_FRAME_MJPEG_SIZE(
frm->frame.b_frame_interval_type);
}
break;
}
return 0;
}
static int uvcg_streaming_class_allow_link(struct config_item *src,
struct config_item *target)
{
struct config_item *streaming, *header;
struct f_uvc_opts *opts;
struct mutex *su_mutex = &src->ci_group->cg_subsys->su_mutex;
struct uvc_descriptor_header ***class_array, **cl_arr;
struct uvcg_streaming_header *target_hdr;
void *data, *data_save;
size_t size = 0, count = 0;
int ret = -EINVAL;
mutex_lock(su_mutex);
streaming = src->ci_parent->ci_parent;
header = config_group_find_item(to_config_group(streaming), "header");
if (!header || target->ci_parent != header)
goto out;
opts = to_f_uvc_opts(streaming->ci_parent);
mutex_lock(&opts->lock);
class_array = __uvcg_get_stream_class_arr(src, opts);
if (!class_array || *class_array || opts->refcnt) {
ret = -EBUSY;
goto unlock;
}
target_hdr = to_uvcg_streaming_header(target);
ret = __uvcg_iter_strm_cls(target_hdr, &size, &count, __uvcg_cnt_strm);
if (ret)
goto unlock;
count += 2;
*class_array = kcalloc(count, sizeof(void *), GFP_KERNEL);
if (!*class_array) {
ret = -ENOMEM;
goto unlock;
}
data = data_save = kzalloc(size, GFP_KERNEL);
if (!data) {
kfree(*class_array);
*class_array = NULL;
ret = PTR_ERR(data);
goto unlock;
}
cl_arr = *class_array;
ret = __uvcg_iter_strm_cls(target_hdr, &data, &cl_arr,
__uvcg_fill_strm);
if (ret) {
kfree(*class_array);
*class_array = NULL;
kfree(data_save);
goto unlock;
}
*cl_arr = (struct uvc_descriptor_header *)&opts->uvc_color_matching;
++target_hdr->linked;
ret = 0;
unlock:
mutex_unlock(&opts->lock);
out:
mutex_unlock(su_mutex);
return ret;
}
static int uvcg_streaming_class_drop_link(struct config_item *src,
struct config_item *target)
{
struct config_item *streaming, *header;
struct f_uvc_opts *opts;
struct mutex *su_mutex = &src->ci_group->cg_subsys->su_mutex;
struct uvc_descriptor_header ***class_array;
struct uvcg_streaming_header *target_hdr;
int ret = -EINVAL;
mutex_lock(su_mutex);
streaming = src->ci_parent->ci_parent;
header = config_group_find_item(to_config_group(streaming), "header");
if (!header || target->ci_parent != header)
goto out;
opts = to_f_uvc_opts(streaming->ci_parent);
mutex_lock(&opts->lock);
class_array = __uvcg_get_stream_class_arr(src, opts);
if (!class_array || !*class_array)
goto unlock;
if (opts->refcnt) {
ret = -EBUSY;
goto unlock;
}
target_hdr = to_uvcg_streaming_header(target);
--target_hdr->linked;
kfree(**class_array);
kfree(*class_array);
*class_array = NULL;
ret = 0;
unlock:
mutex_unlock(&opts->lock);
out:
mutex_unlock(su_mutex);
return ret;
}
static inline struct f_uvc_opts *to_f_uvc_opts(struct config_item *item)
{
return container_of(to_config_group(item), struct f_uvc_opts,
func_inst.group);
}
static void uvc_attr_release(struct config_item *item)
{
struct f_uvc_opts *opts = to_f_uvc_opts(item);
usb_put_function_instance(&opts->func_inst);
}
static inline void uvcg_init_group(struct config_group *g,
struct config_group **default_groups,
const char *name,
struct config_item_type *type)
{
g->default_groups = default_groups;
config_group_init_type_name(g, name, type);
}
int uvcg_attach_configfs(struct f_uvc_opts *opts)
{
config_group_init_type_name(&uvcg_control_header_grp.group,
"header",
&uvcg_control_header_grp_type);
config_group_init_type_name(&uvcg_default_processing.group,
"default",
&uvcg_default_processing_type);
uvcg_init_group(&uvcg_processing_grp.group,
uvcg_processing_default_groups,
"processing",
&uvcg_processing_grp_type);
config_group_init_type_name(&uvcg_default_camera.group,
"default",
&uvcg_default_camera_type);
uvcg_init_group(&uvcg_camera_grp.group,
uvcg_camera_default_groups,
"camera",
&uvcg_camera_grp_type);
config_group_init_type_name(&uvcg_default_output.group,
"default",
&uvcg_default_output_type);
uvcg_init_group(&uvcg_output_grp.group,
uvcg_output_default_groups,
"output",
&uvcg_output_grp_type);
uvcg_init_group(&uvcg_terminal_grp.group,
uvcg_terminal_default_groups,
"terminal",
&uvcg_terminal_grp_type);
config_group_init_type_name(&uvcg_control_class_fs.group,
"fs",
&uvcg_control_class_type);
config_group_init_type_name(&uvcg_control_class_ss.group,
"ss",
&uvcg_control_class_type);
uvcg_init_group(&uvcg_control_class_grp.group,
uvcg_control_class_default_groups,
"class",
&uvcg_control_class_grp_type);
uvcg_init_group(&uvcg_control_grp.group,
uvcg_control_default_groups,
"control",
&uvcg_control_grp_type);
config_group_init_type_name(&uvcg_streaming_header_grp.group,
"header",
&uvcg_streaming_header_grp_type);
config_group_init_type_name(&uvcg_uncompressed_grp.group,
"uncompressed",
&uvcg_uncompressed_grp_type);
config_group_init_type_name(&uvcg_mjpeg_grp.group,
"mjpeg",
&uvcg_mjpeg_grp_type);
config_group_init_type_name(&uvcg_default_color_matching.group,
"default",
&uvcg_default_color_matching_type);
uvcg_init_group(&uvcg_color_matching_grp.group,
uvcg_color_matching_default_groups,
"color_matching",
&uvcg_color_matching_grp_type);
config_group_init_type_name(&uvcg_streaming_class_fs.group,
"fs",
&uvcg_streaming_class_type);
config_group_init_type_name(&uvcg_streaming_class_hs.group,
"hs",
&uvcg_streaming_class_type);
config_group_init_type_name(&uvcg_streaming_class_ss.group,
"ss",
&uvcg_streaming_class_type);
uvcg_init_group(&uvcg_streaming_class_grp.group,
uvcg_streaming_class_default_groups,
"class",
&uvcg_streaming_class_grp_type);
uvcg_init_group(&uvcg_streaming_grp.group,
uvcg_streaming_default_groups,
"streaming",
&uvcg_streaming_grp_type);
uvcg_init_group(&opts->func_inst.group,
uvcg_default_groups,
"",
&uvc_func_type);
return 0;
}
