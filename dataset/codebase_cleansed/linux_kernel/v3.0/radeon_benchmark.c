void radeon_benchmark_move(struct radeon_device *rdev, unsigned bsize,
unsigned sdomain, unsigned ddomain)
{
struct radeon_bo *dobj = NULL;
struct radeon_bo *sobj = NULL;
struct radeon_fence *fence = NULL;
uint64_t saddr, daddr;
unsigned long start_jiffies;
unsigned long end_jiffies;
unsigned long time;
unsigned i, n, size;
int r;
size = bsize;
n = 1024;
r = radeon_bo_create(rdev, size, PAGE_SIZE, true, sdomain, &sobj);
if (r) {
goto out_cleanup;
}
r = radeon_bo_reserve(sobj, false);
if (unlikely(r != 0))
goto out_cleanup;
r = radeon_bo_pin(sobj, sdomain, &saddr);
radeon_bo_unreserve(sobj);
if (r) {
goto out_cleanup;
}
r = radeon_bo_create(rdev, size, PAGE_SIZE, true, ddomain, &dobj);
if (r) {
goto out_cleanup;
}
r = radeon_bo_reserve(dobj, false);
if (unlikely(r != 0))
goto out_cleanup;
r = radeon_bo_pin(dobj, ddomain, &daddr);
radeon_bo_unreserve(dobj);
if (r) {
goto out_cleanup;
}
if (rdev->asic->copy_dma) {
start_jiffies = jiffies;
for (i = 0; i < n; i++) {
r = radeon_fence_create(rdev, &fence);
if (r) {
goto out_cleanup;
}
r = radeon_copy_dma(rdev, saddr, daddr,
size / RADEON_GPU_PAGE_SIZE, fence);
if (r) {
goto out_cleanup;
}
r = radeon_fence_wait(fence, false);
if (r) {
goto out_cleanup;
}
radeon_fence_unref(&fence);
}
end_jiffies = jiffies;
time = end_jiffies - start_jiffies;
time = jiffies_to_msecs(time);
if (time > 0) {
i = ((n * size) >> 10) / time;
printk(KERN_INFO "radeon: dma %u bo moves of %ukb from"
" %d to %d in %lums (%ukb/ms %ukb/s %uM/s)\n",
n, size >> 10,
sdomain, ddomain, time,
i, i * 1000, (i * 1000) / 1024);
}
}
start_jiffies = jiffies;
for (i = 0; i < n; i++) {
r = radeon_fence_create(rdev, &fence);
if (r) {
goto out_cleanup;
}
r = radeon_copy_blit(rdev, saddr, daddr, size / RADEON_GPU_PAGE_SIZE, fence);
if (r) {
goto out_cleanup;
}
r = radeon_fence_wait(fence, false);
if (r) {
goto out_cleanup;
}
radeon_fence_unref(&fence);
}
end_jiffies = jiffies;
time = end_jiffies - start_jiffies;
time = jiffies_to_msecs(time);
if (time > 0) {
i = ((n * size) >> 10) / time;
printk(KERN_INFO "radeon: blit %u bo moves of %ukb from %d to %d"
" in %lums (%ukb/ms %ukb/s %uM/s)\n", n, size >> 10,
sdomain, ddomain, time, i, i * 1000, (i * 1000) / 1024);
}
out_cleanup:
if (sobj) {
r = radeon_bo_reserve(sobj, false);
if (likely(r == 0)) {
radeon_bo_unpin(sobj);
radeon_bo_unreserve(sobj);
}
radeon_bo_unref(&sobj);
}
if (dobj) {
r = radeon_bo_reserve(dobj, false);
if (likely(r == 0)) {
radeon_bo_unpin(dobj);
radeon_bo_unreserve(dobj);
}
radeon_bo_unref(&dobj);
}
if (fence) {
radeon_fence_unref(&fence);
}
if (r) {
printk(KERN_WARNING "Error while benchmarking BO move.\n");
}
}
void radeon_benchmark(struct radeon_device *rdev)
{
radeon_benchmark_move(rdev, 1024*1024, RADEON_GEM_DOMAIN_GTT,
RADEON_GEM_DOMAIN_VRAM);
radeon_benchmark_move(rdev, 1024*1024, RADEON_GEM_DOMAIN_VRAM,
RADEON_GEM_DOMAIN_GTT);
}
