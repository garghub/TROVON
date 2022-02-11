static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 ;
T_3 * V_7 = NULL , * V_8 ;
T_4 * V_9 ;
T_1 * V_10 ;
int V_11 ;
T_5 V_12 ;
T_6 V_13 ;
T_7 V_14 ;
T_7 V_15 ;
T_7 V_16 ;
T_8 V_17 ;
T_9 V_18 ;
T_5 V_19 ;
F_2 ( V_2 -> V_20 , V_21 , L_1 ) ;
F_3 ( V_2 -> V_20 , V_22 ) ;
V_11 = 0 ;
V_12 = F_4 ( V_1 , V_11 ) ;
V_13 = F_5 ( V_1 , V_11 + 1 ) ;
F_6 ( V_2 -> V_20 , V_22 , L_2 ,
V_12 , V_13 ) ;
if ( V_12 != 2 ) {
goto V_23;
}
if ( V_13 < V_24 ) {
goto V_23;
}
V_9 = F_7 ( V_3 , V_25 , V_1 , 0 , V_13 ,
V_26 ) ;
V_7 = F_8 ( V_9 , V_27 ) ;
F_7 ( V_7 , V_28 , V_1 , V_11 , 1 ,
V_29 ) ;
V_11 += 1 ;
F_7 ( V_7 , V_30 , V_1 , V_11 , 2 ,
V_29 ) ;
V_11 += 2 ;
V_9 = F_7 ( V_7 , V_31 , V_1 , V_11 ,
4 , V_29 ) ;
V_8 = F_8 ( V_9 , V_32 ) ;
F_7 ( V_8 , V_33 , V_1 , V_11 ,
4 , V_29 ) ;
F_7 ( V_8 , V_34 , V_1 , V_11 ,
4 , V_29 ) ;
F_7 ( V_8 , V_35 , V_1 ,
V_11 , 4 , V_29 ) ;
F_7 ( V_8 , V_36 , V_1 , V_11 ,
4 , V_29 ) ;
V_11 += 4 ;
V_15 = F_9 ( V_1 , V_11 ) ;
V_11 += 4 ;
if ( V_15 != 0xffffffff ) {
V_14 = F_9 ( V_1 , V_11 ) ;
memset ( & V_6 -> V_37 , 0 , sizeof( V_6 -> V_37 ) ) ;
switch ( V_14 ) {
case V_38 :
V_6 -> V_39 = V_40 ;
break;
case V_41 :
V_6 -> V_39 = V_42 ;
break;
case V_43 :
V_6 -> V_39 = V_44 ;
break;
case V_45 :
V_6 -> V_39 = V_46 ;
break;
case V_47 :
V_6 -> V_39 = V_48 ;
break;
case V_49 :
V_6 -> V_39 = V_50 ;
break;
case V_51 :
V_6 -> V_39 = V_52 ;
break;
case V_53 :
V_6 -> V_39 = V_54 ;
break;
case V_55 :
V_6 -> V_39 = V_56 ;
break;
default:
V_6 -> V_39 = V_40 ;
break;
}
F_7 ( V_7 , V_57 , V_1 , V_11 , 4 ,
V_29 ) ;
V_11 += 4 ;
V_16 = F_9 ( V_1 , V_11 ) ;
if ( V_16 < 1000 ) {
if ( V_16 == 0 ) {
F_10 ( V_7 , V_58 ,
V_1 , V_11 , 4 , V_16 ,
L_3 ) ;
} else {
T_10 V_59 ;
V_6 -> V_60 = TRUE ;
V_6 -> V_16 = V_16 ;
F_11 ( V_7 , V_58 ,
V_1 , V_11 , 4 , V_16 ) ;
switch ( V_6 -> V_39 ) {
case V_48 :
case V_52 :
V_59 = F_12 ( V_16 , TRUE ) ;
break;
case V_50 :
V_59 = F_12 ( V_16 , FALSE ) ;
break;
default:
V_59 = 0 ;
break;
}
if ( V_59 != 0 ) {
V_6 -> V_61 = TRUE ;
V_6 -> V_59 = V_59 ;
}
}
} else {
V_6 -> V_61 = TRUE ;
V_6 -> V_59 = V_16 ;
F_10 ( V_7 , V_62 ,
V_1 , V_11 , 4 , V_16 ,
L_4 , V_16 ) ;
V_17 = F_13 ( V_16 ) ;
if ( V_17 != - 1 ) {
V_6 -> V_60 = TRUE ;
V_6 -> V_16 = V_17 ;
}
}
V_11 += 4 ;
V_18 = F_9 ( V_1 , V_11 ) ;
if ( V_18 == 0 ) {
F_14 ( V_7 , V_63 ,
V_1 , V_11 , 4 , V_18 ,
L_3 ) ;
} else {
V_6 -> V_64 = TRUE ;
V_6 -> V_65 = V_18 ;
F_14 ( V_7 , V_63 ,
V_1 , V_11 , 4 , V_18 ,
L_5 , V_18 ) ;
}
V_11 += 4 ;
V_19 = F_4 ( V_1 , V_11 ) ;
if ( V_19 == 0 ) {
F_10 ( V_7 , V_66 ,
V_1 , V_11 , 1 , V_19 ,
L_3 ) ;
} else {
V_6 -> V_67 = TRUE ;
V_6 -> V_68 = V_19 ;
F_10 ( V_7 , V_66 ,
V_1 , V_11 , 1 , V_19 ,
L_6 , V_19 * .5 ) ;
}
V_11 += 1 ;
} else
V_11 += 13 ;
V_6 -> V_69 = TRUE ;
V_6 -> V_70 = F_15 ( V_1 , V_11 ) ;
F_7 ( V_7 , V_71 , V_1 , V_11 , 8 ,
V_29 ) ;
V_23:
V_11 = V_13 ;
V_10 = F_16 ( V_1 , V_11 ) ;
F_17 ( V_72 , V_10 , V_2 , V_3 , V_6 ) ;
return V_11 ;
}
void
F_18 ( void )
{
static const T_11 V_14 [] = {
{ V_38 , L_3 } ,
{ V_41 , L_7 } ,
{ V_45 , L_8 } ,
{ V_43 , L_9 } ,
{ V_49 , L_10 } ,
{ V_47 , L_11 } ,
{ V_51 , L_12 } ,
{ V_53 , L_13 } ,
{ V_55 , L_14 } ,
{ 0 , NULL } ,
} ;
static T_12 V_73 [] = {
{ & V_28 , { L_15 , L_16 , V_74 ,
V_75 , NULL , 0x0 , NULL , V_76 } } ,
{ & V_30 , { L_17 , L_18 , V_77 ,
V_75 , NULL , 0x0 , NULL , V_76 } } ,
{ & V_31 , { L_19 , L_20 , V_78 ,
V_79 , NULL , 0x0 , NULL , V_76 } } ,
{ & V_33 , { L_21 , L_22 , V_78 ,
V_79 , NULL , V_80 , NULL , V_76 } } ,
{ & V_34 , { L_23 , L_24 , V_78 ,
V_79 , NULL , V_81 , NULL , V_76 } } ,
{ & V_35 , { L_25 , L_26 , V_78 ,
V_79 , NULL , V_82 , NULL , V_76 } } ,
{ & V_36 , { L_27 , L_28 , V_78 ,
V_79 , NULL , V_83 , NULL , V_76 } } ,
#if 0
{ &hf_netmon_802_11_flags, { "Flags", "netmon_802_11.flags", FT_UINT32,
BASE_HEX, NULL, 0x0, NULL, HFILL } },
#endif
{ & V_57 , { L_29 , L_30 , V_78 ,
V_75 , F_19 ( V_14 ) , 0x0 , NULL , V_76 } } ,
{ & V_58 , { L_31 , L_32 , V_78 ,
V_75 , NULL , 0x0 , NULL , V_76 } } ,
{ & V_62 , { L_33 , L_34 , V_78 ,
V_75 , NULL , 0x0 , NULL , V_76 } } ,
{ & V_63 , { L_35 , L_36 , V_84 ,
V_75 , NULL , 0x0 , NULL , V_76 } } ,
{ & V_66 , { L_37 , L_38 , V_78 ,
V_75 , NULL , 0x0 , NULL , V_76 } } ,
{ & V_71 , { L_39 , L_40 , V_85 ,
V_75 , NULL , 0x0 , NULL , V_76 } } ,
} ;
static T_8 * V_86 [] = {
& V_27 ,
& V_32
} ;
V_25 = F_20 ( L_41 ,
L_42 ,
L_43 ) ;
F_21 ( V_25 , V_73 , F_22 ( V_73 ) ) ;
F_23 ( V_86 , F_22 ( V_86 ) ) ;
}
void
F_24 ( void )
{
T_13 V_87 ;
V_72 = F_25 ( L_44 , V_25 ) ;
V_87 = F_26 ( F_1 ,
V_25 ) ;
F_27 ( L_45 , V_88 , V_87 ) ;
}
