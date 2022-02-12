int mthca_uar_alloc(struct mthca_dev *dev, struct mthca_uar *uar)
{
uar->index = mthca_alloc(&dev->uar_table.alloc);
if (uar->index == -1)
return -ENOMEM;
uar->pfn = (pci_resource_start(dev->pdev, 2) >> PAGE_SHIFT) + uar->index;
return 0;
}
void mthca_uar_free(struct mthca_dev *dev, struct mthca_uar *uar)
{
mthca_free(&dev->uar_table.alloc, uar->index);
}
int mthca_init_uar_table(struct mthca_dev *dev)
{
int ret;
ret = mthca_alloc_init(&dev->uar_table.alloc,
dev->limits.num_uars,
dev->limits.num_uars - 1,
dev->limits.reserved_uars + 1);
if (ret)
return ret;
ret = mthca_init_db_tab(dev);
if (ret)
mthca_alloc_cleanup(&dev->uar_table.alloc);
return ret;
}
void mthca_cleanup_uar_table(struct mthca_dev *dev)
{
mthca_cleanup_db_tab(dev);
mthca_alloc_cleanup(&dev->uar_table.alloc);
}
