int ceph_cls_lock(struct ceph_osd_client *osdc,
struct ceph_object_id *oid,
struct ceph_object_locator *oloc,
char *lock_name, u8 type, char *cookie,
char *tag, char *desc, u8 flags)
{
int lock_op_buf_size;
int name_len = strlen(lock_name);
int cookie_len = strlen(cookie);
int tag_len = strlen(tag);
int desc_len = strlen(desc);
void *p, *end;
struct page *lock_op_page;
struct timespec mtime;
int ret;
lock_op_buf_size = name_len + sizeof(__le32) +
cookie_len + sizeof(__le32) +
tag_len + sizeof(__le32) +
desc_len + sizeof(__le32) +
sizeof(struct ceph_timespec) +
sizeof(u8) + sizeof(u8) +
CEPH_ENCODING_START_BLK_LEN;
if (lock_op_buf_size > PAGE_SIZE)
return -E2BIG;
lock_op_page = alloc_page(GFP_NOIO);
if (!lock_op_page)
return -ENOMEM;
p = page_address(lock_op_page);
end = p + lock_op_buf_size;
ceph_start_encoding(&p, 1, 1,
lock_op_buf_size - CEPH_ENCODING_START_BLK_LEN);
ceph_encode_string(&p, end, lock_name, name_len);
ceph_encode_8(&p, type);
ceph_encode_string(&p, end, cookie, cookie_len);
ceph_encode_string(&p, end, tag, tag_len);
ceph_encode_string(&p, end, desc, desc_len);
memset(&mtime, 0, sizeof(mtime));
ceph_encode_timespec(p, &mtime);
p += sizeof(struct ceph_timespec);
ceph_encode_8(&p, flags);
dout("%s lock_name %s type %d cookie %s tag %s desc %s flags 0x%x\n",
__func__, lock_name, type, cookie, tag, desc, flags);
ret = ceph_osdc_call(osdc, oid, oloc, "lock", "lock",
CEPH_OSD_FLAG_WRITE | CEPH_OSD_FLAG_ONDISK,
lock_op_page, lock_op_buf_size, NULL, NULL);
dout("%s: status %d\n", __func__, ret);
__free_page(lock_op_page);
return ret;
}
int ceph_cls_unlock(struct ceph_osd_client *osdc,
struct ceph_object_id *oid,
struct ceph_object_locator *oloc,
char *lock_name, char *cookie)
{
int unlock_op_buf_size;
int name_len = strlen(lock_name);
int cookie_len = strlen(cookie);
void *p, *end;
struct page *unlock_op_page;
int ret;
unlock_op_buf_size = name_len + sizeof(__le32) +
cookie_len + sizeof(__le32) +
CEPH_ENCODING_START_BLK_LEN;
if (unlock_op_buf_size > PAGE_SIZE)
return -E2BIG;
unlock_op_page = alloc_page(GFP_NOIO);
if (!unlock_op_page)
return -ENOMEM;
p = page_address(unlock_op_page);
end = p + unlock_op_buf_size;
ceph_start_encoding(&p, 1, 1,
unlock_op_buf_size - CEPH_ENCODING_START_BLK_LEN);
ceph_encode_string(&p, end, lock_name, name_len);
ceph_encode_string(&p, end, cookie, cookie_len);
dout("%s lock_name %s cookie %s\n", __func__, lock_name, cookie);
ret = ceph_osdc_call(osdc, oid, oloc, "lock", "unlock",
CEPH_OSD_FLAG_WRITE | CEPH_OSD_FLAG_ONDISK,
unlock_op_page, unlock_op_buf_size, NULL, NULL);
dout("%s: status %d\n", __func__, ret);
__free_page(unlock_op_page);
return ret;
}
int ceph_cls_break_lock(struct ceph_osd_client *osdc,
struct ceph_object_id *oid,
struct ceph_object_locator *oloc,
char *lock_name, char *cookie,
struct ceph_entity_name *locker)
{
int break_op_buf_size;
int name_len = strlen(lock_name);
int cookie_len = strlen(cookie);
struct page *break_op_page;
void *p, *end;
int ret;
break_op_buf_size = name_len + sizeof(__le32) +
cookie_len + sizeof(__le32) +
sizeof(u8) + sizeof(__le64) +
CEPH_ENCODING_START_BLK_LEN;
if (break_op_buf_size > PAGE_SIZE)
return -E2BIG;
break_op_page = alloc_page(GFP_NOIO);
if (!break_op_page)
return -ENOMEM;
p = page_address(break_op_page);
end = p + break_op_buf_size;
ceph_start_encoding(&p, 1, 1,
break_op_buf_size - CEPH_ENCODING_START_BLK_LEN);
ceph_encode_string(&p, end, lock_name, name_len);
ceph_encode_copy(&p, locker, sizeof(*locker));
ceph_encode_string(&p, end, cookie, cookie_len);
dout("%s lock_name %s cookie %s locker %s%llu\n", __func__, lock_name,
cookie, ENTITY_NAME(*locker));
ret = ceph_osdc_call(osdc, oid, oloc, "lock", "break_lock",
CEPH_OSD_FLAG_WRITE | CEPH_OSD_FLAG_ONDISK,
break_op_page, break_op_buf_size, NULL, NULL);
dout("%s: status %d\n", __func__, ret);
__free_page(break_op_page);
return ret;
}
void ceph_free_lockers(struct ceph_locker *lockers, u32 num_lockers)
{
int i;
for (i = 0; i < num_lockers; i++)
kfree(lockers[i].id.cookie);
kfree(lockers);
}
static int decode_locker(void **p, void *end, struct ceph_locker *locker)
{
u8 struct_v;
u32 len;
char *s;
int ret;
ret = ceph_start_decoding(p, end, 1, "locker_id_t", &struct_v, &len);
if (ret)
return ret;
ceph_decode_copy(p, &locker->id.name, sizeof(locker->id.name));
s = ceph_extract_encoded_string(p, end, NULL, GFP_NOIO);
if (IS_ERR(s))
return PTR_ERR(s);
locker->id.cookie = s;
ret = ceph_start_decoding(p, end, 1, "locker_info_t", &struct_v, &len);
if (ret)
return ret;
*p += sizeof(struct ceph_timespec);
ceph_decode_copy(p, &locker->info.addr, sizeof(locker->info.addr));
ceph_decode_addr(&locker->info.addr);
len = ceph_decode_32(p);
*p += len;
dout("%s %s%llu cookie %s addr %s\n", __func__,
ENTITY_NAME(locker->id.name), locker->id.cookie,
ceph_pr_addr(&locker->info.addr.in_addr));
return 0;
}
static int decode_lockers(void **p, void *end, u8 *type, char **tag,
struct ceph_locker **lockers, u32 *num_lockers)
{
u8 struct_v;
u32 struct_len;
char *s;
int i;
int ret;
ret = ceph_start_decoding(p, end, 1, "cls_lock_get_info_reply",
&struct_v, &struct_len);
if (ret)
return ret;
*num_lockers = ceph_decode_32(p);
*lockers = kcalloc(*num_lockers, sizeof(**lockers), GFP_NOIO);
if (!*lockers)
return -ENOMEM;
for (i = 0; i < *num_lockers; i++) {
ret = decode_locker(p, end, *lockers + i);
if (ret)
goto err_free_lockers;
}
*type = ceph_decode_8(p);
s = ceph_extract_encoded_string(p, end, NULL, GFP_NOIO);
if (IS_ERR(s)) {
ret = PTR_ERR(s);
goto err_free_lockers;
}
*tag = s;
return 0;
err_free_lockers:
ceph_free_lockers(*lockers, *num_lockers);
return ret;
}
int ceph_cls_lock_info(struct ceph_osd_client *osdc,
struct ceph_object_id *oid,
struct ceph_object_locator *oloc,
char *lock_name, u8 *type, char **tag,
struct ceph_locker **lockers, u32 *num_lockers)
{
int get_info_op_buf_size;
int name_len = strlen(lock_name);
struct page *get_info_op_page, *reply_page;
size_t reply_len;
void *p, *end;
int ret;
get_info_op_buf_size = name_len + sizeof(__le32) +
CEPH_ENCODING_START_BLK_LEN;
if (get_info_op_buf_size > PAGE_SIZE)
return -E2BIG;
get_info_op_page = alloc_page(GFP_NOIO);
if (!get_info_op_page)
return -ENOMEM;
reply_page = alloc_page(GFP_NOIO);
if (!reply_page) {
__free_page(get_info_op_page);
return -ENOMEM;
}
p = page_address(get_info_op_page);
end = p + get_info_op_buf_size;
ceph_start_encoding(&p, 1, 1,
get_info_op_buf_size - CEPH_ENCODING_START_BLK_LEN);
ceph_encode_string(&p, end, lock_name, name_len);
dout("%s lock_name %s\n", __func__, lock_name);
ret = ceph_osdc_call(osdc, oid, oloc, "lock", "get_info",
CEPH_OSD_FLAG_READ, get_info_op_page,
get_info_op_buf_size, reply_page, &reply_len);
dout("%s: status %d\n", __func__, ret);
if (ret >= 0) {
p = page_address(reply_page);
end = p + reply_len;
ret = decode_lockers(&p, end, type, tag, lockers, num_lockers);
}
__free_page(get_info_op_page);
__free_page(reply_page);
return ret;
}
