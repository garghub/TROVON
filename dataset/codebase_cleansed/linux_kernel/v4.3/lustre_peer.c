void class_init_uuidlist(void)
{
INIT_LIST_HEAD(&g_uuid_list);
spin_lock_init(&g_uuid_lock);
}
void class_exit_uuidlist(void)
{
class_del_uuid(NULL);
}
int lustre_uuid_to_peer(const char *uuid, lnet_nid_t *peer_nid, int index)
{
struct uuid_nid_data *data;
struct obd_uuid tmp;
int rc = -ENOENT;
obd_str2uuid(&tmp, uuid);
spin_lock(&g_uuid_lock);
list_for_each_entry(data, &g_uuid_list, un_list) {
if (obd_uuid_equals(&data->un_uuid, &tmp)) {
if (index >= data->un_nid_count)
break;
rc = 0;
*peer_nid = data->un_nids[index];
break;
}
}
spin_unlock(&g_uuid_lock);
return rc;
}
int class_add_uuid(const char *uuid, __u64 nid)
{
struct uuid_nid_data *data, *entry;
int found = 0;
LASSERT(nid != 0);
if (strlen(uuid) > UUID_MAX - 1)
return -EOVERFLOW;
data = kzalloc(sizeof(*data), GFP_NOFS);
if (!data)
return -ENOMEM;
obd_str2uuid(&data->un_uuid, uuid);
data->un_nids[0] = nid;
data->un_nid_count = 1;
spin_lock(&g_uuid_lock);
list_for_each_entry(entry, &g_uuid_list, un_list) {
if (obd_uuid_equals(&entry->un_uuid, &data->un_uuid)) {
int i;
found = 1;
for (i = 0; i < entry->un_nid_count; i++)
if (nid == entry->un_nids[i])
break;
if (i == entry->un_nid_count) {
LASSERT(entry->un_nid_count < NIDS_MAX);
entry->un_nids[entry->un_nid_count++] = nid;
}
break;
}
}
if (!found)
list_add(&data->un_list, &g_uuid_list);
spin_unlock(&g_uuid_lock);
if (found) {
CDEBUG(D_INFO, "found uuid %s %s cnt=%d\n", uuid,
libcfs_nid2str(nid), entry->un_nid_count);
kfree(data);
} else {
CDEBUG(D_INFO, "add uuid %s %s\n", uuid, libcfs_nid2str(nid));
}
return 0;
}
int class_del_uuid(const char *uuid)
{
LIST_HEAD(deathrow);
struct uuid_nid_data *data;
spin_lock(&g_uuid_lock);
if (uuid != NULL) {
struct obd_uuid tmp;
obd_str2uuid(&tmp, uuid);
list_for_each_entry(data, &g_uuid_list, un_list) {
if (obd_uuid_equals(&data->un_uuid, &tmp)) {
list_move(&data->un_list, &deathrow);
break;
}
}
} else
list_splice_init(&g_uuid_list, &deathrow);
spin_unlock(&g_uuid_lock);
if (uuid != NULL && list_empty(&deathrow)) {
CDEBUG(D_INFO, "Try to delete a non-existent uuid %s\n", uuid);
return -EINVAL;
}
while (!list_empty(&deathrow)) {
data = list_entry(deathrow.next, struct uuid_nid_data,
un_list);
list_del(&data->un_list);
CDEBUG(D_INFO, "del uuid %s %s/%d\n",
obd_uuid2str(&data->un_uuid),
libcfs_nid2str(data->un_nids[0]),
data->un_nid_count);
kfree(data);
}
return 0;
}
int class_check_uuid(struct obd_uuid *uuid, __u64 nid)
{
struct uuid_nid_data *entry;
int found = 0;
CDEBUG(D_INFO, "check if uuid %s has %s.\n",
obd_uuid2str(uuid), libcfs_nid2str(nid));
spin_lock(&g_uuid_lock);
list_for_each_entry(entry, &g_uuid_list, un_list) {
int i;
if (!obd_uuid_equals(&entry->un_uuid, uuid))
continue;
for (i = 0; i < entry->un_nid_count; i++) {
if (entry->un_nids[i] == nid) {
found = 1;
break;
}
}
break;
}
spin_unlock(&g_uuid_lock);
return found;
}
