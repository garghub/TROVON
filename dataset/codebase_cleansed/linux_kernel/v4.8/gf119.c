int\r\ngf119_dma_new(struct nvkm_device *device, int index, struct nvkm_dma **pdma)\r\n{\r\nreturn nvkm_dma_new_(&gf119_dma, device, index, pdma);\r\n}
