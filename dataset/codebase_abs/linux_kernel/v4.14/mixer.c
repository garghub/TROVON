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
V_59 = F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_50 ,
V_61 | V_62 | V_63 ,
V_51 , V_58 , V_9 , V_56 ) ;
if ( V_59 >= V_56 ) {
* V_52 = F_11 ( V_14 , F_21 ( V_9 , V_56 ) ) ;
V_59 = 0 ;
goto V_64;
} else if ( V_59 == - V_65 ) {
goto V_64;
}
}
F_22 ( V_37 ,
L_1 ,
V_50 , V_51 , V_58 , V_14 -> V_40 ) ;
V_59 = - V_66 ;
V_64:
F_23 ( V_37 ) ;
return V_59 ;
}
static int F_24 ( struct V_13 * V_14 , int V_50 ,
int V_51 , int * V_52 )
{
struct V_53 * V_37 = V_14 -> V_54 . V_55 -> V_37 ;
unsigned char V_9 [ 4 + 3 * sizeof( V_67 ) ] ;
unsigned char * V_39 ;
int V_58 = 0 , V_68 , V_69 ;
T_1 V_70 ;
if ( V_50 == V_71 ) {
V_70 = V_72 ;
V_69 = F_15 ( V_14 -> V_40 ) ;
} else {
V_70 = V_73 ;
V_69 = sizeof( V_9 ) ;
}
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_68 = F_17 ( V_37 ) ? - V_60 : 0 ;
if ( V_68 )
goto error;
V_58 = F_18 ( V_37 ) | ( V_14 -> V_54 . V_8 << 8 ) ;
V_68 = F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_70 ,
V_61 | V_62 | V_63 ,
V_51 , V_58 , V_9 , V_69 ) ;
F_23 ( V_37 ) ;
if ( V_68 < 0 ) {
error:
F_25 ( V_37 ,
L_1 ,
V_50 , V_51 , V_58 , V_14 -> V_40 ) ;
return V_68 ;
}
switch ( V_50 ) {
case V_71 :
V_39 = V_9 ;
break;
case V_74 :
V_39 = V_9 + sizeof( V_75 ) ;
break;
case V_76 :
V_39 = V_9 + sizeof( V_75 ) * 2 ;
break;
case V_77 :
V_39 = V_9 + sizeof( V_75 ) * 3 ;
break;
default:
return - V_66 ;
}
* V_52 = F_11 ( V_14 , F_21 ( V_39 , sizeof( V_75 ) ) ) ;
return 0 ;
}
static int F_26 ( struct V_13 * V_14 , int V_50 ,
int V_51 , int * V_52 )
{
V_51 += V_14 -> V_78 ;
return ( V_14 -> V_54 . V_55 -> V_79 == V_80 ) ?
F_16 ( V_14 , V_50 , V_51 , V_52 ) :
F_24 ( V_14 , V_50 , V_51 , V_52 ) ;
}
static int F_27 ( struct V_13 * V_14 ,
int V_51 , int * V_81 )
{
return F_26 ( V_14 , V_71 , V_51 , V_81 ) ;
}
static inline int F_28 ( struct V_13 * V_14 ,
int V_82 , int * V_81 )
{
return F_26 ( V_14 , V_71 ,
( V_14 -> V_5 << 8 ) | V_82 ,
V_81 ) ;
}
int F_29 ( struct V_13 * V_14 ,
int V_82 , int V_20 , int * V_81 )
{
int V_59 ;
if ( V_14 -> V_83 & ( 1 << V_82 ) ) {
* V_81 = V_14 -> V_84 [ V_20 ] ;
return 0 ;
}
V_59 = F_28 ( V_14 , V_82 , V_81 ) ;
if ( V_59 < 0 ) {
if ( ! V_14 -> V_54 . V_55 -> V_85 )
F_22 ( V_14 -> V_54 . V_55 -> V_37 ,
L_2 ,
V_14 -> V_5 , V_82 , V_59 ) ;
return V_59 ;
}
V_14 -> V_83 |= 1 << V_82 ;
V_14 -> V_84 [ V_20 ] = * V_81 ;
return 0 ;
}
int F_30 ( struct V_13 * V_14 ,
int V_50 , int V_51 , int V_86 )
{
struct V_53 * V_37 = V_14 -> V_54 . V_55 -> V_37 ;
unsigned char V_9 [ 4 ] ;
int V_58 = 0 , V_56 , V_59 , V_57 = 10 ;
V_51 += V_14 -> V_78 ;
if ( V_14 -> V_54 . V_55 -> V_79 == V_80 ) {
V_56 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
} else {
V_56 = F_15 ( V_14 -> V_40 ) ;
if ( V_50 != V_87 ) {
F_22 ( V_37 , L_3 ) ;
return - V_66 ;
}
V_50 = V_72 ;
}
V_86 = F_12 ( V_14 , V_86 ) ;
V_9 [ 0 ] = V_86 & 0xff ;
V_9 [ 1 ] = ( V_86 >> 8 ) & 0xff ;
V_9 [ 2 ] = ( V_86 >> 16 ) & 0xff ;
V_9 [ 3 ] = ( V_86 >> 24 ) & 0xff ;
V_59 = F_17 ( V_37 ) ;
if ( V_59 < 0 )
return - V_60 ;
while ( V_57 -- > 0 ) {
V_58 = F_18 ( V_37 ) | ( V_14 -> V_54 . V_8 << 8 ) ;
V_59 = F_19 ( V_37 -> V_38 ,
F_31 ( V_37 -> V_38 , 0 ) , V_50 ,
V_61 | V_62 | V_88 ,
V_51 , V_58 , V_9 , V_56 ) ;
if ( V_59 >= 0 ) {
V_59 = 0 ;
goto V_64;
} else if ( V_59 == - V_65 ) {
goto V_64;
}
}
F_22 ( V_37 , L_4 ,
V_50 , V_51 , V_58 , V_14 -> V_40 , V_9 [ 0 ] , V_9 [ 1 ] ) ;
V_59 = - V_66 ;
V_64:
F_23 ( V_37 ) ;
return V_59 ;
}
static int F_32 ( struct V_13 * V_14 ,
int V_51 , int V_81 )
{
return F_30 ( V_14 , V_87 , V_51 , V_81 ) ;
}
int F_33 ( struct V_13 * V_14 , int V_82 ,
int V_20 , int V_81 )
{
int V_59 ;
unsigned int V_89 = ( V_82 == 0 ) ?
V_14 -> V_90 :
V_14 -> V_91 & ( 1 << ( V_82 - 1 ) ) ;
if ( V_89 ) {
F_22 ( V_14 -> V_54 . V_55 -> V_37 ,
L_5 ,
V_92 , V_82 , V_14 -> V_5 ) ;
return 0 ;
}
V_59 = F_30 ( V_14 ,
V_87 , ( V_14 -> V_5 << 8 ) | V_82 ,
V_81 ) ;
if ( V_59 < 0 )
return V_59 ;
V_14 -> V_83 |= 1 << V_82 ;
V_14 -> V_84 [ V_20 ] = V_81 ;
return 0 ;
}
int F_34 ( struct V_93 * V_94 , int V_95 ,
unsigned int V_69 , unsigned int T_2 * V_96 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
F_35 ( V_98 , 0 , 0 ) ;
if ( V_69 < sizeof( V_98 ) )
return - V_99 ;
if ( V_14 -> V_100 )
V_98 [ 0 ] = V_101 ;
V_98 [ 2 ] = V_14 -> V_15 ;
V_98 [ 3 ] = V_14 -> V_17 ;
if ( F_36 ( V_96 , V_98 , sizeof( V_98 ) ) )
return - V_102 ;
return 0 ;
}
static int F_37 ( unsigned char * V_103 ,
int V_104 , int V_105 , int V_106 )
{
int V_58 = V_104 * V_106 + V_105 ;
return V_103 [ V_58 >> 3 ] & ( 0x80 >> ( V_58 & 7 ) ) ;
}
int F_38 ( struct V_107 * V_108 ,
struct V_93 * V_109 )
{
struct V_110 * V_55 = V_108 -> V_55 ;
int V_59 ;
while ( F_39 ( V_55 -> V_37 -> V_111 , & V_109 -> V_8 ) )
V_109 -> V_8 . V_20 ++ ;
if ( ( V_59 = F_40 ( V_55 -> V_37 -> V_111 , V_109 ) ) < 0 ) {
F_22 ( V_55 -> V_37 , L_6 ,
V_59 ) ;
return V_59 ;
}
V_108 -> V_109 = V_109 ;
V_108 -> V_112 = V_55 -> V_113 [ V_108 -> V_8 ] ;
V_55 -> V_113 [ V_108 -> V_8 ] = V_108 ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 , struct V_114 * V_115 ,
unsigned char * V_11 , int V_35 , int V_116 )
{
struct V_117 * V_24 ;
if ( V_115 -> V_11 )
return F_9 ( V_3 , V_115 -> V_11 ,
V_11 , V_35 ) ;
if ( V_115 -> type >> 16 ) {
if ( V_116 )
return 0 ;
switch ( V_115 -> type >> 16 ) {
case V_118 :
strcpy ( V_11 , L_7 ) ;
return 8 ;
case V_119 :
strcpy ( V_11 , L_8 ) ;
return 12 ;
case V_120 :
strcpy ( V_11 , L_9 ) ;
return 8 ;
case V_121 :
strcpy ( V_11 , L_10 ) ;
return 5 ;
default:
return sprintf ( V_11 , L_11 , V_115 -> V_8 ) ;
}
}
switch ( V_115 -> type & 0xff00 ) {
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
for ( V_24 = V_122 ; V_24 -> type ; V_24 ++ ) {
if ( V_24 -> type == V_115 -> type ) {
strcpy ( V_11 , V_24 -> V_11 ) ;
return strlen ( V_24 -> V_11 ) ;
}
}
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , int V_8 ,
struct V_114 * V_123 )
{
int V_59 ;
void * V_124 ;
memset ( V_123 , 0 , sizeof( * V_123 ) ) ;
while ( ( V_124 = F_7 ( V_3 , V_8 ) ) != NULL ) {
unsigned char * V_27 = V_124 ;
V_123 -> V_8 = V_8 ;
switch ( V_27 [ 2 ] ) {
case V_32 :
if ( V_3 -> V_55 -> V_79 == V_80 ) {
struct V_125 * V_126 = V_124 ;
V_123 -> type = F_43 ( V_126 -> V_127 ) ;
V_123 -> V_128 = V_126 -> V_129 ;
V_123 -> V_130 = F_43 ( V_126 -> V_131 ) ;
V_123 -> V_11 = V_126 -> V_132 ;
} else {
struct V_133 * V_126 = V_124 ;
V_59 = F_42 ( V_3 , V_126 -> V_134 , V_123 ) ;
if ( V_59 < 0 )
return V_59 ;
V_123 -> V_8 = V_8 ;
V_123 -> type = F_43 ( V_126 -> V_127 ) ;
V_123 -> V_128 = V_126 -> V_129 ;
V_123 -> V_130 = F_44 ( V_126 -> V_135 ) ;
V_123 -> V_11 = V_126 -> V_132 ;
}
return 0 ;
case V_136 : {
struct V_26 * V_126 = V_124 ;
V_8 = V_126 -> V_137 ;
break;
}
case V_121 : {
struct V_138 * V_126 = V_124 ;
V_123 -> type = V_126 -> V_31 << 16 ;
V_123 -> V_128 = F_45 ( V_126 ) ;
V_123 -> V_130 = F_46 ( V_126 , V_3 -> V_55 -> V_79 ) ;
V_123 -> V_11 = F_47 ( V_126 ) ;
return 0 ;
}
case V_118 :
case V_139 : {
struct V_140 * V_126 = V_124 ;
V_59 = F_42 ( V_3 , V_126 -> V_141 [ 0 ] , V_123 ) ;
if ( V_59 < 0 )
return V_59 ;
V_123 -> type = V_126 -> V_31 << 16 ;
V_123 -> V_8 = V_8 ;
V_123 -> V_11 = F_48 ( V_126 ) ;
return 0 ;
}
case V_119 :
case V_120 :
case V_142 : {
struct V_143 * V_126 = V_124 ;
if ( V_3 -> V_55 -> V_79 == V_144 &&
V_27 [ 2 ] == V_145 ) {
return 0 ;
}
if ( V_126 -> V_146 ) {
V_8 = V_126 -> V_141 [ 0 ] ;
break;
}
V_123 -> type = V_126 -> V_31 << 16 ;
V_123 -> V_128 = F_49 ( V_126 ) ;
V_123 -> V_130 = F_50 ( V_126 , V_3 -> V_55 -> V_79 ) ;
V_123 -> V_11 = F_51 ( V_126 , V_3 -> V_55 -> V_79 ) ;
return 0 ;
}
case V_147 : {
struct V_148 * V_126 = V_124 ;
V_123 -> type = V_126 -> V_31 << 16 ;
V_123 -> V_8 = V_8 ;
V_123 -> V_11 = V_126 -> V_149 ;
return 0 ;
}
default:
return - V_150 ;
}
}
return - V_150 ;
}
void F_52 ( struct V_93 * V_109 )
{
F_53 ( V_109 -> V_97 ) ;
V_109 -> V_97 = NULL ;
}
static void F_54 ( struct V_13 * V_14 ,
struct V_93 * V_109 )
{
struct V_53 * V_37 = V_14 -> V_54 . V_55 -> V_37 ;
switch ( V_37 -> V_151 ) {
case F_55 ( 0x0763 , 0x2030 ) :
case F_55 ( 0x0763 , 0x2031 ) :
if ( strcmp ( V_109 -> V_8 . V_11 , L_16 ) == 0 ) {
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0xffff ;
V_14 -> V_47 = 0x00e6 ;
break;
}
if ( strcmp ( V_109 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_109 -> V_8 . V_11 , L_18 ) == 0 ) {
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0xff ;
break;
}
if ( strstr ( V_109 -> V_8 . V_11 , L_19 ) != NULL ) {
V_14 -> V_16 = 0xb706 ;
V_14 -> V_18 = 0xff7b ;
V_14 -> V_47 = 0x0073 ;
break;
}
if ( ( strstr ( V_109 -> V_8 . V_11 , L_20 ) != NULL ) ||
( strstr ( V_109 -> V_8 . V_11 , L_21 ) != NULL ) ) {
V_14 -> V_16 = 0xb5fb ;
V_14 -> V_18 = 0xfcfe ;
V_14 -> V_47 = 0x0073 ;
}
break;
case F_55 ( 0x0763 , 0x2081 ) :
case F_55 ( 0x0763 , 0x2080 ) :
if ( strcmp ( V_109 -> V_8 . V_11 , L_16 ) == 0 ) {
F_56 ( V_37 ,
L_22 ) ;
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0x7f00 ;
V_14 -> V_47 = 0x0100 ;
break;
}
if ( strcmp ( V_109 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_109 -> V_8 . V_11 , L_18 ) == 0 ) {
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
if ( ! strcmp ( V_109 -> V_8 . V_11 , L_24 ) &&
V_14 -> V_16 == - 15616 ) {
F_56 ( V_37 ,
L_25 ) ;
V_14 -> V_18 = - 256 ;
}
break;
case F_55 ( 0x046d , 0x09a4 ) :
if ( ! strcmp ( V_109 -> V_8 . V_11 , L_26 ) ) {
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
if ( ! strcmp ( V_109 -> V_8 . V_11 , L_26 ) ) {
F_56 ( V_37 ,
L_28 ) ;
V_14 -> V_47 = 384 ;
}
break;
}
}
static int F_57 ( struct V_13 * V_14 ,
int V_152 , struct V_93 * V_109 )
{
V_14 -> V_16 = V_152 ;
V_14 -> V_18 = V_14 -> V_16 + 1 ;
V_14 -> V_47 = 1 ;
V_14 -> V_15 = V_14 -> V_17 = 0 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_14 -> V_19 = 1 ;
} else {
int V_153 = 0 ;
if ( V_14 -> V_154 ) {
int V_155 ;
for ( V_155 = 0 ; V_155 < V_156 ; V_155 ++ )
if ( V_14 -> V_154 & ( 1 << V_155 ) ) {
V_153 = V_155 + 1 ;
break;
}
}
if ( F_26 ( V_14 , V_76 , ( V_14 -> V_5 << 8 ) | V_153 , & V_14 -> V_18 ) < 0 ||
F_26 ( V_14 , V_74 , ( V_14 -> V_5 << 8 ) | V_153 , & V_14 -> V_16 ) < 0 ) {
F_25 ( V_14 -> V_54 . V_55 -> V_37 ,
L_29 ,
V_14 -> V_54 . V_8 , F_18 ( V_14 -> V_54 . V_55 -> V_37 ) ,
V_14 -> V_5 , V_14 -> V_54 . V_8 ) ;
return - V_66 ;
}
if ( F_26 ( V_14 , V_77 ,
( V_14 -> V_5 << 8 ) | V_153 ,
& V_14 -> V_47 ) < 0 ) {
V_14 -> V_47 = 1 ;
} else {
int V_157 = V_14 -> V_47 ;
while ( V_14 -> V_47 > 1 ) {
if ( F_30 ( V_14 , V_158 ,
( V_14 -> V_5 << 8 ) | V_153 ,
V_14 -> V_47 / 2 ) < 0 )
break;
V_14 -> V_47 /= 2 ;
}
if ( F_26 ( V_14 , V_77 ,
( V_14 -> V_5 << 8 ) | V_153 , & V_14 -> V_47 ) < 0 )
V_14 -> V_47 = V_157 ;
}
if ( V_14 -> V_47 == 0 )
V_14 -> V_47 = 1 ;
if ( V_14 -> V_16 + V_14 -> V_47 < V_14 -> V_18 ) {
int V_157 = V_14 -> V_47 ;
int V_159 , V_160 , V_161 ;
F_28 ( V_14 , V_153 , & V_159 ) ;
for (; ; ) {
V_160 = V_159 ;
if ( V_160 < V_14 -> V_18 )
V_160 += V_14 -> V_47 ;
else
V_160 -= V_14 -> V_47 ;
if ( V_160 < V_14 -> V_16 || V_160 > V_14 -> V_18 ||
F_33 ( V_14 , V_153 , 0 , V_160 ) ||
F_28 ( V_14 , V_153 , & V_161 ) ) {
V_14 -> V_47 = V_157 ;
break;
}
if ( V_160 == V_161 )
break;
V_14 -> V_47 *= 2 ;
}
F_33 ( V_14 , V_153 , 0 , V_159 ) ;
}
V_14 -> V_19 = 1 ;
}
if ( V_109 )
F_54 ( V_14 , V_109 ) ;
V_14 -> V_15 = ( F_11 ( V_14 , V_14 -> V_16 ) * 100 ) / 256 ;
V_14 -> V_17 = ( F_11 ( V_14 , V_14 -> V_18 ) * 100 ) / 256 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
if ( V_14 -> V_15 < 0 )
V_14 -> V_17 = 0 ;
else if ( V_14 -> V_15 > 0 )
V_14 -> V_15 = 0 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
return - V_66 ;
}
}
return 0 ;
}
static int F_58 ( struct V_93 * V_94 ,
struct V_162 * V_163 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 )
V_163 -> type = V_164 ;
else
V_163 -> type = V_165 ;
V_163 -> V_23 = V_14 -> V_128 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_163 -> V_81 . integer . V_16 = 0 ;
V_163 -> V_81 . integer . V_18 = 1 ;
} else {
if ( ! V_14 -> V_19 ) {
F_57 ( V_14 , 0 , V_94 ) ;
if ( V_14 -> V_19 && V_14 -> V_15 >= V_14 -> V_17 ) {
V_94 -> V_166 [ 0 ] . V_167 &=
~ ( V_168 |
V_169 ) ;
F_59 ( V_14 -> V_54 . V_55 -> V_37 -> V_111 ,
V_170 ,
& V_94 -> V_8 ) ;
}
}
V_163 -> V_81 . integer . V_16 = 0 ;
V_163 -> V_81 . integer . V_18 =
( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
}
return 0 ;
}
static int F_60 ( struct V_93 * V_94 ,
struct V_171 * V_172 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_173 , V_174 , V_39 , V_59 ;
V_172 -> V_81 . integer . V_81 [ 0 ] = V_14 -> V_16 ;
if ( V_14 -> V_154 ) {
V_174 = 0 ;
for ( V_173 = 0 ; V_173 < V_156 ; V_173 ++ ) {
if ( ! ( V_14 -> V_154 & ( 1 << V_173 ) ) )
continue;
V_59 = F_29 ( V_14 , V_173 + 1 , V_174 , & V_39 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_172 -> V_81 . integer . V_81 [ V_174 ] = V_39 ;
V_174 ++ ;
}
return 0 ;
} else {
V_59 = F_29 ( V_14 , 0 , 0 , & V_39 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_172 -> V_81 . integer . V_81 [ 0 ] = V_39 ;
}
return 0 ;
}
static int F_62 ( struct V_93 * V_94 ,
struct V_171 * V_172 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_173 , V_174 , V_39 , V_175 , V_59 ;
int V_176 = 0 ;
if ( V_14 -> V_154 ) {
V_174 = 0 ;
for ( V_173 = 0 ; V_173 < V_156 ; V_173 ++ ) {
if ( ! ( V_14 -> V_154 & ( 1 << V_173 ) ) )
continue;
V_59 = F_29 ( V_14 , V_173 + 1 , V_174 , & V_175 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_172 -> V_81 . integer . V_81 [ V_174 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_175 != V_39 ) {
F_33 ( V_14 , V_173 + 1 , V_174 , V_39 ) ;
V_176 = 1 ;
}
V_174 ++ ;
}
} else {
V_59 = F_29 ( V_14 , 0 , 0 , & V_175 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_172 -> V_81 . integer . V_81 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_175 ) {
F_33 ( V_14 , 0 , 0 , V_39 ) ;
V_176 = 1 ;
}
}
return V_176 ;
}
static T_3 F_63 ( struct V_93 * V_109 , const char * V_177 )
{
return F_64 ( V_109 -> V_8 . V_11 , V_177 , sizeof( V_109 -> V_8 . V_11 ) ) ;
}
static void F_65 ( struct V_93 * V_109 ,
struct V_178 * V_111 )
{
const char * V_179 [] = {
L_14 , L_30 , L_31 , L_32 , NULL } ;
const char * * V_180 ;
bool V_181 = false ;
if ( strcmp ( L_33 , V_109 -> V_8 . V_11 ) )
return;
for ( V_180 = V_179 ; * V_180 ; V_180 ++ )
if ( strstr ( V_111 -> V_182 , * V_180 ) ) {
V_181 = true ;
break;
}
if ( ! V_181 )
return;
F_3 ( V_109 -> V_8 . V_11 , L_31 , sizeof( V_109 -> V_8 . V_11 ) ) ;
}
static void F_66 ( struct V_2 * V_3 , void * V_183 ,
unsigned int V_184 , int V_5 ,
struct V_114 * V_115 , int V_4 ,
int V_185 )
{
struct V_26 * V_186 = V_183 ;
struct V_187 * V_188 ;
unsigned int V_36 = 0 ;
int V_189 = 0 ;
int V_190 = F_67 ( V_186 ) ;
struct V_93 * V_109 ;
struct V_13 * V_14 ;
const struct V_1 * V_7 ;
unsigned int V_191 ;
V_5 ++ ;
if ( V_5 == V_192 ) {
return;
}
V_7 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_193 ) ;
if ( ! V_14 )
return;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_5 = V_5 ;
V_14 -> V_154 = V_184 ;
V_188 = & V_194 [ V_5 - 1 ] ;
if ( V_3 -> V_55 -> V_79 == V_80 )
V_14 -> V_40 = V_188 -> type ;
else
V_14 -> V_40 = V_188 -> V_195 >= 0 ?
V_188 -> V_195 : V_188 -> type ;
if ( V_184 == 0 ) {
V_14 -> V_128 = 1 ;
V_14 -> V_90 = V_185 ;
} else {
int V_155 , V_173 = 0 ;
for ( V_155 = 0 ; V_155 < 16 ; V_155 ++ )
if ( V_184 & ( 1 << V_155 ) )
V_173 ++ ;
V_14 -> V_128 = V_173 ;
V_14 -> V_91 = V_185 ;
}
if ( V_14 -> V_128 == V_185 )
V_109 = F_70 ( & V_196 , V_14 ) ;
else
V_109 = F_70 ( & V_197 , V_14 ) ;
if ( ! V_109 ) {
F_25 ( V_3 -> V_37 , L_34 ) ;
F_53 ( V_14 ) ;
return;
}
V_109 -> V_198 = F_52 ;
V_36 = F_2 ( V_7 , V_109 -> V_8 . V_11 , sizeof( V_109 -> V_8 . V_11 ) ) ;
V_189 = V_36 != 0 ;
if ( ! V_36 && V_190 )
V_36 = F_9 ( V_3 , V_190 ,
V_109 -> V_8 . V_11 , sizeof( V_109 -> V_8 . V_11 ) ) ;
switch ( V_5 ) {
case V_199 :
case V_200 :
if ( ! V_36 ) {
V_36 = F_41 ( V_3 , V_115 , V_109 -> V_8 . V_11 ,
sizeof( V_109 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = F_41 ( V_3 , & V_3 -> V_201 ,
V_109 -> V_8 . V_11 ,
sizeof( V_109 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
snprintf ( V_109 -> V_8 . V_11 , sizeof( V_109 -> V_8 . V_11 ) ,
L_35 , V_4 ) ;
}
if ( ! V_189 )
F_65 ( V_109 , V_3 -> V_55 -> V_37 -> V_111 ) ;
if ( ! V_189 && ! ( V_3 -> V_201 . type >> 16 ) ) {
if ( ( V_3 -> V_201 . type & 0xff00 ) == 0x0100 )
F_63 ( V_109 , L_36 ) ;
else
F_63 ( V_109 , L_37 ) ;
}
F_63 ( V_109 , V_5 == V_199 ?
L_38 : L_39 ) ;
break;
default:
if ( ! V_36 )
F_3 ( V_109 -> V_8 . V_11 , V_194 [ V_5 - 1 ] . V_11 ,
sizeof( V_109 -> V_8 . V_11 ) ) ;
break;
}
F_57 ( V_14 , 0 , V_109 ) ;
if ( V_5 == V_200 ) {
F_5 ( V_7 , V_14 ) ;
if ( V_14 -> V_15 < V_14 -> V_17 || ! V_14 -> V_19 ) {
V_109 -> V_202 . V_173 = F_34 ;
V_109 -> V_166 [ 0 ] . V_167 |=
V_168 |
V_169 ;
}
}
F_71 ( V_3 -> V_55 , V_14 , V_4 , V_109 ) ;
V_191 = ( V_14 -> V_18 - V_14 -> V_16 ) / V_14 -> V_47 ;
if ( V_191 > 384 ) {
F_72 ( V_3 -> V_37 ,
L_40 ,
V_191 ) ;
F_72 ( V_3 -> V_37 ,
L_41 ,
V_14 -> V_54 . V_8 , V_109 -> V_8 . V_11 , V_14 -> V_128 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
}
F_22 ( V_3 -> V_37 , L_42 ,
V_14 -> V_54 . V_8 , V_109 -> V_8 . V_11 , V_14 -> V_128 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
F_38 ( & V_14 -> V_54 , V_109 ) ;
}
static int F_73 ( struct V_2 * V_3 , int V_4 ,
void * V_203 )
{
struct V_148 * V_27 = V_203 ;
struct V_13 * V_14 ;
struct V_93 * V_109 ;
char V_11 [ V_204 ] ;
int V_68 ;
if ( V_3 -> V_55 -> V_79 != V_144 )
return - V_66 ;
if ( V_27 -> V_30 != sizeof( * V_27 ) ) {
F_22 ( V_3 -> V_37 ,
L_43 ,
V_27 -> V_30 ) ;
return 0 ;
}
if ( ! F_74 ( V_27 -> V_205 ,
F_75 ( V_206 ) ) )
return 0 ;
V_14 = F_68 ( sizeof( * V_14 ) , V_193 ) ;
if ( ! V_14 )
return - V_99 ;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_27 -> V_207 ) ;
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 1 ;
V_14 -> V_128 = 1 ;
V_14 -> V_40 = V_41 ;
V_14 -> V_5 = V_206 ;
if ( F_76 ( V_27 -> V_205 ,
F_75 ( V_206 ) ) )
V_109 = F_70 ( & V_197 , V_14 ) ;
else {
V_14 -> V_90 = 1 ;
V_109 = F_70 ( & V_196 , V_14 ) ;
}
if ( ! V_109 ) {
F_53 ( V_14 ) ;
return - V_99 ;
}
V_109 -> V_198 = F_52 ;
V_68 = F_9 ( V_3 , V_27 -> V_149 ,
V_11 , sizeof( V_11 ) ) ;
if ( V_68 > 0 )
snprintf ( V_109 -> V_8 . V_11 , sizeof( V_109 -> V_8 . V_11 ) ,
L_44 , V_11 ) ;
else
snprintf ( V_109 -> V_8 . V_11 , sizeof( V_109 -> V_8 . V_11 ) ,
L_45 , V_27 -> V_207 ) ;
return F_38 ( & V_14 -> V_54 , V_109 ) ;
}
static int F_77 ( struct V_2 * V_3 , int V_4 ,
void * V_203 )
{
int V_128 , V_155 , V_208 ;
struct V_114 V_115 ;
unsigned int V_209 , V_210 ;
int V_59 , V_211 ;
struct V_26 * V_27 = V_203 ;
T_1 * V_212 ;
if ( V_3 -> V_55 -> V_79 == V_80 ) {
V_211 = V_27 -> V_213 ;
if ( ! V_211 ) {
F_22 ( V_3 -> V_37 ,
L_46 ,
V_4 ) ;
return - V_66 ;
}
V_128 = ( V_27 -> V_30 - 7 ) / V_211 - 1 ;
V_212 = V_27 -> V_212 ;
if ( V_27 -> V_30 < 7 + V_211 ) {
F_25 ( V_3 -> V_37 ,
L_47 ,
V_4 ) ;
return - V_66 ;
}
} else {
struct V_214 * V_215 = V_203 ;
V_211 = 4 ;
V_128 = ( V_27 -> V_30 - 6 ) / 4 - 1 ;
V_212 = V_215 -> V_212 ;
if ( V_27 -> V_30 < 6 + V_211 ) {
F_25 ( V_3 -> V_37 ,
L_47 ,
V_4 ) ;
return - V_66 ;
}
}
if ( ( V_59 = F_78 ( V_3 , V_27 -> V_137 ) ) < 0 )
return V_59 ;
V_59 = F_42 ( V_3 , V_27 -> V_137 , & V_115 ) ;
if ( V_59 < 0 )
return V_59 ;
V_209 = F_21 ( V_212 , V_211 ) ;
switch ( V_3 -> V_37 -> V_151 ) {
case F_55 ( 0x08bb , 0x2702 ) :
F_56 ( V_3 -> V_37 ,
L_48 ) ;
V_209 &= ~ F_79 ( V_200 ) ;
break;
case F_55 ( 0x1130 , 0xf211 ) :
F_56 ( V_3 -> V_37 ,
L_49 ) ;
V_128 = 0 ;
break;
}
if ( V_128 > 0 )
V_210 = F_21 ( V_212 + V_211 , V_211 ) ;
else
V_210 = 0 ;
if ( V_3 -> V_55 -> V_79 == V_80 ) {
for ( V_155 = 0 ; V_155 < 10 ; V_155 ++ ) {
unsigned int V_216 = 0 ;
for ( V_208 = 0 ; V_208 < V_128 ; V_208 ++ ) {
unsigned int V_217 ;
V_217 = F_21 ( V_212 +
V_211 * ( V_208 + 1 ) , V_211 ) ;
if ( V_217 & ( 1 << V_155 ) )
V_216 |= ( 1 << V_208 ) ;
}
if ( V_216 & 1 )
F_66 ( V_3 , V_203 , V_216 , V_155 ,
& V_115 , V_4 , 0 ) ;
if ( V_209 & ( 1 << V_155 ) )
F_66 ( V_3 , V_203 , 0 , V_155 , & V_115 ,
V_4 , 0 ) ;
}
} else {
for ( V_155 = 0 ; V_155 < F_80 ( V_194 ) ; V_155 ++ ) {
unsigned int V_216 = 0 ;
unsigned int V_218 = 0 ;
for ( V_208 = 0 ; V_208 < V_128 ; V_208 ++ ) {
unsigned int V_217 ;
V_217 = F_21 ( V_212 +
V_211 * ( V_208 + 1 ) , V_211 ) ;
if ( F_74 ( V_217 , V_155 ) ) {
V_216 |= ( 1 << V_208 ) ;
if ( ! F_76 ( V_217 , V_155 ) )
V_218 |= ( 1 << V_208 ) ;
}
}
if ( V_216 & 1 )
F_66 ( V_3 , V_203 , V_216 , V_155 ,
& V_115 , V_4 , V_218 ) ;
if ( F_74 ( V_209 , V_155 ) )
F_66 ( V_3 , V_203 , 0 , V_155 , & V_115 , V_4 ,
! F_76 ( V_209 , V_155 ) ) ;
}
}
return 0 ;
}
static void F_81 ( struct V_2 * V_3 ,
struct V_138 * V_186 ,
int V_219 , int V_220 , int V_4 ,
struct V_114 * V_115 )
{
struct V_13 * V_14 ;
unsigned int V_106 = F_45 ( V_186 ) ;
unsigned int V_155 , V_36 ;
struct V_93 * V_109 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_193 ) ;
if ( ! V_14 )
return;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_5 = V_220 + 1 ;
V_14 -> V_40 = V_46 ;
for ( V_155 = 0 ; V_155 < V_106 ; V_155 ++ ) {
T_1 * V_173 = F_82 ( V_186 , V_3 -> V_55 -> V_79 ) ;
if ( F_37 ( V_173 , V_220 , V_155 , V_106 ) ) {
V_14 -> V_154 |= ( 1 << V_155 ) ;
V_14 -> V_128 ++ ;
}
}
F_83 ( V_14 , 0 ) ;
V_109 = F_70 ( & V_197 , V_14 ) ;
if ( ! V_109 ) {
F_25 ( V_3 -> V_37 , L_34 ) ;
F_53 ( V_14 ) ;
return;
}
V_109 -> V_198 = F_52 ;
V_36 = F_2 ( V_7 , V_109 -> V_8 . V_11 , sizeof( V_109 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
V_36 = F_41 ( V_3 , V_115 , V_109 -> V_8 . V_11 ,
sizeof( V_109 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
V_36 = sprintf ( V_109 -> V_8 . V_11 , L_50 , V_220 + 1 ) ;
F_63 ( V_109 , L_39 ) ;
F_22 ( V_3 -> V_37 , L_51 ,
V_14 -> V_54 . V_8 , V_109 -> V_8 . V_11 , V_14 -> V_128 , V_14 -> V_16 , V_14 -> V_18 ) ;
F_38 ( & V_14 -> V_54 , V_109 ) ;
}
static int F_84 ( struct V_2 * V_3 , int V_4 ,
void * V_183 )
{
struct V_138 * V_186 = V_183 ;
struct V_114 V_115 ;
int V_221 , V_222 , V_106 ;
int V_223 , V_104 , V_59 ;
if ( V_186 -> V_30 < 11 || ! ( V_221 = V_186 -> V_146 ) ||
! ( V_106 = F_45 ( V_186 ) ) ) {
F_25 ( V_3 -> V_37 ,
L_52 ,
V_4 ) ;
return - V_66 ;
}
V_222 = 0 ;
V_104 = 0 ;
for ( V_223 = 0 ; V_223 < V_221 ; V_223 ++ ) {
V_59 = F_78 ( V_3 , V_186 -> V_141 [ V_223 ] ) ;
if ( V_59 < 0 )
continue;
if ( V_186 -> V_30 <= 10 + V_221 )
continue;
V_59 = F_42 ( V_3 , V_186 -> V_141 [ V_223 ] , & V_115 ) ;
if ( V_59 < 0 )
return V_59 ;
V_222 += V_115 . V_128 ;
for (; V_104 < V_222 ; V_104 ++ ) {
int V_105 , V_224 = 0 ;
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ ) {
T_1 * V_173 = F_82 ( V_186 ,
V_3 -> V_55 -> V_79 ) ;
if ( F_37 ( V_173 , V_104 , V_105 , V_106 ) ) {
V_224 = 1 ;
break;
}
}
if ( V_224 )
F_81 ( V_3 , V_186 , V_223 , V_104 ,
V_4 , & V_115 ) ;
}
}
return 0 ;
}
static int F_85 ( struct V_93 * V_94 ,
struct V_171 * V_172 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_59 , V_39 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_59 < 0 ) {
V_172 -> V_81 . integer . V_81 [ 0 ] = V_14 -> V_16 ;
return F_61 ( V_14 , V_59 ) ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_172 -> V_81 . integer . V_81 [ 0 ] = V_39 ;
return 0 ;
}
static int F_86 ( struct V_93 * V_94 ,
struct V_171 * V_172 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_39 , V_175 , V_59 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_175 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_172 -> V_81 . integer . V_81 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_175 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_87 ( struct V_2 * V_3 , int V_4 ,
void * V_183 , struct V_225 * V_108 ,
char * V_11 )
{
struct V_143 * V_186 = V_183 ;
int V_222 = V_186 -> V_146 ;
struct V_13 * V_14 ;
struct V_93 * V_109 ;
int V_155 , V_59 , V_190 , type , V_36 ;
struct V_225 * V_226 ;
struct V_227 * V_228 ;
const struct V_1 * V_7 ;
static struct V_227 V_229 [] = {
{ 0x01 , L_53 , V_41 } ,
{ 0 }
} ;
static struct V_225 V_230 = {
0 , NULL , V_229
} ;
if ( V_186 -> V_30 < 13 || V_186 -> V_30 < 13 + V_222 ||
V_186 -> V_30 < V_222 + F_88 ( V_186 , V_3 -> V_55 -> V_79 ) ) {
F_25 ( V_3 -> V_37 , L_54 , V_11 , V_4 ) ;
return - V_66 ;
}
for ( V_155 = 0 ; V_155 < V_222 ; V_155 ++ ) {
if ( ( V_59 = F_78 ( V_3 , V_186 -> V_141 [ V_155 ] ) ) < 0 )
return V_59 ;
}
type = F_43 ( V_186 -> V_231 ) ;
for ( V_226 = V_108 ; V_226 && V_226 -> type ; V_226 ++ )
if ( V_226 -> type == type )
break;
if ( ! V_226 || ! V_226 -> type )
V_226 = & V_230 ;
for ( V_228 = V_226 -> V_232 ; V_228 -> V_5 ; V_228 ++ ) {
T_1 * V_233 = F_89 ( V_186 , V_3 -> V_55 -> V_79 ) ;
if ( ! ( V_233 [ V_228 -> V_5 / 8 ] & ( 1 << ( ( V_228 -> V_5 % 8 ) - 1 ) ) ) )
continue;
V_7 = F_1 ( V_3 , V_4 , V_228 -> V_5 ) ;
if ( F_4 ( V_7 ) )
continue;
V_14 = F_68 ( sizeof( * V_14 ) , V_193 ) ;
if ( ! V_14 )
return - V_99 ;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_5 = V_228 -> V_5 ;
V_14 -> V_40 = V_228 -> V_40 ;
V_14 -> V_128 = 1 ;
if ( type == V_234 && V_14 -> V_5 == V_235 ) {
T_1 * V_236 = F_90 ( V_186 , V_3 -> V_55 -> V_79 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_236 [ 0 ] ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else {
if ( type == V_237 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 5 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else
F_83 ( V_14 , V_228 -> V_238 ) ;
}
V_109 = F_70 ( & V_239 , V_14 ) ;
if ( ! V_109 ) {
F_53 ( V_14 ) ;
return - V_99 ;
}
V_109 -> V_198 = F_52 ;
if ( F_2 ( V_7 , V_109 -> V_8 . V_11 , sizeof( V_109 -> V_8 . V_11 ) ) ) {
;
} else if ( V_226 -> V_11 ) {
F_3 ( V_109 -> V_8 . V_11 , V_226 -> V_11 , sizeof( V_109 -> V_8 . V_11 ) ) ;
} else {
V_190 = F_51 ( V_186 , V_3 -> V_55 -> V_79 ) ;
V_36 = 0 ;
if ( V_190 )
V_36 = F_9 ( V_3 , V_190 ,
V_109 -> V_8 . V_11 ,
sizeof( V_109 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
F_3 ( V_109 -> V_8 . V_11 , V_11 , sizeof( V_109 -> V_8 . V_11 ) ) ;
}
F_63 ( V_109 , L_55 ) ;
F_63 ( V_109 , V_228 -> V_240 ) ;
F_22 ( V_3 -> V_37 ,
L_56 ,
V_14 -> V_54 . V_8 , V_109 -> V_8 . V_11 , V_14 -> V_128 ,
V_14 -> V_16 , V_14 -> V_18 ) ;
V_59 = F_38 ( & V_14 -> V_54 , V_109 ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
static int F_91 ( struct V_2 * V_3 , int V_4 ,
void * V_183 )
{
return F_87 ( V_3 , V_4 , V_183 ,
V_241 , L_57 ) ;
}
static int F_92 ( struct V_2 * V_3 , int V_4 ,
void * V_183 )
{
return F_87 ( V_3 , V_4 , V_183 ,
V_242 , L_58 ) ;
}
static int F_93 ( struct V_93 * V_94 ,
struct V_162 * V_163 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
const char * * V_243 = ( const char * * ) V_94 -> V_244 ;
if ( F_94 ( ! V_243 ) )
return - V_66 ;
return F_95 ( V_163 , 1 , V_14 -> V_18 , V_243 ) ;
}
static int F_96 ( struct V_93 * V_94 ,
struct V_171 * V_172 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_39 , V_59 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_59 < 0 ) {
V_172 -> V_81 . V_245 . V_246 [ 0 ] = 0 ;
return F_61 ( V_14 , V_59 ) ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_172 -> V_81 . V_245 . V_246 [ 0 ] = V_39 ;
return 0 ;
}
static int F_97 ( struct V_93 * V_94 ,
struct V_171 * V_172 )
{
struct V_13 * V_14 = V_94 -> V_97 ;
int V_39 , V_175 , V_59 ;
V_59 = F_27 ( V_14 , V_14 -> V_5 << 8 , & V_175 ) ;
if ( V_59 < 0 )
return F_61 ( V_14 , V_59 ) ;
V_39 = V_172 -> V_81 . V_245 . V_246 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_175 ) {
F_32 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static void F_98 ( struct V_93 * V_109 )
{
int V_155 , V_222 = 0 ;
if ( V_109 -> V_97 ) {
struct V_13 * V_14 = V_109 -> V_97 ;
V_222 = V_14 -> V_18 ;
F_53 ( V_14 ) ;
V_109 -> V_97 = NULL ;
}
if ( V_109 -> V_244 ) {
char * * V_243 = ( char * * ) V_109 -> V_244 ;
for ( V_155 = 0 ; V_155 < V_222 ; V_155 ++ )
F_53 ( V_243 [ V_155 ] ) ;
F_53 ( V_243 ) ;
V_109 -> V_244 = 0 ;
}
}
static int F_99 ( struct V_2 * V_3 , int V_4 ,
void * V_183 )
{
struct V_140 * V_186 = V_183 ;
unsigned int V_155 , V_190 , V_36 ;
int V_59 ;
struct V_13 * V_14 ;
struct V_93 * V_109 ;
const struct V_1 * V_7 ;
char * * V_247 ;
if ( ! V_186 -> V_146 || V_186 -> V_30 < 5 + V_186 -> V_146 ) {
F_25 ( V_3 -> V_37 ,
L_59 , V_4 ) ;
return - V_66 ;
}
for ( V_155 = 0 ; V_155 < V_186 -> V_146 ; V_155 ++ ) {
if ( ( V_59 = F_78 ( V_3 , V_186 -> V_141 [ V_155 ] ) ) < 0 )
return V_59 ;
}
if ( V_186 -> V_146 == 1 )
return 0 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
V_14 = F_68 ( sizeof( * V_14 ) , V_193 ) ;
if ( ! V_14 )
return - V_99 ;
F_69 ( & V_14 -> V_54 , V_3 -> V_55 , V_4 ) ;
V_14 -> V_40 = V_43 ;
V_14 -> V_128 = 1 ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_186 -> V_146 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
if ( V_3 -> V_55 -> V_79 == V_80 )
V_14 -> V_5 = 0 ;
else
V_14 -> V_5 = ( V_186 -> V_31 == V_139 ) ?
V_248 : V_249 ;
V_247 = F_100 ( sizeof( char * ) * V_186 -> V_146 , V_193 ) ;
if ( ! V_247 ) {
F_53 ( V_14 ) ;
return - V_99 ;
}
#define F_101 64
for ( V_155 = 0 ; V_155 < V_186 -> V_146 ; V_155 ++ ) {
struct V_114 V_115 ;
V_36 = 0 ;
V_247 [ V_155 ] = F_100 ( F_101 , V_193 ) ;
if ( ! V_247 [ V_155 ] ) {
while ( V_155 -- )
F_53 ( V_247 [ V_155 ] ) ;
F_53 ( V_247 ) ;
F_53 ( V_14 ) ;
return - V_99 ;
}
V_36 = F_6 ( V_3 , V_4 , V_155 , V_247 [ V_155 ] ,
F_101 ) ;
if ( ! V_36 && F_42 ( V_3 , V_186 -> V_141 [ V_155 ] , & V_115 ) >= 0 )
V_36 = F_41 ( V_3 , & V_115 , V_247 [ V_155 ] , F_101 , 0 ) ;
if ( ! V_36 )
sprintf ( V_247 [ V_155 ] , L_60 , V_155 ) ;
}
V_109 = F_70 ( & V_250 , V_14 ) ;
if ( ! V_109 ) {
F_25 ( V_3 -> V_37 , L_34 ) ;
F_53 ( V_247 ) ;
F_53 ( V_14 ) ;
return - V_99 ;
}
V_109 -> V_244 = ( unsigned long ) V_247 ;
V_109 -> V_198 = F_98 ;
V_190 = F_48 ( V_186 ) ;
V_36 = F_2 ( V_7 , V_109 -> V_8 . V_11 , sizeof( V_109 -> V_8 . V_11 ) ) ;
if ( V_36 )
;
else if ( V_190 )
F_9 ( V_3 , V_190 , V_109 -> V_8 . V_11 ,
sizeof( V_109 -> V_8 . V_11 ) ) ;
else {
V_36 = F_41 ( V_3 , & V_3 -> V_201 ,
V_109 -> V_8 . V_11 , sizeof( V_109 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
F_3 ( V_109 -> V_8 . V_11 , L_61 , sizeof( V_109 -> V_8 . V_11 ) ) ;
if ( V_186 -> V_31 == V_139 )
F_63 ( V_109 , L_62 ) ;
else if ( ( V_3 -> V_201 . type & 0xff00 ) == 0x0100 )
F_63 ( V_109 , L_63 ) ;
else
F_63 ( V_109 , L_64 ) ;
}
F_22 ( V_3 -> V_37 , L_65 ,
V_14 -> V_54 . V_8 , V_109 -> V_8 . V_11 , V_186 -> V_146 ) ;
return F_38 ( & V_14 -> V_54 , V_109 ) ;
}
static int F_78 ( struct V_2 * V_3 , int V_4 )
{
unsigned char * V_124 ;
if ( F_102 ( V_4 , V_3 -> V_251 ) )
return 0 ;
V_124 = F_7 ( V_3 , V_4 ) ;
if ( ! V_124 ) {
F_25 ( V_3 -> V_37 , L_66 , V_4 ) ;
return - V_66 ;
}
switch ( V_124 [ 2 ] ) {
case V_32 :
return 0 ;
case V_121 :
return F_84 ( V_3 , V_4 , V_124 ) ;
case V_147 :
return F_73 ( V_3 , V_4 , V_124 ) ;
case V_118 :
case V_139 :
return F_99 ( V_3 , V_4 , V_124 ) ;
case V_136 :
return F_77 ( V_3 , V_4 , V_124 ) ;
case V_119 :
if ( V_3 -> V_55 -> V_79 == V_80 )
return F_91 ( V_3 , V_4 , V_124 ) ;
else
return 0 ;
case V_120 :
if ( V_3 -> V_55 -> V_79 == V_80 )
return F_92 ( V_3 , V_4 , V_124 ) ;
else
return F_91 ( V_3 , V_4 , V_124 ) ;
case V_142 :
return F_92 ( V_3 , V_4 , V_124 ) ;
default:
F_25 ( V_3 -> V_37 ,
L_67 , V_4 , V_124 [ 2 ] ) ;
return - V_66 ;
}
}
static void F_103 ( struct V_110 * V_55 )
{
F_104 ( V_55 ) ;
F_53 ( V_55 -> V_113 ) ;
if ( V_55 -> V_252 ) {
F_53 ( V_55 -> V_252 -> V_253 ) ;
F_105 ( V_55 -> V_252 ) ;
}
F_105 ( V_55 -> V_254 ) ;
F_53 ( V_55 -> V_255 ) ;
F_53 ( V_55 ) ;
}
static int F_106 ( struct V_256 * V_257 )
{
struct V_110 * V_55 = V_257 -> V_258 ;
F_103 ( V_55 ) ;
return 0 ;
}
static int F_107 ( struct V_110 * V_55 )
{
struct V_2 V_3 ;
int V_59 ;
const struct V_259 * V_7 ;
void * V_6 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_37 = V_55 -> V_37 ;
V_3 . V_55 = V_55 ;
V_3 . V_28 = V_55 -> V_260 -> V_261 ;
V_3 . V_10 = V_55 -> V_260 -> V_262 ;
for ( V_7 = V_263 ; V_7 -> V_8 ; V_7 ++ ) {
if ( V_7 -> V_8 == V_3 . V_37 -> V_151 ) {
V_3 . V_7 = V_7 -> V_7 ;
V_3 . V_22 = V_7 -> V_22 ;
V_55 -> V_85 = V_7 -> V_85 ;
break;
}
}
V_6 = NULL ;
while ( ( V_6 = F_108 ( V_55 -> V_260 -> V_261 ,
V_55 -> V_260 -> V_262 ,
V_6 , V_264 ) ) != NULL ) {
if ( V_55 -> V_79 == V_80 ) {
struct V_265 * V_186 = V_6 ;
if ( V_186 -> V_30 < sizeof( * V_186 ) )
continue;
F_109 ( V_186 -> V_266 , V_3 . V_251 ) ;
V_3 . V_201 . V_8 = V_186 -> V_266 ;
V_3 . V_201 . type = F_43 ( V_186 -> V_127 ) ;
V_3 . V_201 . V_11 = V_186 -> V_132 ;
V_59 = F_78 ( & V_3 , V_186 -> V_137 ) ;
if ( V_59 < 0 && V_59 != - V_66 )
return V_59 ;
} else {
struct V_267 * V_186 = V_6 ;
if ( V_186 -> V_30 < sizeof( * V_186 ) )
continue;
F_109 ( V_186 -> V_266 , V_3 . V_251 ) ;
V_3 . V_201 . V_8 = V_186 -> V_266 ;
V_3 . V_201 . type = F_43 ( V_186 -> V_127 ) ;
V_3 . V_201 . V_11 = V_186 -> V_132 ;
V_59 = F_78 ( & V_3 , V_186 -> V_137 ) ;
if ( V_59 < 0 && V_59 != - V_66 )
return V_59 ;
V_59 = F_78 ( & V_3 , V_186 -> V_134 ) ;
if ( V_59 < 0 && V_59 != - V_66 )
return V_59 ;
}
}
return 0 ;
}
void F_110 ( struct V_110 * V_55 , int V_4 )
{
struct V_107 * V_108 ;
for ( V_108 = V_55 -> V_113 [ V_4 ] ; V_108 ; V_108 = V_108 -> V_112 )
F_59 ( V_55 -> V_37 -> V_111 , V_268 ,
& V_108 -> V_109 -> V_8 ) ;
}
static void F_111 ( struct V_269 * V_28 ,
struct V_107 * V_108 )
{
struct V_13 * V_14 = (struct V_13 * ) V_108 ;
static char * V_270 [] = { L_68 , L_69 ,
L_70 , L_71 , L_72 , L_73 } ;
F_112 ( V_28 , L_74
L_75 , V_14 -> V_54 . V_8 ,
V_14 -> V_5 , V_14 -> V_154 , V_14 -> V_128 ,
V_270 [ V_14 -> V_40 ] ) ;
F_112 ( V_28 , L_76 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_15 , V_14 -> V_17 ) ;
}
static void F_113 ( struct V_271 * V_272 ,
struct V_269 * V_28 )
{
struct V_53 * V_37 = V_272 -> V_97 ;
struct V_110 * V_55 ;
struct V_107 * V_108 ;
int V_4 ;
F_114 (mixer, &chip->mixer_list, list) {
F_112 ( V_28 ,
L_77 ,
V_37 -> V_151 , F_18 ( V_37 ) ,
V_55 -> V_85 ) ;
F_112 ( V_28 , L_78 , V_37 -> V_111 -> V_273 ) ;
for ( V_4 = 0 ; V_4 < V_274 ; V_4 ++ ) {
for ( V_108 = V_55 -> V_113 [ V_4 ] ; V_108 ;
V_108 = V_108 -> V_112 ) {
F_112 ( V_28 , L_79 , V_108 -> V_8 ) ;
if ( V_108 -> V_109 )
F_112 ( V_28 ,
L_80 ,
V_108 -> V_109 -> V_8 . V_11 ,
V_108 -> V_109 -> V_8 . V_20 ) ;
if ( V_108 -> V_275 )
V_108 -> V_275 ( V_28 , V_108 ) ;
}
}
}
}
static void F_115 ( struct V_110 * V_55 ,
int V_276 , int V_81 , int V_20 )
{
struct V_107 * V_108 ;
T_1 V_4 = ( V_20 >> 8 ) & 0xff ;
T_1 V_5 = ( V_81 >> 8 ) & 0xff ;
T_1 V_82 = V_81 & 0xff ;
unsigned int V_23 = 0 ;
if ( V_82 >= V_156 ) {
F_22 ( V_55 -> V_37 ,
L_81 ,
V_92 , V_82 ) ;
return;
}
for ( V_108 = V_55 -> V_113 [ V_4 ] ; V_108 ; V_108 = V_108 -> V_112 )
V_23 ++ ;
if ( V_23 == 0 )
return;
for ( V_108 = V_55 -> V_113 [ V_4 ] ; V_108 ; V_108 = V_108 -> V_112 ) {
struct V_13 * V_226 ;
if ( ! V_108 -> V_109 )
continue;
V_226 = (struct V_13 * ) V_108 ;
if ( V_23 > 1 && V_226 -> V_5 != V_5 )
continue;
switch ( V_276 ) {
case V_72 :
if ( V_82 )
V_226 -> V_83 &= ~ ( 1 << V_82 ) ;
else
V_226 -> V_83 = 0 ;
F_59 ( V_55 -> V_37 -> V_111 , V_268 ,
& V_226 -> V_54 . V_109 -> V_8 ) ;
break;
case V_73 :
break;
case V_277 :
break;
default:
F_22 ( V_55 -> V_37 ,
L_82 ,
V_276 ) ;
break;
}
}
}
static void F_116 ( struct V_252 * V_252 )
{
struct V_110 * V_55 = V_252 -> V_278 ;
int V_36 = V_252 -> V_279 ;
int V_280 = V_252 -> V_281 ;
if ( V_280 != 0 )
goto V_282;
if ( V_55 -> V_79 == V_80 ) {
struct V_283 * V_281 ;
for ( V_281 = V_252 -> V_253 ;
V_36 >= sizeof( * V_281 ) ;
V_36 -= sizeof( * V_281 ) , V_281 ++ ) {
F_117 ( & V_252 -> V_38 -> V_38 , L_83 ,
V_281 -> V_284 ,
V_281 -> V_285 ) ;
if ( ( V_281 -> V_284 & V_286 ) !=
V_287 )
continue;
if ( V_281 -> V_284 & V_288 )
F_118 ( V_55 , V_281 -> V_285 ) ;
else
F_110 ( V_55 , V_281 -> V_285 ) ;
}
} else {
struct V_289 * V_290 ;
for ( V_290 = V_252 -> V_253 ;
V_36 >= sizeof( * V_290 ) ;
V_36 -= sizeof( * V_290 ) , V_290 ++ ) {
if ( ( V_290 -> V_291 & V_292 ) ||
( V_290 -> V_291 & V_293 ) )
continue;
F_115 ( V_55 , V_290 -> V_294 ,
F_43 ( V_290 -> V_295 ) ,
F_43 ( V_290 -> V_296 ) ) ;
}
}
V_282:
if ( V_280 != - V_297 &&
V_280 != - V_298 &&
V_280 != - V_299 ) {
V_252 -> V_38 = V_55 -> V_37 -> V_38 ;
F_119 ( V_252 , V_300 ) ;
}
}
static int F_120 ( struct V_110 * V_55 )
{
struct V_301 * V_302 ;
void * V_253 ;
int V_303 ;
unsigned int V_304 ;
if ( F_121 ( V_55 -> V_260 ) -> V_305 < 1 )
return 0 ;
V_302 = F_122 ( V_55 -> V_260 , 0 ) ;
if ( ! F_123 ( V_302 ) || ! F_124 ( V_302 ) )
return 0 ;
V_304 = F_125 ( V_302 ) ;
V_303 = F_43 ( V_302 -> V_306 ) ;
V_253 = F_100 ( V_303 , V_193 ) ;
if ( ! V_253 )
return - V_99 ;
V_55 -> V_252 = F_126 ( 0 , V_193 ) ;
if ( ! V_55 -> V_252 ) {
F_53 ( V_253 ) ;
return - V_99 ;
}
F_127 ( V_55 -> V_252 , V_55 -> V_37 -> V_38 ,
F_128 ( V_55 -> V_37 -> V_38 , V_304 ) ,
V_253 , V_303 ,
F_116 , V_55 , V_302 -> V_307 ) ;
F_119 ( V_55 -> V_252 , V_193 ) ;
return 0 ;
}
int F_129 ( struct V_53 * V_37 , int V_308 ,
int V_309 )
{
static struct V_310 V_311 = {
. V_312 = F_106
} ;
struct V_110 * V_55 ;
struct V_271 * V_272 ;
int V_59 ;
strcpy ( V_37 -> V_111 -> V_313 , L_84 ) ;
V_55 = F_68 ( sizeof( * V_55 ) , V_193 ) ;
if ( ! V_55 )
return - V_99 ;
V_55 -> V_37 = V_37 ;
V_55 -> V_85 = V_309 ;
V_55 -> V_113 = F_130 ( V_274 , sizeof( * V_55 -> V_113 ) ,
V_193 ) ;
if ( ! V_55 -> V_113 ) {
F_53 ( V_55 ) ;
return - V_99 ;
}
V_55 -> V_260 = & F_131 ( V_37 -> V_38 , V_308 ) -> V_314 [ 0 ] ;
switch ( F_121 ( V_55 -> V_260 ) -> V_315 ) {
case V_80 :
default:
V_55 -> V_79 = V_80 ;
break;
case V_144 :
V_55 -> V_79 = V_144 ;
break;
}
if ( ( V_59 = F_107 ( V_55 ) ) < 0 ||
( V_59 = F_120 ( V_55 ) ) < 0 )
goto V_316;
F_132 ( V_55 ) ;
V_59 = F_133 ( V_37 -> V_111 , V_317 , V_55 , & V_311 ) ;
if ( V_59 < 0 )
goto V_316;
if ( F_134 ( & V_37 -> V_318 ) &&
! F_135 ( V_37 -> V_111 , L_85 , & V_272 ) )
F_136 ( V_272 , V_37 , F_113 ) ;
F_137 ( & V_55 -> V_108 , & V_37 -> V_318 ) ;
return 0 ;
V_316:
F_103 ( V_55 ) ;
return V_59 ;
}
void F_104 ( struct V_110 * V_55 )
{
if ( V_55 -> V_319 )
return;
if ( V_55 -> V_252 )
F_138 ( V_55 -> V_252 ) ;
if ( V_55 -> V_254 )
F_138 ( V_55 -> V_254 ) ;
V_55 -> V_319 = true ;
}
static void F_139 ( struct V_110 * V_55 )
{
F_138 ( V_55 -> V_252 ) ;
F_138 ( V_55 -> V_254 ) ;
}
static int F_140 ( struct V_110 * V_55 )
{
int V_59 ;
if ( V_55 -> V_252 ) {
V_59 = F_119 ( V_55 -> V_252 , V_320 ) ;
if ( V_59 < 0 )
return V_59 ;
}
return 0 ;
}
int F_141 ( struct V_110 * V_55 )
{
F_139 ( V_55 ) ;
return 0 ;
}
static int F_142 ( struct V_107 * V_108 )
{
struct V_13 * V_14 = (struct V_13 * ) V_108 ;
int V_173 , V_59 , V_58 ;
if ( V_14 -> V_154 ) {
V_58 = 0 ;
for ( V_173 = 0 ; V_173 < V_156 ; V_173 ++ ) {
if ( ! ( V_14 -> V_154 & ( 1 << V_173 ) ) )
continue;
if ( V_14 -> V_83 & ( 1 << ( V_173 + 1 ) ) ) {
V_59 = F_33 ( V_14 , V_173 + 1 , V_58 ,
V_14 -> V_84 [ V_58 ] ) ;
if ( V_59 < 0 )
return V_59 ;
}
V_58 ++ ;
}
} else {
if ( V_14 -> V_83 ) {
V_59 = F_33 ( V_14 , 0 , 0 , * V_14 -> V_84 ) ;
if ( V_59 < 0 )
return V_59 ;
}
}
return 0 ;
}
int F_143 ( struct V_110 * V_55 , bool V_321 )
{
struct V_107 * V_108 ;
int V_8 , V_59 ;
if ( V_321 ) {
for ( V_8 = 0 ; V_8 < V_274 ; V_8 ++ ) {
for ( V_108 = V_55 -> V_113 [ V_8 ] ; V_108 ;
V_108 = V_108 -> V_112 ) {
if ( V_108 -> V_322 ) {
V_59 = V_108 -> V_322 ( V_108 ) ;
if ( V_59 < 0 )
return V_59 ;
}
}
}
}
return F_140 ( V_55 ) ;
}
void F_69 ( struct V_107 * V_108 ,
struct V_110 * V_55 ,
int V_4 )
{
V_108 -> V_55 = V_55 ;
V_108 -> V_8 = V_4 ;
V_108 -> V_275 = F_111 ;
#ifdef F_144
V_108 -> V_322 = F_142 ;
#endif
}
