int pwc_decompress(struct pwc_device *pdev)
{
struct pwc_frame_buf *fbuf;
int n, line, col, stride;
void *yuv, *image;
u16 *src;
u16 *dsty, *dstu, *dstv;
if (pdev == NULL)
return -EFAULT;
fbuf = pdev->read_frame;
if (fbuf == NULL)
return -EFAULT;
image = pdev->image_data;
image += pdev->images[pdev->fill_image].offset;
yuv = fbuf->data + pdev->frame_header_size;
if (pdev->pixfmt != V4L2_PIX_FMT_YUV420)
{
struct pwc_raw_frame *raw_frame = image;
raw_frame->type = cpu_to_le16(pdev->type);
raw_frame->vbandlength = cpu_to_le16(pdev->vbandlength);
memcpy(raw_frame->cmd, pdev->cmd_buf, 4);
memcpy(raw_frame+1, yuv, pdev->frame_size);
return 0;
}
if (pdev->vbandlength == 0) {
src = (u16 *)yuv;
n = pdev->view.x * pdev->view.y;
stride = pdev->view.x * pdev->offset.y + pdev->offset.x;
dsty = (u16 *)(image + stride);
stride = pdev->view.x * pdev->offset.y / 4 + pdev->offset.x / 2;
dstu = (u16 *)(image + n + stride);
dstv = (u16 *)(image + n + n / 4 + stride);
stride = (pdev->view.x - pdev->image.x) / 2;
for (line = 0; line < pdev->image.y; line++) {
for (col = 0; col < pdev->image.x; col += 4) {
*dsty++ = *src++;
*dsty++ = *src++;
if (line & 1)
*dstv++ = *src++;
else
*dstu++ = *src++;
}
dsty += stride;
if (line & 1)
dstv += (stride >> 1);
else
dstu += (stride >> 1);
}
return 0;
}
if (pdev->vsize == PSZ_VGA && pdev->vframes == 5 && pdev->vsnapshot) {
PWC_ERROR("Mode Bayer is not supported for now\n");
return -ENXIO;
}
if (DEVICE_USE_CODEC1(pdev->type)) {
PWC_ERROR("This chipset is not supported for now\n");
return -ENXIO;
} else {
pwc_dec23_decompress(pdev, yuv, image, PWCX_FLAG_PLANAR);
}
return 0;
}
