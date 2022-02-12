static int
qxl_image_create_helper(struct qxl_device *qdev,
struct qxl_release *release,
struct qxl_bo **image_bo,
const uint8_t *data,
int width, int height,
int depth, unsigned int hash,
int stride)
{
struct qxl_image *image;
struct qxl_data_chunk *chunk;
int i;
int chunk_stride;
int linesize = width * depth / 8;
struct qxl_bo *chunk_bo;
int ret;
void *ptr;
chunk_stride = stride;
ret = qxl_alloc_bo_reserved(qdev, sizeof(*chunk) + height * chunk_stride,
&chunk_bo);
ptr = qxl_bo_kmap_atomic_page(qdev, chunk_bo, 0);
chunk = ptr;
chunk->data_size = height * chunk_stride;
chunk->prev_chunk = 0;
chunk->next_chunk = 0;
qxl_bo_kunmap_atomic_page(qdev, chunk_bo, ptr);
{
void *k_data, *i_data;
int remain;
int page;
int size;
if (stride == linesize && chunk_stride == stride) {
remain = linesize * height;
page = 0;
i_data = (void *)data;
while (remain > 0) {
ptr = qxl_bo_kmap_atomic_page(qdev, chunk_bo, page << PAGE_SHIFT);
if (page == 0) {
chunk = ptr;
k_data = chunk->data;
size = PAGE_SIZE - offsetof(struct qxl_data_chunk, data);
} else {
k_data = ptr;
size = PAGE_SIZE;
}
size = min(size, remain);
memcpy(k_data, i_data, size);
qxl_bo_kunmap_atomic_page(qdev, chunk_bo, ptr);
i_data += size;
remain -= size;
page++;
}
} else {
unsigned page_base, page_offset, out_offset;
for (i = 0 ; i < height ; ++i) {
i_data = (void *)data + i * stride;
remain = linesize;
out_offset = offsetof(struct qxl_data_chunk, data) + i * chunk_stride;
while (remain > 0) {
page_base = out_offset & PAGE_MASK;
page_offset = offset_in_page(out_offset);
size = min((int)(PAGE_SIZE - page_offset), remain);
ptr = qxl_bo_kmap_atomic_page(qdev, chunk_bo, page_base);
k_data = ptr + page_offset;
memcpy(k_data, i_data, size);
qxl_bo_kunmap_atomic_page(qdev, chunk_bo, ptr);
remain -= size;
i_data += size;
out_offset += size;
}
}
}
}
qxl_bo_kunmap(chunk_bo);
ret = qxl_alloc_bo_reserved(qdev, sizeof(*image), image_bo);
ptr = qxl_bo_kmap_atomic_page(qdev, *image_bo, 0);
image = ptr;
image->descriptor.id = 0;
image->descriptor.type = SPICE_IMAGE_TYPE_BITMAP;
image->descriptor.flags = 0;
image->descriptor.width = width;
image->descriptor.height = height;
switch (depth) {
case 1:
image->u.bitmap.format = SPICE_BITMAP_FMT_1BIT_BE;
break;
case 24:
image->u.bitmap.format = SPICE_BITMAP_FMT_24BIT;
break;
case 32:
image->u.bitmap.format = SPICE_BITMAP_FMT_32BIT;
break;
default:
DRM_ERROR("unsupported image bit depth\n");
return -EINVAL;
}
image->u.bitmap.flags = QXL_BITMAP_TOP_DOWN;
image->u.bitmap.x = width;
image->u.bitmap.y = height;
image->u.bitmap.stride = chunk_stride;
image->u.bitmap.palette = 0;
image->u.bitmap.data = qxl_bo_physical_address(qdev, chunk_bo, 0);
qxl_release_add_res(qdev, release, chunk_bo);
qxl_bo_unreserve(chunk_bo);
qxl_bo_unref(&chunk_bo);
qxl_bo_kunmap_atomic_page(qdev, *image_bo, ptr);
return 0;
}
int qxl_image_create(struct qxl_device *qdev,
struct qxl_release *release,
struct qxl_bo **image_bo,
const uint8_t *data,
int x, int y, int width, int height,
int depth, int stride)
{
data += y * stride + x * (depth / 8);
return qxl_image_create_helper(qdev, release, image_bo, data,
width, height, depth, 0, stride);
}
