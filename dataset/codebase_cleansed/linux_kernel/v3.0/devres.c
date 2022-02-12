void __iomem *devm_ioremap_prot(struct device *dev, resource_size_t offset,
size_t size, unsigned long flags)
{
void __iomem **ptr, *addr;
ptr = devres_alloc(devm_ioremap_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return NULL;
addr = ioremap_prot(offset, size, flags);
if (addr) {
*ptr = addr;
devres_add(dev, ptr);
} else
devres_free(ptr);
return addr;
}
