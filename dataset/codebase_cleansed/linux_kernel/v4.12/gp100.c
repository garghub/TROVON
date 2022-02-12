static void
gp100_mc_intr_update(struct gp100_mc *mc)
{
struct nvkm_device *device = mc->base.subdev.device;
u32 mask = mc->intr ? mc->mask : 0, i;
for (i = 0; i < 2; i++) {
nvkm_wr32(device, 0x000180 + (i * 0x04), ~mask);
nvkm_wr32(device, 0x000160 + (i * 0x04), mask);
}
}
void
gp100_mc_intr_unarm(struct nvkm_mc *base)
{
struct gp100_mc *mc = gp100_mc(base);
unsigned long flags;
spin_lock_irqsave(&mc->lock, flags);
mc->intr = false;
gp100_mc_intr_update(mc);
spin_unlock_irqrestore(&mc->lock, flags);
}
void
gp100_mc_intr_rearm(struct nvkm_mc *base)
{
struct gp100_mc *mc = gp100_mc(base);
unsigned long flags;
spin_lock_irqsave(&mc->lock, flags);
mc->intr = true;
gp100_mc_intr_update(mc);
spin_unlock_irqrestore(&mc->lock, flags);
}
void
gp100_mc_intr_mask(struct nvkm_mc *base, u32 mask, u32 intr)
{
struct gp100_mc *mc = gp100_mc(base);
unsigned long flags;
spin_lock_irqsave(&mc->lock, flags);
mc->mask = (mc->mask & ~mask) | intr;
gp100_mc_intr_update(mc);
spin_unlock_irqrestore(&mc->lock, flags);
}
int
gp100_mc_new_(const struct nvkm_mc_func *func, struct nvkm_device *device,
int index, struct nvkm_mc **pmc)
{
struct gp100_mc *mc;
if (!(mc = kzalloc(sizeof(*mc), GFP_KERNEL)))
return -ENOMEM;
nvkm_mc_ctor(func, device, index, &mc->base);
*pmc = &mc->base;
spin_lock_init(&mc->lock);
mc->intr = false;
mc->mask = 0x7fffffff;
return 0;
}
int
gp100_mc_new(struct nvkm_device *device, int index, struct nvkm_mc **pmc)
{
return gp100_mc_new_(&gp100_mc, device, index, pmc);
}
