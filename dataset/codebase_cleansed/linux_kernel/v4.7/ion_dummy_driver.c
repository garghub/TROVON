static int __init ion_dummy_init(void)
{
int i, err;
idev = ion_device_create(NULL);
if (IS_ERR(idev))
return PTR_ERR(idev);
heaps = kcalloc(dummy_ion_pdata.nr, sizeof(struct ion_heap *),
GFP_KERNEL);
if (!heaps)
return -ENOMEM;
carveout_ptr = alloc_pages_exact(
dummy_heaps[ION_HEAP_TYPE_CARVEOUT].size,
GFP_KERNEL);
if (carveout_ptr)
dummy_heaps[ION_HEAP_TYPE_CARVEOUT].base =
virt_to_phys(carveout_ptr);
else
pr_err("ion_dummy: Could not allocate carveout\n");
chunk_ptr = alloc_pages_exact(
dummy_heaps[ION_HEAP_TYPE_CHUNK].size,
GFP_KERNEL);
if (chunk_ptr)
dummy_heaps[ION_HEAP_TYPE_CHUNK].base = virt_to_phys(chunk_ptr);
else
pr_err("ion_dummy: Could not allocate chunk\n");
for (i = 0; i < dummy_ion_pdata.nr; i++) {
struct ion_platform_heap *heap_data = &dummy_ion_pdata.heaps[i];
if (heap_data->type == ION_HEAP_TYPE_CARVEOUT &&
!heap_data->base)
continue;
if (heap_data->type == ION_HEAP_TYPE_CHUNK && !heap_data->base)
continue;
heaps[i] = ion_heap_create(heap_data);
if (IS_ERR_OR_NULL(heaps[i])) {
err = PTR_ERR(heaps[i]);
goto err;
}
ion_device_add_heap(idev, heaps[i]);
}
return 0;
err:
for (i = 0; i < dummy_ion_pdata.nr; ++i)
ion_heap_destroy(heaps[i]);
kfree(heaps);
if (carveout_ptr) {
free_pages_exact(carveout_ptr,
dummy_heaps[ION_HEAP_TYPE_CARVEOUT].size);
carveout_ptr = NULL;
}
if (chunk_ptr) {
free_pages_exact(chunk_ptr,
dummy_heaps[ION_HEAP_TYPE_CHUNK].size);
chunk_ptr = NULL;
}
return err;
}
static void __exit ion_dummy_exit(void)
{
int i;
ion_device_destroy(idev);
for (i = 0; i < dummy_ion_pdata.nr; i++)
ion_heap_destroy(heaps[i]);
kfree(heaps);
if (carveout_ptr) {
free_pages_exact(carveout_ptr,
dummy_heaps[ION_HEAP_TYPE_CARVEOUT].size);
carveout_ptr = NULL;
}
if (chunk_ptr) {
free_pages_exact(chunk_ptr,
dummy_heaps[ION_HEAP_TYPE_CHUNK].size);
chunk_ptr = NULL;
}
}
