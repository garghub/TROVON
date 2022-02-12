static u32 nffw_res_info_version_get(const struct nfp_nffw_info_data *res)
{
return (le32_to_cpu(res->flags[0]) >> 16) & 0xfff;
}
static u32 nffw_res_flg_init_get(const struct nfp_nffw_info_data *res)
{
return (le32_to_cpu(res->flags[0]) >> 0) & 1;
}
static u32 nffw_fwinfo_loaded_get(const struct nffw_fwinfo *fi)
{
return (le32_to_cpu(fi->loaded__mu_da__mip_off_hi) >> 31) & 1;
}
static u32 nffw_fwinfo_mip_cppid_get(const struct nffw_fwinfo *fi)
{
return le32_to_cpu(fi->mip_cppid);
}
static u32 nffw_fwinfo_mip_mu_da_get(const struct nffw_fwinfo *fi)
{
return (le32_to_cpu(fi->loaded__mu_da__mip_off_hi) >> 8) & 1;
}
static u64 nffw_fwinfo_mip_offset_get(const struct nffw_fwinfo *fi)
{
u64 mip_off_hi = le32_to_cpu(fi->loaded__mu_da__mip_off_hi);
return (mip_off_hi & 0xFF) << 32 | le32_to_cpu(fi->mip_offset_lo);
}
static int nfp_mip_mu_locality_lsb(struct nfp_cpp *cpp)
{
unsigned int mode, addr40;
u32 xpbaddr, imbcppat;
int err;
xpbaddr = 0x000a0000 + NFP_CPP_TARGET_MU * 4;
err = nfp_xpb_readl(cpp, xpbaddr, &imbcppat);
if (err < 0)
return err;
mode = NFP_IMB_TGTADDRESSMODECFG_MODE_of(imbcppat);
addr40 = !!(imbcppat & NFP_IMB_TGTADDRESSMODECFG_ADDRMODE);
return nfp_cppat_mu_locality_lsb(mode, addr40);
}
static unsigned int
nffw_res_fwinfos(struct nfp_nffw_info_data *fwinf, struct nffw_fwinfo **arr)
{
switch (nffw_res_info_version_get(fwinf)) {
case 0:
case 1:
*arr = &fwinf->info.v1.fwinfo[0];
return NFFW_FWINFO_CNT_V1;
case 2:
*arr = &fwinf->info.v2.fwinfo[0];
return NFFW_FWINFO_CNT_V2;
default:
*arr = NULL;
return 0;
}
}
struct nfp_nffw_info *nfp_nffw_info_open(struct nfp_cpp *cpp)
{
struct nfp_nffw_info_data *fwinf;
struct nfp_nffw_info *state;
u32 info_ver;
int err;
state = kzalloc(sizeof(*state), GFP_KERNEL);
if (!state)
return ERR_PTR(-ENOMEM);
state->res = nfp_resource_acquire(cpp, NFP_RESOURCE_NFP_NFFW);
if (IS_ERR(state->res))
goto err_free;
fwinf = &state->fwinf;
if (sizeof(*fwinf) > nfp_resource_size(state->res))
goto err_release;
err = nfp_cpp_read(cpp, nfp_resource_cpp_id(state->res),
nfp_resource_address(state->res),
fwinf, sizeof(*fwinf));
if (err < sizeof(*fwinf))
goto err_release;
if (!nffw_res_flg_init_get(fwinf))
goto err_release;
info_ver = nffw_res_info_version_get(fwinf);
if (info_ver > NFFW_INFO_VERSION_CURRENT)
goto err_release;
state->cpp = cpp;
return state;
err_release:
nfp_resource_release(state->res);
err_free:
kfree(state);
return ERR_PTR(-EIO);
}
void nfp_nffw_info_close(struct nfp_nffw_info *state)
{
nfp_resource_release(state->res);
kfree(state);
}
static struct nffw_fwinfo *nfp_nffw_info_fwid_first(struct nfp_nffw_info *state)
{
struct nffw_fwinfo *fwinfo;
unsigned int cnt, i;
cnt = nffw_res_fwinfos(&state->fwinf, &fwinfo);
if (!cnt)
return NULL;
for (i = 0; i < cnt; i++)
if (nffw_fwinfo_loaded_get(&fwinfo[i]))
return &fwinfo[i];
return NULL;
}
int nfp_nffw_info_mip_first(struct nfp_nffw_info *state, u32 *cpp_id, u64 *off)
{
struct nffw_fwinfo *fwinfo;
fwinfo = nfp_nffw_info_fwid_first(state);
if (!fwinfo)
return -EINVAL;
*cpp_id = nffw_fwinfo_mip_cppid_get(fwinfo);
*off = nffw_fwinfo_mip_offset_get(fwinfo);
if (nffw_fwinfo_mip_mu_da_get(fwinfo)) {
int locality_off;
if (NFP_CPP_ID_TARGET_of(*cpp_id) != NFP_CPP_TARGET_MU)
return 0;
locality_off = nfp_mip_mu_locality_lsb(state->cpp);
if (locality_off < 0)
return locality_off;
*off &= ~(NFP_MU_ADDR_ACCESS_TYPE_MASK << locality_off);
*off |= NFP_MU_ADDR_ACCESS_TYPE_DIRECT << locality_off;
}
return 0;
}
