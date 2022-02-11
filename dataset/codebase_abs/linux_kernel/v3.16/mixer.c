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
static int F_15 ( struct V_13 * V_14 , int V_48 ,
int V_49 , int * V_50 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
unsigned char V_9 [ 2 ] ;
int V_53 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
int V_54 = 10 ;
int V_55 = 0 , V_56 ;
V_56 = F_16 ( V_14 -> V_52 -> V_37 ) ;
if ( V_56 < 0 )
return - V_57 ;
F_17 ( & V_37 -> V_58 ) ;
while ( V_54 -- > 0 ) {
if ( V_37 -> V_59 )
break;
V_55 = F_18 ( V_37 ) | ( V_14 -> V_8 << 8 ) ;
if ( F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_48 ,
V_60 | V_61 | V_62 ,
V_49 , V_55 , V_9 , V_53 ) >= V_53 ) {
* V_50 = F_11 ( V_14 , F_21 ( V_9 , V_53 ) ) ;
V_56 = 0 ;
goto V_63;
}
}
F_22 ( V_37 ,
L_1 ,
V_48 , V_49 , V_55 , V_14 -> V_40 ) ;
V_56 = - V_64 ;
V_63:
F_23 ( & V_37 -> V_58 ) ;
F_24 ( V_14 -> V_52 -> V_37 ) ;
return V_56 ;
}
static int F_25 ( struct V_13 * V_14 , int V_48 ,
int V_49 , int * V_50 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
unsigned char V_9 [ 2 + 3 * sizeof( V_65 ) ] ;
unsigned char * V_39 ;
int V_55 = 0 , V_66 , V_67 ;
T_1 V_68 ;
if ( V_48 == V_69 ) {
V_68 = V_70 ;
V_67 = sizeof( V_65 ) ;
} else {
V_68 = V_71 ;
V_67 = sizeof( V_9 ) ;
}
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_66 = F_16 ( V_37 ) ? - V_57 : 0 ;
if ( V_66 )
goto error;
F_17 ( & V_37 -> V_58 ) ;
if ( V_37 -> V_59 ) {
V_66 = - V_72 ;
} else {
V_55 = F_18 ( V_37 ) | ( V_14 -> V_8 << 8 ) ;
V_66 = F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_68 ,
V_60 | V_61 | V_62 ,
V_49 , V_55 , V_9 , V_67 ) ;
}
F_23 ( & V_37 -> V_58 ) ;
F_24 ( V_37 ) ;
if ( V_66 < 0 ) {
error:
F_26 ( V_37 ,
L_1 ,
V_48 , V_49 , V_55 , V_14 -> V_40 ) ;
return V_66 ;
}
switch ( V_48 ) {
case V_69 :
V_39 = V_9 ;
break;
case V_73 :
V_39 = V_9 + sizeof( V_65 ) ;
break;
case V_74 :
V_39 = V_9 + sizeof( V_65 ) * 2 ;
break;
case V_75 :
V_39 = V_9 + sizeof( V_65 ) * 3 ;
break;
default:
return - V_64 ;
}
* V_50 = F_11 ( V_14 , F_21 ( V_39 , sizeof( V_65 ) ) ) ;
return 0 ;
}
static int F_27 ( struct V_13 * V_14 , int V_48 ,
int V_49 , int * V_50 )
{
V_49 += V_14 -> V_76 ;
return ( V_14 -> V_52 -> V_77 == V_78 ) ?
F_15 ( V_14 , V_48 , V_49 , V_50 ) :
F_25 ( V_14 , V_48 , V_49 , V_50 ) ;
}
static int F_28 ( struct V_13 * V_14 ,
int V_49 , int * V_79 )
{
return F_27 ( V_14 , V_69 , V_49 , V_79 ) ;
}
static inline int F_29 ( struct V_13 * V_14 ,
int V_80 , int * V_79 )
{
return F_27 ( V_14 , V_69 ,
( V_14 -> V_5 << 8 ) | V_80 ,
V_79 ) ;
}
static int F_30 ( struct V_13 * V_14 ,
int V_80 , int V_20 , int * V_79 )
{
int V_56 ;
if ( V_14 -> V_81 & ( 1 << V_80 ) ) {
* V_79 = V_14 -> V_82 [ V_20 ] ;
return 0 ;
}
V_56 = F_29 ( V_14 , V_80 , V_79 ) ;
if ( V_56 < 0 ) {
if ( ! V_14 -> V_52 -> V_83 )
F_22 ( V_14 -> V_52 -> V_37 ,
L_2 ,
V_14 -> V_5 , V_80 , V_56 ) ;
return V_56 ;
}
V_14 -> V_81 |= 1 << V_80 ;
V_14 -> V_82 [ V_20 ] = * V_79 ;
return 0 ;
}
int F_31 ( struct V_13 * V_14 ,
int V_48 , int V_49 , int V_84 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
unsigned char V_9 [ 2 ] ;
int V_55 = 0 , V_53 , V_56 , V_54 = 10 ;
V_49 += V_14 -> V_76 ;
if ( V_14 -> V_52 -> V_77 == V_78 ) {
V_53 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
} else {
V_53 = sizeof( V_65 ) ;
if ( V_48 != V_85 ) {
F_22 ( V_37 , L_3 ) ;
return - V_64 ;
}
V_48 = V_70 ;
}
V_84 = F_12 ( V_14 , V_84 ) ;
V_9 [ 0 ] = V_84 & 0xff ;
V_9 [ 1 ] = ( V_84 >> 8 ) & 0xff ;
V_56 = F_16 ( V_37 ) ;
if ( V_56 < 0 )
return - V_57 ;
F_17 ( & V_37 -> V_58 ) ;
while ( V_54 -- > 0 ) {
if ( V_37 -> V_59 )
break;
V_55 = F_18 ( V_37 ) | ( V_14 -> V_8 << 8 ) ;
if ( F_19 ( V_37 -> V_38 ,
F_32 ( V_37 -> V_38 , 0 ) , V_48 ,
V_60 | V_61 | V_86 ,
V_49 , V_55 , V_9 , V_53 ) >= 0 ) {
V_56 = 0 ;
goto V_63;
}
}
F_22 ( V_37 , L_4 ,
V_48 , V_49 , V_55 , V_14 -> V_40 , V_9 [ 0 ] , V_9 [ 1 ] ) ;
V_56 = - V_64 ;
V_63:
F_23 ( & V_37 -> V_58 ) ;
F_24 ( V_37 ) ;
return V_56 ;
}
static int F_33 ( struct V_13 * V_14 ,
int V_49 , int V_79 )
{
return F_31 ( V_14 , V_85 , V_49 , V_79 ) ;
}
static int F_34 ( struct V_13 * V_14 , int V_80 ,
int V_20 , int V_79 )
{
int V_56 ;
unsigned int V_87 = ( V_80 == 0 ) ?
V_14 -> V_88 :
V_14 -> V_89 & ( 1 << ( V_80 - 1 ) ) ;
if ( V_87 ) {
F_22 ( V_14 -> V_52 -> V_37 ,
L_5 ,
V_90 , V_80 , V_14 -> V_5 ) ;
return 0 ;
}
V_56 = F_31 ( V_14 ,
V_85 , ( V_14 -> V_5 << 8 ) | V_80 ,
V_79 ) ;
if ( V_56 < 0 )
return V_56 ;
V_14 -> V_81 |= 1 << V_80 ;
V_14 -> V_82 [ V_20 ] = V_79 ;
return 0 ;
}
int F_35 ( struct V_91 * V_92 , int V_93 ,
unsigned int V_67 , unsigned int T_2 * V_94 )
{
struct V_13 * V_14 = V_92 -> V_95 ;
F_36 ( V_96 , 0 , 0 ) ;
if ( V_67 < sizeof( V_96 ) )
return - V_97 ;
V_96 [ 2 ] = V_14 -> V_15 ;
V_96 [ 3 ] = V_14 -> V_17 ;
if ( F_37 ( V_94 , V_96 , sizeof( V_96 ) ) )
return - V_98 ;
return 0 ;
}
static int F_38 ( unsigned char * V_99 ,
int V_100 , int V_101 , int V_102 )
{
int V_55 = V_100 * V_102 + V_101 ;
return V_99 [ V_55 >> 3 ] & ( 0x80 >> ( V_55 & 7 ) ) ;
}
int F_39 ( struct V_103 * V_52 ,
struct V_91 * V_104 )
{
struct V_13 * V_14 = V_104 -> V_95 ;
int V_56 ;
while ( F_40 ( V_52 -> V_37 -> V_105 , & V_104 -> V_8 ) )
V_104 -> V_8 . V_20 ++ ;
if ( ( V_56 = F_41 ( V_52 -> V_37 -> V_105 , V_104 ) ) < 0 ) {
F_22 ( V_52 -> V_37 , L_6 ,
V_56 ) ;
return V_56 ;
}
V_14 -> V_106 = & V_104 -> V_8 ;
V_14 -> V_107 = V_52 -> V_108 [ V_14 -> V_8 ] ;
V_52 -> V_108 [ V_14 -> V_8 ] = V_14 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_109 * V_110 ,
unsigned char * V_11 , int V_35 , int V_111 )
{
struct V_112 * V_24 ;
if ( V_110 -> V_11 )
return F_9 ( V_3 , V_110 -> V_11 ,
V_11 , V_35 ) ;
if ( V_110 -> type >> 16 ) {
if ( V_111 )
return 0 ;
switch ( V_110 -> type >> 16 ) {
case V_113 :
strcpy ( V_11 , L_7 ) ;
return 8 ;
case V_114 :
strcpy ( V_11 , L_8 ) ;
return 12 ;
case V_115 :
strcpy ( V_11 , L_9 ) ;
return 8 ;
case V_116 :
strcpy ( V_11 , L_10 ) ;
return 5 ;
default:
return sprintf ( V_11 , L_11 , V_110 -> V_8 ) ;
}
}
switch ( V_110 -> type & 0xff00 ) {
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
for ( V_24 = V_117 ; V_24 -> type ; V_24 ++ ) {
if ( V_24 -> type == V_110 -> type ) {
strcpy ( V_11 , V_24 -> V_11 ) ;
return strlen ( V_24 -> V_11 ) ;
}
}
return 0 ;
}
static int F_43 ( struct V_2 * V_3 , int V_8 ,
struct V_109 * V_118 )
{
int V_56 ;
void * V_119 ;
memset ( V_118 , 0 , sizeof( * V_118 ) ) ;
while ( ( V_119 = F_7 ( V_3 , V_8 ) ) != NULL ) {
unsigned char * V_27 = V_119 ;
V_118 -> V_8 = V_8 ;
switch ( V_27 [ 2 ] ) {
case V_32 :
if ( V_3 -> V_52 -> V_77 == V_78 ) {
struct V_120 * V_121 = V_119 ;
V_118 -> type = F_44 ( V_121 -> V_122 ) ;
V_118 -> V_123 = V_121 -> V_124 ;
V_118 -> V_125 = F_44 ( V_121 -> V_126 ) ;
V_118 -> V_11 = V_121 -> V_127 ;
} else {
struct V_128 * V_121 = V_119 ;
V_118 -> type = F_44 ( V_121 -> V_122 ) ;
V_118 -> V_123 = V_121 -> V_124 ;
V_118 -> V_125 = F_45 ( V_121 -> V_129 ) ;
V_118 -> V_11 = V_121 -> V_127 ;
V_56 = F_43 ( V_3 , V_121 -> V_130 , V_118 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
case V_131 : {
struct V_26 * V_121 = V_119 ;
V_8 = V_121 -> V_132 ;
break;
}
case V_116 : {
struct V_133 * V_121 = V_119 ;
V_118 -> type = V_121 -> V_31 << 16 ;
V_118 -> V_123 = F_46 ( V_121 ) ;
V_118 -> V_125 = F_47 ( V_121 , V_3 -> V_52 -> V_77 ) ;
V_118 -> V_11 = F_48 ( V_121 ) ;
return 0 ;
}
case V_113 :
case V_134 : {
struct V_135 * V_121 = V_119 ;
V_56 = F_43 ( V_3 , V_121 -> V_136 [ 0 ] , V_118 ) ;
if ( V_56 < 0 )
return V_56 ;
V_118 -> type = V_121 -> V_31 << 16 ;
V_118 -> V_8 = V_8 ;
V_118 -> V_11 = F_49 ( V_121 ) ;
return 0 ;
}
case V_114 :
case V_115 :
case V_137 : {
struct V_138 * V_121 = V_119 ;
if ( V_3 -> V_52 -> V_77 == V_139 &&
V_27 [ 2 ] == V_140 ) {
return 0 ;
}
if ( V_121 -> V_141 ) {
V_8 = V_121 -> V_136 [ 0 ] ;
break;
}
V_118 -> type = V_121 -> V_31 << 16 ;
V_118 -> V_123 = F_50 ( V_121 ) ;
V_118 -> V_125 = F_51 ( V_121 , V_3 -> V_52 -> V_77 ) ;
V_118 -> V_11 = F_52 ( V_121 , V_3 -> V_52 -> V_77 ) ;
return 0 ;
}
case V_142 : {
struct V_143 * V_121 = V_119 ;
V_118 -> type = V_121 -> V_31 << 16 ;
V_118 -> V_8 = V_8 ;
V_118 -> V_11 = V_121 -> V_144 ;
return 0 ;
}
default:
return - V_72 ;
}
}
return - V_72 ;
}
static void F_53 ( struct V_91 * V_104 )
{
F_54 ( V_104 -> V_95 ) ;
V_104 -> V_95 = NULL ;
}
static void F_55 ( struct V_13 * V_14 ,
struct V_91 * V_104 )
{
struct V_51 * V_37 = V_14 -> V_52 -> V_37 ;
switch ( V_37 -> V_145 ) {
case F_56 ( 0x0763 , 0x2030 ) :
case F_56 ( 0x0763 , 0x2031 ) :
if ( strcmp ( V_104 -> V_8 . V_11 , L_16 ) == 0 ) {
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0xffff ;
V_14 -> V_47 = 0x00e6 ;
break;
}
if ( strcmp ( V_104 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_104 -> V_8 . V_11 , L_18 ) == 0 ) {
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0xff ;
break;
}
if ( strstr ( V_104 -> V_8 . V_11 , L_19 ) != NULL ) {
V_14 -> V_16 = 0xb706 ;
V_14 -> V_18 = 0xff7b ;
V_14 -> V_47 = 0x0073 ;
break;
}
if ( ( strstr ( V_104 -> V_8 . V_11 , L_20 ) != NULL ) ||
( strstr ( V_104 -> V_8 . V_11 , L_21 ) != NULL ) ) {
V_14 -> V_16 = 0xb5fb ;
V_14 -> V_18 = 0xfcfe ;
V_14 -> V_47 = 0x0073 ;
}
break;
case F_56 ( 0x0763 , 0x2081 ) :
case F_56 ( 0x0763 , 0x2080 ) :
if ( strcmp ( V_104 -> V_8 . V_11 , L_16 ) == 0 ) {
F_57 ( V_37 ,
L_22 ) ;
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0x7f00 ;
V_14 -> V_47 = 0x0100 ;
break;
}
if ( strcmp ( V_104 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_104 -> V_8 . V_11 , L_18 ) == 0 ) {
F_57 ( V_37 ,
L_23 ) ;
V_14 -> V_16 = 0x00 ;
V_14 -> V_18 = 0x7f ;
break;
}
break;
case F_56 ( 0x0471 , 0x0101 ) :
case F_56 ( 0x0471 , 0x0104 ) :
case F_56 ( 0x0471 , 0x0105 ) :
case F_56 ( 0x0672 , 0x1041 ) :
if ( ! strcmp ( V_104 -> V_8 . V_11 , L_24 ) &&
V_14 -> V_16 == - 15616 ) {
F_57 ( V_37 ,
L_25 ) ;
V_14 -> V_18 = - 256 ;
}
break;
case F_56 ( 0x046d , 0x09a4 ) :
if ( ! strcmp ( V_104 -> V_8 . V_11 , L_26 ) ) {
F_57 ( V_37 ,
L_27 ) ;
V_14 -> V_16 = 6080 ;
V_14 -> V_18 = 8768 ;
V_14 -> V_47 = 192 ;
}
break;
case F_56 ( 0x046d , 0x0807 ) :
case F_56 ( 0x046d , 0x0808 ) :
case F_56 ( 0x046d , 0x0809 ) :
case F_56 ( 0x046d , 0x081b ) :
case F_56 ( 0x046d , 0x081d ) :
case F_56 ( 0x046d , 0x0825 ) :
case F_56 ( 0x046d , 0x0826 ) :
case F_56 ( 0x046d , 0x0991 ) :
if ( ! strcmp ( V_104 -> V_8 . V_11 , L_26 ) ) {
F_57 ( V_37 ,
L_28 ) ;
V_14 -> V_47 = 384 ;
}
break;
}
}
static int F_58 ( struct V_13 * V_14 ,
int V_146 , struct V_91 * V_104 )
{
V_14 -> V_16 = V_146 ;
V_14 -> V_18 = V_14 -> V_16 + 1 ;
V_14 -> V_47 = 1 ;
V_14 -> V_15 = V_14 -> V_17 = 0 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_14 -> V_19 = 1 ;
} else {
int V_147 = 0 ;
if ( V_14 -> V_148 ) {
int V_149 ;
for ( V_149 = 0 ; V_149 < V_150 ; V_149 ++ )
if ( V_14 -> V_148 & ( 1 << V_149 ) ) {
V_147 = V_149 + 1 ;
break;
}
}
if ( F_27 ( V_14 , V_74 , ( V_14 -> V_5 << 8 ) | V_147 , & V_14 -> V_18 ) < 0 ||
F_27 ( V_14 , V_73 , ( V_14 -> V_5 << 8 ) | V_147 , & V_14 -> V_16 ) < 0 ) {
F_26 ( V_14 -> V_52 -> V_37 ,
L_29 ,
V_14 -> V_8 , F_18 ( V_14 -> V_52 -> V_37 ) ,
V_14 -> V_5 , V_14 -> V_8 ) ;
return - V_64 ;
}
if ( F_27 ( V_14 , V_75 ,
( V_14 -> V_5 << 8 ) | V_147 ,
& V_14 -> V_47 ) < 0 ) {
V_14 -> V_47 = 1 ;
} else {
int V_151 = V_14 -> V_47 ;
while ( V_14 -> V_47 > 1 ) {
if ( F_31 ( V_14 , V_152 ,
( V_14 -> V_5 << 8 ) | V_147 ,
V_14 -> V_47 / 2 ) < 0 )
break;
V_14 -> V_47 /= 2 ;
}
if ( F_27 ( V_14 , V_75 ,
( V_14 -> V_5 << 8 ) | V_147 , & V_14 -> V_47 ) < 0 )
V_14 -> V_47 = V_151 ;
}
if ( V_14 -> V_47 == 0 )
V_14 -> V_47 = 1 ;
if ( V_14 -> V_16 + V_14 -> V_47 < V_14 -> V_18 ) {
int V_151 = V_14 -> V_47 ;
int V_153 , V_154 , V_155 ;
F_29 ( V_14 , V_147 , & V_153 ) ;
for (; ; ) {
V_154 = V_153 ;
if ( V_154 < V_14 -> V_18 )
V_154 += V_14 -> V_47 ;
else
V_154 -= V_14 -> V_47 ;
if ( V_154 < V_14 -> V_16 || V_154 > V_14 -> V_18 ||
F_34 ( V_14 , V_147 , 0 , V_154 ) ||
F_29 ( V_14 , V_147 , & V_155 ) ) {
V_14 -> V_47 = V_151 ;
break;
}
if ( V_154 == V_155 )
break;
V_14 -> V_47 *= 2 ;
}
F_34 ( V_14 , V_147 , 0 , V_153 ) ;
}
V_14 -> V_19 = 1 ;
}
if ( V_104 )
F_55 ( V_14 , V_104 ) ;
V_14 -> V_15 = ( F_11 ( V_14 , V_14 -> V_16 ) * 100 ) / 256 ;
V_14 -> V_17 = ( F_11 ( V_14 , V_14 -> V_18 ) * 100 ) / 256 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
if ( V_14 -> V_15 < 0 )
V_14 -> V_17 = 0 ;
else if ( V_14 -> V_15 > 0 )
V_14 -> V_15 = 0 ;
if ( V_14 -> V_15 > V_14 -> V_17 ) {
return - V_64 ;
}
}
return 0 ;
}
static int F_59 ( struct V_91 * V_92 ,
struct V_156 * V_157 )
{
struct V_13 * V_14 = V_92 -> V_95 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 )
V_157 -> type = V_158 ;
else
V_157 -> type = V_159 ;
V_157 -> V_23 = V_14 -> V_123 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_157 -> V_79 . integer . V_16 = 0 ;
V_157 -> V_79 . integer . V_18 = 1 ;
} else {
if ( ! V_14 -> V_19 ) {
F_58 ( V_14 , 0 , V_92 ) ;
if ( V_14 -> V_19 && V_14 -> V_15 >= V_14 -> V_17 ) {
V_92 -> V_160 [ 0 ] . V_161 &=
~ ( V_162 |
V_163 ) ;
F_60 ( V_14 -> V_52 -> V_37 -> V_105 ,
V_164 ,
& V_92 -> V_8 ) ;
}
}
V_157 -> V_79 . integer . V_16 = 0 ;
V_157 -> V_79 . integer . V_18 =
( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
}
return 0 ;
}
static int F_61 ( struct V_91 * V_92 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = V_92 -> V_95 ;
int V_167 , V_168 , V_39 , V_56 ;
V_166 -> V_79 . integer . V_79 [ 0 ] = V_14 -> V_16 ;
if ( V_14 -> V_148 ) {
V_168 = 0 ;
for ( V_167 = 0 ; V_167 < V_150 ; V_167 ++ ) {
if ( ! ( V_14 -> V_148 & ( 1 << V_167 ) ) )
continue;
V_56 = F_30 ( V_14 , V_167 + 1 , V_168 , & V_39 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_83 ? 0 : V_56 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_166 -> V_79 . integer . V_79 [ V_168 ] = V_39 ;
V_168 ++ ;
}
return 0 ;
} else {
V_56 = F_30 ( V_14 , 0 , 0 , & V_39 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_83 ? 0 : V_56 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_166 -> V_79 . integer . V_79 [ 0 ] = V_39 ;
}
return 0 ;
}
static int F_62 ( struct V_91 * V_92 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = V_92 -> V_95 ;
int V_167 , V_168 , V_39 , V_169 , V_56 ;
int V_170 = 0 ;
if ( V_14 -> V_148 ) {
V_168 = 0 ;
for ( V_167 = 0 ; V_167 < V_150 ; V_167 ++ ) {
if ( ! ( V_14 -> V_148 & ( 1 << V_167 ) ) )
continue;
V_56 = F_30 ( V_14 , V_167 + 1 , V_168 , & V_169 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_83 ? 0 : V_56 ;
V_39 = V_166 -> V_79 . integer . V_79 [ V_168 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_169 != V_39 ) {
F_34 ( V_14 , V_167 + 1 , V_168 , V_39 ) ;
V_170 = 1 ;
}
V_168 ++ ;
}
} else {
V_56 = F_30 ( V_14 , 0 , 0 , & V_169 ) ;
if ( V_56 < 0 )
return V_14 -> V_52 -> V_83 ? 0 : V_56 ;
V_39 = V_166 -> V_79 . integer . V_79 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_169 ) {
F_34 ( V_14 , 0 , 0 , V_39 ) ;
V_170 = 1 ;
}
}
return V_170 ;
}
static T_3 F_63 ( struct V_91 * V_104 , const char * V_171 )
{
return F_64 ( V_104 -> V_8 . V_11 , V_171 , sizeof( V_104 -> V_8 . V_11 ) ) ;
}
static void F_65 ( struct V_91 * V_104 ,
struct V_172 * V_105 )
{
const char * V_173 [] = {
L_14 , L_30 , L_31 , L_32 , NULL } ;
const char * * V_174 ;
bool V_175 = false ;
if ( strcmp ( L_33 , V_104 -> V_8 . V_11 ) )
return;
for ( V_174 = V_173 ; * V_174 ; V_174 ++ )
if ( strstr ( V_105 -> V_176 , * V_174 ) ) {
V_175 = true ;
break;
}
if ( ! V_175 )
return;
F_3 ( V_104 -> V_8 . V_11 , L_31 , sizeof( V_104 -> V_8 . V_11 ) ) ;
}
static void F_66 ( struct V_2 * V_3 , void * V_177 ,
unsigned int V_178 , int V_5 ,
struct V_109 * V_110 , int V_4 ,
int V_179 )
{
struct V_26 * V_180 = V_177 ;
unsigned int V_36 = 0 ;
int V_181 = 0 ;
int V_182 = F_67 ( V_180 ) ;
struct V_91 * V_104 ;
struct V_13 * V_14 ;
const struct V_1 * V_7 ;
unsigned int V_183 ;
V_5 ++ ;
if ( V_5 == V_184 ) {
return;
}
V_7 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_185 ) ;
if ( ! V_14 )
return;
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_5 ;
V_14 -> V_148 = V_178 ;
V_14 -> V_40 = V_186 [ V_5 - 1 ] . type ;
if ( V_178 == 0 ) {
V_14 -> V_123 = 1 ;
V_14 -> V_88 = V_179 ;
} else {
int V_149 , V_167 = 0 ;
for ( V_149 = 0 ; V_149 < 16 ; V_149 ++ )
if ( V_178 & ( 1 << V_149 ) )
V_167 ++ ;
V_14 -> V_123 = V_167 ;
V_14 -> V_89 = V_179 ;
}
if ( V_14 -> V_123 == V_179 )
V_104 = F_69 ( & V_187 , V_14 ) ;
else
V_104 = F_69 ( & V_188 , V_14 ) ;
if ( ! V_104 ) {
F_26 ( V_3 -> V_37 , L_34 ) ;
F_54 ( V_14 ) ;
return;
}
V_104 -> V_189 = F_53 ;
V_36 = F_2 ( V_7 , V_104 -> V_8 . V_11 , sizeof( V_104 -> V_8 . V_11 ) ) ;
V_181 = V_36 != 0 ;
if ( ! V_36 && V_182 )
V_36 = F_9 ( V_3 , V_182 ,
V_104 -> V_8 . V_11 , sizeof( V_104 -> V_8 . V_11 ) ) ;
switch ( V_5 ) {
case V_190 :
case V_191 :
if ( ! V_36 ) {
V_36 = F_42 ( V_3 , V_110 , V_104 -> V_8 . V_11 ,
sizeof( V_104 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = F_42 ( V_3 , & V_3 -> V_192 ,
V_104 -> V_8 . V_11 ,
sizeof( V_104 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = snprintf ( V_104 -> V_8 . V_11 ,
sizeof( V_104 -> V_8 . V_11 ) ,
L_35 , V_4 ) ;
}
if ( ! V_181 )
F_65 ( V_104 , V_3 -> V_52 -> V_37 -> V_105 ) ;
if ( ! V_181 && ! ( V_3 -> V_192 . type >> 16 ) ) {
if ( ( V_3 -> V_192 . type & 0xff00 ) == 0x0100 )
V_36 = F_63 ( V_104 , L_36 ) ;
else
V_36 = F_63 ( V_104 , L_37 ) ;
}
F_63 ( V_104 , V_5 == V_190 ?
L_38 : L_39 ) ;
break;
default:
if ( ! V_36 )
F_3 ( V_104 -> V_8 . V_11 , V_186 [ V_5 - 1 ] . V_11 ,
sizeof( V_104 -> V_8 . V_11 ) ) ;
break;
}
F_58 ( V_14 , 0 , V_104 ) ;
if ( V_5 == V_191 ) {
F_5 ( V_7 , V_14 ) ;
if ( V_14 -> V_15 < V_14 -> V_17 || ! V_14 -> V_19 ) {
V_104 -> V_193 . V_167 = F_35 ;
V_104 -> V_160 [ 0 ] . V_161 |=
V_162 |
V_163 ;
}
}
V_183 = ( V_14 -> V_18 - V_14 -> V_16 ) / V_14 -> V_47 ;
if ( V_183 > 384 ) {
F_70 ( V_3 -> V_37 ,
L_40
L_41 ,
V_183 ) ;
F_70 ( V_3 -> V_37 , L_42
L_43 , V_14 -> V_8 ,
V_104 -> V_8 . V_11 , V_14 -> V_123 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
}
F_22 ( V_3 -> V_37 , L_44 ,
V_14 -> V_8 , V_104 -> V_8 . V_11 , V_14 -> V_123 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
F_39 ( V_3 -> V_52 , V_104 ) ;
}
static int F_71 ( struct V_2 * V_3 , int V_4 ,
void * V_194 )
{
int V_123 , V_149 , V_195 ;
struct V_109 V_110 ;
unsigned int V_196 , V_197 ;
int V_56 , V_198 ;
struct V_26 * V_27 = V_194 ;
T_1 * V_199 ;
if ( V_3 -> V_52 -> V_77 == V_78 ) {
V_198 = V_27 -> V_200 ;
if ( ! V_198 ) {
F_22 ( V_3 -> V_37 ,
L_45 ,
V_4 ) ;
return - V_64 ;
}
V_123 = ( V_27 -> V_30 - 7 ) / V_198 - 1 ;
V_199 = V_27 -> V_199 ;
if ( V_27 -> V_30 < 7 + V_198 ) {
F_26 ( V_3 -> V_37 ,
L_46 ,
V_4 ) ;
return - V_64 ;
}
} else {
struct V_201 * V_202 = V_194 ;
V_198 = 4 ;
V_123 = ( V_27 -> V_30 - 6 ) / 4 - 1 ;
V_199 = V_202 -> V_199 ;
if ( V_27 -> V_30 < 6 + V_198 ) {
F_26 ( V_3 -> V_37 ,
L_46 ,
V_4 ) ;
return - V_64 ;
}
}
if ( ( V_56 = F_72 ( V_3 , V_27 -> V_132 ) ) < 0 )
return V_56 ;
V_56 = F_43 ( V_3 , V_27 -> V_132 , & V_110 ) ;
if ( V_56 < 0 )
return V_56 ;
V_196 = F_21 ( V_199 , V_198 ) ;
switch ( V_3 -> V_37 -> V_145 ) {
case F_56 ( 0x08bb , 0x2702 ) :
F_57 ( V_3 -> V_37 ,
L_47 ) ;
V_196 &= ~ F_73 ( V_191 ) ;
break;
case F_56 ( 0x1130 , 0xf211 ) :
F_57 ( V_3 -> V_37 ,
L_48 ) ;
V_123 = 0 ;
break;
}
if ( V_123 > 0 )
V_197 = F_21 ( V_199 + V_198 , V_198 ) ;
else
V_197 = 0 ;
if ( V_3 -> V_52 -> V_77 == V_78 ) {
for ( V_149 = 0 ; V_149 < 10 ; V_149 ++ ) {
unsigned int V_203 = 0 ;
for ( V_195 = 0 ; V_195 < V_123 ; V_195 ++ ) {
unsigned int V_204 ;
V_204 = F_21 ( V_199 +
V_198 * ( V_195 + 1 ) , V_198 ) ;
if ( V_204 & ( 1 << V_149 ) )
V_203 |= ( 1 << V_195 ) ;
}
if ( V_203 & 1 )
F_66 ( V_3 , V_194 , V_203 , V_149 ,
& V_110 , V_4 , 0 ) ;
if ( V_196 & ( 1 << V_149 ) )
F_66 ( V_3 , V_194 , 0 , V_149 , & V_110 ,
V_4 , 0 ) ;
}
} else {
for ( V_149 = 0 ; V_149 < F_74 ( V_186 ) ; V_149 ++ ) {
unsigned int V_203 = 0 ;
unsigned int V_205 = 0 ;
for ( V_195 = 0 ; V_195 < V_123 ; V_195 ++ ) {
unsigned int V_204 ;
V_204 = F_21 ( V_199 +
V_198 * ( V_195 + 1 ) , V_198 ) ;
if ( F_75 ( V_204 , V_149 ) ) {
V_203 |= ( 1 << V_195 ) ;
if ( ! F_76 ( V_204 , V_149 ) )
V_205 |= ( 1 << V_195 ) ;
}
}
if ( V_203 & 1 )
F_66 ( V_3 , V_194 , V_203 , V_149 ,
& V_110 , V_4 , V_205 ) ;
if ( F_75 ( V_196 , V_149 ) )
F_66 ( V_3 , V_194 , 0 , V_149 , & V_110 , V_4 ,
! F_76 ( V_196 , V_149 ) ) ;
}
}
return 0 ;
}
static void F_77 ( struct V_2 * V_3 ,
struct V_133 * V_180 ,
int V_206 , int V_207 , int V_4 ,
struct V_109 * V_110 )
{
struct V_13 * V_14 ;
unsigned int V_102 = F_46 ( V_180 ) ;
unsigned int V_149 , V_36 ;
struct V_91 * V_104 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_68 ( sizeof( * V_14 ) , V_185 ) ;
if ( ! V_14 )
return;
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_207 + 1 ;
V_14 -> V_40 = V_46 ;
for ( V_149 = 0 ; V_149 < V_102 ; V_149 ++ ) {
T_1 * V_167 = F_78 ( V_180 , V_3 -> V_52 -> V_77 ) ;
if ( F_38 ( V_167 , V_207 , V_149 , V_102 ) ) {
V_14 -> V_148 |= ( 1 << V_149 ) ;
V_14 -> V_123 ++ ;
}
}
F_79 ( V_14 , 0 ) ;
V_104 = F_69 ( & V_188 , V_14 ) ;
if ( ! V_104 ) {
F_26 ( V_3 -> V_37 , L_34 ) ;
F_54 ( V_14 ) ;
return;
}
V_104 -> V_189 = F_53 ;
V_36 = F_2 ( V_7 , V_104 -> V_8 . V_11 , sizeof( V_104 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
V_36 = F_42 ( V_3 , V_110 , V_104 -> V_8 . V_11 ,
sizeof( V_104 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
V_36 = sprintf ( V_104 -> V_8 . V_11 , L_49 , V_207 + 1 ) ;
F_63 ( V_104 , L_39 ) ;
F_22 ( V_3 -> V_37 , L_50 ,
V_14 -> V_8 , V_104 -> V_8 . V_11 , V_14 -> V_123 , V_14 -> V_16 , V_14 -> V_18 ) ;
F_39 ( V_3 -> V_52 , V_104 ) ;
}
static int F_80 ( struct V_2 * V_3 , int V_4 ,
void * V_177 )
{
struct V_133 * V_180 = V_177 ;
struct V_109 V_110 ;
int V_208 , V_209 , V_102 ;
int V_210 , V_100 , V_56 ;
if ( V_180 -> V_30 < 11 || ! ( V_208 = V_180 -> V_141 ) ||
! ( V_102 = F_46 ( V_180 ) ) ) {
F_26 ( V_3 -> V_37 ,
L_51 ,
V_4 ) ;
return - V_64 ;
}
if ( V_180 -> V_30 <= 10 + V_208 ) {
F_22 ( V_3 -> V_37 , L_52 ,
V_4 ) ;
return 0 ;
}
V_209 = 0 ;
V_100 = 0 ;
for ( V_210 = 0 ; V_210 < V_208 ; V_210 ++ ) {
V_56 = F_72 ( V_3 , V_180 -> V_136 [ V_210 ] ) ;
if ( V_56 < 0 )
continue;
V_56 = F_43 ( V_3 , V_180 -> V_136 [ V_210 ] , & V_110 ) ;
if ( V_56 < 0 )
return V_56 ;
V_209 += V_110 . V_123 ;
for (; V_100 < V_209 ; V_100 ++ ) {
int V_101 , V_211 = 0 ;
for ( V_101 = 0 ; V_101 < V_102 ; V_101 ++ ) {
T_1 * V_167 = F_78 ( V_180 ,
V_3 -> V_52 -> V_77 ) ;
if ( F_38 ( V_167 , V_100 , V_101 , V_102 ) ) {
V_211 = 1 ;
break;
}
}
if ( V_211 )
F_77 ( V_3 , V_180 , V_210 , V_100 ,
V_4 , & V_110 ) ;
}
}
return 0 ;
}
static int F_81 ( struct V_91 * V_92 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = V_92 -> V_95 ;
int V_56 , V_39 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_56 < 0 && V_14 -> V_52 -> V_83 ) {
V_166 -> V_79 . integer . V_79 [ 0 ] = V_14 -> V_16 ;
return 0 ;
}
if ( V_56 < 0 )
return V_56 ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_166 -> V_79 . integer . V_79 [ 0 ] = V_39 ;
return 0 ;
}
static int F_82 ( struct V_91 * V_92 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = V_92 -> V_95 ;
int V_39 , V_169 , V_56 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_169 ) ;
if ( V_56 < 0 ) {
if ( V_14 -> V_52 -> V_83 )
return 0 ;
return V_56 ;
}
V_39 = V_166 -> V_79 . integer . V_79 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_169 ) {
F_33 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_83 ( struct V_2 * V_3 , int V_4 ,
void * V_177 , struct V_212 * V_213 ,
char * V_11 )
{
struct V_138 * V_180 = V_177 ;
int V_209 = V_180 -> V_141 ;
struct V_13 * V_14 ;
struct V_91 * V_104 ;
int V_149 , V_56 , V_182 , type , V_36 ;
struct V_212 * V_214 ;
struct V_215 * V_216 ;
const struct V_1 * V_7 ;
static struct V_215 V_217 [] = {
{ 0x01 , L_53 , V_41 } ,
{ 0 }
} ;
static struct V_212 V_218 = {
0 , NULL , V_217
} ;
if ( V_180 -> V_30 < 13 || V_180 -> V_30 < 13 + V_209 ||
V_180 -> V_30 < V_209 + F_84 ( V_180 , V_3 -> V_52 -> V_77 ) ) {
F_26 ( V_3 -> V_37 , L_54 , V_11 , V_4 ) ;
return - V_64 ;
}
for ( V_149 = 0 ; V_149 < V_209 ; V_149 ++ ) {
if ( ( V_56 = F_72 ( V_3 , V_180 -> V_136 [ V_149 ] ) ) < 0 )
return V_56 ;
}
type = F_44 ( V_180 -> V_219 ) ;
for ( V_214 = V_213 ; V_214 && V_214 -> type ; V_214 ++ )
if ( V_214 -> type == type )
break;
if ( ! V_214 || ! V_214 -> type )
V_214 = & V_218 ;
for ( V_216 = V_214 -> V_220 ; V_216 -> V_5 ; V_216 ++ ) {
T_1 * V_221 = F_85 ( V_180 , V_3 -> V_52 -> V_77 ) ;
if ( ! ( V_221 [ V_216 -> V_5 / 8 ] & ( 1 << ( ( V_216 -> V_5 % 8 ) - 1 ) ) ) )
continue;
V_7 = F_1 ( V_3 , V_4 , V_216 -> V_5 ) ;
if ( F_4 ( V_7 ) )
continue;
V_14 = F_68 ( sizeof( * V_14 ) , V_185 ) ;
if ( ! V_14 )
return - V_97 ;
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_5 = V_216 -> V_5 ;
V_14 -> V_40 = V_216 -> V_40 ;
V_14 -> V_123 = 1 ;
if ( type == V_222 && V_14 -> V_5 == V_223 ) {
T_1 * V_224 = F_86 ( V_180 , V_3 -> V_52 -> V_77 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_224 [ 0 ] ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else {
if ( type == V_225 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 5 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else
F_79 ( V_14 , V_216 -> V_226 ) ;
}
V_104 = F_69 ( & V_227 , V_14 ) ;
if ( ! V_104 ) {
F_54 ( V_14 ) ;
return - V_97 ;
}
V_104 -> V_189 = F_53 ;
if ( F_2 ( V_7 , V_104 -> V_8 . V_11 , sizeof( V_104 -> V_8 . V_11 ) ) ) {
;
} else if ( V_214 -> V_11 ) {
F_3 ( V_104 -> V_8 . V_11 , V_214 -> V_11 , sizeof( V_104 -> V_8 . V_11 ) ) ;
} else {
V_182 = F_52 ( V_180 , V_3 -> V_52 -> V_77 ) ;
V_36 = 0 ;
if ( V_182 )
V_36 = F_9 ( V_3 , V_182 ,
V_104 -> V_8 . V_11 ,
sizeof( V_104 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
F_3 ( V_104 -> V_8 . V_11 , V_11 , sizeof( V_104 -> V_8 . V_11 ) ) ;
}
F_63 ( V_104 , L_55 ) ;
F_63 ( V_104 , V_216 -> V_228 ) ;
F_22 ( V_3 -> V_37 ,
L_56 ,
V_14 -> V_8 , V_104 -> V_8 . V_11 , V_14 -> V_123 ,
V_14 -> V_16 , V_14 -> V_18 ) ;
V_56 = F_39 ( V_3 -> V_52 , V_104 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
static int F_87 ( struct V_2 * V_3 , int V_4 ,
void * V_177 )
{
return F_83 ( V_3 , V_4 , V_177 ,
V_229 , L_57 ) ;
}
static int F_88 ( struct V_2 * V_3 , int V_4 ,
void * V_177 )
{
return F_83 ( V_3 , V_4 , V_177 ,
V_230 , L_58 ) ;
}
static int F_89 ( struct V_91 * V_92 ,
struct V_156 * V_157 )
{
struct V_13 * V_14 = V_92 -> V_95 ;
const char * * V_231 = ( const char * * ) V_92 -> V_232 ;
if ( F_90 ( ! V_231 ) )
return - V_64 ;
return F_91 ( V_157 , 1 , V_14 -> V_18 , V_231 ) ;
}
static int F_92 ( struct V_91 * V_92 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = V_92 -> V_95 ;
int V_39 , V_56 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_56 < 0 ) {
if ( V_14 -> V_52 -> V_83 ) {
V_166 -> V_79 . V_233 . V_234 [ 0 ] = 0 ;
return 0 ;
}
return V_56 ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_166 -> V_79 . V_233 . V_234 [ 0 ] = V_39 ;
return 0 ;
}
static int F_93 ( struct V_91 * V_92 ,
struct V_165 * V_166 )
{
struct V_13 * V_14 = V_92 -> V_95 ;
int V_39 , V_169 , V_56 ;
V_56 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_169 ) ;
if ( V_56 < 0 ) {
if ( V_14 -> V_52 -> V_83 )
return 0 ;
return V_56 ;
}
V_39 = V_166 -> V_79 . V_233 . V_234 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_169 ) {
F_33 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static void F_94 ( struct V_91 * V_104 )
{
int V_149 , V_209 = 0 ;
if ( V_104 -> V_95 ) {
struct V_13 * V_14 = V_104 -> V_95 ;
V_209 = V_14 -> V_18 ;
F_54 ( V_14 ) ;
V_104 -> V_95 = NULL ;
}
if ( V_104 -> V_232 ) {
char * * V_231 = ( char * * ) V_104 -> V_232 ;
for ( V_149 = 0 ; V_149 < V_209 ; V_149 ++ )
F_54 ( V_231 [ V_149 ] ) ;
F_54 ( V_231 ) ;
V_104 -> V_232 = 0 ;
}
}
static int F_95 ( struct V_2 * V_3 , int V_4 ,
void * V_177 )
{
struct V_135 * V_180 = V_177 ;
unsigned int V_149 , V_182 , V_36 ;
int V_56 ;
struct V_13 * V_14 ;
struct V_91 * V_104 ;
const struct V_1 * V_7 ;
char * * V_235 ;
if ( ! V_180 -> V_141 || V_180 -> V_30 < 5 + V_180 -> V_141 ) {
F_26 ( V_3 -> V_37 ,
L_59 , V_4 ) ;
return - V_64 ;
}
for ( V_149 = 0 ; V_149 < V_180 -> V_141 ; V_149 ++ ) {
if ( ( V_56 = F_72 ( V_3 , V_180 -> V_136 [ V_149 ] ) ) < 0 )
return V_56 ;
}
if ( V_180 -> V_141 == 1 )
return 0 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
V_14 = F_68 ( sizeof( * V_14 ) , V_185 ) ;
if ( ! V_14 )
return - V_97 ;
V_14 -> V_52 = V_3 -> V_52 ;
V_14 -> V_8 = V_4 ;
V_14 -> V_40 = V_43 ;
V_14 -> V_123 = 1 ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_180 -> V_141 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
if ( V_180 -> V_31 == V_134 )
V_14 -> V_5 = V_236 ;
else
V_14 -> V_5 = 0 ;
V_235 = F_96 ( sizeof( char * ) * V_180 -> V_141 , V_185 ) ;
if ( ! V_235 ) {
F_54 ( V_14 ) ;
return - V_97 ;
}
#define F_97 64
for ( V_149 = 0 ; V_149 < V_180 -> V_141 ; V_149 ++ ) {
struct V_109 V_110 ;
V_36 = 0 ;
V_235 [ V_149 ] = F_96 ( F_97 , V_185 ) ;
if ( ! V_235 [ V_149 ] ) {
while ( V_149 -- )
F_54 ( V_235 [ V_149 ] ) ;
F_54 ( V_235 ) ;
F_54 ( V_14 ) ;
return - V_97 ;
}
V_36 = F_6 ( V_3 , V_4 , V_149 , V_235 [ V_149 ] ,
F_97 ) ;
if ( ! V_36 && F_43 ( V_3 , V_180 -> V_136 [ V_149 ] , & V_110 ) >= 0 )
V_36 = F_42 ( V_3 , & V_110 , V_235 [ V_149 ] , F_97 , 0 ) ;
if ( ! V_36 )
sprintf ( V_235 [ V_149 ] , L_60 , V_149 ) ;
}
V_104 = F_69 ( & V_237 , V_14 ) ;
if ( ! V_104 ) {
F_26 ( V_3 -> V_37 , L_34 ) ;
F_54 ( V_235 ) ;
F_54 ( V_14 ) ;
return - V_97 ;
}
V_104 -> V_232 = ( unsigned long ) V_235 ;
V_104 -> V_189 = F_94 ;
V_182 = F_49 ( V_180 ) ;
V_36 = F_2 ( V_7 , V_104 -> V_8 . V_11 , sizeof( V_104 -> V_8 . V_11 ) ) ;
if ( V_36 )
;
else if ( V_182 )
F_9 ( V_3 , V_182 , V_104 -> V_8 . V_11 ,
sizeof( V_104 -> V_8 . V_11 ) ) ;
else {
V_36 = F_42 ( V_3 , & V_3 -> V_192 ,
V_104 -> V_8 . V_11 , sizeof( V_104 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
F_3 ( V_104 -> V_8 . V_11 , L_61 , sizeof( V_104 -> V_8 . V_11 ) ) ;
if ( V_180 -> V_31 == V_134 )
F_63 ( V_104 , L_62 ) ;
else if ( ( V_3 -> V_192 . type & 0xff00 ) == 0x0100 )
F_63 ( V_104 , L_63 ) ;
else
F_63 ( V_104 , L_64 ) ;
}
F_22 ( V_3 -> V_37 , L_65 ,
V_14 -> V_8 , V_104 -> V_8 . V_11 , V_180 -> V_141 ) ;
if ( ( V_56 = F_39 ( V_3 -> V_52 , V_104 ) ) < 0 )
return V_56 ;
return 0 ;
}
static int F_72 ( struct V_2 * V_3 , int V_4 )
{
unsigned char * V_119 ;
if ( F_98 ( V_4 , V_3 -> V_238 ) )
return 0 ;
V_119 = F_7 ( V_3 , V_4 ) ;
if ( ! V_119 ) {
F_26 ( V_3 -> V_37 , L_66 , V_4 ) ;
return - V_64 ;
}
switch ( V_119 [ 2 ] ) {
case V_32 :
case V_142 :
return 0 ;
case V_116 :
return F_80 ( V_3 , V_4 , V_119 ) ;
case V_113 :
case V_134 :
return F_95 ( V_3 , V_4 , V_119 ) ;
case V_131 :
return F_71 ( V_3 , V_4 , V_119 ) ;
case V_114 :
if ( V_3 -> V_52 -> V_77 == V_78 )
return F_87 ( V_3 , V_4 , V_119 ) ;
else
return 0 ;
case V_115 :
if ( V_3 -> V_52 -> V_77 == V_78 )
return F_88 ( V_3 , V_4 , V_119 ) ;
else
return F_87 ( V_3 , V_4 , V_119 ) ;
case V_137 :
return F_88 ( V_3 , V_4 , V_119 ) ;
default:
F_26 ( V_3 -> V_37 ,
L_67 , V_4 , V_119 [ 2 ] ) ;
return - V_64 ;
}
}
static void F_99 ( struct V_103 * V_52 )
{
F_54 ( V_52 -> V_108 ) ;
if ( V_52 -> V_239 ) {
F_54 ( V_52 -> V_239 -> V_240 ) ;
F_100 ( V_52 -> V_239 ) ;
}
F_100 ( V_52 -> V_241 ) ;
F_54 ( V_52 -> V_242 ) ;
F_54 ( V_52 ) ;
}
static int F_101 ( struct V_243 * V_244 )
{
struct V_103 * V_52 = V_244 -> V_245 ;
F_99 ( V_52 ) ;
return 0 ;
}
static int F_102 ( struct V_103 * V_52 )
{
struct V_2 V_3 ;
int V_56 ;
const struct V_246 * V_7 ;
void * V_6 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_37 = V_52 -> V_37 ;
V_3 . V_52 = V_52 ;
V_3 . V_28 = V_52 -> V_247 -> V_248 ;
V_3 . V_10 = V_52 -> V_247 -> V_249 ;
for ( V_7 = V_250 ; V_7 -> V_8 ; V_7 ++ ) {
if ( V_7 -> V_8 == V_3 . V_37 -> V_145 ) {
V_3 . V_7 = V_7 -> V_7 ;
V_3 . V_22 = V_7 -> V_22 ;
V_52 -> V_83 = V_7 -> V_83 ;
break;
}
}
V_6 = NULL ;
while ( ( V_6 = F_103 ( V_52 -> V_247 -> V_248 ,
V_52 -> V_247 -> V_249 ,
V_6 , V_251 ) ) != NULL ) {
if ( V_52 -> V_77 == V_78 ) {
struct V_252 * V_180 = V_6 ;
if ( V_180 -> V_30 < sizeof( * V_180 ) )
continue;
F_104 ( V_180 -> V_253 , V_3 . V_238 ) ;
V_3 . V_192 . V_8 = V_180 -> V_253 ;
V_3 . V_192 . type = F_44 ( V_180 -> V_122 ) ;
V_3 . V_192 . V_11 = V_180 -> V_127 ;
V_56 = F_72 ( & V_3 , V_180 -> V_132 ) ;
if ( V_56 < 0 && V_56 != - V_64 )
return V_56 ;
} else {
struct V_254 * V_180 = V_6 ;
if ( V_180 -> V_30 < sizeof( * V_180 ) )
continue;
F_104 ( V_180 -> V_253 , V_3 . V_238 ) ;
V_3 . V_192 . V_8 = V_180 -> V_253 ;
V_3 . V_192 . type = F_44 ( V_180 -> V_122 ) ;
V_3 . V_192 . V_11 = V_180 -> V_127 ;
V_56 = F_72 ( & V_3 , V_180 -> V_132 ) ;
if ( V_56 < 0 && V_56 != - V_64 )
return V_56 ;
V_56 = F_72 ( & V_3 , V_180 -> V_130 ) ;
if ( V_56 < 0 && V_56 != - V_64 )
return V_56 ;
}
}
return 0 ;
}
void F_105 ( struct V_103 * V_52 , int V_4 )
{
struct V_13 * V_214 ;
for ( V_214 = V_52 -> V_108 [ V_4 ] ; V_214 ; V_214 = V_214 -> V_107 )
F_60 ( V_52 -> V_37 -> V_105 , V_255 ,
V_214 -> V_106 ) ;
}
static void F_106 ( struct V_256 * V_28 ,
int V_4 ,
struct V_13 * V_14 )
{
static char * V_257 [] = { L_68 , L_69 ,
L_70 , L_71 , L_72 , L_73 } ;
F_107 ( V_28 , L_74 , V_4 ) ;
if ( V_14 -> V_106 )
F_107 ( V_28 , L_75 ,
V_14 -> V_106 -> V_11 , V_14 -> V_106 -> V_20 ) ;
F_107 ( V_28 , L_76
L_77 , V_14 -> V_8 ,
V_14 -> V_5 , V_14 -> V_148 , V_14 -> V_123 ,
V_257 [ V_14 -> V_40 ] ) ;
F_107 ( V_28 , L_78 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_15 , V_14 -> V_17 ) ;
}
static void F_108 ( struct V_258 * V_259 ,
struct V_256 * V_28 )
{
struct V_51 * V_37 = V_259 -> V_95 ;
struct V_103 * V_52 ;
struct V_13 * V_14 ;
int V_4 ;
F_109 (mixer, &chip->mixer_list, list) {
F_107 ( V_28 ,
L_79 ,
V_37 -> V_145 , F_18 ( V_37 ) ,
V_52 -> V_83 ) ;
F_107 ( V_28 , L_80 , V_37 -> V_105 -> V_260 ) ;
for ( V_4 = 0 ; V_4 < V_261 ; V_4 ++ ) {
for ( V_14 = V_52 -> V_108 [ V_4 ] ; V_14 ;
V_14 = V_14 -> V_107 )
F_106 ( V_28 , V_4 , V_14 ) ;
}
}
}
static void F_110 ( struct V_103 * V_52 ,
int V_262 , int V_79 , int V_20 )
{
struct V_13 * V_214 ;
T_1 V_4 = ( V_20 >> 8 ) & 0xff ;
T_1 V_5 = ( V_79 >> 8 ) & 0xff ;
T_1 V_80 = V_79 & 0xff ;
if ( V_80 >= V_150 ) {
F_22 ( V_52 -> V_37 ,
L_81 ,
V_90 , V_80 ) ;
return;
}
for ( V_214 = V_52 -> V_108 [ V_4 ] ; V_214 ; V_214 = V_214 -> V_107 ) {
if ( V_214 -> V_5 != V_5 )
continue;
switch ( V_262 ) {
case V_70 :
if ( V_80 )
V_214 -> V_81 &= ~ ( 1 << V_80 ) ;
else
V_214 -> V_81 = 0 ;
F_60 ( V_52 -> V_37 -> V_105 , V_255 ,
V_214 -> V_106 ) ;
break;
case V_71 :
break;
case V_263 :
break;
default:
F_22 ( V_52 -> V_37 ,
L_82 ,
V_262 ) ;
break;
}
}
}
static void F_111 ( struct V_239 * V_239 )
{
struct V_103 * V_52 = V_239 -> V_264 ;
int V_36 = V_239 -> V_265 ;
int V_266 = V_239 -> V_267 ;
if ( V_266 != 0 )
goto V_268;
if ( V_52 -> V_77 == V_78 ) {
struct V_269 * V_267 ;
for ( V_267 = V_239 -> V_240 ;
V_36 >= sizeof( * V_267 ) ;
V_36 -= sizeof( * V_267 ) , V_267 ++ ) {
F_112 ( & V_239 -> V_38 -> V_38 , L_83 ,
V_267 -> V_270 ,
V_267 -> V_271 ) ;
if ( ( V_267 -> V_270 & V_272 ) !=
V_273 )
continue;
if ( V_267 -> V_270 & V_274 )
F_113 ( V_52 , V_267 -> V_271 ) ;
else
F_105 ( V_52 , V_267 -> V_271 ) ;
}
} else {
struct V_275 * V_276 ;
for ( V_276 = V_239 -> V_240 ;
V_36 >= sizeof( * V_276 ) ;
V_36 -= sizeof( * V_276 ) , V_276 ++ ) {
if ( ( V_276 -> V_277 & V_278 ) ||
( V_276 -> V_277 & V_279 ) )
continue;
F_110 ( V_52 , V_276 -> V_280 ,
F_44 ( V_276 -> V_281 ) ,
F_44 ( V_276 -> V_282 ) ) ;
}
}
V_268:
if ( V_266 != - V_283 &&
V_266 != - V_284 &&
V_266 != - V_285 ) {
V_239 -> V_38 = V_52 -> V_37 -> V_38 ;
F_114 ( V_239 , V_286 ) ;
}
}
static int F_115 ( struct V_103 * V_52 )
{
struct V_287 * V_288 ;
void * V_240 ;
int V_289 ;
unsigned int V_290 ;
if ( F_116 ( V_52 -> V_247 ) -> V_291 < 1 )
return 0 ;
V_288 = F_117 ( V_52 -> V_247 , 0 ) ;
if ( ! F_118 ( V_288 ) || ! F_119 ( V_288 ) )
return 0 ;
V_290 = F_120 ( V_288 ) ;
V_289 = F_44 ( V_288 -> V_292 ) ;
V_240 = F_96 ( V_289 , V_185 ) ;
if ( ! V_240 )
return - V_97 ;
V_52 -> V_239 = F_121 ( 0 , V_185 ) ;
if ( ! V_52 -> V_239 ) {
F_54 ( V_240 ) ;
return - V_97 ;
}
F_122 ( V_52 -> V_239 , V_52 -> V_37 -> V_38 ,
F_123 ( V_52 -> V_37 -> V_38 , V_290 ) ,
V_240 , V_289 ,
F_111 , V_52 , V_288 -> V_293 ) ;
F_114 ( V_52 -> V_239 , V_185 ) ;
return 0 ;
}
int F_124 ( struct V_51 * V_37 , int V_294 ,
int V_295 )
{
static struct V_296 V_297 = {
. V_298 = F_101
} ;
struct V_103 * V_52 ;
struct V_258 * V_259 ;
int V_56 ;
strcpy ( V_37 -> V_105 -> V_299 , L_84 ) ;
V_52 = F_68 ( sizeof( * V_52 ) , V_185 ) ;
if ( ! V_52 )
return - V_97 ;
V_52 -> V_37 = V_37 ;
V_52 -> V_83 = V_295 ;
V_52 -> V_108 = F_125 ( V_261 , sizeof( * V_52 -> V_108 ) ,
V_185 ) ;
if ( ! V_52 -> V_108 ) {
F_54 ( V_52 ) ;
return - V_97 ;
}
V_52 -> V_247 = & F_126 ( V_37 -> V_38 , V_294 ) -> V_300 [ 0 ] ;
switch ( F_116 ( V_52 -> V_247 ) -> V_301 ) {
case V_78 :
default:
V_52 -> V_77 = V_78 ;
break;
case V_139 :
V_52 -> V_77 = V_139 ;
break;
}
if ( ( V_56 = F_102 ( V_52 ) ) < 0 ||
( V_56 = F_115 ( V_52 ) ) < 0 )
goto V_302;
F_127 ( V_52 ) ;
V_56 = F_128 ( V_37 -> V_105 , V_303 , V_52 , & V_297 ) ;
if ( V_56 < 0 )
goto V_302;
if ( F_129 ( & V_37 -> V_304 ) &&
! F_130 ( V_37 -> V_105 , L_85 , & V_259 ) )
F_131 ( V_259 , V_37 , F_108 ) ;
F_132 ( & V_52 -> V_213 , & V_37 -> V_304 ) ;
return 0 ;
V_302:
F_99 ( V_52 ) ;
return V_56 ;
}
void F_133 ( struct V_305 * V_6 )
{
struct V_103 * V_52 ;
V_52 = F_134 ( V_6 , struct V_103 , V_213 ) ;
F_135 ( V_52 -> V_239 ) ;
F_135 ( V_52 -> V_241 ) ;
}
static void F_136 ( struct V_103 * V_52 )
{
F_135 ( V_52 -> V_239 ) ;
F_135 ( V_52 -> V_241 ) ;
}
static int F_137 ( struct V_103 * V_52 )
{
int V_56 ;
if ( V_52 -> V_239 ) {
V_56 = F_114 ( V_52 -> V_239 , V_306 ) ;
if ( V_56 < 0 )
return V_56 ;
}
return 0 ;
}
int F_138 ( struct V_103 * V_52 )
{
F_136 ( V_52 ) ;
return 0 ;
}
static int F_139 ( struct V_13 * V_14 )
{
int V_167 , V_56 , V_55 ;
if ( V_14 -> V_148 ) {
V_55 = 0 ;
for ( V_167 = 0 ; V_167 < V_150 ; V_167 ++ ) {
if ( ! ( V_14 -> V_148 & ( 1 << V_167 ) ) )
continue;
if ( V_14 -> V_81 & ( 1 << V_167 ) ) {
V_56 = F_34 ( V_14 , V_167 + 1 , V_55 ,
V_14 -> V_82 [ V_55 ] ) ;
if ( V_56 < 0 )
return V_56 ;
}
V_55 ++ ;
}
} else {
if ( V_14 -> V_81 ) {
V_56 = F_34 ( V_14 , 0 , 0 , * V_14 -> V_82 ) ;
if ( V_56 < 0 )
return V_56 ;
}
}
return 0 ;
}
int F_140 ( struct V_103 * V_52 , bool V_307 )
{
struct V_13 * V_14 ;
int V_8 , V_56 ;
if ( V_307 ) {
for ( V_8 = 0 ; V_8 < V_261 ; V_8 ++ ) {
for ( V_14 = V_52 -> V_108 [ V_8 ] ; V_14 ;
V_14 = V_14 -> V_107 ) {
V_56 = F_139 ( V_14 ) ;
if ( V_56 < 0 )
return V_56 ;
}
}
}
return F_137 ( V_52 ) ;
}
