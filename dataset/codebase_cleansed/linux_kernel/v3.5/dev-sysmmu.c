static int __init init_sysmmu_platform_device(void)
{
int i, j;
struct sysmmu_resource_map *resmap[2] = {NULL, NULL};
int nmap[2] = {0, 0};
#ifdef CONFIG_ARCH_EXYNOS5
if (soc_is_exynos5250()) {
resmap[0] = sysmmu_resmap5;
nmap[0] = ARRAY_SIZE(sysmmu_resmap5);
nmap[1] = 0;
}
#endif
#ifdef CONFIG_ARCH_EXYNOS4
if (resmap[0] == NULL) {
resmap[0] = sysmmu_resmap4;
nmap[0] = ARRAY_SIZE(sysmmu_resmap4);
}
if (soc_is_exynos4210()) {
resmap[1] = sysmmu_resmap4210;
nmap[1] = ARRAY_SIZE(sysmmu_resmap4210);
}
if (soc_is_exynos4412() || soc_is_exynos4212()) {
resmap[1] = sysmmu_resmap4212;
nmap[1] = ARRAY_SIZE(sysmmu_resmap4212);
}
#endif
for (j = 0; j < 2; j++) {
for (i = 0; i < nmap[j]; i++) {
struct sysmmu_resource_map *map;
struct sysmmu_platform_data *platdata;
map = &resmap[j][i];
map->pdev->dev.parent = map->pdd;
platdata = map->pdev->dev.platform_data;
platdata->clockname = map->clocknames;
if (platform_device_add_resources(map->pdev, map->res,
map->rnum)) {
pr_err("%s: Failed to add device resources for "
"%s.%d\n", __func__,
map->pdev->name, map->pdev->id);
continue;
}
if (platform_device_register(map->pdev)) {
pr_err("%s: Failed to register %s.%d\n",
__func__, map->pdev->name,
map->pdev->id);
}
}
}
return 0;
}
