static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
void * T_4 V_4 )
{
T_5 * V_5 , * V_6 ;
T_3 * V_7 , * V_8 ;
T_6 V_9 = 0 ;
T_7 V_10 , V_11 , V_12 ;
T_8 V_13 , V_14 ;
if ( F_2 ( V_1 ) < V_15 )
return 0 ;
F_3 ( V_2 -> V_16 , V_17 , L_1 ) ;
V_5 = F_4 ( V_3 , V_18 , V_1 , 0 , - 1 , V_19 ) ;
V_7 = F_5 ( V_5 , V_20 ) ;
V_6 = F_4 ( V_7 , V_21 , V_1 , V_9 , 1 , V_19 ) ;
V_8 = F_5 ( V_6 , V_22 ) ;
F_4 ( V_8 , V_23 , V_1 , V_9 , 1 , V_19 ) ;
F_4 ( V_8 , V_24 , V_1 , V_9 , 1 , V_19 ) ;
F_4 ( V_8 , V_25 , V_1 , V_9 , 1 , V_19 ) ;
F_4 ( V_8 , V_26 , V_1 , V_9 , 1 , V_19 ) ;
F_4 ( V_8 , V_27 , V_1 , V_9 , 1 , V_19 ) ;
V_10 = F_6 ( V_1 , V_9 ) ;
V_9 += 1 ;
switch( ( V_10 & V_28 ) >> 2 ) {
case 0 :
V_11 = 0 ;
V_13 = 0 ;
break;
case 1 :
V_11 = 1 ;
V_13 = F_6 ( V_1 , V_9 ) ;
break;
case 2 :
V_11 = 4 ;
V_13 = F_7 ( V_1 , V_9 ) ;
break;
case 3 :
V_11 = 8 ;
V_13 = F_8 ( V_1 , V_9 ) ;
break;
default:
V_11 = 8 ;
V_13 = F_8 ( V_1 , V_9 ) ;
break;
}
if ( V_11 ) {
F_4 ( V_7 , V_29 , V_1 , V_9 , V_11 , V_30 ) ;
V_9 += V_11 ;
}
if( V_10 & V_31 ) {
F_4 ( V_7 , V_32 , V_1 , V_9 , 4 , V_33 | V_19 ) ;
V_9 += 4 ;
}
switch( ( V_10 & V_34 ) >> 4 ) {
case 0 :
V_12 = 1 ;
V_14 = F_6 ( V_1 , V_9 ) ;
break;
case 1 :
V_12 = 2 ;
V_14 = F_9 ( V_1 , V_9 ) ;
break;
case 2 :
V_12 = 4 ;
V_14 = F_7 ( V_1 , V_9 ) ;
break;
case 3 :
V_12 = 6 ;
V_14 = F_10 ( V_1 , V_9 ) ;
break;
default:
V_12 = 6 ;
V_14 = F_10 ( V_1 , V_9 ) ;
break;
}
F_4 ( V_7 , V_35 , V_1 , V_9 , V_12 , V_30 ) ;
V_9 += V_12 ;
F_11 ( V_2 -> V_16 , V_36 , L_2 V_37 L_3 V_37 L_4 , V_13 , V_14 ) ;
#if 0
ti_prflags = proto_tree_add_item(quic_tree, hf_quic_prflags, tvb, offset, 1, ENC_NA);
prflags_tree = proto_item_add_subtree(ti_prflags, ett_quic_prflags);
proto_tree_add_item(prflags_tree, hf_quic_prflags_entropy, tvb, offset, 1, ENC_NA);
proto_tree_add_item(prflags_tree, hf_quic_prflags_fecg, tvb, offset, 1, ENC_NA);
proto_tree_add_item(prflags_tree, hf_quic_prflags_fec, tvb, offset, 1, ENC_NA);
proto_tree_add_item(prflags_tree, hf_quic_prflags_rsv, tvb, offset, 1, ENC_NA);
offset +=1;
#endif
F_4 ( V_7 , V_38 , V_1 , V_9 , - 1 , V_19 ) ;
return V_9 ;
}
static int
F_12 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
void * T_4 V_4 )
{
return F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
static int
F_13 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
void * T_4 V_4 )
{
return F_1 ( V_1 , V_2 , V_3 , NULL ) ;
}
void
F_14 ( void )
{
T_9 * V_39 ;
static T_10 V_40 [] = {
{ & V_21 ,
{ L_5 , L_6 ,
V_41 , V_42 , NULL , 0x0 ,
L_7 , V_43 }
} ,
{ & V_23 ,
{ L_8 , L_9 ,
V_44 , 8 , F_15 ( & V_45 ) , V_31 ,
L_10 , V_43 }
} ,
{ & V_24 ,
{ L_11 , L_12 ,
V_44 , 8 , F_15 ( & V_45 ) , V_46 ,
L_13 , V_43 }
} ,
{ & V_25 ,
{ L_14 , L_15 ,
V_41 , V_42 , F_16 ( V_47 ) , V_28 ,
L_16 , V_43 }
} ,
{ & V_26 ,
{ L_17 , L_18 ,
V_41 , V_42 , F_16 ( V_48 ) , V_34 ,
L_19 , V_43 }
} ,
{ & V_27 ,
{ L_20 , L_21 ,
V_41 , V_42 , NULL , V_49 ,
L_22 , V_43 }
} ,
{ & V_29 ,
{ L_23 , L_24 ,
V_50 , V_51 , NULL , 0x0 ,
L_25 , V_43 }
} ,
{ & V_32 ,
{ L_8 , L_26 ,
V_52 , V_53 , NULL , 0x0 ,
L_27 , V_43 }
} ,
{ & V_35 ,
{ L_28 , L_29 ,
V_50 , V_51 , NULL , 0x0 ,
L_30 , V_43 }
} ,
#if 0
{ &hf_quic_prflags,
{ "Private Flags", "quic.prflags",
FT_UINT8, BASE_HEX, NULL, 0x0,
"Specifying per-packet Private flags", HFILL }
},
{ &hf_quic_prflags_entropy,
{ "Entropy", "quic.prflags.entropy",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PRFLAGS_ENTROPY,
"For data packets, signifies that this packet contains the 1 bit of entropy, for fec packets, contains the xor of the entropy of protected packets", HFILL }
},
{ &hf_quic_prflags_fecg,
{ "FEC Group", "quic.prflags.fecg",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PRFLAGS_FECG,
"Indicates whether the fec byte is present.", HFILL }
},
{ &hf_quic_prflags_fec,
{ "FEC", "quic.prflags.fec",
FT_BOOLEAN, 8, TFS(&tfs_yes_no), PRFLAGS_FEC,
"Signifies that this packet represents an FEC packet", HFILL }
},
{ &hf_quic_prflags_rsv,
{ "Reserved", "quic.prflags.rsv",
FT_UINT8, BASE_HEX, NULL, PRFLAGS_RSV,
"Must be Zero", HFILL }
},
#endif
{ & V_38 ,
{ L_31 , L_32 ,
V_54 , V_53 , NULL , 0x0 ,
L_33 , V_43 }
} ,
} ;
static T_11 * V_55 [] = {
& V_20 ,
& V_22 ,
& V_56
} ;
V_18 = F_17 ( L_34 ,
L_1 , L_35 ) ;
F_18 ( V_18 , V_40 , F_19 ( V_40 ) ) ;
F_20 ( V_55 , F_19 ( V_55 ) ) ;
V_39 = F_21 ( V_18 , V_57 ) ;
F_22 ( V_39 , L_36 , L_37 ,
L_38 ,
10 , & V_58 ) ;
F_22 ( V_39 , L_39 , L_40 ,
L_41 ,
10 , & V_59 ) ;
}
void
V_57 ( void )
{
static T_12 V_60 = FALSE ;
static T_13 V_61 ;
static T_13 V_62 ;
static int V_63 ;
static int V_64 ;
if ( ! V_60 ) {
V_61 = F_23 ( F_12 ,
V_18 ) ;
V_62 = F_23 ( F_13 ,
V_18 ) ;
V_60 = TRUE ;
} else {
F_24 ( L_42 , V_63 , V_61 ) ;
F_24 ( L_42 , V_64 , V_62 ) ;
}
V_63 = V_58 ;
V_64 = V_59 ;
F_25 ( L_42 , V_63 , V_61 ) ;
F_25 ( L_42 , V_64 , V_62 ) ;
}
