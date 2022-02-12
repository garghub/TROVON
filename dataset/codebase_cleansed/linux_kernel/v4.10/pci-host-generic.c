static int gen_pci_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
struct pci_ecam_ops *ops;
of_id = of_match_node(gen_pci_of_match, pdev->dev.of_node);
ops = (struct pci_ecam_ops *)of_id->data;
return pci_host_common_probe(pdev, ops);
}
