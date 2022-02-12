void obdo_refresh_inode(struct inode *dst, struct obdo *src, u32 valid)
{
valid &= src->o_valid;
if (valid & (OBD_MD_FLCTIME | OBD_MD_FLMTIME))
CDEBUG(D_INODE,
"valid %#llx, cur time %lu/%lu, new %llu/%llu\n",
src->o_valid, LTIME_S(dst->i_mtime),
LTIME_S(dst->i_ctime), src->o_mtime, src->o_ctime);
if (valid & OBD_MD_FLATIME && src->o_atime > LTIME_S(dst->i_atime))
LTIME_S(dst->i_atime) = src->o_atime;
if (valid & OBD_MD_FLMTIME && src->o_mtime > LTIME_S(dst->i_mtime))
LTIME_S(dst->i_mtime) = src->o_mtime;
if (valid & OBD_MD_FLCTIME && src->o_ctime > LTIME_S(dst->i_ctime))
LTIME_S(dst->i_ctime) = src->o_ctime;
if (valid & OBD_MD_FLSIZE)
i_size_write(dst, src->o_size);
if (valid & OBD_MD_FLBLKSZ && src->o_blksize > (1 << dst->i_blkbits))
dst->i_blkbits = ffs(src->o_blksize) - 1;
if (dst->i_blkbits < PAGE_SHIFT)
dst->i_blkbits = PAGE_SHIFT;
if (valid & OBD_MD_FLBLOCKS && src->o_blocks > dst->i_blocks)
dst->i_blocks = src->o_blocks;
}
