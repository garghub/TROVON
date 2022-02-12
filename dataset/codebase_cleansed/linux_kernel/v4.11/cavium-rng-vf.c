static int cavium_rng_read(struct hwrng *rng, void *dat, size_t max, bool wait)
{
struct cavium_rng *p = container_of(rng, struct cavium_rng, ops);
unsigned int size = max;
while (size >= 8) {
*((u64 *)dat) = readq(p->result);
size -= 8;
dat += 8;
}
while (size > 0) {
*((u8 *)dat) = readb(p->result);
size--;
dat++;
}
return max;
}
static int cavium_rng_probe_vf(struct pci_dev *pdev,
const struct pci_device_id *id)
{
struct cavium_rng *rng;
int ret;
rng = devm_kzalloc(&pdev->dev, sizeof(*rng), GFP_KERNEL);
if (!rng)
return -ENOMEM;
rng->result = pcim_iomap(pdev, 0, 0);
if (!rng->result) {
dev_err(&pdev->dev, "Error iomap failed retrieving result.\n");
return -ENOMEM;
}
rng->ops.name = devm_kasprintf(&pdev->dev, GFP_KERNEL,
"cavium-rng-%s", dev_name(&pdev->dev));
if (!rng->ops.name)
return -ENOMEM;
rng->ops.read = cavium_rng_read;
rng->ops.quality = 1000;
pci_set_drvdata(pdev, rng);
ret = hwrng_register(&rng->ops);
if (ret) {
dev_err(&pdev->dev, "Error registering device as HWRNG.\n");
return ret;
}
return 0;
}
void cavium_rng_remove_vf(struct pci_dev *pdev)
{
struct cavium_rng *rng;
rng = pci_get_drvdata(pdev);
hwrng_unregister(&rng->ops);
}
