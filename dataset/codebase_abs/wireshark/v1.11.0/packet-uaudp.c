static T_1 F_1 ( T_2 V_1 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( V_4 [ V_2 ] . V_1 == V_1 )
return TRUE ;
return FALSE ;
}
static void F_2 ( T_3 * V_5 , int * V_6 , T_4 * V_7 , T_5 V_8 , T_6 V_9 )
{
switch( V_9 )
{
case 1 :
F_3 ( V_5 ,
* V_6 ,
V_7 ,
V_8 ,
V_9 + 2 ,
F_4 ( V_7 , V_8 + 2 ) ) ;
break;
case 2 :
F_3 ( V_5 ,
* V_6 ,
V_7 ,
V_8 ,
V_9 + 2 ,
F_5 ( V_7 , V_8 + 2 ) ) ;
break;
case 3 :
F_3 ( V_5 ,
* V_6 ,
V_7 ,
V_8 ,
V_9 + 2 ,
F_6 ( V_7 , V_8 + 2 ) ) ;
break;
case 4 :
F_3 ( V_5 ,
* V_6 ,
V_7 ,
V_8 ,
V_9 + 2 ,
F_7 ( V_7 , V_8 + 2 ) ) ;
break;
}
}
static void F_8 ( T_4 * V_7 , T_7 * V_10 , T_3 * V_5 ,
T_8 V_11 )
{
T_5 V_8 = 0 ;
T_9 V_12 ;
T_10 * V_13 ;
T_3 * V_14 ;
F_9 ( V_10 -> V_15 , V_16 , L_1 ) ;
V_12 = F_4 ( V_7 , V_8 ) ;
V_8 += 1 ;
V_17 . V_12 = V_12 ;
V_17 . V_18 = 0 ;
V_17 . V_19 = 0 ;
F_10 ( V_10 -> V_15 ,
V_20 ,
L_2 ,
F_11 ( V_12 , & V_21 , L_3 ) ) ;
V_13 = F_12 ( V_5 , V_22 , V_7 , 0 , 5 ,
L_4 ,
F_11 ( V_12 , & V_21 , L_3 ) ) ;
V_14 = F_13 ( V_13 , V_23 ) ;
F_3 ( V_14 , V_24 , V_7 , 0 , 1 , V_12 ) ;
switch( V_12 )
{
case V_25 :
{
if ( ! V_5 )
break;
while ( F_14 ( V_7 , V_8 ) )
{
T_9 V_26 = F_4 ( V_7 , V_8 + 0 ) ;
T_9 V_9 = F_4 ( V_7 , V_8 + 1 ) ;
switch( V_26 )
{
case V_27 :
F_2 ( V_14 , & V_28 , V_7 , V_8 , V_9 ) ;
break;
case V_29 :
F_2 ( V_14 , & V_30 , V_7 , V_8 , V_9 ) ;
break;
case V_31 :
F_2 ( V_14 , & V_32 , V_7 , V_8 , V_9 ) ;
break;
case V_33 :
F_2 ( V_14 , & V_34 , V_7 , V_8 , V_9 ) ;
break;
case V_35 :
F_2 ( V_14 , & V_36 , V_7 , V_8 , V_9 ) ;
break;
case V_37 :
F_2 ( V_14 , & V_38 , V_7 , V_8 , V_9 ) ;
break;
case V_39 :
F_2 ( V_14 , & V_40 , V_7 , V_8 , V_9 ) ;
break;
case V_41 :
F_2 ( V_14 , & V_42 , V_7 , V_8 , V_9 ) ;
break;
case V_43 :
F_2 ( V_14 , & V_44 , V_7 , V_8 , V_9 ) ;
break;
}
V_8 += ( 2 + V_9 ) ;
}
break;
}
case V_45 :
{
F_3 ( V_14 ,
V_46 ,
V_7 ,
V_8 ,
2 ,
F_5 ( V_7 , V_8 ) ) ;
break;
}
case V_47 :
{
int V_48 ;
F_3 ( V_14 ,
V_46 ,
V_7 ,
V_8 + 0 ,
2 ,
F_5 ( V_7 , V_8 + 0 ) ) ;
F_3 ( V_14 ,
V_49 ,
V_7 ,
V_8 + 2 ,
2 ,
F_5 ( V_7 , V_8 + 2 ) ) ;
V_17 . V_18 = V_46 ;
V_17 . V_19 = V_49 ;
V_8 += 4 ;
V_48 = F_15 ( V_7 ) - V_8 ;
if ( V_48 > 0 )
{
if ( V_11 == V_50 )
F_16 ( V_51 ,
F_17 ( V_7 , V_8 , V_48 , V_48 ) ,
V_10 ,
V_5 ) ;
else if ( V_11 == V_52 )
F_16 ( V_53 ,
F_17 ( V_7 , V_8 , V_48 , V_48 ) ,
V_10 ,
V_5 ) ;
else {
F_18 ( V_10 -> V_15 ,
V_20 ,
L_5 ) ;
}
V_17 . V_18 = V_46 ;
}
else {
F_18 ( V_10 -> V_15 ,
V_20 ,
L_6 ) ;
}
break;
}
default:
break;
}
#if 0
tap_queue_packet(uaudp_tap, pinfo, &ua_tap_info);
#endif
}
static void F_19 ( T_4 * V_7 , T_7 * V_10 , T_3 * V_5 )
{
if ( V_54 ) {
if ( memcmp ( ( V_10 -> V_55 ) . V_56 , V_57 , 4 * sizeof( T_9 ) ) == 0 )
{
F_8 ( V_7 , V_10 , V_5 , V_50 ) ;
return;
}
else if ( memcmp ( ( V_10 -> V_58 ) . V_56 , V_57 , 4 * sizeof( T_9 ) ) == 0 )
{
F_8 ( V_7 , V_10 , V_5 , V_52 ) ;
return;
}
}
if ( F_1 ( V_10 -> V_59 ) )
{
F_8 ( V_7 , V_10 , V_5 , V_52 ) ;
return;
}
else if ( F_1 ( V_10 -> V_60 ) )
{
F_8 ( V_7 , V_10 , V_5 , V_50 ) ;
return;
}
F_8 ( V_7 , V_10 , V_5 , V_61 ) ;
}
static T_1 F_20 ( const T_11 * V_62 , T_9 * V_63 )
{
int V_2 ;
const T_11 * V_64 = V_62 ;
T_12 V_65 ;
if ( V_62 == NULL )
return FALSE ;
for ( V_2 = 0 ; V_2 < 4 ; V_2 ++ )
{
V_65 = 0 ;
while ( * V_64 != '.' && * V_64 != '\0' )
{
V_65 = V_65 * 10 + ( * V_64 - '0' ) ;
V_64 ++ ;
}
if ( V_65 > 255 )
{
return FALSE ;
}
V_63 [ V_2 ] = V_65 ;
V_64 ++ ;
}
return TRUE ;
}
void F_21 ( void )
{
T_13 * V_66 ;
int V_2 ;
static T_14 V_67 [] = {
{
& V_24 ,
{
L_7 ,
L_8 ,
V_68 ,
V_69 | V_70 ,
& V_21 ,
0x0 ,
L_9 ,
V_71
}
} ,
{
& V_28 ,
{
L_10 ,
L_11 ,
V_68 ,
V_69 ,
NULL , 0x0 ,
L_12 ,
V_71
}
} ,
{
& V_30 ,
{
L_13 ,
L_14 ,
V_68 ,
V_69 ,
NULL ,
0x0 ,
L_15 ,
V_71
}
} ,
{
& V_32 ,
{
L_16 ,
L_17 ,
V_68 ,
V_69 ,
NULL ,
0x0 ,
L_18 ,
V_71
}
} ,
{
& V_34 ,
{
L_19 ,
L_20 ,
V_68 ,
V_69 ,
NULL ,
0x0 ,
L_21 ,
V_71
}
} ,
{
& V_36 ,
{
L_22 ,
L_23 ,
V_68 ,
V_69 ,
NULL , 0x0 ,
L_24 ,
V_71
}
} ,
{
& V_38 ,
{
L_25 ,
L_26 ,
V_68 ,
V_69 ,
NULL ,
0x0 ,
L_27 ,
V_71
}
} ,
{
& V_40 ,
{
L_28 ,
L_29 ,
V_68 ,
V_69 ,
NULL ,
0x0 ,
L_30 ,
V_71
}
} ,
{
& V_42 ,
{
L_31 ,
L_32 ,
V_68 ,
V_69 ,
NULL ,
0x0 ,
L_33 ,
V_71
}
} ,
{
& V_44 ,
{
L_34 ,
L_35 ,
V_68 ,
V_69 ,
NULL ,
0x0 ,
L_36 ,
V_71
}
} ,
{
& V_46 ,
{
L_37 ,
L_38 ,
V_72 ,
V_69 ,
NULL ,
0x0 ,
L_39 ,
V_71
}
} ,
{
& V_49 ,
{
L_40 ,
L_41 ,
V_72 ,
V_69 ,
NULL ,
0x0 ,
L_42 ,
V_71
}
} ,
} ;
static T_5 * V_73 [] =
{
& V_23 ,
} ;
V_22 = F_22 ( L_43 ,
L_1 ,
L_44 ) ;
F_23 ( L_44 , F_19 , V_22 ) ;
#if 0
register_dissector("uaudp_dir_unknown", dissect_uaudp_dir_unknown, proto_uaudp);
register_dissector("uaudp_term_to_serv", dissect_uaudp_term_to_serv, proto_uaudp);
register_dissector("uaudp_serv_to_term", dissect_uaudp_serv_to_term, proto_uaudp);
#endif
F_24 ( V_22 , V_67 , F_25 ( V_67 ) ) ;
F_26 ( V_73 , F_25 ( V_73 ) ) ;
V_66 = F_27 ( V_22 , V_74 ) ;
#if 0
prefs_register_bool_preference(uaudp_module, "enable",
"Enable UA/UDP decoding based on preferences",
"Enable UA/UDP decoding based on preferences",
&decode_ua);
#endif
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
F_28 ( V_66 ,
V_4 [ V_2 ] . V_75 ,
V_4 [ V_2 ] . V_76 ,
V_4 [ V_2 ] . V_76 ,
10 ,
& V_4 [ V_2 ] . V_1 ) ;
}
F_29 ( V_66 , L_45 ,
L_46 ,
L_47
L_48 ,
& V_77 ) ;
#if 0
uaudp_tap = register_tap("uaudp");*/
#endif
}
void V_74 ( void )
{
static T_1 V_78 = FALSE ;
static T_15 V_79 ;
int V_2 ;
if ( ! V_78 )
{
V_79 = F_30 ( L_44 ) ;
V_51 = F_30 ( L_49 ) ;
V_53 = F_30 ( L_50 ) ;
#if 0
uaudp_opcode_dissector_table =
register_dissector_table("uaudp.opcode",
"UAUDP opcode",
FT_UINT8,
BASE_DEC);
#endif
V_78 = TRUE ;
}
else
{
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
{
if ( V_4 [ V_2 ] . V_80 )
F_31 ( L_51 , V_4 [ V_2 ] . V_80 , V_79 ) ;
}
if ( F_20 ( V_77 , V_57 ) )
{
V_54 = TRUE ;
}
else
{
V_54 = FALSE ;
V_77 = L_52 ;
}
}
if ( V_81 )
{
int V_82 = TRUE ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
{
if ( V_4 [ V_2 ] . V_1 )
{
F_32 ( L_51 , V_4 [ V_2 ] . V_1 , V_79 ) ;
V_82 = FALSE ;
}
V_4 [ V_2 ] . V_80 = V_4 [ V_2 ] . V_1 ;
}
if ( V_82 )
{
F_33 ( L_51 , V_79 ) ;
}
}
}
