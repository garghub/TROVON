static int set_update_marker(struct ubi_device *ubi, struct ubi_volume *vol)
{
int err;
struct ubi_vtbl_record vtbl_rec;
dbg_gen("set update marker for volume %d", vol->vol_id);
if (vol->upd_marker) {
ubi_assert(ubi->vtbl[vol->vol_id].upd_marker);
dbg_gen("already set");
return 0;
}
vtbl_rec = ubi->vtbl[vol->vol_id];
vtbl_rec.upd_marker = 1;
mutex_lock(&ubi->device_mutex);
err = ubi_change_vtbl_record(ubi, vol->vol_id, &vtbl_rec);
vol->upd_marker = 1;
mutex_unlock(&ubi->device_mutex);
return err;
}
static int clear_update_marker(struct ubi_device *ubi, struct ubi_volume *vol,
long long bytes)
{
int err;
struct ubi_vtbl_record vtbl_rec;
dbg_gen("clear update marker for volume %d", vol->vol_id);
vtbl_rec = ubi->vtbl[vol->vol_id];
ubi_assert(vol->upd_marker && vtbl_rec.upd_marker);
vtbl_rec.upd_marker = 0;
if (vol->vol_type == UBI_STATIC_VOLUME) {
vol->corrupted = 0;
vol->used_bytes = bytes;
vol->used_ebs = div_u64_rem(bytes, vol->usable_leb_size,
&vol->last_eb_bytes);
if (vol->last_eb_bytes)
vol->used_ebs += 1;
else
vol->last_eb_bytes = vol->usable_leb_size;
}
mutex_lock(&ubi->device_mutex);
err = ubi_change_vtbl_record(ubi, vol->vol_id, &vtbl_rec);
vol->upd_marker = 0;
mutex_unlock(&ubi->device_mutex);
return err;
}
int ubi_start_update(struct ubi_device *ubi, struct ubi_volume *vol,
long long bytes)
{
int i, err;
dbg_gen("start update of volume %d, %llu bytes", vol->vol_id, bytes);
ubi_assert(!vol->updating && !vol->changing_leb);
vol->updating = 1;
vol->upd_buf = vmalloc(ubi->leb_size);
if (!vol->upd_buf)
return -ENOMEM;
err = set_update_marker(ubi, vol);
if (err)
return err;
for (i = 0; i < vol->reserved_pebs; i++) {
err = ubi_eba_unmap_leb(ubi, vol, i);
if (err)
return err;
}
if (bytes == 0) {
err = ubi_wl_flush(ubi, UBI_ALL, UBI_ALL);
if (err)
return err;
err = clear_update_marker(ubi, vol, 0);
if (err)
return err;
vfree(vol->upd_buf);
vol->updating = 0;
return 0;
}
vol->upd_ebs = div_u64(bytes + vol->usable_leb_size - 1,
vol->usable_leb_size);
vol->upd_bytes = bytes;
vol->upd_received = 0;
return 0;
}
int ubi_start_leb_change(struct ubi_device *ubi, struct ubi_volume *vol,
const struct ubi_leb_change_req *req)
{
ubi_assert(!vol->updating && !vol->changing_leb);
dbg_gen("start changing LEB %d:%d, %u bytes",
vol->vol_id, req->lnum, req->bytes);
if (req->bytes == 0)
return ubi_eba_atomic_leb_change(ubi, vol, req->lnum, NULL, 0);
vol->upd_bytes = req->bytes;
vol->upd_received = 0;
vol->changing_leb = 1;
vol->ch_lnum = req->lnum;
vol->upd_buf = vmalloc(ALIGN((int)req->bytes, ubi->min_io_size));
if (!vol->upd_buf)
return -ENOMEM;
return 0;
}
static int write_leb(struct ubi_device *ubi, struct ubi_volume *vol, int lnum,
void *buf, int len, int used_ebs)
{
int err;
if (vol->vol_type == UBI_DYNAMIC_VOLUME) {
int l = ALIGN(len, ubi->min_io_size);
memset(buf + len, 0xFF, l - len);
len = ubi_calc_data_len(ubi, buf, l);
if (len == 0) {
dbg_gen("all %d bytes contain 0xFF - skip", len);
return 0;
}
err = ubi_eba_write_leb(ubi, vol, lnum, buf, 0, len);
} else {
memset(buf + len, 0, vol->usable_leb_size - len);
err = ubi_eba_write_leb_st(ubi, vol, lnum, buf, len, used_ebs);
}
return err;
}
int ubi_more_update_data(struct ubi_device *ubi, struct ubi_volume *vol,
const void __user *buf, int count)
{
int lnum, offs, err = 0, len, to_write = count;
dbg_gen("write %d of %lld bytes, %lld already passed",
count, vol->upd_bytes, vol->upd_received);
if (ubi->ro_mode)
return -EROFS;
lnum = div_u64_rem(vol->upd_received, vol->usable_leb_size, &offs);
if (vol->upd_received + count > vol->upd_bytes)
to_write = count = vol->upd_bytes - vol->upd_received;
if (offs != 0) {
len = vol->usable_leb_size - offs;
if (len > count)
len = count;
err = copy_from_user(vol->upd_buf + offs, buf, len);
if (err)
return -EFAULT;
if (offs + len == vol->usable_leb_size ||
vol->upd_received + len == vol->upd_bytes) {
int flush_len = offs + len;
ubi_assert(flush_len <= vol->usable_leb_size);
err = write_leb(ubi, vol, lnum, vol->upd_buf, flush_len,
vol->upd_ebs);
if (err)
return err;
}
vol->upd_received += len;
count -= len;
buf += len;
lnum += 1;
}
while (count) {
if (count > vol->usable_leb_size)
len = vol->usable_leb_size;
else
len = count;
err = copy_from_user(vol->upd_buf, buf, len);
if (err)
return -EFAULT;
if (len == vol->usable_leb_size ||
vol->upd_received + len == vol->upd_bytes) {
err = write_leb(ubi, vol, lnum, vol->upd_buf,
len, vol->upd_ebs);
if (err)
break;
}
vol->upd_received += len;
count -= len;
lnum += 1;
buf += len;
}
ubi_assert(vol->upd_received <= vol->upd_bytes);
if (vol->upd_received == vol->upd_bytes) {
err = ubi_wl_flush(ubi, UBI_ALL, UBI_ALL);
if (err)
return err;
err = clear_update_marker(ubi, vol, vol->upd_bytes);
if (err)
return err;
vol->updating = 0;
err = to_write;
vfree(vol->upd_buf);
}
return err;
}
int ubi_more_leb_change_data(struct ubi_device *ubi, struct ubi_volume *vol,
const void __user *buf, int count)
{
int err;
dbg_gen("write %d of %lld bytes, %lld already passed",
count, vol->upd_bytes, vol->upd_received);
if (ubi->ro_mode)
return -EROFS;
if (vol->upd_received + count > vol->upd_bytes)
count = vol->upd_bytes - vol->upd_received;
err = copy_from_user(vol->upd_buf + vol->upd_received, buf, count);
if (err)
return -EFAULT;
vol->upd_received += count;
if (vol->upd_received == vol->upd_bytes) {
int len = ALIGN((int)vol->upd_bytes, ubi->min_io_size);
memset(vol->upd_buf + vol->upd_bytes, 0xFF,
len - vol->upd_bytes);
len = ubi_calc_data_len(ubi, vol->upd_buf, len);
err = ubi_eba_atomic_leb_change(ubi, vol, vol->ch_lnum,
vol->upd_buf, len);
if (err)
return err;
}
ubi_assert(vol->upd_received <= vol->upd_bytes);
if (vol->upd_received == vol->upd_bytes) {
vol->changing_leb = 0;
err = count;
vfree(vol->upd_buf);
}
return err;
}
