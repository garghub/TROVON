static uint32_t radeon_invalid_rreg(struct radeon_device *rdev, uint32_t reg)
{
DRM_ERROR("Invalid callback to read register 0x%04X\n", reg);
BUG_ON(1);
return 0;
}
static void radeon_invalid_wreg(struct radeon_device *rdev, uint32_t reg, uint32_t v)
{
DRM_ERROR("Invalid callback to write register 0x%04X with 0x%08X\n",
reg, v);
BUG_ON(1);
}
static void radeon_register_accessor_init(struct radeon_device *rdev)
{
rdev->mc_rreg = &radeon_invalid_rreg;
rdev->mc_wreg = &radeon_invalid_wreg;
rdev->pll_rreg = &radeon_invalid_rreg;
rdev->pll_wreg = &radeon_invalid_wreg;
rdev->pciep_rreg = &radeon_invalid_rreg;
rdev->pciep_wreg = &radeon_invalid_wreg;
if (rdev->family < CHIP_RV515) {
rdev->pcie_reg_mask = 0xff;
} else {
rdev->pcie_reg_mask = 0x7ff;
}
if (rdev->family <= CHIP_R580) {
rdev->pll_rreg = &r100_pll_rreg;
rdev->pll_wreg = &r100_pll_wreg;
}
if (rdev->family >= CHIP_R420) {
rdev->mc_rreg = &r420_mc_rreg;
rdev->mc_wreg = &r420_mc_wreg;
}
if (rdev->family >= CHIP_RV515) {
rdev->mc_rreg = &rv515_mc_rreg;
rdev->mc_wreg = &rv515_mc_wreg;
}
if (rdev->family == CHIP_RS400 || rdev->family == CHIP_RS480) {
rdev->mc_rreg = &rs400_mc_rreg;
rdev->mc_wreg = &rs400_mc_wreg;
}
if (rdev->family == CHIP_RS690 || rdev->family == CHIP_RS740) {
rdev->mc_rreg = &rs690_mc_rreg;
rdev->mc_wreg = &rs690_mc_wreg;
}
if (rdev->family == CHIP_RS600) {
rdev->mc_rreg = &rs600_mc_rreg;
rdev->mc_wreg = &rs600_mc_wreg;
}
if (rdev->family >= CHIP_R600) {
rdev->pciep_rreg = &r600_pciep_rreg;
rdev->pciep_wreg = &r600_pciep_wreg;
}
}
void radeon_agp_disable(struct radeon_device *rdev)
{
rdev->flags &= ~RADEON_IS_AGP;
if (rdev->family >= CHIP_R600) {
DRM_INFO("Forcing AGP to PCIE mode\n");
rdev->flags |= RADEON_IS_PCIE;
} else if (rdev->family >= CHIP_RV515 ||
rdev->family == CHIP_RV380 ||
rdev->family == CHIP_RV410 ||
rdev->family == CHIP_R423) {
DRM_INFO("Forcing AGP to PCIE mode\n");
rdev->flags |= RADEON_IS_PCIE;
rdev->asic->gart_tlb_flush = &rv370_pcie_gart_tlb_flush;
rdev->asic->gart_set_page = &rv370_pcie_gart_set_page;
} else {
DRM_INFO("Forcing AGP to PCI mode\n");
rdev->flags |= RADEON_IS_PCI;
rdev->asic->gart_tlb_flush = &r100_pci_gart_tlb_flush;
rdev->asic->gart_set_page = &r100_pci_gart_set_page;
}
rdev->mc.gtt_size = radeon_gart_size * 1024 * 1024;
}
int radeon_asic_init(struct radeon_device *rdev)
{
radeon_register_accessor_init(rdev);
if (rdev->flags & RADEON_SINGLE_CRTC)
rdev->num_crtc = 1;
else
rdev->num_crtc = 2;
rdev->copy_ring = RADEON_RING_TYPE_GFX_INDEX;
switch (rdev->family) {
case CHIP_R100:
case CHIP_RV100:
case CHIP_RS100:
case CHIP_RV200:
case CHIP_RS200:
rdev->asic = &r100_asic;
break;
case CHIP_R200:
case CHIP_RV250:
case CHIP_RS300:
case CHIP_RV280:
rdev->asic = &r200_asic;
break;
case CHIP_R300:
case CHIP_R350:
case CHIP_RV350:
case CHIP_RV380:
if (rdev->flags & RADEON_IS_PCIE)
rdev->asic = &r300_asic_pcie;
else
rdev->asic = &r300_asic;
break;
case CHIP_R420:
case CHIP_R423:
case CHIP_RV410:
rdev->asic = &r420_asic;
if (rdev->bios == NULL) {
rdev->asic->get_engine_clock = &radeon_legacy_get_engine_clock;
rdev->asic->set_engine_clock = &radeon_legacy_set_engine_clock;
rdev->asic->get_memory_clock = &radeon_legacy_get_memory_clock;
rdev->asic->set_memory_clock = NULL;
}
break;
case CHIP_RS400:
case CHIP_RS480:
rdev->asic = &rs400_asic;
break;
case CHIP_RS600:
rdev->asic = &rs600_asic;
break;
case CHIP_RS690:
case CHIP_RS740:
rdev->asic = &rs690_asic;
break;
case CHIP_RV515:
rdev->asic = &rv515_asic;
break;
case CHIP_R520:
case CHIP_RV530:
case CHIP_RV560:
case CHIP_RV570:
case CHIP_R580:
rdev->asic = &r520_asic;
break;
case CHIP_R600:
case CHIP_RV610:
case CHIP_RV630:
case CHIP_RV620:
case CHIP_RV635:
case CHIP_RV670:
rdev->asic = &r600_asic;
break;
case CHIP_RS780:
case CHIP_RS880:
rdev->asic = &rs780_asic;
break;
case CHIP_RV770:
case CHIP_RV730:
case CHIP_RV710:
case CHIP_RV740:
rdev->asic = &rv770_asic;
break;
case CHIP_CEDAR:
case CHIP_REDWOOD:
case CHIP_JUNIPER:
case CHIP_CYPRESS:
case CHIP_HEMLOCK:
if (rdev->family == CHIP_CEDAR)
rdev->num_crtc = 4;
else
rdev->num_crtc = 6;
rdev->asic = &evergreen_asic;
break;
case CHIP_PALM:
case CHIP_SUMO:
case CHIP_SUMO2:
rdev->asic = &sumo_asic;
break;
case CHIP_BARTS:
case CHIP_TURKS:
case CHIP_CAICOS:
if (rdev->family == CHIP_CAICOS)
rdev->num_crtc = 4;
else
rdev->num_crtc = 6;
rdev->asic = &btc_asic;
break;
case CHIP_CAYMAN:
rdev->asic = &cayman_asic;
rdev->num_crtc = 6;
rdev->vm_manager.funcs = &cayman_vm_funcs;
break;
default:
return -EINVAL;
}
if (rdev->flags & RADEON_IS_IGP) {
rdev->asic->get_memory_clock = NULL;
rdev->asic->set_memory_clock = NULL;
}
return 0;
}
