static void F_1 ( void )
{
F_2 ( & V_1 ,
& V_2 ) ;
}
static void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
void F_5 ( T_1 * V_3 ,
T_2 * V_4 , int V_5 ,
int V_6 ,
const T_3 * V_7 , T_4 V_8 )
{
T_2 V_9 ;
T_5 * V_10 ;
T_6 * V_11 = NULL ;
if ( ( V_3 -> V_12 -> V_13 . V_14 ) || ( V_15 == NULL ) )
{
return;
}
F_6 ( & V_9 , V_16 , 0 , NULL ) ;
V_10 = F_7 ( V_8 , V_4 , & V_9 , V_17 , V_5 , V_6 ,
V_18 | ( ! V_6 ? V_19 : 0 ) ) ;
if ( ! V_10 || V_10 -> V_20 != V_8 ) {
V_10 = F_8 ( V_8 , V_4 , & V_9 , V_17 ,
( T_4 ) V_5 , ( T_4 ) V_6 ,
V_21 | ( ! V_6 ? V_22 : 0 ) ) ;
}
F_9 ( V_10 , V_15 ) ;
V_11 = ( T_6 * ) F_10 ( V_10 , V_23 ) ;
if ( ! V_11 ) {
V_11 = F_11 ( F_12 () , T_6 ) ;
F_13 ( V_10 , V_23 , V_11 ) ;
}
F_14 ( V_11 -> V_7 , V_7 , V_24 ) ;
V_11 -> V_8 = V_8 ;
V_11 -> V_25 . V_26 = 0 ;
V_11 -> V_25 . V_27 = - 1 ;
V_11 -> V_25 . V_28 = 0 ;
V_11 -> V_25 . V_29 = - 1 ;
V_11 -> V_25 . V_30 = 0 ;
V_11 -> V_25 . V_31 = 0 ;
V_11 -> V_25 . V_32 = 0 ;
V_11 -> V_25 . V_33 = 0 ;
V_11 -> V_25 . V_34 = - 1 ;
V_11 -> V_35 . V_26 = 0 ;
V_11 -> V_35 . V_27 = - 1 ;
V_11 -> V_35 . V_28 = 0 ;
V_11 -> V_35 . V_29 = - 1 ;
V_11 -> V_35 . V_30 = 0 ;
V_11 -> V_35 . V_31 = 0 ;
V_11 -> V_35 . V_32 = 0 ;
V_11 -> V_35 . V_33 = 0 ;
V_11 -> V_35 . V_34 = - 1 ;
}
static T_7 *
F_15 ( T_8 * V_36 , T_1 * V_3 , T_4 V_37 )
{
T_7 * V_38 ;
T_9 * V_39 ;
T_9 * V_40 ;
T_4 V_41 , V_42 , V_30 , V_31 , V_43 ;
T_10 * V_44 ;
V_38 = F_16 ( V_36 , V_3 , V_37 , NULL ) ;
if ( V_3 -> V_12 -> V_13 . V_14 ) {
if ( V_38 != NULL && V_38 -> V_13 & V_45 ) {
return V_38 ;
} else {
return NULL ;
}
}
if ( V_38 == NULL ) {
return NULL ;
}
V_30 = 0 ;
V_31 = 0 ;
V_43 = 0 ;
for( V_39 = V_38 -> V_46 ; V_39 ; V_39 = V_39 -> V_46 ) {
if ( V_43 != V_39 -> V_47 ) {
V_30 += V_39 -> V_47 - V_43 ;
if ( ( V_39 -> V_47 - V_43 ) > V_31 ) {
V_31 = V_39 -> V_47 - V_43 ;
}
}
V_43 = V_39 -> V_47 + 1 ;
}
V_42 = 0 ;
V_40 = NULL ;
for( V_39 = V_38 -> V_46 ; V_39 ; V_39 = V_39 -> V_46 ) {
if( ! V_40 || V_40 -> V_47 != V_39 -> V_47 ) {
V_42 += V_39 -> V_48 ;
}
V_40 = V_39 ;
}
V_44 = ( T_10 * ) F_17 ( V_42 ) ;
V_38 -> V_49 = F_18 ( V_44 , V_42 , V_42 ) ;
V_38 -> V_48 = V_42 ;
V_41 = 0 ;
V_40 = NULL ;
for ( V_39 = V_38 -> V_46 ; V_39 && V_39 -> V_48 + V_41 <= V_42 ; V_39 = V_39 -> V_46 ) {
if ( V_39 -> V_48 ) {
if( ! V_40 || V_40 -> V_47 != V_39 -> V_47 ) {
F_19 ( V_39 -> V_49 , V_44 + V_41 , 0 , V_39 -> V_48 ) ;
V_41 += V_39 -> V_48 ;
} else {
V_39 -> V_13 |= V_50 ;
V_38 -> V_13 |= V_50 ;
if( ( V_40 -> V_48 != V_39 -> V_48 )
|| F_20 ( V_40 -> V_49 , 0 , F_21 ( V_39 -> V_49 , 0 , V_40 -> V_48 ) , V_40 -> V_48 ) ) {
V_39 -> V_13 |= V_51 ;
V_38 -> V_13 |= V_51 ;
}
}
}
V_40 = V_39 ;
}
for ( V_39 = V_38 -> V_46 ; V_39 ; V_39 = V_39 -> V_46 ) {
if( V_39 -> V_49 ) {
F_22 ( V_39 -> V_49 ) ;
V_39 -> V_49 = NULL ;
}
}
V_38 -> V_13 |= V_45 ;
V_38 -> V_52 = V_3 -> V_12 -> V_53 ;
F_23 ( V_3 -> V_54 , V_55 , L_1 , V_30 , V_31 ) ;
V_56 -> V_30 = V_30 ;
V_56 -> V_31 = V_31 ;
return V_38 ;
}
static int
F_24 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_25 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
16 , & V_58 , TRUE , 7 , NULL ) ;
#line 29 "../../asn1/t38/t38.cnf"
if ( V_59 ) {
F_23 ( T_14 -> V_3 -> V_54 , V_55 , L_2 ,
F_26 ( V_58 , V_60 , L_3 ) ) ;
}
if ( V_59 )
V_61 -> V_62 = V_58 ;
return V_47 ;
}
static int
F_27 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_25 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
9 , & V_63 , TRUE , 6 , NULL ) ;
#line 41 "../../asn1/t38/t38.cnf"
if ( V_59 ) {
F_23 ( T_14 -> V_3 -> V_54 , V_55 , L_4 ,
F_26 ( V_63 , V_64 , L_3 ) ) ;
}
if ( V_59 )
V_61 -> V_65 = V_63 ;
return V_47 ;
}
static int
F_28 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_29 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_66 , V_67 ,
& V_68 ) ;
#line 22 "../../asn1/t38/t38.cnf"
if ( V_59 )
V_61 -> V_69 = V_68 ;
return V_47 ;
}
static int
F_30 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_25 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
8 , & V_70 , ( V_71 ) ? FALSE : TRUE , ( V_71 ) ? 0 : 4 , NULL ) ;
#line 61 "../../asn1/t38/t38.cnf"
if ( V_59 ) {
F_23 ( T_14 -> V_3 -> V_54 , V_55 , L_5 ,
F_26 ( V_70 , V_72 , L_3 ) ) ;
}
if ( V_59 && ( V_73 < 2 ) ) {
if ( V_70 == 2 || V_70 == 4 || V_70 == 7 ) {
T_7 * V_74 = NULL ;
T_11 * V_75 = NULL ;
T_18 V_76 = T_14 -> V_3 -> V_77 ;
T_14 -> V_3 -> V_77 = TRUE ;
if ( V_56 -> V_27 != - 1 ) {
V_74 = F_31 ( & V_1 ,
T_12 , V_47 , T_14 -> V_3 ,
V_56 -> V_26 ,
NULL ,
V_78 + V_73 - ( T_4 ) V_56 -> V_27 + ( T_4 ) V_56 -> V_33 ,
0 ,
FALSE ,
0 ) ;
if ( V_70 == 7 ) {
if ( ! V_74 ) {
F_15 ( & V_1 ,
T_14 -> V_3 ,
V_56 -> V_26
) ;
} else {
F_32 ( T_14 -> V_3 -> V_54 , V_55 , L_6 ) ;
F_33 ( V_61 -> V_79 , V_80 , L_7 ) ;
}
if ( V_56 -> V_30 ) {
F_33 ( V_61 -> V_79 , V_80 , L_8 , V_56 -> V_30 , V_56 -> V_31 ) ;
} else {
F_33 ( V_61 -> V_79 , V_80 , L_7 ) ;
}
F_34 ( T_12 , V_47 , T_14 -> V_3 ,
L_9 , V_74 , & V_81 , NULL , T_16 ) ;
T_14 -> V_3 -> V_77 = V_76 ;
V_61 -> V_32 = V_56 -> V_32 ;
V_61 -> V_82 = V_56 -> V_26 ;
} else {
V_75 = F_34 ( T_12 , V_47 , T_14 -> V_3 ,
L_9 , V_74 , & V_81 , NULL , T_16 ) ;
T_14 -> V_3 -> V_77 = V_76 ;
if ( V_75 ) F_35 ( ( V_83 ) ? V_83 : V_84 , V_75 , T_14 -> V_3 , T_16 , V_61 ) ;
}
} else {
F_36 ( T_16 , T_14 -> V_3 , & V_85 , T_12 , V_47 , F_37 ( T_12 , V_47 ) ,
L_10 ) ;
F_32 ( T_14 -> V_3 -> V_54 , V_55 , L_11 ) ;
T_14 -> V_3 -> V_77 = V_76 ;
}
}
if ( V_86 && ( ( ( V_70 > 0 ) && ( V_70 < 6 ) ) || ( V_70 == 7 ) ) ) {
V_87 -> V_26 = 0 ;
V_87 -> V_27 = - 1 ;
V_87 -> V_33 = 0 ;
V_87 -> V_34 = - 1 ;
}
V_61 -> V_70 = V_70 ;
}
return V_47 ;
}
static int
F_38 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
#line 151 "../../asn1/t38/t38.cnf"
T_11 * V_88 = NULL ;
T_4 V_89 ;
V_47 = F_39 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
1 , 65535 , FALSE , & V_88 ) ;
V_89 = F_40 ( V_88 ) ;
#line 158 "../../asn1/t38/t38.cnf"
if ( V_59 ) {
if( V_89 < 8 ) {
F_23 ( T_14 -> V_3 -> V_54 , V_55 , L_12 ,
F_41 ( F_42 () , V_88 , 0 , V_89 ) ) ;
}
else {
F_23 ( T_14 -> V_3 -> V_54 , V_55 , L_13 ,
F_41 ( F_42 () , V_88 , 0 , 7 ) ) ;
}
}
if ( V_59 && ( V_73 < 2 ) ) {
T_7 * V_74 = NULL ;
if ( V_70 == 0 || V_70 == 6 ) {
T_18 V_76 = T_14 -> V_3 -> V_77 ;
T_14 -> V_3 -> V_77 = TRUE ;
if ( V_90 && V_86 && ( V_56 -> V_26 == 0 ) ) {
V_87 -> V_26 = T_14 -> V_3 -> V_12 -> V_53 ;
V_87 -> V_27 = V_78 ;
V_87 -> V_32 = F_43 ( & T_14 -> V_3 -> V_91 ) ;
V_87 -> V_33 = 0 ;
V_56 -> V_26 = V_87 -> V_26 ;
V_56 -> V_27 = V_87 -> V_27 ;
V_56 -> V_34 = V_87 -> V_34 ;
V_56 -> V_33 = V_87 -> V_33 ;
V_56 -> V_32 = V_87 -> V_32 ;
}
if ( V_78 == ( T_4 ) V_56 -> V_34 ) {
V_56 -> V_33 ++ ;
if( V_86 ) {
V_87 -> V_33 = V_56 -> V_33 ;
}
}
V_74 = F_31 ( & V_1 ,
V_88 , 0 ,
T_14 -> V_3 ,
V_56 -> V_26 ,
NULL ,
V_78 - ( T_4 ) V_56 -> V_27 + ( T_4 ) V_56 -> V_33 ,
V_89 ,
TRUE ,
0 ) ;
V_56 -> V_34 = ( V_92 ) V_78 ;
F_34 ( T_12 , V_47 , T_14 -> V_3 ,
L_9 , V_74 , & V_81 , NULL , T_16 ) ;
if ( ! V_74 ) {
if ( V_70 == 0 ) {
F_23 ( T_14 -> V_3 -> V_54 , V_55 , L_14 ,
V_78 + ( T_4 ) V_56 -> V_33
- ( T_4 ) V_56 -> V_27 ) ;
} else {
F_23 ( T_14 -> V_3 -> V_54 , V_55 , L_15 , V_78 - ( T_4 ) V_56 -> V_27 ) ;
}
}
T_14 -> V_3 -> V_77 = V_76 ;
}
}
return V_47 ;
}
static int
F_44 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_45 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_93 , V_94 ) ;
#line 53 "../../asn1/t38/t38.cnf"
if ( V_59 ) V_73 ++ ;
return V_47 ;
}
static int
F_46 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_47 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_95 , V_96 ) ;
return V_47 ;
}
static int
F_48 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_45 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_97 , V_98 ) ;
return V_47 ;
}
static int
F_49 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_50 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
0U , 65535U , & V_78 , FALSE ) ;
#line 238 "../../asn1/t38/t38.cnf"
if ( V_59 )
V_61 -> V_43 = V_78 ;
F_23 ( T_14 -> V_3 -> V_54 , V_55 , L_16 , V_78 ) ;
return V_47 ;
}
static int
F_51 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
#line 246 "../../asn1/t38/t38.cnf"
V_59 = TRUE ;
V_47 = F_52 ( T_12 , V_47 , T_14 , T_16 , T_17 , F_48 ) ;
#line 248 "../../asn1/t38/t38.cnf"
if ( V_90 && ( ! T_14 -> V_3 -> V_13 . V_99 ) && ( ( V_92 ) V_78 != V_56 -> V_29 ) &&
! ( V_61 -> V_69 == 1 && V_61 -> V_70 == 7 && V_61 -> V_82 == 0 ) )
F_53 ( V_100 , T_14 -> V_3 , V_61 ) ;
if ( V_86 ) V_87 -> V_29 = ( V_92 ) V_78 ;
return V_47 ;
}
static int
F_54 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_52 ( T_12 , V_47 , T_14 , T_16 , T_17 , F_48 ) ;
return V_47 ;
}
static int
F_55 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_47 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_101 , V_102 ) ;
return V_47 ;
}
static int
F_56 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_57 ( T_12 , V_47 , T_14 , T_16 , T_17 , NULL ) ;
return V_47 ;
}
static int
F_58 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_39 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_103 , V_103 , FALSE , NULL ) ;
return V_47 ;
}
static int
F_59 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_47 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_104 , V_105 ) ;
return V_47 ;
}
static int
F_60 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
V_47 = F_45 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_106 , V_107 ) ;
return V_47 ;
}
static int
F_61 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
#line 258 "../../asn1/t38/t38.cnf"
V_59 = FALSE ;
V_47 = F_29 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_108 , V_109 ,
NULL ) ;
#line 260 "../../asn1/t38/t38.cnf"
V_59 = TRUE ;
return V_47 ;
}
static int
F_62 ( T_11 * T_12 V_57 , int V_47 V_57 , T_13 * T_14 V_57 , T_15 * T_16 V_57 , int T_17 V_57 ) {
#line 232 "../../asn1/t38/t38.cnf"
V_70 = 1 ;
V_47 = F_45 ( T_12 , V_47 , T_14 , T_16 , T_17 ,
V_110 , V_111 ) ;
return V_47 ;
}
static int F_63 ( T_11 * T_12 V_57 , T_1 * V_3 V_57 , T_15 * T_16 V_57 , void * V_44 V_57 ) {
int V_47 = 0 ;
T_13 V_112 ;
F_64 ( & V_112 , V_113 , TRUE , V_3 ) ;
V_47 = F_48 ( T_12 , V_47 , & V_112 , T_16 , V_114 ) ;
V_47 += 7 ; V_47 >>= 3 ;
return V_47 ;
}
static int F_65 ( T_11 * T_12 V_57 , T_1 * V_3 V_57 , T_15 * T_16 V_57 , void * V_44 V_57 ) {
int V_47 = 0 ;
T_13 V_112 ;
F_64 ( & V_112 , V_113 , TRUE , V_3 ) ;
V_47 = F_62 ( T_12 , V_47 , & V_112 , T_16 , V_115 ) ;
V_47 += 7 ; V_47 >>= 3 ;
return V_47 ;
}
static void
F_66 ( T_1 * V_3 )
{
V_116 ++ ;
if ( V_116 == V_117 ) {
V_116 = 0 ;
}
V_61 = & V_118 [ V_116 ] ;
V_61 -> V_43 = 0 ;
V_61 -> V_69 = 0 ;
V_61 -> V_65 = 0 ;
V_61 -> V_62 = 0 ;
V_61 -> V_8 = 0 ;
V_61 -> V_70 = 0 ;
V_61 -> V_119 [ 0 ] = '\0' ;
V_61 -> V_79 [ 0 ] = '\0' ;
V_61 -> V_32 = 0 ;
V_61 -> V_82 = 0 ;
V_90 = NULL ;
V_86 = NULL ;
V_90 = ( T_6 * ) F_67 ( F_12 () , V_3 , V_23 , 0 ) ;
V_120 = F_7 ( V_3 -> V_12 -> V_53 , & V_3 -> V_121 , & V_3 -> V_122 ,
V_3 -> V_123 ,
V_3 -> V_124 , V_3 -> V_125 , V_18 | V_19 ) ;
if ( ! V_120 ) {
V_120 = F_8 ( V_3 -> V_12 -> V_53 , & V_3 -> V_122 , & V_3 -> V_121 ,
V_3 -> V_123 , V_3 -> V_125 , V_3 -> V_124 , V_18 | V_19 ) ;
F_9 ( V_120 , V_15 ) ;
}
V_86 = ( T_6 * ) F_10 ( V_120 , V_23 ) ;
if ( ! V_86 ) {
V_86 = F_11 ( F_12 () , T_6 ) ;
V_86 -> V_7 [ 0 ] = '\0' ;
V_86 -> V_8 = 0 ;
V_86 -> V_25 . V_26 = 0 ;
V_86 -> V_25 . V_27 = - 1 ;
V_86 -> V_25 . V_28 = 0 ;
V_86 -> V_25 . V_29 = - 1 ;
V_86 -> V_25 . V_30 = 0 ;
V_86 -> V_25 . V_31 = 0 ;
V_86 -> V_25 . V_32 = 0 ;
V_86 -> V_25 . V_33 = 0 ;
V_86 -> V_25 . V_34 = - 1 ;
V_86 -> V_35 . V_26 = 0 ;
V_86 -> V_35 . V_27 = - 1 ;
V_86 -> V_35 . V_28 = 0 ;
V_86 -> V_35 . V_29 = - 1 ;
V_86 -> V_35 . V_30 = 0 ;
V_86 -> V_35 . V_31 = 0 ;
V_86 -> V_35 . V_32 = 0 ;
V_86 -> V_35 . V_33 = 0 ;
V_86 -> V_35 . V_34 = - 1 ;
F_13 ( V_120 , V_23 , V_86 ) ;
}
if ( ! V_90 ) {
V_90 = F_11 ( F_12 () , T_6 ) ;
F_14 ( V_90 -> V_7 , V_86 -> V_7 , V_24 ) ;
V_90 -> V_8 = V_86 -> V_8 ;
memcpy ( & ( V_90 -> V_25 ) , & ( V_86 -> V_25 ) , sizeof( V_126 ) ) ;
memcpy ( & ( V_90 -> V_35 ) , & ( V_86 -> V_35 ) , sizeof( V_126 ) ) ;
F_68 ( F_12 () , V_3 , V_23 , 0 , V_90 ) ;
}
if ( F_69 ( & V_120 -> V_127 -> V_128 , & V_3 -> V_122 ) ) {
V_87 = & ( V_86 -> V_25 ) ;
V_56 = & ( V_90 -> V_25 ) ;
} else {
V_87 = & ( V_86 -> V_35 ) ;
V_56 = & ( V_90 -> V_35 ) ;
}
V_61 -> V_8 = V_90 -> V_8 ;
}
static void
F_70 ( T_11 * T_12 , T_1 * V_3 , T_15 * T_16 )
{
T_10 V_129 ;
T_19 * V_130 ;
T_15 * V_131 ;
T_4 V_47 = 0 ;
if ( V_132 ) {
V_129 = F_71 ( T_12 , V_47 ) ;
if ( F_72 ( V_129 ) == 2 ) {
F_73 ( V_133 , T_12 , V_3 , T_16 ) ;
return;
}
}
F_74 ( V_3 -> V_54 , V_134 , L_17 ) ;
F_75 ( V_3 -> V_54 , V_55 ) ;
V_59 = TRUE ;
V_73 = 0 ;
V_130 = F_76 ( T_16 , V_23 , T_12 , 0 , - 1 , L_18 ) ;
V_131 = F_77 ( V_130 , V_135 ) ;
F_66 ( V_3 ) ;
if ( V_136 ) {
F_78 ( T_12 , V_131 , V_90 ) ;
}
F_32 ( V_3 -> V_54 , V_55 , L_19 ) ;
V_47 = F_65 ( T_12 , V_3 , V_131 , NULL ) ;
if ( F_37 ( T_12 , V_47 ) > 0 ) {
F_36 ( V_131 , V_3 , & V_85 , T_12 , V_47 , F_37 ( T_12 , V_47 ) ,
L_20 ) ;
F_32 ( V_3 -> V_54 , V_55 , L_11 ) ;
}
}
static void
F_79 ( T_11 * T_12 , T_1 * V_3 , T_15 * T_16 )
{
T_19 * V_130 ;
T_15 * V_131 ;
T_4 V_47 = 0 ;
T_11 * V_137 ;
T_20 V_138 = 1 ;
F_74 ( V_3 -> V_54 , V_134 , L_17 ) ;
F_75 ( V_3 -> V_54 , V_55 ) ;
V_59 = TRUE ;
V_73 = 0 ;
V_130 = F_76 ( T_16 , V_23 , T_12 , 0 , - 1 , L_18 ) ;
V_131 = F_77 ( V_130 , V_135 ) ;
F_66 ( V_3 ) ;
if ( V_136 ) {
F_78 ( T_12 , V_131 , V_90 ) ;
}
F_32 ( V_3 -> V_54 , V_55 , L_21 ) ;
while( F_37 ( T_12 , V_47 ) > 0 )
{
V_137 = F_80 ( T_12 , V_47 ) ;
V_47 += F_63 ( V_137 , V_3 , V_131 , NULL ) ;
V_138 ++ ;
if( F_37 ( T_12 , V_47 ) > 0 ) {
if( V_139 == V_140 ) {
F_36 ( V_131 , V_3 , & V_85 , T_12 , V_47 , F_37 ( T_12 , V_47 ) ,
L_20 ) ;
F_32 ( V_3 -> V_54 , V_55 , L_11 ) ;
break;
} else {
F_23 ( V_3 -> V_54 , V_55 , L_22 , V_138 ) ;
}
}
}
}
static void
F_81 ( T_11 * T_12 , T_1 * V_3 , T_15 * T_16 )
{
V_59 = TRUE ;
if( V_139 == V_140 ) {
F_82 ( T_12 , V_3 , T_16 , V_141 , V_142 ) ;
}
else if( ( V_139 == V_143 ) || ( F_83 ( T_12 , 1 ) == - 1 ) ) {
F_79 ( T_12 , V_3 , T_16 ) ;
}
else {
F_82 ( T_12 , V_3 , T_16 , V_141 , V_142 ) ;
}
}
void
F_78 ( T_11 * T_12 , T_15 * T_16 , T_6 * V_144 )
{
T_15 * V_145 ;
T_19 * V_146 ;
if ( ! V_144 || V_144 -> V_8 == 0 ) {
return;
}
V_146 = F_84 ( T_16 , V_147 , T_12 , 0 , 0 ,
L_23 ,
L_24 ,
V_144 -> V_7 ,
V_144 -> V_8 ) ;
F_85 ( V_146 ) ;
V_145 = F_77 ( V_146 , V_148 ) ;
if ( V_145 )
{
T_19 * V_149 = F_86 ( V_145 , V_150 ,
T_12 , 0 , 0 , V_144 -> V_8 ) ;
F_85 ( V_149 ) ;
V_149 = F_87 ( V_145 , V_151 ,
T_12 , 0 , 0 , V_144 -> V_7 ) ;
F_85 ( V_149 ) ;
}
}
void
F_88 ( void )
{
static T_21 V_152 [] =
{
#line 1 "../../asn1/t38/packet-t38-hfarr.c"
{ & V_114 ,
{ L_25 , L_26 ,
V_153 , V_154 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_115 ,
{ L_27 , L_28 ,
V_153 , V_154 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_156 ,
{ L_29 , L_30 ,
V_157 , V_158 , F_89 ( V_159 ) , 0 ,
NULL , V_155 } } ,
{ & V_160 ,
{ L_31 , L_32 ,
V_157 , V_158 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_161 ,
{ L_33 , L_34 ,
V_157 , V_158 , F_89 ( V_60 ) , 0 ,
NULL , V_155 } } ,
{ & V_162 ,
{ L_35 , L_36 ,
V_157 , V_158 , F_89 ( V_64 ) , 0 ,
NULL , V_155 } } ,
{ & V_163 ,
{ L_37 , L_38 ,
V_153 , V_154 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_164 ,
{ L_39 , L_40 ,
V_157 , V_158 , F_89 ( V_72 ) , 0 ,
NULL , V_155 } } ,
{ & V_165 ,
{ L_41 , L_42 ,
V_166 , V_154 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_167 ,
{ L_43 , L_44 ,
V_157 , V_158 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_168 ,
{ L_45 , L_46 ,
V_153 , V_154 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_169 ,
{ L_47 , L_48 ,
V_157 , V_158 , F_89 ( V_170 ) , 0 ,
NULL , V_155 } } ,
{ & V_171 ,
{ L_49 , L_50 ,
V_157 , V_158 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_172 ,
{ L_51 , L_52 ,
V_153 , V_154 , NULL , 0 ,
L_53 , V_155 } } ,
{ & V_173 ,
{ L_54 , L_55 ,
V_153 , V_154 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_174 ,
{ L_56 , L_57 ,
V_175 , V_158 , NULL , 0 ,
L_58 , V_155 } } ,
{ & V_176 ,
{ L_59 , L_60 ,
V_157 , V_158 , NULL , 0 ,
NULL , V_155 } } ,
{ & V_177 ,
{ L_61 , L_62 ,
V_166 , V_154 , NULL , 0 ,
L_63 , V_155 } } ,
#line 659 "../../asn1/t38/packet-t38-template.c"
{ & V_147 ,
{ L_64 , L_65 , V_178 , V_154 ,
NULL , 0x0 , L_66 , V_155 } } ,
{ & V_150 ,
{ L_67 , L_68 , V_179 , V_154 ,
NULL , 0x0 , L_69 , V_155 } } ,
{ & V_151 ,
{ L_70 , L_71 , V_178 , V_154 ,
NULL , 0x0 , L_72 , V_155 } } ,
{ & V_180 ,
{ L_73 , L_74 ,
V_153 , V_154 , NULL , 0x00 , NULL , V_155 } } ,
{ & V_181 ,
{ L_75 , L_76 ,
V_179 , V_154 , NULL , 0x00 , NULL , V_155 } } ,
{ & V_182 ,
{ L_77 , L_78 ,
V_183 , V_154 , NULL , 0x0 , NULL , V_155 } } ,
{ & V_184 ,
{ L_79 ,
L_80 ,
V_183 , V_154 , NULL , 0x0 , NULL , V_155 } } ,
{ & V_185 ,
{ L_81 ,
L_82 ,
V_183 , V_154 , NULL , 0x0 , NULL , V_155 } } ,
{ & V_186 ,
{ L_83 , L_84 ,
V_183 , V_154 , NULL , 0x0 , NULL , V_155 } } ,
{ & V_187 ,
{ L_85 , L_86 ,
V_179 , V_154 , NULL , 0x00 , NULL , V_155 } } ,
{ & V_188 ,
{ L_87 , L_88 ,
V_157 , V_158 , NULL , 0x00 , NULL , V_155 } } ,
{ & V_189 ,
{ L_89 , L_90 ,
V_179 , V_154 , NULL , 0x00 , NULL , V_155 } } ,
{ & V_190 ,
{ L_91 , L_92 ,
V_157 , V_158 , NULL , 0x00 , NULL , V_155 } } ,
} ;
static T_22 * V_191 [] =
{
& V_135 ,
#line 1 "../../asn1/t38/packet-t38-ettarr.c"
& V_97 ,
& V_66 ,
& V_95 ,
& V_93 ,
& V_110 ,
& V_108 ,
& V_101 ,
& V_106 ,
& V_104 ,
#line 706 "../../asn1/t38/packet-t38-template.c"
& V_148 ,
& V_192 ,
& V_193
} ;
static T_23 V_194 [] = {
{ & V_85 , { L_93 , V_195 , V_196 , L_94 , V_197 } } ,
} ;
T_24 * V_198 ;
T_25 * V_199 ;
V_23 = F_90 ( L_17 , L_17 , L_95 ) ;
F_91 ( V_23 , V_152 , F_92 ( V_152 ) ) ;
F_93 ( V_191 , F_92 ( V_191 ) ) ;
V_199 = F_94 ( V_23 ) ;
F_95 ( V_199 , V_194 , F_92 ( V_194 ) ) ;
F_96 ( L_96 , F_70 , V_23 ) ;
F_97 ( F_1 ) ;
F_98 ( F_3 ) ;
V_100 = F_99 ( L_95 ) ;
V_198 = F_100 ( V_23 , V_200 ) ;
F_101 ( V_198 , L_97 ,
L_98 ,
L_99
L_100 ,
& V_71 ) ;
F_101 ( V_198 , L_101 ,
L_102 ,
L_103
L_104
L_105 ,
& V_132 ) ;
F_102 ( V_198 , L_106 ,
L_107 ,
L_108 ,
10 , & V_201 ) ;
F_102 ( V_198 , L_109 ,
L_110 ,
L_111 ,
10 , & V_202 ) ;
F_101 ( V_198 , L_112 ,
L_113 ,
L_114
L_115
L_116
L_117 ,
& V_141 ) ;
F_103 ( V_198 , L_118 ,
L_119 ,
L_120 ,
( T_22 * ) & V_139 , V_203 , FALSE ) ;
F_101 ( V_198 , L_121 ,
L_122 ,
L_123
L_124 ,
& V_136 ) ;
}
void
V_200 ( void )
{
static T_18 V_204 = FALSE ;
static T_26 V_205 ;
static T_26 V_206 ;
if ( ! V_204 ) {
V_15 = F_104 ( F_70 , V_23 ) ;
V_207 = F_104 ( F_81 , V_23 ) ;
V_142 = F_104 ( F_79 , V_23 ) ;
V_133 = F_105 ( L_125 ) ;
V_83 = F_105 ( L_126 ) ;
V_84 = F_105 ( L_127 ) ;
V_204 = TRUE ;
}
else {
F_106 ( L_106 , V_205 , V_207 ) ;
F_106 ( L_109 , V_206 , V_15 ) ;
}
V_205 = V_201 ;
V_206 = V_202 ;
F_107 ( L_106 , V_205 , V_207 ) ;
F_107 ( L_109 , V_206 , V_15 ) ;
}
