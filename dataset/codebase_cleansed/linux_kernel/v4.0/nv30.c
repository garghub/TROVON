int
nv30_identify(struct nvkm_device *device)
{
switch (device->chipset) {
case 0x30:
device->cname = "NV30";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nvkm_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = nv10_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = nv04_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLK ] = &nv04_clk_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = nv20_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = nv04_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nv04_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &nv04_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = nv30_fb_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv04_instmem_oclass;
device->oclass[NVDEV_SUBDEV_MMU ] = &nv04_mmu_oclass;
device->oclass[NVDEV_ENGINE_DMAOBJ ] = nv04_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv17_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nv10_sw_oclass;
device->oclass[NVDEV_ENGINE_GR ] = &nv30_gr_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = nv04_disp_oclass;
break;
case 0x35:
device->cname = "NV35";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nvkm_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = nv10_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = nv04_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLK ] = &nv04_clk_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = nv20_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = nv04_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nv04_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &nv04_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = nv35_fb_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv04_instmem_oclass;
device->oclass[NVDEV_SUBDEV_MMU ] = &nv04_mmu_oclass;
device->oclass[NVDEV_ENGINE_DMAOBJ ] = nv04_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv17_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nv10_sw_oclass;
device->oclass[NVDEV_ENGINE_GR ] = &nv35_gr_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = nv04_disp_oclass;
break;
case 0x31:
device->cname = "NV31";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nvkm_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = nv10_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = nv04_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLK ] = &nv04_clk_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = nv20_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = nv04_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nv31_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &nv04_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = nv30_fb_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv04_instmem_oclass;
device->oclass[NVDEV_SUBDEV_MMU ] = &nv04_mmu_oclass;
device->oclass[NVDEV_ENGINE_DMAOBJ ] = nv04_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv17_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nv10_sw_oclass;
device->oclass[NVDEV_ENGINE_GR ] = &nv30_gr_oclass;
device->oclass[NVDEV_ENGINE_MPEG ] = &nv31_mpeg_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = nv04_disp_oclass;
break;
case 0x36:
device->cname = "NV36";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nvkm_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = nv10_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = nv04_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLK ] = &nv04_clk_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = nv20_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = nv04_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nv31_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &nv04_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = nv36_fb_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv04_instmem_oclass;
device->oclass[NVDEV_SUBDEV_MMU ] = &nv04_mmu_oclass;
device->oclass[NVDEV_ENGINE_DMAOBJ ] = nv04_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv17_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nv10_sw_oclass;
device->oclass[NVDEV_ENGINE_GR ] = &nv35_gr_oclass;
device->oclass[NVDEV_ENGINE_MPEG ] = &nv31_mpeg_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = nv04_disp_oclass;
break;
case 0x34:
device->cname = "NV34";
device->oclass[NVDEV_SUBDEV_VBIOS ] = &nvkm_bios_oclass;
device->oclass[NVDEV_SUBDEV_GPIO ] = nv10_gpio_oclass;
device->oclass[NVDEV_SUBDEV_I2C ] = nv04_i2c_oclass;
device->oclass[NVDEV_SUBDEV_CLK ] = &nv04_clk_oclass;
device->oclass[NVDEV_SUBDEV_DEVINIT] = nv10_devinit_oclass;
device->oclass[NVDEV_SUBDEV_MC ] = nv04_mc_oclass;
device->oclass[NVDEV_SUBDEV_BUS ] = nv31_bus_oclass;
device->oclass[NVDEV_SUBDEV_TIMER ] = &nv04_timer_oclass;
device->oclass[NVDEV_SUBDEV_FB ] = nv10_fb_oclass;
device->oclass[NVDEV_SUBDEV_INSTMEM] = nv04_instmem_oclass;
device->oclass[NVDEV_SUBDEV_MMU ] = &nv04_mmu_oclass;
device->oclass[NVDEV_ENGINE_DMAOBJ ] = nv04_dmaeng_oclass;
device->oclass[NVDEV_ENGINE_FIFO ] = nv17_fifo_oclass;
device->oclass[NVDEV_ENGINE_SW ] = nv10_sw_oclass;
device->oclass[NVDEV_ENGINE_GR ] = &nv34_gr_oclass;
device->oclass[NVDEV_ENGINE_MPEG ] = &nv31_mpeg_oclass;
device->oclass[NVDEV_ENGINE_DISP ] = nv04_disp_oclass;
break;
default:
nv_fatal(device, "unknown Rankine chipset\n");
return -EINVAL;
}
return 0;
}
