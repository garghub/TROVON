void pwc_dec1_init(struct pwc_device *pdev, const unsigned char *cmd)
{
struct pwc_dec1_private *pdec = &pdev->dec1;
pdec->version = pdev->release;
}
