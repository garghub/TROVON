int uvd_v4_2_resume(struct radeon_device *rdev)
{
uint64_t addr;
uint32_t size;
addr = rdev->uvd.gpu_addr >> 3;
size = RADEON_GPU_PAGE_ALIGN(rdev->uvd_fw->size + 4) >> 3;
WREG32(UVD_VCPU_CACHE_OFFSET0, addr);
WREG32(UVD_VCPU_CACHE_SIZE0, size);
addr += size;
size = RADEON_UVD_STACK_SIZE >> 3;
WREG32(UVD_VCPU_CACHE_OFFSET1, addr);
WREG32(UVD_VCPU_CACHE_SIZE1, size);
addr += size;
size = RADEON_UVD_HEAP_SIZE >> 3;
WREG32(UVD_VCPU_CACHE_OFFSET2, addr);
WREG32(UVD_VCPU_CACHE_SIZE2, size);
addr = (rdev->uvd.gpu_addr >> 28) & 0xF;
WREG32(UVD_LMI_ADDR_EXT, (addr << 12) | (addr << 0));
addr = (rdev->uvd.gpu_addr >> 32) & 0xFF;
WREG32(UVD_LMI_EXT40_ADDR, addr | (0x9 << 16) | (0x1 << 31));
return 0;
}
