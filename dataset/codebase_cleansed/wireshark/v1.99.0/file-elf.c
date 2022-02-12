static gint
value_guard(guint64 value)
{
DISSECTOR_ASSERT_HINT(value <= G_MAXINT, "Too big file - not supported");
return (gint) value;
}
static guint8
dissect_dwarf_encoding(tvbuff_t *tvb, gint offset, proto_item *item)
{
guint8 value;
proto_tree *tree;
tree = proto_item_add_subtree(item, ett_dwarf_encoding);
value = tvb_get_guint8(tvb, offset);
if (value == 0xFF) {
proto_tree_add_item(tree, hf_dwarf_omit, tvb, offset, 1, ENC_NA);
} else {
proto_tree_add_item(tree, hf_dwarf_upper, tvb, offset, 1, ENC_NA);
proto_tree_add_item(tree, hf_dwarf_format, tvb, offset, 1, ENC_NA);
}
return value;
}
static gint8
get_dwarf_extension_length(guint8 format, guint register_size)
{
switch (format & 0x0F) {
case 0x0:
return register_size;
case 0x1:
return LENGTH_ULEB128;
case 0x2:
return 2;
case 0x3:
return 4;
case 0x4:
return 8;
case 0x9:
return LENGTH_LEB128;
case 0xA:
return 2;
case 0xB:
return 4;
case 0xC:
return 8;
}
return 0;
}
static const guint8 *
get_section_name_offset(tvbuff_t *tvb, guint64 shoff, guint16 shnum, guint16 shentsize, guint16 shndx, guint64 shstrtab_offset, guint machine_encoding)
{
gint offset;
guint32 sh_name;
if (shndx > shnum)
return NULL;
offset = value_guard(shoff + shndx * shentsize);
sh_name = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
return tvb_get_const_stringz(tvb, value_guard(shstrtab_offset + sh_name), NULL);
}
static gint
dissect_dynamic(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *entry_tree, proto_item *entry_item,
gint offset, gint register_size, guint machine_encoding)
{
enum enum_tag_type {
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_IGNORED,
DYNAMIC_TYPE_UNSPECIFIED
};
guint64 tag;
static const enum enum_tag_type tag_to_type[MAX_TAG_TO_TYPE] = {
DYNAMIC_TYPE_IGNORED,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_IGNORED,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_IGNORED,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_IGNORED,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_VALUE,
DYNAMIC_TYPE_UNSPECIFIED,
DYNAMIC_TYPE_POINTER,
DYNAMIC_TYPE_VALUE
};
if (register_size == REGISTER_32_SIZE) {
proto_tree_add_item(entry_tree, hf_elf_dynamic_tag, tvb, offset, 4, machine_encoding);
tag = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
offset += 4;
if (tag < MAX_TAG_TO_TYPE && tag_to_type[tag] == DYNAMIC_TYPE_VALUE)
proto_tree_add_item(entry_tree, hf_elf_dynamic_value, tvb, offset, 4, machine_encoding);
else if (tag < MAX_TAG_TO_TYPE && tag_to_type[tag] == DYNAMIC_TYPE_POINTER)
proto_tree_add_item(entry_tree, hf_elf_dynamic_pointer, tvb, offset, 4, machine_encoding);
else if (tag < MAX_TAG_TO_TYPE && tag_to_type[tag] == DYNAMIC_TYPE_IGNORED)
proto_tree_add_item(entry_tree, hf_elf_dynamic_ignored, tvb, offset, 4, machine_encoding);
else
proto_tree_add_item(entry_tree, hf_elf_dynamic_unspecified, tvb, offset, 4, machine_encoding);
offset += 4;
} else {
proto_item *pitem;
pitem = proto_tree_add_item(entry_tree, hf_elf64_dynamic_tag, tvb, offset, 8, machine_encoding);
tag = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
proto_item_append_text(pitem, " (%s)", rval_to_str(value_guard(tag), dynamic_tag_rvals, "Unknown"));
offset += 8;
if (tag < MAX_TAG_TO_TYPE && tag_to_type[tag] == DYNAMIC_TYPE_VALUE)
proto_tree_add_item(entry_tree, hf_elf64_dynamic_value, tvb, offset, 8, machine_encoding);
else if (tag < MAX_TAG_TO_TYPE && tag_to_type[tag] == DYNAMIC_TYPE_POINTER)
proto_tree_add_item(entry_tree, hf_elf64_dynamic_pointer, tvb, offset, 8, machine_encoding);
else if (tag < MAX_TAG_TO_TYPE && tag_to_type[tag] == DYNAMIC_TYPE_IGNORED)
proto_tree_add_item(entry_tree, hf_elf64_dynamic_ignored, tvb, offset, 8, machine_encoding);
else
proto_tree_add_item(entry_tree, hf_elf64_dynamic_unspecified, tvb, offset, 8, machine_encoding);
offset += 8;
}
proto_item_append_text(entry_item, ": %s", rval_to_str(value_guard(tag), dynamic_tag_rvals, "Unknown"));
return offset;
}
static gint
dissect_symbol_table(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *entry_tree, proto_item *entry_item,
gint offset, gint register_size, guint machine_encoding, guint64 strtab_offset,
guint64 shoff, guint16 shnum, guint16 shentsize, guint64 shstrtab_offset)
{
proto_item *pitem;
proto_item *info_item;
proto_tree *info_tree;
guint16 shndx;
guint32 name_index;
const guint8 *section_name;
const guint8 *name;
guint8 info_bind;
guint8 info_type;
pitem = proto_tree_add_item(entry_tree, hf_elf_symbol_table_name_index, tvb, offset, 4, machine_encoding);
if (strtab_offset) {
name_index = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
name = tvb_get_const_stringz(tvb, value_guard(strtab_offset + name_index), NULL);
if (name) {
proto_item_append_text(pitem, ": %s", name);
proto_item_append_text(entry_item, ": %s", name);
}
}
offset += 4;
if (register_size == REGISTER_32_SIZE) {
proto_tree_add_item(entry_tree, hf_elf_symbol_table_value, tvb, offset, 4, machine_encoding);
offset += 4;
proto_tree_add_item(entry_tree, hf_elf_symbol_table_size, tvb, offset, 4, machine_encoding);
offset += 4;
info_item = proto_tree_add_item(entry_tree, hf_elf_symbol_table_info, tvb, offset, 1, machine_encoding);
info_tree = proto_item_add_subtree(info_item, ett_symbol_table_info);
proto_tree_add_item(info_tree, hf_elf_symbol_table_info_bind, tvb, offset, 1, machine_encoding);
proto_tree_add_item(info_tree, hf_elf_symbol_table_info_type, tvb, offset, 1, machine_encoding);
info_bind = tvb_get_guint8(tvb, offset) >> 4;
info_type = tvb_get_guint8(tvb, offset) & 0x0F;
offset += 1;
proto_tree_add_item(entry_tree, hf_elf_symbol_table_other, tvb, offset, 1, machine_encoding);
offset += 1;
pitem = proto_tree_add_item(entry_tree, hf_elf_symbol_table_shndx, tvb, offset, 2, machine_encoding);
shndx = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohs(tvb, offset) : tvb_get_letohs(tvb, offset);
if (shndx <= shnum) {
section_name = get_section_name_offset(tvb, shoff, shnum, shentsize, shndx, shstrtab_offset, machine_encoding);
if (section_name && section_name[0] != '\0')
proto_item_append_text(pitem, " (%u: %s)", shndx, section_name);
} else {
proto_item_append_text(pitem, " (%u)", shndx);
}
offset += 2;
} else {
info_item = proto_tree_add_item(entry_tree, hf_elf_symbol_table_info, tvb, offset, 1, machine_encoding);
info_tree = proto_item_add_subtree(info_item, ett_symbol_table_info);
proto_tree_add_item(info_tree, hf_elf_symbol_table_info_bind, tvb, offset, 1, machine_encoding);
proto_tree_add_item(info_tree, hf_elf_symbol_table_info_type, tvb, offset, 1, machine_encoding);
info_bind = tvb_get_guint8(tvb, offset) >> 4;
info_type = tvb_get_guint8(tvb, offset) & 0x0F;
offset += 1;
proto_tree_add_item(entry_tree, hf_elf_symbol_table_other, tvb, offset, 1, machine_encoding);
offset += 1;
pitem = proto_tree_add_item(entry_tree, hf_elf_symbol_table_shndx, tvb, offset, 2, machine_encoding);
shndx = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohs(tvb, offset) : tvb_get_letohs(tvb, offset);
if (shndx <= shnum) {
section_name = get_section_name_offset(tvb, shoff, shnum, shentsize, shndx, shstrtab_offset, machine_encoding);
if (section_name && section_name[0] != '\0')
proto_item_append_text(pitem, " (%u: %s)", shndx, section_name);
} else {
proto_item_append_text(pitem, " (%u)", shndx);
}
offset += 2;
proto_tree_add_item(entry_tree, hf_elf64_symbol_table_value, tvb, offset, 8, machine_encoding);
offset += 8;
proto_tree_add_item(entry_tree, hf_elf64_symbol_table_size, tvb, offset, 8, machine_encoding);
offset += 8;
}
proto_item_append_text(info_item, " (Bind: %s, Type: %s)",
val_to_str_const(info_bind, symbol_table_info_bind_vals, "Unknown"),
val_to_str_ext_const(info_type, &symbol_table_info_type_vals_ext, "Unknown"));
proto_item_append_text(entry_item, " (Bind: %s, Type: %s)",
val_to_str_const(info_bind, symbol_table_info_bind_vals, "Unknown"),
val_to_str_ext_const(info_type, &symbol_table_info_type_vals_ext, "Unknown"));
return offset;
}
static gint
dissect_eh_frame_hdr(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *segment_tree,
gint offset, gint segment_size _U_, gint register_size, guint machine_encoding)
{
proto_item *item;
proto_tree *table_tree;
guint8 format;
gint efp_length;
gint fde_count_length;
gint table_entry_length;
guint64 fde_count;
guint i_entry;
proto_tree_add_item(segment_tree, hf_elf_eh_frame_hdr_version, tvb, offset, 1, machine_encoding);
offset += 1;
item = proto_tree_add_item(segment_tree, hf_elf_eh_frame_hdr_exception_frame_pointer_encoding, tvb, offset, 1, machine_encoding);
format = dissect_dwarf_encoding(tvb, offset, item);
efp_length = get_dwarf_extension_length(format, register_size);
offset += 1;
item = proto_tree_add_item(segment_tree, hf_elf_eh_frame_hdr_fde_count_encoding, tvb, offset, 1, machine_encoding);
format = dissect_dwarf_encoding(tvb, offset, item);
fde_count_length = get_dwarf_extension_length(format, register_size);
offset += 1;
item = proto_tree_add_item(segment_tree, hf_elf_eh_frame_hdr_binary_search_table_encoding, tvb, offset, 1, machine_encoding);
format = dissect_dwarf_encoding(tvb, offset, item);
table_entry_length = get_dwarf_extension_length(format, register_size);
offset += 1;
if (efp_length == LENGTH_ULEB128) {
guint64 value;
efp_length = dissect_uleb128(tvb, offset, &value);
} else if (efp_length == LENGTH_LEB128) {
gint64 value;
efp_length = dissect_leb128(tvb, offset, &value);
}
proto_tree_add_item(segment_tree, hf_elf_eh_frame_hdr_eh_frame_ptr, tvb, offset, efp_length, machine_encoding);
offset += efp_length;
if (fde_count_length == LENGTH_ULEB128) {
fde_count_length = dissect_uleb128(tvb, offset, &fde_count);
} else if (fde_count_length == LENGTH_LEB128) {
gint64 value;
fde_count_length = dissect_leb128(tvb, offset, &value);
fde_count = (guint64) value;
} else {
if (fde_count_length == 0) fde_count_length = register_size;
switch(fde_count_length) {
case 2:
fde_count = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohs(tvb, offset) : tvb_get_letohs(tvb, offset);
break;
case 4:
fde_count = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
break;
case 8:
fde_count = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
break;
case 0:
default:
fde_count = 0;
break;
}
}
proto_tree_add_item(segment_tree, hf_elf_eh_frame_hdr_fde_count, tvb, offset, fde_count_length, machine_encoding);
offset += fde_count_length;
if (table_entry_length == LENGTH_ULEB128) {
guint64 value;
table_entry_length = dissect_uleb128(tvb, offset, &value);
} else if (table_entry_length == LENGTH_LEB128) {
gint64 value;
table_entry_length = dissect_leb128(tvb, offset, &value);
}
i_entry = 0;
table_tree = proto_tree_add_subtree(segment_tree, tvb, offset, value_guard(fde_count * table_entry_length * 2),
ett_binary_table, NULL, "Binary Search Table");
while (++i_entry <= fde_count) {
proto_tree *entry_tree;
entry_tree = proto_tree_add_subtree_format(table_tree, tvb, offset, table_entry_length * 2, ett_binary_table_entry,
NULL, "Binary Table Entry #%u", i_entry);
proto_tree_add_item(entry_tree, hf_elf_eh_frame_hdr_binary_search_table_entry_initial_location, tvb, offset, table_entry_length, machine_encoding);
offset += table_entry_length;
proto_tree_add_item(entry_tree, hf_elf_eh_frame_hdr_binary_search_table_entry_address, tvb, offset, table_entry_length, machine_encoding);
offset += table_entry_length;
}
return offset;
}
static gint
dissect_eh_frame(tvbuff_t *tvb, packet_info *pinfo _U_, proto_tree *segment_tree,
gint offset, gint segment_size _U_, gint register_size _U_, guint machine_encoding)
{
proto_tree *record_tree;
proto_tree *entry_tree;
guint64 length;
guint64 length_remaining;
guint64 unsigned_value;
gint64 signed_value;
gint size;
gint augmentation_string_length;
const guint8 *augmentation_string;
gboolean is_extended_length = FALSE;
gint start_offset = offset;
gint entry_number;
length = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
if (length == 0xFFFFFFFF) {
is_extended_length = TRUE;
length = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset + 4) : tvb_get_letoh64(tvb, offset + 4);
}
length_remaining = length;
record_tree = proto_tree_add_subtree(segment_tree, tvb, offset, value_guard(length + (is_extended_length ? 4 + 8 : 4)),
ett_elf_cie, NULL, "Common Information Entry");
proto_tree_add_item(record_tree, hf_elf_eh_frame_length, tvb, offset, 4, machine_encoding);
offset += 4;
if (is_extended_length) {
proto_tree_add_item(record_tree, hf_elf_eh_frame_extended_length, tvb, offset, 8, machine_encoding);
offset += 8;
}
proto_tree_add_item(record_tree, hf_elf_eh_frame_cie_id, tvb, offset, 4, machine_encoding);
length_remaining -= 4;
offset += 4;
proto_tree_add_item(record_tree, hf_elf_eh_frame_version, tvb, offset, 1, machine_encoding);
length_remaining -= 1;
offset += 1;
augmentation_string = tvb_get_const_stringz(tvb, offset, &augmentation_string_length);
proto_tree_add_item(record_tree, hf_elf_eh_frame_augmentation_string, tvb, offset, augmentation_string_length, machine_encoding);
length_remaining -= augmentation_string_length;
offset += augmentation_string_length;
size = dissect_uleb128(tvb, offset, &unsigned_value);
proto_tree_add_uint64(record_tree, hf_elf_eh_frame_code_alignment_factor, tvb, offset, size, unsigned_value);
length_remaining -= size;
offset += size;
size = dissect_leb128(tvb, offset, &signed_value);
proto_tree_add_int64(record_tree, hf_elf_eh_frame_data_alignment_factor, tvb, offset, size, signed_value);
length_remaining -= size;
offset += size;
size = dissect_uleb128(tvb, offset, &unsigned_value);
proto_tree_add_uint64(record_tree, hf_elf_eh_frame_return_address_register, tvb, offset, size, unsigned_value);
length_remaining -= size;
offset += size;
if (strchr(augmentation_string, 'z')) {
size = dissect_uleb128(tvb, offset, &unsigned_value);
proto_tree_add_uint64(record_tree, hf_elf_eh_frame_augmentation_length, tvb, offset, size, unsigned_value);
length_remaining -= size;
offset += size;
proto_tree_add_item(record_tree, hf_elf_eh_frame_augmentation_data, tvb, offset, value_guard(unsigned_value), machine_encoding);
length_remaining -= unsigned_value;
offset += value_guard(unsigned_value);
}
proto_tree_add_item(record_tree, hf_elf_eh_frame_initial_instructions, tvb, offset, value_guard(length_remaining), machine_encoding);
offset += value_guard(length_remaining);
record_tree = proto_tree_add_subtree(segment_tree, tvb, offset, value_guard(segment_size - length - 4),
ett_elf_fde, NULL, "Frame Description Entries");
is_extended_length = FALSE;
entry_number = 1;
while (segment_size - (offset - start_offset)) {
length = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
if (length == 0xFFFFFFFF) {
is_extended_length = TRUE;
length = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset + 4) : tvb_get_letoh64(tvb, offset + 4);
}
entry_tree = proto_tree_add_subtree_format(record_tree, tvb, offset, value_guard(length + (is_extended_length ? 4 + 8 : 4)),
ett_elf_entry, NULL, "Entry %i", entry_number);
proto_tree_add_item(entry_tree, hf_elf_eh_frame_fde_length, tvb, offset, 4, machine_encoding);
offset += 4;
if (is_extended_length) {
proto_tree_add_item(entry_tree, hf_elf_eh_frame_fde_extended_length, tvb, offset, 8, machine_encoding);
offset += 8;
}
if (length == 0) break;
length_remaining = length;
proto_tree_add_item(entry_tree, hf_elf_eh_frame_fde_cie_pointer, tvb, offset, 4, machine_encoding);
length_remaining -= 4;
offset += 4;
proto_tree_add_item(entry_tree, hf_elf_eh_frame_fde_pc_begin, tvb, offset, 4, machine_encoding);
length_remaining -= 4;
offset += 4;
proto_tree_add_item(entry_tree, hf_elf_eh_frame_fde_pc_range, tvb, offset, 4, machine_encoding);
length_remaining -= 4;
offset += 4;
if (strchr(augmentation_string, 'z')) {
size = dissect_uleb128(tvb, offset, &unsigned_value);
proto_tree_add_uint64(entry_tree, hf_elf_eh_frame_fde_augmentation_length, tvb, offset, size, unsigned_value);
length_remaining -= size;
offset += size;
proto_tree_add_item(entry_tree, hf_elf_eh_frame_fde_augmentation_data, tvb, offset, value_guard(unsigned_value), machine_encoding);
length_remaining -= unsigned_value;
offset += value_guard(unsigned_value);
}
proto_tree_add_item(entry_tree, hf_elf_eh_frame_fde_call_frame_instructions, tvb, offset, value_guard(length_remaining), machine_encoding);
offset += value_guard(length_remaining);
entry_number += 1;
}
return offset;
}
static int
dissect_elf(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
static const guint8 magic[] = { 0x7F, 'E', 'L', 'F'};
gint offset = 0;
proto_tree *main_tree;
proto_item *main_item;
proto_tree *header_tree;
proto_item *header_item;
proto_tree *program_header_tree;
proto_tree *section_header_tree;
proto_tree *ph_entry_tree;
proto_item *sh_entry_item;
proto_tree *sh_entry_tree;
proto_item *segment_item;
proto_tree *segment_tree;
proto_item *generated_item;
proto_tree *generated_tree;
proto_tree *overlapping_tree;
proto_tree *blackhole_tree;
proto_item *entry_item;
proto_tree *entry_tree;
guint machine_encoding = ENC_NA;
gint register_size = 4;
guint16 phentsize;
guint16 phnum;
guint16 shentsize;
guint16 shnum;
guint64 phoff;
guint64 shoff;
guint16 i_16;
guint32 p_type;
guint32 sh_type;
guint16 shstrndx;
guint64 shstrtab_offset;
guint32 sh_name;
const guint8 *section_name;
guint64 length;
guint64 segment_offset;
guint64 segment_size;
guint64 file_size;
guint64 p_offset;
gint ehsize;
guint area_counter = 0;
segment_info_t *segment_info;
guint i;
guint i_next;
gint next_offset;
gint len;
guint64 sh_entsize;
guint64 strtab_offset = 0;
guint64 dynstr_offset = 0;
if (tvb_length(tvb) < 52)
return 0;
if (tvb_memeql(tvb, 0, magic, sizeof(magic)) != 0)
return 0;
main_item = proto_tree_add_item(tree, proto_elf, tvb, offset, -1, ENC_NA);
main_tree = proto_item_add_subtree(main_item, ett_elf);
header_tree = proto_tree_add_subtree(main_tree, tvb, offset, 1, ett_elf_header, &header_item, "Header");
proto_tree_add_item(header_tree, hf_elf_magic_bytes, tvb, offset, sizeof(magic), ENC_NA);
offset += (int)sizeof(magic);
proto_tree_add_item(header_tree, hf_elf_file_class, tvb, offset, 1, ENC_NA);
register_size *= tvb_get_guint8(tvb, offset);
offset += 1;
proto_tree_add_item(header_tree, hf_elf_data_encoding, tvb, offset, 1, ENC_NA);
if (tvb_get_guint8(tvb, offset) == 1)
machine_encoding = ENC_LITTLE_ENDIAN;
else
machine_encoding = ENC_BIG_ENDIAN;
offset += 1;
proto_tree_add_item(header_tree, hf_elf_file_version, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(header_tree, hf_elf_os_abi, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(header_tree, hf_elf_abi_version, tvb, offset, 1, ENC_NA);
offset += 1;
proto_tree_add_item(header_tree, hf_elf_file_padding, tvb, offset, 7, ENC_NA);
offset += 7;
proto_tree_add_item(header_tree, hf_elf_type, tvb, offset, 2, machine_encoding);
offset += 2;
proto_tree_add_item(header_tree, hf_elf_machine, tvb, offset, 2, machine_encoding);
offset += 2;
proto_tree_add_item(header_tree, hf_elf_version, tvb, offset, 4, machine_encoding);
offset += 4;
proto_tree_add_item(header_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_entry : hf_elf64_entry,
tvb, offset, register_size, machine_encoding);
offset += register_size;
if (register_size == REGISTER_32_SIZE) {
proto_tree_add_item(header_tree, hf_elf_phoff, tvb, offset,
register_size, machine_encoding);
phoff = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
} else {
proto_tree_add_item(header_tree, hf_elf64_phoff, tvb, offset,
register_size, machine_encoding);
phoff = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
}
offset += register_size;
if (register_size == REGISTER_32_SIZE) {
proto_tree_add_item(header_tree, hf_elf_shoff, tvb, offset,
register_size, machine_encoding);
shoff = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
} else {
proto_tree_add_item(header_tree, hf_elf64_shoff, tvb, offset,
register_size, machine_encoding);
shoff = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
}
offset += register_size;
proto_tree_add_item(header_tree, hf_elf_flags, tvb, offset, 4, machine_encoding);
offset += 4;
proto_tree_add_item(header_tree, hf_elf_ehsize, tvb, offset, 2, machine_encoding);
ehsize = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohs(tvb, offset) : tvb_get_letohs(tvb, offset);
proto_item_set_len(header_item, ehsize);
offset += 2;
proto_tree_add_item(header_tree, hf_elf_phentsize, tvb, offset, 2, machine_encoding);
phentsize = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohs(tvb, offset) : tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(header_tree, hf_elf_phnum, tvb, offset, 2, machine_encoding);
phnum = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohs(tvb, offset) : tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(header_tree, hf_elf_shentsize, tvb, offset, 2, machine_encoding);
shentsize = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohs(tvb, offset) : tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(header_tree, hf_elf_shnum, tvb, offset, 2, machine_encoding);
shnum = (machine_encoding == ENC_BIG_ENDIAN) ? tvb_get_ntohs(tvb, offset) : tvb_get_letohs(tvb, offset);
offset += 2;
proto_tree_add_item(header_tree, hf_elf_shstrndx, tvb, offset, 2, machine_encoding);
shstrndx = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohs(tvb, offset) : tvb_get_letohs(tvb, offset);
program_header_tree = proto_tree_add_subtree_format(main_tree, tvb, value_guard(phoff),
phnum * phentsize, ett_elf_program_header, NULL, "Program Header Table [%d entries]", phnum);
section_header_tree = proto_tree_add_subtree_format(main_tree, tvb, value_guard(shoff),
shnum * shentsize, ett_elf_section_header, NULL, "Section Header Table [%d entries]", shnum);
file_size = ehsize + phnum * phentsize + shnum * shentsize;
segment_info = (segment_info_t *) wmem_alloc(wmem_packet_scope(), sizeof(segment_info_t) * (shnum + phnum + 3));
segment_info[area_counter].offset = 0;
segment_info[area_counter].size = ehsize;
segment_info[area_counter].name = "Header";
area_counter += 1;
if (phoff) {
segment_info[area_counter].offset = phoff;
segment_info[area_counter].size = phnum * phentsize;
segment_info[area_counter].name = "ProgramHeader";
area_counter += 1;
}
if (shoff) {
segment_info[area_counter].offset = shoff;
segment_info[area_counter].size = shnum * shentsize;
segment_info[area_counter].name = "SectionHeader";
area_counter += 1;
}
offset = value_guard(phoff);
i_16 = phnum;
while (i_16-- > 0) {
p_type = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
if (p_type >= 0x60000000 && p_type <= 0x6FFFFFFF) {
ph_entry_tree = proto_tree_add_subtree_format(program_header_tree, tvb, offset, phentsize, ett_elf_program_header, NULL,
"Entry #%d: Operating System Specific (0x%08x)", phnum - i_16 - 1, p_type);
proto_tree_add_item(ph_entry_tree, hf_elf_p_type_operating_system_specific, tvb, offset, 4, machine_encoding);
} else if (p_type >= 0x70000000 && p_type <= 0x7FFFFFFF) {
ph_entry_tree = proto_tree_add_subtree_format(program_header_tree, tvb, offset, phentsize, ett_elf_program_header, NULL,
"Entry #%d: Processor Specific (0x%08x)", phnum - i_16 - 1, p_type);
proto_tree_add_item(ph_entry_tree, hf_elf_p_type_processor_specific, tvb, offset, 4, machine_encoding);
} else {
ph_entry_tree = proto_tree_add_subtree_format(program_header_tree, tvb, offset, phentsize, ett_elf_program_header, NULL,
"Entry #%d: %s", phnum - i_16 - 1,
val_to_str_const(p_type, p_type_vals, "Unknown"));
proto_tree_add_item(ph_entry_tree, hf_elf_p_type, tvb, offset, 4, machine_encoding);
}
offset += 4;
if (register_size == REGISTER_64_SIZE) {
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_processor_specific, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_operating_system_specific, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_reserved, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_read, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_write, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_execute, tvb, offset, 4, machine_encoding);
offset += 4;
}
proto_tree_add_item(ph_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_p_offset : hf_elf64_p_offset,
tvb, offset, register_size, machine_encoding);
if (register_size == REGISTER_32_SIZE) {
p_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
} else {
p_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
}
offset += register_size;
proto_tree_add_item(ph_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_p_vaddr : hf_elf64_p_vaddr,
tvb, offset, register_size, machine_encoding);
offset += register_size;
proto_tree_add_item(ph_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_p_paddr : hf_elf64_p_paddr,
tvb, offset, register_size, machine_encoding);
offset += register_size;
proto_tree_add_item(ph_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_p_filesz : hf_elf64_p_filesz,
tvb, offset, register_size, machine_encoding);
if (register_size == REGISTER_32_SIZE) {
segment_size = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
} else {
segment_size = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
}
offset += register_size;
proto_tree_add_item(ph_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_p_memsz : hf_elf64_p_memsz,
tvb, offset, register_size, machine_encoding);
offset += register_size;
if (register_size == REGISTER_32_SIZE) {
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_processor_specific, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_operating_system_specific, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_reserved, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_read, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_write, tvb, offset, 4, machine_encoding);
proto_tree_add_item(ph_entry_tree, hf_elf_p_flags_execute, tvb, offset, 4, machine_encoding);
offset += 4;
}
proto_tree_add_item(ph_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_p_align : hf_elf64_p_align,
tvb, offset, register_size, machine_encoding);
offset += register_size;
if (segment_size) {
gchar *name;
name = wmem_strdup_printf(wmem_packet_scope(), "ProgramHeaderEntry #%u", phnum - i_16 - 1);
proto_tree_add_text(ph_entry_tree, tvb, value_guard(p_offset), value_guard(segment_size), "Segment");
file_size += segment_size;
segment_info[area_counter].offset = p_offset;
segment_info[area_counter].size = segment_size;
segment_info[area_counter].name = name;
area_counter += 1;
}
}
offset = value_guard(shoff);
i_16 = shnum;
while (i_16-- > 0) {
sh_name = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
offset += 4;
offset += 4;
length = shoff + shstrndx * shentsize + 2 * 4 + 2 * register_size;
if (register_size == REGISTER_32_SIZE) {
shstrtab_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, value_guard(length)) : tvb_get_letohl(tvb, value_guard(length));
} else {
shstrtab_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, value_guard(length)) : tvb_get_letoh64(tvb, value_guard(length));
}
section_name = tvb_get_const_stringz(tvb, value_guard(shstrtab_offset + sh_name), NULL);
if (register_size == REGISTER_64_SIZE && machine_encoding == ENC_BIG_ENDIAN) {
offset += 4;
}
offset += 4;
if (register_size == REGISTER_64_SIZE && machine_encoding == ENC_LITTLE_ENDIAN) {
offset += 4;
}
offset += register_size;
if (register_size == REGISTER_32_SIZE) {
segment_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
} else {
segment_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
}
if (g_strcmp0(section_name, ".strtab") == 0) {
strtab_offset = segment_offset;
} else if (g_strcmp0(section_name, ".dynstr") == 0) {
dynstr_offset = segment_offset;
}
offset += register_size;
offset += register_size;
offset += 4;
offset += 4;
offset += register_size;
offset += register_size;
}
offset = value_guard(shoff);
i_16 = shnum;
while (i_16-- > 0) {
sh_entry_tree = proto_tree_add_subtree_format(section_header_tree, tvb, offset, shentsize,
ett_elf_section_header, &sh_entry_item, "Entry #%d: ", shnum - i_16 - 1);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_name, tvb, offset, 4, machine_encoding);
sh_name = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
offset += 4;
sh_type = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
if (sh_type >= 0x60000000 && sh_type <= 0x6FFFFFFF) {
proto_item_append_text(sh_entry_item, "Operating System Specific (0x%08x)", sh_type);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_type_operating_system_specific, tvb, offset, 4, machine_encoding);
} else if (sh_type >= 0x70000000 && sh_type <= 0x7FFFFFFF) {
proto_item_append_text(sh_entry_item, "Processor Specific (0x%08x)", sh_type);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_type_processor_specific, tvb, offset, 4, machine_encoding);
} else if (sh_type >= 0x80000000 && sh_type <= 0xFFFFFFFF) {
proto_item_append_text(sh_entry_item, "User Specific (0x%08x)", sh_type);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_type_user_specific, tvb, offset, 4, machine_encoding);
}else {
proto_item_append_text(sh_entry_item, "%s", val_to_str_ext_const(sh_type, &sh_type_vals_ext, "Unknown"));
proto_tree_add_item(sh_entry_tree, hf_elf_sh_type, tvb, offset, 4, machine_encoding);
}
offset += 4;
length = shoff + shstrndx * shentsize + 2 * 4 + 2 * register_size;
if (register_size == REGISTER_32_SIZE) {
shstrtab_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, value_guard(length)) : tvb_get_letohl(tvb, value_guard(length));
} else {
shstrtab_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, value_guard(length)) : tvb_get_letoh64(tvb, value_guard(length));
}
section_name = tvb_get_const_stringz(tvb, value_guard(shstrtab_offset + sh_name), NULL);
if (section_name)
proto_item_append_text(sh_entry_item, ": %s", section_name);
if (register_size == REGISTER_64_SIZE && machine_encoding == ENC_BIG_ENDIAN) {
offset += 4;
}
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_processor_specific, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_operating_system_specific, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_reserved, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_tls, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_group, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_os_nonconforming, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_link_order, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_info_link, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_strings, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_merge, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_reserved_8, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_exec_instr, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_alloc, tvb, offset, 4, machine_encoding);
proto_tree_add_item(sh_entry_tree, hf_elf_sh_flags_write, tvb, offset, 4, machine_encoding);
offset += 4;
if (register_size == REGISTER_64_SIZE && machine_encoding == ENC_LITTLE_ENDIAN) {
offset += 4;
}
proto_tree_add_item(sh_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_sh_addr : hf_elf64_sh_addr,
tvb, offset, register_size, machine_encoding);
offset += register_size;
proto_tree_add_item(sh_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_sh_offset : hf_elf64_sh_offset,
tvb, offset, register_size, machine_encoding);
if (register_size == REGISTER_32_SIZE) {
segment_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
} else {
segment_offset = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
}
offset += register_size;
proto_tree_add_item(sh_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_sh_size : hf_elf64_sh_size,
tvb, offset, register_size, machine_encoding);
if (register_size == REGISTER_32_SIZE) {
segment_size = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
} else {
segment_size = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
}
offset += register_size;
proto_tree_add_item(sh_entry_tree, hf_elf_sh_link, tvb, offset, 4, machine_encoding);
offset += 4;
proto_tree_add_item(sh_entry_tree, hf_elf_sh_info, tvb, offset, 4, machine_encoding);
offset += 4;
proto_tree_add_item(sh_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_sh_addralign : hf_elf64_sh_addralign,
tvb, offset, register_size, machine_encoding);
offset += register_size;
proto_tree_add_item(sh_entry_tree,
(register_size == REGISTER_32_SIZE) ? hf_elf_sh_entsize : hf_elf64_sh_entsize,
tvb, offset, register_size, machine_encoding);
if (register_size == REGISTER_32_SIZE) {
sh_entsize = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntohl(tvb, offset) : tvb_get_letohl(tvb, offset);
} else {
sh_entsize = (machine_encoding == ENC_BIG_ENDIAN) ?
tvb_get_ntoh64(tvb, offset) : tvb_get_letoh64(tvb, offset);
}
offset += register_size;
if (segment_size > 0 && sh_type != 8) {
file_size += segment_size;
segment_info[area_counter].offset = segment_offset;
segment_info[area_counter].size = segment_size;
segment_info[area_counter].name = section_name;
area_counter += 1;
segment_tree = proto_tree_add_subtree(sh_entry_tree, tvb, value_guard(segment_offset),
value_guard(segment_size), ett_elf_segment, &segment_item, "Segment");
if (g_strcmp0(section_name, ".eh_frame") == 0) {
next_offset = dissect_eh_frame(tvb, pinfo, segment_tree,
value_guard(segment_offset), value_guard(segment_size), register_size,
machine_encoding);
if (next_offset != (gint) (segment_offset + segment_size))
expert_add_info(pinfo, segment_item, &ei_invalid_segment_size);
} else if (g_strcmp0(section_name, ".eh_frame_hdr") == 0) {
next_offset = dissect_eh_frame_hdr(tvb, pinfo, segment_tree,
value_guard(segment_offset), value_guard(segment_size), register_size,
machine_encoding);
if (next_offset != (gint) (segment_offset + segment_size))
expert_add_info(pinfo, segment_item, &ei_invalid_segment_size);
} else if (sh_type == 0x06) {
if (sh_entsize > 0) {
next_offset = value_guard(segment_offset);
for (i = 1; i < (segment_size / sh_entsize) + 1; i += 1) {
entry_tree = proto_tree_add_subtree_format(segment_tree, tvb, next_offset,
value_guard(sh_entsize), ett_symbol_table_entry, &entry_item, "Entry #%d", i);
next_offset = dissect_dynamic(tvb, pinfo, entry_tree, entry_item,
next_offset, register_size, machine_encoding);
if (next_offset != (gint) (segment_offset + i * sh_entsize))
expert_add_info(pinfo, segment_item, &ei_invalid_entry_size);
}
}
} else if (sh_type == 0x02 || sh_type == 0x0b) {
if (sh_entsize > 0) {
next_offset = value_guard(segment_offset);
for (i = 1; i < (segment_size / sh_entsize) + 1; i += 1) {
entry_tree = proto_tree_add_subtree_format(segment_tree, tvb, next_offset,
value_guard(sh_entsize), ett_symbol_table_entry, &entry_item, "Entry #%d", i);
next_offset = dissect_symbol_table(tvb, pinfo, entry_tree, entry_item,
next_offset, register_size, machine_encoding, (sh_type == 0x02) ? strtab_offset : dynstr_offset,
shoff, shnum, shentsize, shstrtab_offset);
if (next_offset != (gint) (segment_offset + i * sh_entsize))
expert_add_info(pinfo, segment_item, &ei_invalid_entry_size);
}
}
} else if (sh_type == 0x03) {
next_offset = value_guard(segment_offset);
i = 1;
while (next_offset < (gint) (segment_offset + segment_size)) {
tvb_get_const_stringz(tvb, next_offset, &len);
entry_item = proto_tree_add_item(segment_tree, hf_elf_string, tvb, next_offset, len, ENC_ASCII | ENC_NA);
proto_item_append_text(entry_item, " (Number: %u, Index: %u, Length: %u)", (guint) i, (guint) (next_offset - segment_offset), len - 1);
next_offset += len;
i += 1;
}
} else {
if (sh_entsize > 0) {
next_offset = value_guard(segment_offset);
for (i = 1; i < (segment_size / sh_entsize) + 1; i += 1) {
proto_tree_add_text(segment_tree, tvb, next_offset,
value_guard(sh_entsize), "Entry #%d ", i);
next_offset += value_guard(sh_entsize);
}
}
}
}
}
generated_tree = proto_tree_add_subtree(main_tree, tvb, 0, 0, ett_elf_info, &generated_item, "Infos");
PROTO_ITEM_SET_GENERATED(generated_item);
blackhole_tree = proto_tree_add_subtree(generated_tree, tvb, 0, 0, ett_elf_black_holes, NULL, "Backholes");
overlapping_tree = proto_tree_add_subtree(generated_tree, tvb, 0, 0, ett_elf_overlapping, NULL, "Overlapping");
for (i = 0; i < area_counter; i += 1) {
segment_info_t tmp_segment;
segment_info_t *min_offset_segment;
min_offset_segment = &segment_info[i];
for (i_next = i + 1; i_next < area_counter; i_next += 1) {
if (min_offset_segment->offset <= segment_info[i_next].offset) continue;
tmp_segment = *min_offset_segment;
*min_offset_segment = segment_info[i_next];
segment_info[i_next] = tmp_segment;
}
}
for (i = 1; i < area_counter; i += 1) {
if (segment_info[i - 1].offset + segment_info[i - 1].size < segment_info[i].offset) {
len = (guint) (segment_info[i].offset - segment_info[i - 1].offset - segment_info[i - 1].size);
proto_tree_add_text(blackhole_tree, tvb, value_guard(segment_info[i].offset - len), len, "Blackhole between: %s and %s, size: %u",
segment_info[i - 1].name, segment_info[i].name, len);
} else if (segment_info[i - 1].offset + segment_info[i - 1].size > segment_info[i].offset) {
len = (guint) (segment_info[i - 1].offset + segment_info[i - 1].size - segment_info[i].offset);
proto_tree_add_text(overlapping_tree, tvb, value_guard(segment_info[i - 1].offset + segment_info[i - 1].size - len), len, "Overlapping between: %s and %s, size: %u",
segment_info[i - 1].name, segment_info[i].name, len);
file_size -= len;
}
}
if (segment_info[area_counter - 1].offset + segment_info[area_counter - 1].size < tvb_length(tvb)) {
len = tvb_length(tvb) - (guint) (segment_info[area_counter - 1].offset - segment_info[area_counter - 1].size);
proto_tree_add_text(blackhole_tree, tvb,
value_guard(segment_info[area_counter - 1].offset +
segment_info[area_counter - 1].size),
len, "Blackhole between: %s and <EOF>, size: %u",
segment_info[area_counter - 1].name, len);
}
proto_tree_add_text(generated_tree, tvb, 0, 0, "File size: %i", tvb_length(tvb));
proto_tree_add_text(generated_tree, tvb, 0, 0, "Header size + all segment size: %i", (int) file_size);
proto_tree_add_text(generated_tree, tvb, 0, 0, "Total blackholes size: %i", tvb_length(tvb) - (int) file_size);
col_clear(pinfo->cinfo, COL_INFO);
col_add_str(pinfo->cinfo, COL_INFO, "(ELF)");
offset = tvb_length(tvb);
return offset;
}
static gboolean
dissect_elf_heur(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
return dissect_elf(tvb, pinfo, tree, NULL) > 0;
}
void
proto_register_elf(void)
{
module_t *module;
expert_module_t *expert_module;
static hf_register_info hf[] = {
{ &hf_elf_magic_bytes,
{ "Magic Bytes", "elf.magic_bytes",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_file_class,
{ "File Class", "elf.file_class",
FT_UINT8, BASE_HEX, VALS(class_vals), 0x00,
NULL, HFILL }
},
{ &hf_elf_data_encoding,
{ "Data Encoding", "elf.data_encoding",
FT_UINT8, BASE_HEX, VALS(data_encoding_vals), 0x00,
NULL, HFILL }
},
{ &hf_elf_file_version,
{ "File Version", "elf.file_version",
FT_UINT8, BASE_HEX, VALS(version_vals), 0x00,
NULL, HFILL }
},
{ &hf_elf_os_abi,
{ "OS ABI", "elf.os_abi",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &os_abi_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_elf_abi_version,
{ "ABI Version", "elf.abi_version",
FT_UINT8, BASE_HEX_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_file_padding,
{ "File Padding", "elf.file_padding",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_type,
{ "Type", "elf.type",
FT_UINT16, BASE_HEX, VALS(type_vals), 0x00,
NULL, HFILL }
},
{ &hf_elf_machine,
{ "Machine", "elf.machine",
FT_UINT16, BASE_HEX | BASE_EXT_STRING, &machine_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_elf_version,
{ "Version", "elf.version",
FT_UINT32, BASE_HEX, VALS(version_vals), 0x00,
NULL, HFILL }
},
{ &hf_elf_entry,
{ "Entry", "elf.entry",
FT_UINT32, BASE_HEX, NULL, 0x00,
"This member gives the virtual address to which the system first transfers control, thus starting the process. If the file has no associated entry point, this member holds zero. ", HFILL }
},
{ &hf_elf64_entry,
{ "Entry", "elf.entry",
FT_UINT64, BASE_HEX, NULL, 0x00,
"This member gives the virtual address to which the system first transfers control, thus starting the process. If the file has no associated entry point, this member holds zero. ", HFILL }
},
{ &hf_elf_phoff,
{ "Program Header Table File Offset", "elf.phoff",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member holds the program header table's file offset in bytes. If the file has no program header table, this member holds zero.", HFILL }
},
{ &hf_elf64_phoff,
{ "Program Header Table File Offset", "elf.phoff",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"This member holds the program header table's file offset in bytes. If the file has no program header table, this member holds zero.", HFILL }
},
{ &hf_elf_shoff,
{ "Section Header Table File Offset", "elf.shoff",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member holds the section header table's file offset in bytes. If the file has no section header table, this member holds zero.", HFILL }
},
{ &hf_elf64_shoff,
{ "Section Header Table File Offset", "elf.shoff",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"This member holds the section header table's file offset in bytes. If the file has no section header table, this member holds zero.", HFILL }
},
{ &hf_elf_flags,
{ "Flags", "elf.flags",
FT_UINT32, BASE_HEX, NULL, 0x00,
"This member holds processor-specific flags associated with the file. Flag names take the form EF_machine_flag.", HFILL }
},
{ &hf_elf_ehsize,
{ "ELF Header Size", "elf.ehsize",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
"This member holds the ELF header's size in bytes.", HFILL }
},
{ &hf_elf_phentsize,
{ "Entry Size in Program Header Table", "elf.phentsize",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
"This member holds the size in bytes of one entry in the file's program header table; all entries are the same size.", HFILL }
},
{ &hf_elf_phnum,
{ "Number of Entries in the Program Header Table", "elf.phnum",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
"This member holds the number of entries in the program header table. Thus the product of e_phentsize and e_phnum gives the table's size in bytes. If a file has no program header table, e_phnum holds the value zero.", HFILL }
},
{ &hf_elf_shentsize,
{ "Entry Size in Section Header Table", "elf.shentsize",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
"This member holds a section header's size in bytes. A section header is one entry in the section header table; all entries are the same size.", HFILL }
},
{ &hf_elf_shnum,
{ "Number of Entries in the Section Header Table", "elf.shnum",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
"This member holds the number of entries in the section header table. Thus the product of e_shentsize and e_shnum gives the section header table's size in bytes. If a file has no section header table, e_shnum holds the value zero.", HFILL }
},
{ &hf_elf_shstrndx,
{ "Section Header Table String Index", "elf.shstrndx",
FT_UINT16, BASE_DEC_HEX, NULL, 0x00,
"This member holds the section header table index of the entry associated with the section name string table. If the file has no section name string table, this member holds the value SHN_UNDEF.", HFILL }
},
{ &hf_elf_p_type,
{ "Element Type", "elf.p_type",
FT_UINT32, BASE_HEX_DEC, VALS(p_type_vals), 0x00,
"This member tells what kind of segment this array element describes or how to interpret the array element's information.", HFILL }
},
{ &hf_elf_p_type_operating_system_specific,
{ "Element Type: Operating System Specific", "elf.p_type",
FT_UINT32, BASE_HEX_DEC, NULL, 0x00,
"This member tells what kind of segment this array element describes or how to interpret the array element's information.", HFILL }
},
{ &hf_elf_p_type_processor_specific,
{ "Element Type: Processor Specific", "elf.p_type",
FT_UINT32, BASE_HEX_DEC, NULL, 0x00,
"This member tells what kind of segment this array element describes or how to interpret the array element's information.", HFILL }
},
{ &hf_elf_p_offset,
{ "File Offset", "elf.p_offset",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member gives the offset from the beginning of the file at which the first byte of the segment resides.", HFILL }
},
{ &hf_elf64_p_offset,
{ "File Offset", "elf.p_offset",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"This member gives the offset from the beginning of the file at which the first byte of the segment resides.", HFILL }
},
{ &hf_elf_p_vaddr,
{ "Virtual Address", "elf.p_vaddr",
FT_UINT32, BASE_HEX, NULL, 0x00,
"This member gives the virtual address at which the first byte of the segment resides in memory.", HFILL }
},
{ &hf_elf64_p_vaddr,
{ "Virtual Address", "elf.p_vaddr",
FT_UINT64, BASE_HEX, NULL, 0x00,
"This member gives the virtual address at which the first byte of the segment resides in memory.", HFILL }
},
{ &hf_elf_p_paddr,
{ "Physical Address", "elf.p_paddr",
FT_UINT32, BASE_HEX, NULL, 0x00,
"On systems for which physical addressing is relevant, this member is reserved for the segment's physical address. Because System V ignores physical addressing for application programs, this member has unspecified contents for executable files and shared objects.", HFILL }
},
{ &hf_elf64_p_paddr,
{ "Physical Address", "elf.p_paddr",
FT_UINT64, BASE_HEX, NULL, 0x00,
"On systems for which physical addressing is relevant, this member is reserved for the segment's physical address. Because System V ignores physical addressing for application programs, this member has unspecified contents for executable files and shared objects.", HFILL }
},
{ &hf_elf_p_filesz,
{ "File Image Size", "elf.p_filesz",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member gives the number of bytes in the file image of the segment; it may be zero.", HFILL }
},
{ &hf_elf64_p_filesz,
{ "File Image Size", "elf.p_filesz",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"This member gives the number of bytes in the file image of the segment; it may be zero.", HFILL }
},
{ &hf_elf_p_memsz,
{ "Memory Image Size", "elf.p_memsz",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member gives the number of bytes in the memory image of the segment; it may be zero.", HFILL }
},
{ &hf_elf64_p_memsz,
{ "Memory Image Size", "elf.p_memsz",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"This member gives the number of bytes in the memory image of the segment; it may be zero.", HFILL }
},
{ &hf_elf_p_flags_processor_specific,
{ "Processor Specific Flags", "elf.p_flags.maskproc",
FT_BOOLEAN, 32, NULL, 0xF0000000,
NULL, HFILL }
},
{ &hf_elf_p_flags_operating_system_specific,
{ "Operating System Specific Flags", "elf.p_flags.maskos",
FT_BOOLEAN, 32, NULL, 0x0FF00000,
NULL, HFILL }
},
{ &hf_elf_p_flags_reserved,
{ "Reserrved Flags", "elf.p_flags.reserved",
FT_BOOLEAN, 32, NULL, 0x000FFFF8,
NULL, HFILL }
},
{ &hf_elf_p_flags_read,
{ "Read Flag", "elf.p_flags.read",
FT_BOOLEAN, 32, NULL, 0x00000004,
NULL, HFILL }
},
{ &hf_elf_p_flags_write,
{ "Write Flag", "elf.p_flags.write",
FT_BOOLEAN, 32, NULL, 0x00000002,
NULL, HFILL }
},
{ &hf_elf_p_flags_execute,
{ "Execute Flag", "elf.p_flags.execute",
FT_BOOLEAN, 32, NULL, 0x00000001,
NULL, HFILL }
},
{ &hf_elf_p_align,
{ "Align", "elf.p_align",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member gives the value to which the segments are aligned in memory and in the file. Values 0 and 1 mean no alignment is required. Otherwise, p_align should be a positive, integral power of 2, and p_vaddr should equal p_offset, modulo p_align.", HFILL }
},
{ &hf_elf64_p_align,
{ "Align", "elf.p_align",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"This member gives the value to which the segments are aligned in memory and in the file. Values 0 and 1 mean no alignment is required. Otherwise, p_align should be a positive, integral power of 2, and p_vaddr should equal p_offset, modulo p_align.", HFILL }
},
{ &hf_elf_sh_name,
{ "Name Index", "elf.sh_name",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"Section Name. Its value is an index into the section header string table section, giving the location of a null-terminated string.", HFILL }
},
{ &hf_elf_sh_type,
{ "Type", "elf.sh_type",
FT_UINT32, BASE_HEX_DEC | BASE_EXT_STRING, &sh_type_vals_ext, 0x00,
"This member categorizes the section's contents and semantics.", HFILL }
},
{ &hf_elf_sh_type_operating_system_specific,
{ "Type: Operating System Specific", "elf.sh_type",
FT_UINT32, BASE_HEX_DEC, NULL, 0x00,
"This member categorizes the section's contents and semantics.", HFILL }
},
{ &hf_elf_sh_type_processor_specific,
{ "Type: Procesor Specific", "elf.sh_type",
FT_UINT32, BASE_HEX_DEC, NULL, 0x00,
"This member categorizes the section's contents and semantics.", HFILL }
},
{ &hf_elf_sh_type_user_specific,
{ "Type: User Specific", "elf.sh_type",
FT_UINT32, BASE_HEX_DEC, NULL, 0x00,
"This member categorizes the section's contents and semantics.", HFILL }
},
{ &hf_elf_sh_flags_processor_specific,
{ "Processor Specific Flags", "elf.sh_flags.maskproc",
FT_BOOLEAN, 32, NULL, 0xF0000000,
NULL, HFILL }
},
{ &hf_elf_sh_flags_operating_system_specific,
{ "Operating System Specific Flags", "elf.sh_flags.maskos",
FT_BOOLEAN, 32, NULL, 0x0FF00000,
NULL, HFILL }
},
{ &hf_elf_sh_flags_reserved,
{ "Reserved", "elf.sh_flags.reserved",
FT_BOOLEAN, 32, NULL, 0x000FF800,
NULL, HFILL }
},
{ &hf_elf_sh_flags_tls,
{ "TLS Flag", "elf.sh_flags.tls",
FT_BOOLEAN, 32, NULL, 0x00000400,
"This section holds Thread-Local Storage, meaning that each separate execution flow has its own distinct instance of this data. Implementations need not support this flag.", HFILL }
},
{ &hf_elf_sh_flags_group,
{ "Group Flag", "elf.sh_flags.group",
FT_BOOLEAN, 32, NULL, 0x00000200,
"This section is a member (perhaps the only one) of a section group.", HFILL }
},
{ &hf_elf_sh_flags_os_nonconforming,
{ "OS NonConforming Flag", "elf.sh_flags.os_nonconforming",
FT_BOOLEAN, 32, NULL, 0x00000100,
"This section requires special OS-specific processing to avoid incorrect behavior.", HFILL }
},
{ &hf_elf_sh_flags_link_order,
{ "Link Order Flag", "elf.sh_flags.link_order",
FT_BOOLEAN, 32, NULL, 0x00000080,
"This flag adds special ordering requirements for link editors.", HFILL }
},
{ &hf_elf_sh_flags_info_link,
{ "Info Link Flag", "elf.sh_flags.info_link",
FT_BOOLEAN, 32, NULL, 0x00000040,
"The sh_info field of this section header holds a section header table index.", HFILL }
},
{ &hf_elf_sh_flags_strings,
{ "Strings Flag", "elf.sh_flags.strings",
FT_BOOLEAN, 32, NULL, 0x00000020,
"The data elements in the section consist of null-terminated character strings. The size of each character is specified in the section header's sh_entsize field.", HFILL }
},
{ &hf_elf_sh_flags_merge,
{ "Merge Flag", "elf.sh_flags.merge",
FT_BOOLEAN, 32, NULL, 0x00000010,
"The data in the section may be merged to eliminate duplication.", HFILL }
},
{ &hf_elf_sh_flags_reserved_8,
{ "Reserved", "elf.sh_flags.reserved.8",
FT_BOOLEAN, 32, NULL, 0x00000008,
NULL, HFILL }
},
{ &hf_elf_sh_flags_exec_instr,
{ "Exec Instr Flag", "elf.sh_flags.exec_instr",
FT_BOOLEAN, 32, NULL, 0x00000004,
"The section contains executable machine instructions.", HFILL }
},
{ &hf_elf_sh_flags_alloc,
{ "Alloc Flag", "elf.sh_flags.alloc",
FT_BOOLEAN, 32, NULL, 0x00000002,
"The section occupies memory during process execution. Some control sections do not reside in the memory image of an object file; this attribute is off for those sections.", HFILL }
},
{ &hf_elf_sh_flags_write,
{ "Write Flag", "elf.sh_flags.write",
FT_BOOLEAN, 32, NULL, 0x00000001,
"The section contains data that should be writable during process execution.", HFILL }
},
{ &hf_elf_sh_addr,
{ "Address", "elf.sh_addr",
FT_UINT32, BASE_HEX, NULL, 0x00,
"If the section will appear in the memory image of a process, this member gives the address at which the section's first byte should reside. Otherwise, the member contains 0.", HFILL }
},
{ &hf_elf64_sh_addr,
{ "Address", "elf.sh_addr",
FT_UINT64, BASE_HEX, NULL, 0x00,
"If the section will appear in the memory image of a process, this member gives the address at which the section's first byte should reside. Otherwise, the member contains 0.", HFILL }
},
{ &hf_elf_sh_offset,
{ "File Offset", "elf.sh_offset",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member's value gives the byte offset from the beginning of the file to the first byte in the section. One section type, SHT_NOBITS, occupies no space in the file, and its sh_offset member locates the conceptual placement in the file.", HFILL }
},
{ &hf_elf64_sh_offset,
{ "File Offset", "elf.sh_offset",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"This member's value gives the byte offset from the beginning of the file to the first byte in the section. One section type, SHT_NOBITS, occupies no space in the file, and its sh_offset member locates the conceptual placement in the file.", HFILL }
},
{ &hf_elf_sh_size,
{ "Size", "elf.sh_size",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member gives the section's size in bytes.", HFILL }
},
{ &hf_elf64_sh_size,
{ "Size", "elf.sh_size",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"This member gives the section's size in bytes.", HFILL }
},
{ &hf_elf_sh_link,
{ "Link Index", "elf.sh_link",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member holds a section header table index link, whose interpretation depends on the section type.", HFILL }
},
{ &hf_elf_sh_info,
{ "Info", "elf.sh_info",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"This member holds extra information, whose interpretation depends on the section type.", HFILL }
},
{ &hf_elf_sh_addralign,
{ "Address Alignment", "elf.sh_addralign",
FT_UINT32, BASE_HEX, NULL, 0x00,
"Some sections have address alignment constraints. Currently, only 0 and positive integral powers of two are allowed. Values 0 and 1 mean the section has no alignment constraints.", HFILL }
},
{ &hf_elf64_sh_addralign,
{ "Address Alignment", "elf.sh_addralign",
FT_UINT64, BASE_HEX, NULL, 0x00,
"Some sections have address alignment constraints. Currently, only 0 and positive integral powers of two are allowed. Values 0 and 1 mean the section has no alignment constraints.", HFILL }
},
{ &hf_elf_sh_entsize,
{ "Entry Size", "elf.sh_entsize",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"Some sections hold a table of fixed-size entries, such as a symbol table. For such a section, this member gives the size in bytes of each entry. The member contains 0 if the section does not hold a table of fixed-size entries.", HFILL }
},
{ &hf_elf64_sh_entsize,
{ "Entry Size", "elf.sh_entsize",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"Some sections hold a table of fixed-size entries, such as a symbol table. For such a section, this member gives the size in bytes of each entry. The member contains 0 if the section does not hold a table of fixed-size entries.", HFILL }
},
{ &hf_elf_eh_frame_length,
{ "Length", "elf.eh_frame.length",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"A 4 byte unsigned value indicating the length in bytes of the CIE structure, not including the Length field itself. If Length contains the value 0xffffffff, then the length is contained in the Extended Length field. If Length contains the value 0, then this CIE shall be considered a terminator and processing shall end.", HFILL }
},
{ &hf_elf_eh_frame_extended_length,
{ "Length", "elf.eh_frame.length",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"A 4 byte unsigned value indicating the length in bytes of the CIE structure, not including the Length field itself. If Length contains the value 0xffffffff, then the length is contained in the Extended Length field. If Length contains the value 0, then this CIE shall be considered a terminator and processing shall end.", HFILL }
},
{ &hf_elf_eh_frame_cie_id,
{ "CIE ID", "elf.eh_frame.cie_id",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"A 4 byte unsigned value that is used to distinguish CIE records from FDE records. This value shall always be 0, which indicates this record is a CIE.", HFILL }
},
{ &hf_elf_eh_frame_version,
{ "Version", "elf.eh_frame.version",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00,
"A 1 byte value that identifies the version number of the frame information structure. This value shall be 1.", HFILL }
},
{ &hf_elf_eh_frame_augmentation_string,
{ "Augmentation String", "elf.eh_frame.version",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
"This value is a NUL terminated string that identifies the augmentation to the CIE or to the FDEs associated with this CIE. A zero length string indicates that no augmentation data is present. The augmentation string is case sensitive.", HFILL }
},
{ &hf_elf_eh_frame_code_alignment_factor,
{ "Code Alignment Factor", "elf.eh_frame.code_alignment_factor",
FT_UINT64, BASE_DEC, NULL, 0x00,
"An unsigned LEB128 encoded value that is factored out of all advance location instructions that are associated with this CIE or its FDEs. This value shall be multiplied by the delta argument of an adavance location instruction to obtain the new location value.", HFILL }
},
{ &hf_elf_eh_frame_data_alignment_factor,
{ "Data Alignment Factor", "elf.eh_frame.data_alignment_factor",
FT_INT64, BASE_DEC, NULL, 0x00,
"A signed LEB128 encoded value that is factored out of all offset instructions that are associated with this CIE or its FDEs. This value shall be multiplied by the register offset argument of an offset instruction to obtain the new offset value.", HFILL }
},
{ &hf_elf_eh_frame_return_address_register,
{ "Return Address Register", "elf.eh_frame.return_address_register",
FT_UINT64, BASE_DEC, NULL, 0x00,
"An unsigned LEB128 constant that indicates which column in the rule table represents the return address of the function. Note that this column might not correspond to an actual machine register.", HFILL }
},
{ &hf_elf_eh_frame_augmentation_length,
{ "Augmentation Length", "elf.eh_frame.augmentation_length",
FT_UINT64, BASE_DEC, NULL, 0x00,
"An unsigned LEB128 encoded value indicating the length in bytes of the Augmentation Data. This field is only present if the Augmentation String contains the character 'z'.", HFILL }
},
{ &hf_elf_eh_frame_augmentation_data,
{ "Augmentation Data", "elf.eh_frame.augmentation_data",
FT_BYTES, BASE_NONE, NULL, 0x00,
"A block of data whose contents are defined by the contents of the Augmentation String as described below. This field is only present if the Augmentation String contains the character 'z'.", HFILL }
},
{ &hf_elf_eh_frame_initial_instructions,
{ "Initial Instructions", "elf.eh_frame.initial_instructions",
FT_BYTES, BASE_NONE, NULL, 0x00,
"Initial set of Call Frame Instructions.", HFILL }
},
{ &hf_elf_eh_frame_fde_length,
{ "Length", "elf.eh_frame.fde.length",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"A 4 byte unsigned value indicating the length in bytes of the CIE structure, not including the Length field itself. If Length contains the value 0xffffffff, then the length is contained in the Extended Length field. If Length contains the value 0, then this CIE shall be considered a terminator and processing shall end.", HFILL }
},
{ &hf_elf_eh_frame_fde_extended_length,
{ "Length", "elf.eh_frame.fde.length",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
"A 4 byte unsigned value indicating the length in bytes of the CIE structure, not including the Length field itself. If Length contains the value 0xffffffff, then the length is contained in the Extended Length field. If Length contains the value 0, then this CIE shall be considered a terminator and processing shall end.", HFILL }
},
{ &hf_elf_eh_frame_fde_cie_pointer,
{ "CIE Pointer", "elf.eh_frame.fde.cie_pointer",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"A 4 byte unsigned value that when subtracted from the offset of the the CIE Pointer in the current FDE yields the offset of the start of the associated CIE. This value shall never be 0.", HFILL }
},
{ &hf_elf_eh_frame_fde_pc_begin,
{ "PC Begin", "elf.eh_frame.fde.pc_begin",
FT_UINT32, BASE_HEX, NULL, 0x00,
"An encoded value that indicates the address of the initial location associated with this FDE. The encoding format is specified in the Augmentation Data.", HFILL }
},
{ &hf_elf_eh_frame_fde_pc_range,
{ "PC Range", "elf.eh_frame.fde.pc_range",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
"An absolute value that indicates the number of bytes of instructions associated with this FDE.", HFILL }
},
{ &hf_elf_eh_frame_fde_augmentation_length,
{ "Augmentation Length", "elf.eh_frame.fde.augmentation_length",
FT_UINT64, BASE_DEC, NULL, 0x00,
"An unsigned LEB128 encoded value indicating the length in bytes of the Augmentation Data. This field is only present if the Augmentation String in the associated CIE contains the character 'z'.", HFILL }
},
{ &hf_elf_eh_frame_fde_augmentation_data,
{ "Augmentation Data", "elf.eh_frame.fde.augmentation_data",
FT_BYTES, BASE_NONE, NULL, 0x00,
"A block of data whose contents are defined by the contents of the Augmentation String in the associated CIE as described above. This field is only present if the Augmentation String in the associated CIE contains the character 'z'. The size of this data is given by the Augentation Length.", HFILL }
},
{ &hf_elf_eh_frame_fde_call_frame_instructions,
{ "Call Frame Instructions", "elf.eh_frame.fde.call_frame_instructions",
FT_BYTES, BASE_NONE, NULL, 0x00,
"A set of Call Frame Instructions.", HFILL }
},
{ &hf_elf_eh_frame_hdr_version,
{ "Version", "elf.eh_frame_hdr.version",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00,
"Version of the .eh_frame_hdr format. This value shall be 1.", HFILL }
},
{ &hf_elf_eh_frame_hdr_exception_frame_pointer_encoding,
{ "Exeption Frame Pointer Encoding", "elf.eh_frame_hdr.eh_frame_ptr_enc",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00,
"The encoding format of the eh_frame_ptr field.", HFILL }
},
{ &hf_elf_eh_frame_hdr_fde_count_encoding,
{ "FDE Count Encoding", "elf.eh_frame_hdr.fde_count_enc",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00,
"The encoding format of the fde_count field. A value of DW_EH_PE_omit indicates the binary search table is not present.", HFILL }
},
{ &hf_elf_eh_frame_hdr_binary_search_table_encoding,
{ "Binary Search Table Encoding", "elf.eh_frame_hdr.binary_search_table_encoding",
FT_UINT8, BASE_DEC_HEX, NULL, 0x00,
"The encoding format of the entries in the binary search table. A value of DW_EH_PE_omit indicates the binary search table is not present.", HFILL }
},
{ &hf_elf_eh_frame_hdr_eh_frame_ptr,
{ "Exeption Frame Pointer", "elf.eh_frame_hdr.eh_frame_ptr",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_eh_frame_hdr_fde_count,
{ "FDE Count", "elf.eh_frame_hdr.fde_count",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_eh_frame_hdr_binary_search_table_entry_initial_location,
{ "Initial location", "elf.eh_frame_hdr.binary_search_table_entry.initial_location",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_eh_frame_hdr_binary_search_table_entry_address,
{ "Address", "elf.eh_frame_hdr.binary_search_table_entry.address",
FT_BYTES, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_symbol_table_name_index,
{ "Name Index", "elf.symbol_table.name_index",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_symbol_table_info,
{ "Info", "elf.symbol_table.info",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_symbol_table_info_bind,
{ "Bind", "elf.symbol_table.info.bind",
FT_UINT8, BASE_HEX, VALS(symbol_table_info_bind_vals), 0xF0,
NULL, HFILL }
},
{ &hf_elf_symbol_table_info_type,
{ "Type", "elf.symbol_table.info.type",
FT_UINT8, BASE_HEX | BASE_EXT_STRING, &symbol_table_info_type_vals_ext, 0x0F,
NULL, HFILL }
},
{ &hf_elf_symbol_table_other,
{ "Other", "elf.symbol_table.other",
FT_UINT8, BASE_HEX, VALS(symbol_table_other_vals), 0x00,
NULL, HFILL }
},
{ &hf_elf_symbol_table_shndx,
{ "Releated Section Header Index", "elf.symbol_table.shndx",
FT_UINT16, BASE_HEX | BASE_RANGE_STRING, RVALS(symbol_table_shndx_rvals), 0x00,
NULL, HFILL }
},
{ &hf_elf_symbol_table_value,
{ "Value", "elf.symbol_table.value",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf64_symbol_table_value,
{ "Value", "elf.symbol_table.value",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_symbol_table_size,
{ "Size", "elf.symbol_table.size",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf64_symbol_table_size,
{ "Size", "elf.symbol_table.size",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_dynamic_tag,
{ "Tag", "elf.dynamic.tag",
FT_UINT32, BASE_HEX | BASE_RANGE_STRING, RVALS(dynamic_tag_rvals), 0x00,
NULL, HFILL }
},
{ &hf_elf_dynamic_value,
{ "Value", "elf.dynamic.value",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_dynamic_pointer,
{ "Pointer", "elf.dynamic.pointer",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_dynamic_ignored,
{ "Ignored", "elf.dynamic.ignored",
FT_UINT32, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf_dynamic_unspecified,
{ "Unspecified", "elf.dynamic.unspecified",
FT_UINT32, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf64_dynamic_tag,
{ "Tag", "elf.dynamic.tag",
FT_UINT64, BASE_HEX , NULL , 0x00,
NULL, HFILL }
},
{ &hf_elf64_dynamic_value,
{ "Value", "elf.dynamic.value",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf64_dynamic_pointer,
{ "Pointer", "elf.dynamic.pointer",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf64_dynamic_ignored,
{ "Ignored", "elf.dynamic.ignored",
FT_UINT64, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_elf64_dynamic_unspecified,
{ "Unspecified", "elf.dynamic.unspecified",
FT_UINT64, BASE_DEC_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_dwarf_omit,
{ "DW_EH_PE_omit", "elf.dwarf.omit",
FT_UINT8, BASE_HEX, NULL, 0x00,
"Used to indicate that no value is present.", HFILL }
},
{ &hf_dwarf_upper,
{ "DWARF Exception Header application", "elf.dwarf.upper",
FT_UINT8, BASE_HEX, VALS(eh_dwarf_upper), 0xF0,
"The upper 4 bits indicate how the value is to be applied.", HFILL }
},
{ &hf_dwarf_format,
{ "DWARF Exception Header value format", "elf.dwarf.format",
FT_UINT8, BASE_HEX, VALS(eh_dwarf_format), 0x0F,
"The lower 4 bits indicate the format of the data.", HFILL }
},
{ &hf_elf_string,
{ "String", "elf.string",
FT_STRINGZ, BASE_NONE, NULL, 0x00,
NULL, HFILL }
}
};
static ei_register_info ei[] = {
{ &ei_invalid_segment_size, { "elf.invalid_segment_size", PI_PROTOCOL, PI_WARN, "Segment size is different then currently parsed bytes", EXPFILL }},
{ &ei_invalid_entry_size, { "elf.invalid_entry_size", PI_PROTOCOL, PI_WARN, "Entry size is different then currently parsed bytes", EXPFILL }},
};
static gint *ett[] = {
&ett_elf,
&ett_elf_header,
&ett_elf_program_header,
&ett_elf_section_header,
&ett_elf_segment,
&ett_elf_cie,
&ett_elf_fde,
&ett_elf_entry,
&ett_elf_info,
&ett_elf_black_holes,
&ett_elf_overlapping,
&ett_dwarf_encoding,
&ett_binary_table,
&ett_binary_table_entry,
&ett_symbol_table_entry,
&ett_symbol_table_info
};
proto_elf = proto_register_protocol("Executable and Linkable Format", "ELF", "elf");
proto_register_field_array(proto_elf, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
elf_handle = new_register_dissector("elf", dissect_elf, proto_elf);
module = prefs_register_protocol(proto_elf, NULL);
prefs_register_static_text_preference(module, "version",
"ELF version: 4.1 DRAFT",
"Version of file-format supported by this dissector.");
expert_module = expert_register_protocol(proto_elf);
expert_register_field_array(expert_module, ei, array_length(ei));
}
void
proto_reg_handoff_elf(void)
{
dissector_add_string("media_type", "application/x-executable", elf_handle);
dissector_add_string("media_type", "application/x-coredump", elf_handle);
dissector_add_string("media_type", "application/x-object", elf_handle);
dissector_add_string("media_type", "application/x-sharedlib", elf_handle);
dissector_add_uint("ftap_encap", 1234, elf_handle);
heur_dissector_add("wtap_file", dissect_elf_heur, proto_elf);
}
