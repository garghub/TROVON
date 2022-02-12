static int nfp_meid(u8 island_id, u8 menum)
{
return (island_id & 0x3F) == island_id && menum < 12 ?
(island_id << 4) | (menum + 4) : -1;
}
static void
nfp_rtsym_sw_entry_init(struct nfp_rtsym_table *cache, u32 strtab_size,
struct nfp_rtsym *sw, struct nfp_rtsym_entry *fw)
{
sw->type = fw->type;
sw->name = cache->strtab + le16_to_cpu(fw->name) % strtab_size;
sw->addr = ((u64)fw->addr_hi << 32) | le32_to_cpu(fw->addr_lo);
sw->size = ((u64)fw->size_hi << 32) | le32_to_cpu(fw->size_lo);
switch (fw->target) {
case SYM_TGT_LMEM:
sw->target = NFP_RTSYM_TARGET_LMEM;
break;
case SYM_TGT_EMU_CACHE:
sw->target = NFP_RTSYM_TARGET_EMU_CACHE;
break;
default:
sw->target = fw->target;
break;
}
if (fw->menum != 0xff)
sw->domain = nfp_meid(fw->island, fw->menum);
else if (fw->island != 0xff)
sw->domain = fw->island;
else
sw->domain = -1;
}
struct nfp_rtsym_table *nfp_rtsym_table_read(struct nfp_cpp *cpp)
{
struct nfp_rtsym_table *rtbl;
const struct nfp_mip *mip;
mip = nfp_mip_open(cpp);
rtbl = __nfp_rtsym_table_read(cpp, mip);
nfp_mip_close(mip);
return rtbl;
}
struct nfp_rtsym_table *
__nfp_rtsym_table_read(struct nfp_cpp *cpp, const struct nfp_mip *mip)
{
const u32 dram = NFP_CPP_ID(NFP_CPP_TARGET_MU, NFP_CPP_ACTION_RW, 0) |
NFP_ISL_EMEM0;
u32 strtab_addr, symtab_addr, strtab_size, symtab_size;
struct nfp_rtsym_entry *rtsymtab;
struct nfp_rtsym_table *cache;
int err, n, size;
if (!mip)
return NULL;
nfp_mip_strtab(mip, &strtab_addr, &strtab_size);
nfp_mip_symtab(mip, &symtab_addr, &symtab_size);
if (!symtab_size || !strtab_size || symtab_size % sizeof(*rtsymtab))
return NULL;
symtab_size = round_up(symtab_size, 8);
strtab_size = round_up(strtab_size, 8);
rtsymtab = kmalloc(symtab_size, GFP_KERNEL);
if (!rtsymtab)
return NULL;
size = sizeof(*cache);
size += symtab_size / sizeof(*rtsymtab) * sizeof(struct nfp_rtsym);
size += strtab_size + 1;
cache = kmalloc(size, GFP_KERNEL);
if (!cache)
goto exit_free_rtsym_raw;
cache->cpp = cpp;
cache->num = symtab_size / sizeof(*rtsymtab);
cache->strtab = (void *)&cache->symtab[cache->num];
err = nfp_cpp_read(cpp, dram, symtab_addr, rtsymtab, symtab_size);
if (err != symtab_size)
goto exit_free_cache;
err = nfp_cpp_read(cpp, dram, strtab_addr, cache->strtab, strtab_size);
if (err != strtab_size)
goto exit_free_cache;
cache->strtab[strtab_size] = '\0';
for (n = 0; n < cache->num; n++)
nfp_rtsym_sw_entry_init(cache, strtab_size,
&cache->symtab[n], &rtsymtab[n]);
kfree(rtsymtab);
return cache;
exit_free_cache:
kfree(cache);
exit_free_rtsym_raw:
kfree(rtsymtab);
return NULL;
}
int nfp_rtsym_count(struct nfp_rtsym_table *rtbl)
{
if (!rtbl)
return -EINVAL;
return rtbl->num;
}
const struct nfp_rtsym *nfp_rtsym_get(struct nfp_rtsym_table *rtbl, int idx)
{
if (!rtbl)
return NULL;
if (idx >= rtbl->num)
return NULL;
return &rtbl->symtab[idx];
}
const struct nfp_rtsym *
nfp_rtsym_lookup(struct nfp_rtsym_table *rtbl, const char *name)
{
int n;
if (!rtbl)
return NULL;
for (n = 0; n < rtbl->num; n++)
if (strcmp(name, rtbl->symtab[n].name) == 0)
return &rtbl->symtab[n];
return NULL;
}
u64 nfp_rtsym_read_le(struct nfp_rtsym_table *rtbl, const char *name,
int *error)
{
const struct nfp_rtsym *sym;
u32 val32, id;
u64 val;
int err;
sym = nfp_rtsym_lookup(rtbl, name);
if (!sym) {
err = -ENOENT;
goto exit;
}
id = NFP_CPP_ISLAND_ID(sym->target, NFP_CPP_ACTION_RW, 0, sym->domain);
switch (sym->size) {
case 4:
err = nfp_cpp_readl(rtbl->cpp, id, sym->addr, &val32);
val = val32;
break;
case 8:
err = nfp_cpp_readq(rtbl->cpp, id, sym->addr, &val);
break;
default:
nfp_err(rtbl->cpp,
"rtsym '%s' unsupported or non-scalar size: %lld\n",
name, sym->size);
err = -EINVAL;
break;
}
if (err == sym->size)
err = 0;
else if (err >= 0)
err = -EIO;
exit:
if (error)
*error = err;
if (err)
return ~0ULL;
return val;
}
u8 __iomem *
nfp_rtsym_map(struct nfp_rtsym_table *rtbl, const char *name, const char *id,
unsigned int min_size, struct nfp_cpp_area **area)
{
const struct nfp_rtsym *sym;
u8 __iomem *mem;
sym = nfp_rtsym_lookup(rtbl, name);
if (!sym)
return (u8 __iomem *)ERR_PTR(-ENOENT);
if (sym->size < min_size) {
nfp_err(rtbl->cpp, "Symbol %s too small\n", name);
return (u8 __iomem *)ERR_PTR(-EINVAL);
}
mem = nfp_cpp_map_area(rtbl->cpp, id, sym->domain, sym->target,
sym->addr, sym->size, area);
if (IS_ERR(mem)) {
nfp_err(rtbl->cpp, "Failed to map symbol %s: %ld\n",
name, PTR_ERR(mem));
return mem;
}
return mem;
}
