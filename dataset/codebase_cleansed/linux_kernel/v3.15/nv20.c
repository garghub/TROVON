int
nv20_identify(struct nouveau_device *device)
{
switch (device->chipset) {
case 0x20:
device->cname = "NV20";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nouveau_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = &nv10_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = &nv04_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLOCK ] = &nv04_clock_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = nv20_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = nv04_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nv04_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &nv04_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = nv20_fb_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv04_instmem_oclass;
device->oclass[NVDEV_SUBDEV_VM ] = &nv04_vmmgr_oclass;
device->oclass[NVDEV_ENGINE_DMAOBJ ] = &nv04_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv17_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nv10_software_oclass;
device->oclass[NVDEV_ENGINE_GR ] = &nv20_graph_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = nv04_disp_oclass;
break;
case 0x25:
device->cname = "NV25";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nouveau_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = &nv10_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = &nv04_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLOCK ] = &nv04_clock_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = nv20_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = nv04_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nv04_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &nv04_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = nv25_fb_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv04_instmem_oclass;
device->oclass[NVDEV_SUBDEV_VM ] = &nv04_vmmgr_oclass;
device->oclass[NVDEV_ENGINE_DMAOBJ ] = &nv04_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv17_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nv10_software_oclass;
device->oclass[NVDEV_ENGINE_GR ] = &nv25_graph_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = nv04_disp_oclass;
break;
case 0x28:
device->cname = "NV28";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nouveau_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = &nv10_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = &nv04_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLOCK ] = &nv04_clock_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = nv20_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = nv04_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nv04_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &nv04_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = nv25_fb_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv04_instmem_oclass;
device->oclass[NVDEV_SUBDEV_VM ] = &nv04_vmmgr_oclass;
device->oclass[NVDEV_ENGINE_DMAOBJ ] = &nv04_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv17_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nv10_software_oclass;
device->oclass[NVDEV_ENGINE_GR ] = &nv25_graph_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = nv04_disp_oclass;
break;
case 0x2a:
device->cname = "NV2A";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nouveau_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = &nv10_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = &nv04_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLOCK ] = &nv04_clock_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = nv20_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = nv04_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nv04_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &nv04_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = nv25_fb_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv04_instmem_oclass;
device->oclass[NVDEV_SUBDEV_VM ] = &nv04_vmmgr_oclass;
device->oclass[NVDEV_ENGINE_DMAOBJ ] = &nv04_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv17_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nv10_software_oclass;
device->oclass[NVDEV_ENGINE_GR ] = &nv2a_graph_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = nv04_disp_oclass;
break;
default:
nv_fatal(device, "unknown Kelvin chipset\n");
return -EINVAL;
}
return 0;
}
