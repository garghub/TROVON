static T_1
F_1 ( T_1 V_1 , T_1 V_2 )
{
switch ( V_1 ) {
case V_3 :
return V_4 ;
break;
case V_5 :
if ( V_2 == 0 ) {
return V_6 ;
} else {
return V_7 ;
}
break;
case V_8 :
return V_9 ;
break;
case V_10 :
return V_11 ;
break;
case V_12 :
return V_11 ;
break;
case V_13 :
return V_11 ;
break;
case V_14 :
return V_11 ;
break;
case V_15 :
return V_11 ;
break;
case V_16 :
return V_11 ;
break;
case V_17 :
return V_11 ;
break;
case V_18 :
return V_11 ;
break;
case V_19 :
return V_20 ;
break;
case V_21 :
return V_20 ;
break;
case V_22 :
return V_23 ;
break;
default:
return V_24 ;
break;
}
}
static void
F_2 ( T_2 * V_25 , T_3 * V_26 , T_4 * V_27 )
{
T_1 V_1 ;
T_1 V_2 ;
T_5 V_28 ;
T_5 V_29 ;
T_5 V_30 ;
T_1 V_31 ;
T_6 V_32 ;
T_7 V_33 ;
const T_8 * V_34 ;
F_3 ( V_26 -> V_35 , V_36 , L_1 ) ;
F_4 ( V_26 -> V_35 , V_37 ) ;
V_33 = F_5 ( V_25 , 4 ) ;
V_28 = F_6 ( V_25 , 0 ) ;
V_2 = V_28 & 0x7F ;
V_1 = ( V_28 >> 7 ) & 0xF ;
V_31 = F_1 ( V_1 , V_2 ) ;
if ( V_2 == 0 ) {
V_34 = F_7 ( V_1 , V_38 , L_2 ) ;
F_8 ( V_26 -> V_35 , V_37 , L_3 , V_34 ) ;
} else {
V_34 = F_7 ( V_1 , V_39 , L_2 ) ;
F_8 ( V_26 -> V_35 , V_37 , L_4 , V_34 ) ;
}
F_9 ( V_26 -> V_35 , V_37 , L_5 ,
F_10 ( V_25 , V_40 , V_33 , ' ' ) ) ;
if ( V_27 ) {
T_9 * V_41 , * V_42 , * V_43 ;
T_4 * V_44 ;
T_4 * V_45 ;
T_4 * V_46 ;
V_41 = F_11 ( V_27 , V_47 , V_25 , 0 , - 1 , V_48 ) ;
V_44 = F_12 ( V_41 , V_49 ) ;
V_42 = F_11 ( V_44 , V_50 , V_25 , 0 , 4 , V_51 ) ;
V_45 = F_12 ( V_42 , V_49 ) ;
F_11 ( V_45 , V_52 , V_25 , 0 , 4 , V_51 ) ;
F_11 ( V_45 , V_53 , V_25 , 0 , 4 , V_51 ) ;
V_43 = F_13 ( V_44 , V_25 ,
( V_31 != V_6 ) ? 8 : 0 ,
( V_31 != V_6 ) ? - 1 : 0 ,
L_6 , V_34 ) ;
V_46 = F_12 ( V_43 , V_49 ) ;
switch( V_31 )
{
case V_4 :
F_11 ( V_46 ,
V_54 , V_25 , V_55 , 1 , V_51 ) ;
F_11 ( V_46 ,
V_56 , V_25 , V_57 , 1 , V_51 ) ;
break;
case V_23 :
F_11 ( V_46 ,
V_58 , V_25 , V_59 , 1 , V_51 ) ;
break;
case V_6 :
break;
case V_9 :
V_29 = F_14 ( V_25 , V_40 ) ;
V_30 = F_15 ( V_25 , V_40 + 4 ) ;
V_32 . V_60 = ( V_30 + V_61 )
* V_62 + ( V_29 / 1000 ) ;
V_32 . V_63 = ( V_29 % 1000 ) * V_64 ;
F_16 ( V_46 ,
V_65 , V_25 , V_66 , 6 , & V_32 ) ;
F_17 ( V_46 ,
V_67 , V_25 , V_66 , 4 , V_29 ) ;
F_17 ( V_46 ,
V_68 , V_25 , V_69 , 2 , V_30 ) ;
break;
case V_7 :
F_11 ( V_46 ,
V_70 , V_25 , V_71 , 2 , V_51 ) ;
F_11 ( V_46 ,
V_72 , V_25 , V_73 , 1 , V_51 ) ;
F_11 ( V_46 ,
V_74 , V_25 , V_75 , 4 , V_48 ) ;
break;
case V_11 :
if ( V_33 != 0 ) {
F_11 ( V_46 ,
V_76 , V_25 , V_40 , V_33 , V_48 ) ;
}
else {
F_18 ( V_46 ,
V_77 , V_25 , V_40 , 0 , L_7 ) ;
}
break;
case V_20 :
F_11 ( V_46 ,
V_78 , V_25 , V_79 , 1 , V_51 ) ;
F_11 ( V_46 ,
V_80 , V_25 , V_81 , 2 , V_51 ) ;
F_11 ( V_46 ,
V_82 , V_25 , V_83 , 1 , V_51 ) ;
F_11 ( V_46 ,
V_84 , V_25 , V_85 , 4 , V_48 ) ;
break;
}
}
}
void
F_19 ( void )
{
static T_10 V_86 [] = {
{ & V_50 ,
{ L_8 , L_9 ,
V_87 , V_88 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_52 ,
{ L_10 , L_11 ,
V_87 , V_88 , NULL , 0x780 ,
NULL , V_89 }
} ,
{ & V_53 ,
{ L_12 , L_13 ,
V_87 , V_88 , NULL , 0x7F ,
NULL , V_89 }
} ,
{ & V_76 ,
{ L_14 , L_15 ,
V_90 , V_91 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_77 ,
{ L_14 , L_15 ,
V_92 , V_91 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_78 ,
{ L_16 , L_17 ,
V_93 , V_88 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_80 ,
{ L_18 , L_19 ,
V_94 , V_88 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_82 ,
{ L_20 , L_21 ,
V_93 , V_88 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_84 ,
{ L_14 , L_22 ,
V_90 , V_91 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_70 ,
{ L_23 , L_24 ,
V_94 , V_88 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_72 ,
{ L_25 , L_26 ,
V_93 , V_88 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_74 ,
{ L_27 , L_28 ,
V_90 , V_91 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_54 ,
{ L_29 , L_30 ,
V_93 , V_88 , F_20 ( V_95 ) , 0xFF ,
NULL , V_89 }
} ,
{ & V_56 ,
{ L_12 , L_31 ,
V_93 , V_88 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_58 ,
{ L_12 , L_32 ,
V_93 , V_88 , F_20 ( V_96 ) , 0x7F ,
NULL , V_89 }
} ,
{ & V_65 ,
{ L_33 , L_34 ,
V_97 , V_98 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_67 ,
{ L_35 , L_36 ,
V_87 , V_99 , NULL , 0x0 ,
NULL , V_89 }
} ,
{ & V_68 ,
{ L_37 , L_38 ,
V_94 , V_99 , NULL , 0x0 ,
NULL , V_89 }
} ,
} ;
static T_7 * V_100 [] = {
& V_49
} ;
V_47 = F_21 ( L_1 ,
L_39 ,
L_40 ) ;
F_22 ( L_40 , F_2 , V_47 ) ;
F_23 ( V_47 , V_86 , F_24 ( V_86 ) ) ;
F_25 ( V_100 , F_24 ( V_100 ) ) ;
}
