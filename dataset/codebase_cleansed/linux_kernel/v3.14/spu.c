static struct spu_pdata *spu_pdata(struct spu *spu)
{
return spu->pdata;
}
static void _dump_areas(unsigned int spe_id, unsigned long priv2,
unsigned long problem, unsigned long ls, unsigned long shadow,
const char* func, int line)
{
pr_debug("%s:%d: spe_id: %xh (%u)\n", func, line, spe_id, spe_id);
pr_debug("%s:%d: priv2: %lxh\n", func, line, priv2);
pr_debug("%s:%d: problem: %lxh\n", func, line, problem);
pr_debug("%s:%d: ls: %lxh\n", func, line, ls);
pr_debug("%s:%d: shadow: %lxh\n", func, line, shadow);
}
u64 ps3_get_spe_id(void *arg)
{
return spu_pdata(arg)->spe_id;
}
static unsigned long get_vas_id(void)
{
u64 id;
lv1_get_logical_ppe_id(&id);
lv1_get_virtual_address_space_id_of_ppe(&id);
return id;
}
static int __init construct_spu(struct spu *spu)
{
int result;
u64 unused;
u64 problem_phys;
u64 local_store_phys;
result = lv1_construct_logical_spe(PAGE_SHIFT, PAGE_SHIFT, PAGE_SHIFT,
PAGE_SHIFT, PAGE_SHIFT, get_vas_id(), SPE_TYPE_LOGICAL,
&spu_pdata(spu)->priv2_addr, &problem_phys,
&local_store_phys, &unused,
&spu_pdata(spu)->shadow_addr,
&spu_pdata(spu)->spe_id);
spu->problem_phys = problem_phys;
spu->local_store_phys = local_store_phys;
if (result) {
pr_debug("%s:%d: lv1_construct_logical_spe failed: %s\n",
__func__, __LINE__, ps3_result(result));
return result;
}
return result;
}
static void spu_unmap(struct spu *spu)
{
iounmap(spu->priv2);
iounmap(spu->problem);
iounmap((__force u8 __iomem *)spu->local_store);
iounmap(spu_pdata(spu)->shadow);
}
static int __init setup_areas(struct spu *spu)
{
struct table {char* name; unsigned long addr; unsigned long size;};
static const unsigned long shadow_flags = _PAGE_NO_CACHE | 3;
spu_pdata(spu)->shadow = __ioremap(spu_pdata(spu)->shadow_addr,
sizeof(struct spe_shadow),
shadow_flags);
if (!spu_pdata(spu)->shadow) {
pr_debug("%s:%d: ioremap shadow failed\n", __func__, __LINE__);
goto fail_ioremap;
}
spu->local_store = (__force void *)ioremap_prot(spu->local_store_phys,
LS_SIZE, _PAGE_NO_CACHE);
if (!spu->local_store) {
pr_debug("%s:%d: ioremap local_store failed\n",
__func__, __LINE__);
goto fail_ioremap;
}
spu->problem = ioremap(spu->problem_phys,
sizeof(struct spu_problem));
if (!spu->problem) {
pr_debug("%s:%d: ioremap problem failed\n", __func__, __LINE__);
goto fail_ioremap;
}
spu->priv2 = ioremap(spu_pdata(spu)->priv2_addr,
sizeof(struct spu_priv2));
if (!spu->priv2) {
pr_debug("%s:%d: ioremap priv2 failed\n", __func__, __LINE__);
goto fail_ioremap;
}
dump_areas(spu_pdata(spu)->spe_id, spu_pdata(spu)->priv2_addr,
spu->problem_phys, spu->local_store_phys,
spu_pdata(spu)->shadow_addr);
dump_areas(spu_pdata(spu)->spe_id, (unsigned long)spu->priv2,
(unsigned long)spu->problem, (unsigned long)spu->local_store,
(unsigned long)spu_pdata(spu)->shadow);
return 0;
fail_ioremap:
spu_unmap(spu);
return -ENOMEM;
}
static int __init setup_interrupts(struct spu *spu)
{
int result;
result = ps3_spe_irq_setup(PS3_BINDING_CPU_ANY, spu_pdata(spu)->spe_id,
0, &spu->irqs[0]);
if (result)
goto fail_alloc_0;
result = ps3_spe_irq_setup(PS3_BINDING_CPU_ANY, spu_pdata(spu)->spe_id,
1, &spu->irqs[1]);
if (result)
goto fail_alloc_1;
result = ps3_spe_irq_setup(PS3_BINDING_CPU_ANY, spu_pdata(spu)->spe_id,
2, &spu->irqs[2]);
if (result)
goto fail_alloc_2;
return result;
fail_alloc_2:
ps3_spe_irq_destroy(spu->irqs[1]);
fail_alloc_1:
ps3_spe_irq_destroy(spu->irqs[0]);
fail_alloc_0:
spu->irqs[0] = spu->irqs[1] = spu->irqs[2] = NO_IRQ;
return result;
}
static int __init enable_spu(struct spu *spu)
{
int result;
result = lv1_enable_logical_spe(spu_pdata(spu)->spe_id,
spu_pdata(spu)->resource_id);
if (result) {
pr_debug("%s:%d: lv1_enable_logical_spe failed: %s\n",
__func__, __LINE__, ps3_result(result));
goto fail_enable;
}
result = setup_areas(spu);
if (result)
goto fail_areas;
result = setup_interrupts(spu);
if (result)
goto fail_interrupts;
return 0;
fail_interrupts:
spu_unmap(spu);
fail_areas:
lv1_disable_logical_spe(spu_pdata(spu)->spe_id, 0);
fail_enable:
return result;
}
static int ps3_destroy_spu(struct spu *spu)
{
int result;
pr_debug("%s:%d spu_%d\n", __func__, __LINE__, spu->number);
result = lv1_disable_logical_spe(spu_pdata(spu)->spe_id, 0);
BUG_ON(result);
ps3_spe_irq_destroy(spu->irqs[2]);
ps3_spe_irq_destroy(spu->irqs[1]);
ps3_spe_irq_destroy(spu->irqs[0]);
spu->irqs[0] = spu->irqs[1] = spu->irqs[2] = NO_IRQ;
spu_unmap(spu);
result = lv1_destruct_logical_spe(spu_pdata(spu)->spe_id);
BUG_ON(result);
kfree(spu->pdata);
spu->pdata = NULL;
return 0;
}
static int __init ps3_create_spu(struct spu *spu, void *data)
{
int result;
pr_debug("%s:%d spu_%d\n", __func__, __LINE__, spu->number);
spu->pdata = kzalloc(sizeof(struct spu_pdata),
GFP_KERNEL);
if (!spu->pdata) {
result = -ENOMEM;
goto fail_malloc;
}
spu_pdata(spu)->resource_id = (unsigned long)data;
spu_pdata(spu)->cache.sr1 = 0x33;
result = construct_spu(spu);
if (result)
goto fail_construct;
result = enable_spu(spu);
if (result)
goto fail_enable;
while (in_be64(&spu_pdata(spu)->shadow->spe_execution_status)
!= SPE_EX_STATE_EXECUTED)
(void)0;
return result;
fail_enable:
fail_construct:
ps3_destroy_spu(spu);
fail_malloc:
return result;
}
static int __init ps3_enumerate_spus(int (*fn)(void *data))
{
int result;
unsigned int num_resource_id;
unsigned int i;
result = ps3_repository_read_num_spu_resource_id(&num_resource_id);
pr_debug("%s:%d: num_resource_id %u\n", __func__, __LINE__,
num_resource_id);
for (i = 0; i < num_resource_id; i++) {
enum ps3_spu_resource_type resource_type;
unsigned int resource_id;
result = ps3_repository_read_spu_resource_id(i,
&resource_type, &resource_id);
if (result)
break;
if (resource_type == PS3_SPU_RESOURCE_TYPE_EXCLUSIVE) {
result = fn((void*)(unsigned long)resource_id);
if (result)
break;
}
}
if (result) {
printk(KERN_WARNING "%s:%d: Error initializing spus\n",
__func__, __LINE__);
return result;
}
return num_resource_id;
}
static int ps3_init_affinity(void)
{
return 0;
}
static void ps3_enable_spu(struct spu_context *ctx)
{
}
static void ps3_disable_spu(struct spu_context *ctx)
{
ctx->ops->runcntl_stop(ctx);
}
static void int_mask_and(struct spu *spu, int class, u64 mask)
{
u64 old_mask;
old_mask = spu_int_mask_get(spu, class);
spu_int_mask_set(spu, class, old_mask & mask);
}
static void int_mask_or(struct spu *spu, int class, u64 mask)
{
u64 old_mask;
old_mask = spu_int_mask_get(spu, class);
spu_int_mask_set(spu, class, old_mask | mask);
}
static void int_mask_set(struct spu *spu, int class, u64 mask)
{
spu_pdata(spu)->cache.masks[class] = mask;
lv1_set_spe_interrupt_mask(spu_pdata(spu)->spe_id, class,
spu_pdata(spu)->cache.masks[class]);
}
static u64 int_mask_get(struct spu *spu, int class)
{
return spu_pdata(spu)->cache.masks[class];
}
static void int_stat_clear(struct spu *spu, int class, u64 stat)
{
lv1_clear_spe_interrupt_status(spu_pdata(spu)->spe_id, class,
stat, 0);
}
static u64 int_stat_get(struct spu *spu, int class)
{
u64 stat;
lv1_get_spe_interrupt_status(spu_pdata(spu)->spe_id, class, &stat);
return stat;
}
static void cpu_affinity_set(struct spu *spu, int cpu)
{
}
static u64 mfc_dar_get(struct spu *spu)
{
return in_be64(&spu_pdata(spu)->shadow->mfc_dar_RW);
}
static void mfc_dsisr_set(struct spu *spu, u64 dsisr)
{
}
static u64 mfc_dsisr_get(struct spu *spu)
{
return in_be64(&spu_pdata(spu)->shadow->mfc_dsisr_RW);
}
static void mfc_sdr_setup(struct spu *spu)
{
}
static void mfc_sr1_set(struct spu *spu, u64 sr1)
{
static const u64 allowed = ~(MFC_STATE1_LOCAL_STORAGE_DECODE_MASK
| MFC_STATE1_PROBLEM_STATE_MASK);
BUG_ON((sr1 & allowed) != (spu_pdata(spu)->cache.sr1 & allowed));
spu_pdata(spu)->cache.sr1 = sr1;
lv1_set_spe_privilege_state_area_1_register(
spu_pdata(spu)->spe_id,
offsetof(struct spu_priv1, mfc_sr1_RW),
spu_pdata(spu)->cache.sr1);
}
static u64 mfc_sr1_get(struct spu *spu)
{
return spu_pdata(spu)->cache.sr1;
}
static void mfc_tclass_id_set(struct spu *spu, u64 tclass_id)
{
spu_pdata(spu)->cache.tclass_id = tclass_id;
lv1_set_spe_privilege_state_area_1_register(
spu_pdata(spu)->spe_id,
offsetof(struct spu_priv1, mfc_tclass_id_RW),
spu_pdata(spu)->cache.tclass_id);
}
static u64 mfc_tclass_id_get(struct spu *spu)
{
return spu_pdata(spu)->cache.tclass_id;
}
static void tlb_invalidate(struct spu *spu)
{
}
static void resource_allocation_groupID_set(struct spu *spu, u64 id)
{
}
static u64 resource_allocation_groupID_get(struct spu *spu)
{
return 0;
}
static void resource_allocation_enable_set(struct spu *spu, u64 enable)
{
}
static u64 resource_allocation_enable_get(struct spu *spu)
{
return 0;
}
void ps3_spu_set_platform(void)
{
spu_priv1_ops = &spu_priv1_ps3_ops;
spu_management_ops = &spu_management_ps3_ops;
}
