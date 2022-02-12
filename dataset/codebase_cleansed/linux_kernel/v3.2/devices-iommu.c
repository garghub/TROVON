static int __init msm8x60_iommu_init(void)
{
int ret, i;
ret = platform_device_register(&msm_root_iommu_dev);
if (ret != 0) {
pr_err("Failed to register root IOMMU device!\n");
goto failure;
}
for (i = 0; i < ARRAY_SIZE(msm_iommu_devs); i++) {
ret = platform_device_add_data(msm_iommu_devs[i],
msm_iommu_data[i],
sizeof(struct msm_iommu_dev));
if (ret != 0) {
pr_err("platform_device_add_data failed, "
"i = %d\n", i);
goto failure_unwind;
}
ret = platform_device_register(msm_iommu_devs[i]);
if (ret != 0) {
pr_err("platform_device_register iommu failed, "
"i = %d\n", i);
goto failure_unwind;
}
}
for (i = 0; i < ARRAY_SIZE(msm_iommu_ctx_devs); i++) {
ret = platform_device_add_data(msm_iommu_ctx_devs[i],
msm_iommu_ctx_data[i],
sizeof(*msm_iommu_ctx_devs[i]));
if (ret != 0) {
pr_err("platform_device_add_data iommu failed, "
"i = %d\n", i);
goto failure_unwind2;
}
ret = platform_device_register(msm_iommu_ctx_devs[i]);
if (ret != 0) {
pr_err("platform_device_register ctx failed, "
"i = %d\n", i);
goto failure_unwind2;
}
}
return 0;
failure_unwind2:
while (--i >= 0)
platform_device_unregister(msm_iommu_ctx_devs[i]);
failure_unwind:
while (--i >= 0)
platform_device_unregister(msm_iommu_devs[i]);
platform_device_unregister(&msm_root_iommu_dev);
failure:
return ret;
}
static void __exit msm8x60_iommu_exit(void)
{
int i;
for (i = 0; i < ARRAY_SIZE(msm_iommu_ctx_devs); i++)
platform_device_unregister(msm_iommu_ctx_devs[i]);
for (i = 0; i < ARRAY_SIZE(msm_iommu_devs); ++i)
platform_device_unregister(msm_iommu_devs[i]);
platform_device_unregister(&msm_root_iommu_dev);
}
