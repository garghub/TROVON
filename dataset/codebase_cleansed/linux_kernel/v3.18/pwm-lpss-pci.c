static int pwm_lpss_probe_pci(struct pci_dev *pdev,
const struct pci_device_id *id)
{
const struct pwm_lpss_boardinfo *info;
struct pwm_lpss_chip *lpwm;
int err;
err = pcim_enable_device(pdev);
if (err < 0)
return err;
info = (struct pwm_lpss_boardinfo *)id->driver_data;
lpwm = pwm_lpss_probe(&pdev->dev, &pdev->resource[0], info);
if (IS_ERR(lpwm))
return PTR_ERR(lpwm);
pci_set_drvdata(pdev, lpwm);
return 0;
}
static void pwm_lpss_remove_pci(struct pci_dev *pdev)
{
struct pwm_lpss_chip *lpwm = pci_get_drvdata(pdev);
pwm_lpss_remove(lpwm);
}
