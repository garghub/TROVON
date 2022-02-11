static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 ,
T_4 V_4 )
{
T_5 V_5 = 0 ;
T_6 type , V_6 ;
T_7 V_7 ;
T_8 * V_8 , * V_9 , * V_10 ;
T_3 * V_11 , * V_12 ;
F_2 ( V_2 -> V_13 , V_14 , L_1 ) ;
V_7 = F_3 ( V_1 , V_5 ) ;
V_5 += 1 ;
V_15 . V_7 = V_7 ;
V_15 . V_16 = 0 ;
V_15 . V_17 = 0 ;
F_4 ( V_2 -> V_13 ,
V_18 ,
L_2 ,
F_5 ( V_7 , & V_19 , L_3 ) ) ;
V_8 = F_6 ( V_3 , V_20 , V_1 , 0 , F_7 ( V_1 ) ,
L_4 ,
F_5 ( V_7 , & V_19 , L_3 ) ) ;
V_11 = F_8 ( V_8 , V_21 ) ;
F_9 ( V_11 , V_22 , V_1 , 0 , 1 , V_7 ) ;
switch( V_7 )
{
case V_23 :
{
while( F_10 ( V_1 , V_5 ) > 0 )
{
type = F_3 ( V_1 , V_5 + 0 ) ;
V_12 = F_11 ( V_11 , V_1 , V_5 , 0 , V_24 , & V_9 ,
F_5 ( type , & V_25 , L_5 ) ) ;
F_9 ( V_12 , V_26 , V_1 , V_5 , 1 , type ) ;
V_5 ++ ;
V_10 = F_12 ( V_12 , V_27 , V_1 , V_5 , 1 , V_28 , & V_6 ) ;
F_13 ( V_9 , V_6 + 2 ) ;
V_5 ++ ;
switch( type )
{
case V_29 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_30 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
case V_33 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_34 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
case V_35 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_36 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
case V_37 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_38 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
case V_39 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_40 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
case V_41 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_42 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
case V_43 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_44 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
case V_45 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_46 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
case V_47 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_48 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
case V_49 :
if ( ( V_6 >= 1 ) && ( V_6 <= 4 ) )
{
F_14 ( V_12 , V_50 , V_1 , V_5 , V_6 , V_31 ) ;
}
else
{
F_15 ( V_2 , V_10 , & V_32 , L_6 , V_6 ) ;
}
break;
}
V_5 += V_6 ;
}
break;
}
case V_51 :
{
F_14 ( V_11 ,
V_52 ,
V_1 ,
V_5 ,
2 ,
V_31 ) ;
break;
}
case V_53 :
{
int V_54 ;
F_12 ( V_11 ,
V_52 ,
V_1 ,
V_5 + 0 ,
2 ,
V_31 ,
& V_15 . V_16 ) ;
F_12 ( V_11 ,
V_55 ,
V_1 ,
V_5 + 2 ,
2 ,
V_31 ,
& V_15 . V_17 ) ;
V_5 += 4 ;
V_54 = F_7 ( V_1 ) - V_5 ;
if ( V_54 > 0 )
{
if ( V_4 == V_56 )
F_16 ( V_57 ,
F_17 ( V_1 , V_5 , V_54 ) ,
V_2 ,
V_3 ) ;
else if ( V_4 == V_58 )
F_16 ( V_59 ,
F_17 ( V_1 , V_5 , V_54 ) ,
V_2 ,
V_3 ) ;
else {
F_2 ( V_2 -> V_13 ,
V_18 ,
L_7 ) ;
}
V_15 . V_16 = V_52 ;
}
else {
F_2 ( V_2 -> V_13 ,
V_18 ,
L_8 ) ;
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
static int F_18 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_9 V_60 )
{
if ( V_61 ) {
if ( memcmp ( ( V_2 -> V_62 ) . T_9 , & V_63 , sizeof( V_63 ) ) == 0 )
{
F_1 ( V_1 , V_2 , V_3 , V_56 ) ;
return F_19 ( V_1 ) ;
}
else if ( memcmp ( ( V_2 -> V_64 ) . T_9 , & V_63 , sizeof( V_63 ) ) == 0 )
{
F_1 ( V_1 , V_2 , V_3 , V_58 ) ;
return F_19 ( V_1 ) ;
}
}
if ( F_20 ( V_65 , V_2 -> V_66 ) )
{
F_1 ( V_1 , V_2 , V_3 , V_58 ) ;
return F_19 ( V_1 ) ;
}
else if ( F_20 ( V_65 , V_2 -> V_67 ) )
{
F_1 ( V_1 , V_2 , V_3 , V_56 ) ;
return F_19 ( V_1 ) ;
}
F_1 ( V_1 , V_2 , V_3 , V_68 ) ;
return F_19 ( V_1 ) ;
}
static void
F_21 ( void ) {
V_65 = F_22 ( L_9 , L_10 ) ;
if ( * V_69 ) {
V_61 = F_23 ( V_69 , & V_63 ) ;
if ( ! V_61 ) {
F_24 ( L_11 ,
V_69 ) ;
}
}
}
void F_25 ( void )
{
T_10 * V_70 ;
static T_11 V_71 [] = {
{
& V_22 ,
{
L_12 ,
L_13 ,
V_72 ,
V_73 | V_74 ,
& V_19 ,
0x0 ,
L_14 ,
V_75
}
} ,
{
& V_30 ,
{
L_15 ,
L_16 ,
V_72 ,
V_73 ,
NULL , 0x0 ,
L_17 ,
V_75
}
} ,
{
& V_34 ,
{
L_18 ,
L_19 ,
V_72 ,
V_73 ,
NULL ,
0x0 ,
L_20 ,
V_75
}
} ,
{
& V_36 ,
{
L_21 ,
L_22 ,
V_72 ,
V_73 ,
NULL ,
0x0 ,
L_23 ,
V_75
}
} ,
{
& V_38 ,
{
L_24 ,
L_25 ,
V_72 ,
V_73 ,
NULL ,
0x0 ,
L_26 ,
V_75
}
} ,
{
& V_40 ,
{
L_27 ,
L_28 ,
V_72 ,
V_73 ,
NULL , 0x0 ,
L_29 ,
V_75
}
} ,
{
& V_42 ,
{
L_30 ,
L_31 ,
V_72 ,
V_73 ,
NULL ,
0x0 ,
L_32 ,
V_75
}
} ,
{
& V_44 ,
{
L_33 ,
L_34 ,
V_72 ,
V_73 ,
NULL ,
0x0 ,
L_35 ,
V_75
}
} ,
{
& V_46 ,
{
L_36 ,
L_37 ,
V_72 ,
V_73 ,
NULL ,
0x0 ,
L_38 ,
V_75
}
} ,
{
& V_48 ,
{
L_39 ,
L_40 ,
V_72 ,
V_73 ,
NULL ,
0x0 ,
L_41 ,
V_75
}
} ,
{
& V_50 ,
{
L_42 ,
L_43 ,
V_72 ,
V_73 ,
NULL ,
0x0 ,
L_44 ,
V_75
}
} ,
{
& V_52 ,
{
L_45 ,
L_46 ,
V_76 ,
V_73 ,
NULL ,
0x0 ,
L_47 ,
V_75
}
} ,
{
& V_55 ,
{
L_48 ,
L_49 ,
V_76 ,
V_73 ,
NULL ,
0x0 ,
L_50 ,
V_75
}
} ,
{
& V_26 ,
{
L_51 ,
L_52 ,
V_72 ,
V_73 | V_74 ,
& V_25 ,
0x0 ,
NULL ,
V_75
}
} ,
{
& V_27 ,
{
L_53 ,
L_54 ,
V_72 ,
V_73 ,
NULL ,
0x0 ,
NULL ,
V_75
}
} ,
} ;
static T_5 * V_77 [] =
{
& V_21 ,
& V_24 ,
} ;
static T_12 V_78 [] = {
{ & V_32 , { L_55 , V_79 , V_80 , L_56 , V_81 } } ,
} ;
T_13 * V_82 ;
V_20 = F_26 ( L_57 , L_1 , L_9 ) ;
V_83 = F_27 ( L_9 , F_18 , V_20 ) ;
#if 0
register_dissector("uaudp_dir_unknown", dissect_uaudp_dir_unknown, proto_uaudp);
register_dissector("uaudp_term_to_serv", dissect_uaudp_term_to_serv, proto_uaudp);
register_dissector("uaudp_serv_to_term", dissect_uaudp_serv_to_term, proto_uaudp);
#endif
F_28 ( V_20 , V_71 , F_29 ( V_71 ) ) ;
F_30 ( V_77 , F_29 ( V_77 ) ) ;
V_82 = F_31 ( V_20 ) ;
F_32 ( V_82 , V_78 , F_29 ( V_78 ) ) ;
#if 0
uaudp_opcode_dissector_table =
register_dissector_table("uaudp.opcode",
"UAUDP opcode",
FT_UINT8,
BASE_DEC);
#endif
V_70 = F_33 ( V_20 , F_21 ) ;
F_34 ( V_70 , L_58 ,
L_59 ,
L_60
L_61 ,
& V_69 ) ;
#if 0
uaudp_tap = register_tap("uaudp");*/
#endif
}
void F_35 ( void )
{
V_57 = F_36 ( L_62 , V_20 ) ;
V_59 = F_36 ( L_63 , V_20 ) ;
F_37 ( L_10 , V_84 , V_83 ) ;
}
