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
struct V_51 * V_37 = V_14 -> V_52 . V_53 -> V_37 ;
unsigned char V_9 [ 2 ] ;
int V_54 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
int V_55 = 10 ;
int V_56 = 0 , V_57 ;
V_57 = F_16 ( V_37 ) ;
if ( V_57 < 0 )
return - V_58 ;
F_17 ( & V_37 -> V_59 ) ;
while ( V_55 -- > 0 ) {
if ( V_37 -> V_60 )
break;
V_56 = F_18 ( V_37 ) | ( V_14 -> V_52 . V_8 << 8 ) ;
if ( F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_48 ,
V_61 | V_62 | V_63 ,
V_49 , V_56 , V_9 , V_54 ) >= V_54 ) {
* V_50 = F_11 ( V_14 , F_21 ( V_9 , V_54 ) ) ;
V_57 = 0 ;
goto V_64;
}
}
F_22 ( V_37 ,
L_1 ,
V_48 , V_49 , V_56 , V_14 -> V_40 ) ;
V_57 = - V_65 ;
V_64:
F_23 ( & V_37 -> V_59 ) ;
F_24 ( V_37 ) ;
return V_57 ;
}
static int F_25 ( struct V_13 * V_14 , int V_48 ,
int V_49 , int * V_50 )
{
struct V_51 * V_37 = V_14 -> V_52 . V_53 -> V_37 ;
unsigned char V_9 [ 2 + 3 * sizeof( V_66 ) ] ;
unsigned char * V_39 ;
int V_56 = 0 , V_67 , V_68 ;
T_1 V_69 ;
if ( V_48 == V_70 ) {
V_69 = V_71 ;
V_68 = sizeof( V_66 ) ;
} else {
V_69 = V_72 ;
V_68 = sizeof( V_9 ) ;
}
memset ( V_9 , 0 , sizeof( V_9 ) ) ;
V_67 = F_16 ( V_37 ) ? - V_58 : 0 ;
if ( V_67 )
goto error;
F_17 ( & V_37 -> V_59 ) ;
if ( V_37 -> V_60 ) {
V_67 = - V_73 ;
} else {
V_56 = F_18 ( V_37 ) | ( V_14 -> V_52 . V_8 << 8 ) ;
V_67 = F_19 ( V_37 -> V_38 , F_20 ( V_37 -> V_38 , 0 ) , V_69 ,
V_61 | V_62 | V_63 ,
V_49 , V_56 , V_9 , V_68 ) ;
}
F_23 ( & V_37 -> V_59 ) ;
F_24 ( V_37 ) ;
if ( V_67 < 0 ) {
error:
F_26 ( V_37 ,
L_1 ,
V_48 , V_49 , V_56 , V_14 -> V_40 ) ;
return V_67 ;
}
switch ( V_48 ) {
case V_70 :
V_39 = V_9 ;
break;
case V_74 :
V_39 = V_9 + sizeof( V_66 ) ;
break;
case V_75 :
V_39 = V_9 + sizeof( V_66 ) * 2 ;
break;
case V_76 :
V_39 = V_9 + sizeof( V_66 ) * 3 ;
break;
default:
return - V_65 ;
}
* V_50 = F_11 ( V_14 , F_21 ( V_39 , sizeof( V_66 ) ) ) ;
return 0 ;
}
static int F_27 ( struct V_13 * V_14 , int V_48 ,
int V_49 , int * V_50 )
{
V_49 += V_14 -> V_77 ;
return ( V_14 -> V_52 . V_53 -> V_78 == V_79 ) ?
F_15 ( V_14 , V_48 , V_49 , V_50 ) :
F_25 ( V_14 , V_48 , V_49 , V_50 ) ;
}
static int F_28 ( struct V_13 * V_14 ,
int V_49 , int * V_80 )
{
return F_27 ( V_14 , V_70 , V_49 , V_80 ) ;
}
static inline int F_29 ( struct V_13 * V_14 ,
int V_81 , int * V_80 )
{
return F_27 ( V_14 , V_70 ,
( V_14 -> V_5 << 8 ) | V_81 ,
V_80 ) ;
}
int F_30 ( struct V_13 * V_14 ,
int V_81 , int V_20 , int * V_80 )
{
int V_57 ;
if ( V_14 -> V_82 & ( 1 << V_81 ) ) {
* V_80 = V_14 -> V_83 [ V_20 ] ;
return 0 ;
}
V_57 = F_29 ( V_14 , V_81 , V_80 ) ;
if ( V_57 < 0 ) {
if ( ! V_14 -> V_52 . V_53 -> V_84 )
F_22 ( V_14 -> V_52 . V_53 -> V_37 ,
L_2 ,
V_14 -> V_5 , V_81 , V_57 ) ;
return V_57 ;
}
V_14 -> V_82 |= 1 << V_81 ;
V_14 -> V_83 [ V_20 ] = * V_80 ;
return 0 ;
}
int F_31 ( struct V_13 * V_14 ,
int V_48 , int V_49 , int V_85 )
{
struct V_51 * V_37 = V_14 -> V_52 . V_53 -> V_37 ;
unsigned char V_9 [ 2 ] ;
int V_56 = 0 , V_54 , V_57 , V_55 = 10 ;
V_49 += V_14 -> V_77 ;
if ( V_14 -> V_52 . V_53 -> V_78 == V_79 ) {
V_54 = V_14 -> V_40 >= V_46 ? 2 : 1 ;
} else {
V_54 = sizeof( V_66 ) ;
if ( V_48 != V_86 ) {
F_22 ( V_37 , L_3 ) ;
return - V_65 ;
}
V_48 = V_71 ;
}
V_85 = F_12 ( V_14 , V_85 ) ;
V_9 [ 0 ] = V_85 & 0xff ;
V_9 [ 1 ] = ( V_85 >> 8 ) & 0xff ;
V_57 = F_16 ( V_37 ) ;
if ( V_57 < 0 )
return - V_58 ;
F_17 ( & V_37 -> V_59 ) ;
while ( V_55 -- > 0 ) {
if ( V_37 -> V_60 )
break;
V_56 = F_18 ( V_37 ) | ( V_14 -> V_52 . V_8 << 8 ) ;
if ( F_19 ( V_37 -> V_38 ,
F_32 ( V_37 -> V_38 , 0 ) , V_48 ,
V_61 | V_62 | V_87 ,
V_49 , V_56 , V_9 , V_54 ) >= 0 ) {
V_57 = 0 ;
goto V_64;
}
}
F_22 ( V_37 , L_4 ,
V_48 , V_49 , V_56 , V_14 -> V_40 , V_9 [ 0 ] , V_9 [ 1 ] ) ;
V_57 = - V_65 ;
V_64:
F_23 ( & V_37 -> V_59 ) ;
F_24 ( V_37 ) ;
return V_57 ;
}
static int F_33 ( struct V_13 * V_14 ,
int V_49 , int V_80 )
{
return F_31 ( V_14 , V_86 , V_49 , V_80 ) ;
}
int F_34 ( struct V_13 * V_14 , int V_81 ,
int V_20 , int V_80 )
{
int V_57 ;
unsigned int V_88 = ( V_81 == 0 ) ?
V_14 -> V_89 :
V_14 -> V_90 & ( 1 << ( V_81 - 1 ) ) ;
if ( V_88 ) {
F_22 ( V_14 -> V_52 . V_53 -> V_37 ,
L_5 ,
V_91 , V_81 , V_14 -> V_5 ) ;
return 0 ;
}
V_57 = F_31 ( V_14 ,
V_86 , ( V_14 -> V_5 << 8 ) | V_81 ,
V_80 ) ;
if ( V_57 < 0 )
return V_57 ;
V_14 -> V_82 |= 1 << V_81 ;
V_14 -> V_83 [ V_20 ] = V_80 ;
return 0 ;
}
int F_35 ( struct V_92 * V_93 , int V_94 ,
unsigned int V_68 , unsigned int T_2 * V_95 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
F_36 ( V_97 , 0 , 0 ) ;
if ( V_68 < sizeof( V_97 ) )
return - V_98 ;
V_97 [ 2 ] = V_14 -> V_15 ;
V_97 [ 3 ] = V_14 -> V_17 ;
if ( F_37 ( V_95 , V_97 , sizeof( V_97 ) ) )
return - V_99 ;
return 0 ;
}
static int F_38 ( unsigned char * V_100 ,
int V_101 , int V_102 , int V_103 )
{
int V_56 = V_101 * V_103 + V_102 ;
return V_100 [ V_56 >> 3 ] & ( 0x80 >> ( V_56 & 7 ) ) ;
}
int F_39 ( struct V_104 * V_105 ,
struct V_92 * V_106 )
{
struct V_107 * V_53 = V_105 -> V_53 ;
int V_57 ;
while ( F_40 ( V_53 -> V_37 -> V_108 , & V_106 -> V_8 ) )
V_106 -> V_8 . V_20 ++ ;
if ( ( V_57 = F_41 ( V_53 -> V_37 -> V_108 , V_106 ) ) < 0 ) {
F_22 ( V_53 -> V_37 , L_6 ,
V_57 ) ;
return V_57 ;
}
V_105 -> V_106 = V_106 ;
V_105 -> V_109 = V_53 -> V_110 [ V_105 -> V_8 ] ;
V_53 -> V_110 [ V_105 -> V_8 ] = V_105 ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , struct V_111 * V_112 ,
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
static int F_43 ( struct V_2 * V_3 , int V_8 ,
struct V_111 * V_120 )
{
int V_57 ;
void * V_121 ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
while ( ( V_121 = F_7 ( V_3 , V_8 ) ) != NULL ) {
unsigned char * V_27 = V_121 ;
V_120 -> V_8 = V_8 ;
switch ( V_27 [ 2 ] ) {
case V_32 :
if ( V_3 -> V_53 -> V_78 == V_79 ) {
struct V_122 * V_123 = V_121 ;
V_120 -> type = F_44 ( V_123 -> V_124 ) ;
V_120 -> V_125 = V_123 -> V_126 ;
V_120 -> V_127 = F_44 ( V_123 -> V_128 ) ;
V_120 -> V_11 = V_123 -> V_129 ;
} else {
struct V_130 * V_123 = V_121 ;
V_120 -> type = F_44 ( V_123 -> V_124 ) ;
V_120 -> V_125 = V_123 -> V_126 ;
V_120 -> V_127 = F_45 ( V_123 -> V_131 ) ;
V_120 -> V_11 = V_123 -> V_129 ;
V_57 = F_43 ( V_3 , V_123 -> V_132 , V_120 ) ;
if ( V_57 < 0 )
return V_57 ;
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
V_120 -> V_125 = F_46 ( V_123 ) ;
V_120 -> V_127 = F_47 ( V_123 , V_3 -> V_53 -> V_78 ) ;
V_120 -> V_11 = F_48 ( V_123 ) ;
return 0 ;
}
case V_115 :
case V_136 : {
struct V_137 * V_123 = V_121 ;
V_57 = F_43 ( V_3 , V_123 -> V_138 [ 0 ] , V_120 ) ;
if ( V_57 < 0 )
return V_57 ;
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_8 = V_8 ;
V_120 -> V_11 = F_49 ( V_123 ) ;
return 0 ;
}
case V_116 :
case V_117 :
case V_139 : {
struct V_140 * V_123 = V_121 ;
if ( V_3 -> V_53 -> V_78 == V_141 &&
V_27 [ 2 ] == V_142 ) {
return 0 ;
}
if ( V_123 -> V_143 ) {
V_8 = V_123 -> V_138 [ 0 ] ;
break;
}
V_120 -> type = V_123 -> V_31 << 16 ;
V_120 -> V_125 = F_50 ( V_123 ) ;
V_120 -> V_127 = F_51 ( V_123 , V_3 -> V_53 -> V_78 ) ;
V_120 -> V_11 = F_52 ( V_123 , V_3 -> V_53 -> V_78 ) ;
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
return - V_73 ;
}
}
return - V_73 ;
}
void F_53 ( struct V_92 * V_106 )
{
F_54 ( V_106 -> V_96 ) ;
V_106 -> V_96 = NULL ;
}
static void F_55 ( struct V_13 * V_14 ,
struct V_92 * V_106 )
{
struct V_51 * V_37 = V_14 -> V_52 . V_53 -> V_37 ;
switch ( V_37 -> V_147 ) {
case F_56 ( 0x0763 , 0x2030 ) :
case F_56 ( 0x0763 , 0x2031 ) :
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
case F_56 ( 0x0763 , 0x2081 ) :
case F_56 ( 0x0763 , 0x2080 ) :
if ( strcmp ( V_106 -> V_8 . V_11 , L_16 ) == 0 ) {
F_57 ( V_37 ,
L_22 ) ;
V_14 -> V_16 = 0x0000 ;
V_14 -> V_18 = 0x7f00 ;
V_14 -> V_47 = 0x0100 ;
break;
}
if ( strcmp ( V_106 -> V_8 . V_11 , L_17 ) == 0 ||
strcmp ( V_106 -> V_8 . V_11 , L_18 ) == 0 ) {
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
if ( ! strcmp ( V_106 -> V_8 . V_11 , L_24 ) &&
V_14 -> V_16 == - 15616 ) {
F_57 ( V_37 ,
L_25 ) ;
V_14 -> V_18 = - 256 ;
}
break;
case F_56 ( 0x046d , 0x09a4 ) :
if ( ! strcmp ( V_106 -> V_8 . V_11 , L_26 ) ) {
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
case F_56 ( 0x046d , 0x0819 ) :
case F_56 ( 0x046d , 0x081b ) :
case F_56 ( 0x046d , 0x081d ) :
case F_56 ( 0x046d , 0x0825 ) :
case F_56 ( 0x046d , 0x0826 ) :
case F_56 ( 0x046d , 0x08ca ) :
case F_56 ( 0x046d , 0x0991 ) :
if ( ! strcmp ( V_106 -> V_8 . V_11 , L_26 ) ) {
F_57 ( V_37 ,
L_28 ) ;
V_14 -> V_47 = 384 ;
}
break;
}
}
static int F_58 ( struct V_13 * V_14 ,
int V_148 , struct V_92 * V_106 )
{
V_14 -> V_16 = V_148 ;
V_14 -> V_18 = V_14 -> V_16 + 1 ;
V_14 -> V_47 = 1 ;
V_14 -> V_15 = V_14 -> V_17 = 0 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_14 -> V_19 = 1 ;
} else {
int V_149 = 0 ;
if ( V_14 -> V_150 ) {
int V_151 ;
for ( V_151 = 0 ; V_151 < V_152 ; V_151 ++ )
if ( V_14 -> V_150 & ( 1 << V_151 ) ) {
V_149 = V_151 + 1 ;
break;
}
}
if ( F_27 ( V_14 , V_75 , ( V_14 -> V_5 << 8 ) | V_149 , & V_14 -> V_18 ) < 0 ||
F_27 ( V_14 , V_74 , ( V_14 -> V_5 << 8 ) | V_149 , & V_14 -> V_16 ) < 0 ) {
F_26 ( V_14 -> V_52 . V_53 -> V_37 ,
L_29 ,
V_14 -> V_52 . V_8 , F_18 ( V_14 -> V_52 . V_53 -> V_37 ) ,
V_14 -> V_5 , V_14 -> V_52 . V_8 ) ;
return - V_65 ;
}
if ( F_27 ( V_14 , V_76 ,
( V_14 -> V_5 << 8 ) | V_149 ,
& V_14 -> V_47 ) < 0 ) {
V_14 -> V_47 = 1 ;
} else {
int V_153 = V_14 -> V_47 ;
while ( V_14 -> V_47 > 1 ) {
if ( F_31 ( V_14 , V_154 ,
( V_14 -> V_5 << 8 ) | V_149 ,
V_14 -> V_47 / 2 ) < 0 )
break;
V_14 -> V_47 /= 2 ;
}
if ( F_27 ( V_14 , V_76 ,
( V_14 -> V_5 << 8 ) | V_149 , & V_14 -> V_47 ) < 0 )
V_14 -> V_47 = V_153 ;
}
if ( V_14 -> V_47 == 0 )
V_14 -> V_47 = 1 ;
if ( V_14 -> V_16 + V_14 -> V_47 < V_14 -> V_18 ) {
int V_153 = V_14 -> V_47 ;
int V_155 , V_156 , V_157 ;
F_29 ( V_14 , V_149 , & V_155 ) ;
for (; ; ) {
V_156 = V_155 ;
if ( V_156 < V_14 -> V_18 )
V_156 += V_14 -> V_47 ;
else
V_156 -= V_14 -> V_47 ;
if ( V_156 < V_14 -> V_16 || V_156 > V_14 -> V_18 ||
F_34 ( V_14 , V_149 , 0 , V_156 ) ||
F_29 ( V_14 , V_149 , & V_157 ) ) {
V_14 -> V_47 = V_153 ;
break;
}
if ( V_156 == V_157 )
break;
V_14 -> V_47 *= 2 ;
}
F_34 ( V_14 , V_149 , 0 , V_155 ) ;
}
V_14 -> V_19 = 1 ;
}
if ( V_106 )
F_55 ( V_14 , V_106 ) ;
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
static int F_59 ( struct V_92 * V_93 ,
struct V_158 * V_159 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 )
V_159 -> type = V_160 ;
else
V_159 -> type = V_161 ;
V_159 -> V_23 = V_14 -> V_125 ;
if ( V_14 -> V_40 == V_41 ||
V_14 -> V_40 == V_42 ) {
V_159 -> V_80 . integer . V_16 = 0 ;
V_159 -> V_80 . integer . V_18 = 1 ;
} else {
if ( ! V_14 -> V_19 ) {
F_58 ( V_14 , 0 , V_93 ) ;
if ( V_14 -> V_19 && V_14 -> V_15 >= V_14 -> V_17 ) {
V_93 -> V_162 [ 0 ] . V_163 &=
~ ( V_164 |
V_165 ) ;
F_60 ( V_14 -> V_52 . V_53 -> V_37 -> V_108 ,
V_166 ,
& V_93 -> V_8 ) ;
}
}
V_159 -> V_80 . integer . V_16 = 0 ;
V_159 -> V_80 . integer . V_18 =
( V_14 -> V_18 - V_14 -> V_16 + V_14 -> V_47 - 1 ) / V_14 -> V_47 ;
}
return 0 ;
}
static int F_61 ( struct V_92 * V_93 ,
struct V_167 * V_168 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_169 , V_170 , V_39 , V_57 ;
V_168 -> V_80 . integer . V_80 [ 0 ] = V_14 -> V_16 ;
if ( V_14 -> V_150 ) {
V_170 = 0 ;
for ( V_169 = 0 ; V_169 < V_152 ; V_169 ++ ) {
if ( ! ( V_14 -> V_150 & ( 1 << V_169 ) ) )
continue;
V_57 = F_30 ( V_14 , V_169 + 1 , V_170 , & V_39 ) ;
if ( V_57 < 0 )
return F_62 ( V_14 , V_57 ) ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_168 -> V_80 . integer . V_80 [ V_170 ] = V_39 ;
V_170 ++ ;
}
return 0 ;
} else {
V_57 = F_30 ( V_14 , 0 , 0 , & V_39 ) ;
if ( V_57 < 0 )
return F_62 ( V_14 , V_57 ) ;
V_39 = F_13 ( V_14 , V_39 ) ;
V_168 -> V_80 . integer . V_80 [ 0 ] = V_39 ;
}
return 0 ;
}
static int F_63 ( struct V_92 * V_93 ,
struct V_167 * V_168 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_169 , V_170 , V_39 , V_171 , V_57 ;
int V_172 = 0 ;
if ( V_14 -> V_150 ) {
V_170 = 0 ;
for ( V_169 = 0 ; V_169 < V_152 ; V_169 ++ ) {
if ( ! ( V_14 -> V_150 & ( 1 << V_169 ) ) )
continue;
V_57 = F_30 ( V_14 , V_169 + 1 , V_170 , & V_171 ) ;
if ( V_57 < 0 )
return F_62 ( V_14 , V_57 ) ;
V_39 = V_168 -> V_80 . integer . V_80 [ V_170 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_171 != V_39 ) {
F_34 ( V_14 , V_169 + 1 , V_170 , V_39 ) ;
V_172 = 1 ;
}
V_170 ++ ;
}
} else {
V_57 = F_30 ( V_14 , 0 , 0 , & V_171 ) ;
if ( V_57 < 0 )
return F_62 ( V_14 , V_57 ) ;
V_39 = V_168 -> V_80 . integer . V_80 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_171 ) {
F_34 ( V_14 , 0 , 0 , V_39 ) ;
V_172 = 1 ;
}
}
return V_172 ;
}
static T_3 F_64 ( struct V_92 * V_106 , const char * V_173 )
{
return F_65 ( V_106 -> V_8 . V_11 , V_173 , sizeof( V_106 -> V_8 . V_11 ) ) ;
}
static void F_66 ( struct V_92 * V_106 ,
struct V_174 * V_108 )
{
const char * V_175 [] = {
L_14 , L_30 , L_31 , L_32 , NULL } ;
const char * * V_176 ;
bool V_177 = false ;
if ( strcmp ( L_33 , V_106 -> V_8 . V_11 ) )
return;
for ( V_176 = V_175 ; * V_176 ; V_176 ++ )
if ( strstr ( V_108 -> V_178 , * V_176 ) ) {
V_177 = true ;
break;
}
if ( ! V_177 )
return;
F_3 ( V_106 -> V_8 . V_11 , L_31 , sizeof( V_106 -> V_8 . V_11 ) ) ;
}
static void F_67 ( struct V_2 * V_3 , void * V_179 ,
unsigned int V_180 , int V_5 ,
struct V_111 * V_112 , int V_4 ,
int V_181 )
{
struct V_26 * V_182 = V_179 ;
unsigned int V_36 = 0 ;
int V_183 = 0 ;
int V_184 = F_68 ( V_182 ) ;
struct V_92 * V_106 ;
struct V_13 * V_14 ;
const struct V_1 * V_7 ;
unsigned int V_185 ;
V_5 ++ ;
if ( V_5 == V_186 ) {
return;
}
V_7 = F_1 ( V_3 , V_4 , V_5 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_69 ( sizeof( * V_14 ) , V_187 ) ;
if ( ! V_14 )
return;
F_70 ( & V_14 -> V_52 , V_3 -> V_53 , V_4 ) ;
V_14 -> V_5 = V_5 ;
V_14 -> V_150 = V_180 ;
V_14 -> V_40 = V_188 [ V_5 - 1 ] . type ;
if ( V_180 == 0 ) {
V_14 -> V_125 = 1 ;
V_14 -> V_89 = V_181 ;
} else {
int V_151 , V_169 = 0 ;
for ( V_151 = 0 ; V_151 < 16 ; V_151 ++ )
if ( V_180 & ( 1 << V_151 ) )
V_169 ++ ;
V_14 -> V_125 = V_169 ;
V_14 -> V_90 = V_181 ;
}
if ( V_14 -> V_125 == V_181 )
V_106 = F_71 ( & V_189 , V_14 ) ;
else
V_106 = F_71 ( & V_190 , V_14 ) ;
if ( ! V_106 ) {
F_26 ( V_3 -> V_37 , L_34 ) ;
F_54 ( V_14 ) ;
return;
}
V_106 -> V_191 = F_53 ;
V_36 = F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
V_183 = V_36 != 0 ;
if ( ! V_36 && V_184 )
V_36 = F_9 ( V_3 , V_184 ,
V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
switch ( V_5 ) {
case V_192 :
case V_193 :
if ( ! V_36 ) {
V_36 = F_42 ( V_3 , V_112 , V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
V_36 = F_42 ( V_3 , & V_3 -> V_194 ,
V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) , 1 ) ;
if ( ! V_36 )
snprintf ( V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ,
L_35 , V_4 ) ;
}
if ( ! V_183 )
F_66 ( V_106 , V_3 -> V_53 -> V_37 -> V_108 ) ;
if ( ! V_183 && ! ( V_3 -> V_194 . type >> 16 ) ) {
if ( ( V_3 -> V_194 . type & 0xff00 ) == 0x0100 )
F_64 ( V_106 , L_36 ) ;
else
F_64 ( V_106 , L_37 ) ;
}
F_64 ( V_106 , V_5 == V_192 ?
L_38 : L_39 ) ;
break;
default:
if ( ! V_36 )
F_3 ( V_106 -> V_8 . V_11 , V_188 [ V_5 - 1 ] . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) ) ;
break;
}
F_58 ( V_14 , 0 , V_106 ) ;
if ( V_5 == V_193 ) {
F_5 ( V_7 , V_14 ) ;
if ( V_14 -> V_15 < V_14 -> V_17 || ! V_14 -> V_19 ) {
V_106 -> V_195 . V_169 = F_35 ;
V_106 -> V_162 [ 0 ] . V_163 |=
V_164 |
V_165 ;
}
}
V_185 = ( V_14 -> V_18 - V_14 -> V_16 ) / V_14 -> V_47 ;
if ( V_185 > 384 ) {
F_72 ( V_3 -> V_37 ,
L_40 ,
V_185 ) ;
F_72 ( V_3 -> V_37 ,
L_41 ,
V_14 -> V_52 . V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
}
F_22 ( V_3 -> V_37 , L_42 ,
V_14 -> V_52 . V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_47 ) ;
F_39 ( & V_14 -> V_52 , V_106 ) ;
}
static int F_73 ( struct V_2 * V_3 , int V_4 ,
void * V_196 )
{
int V_125 , V_151 , V_197 ;
struct V_111 V_112 ;
unsigned int V_198 , V_199 ;
int V_57 , V_200 ;
struct V_26 * V_27 = V_196 ;
T_1 * V_201 ;
if ( V_3 -> V_53 -> V_78 == V_79 ) {
V_200 = V_27 -> V_202 ;
if ( ! V_200 ) {
F_22 ( V_3 -> V_37 ,
L_43 ,
V_4 ) ;
return - V_65 ;
}
V_125 = ( V_27 -> V_30 - 7 ) / V_200 - 1 ;
V_201 = V_27 -> V_201 ;
if ( V_27 -> V_30 < 7 + V_200 ) {
F_26 ( V_3 -> V_37 ,
L_44 ,
V_4 ) ;
return - V_65 ;
}
} else {
struct V_203 * V_204 = V_196 ;
V_200 = 4 ;
V_125 = ( V_27 -> V_30 - 6 ) / 4 - 1 ;
V_201 = V_204 -> V_201 ;
if ( V_27 -> V_30 < 6 + V_200 ) {
F_26 ( V_3 -> V_37 ,
L_44 ,
V_4 ) ;
return - V_65 ;
}
}
if ( ( V_57 = F_74 ( V_3 , V_27 -> V_134 ) ) < 0 )
return V_57 ;
V_57 = F_43 ( V_3 , V_27 -> V_134 , & V_112 ) ;
if ( V_57 < 0 )
return V_57 ;
V_198 = F_21 ( V_201 , V_200 ) ;
switch ( V_3 -> V_37 -> V_147 ) {
case F_56 ( 0x08bb , 0x2702 ) :
F_57 ( V_3 -> V_37 ,
L_45 ) ;
V_198 &= ~ F_75 ( V_193 ) ;
break;
case F_56 ( 0x1130 , 0xf211 ) :
F_57 ( V_3 -> V_37 ,
L_46 ) ;
V_125 = 0 ;
break;
}
if ( V_125 > 0 )
V_199 = F_21 ( V_201 + V_200 , V_200 ) ;
else
V_199 = 0 ;
if ( V_3 -> V_53 -> V_78 == V_79 ) {
for ( V_151 = 0 ; V_151 < 10 ; V_151 ++ ) {
unsigned int V_205 = 0 ;
for ( V_197 = 0 ; V_197 < V_125 ; V_197 ++ ) {
unsigned int V_206 ;
V_206 = F_21 ( V_201 +
V_200 * ( V_197 + 1 ) , V_200 ) ;
if ( V_206 & ( 1 << V_151 ) )
V_205 |= ( 1 << V_197 ) ;
}
if ( V_205 & 1 )
F_67 ( V_3 , V_196 , V_205 , V_151 ,
& V_112 , V_4 , 0 ) ;
if ( V_198 & ( 1 << V_151 ) )
F_67 ( V_3 , V_196 , 0 , V_151 , & V_112 ,
V_4 , 0 ) ;
}
} else {
for ( V_151 = 0 ; V_151 < F_76 ( V_188 ) ; V_151 ++ ) {
unsigned int V_205 = 0 ;
unsigned int V_207 = 0 ;
for ( V_197 = 0 ; V_197 < V_125 ; V_197 ++ ) {
unsigned int V_206 ;
V_206 = F_21 ( V_201 +
V_200 * ( V_197 + 1 ) , V_200 ) ;
if ( F_77 ( V_206 , V_151 ) ) {
V_205 |= ( 1 << V_197 ) ;
if ( ! F_78 ( V_206 , V_151 ) )
V_207 |= ( 1 << V_197 ) ;
}
}
if ( V_205 & 1 )
F_67 ( V_3 , V_196 , V_205 , V_151 ,
& V_112 , V_4 , V_207 ) ;
if ( F_77 ( V_198 , V_151 ) )
F_67 ( V_3 , V_196 , 0 , V_151 , & V_112 , V_4 ,
! F_78 ( V_198 , V_151 ) ) ;
}
}
return 0 ;
}
static void F_79 ( struct V_2 * V_3 ,
struct V_135 * V_182 ,
int V_208 , int V_209 , int V_4 ,
struct V_111 * V_112 )
{
struct V_13 * V_14 ;
unsigned int V_103 = F_46 ( V_182 ) ;
unsigned int V_151 , V_36 ;
struct V_92 * V_106 ;
const struct V_1 * V_7 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return;
V_14 = F_69 ( sizeof( * V_14 ) , V_187 ) ;
if ( ! V_14 )
return;
F_70 ( & V_14 -> V_52 , V_3 -> V_53 , V_4 ) ;
V_14 -> V_5 = V_209 + 1 ;
V_14 -> V_40 = V_46 ;
for ( V_151 = 0 ; V_151 < V_103 ; V_151 ++ ) {
T_1 * V_169 = F_80 ( V_182 , V_3 -> V_53 -> V_78 ) ;
if ( F_38 ( V_169 , V_209 , V_151 , V_103 ) ) {
V_14 -> V_150 |= ( 1 << V_151 ) ;
V_14 -> V_125 ++ ;
}
}
F_81 ( V_14 , 0 ) ;
V_106 = F_71 ( & V_190 , V_14 ) ;
if ( ! V_106 ) {
F_26 ( V_3 -> V_37 , L_34 ) ;
F_54 ( V_14 ) ;
return;
}
V_106 -> V_191 = F_53 ;
V_36 = F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
V_36 = F_42 ( V_3 , V_112 , V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
V_36 = sprintf ( V_106 -> V_8 . V_11 , L_47 , V_209 + 1 ) ;
F_64 ( V_106 , L_39 ) ;
F_22 ( V_3 -> V_37 , L_48 ,
V_14 -> V_52 . V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 , V_14 -> V_16 , V_14 -> V_18 ) ;
F_39 ( & V_14 -> V_52 , V_106 ) ;
}
static int F_82 ( struct V_2 * V_3 , int V_4 ,
void * V_179 )
{
struct V_135 * V_182 = V_179 ;
struct V_111 V_112 ;
int V_210 , V_211 , V_103 ;
int V_212 , V_101 , V_57 ;
if ( V_182 -> V_30 < 11 || ! ( V_210 = V_182 -> V_143 ) ||
! ( V_103 = F_46 ( V_182 ) ) ) {
F_26 ( V_3 -> V_37 ,
L_49 ,
V_4 ) ;
return - V_65 ;
}
V_211 = 0 ;
V_101 = 0 ;
for ( V_212 = 0 ; V_212 < V_210 ; V_212 ++ ) {
V_57 = F_74 ( V_3 , V_182 -> V_138 [ V_212 ] ) ;
if ( V_57 < 0 )
continue;
if ( V_182 -> V_30 <= 10 + V_210 )
continue;
V_57 = F_43 ( V_3 , V_182 -> V_138 [ V_212 ] , & V_112 ) ;
if ( V_57 < 0 )
return V_57 ;
V_211 += V_112 . V_125 ;
for (; V_101 < V_211 ; V_101 ++ ) {
int V_102 , V_213 = 0 ;
for ( V_102 = 0 ; V_102 < V_103 ; V_102 ++ ) {
T_1 * V_169 = F_80 ( V_182 ,
V_3 -> V_53 -> V_78 ) ;
if ( F_38 ( V_169 , V_101 , V_102 , V_103 ) ) {
V_213 = 1 ;
break;
}
}
if ( V_213 )
F_79 ( V_3 , V_182 , V_212 , V_101 ,
V_4 , & V_112 ) ;
}
}
return 0 ;
}
static int F_83 ( struct V_92 * V_93 ,
struct V_167 * V_168 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_57 , V_39 ;
V_57 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_57 < 0 ) {
V_168 -> V_80 . integer . V_80 [ 0 ] = V_14 -> V_16 ;
return F_62 ( V_14 , V_57 ) ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_168 -> V_80 . integer . V_80 [ 0 ] = V_39 ;
return 0 ;
}
static int F_84 ( struct V_92 * V_93 ,
struct V_167 * V_168 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_39 , V_171 , V_57 ;
V_57 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_171 ) ;
if ( V_57 < 0 )
return F_62 ( V_14 , V_57 ) ;
V_39 = V_168 -> V_80 . integer . V_80 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_171 ) {
F_33 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static int F_85 ( struct V_2 * V_3 , int V_4 ,
void * V_179 , struct V_214 * V_105 ,
char * V_11 )
{
struct V_140 * V_182 = V_179 ;
int V_211 = V_182 -> V_143 ;
struct V_13 * V_14 ;
struct V_92 * V_106 ;
int V_151 , V_57 , V_184 , type , V_36 ;
struct V_214 * V_215 ;
struct V_216 * V_217 ;
const struct V_1 * V_7 ;
static struct V_216 V_218 [] = {
{ 0x01 , L_50 , V_41 } ,
{ 0 }
} ;
static struct V_214 V_219 = {
0 , NULL , V_218
} ;
if ( V_182 -> V_30 < 13 || V_182 -> V_30 < 13 + V_211 ||
V_182 -> V_30 < V_211 + F_86 ( V_182 , V_3 -> V_53 -> V_78 ) ) {
F_26 ( V_3 -> V_37 , L_51 , V_11 , V_4 ) ;
return - V_65 ;
}
for ( V_151 = 0 ; V_151 < V_211 ; V_151 ++ ) {
if ( ( V_57 = F_74 ( V_3 , V_182 -> V_138 [ V_151 ] ) ) < 0 )
return V_57 ;
}
type = F_44 ( V_182 -> V_220 ) ;
for ( V_215 = V_105 ; V_215 && V_215 -> type ; V_215 ++ )
if ( V_215 -> type == type )
break;
if ( ! V_215 || ! V_215 -> type )
V_215 = & V_219 ;
for ( V_217 = V_215 -> V_221 ; V_217 -> V_5 ; V_217 ++ ) {
T_1 * V_222 = F_87 ( V_182 , V_3 -> V_53 -> V_78 ) ;
if ( ! ( V_222 [ V_217 -> V_5 / 8 ] & ( 1 << ( ( V_217 -> V_5 % 8 ) - 1 ) ) ) )
continue;
V_7 = F_1 ( V_3 , V_4 , V_217 -> V_5 ) ;
if ( F_4 ( V_7 ) )
continue;
V_14 = F_69 ( sizeof( * V_14 ) , V_187 ) ;
if ( ! V_14 )
return - V_98 ;
F_70 ( & V_14 -> V_52 , V_3 -> V_53 , V_4 ) ;
V_14 -> V_5 = V_217 -> V_5 ;
V_14 -> V_40 = V_217 -> V_40 ;
V_14 -> V_125 = 1 ;
if ( type == V_223 && V_14 -> V_5 == V_224 ) {
T_1 * V_225 = F_88 ( V_182 , V_3 -> V_53 -> V_78 ) ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_225 [ 0 ] ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else {
if ( type == V_226 ) {
V_14 -> V_16 = 0 ;
V_14 -> V_18 = 5 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
} else
F_81 ( V_14 , V_217 -> V_227 ) ;
}
V_106 = F_71 ( & V_228 , V_14 ) ;
if ( ! V_106 ) {
F_54 ( V_14 ) ;
return - V_98 ;
}
V_106 -> V_191 = F_53 ;
if ( F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ) {
;
} else if ( V_215 -> V_11 ) {
F_3 ( V_106 -> V_8 . V_11 , V_215 -> V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
} else {
V_184 = F_52 ( V_182 , V_3 -> V_53 -> V_78 ) ;
V_36 = 0 ;
if ( V_184 )
V_36 = F_9 ( V_3 , V_184 ,
V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( ! V_36 )
F_3 ( V_106 -> V_8 . V_11 , V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
}
F_64 ( V_106 , L_52 ) ;
F_64 ( V_106 , V_217 -> V_229 ) ;
F_22 ( V_3 -> V_37 ,
L_53 ,
V_14 -> V_52 . V_8 , V_106 -> V_8 . V_11 , V_14 -> V_125 ,
V_14 -> V_16 , V_14 -> V_18 ) ;
V_57 = F_39 ( & V_14 -> V_52 , V_106 ) ;
if ( V_57 < 0 )
return V_57 ;
}
return 0 ;
}
static int F_89 ( struct V_2 * V_3 , int V_4 ,
void * V_179 )
{
return F_85 ( V_3 , V_4 , V_179 ,
V_230 , L_54 ) ;
}
static int F_90 ( struct V_2 * V_3 , int V_4 ,
void * V_179 )
{
return F_85 ( V_3 , V_4 , V_179 ,
V_231 , L_55 ) ;
}
static int F_91 ( struct V_92 * V_93 ,
struct V_158 * V_159 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
const char * * V_232 = ( const char * * ) V_93 -> V_233 ;
if ( F_92 ( ! V_232 ) )
return - V_65 ;
return F_93 ( V_159 , 1 , V_14 -> V_18 , V_232 ) ;
}
static int F_94 ( struct V_92 * V_93 ,
struct V_167 * V_168 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_39 , V_57 ;
V_57 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_39 ) ;
if ( V_57 < 0 ) {
V_168 -> V_80 . V_234 . V_235 [ 0 ] = 0 ;
return F_62 ( V_14 , V_57 ) ;
}
V_39 = F_13 ( V_14 , V_39 ) ;
V_168 -> V_80 . V_234 . V_235 [ 0 ] = V_39 ;
return 0 ;
}
static int F_95 ( struct V_92 * V_93 ,
struct V_167 * V_168 )
{
struct V_13 * V_14 = V_93 -> V_96 ;
int V_39 , V_171 , V_57 ;
V_57 = F_28 ( V_14 , V_14 -> V_5 << 8 , & V_171 ) ;
if ( V_57 < 0 )
return F_62 ( V_14 , V_57 ) ;
V_39 = V_168 -> V_80 . V_234 . V_235 [ 0 ] ;
V_39 = F_14 ( V_14 , V_39 ) ;
if ( V_39 != V_171 ) {
F_33 ( V_14 , V_14 -> V_5 << 8 , V_39 ) ;
return 1 ;
}
return 0 ;
}
static void F_96 ( struct V_92 * V_106 )
{
int V_151 , V_211 = 0 ;
if ( V_106 -> V_96 ) {
struct V_13 * V_14 = V_106 -> V_96 ;
V_211 = V_14 -> V_18 ;
F_54 ( V_14 ) ;
V_106 -> V_96 = NULL ;
}
if ( V_106 -> V_233 ) {
char * * V_232 = ( char * * ) V_106 -> V_233 ;
for ( V_151 = 0 ; V_151 < V_211 ; V_151 ++ )
F_54 ( V_232 [ V_151 ] ) ;
F_54 ( V_232 ) ;
V_106 -> V_233 = 0 ;
}
}
static int F_97 ( struct V_2 * V_3 , int V_4 ,
void * V_179 )
{
struct V_137 * V_182 = V_179 ;
unsigned int V_151 , V_184 , V_36 ;
int V_57 ;
struct V_13 * V_14 ;
struct V_92 * V_106 ;
const struct V_1 * V_7 ;
char * * V_236 ;
if ( ! V_182 -> V_143 || V_182 -> V_30 < 5 + V_182 -> V_143 ) {
F_26 ( V_3 -> V_37 ,
L_56 , V_4 ) ;
return - V_65 ;
}
for ( V_151 = 0 ; V_151 < V_182 -> V_143 ; V_151 ++ ) {
if ( ( V_57 = F_74 ( V_3 , V_182 -> V_138 [ V_151 ] ) ) < 0 )
return V_57 ;
}
if ( V_182 -> V_143 == 1 )
return 0 ;
V_7 = F_1 ( V_3 , V_4 , 0 ) ;
if ( F_4 ( V_7 ) )
return 0 ;
V_14 = F_69 ( sizeof( * V_14 ) , V_187 ) ;
if ( ! V_14 )
return - V_98 ;
F_70 ( & V_14 -> V_52 , V_3 -> V_53 , V_4 ) ;
V_14 -> V_40 = V_43 ;
V_14 -> V_125 = 1 ;
V_14 -> V_16 = 1 ;
V_14 -> V_18 = V_182 -> V_143 ;
V_14 -> V_47 = 1 ;
V_14 -> V_19 = 1 ;
if ( V_3 -> V_53 -> V_78 == V_79 )
V_14 -> V_5 = 0 ;
else
V_14 -> V_5 = ( V_182 -> V_31 == V_136 ) ?
V_237 : V_238 ;
V_236 = F_98 ( sizeof( char * ) * V_182 -> V_143 , V_187 ) ;
if ( ! V_236 ) {
F_54 ( V_14 ) ;
return - V_98 ;
}
#define F_99 64
for ( V_151 = 0 ; V_151 < V_182 -> V_143 ; V_151 ++ ) {
struct V_111 V_112 ;
V_36 = 0 ;
V_236 [ V_151 ] = F_98 ( F_99 , V_187 ) ;
if ( ! V_236 [ V_151 ] ) {
while ( V_151 -- )
F_54 ( V_236 [ V_151 ] ) ;
F_54 ( V_236 ) ;
F_54 ( V_14 ) ;
return - V_98 ;
}
V_36 = F_6 ( V_3 , V_4 , V_151 , V_236 [ V_151 ] ,
F_99 ) ;
if ( ! V_36 && F_43 ( V_3 , V_182 -> V_138 [ V_151 ] , & V_112 ) >= 0 )
V_36 = F_42 ( V_3 , & V_112 , V_236 [ V_151 ] , F_99 , 0 ) ;
if ( ! V_36 )
sprintf ( V_236 [ V_151 ] , L_57 , V_151 ) ;
}
V_106 = F_71 ( & V_239 , V_14 ) ;
if ( ! V_106 ) {
F_26 ( V_3 -> V_37 , L_34 ) ;
F_54 ( V_236 ) ;
F_54 ( V_14 ) ;
return - V_98 ;
}
V_106 -> V_233 = ( unsigned long ) V_236 ;
V_106 -> V_191 = F_96 ;
V_184 = F_49 ( V_182 ) ;
V_36 = F_2 ( V_7 , V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( V_36 )
;
else if ( V_184 )
F_9 ( V_3 , V_184 , V_106 -> V_8 . V_11 ,
sizeof( V_106 -> V_8 . V_11 ) ) ;
else {
V_36 = F_42 ( V_3 , & V_3 -> V_194 ,
V_106 -> V_8 . V_11 , sizeof( V_106 -> V_8 . V_11 ) , 0 ) ;
if ( ! V_36 )
F_3 ( V_106 -> V_8 . V_11 , L_58 , sizeof( V_106 -> V_8 . V_11 ) ) ;
if ( V_182 -> V_31 == V_136 )
F_64 ( V_106 , L_59 ) ;
else if ( ( V_3 -> V_194 . type & 0xff00 ) == 0x0100 )
F_64 ( V_106 , L_60 ) ;
else
F_64 ( V_106 , L_61 ) ;
}
F_22 ( V_3 -> V_37 , L_62 ,
V_14 -> V_52 . V_8 , V_106 -> V_8 . V_11 , V_182 -> V_143 ) ;
return F_39 ( & V_14 -> V_52 , V_106 ) ;
}
static int F_74 ( struct V_2 * V_3 , int V_4 )
{
unsigned char * V_121 ;
if ( F_100 ( V_4 , V_3 -> V_240 ) )
return 0 ;
V_121 = F_7 ( V_3 , V_4 ) ;
if ( ! V_121 ) {
F_26 ( V_3 -> V_37 , L_63 , V_4 ) ;
return - V_65 ;
}
switch ( V_121 [ 2 ] ) {
case V_32 :
case V_144 :
return 0 ;
case V_118 :
return F_82 ( V_3 , V_4 , V_121 ) ;
case V_115 :
case V_136 :
return F_97 ( V_3 , V_4 , V_121 ) ;
case V_133 :
return F_73 ( V_3 , V_4 , V_121 ) ;
case V_116 :
if ( V_3 -> V_53 -> V_78 == V_79 )
return F_89 ( V_3 , V_4 , V_121 ) ;
else
return 0 ;
case V_117 :
if ( V_3 -> V_53 -> V_78 == V_79 )
return F_90 ( V_3 , V_4 , V_121 ) ;
else
return F_89 ( V_3 , V_4 , V_121 ) ;
case V_139 :
return F_90 ( V_3 , V_4 , V_121 ) ;
default:
F_26 ( V_3 -> V_37 ,
L_64 , V_4 , V_121 [ 2 ] ) ;
return - V_65 ;
}
}
static void F_101 ( struct V_107 * V_53 )
{
F_54 ( V_53 -> V_110 ) ;
if ( V_53 -> V_241 ) {
F_54 ( V_53 -> V_241 -> V_242 ) ;
F_102 ( V_53 -> V_241 ) ;
}
F_102 ( V_53 -> V_243 ) ;
F_54 ( V_53 -> V_244 ) ;
F_54 ( V_53 ) ;
}
static int F_103 ( struct V_245 * V_246 )
{
struct V_107 * V_53 = V_246 -> V_247 ;
F_101 ( V_53 ) ;
return 0 ;
}
static int F_104 ( struct V_107 * V_53 )
{
struct V_2 V_3 ;
int V_57 ;
const struct V_248 * V_7 ;
void * V_6 ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_37 = V_53 -> V_37 ;
V_3 . V_53 = V_53 ;
V_3 . V_28 = V_53 -> V_249 -> V_250 ;
V_3 . V_10 = V_53 -> V_249 -> V_251 ;
for ( V_7 = V_252 ; V_7 -> V_8 ; V_7 ++ ) {
if ( V_7 -> V_8 == V_3 . V_37 -> V_147 ) {
V_3 . V_7 = V_7 -> V_7 ;
V_3 . V_22 = V_7 -> V_22 ;
V_53 -> V_84 = V_7 -> V_84 ;
break;
}
}
V_6 = NULL ;
while ( ( V_6 = F_105 ( V_53 -> V_249 -> V_250 ,
V_53 -> V_249 -> V_251 ,
V_6 , V_253 ) ) != NULL ) {
if ( V_53 -> V_78 == V_79 ) {
struct V_254 * V_182 = V_6 ;
if ( V_182 -> V_30 < sizeof( * V_182 ) )
continue;
F_106 ( V_182 -> V_255 , V_3 . V_240 ) ;
V_3 . V_194 . V_8 = V_182 -> V_255 ;
V_3 . V_194 . type = F_44 ( V_182 -> V_124 ) ;
V_3 . V_194 . V_11 = V_182 -> V_129 ;
V_57 = F_74 ( & V_3 , V_182 -> V_134 ) ;
if ( V_57 < 0 && V_57 != - V_65 )
return V_57 ;
} else {
struct V_256 * V_182 = V_6 ;
if ( V_182 -> V_30 < sizeof( * V_182 ) )
continue;
F_106 ( V_182 -> V_255 , V_3 . V_240 ) ;
V_3 . V_194 . V_8 = V_182 -> V_255 ;
V_3 . V_194 . type = F_44 ( V_182 -> V_124 ) ;
V_3 . V_194 . V_11 = V_182 -> V_129 ;
V_57 = F_74 ( & V_3 , V_182 -> V_134 ) ;
if ( V_57 < 0 && V_57 != - V_65 )
return V_57 ;
V_57 = F_74 ( & V_3 , V_182 -> V_132 ) ;
if ( V_57 < 0 && V_57 != - V_65 )
return V_57 ;
}
}
return 0 ;
}
void F_107 ( struct V_107 * V_53 , int V_4 )
{
struct V_104 * V_105 ;
for ( V_105 = V_53 -> V_110 [ V_4 ] ; V_105 ; V_105 = V_105 -> V_109 )
F_60 ( V_53 -> V_37 -> V_108 , V_257 ,
& V_105 -> V_106 -> V_8 ) ;
}
static void F_108 ( struct V_258 * V_28 ,
struct V_104 * V_105 )
{
struct V_13 * V_14 = (struct V_13 * ) V_105 ;
static char * V_259 [] = { L_65 , L_66 ,
L_67 , L_68 , L_69 , L_70 } ;
F_109 ( V_28 , L_71
L_72 , V_14 -> V_52 . V_8 ,
V_14 -> V_5 , V_14 -> V_150 , V_14 -> V_125 ,
V_259 [ V_14 -> V_40 ] ) ;
F_109 ( V_28 , L_73 ,
V_14 -> V_16 , V_14 -> V_18 , V_14 -> V_15 , V_14 -> V_17 ) ;
}
static void F_110 ( struct V_260 * V_261 ,
struct V_258 * V_28 )
{
struct V_51 * V_37 = V_261 -> V_96 ;
struct V_107 * V_53 ;
struct V_104 * V_105 ;
int V_4 ;
F_111 (mixer, &chip->mixer_list, list) {
F_109 ( V_28 ,
L_74 ,
V_37 -> V_147 , F_18 ( V_37 ) ,
V_53 -> V_84 ) ;
F_109 ( V_28 , L_75 , V_37 -> V_108 -> V_262 ) ;
for ( V_4 = 0 ; V_4 < V_263 ; V_4 ++ ) {
for ( V_105 = V_53 -> V_110 [ V_4 ] ; V_105 ;
V_105 = V_105 -> V_109 ) {
F_109 ( V_28 , L_76 , V_105 -> V_8 ) ;
if ( V_105 -> V_106 )
F_109 ( V_28 ,
L_77 ,
V_105 -> V_106 -> V_8 . V_11 ,
V_105 -> V_106 -> V_8 . V_20 ) ;
if ( V_105 -> V_264 )
V_105 -> V_264 ( V_28 , V_105 ) ;
}
}
}
}
static void F_112 ( struct V_107 * V_53 ,
int V_265 , int V_80 , int V_20 )
{
struct V_104 * V_105 ;
T_1 V_4 = ( V_20 >> 8 ) & 0xff ;
T_1 V_5 = ( V_80 >> 8 ) & 0xff ;
T_1 V_81 = V_80 & 0xff ;
if ( V_81 >= V_152 ) {
F_22 ( V_53 -> V_37 ,
L_78 ,
V_91 , V_81 ) ;
return;
}
for ( V_105 = V_53 -> V_110 [ V_4 ] ; V_105 ; V_105 = V_105 -> V_109 ) {
struct V_13 * V_215 ;
if ( ! V_105 -> V_106 )
continue;
V_215 = (struct V_13 * ) V_105 ;
if ( V_215 -> V_5 != V_5 )
continue;
switch ( V_265 ) {
case V_71 :
if ( V_81 )
V_215 -> V_82 &= ~ ( 1 << V_81 ) ;
else
V_215 -> V_82 = 0 ;
F_60 ( V_53 -> V_37 -> V_108 , V_257 ,
& V_215 -> V_52 . V_106 -> V_8 ) ;
break;
case V_72 :
break;
case V_266 :
break;
default:
F_22 ( V_53 -> V_37 ,
L_79 ,
V_265 ) ;
break;
}
}
}
static void F_113 ( struct V_241 * V_241 )
{
struct V_107 * V_53 = V_241 -> V_267 ;
int V_36 = V_241 -> V_268 ;
int V_269 = V_241 -> V_270 ;
if ( V_269 != 0 )
goto V_271;
if ( V_53 -> V_78 == V_79 ) {
struct V_272 * V_270 ;
for ( V_270 = V_241 -> V_242 ;
V_36 >= sizeof( * V_270 ) ;
V_36 -= sizeof( * V_270 ) , V_270 ++ ) {
F_114 ( & V_241 -> V_38 -> V_38 , L_80 ,
V_270 -> V_273 ,
V_270 -> V_274 ) ;
if ( ( V_270 -> V_273 & V_275 ) !=
V_276 )
continue;
if ( V_270 -> V_273 & V_277 )
F_115 ( V_53 , V_270 -> V_274 ) ;
else
F_107 ( V_53 , V_270 -> V_274 ) ;
}
} else {
struct V_278 * V_279 ;
for ( V_279 = V_241 -> V_242 ;
V_36 >= sizeof( * V_279 ) ;
V_36 -= sizeof( * V_279 ) , V_279 ++ ) {
if ( ( V_279 -> V_280 & V_281 ) ||
( V_279 -> V_280 & V_282 ) )
continue;
F_112 ( V_53 , V_279 -> V_283 ,
F_44 ( V_279 -> V_284 ) ,
F_44 ( V_279 -> V_285 ) ) ;
}
}
V_271:
if ( V_269 != - V_286 &&
V_269 != - V_287 &&
V_269 != - V_288 ) {
V_241 -> V_38 = V_53 -> V_37 -> V_38 ;
F_116 ( V_241 , V_289 ) ;
}
}
static int F_117 ( struct V_107 * V_53 )
{
struct V_290 * V_291 ;
void * V_242 ;
int V_292 ;
unsigned int V_293 ;
if ( F_118 ( V_53 -> V_249 ) -> V_294 < 1 )
return 0 ;
V_291 = F_119 ( V_53 -> V_249 , 0 ) ;
if ( ! F_120 ( V_291 ) || ! F_121 ( V_291 ) )
return 0 ;
V_293 = F_122 ( V_291 ) ;
V_292 = F_44 ( V_291 -> V_295 ) ;
V_242 = F_98 ( V_292 , V_187 ) ;
if ( ! V_242 )
return - V_98 ;
V_53 -> V_241 = F_123 ( 0 , V_187 ) ;
if ( ! V_53 -> V_241 ) {
F_54 ( V_242 ) ;
return - V_98 ;
}
F_124 ( V_53 -> V_241 , V_53 -> V_37 -> V_38 ,
F_125 ( V_53 -> V_37 -> V_38 , V_293 ) ,
V_242 , V_292 ,
F_113 , V_53 , V_291 -> V_296 ) ;
F_116 ( V_53 -> V_241 , V_187 ) ;
return 0 ;
}
int F_126 ( struct V_51 * V_37 , int V_297 ,
int V_298 )
{
static struct V_299 V_300 = {
. V_301 = F_103
} ;
struct V_107 * V_53 ;
struct V_260 * V_261 ;
int V_57 ;
strcpy ( V_37 -> V_108 -> V_302 , L_81 ) ;
V_53 = F_69 ( sizeof( * V_53 ) , V_187 ) ;
if ( ! V_53 )
return - V_98 ;
V_53 -> V_37 = V_37 ;
V_53 -> V_84 = V_298 ;
V_53 -> V_110 = F_127 ( V_263 , sizeof( * V_53 -> V_110 ) ,
V_187 ) ;
if ( ! V_53 -> V_110 ) {
F_54 ( V_53 ) ;
return - V_98 ;
}
V_53 -> V_249 = & F_128 ( V_37 -> V_38 , V_297 ) -> V_303 [ 0 ] ;
switch ( F_118 ( V_53 -> V_249 ) -> V_304 ) {
case V_79 :
default:
V_53 -> V_78 = V_79 ;
break;
case V_141 :
V_53 -> V_78 = V_141 ;
break;
}
if ( ( V_57 = F_104 ( V_53 ) ) < 0 ||
( V_57 = F_117 ( V_53 ) ) < 0 )
goto V_305;
F_129 ( V_53 ) ;
V_57 = F_130 ( V_37 -> V_108 , V_306 , V_53 , & V_300 ) ;
if ( V_57 < 0 )
goto V_305;
if ( F_131 ( & V_37 -> V_307 ) &&
! F_132 ( V_37 -> V_108 , L_82 , & V_261 ) )
F_133 ( V_261 , V_37 , F_110 ) ;
F_134 ( & V_53 -> V_105 , & V_37 -> V_307 ) ;
return 0 ;
V_305:
F_101 ( V_53 ) ;
return V_57 ;
}
void F_135 ( struct V_107 * V_53 )
{
F_136 ( V_53 -> V_241 ) ;
F_136 ( V_53 -> V_243 ) ;
}
static void F_137 ( struct V_107 * V_53 )
{
F_136 ( V_53 -> V_241 ) ;
F_136 ( V_53 -> V_243 ) ;
}
static int F_138 ( struct V_107 * V_53 )
{
int V_57 ;
if ( V_53 -> V_241 ) {
V_57 = F_116 ( V_53 -> V_241 , V_308 ) ;
if ( V_57 < 0 )
return V_57 ;
}
return 0 ;
}
int F_139 ( struct V_107 * V_53 )
{
F_137 ( V_53 ) ;
return 0 ;
}
static int F_140 ( struct V_104 * V_105 )
{
struct V_13 * V_14 = (struct V_13 * ) V_105 ;
int V_169 , V_57 , V_56 ;
if ( V_14 -> V_150 ) {
V_56 = 0 ;
for ( V_169 = 0 ; V_169 < V_152 ; V_169 ++ ) {
if ( ! ( V_14 -> V_150 & ( 1 << V_169 ) ) )
continue;
if ( V_14 -> V_82 & ( 1 << V_169 ) ) {
V_57 = F_34 ( V_14 , V_169 + 1 , V_56 ,
V_14 -> V_83 [ V_56 ] ) ;
if ( V_57 < 0 )
return V_57 ;
}
V_56 ++ ;
}
} else {
if ( V_14 -> V_82 ) {
V_57 = F_34 ( V_14 , 0 , 0 , * V_14 -> V_83 ) ;
if ( V_57 < 0 )
return V_57 ;
}
}
return 0 ;
}
int F_141 ( struct V_107 * V_53 , bool V_309 )
{
struct V_104 * V_105 ;
int V_8 , V_57 ;
if ( V_309 ) {
for ( V_8 = 0 ; V_8 < V_263 ; V_8 ++ ) {
for ( V_105 = V_53 -> V_110 [ V_8 ] ; V_105 ;
V_105 = V_105 -> V_109 ) {
if ( V_105 -> V_310 ) {
V_57 = V_105 -> V_310 ( V_105 ) ;
if ( V_57 < 0 )
return V_57 ;
}
}
}
}
return F_138 ( V_53 ) ;
}
void F_70 ( struct V_104 * V_105 ,
struct V_107 * V_53 ,
int V_4 )
{
V_105 -> V_53 = V_53 ;
V_105 -> V_8 = V_4 ;
V_105 -> V_264 = F_108 ;
#ifdef F_142
V_105 -> V_310 = F_140 ;
#endif
}
