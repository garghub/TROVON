static int ccu_reset_assert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct ccu_reset *ccu = rcdev_to_ccu_reset(rcdev);
const struct ccu_reset_map *map = &ccu->reset_map[id];
unsigned long flags;
u32 reg;
spin_lock_irqsave(ccu->lock, flags);
reg = readl(ccu->base + map->reg);
writel(reg & ~map->bit, ccu->base + map->reg);
spin_unlock_irqrestore(ccu->lock, flags);
return 0;
}
static int ccu_reset_deassert(struct reset_controller_dev *rcdev,
unsigned long id)
{
struct ccu_reset *ccu = rcdev_to_ccu_reset(rcdev);
const struct ccu_reset_map *map = &ccu->reset_map[id];
unsigned long flags;
u32 reg;
spin_lock_irqsave(ccu->lock, flags);
reg = readl(ccu->base + map->reg);
writel(reg | map->bit, ccu->base + map->reg);
spin_unlock_irqrestore(ccu->lock, flags);
return 0;
}
