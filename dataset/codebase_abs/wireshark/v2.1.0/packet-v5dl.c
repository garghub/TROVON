static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_3 * V_5 , * V_6 ;
T_5 * V_7 , * V_8 ;
int V_9 ;
T_6 V_10 ;
T_7 V_11 ;
#if 0
proto_tree *checksum_tree;
proto_item *checksum_ti;
guint16 checksum, checksum_calculated;
guint checksum_offset;
#endif
T_7 V_12 , V_13 , V_14 , V_15 , V_16 ;
T_8 V_17 = 0 ;
#if 0
guint length, reported_length;
#endif
T_1 * V_18 ;
const char * V_19 = L_1 ;
const char * V_20 = L_1 ;
F_2 ( V_2 -> V_21 , V_22 , L_2 ) ;
F_3 ( V_2 -> V_21 , V_23 ) ;
V_12 = F_4 ( V_1 , 0 ) ;
V_13 = V_12 & V_24 ;
V_15 = ( V_12 & V_25 ) >> V_26 ;
V_14 = ( V_12 & V_27 ) >> V_28 ;
V_16 = ( V_14 << 7 ) + V_15 ;
V_10 = 2 ;
V_9 = V_2 -> V_29 ;
if ( V_2 -> V_29 == V_30 ) {
V_17 = V_13 ? FALSE : TRUE ;
V_19 = L_3 ;
V_20 = L_4 ;
}
else if ( V_2 -> V_29 == V_31 ) {
V_17 = V_13 ? TRUE : FALSE ;
V_19 = L_4 ;
V_20 = L_3 ;
}
F_2 ( V_2 -> V_21 , V_32 , V_19 ) ;
F_2 ( V_2 -> V_21 , V_33 , V_20 ) ;
if ( V_3 ) {
T_5 * V_34 ;
V_7 = F_5 ( V_3 , V_35 , V_1 , 0 , - 1 ,
V_36 ) ;
V_5 = F_6 ( V_7 , V_37 ) ;
if ( V_9 != V_38 ) {
V_34 = F_7 ( V_5 , V_39 ,
V_1 , 0 , 0 , V_2 -> V_29 ) ;
F_8 ( V_34 ) ;
}
V_8 = F_7 ( V_5 , V_40 , V_1 ,
0 , 2 , V_16 ) ;
V_6 = F_6 ( V_8 , V_41 ) ;
F_7 ( V_6 , V_42 , V_1 , 0 , 1 , V_12 ) ;
F_7 ( V_6 , V_43 , V_1 , 0 , 1 , V_12 ) ;
F_7 ( V_6 , V_44 , V_1 , 0 , 1 , V_12 ) ;
F_7 ( V_6 , V_45 , V_1 , 1 , 1 , V_12 ) ;
F_7 ( V_6 , V_46 , V_1 , 1 , 1 , V_12 ) ;
}
else {
V_7 = NULL ;
V_5 = NULL ;
}
V_11 = F_9 ( V_1 , 2 , V_2 , V_5 , V_47 ,
V_48 , & V_49 , & V_50 , NULL , NULL ,
V_17 , TRUE , FALSE ) ;
V_10 += F_10 ( V_11 , TRUE ) ;
if ( V_3 )
F_11 ( V_7 , V_10 ) ;
#if 0
length = tvb_captured_length(tvb);
reported_length = tvb_reported_length(tvb);
if (reported_length < v5dl_header_len + 2)
return;
if (length == reported_length) {
checksum_offset = reported_length - 2;
checksum = tvb_get_ntohs(tvb, checksum_offset);
checksum_calculated = crc16_ccitt_tvb(tvb, checksum_offset);
checksum_calculated = g_htons(checksum_calculated);
if (checksum == checksum_calculated) {
checksum_ti = proto_tree_add_uint_format_value(v5dl_tree, hf_v5dl_checksum, tvb, checksum_offset,
2, 0,
"0x%04x [correct]",
checksum);
checksum_tree = proto_item_add_subtree(checksum_ti, ett_v5dl_checksum);
proto_tree_add_boolean(checksum_tree, hf_v5dl_checksum_good, tvb, checksum_offset, 2, TRUE);
proto_tree_add_boolean(checksum_tree, hf_v5dl_checksum_bad, tvb, checksum_offset, 2, FALSE);
} else {
checksum_ti = proto_tree_add_uint_format_value(v5dl_tree, hf_v5dl_checksum, tvb, checksum_offset,
2, 0,
"0x%04x [incorrect, should be 0x%04x]",
checksum, checksum_calculated);
checksum_tree = proto_item_add_subtree(checksum_ti, ett_v5dl_checksum);
proto_tree_add_boolean(checksum_tree, hf_v5dl_checksum_good, tvb, checksum_offset, 2, FALSE);
proto_tree_add_boolean(checksum_tree, hf_v5dl_checksum_bad, tvb, checksum_offset, 2, TRUE);
}
next_tvb = tvb_new_subset(tvb, v5dl_header_len,
tvb_captured_length_remaining(tvb, v5dl_header_len) - 2,
tvb_reported_length_remaining(tvb, v5dl_header_len) - 2);
} else {
if (length == reported_length - 1) {
next_tvb = tvb_new_subset(tvb, v5dl_header_len,
tvb_captured_length_remaining(tvb, v5dl_header_len) - 1,
tvb_reported_length_remaining(tvb, v5dl_header_len) - 2);
} else {
next_tvb = tvb_new_subset(tvb, v5dl_header_len,
tvb_captured_length_remaining(tvb, v5dl_header_len),
tvb_reported_length_remaining(tvb, v5dl_header_len) - 2);
}
}
#else
V_18 = F_12 ( V_1 , V_10 ) ;
#endif
if ( F_13 ( V_11 ) ) {
F_14 ( V_51 , V_18 , V_2 , V_3 ) ;
}
return F_15 ( V_1 ) ;
}
void
F_16 ( void )
{
static T_9 V_52 [] = {
{ & V_39 ,
{ L_5 , L_6 , V_53 , V_54 , F_17 ( V_55 ) , 0x0 ,
NULL , V_56 } } ,
#if 0
{ &hf_v5dl_address,
{ "Address Field", "v5dl.address", FT_UINT16, BASE_HEX, NULL, 0x0,
"Address", HFILL }},
#endif
{ & V_40 ,
{ L_7 , L_8 , V_57 , V_54 , F_17 ( V_58 ) , 0x0 ,
L_9 , V_56 } } ,
{ & V_42 ,
{ L_10 , L_11 , V_57 , V_54 , NULL , V_27 ,
L_12 , V_56 } } ,
{ & V_43 ,
{ L_13 , L_14 , V_57 , V_54 , NULL , V_24 ,
L_15 , V_56 } } ,
{ & V_44 ,
{ L_16 , L_17 , V_57 , V_54 , NULL , V_59 ,
L_18 , V_56 } } ,
{ & V_45 ,
{ L_19 , L_20 , V_57 , V_54 , NULL , V_25 ,
L_21 , V_56 } } ,
{ & V_46 ,
{ L_22 , L_23 , V_57 , V_54 , NULL , V_60 ,
L_24 , V_56 } } ,
{ & V_47 ,
{ L_25 , L_26 , V_57 , V_61 , NULL , 0x0 ,
NULL , V_56 } } ,
{ & V_62 ,
{ L_27 , L_28 , V_57 , V_54 ,
NULL , V_63 , NULL , V_56 } } ,
{ & V_64 ,
{ L_29 , L_30 , V_57 , V_54 ,
NULL , V_65 , NULL , V_56 } } ,
{ & V_66 ,
{ L_31 , L_32 , V_67 , 8 ,
F_18 ( & V_68 ) , V_69 , NULL , V_56 } } ,
{ & V_70 ,
{ L_31 , L_32 , V_67 , 16 ,
F_18 ( & V_68 ) , V_71 , NULL , V_56 } } ,
{ & V_72 ,
{ L_33 , L_34 , V_67 , 8 ,
F_18 ( & V_68 ) , V_69 , NULL , V_56 } } ,
{ & V_73 ,
{ L_33 , L_34 , V_67 , 16 ,
F_18 ( & V_68 ) , V_71 , NULL , V_56 } } ,
{ & V_74 ,
{ L_35 , L_36 , V_57 , V_61 ,
F_17 ( V_75 ) , V_76 , NULL , V_56 } } ,
{ & V_77 ,
{ L_37 , L_38 , V_53 , V_61 ,
F_17 ( V_78 ) , V_79 , NULL , V_56 } } ,
{ & V_80 ,
{ L_39 , L_40 , V_53 , V_61 ,
F_17 ( V_81 ) , V_79 , NULL , V_56 } } ,
{ & V_82 ,
{ L_41 , L_42 , V_57 , V_61 ,
F_17 ( V_83 ) , V_84 , NULL , V_56 } } ,
{ & V_85 ,
{ L_41 , L_42 , V_53 , V_61 ,
F_17 ( V_83 ) , V_86 , NULL , V_56 } } ,
{ & V_87 ,
{ L_41 , L_42 , V_57 , V_61 ,
F_17 ( V_83 ) , V_86 , NULL , V_56 } } ,
#if 0
{ &hf_v5dl_checksum,
{ "Checksum", "v5dl.checksum", FT_UINT16, BASE_HEX,
NULL, 0x0, "Details at: http://www.wireshark.org/docs/wsug_html_chunked/ChAdvChecksums.html", HFILL }},
{ &hf_v5dl_checksum_good,
{ "Good Checksum", "v5dl.checksum_good", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "True: checksum matches packet content; False: doesn't match content or not checked", HFILL }},
{ &hf_v5dl_checksum_bad,
{ "Bad Checksum", "v5dl.checksum_bad", FT_BOOLEAN, BASE_NONE,
NULL, 0x0, "True: checksum doesn't match packet content; False: matches content or not checked", HFILL }}
#endif
} ;
static T_10 * V_88 [] = {
& V_37 ,
& V_41 ,
& V_48 ,
} ;
V_35 = F_19 ( L_43 ,
L_2 , L_44 ) ;
F_20 ( V_35 , V_52 , F_21 ( V_52 ) ) ;
F_22 ( V_88 , F_21 ( V_88 ) ) ;
F_23 ( L_44 , F_1 , V_35 ) ;
}
void
F_24 ( void )
{
V_51 = F_25 ( L_45 , V_35 ) ;
}
