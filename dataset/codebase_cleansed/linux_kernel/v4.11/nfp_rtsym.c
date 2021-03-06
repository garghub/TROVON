static int nfp_meid(u8 island_id, u8 menum)
{
return (island_id & 0x3F) == island_id && menum < 12 ?
(island_id << 4) | (menum + 4) : -1;
}
static void
nfp_rtsym_sw_entry_init(struct nfp_rtsym_cache *cache, u32 strtab_size,
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
static int nfp_rtsymtab_probe(struct nfp_cpp *cpp)
{
const u32 dram = NFP_CPP_ID(NFP_CPP_TARGET_MU, NFP_CPP_ACTION_RW, 0) |
NFP_ISL_EMEM0;
u32 strtab_addr, symtab_addr, strtab_size, symtab_size;
struct nfp_rtsym_entry *rtsymtab;
struct nfp_rtsym_cache *cache;
const struct nfp_mip *mip;
int err, n, size;
mip = nfp_mip_open(cpp);
if (!mip)
return -EIO;
nfp_mip_strtab(mip, &strtab_addr, &strtab_size);
nfp_mip_symtab(mip, &symtab_addr, &symtab_size);
nfp_mip_close(mip);
if (!symtab_size || !strtab_size || symtab_size % sizeof(*rtsymtab))
return -ENXIO;
symtab_size = round_up(symtab_size, 8);
strtab_size = round_up(strtab_size, 8);
rtsymtab = kmalloc(symtab_size, GFP_KERNEL);
if (!rtsymtab)
return -ENOMEM;
size = sizeof(*cache);
size += symtab_size / sizeof(*rtsymtab) * sizeof(struct nfp_rtsym);
size += strtab_size + 1;
cache = kmalloc(size, GFP_KERNEL);
if (!cache) {
err = -ENOMEM;
goto err_free_rtsym_raw;
}
cache->num = symtab_size / sizeof(*rtsymtab);
cache->strtab = (void *)&cache->symtab[cache->num];
err = nfp_cpp_read(cpp, dram, symtab_addr, rtsymtab, symtab_size);
if (err != symtab_size)
goto err_free_cache;
err = nfp_cpp_read(cpp, dram, strtab_addr, cache->strtab, strtab_size);
if (err != strtab_size)
goto err_free_cache;
cache->strtab[strtab_size] = '\0';
for (n = 0; n < cache->num; n++)
nfp_rtsym_sw_entry_init(cache, strtab_size,
&cache->symtab[n], &rtsymtab[n]);
kfree(rtsymtab);
nfp_rtsym_cache_set(cpp, cache);
return 0;
err_free_cache:
kfree(cache);
err_free_rtsym_raw:
kfree(rtsymtab);
return err;
}
static struct nfp_rtsym_cache *nfp_rtsym(struct nfp_cpp *cpp)
{
struct nfp_rtsym_cache *cache;
int err;
cache = nfp_rtsym_cache(cpp);
if (cache)
return cache;
err = nfp_rtsymtab_probe(cpp);
if (err < 0)
return ERR_PTR(err);
return nfp_rtsym_cache(cpp);
}
int nfp_rtsym_count(struct nfp_cpp *cpp)
{
struct nfp_rtsym_cache *cache;
cache = nfp_rtsym(cpp);
if (IS_ERR(cache))
return PTR_ERR(cache);
return cache->num;
}
const struct nfp_rtsym *nfp_rtsym_get(struct nfp_cpp *cpp, int idx)
{
struct nfp_rtsym_cache *cache;
cache = nfp_rtsym(cpp);
if (IS_ERR(cache))
return NULL;
if (idx >= cache->num)
return NULL;
return &cache->symtab[idx];
}
const struct nfp_rtsym *nfp_rtsym_lookup(struct nfp_cpp *cpp, const char *name)
{
struct nfp_rtsym_cache *cache;
int n;
cache = nfp_rtsym(cpp);
if (IS_ERR(cache))
return NULL;
for (n = 0; n < cache->num; n++) {
if (strcmp(name, cache->symtab[n].name) == 0)
return &cache->symtab[n];
}
return NULL;
}
u64 nfp_rtsym_read_le(struct nfp_cpp *cpp, const char *name, int *error)
{
const struct nfp_rtsym *sym;
u32 val32, id;
u64 val;
int err;
sym = nfp_rtsym_lookup(cpp, name);
if (!sym) {
err = -ENOENT;
goto exit;
}
id = NFP_CPP_ISLAND_ID(sym->target, NFP_CPP_ACTION_RW, 0, sym->domain);
switch (sym->size) {
case 4:
err = nfp_cpp_readl(cpp, id, sym->addr, &val32);
val = val32;
break;
case 8:
err = nfp_cpp_readq(cpp, id, sym->addr, &val);
break;
default:
nfp_err(cpp,
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
