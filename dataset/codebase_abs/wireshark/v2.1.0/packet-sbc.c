static T_1
F_1 ( T_2 * V_1 , T_3 * V_2 , T_4 * V_3 , void * V_4 )
{
T_5 * V_5 ;
T_4 * V_6 ;
T_5 * V_7 ;
T_4 * V_8 ;
T_1 V_9 = 0 ;
T_6 V_10 ;
T_6 V_11 ;
T_6 V_12 ;
T_6 V_13 ;
T_6 V_14 ;
T_6 V_15 ;
T_6 V_16 ;
T_7 V_17 ;
T_6 V_18 ;
T_1 V_19 ;
T_6 V_20 ;
T_1 V_21 ;
T_1 V_22 = 1 ;
T_1 V_23 ;
T_1 V_24 ;
T_8 V_25 ;
T_8 V_26 = 0 ;
T_9 * V_27 ;
F_2 ( V_2 -> V_28 , V_29 , L_1 ) ;
V_27 = ( T_9 * ) V_4 ;
V_5 = F_3 ( V_3 , V_30 , V_1 , V_9 , - 1 , V_31 ) ;
V_6 = F_4 ( V_5 , V_32 ) ;
F_3 ( V_6 , V_33 , V_1 , V_9 , 1 , V_34 ) ;
F_3 ( V_6 , V_35 , V_1 , V_9 , 1 , V_34 ) ;
F_3 ( V_6 , V_36 , V_1 , V_9 , 1 , V_34 ) ;
F_3 ( V_6 , V_37 , V_1 , V_9 , 1 , V_34 ) ;
F_3 ( V_6 , V_38 , V_1 , V_9 , 1 , V_34 ) ;
V_10 = F_5 ( V_1 , V_9 ) & 0x0F ;
V_9 += 1 ;
while ( F_6 ( V_1 , V_9 ) > 0 ) {
V_12 = F_5 ( V_1 , V_9 + 1 ) ;
V_17 = ( V_12 & 0xC0 ) >> 6 ;
V_13 = ( V_12 & 0x30 ) >> 4 ;
V_14 = ( V_12 & 0x0C ) >> 2 ;
V_15 = V_12 & 0x01 ;
V_16 = F_5 ( V_1 , V_9 + 2 ) ;
if ( V_14 == V_39 )
V_19 = 1 ;
else
V_19 = 2 ;
switch ( V_17 ) {
case V_40 :
V_17 = 16000 ;
break;
case V_41 :
V_17 = 32000 ;
break;
case V_42 :
V_17 = 44100 ;
break;
case V_43 :
V_17 = 48000 ;
break;
default:
V_17 = 0 ;
}
V_20 = 4 * ( V_15 + 1 ) ;
V_18 = 4 * ( V_13 + 1 ) ;
V_23 = ( 4 * V_20 * V_19 ) / 8 ;
if ( V_19 == 1 )
V_21 = V_18 * V_19 * V_16 ;
else
V_21 = ( ( ( V_14 == V_44 ) ? 1 : 0 ) * V_20 + V_18 * V_16 ) ;
V_23 += V_21 / 8 ;
if ( V_21 % 8 )
V_23 += 1 ;
V_24 = ( V_23 * V_17 ) / ( V_20 * V_18 ) ;
V_8 = F_7 ( V_6 , V_1 , V_9 , 4 + V_23 ,
V_45 , NULL , L_2 , V_22 , V_10 ) ;
V_7 = F_3 ( V_8 , V_46 , V_1 , V_9 , 1 , V_34 ) ;
V_11 = F_5 ( V_1 , V_9 ) ;
if ( V_11 != 0x9C ) {
F_8 ( V_2 , V_7 , & V_47 ) ;
}
V_9 += 1 ;
F_3 ( V_8 , V_48 , V_1 , V_9 , 1 , V_34 ) ;
F_3 ( V_8 , V_49 , V_1 , V_9 , 1 , V_34 ) ;
F_3 ( V_8 , V_50 , V_1 , V_9 , 1 , V_34 ) ;
F_3 ( V_8 , V_51 , V_1 , V_9 , 1 , V_34 ) ;
F_3 ( V_8 , V_52 , V_1 , V_9 , 1 , V_34 ) ;
V_9 += 1 ;
F_3 ( V_8 , V_53 , V_1 , V_9 , 1 , V_34 ) ;
V_9 += 1 ;
F_3 ( V_8 , V_54 , V_1 , V_9 , 1 , V_34 ) ;
V_9 += 1 ;
F_3 ( V_8 , V_55 , V_1 , V_9 , V_23 , V_31 ) ;
V_9 += V_23 ;
V_7 = F_9 ( V_8 , V_56 , V_1 , V_9 , 0 , V_24 / 1024 ) ;
F_10 ( V_7 , L_3 ) ;
F_11 ( V_7 ) ;
V_25 = ( ( ( double ) V_23 / ( double ) V_24 ) * 1000.0 ) ;
V_26 += V_25 ;
V_7 = F_12 ( V_8 , V_57 , V_1 , V_9 , 0 , V_25 ) ;
F_10 ( V_7 , L_4 ) ;
F_11 ( V_7 ) ;
V_22 += 1 ;
}
V_7 = F_12 ( V_6 , V_58 , V_1 , V_9 , 0 , V_26 ) ;
F_10 ( V_7 , L_4 ) ;
F_11 ( V_7 ) ;
if ( V_27 && V_27 -> V_59 && V_27 -> V_60 > 0 ) {
}
if ( V_27 && V_27 -> V_61 && V_27 -> V_62 ) {
T_10 V_63 ;
F_13 ( & V_63 , & V_2 -> V_64 , & V_27 -> V_61 -> V_64 ) ;
V_7 = F_12 ( V_6 , V_65 , V_1 , V_9 , 0 , F_14 ( & V_63 ) ) ;
F_10 ( V_7 , L_4 ) ;
F_11 ( V_7 ) ;
V_7 = F_12 ( V_6 , V_66 , V_1 , V_9 , 0 , V_27 -> V_61 -> V_67 ) ;
F_10 ( V_7 , L_4 ) ;
F_11 ( V_7 ) ;
F_13 ( & V_63 , & V_2 -> V_64 , & V_27 -> V_61 -> V_68 ) ;
V_7 = F_12 ( V_6 , V_69 , V_1 , V_9 , 0 , F_14 ( & V_63 ) ) ;
F_10 ( V_7 , L_4 ) ;
F_11 ( V_7 ) ;
if ( ! V_2 -> V_70 -> V_71 . V_72 ) {
V_27 -> V_62 -> V_26 += V_26 ;
V_27 -> V_62 -> V_67 += V_26 ;
}
V_7 = F_12 ( V_6 , V_73 , V_1 , V_9 , 0 , V_27 -> V_61 -> V_26 ) ;
F_10 ( V_7 , L_4 ) ;
F_11 ( V_7 ) ;
V_7 = F_12 ( V_6 , V_74 , V_1 , V_9 , 0 , V_27 -> V_61 -> V_26 - F_14 ( & V_63 ) ) ;
F_10 ( V_7 , L_4 ) ;
F_11 ( V_7 ) ;
}
F_15 ( V_2 -> V_28 , V_75 , L_5 , V_10 ) ;
return V_9 ;
}
void
F_16 ( void )
{
T_11 * V_76 ;
T_12 * V_77 ;
static T_13 V_78 [] = {
{ & V_33 ,
{ L_6 , L_7 ,
V_79 , 8 , NULL , 0x80 ,
NULL , V_80 }
} ,
{ & V_35 ,
{ L_8 , L_9 ,
V_79 , 8 , NULL , 0x40 ,
NULL , V_80 }
} ,
{ & V_36 ,
{ L_10 , L_11 ,
V_79 , 8 , NULL , 0x20 ,
NULL , V_80 }
} ,
{ & V_37 ,
{ L_12 , L_13 ,
V_79 , 8 , NULL , 0x10 ,
NULL , V_80 }
} ,
{ & V_38 ,
{ L_14 , L_15 ,
V_81 , V_82 , NULL , 0x0F ,
NULL , V_80 }
} ,
{ & V_46 ,
{ L_16 , L_17 ,
V_81 , V_83 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_48 ,
{ L_18 , L_19 ,
V_81 , V_83 , F_17 ( V_84 ) , 0xC0 ,
NULL , V_80 }
} ,
{ & V_49 ,
{ L_20 , L_21 ,
V_81 , V_83 , F_17 ( V_85 ) , 0x30 ,
NULL , V_80 }
} ,
{ & V_50 ,
{ L_22 , L_23 ,
V_81 , V_83 , F_17 ( V_86 ) , 0x0C ,
NULL , V_80 }
} ,
{ & V_51 ,
{ L_24 , L_25 ,
V_81 , V_83 , F_17 ( V_87 ) , 0x02 ,
NULL , V_80 }
} ,
{ & V_52 ,
{ L_26 , L_27 ,
V_81 , V_83 , F_17 ( V_88 ) , 0x01 ,
NULL , V_80 }
} ,
{ & V_53 ,
{ L_28 , L_29 ,
V_81 , V_82 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_54 ,
{ L_30 , L_31 ,
V_81 , V_83 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_56 ,
{ L_32 , L_33 ,
V_89 , V_82 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_57 ,
{ L_34 , L_35 ,
V_90 , V_91 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_58 ,
{ L_36 , L_37 ,
V_90 , V_91 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_65 ,
{ L_38 , L_39 ,
V_90 , V_91 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_69 ,
{ L_40 , L_41 ,
V_90 , V_91 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_73 ,
{ L_42 , L_43 ,
V_90 , V_91 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_66 ,
{ L_44 , L_45 ,
V_90 , V_91 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_74 ,
{ L_46 , L_47 ,
V_90 , V_91 , NULL , 0x00 ,
NULL , V_80 }
} ,
{ & V_55 ,
{ L_48 , L_49 ,
V_92 , V_91 , NULL , 0x00 ,
NULL , V_80 }
} ,
} ;
static T_1 * V_93 [] = {
& V_32 ,
& V_45 ,
} ;
static T_14 V_94 [] = {
{ & V_47 , { L_50 , V_95 , V_96 , L_51 , V_97 } } ,
} ;
V_30 = F_18 ( L_52 , L_1 , L_53 ) ;
F_19 ( V_30 , V_78 , F_20 ( V_78 ) ) ;
F_21 ( V_93 , F_20 ( V_93 ) ) ;
V_77 = F_22 ( V_30 ) ;
F_23 ( V_77 , V_94 , F_20 ( V_94 ) ) ;
F_24 ( L_53 , F_1 , V_30 ) ;
V_76 = F_25 ( V_30 , NULL ) ;
F_26 ( V_76 , L_54 ,
L_55 ,
L_56 ) ;
}
