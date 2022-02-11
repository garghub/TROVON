static const struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 , int V_5 )
{
const struct V_1 * V_6 = V_3 -> V_7 ;
if ( ! V_6 )
return NULL ;
for ( V_6 = V_3 -> V_7 ; V_6 -> V_8 ; V_6 ++ ) {
if ( V_6 -> V_8 == V_4 &&
( ! V_5 || ! V_6 -> V_5 || V_5 == V_6 -> V_5 ) )
return V_6 ;
}
return NULL ;
}
static int
F_2 ( const struct V_1 * V_6 , char * V_9 , int V_10 )
{
if ( ! V_6 || ! V_6 -> V_11 )
return 0 ;
V_10 -- ;
return F_3 ( V_9 , V_6 -> V_11 , V_10 ) ;
}
static inline int
F_4 ( const struct V_1 * V_6 )
{
if ( ! V_6 || V_6 -> V_11 || V_6 -> V_12 )
return 0 ;
return 1 ;
}
static inline void F_5 ( const struct V_1 * V_6 ,
struct V_13 * V_14 )
{
if ( V_6 && V_6 -> V_12 ) {
V_14 -> V_15 = V_6 -> V_12 -> V_16 ;
V_14 -> V_17 = V_6 -> V_12 -> V_18 ;
V_14 -> V_19 = 1 ;
}
}
static int F_6 ( struct V_2 * V_3 , int V_4 ,
int V_20 , char * V_9 , int V_10 )
{
const struct V_21 * V_6 ;
if ( ! V_3 -> V_22 )
return 0 ;
for ( V_6 = V_3 -> V_22 ; V_6 -> V_8 ; V_6 ++ ) {
if ( V_6 -> V_8 == V_4 && V_20 < V_6 -> V_23 )
return F_3 ( V_9 , V_6 -> V_24 [ V_20 ] , V_10 ) ;
}
return 0 ;
}
static void * F_7 ( struct V_2 * V_3 ,
unsigned char V_25 )
{
struct V_26 * V_27 = NULL ;
while ( ( V_27 = F_8 ( V_3 -> V_28 , V_3 -> V_10 , V_27 ,
V_29 ) ) != NULL ) {
if ( V_27 -> V_30 >= 4 &&
V_27 -> V_31 >= V_32 &&
V_27 -> V_31 <= V_33 &&
V_27 -> V_34 == V_25 )
return V_27 ;
}
return NULL ;
}
static int F_9 ( struct V_2 * V_3 ,
int V_20 , char * V_9 , int V_35 )
{
int V_36 = F_10 ( V_3 -> V_37 -> V_38 , V_20 , V_9 , V_35 - 1 ) ;
V_9 [ V_36 ] = 0 ;
return V_36 ;
}
static int F_11 ( struct V_13 * V_14 , int V_39 )
{
switch ( V_14 -> V_40 ) {
case V_41 :
return ! ! V_39 ;
case V_42 :
return ! V_39 ;
case V_43 :
V_39 &= 0xff ;
break;
case V_44 :
V_39 &= 0xff ;
if ( V_39 >= 0x80 )
V_39 -= 0x100 ;
break;
case V_45 :
V_39 &= 0xffff ;
break;
case V_46 :
V_39 &= 0xffff ;
if ( V_39 >= 0x8000 )
V_39 -= 0x10000 ;
break;
}
return V_39 ;
}
static int F_12 ( struct V_13 * V_14 , int V_39 )
{
switch ( V_14 -> V_40 ) {
case V_41 :
return ! ! V_39 ;
case V_42 :
return ! V_39 ;
case V_44 :
case V_43 :
return V_39 & 0xff ;
case V_46 :
case V_45 :
return V_39 & 0xffff ;
}
return 0 ;
}
static int F_13 ( struct V_13 * V_14 , int V_39 )
{
if ( ! V_14 -> V_47 )
V_14 -> V_47 = 1 ;
if ( V_39 < V_14 -> V_16 )
return 0 ;
else if ( V_39 >= V_14 -> V_18 )
return ( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
else
return ( V_39 - V_14 -> V_16 ) / V_14 -> V_47 ;
}
static int F_14 ( struct V_13 * V_14 , int V_39 )
{
if ( V_39 < 0 )
return V_14 -> V_16 ;
if ( ! V_14 -> V_47 )
V_14 -> V_47 = 1 ;
V_39 *= V_14 -> V_47 ;
V_39 += V_14 -> V_16 ;
if ( V_39 > V_14 -> V_18 )
return V_14 -> V_18 ;
return V_39 ;
}
static int F_15 ( int V_40 )
{
switch ( V_40 ) {
case V_48 :
case V_49 :
return 4 ;
case V_46 :
case V_45 :
return 2 ;
default:
return 1 ;
}
return 0 ;
}
static int F_16 ( struct V_13 * V_14 , int V_50 ,
int V_51 , int * V_52 )
{
struct V_53 * V_37 = V_14 -> V_54 . V_55 -> V_37 ;
unsigned char V_9 [ 2 ] ;
int V_56 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
int V_57 = 10 ;
int V_58 = 0 , V_59 ;
V_59 = F_17 ( V_37 ) ;
if ( V_59 < 0 )
return - V_60 ;
while ( V_57 -- > 0 ) {
V_58 = F_18 ( V_37 ) | ( V_14 -> V_54 . V_8 << 8 ) ;
if ( F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_50 ,
V_61 | V_62 | V_63 ,
V_51 , V_58 , V_9 , V_56 ) >= V_56 ) {
* V_52 = F_11 ( V_14 , F_21 ( V_9 , V_56 ) ) ;
V_59 = 0 ;
goto V_64;
}
}
F_22 ( V_37 ,
L_1 ,
V_50 , V_51 , V_58 , V_14 -> V_40 ) ;
V_59 = - V_65 ;
V_64:
F_23 ( V_37 ) ;
return V_59 ;
}
static int F_24 ( struct V_13 * V_14 , int V_50 ,
int V_51 , int * V_52 )
{
struct V_53 * V_37 = V_14 -> V_54 . V_55 -> V_37 ;
unsigned char V_9 [ 4 + 3 * sizeof( V_66 ) ] ;
unsigned char * V_39 ;
int V_58 = 0 , V_67 , V_68 ;
T_1 V_69 ;
if ( V_50 == V_70 ) {
V_69 = V_71 ;
V_68 = F_15 ( V_14 -> V_40 ) ;
} else {
V_69 = V_72 ;
V_68 = sizeof( V_9 ) ;
}
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_67 = F_17 ( V_37 ) ? - V_60 : 0 ;
if ( V_67 )
goto error;
V_58 = F_18 ( V_37 ) | ( V_14 -> V_54 . V_8 << 8 ) ;
V_67 = F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_69 ,
V_61 | V_62 | V_63 ,
V_51 , V_58 , V_9 , V_68 ) ;
F_23 ( V_37 ) ;
if ( V_67 < 0 ) {
error:
F_25 ( V_37 ,
L_1 ,
V_50 , V_51 , V_58 , V_14 -> V_40 ) ;
return V_67 ;
}
switch ( V_50 ) {
case V_70 :
V_39 = V_9 ;
break;
case V_73 :
V_39 = V_9 + sizeof( V_74 ) ;
break;
case V_75 :
V_39 = V_9 + sizeof( V_74 ) * 2 ;
break;
case V_76 :
V_39 = V_9 + sizeof( V_74 ) * 3 ;
break;
default:
return - V_65 ;
}
* V_52 = F_11 ( V_14 , F_21 ( V_39 , sizeof( V_74 ) ) ) ;
return 0 ;
}
static int F_26 ( struct V_13 * V_14 , int V_50 ,
int V_51 , int * V_52 )
{
V_51 += V_14 -> V_77 ;
return ( V_14 -> V_54 . V_55 -> V_78 == V_79 ) ?
F_16 ( V_14 , V_50 , V_51 , V_52 ) :
F_24 ( V_14 , V_50 , V_51 , V_52 ) ;
}
static int F_27 ( struct V_13 * V_14 ,
int V_51 , int * V_80 )
{
return F_26 ( V_14 , V_70 , V_51 , V_80 ) ;
}
static inline int F_28 ( struct V_13 * V_14 ,
int V_81 , int * V_80 )
{
return F_26 ( V_14 , V_70 ,
( V_14 -> V_5 << 8 ) | V_81 ,
V_80 ) ;
}
int F_29 ( struct V_13 * V_14 ,
int V_81 , int V_20 , int * V_80 )
{
int V_59 ;
if ( V_14 -> V_82 & ( 1 << V_81 ) ) {
* V_80 = V_14 -> V_83 [ V_20 ] ;
return 0 ;
}
V_59 = F_28 ( V_14 , V_81 , V_80 ) ;
if ( V_59 < 0 ) {
if ( ! V_14 -> V_54 . V_55 -> V_84 )
F_22 ( V_14 -> V_54 . V_55 -> V_37 ,
L_2 ,
V_14 -> V_5 , V_81 , V_59 ) ;
return V_59 ;
}
V_14 -> V_82 |= 1 << V_81 ;
V_14 -> V_83 [ V_20 ] = * V_80 ;
return 0 ;
}
int F_30 ( struct V_13 * V_14 ,
int V_50 , int V_51 , int V_85 )
{
struct V_53 * V_37 = V_14 -> V_54 . V_55 -> V_37 ;
unsigned char V_9 [ 4 ] ;
int V_58 = 0 , V_56 , V_59 , V_57 = 10 ;
V_51 += V_14 -> V_77 ;
if ( V_14 -> V_54 . V_55 -> V_78 == V_79 ) {
V_56 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
} else {
V_56 = F_15 ( V_14 -> V_40 ) ;
if ( V_50 != V_86 ) {
F_22 ( V_37 , L_3 ) ;
return - V_65 ;
}
V_50 = V_71 ;
}
V_85 = F_12 ( V_14 , V_85 ) ;
V_9 [ 0 ] = V_85 & 0xff ;
V_9 [ 1 ] = ( V_85 >> 8 ) & 0xff ;
V_9 [ 2 ] = ( V_85 >> 16 ) & 0xff ;
V_9 [ 3 ] = ( V_85 >> 24 ) & 0xff ;
V_59 = F_17 ( V_37 ) ;
if ( V_59 < 0 )
return - V_60 ;
while ( V_57 -- > 0 ) {
V_58 = F_18 ( V_37 ) | ( V_14 -> V_54 . V_8 << 8 ) ;
if ( F_19 ( V_37 -> V_38 ,
F_31 ( V_37 -> V_38 , 0 ) , V_50 ,
V_61 | V_62 | V_87 ,
V_51 , V_58 , V_9 , V_56 ) >= 0 ) {
V_59 = 0 ;
goto V_64;
}
}
F_22 ( V_37 , L_4 ,
V_50 , V_51 , V_58 , V_14 -> V_40 , V_9 [ 0 ] , V_9 [ 1 ] ) ;
V_59 = - V_65 ;
V_64:
F_23 ( V_37 ) ;
return V_59 ;
}
static int F_32 ( struct V_13 * V_14 ,
int V_51 , int V_80 )
{
return F_30 ( V_14 , V_86 , V_51 , V_80 ) ;
}
int F_33 ( struct V_13 * V_14 , int V_81 ,
int V_20 , int V_80 )
{
int V_59 ;
unsigned int V_88 = ( V_81 == 0 ) ?
V_14 -> V_89 :
V_14 -> V_90 & ( 1 << ( V_81 - 1 ) ) ;
if ( V_88 ) {
F_22 ( V_14 -> V_54 . V_55 -> V_37 ,
L_5 ,
V_91 , V_81 , V_14 -> V_5 ) ;
return 0 ;
}
V_59 = F_30 ( V_14 ,
V_86 , ( V_14 -> V_5 << 8 ) | V_81 ,
V_80 ) ;
if ( V_59 < 0 )
return V_59 ;
V_14 -> V_82 |= 1 << V_81 ;
V_14 -> V_83 [ V_20 ] = V_80 ;
return 0 ;
}
int F_34 ( struct V_92 * V_93 , int V_94 ,
unsigned int V_68 , unsigned int T_2 * V_95 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
F_35 ( V_97 , 0 , 0 ) ;
if ( V_68 < sizeof( V_97 ) )
return - V_98 ;
V_97 [ 2 ] = V_14 -> V_15 ;
V_97 [ 3 ] = V_14 -> V_17 ;
if ( F_36 ( V_95 , V_97 , sizeof( V_97 ) ) )
return - V_99 ;
return 0 ;
}
static int F_37 ( unsigned char * V_100 ,
int V_101 , int V_102 , int V_103 )
{
int V_58 = V_101 * V_103 + V_102 ;
return V_100 [ V_58 >> 3 ] & ( 0x80 >> ( V_58 & 7 ) ) ;
}
int F_38 ( struct V_104 * V_105 ,
struct V_92 * V_106 )
{
struct V_107 * V_55 = V_105 -> V_55 ;
int V_59 ;
while ( F_39 ( V_55 -> V_37 -> V_108 , & V_106 -> V_8 ) )
V_106 -> V_8 . V_20 ++ ;
if ( ( V_59 = F_40 ( V_55 -> V_37 -> V_108 , V_106 ) ) < 0 ) {
F_22 ( V_55 -> V_37 , L_6 ,
V_59 ) ;
return V_59 ;
}
V_105 -> V_106 = V_106 ;
V_105 -> V_109 = V_55 -> V_110 [ V_105 -> V_8 ] ;
V_55 -> V_110 [ V_105 -> V_8 ] = V_105 ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_111 * V_112 ,
unsigned char * V_11 , int V_35 , int V_113 )
{
struct V_114 * V_24 ;
if ( V_112 -> V_11 )
return F_9 ( V_3 , V_112 -> V_11 ,
V_11 , V_35 ) ;
if ( V_112 -> type >> 16 ) {
if ( V_113 )
return 0 ;
switch ( V_112 -> type >> 16 ) {
case V_115 :
strcpy ( V_11 , L_7 ) ;
return 8 ;
case V_116 :
strcpy ( V_11 , L_8 ) ;
return 12 ;
case V_117 :
strcpy ( V_11 , L_9 ) ;
return 8 ;
case V_118 :
strcpy ( V_11 , L_10 ) ;
return 5 ;
default:
return sprintf ( V_11 , L_11 , V_112 -> V_8 ) ;
}
}
switch ( V_112 -> type & 0xff00 ) {
case 0x0100 :
strcpy ( V_11 , L_12 ) ;
return 3 ;
case 0x0200 :
strcpy ( V_11 , L_13 ) ;
return 3 ;
case 0x0400 :
strcpy ( V_11 , L_14 ) ;
return 7 ;
case 0x0500 :
strcpy ( V_11 , L_15 ) ;
return 5 ;
}
for ( V_24 = V_119 ; V_24 -> type ; V_24 ++ ) {
if ( V_24 -> type == V_112 -> type ) {
strcpy ( V_11 , V_24 -> V_11 ) ;
return strlen ( V_24 -> V_11 ) ;
}
}
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , int V_8 ,
struct V_111 * V_120 )
{
int V_59 ;
void * V_121 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
while ( ( V_121 = F_7 ( V_3 , V_8 ) ) != NULL ) {
unsigned char * V_27 = V_121 ;
V_120 -> V_8 = V_8 ;
switch ( V_27 [ 2 ] ) {
case V_32 :
if ( V_3 -> V_55 -> V_78 == V_79 ) {
struct V_122 * V_123 = V_121 ;
V_120 -> type = F_43 ( V_123 -> V_124 ) ;
V_120 -> V_125 = V_123 -> V_126 ;
V_120 -> V_127 = F_43 ( V_123 -> V_128 ) ;
V_120 -> V_11 = V_123 -> V_129 ;
} else {
struct V_130 * V_123 = V_121 ;
V_59 = F_42 ( V_3 , V_123 -> V_131 , V_120 ) ;
if ( V_59 < 0 )
return V_59 ;
V_120 -> V_8 = V_8 ;
V_120 -> type = F_43 ( V_123 -> V_124 ) ;
V_120 -> V_125 = V_123 -> V_126 ;
V_120 -> V_127 = F_44 ( V_123 -> V_132 ) ;
V_120 -> V_11 = V_123 -> V_129 ;
}
return 0 ;
case V_133 : {
struct V_26 * V_123 = V_121 ;
V_8 = V_123 -> V_134 ;
break;
}
case V_118 : {
struct V_135 * V_123 = V_121 ;
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_125 = F_45 ( V_123 ) ;
V_120 -> V_127 = F_46 ( V_123 , V_3 -> V_55 -> V_78 ) ;
V_120 -> V_11 = F_47 ( V_123 ) ;
return 0 ;
}
case V_115 :
case V_136 : {
struct V_137 * V_123 = V_121 ;
V_59 = F_42 ( V_3 , V_123 -> V_138 [ 0 ] , V_120 ) ;
if ( V_59 < 0 )
return V_59 ;
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_8 = V_8 ;
V_120 -> V_11 = F_48 ( V_123 ) ;
return 0 ;
}
case V_116 :
case V_117 :
case V_139 : {
struct V_140 * V_123 = V_121 ;
if ( V_3 -> V_55 -> V_78 == V_141 &&
V_27 [ 2 ] == V_142 ) {
return 0 ;
}
if ( V_123 -> V_143 ) {
V_8 = V_123 -> V_138 [ 0 ] ;
break;
}
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_125 = F_49 ( V_123 ) ;
V_120 -> V_127 = F_50 ( V_123 , V_3 -> V_55 -> V_78 ) ;
V_120 -> V_11 = F_51 ( V_123 , V_3 -> V_55 -> V_78 ) ;
return 0 ;
}
case V_144 : {
struct V_145 * V_123 = V_121 ;
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_8 = V_8 ;
V_120 -> V_11 = V_123 -> V_146 ;
return 0 ;
}
default:
return - V_147 ;
}
}
return - V_147 ;
}
void F_52 ( struct V_92 * V_106 )
{
F_53 ( V_106 -> V_96 ) ;
V_106 -> V_96 = NULL ;
}
static void F_54 ( struct V_13 * V_14 ,
struct V_92 * V_106 )
{
struct V_53 * V_37 = V_14 -> V_54 . V_55 -> V_37 ;
switch ( V_37 -> V_148 ) {
case F_55 ( 0x0763 , 0x2030 ) :
case F_55 ( 0x0763 , 0x2031 ) :
if ( strcmp ( V_106 -> V_8 . V_11 , L_16 ) == 0 ) {
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0xffff ;
V_14 -> V_47 = 0x00e6 ;
break;
}
if ( strcmp ( V_106 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_106 -> V_8 . V_11 , L_18 ) == 0 ) {
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0xff ;
break;
}
if ( strstr ( V_106 -> V_8 . V_11 , L_19 ) != NULL ) {
V_14 -> V_16 = 0xb706 ;
V_14 -> V_18 = 0xff7b ;
V_14 -> V_47 = 0x0073 ;
break;
}
if ( ( strstr ( V_106 -> V_8 . V_11 , L_20 ) != NULL ) ||
( strstr ( V_106 -> V_8 . V_11 , L_21 ) != NULL ) ) {
V_14 -> V_16 = 0xb5fb ;
V_14 -> V_18 = 0xfcfe ;
V_14 -> V_47 = 0x0073 ;
}
break;
case F_55 ( 0x0763 , 0x2081 ) :
case F_55 ( 0x0763 , 0x2080 ) :
if ( strcmp ( V_106 -> V_8 . V_11 , L_16 ) == 0 ) {
F_56 ( V_37 ,
L_22 ) ;
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0x7f00 ;
V_14 -> V_47 = 0x0100 ;
break;
}
if ( strcmp ( V_106 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_106 -> V_8 . V_11 , L_18 ) == 0 ) {
F_56 ( V_37 ,
L_23 ) ;
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0x7f ;
break;
}
break;
case F_55 ( 0x0471 , 0x0101 ) :
case F_55 ( 0x0471 , 0x0104 ) :
case F_55 ( 0x0471 , 0x0105 ) :
case F_55 ( 0x0672 , 0x1041 ) :
if ( ! strcmp ( V_106 -> V_8 . V_11 , L_24 ) &&
V_14 -> V_16 == - 15616 ) {
F_56 ( V_37 ,
L_25 ) ;
V_14 -> V_18 = - 256 ;
}
break;
case F_55 ( 0x046d , 0x09a4 ) :
if ( ! strcmp ( V_106 -> V_8 . V_11 , L_26 ) ) {
F_56 ( V_37 ,
L_27 ) ;
V_14 -> V_16 = 6080 ;
V_14 -> V_18 = 8768 ;
V_14 -> V_47 = 192 ;
}
break;
case F_55 ( 0x046d , 0x0807 ) :
case F_55 ( 0x046d , 0x0808 ) :
case F_55 ( 0x046d , 0x0809 ) :
case F_55 ( 0x046d , 0x0819 ) :
case F_55 ( 0x046d , 0x081b ) :
case F_55 ( 0x046d , 0x081d ) :
case F_55 ( 0x046d , 0x0825 ) :
case F_55 ( 0x046d , 0x0826 ) :
case F_55 ( 0x046d , 0x08ca ) :
case F_55 ( 0x046d , 0x0991 ) :
if ( ! strcmp ( V_106 -> V_8 . V_11 , L_26 ) ) {
F_56 ( V_37 ,
L_28 ) ;
V_14 -> V_47 = 384 ;
}
break;
}
}
static int F_57 ( struct V_13 * V_14 ,
int V_149 , struct V_92 * V_106 )
{
V_14 -> V_16 = V_149 ;
V_14 -> V_18 = V_14 -> V_16 + 1 ;
V_14 -> V_47 = 1 ;
V_14 -> V_15 = V_14 -> V_17 = 0 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_14 -> V_19 = 1 ;
} else {
int V_150 = 0 ;
if ( V_14 -> V_151 ) {
int V_152 ;
for ( V_152 = 0 ; V_152 < V_153 ; V_152 ++ )
if ( V_14 -> V_151 & ( 1 << V_152 ) ) {
V_150 = V_152 + 1 ;
break;
}
}
if ( F_26 ( V_14 , V_75 , ( V_14 -> V_5 << 8 ) | V_150 , & V_14 -> V_18 ) < 0 ||
F_26 ( V_14 , V_73 , ( V_14 -> V_5 << 8 ) | V_150 , & V_14 -> V_16 ) < 0 ) {
F_25 ( V_14 -> V_54 . V_55 -> V_37 ,
L_29 ,
V_14 -> V_54 . V_8 , F_18 ( V_14 -> V_54 . V_55 -> V_37 ) ,
V_14 -> V_5 , V_14 -> V_54 . V_8 ) ;
return - V_65 ;
}
if ( F_26 ( V_14 , V_76 ,
( V_14 -> V_5 << 8 ) | V_150 ,
& V_14 -> V_47 ) < 0 ) {
V_14 -> V_47 = 1 ;
} else {
int V_154 = V_14 -> V_47 ;
while ( V_14 -> V_47 > 1 ) {
if ( F_30 ( V_14 , V_155 ,
( V_14 -> V_5 << 8 ) | V_150 ,
V_14 -> V_47 / 2 ) < 0 )
break;
V_14 -> V_47 /= 2 ;
}
if ( F_26 ( V_14 , V_76 ,
( V_14 -> V_5 << 8 ) | V_150 , & V_14 -> V_47 ) < 0 )
V_14 -> V_47 = V_154 ;
}
if ( V_14 -> V_47 == 0 )
V_14 -> V_47 = 1 ;
if ( V_14 -> V_16 + V_14 -> V_47 < V_14 -> V_18 ) {
int V_154 = V_14 -> V_47 ;
int V_156 , V_157 , V_158 ;
F_28 ( V_14 , V_150 , & V_156 ) ;
for (; ; ) {
V_157 = V_156 ;
if ( V_157 < V_14 -> V_18 )
V_157 += V_14 -> V_47 ;
else
V_157 -= V_14 -> V_47 ;
if ( V_157 < V_14 -> V_16 || V_157 > V_14 -> V_18 ||
F_33 ( V_14 , V_150 , 0 , V_157 ) ||
F_28 ( V_14 , V_150 , & V_158 ) ) {
V_14 -> V_47 = V_154 ;
break;
}
if ( V_157 == V_158 )
break;
V_14 -> V_47 *= 2 ;
}
F_33 ( V_14 , V_150 , 0 , V_156 ) ;
}
V_14 -> V_19 = 1 ;
}
if ( V_106 )
F_54 ( V_14 , V_106 ) ;
V_14 -> V_15 = ( F_11 ( V_14 , V_14 -> V_16 ) * 100 ) / 256 ;
V_14 -> V_17 = ( F_11 ( V_14 , V_14 -> V_18 ) * 100 ) / 256 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
if ( V_14 -> V_15 < 0 )
V_14 -> V_17 = 0 ;
else if ( V_14 -> V_15 > 0 )
V_14 -> V_15 = 0 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
return - V_65 ;
}
}
return 0 ;
}
static int F_58 ( struct V_92 * V_93 ,
struct V_159 * V_160 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 )
V_160 -> type = V_161 ;
else
V_160 -> type = V_162 ;
V_160 -> V_23 = V_14 -> V_125 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_160 -> V_80 . integer . V_16 = 0 ;
V_160 -> V_80 . integer . V_18 = 1 ;
} else {
if ( ! V_14 -> V_19 ) {
F_57 ( V_14 , 0 , V_93 ) ;
if ( V_14 -> V_19 && V_14 -> V_15 >= V_14 -> V_17 ) {
V_93 -> V_163 [ 0 ] . V_164 &=
~ ( V_165 |
V_166 ) ;
F_59 ( V_14 -> V_54 . V_55 -> V_37 -> V_108 ,
V_167 ,
& V_93 -> V_8 ) ;
}
}
V_160 -> V_80 . integer . V_16 = 0 ;
V_160 -> V_80 . integer . V_18 =
( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
}
return 0 ;
}
static int F_60 ( struct V_92 * V_93 ,
struct V_168 * V_169 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_170 , V_171 , V_39 , V_59 ;
V_169 -> V_80 . integer . V_80 [ 0 ] = V_14 -> V_16 ;
if ( V_14 -> V_151 ) {
V_171 = 0 ;
for ( V_170 = 0 ; V_170 < V_153 ; V_170 ++ ) {
if ( ! ( V_14 -> V_151 & ( 1 << V_170 ) ) )
continue;
V_59 = F_29 ( V_14 , V_170 + 1 , V_171 , & V_39 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_169 -> V_80 . integer . V_80 [ V_171 ] = V_39 ;
V_171 ++ ;
}
return 0 ;
} else {
V_59 = F_29 ( V_14 , 0 , 0 , & V_39 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_169 -> V_80 . integer . V_80 [ 0 ] = V_39 ;
}
return 0 ;
}
static int F_62 ( struct V_92 * V_93 ,
struct V_168 * V_169 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_170 , V_171 , V_39 , V_172 , V_59 ;
int V_173 = 0 ;
if ( V_14 -> V_151 ) {
V_171 = 0 ;
for ( V_170 = 0 ; V_170 < V_153 ; V_170 ++ ) {
if ( ! ( V_14 -> V_151 & ( 1 << V_170 ) ) )
continue;
V_59 = F_29 ( V_14 , V_170 + 1 , V_171 , & V_172 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_169 -> V_80 . integer . V_80 [ V_171 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_172 != V_39 ) {
F_33 ( V_14 , V_170 + 1 , V_171 , V_39 ) ;
V_173 = 1 ;
}
V_171 ++ ;
}
} else {
V_59 = F_29 ( V_14 , 0 , 0 , & V_172 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_169 -> V_80 . integer . V_80 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_172 ) {
F_33 ( V_14 , 0 , 0 , V_39 ) ;
V_173 = 1 ;
}
}
return V_173 ;
}
static T_3 F_63 ( struct V_92 * V_106 , const char * V_174 )
{
return F_64 ( V_106 -> V_8 . V_11 , V_174 , sizeof( V_106 -> V_8 . V_11 ) ) ;
}
static void F_65 ( struct V_92 * V_106 ,
struct V_175 * V_108 )
{
const char * V_176 [] = {
L_14 , L_30 , L_31 , L_32 , NULL } ;
const char * * V_177 ;
bool V_178 = false ;
if ( strcmp ( L_33 , V_106 -> V_8 . V_11 ) )
return;
for ( V_177 = V_176 ; * V_177 ; V_177 ++ )
if ( strstr ( V_108 -> V_179 , * V_177 ) ) {
V_178 = true ;
break;
}
if ( ! V_178 )
return;
F_3 ( V_106 -> V_8 . V_11 , L_31 , sizeof( V_106 -> V_8 . V_11 ) ) ;
}
static void F_66 ( struct V_2 * V_3 , void * V_180 ,
unsigned int V_181 , int V_5 ,
struct V_111 * V_112 , int V_4 ,
int V_182 )
{
struct V_26 * V_183 = V_180 ;
struct V_184 * V_185 ;
unsigned int V_36 = 0 ;
int V_186 = 0 ;
int V_187 = F_67 ( V_183 ) ;
struct V_92 * V_106 ;
struct V_13 * V_14 ;
const struct V_1 * V_7 ;
unsigned int V_188 ;
V_5 ++ ;
if ( V_5 == V_189 ) {
return;
}
V_7 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_190 ) ;
if ( ! V_14 )
return;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_5 = V_5 ;
V_14 -> V_151 = V_181 ;
V_185 = & V_191 [ V_5 - 1 ] ;
if ( V_3 -> V_55 -> V_78 == V_79 )
V_14 -> V_40 = V_185 -> type ;
else
V_14 -> V_40 = V_185 -> V_192 >= 0 ?
V_185 -> V_192 : V_185 -> type ;
if ( V_181 == 0 ) {
V_14 -> V_125 = 1 ;
V_14 -> V_89 = V_182 ;
} else {
int V_152 , V_170 = 0 ;
for ( V_152 = 0 ; V_152 < 16 ; V_152 ++ )
if ( V_181 & ( 1 << V_152 ) )
V_170 ++ ;
V_14 -> V_125 = V_170 ;
V_14 -> V_90 = V_182 ;
}
if ( V_14 -> V_125 == V_182 )
V_106 = F_70 ( & V_193 , V_14 ) ;
else
V_106 = F_70 ( & V_194 , V_14 ) ;
if ( ! V_106 ) {
F_25 ( V_3 -> V_37 , L_34 ) ;
F_53 ( V_14 ) ;
return;
}
V_106 -> V_195 = F_52 ;
V_36 = F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
V_186 = V_36 != 0 ;
if ( ! V_36 && V_187 )
V_36 = F_9 ( V_3 , V_187 ,
V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
switch ( V_5 ) {
case V_196 :
case V_197 :
if ( ! V_36 ) {
V_36 = F_41 ( V_3 , V_112 , V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = F_41 ( V_3 , & V_3 -> V_198 ,
V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
snprintf ( V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ,
L_35 , V_4 ) ;
}
if ( ! V_186 )
F_65 ( V_106 , V_3 -> V_55 -> V_37 -> V_108 ) ;
if ( ! V_186 && ! ( V_3 -> V_198 . type >> 16 ) ) {
if ( ( V_3 -> V_198 . type & 0xff00 ) == 0x0100 )
F_63 ( V_106 , L_36 ) ;
else
F_63 ( V_106 , L_37 ) ;
}
F_63 ( V_106 , V_5 == V_196 ?
L_38 : L_39 ) ;
break;
default:
if ( ! V_36 )
F_3 ( V_106 -> V_8 . V_11 , V_191 [ V_5 - 1 ] . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) ) ;
break;
}
F_57 ( V_14 , 0 , V_106 ) ;
if ( V_5 == V_197 ) {
F_5 ( V_7 , V_14 ) ;
if ( V_14 -> V_15 < V_14 -> V_17 || ! V_14 -> V_19 ) {
V_106 -> V_199 . V_170 = F_34 ;
V_106 -> V_163 [ 0 ] . V_164 |=
V_165 |
V_166 ;
}
}
V_188 = ( V_14 -> V_18 - V_14 -> V_16 ) / V_14 -> V_47 ;
if ( V_188 > 384 ) {
F_71 ( V_3 -> V_37 ,
L_40 ,
V_188 ) ;
F_71 ( V_3 -> V_37 ,
L_41 ,
V_14 -> V_54 . V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
}
F_22 ( V_3 -> V_37 , L_42 ,
V_14 -> V_54 . V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
F_38 ( & V_14 -> V_54 , V_106 ) ;
}
static int F_72 ( struct V_2 * V_3 , int V_4 ,
void * V_200 )
{
int V_125 , V_152 , V_201 ;
struct V_111 V_112 ;
unsigned int V_202 , V_203 ;
int V_59 , V_204 ;
struct V_26 * V_27 = V_200 ;
T_1 * V_205 ;
if ( V_3 -> V_55 -> V_78 == V_79 ) {
V_204 = V_27 -> V_206 ;
if ( ! V_204 ) {
F_22 ( V_3 -> V_37 ,
L_43 ,
V_4 ) ;
return - V_65 ;
}
V_125 = ( V_27 -> V_30 - 7 ) / V_204 - 1 ;
V_205 = V_27 -> V_205 ;
if ( V_27 -> V_30 < 7 + V_204 ) {
F_25 ( V_3 -> V_37 ,
L_44 ,
V_4 ) ;
return - V_65 ;
}
} else {
struct V_207 * V_208 = V_200 ;
V_204 = 4 ;
V_125 = ( V_27 -> V_30 - 6 ) / 4 - 1 ;
V_205 = V_208 -> V_205 ;
if ( V_27 -> V_30 < 6 + V_204 ) {
F_25 ( V_3 -> V_37 ,
L_44 ,
V_4 ) ;
return - V_65 ;
}
}
if ( ( V_59 = F_73 ( V_3 , V_27 -> V_134 ) ) < 0 )
return V_59 ;
V_59 = F_42 ( V_3 , V_27 -> V_134 , & V_112 ) ;
if ( V_59 < 0 )
return V_59 ;
V_202 = F_21 ( V_205 , V_204 ) ;
switch ( V_3 -> V_37 -> V_148 ) {
case F_55 ( 0x08bb , 0x2702 ) :
F_56 ( V_3 -> V_37 ,
L_45 ) ;
V_202 &= ~ F_74 ( V_197 ) ;
break;
case F_55 ( 0x1130 , 0xf211 ) :
F_56 ( V_3 -> V_37 ,
L_46 ) ;
V_125 = 0 ;
break;
}
if ( V_125 > 0 )
V_203 = F_21 ( V_205 + V_204 , V_204 ) ;
else
V_203 = 0 ;
if ( V_3 -> V_55 -> V_78 == V_79 ) {
for ( V_152 = 0 ; V_152 < 10 ; V_152 ++ ) {
unsigned int V_209 = 0 ;
for ( V_201 = 0 ; V_201 < V_125 ; V_201 ++ ) {
unsigned int V_210 ;
V_210 = F_21 ( V_205 +
V_204 * ( V_201 + 1 ) , V_204 ) ;
if ( V_210 & ( 1 << V_152 ) )
V_209 |= ( 1 << V_201 ) ;
}
if ( V_209 & 1 )
F_66 ( V_3 , V_200 , V_209 , V_152 ,
& V_112 , V_4 , 0 ) ;
if ( V_202 & ( 1 << V_152 ) )
F_66 ( V_3 , V_200 , 0 , V_152 , & V_112 ,
V_4 , 0 ) ;
}
} else {
for ( V_152 = 0 ; V_152 < F_75 ( V_191 ) ; V_152 ++ ) {
unsigned int V_209 = 0 ;
unsigned int V_211 = 0 ;
for ( V_201 = 0 ; V_201 < V_125 ; V_201 ++ ) {
unsigned int V_210 ;
V_210 = F_21 ( V_205 +
V_204 * ( V_201 + 1 ) , V_204 ) ;
if ( F_76 ( V_210 , V_152 ) ) {
V_209 |= ( 1 << V_201 ) ;
if ( ! F_77 ( V_210 , V_152 ) )
V_211 |= ( 1 << V_201 ) ;
}
}
if ( V_209 & 1 )
F_66 ( V_3 , V_200 , V_209 , V_152 ,
& V_112 , V_4 , V_211 ) ;
if ( F_76 ( V_202 , V_152 ) )
F_66 ( V_3 , V_200 , 0 , V_152 , & V_112 , V_4 ,
! F_77 ( V_202 , V_152 ) ) ;
}
}
return 0 ;
}
static void F_78 ( struct V_2 * V_3 ,
struct V_135 * V_183 ,
int V_212 , int V_213 , int V_4 ,
struct V_111 * V_112 )
{
struct V_13 * V_14 ;
unsigned int V_103 = F_45 ( V_183 ) ;
unsigned int V_152 , V_36 ;
struct V_92 * V_106 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_190 ) ;
if ( ! V_14 )
return;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_5 = V_213 + 1 ;
V_14 -> V_40 = V_46 ;
for ( V_152 = 0 ; V_152 < V_103 ; V_152 ++ ) {
T_1 * V_170 = F_79 ( V_183 , V_3 -> V_55 -> V_78 ) ;
if ( F_37 ( V_170 , V_213 , V_152 , V_103 ) ) {
V_14 -> V_151 |= ( 1 << V_152 ) ;
V_14 -> V_125 ++ ;
}
}
F_80 ( V_14 , 0 ) ;
V_106 = F_70 ( & V_194 , V_14 ) ;
if ( ! V_106 ) {
F_25 ( V_3 -> V_37 , L_34 ) ;
F_53 ( V_14 ) ;
return;
}
V_106 -> V_195 = F_52 ;
V_36 = F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
V_36 = F_41 ( V_3 , V_112 , V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
V_36 = sprintf ( V_106 -> V_8 . V_11 , L_47 , V_213 + 1 ) ;
F_63 ( V_106 , L_39 ) ;
F_22 ( V_3 -> V_37 , L_48 ,
V_14 -> V_54 . V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 , V_14 -> V_16 , V_14 -> V_18 ) ;
F_38 ( & V_14 -> V_54 , V_106 ) ;
}
static int F_81 ( struct V_2 * V_3 , int V_4 ,
void * V_180 )
{
struct V_135 * V_183 = V_180 ;
struct V_111 V_112 ;
int V_214 , V_215 , V_103 ;
int V_216 , V_101 , V_59 ;
if ( V_183 -> V_30 < 11 || ! ( V_214 = V_183 -> V_143 ) ||
! ( V_103 = F_45 ( V_183 ) ) ) {
F_25 ( V_3 -> V_37 ,
L_49 ,
V_4 ) ;
return - V_65 ;
}
V_215 = 0 ;
V_101 = 0 ;
for ( V_216 = 0 ; V_216 < V_214 ; V_216 ++ ) {
V_59 = F_73 ( V_3 , V_183 -> V_138 [ V_216 ] ) ;
if ( V_59 < 0 )
continue;
if ( V_183 -> V_30 <= 10 + V_214 )
continue;
V_59 = F_42 ( V_3 , V_183 -> V_138 [ V_216 ] , & V_112 ) ;
if ( V_59 < 0 )
return V_59 ;
V_215 += V_112 . V_125 ;
for (; V_101 < V_215 ; V_101 ++ ) {
int V_102 , V_217 = 0 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
T_1 * V_170 = F_79 ( V_183 ,
V_3 -> V_55 -> V_78 ) ;
if ( F_37 ( V_170 , V_101 , V_102 , V_103 ) ) {
V_217 = 1 ;
break;
}
}
if ( V_217 )
F_78 ( V_3 , V_183 , V_216 , V_101 ,
V_4 , & V_112 ) ;
}
}
return 0 ;
}
static int F_82 ( struct V_92 * V_93 ,
struct V_168 * V_169 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_59 , V_39 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_59 < 0 ) {
V_169 -> V_80 . integer . V_80 [ 0 ] = V_14 -> V_16 ;
return F_61 ( V_14 , V_59 ) ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_169 -> V_80 . integer . V_80 [ 0 ] = V_39 ;
return 0 ;
}
static int F_83 ( struct V_92 * V_93 ,
struct V_168 * V_169 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_39 , V_172 , V_59 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_172 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_169 -> V_80 . integer . V_80 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_172 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_84 ( struct V_2 * V_3 , int V_4 ,
void * V_180 , struct V_218 * V_105 ,
char * V_11 )
{
struct V_140 * V_183 = V_180 ;
int V_215 = V_183 -> V_143 ;
struct V_13 * V_14 ;
struct V_92 * V_106 ;
int V_152 , V_59 , V_187 , type , V_36 ;
struct V_218 * V_219 ;
struct V_220 * V_221 ;
const struct V_1 * V_7 ;
static struct V_220 V_222 [] = {
{ 0x01 , L_50 , V_41 } ,
{ 0 }
} ;
static struct V_218 V_223 = {
0 , NULL , V_222
} ;
if ( V_183 -> V_30 < 13 || V_183 -> V_30 < 13 + V_215 ||
V_183 -> V_30 < V_215 + F_85 ( V_183 , V_3 -> V_55 -> V_78 ) ) {
F_25 ( V_3 -> V_37 , L_51 , V_11 , V_4 ) ;
return - V_65 ;
}
for ( V_152 = 0 ; V_152 < V_215 ; V_152 ++ ) {
if ( ( V_59 = F_73 ( V_3 , V_183 -> V_138 [ V_152 ] ) ) < 0 )
return V_59 ;
}
type = F_43 ( V_183 -> V_224 ) ;
for ( V_219 = V_105 ; V_219 && V_219 -> type ; V_219 ++ )
if ( V_219 -> type == type )
break;
if ( ! V_219 || ! V_219 -> type )
V_219 = & V_223 ;
for ( V_221 = V_219 -> V_225 ; V_221 -> V_5 ; V_221 ++ ) {
T_1 * V_226 = F_86 ( V_183 , V_3 -> V_55 -> V_78 ) ;
if ( ! ( V_226 [ V_221 -> V_5 / 8 ] & ( 1 << ( ( V_221 -> V_5 % 8 ) - 1 ) ) ) )
continue;
V_7 = F_1 ( V_3 , V_4 , V_221 -> V_5 ) ;
if ( F_4 ( V_7 ) )
continue;
V_14 = F_68 ( sizeof( * V_14 ) , V_190 ) ;
if ( ! V_14 )
return - V_98 ;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_5 = V_221 -> V_5 ;
V_14 -> V_40 = V_221 -> V_40 ;
V_14 -> V_125 = 1 ;
if ( type == V_227 && V_14 -> V_5 == V_228 ) {
T_1 * V_229 = F_87 ( V_183 , V_3 -> V_55 -> V_78 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_229 [ 0 ] ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else {
if ( type == V_230 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 5 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else
F_80 ( V_14 , V_221 -> V_231 ) ;
}
V_106 = F_70 ( & V_232 , V_14 ) ;
if ( ! V_106 ) {
F_53 ( V_14 ) ;
return - V_98 ;
}
V_106 -> V_195 = F_52 ;
if ( F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ) {
;
} else if ( V_219 -> V_11 ) {
F_3 ( V_106 -> V_8 . V_11 , V_219 -> V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
} else {
V_187 = F_51 ( V_183 , V_3 -> V_55 -> V_78 ) ;
V_36 = 0 ;
if ( V_187 )
V_36 = F_9 ( V_3 , V_187 ,
V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
F_3 ( V_106 -> V_8 . V_11 , V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
}
F_63 ( V_106 , L_52 ) ;
F_63 ( V_106 , V_221 -> V_233 ) ;
F_22 ( V_3 -> V_37 ,
L_53 ,
V_14 -> V_54 . V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 ,
V_14 -> V_16 , V_14 -> V_18 ) ;
V_59 = F_38 ( & V_14 -> V_54 , V_106 ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
static int F_88 ( struct V_2 * V_3 , int V_4 ,
void * V_180 )
{
return F_84 ( V_3 , V_4 , V_180 ,
V_234 , L_54 ) ;
}
static int F_89 ( struct V_2 * V_3 , int V_4 ,
void * V_180 )
{
return F_84 ( V_3 , V_4 , V_180 ,
V_235 , L_55 ) ;
}
static int F_90 ( struct V_92 * V_93 ,
struct V_159 * V_160 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
const char * * V_236 = ( const char * * ) V_93 -> V_237 ;
if ( F_91 ( ! V_236 ) )
return - V_65 ;
return F_92 ( V_160 , 1 , V_14 -> V_18 , V_236 ) ;
}
static int F_93 ( struct V_92 * V_93 ,
struct V_168 * V_169 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_39 , V_59 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_59 < 0 ) {
V_169 -> V_80 . V_238 . V_239 [ 0 ] = 0 ;
return F_61 ( V_14 , V_59 ) ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_169 -> V_80 . V_238 . V_239 [ 0 ] = V_39 ;
return 0 ;
}
static int F_94 ( struct V_92 * V_93 ,
struct V_168 * V_169 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_39 , V_172 , V_59 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_172 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_169 -> V_80 . V_238 . V_239 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_172 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static void F_95 ( struct V_92 * V_106 )
{
int V_152 , V_215 = 0 ;
if ( V_106 -> V_96 ) {
struct V_13 * V_14 = V_106 -> V_96 ;
V_215 = V_14 -> V_18 ;
F_53 ( V_14 ) ;
V_106 -> V_96 = NULL ;
}
if ( V_106 -> V_237 ) {
char * * V_236 = ( char * * ) V_106 -> V_237 ;
for ( V_152 = 0 ; V_152 < V_215 ; V_152 ++ )
F_53 ( V_236 [ V_152 ] ) ;
F_53 ( V_236 ) ;
V_106 -> V_237 = 0 ;
}
}
static int F_96 ( struct V_2 * V_3 , int V_4 ,
void * V_180 )
{
struct V_137 * V_183 = V_180 ;
unsigned int V_152 , V_187 , V_36 ;
int V_59 ;
struct V_13 * V_14 ;
struct V_92 * V_106 ;
const struct V_1 * V_7 ;
char * * V_240 ;
if ( ! V_183 -> V_143 || V_183 -> V_30 < 5 + V_183 -> V_143 ) {
F_25 ( V_3 -> V_37 ,
L_56 , V_4 ) ;
return - V_65 ;
}
for ( V_152 = 0 ; V_152 < V_183 -> V_143 ; V_152 ++ ) {
if ( ( V_59 = F_73 ( V_3 , V_183 -> V_138 [ V_152 ] ) ) < 0 )
return V_59 ;
}
if ( V_183 -> V_143 == 1 )
return 0 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
V_14 = F_68 ( sizeof( * V_14 ) , V_190 ) ;
if ( ! V_14 )
return - V_98 ;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_40 = V_43 ;
V_14 -> V_125 = 1 ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_183 -> V_143 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
if ( V_3 -> V_55 -> V_78 == V_79 )
V_14 -> V_5 = 0 ;
else
V_14 -> V_5 = ( V_183 -> V_31 == V_136 ) ?
V_241 : V_242 ;
V_240 = F_97 ( sizeof( char * ) * V_183 -> V_143 , V_190 ) ;
if ( ! V_240 ) {
F_53 ( V_14 ) ;
return - V_98 ;
}
#define F_98 64
for ( V_152 = 0 ; V_152 < V_183 -> V_143 ; V_152 ++ ) {
struct V_111 V_112 ;
V_36 = 0 ;
V_240 [ V_152 ] = F_97 ( F_98 , V_190 ) ;
if ( ! V_240 [ V_152 ] ) {
while ( V_152 -- )
F_53 ( V_240 [ V_152 ] ) ;
F_53 ( V_240 ) ;
F_53 ( V_14 ) ;
return - V_98 ;
}
V_36 = F_6 ( V_3 , V_4 , V_152 , V_240 [ V_152 ] ,
F_98 ) ;
if ( ! V_36 && F_42 ( V_3 , V_183 -> V_138 [ V_152 ] , & V_112 ) >= 0 )
V_36 = F_41 ( V_3 , & V_112 , V_240 [ V_152 ] , F_98 , 0 ) ;
if ( ! V_36 )
sprintf ( V_240 [ V_152 ] , L_57 , V_152 ) ;
}
V_106 = F_70 ( & V_243 , V_14 ) ;
if ( ! V_106 ) {
F_25 ( V_3 -> V_37 , L_34 ) ;
F_53 ( V_240 ) ;
F_53 ( V_14 ) ;
return - V_98 ;
}
V_106 -> V_237 = ( unsigned long ) V_240 ;
V_106 -> V_195 = F_95 ;
V_187 = F_48 ( V_183 ) ;
V_36 = F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( V_36 )
;
else if ( V_187 )
F_9 ( V_3 , V_187 , V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) ) ;
else {
V_36 = F_41 ( V_3 , & V_3 -> V_198 ,
V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
F_3 ( V_106 -> V_8 . V_11 , L_58 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( V_183 -> V_31 == V_136 )
F_63 ( V_106 , L_59 ) ;
else if ( ( V_3 -> V_198 . type & 0xff00 ) == 0x0100 )
F_63 ( V_106 , L_60 ) ;
else
F_63 ( V_106 , L_61 ) ;
}
F_22 ( V_3 -> V_37 , L_62 ,
V_14 -> V_54 . V_8 , V_106 -> V_8 . V_11 , V_183 -> V_143 ) ;
return F_38 ( & V_14 -> V_54 , V_106 ) ;
}
static int F_73 ( struct V_2 * V_3 , int V_4 )
{
unsigned char * V_121 ;
if ( F_99 ( V_4 , V_3 -> V_244 ) )
return 0 ;
V_121 = F_7 ( V_3 , V_4 ) ;
if ( ! V_121 ) {
F_25 ( V_3 -> V_37 , L_63 , V_4 ) ;
return - V_65 ;
}
switch ( V_121 [ 2 ] ) {
case V_32 :
case V_144 :
return 0 ;
case V_118 :
return F_81 ( V_3 , V_4 , V_121 ) ;
case V_115 :
case V_136 :
return F_96 ( V_3 , V_4 , V_121 ) ;
case V_133 :
return F_72 ( V_3 , V_4 , V_121 ) ;
case V_116 :
if ( V_3 -> V_55 -> V_78 == V_79 )
return F_88 ( V_3 , V_4 , V_121 ) ;
else
return 0 ;
case V_117 :
if ( V_3 -> V_55 -> V_78 == V_79 )
return F_89 ( V_3 , V_4 , V_121 ) ;
else
return F_88 ( V_3 , V_4 , V_121 ) ;
case V_139 :
return F_89 ( V_3 , V_4 , V_121 ) ;
default:
F_25 ( V_3 -> V_37 ,
L_64 , V_4 , V_121 [ 2 ] ) ;
return - V_65 ;
}
}
static void F_100 ( struct V_107 * V_55 )
{
F_53 ( V_55 -> V_110 ) ;
if ( V_55 -> V_245 ) {
F_53 ( V_55 -> V_245 -> V_246 ) ;
F_101 ( V_55 -> V_245 ) ;
}
F_101 ( V_55 -> V_247 ) ;
F_53 ( V_55 -> V_248 ) ;
F_53 ( V_55 ) ;
}
static int F_102 ( struct V_249 * V_250 )
{
struct V_107 * V_55 = V_250 -> V_251 ;
F_100 ( V_55 ) ;
return 0 ;
}
static int F_103 ( struct V_107 * V_55 )
{
struct V_2 V_3 ;
int V_59 ;
const struct V_252 * V_7 ;
void * V_6 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_37 = V_55 -> V_37 ;
V_3 . V_55 = V_55 ;
V_3 . V_28 = V_55 -> V_253 -> V_254 ;
V_3 . V_10 = V_55 -> V_253 -> V_255 ;
for ( V_7 = V_256 ; V_7 -> V_8 ; V_7 ++ ) {
if ( V_7 -> V_8 == V_3 . V_37 -> V_148 ) {
V_3 . V_7 = V_7 -> V_7 ;
V_3 . V_22 = V_7 -> V_22 ;
V_55 -> V_84 = V_7 -> V_84 ;
break;
}
}
V_6 = NULL ;
while ( ( V_6 = F_104 ( V_55 -> V_253 -> V_254 ,
V_55 -> V_253 -> V_255 ,
V_6 , V_257 ) ) != NULL ) {
if ( V_55 -> V_78 == V_79 ) {
struct V_258 * V_183 = V_6 ;
if ( V_183 -> V_30 < sizeof( * V_183 ) )
continue;
F_105 ( V_183 -> V_259 , V_3 . V_244 ) ;
V_3 . V_198 . V_8 = V_183 -> V_259 ;
V_3 . V_198 . type = F_43 ( V_183 -> V_124 ) ;
V_3 . V_198 . V_11 = V_183 -> V_129 ;
V_59 = F_73 ( & V_3 , V_183 -> V_134 ) ;
if ( V_59 < 0 && V_59 != - V_65 )
return V_59 ;
} else {
struct V_260 * V_183 = V_6 ;
if ( V_183 -> V_30 < sizeof( * V_183 ) )
continue;
F_105 ( V_183 -> V_259 , V_3 . V_244 ) ;
V_3 . V_198 . V_8 = V_183 -> V_259 ;
V_3 . V_198 . type = F_43 ( V_183 -> V_124 ) ;
V_3 . V_198 . V_11 = V_183 -> V_129 ;
V_59 = F_73 ( & V_3 , V_183 -> V_134 ) ;
if ( V_59 < 0 && V_59 != - V_65 )
return V_59 ;
V_59 = F_73 ( & V_3 , V_183 -> V_131 ) ;
if ( V_59 < 0 && V_59 != - V_65 )
return V_59 ;
}
}
return 0 ;
}
void F_106 ( struct V_107 * V_55 , int V_4 )
{
struct V_104 * V_105 ;
for ( V_105 = V_55 -> V_110 [ V_4 ] ; V_105 ; V_105 = V_105 -> V_109 )
F_59 ( V_55 -> V_37 -> V_108 , V_261 ,
& V_105 -> V_106 -> V_8 ) ;
}
static void F_107 ( struct V_262 * V_28 ,
struct V_104 * V_105 )
{
struct V_13 * V_14 = (struct V_13 * ) V_105 ;
static char * V_263 [] = { L_65 , L_66 ,
L_67 , L_68 , L_69 , L_70 } ;
F_108 ( V_28 , L_71
L_72 , V_14 -> V_54 . V_8 ,
V_14 -> V_5 , V_14 -> V_151 , V_14 -> V_125 ,
V_263 [ V_14 -> V_40 ] ) ;
F_108 ( V_28 , L_73 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_15 , V_14 -> V_17 ) ;
}
static void F_109 ( struct V_264 * V_265 ,
struct V_262 * V_28 )
{
struct V_53 * V_37 = V_265 -> V_96 ;
struct V_107 * V_55 ;
struct V_104 * V_105 ;
int V_4 ;
F_110 (mixer, &chip->mixer_list, list) {
F_108 ( V_28 ,
L_74 ,
V_37 -> V_148 , F_18 ( V_37 ) ,
V_55 -> V_84 ) ;
F_108 ( V_28 , L_75 , V_37 -> V_108 -> V_266 ) ;
for ( V_4 = 0 ; V_4 < V_267 ; V_4 ++ ) {
for ( V_105 = V_55 -> V_110 [ V_4 ] ; V_105 ;
V_105 = V_105 -> V_109 ) {
F_108 ( V_28 , L_76 , V_105 -> V_8 ) ;
if ( V_105 -> V_106 )
F_108 ( V_28 ,
L_77 ,
V_105 -> V_106 -> V_8 . V_11 ,
V_105 -> V_106 -> V_8 . V_20 ) ;
if ( V_105 -> V_268 )
V_105 -> V_268 ( V_28 , V_105 ) ;
}
}
}
}
static void F_111 ( struct V_107 * V_55 ,
int V_269 , int V_80 , int V_20 )
{
struct V_104 * V_105 ;
T_1 V_4 = ( V_20 >> 8 ) & 0xff ;
T_1 V_5 = ( V_80 >> 8 ) & 0xff ;
T_1 V_81 = V_80 & 0xff ;
if ( V_81 >= V_153 ) {
F_22 ( V_55 -> V_37 ,
L_78 ,
V_91 , V_81 ) ;
return;
}
for ( V_105 = V_55 -> V_110 [ V_4 ] ; V_105 ; V_105 = V_105 -> V_109 ) {
struct V_13 * V_219 ;
if ( ! V_105 -> V_106 )
continue;
V_219 = (struct V_13 * ) V_105 ;
if ( V_219 -> V_5 != V_5 )
continue;
switch ( V_269 ) {
case V_71 :
if ( V_81 )
V_219 -> V_82 &= ~ ( 1 << V_81 ) ;
else
V_219 -> V_82 = 0 ;
F_59 ( V_55 -> V_37 -> V_108 , V_261 ,
& V_219 -> V_54 . V_106 -> V_8 ) ;
break;
case V_72 :
break;
case V_270 :
break;
default:
F_22 ( V_55 -> V_37 ,
L_79 ,
V_269 ) ;
break;
}
}
}
static void F_112 ( struct V_245 * V_245 )
{
struct V_107 * V_55 = V_245 -> V_271 ;
int V_36 = V_245 -> V_272 ;
int V_273 = V_245 -> V_274 ;
if ( V_273 != 0 )
goto V_275;
if ( V_55 -> V_78 == V_79 ) {
struct V_276 * V_274 ;
for ( V_274 = V_245 -> V_246 ;
V_36 >= sizeof( * V_274 ) ;
V_36 -= sizeof( * V_274 ) , V_274 ++ ) {
F_113 ( & V_245 -> V_38 -> V_38 , L_80 ,
V_274 -> V_277 ,
V_274 -> V_278 ) ;
if ( ( V_274 -> V_277 & V_279 ) !=
V_280 )
continue;
if ( V_274 -> V_277 & V_281 )
F_114 ( V_55 , V_274 -> V_278 ) ;
else
F_106 ( V_55 , V_274 -> V_278 ) ;
}
} else {
struct V_282 * V_283 ;
for ( V_283 = V_245 -> V_246 ;
V_36 >= sizeof( * V_283 ) ;
V_36 -= sizeof( * V_283 ) , V_283 ++ ) {
if ( ( V_283 -> V_284 & V_285 ) ||
( V_283 -> V_284 & V_286 ) )
continue;
F_111 ( V_55 , V_283 -> V_287 ,
F_43 ( V_283 -> V_288 ) ,
F_43 ( V_283 -> V_289 ) ) ;
}
}
V_275:
if ( V_273 != - V_290 &&
V_273 != - V_291 &&
V_273 != - V_292 ) {
V_245 -> V_38 = V_55 -> V_37 -> V_38 ;
F_115 ( V_245 , V_293 ) ;
}
}
static int F_116 ( struct V_107 * V_55 )
{
struct V_294 * V_295 ;
void * V_246 ;
int V_296 ;
unsigned int V_297 ;
if ( F_117 ( V_55 -> V_253 ) -> V_298 < 1 )
return 0 ;
V_295 = F_118 ( V_55 -> V_253 , 0 ) ;
if ( ! F_119 ( V_295 ) || ! F_120 ( V_295 ) )
return 0 ;
V_297 = F_121 ( V_295 ) ;
V_296 = F_43 ( V_295 -> V_299 ) ;
V_246 = F_97 ( V_296 , V_190 ) ;
if ( ! V_246 )
return - V_98 ;
V_55 -> V_245 = F_122 ( 0 , V_190 ) ;
if ( ! V_55 -> V_245 ) {
F_53 ( V_246 ) ;
return - V_98 ;
}
F_123 ( V_55 -> V_245 , V_55 -> V_37 -> V_38 ,
F_124 ( V_55 -> V_37 -> V_38 , V_297 ) ,
V_246 , V_296 ,
F_112 , V_55 , V_295 -> V_300 ) ;
F_115 ( V_55 -> V_245 , V_190 ) ;
return 0 ;
}
int F_125 ( struct V_53 * V_37 , int V_301 ,
int V_302 )
{
static struct V_303 V_304 = {
. V_305 = F_102
} ;
struct V_107 * V_55 ;
struct V_264 * V_265 ;
int V_59 ;
strcpy ( V_37 -> V_108 -> V_306 , L_81 ) ;
V_55 = F_68 ( sizeof( * V_55 ) , V_190 ) ;
if ( ! V_55 )
return - V_98 ;
V_55 -> V_37 = V_37 ;
V_55 -> V_84 = V_302 ;
V_55 -> V_110 = F_126 ( V_267 , sizeof( * V_55 -> V_110 ) ,
V_190 ) ;
if ( ! V_55 -> V_110 ) {
F_53 ( V_55 ) ;
return - V_98 ;
}
V_55 -> V_253 = & F_127 ( V_37 -> V_38 , V_301 ) -> V_307 [ 0 ] ;
switch ( F_117 ( V_55 -> V_253 ) -> V_308 ) {
case V_79 :
default:
V_55 -> V_78 = V_79 ;
break;
case V_141 :
V_55 -> V_78 = V_141 ;
break;
}
if ( ( V_59 = F_103 ( V_55 ) ) < 0 ||
( V_59 = F_116 ( V_55 ) ) < 0 )
goto V_309;
F_128 ( V_55 ) ;
V_59 = F_129 ( V_37 -> V_108 , V_310 , V_55 , & V_304 ) ;
if ( V_59 < 0 )
goto V_309;
if ( F_130 ( & V_37 -> V_311 ) &&
! F_131 ( V_37 -> V_108 , L_82 , & V_265 ) )
F_132 ( V_265 , V_37 , F_109 ) ;
F_133 ( & V_55 -> V_105 , & V_37 -> V_311 ) ;
return 0 ;
V_309:
F_100 ( V_55 ) ;
return V_59 ;
}
void F_134 ( struct V_107 * V_55 )
{
F_135 ( V_55 -> V_245 ) ;
F_135 ( V_55 -> V_247 ) ;
}
static void F_136 ( struct V_107 * V_55 )
{
F_135 ( V_55 -> V_245 ) ;
F_135 ( V_55 -> V_247 ) ;
}
static int F_137 ( struct V_107 * V_55 )
{
int V_59 ;
if ( V_55 -> V_245 ) {
V_59 = F_115 ( V_55 -> V_245 , V_312 ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
int F_138 ( struct V_107 * V_55 )
{
F_136 ( V_55 ) ;
return 0 ;
}
static int F_139 ( struct V_104 * V_105 )
{
struct V_13 * V_14 = (struct V_13 * ) V_105 ;
int V_170 , V_59 , V_58 ;
if ( V_14 -> V_151 ) {
V_58 = 0 ;
for ( V_170 = 0 ; V_170 < V_153 ; V_170 ++ ) {
if ( ! ( V_14 -> V_151 & ( 1 << V_170 ) ) )
continue;
if ( V_14 -> V_82 & ( 1 << ( V_170 + 1 ) ) ) {
V_59 = F_33 ( V_14 , V_170 + 1 , V_58 ,
V_14 -> V_83 [ V_58 ] ) ;
if ( V_59 < 0 )
return V_59 ;
}
V_58 ++ ;
}
} else {
if ( V_14 -> V_82 ) {
V_59 = F_33 ( V_14 , 0 , 0 , * V_14 -> V_83 ) ;
if ( V_59 < 0 )
return V_59 ;
}
}
return 0 ;
}
int F_140 ( struct V_107 * V_55 , bool V_313 )
{
struct V_104 * V_105 ;
int V_8 , V_59 ;
if ( V_313 ) {
for ( V_8 = 0 ; V_8 < V_267 ; V_8 ++ ) {
for ( V_105 = V_55 -> V_110 [ V_8 ] ; V_105 ;
V_105 = V_105 -> V_109 ) {
if ( V_105 -> V_314 ) {
V_59 = V_105 -> V_314 ( V_105 ) ;
if ( V_59 < 0 )
return V_59 ;
}
}
}
}
return F_137 ( V_55 ) ;
}
void F_69 ( struct V_104 * V_105 ,
struct V_107 * V_55 ,
int V_4 )
{
V_105 -> V_55 = V_55 ;
V_105 -> V_8 = V_4 ;
V_105 -> V_268 = F_107 ;
#ifdef F_141
V_105 -> V_314 = F_139 ;
#endif
}
