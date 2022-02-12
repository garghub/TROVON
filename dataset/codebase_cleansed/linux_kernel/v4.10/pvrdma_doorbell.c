int pvrdma_uar_table_init(struct pvrdma_dev *dev)
{
u32 num = dev->dsr->caps.max_uar;
u32 mask = num - 1;
struct pvrdma_id_table *tbl = &dev->uar_table.tbl;
if (!is_power_of_2(num))
return -EINVAL;
tbl->last = 0;
tbl->top = 0;
tbl->max = num;
tbl->mask = mask;
spin_lock_init(&tbl->lock);
tbl->table = kcalloc(BITS_TO_LONGS(num), sizeof(long), GFP_KERNEL);
if (!tbl->table)
return -ENOMEM;
set_bit(0, tbl->table);
return 0;
}
void pvrdma_uar_table_cleanup(struct pvrdma_dev *dev)
{
struct pvrdma_id_table *tbl = &dev->uar_table.tbl;
kfree(tbl->table);
}
int pvrdma_uar_alloc(struct pvrdma_dev *dev, struct pvrdma_uar_map *uar)
{
struct pvrdma_id_table *tbl;
unsigned long flags;
u32 obj;
tbl = &dev->uar_table.tbl;
spin_lock_irqsave(&tbl->lock, flags);
obj = find_next_zero_bit(tbl->table, tbl->max, tbl->last);
if (obj >= tbl->max) {
tbl->top = (tbl->top + tbl->max) & tbl->mask;
obj = find_first_zero_bit(tbl->table, tbl->max);
}
if (obj >= tbl->max) {
spin_unlock_irqrestore(&tbl->lock, flags);
return -ENOMEM;
}
set_bit(obj, tbl->table);
obj |= tbl->top;
spin_unlock_irqrestore(&tbl->lock, flags);
uar->index = obj;
uar->pfn = (pci_resource_start(dev->pdev, PVRDMA_PCI_RESOURCE_UAR) >>
PAGE_SHIFT) + uar->index;
return 0;
}
void pvrdma_uar_free(struct pvrdma_dev *dev, struct pvrdma_uar_map *uar)
{
struct pvrdma_id_table *tbl = &dev->uar_table.tbl;
unsigned long flags;
u32 obj;
obj = uar->index & (tbl->max - 1);
spin_lock_irqsave(&tbl->lock, flags);
clear_bit(obj, tbl->table);
tbl->last = min(tbl->last, obj);
tbl->top = (tbl->top + tbl->max) & tbl->mask;
spin_unlock_irqrestore(&tbl->lock, flags);
}
