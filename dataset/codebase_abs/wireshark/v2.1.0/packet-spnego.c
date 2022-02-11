static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 33 "./asn1/spnego/spnego.cnf"
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
#line 101 "./asn1/spnego/spnego.cnf"
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
#line 122 "./asn1/spnego/spnego.cnf"
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
#line 12 "./asn1/spnego/spnego.cnf"
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
#line 135 "./asn1/spnego/spnego.cnf"
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
#line 158 "./asn1/spnego/spnego.cnf"
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
#line 58 "./asn1/spnego/spnego.cnf"
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
static int
F_36 ( T_3 * T_4 , T_14 * V_9 , T_8 * T_9 , void * V_43 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_15 V_44 ;
const char * V_45 ;
T_3 * V_46 ;
T_16 V_47 ;
T_1 V_48 , V_49 = 0 ;
T_17 V_50 ;
T_18 V_35 ;
T_19 * V_51 = ( T_19 * ) V_43 ;
T_6 V_52 ;
F_37 ( & V_52 , V_53 , TRUE , V_9 ) ;
V_32 = F_30 ( T_9 , V_54 , T_4 , T_5 ,
- 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_55 ) ;
F_38 ( T_4 , T_5 , & V_47 , & V_48 , & V_50 ) ;
if ( V_47 == V_42 && V_48 ) {
T_5 = F_39 ( V_9 , V_33 , T_4 , T_5 , & V_47 , & V_48 , & V_50 ) ;
T_5 = F_40 ( V_9 , V_33 , T_4 , T_5 , & V_35 , & V_49 ) ;
switch ( V_50 ) {
case 0 :
T_5 = F_2 ( FALSE , & V_52 , V_33 , T_4 , T_5 , V_56 , & V_45 ) ;
V_44 = F_41 ( T_4 , T_5 ) ;
F_42 ( V_33 , V_57 , T_4 , T_5 , 2 ,
V_44 ) ;
T_5 += 2 ;
break;
case 14 :
case 15 :
F_43 ( T_4 , V_9 , V_33 , FALSE , NULL ) ;
return F_44 ( T_4 ) ;
default:
F_45 ( V_33 , V_9 , & V_58 , T_4 , T_5 , 0 ,
L_1 ,
V_47 , V_48 , V_50 ) ;
goto V_59;
}
} else {
V_44 = F_41 ( T_4 , T_5 ) ;
F_42 ( V_33 , V_57 , T_4 , T_5 , 2 ,
V_44 ) ;
T_5 += 2 ;
}
switch ( V_44 ) {
case V_60 :
case V_61 :
case V_62 :
V_46 = F_32 ( T_4 , T_5 ) ;
T_5 = F_43 ( V_46 , V_9 , V_33 , FALSE , NULL ) ;
break;
case V_63 :
T_5 = F_46 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_64 :
T_5 = F_47 ( T_4 , T_5 , V_9 , V_33 , V_44 , V_51 ) ;
break;
case V_65 :
break;
case V_66 :
T_5 = F_48 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_67 :
T_5 = F_49 ( T_4 , T_5 , V_9 , V_33 , V_44 , V_51 ) ;
break;
default:
break;
}
V_59:
F_50 ( V_32 , T_5 ) ;
return F_44 ( T_4 ) ;
}
static int
F_51 ( const T_20 * V_68 , T_21 V_69 , int V_70 ,
const T_20 * V_71 , T_21 V_72 ,
T_20 * V_73 )
{
T_20 V_74 [ 16 ] ;
T_20 V_75 [ 4 ] ;
memset ( V_75 , 0 , 4 ) ;
if ( V_70 == V_76 ) {
T_20 V_77 [ 14 ] = L_2 ;
memcpy ( V_77 + 10 , V_75 , sizeof( V_75 ) ) ;
F_52 (
V_77 , 14 ,
V_68 ,
V_69 ,
V_74 ) ;
memset ( & V_74 [ 7 ] , 0xAB , 9 ) ;
} else {
F_52 (
V_75 , 4 ,
V_68 ,
V_69 ,
V_74 ) ;
}
F_52 (
V_71 , V_72 ,
V_74 ,
16 ,
V_73 ) ;
return 0 ;
}
static int
F_53 ( int V_78 )
{
switch ( V_78 ) {
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
F_54 ( T_20 * V_68 , int V_79 ,
unsigned int V_78 ,
T_20 V_80 [ 8 ] ,
const T_20 * V_81 , T_21 V_82 ,
const T_20 * V_83 , T_21 V_84 ,
const T_20 * V_85 , T_21 V_86 )
{
static const T_20 V_87 [] = L_3 ;
T_20 V_88 [ 16 ] ;
T_20 V_89 [ 4 ] ;
T_22 V_90 ;
T_20 V_91 [ 16 ] ;
int V_92 ;
T_20 V_93 [ 16 ] ;
V_92 = F_53 ( V_78 ) ;
F_52 ( V_87 , sizeof( V_87 ) ,
V_68 , V_79 ,
V_88 ) ;
F_55 ( & V_90 ) ;
V_89 [ 0 ] = ( V_92 >> 0 ) & 0xFF ;
V_89 [ 1 ] = ( V_92 >> 8 ) & 0xFF ;
V_89 [ 2 ] = ( V_92 >> 16 ) & 0xFF ;
V_89 [ 3 ] = ( V_92 >> 24 ) & 0xFF ;
F_56 ( & V_90 , V_89 , 4 ) ;
F_56 ( & V_90 , V_81 , V_82 ) ;
F_56 ( & V_90 , V_83 , V_84 ) ;
F_56 ( & V_90 , V_85 , V_86 ) ;
F_57 ( & V_90 , V_91 ) ;
F_52 ( V_91 , 16 , V_88 , 16 , V_93 ) ;
memcpy ( V_80 , V_93 , 8 ) ;
return 0 ;
}
static int
F_58 ( T_20 * V_94 , int V_95 ,
int V_96 ,
int * V_97 )
{
T_20 * V_98 ;
int V_99 ;
int V_100 ;
V_98 = V_94 + V_95 - 1 ;
V_99 = * V_98 ;
if ( V_99 > V_96 )
return 1 ;
for ( V_100 = V_99 ; V_100 > 0 && * V_98 == V_99 ; V_100 -- , V_98 -- )
;
if ( V_100 != 0 )
return 2 ;
* V_97 = V_99 ;
return 0 ;
}
static int
F_59 ( T_19 * V_101 , T_20 * V_102 , T_20 * V_103 ,
T_20 * V_104 , int V_69 , int V_70 )
{
T_20 V_105 [ 16 ] ;
int V_106 ;
int V_96 ;
T_20 V_107 [ 16 ] ;
T_18 V_108 [ 2 ] ;
T_20 V_109 [ 8 ] ;
T_20 V_71 [ 8 ] ;
int V_110 ;
int V_111 ;
int V_97 = 0 ;
V_96 = F_44 ( V_101 -> V_112 ) ;
if( F_60 ( V_101 -> V_113 , 4 ) == 0x1000 ) {
V_111 = 1 ;
} else if ( F_60 ( V_101 -> V_113 , 4 ) == 0xffff ) {
V_111 = 0 ;
} else {
return - 3 ;
}
if( F_60 ( V_101 -> V_113 , 6 ) != 0xffff ) {
return - 4 ;
}
V_106 = F_51 ( V_104 , V_69 , V_70 ,
F_61 ( V_101 -> V_113 , 16 , 8 ) ,
8 ,
V_107 ) ;
if ( V_106 ) {
return - 5 ;
}
{
T_23 V_114 ;
F_62 ( & V_114 , V_107 , sizeof( V_107 ) ) ;
F_63 ( V_101 -> V_113 , V_108 , 8 , 8 ) ;
F_64 ( & V_114 , ( T_20 * ) V_108 , 8 ) ;
memset ( V_107 , 0 , sizeof( V_107 ) ) ;
}
if ( V_108 [ 1 ] != 0xFFFFFFFF && V_108 [ 1 ] != 0x00000000 ) {
return - 6 ;
}
{
int V_100 ;
for ( V_100 = 0 ; V_100 < 16 ; V_100 ++ )
V_105 [ V_100 ] = ( ( T_20 * ) V_104 ) [ V_100 ] ^ 0xF0 ;
}
V_106 = F_51 ( V_105 , sizeof( V_105 ) , V_70 ,
( const T_20 * ) V_108 , 4 ,
V_107 ) ;
memset ( V_105 , 0 , sizeof( V_105 ) ) ;
if ( V_106 ) {
return - 7 ;
}
if( V_111 ) {
T_23 V_114 ;
F_62 ( & V_114 , V_107 , sizeof( V_107 ) ) ;
F_63 ( V_101 -> V_113 , V_109 , 24 , 8 ) ;
F_64 ( & V_114 , V_109 , 8 ) ;
memcpy ( V_103 , V_102 , V_96 ) ;
F_64 ( & V_114 , V_103 , V_96 ) ;
} else {
F_63 ( V_101 -> V_113 , V_109 , 24 , 8 ) ;
memcpy ( V_103 ,
V_102 ,
V_96 ) ;
}
memset ( V_107 , 0 , sizeof( V_107 ) ) ;
if( V_101 -> V_115 == V_116 ) {
V_106 = F_58 ( V_103 , V_96 , V_96 , & V_97 ) ;
if ( V_106 ) {
return - 9 ;
}
V_96 -= V_97 ;
}
if( V_101 -> V_115 == V_116 ) {
V_106 = F_54 ( V_104 , V_69 ,
V_117 ,
V_71 ,
F_61 ( V_101 -> V_113 , 0 , 8 ) , 8 ,
V_109 , sizeof( V_109 ) ,
V_103 ,
V_96 + V_97 ) ;
if ( V_106 ) {
return - 10 ;
}
V_110 = F_65 ( V_101 -> V_113 , 16 , V_71 , 8 ) ;
if ( V_110 ) {
return - 11 ;
}
}
return V_96 ;
}
static void
F_66 ( T_8 * T_9 V_1 , T_14 * V_9 , T_3 * T_4 , int V_118 , T_19 * V_101 )
{
int V_106 ;
T_24 * V_119 ;
int V_120 ;
const T_20 * V_121 ;
T_20 * V_122 = NULL ;
T_20 * V_103 ;
V_120 = F_44 ( V_101 -> V_112 ) ;
V_121 = F_61 ( V_101 -> V_112 , 0 , V_120 ) ;
V_122 = ( T_20 * ) F_67 ( F_68 () , V_120 ) ;
V_103 = ( T_20 * ) F_67 ( V_9 -> V_123 , V_120 ) ;
for( V_119 = V_124 ; V_119 ; V_119 = V_119 -> V_125 ) {
if( V_119 -> V_118 != V_118 ) {
continue;
}
memcpy ( V_122 , V_121 , V_120 ) ;
V_106 = F_59 ( V_101 ,
V_122 ,
V_103 ,
V_119 -> V_126 ,
V_119 -> V_127 ,
V_119 -> V_118 ) ;
if ( V_106 >= 0 ) {
F_69 ( V_9 , NULL , & V_128 ,
L_4 ,
V_119 -> V_118 , V_9 -> V_129 , V_119 -> V_130 ) ;
V_101 -> V_131 = F_70 ( T_4 ,
V_103 ,
V_106 , V_106 ) ;
F_71 ( V_9 , V_101 -> V_131 , L_5 ) ;
return;
}
}
}
static int
F_72 ( T_20 * V_43 , int V_35 , T_15 V_132 , int V_133 )
{
T_20 * V_134 , V_135 [ 256 ] ;
T_21 V_136 ;
if ( V_35 == 0 )
return 0 ;
V_132 %= V_35 ;
if ( V_132 == 0 )
return 0 ;
V_136 = V_35 - V_132 ;
if ( V_132 <= sizeof( V_135 ) ) {
V_134 = V_135 ;
} else {
V_134 = ( T_20 * ) F_73 ( V_132 ) ;
if ( V_134 == NULL )
return - 1 ;
}
if ( V_133 ) {
memcpy ( V_134 , V_43 , V_132 ) ;
memmove ( V_43 , V_43 + V_132 , V_136 ) ;
memcpy ( V_43 + V_136 , V_134 , V_132 ) ;
} else {
memcpy ( V_134 , V_43 + V_136 , V_132 ) ;
memmove ( V_43 + V_132 , V_43 , V_136 ) ;
memcpy ( V_43 , V_134 , V_132 ) ;
}
if ( V_132 > sizeof( V_135 ) )
F_74 ( V_134 ) ;
return 0 ;
}
static void
F_75 ( T_8 * T_9 ,
T_14 * V_9 ,
T_3 * V_137 ,
T_19 * V_101 ,
T_15 V_138 ,
T_15 V_132 ,
int V_118 ,
unsigned int V_78 )
{
T_20 * V_139 ;
T_20 * V_140 ;
int V_96 ;
T_3 * V_141 ;
if( ! V_142 ) {
return;
}
V_96 = F_44 ( V_137 ) + F_44 ( V_101 -> V_112 ) ;
V_139 = ( T_20 * ) F_67 ( V_9 -> V_123 , V_96 ) ;
F_63 ( V_137 , V_139 ,
0 , F_44 ( V_137 ) ) ;
F_63 ( V_101 -> V_112 , V_139 + F_44 ( V_137 ) ,
0 , F_44 ( V_101 -> V_112 ) ) ;
if ( V_101 -> V_115 == V_143 ) {
V_132 += V_138 ;
}
F_72 ( V_139 , V_96 , V_132 , TRUE ) ;
V_141 = F_70 ( V_101 -> V_112 , V_139 ,
V_96 , V_96 ) ;
F_71 ( V_9 , V_141 , L_6 ) ;
V_140 = F_76 ( T_9 , V_9 , V_78 , V_141 ,
V_118 , & V_96 ) ;
if ( V_140 ) {
T_20 * V_144 ;
V_144 = ( T_20 * ) F_77 ( V_140 , F_44 ( V_101 -> V_112 ) ) ;
F_74 ( V_140 ) ;
V_101 -> V_131 = F_70 ( V_101 -> V_112 ,
V_144 ,
F_44 ( V_101 -> V_112 ) ,
F_44 ( V_101 -> V_112 ) ) ;
F_71 ( V_9 , V_101 -> V_131 , L_5 ) ;
F_78 ( V_101 -> V_131 , F_74 ) ;
}
}
static int
F_47 ( T_3 * T_4 , int T_5 , T_14 * V_9
#ifndef F_79
V_1
#endif
, T_8 * T_9 , T_15 V_44
#ifndef F_79
V_1
#endif
, T_19 * V_101
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
if ( V_101 != NULL )
V_101 -> V_155 = ( V_146 != V_156 ) ;
#ifdef F_79
#define F_80 32
if( V_101 && V_101 -> V_115 ) {
if( ! V_101 -> V_112 ) {
int V_35 ;
V_35 = F_81 ( T_4 , T_5 ) ;
if( V_35 > F_82 ( T_4 , T_5 ) ) {
return T_5 ;
}
V_101 -> V_112 = F_83 (
T_4 , T_5 , V_35 ) ;
}
if( ( V_44 == V_64 )
&& ( V_145 == V_152 )
&& ( V_146 == V_157 ) ) {
if( ! V_101 -> V_113 ) {
V_101 -> V_113 = F_83 (
T_4 , V_147 - 2 ,
F_80 ) ;
}
#if F_84 ( V_158 ) || F_84 ( V_159 )
F_66 ( T_9 ,
V_9 ,
T_4 ,
V_160 ,
V_101 ) ;
#endif
}
}
#endif
return T_5 ;
}
static int
F_46 ( T_3 * T_4 , int T_5 , T_14 * V_9 V_1 , T_8 * T_9 )
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
T_8 * V_161 ,
T_20 T_25 V_1 )
{
static const int * V_162 [] = {
& V_163 ,
& V_164 ,
& V_165 ,
NULL
} ;
F_86 ( V_161 , T_4 , T_5 , V_166 , V_167 , V_162 , V_37 ) ;
return ( T_5 + 1 ) ;
}
static int
F_49 ( T_3 * T_4 , int T_5 , T_14 * V_9
#ifndef F_79
V_1
#endif
, T_8 * T_9 , T_15 V_44 V_1
, T_19 * V_101
)
{
T_20 V_162 ;
T_15 V_138 ;
#if F_84 ( V_158 ) || F_84 ( V_159 )
T_15 V_132 ;
#endif
int V_168 ;
int V_147 = T_5 ;
V_162 = F_87 ( T_4 , T_5 ) ;
T_5 = F_85 ( T_4 , T_5 , T_9 , V_162 ) ;
if ( V_101 != NULL )
V_101 -> V_155 = ( V_162 & 2 ) ;
F_30 ( T_9 , V_169 , T_4 , T_5 , 1 ,
V_37 ) ;
T_5 += 1 ;
V_138 = F_60 ( T_4 , T_5 ) ;
F_30 ( T_9 , V_170 , T_4 , T_5 , 2 ,
V_171 ) ;
T_5 += 2 ;
#if F_84 ( V_158 ) || F_84 ( V_159 )
V_132 = F_60 ( T_4 , T_5 ) ;
#endif
F_30 ( T_9 , V_172 , T_4 , T_5 , 2 ,
V_171 ) ;
T_5 += 2 ;
F_30 ( T_9 , V_173 , T_4 , T_5 , 8 ,
V_171 ) ;
T_5 += 8 ;
if ( V_101 == NULL )
return T_5 ;
if ( V_101 -> V_155 ) {
V_168 = 44 + V_138 ;
F_30 ( T_9 , V_151 , T_4 , T_5 ,
V_168 , V_37 ) ;
T_5 += V_168 ;
} else {
int V_174 ;
int V_175 = 0 ;
V_168 = V_138 ;
V_175 = F_81 ( T_4 , T_5 ) ;
if ( V_175 > V_138 ) {
V_175 -= V_138 ;
}
#if F_84 ( V_158 ) || F_84 ( V_159 )
if ( V_132 == V_138 ) {
F_30 ( T_9 , V_151 ,
T_4 , T_5 , V_168 , V_37 ) ;
T_5 += V_168 ;
}
#endif
V_174 = T_5 ;
V_101 -> V_113 = F_83 ( T_4 , T_5 ,
V_175 ) ;
T_5 += V_175 ;
#if F_84 ( V_158 ) || F_84 ( V_159 )
if ( V_132 == 0 )
#endif
{
F_30 ( T_9 , V_151 ,
T_4 , T_5 , V_168 , V_37 ) ;
}
return V_174 ;
}
if( V_101 -> V_115 ) {
if( ! V_101 -> V_112 ) {
int V_35 ;
V_35 = F_81 ( T_4 , T_5 ) ;
if( V_35 > F_82 ( T_4 , T_5 ) ) {
return T_5 ;
}
V_101 -> V_112 = F_88 (
T_4 , T_5 , V_35 , V_35 ) ;
}
if ( V_101 -> V_155 ) {
if( ! V_101 -> V_113 ) {
V_101 -> V_113 = F_83 (
T_4 , V_147 - 2 ,
T_5 - ( V_147 - 2 ) ) ;
}
}
}
#if F_84 ( V_158 ) || F_84 ( V_159 )
{
T_3 * V_137 = F_83 ( T_4 , 16 , V_168 ) ;
if ( V_101 -> V_155 ) {
if( V_101 -> V_112 ) {
F_75 ( T_9 ,
V_9 ,
V_137 ,
V_101 ,
V_138 ,
V_132 ,
- 1 ,
( V_162 & 0x0001 ) ?
V_176 :
V_177 ) ;
}
}
}
#endif
return T_5 ;
}
static int
F_48 ( T_3 * T_4 , int T_5 , T_14 * V_9 V_1 , T_8 * T_9 )
{
T_20 V_162 ;
int V_168 ;
V_162 = F_87 ( T_4 , T_5 ) ;
T_5 = F_85 ( T_4 , T_5 , T_9 , V_162 ) ;
F_30 ( T_9 , V_169 , T_4 , T_5 , 5 ,
V_37 ) ;
T_5 += 5 ;
F_30 ( T_9 , V_173 , T_4 , T_5 , 8 ,
V_171 ) ;
T_5 += 8 ;
V_168 = F_82 ( T_4 , T_5 ) ;
F_30 ( T_9 , V_151 , T_4 , T_5 ,
V_168 , V_37 ) ;
T_5 += V_168 ;
return T_5 ;
}
static int
F_89 ( T_3 * T_4 , T_14 * V_9 V_1 , T_8 * T_9 , void * V_43 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_15 V_44 ;
T_19 * V_51 = ( T_19 * ) V_43 ;
V_32 = F_30 ( T_9 , V_54 , T_4 , 0 , - 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_55 ) ;
V_44 = F_41 ( T_4 , T_5 ) ;
F_42 ( V_33 , V_57 , T_4 , T_5 , 2 ,
V_44 ) ;
T_5 += 2 ;
switch ( V_44 ) {
case V_63 :
T_5 = F_46 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_64 :
T_5 = F_47 ( T_4 , T_5 , V_9 , V_33 , V_44 , V_51 ) ;
break;
case V_66 :
T_5 = F_48 ( T_4 , T_5 , V_9 , V_33 ) ;
break;
case V_67 :
T_5 = F_49 ( T_4 , T_5 , V_9 , V_33 , V_44 , V_51 ) ;
break;
default:
break;
}
F_50 ( V_32 , T_5 ) ;
return T_5 ;
}
static int
F_90 ( T_3 * T_4 , T_14 * V_9 , T_8 * T_9 , void * V_43 V_1 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_6 V_52 ;
F_37 ( & V_52 , V_53 , TRUE , V_9 ) ;
V_3 = NULL ;
V_32 = F_30 ( T_9 , V_10 , T_4 , T_5 ,
- 1 , V_37 ) ;
V_33 = F_31 ( V_32 , V_178 ) ;
T_5 = F_34 ( FALSE , T_4 , T_5 , & V_52 , V_33 , - 1 ) ;
return T_5 ;
}
static int
F_91 ( T_3 * T_4 , T_14 * V_9 , T_8 * V_179 , void * V_43 V_1 )
{
T_13 * V_32 ;
T_8 * V_33 ;
int T_5 = 0 ;
T_12 * V_6 ;
T_6 V_52 ;
F_37 ( & V_52 , V_53 , TRUE , V_9 ) ;
V_5 = ( T_11 * ) F_92 ( F_93 () , V_9 , V_10 , 0 ) ;
if ( ! V_5 && ! V_9 -> V_180 -> V_162 . V_181 ) {
V_6 = F_94 ( V_9 -> V_129 , & V_9 -> V_182 , & V_9 -> V_183 ,
V_9 -> V_18 , V_9 -> V_20 ,
V_9 -> V_184 , 0 ) ;
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
F_24 ( FALSE , T_4 , T_5 , & V_52 , V_33 , - 1 ) ;
return F_44 ( T_4 ) ;
}
void F_97 ( void ) {
static T_26 V_185 [] = {
{ & V_36 ,
{ L_7 , L_8 ,
V_186 , V_187 , NULL , 0x0 , L_9 ,
V_188 } } ,
{ & V_54 ,
{ L_10 , L_11 , V_189 ,
V_187 , NULL , 0 , NULL , V_188 } } ,
{ & V_56 ,
{ L_12 , L_13 , V_190 ,
V_187 , NULL , 0 , NULL , V_188 } } ,
{ & V_57 ,
{ L_14 , L_15 , V_191 , V_192 ,
F_98 ( V_193 ) , 0 , L_16 , V_188 } } ,
{ & V_148 ,
{ L_17 , L_18 , V_191 , V_192 ,
F_98 ( V_194 ) , 0 , L_19 , V_188 } } ,
{ & V_149 ,
{ L_20 , L_21 , V_191 , V_192 ,
F_98 ( V_195 ) , 0 , L_22 , V_188 } } ,
{ & V_150 ,
{ L_23 , L_24 , V_189 , V_187 ,
NULL , 0 , L_25 , V_188 } } ,
{ & V_151 ,
{ L_26 , L_27 , V_189 , V_187 ,
NULL , 0 , L_28 , V_188 } } ,
{ & V_154 ,
{ L_29 , L_30 , V_189 , V_187 ,
NULL , 0 , L_31 , V_188 } } ,
{ & V_169 ,
{ L_32 , L_33 , V_189 , V_187 ,
NULL , 0 , L_34 , V_188 } } ,
{ & V_166 ,
{ L_35 , L_36 , V_196 , V_192 ,
NULL , 0 , L_37 , V_188 } } ,
{ & V_165 ,
{ L_38 , L_39 , V_197 , 8 ,
F_99 ( & V_198 ) , 0x01 , NULL , V_188 } } ,
{ & V_164 ,
{ L_40 , L_41 , V_197 , 8 ,
F_99 ( & V_198 ) , 0x02 , NULL , V_188 } } ,
{ & V_163 ,
{ L_42 , L_43 , V_197 , 8 ,
F_99 ( & V_198 ) , 0x04 , NULL , V_188 } } ,
{ & V_170 ,
{ L_44 , L_45 , V_191 , V_199 ,
NULL , 0 , L_46 , V_188 } } ,
{ & V_172 ,
{ L_47 , L_48 , V_191 , V_199 ,
NULL , 0 , L_49 , V_188 } } ,
{ & V_173 ,
{ L_50 , L_51 , V_200 , V_199 ,
NULL , 0 , L_52 , V_188 } } ,
#line 1 "./asn1/spnego/packet-spnego-hfarr.c"
{ & V_201 ,
{ L_53 , L_54 ,
V_186 , V_187 , NULL , 0 ,
NULL , V_188 } } ,
{ & V_202 ,
{ L_55 , L_56 ,
V_186 , V_187 , NULL , 0 ,
NULL , V_188 } } ,
{ & V_203 ,
{ L_57 , L_58 ,
V_204 , V_187 , NULL , 0 ,
NULL , V_188 } } ,
{ & V_205 ,
{ L_59 , L_60 ,
V_206 , V_199 , NULL , 0 ,
L_61 , V_188 } } ,
{ & V_207 ,
{ L_62 , L_63 ,
V_189 , V_187 , NULL , 0 ,
L_64 , V_188 } } ,
{ & V_208 ,
{ L_65 , L_66 ,
V_189 , V_187 , NULL , 0 ,
NULL , V_188 } } ,
{ & V_209 ,
{ L_67 , L_68 ,
V_189 , V_187 , NULL , 0 ,
L_69 , V_188 } } ,
{ & V_210 ,
{ L_70 , L_71 ,
V_190 , V_187 , NULL , 0 ,
L_72 , V_188 } } ,
{ & V_211 ,
{ L_73 , L_74 ,
V_189 , V_187 , NULL , 0 ,
L_69 , V_188 } } ,
{ & V_212 ,
{ L_65 , L_66 ,
V_189 , V_187 , NULL , 0 ,
L_69 , V_188 } } ,
{ & V_213 ,
{ L_75 , L_76 ,
V_186 , V_187 , NULL , 0 ,
NULL , V_188 } } ,
{ & V_214 ,
{ L_77 , L_78 ,
V_206 , V_199 , F_98 ( V_215 ) , 0 ,
NULL , V_188 } } ,
{ & V_216 ,
{ L_79 , L_80 ,
V_204 , V_187 , NULL , 0 ,
NULL , V_188 } } ,
{ & V_217 ,
{ L_81 , L_82 ,
V_189 , V_187 , NULL , 0 ,
NULL , V_188 } } ,
{ & V_218 ,
{ L_83 , L_84 ,
V_204 , V_187 , NULL , 0 ,
L_57 , V_188 } } ,
{ & V_219 ,
{ L_85 , L_86 ,
V_186 , V_187 , NULL , 0 ,
NULL , V_188 } } ,
{ & V_220 ,
{ L_87 , L_88 ,
V_197 , 8 , NULL , 0x80 ,
NULL , V_188 } } ,
{ & V_221 ,
{ L_89 , L_90 ,
V_197 , 8 , NULL , 0x40 ,
NULL , V_188 } } ,
{ & V_222 ,
{ L_91 , L_92 ,
V_197 , 8 , NULL , 0x20 ,
NULL , V_188 } } ,
{ & V_223 ,
{ L_93 , L_94 ,
V_197 , 8 , NULL , 0x10 ,
NULL , V_188 } } ,
{ & V_224 ,
{ L_95 , L_96 ,
V_197 , 8 , NULL , 0x08 ,
NULL , V_188 } } ,
{ & V_225 ,
{ L_97 , L_98 ,
V_197 , 8 , NULL , 0x04 ,
NULL , V_188 } } ,
{ & V_226 ,
{ L_99 , L_100 ,
V_197 , 8 , NULL , 0x02 ,
NULL , V_188 } } ,
#line 1417 "./asn1/spnego/packet-spnego-template.c"
} ;
static T_27 * V_227 [] = {
& V_178 ,
& V_38 ,
& V_55 ,
& V_167 ,
#line 1 "./asn1/spnego/packet-spnego-ettarr.c"
& V_25 ,
& V_8 ,
& V_16 ,
& V_28 ,
& V_30 ,
& V_12 ,
& V_23 ,
& V_41 ,
#line 1427 "./asn1/spnego/packet-spnego-template.c"
} ;
static T_28 V_228 [] = {
{ & V_128 , { L_101 , V_229 , V_230 , L_102 , V_231 } } ,
{ & V_58 , { L_103 , V_232 , V_233 , L_104 , V_231 } } ,
} ;
T_29 * V_234 ;
V_10 = F_100 ( V_235 , V_236 , V_237 ) ;
F_101 ( L_105 , F_91 , V_10 ) ;
V_238 = F_100 ( L_106 ,
L_106 ,
L_107 ) ;
F_101 ( L_107 , F_36 , V_238 ) ;
F_101 ( L_108 , F_89 , V_238 ) ;
F_102 ( V_10 , V_185 , F_103 ( V_185 ) ) ;
F_104 ( V_227 , F_103 ( V_227 ) ) ;
V_234 = F_105 ( V_10 ) ;
F_106 ( V_234 , V_228 , F_103 ( V_228 ) ) ;
}
void F_107 ( void ) {
T_30 V_239 , V_240 ;
T_30 V_241 , V_242 ;
V_239 = F_108 ( L_105 ) ;
V_240 = F_109 ( F_90 , V_10 ) ;
F_110 ( L_109 , V_10 , V_178 ,
V_239 , V_240 ,
L_110 ) ;
V_241 = F_108 ( L_107 ) ;
V_242 = F_108 ( L_108 ) ;
F_110 ( L_111 , V_238 , V_55 ,
V_241 , V_242 ,
L_112 ) ;
F_110 ( L_113 , V_238 , V_55 ,
V_241 , V_242 ,
L_114 ) ;
F_110 ( L_115 , V_238 , V_55 ,
V_241 , V_242 ,
L_116 ) ;
}
