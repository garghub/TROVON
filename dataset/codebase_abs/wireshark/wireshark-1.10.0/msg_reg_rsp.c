void F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 = 0 ;
T_4 V_5 ;
T_4 V_6 , V_7 ;
T_5 * V_8 = NULL ;
T_3 * V_9 = NULL ;
T_5 * V_10 = NULL ;
T_3 * V_11 = NULL ;
T_3 * V_12 = NULL ;
T_6 V_13 = FALSE ;
T_7 V_14 ;
T_8 V_15 ;
T_4 V_16 ;
T_4 V_17 = 0 ;
T_7 V_18 ;
T_8 V_19 ;
T_8 V_20 ;
T_4 V_21 ;
V_7 = F_2 ( V_1 , V_4 ) ;
if ( V_7 != V_22 )
{
return;
}
if ( V_3 )
{
V_6 = F_3 ( V_1 ) ;
V_8 = F_4 ( V_3 , V_23 , V_1 , V_4 , V_6 , L_1 ) ;
V_9 = F_5 ( V_8 , V_24 ) ;
F_6 ( V_9 , V_25 , V_1 , V_4 , 1 , V_26 ) ;
F_6 ( V_9 , V_27 , V_1 , V_4 + 1 , 1 , V_26 ) ;
V_4 += 2 ;
while ( V_4 < V_6 )
{
F_7 ( & V_14 , V_1 , V_4 ) ;
V_15 = F_8 ( & V_14 ) ;
V_16 = F_9 ( & V_14 ) ;
if ( V_15 == - 1 || V_16 > V_28 || V_16 < 1 )
{
F_10 ( V_2 -> V_29 , V_30 , NULL , L_2 ) ;
F_6 ( V_9 , V_31 , V_1 , V_4 , ( V_6 - V_4 ) , V_32 ) ;
break;
}
V_5 = V_4 + F_11 ( & V_14 ) ;
switch ( V_15 ) {
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
case V_45 :
case V_46 :
#ifdef F_12
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
case V_58 :
case V_59 :
#endif
F_13 ( V_9 , V_15 , V_1 , V_5 , V_16 , V_2 , V_4 , V_23 ) ;
break;
case V_60 :
V_11 = F_14 ( & V_14 , V_61 , V_9 , V_62 , V_1 , V_5 , V_16 , FALSE ) ;
F_6 ( V_11 , V_62 , V_1 , V_5 , V_16 , V_26 ) ;
break;
case V_63 :
V_11 = F_14 ( & V_14 , V_61 , V_9 , V_64 , V_1 , V_5 , V_16 , FALSE ) ;
F_6 ( V_11 , V_64 , V_1 , V_5 , V_16 , V_26 ) ;
break;
case V_65 :
V_12 = F_15 ( & V_14 , V_61 , V_9 , V_23 , V_1 , V_5 , V_16 , L_3 , V_16 ) ;
V_17 = V_5 ;
while( V_17 < V_16 ) {
F_7 ( & V_18 , V_1 , V_17 ) ;
V_19 = F_8 ( & V_18 ) ;
V_20 = F_9 ( & V_18 ) ;
if ( V_15 == - 1 || V_20 > V_28 || V_20 < 1 )
{
F_10 ( V_2 -> V_29 , V_30 , NULL , L_2 ) ;
F_6 ( V_9 , V_31 , V_1 , V_4 , ( V_6 - V_4 ) , V_32 ) ;
break;
}
V_21 = V_17 + F_11 ( & V_18 ) ;
switch ( V_19 ) {
case V_66 :
V_11 = F_14 ( & V_18 , V_61 , V_12 , V_67 , V_1 , V_21 , V_20 , FALSE ) ;
F_6 ( V_11 , V_67 , V_1 , V_21 , V_20 , V_26 ) ;
break;
case V_68 :
V_11 = F_14 ( & V_18 , V_61 , V_12 , V_69 , V_1 , V_21 , V_20 , FALSE ) ;
F_6 ( V_11 , V_69 , V_1 , V_21 , V_20 , V_26 ) ;
break;
case V_70 :
V_11 = F_15 ( & V_18 , V_61 , V_12 , V_23 , V_1 , V_21 , V_20 , L_4 , V_16 ) ;
F_16 ( F_17 ( V_1 , V_21 , V_20 , V_20 ) , V_2 , V_11 ) ;
break;
default:
V_11 = F_14 ( & V_18 , V_61 , V_12 , V_71 , V_1 , V_21 , V_20 , FALSE ) ;
F_6 ( V_11 , V_71 , V_1 , V_21 , V_20 , V_32 ) ;
break;
}
V_17 = V_20 + V_21 ;
}
break;
case V_72 :
V_11 = F_15 ( & V_14 , V_24 , V_9 , V_23 , V_1 , V_5 , V_16 , L_5 , V_16 ) ;
V_10 = F_6 ( V_11 , V_73 , V_1 , V_5 , V_16 , V_26 ) ;
if ( V_74 ) {
F_18 ( V_10 , L_6 ) ;
} else {
F_18 ( V_10 , L_7 ) ;
}
break;
case V_75 :
V_11 = F_15 ( & V_14 , V_24 , V_9 , V_23 , V_1 , V_5 , V_16 , L_8 , V_16 ) ;
F_19 ( F_17 ( V_1 , V_5 , V_16 , V_16 ) , V_2 , V_11 ) ;
break;
case V_76 :
V_11 = F_15 ( & V_14 , V_24 , V_9 , V_23 , V_1 , V_5 , V_16 , L_9 , V_16 ) ;
F_19 ( F_17 ( V_1 , V_5 , V_16 , V_16 ) , V_2 , V_11 ) ;
break;
case V_77 :
V_11 = F_15 ( & V_14 , V_24 , V_9 , V_23 , V_1 , V_5 , V_16 , L_10 , V_16 ) ;
F_20 ( V_11 , V_1 , V_4 + 2 , V_16 ) ;
V_13 = TRUE ;
break;
case V_78 :
V_11 = F_15 ( & V_14 , V_24 , V_9 , V_23 , V_1 , V_5 , V_16 , L_11 , V_16 ) ;
F_21 ( V_11 , V_1 , V_4 + 2 , V_16 ) ;
break;
case V_79 :
case V_80 :
if ( ( ! V_74 && ( V_15 == V_79 ) ) ||
( V_74 && ( V_15 == V_80 ) ) ) {
V_11 = F_15 ( & V_14 , V_24 , V_9 , V_23 , V_1 , V_5 , V_16 , L_12 , V_16 ) ;
F_22 ( V_11 , V_1 , V_5 , V_16 ) ;
} else {
V_11 = F_14 ( & V_14 , V_61 , V_9 , V_71 , V_1 , V_5 , V_16 , FALSE ) ;
F_6 ( V_11 , V_71 , V_1 , V_5 , V_16 , V_32 ) ;
}
break;
case V_81 :
case V_82 :
case V_83 :
F_23 ( F_17 ( V_1 , V_4 , ( V_6 - V_4 ) , ( V_6 - V_4 ) ) , V_2 , V_9 ) ;
break;
default:
V_11 = F_14 ( & V_14 , V_61 , V_9 , V_71 , V_1 , V_5 , V_16 , FALSE ) ;
F_6 ( V_11 , V_71 , V_1 , V_5 , V_16 , V_32 ) ;
break;
}
V_4 = V_16 + V_5 ;
}
if ( ! V_13 )
F_18 ( V_9 , L_13 ) ;
}
}
void F_24 ( void )
{
static T_9 V_84 [] =
{
{
& V_25 ,
{
L_14 , L_15 ,
V_85 , V_86 , NULL , 0x0 , NULL , V_87
}
} ,
{
& V_31 ,
{
L_16 , L_17 ,
V_88 , V_89 , NULL , 0 , NULL , V_87
}
} ,
{
& V_67 ,
{
L_18 , L_19 ,
V_90 , V_86 , NULL , 0x0 , NULL , V_87
}
} ,
{
& V_27 ,
{
L_20 , L_21 ,
V_85 , V_91 , F_25 ( V_92 ) , 0x0 , NULL , V_87
}
} ,
{
& V_62 ,
{
L_22 , L_23 ,
V_90 , V_86 , NULL , 0x0 , NULL , V_87
}
} ,
{
& V_64 ,
{
L_24 , L_25 ,
V_85 , V_86 , NULL , 0x0 , NULL , V_87
}
} ,
{
& V_69 ,
{
L_26 , L_27 ,
V_93 , V_86 , NULL , 0x0 , NULL , V_87
}
} ,
{
& V_73 ,
{
L_28 , L_29 ,
V_90 , V_86 , NULL , 0x0 , NULL , V_87
}
} ,
{
& V_71 ,
{
L_30 , L_31 ,
V_88 , V_89 , NULL , 0x00 , NULL , V_87
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
static T_8 * V_94 [] =
{
& V_24 ,
& V_61
} ;
V_23 = V_95 ;
F_26 ( V_23 , V_84 , F_27 ( V_84 ) ) ;
F_28 ( V_94 , F_27 ( V_94 ) ) ;
}
