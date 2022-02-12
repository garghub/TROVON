static int target_rw(u32 cpp_id, int pp, int start, int len)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(0, 0, 0, pp);
AT(1, 0, pp, 0);
AT(NFP_CPP_ACTION_RW, 0, pp, pp);
default:
return -EINVAL;
}
}
static int nfp6000_nbi_dma(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(0, 0, 0, P64);
AT(1, 0, P64, 0);
AT(NFP_CPP_ACTION_RW, 0, P64, P64);
default:
return -EINVAL;
}
}
static int nfp6000_nbi_stats(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(0, 0, 0, P32);
AT(1, 0, P32, 0);
AT(NFP_CPP_ACTION_RW, 0, P32, P32);
default:
return -EINVAL;
}
}
static int nfp6000_nbi_tm(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(0, 0, 0, P64);
AT(1, 0, P64, 0);
AT(NFP_CPP_ACTION_RW, 0, P64, P64);
default:
return -EINVAL;
}
}
static int nfp6000_nbi_ppc(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(0, 0, 0, P64);
AT(1, 0, P64, 0);
AT(NFP_CPP_ACTION_RW, 0, P64, P64);
default:
return -EINVAL;
}
}
static int nfp6000_nbi(u32 cpp_id, u64 address)
{
u64 rel_addr = address & 0x3fFFFF;
if (rel_addr < (1 << 20))
return nfp6000_nbi_dma(cpp_id);
if (rel_addr < (2 << 20))
return nfp6000_nbi_stats(cpp_id);
if (rel_addr < (3 << 20))
return nfp6000_nbi_tm(cpp_id);
return nfp6000_nbi_ppc(cpp_id);
}
static int nfp6000_mu_common(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(NFP_CPP_ACTION_RW, 0, P64, P64);
AT(NFP_CPP_ACTION_RW, 1, P64, P64);
AT(NFP_CPP_ACTION_RW, 2, P64, P64);
AT(NFP_CPP_ACTION_RW, 3, P64, P64);
AT(0, 0, 0, P64);
AT(0, 1, 0, P64);
AT(0, 2, 0, P64);
AT(0, 3, 0, P64);
AT(1, 0, P64, 0);
AT(1, 1, P64, 0);
AT(1, 2, P64, 0);
AT(1, 3, P64, 0);
AT(3, 0, 0, P32);
AT(3, 2, P32, 0);
AT(4, 0, P32, 0);
AT(4, 2, 0, 0);
AT(4, 3, 0, P32);
AT(5, 0, P32, 0);
AT(5, 3, 0, P32);
AT(6, 0, P32, 0);
AT(6, 3, 0, P32);
AT(7, 0, P32, 0);
AT(7, 3, 0, P32);
AT(8, 0, P32, 0);
AT(8, 3, 0, P32);
AT(9, 0, P32, 0);
AT(9, 3, 0, P32);
AT(10, 0, P32, 0);
AT(10, 3, 0, P32);
AT(13, 0, 0, P32);
AT(13, 1, 0, P32);
AT(13, 2, P32, 0);
AT(15, 0, P32, 0);
AT(15, 3, 0, P32);
AT(28, 0, 0, P32);
AT(28, 1, 0, P32);
AT(28, 2, 0, P32);
AT(28, 3, 0, P32);
AT(31, 0, P32, 0);
AT(31, 1, P32, 0);
AT(31, 2, P32, 0);
AT(31, 3, P32, 0);
default:
return -EINVAL;
}
}
static int nfp6000_mu_ctm(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(16, 1, 0, P32);
AT(17, 1, 0, P32);
AT(17, 3, 0, P64);
AT(18, 2, 0, P64);
AT(18, 3, 0, P64);
AT(21, 0, 0, P64);
AT(21, 1, 0, P64);
AT(21, 2, 0, P64);
AT(21, 3, 0, P64);
default:
return nfp6000_mu_common(cpp_id);
}
}
static int nfp6000_mu_emu(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(18, 0, 0, P32);
AT(18, 1, 0, P32);
AT(18, 2, P32, 0);
AT(18, 3, P32, 0);
AT(20, 2, P32, 0);
AT(21, 0, 0, P32);
AT(21, 1, 0, P32);
AT(21, 2, 0, P32);
AT(22, 0, 0, P32);
AT(22, 1, 0, P32);
AT(22, 2, 0, P32);
default:
return nfp6000_mu_common(cpp_id);
}
}
static int nfp6000_mu_imu(u32 cpp_id)
{
return nfp6000_mu_common(cpp_id);
}
static int nfp6000_mu(u32 cpp_id, u64 address)
{
int pp;
if (address < 0x2000000000ULL)
pp = nfp6000_mu_ctm(cpp_id);
else if (address < 0x8000000000ULL)
pp = nfp6000_mu_emu(cpp_id);
else if (address < 0x9800000000ULL)
pp = nfp6000_mu_ctm(cpp_id);
else if (address < 0x9C00000000ULL)
pp = nfp6000_mu_emu(cpp_id);
else if (address < 0xA000000000ULL)
pp = nfp6000_mu_imu(cpp_id);
else
pp = nfp6000_mu_ctm(cpp_id);
return pp;
}
static int nfp6000_ila(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(0, 1, 0, P32);
AT(2, 0, 0, P32);
AT(3, 0, P32, 0);
default:
return target_rw(cpp_id, P32, 48, 4);
}
}
static int nfp6000_pci(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(2, 0, 0, P32);
AT(3, 0, P32, 0);
default:
return target_rw(cpp_id, P32, 4, 4);
}
}
static int nfp6000_crypto(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(2, 0, P64, 0);
default:
return target_rw(cpp_id, P64, 12, 4);
}
}
static int nfp6000_cap_xpb(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(0, 1, 0, P32);
AT(0, 2, P32, 0);
AT(1, 1, P32, 0);
AT(1, 2, P32, 0);
AT(2, 0, 0, P32);
AT(2, 1, 0, P32);
AT(2, 2, 0, P32);
AT(2, 3, 0, P32);
AT(3, 0, P32, 0);
AT(3, 1, P32, 0);
AT(3, 2, P32, 0);
AT(3, 3, P32, 0);
AT(NFP_CPP_ACTION_RW, 1, P32, P32);
default:
return target_rw(cpp_id, P32, 1, 63);
}
}
static int nfp6000_cls(u32 cpp_id)
{
switch (cpp_id & NFP_CPP_ID(0, ~0, ~0)) {
AT(0, 3, P32, 0);
AT(2, 0, P32, 0);
AT(2, 1, P32, 0);
AT(4, 0, P32, 0);
AT(4, 1, P32, 0);
AT(6, 0, P32, 0);
AT(6, 1, P32, 0);
AT(6, 2, P32, 0);
AT(8, 2, P32, 0);
AT(8, 3, P32, 0);
AT(9, 0, 0, P32);
AT(9, 1, 0, P32);
AT(9, 2, 0, P32);
AT(9, 3, 0, P32);
AT(10, 0, P32, 0);
AT(10, 2, P32, 0);
AT(14, 0, P32, 0);
AT(15, 1, 0, P32);
AT(17, 2, P32, 0);
AT(24, 0, 0, P32);
AT(24, 1, P32, 0);
AT(25, 0, 0, P32);
AT(25, 1, P32, 0);
default:
return target_rw(cpp_id, P32, 0, 64);
}
}
int nfp_target_pushpull(u32 cpp_id, u64 address)
{
switch (NFP_CPP_ID_TARGET_of(cpp_id)) {
case NFP_CPP_TARGET_NBI:
return nfp6000_nbi(cpp_id, address);
case NFP_CPP_TARGET_QDR:
return target_rw(cpp_id, P32, 24, 4);
case NFP_CPP_TARGET_ILA:
return nfp6000_ila(cpp_id);
case NFP_CPP_TARGET_MU:
return nfp6000_mu(cpp_id, address);
case NFP_CPP_TARGET_PCIE:
return nfp6000_pci(cpp_id);
case NFP_CPP_TARGET_ARM:
if (address < 0x10000)
return target_rw(cpp_id, P64, 1, 1);
else
return target_rw(cpp_id, P32, 1, 1);
case NFP_CPP_TARGET_CRYPTO:
return nfp6000_crypto(cpp_id);
case NFP_CPP_TARGET_CT_XPB:
return nfp6000_cap_xpb(cpp_id);
case NFP_CPP_TARGET_CLS:
return nfp6000_cls(cpp_id);
case 0:
return target_rw(cpp_id, P32, 4, 4);
default:
return -EINVAL;
}
}
static int nfp_decode_basic(u64 addr, int *dest_island, int cpp_tgt,
int mode, bool addr40, int isld1, int isld0)
{
int iid_lsb, idx_lsb;
if (cpp_tgt == NFP_CPP_TARGET_MU || cpp_tgt == NFP_CPP_TARGET_CT_XPB)
return -EINVAL;
switch (mode) {
case 0:
iid_lsb = addr40 ? 34 : 26;
*dest_island = (addr >> iid_lsb) & 0x3F;
return 0;
case 1:
idx_lsb = addr40 ? 39 : 31;
if (addr & BIT_ULL(idx_lsb))
*dest_island = isld1;
else
*dest_island = isld0;
return 0;
case 2:
isld0 &= ~1;
isld1 &= ~1;
idx_lsb = addr40 ? 39 : 31;
iid_lsb = idx_lsb - 1;
if (addr & BIT_ULL(idx_lsb))
*dest_island = isld1 | (int)((addr >> iid_lsb) & 1);
else
*dest_island = isld0 | (int)((addr >> iid_lsb) & 1);
return 0;
case 3:
isld0 &= ~3;
isld1 &= ~3;
idx_lsb = addr40 ? 39 : 31;
iid_lsb = idx_lsb - 2;
if (addr & BIT_ULL(idx_lsb))
*dest_island = isld1 | (int)((addr >> iid_lsb) & 3);
else
*dest_island = isld0 | (int)((addr >> iid_lsb) & 3);
return 0;
default:
return -EINVAL;
}
}
static int nfp_encode_basic_qdr(u64 addr, int dest_island, int cpp_tgt,
int mode, bool addr40, int isld1, int isld0)
{
int v, ret;
ret = nfp_decode_basic(addr, &v, cpp_tgt, mode, addr40, isld1, isld0);
if (ret)
return ret;
if (dest_island != -1 && dest_island != v)
return -EINVAL;
return 0;
}
static int nfp_encode_basic_search(u64 *addr, int dest_island, int *isld,
int iid_lsb, int idx_lsb, int v_max)
{
int i, v;
for (i = 0; i < 2; i++)
for (v = 0; v < v_max; v++) {
if (dest_island != (isld[i] | v))
continue;
*addr &= ~GENMASK_ULL(idx_lsb, iid_lsb);
*addr |= ((u64)i << idx_lsb);
*addr |= ((u64)v << iid_lsb);
return 0;
}
return -ENODEV;
}
static int nfp_encode_basic(u64 *addr, int dest_island, int cpp_tgt,
int mode, bool addr40, int isld1, int isld0)
{
int iid_lsb, idx_lsb;
int isld[2];
u64 v64;
isld[0] = isld0;
isld[1] = isld1;
if (cpp_tgt == NFP_CPP_TARGET_MU || cpp_tgt == NFP_CPP_TARGET_CT_XPB)
return -EINVAL;
switch (mode) {
case 0:
if (cpp_tgt == NFP_CPP_TARGET_QDR && !addr40)
return nfp_encode_basic_qdr(*addr, cpp_tgt, dest_island,
mode, addr40, isld1, isld0);
iid_lsb = addr40 ? 34 : 26;
v64 = GENMASK_ULL(iid_lsb + 5, iid_lsb);
*addr &= ~v64;
*addr |= ((u64)dest_island << iid_lsb) & v64;
return 0;
case 1:
if (cpp_tgt == NFP_CPP_TARGET_QDR && !addr40)
return nfp_encode_basic_qdr(*addr, cpp_tgt, dest_island,
mode, addr40, isld1, isld0);
idx_lsb = addr40 ? 39 : 31;
if (dest_island == isld0) {
*addr &= ~BIT_ULL(idx_lsb);
return 0;
}
if (dest_island == isld1) {
*addr |= BIT_ULL(idx_lsb);
return 0;
}
return -ENODEV;
case 2:
if (cpp_tgt == NFP_CPP_TARGET_QDR && !addr40)
return nfp_encode_basic_qdr(*addr, cpp_tgt, dest_island,
mode, addr40, isld1, isld0);
isld[0] &= ~1;
isld[1] &= ~1;
idx_lsb = addr40 ? 39 : 31;
iid_lsb = idx_lsb - 1;
return nfp_encode_basic_search(addr, dest_island, isld,
iid_lsb, idx_lsb, 2);
case 3:
if (cpp_tgt == NFP_CPP_TARGET_QDR && !addr40)
return nfp_encode_basic_qdr(*addr, cpp_tgt, dest_island,
mode, addr40, isld1, isld0);
isld[0] &= ~3;
isld[1] &= ~3;
idx_lsb = addr40 ? 39 : 31;
iid_lsb = idx_lsb - 2;
return nfp_encode_basic_search(addr, dest_island, isld,
iid_lsb, idx_lsb, 4);
default:
return -EINVAL;
}
}
static int nfp_encode_mu(u64 *addr, int dest_island, int mode,
bool addr40, int isld1, int isld0)
{
int iid_lsb, idx_lsb, locality_lsb;
int isld[2];
u64 v64;
int da;
isld[0] = isld0;
isld[1] = isld1;
locality_lsb = nfp_cppat_mu_locality_lsb(mode, addr40);
if (((*addr >> locality_lsb) & 3) == _NIC_NFP6000_MU_LOCALITY_DIRECT)
da = 1;
else
da = 0;
switch (mode) {
case 0:
iid_lsb = addr40 ? 32 : 24;
v64 = GENMASK_ULL(iid_lsb + 5, iid_lsb);
*addr &= ~v64;
*addr |= (((u64)dest_island) << iid_lsb) & v64;
return 0;
case 1:
if (da) {
iid_lsb = addr40 ? 32 : 24;
v64 = GENMASK_ULL(iid_lsb + 5, iid_lsb);
*addr &= ~v64;
*addr |= (((u64)dest_island) << iid_lsb) & v64;
return 0;
}
idx_lsb = addr40 ? 37 : 29;
if (dest_island == isld0) {
*addr &= ~BIT_ULL(idx_lsb);
return 0;
}
if (dest_island == isld1) {
*addr |= BIT_ULL(idx_lsb);
return 0;
}
return -ENODEV;
case 2:
if (da) {
iid_lsb = addr40 ? 32 : 24;
v64 = GENMASK_ULL(iid_lsb + 5, iid_lsb);
*addr &= ~v64;
*addr |= (((u64)dest_island) << iid_lsb) & v64;
return 0;
}
isld[0] &= ~1;
isld[1] &= ~1;
idx_lsb = addr40 ? 37 : 29;
iid_lsb = idx_lsb - 1;
return nfp_encode_basic_search(addr, dest_island, isld,
iid_lsb, idx_lsb, 2);
case 3:
if (dest_island > 0 && (dest_island < 24 || dest_island > 26)) {
*addr |= ((u64)_NIC_NFP6000_MU_LOCALITY_DIRECT)
<< locality_lsb;
da = 1;
}
if (da) {
iid_lsb = addr40 ? 32 : 24;
v64 = GENMASK_ULL(iid_lsb + 5, iid_lsb);
*addr &= ~v64;
*addr |= (((u64)dest_island) << iid_lsb) & v64;
return 0;
}
isld[0] &= ~3;
isld[1] &= ~3;
idx_lsb = addr40 ? 37 : 29;
iid_lsb = idx_lsb - 2;
return nfp_encode_basic_search(addr, dest_island, isld,
iid_lsb, idx_lsb, 4);
default:
return -EINVAL;
}
}
static int nfp_cppat_addr_encode(u64 *addr, int dest_island, int cpp_tgt,
int mode, bool addr40, int isld1, int isld0)
{
switch (cpp_tgt) {
case NFP_CPP_TARGET_NBI:
case NFP_CPP_TARGET_QDR:
case NFP_CPP_TARGET_ILA:
case NFP_CPP_TARGET_PCIE:
case NFP_CPP_TARGET_ARM:
case NFP_CPP_TARGET_CRYPTO:
case NFP_CPP_TARGET_CLS:
return nfp_encode_basic(addr, dest_island, cpp_tgt, mode,
addr40, isld1, isld0);
case NFP_CPP_TARGET_MU:
return nfp_encode_mu(addr, dest_island, mode,
addr40, isld1, isld0);
case NFP_CPP_TARGET_CT_XPB:
if (mode != 1 || addr40)
return -EINVAL;
*addr &= ~GENMASK_ULL(29, 24);
*addr |= ((u64)dest_island << 24) & GENMASK_ULL(29, 24);
return 0;
default:
return -EINVAL;
}
}
int nfp_target_cpp(u32 cpp_island_id, u64 cpp_island_address,
u32 *cpp_target_id, u64 *cpp_target_address,
const u32 *imb_table)
{
const int island = NFP_CPP_ID_ISLAND_of(cpp_island_id);
const int target = NFP_CPP_ID_TARGET_of(cpp_island_id);
u32 imb;
int err;
if (target < 0 || target >= 16)
return -EINVAL;
if (island == 0) {
*cpp_target_id = cpp_island_id;
*cpp_target_address = cpp_island_address;
return 0;
}
if (!imb_table)
return -EINVAL;
imb = imb_table[target];
*cpp_target_address = cpp_island_address;
err = nfp_cppat_addr_encode(cpp_target_address, island, target,
((imb >> 13) & 7), ((imb >> 12) & 1),
((imb >> 6) & 0x3f), ((imb >> 0) & 0x3f));
if (err)
return err;
*cpp_target_id = NFP_CPP_ID(target,
NFP_CPP_ID_ACTION_of(cpp_island_id),
NFP_CPP_ID_TOKEN_of(cpp_island_id));
return 0;
}
