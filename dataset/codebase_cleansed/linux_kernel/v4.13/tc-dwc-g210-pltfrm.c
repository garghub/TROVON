static int tc_dwc_g210_pltfm_probe(struct platform_device *pdev)
{
int err;
const struct of_device_id *of_id;
struct ufs_hba_variant_ops *vops;
struct device *dev = &pdev->dev;
of_id = of_match_node(tc_dwc_g210_pltfm_match, dev->of_node);
vops = (struct ufs_hba_variant_ops *)of_id->data;
err = ufshcd_pltfrm_init(pdev, vops);
if (err)
dev_err(dev, "ufshcd_pltfrm_init() failed %d\n", err);
return err;
}
static int tc_dwc_g210_pltfm_remove(struct platform_device *pdev)
{
struct ufs_hba *hba = platform_get_drvdata(pdev);
pm_runtime_get_sync(&(pdev)->dev);
ufshcd_remove(hba);
return 0;
}
