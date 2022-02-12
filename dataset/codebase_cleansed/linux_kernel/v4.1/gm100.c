int
gm100_identify(struct nvkm_device *device)
{
switch (device->chipset) {
case 0x117:
device->cname = "GM107";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nvkm_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = gk104_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = gf110_i2c_oclass;
device->oclass[NVDEV_SUBDEV_FUSE ] = &gm107_fuse_oclass;
device->oclass[NVDEV_SUBDEV_CLK ] = &gk104_clk_oclass;
device->oclass[NVDEV_SUBDEV_THERM ] = &gm107_therm_oclass;
device->oclass[NVDEV_SUBDEV_MXM ] = &nv50_mxm_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = gm107_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = gk20a_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = gf100_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &gk20a_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = gm107_fb_oclass;
device->oclass[NVDEV_SUBDEV_LTC ] = gm107_ltc_oclass;
device->oclass[NVDEV_SUBDEV_IBUS ] = &gk104_ibus_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv50_instmem_oclass;
device->oclass[NVDEV_SUBDEV_MMU ] = &gf100_mmu_oclass;
device->oclass[NVDEV_SUBDEV_BAR ] = &gf100_bar_oclass;
device->oclass[NVDEV_SUBDEV_PMU ] = gk208_pmu_oclass;
#if 0
device->oclass[NVDEV_SUBDEV_VOLT ] = &nv40_volt_oclass;
#endif
device->oclass[NVDEV_ENGINE_DMAOBJ ] = gf110_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = gk208_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = gf100_sw_oclass;
device->oclass[NVDEV_ENGINE_GR ] = gm107_gr_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = gm107_disp_oclass;
device->oclass[NVDEV_ENGINE_CE0 ] = &gk104_ce0_oclass;
#if 0
device->oclass[NVDEV_ENGINE_CE1 ] = &gk104_ce1_oclass;
#endif
device->oclass[NVDEV_ENGINE_CE2 ] = &gk104_ce2_oclass;
#if 0
device->oclass[NVDEV_ENGINE_MSVLD ] = &gk104_msvld_oclass;
device->oclass[NVDEV_ENGINE_MSPDEC ] = &gk104_mspdec_oclass;
device->oclass[NVDEV_ENGINE_MSPPP ] = &gf100_msppp_oclass;
#endif
break;
case 0x124:
device->cname = "GM204";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nvkm_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = gk104_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = gm204_i2c_oclass;
device->oclass[NVDEV_SUBDEV_FUSE ] = &gm107_fuse_oclass;
#if 0
device->oclass[NVDEV_SUBDEV_CLK ] = &gk104_clk_oclass;
device->oclass[NVDEV_SUBDEV_THERM ] = &gm107_therm_oclass;
#endif
device->oclass[NVDEV_SUBDEV_MXM ] = &nv50_mxm_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = gm204_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = gk20a_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = gf100_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &gk20a_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = gm107_fb_oclass;
device->oclass[NVDEV_SUBDEV_LTC ] = gm107_ltc_oclass;
device->oclass[NVDEV_SUBDEV_IBUS ] = &gk104_ibus_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv50_instmem_oclass;
device->oclass[NVDEV_SUBDEV_MMU ] = &gf100_mmu_oclass;
device->oclass[NVDEV_SUBDEV_BAR ] = &gf100_bar_oclass;
device->oclass[NVDEV_SUBDEV_PMU ] = gk208_pmu_oclass;
#if 0
device->oclass[NVDEV_SUBDEV_VOLT ] = &nv40_volt_oclass;
#endif
device->oclass[NVDEV_ENGINE_DMAOBJ ] = gf110_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = gm204_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = gf100_sw_oclass;
device->oclass[NVDEV_ENGINE_GR ] = gm204_gr_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = gm204_disp_oclass;
device->oclass[NVDEV_ENGINE_CE0 ] = &gm204_ce0_oclass;
device->oclass[NVDEV_ENGINE_CE1 ] = &gm204_ce1_oclass;
device->oclass[NVDEV_ENGINE_CE2 ] = &gm204_ce2_oclass;
#if 0
device->oclass[NVDEV_ENGINE_MSVLD ] = &gk104_msvld_oclass;
device->oclass[NVDEV_ENGINE_MSPDEC ] = &gk104_mspdec_oclass;
device->oclass[NVDEV_ENGINE_MSPPP ] = &gf100_msppp_oclass;
#endif
break;
case 0x126:
device->cname = "GM206";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nvkm_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = gk104_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = gm204_i2c_oclass;
device->oclass[NVDEV_SUBDEV_FUSE ] = &gm107_fuse_oclass;
#if 0
device->oclass[NVDEV_SUBDEV_CLK ] = &gk104_clk_oclass;
device->oclass[NVDEV_SUBDEV_THERM ] = &gm107_therm_oclass;
#endif
device->oclass[NVDEV_SUBDEV_MXM ] = &nv50_mxm_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = gm204_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = gk20a_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = gf100_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &gk20a_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = gm107_fb_oclass;
device->oclass[NVDEV_SUBDEV_LTC ] = gm107_ltc_oclass;
device->oclass[NVDEV_SUBDEV_IBUS ] = &gk104_ibus_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv50_instmem_oclass;
device->oclass[NVDEV_SUBDEV_MMU ] = &gf100_mmu_oclass;
device->oclass[NVDEV_SUBDEV_BAR ] = &gf100_bar_oclass;
device->oclass[NVDEV_SUBDEV_PMU ] = gk208_pmu_oclass;
#if 0
device->oclass[NVDEV_SUBDEV_VOLT ] = &nv40_volt_oclass;
#endif
device->oclass[NVDEV_ENGINE_DMAOBJ ] = gf110_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = gm204_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = gf100_sw_oclass;
device->oclass[NVDEV_ENGINE_GR ] = gm206_gr_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = gm204_disp_oclass;
device->oclass[NVDEV_ENGINE_CE0 ] = &gm204_ce0_oclass;
device->oclass[NVDEV_ENGINE_CE1 ] = &gm204_ce1_oclass;
device->oclass[NVDEV_ENGINE_CE2 ] = &gm204_ce2_oclass;
#if 0
device->oclass[NVDEV_ENGINE_MSVLD ] = &gk104_msvld_oclass;
device->oclass[NVDEV_ENGINE_MSPDEC ] = &gk104_mspdec_oclass;
device->oclass[NVDEV_ENGINE_MSPPP ] = &gf100_msppp_oclass;
#endif
break;
default:
nv_fatal(device, "unknown Maxwell chipset\n");
return -EINVAL;
}
return 0;
}
