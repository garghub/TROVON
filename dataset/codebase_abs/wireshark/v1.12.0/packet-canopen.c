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
static int
F_2 ( T_2 * V_25 , T_3 * V_26 , T_4 * V_27 , void * V_28 )
{
T_1 V_1 ;
T_1 V_2 ;
T_5 V_29 ;
T_5 V_30 ;
struct V_31 V_32 ;
T_1 V_33 ;
T_6 V_34 ;
T_7 V_35 = F_3 ( V_25 ) ;
const T_8 * V_36 ;
int V_37 = 0 ;
F_4 ( V_28 ) ;
V_32 = * ( (struct V_31 * ) V_28 ) ;
F_5 ( V_26 -> V_38 , V_39 , L_1 ) ;
F_6 ( V_26 -> V_38 , V_40 ) ;
V_2 = V_32 . V_41 & 0x7F ;
V_1 = ( V_32 . V_41 >> 7 ) & 0x0F ;
V_33 = F_1 ( V_1 , V_2 ) ;
if ( V_2 == 0 ) {
V_36 = F_7 ( V_1 , V_42 , L_2 ) ;
F_8 ( V_26 -> V_38 , V_40 , L_3 , V_36 ) ;
} else {
V_36 = F_7 ( V_1 , V_43 , L_2 ) ;
F_8 ( V_26 -> V_38 , V_40 , L_4 , V_36 ) ;
}
F_9 ( V_26 -> V_38 , V_40 , L_5 ,
F_10 ( V_25 , V_37 , V_35 , ' ' ) ) ;
if ( V_27 ) {
T_9 * V_44 , * V_45 , * V_46 ;
T_4 * V_47 ;
T_4 * V_48 ;
T_4 * V_49 ;
V_44 = F_11 ( V_27 , V_50 , V_25 , 0 , - 1 , V_51 ) ;
V_47 = F_12 ( V_44 , V_52 ) ;
V_45 = F_13 ( V_47 , V_53 , V_25 , 0 , 0 , V_32 . V_41 ) ;
V_48 = F_12 ( V_45 , V_52 ) ;
V_44 = F_13 ( V_48 , V_54 , V_25 , 0 , 0 , V_32 . V_41 ) ;
F_14 ( V_44 ) ;
V_44 = F_13 ( V_48 , V_55 , V_25 , 0 , 0 , V_32 . V_41 ) ;
F_14 ( V_44 ) ;
V_46 = F_15 ( V_47 , V_25 , 0 ,
( V_33 != V_6 ) ? - 1 : 0 ,
L_6 , V_36 ) ;
V_49 = F_12 ( V_46 , V_52 ) ;
switch( V_33 )
{
case V_4 :
F_11 ( V_49 ,
V_56 , V_25 , V_37 , 1 , V_57 ) ;
V_37 ++ ;
F_11 ( V_49 ,
V_58 , V_25 , V_37 , 1 , V_57 ) ;
break;
case V_23 :
F_11 ( V_49 ,
V_59 , V_25 , V_37 , 1 , V_57 ) ;
break;
case V_6 :
break;
case V_9 :
V_29 = F_16 ( V_25 , V_37 ) ;
V_30 = F_17 ( V_25 , V_37 + 4 ) ;
V_34 . V_60 = ( V_30 + V_61 )
* V_62 + ( V_29 / 1000 ) ;
V_34 . V_63 = ( V_29 % 1000 ) * V_64 ;
F_18 ( V_49 ,
V_65 , V_25 , V_37 , 6 , & V_34 ) ;
F_13 ( V_49 ,
V_66 , V_25 , V_37 , 4 , V_29 ) ;
V_37 += 2 ;
F_13 ( V_49 ,
V_67 , V_25 , V_37 , 2 , V_30 ) ;
break;
case V_7 :
F_11 ( V_49 ,
V_68 , V_25 , V_37 , 2 , V_57 ) ;
V_37 += 2 ;
F_11 ( V_49 ,
V_69 , V_25 , V_37 , 1 , V_57 ) ;
V_37 ++ ;
F_11 ( V_49 ,
V_70 , V_25 , V_37 , 4 , V_51 ) ;
break;
case V_11 :
if ( V_35 != 0 ) {
F_11 ( V_49 ,
V_71 , V_25 , V_37 , V_35 , V_51 ) ;
}
else {
F_19 ( V_49 ,
V_72 , V_25 , V_37 , 0 , L_7 ) ;
}
break;
case V_20 :
F_11 ( V_49 ,
V_73 , V_25 , V_37 , 1 , V_57 ) ;
V_37 ++ ;
F_11 ( V_49 ,
V_74 , V_25 , V_37 , 2 , V_57 ) ;
V_37 += 2 ;
F_11 ( V_49 ,
V_75 , V_25 , V_37 , 1 , V_57 ) ;
V_37 ++ ;
F_11 ( V_49 ,
V_76 , V_25 , V_37 , 4 , V_51 ) ;
break;
}
}
return F_20 ( V_25 ) ;
}
void
F_21 ( void )
{
static T_10 V_77 [] = {
{ & V_53 ,
{ L_8 , L_9 ,
V_78 , V_79 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_54 ,
{ L_10 , L_11 ,
V_78 , V_79 , NULL , 0x780 ,
NULL , V_80 }
} ,
{ & V_55 ,
{ L_12 , L_13 ,
V_78 , V_79 , NULL , 0x7F ,
NULL , V_80 }
} ,
{ & V_71 ,
{ L_14 , L_15 ,
V_81 , V_82 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_72 ,
{ L_14 , L_15 ,
V_83 , V_82 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_73 ,
{ L_16 , L_17 ,
V_84 , V_79 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_74 ,
{ L_18 , L_19 ,
V_85 , V_79 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_75 ,
{ L_20 , L_21 ,
V_84 , V_79 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_76 ,
{ L_14 , L_22 ,
V_81 , V_82 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_68 ,
{ L_23 , L_24 ,
V_85 , V_79 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_69 ,
{ L_25 , L_26 ,
V_84 , V_79 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_70 ,
{ L_27 , L_28 ,
V_81 , V_82 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_56 ,
{ L_29 , L_30 ,
V_84 , V_79 , F_22 ( V_86 ) , 0xFF ,
NULL , V_80 }
} ,
{ & V_58 ,
{ L_12 , L_31 ,
V_84 , V_79 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_59 ,
{ L_12 , L_32 ,
V_84 , V_79 , F_22 ( V_87 ) , 0x7F ,
NULL , V_80 }
} ,
{ & V_65 ,
{ L_33 , L_34 ,
V_88 , V_89 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_66 ,
{ L_35 , L_36 ,
V_78 , V_90 , NULL , 0x0 ,
NULL , V_80 }
} ,
{ & V_67 ,
{ L_37 , L_38 ,
V_85 , V_90 , NULL , 0x0 ,
NULL , V_80 }
} ,
} ;
static T_7 * V_91 [] = {
& V_52
} ;
V_50 = F_23 ( L_1 ,
L_39 ,
L_40 ) ;
F_24 ( L_40 , F_2 , V_50 ) ;
F_25 ( V_50 , V_77 , F_26 ( V_77 ) ) ;
F_27 ( V_91 , F_26 ( V_91 ) ) ;
}
