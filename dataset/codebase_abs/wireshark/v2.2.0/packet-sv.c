static int
F_1 ( T_1 V_1 , T_2 * V_2 , T_3 * V_3 , T_4 * V_4 , int V_5 , int T_5 V_6 )
{
T_6 V_7 ;
T_1 V_8 ;
T_7 V_9 ;
T_8 V_10 ;
T_3 * V_11 ;
T_7 V_12 ;
T_8 V_13 ;
T_8 V_14 ;
static const int * V_15 [] = {
& V_16 ,
& V_17 ,
& V_18 ,
& V_19 ,
& V_20 ,
& V_21 ,
& V_22 ,
& V_23 ,
& V_24 ,
& V_25 ,
& V_26 ,
& V_27 ,
& V_28 ,
NULL
} ;
if ( ! V_1 ) {
V_5 = F_2 ( V_2 , V_3 , V_4 , V_5 , & V_7 , & V_8 , & V_9 ) ;
V_5 = F_3 ( V_2 , V_3 , V_4 , V_5 , & V_10 , NULL ) ;
} else {
V_10 = F_4 ( V_4 , V_5 ) ;
}
V_11 = F_5 ( V_3 , V_4 , V_5 , V_10 , V_29 , NULL , L_1 ) ;
V_30 . V_31 = 0 ;
for ( V_14 = 0 ; V_14 < V_10 / 8 ; V_14 ++ ) {
if ( V_3 && V_11 ) {
V_12 = F_6 ( V_4 , V_5 ) ;
V_13 = F_6 ( V_4 , V_5 + 4 ) ;
F_7 ( V_11 , V_32 , V_4 , V_5 , 4 , V_33 ) ;
F_8 ( V_11 , V_4 , V_5 + 4 , V_34 , V_35 , V_15 , V_33 ) ;
if ( V_14 < V_36 ) {
V_30 . V_37 [ V_14 ] . V_12 = V_12 ;
V_30 . V_37 [ V_14 ] . V_13 = V_13 ;
V_30 . V_31 ++ ;
}
}
V_5 += 8 ;
}
return V_5 ;
}
static int
F_9 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
V_5 = F_10 ( V_1 , T_10 , V_3 , V_4 , V_5 , T_11 ,
NULL ) ;
return V_5 ;
}
static int
F_11 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
V_5 = F_12 ( V_1 , V_38 ,
T_10 , V_3 , V_4 , V_5 , T_11 ,
NULL ) ;
return V_5 ;
}
static int
F_13 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
#line 18 "./asn1/sv/sv.cnf"
T_8 V_12 ;
V_5 = F_10 ( V_1 , T_10 , V_3 , V_4 , V_5 , T_11 ,
& V_12 ) ;
V_30 . V_39 = V_12 ;
return V_5 ;
}
static int
F_14 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
V_5 = F_10 ( V_1 , T_10 , V_3 , V_4 , V_5 , T_11 ,
NULL ) ;
return V_5 ;
}
static int
F_15 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
#line 24 "./asn1/sv/sv.cnf"
T_8 V_10 ;
T_8 V_40 ;
T_8 V_41 ;
T_8 V_42 ;
T_12 V_43 ;
T_13 * V_44 ;
V_10 = F_4 ( V_4 , V_5 ) ;
if( V_10 != 8 )
{
F_16 ( V_3 , T_10 -> V_2 , & V_45 , V_4 , V_5 , V_10 ,
L_2 ) ;
if( T_11 >= 0 )
{
F_17 ( V_3 , T_11 , V_4 , V_5 , V_10 , L_3 ) ;
}
return V_5 ;
}
V_40 = F_6 ( V_4 , V_5 ) ;
V_41 = F_18 ( V_4 , V_5 + 4 ) * 0x100 ;
V_42 = ( T_8 ) ( ( ( V_46 ) V_41 * F_19 ( 1000000000 ) ) / F_19 ( 0x100000000 ) ) ;
V_43 . V_47 = V_40 ;
V_43 . V_48 = V_42 ;
V_44 = F_20 ( F_21 () , & V_43 , V_49 , TRUE ) ;
if( T_11 >= 0 )
{
F_17 ( V_3 , T_11 , V_4 , V_5 , V_10 , V_44 ) ;
}
V_5 += 8 ;
return V_5 ;
return V_5 ;
}
static int
F_22 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
#line 65 "./asn1/sv/sv.cnf"
T_8 V_12 ;
V_5 = F_10 ( V_1 , T_10 , V_3 , V_4 , V_5 , T_11 ,
& V_12 ) ;
V_30 . V_50 = V_12 ;
return V_5 ;
}
static int
F_23 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
#line 77 "./asn1/sv/sv.cnf"
if ( V_51 ) {
V_5 = F_1 ( V_1 , T_10 -> V_2 , V_3 , V_4 , V_5 , T_11 ) ;
} else {
V_5 = F_24 ( V_1 , T_10 , V_3 , V_4 , V_5 , T_11 , NULL ) ;
}
return V_5 ;
}
static int
F_25 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
#line 71 "./asn1/sv/sv.cnf"
T_8 V_12 ;
V_5 = F_10 ( V_1 , T_10 , V_3 , V_4 , V_5 , T_11 ,
& V_12 ) ;
V_30 . V_52 = V_12 ;
return V_5 ;
}
static int
F_26 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
V_5 = F_27 ( V_1 , T_10 , V_3 , V_4 , V_5 ,
V_53 , T_11 , V_54 ) ;
return V_5 ;
}
static int
F_28 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
V_5 = F_29 ( V_1 , T_10 , V_3 , V_4 , V_5 ,
V_55 , T_11 , V_56 ) ;
return V_5 ;
}
static int
F_30 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
V_5 = F_27 ( V_1 , T_10 , V_3 , V_4 , V_5 ,
V_57 , T_11 , V_58 ) ;
return V_5 ;
}
static int
F_31 ( T_1 V_1 V_6 , T_4 * V_4 V_6 , int V_5 V_6 , T_9 * T_10 V_6 , T_3 * V_3 V_6 , int T_11 V_6 ) {
V_5 = F_32 ( T_10 , V_3 , V_4 , V_5 ,
V_59 , T_11 , V_60 ,
NULL ) ;
return V_5 ;
}
static int
F_33 ( T_4 * V_4 , T_2 * V_2 , T_3 * V_61 , void * T_14 V_6 )
{
int V_5 = 0 ;
int V_62 ;
T_15 * V_63 ;
T_3 * V_3 ;
T_9 V_64 ;
F_34 ( & V_64 , V_65 , TRUE , V_2 ) ;
V_63 = F_7 ( V_61 , V_66 , V_4 , 0 , - 1 , V_67 ) ;
V_3 = F_35 ( V_63 , V_68 ) ;
F_36 ( V_2 -> V_69 , V_70 , V_71 ) ;
F_37 ( V_2 -> V_69 , V_72 ) ;
F_7 ( V_3 , V_73 , V_4 , V_5 , 2 , V_33 ) ;
F_7 ( V_3 , V_74 , V_4 , V_5 + 2 , 2 , V_33 ) ;
F_7 ( V_3 , V_75 , V_4 , V_5 + 4 , 2 , V_33 ) ;
F_7 ( V_3 , V_76 , V_4 , V_5 + 6 , 2 , V_33 ) ;
V_5 = 8 ;
while ( F_4 ( V_4 , V_5 ) > 0 ) {
V_62 = V_5 ;
V_5 = F_31 ( FALSE , V_4 , V_5 , & V_64 , V_3 , - 1 ) ;
if ( V_5 == V_62 ) {
F_38 ( V_3 , V_2 , & V_77 , V_4 , V_5 , - 1 ) ;
break;
}
}
F_39 ( V_78 , V_2 , & V_30 ) ;
return F_40 ( V_4 ) ;
}
void F_41 ( void ) {
static T_16 V_79 [] = {
{ & V_73 ,
{ L_4 , L_5 , V_80 , V_81 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_74 ,
{ L_6 , L_7 , V_80 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_75 ,
{ L_8 , L_9 , V_80 , V_84 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_76 ,
{ L_10 , L_11 , V_80 , V_84 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_32 ,
{ L_12 , L_13 , V_85 , V_83 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_34 ,
{ L_14 , L_15 , V_86 , V_81 , NULL , 0x0 , NULL , V_82 } } ,
{ & V_16 ,
{ L_16 , L_17 , V_86 , V_81 , F_42 ( V_87 ) , V_88 , NULL , V_82 } } ,
{ & V_17 ,
{ L_18 , L_19 , V_89 , 32 , NULL , V_90 , NULL , V_82 } } ,
{ & V_18 ,
{ L_20 , L_21 , V_89 , 32 , NULL , V_91 , NULL , V_82 } } ,
{ & V_19 ,
{ L_22 , L_23 , V_89 , 32 , NULL , V_92 , NULL , V_82 } } ,
{ & V_20 ,
{ L_24 , L_25 , V_89 , 32 , NULL , V_93 , NULL , V_82 } } ,
{ & V_21 ,
{ L_26 , L_27 , V_89 , 32 , NULL , V_94 , NULL , V_82 } } ,
{ & V_22 ,
{ L_28 , L_29 , V_89 , 32 , NULL , V_95 , NULL , V_82 } } ,
{ & V_23 ,
{ L_30 , L_31 , V_89 , 32 , NULL , V_96 , NULL , V_82 } } ,
{ & V_24 ,
{ L_32 , L_33 , V_89 , 32 , NULL , V_97 , NULL , V_82 } } ,
{ & V_25 ,
{ L_34 , L_35 , V_86 , V_81 , F_42 ( V_98 ) , V_99 , NULL , V_82 } } ,
{ & V_26 ,
{ L_36 , L_37 , V_89 , 32 , NULL , V_100 , NULL , V_82 } } ,
{ & V_27 ,
{ L_38 , L_39 , V_89 , 32 , NULL , V_101 , NULL , V_82 } } ,
{ & V_28 ,
{ L_40 , L_41 , V_89 , 32 , NULL , V_102 , NULL , V_82 } } ,
#line 1 "./asn1/sv/packet-sv-hfarr.c"
{ & V_103 ,
{ L_42 , L_43 ,
V_104 , V_105 , NULL , 0 ,
NULL , V_82 } } ,
{ & V_106 ,
{ L_44 , L_45 ,
V_86 , V_83 , NULL , 0 ,
L_46 , V_82 } } ,
{ & V_107 ,
{ L_47 , L_48 ,
V_86 , V_83 , NULL , 0 ,
L_49 , V_82 } } ,
{ & V_108 ,
{ L_50 , L_51 ,
V_104 , V_105 , NULL , 0 ,
NULL , V_82 } } ,
{ & V_109 ,
{ L_52 , L_53 ,
V_110 , V_105 , NULL , 0 ,
L_54 , V_82 } } ,
{ & V_111 ,
{ L_55 , L_56 ,
V_110 , V_105 , NULL , 0 ,
L_54 , V_82 } } ,
{ & V_112 ,
{ L_57 , L_58 ,
V_86 , V_83 , NULL , 0 ,
NULL , V_82 } } ,
{ & V_113 ,
{ L_59 , L_60 ,
V_86 , V_83 , NULL , 0 ,
L_61 , V_82 } } ,
{ & V_114 ,
{ L_62 , L_63 ,
V_110 , V_105 , NULL , 0 ,
L_64 , V_82 } } ,
{ & V_115 ,
{ L_65 , L_66 ,
V_85 , V_83 , F_42 ( V_116 ) , 0 ,
NULL , V_82 } } ,
{ & V_117 ,
{ L_67 , L_68 ,
V_86 , V_83 , NULL , 0 ,
L_46 , V_82 } } ,
{ & V_118 ,
{ L_69 , L_70 ,
V_119 , V_105 , NULL , 0 ,
L_71 , V_82 } } ,
{ & V_120 ,
{ L_72 , L_73 ,
V_85 , V_83 , F_42 ( V_121 ) , 0 ,
NULL , V_82 } } ,
#line 299 "./asn1/sv/packet-sv-template.c"
} ;
static T_17 * V_122 [] = {
& V_68 ,
& V_29 ,
& V_35 ,
#line 1 "./asn1/sv/packet-sv-ettarr.c"
& V_60 ,
& V_58 ,
& V_56 ,
& V_54 ,
#line 307 "./asn1/sv/packet-sv-template.c"
} ;
static T_18 V_123 [] = {
{ & V_45 , { L_74 , V_124 , V_125 , L_75 , V_126 } } ,
{ & V_77 , { L_76 , V_127 , V_128 , L_77 , V_126 } } ,
} ;
T_19 * V_129 ;
T_20 * V_130 ;
V_66 = F_43 ( V_71 , V_131 , V_132 ) ;
V_133 = F_44 ( L_78 , F_33 , V_66 ) ;
F_45 ( V_66 , V_79 , F_46 ( V_79 ) ) ;
F_47 ( V_122 , F_46 ( V_122 ) ) ;
V_129 = F_48 ( V_66 ) ;
F_49 ( V_129 , V_123 , F_46 ( V_123 ) ) ;
V_130 = F_50 ( V_66 , NULL ) ;
F_51 ( V_130 , L_79 ,
L_80 ,
NULL , & V_51 ) ;
V_78 = F_52 ( L_78 ) ;
}
void F_53 ( void ) {
F_54 ( L_81 , V_134 , V_133 ) ;
}
