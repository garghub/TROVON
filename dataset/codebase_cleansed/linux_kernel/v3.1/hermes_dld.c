static inline u32
dblock_addr(const struct dblock *blk)
{
return le32_to_cpu(blk->addr);
}
static inline u32
dblock_len(const struct dblock *blk)
{
return le16_to_cpu(blk->len);
}
static inline u32
pdr_id(const struct pdr *pdr)
{
return le32_to_cpu(pdr->id);
}
static inline u32
pdr_addr(const struct pdr *pdr)
{
return le32_to_cpu(pdr->addr);
}
static inline u32
pdr_len(const struct pdr *pdr)
{
return le32_to_cpu(pdr->len);
}
static inline u32
pdi_id(const struct pdi *pdi)
{
return le16_to_cpu(pdi->id);
}
static inline u32
pdi_len(const struct pdi *pdi)
{
return 2 * (le16_to_cpu(pdi->len) - 1);
}
static const struct pdr *
hermes_find_pdr(const struct pdr *first_pdr, u32 record_id, const void *end)
{
const struct pdr *pdr = first_pdr;
end -= sizeof(struct pdr);
while (((void *) pdr <= end) &&
(pdr_id(pdr) != PDI_END)) {
if (pdr_len(pdr) < 2)
return NULL;
if (pdr_id(pdr) == record_id)
return pdr;
pdr = (struct pdr *) pdr->next;
}
return NULL;
}
static const struct pdi *
hermes_find_pdi(const struct pdi *first_pdi, u32 record_id, const void *end)
{
const struct pdi *pdi = first_pdi;
end -= sizeof(struct pdi);
while (((void *) pdi <= end) &&
(pdi_id(pdi) != PDI_END)) {
if (pdi_id(pdi) == record_id)
return pdi;
pdi = (struct pdi *) &pdi->data[pdi_len(pdi)];
}
return NULL;
}
static int
hermes_plug_pdi(struct hermes *hw, const struct pdr *first_pdr,
const struct pdi *pdi, const void *pdr_end)
{
const struct pdr *pdr;
pdr = hermes_find_pdr(first_pdr, pdi_id(pdi), pdr_end);
if (!pdr)
return 0;
if (pdi_len(pdi) != pdr_len(pdr))
return -EINVAL;
hw->ops->program(hw, pdi->data, pdr_addr(pdr), pdi_len(pdi));
return 0;
}
int hermes_apply_pda(struct hermes *hw,
const char *first_pdr,
const void *pdr_end,
const __le16 *pda,
const void *pda_end)
{
int ret;
const struct pdi *pdi;
const struct pdr *pdr;
pdr = (const struct pdr *) first_pdr;
pda_end -= sizeof(struct pdi);
pdi = (const struct pdi *) (pda + 2);
while (((void *) pdi <= pda_end) &&
(pdi_id(pdi) != PDI_END)) {
ret = hermes_plug_pdi(hw, pdr, pdi, pdr_end);
if (ret)
return ret;
pdi = (const struct pdi *) &pdi->data[pdi_len(pdi)];
}
return 0;
}
size_t
hermes_blocks_length(const char *first_block, const void *end)
{
const struct dblock *blk = (const struct dblock *) first_block;
int total_len = 0;
int len;
end -= sizeof(*blk);
while (((void *) blk <= end) &&
(dblock_addr(blk) != BLOCK_END)) {
len = dblock_len(blk);
total_len += sizeof(*blk) + len;
blk = (struct dblock *) &blk->data[len];
}
return total_len;
}
int hermes_program(struct hermes *hw, const char *first_block, const void *end)
{
const struct dblock *blk;
u32 blkaddr;
u32 blklen;
int err = 0;
blk = (const struct dblock *) first_block;
if ((void *) blk > (end - sizeof(*blk)))
return -EIO;
blkaddr = dblock_addr(blk);
blklen = dblock_len(blk);
while ((blkaddr != BLOCK_END) &&
(((void *) blk + blklen) <= end)) {
pr_debug(PFX "Programming block of length %d "
"to address 0x%08x\n", blklen, blkaddr);
err = hw->ops->program(hw, blk->data, blkaddr, blklen);
if (err)
break;
blk = (const struct dblock *) &blk->data[blklen];
if ((void *) blk > (end - sizeof(*blk)))
return -EIO;
blkaddr = dblock_addr(blk);
blklen = dblock_len(blk);
}
return err;
}
int hermes_apply_pda_with_defaults(struct hermes *hw,
const char *first_pdr,
const void *pdr_end,
const __le16 *pda,
const void *pda_end)
{
const struct pdr *pdr = (const struct pdr *) first_pdr;
const struct pdi *first_pdi = (const struct pdi *) &pda[2];
const struct pdi *pdi;
const struct pdi *default_pdi = NULL;
const struct pdi *outdoor_pdi;
int record_id;
pdr_end -= sizeof(struct pdr);
while (((void *) pdr <= pdr_end) &&
(pdr_id(pdr) != PDI_END)) {
if (pdr_len(pdr) < 2)
break;
record_id = pdr_id(pdr);
pdi = hermes_find_pdi(first_pdi, record_id, pda_end);
if (pdi)
pr_debug(PFX "Found record 0x%04x at %p\n",
record_id, pdi);
switch (record_id) {
case 0x110:
case 0x120:
outdoor_pdi = hermes_find_pdi(first_pdi, record_id + 1,
pda_end);
default_pdi = NULL;
if (outdoor_pdi) {
pdi = outdoor_pdi;
pr_debug(PFX
"Using outdoor record 0x%04x at %p\n",
record_id + 1, pdi);
}
break;
case 0x5:
default_pdi = (struct pdi *) &DEFAULT_PDR(0x0005);
break;
case 0x108:
default_pdi = (struct pdi *) &DEFAULT_PDR(0x0108);
break;
case 0x109:
default_pdi = (struct pdi *) &DEFAULT_PDR(0x0109);
break;
case 0x150:
default_pdi = (struct pdi *) &DEFAULT_PDR(0x0150);
break;
case 0x160:
default_pdi = (struct pdi *) &DEFAULT_PDR(0x0160);
break;
case 0x161:
default_pdi = (struct pdi *) &DEFAULT_PDR(0x0161);
break;
default:
default_pdi = NULL;
break;
}
if (!pdi && default_pdi) {
pdi = default_pdi;
pr_debug(PFX "Using default record 0x%04x at %p\n",
record_id, pdi);
}
if (pdi) {
if ((pdi_len(pdi) == pdr_len(pdr)) &&
((void *) pdi->data + pdi_len(pdi) < pda_end)) {
hw->ops->program(hw, pdi->data, pdr_addr(pdr),
pdi_len(pdi));
}
}
pdr++;
}
return 0;
}
