static void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 = 0 ;
T_4 V_5 ;
T_4 V_6 ;
T_5 * V_7 ;
T_3 * V_8 ;
T_5 * V_9 = NULL ;
T_3 * V_10 = NULL ;
T_3 * V_11 = NULL ;
T_6 V_12 = FALSE ;
T_7 V_13 ;
T_8 V_14 ;
T_4 V_15 ;
T_4 V_16 = 0 ;
T_7 V_17 ;
T_8 V_18 ;
T_8 V_19 ;
T_4 V_20 ;
{
V_6 = F_2 ( V_1 ) ;
V_7 = F_3 ( V_3 , V_21 , V_1 , V_4 , V_6 , L_1 ) ;
V_8 = F_4 ( V_7 , V_22 ) ;
F_5 ( V_8 , V_23 , V_1 , V_4 , 1 , V_24 ) ;
V_4 += 1 ;
while ( V_4 < V_6 )
{
F_6 ( & V_13 , V_1 , V_4 ) ;
V_14 = F_7 ( & V_13 ) ;
V_15 = F_8 ( & V_13 ) ;
if ( V_14 == - 1 || V_15 > V_25 || V_15 < 1 )
{
F_9 ( V_2 -> V_26 , V_27 , NULL , L_2 ) ;
F_5 ( V_8 , V_28 , V_1 , V_4 , ( V_6 - V_4 ) , V_29 ) ;
break;
}
V_5 = V_4 + F_10 ( & V_13 ) ;
switch ( V_14 ) {
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
#ifdef F_11
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
#endif
F_12 ( V_8 , V_14 , V_1 , V_5 , V_15 , V_2 , V_4 , V_21 ) ;
break;
case V_57 :
F_13 ( & V_13 , V_8 , V_58 , V_1 , V_4 , V_24 ) ;
break;
case V_59 :
F_13 ( & V_13 , V_8 , V_60 , V_1 , V_4 , V_24 ) ;
break;
case V_61 :
V_11 = F_14 ( & V_13 , V_62 , V_8 , V_21 , V_1 , V_4 , V_15 , L_3 ) ;
V_16 = V_5 ;
while( V_16 < V_15 ) {
F_6 ( & V_17 , V_1 , V_16 ) ;
V_18 = F_7 ( & V_17 ) ;
V_19 = F_8 ( & V_17 ) ;
if ( V_14 == - 1 || V_19 > V_25 || V_19 < 1 )
{
F_9 ( V_2 -> V_26 , V_27 , NULL , L_2 ) ;
F_5 ( V_8 , V_28 , V_1 , V_4 , ( V_6 - V_4 ) , V_29 ) ;
break;
}
V_20 = V_16 + F_10 ( & V_17 ) ;
switch ( V_18 ) {
case V_63 :
F_13 ( & V_17 , V_11 , V_64 , V_1 , V_16 , V_24 ) ;
break;
case V_65 :
F_13 ( & V_17 , V_11 , V_66 , V_1 , V_16 , V_24 ) ;
break;
case V_67 :
V_10 = F_14 ( & V_17 , V_62 , V_11 , V_21 , V_1 , V_16 , V_19 , L_4 ) ;
F_15 ( V_68 , F_16 ( V_1 , V_20 , V_19 ) , V_2 , V_10 ) ;
break;
default:
F_13 ( & V_17 , V_11 , V_69 , V_1 , V_16 , V_29 ) ;
break;
}
V_16 = V_19 + V_20 ;
}
break;
case V_70 :
V_9 = F_13 ( & V_13 , V_8 , V_71 , V_1 , V_4 , V_24 ) ;
if ( V_72 ) {
F_17 ( V_9 , L_5 ) ;
} else {
F_17 ( V_9 , L_6 ) ;
}
break;
case V_73 :
V_10 = F_14 ( & V_13 , V_22 , V_8 , V_21 , V_1 , V_4 , V_15 , L_7 ) ;
F_18 ( F_16 ( V_1 , V_5 , V_15 ) , V_2 , V_10 ) ;
break;
case V_74 :
V_10 = F_14 ( & V_13 , V_22 , V_8 , V_21 , V_1 , V_4 , V_15 , L_8 ) ;
F_18 ( F_16 ( V_1 , V_5 , V_15 ) , V_2 , V_10 ) ;
break;
case V_75 :
V_10 = F_14 ( & V_13 , V_22 , V_8 , V_21 , V_1 , V_4 , V_15 , L_9 ) ;
F_19 ( V_10 , V_1 , V_4 + 2 , V_15 ) ;
V_12 = TRUE ;
break;
case V_76 :
V_10 = F_14 ( & V_13 , V_22 , V_8 , V_21 , V_1 , V_4 , V_15 , L_10 ) ;
F_20 ( V_10 , V_1 , V_4 + 2 , V_15 ) ;
break;
case V_77 :
case V_78 :
if ( ( ! V_72 && ( V_14 == V_77 ) ) ||
( V_72 && ( V_14 == V_78 ) ) ) {
V_10 = F_14 ( & V_13 , V_22 , V_8 , V_21 , V_1 , V_4 , V_15 , L_11 ) ;
F_21 ( V_10 , V_1 , V_5 , V_15 ) ;
} else {
F_13 ( & V_13 , V_8 , V_69 , V_1 , V_4 , V_29 ) ;
}
break;
case V_79 :
case V_80 :
case V_81 :
F_22 ( F_16 ( V_1 , V_4 , ( V_6 - V_4 ) ) , V_2 , V_8 ) ;
break;
default:
F_13 ( & V_13 , V_8 , V_69 , V_1 , V_4 , V_29 ) ;
break;
}
V_4 = V_15 + V_5 ;
}
if ( ! V_12 )
F_17 ( V_8 , L_12 ) ;
}
}
void F_23 ( void )
{
static T_9 V_82 [] =
{
{
& V_28 ,
{
L_13 , L_14 ,
V_83 , V_84 , NULL , 0 , NULL , V_85
}
} ,
{
& V_64 ,
{
L_15 , L_16 ,
V_86 , V_87 , NULL , 0x0 , NULL , V_85
}
} ,
{
& V_23 ,
{
L_17 , L_18 ,
V_88 , V_89 , F_24 ( V_90 ) , 0x0 , NULL , V_85
}
} ,
{
& V_58 ,
{
L_19 , L_20 ,
V_86 , V_87 , NULL , 0x0 , NULL , V_85
}
} ,
{
& V_60 ,
{
L_21 , L_22 ,
V_88 , V_87 , NULL , 0x0 , NULL , V_85
}
} ,
{
& V_66 ,
{
L_23 , L_24 ,
V_91 , V_87 , NULL , 0x0 , NULL , V_85
}
} ,
{
& V_71 ,
{
L_25 , L_26 ,
V_86 , V_87 , NULL , 0x0 , NULL , V_85
}
} ,
{
& V_69 ,
{
L_27 , L_28 ,
V_83 , V_84 , NULL , 0x00 , NULL , V_85
}
} ,
#if 0
{
&hf_tlv_value,
{
"Value", "wmx.reg_rsp.tlv_value",
FT_BYTES, BASE_NONE, NULL, 0x00, NULL, HFILL
}
}
#endif
} ;
static T_8 * V_92 [] =
{
& V_22 ,
& V_62
} ;
V_21 = F_25 (
L_29 ,
L_30 ,
L_31
) ;
F_26 ( V_21 , V_82 , F_27 ( V_82 ) ) ;
F_28 ( V_92 , F_27 ( V_92 ) ) ;
F_29 ( L_32 , F_1 , - 1 ) ;
}
void F_30 ( void )
{
T_10 V_93 ;
V_68 = F_31 ( L_33 ) ;
V_93 = F_32 ( F_1 , V_21 ) ;
F_33 ( L_34 , V_94 , V_93 ) ;
}
