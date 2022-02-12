ssize_t vfio_pci_io_readwrite(struct vfio_pci_device *vdev, char __user *buf,
size_t count, loff_t *ppos, bool iswrite)
{
struct pci_dev *pdev = vdev->pdev;
loff_t pos = *ppos & VFIO_PCI_OFFSET_MASK;
int bar = VFIO_PCI_OFFSET_TO_INDEX(*ppos);
void __iomem *io;
size_t done = 0;
if (!pci_resource_start(pdev, bar))
return -EINVAL;
if (pos + count > pci_resource_len(pdev, bar))
return -EINVAL;
if (!vdev->barmap[bar]) {
int ret;
ret = pci_request_selected_regions(pdev, 1 << bar, "vfio");
if (ret)
return ret;
vdev->barmap[bar] = pci_iomap(pdev, bar, 0);
if (!vdev->barmap[bar]) {
pci_release_selected_regions(pdev, 1 << bar);
return -EINVAL;
}
}
io = vdev->barmap[bar];
while (count) {
int filled;
if (count >= 3 && !(pos % 4)) {
__le32 val;
if (iswrite) {
if (copy_from_user(&val, buf, 4))
return -EFAULT;
iowrite32(le32_to_cpu(val), io + pos);
} else {
val = cpu_to_le32(ioread32(io + pos));
if (copy_to_user(buf, &val, 4))
return -EFAULT;
}
filled = 4;
} else if ((pos % 2) == 0 && count >= 2) {
__le16 val;
if (iswrite) {
if (copy_from_user(&val, buf, 2))
return -EFAULT;
iowrite16(le16_to_cpu(val), io + pos);
} else {
val = cpu_to_le16(ioread16(io + pos));
if (copy_to_user(buf, &val, 2))
return -EFAULT;
}
filled = 2;
} else {
u8 val;
if (iswrite) {
if (copy_from_user(&val, buf, 1))
return -EFAULT;
iowrite8(val, io + pos);
} else {
val = ioread8(io + pos);
if (copy_to_user(buf, &val, 1))
return -EFAULT;
}
filled = 1;
}
count -= filled;
done += filled;
buf += filled;
pos += filled;
}
*ppos += done;
return done;
}
ssize_t vfio_pci_mem_readwrite(struct vfio_pci_device *vdev, char __user *buf,
size_t count, loff_t *ppos, bool iswrite)
{
struct pci_dev *pdev = vdev->pdev;
loff_t pos = *ppos & VFIO_PCI_OFFSET_MASK;
int bar = VFIO_PCI_OFFSET_TO_INDEX(*ppos);
void __iomem *io;
resource_size_t end;
size_t done = 0;
size_t x_start = 0, x_end = 0;
if (!pci_resource_start(pdev, bar))
return -EINVAL;
end = pci_resource_len(pdev, bar);
if (pos > end)
return -EINVAL;
if (pos == end)
return 0;
if (pos + count > end)
count = end - pos;
if (bar == PCI_ROM_RESOURCE) {
io = pci_map_rom(pdev, &x_start);
x_end = end;
} else {
if (!vdev->barmap[bar]) {
int ret;
ret = pci_request_selected_regions(pdev, 1 << bar,
"vfio");
if (ret)
return ret;
vdev->barmap[bar] = pci_iomap(pdev, bar, 0);
if (!vdev->barmap[bar]) {
pci_release_selected_regions(pdev, 1 << bar);
return -EINVAL;
}
}
io = vdev->barmap[bar];
if (bar == vdev->msix_bar) {
x_start = vdev->msix_offset;
x_end = vdev->msix_offset + vdev->msix_size;
}
}
if (!io)
return -EINVAL;
while (count) {
size_t fillable, filled;
if (pos < x_start)
fillable = x_start - pos;
else if (pos >= x_end)
fillable = end - pos;
else
fillable = 0;
if (fillable >= 4 && !(pos % 4) && (count >= 4)) {
__le32 val;
if (iswrite) {
if (copy_from_user(&val, buf, 4))
goto out;
iowrite32(le32_to_cpu(val), io + pos);
} else {
val = cpu_to_le32(ioread32(io + pos));
if (copy_to_user(buf, &val, 4))
goto out;
}
filled = 4;
} else if (fillable >= 2 && !(pos % 2) && (count >= 2)) {
__le16 val;
if (iswrite) {
if (copy_from_user(&val, buf, 2))
goto out;
iowrite16(le16_to_cpu(val), io + pos);
} else {
val = cpu_to_le16(ioread16(io + pos));
if (copy_to_user(buf, &val, 2))
goto out;
}
filled = 2;
} else if (fillable) {
u8 val;
if (iswrite) {
if (copy_from_user(&val, buf, 1))
goto out;
iowrite8(val, io + pos);
} else {
val = ioread8(io + pos);
if (copy_to_user(buf, &val, 1))
goto out;
}
filled = 1;
} else {
if (!iswrite) {
char val = 0xFF;
size_t i;
for (i = 0; i < x_end - pos; i++) {
if (put_user(val, buf + i))
goto out;
}
}
filled = x_end - pos;
}
count -= filled;
done += filled;
buf += filled;
pos += filled;
}
*ppos += done;
out:
if (bar == PCI_ROM_RESOURCE)
pci_unmap_rom(pdev, io);
return count ? -EFAULT : done;
}
