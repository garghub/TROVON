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
memcpy(vgpu_cfg_space(vgpu) + offset, p_data, bytes);
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
unsigned int bar_index =
(rounddown(offset, 8) % PCI_BASE_ADDRESS_0) / 8;
u32 new = *(u32 *)(p_data);
bool lo = IS_ALIGNED(offset, 8);
u64 size;
int ret = 0;
bool mmio_enabled =
vgpu_cfg_space(vgpu)[PCI_COMMAND] & PCI_COMMAND_MEMORY;
if (WARN_ON(bar_index >= INTEL_GVT_PCI_BAR_MAX))
return -EINVAL;
if (new == 0xffffffff) {
size = vgpu->cfg_space.bar[bar_index].size;
if (lo) {
new = rounddown(new, size);
} else {
u32 val = vgpu_cfg_space(vgpu)[rounddown(offset, 8)];
if (val & PCI_BASE_ADDRESS_MEM_TYPE_64)
new &= (~(size-1)) >> 32;
else
new = 0;
}
switch (bar_index) {
case INTEL_GVT_PCI_BAR_GTTMMIO:
ret = trap_gttmmio(vgpu, false);
break;
case INTEL_GVT_PCI_BAR_APERTURE:
ret = map_aperture(vgpu, false);
break;
}
intel_vgpu_write_pci_bar(vgpu, offset, new, lo);
} else {
switch (bar_index) {
case INTEL_GVT_PCI_BAR_GTTMMIO:
ret = trap_gttmmio(vgpu, false);
break;
case INTEL_GVT_PCI_BAR_APERTURE:
ret = map_aperture(vgpu, false);
break;
}
intel_vgpu_write_pci_bar(vgpu, offset, new, lo);
if (mmio_enabled) {
switch (bar_index) {
case INTEL_GVT_PCI_BAR_GTTMMIO:
ret = trap_gttmmio(vgpu, true);
break;
case INTEL_GVT_PCI_BAR_APERTURE:
ret = map_aperture(vgpu, true);
break;
}
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
case PCI_BASE_ADDRESS_0:
case PCI_BASE_ADDRESS_1:
case PCI_BASE_ADDRESS_2:
case PCI_BASE_ADDRESS_3:
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
memcpy(vgpu_cfg_space(vgpu) + offset, p_data, bytes);
break;
default:
memcpy(vgpu_cfg_space(vgpu) + offset, p_data, bytes);
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
int i;
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
memset(vgpu_cfg_space(vgpu) + INTEL_GVT_PCI_OPREGION, 0, 4);
for (i = 0; i < INTEL_GVT_MAX_BAR_NUM; i++) {
vgpu->cfg_space.bar[i].size = pci_resource_len(
gvt->dev_priv->drm.pdev, i * 2);
vgpu->cfg_space.bar[i].tracked = false;
}
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
