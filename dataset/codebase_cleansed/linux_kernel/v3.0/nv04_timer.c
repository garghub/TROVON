int
nv04_timer_init(struct drm_device *dev)
{
nv_wr32(dev, NV04_PTIMER_INTR_EN_0, 0x00000000);
nv_wr32(dev, NV04_PTIMER_INTR_0, 0xFFFFFFFF);
if (!nv_rd32(dev, NV04_PTIMER_NUMERATOR) ||
!nv_rd32(dev, NV04_PTIMER_DENOMINATOR)) {
nv_wr32(dev, NV04_PTIMER_NUMERATOR, 0x00000008);
nv_wr32(dev, NV04_PTIMER_DENOMINATOR, 0x00000003);
}
return 0;
}
uint64_t
nv04_timer_read(struct drm_device *dev)
{
uint32_t low;
uint32_t high2 = nv_rd32(dev, NV04_PTIMER_TIME_1);
uint32_t high1;
do {
high1 = high2;
low = nv_rd32(dev, NV04_PTIMER_TIME_0);
high2 = nv_rd32(dev, NV04_PTIMER_TIME_1);
} while (high1 != high2);
return (((uint64_t)high2) << 32) | (uint64_t)low;
}
void
nv04_timer_takedown(struct drm_device *dev)
{
}
