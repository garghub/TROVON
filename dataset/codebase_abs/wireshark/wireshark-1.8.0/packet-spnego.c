static int
F_1 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 23 "../../asn1/spnego/spnego.cnf"
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
#line 91 "../../asn1/spnego/spnego.cnf"
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
#line 112 "../../asn1/spnego/spnego.cnf"
T_3 * V_13 = NULL ;
T_5 = F_11 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_13 ) ;
if ( V_13 && V_5 )
F_12 ( V_5 -> V_14 , V_13 , T_7 -> V_9 , T_9 ) ;
return T_5 ;
}
static int
F_13 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 126 "../../asn1/spnego/spnego.cnf"
T_13 V_15 ;
T_1 V_16 ;
T_14 V_17 ;
T_3 * V_18 ;
F_14 ( T_4 , T_5 , & V_15 , & V_16 , & V_17 ) ;
if ( V_15 == V_19 && V_16 && V_17 == V_20 ) {
return F_15 ( FALSE , T_4 , T_5 , T_7 , T_9 ,
V_21 ) ;
} else {
T_5 = F_11 ( FALSE , T_7 , T_9 , T_4 , T_5 ,
V_21 , & V_18 ) ;
if ( V_18 && V_5 )
F_12 ( V_5 -> V_14 , V_18 , T_7 -> V_9 , T_9 ) ;
return T_5 ;
}
return T_5 ;
}
static int
F_16 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_17 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_22 , T_10 , V_23 ) ;
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
#line 164 "../../asn1/spnego/spnego.cnf"
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
#line 187 "../../asn1/spnego/spnego.cnf"
T_3 * V_24 ;
T_5 = F_11 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_24 ) ;
if ( V_24 && ( F_22 ( V_24 ) > 0 ) ) {
T_11 * V_2 = V_5 ;
if( V_2 ) {
F_12 ( V_2 -> V_14 , V_24 , T_7 -> V_9 , T_9 ) ;
}
}
return T_5 ;
}
static int
F_23 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 214 "../../asn1/spnego/spnego.cnf"
T_3 * V_18 ;
T_5 = F_11 ( T_2 , T_7 , T_9 , T_4 , T_5 , T_10 ,
& V_18 ) ;
if ( V_18 && ( F_22 ( V_18 ) > 0 ) ) {
T_11 * V_2 = V_5 ;
if( V_2 ) {
F_12 ( V_2 -> V_14 , V_18 , T_7 -> V_9 , T_9 ) ;
}
}
return T_5 ;
}
static int
F_24 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_17 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_25 , T_10 , V_26 ) ;
return T_5 ;
}
static int
F_25 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_26 ( T_7 , T_9 , T_4 , T_5 ,
V_27 , T_10 , V_28 ,
NULL ) ;
return T_5 ;
}
static int
F_27 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_28 ( T_2 , V_29 ,
T_7 , T_9 , T_4 , T_5 , T_10 ,
NULL ) ;
return T_5 ;
}
static int
F_15 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_17 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_30 , T_10 , V_31 ) ;
return T_5 ;
}
static int
F_29 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
#line 48 "../../asn1/spnego/spnego.cnf"
T_11 * V_32 ;
T_15 * V_33 ;
T_8 * V_34 ;
T_3 * V_35 ;
int V_36 ;
V_32 = F_3 ( V_3 ) ;
V_33 = F_30 ( T_9 , V_37 , T_4 , T_5 , - 1 , V_38 ) ;
V_34 = F_31 ( V_33 , V_39 ) ;
V_35 = F_32 ( T_4 , T_5 ) ;
if ( V_32 && V_32 -> V_40 ) {
V_36 = F_12 ( V_32 -> V_40 , V_35 , T_7 -> V_9 ,
V_34 ) ;
if ( V_36 == 0 )
T_5 = F_33 ( T_4 ) ;
else
T_5 = T_5 + V_36 ;
} else
T_5 = F_33 ( T_4 ) ;
return T_5 ;
}
static int
F_34 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_17 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
V_41 , T_10 , V_42 ) ;
return T_5 ;
}
static int
F_35 ( T_1 T_2 V_1 , T_3 * T_4 V_1 , int T_5 V_1 , T_6 * T_7 V_1 , T_8 * T_9 V_1 , int T_10 V_1 ) {
T_5 = F_36 ( T_2 , T_7 , T_9 , T_4 , T_5 ,
T_10 , V_43 , 0 , TRUE , F_34 ) ;
return T_5 ;
}
static void
F_37 ( T_3 * T_4 , T_16 * V_9 , T_8 * T_9 )
{
T_15 * V_33 ;
T_8 * V_34 ;
int T_5 = 0 ;
T_17 V_44 ;
const char * V_45 ;
T_3 * V_46 ;
T_13 V_15 ;
T_1 V_16 , V_47 = 0 ;
T_14 V_17 ;
T_18 V_36 ;
T_6 V_48 ;
F_38 ( & V_48 , V_49 , TRUE , V_9 ) ;
V_33 = F_30 ( T_9 , V_50 , T_4 , T_5 ,
- 1 , V_38 ) ;
V_34 = F_31 ( V_33 , V_51 ) ;
F_14 ( T_4 , T_5 , & V_15 , & V_16 , & V_17 ) ;
if ( V_15 == V_43 && V_16 ) {
T_5 = F_39 ( V_9 , V_34 , T_4 , T_5 , & V_15 , & V_16 , & V_17 ) ;
T_5 = F_40 ( V_9 , V_34 , T_4 , T_5 , & V_36 , & V_47 ) ;
switch ( V_17 ) {
case 0 :
T_5 = F_2 ( FALSE , & V_48 , V_34 , T_4 , T_5 , V_52 , & V_45 ) ;
V_44 = F_41 ( T_4 , T_5 ) ;
F_42 ( V_34 , V_53 , T_4 , T_5 , 2 ,
V_44 ) ;
T_5 += 2 ;
break;
case 14 :
case 15 :
F_43 ( T_4 , V_9 , V_34 , FALSE , NULL ) ;
return;
default:
F_44 ( V_34 , T_4 , T_5 , 0 ,
L_1 ,
V_15 , V_16 , V_17 ) ;
goto V_54;
}
} else {
V_44 = F_41 ( T_4 , T_5 ) ;
F_42 ( V_34 , V_53 , T_4 , T_5 , 2 ,
V_44 ) ;
T_5 += 2 ;
}
switch ( V_44 ) {
case V_55 :
case V_56 :
case V_57 :
V_46 = F_32 ( T_4 , T_5 ) ;
T_5 = F_43 ( V_46 , V_9 , V_34 , FALSE , NULL ) ;
break;
case V_58 :
T_5 = F_45 ( T_4 , T_5 , V_9 , V_34 ) ;
break;
case V_59 :
T_5 = F_46 ( T_4 , T_5 , V_9 , V_34 , V_44 ) ;
break;
case V_60 :
break;
case V_61 :
T_5 = F_47 ( T_4 , T_5 , V_9 , V_34 ) ;
break;
case V_62 :
T_5 = F_48 ( T_4 , T_5 , V_9 , V_34 , V_44 ) ;
break;
default:
break;
}
V_54:
F_49 ( V_33 , T_5 ) ;
return;
}
static int
F_50 ( void * V_63 , T_19 V_64 , int V_65 ,
void * V_66 , T_19 V_67 ,
void * V_68 )
{
T_20 V_69 [ 16 ] ;
T_20 V_70 [ 4 ] ;
memset ( V_70 , 0 , 4 ) ;
if ( V_65 == V_71 ) {
T_20 V_72 [ 14 ] = L_2 ;
memcpy ( V_72 + 10 , V_70 , sizeof( V_70 ) ) ;
F_51 (
V_72 , 14 ,
V_63 ,
V_64 ,
V_69 ) ;
memset ( & V_69 [ 7 ] , 0xAB , 9 ) ;
} else {
F_51 (
V_70 , 4 ,
V_63 ,
V_64 ,
V_69 ) ;
}
F_51 (
V_66 , V_67 ,
V_69 ,
16 ,
V_68 ) ;
return 0 ;
}
static int
F_52 ( int V_73 )
{
switch ( V_73 ) {
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
F_53 ( T_20 * V_63 , int V_74 ,
unsigned V_73 ,
T_20 V_75 [ 8 ] ,
const void * V_76 , T_19 V_77 ,
const void * V_78 , T_19 V_79 ,
const void * V_80 , T_19 V_81 )
{
const T_20 V_82 [] = L_3 ;
T_20 V_83 [ 16 ] ;
unsigned char V_84 [ 4 ] ;
T_21 V_85 ;
unsigned char V_86 [ 16 ] ;
int V_87 ;
T_20 V_88 [ 16 ] ;
V_87 = F_52 ( V_73 ) ;
F_51 ( V_82 , sizeof( V_82 ) ,
V_63 , V_74 ,
V_83 ) ;
F_54 ( & V_85 ) ;
V_84 [ 0 ] = ( V_87 >> 0 ) & 0xFF ;
V_84 [ 1 ] = ( V_87 >> 8 ) & 0xFF ;
V_84 [ 2 ] = ( V_87 >> 16 ) & 0xFF ;
V_84 [ 3 ] = ( V_87 >> 24 ) & 0xFF ;
F_55 ( & V_85 , V_84 , 4 ) ;
F_55 ( & V_85 , V_76 , V_77 ) ;
F_55 ( & V_85 , V_78 , V_79 ) ;
F_55 ( & V_85 , V_80 , V_81 ) ;
F_56 ( & V_85 , V_86 ) ;
F_51 ( V_86 , 16 , V_83 , 16 , V_88 ) ;
memcpy ( V_75 , V_88 , 8 ) ;
return 0 ;
}
static int
F_57 ( unsigned char * V_89 , int V_90 ,
T_19 V_91 ,
T_19 * V_92 )
{
unsigned char * V_93 ;
T_19 V_94 ;
int V_95 ;
V_93 = V_89 + V_90 - 1 ;
V_94 = * V_93 ;
if ( V_94 > V_91 )
return 1 ;
for ( V_95 = V_94 ; V_95 > 0 && * V_93 == V_94 ; V_95 -- , V_93 -- )
;
if ( V_95 != 0 )
return 2 ;
* V_92 = V_94 ;
return 0 ;
}
static int
F_58 ( T_16 * V_9 ,
T_20 * V_96 ,
T_20 * V_97 ,
T_20 * V_98 , int V_64 , int V_65 )
{
T_20 V_99 [ 16 ] ;
int V_100 ;
T_19 V_91 ;
T_20 V_101 [ 16 ] ;
T_18 V_102 [ 2 ] ;
T_20 V_103 [ 8 ] ;
T_20 V_66 [ 8 ] ;
int V_104 ;
int V_105 ;
T_19 V_92 = 0 ;
V_91 = F_33 ( V_9 -> V_106 ) ;
if( F_59 ( V_9 -> V_107 , 4 ) == 0x1000 ) {
V_105 = 1 ;
} else if ( F_59 ( V_9 -> V_107 , 4 ) == 0xffff ) {
V_105 = 0 ;
} else {
return - 3 ;
}
if( F_59 ( V_9 -> V_107 , 6 ) != 0xffff ) {
return - 4 ;
}
V_100 = F_50 ( V_98 , V_64 , V_65 ,
( void * ) F_60 ( V_9 -> V_107 , 16 , 8 ) ,
8 ,
V_101 ) ;
if ( V_100 ) {
return - 5 ;
}
{
T_22 V_108 ;
F_61 ( & V_108 , V_101 , sizeof( V_101 ) ) ;
F_62 ( V_9 -> V_107 , V_102 , 8 , 8 ) ;
F_63 ( & V_108 , ( unsigned char * ) V_102 , 8 ) ;
memset ( V_101 , 0 , sizeof( V_101 ) ) ;
}
if ( V_102 [ 1 ] != 0xFFFFFFFF && V_102 [ 1 ] != 0x00000000 ) {
return - 6 ;
}
{
int V_95 ;
for ( V_95 = 0 ; V_95 < 16 ; V_95 ++ )
V_99 [ V_95 ] = ( ( T_20 * ) V_98 ) [ V_95 ] ^ 0xF0 ;
}
V_100 = F_50 ( V_99 , sizeof( V_99 ) , V_65 ,
( unsigned char * ) V_102 , 4 ,
V_101 ) ;
memset ( V_99 , 0 , sizeof( V_99 ) ) ;
if ( V_100 ) {
return - 7 ;
}
if( V_105 ) {
T_22 V_108 ;
F_61 ( & V_108 , V_101 , sizeof( V_101 ) ) ;
F_62 ( V_9 -> V_107 , V_103 , 24 , 8 ) ;
F_63 ( & V_108 , V_103 , 8 ) ;
memcpy ( V_97 , V_96 , V_91 ) ;
F_63 ( & V_108 , V_97 , V_91 ) ;
} else {
F_62 ( V_9 -> V_107 , V_103 , 24 , 8 ) ;
memcpy ( V_97 ,
V_96 ,
V_91 ) ;
}
memset ( V_101 , 0 , sizeof( V_101 ) ) ;
if( V_9 -> V_109 == V_110 ) {
V_100 = F_57 ( V_97 , V_91 , V_91 , & V_92 ) ;
if ( V_100 ) {
return - 9 ;
}
V_91 -= V_92 ;
}
if( V_9 -> V_109 == V_110 ) {
V_100 = F_53 ( V_98 , V_64 ,
V_111 ,
V_66 ,
F_60 ( V_9 -> V_107 , 0 , 8 ) , 8 ,
V_103 , sizeof( V_103 ) ,
V_97 ,
V_91 + V_92 ) ;
if ( V_100 ) {
return - 10 ;
}
V_104 = F_64 ( V_9 -> V_107 , 16 , V_66 , 8 ) ;
if ( V_104 ) {
return - 11 ;
}
}
return V_91 ;
}
static void
F_65 ( T_8 * T_9 , T_16 * V_9 , T_3 * T_4 , int V_112 )
{
int V_100 ;
T_23 * V_113 ;
int V_114 ;
const T_20 * V_115 ;
static int V_116 = 0 ;
static T_20 * V_117 [ 4 ] = { NULL , NULL , NULL , NULL } ;
static T_20 * V_118 = NULL ;
T_20 * V_97 ;
V_116 ++ ;
if( V_116 >= 4 ) {
V_116 = 0 ;
}
V_97 = V_117 [ V_116 ] ;
V_114 = F_33 ( V_9 -> V_106 ) ;
V_115 = F_60 ( V_9 -> V_106 , 0 , V_114 ) ;
V_118 = F_66 ( V_114 ) ;
if( V_97 ) {
F_67 ( V_97 ) ;
V_97 = NULL ;
}
V_97 = F_68 ( V_114 ) ;
for( V_113 = V_119 ; V_113 ; V_113 = V_113 -> V_120 ) {
if( V_113 -> V_112 != V_112 ) {
continue;
}
memcpy ( V_118 , V_115 , V_114 ) ;
V_100 = F_58 ( V_9 ,
V_118 ,
V_97 ,
V_113 -> V_121 ,
V_113 -> V_122 ,
V_113 -> V_112
) ;
if ( V_100 >= 0 ) {
F_44 ( T_9 , NULL , 0 , 0 , L_4 , V_113 -> V_123 ) ;
V_9 -> V_124 = F_69 ( T_4 ,
V_97 ,
V_100 , V_100 ) ;
F_70 ( V_9 -> V_124 , F_67 ) ;
F_71 ( V_9 , V_9 -> V_124 , L_5 ) ;
return;
}
}
return;
}
static int
F_72 ( void * V_125 , int V_36 , T_17 V_126 , int V_127 )
{
unsigned char * V_128 , V_129 [ 256 ] ;
T_19 V_130 ;
if ( V_36 == 0 )
return 0 ;
V_126 %= V_36 ;
if ( V_126 == 0 )
return 0 ;
V_130 = V_36 - V_126 ;
if ( V_126 <= sizeof( V_129 ) ) {
V_128 = V_129 ;
} else {
V_128 = F_68 ( V_126 ) ;
if ( V_128 == NULL )
return - 1 ;
}
if ( V_127 ) {
memcpy ( V_128 , V_125 , V_126 ) ;
memmove ( V_125 , ( unsigned char * ) V_125 + V_126 , V_130 ) ;
memcpy ( ( unsigned char * ) V_125 + V_130 , V_128 , V_126 ) ;
} else {
memcpy ( V_128 , ( unsigned char * ) V_125 + V_130 , V_126 ) ;
memmove ( ( unsigned char * ) V_125 + V_126 , V_125 , V_130 ) ;
memcpy ( V_125 , V_128 , V_126 ) ;
}
if ( V_126 > sizeof( V_129 ) )
F_67 ( V_128 ) ;
return 0 ;
}
static void
F_73 ( T_8 * T_9 V_1 ,
T_16 * V_9 ,
T_3 * V_131 ,
T_3 * V_132 ,
T_17 V_133 ,
T_17 V_126 ,
T_1 V_134 ,
int V_112 ,
unsigned int V_73 )
{
T_20 * V_135 ;
T_20 * V_136 ;
int V_91 ;
T_3 * V_137 ;
if( ! V_138 ) {
return;
}
V_91 = F_33 ( V_131 ) + F_33 ( V_132 ) ;
V_135 = F_68 ( V_91 ) ;
F_62 ( V_131 , V_135 ,
0 , F_33 ( V_131 ) ) ;
F_62 ( V_132 , V_135 + F_33 ( V_131 ) ,
0 , F_33 ( V_132 ) ) ;
if ( V_134 ) {
V_126 += V_133 ;
}
F_72 ( V_135 , V_91 , V_126 , TRUE ) ;
V_137 = F_69 ( V_132 , V_135 ,
V_91 , V_91 ) ;
F_70 ( V_137 , F_67 ) ;
F_71 ( V_9 , V_137 , L_6 ) ;
V_136 = F_74 ( T_9 , V_9 , V_73 , V_137 ,
V_112 , & V_91 ) ;
if ( V_136 ) {
T_20 * V_139 ;
V_139 = F_75 ( V_136 , F_33 ( V_132 ) ) ;
F_67 ( V_136 ) ;
V_9 -> V_124 = F_69 ( V_132 ,
V_139 ,
F_33 ( V_132 ) ,
F_33 ( V_132 ) ) ;
F_71 ( V_9 , V_9 -> V_124 , L_5 ) ;
F_70 ( V_9 -> V_124 , F_67 ) ;
return;
}
return;
}
static int
F_46 ( T_3 * T_4 , int T_5 , T_16 * V_9
#ifndef F_76
V_1
#endif
, T_8 * T_9 , T_17 V_44
#ifndef F_76
V_1
#endif
)
{
T_17 V_140 , V_141 ;
#ifdef F_76
int V_142 = T_5 ;
#endif
V_140 = F_41 ( T_4 , T_5 ) ;
F_42 ( T_9 , V_143 , T_4 , T_5 , 2 ,
V_140 ) ;
T_5 += 2 ;
V_141 = F_41 ( T_4 , T_5 ) ;
F_42 ( T_9 , V_144 , T_4 , T_5 , 2 ,
V_141 ) ;
T_5 += 2 ;
T_5 += 2 ;
F_30 ( T_9 , V_145 , T_4 , T_5 , 8 ,
V_38 ) ;
T_5 += 8 ;
F_30 ( T_9 , V_146 , T_4 , T_5 , 8 ,
V_38 ) ;
T_5 += 8 ;
if ( ( V_140 == V_147 ) ||
( V_140 == V_148 ) ) {
F_30 ( T_9 , V_149 , T_4 , T_5 , 8 ,
V_38 ) ;
T_5 += 8 ;
}
V_9 -> V_150 = ( V_141 != V_151 ) ;
#ifdef F_76
#define F_77 32
if( V_9 -> V_109 ) {
if( ! V_9 -> V_106 ) {
int V_36 ;
V_36 = F_78 ( T_4 , T_5 ) ;
if( V_36 > F_79 ( T_4 , T_5 ) ) {
return T_5 ;
}
V_9 -> V_106 = F_80 (
T_4 , T_5 , V_36 , V_36 ) ;
}
if( ( V_44 == V_59 )
&& ( V_140 == V_147 )
&& ( V_141 == V_152 ) ) {
if( ! V_9 -> V_107 ) {
V_9 -> V_107 = F_80 (
T_4 , V_142 - 2 ,
F_77 ,
F_77 ) ;
}
#if F_81 ( V_153 ) || F_81 ( V_154 )
F_65 ( T_9 ,
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
F_45 ( T_3 * T_4 , int T_5 , T_16 * V_9 V_1 , T_8 * T_9 )
{
T_17 V_140 ;
V_140 = F_41 ( T_4 , T_5 ) ;
F_42 ( T_9 , V_143 , T_4 , T_5 , 2 ,
V_140 ) ;
T_5 += 2 ;
T_5 += 4 ;
F_30 ( T_9 , V_145 , T_4 , T_5 , 8 ,
V_38 ) ;
T_5 += 8 ;
F_30 ( T_9 , V_146 , T_4 , T_5 , 8 ,
V_38 ) ;
T_5 += 8 ;
if ( F_79 ( T_4 , T_5 ) ) {
if ( V_140 == V_147 ) {
F_30 ( T_9 , V_149 , T_4 , T_5 , 8 ,
V_38 ) ;
T_5 += 8 ;
}
}
return T_5 ;
}
static int
F_82 ( T_3 * T_4 , int T_5 ,
T_8 * V_155 ,
T_20 V_156 )
{
T_8 * V_157 = NULL ;
T_15 * V_158 = NULL ;
if ( V_155 ) {
V_158 = F_42 ( V_155 ,
V_159 ,
T_4 , T_5 , 1 , V_156 ) ;
V_157 = F_31 ( V_158 , V_160 ) ;
}
F_83 ( V_157 ,
V_161 ,
T_4 , T_5 , 1 , V_156 ) ;
F_83 ( V_157 ,
V_162 ,
T_4 , T_5 , 1 , V_156 ) ;
F_83 ( V_157 ,
V_163 ,
T_4 , T_5 , 1 , V_156 ) ;
return ( T_5 + 1 ) ;
}
static int
F_48 ( T_3 * T_4 , int T_5 , T_16 * V_9
#ifndef F_76
V_1
#endif
, T_8 * T_9 , T_17 V_44 V_1
)
{
T_20 V_164 ;
T_17 V_133 ;
#if F_81 ( V_153 ) || F_81 ( V_154 )
T_17 V_126 ;
#endif
int V_165 ;
int V_142 = T_5 ;
V_164 = F_84 ( T_4 , T_5 ) ;
T_5 = F_82 ( T_4 , T_5 , T_9 , V_164 ) ;
V_9 -> V_150 = ( V_164 & 2 ) ;
F_30 ( T_9 , V_166 , T_4 , T_5 , 1 ,
V_38 ) ;
T_5 += 1 ;
V_133 = F_59 ( T_4 , T_5 ) ;
F_30 ( T_9 , V_167 , T_4 , T_5 , 2 ,
V_168 ) ;
T_5 += 2 ;
#if F_81 ( V_153 ) || F_81 ( V_154 )
V_126 = F_59 ( T_4 , T_5 ) ;
#endif
F_30 ( T_9 , V_169 , T_4 , T_5 , 2 ,
V_168 ) ;
T_5 += 2 ;
F_30 ( T_9 , V_170 , T_4 , T_5 , 8 ,
V_168 ) ;
T_5 += 8 ;
if ( V_9 -> V_150 ) {
V_165 = 44 + V_133 ;
} else {
V_165 = 12 ;
}
F_30 ( T_9 , V_146 , T_4 , T_5 ,
V_165 , V_38 ) ;
T_5 += V_165 ;
if( V_9 -> V_109 ) {
if( ! V_9 -> V_106 ) {
int V_36 ;
V_36 = F_78 ( T_4 , T_5 ) ;
if( V_36 > F_79 ( T_4 , T_5 ) ) {
return T_5 ;
}
V_9 -> V_106 = F_80 (
T_4 , T_5 , V_36 , V_36 ) ;
}
if ( V_9 -> V_150 ) {
if( ! V_9 -> V_107 ) {
V_9 -> V_107 = F_80 (
T_4 , V_142 - 2 ,
T_5 - ( V_142 - 2 ) ,
T_5 - ( V_142 - 2 ) ) ;
}
}
}
#if F_81 ( V_153 ) || F_81 ( V_154 )
{
T_3 * V_131 = F_80 ( T_4 , 16 , V_165 , V_165 ) ;
if ( V_9 -> V_150 ) {
if( V_9 -> V_106 ) {
F_73 ( T_9 ,
V_9 ,
V_131 ,
V_9 -> V_106 ,
V_133 ,
V_126 ,
( V_9 -> V_109 == V_171 ) ? TRUE : FALSE ,
- 1 ,
( V_164 & 0x0001 ) ?
V_172 :
V_173 ) ;
}
}
}
#endif
return T_5 ;
}
static int
F_47 ( T_3 * T_4 , int T_5 , T_16 * V_9 V_1 , T_8 * T_9 )
{
T_20 V_164 ;
int V_165 ;
V_164 = F_84 ( T_4 , T_5 ) ;
T_5 = F_82 ( T_4 , T_5 , T_9 , V_164 ) ;
F_30 ( T_9 , V_166 , T_4 , T_5 , 5 ,
V_38 ) ;
T_5 += 5 ;
F_30 ( T_9 , V_170 , T_4 , T_5 , 8 ,
V_168 ) ;
T_5 += 8 ;
V_165 = F_79 ( T_4 , T_5 ) ;
F_30 ( T_9 , V_146 , T_4 , T_5 ,
V_165 , V_38 ) ;
T_5 += V_165 ;
return T_5 ;
}
static int
F_85 ( T_3 * T_4 , T_16 * V_9 V_1 , T_8 * T_9 )
{
T_15 * V_33 ;
T_8 * V_34 ;
int T_5 = 0 ;
T_17 V_44 ;
V_33 = F_30 ( T_9 , V_50 , T_4 , 0 , - 1 , V_38 ) ;
V_34 = F_31 ( V_33 , V_51 ) ;
V_44 = F_41 ( T_4 , T_5 ) ;
F_42 ( V_34 , V_53 , T_4 , T_5 , 2 ,
V_44 ) ;
T_5 += 2 ;
switch ( V_44 ) {
case V_58 :
T_5 = F_45 ( T_4 , T_5 , V_9 , V_34 ) ;
break;
case V_59 :
T_5 = F_46 ( T_4 , T_5 , V_9 , V_34 , V_44 ) ;
break;
case V_61 :
T_5 = F_47 ( T_4 , T_5 , V_9 , V_34 ) ;
break;
case V_62 :
T_5 = F_48 ( T_4 , T_5 , V_9 , V_34 , V_44 ) ;
break;
default:
break;
}
F_49 ( V_33 , T_5 ) ;
return T_5 ;
}
static int
F_86 ( T_3 * T_4 , T_16 * V_9 , T_8 * T_9 )
{
T_15 * V_33 ;
T_8 * V_34 ;
int T_5 = 0 ;
T_6 V_48 ;
F_38 ( & V_48 , V_49 , TRUE , V_9 ) ;
V_3 = NULL ;
V_33 = F_30 ( T_9 , V_10 , T_4 , T_5 ,
- 1 , V_38 ) ;
V_34 = F_31 ( V_33 , V_174 ) ;
T_5 = F_35 ( FALSE , T_4 , T_5 , & V_48 , V_34 , - 1 ) ;
return T_5 ;
}
static void
F_87 ( T_3 * T_4 , T_16 * V_9 , T_8 * V_175 )
{
T_15 * V_33 ;
T_8 * V_34 ;
int T_5 = 0 ;
T_12 * V_6 ;
T_6 V_48 ;
F_38 ( & V_48 , V_49 , TRUE , V_9 ) ;
V_5 = F_88 ( V_9 -> V_176 , V_10 ) ;
if ( ! V_5 && ! V_9 -> V_176 -> V_164 . V_177 ) {
V_6 = F_89 ( V_9 -> V_176 -> V_178 , & V_9 -> V_179 , & V_9 -> V_180 ,
V_9 -> V_181 , V_9 -> V_182 ,
V_9 -> V_183 , 0 ) ;
if ( V_6 ) {
V_5 = F_90 ( V_6 ,
V_10 ) ;
if ( V_5 )
F_91 ( V_9 -> V_176 , V_10 , V_5 ) ;
}
}
V_33 = F_30 ( V_175 , V_10 , T_4 , T_5 ,
- 1 , V_38 ) ;
V_34 = F_31 ( V_33 , V_174 ) ;
T_5 = F_25 ( FALSE , T_4 , T_5 , & V_48 , V_34 , - 1 ) ;
}
void F_92 ( void ) {
static T_24 V_184 [] = {
{ & V_37 ,
{ L_7 , L_8 ,
V_185 , V_186 , NULL , 0x0 , L_9 ,
V_187 } } ,
{ & V_50 ,
{ L_10 , L_11 , V_188 ,
V_186 , NULL , 0 , NULL , V_187 } } ,
{ & V_52 ,
{ L_12 , L_13 , V_189 ,
V_186 , NULL , 0 , NULL , V_187 } } ,
{ & V_53 ,
{ L_14 , L_15 , V_190 , V_191 ,
F_93 ( V_192 ) , 0 , L_16 , V_187 } } ,
{ & V_143 ,
{ L_17 , L_18 , V_190 , V_191 ,
F_93 ( V_193 ) , 0 , L_19 , V_187 } } ,
{ & V_144 ,
{ L_20 , L_21 , V_190 , V_191 ,
F_93 ( V_194 ) , 0 , L_22 , V_187 } } ,
{ & V_145 ,
{ L_23 , L_24 , V_188 , V_186 ,
NULL , 0 , L_25 , V_187 } } ,
{ & V_146 ,
{ L_26 , L_27 , V_188 , V_186 ,
NULL , 0 , L_28 , V_187 } } ,
{ & V_149 ,
{ L_29 , L_30 , V_188 , V_186 ,
NULL , 0 , L_31 , V_187 } } ,
{ & V_166 ,
{ L_32 , L_33 , V_188 , V_186 ,
NULL , 0 , L_34 , V_187 } } ,
{ & V_159 ,
{ L_35 , L_36 , V_195 , V_191 ,
NULL , 0 , L_37 , V_187 } } ,
{ & V_163 ,
{ L_38 , L_39 , V_196 , 8 ,
F_94 ( & V_197 ) , 0x01 , NULL , V_187 } } ,
{ & V_162 ,
{ L_40 , L_41 , V_196 , 8 ,
F_94 ( & V_197 ) , 0x02 , NULL , V_187 } } ,
{ & V_161 ,
{ L_42 , L_43 , V_196 , 8 ,
F_94 ( & V_197 ) , 0x04 , NULL , V_187 } } ,
{ & V_167 ,
{ L_44 , L_45 , V_190 , V_198 ,
NULL , 0 , L_46 , V_187 } } ,
{ & V_169 ,
{ L_47 , L_48 , V_190 , V_198 ,
NULL , 0 , L_49 , V_187 } } ,
{ & V_170 ,
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
V_189 , V_186 , NULL , 0 ,
L_61 , V_187 } } ,
{ & V_205 ,
{ L_62 , L_63 ,
V_206 , V_198 , NULL , 0 ,
L_64 , V_187 } } ,
{ & V_207 ,
{ L_65 , L_66 ,
V_188 , V_186 , NULL , 0 ,
L_67 , V_187 } } ,
{ & V_208 ,
{ L_68 , L_69 ,
V_188 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_209 ,
{ L_70 , L_71 ,
V_188 , V_186 , NULL , 0 ,
L_72 , V_187 } } ,
{ & V_210 ,
{ L_73 , L_74 ,
V_206 , V_198 , F_93 ( V_211 ) , 0 ,
NULL , V_187 } } ,
{ & V_212 ,
{ L_75 , L_76 ,
V_203 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_213 ,
{ L_77 , L_78 ,
V_188 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_21 ,
{ L_70 , L_71 ,
V_188 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_214 ,
{ L_79 , L_80 ,
V_203 , V_186 , NULL , 0 ,
L_57 , V_187 } } ,
{ & V_215 ,
{ L_81 , L_82 ,
V_185 , V_186 , NULL , 0 ,
NULL , V_187 } } ,
{ & V_216 ,
{ L_83 , L_84 ,
V_196 , 8 , NULL , 0x80 ,
NULL , V_187 } } ,
{ & V_217 ,
{ L_85 , L_86 ,
V_196 , 8 , NULL , 0x40 ,
NULL , V_187 } } ,
{ & V_218 ,
{ L_87 , L_88 ,
V_196 , 8 , NULL , 0x20 ,
NULL , V_187 } } ,
{ & V_219 ,
{ L_89 , L_90 ,
V_196 , 8 , NULL , 0x10 ,
NULL , V_187 } } ,
{ & V_220 ,
{ L_91 , L_92 ,
V_196 , 8 , NULL , 0x08 ,
NULL , V_187 } } ,
{ & V_221 ,
{ L_93 , L_94 ,
V_196 , 8 , NULL , 0x04 ,
NULL , V_187 } } ,
{ & V_222 ,
{ L_95 , L_96 ,
V_196 , 8 , NULL , 0x02 ,
NULL , V_187 } } ,
#line 1393 "../../asn1/spnego/packet-spnego-template.c"
} ;
static T_25 * V_223 [] = {
& V_174 ,
& V_39 ,
& V_51 ,
& V_160 ,
#line 1 "../../asn1/spnego/packet-spnego-ettarr.c"
& V_28 ,
& V_8 ,
& V_31 ,
& V_23 ,
& V_12 ,
& V_26 ,
& V_42 ,
#line 1403 "../../asn1/spnego/packet-spnego-template.c"
} ;
V_10 = F_95 ( V_224 , V_225 , V_226 ) ;
F_96 ( L_97 , F_87 , V_10 ) ;
V_227 = F_95 ( L_98 ,
L_98 ,
L_99 ) ;
F_96 ( L_99 , F_37 , V_227 ) ;
F_97 ( L_100 , F_85 , V_227 ) ;
F_98 ( V_10 , V_184 , F_99 ( V_184 ) ) ;
F_100 ( V_223 , F_99 ( V_223 ) ) ;
}
void F_101 ( void ) {
T_26 V_228 , V_229 ;
T_26 V_230 , V_231 ;
V_228 = F_102 ( L_97 ) ;
V_229 = F_103 ( F_86 , V_10 ) ;
F_104 ( L_101 , V_10 , V_174 ,
V_228 , V_229 ,
L_102 ) ;
V_230 = F_102 ( L_99 ) ;
V_231 = F_102 ( L_100 ) ;
F_104 ( L_103 , V_227 , V_51 ,
V_230 , V_231 ,
L_104 ) ;
F_104 ( L_105 , V_227 , V_51 ,
V_230 , V_231 ,
L_106 ) ;
F_104 ( L_107 , V_227 , V_51 ,
V_230 , V_231 ,
L_108 ) ;
}
