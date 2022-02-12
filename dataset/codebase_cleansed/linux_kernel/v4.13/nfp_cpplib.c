int nfp_cpp_readl(struct nfp_cpp *cpp, u32 cpp_id,
unsigned long long address, u32 *value)
{
u8 tmp[4];
int err;
err = nfp_cpp_read(cpp, cpp_id, address, tmp, sizeof(tmp));
*value = get_unaligned_le32(tmp);
return err;
}
int nfp_cpp_writel(struct nfp_cpp *cpp, u32 cpp_id,
unsigned long long address, u32 value)
{
u8 tmp[4];
put_unaligned_le32(value, tmp);
return nfp_cpp_write(cpp, cpp_id, address, tmp, sizeof(tmp));
}
int nfp_cpp_readq(struct nfp_cpp *cpp, u32 cpp_id,
unsigned long long address, u64 *value)
{
u8 tmp[8];
int err;
err = nfp_cpp_read(cpp, cpp_id, address, tmp, sizeof(tmp));
*value = get_unaligned_le64(tmp);
return err;
}
int nfp_cpp_writeq(struct nfp_cpp *cpp, u32 cpp_id,
unsigned long long address, u64 value)
{
u8 tmp[8];
put_unaligned_le64(value, tmp);
return nfp_cpp_write(cpp, cpp_id, address, tmp, sizeof(tmp));
}
int nfp_cpp_model_autodetect(struct nfp_cpp *cpp, u32 *model)
{
const u32 arm_id = NFP_CPP_ID(NFP_CPP_TARGET_ARM, 0, 0);
u32 reg;
int err;
err = nfp_cpp_readl(cpp, arm_id, NFP6000_ARM_GCSR_SOFTMODEL0, model);
if (err < 0)
return err;
*model &= ~0xff;
err = nfp_xpb_readl(cpp, NFP_XPB_DEVICE(1, 1, 16) + NFP_PL_DEVICE_ID,
&reg);
if (err < 0)
return err;
*model |= (NFP_PL_DEVICE_ID_MASK & reg) - 0x10;
return 0;
}
static u8 nfp_bytemask(int width, u64 addr)
{
if (width == 8)
return 0xff;
else if (width == 4)
return 0x0f << (addr & 4);
else if (width == 2)
return 0x03 << (addr & 6);
else if (width == 1)
return 0x01 << (addr & 7);
else
return 0;
}
int nfp_cpp_explicit_read(struct nfp_cpp *cpp, u32 cpp_id,
u64 addr, void *buff, size_t len, int width_read)
{
struct nfp_cpp_explicit *expl;
char *tmp = buff;
int err, i, incr;
u8 byte_mask;
if (len & (width_read - 1))
return -EINVAL;
expl = nfp_cpp_explicit_acquire(cpp);
if (!expl)
return -EBUSY;
incr = min_t(int, 16 * width_read, 128);
incr = min_t(int, incr, len);
if (NFP_CPP_ID_ACTION_of(cpp_id) == NFP_CPP_ACTION_RW)
cpp_id = NFP_CPP_ID(NFP_CPP_ID_TARGET_of(cpp_id), 0,
NFP_CPP_ID_TOKEN_of(cpp_id));
byte_mask = nfp_bytemask(width_read, addr);
nfp_cpp_explicit_set_target(expl, cpp_id,
incr / width_read - 1, byte_mask);
nfp_cpp_explicit_set_posted(expl, 1, 0, NFP_SIGNAL_PUSH,
0, NFP_SIGNAL_NONE);
for (i = 0; i < len; i += incr, addr += incr, tmp += incr) {
if (i + incr > len) {
incr = len - i;
nfp_cpp_explicit_set_target(expl, cpp_id,
incr / width_read - 1,
0xff);
}
err = nfp_cpp_explicit_do(expl, addr);
if (err < 0)
goto exit_release;
err = nfp_cpp_explicit_get(expl, tmp, incr);
if (err < 0)
goto exit_release;
}
err = len;
exit_release:
nfp_cpp_explicit_release(expl);
return err;
}
int nfp_cpp_explicit_write(struct nfp_cpp *cpp, u32 cpp_id, u64 addr,
const void *buff, size_t len, int width_write)
{
struct nfp_cpp_explicit *expl;
const char *tmp = buff;
int err, i, incr;
u8 byte_mask;
if (len & (width_write - 1))
return -EINVAL;
expl = nfp_cpp_explicit_acquire(cpp);
if (!expl)
return -EBUSY;
incr = min_t(int, 16 * width_write, 128);
incr = min_t(int, incr, len);
if (NFP_CPP_ID_ACTION_of(cpp_id) == NFP_CPP_ACTION_RW)
cpp_id = NFP_CPP_ID(NFP_CPP_ID_TARGET_of(cpp_id), 1,
NFP_CPP_ID_TOKEN_of(cpp_id));
byte_mask = nfp_bytemask(width_write, addr);
nfp_cpp_explicit_set_target(expl, cpp_id,
incr / width_write - 1, byte_mask);
nfp_cpp_explicit_set_posted(expl, 1, 0, NFP_SIGNAL_PULL,
0, NFP_SIGNAL_NONE);
for (i = 0; i < len; i += incr, addr += incr, tmp += incr) {
if (i + incr > len) {
incr = len - i;
nfp_cpp_explicit_set_target(expl, cpp_id,
incr / width_write - 1,
0xff);
}
err = nfp_cpp_explicit_put(expl, tmp, incr);
if (err < 0)
goto exit_release;
err = nfp_cpp_explicit_do(expl, addr);
if (err < 0)
goto exit_release;
}
err = len;
exit_release:
nfp_cpp_explicit_release(expl);
return err;
}
u8 __iomem *
nfp_cpp_map_area(struct nfp_cpp *cpp, const char *name, int domain, int target,
u64 addr, unsigned long size, struct nfp_cpp_area **area)
{
u8 __iomem *res;
u32 dest;
dest = NFP_CPP_ISLAND_ID(target, NFP_CPP_ACTION_RW, 0, domain);
*area = nfp_cpp_area_alloc_acquire(cpp, name, dest, addr, size);
if (!*area)
goto err_eio;
res = nfp_cpp_area_iomem(*area);
if (!res)
goto err_release_free;
return res;
err_release_free:
nfp_cpp_area_release_free(*area);
err_eio:
return (u8 __iomem *)ERR_PTR(-EIO);
}
