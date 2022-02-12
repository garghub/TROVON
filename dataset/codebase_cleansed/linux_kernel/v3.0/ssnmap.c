static inline size_t sctp_ssnmap_size(__u16 in, __u16 out)
{
return sizeof(struct sctp_ssnmap) + (in + out) * sizeof(__u16);
}
struct sctp_ssnmap *sctp_ssnmap_new(__u16 in, __u16 out,
gfp_t gfp)
{
struct sctp_ssnmap *retval;
int size;
size = sctp_ssnmap_size(in, out);
if (size <= MAX_KMALLOC_SIZE)
retval = kmalloc(size, gfp);
else
retval = (struct sctp_ssnmap *)
__get_free_pages(gfp, get_order(size));
if (!retval)
goto fail;
if (!sctp_ssnmap_init(retval, in, out))
goto fail_map;
retval->malloced = 1;
SCTP_DBG_OBJCNT_INC(ssnmap);
return retval;
fail_map:
if (size <= MAX_KMALLOC_SIZE)
kfree(retval);
else
free_pages((unsigned long)retval, get_order(size));
fail:
return NULL;
}
static struct sctp_ssnmap *sctp_ssnmap_init(struct sctp_ssnmap *map, __u16 in,
__u16 out)
{
memset(map, 0x00, sctp_ssnmap_size(in, out));
map->in.ssn = (__u16 *)&map[1];
map->in.len = in;
map->out.ssn = &map->in.ssn[in];
map->out.len = out;
return map;
}
void sctp_ssnmap_clear(struct sctp_ssnmap *map)
{
size_t size;
size = (map->in.len + map->out.len) * sizeof(__u16);
memset(map->in.ssn, 0x00, size);
}
void sctp_ssnmap_free(struct sctp_ssnmap *map)
{
if (map && map->malloced) {
int size;
size = sctp_ssnmap_size(map->in.len, map->out.len);
if (size <= MAX_KMALLOC_SIZE)
kfree(map);
else
free_pages((unsigned long)map, get_order(size));
SCTP_DBG_OBJCNT_DEC(ssnmap);
}
}
