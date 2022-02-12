static int vfio_user_config_read(struct pci_dev *pdev, int offset,
__le32 *val, int count)
{
int ret = -EINVAL;
u32 tmp_val = 0;
switch (count) {
case 1:
{
u8 tmp;
ret = pci_user_read_config_byte(pdev, offset, &tmp);
tmp_val = tmp;
break;
}
case 2:
{
u16 tmp;
ret = pci_user_read_config_word(pdev, offset, &tmp);
tmp_val = tmp;
break;
}
case 4:
ret = pci_user_read_config_dword(pdev, offset, &tmp_val);
break;
}
*val = cpu_to_le32(tmp_val);
return pcibios_err_to_errno(ret);
}
static int vfio_user_config_write(struct pci_dev *pdev, int offset,
__le32 val, int count)
{
int ret = -EINVAL;
u32 tmp_val = le32_to_cpu(val);
switch (count) {
case 1:
ret = pci_user_write_config_byte(pdev, offset, tmp_val);
break;
case 2:
ret = pci_user_write_config_word(pdev, offset, tmp_val);
break;
case 4:
ret = pci_user_write_config_dword(pdev, offset, tmp_val);
break;
}
return pcibios_err_to_errno(ret);
}
static int vfio_default_config_read(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 *val)
{
__le32 virt = 0;
memcpy(val, vdev->vconfig + pos, count);
memcpy(&virt, perm->virt + offset, count);
if (cpu_to_le32(~0U >> (32 - (count * 8))) != virt) {
struct pci_dev *pdev = vdev->pdev;
__le32 phys_val = 0;
int ret;
ret = vfio_user_config_read(pdev, pos, &phys_val, count);
if (ret)
return ret;
*val = (phys_val & ~virt) | (*val & virt);
}
return count;
}
static int vfio_default_config_write(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 val)
{
__le32 virt = 0, write = 0;
memcpy(&write, perm->write + offset, count);
if (!write)
return count;
memcpy(&virt, perm->virt + offset, count);
if (write & virt) {
__le32 virt_val = 0;
memcpy(&virt_val, vdev->vconfig + pos, count);
virt_val &= ~(write & virt);
virt_val |= (val & (write & virt));
memcpy(vdev->vconfig + pos, &virt_val, count);
}
if (write & ~virt) {
struct pci_dev *pdev = vdev->pdev;
__le32 phys_val = 0;
int ret;
ret = vfio_user_config_read(pdev, pos, &phys_val, count);
if (ret)
return ret;
phys_val &= ~(write & ~virt);
phys_val |= (val & (write & ~virt));
ret = vfio_user_config_write(pdev, pos, phys_val, count);
if (ret)
return ret;
}
return count;
}
static int vfio_direct_config_read(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 *val)
{
int ret;
ret = vfio_user_config_read(vdev->pdev, pos, val, count);
if (ret)
return pcibios_err_to_errno(ret);
if (pos >= PCI_CFG_SPACE_SIZE) {
if (offset < 4)
memcpy(val, vdev->vconfig + pos, count);
} else if (pos >= PCI_STD_HEADER_SIZEOF) {
if (offset == PCI_CAP_LIST_ID && count > 1)
memcpy(val, vdev->vconfig + pos,
min(PCI_CAP_FLAGS, count));
else if (offset == PCI_CAP_LIST_NEXT)
memcpy(val, vdev->vconfig + pos, 1);
}
return count;
}
static int vfio_raw_config_write(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 val)
{
int ret;
ret = vfio_user_config_write(vdev->pdev, pos, val, count);
if (ret)
return ret;
return count;
}
static int vfio_raw_config_read(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 *val)
{
int ret;
ret = vfio_user_config_read(vdev->pdev, pos, val, count);
if (ret)
return pcibios_err_to_errno(ret);
return count;
}
static int vfio_virt_config_write(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 val)
{
memcpy(vdev->vconfig + pos, &val, count);
return count;
}
static int vfio_virt_config_read(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 *val)
{
memcpy(val, vdev->vconfig + pos, count);
return count;
}
static void free_perm_bits(struct perm_bits *perm)
{
kfree(perm->virt);
kfree(perm->write);
perm->virt = NULL;
perm->write = NULL;
}
static int alloc_perm_bits(struct perm_bits *perm, int size)
{
size = round_up(size, 4);
perm->virt = kzalloc(size, GFP_KERNEL);
perm->write = kzalloc(size, GFP_KERNEL);
if (!perm->virt || !perm->write) {
free_perm_bits(perm);
return -ENOMEM;
}
perm->readfn = vfio_default_config_read;
perm->writefn = vfio_default_config_write;
return 0;
}
static inline void p_setb(struct perm_bits *p, int off, u8 virt, u8 write)
{
p->virt[off] = virt;
p->write[off] = write;
}
static inline void p_setw(struct perm_bits *p, int off, u16 virt, u16 write)
{
*(__le16 *)(&p->virt[off]) = cpu_to_le16(virt);
*(__le16 *)(&p->write[off]) = cpu_to_le16(write);
}
static inline void p_setd(struct perm_bits *p, int off, u32 virt, u32 write)
{
*(__le32 *)(&p->virt[off]) = cpu_to_le32(virt);
*(__le32 *)(&p->write[off]) = cpu_to_le32(write);
}
static void vfio_bar_restore(struct vfio_pci_device *vdev)
{
struct pci_dev *pdev = vdev->pdev;
u32 *rbar = vdev->rbar;
int i;
if (pdev->is_virtfn)
return;
pr_info("%s: %s reset recovery - restoring bars\n",
__func__, dev_name(&pdev->dev));
for (i = PCI_BASE_ADDRESS_0; i <= PCI_BASE_ADDRESS_5; i += 4, rbar++)
pci_user_write_config_dword(pdev, i, *rbar);
pci_user_write_config_dword(pdev, PCI_ROM_ADDRESS, *rbar);
}
static __le32 vfio_generate_bar_flags(struct pci_dev *pdev, int bar)
{
unsigned long flags = pci_resource_flags(pdev, bar);
u32 val;
if (flags & IORESOURCE_IO)
return cpu_to_le32(PCI_BASE_ADDRESS_SPACE_IO);
val = PCI_BASE_ADDRESS_SPACE_MEMORY;
if (flags & IORESOURCE_PREFETCH)
val |= PCI_BASE_ADDRESS_MEM_PREFETCH;
if (flags & IORESOURCE_MEM_64)
val |= PCI_BASE_ADDRESS_MEM_TYPE_64;
return cpu_to_le32(val);
}
static void vfio_bar_fixup(struct vfio_pci_device *vdev)
{
struct pci_dev *pdev = vdev->pdev;
int i;
__le32 *bar;
u64 mask;
bar = (__le32 *)&vdev->vconfig[PCI_BASE_ADDRESS_0];
for (i = PCI_STD_RESOURCES; i <= PCI_STD_RESOURCE_END; i++, bar++) {
if (!pci_resource_start(pdev, i)) {
*bar = 0;
continue;
}
mask = ~(pci_resource_len(pdev, i) - 1);
*bar &= cpu_to_le32((u32)mask);
*bar |= vfio_generate_bar_flags(pdev, i);
if (*bar & cpu_to_le32(PCI_BASE_ADDRESS_MEM_TYPE_64)) {
bar++;
*bar &= cpu_to_le32((u32)(mask >> 32));
i++;
}
}
bar = (__le32 *)&vdev->vconfig[PCI_ROM_ADDRESS];
if (pci_resource_start(pdev, PCI_ROM_RESOURCE)) {
mask = ~(pci_resource_len(pdev, PCI_ROM_RESOURCE) - 1);
mask |= PCI_ROM_ADDRESS_ENABLE;
*bar &= cpu_to_le32((u32)mask);
} else if (pdev->resource[PCI_ROM_RESOURCE].flags &
IORESOURCE_ROM_SHADOW) {
mask = ~(0x20000 - 1);
mask |= PCI_ROM_ADDRESS_ENABLE;
*bar &= cpu_to_le32((u32)mask);
} else
*bar = 0;
vdev->bardirty = false;
}
static int vfio_basic_config_read(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 *val)
{
if (is_bar(offset))
vfio_bar_fixup(vdev);
count = vfio_default_config_read(vdev, pos, count, perm, offset, val);
if (offset == PCI_COMMAND && vdev->pdev->is_virtfn) {
u16 cmd = le16_to_cpu(*(__le16 *)&vdev->vconfig[PCI_COMMAND]);
u32 tmp_val = le32_to_cpu(*val);
tmp_val |= cmd & PCI_COMMAND_MEMORY;
*val = cpu_to_le32(tmp_val);
}
return count;
}
static int vfio_basic_config_write(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 val)
{
struct pci_dev *pdev = vdev->pdev;
__le16 *virt_cmd;
u16 new_cmd = 0;
int ret;
virt_cmd = (__le16 *)&vdev->vconfig[PCI_COMMAND];
if (offset == PCI_COMMAND) {
bool phys_mem, virt_mem, new_mem, phys_io, virt_io, new_io;
u16 phys_cmd;
ret = pci_user_read_config_word(pdev, PCI_COMMAND, &phys_cmd);
if (ret)
return ret;
new_cmd = le32_to_cpu(val);
phys_mem = !!(phys_cmd & PCI_COMMAND_MEMORY);
virt_mem = !!(le16_to_cpu(*virt_cmd) & PCI_COMMAND_MEMORY);
new_mem = !!(new_cmd & PCI_COMMAND_MEMORY);
phys_io = !!(phys_cmd & PCI_COMMAND_IO);
virt_io = !!(le16_to_cpu(*virt_cmd) & PCI_COMMAND_IO);
new_io = !!(new_cmd & PCI_COMMAND_IO);
if ((new_mem && virt_mem && !phys_mem) ||
(new_io && virt_io && !phys_io))
vfio_bar_restore(vdev);
}
count = vfio_default_config_write(vdev, pos, count, perm, offset, val);
if (count < 0)
return count;
if (offset == PCI_COMMAND) {
u16 mask = PCI_COMMAND_MEMORY | PCI_COMMAND_IO;
*virt_cmd &= cpu_to_le16(~mask);
*virt_cmd |= cpu_to_le16(new_cmd & mask);
}
if (offset >= PCI_COMMAND && offset <= PCI_COMMAND + 1) {
bool virt_intx_disable;
virt_intx_disable = !!(le16_to_cpu(*virt_cmd) &
PCI_COMMAND_INTX_DISABLE);
if (virt_intx_disable && !vdev->virq_disabled) {
vdev->virq_disabled = true;
vfio_pci_intx_mask(vdev);
} else if (!virt_intx_disable && vdev->virq_disabled) {
vdev->virq_disabled = false;
vfio_pci_intx_unmask(vdev);
}
}
if (is_bar(offset))
vdev->bardirty = true;
return count;
}
static int __init init_pci_cap_basic_perm(struct perm_bits *perm)
{
if (alloc_perm_bits(perm, PCI_STD_HEADER_SIZEOF))
return -ENOMEM;
perm->readfn = vfio_basic_config_read;
perm->writefn = vfio_basic_config_write;
p_setw(perm, PCI_VENDOR_ID, (u16)ALL_VIRT, NO_WRITE);
p_setw(perm, PCI_DEVICE_ID, (u16)ALL_VIRT, NO_WRITE);
p_setw(perm, PCI_COMMAND, PCI_COMMAND_INTX_DISABLE, (u16)ALL_WRITE);
p_setw(perm, PCI_STATUS, PCI_STATUS_CAP_LIST, NO_WRITE);
p_setb(perm, PCI_CACHE_LINE_SIZE, NO_VIRT, (u8)ALL_WRITE);
p_setb(perm, PCI_LATENCY_TIMER, NO_VIRT, (u8)ALL_WRITE);
p_setb(perm, PCI_BIST, NO_VIRT, (u8)ALL_WRITE);
p_setd(perm, PCI_BASE_ADDRESS_0, ALL_VIRT, ALL_WRITE);
p_setd(perm, PCI_BASE_ADDRESS_1, ALL_VIRT, ALL_WRITE);
p_setd(perm, PCI_BASE_ADDRESS_2, ALL_VIRT, ALL_WRITE);
p_setd(perm, PCI_BASE_ADDRESS_3, ALL_VIRT, ALL_WRITE);
p_setd(perm, PCI_BASE_ADDRESS_4, ALL_VIRT, ALL_WRITE);
p_setd(perm, PCI_BASE_ADDRESS_5, ALL_VIRT, ALL_WRITE);
p_setd(perm, PCI_ROM_ADDRESS, ALL_VIRT, ALL_WRITE);
p_setb(perm, PCI_CAPABILITY_LIST, (u8)ALL_VIRT, NO_WRITE);
p_setb(perm, PCI_INTERRUPT_LINE, (u8)ALL_VIRT, (u8)ALL_WRITE);
p_setb(perm, PCI_INTERRUPT_PIN, (u8)ALL_VIRT, (u8)NO_WRITE);
return 0;
}
static int vfio_pm_config_write(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 val)
{
count = vfio_default_config_write(vdev, pos, count, perm, offset, val);
if (count < 0)
return count;
if (offset == PCI_PM_CTRL) {
pci_power_t state;
switch (le32_to_cpu(val) & PCI_PM_CTRL_STATE_MASK) {
case 0:
state = PCI_D0;
break;
case 1:
state = PCI_D1;
break;
case 2:
state = PCI_D2;
break;
case 3:
state = PCI_D3hot;
break;
}
pci_set_power_state(vdev->pdev, state);
}
return count;
}
static int __init init_pci_cap_pm_perm(struct perm_bits *perm)
{
if (alloc_perm_bits(perm, pci_cap_length[PCI_CAP_ID_PM]))
return -ENOMEM;
perm->writefn = vfio_pm_config_write;
p_setb(perm, PCI_CAP_LIST_NEXT, (u8)ALL_VIRT, NO_WRITE);
p_setd(perm, PCI_PM_CTRL, NO_VIRT, ~PCI_PM_CTRL_STATE_MASK);
return 0;
}
static int vfio_vpd_config_write(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 val)
{
struct pci_dev *pdev = vdev->pdev;
__le16 *paddr = (__le16 *)(vdev->vconfig + pos - offset + PCI_VPD_ADDR);
__le32 *pdata = (__le32 *)(vdev->vconfig + pos - offset + PCI_VPD_DATA);
u16 addr;
u32 data;
count = vfio_default_config_write(vdev, pos, count, perm, offset, val);
if (count < 0 || offset > PCI_VPD_ADDR + 1 ||
offset + count <= PCI_VPD_ADDR + 1)
return count;
addr = le16_to_cpu(*paddr);
if (addr & PCI_VPD_ADDR_F) {
data = le32_to_cpu(*pdata);
if (pci_write_vpd(pdev, addr & ~PCI_VPD_ADDR_F, 4, &data) != 4)
return count;
} else {
if (pci_read_vpd(pdev, addr, 4, &data) != 4)
return count;
*pdata = cpu_to_le32(data);
}
addr ^= PCI_VPD_ADDR_F;
*paddr = cpu_to_le16(addr);
return count;
}
static int __init init_pci_cap_vpd_perm(struct perm_bits *perm)
{
if (alloc_perm_bits(perm, pci_cap_length[PCI_CAP_ID_VPD]))
return -ENOMEM;
perm->writefn = vfio_vpd_config_write;
p_setb(perm, PCI_CAP_LIST_NEXT, (u8)ALL_VIRT, NO_WRITE);
p_setw(perm, PCI_VPD_ADDR, (u16)ALL_VIRT, (u16)ALL_WRITE);
p_setd(perm, PCI_VPD_DATA, ALL_VIRT, ALL_WRITE);
return 0;
}
static int __init init_pci_cap_pcix_perm(struct perm_bits *perm)
{
if (alloc_perm_bits(perm, PCI_CAP_PCIX_SIZEOF_V2))
return -ENOMEM;
p_setb(perm, PCI_CAP_LIST_NEXT, (u8)ALL_VIRT, NO_WRITE);
p_setw(perm, PCI_X_CMD, NO_VIRT, (u16)ALL_WRITE);
p_setd(perm, PCI_X_ECC_CSR, NO_VIRT, ALL_WRITE);
return 0;
}
static int __init init_pci_cap_exp_perm(struct perm_bits *perm)
{
if (alloc_perm_bits(perm, PCI_CAP_EXP_ENDPOINT_SIZEOF_V2))
return -ENOMEM;
p_setb(perm, PCI_CAP_LIST_NEXT, (u8)ALL_VIRT, NO_WRITE);
p_setw(perm, PCI_EXP_DEVCTL, NO_VIRT, ~PCI_EXP_DEVCTL_PHANTOM);
p_setw(perm, PCI_EXP_DEVCTL2, NO_VIRT, ~PCI_EXP_DEVCTL2_ARI);
return 0;
}
static int __init init_pci_cap_af_perm(struct perm_bits *perm)
{
if (alloc_perm_bits(perm, pci_cap_length[PCI_CAP_ID_AF]))
return -ENOMEM;
p_setb(perm, PCI_CAP_LIST_NEXT, (u8)ALL_VIRT, NO_WRITE);
p_setb(perm, PCI_AF_CTRL, NO_VIRT, PCI_AF_CTRL_FLR);
return 0;
}
static int __init init_pci_ext_cap_err_perm(struct perm_bits *perm)
{
u32 mask;
if (alloc_perm_bits(perm, pci_ext_cap_length[PCI_EXT_CAP_ID_ERR]))
return -ENOMEM;
p_setd(perm, 0, ALL_VIRT, NO_WRITE);
mask = PCI_ERR_UNC_UND |
PCI_ERR_UNC_DLP |
PCI_ERR_UNC_SURPDN |
PCI_ERR_UNC_POISON_TLP |
PCI_ERR_UNC_FCP |
PCI_ERR_UNC_COMP_TIME |
PCI_ERR_UNC_COMP_ABORT |
PCI_ERR_UNC_UNX_COMP |
PCI_ERR_UNC_RX_OVER |
PCI_ERR_UNC_MALF_TLP |
PCI_ERR_UNC_ECRC |
PCI_ERR_UNC_UNSUP |
PCI_ERR_UNC_ACSV |
PCI_ERR_UNC_INTN |
PCI_ERR_UNC_MCBTLP |
PCI_ERR_UNC_ATOMEG |
PCI_ERR_UNC_TLPPRE;
p_setd(perm, PCI_ERR_UNCOR_STATUS, NO_VIRT, mask);
p_setd(perm, PCI_ERR_UNCOR_MASK, NO_VIRT, mask);
p_setd(perm, PCI_ERR_UNCOR_SEVER, NO_VIRT, mask);
mask = PCI_ERR_COR_RCVR |
PCI_ERR_COR_BAD_TLP |
PCI_ERR_COR_BAD_DLLP |
PCI_ERR_COR_REP_ROLL |
PCI_ERR_COR_REP_TIMER |
PCI_ERR_COR_ADV_NFAT |
PCI_ERR_COR_INTERNAL |
PCI_ERR_COR_LOG_OVER;
p_setd(perm, PCI_ERR_COR_STATUS, NO_VIRT, mask);
p_setd(perm, PCI_ERR_COR_MASK, NO_VIRT, mask);
mask = PCI_ERR_CAP_ECRC_GENE |
PCI_ERR_CAP_ECRC_CHKE;
p_setd(perm, PCI_ERR_CAP, NO_VIRT, mask);
return 0;
}
static int __init init_pci_ext_cap_pwr_perm(struct perm_bits *perm)
{
if (alloc_perm_bits(perm, pci_ext_cap_length[PCI_EXT_CAP_ID_PWR]))
return -ENOMEM;
p_setd(perm, 0, ALL_VIRT, NO_WRITE);
p_setb(perm, PCI_PWR_DATA, NO_VIRT, (u8)ALL_WRITE);
return 0;
}
void vfio_pci_uninit_perm_bits(void)
{
free_perm_bits(&cap_perms[PCI_CAP_ID_BASIC]);
free_perm_bits(&cap_perms[PCI_CAP_ID_PM]);
free_perm_bits(&cap_perms[PCI_CAP_ID_VPD]);
free_perm_bits(&cap_perms[PCI_CAP_ID_PCIX]);
free_perm_bits(&cap_perms[PCI_CAP_ID_EXP]);
free_perm_bits(&cap_perms[PCI_CAP_ID_AF]);
free_perm_bits(&ecap_perms[PCI_EXT_CAP_ID_ERR]);
free_perm_bits(&ecap_perms[PCI_EXT_CAP_ID_PWR]);
}
int __init vfio_pci_init_perm_bits(void)
{
int ret;
ret = init_pci_cap_basic_perm(&cap_perms[PCI_CAP_ID_BASIC]);
ret |= init_pci_cap_pm_perm(&cap_perms[PCI_CAP_ID_PM]);
ret |= init_pci_cap_vpd_perm(&cap_perms[PCI_CAP_ID_VPD]);
ret |= init_pci_cap_pcix_perm(&cap_perms[PCI_CAP_ID_PCIX]);
cap_perms[PCI_CAP_ID_VNDR].writefn = vfio_raw_config_write;
ret |= init_pci_cap_exp_perm(&cap_perms[PCI_CAP_ID_EXP]);
ret |= init_pci_cap_af_perm(&cap_perms[PCI_CAP_ID_AF]);
ret |= init_pci_ext_cap_err_perm(&ecap_perms[PCI_EXT_CAP_ID_ERR]);
ret |= init_pci_ext_cap_pwr_perm(&ecap_perms[PCI_EXT_CAP_ID_PWR]);
ecap_perms[PCI_EXT_CAP_ID_VNDR].writefn = vfio_raw_config_write;
if (ret)
vfio_pci_uninit_perm_bits();
return ret;
}
static int vfio_find_cap_start(struct vfio_pci_device *vdev, int pos)
{
u8 cap;
int base = (pos >= PCI_CFG_SPACE_SIZE) ? PCI_CFG_SPACE_SIZE :
PCI_STD_HEADER_SIZEOF;
cap = vdev->pci_config_map[pos];
if (cap == PCI_CAP_ID_BASIC)
return 0;
while (pos - 1 >= base && vdev->pci_config_map[pos - 1] == cap)
pos--;
return pos;
}
static int vfio_msi_config_read(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 *val)
{
if (offset <= PCI_MSI_FLAGS && offset + count >= PCI_MSI_FLAGS) {
__le16 *flags;
int start;
start = vfio_find_cap_start(vdev, pos);
flags = (__le16 *)&vdev->vconfig[start];
*flags &= cpu_to_le16(~PCI_MSI_FLAGS_QMASK);
*flags |= cpu_to_le16(vdev->msi_qmax << 1);
}
return vfio_default_config_read(vdev, pos, count, perm, offset, val);
}
static int vfio_msi_config_write(struct vfio_pci_device *vdev, int pos,
int count, struct perm_bits *perm,
int offset, __le32 val)
{
count = vfio_default_config_write(vdev, pos, count, perm, offset, val);
if (count < 0)
return count;
if (offset <= PCI_MSI_FLAGS && offset + count >= PCI_MSI_FLAGS) {
__le16 *pflags;
u16 flags;
int start, ret;
start = vfio_find_cap_start(vdev, pos);
pflags = (__le16 *)&vdev->vconfig[start + PCI_MSI_FLAGS];
flags = le16_to_cpu(*pflags);
if (!is_msi(vdev))
flags &= ~PCI_MSI_FLAGS_ENABLE;
if ((flags & PCI_MSI_FLAGS_QSIZE) >> 4 > vdev->msi_qmax) {
flags &= ~PCI_MSI_FLAGS_QSIZE;
flags |= vdev->msi_qmax << 4;
}
*pflags = cpu_to_le16(flags);
ret = pci_user_write_config_word(vdev->pdev,
start + PCI_MSI_FLAGS,
flags);
if (ret)
return pcibios_err_to_errno(ret);
}
return count;
}
static int init_pci_cap_msi_perm(struct perm_bits *perm, int len, u16 flags)
{
if (alloc_perm_bits(perm, len))
return -ENOMEM;
perm->readfn = vfio_msi_config_read;
perm->writefn = vfio_msi_config_write;
p_setb(perm, PCI_CAP_LIST_NEXT, (u8)ALL_VIRT, NO_WRITE);
p_setb(perm, PCI_MSI_FLAGS, (u8)ALL_VIRT, (u8)ALL_WRITE);
p_setd(perm, PCI_MSI_ADDRESS_LO, ALL_VIRT, ALL_WRITE);
if (flags & PCI_MSI_FLAGS_64BIT) {
p_setd(perm, PCI_MSI_ADDRESS_HI, ALL_VIRT, ALL_WRITE);
p_setw(perm, PCI_MSI_DATA_64, (u16)ALL_VIRT, (u16)ALL_WRITE);
if (flags & PCI_MSI_FLAGS_MASKBIT) {
p_setd(perm, PCI_MSI_MASK_64, NO_VIRT, ALL_WRITE);
p_setd(perm, PCI_MSI_PENDING_64, NO_VIRT, ALL_WRITE);
}
} else {
p_setw(perm, PCI_MSI_DATA_32, (u16)ALL_VIRT, (u16)ALL_WRITE);
if (flags & PCI_MSI_FLAGS_MASKBIT) {
p_setd(perm, PCI_MSI_MASK_32, NO_VIRT, ALL_WRITE);
p_setd(perm, PCI_MSI_PENDING_32, NO_VIRT, ALL_WRITE);
}
}
return 0;
}
static int vfio_msi_cap_len(struct vfio_pci_device *vdev, u8 pos)
{
struct pci_dev *pdev = vdev->pdev;
int len, ret;
u16 flags;
ret = pci_read_config_word(pdev, pos + PCI_MSI_FLAGS, &flags);
if (ret)
return pcibios_err_to_errno(ret);
len = 10;
if (flags & PCI_MSI_FLAGS_64BIT)
len += 4;
if (flags & PCI_MSI_FLAGS_MASKBIT)
len += 10;
if (vdev->msi_perm)
return len;
vdev->msi_perm = kmalloc(sizeof(struct perm_bits), GFP_KERNEL);
if (!vdev->msi_perm)
return -ENOMEM;
ret = init_pci_cap_msi_perm(vdev->msi_perm, len, flags);
if (ret)
return ret;
return len;
}
static int vfio_vc_cap_len(struct vfio_pci_device *vdev, u16 pos)
{
struct pci_dev *pdev = vdev->pdev;
u32 tmp;
int ret, evcc, phases, vc_arb;
int len = PCI_CAP_VC_BASE_SIZEOF;
ret = pci_read_config_dword(pdev, pos + PCI_VC_PORT_CAP1, &tmp);
if (ret)
return pcibios_err_to_errno(ret);
evcc = tmp & PCI_VC_CAP1_EVCC;
ret = pci_read_config_dword(pdev, pos + PCI_VC_PORT_CAP2, &tmp);
if (ret)
return pcibios_err_to_errno(ret);
if (tmp & PCI_VC_CAP2_128_PHASE)
phases = 128;
else if (tmp & PCI_VC_CAP2_64_PHASE)
phases = 64;
else if (tmp & PCI_VC_CAP2_32_PHASE)
phases = 32;
else
phases = 0;
vc_arb = phases * 4;
len += (1 + evcc) * PCI_CAP_VC_PER_VC_SIZEOF;
if (vc_arb) {
len = round_up(len, 16);
len += vc_arb / 8;
}
return len;
}
static int vfio_cap_len(struct vfio_pci_device *vdev, u8 cap, u8 pos)
{
struct pci_dev *pdev = vdev->pdev;
u32 dword;
u16 word;
u8 byte;
int ret;
switch (cap) {
case PCI_CAP_ID_MSI:
return vfio_msi_cap_len(vdev, pos);
case PCI_CAP_ID_PCIX:
ret = pci_read_config_word(pdev, pos + PCI_X_CMD, &word);
if (ret)
return pcibios_err_to_errno(ret);
if (PCI_X_CMD_VERSION(word)) {
pci_read_config_dword(pdev, PCI_CFG_SPACE_SIZE, &dword);
vdev->extended_caps = (dword != 0);
return PCI_CAP_PCIX_SIZEOF_V2;
} else
return PCI_CAP_PCIX_SIZEOF_V0;
case PCI_CAP_ID_VNDR:
ret = pci_read_config_byte(pdev, pos + PCI_CAP_FLAGS, &byte);
if (ret)
return pcibios_err_to_errno(ret);
return byte;
case PCI_CAP_ID_EXP:
pci_read_config_dword(pdev, PCI_CFG_SPACE_SIZE, &dword);
vdev->extended_caps = (dword != 0);
if ((pcie_caps_reg(pdev) & PCI_EXP_FLAGS_VERS) == 1)
return PCI_CAP_EXP_ENDPOINT_SIZEOF_V1;
else
return PCI_CAP_EXP_ENDPOINT_SIZEOF_V2;
case PCI_CAP_ID_HT:
ret = pci_read_config_byte(pdev, pos + 3, &byte);
if (ret)
return pcibios_err_to_errno(ret);
return (byte & HT_3BIT_CAP_MASK) ?
HT_CAP_SIZEOF_SHORT : HT_CAP_SIZEOF_LONG;
case PCI_CAP_ID_SATA:
ret = pci_read_config_byte(pdev, pos + PCI_SATA_REGS, &byte);
if (ret)
return pcibios_err_to_errno(ret);
byte &= PCI_SATA_REGS_MASK;
if (byte == PCI_SATA_REGS_INLINE)
return PCI_SATA_SIZEOF_LONG;
else
return PCI_SATA_SIZEOF_SHORT;
default:
pr_warn("%s: %s unknown length for pci cap 0x%x@0x%x\n",
dev_name(&pdev->dev), __func__, cap, pos);
}
return 0;
}
static int vfio_ext_cap_len(struct vfio_pci_device *vdev, u16 ecap, u16 epos)
{
struct pci_dev *pdev = vdev->pdev;
u8 byte;
u32 dword;
int ret;
switch (ecap) {
case PCI_EXT_CAP_ID_VNDR:
ret = pci_read_config_dword(pdev, epos + PCI_VSEC_HDR, &dword);
if (ret)
return pcibios_err_to_errno(ret);
return dword >> PCI_VSEC_HDR_LEN_SHIFT;
case PCI_EXT_CAP_ID_VC:
case PCI_EXT_CAP_ID_VC9:
case PCI_EXT_CAP_ID_MFVC:
return vfio_vc_cap_len(vdev, epos);
case PCI_EXT_CAP_ID_ACS:
ret = pci_read_config_byte(pdev, epos + PCI_ACS_CAP, &byte);
if (ret)
return pcibios_err_to_errno(ret);
if (byte & PCI_ACS_EC) {
int bits;
ret = pci_read_config_byte(pdev,
epos + PCI_ACS_EGRESS_BITS,
&byte);
if (ret)
return pcibios_err_to_errno(ret);
bits = byte ? round_up(byte, 32) : 256;
return 8 + (bits / 8);
}
return 8;
case PCI_EXT_CAP_ID_REBAR:
ret = pci_read_config_byte(pdev, epos + PCI_REBAR_CTRL, &byte);
if (ret)
return pcibios_err_to_errno(ret);
byte &= PCI_REBAR_CTRL_NBAR_MASK;
byte >>= PCI_REBAR_CTRL_NBAR_SHIFT;
return 4 + (byte * 8);
case PCI_EXT_CAP_ID_DPA:
ret = pci_read_config_byte(pdev, epos + PCI_DPA_CAP, &byte);
if (ret)
return pcibios_err_to_errno(ret);
byte &= PCI_DPA_CAP_SUBSTATE_MASK;
return PCI_DPA_BASE_SIZEOF + byte + 1;
case PCI_EXT_CAP_ID_TPH:
ret = pci_read_config_dword(pdev, epos + PCI_TPH_CAP, &dword);
if (ret)
return pcibios_err_to_errno(ret);
if ((dword & PCI_TPH_CAP_LOC_MASK) == PCI_TPH_LOC_CAP) {
int sts;
sts = dword & PCI_TPH_CAP_ST_MASK;
sts >>= PCI_TPH_CAP_ST_SHIFT;
return PCI_TPH_BASE_SIZEOF + (sts * 2) + 2;
}
return PCI_TPH_BASE_SIZEOF;
default:
pr_warn("%s: %s unknown length for pci ecap 0x%x@0x%x\n",
dev_name(&pdev->dev), __func__, ecap, epos);
}
return 0;
}
static int vfio_fill_vconfig_bytes(struct vfio_pci_device *vdev,
int offset, int size)
{
struct pci_dev *pdev = vdev->pdev;
int ret = 0;
while (size) {
int filled;
if (size >= 4 && !(offset % 4)) {
__le32 *dwordp = (__le32 *)&vdev->vconfig[offset];
u32 dword;
ret = pci_read_config_dword(pdev, offset, &dword);
if (ret)
return ret;
*dwordp = cpu_to_le32(dword);
filled = 4;
} else if (size >= 2 && !(offset % 2)) {
__le16 *wordp = (__le16 *)&vdev->vconfig[offset];
u16 word;
ret = pci_read_config_word(pdev, offset, &word);
if (ret)
return ret;
*wordp = cpu_to_le16(word);
filled = 2;
} else {
u8 *byte = &vdev->vconfig[offset];
ret = pci_read_config_byte(pdev, offset, byte);
if (ret)
return ret;
filled = 1;
}
offset += filled;
size -= filled;
}
return ret;
}
static int vfio_cap_init(struct vfio_pci_device *vdev)
{
struct pci_dev *pdev = vdev->pdev;
u8 *map = vdev->pci_config_map;
u16 status;
u8 pos, *prev, cap;
int loops, ret, caps = 0;
ret = pci_read_config_word(pdev, PCI_STATUS, &status);
if (ret)
return ret;
if (!(status & PCI_STATUS_CAP_LIST))
return 0;
ret = pci_read_config_byte(pdev, PCI_CAPABILITY_LIST, &pos);
if (ret)
return ret;
prev = &vdev->vconfig[PCI_CAPABILITY_LIST];
loops = (PCI_CFG_SPACE_SIZE - PCI_STD_HEADER_SIZEOF) / PCI_CAP_SIZEOF;
while (pos && loops--) {
u8 next;
int i, len = 0;
ret = pci_read_config_byte(pdev, pos, &cap);
if (ret)
return ret;
ret = pci_read_config_byte(pdev,
pos + PCI_CAP_LIST_NEXT, &next);
if (ret)
return ret;
if (cap <= PCI_CAP_ID_MAX) {
len = pci_cap_length[cap];
if (len == 0xFF) {
len = vfio_cap_len(vdev, cap, pos);
if (len < 0)
return len;
}
}
if (!len) {
pr_info("%s: %s hiding cap 0x%x\n",
__func__, dev_name(&pdev->dev), cap);
*prev = next;
pos = next;
continue;
}
for (i = 0; i < len; i++) {
if (likely(map[pos + i] == PCI_CAP_ID_INVALID))
continue;
pr_warn("%s: %s pci config conflict @0x%x, was cap 0x%x now cap 0x%x\n",
__func__, dev_name(&pdev->dev),
pos + i, map[pos + i], cap);
}
BUILD_BUG_ON(PCI_CAP_ID_MAX >= PCI_CAP_ID_INVALID_VIRT);
memset(map + pos, cap, len);
ret = vfio_fill_vconfig_bytes(vdev, pos, len);
if (ret)
return ret;
prev = &vdev->vconfig[pos + PCI_CAP_LIST_NEXT];
pos = next;
caps++;
}
if (!caps) {
__le16 *vstatus = (__le16 *)&vdev->vconfig[PCI_STATUS];
*vstatus &= ~cpu_to_le16(PCI_STATUS_CAP_LIST);
}
return 0;
}
static int vfio_ecap_init(struct vfio_pci_device *vdev)
{
struct pci_dev *pdev = vdev->pdev;
u8 *map = vdev->pci_config_map;
u16 epos;
__le32 *prev = NULL;
int loops, ret, ecaps = 0;
if (!vdev->extended_caps)
return 0;
epos = PCI_CFG_SPACE_SIZE;
loops = (pdev->cfg_size - PCI_CFG_SPACE_SIZE) / PCI_CAP_SIZEOF;
while (loops-- && epos >= PCI_CFG_SPACE_SIZE) {
u32 header;
u16 ecap;
int i, len = 0;
bool hidden = false;
ret = pci_read_config_dword(pdev, epos, &header);
if (ret)
return ret;
ecap = PCI_EXT_CAP_ID(header);
if (ecap <= PCI_EXT_CAP_ID_MAX) {
len = pci_ext_cap_length[ecap];
if (len == 0xFF) {
len = vfio_ext_cap_len(vdev, ecap, epos);
if (len < 0)
return ret;
}
}
if (!len) {
pr_info("%s: %s hiding ecap 0x%x@0x%x\n",
__func__, dev_name(&pdev->dev), ecap, epos);
if (prev) {
u32 val = epos = PCI_EXT_CAP_NEXT(header);
*prev &= cpu_to_le32(~(0xffcU << 20));
*prev |= cpu_to_le32(val << 20);
continue;
}
len = PCI_CAP_SIZEOF;
hidden = true;
}
for (i = 0; i < len; i++) {
if (likely(map[epos + i] == PCI_CAP_ID_INVALID))
continue;
pr_warn("%s: %s pci config conflict @0x%x, was ecap 0x%x now ecap 0x%x\n",
__func__, dev_name(&pdev->dev),
epos + i, map[epos + i], ecap);
}
BUILD_BUG_ON(PCI_EXT_CAP_ID_MAX >= PCI_CAP_ID_INVALID_VIRT);
memset(map + epos, ecap, len);
ret = vfio_fill_vconfig_bytes(vdev, epos, len);
if (ret)
return ret;
if (hidden)
*(__le32 *)&vdev->vconfig[epos] &=
cpu_to_le32((0xffcU << 20));
else
ecaps++;
prev = (__le32 *)&vdev->vconfig[epos];
epos = PCI_EXT_CAP_NEXT(header);
}
if (!ecaps)
*(u32 *)&vdev->vconfig[PCI_CFG_SPACE_SIZE] = 0;
return 0;
}
int vfio_config_init(struct vfio_pci_device *vdev)
{
struct pci_dev *pdev = vdev->pdev;
u8 *map, *vconfig;
int ret;
map = kmalloc(pdev->cfg_size, GFP_KERNEL);
if (!map)
return -ENOMEM;
vconfig = kmalloc(pdev->cfg_size, GFP_KERNEL);
if (!vconfig) {
kfree(map);
return -ENOMEM;
}
vdev->pci_config_map = map;
vdev->vconfig = vconfig;
memset(map, PCI_CAP_ID_BASIC, PCI_STD_HEADER_SIZEOF);
memset(map + PCI_STD_HEADER_SIZEOF, PCI_CAP_ID_INVALID,
pdev->cfg_size - PCI_STD_HEADER_SIZEOF);
ret = vfio_fill_vconfig_bytes(vdev, 0, PCI_STD_HEADER_SIZEOF);
if (ret)
goto out;
vdev->bardirty = true;
vdev->rbar[0] = le32_to_cpu(*(__le32 *)&vconfig[PCI_BASE_ADDRESS_0]);
vdev->rbar[1] = le32_to_cpu(*(__le32 *)&vconfig[PCI_BASE_ADDRESS_1]);
vdev->rbar[2] = le32_to_cpu(*(__le32 *)&vconfig[PCI_BASE_ADDRESS_2]);
vdev->rbar[3] = le32_to_cpu(*(__le32 *)&vconfig[PCI_BASE_ADDRESS_3]);
vdev->rbar[4] = le32_to_cpu(*(__le32 *)&vconfig[PCI_BASE_ADDRESS_4]);
vdev->rbar[5] = le32_to_cpu(*(__le32 *)&vconfig[PCI_BASE_ADDRESS_5]);
vdev->rbar[6] = le32_to_cpu(*(__le32 *)&vconfig[PCI_ROM_ADDRESS]);
if (pdev->is_virtfn) {
*(__le16 *)&vconfig[PCI_VENDOR_ID] = cpu_to_le16(pdev->vendor);
*(__le16 *)&vconfig[PCI_DEVICE_ID] = cpu_to_le16(pdev->device);
}
if (!IS_ENABLED(CONFIG_VFIO_PCI_INTX))
vconfig[PCI_INTERRUPT_PIN] = 0;
ret = vfio_cap_init(vdev);
if (ret)
goto out;
ret = vfio_ecap_init(vdev);
if (ret)
goto out;
return 0;
out:
kfree(map);
vdev->pci_config_map = NULL;
kfree(vconfig);
vdev->vconfig = NULL;
return pcibios_err_to_errno(ret);
}
void vfio_config_free(struct vfio_pci_device *vdev)
{
kfree(vdev->vconfig);
vdev->vconfig = NULL;
kfree(vdev->pci_config_map);
vdev->pci_config_map = NULL;
kfree(vdev->msi_perm);
vdev->msi_perm = NULL;
}
static size_t vfio_pci_cap_remaining_dword(struct vfio_pci_device *vdev,
loff_t pos)
{
u8 cap = vdev->pci_config_map[pos];
size_t i;
for (i = 1; (pos + i) % 4 && vdev->pci_config_map[pos + i] == cap; i++)
;
return i;
}
static ssize_t vfio_config_do_rw(struct vfio_pci_device *vdev, char __user *buf,
size_t count, loff_t *ppos, bool iswrite)
{
struct pci_dev *pdev = vdev->pdev;
struct perm_bits *perm;
__le32 val = 0;
int cap_start = 0, offset;
u8 cap_id;
ssize_t ret;
if (*ppos < 0 || *ppos >= pdev->cfg_size ||
*ppos + count > pdev->cfg_size)
return -EFAULT;
count = min(count, vfio_pci_cap_remaining_dword(vdev, *ppos));
if (count >= 4 && !(*ppos % 4))
count = 4;
else if (count >= 2 && !(*ppos % 2))
count = 2;
else
count = 1;
ret = count;
cap_id = vdev->pci_config_map[*ppos];
if (cap_id == PCI_CAP_ID_INVALID) {
perm = &unassigned_perms;
cap_start = *ppos;
} else if (cap_id == PCI_CAP_ID_INVALID_VIRT) {
perm = &virt_perms;
cap_start = *ppos;
} else {
if (*ppos >= PCI_CFG_SPACE_SIZE) {
WARN_ON(cap_id > PCI_EXT_CAP_ID_MAX);
perm = &ecap_perms[cap_id];
cap_start = vfio_find_cap_start(vdev, *ppos);
} else {
WARN_ON(cap_id > PCI_CAP_ID_MAX);
perm = &cap_perms[cap_id];
if (cap_id == PCI_CAP_ID_MSI)
perm = vdev->msi_perm;
if (cap_id > PCI_CAP_ID_BASIC)
cap_start = vfio_find_cap_start(vdev, *ppos);
}
}
WARN_ON(!cap_start && cap_id != PCI_CAP_ID_BASIC);
WARN_ON(cap_start > *ppos);
offset = *ppos - cap_start;
if (iswrite) {
if (!perm->writefn)
return ret;
if (copy_from_user(&val, buf, count))
return -EFAULT;
ret = perm->writefn(vdev, *ppos, count, perm, offset, val);
} else {
if (perm->readfn) {
ret = perm->readfn(vdev, *ppos, count,
perm, offset, &val);
if (ret < 0)
return ret;
}
if (copy_to_user(buf, &val, count))
return -EFAULT;
}
return ret;
}
ssize_t vfio_pci_config_rw(struct vfio_pci_device *vdev, char __user *buf,
size_t count, loff_t *ppos, bool iswrite)
{
size_t done = 0;
int ret = 0;
loff_t pos = *ppos;
pos &= VFIO_PCI_OFFSET_MASK;
while (count) {
ret = vfio_config_do_rw(vdev, buf, count, &pos, iswrite);
if (ret < 0)
return ret;
count -= ret;
done += ret;
buf += ret;
pos += ret;
}
*ppos += done;
return done;
}
