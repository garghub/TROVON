int pwc_get_size(struct pwc_device *pdev, int width, int height)
{
int i;
for (i = PSZ_MAX - 1; i >= 0; i--) {
if (!(pdev->image_mask & (1 << i)))
continue;
if (pwc_image_sizes[i][0] <= width &&
pwc_image_sizes[i][1] <= height)
return i;
}
for (i = 0; i < PSZ_MAX; i++) {
if (pdev->image_mask & (1 << i))
return i;
}
return 0;
}
void pwc_construct(struct pwc_device *pdev)
{
if (DEVICE_USE_CODEC1(pdev->type)) {
pdev->image_mask = 1 << PSZ_SQCIF | 1 << PSZ_QCIF | 1 << PSZ_CIF;
pdev->vcinterface = 2;
pdev->vendpoint = 4;
pdev->frame_header_size = 0;
pdev->frame_trailer_size = 0;
} else if (DEVICE_USE_CODEC3(pdev->type)) {
pdev->image_mask = 1 << PSZ_QSIF | 1 << PSZ_SIF | 1 << PSZ_VGA;
pdev->vcinterface = 3;
pdev->vendpoint = 5;
pdev->frame_header_size = TOUCAM_HEADER_SIZE;
pdev->frame_trailer_size = TOUCAM_TRAILER_SIZE;
} else {
pdev->image_mask = 1 << PSZ_SQCIF | 1 << PSZ_QSIF | 1 << PSZ_QCIF | 1 << PSZ_SIF | 1 << PSZ_CIF | 1 << PSZ_VGA;
pdev->vcinterface = 3;
pdev->vendpoint = 4;
pdev->frame_header_size = 0;
pdev->frame_trailer_size = 0;
}
}
