static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 33 "../../asn1/spnego/spnego.cnf"
T_11 * V_2 ;
T_5 = F_2 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 , & V_3 ) ;
V_2 = F_3 ( V_3 ) ;
if ( ! V_4 ) {
if ( V_2 )
V_5 = V_2 ;
V_4 = TRUE ;
}
return T_5 ;
}
static int
F_4 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 101 "../../asn1/spnego/spnego.cnf"
T_12 * V_6 ;
V_4 = FALSE ;
T_5 = F_5 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_7 , T_10 , V_8 ) ;
if( V_4 ) {
V_6 = F_6 ( T_7 -> V_9 ) ;
F_7 ( V_6 , V_10 , V_5 ) ;
}
return T_5 ;
}
static int
F_8 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_9 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_11 , T_10 , V_12 ,
NULL ) ;
return T_5 ;
}
static int
F_10 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 122 "../../asn1/spnego/spnego.cnf"
T_3 * V_13 = NULL ;
T_5 = F_11 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_13 ) ;
if ( V_13 && V_5 )
F_12 ( V_5 -> V_14 , V_13 , T_7 -> V_9 , T_9 ) ;
return T_5 ;
}
static int
F_13 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_11 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_14 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_15 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_15 , T_10 , V_16 ) ;
return T_5 ;
}
static int
F_16 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 12 "../../asn1/spnego/spnego.cnf"
T_1 V_17 = T_7 -> V_9 -> V_18 == V_19 &&
T_7 -> V_9 -> V_20 < 1024 ;
if ( V_17 ) {
return F_17 ( T_2 , T_4 , T_5 ,
T_7 , T_9 , T_10 ) ;
} else {
return F_14 ( T_2 , T_4 , T_5 ,
T_7 , T_9 , T_10 ) ;
}
return T_5 ;
}
static int
F_18 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_19 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_20 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 135 "../../asn1/spnego/spnego.cnf"
T_12 * V_6 ;
V_4 = FALSE ;
T_5 = F_1 ( T_2 , T_4 , T_5 , T_7 , T_9 , T_10 ) ;
if( V_4 ) {
V_6 = F_6 ( T_7 -> V_9 ) ;
F_7 ( V_6 , V_10 , V_5 ) ;
}
return T_5 ;
}
static int
F_21 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 158 "../../asn1/spnego/spnego.cnf"
T_3 * V_21 ;
T_5 = F_11 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_21 ) ;
if ( V_21 && ( F_22 ( V_21 ) > 0 ) ) {
T_11 * V_2 = V_5 ;
if( V_2 ) {
F_12 ( V_2 -> V_14 , V_21 , T_7 -> V_9 , T_9 ) ;
}
}
return T_5 ;
}
static int
F_23 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_15 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_22 , T_10 , V_23 ) ;
return T_5 ;
}
static int
F_24 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_25 ( T_7 , T_9 , T_4 , T_5 ,
V_24 , T_10 , V_25 ,
NULL ) ;
return T_5 ;
}
static int
F_26 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_27 ( T_2 , V_26 ,
T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_28 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_15 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_27 , T_10 , V_28 ) ;
return T_5 ;
}
static int
F_17 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_15 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_29 , T_10 , V_30 ) ;
return T_5 ;
}
static int
F_29 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 58 "../../asn1/spnego/spnego.cnf"
T_11 * V_31 ;
T_13 * V_32 ;
T_8 * V_33 ;
T_3 * V_34 ;
int V_35 ;
V_31 = F_3 ( V_3 ) ;
V_32 = F_30 ( T_9 , V_36 , T_4 , T_5 , - 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_38 ) ;
V_34 = F_32 ( T_4 , T_5 ) ;
if ( V_31 && V_31 -> V_39 ) {
V_35 = F_12 ( V_31 -> V_39 , V_34 , T_7 -> V_9 ,
V_33 ) ;
if ( V_35 == 0 )
T_5 = F_22 ( T_4 ) ;
else
T_5 = T_5 + V_35 ;
} else
T_5 = F_22 ( T_4 ) ;
return T_5 ;
}
static int
F_33 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_15 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_40 , T_10 , V_41 ) ;
return T_5 ;
}
static int
F_34 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_35 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
T_10 , V_42 , 0 , TRUE , F_33 ) ;
return T_5 ;
}
static void
F_36 ( T_3 * T_4 , T_14 * V_9 , T_8 * T_9 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_15 V_43 ;
const char * V_44 ;
T_3 * V_45 ;
T_16 V_46 ;
T_1 V_47 , V_48 = 0 ;
T_17 V_49 ;
T_18 V_35 ;
T_6 V_50 ;
F_37 ( & V_50 , V_51 , TRUE , V_9 ) ;
V_32 = F_30 ( T_9 , V_52 , T_4 , T_5 ,
- 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_53 ) ;
F_38 ( T_4 , T_5 , & V_46 , & V_47 , & V_49 ) ;
if ( V_46 == V_42 && V_47 ) {
T_5 = F_39 ( V_9 , V_33 , T_4 , T_5 , & V_46 , & V_47 , & V_49 ) ;
T_5 = F_40 ( V_9 , V_33 , T_4 , T_5 , & V_35 , & V_48 ) ;
switch ( V_49 ) {
case 0 :
T_5 = F_2 ( FALSE , & V_50 , V_33 , T_4 , T_5 , V_54 , & V_44 ) ;
V_43 = F_41 ( T_4 , T_5 ) ;
F_42 ( V_33 , V_55 , T_4 , T_5 , 2 ,
V_43 ) ;
T_5 += 2 ;
break;
case 14 :
case 15 :
F_43 ( T_4 , V_9 , V_33 , FALSE , NULL ) ;
return;
default:
F_44 ( V_33 , V_9 , & V_56 , T_4 , T_5 , 0 ,
L_1 ,
V_46 , V_47 , V_49 ) ;
goto V_57;
}
} else {
V_43 = F_41 ( T_4 , T_5 ) ;
F_42 ( V_33 , V_55 , T_4 , T_5 , 2 ,
V_43 ) ;
T_5 += 2 ;
}
switch ( V_43 ) {
case V_58 :
case V_59 :
case V_60 :
V_45 = F_32 ( T_4 , T_5 ) ;
T_5 = F_43 ( V_45 , V_9 , V_33 , FALSE , NULL ) ;
break;
case V_61 :
T_5 = F_45 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_62 :
T_5 = F_46 ( T_4 , T_5 , V_9 , V_33 , V_43 ) ;
break;
case V_63 :
break;
case V_64 :
T_5 = F_47 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_65 :
T_5 = F_48 ( T_4 , T_5 , V_9 , V_33 , V_43 ) ;
break;
default:
break;
}
V_57:
F_49 ( V_32 , T_5 ) ;
return;
}
static int
F_50 ( const T_19 * V_66 , T_20 V_67 , int V_68 ,
const T_19 * V_69 , T_20 V_70 ,
T_19 * V_71 )
{
T_19 V_72 [ 16 ] ;
T_19 V_73 [ 4 ] ;
memset ( V_73 , 0 , 4 ) ;
if ( V_68 == V_74 ) {
T_19 V_75 [ 14 ] = L_2 ;
memcpy ( V_75 + 10 , V_73 , sizeof( V_73 ) ) ;
F_51 (
V_75 , 14 ,
V_66 ,
V_67 ,
V_72 ) ;
memset ( & V_72 [ 7 ] , 0xAB , 9 ) ;
} else {
F_51 (
V_73 , 4 ,
V_66 ,
V_67 ,
V_72 ) ;
}
F_51 (
V_69 , V_70 ,
V_72 ,
16 ,
V_71 ) ;
return 0 ;
}
static int
F_52 ( int V_76 )
{
switch ( V_76 ) {
case 3 :
case 9 :
return 8 ;
case 22 :
return 13 ;
case 23 :
return 15 ;
case 24 :
return 0 ;
default :
return 0 ;
}
}
static int
F_53 ( T_19 * V_66 , int V_77 ,
unsigned int V_76 ,
T_19 V_78 [ 8 ] ,
const T_19 * V_79 , T_20 V_80 ,
const T_19 * V_81 , T_20 V_82 ,
const T_19 * V_83 , T_20 V_84 )
{
static const T_19 V_85 [] = L_3 ;
T_19 V_86 [ 16 ] ;
T_19 V_87 [ 4 ] ;
T_21 V_88 ;
T_19 V_89 [ 16 ] ;
int V_90 ;
T_19 V_91 [ 16 ] ;
V_90 = F_52 ( V_76 ) ;
F_51 ( V_85 , sizeof( V_85 ) ,
V_66 , V_77 ,
V_86 ) ;
F_54 ( & V_88 ) ;
V_87 [ 0 ] = ( V_90 >> 0 ) & 0xFF ;
V_87 [ 1 ] = ( V_90 >> 8 ) & 0xFF ;
V_87 [ 2 ] = ( V_90 >> 16 ) & 0xFF ;
V_87 [ 3 ] = ( V_90 >> 24 ) & 0xFF ;
F_55 ( & V_88 , V_87 , 4 ) ;
F_55 ( & V_88 , V_79 , V_80 ) ;
F_55 ( & V_88 , V_81 , V_82 ) ;
F_55 ( & V_88 , V_83 , V_84 ) ;
F_56 ( & V_88 , V_89 ) ;
F_51 ( V_89 , 16 , V_86 , 16 , V_91 ) ;
memcpy ( V_78 , V_91 , 8 ) ;
return 0 ;
}
static int
F_57 ( T_19 * V_92 , int V_93 ,
int V_94 ,
int * V_95 )
{
T_19 * V_96 ;
int V_97 ;
int V_98 ;
V_96 = V_92 + V_93 - 1 ;
V_97 = * V_96 ;
if ( V_97 > V_94 )
return 1 ;
for ( V_98 = V_97 ; V_98 > 0 && * V_96 == V_97 ; V_98 -- , V_96 -- )
;
if ( V_98 != 0 )
return 2 ;
* V_95 = V_97 ;
return 0 ;
}
static int
F_58 ( T_14 * V_9 ,
T_19 * V_99 ,
T_19 * V_100 ,
T_19 * V_101 , int V_67 , int V_68 )
{
T_19 V_102 [ 16 ] ;
int V_103 ;
int V_94 ;
T_19 V_104 [ 16 ] ;
T_18 V_105 [ 2 ] ;
T_19 V_106 [ 8 ] ;
T_19 V_69 [ 8 ] ;
int V_107 ;
int V_108 ;
int V_95 = 0 ;
V_94 = F_59 ( V_9 -> V_109 ) ;
if( F_60 ( V_9 -> V_110 , 4 ) == 0x1000 ) {
V_108 = 1 ;
} else if ( F_60 ( V_9 -> V_110 , 4 ) == 0xffff ) {
V_108 = 0 ;
} else {
return - 3 ;
}
if( F_60 ( V_9 -> V_110 , 6 ) != 0xffff ) {
return - 4 ;
}
V_103 = F_50 ( V_101 , V_67 , V_68 ,
F_61 ( V_9 -> V_110 , 16 , 8 ) ,
8 ,
V_104 ) ;
if ( V_103 ) {
return - 5 ;
}
{
T_22 V_111 ;
F_62 ( & V_111 , V_104 , sizeof( V_104 ) ) ;
F_63 ( V_9 -> V_110 , V_105 , 8 , 8 ) ;
F_64 ( & V_111 , ( T_19 * ) V_105 , 8 ) ;
memset ( V_104 , 0 , sizeof( V_104 ) ) ;
}
if ( V_105 [ 1 ] != 0xFFFFFFFF && V_105 [ 1 ] != 0x00000000 ) {
return - 6 ;
}
{
int V_98 ;
for ( V_98 = 0 ; V_98 < 16 ; V_98 ++ )
V_102 [ V_98 ] = ( ( T_19 * ) V_101 ) [ V_98 ] ^ 0xF0 ;
}
V_103 = F_50 ( V_102 , sizeof( V_102 ) , V_68 ,
( const T_19 * ) V_105 , 4 ,
V_104 ) ;
memset ( V_102 , 0 , sizeof( V_102 ) ) ;
if ( V_103 ) {
return - 7 ;
}
if( V_108 ) {
T_22 V_111 ;
F_62 ( & V_111 , V_104 , sizeof( V_104 ) ) ;
F_63 ( V_9 -> V_110 , V_106 , 24 , 8 ) ;
F_64 ( & V_111 , V_106 , 8 ) ;
memcpy ( V_100 , V_99 , V_94 ) ;
F_64 ( & V_111 , V_100 , V_94 ) ;
} else {
F_63 ( V_9 -> V_110 , V_106 , 24 , 8 ) ;
memcpy ( V_100 ,
V_99 ,
V_94 ) ;
}
memset ( V_104 , 0 , sizeof( V_104 ) ) ;
if( V_9 -> V_112 == V_113 ) {
V_103 = F_57 ( V_100 , V_94 , V_94 , & V_95 ) ;
if ( V_103 ) {
return - 9 ;
}
V_94 -= V_95 ;
}
if( V_9 -> V_112 == V_113 ) {
V_103 = F_53 ( V_101 , V_67 ,
V_114 ,
V_69 ,
F_61 ( V_9 -> V_110 , 0 , 8 ) , 8 ,
V_106 , sizeof( V_106 ) ,
V_100 ,
V_94 + V_95 ) ;
if ( V_103 ) {
return - 10 ;
}
V_107 = F_65 ( V_9 -> V_110 , 16 , V_69 , 8 ) ;
if ( V_107 ) {
return - 11 ;
}
}
return V_94 ;
}
static void
F_66 ( T_8 * T_9 V_1 , T_14 * V_9 , T_3 * T_4 , int V_115 )
{
int V_103 ;
T_23 * V_116 ;
int V_117 ;
const T_19 * V_118 ;
T_19 * V_119 = NULL ;
T_19 * V_100 ;
V_117 = F_59 ( V_9 -> V_109 ) ;
V_118 = F_61 ( V_9 -> V_109 , 0 , V_117 ) ;
V_119 = ( T_19 * ) F_67 ( F_68 () , V_117 ) ;
V_100 = ( T_19 * ) F_67 ( V_9 -> V_120 , V_117 ) ;
for( V_116 = V_121 ; V_116 ; V_116 = V_116 -> V_122 ) {
if( V_116 -> V_115 != V_115 ) {
continue;
}
memcpy ( V_119 , V_118 , V_117 ) ;
V_103 = F_58 ( V_9 ,
V_119 ,
V_100 ,
V_116 -> V_123 ,
V_116 -> V_124 ,
V_116 -> V_115
) ;
if ( V_103 >= 0 ) {
F_69 ( V_9 , NULL , & V_125 ,
L_4 ,
V_116 -> V_115 , V_9 -> V_126 -> V_127 , V_116 -> V_128 ) ;
V_9 -> V_129 = F_70 ( T_4 ,
V_100 ,
V_103 , V_103 ) ;
F_71 ( V_9 , V_9 -> V_129 , L_5 ) ;
return;
}
}
return;
}
static int
F_72 ( T_19 * V_130 , int V_35 , T_15 V_131 , int V_132 )
{
T_19 * V_133 , V_134 [ 256 ] ;
T_20 V_135 ;
if ( V_35 == 0 )
return 0 ;
V_131 %= V_35 ;
if ( V_131 == 0 )
return 0 ;
V_135 = V_35 - V_131 ;
if ( V_131 <= sizeof( V_134 ) ) {
V_133 = V_134 ;
} else {
V_133 = ( T_19 * ) F_73 ( V_131 ) ;
if ( V_133 == NULL )
return - 1 ;
}
if ( V_132 ) {
memcpy ( V_133 , V_130 , V_131 ) ;
memmove ( V_130 , V_130 + V_131 , V_135 ) ;
memcpy ( V_130 + V_135 , V_133 , V_131 ) ;
} else {
memcpy ( V_133 , V_130 + V_135 , V_131 ) ;
memmove ( V_130 + V_131 , V_130 , V_135 ) ;
memcpy ( V_130 , V_133 , V_131 ) ;
}
if ( V_131 > sizeof( V_134 ) )
F_74 ( V_133 ) ;
return 0 ;
}
static void
F_75 ( T_8 * T_9 V_1 ,
T_14 * V_9 ,
T_3 * V_136 ,
T_3 * V_137 ,
T_15 V_138 ,
T_15 V_131 ,
T_1 V_139 ,
int V_115 ,
unsigned int V_76 )
{
T_19 * V_140 ;
T_19 * V_141 ;
int V_94 ;
T_3 * V_142 ;
if( ! V_143 ) {
return;
}
V_94 = F_59 ( V_136 ) + F_59 ( V_137 ) ;
V_140 = ( T_19 * ) F_67 ( V_9 -> V_120 , V_94 ) ;
F_63 ( V_136 , V_140 ,
0 , F_59 ( V_136 ) ) ;
F_63 ( V_137 , V_140 + F_59 ( V_136 ) ,
0 , F_59 ( V_137 ) ) ;
if ( V_139 ) {
V_131 += V_138 ;
}
F_72 ( V_140 , V_94 , V_131 , TRUE ) ;
V_142 = F_70 ( V_137 , V_140 ,
V_94 , V_94 ) ;
F_71 ( V_9 , V_142 , L_6 ) ;
V_141 = F_76 ( T_9 , V_9 , V_76 , V_142 ,
V_115 , & V_94 ) ;
if ( V_141 ) {
T_19 * V_144 ;
V_144 = ( T_19 * ) F_77 ( V_141 , F_59 ( V_137 ) ) ;
F_74 ( V_141 ) ;
V_9 -> V_129 = F_70 ( V_137 ,
V_144 ,
F_59 ( V_137 ) ,
F_59 ( V_137 ) ) ;
F_71 ( V_9 , V_9 -> V_129 , L_5 ) ;
F_78 ( V_9 -> V_129 , F_74 ) ;
return;
}
return;
}
static int
F_46 ( T_3 * T_4 , int T_5 , T_14 * V_9
#ifndef F_79
V_1
#endif
, T_8 * T_9 , T_15 V_43
#ifndef F_79
V_1
#endif
)
{
T_15 V_145 , V_146 ;
#ifdef F_79
int V_147 = T_5 ;
#endif
V_145 = F_41 ( T_4 , T_5 ) ;
F_42 ( T_9 , V_148 , T_4 , T_5 , 2 ,
V_145 ) ;
T_5 += 2 ;
V_146 = F_41 ( T_4 , T_5 ) ;
F_42 ( T_9 , V_149 , T_4 , T_5 , 2 ,
V_146 ) ;
T_5 += 2 ;
T_5 += 2 ;
F_30 ( T_9 , V_150 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
F_30 ( T_9 , V_151 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
if ( ( V_145 == V_152 ) ||
( V_145 == V_153 ) ) {
F_30 ( T_9 , V_154 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
}
V_9 -> V_155 = ( V_146 != V_156 ) ;
#ifdef F_79
#define F_80 32
if( V_9 -> V_112 ) {
if( ! V_9 -> V_109 ) {
int V_35 ;
V_35 = F_81 ( T_4 , T_5 ) ;
if( V_35 > F_82 ( T_4 , T_5 ) ) {
return T_5 ;
}
V_9 -> V_109 = F_83 (
T_4 , T_5 , V_35 ) ;
}
if( ( V_43 == V_62 )
&& ( V_145 == V_152 )
&& ( V_146 == V_157 ) ) {
if( ! V_9 -> V_110 ) {
V_9 -> V_110 = F_83 (
T_4 , V_147 - 2 ,
F_80 ) ;
}
#if F_84 ( V_158 ) || F_84 ( V_159 )
F_66 ( T_9 ,
V_9 ,
T_4 ,
23 ) ;
#endif
}
}
#endif
return T_5 ;
}
static int
F_45 ( T_3 * T_4 , int T_5 , T_14 * V_9 V_1 , T_8 * T_9 )
{
T_15 V_145 ;
V_145 = F_41 ( T_4 , T_5 ) ;
F_42 ( T_9 , V_148 , T_4 , T_5 , 2 ,
V_145 ) ;
T_5 += 2 ;
T_5 += 4 ;
F_30 ( T_9 , V_150 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
F_30 ( T_9 , V_151 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
if ( F_81 ( T_4 , T_5 ) ) {
if ( V_145 == V_152 ) {
F_30 ( T_9 , V_154 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
}
}
return T_5 ;
}
static int
F_85 ( T_3 * T_4 , int T_5 ,
T_8 * V_160 ,
T_19 T_24 V_1 )
{
static const int * V_161 [] = {
& V_162 ,
& V_163 ,
& V_164 ,
NULL
} ;
F_86 ( V_160 , T_4 , T_5 , V_165 , V_166 , V_161 , V_37 ) ;
return ( T_5 + 1 ) ;
}
static int
F_48 ( T_3 * T_4 , int T_5 , T_14 * V_9
#ifndef F_79
V_1
#endif
, T_8 * T_9 , T_15 V_43 V_1
)
{
T_19 V_161 ;
T_15 V_138 ;
#if F_84 ( V_158 ) || F_84 ( V_159 )
T_15 V_131 ;
#endif
int V_167 ;
int V_147 = T_5 ;
V_161 = F_87 ( T_4 , T_5 ) ;
T_5 = F_85 ( T_4 , T_5 , T_9 , V_161 ) ;
V_9 -> V_155 = ( V_161 & 2 ) ;
F_30 ( T_9 , V_168 , T_4 , T_5 , 1 ,
V_37 ) ;
T_5 += 1 ;
V_138 = F_60 ( T_4 , T_5 ) ;
F_30 ( T_9 , V_169 , T_4 , T_5 , 2 ,
V_170 ) ;
T_5 += 2 ;
#if F_84 ( V_158 ) || F_84 ( V_159 )
V_131 = F_60 ( T_4 , T_5 ) ;
#endif
F_30 ( T_9 , V_171 , T_4 , T_5 , 2 ,
V_170 ) ;
T_5 += 2 ;
F_30 ( T_9 , V_172 , T_4 , T_5 , 8 ,
V_170 ) ;
T_5 += 8 ;
if ( V_9 -> V_155 ) {
V_167 = 44 + V_138 ;
F_30 ( T_9 , V_151 , T_4 , T_5 ,
V_167 , V_37 ) ;
T_5 += V_167 ;
} else {
int V_173 ;
int V_174 = 0 ;
V_167 = V_138 ;
V_174 = F_81 ( T_4 , T_5 ) ;
if ( V_174 > V_138 ) {
V_174 -= V_138 ;
}
#if F_84 ( V_158 ) || F_84 ( V_159 )
if ( V_131 == V_138 ) {
F_30 ( T_9 , V_151 ,
T_4 , T_5 , V_167 , V_37 ) ;
T_5 += V_167 ;
}
#endif
V_173 = T_5 ;
V_9 -> V_110 = F_83 ( T_4 , T_5 ,
V_174 ) ;
T_5 += V_174 ;
#if F_84 ( V_158 ) || F_84 ( V_159 )
if ( V_131 == 0 )
#endif
{
F_30 ( T_9 , V_151 ,
T_4 , T_5 , V_167 , V_37 ) ;
}
return V_173 ;
}
if( V_9 -> V_112 ) {
if( ! V_9 -> V_109 ) {
int V_35 ;
V_35 = F_81 ( T_4 , T_5 ) ;
if( V_35 > F_82 ( T_4 , T_5 ) ) {
return T_5 ;
}
V_9 -> V_109 = F_88 (
T_4 , T_5 , V_35 , V_35 ) ;
}
if ( V_9 -> V_155 ) {
if( ! V_9 -> V_110 ) {
V_9 -> V_110 = F_83 (
T_4 , V_147 - 2 ,
T_5 - ( V_147 - 2 ) ) ;
}
}
}
#if F_84 ( V_158 ) || F_84 ( V_159 )
{
T_3 * V_136 = F_83 ( T_4 , 16 , V_167 ) ;
if ( V_9 -> V_155 ) {
if( V_9 -> V_109 ) {
F_75 ( T_9 ,
V_9 ,
V_136 ,
V_9 -> V_109 ,
V_138 ,
V_131 ,
( V_9 -> V_112 == V_175 ) ? TRUE : FALSE ,
- 1 ,
( V_161 & 0x0001 ) ?
V_176 :
V_177 ) ;
}
}
}
#endif
return T_5 ;
}
static int
F_47 ( T_3 * T_4 , int T_5 , T_14 * V_9 V_1 , T_8 * T_9 )
{
T_19 V_161 ;
int V_167 ;
V_161 = F_87 ( T_4 , T_5 ) ;
T_5 = F_85 ( T_4 , T_5 , T_9 , V_161 ) ;
F_30 ( T_9 , V_168 , T_4 , T_5 , 5 ,
V_37 ) ;
T_5 += 5 ;
F_30 ( T_9 , V_172 , T_4 , T_5 , 8 ,
V_170 ) ;
T_5 += 8 ;
V_167 = F_82 ( T_4 , T_5 ) ;
F_30 ( T_9 , V_151 , T_4 , T_5 ,
V_167 , V_37 ) ;
T_5 += V_167 ;
return T_5 ;
}
static int
F_89 ( T_3 * T_4 , T_14 * V_9 V_1 , T_8 * T_9 , void * V_130 V_1 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_15 V_43 ;
V_32 = F_30 ( T_9 , V_52 , T_4 , 0 , - 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_53 ) ;
V_43 = F_41 ( T_4 , T_5 ) ;
F_42 ( V_33 , V_55 , T_4 , T_5 , 2 ,
V_43 ) ;
T_5 += 2 ;
switch ( V_43 ) {
case V_61 :
T_5 = F_45 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_62 :
T_5 = F_46 ( T_4 , T_5 , V_9 , V_33 , V_43 ) ;
break;
case V_64 :
T_5 = F_47 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_65 :
T_5 = F_48 ( T_4 , T_5 , V_9 , V_33 , V_43 ) ;
break;
default:
break;
}
F_49 ( V_32 , T_5 ) ;
return T_5 ;
}
static int
F_90 ( T_3 * T_4 , T_14 * V_9 , T_8 * T_9 , void * V_130 V_1 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_6 V_50 ;
F_37 ( & V_50 , V_51 , TRUE , V_9 ) ;
V_3 = NULL ;
V_32 = F_30 ( T_9 , V_10 , T_4 , T_5 ,
- 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_178 ) ;
T_5 = F_34 ( FALSE , T_4 , T_5 , & V_50 , V_33 , - 1 ) ;
return T_5 ;
}
static void
F_91 ( T_3 * T_4 , T_14 * V_9 , T_8 * V_179 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_12 * V_6 ;
T_6 V_50 ;
F_37 ( & V_50 , V_51 , TRUE , V_9 ) ;
V_5 = ( T_11 * ) F_92 ( F_93 () , V_9 , V_10 , 0 ) ;
if ( ! V_5 && ! V_9 -> V_126 -> V_161 . V_180 ) {
V_6 = F_94 ( V_9 -> V_126 -> V_127 , & V_9 -> V_181 , & V_9 -> V_182 ,
V_9 -> V_18 , V_9 -> V_20 ,
V_9 -> V_183 , 0 ) ;
if ( V_6 ) {
V_5 = ( T_11 * ) F_95 ( V_6 ,
V_10 ) ;
if ( V_5 )
F_96 ( F_93 () , V_9 , V_10 , 0 , V_5 ) ;
}
}
V_32 = F_30 ( V_179 , V_10 , T_4 , T_5 ,
- 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_178 ) ;
F_24 ( FALSE , T_4 , T_5 , & V_50 , V_33 , - 1 ) ;
}
void F_97 ( void ) {
static T_25 V_184 [] = {
{ & V_36 ,
{ L_7 , L_8 ,
V_185 , V_186 , NULL , 0x0 , L_9 ,
V_187 } } ,
{ & V_52 ,
{ L_10 , L_11 , V_188 ,
V_186 , NULL , 0 , NULL , V_187 } } ,
{ & V_54 ,
{ L_12 , L_13 , V_189 ,
V_186 , NULL , 0 , NULL , V_187 } } ,
{ & V_55 ,
{ L_14 , L_15 , V_190 , V_191 ,
F_98 ( V_192 ) , 0 , L_16 , V_187 } } ,
{ & V_148 ,
{ L_17 , L_18 , V_190 , V_191 ,
F_98 ( V_193 ) , 0 , L_19 , V_187 } } ,
{ & V_149 ,
{ L_20 , L_21 , V_190 , V_191 ,
F_98 ( V_194 ) , 0 , L_22 , V_187 } } ,
{ & V_150 ,
{ L_23 , L_24 , V_188 , V_186 ,
NULL , 0 , L_25 , V_187 } } ,
{ & V_151 ,
{ L_26 , L_27 , V_188 , V_186 ,
NULL , 0 , L_28 , V_187 } } ,
{ & V_154 ,
{ L_29 , L_30 , V_188 , V_186 ,
NULL , 0 , L_31 , V_187 } } ,
{ & V_168 ,
{ L_32 , L_33 , V_188 , V_186 ,
NULL , 0 , L_34 , V_187 } } ,
{ & V_165 ,
{ L_35 , L_36 , V_195 , V_191 ,
NULL , 0 , L_37 , V_187 } } ,
{ & V_164 ,
{ L_38 , L_39 , V_196 , 8 ,
F_99 ( & V_197 ) , 0x01 , NULL , V_187 } } ,
{ & V_163 ,
{ L_40 , L_41 , V_196 , 8 ,
F_99 ( & V_197 ) , 0x02 , NULL , V_187 } } ,
{ & V_162 ,
{ L_42 , L_43 , V_196 , 8 ,
F_99 ( & V_197 ) , 0x04 , NULL , V_187 } } ,
{ & V_169 ,
{ L_44 , L_45 , V_190 , V_198 ,
NULL , 0 , L_46 , V_187 } } ,
{ & V_171 ,
{ L_47 , L_48 , V_190 , V_198 ,
NULL , 0 , L_49 , V_187 } } ,
{ & V_172 ,
{ L_50 , L_51 , V_199 , V_198 ,
NULL , 0 , L_52 , V_187 } } ,
#line 1 "../../asn1/spnego/packet-spnego-hfarr.c"
{ & V_200 ,
{ L_53 , L_54 ,
V_185 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_201 ,
{ L_55 , L_56 ,
V_185 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_202 ,
{ L_57 , L_58 ,
V_203 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_204 ,
{ L_59 , L_60 ,
V_205 , V_198 , NULL , 0 ,
L_61 , V_187 } } ,
{ & V_206 ,
{ L_62 , L_63 ,
V_188 , V_186 , NULL , 0 ,
L_64 , V_187 } } ,
{ & V_207 ,
{ L_65 , L_66 ,
V_188 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_208 ,
{ L_67 , L_68 ,
V_188 , V_186 , NULL , 0 ,
L_69 , V_187 } } ,
{ & V_209 ,
{ L_70 , L_71 ,
V_189 , V_186 , NULL , 0 ,
L_72 , V_187 } } ,
{ & V_210 ,
{ L_73 , L_74 ,
V_188 , V_186 , NULL , 0 ,
L_69 , V_187 } } ,
{ & V_211 ,
{ L_65 , L_66 ,
V_188 , V_186 , NULL , 0 ,
L_69 , V_187 } } ,
{ & V_212 ,
{ L_75 , L_76 ,
V_185 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_213 ,
{ L_77 , L_78 ,
V_205 , V_198 , F_98 ( V_214 ) , 0 ,
NULL , V_187 } } ,
{ & V_215 ,
{ L_79 , L_80 ,
V_203 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_216 ,
{ L_81 , L_82 ,
V_188 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_217 ,
{ L_83 , L_84 ,
V_203 , V_186 , NULL , 0 ,
L_57 , V_187 } } ,
{ & V_218 ,
{ L_85 , L_86 ,
V_185 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_219 ,
{ L_87 , L_88 ,
V_196 , 8 , NULL , 0x80 ,
NULL , V_187 } } ,
{ & V_220 ,
{ L_89 , L_90 ,
V_196 , 8 , NULL , 0x40 ,
NULL , V_187 } } ,
{ & V_221 ,
{ L_91 , L_92 ,
V_196 , 8 , NULL , 0x20 ,
NULL , V_187 } } ,
{ & V_222 ,
{ L_93 , L_94 ,
V_196 , 8 , NULL , 0x10 ,
NULL , V_187 } } ,
{ & V_223 ,
{ L_95 , L_96 ,
V_196 , 8 , NULL , 0x08 ,
NULL , V_187 } } ,
{ & V_224 ,
{ L_97 , L_98 ,
V_196 , 8 , NULL , 0x04 ,
NULL , V_187 } } ,
{ & V_225 ,
{ L_99 , L_100 ,
V_196 , 8 , NULL , 0x02 ,
NULL , V_187 } } ,
#line 1414 "../../asn1/spnego/packet-spnego-template.c"
} ;
static T_26 * V_226 [] = {
& V_178 ,
& V_38 ,
& V_53 ,
& V_166 ,
#line 1 "../../asn1/spnego/packet-spnego-ettarr.c"
& V_25 ,
& V_8 ,
& V_16 ,
& V_28 ,
& V_30 ,
& V_12 ,
& V_23 ,
& V_41 ,
#line 1424 "../../asn1/spnego/packet-spnego-template.c"
} ;
static T_27 V_227 [] = {
{ & V_125 , { L_101 , V_228 , V_229 , L_102 , V_230 } } ,
{ & V_56 , { L_103 , V_231 , V_232 , L_104 , V_230 } } ,
} ;
T_28 * V_233 ;
V_10 = F_100 ( V_234 , V_235 , V_236 ) ;
F_101 ( L_105 , F_91 , V_10 ) ;
V_237 = F_100 ( L_106 ,
L_106 ,
L_107 ) ;
F_101 ( L_107 , F_36 , V_237 ) ;
F_102 ( L_108 , F_89 , V_237 ) ;
F_103 ( V_10 , V_184 , F_104 ( V_184 ) ) ;
F_105 ( V_226 , F_104 ( V_226 ) ) ;
V_233 = F_106 ( V_10 ) ;
F_107 ( V_233 , V_227 , F_104 ( V_227 ) ) ;
}
void F_108 ( void ) {
T_29 V_238 , V_239 ;
T_29 V_240 , V_241 ;
V_238 = F_109 ( L_105 ) ;
V_239 = F_110 ( F_90 , V_10 ) ;
F_111 ( L_109 , V_10 , V_178 ,
V_238 , V_239 ,
L_110 ) ;
V_240 = F_109 ( L_107 ) ;
V_241 = F_109 ( L_108 ) ;
F_111 ( L_111 , V_237 , V_53 ,
V_240 , V_241 ,
L_112 ) ;
F_111 ( L_113 , V_237 , V_53 ,
V_240 , V_241 ,
L_114 ) ;
F_111 ( L_115 , V_237 , V_53 ,
V_240 , V_241 ,
L_116 ) ;
}
