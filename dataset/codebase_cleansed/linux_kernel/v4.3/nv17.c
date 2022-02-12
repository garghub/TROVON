static void
nv17_fifo_init(struct nvkm_fifo *base)
{
struct nv04_fifo *fifo = nv04_fifo(base);
struct nvkm_device *device = fifo->base.engine.subdev.device;
struct nvkm_instmem *imem = device->imem;
struct nvkm_ramht *ramht = imem->ramht;
struct nvkm_memory *ramro = imem->ramro;
struct nvkm_memory *ramfc = imem->ramfc;
nvkm_wr32(device, NV04_PFIFO_DELAY_0, 0x000000ff);
nvkm_wr32(device, NV04_PFIFO_DMA_TIMESLICE, 0x0101ffff);
nvkm_wr32(device, NV03_PFIFO_RAMHT, (0x03 << 24) |
((ramht->bits - 9) << 16) |
(ramht->gpuobj->addr >> 8));
nvkm_wr32(device, NV03_PFIFO_RAMRO, nvkm_memory_addr(ramro) >> 8);
nvkm_wr32(device, NV03_PFIFO_RAMFC, nvkm_memory_addr(ramfc) >> 8 |
0x00010000);
nvkm_wr32(device, NV03_PFIFO_CACHE1_PUSH1, fifo->base.nr - 1);
nvkm_wr32(device, NV03_PFIFO_INTR_0, 0xffffffff);
nvkm_wr32(device, NV03_PFIFO_INTR_EN_0, 0xffffffff);
nvkm_wr32(device, NV03_PFIFO_CACHE1_PUSH0, 1);
nvkm_wr32(device, NV04_PFIFO_CACHE1_PULL0, 1);
nvkm_wr32(device, NV03_PFIFO_CACHES, 1);
}
int
nv17_fifo_new(struct nvkm_device *device, int index, struct nvkm_fifo **pfifo)
{
return nv04_fifo_new_(&nv17_fifo, device, index, 32,
nv17_fifo_ramfc, pfifo);
}
