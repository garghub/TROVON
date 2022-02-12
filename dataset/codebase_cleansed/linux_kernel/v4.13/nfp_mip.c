static int
nfp_mip_try_read(struct nfp_cpp *cpp, u32 cpp_id, u64 addr, struct nfp_mip *mip)
{
int ret;
ret = nfp_cpp_read(cpp, cpp_id, addr, mip, sizeof(*mip));
if (ret != sizeof(*mip)) {
nfp_err(cpp, "Failed to read MIP data (%d, %zu)\n",
ret, sizeof(*mip));
return -EIO;
}
if (mip->signature != NFP_MIP_SIGNATURE) {
nfp_warn(cpp, "Incorrect MIP signature (0x%08x)\n",
le32_to_cpu(mip->signature));
return -EINVAL;
}
if (mip->mip_version != NFP_MIP_VERSION) {
nfp_warn(cpp, "Unsupported MIP version (%d)\n",
le32_to_cpu(mip->mip_version));
return -EINVAL;
}
return 0;
}
static int nfp_mip_read_resource(struct nfp_cpp *cpp, struct nfp_mip *mip)
{
struct nfp_nffw_info *nffw_info;
u32 cpp_id;
u64 addr;
int err;
nffw_info = nfp_nffw_info_open(cpp);
if (IS_ERR(nffw_info))
return PTR_ERR(nffw_info);
err = nfp_nffw_info_mip_first(nffw_info, &cpp_id, &addr);
if (err)
goto exit_close_nffw;
err = nfp_mip_try_read(cpp, cpp_id, addr, mip);
exit_close_nffw:
nfp_nffw_info_close(nffw_info);
return err;
}
const struct nfp_mip *nfp_mip_open(struct nfp_cpp *cpp)
{
struct nfp_mip *mip;
int err;
mip = kmalloc(sizeof(*mip), GFP_KERNEL);
if (!mip)
return NULL;
err = nfp_mip_read_resource(cpp, mip);
if (err) {
kfree(mip);
return NULL;
}
mip->name[sizeof(mip->name) - 1] = 0;
return mip;
}
void nfp_mip_close(const struct nfp_mip *mip)
{
kfree(mip);
}
const char *nfp_mip_name(const struct nfp_mip *mip)
{
return mip->name;
}
void nfp_mip_symtab(const struct nfp_mip *mip, u32 *addr, u32 *size)
{
*addr = le32_to_cpu(mip->symtab_addr);
*size = le32_to_cpu(mip->symtab_size);
}
void nfp_mip_strtab(const struct nfp_mip *mip, u32 *addr, u32 *size)
{
*addr = le32_to_cpu(mip->strtab_addr);
*size = le32_to_cpu(mip->strtab_size);
}
