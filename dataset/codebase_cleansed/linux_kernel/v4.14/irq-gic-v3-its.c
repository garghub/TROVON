static struct its_collection *dev_event_to_col(struct its_device *its_dev,
u32 event)
{
struct its_node *its = its_dev->its;
return its->collections + its_dev->event_map.col_map[event];
}
static void its_mask_encode(u64 *raw_cmd, u64 val, int h, int l)
{
u64 mask = GENMASK_ULL(h, l);
*raw_cmd &= ~mask;
*raw_cmd |= (val << l) & mask;
}
static void its_encode_cmd(struct its_cmd_block *cmd, u8 cmd_nr)
{
its_mask_encode(&cmd->raw_cmd[0], cmd_nr, 7, 0);
}
static void its_encode_devid(struct its_cmd_block *cmd, u32 devid)
{
its_mask_encode(&cmd->raw_cmd[0], devid, 63, 32);
}
static void its_encode_event_id(struct its_cmd_block *cmd, u32 id)
{
its_mask_encode(&cmd->raw_cmd[1], id, 31, 0);
}
static void its_encode_phys_id(struct its_cmd_block *cmd, u32 phys_id)
{
its_mask_encode(&cmd->raw_cmd[1], phys_id, 63, 32);
}
static void its_encode_size(struct its_cmd_block *cmd, u8 size)
{
its_mask_encode(&cmd->raw_cmd[1], size, 4, 0);
}
static void its_encode_itt(struct its_cmd_block *cmd, u64 itt_addr)
{
its_mask_encode(&cmd->raw_cmd[2], itt_addr >> 8, 51, 8);
}
static void its_encode_valid(struct its_cmd_block *cmd, int valid)
{
its_mask_encode(&cmd->raw_cmd[2], !!valid, 63, 63);
}
static void its_encode_target(struct its_cmd_block *cmd, u64 target_addr)
{
its_mask_encode(&cmd->raw_cmd[2], target_addr >> 16, 51, 16);
}
static void its_encode_collection(struct its_cmd_block *cmd, u16 col)
{
its_mask_encode(&cmd->raw_cmd[2], col, 15, 0);
}
static void its_encode_vpeid(struct its_cmd_block *cmd, u16 vpeid)
{
its_mask_encode(&cmd->raw_cmd[1], vpeid, 47, 32);
}
static void its_encode_virt_id(struct its_cmd_block *cmd, u32 virt_id)
{
its_mask_encode(&cmd->raw_cmd[2], virt_id, 31, 0);
}
static void its_encode_db_phys_id(struct its_cmd_block *cmd, u32 db_phys_id)
{
its_mask_encode(&cmd->raw_cmd[2], db_phys_id, 63, 32);
}
static void its_encode_db_valid(struct its_cmd_block *cmd, bool db_valid)
{
its_mask_encode(&cmd->raw_cmd[2], db_valid, 0, 0);
}
static void its_encode_seq_num(struct its_cmd_block *cmd, u16 seq_num)
{
its_mask_encode(&cmd->raw_cmd[0], seq_num, 47, 32);
}
static void its_encode_its_list(struct its_cmd_block *cmd, u16 its_list)
{
its_mask_encode(&cmd->raw_cmd[1], its_list, 15, 0);
}
static void its_encode_vpt_addr(struct its_cmd_block *cmd, u64 vpt_pa)
{
its_mask_encode(&cmd->raw_cmd[3], vpt_pa >> 16, 51, 16);
}
static void its_encode_vpt_size(struct its_cmd_block *cmd, u8 vpt_size)
{
its_mask_encode(&cmd->raw_cmd[3], vpt_size, 4, 0);
}
static inline void its_fixup_cmd(struct its_cmd_block *cmd)
{
cmd->raw_cmd[0] = cpu_to_le64(cmd->raw_cmd[0]);
cmd->raw_cmd[1] = cpu_to_le64(cmd->raw_cmd[1]);
cmd->raw_cmd[2] = cpu_to_le64(cmd->raw_cmd[2]);
cmd->raw_cmd[3] = cpu_to_le64(cmd->raw_cmd[3]);
}
static struct its_collection *its_build_mapd_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
unsigned long itt_addr;
u8 size = ilog2(desc->its_mapd_cmd.dev->nr_ites);
itt_addr = virt_to_phys(desc->its_mapd_cmd.dev->itt);
itt_addr = ALIGN(itt_addr, ITS_ITT_ALIGN);
its_encode_cmd(cmd, GITS_CMD_MAPD);
its_encode_devid(cmd, desc->its_mapd_cmd.dev->device_id);
its_encode_size(cmd, size - 1);
its_encode_itt(cmd, itt_addr);
its_encode_valid(cmd, desc->its_mapd_cmd.valid);
its_fixup_cmd(cmd);
return NULL;
}
static struct its_collection *its_build_mapc_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
its_encode_cmd(cmd, GITS_CMD_MAPC);
its_encode_collection(cmd, desc->its_mapc_cmd.col->col_id);
its_encode_target(cmd, desc->its_mapc_cmd.col->target_address);
its_encode_valid(cmd, desc->its_mapc_cmd.valid);
its_fixup_cmd(cmd);
return desc->its_mapc_cmd.col;
}
static struct its_collection *its_build_mapti_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
struct its_collection *col;
col = dev_event_to_col(desc->its_mapti_cmd.dev,
desc->its_mapti_cmd.event_id);
its_encode_cmd(cmd, GITS_CMD_MAPTI);
its_encode_devid(cmd, desc->its_mapti_cmd.dev->device_id);
its_encode_event_id(cmd, desc->its_mapti_cmd.event_id);
its_encode_phys_id(cmd, desc->its_mapti_cmd.phys_id);
its_encode_collection(cmd, col->col_id);
its_fixup_cmd(cmd);
return col;
}
static struct its_collection *its_build_movi_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
struct its_collection *col;
col = dev_event_to_col(desc->its_movi_cmd.dev,
desc->its_movi_cmd.event_id);
its_encode_cmd(cmd, GITS_CMD_MOVI);
its_encode_devid(cmd, desc->its_movi_cmd.dev->device_id);
its_encode_event_id(cmd, desc->its_movi_cmd.event_id);
its_encode_collection(cmd, desc->its_movi_cmd.col->col_id);
its_fixup_cmd(cmd);
return col;
}
static struct its_collection *its_build_discard_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
struct its_collection *col;
col = dev_event_to_col(desc->its_discard_cmd.dev,
desc->its_discard_cmd.event_id);
its_encode_cmd(cmd, GITS_CMD_DISCARD);
its_encode_devid(cmd, desc->its_discard_cmd.dev->device_id);
its_encode_event_id(cmd, desc->its_discard_cmd.event_id);
its_fixup_cmd(cmd);
return col;
}
static struct its_collection *its_build_inv_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
struct its_collection *col;
col = dev_event_to_col(desc->its_inv_cmd.dev,
desc->its_inv_cmd.event_id);
its_encode_cmd(cmd, GITS_CMD_INV);
its_encode_devid(cmd, desc->its_inv_cmd.dev->device_id);
its_encode_event_id(cmd, desc->its_inv_cmd.event_id);
its_fixup_cmd(cmd);
return col;
}
static struct its_collection *its_build_int_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
struct its_collection *col;
col = dev_event_to_col(desc->its_int_cmd.dev,
desc->its_int_cmd.event_id);
its_encode_cmd(cmd, GITS_CMD_INT);
its_encode_devid(cmd, desc->its_int_cmd.dev->device_id);
its_encode_event_id(cmd, desc->its_int_cmd.event_id);
its_fixup_cmd(cmd);
return col;
}
static struct its_collection *its_build_clear_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
struct its_collection *col;
col = dev_event_to_col(desc->its_clear_cmd.dev,
desc->its_clear_cmd.event_id);
its_encode_cmd(cmd, GITS_CMD_CLEAR);
its_encode_devid(cmd, desc->its_clear_cmd.dev->device_id);
its_encode_event_id(cmd, desc->its_clear_cmd.event_id);
its_fixup_cmd(cmd);
return col;
}
static struct its_collection *its_build_invall_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
its_encode_cmd(cmd, GITS_CMD_INVALL);
its_encode_collection(cmd, desc->its_mapc_cmd.col->col_id);
its_fixup_cmd(cmd);
return NULL;
}
static struct its_vpe *its_build_vinvall_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
its_encode_cmd(cmd, GITS_CMD_VINVALL);
its_encode_vpeid(cmd, desc->its_vinvall_cmd.vpe->vpe_id);
its_fixup_cmd(cmd);
return desc->its_vinvall_cmd.vpe;
}
static struct its_vpe *its_build_vmapp_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
unsigned long vpt_addr;
vpt_addr = virt_to_phys(page_address(desc->its_vmapp_cmd.vpe->vpt_page));
its_encode_cmd(cmd, GITS_CMD_VMAPP);
its_encode_vpeid(cmd, desc->its_vmapp_cmd.vpe->vpe_id);
its_encode_valid(cmd, desc->its_vmapp_cmd.valid);
its_encode_target(cmd, desc->its_vmapp_cmd.col->target_address);
its_encode_vpt_addr(cmd, vpt_addr);
its_encode_vpt_size(cmd, LPI_NRBITS - 1);
its_fixup_cmd(cmd);
return desc->its_vmapp_cmd.vpe;
}
static struct its_vpe *its_build_vmapti_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
u32 db;
if (desc->its_vmapti_cmd.db_enabled)
db = desc->its_vmapti_cmd.vpe->vpe_db_lpi;
else
db = 1023;
its_encode_cmd(cmd, GITS_CMD_VMAPTI);
its_encode_devid(cmd, desc->its_vmapti_cmd.dev->device_id);
its_encode_vpeid(cmd, desc->its_vmapti_cmd.vpe->vpe_id);
its_encode_event_id(cmd, desc->its_vmapti_cmd.event_id);
its_encode_db_phys_id(cmd, db);
its_encode_virt_id(cmd, desc->its_vmapti_cmd.virt_id);
its_fixup_cmd(cmd);
return desc->its_vmapti_cmd.vpe;
}
static struct its_vpe *its_build_vmovi_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
u32 db;
if (desc->its_vmovi_cmd.db_enabled)
db = desc->its_vmovi_cmd.vpe->vpe_db_lpi;
else
db = 1023;
its_encode_cmd(cmd, GITS_CMD_VMOVI);
its_encode_devid(cmd, desc->its_vmovi_cmd.dev->device_id);
its_encode_vpeid(cmd, desc->its_vmovi_cmd.vpe->vpe_id);
its_encode_event_id(cmd, desc->its_vmovi_cmd.event_id);
its_encode_db_phys_id(cmd, db);
its_encode_db_valid(cmd, true);
its_fixup_cmd(cmd);
return desc->its_vmovi_cmd.vpe;
}
static struct its_vpe *its_build_vmovp_cmd(struct its_cmd_block *cmd,
struct its_cmd_desc *desc)
{
its_encode_cmd(cmd, GITS_CMD_VMOVP);
its_encode_seq_num(cmd, desc->its_vmovp_cmd.seq_num);
its_encode_its_list(cmd, desc->its_vmovp_cmd.its_list);
its_encode_vpeid(cmd, desc->its_vmovp_cmd.vpe->vpe_id);
its_encode_target(cmd, desc->its_vmovp_cmd.col->target_address);
its_fixup_cmd(cmd);
return desc->its_vmovp_cmd.vpe;
}
static u64 its_cmd_ptr_to_offset(struct its_node *its,
struct its_cmd_block *ptr)
{
return (ptr - its->cmd_base) * sizeof(*ptr);
}
static int its_queue_full(struct its_node *its)
{
int widx;
int ridx;
widx = its->cmd_write - its->cmd_base;
ridx = readl_relaxed(its->base + GITS_CREADR) / sizeof(struct its_cmd_block);
if (((widx + 1) % ITS_CMD_QUEUE_NR_ENTRIES) == ridx)
return 1;
return 0;
}
static struct its_cmd_block *its_allocate_entry(struct its_node *its)
{
struct its_cmd_block *cmd;
u32 count = 1000000;
while (its_queue_full(its)) {
count--;
if (!count) {
pr_err_ratelimited("ITS queue not draining\n");
return NULL;
}
cpu_relax();
udelay(1);
}
cmd = its->cmd_write++;
if (its->cmd_write == (its->cmd_base + ITS_CMD_QUEUE_NR_ENTRIES))
its->cmd_write = its->cmd_base;
cmd->raw_cmd[0] = 0;
cmd->raw_cmd[1] = 0;
cmd->raw_cmd[2] = 0;
cmd->raw_cmd[3] = 0;
return cmd;
}
static struct its_cmd_block *its_post_commands(struct its_node *its)
{
u64 wr = its_cmd_ptr_to_offset(its, its->cmd_write);
writel_relaxed(wr, its->base + GITS_CWRITER);
return its->cmd_write;
}
static void its_flush_cmd(struct its_node *its, struct its_cmd_block *cmd)
{
if (its->flags & ITS_FLAGS_CMDQ_NEEDS_FLUSHING)
gic_flush_dcache_to_poc(cmd, sizeof(*cmd));
else
dsb(ishst);
}
static void its_wait_for_range_completion(struct its_node *its,
struct its_cmd_block *from,
struct its_cmd_block *to)
{
u64 rd_idx, from_idx, to_idx;
u32 count = 1000000;
from_idx = its_cmd_ptr_to_offset(its, from);
to_idx = its_cmd_ptr_to_offset(its, to);
while (1) {
rd_idx = readl_relaxed(its->base + GITS_CREADR);
if (from_idx < to_idx && rd_idx >= to_idx)
break;
if (from_idx >= to_idx && rd_idx >= to_idx && rd_idx < from_idx)
break;
count--;
if (!count) {
pr_err_ratelimited("ITS queue timeout\n");
return;
}
cpu_relax();
udelay(1);
}
}
static void its_build_sync_cmd(struct its_cmd_block *sync_cmd,
struct its_collection *sync_col)
{
its_encode_cmd(sync_cmd, GITS_CMD_SYNC);
its_encode_target(sync_cmd, sync_col->target_address);
its_fixup_cmd(sync_cmd);
}
void its_send_vmovp(struct its_vpe *vpe)
{
struct its_cmd_desc desc;
struct its_node *its;
unsigned long flags;
int col_id = vpe->col_idx;
desc.its_vmovp_cmd.vpe = vpe;
desc.its_vmovp_cmd.its_list = (u16)its_list_map;
if (!its_list_map) {
its = list_first_entry(&its_nodes, struct its_node, entry);
desc.its_vmovp_cmd.seq_num = 0;
desc.its_vmovp_cmd.col = &its->collections[col_id];
its_send_single_vcommand(its, its_build_vmovp_cmd, &desc);
return;
}
raw_spin_lock_irqsave(&vmovp_lock, flags);
desc.its_vmovp_cmd.seq_num = vmovp_seq_num++;
list_for_each_entry(its, &its_nodes, entry) {
if (!its->is_v4)
continue;
desc.its_vmovp_cmd.col = &its->collections[col_id];
its_send_single_vcommand(its, its_build_vmovp_cmd, &desc);
}
raw_spin_unlock_irqrestore(&vmovp_lock, flags);
}
static void its_send_vinvall(struct its_vpe *vpe)
{
struct its_cmd_desc desc;
struct its_node *its;
desc.its_vinvall_cmd.vpe = vpe;
list_for_each_entry(its, &its_nodes, entry) {
if (!its->is_v4)
continue;
its_send_single_vcommand(its, its_build_vinvall_cmd, &desc);
}
}
static inline u32 its_get_event_id(struct irq_data *d)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
return d->hwirq - its_dev->event_map.lpi_base;
}
static void lpi_write_config(struct irq_data *d, u8 clr, u8 set)
{
irq_hw_number_t hwirq;
struct page *prop_page;
u8 *cfg;
if (irqd_is_forwarded_to_vcpu(d)) {
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
u32 event = its_get_event_id(d);
prop_page = its_dev->event_map.vm->vprop_page;
hwirq = its_dev->event_map.vlpi_maps[event].vintid;
} else {
prop_page = gic_rdists->prop_page;
hwirq = d->hwirq;
}
cfg = page_address(prop_page) + hwirq - 8192;
*cfg &= ~clr;
*cfg |= set | LPI_PROP_GROUP1;
if (gic_rdists->flags & RDIST_FLAGS_PROPBASE_NEEDS_FLUSHING)
gic_flush_dcache_to_poc(cfg, sizeof(*cfg));
else
dsb(ishst);
}
static void lpi_update_config(struct irq_data *d, u8 clr, u8 set)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
lpi_write_config(d, clr, set);
its_send_inv(its_dev, its_get_event_id(d));
}
static void its_vlpi_set_doorbell(struct irq_data *d, bool enable)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
u32 event = its_get_event_id(d);
if (its_dev->event_map.vlpi_maps[event].db_enabled == enable)
return;
its_dev->event_map.vlpi_maps[event].db_enabled = enable;
its_send_vmovi(its_dev, event);
}
static void its_mask_irq(struct irq_data *d)
{
if (irqd_is_forwarded_to_vcpu(d))
its_vlpi_set_doorbell(d, false);
lpi_update_config(d, LPI_PROP_ENABLED, 0);
}
static void its_unmask_irq(struct irq_data *d)
{
if (irqd_is_forwarded_to_vcpu(d))
its_vlpi_set_doorbell(d, true);
lpi_update_config(d, 0, LPI_PROP_ENABLED);
}
static int its_set_affinity(struct irq_data *d, const struct cpumask *mask_val,
bool force)
{
unsigned int cpu;
const struct cpumask *cpu_mask = cpu_online_mask;
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
struct its_collection *target_col;
u32 id = its_get_event_id(d);
if (irqd_is_forwarded_to_vcpu(d))
return -EINVAL;
if (its_dev->its->flags & ITS_FLAGS_WORKAROUND_CAVIUM_23144) {
if (its_dev->its->numa_node >= 0) {
cpu_mask = cpumask_of_node(its_dev->its->numa_node);
if (!cpumask_intersects(mask_val, cpu_mask))
return -EINVAL;
}
}
cpu = cpumask_any_and(mask_val, cpu_mask);
if (cpu >= nr_cpu_ids)
return -EINVAL;
if (cpu != its_dev->event_map.col_map[id]) {
target_col = &its_dev->its->collections[cpu];
its_send_movi(its_dev, target_col, id);
its_dev->event_map.col_map[id] = cpu;
irq_data_update_effective_affinity(d, cpumask_of(cpu));
}
return IRQ_SET_MASK_OK_DONE;
}
static void its_irq_compose_msi_msg(struct irq_data *d, struct msi_msg *msg)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
struct its_node *its;
u64 addr;
its = its_dev->its;
addr = its->phys_base + GITS_TRANSLATER;
msg->address_lo = lower_32_bits(addr);
msg->address_hi = upper_32_bits(addr);
msg->data = its_get_event_id(d);
iommu_dma_map_msi_msg(d->irq, msg);
}
static int its_irq_set_irqchip_state(struct irq_data *d,
enum irqchip_irq_state which,
bool state)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
u32 event = its_get_event_id(d);
if (which != IRQCHIP_STATE_PENDING)
return -EINVAL;
if (state)
its_send_int(its_dev, event);
else
its_send_clear(its_dev, event);
return 0;
}
static int its_vlpi_map(struct irq_data *d, struct its_cmd_info *info)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
u32 event = its_get_event_id(d);
int ret = 0;
if (!info->map)
return -EINVAL;
mutex_lock(&its_dev->event_map.vlpi_lock);
if (!its_dev->event_map.vm) {
struct its_vlpi_map *maps;
maps = kzalloc(sizeof(*maps) * its_dev->event_map.nr_lpis,
GFP_KERNEL);
if (!maps) {
ret = -ENOMEM;
goto out;
}
its_dev->event_map.vm = info->map->vm;
its_dev->event_map.vlpi_maps = maps;
} else if (its_dev->event_map.vm != info->map->vm) {
ret = -EINVAL;
goto out;
}
its_dev->event_map.vlpi_maps[event] = *info->map;
if (irqd_is_forwarded_to_vcpu(d)) {
its_send_vmovi(its_dev, event);
} else {
its_send_discard(its_dev, event);
its_send_vmapti(its_dev, event);
irqd_set_forwarded_to_vcpu(d);
its_dev->event_map.nr_vlpis++;
}
out:
mutex_unlock(&its_dev->event_map.vlpi_lock);
return ret;
}
static int its_vlpi_get(struct irq_data *d, struct its_cmd_info *info)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
u32 event = its_get_event_id(d);
int ret = 0;
mutex_lock(&its_dev->event_map.vlpi_lock);
if (!its_dev->event_map.vm ||
!its_dev->event_map.vlpi_maps[event].vm) {
ret = -EINVAL;
goto out;
}
*info->map = its_dev->event_map.vlpi_maps[event];
out:
mutex_unlock(&its_dev->event_map.vlpi_lock);
return ret;
}
static int its_vlpi_unmap(struct irq_data *d)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
u32 event = its_get_event_id(d);
int ret = 0;
mutex_lock(&its_dev->event_map.vlpi_lock);
if (!its_dev->event_map.vm || !irqd_is_forwarded_to_vcpu(d)) {
ret = -EINVAL;
goto out;
}
its_send_discard(its_dev, event);
irqd_clr_forwarded_to_vcpu(d);
its_send_mapti(its_dev, d->hwirq, event);
lpi_update_config(d, 0xff, (LPI_PROP_DEFAULT_PRIO |
LPI_PROP_ENABLED |
LPI_PROP_GROUP1));
if (!--its_dev->event_map.nr_vlpis) {
its_dev->event_map.vm = NULL;
kfree(its_dev->event_map.vlpi_maps);
}
out:
mutex_unlock(&its_dev->event_map.vlpi_lock);
return ret;
}
static int its_vlpi_prop_update(struct irq_data *d, struct its_cmd_info *info)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
if (!its_dev->event_map.vm || !irqd_is_forwarded_to_vcpu(d))
return -EINVAL;
if (info->cmd_type == PROP_UPDATE_AND_INV_VLPI)
lpi_update_config(d, 0xff, info->config);
else
lpi_write_config(d, 0xff, info->config);
its_vlpi_set_doorbell(d, !!(info->config & LPI_PROP_ENABLED));
return 0;
}
static int its_irq_set_vcpu_affinity(struct irq_data *d, void *vcpu_info)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
struct its_cmd_info *info = vcpu_info;
if (!its_dev->its->is_v4)
return -EINVAL;
if (!info)
return its_vlpi_unmap(d);
switch (info->cmd_type) {
case MAP_VLPI:
return its_vlpi_map(d, info);
case GET_VLPI:
return its_vlpi_get(d, info);
case PROP_UPDATE_VLPI:
case PROP_UPDATE_AND_INV_VLPI:
return its_vlpi_prop_update(d, info);
default:
return -EINVAL;
}
}
static int its_lpi_to_chunk(int lpi)
{
return (lpi - 8192) >> IRQS_PER_CHUNK_SHIFT;
}
static int its_chunk_to_lpi(int chunk)
{
return (chunk << IRQS_PER_CHUNK_SHIFT) + 8192;
}
static int __init its_lpi_init(u32 id_bits)
{
lpi_chunks = its_lpi_to_chunk(1UL << id_bits);
lpi_bitmap = kzalloc(BITS_TO_LONGS(lpi_chunks) * sizeof(long),
GFP_KERNEL);
if (!lpi_bitmap) {
lpi_chunks = 0;
return -ENOMEM;
}
pr_info("ITS: Allocated %d chunks for LPIs\n", (int)lpi_chunks);
return 0;
}
static unsigned long *its_lpi_alloc_chunks(int nr_irqs, int *base, int *nr_ids)
{
unsigned long *bitmap = NULL;
int chunk_id;
int nr_chunks;
int i;
nr_chunks = DIV_ROUND_UP(nr_irqs, IRQS_PER_CHUNK);
spin_lock(&lpi_lock);
do {
chunk_id = bitmap_find_next_zero_area(lpi_bitmap, lpi_chunks,
0, nr_chunks, 0);
if (chunk_id < lpi_chunks)
break;
nr_chunks--;
} while (nr_chunks > 0);
if (!nr_chunks)
goto out;
bitmap = kzalloc(BITS_TO_LONGS(nr_chunks * IRQS_PER_CHUNK) * sizeof (long),
GFP_ATOMIC);
if (!bitmap)
goto out;
for (i = 0; i < nr_chunks; i++)
set_bit(chunk_id + i, lpi_bitmap);
*base = its_chunk_to_lpi(chunk_id);
*nr_ids = nr_chunks * IRQS_PER_CHUNK;
out:
spin_unlock(&lpi_lock);
if (!bitmap)
*base = *nr_ids = 0;
return bitmap;
}
static void its_lpi_free_chunks(unsigned long *bitmap, int base, int nr_ids)
{
int lpi;
spin_lock(&lpi_lock);
for (lpi = base; lpi < (base + nr_ids); lpi += IRQS_PER_CHUNK) {
int chunk = its_lpi_to_chunk(lpi);
BUG_ON(chunk > lpi_chunks);
if (test_bit(chunk, lpi_bitmap)) {
clear_bit(chunk, lpi_bitmap);
} else {
pr_err("Bad LPI chunk %d\n", chunk);
}
}
spin_unlock(&lpi_lock);
kfree(bitmap);
}
static struct page *its_allocate_prop_table(gfp_t gfp_flags)
{
struct page *prop_page;
prop_page = alloc_pages(gfp_flags, get_order(LPI_PROPBASE_SZ));
if (!prop_page)
return NULL;
memset(page_address(prop_page),
LPI_PROP_DEFAULT_PRIO | LPI_PROP_GROUP1,
LPI_PROPBASE_SZ);
gic_flush_dcache_to_poc(page_address(prop_page), LPI_PROPBASE_SZ);
return prop_page;
}
static void its_free_prop_table(struct page *prop_page)
{
free_pages((unsigned long)page_address(prop_page),
get_order(LPI_PROPBASE_SZ));
}
static int __init its_alloc_lpi_tables(void)
{
phys_addr_t paddr;
lpi_id_bits = min_t(u32, gic_rdists->id_bits, ITS_MAX_LPI_NRBITS);
gic_rdists->prop_page = its_allocate_prop_table(GFP_NOWAIT);
if (!gic_rdists->prop_page) {
pr_err("Failed to allocate PROPBASE\n");
return -ENOMEM;
}
paddr = page_to_phys(gic_rdists->prop_page);
pr_info("GIC: using LPI property table @%pa\n", &paddr);
return its_lpi_init(lpi_id_bits);
}
static u64 its_read_baser(struct its_node *its, struct its_baser *baser)
{
u32 idx = baser - its->tables;
return gits_read_baser(its->base + GITS_BASER + (idx << 3));
}
static void its_write_baser(struct its_node *its, struct its_baser *baser,
u64 val)
{
u32 idx = baser - its->tables;
gits_write_baser(val, its->base + GITS_BASER + (idx << 3));
baser->val = its_read_baser(its, baser);
}
static int its_setup_baser(struct its_node *its, struct its_baser *baser,
u64 cache, u64 shr, u32 psz, u32 order,
bool indirect)
{
u64 val = its_read_baser(its, baser);
u64 esz = GITS_BASER_ENTRY_SIZE(val);
u64 type = GITS_BASER_TYPE(val);
u64 baser_phys, tmp;
u32 alloc_pages;
void *base;
retry_alloc_baser:
alloc_pages = (PAGE_ORDER_TO_SIZE(order) / psz);
if (alloc_pages > GITS_BASER_PAGES_MAX) {
pr_warn("ITS@%pa: %s too large, reduce ITS pages %u->%u\n",
&its->phys_base, its_base_type_string[type],
alloc_pages, GITS_BASER_PAGES_MAX);
alloc_pages = GITS_BASER_PAGES_MAX;
order = get_order(GITS_BASER_PAGES_MAX * psz);
}
base = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO, order);
if (!base)
return -ENOMEM;
baser_phys = virt_to_phys(base);
if (IS_ENABLED(CONFIG_ARM64_64K_PAGES) && (baser_phys >> 48)) {
if (psz != SZ_64K) {
pr_err("ITS: no 52bit PA support when psz=%d\n", psz);
free_pages((unsigned long)base, order);
return -ENXIO;
}
baser_phys = GITS_BASER_PHYS_52_to_48(baser_phys);
}
retry_baser:
val = (baser_phys |
(type << GITS_BASER_TYPE_SHIFT) |
((esz - 1) << GITS_BASER_ENTRY_SIZE_SHIFT) |
((alloc_pages - 1) << GITS_BASER_PAGES_SHIFT) |
cache |
shr |
GITS_BASER_VALID);
val |= indirect ? GITS_BASER_INDIRECT : 0x0;
switch (psz) {
case SZ_4K:
val |= GITS_BASER_PAGE_SIZE_4K;
break;
case SZ_16K:
val |= GITS_BASER_PAGE_SIZE_16K;
break;
case SZ_64K:
val |= GITS_BASER_PAGE_SIZE_64K;
break;
}
its_write_baser(its, baser, val);
tmp = baser->val;
if ((val ^ tmp) & GITS_BASER_SHAREABILITY_MASK) {
shr = tmp & GITS_BASER_SHAREABILITY_MASK;
if (!shr) {
cache = GITS_BASER_nC;
gic_flush_dcache_to_poc(base, PAGE_ORDER_TO_SIZE(order));
}
goto retry_baser;
}
if ((val ^ tmp) & GITS_BASER_PAGE_SIZE_MASK) {
free_pages((unsigned long)base, order);
baser->base = NULL;
switch (psz) {
case SZ_16K:
psz = SZ_4K;
goto retry_alloc_baser;
case SZ_64K:
psz = SZ_16K;
goto retry_alloc_baser;
}
}
if (val != tmp) {
pr_err("ITS@%pa: %s doesn't stick: %llx %llx\n",
&its->phys_base, its_base_type_string[type],
val, tmp);
free_pages((unsigned long)base, order);
return -ENXIO;
}
baser->order = order;
baser->base = base;
baser->psz = psz;
tmp = indirect ? GITS_LVL1_ENTRY_SIZE : esz;
pr_info("ITS@%pa: allocated %d %s @%lx (%s, esz %d, psz %dK, shr %d)\n",
&its->phys_base, (int)(PAGE_ORDER_TO_SIZE(order) / (int)tmp),
its_base_type_string[type],
(unsigned long)virt_to_phys(base),
indirect ? "indirect" : "flat", (int)esz,
psz / SZ_1K, (int)shr >> GITS_BASER_SHAREABILITY_SHIFT);
return 0;
}
static bool its_parse_indirect_baser(struct its_node *its,
struct its_baser *baser,
u32 psz, u32 *order, u32 ids)
{
u64 tmp = its_read_baser(its, baser);
u64 type = GITS_BASER_TYPE(tmp);
u64 esz = GITS_BASER_ENTRY_SIZE(tmp);
u64 val = GITS_BASER_InnerShareable | GITS_BASER_RaWaWb;
u32 new_order = *order;
bool indirect = false;
if ((esz << ids) > (psz * 2)) {
its_write_baser(its, baser, val | GITS_BASER_INDIRECT);
indirect = !!(baser->val & GITS_BASER_INDIRECT);
if (indirect) {
ids -= ilog2(psz / (int)esz);
esz = GITS_LVL1_ENTRY_SIZE;
}
}
new_order = max_t(u32, get_order(esz << ids), new_order);
if (new_order >= MAX_ORDER) {
new_order = MAX_ORDER - 1;
ids = ilog2(PAGE_ORDER_TO_SIZE(new_order) / (int)esz);
pr_warn("ITS@%pa: %s Table too large, reduce ids %u->%u\n",
&its->phys_base, its_base_type_string[type],
its->device_ids, ids);
}
*order = new_order;
return indirect;
}
static void its_free_tables(struct its_node *its)
{
int i;
for (i = 0; i < GITS_BASER_NR_REGS; i++) {
if (its->tables[i].base) {
free_pages((unsigned long)its->tables[i].base,
its->tables[i].order);
its->tables[i].base = NULL;
}
}
}
static int its_alloc_tables(struct its_node *its)
{
u64 typer = gic_read_typer(its->base + GITS_TYPER);
u32 ids = GITS_TYPER_DEVBITS(typer);
u64 shr = GITS_BASER_InnerShareable;
u64 cache = GITS_BASER_RaWaWb;
u32 psz = SZ_64K;
int err, i;
if (its->flags & ITS_FLAGS_WORKAROUND_CAVIUM_22375) {
cache = GITS_BASER_nCnB;
ids = 0x14;
}
its->device_ids = ids;
for (i = 0; i < GITS_BASER_NR_REGS; i++) {
struct its_baser *baser = its->tables + i;
u64 val = its_read_baser(its, baser);
u64 type = GITS_BASER_TYPE(val);
u32 order = get_order(psz);
bool indirect = false;
switch (type) {
case GITS_BASER_TYPE_NONE:
continue;
case GITS_BASER_TYPE_DEVICE:
indirect = its_parse_indirect_baser(its, baser,
psz, &order,
its->device_ids);
case GITS_BASER_TYPE_VCPU:
indirect = its_parse_indirect_baser(its, baser,
psz, &order,
ITS_MAX_VPEID_BITS);
break;
}
err = its_setup_baser(its, baser, cache, shr, psz, order, indirect);
if (err < 0) {
its_free_tables(its);
return err;
}
psz = baser->psz;
cache = baser->val & GITS_BASER_CACHEABILITY_MASK;
shr = baser->val & GITS_BASER_SHAREABILITY_MASK;
}
return 0;
}
static int its_alloc_collections(struct its_node *its)
{
its->collections = kzalloc(nr_cpu_ids * sizeof(*its->collections),
GFP_KERNEL);
if (!its->collections)
return -ENOMEM;
return 0;
}
static struct page *its_allocate_pending_table(gfp_t gfp_flags)
{
struct page *pend_page;
pend_page = alloc_pages(gfp_flags | __GFP_ZERO,
get_order(max_t(u32, LPI_PENDBASE_SZ, SZ_64K)));
if (!pend_page)
return NULL;
gic_flush_dcache_to_poc(page_address(pend_page), LPI_PENDBASE_SZ);
return pend_page;
}
static void its_free_pending_table(struct page *pt)
{
free_pages((unsigned long)page_address(pt),
get_order(max_t(u32, LPI_PENDBASE_SZ, SZ_64K)));
}
static void its_cpu_init_lpis(void)
{
void __iomem *rbase = gic_data_rdist_rd_base();
struct page *pend_page;
u64 val, tmp;
pend_page = gic_data_rdist()->pend_page;
if (!pend_page) {
phys_addr_t paddr;
pend_page = its_allocate_pending_table(GFP_NOWAIT);
if (!pend_page) {
pr_err("Failed to allocate PENDBASE for CPU%d\n",
smp_processor_id());
return;
}
paddr = page_to_phys(pend_page);
pr_info("CPU%d: using LPI pending table @%pa\n",
smp_processor_id(), &paddr);
gic_data_rdist()->pend_page = pend_page;
}
val = readl_relaxed(rbase + GICR_CTLR);
val &= ~GICR_CTLR_ENABLE_LPIS;
writel_relaxed(val, rbase + GICR_CTLR);
dsb(sy);
val = (page_to_phys(gic_rdists->prop_page) |
GICR_PROPBASER_InnerShareable |
GICR_PROPBASER_RaWaWb |
((LPI_NRBITS - 1) & GICR_PROPBASER_IDBITS_MASK));
gicr_write_propbaser(val, rbase + GICR_PROPBASER);
tmp = gicr_read_propbaser(rbase + GICR_PROPBASER);
if ((tmp ^ val) & GICR_PROPBASER_SHAREABILITY_MASK) {
if (!(tmp & GICR_PROPBASER_SHAREABILITY_MASK)) {
val &= ~(GICR_PROPBASER_SHAREABILITY_MASK |
GICR_PROPBASER_CACHEABILITY_MASK);
val |= GICR_PROPBASER_nC;
gicr_write_propbaser(val, rbase + GICR_PROPBASER);
}
pr_info_once("GIC: using cache flushing for LPI property table\n");
gic_rdists->flags |= RDIST_FLAGS_PROPBASE_NEEDS_FLUSHING;
}
val = (page_to_phys(pend_page) |
GICR_PENDBASER_InnerShareable |
GICR_PENDBASER_RaWaWb);
gicr_write_pendbaser(val, rbase + GICR_PENDBASER);
tmp = gicr_read_pendbaser(rbase + GICR_PENDBASER);
if (!(tmp & GICR_PENDBASER_SHAREABILITY_MASK)) {
val &= ~(GICR_PENDBASER_SHAREABILITY_MASK |
GICR_PENDBASER_CACHEABILITY_MASK);
val |= GICR_PENDBASER_nC;
gicr_write_pendbaser(val, rbase + GICR_PENDBASER);
}
val = readl_relaxed(rbase + GICR_CTLR);
val |= GICR_CTLR_ENABLE_LPIS;
writel_relaxed(val, rbase + GICR_CTLR);
dsb(sy);
}
static void its_cpu_init_collection(void)
{
struct its_node *its;
int cpu;
spin_lock(&its_lock);
cpu = smp_processor_id();
list_for_each_entry(its, &its_nodes, entry) {
u64 target;
if (its->flags & ITS_FLAGS_WORKAROUND_CAVIUM_23144) {
struct device_node *cpu_node;
cpu_node = of_get_cpu_node(cpu, NULL);
if (its->numa_node != NUMA_NO_NODE &&
its->numa_node != of_node_to_nid(cpu_node))
continue;
}
if (gic_read_typer(its->base + GITS_TYPER) & GITS_TYPER_PTA) {
target = gic_data_rdist()->phys_base;
} else {
target = gic_read_typer(gic_data_rdist_rd_base() + GICR_TYPER);
target = GICR_TYPER_CPU_NUMBER(target) << 16;
}
its->collections[cpu].target_address = target;
its->collections[cpu].col_id = cpu;
its_send_mapc(its, &its->collections[cpu], 1);
its_send_invall(its, &its->collections[cpu]);
}
spin_unlock(&its_lock);
}
static struct its_device *its_find_device(struct its_node *its, u32 dev_id)
{
struct its_device *its_dev = NULL, *tmp;
unsigned long flags;
raw_spin_lock_irqsave(&its->lock, flags);
list_for_each_entry(tmp, &its->its_device_list, entry) {
if (tmp->device_id == dev_id) {
its_dev = tmp;
break;
}
}
raw_spin_unlock_irqrestore(&its->lock, flags);
return its_dev;
}
static struct its_baser *its_get_baser(struct its_node *its, u32 type)
{
int i;
for (i = 0; i < GITS_BASER_NR_REGS; i++) {
if (GITS_BASER_TYPE(its->tables[i].val) == type)
return &its->tables[i];
}
return NULL;
}
static bool its_alloc_table_entry(struct its_baser *baser, u32 id)
{
struct page *page;
u32 esz, idx;
__le64 *table;
esz = GITS_BASER_ENTRY_SIZE(baser->val);
if (!(baser->val & GITS_BASER_INDIRECT))
return (id < (PAGE_ORDER_TO_SIZE(baser->order) / esz));
idx = id >> ilog2(baser->psz / esz);
if (idx >= (PAGE_ORDER_TO_SIZE(baser->order) / GITS_LVL1_ENTRY_SIZE))
return false;
table = baser->base;
if (!table[idx]) {
page = alloc_pages(GFP_KERNEL | __GFP_ZERO, get_order(baser->psz));
if (!page)
return false;
if (!(baser->val & GITS_BASER_SHAREABILITY_MASK))
gic_flush_dcache_to_poc(page_address(page), baser->psz);
table[idx] = cpu_to_le64(page_to_phys(page) | GITS_BASER_VALID);
if (!(baser->val & GITS_BASER_SHAREABILITY_MASK))
gic_flush_dcache_to_poc(table + idx, GITS_LVL1_ENTRY_SIZE);
dsb(sy);
}
return true;
}
static bool its_alloc_device_table(struct its_node *its, u32 dev_id)
{
struct its_baser *baser;
baser = its_get_baser(its, GITS_BASER_TYPE_DEVICE);
if (!baser)
return (ilog2(dev_id) < its->device_ids);
return its_alloc_table_entry(baser, dev_id);
}
static bool its_alloc_vpe_table(u32 vpe_id)
{
struct its_node *its;
list_for_each_entry(its, &its_nodes, entry) {
struct its_baser *baser;
if (!its->is_v4)
continue;
baser = its_get_baser(its, GITS_BASER_TYPE_VCPU);
if (!baser)
return false;
if (!its_alloc_table_entry(baser, vpe_id))
return false;
}
return true;
}
static struct its_device *its_create_device(struct its_node *its, u32 dev_id,
int nvecs, bool alloc_lpis)
{
struct its_device *dev;
unsigned long *lpi_map = NULL;
unsigned long flags;
u16 *col_map = NULL;
void *itt;
int lpi_base;
int nr_lpis;
int nr_ites;
int sz;
if (!its_alloc_device_table(its, dev_id))
return NULL;
dev = kzalloc(sizeof(*dev), GFP_KERNEL);
nr_ites = max(2UL, roundup_pow_of_two(nvecs));
sz = nr_ites * its->ite_size;
sz = max(sz, ITS_ITT_ALIGN) + ITS_ITT_ALIGN - 1;
itt = kzalloc(sz, GFP_KERNEL);
if (alloc_lpis) {
lpi_map = its_lpi_alloc_chunks(nvecs, &lpi_base, &nr_lpis);
if (lpi_map)
col_map = kzalloc(sizeof(*col_map) * nr_lpis,
GFP_KERNEL);
} else {
col_map = kzalloc(sizeof(*col_map) * nr_ites, GFP_KERNEL);
nr_lpis = 0;
lpi_base = 0;
}
if (!dev || !itt || !col_map || (!lpi_map && alloc_lpis)) {
kfree(dev);
kfree(itt);
kfree(lpi_map);
kfree(col_map);
return NULL;
}
gic_flush_dcache_to_poc(itt, sz);
dev->its = its;
dev->itt = itt;
dev->nr_ites = nr_ites;
dev->event_map.lpi_map = lpi_map;
dev->event_map.col_map = col_map;
dev->event_map.lpi_base = lpi_base;
dev->event_map.nr_lpis = nr_lpis;
mutex_init(&dev->event_map.vlpi_lock);
dev->device_id = dev_id;
INIT_LIST_HEAD(&dev->entry);
raw_spin_lock_irqsave(&its->lock, flags);
list_add(&dev->entry, &its->its_device_list);
raw_spin_unlock_irqrestore(&its->lock, flags);
its_send_mapd(dev, 1);
return dev;
}
static void its_free_device(struct its_device *its_dev)
{
unsigned long flags;
raw_spin_lock_irqsave(&its_dev->its->lock, flags);
list_del(&its_dev->entry);
raw_spin_unlock_irqrestore(&its_dev->its->lock, flags);
kfree(its_dev->itt);
kfree(its_dev);
}
static int its_alloc_device_irq(struct its_device *dev, irq_hw_number_t *hwirq)
{
int idx;
idx = find_first_zero_bit(dev->event_map.lpi_map,
dev->event_map.nr_lpis);
if (idx == dev->event_map.nr_lpis)
return -ENOSPC;
*hwirq = dev->event_map.lpi_base + idx;
set_bit(idx, dev->event_map.lpi_map);
return 0;
}
static int its_msi_prepare(struct irq_domain *domain, struct device *dev,
int nvec, msi_alloc_info_t *info)
{
struct its_node *its;
struct its_device *its_dev;
struct msi_domain_info *msi_info;
u32 dev_id;
dev_id = info->scratchpad[0].ul;
msi_info = msi_get_domain_info(domain);
its = msi_info->data;
if (!gic_rdists->has_direct_lpi &&
vpe_proxy.dev &&
vpe_proxy.dev->its == its &&
dev_id == vpe_proxy.dev->device_id) {
WARN_ONCE(1, "DevId %x clashes with GICv4 VPE proxy device\n",
dev_id);
return -EINVAL;
}
its_dev = its_find_device(its, dev_id);
if (its_dev) {
pr_debug("Reusing ITT for devID %x\n", dev_id);
goto out;
}
its_dev = its_create_device(its, dev_id, nvec, true);
if (!its_dev)
return -ENOMEM;
pr_debug("ITT %d entries, %d bits\n", nvec, ilog2(nvec));
out:
info->scratchpad[0].ptr = its_dev;
return 0;
}
static int its_irq_gic_domain_alloc(struct irq_domain *domain,
unsigned int virq,
irq_hw_number_t hwirq)
{
struct irq_fwspec fwspec;
if (irq_domain_get_of_node(domain->parent)) {
fwspec.fwnode = domain->parent->fwnode;
fwspec.param_count = 3;
fwspec.param[0] = GIC_IRQ_TYPE_LPI;
fwspec.param[1] = hwirq;
fwspec.param[2] = IRQ_TYPE_EDGE_RISING;
} else if (is_fwnode_irqchip(domain->parent->fwnode)) {
fwspec.fwnode = domain->parent->fwnode;
fwspec.param_count = 2;
fwspec.param[0] = hwirq;
fwspec.param[1] = IRQ_TYPE_EDGE_RISING;
} else {
return -EINVAL;
}
return irq_domain_alloc_irqs_parent(domain, virq, 1, &fwspec);
}
static int its_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *args)
{
msi_alloc_info_t *info = args;
struct its_device *its_dev = info->scratchpad[0].ptr;
irq_hw_number_t hwirq;
int err;
int i;
for (i = 0; i < nr_irqs; i++) {
err = its_alloc_device_irq(its_dev, &hwirq);
if (err)
return err;
err = its_irq_gic_domain_alloc(domain, virq + i, hwirq);
if (err)
return err;
irq_domain_set_hwirq_and_chip(domain, virq + i,
hwirq, &its_irq_chip, its_dev);
irqd_set_single_target(irq_desc_get_irq_data(irq_to_desc(virq + i)));
pr_debug("ID:%d pID:%d vID:%d\n",
(int)(hwirq - its_dev->event_map.lpi_base),
(int) hwirq, virq + i);
}
return 0;
}
static void its_irq_domain_activate(struct irq_domain *domain,
struct irq_data *d)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
u32 event = its_get_event_id(d);
const struct cpumask *cpu_mask = cpu_online_mask;
int cpu;
if (its_dev->its->numa_node >= 0)
cpu_mask = cpumask_of_node(its_dev->its->numa_node);
cpu = cpumask_first(cpu_mask);
its_dev->event_map.col_map[event] = cpu;
irq_data_update_effective_affinity(d, cpumask_of(cpu));
its_send_mapti(its_dev, d->hwirq, event);
}
static void its_irq_domain_deactivate(struct irq_domain *domain,
struct irq_data *d)
{
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
u32 event = its_get_event_id(d);
its_send_discard(its_dev, event);
}
static void its_irq_domain_free(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs)
{
struct irq_data *d = irq_domain_get_irq_data(domain, virq);
struct its_device *its_dev = irq_data_get_irq_chip_data(d);
int i;
for (i = 0; i < nr_irqs; i++) {
struct irq_data *data = irq_domain_get_irq_data(domain,
virq + i);
u32 event = its_get_event_id(data);
clear_bit(event, its_dev->event_map.lpi_map);
irq_domain_reset_irq_data(data);
}
if (bitmap_empty(its_dev->event_map.lpi_map,
its_dev->event_map.nr_lpis)) {
its_lpi_free_chunks(its_dev->event_map.lpi_map,
its_dev->event_map.lpi_base,
its_dev->event_map.nr_lpis);
kfree(its_dev->event_map.col_map);
its_send_mapd(its_dev, 0);
its_free_device(its_dev);
}
irq_domain_free_irqs_parent(domain, virq, nr_irqs);
}
static void its_vpe_db_proxy_unmap_locked(struct its_vpe *vpe)
{
if (vpe->vpe_proxy_event == -1)
return;
its_send_discard(vpe_proxy.dev, vpe->vpe_proxy_event);
vpe_proxy.vpes[vpe->vpe_proxy_event] = NULL;
if (vpe_proxy.vpes[vpe_proxy.next_victim])
vpe_proxy.next_victim = vpe->vpe_proxy_event;
vpe->vpe_proxy_event = -1;
}
static void its_vpe_db_proxy_unmap(struct its_vpe *vpe)
{
if (!gic_rdists->has_direct_lpi) {
unsigned long flags;
raw_spin_lock_irqsave(&vpe_proxy.lock, flags);
its_vpe_db_proxy_unmap_locked(vpe);
raw_spin_unlock_irqrestore(&vpe_proxy.lock, flags);
}
}
static void its_vpe_db_proxy_map_locked(struct its_vpe *vpe)
{
if (vpe->vpe_proxy_event != -1)
return;
if (vpe_proxy.vpes[vpe_proxy.next_victim])
its_vpe_db_proxy_unmap_locked(vpe_proxy.vpes[vpe_proxy.next_victim]);
vpe_proxy.vpes[vpe_proxy.next_victim] = vpe;
vpe->vpe_proxy_event = vpe_proxy.next_victim;
vpe_proxy.next_victim = (vpe_proxy.next_victim + 1) % vpe_proxy.dev->nr_ites;
vpe_proxy.dev->event_map.col_map[vpe->vpe_proxy_event] = vpe->col_idx;
its_send_mapti(vpe_proxy.dev, vpe->vpe_db_lpi, vpe->vpe_proxy_event);
}
static void its_vpe_db_proxy_move(struct its_vpe *vpe, int from, int to)
{
unsigned long flags;
struct its_collection *target_col;
if (gic_rdists->has_direct_lpi) {
void __iomem *rdbase;
rdbase = per_cpu_ptr(gic_rdists->rdist, from)->rd_base;
gic_write_lpir(vpe->vpe_db_lpi, rdbase + GICR_CLRLPIR);
while (gic_read_lpir(rdbase + GICR_SYNCR) & 1)
cpu_relax();
return;
}
raw_spin_lock_irqsave(&vpe_proxy.lock, flags);
its_vpe_db_proxy_map_locked(vpe);
target_col = &vpe_proxy.dev->its->collections[to];
its_send_movi(vpe_proxy.dev, target_col, vpe->vpe_proxy_event);
vpe_proxy.dev->event_map.col_map[vpe->vpe_proxy_event] = to;
raw_spin_unlock_irqrestore(&vpe_proxy.lock, flags);
}
static int its_vpe_set_affinity(struct irq_data *d,
const struct cpumask *mask_val,
bool force)
{
struct its_vpe *vpe = irq_data_get_irq_chip_data(d);
int cpu = cpumask_first(mask_val);
if (vpe->col_idx != cpu) {
int from = vpe->col_idx;
vpe->col_idx = cpu;
its_send_vmovp(vpe);
its_vpe_db_proxy_move(vpe, from, cpu);
}
return IRQ_SET_MASK_OK_DONE;
}
static void its_vpe_schedule(struct its_vpe *vpe)
{
void * __iomem vlpi_base = gic_data_rdist_vlpi_base();
u64 val;
val = virt_to_phys(page_address(vpe->its_vm->vprop_page)) &
GENMASK_ULL(51, 12);
val |= (LPI_NRBITS - 1) & GICR_VPROPBASER_IDBITS_MASK;
val |= GICR_VPROPBASER_RaWb;
val |= GICR_VPROPBASER_InnerShareable;
gits_write_vpropbaser(val, vlpi_base + GICR_VPROPBASER);
val = virt_to_phys(page_address(vpe->vpt_page)) &
GENMASK_ULL(51, 16);
val |= GICR_VPENDBASER_RaWaWb;
val |= GICR_VPENDBASER_NonShareable;
val |= GICR_VPENDBASER_PendingLast;
val |= vpe->idai ? GICR_VPENDBASER_IDAI : 0;
val |= GICR_VPENDBASER_Valid;
gits_write_vpendbaser(val, vlpi_base + GICR_VPENDBASER);
}
static void its_vpe_deschedule(struct its_vpe *vpe)
{
void * __iomem vlpi_base = gic_data_rdist_vlpi_base();
u32 count = 1000000;
bool clean;
u64 val;
val = gits_read_vpendbaser(vlpi_base + GICR_VPENDBASER);
val &= ~GICR_VPENDBASER_Valid;
gits_write_vpendbaser(val, vlpi_base + GICR_VPENDBASER);
do {
val = gits_read_vpendbaser(vlpi_base + GICR_VPENDBASER);
clean = !(val & GICR_VPENDBASER_Dirty);
if (!clean) {
count--;
cpu_relax();
udelay(1);
}
} while (!clean && count);
if (unlikely(!clean && !count)) {
pr_err_ratelimited("ITS virtual pending table not cleaning\n");
vpe->idai = false;
vpe->pending_last = true;
} else {
vpe->idai = !!(val & GICR_VPENDBASER_IDAI);
vpe->pending_last = !!(val & GICR_VPENDBASER_PendingLast);
}
}
static int its_vpe_set_vcpu_affinity(struct irq_data *d, void *vcpu_info)
{
struct its_vpe *vpe = irq_data_get_irq_chip_data(d);
struct its_cmd_info *info = vcpu_info;
switch (info->cmd_type) {
case SCHEDULE_VPE:
its_vpe_schedule(vpe);
return 0;
case DESCHEDULE_VPE:
its_vpe_deschedule(vpe);
return 0;
case INVALL_VPE:
its_send_vinvall(vpe);
return 0;
default:
return -EINVAL;
}
}
static void its_vpe_send_cmd(struct its_vpe *vpe,
void (*cmd)(struct its_device *, u32))
{
unsigned long flags;
raw_spin_lock_irqsave(&vpe_proxy.lock, flags);
its_vpe_db_proxy_map_locked(vpe);
cmd(vpe_proxy.dev, vpe->vpe_proxy_event);
raw_spin_unlock_irqrestore(&vpe_proxy.lock, flags);
}
static void its_vpe_send_inv(struct irq_data *d)
{
struct its_vpe *vpe = irq_data_get_irq_chip_data(d);
if (gic_rdists->has_direct_lpi) {
void __iomem *rdbase;
rdbase = per_cpu_ptr(gic_rdists->rdist, vpe->col_idx)->rd_base;
gic_write_lpir(vpe->vpe_db_lpi, rdbase + GICR_INVLPIR);
while (gic_read_lpir(rdbase + GICR_SYNCR) & 1)
cpu_relax();
} else {
its_vpe_send_cmd(vpe, its_send_inv);
}
}
static void its_vpe_mask_irq(struct irq_data *d)
{
lpi_write_config(d->parent_data, LPI_PROP_ENABLED, 0);
its_vpe_send_inv(d);
}
static void its_vpe_unmask_irq(struct irq_data *d)
{
lpi_write_config(d->parent_data, 0, LPI_PROP_ENABLED);
its_vpe_send_inv(d);
}
static int its_vpe_set_irqchip_state(struct irq_data *d,
enum irqchip_irq_state which,
bool state)
{
struct its_vpe *vpe = irq_data_get_irq_chip_data(d);
if (which != IRQCHIP_STATE_PENDING)
return -EINVAL;
if (gic_rdists->has_direct_lpi) {
void __iomem *rdbase;
rdbase = per_cpu_ptr(gic_rdists->rdist, vpe->col_idx)->rd_base;
if (state) {
gic_write_lpir(vpe->vpe_db_lpi, rdbase + GICR_SETLPIR);
} else {
gic_write_lpir(vpe->vpe_db_lpi, rdbase + GICR_CLRLPIR);
while (gic_read_lpir(rdbase + GICR_SYNCR) & 1)
cpu_relax();
}
} else {
if (state)
its_vpe_send_cmd(vpe, its_send_int);
else
its_vpe_send_cmd(vpe, its_send_clear);
}
return 0;
}
static int its_vpe_id_alloc(void)
{
return ida_simple_get(&its_vpeid_ida, 0, ITS_MAX_VPEID, GFP_KERNEL);
}
static void its_vpe_id_free(u16 id)
{
ida_simple_remove(&its_vpeid_ida, id);
}
static int its_vpe_init(struct its_vpe *vpe)
{
struct page *vpt_page;
int vpe_id;
vpe_id = its_vpe_id_alloc();
if (vpe_id < 0)
return vpe_id;
vpt_page = its_allocate_pending_table(GFP_KERNEL);
if (!vpt_page) {
its_vpe_id_free(vpe_id);
return -ENOMEM;
}
if (!its_alloc_vpe_table(vpe_id)) {
its_vpe_id_free(vpe_id);
its_free_pending_table(vpe->vpt_page);
return -ENOMEM;
}
vpe->vpe_id = vpe_id;
vpe->vpt_page = vpt_page;
vpe->vpe_proxy_event = -1;
return 0;
}
static void its_vpe_teardown(struct its_vpe *vpe)
{
its_vpe_db_proxy_unmap(vpe);
its_vpe_id_free(vpe->vpe_id);
its_free_pending_table(vpe->vpt_page);
}
static void its_vpe_irq_domain_free(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs)
{
struct its_vm *vm = domain->host_data;
int i;
irq_domain_free_irqs_parent(domain, virq, nr_irqs);
for (i = 0; i < nr_irqs; i++) {
struct irq_data *data = irq_domain_get_irq_data(domain,
virq + i);
struct its_vpe *vpe = irq_data_get_irq_chip_data(data);
BUG_ON(vm != vpe->its_vm);
clear_bit(data->hwirq, vm->db_bitmap);
its_vpe_teardown(vpe);
irq_domain_reset_irq_data(data);
}
if (bitmap_empty(vm->db_bitmap, vm->nr_db_lpis)) {
its_lpi_free_chunks(vm->db_bitmap, vm->db_lpi_base, vm->nr_db_lpis);
its_free_prop_table(vm->vprop_page);
}
}
static int its_vpe_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *args)
{
struct its_vm *vm = args;
unsigned long *bitmap;
struct page *vprop_page;
int base, nr_ids, i, err = 0;
BUG_ON(!vm);
bitmap = its_lpi_alloc_chunks(nr_irqs, &base, &nr_ids);
if (!bitmap)
return -ENOMEM;
if (nr_ids < nr_irqs) {
its_lpi_free_chunks(bitmap, base, nr_ids);
return -ENOMEM;
}
vprop_page = its_allocate_prop_table(GFP_KERNEL);
if (!vprop_page) {
its_lpi_free_chunks(bitmap, base, nr_ids);
return -ENOMEM;
}
vm->db_bitmap = bitmap;
vm->db_lpi_base = base;
vm->nr_db_lpis = nr_ids;
vm->vprop_page = vprop_page;
for (i = 0; i < nr_irqs; i++) {
vm->vpes[i]->vpe_db_lpi = base + i;
err = its_vpe_init(vm->vpes[i]);
if (err)
break;
err = its_irq_gic_domain_alloc(domain, virq + i,
vm->vpes[i]->vpe_db_lpi);
if (err)
break;
irq_domain_set_hwirq_and_chip(domain, virq + i, i,
&its_vpe_irq_chip, vm->vpes[i]);
set_bit(i, bitmap);
}
if (err) {
if (i > 0)
its_vpe_irq_domain_free(domain, virq, i - 1);
its_lpi_free_chunks(bitmap, base, nr_ids);
its_free_prop_table(vprop_page);
}
return err;
}
static void its_vpe_irq_domain_activate(struct irq_domain *domain,
struct irq_data *d)
{
struct its_vpe *vpe = irq_data_get_irq_chip_data(d);
vpe->col_idx = cpumask_first(cpu_online_mask);
its_send_vmapp(vpe, true);
its_send_vinvall(vpe);
}
static void its_vpe_irq_domain_deactivate(struct irq_domain *domain,
struct irq_data *d)
{
struct its_vpe *vpe = irq_data_get_irq_chip_data(d);
its_send_vmapp(vpe, false);
}
static int its_force_quiescent(void __iomem *base)
{
u32 count = 1000000;
u32 val;
val = readl_relaxed(base + GITS_CTLR);
if ((val & GITS_CTLR_QUIESCENT) && !(val & GITS_CTLR_ENABLE))
return 0;
val &= ~(GITS_CTLR_ENABLE | GITS_CTLR_ImDe);
writel_relaxed(val, base + GITS_CTLR);
while (1) {
val = readl_relaxed(base + GITS_CTLR);
if (val & GITS_CTLR_QUIESCENT)
return 0;
count--;
if (!count)
return -EBUSY;
cpu_relax();
udelay(1);
}
}
static void __maybe_unused its_enable_quirk_cavium_22375(void *data)
{
struct its_node *its = data;
its->flags |= ITS_FLAGS_WORKAROUND_CAVIUM_22375;
}
static void __maybe_unused its_enable_quirk_cavium_23144(void *data)
{
struct its_node *its = data;
its->flags |= ITS_FLAGS_WORKAROUND_CAVIUM_23144;
}
static void __maybe_unused its_enable_quirk_qdf2400_e0065(void *data)
{
struct its_node *its = data;
its->ite_size = 16;
}
static void its_enable_quirks(struct its_node *its)
{
u32 iidr = readl_relaxed(its->base + GITS_IIDR);
gic_enable_quirks(iidr, its_quirks, its);
}
static int its_init_domain(struct fwnode_handle *handle, struct its_node *its)
{
struct irq_domain *inner_domain;
struct msi_domain_info *info;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
inner_domain = irq_domain_create_tree(handle, &its_domain_ops, its);
if (!inner_domain) {
kfree(info);
return -ENOMEM;
}
inner_domain->parent = its_parent;
irq_domain_update_bus_token(inner_domain, DOMAIN_BUS_NEXUS);
inner_domain->flags |= IRQ_DOMAIN_FLAG_MSI_REMAP;
info->ops = &its_msi_domain_ops;
info->data = its;
inner_domain->host_data = info;
return 0;
}
static int its_init_vpe_domain(void)
{
struct its_node *its;
u32 devid;
int entries;
if (gic_rdists->has_direct_lpi) {
pr_info("ITS: Using DirectLPI for VPE invalidation\n");
return 0;
}
its = list_first_entry(&its_nodes, struct its_node, entry);
entries = roundup_pow_of_two(nr_cpu_ids);
vpe_proxy.vpes = kzalloc(sizeof(*vpe_proxy.vpes) * entries,
GFP_KERNEL);
if (!vpe_proxy.vpes) {
pr_err("ITS: Can't allocate GICv4 proxy device array\n");
return -ENOMEM;
}
devid = GENMASK(its->device_ids - 1, 0);
vpe_proxy.dev = its_create_device(its, devid, entries, false);
if (!vpe_proxy.dev) {
kfree(vpe_proxy.vpes);
pr_err("ITS: Can't allocate GICv4 proxy device\n");
return -ENOMEM;
}
BUG_ON(entries > vpe_proxy.dev->nr_ites);
raw_spin_lock_init(&vpe_proxy.lock);
vpe_proxy.next_victim = 0;
pr_info("ITS: Allocated DevID %x as GICv4 proxy device (%d slots)\n",
devid, vpe_proxy.dev->nr_ites);
return 0;
}
static int __init its_compute_its_list_map(struct resource *res,
void __iomem *its_base)
{
int its_number;
u32 ctlr;
its_number = find_first_zero_bit(&its_list_map, ITS_LIST_MAX);
if (its_number >= ITS_LIST_MAX) {
pr_err("ITS@%pa: No ITSList entry available!\n",
&res->start);
return -EINVAL;
}
ctlr = readl_relaxed(its_base + GITS_CTLR);
ctlr &= ~GITS_CTLR_ITS_NUMBER;
ctlr |= its_number << GITS_CTLR_ITS_NUMBER_SHIFT;
writel_relaxed(ctlr, its_base + GITS_CTLR);
ctlr = readl_relaxed(its_base + GITS_CTLR);
if ((ctlr & GITS_CTLR_ITS_NUMBER) != (its_number << GITS_CTLR_ITS_NUMBER_SHIFT)) {
its_number = ctlr & GITS_CTLR_ITS_NUMBER;
its_number >>= GITS_CTLR_ITS_NUMBER_SHIFT;
}
if (test_and_set_bit(its_number, &its_list_map)) {
pr_err("ITS@%pa: Duplicate ITSList entry %d\n",
&res->start, its_number);
return -EINVAL;
}
return its_number;
}
static int __init its_probe_one(struct resource *res,
struct fwnode_handle *handle, int numa_node)
{
struct its_node *its;
void __iomem *its_base;
u32 val, ctlr;
u64 baser, tmp, typer;
int err;
its_base = ioremap(res->start, resource_size(res));
if (!its_base) {
pr_warn("ITS@%pa: Unable to map ITS registers\n", &res->start);
return -ENOMEM;
}
val = readl_relaxed(its_base + GITS_PIDR2) & GIC_PIDR2_ARCH_MASK;
if (val != 0x30 && val != 0x40) {
pr_warn("ITS@%pa: No ITS detected, giving up\n", &res->start);
err = -ENODEV;
goto out_unmap;
}
err = its_force_quiescent(its_base);
if (err) {
pr_warn("ITS@%pa: Failed to quiesce, giving up\n", &res->start);
goto out_unmap;
}
pr_info("ITS %pR\n", res);
its = kzalloc(sizeof(*its), GFP_KERNEL);
if (!its) {
err = -ENOMEM;
goto out_unmap;
}
raw_spin_lock_init(&its->lock);
INIT_LIST_HEAD(&its->entry);
INIT_LIST_HEAD(&its->its_device_list);
typer = gic_read_typer(its_base + GITS_TYPER);
its->base = its_base;
its->phys_base = res->start;
its->ite_size = GITS_TYPER_ITT_ENTRY_SIZE(typer);
its->is_v4 = !!(typer & GITS_TYPER_VLPIS);
if (its->is_v4) {
if (!(typer & GITS_TYPER_VMOVP)) {
err = its_compute_its_list_map(res, its_base);
if (err < 0)
goto out_free_its;
pr_info("ITS@%pa: Using ITS number %d\n",
&res->start, err);
} else {
pr_info("ITS@%pa: Single VMOVP capable\n", &res->start);
}
}
its->numa_node = numa_node;
its->cmd_base = (void *)__get_free_pages(GFP_KERNEL | __GFP_ZERO,
get_order(ITS_CMD_QUEUE_SZ));
if (!its->cmd_base) {
err = -ENOMEM;
goto out_free_its;
}
its->cmd_write = its->cmd_base;
its_enable_quirks(its);
err = its_alloc_tables(its);
if (err)
goto out_free_cmd;
err = its_alloc_collections(its);
if (err)
goto out_free_tables;
baser = (virt_to_phys(its->cmd_base) |
GITS_CBASER_RaWaWb |
GITS_CBASER_InnerShareable |
(ITS_CMD_QUEUE_SZ / SZ_4K - 1) |
GITS_CBASER_VALID);
gits_write_cbaser(baser, its->base + GITS_CBASER);
tmp = gits_read_cbaser(its->base + GITS_CBASER);
if ((tmp ^ baser) & GITS_CBASER_SHAREABILITY_MASK) {
if (!(tmp & GITS_CBASER_SHAREABILITY_MASK)) {
baser &= ~(GITS_CBASER_SHAREABILITY_MASK |
GITS_CBASER_CACHEABILITY_MASK);
baser |= GITS_CBASER_nC;
gits_write_cbaser(baser, its->base + GITS_CBASER);
}
pr_info("ITS: using cache flushing for cmd queue\n");
its->flags |= ITS_FLAGS_CMDQ_NEEDS_FLUSHING;
}
gits_write_cwriter(0, its->base + GITS_CWRITER);
ctlr = readl_relaxed(its->base + GITS_CTLR);
ctlr |= GITS_CTLR_ENABLE;
if (its->is_v4)
ctlr |= GITS_CTLR_ImDe;
writel_relaxed(ctlr, its->base + GITS_CTLR);
err = its_init_domain(handle, its);
if (err)
goto out_free_tables;
spin_lock(&its_lock);
list_add(&its->entry, &its_nodes);
spin_unlock(&its_lock);
return 0;
out_free_tables:
its_free_tables(its);
out_free_cmd:
free_pages((unsigned long)its->cmd_base, get_order(ITS_CMD_QUEUE_SZ));
out_free_its:
kfree(its);
out_unmap:
iounmap(its_base);
pr_err("ITS@%pa: failed probing (%d)\n", &res->start, err);
return err;
}
static bool gic_rdists_supports_plpis(void)
{
return !!(gic_read_typer(gic_data_rdist_rd_base() + GICR_TYPER) & GICR_TYPER_PLPIS);
}
int its_cpu_init(void)
{
if (!list_empty(&its_nodes)) {
if (!gic_rdists_supports_plpis()) {
pr_info("CPU%d: LPIs not supported\n", smp_processor_id());
return -ENXIO;
}
its_cpu_init_lpis();
its_cpu_init_collection();
}
return 0;
}
static int __init its_of_probe(struct device_node *node)
{
struct device_node *np;
struct resource res;
for (np = of_find_matching_node(node, its_device_id); np;
np = of_find_matching_node(np, its_device_id)) {
if (!of_property_read_bool(np, "msi-controller")) {
pr_warn("%pOF: no msi-controller property, ITS ignored\n",
np);
continue;
}
if (of_address_to_resource(np, 0, &res)) {
pr_warn("%pOF: no regs?\n", np);
continue;
}
its_probe_one(&res, &np->fwnode, of_node_to_nid(np));
}
return 0;
}
static int __init acpi_get_its_numa_node(u32 its_id)
{
int i;
for (i = 0; i < its_in_srat; i++) {
if (its_id == its_srat_maps[i].its_id)
return its_srat_maps[i].numa_node;
}
return NUMA_NO_NODE;
}
static int __init gic_acpi_match_srat_its(struct acpi_subtable_header *header,
const unsigned long end)
{
return 0;
}
static int __init gic_acpi_parse_srat_its(struct acpi_subtable_header *header,
const unsigned long end)
{
int node;
struct acpi_srat_gic_its_affinity *its_affinity;
its_affinity = (struct acpi_srat_gic_its_affinity *)header;
if (!its_affinity)
return -EINVAL;
if (its_affinity->header.length < sizeof(*its_affinity)) {
pr_err("SRAT: Invalid header length %d in ITS affinity\n",
its_affinity->header.length);
return -EINVAL;
}
node = acpi_map_pxm_to_node(its_affinity->proximity_domain);
if (node == NUMA_NO_NODE || node >= MAX_NUMNODES) {
pr_err("SRAT: Invalid NUMA node %d in ITS affinity\n", node);
return 0;
}
its_srat_maps[its_in_srat].numa_node = node;
its_srat_maps[its_in_srat].its_id = its_affinity->its_id;
its_in_srat++;
pr_info("SRAT: PXM %d -> ITS %d -> Node %d\n",
its_affinity->proximity_domain, its_affinity->its_id, node);
return 0;
}
static void __init acpi_table_parse_srat_its(void)
{
int count;
count = acpi_table_parse_entries(ACPI_SIG_SRAT,
sizeof(struct acpi_table_srat),
ACPI_SRAT_TYPE_GIC_ITS_AFFINITY,
gic_acpi_match_srat_its, 0);
if (count <= 0)
return;
its_srat_maps = kmalloc(count * sizeof(struct its_srat_map),
GFP_KERNEL);
if (!its_srat_maps) {
pr_warn("SRAT: Failed to allocate memory for its_srat_maps!\n");
return;
}
acpi_table_parse_entries(ACPI_SIG_SRAT,
sizeof(struct acpi_table_srat),
ACPI_SRAT_TYPE_GIC_ITS_AFFINITY,
gic_acpi_parse_srat_its, 0);
}
static void __init acpi_its_srat_maps_free(void)
{
kfree(its_srat_maps);
}
static void __init acpi_table_parse_srat_its(void) { }
static int __init acpi_get_its_numa_node(u32 its_id) { return NUMA_NO_NODE; }
static void __init acpi_its_srat_maps_free(void) { }
static int __init gic_acpi_parse_madt_its(struct acpi_subtable_header *header,
const unsigned long end)
{
struct acpi_madt_generic_translator *its_entry;
struct fwnode_handle *dom_handle;
struct resource res;
int err;
its_entry = (struct acpi_madt_generic_translator *)header;
memset(&res, 0, sizeof(res));
res.start = its_entry->base_address;
res.end = its_entry->base_address + ACPI_GICV3_ITS_MEM_SIZE - 1;
res.flags = IORESOURCE_MEM;
dom_handle = irq_domain_alloc_fwnode((void *)its_entry->base_address);
if (!dom_handle) {
pr_err("ITS@%pa: Unable to allocate GICv3 ITS domain token\n",
&res.start);
return -ENOMEM;
}
err = iort_register_domain_token(its_entry->translation_id, dom_handle);
if (err) {
pr_err("ITS@%pa: Unable to register GICv3 ITS domain token (ITS ID %d) to IORT\n",
&res.start, its_entry->translation_id);
goto dom_err;
}
err = its_probe_one(&res, dom_handle,
acpi_get_its_numa_node(its_entry->translation_id));
if (!err)
return 0;
iort_deregister_domain_token(its_entry->translation_id);
dom_err:
irq_domain_free_fwnode(dom_handle);
return err;
}
static void __init its_acpi_probe(void)
{
acpi_table_parse_srat_its();
acpi_table_parse_madt(ACPI_MADT_TYPE_GENERIC_TRANSLATOR,
gic_acpi_parse_madt_its, 0);
acpi_its_srat_maps_free();
}
static void __init its_acpi_probe(void) { }
int __init its_init(struct fwnode_handle *handle, struct rdists *rdists,
struct irq_domain *parent_domain)
{
struct device_node *of_node;
struct its_node *its;
bool has_v4 = false;
int err;
its_parent = parent_domain;
of_node = to_of_node(handle);
if (of_node)
its_of_probe(of_node);
else
its_acpi_probe();
if (list_empty(&its_nodes)) {
pr_warn("ITS: No ITS available, not enabling LPIs\n");
return -ENXIO;
}
gic_rdists = rdists;
err = its_alloc_lpi_tables();
if (err)
return err;
list_for_each_entry(its, &its_nodes, entry)
has_v4 |= its->is_v4;
if (has_v4 & rdists->has_vlpis) {
if (its_init_vpe_domain() ||
its_init_v4(parent_domain, &its_vpe_domain_ops)) {
rdists->has_vlpis = false;
pr_err("ITS: Disabling GICv4 support\n");
}
}
return 0;
}
