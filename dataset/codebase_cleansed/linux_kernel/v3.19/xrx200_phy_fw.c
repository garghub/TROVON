static dma_addr_t xway_gphy_load(struct platform_device *pdev)
{
const struct firmware *fw;
dma_addr_t dev_addr = 0;
const char *fw_name;
void *fw_addr;
size_t size;
if (of_get_property(pdev->dev.of_node, "firmware1", NULL) ||
of_get_property(pdev->dev.of_node, "firmware2", NULL)) {
switch (ltq_soc_type()) {
case SOC_TYPE_VR9:
if (of_property_read_string(pdev->dev.of_node,
"firmware1", &fw_name)) {
dev_err(&pdev->dev,
"failed to load firmware filename\n");
return 0;
}
break;
case SOC_TYPE_VR9_2:
if (of_property_read_string(pdev->dev.of_node,
"firmware2", &fw_name)) {
dev_err(&pdev->dev,
"failed to load firmware filename\n");
return 0;
}
break;
}
} else if (of_property_read_string(pdev->dev.of_node,
"firmware", &fw_name)) {
dev_err(&pdev->dev, "failed to load firmware filename\n");
return 0;
}
dev_info(&pdev->dev, "requesting %s\n", fw_name);
if (request_firmware(&fw, fw_name, &pdev->dev)) {
dev_err(&pdev->dev, "failed to load firmware: %s\n", fw_name);
return 0;
}
size = fw->size + XRX200_GPHY_FW_ALIGN;
fw_addr = dma_alloc_coherent(&pdev->dev, size, &dev_addr, GFP_KERNEL);
if (fw_addr) {
fw_addr = PTR_ALIGN(fw_addr, XRX200_GPHY_FW_ALIGN);
dev_addr = ALIGN(dev_addr, XRX200_GPHY_FW_ALIGN);
memcpy(fw_addr, fw->data, fw->size);
} else {
dev_err(&pdev->dev, "failed to alloc firmware memory\n");
}
release_firmware(fw);
return dev_addr;
}
static int xway_phy_fw_probe(struct platform_device *pdev)
{
dma_addr_t fw_addr;
struct property *pp;
unsigned char *phyids;
int i, ret = 0;
fw_addr = xway_gphy_load(pdev);
if (!fw_addr)
return -EINVAL;
pp = of_find_property(pdev->dev.of_node, "phys", NULL);
if (!pp)
return -ENOENT;
phyids = pp->value;
for (i = 0; i < pp->length && !ret; i++)
ret = xrx200_gphy_boot(&pdev->dev, phyids[i], fw_addr);
if (!ret)
mdelay(100);
return ret;
}
