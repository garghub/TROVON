void *
nvkm_acr_load_firmware(const struct nvkm_subdev *subdev, const char *name,
size_t min_size)
{
const struct firmware *fw;
void *blob;
int ret;
ret = nvkm_firmware_get(subdev->device, name, &fw);
if (ret)
return ERR_PTR(ret);
if (fw->size < min_size) {
nvkm_error(subdev, "%s is smaller than expected size %zu\n",
name, min_size);
nvkm_firmware_put(fw);
return ERR_PTR(-EINVAL);
}
blob = kmemdup(fw->data, fw->size, GFP_KERNEL);
nvkm_firmware_put(fw);
if (!blob)
return ERR_PTR(-ENOMEM);
return blob;
}
