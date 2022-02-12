int ieee80211_radiotap_iterator_init(
struct ieee80211_radiotap_iterator *iterator,
struct ieee80211_radiotap_header *radiotap_header,
int max_length, const struct ieee80211_radiotap_vendor_namespaces *vns)
{
if (max_length < (int)sizeof(struct ieee80211_radiotap_header))
return -EINVAL;
if (radiotap_header->it_version)
return -EINVAL;
if (max_length < get_unaligned_le16(&radiotap_header->it_len))
return -EINVAL;
iterator->_rtheader = radiotap_header;
iterator->_max_length = get_unaligned_le16(&radiotap_header->it_len);
iterator->_arg_index = 0;
iterator->_bitmap_shifter = get_unaligned_le32(&radiotap_header->it_present);
iterator->_arg = (guint8 *)radiotap_header + sizeof(*radiotap_header);
iterator->_reset_on_ext = 0;
iterator->_next_bitmap = &radiotap_header->it_present;
iterator->_next_bitmap++;
iterator->_vns = vns;
iterator->current_namespace = &radiotap_ns;
iterator->is_radiotap_ns = 1;
#ifdef RADIOTAP_SUPPORT_OVERRIDES
iterator->n_overrides = 0;
iterator->overrides = NULL;
#endif
if (iterator->_bitmap_shifter & (1<<IEEE80211_RADIOTAP_EXT)) {
while (get_unaligned_le32(iterator->_arg) &
(1 << IEEE80211_RADIOTAP_EXT)) {
iterator->_arg += sizeof(guint32);
if (!ITERATOR_VALID(iterator, sizeof(guint32)))
return -EINVAL;
}
iterator->_arg += sizeof(guint32);
}
iterator->this_arg = iterator->_arg;
return 0;
}
static void find_ns(struct ieee80211_radiotap_iterator *iterator,
guint32 oui, guint8 subns)
{
int i;
iterator->current_namespace = NULL;
if (!iterator->_vns)
return;
for (i = 0; i < iterator->_vns->n_ns; i++) {
if (iterator->_vns->ns[i].oui != oui)
continue;
if (iterator->_vns->ns[i].subns != subns)
continue;
iterator->current_namespace = &iterator->_vns->ns[i];
break;
}
}
static int find_override(struct ieee80211_radiotap_iterator *iterator,
int *align, int *size)
{
int i;
if (!iterator->overrides)
return 0;
for (i = 0; i < iterator->n_overrides; i++) {
if (iterator->_arg_index == iterator->overrides[i].field) {
*align = iterator->overrides[i].align;
*size = iterator->overrides[i].size;
if (!*align)
return 0;
return 1;
}
}
return 0;
}
int ieee80211_radiotap_iterator_next(
struct ieee80211_radiotap_iterator *iterator)
{
while (1) {
int hit = 0;
int pad, align, size, subns;
guint32 oui;
if ((iterator->_arg_index % 32) == IEEE80211_RADIOTAP_EXT &&
!(iterator->_bitmap_shifter & 1))
return -ENOENT;
if (!(iterator->_bitmap_shifter & 1))
goto next_entry;
switch (iterator->_arg_index % 32) {
case IEEE80211_RADIOTAP_RADIOTAP_NAMESPACE:
case IEEE80211_RADIOTAP_EXT:
align = 1;
size = 0;
break;
case IEEE80211_RADIOTAP_VENDOR_NAMESPACE:
align = 2;
size = 6;
break;
default:
#ifdef RADIOTAP_SUPPORT_OVERRIDES
if (find_override(iterator, &align, &size)) {
} else
#endif
if (!iterator->current_namespace ||
iterator->_arg_index >= iterator->current_namespace->n_bits) {
if (iterator->current_namespace == &radiotap_ns)
return -ENOENT;
align = 0;
} else {
align = iterator->current_namespace->align_size[iterator->_arg_index].align;
size = iterator->current_namespace->align_size[iterator->_arg_index].size;
}
if (!align) {
iterator->_arg = iterator->_next_ns_data;
iterator->current_namespace = NULL;
goto next_entry;
}
break;
}
pad = (int)((iterator->_arg - (unsigned char *)iterator->_rtheader) & (align - 1));
if (pad)
iterator->_arg += align - pad;
if (iterator->_arg_index % 32 == IEEE80211_RADIOTAP_VENDOR_NAMESPACE) {
int vnslen;
if (!ITERATOR_VALID(iterator, size))
return -EINVAL;
oui = (*iterator->_arg << 16) |
(*(iterator->_arg + 1) << 8) |
*(iterator->_arg + 2);
subns = *(iterator->_arg + 3);
find_ns(iterator, oui, subns);
vnslen = get_unaligned_le16(iterator->_arg + 4);
iterator->_next_ns_data = iterator->_arg + size + vnslen;
if (!iterator->current_namespace)
size += vnslen;
}
iterator->this_arg_index = iterator->_arg_index;
iterator->this_arg = iterator->_arg;
iterator->this_arg_size = size;
iterator->_arg += size;
if (!ITERATOR_VALID(iterator, 0))
return -EINVAL;
switch (iterator->_arg_index % 32) {
case IEEE80211_RADIOTAP_VENDOR_NAMESPACE:
iterator->_reset_on_ext = 1;
iterator->is_radiotap_ns = 0;
iterator->this_arg_index =
IEEE80211_RADIOTAP_VENDOR_NAMESPACE;
if (!iterator->current_namespace)
hit = 1;
goto next_entry;
case IEEE80211_RADIOTAP_RADIOTAP_NAMESPACE:
iterator->_reset_on_ext = 1;
iterator->current_namespace = &radiotap_ns;
iterator->is_radiotap_ns = 1;
goto next_entry;
case IEEE80211_RADIOTAP_EXT:
iterator->_bitmap_shifter =
get_unaligned_le32(iterator->_next_bitmap);
iterator->_next_bitmap++;
if (iterator->_reset_on_ext)
iterator->_arg_index = 0;
else
iterator->_arg_index++;
iterator->_reset_on_ext = 0;
break;
default:
hit = 1;
next_entry:
iterator->_bitmap_shifter >>= 1;
iterator->_arg_index++;
}
if (hit)
return 0;
}
}
