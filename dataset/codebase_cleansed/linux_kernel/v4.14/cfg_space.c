static void vgpu_pci_cfg_mem_write(struct intel_vgpu *vgpu, unsigned int off,
u8 *src, unsigned int bytes)
{
u8 *cfg_base = vgpu_cfg_space(vgpu);
u8 mask, new, old;
int i = 0;
for (; i < bytes && (off + i < sizeof(pci_cfg_space_rw_bmp)); i++) {
mask = pci_cfg_space_rw_bmp[off + i];
old = cfg_base[off + i];
new = src[i] & mask;
if (off + i == PCI_STATUS + 1)
new = (~new & old) & mask;
cfg_base[off + i] = (old & ~mask) | new;
}
if (i < bytes)
memcpy(cfg_base + off + i, src + i, bytes - i);
}
int intel_vgpu_emulate_cfg_read(struct intel_vgpu *vgpu, unsigned int offset,
void *p_data, unsigned int bytes)
{
if (WARN_ON(bytes > 4))
return -EINVAL;
if (WARN_ON(offset + bytes > INTEL_GVT_MAX_CFG_SPACE_SZ))
return -EINVAL;
memcpy(p_data, vgpu_cfg_space(vgpu) + offset, bytes);
return 0;
}
static int map_aperture(struct intel_vgpu *vgpu, bool map)
{
u64 first_gfn, first_mfn;
u64 val;
int ret;
if (map == vgpu->cfg_space.bar[INTEL_GVT_PCI_BAR_APERTURE].tracked)
return 0;
val = vgpu_cfg_space(vgpu)[PCI_BASE_ADDRESS_2];
if (val & PCI_BASE_ADDRESS_MEM_TYPE_64)
val = *(u64 *)(vgpu_cfg_space(vgpu) + PCI_BASE_ADDRESS_2);
else
val = *(u32 *)(vgpu_cfg_space(vgpu) + PCI_BASE_ADDRESS_2);
first_gfn = (val + vgpu_aperture_offset(vgpu)) >> PAGE_SHIFT;
first_mfn = vgpu_aperture_pa_base(vgpu) >> PAGE_SHIFT;
ret = intel_gvt_hypervisor_map_gfn_to_mfn(vgpu, first_gfn,
first_mfn,
vgpu_aperture_sz(vgpu) >>
PAGE_SHIFT, map);
if (ret)
return ret;
vgpu->cfg_space.bar[INTEL_GVT_PCI_BAR_APERTURE].tracked = map;
return 0;
}
static int trap_gttmmio(struct intel_vgpu *vgpu, bool trap)
{
u64 start, end;
u64 val;
int ret;
if (trap == vgpu->cfg_space.bar[INTEL_GVT_PCI_BAR_GTTMMIO].tracked)
return 0;
val = vgpu_cfg_space(vgpu)[PCI_BASE_ADDRESS_0];
if (val & PCI_BASE_ADDRESS_MEM_TYPE_64)
start = *(u64 *)(vgpu_cfg_space(vgpu) + PCI_BASE_ADDRESS_0);
else
start = *(u32 *)(vgpu_cfg_space(vgpu) + PCI_BASE_ADDRESS_0);
start &= ~GENMASK(3, 0);
end = start + vgpu->cfg_space.bar[INTEL_GVT_PCI_BAR_GTTMMIO].size - 1;
ret = intel_gvt_hypervisor_set_trap_area(vgpu, start, end, trap);
if (ret)
return ret;
vgpu->cfg_space.bar[INTEL_GVT_PCI_BAR_GTTMMIO].tracked = trap;
return 0;
}
static int emulate_pci_command_write(struct intel_vgpu *vgpu,
unsigned int offset, void *p_data, unsigned int bytes)
{
u8 old = vgpu_cfg_space(vgpu)[offset];
u8 new = *(u8 *)p_data;
u8 changed = old ^ new;
int ret;
vgpu_pci_cfg_mem_write(vgpu, offset, p_data, bytes);
if (!(changed & PCI_COMMAND_MEMORY))
return 0;
if (old & PCI_COMMAND_MEMORY) {
ret = trap_gttmmio(vgpu, false);
if (ret)
return ret;
ret = map_aperture(vgpu, false);
if (ret)
return ret;
} else {
ret = trap_gttmmio(vgpu, true);
if (ret)
return ret;
ret = map_aperture(vgpu, true);
if (ret)
return ret;
}
return 0;
}
static int emulate_pci_bar_write(struct intel_vgpu *vgpu, unsigned int offset,
void *p_data, unsigned int bytes)
{
u32 new = *(u32 *)(p_data);
bool lo = IS_ALIGNED(offset, 8);
u64 size;
int ret = 0;
bool mmio_enabled =
vgpu_cfg_space(vgpu)[PCI_COMMAND] & PCI_COMMAND_MEMORY;
struct intel_vgpu_pci_bar *bars = vgpu->cfg_space.bar;
if (new == 0xffffffff) {
switch (offset) {
case PCI_BASE_ADDRESS_0:
case PCI_BASE_ADDRESS_1:
size = ~(bars[INTEL_GVT_PCI_BAR_GTTMMIO].size -1);
intel_vgpu_write_pci_bar(vgpu, offset,
size >> (lo ? 0 : 32), lo);
ret = trap_gttmmio(vgpu, false);
break;
case PCI_BASE_ADDRESS_2:
case PCI_BASE_ADDRESS_3:
size = ~(bars[INTEL_GVT_PCI_BAR_APERTURE].size -1);
intel_vgpu_write_pci_bar(vgpu, offset,
size >> (lo ? 0 : 32), lo);
ret = map_aperture(vgpu, false);
break;
default:
intel_vgpu_write_pci_bar(vgpu, offset, 0x0, false);
}
} else {
switch (offset) {
case PCI_BASE_ADDRESS_0:
case PCI_BASE_ADDRESS_1:
trap_gttmmio(vgpu, false);
intel_vgpu_write_pci_bar(vgpu, offset, new, lo);
ret = trap_gttmmio(vgpu, mmio_enabled);
break;
case PCI_BASE_ADDRESS_2:
case PCI_BASE_ADDRESS_3:
map_aperture(vgpu, false);
intel_vgpu_write_pci_bar(vgpu, offset, new, lo);
ret = map_aperture(vgpu, mmio_enabled);
break;
default:
intel_vgpu_write_pci_bar(vgpu, offset, new, lo);
}
}
return ret;
}
int intel_vgpu_emulate_cfg_write(struct intel_vgpu *vgpu, unsigned int offset,
void *p_data, unsigned int bytes)
{
int ret;
if (WARN_ON(bytes > 4))
return -EINVAL;
if (WARN_ON(offset + bytes > INTEL_GVT_MAX_CFG_SPACE_SZ))
return -EINVAL;
if (IS_ALIGNED(offset, 2) && offset == PCI_COMMAND) {
if (WARN_ON(bytes > 2))
return -EINVAL;
return emulate_pci_command_write(vgpu, offset, p_data, bytes);
}
switch (rounddown(offset, 4)) {
case PCI_BASE_ADDRESS_0 ... PCI_BASE_ADDRESS_5:
if (WARN_ON(!IS_ALIGNED(offset, 4)))
return -EINVAL;
return emulate_pci_bar_write(vgpu, offset, p_data, bytes);
case INTEL_GVT_PCI_SWSCI:
if (WARN_ON(!IS_ALIGNED(offset, 4)))
return -EINVAL;
ret = intel_vgpu_emulate_opregion_request(vgpu, *(u32 *)p_data);
if (ret)
return ret;
break;
case INTEL_GVT_PCI_OPREGION:
if (WARN_ON(!IS_ALIGNED(offset, 4)))
return -EINVAL;
ret = intel_vgpu_init_opregion(vgpu, *(u32 *)p_data);
if (ret)
return ret;
vgpu_pci_cfg_mem_write(vgpu, offset, p_data, bytes);
break;
default:
vgpu_pci_cfg_mem_write(vgpu, offset, p_data, bytes);
break;
}
return 0;
}
void intel_vgpu_init_cfg_space(struct intel_vgpu *vgpu,
bool primary)
{
struct intel_gvt *gvt = vgpu->gvt;
const struct intel_gvt_device_info *info = &gvt->device_info;
u16 *gmch_ctl;
memcpy(vgpu_cfg_space(vgpu), gvt->firmware.cfg_space,
info->cfg_space_size);
if (!primary) {
vgpu_cfg_space(vgpu)[PCI_CLASS_DEVICE] =
INTEL_GVT_PCI_CLASS_VGA_OTHER;
vgpu_cfg_space(vgpu)[PCI_CLASS_PROG] =
INTEL_GVT_PCI_CLASS_VGA_OTHER;
}
gmch_ctl = (u16 *)(vgpu_cfg_space(vgpu) + INTEL_GVT_PCI_GMCH_CONTROL);
*gmch_ctl &= ~(BDW_GMCH_GMS_MASK << BDW_GMCH_GMS_SHIFT);
intel_vgpu_write_pci_bar(vgpu, PCI_BASE_ADDRESS_2,
gvt_aperture_pa_base(gvt), true);
vgpu_cfg_space(vgpu)[PCI_COMMAND] &= ~(PCI_COMMAND_IO
| PCI_COMMAND_MEMORY
| PCI_COMMAND_MASTER);
memset(vgpu_cfg_space(vgpu) + PCI_BASE_ADDRESS_1, 0, 4);
memset(vgpu_cfg_space(vgpu) + PCI_BASE_ADDRESS_3, 0, 4);
memset(vgpu_cfg_space(vgpu) + PCI_BASE_ADDRESS_4, 0, 8);
memset(vgpu_cfg_space(vgpu) + INTEL_GVT_PCI_OPREGION, 0, 4);
vgpu->cfg_space.bar[INTEL_GVT_PCI_BAR_GTTMMIO].size =
pci_resource_len(gvt->dev_priv->drm.pdev, 0);
vgpu->cfg_space.bar[INTEL_GVT_PCI_BAR_APERTURE].size =
pci_resource_len(gvt->dev_priv->drm.pdev, 2);
}
void intel_vgpu_reset_cfg_space(struct intel_vgpu *vgpu)
{
u8 cmd = vgpu_cfg_space(vgpu)[PCI_COMMAND];
bool primary = vgpu_cfg_space(vgpu)[PCI_CLASS_DEVICE] !=
INTEL_GVT_PCI_CLASS_VGA_OTHER;
if (cmd & PCI_COMMAND_MEMORY) {
trap_gttmmio(vgpu, false);
map_aperture(vgpu, false);
}
intel_vgpu_init_cfg_space(vgpu, primary);
}
