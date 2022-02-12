static gboolean gsm_rr_csn_flag(tvbuff_t *tvb, proto_tree *tree, gint bit_offset, const char *description, const char *true_string, const char * false_string)
{
guint8 bit_mask = 0x80 >> (bit_offset % 8);
guint8 value = tvb_get_guint8(tvb, bit_offset >> 3);
guint8 offset_in_octet = bit_offset % 8;
char bits_str[] = {".... ...."};
if (value & bit_mask)
{
bits_str[offset_in_octet + (offset_in_octet / 4)] = '1';
proto_tree_add_text(tree, tvb, bit_offset>>3, 1, "%s: %s: %s", bits_str, description, true_string);
return TRUE;
}
bits_str[offset_in_octet + (offset_in_octet / 4)] = '0';
proto_tree_add_text(tree, tvb, bit_offset>>3, 1, "%s: %s: %s", bits_str, description, false_string);
return FALSE;
}
static gboolean gsm_rr_csn_HL_flag(tvbuff_t *tvb, proto_tree *tree, guint truncation_length, guint bit_offset, const char *description, const char *true_string, const char * false_string)
{
guint8 bit_mask = 0x80 >> (bit_offset % 8);
guint8 value = PADDING_BYTE;
char bits_str[] = {".... ...."};
guint8 offset_in_octet = bit_offset % 8;
if (truncation_length)
{
if (bit_offset < truncation_length)
{
value = tvb_get_guint8(tvb, bit_offset >> 3)^PADDING_BYTE;
}
else
{
proto_tree_add_text(tree, tvb, truncation_length>>3, 1, "(implicit L bit): %s: %s", description, false_string);
return FALSE;
}
}
else
{
value = tvb_get_guint8(tvb, bit_offset >> 3)^PADDING_BYTE;
}
if (value & bit_mask)
{
bits_str[offset_in_octet + (offset_in_octet / 4)] = 'H';
proto_tree_add_text(tree, tvb, bit_offset>>3, 1, "%s: %s: %s", bits_str, description, true_string);
return TRUE;
}
bits_str[offset_in_octet + (offset_in_octet / 4)] = 'L';
proto_tree_add_text(tree, tvb, bit_offset>>3, 1, "%s: %s: %s", bits_str, description, false_string);
return FALSE;
}
static guint16
de_rr_ba_range(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
guint8 value;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_range_nb, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
value = tvb_get_guint8(tvb, curr_offset);
curr_offset += 1;
bit_offset = curr_offset << 3;
while (value)
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_range_lower, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset += 10;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_range_higher, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset += 10;
value -= 1;
}
curr_offset += len - 1;
return (curr_offset - offset);
}
static void display_channel_list(guint8 *list, tvbuff_t *tvb, proto_tree *tree, guint32 offset, guint len)
{
int arfcn;
proto_item *ti = NULL;
ti = proto_tree_add_text(tree, tvb, offset, len, "List of ARFCNs =");
for (arfcn=0; arfcn<ARFCN_MAX; arfcn++) {
if (list[arfcn])
proto_item_append_text(ti, " %d", arfcn);
}
return;
}
static void gsm_rr_csn_padding_bits(proto_tree* tree, tvbuff_t* tvb, guint16 bit_offset, guint8 octet_len)
{
guint i;
gboolean non_padding_found = FALSE;
guint8 octet_offset = bit_offset >> 3;
if ((octet_len << 3) > bit_offset)
{
guint8 bit_mask = 0xFF >> (bit_offset & 0x07);
if ((tvb_get_guint8(tvb, octet_offset) & bit_mask) != (PADDING_BYTE & bit_mask))
{
non_padding_found = TRUE;
}
else
{
for (i=octet_offset+1; (i<octet_len) && !non_padding_found; i++)
{
if (tvb_get_guint8(tvb, i) != PADDING_BYTE)
non_padding_found = TRUE;
}
}
if (non_padding_found)
{
proto_tree_add_text(tree, tvb, octet_offset, -1,"Padding Bits: Unknown extension detected or malformed PDU (Not decoded)");
}
else
{
proto_tree_add_text(tree, tvb, octet_offset, -1,"Padding Bits: default padding");
}
}
else
{
proto_tree_add_text(tree, tvb, 0, 0,"No space for padding bits");
}
}
static gint greatest_power_of_2_lesser_or_equal_to(gint idx)
{
gint j = 1;
do {
j <<= 1;
} while (j <= idx);
j >>= 1;
return j;
}
gint f_k(gint k, gint *w, gint range)
{
gint idx, n, j;
idx = k;
range -= 1;
range = range/greatest_power_of_2_lesser_or_equal_to(idx);
n = w[idx]-1;
while (idx>1) {
j = greatest_power_of_2_lesser_or_equal_to(idx);
range = 2*range+1;
if ((2*idx) < 3*j){
idx -= j/2;
n = (n+w[idx]-1+((range-1)/2)+1)%range;
}
else {
idx -= j;
n = (n+w[idx]-1+1)%range;
}
}
return (n+1)%1024;
}
static void dissect_channel_list_n_range(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gint range)
{
gint curr_offset = offset, bit_offset, f0, arfcn_orig, w[64], wsize, i;
gint octet, nwi = 1, jwi=0, imax, iused, arfcn;
guint8 list[1024];
proto_item *item;
proto_tree *subtree;
memset((void*)list,0,sizeof(list));
item = proto_tree_add_text(tree,tvb, curr_offset, len, "Range %d format", range);
subtree = proto_item_add_subtree(item, ett_gsm_rr_elem[DE_RR_NEIGH_CELL_DESC]);
octet = tvb_get_guint8(tvb, curr_offset);
if (range == 1024) {
f0 = (octet>>2)&1;
if (f0)
list[0] = 1;
arfcn_orig = 0;
wsize = 10;
imax = 16;
bit_offset = curr_offset*8 + 6;
}
else {
bit_offset = curr_offset*8 + 7;
arfcn_orig = (gint) tvb_get_bits(tvb, bit_offset, 10, FALSE);
proto_tree_add_bits_item(subtree, hf_n_range_orig_arfcn, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset+=10;
list[arfcn_orig] = 1;
switch (range) {
case 512:
wsize=9;
imax = 17;
break;
case 256:
wsize=8;
imax = 21;
break;
case 128:
wsize=7;
imax = 28;
break;
default:
DISSECTOR_ASSERT_NOT_REACHED();
}
}
iused = imax;
for (i=1; i<=imax; i++) {
w[i] = (gint) tvb_get_bits(tvb, bit_offset, wsize, FALSE);
proto_tree_add_text(subtree, tvb, bit_offset>>3, ((bit_offset+wsize-1)>>3) - (bit_offset>>3) + 1 , "%s %s(%d): %d",
decode_bits_in_field(bit_offset, wsize, w[i]),
"W",
i,
w[i]);
bit_offset += wsize;
curr_offset = bit_offset>>3;
if ((iused == imax) && (w[i] == 0) ) {
iused = i - 1;
}
if ((curr_offset-offset)>len) {
iused = i - 1;
break;
}
if (++jwi == nwi) {
jwi = 0;
nwi <<= 1;
wsize--;
}
}
for (i=1; i<=iused; i++) {
arfcn = (f_k(i, w, range) + arfcn_orig)%1024;
list[arfcn] = 1;
}
display_channel_list(list, tvb, tree, offset, curr_offset-offset);
return;
}
static guint16
dissect_arfcn_list_core(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_, guint8 format)
{
guint32 curr_offset, byte;
guint8 oct,bit;
guint16 arfcn;
proto_item *item;
curr_offset = offset;
if ((format & 0xc0) == 0x00)
{
item = proto_tree_add_text(tree,tvb, curr_offset, len, "List of ARFCNs =");
bit = 4;
arfcn = 125;
for (byte = 0; byte <= len-1; byte++)
{
oct = tvb_get_guint8(tvb, curr_offset);
while (bit-- != 0)
{
arfcn--;
if (((oct >> bit) & 1) == 1)
{
proto_item_append_text(item," %d",arfcn);
}
}
bit = 8;
curr_offset++;
}
}
else if ((format & 0xc8) == 0x80)
{
dissect_channel_list_n_range(tvb, tree, pinfo, curr_offset, len, 1024);
curr_offset = curr_offset + len;
}
else if ((format & 0xce) == 0x88)
{
dissect_channel_list_n_range(tvb, tree, pinfo, curr_offset, len, 512);
curr_offset = curr_offset + len;
}
else if ((format & 0xce) == 0x8a)
{
dissect_channel_list_n_range(tvb, tree, pinfo, curr_offset, len, 256);
curr_offset = curr_offset + len;
}
else if ((format & 0xce) == 0x8c)
{
dissect_channel_list_n_range(tvb, tree, pinfo, curr_offset, len, 128);
curr_offset = curr_offset + len;
}
else if ((format & 0xce) == 0x8e)
{
arfcn = ((format & 0x01) << 9) | (tvb_get_guint8(tvb, curr_offset+1) << 1) | ((tvb_get_guint8(tvb, curr_offset + 2) & 0x80) >> 7);
item = proto_tree_add_text(tree,tvb,curr_offset,len,"List of ARFCNs = %d",arfcn);
curr_offset = curr_offset + 2;
bit = 7;
for (byte = 0; byte <= len-3; byte++)
{
oct = tvb_get_guint8(tvb, curr_offset);
while (bit-- != 0)
{
arfcn++;
if (((oct >> bit) & 1) == 1)
{
proto_item_append_text(item," %d",arfcn);
}
}
bit = 8;
curr_offset++;
}
}
return(curr_offset - offset);
}
static guint16
dissect_arfcn_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_rr_format_id, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += dissect_arfcn_list_core(tvb, tree, pinfo, offset, len, add_string, string_len, oct);
return(curr_offset - offset);
}
static guint16
dissect_arfcn_list2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct;
curr_offset = offset;
oct = tvb_get_guint8(tvb, curr_offset) & 0xbf;
proto_tree_add_item(tree, hf_gsm_a_rr_format_id2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += dissect_arfcn_list_core(tvb, tree, pinfo, offset, len, add_string, string_len, oct);
return(curr_offset - offset);
}
static guint16
de_rr_cell_ch_dsc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
return dissect_arfcn_list(tvb, tree, pinfo, offset, 16, add_string, string_len);
}
static guint16
de_rr_ba_list_pref(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint bit_offset;
bit_offset = offset << 3;
while (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Repeating Range Limits", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_range_lower, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset += 10;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_range_higher, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset += 10;
}
while (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Repeating BA Frequency", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_ba_freq, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset += 10;
}
if (((bit_offset + 7) >> 3) > (offset + len))
{
expert_add_info(pinfo, proto_tree_get_parent(tree), &ei_gsm_a_rr_ie_overrun);
}
else if ((bit_offset >> 3) < (offset + len))
{
expert_add_info(pinfo, proto_tree_get_parent(tree), &ei_gsm_a_rr_ie_underrun);
}
return len;
}
static guint16
de_rr_utran_freq_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint bit_offset;
bit_offset = offset << 3;
while (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Repeating FDD Frequency", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_fdd_uarfcn, tvb, bit_offset, 14, ENC_BIG_ENDIAN);
bit_offset += 14;
}
while (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Repeating TDD Frequency", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_tdd_uarfcn, tvb, bit_offset, 14, ENC_BIG_ENDIAN);
bit_offset += 14;
}
if (((bit_offset + 7) >> 3) > (offset + len))
{
expert_add_info(pinfo, proto_tree_get_parent(tree), &ei_gsm_a_rr_ie_overrun);
}
else if ((bit_offset >> 3) < (offset + len))
{
expert_add_info(pinfo, proto_tree_get_parent(tree), &ei_gsm_a_rr_ie_underrun);
}
return (len);
}
static guint16
de_rr_cell_select_indic(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_tree *subtree, *subtree2;
proto_item *item, *item2;
guint32 curr_offset;
gint bit_offset, bit_offset_sav, idx, xdd_cell_info, wsize, nwi, jwi, w[64], i, iused, xdd_indic0;
guint8 value;
curr_offset = offset;
bit_offset = curr_offset << 3;
value = tvb_get_bits8(tvb,bit_offset,3);
bit_offset += 3;
switch (value)
{
case 0:
bit_offset_sav = bit_offset;
item = proto_tree_add_text(tree, tvb, bit_offset>>3, -1, "%s",
gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_GSM_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_GSM_DESC]);
while (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Repeating GSM Description struct", "Present", "Not Present"))
{
gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Band Indicator", "1900", "1800");
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_arfcn, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset += 10;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bsic, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
}
proto_item_set_len(item,((bit_offset>>3) - (bit_offset_sav>>3) + 1));
break;
case 1:
bit_offset_sav = bit_offset;
item = proto_tree_add_text(tree, tvb, bit_offset>>3, -1, "%s",
gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_FDD_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_UTRAN_FDD_DESC]);
while (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Repeating UTRAN FDD Description struct", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Bandwidth FDD", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bandwidth_fdd, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_fdd_uarfcn, tvb, bit_offset, 14, ENC_BIG_ENDIAN);
bit_offset += 14;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "FDD Cell Information", "Present", "Not Present"))
{
xdd_indic0 = gsm_rr_csn_flag(tvb, subtree, bit_offset++, "FDD Indic0", "1", "0");
idx = tvb_get_bits8(tvb,bit_offset,5);
proto_tree_add_text(subtree,tvb, bit_offset>>3, 1, "Nr of FDD Cells : %d", idx);
bit_offset += 5;
idx = convert_n_to_p[idx];
item2 = proto_tree_add_text(subtree,tvb, bit_offset>>3, (idx>>3)+1, "%s",
gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_FDD_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_FDD_CELL_INFORMATION_FIELD]);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, (idx>>3)+1, "Field is %d bits long", idx);
if (xdd_indic0)
{
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0, "Scrambling Code: %d", 0);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0, "Diversity: %d", 0);
}
if (idx)
{
wsize = 10;
nwi = 1;
jwi = 0;
i = 1;
while (idx > 0)
{
w[i] = tvb_get_bits(tvb, bit_offset, wsize, ENC_BIG_ENDIAN);
bit_offset += wsize;
idx -= wsize;
if (w[i] == 0)
{
idx = 0;
break;
}
if (++jwi == nwi)
{
jwi = 0;
nwi <<= 1;
wsize--;
}
i++;
}
if (idx < 0)
{
bit_offset += idx;
}
iused = i-1;
for (i=1; i <= iused; i++)
{
xdd_cell_info = f_k(i, w, 1024);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0,
"Scrambling Code: %d", xdd_cell_info & 0x01FF);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0,
"Diversity: %d", (xdd_cell_info >> 9) & 0x01);
}
}
}
}
proto_item_set_len(item,((bit_offset>>3) - (bit_offset_sav>>3) + 1));
break;
case 2:
bit_offset_sav = bit_offset;
item = proto_tree_add_text(tree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_TDD_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_UTRAN_TDD_DESC]);
while (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Repeating UTRAN TDD Description struct", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Bandwidth TDD", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bandwidth_tdd, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tdd_uarfcn, tvb, bit_offset, 14, ENC_BIG_ENDIAN);
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "TDD Cell Information", "Present", "Not Present"))
{
xdd_indic0 = gsm_rr_csn_flag(tvb, subtree, bit_offset++, "TDD Indic0", "1", "0");
idx = tvb_get_bits8(tvb,bit_offset,5);
proto_tree_add_text(subtree,tvb, bit_offset>>3, 1, "Nr of TDD Cells : %d", idx);
bit_offset += 5;
idx = convert_n_to_q[idx];
item2 = proto_tree_add_text(subtree,tvb, bit_offset>>3, (idx>>3)+1, "%s",
gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_TDD_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_TDD_CELL_INFORMATION_FIELD]);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, (idx>>3)+1, "Field is %d bits long", idx);
if (xdd_indic0)
{
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0, "Cell Parameter: %d", 0);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0, "Sync Case TSTD: %d", 0);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0, "Diversity TDD: %d", 0);
}
if (idx)
{
wsize = 9;
nwi = 1;
jwi = 0;
i = 1;
while (idx > 0)
{
w[i] = tvb_get_bits(tvb, bit_offset, wsize, ENC_BIG_ENDIAN);
bit_offset += wsize;
idx -= wsize;
if (w[i] == 0)
{
idx = 0;
break;
}
if (++jwi == nwi)
{
jwi = 0;
nwi <<= 1;
wsize--;
}
i++;
}
if (idx < 0)
{
bit_offset += idx;
}
iused = i-1;
for (i=1; i <= iused; i++)
{
xdd_cell_info = f_k(i, w, 512);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0,
"Cell Parameter: %d", xdd_cell_info & 0x07F);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0,
"Sync Case TSTD: %d", (xdd_cell_info >> 7) & 0x01);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 0,
"Diversity TDD: %d", (xdd_cell_info >> 8) & 0x01);
}
}
}
}
proto_item_set_len(item,((bit_offset>>3) - (bit_offset_sav>>3) + 1));
break;
default:
break;
}
curr_offset += len;
return (curr_offset - offset);
}
guint16
de_rr_cell_dsc(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint16 bcch_arfcn;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_ncc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_bcc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
bcch_arfcn = (tvb_get_guint8(tvb,curr_offset) & 0xc0) << 2;
bcch_arfcn = bcch_arfcn | tvb_get_guint8(tvb,curr_offset+1);
proto_tree_add_uint(subtree, hf_gsm_a_rr_bcch_arfcn , tvb, curr_offset, 2, bcch_arfcn );
curr_offset = curr_offset + 2;
return(curr_offset - offset);
}
static guint16
de_rr_cell_opt_bcch(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pwrc, tvb, (curr_offset<<3)+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_dtx_bcch, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_radio_link_timeout, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_cell_opt_sacch(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pwrc, tvb, (curr_offset<<3)+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_split_bits_item_ret_val(subtree, hf_gsm_a_rr_dtx_sacch, tvb, (curr_offset<<3), gsm_a_rr_dtx_sacch_crumbs, NULL);
proto_tree_add_item(subtree, hf_gsm_a_rr_radio_link_timeout, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_cell_sel_param(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_cell_reselect_hyst, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_ms_txpwr_max_cch, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
proto_tree_add_item(subtree, hf_gsm_a_rr_acs, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_neci, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_rxlev_access_min, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
guint16
de_rr_ch_dsc(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct8,subchannel;
guint16 arfcn, hsn, maio;
const gchar *str;
curr_offset = offset;
oct8 = tvb_get_guint8(tvb, curr_offset);
if ((oct8 & 0xf8) == 0x08)
{
str = "TCH/F + ACCHs";
other_decode_bitfield_value(a_bigbuf, oct8, 0xf8, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = %s",a_bigbuf,str);
}
else
{
if ((oct8 & 0xf0) == 0x10)
{
str = "TCH/H + ACCHs, Subchannel";
subchannel = ((oct8 & 0x08)>>3);
}
else if ((oct8 & 0xe0) == 0x20)
{
str = "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4), Subchannel";
subchannel = ((oct8 & 0x18)>>3);
}
else if ((oct8 & 0xc0) == 0x40)
{
str = "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8), Subchannel";
subchannel = ((oct8 & 0x38)>>3);
} else {
str = "Unknown channel information";
subchannel = oct8;
}
other_decode_bitfield_value(a_bigbuf, oct8, 0xf8, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = %s %d",a_bigbuf,str,subchannel);
}
other_decode_bitfield_value(a_bigbuf, oct8, 0x07, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Timeslot: %d",a_bigbuf,(oct8 & 0x07));
curr_offset +=1;
oct8 = tvb_get_guint8(tvb, curr_offset);
other_decode_bitfield_value(a_bigbuf, oct8, 0xe0, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Training Sequence: %d",a_bigbuf,((oct8 & 0xe0)>>5));
if ((oct8 & 0x10) == 0x10)
{
maio = ((oct8 & 0x0f)<<2) | ((tvb_get_guint8(tvb,curr_offset+1) & 0xc0) >> 6);
hsn = (tvb_get_guint8(tvb,curr_offset+1) & 0x3f);
str = "Yes";
other_decode_bitfield_value(a_bigbuf, oct8, 0x10, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Hopping channel: %s",a_bigbuf,str);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Hopping channel: MAIO %d",maio);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Hopping channel: HSN %d",hsn);
}
else
{
arfcn = ((oct8 & 0x03) << 8) | tvb_get_guint8(tvb,curr_offset+1);
str = "No";
other_decode_bitfield_value(a_bigbuf, oct8, 0x10, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Hopping channel: %s",a_bigbuf,str);
other_decode_bitfield_value(a_bigbuf, oct8, 0x0c, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Spare",a_bigbuf);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Single channel : ARFCN %d",arfcn);
}
curr_offset = curr_offset + 2;
return(curr_offset - offset);
}
static guint16
de_rr_ch_dsc2(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct8,subchannel;
guint16 arfcn, hsn, maio;
const gchar *str;
curr_offset = offset;
oct8 = tvb_get_guint8(tvb, curr_offset);
if ((oct8 & 0xf8) == 0x0)
{
str = "TCH/F + FACCH/F and SACCH/M";
other_decode_bitfield_value(a_bigbuf, oct8, 0xf8, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = %s",a_bigbuf,str);
}
else if ((oct8 & 0xf8) == 0x08)
{
str = "TCH/F + FACCH/F and SACCH/F";
other_decode_bitfield_value(a_bigbuf, oct8, 0xf8, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = %s",a_bigbuf,str);
}
else if ((oct8 & 0xf8) == 0xf0)
{
str = "TCH/F + FACCH/F and SACCH/M + bi- and unidirectional channels";
other_decode_bitfield_value(a_bigbuf, oct8, 0xf8, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = %s",a_bigbuf,str);
}
else
{
if ((oct8 & 0xf0) == 0x10)
{
str = "TCH/H + ACCHs, Subchannel";
subchannel = ((oct8 & 0x08)>>3);
}
else if ((oct8 & 0xe0) == 0x20)
{
str = "SDCCH/4 + SACCH/C4 or CBCH (SDCCH/4), Subchannel";
subchannel = ((oct8 & 0x18)>>3);
}
else if ((oct8 & 0xc0) == 0x40)
{
str = "SDCCH/8 + SACCH/C8 or CBCH (SDCCH/8), Subchannel";
subchannel = ((oct8 % 0x38)>>3);
}
else if ((oct8 & 0xc0) == 0x80)
{
str = "TCH/F + FACCH/F and SACCH/M + bidirectional channels at timeslot";
subchannel = ((oct8 % 0x38)>>3);
}
else if ((oct8 & 0xe0) == 0xc0)
{
str = "TCH/F + FACCH/F and SACCH/M + unidirectional channels at timeslot";
subchannel = ((oct8 % 0x38)>>3);
} else {
str = "Unknown channel information";
subchannel = oct8;
}
other_decode_bitfield_value(a_bigbuf, oct8, 0xf8, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = %s %d",a_bigbuf,str,subchannel);
}
other_decode_bitfield_value(a_bigbuf, oct8, 0x07, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Timeslot: %d",a_bigbuf,(oct8 & 0x07));
curr_offset +=1;
oct8 = tvb_get_guint8(tvb, curr_offset);
other_decode_bitfield_value(a_bigbuf, oct8, 0xe0, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Training Sequence: %d",a_bigbuf,((oct8 & 0xe0)>>5));
if ((oct8 & 0x10) == 0x10)
{
maio = ((oct8 & 0x0f)<<2) | ((tvb_get_guint8(tvb,curr_offset+1) & 0xc0) >> 6);
hsn = (tvb_get_guint8(tvb,curr_offset+1) & 0x3f);
str = "Yes";
other_decode_bitfield_value(a_bigbuf, oct8, 0x10, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Hopping channel: %s",a_bigbuf,str);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Hopping channel: MAIO %d",maio);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Hopping channel: HSN %d",hsn);
}
else
{
arfcn = ((oct8 & 0x03) << 8) | tvb_get_guint8(tvb,curr_offset+1);
str = "No";
other_decode_bitfield_value(a_bigbuf, oct8, 0x10, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Hopping channel: %s",a_bigbuf,str);
other_decode_bitfield_value(a_bigbuf, oct8, 0x0c, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Spare",a_bigbuf);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Single channel : ARFCN %d",arfcn);
}
curr_offset = curr_offset + 2;
return(curr_offset - offset);
}
static guint16
de_rr_ch_dsc3(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct8;
guint16 arfcn, hsn, maio;
const gchar *str;
curr_offset = offset;
oct8 = tvb_get_guint8(tvb, curr_offset);
other_decode_bitfield_value(a_bigbuf, oct8, 0xe0, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Training Sequence: %d",a_bigbuf,((oct8 & 0xe0)>>5));
if ((oct8 & 0x10) == 0x10)
{
maio = ((oct8 & 0x0f)<<2) | ((tvb_get_guint8(tvb,curr_offset+1) & 0xc0) >> 6);
hsn = (tvb_get_guint8(tvb,curr_offset+1) & 0x3f);
str = "Yes";
other_decode_bitfield_value(a_bigbuf, oct8, 0x10, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Hopping channel: %s",a_bigbuf,str);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Hopping channel: MAIO %d",maio);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Hopping channel: HSN %d",hsn);
}
else
{
arfcn = ((oct8 & 0x03) << 8) | tvb_get_guint8(tvb,curr_offset+1);
str = "No";
other_decode_bitfield_value(a_bigbuf, oct8, 0x10, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Hopping channel: %s",a_bigbuf,str);
other_decode_bitfield_value(a_bigbuf, oct8, 0x0c, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Spare",a_bigbuf);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Single channel : ARFCN %d",arfcn);
}
curr_offset = curr_offset + 2;
return(curr_offset - offset);
}
guint16
de_rr_ch_mode(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_channel_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_ch_mode2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_channel_mode2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_utran_cm(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
tvbuff_t *rrc_irat_ho_info_tvb;
curr_offset = offset;
if (len)
{
rrc_irat_ho_info_tvb = tvb_new_subset(tvb, curr_offset, len, len);
if (rrc_irat_ho_info_handle)
call_dissector(rrc_irat_ho_info_handle, rrc_irat_ho_info_tvb, pinfo, tree);
}
curr_offset += len;
return(curr_offset - offset);
}
guint16
de_rr_cm_enq_mask(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_cm_cng_msg_req, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_utran_cm_cng_msg_req, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_cdma200_cm_cng_msg_req, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_geran_iu_cm_cng_msg_req, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
guint16
de_rr_chnl_needed(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
curr_offset = offset;
if (RIGHT_NIBBLE == len)
bit_offset = 4;
else
bit_offset = 0;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_chnl_needed_ch1, tvb, (curr_offset<<3)+bit_offset+2, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_chnl_needed_ch2, tvb, (curr_offset<<3)+bit_offset, 2, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
guint16
de_rr_chnl_req_desc2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 bit_offset = offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_pkt_estab_cause, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_peak_throughput_class, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_radio_priority, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_rlc_mode, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_llc_pdu_type, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_rlc_octet_count, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset += 16;
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "PFI", "Present", "Not Present")) {
proto_tree_add_bits_item(tree, hf_gsm_a_rr_pfi, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
}
gsm_rr_csn_HL_flag(tvb, tree, 0, bit_offset++, "Multiple TBF Capability",
"Multiple TBF procedures in A/Gb mode supported",
"Multiple TBF procedures in A/Gb mode not supported");
bit_offset += 1;
if (gsm_rr_csn_HL_flag(tvb, tree, (offset+len)<<3, bit_offset++, "Additions in Rel-7", "Present", "Not present")) {
proto_tree_add_bits_item(tree, hf_gsm_a_rr_rlc_non_pers_mode_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_reduced_latency_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_ul_egprs2, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_dl_egprs2, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
if (gsm_rr_csn_HL_flag(tvb, tree, (offset+len)<<3, bit_offset++, "Additions in Rel-9", "Present", "Not present")) {
proto_tree_add_bits_item(tree, hf_gsm_a_rr_emst_ms_cap, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
}
return len;
}
guint16
de_rr_cip_mode_set(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
guint64 value;
curr_offset = offset;
if (RIGHT_NIBBLE == len)
bit_offset = 4;
else
bit_offset = 0;
proto_tree_add_bits_ret_val(tree, hf_gsm_a_rr_sc, tvb, (curr_offset<<3)+bit_offset+3, 1, &value, ENC_BIG_ENDIAN);
if (value == 1){
proto_tree_add_bits_item(tree, hf_gsm_a_rr_algorithm_id, tvb, (curr_offset<<3)+bit_offset, 3, ENC_BIG_ENDIAN);
}
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_cip_mode_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
curr_offset = offset;
if (RIGHT_NIBBLE == len)
bit_offset = 4;
else
bit_offset = 0;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_cr, tvb, (curr_offset<<3)+bit_offset+3, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_ctrl_ch_desc(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint8 oct;
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_mscr, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_att, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_bs_ag_blks_res, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_ccch_conf, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
oct = tvb_get_guint8(tvb, curr_offset);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_cbq3, tvb, (curr_offset<<3)+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_uint(subtree, hf_gsm_a_rr_bs_pa_mfrms, tvb, curr_offset, 1, (oct&0x07)+2);
curr_offset = curr_offset + 1;
proto_tree_add_item(subtree, hf_gsm_a_rr_t3212, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_dtm_info_details(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 bit_offset = offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_max_lapdm, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_gprs_ms_txpwr_max_ccch, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_cell_id, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset += 16;
if (gsm_rr_csn_HL_flag(tvb, tree, (offset+len)<<3, bit_offset++, "Additions in Rel-6", "Present", "Not present")) {
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "MBMS procedures", "Supported by cell", "Not supported by cell")) {
proto_tree_add_bits_item(tree, hf_gsm_a_rr_dedicated_mode_mbms_notification_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_mnci_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
}
}
return len;
}
static guint16
de_rr_dyn_arfcn_map(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint bit_offset;
bit_offset = offset << 3;
while (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Repeating Dynamic ARFCN Mapping", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_gsm_band, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_arfcn_first, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset += 10;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_band_offset, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset += 10;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_arfcn_range, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
}
if (((bit_offset + 7) >> 3) > (offset + len))
{
expert_add_info(pinfo, proto_tree_get_parent(tree), &ei_gsm_a_rr_ie_overrun);
}
else if ((bit_offset >> 3) < (offset + len))
{
expert_add_info(pinfo, proto_tree_get_parent(tree), &ei_gsm_a_rr_ie_underrun);
}
return(len);
}
static guint16
de_rr_freq_ch_seq(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset, i;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_lowest_arfcn, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
bit_offset = curr_offset << 3;
for (i=0; i<16; i++)
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_inc_skip_arfcn, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
}
curr_offset = curr_offset + 8;
return(curr_offset - offset);
}
static guint16
de_rr_freq_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
return dissect_arfcn_list(tvb, tree, pinfo, offset, len, add_string, string_len);
}
static guint16
de_rr_freq_short_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
return dissect_arfcn_list(tvb, tree, pinfo, offset, 9, add_string, string_len);
}
static guint16
de_rr_freq_short_list2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
return dissect_arfcn_list(tvb, tree, pinfo, offset, 8, add_string, string_len);
}
static guint16
de_rr_gprs_resumption(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_gprs_resumption_ack, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return (curr_offset - offset);
}
static gint
de_rr_rest_oct_gprs_cell_options(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree, *subtree2;
proto_item *item, *item2;
gint curr_bit_offset, curr_bit_offset_sav;
guint8 value;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_GPRS_CELL_OPTIONS].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_GPRS_CELL_OPTIONS]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_nmo, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_t3168, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_t3192, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_drx_timer_max, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_access_burst_type, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_control_ack_type, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bs_cv_max, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "PAN bits", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pan_dec, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pan_inc, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pan_max, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Optional Extensions", "Present", "Not Present"))
{
curr_bit_offset_sav = curr_bit_offset;
item2 = proto_tree_add_text(subtree, tvb, curr_bit_offset>>3, -1, "%s",
gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_GPRS_CELL_OPTIONS_EXT_INFO].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_GPRS_CELL_OPTIONS_EXT_INFO]);
value = tvb_get_bits8(tvb,curr_bit_offset,6);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 1, "Extension Length: %d", value);
curr_bit_offset += 6;
value += 1;
proto_item_set_len(item2,((curr_bit_offset+value)>>3) - (curr_bit_offset_sav>>3)+1);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "EGPRS", "Supported by cell", "Not supported by cell"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_egprs_packet_channel_request, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_bep_period, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
value -= 5;
}
value -= 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_pfc_feature_mode, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_dtm_support, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_bss_paging_coordination, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
value -= 3;
if (value > 0)
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_ccn_active, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_nw_ext_utbf, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
value -= 2;
if (value > 0)
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_multiple_tbf_capability, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_ext_utbf_no_data, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_dtm_enhancements_capability, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
value -= 3;
if (gsm_rr_csn_flag(tvb, subtree2, curr_bit_offset++, "MBMS procedures", "Supported by cell", "Not supported by cell"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_dedicated_mode_mbms_notification_support, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_mnci_support, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
value -= 2;
}
value -= 1;
if (value > 0)
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_reduced_latency_access, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
value -= 1;
}
}
}
curr_bit_offset += value;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_rest_oct_gprs_power_control_parameters(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_GPRS_POWER_CONTROL_PARAMS].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_GPRS_POWER_CONTROL_PARAMS]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_alpha, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_t_avg_w, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_t_avg_t, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pc_meas_chan, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_n_avg_i, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static guint16
de_rr_gprs_broadcast_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len , gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
curr_offset = offset;
bit_offset = curr_offset << 3;
bit_offset += de_rr_rest_oct_gprs_cell_options(tvb, tree, bit_offset);
de_rr_rest_oct_gprs_power_control_parameters(tvb, tree, bit_offset);
curr_offset += len;
return (curr_offset - offset);
}
static guint16
de_rr_ho_ref(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_ho_ref_val, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_tbf_starting_time(tvbuff_t *tvb, proto_tree *tree, guint32 bit_offset)
{
proto_item *item;
guint32 curr_bit_offset;
guint16 rfn, t;
guint64 t1, t2, t3;
curr_bit_offset = bit_offset;
proto_tree_add_bits_ret_val(tree, hf_gsm_a_rr_tbf_T1prim, tvb, curr_bit_offset, 5, &t1, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_tree_add_bits_ret_val(tree, hf_gsm_a_rr_tbf_T3, tvb, curr_bit_offset, 6, &t3, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
proto_tree_add_bits_ret_val(tree, hf_gsm_a_rr_tbf_T2, tvb, curr_bit_offset, 5, &t2, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
t = (26 + t3 - t2) % 26;
rfn = (guint16)((51 * t) + t3 + (51 * 26 * t1));
item = proto_tree_add_uint(tree, hf_gsm_a_rr_tbf_starting_time, tvb, bit_offset >> 3, ((curr_bit_offset - bit_offset) >> 3) + 1, rfn);
PROTO_ITEM_SET_GENERATED(item);
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_ia_rest_oct_egprs_packet_uplink_assignment(tvbuff_t *tvb, proto_tree *tree, gint bit_offset, guint bit_len)
{
proto_tree *subtree;
proto_item *item;
guint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EGPRS_PACKET_UPLINK_ASSIGNMENT].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EGPRS_PACKET_UPLINK_ASSIGNMENT]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_extended_ra, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Access Technologies Request", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_access_tech_type, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "", "TFI Assignment Present", "Multi Block Allocation Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tfi_assignment, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_polling, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Allocation Type", "Fixed Allocation (not to be used after Rel-4)", "Dynamic Allocation (mandatory after Rel-4)"))
{
gint8 bitmap_len = tvb_get_bits8(tvb, curr_bit_offset, 5);
gint32 bitmap;
proto_tree_add_text(tree, tvb, curr_bit_offset>>3, 1+((curr_bit_offset+5)>>3) - (curr_bit_offset>>3), "Bitmap length %d", bitmap_len);
curr_bit_offset += 5;
bitmap = tvb_get_bits32(tvb, curr_bit_offset, bitmap_len, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, curr_bit_offset>>3, 1+((curr_bit_offset+bitmap_len)>>3) - (curr_bit_offset>>3), "Bitmap %d", bitmap);
curr_bit_offset += bitmap_len;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "P0 bits", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_p0, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pr_mode, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_usf, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_usf_granularity, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "P0 bits", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_p0, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pr_mode, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_egprs_mcs, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tlli_block_channel_coding, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "BEP_PERIOD2", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bep_period2, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_resegment, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_egprs_window_size, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Alpha", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_alpha, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_gamma, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Timing Advance Index", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_timing_adv_index, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "TBF Starting Time", "Present", "Not Present"))
{
curr_bit_offset += de_tbf_starting_time(tvb, subtree, curr_bit_offset);
}
}
else
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Alpha", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_alpha, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_gamma, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
curr_bit_offset += de_tbf_starting_time(tvb, subtree, curr_bit_offset);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_num_of_radio_block_allocated, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "P0 bits", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_p0, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "BTS Power Control Mode", "Mode B (not to be used after Rel-4)", "Mode A (mandatory after Rel-4)");
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pr_mode, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
if (curr_bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb,subtree, 0,curr_bit_offset++,"Additions in Rel-7", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "PFI", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pfi, tvb, curr_bit_offset, 7, ENC_BIG_ENDIAN);
curr_bit_offset += 7;
}
}
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_ia_rest_oct_tmgi(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
guint16 value16;
gchar mcc[4];
gchar mnc[4];
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_TMGI].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_TMGI]);
if (0 == gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "MCC and MNC Parameters", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_mbms_service_id, tvb, curr_bit_offset, 24, ENC_BIG_ENDIAN);
curr_bit_offset += 24;
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_mbms_service_id, tvb, curr_bit_offset, 24, ENC_BIG_ENDIAN);
curr_bit_offset += 24;
value16 = tvb_get_bits16(tvb,curr_bit_offset,12,ENC_BIG_ENDIAN);
mcc[0] = '0' + ((value16>>8)&0xf);
mcc[1] = '0' + ((value16>>4)&0xf);
mcc[2] = '0' + ((value16 )&0xf);
mcc[3] = '\0';
proto_tree_add_text(tree,
tvb, curr_bit_offset>>3, 12,
"Mobile Country Code (MCC): %s",
mcc);
curr_bit_offset += 12;
value16 = tvb_get_bits16(tvb,curr_bit_offset,12,ENC_BIG_ENDIAN);
mnc[0] = '0' + ((value16>>8)&0xf);
mnc[1] = '0' + ((value16>>4)&0xf);
mnc[2] = '0' + ((value16 )&0xf);
mnc[3] = '\0';
proto_tree_add_text(tree,
tvb, curr_bit_offset>>3, 12,
"Mobile Network Code (MNC): %s",
mnc);
curr_bit_offset += 12;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_ia_rest_oct_packet_timing_advance(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_PACKET_TIMING_ADVANCE].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_PACKET_TIMING_ADVANCE]);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Timing Advance Value", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_timing_adv, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Timing Advance Index and Timeslot", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_timing_adv_index, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_timing_adv_timeslot_num, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_ia_rest_oct_multiple_blocks_packet_downlink_assignment(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
guint8 value;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_MULTIPLE_BLOCKS_PACKET_DOWNLINK_ASSIGNMENT].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_MULTIPLE_BLOCKS_PACKET_DOWNLINK_ASSIGNMENT]);
curr_bit_offset += de_tbf_starting_time(tvb, subtree, curr_bit_offset);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_num_of_radio_block_allocated, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "", "default 0 bit", "Reserved Value"))
{
if (0 == gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "MBMS Assignment", "(Non-distribution)", "(Distribution)"))
{
curr_bit_offset += de_rr_ia_rest_oct_tmgi(tvb, tree, curr_bit_offset);
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tlli, tvb, curr_bit_offset, 32, ENC_BIG_ENDIAN);
curr_bit_offset += 32;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "MS Parameters", "Present", "Not Present"))
{
value = tvb_get_bits8(tvb,curr_bit_offset,2);
proto_tree_add_text(tree,
tvb, curr_bit_offset>>3, 2,
"Length Indicator of MS ID: %d",
value);
curr_bit_offset += 2;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_ms_id, tvb, curr_bit_offset, value+1, ENC_BIG_ENDIAN);
curr_bit_offset += value+1;
curr_bit_offset += de_rr_ia_rest_oct_packet_timing_advance(tvb, tree, curr_bit_offset);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Alpha", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_alpha, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Gamma", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_gamma, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
}
}
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_ia_rest_oct_packet_uplink_assignment(tvbuff_t *tvb, proto_tree *tree, gint bit_offset, guint bit_len)
{
proto_tree *subtree;
proto_item *item;
guint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_PACKET_UPLINK_ASSIGNMENT].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_PACKET_UPLINK_ASSIGNMENT]);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Packet Uplink Assignment", "Normal", "Single Block"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tfi_assignment, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_polling, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Allocation Type", "Fixed Allocation (not to be used after Rel-4))", "Dynamic Allocation (mandatory after Rel-4)"))
{
gint8 bitmap_len = tvb_get_bits8(tvb, curr_bit_offset, 5);
gint32 bitmap;
proto_tree_add_text(tree, tvb, curr_bit_offset>>3, 1+((curr_bit_offset+5)>>3) - (curr_bit_offset>>3), "Bitmap length %d", bitmap_len);
curr_bit_offset += 5;
bitmap = tvb_get_bits32(tvb, curr_bit_offset, bitmap_len, ENC_BIG_ENDIAN);
proto_tree_add_text(tree, tvb, curr_bit_offset>>3, 1+((curr_bit_offset+bitmap_len)>>3) - (curr_bit_offset>>3), "Bitmap %d", bitmap);
curr_bit_offset += bitmap_len;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "P0 bits", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_p0, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pr_mode, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_usf, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_usf_granularity, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "P0", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_p0, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pr_mode, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_gprs_cs, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tlli_block_channel_coding, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Alpha", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_alpha, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_gamma, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Timing Advance Index", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_timing_adv_index, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "TBF Starting Time", "Present", "Not Present"))
{
curr_bit_offset += de_tbf_starting_time(tvb, subtree, curr_bit_offset);
}
}
else
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Alpha", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_alpha, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_gamma, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Bit reserved for earlier version of protocol", "Early R97 version", "Later than R97 version");
gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Bit reserved for earlier version of protocol", "Later than R97 version", "Early R97 version");
curr_bit_offset += de_tbf_starting_time(tvb, subtree, curr_bit_offset);
if (gsm_rr_csn_HL_flag(tvb,subtree, 0,curr_bit_offset++,"P0", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_p0, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Bit reserved for earlier version of protocol", "Earlier version", "Current version");
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pr_mode, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
}
if (curr_bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb,subtree, 0,curr_bit_offset++,"Additions in R99", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Extended RA", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_extended_ra, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
}
}
if (curr_bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb,subtree, 0,curr_bit_offset++,"Additions in Rel-6", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "PFI", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pfi, tvb, curr_bit_offset, 7, ENC_BIG_ENDIAN);
curr_bit_offset += 7;
}
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_ia_rest_oct_packet_downlink_assignment(tvbuff_t *tvb, proto_tree *tree, guint bit_offset, guint bit_len)
{
proto_tree *subtree;
proto_item *item;
guint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_PACKET_DOWNLINK_ASSIGNMENT].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_PACKET_DOWNLINK_ASSIGNMENT]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tlli, tvb, curr_bit_offset, 32, ENC_BIG_ENDIAN);
curr_bit_offset += 32;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "TFI Assignment (etc)", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tfi_assignment, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rlc_mode, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Alpha", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_alpha, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_gamma, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_polling, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_ta_valid, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Timing Advance Index", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_timing_adv_index, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "TBF Starting Time", "Present", "Not Present"))
{
curr_bit_offset += de_tbf_starting_time(tvb, subtree, curr_bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "P0", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_p0, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "BTS Power Control Mode", "Mode B (not to be used after Rel-4)", "Mode A (mandatory after Rel-4)");
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pr_mode, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
if (curr_bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb,subtree, 0,curr_bit_offset++,"Additions in R99", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_egprs_window_size, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_link_quality_meas_mode, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "BEP_PERIOD2", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bep_period2, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
}
}
if (curr_bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb,subtree, 0, curr_bit_offset++, "Additions in Rel-6", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "PFI", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_pfi, tvb, curr_bit_offset, 7, ENC_BIG_ENDIAN);
curr_bit_offset += 7;
}
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_ia_rest_oct_second_part_packet_assignment(tvbuff_t *tvb, proto_tree *tree, guint bit_offset, guint bit_len)
{
proto_tree *subtree;
proto_item *item;
guint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_SECOND_PART_PACKET_ASSIGNMENT].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_SECOND_PART_PACKET_ASSIGNMENT]);
if (curr_bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb,subtree, 0,curr_bit_offset++,"Additions in R99", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Extended RA", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_extended_ra, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static guint16
de_rr_ia_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
guint32 curr_offset;
gint bit_offset;
gint length;
guint64 ma_length;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
curr_offset = offset;
bit_offset = curr_offset << 3;
if (0 == gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "First Discriminator Bit", "High", "Low"))
{
if (0 == gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Second Discriminator Bit", "High", "Low"))
{
gsm_rr_csn_HL_flag(tvb, subtree, 0,bit_offset++, "A compressed version of the INTER RAT HANDOVER INFO message ", "shall be used", "shall not be used");
}
else
{
if (0 == gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Discriminator bit", "reserved for future use", "EGPRS Packet Uplink Assignment or Multiple blocks Packet Downlink Assignment"))
{
if (0 == gsm_rr_csn_flag(tvb, subtree, bit_offset++, "", "Multiple blocks Packet Downlink Assignment", "EGPRS Packet Uplink Assignment"))
{
bit_offset += de_rr_ia_rest_oct_egprs_packet_uplink_assignment(tvb, subtree, bit_offset, bit_len);
}
else
{
bit_offset += de_rr_ia_rest_oct_multiple_blocks_packet_downlink_assignment(tvb, subtree, bit_offset);
}
}
else
{
proto_tree_add_text(subtree, tvb, bit_offset>>3, 1, "reserved for future use (however the value 7C for the first octet shall not be used)");
}
}
}
else
{
if (0 == gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Second Discriminator Bit", "High", "Low"))
{
proto_tree_add_bits_ret_val(subtree, hf_gsm_a_rr_ma_length, tvb, bit_offset, 6, &ma_length, ENC_BIG_ENDIAN);
bit_offset += 6;
if (ma_length>0)
{
bit_offset += 2;
proto_tree_add_text(subtree, tvb, bit_offset>>3, 1, "MAIO: %d", tvb_get_bits8(tvb,bit_offset,6));
bit_offset += 6;
length = (gint)ma_length;
item = proto_tree_add_text(subtree,tvb, bit_offset>>3, (length>>3)-1, "MA Bitmap: ");
length = (length-1)*8;
while (length)
{
proto_item_append_text(item,"%d",tvb_get_bits8(tvb,bit_offset,1));
bit_offset += 1;
length -= 1;
}
}
gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "A compressed version of the INTER RAT HANDOVER INFO message", "shall be used", "shall not be used");
}
else
{
if (0 == gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Discriminator Bit", "Second Part Packet Assignment", "Packet Assignment"))
{
if (0 == gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Discriminator Bit", "Packet Downlink Assignment", "Packet Uplink Assignment"))
{
bit_offset += de_rr_ia_rest_oct_packet_uplink_assignment(tvb, subtree, bit_offset, bit_len);
}
else
{
bit_offset += de_rr_ia_rest_oct_packet_downlink_assignment(tvb, subtree, bit_offset, bit_len);
}
}
else
{
bit_offset += de_rr_ia_rest_oct_second_part_packet_assignment(tvb, subtree, bit_offset, bit_len);
}
}
}
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_iar_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_bit_offset;
guint8 i;
guint8 tvb_len = tvb_length(tvb);
curr_bit_offset = offset<<3;
for( i=0; i<4; i++ )
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Extended RA", "Present", "Not Present"))
{
proto_tree_add_text(subtree, tvb, curr_bit_offset>>3, 1, "Extended RA %d present", i);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_extended_ra, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
else
{
proto_tree_add_text(subtree, tvb, curr_bit_offset>>3, 1, "Extended RA %d not present", i);
}
}
gsm_rr_csn_padding_bits(subtree, tvb, curr_bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_iax_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_bit_offset;
guint8 tvb_len = tvb_length(tvb);
curr_bit_offset = offset<<3;
gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "A compressed version of the INTER RAT HANDOVER INFO message", "shall be used", "shall not be used");
gsm_rr_csn_padding_bits(subtree, tvb, curr_bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_l2_pseudo_len(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_L2_pseudo_len, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
guint16
de_rr_meas_res(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
guint64 no_ncell_m;
curr_offset = offset;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_ba_used, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_dtx_used, tvb, (curr_offset<<3)+1, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rxlev_full_serv_cell, tvb, (curr_offset<<3)+2, 6, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_ba_used, tvb, curr_offset<<3, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_meas_valid, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_rxlev_sub_serv_cell, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rxqual_full_serv_cell, tvb, (curr_offset<<3)+1, 3, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_rxqual_sub_serv_cell, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
bit_offset = (curr_offset << 3) + 7;
proto_tree_add_bits_ret_val(subtree, hf_gsm_a_rr_no_ncell_m, tvb, bit_offset, 3, &no_ncell_m, ENC_BIG_ENDIAN);
bit_offset += 3;
if (no_ncell_m == 7)
no_ncell_m = 0;
while (no_ncell_m)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rxlev_ncell, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bcch_freq_ncell, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bsic_ncell, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
no_ncell_m -= 1;
}
return(len);
}
static guint16
de_rr_mob_all(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
proto_item *item;
gint i, j;
guint8 value;
curr_offset = offset;
item = proto_tree_add_text(tree, tvb, curr_offset, len, "Bitmap of increasing ARFCNs included in the Mobile Allocation: ");
for(i=len; i>0; i--)
{
value = tvb_get_guint8(tvb,curr_offset+i-1);
for (j=0; j<8; j++)
{
proto_item_append_text(item,"%d",(value>>j)&0x01);
}
}
curr_offset = curr_offset + len;
return(curr_offset - offset);
}
static guint16
de_rr_mob_time_diff(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_mobile_time_difference, tvb, curr_offset, len, ENC_BIG_ENDIAN);
curr_offset = curr_offset + len;
return(curr_offset - offset);
}
guint16
de_rr_multirate_conf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct;
gint bit_offset, remaining_length, nb_of_params;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_multirate_speech_ver, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_NCSB, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_ICMI, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_start_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
oct = ( tvb_get_guint8(tvb,curr_offset) &0xe0 ) >> 5;
curr_offset++;
switch ( oct){
case 1:
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v1_b8, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v1_b7, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v1_b6, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v1_b5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v1_b4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v1_b3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v1_b2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v1_b1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
remaining_length = len-2;
break;
case 2:
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v2_b5, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v2_b4, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v2_b3, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v2_b2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_set_of_amr_codec_modes_v2_b1, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
remaining_length = len-2;
break;
default:
proto_tree_add_text(tree,tvb,offset,1,"Unknown version");
proto_tree_add_text(tree,tvb, curr_offset, len-1 ,"Data(Not decoded)");
remaining_length = 0;
break;
}
if (remaining_length)
{
bit_offset = (curr_offset<<3) + 2;
nb_of_params = remaining_length - 1;
while (nb_of_params)
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_amr_threshold, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_amr_hysteresis, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
nb_of_params -= 1;
}
}
curr_offset = offset + len;
return(curr_offset - offset);
}
static guint16
de_rr_mult_all(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
guint32 curr_offset;
guint8 oct;
guint8 i;
curr_offset = offset;
item = proto_tree_add_text(tree,tvb, curr_offset, 1 ,"List of DA:");
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
for( i=0;i<7;i++ )
{
if( (oct>>i) & 1 )
{
proto_item_append_text(item," DA%d",i+1);
}
}
if( oct & 0x80 )
{
item = proto_tree_add_text(tree,tvb, curr_offset, 1 ,"List of UA:");
oct = tvb_get_guint8(tvb, curr_offset);
curr_offset++;
for( i=0;i<7;i++ )
{
if( (oct>>i) & 1 )
{
proto_item_append_text(item," UA%d",i+1);
}
}
}
while ( curr_offset < offset + len )
{
proto_tree_add_item(tree, hf_gsm_a_rr_ma_channel_set, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
}
return(curr_offset - offset);
}
static guint16
de_rr_neigh_cell_desc(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_ext_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_rr_ba_ind, tvb, (curr_offset<<3)+3, 1, ENC_BIG_ENDIAN);
return dissect_arfcn_list(tvb, tree, pinfo, offset, 16, add_string, string_len);
}
static guint16
de_rr_neigh_cell_desc2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_multiband_reporting, tvb, (curr_offset<<3)+1, 2, ENC_BIG_ENDIAN);
proto_tree_add_bits_item(tree, hf_gsm_a_rr_ba_ind, tvb, (curr_offset<<3)+3, 1, ENC_BIG_ENDIAN);
return dissect_arfcn_list2(tvb, tree, pinfo, offset, 16, add_string, string_len);
}
static guint16
de_rr_p1_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_item *item2;
guint32 curr_offset, value;
gint bit_offset, bit_offset_sav;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
curr_offset = offset;
bit_offset = curr_offset << 3;
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "NLN(PCH)", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_nln_pch, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_nln_status_pch, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Priority 1", "Present", "Not present"))
{
item2 = proto_tree_add_bits_item(subtree, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_item_append_text(item2, " for Mobile Identity 1");
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Priority 2", "Present", "Not present"))
{
item2 = proto_tree_add_bits_item(subtree, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_item_append_text(item2, " for Mobile Identity 2");
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Group Call Information", "Present", "Not present"))
{
bit_offset_sav = bit_offset;
bit_offset += 36;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Group Channel Description", "Present", "Not Present"))
{
bit_offset += 24;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Hopping case", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "????", "Present", "Not Present"))
{
bit_offset += 64;
}
else
{
value = tvb_get_bits8(tvb,bit_offset,8);
bit_offset += 8 + (value<<3);
}
}
}
proto_tree_add_text(subtree,tvb, bit_offset_sav>>3, (bit_offset-bit_offset_sav)>>3,"Group Call Information: Data(Not decoded)");
}
gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Packet Page Indication 1", "For GPRS", "For RR connection establishment");
gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Packet Page Indication 2", "For GPRS", "For RR connection establishment");
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_p2_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_item *item2;
guint32 curr_offset;
gint bit_offset;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
curr_offset = offset;
bit_offset = curr_offset << 3;
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Channel Needed 3", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_chnl_needed_ch3, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len ,bit_offset++, "NLN (PCH)", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_nln_pch, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_nln_status_pch, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Priority 1", "Present", "Not present"))
{
item2 = proto_tree_add_bits_item(subtree, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_item_append_text(item2, " for Mobile Identity 1");
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Priority 2", "Present", "Not present"))
{
item2 = proto_tree_add_bits_item(subtree, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_item_append_text(item2, " for Mobile Identity 2");
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Priority 3", "Present", "Not present"))
{
item2 = proto_tree_add_bits_item(subtree, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_item_append_text(item2, " for Mobile Identity 3");
}
gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Packet Paging Procedure 1", "For GPRS", "For RR connection establishment");
gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Packet Paging Procedure 2", "For GPRS", "For RR connection establishment");
gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Packet Paging Procedure 3", "For GPRS", "For RR connection establishment");
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Additions in release 6", "Present", "Not present"))
{
bit_offset += 1;
proto_tree_add_text(subtree, tvb, bit_offset>>3, -1,"Additions in Release 6: Data(Not decoded)");
}
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_p3_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_item *item2;
guint32 curr_offset;
gint bit_offset;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
curr_offset = offset;
bit_offset = curr_offset << 3;
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Channel Needed 3 & 4", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_chnl_needed_ch3, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_chnl_needed_ch4, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "NLN (PCH)", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_nln_pch, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_nln_status_pch, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Priority 1", "Present", "Not present"))
{
item2 = proto_tree_add_bits_item(subtree, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_item_append_text(item2, " for Mobile Identity 1");
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Priority 2", "Present", "Not present"))
{
item2 = proto_tree_add_bits_item(subtree, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_item_append_text(item2, " for Mobile Identity 2");
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Priority 3", "Present", "Not present"))
{
item2 = proto_tree_add_bits_item(subtree, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_item_append_text(item2, " for Mobile Identity 3");
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Priority 4", "Present", "Not present"))
{
item2 = proto_tree_add_bits_item(subtree, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_item_append_text(item2, " for Mobile Identity 4");
}
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_packet_ch_desc(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
guint8 oct8;
guint16 arfcn, hsn, maio;
const gchar *str;
curr_offset = offset;
oct8 = tvb_get_guint8(tvb, curr_offset);
str = "Spare bits (ignored by receiver)";
other_decode_bitfield_value(a_bigbuf, oct8, 0xf8, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = %s",a_bigbuf,str);
other_decode_bitfield_value(a_bigbuf, oct8, 0x07, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Timeslot: %d",a_bigbuf,(oct8 & 0x07));
curr_offset +=1;
oct8 = tvb_get_guint8(tvb, curr_offset);
other_decode_bitfield_value(a_bigbuf, oct8, 0xe0, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Training Sequence: %d",a_bigbuf,((oct8 & 0xe0)>>5));
if ((oct8 & 0x10) == 0x10)
{
maio = ((oct8 & 0x0f)<<2) | ((tvb_get_guint8(tvb,curr_offset+1) & 0xc0) >> 6);
hsn = (tvb_get_guint8(tvb,curr_offset+1) & 0x3f);
str = "Yes";
other_decode_bitfield_value(a_bigbuf, oct8, 0x10, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Hopping channel: %s",a_bigbuf,str);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Hopping channel: MAIO %d",maio);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Hopping channel: HSN %d",hsn);
}
else
{
arfcn = ((oct8 & 0x03) << 8) | tvb_get_guint8(tvb,curr_offset+1);
str = "No";
other_decode_bitfield_value(a_bigbuf, oct8, 0x10, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Hopping channel: %s",a_bigbuf,str);
other_decode_bitfield_value(a_bigbuf, oct8, 0x0c, 8);
proto_tree_add_text(subtree,tvb, curr_offset, 1,"%s = Spare",a_bigbuf);
proto_tree_add_text(subtree,tvb, curr_offset, 2,"Single channel : ARFCN %d",arfcn);
}
curr_offset = curr_offset + 2;
return(curr_offset - offset);
}
static guint16
de_rr_ded_mod_or_tbf(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_dedicated_mode_or_tbf, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return(curr_offset - offset);
}
static guint16
de_rr_pkt_ul_ass(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(subtree, tvb, curr_offset, len, "Not dissected yet");
return len;
}
static guint16
de_rr_pkt_dl_ass(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(subtree, tvb, curr_offset, len, "Not dissected yet");
return len;
}
static guint16
de_rr_pkt_dl_ass_type2(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(subtree, tvb, curr_offset, len, "Not dissected yet");
return len;
}
static guint16
de_rr_page_mode(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_page_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return(curr_offset - offset);
}
static guint16
de_rr_ncc_perm(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_ncc_permitted, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_pow_cmd(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_b8spare, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_pow_cmd_epc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_pow_cmd_fpcepc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_pow_cmd_powlev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_pow_cmd_and_acc_type(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_pow_cmd_atc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_pow_cmd_epc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_pow_cmd_fpcepc, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_pow_cmd_powlev, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_rach_ctrl_param(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_max_retrans, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_tx_integer, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_cell_barr_access, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_re, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
proto_tree_add_item(subtree, hf_gsm_a_rr_acc, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 2;
return(curr_offset - offset);
}
static guint16 reduced_frame_number(guint16 fn)
{
gint16 t2, t3, t;
guint16 frame, t1;
t1 = (fn >> 11) & 0x1f;
t2 = (fn >> 0) & 0x1f;
t3 = (fn >> 5) & 0x3f;
t = (t3-t2)%26;
if (t<0)
t += 26;
frame = 51*(unsigned)t+(unsigned)t3+51*26*t1;
return frame;
}
static guint16
de_rr_req_ref(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
guint32 curr_offset;
guint16 rfn;
guint16 fn;
curr_offset = offset;
proto_tree_add_item(subtree, hf_gsm_a_rr_ra, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
fn = tvb_get_ntohs(tvb,curr_offset);
rfn = reduced_frame_number(fn);
proto_tree_add_item(subtree, hf_gsm_a_rr_T1prim, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(subtree, hf_gsm_a_rr_T3, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(subtree, hf_gsm_a_rr_T2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
item = proto_tree_add_uint(subtree, hf_gsm_a_rr_rfn, tvb, curr_offset-2, 2, rfn);
PROTO_ITEM_SET_GENERATED(item);
return(curr_offset - offset);
}
guint16
de_rr_cause(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_RR_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_rr_si1_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
guint8 tvb_len = tvb_length(tvb);
curr_offset = offset;
bit_offset = curr_offset << 3;
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "NCH position", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_nch_position, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
}
gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Band Indicator", "1900", "1800");
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_si2ter_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *subtree2;
proto_item *item2;
guint32 curr_offset;
gint bit_offset, bit_offset_sav;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
curr_offset = offset;
bit_offset = curr_offset<<3;
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "MP Changemark", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si2ter_mp_change_mark, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si2ter_3g_change_mark, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si2ter_index, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si2ter_count, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "UTRAN FDD Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_FDD_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_UTRAN_FDD_DESC]);
gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "Bit reserved for earlier version of protocol", "Earlier version", "Current version");
gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "Bit reserved for earlier version of protocol", "Current version", "Earlier version");
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_uarfcn, tvb, bit_offset, 14, ENC_BIG_ENDIAN);
bit_offset += 14;
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "Bandwidth FDD", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_bandwidth_fdd, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
proto_item_set_len(item2,(bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "UTRAN TDD Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_TDD_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_UTRAN_TDD_DESC]);
gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "Bit reserved for earlier version of protocol", "Earlier version", "Current version");
gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "Bit reserved for earlier version of protocol", "Current version", "Earlier version");
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_tdd_uarfcn, tvb, bit_offset, 14, ENC_BIG_ENDIAN);
bit_offset += 14;
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "Bandwidth TDD", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_bandwidth_tdd, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
proto_item_set_len(item2,(bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Measurement Parameters Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_MEAS_PARAM_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_MEAS_PARAM_DESC]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_qsearch_i, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "FDD Parameters", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_qoffset, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_qmin, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "TDD Parameters", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_tdd_qoffset, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
}
proto_item_set_len(item2,(bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (bit_len - bit_offset > 0)
{
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Additions in Rel-5", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Additional Measurement Parameters Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_ADD_MEAS_PARAM_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_ADD_MEAS_PARAM_DESC]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_qmin_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_rscpmin, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_item_set_len(item2,(bit_offset>>3) - (bit_offset_sav>>3)+1);
}
}
}
}
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static gint
de_rr_si2quater_meas_info_utran_fdd_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree, *subtree2;
proto_item *item, *item2;
gint curr_bit_offset, idx;
gint xdd_cell_info, wsize, nwi, jwi, w[64], i, iused, xdd_indic0;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_FDD_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_UTRAN_FDD_DESC]);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Bandwidth FDD", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bandwidth_fdd, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated UMTS FDD Neighbour Cells", "Present", "Not Present"))
{
gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Bit reserved for earlier version of protocol", "Earlier version", "Current version");
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_fdd_uarfcn, tvb, curr_bit_offset, 14, ENC_BIG_ENDIAN);
curr_bit_offset += 14;
xdd_indic0 = gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "the FDD_CELL_INFORMATION parameter value '0000000000' ", "is a member of the set", "is not a member of the set");
idx = tvb_get_bits8(tvb,curr_bit_offset,5);
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 1, "Nr of FDD Cells : %d", idx);
curr_bit_offset += 5;
idx = convert_n_to_p[idx];
item2 = proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, (idx>>3)+1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_FDD_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_FDD_CELL_INFORMATION_FIELD]);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, (idx>>3)+1, "Field is %d bits long", idx);
if (xdd_indic0)
{
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Scrambling Code: %d", 0);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Diversity: %d", 0);
}
if (idx)
{
wsize = 10;
nwi = 1;
jwi = 0;
i = 1;
while (idx > 0)
{
w[i] = tvb_get_bits(tvb, curr_bit_offset, wsize, ENC_BIG_ENDIAN);
curr_bit_offset += wsize;
idx -= wsize;
if (w[i] == 0)
{
idx = 0;
break;
}
if (++jwi == nwi)
{
jwi = 0;
nwi <<= 1;
wsize--;
}
i++;
}
if (idx < 0)
{
curr_bit_offset += idx;
}
iused = i-1;
for (i=1; i <= iused; i++)
{
xdd_cell_info = f_k(i, w, 1024);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Scrambling Code: %d", xdd_cell_info & 0x01FF);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Diversity: %d", (xdd_cell_info >> 9) & 0x01);
}
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_si2quater_meas_info_utran_tdd_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree, *subtree2;
proto_item *item, *item2;
gint curr_bit_offset, idx;
gint xdd_cell_info, wsize, nwi, jwi, w[64], i, iused, xdd_indic0;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_TDD_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_UTRAN_TDD_DESC]);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Bandwidth TDD", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bandwidth_tdd, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated UMTS TDD Neighbour Cells", "Present", "Not Present"))
{
gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Bit reserved for earlier version of protocol", "Earlier version", "Current version");
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tdd_uarfcn, tvb, curr_bit_offset, 14, ENC_BIG_ENDIAN);
curr_bit_offset += 14;
xdd_indic0 = gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "the FDD_CELL_INFORMATION parameter value '0000000000' ", "is a member of the set", "is not a member of the set");
idx = tvb_get_bits8(tvb,curr_bit_offset,5);
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 1, "Nr of TDD Cells : %d", idx);
curr_bit_offset += 5;
idx = convert_n_to_q[idx];
item2 = proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, (idx>>3)+1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_TDD_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_TDD_CELL_INFORMATION_FIELD]);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, (idx>>3)+1, "Field is %d bits long", idx);
if (xdd_indic0)
{
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Cell Parameter: %d", 0);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Sync Case TSTD: %d", 0);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Diversity TDD: %d", 0);
}
if (idx)
{
wsize = 9;
nwi = 1;
jwi = 0;
i = 1;
while (idx > 0)
{
w[i] = tvb_get_bits(tvb, curr_bit_offset, wsize, ENC_BIG_ENDIAN);
curr_bit_offset += wsize;
idx -= wsize;
if (w[i] == 0)
{
idx = 0;
break;
}
if (++jwi == nwi)
{
jwi = 0;
nwi <<= 1;
wsize--;
}
i++;
}
if (idx < 0)
{
curr_bit_offset += idx;
}
iused = i-1;
for (i=1; i <= iused; i++)
{
xdd_cell_info = f_k(i, w, 512);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Cell Parameter: %d", xdd_cell_info & 0x07F);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Sync Case TSTD: %d", (xdd_cell_info >> 7) & 0x01);
proto_tree_add_text(subtree2,tvb, curr_bit_offset>>3, 0, "Diversity TDD: %d", (xdd_cell_info >> 8) & 0x01);
}
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_rtd_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset, rr_rest_octets_elem_idx_t id)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset, idx;
guint8 value;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[id].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[id]);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "RTD6", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "BA Index Start RTD", "Present", "Not Present"))
{
idx = tvb_get_bits8(tvb,curr_bit_offset,5);
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 1, "BA Index Start RTD: %d", idx);
curr_bit_offset += 5;
}
else
idx = 0;
value = gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "RTD", "Not Present", "Present");
while (value == 0)
{
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 1, "RTD index %d: %d TDMA frame(s) modulo 51 TDMA frames", idx, tvb_get_bits8(tvb,curr_bit_offset,6));
curr_bit_offset += 6;
value = gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "additional RTD", "Not Present", "Present");
}
value = gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "additional RTD struct", "Not Present", "Present");
while(value == 0)
{
idx += 1;
value = gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "RTD", "Not Present", "Present");
while (value == 0)
{
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 1, "RTD index %d: %d TDMA frame(s) modulo 51 TDMA frames", idx, tvb_get_bits8(tvb,curr_bit_offset,6));
curr_bit_offset += 6;
value = gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "additional RTD", "Not Present", "Present");
}
value = gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "additional RTD struct", "Not Present", "Present");
}
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "RTD12", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "RTD12", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "BA Index Start RTD", "Present", "Not Present"))
{
idx = tvb_get_bits8(tvb,curr_bit_offset,5);
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 1, "BA Index Start RTD: %d", idx);
curr_bit_offset += 5;
}
else
idx = 0;
while (0 == gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated RTD", "Not Present", "Present"))
{
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 2, "RTD index %d: %d/64 TDMA frame(s) modulo 51 TDMA frames", idx, tvb_get_bits16(tvb,curr_bit_offset,12,ENC_BIG_ENDIAN));
curr_bit_offset += 12;
}
while(0 == gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated RTD Frequency", "Not Present", "Present"))
{
idx += 1;
while (0 == gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated RTD", "Not Present", "Present"))
{
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 2, "RTD index %d: %d/64 TDMA frame(s) modulo 51 TDMA frames", idx, tvb_get_bits16(tvb,curr_bit_offset,12,ENC_BIG_ENDIAN));
curr_bit_offset += 12;
}
}
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_bsic_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset, rr_rest_octets_elem_idx_t id)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset, idx;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[id].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[id]);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "BA Index Start BSIC", "Present", "Not Present"))
{
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 1, "BA Index Start BSIC: %d", tvb_get_bits8(tvb,curr_bit_offset,5));
curr_bit_offset += 5;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bsic, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
idx = tvb_get_bits8(tvb,curr_bit_offset,7);
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 1, "Number Remaining BSIC: %d", idx);
curr_bit_offset += 7;
while (idx)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_frequency_scrolling, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bsic, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
idx -= 1;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_report_priority_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset, rr_rest_octets_elem_idx_t id)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset, idx;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[id].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[id]);
idx = tvb_get_bits8(tvb,curr_bit_offset,7);
proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, 1, "Number Cells: %d", idx);
curr_bit_offset += 7;
while (idx)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rep_priority, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
idx -= 1;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_meas_param_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset, rr_rest_octets_elem_idx_t id)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[id].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[id]);
if (id == DE_RR_REST_OCTETS_GPRS_MEAS_PARAM_DESC)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_report_type, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_reporting_rate, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset +=1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_invalid_bsic_reporting, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset +=1;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Multiband Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_multiband_reporting, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Serving Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_serving_band_reporting, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_scale_ord, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "900 Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_900_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_900_reporting_threshold, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "1800 Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_1800_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_1800_reporting_threshold, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "400 Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_400_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_400_reporting_threshold, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "1900 Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_1900_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_1900_reporting_threshold, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "850 Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_850_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_850_reporting_threshold, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_3g_add_meas_param_desc2(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_ADD_MEAS_PARAM_DESC2].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_ADD_MEAS_PARAM_DESC2]);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "FDD Reporting Threshold2", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_fdd_reporting_threshold_2, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_3g_priority_param_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_PRIORITY_PARAM_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_PRIORITY_PARAM_DESC]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_priority_param_desc_utran_start, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_priority_param_desc_utran_stop, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Default UTRAN Priority Parameters", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_priority_param_desc_default_utran_prio, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_priority_param_desc_default_threshold_utran, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_priority_param_desc_default_utran_qrxlevmin, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated UTRAN Priority Parameters", "Present", "Not Present"))
{
proto_tree *subtree_rep_utran_prio;
proto_item *item_rep_utran_prio;
gint rep_utran_prio_bit_offset = curr_bit_offset;
item_rep_utran_prio = proto_tree_add_text(subtree, tvb, curr_bit_offset>>3, 1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_PRIO_PARAM].strptr);
subtree_rep_utran_prio = proto_item_add_subtree(item_rep_utran_prio, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_UTRAN_PRIO_PARAM]);
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "UTRAN Frequency Index", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree_rep_utran_prio, hf_gsm_a_rr_utran_frequency_index, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "UTRAN Priority", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree_rep_utran_prio, hf_gsm_a_rr_utran_priority, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
proto_tree_add_bits_item(subtree_rep_utran_prio, hf_gsm_a_rr_thresh_utran_high, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Threshold UTRAN Low", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree_rep_utran_prio, hf_gsm_a_rr_thresh_utran_low, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "UTRAN Qrxlev Min", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree_rep_utran_prio, hf_gsm_a_rr_utran_qrxlevmin, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
proto_item_set_len(item_rep_utran_prio, (curr_bit_offset>>3) - (rep_utran_prio_bit_offset>>3)+1);
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_neighbour_cells(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EUTRAN_NEIGHBOUR_CELLS].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EUTRAN_NEIGHBOUR_CELLS]);
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN Neighbour Cells Struct", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_earfcn, tvb, curr_bit_offset, 16, ENC_BIG_ENDIAN);
curr_bit_offset += 16;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Measurement Bandwidth", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_measurement_bandwidth, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN Priority", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_priority, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_thresh_eutran_high, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Threshold E-UTRAN Low", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_thresh_eutran_low, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN Qrxlev Min", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_qrxlevmin, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_neighbour_cells_mi(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EUTRAN_NEIGHBOUR_CELLS].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EUTRAN_NEIGHBOUR_CELLS]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_earfcn, tvb, curr_bit_offset, 16, ENC_BIG_ENDIAN);
curr_bit_offset += 16;
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated EARFCN", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_earfcn, tvb, curr_bit_offset, 16, ENC_BIG_ENDIAN);
curr_bit_offset += 16;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Measurement Bandwidth ", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_measurement_bandwidth, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_pcid(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
gint curr_bit_offset = bit_offset;
proto_item *item;
while (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "Repeated PCID", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_pcid, tvb, curr_bit_offset, 9, ENC_BIG_ENDIAN);
curr_bit_offset += 9;
}
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "PCID Bitmap Group", "Present", "Not Present"))
{
gint i;
guint8 bitmap = tvb_get_bits8(tvb,curr_bit_offset,6);
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_pcid_bitmap_group, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
if (bitmap > 0)
{
proto_item_append_text(item, ": Cells IDs addressed by the bitmap:");
}
for (i = 0; i < 6; i++)
{
if ((1 << i) & bitmap)
{
if ( i != 0)
{
proto_item_append_text(item, ",");
}
proto_item_append_text(item, " %d to %d",i*84, (i+1)*84 - 1);
}
}
curr_bit_offset += 6;
}
while (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "PCID Pattern", "Present", "Not Present"))
{
gint pcid_pattern_length;
gint pcid_pattern;
gint pattern_lower_bound, pattern_upper_bound;
gint i;
pcid_pattern_length = tvb_get_bits8(tvb,curr_bit_offset,3) + 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_pcid_pattern_length, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
pcid_pattern = tvb_get_bits8(tvb,curr_bit_offset, pcid_pattern_length);
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, 1, "%s = PCID_Pattern: %d",
decode_bits_in_field(curr_bit_offset,pcid_pattern_length, pcid_pattern),
pcid_pattern);
pattern_lower_bound = pcid_pattern << (9 - pcid_pattern_length);
pattern_upper_bound = pattern_lower_bound;
for (i = 0; i < (9-pcid_pattern_length); i++)
{
pattern_upper_bound |= 1 << i;
}
proto_item_append_text(item, ": Cells IDs addressed by the pattern: %d to %d", pattern_lower_bound, pattern_upper_bound);
curr_bit_offset += pcid_pattern_length;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_pcid_pattern_sense, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_not_allowed_cells(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EUTRAN_NOT_ALLOWED_CELLS].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EUTRAN_NOT_ALLOWED_CELLS]);
curr_bit_offset += de_rr_eutran_pcid(tvb, subtree, curr_bit_offset);
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated E-UTRAN Frequency Index", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_frequency_index, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_pcid_to_ta_mapping(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EUTRAN_PCID_TO_TA_MAPPING].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EUTRAN_PCID_TO_TA_MAPPING]);
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeating PCID group", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_pcid(tvb, subtree, curr_bit_offset);
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_measurement_param_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
gint curr_bit_offset;
proto_item *item;
guint8 rep_quant;
curr_bit_offset = bit_offset;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_qsearch_c_eutran_initial, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
rep_quant = gsm_rr_csn_flag(tvb, tree, curr_bit_offset, "E-UTRAN Reporting Quantity", "RSRQ", "RSRP");
curr_bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_multirat_reporting, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
if (!gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "Reporting", "3 bit", "6 bit"))
{
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-UTRAN FDD FDD 3 bit Reporting", "Present", "Not Present"))
{
if (rep_quant == 0)
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_fdd_reporting_threshold_rsrp, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_fdd_reporting_threshold_rsrq, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
}
curr_bit_offset += 3;
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-UTRAN FDD Reporting Threshold2", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_fdd_reporting_threshold_2, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
if (rep_quant == 0)
{
proto_item_append_text(item, " (%.1f dB)", (gfloat)tvb_get_bits8(tvb,curr_bit_offset,6)/2 - 19.5);
}
else
{
proto_item_append_text(item, " (%d dBm)", tvb_get_bits8(tvb,curr_bit_offset,6) - 140);
}
curr_bit_offset += 6;
}
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-EUTRAN FDD Reporting Offset", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_fdd_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
}
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-UTRAN TDD TDD 3 bit Reporting", "Present", "Not Present"))
{
if (rep_quant == 0)
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_tdd_reporting_threshold_rsrp, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_tdd_reporting_threshold_rsrq, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
}
curr_bit_offset += 3;
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-UTRAN TDD Reporting Threshold2", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_tdd_reporting_threshold_2, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
if (rep_quant == 0)
{
proto_item_append_text(item, " (%.1f dB)", (gfloat)tvb_get_bits8(tvb,curr_bit_offset,6)/2 - 19.5);
}
else
{
proto_item_append_text(item, " (%d dBm)", tvb_get_bits8(tvb,curr_bit_offset,6) - 140);
}
curr_bit_offset += 6;
}
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-EUTRAN TDD Reporting Offset", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_tdd_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
}
}
else
{
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-EUTRAN FDD Reporting Threshold", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_fdd_measurement_report_offset, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
if (rep_quant == 0)
{
proto_item_append_text(item, " (%d dBm)", tvb_get_bits8(tvb,curr_bit_offset,6) - 140);
}
else
{
proto_item_append_text(item, " (%.1f dB)", (gfloat)tvb_get_bits8(tvb,curr_bit_offset,6)/2 - 19.5);
}
curr_bit_offset += 6;
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-UTRAN FDD Reporting Threshold2", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_fdd_reporting_threshold_2, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
if (rep_quant == 0)
{
proto_item_append_text(item, " (%.1f dB)", (gfloat)tvb_get_bits8(tvb,curr_bit_offset,6)/2 - 19.5);
}
else
{
proto_item_append_text(item, " (%d dBm)", tvb_get_bits8(tvb,curr_bit_offset,6) - 140);
}
curr_bit_offset += 6;
}
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-UTRAN FDD Reporting Offset", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_fdd_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
}
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-UTRAN TDD Reporting Offset", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_tdd_measurement_report_offset, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
if (rep_quant == 0)
{
proto_item_append_text(item, " (%d dBm)", tvb_get_bits8(tvb,curr_bit_offset,6) - 140);
}
else
{
proto_item_append_text(item, " (%.1f dB)", (gfloat)tvb_get_bits8(tvb,curr_bit_offset,6)/2 - 19.5);
}
curr_bit_offset += 6;
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-UTRAN TDD Reporting Threshold2", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_tdd_reporting_threshold_2, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
if (rep_quant == 0)
{
proto_item_append_text(item, " (%.1f dB)", (gfloat)tvb_get_bits8(tvb,curr_bit_offset,6)/2 - 19.5);
}
else
{
proto_item_append_text(item, " (%d dBm)", tvb_get_bits8(tvb,curr_bit_offset,6) - 140);
}
curr_bit_offset += 6;
}
if (gsm_rr_csn_flag(tvb, tree, curr_bit_offset++, "E-UTRAN TDD Reporting Offset", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_tdd_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
}
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_reporting_granularity, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
if (rep_quant == 0)
{
proto_item_append_text(item, " (%d dB step)", 2 + tvb_get_bits8(tvb,curr_bit_offset,1));
}
else
{
proto_item_append_text(item, " (%d dB step)", 1 + tvb_get_bits8(tvb,curr_bit_offset,1));
}
curr_bit_offset += 1;
}
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_param_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
guint8 rep_quant = 0;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EUTRAN_PARAM_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EUTRAN_PARAM_DESC]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_ccn_active, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_start, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_stop, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN Measurement Parameters Description", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_measurement_param_desc(tvb, subtree, curr_bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "GPRS E-UTRAN Measurement Parameters Description", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_qsearch_p_eutran, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
rep_quant = gsm_rr_csn_flag(tvb, subtree, curr_bit_offset, "E-UTRAN Reporting Quantity", "RSRQ", "RSRP");
curr_bit_offset++;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_multirat_reporting, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN FDD Reporting", "Present", "Not Present"))
{
if (rep_quant == 0)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_fdd_reporting_threshold_rsrp, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_fdd_reporting_threshold_rsrq, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
}
curr_bit_offset += 3;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN FDD Reporting Threshold 2", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_fdd_reporting_threshold_2, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
if (rep_quant == 0)
{
proto_item_append_text(item, " (%.1f dB)", (gfloat)tvb_get_bits8(tvb,curr_bit_offset,6)/2 - 19.5);
}
else
{
proto_item_append_text(item, " (%d dBm)", tvb_get_bits8(tvb,curr_bit_offset,6) - 140);
}
curr_bit_offset += 6;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN FDD Reporting Offset", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_fdd_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN TDD Reporting", "Present", "Not Present"))
{
if (rep_quant == 0)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_tdd_reporting_threshold_rsrp, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_tdd_reporting_threshold_rsrq, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
}
curr_bit_offset += 3;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN TDD Reporting Threshold 2", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_tdd_reporting_threshold_2, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
if (rep_quant == 0)
{
proto_item_append_text(item, " (%.1f dB)", (gfloat)tvb_get_bits8(tvb,curr_bit_offset,6)/2 - 19.5);
}
else
{
proto_item_append_text(item, " (%d dBm)", tvb_get_bits8(tvb,curr_bit_offset,6) - 140);
}
curr_bit_offset += 6;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN TDD Reporting Offset", "Present", "Not Present"))
{
item = proto_tree_add_bits_item(tree, hf_gsm_a_rr_eutran_tdd_reporting_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
}
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated E-UTRAN Neighbour Cells", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_neighbour_cells(tvb, subtree, curr_bit_offset);
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated E-UTRAN Not Allowed Cells", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_not_allowed_cells(tvb, subtree, curr_bit_offset);
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated E-UTRAN PCID to TA mapping", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_pcid_to_ta_mapping(tvb, subtree, curr_bit_offset);
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_param_desc_mi(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EUTRAN_PARAM_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EUTRAN_PARAM_DESC]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_start, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_stop, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN Measurement Parameters Description", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_measurement_param_desc(tvb, subtree, curr_bit_offset);
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated E-UTRAN Neighbour Cells", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_neighbour_cells_mi(tvb, subtree, curr_bit_offset);
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated E-UTRAN Not Allowed Cells", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_not_allowed_cells(tvb, subtree, curr_bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Measurement Control Parameters Description", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Default Measurement Control E-UTRAN", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_default_measurement_control_eutran, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated E-UTRAN Measurement Control Parameters", "Present", "Not Present"))
{
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated E-UTRAN Frequency Index", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_frequency_index, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_measurement_control_eutran, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_priority_and_eutran_param_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_PRIORITY_AND_EUTRAN_PARAM_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_PRIORITY_AND_EUTRAN_PARAM_DESC]);
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Serving Cell Priority Parameters Description", "Present", "Not Present"))
{
proto_tree *subtree_serv;
proto_item *item_serv;
gint serv_bit_offset = curr_bit_offset;
item_serv = proto_tree_add_text(subtree, tvb, curr_bit_offset>>3, ((curr_bit_offset+15)>>3)-(curr_bit_offset>>3) + 1 , "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_SERVING_CELL_PRIORITY_PARAM_DESC].strptr);
subtree_serv = proto_item_add_subtree(item_serv, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_SERVING_CELL_PRIORITY_PARAM_DESC]);
proto_tree_add_bits_item(subtree_serv, hf_gsm_a_rr_serving_cell_priority_param_geran_priority, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree_serv, hf_gsm_a_rr_serving_cell_priority_param_thresh_prio_search, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_tree_add_bits_item(subtree_serv, hf_gsm_a_rr_serving_cell_priority_param_thresh_gsm_low, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
proto_tree_add_bits_item(subtree_serv, hf_gsm_a_rr_serving_cell_priority_param_h_prio, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
proto_tree_add_bits_item(subtree_serv, hf_gsm_a_rr_serving_cell_priority_param_t_reselection, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
proto_item_set_len(item_serv, (curr_bit_offset>>3) - (serv_bit_offset>>3)+1);
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "3G Priority Parameters Description", "Present", "Not Present"))
{
curr_bit_offset += de_rr_3g_priority_param_desc(tvb, subtree, curr_bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "E-UTRAN Parameters Description", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_param_desc(tvb, subtree, curr_bit_offset);
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_3g_csg_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_CSG_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_CSG_DESC]);
while (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Repeated CSG_PSC_SPLIT struct", "Present", "Not Present"))
{
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "PSC", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_psc, tvb, curr_bit_offset, 9, ENC_BIG_ENDIAN);
curr_bit_offset += 9;
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "PSC Pattern", "Present", "Not Present"))
{
gint psc_pattern_length;
gint psc_pattern;
psc_pattern_length = tvb_get_bits8(tvb,curr_bit_offset,3) + 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_utran_psc_pattern_length, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
psc_pattern = tvb_get_bits8(tvb,curr_bit_offset, psc_pattern_length);
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, 1, "%s = PSC_Pattern: %d",
decode_bits_in_field(curr_bit_offset,psc_pattern_length, psc_pattern),
psc_pattern);
curr_bit_offset += psc_pattern_length;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_utran_psc_pattern_sense, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated UTRAN Frequency Index", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_utran_frequency_index, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
}
while(gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "repeated CSG FDD UARFCN", "Present", "Not Present"))
{
if (!gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Technology", "TDD", "FDD"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_utran_csg_fdd_uarfcn, tvb, curr_bit_offset, 14, ENC_BIG_ENDIAN);
curr_bit_offset += 14;
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_utran_csg_tdd_uarfcn, tvb, curr_bit_offset, 14, ENC_BIG_ENDIAN);
curr_bit_offset += 14;
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_csg_desc(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EUTRAN_CSG_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EUTRAN_CSG_DESC]);
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated PCID group", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_pcid(tvb, subtree, curr_bit_offset);
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated EARFCN", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_csg_earfcn, tvb, curr_bit_offset, 16, ENC_BIG_ENDIAN);
curr_bit_offset += 16;
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_eutran_csg_desc_mi(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EUTRAN_CSG_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EUTRAN_CSG_DESC]);
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated CSG PCI Split", "Present", "Not Present"))
{
curr_bit_offset += de_rr_eutran_pcid(tvb, subtree, curr_bit_offset);
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_utran_measurement_control_param_mi(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_UTRAN_MEASUREMENT_CONTROL_PARAM_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_UTRAN_MEASUREMENT_CONTROL_PARAM_DESC]);
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated UTRAN Frequency Index", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_utran_frequency_index, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_control_param_desc_meas_ctrl_utran, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static gint
de_rr_3g_supplementary_param_desc_mi(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_SUPPLEMENTARY_PARAM_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_SUPPLEMENTARY_PARAM_DESC]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_priority_param_desc_utran_start, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_priority_param_desc_utran_stop, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "3G Measurement Control Parameters Description", "Present", "Not Present"))
{
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "3G Measurement Control Parameters Description struct", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_control_param_desc_meas_ctrl_utran, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
}
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "Repeated UTRAN Measurement Control Parameters struct", "Present", "Not Present"))
{
curr_bit_offset += de_rr_utran_measurement_control_param_mi(tvb, subtree, curr_bit_offset);
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return(curr_bit_offset - bit_offset);
}
static guint16
de_rr_si2quater_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *subtree2, *subtree3;
proto_item *item2, *item3;
guint32 curr_offset;
gint bit_offset, bit_offset_sav, idx;
guint8 value;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
curr_offset = offset;
bit_offset = curr_offset << 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_ba_ind, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_ba_ind, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_mp_change_mark, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si2quater_index, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si2quater_count, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Measurement Parameters Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_MEAS_PARAM_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_MEAS_PARAM_DESC]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_gsm_report_type, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_serving_band_reporting, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "GPRS Real Time Difference Description", "Present", "Not Present"))
{
bit_offset += de_rr_rtd_desc(tvb, subtree, bit_offset, DE_RR_REST_OCTETS_GPRS_RTD_DESC);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "GPRS BSIC Description", "Present", "Not Present"))
{
bit_offset += de_rr_bsic_desc(tvb, subtree, bit_offset, DE_RR_REST_OCTETS_GPRS_BSIC_DESC);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "GPRS Report Priority Description", "Present", "Not Present"))
{
bit_offset += de_rr_report_priority_desc(tvb, subtree, bit_offset, DE_RR_REST_OCTETS_GPRS_REPORT_PRIO_DESC);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "GPRS Measurement Parameters Description", "Present", "Not Present"))
{
bit_offset += de_rr_meas_param_desc(tvb, subtree, bit_offset, DE_RR_REST_OCTETS_GPRS_MEAS_PARAM_DESC);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "NC Measurement Parameters", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_NC_MEAS_PARAM].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_NC_MEAS_PARAM]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_network_control_order, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "NC Periods", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_nc_non_drx_period, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_nc_reporting_period_i, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_nc_reporting_period_t, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "SI 2quater Extension Information", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_SI2Q_EXT_INFO].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_SI2Q_EXT_INFO]);
idx = tvb_get_bits8(tvb,bit_offset,8);
proto_tree_add_text(subtree2,tvb, bit_offset>>3, 1, "Extension Length: %d", idx);
bit_offset += 8;
proto_item_set_len(item2,((bit_offset+idx+1)>>3) - (bit_offset_sav>>3)+1);
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "CCN Support Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item3 = proto_tree_add_text(subtree2, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_CCN_SUPPORT_DESC].strptr);
subtree3 = proto_item_add_subtree(item3, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_CCN_SUPPORT_DESC]);
value = tvb_get_bits8(tvb,bit_offset,7);
proto_tree_add_text(subtree3,tvb, bit_offset>>3, 1, "Number Cells: %d", value);
bit_offset += 7;
idx -= 7;
item2 = proto_tree_add_text(subtree3,tvb, bit_offset>>3, (value>>3)+1, "CCN Supported: ");
while (value)
{
proto_item_append_text(item2,"%d",tvb_get_bits8(tvb,bit_offset,1));
bit_offset += 1;
value -= 1;
idx -= 1;
}
proto_item_set_len(item3, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
bit_offset += idx;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Neighbour Cell Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_NEIGH_CELL_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_NEIGH_CELL_DESC]);
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "Index Start 3G", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_index_start_3g, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
}
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "Absolute Index Start EMR", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_absolute_index_start_emr, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
}
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "UTRAN FDD Description", "Present", "Not Present"))
{
bit_offset += de_rr_si2quater_meas_info_utran_fdd_desc(tvb, subtree2, bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "UTRAN TDD Description", "Present", "Not Present"))
{
bit_offset += de_rr_si2quater_meas_info_utran_tdd_desc(tvb, subtree2, bit_offset);
}
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Measurement Parameters Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_MEAS_PARAM_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_MEAS_PARAM_DESC]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_qsearch_i, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_qsearch_c_initial, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "FDD Information", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_qoffset, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_rep_quant, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_multirat_reporting, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_qmin, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "TDD Information", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_tdd_qoffset, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_tdd_multirat_reporting, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "GPRS 3G Measurement Parameters Description", "Present", "Not Present"))
{
guint8 reporting_quant = 0;
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_GPRS_3G_MEAS_PARAM_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_GPRS_3G_MEAS_PARAM_DESC]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_qsearch_p, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_3g_search_prio, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "FDD Parameters", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_rep_quant, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
reporting_quant = gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "Reporting Quantity", "Ec/No", "RSCP");
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_multirat_reporting, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "FDD Reporting Parameters", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_reporting_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
if (reporting_quant == 0)
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_reporting_threshold_rscp, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_reporting_threshold_ecn0, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "TDD Multirat Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_tdd_multirat_reporting, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
if (gsm_rr_csn_flag(tvb, subtree2, bit_offset++, "TDD Reporting Parameters", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_tdd_reporting_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
if (reporting_quant == 0)
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_tdd_reporting_threshold_rscp, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_tdd_reporting_threshold_ecn0, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
bit_offset += 3;
}
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (bit_len - bit_offset > 0)
{
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Additions in Rel-5", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Additional Measurement Parameters Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_ADD_MEAS_PARAM_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_ADD_MEAS_PARAM_DESC]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_qmin_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_fdd_rscpmin, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Additional Measurement Parameters Description 2", "Present", "Not Present"))
{
bit_offset += de_rr_3g_add_meas_param_desc2(tvb, subtree, bit_offset);
}
if (bit_len - bit_offset > 0)
{
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Additions in Rel-6", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_ccn_active, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
if (bit_len - bit_offset > 0)
{
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Additions in Rel-7", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "700 Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_700_reporting_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_700_reporting_threshold, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "810 Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_810_reporting_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_810_reporting_threshold, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
if (bit_len - bit_offset > 0)
{
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Additions in Rel-8", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Supplementary Parameters Description ", "Present", "Not Present"))
{
bit_offset += de_rr_priority_and_eutran_param_desc(tvb, subtree, bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G CSG Description ", "Present", "Not Present"))
{
bit_offset += de_rr_3g_csg_desc(tvb, subtree, bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "EUTRAN CSG Description ", "Present", "Not Present"))
{
bit_offset += de_rr_eutran_csg_desc(tvb, subtree, bit_offset);
}
}
}
}
}
}
}
}
}
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static gint
de_rr_rest_oct_opt_sel_param(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
if (gsm_rr_csn_HL_flag(tvb, tree, 0, curr_bit_offset++, "Selection Parameters", "Present", "Not present"))
{
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_OPTIONAL_SEL_PARAM].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_OPTIONAL_SEL_PARAM]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_cbq, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_cell_reselect_offset, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_temporary_offset, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_penalty_time, tvb, curr_bit_offset, 5, ENC_BIG_ENDIAN);
curr_bit_offset += 5;
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
}
return (curr_bit_offset - bit_offset);
}
static gint
de_rr_rest_oct_gprs_indicator(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, 1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_GPRS_INDICATOR].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_GPRS_INDICATOR]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_gprs_ra_colour, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si13_position, tvb, curr_bit_offset, 1, ENC_BIG_ENDIAN);
curr_bit_offset += 1;
return (curr_bit_offset - bit_offset);
}
static guint16
de_rr_si3_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset;
gboolean gprs_indicator;
guint8 tvb_len = tvb_length(tvb);
curr_offset = offset;
bit_offset = curr_offset << 3;
bit_offset += de_rr_rest_oct_opt_sel_param(tvb, subtree, bit_offset);
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Optional Power Offset", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_power_offset, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "SYSTEM INFORMATION TYPE 2ter", "Available", "Not Available");
gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Early Classmark Sending", "Is allowed", "Is forbidden");
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Scheduling if and where", "Present", "Not present"))
{
proto_tree_add_text(subtree, tvb, bit_offset>>3, 1, "Where: %d",tvb_get_bits8(tvb,bit_offset,3));
bit_offset += 3;
}
gprs_indicator = gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "GPRS Indicator", "Present", "Not present");
if (gprs_indicator)
{
bit_offset += de_rr_rest_oct_gprs_indicator(tvb, subtree, bit_offset);
}
gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "3G Early Classmark Sending Restriction",
"The sending of UTRAN,CDMA2000 and GERAN IU MODE CLASSMARK CHANGE messages are controlled by the Early Classmark Sending Control parameter",
"Neither UTRAN, CDMA2000 nor GERAN IU MODE CLASSMARK CHANGE message shall be sent with the Early classmark sending");
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "SI2quater Indicator", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si2quater_position, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
}
if (gprs_indicator == FALSE)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si13alt_position, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
}
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_si4_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
proto_tree *subtree2, *subtree3;
proto_item *item2, *item3;
guint32 curr_offset;
gint bit_offset, bit_offset_sav;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
curr_offset = offset;
bit_offset = curr_offset << 3;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_SI4_REST_OCTETS_O].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_SI4_REST_OCTETS_O]);
bit_offset += de_rr_rest_oct_opt_sel_param(tvb, subtree2, bit_offset);
if (gsm_rr_csn_HL_flag(tvb, subtree2, bit_len, bit_offset++, "Optional Power Offset", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_power_offset, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
if (gsm_rr_csn_HL_flag(tvb, subtree2, bit_len, bit_offset++, "GPRS Indicator", "Present", "Not present"))
{
bit_offset += de_rr_rest_oct_gprs_indicator(tvb, subtree2, bit_offset);
}
proto_item_set_len(item2,(bit_offset>>3) + 1 - curr_offset);
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "SI4 Rest Octets_S", "Present", "Not present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_SI4_REST_OCTETS_S].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_SI4_REST_OCTETS_S]);
if (gsm_rr_csn_HL_flag(tvb, subtree2, bit_len, bit_offset++, "LSA Parameters", "Present", "Not present"))
{
item3 = proto_tree_add_text(subtree2, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_LSA_PARAMETERS].strptr);
subtree3 = proto_item_add_subtree(item3, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_LSA_PARAMETERS]);
proto_tree_add_bits_item(subtree3, hf_gsm_a_rr_prio_thr, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree3, hf_gsm_a_rr_lsa_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
if (gsm_rr_csn_flag(tvb,subtree3, bit_offset++,"MCC/MNC", "Present", "Not Present"))
{
proto_tree_add_text(subtree3, tvb, bit_offset>>3, 2, "MCC: %d", tvb_get_bits16(tvb,bit_offset,12,ENC_BIG_ENDIAN));
bit_offset += 12;
proto_tree_add_text(subtree3, tvb, bit_offset>>3, 2, "MNC: %d", tvb_get_bits16(tvb,bit_offset,12,ENC_BIG_ENDIAN));
bit_offset += 12;
}
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_HL_flag(tvb, subtree2, bit_len, bit_offset++, "Cell Identity", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_cell_id, tvb, bit_offset, 16, ENC_BIG_ENDIAN);
bit_offset += 16;
}
if (gsm_rr_csn_HL_flag(tvb, subtree2, bit_len, bit_offset++, "LSA ID information", "Present", "Not present"))
{
item3 = proto_tree_add_text(subtree2, tvb, bit_offset>>3, len, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_LSA_ID_INFO].strptr);
subtree3 = proto_item_add_subtree(item3, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_LSA_ID_INFO]);
do
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Type", "Short LSA ID", "LSA ID"))
{
proto_tree_add_text(subtree3, tvb, bit_offset>>3, 3, "Short LSA ID: %d",tvb_get_bits16(tvb,bit_offset,10,ENC_BIG_ENDIAN));
bit_offset += 10;
}
else
{
proto_tree_add_text(subtree3, tvb, bit_offset>>3, 3, "LSA ID: %d",tvb_get_bits32(tvb,bit_offset,24,ENC_BIG_ENDIAN));
bit_offset += 24;
}
} while (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Additional LSA ID", "Present", "Not Present"));
}
if (gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "CBQ3", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_cbq3, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "SI3 alt position", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si13alt_position, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
}
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
else
{
gsm_rr_csn_HL_flag(tvb, subtree, bit_len, bit_offset++, "Break Indicator",
"Additional parameters \"SI4 Rest Octets_S\" are sent in SYSTEM INFORMATION TYPE 7 and 8",
"Additional parameters \"SI4 Rest Octets_S\" are not sent in SYSTEM INFORMATION TYPE 7 and 8");
}
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_si6_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *subtree2;
proto_item *item2;
guint32 curr_offset;
gint bit_offset, bit_offset_sav;
guint8 value;
guint8 tvb_len = tvb_length(tvb);
curr_offset = offset;
bit_offset = curr_offset << 3;
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "PCH and NCH Info", "Present", "Not present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_PCH_AND_NCH_INFO].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_PCH_AND_NCH_INFO]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_paging_channel_restructuring, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_nln_sacch, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Call Priority", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_call_prio, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_nln_status_sacch, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "VBS/VGCS options", "Present", "Not present"))
{
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb,bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_VBS_VGCS_OPTIONS].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_VBS_VGCS_OPTIONS]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_vbs_vgcs_inband_notifications, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_vbs_vgcs_inband_pagings, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
value = gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "DTM", "Supported in Serving cell", "Not Supported in Serving cell");
if (value == TRUE)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rac, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset += 8;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_max_lapdm, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Band Indicator", "1900", "1800");
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "GPRS MS PWR MAX CCCH", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_gprs_ms_txpwr_max_ccch, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
}
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "MBMS Procedures", "Supported", "Not supported"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_dedicated_mode_mbms_notification_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_mnci_support, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
}
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Additions in Rel-7", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "AMR Config", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_amr_config, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
}
}
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static gint
de_rr_rest_oct_gprs_mobile_allocation(tvbuff_t *tvb, proto_tree *tree, gint bit_offset)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
guint8 value;
guint64 ma_length;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_GPRS_MOBILE_ALLOC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_GPRS_MOBILE_ALLOC]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_hsn, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "RFL number list", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rfl_number, tvb, curr_bit_offset, 4, ENC_BIG_ENDIAN);
curr_bit_offset += 4;
}
if (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "MA", "Not Present", "Present"))
{
while (gsm_rr_csn_flag(tvb, subtree, curr_bit_offset++, "ARFCN index list", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_arfcn_index, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
}
}
else
{
proto_tree_add_bits_ret_val(subtree, hf_gsm_a_rr_ma_length, tvb, curr_bit_offset, 6, &ma_length, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
value = (gint)ma_length + 1;
item = proto_tree_add_text(subtree,tvb, curr_bit_offset>>3, (value>>3)+1, "MA Bitmap: ");
while (value)
{
proto_item_append_text(item,"%d",tvb_get_bits8(tvb,curr_bit_offset,1));
curr_bit_offset += 1;
value -= 1;
}
}
proto_item_set_len(item,((curr_bit_offset>>3) - (bit_offset>>3) + 1));
return (curr_bit_offset - bit_offset);
}
static guint16
de_rr_si13_rest_oct(tvbuff_t *tvb, proto_tree *subtree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *subtree2;
proto_item *item2;
guint bit_offset, bit_offset_sav;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
bit_offset = offset << 3;
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "SI13 contents", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bcch_change_mark, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si_change_field, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "SI13 Change Mark", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si13_change_mark, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
bit_offset += de_rr_rest_oct_gprs_mobile_allocation(tvb, subtree, bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "PBCCH", "Present In Cell", "Not Present In Cell"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_psi1_repeat_period, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
bit_offset_sav = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_PBCCH_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_PBCCH_DESC]);
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_pbcch_pb, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_pbcch_tsc, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_pbcch_tn, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "MAIO", "Present", "Not Present"))
{
proto_tree_add_text(subtree2, tvb, bit_offset>>3, 1, "MAIO: %d", tvb_get_bits8(tvb,bit_offset,6));
bit_offset += 6;
}
else
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "ARFCN", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree2, hf_gsm_a_rr_arfcn, tvb, bit_offset, 10, ENC_BIG_ENDIAN);
bit_offset += 10;
}
else
proto_tree_add_text(subtree2, tvb, bit_offset>>3, 1, "PBCCH shall use the BCCH carrier");
}
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rac, tvb, bit_offset, 8, ENC_BIG_ENDIAN);
bit_offset += 8;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_spgc_ccch_sup, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_priority_access_thr, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_network_control_order, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
bit_offset += de_rr_rest_oct_gprs_cell_options(tvb, subtree, bit_offset);
bit_offset += de_rr_rest_oct_gprs_power_control_parameters(tvb, subtree, bit_offset);
}
if (bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Additions in R99", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_sgsnr, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
if (bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Additions in Rel-4", "Present", "Not present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si_status_ind, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
if (bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb, subtree, 0, bit_offset++, "Additions in Rel-6", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "LB MS TXPWR MAX CCH ", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_lb_ms_txpwr_max_cch, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
}
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_si2n_support, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
}
}
}
}
}
}
gsm_rr_csn_padding_bits(subtree, tvb, bit_offset, tvb_len);
return tvb_len - offset;
}
static guint16
de_rr_starting_time(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_item *item;
guint32 curr_offset;
guint16 rfn, fn;
curr_offset = offset;
fn = tvb_get_ntohs(tvb,curr_offset);
rfn = reduced_frame_number(fn);
proto_tree_add_item(tree, hf_gsm_a_rr_T1prim, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_T3, tvb, curr_offset, 2, ENC_BIG_ENDIAN);
curr_offset++;
proto_tree_add_item(tree, hf_gsm_a_rr_T2, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
item = proto_tree_add_uint(tree, hf_gsm_a_rr_rfn, tvb, curr_offset-2, 2, rfn);
PROTO_ITEM_SET_GENERATED(item);
return(curr_offset - offset);
}
static guint16
de_rr_sync_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_sync_ind_nci, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_sync_ind_rot, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_sync_ind_si, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_timing_adv(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_timing_adv, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_time_diff(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_time_diff, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
guint16
de_rr_tlli(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset, tlli;
curr_offset = offset;
tlli = tvb_get_ntohl(tvb, curr_offset);
proto_tree_add_item(tree, hf_gsm_a_rr_tlli, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 4;
if(add_string)
g_snprintf(add_string, string_len, " - 0x%x", tlli);
return(curr_offset - offset);
}
static guint16
de_rr_tmsi_ptmsi(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *subtree;
proto_item *item;
guint32 curr_offset;
curr_offset = offset;
item = proto_tree_add_text(tree, tvb, curr_offset, 3, "%s",
val_to_str_ext_const(DE_RR_TMSI_PTMSI, &gsm_rr_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_rr_elem[DE_RR_TMSI_PTMSI]);
proto_tree_add_item(subtree, hf_gsm_a_rr_tmsi_ptmsi, tvb, curr_offset, 4, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 4;
return(curr_offset - offset);
}
static guint16
de_rr_vgcs_tar_mode_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_target_mode, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_group_cipher_key_number, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_vgcs_cip_par(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_text(tree,tvb, curr_offset, len ,"Data(Not decoded)");
curr_offset = curr_offset + 2;
return(curr_offset - offset);
}
static guint16
de_rr_wait_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_wait_indication, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_ext_meas_result(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
gint bit_offset, i;
guint8 value;
curr_offset = offset;
bit_offset = curr_offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_seq_code, tvb,bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_dtx_used, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
for (i=0; i<21; i++)
{
value = tvb_get_bits8(tvb,bit_offset,6);
proto_tree_add_text(tree, tvb, bit_offset>>3, 1, "RXLEV carrier %d: %s (%d)",i,val_to_str_ext_const(value, &gsm_a_rr_rxlev_vals_ext, "Unknown"),value);
bit_offset += 6;
}
curr_offset = offset + len;
return(curr_offset - offset);
}
static guint16
de_rr_ext_meas_freq_list(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_seq_code, tvb,(curr_offset<<3)+3, 1, ENC_BIG_ENDIAN);
return dissect_arfcn_list(tvb, tree, pinfo, offset, 16, add_string, string_len);
}
guint16
de_rr_sus_cau(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_suspension_cause, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 1;
return(curr_offset - offset);
}
static guint16
de_rr_apdu_id(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_rr_apdu_id, tvb, offset, 1, ENC_BIG_ENDIAN);
return 0;
}
static guint16
de_rr_apdu_flags(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree_add_item(tree, hf_gsm_a_rr_apdu_flags, tvb, offset, 1, ENC_BIG_ENDIAN);
return 1;
}
static guint16
de_rr_apdu_data(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
tvbuff_t *sub_tvb;
sub_tvb = tvb_new_subset(tvb, offset, len, len);
if (rrlp_dissector)
call_dissector(rrlp_dissector, sub_tvb,pinfo, tree);
return len;
}
static guint16
de_rr_ho_to_utran_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
tvbuff_t *rrc_irat_ho_to_utran_cmd_tvb;
curr_offset = offset;
if (len)
{
rrc_irat_ho_to_utran_cmd_tvb = tvb_new_subset(tvb, curr_offset, len, len);
if (rrc_irat_ho_to_utran_cmd_handle)
call_dissector(rrc_irat_ho_to_utran_cmd_handle, rrc_irat_ho_to_utran_cmd_tvb, pinfo, tree);
}
curr_offset += len;
return(curr_offset - offset);
}
static guint16
de_rr_serv_sup(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_MBMS_multicast, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
proto_tree_add_item(tree, hf_gsm_a_rr_MBMS_broadcast, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset++;
return(curr_offset - offset);
}
static guint16
de_rr_ded_serv_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
guint32 curr_offset;
curr_offset = offset;
proto_tree_add_item(tree, hf_gsm_a_rr_last_segment, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset = curr_offset + 3;
return(curr_offset - offset);
}
static guint16
de_rr_carrier_ind(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_, gchar *add_string _U_, int string_len _U_)
{
proto_tree *subtree;
proto_item *item;
guint32 curr_offset;
curr_offset = offset;
item = proto_tree_add_text(tree, tvb, curr_offset, 3, "%s",
val_to_str_ext_const(DE_RR_CARRIER_IND, &gsm_rr_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_rr_elem[DE_RR_CARRIER_IND]);
proto_tree_add_item(subtree, hf_gsm_a_rr_carrier_ind, tvb, curr_offset, 1, ENC_BIG_ENDIAN);
curr_offset += 1;
return(curr_offset - offset);
}
static void
dtap_rr_add_ass(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, NULL);
ELEM_OPT_TLV(0x72, GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, NULL);
ELEM_OPT_TV(0x7c, GSM_A_PDU_TYPE_RR, DE_RR_STARTING_TIME, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_ass_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC2, " - Description of the First Channel, after time");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_POW_CMD, NULL);
ELEM_OPT_TLV(0x05, GSM_A_PDU_TYPE_RR, DE_RR_FREQ_LIST, " - Frequency List, after time");
ELEM_OPT_TV(0x62, GSM_A_PDU_TYPE_RR, DE_RR_CELL_CH_DSC, NULL);
ELEM_OPT_TLV(0x10,GSM_A_PDU_TYPE_RR, DE_RR_MULT_ALL, " - Description of the multislot configuration");
ELEM_OPT_TV(0x63,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of the First Channel(Channel Set 1)");
ELEM_OPT_TV(0x11,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 2");
ELEM_OPT_TV(0x13,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 3");
ELEM_OPT_TV(0x14,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 4");
ELEM_OPT_TV(0x15,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 5");
ELEM_OPT_TV(0x16,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 6");
ELEM_OPT_TV(0x17,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 7");
ELEM_OPT_TV(0x18,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 8");
ELEM_OPT_TV(0x64,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, "Description of the Second Channel, after time");
ELEM_OPT_TV(0x66,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE2, " - Mode of the Second Channel");
ELEM_OPT_TLV(0x72,GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, " - Mobile Allocation, after time");
ELEM_OPT_TV(0x7C,GSM_A_PDU_TYPE_RR, DE_RR_STARTING_TIME, NULL);
ELEM_OPT_TLV(0x19, GSM_A_PDU_TYPE_RR, DE_RR_FREQ_LIST, " - Frequency List, before time");
ELEM_OPT_TV(0x1c,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC2, " - Description of the First Channel, before time");
ELEM_OPT_TV(0x1d,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, " - Description of the Second Channel, before time");
ELEM_OPT_TV(0x1e,GSM_A_PDU_TYPE_RR, DE_RR_FREQ_CH_SEQ, " - Frequency channel sequence before time");
ELEM_OPT_TLV(0x21,GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, " - Mobile Allocation, before time");
ELEM_OPT_TV_SHORT(0x90,GSM_A_PDU_TYPE_RR, DE_RR_CIP_MODE_SET, NULL);
ELEM_OPT_TLV(0x01,GSM_A_PDU_TYPE_RR, DE_RR_VGCS_TAR_MODE_IND, NULL);
ELEM_OPT_TLV(0x03,GSM_A_PDU_TYPE_RR, DE_RR_MULTIRATE_CONF, NULL);
ELEM_OPT_TLV(0x04,GSM_A_PDU_TYPE_RR, DE_RR_VGCS_CIP_PAR, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_ass_comp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_ass_fail(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_ch_mode_mod(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC2, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, NULL);
ELEM_OPT_TLV(0x01,GSM_A_PDU_TYPE_RR, DE_RR_VGCS_TAR_MODE_IND, NULL);
ELEM_OPT_TLV(0x03,GSM_A_PDU_TYPE_RR, DE_RR_MULTIRATE_CONF, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_ch_mode_mod_ack(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC2, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_ch_rel(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CAUSE, NULL);
ELEM_OPT_TLV(0x73, GSM_A_PDU_TYPE_RR, DE_RR_BA_RANGE, NULL);
ELEM_OPT_TV_SHORT(0xC0, GSM_A_PDU_TYPE_RR, DE_RR_GPRS_RESUMPTION, NULL);
ELEM_OPT_TLV(0x75, GSM_A_PDU_TYPE_RR, DE_RR_BA_LIST_PREF, NULL);
ELEM_OPT_TLV(0x76, GSM_A_PDU_TYPE_RR, DE_RR_UTRAN_FREQ_LIST, NULL);
ELEM_OPT_TV(0x62, GSM_A_PDU_TYPE_RR, DE_RR_CELL_CH_DSC, NULL);
ELEM_OPT_TLV(0x77, GSM_A_PDU_TYPE_RR, DE_RR_CELL_SELECT_INDIC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_cip_mode_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_RR, DE_RR_CIP_MODE_SET,
GSM_A_PDU_TYPE_RR, DE_RR_CIP_MODE_RESP);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
void
dtap_rr_cip_mode_cpte(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(0x17, GSM_A_PDU_TYPE_COMMON, DE_MID, "Mobile Equipment Identity");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_mm_cm_change(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MS_CM_2, NULL);
ELEM_OPT_TLV(0x20, GSM_A_PDU_TYPE_COMMON, DE_MS_CM_3, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_utran_classmark_change(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_UTRAN_CM, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_cm_enq(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TLV(0x10, GSM_A_PDU_TYPE_RR, DE_RR_CM_ENQ_MASK, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_conf_change_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_MULT_ALL, NULL);
ELEM_OPT_TV(0x63,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 1");
ELEM_OPT_TV(0x11,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 2");
ELEM_OPT_TV(0x13,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 3");
ELEM_OPT_TV(0x14,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 4");
ELEM_OPT_TV(0x15,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 5");
ELEM_OPT_TV(0x16,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 6");
ELEM_OPT_TV(0x17,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 7");
ELEM_OPT_TV(0x18,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 8");
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_conf_change_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_dtm_ass_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_POW_CMD, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_GPRS_BROADCAST_INFORMATION, NULL);
ELEM_OPT_TV(0x10, GSM_A_PDU_TYPE_RR, DE_RR_CELL_CH_DSC, NULL);
ELEM_OPT_TV(0x11,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, NULL);
ELEM_OPT_TLV(0x12, GSM_A_PDU_TYPE_RR, DE_RR_FREQ_LIST, NULL);
ELEM_OPT_TLV(0x13, GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, NULL);
ELEM_OPT_TLV(0x15, GSM_A_PDU_TYPE_RR, DE_RR_PKT_UL_ASS, NULL);
ELEM_OPT_TLV(0x16, GSM_A_PDU_TYPE_RR, DE_RR_PKT_DL_ASS, NULL);
ELEM_OPT_TLV(0x17,GSM_A_PDU_TYPE_RR, DE_RR_MULTIRATE_CONF, NULL);
ELEM_OPT_TV_SHORT(0x90,GSM_A_PDU_TYPE_RR, DE_RR_CIP_MODE_SET, NULL);
ELEM_OPT_TLV(0x18, GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, " - C2");
ELEM_OPT_TLV(0x19, GSM_A_PDU_TYPE_RR, DE_RR_FREQ_LIST, " - C2");
ELEM_OPT_TLV(0x20, GSM_A_PDU_TYPE_RR, DE_RR_PKT_DL_ASS_TYPE2, NULL);
ELEM_OPT_TV(0x21,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC3, " - Channel Description C2");
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_dtm_ass_fail(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_dtm_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_DTM_INFO_DETAILS, NULL);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_dtm_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_WAIT_IND, " - DTM Wait Indication");
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_dtm_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TLLI, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_CHNL_REQ_DESC2, NULL);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_freq_redef(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_STARTING_TIME, NULL);
ELEM_OPT_TV(0x62,GSM_A_PDU_TYPE_RR, DE_RR_CELL_CH_DSC, NULL);
ELEM_OPT_TV_SHORT(0x90,GSM_A_PDU_TYPE_RR, DE_RR_CARRIER_IND,NULL);
ELEM_OPT_TLV(0x11, GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, " - Mobile Allocation C2");
ELEM_OPT_TV(0x12,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC3, " - Channel Description C2");
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_gprs_sus_req(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TLLI, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_GM, DE_RAI, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_SUS_CAU, NULL);
ELEM_OPT_TV_SHORT(0x01,GSM_A_PDU_TYPE_RR, DE_RR_SERV_SUP,NULL);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
void
dtap_rr_ho_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CELL_DSC, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC2, " - Description of the first channel, after time");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_HO_REF, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_POW_CMD_AND_ACC_TYPE, NULL);
ELEM_OPT_TV_SHORT(0xD0,GSM_A_PDU_TYPE_RR, DE_RR_SYNC_IND,NULL);
ELEM_OPT_TV(0x02,GSM_A_PDU_TYPE_RR, DE_RR_FREQ_SHORT_LIST," - Frequency Short List, after time");
ELEM_OPT_TLV(0x05, GSM_A_PDU_TYPE_RR, DE_RR_FREQ_LIST, " - Frequency List, after time");
ELEM_OPT_TV(0x62,GSM_A_PDU_TYPE_RR, DE_RR_CELL_CH_DSC, NULL);
ELEM_OPT_TLV(0x10,GSM_A_PDU_TYPE_RR, DE_RR_MULT_ALL, NULL);
ELEM_OPT_TV(0x63,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of the First Channel(Channel Set 1))");
ELEM_OPT_TV(0x11,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 2");
ELEM_OPT_TV(0x13,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 3");
ELEM_OPT_TV(0x14,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 4");
ELEM_OPT_TV(0x15,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 5");
ELEM_OPT_TV(0x16,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 6");
ELEM_OPT_TV(0x17,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 7");
ELEM_OPT_TV(0x18,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE, " - Mode of Channel Set 8");
ELEM_OPT_TV(0x64,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, " - Description of the Second Channel, after time");
ELEM_OPT_TV(0x66,GSM_A_PDU_TYPE_RR, DE_RR_CH_MODE2, " - Mode of the Second Channel");
ELEM_OPT_TV(0x69,GSM_A_PDU_TYPE_RR, DE_RR_FREQ_CH_SEQ, " - Frequency Channel Sequence, after time");
ELEM_OPT_TLV(0x72,GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, " - Mobile Allocation, after time");
ELEM_OPT_TV(0x7C,GSM_A_PDU_TYPE_RR, DE_RR_STARTING_TIME, NULL);
ELEM_OPT_TV(0x7B,GSM_A_PDU_TYPE_RR, DE_RR_TIME_DIFF, " - Real Time Difference");
ELEM_OPT_TV(0x7D,GSM_A_PDU_TYPE_RR, DE_RR_TIMING_ADV, NULL);
ELEM_OPT_TV(0x12,GSM_A_PDU_TYPE_RR, DE_RR_FREQ_SHORT_LIST, " - Frequency Short List, before time");
ELEM_OPT_TLV(0x19,GSM_A_PDU_TYPE_RR, DE_RR_FREQ_LIST, " - Frequency List, before time");
ELEM_OPT_TV(0x1c,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC2, " - Description of the First Channel, before time");
ELEM_OPT_TV(0x1d,GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, " - Description of the Second Channel, before time");
ELEM_OPT_TV(0x1e,GSM_A_PDU_TYPE_RR, DE_RR_FREQ_CH_SEQ, " - Frequency channel sequence before time");
ELEM_OPT_TLV(0x21,GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, " - Mobile Allocation, before time");
ELEM_OPT_TV_SHORT(0x90,GSM_A_PDU_TYPE_RR, DE_RR_CIP_MODE_SET, NULL);
ELEM_OPT_TLV(0x01,GSM_A_PDU_TYPE_RR, DE_RR_VGCS_TAR_MODE_IND, NULL);
ELEM_OPT_TLV(0x03,GSM_A_PDU_TYPE_RR, DE_RR_MULTIRATE_CONF, NULL);
ELEM_OPT_TLV(0x76,GSM_A_PDU_TYPE_RR, DE_RR_DYN_ARFCN_MAP, NULL);
ELEM_OPT_TLV(0x04,GSM_A_PDU_TYPE_RR, DE_RR_VGCS_CIP_PAR, NULL);
ELEM_OPT_TV(0x51,GSM_A_PDU_TYPE_RR, DE_RR_DED_SERV_INF, NULL);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_inter_syst_to_utran_ho_cmd(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_HO_TO_UTRAN_CMD, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_ho_cpte(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CAUSE, NULL);
ELEM_OPT_TLV(0x77,GSM_A_PDU_TYPE_RR, DE_RR_MOB_TIME_DIFF, " - Mobile Observed Time Difference");
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_ho_fail(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_imm_ass(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
guint8 oct;
curr_offset = offset;
curr_len = len;
oct = tvb_get_guint8(tvb, curr_offset);
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_RR, DE_RR_PAGE_MODE,
GSM_A_PDU_TYPE_RR, DE_RR_DED_MOD_OR_TBF);
if((oct&0x10) == 0){
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, NULL);
}else{
if((oct&0x04) == 0){
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_PACKET_CH_DESC, NULL);
}
}
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_REQ_REF, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TIMING_ADV, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, NULL);
ELEM_OPT_TV(0x7C,GSM_A_PDU_TYPE_RR, DE_RR_STARTING_TIME, NULL);
if(tvb_length_remaining(tvb,curr_offset) > 0)
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_IA_REST_OCT, NULL);
}
static void
dtap_rr_imm_ass_ext(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_RR, DE_RR_PAGE_MODE,
GSM_A_PDU_TYPE_COMMON, DE_SPARE_NIBBLE);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, " - Channel Description 1");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_REQ_REF, " - Request Reference 1");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TIMING_ADV, " - Timing Advance 1");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, " - Channel Description 2");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_REQ_REF, " - Request Reference 2");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TIMING_ADV, " - Timing Advance 2");
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, NULL);
ELEM_OPT_TV(0x7C,GSM_A_PDU_TYPE_RR, DE_RR_STARTING_TIME, NULL);
if(tvb_length_remaining(tvb,curr_offset) > 0)
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_IAX_REST_OCT, NULL);
}
static void
dtap_rr_imm_ass_rej(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_RR, DE_RR_PAGE_MODE,
GSM_A_PDU_TYPE_COMMON, DE_SPARE_NIBBLE);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_REQ_REF, " - Request Reference 1");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_WAIT_IND, " - Wait Indication 1");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_REQ_REF, " - Request Reference 2");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_WAIT_IND, " - Wait Indication 2");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_REQ_REF, " - Request Reference 3");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_WAIT_IND, " - Wait Indication 3");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_REQ_REF, " - Request Reference 4");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_WAIT_IND, " - Wait Indication 4");
if(tvb_length_remaining(tvb,curr_offset) > 0)
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_IAR_REST_OCT, NULL);
}
static void
dtap_rr_meas_rep(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_MEAS_RES, NULL);
}
static void
dtap_rr_pkt_assign(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_GPRS_BROADCAST_INFORMATION, NULL);
ELEM_OPT_TLV(0x22, GSM_A_PDU_TYPE_RR, DE_RR_PKT_UL_ASS, NULL);
ELEM_OPT_TLV(0x23, GSM_A_PDU_TYPE_RR, DE_RR_PKT_DL_ASS, NULL);
ELEM_OPT_TLV(0x12, GSM_A_PDU_TYPE_RR, DE_RR_FREQ_LIST, " - Frequency List C2");
ELEM_OPT_TLV(0x13, GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, " - Mobile Allocation C2");
ELEM_OPT_TV(0x14, GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC3, " - Channel Description C2");
ELEM_OPT_TLV(0x24, GSM_A_PDU_TYPE_RR, DE_RR_PKT_DL_ASS_TYPE2, NULL);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_pkt_notif(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_OPT_TV(0x10, GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, " - Packet TMSI");
ELEM_OPT_TLV(0x11, GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
EXTRANEOUS_DATA_CHECK(len, curr_offset - offset);
}
static void
dtap_rr_paging_req_type_1(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_RR, DE_RR_PAGE_MODE,
GSM_A_PDU_TYPE_RR, DE_RR_CHNL_NEEDED);
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MID, " - Mobile Identity 1");
ELEM_OPT_TLV(0x17, GSM_A_PDU_TYPE_COMMON, DE_MID, " - Mobile Identity 2");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_P1_REST_OCT, NULL);
}
static void
dtap_rr_paging_req_type_2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_RR, DE_RR_PAGE_MODE,
GSM_A_PDU_TYPE_RR, DE_RR_CHNL_NEEDED);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, " - Mobile Identity 1");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, " - Mobile Identity 2");
ELEM_OPT_TLV(0x17, GSM_A_PDU_TYPE_COMMON, DE_MID, " - Mobile Identity 3");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_P2_REST_OCT, NULL);
}
static void
dtap_rr_paging_req_type_3(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_VV_SHORT(GSM_A_PDU_TYPE_RR, DE_RR_PAGE_MODE,
GSM_A_PDU_TYPE_RR, DE_RR_CHNL_NEEDED);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, " - Mobile Identity 1");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, " - Mobile Identity 2");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, " - Mobile Identity 3");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TMSI_PTMSI, " - Mobile Identity 4");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_P3_REST_OCT, NULL);
}
static void
dtap_rr_paging_resp(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
guint8 oct;
proto_tree *subtree;
proto_item *item;
curr_offset = offset;
curr_len = len;
oct = tvb_get_guint8(tvb, curr_offset);
other_decode_bitfield_value(a_bigbuf, oct, 0xf0, 8);
proto_tree_add_text(tree,
tvb, curr_offset, 1,
"%s : Spare",
a_bigbuf);
item =
proto_tree_add_text(tree,
tvb, curr_offset, 1, "%s",
val_to_str_ext_const(DE_CIPH_KEY_SEQ_NUM, &gsm_common_elem_strings_ext, ""));
subtree = proto_item_add_subtree(item, ett_gsm_common_elem[DE_CIPH_KEY_SEQ_NUM]);
other_decode_bitfield_value(a_bigbuf, oct, 0x08, 8);
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s : Spare",
a_bigbuf);
other_decode_bitfield_value(a_bigbuf, oct, 0x07, 8);
switch (oct & 0x07)
{
case 0x07:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s : Ciphering Key Sequence Number: No key is available",
a_bigbuf);
break;
default:
proto_tree_add_text(subtree,
tvb, curr_offset, 1,
"%s : Ciphering Key Sequence Number: %u",
a_bigbuf,
oct & 0x07);
break;
}
curr_offset++;
curr_len--;
if ((signed)curr_len <= 0) return;
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MS_CM_2, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_COMMON, DE_MID, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_partial_rel(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_phy_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_TIMING_ADV, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_rr_status(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CAUSE, NULL);
EXTRANEOUS_DATA_CHECK(curr_len, 0);
}
static void
dtap_rr_sys_info_1(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CELL_CH_DSC, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_RACH_CTRL_PARAM, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_SI1_REST_OCT, NULL);
}
static void
dtap_rr_sys_info_2(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_NEIGH_CELL_DESC, " - BCCH Frequency List");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_NCC_PERM, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_RACH_CTRL_PARAM, NULL);
}
static void
dtap_rr_sys_info_2bis(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_NEIGH_CELL_DESC, " - Extended BCCH Frequency List");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_RACH_CTRL_PARAM, NULL);
}
static void
dtap_rr_sys_info_2ter(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_NEIGH_CELL_DESC2, " - Extended BCCH Frequency List");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_SI2TER_REST_OCT, NULL);
}
static void
dtap_rr_sys_info_2quater(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_SI2QUATER_REST_OCT, NULL);
}
static void
dtap_rr_sys_info_3(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_CELL_ID, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CTRL_CH_DESC, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CELL_OPT_BCCH, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CELL_SEL_PARAM, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_RACH_CTRL_PARAM, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_SI3_REST_OCT, NULL);
}
static void
dtap_rr_sys_info_4(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CELL_SEL_PARAM, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_RACH_CTRL_PARAM, NULL);
ELEM_OPT_TV(0x64, GSM_A_PDU_TYPE_RR, DE_RR_CH_DSC, " - CBCH");
ELEM_OPT_TLV(0x72, GSM_A_PDU_TYPE_RR, DE_RR_MOB_ALL, " - CBCH");
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_SI4_REST_OCT, NULL);
}
static void
dtap_rr_sys_info_5(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_NEIGH_CELL_DESC, " - BCCH Frequency List");
}
static void
dtap_rr_sys_info_5bis(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_NEIGH_CELL_DESC, " - Extended BCCH Frequency List");
}
static void
dtap_rr_sys_info_5ter(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_NEIGH_CELL_DESC2, " - Extended BCCH Frequency List");
}
static void
dtap_rr_sys_info_6(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_CELL_ID, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_COMMON, DE_LAI, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_CELL_OPT_SACCH, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_NCC_PERM, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_SI6_REST_OCT, NULL);
}
static void
dtap_rr_sys_info_13(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_SI13_REST_OCT, NULL);
}
static void
dtap_rr_ext_meas_order(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_EXT_MEAS_FREQ_LIST, NULL);
}
static void
dtap_rr_ext_meas_report(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_EXT_MEAS_RESULT, NULL);
}
static void
dtap_rr_app_inf(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
guint32 curr_offset;
guint32 consumed;
guint curr_len;
curr_offset = offset;
curr_len = len;
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_APDU_ID, NULL);
ELEM_MAND_V(GSM_A_PDU_TYPE_RR, DE_RR_APDU_FLAGS, NULL);
ELEM_MAND_LV(GSM_A_PDU_TYPE_RR, DE_RR_APDU_DATA, NULL);
}
static void
sacch_rr_meas_info(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len _U_)
{
proto_tree *subtree = NULL, *subtree2 = NULL;
proto_item *item, *item2;
guint32 curr_offset;
gint bit_offset, bit_offset_sav, bit_offset_sav2;
guint8 value, idx;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
curr_offset = offset;
bit_offset = curr_offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_ba_ind, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_3g_ba_ind, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_mp_change_mark, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_mi_index, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_mi_count, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_pwrc, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_gsm_report_type, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_reporting_rate, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset +=1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_invalid_bsic_reporting, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset +=1;
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Real Time Difference Description", "Present", "Not Present"))
{
bit_offset += de_rr_rtd_desc(tvb, tree, bit_offset, DE_RR_REST_OCTETS_RTD_DESC);
}
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "BSIC Description", "Present", "Not Present"))
{
bit_offset += de_rr_bsic_desc(tvb, tree, bit_offset, DE_RR_REST_OCTETS_BSIC_DESC);
}
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Report Priority Description", "Present", "Not Present"))
{
bit_offset += de_rr_report_priority_desc(tvb, tree, bit_offset, DE_RR_REST_OCTETS_REPORT_PRIO_DESC);
}
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Measurement Parameters Description", "Present", "Not Present"))
{
bit_offset += de_rr_meas_param_desc(tvb, tree, bit_offset, DE_RR_REST_OCTETS_MEAS_PARAM_DESC);
}
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "future extensions of the 2G parameters", "Present", "Not Present"))
{
value = tvb_get_bits8(tvb,bit_offset,8);
bit_offset += 8 + value + 1;
}
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "3G Neighbour Cell Description", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item = proto_tree_add_text(tree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_NEIGH_CELL_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_NEIGH_CELL_DESC]);
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Wait", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_wait, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Index Start 3G", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_index_start_3g, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Absolute Index Start EMR", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_absolute_index_start_emr, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "UTRAN FDD Description", "Present", "Not Present"))
{
bit_offset += de_rr_si2quater_meas_info_utran_fdd_desc(tvb, subtree, bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "UTRAN TDD Description", "Present", "Not Present"))
{
bit_offset += de_rr_si2quater_meas_info_utran_tdd_desc(tvb, subtree, bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "CDMA2000 Description", "Present", "Not Present"))
{
bit_offset_sav2 = bit_offset;
item2 = proto_tree_add_text(subtree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_CDMA2000_DESC].strptr);
subtree2 = proto_item_add_subtree(item2, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_CDMA2000_DESC]);
bit_offset += 16;
idx = tvb_get_bits8(tvb,bit_offset,5);
bit_offset += 5;
while (idx)
{
bit_offset += 9;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "additional information for 3X Auxiliary Pilot", "Present", "Not Present"))
{
value = tvb_get_bits8(tvb,bit_offset,3);
switch (value)
{
case 0:
bit_offset += 5;
break;
case 1:
bit_offset += 2;
bit_offset += tvb_get_bits8(tvb,bit_offset,3) + 3 + 6;
break;
case 2:
bit_offset += 2;
bit_offset += tvb_get_bits8(tvb,bit_offset,3) + 3 + 6;
bit_offset += 4;
break;
case 3:
bit_offset += 8;
break;
case 6:
bit_offset += 10;
bit_offset += tvb_get_bits8(tvb,bit_offset,3) + 3 + 6;
if (tvb_get_bits8(tvb,bit_offset,1))
{
bit_offset += 3;
bit_offset += tvb_get_bits8(tvb,bit_offset,3) + 3 + 6;
}
else
bit_offset += 1;
if (tvb_get_bits8(tvb,bit_offset,1))
{
bit_offset += 3;
bit_offset += tvb_get_bits8(tvb,bit_offset,3) + 3 + 6;
}
else
bit_offset += 1;
break;
default:
return;
}
}
idx -= 1;
}
proto_tree_add_text(subtree2,tvb, bit_offset_sav2>>3, ((bit_offset-bit_offset_sav2)>>3)+1,"Data(Not decoded)");
proto_item_set_len(item2, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
proto_item_set_len(item, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Measurement Parameters Description", "Present", "Not Present"))
{
guint8 reporting_quant = 0;
bit_offset_sav = bit_offset;
item = proto_tree_add_text(tree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_3G_MEAS_PARAM_DESC].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_3G_MEAS_PARAM_DESC]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_qsearch_c, tvb, bit_offset, 4, ENC_BIG_ENDIAN);
bit_offset += 4;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_3g_search_prio, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_fdd_rep_quant, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
reporting_quant = gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Reporting Quantity", "Ec/No", "RSCP");
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "FDD Multirat Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_fdd_multirat_reporting, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "FDD Reporting Offset", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_fdd_reporting_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
if (reporting_quant == 0)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_fdd_reporting_threshold_rscp, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_fdd_reporting_threshold_ecn0, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "TDD Multirat Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tdd_multirat_reporting, tvb, bit_offset, 2, ENC_BIG_ENDIAN);
bit_offset += 2;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "TDD Reporting Offset", "Present", "Not Present"))
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tdd_reporting_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
if (reporting_quant == 0)
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tdd_reporting_threshold_rscp, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
else
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_tdd_reporting_threshold_ecn0, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
}
bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "CDMA2000 Multirat Reporting", "Present", "Not Present"))
bit_offset += 2;
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "CDMA2000 Reporting Threshold", "Present", "Not Present"))
bit_offset += 6;
proto_item_set_len(item, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (bit_len - bit_offset > 0)
{
if (gsm_rr_csn_HL_flag(tvb, tree, 0, bit_offset++, "Additions in Rel-5", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Additional Measurement Parameters Description 2", "Present", "Not Present"))
{
bit_offset += de_rr_3g_add_meas_param_desc2(tvb, tree, bit_offset);
}
if (bit_len - bit_offset > 0)
{
if (gsm_rr_csn_HL_flag(tvb, tree, 0, bit_offset++,"Additions in Rel-7", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "700 Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_700_reporting_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_700_reporting_threshold, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "810 Reporting", "Present", "Not Present"))
{
proto_tree_add_bits_item(tree, hf_gsm_a_rr_810_reporting_offset, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_810_reporting_threshold, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
}
if (bit_len - bit_offset > 0)
{
if (gsm_rr_csn_HL_flag(tvb, tree, 0, bit_offset++, "Additions in Rel-8", "Present", "Not present"))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "3G Supplementary Parameters Description", "Present", "Not Present"))
{
bit_offset += de_rr_3g_supplementary_param_desc_mi(tvb, tree, bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "E-UTRAN Parameters Description", "Present", "Not Present"))
{
bit_offset += de_rr_eutran_param_desc_mi(tvb, tree, bit_offset);
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "E-UTRAN CSG Description", "Present", "Not Present"))
{
bit_offset += de_rr_eutran_csg_desc_mi(tvb, tree, bit_offset);
}
}
}
}
}
}
}
gsm_rr_csn_padding_bits(tree, tvb, bit_offset, tvb_len);
}
static guint32
sacch_rr_eutran_meas_report(tvbuff_t *tvb, proto_tree *tree, guint32 bit_offset, guint len_in_bit _U_)
{
proto_tree *subtree;
proto_item *item;
gint curr_bit_offset;
gint8 n_eutran;
curr_bit_offset = bit_offset;
item = proto_tree_add_text(tree, tvb, curr_bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_EUTRAN_MEASUREMENT_REPORT].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_EUTRAN_MEASUREMENT_REPORT]);
n_eutran = tvb_get_bits8(tvb,curr_bit_offset,2);
n_eutran += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_mr_n_eutran, tvb, curr_bit_offset, 2, ENC_BIG_ENDIAN);
curr_bit_offset += 2;
while ( (n_eutran > 0) && (curr_bit_offset - bit_offset < len_in_bit) )
{
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_mr_freq_idx, tvb, curr_bit_offset, 3, ENC_BIG_ENDIAN);
curr_bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_mr_cell_id, tvb, curr_bit_offset, 9, ENC_BIG_ENDIAN);
curr_bit_offset += 9;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_eutran_mr_rpt_quantity, tvb, curr_bit_offset, 6, ENC_BIG_ENDIAN);
curr_bit_offset += 6;
n_eutran -= 1;
}
return curr_bit_offset - bit_offset;
}
static void
sacch_rr_enh_meas_report(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo _U_, guint32 offset, guint len)
{
proto_tree *subtree;
proto_item *item;
guint32 curr_offset;
guint bit_offset, bit_offset_sav;
guint8 tvb_len = tvb_length(tvb);
guint16 bit_len = tvb_len << 3;
guint8 idx;
curr_offset = offset;
bit_offset = curr_offset << 3;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_ba_used, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_3g_ba_used, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_bsic_seen, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(tree, hf_gsm_a_rr_scale, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Serving cell data", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item = proto_tree_add_text(tree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_SERVING_CELL_DATA].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_SERVING_CELL_DATA]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_dtx_used, tvb, bit_offset, 1, ENC_BIG_ENDIAN);
bit_offset += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rxlev_full_serv_cell, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rxqual_full_serv_cell, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_mean_bep_gmsk, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_mean_cv_bep, tvb, bit_offset, 3, ENC_BIG_ENDIAN);
bit_offset += 3;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_nbr_rcvd_blocks, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
proto_item_set_len(item, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
while (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Repeated Invalid BSIC Information", "Present", "Not Present"))
{
bit_offset_sav = bit_offset;
item = proto_tree_add_text(tree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_REPEAT_INV_BSIC_INFO].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_REPEAT_INV_BSIC_INFO]);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bcch_freq_ncell, tvb, bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_bsic_ncell, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_rxlev_ncell, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
proto_item_set_len(item, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
if (gsm_rr_csn_flag(tvb, tree, bit_offset++, "Bitmap Type Reporting", "Present", "Not Present"))
{
item = proto_tree_add_text(tree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_BITMAP_TYPE_REPORTING].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_BITMAP_TYPE_REPORTING]);
idx = 0;
while (((guint)(bit_offset>>3) <= (offset + len)) && (idx < 96))
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Reporting Quantity", "Present", "Not Present"))
{
proto_tree_add_text(subtree, tvb, bit_offset>>3, 1, "Neighbour Cell List index: %u", idx);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_reporting_quantity, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
}
idx += 1;
}
}
if (bit_offset < bit_len)
{
if (gsm_rr_csn_HL_flag(tvb, tree, 0, bit_offset++, "Additions in Rel-8", "Present", "Not Present"))
{
gint8 bitmap_length;
bit_offset_sav = bit_offset;
item = proto_tree_add_text(tree, tvb, bit_offset>>3, -1, "%s", gsm_rr_rest_octets_elem_strings[DE_RR_REST_OCTETS_REPORTING_QUANTITY].strptr);
subtree = proto_item_add_subtree(item, ett_gsm_rr_rest_octets_elem[DE_RR_REST_OCTETS_REPORTING_QUANTITY]);
bitmap_length = tvb_get_bits8(tvb,bit_offset,7);
bitmap_length += 1;
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_emr_bitmap_length, tvb, bit_offset, 7, ENC_BIG_ENDIAN);
bit_offset += 7;
idx = 0;
while ((guint)(bit_offset>>3) <= (offset + len) && (idx < bitmap_length) )
{
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "Reporting Quantity", "Present", "Not Present"))
{
proto_tree_add_text(subtree, tvb, bit_offset>>3, 1, "Neighbour Cell List index: %u", idx);
proto_tree_add_bits_item(subtree, hf_gsm_a_rr_reporting_quantity, tvb, bit_offset, 6, ENC_BIG_ENDIAN);
bit_offset += 6;
}
idx += 1;
}
if (gsm_rr_csn_flag(tvb, subtree, bit_offset++, "E-UTRAN Measurement Report", "Present", "Not Present"))
{
bit_offset += sacch_rr_eutran_meas_report(tvb, subtree, bit_offset, len*8-(bit_offset-offset*8));
}
proto_item_set_len(item, (bit_offset>>3) - (bit_offset_sav>>3)+1);
}
}
gsm_rr_csn_padding_bits(tree, tvb, bit_offset, tvb_len);
}
void get_rr_msg_params(guint8 oct, const gchar **msg_str, int *ett_tree, int *hf_idx, msg_fcn *msg_fcn_p)
{
gint idx;
*msg_str = try_val_to_str_idx((guint32) (oct & DTAP_RR_IEI_MASK), gsm_a_dtap_msg_rr_strings, &idx);
*hf_idx = hf_gsm_a_dtap_msg_rr_type;
if (*msg_str != NULL) {
*ett_tree = ett_gsm_dtap_msg_rr[idx];
*msg_fcn_p = dtap_msg_rr_fcn[idx];
}
return;
}
static void
dissect_ccch(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
static gsm_a_tap_rec_t tap_rec[4];
static gsm_a_tap_rec_t *tap_p;
static guint tap_current = 0;
void (*msg_fcn_p)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len);
guint8 oct;
guint8 pd;
guint32 offset;
guint32 len;
guint32 oct_1, oct_2;
proto_item *ccch_item = NULL;
proto_tree *ccch_tree = NULL;
proto_item *oct_1_item = NULL;
proto_tree *pd_tree = NULL;
const gchar *msg_str;
gint ett_tree;
gint ti;
int hf_idx;
gboolean nsd;
len = tvb_length(tvb);
if (len < 3){
call_dissector(data_handle, tvb, pinfo, tree);
return;
}
col_append_str(pinfo->cinfo, COL_INFO, "(CCCH) ");
tap_current++;
if (tap_current >= 4)
{
tap_current = 0;
}
tap_p = &tap_rec[tap_current];
offset = 0;
oct_2 = 0;
offset += 1;
oct_1 = tvb_get_guint8(tvb, offset++);
if ((((oct_1 & DTAP_TI_MASK) >> 4) & DTAP_TIE_PRES_MASK) == DTAP_TIE_PRES_MASK){
oct_2 = tvb_get_guint8(tvb, offset++);
}
oct = tvb_get_guint8(tvb, offset);
pd = oct_1 & DTAP_PD_MASK;
ti = -1;
msg_str = NULL;
ett_tree = -1;
hf_idx = -1;
msg_fcn_p = NULL;
nsd = FALSE;
col_append_fstr(pinfo->cinfo, COL_INFO, "(%s) ",val_to_str(pd,gsm_a_pd_short_str_vals,"Unknown (%u)"));
switch (pd){
case 6:
get_rr_msg_params(oct, &msg_str, &ett_tree, &hf_idx, &msg_fcn_p);
break;
default:
return;
}
if (msg_str == NULL){
ccch_item = proto_tree_add_protocol_format(tree, proto_a_ccch, tvb, 0, len,
"GSM CCCH - Message Type (0x%02x)",
oct);
ccch_tree = proto_item_add_subtree(ccch_item, ett_ccch_msg);
}else{
ccch_item = proto_tree_add_protocol_format(tree, proto_a_ccch, tvb, 0, -1,
"GSM CCCH - %s", msg_str);
ccch_tree = proto_item_add_subtree(ccch_item, ett_tree);
}
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", msg_str);
elem_v(tvb, ccch_tree, pinfo, GSM_A_PDU_TYPE_RR, DE_RR_L2_PSEUDO_LEN, 0, NULL);
oct_1_item =
proto_tree_add_text(ccch_tree,
tvb, 1, 1,
"Protocol Discriminator: %s",
val_to_str(pd, protocol_discriminator_vals, "Unknown (%u)"));
pd_tree = proto_item_add_subtree(oct_1_item, ett_ccch_oct_1);
proto_tree_add_item(pd_tree, hf_gsm_a_L3_protocol_discriminator, tvb, 1, 1, ENC_BIG_ENDIAN);
if (ti == -1){
proto_tree_add_item(pd_tree, hf_gsm_a_skip_ind, tvb, 1, 1, ENC_BIG_ENDIAN);
}else{
other_decode_bitfield_value(a_bigbuf, oct_1, 0x80, 8);
proto_tree_add_text(pd_tree,tvb, 1, 1,
"%s : TI flag: %s",
a_bigbuf,
((oct_1 & 0x80) ? "allocated by receiver" : "allocated by sender"));
if ((ti & DTAP_TIE_PRES_MASK) == DTAP_TIE_PRES_MASK){
other_decode_bitfield_value(a_bigbuf, oct_1, 0x70, 8);
proto_tree_add_text(pd_tree, tvb, 1, 1,
"%s : TIO: The TI value is given by the TIE in octet 2",
a_bigbuf);
}else{
other_decode_bitfield_value(a_bigbuf, oct_1, 0x70, 8);
proto_tree_add_text(pd_tree,tvb, 1, 1,
"%s : TIO: %u",a_bigbuf,ti & DTAP_TIE_PRES_MASK);
}
}
if ((ti != -1) && (ti & DTAP_TIE_PRES_MASK) == DTAP_TIE_PRES_MASK){
proto_tree_add_item(tree, hf_gsm_a_extension, tvb, 2, 1, ENC_BIG_ENDIAN);
other_decode_bitfield_value(a_bigbuf, oct_2, DTAP_TIE_MASK, 8);
proto_tree_add_text(pd_tree, tvb, 2, 1,
"%s : TIE: %u", a_bigbuf, oct_2 & DTAP_TIE_MASK);
}
if ((pinfo->p2p_dir == P2P_DIR_RECV) &&
nsd)
{
}
proto_tree_add_uint_format(ccch_tree, hf_idx, tvb, offset, 1, oct,
"Message Type: %s",msg_str ? msg_str : "(Unknown)");
offset++;
tap_p->pdu_type = GSM_A_PDU_TYPE_DTAP;
tap_p->message_type = (nsd ? (oct & 0x3f) : oct);
tap_p->protocol_disc = (gsm_a_pd_str_e)pd;
tap_queue_packet(gsm_a_tap, pinfo, tap_p);
if (msg_str == NULL)
return;
if (offset >= len)
return;
if (msg_fcn_p == NULL){
proto_tree_add_text(ccch_tree, tvb, offset, len - offset,
"Message Elements");
}else{
(*msg_fcn_p)(tvb, ccch_tree, pinfo, offset, len - offset);
}
}
static void
get_rr_short_pd_msg_params(guint8 mess_type, const gchar **msg_str, int *ett_tree, int *hf_idx, msg_fcn *msg_fcn_p)
{
gint idx;
*msg_str = try_val_to_str_idx((guint32) mess_type, gsm_a_rr_short_pd_msg_strings, &idx);
*hf_idx = hf_gsm_a_rr_short_pd_msg_type;
if (*msg_str != NULL) {
*ett_tree = ett_gsm_sacch_msg_rr[idx];
*msg_fcn_p = sacch_msg_rr_fcn[idx];
}
}
static void
dissect_sacch(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
static gsm_a_tap_rec_t tap_rec[4];
static gsm_a_tap_rec_t *tap_p;
static guint tap_current = 0;
void (*msg_fcn_p)(tvbuff_t *tvb, proto_tree *tree, packet_info *pinfo, guint32 offset, guint len);
guint8 oct, short_pd, mess_type;
guint32 offset, bit_offset = 0;
guint32 len;
proto_item *sacch_item = NULL;
proto_tree *sacch_tree = NULL;
const gchar *msg_str;
gint ett_tree;
int hf_idx;
len = tvb_length(tvb);
col_append_str(pinfo->cinfo, COL_INFO, "(SACCH) ");
tap_current++;
if (tap_current >= 4)
{
tap_current = 0;
}
tap_p = &tap_rec[tap_current];
offset = 0;
oct = tvb_get_guint8(tvb, offset);
msg_str = NULL;
ett_tree = -1;
hf_idx = -1;
msg_fcn_p = NULL;
short_pd = (oct & 0x80) >> 7;
mess_type = (oct & 0x7c) >> 2;
if (short_pd == 0)
{
col_append_fstr(pinfo->cinfo, COL_INFO, "(RR) ");
get_rr_short_pd_msg_params(mess_type, &msg_str, &ett_tree, &hf_idx, &msg_fcn_p);
}
else
{
col_append_fstr(pinfo->cinfo, COL_INFO, "(Unknown) ");
}
if (msg_str == NULL){
sacch_item = proto_tree_add_protocol_format(tree, proto_a_sacch, tvb, 0, len,
"GSM SACCH - Message Type (0x%02x)", mess_type);
sacch_tree = proto_item_add_subtree(sacch_item, ett_sacch_msg);
}else{
sacch_item = proto_tree_add_protocol_format(tree, proto_a_sacch, tvb, 0, -1,
"GSM SACCH - %s", msg_str);
sacch_tree = proto_item_add_subtree(sacch_item, ett_tree);
col_append_fstr(pinfo->cinfo, COL_INFO, "%s ", msg_str);
}
if (short_pd == 0)
proto_tree_add_bits_item(sacch_tree, hf_gsm_a_rr_short_pd, tvb, offset * 8 + bit_offset++, 1, ENC_BIG_ENDIAN);
if (hf_idx == -1)
return;
proto_tree_add_bits_item(sacch_tree, hf_gsm_a_rr_short_pd_msg_type, tvb, offset * 8 + bit_offset, 5, ENC_BIG_ENDIAN);
bit_offset += 5;
proto_tree_add_bits_item(sacch_tree, hf_gsm_a_rr_short_l2_header, tvb, offset * 8 + bit_offset, 2, ENC_BIG_ENDIAN);
offset++;
tap_p->pdu_type = GSM_A_PDU_TYPE_SACCH;
tap_p->message_type = mess_type;
tap_p->protocol_disc = (gsm_a_pd_str_e)short_pd;
tap_queue_packet(gsm_a_tap, pinfo, tap_p);
if (msg_str == NULL)
return;
if (msg_fcn_p == NULL){
proto_tree_add_text(sacch_tree, tvb, offset, len - offset,
"Message Elements");
}else{
(*msg_fcn_p)(tvb, sacch_tree, pinfo, offset, len - offset);
}
}
void
proto_register_gsm_a_rr(void)
{
guint i;
guint last_offset;
static hf_register_info hf[] =
{
{ &hf_gsm_a_dtap_msg_rr_type,
{ "DTAP Radio Resources Management Message Type", "gsm_a.dtap.msg_rr_type",
FT_UINT8, BASE_HEX, VALS(gsm_a_dtap_msg_rr_strings), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_elem_id,
{ "Element ID", "gsm_a.rr.elem_id",
FT_UINT8, BASE_HEX, NULL, 0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_bcc,
{ "BCC","gsm_a.rr.bcc",
FT_UINT8,BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ncc,
{ "NCC","gsm_a.rr.ncc",
FT_UINT8,BASE_DEC, NULL, 0x38,
NULL, HFILL }
},
{ &hf_gsm_a_rr_bcch_arfcn,
{ "BCCH ARFCN(RF channel number)","gsm_a.rr.bcch_arfcn",
FT_UINT16,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_range_nb,
{ "Number of Ranges","gsm_a.rr.range_nb",
FT_UINT8, BASE_DEC, NULL, 0xff,
NULL, HFILL }
},
{ &hf_gsm_a_rr_range_lower,
{ "Range Lower","gsm_a.rr.range_lower",
FT_UINT16, BASE_DEC, NULL, 0x0000,
"ARFCN used as the lower limit of a range of frequencies to be used by the mobile station in cell selection (Range Lower)", HFILL }
},
{ &hf_gsm_a_rr_range_higher,
{ "Range Higher","gsm_a.rr.range_higher",
FT_UINT16, BASE_DEC, NULL, 0x0000,
"ARFCN used as the higher limit of a range of frequencies to be used by the mobile station in cell selection (Range Higher)", HFILL }
},
{ &hf_gsm_a_rr_ba_freq,
{ "BA Freq","gsm_a.rr.ba_freq",
FT_UINT16, BASE_DEC, NULL, 0x0000,
"ARFCN indicating a single frequency to be used by the mobile station in cell selection and reselection (BA Freq)", HFILL }
},
{ &hf_gsm_a_rr_ho_ref_val,
{ "Handover reference value","gsm_a.rr.ho_ref_val",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_L2_pseudo_len,
{ "L2 Pseudo Length value","gsm_a.rr.l2_pseudo_len",
FT_UINT8, BASE_DEC, NULL, 0xfc,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ba_used,
{ "BA-USED","gsm_a.rr.ba_used",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_dtx_used,
{ "DTX-USED","gsm_a.rr.dtx_used",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_dtx_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_3g_ba_used,
{ "3G-BA-USED","gsm_a.rr.3g_ba_used",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_meas_valid,
{ "MEAS-VALID","gsm_a.rr.meas_valid",
FT_BOOLEAN,8, TFS(&gsm_a_rr_mv_vals), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rxlev_full_serv_cell,
{ "RXLEV-FULL-SERVING-CELL","gsm_a.rr.rxlev_full_serv_cell",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &gsm_a_rr_rxlev_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rxlev_sub_serv_cell,
{ "RXLEV-SUB-SERVING-CELL","gsm_a.rr.rxlev_sub_serv_cell",
FT_UINT8,BASE_DEC|BASE_EXT_STRING, &gsm_a_rr_rxlev_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rxqual_full_serv_cell,
{ "RXQUAL-FULL-SERVING-CELL","gsm_a.rr.rxqual_full_serv_cell",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_rxqual_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rxqual_sub_serv_cell,
{ "RXQUAL-SUB-SERVING-CELL","gsm_a.rr.rxqual_sub_serv_cell",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_rxqual_vals), 0x0e,
NULL, HFILL }
},
{ &hf_gsm_a_rr_no_ncell_m,
{ "NO-NCELL-M","gsm_a.rr.no_ncell_m",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_ncell_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rxlev_ncell,
{ "RXLEV-NCELL","gsm_a.rr.rxlev_ncell",
FT_UINT8,BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_bcch_freq_ncell,
{ "BCCH-FREQ-NCELL","gsm_a.rr.bcch_freq_ncell",
FT_UINT8,BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_bsic_ncell,
{ "BSIC-NCELL","gsm_a.rr.bsic_ncell",
FT_UINT8,BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_mobile_time_difference,
{ "Mobile Timing Difference value (in half bit periods)","gsm_a.rr.mobile_time_difference",
FT_UINT32,BASE_DEC, NULL, 0xFFFFF8,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pow_cmd_atc,
{ "ATC","gsm_a.rr.pow_cmd_atc",
FT_BOOLEAN,8, TFS(&gsm_a_rr_pow_cmd_atc_value), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_rr_page_mode,
{ "Page Mode","gsm_a.rr.page_mode",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_page_mode_vals), 0x0F,
NULL, HFILL }
},
{ &hf_gsm_a_rr_dedicated_mode_or_tbf,
{ "Dedicated mode or TBF","gsm_a.rr.dedicated_mode_or_tbf",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_dedicated_mode_or_tbf_vals), 0xF0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pow_cmd_epc,
{ "EPC_mode","gsm_a.rr.pow_cmd_epc",
FT_BOOLEAN,8, TFS(&gsm_a_rr_pow_cmd_epc_value), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pow_cmd_fpcepc,
{ "FPC_EPC","gsm_a.rr.pow_cmd_fpcepc",
FT_BOOLEAN,8, TFS(&gsm_a_rr_pow_cmd_fpcepc_value), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pow_cmd_powlev,
{ "POWER LEVEL","gsm_a.rr.pow_cmd_pow",
FT_UINT8,BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_gsm_a_rr_sync_ind_nci,
{ "Normal cell indication(NCI)","gsm_a.rr.sync_ind_nci",
FT_BOOLEAN,8, TFS(&gsm_a_rr_sync_ind_nci_value), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_rr_sync_ind_rot,
{ "Report Observed Time Difference(ROT)","gsm_a.rr.sync_ind_rot",
FT_BOOLEAN,8, TFS(&sm_a_rr_sync_ind_rot_value), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_rr_sync_ind_si,
{ "Synchronization indication(SI)","gsm_a.rr.sync_ind_si",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_sync_ind_si_vals), 0x03,
NULL, HFILL }
},
{ &hf_gsm_a_rr_format_id,
{ "Format Identifier","gsm_a.rr.format_id",
FT_UINT8,BASE_HEX, VALS(gsm_a_rr_freq_list_format_id_vals), 0xce,
NULL, HFILL }
},
{ &hf_gsm_a_rr_format_id2,
{ "Format Identifier","gsm_a.rr.format_id",
FT_UINT8,BASE_HEX, VALS(gsm_a_rr_freq_list_format_id_vals), 0x8e,
NULL, HFILL }
},
{ &hf_gsm_a_rr_channel_mode,
{ "Channel Mode","gsm_a.rr.channel_mode",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_channel_mode_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_channel_mode2,
{ "Channel Mode 2","gsm_a.rr.channel_mode2",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_channel_mode2_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_sc,
{ "SC","gsm_a.rr.SC",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_sc_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_algorithm_id,
{ "Algorithm identifier","gsm_a.rr.algorithm_identifier",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_algorithm_identifier_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_cr,
{ "CR","gsm_a.rr.CR",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_cr_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_multirate_speech_ver,
{ "Multirate speech version","gsm_a.rr.multirate_speech_ver",
FT_UINT8,BASE_DEC, VALS(multirate_speech_ver_vals), 0xe0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_NCSB,
{ "NSCB: Noise Suppression Control Bit","gsm_a.rr.NCSB",
FT_UINT8,BASE_DEC, VALS(NSCB_vals), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ICMI,
{ "ICMI: Initial Codec Mode Indicator","gsm_a.rr.ICMI",
FT_UINT8,BASE_DEC, VALS(ICMI_vals), 0x8,
NULL, HFILL }
},
{ &hf_gsm_a_rr_start_mode,
{ "Start Mode","gsm_a.rr.start_mode",
FT_UINT8,BASE_DEC, NULL, 0x3,
NULL, HFILL }
},
{ &hf_gsm_a_rr_timing_adv,
{ "Timing advance value","gsm_a.rr.timing_adv",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_time_diff,
{ "Time difference value","gsm_a.rr.time_diff",
FT_UINT8,BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_tlli,
{ "TLLI","gsm_a.rr.tlli",
FT_UINT32,BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_tmsi_ptmsi,
{ "TMSI/P-TMSI Value","gsm_a.rr.tmsi_ptmsi",
FT_UINT32,BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_target_mode,
{ "Target mode","gsm_a.rr.target_mode",
FT_UINT8,BASE_DEC, NULL, 0xc0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_wait_indication,
{ "Wait Indication","gsm_a.rr.wait_indication",
FT_UINT8,BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_seq_code,
{ "Sequence Code","gsm_a.rr.seq_code",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_group_cipher_key_number,
{ "Group cipher key number","gsm_a.rr.Group_cipher_key_number",
FT_UINT8,BASE_DEC, NULL, 0x3c,
NULL, HFILL }
},
{ &hf_gsm_a_rr_MBMS_broadcast,
{ "MBMS Broadcast","gsm_a.rr.MBMS_broadcast",
FT_BOOLEAN,8, TFS(&gsm_a_rr_MBMS_broadcast_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_rr_MBMS_multicast,
{ "MBMS Multicast","gsm_a.rr.MBMS_multicast",
FT_BOOLEAN,8, TFS(&gsm_a_rr_MBMS_multicast_value), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_rr_last_segment,
{ "Last Segment","gsm_a.rr.last_segment",
FT_BOOLEAN,8, TFS(&gsm_a_rr_last_segment_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_rr_carrier_ind,
{ "Carrier Indication","gsm_a.rr.carrier_ind",
FT_BOOLEAN,8, TFS(&gsm_a_rr_carrier_ind_value), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ra,
{ "Random Access Information (RA)", "gsm_a.rr.ra",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_T1prim,
{ "T1'", "gsm_a.rr.T1prim",
FT_UINT8, BASE_DEC, NULL, 0xf8,
NULL, HFILL }
},
{ &hf_gsm_a_rr_T3,
{ "T3", "gsm_a.rr.T3",
FT_UINT16, BASE_DEC, NULL, 0x07e0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_T2,
{ "T2", "gsm_a.rr.T2",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_gsm_a_rr_tbf_T1prim,
{ "T1' (TBF)", "gsm_a.rr.tbf.T1prim",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_tbf_T3,
{ "T3 (TBF)", "gsm_a.rr.tbf.T3",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_tbf_T2,
{ "T2 (TBF)", "gsm_a.rr.tbf.T2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rfn,
{ "RFN", "gsm_a.rr.rfn",
FT_UINT16, BASE_DEC, NULL, 0x0,
"Reduced Frame Number", HFILL }
},
{ &hf_gsm_a_rr_RR_cause,
{ "RR cause value","gsm_a.rr.RRcause",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_RR_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_cm_cng_msg_req,
{ "CLASSMARK CHANGE","gsm_a.rr.cm_cng_msg_req",
FT_BOOLEAN,8, TFS(&gsm_a_msg_req_value), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_rr_utran_cm_cng_msg_req,
{ "UTRAN CLASSMARK CHANGE","gsm_a.rr.utran_cm_cng_msg_req",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_utran_cm_cng_msg_req_vals), 0x70,
NULL, HFILL }
},
{ &hf_gsm_a_rr_cdma200_cm_cng_msg_req,
{ "CDMA2000 CLASSMARK CHANGE","gsm_a.rr.cdma200_cm_cng_msg_req",
FT_BOOLEAN,8, TFS(&gsm_a_msg_req_value), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_rr_geran_iu_cm_cng_msg_req,
{ "GERAN IU MODE CLASSMARK CHANGE","gsm_a.rr.geran_iu_cm_cng_msg_req",
FT_BOOLEAN,8, TFS(&gsm_a_msg_req_value), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_rr_chnl_needed_ch1,
{ "Channel 1","gsm_a.rr.chnl_needed_ch1",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_channel_needed_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_chnl_needed_ch2,
{ "Channel 2","gsm_a.rr.chnl_needed_ch2",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_channel_needed_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_chnl_needed_ch3,
{ "Channel 3","gsm_a.rr.chnl_needed_ch3",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_channel_needed_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_chnl_needed_ch4,
{ "Channel 4","gsm_a.rr.chnl_needed_ch4",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_channel_needed_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pkt_estab_cause,
{ "PACKET_ESTABLISHMENT_CAUSE","gsm_a.rr.pkt_estab_cause",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_pkt_estab_cause_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_peak_throughput_class,
{ "PEAK_THROUGHPUT_CLASS","gsm_a.rr.peak_throughput_class",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_radio_priority,
{ "RADIO_PRIORITY","gsm_a.rr.radio_priority",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_radio_priority_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_llc_pdu_type,
{ "LLC_PDU_TYPE","gsm_a.rr.llc_pdu_type",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_llc_pdu_type_value), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rlc_octet_count,
{ "RLC_OCTET_COUNT","gsm_a.rr.rlc_octet_count",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rlc_non_pers_mode_cap,
{ "RLC Non-persistent Mode Capability","gsm_a.rr.rlc_non_pers_mode_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_reduced_latency_cap,
{ "Reduced Latency Capability","gsm_a.rr.reduced_latency_cap",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_reduced_latency_cap_value), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ul_egprs2,
{ "Uplink EGPRS2","gsm_a.rr.ul_egprs2",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_egprs2_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_dl_egprs2,
{ "Downlink EGPRS2","gsm_a.rr.dl_egprs2",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_egprs2_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_emst_ms_cap,
{ "EMST_MS_Capability","gsm_a.rr.emst_ms_cap",
FT_BOOLEAN, BASE_NONE, TFS(&tfs_supported_not_supported), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_suspension_cause,
{ "Suspension cause value","gsm_a.rr.suspension_cause",
FT_UINT8,BASE_DEC, VALS(gsm_a_rr_suspension_cause_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_apdu_id,
{ "APDU ID","gsm_a.rr.apdu_id",
FT_UINT8,BASE_HEX, VALS(gsm_a_rr_apdu_id_vals), 0x0f,
NULL, HFILL }
},
{ &hf_gsm_a_rr_apdu_flags,
{ "APDU Flags","gsm_a.rr.apdu_flags",
FT_UINT8,BASE_HEX, VALS(gsm_a_rr_apdu_flags_vals), 0xf0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v1_b8,
{ "12,2 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v1b8",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x80,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v1_b7,
{ "10,2 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v1b7",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x40,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v1_b6,
{ "7,95 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v1b6",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x20,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v1_b5,
{ "7,40 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v1b5",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v1_b4,
{ "6,70 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v1b4",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v1_b3,
{ "5,90 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v1b3",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v1_b2,
{ "5,15 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v1b2",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v1_b1,
{ "4,75 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v1b1",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v2_b5,
{ "23,85 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v2b5",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x10,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v2_b4,
{ "15,85 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v2b4",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x08,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v2_b3,
{ "12,65 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v2b3",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x04,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v2_b2,
{ "8,85 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v2b2",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x02,
NULL, HFILL }
},
{ &hf_gsm_a_rr_set_of_amr_codec_modes_v2_b1,
{ "6,60 kbit/s codec rate", "gsm_a.rr.set_of_amr_codec_modes_v2b1",
FT_BOOLEAN,8, TFS(&gsm_a_rr_set_of_amr_codec_modes), 0x01,
NULL, HFILL }
},
{ &hf_gsm_a_rr_amr_threshold,
{ "AMR Threshold", "gsm_a.rr.amr_threshold",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gsm_a_rr_amr_threshold_vals_ext, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_amr_hysteresis,
{ "AMR Hysteresis", "gsm_a.rr.amr_hysteresis",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_amr_hysteresis_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pwrc,
{ "PWRC", "gsm_a.rr.pwrc",
FT_BOOLEAN, BASE_NONE, NULL, 0x0,
"Power Control Indicator (PWRC)", HFILL }
},
{ &hf_gsm_a_rr_dtx_bcch,
{ "DTX (BCCH)", "gsm_a.rr.dtx_bcch",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_dtx_bcch_vals), 0x30,
"Discontinuous Transmission (DTX-BCCH)", HFILL }
},
{ &hf_gsm_a_rr_dtx_sacch,
{ "DTX (SACCH)", "gsm_a.rr.dtx_sacch",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_dtx_sacch_vals), 0x00,
"Discontinuous Transmission (DTX-SACCH)", HFILL }
},
{ &hf_gsm_a_rr_radio_link_timeout,
{ "Radio Link Timeout", "gsm_a.rr.radio_link_timeout",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_radio_link_timeout_vals), 0x0f,
"Radio Link Timeout (s)", HFILL }
},
{ &hf_gsm_a_rr_cell_reselect_hyst,
{ "Cell Reselection Hysteresis", "gsm_a.rr.cell_reselect_hyst",
FT_UINT8, BASE_DEC, NULL, 0xe0,
"Cell Reselection Hysteresis (dB)", HFILL }
},
{ &hf_gsm_a_rr_ms_txpwr_max_cch,
{ "MS TXPWR MAX CCH", "gsm_a.rr.ms_txpwr_max_cch",
FT_UINT8, BASE_DEC, NULL, 0x1f,
NULL, HFILL }
},
{ &hf_gsm_a_rr_acs,
{ "ACS", "gsm_a.rr.acs",
FT_BOOLEAN, 8, NULL, 0x80,
"Additional Reselect Param Indicator (ACS)", HFILL }
},
{ &hf_gsm_a_rr_neci,
{ "NECI", "gsm_a.rr.neci",
FT_UINT8, BASE_DEC, NULL, 0x40,
"New Establishment Cause Indicator (NECI)", HFILL }
},
{ &hf_gsm_a_rr_rxlev_access_min,
{ "RXLEV-ACCESS-MIN", "gsm_a.rr.rxlev_access_min",
FT_UINT8, BASE_DEC|BASE_EXT_STRING, &gsm_a_rr_rxlev_vals_ext, 0x3f,
NULL, HFILL }
},
{ &hf_gsm_a_rr_mscr,
{ "MSCR", "gsm_a.rr.mscr",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_mscr_vals), 0x80,
"MSC Release Indicator (MSCR)", HFILL }
},
{ &hf_gsm_a_rr_att,
{ "ATT", "gsm_a.rr.att",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_att_vals), 0x40,
"Attach Indicator (ATT)", HFILL }
},
{ &hf_gsm_a_rr_bs_ag_blks_res,
{ "BS_AG_BLKS_RES", "gsm_a.rr.bs_ag_blks_res",
FT_UINT8, BASE_DEC, NULL, 0x38,
"Access Grant Reserved Blocks (BS_AG_BLKS_RES)", HFILL }
},
{ &hf_gsm_a_rr_ccch_conf,
{ "CCCH-CONF", "gsm_a.rr.ccch_conf",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_ccch_conf_vals), 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_rr_cbq3,
{ "CBQ3", "gsm_a.rr.cbq3",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_cbq3_vals), 0x00,
"Cell Bar Qualify 3", HFILL }
},
{ &hf_gsm_a_rr_bs_pa_mfrms,
{ "BS-PA-MFRMS", "gsm_a.rr.bs_pa_mfrms",
FT_UINT8, BASE_DEC, NULL, 0x07,
NULL, HFILL }
},
{ &hf_gsm_a_rr_t3212,
{ "T3212", "gsm_a.rr.t3212",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Periodic Update period (T3212) (deci-hours)", HFILL }
},
{ &hf_gsm_a_rr_gsm_band,
{ "GSM Band", "gsm_a.rr.gsm_band",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_gsm_band_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_arfcn_first,
{ "ARFCN First", "gsm_a.rr.arfcn_first",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_band_offset,
{ "Band Offset", "gsm_a.rr.band_offset",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_arfcn_range,
{ "ARFCN Range", "gsm_a.rr.arfcn_range",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_lowest_arfcn,
{ "Lowest ARFCN", "gsm_a.rr.lowest_arfcn",
FT_UINT8, BASE_DEC, NULL, 0x7f,
NULL, HFILL }
},
{ &hf_gsm_a_rr_inc_skip_arfcn,
{ "Increment skip ARFCN", "gsm_a.rr.inc_skip_arfcn",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_gprs_resumption_ack,
{ "Ack", "gsm_a.rr.gprs_resumption_ack",
FT_BOOLEAN, 8, TFS(&gsm_a_rr_gprs_resumption_ack_value), 0x01,
"GPRS Resumption Ack bit", HFILL }
},
{ &hf_gsm_a_rr_ext_ind,
{ "EXT-IND", "gsm_a.rr.ext_ind",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_ext_ind_vals), 0x20,
"Extension Indication (EXT-IND)", HFILL }
},
{ &hf_gsm_a_rr_ba_ind,
{ "BA-IND", "gsm_a.rr.ba_ind",
FT_UINT8, BASE_DEC, NULL, 0x00,
"BCCH Allocation Indication (BA-IND)", HFILL }
},
{ &hf_gsm_a_rr_multiband_reporting,
{ "Multiband Reporting", "gsm_a.rr.multiband_reporting",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Number of cells to be reported in each band if Multiband Reporting", HFILL }
},
{ &hf_gsm_a_rr_ncc_permitted,
{ "NCC Permitted", "gsm_a.rr.ncc_permitted",
FT_UINT8, BASE_HEX, NULL, 0xff,
NULL, HFILL }
},
{ &hf_gsm_a_rr_max_retrans,
{ "Max retrans", "gsm_a.rr.max_retrans",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_max_retrans_vals), 0xc0,
"Maximum number of retransmissions", HFILL }
},
{ &hf_gsm_a_rr_tx_integer,
{ "Tx-integer", "gsm_a.rr.tx_integer",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_tx_integer_vals), 0x3c,
"Number of Slots to spread Transmission (Tx-integer)", HFILL }
},
{ &hf_gsm_a_rr_cell_barr_access,
{ "CELL_BARR_ACCESS", "gsm_a.rr.cell_barr_access",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_cell_barr_access_vals), 0x02,
"Cell Barred for Access (CELL_BARR_ACCESS)", HFILL }
},
{ &hf_gsm_a_rr_re,
{ "RE", "gsm_a.rr.re",
FT_BOOLEAN, 8, NULL, 0x01,
"Call re-establishment allowed (RE)", HFILL }
},
{ &hf_gsm_a_rr_acc,
{ "ACC", "gsm_a.rr.acc",
FT_UINT16, BASE_HEX, NULL, 0xffff,
"Access Control Class N barred (ACC)", HFILL }
},
{ &hf_gsm_a_rr_nch_position,
{ "NCH Position", "gsm_a.rr.nch_position",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_nch_position_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si2ter_mp_change_mark,
{ "SI2ter Measurement Parameter Change Mark", "gsm_a.rr.si2ter_mp_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si2ter_3g_change_mark,
{ "SI2ter 3G Change Mark", "gsm_a.rr.si2ter_3g_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si2ter_index,
{ "SI2ter Index", "gsm_a.rr.si2ter_index",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si2ter_count,
{ "SI2ter Count", "gsm_a.rr.si2ter_count",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_fdd_uarfcn,
{ "FDD UARFCN", "gsm_a.rr.fdd_uarfcn",
FT_UINT16, BASE_DEC, NULL, 0x0000,
NULL, HFILL }
},
{ &hf_gsm_a_rr_bandwidth_fdd,
{ "Bandwidth FDD", "gsm_a.rr.bandwidth_fdd",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_tdd_uarfcn,
{ "TDD UARFCN", "gsm_a.rr.tdd_uarfcn",
FT_UINT16, BASE_DEC, NULL, 0x0000,
NULL, HFILL }
},
{ &hf_gsm_a_rr_bandwidth_tdd,
{ "Bandwidth TDD", "gsm_a.rr.bandwidth_tdd",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_arfcn,
{ "ARFCN", "gsm_a.rr.arfcn",
FT_UINT16, BASE_DEC, NULL, 0x0000,
"Absolute Radio Frequency Channel Number (ARFCN)", HFILL }
},
{ &hf_gsm_a_rr_bsic,
{ "BSIC", "gsm_a.rr.bsic",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Base Station Identify Code (BSIC)", HFILL }
},
{ &hf_gsm_a_rr_qsearch_i,
{ "Qsearch I", "gsm_a.rr.qsearch_i",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_qsearch_x_vals), 0x00,
"Search for 3G cells if signal level is below (0 7) or above (8 15) threshold (Qsearch I)", HFILL }
},
{ &hf_gsm_a_rr_fdd_qoffset,
{ "FDD Qoffset", "gsm_a.rr.fdd_qoffset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xdd_qoffset_vals), 0x00,
"Offset to RLA_C for cell re selection to FDD access technology (FDD Qoffset)", HFILL }
},
{ &hf_gsm_a_rr_fdd_qmin,
{ "FDD Qmin", "gsm_a.rr.fdd_qmin",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_fdd_qmin_vals), 0x00,
"Minimum threshold for Ec/No for UTRAN FDD cell re-selection (FDD Qmin)", HFILL }
},
{ &hf_gsm_a_rr_tdd_qoffset,
{ "TDD Qoffset", "gsm_a.rr.tdd_qoffset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xdd_qoffset_vals), 0x00,
"Offset to RLA_C for cell re selection to TDD access technology (TDD Qoffset)", HFILL }
},
{ &hf_gsm_a_rr_fdd_qmin_offset,
{ "FDD Qmin Offset", "gsm_a.rr.fdd_qmin_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_fdd_qmin_offset_vals), 0x00,
"Offset to FDD Qmin value (FDD Qmin Offset)", HFILL }
},
{ &hf_gsm_a_rr_fdd_rscpmin,
{ "FDD RSCPmin", "gsm_a.rr.fdd_rscpmin",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_fdd_rscpmin_vals), 0x00,
"Minimum threshold of RSCP for UTRAN FDD cell re-selection (FDD RSCPmin)", HFILL }
},
{ &hf_gsm_a_rr_3g_ba_ind,
{ "3G BA-IND", "gsm_a.rr.3g_ba_ind",
FT_UINT8, BASE_DEC, NULL, 0x00,
"3G BCCH Allocation Indication (3G BA-IND)", HFILL }
},
{ &hf_gsm_a_rr_mp_change_mark,
{ "Measurement Parameter Change Mark", "gsm_a.rr.mp_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si2quater_index,
{ "SI2quater Index", "gsm_a.rr.si2quater_index",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si2quater_count,
{ "SI2quater Count", "gsm_a.rr.si2quater_count",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_gsm_report_type,
{ "Report Type", "gsm_a.rr.gsm_report_type",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_gsm_report_type_value), 0x0,
"Report type the MS shall use (Report Type)", HFILL }
},
{ &hf_gsm_a_rr_serving_band_reporting,
{ "Serving Band Reporting", "gsm_a.rr.serving_band_reporting",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Number of cells reported from the GSM serving frequency band (Serving Band Reporting)", HFILL }
},
{ &hf_gsm_a_rr_frequency_scrolling,
{ "Frequency Scrolling", "gsm_a.rr.frequency_scrolling",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_frequency_scrolling_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rep_priority,
{ "Rep Priority", "gsm_a.rr.rep_priority",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_rep_priority_value), 0x0,
"Reporting Priority", HFILL }
},
{ &hf_gsm_a_rr_report_type,
{ "Report Type", "gsm_a.rr.report_type",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_report_type_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_reporting_rate,
{ "Reporting Rate", "gsm_a.rr.reporting_rate",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_reporting_rate_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_invalid_bsic_reporting,
{ "Invalid BSIC Reporting", "gsm_a.rr.invalid_bsic_reporting",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_invalid_bsic_reporting_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_scale_ord,
{ "Scale Ord", "gsm_a.rr.scale_ord",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_scale_ord_vals), 0x00,
"Offset used for the reported RXLEV values (Scale Ord)", HFILL }
},
{ &hf_gsm_a_rr_900_reporting_offset,
{ "900 Reporting Offset", "gsm_a.rr.900_reporting_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xxx_reporting_offset_vals), 0x00,
"Offset to the reported value when prioritising the cells for reporting for GSM frequency band 900 (900 Reporting Offset)", HFILL }
},
{ &hf_gsm_a_rr_900_reporting_threshold,
{ "900 Reporting Threshold", "gsm_a.rr.900_reporting_threshold",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_gsm_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for GSM frequency band 900 (900 Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_1800_reporting_offset,
{ "1800 Reporting Offset", "gsm_a.rr.1800_reporting_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xxx_reporting_offset_vals), 0x00,
"Offset to the reported value when prioritising the cells for reporting for GSM frequency band 1800 (1800 Reporting Offset)", HFILL }
},
{ &hf_gsm_a_rr_1800_reporting_threshold,
{ "1800 Reporting Threshold", "gsm_a.rr.1800_reporting_threshold",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_gsm_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for GSM frequency band 1800 (1800 Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_400_reporting_offset,
{ "400 Reporting Offset", "gsm_a.rr.400_reporting_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xxx_reporting_offset_vals), 0x00,
"Offset to the reported value when prioritising the cells for reporting for GSM frequency band 400 (400 Reporting Offset)", HFILL }
},
{ &hf_gsm_a_rr_400_reporting_threshold,
{ "400 Reporting Threshold", "gsm_a.rr.400_reporting_threshold",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_gsm_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for GSM frequency band 400 (400 Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_1900_reporting_offset,
{ "1900 Reporting Offset", "gsm_a.rr.1900_reporting_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xxx_reporting_offset_vals), 0x00,
"Offset to the reported value when prioritising the cells for reporting for GSM frequency band 1900 (1900 Reporting Offset)", HFILL }
},
{ &hf_gsm_a_rr_1900_reporting_threshold,
{ "1900 Reporting Threshold", "gsm_a.rr.1900_reporting_threshold",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_gsm_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for GSM frequency band 1900 (1900 Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_850_reporting_offset,
{ "850 Reporting Offset", "gsm_a.rr.850_reporting_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xxx_reporting_offset_vals), 0x00,
"Offset to the reported value when prioritising the cells for reporting for GSM frequency band 850 (850 Reporting Offset)", HFILL }
},
{ &hf_gsm_a_rr_850_reporting_threshold,
{ "850 Reporting Threshold", "gsm_a.rr.900_reporting_threshold",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_gsm_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for GSM frequency band 850 (850 Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_network_control_order,
{ "Network Control Order", "gsm_a.rr.network_control_order",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_network_control_order_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_nc_non_drx_period,
{ "NC Non DRX Period", "gsm_a.rr.nc_non_drx_period",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_nc_non_drx_period_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_nc_reporting_period_i,
{ "NC Reporting Period I", "gsm_a.rr.nc_reporting_period_i",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_nc_reporting_period_x_vals), 0x00,
"NC Reporting Period in Packet Idle mode (NC Reporting Period I)", HFILL }
},
{ &hf_gsm_a_rr_nc_reporting_period_t,
{ "NC Reporting Period T", "gsm_a.rr.nc_reporting_period_t",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_nc_reporting_period_x_vals), 0x00,
"NC Reporting Period in Packet Transfer mode (NC Reporting Period T)", HFILL }
},
{ &hf_gsm_a_rr_index_start_3g,
{ "Index Start 3G", "gsm_a.rr.index_start_3g",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_absolute_index_start_emr,
{ "Absolute Index Start EMR", "gsm_a.rr.absolute_index_start_emr",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_qsearch_c_initial,
{ "QSearch C Initial", "gsm_a.rr.qsearch_c_initial",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_qsearch_c_initial_value), 0x0,
"Qsearch value to be used in connected mode before Qsearch C is received (QSearch C Initial)", HFILL }
},
{ &hf_gsm_a_rr_fdd_rep_quant,
{ "FDD Rep Quant", "gsm_a.rr.fdd_rep_quant",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_fdd_rep_quant_value), 0x0,
"FDD Reporting Quantity (FDD Rep Quant)", HFILL }
},
{ &hf_gsm_a_rr_fdd_multirat_reporting,
{ "FDD Multirat Reporting", "gsm_a.rr.fdd_multirat_reporting",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Number of cells from the FDD access technology that shall be included in the list of strongest cells or in the measurement report (FDD Multirat Reporting)", HFILL }
},
{ &hf_gsm_a_rr_tdd_multirat_reporting,
{ "TDD Multirat Reporting", "gsm_a.rr.tdd_multirat_reporting",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Number of cells from the TDD access technology that shall be included in the list of strongest cells or in the measurement report (TDD Multirat Reporting)", HFILL }
},
{ &hf_gsm_a_rr_qsearch_p,
{ "Qsearch P", "gsm_a.rr.qsearch_p",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_qsearch_x_vals), 0x00,
"Search for 3G cells if signal level below threshold (Qsearch P)", HFILL }
},
{ &hf_gsm_a_rr_3g_search_prio,
{ "3G Search Prio (ignored in Rel-8)", "gsm_a.rr.3g_search_prio",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_3g_search_prio_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_fdd_reporting_offset,
{ "FDD Reporting Offset", "gsm_a.rr.fdd_reporting_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xxx_reporting_offset_vals), 0x00,
"Offset to the reported value when prioritising the cells for reporting for FDD access technology (FDD Reporting Offset)", HFILL }
},
{ &hf_gsm_a_rr_fdd_reporting_threshold_rscp,
{ "FDD Reporting Threshold RSCP", "gsm_a.rr.fdd_reporting_threshold_rscp",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_wcdma_rscp_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for FDD access technology (FDD Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_fdd_reporting_threshold_ecn0,
{ "FDD Reporting Threshold EcN0", "gsm_a.rr.fdd_reporting_threshold_ecn0",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_wcdma_ecn0_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for FDD access technology (FDD Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_tdd_reporting_offset,
{ "TDD Reporting Offset", "gsm_a.rr.tdd_reporting_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xxx_reporting_offset_vals), 0x00,
"Offset to the reported value when prioritising the cells for reporting for TDD access technology (TDD Reporting Offset)", HFILL }
},
{ &hf_gsm_a_rr_tdd_reporting_threshold_rscp,
{ "TDD Reporting Threshold RSCP", "gsm_a.rr.tdd_reporting_threshold_rscp",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_wcdma_rscp_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for TDD access technology (TDD Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_tdd_reporting_threshold_ecn0,
{ "TDD Reporting Threshold EcN0", "gsm_a.rr.tdd_reporting_threshold_ecn0",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_wcdma_ecn0_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for TDD access technology (TDD Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_fdd_reporting_threshold_2,
{ "FDD Reporting Threshold 2", "gsm_a.rr.fdd_reporting_threshold_2",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Reporting threshold for the CPICH parameter (Ec/No or RSCP) that is not reported according to FDD_REP_QUANT (FDD Reporting Threshold 2)", HFILL }
},
{ &hf_gsm_a_rr_3g_ccn_active,
{ "3G CCN Active", "gsm_a.rr.3g_ccn_active",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_3g_ccn_active_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_700_reporting_offset,
{ "700 Reporting Offset", "gsm_a.rr.700_reporting_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xxx_reporting_offset_vals), 0x00,
"Offset to the reported value when prioritising the cells for reporting for GSM frequency band 700 (700 Reporting Offset)", HFILL }
},
{ &hf_gsm_a_rr_700_reporting_threshold,
{ "700 Reporting Threshold", "gsm_a.rr.700_reporting_threshold",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_gsm_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for GSM frequency band 700 (700 Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_810_reporting_offset,
{ "810 Reporting Offset", "gsm_a.rr.810_reporting_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_xxx_reporting_offset_vals), 0x00,
"Offset to the reported value when prioritising the cells for reporting for GSM frequency band 810 (810 Reporting Offset)", HFILL }
},
{ &hf_gsm_a_rr_810_reporting_threshold,
{ "810 Reporting Threshold", "gsm_a.rr.810_reporting_threshold",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_gsm_reporting_threshold_vals), 0x00,
"Apply priority reporting if the reported value is above threshold for GSM frequency band 810 (810 Reporting Threshold)", HFILL }
},
{ &hf_gsm_a_rr_cbq,
{ "CBQ", "gsm_a.rr.cbq",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Cell Bar Qualify", HFILL }
},
{ &hf_gsm_a_rr_cell_reselect_offset,
{ "Cell Reselect Offset", "gsm_a.rr.cell_reselect_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_cell_reselect_offset_vals), 0x00,
"Offset to the C2 reselection criterion (Cell Reselect Offset)", HFILL }
},
{ &hf_gsm_a_rr_temporary_offset,
{ "Temporary Offset", "gsm_a.rr.temporary_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_temporary_offset_vals), 0x0,
"Negative offset to C2 for the duration of Penalty Time (Temporary Offset)", HFILL }
},
{ &hf_gsm_a_rr_penalty_time,
{ "Penalty Time", "gsm_a.rr.penalty_time",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_penalty_time_vals), 0x0,
"Duration for which the temporary offset is applied (Penalty Time)", HFILL }
},
{ &hf_gsm_a_rr_gprs_ra_colour,
{ "GPRS RA Colour", "gsm_a.rr.gprs_ra_colour",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si13_position,
{ "SI13 Position", "gsm_a.rr.si13_position",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_si13_position_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_power_offset,
{ "Power Offset", "gsm_a.rr.power_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_power_offset_vals), 0x0,
"Power offset used in conjunction with the MS TXPWR MAX CCH parameter by the class 3 DCS 1800 MS (Power Offset)", HFILL }
},
{ &hf_gsm_a_rr_si2quater_position,
{ "SI2quater Position", "gsm_a.rr.si2quater_position",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_si2quater_position_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si13alt_position,
{ "SI13alt Position", "gsm_a.rr.si13alt_position",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_si13alt_position_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_prio_thr,
{ "Prio Thr", "gsm_a.rr.prio_thr",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_prio_thr_vals), 0x0,
"Prio signal strength threshold is related to RXLEV ACCESS_MIN (Prio Thr)", HFILL }
},
{ &hf_gsm_a_rr_lsa_offset,
{ "LSA Offset", "gsm_a.rr.lsa_offset",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_lsa_offset_vals), 0x0,
"Offset to be used for LSA cell re selection between cells with the same LSA priorities (LSA Offset)", HFILL }
},
{ &hf_gsm_a_rr_cell_id,
{ "Cell Identity", "gsm_a.rr.cell_id",
FT_UINT16, BASE_HEX_DEC, 0, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_paging_channel_restructuring,
{ "Paging Channel Restructuring", "gsm_a.rr.paging_channel_restructuring",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_paging_channel_restructuring_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_nln_sacch,
{ "NLN (SACCH)", "gsm_a.rr.nln_sacch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_nln_status_sacch,
{ "NLN Status (SACCH)", "gsm_a.rr.nln_status_sacch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_nln_pch,
{ "NLN (PCH)", "gsm_a.rr.nln_pch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_nln_status_pch,
{ "NLN Status (PCH)", "gsm_a.rr.nln_status_pch",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_vbs_vgcs_inband_notifications,
{ "Inband Notifications", "gsm_a.rr.vbs_vgcs_inband_notifications",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_vbs_vgcs_inband_notifications_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_vbs_vgcs_inband_pagings,
{ "Inband Pagings", "gsm_a.rr.vbs_vgcs_inband_pagings",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_vbs_vgcs_inband_pagings_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rac,
{ "RAC", "gsm_a.rr.rac",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Routeing Area Code", HFILL }
},
{ &hf_gsm_a_rr_max_lapdm,
{ "Max LAPDm", "gsm_a.rr.max_lapdm",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_max_lapdm_vals), 0x0,
"Maximum number of LAPDm frames on which a layer 3 can be segmented into and be sent on the main DCCH (Max LAPDm)", HFILL }
},
{ &hf_gsm_a_rr_gprs_ms_txpwr_max_ccch,
{ "GPRS MS TxPwr Max CCH", "gsm_a.rr.gprs_ms_txpwr_max_cch",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_dedicated_mode_mbms_notification_support,
{ "Dedicated Mode MBMS Notification Support", "gsm_a.rr.dedicated_mode_mbms_notification_support",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_dedicated_mode_mbms_notification_support_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_mnci_support,
{ "MNCI Support", "gsm_a.rr.mnci_support",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_mnci_support_value), 0x0,
"MBMS Neighbouring Cell Information Support (MNCI Support)", HFILL }
},
{ &hf_gsm_a_rr_amr_config,
{ "AMR Configuration", "gsm_a.rr.amr_config",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_bcch_change_mark,
{ "BCCH Change Mark", "gsm_a.rr.bcch_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si_change_field,
{ "SI Change Field", "gsm_a.rr.si_change_field",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_si_change_field_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_si13_change_mark,
{ "SI13 Change Mark", "gsm_a.rr.si13_change_mark",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_hsn,
{ "HSN", "gsm_a.rr.hsn",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Hopping Sequence Number (HSN)", HFILL }
},
{ &hf_gsm_a_rr_rfl_number,
{ "RFL Number", "gsm_a.rr.rfl_number",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Radio Frequency List Number (RFL Number)", HFILL }
},
{ &hf_gsm_a_rr_arfcn_index,
{ "ARFCN Index", "gsm_a.rr.arfcn_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ma_length,
{ "MA Length", "gsm_a.rr.ma_length",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Mobile Allocation Length (MA Length)", HFILL }
},
{ &hf_gsm_a_rr_psi1_repeat_period,
{ "PSI1 Repeat Period", "gsm_a.rr.psi1_repeat_period",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_psi1_repeat_period_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pbcch_pb,
{ "Pb", "gsm_a.rr.pbcch_pb",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_pbcch_pb_vals), 0x0,
"Power reduction on PBCCH/PCCCH (Pb)", HFILL }
},
{ &hf_gsm_a_rr_pbcch_tsc,
{ "TSC", "gsm_a.rr.pbcch_tsc",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Training Sequence Code for PBCCH (TSC)", HFILL }
},
{ &hf_gsm_a_rr_pbcch_tn,
{ "TN", "gsm_a.rr.pbcch_tn",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Timeslot Number for PCCH (TN)", HFILL }
},
{ &hf_gsm_a_rr_spgc_ccch_sup,
{ "SPGC CCCH Sup", "gsm_a.rr.spgc_ccch_sup",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_spgc_ccch_sup_value), 0x0,
"Split PG Cycle Code on CCCH Support (SPGC CCCH Sup)", HFILL }
},
{ &hf_gsm_a_rr_priority_access_thr,
{ "Priority Access Thr", "gsm_a.rr.priority_access_thr",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_priority_access_thr_vals), 0x0,
"Priority Access Threshold for packet access (Priority Access Thr)", HFILL }
},
{ &hf_gsm_a_rr_nmo,
{ "NMO", "gsm_a.rr.nmo",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_nmo_vals), 0x0,
"Network mode of Operation (NMO)", HFILL }
},
{ &hf_gsm_a_rr_t3168,
{ "T3168", "gsm_a.rr.t3168",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_t3168_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_t3192,
{ "T3192", "gsm_a.rr.t3192",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_t3192_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_drx_timer_max,
{ "DRX Timer Max", "gsm_a.rr.drx_timer_max",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_drx_timer_max_vals), 0x0,
"Discontinuous Reception Timer Max (DRX Timer Max)", HFILL }
},
{ &hf_gsm_a_rr_access_burst_type,
{ "Access Burst Type", "gsm_a.rr.access_burst_type",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_access_burst_type_value), 0x0,
"Format used in the PACKET CHANNEL REQUEST message, the PS HANDOVER ACCESS message, the PTCCH uplink block and in the PACKET CONTROL ACKNOWLEDGMENT message (Access Burst Type)", HFILL }
},
{ &hf_gsm_a_rr_control_ack_type,
{ "Control Ack Type", "gsm_a.rr.control_ack_type",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_control_ack_type_value), 0x0,
"Default format of the PACKET CONTROL ACKNOWLEDGMENT message (Control Ack Type)", HFILL }
},
{ &hf_gsm_a_rr_bs_cv_max,
{ "BS CV Max", "gsm_a.rr.bs_cv_max",
FT_UINT8, BASE_DEC, NULL, 0x0,
"Base Station Countdown Value Maximum (BS CV Max)", HFILL }
},
{ &hf_gsm_a_rr_pan_dec,
{ "PAN Dec", "gsm_a.rr.pan_dec",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pan_inc,
{ "PAN Inc", "gsm_a.rr.pan_inc",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pan_max,
{ "PAN Max", "gsm_a.rr.pan_max",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_pan_max_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_egprs_packet_channel_request,
{ "EGPRS Packet Channel Request", "gsm_a.rr.egprs_packet_channel_request",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_egprs_packet_channel_request_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_bep_period,
{ "BEP Period", "gsm_a.rr.bep_period",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_bep_period_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pfc_feature_mode,
{ "PFC Feature Mode", "gsm_a.rr.pfc_feature_mode",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_pfc_feature_mode_value), 0x0,
"Packet Flow Context Feature Mode (PFC Feature Mode)", HFILL }
},
{ &hf_gsm_a_rr_dtm_support,
{ "DTM Support", "gsm_a.rr.dtm_support",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_dtm_support_value), 0x0,
"Dual Transfer Mode Support (DTM Support)", HFILL }
},
{ &hf_gsm_a_rr_bss_paging_coordination,
{ "BSS Paging Coordination", "gsm_a.rr.bss_paging_coordination",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_bss_paging_coordination_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ccn_active,
{ "CCN Active", "gsm_a.rr.ccn_active",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_ccn_active_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_nw_ext_utbf,
{ "NW Ext UTBF", "gsm_a.rr.nw_ext_utbf",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_nw_ext_utbf_value), 0x0,
"Network Extended Uplink TBF (NW Ext UTBF)", HFILL }
},
{ &hf_gsm_a_rr_multiple_tbf_capability,
{ "Multiple TBF Capability", "gsm_a.rr.multiple_tbf_capability",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_multiple_tbf_capability_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ext_utbf_no_data,
{ "Ext UTBF No Data", "gsm_a.rr.ext_utbf_no_data",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_ext_utbf_no_data_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_dtm_enhancements_capability,
{ "DTM Enhancements Capability", "gsm_a.rr.dtm_enhancements_capability",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_dtm_enhancements_capability_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_reduced_latency_access,
{ "Reduced Latency Access", "gsm_a.rr.reduced_latency_access",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_reduced_latency_access_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_alpha,
{ "Alpha", "gsm_a.rr.alpha",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_alpha_vals), 0x0,
"Alpha parameter for GPR MS output power control (Alpha)", HFILL }
},
{ &hf_gsm_a_rr_t_avg_w,
{ "T Avg W", "gsm_a.rr.t_avg_w",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_t_avg_x_vals), 0x0,
"Signal strength filter period for power control in packet idle mode", HFILL }
},
{ &hf_gsm_a_rr_t_avg_t,
{ "T Avg T", "gsm_a.rr.t_avg_t",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_t_avg_x_vals), 0x0,
"Signal strength filter period for power control in packet transfer mode", HFILL }
},
{ &hf_gsm_a_rr_pc_meas_chan,
{ "PC Meas Chan", "gsm_a.rr.pc_meas_chan",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_pc_meas_chan_value), 0x0,
"Channel used to measure the received power level on the downlink for the purpose of the uplink power control (PC Meas Chan)", HFILL }
},
{ &hf_gsm_a_rr_n_avg_i,
{ "N Avg I", "gsm_a.rr.n_avg_i",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_n_avg_i_vals), 0x0,
"Interfering signal strength filter constant for power control (N Avg I)", HFILL }
},
{ &hf_gsm_a_rr_sgsnr,
{ "SGSNR", "gsm_a.rr.sgsnr",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_sgsnr_value), 0x0,
"SGSN Release (SGSNR)", HFILL }
},
{ &hf_gsm_a_rr_si_status_ind,
{ "SI Status Ind", "gsm_a.rr.si_status_ind",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_si_status_ind_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_lb_ms_txpwr_max_cch,
{ "LB MS TxPwr Max CCCH", "gsm_a.rr.n_avg_i",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_n_avg_i_vals), 0x0,
"Maximum TX power level an MS is allowed to use on all other than DCS 1800 and PCS 1900 frequency bands when accessing the system until otherwise commanded (LB MS TxPwr Max CCCH)", HFILL }
},
{ &hf_gsm_a_rr_si2n_support,
{ "SI2n Support", "gsm_a.rr.si2n_support",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_si2n_support_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_mi_index,
{ "Measurement Information Index", "gsm_a.rr.mi_index",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_mi_count,
{ "Measurement Information Count", "gsm_a.rr.mi_count",
FT_UINT8, BASE_DEC, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_3g_wait,
{ "3G Wait", "gsm_a.rr.3g_wait",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_3g_wait_vals), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_qsearch_c,
{ "Qsearch C", "gsm_a.rr.qsearch_c",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_qsearch_x_vals), 0x00,
"Search for 3G cells if signal level is below (0 7) or above (8 15) threshold (Qsearch C)", HFILL }
},
{ &hf_gsm_a_rr_bsic_seen,
{ "BSIC Seen", "gsm_a.rr.bsic_seen",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_bsic_seen_value), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_scale,
{ "Scale", "gsm_a.rr.scale",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_scale_value), 0x0,
"Offset applied for the reported RXLEV values (Scale)", HFILL }
},
{ &hf_gsm_a_rr_mean_bep_gmsk,
{ "Mean BEP GMSK", "gsm_a.rr.mean_bep_gmsk",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_mean_bep_gmsk_vals), 0x00,
"Mean Bit Error Probability in GMSK (Mean BEP GMSK)", HFILL }
},
{ &hf_gsm_a_rr_mean_cv_bep,
{ "CV BEP", "gsm_a.rr.cv_bep",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_cv_bep_vals), 0x00,
"Coefficient of Variation of the Bit Error Probability (CV BEP)", HFILL }
},
{ &hf_gsm_a_rr_nbr_rcvd_blocks,
{ "Nb Rcvd Blocks", "gsm_a.rr.nbr_rcvd_blocks",
FT_UINT8, BASE_DEC, NULL, 0x00,
"Number of correctly decoded blocks that were completed during the measurement report period (Nb Rcvd Blocks)", HFILL }
},
{ &hf_gsm_a_rr_reporting_quantity,
{ "Reporting Quantity", "gsm_a.rr.reporting_quantity",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_3g_priority_param_desc_utran_start,
{ "UTRAN Start", "gsm_a.rr.3g_priority.utran_start",
FT_BOOLEAN, BASE_NONE, TFS(&priority_utran_start), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_3g_priority_param_desc_utran_stop,
{ "UTRAN Stop", "gsm_a.rr.3g_priority.utran_stop",
FT_BOOLEAN, BASE_NONE, TFS(&priority_utran_stop), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_3g_priority_param_desc_default_utran_prio,
{ "DEFAULT_UTRAN_PRIORITY", "gsm_a.rr.3g_priority.default_utran_prio",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_3g_priority_param_desc_default_threshold_utran,
{ "DEFAULT_THRESH_UTRAN", "gsm_a.rr.3g_priority.default_threshold_utran",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_thresh_utran_eutran_high_low), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_3g_priority_param_desc_default_utran_qrxlevmin,
{ "DEFAULT_UTRAN_QRXLEVMIN", "gsm_a.rr.3g_priority.default_utran_qrxlevmin",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_utran_qrxlevmin), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_utran_frequency_index,
{ "UTRAN Frequency Index", "gsm_a.rr.3g_priority.utran_frequency_index",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_utran_priority,
{ "UTRAN_PRIORITY", "gsm_a.rr.3g_priority.utran_priority",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_thresh_utran_high,
{ "THRESH_UTRAN_high", "gsm_a.rr.3g_priority.thres_utran_high",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_thresh_utran_eutran_high_low), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_thresh_utran_low,
{ "THRESH_UTRAN_low", "gsm_a.rr.3g_priority.thres_utran_low",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_thresh_utran_eutran_high_low), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_utran_qrxlevmin,
{ "UTRAN_QRXLEVMIN", "gsm_a.rr.3g_priority.utran_qrxlevmin",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_utran_qrxlevmin), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_ccn_active,
{ "E-UTRAN_CCN_ACTIVE", "gsm_a.rr.3g_priority.eutran_ccn_active",
FT_BOOLEAN, BASE_NONE, TFS(&eutran_ccn_active), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_start,
{ "E-UTRAN Start", "gsm_a.rr.3g_priority.eutran_start",
FT_BOOLEAN, BASE_NONE, TFS(&priority_utran_start), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_stop,
{ "E-UTRAN Stop", "gsm_a.rr.3g_priority.utran_stop",
FT_BOOLEAN, BASE_NONE, TFS(&priority_utran_stop), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_qsearch_c_eutran_initial,
{ "Qsearch_C_E-UTRAN_Initial", "gsm_a.rr.qsearch_c_eutran_initial",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_qsearch_c_eutran_initial), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_multirat_reporting,
{ "E-UTRAN_MULTIRAT_REPORTING (nb of E-UTRAN cells to be included in measurement report)", "gsm_a.rr.eutran_multirat_reporting",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_fdd_reporting_threshold_rsrp,
{ "E-UTRAN_FDD_REPORTING_THRESHOLD", "gsm_a.rr.eutran_fdd_reporting_threshold_rsrp",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_lte_rsrp_reporting_threshold_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_fdd_reporting_threshold_rsrq,
{ "E-UTRAN_FDD_REPORTING_THRESHOLD", "gsm_a.rr.eutran_fdd_reporting_threshold_rsrq",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_lte_rsrq_reporting_threshold_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_fdd_reporting_threshold_2,
{ "E-UTRAN_FDD_REPORTING_THRESHOLD_2", "gsm_a.rr.eutran_fdd_reporting_threshold_2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_fdd_reporting_offset,
{ "E-UTRAN_FDD_REPORTING_OFFSET", "gsm_a.rr.eutran_fdd_reporting_offset",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_tdd_reporting_threshold_rsrp,
{ "E-UTRAN_TDD_REPORTING_THRESHOLD", "gsm_a.rr.eutran_tdd_reporting_threshold_rsrp",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_lte_rsrp_reporting_threshold_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_tdd_reporting_threshold_rsrq,
{ "E-UTRAN_TDD_REPORTING_THRESHOLD", "gsm_a.rr.eutran_tdd_reporting_threshold_rsrq",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_lte_rsrq_reporting_threshold_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_tdd_reporting_threshold_2,
{ "E-UTRAN_TDD_REPORTING_THRESHOLD_2", "gsm_a.rr.eutran_tdd_reporting_threshold_2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_tdd_reporting_offset,
{ "E-UTRAN_TDD_REPORTING_OFFSET", "gsm_a.rr.eutran_tdd_reporting_offset",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_fdd_measurement_report_offset,
{ "E-UTRAN_FDD_MEASUREMENT_REPORT_OFFSET", "gsm_a.rr.eutran_fdd_measurement_report_offset",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_tdd_measurement_report_offset,
{ "E-UTRAN_TDD_MEASUREMENT_REPORT_OFFSET", "gsm_a.rr.eutran_tdd_measurement_report_offset",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_reporting_granularity,
{ "REPORTING_GRANULARITY", "gsm_a.rr.reporting_granularity",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_default_measurement_control_eutran,
{ "DEFAULT_Measurement_Control_E-UTRAN", "gsm_a.rr.eutran_default_measurement_control_eutran",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_measurement_control_eutran,
{ "Measurement_Control_E-UTRAN", "gsm_a.rr.eutran_measurement_control_eutran",
FT_BOOLEAN, BASE_NONE, TFS(&measurement_control_eutran), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_qsearch_p_eutran,
{ "Qsearch_P_E-UTRAN", "gsm_a.rr.qsearch_p_eutran",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_serving_cell_priority_param_geran_priority,
{ "GERAN_PRIORITY", "gsm_a.rr.serving_cell_priority_param_geran_priority",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_serving_cell_priority_param_thresh_prio_search,
{ "THRESH_Priority_Search", "gsm_a.rr.serving_cell_priority_param_thresh_prio_search",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_serving_cell_thresh_priority_search), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_serving_cell_priority_param_thresh_gsm_low,
{ "THRESH_GSM_low", "gsm_a.rr.serving_cell_priority_param_thresh_gsm_low",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_serving_cell_thresh_gsm_low), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_serving_cell_priority_param_h_prio,
{ "H_PRIO", "gsm_a.rr.serving_cell_priority_param_h_prio",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_serving_cell_priority_param_h_prio), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_serving_cell_priority_param_t_reselection,
{ "T_Reselection", "gsm_a.rr.serving_cell_priority_param_t_reselection",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_serving_cell_priority_param_t_reselection), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_earfcn,
{ "EARFCN", "gsm_a.rr.earfcn",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_measurement_bandwidth,
{ "Measurement Bandwidth", "gsm_a.rr.eutran_measurement_bandwidth",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_eutran_measurement_bandwidth), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_priority,
{ "E-UTRAN_PRIORITY", "gsm_a.rr.eutran_priority",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_thresh_eutran_high,
{ "THRESH_EUTRAN_high", "gsm_a.rr.thresh_eutran_high",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_thresh_utran_eutran_high_low), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_thresh_eutran_low,
{ "THRESH_EUTRAN_low", "gsm_a.rr.thresh_eutran_low",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_thresh_utran_eutran_high_low), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_qrxlevmin,
{ "E-UTRAN_QRXLEVMIN", "gsm_a.rr.eutran_qrxlevmin",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_eutran_qrxlevmin), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_pcid,
{ "PCID", "gsm_a.rr.pcid",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_pcid_bitmap_group,
{ "PCID_BITMAP_GROUP", "gsm_a.rr.pcid_bitmap_group",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_pcid_pattern_length,
{ "PCID_Pattern_length", "gsm_a.rr.pcid_pattern_length",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_pcid_psc_pattern_length), 0x00,
NULL, HFILL }
},
#if 0
{ &hf_gsm_a_rr_eutran_pcid_pattern,
{ "PCID_Pattern", "gsm_a.rr.pcid_pattern",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
#endif
{ &hf_gsm_a_rr_eutran_pcid_pattern_sense,
{ "PCID_pattern_sense", "gsm_a.rr.pcid_pattern_sense",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rr_pcid_pattern_sense), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_frequency_index,
{ "E-UTRAN_FREQUENCY_INDEX", "gsm_a.rr.eutran_frequency_index",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_psc,
{ "PSC", "gsm_a.rr.psc",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_utran_psc_pattern_length,
{ "PSC_Pattern_length", "gsm_a.rr.psc_pattern_length",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_pcid_psc_pattern_length), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_utran_psc_pattern_sense,
{ "PSC_pattern_sense", "gsm_a.rr.psc_pattern_sense",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_utran_csg_fdd_uarfcn,
{ "CSG FDD UARFCN", "gsm_a.rr.utran_csg_fdd_uarfcn",
FT_UINT16, BASE_DEC, NULL, 0x0000,
NULL, HFILL }
},
{ &hf_gsm_a_rr_utran_csg_tdd_uarfcn,
{ "CSG TDD UARFCN", "gsm_a.rr.utran_csg_tdd_uarfcn",
FT_UINT16, BASE_DEC, NULL, 0x0000,
NULL, HFILL }
},
{ &hf_gsm_a_rr_csg_earfcn,
{ "CSG_EARFCN", "gsm_a.rr.csg_earfcn",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_3g_control_param_desc_meas_ctrl_utran,
{ "PCID_pattern_sense", "gsm_a.rr.meas_ctrl_utran",
FT_BOOLEAN, BASE_NONE, TFS(&measurement_control_utran), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_extended_ra,
{ "Extended_RA", "gsm_a.rr.extended_ra",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_access_tech_type,
{ "Access_Technology_Type", "gsm_a.rr.access_tech_type",
FT_UINT8, BASE_DEC, VALS(gsm_a_access_tech_type_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_tfi_assignment,
{ "TFI_Assignment", "gsm_a.rr.tfi_assignment",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_polling,
{ "Polling", "gsm_a.rr.polling",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_polling_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_usf,
{ "USF", "gsm_a.rr.usf",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_usf_granularity,
{ "USF_granularity", "gsm_a.rr.usf_granularity",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_usf_granularity_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_p0,
{ "P0", "gsm_a.rr.p0",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pr_mode,
{ "pr_mode", "gsm_a.rr.pr_mode",
FT_BOOLEAN, BASE_NONE, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_egprs_mcs,
{ "Egprs_Modulation_and_Coding_Scheme", "gsm_a.rr.egprs_mcs",
FT_UINT8, BASE_DEC, VALS(gsm_a_egprs_mcs_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_tlli_block_channel_coding,
{ "TLLI_Block_Channel_Coding", "gsm_a.rr.tlli_block_cs",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_tlli_block_channel_coding_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_bep_period2,
{ "Bep_Period2", "gsm_a.rr.bep_period2",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_resegment,
{ "Resegment", "gsm_a.rr.resegment",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_resegment_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_egprs_window_size,
{ "Egprs_Windows_Size", "gsm_a.rr.egprs_win_size",
FT_UINT8, BASE_DEC, VALS(gsm_a_egprs_windows_size_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_gamma,
{ "Gamma", "gsm_a.rr.gamma",
FT_UINT8, BASE_DEC, VALS(gsm_a_rr_gamma_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_timing_adv_index,
{ "Timing_Advance_Index", "gsm_a.rr.timing_adv_idx",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_tbf_starting_time,
{ "TBF_Starting_Time", "gsm_a.rr.tvf_start_time",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_num_of_radio_block_allocated,
{ "Number_of_Radio_Block_Allocated", "gsm_a.rr.num_of_radio_blk_allocated",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_pfi,
{ "PFI", "gsm_a.rr.pfi",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_mbms_service_id,
{ "MBMS_Service_ID", "gsm_a.rr.mbms_service_id",
FT_UINT32, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ms_id,
{ "MS_ID", "gsm_a.rr.ms_id",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_timing_adv_timeslot_num,
{ "Timing_Advance_Timeslot_Number", "gsm_a.rr.timing_adv_ts",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_gprs_cs,
{ "Channel_Coding_Command", "gsm_a.rr.gprs_cs",
FT_UINT8, BASE_DEC, VALS(gsm_a_gprs_cs_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_rlc_mode,
{ "RLC_Mode", "gsm_a.rr.rlc_mode",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_rlc_mode_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ta_valid,
{ "TA_Valid", "gsm_a.rr.ta_valid",
FT_BOOLEAN, BASE_NONE, TFS(&gsm_a_ta_valid_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_link_quality_meas_mode,
{ "Link_Quality_Measure_Mode", "gsm_a.rr.link_qual_meas_mode",
FT_UINT8, BASE_DEC, VALS(gsm_a_link_quality_meas_mode_vals), 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_emr_bitmap_length,
{ "BITMAP_LENGTH", "gsm_a.rr.emr_bitmap_len",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_mr_n_eutran,
{ "N_E-UTRAN", "gsm_a.rr.eutran_mr_n_eutran",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_mr_freq_idx,
{ "E-UTRAN_FREQUENCY_INDEX", "gsm_a.rr.eutran_mr_freq_idx",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_mr_cell_id,
{ "CELL IDENTITY", "gsm_a.rr.eutran_mr_cell_id",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_eutran_mr_rpt_quantity,
{ "REPORTING_QUANTITY", "gsm_a.rr.eutran_mr_rpt_quantity",
FT_UINT8, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
{ &hf_gsm_a_rr_ma_channel_set,
{ "Channel Set", "gsm_a.rr.ma_channel_set",
FT_UINT8, BASE_HEX, NULL, 0x00,
NULL, HFILL }
},
{ &hf_n_range_orig_arfcn,
{ "ORIG-ARFCN", "gsm_a.rr.orig_arfcn",
FT_UINT16, BASE_DEC, NULL, 0x00,
NULL, HFILL }
},
};
static hf_register_info hf_rr_short_pd[] =
{
{ &hf_gsm_a_rr_short_pd,
{ "Radio Resources Short Protocol Discriminator", "gsm_a.rr.short_pd",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_short_pd_msg_type,
{ "Radio Resources Short PD Message Type", "gsm_a.rr.short_pd_type",
FT_UINT8, BASE_HEX, VALS(gsm_a_rr_short_pd_msg_strings), 0x0,
NULL, HFILL }
},
{ &hf_gsm_a_rr_short_l2_header,
{ "Radio Resources Short L2 Header", "gsm_a.rr.short_l2_header",
FT_UINT8, BASE_HEX, NULL, 0x0,
NULL, HFILL }
}
};
#define NUM_INDIVIDUAL_ELEMS 3
gint *ett[NUM_INDIVIDUAL_ELEMS +
NUM_GSM_DTAP_MSG_RR +
NUM_GSM_RR_ELEM +
NUM_GSM_RR_REST_OCTETS_ELEM +
NUM_GSM_SACCH_MSG_RR];
static ei_register_info ei[] = {
{ &ei_gsm_a_rr_ie_overrun, { "gsm_a.rr.ie_overrun", PI_MALFORMED, PI_ERROR, "IE over-runs stated length", EXPFILL }},
{ &ei_gsm_a_rr_ie_underrun, { "gsm_a.rr.ie_underrun", PI_COMMENTS_GROUP, PI_NOTE, "IE under-runs stated length", EXPFILL }},
};
expert_module_t* expert_a_rr;
ett[0] = &ett_ccch_msg;
ett[1] = &ett_ccch_oct_1;
ett[2] = &ett_sacch_msg;
last_offset = NUM_INDIVIDUAL_ELEMS;
for (i=0; i < NUM_GSM_DTAP_MSG_RR; i++, last_offset++)
{
ett_gsm_dtap_msg_rr[i] = -1;
ett[last_offset] = &ett_gsm_dtap_msg_rr[i];
}
for (i=0; i < NUM_GSM_RR_ELEM; i++, last_offset++)
{
ett_gsm_rr_elem[i] = -1;
ett[last_offset] = &ett_gsm_rr_elem[i];
}
for (i=0; i < NUM_GSM_RR_REST_OCTETS_ELEM; i++, last_offset++)
{
ett_gsm_rr_rest_octets_elem[i] = -1;
ett[last_offset] = &ett_gsm_rr_rest_octets_elem[i];
}
for (i=0; i < NUM_GSM_SACCH_MSG_RR; i++, last_offset++)
{
ett_gsm_sacch_msg_rr[i] = -1;
ett[last_offset] = &ett_gsm_sacch_msg_rr[i];
}
proto_a_rr =
proto_register_protocol("GSM A-I/F Radio Resource Management", "GSM RR", "gsm_a.rr");
proto_register_field_array(proto_a_rr, hf, array_length(hf));
expert_a_rr = expert_register_protocol(proto_a_rr);
expert_register_field_array(expert_a_rr, ei, array_length(ei));
proto_a_ccch =
proto_register_protocol("GSM CCCH", "GSM CCCH", "gsm_a.ccch");
register_dissector("gsm_a_ccch", dissect_ccch, proto_a_ccch);
proto_a_sacch =
proto_register_protocol("GSM SACCH", "GSM SACCH", "gsm_a.sacch");
proto_register_field_array(proto_a_sacch, hf_rr_short_pd, array_length(hf_rr_short_pd));
register_dissector("gsm_a_sacch", dissect_sacch, proto_a_sacch);
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_gsm_a_rr(void)
{
data_handle = find_dissector("data");
rrc_irat_ho_info_handle = find_dissector("rrc.irat.irat_ho_info");
rrc_irat_ho_to_utran_cmd_handle = find_dissector("rrc.irat.ho_to_utran_cmd");
rrlp_dissector = find_dissector("rrlp");
}
