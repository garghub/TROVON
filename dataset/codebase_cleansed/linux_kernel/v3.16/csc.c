u32 read_reg(struct csc_data *csc, int offset)
{
return ioread32(csc->base + offset);
}
void csc_set_coeff_bypass(struct csc_data *csc, u32 *csc_reg5)
{
*csc_reg5 |= CSC_BYPASS;
}
void csc_set_coeff(struct csc_data *csc, u32 *csc_reg0,
enum v4l2_colorspace src_colorspace,
enum v4l2_colorspace dst_colorspace)
{
u32 *csc_reg5 = csc_reg0 + 5;
u32 *shadow_csc = csc_reg0;
struct colorspace_coeffs *sd_hd_coeffs;
u16 *coeff, *end_coeff;
enum v4l2_colorspace yuv_colorspace;
int sel = 0;
if (dst_colorspace == V4L2_COLORSPACE_SRGB &&
(src_colorspace == V4L2_COLORSPACE_SMPTE170M ||
src_colorspace == V4L2_COLORSPACE_REC709)) {
sel = 1;
yuv_colorspace = src_colorspace;
} else if ((dst_colorspace == V4L2_COLORSPACE_SMPTE170M ||
dst_colorspace == V4L2_COLORSPACE_REC709) &&
src_colorspace == V4L2_COLORSPACE_SRGB) {
sel = 3;
yuv_colorspace = dst_colorspace;
} else {
*csc_reg5 |= CSC_BYPASS;
return;
}
sd_hd_coeffs = &colorspace_coeffs[sel];
if (yuv_colorspace == V4L2_COLORSPACE_SMPTE170M)
coeff = sd_hd_coeffs->sd;
else
coeff = sd_hd_coeffs->hd;
end_coeff = coeff + 12;
for (; coeff < end_coeff; coeff += 2)
*shadow_csc++ = (*(coeff + 1) << 16) | *coeff;
}
struct csc_data *csc_create(struct platform_device *pdev)
{
struct csc_data *csc;
dev_dbg(&pdev->dev, "csc_create\n");
csc = devm_kzalloc(&pdev->dev, sizeof(*csc), GFP_KERNEL);
if (!csc) {
dev_err(&pdev->dev, "couldn't alloc csc_data\n");
return ERR_PTR(-ENOMEM);
}
csc->pdev = pdev;
csc->res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"csc");
if (csc->res == NULL) {
dev_err(&pdev->dev, "missing platform resources data\n");
return ERR_PTR(-ENODEV);
}
csc->base = devm_ioremap_resource(&pdev->dev, csc->res);
if (IS_ERR(csc->base)) {
dev_err(&pdev->dev, "failed to ioremap\n");
return csc->base;
}
return csc;
}
