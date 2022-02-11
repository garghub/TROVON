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
T_5 = F_33 ( T_4 ) ;
else
T_5 = T_5 + V_35 ;
} else
T_5 = F_33 ( T_4 ) ;
return T_5 ;
}
static int
F_34 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_15 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_40 , T_10 , V_41 ) ;
return T_5 ;
}
static int
F_35 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_36 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
T_10 , V_42 , 0 , TRUE , F_34 ) ;
return T_5 ;
}
static void
F_37 ( T_3 * T_4 , T_14 * V_9 , T_8 * T_9 )
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
F_38 ( & V_50 , V_51 , TRUE , V_9 ) ;
V_32 = F_30 ( T_9 , V_52 , T_4 , T_5 ,
- 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_53 ) ;
F_39 ( T_4 , T_5 , & V_46 , & V_47 , & V_49 ) ;
if ( V_46 == V_42 && V_47 ) {
T_5 = F_40 ( V_9 , V_33 , T_4 , T_5 , & V_46 , & V_47 , & V_49 ) ;
T_5 = F_41 ( V_9 , V_33 , T_4 , T_5 , & V_35 , & V_48 ) ;
switch ( V_49 ) {
case 0 :
T_5 = F_2 ( FALSE , & V_50 , V_33 , T_4 , T_5 , V_54 , & V_44 ) ;
V_43 = F_42 ( T_4 , T_5 ) ;
F_43 ( V_33 , V_55 , T_4 , T_5 , 2 ,
V_43 ) ;
T_5 += 2 ;
break;
case 14 :
case 15 :
F_44 ( T_4 , V_9 , V_33 , FALSE , NULL ) ;
return;
default:
F_45 ( V_33 , T_4 , T_5 , 0 ,
L_1 ,
V_46 , V_47 , V_49 ) ;
goto V_56;
}
} else {
V_43 = F_42 ( T_4 , T_5 ) ;
F_43 ( V_33 , V_55 , T_4 , T_5 , 2 ,
V_43 ) ;
T_5 += 2 ;
}
switch ( V_43 ) {
case V_57 :
case V_58 :
case V_59 :
V_45 = F_32 ( T_4 , T_5 ) ;
T_5 = F_44 ( V_45 , V_9 , V_33 , FALSE , NULL ) ;
break;
case V_60 :
T_5 = F_46 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_61 :
T_5 = F_47 ( T_4 , T_5 , V_9 , V_33 , V_43 ) ;
break;
case V_62 :
break;
case V_63 :
T_5 = F_48 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_64 :
T_5 = F_49 ( T_4 , T_5 , V_9 , V_33 , V_43 ) ;
break;
default:
break;
}
V_56:
F_50 ( V_32 , T_5 ) ;
return;
}
static int
F_51 ( const T_19 * V_65 , T_20 V_66 , int V_67 ,
const T_19 * V_68 , T_20 V_69 ,
T_19 * V_70 )
{
T_19 V_71 [ 16 ] ;
T_19 V_72 [ 4 ] ;
memset ( V_72 , 0 , 4 ) ;
if ( V_67 == V_73 ) {
T_19 V_74 [ 14 ] = L_2 ;
memcpy ( V_74 + 10 , V_72 , sizeof( V_72 ) ) ;
F_52 (
V_74 , 14 ,
V_65 ,
V_66 ,
V_71 ) ;
memset ( & V_71 [ 7 ] , 0xAB , 9 ) ;
} else {
F_52 (
V_72 , 4 ,
V_65 ,
V_66 ,
V_71 ) ;
}
F_52 (
V_68 , V_69 ,
V_71 ,
16 ,
V_70 ) ;
return 0 ;
}
static int
F_53 ( int V_75 )
{
switch ( V_75 ) {
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
F_54 ( T_19 * V_65 , int V_76 ,
unsigned int V_75 ,
T_19 V_77 [ 8 ] ,
const T_19 * V_78 , T_20 V_79 ,
const T_19 * V_80 , T_20 V_81 ,
const T_19 * V_82 , T_20 V_83 )
{
static const T_19 V_84 [] = L_3 ;
T_19 V_85 [ 16 ] ;
T_19 V_86 [ 4 ] ;
T_21 V_87 ;
T_19 V_88 [ 16 ] ;
int V_89 ;
T_19 V_90 [ 16 ] ;
V_89 = F_53 ( V_75 ) ;
F_52 ( V_84 , sizeof( V_84 ) ,
V_65 , V_76 ,
V_85 ) ;
F_55 ( & V_87 ) ;
V_86 [ 0 ] = ( V_89 >> 0 ) & 0xFF ;
V_86 [ 1 ] = ( V_89 >> 8 ) & 0xFF ;
V_86 [ 2 ] = ( V_89 >> 16 ) & 0xFF ;
V_86 [ 3 ] = ( V_89 >> 24 ) & 0xFF ;
F_56 ( & V_87 , V_86 , 4 ) ;
F_56 ( & V_87 , V_78 , V_79 ) ;
F_56 ( & V_87 , V_80 , V_81 ) ;
F_56 ( & V_87 , V_82 , V_83 ) ;
F_57 ( & V_87 , V_88 ) ;
F_52 ( V_88 , 16 , V_85 , 16 , V_90 ) ;
memcpy ( V_77 , V_90 , 8 ) ;
return 0 ;
}
static int
F_58 ( T_19 * V_91 , int V_92 ,
int V_93 ,
int * V_94 )
{
T_19 * V_95 ;
int V_96 ;
int V_97 ;
V_95 = V_91 + V_92 - 1 ;
V_96 = * V_95 ;
if ( V_96 > V_93 )
return 1 ;
for ( V_97 = V_96 ; V_97 > 0 && * V_95 == V_96 ; V_97 -- , V_95 -- )
;
if ( V_97 != 0 )
return 2 ;
* V_94 = V_96 ;
return 0 ;
}
static int
F_59 ( T_14 * V_9 ,
T_19 * V_98 ,
T_19 * V_99 ,
T_19 * V_100 , int V_66 , int V_67 )
{
T_19 V_101 [ 16 ] ;
int V_102 ;
int V_93 ;
T_19 V_103 [ 16 ] ;
T_18 V_104 [ 2 ] ;
T_19 V_105 [ 8 ] ;
T_19 V_68 [ 8 ] ;
int V_106 ;
int V_107 ;
int V_94 = 0 ;
V_93 = F_33 ( V_9 -> V_108 ) ;
if( F_60 ( V_9 -> V_109 , 4 ) == 0x1000 ) {
V_107 = 1 ;
} else if ( F_60 ( V_9 -> V_109 , 4 ) == 0xffff ) {
V_107 = 0 ;
} else {
return - 3 ;
}
if( F_60 ( V_9 -> V_109 , 6 ) != 0xffff ) {
return - 4 ;
}
V_102 = F_51 ( V_100 , V_66 , V_67 ,
F_61 ( V_9 -> V_109 , 16 , 8 ) ,
8 ,
V_103 ) ;
if ( V_102 ) {
return - 5 ;
}
{
T_22 V_110 ;
F_62 ( & V_110 , V_103 , sizeof( V_103 ) ) ;
F_63 ( V_9 -> V_109 , V_104 , 8 , 8 ) ;
F_64 ( & V_110 , ( T_19 * ) V_104 , 8 ) ;
memset ( V_103 , 0 , sizeof( V_103 ) ) ;
}
if ( V_104 [ 1 ] != 0xFFFFFFFF && V_104 [ 1 ] != 0x00000000 ) {
return - 6 ;
}
{
int V_97 ;
for ( V_97 = 0 ; V_97 < 16 ; V_97 ++ )
V_101 [ V_97 ] = ( ( T_19 * ) V_100 ) [ V_97 ] ^ 0xF0 ;
}
V_102 = F_51 ( V_101 , sizeof( V_101 ) , V_67 ,
( const T_19 * ) V_104 , 4 ,
V_103 ) ;
memset ( V_101 , 0 , sizeof( V_101 ) ) ;
if ( V_102 ) {
return - 7 ;
}
if( V_107 ) {
T_22 V_110 ;
F_62 ( & V_110 , V_103 , sizeof( V_103 ) ) ;
F_63 ( V_9 -> V_109 , V_105 , 24 , 8 ) ;
F_64 ( & V_110 , V_105 , 8 ) ;
memcpy ( V_99 , V_98 , V_93 ) ;
F_64 ( & V_110 , V_99 , V_93 ) ;
} else {
F_63 ( V_9 -> V_109 , V_105 , 24 , 8 ) ;
memcpy ( V_99 ,
V_98 ,
V_93 ) ;
}
memset ( V_103 , 0 , sizeof( V_103 ) ) ;
if( V_9 -> V_111 == V_112 ) {
V_102 = F_58 ( V_99 , V_93 , V_93 , & V_94 ) ;
if ( V_102 ) {
return - 9 ;
}
V_93 -= V_94 ;
}
if( V_9 -> V_111 == V_112 ) {
V_102 = F_54 ( V_100 , V_66 ,
V_113 ,
V_68 ,
F_61 ( V_9 -> V_109 , 0 , 8 ) , 8 ,
V_105 , sizeof( V_105 ) ,
V_99 ,
V_93 + V_94 ) ;
if ( V_102 ) {
return - 10 ;
}
V_106 = F_65 ( V_9 -> V_109 , 16 , V_68 , 8 ) ;
if ( V_106 ) {
return - 11 ;
}
}
return V_93 ;
}
static void
F_66 ( T_8 * T_9 , T_14 * V_9 , T_3 * T_4 , int V_114 )
{
int V_102 ;
T_23 * V_115 ;
int V_116 ;
const T_19 * V_117 ;
T_19 * V_118 = NULL ;
T_19 * V_99 ;
V_116 = F_33 ( V_9 -> V_108 ) ;
V_117 = F_61 ( V_9 -> V_108 , 0 , V_116 ) ;
V_118 = ( T_19 * ) F_67 ( F_68 () , V_116 ) ;
V_99 = ( T_19 * ) F_67 ( V_9 -> V_119 , V_116 ) ;
for( V_115 = V_120 ; V_115 ; V_115 = V_115 -> V_121 ) {
if( V_115 -> V_114 != V_114 ) {
continue;
}
memcpy ( V_118 , V_117 , V_116 ) ;
V_102 = F_59 ( V_9 ,
V_118 ,
V_99 ,
V_115 -> V_122 ,
V_115 -> V_123 ,
V_115 -> V_114
) ;
if ( V_102 >= 0 ) {
F_45 ( T_9 , NULL , 0 , 0 , L_4 , V_115 -> V_124 ) ;
V_9 -> V_125 = F_69 ( T_4 ,
V_99 ,
V_102 , V_102 ) ;
F_70 ( V_9 , V_9 -> V_125 , L_5 ) ;
return;
}
}
return;
}
static int
F_71 ( T_19 * V_126 , int V_35 , T_15 V_127 , int V_128 )
{
T_19 * V_129 , V_130 [ 256 ] ;
T_20 V_131 ;
if ( V_35 == 0 )
return 0 ;
V_127 %= V_35 ;
if ( V_127 == 0 )
return 0 ;
V_131 = V_35 - V_127 ;
if ( V_127 <= sizeof( V_130 ) ) {
V_129 = V_130 ;
} else {
V_129 = ( T_19 * ) F_72 ( V_127 ) ;
if ( V_129 == NULL )
return - 1 ;
}
if ( V_128 ) {
memcpy ( V_129 , V_126 , V_127 ) ;
memmove ( V_126 , V_126 + V_127 , V_131 ) ;
memcpy ( V_126 + V_131 , V_129 , V_127 ) ;
} else {
memcpy ( V_129 , V_126 + V_131 , V_127 ) ;
memmove ( V_126 + V_127 , V_126 , V_131 ) ;
memcpy ( V_126 , V_129 , V_127 ) ;
}
if ( V_127 > sizeof( V_130 ) )
F_73 ( V_129 ) ;
return 0 ;
}
static void
F_74 ( T_8 * T_9 V_1 ,
T_14 * V_9 ,
T_3 * V_132 ,
T_3 * V_133 ,
T_15 V_134 ,
T_15 V_127 ,
T_1 V_135 ,
int V_114 ,
unsigned int V_75 )
{
T_19 * V_136 ;
T_19 * V_137 ;
int V_93 ;
T_3 * V_138 ;
if( ! V_139 ) {
return;
}
V_93 = F_33 ( V_132 ) + F_33 ( V_133 ) ;
V_136 = ( T_19 * ) F_67 ( V_9 -> V_119 , V_93 ) ;
F_63 ( V_132 , V_136 ,
0 , F_33 ( V_132 ) ) ;
F_63 ( V_133 , V_136 + F_33 ( V_132 ) ,
0 , F_33 ( V_133 ) ) ;
if ( V_135 ) {
V_127 += V_134 ;
}
F_71 ( V_136 , V_93 , V_127 , TRUE ) ;
V_138 = F_69 ( V_133 , V_136 ,
V_93 , V_93 ) ;
F_70 ( V_9 , V_138 , L_6 ) ;
V_137 = F_75 ( T_9 , V_9 , V_75 , V_138 ,
V_114 , & V_93 ) ;
if ( V_137 ) {
T_19 * V_140 ;
V_140 = ( T_19 * ) F_76 ( V_137 , F_33 ( V_133 ) ) ;
F_73 ( V_137 ) ;
V_9 -> V_125 = F_69 ( V_133 ,
V_140 ,
F_33 ( V_133 ) ,
F_33 ( V_133 ) ) ;
F_70 ( V_9 , V_9 -> V_125 , L_5 ) ;
F_77 ( V_9 -> V_125 , F_73 ) ;
return;
}
return;
}
static int
F_47 ( T_3 * T_4 , int T_5 , T_14 * V_9
#ifndef F_78
V_1
#endif
, T_8 * T_9 , T_15 V_43
#ifndef F_78
V_1
#endif
)
{
T_15 V_141 , V_142 ;
#ifdef F_78
int V_143 = T_5 ;
#endif
V_141 = F_42 ( T_4 , T_5 ) ;
F_43 ( T_9 , V_144 , T_4 , T_5 , 2 ,
V_141 ) ;
T_5 += 2 ;
V_142 = F_42 ( T_4 , T_5 ) ;
F_43 ( T_9 , V_145 , T_4 , T_5 , 2 ,
V_142 ) ;
T_5 += 2 ;
T_5 += 2 ;
F_30 ( T_9 , V_146 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
F_30 ( T_9 , V_147 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
if ( ( V_141 == V_148 ) ||
( V_141 == V_149 ) ) {
F_30 ( T_9 , V_150 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
}
V_9 -> V_151 = ( V_142 != V_152 ) ;
#ifdef F_78
#define F_79 32
if( V_9 -> V_111 ) {
if( ! V_9 -> V_108 ) {
int V_35 ;
V_35 = F_80 ( T_4 , T_5 ) ;
if( V_35 > F_81 ( T_4 , T_5 ) ) {
return T_5 ;
}
V_9 -> V_108 = F_82 (
T_4 , T_5 , V_35 , V_35 ) ;
}
if( ( V_43 == V_61 )
&& ( V_141 == V_148 )
&& ( V_142 == V_153 ) ) {
if( ! V_9 -> V_109 ) {
V_9 -> V_109 = F_82 (
T_4 , V_143 - 2 ,
F_79 ,
F_79 ) ;
}
#if F_83 ( V_154 ) || F_83 ( V_155 )
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
F_46 ( T_3 * T_4 , int T_5 , T_14 * V_9 V_1 , T_8 * T_9 )
{
T_15 V_141 ;
V_141 = F_42 ( T_4 , T_5 ) ;
F_43 ( T_9 , V_144 , T_4 , T_5 , 2 ,
V_141 ) ;
T_5 += 2 ;
T_5 += 4 ;
F_30 ( T_9 , V_146 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
F_30 ( T_9 , V_147 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
if ( F_81 ( T_4 , T_5 ) ) {
if ( V_141 == V_148 ) {
F_30 ( T_9 , V_150 , T_4 , T_5 , 8 ,
V_37 ) ;
T_5 += 8 ;
}
}
return T_5 ;
}
static int
F_84 ( T_3 * T_4 , int T_5 ,
T_8 * V_156 ,
T_19 V_157 )
{
T_8 * V_158 = NULL ;
T_13 * V_159 = NULL ;
if ( V_156 ) {
V_159 = F_43 ( V_156 ,
V_160 ,
T_4 , T_5 , 1 , V_157 ) ;
V_158 = F_31 ( V_159 , V_161 ) ;
}
F_85 ( V_158 ,
V_162 ,
T_4 , T_5 , 1 , V_157 ) ;
F_85 ( V_158 ,
V_163 ,
T_4 , T_5 , 1 , V_157 ) ;
F_85 ( V_158 ,
V_164 ,
T_4 , T_5 , 1 , V_157 ) ;
return ( T_5 + 1 ) ;
}
static int
F_49 ( T_3 * T_4 , int T_5 , T_14 * V_9
#ifndef F_78
V_1
#endif
, T_8 * T_9 , T_15 V_43 V_1
)
{
T_19 V_165 ;
T_15 V_134 ;
#if F_83 ( V_154 ) || F_83 ( V_155 )
T_15 V_127 ;
#endif
int V_166 ;
int V_143 = T_5 ;
V_165 = F_86 ( T_4 , T_5 ) ;
T_5 = F_84 ( T_4 , T_5 , T_9 , V_165 ) ;
V_9 -> V_151 = ( V_165 & 2 ) ;
F_30 ( T_9 , V_167 , T_4 , T_5 , 1 ,
V_37 ) ;
T_5 += 1 ;
V_134 = F_60 ( T_4 , T_5 ) ;
F_30 ( T_9 , V_168 , T_4 , T_5 , 2 ,
V_169 ) ;
T_5 += 2 ;
#if F_83 ( V_154 ) || F_83 ( V_155 )
V_127 = F_60 ( T_4 , T_5 ) ;
#endif
F_30 ( T_9 , V_170 , T_4 , T_5 , 2 ,
V_169 ) ;
T_5 += 2 ;
F_30 ( T_9 , V_171 , T_4 , T_5 , 8 ,
V_169 ) ;
T_5 += 8 ;
if ( V_9 -> V_151 ) {
V_166 = 44 + V_134 ;
F_30 ( T_9 , V_147 , T_4 , T_5 ,
V_166 , V_37 ) ;
T_5 += V_166 ;
} else {
int V_172 = 0 ;
V_166 = V_134 ;
V_172 = F_80 ( T_4 , T_5 ) -
V_134 ;
V_9 -> V_109 = F_82 ( T_4 , T_5 ,
V_172 , V_172 ) ;
T_5 += V_172 ;
F_30 ( T_9 , V_147 , T_4 , T_5 ,
V_166 , V_37 ) ;
return T_5 - V_172 ;
}
if( V_9 -> V_111 ) {
if( ! V_9 -> V_108 ) {
int V_35 ;
V_35 = F_80 ( T_4 , T_5 ) ;
if( V_35 > F_81 ( T_4 , T_5 ) ) {
return T_5 ;
}
V_9 -> V_108 = F_82 (
T_4 , T_5 , V_35 , V_35 ) ;
}
if ( V_9 -> V_151 ) {
if( ! V_9 -> V_109 ) {
V_9 -> V_109 = F_82 (
T_4 , V_143 - 2 ,
T_5 - ( V_143 - 2 ) ,
T_5 - ( V_143 - 2 ) ) ;
}
}
}
#if F_83 ( V_154 ) || F_83 ( V_155 )
{
T_3 * V_132 = F_82 ( T_4 , 16 , V_166 , V_166 ) ;
if ( V_9 -> V_151 ) {
if( V_9 -> V_108 ) {
F_74 ( T_9 ,
V_9 ,
V_132 ,
V_9 -> V_108 ,
V_134 ,
V_127 ,
( V_9 -> V_111 == V_173 ) ? TRUE : FALSE ,
- 1 ,
( V_165 & 0x0001 ) ?
V_174 :
V_175 ) ;
}
}
}
#endif
return T_5 ;
}
static int
F_48 ( T_3 * T_4 , int T_5 , T_14 * V_9 V_1 , T_8 * T_9 )
{
T_19 V_165 ;
int V_166 ;
V_165 = F_86 ( T_4 , T_5 ) ;
T_5 = F_84 ( T_4 , T_5 , T_9 , V_165 ) ;
F_30 ( T_9 , V_167 , T_4 , T_5 , 5 ,
V_37 ) ;
T_5 += 5 ;
F_30 ( T_9 , V_171 , T_4 , T_5 , 8 ,
V_169 ) ;
T_5 += 8 ;
V_166 = F_81 ( T_4 , T_5 ) ;
F_30 ( T_9 , V_147 , T_4 , T_5 ,
V_166 , V_37 ) ;
T_5 += V_166 ;
return T_5 ;
}
static int
F_87 ( T_3 * T_4 , T_14 * V_9 V_1 , T_8 * T_9 , void * V_126 V_1 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_15 V_43 ;
V_32 = F_30 ( T_9 , V_52 , T_4 , 0 , - 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_53 ) ;
V_43 = F_42 ( T_4 , T_5 ) ;
F_43 ( V_33 , V_55 , T_4 , T_5 , 2 ,
V_43 ) ;
T_5 += 2 ;
switch ( V_43 ) {
case V_60 :
T_5 = F_46 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_61 :
T_5 = F_47 ( T_4 , T_5 , V_9 , V_33 , V_43 ) ;
break;
case V_63 :
T_5 = F_48 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_64 :
T_5 = F_49 ( T_4 , T_5 , V_9 , V_33 , V_43 ) ;
break;
default:
break;
}
F_50 ( V_32 , T_5 ) ;
return T_5 ;
}
static int
F_88 ( T_3 * T_4 , T_14 * V_9 , T_8 * T_9 , void * V_126 V_1 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_6 V_50 ;
F_38 ( & V_50 , V_51 , TRUE , V_9 ) ;
V_3 = NULL ;
V_32 = F_30 ( T_9 , V_10 , T_4 , T_5 ,
- 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_176 ) ;
T_5 = F_35 ( FALSE , T_4 , T_5 , & V_50 , V_33 , - 1 ) ;
return T_5 ;
}
static void
F_89 ( T_3 * T_4 , T_14 * V_9 , T_8 * V_177 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_12 * V_6 ;
T_6 V_50 ;
F_38 ( & V_50 , V_51 , TRUE , V_9 ) ;
V_5 = ( T_11 * ) F_90 ( F_91 () , V_9 , V_10 , 0 ) ;
if ( ! V_5 && ! V_9 -> V_178 -> V_165 . V_179 ) {
V_6 = F_92 ( V_9 -> V_178 -> V_180 , & V_9 -> V_181 , & V_9 -> V_182 ,
V_9 -> V_18 , V_9 -> V_20 ,
V_9 -> V_183 , 0 ) ;
if ( V_6 ) {
V_5 = ( T_11 * ) F_93 ( V_6 ,
V_10 ) ;
if ( V_5 )
F_94 ( F_91 () , V_9 , V_10 , 0 , V_5 ) ;
}
}
V_32 = F_30 ( V_177 , V_10 , T_4 , T_5 ,
- 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_176 ) ;
F_24 ( FALSE , T_4 , T_5 , & V_50 , V_33 , - 1 ) ;
}
void F_95 ( void ) {
static T_24 V_184 [] = {
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
F_96 ( V_192 ) , 0 , L_16 , V_187 } } ,
{ & V_144 ,
{ L_17 , L_18 , V_190 , V_191 ,
F_96 ( V_193 ) , 0 , L_19 , V_187 } } ,
{ & V_145 ,
{ L_20 , L_21 , V_190 , V_191 ,
F_96 ( V_194 ) , 0 , L_22 , V_187 } } ,
{ & V_146 ,
{ L_23 , L_24 , V_188 , V_186 ,
NULL , 0 , L_25 , V_187 } } ,
{ & V_147 ,
{ L_26 , L_27 , V_188 , V_186 ,
NULL , 0 , L_28 , V_187 } } ,
{ & V_150 ,
{ L_29 , L_30 , V_188 , V_186 ,
NULL , 0 , L_31 , V_187 } } ,
{ & V_167 ,
{ L_32 , L_33 , V_188 , V_186 ,
NULL , 0 , L_34 , V_187 } } ,
{ & V_160 ,
{ L_35 , L_36 , V_195 , V_191 ,
NULL , 0 , L_37 , V_187 } } ,
{ & V_164 ,
{ L_38 , L_39 , V_196 , 8 ,
F_97 ( & V_197 ) , 0x01 , NULL , V_187 } } ,
{ & V_163 ,
{ L_40 , L_41 , V_196 , 8 ,
F_97 ( & V_197 ) , 0x02 , NULL , V_187 } } ,
{ & V_162 ,
{ L_42 , L_43 , V_196 , 8 ,
F_97 ( & V_197 ) , 0x04 , NULL , V_187 } } ,
{ & V_168 ,
{ L_44 , L_45 , V_190 , V_198 ,
NULL , 0 , L_46 , V_187 } } ,
{ & V_170 ,
{ L_47 , L_48 , V_190 , V_198 ,
NULL , 0 , L_49 , V_187 } } ,
{ & V_171 ,
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
V_205 , V_198 , F_96 ( V_214 ) , 0 ,
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
#line 1409 "../../asn1/spnego/packet-spnego-template.c"
} ;
static T_25 * V_226 [] = {
& V_176 ,
& V_38 ,
& V_53 ,
& V_161 ,
#line 1 "../../asn1/spnego/packet-spnego-ettarr.c"
& V_25 ,
& V_8 ,
& V_16 ,
& V_28 ,
& V_30 ,
& V_12 ,
& V_23 ,
& V_41 ,
#line 1419 "../../asn1/spnego/packet-spnego-template.c"
} ;
V_10 = F_98 ( V_227 , V_228 , V_229 ) ;
F_99 ( L_101 , F_89 , V_10 ) ;
V_230 = F_98 ( L_102 ,
L_102 ,
L_103 ) ;
F_99 ( L_103 , F_37 , V_230 ) ;
F_100 ( L_104 , F_87 , V_230 ) ;
F_101 ( V_10 , V_184 , F_102 ( V_184 ) ) ;
F_103 ( V_226 , F_102 ( V_226 ) ) ;
}
void F_104 ( void ) {
T_26 V_231 , V_232 ;
T_26 V_233 , V_234 ;
V_231 = F_105 ( L_101 ) ;
V_232 = F_106 ( F_88 , V_10 ) ;
F_107 ( L_105 , V_10 , V_176 ,
V_231 , V_232 ,
L_106 ) ;
V_233 = F_105 ( L_103 ) ;
V_234 = F_105 ( L_104 ) ;
F_107 ( L_107 , V_230 , V_53 ,
V_233 , V_234 ,
L_108 ) ;
F_107 ( L_109 , V_230 , V_53 ,
V_233 , V_234 ,
L_110 ) ;
F_107 ( L_111 , V_230 , V_53 ,
V_233 , V_234 ,
L_112 ) ;
}
