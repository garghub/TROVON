static int command_read(struct pci_dev *dev, int offset, u16 *value, void *data)
{
int i;
int ret;
ret = xen_pcibk_read_config_word(dev, offset, value, data);
if (!pci_is_enabled(dev))
return ret;
for (i = 0; i < PCI_ROM_RESOURCE; i++) {
if (dev->resource[i].flags & IORESOURCE_IO)
*value |= PCI_COMMAND_IO;
if (dev->resource[i].flags & IORESOURCE_MEM)
*value |= PCI_COMMAND_MEMORY;
}
return ret;
}
static int command_write(struct pci_dev *dev, int offset, u16 value, void *data)
{
struct xen_pcibk_dev_data *dev_data;
int err;
dev_data = pci_get_drvdata(dev);
if (!pci_is_enabled(dev) && is_enable_cmd(value)) {
if (unlikely(verbose_request))
printk(KERN_DEBUG DRV_NAME ": %s: enable\n",
pci_name(dev));
err = pci_enable_device(dev);
if (err)
return err;
if (dev_data)
dev_data->enable_intx = 1;
} else if (pci_is_enabled(dev) && !is_enable_cmd(value)) {
if (unlikely(verbose_request))
printk(KERN_DEBUG DRV_NAME ": %s: disable\n",
pci_name(dev));
pci_disable_device(dev);
if (dev_data)
dev_data->enable_intx = 0;
}
if (!dev->is_busmaster && is_master_cmd(value)) {
if (unlikely(verbose_request))
printk(KERN_DEBUG DRV_NAME ": %s: set bus master\n",
pci_name(dev));
pci_set_master(dev);
}
if (value & PCI_COMMAND_INVALIDATE) {
if (unlikely(verbose_request))
printk(KERN_DEBUG
DRV_NAME ": %s: enable memory-write-invalidate\n",
pci_name(dev));
err = pci_set_mwi(dev);
if (err) {
printk(KERN_WARNING
DRV_NAME ": %s: cannot enable "
"memory-write-invalidate (%d)\n",
pci_name(dev), err);
value &= ~PCI_COMMAND_INVALIDATE;
}
}
return pci_write_config_word(dev, offset, value);
}
static int rom_write(struct pci_dev *dev, int offset, u32 value, void *data)
{
struct pci_bar_info *bar = data;
if (unlikely(!bar)) {
printk(KERN_WARNING DRV_NAME ": driver data not found for %s\n",
pci_name(dev));
return XEN_PCI_ERR_op_failed;
}
if (value == ~PCI_ROM_ADDRESS_ENABLE)
bar->which = 1;
else {
u32 tmpval;
pci_read_config_dword(dev, offset, &tmpval);
if (tmpval != bar->val && value == bar->val) {
pci_write_config_dword(dev, offset, bar->val);
}
bar->which = 0;
}
return 0;
}
static int bar_write(struct pci_dev *dev, int offset, u32 value, void *data)
{
struct pci_bar_info *bar = data;
if (unlikely(!bar)) {
printk(KERN_WARNING DRV_NAME ": driver data not found for %s\n",
pci_name(dev));
return XEN_PCI_ERR_op_failed;
}
if (value == ~0)
bar->which = 1;
else {
u32 tmpval;
pci_read_config_dword(dev, offset, &tmpval);
if (tmpval != bar->val && value == bar->val) {
pci_write_config_dword(dev, offset, bar->val);
}
bar->which = 0;
}
return 0;
}
static int bar_read(struct pci_dev *dev, int offset, u32 * value, void *data)
{
struct pci_bar_info *bar = data;
if (unlikely(!bar)) {
printk(KERN_WARNING DRV_NAME ": driver data not found for %s\n",
pci_name(dev));
return XEN_PCI_ERR_op_failed;
}
*value = bar->which ? bar->len_val : bar->val;
return 0;
}
static inline void read_dev_bar(struct pci_dev *dev,
struct pci_bar_info *bar_info, int offset,
u32 len_mask)
{
int pos;
struct resource *res = dev->resource;
if (offset == PCI_ROM_ADDRESS || offset == PCI_ROM_ADDRESS1)
pos = PCI_ROM_RESOURCE;
else {
pos = (offset - PCI_BASE_ADDRESS_0) / 4;
if (pos && ((res[pos - 1].flags & (PCI_BASE_ADDRESS_SPACE |
PCI_BASE_ADDRESS_MEM_TYPE_MASK)) ==
(PCI_BASE_ADDRESS_SPACE_MEMORY |
PCI_BASE_ADDRESS_MEM_TYPE_64))) {
bar_info->val = res[pos - 1].start >> 32;
bar_info->len_val = res[pos - 1].end >> 32;
return;
}
}
bar_info->val = res[pos].start |
(res[pos].flags & PCI_REGION_FLAG_MASK);
bar_info->len_val = resource_size(&res[pos]);
}
static void *bar_init(struct pci_dev *dev, int offset)
{
struct pci_bar_info *bar = kmalloc(sizeof(*bar), GFP_KERNEL);
if (!bar)
return ERR_PTR(-ENOMEM);
read_dev_bar(dev, bar, offset, ~0);
bar->which = 0;
return bar;
}
static void *rom_init(struct pci_dev *dev, int offset)
{
struct pci_bar_info *bar = kmalloc(sizeof(*bar), GFP_KERNEL);
if (!bar)
return ERR_PTR(-ENOMEM);
read_dev_bar(dev, bar, offset, ~PCI_ROM_ADDRESS_ENABLE);
bar->which = 0;
return bar;
}
static void bar_reset(struct pci_dev *dev, int offset, void *data)
{
struct pci_bar_info *bar = data;
bar->which = 0;
}
static void bar_release(struct pci_dev *dev, int offset, void *data)
{
kfree(data);
}
static int xen_pcibk_read_vendor(struct pci_dev *dev, int offset,
u16 *value, void *data)
{
*value = dev->vendor;
return 0;
}
static int xen_pcibk_read_device(struct pci_dev *dev, int offset,
u16 *value, void *data)
{
*value = dev->device;
return 0;
}
static int interrupt_read(struct pci_dev *dev, int offset, u8 * value,
void *data)
{
*value = (u8) dev->irq;
return 0;
}
static int bist_write(struct pci_dev *dev, int offset, u8 value, void *data)
{
u8 cur_value;
int err;
err = pci_read_config_byte(dev, offset, &cur_value);
if (err)
goto out;
if ((cur_value & ~PCI_BIST_START) == (value & ~PCI_BIST_START)
|| value == PCI_BIST_START)
err = pci_write_config_byte(dev, offset, value);
out:
return err;
}
int xen_pcibk_config_header_add_fields(struct pci_dev *dev)
{
int err;
err = xen_pcibk_config_add_fields(dev, header_common);
if (err)
goto out;
switch (dev->hdr_type) {
case PCI_HEADER_TYPE_NORMAL:
err = xen_pcibk_config_add_fields(dev, header_0);
break;
case PCI_HEADER_TYPE_BRIDGE:
err = xen_pcibk_config_add_fields(dev, header_1);
break;
default:
err = -EINVAL;
printk(KERN_ERR DRV_NAME ": %s: Unsupported header type %d!\n",
pci_name(dev), dev->hdr_type);
break;
}
out:
return err;
}
