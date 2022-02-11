static T_1
F_1 ( T_2 * T_3 V_1 , T_4 * V_2 , int V_3 )
{
T_5 type ;
T_6 V_4 ;
if ( F_2 ( V_2 , V_3 ) == 19 &&
F_3 ( V_2 , V_3 + 1 , L_1 , 19 ) == 0 ) {
return 1 +
19 +
8 +
20 +
20 ;
} else {
V_4 = F_4 ( V_2 , V_3 ) ;
if( V_4 == 0 ) {
return V_5 ;
}
if( F_5 ( V_2 , V_3 + V_5 ) ) {
type = F_2 ( V_2 , V_3 + V_5 ) ;
if( ( type <= V_6 || type == V_7 ) && V_4 < 0x1000000 ) {
return V_5 + V_4 ;
} else {
return F_6 ( V_2 , V_3 ) ;
}
} else {
return F_6 ( V_2 , V_3 ) ;
}
}
}
static void
F_7 ( T_4 * V_2 , T_2 * T_3 , T_7 * V_8 )
{
int V_3 = 0 ;
int V_9 ;
int V_10 = 0 ;
T_7 * V_11 ;
T_8 type = 0 ;
T_6 V_12 = 0 ;
T_5 V_13 = 0 ;
T_6 V_4 ;
const char * V_14 = NULL ;
T_9 * V_15 ;
T_6 V_16 , V_17 , V_18 ;
T_6 V_19 ;
T_4 * V_20 ;
if ( F_8 ( V_2 , V_3 + V_5 , 1 ) ) {
V_4 = F_4 ( V_2 , V_3 ) ;
type = F_2 ( V_2 , V_3 + V_5 ) ;
if ( type == V_21 && V_4 > 4 ) {
if ( ! F_8 ( V_2 , V_3 + V_5 , 4 ) )
return;
V_12 = F_4 ( V_2 , V_3 + V_5 ) ;
if ( 4 + V_12 + 1 <= V_4 ) {
if ( ! F_8 ( V_2 , V_3 + V_5 + 4 , V_12 + 1 ) )
return;
for ( V_9 = 0 ; V_22 [ V_9 ] . V_23 ; V_9 ++ ) {
if ( strlen ( V_22 [ V_9 ] . V_23 ) == V_12 &&
F_3 ( V_2 , V_3 + V_5 + 4 ,
V_22 [ V_9 ] . V_23 , ( int ) strlen ( V_22 [ V_9 ] . V_23 ) ) == 0 ) {
V_13 = F_2 ( V_2 , V_3 + V_5 + 4 + V_12 ) ;
if ( V_13 == 0 || V_13 == 1 || V_13 == 2 ) {
type = V_22 [ V_9 ] . V_24 ;
V_10 = 1 ;
}
break;
}
}
}
}
V_14 = F_9 ( type , V_25 ) ;
#if 0
if (msgtype == NULL && isamp) {
msgtype = try_val_to_str(type, azureus_messages);
}
#endif
if ( V_14 == NULL ) {
F_10 ( V_8 , V_2 , V_3 , - 1 , L_2 ) ;
F_11 ( T_3 -> V_26 , V_27 , L_2 ) ;
return;
}
} else {
return;
}
if ( V_10 ) {
V_15 = F_12 ( V_8 , V_28 , V_2 , V_3 , V_4 + V_5 , V_29 ) ;
} else {
V_15 = F_12 ( V_8 , V_30 , V_2 , V_3 , V_4 + V_5 , V_29 ) ;
}
V_11 = F_13 ( V_15 , V_31 ) ;
if ( V_4 == 0 ) {
F_12 ( V_11 , V_32 , V_2 , V_3 , V_5 , V_33 ) ;
F_11 ( T_3 -> V_26 , V_27 , L_3 ) ;
return;
}
F_12 ( V_11 , V_32 , V_2 , V_3 , V_5 , V_33 ) ;
V_3 += V_5 ;
if ( V_10 ) {
F_12 ( V_11 , V_34 , V_2 , V_3 , 4 , V_33 ) ;
F_12 ( V_11 , V_35 , V_2 , V_3 + 4 , V_12 , V_36 | V_29 ) ;
F_14 ( V_15 , L_4 , V_4 , V_14 ) ;
F_12 ( V_11 , V_37 , V_2 , V_3 + 4 + V_12 , 1 , V_33 ) ;
V_3 += 4 + V_12 + 1 ;
V_4 -= 4 + V_12 + 1 ;
} else {
F_12 ( V_11 , V_38 , V_2 , V_3 , 1 , V_33 ) ;
F_14 ( V_15 , L_5 , V_4 , V_14 ) ;
V_3 += 1 ;
V_4 -= 1 ;
}
F_11 ( T_3 -> V_26 , V_27 , V_14 ) ;
switch ( type ) {
case V_21 :
case V_39 :
case V_40 :
case V_41 :
break;
case V_42 :
case V_43 :
V_16 = F_4 ( V_2 , V_3 ) ;
F_15 ( V_11 , V_44 , V_2 , V_3 , 4 , V_16 ) ; V_3 += 4 ;
V_17 = F_4 ( V_2 , V_3 ) ;
F_15 ( V_11 , V_45 , V_2 , V_3 , 4 , V_17 ) ; V_3 += 4 ;
V_18 = F_4 ( V_2 , V_3 ) ;
F_15 ( V_11 , V_46 , V_2 , V_3 , 4 , V_18 ) ;
F_14 ( V_15 , L_6 , V_16 , V_17 , V_18 ) ;
F_16 ( T_3 -> V_26 , V_27 , L_6 , V_16 , V_17 , V_18 ) ;
break;
case V_6 :
F_12 ( V_11 , V_47 , V_2 , V_3 , 2 , V_33 ) ;
break;
case V_7 :
F_12 ( V_11 , V_48 , V_2 , V_3 , V_4 , V_29 ) ;
break;
case V_49 :
V_16 = F_4 ( V_2 , V_3 ) ;
F_12 ( V_11 , V_44 , V_2 , V_3 , 4 , V_33 ) ;
F_14 ( V_15 , L_7 , V_16 ) ;
F_16 ( T_3 -> V_26 , V_27 , L_7 , V_16 ) ;
break;
case V_50 :
F_12 ( V_11 , V_51 , V_2 , V_3 , V_4 , V_29 ) ;
F_14 ( V_15 , L_8 , V_4 ) ;
F_16 ( T_3 -> V_26 , V_27 , L_8 , V_4 ) ;
break;
case V_52 :
V_16 = F_4 ( V_2 , V_3 ) ;
F_15 ( V_11 , V_44 , V_2 , V_3 , 4 , V_16 ) ;
V_3 += 4 ;
V_4 -= 4 ;
V_17 = F_4 ( V_2 , V_3 ) ;
F_15 ( V_11 , V_45 , V_2 , V_3 , 4 , V_17 ) ;
V_3 += 4 ;
V_4 -= 4 ;
F_12 ( V_11 , V_53 , V_2 , V_3 , V_4 , V_29 ) ;
F_14 ( V_15 , L_9 , V_16 , V_17 , V_4 ) ;
F_16 ( T_3 -> V_26 , V_27 , L_9 , V_16 , V_17 , V_4 ) ;
break;
case V_54 :
case V_55 :
V_20 = F_17 ( V_2 , V_3 , V_4 , V_4 ) ;
F_18 ( V_56 , V_20 , T_3 , V_11 ) ;
break;
case V_57 :
V_19 = F_4 ( V_2 , V_3 ) ;
F_12 ( V_11 , V_58 , V_2 , V_3 , 4 , V_33 ) ;
F_12 ( V_11 , V_59 , V_2 , V_3 + 4 , V_19 , V_36 | V_29 ) ;
F_12 ( V_11 , V_60 , V_2 , V_3 + 4 + V_19 , 4 , V_33 ) ;
F_12 ( V_11 , V_61 , V_2 , V_3 + 4 + V_19 + 4 , 4 , V_33 ) ;
break;
case V_62 :
F_12 ( V_11 , V_61 , V_2 , V_3 , 4 , V_33 ) ;
break;
default:
break;
}
}
static int
F_19 ( T_4 * V_2 , T_2 * T_3 V_1 , T_7 * V_8 )
{
int V_3 = 0 ;
int V_9 ;
char * V_63 ;
F_11 ( T_3 -> V_26 , V_27 , L_10 ) ;
F_12 ( V_8 , V_64 , V_2 , V_3 , 1 , V_33 ) ; V_3 += 1 ;
F_12 ( V_8 , V_65 , V_2 , V_3 , 19 , V_36 | V_29 ) ; V_3 += 19 ;
F_12 ( V_8 , V_66 , V_2 , V_3 , 8 , V_29 ) ; V_3 += 8 ;
F_12 ( V_8 , V_67 , V_2 , V_3 , 20 , V_29 ) ;
V_3 += 20 ;
F_12 ( V_8 , V_68 , V_2 , V_3 , 20 , V_29 ) ;
if( V_69 ) {
for( V_9 = 0 ; V_70 [ V_9 ] . V_23 != NULL ; ++ V_9 )
{
if( F_3 ( V_2 , V_3 , V_70 [ V_9 ] . V_71 , ( int ) strlen ( V_70 [ V_9 ] . V_71 ) ) == 0 ) {
V_63 = F_20 ( F_21 () , V_2 , V_3 + ( int ) strlen ( V_70 [ V_9 ] . V_71 ) ,
V_70 [ V_9 ] . V_72 ) ;
F_10 ( V_8 , V_2 , V_3 , 20 , L_11 ,
V_70 [ V_9 ] . V_23 ,
F_22 ( ( V_73 * ) V_63 , V_70 [ V_9 ] . V_72 ) ) ;
break;
}
}
}
V_3 += 20 ;
return V_3 ;
}
static
int F_23 ( T_4 * V_2 , T_2 * T_3 , T_7 * V_8 , void * T_10 V_1 )
{
T_9 * V_15 ;
F_11 ( T_3 -> V_26 , V_74 , L_12 ) ;
F_11 ( T_3 -> V_26 , V_27 , L_13 ) ;
V_15 = F_12 ( V_8 , V_75 , V_2 , 0 , - 1 , V_29 ) ;
V_8 = F_13 ( V_15 , V_76 ) ;
if ( F_2 ( V_2 , 0 ) == 19 &&
F_3 ( V_2 , 1 , L_1 , 19 ) == 0 ) {
F_19 ( V_2 , T_3 , V_8 ) ;
} else {
F_7 ( V_2 , T_3 , V_8 ) ;
}
F_24 ( T_3 -> V_26 , V_27 , L_14 ) ;
F_25 ( T_3 -> V_26 , V_27 ) ;
return F_26 ( V_2 ) ;
}
static
int F_27 ( T_4 * V_2 , T_2 * T_3 , T_7 * V_8 , void * T_10 )
{
F_28 ( V_2 , T_3 , V_8 , V_77 , V_5 ,
F_1 , F_23 , T_10 ) ;
return F_26 ( V_2 ) ;
}
static
T_11 F_29 ( T_4 * V_2 , T_2 * T_3 ,
T_7 * V_8 , void * T_10 )
{
T_12 * V_78 ;
if ( F_26 ( V_2 ) >= 20 &&
F_2 ( V_2 , 0 ) == 19 &&
F_3 ( V_2 , 1 , L_1 , 19 ) == 0 ) {
V_78 = F_30 ( T_3 ) ;
F_31 ( V_78 , V_79 ) ;
F_27 ( V_2 , T_3 , V_8 , T_10 ) ;
return TRUE ;
}
return FALSE ;
}
void
F_32 ( void )
{
static T_13 V_80 [] = {
#if 0
{ &hf_bittorrent_field_length,
{ "Field Length", "bittorrent.length", FT_UINT32, BASE_DEC, NULL, 0x0, NULL, HFILL }
},
#endif
{ & V_64 ,
{ L_15 , L_16 , V_81 , V_82 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_65 ,
{ L_17 , L_18 , V_84 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_66 ,
{ L_19 , L_20 , V_86 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_67 ,
{ L_21 , L_22 , V_86 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_68 ,
{ L_23 , L_24 , V_86 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_30 ,
{ L_25 , L_26 , V_87 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_32 ,
{ L_27 , L_28 , V_88 , V_82 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_38 ,
{ L_29 , L_30 , V_81 , V_82 , F_33 ( V_25 ) , 0x0 , NULL , V_83 }
} ,
{ & V_28 ,
{ L_31 , L_32 , V_87 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_34 ,
{ L_33 , L_34 , V_88 , V_82 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_35 ,
{ L_29 , L_35 , V_84 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_37 ,
{ L_36 , L_37 , V_81 , V_82 , F_33 ( V_89 ) , 0x0 , NULL , V_83 }
} ,
{ & V_51 ,
{ L_38 , L_39 , V_86 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_44 ,
{ L_40 , L_41 , V_88 , V_90 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_45 ,
{ L_42 , L_43 , V_88 , V_90 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_53 ,
{ L_44 , L_45 , V_86 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_46 ,
{ L_46 , L_47 , V_88 , V_90 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_58 ,
{ L_48 , L_49 , V_88 , V_82 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_59 ,
{ L_50 , L_51 , V_84 , V_85 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_60 ,
{ L_52 , L_53 , V_88 , V_82 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_61 ,
{ L_54 , L_55 , V_88 , V_90 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_47 ,
{ L_52 , L_56 , V_91 , V_82 , NULL , 0x0 , NULL , V_83 }
} ,
{ & V_48 ,
{ L_57 , L_58 , V_86 , V_85 , NULL , 0x0 , NULL , V_83 }
}
} ;
static T_14 * V_92 [] = {
& V_76 ,
& V_31 ,
& V_93 ,
} ;
T_15 * V_94 ;
V_75 = F_34 ( L_12 , L_12 , L_59 ) ;
F_35 ( V_75 , V_80 , F_36 ( V_80 ) ) ;
F_37 ( V_92 , F_36 ( V_92 ) ) ;
F_38 ( L_60 , F_27 , V_75 ) ;
V_94 = F_39 ( V_75 , NULL ) ;
F_40 ( V_94 , L_61 ,
L_62 ,
L_63
L_64 ,
& V_77 ) ;
F_40 ( V_94 , L_65 ,
L_66 ,
L_67 ,
& V_69 ) ;
}
void
F_41 ( void )
{
V_56 = F_42 ( L_68 ) ;
V_79 = F_42 ( L_60 ) ;
#if 0
dissector_add_uint("tcp.port", 6881, dissector_handle);
dissector_add_uint("tcp.port", 6882, dissector_handle);
dissector_add_uint("tcp.port", 6883, dissector_handle);
dissector_add_uint("tcp.port", 6884, dissector_handle);
dissector_add_uint("tcp.port", 6885, dissector_handle);
dissector_add_uint("tcp.port", 6886, dissector_handle);
dissector_add_uint("tcp.port", 6887, dissector_handle);
dissector_add_uint("tcp.port", 6888, dissector_handle);
dissector_add_uint("tcp.port", 6889, dissector_handle);
#endif
F_43 ( L_69 , F_29 , V_75 ) ;
}
