static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_3 * V_4 , * V_5 ;
T_4 * V_6 , * V_7 ;
int V_8 ;
T_5 V_9 ;
T_6 V_10 ;
#if 0
proto_tree *checksum_tree;
proto_item *checksum_ti;
guint16 checksum, checksum_calculated;
guint checksum_offset;
#endif
T_6 V_11 , V_12 , V_13 , V_14 , V_15 ;
T_7 V_16 = 0 ;
#if 0
guint length, reported_length;
#endif
T_1 * V_17 ;
const char * V_18 = L_1 ;
const char * V_19 = L_1 ;
F_2 ( V_2 -> V_20 , V_21 , L_2 ) ;
F_3 ( V_2 -> V_20 , V_22 ) ;
V_11 = F_4 ( V_1 , 0 ) ;
V_12 = V_11 & V_23 ;
V_14 = ( V_11 & V_24 ) >> V_25 ;
V_13 = ( V_11 & V_26 ) >> V_27 ;
V_15 = ( V_13 << 7 ) + V_14 ;
V_9 = 2 ;
V_8 = V_2 -> V_28 ;
if ( V_2 -> V_28 == V_29 ) {
V_16 = V_12 ? FALSE : TRUE ;
V_18 = L_3 ;
V_19 = L_4 ;
}
else if ( V_2 -> V_28 == V_30 ) {
V_16 = V_12 ? TRUE : FALSE ;
V_18 = L_4 ;
V_19 = L_3 ;
}
F_2 ( V_2 -> V_20 , V_31 , V_18 ) ;
F_2 ( V_2 -> V_20 , V_32 , V_19 ) ;
if ( V_3 ) {
T_4 * V_33 ;
V_6 = F_5 ( V_3 , V_34 , V_1 , 0 , - 1 ,
V_35 ) ;
V_4 = F_6 ( V_6 , V_36 ) ;
if ( V_8 != V_37 ) {
V_33 = F_7 ( V_4 , V_38 ,
V_1 , 0 , 0 , V_2 -> V_28 ) ;
F_8 ( V_33 ) ;
}
V_7 = F_7 ( V_4 , V_39 , V_1 ,
0 , 2 , V_15 ) ;
V_5 = F_6 ( V_7 , V_40 ) ;
F_7 ( V_5 , V_41 , V_1 , 0 , 1 , V_11 ) ;
F_7 ( V_5 , V_42 , V_1 , 0 , 1 , V_11 ) ;
F_7 ( V_5 , V_43 , V_1 , 0 , 1 , V_11 ) ;
F_7 ( V_5 , V_44 , V_1 , 1 , 1 , V_11 ) ;
F_7 ( V_5 , V_45 , V_1 , 1 , 1 , V_11 ) ;
}
else {
V_6 = NULL ;
V_4 = NULL ;
}
V_10 = F_9 ( V_1 , 2 , V_2 , V_4 , V_46 ,
V_47 , & V_48 , & V_49 , NULL , NULL ,
V_16 , TRUE , FALSE ) ;
V_9 += F_10 ( V_10 , TRUE ) ;
if ( V_3 )
F_11 ( V_6 , V_9 ) ;
#if 0
length = tvb_length(tvb);
reported_length = tvb_reported_length(tvb);
if (reported_length < v5dl_header_len + 2)
THROW(ReportedBoundsError);
if (length == reported_length) {
checksum_offset = reported_length - 2;
checksum = tvb_get_ntohs(tvb, checksum_offset);
checksum_calculated = crc16_ccitt_tvb(tvb, checksum_offset);
checksum_calculated = g_htons(checksum_calculated);
if (checksum == checksum_calculated) {
checksum_ti = proto_tree_add_uint_format(v5dl_tree, hf_v5dl_checksum, tvb, checksum_offset,
2, 0,
"Checksum: 0x%04x [correct]",
checksum);
checksum_tree = proto_item_add_subtree(checksum_ti, ett_v5dl_checksum);
proto_tree_add_boolean(checksum_tree, hf_v5dl_checksum_good, tvb, checksum_offset, 2, TRUE);
proto_tree_add_boolean(checksum_tree, hf_v5dl_checksum_bad, tvb, checksum_offset, 2, FALSE);
} else {
checksum_ti = proto_tree_add_uint_format(v5dl_tree, hf_v5dl_checksum, tvb, checksum_offset,
2, 0,
"Checksum: 0x%04x [incorrect, should be 0x%04x]",
checksum, checksum_calculated);
checksum_tree = proto_item_add_subtree(checksum_ti, ett_v5dl_checksum);
proto_tree_add_boolean(checksum_tree, hf_v5dl_checksum_good, tvb, checksum_offset, 2, FALSE);
proto_tree_add_boolean(checksum_tree, hf_v5dl_checksum_bad, tvb, checksum_offset, 2, TRUE);
}
next_tvb = tvb_new_subset(tvb, v5dl_header_len,
tvb_length_remaining(tvb, v5dl_header_len) - 2,
tvb_reported_length_remaining(tvb, v5dl_header_len) - 2);
} else {
if (length == reported_length - 1) {
next_tvb = tvb_new_subset(tvb, v5dl_header_len,
tvb_length_remaining(tvb, v5dl_header_len) - 1,
tvb_reported_length_remaining(tvb, v5dl_header_len) - 2);
} else {
next_tvb = tvb_new_subset(tvb, v5dl_header_len,
tvb_length_remaining(tvb, v5dl_header_len),
tvb_reported_length_remaining(tvb, v5dl_header_len) - 2);
}
}
#else
V_17 = F_12 ( V_1 , V_9 ) ;
#endif
if ( F_13 ( V_10 ) ) {
F_14 ( V_50 , V_17 , V_2 , V_3 ) ;
}
}
void
F_15 ( void )
{
static T_8 V_51 [] = {
{ & V_38 ,
{ L_5 , L_6 , V_52 , V_53 , F_16 ( V_54 ) , 0x0 ,
NULL , V_55 } } ,
#if 0
{ &hf_v5dl_address,
{ "Address Field", "v5dl.address", FT_UINT16, BASE_HEX, NULL, 0x0,
"Address", HFILL }},
#endif
{ & V_39 ,
{ L_7 , L_8 , V_56 , V_53 , F_16 ( V_57 ) , 0x0 ,
L_9 , V_55 } } ,
{ & V_41 ,
{ L_10 , L_11 , V_56 , V_53 , NULL , V_26 ,
L_12 , V_55 } } ,
{ & V_42 ,
{ L_13 , L_14 , V_56 , V_53 , NULL , V_23 ,
L_15 , V_55 } } ,
{ & V_43 ,
{ L_16 , L_17 , V_56 , V_53 , NULL , V_58 ,
L_18 , V_55 } } ,
{ & V_44 ,
{ L_19 , L_20 , V_56 , V_53 , NULL , V_24 ,
L_21 , V_55 } } ,
{ & V_45 ,
{ L_22 , L_23 , V_56 , V_53 , NULL , V_59 ,
L_24 , V_55 } } ,
{ & V_46 ,
{ L_25 , L_26 , V_56 , V_60 , NULL , 0x0 ,
NULL , V_55 } } ,
{ & V_61 ,
{ L_27 , L_28 , V_56 , V_53 ,
NULL , V_62 , NULL , V_55 } } ,
{ & V_63 ,
{ L_29 , L_30 , V_56 , V_53 ,
NULL , V_64 , NULL , V_55 } } ,
{ & V_65 ,
{ L_31 , L_32 , V_66 , 8 ,
F_17 ( & V_67 ) , V_68 , NULL , V_55 } } ,
{ & V_69 ,
{ L_31 , L_32 , V_66 , 16 ,
F_17 ( & V_67 ) , V_70 , NULL , V_55 } } ,
{ & V_71 ,
{ L_33 , L_34 , V_66 , 8 ,
F_17 ( & V_67 ) , V_68 , NULL , V_55 } } ,
{ & V_72 ,
{ L_33 , L_34 , V_66 , 16 ,
F_17 ( & V_67 ) , V_70 , NULL , V_55 } } ,
{ & V_73 ,
{ L_35 , L_36 , V_56 , V_60 ,
F_16 ( V_74 ) , V_75 , NULL , V_55 } } ,
{ & V_76 ,
{ L_37 , L_38 , V_52 , V_60 ,
F_16 ( V_77 ) , V_78 , NULL , V_55 } } ,
{ & V_79 ,
{ L_39 , L_40 , V_52 , V_60 ,
F_16 ( V_80 ) , V_78 , NULL , V_55 } } ,
{ & V_81 ,
{ L_41 , L_42 , V_56 , V_60 ,
F_16 ( V_82 ) , V_83 , NULL , V_55 } } ,
{ & V_84 ,
{ L_41 , L_42 , V_52 , V_60 ,
F_16 ( V_82 ) , V_85 , NULL , V_55 } } ,
{ & V_86 ,
{ L_41 , L_42 , V_56 , V_60 ,
F_16 ( V_82 ) , V_85 , NULL , V_55 } } ,
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
static T_9 * V_87 [] = {
& V_36 ,
& V_40 ,
& V_47 ,
} ;
V_34 = F_18 ( L_43 ,
L_2 , L_44 ) ;
F_19 ( V_34 , V_51 , F_20 ( V_51 ) ) ;
F_21 ( V_87 , F_20 ( V_87 ) ) ;
F_22 ( L_44 , F_1 , V_34 ) ;
}
void
F_23 ( void )
{
V_50 = F_24 ( L_45 ) ;
}
