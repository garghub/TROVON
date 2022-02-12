bool ntfs_are_names_equal(const ntfschar *s1, size_t s1_len,
const ntfschar *s2, size_t s2_len, const IGNORE_CASE_BOOL ic,
const ntfschar *upcase, const u32 upcase_size)
{
if (s1_len != s2_len)
return false;
if (ic == CASE_SENSITIVE)
return !ntfs_ucsncmp(s1, s2, s1_len);
return !ntfs_ucsncasecmp(s1, s2, s1_len, upcase, upcase_size);
}
int ntfs_collate_names(const ntfschar *name1, const u32 name1_len,
const ntfschar *name2, const u32 name2_len,
const int err_val, const IGNORE_CASE_BOOL ic,
const ntfschar *upcase, const u32 upcase_len)
{
u32 cnt, min_len;
u16 c1, c2;
min_len = name1_len;
if (name1_len > name2_len)
min_len = name2_len;
for (cnt = 0; cnt < min_len; ++cnt) {
c1 = le16_to_cpu(*name1++);
c2 = le16_to_cpu(*name2++);
if (ic) {
if (c1 < upcase_len)
c1 = le16_to_cpu(upcase[c1]);
if (c2 < upcase_len)
c2 = le16_to_cpu(upcase[c2]);
}
if (c1 < 64 && legal_ansi_char_array[c1] & 8)
return err_val;
if (c1 < c2)
return -1;
if (c1 > c2)
return 1;
}
if (name1_len < name2_len)
return -1;
if (name1_len == name2_len)
return 0;
c1 = le16_to_cpu(*name1);
if (c1 < 64 && legal_ansi_char_array[c1] & 8)
return err_val;
return 1;
}
int ntfs_ucsncmp(const ntfschar *s1, const ntfschar *s2, size_t n)
{
u16 c1, c2;
size_t i;
for (i = 0; i < n; ++i) {
c1 = le16_to_cpu(s1[i]);
c2 = le16_to_cpu(s2[i]);
if (c1 < c2)
return -1;
if (c1 > c2)
return 1;
if (!c1)
break;
}
return 0;
}
int ntfs_ucsncasecmp(const ntfschar *s1, const ntfschar *s2, size_t n,
const ntfschar *upcase, const u32 upcase_size)
{
size_t i;
u16 c1, c2;
for (i = 0; i < n; ++i) {
if ((c1 = le16_to_cpu(s1[i])) < upcase_size)
c1 = le16_to_cpu(upcase[c1]);
if ((c2 = le16_to_cpu(s2[i])) < upcase_size)
c2 = le16_to_cpu(upcase[c2]);
if (c1 < c2)
return -1;
if (c1 > c2)
return 1;
if (!c1)
break;
}
return 0;
}
void ntfs_upcase_name(ntfschar *name, u32 name_len, const ntfschar *upcase,
const u32 upcase_len)
{
u32 i;
u16 u;
for (i = 0; i < name_len; i++)
if ((u = le16_to_cpu(name[i])) < upcase_len)
name[i] = upcase[u];
}
void ntfs_file_upcase_value(FILE_NAME_ATTR *file_name_attr,
const ntfschar *upcase, const u32 upcase_len)
{
ntfs_upcase_name((ntfschar*)&file_name_attr->file_name,
file_name_attr->file_name_length, upcase, upcase_len);
}
int ntfs_file_compare_values(FILE_NAME_ATTR *file_name_attr1,
FILE_NAME_ATTR *file_name_attr2,
const int err_val, const IGNORE_CASE_BOOL ic,
const ntfschar *upcase, const u32 upcase_len)
{
return ntfs_collate_names((ntfschar*)&file_name_attr1->file_name,
file_name_attr1->file_name_length,
(ntfschar*)&file_name_attr2->file_name,
file_name_attr2->file_name_length,
err_val, ic, upcase, upcase_len);
}
int ntfs_nlstoucs(const ntfs_volume *vol, const char *ins,
const int ins_len, ntfschar **outs)
{
struct nls_table *nls = vol->nls_map;
ntfschar *ucs;
wchar_t wc;
int i, o, wc_len;
if (likely(ins)) {
ucs = kmem_cache_alloc(ntfs_name_cache, GFP_NOFS);
if (likely(ucs)) {
for (i = o = 0; i < ins_len; i += wc_len) {
wc_len = nls->char2uni(ins + i, ins_len - i,
&wc);
if (likely(wc_len >= 0 &&
o < NTFS_MAX_NAME_LEN)) {
if (likely(wc)) {
ucs[o++] = cpu_to_le16(wc);
continue;
}
break;
}
goto name_err;
}
ucs[o] = 0;
*outs = ucs;
return o;
}
ntfs_error(vol->sb, "Failed to allocate buffer for converted "
"name from ntfs_name_cache.");
return -ENOMEM;
}
ntfs_error(vol->sb, "Received NULL pointer.");
return -EINVAL;
name_err:
kmem_cache_free(ntfs_name_cache, ucs);
if (wc_len < 0) {
ntfs_error(vol->sb, "Name using character set %s contains "
"characters that cannot be converted to "
"Unicode.", nls->charset);
i = -EILSEQ;
} else {
ntfs_error(vol->sb, "Name is too long (maximum length for a "
"name on NTFS is %d Unicode characters.",
NTFS_MAX_NAME_LEN);
i = -ENAMETOOLONG;
}
return i;
}
int ntfs_ucstonls(const ntfs_volume *vol, const ntfschar *ins,
const int ins_len, unsigned char **outs, int outs_len)
{
struct nls_table *nls = vol->nls_map;
unsigned char *ns;
int i, o, ns_len, wc;
if (ins) {
ns = *outs;
ns_len = outs_len;
if (ns && !ns_len) {
wc = -ENAMETOOLONG;
goto conversion_err;
}
if (!ns) {
ns_len = ins_len * NLS_MAX_CHARSET_SIZE;
ns = kmalloc(ns_len + 1, GFP_NOFS);
if (!ns)
goto mem_err_out;
}
for (i = o = 0; i < ins_len; i++) {
retry: wc = nls->uni2char(le16_to_cpu(ins[i]), ns + o,
ns_len - o);
if (wc > 0) {
o += wc;
continue;
} else if (!wc)
break;
else if (wc == -ENAMETOOLONG && ns != *outs) {
unsigned char *tc;
tc = kmalloc((ns_len + 64) &
~63, GFP_NOFS);
if (tc) {
memcpy(tc, ns, ns_len);
ns_len = ((ns_len + 64) & ~63) - 1;
kfree(ns);
ns = tc;
goto retry;
}
}
goto conversion_err;
}
ns[o] = 0;
*outs = ns;
return o;
}
ntfs_error(vol->sb, "Received NULL pointer.");
return -EINVAL;
conversion_err:
ntfs_error(vol->sb, "Unicode name contains characters that cannot be "
"converted to character set %s. You might want to "
"try to use the mount option nls=utf8.", nls->charset);
if (ns != *outs)
kfree(ns);
if (wc != -ENAMETOOLONG)
wc = -EILSEQ;
return wc;
mem_err_out:
ntfs_error(vol->sb, "Failed to allocate name!");
return -ENOMEM;
}
