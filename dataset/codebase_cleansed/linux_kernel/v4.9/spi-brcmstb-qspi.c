static int brcmstb_qspi_probe(struct platform_device *pdev)
{
return bcm_qspi_probe(pdev, NULL);
}
static int brcmstb_qspi_remove(struct platform_device *pdev)
{
return bcm_qspi_remove(pdev);
}
