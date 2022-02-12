static int ci_hdrc_zevio_probe(struct platform_device *pdev)
{
struct platform_device *ci_pdev;
dev_dbg(&pdev->dev, "ci_hdrc_zevio_probe\n");
ci_pdev = ci_hdrc_add_device(&pdev->dev,
pdev->resource, pdev->num_resources,
&ci_hdrc_zevio_platdata);
if (IS_ERR(ci_pdev)) {
dev_err(&pdev->dev, "ci_hdrc_add_device failed!\n");
return PTR_ERR(ci_pdev);
}
platform_set_drvdata(pdev, ci_pdev);
return 0;
}
static int ci_hdrc_zevio_remove(struct platform_device *pdev)
{
struct platform_device *ci_pdev = platform_get_drvdata(pdev);
ci_hdrc_remove_device(ci_pdev);
return 0;
}
