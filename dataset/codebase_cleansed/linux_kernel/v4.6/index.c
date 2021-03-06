ntfs_index_context *ntfs_index_ctx_get(ntfs_inode *idx_ni)
{
ntfs_index_context *ictx;
ictx = kmem_cache_alloc(ntfs_index_ctx_cache, GFP_NOFS);
if (ictx)
*ictx = (ntfs_index_context){ .idx_ni = idx_ni };
return ictx;
}
void ntfs_index_ctx_put(ntfs_index_context *ictx)
{
if (ictx->entry) {
if (ictx->is_in_root) {
if (ictx->actx)
ntfs_attr_put_search_ctx(ictx->actx);
if (ictx->base_ni)
unmap_mft_record(ictx->base_ni);
} else {
struct page *page = ictx->page;
if (page) {
BUG_ON(!PageLocked(page));
unlock_page(page);
ntfs_unmap_page(page);
}
}
}
kmem_cache_free(ntfs_index_ctx_cache, ictx);
return;
}
int ntfs_index_lookup(const void *key, const int key_len,
ntfs_index_context *ictx)
{
VCN vcn, old_vcn;
ntfs_inode *idx_ni = ictx->idx_ni;
ntfs_volume *vol = idx_ni->vol;
struct super_block *sb = vol->sb;
ntfs_inode *base_ni = idx_ni->ext.base_ntfs_ino;
MFT_RECORD *m;
INDEX_ROOT *ir;
INDEX_ENTRY *ie;
INDEX_ALLOCATION *ia;
u8 *index_end, *kaddr;
ntfs_attr_search_ctx *actx;
struct address_space *ia_mapping;
struct page *page;
int rc, err = 0;
ntfs_debug("Entering.");
BUG_ON(!NInoAttr(idx_ni));
BUG_ON(idx_ni->type != AT_INDEX_ALLOCATION);
BUG_ON(idx_ni->nr_extents != -1);
BUG_ON(!base_ni);
BUG_ON(!key);
BUG_ON(key_len <= 0);
if (!ntfs_is_collation_rule_supported(
idx_ni->itype.index.collation_rule)) {
ntfs_error(sb, "Index uses unsupported collation rule 0x%x. "
"Aborting lookup.", le32_to_cpu(
idx_ni->itype.index.collation_rule));
return -EOPNOTSUPP;
}
m = map_mft_record(base_ni);
if (IS_ERR(m)) {
ntfs_error(sb, "map_mft_record() failed with error code %ld.",
-PTR_ERR(m));
return PTR_ERR(m);
}
actx = ntfs_attr_get_search_ctx(base_ni, m);
if (unlikely(!actx)) {
err = -ENOMEM;
goto err_out;
}
err = ntfs_attr_lookup(AT_INDEX_ROOT, idx_ni->name, idx_ni->name_len,
CASE_SENSITIVE, 0, NULL, 0, actx);
if (unlikely(err)) {
if (err == -ENOENT) {
ntfs_error(sb, "Index root attribute missing in inode "
"0x%lx.", idx_ni->mft_no);
err = -EIO;
}
goto err_out;
}
ir = (INDEX_ROOT*)((u8*)actx->attr +
le16_to_cpu(actx->attr->data.resident.value_offset));
index_end = (u8*)&ir->index + le32_to_cpu(ir->index.index_length);
ie = (INDEX_ENTRY*)((u8*)&ir->index +
le32_to_cpu(ir->index.entries_offset));
for (;; ie = (INDEX_ENTRY*)((u8*)ie + le16_to_cpu(ie->length))) {
if ((u8*)ie < (u8*)actx->mrec || (u8*)ie +
sizeof(INDEX_ENTRY_HEADER) > index_end ||
(u8*)ie + le16_to_cpu(ie->length) > index_end)
goto idx_err_out;
if (ie->flags & INDEX_ENTRY_END)
break;
if ((u32)sizeof(INDEX_ENTRY_HEADER) +
le16_to_cpu(ie->key_length) >
le16_to_cpu(ie->data.vi.data_offset) ||
(u32)le16_to_cpu(ie->data.vi.data_offset) +
le16_to_cpu(ie->data.vi.data_length) >
le16_to_cpu(ie->length))
goto idx_err_out;
if ((key_len == le16_to_cpu(ie->key_length)) && !memcmp(key,
&ie->key, key_len)) {
ir_done:
ictx->is_in_root = true;
ictx->ir = ir;
ictx->actx = actx;
ictx->base_ni = base_ni;
ictx->ia = NULL;
ictx->page = NULL;
done:
ictx->entry = ie;
ictx->data = (u8*)ie +
le16_to_cpu(ie->data.vi.data_offset);
ictx->data_len = le16_to_cpu(ie->data.vi.data_length);
ntfs_debug("Done.");
return err;
}
rc = ntfs_collate(vol, idx_ni->itype.index.collation_rule, key,
key_len, &ie->key, le16_to_cpu(ie->key_length));
if (rc == -1)
break;
if (!rc)
goto ir_done;
}
if (!(ie->flags & INDEX_ENTRY_NODE)) {
ntfs_debug("Entry not found.");
err = -ENOENT;
goto ir_done;
}
if (!NInoIndexAllocPresent(idx_ni)) {
ntfs_error(sb, "No index allocation attribute but index entry "
"requires one. Inode 0x%lx is corrupt or "
"driver bug.", idx_ni->mft_no);
goto err_out;
}
vcn = sle64_to_cpup((sle64*)((u8*)ie + le16_to_cpu(ie->length) - 8));
ia_mapping = VFS_I(idx_ni)->i_mapping;
ntfs_attr_put_search_ctx(actx);
unmap_mft_record(base_ni);
m = NULL;
actx = NULL;
descend_into_child_node:
page = ntfs_map_page(ia_mapping, vcn <<
idx_ni->itype.index.vcn_size_bits >> PAGE_SHIFT);
if (IS_ERR(page)) {
ntfs_error(sb, "Failed to map index page, error %ld.",
-PTR_ERR(page));
err = PTR_ERR(page);
goto err_out;
}
lock_page(page);
kaddr = (u8*)page_address(page);
fast_descend_into_child_node:
ia = (INDEX_ALLOCATION*)(kaddr + ((vcn <<
idx_ni->itype.index.vcn_size_bits) & ~PAGE_MASK));
if ((u8*)ia < kaddr || (u8*)ia > kaddr + PAGE_SIZE) {
ntfs_error(sb, "Out of bounds check failed. Corrupt inode "
"0x%lx or driver bug.", idx_ni->mft_no);
goto unm_err_out;
}
if (unlikely(!ntfs_is_indx_record(ia->magic))) {
ntfs_error(sb, "Index record with vcn 0x%llx is corrupt. "
"Corrupt inode 0x%lx. Run chkdsk.",
(long long)vcn, idx_ni->mft_no);
goto unm_err_out;
}
if (sle64_to_cpu(ia->index_block_vcn) != vcn) {
ntfs_error(sb, "Actual VCN (0x%llx) of index buffer is "
"different from expected VCN (0x%llx). Inode "
"0x%lx is corrupt or driver bug.",
(unsigned long long)
sle64_to_cpu(ia->index_block_vcn),
(unsigned long long)vcn, idx_ni->mft_no);
goto unm_err_out;
}
if (le32_to_cpu(ia->index.allocated_size) + 0x18 !=
idx_ni->itype.index.block_size) {
ntfs_error(sb, "Index buffer (VCN 0x%llx) of inode 0x%lx has "
"a size (%u) differing from the index "
"specified size (%u). Inode is corrupt or "
"driver bug.", (unsigned long long)vcn,
idx_ni->mft_no,
le32_to_cpu(ia->index.allocated_size) + 0x18,
idx_ni->itype.index.block_size);
goto unm_err_out;
}
index_end = (u8*)ia + idx_ni->itype.index.block_size;
if (index_end > kaddr + PAGE_SIZE) {
ntfs_error(sb, "Index buffer (VCN 0x%llx) of inode 0x%lx "
"crosses page boundary. Impossible! Cannot "
"access! This is probably a bug in the "
"driver.", (unsigned long long)vcn,
idx_ni->mft_no);
goto unm_err_out;
}
index_end = (u8*)&ia->index + le32_to_cpu(ia->index.index_length);
if (index_end > (u8*)ia + idx_ni->itype.index.block_size) {
ntfs_error(sb, "Size of index buffer (VCN 0x%llx) of inode "
"0x%lx exceeds maximum size.",
(unsigned long long)vcn, idx_ni->mft_no);
goto unm_err_out;
}
ie = (INDEX_ENTRY*)((u8*)&ia->index +
le32_to_cpu(ia->index.entries_offset));
for (;; ie = (INDEX_ENTRY*)((u8*)ie + le16_to_cpu(ie->length))) {
if ((u8*)ie < (u8*)ia || (u8*)ie +
sizeof(INDEX_ENTRY_HEADER) > index_end ||
(u8*)ie + le16_to_cpu(ie->length) > index_end) {
ntfs_error(sb, "Index entry out of bounds in inode "
"0x%lx.", idx_ni->mft_no);
goto unm_err_out;
}
if (ie->flags & INDEX_ENTRY_END)
break;
if ((u32)sizeof(INDEX_ENTRY_HEADER) +
le16_to_cpu(ie->key_length) >
le16_to_cpu(ie->data.vi.data_offset) ||
(u32)le16_to_cpu(ie->data.vi.data_offset) +
le16_to_cpu(ie->data.vi.data_length) >
le16_to_cpu(ie->length)) {
ntfs_error(sb, "Index entry out of bounds in inode "
"0x%lx.", idx_ni->mft_no);
goto unm_err_out;
}
if ((key_len == le16_to_cpu(ie->key_length)) && !memcmp(key,
&ie->key, key_len)) {
ia_done:
ictx->is_in_root = false;
ictx->actx = NULL;
ictx->base_ni = NULL;
ictx->ia = ia;
ictx->page = page;
goto done;
}
rc = ntfs_collate(vol, idx_ni->itype.index.collation_rule, key,
key_len, &ie->key, le16_to_cpu(ie->key_length));
if (rc == -1)
break;
if (!rc)
goto ia_done;
}
if (!(ie->flags & INDEX_ENTRY_NODE)) {
ntfs_debug("Entry not found.");
err = -ENOENT;
goto ia_done;
}
if ((ia->index.flags & NODE_MASK) == LEAF_NODE) {
ntfs_error(sb, "Index entry with child node found in a leaf "
"node in inode 0x%lx.", idx_ni->mft_no);
goto unm_err_out;
}
old_vcn = vcn;
vcn = sle64_to_cpup((sle64*)((u8*)ie + le16_to_cpu(ie->length) - 8));
if (vcn >= 0) {
if (old_vcn << vol->cluster_size_bits >>
PAGE_SHIFT == vcn <<
vol->cluster_size_bits >>
PAGE_SHIFT)
goto fast_descend_into_child_node;
unlock_page(page);
ntfs_unmap_page(page);
goto descend_into_child_node;
}
ntfs_error(sb, "Negative child node vcn in inode 0x%lx.",
idx_ni->mft_no);
unm_err_out:
unlock_page(page);
ntfs_unmap_page(page);
err_out:
if (!err)
err = -EIO;
if (actx)
ntfs_attr_put_search_ctx(actx);
if (m)
unmap_mft_record(base_ni);
return err;
idx_err_out:
ntfs_error(sb, "Corrupt index. Aborting lookup.");
goto err_out;
}
