static int
gp102_disp_core_init(struct nv50_disp_dmac *chan)
{
struct nv50_disp *disp = chan->base.root->disp;
struct nvkm_subdev *subdev = &disp->base.engine.subdev;
struct nvkm_device *device = subdev->device;
nvkm_mask(device, 0x6100a0, 0x00000001, 0x00000001);
nvkm_wr32(device, 0x611494, chan->push);
nvkm_wr32(device, 0x611498, 0x00010000);
nvkm_wr32(device, 0x61149c, 0x00000001);
nvkm_mask(device, 0x610490, 0x00000010, 0x00000010);
nvkm_wr32(device, 0x640000, 0x00000000);
nvkm_wr32(device, 0x610490, 0x01000013);
if (nvkm_msec(device, 2000,
if (!(nvkm_rd32(device, 0x610490) & 0x80000000))
break;
) < 0) {
nvkm_error(subdev, "core init: %08x\n",
nvkm_rd32(device, 0x610490));
return -EBUSY;
}
return 0;
}
