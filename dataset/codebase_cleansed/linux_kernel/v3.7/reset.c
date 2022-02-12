int mlx4_reset(struct mlx4_dev *dev)
{
void __iomem *reset;
u32 *hca_header = NULL;
int pcie_cap;
u16 devctl;
u16 linkctl;
u16 vendor;
unsigned long end;
u32 sem;
int i;
int err = 0;
#define MLX4_RESET_BASE 0xf0000
#define MLX4_RESET_SIZE 0x400
#define MLX4_SEM_OFFSET 0x3fc
#define MLX4_RESET_OFFSET 0x10
#define MLX4_RESET_VALUE swab32(1)
#define MLX4_SEM_TIMEOUT_JIFFIES (10 * HZ)
#define MLX4_RESET_TIMEOUT_JIFFIES (2 * HZ)
hca_header = kmalloc(256, GFP_KERNEL);
if (!hca_header) {
err = -ENOMEM;
mlx4_err(dev, "Couldn't allocate memory to save HCA "
"PCI header, aborting.\n");
goto out;
}
pcie_cap = pci_pcie_cap(dev->pdev);
for (i = 0; i < 64; ++i) {
if (i == 22 || i == 23)
continue;
if (pci_read_config_dword(dev->pdev, i * 4, hca_header + i)) {
err = -ENODEV;
mlx4_err(dev, "Couldn't save HCA "
"PCI header, aborting.\n");
goto out;
}
}
reset = ioremap(pci_resource_start(dev->pdev, 0) + MLX4_RESET_BASE,
MLX4_RESET_SIZE);
if (!reset) {
err = -ENOMEM;
mlx4_err(dev, "Couldn't map HCA reset register, aborting.\n");
goto out;
}
end = jiffies + MLX4_SEM_TIMEOUT_JIFFIES;
do {
sem = readl(reset + MLX4_SEM_OFFSET);
if (!sem)
break;
msleep(1);
} while (time_before(jiffies, end));
if (sem) {
mlx4_err(dev, "Failed to obtain HW semaphore, aborting\n");
err = -EAGAIN;
iounmap(reset);
goto out;
}
writel(MLX4_RESET_VALUE, reset + MLX4_RESET_OFFSET);
iounmap(reset);
msleep(1000);
end = jiffies + MLX4_RESET_TIMEOUT_JIFFIES;
do {
if (!pci_read_config_word(dev->pdev, PCI_VENDOR_ID, &vendor) &&
vendor != 0xffff)
break;
msleep(1);
} while (time_before(jiffies, end));
if (vendor == 0xffff) {
err = -ENODEV;
mlx4_err(dev, "PCI device did not come back after reset, "
"aborting.\n");
goto out;
}
if (pcie_cap) {
devctl = hca_header[(pcie_cap + PCI_EXP_DEVCTL) / 4];
if (pcie_capability_write_word(dev->pdev, PCI_EXP_DEVCTL,
devctl)) {
err = -ENODEV;
mlx4_err(dev, "Couldn't restore HCA PCI Express "
"Device Control register, aborting.\n");
goto out;
}
linkctl = hca_header[(pcie_cap + PCI_EXP_LNKCTL) / 4];
if (pcie_capability_write_word(dev->pdev, PCI_EXP_LNKCTL,
linkctl)) {
err = -ENODEV;
mlx4_err(dev, "Couldn't restore HCA PCI Express "
"Link control register, aborting.\n");
goto out;
}
}
for (i = 0; i < 16; ++i) {
if (i * 4 == PCI_COMMAND)
continue;
if (pci_write_config_dword(dev->pdev, i * 4, hca_header[i])) {
err = -ENODEV;
mlx4_err(dev, "Couldn't restore HCA reg %x, "
"aborting.\n", i);
goto out;
}
}
if (pci_write_config_dword(dev->pdev, PCI_COMMAND,
hca_header[PCI_COMMAND / 4])) {
err = -ENODEV;
mlx4_err(dev, "Couldn't restore HCA COMMAND, "
"aborting.\n");
goto out;
}
out:
kfree(hca_header);
return err;
}
