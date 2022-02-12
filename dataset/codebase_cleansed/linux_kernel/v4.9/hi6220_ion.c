static int hi6220_ion_probe(struct platform_device *pdev)
{
struct hisi_ion_dev *ipdev;
int i;
ipdev = devm_kzalloc(&pdev->dev, sizeof(*ipdev), GFP_KERNEL);
if (!ipdev)
return -ENOMEM;
platform_set_drvdata(pdev, ipdev);
ipdev->idev = ion_device_create(NULL);
if (IS_ERR(ipdev->idev))
return PTR_ERR(ipdev->idev);
ipdev->data = ion_parse_dt(pdev, hisi_heaps);
if (IS_ERR(ipdev->data))
return PTR_ERR(ipdev->data);
ipdev->heaps = devm_kzalloc(&pdev->dev,
sizeof(struct ion_heap) * ipdev->data->nr,
GFP_KERNEL);
if (!ipdev->heaps) {
ion_destroy_platform_data(ipdev->data);
return -ENOMEM;
}
for (i = 0; i < ipdev->data->nr; i++) {
ipdev->heaps[i] = ion_heap_create(&ipdev->data->heaps[i]);
if (!ipdev->heaps) {
ion_destroy_platform_data(ipdev->data);
return -ENOMEM;
}
ion_device_add_heap(ipdev->idev, ipdev->heaps[i]);
}
return 0;
}
static int hi6220_ion_remove(struct platform_device *pdev)
{
struct hisi_ion_dev *ipdev;
int i;
ipdev = platform_get_drvdata(pdev);
for (i = 0; i < ipdev->data->nr; i++)
ion_heap_destroy(ipdev->heaps[i]);
ion_destroy_platform_data(ipdev->data);
ion_device_destroy(ipdev->idev);
return 0;
}
static int __init hi6220_ion_init(void)
{
return platform_driver_register(&hi6220_ion_driver);
}
