static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_3 * V_5 , * V_6 ;
T_5 * V_7 , * V_8 ;
int V_9 ;
int V_10 ;
T_6 V_11 , V_12 ;
T_7 V_13 ;
T_1 * V_14 ;
F_2 ( V_2 -> V_15 , V_16 , L_1 ) ;
F_3 ( V_2 -> V_15 , V_17 ) ;
V_11 = F_4 ( V_1 , 0 ) ;
F_5 ( V_2 -> V_15 , V_18 , L_2 , V_11 ) ;
V_12 = F_4 ( V_1 , 1 ) ;
if ( ( ( V_11 & 0x01 ) != 0x00 ) && ( ( V_12 & 0x01 ) != 0x01 ) )
{
F_2 ( V_2 -> V_15 , V_17 , L_3 ) ;
if ( V_3 )
F_6 ( V_3 , V_19 , V_1 , 0 , - 1 ,
L_3 ) ;
return 2 ;
}
if ( V_2 -> V_20 == V_21 ) {
V_9 = ( V_11 & 0x02 ) ? FALSE : TRUE ;
F_2 ( V_2 -> V_15 , V_22 , L_4 ) ;
F_2 ( V_2 -> V_15 , V_18 , L_5 ) ;
} else {
V_9 = ( V_11 & 0x02 ) ? TRUE : FALSE ;
F_2 ( V_2 -> V_15 , V_22 , L_5 ) ;
F_2 ( V_2 -> V_15 , V_18 , L_4 ) ;
}
V_7 = F_6 ( V_3 , V_19 , V_1 , 0 , - 1 , L_1 ) ;
V_5 = F_7 ( V_7 , V_23 ) ;
V_8 = F_8 ( V_5 , V_24 , V_1 , 0 , 2 , V_25 ) ;
F_9 ( V_8 , L_6 ,
( ( V_11 & 0xfc ) << 5 ) | ( ( V_12 & 0xfe ) >> 1 ) ,
V_11 & 0x02 ? L_7 : L_8 ) ;
V_6 = F_7 ( V_8 , V_26 ) ;
F_8 ( V_6 , V_27 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_6 , V_28 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_6 , V_29 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_6 , V_30 , V_1 , 0 , 2 , V_25 ) ;
V_13 = F_10 ( V_1 , 2 , V_2 , V_5 , V_31 ,
V_32 , & V_33 , & V_34 ,
NULL , NULL , V_9 , TRUE , FALSE ) ;
V_10 = 2 + F_11 ( V_13 , TRUE ) ;
if ( F_12 ( V_1 , V_10 , 1 ) )
V_10 += F_13 ( V_1 , V_10 , V_5 ) ;
F_14 ( V_7 , V_10 ) ;
V_14 = F_15 ( V_1 , V_10 ) ;
F_16 ( V_14 , V_2 , V_5 ) ;
return F_17 ( V_1 ) ;
}
static int
F_13 ( T_1 * V_1 , int V_35 , T_3 * V_3 )
{
int V_36 ;
T_6 V_11 ;
T_3 * V_37 ;
T_5 * V_8 ;
V_11 = F_4 ( V_1 , V_35 ) ;
if ( V_11 & 0x80 ) {
V_36 = 1 ;
V_8 = F_8 ( V_3 , V_38 , V_1 , 0 , 1 , V_25 ) ;
V_37 = F_7 ( V_8 , V_39 ) ;
F_8 ( V_37 , V_40 , V_1 , 0 , 1 , V_41 ) ;
F_8 ( V_37 , V_42 , V_1 , 0 , 1 , V_41 ) ;
F_8 ( V_37 , V_43 , V_1 , 0 , 1 , V_25 ) ;
F_8 ( V_37 , V_44 , V_1 , 0 , 1 , V_41 ) ;
F_8 ( V_37 , V_45 , V_1 , 0 , 1 , V_41 ) ;
} else {
V_36 = 2 ;
V_8 = F_8 ( V_3 , V_46 , V_1 , 0 , 2 , V_25 ) ;
V_37 = F_7 ( V_8 , V_39 ) ;
F_8 ( V_37 , V_47 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_37 , V_48 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_37 , V_49 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_37 , V_50 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_37 , V_51 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_37 , V_52 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_37 , V_53 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_37 , V_54 , V_1 , 0 , 2 , V_25 ) ;
F_8 ( V_37 , V_55 , V_1 , 0 , 2 , V_25 ) ;
}
F_9 ( V_8 , L_9 ,
V_11 & 0x02 ? 1 : 0 , V_11 & 0x01 ? 1 : 0 ) ;
return V_36 ;
}
void
F_18 ( void )
{
static T_8 V_56 [] = {
{ & V_24 ,
{ L_10 , L_11 , V_57 , V_58 , NULL ,
0x0 , NULL , V_59 } } ,
{ & V_27 ,
{ L_12 , L_13 , V_60 , 16 , F_19 ( & V_61 ) ,
0x0002 , NULL , V_59 } } ,
{ & V_28 ,
{ L_14 , L_15 , V_57 , V_58 , NULL ,
0xfefc , NULL , V_59 } } ,
{ & V_29 ,
{ L_16 , L_17 , V_60 , 16 , F_19 ( & V_62 ) ,
0x0001 , NULL , V_59 } } ,
{ & V_30 ,
{ L_18 , L_19 , V_60 , 16 , F_19 ( & V_63 ) ,
0x0100 , NULL , V_59 } } ,
{ & V_31 ,
{ L_20 , L_21 , V_57 , V_58 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_64 ,
{ L_22 , L_23 , V_57 , V_65 ,
NULL , V_66 , NULL , V_59 } } ,
{ & V_67 ,
{ L_24 , L_25 , V_57 , V_65 ,
NULL , V_68 , NULL , V_59 } } ,
{ & V_69 ,
{ L_26 , L_27 , V_60 , 8 ,
F_19 ( & V_70 ) , V_71 , NULL , V_59 } } ,
{ & V_72 ,
{ L_26 , L_27 , V_60 , 16 ,
F_19 ( & V_70 ) , V_73 , NULL , V_59 } } ,
{ & V_74 ,
{ L_28 , L_29 , V_60 , 8 ,
F_19 ( & V_70 ) , V_71 , NULL , V_59 } } ,
{ & V_75 ,
{ L_28 , L_29 , V_60 , 16 ,
F_19 ( & V_70 ) , V_73 , NULL , V_59 } } ,
{ & V_76 ,
{ L_30 , L_31 , V_57 , V_58 ,
F_20 ( V_77 ) , V_78 , NULL , V_59 } } ,
{ & V_79 ,
{ L_32 , L_33 , V_80 , V_58 ,
F_20 ( V_81 ) , V_82 , NULL , V_59 } } ,
{ & V_83 ,
{ L_34 , L_35 , V_80 , V_58 ,
F_20 ( V_84 ) , V_82 , NULL , V_59 } } ,
{ & V_85 ,
{ L_36 , L_37 , V_57 , V_58 ,
F_20 ( V_86 ) , V_87 , NULL , V_59 } } ,
{ & V_88 ,
{ L_36 , L_37 , V_80 , V_58 ,
F_20 ( V_86 ) , V_89 , NULL , V_59 } } ,
{ & V_90 ,
{ L_36 , L_37 , V_57 , V_58 ,
F_20 ( V_86 ) , V_89 , NULL , V_59 } } ,
{ & V_38 ,
{ L_38 , L_39 , V_80 , V_58 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_40 ,
{ L_40 , L_41 , V_60 , 8 , F_19 ( & V_91 ) , 0x80 ,
NULL , V_59 } } ,
{ & V_42 ,
{ L_42 , L_43 , V_60 , 8 , F_19 ( & V_91 ) , 0x40 ,
NULL , V_59 } } ,
{ & V_43 ,
{ L_44 , L_45 , V_80 , V_58 , NULL , 0x0C ,
NULL , V_59 } } ,
{ & V_44 ,
{ L_46 , L_47 , V_60 , 8 , F_19 ( & V_92 ) , 0x02 ,
NULL , V_59 } } ,
{ & V_45 ,
{ L_48 , L_49 , V_60 , 8 , F_19 ( & V_92 ) , 0x01 ,
NULL , V_59 } } ,
{ & V_46 ,
{ L_38 , L_39 , V_57 , V_58 , NULL , 0x0 ,
NULL , V_59 } } ,
{ & V_47 ,
{ L_40 , L_41 , V_60 , 16 , F_19 ( & V_91 ) , 0x80 ,
NULL , V_59 } } ,
{ & V_48 ,
{ L_42 , L_43 , V_60 , 16 , F_19 ( & V_91 ) , 0x40 ,
NULL , V_59 } } ,
{ & V_49 ,
{ L_44 , L_45 , V_57 , V_58 , NULL , 0x0C ,
NULL , V_59 } } ,
{ & V_50 ,
{ L_46 , L_47 , V_60 , 16 , F_19 ( & V_92 ) , 0x02 ,
NULL , V_59 } } ,
{ & V_51 ,
{ L_48 , L_49 , V_60 , 16 , F_19 ( & V_92 ) , 0x01 ,
NULL , V_59 } } ,
{ & V_52 ,
{ L_50 , L_51 , V_60 , 16 , F_19 ( & V_91 ) , 0x8000 ,
NULL , V_59 } } ,
{ & V_53 ,
{ L_52 , L_53 , V_60 , 16 , F_19 ( & V_91 ) , 0x4000 ,
NULL , V_59 } } ,
{ & V_54 ,
{ L_54 , L_55 , V_60 , 16 , F_19 ( & V_91 ) , 0x2000 ,
NULL , V_59 } } ,
{ & V_55 ,
{ L_56 , L_57 , V_60 , 16 , F_19 ( & V_91 ) , 0x1000 ,
NULL , V_59 } } ,
} ;
static T_9 * V_93 [] = {
& V_23 ,
& V_26 ,
& V_32 ,
& V_39 ,
} ;
V_19 = F_21 ( L_58 ,
L_1 , L_59 ) ;
F_22 ( V_19 , V_56 , F_23 ( V_56 ) ) ;
F_24 ( V_93 , F_23 ( V_93 ) ) ;
F_25 ( L_59 , F_1 , V_19 ) ;
}
