static T_1 F_1 ( T_2 * T_3 V_1 , T_4 * V_2 , T_1 V_3 , T_5 * V_4 ) {
T_6 V_5 , V_6 , V_7 , V_8 , V_9 ;
T_1 V_10 , V_11 , V_12 ;
T_7 V_13 ;
T_8 V_14 , V_15 ;
T_9 * V_16 , * V_17 , * V_18 ;
T_5 * V_19 , * V_20 , * V_21 ;
const T_10 * V_22 ;
V_5 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_23 , V_2 , V_3 , 1 , V_24 ) ;
V_3 ++ ;
if ( V_5 == 0 )
return V_3 ;
V_10 = V_3 ;
V_6 = V_5 / 2 + 1 ;
V_18 = F_3 ( V_4 , V_25 , V_2 , V_3 , V_6 , V_24 ) ;
V_19 = F_4 ( V_18 , V_26 ) ;
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
V_8 = F_2 ( V_2 , V_3 + V_7 / 2 ) ;
F_5 ( V_19 , V_27 , V_2 , V_3 + V_7 / 2 , 1 ,
( V_8 & ( 0x08 << 4 * ( V_7 % 2 ) ) ) , L_1 ,
V_7 , ( V_8 & ( 0x08 << 4 * ( V_7 % 2 ) ) ) ? L_2 : L_3 ) ;
F_6 ( V_19 , V_28 , V_2 , V_3 + V_7 / 2 , 1 ,
( V_8 & ( 0x07 << 4 * ( V_7 % 2 ) ) ) , L_4 ,
V_7 , ( V_8 & ( 0x07 << 4 * ( V_7 % 2 ) ) ) ) ;
}
V_8 = F_2 ( V_2 , V_3 + V_5 / 2 ) ;
F_7 ( V_19 , V_29 , V_2 , V_3 + V_5 / 2 , 1 , ( V_8 & ( 0x01 << 4 * ( V_5 % 2 ) ) ) ) ;
V_15 = V_8 & ( 0x01 << 4 * ( V_5 % 2 ) ) ;
V_3 += V_6 ;
V_11 = V_3 ;
V_16 = F_8 ( V_4 , V_2 , V_3 , 0 , L_5 ) ;
V_20 = F_4 ( V_16 , V_30 ) ;
for ( V_7 = 0 ; V_7 < V_5 ; V_7 ++ ) {
V_8 = F_2 ( V_2 , V_10 + V_7 / 2 ) ;
V_14 = V_8 & ( 0x08 << 4 * ( V_7 % 2 ) ) ;
V_12 = V_3 ;
V_17 = F_8 ( V_20 , V_2 , V_3 , 0 , L_6 , V_7 ) ;
V_21 = F_4 ( V_17 , V_31 ) ;
V_9 = F_2 ( V_2 , V_3 ) ;
F_9 ( V_21 , V_32 , V_2 , V_3 , 1 , V_9 ) ;
F_10 ( V_17 , L_7 , V_9 ) ;
V_3 ++ ;
if ( ! V_14 )
continue;
if ( V_15 ) {
V_13 = F_11 ( V_2 , V_3 ) ;
F_9 ( V_21 , V_33 , V_2 , V_3 , 2 , V_13 ) ;
V_3 += 2 ;
}
else {
V_13 = F_2 ( V_2 , V_3 ) ;
F_9 ( V_21 , V_34 , V_2 , V_3 , 1 , V_13 ) ;
V_3 ++ ;
}
V_22 = F_12 ( F_13 () , V_2 , V_3 , V_13 ) ;
F_3 ( V_21 , V_35 , V_2 , V_3 , V_13 , V_24 | V_36 ) ;
F_10 ( V_17 , L_8 , V_22 ) ;
V_3 += V_13 ;
F_14 ( V_17 , V_3 - V_12 ) ;
}
F_14 ( V_16 , V_3 - V_11 ) ;
return V_3 ;
}
static T_1 F_15 ( T_8 V_37 , T_2 * T_3 , T_4 * V_2 , T_1 V_3 , T_5 * V_4 , T_10 * * T_11 V_1 ) {
T_7 V_38 , V_7 ;
if ( V_37 ) {
V_38 = F_16 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_39 , V_2 , V_3 , 4 , V_40 ) ;
V_3 += 4 ;
} else {
V_38 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_41 , V_2 , V_3 , 1 , V_40 ) ;
V_3 ++ ;
}
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
V_3 = F_17 ( NULL , T_3 , V_2 , V_3 , V_4 ) ;
}
return V_3 ;
}
static T_1 F_18 ( T_6 V_42 , T_2 * T_3 , T_4 * V_2 , T_1 V_3 , T_5 * V_4 , T_10 * * T_11 ) {
T_12 V_43 , V_44 , V_7 ;
T_7 V_45 ;
switch ( V_42 ) {
case V_46 :
V_3 = F_1 ( T_3 , V_2 , V_3 , V_4 ) ;
break;
case V_47 :
V_44 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_48 , V_2 , V_3 , 1 , V_40 ) ;
V_3 += 1 ;
if ( T_11 )
* T_11 = F_19 ( F_13 () , L_9 , V_44 ) ;
break;
case V_49 :
V_44 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_50 , V_2 , V_3 , 1 , V_40 ) ;
V_3 += 1 ;
if ( T_11 )
* T_11 = F_19 ( F_13 () , L_9 , V_44 ) ;
break;
case V_51 :
V_44 = F_16 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_52 , V_2 , V_3 , 4 , V_40 ) ;
V_3 += 4 ;
if ( T_11 )
* T_11 = F_19 ( F_13 () , L_9 , V_44 ) ;
break;
case V_53 :
V_3 = F_17 ( L_10 , T_3 , V_2 , V_3 , V_4 ) ;
F_3 ( V_4 , V_54 , V_2 , V_3 , 4 , V_40 ) ;
V_3 += 4 ;
F_3 ( V_4 , V_55 , V_2 , V_3 , 4 , V_40 ) ;
V_3 += 4 ;
F_3 ( V_4 , V_56 , V_2 , V_3 , 1 , V_40 ) ;
V_3 ++ ;
break;
case V_57 :
V_3 = F_15 ( FALSE , T_3 , V_2 , V_3 , V_4 , T_11 ) ;
break;
case V_58 :
V_3 = F_15 ( TRUE , T_3 , V_2 , V_3 , V_4 , T_11 ) ;
break;
case V_59 :
break;
case V_60 :
V_43 = F_16 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_61 , V_2 , V_3 , 4 , V_40 ) ;
V_3 += 4 ;
for ( V_7 = 0 ; V_7 < V_43 ; V_7 ++ ) {
V_3 = F_17 ( NULL , T_3 , V_2 , V_3 , V_4 ) ;
}
V_3 = F_17 ( L_11 , T_3 , V_2 , V_3 , V_4 ) ;
break;
case V_62 :
V_43 = F_11 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_63 , V_2 , V_3 , 2 , V_40 ) ;
V_3 += 2 ;
V_3 = F_17 ( L_10 , T_3 , V_2 , V_3 , V_4 ) ;
F_3 ( V_4 , V_64 , V_2 , V_3 , 1 , V_40 ) ;
V_3 ++ ;
for ( V_7 = 0 ; V_7 < V_43 ; V_7 ++ ) {
V_45 = F_16 ( V_2 , V_3 ) ;
F_6 ( V_4 , V_65 , V_2 , V_3 , 4 ,
V_45 , L_12 , V_7 , V_45 ) ;
V_3 += 4 ;
}
break;
}
return V_3 ;
}
static T_1 F_20 ( T_4 * V_2 , T_2 * T_3 , T_5 * V_4 , const T_10 * V_66 ) {
T_1 V_3 = 0 ;
T_6 V_67 , V_42 ;
T_9 * V_68 ;
T_5 * V_69 ;
V_67 = F_2 ( V_2 , V_3 ) ;
if ( V_67 != V_70 ) {
return 0 ;
}
V_68 = F_8 ( V_4 , V_2 , V_3 , - 1 , L_13 , ( V_66 ) ? V_66 : L_14 ) ;
V_69 = F_4 ( V_68 , V_71 ) ;
F_8 ( V_69 , V_2 , V_3 , 1 , L_15 , V_67 ) ;
V_3 ++ ;
V_42 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_69 , V_72 , V_2 , V_3 , 1 , V_40 ) ;
V_3 ++ ;
if ( ! V_66 )
F_21 ( V_68 , L_13 , F_22 ( V_42 , F_23 ( V_73 ) , L_16 ) ) ;
V_3 = F_18 ( V_42 , T_3 , V_2 , V_3 , V_69 , NULL ) ;
F_14 ( V_68 , V_3 ) ;
return V_3 ;
}
static T_1 F_17 ( const T_10 * V_66 , T_2 * T_3 , T_4 * V_2 , T_1 V_3 , T_5 * V_4 ) {
T_1 V_74 = V_3 ;
T_6 V_42 ;
T_9 * V_68 ;
T_5 * V_69 ;
T_10 * T_11 = NULL ;
V_68 = F_8 ( V_4 , V_2 , V_3 , - 1 , L_13 , ( V_66 ) ? V_66 : L_14 ) ;
V_69 = F_4 ( V_68 , V_71 ) ;
V_42 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_69 , V_72 , V_2 , V_3 , 1 , V_40 ) ;
V_3 ++ ;
if ( ! V_66 )
F_21 ( V_68 , L_13 , F_22 ( V_42 , F_23 ( V_73 ) , L_16 ) ) ;
V_3 = F_18 ( V_42 , T_3 , V_2 , V_3 , V_69 , & T_11 ) ;
if ( T_11 )
F_10 ( V_68 , L_17 , T_11 ) ;
F_14 ( V_68 , V_3 - V_74 ) ;
return V_3 ;
}
static T_8 F_24 ( T_4 * V_2 , int V_3 ) {
T_7 V_43 = F_11 ( V_2 , V_3 ) ;
T_6 V_42 = F_2 ( V_2 , V_3 + 2 ) ;
return ( ( V_43 > 0 ) && strchr ( L_18 , V_42 ) && ( V_43 == ( T_7 ) F_25 ( V_2 , V_3 + 2 ) ) ) ;
}
static void F_26 ( T_4 * V_2 , T_2 * T_3 , T_5 * V_4 ) {
T_1 V_3 = 0 ;
T_6 V_42 ;
T_1 V_7 ;
T_8 V_75 = FALSE ;
T_7 V_76 ;
const T_10 * V_22 ;
F_3 ( V_4 , V_77 , V_2 , V_3 , 2 , V_40 ) ;
V_3 += 2 ;
V_42 = F_2 ( V_2 , V_3 ) ;
F_3 ( V_4 , V_78 , V_2 , V_3 , 1 , V_36 | V_24 ) ;
V_3 ++ ;
switch ( V_42 ) {
case 'n' :
F_3 ( V_4 , V_79 , V_2 , V_3 , 2 , V_40 ) ;
V_3 += 2 ;
F_3 ( V_4 , V_80 , V_2 , V_3 , 4 , V_40 ) ;
V_3 += 4 ;
if ( F_27 ( V_2 , V_3 , 4 ) ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
if( ! F_28 ( F_2 ( V_2 , V_3 + V_7 ) ) ) {
V_75 = TRUE ;
break;
}
}
if ( V_75 ) {
F_3 ( V_4 , V_81 , V_2 , V_3 , 4 , V_40 ) ;
V_3 += 4 ;
}
V_76 = F_25 ( V_2 , V_3 ) ;
V_22 = F_12 ( F_13 () , V_2 , V_3 , V_76 ) ;
F_3 ( V_4 , V_82 , V_2 , V_3 , V_76 , V_36 | V_24 ) ;
F_29 ( T_3 -> V_83 , V_84 , L_19 , ( V_75 ) ? L_20 : L_21 , V_22 ) ;
break;
case 'r' :
F_3 ( V_4 , V_81 , V_2 , V_3 , 4 , V_40 ) ;
V_3 += 4 ;
F_3 ( V_4 , V_85 , V_2 , V_3 , 16 , V_24 ) ;
F_30 ( T_3 -> V_83 , V_84 , L_22 ) ;
break;
case 'a' :
F_3 ( V_4 , V_85 , V_2 , V_3 , 16 , V_24 ) ;
F_30 ( T_3 -> V_83 , V_84 , L_23 ) ;
break;
case 's' :
V_76 = F_25 ( V_2 , V_3 ) ;
V_22 = F_12 ( F_13 () , V_2 , V_3 , V_76 ) ;
F_3 ( V_4 , V_86 , V_2 , V_3 , V_76 , V_36 | V_24 ) ;
F_29 ( T_3 -> V_83 , V_84 , L_24 , V_22 ) ;
break;
}
}
static int F_31 ( T_4 * V_2 , T_2 * T_3 , T_5 * V_4 , void * T_13 V_1 ) {
T_1 V_3 ;
T_7 V_87 ;
T_6 type , V_88 ;
T_5 * V_89 ;
T_9 * V_68 ;
T_4 * V_90 = NULL ;
F_30 ( T_3 -> V_83 , V_91 , V_92 ) ;
V_68 = F_3 ( V_4 , V_93 , V_2 , 0 , - 1 , V_24 ) ;
V_89 = F_4 ( V_68 , V_94 ) ;
if ( F_24 ( V_2 , 0 ) ) {
F_26 ( V_2 , T_3 , V_89 ) ;
return F_32 ( V_2 ) ;
}
V_3 = 0 ;
V_87 = F_16 ( V_2 , V_3 ) ;
F_3 ( V_89 , V_95 , V_2 , V_3 , 4 , V_40 ) ;
V_3 += 4 ;
if ( V_87 == 0 ) {
F_30 ( T_3 -> V_83 , V_84 , L_25 ) ;
return V_3 ;
}
type = F_2 ( V_2 , V_3 ) ;
switch ( type ) {
case V_96 :
F_3 ( V_89 , V_97 , V_2 , V_3 , 1 , V_40 ) ;
V_3 ++ ;
break;
case V_70 :
V_90 = F_33 ( V_2 , V_3 , - 1 , 4 + V_87 - V_3 ) ;
V_3 += F_20 ( V_90 , T_3 , V_89 , L_26 ) ;
if ( ( F_2 ( V_2 , V_3 ) == V_57 ) && ( F_2 ( V_2 , V_3 + 2 ) == V_49 ) ) {
V_88 = F_2 ( V_2 , V_3 + 3 ) ;
F_34 ( T_3 -> V_83 , V_84 , F_22 ( V_88 , F_23 ( V_98 ) , L_27 ) ) ;
}
V_3 = F_17 ( L_28 , T_3 , V_2 , V_3 , V_89 ) ;
if ( F_25 ( V_2 , V_3 ) > 0 )
F_17 ( L_29 , T_3 , V_2 , V_3 , V_89 ) ;
break;
default:
F_3 ( V_89 , V_97 , V_2 , V_3 , 1 , V_40 ) ;
V_3 ++ ;
F_30 ( T_3 -> V_83 , V_84 , L_30 ) ;
}
return F_32 ( V_2 ) ;
}
static T_14 F_35 ( T_2 * T_3 V_1 , T_4 * V_2 , int V_3 ) {
if ( F_24 ( V_2 , V_3 ) )
return ( 2 + F_11 ( V_2 , V_3 ) ) ;
return ( 4 + F_16 ( V_2 , V_3 ) ) ;
}
static int
F_36 ( T_4 * V_2 , T_2 * T_3 , T_5 * V_4 , void * T_13 ) {
F_37 ( V_2 , T_3 , V_4 ,
V_99 ,
4 ,
F_35 ,
F_31 , T_13 ) ;
return F_32 ( V_2 ) ;
}
void F_38 ( void ) {
static T_15 V_100 [] = {
{ & V_77 , { L_31 , L_32 ,
V_101 , V_102 , NULL , 0x0 ,
L_33 , V_103 } } ,
{ & V_78 , { L_34 , L_35 ,
V_104 , V_105 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_97 , { L_36 , L_37 ,
V_106 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_79 , { L_38 , L_39 ,
V_101 , V_102 , F_23 ( V_107 ) , 0x0 ,
NULL , V_103 } } ,
{ & V_80 , { L_40 , L_41 ,
V_108 , V_109 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_81 , { L_42 , L_43 ,
V_108 , V_109 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_85 , { L_44 , L_45 ,
V_110 , V_105 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_82 , { L_46 , L_47 ,
V_104 , V_105 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_86 , { L_48 , L_49 ,
V_104 , V_105 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_23 , { L_50 , L_51 ,
V_106 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_25 , { L_40 , L_52 ,
V_110 , V_105 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_32 , { L_53 , L_54 ,
V_106 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_34 , { L_31 , L_55 ,
V_106 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_33 , { L_31 , L_55 ,
V_101 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_35 , { L_56 , L_57 ,
V_104 , V_105 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_48 , { L_58 , L_59 ,
V_106 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_50 , { L_60 , L_61 ,
V_111 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_52 , { L_60 , L_62 ,
V_112 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_54 , { L_63 , L_64 ,
V_108 , V_109 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_55 , { L_65 , L_66 ,
V_108 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_56 , { L_67 , L_68 ,
V_106 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_61 , { L_69 , L_70 ,
V_108 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_63 , { L_69 , L_71 ,
V_101 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_64 , { L_67 , L_72 ,
V_106 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_65 , { L_63 , L_73 ,
V_108 , V_109 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_95 , { L_31 , L_32 ,
V_108 , V_102 , NULL , 0x0 ,
L_33 , V_103 } } ,
{ & V_72 , { L_34 , L_74 ,
V_106 , V_102 , F_23 ( V_73 ) , 0x0 ,
NULL , V_103 } } ,
{ & V_27 , { L_75 , L_76 ,
V_113 , 8 , F_39 ( & V_114 ) , 0x08 ,
NULL , V_103 } } ,
{ & V_28 , { L_77 , L_78 ,
V_106 , V_102 , NULL , 0x7 ,
NULL , V_103 } } ,
{ & V_29 , { L_79 , L_76 ,
V_113 , 8 , F_39 ( & V_115 ) , 0x12 ,
NULL , V_103 } } ,
{ & V_39 , { L_80 , L_81 ,
V_108 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
{ & V_41 , { L_80 , L_81 ,
V_106 , V_102 , NULL , 0x0 ,
NULL , V_103 } } ,
} ;
static T_1 * V_116 [] = {
& V_94 ,
& V_71 ,
& V_26 ,
& V_30 ,
& V_31 ,
& V_117 ,
} ;
V_93 = F_40 ( V_118 , V_92 , V_119 ) ;
V_120 = F_41 ( V_119 , F_36 , V_93 ) ;
F_42 ( V_93 , V_100 , F_43 ( V_100 ) ) ;
F_44 ( V_116 , F_43 ( V_116 ) ) ;
}
void F_45 ( void ) {
F_46 ( L_82 , V_120 ) ;
}
