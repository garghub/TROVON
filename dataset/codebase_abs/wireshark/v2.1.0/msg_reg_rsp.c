static int F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 = 0 ;
T_5 V_6 ;
T_5 V_7 ;
T_6 * V_8 ;
T_3 * V_9 ;
T_6 * V_10 = NULL ;
T_3 * V_11 = NULL ;
T_3 * V_12 = NULL ;
T_7 V_13 = FALSE ;
T_8 V_14 ;
T_9 V_15 ;
T_5 V_16 ;
T_5 V_17 = 0 ;
T_8 V_18 ;
T_9 V_19 ;
T_9 V_20 ;
T_5 V_21 ;
{
V_7 = F_2 ( V_1 ) ;
V_8 = F_3 ( V_3 , V_22 , V_1 , V_5 , V_7 , L_1 ) ;
V_9 = F_4 ( V_8 , V_23 ) ;
F_5 ( V_9 , V_24 , V_1 , V_5 , 1 , V_25 ) ;
V_5 += 1 ;
while ( V_5 < V_7 )
{
F_6 ( & V_14 , V_1 , V_5 ) ;
V_15 = F_7 ( & V_14 ) ;
V_16 = F_8 ( & V_14 ) ;
if ( V_15 == - 1 || V_16 > V_26 || V_16 < 1 )
{
F_9 ( V_2 -> V_27 , V_28 , NULL , L_2 ) ;
F_5 ( V_9 , V_29 , V_1 , V_5 , ( V_7 - V_5 ) , V_30 ) ;
break;
}
V_6 = V_5 + F_10 ( & V_14 ) ;
switch ( V_15 ) {
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
case V_44 :
#ifdef F_11
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
case V_57 :
#endif
F_12 ( V_9 , V_15 , V_1 , V_6 , V_16 , V_2 , V_5 , V_22 ) ;
break;
case V_58 :
F_13 ( & V_14 , V_9 , V_59 , V_1 , V_5 , V_25 ) ;
break;
case V_60 :
F_13 ( & V_14 , V_9 , V_61 , V_1 , V_5 , V_25 ) ;
break;
case V_62 :
V_12 = F_14 ( & V_14 , V_63 , V_9 , V_22 , V_1 , V_5 , V_16 , L_3 ) ;
V_17 = V_6 ;
while( V_17 < V_16 ) {
F_6 ( & V_18 , V_1 , V_17 ) ;
V_19 = F_7 ( & V_18 ) ;
V_20 = F_8 ( & V_18 ) ;
if ( V_15 == - 1 || V_20 > V_26 || V_20 < 1 )
{
F_9 ( V_2 -> V_27 , V_28 , NULL , L_2 ) ;
F_5 ( V_9 , V_29 , V_1 , V_5 , ( V_7 - V_5 ) , V_30 ) ;
break;
}
V_21 = V_17 + F_10 ( & V_18 ) ;
switch ( V_19 ) {
case V_64 :
F_13 ( & V_18 , V_12 , V_65 , V_1 , V_17 , V_25 ) ;
break;
case V_66 :
F_13 ( & V_18 , V_12 , V_67 , V_1 , V_17 , V_25 ) ;
break;
case V_68 :
V_11 = F_14 ( & V_18 , V_63 , V_12 , V_22 , V_1 , V_17 , V_20 , L_4 ) ;
F_15 ( V_69 , F_16 ( V_1 , V_21 , V_20 ) , V_2 , V_11 ) ;
break;
default:
F_13 ( & V_18 , V_12 , V_70 , V_1 , V_17 , V_30 ) ;
break;
}
V_17 = V_20 + V_21 ;
}
break;
case V_71 :
V_10 = F_13 ( & V_14 , V_9 , V_72 , V_1 , V_5 , V_25 ) ;
if ( V_73 ) {
F_17 ( V_10 , L_5 ) ;
} else {
F_17 ( V_10 , L_6 ) ;
}
break;
case V_74 :
V_11 = F_14 ( & V_14 , V_23 , V_9 , V_22 , V_1 , V_5 , V_16 , L_7 ) ;
F_18 ( F_16 ( V_1 , V_6 , V_16 ) , V_2 , V_11 ) ;
break;
case V_75 :
V_11 = F_14 ( & V_14 , V_23 , V_9 , V_22 , V_1 , V_5 , V_16 , L_8 ) ;
F_18 ( F_16 ( V_1 , V_6 , V_16 ) , V_2 , V_11 ) ;
break;
case V_76 :
V_11 = F_14 ( & V_14 , V_23 , V_9 , V_22 , V_1 , V_5 , V_16 , L_9 ) ;
F_19 ( V_11 , V_1 , V_5 + 2 , V_16 ) ;
V_13 = TRUE ;
break;
case V_77 :
V_11 = F_14 ( & V_14 , V_23 , V_9 , V_22 , V_1 , V_5 , V_16 , L_10 ) ;
F_20 ( V_11 , V_1 , V_5 + 2 , V_16 ) ;
break;
case V_78 :
case V_79 :
if ( ( ! V_73 && ( V_15 == V_78 ) ) ||
( V_73 && ( V_15 == V_79 ) ) ) {
V_11 = F_14 ( & V_14 , V_23 , V_9 , V_22 , V_1 , V_5 , V_16 , L_11 ) ;
F_21 ( V_11 , V_1 , V_6 , V_16 ) ;
} else {
F_13 ( & V_14 , V_9 , V_70 , V_1 , V_5 , V_30 ) ;
}
break;
case V_80 :
case V_81 :
case V_82 :
F_22 ( F_16 ( V_1 , V_5 , ( V_7 - V_5 ) ) , V_2 , V_9 ) ;
break;
default:
F_13 ( & V_14 , V_9 , V_70 , V_1 , V_5 , V_30 ) ;
break;
}
V_5 = V_16 + V_6 ;
}
if ( ! V_13 )
F_17 ( V_9 , L_12 ) ;
}
return F_23 ( V_1 ) ;
}
void F_24 ( void )
{
static T_10 V_83 [] =
{
{
& V_29 ,
{
L_13 , L_14 ,
V_84 , V_85 , NULL , 0 , NULL , V_86
}
} ,
{
& V_65 ,
{
L_15 , L_16 ,
V_87 , V_88 , NULL , 0x0 , NULL , V_86
}
} ,
{
& V_24 ,
{
L_17 , L_18 ,
V_89 , V_90 , F_25 ( V_91 ) , 0x0 , NULL , V_86
}
} ,
{
& V_59 ,
{
L_19 , L_20 ,
V_87 , V_88 , NULL , 0x0 , NULL , V_86
}
} ,
{
& V_61 ,
{
L_21 , L_22 ,
V_89 , V_88 , NULL , 0x0 , NULL , V_86
}
} ,
{
& V_67 ,
{
L_23 , L_24 ,
V_92 , V_88 , NULL , 0x0 , NULL , V_86
}
} ,
{
& V_72 ,
{
L_25 , L_26 ,
V_87 , V_88 , NULL , 0x0 , NULL , V_86
}
} ,
{
& V_70 ,
{
L_27 , L_28 ,
V_84 , V_85 , NULL , 0x00 , NULL , V_86
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
static T_9 * V_93 [] =
{
& V_23 ,
& V_63
} ;
V_22 = F_26 (
L_29 ,
L_30 ,
L_31
) ;
F_27 ( V_22 , V_83 , F_28 ( V_83 ) ) ;
F_29 ( V_93 , F_28 ( V_93 ) ) ;
F_30 ( L_32 , F_1 , - 1 ) ;
}
void F_31 ( void )
{
T_11 V_94 ;
V_69 = F_32 ( L_33 ) ;
V_94 = F_33 ( F_1 , V_22 ) ;
F_34 ( L_34 , V_95 , V_94 ) ;
}
