CsrResult xbv1_parse(card_t *card, fwreadfn_t readfn, void *dlpriv, xbv1_t *fwinfo)
{
ct_t ct;
tag_t tag;
xbv_stack_t stack;
ct.dlpriv = dlpriv;
ct.ioffset = 0;
ct.iread = readfn;
memset(fwinfo, 0, sizeof(xbv1_t));
fwinfo->mode = xbv_unknown;
if (read_tag(card, &ct, &tag) <= 0)
{
unifi_error(NULL, "File is not UniFi firmware\n");
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
DBG_TAG(tag.t_name);
if (!TAG_EQ(tag.t_name, "XBV1"))
{
unifi_error(NULL, "File is not UniFi firmware (%s)\n", tag.t_name);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
stack.ptr = 0;
stack.s[stack.ptr].container = xbv_xbv1;
stack.s[stack.ptr].ioffset_end = XBV_MAX_OFFS;
while (1)
{
s32 n;
n = read_tag(card, &ct, &tag);
if (n < 0)
{
unifi_error(NULL, "No tag\n");
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (n == 0)
{
break;
}
DBG_TAG(tag.t_name);
if (TAG_EQ(tag.t_name, "VERF"))
{
u32 version;
if (xbv_check(fwinfo, &stack, xbv_unknown, xbv_xbv1) ||
(tag.t_len != 2) ||
read_uint(card, &ct, &version, 2))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (version != 0)
{
unifi_error(NULL, "Unsupported firmware file version: %d.%d\n",
version >> 8, version & 0xFF);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
}
else if (TAG_EQ(tag.t_name, "LIST"))
{
char name[4];
u32 list_end;
list_end = ct.ioffset + tag.t_len;
if (read_bytes(card, &ct, name, 4))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
DBG_TAG(name);
if (TAG_EQ(name, "FW "))
{
if (xbv_push(fwinfo, &stack, xbv_firmware, xbv_xbv1, xbv_fw, list_end))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
}
else if (TAG_EQ(name, "VERS"))
{
if (xbv_push(fwinfo, &stack, xbv_firmware, xbv_fw, xbv_vers, list_end) ||
(fwinfo->vers.num_vand != 0))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
}
else if (TAG_EQ(name, "VAND"))
{
struct VAND *vand;
if (xbv_push(fwinfo, &stack, xbv_firmware, xbv_vers, xbv_vand, list_end) ||
(fwinfo->vers.num_vand >= MAX_VAND))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
vand = fwinfo->vand + fwinfo->vers.num_vand++;
vand->first = fwinfo->num_vmeq;
vand->count = 0;
}
else if (TAG_EQ(name, "PTCH"))
{
if (xbv_push(fwinfo, &stack, xbv_patch, xbv_xbv1, xbv_ptch, list_end))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
}
else
{
ct.ioffset += tag.t_len - 4;
}
}
else if (TAG_EQ(tag.t_name, "SLTP"))
{
u32 addr;
if (xbv_check(fwinfo, &stack, xbv_firmware, xbv_fw) ||
(tag.t_len != 4) ||
(fwinfo->slut_addr != 0) ||
read_uint(card, &ct, &addr, 4))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
fwinfo->slut_addr = addr;
}
else if (TAG_EQ(tag.t_name, "FWDL"))
{
u32 addr;
struct FWDL *fwdl;
if (xbv_check(fwinfo, &stack, xbv_firmware, xbv_fw) ||
(fwinfo->num_fwdl >= MAX_FWDL) ||
(read_uint(card, &ct, &addr, 4)))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
fwdl = fwinfo->fwdl + fwinfo->num_fwdl++;
fwdl->dl_size = tag.t_len - 4;
fwdl->dl_addr = addr;
fwdl->dl_offset = ct.ioffset;
ct.ioffset += tag.t_len - 4;
}
else if (TAG_EQ(tag.t_name, "FWOV"))
{
if (xbv_check(fwinfo, &stack, xbv_firmware, xbv_fw) ||
(fwinfo->fwov.dl_size != 0) ||
(fwinfo->fwov.dl_offset != 0))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
fwinfo->fwov.dl_size = tag.t_len;
fwinfo->fwov.dl_offset = ct.ioffset;
ct.ioffset += tag.t_len;
}
else if (TAG_EQ(tag.t_name, "VMEQ"))
{
u32 temp[3];
struct VAND *vand;
struct VMEQ *vmeq;
if (xbv_check(fwinfo, &stack, xbv_firmware, xbv_vand) ||
(fwinfo->num_vmeq >= MAX_VMEQ) ||
(fwinfo->vers.num_vand == 0) ||
(tag.t_len != 8) ||
read_uint(card, &ct, &temp[0], 4) ||
read_uint(card, &ct, &temp[1], 2) ||
read_uint(card, &ct, &temp[2], 2))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
vand = fwinfo->vand + (fwinfo->vers.num_vand - 1);
vmeq = fwinfo->vmeq + fwinfo->num_vmeq++;
vand->count++;
vmeq->addr = temp[0];
vmeq->mask = (u16)temp[1];
vmeq->value = (u16)temp[2];
}
else if (TAG_EQ(tag.t_name, "FWID"))
{
u32 build_id;
if (xbv_check(fwinfo, &stack, xbv_patch, xbv_ptch) ||
(tag.t_len != 4) ||
(fwinfo->build_id != 0) ||
read_uint(card, &ct, &build_id, 4))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
fwinfo->build_id = build_id;
}
else if (TAG_EQ(tag.t_name, "PTDL"))
{
struct PTDL *ptdl;
if (xbv_check(fwinfo, &stack, xbv_patch, xbv_ptch) ||
(fwinfo->num_ptdl >= MAX_PTDL))
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
ptdl = fwinfo->ptdl + fwinfo->num_ptdl++;
ptdl->dl_size = tag.t_len;
ptdl->dl_offset = ct.ioffset;
ct.ioffset += tag.t_len;
}
else
{
ct.ioffset += tag.t_len;
}
while (ct.ioffset >= stack.s[stack.ptr].ioffset_end)
{
if (ct.ioffset > stack.s[stack.ptr].ioffset_end)
{
unifi_error(NULL,
"XBV file has overrun stack'd segment %d (%d > %d)\n",
stack.ptr, ct.ioffset, stack.s[stack.ptr].ioffset_end);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (stack.ptr <= 0)
{
unifi_error(NULL, "XBV file has underrun stack pointer\n");
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
stack.ptr--;
}
}
if (stack.ptr != 0)
{
unifi_error(NULL, "Last list of XBV is not complete.\n");
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
return CSR_RESULT_SUCCESS;
}
static s32 xbv_check(xbv1_t *fwinfo, const xbv_stack_t *stack,
xbv_mode new_mode, xbv_container old_cont)
{
if (new_mode != xbv_unknown)
{
if (fwinfo->mode == xbv_unknown)
{
fwinfo->mode = new_mode;
}
else if (fwinfo->mode != new_mode)
{
return -1;
}
}
if (stack->s[stack->ptr].container != old_cont)
{
return -1;
}
return 0;
}
static s32 xbv_push(xbv1_t *fwinfo, xbv_stack_t *stack,
xbv_mode new_mode, xbv_container old_cont,
xbv_container new_cont, u32 new_ioff)
{
if (xbv_check(fwinfo, stack, new_mode, old_cont))
{
return -1;
}
if (stack->ptr >= (XBV_STACK_SIZE - 1))
{
return -1;
}
stack->ptr++;
stack->s[stack->ptr].container = new_cont;
stack->s[stack->ptr].ioffset_end = new_ioff;
return 0;
}
static u32 xbv2uint(u8 *ptr, s32 len)
{
u32 u = 0;
s16 i;
for (i = 0; i < len; i++)
{
u32 b;
b = ptr[i];
u += b << (i * 8);
}
return u;
}
static s32 read_tag(card_t *card, ct_t *ct, tag_t *tag)
{
u8 buf[8];
s32 n;
n = (*ct->iread)(card->ospriv, ct->dlpriv, ct->ioffset, buf, 8);
if (n <= 0)
{
return n;
}
if (n != 8)
{
return -1;
}
memcpy(tag->t_name, buf, 4);
tag->t_len = xbv2uint(buf + 4, 4);
ct->ioffset += 8;
return 8;
}
static s32 read_bytes(card_t *card, ct_t *ct, void *buf, u32 len)
{
if ((*ct->iread)(card->ospriv, ct->dlpriv, ct->ioffset, buf, len) != (s32)len)
{
return -1;
}
ct->ioffset += len;
return 0;
}
static s32 read_uint(card_t *card, ct_t *ct, u32 *u, u32 len)
{
u8 buf[4];
if (len > 4)
{
return -1;
}
if (read_bytes(card, ct, buf, len))
{
return -1;
}
*u = xbv2uint(buf, len);
return 0;
}
static u32 write_uint16(void *buf, const u32 offset, const u16 val)
{
u8 *dst = (u8 *)buf + offset;
*dst++ = (u8)(val & 0xff);
*dst = (u8)(val >> 8);
return sizeof(u16);
}
static u32 write_uint32(void *buf, const u32 offset, const u32 val)
{
(void)write_uint16(buf, offset + 0, (u16)(val & 0xffff));
(void)write_uint16(buf, offset + 2, (u16)(val >> 16));
return sizeof(u32);
}
static u32 write_bytes(void *buf, const u32 offset, const u8 *data, const u32 len)
{
u32 i;
u8 *dst = (u8 *)buf + offset;
for (i = 0; i < len; i++)
{
*dst++ = *((u8 *)data + i);
}
return len;
}
static u32 write_tag(void *buf, const u32 offset, const char *tag_str)
{
u8 *dst = (u8 *)buf + offset;
memcpy(dst, tag_str, 4);
return 4;
}
static u32 write_chunk(void *buf, const u32 offset, const char *tag_str, const u32 payload_len)
{
u32 written = 0;
written += write_tag(buf, offset, tag_str);
written += write_uint32(buf, written + offset, (u32)payload_len);
return written;
}
static u16 calc_checksum(void *buf, const u32 offset, const u32 bytes_len)
{
u32 i;
u8 *src = (u8 *)buf + offset;
u16 sum = 0;
u16 val;
for (i = 0; i < bytes_len / 2; i++)
{
val = (u16) * src++;
val += (u16)(*src++) << 8;
sum += val;
}
return (STREAM_CHECKSUM - sum);
}
static u32 calc_patch_size(const xbv1_t *fwinfo)
{
s16 i;
u32 size = 0;
if (fwinfo->mode != xbv_firmware)
{
return 0;
}
for (i = 0; i < fwinfo->num_fwdl; i++)
{
size += fwinfo->fwdl[i].dl_size;
}
size += PTDL_RESET_DATA_SIZE;
size += ((fwinfo->num_fwdl / PTDL_MAX_SIZE) + 2) * PTDL_HDR_SIZE;
size += 1024;
return size;
}
static u32 write_xbv_header(void *buf, const u32 offset, const u32 file_payload_length)
{
u32 written = 0;
written += write_chunk(buf, offset + written, (char *)"XBV1", file_payload_length + 6);
written += write_chunk(buf, offset + written, (char *)"VERF", 2);
written += write_uint16(buf, offset + written, 0);
return written;
}
static u32 write_ptch_header(void *buf, const u32 offset, const u32 fw_id)
{
u32 written = 0;
written += write_chunk(buf, offset + written, (char *)"LIST", 0);
written += write_tag(buf, offset + written, (char *)"PTCH");
written += write_chunk(buf, offset + written, (char *)"FWID", 4);
written += write_uint32(buf, offset + written, fw_id);
return written;
}
static u32 write_patchcmd(void *buf, const u32 offset, const u32 dst_genaddr, const u16 len)
{
u32 written = 0;
u32 region = (dst_genaddr >> 28);
u16 cmd_and_len = UF_MEMPUT_MAC;
if (region == UF_REGION_PHY)
{
cmd_and_len = UF_MEMPUT_PHY;
}
else if (region != UF_REGION_MAC)
{
return 0;
}
cmd_and_len |= len;
written += write_uint16(buf, offset + written, cmd_and_len);
written += write_uint16(buf, offset + written, (u16)(dst_genaddr >> 16));
written += write_uint16(buf, offset + written, (u16)(dst_genaddr & 0xffff));
return written;
}
static u32 write_fwdl_to_ptdl(void *buf, const u32 offset, fwreadfn_t readfn,
const struct FWDL *fwdl, const void *dlpriv,
const u32 fw_id, void *fw_buf)
{
u32 written = 0;
s16 chunks = 0;
u32 left = fwdl->dl_size;
u32 dl_addr = fwdl->dl_addr;
u32 dl_offs = fwdl->dl_offset;
u16 csum;
u32 csum_start_offs;
u32 sec_data_len;
u32 sec_len;
while (left)
{
sec_data_len = CSRMIN(left, PTDL_MAX_SIZE - PTDL_HDR_SIZE);
sec_len = sec_data_len + PTDL_HDR_SIZE;
written += write_chunk(buf, offset + written, (char *)"PTDL", sec_len);
csum_start_offs = offset + written;
written += write_uint16(buf, offset + written, (u16)(fw_id >> 16));
written += write_uint16(buf, offset + written, (u16)(fw_id & 0xffff));
written += write_uint16(buf, offset + written, (u16)(sec_len / 2));
written += write_patchcmd(buf, offset + written, dl_addr, (u16)(sec_data_len / 2));
if (readfn(NULL, (void *)dlpriv, dl_offs, fw_buf, sec_data_len) < 0)
{
return 0;
}
written += write_bytes(buf,
offset + written,
fw_buf,
sec_data_len);
csum = calc_checksum(buf, csum_start_offs, written - (csum_start_offs - offset));
written += write_uint16(buf, offset + written, csum);
left -= sec_data_len;
dl_addr += sec_data_len;
dl_offs += sec_data_len;
chunks++;
}
return written;
}
static u32 write_reset_ptdl(void *buf, const u32 offset, const xbv1_t *fwinfo, u32 fw_id)
{
u32 written = 0;
u16 csum;
u32 csum_start_offs;
u32 sec_len;
sec_len = SEC_CMD_LEN + PTDL_VEC_HDR_SIZE;
written += write_chunk(buf, offset + written, (char *)"PTDL", sec_len);
csum_start_offs = offset + written;
written += write_uint16(buf, offset + written, (u16)(fw_id >> 16));
written += write_uint16(buf, offset + written, (u16)(fw_id & 0xffff));
written += write_uint16(buf, offset + written, (u16)(sec_len / 2));
written += write_uint16(buf, offset + written, UF_MAC_START_CMD);
written += write_uint16(buf, offset + written, (UF_MAC_START_VEC >> 16));
written += write_uint16(buf, offset + written, (UF_MAC_START_VEC & 0xffff));
written += write_uint16(buf, offset + written, UF_PHY_START_CMD);
written += write_uint16(buf, offset + written, (UF_PHY_START_VEC >> 16));
written += write_uint16(buf, offset + written, (UF_PHY_START_VEC & 0xffff));
csum = calc_checksum(buf, csum_start_offs, written - (csum_start_offs - offset));
written += write_uint16(buf, offset + written, csum);
return written;
}
s32 xbv1_read_slut(card_t *card, fwreadfn_t readfn, void *dlpriv, xbv1_t *fwinfo,
symbol_t *slut, u32 slut_len)
{
s16 i;
s32 offset;
u32 magic;
u32 count = 0;
ct_t ct;
if (fwinfo->mode != xbv_firmware)
{
return -1;
}
offset = -1;
for (i = 0; i < fwinfo->num_fwdl; i++)
{
if ((fwinfo->slut_addr >= fwinfo->fwdl[i].dl_addr) &&
(fwinfo->slut_addr < (fwinfo->fwdl[i].dl_addr + fwinfo->fwdl[i].dl_size)))
{
offset = fwinfo->fwdl[i].dl_offset +
(fwinfo->slut_addr - fwinfo->fwdl[i].dl_addr);
}
}
if (offset < 0)
{
return -1;
}
ct.dlpriv = dlpriv;
ct.ioffset = offset;
ct.iread = readfn;
if (read_uint(card, &ct, &magic, 2))
{
return -1;
}
if (magic != SLUT_FINGERPRINT)
{
return -1;
}
while (count < slut_len)
{
u32 id, obj;
if (read_uint(card, &ct, &id, 2))
{
return -1;
}
if (id == CSR_SLT_END)
{
break;
}
if (read_uint(card, &ct, &obj, 4))
{
return -1;
}
slut[count].id = (u16)id;
slut[count].obj = obj;
count++;
}
return count;
}
void* xbv_to_patch(card_t *card, fwreadfn_t readfn,
const void *fw_buf, const xbv1_t *fwinfo, u32 *size)
{
void *patch_buf = NULL;
u32 patch_buf_size;
u32 payload_offs = 0;
s16 i;
u32 patch_offs = 0;
u32 list_len_offs = 0;
u32 ptdl_start_offs = 0;
u32 fw_id;
void *rdbuf;
if (!fw_buf || !fwinfo || !card)
{
return NULL;
}
if (fwinfo->mode != xbv_firmware)
{
unifi_error(NULL, "Not a firmware file\n");
return NULL;
}
rdbuf = kmalloc(PTDL_MAX_SIZE, GFP_KERNEL);
if (!rdbuf)
{
unifi_error(card, "Couldn't alloc conversion buffer\n");
return NULL;
}
fw_id = card->build_id;
patch_buf_size = calc_patch_size(fwinfo);
patch_buf = kmalloc(patch_buf_size, GFP_KERNEL);
if (!patch_buf)
{
kfree(rdbuf);
unifi_error(NULL, "Can't malloc buffer for patch conversion\n");
return NULL;
}
memset(patch_buf, 0xdd, patch_buf_size);
patch_offs += write_xbv_header(patch_buf, patch_offs, 0);
payload_offs = patch_offs;
list_len_offs = patch_offs + 4;
patch_offs += write_ptch_header(patch_buf, patch_offs, fw_id);
ptdl_start_offs = patch_offs;
for (i = 0; i < fwinfo->num_fwdl; i++)
{
patch_offs += write_fwdl_to_ptdl(patch_buf,
patch_offs,
readfn,
&fwinfo->fwdl[i],
fw_buf,
fw_id,
rdbuf);
}
patch_offs += write_reset_ptdl(patch_buf, patch_offs, fwinfo, fw_id);
(void)write_uint32(patch_buf, list_len_offs,
(patch_offs - ptdl_start_offs) + PTCH_LIST_SIZE);
(void)write_xbv_header(patch_buf, 0, (patch_offs - payload_offs));
unifi_trace(card->ospriv, UDBG1, "XBV:PTCH size %u, fw_id %u\n",
patch_offs, fw_id);
if (size)
{
*size = patch_offs;
}
kfree(rdbuf);
return patch_buf;
}
