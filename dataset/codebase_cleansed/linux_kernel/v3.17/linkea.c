int linkea_data_new(struct linkea_data *ldata, struct lu_buf *buf)
{
ldata->ld_buf = lu_buf_check_and_alloc(buf, PAGE_CACHE_SIZE);
if (ldata->ld_buf->lb_buf == NULL)
return -ENOMEM;
ldata->ld_leh = ldata->ld_buf->lb_buf;
ldata->ld_leh->leh_magic = LINK_EA_MAGIC;
ldata->ld_leh->leh_len = sizeof(struct link_ea_header);
ldata->ld_leh->leh_reccount = 0;
return 0;
}
int linkea_init(struct linkea_data *ldata)
{
struct link_ea_header *leh;
LASSERT(ldata->ld_buf != NULL);
leh = ldata->ld_buf->lb_buf;
if (leh->leh_magic == __swab32(LINK_EA_MAGIC)) {
leh->leh_magic = LINK_EA_MAGIC;
leh->leh_reccount = __swab32(leh->leh_reccount);
leh->leh_len = __swab64(leh->leh_len);
}
if (leh->leh_magic != LINK_EA_MAGIC)
return -EINVAL;
if (leh->leh_reccount == 0)
return -ENODATA;
ldata->ld_leh = leh;
return 0;
}
static int linkea_entry_pack(struct link_ea_entry *lee,
const struct lu_name *lname,
const struct lu_fid *pfid)
{
struct lu_fid tmpfid;
int reclen;
fid_cpu_to_be(&tmpfid, pfid);
if (OBD_FAIL_CHECK(OBD_FAIL_LFSCK_LINKEA_CRASH))
tmpfid.f_ver = ~0;
memcpy(&lee->lee_parent_fid, &tmpfid, sizeof(tmpfid));
memcpy(lee->lee_name, lname->ln_name, lname->ln_namelen);
reclen = sizeof(struct link_ea_entry) + lname->ln_namelen;
lee->lee_reclen[0] = (reclen >> 8) & 0xff;
lee->lee_reclen[1] = reclen & 0xff;
return reclen;
}
void linkea_entry_unpack(const struct link_ea_entry *lee, int *reclen,
struct lu_name *lname, struct lu_fid *pfid)
{
*reclen = (lee->lee_reclen[0] << 8) | lee->lee_reclen[1];
memcpy(pfid, &lee->lee_parent_fid, sizeof(*pfid));
fid_be_to_cpu(pfid, pfid);
lname->ln_name = lee->lee_name;
lname->ln_namelen = *reclen - sizeof(struct link_ea_entry);
}
int linkea_add_buf(struct linkea_data *ldata, const struct lu_name *lname,
const struct lu_fid *pfid)
{
LASSERT(ldata->ld_leh != NULL);
if (lname == NULL || pfid == NULL)
return -EINVAL;
ldata->ld_reclen = lname->ln_namelen + sizeof(struct link_ea_entry);
if (ldata->ld_leh->leh_len + ldata->ld_reclen >
ldata->ld_buf->lb_len) {
if (lu_buf_check_and_grow(ldata->ld_buf,
ldata->ld_leh->leh_len +
ldata->ld_reclen) < 0)
return -ENOMEM;
}
ldata->ld_leh = ldata->ld_buf->lb_buf;
ldata->ld_lee = ldata->ld_buf->lb_buf + ldata->ld_leh->leh_len;
ldata->ld_reclen = linkea_entry_pack(ldata->ld_lee, lname, pfid);
ldata->ld_leh->leh_len += ldata->ld_reclen;
ldata->ld_leh->leh_reccount++;
CDEBUG(D_INODE, "New link_ea name '%.*s' is added\n",
lname->ln_namelen, lname->ln_name);
return 0;
}
void linkea_del_buf(struct linkea_data *ldata, const struct lu_name *lname)
{
LASSERT(ldata->ld_leh != NULL && ldata->ld_lee != NULL);
ldata->ld_leh->leh_reccount--;
ldata->ld_leh->leh_len -= ldata->ld_reclen;
memmove(ldata->ld_lee, (char *)ldata->ld_lee + ldata->ld_reclen,
(char *)ldata->ld_leh + ldata->ld_leh->leh_len -
(char *)ldata->ld_lee);
CDEBUG(D_INODE, "Old link_ea name '%.*s' is removed\n",
lname->ln_namelen, lname->ln_name);
}
int linkea_links_find(struct linkea_data *ldata, const struct lu_name *lname,
const struct lu_fid *pfid)
{
struct lu_name tmpname;
struct lu_fid tmpfid;
int count;
LASSERT(ldata->ld_leh != NULL);
ldata->ld_lee = (struct link_ea_entry *)(ldata->ld_leh + 1);
for (count = 0; count < ldata->ld_leh->leh_reccount; count++) {
linkea_entry_unpack(ldata->ld_lee, &ldata->ld_reclen,
&tmpname, &tmpfid);
if (tmpname.ln_namelen == lname->ln_namelen &&
lu_fid_eq(&tmpfid, pfid) &&
(strncmp(tmpname.ln_name, lname->ln_name,
tmpname.ln_namelen) == 0))
break;
ldata->ld_lee = (struct link_ea_entry *)((char *)ldata->ld_lee +
ldata->ld_reclen);
}
if (count == ldata->ld_leh->leh_reccount) {
CDEBUG(D_INODE, "Old link_ea name '%.*s' not found\n",
lname->ln_namelen, lname->ln_name);
ldata->ld_lee = NULL;
return -ENOENT;
}
return 0;
}
