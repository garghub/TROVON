int pwc_decode_size(struct pwc_device *pdev, int width, int height)
{
int i, find;
if (pdev->pixfmt != V4L2_PIX_FMT_YUV420)
{
if (width > pdev->abs_max.x || height > pdev->abs_max.y)
{
PWC_DEBUG_SIZE("VIDEO_PALETTE_RAW: going beyond abs_max.\n");
return -1;
}
}
else
{
if (width > pdev->view_max.x || height > pdev->view_max.y)
{
PWC_DEBUG_SIZE("VIDEO_PALETTE_not RAW: going beyond view_max.\n");
return -1;
}
}
find = -1;
for (i = 0; i < PSZ_MAX; i++) {
if (pdev->image_mask & (1 << i)) {
if (pwc_image_sizes[i].x <= width && pwc_image_sizes[i].y <= height)
find = i;
}
}
return find;
}
void pwc_construct(struct pwc_device *pdev)
{
if (DEVICE_USE_CODEC1(pdev->type)) {
pdev->view_min.x = 128;
pdev->view_min.y = 96;
pdev->view_max.x = 352;
pdev->view_max.y = 288;
pdev->abs_max.x = 352;
pdev->abs_max.y = 288;
pdev->image_mask = 1 << PSZ_SQCIF | 1 << PSZ_QCIF | 1 << PSZ_CIF;
pdev->vcinterface = 2;
pdev->vendpoint = 4;
pdev->frame_header_size = 0;
pdev->frame_trailer_size = 0;
} else if (DEVICE_USE_CODEC3(pdev->type)) {
pdev->view_min.x = 160;
pdev->view_min.y = 120;
pdev->view_max.x = 640;
pdev->view_max.y = 480;
pdev->image_mask = 1 << PSZ_QSIF | 1 << PSZ_SIF | 1 << PSZ_VGA;
pdev->abs_max.x = 640;
pdev->abs_max.y = 480;
pdev->vcinterface = 3;
pdev->vendpoint = 5;
pdev->frame_header_size = TOUCAM_HEADER_SIZE;
pdev->frame_trailer_size = TOUCAM_TRAILER_SIZE;
} else {
pdev->view_min.x = 128;
pdev->view_min.y = 96;
pdev->view_max.x = 640;
pdev->view_max.y = 480;
pdev->image_mask = 1 << PSZ_SQCIF | 1 << PSZ_QSIF | 1 << PSZ_QCIF | 1 << PSZ_SIF | 1 << PSZ_CIF | 1 << PSZ_VGA;
pdev->abs_max.x = 640;
pdev->abs_max.y = 480;
pdev->vcinterface = 3;
pdev->vendpoint = 4;
pdev->frame_header_size = 0;
pdev->frame_trailer_size = 0;
}
pdev->pixfmt = V4L2_PIX_FMT_YUV420;
pdev->view_min.size = pdev->view_min.x * pdev->view_min.y;
pdev->view_max.size = pdev->view_max.x * pdev->view_max.y;
pdev->len_per_image = PAGE_ALIGN((pdev->abs_max.x * pdev->abs_max.y * 3) / 2);
}
