static int radeon_benchmark_do_move(struct radeon_device *rdev, unsigned size,
uint64_t saddr, uint64_t daddr,
int flag, int n,
struct reservation_object *resv)
{
unsigned long start_jiffies;
unsigned long end_jiffies;
struct radeon_fence *fence = NULL;
int i, r;
start_jiffies = jiffies;
for (i = 0; i < n; i++) {
switch (flag) {
case RADEON_BENCHMARK_COPY_DMA:
fence = radeon_copy_dma(rdev, saddr, daddr,
size / RADEON_GPU_PAGE_SIZE,
resv);
break;
case RADEON_BENCHMARK_COPY_BLIT:
fence = radeon_copy_blit(rdev, saddr, daddr,
size / RADEON_GPU_PAGE_SIZE,
resv);
break;
default:
DRM_ERROR("Unknown copy method\n");
return -EINVAL;
}
if (IS_ERR(fence))
return PTR_ERR(fence);
r = radeon_fence_wait(fence, false);
radeon_fence_unref(&fence);
if (r)
return r;
}
end_jiffies = jiffies;
return jiffies_to_msecs(end_jiffies - start_jiffies);
}
static void radeon_benchmark_log_results(int n, unsigned size,
unsigned int time,
unsigned sdomain, unsigned ddomain,
char *kind)
{
unsigned int throughput = (n * (size >> 10)) / time;
DRM_INFO("radeon: %s %u bo moves of %u kB from"
" %d to %d in %u ms, throughput: %u Mb/s or %u MB/s\n",
kind, n, size >> 10, sdomain, ddomain, time,
throughput * 8, throughput);
}
static void radeon_benchmark_move(struct radeon_device *rdev, unsigned size,
unsigned sdomain, unsigned ddomain)
{
struct radeon_bo *dobj = NULL;
struct radeon_bo *sobj = NULL;
uint64_t saddr, daddr;
int r, n;
int time;
n = RADEON_BENCHMARK_ITERATIONS;
r = radeon_bo_create(rdev, size, PAGE_SIZE, true, sdomain, 0, NULL, NULL, &sobj);
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
r = radeon_bo_create(rdev, size, PAGE_SIZE, true, ddomain, 0, NULL, NULL, &dobj);
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
if (rdev->asic->copy.dma) {
time = radeon_benchmark_do_move(rdev, size, saddr, daddr,
RADEON_BENCHMARK_COPY_DMA, n,
dobj->tbo.resv);
if (time < 0)
goto out_cleanup;
if (time > 0)
radeon_benchmark_log_results(n, size, time,
sdomain, ddomain, "dma");
}
if (rdev->asic->copy.blit) {
time = radeon_benchmark_do_move(rdev, size, saddr, daddr,
RADEON_BENCHMARK_COPY_BLIT, n,
dobj->tbo.resv);
if (time < 0)
goto out_cleanup;
if (time > 0)
radeon_benchmark_log_results(n, size, time,
sdomain, ddomain, "blit");
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
if (r) {
DRM_ERROR("Error while benchmarking BO move.\n");
}
}
void radeon_benchmark(struct radeon_device *rdev, int test_number)
{
int i;
int common_modes[RADEON_BENCHMARK_COMMON_MODES_N] = {
640 * 480 * 4,
720 * 480 * 4,
800 * 600 * 4,
848 * 480 * 4,
1024 * 768 * 4,
1152 * 768 * 4,
1280 * 720 * 4,
1280 * 800 * 4,
1280 * 854 * 4,
1280 * 960 * 4,
1280 * 1024 * 4,
1440 * 900 * 4,
1400 * 1050 * 4,
1680 * 1050 * 4,
1600 * 1200 * 4,
1920 * 1080 * 4,
1920 * 1200 * 4
};
switch (test_number) {
case 1:
radeon_benchmark_move(rdev, 1024*1024, RADEON_GEM_DOMAIN_GTT,
RADEON_GEM_DOMAIN_VRAM);
radeon_benchmark_move(rdev, 1024*1024, RADEON_GEM_DOMAIN_VRAM,
RADEON_GEM_DOMAIN_GTT);
break;
case 2:
radeon_benchmark_move(rdev, 1024*1024, RADEON_GEM_DOMAIN_VRAM,
RADEON_GEM_DOMAIN_VRAM);
break;
case 3:
for (i = 1; i <= 16384; i <<= 1)
radeon_benchmark_move(rdev, i * RADEON_GPU_PAGE_SIZE,
RADEON_GEM_DOMAIN_GTT,
RADEON_GEM_DOMAIN_VRAM);
break;
case 4:
for (i = 1; i <= 16384; i <<= 1)
radeon_benchmark_move(rdev, i * RADEON_GPU_PAGE_SIZE,
RADEON_GEM_DOMAIN_VRAM,
RADEON_GEM_DOMAIN_GTT);
break;
case 5:
for (i = 1; i <= 16384; i <<= 1)
radeon_benchmark_move(rdev, i * RADEON_GPU_PAGE_SIZE,
RADEON_GEM_DOMAIN_VRAM,
RADEON_GEM_DOMAIN_VRAM);
break;
case 6:
for (i = 0; i < RADEON_BENCHMARK_COMMON_MODES_N; i++)
radeon_benchmark_move(rdev, common_modes[i],
RADEON_GEM_DOMAIN_GTT,
RADEON_GEM_DOMAIN_VRAM);
break;
case 7:
for (i = 0; i < RADEON_BENCHMARK_COMMON_MODES_N; i++)
radeon_benchmark_move(rdev, common_modes[i],
RADEON_GEM_DOMAIN_VRAM,
RADEON_GEM_DOMAIN_GTT);
break;
case 8:
for (i = 0; i < RADEON_BENCHMARK_COMMON_MODES_N; i++)
radeon_benchmark_move(rdev, common_modes[i],
RADEON_GEM_DOMAIN_VRAM,
RADEON_GEM_DOMAIN_VRAM);
break;
default:
DRM_ERROR("Unknown benchmark\n");
}
}
