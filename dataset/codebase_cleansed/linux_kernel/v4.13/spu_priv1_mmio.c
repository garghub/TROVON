static void int_mask_and(struct spu *spu, int class, u64 mask)
{
u64 old_mask;
old_mask = in_be64(&spu->priv1->int_mask_RW[class]);
out_be64(&spu->priv1->int_mask_RW[class], old_mask & mask);
}
static void int_mask_or(struct spu *spu, int class, u64 mask)
{
u64 old_mask;
old_mask = in_be64(&spu->priv1->int_mask_RW[class]);
out_be64(&spu->priv1->int_mask_RW[class], old_mask | mask);
}
static void int_mask_set(struct spu *spu, int class, u64 mask)
{
out_be64(&spu->priv1->int_mask_RW[class], mask);
}
static u64 int_mask_get(struct spu *spu, int class)
{
return in_be64(&spu->priv1->int_mask_RW[class]);
}
static void int_stat_clear(struct spu *spu, int class, u64 stat)
{
out_be64(&spu->priv1->int_stat_RW[class], stat);
}
static u64 int_stat_get(struct spu *spu, int class)
{
return in_be64(&spu->priv1->int_stat_RW[class]);
}
static void cpu_affinity_set(struct spu *spu, int cpu)
{
u64 target;
u64 route;
if (nr_cpus_node(spu->node)) {
const struct cpumask *spumask = cpumask_of_node(spu->node),
*cpumask = cpumask_of_node(cpu_to_node(cpu));
if (!cpumask_intersects(spumask, cpumask))
return;
}
target = iic_get_target_id(cpu);
route = target << 48 | target << 32 | target << 16;
out_be64(&spu->priv1->int_route_RW, route);
}
static u64 mfc_dar_get(struct spu *spu)
{
return in_be64(&spu->priv1->mfc_dar_RW);
}
static u64 mfc_dsisr_get(struct spu *spu)
{
return in_be64(&spu->priv1->mfc_dsisr_RW);
}
static void mfc_dsisr_set(struct spu *spu, u64 dsisr)
{
out_be64(&spu->priv1->mfc_dsisr_RW, dsisr);
}
static void mfc_sdr_setup(struct spu *spu)
{
out_be64(&spu->priv1->mfc_sdr_RW, mfspr(SPRN_SDR1));
}
static void mfc_sr1_set(struct spu *spu, u64 sr1)
{
out_be64(&spu->priv1->mfc_sr1_RW, sr1);
}
static u64 mfc_sr1_get(struct spu *spu)
{
return in_be64(&spu->priv1->mfc_sr1_RW);
}
static void mfc_tclass_id_set(struct spu *spu, u64 tclass_id)
{
out_be64(&spu->priv1->mfc_tclass_id_RW, tclass_id);
}
static u64 mfc_tclass_id_get(struct spu *spu)
{
return in_be64(&spu->priv1->mfc_tclass_id_RW);
}
static void tlb_invalidate(struct spu *spu)
{
out_be64(&spu->priv1->tlb_invalidate_entry_W, 0ul);
}
static void resource_allocation_groupID_set(struct spu *spu, u64 id)
{
out_be64(&spu->priv1->resource_allocation_groupID_RW, id);
}
static u64 resource_allocation_groupID_get(struct spu *spu)
{
return in_be64(&spu->priv1->resource_allocation_groupID_RW);
}
static void resource_allocation_enable_set(struct spu *spu, u64 enable)
{
out_be64(&spu->priv1->resource_allocation_enable_RW, enable);
}
static u64 resource_allocation_enable_get(struct spu *spu)
{
return in_be64(&spu->priv1->resource_allocation_enable_RW);
}
