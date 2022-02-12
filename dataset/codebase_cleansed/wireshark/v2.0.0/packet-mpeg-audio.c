static int
dissect_mpeg_audio_BIT_STRING_SIZE_11(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_bit_string(tvb, offset, actx, tree, hf_index,
11, 11, FALSE, NULL, NULL);
return offset;
}
static int
dissect_mpeg_audio_T_version(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_mpeg_audio_T_layer(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_mpeg_audio_T_protection(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
2, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_mpeg_audio_INTEGER_0_15(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 15U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_audio_INTEGER_0_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 3U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_audio_BOOLEAN(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_boolean(tvb, offset, actx, tree, hf_index, NULL);
return offset;
}
static int
dissect_mpeg_audio_T_channel_mode(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_mpeg_audio_T_emphasis(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_enumerated(tvb, offset, actx, tree, hf_index,
4, NULL, FALSE, 0, NULL);
return offset;
}
static int
dissect_mpeg_audio_Audio(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_mpeg_audio_Audio, Audio_sequence);
return offset;
}
static int
dissect_mpeg_audio_OCTET_STRING_SIZE_3(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
3, 3, FALSE, NULL);
return offset;
}
static int
dissect_mpeg_audio_OCTET_STRING_SIZE_30(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
30, 30, FALSE, NULL);
return offset;
}
static int
dissect_mpeg_audio_OCTET_STRING_SIZE_4(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
4, 4, FALSE, NULL);
return offset;
}
static int
dissect_mpeg_audio_OCTET_STRING_SIZE_28(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_octet_string(tvb, offset, actx, tree, hf_index,
28, 28, FALSE, NULL);
return offset;
}
static int
dissect_mpeg_audio_INTEGER_0_255(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_audio_T_genre(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_constrained_integer(tvb, offset, actx, tree, hf_index,
0U, 255U, NULL, FALSE);
return offset;
}
static int
dissect_mpeg_audio_ID3v1(tvbuff_t *tvb _U_, int offset _U_, asn1_ctx_t *actx _U_, proto_tree *tree _U_, int hf_index _U_) {
offset = dissect_per_sequence(tvb, offset, actx, tree, hf_index,
ett_mpeg_audio_ID3v1, ID3v1_sequence);
return offset;
}
static gboolean
dissect_mpeg_audio_frame(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
guint32 h;
struct mpa mpa;
int data_size = 0;
asn1_ctx_t asn1_ctx;
int offset = 0;
static const char *version_names[] = { "1", "2", "2.5" };
if (!tvb_bytes_exist(tvb, 0, 4))
return FALSE;
h = tvb_get_ntohl(tvb, 0);
MPA_UNMARSHAL(&mpa, h);
if (!MPA_SYNC_VALID(&mpa))
return FALSE;
if (!MPA_VERSION_VALID(&mpa))
return FALSE;
if (!MPA_LAYER_VALID(&mpa))
return FALSE;
col_add_fstr(pinfo->cinfo, COL_PROTOCOL,
"MPEG-%s", version_names[mpa_version(&mpa)]);
col_add_fstr(pinfo->cinfo, COL_INFO,
"Audio Layer %d", mpa_layer(&mpa) + 1);
if (MPA_BITRATE_VALID(&mpa) && MPA_FREQUENCY_VALID(&mpa)) {
data_size = (int)(MPA_DATA_BYTES(&mpa) - sizeof mpa);
SET_ADDRESS(&pinfo->src, AT_NONE, 0, NULL);
col_add_fstr(pinfo->cinfo, COL_DEF_SRC,
"%d kb/s", mpa_bitrate(&mpa) / 1000);
SET_ADDRESS(&pinfo->dst, AT_NONE, 0, NULL);
col_add_fstr(pinfo->cinfo, COL_DEF_DST,
"%g kHz", mpa_frequency(&mpa) / (float)1000);
}
if (tree == NULL)
return TRUE;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
offset = dissect_mpeg_audio_Audio(tvb, offset, &asn1_ctx,
tree, proto_mpeg_audio);
if (data_size > 0) {
unsigned int padding;
proto_tree_add_item(tree, hf_mpeg_audio_data, tvb,
offset / 8, data_size, ENC_NA);
offset += data_size * 8;
padding = mpa_padding(&mpa);
if (padding > 0) {
proto_tree_add_item(tree, hf_mpeg_audio_padbytes, tvb,
offset / 8, padding, ENC_NA);
}
}
return TRUE;
}
static void
dissect_id3v1(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
asn1_ctx_t asn1_ctx;
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ID3v1");
col_clear(pinfo->cinfo, COL_INFO);
if (tree == NULL)
return;
asn1_ctx_init(&asn1_ctx, ASN1_ENC_PER, TRUE, pinfo);
dissect_mpeg_audio_ID3v1(tvb, 0, &asn1_ctx,
tree, hf_id3v1);
}
static void
dissect_id3v2(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree)
{
col_set_str(pinfo->cinfo, COL_PROTOCOL, "ID3v2");
col_clear(pinfo->cinfo, COL_INFO);
proto_tree_add_item(tree, hf_id3v2, tvb,
0, -1, ENC_NA);
}
static gboolean
dissect_mpeg_audio(tvbuff_t *tvb, packet_info *pinfo, proto_tree *tree, void *data _U_)
{
int magic;
if (!tvb_bytes_exist(tvb, 0, 3))
return FALSE;
magic = tvb_get_ntoh24(tvb, 0);
switch (magic) {
case 0x544147:
dissect_id3v1(tvb, pinfo, tree);
return TRUE;
case 0x494433:
dissect_id3v2(tvb, pinfo, tree);
return TRUE;
default:
return dissect_mpeg_audio_frame(tvb, pinfo, tree);
}
}
void
proto_register_mpeg_audio(void)
{
static hf_register_info hf[] = {
#line 1 "../../asn1/mpeg-audio/packet-mpeg-audio-hfarr.c"
{ &hf_mpeg_audio_sync,
{ "sync", "mpeg-audio.sync",
FT_BYTES, BASE_NONE, NULL, 0,
"BIT_STRING_SIZE_11", HFILL }},
{ &hf_mpeg_audio_version,
{ "version", "mpeg-audio.version",
FT_UINT32, BASE_DEC, VALS(mpeg_audio_T_version_vals), 0,
NULL, HFILL }},
{ &hf_mpeg_audio_layer,
{ "layer", "mpeg-audio.layer",
FT_UINT32, BASE_DEC, VALS(mpeg_audio_T_layer_vals), 0,
NULL, HFILL }},
{ &hf_mpeg_audio_protection,
{ "protection", "mpeg-audio.protection",
FT_UINT32, BASE_DEC, VALS(mpeg_audio_T_protection_vals), 0,
NULL, HFILL }},
{ &hf_mpeg_audio_bitrate,
{ "bitrate", "mpeg-audio.bitrate",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_15", HFILL }},
{ &hf_mpeg_audio_frequency,
{ "frequency", "mpeg-audio.frequency",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_mpeg_audio_padding,
{ "padding", "mpeg-audio.padding",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_audio_private,
{ "private", "mpeg-audio.private",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_audio_channel_mode,
{ "channel-mode", "mpeg-audio.channel_mode",
FT_UINT32, BASE_DEC, VALS(mpeg_audio_T_channel_mode_vals), 0,
NULL, HFILL }},
{ &hf_mpeg_audio_mode_extension,
{ "mode-extension", "mpeg-audio.mode_extension",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_3", HFILL }},
{ &hf_mpeg_audio_copyright,
{ "copyright", "mpeg-audio.copyright",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_audio_original,
{ "original", "mpeg-audio.original",
FT_BOOLEAN, BASE_NONE, NULL, 0,
"BOOLEAN", HFILL }},
{ &hf_mpeg_audio_emphasis,
{ "emphasis", "mpeg-audio.emphasis",
FT_UINT32, BASE_DEC, VALS(mpeg_audio_T_emphasis_vals), 0,
NULL, HFILL }},
{ &hf_mpeg_audio_tag,
{ "tag", "mpeg-audio.tag",
FT_STRING, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_3", HFILL }},
{ &hf_mpeg_audio_title,
{ "title", "mpeg-audio.title",
FT_STRING, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_30", HFILL }},
{ &hf_mpeg_audio_artist,
{ "artist", "mpeg-audio.artist",
FT_STRING, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_30", HFILL }},
{ &hf_mpeg_audio_album,
{ "album", "mpeg-audio.album",
FT_STRING, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_30", HFILL }},
{ &hf_mpeg_audio_year,
{ "year", "mpeg-audio.year",
FT_STRING, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_4", HFILL }},
{ &hf_mpeg_audio_comment,
{ "comment", "mpeg-audio.comment",
FT_STRING, BASE_NONE, NULL, 0,
"OCTET_STRING_SIZE_28", HFILL }},
{ &hf_mpeg_audio_must_be_zero,
{ "must-be-zero", "mpeg-audio.must_be_zero",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_mpeg_audio_track,
{ "track", "mpeg-audio.track",
FT_UINT32, BASE_DEC, NULL, 0,
"INTEGER_0_255", HFILL }},
{ &hf_mpeg_audio_genre,
{ "genre", "mpeg-audio.genre",
FT_UINT32, BASE_DEC, VALS(mpeg_audio_T_genre_vals), 0,
NULL, HFILL }},
#line 151 "../../asn1/mpeg-audio/packet-mpeg-audio-template.c"
{ &hf_mpeg_audio_data,
{ "Data", "mpeg-audio.data",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_mpeg_audio_padbytes,
{ "Padding", "mpeg-audio.padbytes",
FT_BYTES, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_id3v1,
{ "ID3v1", "mpeg-audio.id3v1",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
{ &hf_id3v2,
{ "ID3v2", "mpeg-audio.id3v2",
FT_NONE, BASE_NONE, NULL, 0, NULL, HFILL }},
};
static gint *ett[] = {
#line 1 "../../asn1/mpeg-audio/packet-mpeg-audio-ettarr.c"
&ett_mpeg_audio_Audio,
&ett_mpeg_audio_ID3v1,
#line 168 "../../asn1/mpeg-audio/packet-mpeg-audio-template.c"
};
proto_mpeg_audio = proto_register_protocol(
"Moving Picture Experts Group Audio", "MPEG Audio", "mpeg-audio");
proto_register_field_array(proto_mpeg_audio, hf, array_length(hf));
proto_register_subtree_array(ett, array_length(ett));
}
void
proto_reg_handoff_mpeg_audio(void)
{
heur_dissector_add("mpeg", dissect_mpeg_audio, "MPEG Audio", "mpeg_audio", proto_mpeg_audio, HEURISTIC_ENABLE);
}
