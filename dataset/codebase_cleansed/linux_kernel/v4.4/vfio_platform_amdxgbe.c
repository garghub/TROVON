static unsigned int xmdio_read(void *ioaddr, unsigned int mmd,
unsigned int reg)
{
unsigned int mmd_address, value;
mmd_address = (mmd << 16) | ((reg) & 0xffff);
iowrite32(mmd_address >> 8, ioaddr + (PCS_MMD_SELECT << 2));
value = ioread32(ioaddr + ((mmd_address & 0xff) << 2));
return value;
}
static void xmdio_write(void *ioaddr, unsigned int mmd,
unsigned int reg, unsigned int value)
{
unsigned int mmd_address;
mmd_address = (mmd << 16) | ((reg) & 0xffff);
iowrite32(mmd_address >> 8, ioaddr + (PCS_MMD_SELECT << 2));
iowrite32(value, ioaddr + ((mmd_address & 0xff) << 2));
}
int vfio_platform_amdxgbe_reset(struct vfio_platform_device *vdev)
{
struct vfio_platform_region *xgmac_regs = &vdev->regions[0];
struct vfio_platform_region *xpcs_regs = &vdev->regions[1];
u32 dma_mr_value, pcs_value, value;
unsigned int count;
if (!xgmac_regs->ioaddr) {
xgmac_regs->ioaddr =
ioremap_nocache(xgmac_regs->addr, xgmac_regs->size);
if (!xgmac_regs->ioaddr)
return -ENOMEM;
}
if (!xpcs_regs->ioaddr) {
xpcs_regs->ioaddr =
ioremap_nocache(xpcs_regs->addr, xpcs_regs->size);
if (!xpcs_regs->ioaddr)
return -ENOMEM;
}
pcs_value = xmdio_read(xpcs_regs->ioaddr, MDIO_MMD_PCS, MDIO_CTRL1);
pcs_value |= MDIO_CTRL1_RESET;
xmdio_write(xpcs_regs->ioaddr, MDIO_MMD_PCS, MDIO_CTRL1, pcs_value);
count = 50;
do {
msleep(20);
pcs_value = xmdio_read(xpcs_regs->ioaddr, MDIO_MMD_PCS,
MDIO_CTRL1);
} while ((pcs_value & MDIO_CTRL1_RESET) && --count);
if (pcs_value & MDIO_CTRL1_RESET)
pr_warn("%s XGBE PHY reset timeout\n", __func__);
value = xmdio_read(xpcs_regs->ioaddr, MDIO_MMD_AN, MDIO_CTRL1);
value &= ~MDIO_AN_CTRL1_ENABLE;
xmdio_write(xpcs_regs->ioaddr, MDIO_MMD_AN, MDIO_CTRL1, value);
xmdio_write(xpcs_regs->ioaddr, MDIO_MMD_AN, MDIO_AN_INTMASK, 0);
xmdio_write(xpcs_regs->ioaddr, MDIO_MMD_AN, MDIO_AN_INT, 0);
dma_mr_value = ioread32(xgmac_regs->ioaddr + DMA_MR);
dma_mr_value |= 0x1;
iowrite32(dma_mr_value, xgmac_regs->ioaddr + DMA_MR);
usleep_range(10, 15);
count = 2000;
while (count-- && (ioread32(xgmac_regs->ioaddr + DMA_MR) & 1))
usleep_range(500, 600);
if (!count)
pr_warn("%s MAC SW reset failed\n", __func__);
return 0;
}
