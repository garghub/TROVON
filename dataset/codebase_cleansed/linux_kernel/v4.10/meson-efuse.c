static int meson_efuse_read(void *context, unsigned int offset,
void *val, size_t bytes)
{
u8 *buf = val;
int ret;
ret = meson_sm_call_read(buf, SM_EFUSE_READ, offset,
bytes, 0, 0, 0);
if (ret < 0)
return ret;
return 0;
}
static int meson_efuse_probe(struct platform_device *pdev)
{
struct nvmem_device *nvmem;
unsigned int size;
if (meson_sm_call(SM_EFUSE_USER_MAX, &size, 0, 0, 0, 0, 0) < 0)
return -EINVAL;
econfig.dev = &pdev->dev;
econfig.reg_read = meson_efuse_read;
econfig.size = size;
nvmem = nvmem_register(&econfig);
if (IS_ERR(nvmem))
return PTR_ERR(nvmem);
platform_set_drvdata(pdev, nvmem);
return 0;
}
static int meson_efuse_remove(struct platform_device *pdev)
{
struct nvmem_device *nvmem = platform_get_drvdata(pdev);
return nvmem_unregister(nvmem);
}
