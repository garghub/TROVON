static int cavium_rng_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct cavium_rng_pf *rng;
int iov_err;
rng = devm_kzalloc(&pdev->dev, sizeof(*rng), GFP_KERNEL);
if (!rng)
return -ENOMEM;
rng->control_status = pcim_iomap(pdev, 0, 0);
if (!rng->control_status) {
dev_err(&pdev->dev,
"Error iomap failed retrieving control_status.\n");
return -ENOMEM;
}
writeq(THUNDERX_RNM_RNG_EN | THUNDERX_RNM_ENT_EN,
rng->control_status);
pci_set_drvdata(pdev, rng);
iov_err = pci_enable_sriov(pdev, 1);
if (iov_err != 0) {
writeq(0, rng->control_status);
dev_err(&pdev->dev,
"Error initializing RNG virtual function,(%i).\n",
iov_err);
return iov_err;
}
return 0;
}
void cavium_rng_remove(struct pci_dev *pdev)
{
struct cavium_rng_pf *rng;
rng = pci_get_drvdata(pdev);
pci_disable_sriov(pdev);
writeq(0, rng->control_status);
}
