int fdt_check_header(const void *fdt)
{
if (fdt_magic(fdt) == FDT_MAGIC) {
if (fdt_version(fdt) < FDT_FIRST_SUPPORTED_VERSION)
return -FDT_ERR_BADVERSION;
if (fdt_last_comp_version(fdt) > FDT_LAST_SUPPORTED_VERSION)
return -FDT_ERR_BADVERSION;
} else if (fdt_magic(fdt) == FDT_SW_MAGIC) {
if (fdt_size_dt_struct(fdt) == 0)
return -FDT_ERR_BADSTATE;
} else {
return -FDT_ERR_BADMAGIC;
}
return 0;
}
const void *fdt_offset_ptr(const void *fdt, int offset, int len)
{
const char *p;
if (fdt_version(fdt) >= 0x11)
if (((offset + len) < offset)
|| ((offset + len) > fdt_size_dt_struct(fdt)))
return NULL;
p = _fdt_offset_ptr(fdt, offset);
if (p + len < p)
return NULL;
return p;
}
uint32_t fdt_next_tag(const void *fdt, int offset, int *nextoffset)
{
const uint32_t *tagp, *lenp;
uint32_t tag;
const char *p;
if (offset % FDT_TAGSIZE)
return -1;
tagp = fdt_offset_ptr(fdt, offset, FDT_TAGSIZE);
if (! tagp)
return FDT_END;
tag = fdt32_to_cpu(*tagp);
offset += FDT_TAGSIZE;
switch (tag) {
case FDT_BEGIN_NODE:
do {
p = fdt_offset_ptr(fdt, offset++, 1);
} while (p && (*p != '\0'));
if (! p)
return FDT_END;
break;
case FDT_PROP:
lenp = fdt_offset_ptr(fdt, offset, sizeof(*lenp));
if (! lenp)
return FDT_END;
offset += 2*FDT_TAGSIZE + fdt32_to_cpu(*lenp);
break;
}
if (nextoffset)
*nextoffset = FDT_TAGALIGN(offset);
return tag;
}
int _fdt_check_node_offset(const void *fdt, int offset)
{
if ((offset < 0) || (offset % FDT_TAGSIZE)
|| (fdt_next_tag(fdt, offset, &offset) != FDT_BEGIN_NODE))
return -FDT_ERR_BADOFFSET;
return offset;
}
int fdt_next_node(const void *fdt, int offset, int *depth)
{
int nextoffset = 0;
uint32_t tag;
if (offset >= 0)
if ((nextoffset = _fdt_check_node_offset(fdt, offset)) < 0)
return nextoffset;
do {
offset = nextoffset;
tag = fdt_next_tag(fdt, offset, &nextoffset);
switch (tag) {
case FDT_PROP:
case FDT_NOP:
break;
case FDT_BEGIN_NODE:
if (depth)
(*depth)++;
break;
case FDT_END_NODE:
if (depth)
(*depth)--;
break;
case FDT_END:
return -FDT_ERR_NOTFOUND;
default:
return -FDT_ERR_BADSTRUCTURE;
}
} while (tag != FDT_BEGIN_NODE);
return offset;
}
const char *_fdt_find_string(const char *strtab, int tabsize, const char *s)
{
int len = strlen(s) + 1;
const char *last = strtab + tabsize - len;
const char *p;
for (p = strtab; p <= last; p++)
if (memcmp(p, s, len) == 0)
return p;
return NULL;
}
int fdt_move(const void *fdt, void *buf, int bufsize)
{
FDT_CHECK_HEADER(fdt);
if (fdt_totalsize(fdt) > bufsize)
return -FDT_ERR_NOSPACE;
memmove(buf, fdt, fdt_totalsize(fdt));
return 0;
}
