int
gf119_dma_new(struct nvkm_device *device, int index, struct nvkm_dma **pdma)
{
return nvkm_dma_new_(&gf119_dma, device, index, pdma);
}
