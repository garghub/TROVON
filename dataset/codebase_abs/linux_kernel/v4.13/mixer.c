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
if ( V_14 -> V_99 )
V_97 [ 0 ] = V_100 ;
V_97 [ 2 ] = V_14 -> V_15 ;
V_97 [ 3 ] = V_14 -> V_17 ;
if ( F_36 ( V_95 , V_97 , sizeof( V_97 ) ) )
return - V_101 ;
return 0 ;
}
static int F_37 ( unsigned char * V_102 ,
int V_103 , int V_104 , int V_105 )
{
int V_58 = V_103 * V_105 + V_104 ;
return V_102 [ V_58 >> 3 ] & ( 0x80 >> ( V_58 & 7 ) ) ;
}
int F_38 ( struct V_106 * V_107 ,
struct V_92 * V_108 )
{
struct V_109 * V_55 = V_107 -> V_55 ;
int V_59 ;
while ( F_39 ( V_55 -> V_37 -> V_110 , & V_108 -> V_8 ) )
V_108 -> V_8 . V_20 ++ ;
if ( ( V_59 = F_40 ( V_55 -> V_37 -> V_110 , V_108 ) ) < 0 ) {
F_22 ( V_55 -> V_37 , L_6 ,
V_59 ) ;
return V_59 ;
}
V_107 -> V_108 = V_108 ;
V_107 -> V_111 = V_55 -> V_112 [ V_107 -> V_8 ] ;
V_55 -> V_112 [ V_107 -> V_8 ] = V_107 ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_113 * V_114 ,
unsigned char * V_11 , int V_35 , int V_115 )
{
struct V_116 * V_24 ;
if ( V_114 -> V_11 )
return F_9 ( V_3 , V_114 -> V_11 ,
V_11 , V_35 ) ;
if ( V_114 -> type >> 16 ) {
if ( V_115 )
return 0 ;
switch ( V_114 -> type >> 16 ) {
case V_117 :
strcpy ( V_11 , L_7 ) ;
return 8 ;
case V_118 :
strcpy ( V_11 , L_8 ) ;
return 12 ;
case V_119 :
strcpy ( V_11 , L_9 ) ;
return 8 ;
case V_120 :
strcpy ( V_11 , L_10 ) ;
return 5 ;
default:
return sprintf ( V_11 , L_11 , V_114 -> V_8 ) ;
}
}
switch ( V_114 -> type & 0xff00 ) {
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
for ( V_24 = V_121 ; V_24 -> type ; V_24 ++ ) {
if ( V_24 -> type == V_114 -> type ) {
strcpy ( V_11 , V_24 -> V_11 ) ;
return strlen ( V_24 -> V_11 ) ;
}
}
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , int V_8 ,
struct V_113 * V_122 )
{
int V_59 ;
void * V_123 ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
while ( ( V_123 = F_7 ( V_3 , V_8 ) ) != NULL ) {
unsigned char * V_27 = V_123 ;
V_122 -> V_8 = V_8 ;
switch ( V_27 [ 2 ] ) {
case V_32 :
if ( V_3 -> V_55 -> V_78 == V_79 ) {
struct V_124 * V_125 = V_123 ;
V_122 -> type = F_43 ( V_125 -> V_126 ) ;
V_122 -> V_127 = V_125 -> V_128 ;
V_122 -> V_129 = F_43 ( V_125 -> V_130 ) ;
V_122 -> V_11 = V_125 -> V_131 ;
} else {
struct V_132 * V_125 = V_123 ;
V_59 = F_42 ( V_3 , V_125 -> V_133 , V_122 ) ;
if ( V_59 < 0 )
return V_59 ;
V_122 -> V_8 = V_8 ;
V_122 -> type = F_43 ( V_125 -> V_126 ) ;
V_122 -> V_127 = V_125 -> V_128 ;
V_122 -> V_129 = F_44 ( V_125 -> V_134 ) ;
V_122 -> V_11 = V_125 -> V_131 ;
}
return 0 ;
case V_135 : {
struct V_26 * V_125 = V_123 ;
V_8 = V_125 -> V_136 ;
break;
}
case V_120 : {
struct V_137 * V_125 = V_123 ;
V_122 -> type = V_125 -> V_31 << 16 ;
V_122 -> V_127 = F_45 ( V_125 ) ;
V_122 -> V_129 = F_46 ( V_125 , V_3 -> V_55 -> V_78 ) ;
V_122 -> V_11 = F_47 ( V_125 ) ;
return 0 ;
}
case V_117 :
case V_138 : {
struct V_139 * V_125 = V_123 ;
V_59 = F_42 ( V_3 , V_125 -> V_140 [ 0 ] , V_122 ) ;
if ( V_59 < 0 )
return V_59 ;
V_122 -> type = V_125 -> V_31 << 16 ;
V_122 -> V_8 = V_8 ;
V_122 -> V_11 = F_48 ( V_125 ) ;
return 0 ;
}
case V_118 :
case V_119 :
case V_141 : {
struct V_142 * V_125 = V_123 ;
if ( V_3 -> V_55 -> V_78 == V_143 &&
V_27 [ 2 ] == V_144 ) {
return 0 ;
}
if ( V_125 -> V_145 ) {
V_8 = V_125 -> V_140 [ 0 ] ;
break;
}
V_122 -> type = V_125 -> V_31 << 16 ;
V_122 -> V_127 = F_49 ( V_125 ) ;
V_122 -> V_129 = F_50 ( V_125 , V_3 -> V_55 -> V_78 ) ;
V_122 -> V_11 = F_51 ( V_125 , V_3 -> V_55 -> V_78 ) ;
return 0 ;
}
case V_146 : {
struct V_147 * V_125 = V_123 ;
V_122 -> type = V_125 -> V_31 << 16 ;
V_122 -> V_8 = V_8 ;
V_122 -> V_11 = V_125 -> V_148 ;
return 0 ;
}
default:
return - V_149 ;
}
}
return - V_149 ;
}
void F_52 ( struct V_92 * V_108 )
{
F_53 ( V_108 -> V_96 ) ;
V_108 -> V_96 = NULL ;
}
static void F_54 ( struct V_13 * V_14 ,
struct V_92 * V_108 )
{
struct V_53 * V_37 = V_14 -> V_54 . V_55 -> V_37 ;
switch ( V_37 -> V_150 ) {
case F_55 ( 0x0763 , 0x2030 ) :
case F_55 ( 0x0763 , 0x2031 ) :
if ( strcmp ( V_108 -> V_8 . V_11 , L_16 ) == 0 ) {
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0xffff ;
V_14 -> V_47 = 0x00e6 ;
break;
}
if ( strcmp ( V_108 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_108 -> V_8 . V_11 , L_18 ) == 0 ) {
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0xff ;
break;
}
if ( strstr ( V_108 -> V_8 . V_11 , L_19 ) != NULL ) {
V_14 -> V_16 = 0xb706 ;
V_14 -> V_18 = 0xff7b ;
V_14 -> V_47 = 0x0073 ;
break;
}
if ( ( strstr ( V_108 -> V_8 . V_11 , L_20 ) != NULL ) ||
( strstr ( V_108 -> V_8 . V_11 , L_21 ) != NULL ) ) {
V_14 -> V_16 = 0xb5fb ;
V_14 -> V_18 = 0xfcfe ;
V_14 -> V_47 = 0x0073 ;
}
break;
case F_55 ( 0x0763 , 0x2081 ) :
case F_55 ( 0x0763 , 0x2080 ) :
if ( strcmp ( V_108 -> V_8 . V_11 , L_16 ) == 0 ) {
F_56 ( V_37 ,
L_22 ) ;
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0x7f00 ;
V_14 -> V_47 = 0x0100 ;
break;
}
if ( strcmp ( V_108 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_108 -> V_8 . V_11 , L_18 ) == 0 ) {
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
if ( ! strcmp ( V_108 -> V_8 . V_11 , L_24 ) &&
V_14 -> V_16 == - 15616 ) {
F_56 ( V_37 ,
L_25 ) ;
V_14 -> V_18 = - 256 ;
}
break;
case F_55 ( 0x046d , 0x09a4 ) :
if ( ! strcmp ( V_108 -> V_8 . V_11 , L_26 ) ) {
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
case F_55 ( 0x046d , 0x09a2 ) :
if ( ! strcmp ( V_108 -> V_8 . V_11 , L_26 ) ) {
F_56 ( V_37 ,
L_28 ) ;
V_14 -> V_47 = 384 ;
}
break;
}
}
static int F_57 ( struct V_13 * V_14 ,
int V_151 , struct V_92 * V_108 )
{
V_14 -> V_16 = V_151 ;
V_14 -> V_18 = V_14 -> V_16 + 1 ;
V_14 -> V_47 = 1 ;
V_14 -> V_15 = V_14 -> V_17 = 0 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_14 -> V_19 = 1 ;
} else {
int V_152 = 0 ;
if ( V_14 -> V_153 ) {
int V_154 ;
for ( V_154 = 0 ; V_154 < V_155 ; V_154 ++ )
if ( V_14 -> V_153 & ( 1 << V_154 ) ) {
V_152 = V_154 + 1 ;
break;
}
}
if ( F_26 ( V_14 , V_75 , ( V_14 -> V_5 << 8 ) | V_152 , & V_14 -> V_18 ) < 0 ||
F_26 ( V_14 , V_73 , ( V_14 -> V_5 << 8 ) | V_152 , & V_14 -> V_16 ) < 0 ) {
F_25 ( V_14 -> V_54 . V_55 -> V_37 ,
L_29 ,
V_14 -> V_54 . V_8 , F_18 ( V_14 -> V_54 . V_55 -> V_37 ) ,
V_14 -> V_5 , V_14 -> V_54 . V_8 ) ;
return - V_65 ;
}
if ( F_26 ( V_14 , V_76 ,
( V_14 -> V_5 << 8 ) | V_152 ,
& V_14 -> V_47 ) < 0 ) {
V_14 -> V_47 = 1 ;
} else {
int V_156 = V_14 -> V_47 ;
while ( V_14 -> V_47 > 1 ) {
if ( F_30 ( V_14 , V_157 ,
( V_14 -> V_5 << 8 ) | V_152 ,
V_14 -> V_47 / 2 ) < 0 )
break;
V_14 -> V_47 /= 2 ;
}
if ( F_26 ( V_14 , V_76 ,
( V_14 -> V_5 << 8 ) | V_152 , & V_14 -> V_47 ) < 0 )
V_14 -> V_47 = V_156 ;
}
if ( V_14 -> V_47 == 0 )
V_14 -> V_47 = 1 ;
if ( V_14 -> V_16 + V_14 -> V_47 < V_14 -> V_18 ) {
int V_156 = V_14 -> V_47 ;
int V_158 , V_159 , V_160 ;
F_28 ( V_14 , V_152 , & V_158 ) ;
for (; ; ) {
V_159 = V_158 ;
if ( V_159 < V_14 -> V_18 )
V_159 += V_14 -> V_47 ;
else
V_159 -= V_14 -> V_47 ;
if ( V_159 < V_14 -> V_16 || V_159 > V_14 -> V_18 ||
F_33 ( V_14 , V_152 , 0 , V_159 ) ||
F_28 ( V_14 , V_152 , & V_160 ) ) {
V_14 -> V_47 = V_156 ;
break;
}
if ( V_159 == V_160 )
break;
V_14 -> V_47 *= 2 ;
}
F_33 ( V_14 , V_152 , 0 , V_158 ) ;
}
V_14 -> V_19 = 1 ;
}
if ( V_108 )
F_54 ( V_14 , V_108 ) ;
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
struct V_161 * V_162 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 )
V_162 -> type = V_163 ;
else
V_162 -> type = V_164 ;
V_162 -> V_23 = V_14 -> V_127 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_162 -> V_80 . integer . V_16 = 0 ;
V_162 -> V_80 . integer . V_18 = 1 ;
} else {
if ( ! V_14 -> V_19 ) {
F_57 ( V_14 , 0 , V_93 ) ;
if ( V_14 -> V_19 && V_14 -> V_15 >= V_14 -> V_17 ) {
V_93 -> V_165 [ 0 ] . V_166 &=
~ ( V_167 |
V_168 ) ;
F_59 ( V_14 -> V_54 . V_55 -> V_37 -> V_110 ,
V_169 ,
& V_93 -> V_8 ) ;
}
}
V_162 -> V_80 . integer . V_16 = 0 ;
V_162 -> V_80 . integer . V_18 =
( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
}
return 0 ;
}
static int F_60 ( struct V_92 * V_93 ,
struct V_170 * V_171 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_172 , V_173 , V_39 , V_59 ;
V_171 -> V_80 . integer . V_80 [ 0 ] = V_14 -> V_16 ;
if ( V_14 -> V_153 ) {
V_173 = 0 ;
for ( V_172 = 0 ; V_172 < V_155 ; V_172 ++ ) {
if ( ! ( V_14 -> V_153 & ( 1 << V_172 ) ) )
continue;
V_59 = F_29 ( V_14 , V_172 + 1 , V_173 , & V_39 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_171 -> V_80 . integer . V_80 [ V_173 ] = V_39 ;
V_173 ++ ;
}
return 0 ;
} else {
V_59 = F_29 ( V_14 , 0 , 0 , & V_39 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_171 -> V_80 . integer . V_80 [ 0 ] = V_39 ;
}
return 0 ;
}
static int F_62 ( struct V_92 * V_93 ,
struct V_170 * V_171 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_172 , V_173 , V_39 , V_174 , V_59 ;
int V_175 = 0 ;
if ( V_14 -> V_153 ) {
V_173 = 0 ;
for ( V_172 = 0 ; V_172 < V_155 ; V_172 ++ ) {
if ( ! ( V_14 -> V_153 & ( 1 << V_172 ) ) )
continue;
V_59 = F_29 ( V_14 , V_172 + 1 , V_173 , & V_174 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_171 -> V_80 . integer . V_80 [ V_173 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_174 != V_39 ) {
F_33 ( V_14 , V_172 + 1 , V_173 , V_39 ) ;
V_175 = 1 ;
}
V_173 ++ ;
}
} else {
V_59 = F_29 ( V_14 , 0 , 0 , & V_174 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_171 -> V_80 . integer . V_80 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_174 ) {
F_33 ( V_14 , 0 , 0 , V_39 ) ;
V_175 = 1 ;
}
}
return V_175 ;
}
static T_3 F_63 ( struct V_92 * V_108 , const char * V_176 )
{
return F_64 ( V_108 -> V_8 . V_11 , V_176 , sizeof( V_108 -> V_8 . V_11 ) ) ;
}
static void F_65 ( struct V_92 * V_108 ,
struct V_177 * V_110 )
{
const char * V_178 [] = {
L_14 , L_30 , L_31 , L_32 , NULL } ;
const char * * V_179 ;
bool V_180 = false ;
if ( strcmp ( L_33 , V_108 -> V_8 . V_11 ) )
return;
for ( V_179 = V_178 ; * V_179 ; V_179 ++ )
if ( strstr ( V_110 -> V_181 , * V_179 ) ) {
V_180 = true ;
break;
}
if ( ! V_180 )
return;
F_3 ( V_108 -> V_8 . V_11 , L_31 , sizeof( V_108 -> V_8 . V_11 ) ) ;
}
static void F_66 ( struct V_2 * V_3 , void * V_182 ,
unsigned int V_183 , int V_5 ,
struct V_113 * V_114 , int V_4 ,
int V_184 )
{
struct V_26 * V_185 = V_182 ;
struct V_186 * V_187 ;
unsigned int V_36 = 0 ;
int V_188 = 0 ;
int V_189 = F_67 ( V_185 ) ;
struct V_92 * V_108 ;
struct V_13 * V_14 ;
const struct V_1 * V_7 ;
unsigned int V_190 ;
V_5 ++ ;
if ( V_5 == V_191 ) {
return;
}
V_7 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_192 ) ;
if ( ! V_14 )
return;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_5 = V_5 ;
V_14 -> V_153 = V_183 ;
V_187 = & V_193 [ V_5 - 1 ] ;
if ( V_3 -> V_55 -> V_78 == V_79 )
V_14 -> V_40 = V_187 -> type ;
else
V_14 -> V_40 = V_187 -> V_194 >= 0 ?
V_187 -> V_194 : V_187 -> type ;
if ( V_183 == 0 ) {
V_14 -> V_127 = 1 ;
V_14 -> V_89 = V_184 ;
} else {
int V_154 , V_172 = 0 ;
for ( V_154 = 0 ; V_154 < 16 ; V_154 ++ )
if ( V_183 & ( 1 << V_154 ) )
V_172 ++ ;
V_14 -> V_127 = V_172 ;
V_14 -> V_90 = V_184 ;
}
if ( V_14 -> V_127 == V_184 )
V_108 = F_70 ( & V_195 , V_14 ) ;
else
V_108 = F_70 ( & V_196 , V_14 ) ;
if ( ! V_108 ) {
F_25 ( V_3 -> V_37 , L_34 ) ;
F_53 ( V_14 ) ;
return;
}
V_108 -> V_197 = F_52 ;
V_36 = F_2 ( V_7 , V_108 -> V_8 . V_11 , sizeof( V_108 -> V_8 . V_11 ) ) ;
V_188 = V_36 != 0 ;
if ( ! V_36 && V_189 )
V_36 = F_9 ( V_3 , V_189 ,
V_108 -> V_8 . V_11 , sizeof( V_108 -> V_8 . V_11 ) ) ;
switch ( V_5 ) {
case V_198 :
case V_199 :
if ( ! V_36 ) {
V_36 = F_41 ( V_3 , V_114 , V_108 -> V_8 . V_11 ,
sizeof( V_108 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = F_41 ( V_3 , & V_3 -> V_200 ,
V_108 -> V_8 . V_11 ,
sizeof( V_108 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
snprintf ( V_108 -> V_8 . V_11 , sizeof( V_108 -> V_8 . V_11 ) ,
L_35 , V_4 ) ;
}
if ( ! V_188 )
F_65 ( V_108 , V_3 -> V_55 -> V_37 -> V_110 ) ;
if ( ! V_188 && ! ( V_3 -> V_200 . type >> 16 ) ) {
if ( ( V_3 -> V_200 . type & 0xff00 ) == 0x0100 )
F_63 ( V_108 , L_36 ) ;
else
F_63 ( V_108 , L_37 ) ;
}
F_63 ( V_108 , V_5 == V_198 ?
L_38 : L_39 ) ;
break;
default:
if ( ! V_36 )
F_3 ( V_108 -> V_8 . V_11 , V_193 [ V_5 - 1 ] . V_11 ,
sizeof( V_108 -> V_8 . V_11 ) ) ;
break;
}
F_57 ( V_14 , 0 , V_108 ) ;
if ( V_5 == V_199 ) {
F_5 ( V_7 , V_14 ) ;
if ( V_14 -> V_15 < V_14 -> V_17 || ! V_14 -> V_19 ) {
V_108 -> V_201 . V_172 = F_34 ;
V_108 -> V_165 [ 0 ] . V_166 |=
V_167 |
V_168 ;
}
}
F_71 ( V_3 -> V_55 , V_14 , V_4 , V_108 ) ;
V_190 = ( V_14 -> V_18 - V_14 -> V_16 ) / V_14 -> V_47 ;
if ( V_190 > 384 ) {
F_72 ( V_3 -> V_37 ,
L_40 ,
V_190 ) ;
F_72 ( V_3 -> V_37 ,
L_41 ,
V_14 -> V_54 . V_8 , V_108 -> V_8 . V_11 , V_14 -> V_127 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
}
F_22 ( V_3 -> V_37 , L_42 ,
V_14 -> V_54 . V_8 , V_108 -> V_8 . V_11 , V_14 -> V_127 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
F_38 ( & V_14 -> V_54 , V_108 ) ;
}
static int F_73 ( struct V_2 * V_3 , int V_4 ,
void * V_202 )
{
struct V_147 * V_27 = V_202 ;
struct V_13 * V_14 ;
struct V_92 * V_108 ;
char V_11 [ V_203 ] ;
int V_67 ;
if ( V_3 -> V_55 -> V_78 != V_143 )
return - V_65 ;
if ( V_27 -> V_30 != sizeof( * V_27 ) ) {
F_22 ( V_3 -> V_37 ,
L_43 ,
V_27 -> V_30 ) ;
return 0 ;
}
if ( ! F_74 ( V_27 -> V_204 ,
F_75 ( V_205 ) ) )
return 0 ;
V_14 = F_68 ( sizeof( * V_14 ) , V_192 ) ;
if ( ! V_14 )
return - V_98 ;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_27 -> V_206 ) ;
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 1 ;
V_14 -> V_127 = 1 ;
V_14 -> V_40 = V_41 ;
V_14 -> V_5 = V_205 ;
if ( F_76 ( V_27 -> V_204 ,
F_75 ( V_205 ) ) )
V_108 = F_70 ( & V_196 , V_14 ) ;
else {
V_14 -> V_89 = 1 ;
V_108 = F_70 ( & V_195 , V_14 ) ;
}
if ( ! V_108 ) {
F_53 ( V_14 ) ;
return - V_98 ;
}
V_108 -> V_197 = F_52 ;
V_67 = F_9 ( V_3 , V_27 -> V_148 ,
V_11 , sizeof( V_11 ) ) ;
if ( V_67 > 0 )
snprintf ( V_108 -> V_8 . V_11 , sizeof( V_108 -> V_8 . V_11 ) ,
L_44 , V_11 ) ;
else
snprintf ( V_108 -> V_8 . V_11 , sizeof( V_108 -> V_8 . V_11 ) ,
L_45 , V_27 -> V_206 ) ;
return F_38 ( & V_14 -> V_54 , V_108 ) ;
}
static int F_77 ( struct V_2 * V_3 , int V_4 ,
void * V_202 )
{
int V_127 , V_154 , V_207 ;
struct V_113 V_114 ;
unsigned int V_208 , V_209 ;
int V_59 , V_210 ;
struct V_26 * V_27 = V_202 ;
T_1 * V_211 ;
if ( V_3 -> V_55 -> V_78 == V_79 ) {
V_210 = V_27 -> V_212 ;
if ( ! V_210 ) {
F_22 ( V_3 -> V_37 ,
L_46 ,
V_4 ) ;
return - V_65 ;
}
V_127 = ( V_27 -> V_30 - 7 ) / V_210 - 1 ;
V_211 = V_27 -> V_211 ;
if ( V_27 -> V_30 < 7 + V_210 ) {
F_25 ( V_3 -> V_37 ,
L_47 ,
V_4 ) ;
return - V_65 ;
}
} else {
struct V_213 * V_214 = V_202 ;
V_210 = 4 ;
V_127 = ( V_27 -> V_30 - 6 ) / 4 - 1 ;
V_211 = V_214 -> V_211 ;
if ( V_27 -> V_30 < 6 + V_210 ) {
F_25 ( V_3 -> V_37 ,
L_47 ,
V_4 ) ;
return - V_65 ;
}
}
if ( ( V_59 = F_78 ( V_3 , V_27 -> V_136 ) ) < 0 )
return V_59 ;
V_59 = F_42 ( V_3 , V_27 -> V_136 , & V_114 ) ;
if ( V_59 < 0 )
return V_59 ;
V_208 = F_21 ( V_211 , V_210 ) ;
switch ( V_3 -> V_37 -> V_150 ) {
case F_55 ( 0x08bb , 0x2702 ) :
F_56 ( V_3 -> V_37 ,
L_48 ) ;
V_208 &= ~ F_79 ( V_199 ) ;
break;
case F_55 ( 0x1130 , 0xf211 ) :
F_56 ( V_3 -> V_37 ,
L_49 ) ;
V_127 = 0 ;
break;
}
if ( V_127 > 0 )
V_209 = F_21 ( V_211 + V_210 , V_210 ) ;
else
V_209 = 0 ;
if ( V_3 -> V_55 -> V_78 == V_79 ) {
for ( V_154 = 0 ; V_154 < 10 ; V_154 ++ ) {
unsigned int V_215 = 0 ;
for ( V_207 = 0 ; V_207 < V_127 ; V_207 ++ ) {
unsigned int V_216 ;
V_216 = F_21 ( V_211 +
V_210 * ( V_207 + 1 ) , V_210 ) ;
if ( V_216 & ( 1 << V_154 ) )
V_215 |= ( 1 << V_207 ) ;
}
if ( V_215 & 1 )
F_66 ( V_3 , V_202 , V_215 , V_154 ,
& V_114 , V_4 , 0 ) ;
if ( V_208 & ( 1 << V_154 ) )
F_66 ( V_3 , V_202 , 0 , V_154 , & V_114 ,
V_4 , 0 ) ;
}
} else {
for ( V_154 = 0 ; V_154 < F_80 ( V_193 ) ; V_154 ++ ) {
unsigned int V_215 = 0 ;
unsigned int V_217 = 0 ;
for ( V_207 = 0 ; V_207 < V_127 ; V_207 ++ ) {
unsigned int V_216 ;
V_216 = F_21 ( V_211 +
V_210 * ( V_207 + 1 ) , V_210 ) ;
if ( F_74 ( V_216 , V_154 ) ) {
V_215 |= ( 1 << V_207 ) ;
if ( ! F_76 ( V_216 , V_154 ) )
V_217 |= ( 1 << V_207 ) ;
}
}
if ( V_215 & 1 )
F_66 ( V_3 , V_202 , V_215 , V_154 ,
& V_114 , V_4 , V_217 ) ;
if ( F_74 ( V_208 , V_154 ) )
F_66 ( V_3 , V_202 , 0 , V_154 , & V_114 , V_4 ,
! F_76 ( V_208 , V_154 ) ) ;
}
}
return 0 ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_137 * V_185 ,
int V_218 , int V_219 , int V_4 ,
struct V_113 * V_114 )
{
struct V_13 * V_14 ;
unsigned int V_105 = F_45 ( V_185 ) ;
unsigned int V_154 , V_36 ;
struct V_92 * V_108 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_192 ) ;
if ( ! V_14 )
return;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_5 = V_219 + 1 ;
V_14 -> V_40 = V_46 ;
for ( V_154 = 0 ; V_154 < V_105 ; V_154 ++ ) {
T_1 * V_172 = F_82 ( V_185 , V_3 -> V_55 -> V_78 ) ;
if ( F_37 ( V_172 , V_219 , V_154 , V_105 ) ) {
V_14 -> V_153 |= ( 1 << V_154 ) ;
V_14 -> V_127 ++ ;
}
}
F_83 ( V_14 , 0 ) ;
V_108 = F_70 ( & V_196 , V_14 ) ;
if ( ! V_108 ) {
F_25 ( V_3 -> V_37 , L_34 ) ;
F_53 ( V_14 ) ;
return;
}
V_108 -> V_197 = F_52 ;
V_36 = F_2 ( V_7 , V_108 -> V_8 . V_11 , sizeof( V_108 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
V_36 = F_41 ( V_3 , V_114 , V_108 -> V_8 . V_11 ,
sizeof( V_108 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
V_36 = sprintf ( V_108 -> V_8 . V_11 , L_50 , V_219 + 1 ) ;
F_63 ( V_108 , L_39 ) ;
F_22 ( V_3 -> V_37 , L_51 ,
V_14 -> V_54 . V_8 , V_108 -> V_8 . V_11 , V_14 -> V_127 , V_14 -> V_16 , V_14 -> V_18 ) ;
F_38 ( & V_14 -> V_54 , V_108 ) ;
}
static int F_84 ( struct V_2 * V_3 , int V_4 ,
void * V_182 )
{
struct V_137 * V_185 = V_182 ;
struct V_113 V_114 ;
int V_220 , V_221 , V_105 ;
int V_222 , V_103 , V_59 ;
if ( V_185 -> V_30 < 11 || ! ( V_220 = V_185 -> V_145 ) ||
! ( V_105 = F_45 ( V_185 ) ) ) {
F_25 ( V_3 -> V_37 ,
L_52 ,
V_4 ) ;
return - V_65 ;
}
V_221 = 0 ;
V_103 = 0 ;
for ( V_222 = 0 ; V_222 < V_220 ; V_222 ++ ) {
V_59 = F_78 ( V_3 , V_185 -> V_140 [ V_222 ] ) ;
if ( V_59 < 0 )
continue;
if ( V_185 -> V_30 <= 10 + V_220 )
continue;
V_59 = F_42 ( V_3 , V_185 -> V_140 [ V_222 ] , & V_114 ) ;
if ( V_59 < 0 )
return V_59 ;
V_221 += V_114 . V_127 ;
for (; V_103 < V_221 ; V_103 ++ ) {
int V_104 , V_223 = 0 ;
for ( V_104 = 0 ; V_104 < V_105 ; V_104 ++ ) {
T_1 * V_172 = F_82 ( V_185 ,
V_3 -> V_55 -> V_78 ) ;
if ( F_37 ( V_172 , V_103 , V_104 , V_105 ) ) {
V_223 = 1 ;
break;
}
}
if ( V_223 )
F_81 ( V_3 , V_185 , V_222 , V_103 ,
V_4 , & V_114 ) ;
}
}
return 0 ;
}
static int F_85 ( struct V_92 * V_93 ,
struct V_170 * V_171 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_59 , V_39 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_59 < 0 ) {
V_171 -> V_80 . integer . V_80 [ 0 ] = V_14 -> V_16 ;
return F_61 ( V_14 , V_59 ) ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_171 -> V_80 . integer . V_80 [ 0 ] = V_39 ;
return 0 ;
}
static int F_86 ( struct V_92 * V_93 ,
struct V_170 * V_171 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_39 , V_174 , V_59 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_174 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_171 -> V_80 . integer . V_80 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_174 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_87 ( struct V_2 * V_3 , int V_4 ,
void * V_182 , struct V_224 * V_107 ,
char * V_11 )
{
struct V_142 * V_185 = V_182 ;
int V_221 = V_185 -> V_145 ;
struct V_13 * V_14 ;
struct V_92 * V_108 ;
int V_154 , V_59 , V_189 , type , V_36 ;
struct V_224 * V_225 ;
struct V_226 * V_227 ;
const struct V_1 * V_7 ;
static struct V_226 V_228 [] = {
{ 0x01 , L_53 , V_41 } ,
{ 0 }
} ;
static struct V_224 V_229 = {
0 , NULL , V_228
} ;
if ( V_185 -> V_30 < 13 || V_185 -> V_30 < 13 + V_221 ||
V_185 -> V_30 < V_221 + F_88 ( V_185 , V_3 -> V_55 -> V_78 ) ) {
F_25 ( V_3 -> V_37 , L_54 , V_11 , V_4 ) ;
return - V_65 ;
}
for ( V_154 = 0 ; V_154 < V_221 ; V_154 ++ ) {
if ( ( V_59 = F_78 ( V_3 , V_185 -> V_140 [ V_154 ] ) ) < 0 )
return V_59 ;
}
type = F_43 ( V_185 -> V_230 ) ;
for ( V_225 = V_107 ; V_225 && V_225 -> type ; V_225 ++ )
if ( V_225 -> type == type )
break;
if ( ! V_225 || ! V_225 -> type )
V_225 = & V_229 ;
for ( V_227 = V_225 -> V_231 ; V_227 -> V_5 ; V_227 ++ ) {
T_1 * V_232 = F_89 ( V_185 , V_3 -> V_55 -> V_78 ) ;
if ( ! ( V_232 [ V_227 -> V_5 / 8 ] & ( 1 << ( ( V_227 -> V_5 % 8 ) - 1 ) ) ) )
continue;
V_7 = F_1 ( V_3 , V_4 , V_227 -> V_5 ) ;
if ( F_4 ( V_7 ) )
continue;
V_14 = F_68 ( sizeof( * V_14 ) , V_192 ) ;
if ( ! V_14 )
return - V_98 ;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_5 = V_227 -> V_5 ;
V_14 -> V_40 = V_227 -> V_40 ;
V_14 -> V_127 = 1 ;
if ( type == V_233 && V_14 -> V_5 == V_234 ) {
T_1 * V_235 = F_90 ( V_185 , V_3 -> V_55 -> V_78 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_235 [ 0 ] ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else {
if ( type == V_236 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 5 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else
F_83 ( V_14 , V_227 -> V_237 ) ;
}
V_108 = F_70 ( & V_238 , V_14 ) ;
if ( ! V_108 ) {
F_53 ( V_14 ) ;
return - V_98 ;
}
V_108 -> V_197 = F_52 ;
if ( F_2 ( V_7 , V_108 -> V_8 . V_11 , sizeof( V_108 -> V_8 . V_11 ) ) ) {
;
} else if ( V_225 -> V_11 ) {
F_3 ( V_108 -> V_8 . V_11 , V_225 -> V_11 , sizeof( V_108 -> V_8 . V_11 ) ) ;
} else {
V_189 = F_51 ( V_185 , V_3 -> V_55 -> V_78 ) ;
V_36 = 0 ;
if ( V_189 )
V_36 = F_9 ( V_3 , V_189 ,
V_108 -> V_8 . V_11 ,
sizeof( V_108 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
F_3 ( V_108 -> V_8 . V_11 , V_11 , sizeof( V_108 -> V_8 . V_11 ) ) ;
}
F_63 ( V_108 , L_55 ) ;
F_63 ( V_108 , V_227 -> V_239 ) ;
F_22 ( V_3 -> V_37 ,
L_56 ,
V_14 -> V_54 . V_8 , V_108 -> V_8 . V_11 , V_14 -> V_127 ,
V_14 -> V_16 , V_14 -> V_18 ) ;
V_59 = F_38 ( & V_14 -> V_54 , V_108 ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
static int F_91 ( struct V_2 * V_3 , int V_4 ,
void * V_182 )
{
return F_87 ( V_3 , V_4 , V_182 ,
V_240 , L_57 ) ;
}
static int F_92 ( struct V_2 * V_3 , int V_4 ,
void * V_182 )
{
return F_87 ( V_3 , V_4 , V_182 ,
V_241 , L_58 ) ;
}
static int F_93 ( struct V_92 * V_93 ,
struct V_161 * V_162 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
const char * * V_242 = ( const char * * ) V_93 -> V_243 ;
if ( F_94 ( ! V_242 ) )
return - V_65 ;
return F_95 ( V_162 , 1 , V_14 -> V_18 , V_242 ) ;
}
static int F_96 ( struct V_92 * V_93 ,
struct V_170 * V_171 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_39 , V_59 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_59 < 0 ) {
V_171 -> V_80 . V_244 . V_245 [ 0 ] = 0 ;
return F_61 ( V_14 , V_59 ) ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_171 -> V_80 . V_244 . V_245 [ 0 ] = V_39 ;
return 0 ;
}
static int F_97 ( struct V_92 * V_93 ,
struct V_170 * V_171 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_39 , V_174 , V_59 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_174 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_171 -> V_80 . V_244 . V_245 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_174 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static void F_98 ( struct V_92 * V_108 )
{
int V_154 , V_221 = 0 ;
if ( V_108 -> V_96 ) {
struct V_13 * V_14 = V_108 -> V_96 ;
V_221 = V_14 -> V_18 ;
F_53 ( V_14 ) ;
V_108 -> V_96 = NULL ;
}
if ( V_108 -> V_243 ) {
char * * V_242 = ( char * * ) V_108 -> V_243 ;
for ( V_154 = 0 ; V_154 < V_221 ; V_154 ++ )
F_53 ( V_242 [ V_154 ] ) ;
F_53 ( V_242 ) ;
V_108 -> V_243 = 0 ;
}
}
static int F_99 ( struct V_2 * V_3 , int V_4 ,
void * V_182 )
{
struct V_139 * V_185 = V_182 ;
unsigned int V_154 , V_189 , V_36 ;
int V_59 ;
struct V_13 * V_14 ;
struct V_92 * V_108 ;
const struct V_1 * V_7 ;
char * * V_246 ;
if ( ! V_185 -> V_145 || V_185 -> V_30 < 5 + V_185 -> V_145 ) {
F_25 ( V_3 -> V_37 ,
L_59 , V_4 ) ;
return - V_65 ;
}
for ( V_154 = 0 ; V_154 < V_185 -> V_145 ; V_154 ++ ) {
if ( ( V_59 = F_78 ( V_3 , V_185 -> V_140 [ V_154 ] ) ) < 0 )
return V_59 ;
}
if ( V_185 -> V_145 == 1 )
return 0 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
V_14 = F_68 ( sizeof( * V_14 ) , V_192 ) ;
if ( ! V_14 )
return - V_98 ;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_40 = V_43 ;
V_14 -> V_127 = 1 ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_185 -> V_145 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
if ( V_3 -> V_55 -> V_78 == V_79 )
V_14 -> V_5 = 0 ;
else
V_14 -> V_5 = ( V_185 -> V_31 == V_138 ) ?
V_247 : V_248 ;
V_246 = F_100 ( sizeof( char * ) * V_185 -> V_145 , V_192 ) ;
if ( ! V_246 ) {
F_53 ( V_14 ) ;
return - V_98 ;
}
#define F_101 64
for ( V_154 = 0 ; V_154 < V_185 -> V_145 ; V_154 ++ ) {
struct V_113 V_114 ;
V_36 = 0 ;
V_246 [ V_154 ] = F_100 ( F_101 , V_192 ) ;
if ( ! V_246 [ V_154 ] ) {
while ( V_154 -- )
F_53 ( V_246 [ V_154 ] ) ;
F_53 ( V_246 ) ;
F_53 ( V_14 ) ;
return - V_98 ;
}
V_36 = F_6 ( V_3 , V_4 , V_154 , V_246 [ V_154 ] ,
F_101 ) ;
if ( ! V_36 && F_42 ( V_3 , V_185 -> V_140 [ V_154 ] , & V_114 ) >= 0 )
V_36 = F_41 ( V_3 , & V_114 , V_246 [ V_154 ] , F_101 , 0 ) ;
if ( ! V_36 )
sprintf ( V_246 [ V_154 ] , L_60 , V_154 ) ;
}
V_108 = F_70 ( & V_249 , V_14 ) ;
if ( ! V_108 ) {
F_25 ( V_3 -> V_37 , L_34 ) ;
F_53 ( V_246 ) ;
F_53 ( V_14 ) ;
return - V_98 ;
}
V_108 -> V_243 = ( unsigned long ) V_246 ;
V_108 -> V_197 = F_98 ;
V_189 = F_48 ( V_185 ) ;
V_36 = F_2 ( V_7 , V_108 -> V_8 . V_11 , sizeof( V_108 -> V_8 . V_11 ) ) ;
if ( V_36 )
;
else if ( V_189 )
F_9 ( V_3 , V_189 , V_108 -> V_8 . V_11 ,
sizeof( V_108 -> V_8 . V_11 ) ) ;
else {
V_36 = F_41 ( V_3 , & V_3 -> V_200 ,
V_108 -> V_8 . V_11 , sizeof( V_108 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
F_3 ( V_108 -> V_8 . V_11 , L_61 , sizeof( V_108 -> V_8 . V_11 ) ) ;
if ( V_185 -> V_31 == V_138 )
F_63 ( V_108 , L_62 ) ;
else if ( ( V_3 -> V_200 . type & 0xff00 ) == 0x0100 )
F_63 ( V_108 , L_63 ) ;
else
F_63 ( V_108 , L_64 ) ;
}
F_22 ( V_3 -> V_37 , L_65 ,
V_14 -> V_54 . V_8 , V_108 -> V_8 . V_11 , V_185 -> V_145 ) ;
return F_38 ( & V_14 -> V_54 , V_108 ) ;
}
static int F_78 ( struct V_2 * V_3 , int V_4 )
{
unsigned char * V_123 ;
if ( F_102 ( V_4 , V_3 -> V_250 ) )
return 0 ;
V_123 = F_7 ( V_3 , V_4 ) ;
if ( ! V_123 ) {
F_25 ( V_3 -> V_37 , L_66 , V_4 ) ;
return - V_65 ;
}
switch ( V_123 [ 2 ] ) {
case V_32 :
return 0 ;
case V_120 :
return F_84 ( V_3 , V_4 , V_123 ) ;
case V_146 :
return F_73 ( V_3 , V_4 , V_123 ) ;
case V_117 :
case V_138 :
return F_99 ( V_3 , V_4 , V_123 ) ;
case V_135 :
return F_77 ( V_3 , V_4 , V_123 ) ;
case V_118 :
if ( V_3 -> V_55 -> V_78 == V_79 )
return F_91 ( V_3 , V_4 , V_123 ) ;
else
return 0 ;
case V_119 :
if ( V_3 -> V_55 -> V_78 == V_79 )
return F_92 ( V_3 , V_4 , V_123 ) ;
else
return F_91 ( V_3 , V_4 , V_123 ) ;
case V_141 :
return F_92 ( V_3 , V_4 , V_123 ) ;
default:
F_25 ( V_3 -> V_37 ,
L_67 , V_4 , V_123 [ 2 ] ) ;
return - V_65 ;
}
}
static void F_103 ( struct V_109 * V_55 )
{
F_53 ( V_55 -> V_112 ) ;
if ( V_55 -> V_251 ) {
F_53 ( V_55 -> V_251 -> V_252 ) ;
F_104 ( V_55 -> V_251 ) ;
}
F_104 ( V_55 -> V_253 ) ;
F_53 ( V_55 -> V_254 ) ;
F_53 ( V_55 ) ;
}
static int F_105 ( struct V_255 * V_256 )
{
struct V_109 * V_55 = V_256 -> V_257 ;
F_103 ( V_55 ) ;
return 0 ;
}
static int F_106 ( struct V_109 * V_55 )
{
struct V_2 V_3 ;
int V_59 ;
const struct V_258 * V_7 ;
void * V_6 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_37 = V_55 -> V_37 ;
V_3 . V_55 = V_55 ;
V_3 . V_28 = V_55 -> V_259 -> V_260 ;
V_3 . V_10 = V_55 -> V_259 -> V_261 ;
for ( V_7 = V_262 ; V_7 -> V_8 ; V_7 ++ ) {
if ( V_7 -> V_8 == V_3 . V_37 -> V_150 ) {
V_3 . V_7 = V_7 -> V_7 ;
V_3 . V_22 = V_7 -> V_22 ;
V_55 -> V_84 = V_7 -> V_84 ;
break;
}
}
V_6 = NULL ;
while ( ( V_6 = F_107 ( V_55 -> V_259 -> V_260 ,
V_55 -> V_259 -> V_261 ,
V_6 , V_263 ) ) != NULL ) {
if ( V_55 -> V_78 == V_79 ) {
struct V_264 * V_185 = V_6 ;
if ( V_185 -> V_30 < sizeof( * V_185 ) )
continue;
F_108 ( V_185 -> V_265 , V_3 . V_250 ) ;
V_3 . V_200 . V_8 = V_185 -> V_265 ;
V_3 . V_200 . type = F_43 ( V_185 -> V_126 ) ;
V_3 . V_200 . V_11 = V_185 -> V_131 ;
V_59 = F_78 ( & V_3 , V_185 -> V_136 ) ;
if ( V_59 < 0 && V_59 != - V_65 )
return V_59 ;
} else {
struct V_266 * V_185 = V_6 ;
if ( V_185 -> V_30 < sizeof( * V_185 ) )
continue;
F_108 ( V_185 -> V_265 , V_3 . V_250 ) ;
V_3 . V_200 . V_8 = V_185 -> V_265 ;
V_3 . V_200 . type = F_43 ( V_185 -> V_126 ) ;
V_3 . V_200 . V_11 = V_185 -> V_131 ;
V_59 = F_78 ( & V_3 , V_185 -> V_136 ) ;
if ( V_59 < 0 && V_59 != - V_65 )
return V_59 ;
V_59 = F_78 ( & V_3 , V_185 -> V_133 ) ;
if ( V_59 < 0 && V_59 != - V_65 )
return V_59 ;
}
}
return 0 ;
}
void F_109 ( struct V_109 * V_55 , int V_4 )
{
struct V_106 * V_107 ;
for ( V_107 = V_55 -> V_112 [ V_4 ] ; V_107 ; V_107 = V_107 -> V_111 )
F_59 ( V_55 -> V_37 -> V_110 , V_267 ,
& V_107 -> V_108 -> V_8 ) ;
}
static void F_110 ( struct V_268 * V_28 ,
struct V_106 * V_107 )
{
struct V_13 * V_14 = (struct V_13 * ) V_107 ;
static char * V_269 [] = { L_68 , L_69 ,
L_70 , L_71 , L_72 , L_73 } ;
F_111 ( V_28 , L_74
L_75 , V_14 -> V_54 . V_8 ,
V_14 -> V_5 , V_14 -> V_153 , V_14 -> V_127 ,
V_269 [ V_14 -> V_40 ] ) ;
F_111 ( V_28 , L_76 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_15 , V_14 -> V_17 ) ;
}
static void F_112 ( struct V_270 * V_271 ,
struct V_268 * V_28 )
{
struct V_53 * V_37 = V_271 -> V_96 ;
struct V_109 * V_55 ;
struct V_106 * V_107 ;
int V_4 ;
F_113 (mixer, &chip->mixer_list, list) {
F_111 ( V_28 ,
L_77 ,
V_37 -> V_150 , F_18 ( V_37 ) ,
V_55 -> V_84 ) ;
F_111 ( V_28 , L_78 , V_37 -> V_110 -> V_272 ) ;
for ( V_4 = 0 ; V_4 < V_273 ; V_4 ++ ) {
for ( V_107 = V_55 -> V_112 [ V_4 ] ; V_107 ;
V_107 = V_107 -> V_111 ) {
F_111 ( V_28 , L_79 , V_107 -> V_8 ) ;
if ( V_107 -> V_108 )
F_111 ( V_28 ,
L_80 ,
V_107 -> V_108 -> V_8 . V_11 ,
V_107 -> V_108 -> V_8 . V_20 ) ;
if ( V_107 -> V_274 )
V_107 -> V_274 ( V_28 , V_107 ) ;
}
}
}
}
static void F_114 ( struct V_109 * V_55 ,
int V_275 , int V_80 , int V_20 )
{
struct V_106 * V_107 ;
T_1 V_4 = ( V_20 >> 8 ) & 0xff ;
T_1 V_5 = ( V_80 >> 8 ) & 0xff ;
T_1 V_81 = V_80 & 0xff ;
unsigned int V_23 = 0 ;
if ( V_81 >= V_155 ) {
F_22 ( V_55 -> V_37 ,
L_81 ,
V_91 , V_81 ) ;
return;
}
for ( V_107 = V_55 -> V_112 [ V_4 ] ; V_107 ; V_107 = V_107 -> V_111 )
V_23 ++ ;
if ( V_23 == 0 )
return;
for ( V_107 = V_55 -> V_112 [ V_4 ] ; V_107 ; V_107 = V_107 -> V_111 ) {
struct V_13 * V_225 ;
if ( ! V_107 -> V_108 )
continue;
V_225 = (struct V_13 * ) V_107 ;
if ( V_23 > 1 && V_225 -> V_5 != V_5 )
continue;
switch ( V_275 ) {
case V_71 :
if ( V_81 )
V_225 -> V_82 &= ~ ( 1 << V_81 ) ;
else
V_225 -> V_82 = 0 ;
F_59 ( V_55 -> V_37 -> V_110 , V_267 ,
& V_225 -> V_54 . V_108 -> V_8 ) ;
break;
case V_72 :
break;
case V_276 :
break;
default:
F_22 ( V_55 -> V_37 ,
L_82 ,
V_275 ) ;
break;
}
}
}
static void F_115 ( struct V_251 * V_251 )
{
struct V_109 * V_55 = V_251 -> V_277 ;
int V_36 = V_251 -> V_278 ;
int V_279 = V_251 -> V_280 ;
if ( V_279 != 0 )
goto V_281;
if ( V_55 -> V_78 == V_79 ) {
struct V_282 * V_280 ;
for ( V_280 = V_251 -> V_252 ;
V_36 >= sizeof( * V_280 ) ;
V_36 -= sizeof( * V_280 ) , V_280 ++ ) {
F_116 ( & V_251 -> V_38 -> V_38 , L_83 ,
V_280 -> V_283 ,
V_280 -> V_284 ) ;
if ( ( V_280 -> V_283 & V_285 ) !=
V_286 )
continue;
if ( V_280 -> V_283 & V_287 )
F_117 ( V_55 , V_280 -> V_284 ) ;
else
F_109 ( V_55 , V_280 -> V_284 ) ;
}
} else {
struct V_288 * V_289 ;
for ( V_289 = V_251 -> V_252 ;
V_36 >= sizeof( * V_289 ) ;
V_36 -= sizeof( * V_289 ) , V_289 ++ ) {
if ( ( V_289 -> V_290 & V_291 ) ||
( V_289 -> V_290 & V_292 ) )
continue;
F_114 ( V_55 , V_289 -> V_293 ,
F_43 ( V_289 -> V_294 ) ,
F_43 ( V_289 -> V_295 ) ) ;
}
}
V_281:
if ( V_279 != - V_296 &&
V_279 != - V_297 &&
V_279 != - V_298 ) {
V_251 -> V_38 = V_55 -> V_37 -> V_38 ;
F_118 ( V_251 , V_299 ) ;
}
}
static int F_119 ( struct V_109 * V_55 )
{
struct V_300 * V_301 ;
void * V_252 ;
int V_302 ;
unsigned int V_303 ;
if ( F_120 ( V_55 -> V_259 ) -> V_304 < 1 )
return 0 ;
V_301 = F_121 ( V_55 -> V_259 , 0 ) ;
if ( ! F_122 ( V_301 ) || ! F_123 ( V_301 ) )
return 0 ;
V_303 = F_124 ( V_301 ) ;
V_302 = F_43 ( V_301 -> V_305 ) ;
V_252 = F_100 ( V_302 , V_192 ) ;
if ( ! V_252 )
return - V_98 ;
V_55 -> V_251 = F_125 ( 0 , V_192 ) ;
if ( ! V_55 -> V_251 ) {
F_53 ( V_252 ) ;
return - V_98 ;
}
F_126 ( V_55 -> V_251 , V_55 -> V_37 -> V_38 ,
F_127 ( V_55 -> V_37 -> V_38 , V_303 ) ,
V_252 , V_302 ,
F_115 , V_55 , V_301 -> V_306 ) ;
F_118 ( V_55 -> V_251 , V_192 ) ;
return 0 ;
}
int F_128 ( struct V_53 * V_37 , int V_307 ,
int V_308 )
{
static struct V_309 V_310 = {
. V_311 = F_105
} ;
struct V_109 * V_55 ;
struct V_270 * V_271 ;
int V_59 ;
strcpy ( V_37 -> V_110 -> V_312 , L_84 ) ;
V_55 = F_68 ( sizeof( * V_55 ) , V_192 ) ;
if ( ! V_55 )
return - V_98 ;
V_55 -> V_37 = V_37 ;
V_55 -> V_84 = V_308 ;
V_55 -> V_112 = F_129 ( V_273 , sizeof( * V_55 -> V_112 ) ,
V_192 ) ;
if ( ! V_55 -> V_112 ) {
F_53 ( V_55 ) ;
return - V_98 ;
}
V_55 -> V_259 = & F_130 ( V_37 -> V_38 , V_307 ) -> V_313 [ 0 ] ;
switch ( F_120 ( V_55 -> V_259 ) -> V_314 ) {
case V_79 :
default:
V_55 -> V_78 = V_79 ;
break;
case V_143 :
V_55 -> V_78 = V_143 ;
break;
}
if ( ( V_59 = F_106 ( V_55 ) ) < 0 ||
( V_59 = F_119 ( V_55 ) ) < 0 )
goto V_315;
F_131 ( V_55 ) ;
V_59 = F_132 ( V_37 -> V_110 , V_316 , V_55 , & V_310 ) ;
if ( V_59 < 0 )
goto V_315;
if ( F_133 ( & V_37 -> V_317 ) &&
! F_134 ( V_37 -> V_110 , L_85 , & V_271 ) )
F_135 ( V_271 , V_37 , F_112 ) ;
F_136 ( & V_55 -> V_107 , & V_37 -> V_317 ) ;
return 0 ;
V_315:
F_103 ( V_55 ) ;
return V_59 ;
}
void F_137 ( struct V_109 * V_55 )
{
F_138 ( V_55 -> V_251 ) ;
F_138 ( V_55 -> V_253 ) ;
}
static void F_139 ( struct V_109 * V_55 )
{
F_138 ( V_55 -> V_251 ) ;
F_138 ( V_55 -> V_253 ) ;
}
static int F_140 ( struct V_109 * V_55 )
{
int V_59 ;
if ( V_55 -> V_251 ) {
V_59 = F_118 ( V_55 -> V_251 , V_318 ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
int F_141 ( struct V_109 * V_55 )
{
F_139 ( V_55 ) ;
return 0 ;
}
static int F_142 ( struct V_106 * V_107 )
{
struct V_13 * V_14 = (struct V_13 * ) V_107 ;
int V_172 , V_59 , V_58 ;
if ( V_14 -> V_153 ) {
V_58 = 0 ;
for ( V_172 = 0 ; V_172 < V_155 ; V_172 ++ ) {
if ( ! ( V_14 -> V_153 & ( 1 << V_172 ) ) )
continue;
if ( V_14 -> V_82 & ( 1 << ( V_172 + 1 ) ) ) {
V_59 = F_33 ( V_14 , V_172 + 1 , V_58 ,
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
int F_143 ( struct V_109 * V_55 , bool V_319 )
{
struct V_106 * V_107 ;
int V_8 , V_59 ;
if ( V_319 ) {
for ( V_8 = 0 ; V_8 < V_273 ; V_8 ++ ) {
for ( V_107 = V_55 -> V_112 [ V_8 ] ; V_107 ;
V_107 = V_107 -> V_111 ) {
if ( V_107 -> V_320 ) {
V_59 = V_107 -> V_320 ( V_107 ) ;
if ( V_59 < 0 )
return V_59 ;
}
}
}
}
return F_140 ( V_55 ) ;
}
void F_69 ( struct V_106 * V_107 ,
struct V_109 * V_55 ,
int V_4 )
{
V_107 -> V_55 = V_55 ;
V_107 -> V_8 = V_4 ;
V_107 -> V_274 = F_110 ;
#ifdef F_144
V_107 -> V_320 = F_142 ;
#endif
}
