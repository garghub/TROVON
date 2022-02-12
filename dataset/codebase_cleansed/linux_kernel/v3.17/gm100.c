int
gm100_identify(struct nouveau_device *device)
{
switch (device->chipset) {
case 0x117:
device->cname = "GM107";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nouveau_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = nve0_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = nvd0_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLOCK ] = &nve0_clock_oclass;
#if 0
device->oclass[NVDEV_SUBDEV_THERM ] = &nvd0_therm_oclass;
#endif
device->oclass[NVDEV_SUBDEV_MXM ] = &nv50_mxm_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = gm107_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = gk20a_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nvc0_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &gk20a_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = gm107_fb_oclass;
device->oclass[NVDEV_SUBDEV_LTC ] = gm107_ltc_oclass;
device->oclass[NVDEV_SUBDEV_IBUS ] = &nve0_ibus_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv50_instmem_oclass;
device->oclass[NVDEV_SUBDEV_VM ] = &nvc0_vmmgr_oclass;
device->oclass[NVDEV_SUBDEV_BAR ] = &nvc0_bar_oclass;
#if 0
device->oclass[NVDEV_SUBDEV_PWR ] = nv108_pwr_oclass;
device->oclass[NVDEV_SUBDEV_VOLT ] = &nv40_volt_oclass;
#endif
device->oclass[NVDEV_ENGINE_DMAOBJ ] = nvd0_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv108_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nvc0_software_oclass;
device->oclass[NVDEV_ENGINE_GR ] = gm107_graph_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = gm107_disp_oclass;
device->oclass[NVDEV_ENGINE_COPY0 ] = &nve0_copy0_oclass;
#if 0
device->oclass[NVDEV_ENGINE_COPY1 ] = &nve0_copy1_oclass;
#endif
device->oclass[NVDEV_ENGINE_COPY2 ] = &nve0_copy2_oclass;
#if 0
device->oclass[NVDEV_ENGINE_BSP ] = &nve0_bsp_oclass;
device->oclass[NVDEV_ENGINE_VP ] = &nve0_vp_oclass;
device->oclass[NVDEV_ENGINE_PPP ] = &nvc0_ppp_oclass;
#endif
break;
default:
nv_fatal(device, "unknown Maxwell chipset\n");
return -EINVAL;
}
return 0;
}
